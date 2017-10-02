/*
 * FILE       : edcs_unit_dict.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all EUs.
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

#ifndef _EDCS_UNIT_DICT_H_INCLUDED_
#define _EDCS_UNIT_DICT_H_INCLUDED_

#include "edcs_types.h"

#define EDCS_TOTAL_EU 245

/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEUDictionaryEntry
 *
 *   Retrieves dictionary information for the given EU.
 *
 * PARAMETERS:
 *
 *   eu_code_in -- The EU code for which information is requested
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       a handle to the requested dictionary entry will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_CODE - and no changes are made, if eu_code_in
 *     does not correspond to a valid EU.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetEUDictionaryEntry
(
          EDCS_Unit_Code               eu_code_in,
    const EDCS_Unit_Dictionary_Entry **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEUCode
 *
 *   Retrieves the EU code corresponding to the given label.
 *
 * PARAMETERS:
 *
 *   eu_label_in_ptr -- the label for which the corresponding EU code is
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
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and no changes are made, if *eu_label_in_ptr
 *     does not correspond to a valid EU.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_LabelToEUCode
(
    const EDCS_Character  *eu_label_in_ptr,
          EDCS_Unit_Code  *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEUCode
 *
 *   Retrieves the EU code corresponding to the given symbolic constant name.
 *
 * PARAMETERS:
 *
 *   eu_symbolic_constant_in_ptr -- the symbolic constant for which the
 *       corresponding EU code is requested; note that this is the
 *       language-binding symbolic constant name, rather than the abstract
 *       label (i.e., corresponds to the C language binding standard rather
 *       than the abstract EDCS specification)
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       the output will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT - and no changes are made, if *eu_symbolic_constant_in_ptr
 *     does not correspond to a valid EU.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_SymbolicConstantToEUCode
(
    const EDCS_Character  *eu_symbolic_constant_in_ptr,
          EDCS_Unit_Code  *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitCode
 *
 *   Indicates if the given EU code is a valid EDCS Unit Code.
 *
 * PARAMETERS:
 *
 *   eu_code_in -- The EU code whose validity is being checked.
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if a valid EU code was passed in.
 *
 *   EDCS_FALSE - if a non-valid EU code was passed in.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidUnitCode
(
    EDCS_Unit_Code eu_code_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_UnitsAreEquivalent
 *
 *  Determines whether eu_code1_in and eu_code2_in belong to the same EDCS
 *  Equivalence Class (EQ)
 *
 * PARAMETERS:
 *
 *  eu_code1_in - first unit to test
 *
 *  eu_code2_in - second unit to test
 *
 *  result_out_ptr - point to a variable in the user's memory space that
 *    will be set to the result of the test
 *
 * RETURNS:
 *
 *  EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *    value, if valid parameters were passed in.
 *
 *  EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *    result_out_ptr is NULL.
 *
 *  EDCS_SC_INVALID_INPUT_CODE - and *result_out_ptr is set to EDCS_FALSE,
 *    if eu_code1_in or eu_code2_in is not a valid EDCS_Unit_Code
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_UnitsAreEquivalent
(
    EDCS_Unit_Code eu_code1_in,
    EDCS_Unit_Code eu_code2_in,
    EDCS_Boolean   *result_out_ptr
);

/*
 * Symbol:
 *     A/m
 *
 * Unit Equivalence Class: LINEIC_ELECTRIC_CURRENT
 */
#define EUC_AMP_PER_METRE ((EDCS_Unit_Code)1)

/*
 * Symbol:
 *     A/(m^(2) * K^(2))
 *
 * Unit Equivalence Class: THERMION_EMISSION_CUR_DENS
 */
#define EUC_AMP_PER_SQ_M_KELVIN_SQD ((EDCS_Unit_Code)2)

/*
 * Symbol:
 *     A/m^(2)
 *
 * Unit Equivalence Class: AREIC_ELECTRIC_CURRENT
 */
#define EUC_AMP_PER_SQ_METRE ((EDCS_Unit_Code)3)

/*
 * Symbol:
 *     A
 *
 * Unit Equivalence Class: ELECTRIC_CURRENT
 */
#define EUC_AMPERE ((EDCS_Unit_Code)4)

/*
 * Symbol:
 *     A
 *
 * Unit Equivalence Class: LENGTH
 */
#define EUC_ANGSTROM ((EDCS_Unit_Code)5)

/*
 * Symbol:
 *     a
 *
 * Unit Equivalence Class: AREA
 */
#define EUC_ARE ((EDCS_Unit_Code)6)

/*
 * Symbol:
 *     AU
 *
 * Unit Equivalence Class: LENGTH
 */
#define EUC_ASTRONOMICAL_UNIT ((EDCS_Unit_Code)7)

/*
 * Symbol:
 *     bar
 *
 * Unit Equivalence Class: PRESSURE
 */
#define EUC_BAR ((EDCS_Unit_Code)8)

/*
 * Symbol:
 *     b
 *
 * Unit Equivalence Class: AREA
 */
#define EUC_BARN ((EDCS_Unit_Code)9)

/*
 * Symbol:
 *     Bq
 *
 * Unit Equivalence Class: RADIONUCLIDE_ACTIVITY
 */
#define EUC_BECQUEREL ((EDCS_Unit_Code)10)

/*
 * Symbol:
 *     Bq/m^(3)
 *
 * Unit Equivalence Class: VOLUMIC_ACTIVITY
 */
#define EUC_BECQUEREL_PER_CUBIC_METRE ((EDCS_Unit_Code)11)

/*
 * Symbol:
 *     Bq/kg
 *
 * Unit Equivalence Class: MASSIC_ACTIVITY
 */
#define EUC_BECQUEREL_PER_KG ((EDCS_Unit_Code)12)

/*
 * Symbol:
 *     B
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 */
#define EUC_BEL ((EDCS_Unit_Code)13)

/*
 * Symbol:
 *     cd
 *
 * Unit Equivalence Class: LUMINANCE_INTENSITY
 */
#define EUC_CANDELA ((EDCS_Unit_Code)14)

/*
 * Symbol:
 *     cd/m^(2)
 *
 * Unit Equivalence Class: LUMINANCE
 */
#define EUC_CD_PER_SQ_METRE ((EDCS_Unit_Code)15)

/*
 * Symbol:
 *     C
 *
 * Unit Equivalence Class: ELECTRIC_CHARGE
 */
#define EUC_COULOMB ((EDCS_Unit_Code)16)

/*
 * Symbol:
 *     C * m
 *
 * Unit Equivalence Class: ELECTRIC_DIPOLE_MOMENT
 */
#define EUC_COULOMB_METRE ((EDCS_Unit_Code)17)

/*
 * Symbol:
 *     C * m^(2)/V
 *
 * Unit Equivalence Class: ELECTRIC_POLARIZABILITY
 */
