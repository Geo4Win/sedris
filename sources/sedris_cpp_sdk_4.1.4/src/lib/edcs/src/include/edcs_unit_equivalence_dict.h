/*
 * FILE       : edcs_unit_equivalence_dict.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all EQs.
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

#ifndef _EDCS_UNIT_EQUIVALENCE_DICT_H_INCLUDED_
#define _EDCS_UNIT_EQUIVALENCE_DICT_H_INCLUDED_

#include "edcs_types.h"

#define EDCS_TOTAL_EQ 164

/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEQDictionaryEntry
 *
 *   Retrieves dictionary information for the given EQ.
 *
 * PARAMETERS:
 *
 *   eq_code_in-- The EQ code for which information is requested
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
 *   EDCS_SC_INVALID_INPUT_CODE - and no changes are made, if eq_code_in
 *     does not correspond to a valid EQ.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetEQDictionaryEntry
(
          EDCS_Unit_Equivalence_Code               eq_code_in,
    const EDCS_Unit_Equivalence_Dictionary_Entry **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEQCode
 *
 *   Retrieves the EQ code corresponding to the given label.
 *
 * PARAMETERS:
 *
 *   eq_label_in_ptr -- the label for which the corresponding EQ code is
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
 *   EDCS_SC_INVALID_INPUT_LABEL - and no changes are made, if *eq_label_in_ptr
 *     does not correspond to a valid EQ.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_LabelToEQCode
(
    const EDCS_Character             *eq_label_in_ptr,
          EDCS_Unit_Equivalence_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEQCode
 *
 *   Retrieves the EQ code corresponding to the given symbolic constant name.
 *
 * PARAMETERS:
 *
 *   eq_symbolic_constant_in_ptr -- the symbolic constant for which the
 *       corresponding EQ code is requested; note that this is the
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
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT - and no changes are made, if *eq_symbolic_constant_in_ptr
 *     does not correspond to a valid EQ.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_SymbolicConstantToEQCode
(
    const EDCS_Character             *eq_symbolic_constant_in_ptr,
          EDCS_Unit_Equivalence_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_UnitEquivalenceMembership
 *
 *   Determines if the given EU is a member of the given EQ
 *
 * PARAMETERS:
 *
 *   eu_code_in -- handle to the EU code for which information is requested
 *
 *   eq_code_in -- handle to the EQ code to check membership for the given
 *                 EU code
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       the boolean result (EDCS_TRUE or EDCS_FALSE) will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REOUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_CODE - and no changes are made, if eo_code_in
 *     does not correspond to a valid EO.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_UnitEquivalenceMembership
(
    EDCS_Unit_Code             eu_code_in,
    EDCS_Unit_Equivalence_Code eq_code_in,
    EDCS_Boolean              *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitEquivalenceCode
 *
 *   Indicates if the given EQ code is a valid EDCS Unit Equivalence Class Code.
 *
 * PARAMETERS:
 *
 *   eq_code_in -- The EQ code whose validity is being checked.
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if a valid EQ code was passed in.
 *
 *   EDCS_FALSE - if a non-valid EQ code was passed in.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidUnitEquivalenceCode
(
    EDCS_Unit_Equivalence_Code eq_code_in
);

/*
 * Definition:
 *     Absorbed dose of ionizing radiation.
 *
 * Included Units:
 *     GRAY, RAD
 */
#define EQC_ABSORBED_DOSE ((EDCS_Unit_Equivalence_Code)1)

/*
 * Definition:
 *     Absorbed dose rate of ionizing radiation.
 *
 * Included Units:
 *     GRAY_PER_SECOND
 */
#define EQC_ABSORBED_DOSE_RATE ((EDCS_Unit_Equivalence_Code)2)

/*
 * Definition:
 *     Acceleration.
 *
 * Included Units:
 *     GAL, METRE_PER_SEC_SQD
 */
#define EQC_ACCELERATION ((EDCS_Unit_Equivalence_Code)3)

/*
 * Definition:
 *     Acoustic impedance.
 *
 * Included Units:
 *     PASCAL_SEC_PER_CUBIC_METRE
 */
#define EQC_ACOUSTIC_IMPEDANCE ((EDCS_Unit_Equivalence_Code)4)

/*
 * Definition:
 *     Amount of substance.
 *
 * Included Units:
 *     MOLE
 */
#define EQC_AMOUNT_SUBSTANCE ((EDCS_Unit_Equivalence_Code)5)

/*
 * Definition:
 *     Angular acceleration.
 *
 * Included Units:
 *     RADIAN_PER_SEC_SQD
 */
#define EQC_ANGULAR_ACCELERATION ((EDCS_Unit_Equivalence_Code)6)

/*
 * Definition:
 *     Angular cross-section.
 *
 * Included Units:
 *     SQ_METRE_PER_STERADIAN
 */
#define EQC_ANGULAR_CROSS_SECTION ((EDCS_Unit_Equivalence_Code)7)

/*
 * Definition:
 *     Angular impulse.
 *
 * Included Units:
 *     NEWTON_METRE_SECOND
 */
#define EQC_ANGULAR_IMPULSE ((EDCS_Unit_Equivalence_Code)8)

/*
 * Definition:
 *     Angular momentum.
 *
 * Included Units:
 *     KG_METRE_SQD_PER_SEC
 */
#define EQC_ANGULAR_MOMENTUM ((EDCS_Unit_Equivalence_Code)9)

/*
 * Definition:
 *     Angular repetency.
 *
 * Included Units:
 *     RADIAN_PER_METRE
 */
