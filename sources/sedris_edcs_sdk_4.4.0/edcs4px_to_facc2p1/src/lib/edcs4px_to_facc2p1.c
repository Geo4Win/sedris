/*
 * FILE: edcs4px_to_facc2p1.c
 *
 * PROGRAMMERS: Kevin Wertman
 *
 * EDCS 4.4 to FACC 2.1 Mapping SDK Release 4.4.0.0 - July 1, 2011
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
 * disabling 4244 kills the warning when assigning
 * EDCS_POS_INFINITY which is defined as an EDCS_Float
 * to an unsigned int.
 */
#pragma warning ( disable : 4305 4244 )
#endif

#include "edcs4px_to_facc2p1.h"

/*
 * GLOBAL: edcs_to_facc_mapping_initialized
 *
 * Internal variable to keep track of whether or
 * not the internal mapping structures been initialized.
 */
EDCS_Boolean edcs_to_facc_mapping_initialized = EDCS_FALSE;

const char *
EDCS_to_FACC_PrintMappingType
(
    FACC_Mapping_Type_Code mapping_type
)
{
    switch (mapping_type)
    {
        case FACC_MAP_TYP_ONE_TO_ONE:
        {
            return "ONE TO ONE";
        }
        case FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED:
        {
            return "ONE TO ONE QUALIFIED";
        }
        case FACC_MAP_TYP_ONE_TO_ZERO:
        {
            return "ONE TO ZERO";
        }
        case FACC_MAP_TYP_MAP_TO_CODED:
        {
            return "MAP TO CODED";
        }
        case FACC_MAP_TYP_INDETERMINATE:
        {
            return "INDETERMINATE";
        }
        case FACC_MAP_TYP_SPECIAL_CASE:
        {
            return "SPECIAL CASE";
        }
        case FACC_MAP_TYP_ONE_TO_ONE_CONDITIONAL:
        {
            return "ONE TO ONE CONDITIONAL";
        }
        default:
        {
            return "UNKNOWN MAPPING TYPE";
        }
    }
}

const char *
EDCS_to_FACC_PrintFACCValueType
(
    FACC_Value_Type value_type
)
{
    switch (value_type)
    {
        case FACC_VAL_TYP_NULL:
        {
            return "NULL";
        }
        case FACC_VAL_TYP_CODED:
        {
            return "CODED";
        }
        case FACC_VAL_TYP_SHORT_INTEGER:
        {
            return "SHORT INTEGER";
        }
        case FACC_VAL_TYP_LONG_INTEGER:
        {
            return "LONG INTEGER";
        }
        case FACC_VAL_TYP_FLOAT:
        {
            return "FLOAT";
        }
        case FACC_VAL_TYP_TEXT:
        {
            return "TEXT";
        }
        default:
        {
            return "UNKNOWN FACC VALUE TYPE";
        }
    }
}

extern void initialize_attribute_mapping( void );
extern void initialize_class_mapping( void );

EDCS_Status_Code
EDCS_to_FACC_InitMappingInfo
(
    void
)
{
    initialize_class_mapping();
    initialize_attribute_mapping();
    return EDCS_SC_SUCCESS;
}

EDCS_Status_Code
EDCS_to_FACC_ShutdownMappingInfo
(
    void
)
{
    return EDCS_SC_SUCCESS;
}
