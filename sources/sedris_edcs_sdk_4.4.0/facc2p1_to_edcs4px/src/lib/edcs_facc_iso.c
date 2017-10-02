/*
 * FILE: edcs_facc_iso.c
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

#define EDCS_FACC_CLASS_MAPPING_COUNT  539
#define EDCS_FACC_ATTRIBUTE_MAPPING_COUNT  658
#define EDCS_FACC_ATTR_ENUM_MAPPING_COUNT  6317

/*
 * GLOBAL: facc_2p1_mapping_initialized
 *
 * Internal variable to keep track of whether or
 * not the internal mapping structures been initialized.
 */
static EDCS_Boolean facc_2p1_mapping_initialized = EDCS_FALSE;

/*
 * STRUCT: EDCS_FACC_2p1_Class_Mapping
 *
 *   Relates an 2.1 FACC Feature code to its EDCS 4.x mapping.
 */
typedef struct
{
    FACC_2p1_Feature_Code        code;
    FACC_2p1_Class_Mapping_Structure entry;
} EDCS_FACC_2p1_Class_Mapping;

/* this structure is initialized in the local_init_facc_feature_mapping() function */
EDCS_FACC_2p1_Class_Mapping EDCS_FACC_2p1_Class_Mapping_Array[EDCS_FACC_CLASS_MAPPING_COUNT];

/*
 * STRUCT: EDCS_FACC_2p1_Attribute_Mapping
 *
 *   Relates a 2.1 FACC Attribute code to its EDCS 4.x mapping.
 */
typedef struct
{
    FACC_2p1_Attribute_Code              code;
    FACC_2p1_Attribute_Mapping_Structure ea_entry;
    FACC_2p1_Unit_Mapping_Structure      eu_entry;
} EDCS_FACC_2p1_Attribute_Mapping;

/* this structure is initialized in the local_init_facc_attribute_mapping() function */
EDCS_FACC_2p1_Attribute_Mapping EDCS_FACC_2p1_Attribute_Mapping_Array[EDCS_FACC_ATTRIBUTE_MAPPING_COUNT];

/*
 * STRUCT: EDCS_FACC_2p1_Enumerant_Mapping
 *
 *   Relates a 2.1 FACC Attribute code and 2.1 FACC Attribute Enumerant to its
 *   EDCS 4.3 mapping.
 */
typedef struct
{
    FACC_2p1_Attribute_Code              code;
    FACC_2p1_Attribute_Integer_Code      enum_val;
    FACC_2p1_Enumerant_Mapping_Structure entry;
} EDCS_FACC_2p1_Enumerant_Mapping;

/* this structure is initialized in the local_init_ee_mapping() function */
EDCS_FACC_2p1_Enumerant_Mapping EDCS_FACC_2p1_Enumerant_Mapping_Array[EDCS_FACC_ATTR_ENUM_MAPPING_COUNT];

int
local_FACC_Compare_Attribute
(
    const FACC_2p1_Attribute_Code *a_ptr,
    const FACC_2p1_Attribute_Code *b_ptr
)
{
    EDCS_Count i;
    int      result = 0;
    char     c1, c2;

    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;

    i = 0;
    while ((result==0) && (i < 3))
    {
        c1 = (char) toupper(a_ptr->tag[i]);
        c2 = (char) toupper(b_ptr->tag[i]);
        if (c1 < c2)
            result = -1;
        else if (c1 > c2)
            result = 1;
        i++;
    }
    return result;
} /* end local_FACC_Compare_Attribute */

int
local_CompareAttr_Mapping
(
    const EDCS_FACC_2p1_Attribute_Mapping *a_ptr,
    const EDCS_FACC_2p1_Attribute_Mapping *b_ptr
)
{
    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;
    else
        return local_FACC_Compare_Attribute( &(a_ptr->code), &(b_ptr->code) );
} /* end local_CompareAttr_Mapping */

int
local_Compare_FACC_Enum_Mapping
(
    const EDCS_FACC_2p1_Enumerant_Mapping *a_ptr,
    const EDCS_FACC_2p1_Enumerant_Mapping *b_ptr
)
{
    int result;

    if (!a_ptr && b_ptr)
    {
        return -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        return 0;
    }
    else if (a_ptr && !b_ptr)
    {
        return 1;
    }
    else
    {
        result = local_FACC_Compare_Attribute( &(a_ptr->code), &(b_ptr->code) );
        if (result == 0)
        {
            if(a_ptr->enum_val < b_ptr->enum_val)
                    result = -1;
                else if(a_ptr->enum_val > b_ptr->enum_val)
                    result = 1;
        }
        return result;
    }
} /* end local_Compare_FACC_Enum_Mapping */

int
local_FACC_Compare_Features
(
    const FACC_2p1_Feature_Code *a_ptr,
    const FACC_2p1_Feature_Code *b_ptr
)
{
    EDCS_Count i;
    int      result = 0;
    char     c1, c2;

    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;

    i = 0;
    while ((result==0) && (i < 5))
    {
        c1 = (char) toupper(a_ptr->tag[i]);
        c2 = (char) toupper(b_ptr->tag[i]);
        if (c1 < c2)
            result = -1;
        else if (c1 > c2)
            result = 1;
        i++;
    }
    return result;
} /* end local_FACC_Compare_Features */

int
local_CompareFeature_Mapping
(
    const EDCS_FACC_2p1_Class_Mapping *a_ptr,
    const EDCS_FACC_2p1_Class_Mapping *b_ptr
)
{
    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;
    else
        return local_FACC_Compare_Features( &(a_ptr->code), &(b_ptr->code) );
}