#define EQC_ANGULAR_REPETENCY ((EDCS_Unit_Equivalence_Code)10)

/*
 * Definition:
 *     Angular velocity.
 *
 * Included Units:
 *     RADIAN_PER_SEC
 */
#define EQC_ANGULAR_VELOCITY ((EDCS_Unit_Equivalence_Code)11)

/*
 * Definition:
 *     Apparent power.
 *
 * Included Units:
 *     VOLT_AMP
 */
#define EQC_APPARENT_POWER ((EDCS_Unit_Equivalence_Code)12)

/*
 * Definition:
 *     Area.
 *
 * Included Units:
 *     ARE, BARN, HECTARE, SQ_METRE
 */
#define EQC_AREA ((EDCS_Unit_Equivalence_Code)13)

/*
 * Definition:
 *     Areal entity density.
 *
 * Included Units:
 *     INV_SQ_METRE, TEC
 */
#define EQC_AREAL_ENTITY_DENSITY ((EDCS_Unit_Equivalence_Code)14)

/*
 * Definition:
 *     Areic (surface density) electric current.
 *
 * Included Units:
 *     AMP_PER_SQ_METRE
 */
#define EQC_AREIC_ELECTRIC_CURRENT ((EDCS_Unit_Equivalence_Code)15)

/*
 * Definition:
 *     Areic (surface density) power level difference.
 *
 * Included Units:
 *     DB_PER_SQ_METRE
 */
#define EQC_AREIC_POWER_LEVEL_DIFF ((EDCS_Unit_Equivalence_Code)16)

/*
 * Definition:
 *     Capacitance.
 *
 * Included Units:
 *     FARAD
 */
#define EQC_CAPACITANCE ((EDCS_Unit_Equivalence_Code)17)

/*
 * Definition:
 *     Coefficient of heat transfer.
 *
 * Included Units:
 *     WATT_PER_SQ_METRE_K
 */
#define EQC_COEFFICIENT_HEAT_TRANSFER ((EDCS_Unit_Equivalence_Code)18)

/*
 * Definition:
 *     Compressibility.
 *
 * Included Units:
 *     INV_PASCAL
 */
#define EQC_COMPRESSIBILITY ((EDCS_Unit_Equivalence_Code)19)

/*
 * Definition:
 *     Concentration.
 *
 * Included Units:
 *     MOLE_PER_CUBIC_M, MOLE_PER_LITRE
 */
#define EQC_CONCENTRATION ((EDCS_Unit_Equivalence_Code)20)

/*
 * Definition:
 *     Damping coefficient.
 *
 * Included Units:
 *     NEPER_PER_SECOND
 */
#define EQC_DAMPING_COEFFICIENT ((EDCS_Unit_Equivalence_Code)21)

/*
 * Definition:
 *     Density of states.
 *
 * Included Units:
 *     INV_CUBIC_METRE_EV, INV_CUBIC_METRE_JOULE
 */
#define EQC_DENSITY_STATES ((EDCS_Unit_Equivalence_Code)22)

/*
 * Definition:
 *     Dose equivalent of ionizing radiation.
 *
 * Included Units:
 *     REM, SIEVERT
 */
#define EQC_DOSE_EQUIVALENT ((EDCS_Unit_Equivalence_Code)23)

/*
 * Definition:
 *     Dynamic viscosity.
 *
 * Included Units:
 *     PASCAL_SEC
 */
#define EQC_DYNAMIC_VISCOSITY ((EDCS_Unit_Equivalence_Code)24)

/*
 * Definition:
 *     Electric charge.
 *
 * Included Units:
 *     COULOMB
 */
#define EQC_ELECTRIC_CHARGE ((EDCS_Unit_Equivalence_Code)25)

/*
 * Definition:
 *     Electrical conductance.
 *
 * Included Units:
 *     SIEMENS
 */
#define EQC_ELECTRIC_CONDUCTANCE ((EDCS_Unit_Equivalence_Code)26)

/*
 * Definition:
 *     Electrical conductivity.
 *
 * Included Units:
 *     SIEMENS_PER_METRE
 */
#define EQC_ELECTRIC_CONDUCTIVITY ((EDCS_Unit_Equivalence_Code)27)

/*
 * Definition:
 *     Electric current.
 *
 * Included Units:
 *     AMPERE
 */
#define EQC_ELECTRIC_CURRENT ((EDCS_Unit_Equivalence_Code)28)

/*
 * Definition:
 *     Electric dipole moment.
 *
 * Included Units:
 *     COULOMB_METRE
 */
#define EQC_ELECTRIC_DIPOLE_MOMENT ((EDCS_Unit_Equivalence_Code)29)

/*
 * Definition:
 *     Electric field strength.
 *
 * Included Units:
 *     VOLT_PER_METRE
 */
#define EQC_ELECTRIC_FIELD_STRENGTH ((EDCS_Unit_Equivalence_Code)30)

/*
 * Definition:
 *     Electric polarizability of molecule.
 *
 * Included Units:
 *     COULOMB_METRE_SQD_PER_VOLT
 */
#define EQC_ELECTRIC_POLARIZABILITY ((EDCS_Unit_Equivalence_Code)31)

/*
 * Definition:
 *     Electric potential.
 *
 * Included Units:
 *     VOLT
 */
#define EQC_ELECTRIC_POTENTIAL ((EDCS_Unit_Equivalence_Code)32)

/*
 * Definition:
 *     Energy.
 *
 * Included Units:
 *     ELECTRONVOLT, JOULE, WATT_HOUR, WATT_SECOND
 */
#define EQC_ENERGY ((EDCS_Unit_Equivalence_Code)33)