#define EUC_COULOMB_METRE_SQD_PER_VOLT ((EDCS_Unit_Code)18)

/*
 * Symbol:
 *     C/m^(3)
 *
 * Unit Equivalence Class: VOLUME_DENSITY_CHARGE
 */
#define EUC_COULOMB_PER_CUBIC_M ((EDCS_Unit_Code)19)

/*
 * Symbol:
 *     C/kg
 *
 * Unit Equivalence Class: EXPOSURE
 */
#define EUC_COULOMB_PER_KG ((EDCS_Unit_Code)20)

/*
 * Symbol:
 *     C/(kg * s)
 *
 * Unit Equivalence Class: EXPOSURE_RATE
 */
#define EUC_COULOMB_PER_KG_SEC ((EDCS_Unit_Code)21)

/*
 * Symbol:
 *     C/mol
 *
 * Unit Equivalence Class: MOLAR_CHARGE
 */
#define EUC_COULOMB_PER_MOLE ((EDCS_Unit_Code)22)

/*
 * Symbol:
 *     C/m^(2)
 *
 * Unit Equivalence Class: SURFACE_DENSITY_CHARGE
 */
#define EUC_COULOMB_PER_SQ_M ((EDCS_Unit_Code)23)

/*
 * Symbol:
 *     m^(3)/m^(3)
 *
 * Unit Equivalence Class: VOLUME_FRACTION
 */
#define EUC_CUBIC_M_PER_CUBIC_M ((EDCS_Unit_Code)24)

/*
 * Symbol:
 *     m^(3)
 *
 * Unit Equivalence Class: VOLUME
 */
#define EUC_CUBIC_METRE ((EDCS_Unit_Code)25)

/*
 * Symbol:
 *     m^(3)/C
 *
 * Unit Equivalence Class: RECIPROCAL_VOLUMIC_CHARGE
 */
#define EUC_CUBIC_METRE_PER_COULOMB ((EDCS_Unit_Code)26)

/*
 * Symbol:
 *     m^(3)/kg
 *
 * Unit Equivalence Class: SPECIFIC_VOLUME
 */
#define EUC_CUBIC_METRE_PER_KG ((EDCS_Unit_Code)27)

/*
 * Symbol:
 *     m^(3)/mol
 *
 * Unit Equivalence Class: MOLAR_VOLUME
 */
#define EUC_CUBIC_METRE_PER_MOLE ((EDCS_Unit_Code)28)

/*
 * Symbol:
 *     m^(3)/s
 *
 * Unit Equivalence Class: VOLUME_FLOW_RATE
 */
#define EUC_CUBIC_METRE_PER_SEC ((EDCS_Unit_Code)29)

/*
 * Symbol:
 *     Ci
 *
 * Unit Equivalence Class: RADIONUCLIDE_ACTIVITY
 */
#define EUC_CURIE ((EDCS_Unit_Code)30)

/*
 * Symbol:
 *     d
 *
 * Unit Equivalence Class: TIME
 */
#define EUC_DAY ((EDCS_Unit_Code)31)

/*
 * Symbol:
 *     dB
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 */
#define EUC_DB ((EDCS_Unit_Code)32)

/*
 * Symbol:
 *     dB/m
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_LEN_GRADIENT
 */
#define EUC_DB_PER_METRE ((EDCS_Unit_Code)33)

/*
 * Symbol:
 *     dB/(m * kHz)
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_LEN_FREQ
 */
#define EUC_DB_PER_METRE_KHZ ((EDCS_Unit_Code)34)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_FREQ_GRADIENT
 */
#define EUC_DB_PER_OCTAVE ((EDCS_Unit_Code)35)

/*
 * Symbol:
 *     dB/m^(2)
 *
 * Unit Equivalence Class: AREIC_POWER_LEVEL_DIFF
 */
#define EUC_DB_PER_SQ_METRE ((EDCS_Unit_Code)36)

/*
 * Symbol:
 *     dB/(m^(2) * kHz)
 *
 * Unit Equivalence Class: GRAD_POWER_LEVEL_DIFF_LEN_FREQ
 */
#define EUC_DB_PER_SQ_METRE_KHZ ((EDCS_Unit_Code)37)

/*
 * Symbol:
 *     dB (re 1 (mu)Pa)
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 */
#define EUC_DB_REF_ONE_MICROPASCAL ((EDCS_Unit_Code)38)

/*
 * Symbol:
 *     %/min
 *
 * Unit Equivalence Class: RATE
 */
#define EUC_DECAY_RATE ((EDCS_Unit_Code)39)

/*
 * Symbol:
 *     degree
 *
 * Unit Equivalence Class: PLANE_ANGLE
 */
#define EUC_DEGREE_ARC ((EDCS_Unit_Code)40)

/*
 * Symbol:
 *     degreeC
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 */
#define EUC_DEGREE_C ((EDCS_Unit_Code)41)

/*
 * Symbol:
 *     degreeC/h
 *
 * Unit Equivalence Class: THERMO_TEMP_CHANGE_RATE
 */
#define EUC_DEGREE_C_PER_HOUR ((EDCS_Unit_Code)42)

/*
 * Symbol:
 *     degreeC/m
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 */
#define EUC_DEGREE_C_PER_METRE ((EDCS_Unit_Code)43)

/*
 * Symbol:
 *     degreeC/s
 *
 * Unit Equivalence Class: THERMO_TEMP_CHANGE_RATE
 */
#define EUC_DEGREE_C_PER_SEC ((EDCS_Unit_Code)44)

/*
 * Symbol:
 *     eV
 *
 * Unit Equivalence Class: ENERGY
 */
#define EUC_ELECTRONVOLT ((EDCS_Unit_Code)45)

/*
 * Symbol:
 *     eV * m^(2)
 *
 * Unit Equivalence Class: TOTAL_ATOMIC_STOPPING_POWER
 */
#define EUC_ELECTRONVOLT_M_SQD ((EDCS_Unit_Code)46)

/*
 * Symbol:
 *     (eV * m^(2))/kg
 *
 * Unit Equivalence Class: TOTAL_MASS_STOPPING_POWER
 */
#define EUC_ELECTRONVOLT_M_SQD_PER_KG ((EDCS_Unit_Code)47)

/*
 * Symbol:
 *     eV/m
 *
 * Unit Equivalence Class: TOTAL_LINEAR_STOPPING_POWER
 */
#define EUC_ELECTRONVOLT_PER_METRE ((EDCS_Unit_Code)48)

/*
 * Symbol:
 *     F
 *
 * Unit Equivalence Class: CAPACITANCE
 */
#define EUC_FARAD ((EDCS_Unit_Code)49)