static EDCS_Status_Code
local_init_facc_feature_mapping( void )
{
    EDCS_Status_Code    status = EDCS_SC_SUCCESS;
    EDCS_Mapping_Entry *temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[0].code.tag, "AA010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[0].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[0].entry.ec_code = ECC_EXTRACTION_MINE;
    EDCS_FACC_2p1_Class_Mapping_Array[0].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[0].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[0].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[1].code.tag, "AA011", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[1].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[1].entry.ec_code = ECC_SHEAR_WALL;
    EDCS_FACC_2p1_Class_Mapping_Array[1].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[1].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[1].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[2].code.tag, "AA012", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[2].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[2].entry.ec_code = ECC_QUARRY;
    EDCS_FACC_2p1_Class_Mapping_Array[2].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[2].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[2].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[3].code.tag, "AA013", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[3].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[3].entry.ec_code = ECC_TERRAIN_PIT;
    EDCS_FACC_2p1_Class_Mapping_Array[3].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[3].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[3].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[4].code.tag, "AA040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[4].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[4].entry.ec_code = ECC_RIG;
    EDCS_FACC_2p1_Class_Mapping_Array[4].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[4].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[4].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[5].code.tag, "AA050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[5].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[5].entry.ec_code = ECC_WELL;
    EDCS_FACC_2p1_Class_Mapping_Array[5].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[5].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[5].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[6].code.tag, "AA051", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[6].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[6].entry.ec_code = ECC_WELL_HEAD;
    EDCS_FACC_2p1_Class_Mapping_Array[6].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[6].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[6].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[7].code.tag, "AA052", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[7].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[7].entry.ec_code = ECC_PETROLEUM_FIELD;
    EDCS_FACC_2p1_Class_Mapping_Array[7].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[7].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[7].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[8].code.tag, "AA060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[8].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[8].entry.ec_code = ECC_GRADATION_WORKS;
    EDCS_FACC_2p1_Class_Mapping_Array[8].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[8].entry.information = "Note that \"trestle covered with twigs\" corresponds to the more general <STRUCTURE>; consequently, while \"Gradation Works\" maps 1-1 to <GRADATION_WORKS>, the converse may not be true if the structure is not precisely that for which \"Gradation Works\" is defined.";
    EDCS_FACC_2p1_Class_Mapping_Array[8].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[9].code.tag, "AB000", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[9].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[9].entry.ec_code = ECC_DISPOSAL_SITE;
    EDCS_FACC_2p1_Class_Mapping_Array[9].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[9].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[9].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[10].code.tag, "AB010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[10].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[10].entry.ec_code = ECC_RECYCLING_SITE;
    EDCS_FACC_2p1_Class_Mapping_Array[10].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[10].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[10].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[11].code.tag, "AB020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[11].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[11].entry.ec_code = ECC_INCINERATOR;
    EDCS_FACC_2p1_Class_Mapping_Array[11].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[11].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[11].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[12].code.tag, "AB021", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[12].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[12].entry.ec_code = ECC_LIQUID_DIFFUSER;
    EDCS_FACC_2p1_Class_Mapping_Array[12].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[12].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[12].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[13].code.tag, "AB030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[13].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[13].entry.ec_code = ECC_WASTE_PROCESSING_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[13].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[13].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[13].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[14].code.tag, "AC000", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[14].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[14].entry.ec_code = ECC_PROCESSING_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[14].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[14].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[14].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[15].code.tag, "AC010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[15].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[15].entry.ec_code = ECC_BLAST_FURNACE;
    EDCS_FACC_2p1_Class_Mapping_Array[15].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[15].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[15].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[16].code.tag, "AC020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[16].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[16].entry.ec_code = ECC_CATALYTIC_CRACKER;
    EDCS_FACC_2p1_Class_Mapping_Array[16].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[16].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[16].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[17].code.tag, "AC030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[17].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[17].entry.ec_code = ECC_SETTLING_POND;
    EDCS_FACC_2p1_Class_Mapping_Array[17].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[17].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[17].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[18].code.tag, "AC040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[18].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[18].entry.ec_code = ECC_PETROLEUM_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[18].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[18].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[18].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[19].code.tag, "AC050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[19].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[19].entry.ec_code = ECC_INDUSTRIAL_WORKS;
    EDCS_FACC_2p1_Class_Mapping_Array[19].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[19].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[19].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[20].code.tag, "AD010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[20].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[20].entry.ec_code = ECC_POWER_PLANT;
    EDCS_FACC_2p1_Class_Mapping_Array[20].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[20].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[20].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[21].code.tag, "AD020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[21].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[21].entry.ec_code = ECC_SOLAR_PANEL;
    EDCS_FACC_2p1_Class_Mapping_Array[21].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[21].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[21].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[22].code.tag, "AD030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[22].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[22].entry.ec_code = ECC_POWER_SUBSTATION;
    EDCS_FACC_2p1_Class_Mapping_Array[22].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[22].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[22].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[23].code.tag, "AD040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[23].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[23].entry.ec_code = ECC_NUCLEAR_REACTOR;
    EDCS_FACC_2p1_Class_Mapping_Array[23].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[23].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[23].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[24].code.tag, "AD050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[24].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[24].entry.ec_code = ECC_HEATING_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[24].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[24].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[24].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[25].code.tag, "AE010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[25].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[25].entry.ec_code = ECC_ASSEMBLY_PLANT;
    EDCS_FACC_2p1_Class_Mapping_Array[25].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[25].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[25].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[26].code.tag, "AF010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[26].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[26].entry.ec_code = ECC_COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE;
    EDCS_FACC_2p1_Class_Mapping_Array[26].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[26].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[26].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[27].code.tag, "AF020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[27].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[27].entry.ec_code = ECC_CONVEYOR;
    EDCS_FACC_2p1_Class_Mapping_Array[27].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[27].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[27].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[28].code.tag, "AF021", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[28].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[28].entry.ec_code = ECC_BUCKET_ELEVATOR;
    EDCS_FACC_2p1_Class_Mapping_Array[28].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[28].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[28].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[29].code.tag, "AF030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[29].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[29].entry.ec_code = ECC_COOLING_TOWER;
    EDCS_FACC_2p1_Class_Mapping_Array[29].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[29].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[29].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[30].code.tag, "AF040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[30].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[30].entry.ec_code = ECC_CRANE;
    EDCS_FACC_2p1_Class_Mapping_Array[30].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[30].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[30].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[31].code.tag, "AF041", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[31].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[31].entry.ec_code = ECC_SHEERLEGS;
    EDCS_FACC_2p1_Class_Mapping_Array[31].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[31].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[31].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[32].code.tag, "AF050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[32].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[32].entry.ec_code = ECC_EXCAVATING_MACHINE;
    EDCS_FACC_2p1_Class_Mapping_Array[32].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[32].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[32].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[33].code.tag, "AF060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[33].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[33].entry.ec_code = ECC_ENGINE_TEST_CELL;
    EDCS_FACC_2p1_Class_Mapping_Array[33].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[33].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[33].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[34].code.tag, "AF070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[34].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[34].entry.ec_code = ECC_FLARE_PIPE;
    EDCS_FACC_2p1_Class_Mapping_Array[34].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[34].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[34].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[35].code.tag, "AF080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[35].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[35].entry.ec_code = ECC_HOPPER;
    EDCS_FACC_2p1_Class_Mapping_Array[35].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[35].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[35].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[36].code.tag, "AH010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[36].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[36].entry.ec_code = ECC_RAMPART;
    EDCS_FACC_2p1_Class_Mapping_Array[36].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[36].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[36].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[37].code.tag, "AH020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[37].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[37].entry.ec_code = ECC_MILITARY_TRENCH;
    EDCS_FACC_2p1_Class_Mapping_Array[37].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[37].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[37].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[38].code.tag, "AH050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[38].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[38].entry.ec_code = ECC_FORTIFICATION;
    EDCS_FACC_2p1_Class_Mapping_Array[38].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[38].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[38].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[39].code.tag, "AH060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[39].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[39].entry.ec_code = ECC_UNDERGROUND_BUNKER;
    EDCS_FACC_2p1_Class_Mapping_Array[39].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[39].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[39].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[40].code.tag, "AH070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[40].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[40].entry.ec_code = ECC_CHECKPOINT;
    EDCS_FACC_2p1_Class_Mapping_Array[40].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[40].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[40].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[41].code.tag, "AI020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[41].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[41].entry.ec_code = ECC_MOBILE_HOME_PARK;
    EDCS_FACC_2p1_Class_Mapping_Array[41].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[41].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[41].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[42].code.tag, "AI030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[42].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[42].entry.ec_code = ECC_CAMP;
    EDCS_FACC_2p1_Class_Mapping_Array[42].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[42].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[42].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[43].code.tag, "AJ010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[43].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[43].entry.ec_code = ECC_CIRCULAR_IRRIGATION_SYSTEM;
    EDCS_FACC_2p1_Class_Mapping_Array[43].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[43].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[43].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[44].code.tag, "AJ020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[44].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[44].entry.ec_code = ECC_SIPHON;
    EDCS_FACC_2p1_Class_Mapping_Array[44].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[44].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[44].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[45].code.tag, "AJ030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[45].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[45].entry.ec_code = ECC_LIVESTOCK_PEN;
    EDCS_FACC_2p1_Class_Mapping_Array[45].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[45].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[45].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[46].code.tag, "AJ050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[46].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[46].entry.ec_code = ECC_WINDMILL;
    EDCS_FACC_2p1_Class_Mapping_Array[46].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[46].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[46].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[47].code.tag, "AJ051", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[47].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[47].entry.ec_code = ECC_WIND_MOTOR;
    EDCS_FACC_2p1_Class_Mapping_Array[47].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[47].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[47].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[48].code.tag, "AK020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[48].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[48].entry.ec_code = ECC_AMUSEMENT_PARK_ATTRACTION;
    EDCS_FACC_2p1_Class_Mapping_Array[48].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[48].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[48].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[49].code.tag, "AK030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[49].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[49].entry.ec_code = ECC_AMUSEMENT_PARK;
    EDCS_FACC_2p1_Class_Mapping_Array[49].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[49].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[49].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[50].code.tag, "AK040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[50].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[50].entry.ec_code = ECC_ATHLETIC_FIELD;
    EDCS_FACC_2p1_Class_Mapping_Array[50].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[50].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[50].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[51].code.tag, "AK050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[51].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[51].entry.ec_code = ECC_TENNIS_COMPLEX;
    EDCS_FACC_2p1_Class_Mapping_Array[51].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[51].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[51].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[52].code.tag, "AK060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[52].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[52].entry.ec_code = ECC_CAMPGROUND;
    EDCS_FACC_2p1_Class_Mapping_Array[52].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[52].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[52].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[53].code.tag, "AK061", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[53].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[53].entry.ec_code = ECC_PICNIC_TRACT;
    EDCS_FACC_2p1_Class_Mapping_Array[53].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[53].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[53].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[54].code.tag, "AK070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[54].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[54].entry.ec_code = ECC_DRIVE_IN_THEATRE;
    EDCS_FACC_2p1_Class_Mapping_Array[54].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[54].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[54].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[55].code.tag, "AK080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[55].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[55].entry.ec_code = ECC_DRIVE_IN_THEATRE_SCREEN;
    EDCS_FACC_2p1_Class_Mapping_Array[55].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[55].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[55].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[56].code.tag, "AK090", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[56].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[56].entry.ec_code = ECC_FAIRGROUND;
    EDCS_FACC_2p1_Class_Mapping_Array[56].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[56].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[56].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[57].code.tag, "AK091", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[57].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[57].entry.ec_code = ECC_EXHIBITION_GROUND;
    EDCS_FACC_2p1_Class_Mapping_Array[57].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[57].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[57].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[58].code.tag, "AK100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[58].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[58].entry.ec_code = ECC_GOLF_COURSE;
    EDCS_FACC_2p1_Class_Mapping_Array[58].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[58].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[58].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[59].code.tag, "AK101", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[59].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[59].entry.ec_code = ECC_GOLF_DRIVING_RANGE;
    EDCS_FACC_2p1_Class_Mapping_Array[59].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[59].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[59].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[60].code.tag, "AK110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[60].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[60].entry.ec_code = ECC_GRANDSTAND;
    EDCS_FACC_2p1_Class_Mapping_Array[60].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[60].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[60].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[61].code.tag, "AK120", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[61].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[61].entry.ec_code = ECC_PARK;
    EDCS_FACC_2p1_Class_Mapping_Array[61].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[61].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[61].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[62].code.tag, "AK121", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[62].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[62].entry.ec_code = ECC_SCENIC_LOOKOUT;
    EDCS_FACC_2p1_Class_Mapping_Array[62].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[62].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[62].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[63].code.tag, "AK122", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[63].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[63].entry.ec_code = ECC_GREEN_SPACE;
    EDCS_FACC_2p1_Class_Mapping_Array[63].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[63].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[63].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[64].code.tag, "AK130", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[64].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[64].entry.ec_code = ECC_RACE_TRACK;
    EDCS_FACC_2p1_Class_Mapping_Array[64].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[64].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[64].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[65].code.tag, "AK150", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[65].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[65].entry.ec_code = ECC_SKI_JUMP;
    EDCS_FACC_2p1_Class_Mapping_Array[65].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[65].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[65].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[66].code.tag, "AK155", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[66].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[66].entry.ec_code = ECC_SKI_TRACK;
    EDCS_FACC_2p1_Class_Mapping_Array[66].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[66].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[66].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[67].code.tag, "AK160", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[67].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[67].entry.ec_code = ECC_SPORTS_ARENA;
    EDCS_FACC_2p1_Class_Mapping_Array[67].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[67].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[67].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[68].code.tag, "AK170", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[68].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[68].entry.ec_code = ECC_SWIMMING_POOL;
    EDCS_FACC_2p1_Class_Mapping_Array[68].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[68].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[68].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[69].code.tag, "AK180", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[69].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[69].entry.ec_code = ECC_ANIMAL_PARK;
    EDCS_FACC_2p1_Class_Mapping_Array[69].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[69].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[69].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[70].code.tag, "AK190", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[70].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[70].entry.ec_code = ECC_RECREATIONAL_PIER;
    EDCS_FACC_2p1_Class_Mapping_Array[70].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[70].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[70].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[71].code.tag, "AL005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[71].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[71].entry.ec_code = ECC_ANIMAL_SANCTUARY;
    EDCS_FACC_2p1_Class_Mapping_Array[71].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[71].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[71].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[72].code.tag, "AL012", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[72].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[72].entry.ec_code = ECC_ARCHAELOGICAL_SITE;
    EDCS_FACC_2p1_Class_Mapping_Array[72].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[72].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[72].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[73].code.tag, "AL015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[73].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[73].entry.ec_code = ECC_BUILDING;
    EDCS_FACC_2p1_Class_Mapping_Array[73].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[73].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[73].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[74].code.tag, "AL018", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[74].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[74].entry.ec_code = ECC_BUILDING_SUPERSTRUCTURE;
    EDCS_FACC_2p1_Class_Mapping_Array[74].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[74].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[74].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[75].code.tag, "AL019", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[75].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[75].entry.ec_code = ECC_SHED;
    EDCS_FACC_2p1_Class_Mapping_Array[75].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[75].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[75].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[76].code.tag, "AL020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[76].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[76].entry.ec_code = ECC_BUILT_UP_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[76].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[76].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[76].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[77].code.tag, "AL021", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[77].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[77].entry.ec_code = ECC_HISTORICAL_BUILT_UP_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[77].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[77].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[77].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[78].code.tag, "AL025", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[78].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[78].entry.ec_code = ECC_CAIRN;
    EDCS_FACC_2p1_Class_Mapping_Array[78].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[78].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[78].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[79].code.tag, "AL030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[79].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[79].entry.ec_code = ECC_CEMETERY;
    EDCS_FACC_2p1_Class_Mapping_Array[79].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[79].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[79].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[80].code.tag, "AL040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[80].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[80].entry.ec_code = ECC_CLIFF_DWELLING;
    EDCS_FACC_2p1_Class_Mapping_Array[80].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[80].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[80].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[81].code.tag, "AL045", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[81].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[81].entry.ec_code = ECC_COMPLEX_OUTLINE;
    EDCS_FACC_2p1_Class_Mapping_Array[81].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[81].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[81].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[82].code.tag, "AL050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[82].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[82].entry.ec_code = ECC_DISPLAY_SIGN;
    EDCS_FACC_2p1_Class_Mapping_Array[82].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[82].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[82].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[83].code.tag, "AL060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[83].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[83].entry.ec_code = ECC_DRAGON_TEETH;
    EDCS_FACC_2p1_Class_Mapping_Array[83].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[83].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[83].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[84].code.tag, "AL070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[84].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[84].entry.ec_code = ECC_FENCE;
    EDCS_FACC_2p1_Class_Mapping_Array[84].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[84].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[84].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[85].code.tag, "AL073", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[85].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[85].entry.ec_code = ECC_FLAGPOLE;
    EDCS_FACC_2p1_Class_Mapping_Array[85].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[85].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[85].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[86].code.tag, "AL075", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[86].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[86].entry.ec_code = ECC_TERRAIN_TRANSPORTATION_GALLERY;
    EDCS_FACC_2p1_Class_Mapping_Array[86].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[86].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[86].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[87].code.tag, "AL080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[87].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[87].entry.ec_code = ECC_GANTRY;
    EDCS_FACC_2p1_Class_Mapping_Array[87].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[87].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[87].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[88].code.tag, "AL090", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[88].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[88].entry.ec_code = ECC_GRAVE_MARKER;
    EDCS_FACC_2p1_Class_Mapping_Array[88].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[88].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[88].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[89].code.tag, "AL100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[89].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[89].entry.ec_code = ECC_HUT;
    EDCS_FACC_2p1_Class_Mapping_Array[89].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[89].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[89].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[90].code.tag, "AL101", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[90].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[90].entry.ec_code = ECC_CABIN;
    EDCS_FACC_2p1_Class_Mapping_Array[90].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[90].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[90].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[91].code.tag, "AL105", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[91].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[91].entry.ec_code = ECC_SETTLEMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[91].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[91].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[91].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[92].code.tag, "AL110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[92].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[92].entry.ec_code = ECC_LIGHT_SUPPORT_STRUCTURE;
    EDCS_FACC_2p1_Class_Mapping_Array[92].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[92].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[92].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[93].code.tag, "AL116", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[93].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[93].entry.ec_code = ECC_CALVARY_CROSS;
    EDCS_FACC_2p1_Class_Mapping_Array[93].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[93].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[93].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[94].code.tag, "AL120", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[94].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[94].entry.ec_code = ECC_MISSILE_SITE;
    EDCS_FACC_2p1_Class_Mapping_Array[94].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[94].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[94].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[95].code.tag, "AL130", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[95].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[95].entry.ec_code = ECC_MEMORIAL_MONUMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[95].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[95].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[95].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[96].code.tag, "AL135", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[96].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[96].entry.ec_code = ECC_TRADITIONAL_SETTLEMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[96].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[96].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[96].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[97].code.tag, "AL140", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[97].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[97].entry.ec_code = ECC_PARTICLE_ACCELERATOR;
    EDCS_FACC_2p1_Class_Mapping_Array[97].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[97].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[97].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[98].code.tag, "AL141", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[98].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[98].entry.ec_code = ECC_TELESCOPE;
    EDCS_FACC_2p1_Class_Mapping_Array[98].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[98].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[98].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[99].code.tag, "AL155", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[99].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[99].entry.ec_code = ECC_OVERHEAD_OBSTRUCTION;
    EDCS_FACC_2p1_Class_Mapping_Array[99].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[99].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[99].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[100].code.tag, "AL170", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[100].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[100].entry.ec_code = ECC_PUBLIC_SQUARE;
    EDCS_FACC_2p1_Class_Mapping_Array[100].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[100].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[100].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[101].code.tag, "AL195", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[101].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[101].entry.ec_code = ECC_RAMP;
    EDCS_FACC_2p1_Class_Mapping_Array[101].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[101].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[101].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[102].code.tag, "AL200", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[102].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[102].entry.ec_code = ECC_RUINS;
    EDCS_FACC_2p1_Class_Mapping_Array[102].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[102].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[102].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[103].code.tag, "AL201", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[103].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[103].entry.ec_code = ECC_INTEREST_SITE;
    EDCS_FACC_2p1_Class_Mapping_Array[103].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[103].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[103].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[104].code.tag, "AL210", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[104].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[104].entry.ec_code = ECC_PROTECTION_SHED;
    EDCS_FACC_2p1_Class_Mapping_Array[104].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[104].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[104].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[105].code.tag, "AL220", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[105].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[105].entry.ec_code = ECC_STEEPLE;
    EDCS_FACC_2p1_Class_Mapping_Array[105].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[105].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[105].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[106].code.tag, "AL240", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[106].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[106].entry.ec_code = ECC_NON_COMMUNICATION_TOWER;
    EDCS_FACC_2p1_Class_Mapping_Array[106].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[106].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[106].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[107].code.tag, "AL241", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[107].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[107].entry.ec_code = ECC_TOWER;
    EDCS_FACC_2p1_Class_Mapping_Array[107].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[107].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[107].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[108].code.tag, "AL250", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[108].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[108].entry.ec_code = ECC_UNDERGROUND_DWELLING;
    EDCS_FACC_2p1_Class_Mapping_Array[108].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[108].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[108].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[109].code.tag, "AL260", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[109].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[109].entry.ec_code = ECC_WALL;
    EDCS_FACC_2p1_Class_Mapping_Array[109].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[109].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[109].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[110].code.tag, "AM010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[110].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[110].entry.ec_code = ECC_STORAGE_DEPOT;
    EDCS_FACC_2p1_Class_Mapping_Array[110].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[110].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[110].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[111].code.tag, "AM011", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[111].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[111].entry.ec_code = ECC_STORAGE_CONTAINER;
    EDCS_FACC_2p1_Class_Mapping_Array[111].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[111].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[111].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[112].code.tag, "AM020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[112].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[112].entry.ec_code = ECC_GRAIN_STORAGE_STRUCTURE;
    EDCS_FACC_2p1_Class_Mapping_Array[112].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[112].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[112].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[113].code.tag, "AM030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[113].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[113].entry.ec_code = ECC_GRAIN_ELEVATOR;
    EDCS_FACC_2p1_Class_Mapping_Array[113].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[113].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[113].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[114].code.tag, "AM031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[114].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[114].entry.ec_code = ECC_TIMBER_YARD;
    EDCS_FACC_2p1_Class_Mapping_Array[114].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[114].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[114].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[115].code.tag, "AM040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[115].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[115].entry.ec_code = ECC_MINERAL_PILE;
    EDCS_FACC_2p1_Class_Mapping_Array[115].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[115].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[115].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[116].code.tag, "AM060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[116].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[116].entry.ec_code = ECC_STORAGE_BUNKER;
    EDCS_FACC_2p1_Class_Mapping_Array[116].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[116].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[116].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[117].code.tag, "AM070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[117].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[117].entry.ec_code = ECC_STORAGE_TANK;
    EDCS_FACC_2p1_Class_Mapping_Array[117].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[117].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[117].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[118].code.tag, "AM080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[118].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[118].entry.ec_code = ECC_WATER_TOWER;
    EDCS_FACC_2p1_Class_Mapping_Array[118].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[118].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[118].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[119].code.tag, "AN010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[119].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[119].entry.ec_code = ECC_RAILWAY_TRACK;
    EDCS_FACC_2p1_Class_Mapping_Array[119].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[119].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[119].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[120].code.tag, "AN050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[120].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[120].entry.ec_code = ECC_RAILWAY_SIDETRACK;
    EDCS_FACC_2p1_Class_Mapping_Array[120].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[120].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[120].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[121].code.tag, "AN060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[121].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[121].entry.ec_code = ECC_RAILWAY_YARD;
    EDCS_FACC_2p1_Class_Mapping_Array[121].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[121].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[121].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[122].code.tag, "AN065", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[122].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[122].entry.ec_code = ECC_RAIL_HEAD;
    EDCS_FACC_2p1_Class_Mapping_Array[122].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[122].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[122].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[123].code.tag, "AN075", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[123].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[123].entry.ec_code = ECC_RAILWAY_TURNTABLE;
    EDCS_FACC_2p1_Class_Mapping_Array[123].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[123].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[123].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[124].code.tag, "AN080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[124].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[124].entry.ec_code = ECC_RAILWAY_SWITCH;
    EDCS_FACC_2p1_Class_Mapping_Array[124].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[124].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[124].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[125].code.tag, "AP010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[125].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[125].entry.ec_code = ECC_CART_TRACK;
    EDCS_FACC_2p1_Class_Mapping_Array[125].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[125].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[125].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[126].code.tag, "AP020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[126].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[126].entry.ec_code = ECC_ROAD_INTERCHANGE;
    EDCS_FACC_2p1_Class_Mapping_Array[126].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[126].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[126].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[127].code.tag, "AP030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[127].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[127].entry.ec_code = ECC_ROAD;
    EDCS_FACC_2p1_Class_Mapping_Array[127].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[127].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[127].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[128].code.tag, "AP040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[128].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[128].entry.ec_code = ECC_GATE;
    EDCS_FACC_2p1_Class_Mapping_Array[128].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[128].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[128].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[129].code.tag, "AP041", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[129].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[129].entry.ec_code = ECC_VEHICLE_BARRIER;
    EDCS_FACC_2p1_Class_Mapping_Array[129].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[129].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[129].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[130].code.tag, "AP050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[130].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[130].entry.ec_code = ECC_TRAIL;
    EDCS_FACC_2p1_Class_Mapping_Array[130].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[130].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[130].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[131].code.tag, "AP060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[131].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[131].entry.ec_code = ECC_DROVE;
    EDCS_FACC_2p1_Class_Mapping_Array[131].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[131].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[131].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[132].code.tag, "AQ010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[132].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[132].entry.ec_code = ECC_AERIAL_CABLE;
    EDCS_FACC_2p1_Class_Mapping_Array[132].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[132].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[132].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[133].code.tag, "AQ020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[133].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[133].entry.ec_code = ECC_AERIAL_CABLE_PYLON;
    EDCS_FACC_2p1_Class_Mapping_Array[133].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[133].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[133].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[134].code.tag, "AQ021", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[134].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[134].entry.ec_code = ECC_MAST;
    EDCS_FACC_2p1_Class_Mapping_Array[134].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[134].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[134].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[135].code.tag, "AQ030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[135].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[135].entry.ec_code = ECC_BOARDWALK;
    EDCS_FACC_2p1_Class_Mapping_Array[135].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[135].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[135].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[136].code.tag, "AQ040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[136].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[136].entry.ec_code = ECC_BRIDGE;
    EDCS_FACC_2p1_Class_Mapping_Array[136].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[136].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[136].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[137].code.tag, "AQ045", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[137].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[137].entry.ec_code = ECC_BRIDGE_SPAN;
    EDCS_FACC_2p1_Class_Mapping_Array[137].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[137].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[137].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[138].code.tag, "AQ050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[138].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[138].entry.ec_code = ECC_BRIDGE_SUPERSTRUCTURE;
    EDCS_FACC_2p1_Class_Mapping_Array[138].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[138].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[138].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[139].code.tag, "AQ055", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[139].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[139].entry.ec_code = ECC_BRIDGE_TOWER;
    EDCS_FACC_2p1_Class_Mapping_Array[139].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[139].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[139].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[140].code.tag, "AQ056", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[140].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[140].entry.ec_code = ECC_BRIDGE_PIER;
    EDCS_FACC_2p1_Class_Mapping_Array[140].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[140].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[140].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[141].code.tag, "AQ058", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[141].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[141].entry.ec_code = ECC_ROUTE_WIDTH_CHANGE;
    EDCS_FACC_2p1_Class_Mapping_Array[141].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[141].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[141].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[142].code.tag, "AQ060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[142].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[142].entry.ec_code = ECC_CONTROL_TOWER;
    EDCS_FACC_2p1_Class_Mapping_Array[142].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[142].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[142].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[143].code.tag, "AQ062", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[143].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[143].entry.ec_code = ECC_CROSSING;
    EDCS_FACC_2p1_Class_Mapping_Array[143].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[143].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[143].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[144].code.tag, "AQ064", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[144].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[144].entry.ec_code = ECC_CAUSEWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[144].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[144].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[144].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[145].code.tag, "AQ065", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[145].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[145].entry.ec_code = ECC_CULVERT;
    EDCS_FACC_2p1_Class_Mapping_Array[145].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[145].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[145].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[146].code.tag, "AQ068", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[146].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[146].entry.ec_code = ECC_TRANSPORTATION_BLOCK;
    EDCS_FACC_2p1_Class_Mapping_Array[146].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[146].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[146].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[147].code.tag, "AQ070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[147].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[147].entry.ec_code = ECC_FERRY_CROSSING;
    EDCS_FACC_2p1_Class_Mapping_Array[147].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[147].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[147].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[148].code.tag, "AQ080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[148].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[148].entry.ec_code = ECC_FERRY_LOCATION;
    EDCS_FACC_2p1_Class_Mapping_Array[148].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[148].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[148].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[149].code.tag, "AQ090", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[149].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[149].entry.ec_code = ECC_STRUCTURE_ENTRANCE_AND_OR_EXIT;
    EDCS_FACC_2p1_Class_Mapping_Array[149].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[149].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[149].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[150].code.tag, "AQ100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[150].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[150].entry.ec_code = ECC_DISTANCE_POST;
    EDCS_FACC_2p1_Class_Mapping_Array[150].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[150].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[150].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[151].code.tag, "AQ110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[151].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[151].entry.ec_code = ECC_MOORING_MAST;
    EDCS_FACC_2p1_Class_Mapping_Array[151].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[151].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[151].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[152].code.tag, "AQ111", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[152].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[152].entry.ec_code = ECC_PREPARED_WATERCOURSE_CROSSING;
    EDCS_FACC_2p1_Class_Mapping_Array[152].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[152].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[152].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[153].code.tag, "AQ113", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[153].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[153].entry.ec_code = ECC_PIPELINE;
    EDCS_FACC_2p1_Class_Mapping_Array[153].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[153].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[153].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[154].code.tag, "AQ116", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[154].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[154].entry.ec_code = ECC_PUMPING_STATION;
    EDCS_FACC_2p1_Class_Mapping_Array[154].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[154].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[154].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[155].code.tag, "AQ118", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[155].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[155].entry.ec_code = ECC_SHARP_CURVE;
    EDCS_FACC_2p1_Class_Mapping_Array[155].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[155].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[155].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[156].code.tag, "AQ119", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[156].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[156].entry.ec_code = ECC_ROAD_ROUTE_MARKER;
    EDCS_FACC_2p1_Class_Mapping_Array[156].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[156].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[156].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[157].code.tag, "AQ120", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[157].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[157].entry.ec_code = ECC_STEEP_GRADE;
    EDCS_FACC_2p1_Class_Mapping_Array[157].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[157].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[157].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[158].code.tag, "AQ125", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[158].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[158].entry.ec_code = ECC_TRANSPORTATION_STATION;
    EDCS_FACC_2p1_Class_Mapping_Array[158].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[158].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[158].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[159].code.tag, "AQ130", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[159].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[159].entry.ec_code = ECC_TUNNEL;
    EDCS_FACC_2p1_Class_Mapping_Array[159].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[159].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[159].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[160].code.tag, "AQ135", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[160].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[160].entry.ec_code = ECC_ROADSIDE_REST_STOP;
    EDCS_FACC_2p1_Class_Mapping_Array[160].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[160].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[160].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[161].code.tag, "AQ140", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[161].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[161].entry.ec_code = ECC_VEHICLE_LOT;
    EDCS_FACC_2p1_Class_Mapping_Array[161].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[161].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[161].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[162].code.tag, "AQ150", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[162].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[162].entry.ec_code = ECC_STAIR;
    EDCS_FACC_2p1_Class_Mapping_Array[162].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[162].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[162].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[163].code.tag, "AQ151", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[163].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[163].entry.ec_code = ECC_ARCADE;
    EDCS_FACC_2p1_Class_Mapping_Array[163].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[163].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[163].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[164].code.tag, "AT005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[164].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[164].entry.ec_code = ECC_ELECTRICAL_CABLE;
    EDCS_FACC_2p1_Class_Mapping_Array[164].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[164].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[164].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[165].code.tag, "AT006", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[165].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[165].entry.ec_code = ECC_ELEVATED_ELECTRICAL_CABLE;
    EDCS_FACC_2p1_Class_Mapping_Array[165].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[165].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[165].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[166].code.tag, "AT010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[166].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[166].entry.ec_code = ECC_DISH_AERIAL;
    EDCS_FACC_2p1_Class_Mapping_Array[166].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[166].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[166].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[167].code.tag, "AT020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[167].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[167].entry.ec_code = ECC_EARLY_WARNING_RADAR_SITE;
    EDCS_FACC_2p1_Class_Mapping_Array[167].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[167].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[167].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[168].code.tag, "AT030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[168].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[168].entry.ec_code = ECC_POWER_TRANSMISSION_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[168].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[168].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[168].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[169].code.tag, "AT040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[169].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[169].entry.ec_code = ECC_POWER_TRANSMISSION_LINE_PYLON;
    EDCS_FACC_2p1_Class_Mapping_Array[169].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[169].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[169].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[170].code.tag, "AT041", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[170].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[170].entry.ec_code = ECC_TELEFERIC;
    EDCS_FACC_2p1_Class_Mapping_Array[170].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[170].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[170].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[171].code.tag, "AT045", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[171].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[171].entry.ec_code = ECC_RADAR_DEVICE;
    EDCS_FACC_2p1_Class_Mapping_Array[171].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[171].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[171].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[172].code.tag, "AT050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[172].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[172].entry.ec_code = ECC_COMMUNICATION_STATION;
    EDCS_FACC_2p1_Class_Mapping_Array[172].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[172].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[172].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[173].code.tag, "AT060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[173].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[173].entry.ec_code = ECC_ELECTRICAL_SIGNAL_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[173].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[173].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[173].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[174].code.tag, "AT070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[174].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[174].entry.ec_code = ECC_ELECTRICAL_SIGNAL_LINE_PYLON;
    EDCS_FACC_2p1_Class_Mapping_Array[174].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[174].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[174].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[175].code.tag, "AT080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[175].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[175].entry.ec_code = ECC_COMMUNICATION_TOWER;
    EDCS_FACC_2p1_Class_Mapping_Array[175].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[175].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[175].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[176].code.tag, "BA010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[176].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[176].entry.ec_code = ECC_LAND_WATER_BOUNDARY;
    EDCS_FACC_2p1_Class_Mapping_Array[176].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[176].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[176].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[177].code.tag, "BA011", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[177].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[177].entry.ec_code = ECC_COASTLINE;
    EDCS_FACC_2p1_Class_Mapping_Array[177].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[177].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[177].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[178].code.tag, "BA020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[178].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[178].entry.ec_code = ECC_FORESHORE;
    EDCS_FACC_2p1_Class_Mapping_Array[178].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[178].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[178].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[179].code.tag, "BA021", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[179].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[179].entry.ec_code = ECC_NEARSHORE_PRECISE;
    EDCS_FACC_2p1_Class_Mapping_Array[179].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[179].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[179].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[180].code.tag, "BA022", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[180].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[180].entry.ec_code = ECC_BACKSHORE_PRECISE;
    EDCS_FACC_2p1_Class_Mapping_Array[180].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[180].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[180].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[181].code.tag, "BA023", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[181].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[181].entry.ec_code = ECC_FORESHORE_PRECISE;
    EDCS_FACC_2p1_Class_Mapping_Array[181].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[181].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[181].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[182].code.tag, "BA024", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[182].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[182].entry.ec_code = ECC_SHORELINE;
    EDCS_FACC_2p1_Class_Mapping_Array[182].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[182].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[182].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[183].code.tag, "BA030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[183].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[183].entry.ec_code = ECC_ISLAND;
    EDCS_FACC_2p1_Class_Mapping_Array[183].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[183].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[183].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[184].code.tag, "BA040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[184].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[184].entry.ec_code = ECC_TIDAL_WATER;
    EDCS_FACC_2p1_Class_Mapping_Array[184].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[184].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[184].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[185].code.tag, "BA050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[185].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[185].entry.ec_code = ECC_BEACH;
    EDCS_FACC_2p1_Class_Mapping_Array[185].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[185].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[185].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[186].code.tag, "BA051", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[186].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[186].entry.ec_code = ECC_DYKE_TOP;
    EDCS_FACC_2p1_Class_Mapping_Array[186].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[186].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[186].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[187].code.tag, "BB005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[187].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[187].entry.ec_code = ECC_HARBOUR;
    EDCS_FACC_2p1_Class_Mapping_Array[187].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[187].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[187].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[188].code.tag, "BB006", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[188].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[188].entry.ec_code = ECC_HARBOUR_COMPLEX;
    EDCS_FACC_2p1_Class_Mapping_Array[188].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[188].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[188].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[189].code.tag, "BB007", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[189].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[189].entry.ec_code = ECC_WATER_CHANNEL_EDGE;
    EDCS_FACC_2p1_Class_Mapping_Array[189].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[189].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[189].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[190].code.tag, "BB010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[190].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[190].entry.ec_code = ECC_ANCHORAGE;
    EDCS_FACC_2p1_Class_Mapping_Array[190].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[190].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[190].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[191].code.tag, "BB011", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[191].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[191].entry.ec_code = ECC_ANCHORAGE_COMPLEX;
    EDCS_FACC_2p1_Class_Mapping_Array[191].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[191].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[191].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[192].code.tag, "BB012", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[192].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[192].entry.ec_code = ECC_ANCHOR_BERTH;
    EDCS_FACC_2p1_Class_Mapping_Array[192].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[192].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[192].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[193].code.tag, "BB019", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[193].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[193].entry.ec_code = ECC_ANCHOR;
    EDCS_FACC_2p1_Class_Mapping_Array[193].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[193].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[193].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[194].code.tag, "BB020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[194].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[194].entry.ec_code = ECC_VESSEL_BERTH;
    EDCS_FACC_2p1_Class_Mapping_Array[194].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[194].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[194].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[195].code.tag, "BB021", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[195].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[195].entry.ec_code = ECC_MOORING_TROT;
    EDCS_FACC_2p1_Class_Mapping_Array[195].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[195].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[195].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[196].code.tag, "BB022", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[196].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[196].entry.ec_code = ECC_VESSEL_BASIN;
    EDCS_FACC_2p1_Class_Mapping_Array[196].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[196].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[196].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[197].code.tag, "BB030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[197].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[197].entry.ec_code = ECC_BOLLARD;
    EDCS_FACC_2p1_Class_Mapping_Array[197].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[197].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[197].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[198].code.tag, "BB040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[198].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[198].entry.ec_code = ECC_SHORE_PROTECTION_STRUCTURE;
    EDCS_FACC_2p1_Class_Mapping_Array[198].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[198].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[198].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[199].code.tag, "BB041", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[199].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[199].entry.ec_code = ECC_BREAKWATER;
    EDCS_FACC_2p1_Class_Mapping_Array[199].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[199].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[199].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[200].code.tag, "BB042", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[200].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[200].entry.ec_code = ECC_MARINE_MOLE;
    EDCS_FACC_2p1_Class_Mapping_Array[200].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[200].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[200].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[201].code.tag, "BB043", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[201].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[201].entry.ec_code = ECC_GROIN;
    EDCS_FACC_2p1_Class_Mapping_Array[201].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[201].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[201].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[202].code.tag, "BB050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[202].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[202].entry.ec_code = ECC_CALLING_IN_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[202].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[202].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[202].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[203].code.tag, "BB079", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[203].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[203].entry.ec_code = ECC_MOORING_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[203].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[203].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[203].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[204].code.tag, "BB080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[204].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[204].entry.ec_code = ECC_MOORING_DOLPHIN;
    EDCS_FACC_2p1_Class_Mapping_Array[204].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[204].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[204].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[205].code.tag, "BB081", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[205].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[205].entry.ec_code = ECC_SHORELINE_CONSTRUCTION;
    EDCS_FACC_2p1_Class_Mapping_Array[205].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[205].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[205].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[206].code.tag, "BB090", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[206].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[206].entry.ec_code = ECC_DRY_DOCK;
    EDCS_FACC_2p1_Class_Mapping_Array[206].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[206].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[206].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[207].code.tag, "BB100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[207].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[207].entry.ec_code = ECC_FISH_STAKE_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[207].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[207].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[207].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[208].code.tag, "BB105", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[208].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[208].entry.ec_code = ECC_FISHING_HARBOUR;
    EDCS_FACC_2p1_Class_Mapping_Array[208].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[208].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[208].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[209].code.tag, "BB110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[209].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[209].entry.ec_code = ECC_FISH_TRAP;
    EDCS_FACC_2p1_Class_Mapping_Array[209].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[209].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[209].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[210].code.tag, "BB111", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[210].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[210].entry.ec_code = ECC_TUNA_NETTING_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[210].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[210].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[210].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[211].code.tag, "BB115", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[211].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[211].entry.ec_code = ECC_MARINE_GRIDIRON;
    EDCS_FACC_2p1_Class_Mapping_Array[211].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[211].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[211].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[212].code.tag, "BB140", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[212].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[212].entry.ec_code = ECC_JETTY;
    EDCS_FACC_2p1_Class_Mapping_Array[212].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[212].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[212].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[213].code.tag, "BB150", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[213].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[213].entry.ec_code = ECC_SHORELINE_LANDING_PLACE;
    EDCS_FACC_2p1_Class_Mapping_Array[213].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[213].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[213].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[214].code.tag, "BB151", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[214].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[214].entry.ec_code = ECC_SHORELINE_LANDING_STAIR;
    EDCS_FACC_2p1_Class_Mapping_Array[214].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[214].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[214].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[215].code.tag, "BB155", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[215].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[215].entry.ec_code = ECC_MARINE_SIGNAL_STATION;
    EDCS_FACC_2p1_Class_Mapping_Array[215].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[215].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[215].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[216].code.tag, "BB160", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[216].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[216].entry.ec_code = ECC_MOORING_RING;
    EDCS_FACC_2p1_Class_Mapping_Array[216].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[216].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[216].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[217].code.tag, "BB170", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[217].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[217].entry.ec_code = ECC_OFFSHORE_LOADING_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[217].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[217].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[217].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[218].code.tag, "BB180", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[218].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[218].entry.ec_code = ECC_SHELLFISH_BED;
    EDCS_FACC_2p1_Class_Mapping_Array[218].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[218].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[218].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[219].code.tag, "BB190", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[219].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[219].entry.ec_code = ECC_WHARF;
    EDCS_FACC_2p1_Class_Mapping_Array[219].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[219].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[219].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[220].code.tag, "BB198", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[220].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[220].entry.ec_code = ECC_FENDER_CUSHION;
    EDCS_FACC_2p1_Class_Mapping_Array[220].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[220].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[220].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[221].code.tag, "BB199", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[221].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[221].entry.ec_code = ECC_FLOATING_DOCK;
    EDCS_FACC_2p1_Class_Mapping_Array[221].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[221].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[221].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[222].code.tag, "BB200", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[222].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[222].entry.ec_code = ECC_PUMP_OUT_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[222].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[222].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[222].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[223].code.tag, "BB201", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[223].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[223].entry.ec_code = ECC_SMALL_CRAFT_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[223].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[223].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[223].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[224].code.tag, "BB202", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[224].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[224].entry.ec_code = ECC_ICE_BOOM;
    EDCS_FACC_2p1_Class_Mapping_Array[224].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[224].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[224].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[225].code.tag, "BB220", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[225].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[225].entry.ec_code = ECC_MARINE_RAMP;
    EDCS_FACC_2p1_Class_Mapping_Array[225].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[225].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[225].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[226].code.tag, "BB221", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[226].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[226].entry.ec_code = ECC_LOG_RAMP;
    EDCS_FACC_2p1_Class_Mapping_Array[226].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[226].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[226].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[227].code.tag, "BB225", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[227].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[227].entry.ec_code = ECC_RIPRAP;
    EDCS_FACC_2p1_Class_Mapping_Array[227].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[227].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[227].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[228].code.tag, "BB226", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[228].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[228].entry.ec_code = ECC_SHORE_REVETMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[228].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[228].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[228].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[229].code.tag, "BB230", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[229].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[229].entry.ec_code = ECC_SEAWALL;
    EDCS_FACC_2p1_Class_Mapping_Array[229].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[229].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[229].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[230].code.tag, "BB240", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[230].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[230].entry.ec_code = ECC_SLIPWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[230].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[230].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[230].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[231].code.tag, "BB250", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[231].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[231].entry.ec_code = ECC_WATERING_PLACE;
    EDCS_FACC_2p1_Class_Mapping_Array[231].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[231].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[231].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[232].code.tag, "BC010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[232].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[232].entry.ec_code = ECC_BEACON;
    EDCS_FACC_2p1_Class_Mapping_Array[232].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[232].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[232].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[233].code.tag, "BC020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[233].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[233].entry.ec_code = ECC_NAVIGATION_BUOY;
    EDCS_FACC_2p1_Class_Mapping_Array[233].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[233].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[233].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[234].code.tag, "BC030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[234].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[234].entry.ec_code = ECC_MARINE_LEADING_LIGHTS_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[234].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[234].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[234].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[235].code.tag, "BC031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[235].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[235].entry.ec_code = ECC_NAVIGATION_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[235].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[235].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[235].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[236].code.tag, "BC032", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[236].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[236].entry.ec_code = ECC_RADAR_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[236].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[236].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[236].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[237].code.tag, "BC033", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[237].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[237].entry.ec_code = ECC_NAVIGATION_RADAR_RANGE;
    EDCS_FACC_2p1_Class_Mapping_Array[237].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[237].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[237].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[238].code.tag, "BC035", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[238].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[238].entry.ec_code = ECC_MARINE_LIGHT_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[238].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[238].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[238].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[239].code.tag, "BC040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[239].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[239].entry.ec_code = ECC_NAVIGATION_LIGHT;
    EDCS_FACC_2p1_Class_Mapping_Array[239].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[239].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[239].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[240].code.tag, "BC050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[240].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[240].entry.ec_code = ECC_LIGHTHOUSE;
    EDCS_FACC_2p1_Class_Mapping_Array[240].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[240].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[240].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[241].code.tag, "BC055", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[241].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[241].entry.ec_code = ECC_MARINE_NAVIGATION_MARKER;
    EDCS_FACC_2p1_Class_Mapping_Array[241].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[241].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[241].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[242].code.tag, "BC060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[242].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[242].entry.ec_code = ECC_MARINE_LIGHT_SECTOR;
    EDCS_FACC_2p1_Class_Mapping_Array[242].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[242].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[242].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[243].code.tag, "BC070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[243].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[243].entry.ec_code = ECC_LIGHTSHIP;
    EDCS_FACC_2p1_Class_Mapping_Array[243].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[243].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[243].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[244].code.tag, "BC080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[244].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[244].entry.ec_code = ECC_STAKE;
    EDCS_FACC_2p1_Class_Mapping_Array[244].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[244].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[244].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[245].code.tag, "BC098", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[245].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[245].entry.ec_code = ECC_NAVIGATION_MARK_AFLOAT;
    EDCS_FACC_2p1_Class_Mapping_Array[245].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[245].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[245].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[246].code.tag, "BC099", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[246].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[246].entry.ec_code = ECC_NAVIGATION_MARK_FIXED;
    EDCS_FACC_2p1_Class_Mapping_Array[246].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[246].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[246].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[247].code.tag, "BC100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[247].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[247].entry.ec_code = ECC_MARINE_LEADING_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[247].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[247].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[247].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[248].code.tag, "BC101", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[248].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[248].entry.ec_code = ECC_FOG_SIGNAL_DEVICE;
    EDCS_FACC_2p1_Class_Mapping_Array[248].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[248].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[248].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[249].code.tag, "BC102", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[249].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[249].entry.ec_code = ECC_LATERAL_BUOYAGE_INDICATION;
    EDCS_FACC_2p1_Class_Mapping_Array[249].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[249].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[249].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[250].code.tag, "BC110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[250].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[250].entry.ec_code = ECC_TOPMARK;
    EDCS_FACC_2p1_Class_Mapping_Array[250].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[250].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[250].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[251].code.tag, "BD000", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[251].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[251].entry.ec_code = ECC_UNDERWATER_HAZARD;
    EDCS_FACC_2p1_Class_Mapping_Array[251].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[251].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[251].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[252].code.tag, "BD001", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[252].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[252].entry.ec_code = ECC_EXPLOSIVE_NAVAL_MINE;
    EDCS_FACC_2p1_Class_Mapping_Array[252].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[252].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[252].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[253].code.tag, "BD005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[253].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[253].entry.ec_code = ECC_UNDERWATER_OBJECT;
    EDCS_FACC_2p1_Class_Mapping_Array[253].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[253].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[253].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[254].code.tag, "BD010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[254].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[254].entry.ec_code = ECC_BREAKER_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[254].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[254].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[254].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[255].code.tag, "BD020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[255].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[255].entry.ec_code = ECC_CRIB;
    EDCS_FACC_2p1_Class_Mapping_Array[255].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[255].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[255].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[256].code.tag, "BD030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[256].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[256].entry.ec_code = ECC_DISCOLOURED_WATER;
    EDCS_FACC_2p1_Class_Mapping_Array[256].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[256].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[256].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[257].code.tag, "BD040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[257].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[257].entry.ec_code = ECC_EDDY;
    EDCS_FACC_2p1_Class_Mapping_Array[257].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[257].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[257].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[258].code.tag, "BD050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[258].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[258].entry.ec_code = ECC_MARINE_FOUL_GROUND;
    EDCS_FACC_2p1_Class_Mapping_Array[258].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[258].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[258].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[259].code.tag, "BD060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[259].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[259].entry.ec_code = ECC_SEAWEED;
    EDCS_FACC_2p1_Class_Mapping_Array[259].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[259].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[259].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[260].code.tag, "BD070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[260].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[260].entry.ec_code = ECC_MARINE_OBSTRUCTION;
    EDCS_FACC_2p1_Class_Mapping_Array[260].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[260].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[260].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[261].code.tag, "BD071", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[261].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[261].entry.ec_code = ECC_LOG_BOOM;
    EDCS_FACC_2p1_Class_Mapping_Array[261].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[261].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[261].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[262].code.tag, "BD072", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[262].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[262].entry.ec_code = ECC_PONTOON;
    EDCS_FACC_2p1_Class_Mapping_Array[262].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[262].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[262].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[263].code.tag, "BD073", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[263].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[263].entry.ec_code = ECC_OIL_BARRIER;
    EDCS_FACC_2p1_Class_Mapping_Array[263].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[263].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[263].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[264].code.tag, "BD074", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[264].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[264].entry.ec_code = ECC_FLEXIBLE_RESTRAINT;
    EDCS_FACC_2p1_Class_Mapping_Array[264].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[264].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[264].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[265].code.tag, "BD079", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[265].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[265].entry.ec_code = ECC_FISHING_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[265].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[265].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[265].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[266].code.tag, "BD080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[266].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[266].entry.ec_code = ECC_OVERFALL_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[266].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[266].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[266].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[267].code.tag, "BD100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[267].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[267].entry.ec_code = ECC_STRUCTURAL_PILE;
    EDCS_FACC_2p1_Class_Mapping_Array[267].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[267].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[267].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[268].code.tag, "BD110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[268].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[268].entry.ec_code = ECC_MARINE_PLATFORM;
    EDCS_FACC_2p1_Class_Mapping_Array[268].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[268].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[268].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[269].code.tag, "BD111", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[269].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[269].entry.ec_code = ECC_OFFSHORE_PLATFORM;
    EDCS_FACC_2p1_Class_Mapping_Array[269].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[269].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[269].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[270].code.tag, "BD112", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[270].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[270].entry.ec_code = ECC_EXTRACTION_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[270].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[270].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[270].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[271].code.tag, "BD119", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[271].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[271].entry.ec_code = ECC_LEDGE;
    EDCS_FACC_2p1_Class_Mapping_Array[271].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[271].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[271].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[272].code.tag, "BD120", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[272].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[272].entry.ec_code = ECC_REEF;
    EDCS_FACC_2p1_Class_Mapping_Array[272].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[272].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[272].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[273].code.tag, "BD121", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[273].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[273].entry.ec_code = ECC_PINGO;
    EDCS_FACC_2p1_Class_Mapping_Array[273].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[273].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[273].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[274].code.tag, "BD122", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[274].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[274].entry.ec_code = ECC_CAY;
    EDCS_FACC_2p1_Class_Mapping_Array[274].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[274].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[274].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[275].code.tag, "BD123", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[275].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[275].entry.ec_code = ECC_WATERBODY_BOOM;
    EDCS_FACC_2p1_Class_Mapping_Array[275].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[275].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[275].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[276].code.tag, "BD130", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[276].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[276].entry.ec_code = ECC_SUBMERGED_ROCK_FORMATION;
    EDCS_FACC_2p1_Class_Mapping_Array[276].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[276].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[276].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[277].code.tag, "BD140", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[277].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[277].entry.ec_code = ECC_SNAG;
    EDCS_FACC_2p1_Class_Mapping_Array[277].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[277].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[277].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[278].code.tag, "BD180", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[278].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[278].entry.ec_code = ECC_MARINE_WRECK;
    EDCS_FACC_2p1_Class_Mapping_Array[278].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[278].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[278].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[279].code.tag, "BD181", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[279].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[279].entry.ec_code = ECC_HULK;
    EDCS_FACC_2p1_Class_Mapping_Array[279].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[279].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[279].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[280].code.tag, "BE010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[280].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[280].entry.ec_code = ECC_DEPTH_CURVE;
    EDCS_FACC_2p1_Class_Mapping_Array[280].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[280].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[280].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[281].code.tag, "BE015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[281].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[281].entry.ec_code = ECC_DEPTH_CONTOUR_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[281].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[281].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[281].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[282].code.tag, "BE019", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[282].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[282].entry.ec_code = ECC_DEPTH_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[282].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[282].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[282].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[283].code.tag, "BE020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[283].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[283].entry.ec_code = ECC_SOUNDING;
    EDCS_FACC_2p1_Class_Mapping_Array[283].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[283].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[283].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[284].code.tag, "BE021", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[284].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[284].entry.ec_code = ECC_LOW_WATER_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[284].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[284].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[284].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[285].code.tag, "BE022", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[285].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[285].entry.ec_code = ECC_SAND_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[285].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[285].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[285].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[286].code.tag, "BE023", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[286].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[286].entry.ec_code = ECC_MUD_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[286].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[286].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[286].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[287].code.tag, "BE029", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[287].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[287].entry.ec_code = ECC_WATERBODY_FLOOR_SONAR_RETURN;
    EDCS_FACC_2p1_Class_Mapping_Array[287].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[287].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[287].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[288].code.tag, "BE030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[288].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[288].entry.ec_code = ECC_TRACK_SWATH;
    EDCS_FACC_2p1_Class_Mapping_Array[288].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[288].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[288].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[289].code.tag, "BE040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[289].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[289].entry.ec_code = ECC_TRACK_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[289].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[289].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[289].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[290].code.tag, "BE050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[290].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[290].entry.ec_code = ECC_BEACH_PROFILE;
    EDCS_FACC_2p1_Class_Mapping_Array[290].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[290].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[290].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[291].code.tag, "BF010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[291].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[291].entry.ec_code = ECC_BOTTOM_CHARACTERISTIC;
    EDCS_FACC_2p1_Class_Mapping_Array[291].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[291].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[291].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[292].code.tag, "BF011", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[292].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[292].entry.ec_code = ECC_WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION;
    EDCS_FACC_2p1_Class_Mapping_Array[292].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[292].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[292].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[293].code.tag, "BG010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[293].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Class_Mapping_Array[293].entry.ec_code = ECC_OBJECT_SET;
    EDCS_FACC_2p1_Class_Mapping_Array[293].entry.num_entries = 1;
    EDCS_FACC_2p1_Class_Mapping_Array[293].entry.information = "Was: \"Current Flow: The flow direction of a current.\"";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OBJECT_SET_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_OBJSETTY_MARINE_ENVIRONMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[293].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[294].code.tag, "BG011", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[294].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[294].entry.ec_code = ECC_TIDEWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[294].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[294].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[294].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[295].code.tag, "BG012", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[295].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[295].entry.ec_code = ECC_WATER_TURBULENCE;
    EDCS_FACC_2p1_Class_Mapping_Array[295].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[295].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[295].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[296].code.tag, "BG020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[296].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[296].entry.ec_code = ECC_TIDE_GAUGE;
    EDCS_FACC_2p1_Class_Mapping_Array[296].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[296].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[296].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[297].code.tag, "BG030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[297].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[297].entry.ec_code = ECC_TIDE_DATA_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[297].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[297].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[297].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[298].code.tag, "BG040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[298].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[298].entry.ec_code = ECC_WATER_CURRENT_PROPERTY_SET;
    EDCS_FACC_2p1_Class_Mapping_Array[298].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[298].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[298].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[299].code.tag, "BH000", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[299].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[299].entry.ec_code = ECC_INLAND_WATER;
    EDCS_FACC_2p1_Class_Mapping_Array[299].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[299].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[299].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[300].code.tag, "BH010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[300].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[300].entry.ec_code = ECC_AQUEDUCT;
    EDCS_FACC_2p1_Class_Mapping_Array[300].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[300].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[300].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[301].code.tag, "BH011", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[301].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[301].entry.ec_code = ECC_WATER_INTAKE;
    EDCS_FACC_2p1_Class_Mapping_Array[301].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[301].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[301].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[302].code.tag, "BH015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[302].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[302].entry.ec_code = ECC_BOG;
    EDCS_FACC_2p1_Class_Mapping_Array[302].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[302].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[302].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[303].code.tag, "BH020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[303].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[303].entry.ec_code = ECC_CANAL;
    EDCS_FACC_2p1_Class_Mapping_Array[303].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[303].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[303].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[304].code.tag, "BH030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[304].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[304].entry.ec_code = ECC_IRRIGATION_DITCH;
    EDCS_FACC_2p1_Class_Mapping_Array[304].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[304].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[304].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[305].code.tag, "BH040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[305].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[305].entry.ec_code = ECC_WATER_TREATMENT_BED;
    EDCS_FACC_2p1_Class_Mapping_Array[305].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[305].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[305].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[306].code.tag, "BH050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[306].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[306].entry.ec_code = ECC_FISH_HATCHERY;
    EDCS_FACC_2p1_Class_Mapping_Array[306].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[306].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[306].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[307].code.tag, "BH060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[307].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[307].entry.ec_code = ECC_FLUME;
    EDCS_FACC_2p1_Class_Mapping_Array[307].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[307].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[307].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[308].code.tag, "BH070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[308].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[308].entry.ec_code = ECC_FORD;
    EDCS_FACC_2p1_Class_Mapping_Array[308].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[308].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[308].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[309].code.tag, "BH075", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[309].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[309].entry.ec_code = ECC_FOUNTAIN;
    EDCS_FACC_2p1_Class_Mapping_Array[309].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[309].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[309].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[310].code.tag, "BH077", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[310].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[310].entry.ec_code = ECC_HUMMOCK;
    EDCS_FACC_2p1_Class_Mapping_Array[310].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[310].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[310].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[311].code.tag, "BH080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[311].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[311].entry.ec_code = ECC_LAKE;
    EDCS_FACC_2p1_Class_Mapping_Array[311].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[311].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[311].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[312].code.tag, "BH090", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[312].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[312].entry.ec_code = ECC_LAND_FLOODING_PERIODICALLY;
    EDCS_FACC_2p1_Class_Mapping_Array[312].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[312].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[312].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[313].code.tag, "BH091", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[313].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[313].entry.ec_code = ECC_INUNDATED_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[313].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[313].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[313].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[314].code.tag, "BH095", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[314].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[314].entry.ec_code = ECC_VEGETATED_SATURATED_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[314].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[314].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[314].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[315].code.tag, "BH100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[315].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[315].entry.ec_code = ECC_MOAT;
    EDCS_FACC_2p1_Class_Mapping_Array[315].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[315].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[315].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[316].code.tag, "BH110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[316].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[316].entry.ec_code = ECC_PENSTOCK;
    EDCS_FACC_2p1_Class_Mapping_Array[316].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[316].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[316].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[317].code.tag, "BH115", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[317].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[317].entry.ec_code = ECC_UNDERGROUND_WATER;
    EDCS_FACC_2p1_Class_Mapping_Array[317].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[317].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[317].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[318].code.tag, "BH120", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[318].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[318].entry.ec_code = ECC_RAPID;
    EDCS_FACC_2p1_Class_Mapping_Array[318].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[318].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[318].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[319].code.tag, "BH130", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[319].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[319].entry.ec_code = ECC_RESERVOIR;
    EDCS_FACC_2p1_Class_Mapping_Array[319].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[319].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[319].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[320].code.tag, "BH135", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[320].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[320].entry.ec_code = ECC_RICE_FIELD;
    EDCS_FACC_2p1_Class_Mapping_Array[320].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[320].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[320].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[321].code.tag, "BH140", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[321].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[321].entry.ec_code = ECC_RIVER;
    EDCS_FACC_2p1_Class_Mapping_Array[321].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[321].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[321].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[322].code.tag, "BH141", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[322].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[322].entry.ec_code = ECC_RIVER_BANK;
    EDCS_FACC_2p1_Class_Mapping_Array[322].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[322].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[322].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[323].code.tag, "BH145", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[323].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[323].entry.ec_code = ECC_RIVER_VANISHING_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[323].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[323].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[323].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[324].code.tag, "BH150", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[324].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[324].entry.ec_code = ECC_SALT_PAN;
    EDCS_FACC_2p1_Class_Mapping_Array[324].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[324].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[324].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[325].code.tag, "BH155", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[325].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[325].entry.ec_code = ECC_SALT_EVAPORATOR;
    EDCS_FACC_2p1_Class_Mapping_Array[325].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[325].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[325].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[326].code.tag, "BH160", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[326].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[326].entry.ec_code = ECC_SABKHA;
    EDCS_FACC_2p1_Class_Mapping_Array[326].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[326].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[326].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[327].code.tag, "BH165", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[327].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[327].entry.ec_code = ECC_SPILLWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[327].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[327].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[327].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[328].code.tag, "BH170", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[328].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[328].entry.ec_code = ECC_WATERING_HOLE;
    EDCS_FACC_2p1_Class_Mapping_Array[328].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[328].entry.information = "Erroneously mapped to <WATERING_PLACE> in Version 1 of the mapping.";
    EDCS_FACC_2p1_Class_Mapping_Array[328].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[329].code.tag, "BH175", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[329].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[329].entry.ec_code = ECC_DRINKING_TROUGH;
    EDCS_FACC_2p1_Class_Mapping_Array[329].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[329].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[329].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[330].code.tag, "BH180", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[330].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[330].entry.ec_code = ECC_WATERFALL;
    EDCS_FACC_2p1_Class_Mapping_Array[330].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[330].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[330].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[331].code.tag, "BH190", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[331].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[331].entry.ec_code = ECC_LAGOON;
    EDCS_FACC_2p1_Class_Mapping_Array[331].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[331].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[331].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[332].code.tag, "BH191", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[332].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[332].entry.ec_code = ECC_WATER_CHANNEL;
    EDCS_FACC_2p1_Class_Mapping_Array[332].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[332].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[332].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[333].code.tag, "BH200", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[333].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[333].entry.ec_code = ECC_HYDROLOGIC_OBJECT;
    EDCS_FACC_2p1_Class_Mapping_Array[333].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[333].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[333].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[334].code.tag, "BH210", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[334].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[334].entry.ec_code = ECC_INLAND_SHORELINE;
    EDCS_FACC_2p1_Class_Mapping_Array[334].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[334].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[334].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[335].code.tag, "BH501", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[335].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[335].entry.ec_code = ECC_RIVER_ROUTE;
    EDCS_FACC_2p1_Class_Mapping_Array[335].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[335].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[335].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[336].code.tag, "BI005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[336].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[336].entry.ec_code = ECC_BOAT_LIFT;
    EDCS_FACC_2p1_Class_Mapping_Array[336].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[336].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[336].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[337].code.tag, "BI010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[337].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[337].entry.ec_code = ECC_CISTERN;
    EDCS_FACC_2p1_Class_Mapping_Array[337].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[337].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[337].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[338].code.tag, "BI020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[338].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[338].entry.ec_code = ECC_DAM;
    EDCS_FACC_2p1_Class_Mapping_Array[338].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[338].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[338].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[339].code.tag, "BI030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[339].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[339].entry.ec_code = ECC_HYDROGRAPHIC_LOCK;
    EDCS_FACC_2p1_Class_Mapping_Array[339].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[339].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[339].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[340].code.tag, "BI031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[340].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[340].entry.ec_code = ECC_LOCK_BASIN;
    EDCS_FACC_2p1_Class_Mapping_Array[340].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[340].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[340].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[341].code.tag, "BI039", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[341].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[341].entry.ec_code = ECC_SLUICE;
    EDCS_FACC_2p1_Class_Mapping_Array[341].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[341].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[341].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[342].code.tag, "BI040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[342].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[342].entry.ec_code = ECC_SLUICE_GATE;
    EDCS_FACC_2p1_Class_Mapping_Array[342].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[342].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[342].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[343].code.tag, "BI041", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[343].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[343].entry.ec_code = ECC_MARINE_GATE;
    EDCS_FACC_2p1_Class_Mapping_Array[343].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[343].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[343].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[344].code.tag, "BI042", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[344].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[344].entry.ec_code = ECC_CAISSON;
    EDCS_FACC_2p1_Class_Mapping_Array[344].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[344].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[344].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[345].code.tag, "BI043", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[345].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[345].entry.ec_code = ECC_FLOOD_BARRAGE;
    EDCS_FACC_2p1_Class_Mapping_Array[345].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[345].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[345].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[346].code.tag, "BI050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[346].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[346].entry.ec_code = ECC_WATER_INTAKE_TOWER;
    EDCS_FACC_2p1_Class_Mapping_Array[346].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[346].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[346].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[347].code.tag, "BI060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[347].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[347].entry.ec_code = ECC_FISH_LADDER;
    EDCS_FACC_2p1_Class_Mapping_Array[347].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[347].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[347].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[348].code.tag, "BI070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[348].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[348].entry.ec_code = ECC_RIVER_GAUGING_STATION;
    EDCS_FACC_2p1_Class_Mapping_Array[348].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[348].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[348].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[349].code.tag, "BI080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[349].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[349].entry.ec_code = ECC_BOAT_TURNING_BASIN;
    EDCS_FACC_2p1_Class_Mapping_Array[349].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[349].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[349].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[350].code.tag, "BJ020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[350].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[350].entry.ec_code = ECC_MORAINE;
    EDCS_FACC_2p1_Class_Mapping_Array[350].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[350].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[350].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[351].code.tag, "BJ030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[351].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[351].entry.ec_code = ECC_GLACIER;
    EDCS_FACC_2p1_Class_Mapping_Array[351].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[351].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[351].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[352].code.tag, "BJ040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[352].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[352].entry.ec_code = ECC_ICE_CLIFF;
    EDCS_FACC_2p1_Class_Mapping_Array[352].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[352].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[352].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[353].code.tag, "BJ060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[353].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[353].entry.ec_code = ECC_ICE_PEAK;
    EDCS_FACC_2p1_Class_Mapping_Array[353].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[353].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[353].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[354].code.tag, "BJ065", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[354].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[354].entry.ec_code = ECC_ICE_SHELF;
    EDCS_FACC_2p1_Class_Mapping_Array[354].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[354].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[354].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[355].code.tag, "BJ070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[355].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[355].entry.ec_code = ECC_PACK_ICE;
    EDCS_FACC_2p1_Class_Mapping_Array[355].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[355].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[355].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[356].code.tag, "BJ080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[356].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[356].entry.ec_code = ECC_POLAR_ICE;
    EDCS_FACC_2p1_Class_Mapping_Array[356].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[356].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[356].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[357].code.tag, "BJ100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[357].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[357].entry.ec_code = ECC_FROZEN_PRECIPITATION_FIELD;
    EDCS_FACC_2p1_Class_Mapping_Array[357].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[357].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[357].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[358].code.tag, "BJ110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[358].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[358].entry.ec_code = ECC_TUNDRA;
    EDCS_FACC_2p1_Class_Mapping_Array[358].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[358].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[358].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[359].code.tag, "BK010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[359].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[359].entry.ec_code = ECC_ACOUSTIC_STATION;
    EDCS_FACC_2p1_Class_Mapping_Array[359].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[359].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[359].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[360].code.tag, "BK020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[360].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[360].entry.ec_code = ECC_MAGNETIC_STATION;
    EDCS_FACC_2p1_Class_Mapping_Array[360].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[360].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[360].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[361].code.tag, "BK030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[361].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[361].entry.ec_code = ECC_WATER_DATA_COLLECTION_DEVICE;
    EDCS_FACC_2p1_Class_Mapping_Array[361].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[361].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[361].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[362].code.tag, "CA010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[362].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[362].entry.ec_code = ECC_ELEVATION_CONTOUR_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[362].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[362].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[362].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[363].code.tag, "CA020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[363].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[363].entry.ec_code = ECC_RIDGE_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[363].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[363].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[363].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[364].code.tag, "CA025", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[364].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[364].entry.ec_code = ECC_VALLEY_BOTTOM_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[364].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[364].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[364].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[365].code.tag, "CA026", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[365].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[365].entry.ec_code = ECC_BREAK_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[365].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[365].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[365].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[366].code.tag, "CA030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[366].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[366].entry.ec_code = ECC_SPOT_ELEVATION;
    EDCS_FACC_2p1_Class_Mapping_Array[366].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[366].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[366].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[367].code.tag, "CA035", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[367].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[367].entry.ec_code = ECC_INLAND_WATER_ELEVATION;
    EDCS_FACC_2p1_Class_Mapping_Array[367].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[367].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[367].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[368].code.tag, "CA040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[368].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Class_Mapping_Array[368].entry.ec_code = ECC_OBJECT_SET;
    EDCS_FACC_2p1_Class_Mapping_Array[368].entry.num_entries = 1;
    EDCS_FACC_2p1_Class_Mapping_Array[368].entry.information = "Was: \"Contour Polygon (Land): An arbitrary area outline created to establish elevation as polygons.\"";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OBJECT_SET_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_OBJSETTY_HYPSOGRAPHY;
    EDCS_FACC_2p1_Class_Mapping_Array[368].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[369].code.tag, "DA005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[369].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[369].entry.ec_code = ECC_ASPHALT_POOL;
    EDCS_FACC_2p1_Class_Mapping_Array[369].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[369].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[369].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[370].code.tag, "DA006", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[370].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[370].entry.ec_code = ECC_ALKALI_FLAT;
    EDCS_FACC_2p1_Class_Mapping_Array[370].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[370].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[370].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[371].code.tag, "DA010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[371].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[371].entry.ec_code = ECC_GROUND_SURFACE_ELEMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[371].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[371].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[371].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[372].code.tag, "DA020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[372].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[372].entry.ec_code = ECC_BARREN_GROUND;
    EDCS_FACC_2p1_Class_Mapping_Array[372].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[372].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[372].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[373].code.tag, "DA030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[373].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[373].entry.ec_code = ECC_DRY_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[373].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[373].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[373].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[374].code.tag, "DA031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[374].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[374].entry.ec_code = ECC_NAMED_LAND_TRACT;
    EDCS_FACC_2p1_Class_Mapping_Array[374].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[374].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[374].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[375].code.tag, "DB010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[375].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[375].entry.ec_code = ECC_ESCARPMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[375].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[375].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[375].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[376].code.tag, "DB030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[376].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[376].entry.ec_code = ECC_CAVE;
    EDCS_FACC_2p1_Class_Mapping_Array[376].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[376].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[376].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[377].code.tag, "DB031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[377].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[377].entry.ec_code = ECC_HILL;
    EDCS_FACC_2p1_Class_Mapping_Array[377].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[377].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[377].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[378].code.tag, "DB060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[378].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[378].entry.ec_code = ECC_SURFACE_FISSURE;
    EDCS_FACC_2p1_Class_Mapping_Array[378].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[378].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[378].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[379].code.tag, "DB070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[379].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[379].entry.ec_code = ECC_TERRAIN_CUT;
    EDCS_FACC_2p1_Class_Mapping_Array[379].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[379].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[379].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[380].code.tag, "DB080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[380].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[380].entry.ec_code = ECC_TERRAIN_DEPRESSION;
    EDCS_FACC_2p1_Class_Mapping_Array[380].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[380].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[380].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[381].code.tag, "DB090", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[381].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[381].entry.ec_code = ECC_BUILT_UP_TERRAIN;
    EDCS_FACC_2p1_Class_Mapping_Array[381].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[381].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[381].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[382].code.tag, "DB100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[382].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[382].entry.ec_code = ECC_ESKER;
    EDCS_FACC_2p1_Class_Mapping_Array[382].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[382].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[382].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[383].code.tag, "DB110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[383].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[383].entry.ec_code = ECC_GEOLOGIC_FAULT;
    EDCS_FACC_2p1_Class_Mapping_Array[383].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[383].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[383].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[384].code.tag, "DB115", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[384].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[384].entry.ec_code = ECC_GEOTHERMAL_OBJECT;
    EDCS_FACC_2p1_Class_Mapping_Array[384].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[384].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[384].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[385].code.tag, "DB145", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[385].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[385].entry.ec_code = ECC_BARRIER;
    EDCS_FACC_2p1_Class_Mapping_Array[385].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[385].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[385].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[386].code.tag, "DB150", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[386].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[386].entry.ec_code = ECC_MOUNTAIN_PASS;
    EDCS_FACC_2p1_Class_Mapping_Array[386].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[386].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[386].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[387].code.tag, "DB160", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[387].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[387].entry.ec_code = ECC_ROCKY_OUTCROP;
    EDCS_FACC_2p1_Class_Mapping_Array[387].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[387].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[387].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[388].code.tag, "DB161", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[388].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[388].entry.ec_code = ECC_ROCKY_LANDMARK;
    EDCS_FACC_2p1_Class_Mapping_Array[388].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[388].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[388].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[389].code.tag, "DB170", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[389].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[389].entry.ec_code = ECC_SAND_DUNE_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[389].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[389].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[389].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[390].code.tag, "DB176", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[390].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[390].entry.ec_code = ECC_SLOPE_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[390].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[390].entry.information = "Was: \"Slope Category: An area enclosing a group of slope values falling within a set range.\"";
    EDCS_FACC_2p1_Class_Mapping_Array[390].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[391].code.tag, "DB180", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[391].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[391].entry.ec_code = ECC_VOLCANO;
    EDCS_FACC_2p1_Class_Mapping_Array[391].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[391].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[391].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[392].code.tag, "DB190", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[392].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[392].entry.ec_code = ECC_VOLCANIC_DYKE;
    EDCS_FACC_2p1_Class_Mapping_Array[392].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[392].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[392].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[393].code.tag, "DB200", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[393].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[393].entry.ec_code = ECC_GULLY;
    EDCS_FACC_2p1_Class_Mapping_Array[393].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[393].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[393].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[394].code.tag, "DB210", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[394].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[394].entry.ec_code = ECC_POTENTIAL_LANDSLIDE_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[394].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[394].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[394].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[395].code.tag, "DB211", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[395].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[395].entry.ec_code = ECC_LANDSLIDE;
    EDCS_FACC_2p1_Class_Mapping_Array[395].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[395].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[395].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[396].code.tag, "DB220", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[396].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[396].entry.ec_code = ECC_UNDERMINED_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[396].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[396].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[396].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[397].code.tag, "DB230", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[397].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[397].entry.ec_code = ECC_ALLUVIAL_FAN;
    EDCS_FACC_2p1_Class_Mapping_Array[397].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[397].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[397].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[398].code.tag, "DB500", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[398].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[398].entry.ec_code = ECC_CLIFF_BOTTOMLINE;
    EDCS_FACC_2p1_Class_Mapping_Array[398].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[398].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[398].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[399].code.tag, "DB501", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[399].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[399].entry.ec_code = ECC_CLIFF_TOPLINE;
    EDCS_FACC_2p1_Class_Mapping_Array[399].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[399].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[399].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[400].code.tag, "EA010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[400].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[400].entry.ec_code = ECC_CROP_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[400].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[400].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[400].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[401].code.tag, "EA020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[401].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[401].entry.ec_code = ECC_HEDGEROW;
    EDCS_FACC_2p1_Class_Mapping_Array[401].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[401].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[401].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[402].code.tag, "EA030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[402].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[402].entry.ec_code = ECC_PLANT_NURSERY;
    EDCS_FACC_2p1_Class_Mapping_Array[402].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[402].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[402].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[403].code.tag, "EA031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[403].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[403].entry.ec_code = ECC_BOTANICAL_GARDEN;
    EDCS_FACC_2p1_Class_Mapping_Array[403].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[403].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[403].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[404].code.tag, "EA040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[404].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[404].entry.ec_code = ECC_SYSTEMATIC_TREE_PLANTING;
    EDCS_FACC_2p1_Class_Mapping_Array[404].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[404].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[404].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[405].code.tag, "EA050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[405].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[405].entry.ec_code = ECC_VINEYARD;
    EDCS_FACC_2p1_Class_Mapping_Array[405].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[405].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[405].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[406].code.tag, "EA055", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[406].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[406].entry.ec_code = ECC_HOP_FIELD;
    EDCS_FACC_2p1_Class_Mapping_Array[406].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[406].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[406].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[407].code.tag, "EB010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[407].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[407].entry.ec_code = ECC_GRASS_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[407].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[407].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[407].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[408].code.tag, "EB015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[408].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[408].entry.ec_code = ECC_SCRUB_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[408].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[408].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[408].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[409].code.tag, "EB020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[409].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[409].entry.ec_code = ECC_BRUSH_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[409].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[409].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[409].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[410].code.tag, "EB030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[410].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Class_Mapping_Array[410].entry.ec_code = ECC_OBJECT_SET;
    EDCS_FACC_2p1_Class_Mapping_Array[410].entry.num_entries = 1;
    EDCS_FACC_2p1_Class_Mapping_Array[410].entry.information = "Was: \"Land Use / Land Cover (Vegetation): Thematic classification of the predominant vegetation and land use characteristics of the land surface cover.\"";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OBJECT_SET_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_OBJSETTY_LAND_COVER;
    EDCS_FACC_2p1_Class_Mapping_Array[410].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[411].code.tag, "EC010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[411].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[411].entry.ec_code = ECC_WOODY_GRASS_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[411].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[411].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[411].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[412].code.tag, "EC015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[412].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[412].entry.ec_code = ECC_FOREST;
    EDCS_FACC_2p1_Class_Mapping_Array[412].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[412].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[412].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[413].code.tag, "EC020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[413].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[413].entry.ec_code = ECC_OASIS;
    EDCS_FACC_2p1_Class_Mapping_Array[413].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[413].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[413].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[414].code.tag, "EC030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[414].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[414].entry.ec_code = ECC_TREED_TRACT;
    EDCS_FACC_2p1_Class_Mapping_Array[414].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[414].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[414].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[415].code.tag, "EC040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[415].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[415].entry.ec_code = ECC_MAN_MADE_CLEARING;
    EDCS_FACC_2p1_Class_Mapping_Array[415].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[415].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[415].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[416].code.tag, "ED010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[416].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[416].entry.ec_code = ECC_MARSH;
    EDCS_FACC_2p1_Class_Mapping_Array[416].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[416].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[416].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[417].code.tag, "ED020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[417].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[417].entry.ec_code = ECC_SWAMP;
    EDCS_FACC_2p1_Class_Mapping_Array[417].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[417].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[417].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[418].code.tag, "EE000", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[418].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[418].entry.ec_code = ECC_MIXED_VEGETATION_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[418].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[418].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[418].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[419].code.tag, "EE010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[419].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[419].entry.ec_code = ECC_LOGGING_SITE;
    EDCS_FACC_2p1_Class_Mapping_Array[419].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[419].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[419].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[420].code.tag, "EE020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[420].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[420].entry.ec_code = ECC_UNVEGETATED_LAND;
    EDCS_FACC_2p1_Class_Mapping_Array[420].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[420].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[420].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[421].code.tag, "FA000", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[421].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[421].entry.ec_code = ECC_ADMINISTRATIVE_BOUNDARY;
    EDCS_FACC_2p1_Class_Mapping_Array[421].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[421].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[421].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[422].code.tag, "FA001", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[422].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[422].entry.ec_code = ECC_ADMINISTRATIVE_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[422].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[422].entry.information = "Note that \"area\" from \"Administrative Area\" corresponds to <REGION>.";
    EDCS_FACC_2p1_Class_Mapping_Array[422].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[423].code.tag, "FA005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[423].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[423].entry.ec_code = ECC_ACCESS_ZONE;
    EDCS_FACC_2p1_Class_Mapping_Array[423].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[423].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[423].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[424].code.tag, "FA015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[424].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[424].entry.ec_code = ECC_WEAPONS_RANGE;
    EDCS_FACC_2p1_Class_Mapping_Array[424].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[424].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[424].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[425].code.tag, "FA020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[425].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[425].entry.ec_code = ECC_ARMISTICE_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[425].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[425].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[425].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[426].code.tag, "FA030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[426].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[426].entry.ec_code = ECC_CEASE_FIRE_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[426].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[426].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[426].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[427].code.tag, "FA040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[427].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[427].entry.ec_code = ECC_CLAIM_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[427].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[427].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[427].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[428].code.tag, "FA041", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[428].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[428].entry.ec_code = ECC_CONTACT_ZONE;
    EDCS_FACC_2p1_Class_Mapping_Array[428].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[428].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[428].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[429].code.tag, "FA050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[429].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[429].entry.ec_code = ECC_REGULATED_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[429].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[429].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[429].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[430].code.tag, "FA060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[430].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[430].entry.ec_code = ECC_DEFACTO_BOUNDARY;
    EDCS_FACC_2p1_Class_Mapping_Array[430].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[430].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[430].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[431].code.tag, "FA070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[431].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[431].entry.ec_code = ECC_DEMILITARIZED_ZONE;
    EDCS_FACC_2p1_Class_Mapping_Array[431].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[431].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[431].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[432].code.tag, "FA080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[432].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[432].entry.ec_code = ECC_NATIONAL_PARK;
    EDCS_FACC_2p1_Class_Mapping_Array[432].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[432].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[432].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[433].code.tag, "FA081", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[433].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[433].entry.ec_code = ECC_NATURE_RESERVE;
    EDCS_FACC_2p1_Class_Mapping_Array[433].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[433].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[433].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[434].code.tag, "FA082", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[434].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[434].entry.ec_code = ECC_WATER_GATHERING_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[434].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[434].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[434].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[435].code.tag, "FA090", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[435].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[435].entry.ec_code = ECC_GEOPHYSICAL_SURVEY_PATH;
    EDCS_FACC_2p1_Class_Mapping_Array[435].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[435].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[435].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[436].code.tag, "FA100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[436].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[436].entry.ec_code = ECC_TEST_SITE;
    EDCS_FACC_2p1_Class_Mapping_Array[436].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[436].entry.information = "Original concept allowed only areas: \"An area for the testing of technical products.\"";
    EDCS_FACC_2p1_Class_Mapping_Array[436].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[437].code.tag, "FA110", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[437].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[437].entry.ec_code = ECC_INTERNATIONAL_DATE_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[437].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[437].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[437].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[438].code.tag, "FA165", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[438].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[438].entry.ec_code = ECC_TRAINING_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[438].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[438].entry.information = "Original concept allowed only areas: \"A tract of land reserved for training of military, police, fire or rescue personnel. (See also <TRAINING_BUILDING>.)\"";
    EDCS_FACC_2p1_Class_Mapping_Array[438].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[439].code.tag, "FA170", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[439].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[439].entry.ec_code = ECC_OCCUPATION_ZONE;
    EDCS_FACC_2p1_Class_Mapping_Array[439].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[439].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[439].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[440].code.tag, "FC021", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[440].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[440].entry.ec_code = ECC_MARINE_LIMIT_BOUNDARY;
    EDCS_FACC_2p1_Class_Mapping_Array[440].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[440].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[440].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[441].code.tag, "FC031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[441].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[441].entry.ec_code = ECC_MARINE_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[441].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[441].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[441].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[442].code.tag, "FC035", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[442].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[442].entry.ec_code = ECC_WATERBODY_PARTITION;
    EDCS_FACC_2p1_Class_Mapping_Array[442].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[442].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[442].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[443].code.tag, "FC036", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[443].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[443].entry.ec_code = ECC_NAVIGATION_RESTRICTED_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[443].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[443].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[443].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[444].code.tag, "FC040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[444].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[444].entry.ec_code = ECC_TSS_SYSTEM;
    EDCS_FACC_2p1_Class_Mapping_Array[444].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[444].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[444].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[445].code.tag, "FC041", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[445].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[445].entry.ec_code = ECC_TRAFFIC_SEPARATION_SCHEME;
    EDCS_FACC_2p1_Class_Mapping_Array[445].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[445].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[445].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[446].code.tag, "FC100", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[446].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[446].entry.ec_code = ECC_MARINE_MEASURED_DISTANCE_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[446].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[446].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[446].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[447].code.tag, "FC101", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[447].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[447].entry.ec_code = ECC_THEODOLITE_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[447].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[447].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[447].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[448].code.tag, "FC102", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[448].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[448].entry.ec_code = ECC_TEST_REFERENCE_TRACK;
    EDCS_FACC_2p1_Class_Mapping_Array[448].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[448].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[448].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[449].code.tag, "FC130", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[449].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[449].entry.ec_code = ECC_RADAR_REFERENCE_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[449].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[449].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[449].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[450].code.tag, "FC165", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[450].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[450].entry.ec_code = ECC_MARINE_ROUTE;
    EDCS_FACC_2p1_Class_Mapping_Array[450].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[450].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[450].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[451].code.tag, "FC166", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[451].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[451].entry.ec_code = ECC_DEEP_WATER_ROUTE;
    EDCS_FACC_2p1_Class_Mapping_Array[451].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[451].entry.information = "Note that the definition of <DEEP_WATER_ROUTE> is more explicit than that of \"Deep Water Route\", without placing constraints upon the EAs (if any) that may accompany the use of <DEEP_WATER_ROUTE>.";
    EDCS_FACC_2p1_Class_Mapping_Array[451].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[452].code.tag, "FC167", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[452].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[452].entry.ec_code = ECC_DEFINED_WATER;
    EDCS_FACC_2p1_Class_Mapping_Array[452].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[452].entry.information = "Note that the definition of <DEFINED_WATER> is more explicit than that of \"Defined Water\", without placing constraints upon the EAs (if any) that may accompany the use of <DEFINED_WATER>.";
    EDCS_FACC_2p1_Class_Mapping_Array[452].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[453].code.tag, "FC168", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[453].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[453].entry.ec_code = ECC_CANAL_ROUTE;
    EDCS_FACC_2p1_Class_Mapping_Array[453].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[453].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[453].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[454].code.tag, "FC170", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[454].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[454].entry.ec_code = ECC_SAFETY_FAIRWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[454].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[454].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[454].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[455].code.tag, "FC177", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[455].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[455].entry.ec_code = ECC_SWEPT_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[455].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[455].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[455].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[456].code.tag, "GA005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[456].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[456].entry.ec_code = ECC_CONTROLLED_AIRSPACE;
    EDCS_FACC_2p1_Class_Mapping_Array[456].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[456].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[456].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[457].code.tag, "GA010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[457].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[457].entry.ec_code = ECC_ATS_ROUTE_COMPONENT;
    EDCS_FACC_2p1_Class_Mapping_Array[457].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[457].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[457].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[458].code.tag, "GA015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[458].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[458].entry.ec_code = ECC_SPECIAL_USE_AIRSPACE;
    EDCS_FACC_2p1_Class_Mapping_Array[458].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[458].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[458].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[459].code.tag, "GA020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[459].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[459].entry.ec_code = ECC_AIRSPACE_BOUNDARY_COMPONENT;
    EDCS_FACC_2p1_Class_Mapping_Array[459].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[459].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[459].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[460].code.tag, "GA025", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[460].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[460].entry.ec_code = ECC_SPECIAL_USE_AIRSPACE_COMPONENT;
    EDCS_FACC_2p1_Class_Mapping_Array[460].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[460].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[460].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[461].code.tag, "GA030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[461].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[461].entry.ec_code = ECC_OFF_ROUTE_BEARING;
    EDCS_FACC_2p1_Class_Mapping_Array[461].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[461].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[461].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[462].code.tag, "GA031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[462].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[462].entry.ec_code = ECC_AERONAUTICAL_LEAD_RADIAL;
    EDCS_FACC_2p1_Class_Mapping_Array[462].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[462].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[462].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[463].code.tag, "GA035", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[463].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[463].entry.ec_code = ECC_AERONAUTICAL_AID_TO_NAVIGATION;
    EDCS_FACC_2p1_Class_Mapping_Array[463].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[463].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[463].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[464].code.tag, "GA045", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[464].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[464].entry.ec_code = ECC_ATS_ROUTE;
    EDCS_FACC_2p1_Class_Mapping_Array[464].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[464].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[464].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[465].code.tag, "GA047", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[465].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[465].entry.ec_code = ECC_COMPLEX_TERMINAL_ROUTE;
    EDCS_FACC_2p1_Class_Mapping_Array[465].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[465].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[465].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[466].code.tag, "GA048", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[466].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[466].entry.ec_code = ECC_ILS_COMPONENT;
    EDCS_FACC_2p1_Class_Mapping_Array[466].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[466].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[466].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[467].code.tag, "GA049", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[467].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[467].entry.ec_code = ECC_ILS_TERMINAL_COMPONENT;
    EDCS_FACC_2p1_Class_Mapping_Array[467].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[467].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[467].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[468].code.tag, "GA055", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[468].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[468].entry.ec_code = ECC_AVIATION_WAYPOINT;
    EDCS_FACC_2p1_Class_Mapping_Array[468].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[468].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[468].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[469].code.tag, "GA065", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[469].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[469].entry.ec_code = ECC_AIR_WARNING_LIGHT;
    EDCS_FACC_2p1_Class_Mapping_Array[469].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[469].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[469].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[470].code.tag, "GA070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[470].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[470].entry.ec_code = ECC_RUNWAY_PRIMARY_OIS;
    EDCS_FACC_2p1_Class_Mapping_Array[470].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[470].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[470].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[471].code.tag, "GA071", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[471].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[471].entry.ec_code = ECC_RUNWAY_APPROACH_OIS;
    EDCS_FACC_2p1_Class_Mapping_Array[471].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[471].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[471].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[472].code.tag, "GA072", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[472].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[472].entry.ec_code = ECC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS;
    EDCS_FACC_2p1_Class_Mapping_Array[472].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[472].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[472].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[473].code.tag, "GA073", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[473].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[473].entry.ec_code = ECC_RUNWAY_INNER_HORIZONTAL_OIS;
    EDCS_FACC_2p1_Class_Mapping_Array[473].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[473].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[473].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[474].code.tag, "GA074", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[474].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[474].entry.ec_code = ECC_RUNWAY_CONICAL_OIS;
    EDCS_FACC_2p1_Class_Mapping_Array[474].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[474].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[474].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[475].code.tag, "GA075", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[475].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[475].entry.ec_code = ECC_RUNWAY_OUTER_HORIZONTAL_OIS;
    EDCS_FACC_2p1_Class_Mapping_Array[475].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[475].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[475].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[476].code.tag, "GA076", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[476].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[476].entry.ec_code = ECC_RUNWAY_CONICAL_OUTER_HORIZONTAL_TRANSITIONAL_OIS;
    EDCS_FACC_2p1_Class_Mapping_Array[476].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[476].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[476].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[477].code.tag, "GB005", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[477].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[477].entry.ec_code = ECC_AERODROME;
    EDCS_FACC_2p1_Class_Mapping_Array[477].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[477].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[477].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[478].code.tag, "GB006", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[478].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[478].entry.ec_code = ECC_AIRFIELD;
    EDCS_FACC_2p1_Class_Mapping_Array[478].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[478].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[478].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[479].code.tag, "GB007", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[479].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[479].entry.ec_code = ECC_AIRPORT;
    EDCS_FACC_2p1_Class_Mapping_Array[479].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[479].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[479].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[480].code.tag, "GB010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[480].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[480].entry.ec_code = ECC_AERODROME_LIGHTING;
    EDCS_FACC_2p1_Class_Mapping_Array[480].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[480].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[480].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[481].code.tag, "GB015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[481].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[481].entry.ec_code = ECC_AIRCRAFT_PARKING_FACILITY;
    EDCS_FACC_2p1_Class_Mapping_Array[481].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[481].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[481].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[482].code.tag, "GB020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[482].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[482].entry.ec_code = ECC_ARRESTING_GEAR;
    EDCS_FACC_2p1_Class_Mapping_Array[482].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[482].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[482].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[483].code.tag, "GB025", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[483].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[483].entry.ec_code = ECC_BLAST_BARRIER;
    EDCS_FACC_2p1_Class_Mapping_Array[483].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[483].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[483].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[484].code.tag, "GB030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[484].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[484].entry.ec_code = ECC_HELICOPTER_LANDING_PAD;
    EDCS_FACC_2p1_Class_Mapping_Array[484].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[484].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[484].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[485].code.tag, "GB035", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[485].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[485].entry.ec_code = ECC_HELIPORT;
    EDCS_FACC_2p1_Class_Mapping_Array[485].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[485].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[485].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[486].code.tag, "GB040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[486].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[486].entry.ec_code = ECC_LAUNCH_PAD;
    EDCS_FACC_2p1_Class_Mapping_Array[486].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[486].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[486].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[487].code.tag, "GB045", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[487].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[487].entry.ec_code = ECC_RUNWAY_STOPWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[487].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[487].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[487].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[488].code.tag, "GB046", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[488].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[488].entry.ec_code = ECC_RUNWAY_TOUCHDOWN_ZONE;
    EDCS_FACC_2p1_Class_Mapping_Array[488].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[488].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[488].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[489].code.tag, "GB050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[489].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[489].entry.ec_code = ECC_AERODROME_REVETMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[489].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[489].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[489].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[490].code.tag, "GB055", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[490].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[490].entry.ec_code = ECC_RUNWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[490].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[490].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[490].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[491].code.tag, "GB056", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[491].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[491].entry.ec_code = ECC_RUNWAY_ENDPOINT;
    EDCS_FACC_2p1_Class_Mapping_Array[491].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[491].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[491].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[492].code.tag, "GB057", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[492].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[492].entry.ec_code = ECC_ROUTE_SHOULDER;
    EDCS_FACC_2p1_Class_Mapping_Array[492].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[492].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[492].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[493].code.tag, "GB058", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[493].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[493].entry.ec_code = ECC_POINT_ABEAM;
    EDCS_FACC_2p1_Class_Mapping_Array[493].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[493].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[493].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[494].code.tag, "GB059", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[494].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[494].entry.ec_code = ECC_AERODROME_ELEVATION_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[494].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[494].entry.information = "Note that the EDCS concept <AERODROME_ELEVATION_POINT> specifies only that the <LOCATION> is that with the highest elevation measured with respect to some <SURFACE_DATUM> that meets the specified criteria, whereas FACC goes further to specify the unit of measure used (which is not relevant, since the measurement itself is not being defined here) and the <SURFACE_DATUM> in question. Consequently, \"Airfield Elevation Point\" has a 1-1 mapping to <AERODROME_ELEVATION_POINT>, but the converse may not be true.";
    EDCS_FACC_2p1_Class_Mapping_Array[494].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[495].code.tag, "GB060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[495].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[495].entry.ec_code = ECC_RUNWAY_RADAR_REFLECTOR;
    EDCS_FACC_2p1_Class_Mapping_Array[495].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[495].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[495].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[496].code.tag, "GB065", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[496].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[496].entry.ec_code = ECC_SEAPLANE_BASE;
    EDCS_FACC_2p1_Class_Mapping_Array[496].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[496].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[496].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[497].code.tag, "GB070", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[497].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[497].entry.ec_code = ECC_SEAPLANE_RUN;
    EDCS_FACC_2p1_Class_Mapping_Array[497].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[497].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[497].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[498].code.tag, "GB075", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[498].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[498].entry.ec_code = ECC_TAXIWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[498].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[498].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[498].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[499].code.tag, "GB080", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[499].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[499].entry.ec_code = ECC_WIND_INDICATOR;
    EDCS_FACC_2p1_Class_Mapping_Array[499].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[499].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[499].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[500].code.tag, "GB090", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[500].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[500].entry.ec_code = ECC_RUNWAY_DISPLACED_THRESHOLD;
    EDCS_FACC_2p1_Class_Mapping_Array[500].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[500].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[500].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[501].code.tag, "GB160", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[501].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[501].entry.ec_code = ECC_DECONTAMINATION_PAD;
    EDCS_FACC_2p1_Class_Mapping_Array[501].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[501].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[501].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[502].code.tag, "GB170", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[502].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[502].entry.ec_code = ECC_INS_ALIGNMENT_PAD;
    EDCS_FACC_2p1_Class_Mapping_Array[502].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[502].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[502].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[503].code.tag, "GB220", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[503].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[503].entry.ec_code = ECC_NATURAL_AIR_OBSTRUCTION;
    EDCS_FACC_2p1_Class_Mapping_Array[503].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[503].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[503].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[504].code.tag, "GB221", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[504].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[504].entry.ec_code = ECC_MAN_MADE_AIR_OBSTRUCTION;
    EDCS_FACC_2p1_Class_Mapping_Array[504].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[504].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[504].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[505].code.tag, "IA010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[505].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[505].entry.ec_code = ECC_MAP_BOUNDARY;
    EDCS_FACC_2p1_Class_Mapping_Array[505].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[505].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[505].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[506].code.tag, "IA040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[506].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[506].entry.ec_code = ECC_PARCEL;
    EDCS_FACC_2p1_Class_Mapping_Array[506].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[506].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[506].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[507].code.tag, "IA050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[507].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[507].entry.ec_code = ECC_CADASTRAL_CONSTRUCTION;
    EDCS_FACC_2p1_Class_Mapping_Array[507].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[507].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[507].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[508].code.tag, "ID010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[508].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[508].entry.ec_code = ECC_CADASTRAL_CONTROL_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[508].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[508].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[508].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[509].code.tag, "ID020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[509].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[509].entry.ec_code = ECC_FIDUCIAL_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[509].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[509].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[509].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[510].code.tag, "IE010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[510].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[510].entry.ec_code = ECC_MAP_EDGE_FRAME;
    EDCS_FACC_2p1_Class_Mapping_Array[510].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[510].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[510].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[511].code.tag, "IE020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[511].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Class_Mapping_Array[511].entry.ec_code = ECC_OBJECT_SET;
    EDCS_FACC_2p1_Class_Mapping_Array[511].entry.num_entries = 1;
    EDCS_FACC_2p1_Class_Mapping_Array[511].entry.information = "Was: \"Miscellaneous: Contains topographical details and other information.\"";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_OBJECT_SET_TYPE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_OBJSETTY_ELEVATION;
    EDCS_FACC_2p1_Class_Mapping_Array[511].entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[512].code.tag, "IE040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[512].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[512].entry.ec_code = ECC_MAP_LEGEND;
    EDCS_FACC_2p1_Class_Mapping_Array[512].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[512].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[512].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[513].code.tag, "SA010", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[513].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[513].entry.ec_code = ECC_OPEN_WATER;
    EDCS_FACC_2p1_Class_Mapping_Array[513].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[513].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[513].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[514].code.tag, "SA020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[514].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[514].entry.ec_code = ECC_DISTURBED_SOIL;
    EDCS_FACC_2p1_Class_Mapping_Array[514].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[514].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[514].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[515].code.tag, "SA030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[515].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[515].entry.ec_code = ECC_EXPOSED_BEDROCK;
    EDCS_FACC_2p1_Class_Mapping_Array[515].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[515].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[515].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[516].code.tag, "SA040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[516].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[516].entry.ec_code = ECC_PERMANENT_SNOWFIELD;
    EDCS_FACC_2p1_Class_Mapping_Array[516].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[516].entry.information = "Note that this could also be mapped as <SNOWFIELD>, <<PERMANENT>>*TRUE.";
    EDCS_FACC_2p1_Class_Mapping_Array[516].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[517].code.tag, "SA050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[517].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[517].entry.ec_code = ECC_SLOPE_REGION;
    EDCS_FACC_2p1_Class_Mapping_Array[517].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[517].entry.information = "Was: \"Slope Polygon: An area enclosing a group of slope values falling within a set range.\"";
    EDCS_FACC_2p1_Class_Mapping_Array[517].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[518].code.tag, "SA060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[518].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[518].entry.ec_code = ECC_COVERED_WATERCOURSE;
    EDCS_FACC_2p1_Class_Mapping_Array[518].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[518].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[518].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[519].code.tag, "SU001", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[519].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[519].entry.ec_code = ECC_MILITARY_INSTALLATION;
    EDCS_FACC_2p1_Class_Mapping_Array[519].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[519].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[519].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[520].code.tag, "SU002", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[520].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[520].entry.ec_code = ECC_UNDERGROUND_RAILWAY;
    EDCS_FACC_2p1_Class_Mapping_Array[520].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[520].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[520].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[521].code.tag, "SU003", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[521].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[521].entry.ec_code = ECC_MARINE_PORT;
    EDCS_FACC_2p1_Class_Mapping_Array[521].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[521].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[521].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[522].code.tag, "ZB020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[522].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[522].entry.ec_code = ECC_BENCHMARK;
    EDCS_FACC_2p1_Class_Mapping_Array[522].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[522].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[522].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[523].code.tag, "ZB030", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[523].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[523].entry.ec_code = ECC_BOUNDARY_MONUMENT;
    EDCS_FACC_2p1_Class_Mapping_Array[523].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[523].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[523].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[524].code.tag, "ZB031", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[524].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[524].entry.ec_code = ECC_UNMONUMENTED_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[524].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[524].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[524].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[525].code.tag, "ZB035", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[525].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[525].entry.ec_code = ECC_SURVEY_MARKER;
    EDCS_FACC_2p1_Class_Mapping_Array[525].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[525].entry.information = "Was: \"Control Point/Control Station: An object or mark on the ground of known position, elevation, or both.\"";
    EDCS_FACC_2p1_Class_Mapping_Array[525].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[526].code.tag, "ZB036", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[526].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[526].entry.ec_code = ECC_DISTANCE_MARK;
    EDCS_FACC_2p1_Class_Mapping_Array[526].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[526].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[526].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[527].code.tag, "ZB040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[527].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[527].entry.ec_code = ECC_DIAGNOSTIC_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[527].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[527].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[527].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[528].code.tag, "ZB060", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[528].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[528].entry.ec_code = ECC_SURVEY_MARKER;
    EDCS_FACC_2p1_Class_Mapping_Array[528].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[528].entry.information = "Was: \"Geodetic Point: A physical point on the Earth's surface having a surveyed position (e.g. Trig Points).\"";
    EDCS_FACC_2p1_Class_Mapping_Array[528].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[529].code.tag, "ZC040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[529].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[529].entry.ec_code = ECC_MAGNETIC_DISTURBANCE;
    EDCS_FACC_2p1_Class_Mapping_Array[529].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[529].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[529].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[530].code.tag, "ZC050", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[530].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[530].entry.ec_code = ECC_ISOGONIC_LINE;
    EDCS_FACC_2p1_Class_Mapping_Array[530].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[530].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[530].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[531].code.tag, "ZC051", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[531].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[531].entry.ec_code = ECC_PLANETARY_MAGNETIC_POLE;
    EDCS_FACC_2p1_Class_Mapping_Array[531].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[531].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[531].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[532].code.tag, "ZD001", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[532].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[532].entry.ec_code = ECC_NETWORK;
    EDCS_FACC_2p1_Class_Mapping_Array[532].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[532].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[532].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[533].code.tag, "ZD003", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[533].entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Class_Mapping_Array[533].entry.ec_code = ((EDCS_Classification_Code)0);
    EDCS_FACC_2p1_Class_Mapping_Array[533].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[533].entry.information = "Deleted (\"Data Artifact Location\"). The concept being expressed is something EDCS supports with EV codes. For the given specific location, a user of EDCS can specify the proper EDCS Attribute to indicate what *kind* of data is being considered at that location, then assign an EV to it to indicate that data is MISSING, NOT_APPLICABLE, or whatnot.";
    EDCS_FACC_2p1_Class_Mapping_Array[533].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[534].code.tag, "ZD012", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[534].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[534].entry.ec_code = ECC_GEOGRAPHIC_INFORMATION;
    EDCS_FACC_2p1_Class_Mapping_Array[534].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[534].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[534].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[535].code.tag, "ZD015", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[535].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[535].entry.ec_code = ECC_CHANGE_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[535].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[535].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[535].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[536].code.tag, "ZD020", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[536].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[536].entry.ec_code = ECC_VOID_COLLECTION;
    EDCS_FACC_2p1_Class_Mapping_Array[536].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[536].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[536].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[537].code.tag, "ZD040", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[537].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[537].entry.ec_code = ECC_NAMED_MAP_LOCATION;
    EDCS_FACC_2p1_Class_Mapping_Array[537].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[537].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[537].entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Class_Mapping_Array[538].code.tag, "ZD045", 5);
    EDCS_FACC_2p1_Class_Mapping_Array[538].entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Class_Mapping_Array[538].entry.ec_code = ECC_DESCRIBED_POINT;
    EDCS_FACC_2p1_Class_Mapping_Array[538].entry.num_entries = 0;
    EDCS_FACC_2p1_Class_Mapping_Array[538].entry.information = "";
    EDCS_FACC_2p1_Class_Mapping_Array[538].entry.entry_list = NULL;


    if (status == EDCS_SC_SUCCESS)
    {
        qsort( EDCS_FACC_2p1_Class_Mapping_Array,
               EDCS_FACC_CLASS_MAPPING_COUNT,
               sizeof(EDCS_FACC_2p1_Class_Mapping),
               (int(*)(const void*, const void*))
               local_CompareFeature_Mapping
             );
    }
    return status;
} /* end local_init_facc_feature_mapping */