/*
 * Definition:
 *     Energy density.
 *
 * Included Units:
 *     JOULE_PER_CUBIC_M
 */
#define EQC_ENERGY_DENSITY ((EDCS_Unit_Equivalence_Code)34)

/*
 * Definition:
 *     Exposure of ionizing radiation.
 *
 * Included Units:
 *     COULOMB_PER_KG, ROENTGEN
 */
#define EQC_EXPOSURE ((EDCS_Unit_Equivalence_Code)35)

/*
 * Definition:
 *     Exposure rate of ionizing radiation.
 *
 * Included Units:
 *     COULOMB_PER_KG_SEC
 */
#define EQC_EXPOSURE_RATE ((EDCS_Unit_Equivalence_Code)36)

/*
 * Definition:
 *     Field or power level difference.
 *
 * Included Units:
 *     BEL, DB, NEPER
 */
#define EQC_FIELD_OR_POWER_LEVEL_DIFF ((EDCS_Unit_Equivalence_Code)37)

/*
 * Definition:
 *     First radiation constant.
 *
 * Included Units:
 *     WATT_SQ_METRE
 */
#define EQC_FIRST_RADIATION_CONSTANT ((EDCS_Unit_Equivalence_Code)38)

/*
 * Definition:
 *     Flux density.
 *
 * Included Units:
 *     INT_SOLAR_FLUX_UNIT, JANSKY, WATT_PER_SQ_M_HZ
 */
#define EQC_FLUX_DENSITY ((EDCS_Unit_Equivalence_Code)39)

/*
 * Definition:
 *     Force.
 *
 * Included Units:
 *     NEWTON
 */
#define EQC_FORCE ((EDCS_Unit_Equivalence_Code)40)

/*
 * Definition:
 *     Frequency.
 *
 * Included Units:
 *     HERTZ
 */
#define EQC_FREQUENCY ((EDCS_Unit_Equivalence_Code)41)

/*
 * Definition:
 *     Frequency interval.
 *
 * Included Units:
 *     OCTAVE
 */
#define EQC_FREQUENCY_INTERVAL ((EDCS_Unit_Equivalence_Code)42)

/*
 * Definition:
 *     Geopotential energy length (height).
 *
 * Included Units:
 *     GEOPOTENTIAL_METRE
 */
#define EQC_GEOPOTENTIAL_ENERGY_LENGTH ((EDCS_Unit_Equivalence_Code)43)

/*
 * Definition:
 *     Gradient of power ratio (level difference) distance and frequency
 *     gradient.
 *
 * Included Units:
 *     DB_PER_SQ_METRE_KHZ
 */
#define EQC_GRAD_POWER_LEVEL_DIFF_LEN_FREQ ((EDCS_Unit_Equivalence_Code)44)

/*
 * Definition:
 *     Gravitational force between two particles.
 *
 * Included Units:
 *     NEWTON_M_SQD_PER_KG_SQD
 */
#define EQC_GRAVITATIONAL_FORCE ((EDCS_Unit_Equivalence_Code)45)

/*
 * Definition:
 *     Gyromagnetic coefficient.
 *
 * Included Units:
 *     SQ_METRE_AMP_PER_JOULE_SEC
 */
#define EQC_GYROMAGNETIC_COEFFICIENT ((EDCS_Unit_Equivalence_Code)46)

/*
 * Definition:
 *     Heat capacity.
 *
 * Included Units:
 *     JOULE_PER_KELVIN
 */
#define EQC_HEAT_CAPACITY ((EDCS_Unit_Equivalence_Code)47)

/*
 * Definition:
 *     Illuminance.
 *
 * Included Units:
 *     LUX
 */
#define EQC_ILLUMINANCE ((EDCS_Unit_Equivalence_Code)48)

/*
 * Definition:
 *     Impulse.
 *
 * Included Units:
 *     NEWTON_SECOND
 */
#define EQC_IMPULSE ((EDCS_Unit_Equivalence_Code)49)

/*
 * Definition:
 *     Inductance.
 *
 * Included Units:
 *     HENRY
 */
#define EQC_INDUCTANCE ((EDCS_Unit_Equivalence_Code)50)

/*
 * Definition:
 *     Reciprocal length.
 *
 * Included Units:
 *     INV_METRE, INV_MICRON
 */
#define EQC_INV_LENGTH ((EDCS_Unit_Equivalence_Code)51)

/*
 * Definition:
 *     Irradiance.
 *
 * Included Units:
 *     WATT_PER_SQ_METRE
 */
#define EQC_IRRADIANCE ((EDCS_Unit_Equivalence_Code)52)

/*
 * Definition:
 *     Kinematic viscosity.
 *
 * Included Units:
 *     SQ_METRE_PER_SECOND
 */
#define EQC_KINEMATIC_VISCOSITY ((EDCS_Unit_Equivalence_Code)53)

/*
 * Definition:
 *     Length.
 *
 * Included Units:
 *     ANGSTROM, ASTRONOMICAL_UNIT, FOOT, LIGHT_YEAR, METRE, MILE,
 *     NAUTICAL_MILE, PARSEC
 */
#define EQC_LENGTH ((EDCS_Unit_Equivalence_Code)54)

/*
 * Definition:
 *     Light exposure.
 *
 * Included Units:
 *     LUX_HOUR, LUX_SECOND
 */
#define EQC_LIGHT_EXPOSURE ((EDCS_Unit_Equivalence_Code)55)

/*
 * Definition:
 *     Linear energy transfer.
 *
 * Included Units:
 *     JOULE_PER_KM, JOULE_PER_METRE
 */