/*
 * Symbol:
 *     F/m
 *
 * Unit Equivalence Class: PERMITTIVITY
 */
#define EUC_FARAD_PER_METRE ((EDCS_Unit_Code)50)

/*
 * Symbol:
 *     ft
 *
 * Unit Equivalence Class: LENGTH
 */
#define EUC_FOOT ((EDCS_Unit_Code)51)

/*
 * Symbol:
 *     Gal
 *
 * Unit Equivalence Class: ACCELERATION
 */
#define EUC_GAL ((EDCS_Unit_Code)52)

/*
 * Symbol:
 *     gpm
 *
 * Unit Equivalence Class: GEOPOTENTIAL_ENERGY_LENGTH
 */
#define EUC_GEOPOTENTIAL_METRE ((EDCS_Unit_Code)53)

/*
 * Symbol:
 *     gon
 *
 * Unit Equivalence Class: PLANE_ANGLE
 */
#define EUC_GON ((EDCS_Unit_Code)54)

/*
 * Symbol:
 *     g
 *
 * Unit Equivalence Class: MASS
 */
#define EUC_GRAM ((EDCS_Unit_Code)55)

/*
 * Symbol:
 *     g/cm^(3)
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 */
#define EUC_GRAM_PER_CUBIC_CM ((EDCS_Unit_Code)56)

/*
 * Symbol:
 *     g/m^(3)
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 */
#define EUC_GRAM_PER_CUBIC_M ((EDCS_Unit_Code)57)

/*
 * Symbol:
 *     g/g
 *
 * Unit Equivalence Class: MASS_FRACTION
 */
#define EUC_GRAM_PER_GRAM ((EDCS_Unit_Code)58)

/*
 * Symbol:
 *     g/kg
 *
 * Unit Equivalence Class: MASS_FRACTION
 */
#define EUC_GRAM_PER_KILOGRAM ((EDCS_Unit_Code)59)

/*
 * Symbol:
 *     Gy
 *
 * Unit Equivalence Class: ABSORBED_DOSE
 */
#define EUC_GRAY ((EDCS_Unit_Code)60)

/*
 * Symbol:
 *     Gy/s
 *
 * Unit Equivalence Class: ABSORBED_DOSE_RATE
 */
#define EUC_GRAY_PER_SECOND ((EDCS_Unit_Code)61)

/*
 * Symbol:
 *     ha
 *
 * Unit Equivalence Class: AREA
 */
#define EUC_HECTARE ((EDCS_Unit_Code)62)

/*
 * Symbol:
 *     H
 *
 * Unit Equivalence Class: INDUCTANCE
 */
#define EUC_HENRY ((EDCS_Unit_Code)63)

/*
 * Symbol:
 *     H/m
 *
 * Unit Equivalence Class: MAGNETIC_PERMEABILITY
 */
#define EUC_HENRY_PER_METRE ((EDCS_Unit_Code)64)

/*
 * Symbol:
 *     Hz
 *
 * Unit Equivalence Class: FREQUENCY
 */
#define EUC_HERTZ ((EDCS_Unit_Code)65)

/*
 * Symbol:
 *     h
 *
 * Unit Equivalence Class: TIME
 */
#define EUC_HOUR ((EDCS_Unit_Code)66)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: FLUX_DENSITY
 */
#define EUC_INT_SOLAR_FLUX_UNIT ((EDCS_Unit_Code)67)

/*
 * Symbol:
 *     1/cm^(3)
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_DENSITY
 */
#define EUC_INV_CUBIC_CM ((EDCS_Unit_Code)68)

/*
 * Symbol:
 *     1/(cm^(3) * s)
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_EMIT_RATE
 */
#define EUC_INV_CUBIC_CM_SEC ((EDCS_Unit_Code)69)

/*
 * Symbol:
 *     1/m^(3)
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_DENSITY
 */
#define EUC_INV_CUBIC_METRE ((EDCS_Unit_Code)70)

/*
 * Symbol:
 *     1/(m^(3) * eV)
 *
 * Unit Equivalence Class: DENSITY_STATES
 */
#define EUC_INV_CUBIC_METRE_EV ((EDCS_Unit_Code)71)

/*
 * Symbol:
 *     1/(m^(3) * J)
 *
 * Unit Equivalence Class: DENSITY_STATES
 */
#define EUC_INV_CUBIC_METRE_JOULE ((EDCS_Unit_Code)72)

/*
 * Symbol:
 *     1/(m^(3) * s)
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_EMIT_RATE
 */
#define EUC_INV_CUBIC_METRE_SEC ((EDCS_Unit_Code)73)

/*
 * Symbol:
 *     1/H
 *
 * Unit Equivalence Class: RELUCTANCE
 */
#define EUC_INV_HENRY ((EDCS_Unit_Code)74)

/*
 * Symbol:
 *     1/K
 *
 * Unit Equivalence Class: LINEAR_EXPANSION_COEFF
 */
#define EUC_INV_KELVIN ((EDCS_Unit_Code)75)

/*
 * Symbol:
 *     1/m
 *
 * Unit Equivalence Class: INV_LENGTH
 */
#define EUC_INV_METRE ((EDCS_Unit_Code)76)

/*
 * Symbol:
 *     1/(mu)m
 *
 * Unit Equivalence Class: INV_LENGTH
 */
#define EUC_INV_MICRON ((EDCS_Unit_Code)77)

/*
 * Symbol:
 *     1/mol
 *
 * Unit Equivalence Class: MOLAR_DENSITY
 */
#define EUC_INV_MOLE ((EDCS_Unit_Code)78)

/*
 * Symbol:
 *     1/Pa
 *
 * Unit Equivalence Class: COMPRESSIBILITY
 */
#define EUC_INV_PASCAL ((EDCS_Unit_Code)79)

/*
 * Symbol:
 *     1/rad
 *
 * Unit Equivalence Class: RECIPROCAL_PLANE_ANGLE
 */
#define EUC_INV_RADIAN ((EDCS_Unit_Code)80)

/*
 * Symbol:
 *     1/(s * sr)
 *
 * Unit Equivalence Class: PHOTON_INTENSITY
 */
#define EUC_INV_SEC_STERADIAN ((EDCS_Unit_Code)81)

/*
 * Symbol:
 *     1/s
 *
 * Unit Equivalence Class: RATE
 */
#define EUC_INV_SECOND ((EDCS_Unit_Code)82)

/*
 * Symbol:
 *     1/(cm^(2) * s * sr * eV)
 *
 * Unit Equivalence Class: PARTICLE_FLUX_DENSITY
 */
#define EUC_INV_SQ_CM_SEC_SR_EV ((EDCS_Unit_Code)83)

/*
 * Symbol:
 *     1/(cm^(2) * s * sr * KeV)
 *
 * Unit Equivalence Class: PARTICLE_FLUX_DENSITY
 */