static void
local_shutdown_facc_feature_mapping( void )
{
    int i;

    for(i = 0; i < EDCS_FACC_CLASS_MAPPING_COUNT; i++)
    {
        if(EDCS_FACC_2p1_Class_Mapping_Array[i].entry.entry_list)
        {
            free(EDCS_FACC_2p1_Class_Mapping_Array[i].entry.entry_list);
        }
    }
}

static EDCS_Status_Code
local_init_facc_attribute_mapping( void )
{
    EDCS_Status_Code     status = EDCS_SC_SUCCESS;
    EDCS_Mapping_Entry * temp_entries;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[0].code.tag, "AAH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].ea_entry.ea_code = EAC_ABSOLUTE_HORIZONTAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].ea_entry.information = "Need to check that unit of measure is appropriate: EQ LENGTH.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[0].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[1].code.tag, "AAV", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].ea_entry.ea_code = EAC_ABSOLUTE_VERTICAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].ea_entry.information = "Need to check that unit of measure is appropriate: EQ LENGTH.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[1].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[2].code.tag, "ACC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].ea_entry.ea_code = EAC_LOCATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[2].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[3].code.tag, "AE1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].ea_entry.ea_code = EAC_ABSOLUTE_VERTICAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].ea_entry.num_entries = 2;
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].ea_entry.information = "Absolute geodetic height accuracy relative to WGS 84 ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_HIGH;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_VERTICAL_DATUM_IDENTIFIER;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_VERTDTMID_WGS_1984_ELLIPSOID;
    EDCS_FACC_2p1_Attribute_Mapping_Array[3].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[4].code.tag, "AE2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].ea_entry.ea_code = EAC_ABSOLUTE_VERTICAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].ea_entry.num_entries = 2;
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].ea_entry.information = "Absolute geodetic height accuracy relative to WGS 84 ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_LOW;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_VERTICAL_DATUM_IDENTIFIER;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_VERTDTMID_WGS_1984_ELLIPSOID;
    EDCS_FACC_2p1_Attribute_Mapping_Array[4].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[5].code.tag, "AEH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].ea_entry.ea_code = EAC_ABSOLUTE_VERTICAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].ea_entry.information = "Absolute geodetic height accuracy relative to WGS 84 ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VERTICAL_DATUM_IDENTIFIER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_VERTDTMID_WGS_1984_ELLIPSOID;
    EDCS_FACC_2p1_Attribute_Mapping_Array[5].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[6].code.tag, "AFA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].ea_entry.ea_code = EAC_AVAILABLE_FACILITIES_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[6].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[7].code.tag, "AGC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].ea_entry.ea_code = EAC_ARRESTING_GEAR_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[7].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[8].code.tag, "AHA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].ea_entry.ea_code = EAC_ABSOLUTE_HORIZONTAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[8].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[9].code.tag, "AHC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].ea_entry.ea_code = EAC_INLAND_HYDROGRAPHIC_PERMANENCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[9].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[10].code.tag, "AHO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].ea_entry.ea_code = EAC_AERONAUTICAL_OBSTRUCTION_HEIGHT_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[10].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[11].code.tag, "AIA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].ea_entry.ea_code = EAC_AIRSPACE_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[11].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[12].code.tag, "ALA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].ea_entry.ea_code = EAC_ABSOLUTE_LATITUDE_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].ea_entry.information = "Absolute latitude accuracy relative to WGS 84 ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VERTICAL_DATUM_IDENTIFIER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_VERTDTMID_WGS_1984_ELLIPSOID;
    EDCS_FACC_2p1_Attribute_Mapping_Array[12].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[13].code.tag, "ALC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].ea_entry.ea_code = EAC_AIRCRAFT_LOAD_RESTRICTIONS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[13].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[14].code.tag, "ALN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].ea_entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[14].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[15].code.tag, "ALO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].ea_entry.ea_code = EAC_ABSOLUTE_LONGITUDE_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].ea_entry.information = "Absolute longitude accuracy relative to WGS 84 ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VERTICAL_DATUM_IDENTIFIER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_VERTDTMID_WGS_1984_ELLIPSOID;
    EDCS_FACC_2p1_Attribute_Mapping_Array[15].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[16].code.tag, "AO1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].ea_entry.ea_code = EAC_ORIENTATION_ANGLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].ea_entry.information = "Greater precision version of \"Angle of Orientation\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[16].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[17].code.tag, "AO2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].ea_entry.ea_code = EAC_ABSOLUTE_VERTICAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].ea_entry.num_entries = 2;
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].ea_entry.information = "Absolute orthometric height accuracy relative to WGS 84 geoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_HIGH;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_VERTICAL_DATUM_IDENTIFIER;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_VERTDTMID_WGS_1984_GEOID;
    EDCS_FACC_2p1_Attribute_Mapping_Array[17].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[18].code.tag, "AO3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].ea_entry.ea_code = EAC_ABSOLUTE_VERTICAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].ea_entry.num_entries = 2;
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].ea_entry.information = "Absolute orthometric height accuracy relative to WGS 84 geoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(2, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_LOW;
    temp_entries[1].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[1].u.attr_value_entry.ea_code = EAC_VERTICAL_DATUM_IDENTIFIER;
    temp_entries[1].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[1].u.attr_value_entry.ea_value.value.enumeration_value = EEC_VERTDTMID_WGS_1984_GEOID;
    EDCS_FACC_2p1_Attribute_Mapping_Array[18].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[19].code.tag, "AOH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].ea_entry.ea_code = EAC_ABSOLUTE_VERTICAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].ea_entry.information = "Absolute orthometric height accuracy relative to WGS 84 geoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_VERTICAL_DATUM_IDENTIFIER;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_VERTDTMID_WGS_1984_GEOID;
    EDCS_FACC_2p1_Attribute_Mapping_Array[19].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[20].code.tag, "AOO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].ea_entry.ea_code = EAC_ORIENTATION_ANGLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[20].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[21].code.tag, "APT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].ea_entry.ea_code = EAC_AERODROME_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[21].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[22].code.tag, "ARA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].eu_entry.eu_code = EUC_SQ_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].ea_entry.ea_code = EAC_AREA;
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[22].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[23].code.tag, "ARE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].eu_entry.eu_code = EUC_SQ_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].ea_entry.ea_code = EAC_AREA;
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].ea_entry.information = "Greater precision version of \"Area Coverage Attribute\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[23].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[24].code.tag, "ARH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].eu_entry.eu_code = EUC_HECTARE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].ea_entry.ea_code = EAC_AREA;
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].ea_entry.information = "Hectare version of \"Area Coverage Attribute\" - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[24].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[25].code.tag, "ARR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].ea_entry.ea_code = EAC_RADAR_REFLECTOR_ANGLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[25].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[26].code.tag, "ASS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].ea_entry.ea_code = EAC_RUNWAY_APPROACH_OIS_DISTANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[26].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[27].code.tag, "ATC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].ea_entry.ea_code = EAC_AQUEDUCT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[27].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[28].code.tag, "ATL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].ea_entry.ea_code = EAC_ATS_ROUTE_COMPONENT_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[28].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[29].code.tag, "ATN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[29].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[30].code.tag, "AUA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].ea_entry.ea_code = EAC_ATS_USE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[30].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[31].code.tag, "AUB", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].ea_entry.ea_code = EAC_AIRSPACE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[31].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[32].code.tag, "AUL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].ea_entry.ea_code = EAC_AIRSPACE_LIMITATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[32].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[33].code.tag, "AUR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].ea_entry.ea_code = EAC_ATS_ROUTE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[33].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[34].code.tag, "AUS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].ea_entry.ea_code = EAC_AIRSPACE_OPERATING_RESTRICTIONS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[34].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[35].code.tag, "AV1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].ea_entry.ea_code = EAC_LOWEST_AIRSPACE_ALTITUDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].ea_entry.information = "Feet version - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[35].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[36].code.tag, "AV2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].ea_entry.ea_code = EAC_HIGHEST_AIRSPACE_ALTITUDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].ea_entry.information = "Feet version - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[36].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[37].code.tag, "AVA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].ea_entry.ea_code = EAC_ABSOLUTE_VERTICAL_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[37].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[38].code.tag, "AWD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].ea_entry.ea_code = EAC_ATS_ROUTE_COMPONENT_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[38].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[39].code.tag, "AZ1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].ea_entry.ea_code = EAC_LOWEST_AIRSPACE_ALTITUDE_LIMIT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].ea_entry.information = "Feet version - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[39].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[40].code.tag, "AZ2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].ea_entry.ea_code = EAC_HIGHEST_AIRSPACE_ALTITUDE_LIMIT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].ea_entry.information = "Feet version - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[40].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[41].code.tag, "AZ3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].ea_entry.ea_code = EAC_MINIMUM_SAFE_ALTITUDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].ea_entry.information = "Feet version - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[41].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[42].code.tag, "BAC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].ea_entry.ea_code = EAC_BUILT_UP_REGION_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[42].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[43].code.tag, "BCC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].ea_entry.ea_code = EAC_BYPASS_CONDITION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[43].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[44].code.tag, "BCR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].ea_entry.ea_code = EAC_BOTTOM_RETURN_ROCK_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[44].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[45].code.tag, "BCT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].ea_entry.ea_code = EAC_WATERBODY_FLOOR_CONFIGURATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[45].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[46].code.tag, "BDC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].ea_entry.ea_code = EAC_BRIDGE_DESIGN;
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[46].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[47].code.tag, "BDT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_MARKER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[47].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[48].code.tag, "BEN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].ea_entry.ea_code = EAC_TEXTUAL_OBJECT_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[48].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[49].code.tag, "BER", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].ea_entry.ea_code = EAC_BERTH_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[49].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[50].code.tag, "BET", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].ea_entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].ea_entry.information = "Mapped to <<MARK_TYPE>> qualified by <<BEACON_PRESENT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[50].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[51].code.tag, "BFC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].ea_entry.ea_code = EAC_BUILDING_FUNCTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[51].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[52].code.tag, "BGL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].ea_entry.ea_code = EAC_LEFT_ABOVE_BANK_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[52].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[53].code.tag, "BGR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].ea_entry.ea_code = EAC_RIGHT_ABOVE_BANK_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[53].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[54].code.tag, "BHL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].ea_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[54].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[55].code.tag, "BHR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].ea_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[55].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[56].code.tag, "BIT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].ea_entry.ea_code = EAC_BEACH_PORTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[56].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[57].code.tag, "BLC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].ea_entry.ea_code = EAC_BARGE_LOAD_RESTRICTIONS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[57].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[58].code.tag, "BMC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].ea_entry.ea_code = EAC_WATERBODY_FLOOR_MATERIAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[58].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[59].code.tag, "BOC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].ea_entry.ea_code = EAC_WETLAND_SURFACE_FORM;
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[59].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[60].code.tag, "BOT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].ea_entry.ea_code = EAC_BRIDGE_OPENING_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[60].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[61].code.tag, "BR2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].eu_entry.eu_code = EUC_HERTZ;
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].ea_entry.ea_code = EAC_SECONDARY_BROADCAST_FREQUENCY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[61].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[62].code.tag, "BRA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].ea_entry.ea_code = EAC_BOTTOM_RETURN_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[62].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[63].code.tag, "BRC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].ea_entry.ea_code = EAC_BOTTOM_RETURN_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[63].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[64].code.tag, "BRF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].eu_entry.eu_code = EUC_HERTZ;
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].ea_entry.ea_code = EAC_PRIMARY_BROADCAST_FREQUENCY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[64].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[65].code.tag, "BRG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].ea_entry.ea_code = EAC_OBJECT_BEARING_GEODETIC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[65].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[66].code.tag, "BRI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].ea_entry.ea_code = EAC_BOTTOM_RETURN_ALLEGIANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[66].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[67].code.tag, "BRN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].ea_entry.ea_code = EAC_BRIDGE_AND_SPAN_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[67].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[68].code.tag, "BRO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].ea_entry.ea_code = EAC_BOTTOM_RETURN_OBSTACLE_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[68].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[69].code.tag, "BRR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].ea_entry.ea_code = EAC_BEARING_AND_RECIPROCAL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].ea_entry.information = "Changed datatype from STRING to CONSTRAINED_STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[69].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[70].code.tag, "BRS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].ea_entry.ea_code = EAC_BEARING_FROM_SEAWARD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[70].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[71].code.tag, "BRT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].ea_entry.ea_code = EAC_BOTTOM_RETURN_TRACK_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[71].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[72].code.tag, "BRW", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].ea_entry.ea_code = EAC_BOTTOM_RETURN_WRECK_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[72].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[73].code.tag, "BSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].ea_entry.ea_code = EAC_BRIDGE_STRUCTURE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[73].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[74].code.tag, "BSM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].ea_entry.ea_code = EAC_BRIDGE_SPAN_MOBILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[74].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[75].code.tag, "BSN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].ea_entry.ea_code = EAC_BRIDGE_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[75].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[76].code.tag, "BSP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].ea_entry.ea_code = EAC_BRIDGE_SPAN_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[76].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[77].code.tag, "BSR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].ea_entry.ea_code = EAC_BOTTOM_RETURN_SEABED_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[77].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[78].code.tag, "BST", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].ea_entry.ea_code = EAC_BOUNDARY_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[78].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[79].code.tag, "BTC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].ea_entry.ea_code = EAC_MARK_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[79].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[80].code.tag, "BUD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].ea_entry.ea_code = EAC_BRUSH_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<BRUSH_DENSITY>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[80].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[81].code.tag, "BUT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].ea_entry.ea_code = EAC_BUOY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[81].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[82].code.tag, "BVL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].ea_entry.ea_code = EAC_LEFT_BANK_VEGETATION_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[82].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[83].code.tag, "BVR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].ea_entry.ea_code = EAC_RIGHT_BANK_VEGETATION_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[83].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[84].code.tag, "BWL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].ea_entry.ea_code = EAC_LEFT_BELOW_BANK_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[84].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[85].code.tag, "BWR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].ea_entry.ea_code = EAC_RIGHT_BELOW_BANK_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[85].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[86].code.tag, "C60", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_AT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[86].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[87].code.tag, "C61", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_ONE_HOUR_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[87].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[88].code.tag, "C62", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_TWO_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[88].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[89].code.tag, "C63", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_THREE_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[89].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[90].code.tag, "C64", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FOUR_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[90].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[91].code.tag, "C65", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FIVE_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[91].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[92].code.tag, "C66", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_SIX_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[92].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[93].code.tag, "C67", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FIVE_HRS_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[93].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[94].code.tag, "C68", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FOUR_HRS_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[94].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[95].code.tag, "C69", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_THREE_HRS_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[95].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[96].code.tag, "C70", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_TWO_HRS_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[96].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[97].code.tag, "C71", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_ONE_HOUR_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[97].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[98].code.tag, "C80", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_AT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[98].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[99].code.tag, "C81", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_ONE_HOUR_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[99].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[100].code.tag, "C82", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_TWO_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[100].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[101].code.tag, "C83", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_THREE_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[101].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[102].code.tag, "C84", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FOUR_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[102].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[103].code.tag, "C85", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FIVE_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[103].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[104].code.tag, "C86", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_SIX_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[104].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[105].code.tag, "C87", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_SEVEN_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[105].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[106].code.tag, "C88", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_EIGHT_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[106].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[107].code.tag, "C89", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_NINE_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[107].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[108].code.tag, "C90", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_TEN_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[108].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[109].code.tag, "C91", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].ea_entry.information = "Knot - do not need to convert.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_ELEVEN_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[109].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[110].code.tag, "CAB", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].ea_entry.ea_code = EAC_CABLE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[110].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[111].code.tag, "CAC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].ea_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].ea_entry.information = "Equivalent to \"Void Collection Attribute\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[111].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[112].code.tag, "CAP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].ea_entry.ea_code = EAC_CAPACITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].ea_entry.information = "Changed datatype from STR_STRING to CONSTRAINED_STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[112].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[113].code.tag, "CCA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].ea_entry.ea_code = EAC_ROUTE_CONSTRICTION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].ea_entry.information = "Sometimes maps to <<ROUTE_EXPANSION_TYPE>>, depending on enumerant.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[113].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[114].code.tag, "CCC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].ea_entry.ea_code = EAC_COLOURATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[114].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[115].code.tag, "CCR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].ea_entry.ea_code = EAC_COLOURATION_INFORMATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[115].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[116].code.tag, "CDA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].ea_entry.ea_code = EAC_COVERED_DRAIN;
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[116].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[117].code.tag, "CDL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].ea_entry.ea_code = EAC_COVERED_DRAIN_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[117].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[118].code.tag, "CDP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].ea_entry.ea_code = EAC_RECORDING_DATE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[118].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[119].code.tag, "CDV", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].ea_entry.ea_code = EAC_CALENDAR_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_ISO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[119].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[120].code.tag, "CET", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].ea_entry.ea_code = EAC_GRADING_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[120].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[121].code.tag, "CFD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].ea_entry.ea_code = EAC_CULTURAL_OBJECT_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[121].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[122].code.tag, "CHA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].ea_entry.ea_code = EAC_LIGHT_PATTERN;
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[122].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[123].code.tag, "CHL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].ea_entry.ea_code = EAC_COMMUNICATION_CHANNEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[123].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[124].code.tag, "CHT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].ea_entry.ea_code = EAC_WATER_CHANNEL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[124].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[125].code.tag, "CIC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].ea_entry.ea_code = EAC_COLOUR_INTENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[125].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[126].code.tag, "CLI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].ea_entry.ea_code = EAC_ISOLATED_COMMUNICATION_LINE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[126].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[127].code.tag, "CLR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].ea_entry.ea_code = EAC_RAPID_CLASS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[127].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[128].code.tag, "CLT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].ea_entry.information = "Deleted (no longer in FACC): \"Color of Text: Specifies colour to be used when displaying objects identified as NAMED_LOCATION or TEXT_DESCRIPTION.\"";
    EDCS_FACC_2p1_Attribute_Mapping_Array[128].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[129].code.tag, "COC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].ea_entry.ea_code = EAC_CONSPICUOUSNESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[129].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[130].code.tag, "COD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].ea_entry.ea_code = EAC_DELINEATION_CERTAIN;
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[130].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[131].code.tag, "COE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].ea_entry.ea_code = EAC_EXISTENCE_CERTAINTY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[131].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[132].code.tag, "COL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].ea_entry.ea_code = EAC_SIGNAL_LIGHT_CHARACTER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].ea_entry.information = "Changed datatype from LEX_STRING to CONSTRAINED_STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[132].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[133].code.tag, "COT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].ea_entry.ea_code = EAC_CONTOUR_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[133].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[134].code.tag, "CPA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].ea_entry.ea_code = EAC_SURVEY_CONTROL_POINT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[134].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[135].code.tag, "CRA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].ea_entry.ea_code = EAC_CRANE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[135].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[136].code.tag, "CRC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].ea_entry.ea_code = EAC_ROUTE_CROSSING_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[136].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[137].code.tag, "CRM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].ea_entry.ea_code = EAC_CRANE_MOBILITY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[137].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[138].code.tag, "CRN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].ea_entry.ea_code = EAC_MINIMUM_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].ea_entry.information = "Knot - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[138].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[139].code.tag, "CRS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].ea_entry.ea_code = EAC_WATER_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].ea_entry.information = "Knot - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[139].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[140].code.tag, "CRV", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].ea_entry.information = "Use <<WATER_DEPTH>> with an appropriate classification (e.g. <CONTOUR_LINE>); alternately, use attribute <<TERRAIN_ELEVATION>> on an appropriate feature type (e.g., classification \"Contour Line\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[140].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[141].code.tag, "CRX", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].eu_entry.eu_code = EUC_KNOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].ea_entry.ea_code = EAC_MAXIMUM_CURRENT_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].ea_entry.information = "Knot - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[141].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[142].code.tag, "CSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].ea_entry.ea_code = EAC_CROSSING_CONTROL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[142].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[143].code.tag, "CSM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].ea_entry.ea_code = EAC_SECONDARY_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[143].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[144].code.tag, "CTC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].ea_entry.ea_code = EAC_CULVERT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[144].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[145].code.tag, "CTL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].ea_entry.ea_code = EAC_CUMULATIVE_TRACK_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[145].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[146].code.tag, "CUR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].ea_entry.ea_code = EAC_WATER_CURRENT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[146].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[147].code.tag, "CVH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].ea_entry.ea_code = EAC_MAXIMUM_CONTOUR_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[147].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[148].code.tag, "CVL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].ea_entry.ea_code = EAC_MINIMUM_CONTOUR_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[148].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[149].code.tag, "D60", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_AT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[149].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[150].code.tag, "D61", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_ONE_HOUR_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[150].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[151].code.tag, "D62", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_TWO_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[151].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[152].code.tag, "D63", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_THREE_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[152].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[153].code.tag, "D64", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FOUR_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[153].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[154].code.tag, "D65", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FIVE_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[154].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[155].code.tag, "D66", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_SIX_HRS_AFT_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[155].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[156].code.tag, "D67", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FIVE_HRS_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[156].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[157].code.tag, "D68", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FOUR_HRS_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[157].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[158].code.tag, "D69", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_THREE_HRS_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[158].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[159].code.tag, "D70", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_TWO_HRS_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[159].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[160].code.tag, "D71", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_ONE_HOUR_BEFORE_TIDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[160].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[161].code.tag, "D80", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_AT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[161].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[162].code.tag, "D81", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_ONE_HOUR_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[162].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[163].code.tag, "D82", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_TWO_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[163].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[164].code.tag, "D83", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_THREE_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[164].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[165].code.tag, "D84", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FOUR_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[165].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[166].code.tag, "D85", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_FIVE_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[166].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[167].code.tag, "D86", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_SIX_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[167].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[168].code.tag, "D87", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_SEVEN_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[168].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[169].code.tag, "D88", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_EIGHT_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[169].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[170].code.tag, "D89", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_NINE_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[170].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[171].code.tag, "D90", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_TEN_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[171].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[172].code.tag, "D91", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].ea_entry.ea_code = EAC_WATER_CURRENT_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_WATER_CURRENT_REFERENCE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_WTRCURREFR_ELEVEN_HRS_AFT_HIGH_WATER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[172].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[173].code.tag, "DAN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_DESCRIPTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[173].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[174].code.tag, "DEP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].ea_entry.ea_code = EAC_DEPTH_BELOW_SURFACE_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[174].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[175].code.tag, "DF1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].ea_entry.ea_code = EAC_VEHICLE_TRAFFIC_GEODETIC_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_USAGE_PRIMARY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[175].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[176].code.tag, "DF2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].ea_entry.ea_code = EAC_VEHICLE_TRAFFIC_GEODETIC_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_USAGE_SECONDARY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[176].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[177].code.tag, "DF3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].ea_entry.ea_code = EAC_VEHICLE_TRAFFIC_GEODETIC_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_USAGE_TERTIARY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[177].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[178].code.tag, "DF4", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].ea_entry.ea_code = EAC_VEHICLE_TRAFFIC_GEODETIC_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_USAGE_QUATERNARY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[178].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[179].code.tag, "DFT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].ea_entry.ea_code = EAC_DAM_FACE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[179].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[180].code.tag, "DGC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].ea_entry.ea_code = EAC_DROP_GATE_METHOD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[180].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[181].code.tag, "DIR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].ea_entry.ea_code = EAC_RF_DIRECTIVITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[181].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[182].code.tag, "DMB", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].ea_entry.ea_code = EAC_BRUSH_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[182].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[183].code.tag, "DMF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].ea_entry.ea_code = EAC_OBJECT_TYPE_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[183].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[184].code.tag, "DMK", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].ea_entry.ea_code = EAC_KELP_COVERAGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[184].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[185].code.tag, "DMR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].ea_entry.ea_code = EAC_ROOF_COVER_FRACTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[185].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[186].code.tag, "DMS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].ea_entry.ea_code = EAC_STRUCTURE_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[186].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[187].code.tag, "DMT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].ea_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].ea_entry.information = "Mapped to <<SUMMER_CANOPY_COVER_FRACTION>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[187].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[188].code.tag, "DOF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].ea_entry.ea_code = EAC_FLOW_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[188].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[189].code.tag, "DP1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].ea_entry.ea_code = EAC_HIGHEST_ANNUAL_GROUND_WATER_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[189].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[190].code.tag, "DP2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].ea_entry.ea_code = EAC_LOWEST_ANNUAL_GROUND_WATER_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[190].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[191].code.tag, "DR1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].ea_entry.ea_code = EAC_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].ea_entry.information = "Map to <<WATER_DEPTH>> as interval, with lower end as \"[\" with value supplied, and upper end as \"]\" with accompanying value of DR2 (if DR2 is missing, use \"OPEN]\"); EU METRE ES UNI; one out EA results from two EAs in; lesser precision \"Minimum Depth Range\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[191].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[192].code.tag, "DR2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].ea_entry.ea_code = EAC_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].ea_entry.information = "Map to <<WATER_DEPTH>> as interval, with lower end as \"[\" with accompanying value of DR1 (if DR1 is missing, use \"[OPEN\"), and upper end as \"]\" with value supplied; EU METRE ES UNI; one out EA results from two EAs in; lesser precision \"Maximum Depth Range\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[192].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[193].code.tag, "DR3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].ea_entry.ea_code = EAC_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].ea_entry.information = "Map to <<WATER_DEPTH>> as interval, with lower end as \"[\" with value supplied, and upper end as \"]\" with accompanying value of DR4 (if DR4 is missing, use \"OPEN]\"); EU METRE ES UNI; one out EA results from two EAs in; greater precision \"Minimum Depth Range\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[193].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[194].code.tag, "DR4", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].ea_entry.ea_code = EAC_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].ea_entry.information = "Map to <<WATER_DEPTH>> as interval, with lower end as \"[\" with accompanying value of DR3 (if DR3 is missing, use \"[OPEN\"), and upper end as \"]\" with value supplied; EU METRE ES UNI; one out EA results from two EAs in; greater precision \"Maximum Depth Range\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[194].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[195].code.tag, "DRP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].ea_entry.ea_code = EAC_MARINE_LINE_ATNAV_DESCRIPTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[195].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[196].code.tag, "DRW", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].ea_entry.ea_code = EAC_WOODY_VEGETATION_DENSITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[196].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[197].code.tag, "DTE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].ea_entry.ea_code = EAC_PERIODIC_END_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_YYYYMMDD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[197].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[198].code.tag, "DTF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].ea_entry.ea_code = EAC_RUNWAY_DISPLACED_THRESHOLD_DISTANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[198].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[199].code.tag, "DTM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].ea_entry.ea_code = EAC_RUNWAY_DISPLACED_THRESHOLD_DISTANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[199].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[200].code.tag, "DTS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].ea_entry.ea_code = EAC_PERIODIC_START_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_YYYYMMDD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[200].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[201].code.tag, "DUN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].ea_entry.information = "Deleted (no longer in FACC): \"Units, Depth: Unit of depth measurement.\"";
    EDCS_FACC_2p1_Attribute_Mapping_Array[201].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[202].code.tag, "DW1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].ea_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<PREDOMINANT_WATER_DEPTH>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[202].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[203].code.tag, "DW2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].ea_entry.ea_code = EAC_PREDOMINANT_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<PREDOMINANT_WATER_DEPTH>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[203].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[204].code.tag, "DWT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].ea_entry.ea_code = EAC_HYDROGRAPHIC_BARRIER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[204].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[205].code.tag, "EBT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].ea_entry.ea_code = EAC_EDUCATIONAL_BUILDING_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[205].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[206].code.tag, "EDP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].ea_entry.ea_code = EAC_ELECTRONIC_WATERBODY_FLOOR_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[206].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[207].code.tag, "EHF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].ea_entry.ea_code = EAC_RUNWAY_ENDPOINT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].ea_entry.information = "Geodetic height relative to unspecified ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_HIGH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[207].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[208].code.tag, "EHM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].ea_entry.ea_code = EAC_RUNWAY_ENDPOINT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].ea_entry.information = "Geodetic height relative to unspecified ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_HIGH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[208].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[209].code.tag, "ELA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].ea_entry.ea_code = EAC_ELEVATION_ACCURACY_STATEMENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[209].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[210].code.tag, "ELF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].ea_entry.ea_code = EAC_RUNWAY_ENDPOINT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].ea_entry.information = "Geodetic height relative to unspecified ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_LOW;
    EDCS_FACC_2p1_Attribute_Mapping_Array[210].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[211].code.tag, "ELM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].ea_entry.ea_code = EAC_RUNWAY_ENDPOINT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].ea_entry.information = "Geodetic height relative to unspecified ellipsoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_LOW;
    EDCS_FACC_2p1_Attribute_Mapping_Array[211].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[212].code.tag, "EOL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].ea_entry.ea_code = EAC_LIGHT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[212].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[213].code.tag, "EPW", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].eu_entry.eu_code = EUC_WATT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].eu_entry.es_code = ESC_MEGA;
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].ea_entry.ea_code = EAC_POWER_GENERATING_CAPACITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[213].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[214].code.tag, "ETN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].eu_entry.eu_code = EUC_VOLT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].ea_entry.ea_code = EAC_VOLTAGE_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[214].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[215].code.tag, "EXS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].ea_entry.ea_code = EAC_EXISTENCE_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].ea_entry.information = "<<EXISTENCE_STATUS>> has been refactored into a separate set of EA s and has been deprecated. The other EA s are: <<FACILITY_COMMISSIONED_STATUS>>, <<FACILITY_OPERATION_CONTINUITY>>, <<FUNCTIONAL_STATUS>>, <<HISTORICAL_SIGNIFICANCE>>, <<ISOLATED>>, <<MAINTAINED>>, <<MAN_MADE>>, <<MINE_SWEPT>>, <<MONITORED>>, <<NAVIGABLE_STATUS>>, <<PERMANENT>>, <<TIDE_INFLUENCED>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[215].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[216].code.tag, "FAC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].ea_entry.ea_code = EAC_MARINE_CONSTRUCTION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[216].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[217].code.tag, "FCL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].ea_entry.ea_code = EAC_FERRY_CROSSING_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[217].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[218].code.tag, "FCO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].ea_entry.ea_code = EAC_OBJECT_CONFIGURATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].ea_entry.information = "Sometimes maps to <<OBJECT_CONFIGURATION_QUALITY>>, depending on enumerant.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[218].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[219].code.tag, "FCT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].eu_entry.eu_code = EUC_MINUTE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].ea_entry.ea_code = EAC_FERRY_CROSSING_TIME;
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[219].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[220].code.tag, "FDT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].ea_entry.ea_code = EAC_FOG_DETECTOR_LIGHT_PRESENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[220].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[221].code.tag, "FEO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].ea_entry.ea_code = EAC_OBJECT_ELEMENT_GEODETIC_ORIENTATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[221].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[222].code.tag, "FER", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].ea_entry.ea_code = EAC_FERRY_ROUTE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[222].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[223].code.tag, "FFA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].ea_entry.ea_code = EAC_FUEL_FACILITIES_AVAILABLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[223].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[224].code.tag, "FFC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].ea_entry.ea_code = EAC_FISHING_FACILITY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[224].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[225].code.tag, "FHC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].ea_entry.ea_code = EAC_HARBOUR_FACILITY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[225].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[226].code.tag, "FL1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].ea_entry.ea_code = EAC_MINIMUM_FLIGHT_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].ea_entry.information = "Feet version - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[226].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[227].code.tag, "FL2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].ea_entry.ea_code = EAC_MAXIMUM_FLIGHT_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].ea_entry.information = "Feet version - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[227].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[228].code.tag, "FLT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].ea_entry.ea_code = EAC_STRUCTURE_LIGHTING_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[228].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[229].code.tag, "FON", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].ea_entry.information = "Deleted (\"Type of Font: Font used to display objects identified as NAMED_LOCATION or TEXT_DESCRIPTION.\")";
    EDCS_FACC_2p1_Attribute_Mapping_Array[229].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[230].code.tag, "FRQ", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].eu_entry.eu_code = EUC_HERTZ;
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].ea_entry.ea_code = EAC_FREQUENCY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[230].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[231].code.tag, "FRT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].ea_entry.ea_code = EAC_WEAPONS_RANGE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[231].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[232].code.tag, "FTC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].ea_entry.information = "Split into <<FARMING_METHOD>>, <<IRRIGATION_TYPE>> and <<FIELD_PATTERN>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[232].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[233].code.tag, "FTI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].ea_entry.ea_code = EAC_FENCE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[233].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[234].code.tag, "FTP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].ea_entry.ea_code = EAC_FABRICATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[234].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[235].code.tag, "FTR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].ea_entry.ea_code = EAC_OBJECT_RATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].ea_entry.information = "Changed datatype from STR_STRING to CONSTRAINED_STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[235].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[236].code.tag, "FVO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].ea_entry.ea_code = EAC_OBJECT_ORIENTATION_WRT_VERTICAL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[236].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[237].code.tag, "GAW", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].eu_entry.es_code = ESC_CENTI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].ea_entry.ea_code = EAC_RAILWAY_GAUGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[237].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[238].code.tag, "GEH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].ea_entry.ea_code = EAC_GEOMORPHIC_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[238].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[239].code.tag, "GEN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].ea_entry.ea_code = EAC_FOG_SIGNAL_GENERATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[239].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[240].code.tag, "GEO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].ea_entry.ea_code = EAC_GEOGRAPHIC_REGION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[240].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[241].code.tag, "GLI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].ea_entry.information = "Deleted (\"Greater Than or Equal To / Less Than Contour Interval\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[241].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[242].code.tag, "GNC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].ea_entry.ea_code = EAC_NAUTICAL_GATE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[242].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[243].code.tag, "GPD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].ea_entry.ea_code = EAC_GEOMORPHIC_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[243].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[244].code.tag, "GRP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].ea_entry.ea_code = EAC_SIGNAL_LIGHT_PATTERN;
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].ea_entry.information = "Changed datatype from LEX_STRING to CONSTRAINED_STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[244].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[245].code.tag, "GSA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].ea_entry.ea_code = EAC_GLIDE_SLOPE_ANGLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[245].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[246].code.tag, "GSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].ea_entry.ea_code = EAC_TERRAIN_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<TERRAIN_SLOPE>>; may also map to <<DISSECTED_TERRAIN>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[246].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[247].code.tag, "GTC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].ea_entry.ea_code = EAC_GATE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[247].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[248].code.tag, "GUG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].ea_entry.ea_code = EAC_GUYED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[248].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[249].code.tag, "GW1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].ea_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<WATERCOURSE_GAP_WIDTH>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[249].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[250].code.tag, "GW2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].ea_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<WATERCOURSE_GAP_WIDTH>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[250].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[251].code.tag, "GW3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].ea_entry.ea_code = EAC_WATERCOURSE_GAP_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<WATERCOURSE_GAP_WIDTH>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[251].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[252].code.tag, "HCA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].ea_entry.ea_code = EAC_HORIZONTAL_CLEARANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[252].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[253].code.tag, "HCC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].ea_entry.ea_code = EAC_HORIZONTAL_CLEARANCE_LIMITED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[253].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[254].code.tag, "HDH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].ea_entry.ea_code = EAC_HYDROGRAPHIC_DRYING_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[254].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[255].code.tag, "HDI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].ea_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_INFORMATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].ea_entry.information = "Sometimes maps to <<UNCOVERING_HEIGHT_KNOWN>>, depending on enumerant.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[255].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[256].code.tag, "HDP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].ea_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[256].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[257].code.tag, "HFC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].ea_entry.ea_code = EAC_WATERCOURSE_CHANNEL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].ea_entry.information = "Sometimes maps to <<WATERCOURSE_SINK_TYPE>>, depending on enumerant.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[257].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[258].code.tag, "HGF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].ea_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].ea_entry.information = "Feet version of \"Height Above Surface Level\" - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[258].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[259].code.tag, "HGT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].ea_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[259].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[260].code.tag, "HGU", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].ea_entry.ea_code = EAC_UPSTREAM_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[260].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[261].code.tag, "HID", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].ea_entry.ea_code = EAC_HARBOUR_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[261].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[262].code.tag, "HL1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].ea_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<LEFT_BANK_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[262].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[263].code.tag, "HL2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].ea_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<LEFT_BANK_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[263].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[264].code.tag, "HL3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].ea_entry.ea_code = EAC_LEFT_BANK_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<LEFT_BANK_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[264].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[265].code.tag, "HLK", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].ea_entry.ea_code = EAC_HULK_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[265].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[266].code.tag, "HLT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].ea_entry.ea_code = EAC_MARINE_LIGHT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[266].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[267].code.tag, "HOC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].ea_entry.ea_code = EAC_HYDROGRAPHIC_OBJECT_ORIGIN;
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[267].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[268].code.tag, "HOD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].ea_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].ea_entry.information = "Mapped to \"Horizontal Datum\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[268].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[269].code.tag, "HQC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].ea_entry.ea_code = EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[269].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[270].code.tag, "HR1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].ea_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<RIGHT_BANK_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[270].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[271].code.tag, "HR2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].ea_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<RIGHT_BANK_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[271].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[272].code.tag, "HR3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].ea_entry.ea_code = EAC_RIGHT_BANK_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<RIGHT_BANK_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[272].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[273].code.tag, "HS1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].ea_entry.ea_code = EAC_WATER_CURRENT_APPEARANCE_MONTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[273].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[274].code.tag, "HS2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].ea_entry.ea_code = EAC_WATER_CURRENT_DISAPPEARANCE_MONTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[274].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[275].code.tag, "HSB", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].ea_entry.ea_code = EAC_HEIGHT_ABOVE_WATERBODY_FLOOR;
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[275].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[276].code.tag, "HSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].ea_entry.ea_code = EAC_HOSPITAL_BED_CAPACITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[276].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[277].code.tag, "HTR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].ea_entry.ea_code = EAC_HEIGHT_ABOVE_SURFACE_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<HEIGHT_ABOVE_SURFACE_LEVEL>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[277].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[278].code.tag, "HWT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].ea_entry.ea_code = EAC_WORSHIP_PLACE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[278].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[279].code.tag, "HYC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].ea_entry.ea_code = EAC_HYDROLOGIC_PERMANENCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[279].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[280].code.tag, "HZD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].ea_entry.ea_code = EAC_GEODETIC_DATUM_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[280].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[281].code.tag, "IAC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[281].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[282].code.tag, "IAS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].ea_entry.ea_code = EAC_IMO_ADOPTED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[282].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[283].code.tag, "IBC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].ea_entry.ea_code = EAC_INSTALLATION_BUOY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[283].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[284].code.tag, "ICC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].ea_entry.ea_code = EAC_SEA_ICE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[284].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[285].code.tag, "ICE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].ea_entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_ICING_SAG;
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[285].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[286].code.tag, "ICL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].ea_entry.ea_code = EAC_ICAO_AIRSPACE_CLASS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[286].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[287].code.tag, "IDN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].ea_entry.information = "Deleted (\"Identification Number\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[287].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[288].code.tag, "IKO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].ea_entry.ea_code = EAC_AVIATION_LOCATION_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_AVIATION_LOCATION_ID_VALUE_SET;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_AVTLOCIDVALSET_ICAO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[288].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[289].code.tag, "IWO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].ea_entry.ea_code = EAC_INLAND_WATER_OBSTRUCTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[289].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[290].code.tag, "JCR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].ea_entry.ea_code = EAC_ROAD_JUNCTION_CONNECTIVITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[290].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[291].code.tag, "KVA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].eu_entry.eu_code = EUC_VOLT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].eu_entry.es_code = ESC_KILO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].ea_entry.ea_code = EAC_MAXIMUM_VOLTAGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[291].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[292].code.tag, "LAB", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].ea_entry.ea_code = EAC_OBJECT_LABEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[292].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[293].code.tag, "LAF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].ea_entry.ea_code = EAC_MARINE_LINE_ASSOCIATED_ATNAV;
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[293].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[294].code.tag, "LC1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].eu_entry.eu_code = EUC_TON;
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].ea_entry.ea_code = EAC_LOAD_CLASS_ONE_WAY_WHEELED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].ea_entry.information = "Ton - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[294].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[295].code.tag, "LC2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].eu_entry.eu_code = EUC_TON;
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].ea_entry.ea_code = EAC_LOAD_CLASS_TWO_WAY_WHEELED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].ea_entry.information = "Ton - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[295].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[296].code.tag, "LC3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].eu_entry.eu_code = EUC_TON;
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].ea_entry.ea_code = EAC_LOAD_CLASS_ONE_WAY_TRACKED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].ea_entry.information = "Ton - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[296].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[297].code.tag, "LC4", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].eu_entry.eu_code = EUC_TON;
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].ea_entry.ea_code = EAC_LOAD_CLASS_TWO_WAY_TRACKED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].ea_entry.information = "Ton - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[297].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[298].code.tag, "LCN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].ea_entry.ea_code = EAC_SIGNAL_LIGHT_PATTERN_COUNT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[298].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[299].code.tag, "LEC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].ea_entry.information = "Deleted (\"Length of Cab\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[299].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[300].code.tag, "LEF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].ea_entry.ea_code = EAC_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].ea_entry.information = "Foot version of \"Length / Diameter\" - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[300].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[301].code.tag, "LEN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].ea_entry.ea_code = EAC_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[301].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[302].code.tag, "LFA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].ea_entry.ea_code = EAC_AERONAUTICAL_LIGHT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[302].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[303].code.tag, "LFC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].ea_entry.ea_code = EAC_LIGHT_FUNCTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[303].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[304].code.tag, "LNC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].ea_entry.ea_code = EAC_NAVIGATION_PATH_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[304].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[305].code.tag, "LOC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].ea_entry.ea_code = EAC_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[305].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[306].code.tag, "LOG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].ea_entry.ea_code = EAC_LAND_ROUTE_SLOPE_SEGMENT_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[306].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[307].code.tag, "LOR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_RANGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[307].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[308].code.tag, "LRP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_RANGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].ea_entry.information = "Greater precision nautical mile version of \"Length of Range\" - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[308].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[309].code.tag, "LSA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].ea_entry.ea_code = EAC_LIGHT_SECTOR_ANGLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[309].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[310].code.tag, "LSI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].ea_entry.ea_code = EAC_MARINE_LIGHT_SECTOR_INITIAL_ANGLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[310].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[311].code.tag, "LST", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].ea_entry.ea_code = EAC_MARINE_LIGHT_SECTOR_TERMINAL_ANGLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[311].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[312].code.tag, "LTN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].ea_entry.ea_code = EAC_PATH_COUNT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[312].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[313].code.tag, "LVG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].ea_entry.ea_code = EAC_GEOGRAPHIC_LIGHT_RANGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[313].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[314].code.tag, "LVL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].ea_entry.ea_code = EAC_LUMINOUS_LIGHT_RANGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[314].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[315].code.tag, "LVN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].ea_entry.ea_code = EAC_NOMINAL_LIGHT_RANGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[315].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[316].code.tag, "MAA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].ea_entry.ea_code = EAC_MAXIMUM_AUTHORIZED_ALTITUDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].ea_entry.information = "Changed datatype from STRING to REAL; parse string.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[316].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[317].code.tag, "MAC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].ea_entry.ea_code = EAC_MARINE_REGION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[317].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[318].code.tag, "MAG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].ea_entry.ea_code = EAC_MAGNETIC_FIELD_DECLINATION_ANGLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[318].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[319].code.tag, "MAR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_COLOUR;
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[319].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[320].code.tag, "MAS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].ea_entry.ea_code = EAC_MAINTAINED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[320].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[321].code.tag, "MAT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].ea_entry.ea_code = EAC_MINE_OTHER_INFORMATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[321].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[322].code.tag, "MBI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].ea_entry.ea_code = EAC_MILITARY_BRIDGE_INFORMATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[322].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[323].code.tag, "MBL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].ea_entry.ea_code = EAC_MARINE_BOUNDARY_LIMIT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[323].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[324].code.tag, "MCA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].ea_entry.ea_code = EAC_CHARACTER_EMITTED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[324].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[325].code.tag, "MCC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].ea_entry.ea_code = EAC_PRIMARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[325].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[326].code.tag, "MCS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].ea_entry.ea_code = EAC_SECONDARY_MATERIAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[326].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[327].code.tag, "MCT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].ea_entry.ea_code = EAC_MOORING_CONNECTION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[327].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[328].code.tag, "MCU", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].ea_entry.ea_code = EAC_UNDERLYING_MATERIAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[328].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[329].code.tag, "MEA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].ea_entry.ea_code = EAC_MINIMUM_ENROUTE_ALTITUDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].ea_entry.information = "Changed datatype from STR_STRING to REAL; parse string.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[329].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[330].code.tag, "MED", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].ea_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<LAND_TRNSP_MEDIAN_WIDTH>>; mapped to <<LAND_TRNSP_MEDIAN_PRESENT>> for BOOLEAN values.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[330].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[331].code.tag, "MFA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].ea_entry.ea_code = EAC_VEHICLE_MAINTENANCE_AVAILABLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[331].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[332].code.tag, "MHF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].ea_entry.ea_code = EAC_MATERIAL_HANDLING_FACILITIES;
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[332].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[333].code.tag, "MIA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].ea_entry.ea_code = EAC_MINE_ACOUSTIC_ACTUATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[333].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[334].code.tag, "MIC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].ea_entry.ea_code = EAC_MINE_CONTACT_ACTUATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[334].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[335].code.tag, "MID", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].ea_entry.ea_code = EAC_MINE_ALLEGIANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[335].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[336].code.tag, "MII", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].ea_entry.ea_code = EAC_MINE_INFLUENCE_ACTUATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[336].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[337].code.tag, "MIM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].ea_entry.ea_code = EAC_MINE_MAGNETIC_SENSITIVITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[337].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[338].code.tag, "MIN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].ea_entry.ea_code = EAC_EXTRACTION_MINE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[338].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[339].code.tag, "MIO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].ea_entry.ea_code = EAC_MINE_OTHER_ACTUATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[339].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[340].code.tag, "MLR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].ea_entry.ea_code = EAC_LIGHT_VISIBILITY_RANGES;
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].ea_entry.information = "Changed datatype from STRING to CONSTRAINED_STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[340].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[341].code.tag, "MMT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].ea_entry.ea_code = EAC_MINE_TACTICAL_USE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[341].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[342].code.tag, "MNA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].ea_entry.ea_code = EAC_MINE_ACTUATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[342].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[343].code.tag, "MNC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].ea_entry.ea_code = EAC_MINE_CONTROL_METHOD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[343].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[344].code.tag, "MNI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].ea_entry.ea_code = EAC_MINE_INDEPENDENT_ACTUATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[344].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[345].code.tag, "MNL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].ea_entry.ea_code = EAC_MINE_CABLELESS_ACTUATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[345].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[346].code.tag, "MOC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].ea_entry.ea_code = EAC_ATS_ROUTE_LOWEST_ALTITUDE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[346].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[347].code.tag, "MOL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].ea_entry.ea_code = EAC_LIGHT_MULTIPLICITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[347].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[348].code.tag, "MPC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].ea_entry.ea_code = EAC_MINE_POSITION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[348].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[349].code.tag, "MPG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].eu_entry.eu_code = EUC_KILOGRAM;
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].ea_entry.ea_code = EAC_MINE_CHARGE_SIZE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[349].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[350].code.tag, "MPM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].ea_entry.ea_code = EAC_MINE_MOORED_POSITION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[350].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[351].code.tag, "MPO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].ea_entry.ea_code = EAC_MINE_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[351].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[352].code.tag, "MSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].ea_entry.ea_code = EAC_MINE_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[352].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[353].code.tag, "MSD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].ea_entry.ea_code = EAC_MINE_SPECIAL_CAPABILITY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[353].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[354].code.tag, "MSH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].ea_entry.ea_code = EAC_MINE_ANTI_HUNTING_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[354].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[355].code.tag, "MSI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].ea_entry.ea_code = EAC_MINE_INFORMATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[355].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[356].code.tag, "MSR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].ea_entry.ea_code = EAC_MINE_ANTI_RECOVERY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[356].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[357].code.tag, "MST", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].ea_entry.ea_code = EAC_MISSILE_SITE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[357].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[358].code.tag, "MSU", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].ea_entry.ea_code = EAC_MINE_OPERATIONAL_USE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[358].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[359].code.tag, "MSW", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].ea_entry.ea_code = EAC_MINE_ANTI_SWEEP_WIRE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[359].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[360].code.tag, "MTC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].ea_entry.ea_code = EAC_MAST_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[360].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[361].code.tag, "MTN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].ea_entry.ea_code = EAC_MINE_TRACK_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[361].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[362].code.tag, "MTT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].ea_entry.ea_code = EAC_MARINE_TRACK_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[362].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[363].code.tag, "MVC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].ea_entry.ea_code = EAC_MAXIMUM_VERTICAL_CLEARANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[363].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[364].code.tag, "MWF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].ea_entry.ea_code = EAC_MOORING_FACILITY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[364].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[365].code.tag, "MWG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].ea_entry.ea_code = EAC_LAND_TRNSP_MEDIAN_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[365].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[366].code.tag, "NA2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].ea_entry.ea_code = EAC_TOURISTIC_NAME;
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[366].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[367].code.tag, "NA3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].ea_entry.ea_code = EAC_CLASSIFICATION_NAME;
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[367].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[368].code.tag, "NA4", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].ea_entry.ea_code = EAC_COUNTRY_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_COUNTRY_ID_VALUE_SET;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_CTRYIDVALSET_US_FIPS_PRIN_ADMIN_DIVISION_CODE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[368].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[369].code.tag, "NAM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].ea_entry.ea_code = EAC_NAME;
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[369].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[370].code.tag, "NAS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].ea_entry.ea_code = EAC_NATIVE_SETTLEMENT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[370].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[371].code.tag, "NLC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].ea_entry.ea_code = EAC_MARINE_NAVIGATION_LINE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[371].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[372].code.tag, "NM3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].ea_entry.ea_code = EAC_BOUNDARY_FIRST_SIDE_NAME;
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[372].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[373].code.tag, "NM4", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].ea_entry.ea_code = EAC_BOUNDARY_SECOND_SIDE_NAME;
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[373].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[374].code.tag, "NMD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].ea_entry.ea_code = EAC_MARINER_NOTICE_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_ISO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[374].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[375].code.tag, "NMS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_MARK_SYSTEM;
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[375].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[376].code.tag, "NOP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].ea_entry.ea_code = EAC_PLATFORM_COUNT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[376].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[377].code.tag, "NOS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].ea_entry.ea_code = EAC_BRIDGE_SPAN_COUNT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[377].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[378].code.tag, "NPL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].ea_entry.ea_code = EAC_PARALLEL_LINE_COUNT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[378].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[379].code.tag, "NS2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].ea_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].ea_entry.information = "Mapped to <<NAVIGATION_SYSTEM_TYPE>> with qualifying <<USAGE>> of \"Secondary\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_USAGE_SECONDARY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[379].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[380].code.tag, "NST", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].ea_entry.ea_code = EAC_NAVIGATION_SYSTEM_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].ea_entry.information = "Mapped to <<NAVIGATION_SYSTEM_TYPE>> with qualifying <<USAGE>> of \"Primary\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_USAGE_PRIMARY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[380].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[381].code.tag, "OBC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].ea_entry.ea_code = EAC_OIL_BARRIER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[381].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[382].code.tag, "OCC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].ea_entry.ea_code = EAC_OVERHEAD_OBSTRUCTED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[382].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[383].code.tag, "ODF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].ea_entry.ea_code = EAC_ATS_ROUTE_OPPOSITE_FLOW_DIRECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[383].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[384].code.tag, "OHB", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].ea_entry.ea_code = EAC_OVERALL_BRIDGE_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[384].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[385].code.tag, "OHC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].ea_entry.ea_code = EAC_OVERHEAD_CLEARANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[385].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[386].code.tag, "OHD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].ea_entry.ea_code = EAC_MAXIMUM_OBSTACLE_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[386].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[387].code.tag, "OHF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].ea_entry.ea_code = EAC_RUNWAY_ENDPOINT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].ea_entry.information = "Orthometric height relative to unspecified geoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_HIGH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[387].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[388].code.tag, "OHM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].ea_entry.ea_code = EAC_RUNWAY_ENDPOINT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].ea_entry.information = "Orthometric height relative to unspecified geoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_HIGH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[388].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[389].code.tag, "OLF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].ea_entry.ea_code = EAC_RUNWAY_ENDPOINT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].ea_entry.information = "Orthometric height relative to unspecified geoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_LOW;
    EDCS_FACC_2p1_Attribute_Mapping_Array[389].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[390].code.tag, "OLM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].ea_entry.ea_code = EAC_RUNWAY_ENDPOINT_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].ea_entry.information = "Orthometric height relative to unspecified geoid.";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_LOW;
    EDCS_FACC_2p1_Attribute_Mapping_Array[390].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[391].code.tag, "OLQ", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].ea_entry.ea_code = EAC_MULTIPLE_OBSTRUCTION_LIGHTS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[391].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[392].code.tag, "OOC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].ea_entry.ea_code = EAC_OVERHEAD_OBSTRUCTION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[392].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[393].code.tag, "OPC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].ea_entry.ea_code = EAC_OFFSHORE_PLATFORM_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[393].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[394].code.tag, "OPS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].ea_entry.ea_code = EAC_OPERATIONAL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[394].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[395].code.tag, "OPT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].ea_entry.ea_code = EAC_OPERATING_TIME;
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[395].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[396].code.tag, "OR2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_SECONDARY_OPERATING_RANGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[396].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[397].code.tag, "ORC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_PRIMARY_OPERATING_RANGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[397].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[398].code.tag, "ORD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].ea_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[398].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[399].code.tag, "ORS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].ea_entry.ea_code = EAC_OPERATING_RESTRICTIONS_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[399].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[400].code.tag, "OWO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].ea_entry.ea_code = EAC_MARINE_OVERHEAD_OBSTRUCTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[400].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[401].code.tag, "PAB", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].ea_entry.ea_code = EAC_RUNWAY_POINT_ABEAM_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[401].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[402].code.tag, "PAN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].ea_entry.ea_code = EAC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS_SECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[402].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[403].code.tag, "PAT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_COLOUR_PATTERN;
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[403].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[404].code.tag, "PBP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].ea_entry.ea_code = EAC_MARINE_PILOT_BOARDING_METHOD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[404].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[405].code.tag, "PBR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].ea_entry.ea_code = EAC_PUBLICATION_REFERENCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[405].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[406].code.tag, "PBV", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].ea_entry.ea_code = EAC_MARINE_PILOT_BOARDING_VEHICLE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[406].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[407].code.tag, "PCC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].ea_entry.ea_code = EAC_FRACTIONAL_CONTENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[407].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[408].code.tag, "PCI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].ea_entry.ea_code = EAC_CHANGE_POINT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[408].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[409].code.tag, "PCU", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].ea_entry.ea_code = EAC_PEDESTRIAN_CAPACITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[409].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[410].code.tag, "PDE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].ea_entry.ea_code = EAC_PERIODIC_END_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_YYYYMMDD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[410].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[411].code.tag, "PDR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].ea_entry.ea_code = EAC_PEDESTRIAN_RATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].ea_entry.information = "Changed datatype from STR_STRING to CONSTRAINED_STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[411].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[412].code.tag, "PDS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].ea_entry.ea_code = EAC_PERIODIC_START_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_YYYYMMDD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[412].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[413].code.tag, "PER", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].eu_entry.eu_code = EUC_SECOND;
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].ea_entry.ea_code = EAC_LIGHT_PERIOD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[413].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[414].code.tag, "PEV", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].ea_entry.ea_code = EAC_NON_SUB_CONTACT_POSITION_ACCURACY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[414].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[415].code.tag, "PFD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].ea_entry.ea_code = EAC_PREDOMINANT_DEPTH_WITHIN_OBJECT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[415].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[416].code.tag, "PFE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].ea_entry.ea_code = EAC_PREDOMINANT_DEPTH_WITHIN_OBJECT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].ea_entry.information = "Greater precision version of \"Predominant Object Depth\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[416].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[417].code.tag, "PFG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].ea_entry.ea_code = EAC_PREDOMINANT_HEIGHT_WITHIN_OBJECT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].ea_entry.information = "Greater precision version \"Predominant Object Height\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[417].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[418].code.tag, "PFH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].ea_entry.ea_code = EAC_PREDOMINANT_HEIGHT_WITHIN_OBJECT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[418].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[419].code.tag, "PH4", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].ea_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<PREDOMINANT_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[419].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[420].code.tag, "PHT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].ea_entry.ea_code = EAC_PREDOMINANT_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[420].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[421].code.tag, "PIC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].ea_entry.ea_code = EAC_PICTORIAL_RESOURCE_REQUEST;
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[421].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[422].code.tag, "PIL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].ea_entry.ea_code = EAC_MARINE_PILOT_DISTRICT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[422].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[423].code.tag, "PLC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].ea_entry.ea_code = EAC_STRUCTURAL_PILE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[423].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[424].code.tag, "PLT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].ea_entry.ea_code = EAC_PIPELINE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[424].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[425].code.tag, "POI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].ea_entry.ea_code = EAC_INTEREST_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[425].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[426].code.tag, "POP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].ea_entry.ea_code = EAC_POND_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[426].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[427].code.tag, "PPC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].ea_entry.ea_code = EAC_POWER_PLANT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[427].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[428].code.tag, "PPL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].ea_entry.ea_code = EAC_POPULATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[428].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[429].code.tag, "PPT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].ea_entry.ea_code = EAC_POPULATED_PLACE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[429].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[430].code.tag, "PR1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].ea_entry.ea_code = EAC_PERIODIC_RESTRICTION_START;
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[430].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[431].code.tag, "PR2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].ea_entry.ea_code = EAC_PERIODIC_RESTRICTION_END;
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[431].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[432].code.tag, "PRC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].ea_entry.ea_code = EAC_PERIODIC_RESTRICTION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[432].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[433].code.tag, "PRM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].ea_entry.ea_code = EAC_PERMANENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[433].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[434].code.tag, "PRO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].ea_entry.ea_code = EAC_PRIMARY_PRODUCT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].ea_entry.information = "Sometimes maps to <<PRIMARY_BYPRODUCT>> and <<PRIMARY_RAW_MATERIAL>>, depending on enumerant.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[434].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[435].code.tag, "PSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].ea_entry.ea_code = EAC_SURFACE_CHARACTERISTIC_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[435].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[436].code.tag, "PSN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].ea_entry.ea_code = EAC_RUNWAY_PRIMARY_OIS_SECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[436].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[437].code.tag, "PST", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].ea_entry.ea_code = EAC_PHYSICAL_STATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[437].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[438].code.tag, "PWC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].ea_entry.ea_code = EAC_BERTH_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[438].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[439].code.tag, "QID", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].ea_entry.information = "Deleted (\"Quality / Source Record Identifiers: The three character tag for the Source or Quality Record followed by the record number, (e.g., \"QAL4\").\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[439].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[440].code.tag, "QLE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].ea_entry.ea_code = EAC_RELEASABILITY_RESTRICTIONS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[440].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[441].code.tag, "QUA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].ea_entry.ea_code = EAC_LOCATION_ACCURACY_METHOD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[441].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[442].code.tag, "QUD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].ea_entry.ea_code = EAC_RUNWAY_OIS_QUADRANT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[442].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[443].code.tag, "QUL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].ea_entry.information = "Deleted (\"Percentage Reliability of a Qualitative Attribute: Percentage reliability of a Qualitative Attribute.\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[443].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[444].code.tag, "QUT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].ea_entry.information = "Deleted (\"Standard Deviation of a Qualitative Attribute: Standard deviation of a Qualitative Attribute.\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[444].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[445].code.tag, "RAD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].ea_entry.ea_code = EAC_SHARP_CURVE_RADIUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[445].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[446].code.tag, "RAG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].ea_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[446].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[447].code.tag, "RAN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].eu_entry.eu_code = EUC_NAUTICAL_MILE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].ea_entry.ea_code = EAC_AID_TO_NAVIGATION_EFFECTIVENESS_RADIUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].ea_entry.information = "Nautical mile - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[447].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[448].code.tag, "RAS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].ea_entry.ea_code = EAC_RADAR_STATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[448].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[449].code.tag, "RBC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].ea_entry.ea_code = EAC_BRIDGE_INFORMATION_RELIABILITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[449].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[450].code.tag, "RCD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].ea_entry.ea_code = EAC_RECORDING_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_YYYYMMDD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[450].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[451].code.tag, "RDT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].ea_entry.ea_code = EAC_ROAD_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[451].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[452].code.tag, "REF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].ea_entry.ea_code = EAC_RADAR_REFLECTOR_PRESENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[452].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[453].code.tag, "REL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].ea_entry.ea_code = EAC_RELIGIOUS_DESIGNATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].ea_entry.information = "Maps to <<RELIGIOUS_DESIGNATION>>, qualified where needed by various \"denominational family\" EAs.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[453].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[454].code.tag, "RET", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].ea_entry.ea_code = EAC_ACOUSTIC_REFLECTION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[454].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[455].code.tag, "RFQ", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].eu_entry.eu_code = EUC_HERTZ;
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].eu_entry.es_code = ESC_KILO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].ea_entry.ea_code = EAC_RADAR_BEACON_FREQUENCY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[455].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[456].code.tag, "RGC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].ea_entry.ea_code = EAC_RAILWAY_GAUGE_CATEGORY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[456].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[457].code.tag, "RGS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].ea_entry.ea_code = EAC_LIGHT_RELATIVE_LOCATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[457].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[458].code.tag, "RID", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].ea_entry.ea_code = EAC_RUNWAY_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].ea_entry.information = "Changed datatype from STR_STRING to CONSTRAINED_STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[458].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[459].code.tag, "RIH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].ea_entry.ea_code = EAC_RUNWAY_HIGH_END_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[459].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[460].code.tag, "RIL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].ea_entry.ea_code = EAC_RUNWAY_LOW_END_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[460].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[461].code.tag, "RIT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].ea_entry.ea_code = EAC_ROAD_INTERCHANGE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[461].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[462].code.tag, "RKF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].ea_entry.ea_code = EAC_ROCK_FORMATION_STRUCTURE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[462].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[463].code.tag, "RMA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].eu_entry.eu_code = EUC_TON;
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].ea_entry.ea_code = EAC_RAILWAY_MAXIMUM_AXLE_LOAD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].ea_entry.information = "Ton - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[463].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[464].code.tag, "RMT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].eu_entry.eu_code = EUC_TON;
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].ea_entry.ea_code = EAC_RAILWAY_MAXIMUM_LOAD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].ea_entry.information = "Ton - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[464].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[465].code.tag, "RN2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].ea_entry.ea_code = EAC_ROUTE_ALTERNATIVE_DESIGNATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[465].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[466].code.tag, "RNK", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].ea_entry.ea_code = EAC_OBJECT_ORDINAL_RANK;
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].ea_entry.information = "Mapped to \"Ordinal Category\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[466].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[467].code.tag, "ROS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].ea_entry.ea_code = EAC_RADIO_STATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[467].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[468].code.tag, "RPA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].ea_entry.information = "Deleted (\"Require Port Access\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[468].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[469].code.tag, "RRA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].ea_entry.ea_code = EAC_RAILWAY_POWER_SOURCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[469].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[470].code.tag, "RRC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].ea_entry.ea_code = EAC_RAILWAY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[470].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[471].code.tag, "RSA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].ea_entry.ea_code = EAC_BRANCH_RAILWAY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[471].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[472].code.tag, "RSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].ea_entry.ea_code = EAC_MARINE_RESCUE_STATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[472].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[473].code.tag, "RST", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].ea_entry.ea_code = EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[473].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[474].code.tag, "RTA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].ea_entry.ea_code = EAC_RAILWAY_TRACK_ARRANGEMENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[474].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[475].code.tag, "RTB", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].ea_entry.ea_code = EAC_RADAR_TRANSPONDER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[475].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[476].code.tag, "RTC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].ea_entry.ea_code = EAC_ROUTE_WEATHER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[476].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[477].code.tag, "RTN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].ea_entry.ea_code = EAC_ROUTE_DESIGNATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[477].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[478].code.tag, "RTP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].ea_entry.ea_code = EAC_RESERVOIR_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[478].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[479].code.tag, "RTT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].ea_entry.ea_code = EAC_MARINE_ROUTE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[479].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[480].code.tag, "RWL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].ea_entry.ea_code = EAC_WAVELENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].ea_entry.information = "Was \"Wavelength, Radar\".";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_USAGE;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_USAGE_RADAR;
    EDCS_FACC_2p1_Attribute_Mapping_Array[480].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[481].code.tag, "RWT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].ea_entry.ea_code = EAC_RUNWAY_END;
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[481].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[482].code.tag, "SAV", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].ea_entry.information = "Deleted (\"Standardized Attribute Values: Standardized attribute values for use with non-enumerated attributes.\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[482].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[483].code.tag, "SAW", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].ea_entry.ea_code = EAC_MARINE_WARNING_SIGNAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[483].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[484].code.tag, "SBC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].ea_entry.ea_code = EAC_SHELTER_BELT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[484].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[485].code.tag, "SC1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].ea_entry.ea_code = EAC_BEACON_SECTOR_FIRST_LIMIT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[485].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[486].code.tag, "SC2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].ea_entry.ea_code = EAC_BEACON_SECTOR_SECOND_LIMIT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[486].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[487].code.tag, "SCC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].ea_entry.ea_code = EAC_WATER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[487].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[488].code.tag, "SD1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].eu_entry.es_code = ESC_CENTI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].ea_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<MEAN_STEM_DIAMETER>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[488].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[489].code.tag, "SD2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].eu_entry.es_code = ESC_CENTI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].ea_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<MEAN_STEM_DIAMETER>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[489].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[490].code.tag, "SDC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].ea_entry.ea_code = EAC_SOIL_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[490].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[491].code.tag, "SDE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].ea_entry.ea_code = EAC_SOIL_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<SOIL_DEPTH>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[491].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[492].code.tag, "SDO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].ea_entry.ea_code = EAC_SAND_DUNE_ORIENTATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[492].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[493].code.tag, "SDR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].ea_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].ea_entry.information = "Greater precision version of \"Stem Diameter Size\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[493].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[494].code.tag, "SDS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].ea_entry.ea_code = EAC_MEAN_STEM_DIAMETER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[494].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[495].code.tag, "SEA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].ea_entry.ea_code = EAC_WATERBODY_FLOOR_MORPHOLOGY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[495].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[496].code.tag, "SEC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].ea_entry.ea_code = EAC_SECURITY_LEVEL;
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[496].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[497].code.tag, "SEQ", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].ea_entry.ea_code = EAC_SIGNAL_LIGHT_SEQUENCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[497].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[498].code.tag, "SFA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].ea_entry.ea_code = EAC_STORAGE_FACILITY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[498].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[499].code.tag, "SFC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].ea_entry.ea_code = EAC_WATERBODY_FLOOR_OBJECT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[499].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[500].code.tag, "SGC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].ea_entry.ea_code = EAC_SURFACE_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[500].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[501].code.tag, "SGO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].ea_entry.ea_code = EAC_SURFACE_SLOPE_ORIENTATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[501].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[502].code.tag, "SHC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].ea_entry.ea_code = EAC_WATER_CHANNEL_SAFE_HORIZONTAL_CLEARANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[502].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[503].code.tag, "SHO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].ea_entry.ea_code = EAC_SHORELINE_PHYSIOGRAPHY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[503].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[504].code.tag, "SHP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].ea_entry.ea_code = EAC_MARINE_BEACON_SHAPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[504].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[505].code.tag, "SIC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].ea_entry.ea_code = EAC_FROZEN_SURFACE_COVER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[505].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[506].code.tag, "SIT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].ea_entry.ea_code = EAC_MARINE_TRAFFIC_SIGNAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[506].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[507].code.tag, "SIZ", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].ea_entry.information = "Deleted (no longer in FACC): \"Font Size used to display ZD040 and ZD045 in points.\"";
    EDCS_FACC_2p1_Attribute_Mapping_Array[507].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[508].code.tag, "SL1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].ea_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<LEFT_BANK_SLOPE>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[508].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[509].code.tag, "SL2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].ea_entry.ea_code = EAC_LEFT_BANK_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<LEFT_BANK_SLOPE>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[509].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[510].code.tag, "SLC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].ea_entry.ea_code = EAC_VESSEL_LOAD_RESTRICTIONS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[510].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[511].code.tag, "SLT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].ea_entry.ea_code = EAC_SHORELINE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[511].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[512].code.tag, "SM1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].ea_entry.ea_code = EAC_SURFICIAL_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[512].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[513].code.tag, "SMC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].ea_entry.ea_code = EAC_SURFACE_MATERIAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[513].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[514].code.tag, "SND", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].ea_entry.ea_code = EAC_SOUNDING_INFORMATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[514].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[515].code.tag, "SOH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].ea_entry.ea_code = EAC_HAZARD_SEVERITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[515].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[516].code.tag, "SOU", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].ea_entry.ea_code = EAC_SOUNDING_EXPOSITION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[516].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[517].code.tag, "SPD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].eu_entry.eu_code = EUC_MILE_PER_HOUR;
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].ea_entry.ea_code = EAC_VEHICULAR_SPEED_LIMIT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].ea_entry.information = "MPH version of <<VEHICULAR_SPEED_LIMIT>> - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[517].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[518].code.tag, "SPE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].ea_entry.ea_code = EAC_SPOT_ELEVATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[518].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[519].code.tag, "SPL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].ea_entry.ea_code = EAC_LONGEST_BRIDGE_SPAN_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[519].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[520].code.tag, "SPM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].eu_entry.eu_code = EUC_METRE_PER_HOUR;
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].eu_entry.es_code = ESC_KILO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].ea_entry.ea_code = EAC_VEHICULAR_SPEED_LIMIT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].ea_entry.information = "KPH version of <<VEHICULAR_SPEED_LIMIT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[520].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[521].code.tag, "SPR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].ea_entry.ea_code = EAC_TERRAIN_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<TERRAIN_SLOPE>>; may also map to <<DISSECTED_TERRAIN>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[521].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[522].code.tag, "SR1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].ea_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<RIGHT_BANK_SLOPE>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[522].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[523].code.tag, "SR2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].ea_entry.ea_code = EAC_RIGHT_BANK_SLOPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<RIGHT_BANK_SLOPE>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[523].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[524].code.tag, "SRD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].ea_entry.ea_code = EAC_TERRAIN_MORPHOLOGY_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[524].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[525].code.tag, "SRQ", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].ea_entry.information = "EDCS 3.1 EA SURFACE_ROUGHNESS_DESCRIPTION_IDENTIFIER was dropped.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[525].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[526].code.tag, "SSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].ea_entry.ea_code = EAC_STRUCTURE_SHAPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[526].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[527].code.tag, "SSR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].ea_entry.ea_code = EAC_ROOF_SHAPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[527].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[528].code.tag, "SST", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].ea_entry.ea_code = EAC_SOUND_SIGNAL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].ea_entry.information = "Mapped to <<SOUND_SIGNAL_PRESENT>> qualified by <<SOUND_SIGNAL_TYPE>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[528].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[529].code.tag, "STA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].ea_entry.information = "Split into <<MARINE_STATION_ACTIVITY>> and <<MARINE_STATION_EQUIPMENT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[529].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[530].code.tag, "STC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].ea_entry.ea_code = EAC_SOURCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[530].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[531].code.tag, "STG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].ea_entry.ea_code = EAC_WET_SOIL_TRAFFICABILITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[531].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[532].code.tag, "STL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].ea_entry.ea_code = EAC_SEASONAL_TENT_LOCATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[532].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[533].code.tag, "STP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].ea_entry.ea_code = EAC_SOIL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[533].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[534].code.tag, "STQ", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].ea_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<SUMMER_CANOPY_COVER_FRACTION>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[534].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[535].code.tag, "STR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].ea_entry.ea_code = EAC_SUMMER_CANOPY_COVER_FRACTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[535].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[536].code.tag, "STY", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].ea_entry.information = "Deleted (no longer in FACC): \"Style of Text: Text style used to display objects identified as NAMED_LOCATION or TEXT_DESCRIPTION.\"";
    EDCS_FACC_2p1_Attribute_Mapping_Array[536].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[537].code.tag, "SUA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].ea_entry.ea_code = EAC_AIRSPACE_ALTITUDE_LIMITS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[537].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[538].code.tag, "SUE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].ea_entry.ea_code = EAC_SURVEY_END_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_YYYYMMDD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[538].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[539].code.tag, "SUP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].ea_entry.ea_code = EAC_LIGHT_SUPERVISED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[539].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[540].code.tag, "SUR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].ea_entry.ea_code = EAC_SURVEY_QUALIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[540].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[541].code.tag, "SUS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].ea_entry.ea_code = EAC_SURVEY_START_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_YYYYMMDD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[541].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[542].code.tag, "SVA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].ea_entry.ea_code = EAC_SLAVED_DECLINATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[542].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[543].code.tag, "SVC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].ea_entry.ea_code = EAC_SOUNDING_VELOCITY_CORRECTION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[543].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[544].code.tag, "SWC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].ea_entry.ea_code = EAC_SOIL_WETNESS_CATEGORY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[544].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[545].code.tag, "SWL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].eu_entry.eu_code = EUC_KILOPOUND;
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].ea_entry.ea_code = EAC_SINGLE_WHEEL_BEARING_LOAD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].ea_entry.information = "KIP - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[545].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[546].code.tag, "SWT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].ea_entry.ea_code = EAC_SPRING_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[546].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[547].code.tag, "TCL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].ea_entry.ea_code = EAC_TREE_CANOPY_LEVEL_COUNT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[547].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[548].code.tag, "TCS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].ea_entry.ea_code = EAC_TUNNEL_CROSS_SECTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[548].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[549].code.tag, "TEC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].ea_entry.ea_code = EAC_SOUNDING_MEASUREMENT_TECHNIQUE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[549].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[550].code.tag, "TEL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].ea_entry.ea_code = EAC_TELESCOPE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[550].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[551].code.tag, "THM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].ea_entry.ea_code = EAC_RUNWAY_TOUCHDOWN_ZONE_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_HIGH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[551].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[552].code.tag, "TID", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].ea_entry.ea_code = EAC_TIDE_INFLUENCED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[552].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[553].code.tag, "TIM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].eu_entry.eu_code = EUC_HOUR;
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].ea_entry.ea_code = EAC_TIME_QUANTITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[553].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[554].code.tag, "TLM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].ea_entry.ea_code = EAC_RUNWAY_TOUCHDOWN_ZONE_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_LOW;
    EDCS_FACC_2p1_Attribute_Mapping_Array[554].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[555].code.tag, "TLN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].ea_entry.ea_code = EAC_TRANSPORTATION_ROUTE_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[555].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[556].code.tag, "TMC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].ea_entry.ea_code = EAC_TOPMARK_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[556].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[557].code.tag, "TNG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].eu_entry.eu_code = EUC_TON;
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].ea_entry.ea_code = EAC_MARINE_TONNAGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].ea_entry.information = "Ton - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[557].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[558].code.tag, "TOP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].ea_entry.ea_code = EAC_TOPMARK_SHAPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[558].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[559].code.tag, "TRA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].ea_entry.ea_code = EAC_PEDESTRIAN_TRAVERSABILITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[559].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[560].code.tag, "TRE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].ea_entry.ea_code = EAC_TREE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[560].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[561].code.tag, "TRF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].ea_entry.ea_code = EAC_VEHICLE_TRAFFIC_FLOW;
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[561].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[562].code.tag, "TRK", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].ea_entry.ea_code = EAC_RECOMMENDED_TRACK;
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[562].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[563].code.tag, "TS1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].ea_entry.ea_code = EAC_TREE_SPACING;
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<TREE_SPACING>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[563].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[564].code.tag, "TS2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].ea_entry.ea_code = EAC_TREE_SPACING;
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<TREE_SPACING>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[564].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[565].code.tag, "TS3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].ea_entry.ea_code = EAC_TREE_SPACING;
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<TREE_SPACING>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[565].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[566].code.tag, "TSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].ea_entry.ea_code = EAC_TREE_SPACING;
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[566].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[567].code.tag, "TSD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].ea_entry.ea_code = EAC_TREE_SPACING;
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].ea_entry.information = "Greater precision version of <<TREE_SPACING>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[567].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[568].code.tag, "TSP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].ea_entry.ea_code = EAC_MARINE_TSS_COMPONENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[568].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[569].code.tag, "TSR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].ea_entry.ea_code = EAC_TERRAIN_MORPHOLOGY_DESCRIPTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[569].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[570].code.tag, "TSS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].ea_entry.ea_code = EAC_TSS_IMO_ADOPTED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].ea_entry.information = "Changed datatype from ENUM to BOOLEAN.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[570].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[571].code.tag, "TST", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].ea_entry.ea_code = EAC_ELEV_ELECTRICAL_CABLE_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[571].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[572].code.tag, "TTC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].ea_entry.ea_code = EAC_TOWER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[572].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[573].code.tag, "TUC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].ea_entry.ea_code = EAC_TRANSPORTATION_USE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[573].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[574].code.tag, "TXT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].ea_entry.ea_code = EAC_ASSOCIATED_TEXT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[574].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[575].code.tag, "TY3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].ea_entry.ea_code = EAC_BENCHMARK_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[575].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[576].code.tag, "TZH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].ea_entry.ea_code = EAC_RUNWAY_TOUCHDOWN_ZONE_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_HIGH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[576].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[577].code.tag, "TZL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].ea_entry.ea_code = EAC_RUNWAY_TOUCHDOWN_ZONE_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_RUNWAY_END;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_RNWYEND_LOW;
    EDCS_FACC_2p1_Attribute_Mapping_Array[577].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[578].code.tag, "UBC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].ea_entry.ea_code = EAC_UNDERBRIDGE_CLEARANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[578].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[579].code.tag, "UBD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].ea_entry.ea_code = EAC_UNDERBRIDGE_CLEARANCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].ea_entry.information = "Greater precision version of <<UNDERBRIDGE_CLEARANCE>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[579].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[580].code.tag, "UID", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].ea_entry.ea_code = EAC_NUMERIC_OBJECT_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[580].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[581].code.tag, "UMC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].ea_entry.ea_code = EAC_UNDERLYING_MATERIAL_CHARACTERISTIC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[581].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[582].code.tag, "UNI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].ea_entry.information = "Deleted (\"Units: Identifies the units of measure. [Reference DIGEST Part 3 for Units associated with DIGEST header data.]\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[582].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[583].code.tag, "USE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].ea_entry.ea_code = EAC_USAGE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].ea_entry.information = "<<USAGE>> has been refactored into a separate set of EA s and has been deprecated. The other EA s are: <<ACCESS_DIRECTION_TYPE>>, <<ACCESSIBILITY_STATUS>>, <<AERONAUTICAL_APPROACH_TYPE>>, <<AERONAUTICAL_FUNCTION>>, <<AERONAUTICAL_POINT_FUNCTION>>, <<AERONAUTICAL_ROUTE_TYPE>>, <<APRON_HARD_STANDING_FUNCTION>>, <<CONTROLLING_AUTHORITY>>, <<DWELLING_TYPE>>, <<FUNCTIONAL_USE>>, <<MARINE_USE>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[583].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[584].code.tag, "USP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].ea_entry.ea_code = EAC_URBAN_STREET_PATTERN;
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[584].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[585].code.tag, "UT1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].ea_entry.information = "Deleted \"UTM Grid Northing\" - need to combine with other UTM attribution to create a complete location specification.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[585].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[586].code.tag, "UT2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].ea_entry.information = "Deleted \"UTM Grid Easting\" - need to combine with other UTM attribution to create a complete location specification.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[586].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[587].code.tag, "UTS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].ea_entry.information = "Deleted \"UTM Square Identification\" - need to combine with other UTM attribution to create a complete location specification.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[587].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[588].code.tag, "UZ1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].ea_entry.information = "Deleted \"UTM Grid Zone (1)\" - need to combine with other UTM attribution to create a complete location specification.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[588].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[589].code.tag, "UZ2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].ea_entry.information = "Deleted \"UTM Grid Zone (2)\" - need to combine with other UTM attribution to create a complete location specification.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[589].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[590].code.tag, "VA1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].ea_entry.ea_code = EAC_MAGNETIC_FIELD_ANOMALY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].ea_entry.information = "Greater precision version of \"Variation Anomaly Value\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[590].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[591].code.tag, "VAL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].ea_entry.information = "Deleted (\"Value: Generic numeric (integer) value.\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[591].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[592].code.tag, "VAV", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].eu_entry.eu_code = EUC_DEGREE_ARC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].ea_entry.ea_code = EAC_MAGNETIC_FIELD_ANOMALY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[592].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[593].code.tag, "VC1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].ea_entry.ea_code = EAC_VERTICAL_CLEARANCE_CLOSED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].ea_entry.information = "Greater precision version of \"Vertical Clearance Closed\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[593].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[594].code.tag, "VC2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].ea_entry.ea_code = EAC_VERTICAL_CLEARANCE_OPENED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].ea_entry.information = "Greater precision version of \"Vertical Clearance Opened\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[594].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[595].code.tag, "VC3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].ea_entry.ea_code = EAC_VERTICAL_CLEARANCE_SAFE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].ea_entry.information = "Greater precision version of \"Vertical Clearance Safe\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[595].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[596].code.tag, "VCA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].ea_entry.ea_code = EAC_DATA_COLLECTION_CRITERIA;
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].ea_entry.information = "Equivalent to \"Collection Attribute Category\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[596].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[597].code.tag, "VCC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].ea_entry.ea_code = EAC_VERTICAL_CLEARANCE_CLOSED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[597].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[598].code.tag, "VCO", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].ea_entry.ea_code = EAC_VERTICAL_CLEARANCE_OPENED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[598].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[599].code.tag, "VCS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].ea_entry.ea_code = EAC_VERTICAL_CLEARANCE_SAFE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[599].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[600].code.tag, "VCT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].ea_entry.ea_code = EAC_MISSING_INFORMATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[600].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[601].code.tag, "VDC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].ea_entry.map_type = FACC_MAP_TYP_SPECIAL_CASE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].ea_entry.ea_code = EAC_SOUNDING_DATUM_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].ea_entry.information = "Sometimes maps to <<VERTICAL_DATUM_IDENTIFIER>>, depending on enumerant.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[601].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[602].code.tag, "VEC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].ea_entry.ea_code = EAC_VEHICLE_CAPACITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[602].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[603].code.tag, "VEG", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].ea_entry.ea_code = EAC_VEGETATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[603].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[604].code.tag, "VEM", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].ea_entry.ea_code = EAC_VERTICAL_MEASUREMENT_QUALITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[604].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[605].code.tag, "VGT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].ea_entry.ea_code = EAC_VOLCANIC_FORMATION_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[605].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[606].code.tag, "VH1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].ea_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<PREDOMINANT_VEGETATION_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[606].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[607].code.tag, "VH2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].ea_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<PREDOMINANT_VEGETATION_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[607].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[608].code.tag, "VH3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].ea_entry.ea_code = EAC_PREDOMINANT_VEGETATION_HEIGHT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<PREDOMINANT_VEGETATION_HEIGHT>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[608].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[609].code.tag, "VIS", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].ea_entry.ea_code = EAC_LIGHT_VISIBILITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[609].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[610].code.tag, "VOI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].ea_entry.information = "Can be mapped to <<NAME>> by changing datatype from CONSTRAINED_STRING to STRING.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[610].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[611].code.tag, "VRC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].ea_entry.ea_code = EAC_VEGETATION_RESTRICTED_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[611].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[612].code.tag, "VRF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].ea_entry.ea_code = EAC_VISUAL_REFLECTOR_PRESENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[612].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[613].code.tag, "VRR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].ea_entry.ea_code = EAC_HYDROGRAPHIC_DEPTH_CATEGORY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[613].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[614].code.tag, "WD1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].ea_entry.ea_code = EAC_ROAD_MINIMUM_TRAVELLED_WAY_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[614].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[615].code.tag, "WD2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].ea_entry.ea_code = EAC_ROAD_TOTAL_USABLE_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[615].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[616].code.tag, "WD3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].ea_entry.ea_code = EAC_TERRAIN_GAP_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[616].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[617].code.tag, "WD4", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].ea_entry.ea_code = EAC_WET_GAP_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[617].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[618].code.tag, "WD5", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].ea_entry.ea_code = EAC_TOP_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[618].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[619].code.tag, "WD6", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].ea_entry.ea_code = EAC_BOTTOM_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[619].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[620].code.tag, "WDA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].ea_entry.ea_code = EAC_MEAN_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[620].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[621].code.tag, "WDT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].ea_entry.ea_code = EAC_NON_SUB_CONTACT_DATE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].ea_entry.num_entries = 1;
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].ea_entry.information = "";

    temp_entries = (EDCS_Mapping_Entry *) calloc(1, sizeof(EDCS_Mapping_Entry));

    if (temp_entries == NULL)
    {
         fprintf(stderr, "Fatal Error: Unable to allocate memory for mapping entry.\n");
         return EDCS_SC_OTHER_FAILURE;
    }
    temp_entries[0].type = EDCS_MAP_ENTRY_TYP_ATTR_VAL;
    temp_entries[0].u.attr_value_entry.ea_code = EAC_DATE_FORMAT;
    temp_entries[0].u.attr_value_entry.ea_value.attribute_value_type = EDCS_AVT_ENUMERATION;
    temp_entries[0].u.attr_value_entry.ea_value.value.enumeration_value = EEC_DATEFMT_YYYYMMDD;
    EDCS_FACC_2p1_Attribute_Mapping_Array[621].ea_entry.entry_list = temp_entries;

    temp_entries = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[622].code.tag, "WFT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].ea_entry.ea_code = EAC_WELL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[622].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[623].code.tag, "WGF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].ea_entry.ea_code = EAC_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].ea_entry.information = "Feet version of \"Width\" - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[623].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[624].code.tag, "WGP", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].ea_entry.ea_code = EAC_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].ea_entry.information = "Greater precision version of \"Width\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[624].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[625].code.tag, "WID", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].ea_entry.ea_code = EAC_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[625].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[626].code.tag, "WKT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].ea_entry.ea_code = EAC_MARINE_WRECK_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[626].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[627].code.tag, "WLE", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].ea_entry.ea_code = EAC_WATER_LEVEL_EFFECT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[627].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[628].code.tag, "WOC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].ea_entry.ea_code = EAC_TERRAIN_CREST_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[628].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[629].code.tag, "WPC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].ea_entry.ea_code = EAC_WORK_IN_PROGRESS_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[629].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[630].code.tag, "WPI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].ea_entry.ea_code = EAC_MARINE_PORT_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[630].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[631].code.tag, "WPT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].ea_entry.ea_code = EAC_WAYPOINT_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[631].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[632].code.tag, "WRK", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].ea_entry.ea_code = EAC_MARINE_WRECK_STATUS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[632].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[633].code.tag, "WRN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].eu_entry.eu_code = EUC_UNITLESS;
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].ea_entry.ea_code = EAC_NON_SUB_CONTACT_WRECK_IDENTIFIER;
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[633].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[634].code.tag, "WSC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].ea_entry.ea_code = EAC_SCRAP_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[634].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[635].code.tag, "WSR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].ea_entry.ea_code = EAC_NON_SUB_CONTACT_SOURCE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[635].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[636].code.tag, "WT2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].eu_entry.es_code = ESC_DECI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].ea_entry.ea_code = EAC_ROAD_SECOND_TRAVELLED_WAY_WIDTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[636].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[637].code.tag, "WTC", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].ea_entry.ea_code = EAC_LAND_ROUTE_USABLE_WEATHER_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[637].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[638].code.tag, "WTI", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].ea_entry.ea_code = EAC_WALL_TYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[638].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[639].code.tag, "WTR", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].eu_entry.eu_code = EUC_PERCENT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].ea_entry.ea_code = EAC_WINTER_CANOPY_COVER_FRACTION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[639].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[640].code.tag, "WV1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].eu_entry.eu_code = EUC_METRE_PER_SEC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].ea_entry.ea_code = EAC_MEAN_WATER_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].ea_entry.information = "Changed datatype from ENUM to REAL and used intervals of <<MEAN_WATER_SPEED>>.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[640].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[641].code.tag, "WVA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].eu_entry.eu_code = EUC_METRE_PER_SEC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].ea_entry.ea_code = EAC_MEAN_WATER_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[641].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[642].code.tag, "XPD", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].ea_entry.information = "Deleted (\"Display Mode\").";
    EDCS_FACC_2p1_Attribute_Mapping_Array[642].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[643].code.tag, "XSA", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ZERO;
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].ea_entry.ea_code = ((EDCS_Attribute_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].ea_entry.information = "Deprecated in FACC.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[643].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[644].code.tag, "YDH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].ea_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[644].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[645].code.tag, "YDL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].ea_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[645].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[646].code.tag, "YLN", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].ea_entry.ea_code = EAC_LENGTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].ea_entry.information = "Greater precision metre version of \"Length / Diameter\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[646].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[647].code.tag, "YSU", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].ea_entry.ea_code = EAC_SERVICE_BRANCH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[647].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[648].code.tag, "YVH", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].eu_entry.eu_code = EUC_METRE_PER_SEC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].ea_entry.ea_code = EAC_MEAN_SSNL_HIGH_WATER_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[648].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[649].code.tag, "YVL", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].eu_entry.eu_code = EUC_METRE_PER_SEC;
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].ea_entry.ea_code = EAC_MEAN_SSNL_LOW_WATER_SPEED;
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[649].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[650].code.tag, "YWQ", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].eu_entry.map_type = ((FACC_2p1_Mapping_Type_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].eu_entry.eu_code = ((EDCS_Unit_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].eu_entry.es_code = ((EDCS_Unit_Scale_Code)0);
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].ea_entry.ea_code = EAC_WATER_QUALITY;
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[650].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[651].code.tag, "YWT", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].ea_entry.map_type = FACC_MAP_TYP_CHANGE_IN_DATATYPE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].ea_entry.ea_code = EAC_WATER_TABLE_DEPTH;
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].ea_entry.information = "Changed datatype from ENUM to REAL.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[651].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[652].code.tag, "ZV1", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].ea_entry.ea_code = EAC_LOWEST_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[652].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[653].code.tag, "ZV2", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].ea_entry.ea_code = EAC_HIGHEST_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[653].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[654].code.tag, "ZV3", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].ea_entry.ea_code = EAC_AERODROME_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].ea_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[654].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[655].code.tag, "ZV6", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].ea_entry.ea_code = EAC_LOWEST_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].ea_entry.information = "Greater precision metre version of \"Lowest Elevation of Object\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[655].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[656].code.tag, "ZV7", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].eu_entry.eu_code = EUC_METRE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].ea_entry.ea_code = EAC_HIGHEST_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].ea_entry.information = "Greater precision metre version of \"Highest Elevation of Object\".";
    EDCS_FACC_2p1_Attribute_Mapping_Array[656].ea_entry.entry_list = NULL;

    strncpy(EDCS_FACC_2p1_Attribute_Mapping_Array[657].code.tag, "ZVF", 3);
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].eu_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].eu_entry.eu_code = EUC_FOOT;
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].eu_entry.es_code = ESC_UNI;
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].eu_entry.information = "";
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].ea_entry.map_type = FACC_MAP_TYP_ONE_TO_ONE;
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].ea_entry.ea_code = EAC_HIGHEST_ELEVATION;
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].ea_entry.num_entries = 0;
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].ea_entry.information = "Foot version of \"Highest Elevation of Object\" - do not need to convert.";
    EDCS_FACC_2p1_Attribute_Mapping_Array[657].ea_entry.entry_list = NULL;


    if (status == EDCS_SC_SUCCESS)
    {
        qsort( EDCS_FACC_2p1_Attribute_Mapping_Array,
               EDCS_FACC_ATTRIBUTE_MAPPING_COUNT,
               sizeof(EDCS_FACC_2p1_Attribute_Mapping),
               (int(*)(const void*, const void*))
               local_CompareAttr_Mapping
             );
    }
    return status;
} /* end local_init_facc_attribute_mapping */