#define EQC_LINEAR_ENERGY_TRANSFER ((EDCS_Unit_Equivalence_Code)56)

/*
 * Definition:
 *     Linear expansion coefficient.
 *
 * Included Units:
 *     INV_KELVIN
 */
#define EQC_LINEAR_EXPANSION_COEFF ((EDCS_Unit_Equivalence_Code)57)

/*
 * Definition:
 *     Lineic (linear density) electric current.
 *
 * Included Units:
 *     AMP_PER_METRE
 */
#define EQC_LINEIC_ELECTRIC_CURRENT ((EDCS_Unit_Equivalence_Code)58)

/*
 * Definition:
 *     Lineic (linear density) mass.
 *
 * Included Units:
 *     KG_PER_METRE
 */
#define EQC_LINEIC_MASS ((EDCS_Unit_Equivalence_Code)59)

/*
 * Definition:
 *     Lineic (linear density) thermodynamic temperature gradient.
 *
 * Included Units:
 *     DEGREE_C_PER_METRE, KELVIN_PER_KM, KELVIN_PER_METRE
 */
#define EQC_LINEIC_THERMO_TEMP_GRADIENT ((EDCS_Unit_Equivalence_Code)60)

/*
 * Definition:
 *     Lorenz coefficient.
 *
 * Included Units:
 *     VOLT_SQD_PER_KELVIN_SQD
 */
#define EQC_LORENZ_COEFFICIENT ((EDCS_Unit_Equivalence_Code)61)

/*
 * Definition:
 *     Loudness.
 *
 * Included Units:
 *     SONE
 */
#define EQC_LOUDNESS ((EDCS_Unit_Equivalence_Code)62)

/*
 * Definition:
 *     Loudness level.
 *
 * Included Units:
 *     PHON
 */
#define EQC_LOUDNESS_LEVEL ((EDCS_Unit_Equivalence_Code)63)

/*
 * Definition:
 *     Luminance.
 *
 * Included Units:
 *     CD_PER_SQ_METRE
 */
#define EQC_LUMINANCE ((EDCS_Unit_Equivalence_Code)64)

/*
 * Definition:
 *     Luminous efficacy.
 *
 * Included Units:
 *     LUMEN_PER_WATT
 */
#define EQC_LUMINANCE_EFFICIENCY ((EDCS_Unit_Equivalence_Code)65)

/*
 * Definition:
 *     Luminous exitance.
 *
 * Included Units:
 *     LUMEN_PER_SQ_METRE
 */
#define EQC_LUMINANCE_EXITANCE ((EDCS_Unit_Equivalence_Code)66)

/*
 * Definition:
 *     Luminous flux.
 *
 * Included Units:
 *     LUMEN
 */
#define EQC_LUMINANCE_FLUX ((EDCS_Unit_Equivalence_Code)67)

/*
 * Definition:
 *     Luminous intensity.
 *
 * Included Units:
 *     CANDELA
 */
#define EQC_LUMINANCE_INTENSITY ((EDCS_Unit_Equivalence_Code)68)

/*
 * Definition:
 *     Magnetic flux.
 *
 * Included Units:
 *     WEBER
 */
#define EQC_MAGNETIC_FLUX ((EDCS_Unit_Equivalence_Code)69)

/*
 * Definition:
 *     Magnetic flux density.
 *
 * Included Units:
 *     TESLA
 */
#define EQC_MAGNETIC_FLUX_DENSITY ((EDCS_Unit_Equivalence_Code)70)

/*
 * Definition:
 *     Magnetic moment.
 *
 * Included Units:
 *     SQ_METRE_AMPERE
 */
#define EQC_MAGNETIC_MOMENT ((EDCS_Unit_Equivalence_Code)71)

/*
 * Definition:
 *     Magnetic permeability.
 *
 * Included Units:
 *     HENRY_PER_METRE
 */
#define EQC_MAGNETIC_PERMEABILITY ((EDCS_Unit_Equivalence_Code)72)

/*
 * Definition:
 *     Magnetic vector potential.
 *
 * Included Units:
 *     WEBER_PER_METRE
 */
#define EQC_MAGNETIC_VECTOR_POTENTIAL ((EDCS_Unit_Equivalence_Code)73)

/*
 * Definition:
 *     Mass.
 *
 * Included Units:
 *     GRAM, KILOGRAM, KILOPOUND, LONG_TON, TON, TONNE, UNIFIED_AMASS_UNIT
 */
#define EQC_MASS ((EDCS_Unit_Equivalence_Code)74)

/*
 * Definition:
 *     Mass attenuation coefficient.
 *
 * Included Units:
 *     SQ_METRE_PER_KG
 */
#define EQC_MASS_ATTENUATION_COEFF ((EDCS_Unit_Equivalence_Code)75)

/*
 * Definition:
 *     Mass flow rate.
 *
 * Included Units:
 *     KG_PER_SECOND
 */
#define EQC_MASS_FLOW_RATE ((EDCS_Unit_Equivalence_Code)76)

/*
 * Definition:
 *     Mass fraction.
 *
 * Included Units:
 *     GRAM_PER_GRAM, GRAM_PER_KILOGRAM, KG_PER_KG, PPB_MASS_FRACTION,
 *     PPM_MASS_FRACTION, PPTH_MASS_FRACTION, PPT_MASS_FRACTION
 */
#define EQC_MASS_FRACTION ((EDCS_Unit_Equivalence_Code)77)

/*
 * Definition:
 *     Massic (specific) activity.
 *
 * Included Units:
 *     BECQUEREL_PER_KG
 */