#define EUC_INV_SQ_CM_SEC_SR_KEV ((EDCS_Unit_Code)84)

/*
 * Symbol:
 *     1/(cm^(2) * s * sr * MeV)
 *
 * Unit Equivalence Class: PARTICLE_FLUX_DENSITY
 */
#define EUC_INV_SQ_CM_SEC_SR_MEV ((EDCS_Unit_Code)85)

/*
 * Symbol:
 *     1/(cm^(2) * s * sr)
 *
 * Unit Equivalence Class: PHOTON_LUMINANCE
 */
#define EUC_INV_SQ_CM_SEC_STERADIAN ((EDCS_Unit_Code)86)

/*
 * Symbol:
 *     1/(m^(2) * s * sr * eV)
 *
 * Unit Equivalence Class: PARTICLE_FLUX_DENSITY
 */
#define EUC_INV_SQ_M_SEC_SR_EV ((EDCS_Unit_Code)87)

/*
 * Symbol:
 *     1/(m^(2) * s * sr)
 *
 * Unit Equivalence Class: PHOTON_LUMINANCE
 */
#define EUC_INV_SQ_M_SEC_STERADIAN ((EDCS_Unit_Code)88)

/*
 * Symbol:
 *     1/m^(2)
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 */
#define EUC_INV_SQ_METRE ((EDCS_Unit_Code)89)

/*
 * Symbol:
 *     1/(m^(2) * s)
 *
 * Unit Equivalence Class: PARTICLE_CURRENT_DENSITY
 */
#define EUC_INV_SQ_METRE_SEC ((EDCS_Unit_Code)90)

/*
 * Symbol:
 *     1/sr
 *
 * Unit Equivalence Class: RECIPROCAL_SOLID_ANGLE
 */
#define EUC_INV_STERADIAN ((EDCS_Unit_Code)91)

/*
 * Symbol:
 *     1/(sr * m)
 *
 * Unit Equivalence Class: SPECTRAL_RECIPROCAL_SOLID_ANGLE
 */
#define EUC_INV_STERADIAN_METRE ((EDCS_Unit_Code)92)

/*
 * Symbol:
 *     1/(sr * (mu)m)
 *
 * Unit Equivalence Class: SPECTRAL_RECIPROCAL_SOLID_ANGLE
 */
#define EUC_INV_STERADIAN_MICRON ((EDCS_Unit_Code)93)

/*
 * Symbol:
 *     Jy
 *
 * Unit Equivalence Class: FLUX_DENSITY
 */
#define EUC_JANSKY ((EDCS_Unit_Code)94)

/*
 * Symbol:
 *     J
 *
 * Unit Equivalence Class: ENERGY
 */
#define EUC_JOULE ((EDCS_Unit_Code)95)

/*
 * Symbol:
 *     J * m^(2)
 *
 * Unit Equivalence Class: TOTAL_ATOMIC_STOPPING_POWER
 */
#define EUC_JOULE_METRE_SQD ((EDCS_Unit_Code)96)

/*
 * Symbol:
 *     (J * m^(2))/kg
 *
 * Unit Equivalence Class: TOTAL_MASS_STOPPING_POWER
 */
#define EUC_JOULE_METRE_SQD_PER_KG ((EDCS_Unit_Code)97)

/*
 * Symbol:
 *     J/m^(3)
 *
 * Unit Equivalence Class: ENERGY_DENSITY
 */
#define EUC_JOULE_PER_CUBIC_M ((EDCS_Unit_Code)98)

/*
 * Symbol:
 *     J/(g * K)
 *
 * Unit Equivalence Class: SPECIFIC_HEAT_CAPACITY
 */
#define EUC_JOULE_PER_GRAM_K ((EDCS_Unit_Code)99)

/*
 * Symbol:
 *     J/K
 *
 * Unit Equivalence Class: HEAT_CAPACITY
 */
#define EUC_JOULE_PER_KELVIN ((EDCS_Unit_Code)100)

/*
 * Symbol:
 *     J/(K * mol)
 *
 * Unit Equivalence Class: MOLAR_ENTROPY
 */
#define EUC_JOULE_PER_KELVIN_MOLE ((EDCS_Unit_Code)101)

/*
 * Symbol:
 *     J/kg
 *
 * Unit Equivalence Class: SPECIFIC_ENERGY
 */
#define EUC_JOULE_PER_KG ((EDCS_Unit_Code)102)

/*
 * Symbol:
 *     J/(kg * K)
 *
 * Unit Equivalence Class: SPECIFIC_HEAT_CAPACITY
 */
#define EUC_JOULE_PER_KG_KELVIN ((EDCS_Unit_Code)103)

/*
 * Symbol:
 *     J/km
 *
 * Unit Equivalence Class: LINEAR_ENERGY_TRANSFER
 */
#define EUC_JOULE_PER_KM ((EDCS_Unit_Code)104)

/*
 * Symbol:
 *     J/m^(4)
 *
 * Unit Equivalence Class: SPECTRAL_RAD_ENERGY_DENSITY
 */
#define EUC_JOULE_PER_M_FOURTH_PWR ((EDCS_Unit_Code)105)

/*
 * Symbol:
 *     J/m
 *
 * Unit Equivalence Class: LINEAR_ENERGY_TRANSFER
 */
#define EUC_JOULE_PER_METRE ((EDCS_Unit_Code)106)

/*
 * Symbol:
 *     J/mol
 *
 * Unit Equivalence Class: MOLAR_ENERGY
 */
#define EUC_JOULE_PER_MOLE ((EDCS_Unit_Code)107)

/*
 * Symbol:
 *     J/m^(2)
 *
 * Unit Equivalence Class: RADIANT_ENERGY_FLUENCE
 */
#define EUC_JOULE_PER_SQ_METRE ((EDCS_Unit_Code)108)

/*
 * Symbol:
 *     J * s
 *
 * Unit Equivalence Class: PLANCK_CONSTANT
 */
#define EUC_JOULE_SECOND ((EDCS_Unit_Code)109)

/*
 * Symbol:
 *     K
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 */
#define EUC_KELVIN ((EDCS_Unit_Code)110)

/*
 * Symbol:
 *     K/km
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 */
#define EUC_KELVIN_PER_KM ((EDCS_Unit_Code)111)

/*
 * Symbol:
 *     K/m
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 */
#define EUC_KELVIN_PER_METRE ((EDCS_Unit_Code)112)

/*
 * Symbol:
 *     K/s
 *
 * Unit Equivalence Class: THERMO_TEMP_CHANGE_RATE
 */
#define EUC_KELVIN_PER_SEC ((EDCS_Unit_Code)113)

/*
 * Symbol:
 *     K/W
 *
 * Unit Equivalence Class: THERMAL_RESISTANCE
 */