static void
local_shutdown_facc_attribute_mapping( void )
{
    int i;

    for(i = 0; i < EDCS_FACC_ATTRIBUTE_MAPPING_COUNT; i++)
    {
        if(EDCS_FACC_2p1_Attribute_Mapping_Array[i].ea_entry.entry_list)
        {
            free(EDCS_FACC_2p1_Attribute_Mapping_Array[i].ea_entry.entry_list);
        }
    }
}

extern EDCS_Status_Code local_init_facc_attribute_enum_mapping_pt1( void );
extern EDCS_Status_Code local_init_facc_attribute_enum_mapping_pt2( void );
extern EDCS_Status_Code local_init_facc_attribute_enum_mapping_pt3( void );
extern EDCS_Status_Code local_init_facc_attribute_enum_mapping_pt4( void );
extern EDCS_Status_Code local_init_facc_attribute_enum_mapping_pt5( void );
extern EDCS_Status_Code local_init_facc_attribute_enum_mapping_pt6( void );
extern EDCS_Status_Code local_init_facc_attribute_enum_mapping_pt7( void );

static EDCS_Status_Code
local_init_facc_attribute_enum_mapping( void )
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if((status = local_init_facc_attribute_enum_mapping_pt1()) != EDCS_SC_SUCCESS)
    {
        return status;
    }
    else if ((status = local_init_facc_attribute_enum_mapping_pt2())
             != EDCS_SC_SUCCESS)
    {
        return status;
    }
    else if ((status = local_init_facc_attribute_enum_mapping_pt3())
             != EDCS_SC_SUCCESS)
    {
        return status;
    }
    else if ((status = local_init_facc_attribute_enum_mapping_pt4())
             != EDCS_SC_SUCCESS)
    {
        return status;
    }
    else if ((status = local_init_facc_attribute_enum_mapping_pt5())
            != EDCS_SC_SUCCESS)
    {
        return status;
    }
    else if ((status = local_init_facc_attribute_enum_mapping_pt6())
            != EDCS_SC_SUCCESS)
    {
        return status;
    }
    else if ((status = local_init_facc_attribute_enum_mapping_pt7())
            != EDCS_SC_SUCCESS)
    {
        return status;
    }
    qsort(EDCS_FACC_2p1_Enumerant_Mapping_Array,
          EDCS_FACC_ATTR_ENUM_MAPPING_COUNT,
          sizeof(EDCS_FACC_2p1_Enumerant_Mapping),
          (int(*)(const void*, const void*))
          local_Compare_FACC_Enum_Mapping
         );

    return status;
} /* end local_init_facc_attribute_enum_mapping */

