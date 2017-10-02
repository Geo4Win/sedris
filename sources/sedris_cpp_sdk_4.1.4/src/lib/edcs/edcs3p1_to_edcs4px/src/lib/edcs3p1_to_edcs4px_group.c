/*
 * FILE       : edcs3p1_to_edcs4px_group.c
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all EGs.
 *
 *      *** IMPORTANT NOTE ***
 *      This file is generated automatically from the EDCS database tables using
 *      the EDCS Code Generator.  DO NOT MODIFY THIS FILE BY HAND.  Changes should
 *      be made in the EDCS database and EDCS Code generator templates, and will be
 *      reflected in this file when the system is rebuilt.
 *
 * EDCS SDK Release 4.4.0 - July 1, 2011
 * - EDCS spec. 4.4
 *
 * HISTORY:
 *  Release     Date          Notes
 *  1.34   09/17/98
 * Initial release of SAC codes
 *  1.41   10/27/98
 * Update to support Mesh Tables and 2.0 alpha release.
 *  1.95   12/07/98
 * Update to support FACC 2.0a and 2.0 beta release
 *                    (internal use only).
 *  2.00   01/04/99
 * Final update for 2.0 SDK public release.
 *  2.50   07/13/99
 * Update for 2.5 public release
 *  0.09   10/05/99
 * Update for 2.5.2 internal release (mainly minor bug-fixes)
 *  0.09   12/12/99
 * Update for 2.5.3 internal release (mainly TOWAN and ASEA support)
 *  WD3   05/15/00
 * Update for ISO 3rd WD
 *  2.70   06/16/00
 * Update for SEDRIS 3.0 internal release (many inputs)
 *  WD4   11/06/00
 * Update for ISO 4th WD
 *  2.80   02/17/01
 * Update for SEDRIS post-3.0.2 internal release (mainly TSGA support)
 *  2.90   03/16/01
 * Update for SEDRIS 3.0.3 internal release (correct erroneous "S"-based EACs in previous release header files)
 *  WD5   06/04/01
 * Update for ISO 5th WD
 *  CD   12/20/01
 * Update for ISO CD
 *  FCD   08/26/02
 * Update for ISO FCD
 *  FDIS   10/31/03
 * Update for ISO FDIS
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

#include "edcs3p1_to_edcs4px.h"
#include "edcs3p1_to_edcs4px_internal.h"

#define EDCS_3P1_TOTAL_EG 55

static EDCS_3p1_4px_Group_Mapping_Structure
EDCS_3p1_4px_Group_Mappings[] =
{
    { 1, "ABSTRACT_CONCEPT",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_ABSTRACT_OBJECT,
    "" },
    { 2, "ABSTRACTION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_PROPERTY_SET,
    "" },
    { 3, "ACOUSTIC_PHENOMENON",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_ACOUSTIC_PHENOMENON,
    "" },
    { 4, "ADMINISTRATION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_ADMINISTRATION,
    "" },
    { 5, "AGRICULTURE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_AGRICULTURE,
    "" },
    { 6, "AIR_TRNSP",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_AIR_TRNSP,
    "" },
    { 7, "AIRBORNE_PARTICLE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_AIRBORNE_PARTICLE,
    "" },
    { 8, "ALGORITHM_RELATED",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_ALGORITHM_RELATED,
    "" },
    { 9, "ANCILLARY_ARTEFACT",
      EDCS_MAPPING_TYP_ONE_TO_ZERO, 0,
    "" },
    { 10, "ANGULAR_MEASURE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_ANGULAR_MEASURE,
    "" },
    { 11, "ANIMAL",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_ANIMAL,
    "" },
    { 12, "ATMOSPHERE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_ATMOSPHERE,
    "" },
    { 13, "BATHYMETRY",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_WATERBODY_FLOOR,
    "" },
    { 14, "COLOUR",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_COLOUR,
    "" },
    { 15, "COMMUNICATION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_COMMUNICATION,
    "" },
    { 16, "DEMARCATION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_DEMARCATION,
    "" },
    { 17, "DIMENSION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_DIMENSION,
    "" },
    { 18, "EM_PHENOMENON",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_EM_PHENOMENON,
    "" },
    { 19, "HARBOUR_AND_PORT",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_HARBOUR_AND_PORT,
    "" },
    { 20, "HYDROGRAPHIC_ARTEFACT",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_HYDROGRAPHIC_ARTEFACT,
    "" },
    { 21, "HYDROGRAPHIC_INDUSTRY",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_HYDROGRAPHIC_INDUSTRY,
    "" },
    { 22, "HYDROGRAPHIC_TRNSP",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_HYDROGRAPHIC_TRNSP,
    "" },
    { 23, "HYDROLOGY",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_HYDROLOGY,
    "" },
    { 24, "ICE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_ICE,
    "" },
    { 25, "INFRASTRUCTURE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_INFRASTRUCTURE,
    "" },
    { 26, "LAND_INDUSTRY",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_LAND_INDUSTRY,
    "" },
    { 27, "LAND_TRNSP",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_LAND_TRNSP,
    "" },
    { 28, "LIGHTING_AND_VISIBILITY",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_LIGHTING_AND_VISIBILITY,
    "" },
    { 29, "LITTORAL",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_LITTORAL,
    "" },
    { 30, "LIVING_ORGANISM",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_LIVING_ORGANISM,
    "" },
    { 31, "MILITARY_SCIENCE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_MILITARY_SCIENCE,
    "" },
    { 32, "PHYSIOGRAPHY",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_PHYSIOGRAPHY,
    "" },
    { 33, "PLANT",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_PLANT,
    "" },
    { 34, "POSITION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_LOCATION,
    "" },
    { 35, "RATE_OR_RATIO",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_RATE_OR_RATIO,
    "" },
    { 36, "RECREATION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_RECREATION,
    "" },
    { 37, "SHELTER",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_SHELTER,
    "" },
    { 38, "SPACE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_SPACE,
    "" },
    { 39, "SURFACE_MATERIAL",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_SURFACE_MATERIAL,
    "" },
    { 40, "SURVEY",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_SURVEY,
    "" },
    { 41, "TEMPERATURE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_TEMPERATURE,
    "" },
    { 42, "TIME",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_TIME,
    "" },
    { 43, "USAGE_REGION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_USAGE_REGION,
    "" },
    { 44, "VEHICLE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_VEHICLE,
    "" },
    { 45, "WATER_BODY_CONDITION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_WATERBODY_STATE,
    "" },
    { 46, "WATER_BODY_FLOOR",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_WATERBODY_FLOOR,
    "" },
    { 47, "WATER_BODY_SURFACE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_WATERBODY_SURFACE,
    "" },
    { 48, "BUILDING_COMPONENT",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_BUILDING_COMPONENT,
    "" },
    { 49, "TRNSP",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_TRNSP,
    "" },
    { 50, "WATER_BODY_STATE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_WATERBODY_STATE,
    "" },
    { 51, "SUPPORT_STRUCTURE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_SUPPORT_STRUCTURE,
    "" },
    { 52, "MATERIAL",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_MATERIAL,
    "" },
    { 53, "LOCATION",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_LOCATION,
    "" },
    { 54, "SURFACE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_SURFACE,
    "" },
    { 55, "PROPERTY_SET",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EGC_GEN_PROPERTY_SET,
    "" }
}; /* EDCS_3p1_4px_Group_Mappings */