#define EUC_KELVIN_PER_WATT ((EDCS_Unit_Code)114)

/*
 * Symbol:
 *     kg * m/s
 *
 * Unit Equivalence Class: MOMENTUM
 */
#define EUC_KG_METRE_PER_SEC ((EDCS_Unit_Code)115)

/*
 * Symbol:
 *     kg * m^(2)
 *
 * Unit Equivalence Class: MOMENT_INERTIA
 */
#define EUC_KG_METRE_SQD ((EDCS_Unit_Code)116)

/*
 * Symbol:
 *     (kg * m^(2))/s
 *
 * Unit Equivalence Class: ANGULAR_MOMENTUM
 */
#define EUC_KG_METRE_SQD_PER_SEC ((EDCS_Unit_Code)117)

/*
 * Symbol:
 *     kg/m^(3)
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 */
#define EUC_KG_PER_CUBIC_METRE ((EDCS_Unit_Code)118)

/*
 * Symbol:
 *     kg/kg
 *
 * Unit Equivalence Class: MASS_FRACTION
 */
#define EUC_KG_PER_KG ((EDCS_Unit_Code)119)

/*
 * Symbol:
 *     kg/l
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 */
#define EUC_KG_PER_LITRE ((EDCS_Unit_Code)120)

/*
 * Symbol:
 *     kg/m
 *
 * Unit Equivalence Class: LINEIC_MASS
 */
#define EUC_KG_PER_METRE ((EDCS_Unit_Code)121)

/*
 * Symbol:
 *     kg/mol
 *
 * Unit Equivalence Class: MOLAR_MASS
 */
#define EUC_KG_PER_MOLE ((EDCS_Unit_Code)122)

/*
 * Symbol:
 *     kg/s
 *
 * Unit Equivalence Class: MASS_FLOW_RATE
 */
#define EUC_KG_PER_SECOND ((EDCS_Unit_Code)123)

/*
 * Symbol:
 *     kg/m^(2)
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 */
#define EUC_KG_PER_SQ_METRE ((EDCS_Unit_Code)124)

/*
 * Symbol:
 *     kg
 *
 * Unit Equivalence Class: MASS
 */
#define EUC_KILOGRAM ((EDCS_Unit_Code)125)

/*
 * Symbol:
 *     kp
 *
 * Unit Equivalence Class: MASS
 */
#define EUC_KILOPOUND ((EDCS_Unit_Code)126)

/*
 * Symbol:
 *     km/h
 *
 * Unit Equivalence Class: SPEED
 */
#define EUC_KM_PER_HOUR ((EDCS_Unit_Code)127)

/*
 * Symbol:
 *     kn
 *
 * Unit Equivalence Class: SPEED
 */
#define EUC_KNOT ((EDCS_Unit_Code)128)

/*
 * Symbol:
 *     l.y.
 *
 * Unit Equivalence Class: LENGTH
 */
#define EUC_LIGHT_YEAR ((EDCS_Unit_Code)129)

/*
 * Symbol:
 *     l, L (Both symbols are equally accepted.)
 *
 * Unit Equivalence Class: VOLUME
 */
#define EUC_LITRE ((EDCS_Unit_Code)130)

/*
 * Symbol:
 *     L/h
 *
 * Unit Equivalence Class: VOLUME_FLOW_RATE
 */
#define EUC_LITRE_PER_HOUR ((EDCS_Unit_Code)131)

/*
 * Symbol:
 *     L/s
 *
 * Unit Equivalence Class: VOLUME_FLOW_RATE
 */
#define EUC_LITRE_PER_SECOND ((EDCS_Unit_Code)132)

/*
 * Symbol:
 *     ton (long)
 *
 * Unit Equivalence Class: MASS
 */
#define EUC_LONG_TON ((EDCS_Unit_Code)133)

/*
 * Symbol:
 *     lm
 *
 * Unit Equivalence Class: LUMINANCE_FLUX
 */
#define EUC_LUMEN ((EDCS_Unit_Code)134)

/*
 * Symbol:
 *     lm * h
 *
 * Unit Equivalence Class: QUANTITY_LIGHT
 */
#define EUC_LUMEN_HOUR ((EDCS_Unit_Code)135)

/*
 * Symbol:
 *     lm/m^(2)
 *
 * Unit Equivalence Class: LUMINANCE_EXITANCE
 */
#define EUC_LUMEN_PER_SQ_METRE ((EDCS_Unit_Code)136)

/*
 * Symbol:
 *     lm/W
 *
 * Unit Equivalence Class: LUMINANCE_EFFICIENCY
 */
#define EUC_LUMEN_PER_WATT ((EDCS_Unit_Code)137)

/*
 * Symbol:
 *     lm * s
 *
 * Unit Equivalence Class: QUANTITY_LIGHT
 */
#define EUC_LUMEN_SECOND ((EDCS_Unit_Code)138)

/*
 * Symbol:
 *     lx
 *
 * Unit Equivalence Class: ILLUMINANCE
 */
#define EUC_LUX ((EDCS_Unit_Code)139)

/*
 * Symbol:
 *     lx * h
 *
 * Unit Equivalence Class: LIGHT_EXPOSURE
 */
#define EUC_LUX_HOUR ((EDCS_Unit_Code)140)

/*
 * Symbol:
 *     lx * s
 *
 * Unit Equivalence Class: LIGHT_EXPOSURE
 */
#define EUC_LUX_SECOND ((EDCS_Unit_Code)141)

/*
 * Symbol:
 *     m
 *
 * Unit Equivalence Class: LENGTH
 */
#define EUC_METRE ((EDCS_Unit_Code)142)

/*
 * Symbol:
 *     m^(4)
 *
 * Unit Equivalence Class: SECOND_MOMENT_AREA
 */
#define EUC_METRE_FOURTH_POWER ((EDCS_Unit_Code)143)

/*
 * Symbol:
 *     m * K
 *
 * Unit Equivalence Class: SECOND_RADIATION_CONSTANT
 */
#define EUC_METRE_KELVIN ((EDCS_Unit_Code)144)

/*
 * Symbol:
 *     m/h
 *
 * Unit Equivalence Class: SPEED
 */
#define EUC_METRE_PER_HOUR ((EDCS_Unit_Code)145)

/*
 * Symbol:
 *     m/s
 *
 * Unit Equivalence Class: SPEED
 */
#define EUC_METRE_PER_SEC ((EDCS_Unit_Code)146)

/*
 * Symbol:
 *     m/s^(2)
 *
 * Unit Equivalence Class: ACCELERATION
 */
#define EUC_METRE_PER_SEC_SQD ((EDCS_Unit_Code)147)

/*
 * Symbol:
 *     mile
 *
 * Unit Equivalence Class: LENGTH
 */
