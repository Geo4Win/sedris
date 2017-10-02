/*
 * FILE       : edcs_org_schema_dict.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all EOs.
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

#ifndef _EDCS_ORG_SCHEMA_DICT_H_INCLUDED_
#define _EDCS_ORG_SCHEMA_DICT_H_INCLUDED_

#include "edcs_types.h"

#define EDCS_TOTAL_EO 1

/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEODictionaryEntry
 *
 *   Retrieves dictionary information for the given EO.
 *
 * PARAMETERS:
 *
 *   eo_code_in -- handle to the EO code for which information is requested
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *        a handle to the requested dictionary entry will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *       value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REOUIRED_PARAMETER - and no changes are made, if any
 *       parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_CODE - and no changes are made, if eo_code_in
 *       does not correspond to a valid EO.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetEODictionaryEntry
(
          EDCS_Organization_Schema_Code               eo_code_in,
    const EDCS_Organization_Schema_Dictionary_Entry **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEOCode
 *
 *   Retrieves the EO code corresponding to the given label.
 *
 * PARAMETERS:
 *
 *   eo_label_in_ptr -- the label for which the corresponding EO code is
 *       requested; note that this is the abstract label (i.e., corresponds
 *       to the abstract EDCS specification)
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       the output will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REOUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and no changes are made, if *eo_label_in_ptr
 *     does not correspond to a valid EO.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_LabelToEOCode
(
    const EDCS_Character                *eo_label_in_ptr,
          EDCS_Organization_Schema_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEOCode
 *
 *   Retrieves the EO code corresponding to the given symbolic constant name.
 *
 * PARAMETERS:
 *
 *   eo_symbolic_constant_in_ptr -- the symbolic constant for which the
 *       corresponding EO code is requested; note that this is the
 *       language-binding symbolic constant, rather than the abstract label
 *       (i.e., corresponds to the C language binding standard rather than
 *       the abstract EDCS specification)
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       the output will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REOUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT - and no changes are made, if
 *     *eo_symbolic_constant_in_ptr does not correspond to a valid EO.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_SymbolicConstantToEOCode
(
    const EDCS_Character         *eo_symbolic_constant_in_ptr,
          EDCS_Organization_Schema_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidOrganizationSchemaCode
 *
 *   Indicates if the given EO code is a valid EDCS Organization Schema Code.
 *
 * PARAMETERS:
 *
 *   eo_code_in -- The EO code whose validity is being checked.
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if a valid EO code was passed in.
 *
 *   EDCS_FALSE - if a non-valid EO code was passed in.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidOrganizationSchemaCode
(
    EDCS_Organization_Schema_Code eo_code_in
);


/*
 * Definition:
 *     A schema based on natural and/or scientific principles.
 *
 * Group Membership:
 *    EGC_GEN_ABSTRACT_OBJECT
 *    EGC_GEN_ACOUSTIC_PHENOMENON
 *    EGC_GEN_ADMINISTRATION
 *    EGC_GEN_AGRICULTURE
 *    EGC_GEN_AIR_TRNSP
 *    EGC_GEN_AIRBORNE_PARTICLE
 *    EGC_GEN_ALGORITHM_RELATED
 *    EGC_GEN_ANGULAR_MEASURE
 *    EGC_GEN_ANIMAL
 *    EGC_GEN_ATMOSPHERE
 *    EGC_GEN_BUILDING_COMPONENT
 *    EGC_GEN_COLOUR
 *    EGC_GEN_COMMUNICATION
 *    EGC_GEN_DEMARCATION
 *    EGC_GEN_DEVICE_AND_EQUIPMENT
 *    EGC_GEN_DIMENSION
 *    EGC_GEN_EM_PHENOMENON
 *    EGC_GEN_FLUID_CONDITION
 *    EGC_GEN_HARBOUR_AND_PORT
 *    EGC_GEN_HYDROGRAPHIC_ARTEFACT
 *    EGC_GEN_HYDROGRAPHIC_INDUSTRY
 *    EGC_GEN_HYDROGRAPHIC_TRNSP
 *    EGC_GEN_HYDROLOGY
 *    EGC_GEN_ICE
 *    EGC_GEN_IDENTIFICATION
 *    EGC_GEN_INDUSTRY
 *    EGC_GEN_INFRASTRUCTURE
 *    EGC_GEN_LAND_INDUSTRY
 *    EGC_GEN_LAND_TRNSP
 *    EGC_GEN_LIGHTING_AND_VISIBILITY
 *    EGC_GEN_LITTORAL
 *    EGC_GEN_LIVING_ORGANISM
 *    EGC_GEN_LOCATION
 *    EGC_GEN_MATERIAL
 *    EGC_GEN_MILITARY_SCIENCE
 *    EGC_GEN_PHYSIOGRAPHY
 *    EGC_GEN_PLANT
 *    EGC_GEN_PROPERTY_SET
 *    EGC_GEN_RATE_OR_RATIO
 *    EGC_GEN_RECREATION
 *    EGC_GEN_RELIGION
 *    EGC_GEN_SHELTER
 *    EGC_GEN_SPACE
 *    EGC_GEN_SUPPORT_STRUCTURE
 *    EGC_GEN_SURFACE
 *    EGC_GEN_SURFACE_MATERIAL
 *    EGC_GEN_SURVEY
 *    EGC_GEN_TEMPERATURE
 *    EGC_GEN_TIME
 *    EGC_GEN_TRNSP
 *    EGC_GEN_USAGE_REGION
 *    EGC_GEN_VEHICLE
 *    EGC_GEN_WATERBODY_FLOOR
 *    EGC_GEN_WATERBODY_STATE
 *    EGC_GEN_WATERBODY_SURFACE
 */
#define EOC_GENERAL ((EDCS_Organization_Schema_Code)1)

#ifdef __cplusplus
}
#endif

#endif