static void
local_shutdown_facc_attribute_enum_mapping( void )
{
    int i;

    for(i = 0; i < EDCS_FACC_ATTR_ENUM_MAPPING_COUNT; i++)
    {
        if(EDCS_FACC_2p1_Enumerant_Mapping_Array[i].entry.entry_list)
        {
            free(EDCS_FACC_2p1_Enumerant_Mapping_Array[i].entry.entry_list);
        }
    }
}

EDCS_Status_Code
EDCS_InitFACC_2p1_MappingInfo( void )
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if ((status = local_init_facc_feature_mapping()) == EDCS_SC_SUCCESS)
    {
        if((status = local_init_facc_attribute_mapping()) == EDCS_SC_SUCCESS)
        {
            if((status = local_init_facc_attribute_enum_mapping()) == EDCS_SC_SUCCESS)
            {
                facc_2p1_mapping_initialized = EDCS_TRUE;
            }
            else
            {
                local_shutdown_facc_feature_mapping();
                local_shutdown_facc_attribute_mapping();
            }
        }
        else
        {
            local_shutdown_facc_feature_mapping();
        }
    }
    return status;
} /* end EDCS_InitFACC_2p1_MappingInfo */

EDCS_Status_Code
EDCS_ShutdownFACC_2p1_MappingInfo( void )
{
    if(facc_2p1_mapping_initialized)
    {
        local_shutdown_facc_feature_mapping();
        local_shutdown_facc_attribute_mapping();
        local_shutdown_facc_attribute_enum_mapping();
        facc_2p1_mapping_initialized = EDCS_FALSE;
    }
    return EDCS_TRUE;
}