#define EUC_MILE ((EDCS_Unit_Code)148)

/*
 * Symbol:
 *     mile/h
 *
 * Unit Equivalence Class: SPEED
 */
#define EUC_MILE_PER_HOUR ((EDCS_Unit_Code)149)

/*
 * Symbol:
 *     min
 *
 * Unit Equivalence Class: TIME
 */
#define EUC_MINUTE ((EDCS_Unit_Code)150)

/*
 * Symbol:
 *     '
 *
 * Unit Equivalence Class: PLANE_ANGLE
 */
#define EUC_MINUTE_ARC ((EDCS_Unit_Code)151)

/*
 * Symbol:
 *     min/m^(3)
 *
 * Unit Equivalence Class: VOLUMIC_DOSE
 */
#define EUC_MINUTE_PER_CUBIC_METRE ((EDCS_Unit_Code)152)

/*
 * Symbol:
 *     mol
 *
 * Unit Equivalence Class: AMOUNT_SUBSTANCE
 */
#define EUC_MOLE ((EDCS_Unit_Code)153)

/*
 * Symbol:
 *     mol/m^(3)
 *
 * Unit Equivalence Class: CONCENTRATION
 */
#define EUC_MOLE_PER_CUBIC_M ((EDCS_Unit_Code)154)

/*
 * Symbol:
 *     mol/kg
 *
 * Unit Equivalence Class: MOLALITY_SOLUTE
 */
#define EUC_MOLE_PER_KG ((EDCS_Unit_Code)155)

/*
 * Symbol:
 *     mol/l, mol/L
 *
 * Unit Equivalence Class: CONCENTRATION
 */
#define EUC_MOLE_PER_LITRE ((EDCS_Unit_Code)156)

/*
 * Symbol:
 *     mol/mol
 *
 * Unit Equivalence Class: MOLE_FRACTION
 */
#define EUC_MOLE_PER_MOLE ((EDCS_Unit_Code)157)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: LENGTH
 */
#define EUC_NAUTICAL_MILE ((EDCS_Unit_Code)158)

/*
 * Symbol:
 *     Np
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 */
#define EUC_NEPER ((EDCS_Unit_Code)159)

/*
 * Symbol:
 *     Np/s
 *
 * Unit Equivalence Class: DAMPING_COEFFICIENT
 */
#define EUC_NEPER_PER_SECOND ((EDCS_Unit_Code)160)

/*
 * Symbol:
 *     N
 *
 * Unit Equivalence Class: FORCE
 */
#define EUC_NEWTON ((EDCS_Unit_Code)161)

/*
 * Symbol:
 *     (N * m^(2))/kg^(2)
 *
 * Unit Equivalence Class: GRAVITATIONAL_FORCE
 */
#define EUC_NEWTON_M_SQD_PER_KG_SQD ((EDCS_Unit_Code)162)

/*
 * Symbol:
 *     N * m
 *
 * Unit Equivalence Class: MOMENT_FORCE
 */
#define EUC_NEWTON_METRE ((EDCS_Unit_Code)163)

/*
 * Symbol:
 *     N * m * s
 *
 * Unit Equivalence Class: ANGULAR_IMPULSE
 */
#define EUC_NEWTON_METRE_SECOND ((EDCS_Unit_Code)164)

/*
 * Symbol:
 *     N/m
 *
 * Unit Equivalence Class: SURFACE_TENSION
 */
#define EUC_NEWTON_PER_METRE ((EDCS_Unit_Code)165)

/*
 * Symbol:
 *     N/m^(2)
 *
 * Unit Equivalence Class: PRESSURE
 */
#define EUC_NEWTON_PER_SQ_M ((EDCS_Unit_Code)166)

/*
 * Symbol:
 *     N * s
 *
 * Unit Equivalence Class: IMPULSE
 */
#define EUC_NEWTON_SECOND ((EDCS_Unit_Code)167)

/*
 * Symbol:
 *     (N * s)/m
 *
 * Unit Equivalence Class: MECHANICAL_IMPEDANCE
 */
#define EUC_NEWTON_SECOND_PER_METRE ((EDCS_Unit_Code)168)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: FREQUENCY_INTERVAL
 */
#define EUC_OCTAVE ((EDCS_Unit_Code)169)

/*
 * Symbol:
 *     (Omega)
 *
 * Unit Equivalence Class: RESISTANCE
 */
#define EUC_OHM ((EDCS_Unit_Code)170)

/*
 * Symbol:
 *     (Omega) * m
 *
 * Unit Equivalence Class: RESISTIVITY
 */
#define EUC_OHM_METRE ((EDCS_Unit_Code)171)

/*
 * Symbol:
 *     pc
 *
 * Unit Equivalence Class: LENGTH
 */
#define EUC_PARSEC ((EDCS_Unit_Code)172)

/*
 * Symbol:
 *     Pa
 *
 * Unit Equivalence Class: PRESSURE
 */
#define EUC_PASCAL ((EDCS_Unit_Code)173)

/*
 * Symbol:
 *     Pa/K
 *
 * Unit Equivalence Class: PRESSURE_COEFFICIENT
 */
#define EUC_PASCAL_PER_KELVIN ((EDCS_Unit_Code)174)

/*
 * Symbol:
 *     Pa/s
 *
 * Unit Equivalence Class: PRESSURE_CHANGE_RATE
 */
#define EUC_PASCAL_PER_SEC ((EDCS_Unit_Code)175)

/*
 * Symbol:
 *     Pa * s
 *
 * Unit Equivalence Class: DYNAMIC_VISCOSITY
 */
#define EUC_PASCAL_SEC ((EDCS_Unit_Code)176)

/*
 * Symbol:
 *     (Pa * s)/m^(3)
 *
 * Unit Equivalence Class: ACOUSTIC_IMPEDANCE
 */
#define EUC_PASCAL_SEC_PER_CUBIC_METRE ((EDCS_Unit_Code)177)

/*
 * Symbol:
 *     (Pa * s)/m
 *
 * Unit Equivalence Class: SURFACE_DENSITY_MECH_IMPED
 */
#define EUC_PASCAL_SEC_PER_METRE ((EDCS_Unit_Code)178)

/*
 * Symbol:
 *     %
 *
 * Unit Equivalence Class: PURE_NUMBER
 */
#define EUC_PERCENT ((EDCS_Unit_Code)179)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: LOUDNESS_LEVEL
 */
#define EUC_PHON ((EDCS_Unit_Code)180)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: MASS_FRACTION
 */
#define EUC_PPB_MASS_FRACTION ((EDCS_Unit_Code)181)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: MASS_FRACTION
 */
#define EUC_PPM_MASS_FRACTION ((EDCS_Unit_Code)182)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: MASS_FRACTION
 */
