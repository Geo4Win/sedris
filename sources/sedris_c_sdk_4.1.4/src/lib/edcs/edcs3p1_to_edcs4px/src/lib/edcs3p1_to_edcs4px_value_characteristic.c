/*
 * FILE       : edcs3p1_to_edcs4px_value_characteristic.c
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all EVs.
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

#define EDCS_3P1_TOTAL_EV 18

static EDCS_3p1_4px_Characteristic_Mapping_Structure
EDCS_3p1_4px_EV_Mappings[] =
{
    { 1, "VALUE_SPECIFIED",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_VALUE_SPECIFIED,
    "" },
    { 2, "MISSING",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_MISSING,
    "" },
    { 3, "MULTIPLE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_MULTIPLE,
    "" },
    { 4, "NOT_APPLICABLE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_NOT_APPLICABLE,
    "" },
    { 5, "VALUE_WITHHELD",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_VALUE_WITHHELD,
    "" },
    { 6, "UNDESIGNATED",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_UNDESIGNATED,
    "" },
    { 7, "POSITIVE_OVERFLOW",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_POSITIVE_OVERFLOW,
    "" },
    { 8, "NEGATIVE_OVERFLOW",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_NEGATIVE_OVERFLOW,
    "" },
    { 9, "POSITIVE_UNDERFLOW",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_POSITIVE_UNDERFLOW,
    "" },
    { 10, "NEGATIVE_UNDERFLOW",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_NEGATIVE_UNDERFLOW,
    "" },
    { 11, "CONSTANT_VALUE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_CONSTANT_VALUE,
    "" },
    { 12, "SIGNIFICANT_DIGITS",
      EDCS_MAPPING_TYP_ONE_TO_ZERO, 0,
    "No mapping" },
    { 13, "TOLERANCE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_TOLERANCE,
    "" },
    { 14, "MAXIMUM_VALUE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_MAXIMUM_VALUE,
    "" },
    { 15, "MINIMUM_VALUE",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_MINIMUM_VALUE,
    "" },
    { 16, "UPPER_BOUND",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_UPPER_BOUND,
    "" },
    { 17, "LOWER_BOUND",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_LOWER_BOUND,
    "" },
    { 18, "MEASUREMENT_ERROR",
      EDCS_MAPPING_TYP_ONE_TO_ONE, EVC_MEASUREMENT_ERROR,
    "" }
}; /* EDCS_3p1_4px_EV_Mappings */

typedef struct
{
    const EDCS_Character *label_3p1;
          EDCS_Integer    code_3p1;
} EDCS_3p1_EV_Label_Entry;

static const EDCS_3p1_EV_Label_Entry
EDCS_3p1_EV_Label_Array[] =
{
     { "CONSTANT_VALUE", 11 },
     { "LOWER_BOUND", 17 },
     { "MAXIMUM_VALUE", 14 },
     { "MEASUREMENT_ERROR", 18 },
     { "MINIMUM_VALUE", 15 },
     { "MISSING", 2 },
     { "MULTIPLE", 3 },
     { "NEGATIVE_OVERFLOW", 8 },
     { "NEGATIVE_UNDERFLOW", 10 },
     { "NOT_APPLICABLE", 4 },
     { "POSITIVE_OVERFLOW", 7 },
     { "POSITIVE_UNDERFLOW", 9 },
     { "SIGNIFICANT_DIGITS", 12 },
     { "TOLERANCE", 13 },
     { "UNDESIGNATED", 6 },
     { "UPPER_BOUND", 16 },
     { "VALUE_SPECIFIED", 1 },
     { "VALUE_WITHHELD", 5 }
}; /* EDCS_3p1_EV_Label_Array[] */


EDCS_Status_Code
EDCS_Map3p1CharacteristicCode
(
          EDCS_Integer                      ev_3p1_code_in,
    const EDCS_3p1_4px_Characteristic_Mapping_Structure **mapping_info_out_ptr
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
    else if (ev_3p1_code_in < 1 || ev_3p1_code_in > EDCS_3P1_TOTAL_EV)
    {
        *mapping_info_out_ptr = NULL;
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *mapping_info_out_ptr = &(EDCS_3p1_4px_EV_Mappings[ev_3p1_code_in-1]);
    }
    return status;
} /* end EDCS_Map3p1CharacteristicCode */

static int
local_Compare3p1EVLabel
(
    const EDCS_3p1_EV_Label_Entry *a_ptr,
    const EDCS_3p1_EV_Label_Entry *b_ptr
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
} /* end local_Compare3p1EVLabel */

EDCS_Status_Code
EDCS_3p1CharacteristicCodeFromLabel
(
    const char         *ev_3p1_label_in,
          EDCS_Integer *ev_3p1_code_out
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;
    EDCS_3p1_EV_Label_Entry *search_result_ptr = NULL, target;

    if (!ev_3p1_code_out)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!ev_3p1_label_in)
    {
        *ev_3p1_code_out = 0;
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if(!edcs_mapping_initialized)
    {
        fprintf(stderr, "Error: must call EDCS_Init3p1MappingInfo() before using this function\n");
        return EDCS_SC_OTHER_FAILURE;
    }
    else
    {
        target.label_3p1  = ev_3p1_label_in;
        search_result_ptr = (EDCS_3p1_EV_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_3p1_EV_Label_Array,
                               EDCS_3P1_TOTAL_EV,
                               sizeof(EDCS_3p1_EV_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_Compare3p1EVLabel
                            );

        if (search_result_ptr)
        {
            *ev_3p1_code_out = search_result_ptr->code_3p1;
        }
        else
        {
            status = EDCS_SC_INVALID_INPUT_LABEL;
        }
    }
    return status;
} /* end EDCS_3p1CharacteristicCodeFromLabel */

EDCS_Status_Code
EDCS_Map3p1CharacteristicLabel
(
    const char                             *ev_3p1_label_in,
    const EDCS_3p1_4px_Characteristic_Mapping_Structure **mapping_info_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!mapping_info_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!ev_3p1_label_in)
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
        EDCS_Integer ev_code;

        status = EDCS_3p1CharacteristicCodeFromLabel(ev_3p1_label_in, &ev_code);

        if (status == EDCS_SC_SUCCESS)
        {
            status = EDCS_Map3p1CharacteristicCode(ev_code, mapping_info_out_ptr);
        }
    }
    return status;
} /* end EDCS_Map3p1CharacteristicLabel */