EDCS_Status_Code
EDCS_MapFACC_2p1_FeatureCode
(
    const FACC_2p1_Feature_Code                * facc_in_ptr,
    const FACC_2p1_Class_Mapping_Structure ** mapping_info_out_ptr
)
{
    EDCS_Status_Code        status = EDCS_SC_SUCCESS;
    EDCS_FACC_2p1_Class_Mapping *search_result_ptr = NULL;
    EDCS_FACC_2p1_Class_Mapping  target;

    if (!facc_in_ptr || !mapping_info_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if(!facc_2p1_mapping_initialized)
    {
        fprintf(stderr, "Error: must call EDCS_InitFACC_2p1_MappingInfo() before using this function\n");
        return EDCS_SC_OTHER_FAILURE;
    }
    else
    {
        *mapping_info_out_ptr = NULL;
        memcpy(&target.code, facc_in_ptr, sizeof(FACC_2p1_Feature_Code));

        search_result_ptr = (EDCS_FACC_2p1_Class_Mapping *)
                            bsearch
                            (
                                &target,
                                EDCS_FACC_2p1_Class_Mapping_Array,
                                EDCS_FACC_CLASS_MAPPING_COUNT,
                                sizeof(EDCS_FACC_2p1_Class_Mapping),
                                (int(*)(const void*,const void *))
                                local_CompareFeature_Mapping
                            );

        if (search_result_ptr)
        {
            *mapping_info_out_ptr = &(search_result_ptr->entry);
        }
        else
        {
            status = EDCS_SC_INVALID_INPUT_CODE;
        }
    }
    return status;
}

EDCS_Status_Code
EDCS_MapFACC_2p1_AttributeCode
(
    const FACC_2p1_Attribute_Code               * facc_in_ptr,
    const FACC_2p1_Unit_Mapping_Structure      ** unit_mapping_info_out_ptr,
    const FACC_2p1_Attribute_Mapping_Structure ** mapping_info_out_ptr
)
{
    EDCS_Status_Code  status = EDCS_SC_SUCCESS;
    EDCS_FACC_2p1_Attribute_Mapping *search_result_ptr;
    EDCS_FACC_2p1_Attribute_Mapping target;

    if (!facc_in_ptr || !mapping_info_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if(!facc_2p1_mapping_initialized)
    {
        fprintf(stderr, "Error: must call EDCS_InitFACC_2p1_MappingInfo() before using this function\n");
        return EDCS_SC_OTHER_FAILURE;
    }
    else
    {
        *mapping_info_out_ptr = NULL;
        *unit_mapping_info_out_ptr = NULL;
        memcpy(&target.code, facc_in_ptr, sizeof(FACC_2p1_Attribute_Code));

        search_result_ptr = (EDCS_FACC_2p1_Attribute_Mapping *)
                            bsearch
                            (
                                &target,
                                EDCS_FACC_2p1_Attribute_Mapping_Array,
                                EDCS_FACC_ATTRIBUTE_MAPPING_COUNT,
                                sizeof(EDCS_FACC_2p1_Attribute_Mapping),
                                (int(*)(const void*,const void *))
                                local_CompareAttr_Mapping
                            );

        if (search_result_ptr)
        {
            *mapping_info_out_ptr = &(search_result_ptr->ea_entry);
            if(search_result_ptr->eu_entry.map_type != 0)
            {
                *unit_mapping_info_out_ptr = &(search_result_ptr->eu_entry);
            }
        }
        else
        {
            status = EDCS_SC_INVALID_INPUT_CODE;
        }
    }
    return status;
}

EDCS_Status_Code
EDCS_MapFACC_2p1_AttributeIntegerCode
(
    const FACC_2p1_Attribute_Code           * fac_code_in_ptr,
    const FACC_2p1_Attribute_Integer_Code     fac_enum_code_in,
    const FACC_2p1_Enumerant_Mapping_Structure ** mapping_info_out_ptr
)
{
    EDCS_Status_Code  status = EDCS_SC_SUCCESS;
    EDCS_FACC_2p1_Enumerant_Mapping *search_result_ptr;
    EDCS_FACC_2p1_Enumerant_Mapping target;

    if (!fac_code_in_ptr || !mapping_info_out_ptr )
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if(!facc_2p1_mapping_initialized)
    {
        fprintf(stderr, "Error: must call EDCS_InitFACC_2p1_MappingInfo() before using this function\n");
        return EDCS_SC_OTHER_FAILURE;
    }
    else
    {
        *mapping_info_out_ptr = NULL;
        memcpy(&target.code, fac_code_in_ptr, sizeof(FACC_2p1_Attribute_Code));
        target.enum_val = fac_enum_code_in;

        search_result_ptr = (EDCS_FACC_2p1_Enumerant_Mapping *)
                            bsearch
                            (
                                &target,
                                EDCS_FACC_2p1_Enumerant_Mapping_Array,
                                EDCS_FACC_ATTR_ENUM_MAPPING_COUNT,
                                sizeof(EDCS_FACC_2p1_Enumerant_Mapping),
                                (int(*)(const void*,const void *))
                                local_Compare_FACC_Enum_Mapping
                            );

        if (search_result_ptr)
        {
            *mapping_info_out_ptr = &(search_result_ptr->entry);
        }
        else
        {
            status = EDCS_SC_INVALID_INPUT_CODE;
        }
    }
    return status;
} /* end EDCS_MapFACC_2p1_AttributeIntegerCode*/

const char *
EDCS_MapFACC_2p1_GetLibVersion
(
    void
)
{
    return "4.3.2.0";
}