#define EQC_MASSIC_ACTIVITY ((EDCS_Unit_Equivalence_Code)78)

/*
 * Definition:
 *     Massic (specific) optical rotatory power.
 *
 * Included Units:
 *     SQ_METRE_RADIAN_PER_KG
 */
#define EQC_MASSIC_OPTICAL_ROT_POWER ((EDCS_Unit_Equivalence_Code)79)

/*
 * Definition:
 *     Mechanical impedance.
 *
 * Included Units:
 *     NEWTON_SECOND_PER_METRE
 */
#define EQC_MECHANICAL_IMPEDANCE ((EDCS_Unit_Equivalence_Code)80)

/*
 * Definition:
 *     Mobility.
 *
 * Included Units:
 *     SQ_METRE_PER_VOLT_SECOND
 */
#define EQC_MOBILITY ((EDCS_Unit_Equivalence_Code)81)

/*
 * Definition:
 *     Molality of solute.
 *
 * Included Units:
 *     MOLE_PER_KG
 */
#define EQC_MOLALITY_SOLUTE ((EDCS_Unit_Equivalence_Code)82)

/*
 * Definition:
 *     Molar absorption coefficient.
 *
 * Included Units:
 *     SQ_METRE_PER_MOLE
 */
#define EQC_MOLAR_ABSORPTION_COEFF ((EDCS_Unit_Equivalence_Code)83)

/*
 * Definition:
 *     Molar charge.
 *
 * Included Units:
 *     COULOMB_PER_MOLE
 */
#define EQC_MOLAR_CHARGE ((EDCS_Unit_Equivalence_Code)84)

/*
 * Definition:
 *     Molar conductivity.
 *
 * Included Units:
 *     SIEMENS_M_SQD_PER_MOLE
 */
#define EQC_MOLAR_CONDUCTIVITY ((EDCS_Unit_Equivalence_Code)85)

/*
 * Definition:
 *     Molar density.
 *
 * Included Units:
 *     INV_MOLE
 */
#define EQC_MOLAR_DENSITY ((EDCS_Unit_Equivalence_Code)86)

/*
 * Definition:
 *     Molar energy.
 *
 * Included Units:
 *     JOULE_PER_MOLE
 */
#define EQC_MOLAR_ENERGY ((EDCS_Unit_Equivalence_Code)87)

/*
 * Definition:
 *     Molar entropy.
 *
 * Included Units:
 *     JOULE_PER_KELVIN_MOLE
 */
#define EQC_MOLAR_ENTROPY ((EDCS_Unit_Equivalence_Code)88)

/*
 * Definition:
 *     Molar mass.
 *
 * Included Units:
 *     KG_PER_MOLE
 */
#define EQC_MOLAR_MASS ((EDCS_Unit_Equivalence_Code)89)

/*
 * Definition:
 *     Molar optical rotatory power.
 *
 * Included Units:
 *     SQ_METRE_RADIAN_PER_MOLE
 */
#define EQC_MOLAR_OPTICAL_ROT_POWER ((EDCS_Unit_Equivalence_Code)90)

/*
 * Definition:
 *     Molar volume.
 *
 * Included Units:
 *     CUBIC_METRE_PER_MOLE
 */
#define EQC_MOLAR_VOLUME ((EDCS_Unit_Equivalence_Code)91)

/*
 * Definition:
 *     Mole fraction.
 *
 * Included Units:
 *     MOLE_PER_MOLE
 */
#define EQC_MOLE_FRACTION ((EDCS_Unit_Equivalence_Code)92)

/*
 * Definition:
 *     Moment of force.
 *
 * Included Units:
 *     NEWTON_METRE
 */
#define EQC_MOMENT_FORCE ((EDCS_Unit_Equivalence_Code)93)

/*
 * Definition:
 *     Moment of inertia.
 *
 * Included Units:
 *     KG_METRE_SQD
 */
#define EQC_MOMENT_INERTIA ((EDCS_Unit_Equivalence_Code)94)

/*
 * Definition:
 *     Momentum.
 *
 * Included Units:
 *     KG_METRE_PER_SEC
 */
#define EQC_MOMENTUM ((EDCS_Unit_Equivalence_Code)95)

/*
 * Definition:
 *     Particle current density.
 *
 * Included Units:
 *     INV_SQ_METRE_SEC
 */
#define EQC_PARTICLE_CURRENT_DENSITY ((EDCS_Unit_Equivalence_Code)96)

/*
 * Definition:
 *     Particle flux density within an energy range.
 *
 * Included Units:
 *     INV_SQ_CM_SEC_SR_EV, INV_SQ_M_SEC_SR_EV
 */
#define EQC_PARTICLE_FLUX_DENSITY ((EDCS_Unit_Equivalence_Code)97)

/*
 * Definition:
 *     Permittivity.
 *
 * Included Units:
 *     FARAD_PER_METRE
 */
#define EQC_PERMITTIVITY ((EDCS_Unit_Equivalence_Code)98)

/*
 * Definition:
 *     Photon intensity.
 *
 * Included Units:
 *     INV_SEC_STERADIAN
 */
#define EQC_PHOTON_INTENSITY ((EDCS_Unit_Equivalence_Code)99)

/*
 * Definition:
 *     Photon luminance.
 *
 * Included Units:
 *     INV_SQ_CM_SEC_STERADIAN, INV_SQ_M_SEC_STERADIAN
 */
#define EQC_PHOTON_LUMINANCE ((EDCS_Unit_Equivalence_Code)100)