typedef struct
{
    const EDCS_Character *label_3p1;
          EDCS_Integer  code_3p1;
} EDCS_3p1_EG_Label_Entry;

static const EDCS_3p1_EG_Label_Entry
EDCS_3p1_EG_Label_Array[] =
{
     { "ABSTRACT_CONCEPT", 1 },
     { "ABSTRACTION", 2 },
     { "ACOUSTIC_PHENOMENON", 3 },
     { "ADMINISTRATION", 4 },
     { "AGRICULTURE", 5 },
     { "AIR_TRNSP", 6 },
     { "AIRBORNE_PARTICLE", 7 },
     { "ALGORITHM_RELATED", 8 },
     { "ANCILLARY_ARTEFACT", 9 },
     { "ANGULAR_MEASURE", 10 },
     { "ANIMAL", 11 },
     { "ATMOSPHERE", 12 },
     { "BATHYMETRY", 13 },
     { "BUILDING_COMPONENT", 48 },
     { "COLOUR", 14 },
     { "COMMUNICATION", 15 },
     { "DEMARCATION", 16 },
     { "DIMENSION", 17 },
     { "EM_PHENOMENON", 18 },
     { "HARBOUR_AND_PORT", 19 },
     { "HYDROGRAPHIC_ARTEFACT", 20 },
     { "HYDROGRAPHIC_INDUSTRY", 21 },
     { "HYDROGRAPHIC_TRNSP", 22 },
     { "HYDROLOGY", 23 },
     { "ICE", 24 },
     { "INFRASTRUCTURE", 25 },
     { "LAND_INDUSTRY", 26 },
     { "LAND_TRNSP", 27 },
     { "LIGHTING_AND_VISIBILITY", 28 },
     { "LITTORAL", 29 },
     { "LIVING_ORGANISM", 30 },
     { "LOCATION", 53 },
     { "MATERIAL", 52 },
     { "MILITARY_SCIENCE", 31 },
     { "PHYSIOGRAPHY", 32 },
     { "PLANT", 33 },
     { "POSITION", 34 },
     { "PROPERTY_SET", 55 },
     { "RATE_OR_RATIO", 35 },
     { "RECREATION", 36 },
     { "SHELTER", 37 },
     { "SPACE", 38 },
     { "SUPPORT_STRUCTURE", 51 },
     { "SURFACE", 54 },
     { "SURFACE_MATERIAL", 39 },
     { "SURVEY", 40 },
     { "TEMPERATURE", 41 },
     { "TIME", 42 },
     { "TRNSP", 49 },
     { "USAGE_REGION", 43 },
     { "VEHICLE", 44 },
     { "WATER_BODY_CONDITION", 45 },
     { "WATER_BODY_FLOOR", 46 },
     { "WATER_BODY_STATE", 50 },
     { "WATER_BODY_SURFACE", 47 }
}; /* EDCS_3p1_EG_Label_Array[] */


