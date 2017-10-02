/*
 * FILE: edcs_facc_enum_iso3.c
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
local_init_facc_attribute_enum_mapping_pt3( void )
{
    EDCS_Mapping_Entry * temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2000].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2000].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2000].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2000].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2000].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2000].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2000].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2000].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2001].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2001].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2001].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2001].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2001].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2001].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2001].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2001].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2002].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2002].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2002].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2002].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2002].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2002].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2002].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2002].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2003].code.tag, "HR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2003].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2003].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2003].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2003].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2003].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2003].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2003].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2004].code.tag, "HR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2004].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2004].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2004].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2004].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2004].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2004].entry.information = "<= 1,0 metre.";

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
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 1.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2004].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2005].code.tag, "HR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2005].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2005].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2005].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2005].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2005].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2005].entry.information = "> 1,0 metre and <= 5,0 metres.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2005].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2006].code.tag, "HR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2006].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2006].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2006].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2006].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2006].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2006].entry.information = "> 5,0 metres.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2006].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2007].code.tag, "HR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2007].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2007].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2007].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2007].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2007].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2007].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2007].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2008].code.tag, "HR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2008].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2008].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2008].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2008].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2008].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2008].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2008].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2009].code.tag, "HR2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2009].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2009].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2009].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2009].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2009].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2009].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2009].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2010].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2010].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2010].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2010].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2010].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2010].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2010].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2010].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2011].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2011].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2011].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2011].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2011].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2011].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2011].entry.information = "<= 0,2 metre.";

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
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2011].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2012].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2012].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2012].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2012].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2012].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2012].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2012].entry.information = "> 0,2 metre and <= 0,5 metre.";

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
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.2;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2012].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2013].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2013].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2013].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2013].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2013].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2013].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2013].entry.information = "> 0,5 metre and <= 1,0 metre.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2013].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2014].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2014].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2014].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2014].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2014].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2014].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2014].entry.information = "> 1,0 metre and <= 1,5 metres.";

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
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2014].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2015].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2015].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2015].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2015].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2015].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2015].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2015].entry.information = "> 1,5 metres and <= 2,0 metres.";

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
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2015].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2016].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2016].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2016].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2016].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2016].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2016].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2016].entry.information = "> 2,0 metres and <= 5,0 metres.";

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
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 2.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2016].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2017].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2017].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2017].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2017].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2017].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2017].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2017].entry.information = "> 5,0 metres.";

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
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2017].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2018].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2018].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2018].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2018].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2018].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2018].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2018].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2018].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2019].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2019].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2019].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2019].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2019].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2019].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2019].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2019].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2020].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2020].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2020].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2020].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2020].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2020].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2020].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2020].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2021].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2021].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2021].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2021].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2021].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2021].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2021].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2021].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2022].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2022].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2022].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2022].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2022].entry.ee_code = EEC_WTRCURAPMON_JANUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2022].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2022].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2022].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2023].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2023].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2023].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2023].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2023].entry.ee_code = EEC_WTRCURAPMON_FEBRUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2023].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2023].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2023].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2024].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2024].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2024].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2024].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2024].entry.ee_code = EEC_WTRCURAPMON_MARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2024].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2024].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2024].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2025].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2025].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2025].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2025].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2025].entry.ee_code = EEC_WTRCURAPMON_APRIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2025].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2025].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2025].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2026].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2026].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2026].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2026].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2026].entry.ee_code = EEC_WTRCURAPMON_MAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2026].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2026].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2026].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2027].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2027].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2027].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2027].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2027].entry.ee_code = EEC_WTRCURAPMON_JUNE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2027].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2027].entry.information = "Erroneously mapped to MAY in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2027].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2028].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2028].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2028].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2028].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2028].entry.ee_code = EEC_WTRCURAPMON_JULY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2028].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2028].entry.information = "Erroneously mapped to JUNE in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2028].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2029].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2029].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2029].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2029].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2029].entry.ee_code = EEC_WTRCURAPMON_AUGUST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2029].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2029].entry.information = "Erroneously mapped to JULY in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2029].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2030].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2030].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2030].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2030].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2030].entry.ee_code = EEC_WTRCURAPMON_SEPTEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2030].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2030].entry.information = "Erroneously mapped to AUGUST in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2030].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2031].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2031].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2031].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2031].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2031].entry.ee_code = EEC_WTRCURAPMON_OCTOBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2031].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2031].entry.information = "Erroneously mapped to SEPTEMBER in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2031].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2032].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2032].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2032].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2032].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2032].entry.ee_code = EEC_WTRCURAPMON_NOVEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2032].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2032].entry.information = "Erroneously mapped to OCTOBER in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2032].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2033].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2033].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2033].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2033].entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2033].entry.ee_code = EEC_WTRCURAPMON_DECEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2033].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2033].entry.information = "Erroneously mapped to NOVEMBER in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2033].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2034].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2034].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2034].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2034].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2034].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2034].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2034].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2034].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2035].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2035].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2035].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2035].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2035].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2035].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2035].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2035].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2036].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2036].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2036].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2036].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2036].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2036].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2036].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2036].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2037].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2037].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2037].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2037].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2037].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2037].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2037].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2037].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2038].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2038].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2038].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2038].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2038].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2038].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2038].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2038].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2039].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2039].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2039].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2039].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2039].entry.ee_code = EEC_WTRCURDISAPMON_JANUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2039].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2039].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2039].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2040].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2040].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2040].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2040].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2040].entry.ee_code = EEC_WTRCURDISAPMON_FEBRUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2040].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2040].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2040].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2041].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2041].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2041].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2041].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2041].entry.ee_code = EEC_WTRCURDISAPMON_MARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2041].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2041].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2041].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2042].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2042].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2042].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2042].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2042].entry.ee_code = EEC_WTRCURDISAPMON_APRIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2042].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2042].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2042].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2043].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2043].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2043].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2043].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2043].entry.ee_code = EEC_WTRCURDISAPMON_MAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2043].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2043].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2043].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2044].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2044].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2044].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2044].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2044].entry.ee_code = EEC_WTRCURDISAPMON_JUNE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2044].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2044].entry.information = "Erroneously mapped to MAY in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2044].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2045].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2045].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2045].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2045].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2045].entry.ee_code = EEC_WTRCURDISAPMON_JULY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2045].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2045].entry.information = "Erroneously mapped to JUNE in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2045].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2046].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2046].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2046].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2046].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2046].entry.ee_code = EEC_WTRCURDISAPMON_AUGUST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2046].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2046].entry.information = "Erroneously mapped to JULY in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2046].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2047].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2047].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2047].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2047].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2047].entry.ee_code = EEC_WTRCURDISAPMON_SEPTEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2047].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2047].entry.information = "Erroneously mapped to AUGUST in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2047].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2048].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2048].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2048].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2048].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2048].entry.ee_code = EEC_WTRCURDISAPMON_OCTOBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2048].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2048].entry.information = "Erroneously mapped to SEPTEMBER in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2048].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2049].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2049].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2049].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2049].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2049].entry.ee_code = EEC_WTRCURDISAPMON_NOVEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2049].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2049].entry.information = "Erroneously mapped to OCTOBER in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2049].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2050].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2050].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2050].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2050].entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2050].entry.ee_code = EEC_WTRCURDISAPMON_DECEMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2050].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2050].entry.information = "Erroneously mapped to NOVEMBER in Version 1 of the mapping.";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2050].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2051].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2051].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2051].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2051].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2051].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2051].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2051].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2051].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2052].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2052].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2052].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2052].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2052].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2052].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2052].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2052].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2053].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2053].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2053].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2053].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2053].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2053].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2053].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2053].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2054].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2054].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2054].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2054].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2054].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2054].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2054].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2054].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2055].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2055].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2055].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2055].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2055].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2055].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2055].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2055].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2056].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2056].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2056].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2056].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2056].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2056].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2056].entry.information = "<= 0,5 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_LE_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.le_semi_interval = 0.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2056].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2057].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2057].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2057].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2057].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2057].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2057].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2057].entry.information = "> 0,5 metre and <= 1,0 metre.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 0.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2057].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2058].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2058].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2058].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2058].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2058].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2058].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2058].entry.information = "> 1,0 metre and <= 1,5 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 1.5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2058].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2059].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2059].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2059].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2059].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2059].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2059].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2059].entry.information = "> 1,5 metres and <= 2,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 1.5;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 2.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2059].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2060].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2060].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2060].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2060].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2060].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2060].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2060].entry.information = "> 2,0 metres and <= 5,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 2.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 5.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2060].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2061].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2061].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2061].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2061].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2061].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2061].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2061].entry.information = "> 5,0 metres and <= 10,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 5.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 10.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2061].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2062].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2062].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2062].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2062].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2062].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2062].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2062].entry.information = "> 10,0 metres and <= 20,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 10.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 20.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2062].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2063].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2063].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2063].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2063].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2063].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2063].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2063].entry.information = "> 20,0 metres and <= 35,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_LE_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.lower_bound = 20.0;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_le_interval.upper_bound = 35.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2063].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2064].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2064].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2064].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2064].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2064].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2064].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2064].entry.information = "> 35,0 metres.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_REAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit = EUC_METRE;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.unit_scale = ESC_UNI;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.numeric_value_type = EDCS_NVT_GT_SEMI_INTERVAL;
    temp_entries[0].u.attr_value_entry.ea_value.value.real_value.value.gt_semi_interval = 35.0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2064].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2065].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2065].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2065].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2065].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2065].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2065].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2065].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2065].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2066].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2066].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2066].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2066].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2066].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2066].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2066].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2066].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2067].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2067].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2067].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2067].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2067].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2067].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2067].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2067].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2068].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2068].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2068].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2068].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2068].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2068].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2068].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2068].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2069].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2069].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2069].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2069].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2069].entry.ee_code = EEC_WORSHIPPLACETY_CATHEDRAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2069].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2069].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2069].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2070].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2070].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2070].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2070].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2070].entry.ee_code = EEC_WORSHIPPLACETY_CHAPEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2070].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2070].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2070].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2071].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2071].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2071].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2071].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2071].entry.ee_code = EEC_WORSHIPPLACETY_CHURCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2071].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2071].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2071].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2072].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2072].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2072].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2072].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2072].entry.ee_code = EEC_WORSHIPPLACETY_MARABOUT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2072].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2072].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2072].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2073].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2073].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2073].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2073].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2073].entry.ee_code = EEC_WORSHIPPLACETY_MINARET;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2073].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2073].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2073].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2074].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2074].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2074].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2074].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2074].entry.ee_code = EEC_WORSHIPPLACETY_RELIGIOUS_COMMUNITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2074].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2074].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2074].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2075].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2075].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2075].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2075].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2075].entry.ee_code = EEC_WORSHIPPLACETY_MOSQUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2075].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2075].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2075].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2076].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2076].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2076].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2076].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2076].entry.ee_code = EEC_WORSHIPPLACETY_PAGODA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2076].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2076].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2076].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2077].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2077].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2077].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2077].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2077].entry.ee_code = EEC_WORSHIPPLACETY_SHRINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2077].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2077].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2077].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2078].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2078].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2078].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2078].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2078].entry.ee_code = EEC_WORSHIPPLACETY_TABERNACLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2078].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2078].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2078].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2079].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2079].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2079].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2079].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2079].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2079].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2079].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2079].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2080].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2080].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2080].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2080].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2080].entry.ee_code = EEC_WORSHIPPLACETY_SYNAGOGUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2080].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2080].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2080].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2081].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2081].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2081].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2081].entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2081].entry.ee_code = EEC_WORSHIPPLACETY_STUPA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2081].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2081].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2081].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2082].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2082].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2082].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2082].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2082].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2082].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2082].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Not Applicable)\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2082].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2083].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2083].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2083].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2083].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2083].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2083].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2083].entry.information = "Was: \"Any\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2083].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2084].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2084].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2084].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2084].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2084].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2084].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2084].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2084].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2085].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2085].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2085].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2085].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2085].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2085].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2085].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2085].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2086].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2086].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2086].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2086].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2086].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2086].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2086].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2086].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2087].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2087].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2087].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2087].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2087].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2087].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2087].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2087].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2088].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2088].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2088].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2088].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2088].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2088].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2088].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2088].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2089].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2089].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2089].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2089].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2089].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2089].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2089].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2089].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2090].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2090].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2090].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2090].entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2090].entry.ee_code = EEC_HYDRLPERM_DRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2090].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2090].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2090].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2091].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2091].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2091].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2091].entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2091].entry.ee_code = EEC_HYDRLPERM_NON_PERENNIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2091].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2091].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2091].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2092].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2092].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2092].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2092].entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2092].entry.ee_code = EEC_HYDRLPERM_PERENNIAL_OR_PERMANENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2092].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2092].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2092].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2093].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2093].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2093].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2093].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2093].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2093].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2093].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2093].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2094].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2094].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2094].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2094].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2094].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2094].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2094].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2094].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2095].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2095].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2095].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2095].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2095].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2095].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2095].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2095].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2096].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2096].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2096].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2096].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2096].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2096].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2096].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2096].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2097].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2097].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2097].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2097].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2097].entry.ee_code = EEC_GDDTMID_ADINDAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2097].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2097].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2097].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2098].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2098].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2098].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2098].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2098].entry.ee_code = EEC_GDDTMID_ADINDAN_ETHIOPIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2098].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2098].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2098].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2099].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2099].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2099].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2099].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2099].entry.ee_code = EEC_GDDTMID_ADINDAN_SUDAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2099].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2099].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2099].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2100].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2100].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2100].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2100].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2100].entry.ee_code = EEC_GDDTMID_ADINDAN_MALI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2100].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2100].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2100].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2101].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2101].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2101].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2101].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2101].entry.ee_code = EEC_GDDTMID_ADINDAN_SENEGAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2101].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2101].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2101].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2102].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2102].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2102].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2102].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2102].entry.ee_code = EEC_GDDTMID_ADINDAN_BURKINA_FASO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2102].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2102].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2102].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2103].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2103].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2103].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2103].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2103].entry.ee_code = EEC_GDDTMID_ADINDAN_CAMEROON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2103].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2103].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2103].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2104].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2104].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2104].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2104].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2104].entry.ee_code = EEC_GDDTMID_ADINDAN_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2104].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2104].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2104].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2105].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2105].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2105].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2105].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2105].entry.ee_code = EEC_GDDTMID_AFGOOYE_SOMALIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2105].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2105].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2105].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2106].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2106].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2106].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2106].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2106].entry.ee_code = EEC_GDDTMID_ANTIGUA_ISLAND_ASTRO_1943;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2106].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2106].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2106].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2107].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2107].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2107].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2107].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2107].entry.ee_code = EEC_GDDTMID_AIN_EL_ABD_1970;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2107].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2107].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2107].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2108].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2108].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2108].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2108].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2108].entry.ee_code = EEC_GDDTMID_AIN_EL_ABD_1970_BAHRAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2108].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2108].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2108].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2109].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2109].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2109].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2109].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2109].entry.ee_code = EEC_GDDTMID_AIN_EL_ABD_1970_SAUDI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2109].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2109].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2109].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2110].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2110].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2110].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2110].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2110].entry.ee_code = EEC_GDDTMID_AMERICAN_SAMOA_1962;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2110].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2110].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2110].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2111].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2111].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2111].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2111].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2111].entry.ee_code = EEC_GDDTMID_AMERSFOORT_1885_1903;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2111].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2111].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2111].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2112].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2112].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2112].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2112].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2112].entry.ee_code = EEC_GDDTMID_ANNA_1_ASTRO_1965;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2112].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2112].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2112].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2113].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2113].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2113].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2113].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2113].entry.ee_code = EEC_GDDTMID_LUZON_APPROXIMATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2113].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2113].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2113].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2114].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2114].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2114].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2114].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2114].entry.ee_code = EEC_GDDTMID_ARC_1950;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2114].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2114].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2114].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2115].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2115].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2115].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2115].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2115].entry.ee_code = EEC_GDDTMID_ARC_1950_BOTSWANA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2115].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2115].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2115].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2116].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2116].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2116].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2116].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2116].entry.ee_code = EEC_GDDTMID_ARC_1950_LESOTHO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2116].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2116].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2116].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2117].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2117].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2117].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2117].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2117].entry.ee_code = EEC_GDDTMID_ARC_1950_MALAWI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2117].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2117].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2117].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2118].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2118].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2118].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2118].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2118].entry.ee_code = EEC_GDDTMID_ARC_1950_SWAZILAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2118].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2118].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2118].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2119].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2119].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2119].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2119].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2119].entry.ee_code = EEC_GDDTMID_ARC_1950_ZAIRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2119].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2119].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2119].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2120].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2120].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2120].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2120].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2120].entry.ee_code = EEC_GDDTMID_ARC_1950_ZAMBIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2120].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2120].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2120].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2121].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2121].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2121].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2121].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2121].entry.ee_code = EEC_GDDTMID_ARC_1950_ZIMBABWE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2121].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2121].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2121].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2122].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2122].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2122].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2122].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2122].entry.ee_code = EEC_GDDTMID_ARC_1950_BURUNDI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2122].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2122].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2122].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2123].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2123].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2123].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2123].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2123].entry.ee_code = EEC_GDDTMID_ARC_1950_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2123].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2123].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2123].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2124].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2124].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2124].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2124].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2124].entry.ee_code = EEC_GDDTMID_ARC_1960;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2124].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2124].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2124].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2125].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2125].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2125].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2125].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2125].entry.ee_code = EEC_GDDTMID_ARC_1960_KENYA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2125].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2125].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2125].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2126].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2126].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2126].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2126].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2126].entry.ee_code = EEC_GDDTMID_ARC_1960_TANZANIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2126].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2126].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2126].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2127].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2127].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2127].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2127].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2127].entry.ee_code = EEC_GDDTMID_ARC_1960_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2127].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2127].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2127].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2128].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2128].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2128].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2128].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2128].entry.ee_code = EEC_GDDTMID_ARC_1935_AFRICA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2128].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2128].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2128].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2129].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2129].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2129].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2129].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2129].entry.ee_code = EEC_GDDTMID_ASCENSION_ISLAND_1958;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2129].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2129].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2129].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2130].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2130].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2130].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2130].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2130].entry.ee_code = EEC_GDDTMID_MONTSERRAT_ASTRO_1958;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2130].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2130].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2130].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2131].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2131].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2131].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2131].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2131].entry.ee_code = EEC_GDDTMID_ASTRO_STATION_1952;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2131].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2131].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2131].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2132].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2132].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2132].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2132].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2132].entry.ee_code = EEC_GDDTMID_ASTRO_BEACON_E_1945;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2132].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2132].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2132].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2133].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2133].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2133].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2133].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2133].entry.ee_code = EEC_GDDTMID_AV_TERRESTRIAL_SYSTEM_1977;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2133].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2133].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2133].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2134].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2134].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2134].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2134].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2134].entry.ee_code = EEC_GDDTMID_AUSTRALIAN_GEOD_1966;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2134].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2134].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2134].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2135].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2135].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2135].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2135].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2135].entry.ee_code = EEC_GDDTMID_AUSTRALIAN_GEOD_1984;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2135].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2135].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2135].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2136].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2136].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2136].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2136].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2136].entry.ee_code = EEC_GDDTMID_DJAKARTA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2136].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2136].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2136].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2137].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2137].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2137].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2137].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2137].entry.ee_code = EEC_GDDTMID_DJAKARTA_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2137].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2137].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2137].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2138].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2138].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2138].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2138].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2138].entry.ee_code = EEC_GDDTMID_BEKAA_BASE_SOUTH_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2138].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2138].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2138].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2139].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2139].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2139].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2139].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2139].entry.ee_code = EEC_GDDTMID_BELGIUM_1950;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2139].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2139].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2139].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2140].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2140].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2140].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2140].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2140].entry.ee_code = EEC_GDDTMID_BERMUDA_1957;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2140].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2140].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2140].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2141].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2141].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2141].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2141].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2141].entry.ee_code = EEC_GDDTMID_BISSAU;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2141].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2141].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2141].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2142].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2142].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2142].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2142].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2142].entry.ee_code = EEC_GDDTMID_BJZ54_MODIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2142].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2142].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2142].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2143].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2143].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2143].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2143].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2143].entry.ee_code = EEC_GDDTMID_BJZ54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2143].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2143].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2143].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2144].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2144].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2144].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2144].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2144].entry.ee_code = EEC_GDDTMID_BOGOTA_OBS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2144].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2144].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2144].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2145].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2145].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2145].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2145].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2145].entry.ee_code = EEC_GDDTMID_BOGOTA_OBS_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2145].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2145].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2145].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2146].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2146].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2146].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2146].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2146].entry.ee_code = EEC_GDDTMID_BERN_1898;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2146].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2146].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2146].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2147].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2147].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2147].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2147].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2147].entry.ee_code = EEC_GDDTMID_BERN_1898_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2147].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2147].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2147].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2148].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2148].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2148].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2148].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2148].entry.ee_code = EEC_GDDTMID_BUKIT_RIMPAH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2148].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2148].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2148].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2149].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2149].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2149].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2149].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2149].entry.ee_code = EEC_GDDTMID_CAPE_CANAVERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2149].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2149].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2149].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2150].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2150].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2150].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2150].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2150].entry.ee_code = EEC_GDDTMID_CAMPO_INCHAUSPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2150].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2150].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2150].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2151].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2151].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2151].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2151].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2151].entry.ee_code = EEC_GDDTMID_CAMACUPA_BASE_SW_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2151].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2151].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2151].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2152].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2152].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2152].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2152].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2152].entry.ee_code = EEC_GDDTMID_CANTON_ASTRO_1966;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2152].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2152].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2152].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2153].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2153].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2153].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2153].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2153].entry.ee_code = EEC_GDDTMID_CAPE_SOUTH_AFRICA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2153].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2153].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2153].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2154].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2154].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2154].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2154].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2154].entry.ee_code = EEC_GDDTMID_CAMP_AREA_ASTRO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2154].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2154].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2154].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2155].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2155].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2155].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2155].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2155].entry.ee_code = EEC_GDDTMID_S_JTSK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2155].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2155].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2155].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2156].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2156].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2156].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2156].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2156].entry.ee_code = EEC_GDDTMID_CARTHAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2156].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2156].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2156].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2157].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2157].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2157].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2157].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2157].entry.ee_code = EEC_GDDTMID_COMP_GEOD_DU_QUEBEC_1977;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2157].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2157].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2157].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2158].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2158].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2158].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2158].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2158].entry.ee_code = EEC_GDDTMID_CHATHAM_ASTRO_1971;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2158].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2158].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2158].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2159].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2159].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2159].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2159].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2159].entry.ee_code = EEC_GDDTMID_CHUA_ASTRO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2159].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2159].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2159].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2160].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2160].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2160].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2160].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2160].entry.ee_code = EEC_GDDTMID_CORREGO_ALEGRE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2160].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2160].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2160].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2161].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2161].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2161].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2161].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2161].entry.ee_code = EEC_GDDTMID_CONAKRY_PYRAMID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2161].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2161].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2161].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2162].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2162].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2162].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2162].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2162].entry.ee_code = EEC_GDDTMID_CSG67_GUYANA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2162].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2162].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2162].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2163].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2163].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2163].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2163].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2163].entry.ee_code = EEC_GDDTMID_DABOLA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2163].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2163].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2163].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2164].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2164].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2164].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2164].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2164].entry.ee_code = EEC_GDDTMID_DCS3_LIGHTHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2164].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2164].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2164].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2165].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2165].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2165].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2165].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2165].entry.ee_code = EEC_GDDTMID_DECEPTION_ISLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2165].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2165].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2165].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2166].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2166].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2166].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2166].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2166].entry.ee_code = EEC_GDDTMID_GUX_1_ASTRO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2166].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2166].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2166].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2167].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2167].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2167].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2167].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2167].entry.ee_code = EEC_GDDTMID_DOMINICA_ASTRO_M12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2167].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2167].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2167].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2168].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2168].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2168].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2168].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2168].entry.ee_code = EEC_GDDTMID_EASTER_ISLAND_1967;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2168].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2168].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2168].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2169].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2169].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2169].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2169].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2169].entry.ee_code = EEC_GDDTMID_WAKE_ENIWETOK_1960;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2169].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2169].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2169].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2170].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2170].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2170].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2170].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2170].entry.ee_code = EEC_GDDTMID_EUR_1950;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2170].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2170].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2170].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2171].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2171].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2171].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2171].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2171].entry.ee_code = EEC_GDDTMID_EUR_1950_W_EUROPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2171].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2171].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2171].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2172].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2172].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2172].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2172].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2172].entry.ee_code = EEC_GDDTMID_EUR_1950_GREECE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2172].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2172].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2172].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2173].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2173].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2173].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2173].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2173].entry.ee_code = EEC_GDDTMID_EUR_1950_NORWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2173].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2173].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2173].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2174].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2174].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2174].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2174].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2174].entry.ee_code = EEC_GDDTMID_EUR_1950_PORTUGAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2174].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2174].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2174].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2175].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2175].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2175].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2175].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2175].entry.ee_code = EEC_GDDTMID_EUR_1950_CYPRUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2175].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2175].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2175].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2176].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2176].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2176].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2176].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2176].entry.ee_code = EEC_GDDTMID_EUR_1950_EGYPT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2176].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2176].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2176].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2177].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2177].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2177].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2177].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2177].entry.ee_code = EEC_GDDTMID_EUR_1950_SCOTLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2177].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2177].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2177].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2178].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2178].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2178].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2178].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2178].entry.ee_code = EEC_GDDTMID_EUR_1950_IRAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2178].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2178].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2178].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2179].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2179].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2179].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2179].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2179].entry.ee_code = EEC_GDDTMID_EUR_1950_SARDINIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2179].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2179].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2179].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2180].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2180].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2180].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2180].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2180].entry.ee_code = EEC_GDDTMID_EUR_1950_SICILY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2180].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2180].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2180].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2181].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2181].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2181].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2181].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2181].entry.ee_code = EEC_GDDTMID_EUR_1950_ENGLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2181].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2181].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2181].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2182].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2182].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2182].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2182].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2182].entry.ee_code = EEC_GDDTMID_EUR_1950_MALTA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2182].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2182].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2182].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2183].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2183].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2183].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2183].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2183].entry.ee_code = EEC_GDDTMID_EUR_1950_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2183].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2183].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2183].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2184].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2184].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2184].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2184].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2184].entry.ee_code = EEC_GDDTMID_EUR_1950_IRAQ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2184].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2184].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2184].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2185].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2185].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2185].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2185].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2185].entry.ee_code = EEC_GDDTMID_EUR_1950_TUNISIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2185].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2185].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2185].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2186].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2186].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2186].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2186].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2186].entry.ee_code = EEC_GDDTMID_EUR_1979;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2186].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2186].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2186].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2187].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2187].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2187].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2187].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2187].entry.ee_code = EEC_GDDTMID_ETRS_1989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2187].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2187].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2187].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2188].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2188].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2188].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2188].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2188].entry.ee_code = EEC_GDDTMID_FAHUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2188].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2188].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2188].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2189].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2189].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2189].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2189].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2189].entry.ee_code = EEC_GDDTMID_OBSERV_METEORO_1939;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2189].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2189].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2189].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2190].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2190].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2190].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2190].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2190].entry.ee_code = EEC_GDDTMID_FORT_THOMAS_1955;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2190].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2190].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2190].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2191].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2191].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2191].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2191].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2191].entry.ee_code = EEC_GDDTMID_GAN_1970;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2191].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2191].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2191].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2192].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2192].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2192].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2192].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2192].entry.ee_code = EEC_GDDTMID_GANDAJIKA_BASE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2192].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2192].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2192].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2193].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2193].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2193].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2193].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2193].entry.ee_code = EEC_GDDTMID_GEOCENTRIC_DATUM_AUSTRALIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2193].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2193].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2193].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2194].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2194].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2194].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2194].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2194].entry.ee_code = EEC_GDDTMID_GDZ80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2194].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2194].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2194].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2195].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2195].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2195].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2195].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2195].entry.ee_code = EEC_GDDTMID_GEODETIC_DATUM_1949;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2195].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2195].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2195].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2196].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2196].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2196].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2196].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2196].entry.ee_code = EEC_GDDTMID_DOS_1968;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2196].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2196].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2196].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2197].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2197].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2197].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2197].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2197].entry.ee_code = EEC_GDDTMID_GRACIOSA_BASE_SW_1948;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2197].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2197].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2197].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2198].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2198].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2198].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2198].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2198].entry.ee_code = EEC_GDDTMID_GREEK_DATUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2198].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2198].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2198].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2199].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2199].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2199].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2199].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2199].entry.ee_code = EEC_GDDTMID_GREEK_GRS_1987;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2199].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2199].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2199].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2200].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2200].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2200].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2200].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2200].entry.ee_code = EEC_GDDTMID_GUNONG_SEGARA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2200].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2200].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2200].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2201].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2201].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2201].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2201].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2201].entry.ee_code = EEC_GDDTMID_GUNONG_SERINDUNG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2201].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2201].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2201].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2202].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2202].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2202].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2202].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2202].entry.ee_code = EEC_GDDTMID_GUAM_1963;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2202].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2202].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2202].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2203].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2203].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2203].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2203].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2203].entry.ee_code = EEC_GDDTMID_HERAT_NORTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2203].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2203].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2203].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2204].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2204].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2204].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2204].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2204].entry.ee_code = EEC_GDDTMID_HERMANNSKOGEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2204].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2204].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2204].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2205].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2205].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2205].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2205].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2205].entry.ee_code = EEC_GDDTMID_PROV_S_CHILEAN_1963;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2205].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2205].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2205].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2206].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2206].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2206].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2206].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2206].entry.ee_code = EEC_GDDTMID_HJORSEY_1955;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2206].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2206].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2206].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2207].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2207].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2207].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2207].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2207].entry.ee_code = EEC_GDDTMID_HONG_KONG_1963;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2207].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2207].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2207].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2208].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2208].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2208].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2208].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2208].entry.ee_code = EEC_GDDTMID_HONG_KONG_1929;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2208].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2208].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2208].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2209].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2209].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2209].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2209].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2209].entry.ee_code = EEC_GDDTMID_HU_TZU_SHAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2209].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2209].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2209].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2210].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2210].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2210].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2210].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2210].entry.ee_code = EEC_GDDTMID_HUNGARIAN_1972;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2210].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2210].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2210].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2211].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2211].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2211].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2211].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2211].entry.ee_code = EEC_GDDTMID_BELLEVUE_IGN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2211].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2211].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2211].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2212].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2212].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2212].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2212].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2212].entry.ee_code = EEC_GDDTMID_INDONESIAN_1974;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2212].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2212].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2212].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2213].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2213].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2213].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2213].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2213].entry.ee_code = EEC_GDDTMID_INDIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2213].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2213].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2213].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2214].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2214].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2214].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2214].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2214].entry.ee_code = EEC_GDDTMID_INDIAN_THAILAND_VIETNAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2214].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2214].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2214].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2215].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2215].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2215].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2215].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2215].entry.ee_code = EEC_GDDTMID_INDIAN_BANGLADESH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2215].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2215].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2215].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2216].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2216].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2216].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2216].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2216].entry.ee_code = EEC_GDDTMID_INDIAN_NEPAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2216].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2216].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2216].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2217].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2217].enum_val = 121;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2217].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2217].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2217].entry.ee_code = EEC_GDDTMID_INDIAN_PAKISTAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2217].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2217].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2217].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2218].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2218].enum_val = 122;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2218].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2218].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2218].entry.ee_code = EEC_GDDTMID_INDIAN_1954;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2218].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2218].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2218].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2219].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2219].enum_val = 123;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2219].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2219].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2219].entry.ee_code = EEC_GDDTMID_INDIAN_1954_THAILAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2219].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2219].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2219].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2220].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2220].enum_val = 124;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2220].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2220].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2220].entry.ee_code = EEC_GDDTMID_INDIAN_1960;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2220].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2220].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2220].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2221].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2221].enum_val = 125;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2221].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2221].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2221].entry.ee_code = EEC_GDDTMID_INDIAN_1960_VIETNAM_16N;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2221].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2221].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2221].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2222].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2222].enum_val = 126;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2222].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2222].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2222].entry.ee_code = EEC_GDDTMID_INDIAN_1960_CON_SON_ISLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2222].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2222].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2222].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2223].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2223].enum_val = 127;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2223].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2223].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2223].entry.ee_code = EEC_GDDTMID_INDIAN_1975;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2223].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2223].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2223].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2224].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2224].enum_val = 128;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2224].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2224].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2224].entry.ee_code = EEC_GDDTMID_INDIAN_1975_THAILAND_1977;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2224].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2224].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2224].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2225].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2225].enum_val = 129;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2225].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2225].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2225].entry.ee_code = EEC_GDDTMID_IRELAND_1965;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2225].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2225].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2225].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2226].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2226].enum_val = 130;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2226].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2226].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2226].entry.ee_code = EEC_GDDTMID_ISTS_061_ASTRO_1968;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2226].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2226].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2226].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2227].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2227].enum_val = 131;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2227].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2227].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2227].entry.ee_code = EEC_GDDTMID_ISTS_073_ASTRO_1969;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2227].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2227].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2227].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2228].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2228].enum_val = 132;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2228].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2228].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2228].entry.ee_code = EEC_GDDTMID_JOHNSTON_ISLAND_1961;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2228].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2228].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2228].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2229].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2229].enum_val = 133;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2229].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2229].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2229].entry.ee_code = EEC_GDDTMID_KALIANPUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2229].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2229].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2229].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2230].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2230].enum_val = 134;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2230].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2230].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2230].entry.ee_code = EEC_GDDTMID_KANDAWALA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2230].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2230].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2230].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2231].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2231].enum_val = 135;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2231].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2231].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2231].entry.ee_code = EEC_GDDTMID_KERTAU_1948;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2231].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2231].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2231].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2232].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2232].enum_val = 136;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2232].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2232].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2232].entry.ee_code = EEC_GDDTMID_KCS_2_SIERRA_LEONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2232].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2232].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2232].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2233].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2233].enum_val = 137;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2233].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2233].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2233].entry.ee_code = EEC_GDDTMID_KERGUELEN_ISLAND_1949;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2233].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2233].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2233].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2234].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2234].enum_val = 138;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2234].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2234].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2234].entry.ee_code = EEC_GDDTMID_KOREAN_GEODETIC_1995;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2234].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2234].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2234].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2235].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2235].enum_val = 139;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2235].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2235].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2235].entry.ee_code = EEC_GDDTMID_KKJ_FINLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2235].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2235].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2235].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2236].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2236].enum_val = 140;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2236].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2236].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2236].entry.ee_code = EEC_GDDTMID_KUSAIE_ASTRO_1951;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2236].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2236].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2236].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2237].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2237].enum_val = 141;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2237].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2237].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2237].entry.ee_code = EEC_GDDTMID_KUWAIT_OIL_COMPANY_K28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2237].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2237].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2237].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2238].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2238].enum_val = 142;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2238].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2238].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2238].entry.ee_code = EEC_GDDTMID_LC5_ASTRO_1961;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2238].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2238].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2238].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2239].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2239].enum_val = 143;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2239].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2239].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2239].entry.ee_code = EEC_GDDTMID_LEIGON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2239].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2239].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2239].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2240].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2240].enum_val = 144;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2240].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2240].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2240].entry.ee_code = EEC_GDDTMID_LIBERIA_1964;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2240].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2240].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2240].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2241].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2241].enum_val = 145;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2241].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2241].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2241].entry.ee_code = EEC_GDDTMID_LISBON_D73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2241].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2241].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2241].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2242].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2242].enum_val = 146;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2242].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2242].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2242].entry.ee_code = EEC_GDDTMID_LOCAL_ASTRONOMICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2242].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2242].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2242].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2243].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2243].enum_val = 147;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2243].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2243].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2243].entry.ee_code = EEC_GDDTMID_LOMA_QUINTANA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2243].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2243].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2243].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2244].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2244].enum_val = 148;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2244].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2244].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2244].entry.ee_code = EEC_GDDTMID_LUZON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2244].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2244].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2244].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2245].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2245].enum_val = 149;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2245].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2245].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2245].entry.ee_code = EEC_GDDTMID_LUZON_PHILIPPINES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2245].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2245].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2245].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2246].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2246].enum_val = 150;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2246].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2246].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2246].entry.ee_code = EEC_GDDTMID_LUZON_MINDANAO_ISLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2246].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2246].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2246].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2247].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2247].enum_val = 151;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2247].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2247].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2247].entry.ee_code = EEC_GDDTMID_MARCO_ASTRO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2247].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2247].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2247].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2248].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2248].enum_val = 152;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2248].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2248].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2248].entry.ee_code = EEC_GDDTMID_MARTINIQUE_FORT_DESAIX;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2248].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2248].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2248].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2249].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2249].enum_val = 153;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2249].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2249].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2249].entry.ee_code = EEC_GDDTMID_MASSAWA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2249].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2249].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2249].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2250].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2250].enum_val = 154;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2250].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2250].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2250].entry.ee_code = EEC_GDDTMID_MANOKWARI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2250].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2250].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2250].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2251].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2251].enum_val = 155;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2251].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2251].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2251].entry.ee_code = EEC_GDDTMID_MAYOTTE_COMBANI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2251].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2251].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2251].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2252].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2252].enum_val = 156;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2252].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2252].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2252].entry.ee_code = EEC_GDDTMID_MOUNT_DILLON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2252].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2252].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2252].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2253].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2253].enum_val = 157;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2253].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2253].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2253].entry.ee_code = EEC_GDDTMID_MERCHICH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2253].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2253].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2253].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2254].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2254].enum_val = 158;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2254].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2254].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2254].entry.ee_code = EEC_GDDTMID_MIDWAY_ASTRO_1961;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2254].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2254].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2254].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2255].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2255].enum_val = 159;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2255].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2255].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2255].entry.ee_code = EEC_GDDTMID_MAHE_1971;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2255].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2255].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2255].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2256].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2256].enum_val = 160;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2256].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2256].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2256].entry.ee_code = EEC_GDDTMID_MINNA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2256].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2256].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2256].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2257].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2257].enum_val = 161;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2257].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2257].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2257].entry.ee_code = EEC_GDDTMID_MINNA_CAMEROON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2257].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2257].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2257].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2258].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2258].enum_val = 162;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2258].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2258].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2258].entry.ee_code = EEC_GDDTMID_MINNA_NIGERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2258].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2258].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2258].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2259].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2259].enum_val = 163;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2259].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2259].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2259].entry.ee_code = EEC_GDDTMID_ROME_1940;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2259].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2259].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2259].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2260].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2260].enum_val = 164;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2260].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2260].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2260].entry.ee_code = EEC_GDDTMID_ROME_1940_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2260].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2260].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2260].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2261].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2261].enum_val = 165;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2261].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2261].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2261].entry.ee_code = EEC_GDDTMID_MONTJONG_LOWE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2261].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2261].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2261].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2262].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2262].enum_val = 166;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2262].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2262].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2262].entry.ee_code = EEC_GDDTMID_M_PORALOKO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2262].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2262].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2262].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2263].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2263].enum_val = 167;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2263].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2263].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2263].entry.ee_code = EEC_GDDTMID_VITI_LEVU_1916;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2263].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2263].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2263].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2264].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2264].enum_val = 168;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2264].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2264].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2264].entry.ee_code = EEC_GDDTMID_NAHRWAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2264].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2264].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2264].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2265].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2265].enum_val = 169;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2265].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2265].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2265].entry.ee_code = EEC_GDDTMID_NAHRWAN_MASIRAH_OMAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2265].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2265].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2265].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2266].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2266].enum_val = 170;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2266].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2266].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2266].entry.ee_code = EEC_GDDTMID_NAHRWAN_UAE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2266].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2266].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2266].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2267].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2267].enum_val = 171;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2267].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2267].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2267].entry.ee_code = EEC_GDDTMID_NAHRWAN_SAUDI_ARABIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2267].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2267].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2267].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2268].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2268].enum_val = 172;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2268].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2268].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2268].entry.ee_code = EEC_GDDTMID_NAPARIMA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2268].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2268].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2268].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2269].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2269].enum_val = 173;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2269].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2269].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2269].entry.ee_code = EEC_GDDTMID_N_AM_1983;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2269].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2269].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2269].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2270].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2270].enum_val = 174;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2270].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2270].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2270].entry.ee_code = EEC_GDDTMID_N_AM_1983_ALASKA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2270].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2270].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2270].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2271].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2271].enum_val = 175;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2271].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2271].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2271].entry.ee_code = EEC_GDDTMID_N_AM_1983_CANADA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2271].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2271].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2271].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2272].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2272].enum_val = 176;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2272].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2272].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2272].entry.ee_code = EEC_GDDTMID_N_AM_1983_CONUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2272].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2272].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2272].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2273].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2273].enum_val = 177;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2273].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2273].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2273].entry.ee_code = EEC_GDDTMID_N_AM_1983_MEXICO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2273].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2273].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2273].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2274].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2274].enum_val = 178;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2274].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2274].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2274].entry.ee_code = EEC_GDDTMID_N_AM_1983_ALEUTIANS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2274].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2274].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2274].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2275].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2275].enum_val = 179;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2275].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2275].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2275].entry.ee_code = EEC_GDDTMID_N_AM_1983_HAWAII;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2275].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2275].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2275].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2276].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2276].enum_val = 180;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2276].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2276].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2276].entry.ee_code = EEC_GDDTMID_N_AM_1927;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2276].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2276].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2276].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2277].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2277].enum_val = 181;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2277].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2277].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2277].entry.ee_code = EEC_GDDTMID_N_AM_1927_EASTERN_US;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2277].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2277].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2277].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2278].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2278].enum_val = 182;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2278].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2278].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2278].entry.ee_code = EEC_GDDTMID_N_AM_1927_WESTERN_US;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2278].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2278].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2278].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2279].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2279].enum_val = 183;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2279].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2279].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2279].entry.ee_code = EEC_GDDTMID_N_AM_1927_CONUS_MEAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2279].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2279].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2279].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2280].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2280].enum_val = 184;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2280].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2280].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2280].entry.ee_code = EEC_GDDTMID_N_AM_1927_ALASKA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2280].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2280].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2280].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2281].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2281].enum_val = 185;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2281].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2281].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2281].entry.ee_code = EEC_GDDTMID_N_AM_1927_CANADA_MEAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2281].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2281].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2281].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2282].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2282].enum_val = 186;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2282].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2282].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2282].entry.ee_code = EEC_GDDTMID_N_AM_1927_ALBERTA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2282].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2282].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2282].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2283].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2283].enum_val = 187;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2283].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2283].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2283].entry.ee_code = EEC_GDDTMID_N_AM_1927_NEWFOUNDLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2283].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2283].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2283].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2284].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2284].enum_val = 188;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2284].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2284].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2284].entry.ee_code = EEC_GDDTMID_N_AM_1927_MANITOBA_ONTARIO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2284].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2284].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2284].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2285].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2285].enum_val = 189;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2285].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2285].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2285].entry.ee_code = EEC_GDDTMID_N_AM_1927_NORTHWEST_TERR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2285].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2285].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2285].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2286].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2286].enum_val = 190;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2286].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2286].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2286].entry.ee_code = EEC_GDDTMID_N_AM_1927_YUKON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2286].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2286].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2286].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2287].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2287].enum_val = 191;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2287].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2287].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2287].entry.ee_code = EEC_GDDTMID_N_AM_1927_MEXICO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2287].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2287].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2287].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2288].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2288].enum_val = 192;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2288].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2288].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2288].entry.ee_code = EEC_GDDTMID_N_AM_1927_CENTRAL_AMERICA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2288].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2288].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2288].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2289].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2289].enum_val = 193;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2289].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2289].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2289].entry.ee_code = EEC_GDDTMID_N_AM_1927_CANAL_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2289].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2289].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2289].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2290].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2290].enum_val = 194;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2290].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2290].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2290].entry.ee_code = EEC_GDDTMID_N_AM_1927_CARIBBEAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2290].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2290].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2290].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2291].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2291].enum_val = 195;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2291].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2291].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2291].entry.ee_code = EEC_GDDTMID_N_AM_1927_BAHAMAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2291].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2291].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2291].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2292].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2292].enum_val = 196;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2292].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2292].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2292].entry.ee_code = EEC_GDDTMID_N_AM_1927_SAN_SALVADOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2292].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2292].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2292].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2293].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2293].enum_val = 197;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2293].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2293].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2293].entry.ee_code = EEC_GDDTMID_N_AM_1927_CUBA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2293].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2293].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2293].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2294].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2294].enum_val = 198;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2294].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2294].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2294].entry.ee_code = EEC_GDDTMID_N_AM_1927_HAYES_GREENLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2294].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2294].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2294].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2295].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2295].enum_val = 199;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2295].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2295].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2295].entry.ee_code = EEC_GDDTMID_N_AM_1927_EAST_ALEUTIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2295].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2295].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2295].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2296].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2296].enum_val = 200;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2296].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2296].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2296].entry.ee_code = EEC_GDDTMID_N_AM_1927_WEST_ALEUTIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2296].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2296].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2296].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2297].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2297].enum_val = 201;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2297].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2297].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2297].entry.ee_code = EEC_GDDTMID_NAHRWAN_REVISED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2297].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2297].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2297].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2298].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2298].enum_val = 202;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2298].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2298].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2298].entry.ee_code = EEC_GDDTMID_NEW_FRENCH_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2298].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2298].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2298].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2299].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2299].enum_val = 203;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2299].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2299].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2299].entry.ee_code = EEC_GDDTMID_NEW_FRENCH_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2299].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2299].entry.information = "Was: \"Alt: FDA\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2299].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2300].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2300].enum_val = 204;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2300].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2300].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2300].entry.ee_code = EEC_GDDTMID_N_SAHARA_1959;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2300].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2300].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2300].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2301].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2301].enum_val = 205;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2301].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2301].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2301].entry.ee_code = EEC_GDDTMID_OCOTOPEQUE_GUATEMALA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2301].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2301].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2301].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2302].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2302].enum_val = 206;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2302].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2302].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2302].entry.ee_code = EEC_GDDTMID_BELGIUM_1972;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2302].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2302].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2302].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2303].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2303].enum_val = 207;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2303].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2303].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2303].entry.ee_code = EEC_GDDTMID_OLD_EGYPTIAN_1907;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2303].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2303].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2303].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2304].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2304].enum_val = 208;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2304].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2304].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2304].entry.ee_code = EEC_GDDTMID_OSGB_1936;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2304].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2304].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2304].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2305].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2305].enum_val = 209;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2305].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2305].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2305].entry.ee_code = EEC_GDDTMID_OSGB_1936_ENGLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2305].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2305].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2305].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2306].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2306].enum_val = 210;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2306].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2306].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2306].entry.ee_code = EEC_GDDTMID_OSGB_1936_ENG_ISLE_OF_MAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2306].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2306].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2306].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2307].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2307].enum_val = 211;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2307].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2307].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2307].entry.ee_code = EEC_GDDTMID_OSGB_1936_SCOTLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2307].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2307].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2307].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2308].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2308].enum_val = 212;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2308].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2308].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2308].entry.ee_code = EEC_GDDTMID_OSGB_1936_WALES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2308].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2308].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2308].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2309].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2309].enum_val = 213;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2309].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2309].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2309].entry.ee_code = EEC_GDDTMID_OSGB_1936_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2309].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2309].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2309].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2310].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2310].enum_val = 214;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2310].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2310].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2310].entry.ee_code = EEC_GDDTMID_OLD_HAWAIIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2310].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2310].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2310].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2311].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2311].enum_val = 215;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2311].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2311].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2311].entry.ee_code = EEC_GDDTMID_OLD_HAWAIIAN_HAWAII;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2311].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2311].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2311].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2312].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2312].enum_val = 216;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2312].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2312].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2312].entry.ee_code = EEC_GDDTMID_OLD_HAWAIIAN_KAUAI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2312].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2312].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2312].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2313].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2313].enum_val = 217;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2313].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2313].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2313].entry.ee_code = EEC_GDDTMID_OLD_HAWAIIAN_MAUI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2313].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2313].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2313].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2314].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2314].enum_val = 218;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2314].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2314].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2314].entry.ee_code = EEC_GDDTMID_OLD_HAWAIIAN_OAHU;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2314].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2314].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2314].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2315].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2315].enum_val = 219;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2315].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2315].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2315].entry.ee_code = EEC_GDDTMID_OLD_HAWAIIAN_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2315].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2315].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2315].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2316].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2316].enum_val = 220;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2316].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2316].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2316].entry.ee_code = EEC_GDDTMID_OSLO_OBS_OLD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2316].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2316].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2316].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2317].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2317].enum_val = 221;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2317].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2317].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2317].entry.ee_code = EEC_GDDTMID_PADANG_BASE_WEST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2317].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2317].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2317].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2318].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2318].enum_val = 222;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2318].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2318].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2318].entry.ee_code = EEC_GDDTMID_PADANG_BASE_WEST_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2318].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2318].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2318].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2319].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2319].enum_val = 223;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2319].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2319].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2319].entry.ee_code = EEC_GDDTMID_PALESTINE_1928;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2319].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2319].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2319].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2320].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2320].enum_val = 224;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2320].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2320].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2320].entry.ee_code = EEC_GDDTMID_POTSDAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2320].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2320].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2320].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2321].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2321].enum_val = 225;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2321].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2321].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2321].entry.ee_code = EEC_GDDTMID_AYABELLE_LIGHTHOUSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2321].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2321].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2321].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2322].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2322].enum_val = 226;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2322].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2322].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2322].entry.ee_code = EEC_GDDTMID_PITCAIRN_ASTRO_1967;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2322].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2322].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2322].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2323].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2323].enum_val = 227;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2323].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2323].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2323].entry.ee_code = EEC_GDDTMID_PICO_DE_LAS_NIEVES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2323].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2323].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2323].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2324].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2324].enum_val = 228;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2324].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2324].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2324].entry.ee_code = EEC_GDDTMID_PORTO_SANTO_1936;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2324].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2324].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2324].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2325].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2325].enum_val = 229;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2325].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2325].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2325].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2325].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2325].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2325].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2326].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2326].enum_val = 230;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2326].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2326].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2326].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_BOLIVIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2326].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2326].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2326].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2327].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2327].enum_val = 231;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2327].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2327].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2327].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_N_CHILE_19S;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2327].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2327].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2327].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2328].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2328].enum_val = 232;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2328].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2328].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2328].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_S_CHILE_43S;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2328].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2328].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2328].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2329].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2329].enum_val = 233;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2329].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2329].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2329].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_COLOMBIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2329].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2329].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2329].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2330].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2330].enum_val = 234;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2330].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2330].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2330].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_ECUADOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2330].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2330].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2330].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2331].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2331].enum_val = 235;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2331].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2331].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2331].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_GUYANA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2331].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2331].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2331].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2332].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2332].enum_val = 236;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2332].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2332].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2332].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_PERU;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2332].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2332].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2332].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2333].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2333].enum_val = 237;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2333].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2333].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2333].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_VENEZUELA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2333].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2333].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2333].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2334].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2334].enum_val = 238;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2334].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2334].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2334].entry.ee_code = EEC_GDDTMID_PROV_S_AM_1956_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2334].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2334].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2334].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2335].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2335].enum_val = 239;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2335].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2335].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2335].entry.ee_code = EEC_GDDTMID_POINT_58_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2335].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2335].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2335].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2336].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2336].enum_val = 240;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2336].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2336].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2336].entry.ee_code = EEC_GDDTMID_POINTE_NOIRE_1948;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2336].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2336].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2336].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2337].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2337].enum_val = 241;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2337].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2337].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2337].entry.ee_code = EEC_GDDTMID_PULKOVO_1942;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2337].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2337].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2337].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2338].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2338].enum_val = 242;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2338].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2338].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2338].entry.ee_code = EEC_GDDTMID_PUERTO_RICO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2338].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2338].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2338].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2339].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2339].enum_val = 243;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2339].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2339].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2339].entry.ee_code = EEC_GDDTMID_QATAR_NATIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2339].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2339].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2339].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2340].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2340].enum_val = 244;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2340].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2340].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2340].entry.ee_code = EEC_GDDTMID_QORNOQ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2340].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2340].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2340].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2341].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2341].enum_val = 245;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2341].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2341].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2341].entry.ee_code = EEC_GDDTMID_RAUENBERG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2341].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2341].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2341].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2342].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2342].enum_val = 246;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2342].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2342].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2342].entry.ee_code = EEC_GDDTMID_RECONN_TRIANG_MOROCCO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2342].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2342].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2342].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2343].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2343].enum_val = 247;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2343].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2343].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2343].entry.ee_code = EEC_GDDTMID_REUNION_1947;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2343].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2343].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2343].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2344].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2344].enum_val = 248;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2344].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2344].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2344].entry.ee_code = EEC_GDDTMID_RIKETS_1990_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2344].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2344].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2344].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2345].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2345].enum_val = 249;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2345].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2345].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2345].entry.ee_code = EEC_GDDTMID_SANTO_DOS_1965;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2345].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2345].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2345].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2346].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2346].enum_val = 250;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2346].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2346].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2346].entry.ee_code = EEC_GDDTMID_S_AFRICAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2346].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2346].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2346].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2347].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2347].enum_val = 251;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2347].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2347].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2347].entry.ee_code = EEC_GDDTMID_SAINTE_ANNE_I_1984;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2347].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2347].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2347].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2348].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2348].enum_val = 252;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2348].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2348].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2348].entry.ee_code = EEC_GDDTMID_S_AM_1969;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2348].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2348].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2348].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2349].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2349].enum_val = 253;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2349].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2349].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2349].entry.ee_code = EEC_GDDTMID_S_AM_1969_ARGENTINA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2349].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2349].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2349].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2350].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2350].enum_val = 254;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2350].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2350].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2350].entry.ee_code = EEC_GDDTMID_S_AM_1969_BOLIVIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2350].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2350].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2350].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2351].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2351].enum_val = 255;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2351].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2351].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2351].entry.ee_code = EEC_GDDTMID_S_AM_1969_BRAZIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2351].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2351].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2351].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2352].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2352].enum_val = 256;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2352].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2352].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2352].entry.ee_code = EEC_GDDTMID_S_AM_1969_CHILE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2352].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2352].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2352].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2353].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2353].enum_val = 257;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2353].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2353].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2353].entry.ee_code = EEC_GDDTMID_S_AM_1969_COLOMBIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2353].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2353].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2353].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2354].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2354].enum_val = 258;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2354].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2354].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2354].entry.ee_code = EEC_GDDTMID_S_AM_1969_ECUADOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2354].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2354].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2354].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2355].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2355].enum_val = 259;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2355].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2355].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2355].entry.ee_code = EEC_GDDTMID_S_AM_1969_GUYANA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2355].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2355].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2355].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2356].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2356].enum_val = 260;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2356].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2356].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2356].entry.ee_code = EEC_GDDTMID_S_AM_1969_PARAGUAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2356].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2356].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2356].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2357].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2357].enum_val = 261;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2357].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2357].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2357].entry.ee_code = EEC_GDDTMID_S_AM_1969_PERU;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2357].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2357].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2357].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2358].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2358].enum_val = 262;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2358].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2358].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2358].entry.ee_code = EEC_GDDTMID_S_AM_1969_BALTRA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2358].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2358].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2358].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2359].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2359].enum_val = 263;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2359].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2359].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2359].entry.ee_code = EEC_GDDTMID_S_AM_1969_TRINIDAD_TOBAGO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2359].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2359].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2359].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2360].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2360].enum_val = 264;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2360].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2360].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2360].entry.ee_code = EEC_GDDTMID_S_AM_1969_VENEZUELA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2360].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2360].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2360].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2361].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2361].enum_val = 265;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2361].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2361].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2361].entry.ee_code = EEC_GDDTMID_S_AM_1969_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2361].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2361].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2361].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2362].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2362].enum_val = 266;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2362].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2362].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2362].entry.ee_code = EEC_GDDTMID_SAO_BRAZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2362].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2362].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2362].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2363].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2363].enum_val = 267;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2363].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2363].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2363].entry.ee_code = EEC_GDDTMID_SAPPER_HILL_1943;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2363].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2363].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2363].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2364].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2364].enum_val = 268;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2364].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2364].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2364].entry.ee_code = EEC_GDDTMID_SCHWARZECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2364].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2364].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2364].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2365].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2365].enum_val = 269;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2365].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2365].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2365].entry.ee_code = EEC_GDDTMID_SOVIET_GEODETIC_1985;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2365].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2365].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2365].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2366].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2366].enum_val = 270;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2366].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2366].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2366].entry.ee_code = EEC_GDDTMID_SOVIET_GEODETIC_1990;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2366].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2366].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2366].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2367].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2367].enum_val = 271;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2367].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2367].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2367].entry.ee_code = EEC_GDDTMID_SELVAGEM_GRANDE_1938;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2367].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2367].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2367].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2368].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2368].enum_val = 272;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2368].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2368].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2368].entry.ee_code = EEC_GDDTMID_ASTRO_DOS_71_4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2368].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2368].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2368].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2369].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2369].enum_val = 273;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2369].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2369].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2369].entry.ee_code = EEC_GDDTMID_SIERRA_LEONE_1960;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2369].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2369].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2369].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2370].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2370].enum_val = 274;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2370].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2370].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2370].entry.ee_code = EEC_GDDTMID_S_ASIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2370].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2370].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2370].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2371].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2371].enum_val = 275;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2371].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2371].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2371].entry.ee_code = EEC_GDDTMID_S42_PULKOVO_1958;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2371].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2371].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2371].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2372].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2372].enum_val = 276;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2372].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2372].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2372].entry.ee_code = EEC_GDDTMID_ST_PIERRE_ET_MIQUELON_1950;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2372].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2372].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2372].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2373].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2373].enum_val = 277;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2373].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2373].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2373].entry.ee_code = EEC_GDDTMID_STOCKHOLM_1938;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2373].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2373].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2373].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2374].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2374].enum_val = 278;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2374].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2374].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2374].entry.ee_code = EEC_GDDTMID_SYDNEY_OBSERVATORY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2374].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2374].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2374].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2375].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2375].enum_val = 279;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2375].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2375].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2375].entry.ee_code = EEC_GDDTMID_TANANARIVE_OBS_1925;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2375].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2375].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2375].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2376].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2376].enum_val = 280;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2376].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2376].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2376].entry.ee_code = EEC_GDDTMID_TANANARIVE_OBS_ZERO_1925;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2376].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2376].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2376].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2377].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2377].enum_val = 281;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2377].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2377].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2377].entry.ee_code = EEC_GDDTMID_TRISTAN_ASTRO_1968;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2377].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2377].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2377].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2378].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2378].enum_val = 282;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2378].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2378].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2378].entry.ee_code = EEC_GDDTMID_TIMBALAI_1948;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2378].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2378].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2378].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2379].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2379].enum_val = 283;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2379].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2379].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2379].entry.ee_code = EEC_GDDTMID_TIMBALAI_1968;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2379].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2379].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2379].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2380].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2380].enum_val = 284;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2380].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2380].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2380].entry.ee_code = EEC_GDDTMID_TOKYO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2380].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2380].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2380].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2381].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2381].enum_val = 285;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2381].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2381].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2381].entry.ee_code = EEC_GDDTMID_TOKYO_JAPAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2381].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2381].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2381].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2382].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2382].enum_val = 286;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2382].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2382].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2382].entry.ee_code = EEC_GDDTMID_TOKYO_KOREA_1997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2382].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2382].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2382].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2383].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2383].enum_val = 287;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2383].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2383].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2383].entry.ee_code = EEC_GDDTMID_TOKYO_OKINAWA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2383].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2383].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2383].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2384].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2384].enum_val = 288;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2384].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2384].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2384].entry.ee_code = EEC_GDDTMID_TOKYO_MEAN_SOLUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2384].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2384].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2384].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2385].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2385].enum_val = 289;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2385].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2385].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2385].entry.ee_code = EEC_GDDTMID_TRINIDAD_1903;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2385].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2385].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2385].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2386].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2386].enum_val = 290;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2386].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2386].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2386].entry.ee_code = EEC_GDDTMID_ASTRO_TERN_IS_1961;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2386].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2386].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2386].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2387].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2387].enum_val = 291;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2387].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2387].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2387].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2387].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2387].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2387].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2388].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2388].enum_val = 292;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2388].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2388].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2388].entry.ee_code = EEC_GDDTMID_VOIROL_1874;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2388].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2388].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2388].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2389].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2389].enum_val = 293;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2389].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2389].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2389].entry.ee_code = EEC_GDDTMID_VOIROL_1874_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2389].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2389].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2389].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2390].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2390].enum_val = 294;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2390].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2390].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2390].entry.ee_code = EEC_GDDTMID_VOIROL_1960_ALGERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2390].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2390].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2390].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2391].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2391].enum_val = 295;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2391].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2391].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2391].entry.ee_code = EEC_GDDTMID_VOIROL_1960_ZERO_ALGERIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2391].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2391].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2391].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2392].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2392].enum_val = 296;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2392].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2392].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2392].entry.ee_code = EEC_GDDTMID_WAKE_ISLAND_ASTRO_1952;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2392].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2392].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2392].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2393].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2393].enum_val = 297;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2393].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2393].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2393].entry.ee_code = EEC_GDDTMID_WGS_1960;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2393].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2393].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2393].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2394].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2394].enum_val = 298;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2394].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2394].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2394].entry.ee_code = EEC_GDDTMID_WGS_1966;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2394].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2394].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2394].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2395].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2395].enum_val = 299;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2395].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2395].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2395].entry.ee_code = EEC_GDDTMID_WGS_1972;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2395].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2395].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2395].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2396].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2396].enum_val = 300;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2396].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2396].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2396].entry.ee_code = EEC_GDDTMID_WGS_1984;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2396].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2396].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2396].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2397].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2397].enum_val = 301;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2397].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2397].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2397].entry.ee_code = EEC_GDDTMID_YACARE_URUGUAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2397].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2397].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2397].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2398].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2398].enum_val = 302;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2398].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2398].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2398].entry.ee_code = EEC_GDDTMID_ZANDERIJ_SURINAME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2398].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2398].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2398].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2399].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2399].enum_val = 303;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2399].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2399].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2399].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2399].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2399].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2399].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2400].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2400].enum_val = 304;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2400].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2400].entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2400].entry.ee_code = EEC_GDDTMID_KKJ_FINLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2400].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2400].entry.information = "Was: \"Finnish-KKJ\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2400].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2401].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2401].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2401].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2401].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2401].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2401].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2401].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2401].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2402].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2402].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2402].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2402].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2402].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2402].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2402].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2402].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2403].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2403].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2403].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2403].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2403].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2403].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2403].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2403].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2404].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2404].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2404].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2404].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2404].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2404].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2404].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2404].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2405].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2405].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2405].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2405].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2405].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2405].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2405].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2405].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2406].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2406].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2406].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2406].entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2406].entry.ee_code = EEC_AIDNAVSYSTY_NON_IALA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2406].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2406].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2406].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2407].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2407].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2407].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2407].entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2407].entry.ee_code = EEC_AIDNAVSYSTY_IALA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2407].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2407].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2407].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2408].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2408].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2408].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2408].entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2408].entry.ee_code = EEC_AIDNAVSYSTY_IALA_REGION_A;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2408].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2408].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2408].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2409].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2409].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2409].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2409].entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2409].entry.ee_code = EEC_AIDNAVSYSTY_IALA_REGION_B;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2409].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2409].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2409].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2410].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2410].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2410].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2410].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2410].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2410].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2410].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2410].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2411].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2411].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2411].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2411].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2411].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2411].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2411].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2411].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2412].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2412].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2412].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2412].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2412].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2412].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2412].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2412].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2413].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2413].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2413].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2413].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2413].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2413].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2413].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2413].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2414].code.tag, "IAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2414].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2414].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2414].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2414].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2414].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2414].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2414].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2415].code.tag, "IAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2415].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2415].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2415].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2415].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2415].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2415].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_IMO_ADOPTED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2415].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2416].code.tag, "IAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2416].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2416].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2416].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2416].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2416].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2416].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_IMO_ADOPTED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2416].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2417].code.tag, "IAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2417].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2417].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2417].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2417].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2417].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2417].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2417].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2418].code.tag, "IAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2418].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2418].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2418].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2418].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2418].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2418].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2418].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2419].code.tag, "IAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2419].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2419].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2419].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2419].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2419].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2419].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2419].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2420].code.tag, "IAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2420].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2420].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2420].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2420].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2420].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2420].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_IMO_ADOPTED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2420].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2421].code.tag, "IBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2421].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2421].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2421].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2421].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2421].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2421].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INSTALLATION_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2421].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2422].code.tag, "IBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2422].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2422].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2422].entry.ea_code = EAC_INSTALLATION_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2422].entry.ee_code = EEC_INSTBUOYTY_CATENARY_ANCHOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2422].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2422].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2422].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2423].code.tag, "IBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2423].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2423].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2423].entry.ea_code = EAC_INSTALLATION_BUOY_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2423].entry.ee_code = EEC_INSTBUOYTY_SINGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2423].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2423].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2423].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2424].code.tag, "IBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2424].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2424].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2424].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2424].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2424].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2424].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INSTALLATION_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2424].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2425].code.tag, "IBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2425].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2425].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2425].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2425].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2425].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2425].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INSTALLATION_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2425].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2426].code.tag, "IBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2426].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2426].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2426].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2426].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2426].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2426].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INSTALLATION_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2426].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2427].code.tag, "IBC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2427].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2427].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2427].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2427].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2427].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2427].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INSTALLATION_BUOY_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2427].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2428].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2428].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2428].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2428].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2428].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2428].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2428].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEA_ICE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2428].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2429].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2429].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2429].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2429].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2429].entry.ee_code = EEC_SEAICETY_FAST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2429].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2429].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2429].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2430].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2430].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2430].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2430].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2430].entry.ee_code = EEC_SEAICETY_SEA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2430].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2430].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2430].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2431].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2431].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2431].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2431].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2431].entry.ee_code = EEC_SEAICETY_GROWLER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2431].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2431].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2431].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2432].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2432].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2432].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2432].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2432].entry.ee_code = EEC_SEAICETY_PANCAKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2432].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2432].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2432].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2433].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2433].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2433].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2433].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2433].entry.ee_code = EEC_SEAICETY_GLACIER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2433].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2433].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2433].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2434].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2434].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2434].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2434].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2434].entry.ee_code = EEC_SEAICETY_PEAK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2434].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2434].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2434].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2435].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2435].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2435].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2435].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2435].entry.ee_code = EEC_SEAICETY_PACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2435].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2435].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2435].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2436].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2436].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2436].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2436].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2436].entry.ee_code = EEC_SEAICETY_POLAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2436].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2436].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2436].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2437].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2437].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2437].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2437].entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2437].entry.ee_code = EEC_SEAICETY_DEBRIS_COVERED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2437].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2437].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2437].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2438].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2438].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2438].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2438].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2438].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2438].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2438].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEA_ICE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2438].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2439].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2439].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2439].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2439].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2439].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2439].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2439].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEA_ICE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2439].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2440].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2440].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2440].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2440].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2440].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2440].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2440].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEA_ICE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2440].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2441].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2441].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2441].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2441].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2441].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2441].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2441].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SEA_ICE_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2441].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2442].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2442].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2442].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2442].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2442].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2442].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2442].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2442].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2443].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2443].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2443].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2443].entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2443].entry.ee_code = EEC_ICAOARSPCCLS_A;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2443].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2443].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2443].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2444].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2444].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2444].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2444].entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2444].entry.ee_code = EEC_ICAOARSPCCLS_B;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2444].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2444].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2444].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2445].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2445].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2445].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2445].entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2445].entry.ee_code = EEC_ICAOARSPCCLS_C;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2445].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2445].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2445].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2446].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2446].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2446].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2446].entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2446].entry.ee_code = EEC_ICAOARSPCCLS_D;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2446].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2446].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2446].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2447].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2447].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2447].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2447].entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2447].entry.ee_code = EEC_ICAOARSPCCLS_E;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2447].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2447].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2447].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2448].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2448].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2448].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2448].entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2448].entry.ee_code = EEC_ICAOARSPCCLS_F;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2448].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2448].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2448].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2449].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2449].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2449].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2449].entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2449].entry.ee_code = EEC_ICAOARSPCCLS_G;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2449].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2449].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2449].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2450].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2450].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2450].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2450].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2450].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2450].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2450].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2450].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2451].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2451].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2451].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2451].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2451].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2451].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2451].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2451].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2452].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2452].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2452].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2452].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2452].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2452].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2452].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2452].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2453].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2453].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2453].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2453].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2453].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2453].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2453].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2453].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2454].code.tag, "IWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2454].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2454].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2454].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2454].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2454].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2454].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_WATER_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2454].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2455].code.tag, "IWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2455].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2455].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2455].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2455].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2455].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2455].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_INLAND_WATER_OBSTRUCTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2455].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2456].code.tag, "IWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2456].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2456].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2456].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2456].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2456].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2456].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_INLAND_WATER_OBSTRUCTION;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2456].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2457].code.tag, "IWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2457].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2457].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2457].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2457].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2457].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2457].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_WATER_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2457].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2458].code.tag, "IWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2458].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2458].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2458].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2458].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2458].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2458].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_WATER_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2458].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2459].code.tag, "IWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2459].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2459].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2459].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2459].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2459].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2459].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_WATER_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2459].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2460].code.tag, "IWO", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2460].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2460].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2460].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2460].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2460].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2460].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_INLAND_WATER_OBSTRUCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2460].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2461].code.tag, "JCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2461].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2461].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2461].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2461].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2461].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2461].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_JUNCTION_CONNECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2461].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2462].code.tag, "JCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2462].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2462].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2462].entry.ea_code = EAC_ROAD_JUNCTION_CONNECTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2462].entry.ee_code = EEC_RDJUNCCONNY_FULL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2462].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2462].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2462].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2463].code.tag, "JCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2463].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2463].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2463].entry.ea_code = EAC_ROAD_JUNCTION_CONNECTIVITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2463].entry.ee_code = EEC_RDJUNCCONNY_RESTRICTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2463].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2463].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2463].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2464].code.tag, "JCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2464].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2464].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2464].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2464].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2464].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2464].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_JUNCTION_CONNECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2464].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2465].code.tag, "JCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2465].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2465].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2465].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2465].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2465].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2465].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_JUNCTION_CONNECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2465].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2466].code.tag, "JCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2466].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2466].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2466].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2466].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2466].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2466].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_JUNCTION_CONNECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2466].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2467].code.tag, "JCR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2467].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2467].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2467].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2467].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2467].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2467].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_ROAD_JUNCTION_CONNECTIVITY;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2467].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2468].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2468].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2468].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2468].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2468].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2468].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2468].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2468].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2469].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2469].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2469].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2469].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2469].entry.ee_code = EEC_MARLNASSATNAV_SINGLE_OBJECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2469].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2469].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2469].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2470].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2470].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2470].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2470].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2470].entry.ee_code = EEC_MARLNASSATNAV_DIRECTIONAL_LIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2470].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2470].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2470].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2471].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2471].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2471].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2471].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2471].entry.ee_code = EEC_MARLNASSATNAV_MULTIPLE_LIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2471].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2471].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2471].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2472].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2472].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2472].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2472].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2472].entry.ee_code = EEC_MARLNASSATNAV_MULTIPLE_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2472].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2472].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2472].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2473].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2473].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2473].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2473].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2473].entry.ee_code = EEC_MARLNASSATNAV_MULTIPLE_OBJECT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2473].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2473].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2473].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2474].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2474].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2474].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2474].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2474].entry.ee_code = EEC_MARLNASSATNAV_MEASURED_DISTANCE_MARKERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2474].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2474].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2474].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2475].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2475].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2475].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2475].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2475].entry.ee_code = EEC_MARLNASSATNAV_DIRECTIONAL_RADIO_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2475].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2475].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2475].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2476].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2476].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2476].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2476].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2476].entry.ee_code = EEC_MARLNASSATNAV_MOIRE_EFFECT_LIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2476].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2476].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2476].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2477].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2477].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2477].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2477].entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2477].entry.ee_code = EEC_MARLNASSATNAV_LEADING_RADIO_TRANSPONDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2477].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2477].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2477].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2478].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2478].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2478].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2478].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2478].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2478].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2478].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2478].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2479].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2479].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2479].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2479].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2479].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2479].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2479].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2479].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2480].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2480].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2480].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2480].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2480].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2480].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2480].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2480].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2481].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2481].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2481].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2481].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2481].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2481].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2481].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2481].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2482].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2482].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2482].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2482].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2482].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2482].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2482].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2482].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2483].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2483].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2483].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2483].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2483].entry.ee_code = EEC_AEROLGTTY_AERODROME_TERMINAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2483].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2483].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2483].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2484].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2484].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2484].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2484].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2484].entry.ee_code = EEC_AEROLGTTY_CENTRE_LINE_AND_BAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2484].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2484].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2484].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2485].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2485].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2485].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2485].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2485].entry.ee_code = EEC_AEROLGTTY_BOUNDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2485].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2485].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2485].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2486].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2486].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2486].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2486].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2486].entry.ee_code = EEC_AEROLGTTY_RUNWAY_CENTRE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2486].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2486].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2486].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2487].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2487].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2487].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2487].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2487].entry.ee_code = EEC_AEROLGTTY_RUNWAY_END;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2487].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2487].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2487].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2488].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2488].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2488].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2488].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2488].entry.ee_code = EEC_AEROLGTTY_RUNWAY_REGION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2488].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2488].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2488].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2489].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2489].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2489].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2489].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2489].entry.ee_code = EEC_AEROLGTTY_SEQUENCED_STROBE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2489].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2489].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2489].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2490].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2490].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2490].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2490].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2490].entry.ee_code = EEC_AEROLGTTY_TAXIWAY_LIGHTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2490].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2490].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2490].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2491].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2491].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2491].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2491].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2491].entry.ee_code = EEC_AEROLGTTY_VASI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2491].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2491].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2491].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2492].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2492].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2492].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2492].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2492].entry.ee_code = EEC_AEROLGTTY_ROTATING_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2492].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2492].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2492].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2493].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2493].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2493].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2493].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2493].entry.ee_code = EEC_AEROLGTTY_OBSTRUCTION_LIGHTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2493].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2493].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2493].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2494].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2494].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2494].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2494].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2494].entry.ee_code = EEC_AEROLGTTY_THRESHOLD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2494].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2494].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2494].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2495].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2495].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2495].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2495].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2495].entry.ee_code = EEC_AEROLGTTY_TOUCHDOWN_ZONE_LIGHTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2495].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2495].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2495].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2496].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2496].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2496].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2496].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2496].entry.ee_code = EEC_AEROLGTTY_OTHER_AERODROME_LIGHTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2496].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2496].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2496].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2497].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2497].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2497].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2497].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2497].entry.ee_code = EEC_AEROLGTTY_ALSF_I;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2497].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2497].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2497].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2498].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2498].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2498].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2498].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2498].entry.ee_code = EEC_AEROLGTTY_ALSF_II;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2498].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2498].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2498].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2499].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2499].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2499].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2499].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2499].entry.ee_code = EEC_AEROLGTTY_SSALF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2499].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2499].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2499].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2500].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2500].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2500].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2500].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2500].entry.ee_code = EEC_AEROLGTTY_SSALR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2500].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2500].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2500].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2501].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2501].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2501].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2501].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2501].entry.ee_code = EEC_AEROLGTTY_MALSF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2501].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2501].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2501].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2502].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2502].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2502].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2502].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2502].entry.ee_code = EEC_AEROLGTTY_MALSR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2502].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2502].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2502].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2503].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2503].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2503].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2503].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2503].entry.ee_code = EEC_AEROLGTTY_LANDING_DIRECTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2503].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2503].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2503].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2504].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2504].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2504].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2504].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2504].entry.ee_code = EEC_AEROLGTTY_RAIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2504].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2504].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2504].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2505].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2505].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2505].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2505].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2505].entry.ee_code = EEC_AEROLGTTY_ODALS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2505].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2505].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2505].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2506].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2506].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2506].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2506].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2506].entry.ee_code = EEC_AEROLGTTY_OTHER_APPROACH_LIGHTING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2506].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2506].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2506].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2507].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2507].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2507].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2507].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2507].entry.ee_code = EEC_AEROLGTTY_PRECISION_APPROACH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2507].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2507].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2507].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2508].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2508].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2508].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2508].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2508].entry.ee_code = EEC_AEROLGTTY_STROBE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2508].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2508].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2508].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2509].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2509].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2509].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2509].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2509].entry.ee_code = EEC_AEROLGTTY_RUNWAY_FLOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2509].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2509].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2509].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2510].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2510].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2510].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2510].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2510].entry.ee_code = EEC_AEROLGTTY_VARIABLE_INTENSITY_RUNWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2510].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2510].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2510].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2511].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2511].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2511].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2511].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2511].entry.ee_code = EEC_AEROLGTTY_PORTABLE_RUNWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2511].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2511].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2511].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2512].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2512].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2512].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2512].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2512].entry.ee_code = EEC_AEROLGTTY_FLARES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2512].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2512].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2512].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2513].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2513].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2513].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2513].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2513].entry.ee_code = EEC_AEROLGTTY_WIND_INDICATOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2513].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2513].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2513].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2514].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2514].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2514].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2514].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2514].entry.ee_code = EEC_AEROLGTTY_VASI_3_BAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2514].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2514].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2514].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2515].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2515].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2515].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2515].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2515].entry.ee_code = EEC_AEROLGTTY_OPTICAL_LANDING_SYSTEM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2515].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2515].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2515].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2516].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2516].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2516].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2516].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2516].entry.ee_code = EEC_AEROLGTTY_AEROMARINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2516].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2516].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2516].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2517].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2517].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2517].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2517].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2517].entry.ee_code = EEC_AEROLGTTY_AUXILIARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2517].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2517].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2517].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2518].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2518].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2518].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2518].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2518].entry.ee_code = EEC_AEROLGTTY_BEACON_UNSPECIFIED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2518].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2518].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2518].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2519].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2519].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2519].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2519].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2519].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2519].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2519].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2519].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2520].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2520].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2520].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2520].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2520].entry.ee_code = EEC_AEROLGTTY_FISHING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2520].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2520].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2520].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2521].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2521].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2521].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2521].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2521].entry.ee_code = EEC_AEROLGTTY_FOG_DETECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2521].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2521].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2521].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2522].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2522].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2522].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2522].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2522].entry.ee_code = EEC_AEROLGTTY_HARBOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2522].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2522].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2522].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2523].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2523].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2523].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2523].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2523].entry.ee_code = EEC_AEROLGTTY_HORIZONTAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2523].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2523].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2523].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2524].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2524].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2524].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2524].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2524].entry.ee_code = EEC_AEROLGTTY_OBSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2524].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2524].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2524].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2525].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2525].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2525].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2525].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2525].entry.ee_code = EEC_AEROLGTTY_OCCASIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2525].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2525].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2525].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2526].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2526].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2526].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2526].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2526].entry.ee_code = EEC_AEROLGTTY_PRIVATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2526].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2526].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2526].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2527].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2527].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2527].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2527].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2527].entry.ee_code = EEC_AEROLGTTY_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2527].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2527].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2527].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2528].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2528].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2528].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2528].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2528].entry.ee_code = EEC_AEROLGTTY_SEASONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2528].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2528].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2528].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2529].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2529].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2529].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2529].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2529].entry.ee_code = EEC_AEROLGTTY_TIDAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2529].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2529].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2529].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2530].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2530].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2530].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2530].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2530].entry.ee_code = EEC_AEROLGTTY_VERTICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2530].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2530].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2530].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2531].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2531].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2531].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2531].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2531].entry.ee_code = EEC_AEROLGTTY_CENTRE_LINE_HIGH_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2531].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2531].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2531].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2532].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2532].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2532].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2532].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2532].entry.ee_code = EEC_AEROLGTTY_PRIMARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2532].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2532].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2532].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2533].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2533].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2533].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2533].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2533].entry.ee_code = EEC_AEROLGTTY_SECONDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2533].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2533].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2533].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2534].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2534].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2534].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2534].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2534].entry.ee_code = EEC_AEROLGTTY_MAJOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2534].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2534].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2534].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2535].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2535].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2535].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2535].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2535].entry.ee_code = EEC_AEROLGTTY_MINOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2535].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2535].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2535].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2536].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2536].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2536].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2536].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2536].entry.ee_code = EEC_AEROLGTTY_VASI_2_BAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2536].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2536].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2536].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2537].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2537].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2537].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2537].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2537].entry.ee_code = EEC_AEROLGTTY_IDENTIFICATION_BEACON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2537].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2537].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2537].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2538].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2538].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2538].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2538].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2538].entry.ee_code = EEC_AEROLGTTY_NONE_AVAILABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2538].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2538].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2538].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2539].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2539].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2539].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2539].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2539].entry.ee_code = EEC_AEROLGTTY_OVERRUN_CENTRE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2539].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2539].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2539].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2540].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2540].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2540].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2540].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2540].entry.ee_code = EEC_AEROLGTTY_CENTRE_LINE_AND_BAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2540].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2540].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2540].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2541].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2541].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2541].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2541].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2541].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2541].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2541].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2541].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2542].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2542].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2542].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2542].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2542].entry.ee_code = EEC_AEROLGTTY_HONG_KONG_CURVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2542].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2542].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2542].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2543].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2543].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2543].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2543].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2543].entry.ee_code = EEC_AEROLGTTY_LEFT_SINGLE_ROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2543].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2543].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2543].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2544].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2544].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2544].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2544].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2544].entry.ee_code = EEC_AEROLGTTY_CENTRE_ROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2544].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2544].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2544].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2545].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2545].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2545].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2545].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2545].entry.ee_code = EEC_AEROLGTTY_FORMER_NATO_STANDARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2545].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2545].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2545].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2546].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2546].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2546].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2546].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2546].entry.ee_code = EEC_AEROLGTTY_NATO_STANDARD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2546].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2546].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2546].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2547].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2547].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2547].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2547].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2547].entry.ee_code = EEC_AEROLGTTY_CENTRE_AND_DOUBLE_ROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2547].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2547].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2547].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2548].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2548].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2548].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2548].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2548].entry.ee_code = EEC_AEROLGTTY_PORTABLE_APPROACH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2548].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2548].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2548].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2549].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2549].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2549].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2549].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2549].entry.ee_code = EEC_AEROLGTTY_CENTRE_ROW_2_HI_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2549].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2549].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2549].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2550].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2550].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2550].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2550].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2550].entry.ee_code = EEC_AEROLGTTY_CENTRE_ROW_1_HI_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2550].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2550].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2550].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2551].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2551].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2551].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2551].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2551].entry.ee_code = EEC_AEROLGTTY_US_NAVY_PARALLEL_ROW_AND_X;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2551].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2551].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2551].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2552].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2552].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2552].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2552].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2552].entry.ee_code = EEC_AEROLGTTY_TWO_PARALLEL_ROW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2552].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2552].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2552].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2553].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2553].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2553].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2553].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2553].entry.ee_code = EEC_AEROLGTTY_LEFT_ROW_HIGH_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2553].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2553].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2553].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2554].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2554].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2554].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2554].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2554].entry.ee_code = EEC_AEROLGTTY_US_AIR_FORCE_OVERRUN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2554].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2554].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2554].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2555].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2555].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2555].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2555].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2555].entry.ee_code = EEC_AEROLGTTY_CALVERT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2555].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2555].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2555].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2556].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2556].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2556].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2556].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2556].entry.ee_code = EEC_AEROLGTTY_SINGLE_ROW_CENTRE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2556].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2556].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2556].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2557].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2557].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2557].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2557].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2557].entry.ee_code = EEC_AEROLGTTY_NARROW_MULTI_CROSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2557].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2557].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2557].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2558].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2558].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2558].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2558].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2558].entry.ee_code = EEC_AEROLGTTY_CENTRE_LINE_HIGH_INTENSITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2558].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2558].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2558].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2559].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2559].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2559].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2559].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2559].entry.ee_code = EEC_AEROLGTTY_ALTERNATE_CENTRE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2559].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2559].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2559].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2560].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2560].enum_val = 121;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2560].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2560].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2560].entry.ee_code = EEC_AEROLGTTY_CROSS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2560].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2560].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2560].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2561].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2561].enum_val = 122;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2561].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2561].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2561].entry.ee_code = EEC_AEROLGTTY_NEON_LADDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2561].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2561].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2561].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2562].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2562].enum_val = 123;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2562].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2562].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2562].entry.ee_code = EEC_AEROLGTTY_SINGAPORE_CENTRE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2562].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2562].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2562].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2563].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2563].enum_val = 124;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2563].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2563].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2563].entry.ee_code = EEC_AEROLGTTY_CENTRE_LINE_2_CROSSBAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2563].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2563].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2563].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2564].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2564].enum_val = 125;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2564].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2564].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2564].entry.ee_code = EEC_AEROLGTTY_TVASI_T_BAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2564].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2564].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2564].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2565].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2565].enum_val = 126;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2565].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2565].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2565].entry.ee_code = EEC_AEROLGTTY_VASI_PULSATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2565].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2565].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2565].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2566].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2566].enum_val = 127;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2566].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2566].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2566].entry.ee_code = EEC_AEROLGTTY_CENTRE_LINE_2_CROSSBAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2566].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2566].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2566].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2567].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2567].enum_val = 128;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2567].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2567].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2567].entry.ee_code = EEC_AEROLGTTY_VASI_WITH_INDICATOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2567].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2567].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2567].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2568].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2568].enum_val = 129;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2568].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2568].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2568].entry.ee_code = EEC_AEROLGTTY_LOW_COST_VASI;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2568].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2568].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2568].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2569].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2569].enum_val = 130;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2569].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2569].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2569].entry.ee_code = EEC_AEROLGTTY_HIGH_INTENSITY_RUNWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2569].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2569].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2569].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2570].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2570].enum_val = 131;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2570].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2570].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2570].entry.ee_code = EEC_AEROLGTTY_MEDIUM_INTENSITY_RUNWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2570].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2570].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2570].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2571].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2571].enum_val = 132;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2571].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2571].entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2571].entry.ee_code = EEC_AEROLGTTY_LOW_INTENSITY_RUNWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2571].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2571].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2571].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2572].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2572].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2572].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2572].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2572].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2572].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2572].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2572].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2573].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2573].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2573].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2573].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2573].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2573].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2573].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2573].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2574].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2574].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2574].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2574].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2574].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2574].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2574].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2574].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2575].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2575].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2575].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2575].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2575].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2575].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2575].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2575].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2576].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2576].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2576].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2576].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2576].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2576].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2576].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2576].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2577].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2577].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2577].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2577].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2577].entry.ee_code = EEC_LGTFN_DIRECTIONAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2577].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2577].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2577].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2578].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2578].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2578].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2578].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2578].entry.ee_code = EEC_LGTFN_REAR_OR_UPPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2578].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2578].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2578].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2579].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2579].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2579].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2579].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2579].entry.ee_code = EEC_LGTFN_FRONT_OR_LOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2579].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2579].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2579].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2580].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2580].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2580].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2580].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2580].entry.ee_code = EEC_LGTFN_LEADING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2580].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2580].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2580].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2581].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2581].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2581].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2581].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2581].entry.ee_code = EEC_LGTFN_AEROLIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2581].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2581].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2581].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2582].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2582].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2582].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2582].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2582].entry.ee_code = EEC_LGTFN_AIR_OBSTRUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2582].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2582].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2582].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2583].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2583].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2583].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2583].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2583].entry.ee_code = EEC_LGTFN_FOG_DETECTOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2583].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2583].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2583].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2584].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2584].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2584].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2584].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2584].entry.ee_code = EEC_LGTFN_FLOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2584].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2584].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2584].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2585].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2585].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2585].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2585].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2585].entry.ee_code = EEC_LGTFN_STRIP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2585].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2585].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2585].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2586].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2586].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2586].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2586].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2586].entry.ee_code = EEC_LGTFN_SUBSIDIARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2586].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2586].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2586].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2587].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2587].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2587].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2587].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2587].entry.ee_code = EEC_LGTFN_SPOTLIGHT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2587].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2587].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2587].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2588].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2588].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2588].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2588].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2588].entry.ee_code = EEC_LGTFN_EMERGENCY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2588].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2588].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2588].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2589].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2589].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2589].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2589].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2589].entry.ee_code = EEC_LGTFN_BEARING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2589].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2589].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2589].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2590].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2590].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2590].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2590].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2590].entry.ee_code = EEC_LGTFN_UPPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2590].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2590].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2590].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2591].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2591].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2591].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2591].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2591].entry.ee_code = EEC_LGTFN_MIDDLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2591].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2591].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2591].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2592].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2592].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2592].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2592].entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2592].entry.ee_code = EEC_LGTFN_LOWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2592].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2592].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2592].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2593].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2593].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2593].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2593].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2593].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2593].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2593].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2593].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2594].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2594].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2594].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2594].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2594].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2594].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2594].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2594].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2595].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2595].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2595].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2595].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2595].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2595].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2595].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2595].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2596].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2596].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2596].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2596].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2596].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2596].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2596].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_LIGHT_FUNCTION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2596].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2597].code.tag, "LNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2597].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2597].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2597].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2597].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2597].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2597].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_PATH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2597].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2598].code.tag, "LNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2598].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2598].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2598].entry.ea_code = EAC_NAVIGATION_PATH_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2598].entry.ee_code = EEC_NAVPATHTY_LOXODROME;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2598].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2598].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2598].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2599].code.tag, "LNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2599].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2599].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2599].entry.ea_code = EAC_NAVIGATION_PATH_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2599].entry.ee_code = EEC_NAVPATHTY_GEODESIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2599].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2599].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2599].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2600].code.tag, "LNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2600].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2600].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2600].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2600].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2600].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2600].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_PATH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2600].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2601].code.tag, "LNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2601].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2601].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2601].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2601].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2601].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2601].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_PATH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2601].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2602].code.tag, "LNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2602].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2602].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2602].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2602].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2602].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2602].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_PATH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2602].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2603].code.tag, "LNC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2603].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2603].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2603].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2603].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2603].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2603].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_NAVIGATION_PATH_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2603].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2604].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2604].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2604].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2604].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2604].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2604].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2604].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2604].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2605].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2605].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2605].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2605].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2605].entry.ee_code = EEC_RELLOC_ABOVE_SRF_HGT_KNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2605].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2605].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2605].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2606].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2606].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2606].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2606].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2606].entry.ee_code = EEC_RELLOC_AWASH_AT_CHART_DATUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2606].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2606].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2606].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2607].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2607].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2607].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2607].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2607].entry.ee_code = EEC_RELLOC_COVERED_INTERMITTENTLY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2607].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2607].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2607].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2608].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2608].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2608].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2608].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2608].entry.ee_code = EEC_RELLOC_BELOW_WTR_BODY_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2608].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2608].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2608].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2609].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2609].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2609].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2609].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2609].entry.ee_code = EEC_RELLOC_COVERED_lt_20_M;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2609].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2609].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2609].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2610].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2610].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2610].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2610].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2610].entry.ee_code = EEC_RELLOC_COVERED_ge_20_M_AND_lt_30_M;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2610].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2610].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2610].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2611].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2611].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2611].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2611].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2611].entry.ee_code = EEC_RELLOC_COVERED_ge_30_M;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2611].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2611].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2611].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2612].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2612].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2612].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2612].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2612].entry.ee_code = EEC_RELLOC_ON_TERRAIN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2612].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2612].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2612].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2613].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2613].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2613].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2613].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2613].entry.ee_code = EEC_RELLOC_DEPTH_KNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2613].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2613].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2613].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2614].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2614].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2614].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2614].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2614].entry.ee_code = EEC_RELLOC_DEPTH_KNOWN_CLEARED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2614].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2614].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2614].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2615].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2615].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2615].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2615].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2615].entry.ee_code = EEC_RELLOC_DEPTH_UNKNOWN_BUT_SAFE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2615].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2615].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2615].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2616].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2616].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2616].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2616].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2616].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2616].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2616].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2616].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2617].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2617].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2617].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2617].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2617].entry.ee_code = EEC_RELLOC_HULL_SHOWING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2617].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2617].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2617].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2618].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2618].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2618].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2618].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2618].entry.ee_code = EEC_RELLOC_MASTS_SHOWING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2618].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2618].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2618].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2619].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2619].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2619].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2619].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2619].entry.ee_code = EEC_RELLOC_ON_WTR_BODY_SURFACE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2619].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2619].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2619].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2620].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2620].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2620].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2620].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2620].entry.ee_code = EEC_RELLOC_PARTIALLY_SUBMERGED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2620].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2620].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2620].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2621].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2621].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2621].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2621].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2621].entry.ee_code = EEC_RELLOC_ON_WTR_BODY_FLOOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2621].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2621].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2621].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2622].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2622].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2622].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2622].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2622].entry.ee_code = EEC_RELLOC_ABOVE_SRF_HGT_UNKNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2622].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2622].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2622].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2623].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2623].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2623].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2623].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2623].entry.ee_code = EEC_RELLOC_FUNNEL_SHOWING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2623].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2623].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2623].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2624].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2624].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2624].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2624].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2624].entry.ee_code = EEC_RELLOC_SUPERSTRUCTURE_SHOWING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2624].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2624].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2624].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2625].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2625].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2625].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2625].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2625].entry.ee_code = EEC_RELLOC_OFFSHORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2625].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2625].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2625].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2626].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2626].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2626].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2626].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2626].entry.ee_code = EEC_RELLOC_BELOW_WTR_BODY_FLOOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2626].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2626].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2626].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2627].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2627].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2627].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2627].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2627].entry.ee_code = EEC_RELLOC_ABOVE_WTR_BODY_FLOOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2627].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2627].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2627].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2628].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2628].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2628].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2628].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2628].entry.ee_code = EEC_RELLOC_ABOVE_SRF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2628].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2628].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2628].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2629].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2629].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2629].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2629].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2629].entry.ee_code = EEC_RELLOC_MASTS_AND_FUNNEL_SHOWING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2629].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2629].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2629].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2630].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2630].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2630].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2630].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2630].entry.ee_code = EEC_RELLOC_NON_FLOATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2630].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2630].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2630].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2631].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2631].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2631].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2631].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2631].entry.ee_code = EEC_RELLOC_ELEVATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2631].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2631].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2631].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2632].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2632].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2632].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2632].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2632].entry.ee_code = EEC_RELLOC_DEPRESSED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2632].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2632].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2632].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2633].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2633].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2633].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2633].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2633].entry.ee_code = EEC_RELLOC_NOT_SUBMERGED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2633].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2633].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2633].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2634].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2634].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2634].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2634].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2634].entry.ee_code = EEC_RELLOC_INLAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2634].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2634].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2634].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2635].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2635].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2635].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2635].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2635].entry.ee_code = EEC_RELLOC_OVERHEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2635].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2635].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2635].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2636].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2636].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2636].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2636].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2636].entry.ee_code = EEC_RELLOC_HEIGHT_ABOVE_BOTTOM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2636].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2636].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2636].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2637].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2637].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2637].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2637].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2637].entry.ee_code = EEC_RELLOC_EXACT_POSITION_KNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2637].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2637].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2637].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2638].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2638].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2638].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2638].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2638].entry.ee_code = EEC_RELLOC_EXACT_POSITION_UNKNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2638].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2638].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2638].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2639].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2639].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2639].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2639].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2639].entry.ee_code = EEC_RELLOC_DEPTH_UNKNOWN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2639].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2639].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2639].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2640].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2640].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2640].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2640].entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2640].entry.ee_code = EEC_RELLOC_UNDERGROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2640].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2640].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2640].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2641].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2641].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2641].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2641].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2641].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2641].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2641].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2641].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2642].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2642].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2642].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2642].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2642].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2642].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2642].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2642].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2643].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2643].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2643].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2643].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2643].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2643].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2643].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2643].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2644].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2644].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2644].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2644].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2644].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2644].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2644].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_RELATIVE_LOCATION;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2644].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2645].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2645].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2645].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2645].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2645].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2645].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2645].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2645].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2646].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2646].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2646].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2646].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2646].entry.ee_code = EEC_MARREGNTY_CUSTOMS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2646].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2646].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2646].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2647].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2647].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2647].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2647].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2647].entry.ee_code = EEC_MARREGNTY_DREDGED_CHANNEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2647].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2647].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2647].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2648].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2648].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2648].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2648].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2648].entry.ee_code = EEC_MARREGNTY_HARBOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2648].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2648].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2648].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2649].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2649].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2649].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2649].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2649].entry.ee_code = EEC_MARREGNTY_MINE_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2649].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2649].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2649].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2650].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2650].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2650].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2650].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2650].entry.ee_code = EEC_MARREGNTY_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2650].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2650].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2650].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2651].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2651].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2651].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2651].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2651].entry.ee_code = EEC_MARREGNTY_RECLAMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2651].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2651].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2651].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2652].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2652].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2652].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2652].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2652].entry.ee_code = EEC_MARREGNTY_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2652].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2652].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2652].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2653].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2653].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2653].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2653].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2653].entry.ee_code = EEC_MARREGNTY_WORKS_IN_PROGRESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2653].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2653].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2653].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2654].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2654].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2654].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2654].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2654].entry.ee_code = EEC_MARREGNTY_SWEPT_BY_WIRE_DRAG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2654].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2654].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2654].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2655].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2655].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2655].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2655].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2655].entry.ee_code = EEC_MARREGNTY_ANCHORAGE_GENERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2655].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2655].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2655].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2656].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2656].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2656].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2656].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2656].entry.ee_code = EEC_MARREGNTY_ANCHORING_BERTHS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2656].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2656].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2656].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2657].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2657].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2657].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2657].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2657].entry.ee_code = EEC_MARREGNTY_EXPLOSIVE_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2657].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2657].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2657].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2658].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2658].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2658].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2658].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2658].entry.ee_code = EEC_MARREGNTY_DEEP_DRAFT_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2658].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2658].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2658].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2659].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2659].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2659].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2659].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2659].entry.ee_code = EEC_MARREGNTY_ANCHORING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2659].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2659].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2659].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2660].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2660].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2660].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2660].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2660].entry.ee_code = EEC_MARREGNTY_QUARANTINE_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2660].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2660].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2660].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2661].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2661].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2661].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2661].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2661].entry.ee_code = EEC_MARREGNTY_RESERVED_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2661].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2661].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2661].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2662].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2662].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2662].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2662].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2662].entry.ee_code = EEC_MARREGNTY_SMALL_CRAFT_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2662].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2662].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2662].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2663].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2663].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2663].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2663].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2663].entry.ee_code = EEC_MARREGNTY_TANKER_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2663].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2663].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2663].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2664].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2664].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2664].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2664].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2664].entry.ee_code = EEC_MARREGNTY_SUB_CABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2664].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2664].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2664].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2665].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2665].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2665].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2665].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2665].entry.ee_code = EEC_MARREGNTY_PIPELINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2665].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2665].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2665].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2666].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2666].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2666].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2666].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2666].entry.ee_code = EEC_MARREGNTY_FISHING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2666].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2666].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2666].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2667].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2667].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2667].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2667].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2667].entry.ee_code = EEC_MARREGNTY_CABLE_AND_PIPELINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2667].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2667].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2667].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2668].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2668].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2668].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2668].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2668].entry.ee_code = EEC_MARREGNTY_SWINGING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2668].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2668].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2668].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2669].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2669].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2669].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2669].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2669].entry.ee_code = EEC_MARREGNTY_SPOIL_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2669].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2669].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2669].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2670].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2670].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2670].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2670].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2670].entry.ee_code = EEC_MARREGNTY_UNSURVEYED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2670].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2670].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2670].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2671].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2671].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2671].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2671].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2671].entry.ee_code = EEC_MARREGNTY_SUB_EXERCISE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2671].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2671].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2671].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2672].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2672].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2672].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2672].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2672].entry.ee_code = EEC_MARREGNTY_MINE_LAYING_PRACTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2672].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2672].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2672].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2673].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2673].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2673].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2673].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2673].entry.ee_code = EEC_MARREGNTY_FIRING_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2673].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2673].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2673].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2674].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2674].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2674].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2674].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2674].entry.ee_code = EEC_MARREGNTY_HAZMAT_DUMPING_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2674].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2674].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2674].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2675].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2675].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2675].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2675].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2675].entry.ee_code = EEC_MARREGNTY_INCINERATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2675].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2675].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2675].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2676].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2676].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2676].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2676].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2676].entry.ee_code = EEC_MARREGNTY_PETROLEUM_FIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2676].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2676].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2676].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2677].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2677].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2677].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2677].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2677].entry.ee_code = EEC_MARREGNTY_GAS_FIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2677].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2677].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2677].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2678].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2678].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2678].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2678].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2678].entry.ee_code = EEC_MARREGNTY_HISTORIC_WRECK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2678].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2678].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2678].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2679].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2679].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2679].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2679].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2679].entry.ee_code = EEC_MARREGNTY_EXPLOSIVE_DUMPING_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2679].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2679].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2679].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2680].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2680].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2680].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2680].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2680].entry.ee_code = EEC_MARREGNTY_FORMER_MINE_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2680].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2680].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2680].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2681].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2681].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2681].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2681].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2681].entry.ee_code = EEC_MARREGNTY_SAFETY_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2681].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2681].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2681].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2682].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2682].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2682].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2682].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2682].entry.ee_code = EEC_MARREGNTY_CHEMICAL_DUMPING_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2682].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2682].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2682].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2683].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2683].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2683].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2683].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2683].entry.ee_code = EEC_MARREGNTY_SEPARATION_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2683].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2683].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2683].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2684].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2684].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2684].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2684].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2684].entry.ee_code = EEC_MARREGNTY_ROUNDABOUT_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2684].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2684].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2684].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2685].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2685].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2685].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2685].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2685].entry.ee_code = EEC_MARREGNTY_INSHORE_TRAFFIC_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2685].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2685].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2685].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2686].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2686].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2686].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2686].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2686].entry.ee_code = EEC_MARREGNTY_PRECAUTIONARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2686].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2686].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2686].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2687].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2687].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2687].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2687].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2687].entry.ee_code = EEC_MARREGNTY_TO_BE_AVOIDED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2687].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2687].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2687].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2688].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2688].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2688].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2688].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2688].entry.ee_code = EEC_MARREGNTY_DEGAUSSING_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2688].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2688].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2688].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2689].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2689].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2689].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2689].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2689].entry.ee_code = EEC_MARREGNTY_OUTFALL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2689].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2689].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2689].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2690].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2690].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2690].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2690].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2690].entry.ee_code = EEC_MARREGNTY_INTAKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2690].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2690].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2690].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2691].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2691].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2691].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2691].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2691].entry.ee_code = EEC_MARREGNTY_PROTECTED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2691].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2691].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2691].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2692].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2692].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2692].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2692].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2692].entry.ee_code = EEC_MARREGNTY_PILOT_BOARDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2692].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2692].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2692].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2693].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2693].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2693].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2693].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2693].entry.ee_code = EEC_MARREGNTY_CARGO_TRNSHP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2693].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2693].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2693].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2694].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2694].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2694].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2694].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2694].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2694].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2694].entry.information = "NIMA does not define FACC Attribute code value \"Red rocks\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2694].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2695].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2695].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2695].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2695].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2695].entry.ee_code = EEC_MARREGNTY_LATERITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2695].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2695].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2695].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2696].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2696].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2696].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2696].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2696].entry.ee_code = EEC_MARREGNTY_EVAPORITES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2696].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2696].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2696].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2697].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2697].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2697].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2697].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2697].entry.ee_code = EEC_MARREGNTY_SEAPLANE_RUN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2697].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2697].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2697].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2698].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2698].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2698].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2698].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2698].entry.ee_code = EEC_MARREGNTY_TIME_LIMITED_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2698].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2698].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2698].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2699].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2699].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2699].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2699].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2699].entry.ee_code = EEC_MARREGNTY_FAIRWAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2699].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2699].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2699].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2700].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2700].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2700].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2700].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2700].entry.ee_code = EEC_MARREGNTY_FISH_TRAP;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2700].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2700].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2700].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2701].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2701].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2701].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2701].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2701].entry.ee_code = EEC_MARREGNTY_MARINE_FARM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2701].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2701].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2701].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2702].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2702].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2702].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2702].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2702].entry.ee_code = EEC_MARREGNTY_DREDGING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2702].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2702].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2702].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2703].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2703].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2703].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2703].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2703].entry.ee_code = EEC_MARREGNTY_SEWER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2703].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2703].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2703].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2704].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2704].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2704].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2704].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2704].entry.ee_code = EEC_MARREGNTY_FREE_PORT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2704].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2704].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2704].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2705].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2705].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2705].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2705].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2705].entry.ee_code = EEC_MARREGNTY_FISH_SANCTUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2705].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2705].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2705].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2706].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2706].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2706].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2706].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2706].entry.ee_code = EEC_MARREGNTY_DEGAUSSING_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2706].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2706].entry.information = "Was: \"Degaussing Range (Do not use this value, use MAC 44)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2706].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2707].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2707].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2707].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2707].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2707].entry.ee_code = EEC_MARREGNTY_DEVELOPMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2707].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2707].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2707].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2708].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2708].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2708].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2708].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2708].entry.ee_code = EEC_MARREGNTY_DIVING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2708].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2708].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2708].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2709].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2709].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2709].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2709].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2709].entry.ee_code = EEC_MARREGNTY_DANGER_OF_STRANDING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2709].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2709].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2709].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2710].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2710].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2710].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2710].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2710].entry.ee_code = EEC_MARREGNTY_NAVIGATIONAL_AID;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2710].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2710].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2710].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2711].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2711].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2711].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2711].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2711].entry.ee_code = EEC_MARREGNTY_HISTORIC_WRECK_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2711].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2711].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2711].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2712].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2712].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2712].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2712].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2712].entry.ee_code = EEC_MARREGNTY_SEAL_SANCTUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2712].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2712].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2712].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2713].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2713].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2713].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2713].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2713].entry.ee_code = EEC_MARREGNTY_GAME_PRESERVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2713].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2713].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2713].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2714].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2714].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2714].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2714].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2714].entry.ee_code = EEC_MARREGNTY_BIRD_SANCTUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2714].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2714].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2714].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2715].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2715].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2715].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2715].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2715].entry.ee_code = EEC_MARREGNTY_NATURE_RESERVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2715].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2715].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2715].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2716].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2716].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2716].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2716].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2716].entry.ee_code = EEC_MARREGNTY_PRACTICE_IN_GENERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2716].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2716].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2716].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2717].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2717].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2717].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2717].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2717].entry.ee_code = EEC_MARREGNTY_TORPEDO_PRACTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2717].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2717].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2717].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2718].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2718].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2718].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2718].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2718].entry.ee_code = EEC_MARREGNTY_ANCHORAGE_FOR_24_HOURS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2718].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2718].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2718].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2719].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2719].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2719].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2719].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2719].entry.ee_code = EEC_MARREGNTY_SMALL_CRAFT_MOORING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2719].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2719].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2719].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2720].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2720].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2720].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2720].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2720].entry.ee_code = EEC_MARREGNTY_SEAPLANE_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2720].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2720].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2720].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2721].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2721].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2721].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2721].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2721].entry.ee_code = EEC_MARREGNTY_UNRESTRICTED_ANCHORAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2721].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2721].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2721].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2722].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2722].enum_val = 97;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2722].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2722].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2722].entry.ee_code = EEC_MARREGNTY_TSS_CROSSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2722].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2722].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2722].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2723].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2723].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2723].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2723].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2723].entry.ee_code = EEC_MARREGNTY_OFFSHORE_PRODUCTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2723].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2723].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2723].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2724].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2724].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2724].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2724].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2724].entry.ee_code = EEC_MARREGNTY_DOCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2724].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2724].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2724].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2725].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2725].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2725].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2725].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2725].entry.ee_code = EEC_MARREGNTY_CAUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2725].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2725].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Caution Area)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2725].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2726].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2726].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2726].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2726].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2726].entry.ee_code = EEC_MARREGNTY_MARINE_SANCTUARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2726].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2726].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2726].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2727].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2727].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2727].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2727].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2727].entry.ee_code = EEC_MARREGNTY_WAITING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2727].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2727].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2727].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2728].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2728].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2728].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2728].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2728].entry.ee_code = EEC_MARREGNTY_MINESWEPT_CHANNEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2728].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2728].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2728].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2729].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2729].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2729].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2729].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2729].entry.ee_code = EEC_MARREGNTY_MAJOR_NAVY_OPERATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2729].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2729].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2729].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2730].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2730].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2730].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2730].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2730].entry.ee_code = EEC_MARREGNTY_MINOR_NAVY_OPERATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2730].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2730].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2730].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2731].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2731].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2731].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2731].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2731].entry.ee_code = EEC_MARREGNTY_ASW_OPERATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2731].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2731].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2731].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2732].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2732].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2732].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2732].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2732].entry.ee_code = EEC_MARREGNTY_SUB_OPERATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2732].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2732].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2732].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2733].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2733].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2733].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2733].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2733].entry.ee_code = EEC_MARREGNTY_SUB_SUBMERGED_TRANSIT_LANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2733].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2733].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2733].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2734].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2734].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2734].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2734].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2734].entry.ee_code = EEC_MARREGNTY_SUB_SRF_TRANSIT_LANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2734].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2734].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2734].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2735].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2735].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2735].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2735].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2735].entry.ee_code = EEC_MARREGNTY_SRF_FREE_LANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2735].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2735].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2735].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2736].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2736].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2736].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2736].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2736].entry.ee_code = EEC_MARREGNTY_SRF_OPERATING_MAJOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2736].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2736].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2736].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2737].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2737].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2737].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2737].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2737].entry.ee_code = EEC_MARREGNTY_SRF_OPERATING_MINOR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2737].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2737].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2737].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2738].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2738].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2738].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2738].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2738].entry.ee_code = EEC_MARREGNTY_ANCHORING_FISHING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2738].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2738].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2738].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2739].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2739].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2739].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2739].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2739].entry.ee_code = EEC_MARREGNTY_SEA_TEST_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2739].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2739].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2739].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2740].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2740].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2740].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2740].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2740].entry.ee_code = EEC_MARREGNTY_SUB_GUNNERY_EXERCISE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2740].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2740].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2740].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2741].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2741].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2741].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2741].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2741].entry.ee_code = EEC_MARREGNTY_NAMED_OPERATING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2741].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2741].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2741].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2742].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2742].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2742].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2742].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2742].entry.ee_code = EEC_MARREGNTY_TERRITORIAL_SEA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2742].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2742].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2742].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2743].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2743].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2743].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2743].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2743].entry.ee_code = EEC_MARREGNTY_CONTINENTAL_SHELF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2743].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2743].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2743].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2744].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2744].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2744].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2744].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2744].entry.ee_code = EEC_MARREGNTY_CONTIGUOUS_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2744].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2744].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2744].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2745].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2745].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2745].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2745].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2745].entry.ee_code = EEC_MARREGNTY_EXCLUSIVE_ECONOMIC_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2745].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2745].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2745].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2746].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2746].enum_val = 121;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2746].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2746].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2746].entry.ee_code = EEC_MARREGNTY_FISHERY_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2746].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2746].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2746].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2747].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2747].enum_val = 122;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2747].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2747].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2747].entry.ee_code = EEC_MARREGNTY_FISHING_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2747].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2747].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2747].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2748].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2748].enum_val = 123;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2748].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2748].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2748].entry.ee_code = EEC_MARREGNTY_CAUTION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2748].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2748].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2748].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2749].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2749].enum_val = 124;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2749].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2749].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2749].entry.ee_code = EEC_MARREGNTY_VESSEL_DUMPING_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2749].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2749].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2749].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2750].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2750].enum_val = 125;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2750].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2750].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2750].entry.ee_code = EEC_MARREGNTY_MILITARY_PRACTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2750].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2750].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2750].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2751].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2751].enum_val = 126;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2751].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2751].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2751].entry.ee_code = EEC_MARREGNTY_SWIMMING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2751].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2751].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2751].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2752].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2752].enum_val = 127;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2752].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2752].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2752].entry.ee_code = EEC_MARREGNTY_WAITING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2752].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2752].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK (Waiting Area)\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2752].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2753].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2753].enum_val = 128;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2753].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2753].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2753].entry.ee_code = EEC_MARREGNTY_RESEARCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2753].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2753].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2753].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2754].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2754].enum_val = 129;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2754].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2754].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2754].entry.ee_code = EEC_MARREGNTY_ECOLOGICAL_RESERVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2754].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2754].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2754].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2755].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2755].enum_val = 130;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2755].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2755].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2755].entry.ee_code = EEC_MARREGNTY_NO_WAKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2755].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2755].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2755].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2756].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2756].enum_val = 131;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2756].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2756].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2756].entry.ee_code = EEC_MARREGNTY_ANCHORING_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2756].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2756].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2756].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2757].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2757].enum_val = 132;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2757].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2757].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2757].entry.ee_code = EEC_MARREGNTY_FISHING_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2757].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2757].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2757].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2758].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2758].enum_val = 133;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2758].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2758].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2758].entry.ee_code = EEC_MARREGNTY_TRAWLING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2758].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2758].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2758].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2759].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2759].enum_val = 134;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2759].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2759].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2759].entry.ee_code = EEC_MARREGNTY_TRAWLING_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2759].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2759].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2759].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2760].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2760].enum_val = 135;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2760].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2760].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2760].entry.ee_code = EEC_MARREGNTY_ENTRY_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2760].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2760].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2760].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2761].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2761].enum_val = 136;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2761].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2761].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2761].entry.ee_code = EEC_MARREGNTY_DREDGING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2761].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2761].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2761].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2762].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2762].enum_val = 137;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2762].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2762].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2762].entry.ee_code = EEC_MARREGNTY_DREDGING_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2762].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2762].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2762].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2763].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2763].enum_val = 138;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2763].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2763].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2763].entry.ee_code = EEC_MARREGNTY_DIVING_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2763].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2763].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2763].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2764].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2764].enum_val = 139;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2764].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2764].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2764].entry.ee_code = EEC_MARREGNTY_CONSTRUCTION_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2764].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2764].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2764].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2765].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2765].enum_val = 140;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2765].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2765].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2765].entry.ee_code = EEC_MARREGNTY_EXERCISE_AREA_LIMIT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2765].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2765].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2765].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2766].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2766].enum_val = 141;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2766].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2766].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2766].entry.ee_code = EEC_MARREGNTY_UNEXPLODED_MUNITIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2766].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2766].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2766].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2767].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2767].enum_val = 142;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2767].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2767].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2767].entry.ee_code = EEC_MARREGNTY_SUB_WARNING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2767].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2767].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2767].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2768].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2768].enum_val = 143;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2768].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2768].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2768].entry.ee_code = EEC_MARREGNTY_NAVAL_OPERATIONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2768].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2768].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2768].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2769].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2769].enum_val = 144;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2769].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2769].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2769].entry.ee_code = EEC_MARREGNTY_INWATER_TRACKING_RANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2769].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2769].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2769].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2770].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2770].enum_val = 145;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2770].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2770].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2770].entry.ee_code = EEC_MARREGNTY_FORACS_V_LIMITS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2770].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2770].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2770].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2771].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2771].enum_val = 146;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2771].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2771].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2771].entry.ee_code = EEC_MARREGNTY_MISSILE_TEST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2771].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2771].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2771].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2772].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2772].enum_val = 147;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2772].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2772].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2772].entry.ee_code = EEC_MARREGNTY_BOMBING_STRAFING_TARGETS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2772].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2772].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2772].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2773].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2773].enum_val = 148;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2773].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2773].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2773].entry.ee_code = EEC_MARREGNTY_DRILL_MINEFIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2773].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2773].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2773].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2774].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2774].enum_val = 149;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2774].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2774].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2774].entry.ee_code = EEC_MARREGNTY_ABANDONED_DRILL_MINEFIELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2774].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2774].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2774].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2775].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2775].enum_val = 150;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2775].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2775].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2775].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2775].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2775].entry.information = "NIMA does not define FACC Attribute code value \"Acronym Purple\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2775].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2776].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2776].enum_val = 151;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2776].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2776].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2776].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2776].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2776].entry.information = "NIMA does not define FACC Attribute code value \"Acronym Brown\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2776].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2777].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2777].enum_val = 152;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2777].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2777].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2777].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2777].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2777].entry.information = "NIMA does not define FACC Attribute code value \"Acronym Blue\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2777].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2778].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2778].enum_val = 153;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2778].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2778].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2778].entry.ee_code = EEC_MARREGNTY_LCAC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2778].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2778].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2778].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2779].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2779].enum_val = 154;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2779].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2779].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2779].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2779].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2779].entry.information = "NIMA does not define FACC Attribute code value \"Foxtrot\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2779].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2780].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2780].enum_val = 155;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2780].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2780].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2780].entry.ee_code = EEC_MARREGNTY_SUB_DANGER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2780].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2780].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2780].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2781].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2781].enum_val = 156;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2781].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2781].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2781].entry.ee_code = EEC_MARREGNTY_SRF_VESSEL_SAFETY_LANE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2781].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2781].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2781].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2782].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2782].enum_val = 157;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2782].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2782].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2782].entry.ee_code = EEC_MARREGNTY_ATLANTIC_FLEET_WEAPONS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2782].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2782].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2782].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2783].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2783].enum_val = 158;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2783].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2783].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2783].entry.ee_code = EEC_MARREGNTY_NAVAL_DEFENCE_SEA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2783].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2783].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2783].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2784].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2784].enum_val = 159;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2784].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2784].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2784].entry.ee_code = EEC_MARREGNTY_UNDERWATER_TELEPHONE_TEST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2784].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2784].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2784].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2785].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2785].enum_val = 160;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2785].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2785].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2785].entry.ee_code = EEC_MARREGNTY_WATER_SKIING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2785].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2785].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2785].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2786].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2786].enum_val = 161;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2786].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2786].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2786].entry.ee_code = EEC_MARREGNTY_DISCHARGING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2786].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2786].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2786].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2787].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2787].enum_val = 162;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2787].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2787].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2787].entry.ee_code = EEC_MARREGNTY_DISCHARGING_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2787].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2787].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2787].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2788].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2788].enum_val = 163;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2788].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2788].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2788].entry.ee_code = EEC_MARREGNTY_EXPLORE_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2788].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2788].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2788].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2789].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2789].enum_val = 164;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2789].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2789].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2789].entry.ee_code = EEC_MARREGNTY_EXPLORE_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2789].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2789].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2789].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2790].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2790].enum_val = 165;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2790].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2790].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2790].entry.ee_code = EEC_MARREGNTY_DRILLING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2790].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2790].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2790].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2791].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2791].enum_val = 166;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2791].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2791].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2791].entry.ee_code = EEC_MARREGNTY_DRILLING_RSTRCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2791].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2791].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2791].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2792].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2792].enum_val = 167;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2792].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2792].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2792].entry.ee_code = EEC_MARREGNTY_ARTIFACT_REMOVAL_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2792].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2792].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2792].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2793].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2793].enum_val = 168;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2793].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2793].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2793].entry.ee_code = EEC_MARREGNTY_CARGO_TRNSHP_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2793].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2793].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2793].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2794].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2794].enum_val = 169;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2794].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2794].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2794].entry.ee_code = EEC_MARREGNTY_DRAGGING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2794].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2794].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2794].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2795].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2795].enum_val = 170;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2795].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2795].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2795].entry.ee_code = EEC_MARREGNTY_STOPPING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2795].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2795].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2795].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2796].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2796].enum_val = 171;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2796].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2796].entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2796].entry.ee_code = EEC_MARREGNTY_LANDING_PRHBT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2796].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2796].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2796].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2797].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2797].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2797].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2797].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2797].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2797].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2797].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2797].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2798].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2798].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2798].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2798].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2798].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2798].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2798].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2798].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2799].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2799].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2799].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2799].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2799].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2799].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2799].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2799].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2800].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2800].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2800].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2800].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2800].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2800].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2800].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_REGION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2800].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2801].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2801].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2801].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2801].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2801].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2801].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2801].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2801].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2802].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2802].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2802].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2802].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2802].entry.ee_code = EEC_AIDNAVMKCOLR_GREEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2802].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2802].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2802].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2803].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2803].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2803].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2803].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2803].entry.ee_code = EEC_AIDNAVMKCOLR_BLACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2803].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2803].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2803].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2804].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2804].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2804].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2804].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2804].entry.ee_code = EEC_AIDNAVMKCOLR_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2804].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2804].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2804].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2805].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2805].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2805].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2805].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2805].entry.ee_code = EEC_AIDNAVMKCOLR_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2805].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2805].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2805].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2806].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2806].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2806].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2806].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2806].entry.ee_code = EEC_AIDNAVMKCOLR_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2806].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2806].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2806].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2807].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2807].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2807].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2807].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2807].entry.ee_code = EEC_AIDNAVMKCOLR_ORANGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2807].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2807].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2807].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2808].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2808].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2808].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2808].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2808].entry.ee_code = EEC_AIDNAVMKCOLR_BLACK_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2808].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2808].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2808].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2809].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2809].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2809].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2809].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2809].entry.ee_code = EEC_AIDNAVMKCOLR_BLACK_YELLOW_BLACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2809].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2809].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2809].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2810].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2810].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2810].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2810].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2810].entry.ee_code = EEC_AIDNAVMKCOLR_YELLOW_BLACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2810].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2810].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2810].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2811].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2811].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2811].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2811].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2811].entry.ee_code = EEC_AIDNAVMKCOLR_YELLOW_BLACK_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2811].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2811].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2811].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2812].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2812].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2812].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2812].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2812].entry.ee_code = EEC_AIDNAVMKCOLR_RED_WHITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2812].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2812].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2812].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2813].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2813].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2813].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2813].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2813].entry.ee_code = EEC_AIDNAVMKCOLR_GREEN_RED_GREEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2813].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2813].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2813].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2814].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2814].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2814].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2814].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2814].entry.ee_code = EEC_AIDNAVMKCOLR_RED_GREEN_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2814].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2814].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2814].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2815].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2815].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2815].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2815].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2815].entry.ee_code = EEC_AIDNAVMKCOLR_BLACK_RED_BLACK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2815].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2815].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2815].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2816].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2816].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2816].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2816].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2816].entry.ee_code = EEC_AIDNAVMKCOLR_YELLOW_RED_YELLOW;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2816].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2816].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2816].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2817].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2817].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2817].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2817].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2817].entry.ee_code = EEC_AIDNAVMKCOLR_GREEN_RED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2817].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2817].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2817].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2818].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2818].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2818].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2818].entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2818].entry.ee_code = EEC_AIDNAVMKCOLR_RED_GREEN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2818].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2818].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2818].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2819].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2819].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2819].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2819].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2819].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2819].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2819].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2819].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2820].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2820].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2820].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2820].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2820].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2820].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2820].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2820].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2821].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2821].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2821].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2821].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2821].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2821].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2821].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2821].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2822].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2822].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2822].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2822].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2822].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2822].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2822].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2822].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2823].code.tag, "MAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2823].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2823].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2823].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2823].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2823].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2823].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAINTAINED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2823].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2824].code.tag, "MAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2824].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2824].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2824].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2824].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2824].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2824].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MAINTAINED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_TRUE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2824].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2825].code.tag, "MAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2825].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2825].entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2825].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2825].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2825].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2825].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_MAINTAINED;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_BOOLEAN;
    temp_entries[0].u.attr_value_entry.ea_value.value.boolean_value = EDCS_FALSE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2825].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2826].code.tag, "MAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2826].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2826].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2826].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2826].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2826].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2826].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAINTAINED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2826].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2827].code.tag, "MAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2827].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2827].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2827].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2827].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2827].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2827].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAINTAINED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2827].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2828].code.tag, "MAS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2828].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2828].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2828].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2828].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2828].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2828].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MAINTAINED;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2828].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2829].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2829].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2829].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2829].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2829].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2829].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2829].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2829].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2830].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2830].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2830].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2830].entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2830].entry.ee_code = EEC_MINEOTHINFTY_IDENTITY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2830].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2830].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2830].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2831].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2831].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2831].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2831].entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2831].entry.ee_code = EEC_MINEOTHINFTY_STATUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2831].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2831].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2831].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2832].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2832].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2832].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2832].entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2832].entry.ee_code = EEC_MINEOTHINFTY_LOCATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2832].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2832].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2832].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2833].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2833].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2833].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2833].entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2833].entry.ee_code = EEC_MINEOTHINFTY_SPECIAL_INFORMATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2833].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2833].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2833].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2834].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2834].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2834].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2834].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2834].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2834].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2834].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2834].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2835].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2835].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2835].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2835].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2835].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2835].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2835].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2835].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2836].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2836].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2836].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2836].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2836].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2836].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2836].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2836].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2837].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2837].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2837].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2837].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2837].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2837].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2837].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2837].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2838].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2838].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2838].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2838].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2838].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2838].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2838].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2838].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2839].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2839].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2839].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2839].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2839].entry.ee_code = EEC_MARBNDRYLIMTY_COLREGS_DEMARCATION_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2839].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2839].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2839].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2840].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2840].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2840].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2840].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2840].entry.ee_code = EEC_MARBNDRYLIMTY_CUSTOMS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2840].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2840].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2840].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2841].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2841].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2841].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2841].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2841].entry.ee_code = EEC_MARBNDRYLIMTY_FISHING_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2841].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2841].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2841].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2842].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2842].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2842].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2842].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2842].entry.ee_code = EEC_MARBNDRYLIMTY_HARBOUR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2842].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2842].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2842].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2843].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2843].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2843].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2843].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2843].entry.ee_code = EEC_MARBNDRYLIMTY_TSS_SEPARATION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2843].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2843].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2843].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2844].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2844].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2844].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2844].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2844].entry.ee_code = EEC_MARBNDRYLIMTY_TRRT_WATERS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2844].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2844].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2844].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2845].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2845].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2845].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2845].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2845].entry.ee_code = EEC_MARBNDRYLIMTY_TRRT_WATERS_BASELINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2845].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2845].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2845].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2846].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2846].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2846].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2846].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2846].entry.ee_code = EEC_MARBNDRYLIMTY_MARINE_LIMIT_GENERAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2846].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2846].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2846].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2847].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2847].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2847].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2847].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2847].entry.ee_code = EEC_MARBNDRYLIMTY_INTERNATIONAL_BOUNDARY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2847].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2847].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2847].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2848].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2848].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2848].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2848].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2848].entry.ee_code = EEC_MARBNDRYLIMTY_CONTINENTAL_SHELF;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2848].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2848].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2848].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2849].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2849].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2849].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2849].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2849].entry.ee_code = EEC_MARBNDRYLIMTY_EXCLUSIVE_ECONOMIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2849].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2849].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2849].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2850].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2850].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2850].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2850].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2850].entry.ee_code = EEC_MARBNDRYLIMTY_CONTIGUOUS_ZONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2850].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2850].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2850].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2851].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2851].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2851].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2851].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2851].entry.ee_code = EEC_MARBNDRYLIMTY_CLEARING_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2851].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2851].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2851].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2852].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2852].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2852].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2852].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2852].entry.ee_code = EEC_MARBNDRYLIMTY_DANGER_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2852].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2852].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2852].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2853].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2853].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2853].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2853].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2853].entry.ee_code = EEC_MARBNDRYLIMTY_ARMISTICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2853].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2853].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2853].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2854].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2854].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2854].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2854].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2854].entry.ee_code = EEC_MARBNDRYLIMTY_GULF_STREAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2854].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2854].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2854].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2855].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2855].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2855].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2855].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2855].entry.ee_code = EEC_MARBNDRYLIMTY_THREE_NAUTICAL_MILE_LINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2855].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2855].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2855].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2856].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2856].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2856].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2856].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2856].entry.ee_code = EEC_MARBNDRYLIMTY_APPROXIMATE_BATHYMETRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2856].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2856].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2856].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2857].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2857].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2857].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2857].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2857].entry.ee_code = EEC_MARBNDRYLIMTY_MANAGEMENT_AND_ZONING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2857].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2857].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2857].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2858].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2858].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2858].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2858].entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2858].entry.ee_code = EEC_MARBNDRYLIMTY_TRAFFIC_SERVICES;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2858].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2858].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2858].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2859].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2859].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2859].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2859].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2859].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2859].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2859].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2859].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2860].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2860].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2860].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2860].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2860].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2860].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2860].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2860].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2861].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2861].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2861].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2861].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2861].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2861].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2861].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2861].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2862].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2862].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2862].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2862].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2862].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2862].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2862].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2862].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2863].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2863].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2863].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2863].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2863].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2863].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2863].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2863].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2864].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2864].enum_val = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2864].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2864].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2864].entry.ee_code = EEC_PRIMATTY_ALUMINUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2864].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2864].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2864].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2865].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2865].enum_val = 2;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2865].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2865].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2865].entry.ee_code = EEC_PRIMATTY_ALUMINUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2865].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2865].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2865].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2866].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2866].enum_val = 3;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2866].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2866].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2866].entry.ee_code = EEC_PRIMATTY_AMMUNITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2866].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2866].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2866].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2867].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2867].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2867].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2867].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2867].entry.ee_code = EEC_PRIMATTY_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2867].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2867].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2867].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2868].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2868].enum_val = 5;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2868].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2868].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2868].entry.ee_code = EEC_PRIMATTY_ASPHALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2868].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2868].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2868].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2869].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2869].enum_val = 6;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2869].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2869].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2869].entry.ee_code = EEC_PRIMATTY_BASALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2869].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2869].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2869].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2870].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2870].enum_val = 7;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2870].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2870].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2870].entry.ee_code = EEC_PRIMATTY_BEDROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2870].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2870].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2870].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2871].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2871].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2871].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2871].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2871].entry.ee_code = EEC_PRIMATTY_BOULDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2871].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2871].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2871].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2872].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2872].enum_val = 9;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2872].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2872].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2872].entry.ee_code = EEC_PRIMATTY_BRICK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2872].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2872].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2872].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2873].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2873].enum_val = 10;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2873].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2873].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2873].entry.ee_code = EEC_PRIMATTY_CALCAREOUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2873].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2873].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2873].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2874].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2874].enum_val = 11;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2874].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2874].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2874].entry.ee_code = EEC_PRIMATTY_CEMENT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2874].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2874].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2874].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2875].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2875].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2875].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2875].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2875].entry.ee_code = EEC_PRIMATTY_CHALK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2875].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2875].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2875].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2876].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2876].enum_val = 13;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2876].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2876].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2876].entry.ee_code = EEC_PRIMATTY_CHEMICAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2876].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2876].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2876].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2877].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2877].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2877].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2877].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2877].entry.ee_code = EEC_PRIMATTY_CINDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2877].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2877].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2877].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2878].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2878].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2878].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2878].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2878].entry.ee_code = EEC_PRIMATTY_CIRRIPEDIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2878].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2878].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2878].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2879].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2879].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2879].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2879].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2879].entry.ee_code = EEC_PRIMATTY_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2879].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2879].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2879].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2880].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2880].enum_val = 17;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2880].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2880].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2880].entry.ee_code = EEC_PRIMATTY_COAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2880].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2880].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2880].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2881].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2881].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2881].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2881].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2881].entry.ee_code = EEC_PRIMATTY_COBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2881].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2881].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2881].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2882].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2882].enum_val = 19;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2882].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2882].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2882].entry.ee_code = EEC_PRIMATTY_COKE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2882].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2882].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2882].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2883].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2883].enum_val = 20;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2883].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2883].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2883].entry.ee_code = EEC_PRIMATTY_COMPOSITION;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2883].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2883].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2883].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2884].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2884].enum_val = 21;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2884].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2884].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2884].entry.ee_code = EEC_PRIMATTY_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2884].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2884].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2884].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2885].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2885].enum_val = 22;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2885].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2885].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2885].entry.ee_code = EEC_PRIMATTY_CONGLOMERATE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2885].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2885].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2885].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2886].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2886].enum_val = 23;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2886].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2886].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2886].entry.ee_code = EEC_PRIMATTY_COPPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2886].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2886].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2886].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2887].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2887].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2887].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2887].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2887].entry.ee_code = EEC_PRIMATTY_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2887].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2887].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2887].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2888].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2888].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2888].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2888].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2888].entry.ee_code = EEC_PRIMATTY_CORAL_HEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2888].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2888].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2888].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2889].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2889].enum_val = 26;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2889].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2889].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2889].entry.ee_code = EEC_PRIMATTY_DESALINATED_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2889].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2889].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2889].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2890].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2890].enum_val = 27;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2890].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2890].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2890].entry.ee_code = EEC_PRIMATTY_DIAMOND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2890].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2890].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2890].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2891].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2891].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2891].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2891].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2891].entry.ee_code = EEC_PRIMATTY_DIATOMACEOUS_EARTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2891].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2891].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2891].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2892].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2892].enum_val = 29;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2892].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2892].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2892].entry.ee_code = EEC_PRIMATTY_DOLOMITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2892].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2892].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2892].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2893].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2893].enum_val = 30;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2893].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2893].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2893].entry.ee_code = EEC_PRIMATTY_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2893].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2893].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2893].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2894].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2894].enum_val = 31;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2894].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2894].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2894].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2894].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2894].entry.information = "\"Electric\" is not a material type.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2894].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2895].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2895].enum_val = 32;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2895].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2895].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2895].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2895].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2895].entry.information = "\"Eroded land\" is not a material type. See <<TERRAIN_MORPHOLOGY>>.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2895].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2896].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2896].enum_val = 33;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2896].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2896].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2896].entry.ee_code = EEC_PRIMATTY_EXPLOSIVE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2896].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2896].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2896].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2897].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2897].enum_val = 34;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2897].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2897].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2897].entry.ee_code = EEC_PRIMATTY_FLYSCH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2897].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2897].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2897].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2898].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2898].enum_val = 35;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2898].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2898].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2898].entry.ee_code = EEC_PRIMATTY_FOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2898].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2898].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2898].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2899].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2899].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2899].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2899].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2899].entry.ee_code = EEC_PRIMATTY_FORAMINIFERA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2899].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2899].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2899].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2900].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2900].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2900].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2900].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2900].entry.ee_code = EEC_PRIMATTY_FUCUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2900].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2900].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2900].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2901].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2901].enum_val = 38;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2901].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2901].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2901].entry.ee_code = EEC_PRIMATTY_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2901].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2901].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2901].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2902].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2902].enum_val = 39;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2902].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2902].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2902].entry.ee_code = EEC_PRIMATTY_GAS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2902].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2902].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2902].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2903].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2903].enum_val = 40;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2903].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2903].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2903].entry.ee_code = EEC_PRIMATTY_GLASS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2903].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2903].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2903].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2904].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2904].enum_val = 41;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2904].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2904].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2904].entry.ee_code = EEC_PRIMATTY_GLOBIGERINA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2904].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2904].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2904].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2905].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2905].enum_val = 42;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2905].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2905].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2905].entry.ee_code = EEC_PRIMATTY_GOLD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2905].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2905].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2905].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2906].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2906].enum_val = 43;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2906].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2906].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2906].entry.ee_code = EEC_PRIMATTY_GRANITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2906].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2906].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2906].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2907].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2907].enum_val = 44;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2907].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2907].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2907].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2907].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2907].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2907].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2908].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2908].enum_val = 45;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2908].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2908].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2908].entry.ee_code = EEC_PRIMATTY_PLANT_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2908].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2908].entry.information = "Generalized from \"Grass or thatch\".";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2908].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2909].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2909].enum_val = 46;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2909].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2909].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2909].entry.ee_code = EEC_PRIMATTY_GRAVEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2909].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2909].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2909].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2910].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2910].enum_val = 47;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2910].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2910].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2910].entry.ee_code = EEC_PRIMATTY_GREENSTONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2910].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2910].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2910].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2911].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2911].enum_val = 48;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2911].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2911].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2911].entry.ee_code = EEC_PRIMATTY_GROUND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2911].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2911].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2911].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2912].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2912].enum_val = 49;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2912].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2912].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2912].entry.ee_code = EEC_PRIMATTY_GROUND_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2912].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2912].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2912].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2913].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2913].enum_val = 50;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2913].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2913].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2913].entry.ee_code = EEC_PRIMATTY_HEAT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2913].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2913].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2913].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2914].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2914].enum_val = 51;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2914].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2914].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2914].entry.ee_code = EEC_PRIMATTY_IRON;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2914].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2914].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2914].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2915].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2915].enum_val = 52;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2915].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2915].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2915].entry.ee_code = EEC_PRIMATTY_LAVA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2915].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2915].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2915].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2916].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2916].enum_val = 53;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2916].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2916].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2916].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2916].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2916].entry.information = "Was: \"VALUE INTENTIONALLY LEFT BLANK\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2916].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2917].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2917].enum_val = 54;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2917].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2917].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2917].entry.ee_code = EEC_PRIMATTY_LEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2917].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2917].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2917].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2918].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2918].enum_val = 55;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2918].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2918].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2918].entry.ee_code = EEC_PRIMATTY_LOESS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2918].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2918].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2918].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2919].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2919].enum_val = 56;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2919].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2919].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2919].entry.ee_code = EEC_PRIMATTY_LUMBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2919].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2919].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2919].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2920].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2920].enum_val = 57;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2920].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2920].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2920].entry.ee_code = EEC_PRIMATTY_MACADAM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2920].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2920].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2920].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2921].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2921].enum_val = 58;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2921].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2921].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2921].entry.ee_code = EEC_PRIMATTY_MADREPORE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2921].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2921].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2921].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2922].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2922].enum_val = 59;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2922].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2922].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2922].entry.ee_code = EEC_PRIMATTY_MANGANESE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2922].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2922].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2922].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2923].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2923].enum_val = 60;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2923].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2923].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2923].entry.ee_code = EEC_PRIMATTY_MARBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2923].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2923].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2923].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2924].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2924].enum_val = 61;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2924].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2924].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2924].entry.ee_code = EEC_PRIMATTY_MARL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2924].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2924].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2924].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2925].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2925].enum_val = 62;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2925].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2925].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2925].entry.ee_code = EEC_PRIMATTY_MASONRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2925].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2925].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2925].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2926].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2926].enum_val = 63;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2926].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2926].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2926].entry.ee_code = EEC_PRIMATTY_MATTE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2926].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2926].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2926].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2927].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2927].enum_val = 64;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2927].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2927].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2927].entry.ee_code = EEC_PRIMATTY_METAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2927].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2927].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2927].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2928].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2928].enum_val = 65;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2928].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2928].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2928].entry.ee_code = EEC_PRIMATTY_MUD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2928].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2928].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2928].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2929].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2929].enum_val = 66;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2929].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2929].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2929].entry.ee_code = EEC_PRIMATTY_MUSSEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2929].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2929].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2929].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2930].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2930].enum_val = 67;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2930].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2930].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2930].entry.ee_code = EEC_PRIMATTY_OIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2930].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2930].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2930].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2931].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2931].enum_val = 68;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2931].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2931].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2931].entry.ee_code = EEC_PRIMATTY_OIL_BLISTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2931].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2931].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2931].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2932].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2932].enum_val = 69;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2932].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2932].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2932].entry.ee_code = EEC_PRIMATTY_OOZE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2932].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2932].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2932].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2933].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2933].enum_val = 70;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2933].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2933].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2933].entry.ee_code = EEC_PRIMATTY_OYSTER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2933].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2933].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2933].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2934].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2934].enum_val = 71;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2934].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2934].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2934].entry.ee_code = EEC_PRIMATTY_PAPER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2934].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2934].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2934].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2935].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2935].enum_val = 72;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2935].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2935].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2935].entry.ee_code = EEC_PRIMATTY_PART_METAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2935].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2935].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2935].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2936].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2936].enum_val = 73;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2936].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2936].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2936].entry.ee_code = EEC_PRIMATTY_PEBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2936].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2936].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2936].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2937].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2937].enum_val = 74;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2937].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2937].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2937].entry.ee_code = EEC_PRIMATTY_PLASTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2937].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2937].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2937].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2938].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2938].enum_val = 75;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2938].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2938].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2938].entry.ee_code = EEC_PRIMATTY_POLYZOA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2938].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2938].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2938].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2939].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2939].enum_val = 76;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2939].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2939].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2939].entry.ee_code = EEC_PRIMATTY_PORPHYRY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2939].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2939].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2939].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2940].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2940].enum_val = 77;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2940].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2940].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2940].entry.ee_code = EEC_PRIMATTY_PRESTRESSED_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2940].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2940].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2940].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2941].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2941].enum_val = 78;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2941].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2941].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2941].entry.ee_code = EEC_PRIMATTY_PTEROPOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2941].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2941].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2941].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2942].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2942].enum_val = 79;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2942].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2942].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2942].entry.ee_code = EEC_PRIMATTY_PUMICE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2942].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2942].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2942].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2943].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2943].enum_val = 80;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2943].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2943].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2943].entry.ee_code = EEC_PRIMATTY_QUARTZ;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2943].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2943].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2943].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2944].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2944].enum_val = 81;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2944].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2944].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2944].entry.ee_code = EEC_PRIMATTY_RADIOLARIAN;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2944].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2944].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2944].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2945].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2945].enum_val = 82;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2945].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2945].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2945].entry.ee_code = EEC_PRIMATTY_RADIOACTIVE_MATERIAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2945].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2945].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2945].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2946].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2946].enum_val = 83;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2946].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2946].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2946].entry.ee_code = EEC_PRIMATTY_REINFORCED_CONCRETE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2946].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2946].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2946].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2947].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2947].enum_val = 84;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2947].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2947].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2947].entry.ee_code = EEC_PRIMATTY_ROCK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2947].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2947].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2947].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2948].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2948].enum_val = 85;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2948].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2948].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2948].entry.ee_code = EEC_PRIMATTY_RUBBER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2948].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2948].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2948].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2949].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2949].enum_val = 86;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2949].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2949].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2949].entry.ee_code = EEC_PRIMATTY_RUBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2949].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2949].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2949].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2950].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2950].enum_val = 87;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2950].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2950].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2950].entry.ee_code = EEC_PRIMATTY_SALT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2950].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2950].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2950].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2951].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2951].enum_val = 88;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2951].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2951].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2951].entry.ee_code = EEC_PRIMATTY_SAND;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2951].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2951].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2951].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2952].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2952].enum_val = 89;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2952].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2952].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2952].entry.ee_code = EEC_PRIMATTY_SANDSTONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2952].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2952].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2952].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2953].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2953].enum_val = 90;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2953].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2953].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2953].entry.ee_code = EEC_PRIMATTY_SCHIST;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2953].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2953].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2953].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2954].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2954].enum_val = 91;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2954].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2954].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2954].entry.ee_code = EEC_PRIMATTY_SPOIL_OR_TAILINGS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2954].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2954].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2954].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2955].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2955].enum_val = 92;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2955].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2955].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2955].entry.ee_code = EEC_PRIMATTY_SCORIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2955].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2955].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2955].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2956].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2956].enum_val = 93;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2956].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2956].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2956].entry.ee_code = EEC_PRIMATTY_SEA_TANGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2956].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2956].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2956].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2957].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2957].enum_val = 94;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2957].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2957].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2957].entry.ee_code = EEC_PRIMATTY_SEAWEED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2957].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2957].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2957].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2958].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2958].enum_val = 95;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2958].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2958].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2958].entry.ee_code = EEC_PRIMATTY_SEWAGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2958].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2958].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2958].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2959].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2959].enum_val = 96;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2959].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2959].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2959].entry.ee_code = EEC_PRIMATTY_SHELL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2959].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2959].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2959].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2960].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2960].enum_val = 98;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2960].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2960].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2960].entry.ee_code = EEC_PRIMATTY_SHINGLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2960].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2960].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2960].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2961].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2961].enum_val = 99;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2961].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2961].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2961].entry.ee_code = EEC_PRIMATTY_SILT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2961].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2961].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2961].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2962].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2962].enum_val = 100;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2962].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2962].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2962].entry.ee_code = EEC_PRIMATTY_SILVER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2962].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2962].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2962].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2963].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2963].enum_val = 101;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2963].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2963].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2963].entry.ee_code = EEC_PRIMATTY_SLAG;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2963].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2963].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2963].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2964].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2964].enum_val = 102;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2964].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2964].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2964].entry.ee_code = EEC_PRIMATTY_SLUDGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2964].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2964].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2964].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2965].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2965].enum_val = 103;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2965].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2965].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2965].entry.ee_code = EEC_PRIMATTY_FROZEN_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2965].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2965].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2965].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2966].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2966].enum_val = 104;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2966].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2966].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2966].entry.ee_code = EEC_PRIMATTY_SOIL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2966].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2966].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2966].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2967].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2967].enum_val = 105;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2967].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2967].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2967].entry.ee_code = EEC_PRIMATTY_SPICULE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2967].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2967].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2967].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2968].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2968].enum_val = 106;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2968].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2968].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2968].entry.ee_code = EEC_PRIMATTY_SPONGE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2968].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2968].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2968].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2969].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2969].enum_val = 107;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2969].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2969].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2969].entry.ee_code = EEC_PRIMATTY_STEEL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2969].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2969].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2969].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2970].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2970].enum_val = 108;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2970].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2970].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2970].entry.ee_code = EEC_PRIMATTY_STONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2970].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2970].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2970].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2971].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2971].enum_val = 109;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2971].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2971].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2971].entry.ee_code = EEC_PRIMATTY_SUGAR;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2971].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2971].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2971].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2972].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2972].enum_val = 110;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2972].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2972].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2972].entry.ee_code = EEC_PRIMATTY_TRAVERTINE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2972].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2972].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2972].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2973].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2973].enum_val = 111;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2973].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2973].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2973].entry.ee_code = EEC_PRIMATTY_TUFA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2973].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2973].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2973].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2974].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2974].enum_val = 112;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2974].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2974].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2974].entry.ee_code = EEC_PRIMATTY_URANIUM;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2974].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2974].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2974].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2975].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2975].enum_val = 113;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2975].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2975].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2975].entry.ee_code = EEC_PRIMATTY_VEGETATION_PRODUCT;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2975].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2975].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2975].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2976].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2976].enum_val = 114;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2976].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2976].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2976].entry.ee_code = EEC_PRIMATTY_VOLCANIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2976].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2976].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2976].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2977].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2977].enum_val = 115;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2977].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2977].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2977].entry.ee_code = EEC_PRIMATTY_VOLCANIC_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2977].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2977].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2977].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2978].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2978].enum_val = 116;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2978].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2978].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2978].entry.ee_code = EEC_PRIMATTY_WATER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2978].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2978].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2978].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2979].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2979].enum_val = 117;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2979].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2979].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2979].entry.ee_code = EEC_PRIMATTY_WOOD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2979].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2979].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2979].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2980].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2980].enum_val = 118;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2980].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2980].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2980].entry.ee_code = EEC_PRIMATTY_ZINC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2980].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2980].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2980].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2981].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2981].enum_val = 119;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2981].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2981].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2981].entry.ee_code = EEC_PRIMATTY_EVAPORITE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2981].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2981].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2981].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2982].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2982].enum_val = 120;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2982].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2982].entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2982].entry.ee_code = EEC_PRIMATTY_GLASS_REINFORCED_PLASTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2982].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2982].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2982].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2983].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2983].enum_val = 989;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2983].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2983].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2983].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2983].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2983].entry.information = "Based on Table 5.2 Special Reserved Values.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MULTIPLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2983].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2984].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2984].enum_val = 997;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2984].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2984].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2984].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2984].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2984].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_VALUE_WITHHELD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2984].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2985].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2985].enum_val = 998;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2985].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2985].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2985].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2985].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2985].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_NOT_APPLICABLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2985].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2986].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2986].enum_val = 999;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2986].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2986].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2986].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2986].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2986].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_UNDESIGNATED;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2986].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2987].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2987].enum_val = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2987].entry.map_type = FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2987].entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2987].entry.ee_code = ((EDCS_Enumerant_Code)0);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2987].entry.num_entries = 1;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2987].entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }

    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC;
    temp_entries[0].u.characteristic_entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    temp_entries[0].u.characteristic_entry.ev_code = EVC_MISSING;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2987].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2988].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2988].enum_val = 4;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2988].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2988].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2988].entry.ee_code = EEC_SECMATTY_ASH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2988].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2988].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2988].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2989].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2989].enum_val = 8;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2989].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2989].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2989].entry.ee_code = EEC_SECMATTY_BOULDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2989].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2989].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2989].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2990].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2990].enum_val = 12;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2990].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2990].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2990].entry.ee_code = EEC_SECMATTY_CHALK;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2990].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2990].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2990].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2991].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2991].enum_val = 14;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2991].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2991].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2991].entry.ee_code = EEC_SECMATTY_CINDER;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2991].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2991].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2991].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2992].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2992].enum_val = 15;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2992].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2992].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2992].entry.ee_code = EEC_SECMATTY_CIRRIPEDIA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2992].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2992].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2992].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2993].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2993].enum_val = 16;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2993].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2993].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2993].entry.ee_code = EEC_SECMATTY_CLAY;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2993].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2993].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2993].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2994].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2994].enum_val = 18;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2994].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2994].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2994].entry.ee_code = EEC_SECMATTY_COBBLE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2994].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2994].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2994].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2995].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2995].enum_val = 24;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2995].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2995].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2995].entry.ee_code = EEC_SECMATTY_CORAL;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2995].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2995].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2995].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2996].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2996].enum_val = 25;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2996].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2996].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2996].entry.ee_code = EEC_SECMATTY_CORAL_HEAD;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2996].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2996].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2996].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2997].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2997].enum_val = 28;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2997].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2997].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2997].entry.ee_code = EEC_SECMATTY_DIATOMACEOUS_EARTH;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2997].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2997].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2997].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2998].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2998].enum_val = 36;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2998].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2998].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2998].entry.ee_code = EEC_SECMATTY_FORAMINIFERA;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2998].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2998].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2998].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Enumerant_Mapping_Array[2999].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2999].enum_val = 37;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2999].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2999].entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2999].entry.ee_code = EEC_SECMATTY_FUCUS;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2999].entry.num_entries = 0;
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2999].entry.information = "";
    EDCS_FACC_2p1_Enumerant_Mapping_Array[2999].entry.entry_list = NULL;

    return EDCS_SC_SUCCESS;
} /* end local_init_facc_attribute_enum_mapping_pt3 */

