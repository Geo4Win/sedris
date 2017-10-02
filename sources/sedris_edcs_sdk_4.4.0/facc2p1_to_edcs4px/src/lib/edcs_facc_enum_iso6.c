/*
 * FILE: edcs_facc_enum_iso6.c
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
local_init_facc_attribute_enum_mapping_pt6( void )
{
    EDCS_Mapping_Entry * temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5000].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5000].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5000].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5000].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5000].entry.ee_code = EEC_STRSHAP_CRESCENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5000].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5000].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5000].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5001].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5001].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5001].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5001].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5001].entry.ee_code = EEC_STRSHAP_FERRIS_WHEEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5001].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5001].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5001].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5002].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5002].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5002].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5002].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5002].entry.ee_code = EEC_STRSHAP_ENCLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5002].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5002].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5002].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5003].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5003].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5003].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5003].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5003].entry.ee_code = EEC_STRSHAP_ROLLER_COASTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5003].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5003].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5003].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5004].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5004].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5004].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5004].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5004].entry.ee_code = EEC_STRSHAP_LATERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5004].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5004].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5004].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5005].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5005].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5005].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5005].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5005].entry.ee_code = EEC_STRSHAP_MOUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5005].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5005].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5005].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5006].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5006].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5006].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5006].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5006].entry.ee_code = EEC_STRSHAP_RIPPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5006].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5006].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5006].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5007].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5007].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5007].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5007].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5007].entry.ee_code = EEC_STRSHAP_STAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5007].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5007].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5007].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5008].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5008].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5008].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5008].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5008].entry.ee_code = EEC_STRSHAP_TRANSVERSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5008].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5008].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5008].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5009].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5009].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5009].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5009].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5009].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5009].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5009].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5009].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5010].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5010].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5010].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5010].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5010].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5010].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5010].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5010].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5011].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5011].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5011].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5011].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5011].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5011].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5011].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5011].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5012].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5012].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5012].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5012].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5012].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5012].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5012].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5012].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5013].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5013].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5013].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5013].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5013].entry.ee_code = EEC_STRSHAP_WINDMOTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5013].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5013].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5013].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5014].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5014].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5014].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5014].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5014].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5014].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5014].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5014].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5015].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5015].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5015].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5015].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5015].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5015].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5015].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5015].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5016].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5016].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5016].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5016].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5016].entry.ee_code = EEC_STRSHAP_OPEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5016].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5016].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5016].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5017].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5017].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5017].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5017].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5017].entry.ee_code = EEC_STRSHAP_A_FRAME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5017].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5017].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5017].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5018].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5018].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5018].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5018].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5018].entry.ee_code = EEC_STRSHAP_H_FRAME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5018].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5018].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5018].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5019].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5019].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5019].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5019].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5019].entry.ee_code = EEC_STRSHAP_I_FRAME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5019].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5019].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5019].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5020].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5020].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5020].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5020].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5020].entry.ee_code = EEC_STRSHAP_Y_FRAME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5020].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5020].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5020].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5021].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5021].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5021].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5021].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5021].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5021].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5021].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5021].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5022].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5022].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5022].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5022].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5022].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5022].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5022].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5022].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5023].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5023].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5023].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5023].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5023].entry.ee_code = EEC_STRSHAP_TELESCOPING_GASHOLDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5023].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5023].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5023].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5024].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5024].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5024].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5024].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5024].entry.ee_code = EEC_STRSHAP_MAST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5024].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5024].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5024].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5025].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5025].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5025].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5025].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5025].entry.ee_code = EEC_STRSHAP_TRIPOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5025].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5025].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5025].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5026].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5026].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5026].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5026].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5026].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5026].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5026].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5026].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5027].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5027].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5027].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5027].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5027].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5027].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5027].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5027].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5028].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5028].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5028].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5028].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5028].entry.ee_code = EEC_STRSHAP_CYLINDER_WITH_FLAT_TOP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5028].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5028].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5028].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5029].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5029].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5029].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5029].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5029].entry.ee_code = EEC_STRSHAP_CYLINDER_WITH_DOMED_TOP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5029].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5029].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5029].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5030].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5030].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5030].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5030].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5030].entry.ee_code = EEC_STRSHAP_CYLINDER_PEAKED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5030].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5030].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5030].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5031].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5031].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5031].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5031].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5031].entry.ee_code = EEC_STRSHAP_SUPERBUOY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5031].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5031].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5031].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5032].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5032].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5032].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5032].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5032].entry.ee_code = EEC_STRSHAP_T_FRAME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5032].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5032].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5032].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5033].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5033].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5033].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5033].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5033].entry.ee_code = EEC_STRSHAP_TETRAHEDRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5033].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5033].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5033].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5034].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5034].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5034].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5034].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5034].entry.ee_code = EEC_STRSHAP_FUNNEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5034].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5034].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5034].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5035].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5035].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5035].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5035].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5035].entry.ee_code = EEC_STRSHAP_ARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5035].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5035].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5035].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5036].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5036].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5036].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5036].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5036].entry.ee_code = EEC_STRSHAP_MULTIPLE_ARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5036].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5036].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5036].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5037].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5037].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5037].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5037].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5037].entry.ee_code = EEC_STRSHAP_ROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5037].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5037].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5037].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5038].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5038].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5038].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5038].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5038].entry.ee_code = EEC_STRSHAP_RECTANGULAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5038].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5038].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5038].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5039].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5039].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5039].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5039].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5039].entry.ee_code = EEC_STRSHAP_DRAGON_TEETH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5039].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5039].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5039].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5040].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5040].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5040].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5040].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5040].entry.ee_code = EEC_STRSHAP_I_BEAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5040].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5040].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5040].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5041].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5041].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5041].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5041].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5041].entry.ee_code = EEC_STRSHAP_SQUARE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5041].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5041].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5041].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5042].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5042].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5042].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5042].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5042].entry.ee_code = EEC_STRSHAP_IRREGULAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5042].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5042].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5042].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5043].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5043].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5043].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5043].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5043].entry.ee_code = EEC_STRSHAP_DIAMOND_SHAPED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5043].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5043].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5043].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5044].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5044].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5044].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5044].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5044].entry.ee_code = EEC_STRSHAP_OVAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5044].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5044].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5044].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5045].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5045].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5045].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5045].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5045].entry.ee_code = EEC_STRSHAP_DOME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5045].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5045].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5045].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5046].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5046].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5046].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5046].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5046].entry.ee_code = EEC_STRSHAP_SPHERICAL_WITH_COLUMNS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5046].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5046].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5046].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5047].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5047].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5047].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5047].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5047].entry.ee_code = EEC_STRSHAP_CYLINDER_PEAKED_WITH_TOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5047].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5047].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5047].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5048].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5048].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5048].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5048].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5048].entry.ee_code = EEC_STRSHAP_HIGH_RISE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5048].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5048].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5048].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5049].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5049].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5049].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5049].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5049].entry.ee_code = EEC_STRSHAP_CYLINDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5049].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5049].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5049].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5050].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5050].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5050].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5050].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5050].entry.ee_code = EEC_STRSHAP_CUBIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5050].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5050].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5050].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5051].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5051].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5051].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5051].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5051].entry.ee_code = EEC_STRSHAP_POLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5051].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5051].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5051].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5052].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5052].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5052].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5052].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5052].entry.ee_code = EEC_STRSHAP_BOARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5052].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5052].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5052].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5053].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5053].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5053].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5053].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5053].entry.ee_code = EEC_STRSHAP_COLUMN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5053].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5053].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5053].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5054].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5054].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5054].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5054].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5054].entry.ee_code = EEC_STRSHAP_PLAQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5054].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5054].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5054].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5055].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5055].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5055].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5055].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5055].entry.ee_code = EEC_STRSHAP_STATUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5055].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5055].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5055].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5056].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5056].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5056].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5056].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5056].entry.ee_code = EEC_STRSHAP_CROSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5056].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5056].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5056].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5057].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5057].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5057].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5057].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5057].entry.ee_code = EEC_STRSHAP_TOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5057].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5057].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5057].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5058].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5058].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5058].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5058].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5058].entry.ee_code = EEC_STRSHAP_SCANNER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5058].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5058].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5058].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5059].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5059].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5059].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5059].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5059].entry.ee_code = EEC_STRSHAP_OBELISK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5059].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5059].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5059].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5060].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5060].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5060].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5060].entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5060].entry.ee_code = EEC_STRSHAP_TOWER_MOUNTED_RADOME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5060].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5060].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5060].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5061].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5061].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5061].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5061].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5061].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5061].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5061].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5061].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5062].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5062].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5062].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5062].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5062].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5062].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5062].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5062].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5063].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5063].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5063].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5063].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5063].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5063].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5063].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5063].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5064].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5064].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5064].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5064].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5064].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5064].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5064].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_STRUCTURE_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5064].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5065].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5065].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5065].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5065].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5065].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5065].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5065].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5065].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5066].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5066].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5066].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5066].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5066].entry.ee_code = EEC_ROOFSHAP_PEAKED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5066].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5066].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5066].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5067].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5067].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5067].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5067].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5067].entry.ee_code = EEC_ROOFSHAP_CURVED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5067].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5067].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5067].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5068].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5068].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5068].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5068].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5068].entry.ee_code = EEC_ROOFSHAP_DOME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5068].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5068].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5068].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5069].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5069].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5069].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5069].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5069].entry.ee_code = EEC_ROOFSHAP_FLAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5069].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5069].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5069].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5070].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5070].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5070].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5070].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5070].entry.ee_code = EEC_ROOFSHAP_GABLE_PITCHED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5070].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5070].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5070].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5071].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5071].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5071].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5071].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5071].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5071].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5071].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5071].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5072].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5072].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5072].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5072].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5072].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5072].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5072].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5072].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5073].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5073].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5073].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5073].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5073].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5073].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5073].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5073].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5074].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5074].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5074].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5074].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5074].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5074].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5074].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5074].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5075].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5075].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5075].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5075].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5075].entry.ee_code = EEC_ROOFSHAP_SAWTOOTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5075].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5075].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5075].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5076].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5076].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5076].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5076].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5076].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5076].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5076].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5076].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5077].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5077].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5077].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5077].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5077].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5077].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5077].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5077].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5078].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5078].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5078].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5078].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5078].entry.ee_code = EEC_ROOFSHAP_WITH_CLERESTORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5078].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5078].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5078].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5079].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5079].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5079].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5079].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5079].entry.ee_code = EEC_ROOFSHAP_WITH_STEEPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5079].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5079].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5079].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5080].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5080].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5080].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5080].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5080].entry.ee_code = EEC_ROOFSHAP_FLAT_WITH_CLERESTORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5080].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5080].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5080].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5081].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5081].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5081].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5081].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5081].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5081].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5081].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5081].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5082].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5082].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5082].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5082].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5082].entry.ee_code = EEC_ROOFSHAP_GABLE_WITH_CLERESTORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5082].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5082].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5082].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5083].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5083].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5083].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5083].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5083].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5083].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5083].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5083].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5084].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5084].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5084].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5084].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5084].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5084].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5084].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5084].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5085].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5085].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5085].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5085].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5085].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5085].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5085].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5085].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5086].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5086].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5086].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5086].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5086].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5086].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5086].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5086].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5087].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5087].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5087].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5087].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5087].entry.ee_code = EEC_ROOFSHAP_WITH_CUPOLA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5087].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5087].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5087].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5088].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5088].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5088].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5088].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5088].entry.ee_code = EEC_ROOFSHAP_WITH_TURRET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5088].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5088].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5088].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5089].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5089].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5089].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5089].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5089].entry.ee_code = EEC_ROOFSHAP_WITH_TOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5089].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5089].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5089].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5090].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5090].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5090].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5090].entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5090].entry.ee_code = EEC_ROOFSHAP_WITH_MINARET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5090].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5090].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5090].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5091].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5091].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5091].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5091].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5091].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5091].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5091].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5091].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5092].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5092].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5092].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5092].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5092].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5092].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5092].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5092].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5093].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5093].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5093].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5093].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5093].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5093].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5093].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5093].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5094].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5094].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5094].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5094].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5094].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5094].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5094].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROOF_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5094].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5095].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5095].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5095].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5095].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5095].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5095].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5095].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5095].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5096].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5096].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5096].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5096].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5096].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5096].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5096].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_BELL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5096].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5097].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5097].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5097].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5097].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5097].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5097].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5097].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_DIAPHONE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5097].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5098].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5098].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5098].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5098].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5098].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5098].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5098].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_EXPLOSIVE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5098].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5099].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5099].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5099].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5099].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5099].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5099].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5099].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_GONG;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5099].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5100].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5100].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5100].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5100].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5100].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5100].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5100].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_GUN;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5100].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5101].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5101].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5101].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5101].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5101].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5101].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5101].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_HORN;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5101].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5102].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5102].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5102].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5102].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5102].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5102].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5102].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_NAUTOPHONE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5102].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5103].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5103].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5103].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5103].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5103].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5103].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5103].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_RADIO_FOG;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5103].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5104].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5104].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5104].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5104].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5104].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5104].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5104].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_SIREN;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5104].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5105].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5105].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5105].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5105].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5105].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5105].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5105].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_SUBMARINE_FOG_BELL;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5105].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5106].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5106].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5106].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5106].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5106].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5106].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5106].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_SUBMARINE_OSCILLATOR;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5106].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5107].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5107].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5107].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5107].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5107].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5107].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5107].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_SUBMARINE_CONNECTED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5107].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5108].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5108].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5108].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5108].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5108].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5108].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5108].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_SUBMARINE_NOT_CONNECTED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5108].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5109].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5109].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5109].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5109].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5109].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5109].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5109].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_WHISTLE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5109].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5110].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5110].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5110].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5110].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5110].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5110].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5110].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_REED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5110].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5111].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5111].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5111].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5111].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5111].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5111].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5111].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5111].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5112].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5112].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5112].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5112].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5112].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5112].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5112].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_SNDSIGTY_TYFON;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5112].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5113].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5113].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5113].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5113].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5113].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5113].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5113].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5113].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5114].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5114].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5114].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5114].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5114].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5114].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5114].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5114].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5115].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5115].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5115].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5115].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5115].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5115].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5115].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5115].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5116].code.tag, "SST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5116].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5116].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5116].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5116].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5116].entry.num_entries = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5116].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_SOUND_SIGNAL_PRESENT;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[1].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5116].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5117].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5117].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5117].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5117].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5117].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5117].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5117].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5117].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5118].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5118].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5118].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5118].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5118].entry.ee_code = EEC_MARSTAACTV_COASTGUARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5118].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5118].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5118].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5119].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5119].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5119].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5119].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5119].entry.ee_code = EEC_MARSTAEQ_FIREBOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5119].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5119].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5119].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5120].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5120].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5120].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5120].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5120].entry.ee_code = EEC_MARSTAACTV_MARINE_POLICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5120].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5120].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5120].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5121].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5121].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5121].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5121].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5121].entry.ee_code = EEC_MARSTAEQ_ICE_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5121].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5121].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5121].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5122].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5122].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5122].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5122].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5122].entry.ee_code = EEC_MARSTAEQ_LIFEBOAT_OR_RESCUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5122].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5122].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5122].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5123].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5123].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5123].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5123].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5123].entry.ee_code = EEC_MARSTAACTV_PORT_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5123].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5123].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5123].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5124].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5124].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5124].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5124].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5124].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5124].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5124].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5124].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5125].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5125].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5125].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5125].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5125].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5125].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5125].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5125].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5126].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5126].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5126].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5126].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5126].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5126].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5126].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5126].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5127].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5127].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5127].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5127].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5127].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5127].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5127].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5127].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5128].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5128].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5128].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5128].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5128].entry.ee_code = EEC_MARSTAACTV_PILOT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5128].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5128].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5128].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5129].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5129].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5129].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5129].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5129].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5129].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5129].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5129].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5130].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5130].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5130].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5130].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5130].entry.ee_code = EEC_MARSTAACTV_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5130].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5130].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5130].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5131].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5131].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5131].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5131].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5131].entry.ee_code = EEC_MARSTAEQ_SIGNAL_MAST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5131].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5131].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5131].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5132].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5132].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5132].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5132].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5132].entry.ee_code = EEC_MARSTAACTV_STORM_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5132].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5132].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5132].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5133].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5133].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5133].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5133].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5133].entry.ee_code = EEC_MARSTAACTV_STREAM_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5133].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5133].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5133].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5134].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5134].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5134].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5134].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5134].entry.ee_code = EEC_MARSTAACTV_TIDE_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5134].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5134].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5134].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5135].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5135].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5135].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5135].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5135].entry.ee_code = EEC_MARSTAEQ_TIME_BALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5135].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5135].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5135].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5136].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5136].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5136].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5136].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5136].entry.ee_code = EEC_MARSTAACTV_TIME_SIGNAL_LIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5136].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5136].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5136].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5137].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5137].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5137].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5137].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5137].entry.ee_code = EEC_MARSTAACTV_UNMANNED_OCEAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5137].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5137].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5137].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5138].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5138].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5138].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5138].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5138].entry.ee_code = EEC_MARSTAACTV_WEATHER_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5138].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5138].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5138].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5139].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5139].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5139].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5139].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5139].entry.ee_code = EEC_MARSTAEQ_FOG_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5139].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5139].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5139].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5140].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5140].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5140].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5140].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5140].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5140].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5140].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5140].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5141].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5141].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5141].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5141].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5141].entry.ee_code = EEC_MARSTAEQ_SEMAPHORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5141].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5141].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5141].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5142].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5142].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5142].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5142].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5142].entry.ee_code = EEC_MARSTAEQ_STA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5142].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5142].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5142].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5143].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5143].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5143].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5143].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5143].entry.ee_code = EEC_MARSTAACTV_TIDAL_CURRENT_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5143].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5143].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5143].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5144].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5144].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5144].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5144].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5144].entry.ee_code = EEC_MARSTAACTV_TRAFFIC_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5144].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5144].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5144].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5145].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5145].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5145].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5145].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5145].entry.ee_code = EEC_MARSTAACTV_BRIDGE_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5145].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5145].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5145].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5146].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5146].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5146].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5146].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5146].entry.ee_code = EEC_MARSTAACTV_LOCK_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5146].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5146].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5146].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5147].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5147].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5147].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5147].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5147].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5147].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5147].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5147].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5148].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5148].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5148].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5148].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5148].entry.ee_code = EEC_MARSTAACTV_INT_PORT_TRAFFIC_SIGNALS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5148].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5148].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5148].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5149].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5149].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5149].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5149].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5149].entry.ee_code = EEC_MARSTAACTV_FIRING_PRACTICE_SIGNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5149].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5149].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5149].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5150].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5150].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5150].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5150].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5150].entry.ee_code = EEC_MARSTAEQ_SIGNAL_TRAFFIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5150].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5150].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5150].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5151].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5151].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5151].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5151].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5151].entry.ee_code = EEC_MARSTAACTV_WARNING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5151].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5151].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5151].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5152].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5152].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5152].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5152].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5152].entry.ee_code = EEC_MARSTAACTV_RADAR_SURVEILLANCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5152].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5152].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5152].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5153].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5153].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5153].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5153].entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5153].entry.ee_code = EEC_MARSTAACTV_PILOT_LOOKOUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5153].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5153].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5153].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5154].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5154].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5154].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5154].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5154].entry.ee_code = EEC_MARSTAEQ_THEODOLITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5154].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5154].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5154].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5155].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5155].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5155].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5155].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5155].entry.ee_code = EEC_MARSTAEQ_CAMERA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5155].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5155].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5155].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5156].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5156].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5156].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5156].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5156].entry.ee_code = EEC_MARSTAEQ_RADAR_TARGET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5156].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5156].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5156].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5157].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5157].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5157].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5157].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5157].entry.ee_code = EEC_MARSTAEQ_SONAR_TARGET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5157].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5157].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5157].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5158].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5158].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5158].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5158].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5158].entry.ee_code = EEC_MARSTAEQ_UNDERWATER_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5158].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5158].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5158].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5159].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5159].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5159].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5159].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5159].entry.ee_code = EEC_MARSTAEQ_UNDERWATER_EMERGENCY_WARNING_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5159].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5159].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5159].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5160].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5160].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5160].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5160].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5160].entry.ee_code = EEC_MARSTAEQ_BOMIS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5160].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5160].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5160].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5161].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5161].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5161].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5161].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5161].entry.ee_code = EEC_MARSTAEQ_TRANSIT_HUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5161].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5161].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5161].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5162].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5162].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5162].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5162].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5162].entry.ee_code = EEC_MARSTAEQ_FORACS_TRANSDUCER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5162].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5162].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5162].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5163].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5163].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5163].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5163].entry.ea_code = EAC_MARINE_STATION_EQUIPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5163].entry.ee_code = EEC_MARSTAEQ_NMH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5163].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5163].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5163].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5164].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5164].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5164].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5164].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5164].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5164].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5164].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5164].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5165].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5165].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5165].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5165].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5165].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5165].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5165].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5165].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5166].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5166].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5166].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5166].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5166].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5166].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5166].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5166].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5167].code.tag, "STA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5167].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5167].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5167].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5167].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5167].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5167].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_STATION_ACTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5167].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5168].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5168].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5168].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5168].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5168].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5168].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5168].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5168].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5169].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5169].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5169].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5169].entry.ea_code = EAC_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5169].entry.ee_code = EEC_SOURCE_SURVEY_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5169].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5169].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5169].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5170].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5170].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5170].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5170].entry.ea_code = EAC_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5170].entry.ee_code = EEC_SOURCE_STEREO_IMAGERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5170].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5170].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5170].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5171].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5171].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5171].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5171].entry.ea_code = EAC_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5171].entry.ee_code = EEC_SOURCE_MONO_IMAGERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5171].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5171].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5171].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5172].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5172].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5172].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5172].entry.ea_code = EAC_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5172].entry.ee_code = EEC_SOURCE_CARTOGRAPHIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5172].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5172].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5172].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5173].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5173].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5173].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5173].entry.ea_code = EAC_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5173].entry.ee_code = EEC_SOURCE_REPORTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5173].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5173].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5173].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5174].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5174].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5174].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5174].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5174].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5174].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5174].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5174].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5175].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5175].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5175].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5175].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5175].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5175].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5175].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5175].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5176].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5176].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5176].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5176].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5176].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5176].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5176].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5176].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5177].code.tag, "STC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5177].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5177].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5177].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5177].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5177].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5177].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOURCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5177].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5178].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5178].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5178].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5178].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5178].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5178].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5178].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5178].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5179].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5179].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5179].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5179].entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5179].entry.ee_code = EEC_WETSOILTRAF_GW_GP_SW_SP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5179].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5179].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5179].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5180].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5180].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5180].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5180].entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5180].entry.ee_code = EEC_WETSOILTRAF_CH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5180].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5180].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5180].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5181].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5181].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5181].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5181].entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5181].entry.ee_code = EEC_WETSOILTRAF_GC_SC_CL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5181].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5181].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5181].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5182].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5182].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5182].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5182].entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5182].entry.ee_code = EEC_WETSOILTRAF_GM_SM_ML_ML_AND_CL_MH_OL_OH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5182].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5182].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5182].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5183].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5183].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5183].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5183].entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5183].entry.ee_code = EEC_WETSOILTRAF_PT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5183].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5183].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5183].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5184].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5184].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5184].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5184].entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5184].entry.ee_code = EEC_WETSOILTRAF_NOT_EVALUATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5184].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5184].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5184].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5185].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5185].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5185].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5185].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5185].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5185].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5185].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5185].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5186].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5186].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5186].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5186].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5186].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5186].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5186].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5186].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5187].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5187].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5187].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5187].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5187].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5187].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5187].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5187].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5188].code.tag, "STG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5188].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5188].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5188].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5188].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5188].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5188].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5188].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5189].code.tag, "STL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5189].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5189].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5189].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5189].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5189].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5189].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEASONAL_TENT_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5189].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5190].code.tag, "STL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5190].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5190].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5190].entry.ea_code = EAC_SEASONAL_TENT_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5190].entry.ee_code = EEC_SSNTENTLOC_WINTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5190].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5190].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5190].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5191].code.tag, "STL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5191].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5191].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5191].entry.ea_code = EAC_SEASONAL_TENT_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5191].entry.ee_code = EEC_SSNTENTLOC_SUMMER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5191].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5191].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5191].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5192].code.tag, "STL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5192].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5192].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5192].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5192].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5192].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5192].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEASONAL_TENT_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5192].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5193].code.tag, "STL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5193].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5193].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5193].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5193].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5193].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5193].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEASONAL_TENT_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5193].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5194].code.tag, "STL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5194].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5194].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5194].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5194].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5194].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5194].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEASONAL_TENT_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5194].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5195].code.tag, "STL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5195].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5195].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5195].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5195].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5195].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5195].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEASONAL_TENT_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5195].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5196].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5196].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5196].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5196].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5196].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5196].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5196].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5196].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5197].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5197].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5197].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5197].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5197].entry.ee_code = EEC_SOILTY_WELL_GRADED_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5197].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5197].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5197].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5198].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5198].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5198].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5198].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5198].entry.ee_code = EEC_SOILTY_POORLY_GRADED_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5198].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5198].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5198].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5199].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5199].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5199].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5199].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5199].entry.ee_code = EEC_SOILTY_SILTY_GRAVEL_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5199].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5199].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5199].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5200].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5200].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5200].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5200].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5200].entry.ee_code = EEC_SOILTY_CLAYEY_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5200].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5200].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5200].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5201].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5201].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5201].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5201].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5201].entry.ee_code = EEC_SOILTY_WELL_GRADED_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5201].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5201].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5201].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5202].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5202].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5202].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5202].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5202].entry.ee_code = EEC_SOILTY_POORLY_GRADED_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5202].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5202].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5202].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5203].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5203].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5203].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5203].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5203].entry.ee_code = EEC_SOILTY_SILTY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5203].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5203].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5203].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5204].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5204].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5204].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5204].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5204].entry.ee_code = EEC_SOILTY_CLAYEY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5204].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5204].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5204].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5205].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5205].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5205].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5205].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5205].entry.ee_code = EEC_SOILTY_SILT_FINE_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5205].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5205].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5205].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5206].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5206].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5206].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5206].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5206].entry.ee_code = EEC_SOILTY_LEAN_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5206].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5206].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5206].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5207].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5207].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5207].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5207].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5207].entry.ee_code = EEC_SOILTY_ORGANIC_SILT_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5207].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5207].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5207].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5208].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5208].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5208].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5208].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5208].entry.ee_code = EEC_SOILTY_FAT_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5208].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5208].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5208].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5209].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5209].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5209].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5209].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5209].entry.ee_code = EEC_SOILTY_MICRACEOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5209].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5209].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5209].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5210].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5210].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5210].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5210].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5210].entry.ee_code = EEC_SOILTY_ORGANIC_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5210].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5210].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5210].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5211].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5211].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5211].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5211].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5211].entry.ee_code = EEC_SOILTY_PEAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5211].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5211].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5211].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5212].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5212].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5212].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5212].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5212].entry.ee_code = EEC_SOILTY_SILT_FINE_SAND_AND_LEAN_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5212].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5212].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5212].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5213].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5213].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5213].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5213].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5213].entry.ee_code = EEC_SOILTY_EVAPORITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5213].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5213].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5213].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5214].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5214].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5214].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5214].entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5214].entry.ee_code = EEC_SOILTY_NOT_EVALUATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5214].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5214].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5214].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5215].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5215].enum_val = 501;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5215].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5215].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5215].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5215].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5215].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5215].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5216].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5216].enum_val = 502;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5216].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5216].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5216].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5216].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5216].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5216].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5217].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5217].enum_val = 503;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5217].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5217].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5217].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5217].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5217].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5217].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5218].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5218].enum_val = 504;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5218].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5218].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5218].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5218].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5218].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5218].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5219].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5219].enum_val = 505;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5219].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5219].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5219].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5219].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5219].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5219].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5220].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5220].enum_val = 506;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5220].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5220].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5220].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5220].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5220].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5220].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5221].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5221].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5221].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5221].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5221].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5221].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5221].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5221].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5222].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5222].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5222].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5222].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5222].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5222].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5222].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5222].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5223].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5223].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5223].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5223].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5223].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5223].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5223].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5223].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5224].code.tag, "STP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5224].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5224].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5224].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5224].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5224].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5224].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5224].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5225].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5225].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5225].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5225].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5225].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5225].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5225].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5225].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5226].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5226].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5226].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5226].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5226].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5226].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5226].entry.information = "<= 25%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 25.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5226].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5227].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5227].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5227].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5227].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5227].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5227].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5227].entry.information = "> 25% and <= 50%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 25.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5227].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5228].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5228].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5228].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5228].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5228].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5228].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5228].entry.information = "> 50% and <= 75%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 50.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 75.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5228].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5229].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5229].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5229].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5229].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5229].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5229].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5229].entry.information = "> 75%.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 75.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5229].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5230].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5230].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5230].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5230].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5230].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5230].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5230].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Not Applicable)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5230].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5231].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5231].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5231].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5231].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5231].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5231].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5231].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5231].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5232].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5232].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5232].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5232].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5232].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5232].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5232].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5232].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5233].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5233].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5233].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5233].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5233].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5233].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5233].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5233].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5234].code.tag, "SUP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5234].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5234].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5234].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5234].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5234].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5234].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_SUPERVISED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5234].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5235].code.tag, "SUP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5235].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5235].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5235].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5235].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5235].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5235].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LIGHT_SUPERVISED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5235].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5236].code.tag, "SUP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5236].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5236].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5236].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5236].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5236].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5236].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_LIGHT_SUPERVISED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5236].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5237].code.tag, "SUP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5237].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5237].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5237].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5237].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5237].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5237].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_SUPERVISED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5237].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5238].code.tag, "SUP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5238].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5238].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5238].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5238].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5238].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5238].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_SUPERVISED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5238].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5239].code.tag, "SUP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5239].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5239].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5239].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5239].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5239].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5239].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_SUPERVISED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5239].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5240].code.tag, "SUP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5240].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5240].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5240].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5240].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5240].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5240].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_SUPERVISED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5240].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5241].code.tag, "SUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5241].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5241].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5241].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5241].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5241].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5241].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_QUALIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5241].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5242].code.tag, "SUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5242].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5242].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5242].entry.ea_code = EAC_SURVEY_QUALIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5242].entry.ee_code = EEC_SURVQUAL_SURVEYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5242].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5242].entry.information = "Was whether the survey was adequate.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5242].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5243].code.tag, "SUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5243].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5243].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5243].entry.ea_code = EAC_SURVEY_QUALIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5243].entry.ee_code = EEC_SURVQUAL_INADEQUATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5243].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5243].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5243].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5244].code.tag, "SUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5244].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5244].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5244].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5244].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5244].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5244].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_QUALIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5244].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5245].code.tag, "SUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5245].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5245].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5245].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5245].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5245].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5245].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_QUALIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5245].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5246].code.tag, "SUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5246].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5246].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5246].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5246].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5246].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5246].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_QUALIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5246].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5247].code.tag, "SUR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5247].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5247].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5247].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5247].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5247].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5247].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SURVEY_QUALIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5247].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5248].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5248].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5248].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5248].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5248].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5248].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5248].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5248].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5249].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5249].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5249].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5249].entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5249].entry.ee_code = EEC_SNDGVEL_SOUNDER_4800_CALIBRATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5249].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5249].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5249].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5250].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5250].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5250].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5250].entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5250].entry.ee_code = EEC_SNDGVEL_SOUNDER_1500_CALIBRATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5250].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5250].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5250].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5251].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5251].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5251].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5251].entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5251].entry.ee_code = EEC_SNDGVEL_MATHEWS_TABLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5251].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5251].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5251].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5252].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5252].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5252].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5252].entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5252].entry.ee_code = EEC_SNDGVEL_SOUND_VELOCITY_METER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5252].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5252].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5252].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5253].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5253].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5253].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5253].entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5253].entry.ee_code = EEC_SNDGVEL_CORRECTED_BY_OTHER_MEANS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5253].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5253].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5253].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5254].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5254].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5254].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5254].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5254].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5254].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5254].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5254].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5255].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5255].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5255].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5255].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5255].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5255].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5255].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5255].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5256].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5256].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5256].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5256].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5256].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5256].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5256].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5256].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5257].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5257].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5257].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5257].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5257].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5257].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5257].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5257].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5258].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5258].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5258].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5258].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5258].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5258].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5258].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5258].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5259].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5259].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5259].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5259].entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5259].entry.ee_code = EEC_SOILWETNCAT_PERENNIALLY_DRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5259].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5259].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5259].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5260].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5260].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5260].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5260].entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5260].entry.ee_code = EEC_SOILWETNCAT_MOIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5260].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5260].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5260].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5261].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5261].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5261].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5261].entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5261].entry.ee_code = EEC_SOILWETNCAT_WET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5261].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5261].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5261].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5262].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5262].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5262].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5262].entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5262].entry.ee_code = EEC_SOILWETNCAT_FROZEN_OR_PERMAFROST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5262].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5262].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5262].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5263].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5263].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5263].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5263].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5263].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5263].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5263].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5263].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5264].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5264].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5264].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5264].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5264].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5264].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5264].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5264].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5265].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5265].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5265].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5265].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5265].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5265].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5265].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5265].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5266].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5266].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5266].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5266].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5266].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5266].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5266].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5266].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5267].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5267].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5267].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5267].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5267].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5267].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5267].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPRING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5267].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5268].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5268].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5268].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5268].entry.ea_code = EAC_SPRING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5268].entry.ee_code = EEC_SPRTY_GEYSER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5268].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5268].entry.information = "Was: \"Geyser\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5268].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5269].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5269].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5269].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5269].entry.ea_code = EAC_SPRING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5269].entry.ee_code = EEC_SPRTY_HOT_SPRING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5269].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5269].entry.information = "Was: \"Hot Spring\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5269].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5270].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5270].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5270].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5270].entry.ea_code = EAC_SPRING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5270].entry.ee_code = EEC_SPRTY_FUMAROLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5270].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5270].entry.information = "Was: \"Fumarole\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5270].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5271].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5271].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5271].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5271].entry.ea_code = EAC_SPRING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5271].entry.ee_code = EEC_SPRTY_ARTESIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5271].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5271].entry.information = "Was: \"Artesian\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5271].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5272].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5272].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5272].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_CONDITIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5272].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5272].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5272].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5272].entry.information = "Was: \"Water-hole\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_CLASS;
    temp_entries[0].u.class_entry = ECC_WATERING_HOLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5272].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5273].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5273].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5273].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5273].entry.ea_code = EAC_SPRING_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5273].entry.ee_code = EEC_SPRTY_WALLED_IN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5273].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5273].entry.information = "Was: \"Walled-In Spring\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5273].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5274].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5274].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5274].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5274].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5274].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5274].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5274].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPRING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5274].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5275].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5275].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5275].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5275].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5275].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5275].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5275].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPRING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5275].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5276].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5276].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5276].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5276].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5276].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5276].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5276].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPRING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5276].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5277].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5277].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5277].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5277].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5277].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5277].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5277].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SPRING_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5277].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5278].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5278].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5278].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5278].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5278].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5278].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5278].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5278].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5279].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5279].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5279].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5279].entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5279].entry.ee_code = EEC_TNLXSECT_ARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5279].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5279].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5279].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5280].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5280].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5280].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5280].entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5280].entry.ee_code = EEC_TNLXSECT_BOX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5280].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5280].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5280].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5281].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5281].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5281].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5281].entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5281].entry.ee_code = EEC_TNLXSECT_CIRCULAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5281].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5281].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5281].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5282].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5282].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5282].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5282].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5282].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5282].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5282].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5282].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5283].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5283].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5283].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5283].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5283].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5283].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5283].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5283].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5284].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5284].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5284].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5284].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5284].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5284].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5284].entry.information = "Erroneously mapped to ARCH in Version 1 of the mapping.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5284].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5285].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5285].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5285].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5285].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5285].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5285].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5285].entry.information = "Erroneously mapped to BOX in Version 1 of the mapping.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5285].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5286].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5286].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5286].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5286].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5286].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5286].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5286].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5286].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5287].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5287].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5287].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5287].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5287].entry.ee_code = EEC_SNDGMEASTECH_ECHO_SOUNDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5287].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5287].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5287].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5288].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5288].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5288].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5288].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5288].entry.ee_code = EEC_SNDGMEASTECH_SIDE_SCAN_SONAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5288].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5288].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5288].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5289].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5289].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5289].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5289].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5289].entry.ee_code = EEC_SNDGMEASTECH_MULTI_BEAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5289].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5289].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5289].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5290].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5290].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5290].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5290].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5290].entry.ee_code = EEC_SNDGMEASTECH_DIVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5290].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5290].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5290].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5291].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5291].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5291].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5291].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5291].entry.ee_code = EEC_SNDGMEASTECH_LEAD_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5291].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5291].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5291].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5292].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5292].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5292].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5292].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5292].entry.ee_code = EEC_SNDGMEASTECH_WIRE_DRAG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5292].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5292].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5292].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5293].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5293].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5293].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5293].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5293].entry.ee_code = EEC_SNDGMEASTECH_LASER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5293].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5293].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5293].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5294].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5294].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5294].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5294].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5294].entry.ee_code = EEC_SNDGMEASTECH_SWEPT_VERTICAL_ACOUSTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5294].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5294].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5294].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5295].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5295].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5295].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5295].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5295].entry.ee_code = EEC_SNDGMEASTECH_ELECTROMAGNETIC_SENSOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5295].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5295].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5295].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5296].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5296].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5296].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5296].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5296].entry.ee_code = EEC_SNDGMEASTECH_PHOTOGRAMMETRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5296].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5296].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5296].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5297].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5297].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5297].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5297].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5297].entry.ee_code = EEC_SNDGMEASTECH_SATELLITE_IMAGERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5297].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5297].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5297].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5298].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5298].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5298].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5298].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5298].entry.ee_code = EEC_SNDGMEASTECH_LEVELING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5298].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5298].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5298].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5299].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5299].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5299].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5299].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5299].entry.ee_code = EEC_SNDGMEASTECH_COMPUTER_GENERATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5299].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5299].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5299].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5300].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5300].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5300].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5300].entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5300].entry.ee_code = EEC_SNDGMEASTECH_SWEPT_SIDE_SCAN_SONAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5300].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5300].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5300].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5301].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5301].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5301].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5301].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5301].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5301].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5301].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5301].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5302].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5302].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5302].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5302].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5302].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5302].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5302].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5302].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5303].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5303].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5303].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5303].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5303].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5303].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5303].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5303].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5304].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5304].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5304].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5304].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5304].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5304].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5304].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5304].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5305].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5305].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5305].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5305].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5305].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5305].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5305].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TELESCOPE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5305].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5306].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5306].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5306].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5306].entry.ea_code = EAC_TELESCOPE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5306].entry.ee_code = EEC_TELESCOPETY_OPTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5306].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5306].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5306].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5307].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5307].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5307].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5307].entry.ea_code = EAC_TELESCOPE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5307].entry.ee_code = EEC_TELESCOPETY_PARABOLIC_RADIO_AERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5307].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5307].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5307].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5308].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5308].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5308].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5308].entry.ea_code = EAC_TELESCOPE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5308].entry.ee_code = EEC_TELESCOPETY_RADIO_AERIAL_ARRAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5308].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5308].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5308].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5309].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5309].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5309].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5309].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5309].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5309].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5309].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TELESCOPE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5309].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5310].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5310].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5310].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5310].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5310].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5310].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5310].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TELESCOPE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5310].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5311].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5311].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5311].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5311].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5311].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5311].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5311].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TELESCOPE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5311].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5312].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5312].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5312].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5312].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5312].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5312].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5312].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TELESCOPE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5312].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5313].code.tag, "TID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5313].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5313].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5313].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5313].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5313].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5313].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TIDE_INFLUENCED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5313].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5314].code.tag, "TID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5314].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5314].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5314].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5314].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5314].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5314].entry.information = "";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5314].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5315].code.tag, "TID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5315].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5315].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5315].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5315].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5315].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5315].entry.information = "";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5315].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5316].code.tag, "TID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5316].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5316].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5316].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5316].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5316].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5316].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TIDE_INFLUENCED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5316].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5317].code.tag, "TID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5317].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5317].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5317].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5317].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5317].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5317].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TIDE_INFLUENCED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5317].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5318].code.tag, "TID", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5318].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5318].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5318].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5318].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5318].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5318].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TIDE_INFLUENCED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5318].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5319].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5319].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5319].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5319].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5319].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5319].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5319].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5319].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5320].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5320].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5320].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5320].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5320].entry.ee_code = EEC_TPMKTY_EAST_MARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5320].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5320].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5320].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5321].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5321].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5321].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5321].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5321].entry.ee_code = EEC_TPMKTY_ISOLATED_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5321].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5321].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5321].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5322].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5322].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5322].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5322].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5322].entry.ee_code = EEC_TPMKTY_NORTH_MARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5322].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5322].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5322].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5323].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5323].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5323].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5323].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5323].entry.ee_code = EEC_TPMKTY_PORT_HAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5323].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5323].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5323].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5324].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5324].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5324].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5324].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5324].entry.ee_code = EEC_TPMKTY_SAFE_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5324].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5324].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5324].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5325].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5325].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5325].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5325].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5325].entry.ee_code = EEC_TPMKTY_SPECIAL_X;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5325].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5325].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5325].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5326].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5326].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5326].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5326].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5326].entry.ee_code = EEC_TPMKTY_STARBOARD_HAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5326].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5326].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5326].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5327].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5327].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5327].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5327].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5327].entry.ee_code = EEC_TPMKTY_SOUTH_MARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5327].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5327].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5327].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5328].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5328].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5328].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5328].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5328].entry.ee_code = EEC_TPMKTY_WEST_MARK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5328].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5328].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5328].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5329].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5329].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5329].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5329].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5329].entry.ee_code = EEC_TPMKTY_NUN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5329].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5329].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5329].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5330].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5330].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5330].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5330].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5330].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5330].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5330].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5330].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5331].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5331].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5331].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5331].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5331].entry.ee_code = EEC_TPMKTY_BALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5331].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5331].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5331].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5332].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5332].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5332].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5332].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5332].entry.ee_code = EEC_TPMKTY_CAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5332].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5332].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5332].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5333].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5333].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5333].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5333].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5333].entry.ee_code = EEC_TPMKTY_ST_ANDREWS_CROSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5333].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5333].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5333].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5334].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5334].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5334].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5334].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5334].entry.ee_code = EEC_TPMKTY_BALL_OVER_CONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5334].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5334].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5334].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5335].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5335].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5335].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5335].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5335].entry.ee_code = EEC_TPMKTY_CONE_OVER_BALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5335].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5335].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5335].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5336].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5336].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5336].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5336].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5336].entry.ee_code = EEC_TPMKTY_BROOM_POINT_UP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5336].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5336].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5336].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5337].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5337].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5337].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5337].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5337].entry.ee_code = EEC_TPMKTY_PERCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5337].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5337].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5337].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5338].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5338].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5338].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5338].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5338].entry.ee_code = EEC_TPMKTY_DIAMOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5338].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5338].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5338].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5339].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5339].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5339].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5339].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5339].entry.ee_code = EEC_TPMKTY_BROOM_POINT_DOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5339].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5339].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5339].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5340].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5340].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5340].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5340].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5340].entry.ee_code = EEC_TPMKTY_CONE_POINT_UPWARDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5340].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5340].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5340].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5341].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5341].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5341].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5341].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5341].entry.ee_code = EEC_TPMKTY_CONE_POINT_DOWNWARDS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5341].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5341].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5341].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5342].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5342].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5342].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5342].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5342].entry.ee_code = EEC_TPMKTY_UPRIGHT_CROSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5342].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5342].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5342].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5343].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5343].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5343].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5343].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5343].entry.ee_code = EEC_TPMKTY_OPTICAL_REFLECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5343].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5343].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5343].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5344].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5344].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5344].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5344].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5344].entry.ee_code = EEC_TPMKTY_CAN_OPEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5344].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5344].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5344].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5345].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5345].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5345].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5345].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5345].entry.ee_code = EEC_TPMKTY_CAN_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5345].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5345].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5345].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5346].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5346].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5346].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5346].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5346].entry.ee_code = EEC_TPMKTY_BALL_OPEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5346].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5346].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5346].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5347].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5347].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5347].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5347].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5347].entry.ee_code = EEC_TPMKTY_BALL_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5347].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5347].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5347].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5348].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5348].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5348].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5348].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5348].entry.ee_code = EEC_TPMKTY_CAN_OVER_BALL_OPEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5348].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5348].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5348].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5349].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5349].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5349].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5349].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5349].entry.ee_code = EEC_TPMKTY_CROSS_OVER_BALL_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5349].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5349].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5349].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5350].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5350].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5350].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5350].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5350].entry.ee_code = EEC_TPMKTY_DIAMOND_OVER_BALL_FILLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5350].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5350].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5350].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5351].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5351].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5351].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5351].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5351].entry.ee_code = EEC_TPMKTY_DOUBLE_CONE_POINTS_APART;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5351].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5351].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5351].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5352].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5352].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5352].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5352].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5352].entry.ee_code = EEC_TPMKTY_NONE_PRESENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5352].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5352].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5352].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5353].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5353].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5353].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5353].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5353].entry.ee_code = EEC_TPMKTY_SQUARE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5353].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5353].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Square)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5353].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5354].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5354].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5354].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5354].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5354].entry.ee_code = EEC_TPMKTY_T_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5354].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5354].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5354].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5355].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5355].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5355].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5355].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5355].entry.ee_code = EEC_TPMKTY_CROSS_OVER_BALL_OPEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5355].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5355].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5355].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5356].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5356].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5356].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5356].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5356].entry.ee_code = EEC_TPMKTY_DOUBLE_BALL_OPEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5356].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5356].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5356].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5357].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5357].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5357].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5357].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5357].entry.ee_code = EEC_TPMKTY_FLAG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5357].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5357].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5357].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5358].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5358].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5358].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5358].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5358].entry.ee_code = EEC_TPMKTY_SPHERE_OVER_RHOMBUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5358].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5358].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5358].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5359].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5359].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5359].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5359].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5359].entry.ee_code = EEC_TPMKTY_SQUARE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5359].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5359].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5359].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5360].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5360].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5360].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5360].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5360].entry.ee_code = EEC_TPMKTY_RECTANGLE_HORIZONTAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5360].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5360].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5360].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5361].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5361].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5361].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5361].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5361].entry.ee_code = EEC_TPMKTY_RECTANGLE_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5361].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5361].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5361].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5362].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5362].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5362].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5362].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5362].entry.ee_code = EEC_TPMKTY_TRAPEZIUM_UP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5362].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5362].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5362].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5363].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5363].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5363].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5363].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5363].entry.ee_code = EEC_TPMKTY_TRAPEZIUM_DOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5363].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5363].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5363].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5364].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5364].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5364].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5364].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5364].entry.ee_code = EEC_TPMKTY_TRIANGLE_POINT_UP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5364].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5364].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5364].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5365].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5365].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5365].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5365].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5365].entry.ee_code = EEC_TPMKTY_TRIANGLE_POINT_DOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5365].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5365].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5365].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5366].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5366].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5366].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5366].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5366].entry.ee_code = EEC_TPMKTY_CIRCLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5366].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5366].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5366].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5367].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5367].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5367].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5367].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5367].entry.ee_code = EEC_TPMKTY_TWO_UPRIGHT_CROSSES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5367].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5367].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5367].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5368].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5368].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5368].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5368].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5368].entry.ee_code = EEC_TPMKTY_TRI_POINT_UP_OVER_CIRCLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5368].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5368].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5368].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5369].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5369].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5369].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5369].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5369].entry.ee_code = EEC_TPMKTY_UPRIGHT_CROSS_OVER_CIRCLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5369].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5369].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5369].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5370].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5370].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5370].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5370].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5370].entry.ee_code = EEC_TPMKTY_RHOMBUS_OVER_CIRCLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5370].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5370].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5370].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5371].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5371].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5371].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5371].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5371].entry.ee_code = EEC_TPMKTY_CIRCLE_OVER_TRIANGLE_POINT_UP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5371].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5371].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5371].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5372].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5372].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5372].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5372].entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5372].entry.ee_code = EEC_TPMKTY_OTHER_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5372].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5372].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5372].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5373].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5373].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5373].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5373].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5373].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5373].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5373].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5373].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5374].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5374].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5374].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5374].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5374].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5374].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5374].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5374].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5375].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5375].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5375].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5375].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5375].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5375].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5375].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5375].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5376].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5376].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5376].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5376].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5376].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5376].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5376].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5376].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5377].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5377].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5377].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5377].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5377].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5377].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5377].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5377].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5378].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5378].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5378].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5378].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5378].entry.ee_code = EEC_TPMKSHAP_CONE_POINT_UP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5378].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5378].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5378].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5379].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5379].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5379].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5379].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5379].entry.ee_code = EEC_TPMKSHAP_CONE_POINT_DOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5379].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5379].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5379].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5380].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5380].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5380].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5380].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5380].entry.ee_code = EEC_TPMKSHAP_SPHERE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5380].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5380].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5380].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5381].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5381].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5381].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5381].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5381].entry.ee_code = EEC_TPMKSHAP_TWO_SPHERES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5381].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5381].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5381].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5382].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5382].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5382].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5382].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5382].entry.ee_code = EEC_TPMKSHAP_CYLINDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5382].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5382].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5382].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5383].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5383].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5383].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5383].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5383].entry.ee_code = EEC_TPMKSHAP_BOARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5383].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5383].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5383].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5384].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5384].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5384].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5384].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5384].entry.ee_code = EEC_TPMKSHAP_X_SHAPED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5384].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5384].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5384].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5385].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5385].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5385].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5385].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5385].entry.ee_code = EEC_TPMKSHAP_CROSS_SHAPED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5385].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5385].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5385].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5386].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5386].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5386].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5386].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5386].entry.ee_code = EEC_TPMKSHAP_CUBE_POINT_UP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5386].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5386].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5386].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5387].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5387].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5387].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5387].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5387].entry.ee_code = EEC_TPMKSHAP_TWO_CONES_POINT_TO_POINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5387].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5387].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5387].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5388].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5388].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5388].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5388].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5388].entry.ee_code = EEC_TPMKSHAP_TWO_CONES_BASE_TO_BASE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5388].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5388].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5388].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5389].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5389].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5389].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5389].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5389].entry.ee_code = EEC_TPMKSHAP_RHOMBUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5389].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5389].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5389].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5390].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5390].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5390].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5390].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5390].entry.ee_code = EEC_TPMKSHAP_TWO_CONES_POINTS_UPWARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5390].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5390].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5390].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5391].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5391].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5391].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5391].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5391].entry.ee_code = EEC_TPMKSHAP_TWO_CONES_POINTS_DOWNWARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5391].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5391].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5391].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5392].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5392].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5392].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5392].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5392].entry.ee_code = EEC_TPMKSHAP_BESOM_POINT_UP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5392].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5392].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5392].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5393].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5393].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5393].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5393].entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5393].entry.ee_code = EEC_TPMKSHAP_BESOM_POINT_DOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5393].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5393].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5393].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5394].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5394].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5394].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5394].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5394].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5394].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5394].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5394].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5395].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5395].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5395].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5395].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5395].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5395].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5395].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5395].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5396].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5396].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5396].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5396].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5396].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5396].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5396].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5396].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5397].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5397].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5397].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5397].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5397].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5397].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5397].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOPMARK_SHAPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5397].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5398].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5398].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5398].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5398].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5398].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5398].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5398].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5398].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5399].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5399].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5399].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5399].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5399].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5399].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5399].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5399].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5400].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5400].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5400].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5400].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5400].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5400].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5400].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5400].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5401].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5401].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5401].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5401].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5401].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5401].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5401].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5401].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5402].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5402].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5402].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5402].entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5402].entry.ee_code = EEC_PEDTRAV_WATER_BODY_WADABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5402].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5402].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5402].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5403].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5403].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5403].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5403].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5403].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5403].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5403].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5403].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5404].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5404].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5404].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5404].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5404].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5404].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5404].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5404].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5405].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5405].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5405].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5405].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5405].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5405].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5405].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5405].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5406].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5406].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5406].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5406].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5406].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5406].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5406].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5406].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5407].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5407].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5407].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5407].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5407].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5407].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5407].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5407].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5408].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5408].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5408].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5408].entry.ea_code = EAC_TREE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5408].entry.ee_code = EEC_TREETY_DECIDUOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5408].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5408].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5408].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5409].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5409].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5409].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5409].entry.ea_code = EAC_TREE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5409].entry.ee_code = EEC_TREETY_EVERGREEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5409].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5409].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5409].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5410].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5410].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5410].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5410].entry.ea_code = EAC_TREE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5410].entry.ee_code = EEC_TREETY_MIXED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5410].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5410].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5410].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5411].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5411].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5411].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5411].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5411].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5411].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5411].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5411].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5412].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5412].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5412].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5412].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5412].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5412].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5412].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5412].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5413].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5413].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5413].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5413].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5413].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5413].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5413].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5413].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5414].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5414].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5414].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5414].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5414].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5414].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5414].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5414].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5415].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5415].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5415].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5415].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5415].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5415].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5415].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5415].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5416].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5416].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5416].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5416].entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5416].entry.ee_code = EEC_VEHTRAFFLOW_INBOUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5416].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5416].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5416].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5417].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5417].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5417].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5417].entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5417].entry.ee_code = EEC_VEHTRAFFLOW_OUTBOUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5417].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5417].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5417].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5418].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5418].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5418].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5418].entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5418].entry.ee_code = EEC_VEHTRAFFLOW_ONE_WAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5418].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5418].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5418].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5419].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5419].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5419].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5419].entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5419].entry.ee_code = EEC_VEHTRAFFLOW_TWO_WAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5419].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5419].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5419].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5420].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5420].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5420].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5420].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5420].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5420].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5420].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5420].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5421].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5421].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5421].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5421].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5421].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5421].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5421].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5421].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5422].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5422].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5422].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5422].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5422].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5422].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5422].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5422].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5423].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5423].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5423].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5423].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5423].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5423].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5423].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5423].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5424].code.tag, "TRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5424].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5424].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5424].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5424].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5424].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5424].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECOMMENDED_TRACK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5424].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5425].code.tag, "TRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5425].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5425].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5425].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5425].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5425].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5425].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RECOMMENDED_TRACK;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5425].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5426].code.tag, "TRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5426].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5426].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5426].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5426].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5426].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5426].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RECOMMENDED_TRACK;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5426].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5427].code.tag, "TRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5427].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5427].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5427].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5427].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5427].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5427].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECOMMENDED_TRACK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5427].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5428].code.tag, "TRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5428].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5428].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5428].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5428].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5428].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5428].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECOMMENDED_TRACK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5428].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5429].code.tag, "TRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5429].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5429].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5429].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5429].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5429].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5429].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECOMMENDED_TRACK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5429].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5430].code.tag, "TRK", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5430].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5430].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5430].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5430].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5430].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5430].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RECOMMENDED_TRACK;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5430].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5431].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5431].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5431].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5431].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5431].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5431].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5431].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5431].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5432].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5432].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5432].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5432].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5432].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5432].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5432].entry.information = "<= 5,0 decimetre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5432].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5433].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5433].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5433].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5433].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5433].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5433].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5433].entry.information = "> 5,0 decimetre and <= 10,0 decimetre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5433].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5434].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5434].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5434].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5434].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5434].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5434].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5434].entry.information = "> 10,0 decimetre and <= 15,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 15.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5434].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5435].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5435].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5435].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5435].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5435].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5435].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5435].entry.information = "> 15,0 decimetres and <= 20,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 15.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5435].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5436].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5436].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5436].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5436].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5436].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5436].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5436].entry.information = "> 20,0 decimetres and <= 25,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 25.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5436].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5437].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5437].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5437].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5437].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5437].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5437].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5437].entry.information = "> 25,0 decimetres and <= 30,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 25.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5437].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5438].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5438].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5438].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5438].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5438].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5438].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5438].entry.information = "> 30,0 decimetres and <= 35,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 35.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5438].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5439].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5439].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5439].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5439].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5439].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5439].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5439].entry.information = "> 35,0 decimetres and <= 40,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 35.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5439].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5440].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5440].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5440].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5440].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5440].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5440].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5440].entry.information = "> 40,0 decimetres and <= 50,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 40.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5440].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5441].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5441].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5441].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5441].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5441].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5441].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5441].entry.information = "> 50,0 decimetres and <= 60,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 50.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 60.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5441].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5442].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5442].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5442].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5442].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5442].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5442].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5442].entry.information = "> 60,0 decimetres and <= 80,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 60.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 80.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5442].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5443].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5443].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5443].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5443].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5443].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5443].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5443].entry.information = "> 80,0 decimetres and <= 100,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 80.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5443].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5444].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5444].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5444].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5444].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5444].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5444].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5444].entry.information = "> 100,0 decimetres and <= 150,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 100.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 150.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5444].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5445].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5445].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5445].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5445].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5445].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5445].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5445].entry.information = "> 150,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 150.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5445].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5446].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5446].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5446].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5446].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5446].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5446].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5446].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5446].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5447].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5447].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5447].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5447].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5447].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5447].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5447].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5447].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5448].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5448].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5448].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5448].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5448].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5448].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5448].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5448].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5449].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5449].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5449].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5449].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5449].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5449].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5449].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5449].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5450].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5450].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5450].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5450].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5450].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5450].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5450].entry.information = "<= 30,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5450].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5451].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5451].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5451].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5451].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5451].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5451].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5451].entry.information = "> 30,0 decimetres and <= 70,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 70.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5451].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5452].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5452].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5452].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5452].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5452].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5452].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5452].entry.information = "> 70,0 decimetres and <= 100,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 70.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5452].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5453].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5453].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5453].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5453].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5453].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5453].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5453].entry.information = "> 100,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5453].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5454].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5454].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5454].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5454].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5454].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5454].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5454].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5454].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5455].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5455].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5455].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5455].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5455].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5455].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5455].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5455].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5456].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5456].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5456].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5456].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5456].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5456].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5456].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5456].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5457].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5457].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5457].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5457].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5457].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5457].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5457].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5457].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5458].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5458].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5458].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5458].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5458].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5458].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5458].entry.information = "<= 10,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5458].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5459].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5459].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5459].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5459].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5459].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5459].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5459].entry.information = "> 10,0 decimetres and <= 20,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5459].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5460].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5460].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5460].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5460].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5460].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5460].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5460].entry.information = "> 20,0 decimetres and <= 30,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5460].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5461].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5461].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5461].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5461].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5461].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5461].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5461].entry.information = "> 30,0 decimetres and <= 50,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 50.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5461].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5462].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5462].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5462].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5462].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5462].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5462].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5462].entry.information = "> 50,0 decimetres and <= 70,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 50.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 70.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5462].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5463].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5463].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5463].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5463].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5463].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5463].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5463].entry.information = "> 70,0 decimetres and <= 100,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 70.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 100.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5463].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5464].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5464].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5464].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5464].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5464].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5464].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5464].entry.information = "> 100,0 decimetres and <= 150,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 100.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 150.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5464].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5465].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5465].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5465].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5465].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5465].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5465].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5465].entry.information = "> 150,0 decimetres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_DECI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 150.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5465].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5466].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5466].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5466].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5466].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5466].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5466].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5466].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5466].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5467].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5467].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5467].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5467].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5467].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5467].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5467].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5467].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5468].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5468].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5468].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5468].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5468].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5468].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5468].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TREE_SPACING;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5468].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5469].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5469].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5469].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5469].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5469].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5469].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5469].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5469].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5470].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5470].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5470].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5470].entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5470].entry.ee_code = EEC_MARTSSCMPT_ARROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5470].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5470].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5470].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5471].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5471].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5471].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5471].entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5471].entry.ee_code = EEC_MARTSSCMPT_OUTER_BOUNDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5471].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5471].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5471].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5472].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5472].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5472].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5472].entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5472].entry.ee_code = EEC_MARTSSCMPT_SEP_ZONE_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5472].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5472].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5472].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5473].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5473].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5473].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5473].entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5473].entry.ee_code = EEC_MARTSSCMPT_SEP_ZONE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5473].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5473].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5473].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5474].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5474].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5474].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5474].entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5474].entry.ee_code = EEC_MARTSSCMPT_SEP_ZONE_POINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5474].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5474].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5474].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5475].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5475].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5475].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5475].entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5475].entry.ee_code = EEC_MARTSSCMPT_INBOUND_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5475].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5475].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5475].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5476].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5476].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5476].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5476].entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5476].entry.ee_code = EEC_MARTSSCMPT_OUTBOUND_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5476].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5476].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5476].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5477].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5477].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5477].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5477].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5477].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5477].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5477].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5477].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5478].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5478].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5478].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5478].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5478].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5478].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5478].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5478].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5479].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5479].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5479].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5479].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5479].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5479].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5479].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5479].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5480].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5480].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5480].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5480].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5480].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5480].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5480].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5480].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5481].code.tag, "TSS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5481].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5481].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5481].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5481].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5481].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5481].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TSS_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5481].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5482].code.tag, "TSS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5482].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5482].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5482].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5482].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5482].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5482].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TSS_IMO_ADOPTED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5482].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5483].code.tag, "TSS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5483].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5483].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5483].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5483].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5483].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5483].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_TSS_IMO_ADOPTED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5483].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5484].code.tag, "TSS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5484].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5484].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5484].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5484].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5484].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5484].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TSS_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5484].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5485].code.tag, "TSS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5485].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5485].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5485].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5485].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5485].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5485].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TSS_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5485].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5486].code.tag, "TSS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5486].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5486].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5486].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5486].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5486].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5486].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TSS_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5486].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5487].code.tag, "TSS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5487].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5487].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5487].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5487].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5487].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5487].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TSS_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5487].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5488].code.tag, "TST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5488].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5488].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5488].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5488].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5488].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5488].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5488].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5489].code.tag, "TST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5489].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5489].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5489].entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5489].entry.ee_code = EEC_ELEVELECCBLTY_NORMAL_SUSPENSION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5489].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5489].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5489].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5490].code.tag, "TST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5490].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5490].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5490].entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5490].entry.ee_code = EEC_ELEVELECCBLTY_MOUNTAIN_CATENARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5490].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5490].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5490].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5491].code.tag, "TST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5491].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5491].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5491].entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5491].entry.ee_code = EEC_ELEVELECCBLTY_OVERWATER_CATENARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5491].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5491].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5491].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5492].code.tag, "TST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5492].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5492].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5492].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5492].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5492].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5492].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5492].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5493].code.tag, "TST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5493].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5493].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5493].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5493].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5493].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5493].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5493].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5494].code.tag, "TST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5494].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5494].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5494].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5494].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5494].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5494].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5494].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5495].code.tag, "TST", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5495].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5495].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5495].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5495].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5495].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5495].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5495].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5496].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5496].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5496].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5496].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5496].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5496].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5496].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOWER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5496].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5497].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5497].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5497].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5497].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5497].entry.ee_code = EEC_TOWERTY_BRIDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5497].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5497].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5497].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5498].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5498].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5498].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5498].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5498].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5498].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5498].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOWER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5498].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5499].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5499].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5499].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5499].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5499].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5499].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5499].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOWER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5499].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5500].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5500].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5500].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5500].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5500].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5500].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5500].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOWER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5500].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5501].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5501].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5501].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5501].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5501].entry.ee_code = EEC_TOWERTY_ILLUMINATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5501].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5501].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5501].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5502].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5502].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5502].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5502].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5502].entry.ee_code = EEC_TOWERTY_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5502].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5502].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5502].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5503].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5503].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5503].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5503].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5503].entry.ee_code = EEC_TOWERTY_RADIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5503].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5503].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5503].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5504].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5504].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5504].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5504].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5504].entry.ee_code = EEC_TOWERTY_COOLING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5504].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5504].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5504].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5505].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5505].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5505].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5505].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5505].entry.ee_code = EEC_TOWERTY_RADAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5505].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5505].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5505].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5506].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5506].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5506].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5506].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5506].entry.ee_code = EEC_TOWERTY_LOOKOUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5506].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5506].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5506].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5507].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5507].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5507].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5507].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5507].entry.ee_code = EEC_TOWERTY_TELEVISION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5507].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5507].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5507].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5508].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5508].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5508].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5508].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5508].entry.ee_code = EEC_TOWERTY_FIRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5508].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5508].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5508].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5509].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5509].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5509].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5509].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5509].entry.ee_code = EEC_TOWERTY_MOORING_ARTICULATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5509].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5509].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5509].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5510].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5510].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5510].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5510].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5510].entry.ee_code = EEC_TOWERTY_POWER_TRANSMISSION_LINE_PYLON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5510].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5510].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5510].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5511].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5511].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5511].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5511].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5511].entry.ee_code = EEC_TOWERTY_LORAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5511].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5511].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5511].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5512].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5512].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5512].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5512].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5512].entry.ee_code = EEC_TOWERTY_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5512].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5512].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5512].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5513].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5513].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5513].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5513].entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5513].entry.ee_code = EEC_TOWERTY_MICROWAVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5513].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5513].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5513].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5514].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5514].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5514].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5514].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5514].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5514].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5514].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOWER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5514].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5515].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5515].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5515].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5515].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5515].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5515].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5515].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOWER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5515].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5516].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5516].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5516].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5516].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5516].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5516].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5516].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOWER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5516].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5517].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5517].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5517].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5517].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5517].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5517].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5517].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TOWER_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5517].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5518].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5518].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5518].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5518].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5518].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5518].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5518].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TRANSPORTATION_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5518].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5519].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5519].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5519].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5519].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5519].entry.ee_code = EEC_TRNSPUSE_ROAD_AND_RAILWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5519].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5519].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5519].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5520].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5520].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5520].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5520].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5520].entry.ee_code = EEC_TRNSPUSE_HIGHWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5520].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5520].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5520].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5521].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5521].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5521].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5521].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5521].entry.ee_code = EEC_TRNSPUSE_RAILWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5521].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5521].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5521].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5522].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5522].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5522].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5522].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5522].entry.ee_code = EEC_TRNSPUSE_ROAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5522].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5522].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5522].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5523].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5523].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5523].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5523].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5523].entry.ee_code = EEC_TRNSPUSE_STREET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5523].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5523].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5523].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5524].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5524].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5524].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5524].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5524].entry.ee_code = EEC_TRNSPUSE_THROUGH_ROUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5524].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5524].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5524].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5525].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5525].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5525].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5525].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5525].entry.ee_code = EEC_TRNSPUSE_AIR_TRAFFIC_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5525].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5525].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5525].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5526].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5526].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5526].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5526].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5526].entry.ee_code = EEC_TRNSPUSE_MARINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5526].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5526].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5526].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5527].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5527].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5527].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5527].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5527].entry.ee_code = EEC_TRNSPUSE_AIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5527].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5527].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5527].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5528].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5528].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5528].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5528].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5528].entry.ee_code = EEC_TRNSPUSE_BUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5528].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5528].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5528].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5529].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5529].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5529].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5529].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5529].entry.ee_code = EEC_TRNSPUSE_PEDESTRIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5529].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5529].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5529].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5530].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5530].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5530].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5530].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5530].entry.ee_code = EEC_TRNSPUSE_PIPELINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5530].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5530].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5530].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5531].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5531].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5531].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5531].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5531].entry.ee_code = EEC_TRNSPUSE_NON_HUMAN_ANIMAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5531].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5531].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5531].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5532].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5532].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5532].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5532].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5532].entry.ee_code = EEC_TRNSPUSE_AIRCRAFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5532].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5532].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5532].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5533].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5533].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5533].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5533].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5533].entry.ee_code = EEC_TRNSPUSE_SHIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5533].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5533].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5533].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5534].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5534].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5534].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5534].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5534].entry.ee_code = EEC_TRNSPUSE_AUTOMOTIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5534].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5534].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5534].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5535].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5535].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5535].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5535].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5535].entry.ee_code = EEC_TRNSPUSE_BOAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5535].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5535].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5535].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5536].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5536].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5536].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5536].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5536].entry.ee_code = EEC_TRNSPUSE_INDUSTRIAL_VESSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5536].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5536].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5536].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5537].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5537].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5537].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5537].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5537].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5537].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5537].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TRANSPORTATION_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5537].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5538].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5538].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5538].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5538].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5538].entry.ee_code = EEC_TRNSPUSE_PASSENGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5538].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5538].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5538].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5539].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5539].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5539].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5539].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5539].entry.ee_code = EEC_TRNSPUSE_CHAIR_LIFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5539].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5539].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5539].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5540].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5540].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5540].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5540].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5540].entry.ee_code = EEC_TRNSPUSE_SKI_TOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5540].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5540].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5540].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5541].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5541].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5541].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5541].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5541].entry.ee_code = EEC_TRNSPUSE_SLEIGH_TOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5541].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5541].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5541].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5542].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5542].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5542].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5542].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5542].entry.ee_code = EEC_TRNSPUSE_TOW_PATH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5542].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5542].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5542].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5543].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5543].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5543].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5543].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5543].entry.ee_code = EEC_TRNSPUSE_MOTORCYCLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5543].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5543].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5543].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5544].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5544].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5544].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5544].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5544].entry.ee_code = EEC_TRNSPUSE_BICYCLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5544].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5544].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5544].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5545].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5545].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5545].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5545].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5545].entry.ee_code = EEC_TRNSPUSE_MINERALS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5545].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5545].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5545].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5546].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5546].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5546].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5546].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5546].entry.ee_code = EEC_TRNSPUSE_WATERWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5546].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5546].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5546].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5547].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5547].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5547].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5547].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5547].entry.ee_code = EEC_TRNSPUSE_NO_TRANSPORT_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5547].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5547].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5547].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5548].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5548].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5548].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5548].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5548].entry.ee_code = EEC_TRNSPUSE_SLIP_OR_ACCESS_ROAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5548].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5548].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5548].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5549].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5549].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5549].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5549].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5549].entry.ee_code = EEC_TRNSPUSE_PORTAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5549].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5549].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5549].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5550].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5550].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5550].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5550].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5550].entry.ee_code = EEC_TRNSPUSE_CANAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5550].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5550].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5550].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5551].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5551].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5551].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5551].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5551].entry.ee_code = EEC_TRNSPUSE_CARAVAN_ROUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5551].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5551].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5551].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5552].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5552].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5552].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5552].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5552].entry.ee_code = EEC_TRNSPUSE_SUBWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5552].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5552].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5552].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5553].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5553].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5553].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5553].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5553].entry.ee_code = EEC_TRNSPUSE_AQUEDUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5553].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5553].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5553].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5554].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5554].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5554].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5554].entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5554].entry.ee_code = EEC_TRNSPUSE_ROAD_AND_RUNWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5554].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5554].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5554].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5555].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5555].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5555].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5555].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5555].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5555].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5555].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TRANSPORTATION_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5555].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5556].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5556].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5556].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5556].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5556].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5556].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5556].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TRANSPORTATION_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5556].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5557].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5557].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5557].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5557].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5557].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5557].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5557].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TRANSPORTATION_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5557].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5558].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5558].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5558].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5558].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5558].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5558].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5558].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_TRANSPORTATION_USE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5558].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5559].code.tag, "TY3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5559].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5559].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5559].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5559].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5559].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5559].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BENCHMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5559].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5560].code.tag, "TY3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5560].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5560].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5560].entry.ea_code = EAC_BENCHMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5560].entry.ee_code = EEC_BNCHMKTY_PRIMARY_ACS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5560].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5560].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5560].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5561].code.tag, "TY3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5561].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5561].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5561].entry.ea_code = EAC_BENCHMARK_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5561].entry.ee_code = EEC_BNCHMKTY_SECONDARY_ACS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5561].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5561].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5561].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5562].code.tag, "TY3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5562].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5562].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5562].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5562].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5562].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5562].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BENCHMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5562].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5563].code.tag, "TY3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5563].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5563].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5563].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5563].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5563].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5563].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BENCHMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5563].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5564].code.tag, "TY3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5564].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5564].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5564].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5564].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5564].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5564].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BENCHMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5564].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5565].code.tag, "TY3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5565].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5565].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5565].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5565].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5565].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5565].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_BENCHMARK_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5565].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5566].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5566].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5566].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5566].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5566].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5566].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5566].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5566].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5567].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5567].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5567].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5567].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5567].entry.ee_code = EEC_UNDRMATCHR_BROKEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5567].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5567].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5567].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5568].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5568].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5568].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5568].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5568].entry.ee_code = EEC_UNDRMATCHR_COARSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5568].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5568].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5568].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5569].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5569].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5569].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5569].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5569].entry.ee_code = EEC_UNDRMATCHR_DECAYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5569].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5569].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5569].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5570].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5570].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5570].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5570].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5570].entry.ee_code = EEC_UNDRMATCHR_FINE_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5570].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5570].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5570].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5571].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5571].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5571].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5571].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5571].entry.ee_code = EEC_UNDRMATCHR_GRITTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5571].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5571].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5571].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5572].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5572].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5572].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5572].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5572].entry.ee_code = EEC_UNDRMATCHR_HARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5572].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5572].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5572].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5573].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5573].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5573].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5573].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5573].entry.ee_code = EEC_UNDRMATCHR_ROTTEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5573].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5573].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5573].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5574].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5574].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5574].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5574].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5574].entry.ee_code = EEC_UNDRMATCHR_SOFT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5574].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5574].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5574].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5575].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5575].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5575].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5575].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5575].entry.ee_code = EEC_UNDRMATCHR_STICKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5575].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5575].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5575].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5576].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5576].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5576].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5576].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5576].entry.ee_code = EEC_UNDRMATCHR_STIFF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5576].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5576].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5576].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5577].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5577].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5577].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5577].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5577].entry.ee_code = EEC_UNDRMATCHR_STREAKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5577].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5577].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5577].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5578].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5578].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5578].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5578].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5578].entry.ee_code = EEC_UNDRMATCHR_TENACIOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5578].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5578].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5578].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5579].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5579].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5579].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5579].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5579].entry.ee_code = EEC_UNDRMATCHR_UNEVEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5579].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5579].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5579].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5580].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5580].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5580].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5580].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5580].entry.ee_code = EEC_UNDRMATCHR_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5580].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5580].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5580].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5581].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5581].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5581].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5581].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5581].entry.ee_code = EEC_UNDRMATCHR_FLINTY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5581].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5581].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5581].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5582].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5582].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5582].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5582].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5582].entry.ee_code = EEC_UNDRMATCHR_GLACIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5582].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5582].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5582].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5583].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5583].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5583].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5583].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5583].entry.ee_code = EEC_UNDRMATCHR_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5583].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5583].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5583].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5584].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5584].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5584].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5584].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5584].entry.ee_code = EEC_UNDRMATCHR_LARGE_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5584].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5584].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5584].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5585].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5585].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5585].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5585].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5585].entry.ee_code = EEC_UNDRMATCHR_ROCKY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5585].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5585].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5585].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5586].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5586].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5586].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5586].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5586].entry.ee_code = EEC_UNDRMATCHR_SMALL_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5586].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5586].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5586].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5587].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5587].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5587].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5587].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5587].entry.ee_code = EEC_UNDRMATCHR_SPECKLED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5587].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5587].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5587].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5588].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5588].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5588].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5588].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5588].entry.ee_code = EEC_UNDRMATCHR_VARIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5588].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5588].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5588].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5589].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5589].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5589].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5589].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5589].entry.ee_code = EEC_UNDRMATCHR_VOLCANIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5589].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5589].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5589].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5590].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5590].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5590].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5590].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5590].entry.ee_code = EEC_UNDRMATCHR_MEDIUM_PARTICLES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5590].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5590].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5590].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5591].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5591].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5591].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5591].entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5591].entry.ee_code = EEC_UNDRMATCHR_MASONRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5591].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5591].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5591].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5592].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5592].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5592].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5592].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5592].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5592].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5592].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5592].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5593].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5593].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5593].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5593].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5593].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5593].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5593].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5593].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5594].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5594].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5594].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5594].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5594].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5594].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5594].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5594].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5595].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5595].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5595].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5595].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5595].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5595].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5595].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5595].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5596].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5596].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5596].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5596].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5596].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5596].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5596].entry.information = "Deleted: \"Unknown\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5596].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5597].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5597].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5597].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5597].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5597].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5597].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5597].entry.information = "Deleted: \"Metres\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5597].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5598].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5598].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5598].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5598].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5598].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5598].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5598].entry.information = "Deleted: \"Fathoms and Feet\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5598].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5599].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5599].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5599].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5599].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5599].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5599].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5599].entry.information = "Deleted: \"Fathoms and Fractions\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5599].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5600].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5600].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5600].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5600].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5600].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5600].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5600].entry.information = "Deleted: \"Nautical Miles\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5600].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5601].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5601].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5601].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5601].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5601].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5601].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5601].entry.information = "Deleted: \"Feet\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5601].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5602].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5602].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5602].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5602].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5602].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5602].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5602].entry.information = "Deleted: \"Kilometers\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5602].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5603].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5603].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5603].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5603].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5603].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5603].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5603].entry.information = "Deleted: \"Yards\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5603].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5604].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5604].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5604].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5604].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5604].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5604].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5604].entry.information = "Deleted: \"Cables\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5604].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5605].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5605].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5605].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5605].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5605].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5605].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5605].entry.information = "Deleted: \"Degrees of Arc\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5605].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5606].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5606].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5606].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5606].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5606].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5606].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5606].entry.information = "Deleted: \"Millimetres\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5606].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5607].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5607].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5607].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5607].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5607].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5607].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5607].entry.information = "Deleted: \"Unpopulated\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5607].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5608].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5608].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5608].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5608].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5608].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5608].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5608].entry.information = "Deleted: \"Not Applicable\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5608].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5609].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5609].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5609].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5609].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5609].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5609].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5609].entry.information = "Deleted: \"Other\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5609].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5610].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5610].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5610].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5610].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5610].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5610].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5610].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5610].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5611].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5611].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5611].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5611].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5611].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5611].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5611].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5611].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5612].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5612].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5612].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5612].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5612].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5612].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5612].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5612].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5613].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5613].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5613].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5613].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5613].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5613].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5613].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5613].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5614].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5614].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5614].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5614].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5614].entry.ee_code = EEC_USAGE_NATIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5614].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5614].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<NATIONAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5614].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5615].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5615].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5615].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5615].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5615].entry.ee_code = EEC_USAGE_STATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5615].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5615].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<STATE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5615].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5616].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5616].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5616].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5616].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5616].entry.ee_code = EEC_USAGE_PRIVATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5616].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5616].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<PRIVATE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5616].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5617].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5617].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5617].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5617].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5617].entry.ee_code = EEC_USAGE_TRIBAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5617].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5617].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<TRIBAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5617].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5618].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5618].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5618].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5618].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5618].entry.ee_code = EEC_USAGE_MILITARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5618].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5618].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<MILITARY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5618].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5619].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5619].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5619].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5619].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5619].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5619].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5619].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5619].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5620].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5620].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5620].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5620].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5620].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5620].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5620].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5620].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5621].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5621].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5621].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5621].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5621].entry.ee_code = EEC_USAGE_TEMPORARY_RESIDENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5621].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5621].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5621].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5622].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5622].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5622].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5622].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5622].entry.ee_code = EEC_USAGE_APARTMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5622].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5622].entry.information = "Note that this can also be mapped as <<DWELLING_TYPE>>*<<<APARTMENT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5622].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5623].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5623].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5623].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5623].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5623].entry.ee_code = EEC_USAGE_OPEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5623].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5623].entry.information = "Note that this can also be mapped as <<ACCESSIBILITY_STATUS>>*<<<OPEN>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5623].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5624].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5624].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5624].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5624].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5624].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5624].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5624].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5624].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5625].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5625].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5625].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5625].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5625].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5625].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5625].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5625].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5626].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5626].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5626].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5626].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5626].entry.ee_code = EEC_USAGE_CITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5626].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5626].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<CITY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5626].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5627].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5627].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5627].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5627].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5627].entry.ee_code = EEC_USAGE_ADVERTISING_BILLBOARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5627].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5627].entry.information = "Note that this can also be mapped as <<DISPLAY_SIGN_TYPE>>*<<<ADVERTISING_BILLBOARD>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5627].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5628].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5628].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5628].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5628].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5628].entry.ee_code = EEC_USAGE_SCOREBOARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5628].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5628].entry.information = "Note that this can also be mapped as <<DISPLAY_SIGN_TYPE>>*<<<SCOREBOARD>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5628].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5629].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5629].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5629].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5629].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5629].entry.ee_code = EEC_USAGE_HIGHWAY_SIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5629].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5629].entry.information = "Note that this can also be mapped as <<DISPLAY_SIGN_TYPE>>*<<<HIGHWAY_SIGN>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5629].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5630].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5630].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5630].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5630].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5630].entry.ee_code = EEC_USAGE_CLOSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5630].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5630].entry.information = "Note that this can also be mapped as <<ACCESSIBILITY_STATUS>>*<<<CLOSED>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5630].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5631].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5631].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5631].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5631].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5631].entry.ee_code = EEC_USAGE_RESTRICTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5631].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5631].entry.information = "Note that this can also be mapped as <<ACCESSIBILITY_STATUS>>*<<<RESTRICTED>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5631].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5632].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5632].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5632].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5632].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5632].entry.ee_code = EEC_USAGE_JOINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5632].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5632].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<JOINT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5632].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5633].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5633].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5633].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5633].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5633].entry.ee_code = EEC_USAGE_INTERNATIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5633].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5633].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<INTERNATIONAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5633].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5634].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5634].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5634].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5634].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5634].entry.ee_code = EEC_USAGE_UNIDENTIFIED_AIRSTRIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5634].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5634].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<UNIDENTIFIED_AIRSTRIP>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5634].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5635].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5635].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5635].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5635].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5635].entry.ee_code = EEC_USAGE_FEDERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5635].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5635].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<FEDERAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5635].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5636].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5636].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5636].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5636].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5636].entry.ee_code = EEC_USAGE_PRIMARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5636].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5636].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5636].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5637].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5637].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5637].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5637].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5637].entry.ee_code = EEC_USAGE_SECONDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5637].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5637].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5637].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5638].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5638].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5638].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5638].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5638].entry.ee_code = EEC_USAGE_TERTIARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5638].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5638].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5638].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5639].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5639].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5639].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5639].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5639].entry.ee_code = EEC_USAGE_INSULAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5639].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5639].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<INSULAR>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5639].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5640].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5640].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5640].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5640].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5640].entry.ee_code = EEC_USAGE_PROVINCIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5640].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5640].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<PROVINCIAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5640].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5641].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5641].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5641].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5641].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5641].entry.ee_code = EEC_USAGE_INTERSTATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5641].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5641].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<INTERSTATE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5641].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5642].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5642].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5642].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5642].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5642].entry.ee_code = EEC_USAGE_INDUSTRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5642].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5642].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<INDUSTRY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5642].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5643].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5643].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5643].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5643].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5643].entry.ee_code = EEC_USAGE_COMMERCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5643].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5643].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<COMMERCE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5643].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5644].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5644].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5644].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5644].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5644].entry.ee_code = EEC_USAGE_INSTITUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5644].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5644].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<INSTITUTION>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5644].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5645].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5645].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5645].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5645].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5645].entry.ee_code = EEC_USAGE_RESIDENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5645].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5645].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<RESIDENCE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5645].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5646].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5646].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5646].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5646].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5646].entry.ee_code = EEC_USAGE_AGRICULTURE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5646].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5646].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<AGRICULTURE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5646].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5647].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5647].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5647].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5647].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5647].entry.ee_code = EEC_USAGE_DECOY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5647].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5647].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<DECOY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5647].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5648].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5648].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5648].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5648].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5648].entry.ee_code = EEC_USAGE_NON_MILITARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5648].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5648].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<NON_MILITARY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5648].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5649].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5649].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5649].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5649].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5649].entry.ee_code = EEC_USAGE_LIMITED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5649].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5649].entry.information = "Note that this can also be mapped as <<ACCESSIBILITY_STATUS>>*<<<LIMITED>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5649].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5650].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5650].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5650].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5650].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5650].entry.ee_code = EEC_USAGE_TELEGRAPH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5650].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5650].entry.information = "Note that this can also be mapped as <<UTILITY_USE>>*<<<TELEGRAPH>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5650].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5651].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5651].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5651].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5651].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5651].entry.ee_code = EEC_USAGE_TELEPHONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5651].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5651].entry.information = "Note that this can also be mapped as <<UTILITY_USE>>*<<<TELEPHONE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5651].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5652].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5652].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5652].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5652].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5652].entry.ee_code = EEC_USAGE_POWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5652].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5652].entry.information = "Note that this can also be mapped as <<UTILITY_USE>>*<<<POWER>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5652].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5653].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5653].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5653].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5653].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5653].entry.ee_code = EEC_USAGE_MARINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5653].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5653].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<MARINE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5653].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5654].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5654].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5654].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5654].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5654].entry.ee_code = EEC_USAGE_AVALANCHE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5654].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5654].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<AVALANCHE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5654].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5655].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5655].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5655].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5655].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5655].entry.ee_code = EEC_USAGE_REFUGEE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5655].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5655].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<REFUGEE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5655].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5656].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5656].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5656].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5656].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5656].entry.ee_code = EEC_USAGE_PRISONER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5656].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5656].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<PRISONER>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5656].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5657].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5657].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5657].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5657].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5657].entry.ee_code = EEC_USAGE_ANIMAL_SANCTUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5657].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5657].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<ANIMAL_SANCTUARY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5657].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5658].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5658].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5658].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5658].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5658].entry.ee_code = EEC_USAGE_LEVEE_OR_DYKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5658].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5658].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<LEVEE_OR_DYKE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5658].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5659].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5659].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5659].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5659].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5659].entry.ee_code = EEC_USAGE_RESERVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5659].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5659].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<RESERVE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5659].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5660].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5660].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5660].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5660].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5660].entry.ee_code = EEC_USAGE_TERMINUS_OR_TERMINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5660].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5660].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<TERMINUS_OR_TERMINAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5660].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5661].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5661].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5661].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5661].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5661].entry.ee_code = EEC_USAGE_LOW_ALTITUDE_ENROUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5661].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5661].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_ROUTE_TYPE>>*<<<LOW_ALTITUDE_ENROUTE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5661].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5662].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5662].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5662].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5662].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5662].entry.ee_code = EEC_USAGE_HIGH_ALTITUDE_ENROUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5662].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5662].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_ROUTE_TYPE>>*<<<HIGH_ALTITUDE_ENROUTE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5662].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5663].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5663].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5663].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5663].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5663].entry.ee_code = EEC_USAGE_LOW_HIGH_ALTITUDE_ENROUTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5663].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5663].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_ROUTE_TYPE>>*<<<LOW_HIGH_ALTITUDE_ENROUTE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5663].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5664].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5664].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5664].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5664].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5664].entry.ee_code = EEC_USAGE_STOL_APPROACH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5664].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5664].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_APPROACH_TYPE>>*<<<STOL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5664].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5665].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5665].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5665].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5665].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5665].entry.ee_code = EEC_USAGE_VISUAL_APPROACH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5665].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5665].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_APPROACH_TYPE>>*<<<VISUAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5665].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5666].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5666].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5666].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5666].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5666].entry.ee_code = EEC_USAGE_NON_PRECISION_INSTRUMENT_APPROACH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5666].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5666].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_APPROACH_TYPE>>*<<<NON_PRECISION_INSTRUMENT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5666].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5667].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5667].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5667].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5667].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5667].entry.ee_code = EEC_USAGE_PRECISION_INSTRUMENT_APPROACH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5667].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5667].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_APPROACH_TYPE>>*<<<PRECISION_INSTRUMENT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5667].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5668].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5668].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5668].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5668].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5668].entry.ee_code = EEC_USAGE_ENTRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5668].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5668].entry.information = "Note that this can also be mapped as <<ACCESS_DIRECTION_TYPE>>*<<<ENTRY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5668].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5669].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5669].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5669].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5669].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5669].entry.ee_code = EEC_USAGE_EXIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5669].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5669].entry.information = "Note that this can also be mapped as <<ACCESS_DIRECTION_TYPE>>*<<<EXIT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5669].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5670].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5670].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5670].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5670].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5670].entry.ee_code = EEC_USAGE_TRANSACTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5670].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5670].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<TRANSACTION>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5670].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5671].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5671].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5671].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5671].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5671].entry.ee_code = EEC_USAGE_FEEDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5671].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5671].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<FEEDER>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5671].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5672].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5672].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5672].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5672].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5672].entry.ee_code = EEC_USAGE_INITIAL_APPROACH_FIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5672].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5672].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_APPROACH_TYPE>>*<<<INITIAL_FIX>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5672].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5673].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5673].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5673].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5673].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5673].entry.ee_code = EEC_USAGE_FINAL_APPROACH_FIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5673].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5673].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_APPROACH_TYPE>>*<<<FINAL_FIX>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5673].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5674].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5674].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5674].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5674].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5674].entry.ee_code = EEC_USAGE_VISUAL_DESCENT_POINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5674].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5674].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_POINT_FUNCTION>>*<<<VISUAL_DESCENT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5674].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5675].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5675].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5675].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5675].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5675].entry.ee_code = EEC_USAGE_MISSED_APPROACH_POINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5675].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5675].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_POINT_FUNCTION>>*<<<MISSED_APPROACH>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5675].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5676].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5676].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5676].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5676].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5676].entry.ee_code = EEC_USAGE_RADAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5676].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5676].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<RADAR>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5676].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5677].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5677].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5677].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5677].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5677].entry.ee_code = EEC_USAGE_MILEAGE_BREAK_DOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5677].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5677].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<MILEAGE_BREAK_DOWN>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5677].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5678].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5678].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5678].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5678].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5678].entry.ee_code = EEC_USAGE_AID_TO_NAVIGATION_CHANGEOVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5678].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5678].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<AID_TO_NAVIGATION_CHANGEOVER>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5678].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5679].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5679].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5679].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5679].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5679].entry.ee_code = EEC_USAGE_ALTIMETER_CHANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5679].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5679].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<ALTIMETER_CHANGE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5679].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5680].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5680].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5680].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5680].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5680].entry.ee_code = EEC_USAGE_COMPULSORY_REPORT_POINTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5680].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5680].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_POINT_FUNCTION>>*<<<COMPULSORY_REPORT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5680].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5681].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5681].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5681].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5681].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5681].entry.ee_code = EEC_USAGE_NON_COMPULSORY_REPORT_POINTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5681].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5681].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_POINT_FUNCTION>>*<<<NON_COMPULSORY_REPORT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5681].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5682].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5682].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5682].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5682].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5682].entry.ee_code = EEC_USAGE_ALERT_APRON_OR_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5682].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5682].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<ALERT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5682].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5683].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5683].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5683].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5683].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5683].entry.ee_code = EEC_USAGE_OPERATIONAL_APRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5683].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5683].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<OPERATIONAL_APRON>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5683].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5684].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5684].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5684].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5684].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5684].entry.ee_code = EEC_USAGE_AIRCRAFT_HANGAR_APRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5684].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5684].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<AIRCRAFT_HANGAR_APRON>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5684].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5685].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5685].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5685].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5685].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5685].entry.ee_code = EEC_USAGE_BASE_FLIGHT_APRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5685].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5685].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<BASE_FLIGHT_APRON>>>, since <<USAGE<< has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5685].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5686].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5686].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5686].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5686].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5686].entry.ee_code = EEC_USAGE_ENGINE_TEST_PAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5686].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5686].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<ENGINE_TEST_PAD>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5686].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5687].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5687].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5687].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5687].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5687].entry.ee_code = EEC_USAGE_TRANSIENT_APRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5687].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5687].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<TRANSIENT_APRON>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5687].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5688].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5688].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5688].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5688].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5688].entry.ee_code = EEC_USAGE_DEPOT_APRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5688].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5688].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<DEPOT_APRON>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5688].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5689].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5689].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5689].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5689].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5689].entry.ee_code = EEC_USAGE_STUB_APRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5689].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5689].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<STUB_APRON>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5689].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5690].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5690].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5690].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5690].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5690].entry.ee_code = EEC_USAGE_DISPERSAL_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5690].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5690].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<DISPERSAL_HARD_STANDING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5690].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5691].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5691].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5691].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5691].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5691].entry.ee_code = EEC_USAGE_PAD_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5691].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5691].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<PAD_HARD_STANDING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5691].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5692].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5692].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5692].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5692].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5692].entry.ee_code = EEC_USAGE_REFUELLING_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5692].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5692].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<REFUELING_HARD_STANDING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5692].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5693].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5693].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5693].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5693].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5693].entry.ee_code = EEC_USAGE_PARKING_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5693].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5693].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<PARKING_HARD_STANDING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5693].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5694].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5694].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5694].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5694].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5694].entry.ee_code = EEC_USAGE_ENGINE_RUN_UP_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5694].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5694].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<ENGINE_RUN_UP_HARD_STANDING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5694].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5695].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5695].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5695].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5695].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5695].entry.ee_code = EEC_USAGE_FIRING_IN_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5695].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5695].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<FIRING_IN_HARD_STANDING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5695].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5696].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5696].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5696].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5696].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5696].entry.ee_code = EEC_USAGE_COMPASS_ROSE_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5696].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5696].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<COMPASS_ROSE_HARD_STANDING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5696].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5697].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5697].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5697].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5697].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5697].entry.ee_code = EEC_USAGE_MAINTENANCE_HARDSTAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5697].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5697].entry.information = "Note that this can also be mapped as <<APRON_HARD_STANDING_FUNCTION>>*<<<MAINTENANCE_HARD_STANDING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5697].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5698].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5698].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5698].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5698].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5698].entry.ee_code = EEC_USAGE_QUATERNARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5698].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5698].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5698].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5699].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5699].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5699].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5699].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5699].entry.ee_code = EEC_USAGE_QUINTARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5699].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5699].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5699].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5700].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5700].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5700].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5700].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5700].entry.ee_code = EEC_USAGE_REGIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5700].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5700].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<REGIONAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5700].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5701].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5701].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5701].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5701].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5701].entry.ee_code = EEC_USAGE_COMMUNAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5701].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5701].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<COMMUNAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5701].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5702].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5702].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5702].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5702].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5702].entry.ee_code = EEC_USAGE_SNOW_SHED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5702].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5702].entry.information = "Note that this can also be mapped as <<PROTECTION_SHED_TYPE>>*<<<SNOW_SHED>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5702].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5703].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5703].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5703].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5703].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5703].entry.ee_code = EEC_USAGE_ROCK_SHED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5703].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5703].entry.information = "Note that this can also be mapped as <<PROTECTION_SHED_TYPE>>*<<<ROCK_SHED>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5703].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5704].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5704].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5704].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5704].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5704].entry.ee_code = EEC_USAGE_OUTFALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5704].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5704].entry.information = "Note that this can also be mapped as <<UTILITY_USE>>*<<<OUTFALL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5704].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5705].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5705].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5705].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5705].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5705].entry.ee_code = EEC_USAGE_INTAKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5705].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5705].entry.information = "Note that this can also be mapped as <<UTILITY_USE>>*<<<WATER_INTAKE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5705].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5706].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5706].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5706].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5706].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5706].entry.ee_code = EEC_USAGE_VESSEL_BERTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5706].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5706].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<VESSEL_BERTH>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5706].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5707].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5707].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5707].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5707].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5707].entry.ee_code = EEC_USAGE_RECREATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5707].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5707].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<RECREATION>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5707].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5708].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5708].enum_val = 121;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5708].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5708].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5708].entry.ee_code = EEC_USAGE_AIRCRAFT_FACILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5708].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5708].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5708].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5709].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5709].enum_val = 122;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5709].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5709].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5709].entry.ee_code = EEC_USAGE_FIREBREAK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5709].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5709].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<FIREBREAK>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5709].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5710].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5710].enum_val = 123;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5710].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5710].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5710].entry.ee_code = EEC_USAGE_TOURIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5710].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5710].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<TOURIST>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5710].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5711].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5711].enum_val = 124;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5711].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5711].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5711].entry.ee_code = EEC_USAGE_IRRIGATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5711].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5711].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<IRRIGATION>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5711].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5712].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5712].enum_val = 125;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5712].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5712].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5712].entry.ee_code = EEC_USAGE_RETAINING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5712].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5712].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<RETAINING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5712].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5713].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5713].enum_val = 127;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5713].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5713].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5713].entry.ee_code = EEC_USAGE_CAUSEWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5713].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5713].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<CAUSEWAY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5713].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5714].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5714].enum_val = 128;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5714].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5714].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5714].entry.ee_code = EEC_USAGE_MIXED_URBAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5714].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5714].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<MIXED_URBAN>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5714].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5715].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5715].enum_val = 129;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5715].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5715].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5715].entry.ee_code = EEC_USAGE_MILITARY_DISTRICT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5715].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5715].entry.information = "Note that this can also be mapped as <<CONTROLLING_AUTHORITY>>*<<<MILITARY_DISTRICT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5715].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5716].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5716].enum_val = 130;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5716].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5716].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5716].entry.ee_code = EEC_USAGE_TRANSPORTATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5716].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5716].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<TRANSPORTATION>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5716].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5717].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5717].enum_val = 131;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5717].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5717].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5717].entry.ee_code = EEC_USAGE_FLOOD_BARRAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5717].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5717].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<FLOOD_BARRAGE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5717].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5718].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5718].enum_val = 132;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5718].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5718].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5718].entry.ee_code = EEC_USAGE_CONTAINER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5718].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5718].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<CONTAINER>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5718].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5719].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5719].enum_val = 133;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5719].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5719].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5719].entry.ee_code = EEC_USAGE_SINGLE_POINT_MOORING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5719].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5719].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<SINGLE_POINT_MOORING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs. Note that <<MARINE_USE>> is defined in terms of <MARINE_OBJECT> rather than the more general <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5719].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5720].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5720].enum_val = 134;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5720].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5720].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5720].entry.ee_code = EEC_USAGE_UTILITY_OR_COMMUNICATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5720].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5720].entry.information = "Note that this can also be mapped as <<UTILITY_USE>>*EV EVC_UNDESIGNATED (if an exclusive or semantic is intended) or <<UTILITY_USE>>*<<<UTILITY_COMMUNICATION>>> (if an \"and\" semantic is intended), since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5720].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5721].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5721].enum_val = 136;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5721].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5721].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5721].entry.ee_code = EEC_USAGE_AS_FILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5721].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5721].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5721].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5722].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5722].enum_val = 139;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5722].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5722].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5722].entry.ee_code = EEC_USAGE_FILL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5722].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5722].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5722].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5723].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5723].enum_val = 140;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5723].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5723].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5723].entry.ee_code = EEC_USAGE_MEDICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5723].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5723].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<MEDICAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5723].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5724].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5724].enum_val = 141;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5724].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5724].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5724].entry.ee_code = EEC_USAGE_FOREST_PRESERVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5724].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5724].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<FOREST_PRESERVE>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5724].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5725].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5725].enum_val = 142;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5725].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5725].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5725].entry.ee_code = EEC_USAGE_FLOOD_CONTROL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5725].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5725].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<FLOOD_CONTROL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5725].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5726].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5726].enum_val = 143;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5726].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5726].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5726].entry.ee_code = EEC_USAGE_ARIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5726].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5726].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_POINT_FUNCTION>>*<<<ARIP_INITIAL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5726].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5727].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5727].enum_val = 144;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5727].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5727].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5727].entry.ee_code = EEC_USAGE_ARCP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5727].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5727].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_POINT_FUNCTION>>*<<<ARCP_CONTROL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5727].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5728].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5728].enum_val = 145;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5728].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5728].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5728].entry.ee_code = EEC_USAGE_NAVIGATION_CHECK_POINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5728].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5728].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_POINT_FUNCTION>>*<<<NAVIGATION_CHECK>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5728].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5729].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5729].enum_val = 146;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5729].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5729].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5729].entry.ee_code = EEC_USAGE_EXIT_OR_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5729].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5729].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5729].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5730].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5730].enum_val = 147;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5730].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5730].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5730].entry.ee_code = EEC_USAGE_ENTRY_OR_STARTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5730].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5730].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5730].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5731].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5731].enum_val = 148;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5731].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5731].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5731].entry.ee_code = EEC_USAGE_ANCHOR_POINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5731].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5731].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<ANCHOR_POINT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5731].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5732].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5732].enum_val = 150;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5732].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5732].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5732].entry.ee_code = EEC_USAGE_ALTERNATE_ENTRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5732].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5732].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<ALTERNATE_ENTRY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5732].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5733].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5733].enum_val = 151;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5733].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5733].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5733].entry.ee_code = EEC_USAGE_ALTERNATE_EXIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5733].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5733].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<ALTERNATE_EXIT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5733].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5734].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5734].enum_val = 152;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5734].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5734].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5734].entry.ee_code = EEC_USAGE_ALTERNATE_ENTRY_OR_EXIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5734].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5734].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<ALTERNATE_ENTRY_EXIT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5734].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5735].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5735].enum_val = 153;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5735].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5735].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5735].entry.ee_code = EEC_USAGE_TURNING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5735].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5735].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<TURNING>>>, since <<USAGE>> has been deprecated and refactored into separate EAs. Note that <<MARINE_USE>> is defined in terms of <MARINE_OBJECT> rather than <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5735].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5736].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5736].enum_val = 154;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5736].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5736].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5736].entry.ee_code = EEC_USAGE_COMPASS_ADJUSTMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5736].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5736].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<COMPASS_ADJUSTMENT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5736].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5737].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5737].enum_val = 155;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5737].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5737].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5737].entry.ee_code = EEC_USAGE_PROHIBITED_AREA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5737].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5737].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<PROHIBITED_REGION>>>, since <<USAGE>> has been deprecated and refactored into separate EAs. Note that <<MARINE_USE>> is defined in terms of <MARINE_OBJECT> rather than <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5737].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5738].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5738].enum_val = 156;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5738].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5738].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5738].entry.ee_code = EEC_USAGE_TIMEBALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5738].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5738].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<TIMEBALL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs. Note that <<MARINE_USE>> is defined in terms of <MARINE_OBJECT> rather than <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5738].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5739].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5739].enum_val = 157;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5739].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5739].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5739].entry.ee_code = EEC_USAGE_CLOCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5739].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5739].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<CLOCK>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5739].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5740].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5740].enum_val = 158;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5740].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5740].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5740].entry.ee_code = EEC_USAGE_RESERVED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5740].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5740].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<RESERVED>>>, since <<USAGE>> has been deprecated and refactored into separate EAs. Note that <<MARINE_USE>> is defined in terms of <MARINE_OBJECT> rather than <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5740].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5741].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5741].enum_val = 159;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5741].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5741].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5741].entry.ee_code = EEC_USAGE_MANDATORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5741].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5741].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<MANDATORY>>>, since <<USAGE>> has been deprecated and refactored into separate EAs. Note that <<MARINE_USE>> is defined for <MARINE_OBJECT> rather than <OBJECT>.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5741].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5742].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5742].enum_val = 160;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5742].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5742].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5742].entry.ee_code = EEC_USAGE_MARINE_STATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5742].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5742].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<MARINE_STATION>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5742].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5743].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5743].enum_val = 900;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5743].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5743].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5743].entry.ee_code = EEC_USAGE_BUTTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5743].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5743].entry.information = "Note that this can also be mapped as <<MARINE_USE>>*<<<BUTTS>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5743].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5744].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5744].enum_val = 901;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5744].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5744].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5744].entry.ee_code = EEC_USAGE_SCHOOL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5744].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5744].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<SCHOOL>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5744].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5745].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5745].enum_val = 986;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5745].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5745].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5745].entry.ee_code = EEC_USAGE_MILITARY_DISTRICT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5745].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5745].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Military District)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5745].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5746].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5746].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5746].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5746].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5746].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5746].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5746].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5746].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5747].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5747].enum_val = 990;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5747].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5747].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5747].entry.ee_code = EEC_USAGE_UNPOPULATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5747].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5747].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5747].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5748].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5748].enum_val = 991;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5748].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5748].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5748].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5748].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5748].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5748].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5749].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5749].enum_val = 992;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5749].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5749].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5749].entry.ee_code = EEC_USAGE_DRAG_STRIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5749].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5749].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<DRAG_STRIP>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5749].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5750].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5750].enum_val = 993;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5750].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5750].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5750].entry.ee_code = EEC_USAGE_FILTRATION_POND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5750].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5750].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<FILTRATION_POND>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5750].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5751].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5751].enum_val = 994;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5751].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5751].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5751].entry.ee_code = EEC_USAGE_DUGOUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5751].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5751].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<DUGOUT>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5751].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5752].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5752].enum_val = 995;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5752].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5752].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5752].entry.ee_code = EEC_USAGE_DRINKING_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5752].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5752].entry.information = "Note that this can also be mapped as <<UTILITY_USE>>*<<<DRINKING_WATER>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5752].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5753].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5753].enum_val = 996;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5753].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5753].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5753].entry.ee_code = EEC_USAGE_TRIANGULATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5753].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5753].entry.information = "Note that this can also be mapped as <<UTILITY_USE>>*<<<TRIANGULATION>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5753].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5754].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5754].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5754].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5754].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5754].entry.ee_code = EEC_USAGE_CABLE_PIPE_SIGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5754].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5754].entry.information = "Note that this can also be mapped as <<FUNCTIONAL_USE>>*<<<CABLE_PIPE_SIGN>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5754].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5755].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5755].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5755].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5755].entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5755].entry.ee_code = EEC_USAGE_SEAPLANE_RUN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5755].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5755].entry.information = "Note that this can also be mapped as <<AERONAUTICAL_FUNCTION>>*<<<SEAPLANE_RUN>>>, since <<USAGE>> has been deprecated and refactored into separate EAs.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5755].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5756].code.tag, "USE", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5756].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5756].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5756].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5756].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5756].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5756].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5756].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5757].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5757].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5757].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5757].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5757].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5757].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5757].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_URBAN_STREET_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5757].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5758].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5758].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5758].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5758].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5758].entry.ee_code = EEC_URBSTREETPAT_REG_GRID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5758].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5758].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5758].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5759].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5759].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5759].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5759].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5759].entry.ee_code = EEC_URBSTREETPAT_IRREG_GRID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5759].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5759].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5759].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5760].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5760].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5760].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5760].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5760].entry.ee_code = EEC_URBSTREETPAT_CURVILINEAR_CLUSTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5760].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5760].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5760].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5761].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5761].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5761].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5761].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5761].entry.ee_code = EEC_URBSTREETPAT_REG_RADIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5761].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5761].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5761].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5762].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5762].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5762].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5762].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5762].entry.ee_code = EEC_URBSTREETPAT_IRREG_RADIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5762].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5762].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5762].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5763].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5763].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5763].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5763].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5763].entry.ee_code = EEC_URBSTREETPAT_MIXED_CLUSTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5763].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5763].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5763].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5764].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5764].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5764].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5764].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5764].entry.ee_code = EEC_URBSTREETPAT_MIXED_GRID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5764].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5764].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5764].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5765].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5765].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5765].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5765].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5765].entry.ee_code = EEC_URBSTREETPAT_MIXED_RADIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5765].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5765].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5765].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5766].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5766].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5766].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5766].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5766].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5766].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5766].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_URBAN_STREET_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5766].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5767].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5767].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5767].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5767].entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5767].entry.ee_code = EEC_URBSTREETPAT_LINEAR_STRIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5767].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5767].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5767].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5768].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5768].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5768].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5768].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5768].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5768].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5768].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_URBAN_STREET_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5768].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5769].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5769].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5769].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5769].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5769].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5769].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5769].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_URBAN_STREET_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5769].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5770].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5770].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5770].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5770].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5770].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5770].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5770].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_URBAN_STREET_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5770].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5771].code.tag, "USP", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5771].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5771].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5771].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5771].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5771].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5771].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_URBAN_STREET_PATTERN;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5771].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5772].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5772].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5772].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5772].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5772].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5772].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5772].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5772].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5773].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5773].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5773].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5773].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5773].entry.ee_code = EEC_DATACOLLCRIT_NOT_REQUESTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5773].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5773].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5773].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5774].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5774].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5774].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5774].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5774].entry.ee_code = EEC_DATACOLLCRIT_TOO_ROUGH_TO_COLLECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5774].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5774].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5774].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5775].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5775].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5775].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5775].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5775].entry.ee_code = EEC_DATACOLLCRIT_NO_AVAILABLE_IMAGERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5775].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5775].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5775].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5776].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5776].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5776].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5776].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5776].entry.ee_code = EEC_DATACOLLCRIT_DIFFERENT_HEIGHT_THRESHOLD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5776].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5776].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5776].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5777].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5777].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5777].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5777].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5777].entry.ee_code = EEC_DATACOLLCRIT_LOW_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5777].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5777].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5777].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5778].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5778].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5778].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5778].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5778].entry.ee_code = EEC_DATACOLLCRIT_NO_AVAILABLE_MAP_SOURCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5778].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5778].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5778].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5779].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5779].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5779].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5779].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5779].entry.ee_code = EEC_DATACOLLCRIT_NO_SUITABLE_IMAGERY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5779].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5779].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5779].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5780].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5780].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5780].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5780].entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5780].entry.ee_code = EEC_DATACOLLCRIT_NOT_REQUIRED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5780].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5780].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5780].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5781].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5781].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5781].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5781].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5781].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5781].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5781].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5781].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5782].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5782].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5782].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5782].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5782].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5782].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5782].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5782].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5783].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5783].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5783].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5783].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5783].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5783].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5783].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5783].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5784].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5784].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5784].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5784].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5784].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5784].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5784].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5784].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5785].code.tag, "VCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5785].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5785].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5785].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5785].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5785].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5785].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSING_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5785].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5786].code.tag, "VCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5786].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5786].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5786].entry.ea_code = EAC_MISSING_INFORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5786].entry.ee_code = EEC_MISSINFTY_TERRAIN_RELIEF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5786].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5786].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5786].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5787].code.tag, "VCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5787].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5787].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5787].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5787].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5787].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5787].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Other)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSING_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5787].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5788].code.tag, "VCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5788].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5788].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5788].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5788].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5788].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5788].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSING_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5788].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5789].code.tag, "VCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5789].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5789].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5789].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5789].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5789].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5789].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSING_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5789].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5790].code.tag, "VCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5790].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5790].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5790].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5790].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5790].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5790].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSING_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5790].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5791].code.tag, "VCT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5791].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5791].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5791].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5791].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5791].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5791].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MISSING_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5791].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5792].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5792].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5792].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5792].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5792].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5792].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5792].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5792].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5793].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5793].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5793].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5793].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5793].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5793].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5793].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5793].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5794].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5794].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5794].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5794].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5794].entry.ee_code = EEC_SNDGDTMTY_HIGH_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5794].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5794].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5794].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5795].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5795].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5795].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5795].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5795].entry.ee_code = EEC_SNDGDTMTY_HGHR_HIGH_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5795].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5795].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5795].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5796].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5796].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5796].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5796].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5796].entry.ee_code = EEC_SNDGDTMTY_INDIAN_SPRING_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5796].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5796].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5796].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5797].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5797].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5797].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5797].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5797].entry.ee_code = EEC_SNDGDTMTY_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5797].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5797].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5797].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5798].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5798].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5798].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5798].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5798].entry.ee_code = EEC_SNDGDTMTY_LOWER_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5798].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5798].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5798].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5799].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5799].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5799].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5799].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5799].entry.ee_code = EEC_SNDGDTMTY_MEAN_HIGH_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5799].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5799].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5799].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5800].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5800].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5800].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5800].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5800].entry.ee_code = EEC_SNDGDTMTY_MEAN_HIGH_NEAPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5800].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5800].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5800].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5801].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5801].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5801].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5801].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5801].entry.ee_code = EEC_SNDGDTMTY_MEAN_HIGH_SPRINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5801].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5801].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5801].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5802].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5802].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5802].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5802].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5802].entry.ee_code = EEC_SNDGDTMTY_MEAN_HGHR_HIGH_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5802].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5802].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5802].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5803].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5803].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5803].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5803].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5803].entry.ee_code = EEC_SNDGDTMTY_MEAN_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5803].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5803].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5803].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5804].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5804].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5804].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5804].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5804].entry.ee_code = EEC_SNDGDTMTY_MEAN_LOW_NEAPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5804].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5804].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5804].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5805].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5805].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5805].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5805].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5805].entry.ee_code = EEC_SNDGDTMTY_MEAN_LOW_SPRINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5805].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5805].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5805].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5806].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5806].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5806].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5806].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5806].entry.ee_code = EEC_SNDGDTMTY_MEAN_LOWER_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5806].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5806].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5806].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5807].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5807].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5807].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5807].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5807].entry.ee_code = EEC_SNDGDTMTY_MEAN_SEA_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5807].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5807].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5807].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5808].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5808].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5808].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5808].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5808].entry.ee_code = EEC_SNDGDTMTY_MEAN_TIDE_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5808].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5808].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5808].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5809].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5809].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5809].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5809].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5809].entry.ee_code = EEC_SNDGDTMTY_NEAP_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5809].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5809].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5809].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5810].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5810].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5810].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5810].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5810].entry.ee_code = EEC_SNDGDTMTY_SPRING_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5810].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5810].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5810].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5811].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5811].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5811].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5811].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5811].entry.ee_code = EEC_SNDGDTMTY_MEAN_LOWER_LOW_SPRINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5811].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5811].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5811].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5812].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5812].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5812].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5812].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5812].entry.ee_code = EEC_SNDGDTMTY_LOWEST_ASTRONOMICAL_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5812].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5812].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5812].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5813].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5813].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5813].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5813].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5813].entry.ee_code = EEC_SNDGDTMTY_CHART_DATUM_UNSPECIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5813].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5813].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5813].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5814].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5814].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5814].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5814].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5814].entry.ee_code = EEC_SNDGDTMTY_HIGHEST_ASTRONOMICAL_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5814].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5814].entry.information = "Now deprecated by FACC; use VDC_106.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5814].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5815].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5815].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5815].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5815].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5815].entry.ee_code = EEC_SNDGDTMTY_MEAN_HGHR_HIGH_SPRINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5815].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5815].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5815].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5816].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5816].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5816].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5816].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5816].entry.ee_code = EEC_SNDGDTMTY_HIGHEST_NORMAL_HIGH_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5816].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5816].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5816].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5817].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5817].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5817].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5817].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5817].entry.ee_code = EEC_SNDGDTMTY_HIGHEST_HIGH_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5817].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5817].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5817].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5818].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5818].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5818].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5818].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5818].entry.ee_code = EEC_SNDGDTMTY_INDIAN_SPRING_HIGH_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5818].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5818].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5818].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5819].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5819].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5819].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5819].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5819].entry.ee_code = EEC_SNDGDTMTY_LOWEST_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5819].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5819].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5819].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5820].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5820].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5820].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5820].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5820].entry.ee_code = EEC_SNDGDTMTY_LOWEST_LOW_SPRINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5820].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5820].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5820].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5821].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5821].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5821].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5821].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5821].entry.ee_code = EEC_SNDGDTMTY_APPROX_MEAN_LOW_SPRINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5821].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5821].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5821].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5822].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5822].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5822].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5822].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5822].entry.ee_code = EEC_SNDGDTMTY_LOW_WATER_SPRINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5822].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5822].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5822].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5823].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5823].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5823].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5823].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5823].entry.ee_code = EEC_SNDGDTMTY_APPROX_LOWEST_ASTRONOMICAL_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5823].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5823].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5823].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5824].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5824].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5824].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5824].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5824].entry.ee_code = EEC_SNDGDTMTY_NEARLY_LOWEST_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5824].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5824].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5824].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5825].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5825].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5825].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5825].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5825].entry.ee_code = EEC_SNDGDTMTY_APPROX_MEAN_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5825].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5825].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5825].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5826].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5826].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5826].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5826].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5826].entry.ee_code = EEC_SNDGDTMTY_APPROX_MEAN_LOWER_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5826].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5826].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5826].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5827].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5827].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5827].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5827].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5827].entry.ee_code = EEC_SNDGDTMTY_APPROX_MEAN_SEA_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5827].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5827].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5827].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5828].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5828].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5828].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5828].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5828].entry.ee_code = EEC_SNDGDTMTY_HIGH_WATER_SPRINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5828].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5828].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5828].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5829].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5829].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5829].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5829].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5829].entry.ee_code = EEC_SNDGDTMTY_EQUINOCTIAL_SPRING_LOW_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5829].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5829].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5829].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5830].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5830].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5830].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5830].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5830].entry.ee_code = EEC_SNDGDTMTY_LOCAL_DATUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5830].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5830].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5830].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5831].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5831].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5831].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5831].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5831].entry.ee_code = EEC_SNDGDTMTY_IGLD_1985;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5831].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5831].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5831].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5832].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5832].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5832].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5832].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5832].entry.ee_code = EEC_SNDGDTMTY_MEAN_WATER_LEVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5832].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5832].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5832].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5833].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5833].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5833].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5833].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5833].entry.ee_code = EEC_SNDGDTMTY_LOWER_LOW_LARGE_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5833].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5833].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5833].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5834].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5834].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5834].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5834].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5834].entry.ee_code = EEC_SNDGDTMTY_HGHR_HIGH_LARGE_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5834].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5834].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5834].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5835].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5835].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5835].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5835].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5835].entry.ee_code = EEC_SNDGDTMTY_HIGHEST_ASTRONOMICAL_TIDE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5835].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5835].entry.information = "Was: \"Highest Astronomical Tide\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5835].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5836].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5836].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5836].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5836].entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5836].entry.ee_code = EEC_SNDGDTMTY_NEARLY_HIGHEST_HIGH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5836].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5836].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5836].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5837].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5837].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5837].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5837].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5837].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5837].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5837].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5837].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5838].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5838].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5838].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5838].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5838].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5838].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5838].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5838].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5839].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5839].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5839].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5839].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5839].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5839].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5839].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5839].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5840].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5840].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5840].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5840].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5840].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5840].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5840].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5840].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5841].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5841].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5841].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5841].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5841].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5841].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5841].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5841].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5842].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5842].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5842].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5842].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5842].entry.ee_code = EEC_VEGTY_DRY_CROPS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5842].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5842].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5842].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5843].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5843].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5843].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5843].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5843].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5843].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5843].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5843].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5844].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5844].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5844].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5844].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5844].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5844].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5844].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5844].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5845].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5845].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5845].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5845].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5845].entry.ee_code = EEC_VEGTY_RICE_FIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5845].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5845].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5845].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5846].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5846].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5846].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5846].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5846].entry.ee_code = EEC_VEGTY_AGRI_SCATTERED_FORESTS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5846].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5846].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5846].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5847].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5847].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5847].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5847].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5847].entry.ee_code = EEC_VEGTY_CRANBERRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5847].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5847].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5847].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5848].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5848].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5848].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5848].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5848].entry.ee_code = EEC_VEGTY_PEAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5848].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5848].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5848].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5849].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5849].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5849].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5849].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5849].entry.ee_code = EEC_VEGTY_GRASS_LAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5849].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5849].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5849].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5850].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5850].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5850].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5850].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5850].entry.ee_code = EEC_VEGTY_GRASS_LAND_SCATTERED_TREES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5850].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5850].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5850].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5851].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5851].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5851].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5851].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5851].entry.ee_code = EEC_VEGTY_TROPICAL_GRASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5851].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5851].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5851].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5852].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5852].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5852].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5852].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5852].entry.ee_code = EEC_VEGTY_CASUARINA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5852].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5852].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5852].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5853].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5853].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5853].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5853].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5853].entry.ee_code = EEC_VEGTY_CONIFER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5853].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5853].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5853].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5854].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5854].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5854].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5854].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5854].entry.ee_code = EEC_VEGTY_NIPA_PALM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5854].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5854].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5854].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5855].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5855].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5855].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5855].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5855].entry.ee_code = EEC_VEGTY_PALM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5855].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5855].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5855].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5856].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5856].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5856].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5856].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5856].entry.ee_code = EEC_VEGTY_FILAO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5856].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5856].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5856].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5857].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5857].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5857].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5857].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5857].entry.ee_code = EEC_VEGTY_MANGROVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5857].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5857].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5857].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5858].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5858].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5858].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5858].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5858].entry.ee_code = EEC_VEGTY_GROVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5858].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5858].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5858].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5859].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5859].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5859].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5859].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5859].entry.ee_code = EEC_VEGTY_WHEAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5859].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5859].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5859].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5860].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5860].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5860].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5860].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5860].entry.ee_code = EEC_VEGTY_MAIZE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5860].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5860].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5860].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5861].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5861].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5861].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5861].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5861].entry.ee_code = EEC_VEGTY_DECIDUOUS_UNSPECIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5861].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5861].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5861].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5862].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5862].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5862].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5862].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5862].entry.ee_code = EEC_VEGTY_EVERGREEN_UNSPECIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5862].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5862].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5862].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5863].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5863].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5863].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5863].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5863].entry.ee_code = EEC_VEGTY_CORK_OAK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5863].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5863].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5863].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5864].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5864].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5864].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5864].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5864].entry.ee_code = EEC_VEGTY_FIR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5864].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5864].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5864].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5865].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5865].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5865].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5865].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5865].entry.ee_code = EEC_VEGTY_BEECH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5865].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5865].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5865].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5866].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5866].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5866].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5866].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5866].entry.ee_code = EEC_VEGTY_EUCALYPTUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5866].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5866].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5866].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5867].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5867].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5867].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5867].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5867].entry.ee_code = EEC_VEGTY_OAK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5867].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5867].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5867].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5868].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5868].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5868].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5868].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5868].entry.ee_code = EEC_VEGTY_PINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5868].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5868].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5868].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5869].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5869].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5869].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5869].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5869].entry.ee_code = EEC_VEGTY_WALNUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5869].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5869].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5869].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5870].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5870].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5870].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5870].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5870].entry.ee_code = EEC_VEGTY_MAPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5870].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5870].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5870].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5871].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5871].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5871].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5871].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5871].entry.ee_code = EEC_VEGTY_POPLAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5871].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5871].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5871].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5872].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5872].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5872].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5872].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5872].entry.ee_code = EEC_VEGTY_OLIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5872].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5872].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5872].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5873].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5873].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5873].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5873].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5873].entry.ee_code = EEC_VEGTY_CHESTNUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5873].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5873].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5873].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5874].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5874].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5874].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5874].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5874].entry.ee_code = EEC_VEGTY_LARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5874].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5874].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5874].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5875].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5875].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5875].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5875].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5875].entry.ee_code = EEC_VEGTY_CYPRESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5875].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5875].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5875].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5876].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5876].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5876].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5876].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5876].entry.ee_code = EEC_VEGTY_PEACH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5876].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5876].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5876].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5877].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5877].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5877].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5877].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5877].entry.ee_code = EEC_VEGTY_APPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5877].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5877].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5877].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5878].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5878].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5878].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5878].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5878].entry.ee_code = EEC_VEGTY_CAROB;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5878].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5878].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5878].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5879].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5879].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5879].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5879].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5879].entry.ee_code = EEC_VEGTY_ALMOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5879].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5879].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5879].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5880].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5880].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5880].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5880].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5880].entry.ee_code = EEC_VEGTY_CITRUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5880].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5880].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5880].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5881].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5881].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5881].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5881].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5881].entry.ee_code = EEC_VEGTY_ELM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5881].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5881].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5881].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5882].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5882].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5882].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5882].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5882].entry.ee_code = EEC_VEGTY_ILEX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5882].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5882].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5882].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5883].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5883].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5883].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5883].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5883].entry.ee_code = EEC_VEGTY_BIRCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5883].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5883].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5883].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5884].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5884].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5884].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5884].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5884].entry.ee_code = EEC_VEGTY_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5884].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5884].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5884].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5885].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5885].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5885].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5885].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5885].entry.ee_code = EEC_VEGTY_HAZEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5885].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5885].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5885].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5886].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5886].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5886].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5886].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5886].entry.ee_code = EEC_VEGTY_MIXED_DECIDUOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5886].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5886].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5886].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5887].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5887].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5887].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5887].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5887].entry.ee_code = EEC_VEGTY_MIXED_TREES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5887].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5887].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5887].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5888].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5888].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5888].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5888].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5888].entry.ee_code = EEC_VEGTY_NON_TREED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5888].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5888].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5888].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5889].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5889].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5889].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5889].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5889].entry.ee_code = EEC_VEGTY_FOREST_CLEARING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5889].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5889].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5889].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5890].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5890].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5890].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5890].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5890].entry.ee_code = EEC_VEGTY_BRUSHLAND_OPEN_TO_MEDIUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5890].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5890].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5890].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5891].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5891].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5891].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5891].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5891].entry.ee_code = EEC_VEGTY_BRUSHLAND_MEDIUM_TO_DENSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5891].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5891].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5891].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5892].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5892].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5892].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5892].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5892].entry.ee_code = EEC_VEGTY_WITH_TREES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5892].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5892].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5892].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5893].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5893].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5893].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5893].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5893].entry.ee_code = EEC_VEGTY_WITHOUT_TREES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5893].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5893].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5893].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5894].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5894].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5894].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5894].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5894].entry.ee_code = EEC_VEGTY_AGRI_SCATTERED_TREES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5894].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5894].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5894].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5895].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5895].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5895].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5895].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5895].entry.ee_code = EEC_VEGTY_REED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5895].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5895].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5895].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5896].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5896].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5896].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5896].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5896].entry.ee_code = EEC_VEGTY_MOSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5896].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5896].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5896].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5897].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5897].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5897].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5897].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5897].entry.ee_code = EEC_VEGTY_KELP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5897].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5897].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5897].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5898].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5898].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5898].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5898].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5898].entry.ee_code = EEC_VEGTY_SEAWEED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5898].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5898].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5898].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5899].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5899].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5899].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5899].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5899].entry.ee_code = EEC_VEGTY_SEA_GRASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5899].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5899].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5899].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5900].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5900].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5900].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5900].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5900].entry.ee_code = EEC_VEGTY_SARGASSUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5900].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5900].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5900].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5901].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5901].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5901].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5901].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5901].entry.ee_code = EEC_VEGTY_TUNDRA_WET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5901].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5901].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5901].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5902].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5902].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5902].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5902].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5902].entry.ee_code = EEC_VEGTY_ALPINE_TUNDRA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5902].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5902].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5902].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5903].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5903].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5903].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5903].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5903].entry.ee_code = EEC_VEGTY_GARDEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5903].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5903].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5903].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5904].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5904].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5904].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5904].entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5904].entry.ee_code = EEC_VEGTY_HEATH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5904].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5904].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5904].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5905].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5905].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5905].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5905].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5905].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5905].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5905].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5905].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5906].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5906].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5906].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5906].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5906].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5906].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5906].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5906].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5907].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5907].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5907].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5907].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5907].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5907].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5907].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5907].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5908].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5908].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5908].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5908].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5908].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5908].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5908].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5908].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5909].code.tag, "VEM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5909].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5909].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5909].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5909].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5909].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5909].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VERTICAL_MEASUREMENT_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5909].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5910].code.tag, "VEM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5910].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5910].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5910].entry.ea_code = EAC_VERTICAL_MEASUREMENT_QUALITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5910].entry.ee_code = EEC_VERTMEASQUAL_MEASURED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5910].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5910].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5910].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5911].code.tag, "VEM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5911].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5911].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5911].entry.ea_code = EAC_VERTICAL_MEASUREMENT_QUALITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5911].entry.ee_code = EEC_VERTMEASQUAL_ESTIMATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5911].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5911].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5911].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5912].code.tag, "VEM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5912].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5912].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5912].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5912].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5912].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5912].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VERTICAL_MEASUREMENT_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5912].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5913].code.tag, "VEM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5913].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5913].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5913].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5913].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5913].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5913].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VERTICAL_MEASUREMENT_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5913].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5914].code.tag, "VEM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5914].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5914].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5914].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5914].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5914].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5914].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VERTICAL_MEASUREMENT_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5914].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5915].code.tag, "VEM", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5915].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5915].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5915].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5915].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5915].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5915].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VERTICAL_MEASUREMENT_QUALITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5915].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5916].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5916].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5916].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5916].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5916].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5916].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5916].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5916].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5917].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5917].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5917].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5917].entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5917].entry.ee_code = EEC_VOLCFORMTY_CONICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5917].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5917].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5917].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5918].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5918].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5918].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5918].entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5918].entry.ee_code = EEC_VOLCFORMTY_CINDER_CONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5918].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5918].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5918].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5919].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5919].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5919].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5919].entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5919].entry.ee_code = EEC_VOLCFORMTY_SHIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5919].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5919].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5919].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5920].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5920].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5920].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5920].entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5920].entry.ee_code = EEC_VOLCFORMTY_CALDERA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5920].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5920].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5920].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5921].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5921].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5921].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5921].entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5921].entry.ee_code = EEC_VOLCFORMTY_COMPOSITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5921].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5921].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5921].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5922].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5922].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5922].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5922].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5922].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5922].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5922].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5922].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5923].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5923].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5923].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5923].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5923].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5923].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5923].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5923].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5924].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5924].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5924].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5924].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5924].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5924].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5924].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5924].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5925].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5925].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5925].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5925].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5925].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5925].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5925].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5925].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5926].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5926].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5926].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5926].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5926].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5926].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5926].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5926].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5927].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5927].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5927].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5927].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5927].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5927].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5927].entry.information = "<= 2 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 2.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5927].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5928].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5928].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5928].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5928].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5928].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5928].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5928].entry.information = "> 2 metres and <= 5 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 2.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5928].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5929].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5929].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5929].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5929].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5929].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5929].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5929].entry.information = "> 5 metres and <= 10 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5929].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5930].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5930].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5930].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5930].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5930].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5930].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5930].entry.information = "> 10 metres and <= 15 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 15.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5930].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5931].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5931].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5931].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5931].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5931].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5931].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5931].entry.information = "> 15 metres and <= 20 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 15.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5931].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5932].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5932].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5932].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5932].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5932].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5932].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5932].entry.information = "> 20 metres and <= 30 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5932].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5933].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5933].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5933].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5933].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5933].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5933].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5933].entry.information = "> 30 metres and <= 40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5933].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5934].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5934].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5934].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5934].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5934].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5934].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5934].entry.information = "> 40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5934].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5935].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5935].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5935].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5935].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5935].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5935].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5935].entry.information = "> 20 metres and <= 25 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 25.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5935].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5936].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5936].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5936].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5936].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5936].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5936].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5936].entry.information = "> 25 metres and <= 30 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 25.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 30.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5936].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5937].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5937].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5937].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5937].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5937].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5937].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5937].entry.information = "> 30 metres and <= 35 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 35.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5937].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5938].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5938].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5938].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5938].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5938].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5938].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5938].entry.information = "> 35 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 35.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5938].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5939].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5939].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5939].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5939].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5939].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5939].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5939].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5939].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5940].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5940].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5940].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5940].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5940].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5940].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5940].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5940].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5941].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5941].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5941].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5941].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5941].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5941].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5941].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5941].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5942].code.tag, "VH2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5942].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5942].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5942].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5942].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5942].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5942].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5942].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5943].code.tag, "VH2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5943].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5943].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5943].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5943].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5943].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5943].entry.information = "<= 5 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5943].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5944].code.tag, "VH2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5944].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5944].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5944].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5944].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5944].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5944].entry.information = "> 5 metres and <= 20 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5944].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5945].code.tag, "VH2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5945].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5945].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5945].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5945].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5945].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5945].entry.information = "> 20 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5945].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5946].code.tag, "VH2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5946].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5946].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5946].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5946].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5946].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5946].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5946].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5947].code.tag, "VH2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5947].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5947].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5947].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5947].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5947].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5947].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5947].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5948].code.tag, "VH2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5948].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5948].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5948].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5948].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5948].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5948].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5948].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5949].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5949].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5949].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5949].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5949].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5949].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5949].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5949].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5950].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5950].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5950].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5950].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5950].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5950].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5950].entry.information = "<= 5 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5950].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5951].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5951].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5951].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5951].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5951].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5951].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5951].entry.information = "> 5 metres and <= 10 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5951].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5952].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5952].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5952].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5952].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5952].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5952].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5952].entry.information = "> 10 metres and <= 20 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5952].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5953].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5953].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5953].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5953].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5953].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5953].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5953].entry.information = "> 20 metres and <= 40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5953].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5954].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5954].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5954].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5954].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5954].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5954].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5954].entry.information = "> 40 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 40.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5954].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5955].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5955].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5955].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5955].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5955].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5955].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5955].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5955].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5956].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5956].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5956].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5956].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5956].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5956].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5956].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5956].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5957].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5957].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5957].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5957].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5957].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5957].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5957].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5957].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5958].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5958].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5958].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5958].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5958].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5958].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5958].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_VISIBILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5958].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5959].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5959].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5959].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5959].entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5959].entry.ee_code = EEC_LGTVIS_HIGH_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5959].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5959].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5959].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5960].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5960].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5960].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5960].entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5960].entry.ee_code = EEC_LGTVIS_LOW_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5960].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5960].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5960].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5961].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5961].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5961].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5961].entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5961].entry.ee_code = EEC_LGTVIS_FAINT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5961].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5961].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5961].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5962].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5962].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5962].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5962].entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5962].entry.ee_code = EEC_LGTVIS_INTENSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5962].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5962].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5962].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5963].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5963].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5963].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5963].entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5963].entry.ee_code = EEC_LGTVIS_UNINTENSIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5963].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5963].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5963].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5964].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5964].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5964].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5964].entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5964].entry.ee_code = EEC_LGTVIS_DELIBERATELY_RESTRICTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5964].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5964].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5964].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5965].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5965].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5965].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5965].entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5965].entry.ee_code = EEC_LGTVIS_OBSCURED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5965].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5965].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5965].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5966].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5966].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5966].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5966].entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5966].entry.ee_code = EEC_LGTVIS_PARTIALLY_OBSCURED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5966].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5966].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5966].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5967].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5967].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5967].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5967].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5967].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5967].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5967].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_VISIBILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5967].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5968].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5968].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5968].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5968].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5968].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5968].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5968].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_VISIBILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5968].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5969].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5969].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5969].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5969].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5969].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5969].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5969].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_VISIBILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5969].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5970].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5970].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5970].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5970].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5970].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5970].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5970].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_VISIBILITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5970].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5971].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5971].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5971].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5971].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5971].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5971].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5971].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5971].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5972].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5972].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5972].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5972].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5972].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5972].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5972].entry.information = "100% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 0.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5972].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5973].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5973].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5973].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5973].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5973].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5973].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5973].entry.information = "95% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5973].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5974].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5974].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5974].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5974].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5974].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5974].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5974].entry.information = "90% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5974].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5975].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5975].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5975].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5975].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5975].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5975].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5975].entry.information = "85% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 15.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5975].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5976].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5976].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5976].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5976].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5976].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5976].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5976].entry.information = "80% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5976].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5977].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5977].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5977].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5977].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5977].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5977].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5977].entry.information = "75% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 25.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5977].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5978].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5978].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5978].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5978].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5978].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5978].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5978].entry.information = "70% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 30.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5978].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5979].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5979].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5979].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5979].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5979].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5979].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5979].entry.information = "65% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 35.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5979].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5980].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5980].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5980].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5980].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5980].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5980].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5980].entry.information = "60% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 40.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5980].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5981].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5981].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5981].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5981].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5981].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5981].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5981].entry.information = "55% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 45.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5981].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5982].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5982].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5982].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5982].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5982].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5982].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5982].entry.information = "50% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 50.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5982].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5983].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5983].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5983].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5983].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5983].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5983].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5983].entry.information = "45% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 55.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5983].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5984].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5984].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5984].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5984].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5984].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5984].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5984].entry.information = "40% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 60.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5984].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5985].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5985].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5985].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5985].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5985].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5985].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5985].entry.information = "35% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 65.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5985].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5986].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5986].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5986].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5986].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5986].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5986].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5986].entry.information = "30% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 70.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5986].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5987].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5987].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5987].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5987].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5987].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5987].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5987].entry.information = "25% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 75.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5987].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5988].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5988].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5988].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5988].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5988].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5988].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5988].entry.information = "20% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 80.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5988].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5989].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5989].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5989].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5989].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5989].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5989].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5989].entry.information = "15% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 85.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5989].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5990].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5990].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5990].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5990].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5990].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5990].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5990].entry.information = "10% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 90.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5990].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5991].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5991].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5991].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5991].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5991].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5991].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5991].entry.information = "5% speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 95.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5991].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5992].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5992].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5992].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5992].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5992].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5992].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5992].entry.information = "No speed reduction.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.single_value = 100.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_PERCENT;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5992].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5993].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5993].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5993].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5993].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5993].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5993].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5993].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5993].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5994].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5994].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5994].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5994].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5994].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5994].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5994].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5994].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5995].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5995].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5995].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5995].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5995].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5995].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5995].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5995].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5996].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5996].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5996].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5996].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5996].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5996].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5996].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5996].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5997].code.tag, "VRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5997].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5997].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5997].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5997].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5997].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5997].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_VISUAL_REFLECTOR_PRESENT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5997].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5998].code.tag, "VRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5998].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5998].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5998].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5998].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5998].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5998].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VISUAL_REFLECTOR_PRESENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5998].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[5999].code.tag, "VRF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5999].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5999].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5999].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5999].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5999].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5999].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VISUAL_REFLECTOR_PRESENT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[5999].entry.entry_list = temp_entries;

    temp_entries = NULL;

    return EDCS_SC_SUCCESS;
} /* end local_init_facc_attribute_enum_mapping_pt6 */