#define EUC_PPT_MASS_FRACTION ((EDCS_Unit_Code)183)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: MASS_FRACTION
 */
#define EUC_PPTH_MASS_FRACTION ((EDCS_Unit_Code)184)

/*
 * Symbol:
 *     rd
 *
 * Unit Equivalence Class: ABSORBED_DOSE
 */
#define EUC_RAD ((EDCS_Unit_Code)185)

/*
 * Symbol:
 *     rad
 *
 * Unit Equivalence Class: PLANE_ANGLE
 */
#define EUC_RADIAN ((EDCS_Unit_Code)186)

/*
 * Symbol:
 *     rad/m
 *
 * Unit Equivalence Class: ANGULAR_REPETENCY
 */
#define EUC_RADIAN_PER_METRE ((EDCS_Unit_Code)187)

/*
 * Symbol:
 *     rad/s
 *
 * Unit Equivalence Class: ANGULAR_VELOCITY
 */
#define EUC_RADIAN_PER_SEC ((EDCS_Unit_Code)188)

/*
 * Symbol:
 *     rad/s^(2)
 *
 * Unit Equivalence Class: ANGULAR_ACCELERATION
 */
#define EUC_RADIAN_PER_SEC_SQD ((EDCS_Unit_Code)189)

/*
 * Symbol:
 *     rem
 *
 * Unit Equivalence Class: DOSE_EQUIVALENT
 */
#define EUC_REM ((EDCS_Unit_Code)190)

/*
 * Symbol:
 *     R
 *
 * Unit Equivalence Class: EXPOSURE
 */
#define EUC_ROENTGEN ((EDCS_Unit_Code)191)

/*
 * Symbol:
 *     s
 *
 * Unit Equivalence Class: TIME
 */
#define EUC_SECOND ((EDCS_Unit_Code)192)

/*
 * Symbol:
 *     "
 *
 * Unit Equivalence Class: PLANE_ANGLE
 */
#define EUC_SECOND_ARC ((EDCS_Unit_Code)193)

/*
 * Symbol:
 *     s/(m^(3) * rad)
 *
 * Unit Equivalence Class: SPECTRAL_CONC_VIBRAT_MODES
 */
#define EUC_SECOND_PER_CUBIC_M_RADIAN ((EDCS_Unit_Code)194)

/*
 * Symbol:
 *     s/m^(3)
 *
 * Unit Equivalence Class: VOLUMIC_DOSE
 */
#define EUC_SECOND_PER_CUBIC_METRE ((EDCS_Unit_Code)195)

/*
 * Symbol:
 *     S
 *
 * Unit Equivalence Class: ELECTRIC_CONDUCTANCE
 */
#define EUC_SIEMENS ((EDCS_Unit_Code)196)

/*
 * Symbol:
 *     (S * m^(2))/mol
 *
 * Unit Equivalence Class: MOLAR_CONDUCTIVITY
 */
#define EUC_SIEMENS_M_SQD_PER_MOLE ((EDCS_Unit_Code)197)

/*
 * Symbol:
 *     S/m
 *
 * Unit Equivalence Class: ELECTRIC_CONDUCTIVITY
 */
#define EUC_SIEMENS_PER_METRE ((EDCS_Unit_Code)198)

/*
 * Symbol:
 *     Sv
 *
 * Unit Equivalence Class: DOSE_EQUIVALENT
 */
#define EUC_SIEVERT ((EDCS_Unit_Code)199)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: LOUDNESS
 */
#define EUC_SONE ((EDCS_Unit_Code)200)

/*
 * Symbol:
 *     m^(2)
 *
 * Unit Equivalence Class: AREA
 */
#define EUC_SQ_METRE ((EDCS_Unit_Code)201)

/*
 * Symbol:
 *     (m^(2) * A)/(J * s)
 *
 * Unit Equivalence Class: GYROMAGNETIC_COEFFICIENT
 */
#define EUC_SQ_METRE_AMP_PER_JOULE_SEC ((EDCS_Unit_Code)202)

/*
 * Symbol:
 *     m^(2) * A
 *
 * Unit Equivalence Class: MAGNETIC_MOMENT
 */
#define EUC_SQ_METRE_AMPERE ((EDCS_Unit_Code)203)

/*
 * Symbol:
 *     (m^(2) * K)/W
 *
 * Unit Equivalence Class: THERMAL_INSULANCE
 */
#define EUC_SQ_METRE_KELVIN_PER_WATT ((EDCS_Unit_Code)204)

/*
 * Symbol:
 *     m^(2)/J
 *
 * Unit Equivalence Class: SPECTRAL_CROSS_SECTION
 */
#define EUC_SQ_METRE_PER_JOULE ((EDCS_Unit_Code)205)

/*
 * Symbol:
 *     m^(2)/(J * sr)
 *
 * Unit Equivalence Class: SPECTRAL_ANGULAR_CROSS_SECT
 */
#define EUC_SQ_METRE_PER_JOULE_SR ((EDCS_Unit_Code)206)

/*
 * Symbol:
 *     m^(2)/kg
 *
 * Unit Equivalence Class: MASS_ATTENUATION_COEFF
 */
#define EUC_SQ_METRE_PER_KG ((EDCS_Unit_Code)207)

/*
 * Symbol:
 *     m^(2)/mol
 *
 * Unit Equivalence Class: MOLAR_ABSORPTION_COEFF
 */
#define EUC_SQ_METRE_PER_MOLE ((EDCS_Unit_Code)208)

/*
 * Symbol:
 *     m^(2)/s
 *
 * Unit Equivalence Class: KINEMATIC_VISCOSITY
 */
#define EUC_SQ_METRE_PER_SECOND ((EDCS_Unit_Code)209)

/*
 * Symbol:
 *     m^(2)/sr
 *
 * Unit Equivalence Class: ANGULAR_CROSS_SECTION
 */
#define EUC_SQ_METRE_PER_STERADIAN ((EDCS_Unit_Code)210)

/*
 * Symbol:
 *     m^(2)/(V * s)
 *
 * Unit Equivalence Class: MOBILITY
 */
#define EUC_SQ_METRE_PER_VOLT_SECOND ((EDCS_Unit_Code)211)

/*
 * Symbol:
 *     (m^(2) * rad)/kg
 *
 * Unit Equivalence Class: MASSIC_OPTICAL_ROT_POWER
 */
#define EUC_SQ_METRE_RADIAN_PER_KG ((EDCS_Unit_Code)212)

/*
 * Symbol:
 *     (m^(2) * rad)/mol
 *
 * Unit Equivalence Class: MOLAR_OPTICAL_ROT_POWER
 */
#define EUC_SQ_METRE_RADIAN_PER_MOLE ((EDCS_Unit_Code)213)