/*
 * Definition:
 *     Planck constant.
 *
 * Included Units:
 *     JOULE_SECOND
 */
#define EQC_PLANCK_CONSTANT ((EDCS_Unit_Equivalence_Code)101)

/*
 * Definition:
 *     Plane angle.
 *
 * Included Units:
 *     DEGREE_ARC, GON, MINUTE_ARC, RADIAN, SECOND_ARC
 */
#define EQC_PLANE_ANGLE ((EDCS_Unit_Equivalence_Code)102)

/*
 * Definition:
 *     Power.
 *
 * Included Units:
 *     WATT
 */
#define EQC_POWER ((EDCS_Unit_Equivalence_Code)103)

/*
 * Definition:
 *     Power level difference frequency gradient.
 *
 * Included Units:
 *     DB_PER_OCTAVE
 */
#define EQC_POWER_LEVEL_DIFF_FREQ_GRADIENT ((EDCS_Unit_Equivalence_Code)104)

/*
 * Definition:
 *     Power level difference length and frequency gradient.
 *
 * Included Units:
 *     DB_PER_METRE_KHZ
 */
#define EQC_POWER_LEVEL_DIFF_LEN_FREQ ((EDCS_Unit_Equivalence_Code)105)

/*
 * Definition:
 *     Power level difference length gradient.
 *
 * Included Units:
 *     DB_PER_METRE
 */
#define EQC_POWER_LEVEL_DIFF_LEN_GRADIENT ((EDCS_Unit_Equivalence_Code)106)

/*
 * Definition:
 *     Pressure.
 *
 * Included Units:
 *     BAR, NEWTON_PER_SQ_M, PASCAL
 */
#define EQC_PRESSURE ((EDCS_Unit_Equivalence_Code)107)

/*
 * Definition:
 *     Pressure change rate.
 *
 * Included Units:
 *     PASCAL_PER_SEC
 */
#define EQC_PRESSURE_CHANGE_RATE ((EDCS_Unit_Equivalence_Code)108)

/*
 * Definition:
 *     Pressure coefficient.
 *
 * Included Units:
 *     PASCAL_PER_KELVIN
 */
#define EQC_PRESSURE_COEFFICIENT ((EDCS_Unit_Equivalence_Code)109)

/*
 * Definition:
 *     Pressure power level.
 *
 * Included Units:
 *     DB_REF_ONE_MICROPASCAL
 */
#define EQC_PRESSURE_POWER_LEVEL ((EDCS_Unit_Equivalence_Code)110)

/*
 * Definition:
 *     Pure number.
 *
 * Included Units:
 *     PERCENT, UNITLESS
 */
#define EQC_PURE_NUMBER ((EDCS_Unit_Equivalence_Code)111)

/*
 * Definition:
 *     Quantity of light.
 *
 * Included Units:
 *     LUMEN_HOUR, LUMEN_SECOND
 */
#define EQC_QUANTITY_LIGHT ((EDCS_Unit_Equivalence_Code)112)

/*
 * Definition:
 *     Radiance.
 *
 * Included Units:
 *     WATT_PER_SQ_METRE_SR
 */
#define EQC_RADIANCE ((EDCS_Unit_Equivalence_Code)113)

/*
 * Definition:
 *     Radiant energy fluence.
 *
 * Included Units:
 *     JOULE_PER_SQ_METRE
 */
#define EQC_RADIANT_ENERGY_FLUENCE ((EDCS_Unit_Equivalence_Code)114)

/*
 * Definition:
 *     Radiant exitance rate.
 *
 * Included Units:
 *     WATT_PER_SQ_CM_SEC, WATT_PER_SQ_METRE_SEC
 */
#define EQC_RADIANT_EXITANCE_RATE ((EDCS_Unit_Equivalence_Code)115)

/*
 * Definition:
 *     Radiant intensity.
 *
 * Included Units:
 *     WATT_PER_STERADIAN
 */
#define EQC_RADIANT_INTENSITY ((EDCS_Unit_Equivalence_Code)116)

/*
 * Definition:
 *     Activity of a radionuclide.
 *
 * Included Units:
 *     BECQUEREL, CURIE
 */
#define EQC_RADIONUCLIDE_ACTIVITY ((EDCS_Unit_Equivalence_Code)117)

/*
 * Definition:
 *     Rate.
 *
 * Included Units:
 *     DECAY_RATE, INV_SECOND
 */
#define EQC_RATE ((EDCS_Unit_Equivalence_Code)118)

/*
 * Definition:
 *     Reciprocal plane angle.
 *
 * Included Units:
 *     INV_RADIAN
 */
#define EQC_RECIPROCAL_PLANE_ANGLE ((EDCS_Unit_Equivalence_Code)119)

/*
 * Definition:
 *     Reciprocal solid angle.
 *
 * Included Units:
 *     INV_STERADIAN
 */
#define EQC_RECIPROCAL_SOLID_ANGLE ((EDCS_Unit_Equivalence_Code)120)

/*
 * Definition:
 *     Reciprocal volumic charge.
 *
 * Included Units:
 *     CUBIC_METRE_PER_COULOMB
 */
#define EQC_RECIPROCAL_VOLUMIC_CHARGE ((EDCS_Unit_Equivalence_Code)121)

/*
 * Definition:
 *     Reluctance.
 *
 * Included Units:
 *     INV_HENRY
 */
#define EQC_RELUCTANCE ((EDCS_Unit_Equivalence_Code)122)

/*
 * Definition:
 *     Electrical resistance.
 *
 * Included Units:
 *     OHM
 */
#define EQC_RESISTANCE ((EDCS_Unit_Equivalence_Code)123)