EDCS_Status_Code
EDCS_Map3p1GroupCode
(
          EDCS_Integer                           eg_3p1_code_in,
    const EDCS_3p1_4px_Group_Mapping_Structure **mapping_info_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!mapping_info_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!edcs_mapping_initialized)
    {
        fprintf(stderr, "Error: must call EDCS_Init3p1MappingInfo() before using this function\n");
        status = EDCS_SC_OTHER_FAILURE;
    }
    else if (eg_3p1_code_in < 1 || eg_3p1_code_in > EDCS_3P1_TOTAL_EG)    
    {
        *mapping_info_out_ptr = NULL;
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *mapping_info_out_ptr = &(EDCS_3p1_4px_Group_Mappings[eg_3p1_code_in-1]);
    }
    return status;
} /* end EDCS_Map3p1GroupCode */

static int
local_Compare3p1EGLabel
(
    const EDCS_3p1_EG_Label_Entry *a_ptr,
    const EDCS_3p1_EG_Label_Entry *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;

    result = edcs_internal_strcmp(a_ptr->label_3p1, b_ptr->label_3p1);
    return result;
} /* end local_Compare3p1EGLabel */

EDCS_Status_Code
EDCS_3p1GroupCodeFromLabel
(
    const char         *eg_3p1_label_in,
          EDCS_Integer *eg_3p1_code_out 
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;
    EDCS_3p1_EG_Label_Entry *search_result_ptr = NULL, target;

    if (!eg_3p1_code_out)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!eg_3p1_label_in)
    {
        *eg_3p1_code_out = 0;
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!edcs_mapping_initialized)
    {
        fprintf(stderr, "Error: must call EDCS_Init3p1MappingInfo() before using this function\n");
        status = EDCS_SC_OTHER_FAILURE;
    }
    else
    {
        target.label_3p1  = eg_3p1_label_in;
        search_result_ptr = (EDCS_3p1_EG_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_3p1_EG_Label_Array,
                               EDCS_3P1_TOTAL_EG,
                               sizeof(EDCS_3p1_EG_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_Compare3p1EGLabel
                            );

        if (search_result_ptr)
        {
            *eg_3p1_code_out = search_result_ptr->code_3p1;
        }
        else
        {
            status = EDCS_SC_INVALID_INPUT_LABEL;
        }
    }
    return status;
} /* end EDCS_3p1GroupCodeFromLabel */

EDCS_Status_Code
EDCS_Map3p1GroupLabel
(
    const char                                  *eg_3p1_label_in,
    const EDCS_3p1_4px_Group_Mapping_Structure **mapping_info_out_ptr 
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!mapping_info_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!eg_3p1_label_in)
    {
        *mapping_info_out_ptr = NULL;
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!edcs_mapping_initialized)
    {
        fprintf(stderr, "Error: must call EDCS_Init3p1MappingInfo() before using this function\n");
        status = EDCS_SC_OTHER_FAILURE;
    }
    else
    {
        EDCS_Integer eg_code;

        status = EDCS_3p1GroupCodeFromLabel( eg_3p1_label_in, &eg_code);

        if (status == EDCS_SC_SUCCESS)
        {
            status = EDCS_Map3p1GroupCode( eg_code, mapping_info_out_ptr);
        }
    }
    return status;
} /* end EDCS_Map3p1GroupLabel */