/*
 * Symbol:
 *     sr
 *
 * Unit Equivalence Class: SOLID_ANGLE
 */
#define EUC_STERADIAN ((EDCS_Unit_Code)214)

/*
 * Symbol:
 *     none
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 */
#define EUC_TEC ((EDCS_Unit_Code)215)

/*
 * Symbol:
 *     T
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 */
#define EUC_TESLA ((EDCS_Unit_Code)216)

/*
 * Symbol:
 *     ton
 *
 * Unit Equivalence Class: MASS
 */
#define EUC_TON ((EDCS_Unit_Code)217)

/*
 * Symbol:
 *     t
 *
 * Unit Equivalence Class: MASS
 */
#define EUC_TONNE ((EDCS_Unit_Code)218)

/*
 * Symbol:
 *     t/m^(3)
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 */
#define EUC_TONNE_PER_CUBIC_METRE ((EDCS_Unit_Code)219)

/*
 * Symbol:
 *     u
 *
 * Unit Equivalence Class: MASS
 */
#define EUC_UNIFIED_AMASS_UNIT ((EDCS_Unit_Code)220)

/*
 * Symbol:
 *     1 (often omitted)
 *
 * Unit Equivalence Class: PURE_NUMBER
 */
#define EUC_UNITLESS ((EDCS_Unit_Code)221)

/*
 * Symbol:
 *     V
 *
 * Unit Equivalence Class: ELECTRIC_POTENTIAL
 */
#define EUC_VOLT ((EDCS_Unit_Code)222)

/*
 * Symbol:
 *     V * A
 *
 * Unit Equivalence Class: APPARENT_POWER
 */
#define EUC_VOLT_AMP ((EDCS_Unit_Code)223)

/*
 * Symbol:
 *     V/K
 *
 * Unit Equivalence Class: SEEBECK_COEFFICIENT
 */
#define EUC_VOLT_PER_KELVIN ((EDCS_Unit_Code)224)

/*
 * Symbol:
 *     V/m
 *
 * Unit Equivalence Class: ELECTRIC_FIELD_STRENGTH
 */
#define EUC_VOLT_PER_METRE ((EDCS_Unit_Code)225)

/*
 * Symbol:
 *     V^(2)/K^(2)
 *
 * Unit Equivalence Class: LORENZ_COEFFICIENT
 */
#define EUC_VOLT_SQD_PER_KELVIN_SQD ((EDCS_Unit_Code)226)

/*
 * Symbol:
 *     W
 *
 * Unit Equivalence Class: POWER
 */
#define EUC_WATT ((EDCS_Unit_Code)227)

/*
 * Symbol:
 *     W * h
 *
 * Unit Equivalence Class: ENERGY
 */
#define EUC_WATT_HOUR ((EDCS_Unit_Code)228)

/*
 * Symbol:
 *     W/K
 *
 * Unit Equivalence Class: THERMAL_CONDUCTANCE
 */
#define EUC_WATT_PER_KELVIN ((EDCS_Unit_Code)229)

/*
 * Symbol:
 *     W/(m * K)
 *
 * Unit Equivalence Class: THERMAL_CONDUCTIVITY
 */
#define EUC_WATT_PER_METRE_K ((EDCS_Unit_Code)230)

/*
 * Symbol:
 *     W/(cm^(2) * s)
 *
 * Unit Equivalence Class: RADIANT_EXITANCE_RATE
 */
#define EUC_WATT_PER_SQ_CM_SEC ((EDCS_Unit_Code)231)

/*
 * Symbol:
 *     W/(m^(2) * Hz)
 *
 * Unit Equivalence Class: FLUX_DENSITY
 */
#define EUC_WATT_PER_SQ_M_HZ ((EDCS_Unit_Code)232)

/*
 * Symbol:
 *     W/(m^(2) * K^(4))
 *
 * Unit Equivalence Class: STEFAN_BOLTZMAN_CONSTANT
 */
#define EUC_WATT_PER_SQ_M_K_FOURTH_PWR ((EDCS_Unit_Code)233)

/*
 * Symbol:
 *     W/m^(2)
 *
 * Unit Equivalence Class: IRRADIANCE
 */
#define EUC_WATT_PER_SQ_METRE ((EDCS_Unit_Code)234)

/*
 * Symbol:
 *     W/(m^(2) * K)
 *
 * Unit Equivalence Class: COEFFICIENT_HEAT_TRANSFER
 */
#define EUC_WATT_PER_SQ_METRE_K ((EDCS_Unit_Code)235)

/*
 * Symbol:
 *     W/(m^(2) * (mu)m)
 *
 * Unit Equivalence Class: SPECTRAL_RADIANCE_INTEGRATED
 */
#define EUC_WATT_PER_SQ_METRE_MICRON ((EDCS_Unit_Code)236)

/*
 * Symbol:
 *     W/(m^(2) * s)
 *
 * Unit Equivalence Class: RADIANT_EXITANCE_RATE
 */
#define EUC_WATT_PER_SQ_METRE_SEC ((EDCS_Unit_Code)237)

/*
 * Symbol:
 *     W/(m^(2) * sr)
 *
 * Unit Equivalence Class: RADIANCE
 */
#define EUC_WATT_PER_SQ_METRE_SR ((EDCS_Unit_Code)238)

/*
 * Symbol:
 *     W/(m^(2) * sr * (mu)m)
 *
 * Unit Equivalence Class: SPECTRAL_RADIANCE
 */
#define EUC_WATT_PER_SQ_METRE_SR_MICRON ((EDCS_Unit_Code)239)

/*
 * Symbol:
 *     W/sr
 *
 * Unit Equivalence Class: RADIANT_INTENSITY
 */
#define EUC_WATT_PER_STERADIAN ((EDCS_Unit_Code)240)

/*
 * Symbol:
 *     W * s
 *
 * Unit Equivalence Class: ENERGY
 */
#define EUC_WATT_SECOND ((EDCS_Unit_Code)241)

/*
 * Symbol:
 *     W * m^(2)
 *
 * Unit Equivalence Class: FIRST_RADIATION_CONSTANT
 */
#define EUC_WATT_SQ_METRE ((EDCS_Unit_Code)242)

/*
 * Symbol:
 *     Wb
 *
 * Unit Equivalence Class: MAGNETIC_FLUX
 */
#define EUC_WEBER ((EDCS_Unit_Code)243)

/*
 * Symbol:
 *     Wb/m
 *
 * Unit Equivalence Class: MAGNETIC_VECTOR_POTENTIAL
 */
#define EUC_WEBER_PER_METRE ((EDCS_Unit_Code)244)

/*
 * Symbol:
 *     a
 *
 * Unit Equivalence Class: TIME
 */
#define EUC_YEAR ((EDCS_Unit_Code)245)

#ifdef __cplusplus
}
#endif

#endif