/*
 * Definition:
 *     Resistivity.
 *
 * Included Units:
 *     OHM_METRE
 */
#define EQC_RESISTIVITY ((EDCS_Unit_Equivalence_Code)124)

/*
 * Definition:
 *     Second moment of area.
 *
 * Included Units:
 *     METRE_FOURTH_POWER
 */
#define EQC_SECOND_MOMENT_AREA ((EDCS_Unit_Equivalence_Code)125)

/*
 * Definition:
 *     Second radiation constant.
 *
 * Included Units:
 *     METRE_KELVIN
 */
#define EQC_SECOND_RADIATION_CONSTANT ((EDCS_Unit_Equivalence_Code)126)

/*
 * Definition:
 *     Seebeck coefficient.
 *
 * Included Units:
 *     VOLT_PER_KELVIN
 */
#define EQC_SEEBECK_COEFFICIENT ((EDCS_Unit_Equivalence_Code)127)

/*
 * Definition:
 *     Solid angle.
 *
 * Included Units:
 *     STERADIAN
 */
#define EQC_SOLID_ANGLE ((EDCS_Unit_Equivalence_Code)128)

/*
 * Definition:
 *     Specific energy.
 *
 * Included Units:
 *     JOULE_PER_KG
 */
#define EQC_SPECIFIC_ENERGY ((EDCS_Unit_Equivalence_Code)129)

/*
 * Definition:
 *     Specific heat capacity.
 *
 * Included Units:
 *     JOULE_PER_GRAM_K, JOULE_PER_KG_KELVIN
 */
#define EQC_SPECIFIC_HEAT_CAPACITY ((EDCS_Unit_Equivalence_Code)130)

/*
 * Definition:
 *     Specific volume.
 *
 * Included Units:
 *     CUBIC_METRE_PER_KG
 */
#define EQC_SPECIFIC_VOLUME ((EDCS_Unit_Equivalence_Code)131)

/*
 * Definition:
 *     Spectral angular cross-section.
 *
 * Included Units:
 *     SQ_METRE_PER_JOULE_SR
 */
#define EQC_SPECTRAL_ANGULAR_CROSS_SECT ((EDCS_Unit_Equivalence_Code)132)

/*
 * Definition:
 *     Spectral concentration of vibrational modes.
 *
 * Included Units:
 *     SECOND_PER_CUBIC_M_RADIAN
 */
#define EQC_SPECTRAL_CONC_VIBRAT_MODES ((EDCS_Unit_Equivalence_Code)133)

/*
 * Definition:
 *     Spectral cross-section.
 *
 * Included Units:
 *     SQ_METRE_PER_JOULE
 */
#define EQC_SPECTRAL_CROSS_SECTION ((EDCS_Unit_Equivalence_Code)134)

/*
 * Definition:
 *     Spectral radiant energy density.
 *
 * Included Units:
 *     JOULE_PER_M_FOURTH_PWR
 */
#define EQC_SPECTRAL_RAD_ENERGY_DENSITY ((EDCS_Unit_Equivalence_Code)135)

/*
 * Definition:
 *     Spectral radiance.
 *
 * Included Units:
 *     WATT_PER_SQ_METRE_SR_MICRON
 */
#define EQC_SPECTRAL_RADIANCE ((EDCS_Unit_Equivalence_Code)136)

/*
 * Definition:
 *     Spectral radiance integrated over all directions.
 *
 * Included Units:
 *     WATT_PER_SQ_METRE_MICRON
 */
#define EQC_SPECTRAL_RADIANCE_INTEGRATED ((EDCS_Unit_Equivalence_Code)137)

/*
 * Definition:
 *     Spectral reciprocal solid angle.
 *
 * Included Units:
 *     INV_STERADIAN_METRE, INV_STERADIAN_MICRON
 */
#define EQC_SPECTRAL_RECIPROCAL_SOLID_ANGLE ((EDCS_Unit_Equivalence_Code)138)

/*
 * Definition:
 *     Speed.
 *
 * Included Units:
 *     KM_PER_HOUR, KNOT, METRE_PER_HOUR, METRE_PER_SEC, MILE_PER_HOUR
 */
#define EQC_SPEED ((EDCS_Unit_Equivalence_Code)139)

/*
 * Definition:
 *     Stefan-Boltzmann constant.
 *
 * Included Units:
 *     WATT_PER_SQ_M_K_FOURTH_PWR
 */
#define EQC_STEFAN_BOLTZMAN_CONSTANT ((EDCS_Unit_Equivalence_Code)140)

/*
 * Definition:
 *     Surface density.
 *
 * Included Units:
 *     KG_PER_SQ_METRE
 */
#define EQC_SURFACE_DENSITY ((EDCS_Unit_Equivalence_Code)141)

/*
 * Definition:
 *     Surface density of charge.
 *
 * Included Units:
 *     COULOMB_PER_SQ_M
 */
#define EQC_SURFACE_DENSITY_CHARGE ((EDCS_Unit_Equivalence_Code)142)

/*
 * Definition:
 *     Surface density of mechanical impedance.
 *
 * Included Units:
 *     PASCAL_SEC_PER_METRE
 */
#define EQC_SURFACE_DENSITY_MECH_IMPED ((EDCS_Unit_Equivalence_Code)143)

/*
 * Definition:
 *     Surface tension.
 *
 * Included Units:
 *     NEWTON_PER_METRE
 */
#define EQC_SURFACE_TENSION ((EDCS_Unit_Equivalence_Code)144)

/*
 * Definition:
 *     Thermal conductance.
 *
 * Included Units:
 *     WATT_PER_KELVIN
 */
#define EQC_THERMAL_CONDUCTANCE ((EDCS_Unit_Equivalence_Code)145)

/*
 * Definition:
 *     Thermal conductivity.
 *
 * Included Units:
 *     WATT_PER_METRE_K
 */
#define EQC_THERMAL_CONDUCTIVITY ((EDCS_Unit_Equivalence_Code)146)

/*
 * Definition:
 *     Thermal insulance.
 *
 * Included Units:
 *     SQ_METRE_KELVIN_PER_WATT
 */
#define EQC_THERMAL_INSULANCE ((EDCS_Unit_Equivalence_Code)147)

/*
 * Definition:
 *     Thermal resistance.
 *
 * Included Units:
 *     KELVIN_PER_WATT
 */
#define EQC_THERMAL_RESISTANCE ((EDCS_Unit_Equivalence_Code)148)

/*
 * Definition:
 *     Thermionic emission current density.
 *
 * Included Units:
 *     AMP_PER_SQ_M_KELVIN_SQD
 */
#define EQC_THERMION_EMISSION_CUR_DENS ((EDCS_Unit_Equivalence_Code)149)

/*
 * Definition:
 *     Thermodynamic temperature change rate.
 *
 * Included Units:
 *     DEGREE_C_PER_HOUR, DEGREE_C_PER_SEC, KELVIN_PER_SEC
 */
#define EQC_THERMO_TEMP_CHANGE_RATE ((EDCS_Unit_Equivalence_Code)150)

/*
 * Definition:
 *     Thermodynamic temperature.
 *
 * Included Units:
 *     DEGREE_C, KELVIN
 */
#define EQC_THERMO_TEMPERATURE ((EDCS_Unit_Equivalence_Code)151)

/*
 * Definition:
 *     Time.
 *
 * Included Units:
 *     DAY, HOUR, MINUTE, SECOND, YEAR
 */
#define EQC_TIME ((EDCS_Unit_Equivalence_Code)152)

/*
 * Definition:
 *     Total atomic stopping power.
 *
 * Included Units:
 *     ELECTRONVOLT_M_SQD, JOULE_METRE_SQD
 */
#define EQC_TOTAL_ATOMIC_STOPPING_POWER ((EDCS_Unit_Equivalence_Code)153)

/*
 * Definition:
 *     Total linear stopping power.
 *
 * Included Units:
 *     ELECTRONVOLT_PER_METRE
 */
#define EQC_TOTAL_LINEAR_STOPPING_POWER ((EDCS_Unit_Equivalence_Code)154)

/*
 * Definition:
 *     Total mass stopping power.
 *
 * Included Units:
 *     ELECTRONVOLT_M_SQD_PER_KG,  JOULE_METRE_SQD_PER_KG
 */
#define EQC_TOTAL_MASS_STOPPING_POWER ((EDCS_Unit_Equivalence_Code)155)

/*
 * Definition:
 *     Volume.
 *
 * Included Units:
 *     CUBIC_METRE, LITRE
 */
#define EQC_VOLUME ((EDCS_Unit_Equivalence_Code)156)

/*
 * Definition:
 *     Volume density of charge.
 *
 * Included Units:
 *     COULOMB_PER_CUBIC_M
 */
#define EQC_VOLUME_DENSITY_CHARGE ((EDCS_Unit_Equivalence_Code)157)

/*
 * Definition:
 *     Volume flow rate.
 *
 * Included Units:
 *     CUBIC_METRE_PER_SEC, LITRE_PER_HOUR, LITRE_PER_SECOND
 */
#define EQC_VOLUME_FLOW_RATE ((EDCS_Unit_Equivalence_Code)158)

/*
 * Definition:
 *     Volume fraction.
 *
 * Included Units:
 *     CUBIC_M_PER_CUBIC_M
 */
#define EQC_VOLUME_FRACTION ((EDCS_Unit_Equivalence_Code)159)

/*
 * Definition:
 *     Volumetric entity density.
 *
 * Included Units:
 *     INV_CUBIC_CM, INV_CUBIC_METRE
 */
#define EQC_VOLUMETRIC_ENTITY_DENSITY ((EDCS_Unit_Equivalence_Code)160)

/*
 * Definition:
 *     Volumetric entity emittance or capture rate.
 *
 * Included Units:
 *     INV_CUBIC_CM_SEC, INV_CUBIC_METRE_SEC
 */
#define EQC_VOLUMETRIC_ENTITY_EMIT_RATE ((EDCS_Unit_Equivalence_Code)161)

/*
 * Definition:
 *     Volumic activity.
 *
 * Included Units:
 *     BECQUEREL_PER_CUBIC_METRE
 */
#define EQC_VOLUMIC_ACTIVITY ((EDCS_Unit_Equivalence_Code)162)

/*
 * Definition:
 *     Volumic dose.
 *
 * Included Units:
 *     MINUTE_PER_CUBIC_METRE, SECOND_PER_CUBIC_METRE
 */
#define EQC_VOLUMIC_DOSE ((EDCS_Unit_Equivalence_Code)163)

/*
 * Definition:
 *     Volumic mass.
 *
 * Included Units:
 *     GRAM_PER_CUBIC_CM, GRAM_PER_CUBIC_M, KG_PER_CUBIC_METRE, KG_PER_LITRE,
 *     TONNE_PER_CUBIC_METRE
 */
#define EQC_VOLUMIC_MASS ((EDCS_Unit_Equivalence_Code)164)

#ifdef __cplusplus
}
#endif

#endif
