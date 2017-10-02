/*
 * FILE       : edcs_unit_equivalence_dict.c
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

#include "edcs_unit_equivalence_dict.h"
#include "edcs_internal.h"
#include "edcs_unit_dict.h"

static const EDCS_Unit_Code
EQUnitBinding[] =
{
    /* EDCS Units for EQC_ABSORBED_DOSE */
    EUC_GRAY,
    EUC_RAD,

    /* EDCS Units for EQC_ABSORBED_DOSE_RATE */
    EUC_GRAY_PER_SECOND,

    /* EDCS Units for EQC_ACCELERATION */
    EUC_GAL,
    EUC_METRE_PER_SEC_SQD,

    /* EDCS Units for EQC_ACOUSTIC_IMPEDANCE */
    EUC_PASCAL_SEC_PER_CUBIC_METRE,

    /* EDCS Units for EQC_AMOUNT_SUBSTANCE */
    EUC_MOLE,

    /* EDCS Units for EQC_ANGULAR_ACCELERATION */
    EUC_RADIAN_PER_SEC_SQD,

    /* EDCS Units for EQC_ANGULAR_CROSS_SECTION */
    EUC_SQ_METRE_PER_STERADIAN,

    /* EDCS Units for EQC_ANGULAR_IMPULSE */
    EUC_NEWTON_METRE_SECOND,

    /* EDCS Units for EQC_ANGULAR_MOMENTUM */
    EUC_KG_METRE_SQD_PER_SEC,

    /* EDCS Units for EQC_ANGULAR_REPETENCY */
    EUC_RADIAN_PER_METRE,

    /* EDCS Units for EQC_ANGULAR_VELOCITY */
    EUC_RADIAN_PER_SEC,

    /* EDCS Units for EQC_APPARENT_POWER */
    EUC_VOLT_AMP,

    /* EDCS Units for EQC_AREA */
    EUC_ARE,
    EUC_BARN,
    EUC_HECTARE,
    EUC_SQ_METRE,

    /* EDCS Units for EQC_AREAL_ENTITY_DENSITY */
    EUC_INV_SQ_METRE,
    EUC_TEC,

    /* EDCS Units for EQC_AREIC_ELECTRIC_CURRENT */
    EUC_AMP_PER_SQ_METRE,

    /* EDCS Units for EQC_AREIC_POWER_LEVEL_DIFF */
    EUC_DB_PER_SQ_METRE,

    /* EDCS Units for EQC_CAPACITANCE */
    EUC_FARAD,

    /* EDCS Units for EQC_COEFFICIENT_HEAT_TRANSFER */
    EUC_WATT_PER_SQ_METRE_K,

    /* EDCS Units for EQC_COMPRESSIBILITY */
    EUC_INV_PASCAL,

    /* EDCS Units for EQC_CONCENTRATION */
    EUC_MOLE_PER_CUBIC_M,
    EUC_MOLE_PER_LITRE,

    /* EDCS Units for EQC_DAMPING_COEFFICIENT */
    EUC_NEPER_PER_SECOND,

    /* EDCS Units for EQC_DENSITY_STATES */
    EUC_INV_CUBIC_METRE_EV,
    EUC_INV_CUBIC_METRE_JOULE,

    /* EDCS Units for EQC_DOSE_EQUIVALENT */
    EUC_REM,
    EUC_SIEVERT,

    /* EDCS Units for EQC_DYNAMIC_VISCOSITY */
    EUC_PASCAL_SEC,

    /* EDCS Units for EQC_ELECTRIC_CHARGE */
    EUC_COULOMB,

    /* EDCS Units for EQC_ELECTRIC_CONDUCTANCE */
    EUC_SIEMENS,

    /* EDCS Units for EQC_ELECTRIC_CONDUCTIVITY */
    EUC_SIEMENS_PER_METRE,

    /* EDCS Units for EQC_ELECTRIC_CURRENT */
    EUC_AMPERE,

    /* EDCS Units for EQC_ELECTRIC_DIPOLE_MOMENT */
    EUC_COULOMB_METRE,

    /* EDCS Units for EQC_ELECTRIC_FIELD_STRENGTH */
    EUC_VOLT_PER_METRE,

    /* EDCS Units for EQC_ELECTRIC_POLARIZABILITY */
    EUC_COULOMB_METRE_SQD_PER_VOLT,

    /* EDCS Units for EQC_ELECTRIC_POTENTIAL */
    EUC_VOLT,

    /* EDCS Units for EQC_ENERGY */
    EUC_ELECTRONVOLT,
    EUC_JOULE,
    EUC_WATT_HOUR,
    EUC_WATT_SECOND,

    /* EDCS Units for EQC_ENERGY_DENSITY */
    EUC_JOULE_PER_CUBIC_M,

    /* EDCS Units for EQC_EXPOSURE */
    EUC_COULOMB_PER_KG,
    EUC_ROENTGEN,

    /* EDCS Units for EQC_EXPOSURE_RATE */
    EUC_COULOMB_PER_KG_SEC,

    /* EDCS Units for EQC_FIELD_OR_POWER_LEVEL_DIFF */
    EUC_BEL,
    EUC_DB,
    EUC_NEPER,

    /* EDCS Units for EQC_FIRST_RADIATION_CONSTANT */
    EUC_WATT_SQ_METRE,

    /* EDCS Units for EQC_FLUX_DENSITY */
    EUC_INT_SOLAR_FLUX_UNIT,
    EUC_JANSKY,
    EUC_WATT_PER_SQ_M_HZ,

    /* EDCS Units for EQC_FORCE */
    EUC_NEWTON,

    /* EDCS Units for EQC_FREQUENCY */
    EUC_HERTZ,

    /* EDCS Units for EQC_FREQUENCY_INTERVAL */
    EUC_OCTAVE,

    /* EDCS Units for EQC_GEOPOTENTIAL_ENERGY_LENGTH */
    EUC_GEOPOTENTIAL_METRE,

    /* EDCS Units for EQC_GRAD_POWER_LEVEL_DIFF_LEN_FREQ */
    EUC_DB_PER_SQ_METRE_KHZ,

    /* EDCS Units for EQC_GRAVITATIONAL_FORCE */
    EUC_NEWTON_M_SQD_PER_KG_SQD,

    /* EDCS Units for EQC_GYROMAGNETIC_COEFFICIENT */
    EUC_SQ_METRE_AMP_PER_JOULE_SEC,

    /* EDCS Units for EQC_HEAT_CAPACITY */
    EUC_JOULE_PER_KELVIN,

    /* EDCS Units for EQC_ILLUMINANCE */
    EUC_LUX,

    /* EDCS Units for EQC_IMPULSE */
    EUC_NEWTON_SECOND,

    /* EDCS Units for EQC_INDUCTANCE */
    EUC_HENRY,

    /* EDCS Units for EQC_INV_LENGTH */
    EUC_INV_METRE,
    EUC_INV_MICRON,

    /* EDCS Units for EQC_IRRADIANCE */
    EUC_WATT_PER_SQ_METRE,

    /* EDCS Units for EQC_KINEMATIC_VISCOSITY */
    EUC_SQ_METRE_PER_SECOND,

    /* EDCS Units for EQC_LENGTH */
    EUC_ANGSTROM,
    EUC_ASTRONOMICAL_UNIT,
    EUC_FOOT,
    EUC_LIGHT_YEAR,
    EUC_METRE,
    EUC_MILE,
    EUC_NAUTICAL_MILE,
    EUC_PARSEC,

    /* EDCS Units for EQC_LIGHT_EXPOSURE */
    EUC_LUX_HOUR,
    EUC_LUX_SECOND,

    /* EDCS Units for EQC_LINEAR_ENERGY_TRANSFER */
    EUC_JOULE_PER_KM,
    EUC_JOULE_PER_METRE,

    /* EDCS Units for EQC_LINEAR_EXPANSION_COEFF */
    EUC_INV_KELVIN,

    /* EDCS Units for EQC_LINEIC_ELECTRIC_CURRENT */
    EUC_AMP_PER_METRE,

    /* EDCS Units for EQC_LINEIC_MASS */
    EUC_KG_PER_METRE,

    /* EDCS Units for EQC_LINEIC_THERMO_TEMP_GRADIENT */
    EUC_DEGREE_C_PER_METRE,
    EUC_KELVIN_PER_KM,
    EUC_KELVIN_PER_METRE,

    /* EDCS Units for EQC_LORENZ_COEFFICIENT */
    EUC_VOLT_SQD_PER_KELVIN_SQD,

    /* EDCS Units for EQC_LOUDNESS */
    EUC_SONE,

    /* EDCS Units for EQC_LOUDNESS_LEVEL */
    EUC_PHON,

    /* EDCS Units for EQC_LUMINANCE */
    EUC_CD_PER_SQ_METRE,

    /* EDCS Units for EQC_LUMINANCE_EFFICIENCY */
    EUC_LUMEN_PER_WATT,

    /* EDCS Units for EQC_LUMINANCE_EXITANCE */
    EUC_LUMEN_PER_SQ_METRE,

    /* EDCS Units for EQC_LUMINANCE_FLUX */
    EUC_LUMEN,

    /* EDCS Units for EQC_LUMINANCE_INTENSITY */
    EUC_CANDELA,

    /* EDCS Units for EQC_MAGNETIC_FLUX */
    EUC_WEBER,

    /* EDCS Units for EQC_MAGNETIC_FLUX_DENSITY */
    EUC_TESLA,

    /* EDCS Units for EQC_MAGNETIC_MOMENT */
    EUC_SQ_METRE_AMPERE,

    /* EDCS Units for EQC_MAGNETIC_PERMEABILITY */
    EUC_HENRY_PER_METRE,

    /* EDCS Units for EQC_MAGNETIC_VECTOR_POTENTIAL */
    EUC_WEBER_PER_METRE,

    /* EDCS Units for EQC_MASS */
    EUC_GRAM,
    EUC_KILOGRAM,
    EUC_KILOPOUND,
    EUC_LONG_TON,
    EUC_TON,
    EUC_TONNE,
    EUC_UNIFIED_AMASS_UNIT,

    /* EDCS Units for EQC_MASS_ATTENUATION_COEFF */
    EUC_SQ_METRE_PER_KG,

    /* EDCS Units for EQC_MASS_FLOW_RATE */
    EUC_KG_PER_SECOND,

    /* EDCS Units for EQC_MASS_FRACTION */
    EUC_GRAM_PER_GRAM,
    EUC_GRAM_PER_KILOGRAM,
    EUC_KG_PER_KG,
    EUC_PPB_MASS_FRACTION,
    EUC_PPM_MASS_FRACTION,
    EUC_PPT_MASS_FRACTION,
    EUC_PPTH_MASS_FRACTION,

    /* EDCS Units for EQC_MASSIC_ACTIVITY */
    EUC_BECQUEREL_PER_KG,

    /* EDCS Units for EQC_MASSIC_OPTICAL_ROT_POWER */
    EUC_SQ_METRE_RADIAN_PER_KG,

    /* EDCS Units for EQC_MECHANICAL_IMPEDANCE */
    EUC_NEWTON_SECOND_PER_METRE,

    /* EDCS Units for EQC_MOBILITY */
    EUC_SQ_METRE_PER_VOLT_SECOND,

    /* EDCS Units for EQC_MOLALITY_SOLUTE */
    EUC_MOLE_PER_KG,

    /* EDCS Units for EQC_MOLAR_ABSORPTION_COEFF */
    EUC_SQ_METRE_PER_MOLE,

    /* EDCS Units for EQC_MOLAR_CHARGE */
    EUC_COULOMB_PER_MOLE,

    /* EDCS Units for EQC_MOLAR_CONDUCTIVITY */
    EUC_SIEMENS_M_SQD_PER_MOLE,

    /* EDCS Units for EQC_MOLAR_DENSITY */
    EUC_INV_MOLE,

    /* EDCS Units for EQC_MOLAR_ENERGY */
    EUC_JOULE_PER_MOLE,

    /* EDCS Units for EQC_MOLAR_ENTROPY */
    EUC_JOULE_PER_KELVIN_MOLE,

    /* EDCS Units for EQC_MOLAR_MASS */
    EUC_KG_PER_MOLE,

    /* EDCS Units for EQC_MOLAR_OPTICAL_ROT_POWER */
    EUC_SQ_METRE_RADIAN_PER_MOLE,

    /* EDCS Units for EQC_MOLAR_VOLUME */
    EUC_CUBIC_METRE_PER_MOLE,

    /* EDCS Units for EQC_MOLE_FRACTION */
    EUC_MOLE_PER_MOLE,

    /* EDCS Units for EQC_MOMENT_FORCE */
    EUC_NEWTON_METRE,

    /* EDCS Units for EQC_MOMENT_INERTIA */
    EUC_KG_METRE_SQD,

    /* EDCS Units for EQC_MOMENTUM */
    EUC_KG_METRE_PER_SEC,

    /* EDCS Units for EQC_PARTICLE_CURRENT_DENSITY */
    EUC_INV_SQ_METRE_SEC,

    /* EDCS Units for EQC_PARTICLE_FLUX_DENSITY */
    EUC_INV_SQ_CM_SEC_SR_EV,
    EUC_INV_SQ_CM_SEC_SR_KEV,
    EUC_INV_SQ_CM_SEC_SR_MEV,
    EUC_INV_SQ_M_SEC_SR_EV,

    /* EDCS Units for EQC_PERMITTIVITY */
    EUC_FARAD_PER_METRE,

    /* EDCS Units for EQC_PHOTON_INTENSITY */
    EUC_INV_SEC_STERADIAN,

    /* EDCS Units for EQC_PHOTON_LUMINANCE */
    EUC_INV_SQ_CM_SEC_STERADIAN,
    EUC_INV_SQ_M_SEC_STERADIAN,

    /* EDCS Units for EQC_PLANCK_CONSTANT */
    EUC_JOULE_SECOND,

    /* EDCS Units for EQC_PLANE_ANGLE */
    EUC_DEGREE_ARC,
    EUC_GON,
    EUC_MINUTE_ARC,
    EUC_RADIAN,
    EUC_SECOND_ARC,

    /* EDCS Units for EQC_POWER */
    EUC_WATT,

    /* EDCS Units for EQC_POWER_LEVEL_DIFF_FREQ_GRADIENT */
    EUC_DB_PER_OCTAVE,

    /* EDCS Units for EQC_POWER_LEVEL_DIFF_LEN_FREQ */
    EUC_DB_PER_METRE_KHZ,

    /* EDCS Units for EQC_POWER_LEVEL_DIFF_LEN_GRADIENT */
    EUC_DB_PER_METRE,

    /* EDCS Units for EQC_PRESSURE */
    EUC_BAR,
    EUC_NEWTON_PER_SQ_M,
    EUC_PASCAL,

    /* EDCS Units for EQC_PRESSURE_CHANGE_RATE */
    EUC_PASCAL_PER_SEC,

    /* EDCS Units for EQC_PRESSURE_COEFFICIENT */
    EUC_PASCAL_PER_KELVIN,

    /* EDCS Units for EQC_PRESSURE_POWER_LEVEL */
    EUC_DB_REF_ONE_MICROPASCAL,

    /* EDCS Units for EQC_PURE_NUMBER */
    EUC_PERCENT,
    EUC_UNITLESS,

    /* EDCS Units for EQC_QUANTITY_LIGHT */
    EUC_LUMEN_HOUR,
    EUC_LUMEN_SECOND,

    /* EDCS Units for EQC_RADIANCE */
    EUC_WATT_PER_SQ_METRE_SR,

    /* EDCS Units for EQC_RADIANT_ENERGY_FLUENCE */
    EUC_JOULE_PER_SQ_METRE,

    /* EDCS Units for EQC_RADIANT_EXITANCE_RATE */
    EUC_WATT_PER_SQ_CM_SEC,
    EUC_WATT_PER_SQ_METRE_SEC,

    /* EDCS Units for EQC_RADIANT_INTENSITY */
    EUC_WATT_PER_STERADIAN,

    /* EDCS Units for EQC_RADIONUCLIDE_ACTIVITY */
    EUC_BECQUEREL,
    EUC_CURIE,

    /* EDCS Units for EQC_RATE */
    EUC_DECAY_RATE,
    EUC_INV_SECOND,

    /* EDCS Units for EQC_RECIPROCAL_PLANE_ANGLE */
    EUC_INV_RADIAN,

    /* EDCS Units for EQC_RECIPROCAL_SOLID_ANGLE */
    EUC_INV_STERADIAN,

    /* EDCS Units for EQC_RECIPROCAL_VOLUMIC_CHARGE */
    EUC_CUBIC_METRE_PER_COULOMB,

    /* EDCS Units for EQC_RELUCTANCE */
    EUC_INV_HENRY,

    /* EDCS Units for EQC_RESISTANCE */
    EUC_OHM,

    /* EDCS Units for EQC_RESISTIVITY */
    EUC_OHM_METRE,

    /* EDCS Units for EQC_SECOND_MOMENT_AREA */
    EUC_METRE_FOURTH_POWER,

    /* EDCS Units for EQC_SECOND_RADIATION_CONSTANT */
    EUC_METRE_KELVIN,

    /* EDCS Units for EQC_SEEBECK_COEFFICIENT */
    EUC_VOLT_PER_KELVIN,

    /* EDCS Units for EQC_SOLID_ANGLE */
    EUC_STERADIAN,

    /* EDCS Units for EQC_SPECIFIC_ENERGY */
    EUC_JOULE_PER_KG,

    /* EDCS Units for EQC_SPECIFIC_HEAT_CAPACITY */
    EUC_JOULE_PER_GRAM_K,
    EUC_JOULE_PER_KG_KELVIN,

    /* EDCS Units for EQC_SPECIFIC_VOLUME */
    EUC_CUBIC_METRE_PER_KG,

    /* EDCS Units for EQC_SPECTRAL_ANGULAR_CROSS_SECT */
    EUC_SQ_METRE_PER_JOULE_SR,

    /* EDCS Units for EQC_SPECTRAL_CONC_VIBRAT_MODES */
    EUC_SECOND_PER_CUBIC_M_RADIAN,

    /* EDCS Units for EQC_SPECTRAL_CROSS_SECTION */
    EUC_SQ_METRE_PER_JOULE,

    /* EDCS Units for EQC_SPECTRAL_RAD_ENERGY_DENSITY */
    EUC_JOULE_PER_M_FOURTH_PWR,

    /* EDCS Units for EQC_SPECTRAL_RADIANCE */
    EUC_WATT_PER_SQ_METRE_SR_MICRON,

    /* EDCS Units for EQC_SPECTRAL_RADIANCE_INTEGRATED */
    EUC_WATT_PER_SQ_METRE_MICRON,

    /* EDCS Units for EQC_SPECTRAL_RECIPROCAL_SOLID_ANGLE */
    EUC_INV_STERADIAN_METRE,
    EUC_INV_STERADIAN_MICRON,

    /* EDCS Units for EQC_SPEED */
    EUC_KM_PER_HOUR,
    EUC_KNOT,
    EUC_METRE_PER_HOUR,
    EUC_METRE_PER_SEC,
    EUC_MILE_PER_HOUR,

    /* EDCS Units for EQC_STEFAN_BOLTZMAN_CONSTANT */
    EUC_WATT_PER_SQ_M_K_FOURTH_PWR,

    /* EDCS Units for EQC_SURFACE_DENSITY */
    EUC_KG_PER_SQ_METRE,

    /* EDCS Units for EQC_SURFACE_DENSITY_CHARGE */
    EUC_COULOMB_PER_SQ_M,

    /* EDCS Units for EQC_SURFACE_DENSITY_MECH_IMPED */
    EUC_PASCAL_SEC_PER_METRE,

    /* EDCS Units for EQC_SURFACE_TENSION */
    EUC_NEWTON_PER_METRE,

    /* EDCS Units for EQC_THERMAL_CONDUCTANCE */
    EUC_WATT_PER_KELVIN,

    /* EDCS Units for EQC_THERMAL_CONDUCTIVITY */
    EUC_WATT_PER_METRE_K,

    /* EDCS Units for EQC_THERMAL_INSULANCE */
    EUC_SQ_METRE_KELVIN_PER_WATT,

    /* EDCS Units for EQC_THERMAL_RESISTANCE */
    EUC_KELVIN_PER_WATT,

    /* EDCS Units for EQC_THERMION_EMISSION_CUR_DENS */
    EUC_AMP_PER_SQ_M_KELVIN_SQD,

    /* EDCS Units for EQC_THERMO_TEMP_CHANGE_RATE */
    EUC_DEGREE_C_PER_HOUR,
    EUC_DEGREE_C_PER_SEC,
    EUC_KELVIN_PER_SEC,

    /* EDCS Units for EQC_THERMO_TEMPERATURE */
    EUC_DEGREE_C,
    EUC_KELVIN,

    /* EDCS Units for EQC_TIME */
    EUC_DAY,
    EUC_HOUR,
    EUC_MINUTE,
    EUC_SECOND,
    EUC_YEAR,

    /* EDCS Units for EQC_TOTAL_ATOMIC_STOPPING_POWER */
    EUC_ELECTRONVOLT_M_SQD,
    EUC_JOULE_METRE_SQD,

    /* EDCS Units for EQC_TOTAL_LINEAR_STOPPING_POWER */
    EUC_ELECTRONVOLT_PER_METRE,

    /* EDCS Units for EQC_TOTAL_MASS_STOPPING_POWER */
    EUC_ELECTRONVOLT_M_SQD_PER_KG,
    EUC_JOULE_METRE_SQD_PER_KG,

    /* EDCS Units for EQC_VOLUME */
    EUC_CUBIC_METRE,
    EUC_LITRE,

    /* EDCS Units for EQC_VOLUME_DENSITY_CHARGE */
    EUC_COULOMB_PER_CUBIC_M,

    /* EDCS Units for EQC_VOLUME_FLOW_RATE */
    EUC_CUBIC_METRE_PER_SEC,
    EUC_LITRE_PER_HOUR,
    EUC_LITRE_PER_SECOND,

    /* EDCS Units for EQC_VOLUME_FRACTION */
    EUC_CUBIC_M_PER_CUBIC_M,

    /* EDCS Units for EQC_VOLUMETRIC_ENTITY_DENSITY */
    EUC_INV_CUBIC_CM,
    EUC_INV_CUBIC_METRE,

    /* EDCS Units for EQC_VOLUMETRIC_ENTITY_EMIT_RATE */
    EUC_INV_CUBIC_CM_SEC,
    EUC_INV_CUBIC_METRE_SEC,

    /* EDCS Units for EQC_VOLUMIC_ACTIVITY */
    EUC_BECQUEREL_PER_CUBIC_METRE,

    /* EDCS Units for EQC_VOLUMIC_DOSE */
    EUC_MINUTE_PER_CUBIC_METRE,
    EUC_SECOND_PER_CUBIC_METRE,

    /* EDCS Units for EQC_VOLUMIC_MASS */
    EUC_GRAM_PER_CUBIC_CM,
    EUC_GRAM_PER_CUBIC_M,
    EUC_KG_PER_CUBIC_METRE,
    EUC_KG_PER_LITRE,
    EUC_TONNE_PER_CUBIC_METRE

}; /* end EQUnitBinding */

static const EDCS_Unit_Equivalence_Dictionary_Entry
EDCS_Unit_Equivalence_Dictionary[] =
{
    {EQC_ABSORBED_DOSE,
    "ABSORBED_DOSE", "EQC_ABSORBED_DOSE",
    "Absorbed dose of ionizing radiation.",
    2, &EQUnitBinding[0], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ABSORBED_DOSE_RATE,
    "ABSORBED_DOSE_RATE", "EQC_ABSORBED_DOSE_RATE",
    "Absorbed dose rate of ionizing radiation.",
    1, &EQUnitBinding[2], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ACCELERATION,
    "ACCELERATION", "EQC_ACCELERATION",
    "Acceleration.",
    2, &EQUnitBinding[3], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ACOUSTIC_IMPEDANCE,
    "ACOUSTIC_IMPEDANCE", "EQC_ACOUSTIC_IMPEDANCE",
    "Acoustic impedance.",
    1, &EQUnitBinding[5], EDCS_CONCEPT_STAT_ISO  },

    {EQC_AMOUNT_SUBSTANCE,
    "AMOUNT_SUBSTANCE", "EQC_AMOUNT_SUBSTANCE",
    "Amount of substance.",
    1, &EQUnitBinding[6], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ANGULAR_ACCELERATION,
    "ANGULAR_ACCELERATION", "EQC_ANGULAR_ACCELERATION",
    "Angular acceleration.",
    1, &EQUnitBinding[7], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ANGULAR_CROSS_SECTION,
    "ANGULAR_CROSS_SECTION", "EQC_ANGULAR_CROSS_SECTION",
    "Angular cross-section.",
    1, &EQUnitBinding[8], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ANGULAR_IMPULSE,
    "ANGULAR_IMPULSE", "EQC_ANGULAR_IMPULSE",
    "Angular impulse.",
    1, &EQUnitBinding[9], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ANGULAR_MOMENTUM,
    "ANGULAR_MOMENTUM", "EQC_ANGULAR_MOMENTUM",
    "Angular momentum.",
    1, &EQUnitBinding[10], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ANGULAR_REPETENCY,
    "ANGULAR_REPETENCY", "EQC_ANGULAR_REPETENCY",
    "Angular repetency.",
    1, &EQUnitBinding[11], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ANGULAR_VELOCITY,
    "ANGULAR_VELOCITY", "EQC_ANGULAR_VELOCITY",
    "Angular velocity.",
    1, &EQUnitBinding[12], EDCS_CONCEPT_STAT_ISO  },

    {EQC_APPARENT_POWER,
    "APPARENT_POWER", "EQC_APPARENT_POWER",
    "Apparent power.",
    1, &EQUnitBinding[13], EDCS_CONCEPT_STAT_ISO  },

    {EQC_AREA,
    "AREA", "EQC_AREA",
    "Area.",
    4, &EQUnitBinding[14], EDCS_CONCEPT_STAT_ISO  },

    {EQC_AREAL_ENTITY_DENSITY,
    "AREAL_ENTITY_DENSITY", "EQC_AREAL_ENTITY_DENSITY",
    "Areal entity density.",
    2, &EQUnitBinding[18], EDCS_CONCEPT_STAT_ISO  },

    {EQC_AREIC_ELECTRIC_CURRENT,
    "AREIC_ELECTRIC_CURRENT", "EQC_AREIC_ELECTRIC_CURRENT",
    "Areic (surface density) electric current.",
    1, &EQUnitBinding[20], EDCS_CONCEPT_STAT_ISO  },

    {EQC_AREIC_POWER_LEVEL_DIFF,
    "AREIC_POWER_LEVEL_DIFF", "EQC_AREIC_POWER_LEVEL_DIFF",
    "Areic (surface density) power level difference.",
    1, &EQUnitBinding[21], EDCS_CONCEPT_STAT_ISO  },

    {EQC_CAPACITANCE,
    "CAPACITANCE", "EQC_CAPACITANCE",
    "Capacitance.",
    1, &EQUnitBinding[22], EDCS_CONCEPT_STAT_ISO  },

    {EQC_COEFFICIENT_HEAT_TRANSFER,
    "COEFFICIENT_HEAT_TRANSFER", "EQC_COEFFICIENT_HEAT_TRANSFER",
    "Coefficient of heat transfer.",
    1, &EQUnitBinding[23], EDCS_CONCEPT_STAT_ISO  },

    {EQC_COMPRESSIBILITY,
    "COMPRESSIBILITY", "EQC_COMPRESSIBILITY",
    "Compressibility.",
    1, &EQUnitBinding[24], EDCS_CONCEPT_STAT_ISO  },

    {EQC_CONCENTRATION,
    "CONCENTRATION", "EQC_CONCENTRATION",
    "Concentration.",
    2, &EQUnitBinding[25], EDCS_CONCEPT_STAT_ISO  },

    {EQC_DAMPING_COEFFICIENT,
    "DAMPING_COEFFICIENT", "EQC_DAMPING_COEFFICIENT",
    "Damping coefficient.",
    1, &EQUnitBinding[27], EDCS_CONCEPT_STAT_ISO  },

    {EQC_DENSITY_STATES,
    "DENSITY_STATES", "EQC_DENSITY_STATES",
    "Density of states.",
    2, &EQUnitBinding[28], EDCS_CONCEPT_STAT_ISO  },

    {EQC_DOSE_EQUIVALENT,
    "DOSE_EQUIVALENT", "EQC_DOSE_EQUIVALENT",
    "Dose equivalent of ionizing radiation.",
    2, &EQUnitBinding[30], EDCS_CONCEPT_STAT_ISO  },

    {EQC_DYNAMIC_VISCOSITY,
    "DYNAMIC_VISCOSITY", "EQC_DYNAMIC_VISCOSITY",
    "Dynamic viscosity.",
    1, &EQUnitBinding[32], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ELECTRIC_CHARGE,
    "ELECTRIC_CHARGE", "EQC_ELECTRIC_CHARGE",
    "Electric charge.",
    1, &EQUnitBinding[33], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ELECTRIC_CONDUCTANCE,
    "ELECTRIC_CONDUCTANCE", "EQC_ELECTRIC_CONDUCTANCE",
    "Electrical conductance.",
    1, &EQUnitBinding[34], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ELECTRIC_CONDUCTIVITY,
    "ELECTRIC_CONDUCTIVITY", "EQC_ELECTRIC_CONDUCTIVITY",
    "Electrical conductivity.",
    1, &EQUnitBinding[35], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ELECTRIC_CURRENT,
    "ELECTRIC_CURRENT", "EQC_ELECTRIC_CURRENT",
    "Electric current.",
    1, &EQUnitBinding[36], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ELECTRIC_DIPOLE_MOMENT,
    "ELECTRIC_DIPOLE_MOMENT", "EQC_ELECTRIC_DIPOLE_MOMENT",
    "Electric dipole moment.",
    1, &EQUnitBinding[37], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ELECTRIC_FIELD_STRENGTH,
    "ELECTRIC_FIELD_STRENGTH", "EQC_ELECTRIC_FIELD_STRENGTH",
    "Electric field strength.",
    1, &EQUnitBinding[38], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ELECTRIC_POLARIZABILITY,
    "ELECTRIC_POLARIZABILITY", "EQC_ELECTRIC_POLARIZABILITY",
    "Electric polarizability of molecule.",
    1, &EQUnitBinding[39], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ELECTRIC_POTENTIAL,
    "ELECTRIC_POTENTIAL", "EQC_ELECTRIC_POTENTIAL",
    "Electric potential.",
    1, &EQUnitBinding[40], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ENERGY,
    "ENERGY", "EQC_ENERGY",
    "Energy.",
    4, &EQUnitBinding[41], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ENERGY_DENSITY,
    "ENERGY_DENSITY", "EQC_ENERGY_DENSITY",
    "Energy density.",
    1, &EQUnitBinding[45], EDCS_CONCEPT_STAT_ISO  },

    {EQC_EXPOSURE,
    "EXPOSURE", "EQC_EXPOSURE",
    "Exposure of ionizing radiation.",
    2, &EQUnitBinding[46], EDCS_CONCEPT_STAT_ISO  },

    {EQC_EXPOSURE_RATE,
    "EXPOSURE_RATE", "EQC_EXPOSURE_RATE",
    "Exposure rate of ionizing radiation.",
    1, &EQUnitBinding[48], EDCS_CONCEPT_STAT_ISO  },

    {EQC_FIELD_OR_POWER_LEVEL_DIFF,
    "FIELD_OR_POWER_LEVEL_DIFF", "EQC_FIELD_OR_POWER_LEVEL_DIFF",
    "Field or power level difference.",
    3, &EQUnitBinding[49], EDCS_CONCEPT_STAT_ISO  },

    {EQC_FIRST_RADIATION_CONSTANT,
    "FIRST_RADIATION_CONSTANT", "EQC_FIRST_RADIATION_CONSTANT",
    "First radiation constant.",
    1, &EQUnitBinding[52], EDCS_CONCEPT_STAT_ISO  },

    {EQC_FLUX_DENSITY,
    "FLUX_DENSITY", "EQC_FLUX_DENSITY",
    "Flux density.",
    3, &EQUnitBinding[53], EDCS_CONCEPT_STAT_ISO  },

    {EQC_FORCE,
    "FORCE", "EQC_FORCE",
    "Force.",
    1, &EQUnitBinding[56], EDCS_CONCEPT_STAT_ISO  },

    {EQC_FREQUENCY,
    "FREQUENCY", "EQC_FREQUENCY",
    "Frequency.",
    1, &EQUnitBinding[57], EDCS_CONCEPT_STAT_ISO  },

    {EQC_FREQUENCY_INTERVAL,
    "FREQUENCY_INTERVAL", "EQC_FREQUENCY_INTERVAL",
    "Frequency interval.",
    1, &EQUnitBinding[58], EDCS_CONCEPT_STAT_ISO  },

    {EQC_GEOPOTENTIAL_ENERGY_LENGTH,
    "GEOPOTENTIAL_ENERGY_LENGTH", "EQC_GEOPOTENTIAL_ENERGY_LENGTH",
    "Geopotential energy length (height).",
    1, &EQUnitBinding[59], EDCS_CONCEPT_STAT_ISO  },

    {EQC_GRAD_POWER_LEVEL_DIFF_LEN_FREQ,
    "GRAD_POWER_LEVEL_DIFF_LEN_FREQ", "EQC_GRAD_POWER_LEVEL_DIFF_LEN_FREQ",
    "Gradient of power ratio (level difference) distance and frequency"
    " gradient.",
    1, &EQUnitBinding[60], EDCS_CONCEPT_STAT_ISO  },

    {EQC_GRAVITATIONAL_FORCE,
    "GRAVITATIONAL_FORCE", "EQC_GRAVITATIONAL_FORCE",
    "Gravitational force between two particles.",
    1, &EQUnitBinding[61], EDCS_CONCEPT_STAT_ISO  },

    {EQC_GYROMAGNETIC_COEFFICIENT,
    "GYROMAGNETIC_COEFFICIENT", "EQC_GYROMAGNETIC_COEFFICIENT",
    "Gyromagnetic coefficient.",
    1, &EQUnitBinding[62], EDCS_CONCEPT_STAT_ISO  },

    {EQC_HEAT_CAPACITY,
    "HEAT_CAPACITY", "EQC_HEAT_CAPACITY",
    "Heat capacity.",
    1, &EQUnitBinding[63], EDCS_CONCEPT_STAT_ISO  },

    {EQC_ILLUMINANCE,
    "ILLUMINANCE", "EQC_ILLUMINANCE",
    "Illuminance.",
    1, &EQUnitBinding[64], EDCS_CONCEPT_STAT_ISO  },

    {EQC_IMPULSE,
    "IMPULSE", "EQC_IMPULSE",
    "Impulse.",
    1, &EQUnitBinding[65], EDCS_CONCEPT_STAT_ISO  },

    {EQC_INDUCTANCE,
    "INDUCTANCE", "EQC_INDUCTANCE",
    "Inductance.",
    1, &EQUnitBinding[66], EDCS_CONCEPT_STAT_ISO  },

    {EQC_INV_LENGTH,
    "INV_LENGTH", "EQC_INV_LENGTH",
    "Reciprocal length.",
    2, &EQUnitBinding[67], EDCS_CONCEPT_STAT_ISO  },

    {EQC_IRRADIANCE,
    "IRRADIANCE", "EQC_IRRADIANCE",
    "Irradiance.",
    1, &EQUnitBinding[69], EDCS_CONCEPT_STAT_ISO  },

    {EQC_KINEMATIC_VISCOSITY,
    "KINEMATIC_VISCOSITY", "EQC_KINEMATIC_VISCOSITY",
    "Kinematic viscosity.",
    1, &EQUnitBinding[70], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LENGTH,
    "LENGTH", "EQC_LENGTH",
    "Length.",
    8, &EQUnitBinding[71], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LIGHT_EXPOSURE,
    "LIGHT_EXPOSURE", "EQC_LIGHT_EXPOSURE",
    "Light exposure.",
    2, &EQUnitBinding[79], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LINEAR_ENERGY_TRANSFER,
    "LINEAR_ENERGY_TRANSFER", "EQC_LINEAR_ENERGY_TRANSFER",
    "Linear energy transfer.",
    2, &EQUnitBinding[81], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LINEAR_EXPANSION_COEFF,
    "LINEAR_EXPANSION_COEFF", "EQC_LINEAR_EXPANSION_COEFF",
    "Linear expansion coefficient.",
    1, &EQUnitBinding[83], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LINEIC_ELECTRIC_CURRENT,
    "LINEIC_ELECTRIC_CURRENT", "EQC_LINEIC_ELECTRIC_CURRENT",
    "Lineic (linear density) electric current.",
    1, &EQUnitBinding[84], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LINEIC_MASS,
    "LINEIC_MASS", "EQC_LINEIC_MASS",
    "Lineic (linear density) mass.",
    1, &EQUnitBinding[85], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LINEIC_THERMO_TEMP_GRADIENT,
    "LINEIC_THERMO_TEMP_GRADIENT", "EQC_LINEIC_THERMO_TEMP_GRADIENT",
    "Lineic (linear density) thermodynamic temperature gradient.",
    3, &EQUnitBinding[86], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LORENZ_COEFFICIENT,
    "LORENZ_COEFFICIENT", "EQC_LORENZ_COEFFICIENT",
    "Lorenz coefficient.",
    1, &EQUnitBinding[89], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LOUDNESS,
    "LOUDNESS", "EQC_LOUDNESS",
    "Loudness.",
    1, &EQUnitBinding[90], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LOUDNESS_LEVEL,
    "LOUDNESS_LEVEL", "EQC_LOUDNESS_LEVEL",
    "Loudness level.",
    1, &EQUnitBinding[91], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LUMINANCE,
    "LUMINANCE", "EQC_LUMINANCE",
    "Luminance.",
    1, &EQUnitBinding[92], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LUMINANCE_EFFICIENCY,
    "LUMINANCE_EFFICIENCY", "EQC_LUMINANCE_EFFICIENCY",
    "Luminous efficacy.",
    1, &EQUnitBinding[93], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LUMINANCE_EXITANCE,
    "LUMINANCE_EXITANCE", "EQC_LUMINANCE_EXITANCE",
    "Luminous exitance.",
    1, &EQUnitBinding[94], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LUMINANCE_FLUX,
    "LUMINANCE_FLUX", "EQC_LUMINANCE_FLUX",
    "Luminous flux.",
    1, &EQUnitBinding[95], EDCS_CONCEPT_STAT_ISO  },

    {EQC_LUMINANCE_INTENSITY,
    "LUMINANCE_INTENSITY", "EQC_LUMINANCE_INTENSITY",
    "Luminous intensity.",
    1, &EQUnitBinding[96], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MAGNETIC_FLUX,
    "MAGNETIC_FLUX", "EQC_MAGNETIC_FLUX",
    "Magnetic flux.",
    1, &EQUnitBinding[97], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MAGNETIC_FLUX_DENSITY,
    "MAGNETIC_FLUX_DENSITY", "EQC_MAGNETIC_FLUX_DENSITY",
    "Magnetic flux density.",
    1, &EQUnitBinding[98], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MAGNETIC_MOMENT,
    "MAGNETIC_MOMENT", "EQC_MAGNETIC_MOMENT",
    "Magnetic moment.",
    1, &EQUnitBinding[99], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MAGNETIC_PERMEABILITY,
    "MAGNETIC_PERMEABILITY", "EQC_MAGNETIC_PERMEABILITY",
    "Magnetic permeability.",
    1, &EQUnitBinding[100], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MAGNETIC_VECTOR_POTENTIAL,
    "MAGNETIC_VECTOR_POTENTIAL", "EQC_MAGNETIC_VECTOR_POTENTIAL",
    "Magnetic vector potential.",
    1, &EQUnitBinding[101], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MASS,
    "MASS", "EQC_MASS",
    "Mass.",
    7, &EQUnitBinding[102], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MASS_ATTENUATION_COEFF,
    "MASS_ATTENUATION_COEFF", "EQC_MASS_ATTENUATION_COEFF",
    "Mass attenuation coefficient.",
    1, &EQUnitBinding[109], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MASS_FLOW_RATE,
    "MASS_FLOW_RATE", "EQC_MASS_FLOW_RATE",
    "Mass flow rate.",
    1, &EQUnitBinding[110], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MASS_FRACTION,
    "MASS_FRACTION", "EQC_MASS_FRACTION",
    "Mass fraction.",
    7, &EQUnitBinding[111], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MASSIC_ACTIVITY,
    "MASSIC_ACTIVITY", "EQC_MASSIC_ACTIVITY",
    "Massic (specific) activity.",
    1, &EQUnitBinding[118], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MASSIC_OPTICAL_ROT_POWER,
    "MASSIC_OPTICAL_ROT_POWER", "EQC_MASSIC_OPTICAL_ROT_POWER",
    "Massic (specific) optical rotatory power.",
    1, &EQUnitBinding[119], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MECHANICAL_IMPEDANCE,
    "MECHANICAL_IMPEDANCE", "EQC_MECHANICAL_IMPEDANCE",
    "Mechanical impedance.",
    1, &EQUnitBinding[120], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOBILITY,
    "MOBILITY", "EQC_MOBILITY",
    "Mobility.",
    1, &EQUnitBinding[121], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLALITY_SOLUTE,
    "MOLALITY_SOLUTE", "EQC_MOLALITY_SOLUTE",
    "Molality of solute.",
    1, &EQUnitBinding[122], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_ABSORPTION_COEFF,
    "MOLAR_ABSORPTION_COEFF", "EQC_MOLAR_ABSORPTION_COEFF",
    "Molar absorption coefficient.",
    1, &EQUnitBinding[123], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_CHARGE,
    "MOLAR_CHARGE", "EQC_MOLAR_CHARGE",
    "Molar charge.",
    1, &EQUnitBinding[124], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_CONDUCTIVITY,
    "MOLAR_CONDUCTIVITY", "EQC_MOLAR_CONDUCTIVITY",
    "Molar conductivity.",
    1, &EQUnitBinding[125], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_DENSITY,
    "MOLAR_DENSITY", "EQC_MOLAR_DENSITY",
    "Molar density.",
    1, &EQUnitBinding[126], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_ENERGY,
    "MOLAR_ENERGY", "EQC_MOLAR_ENERGY",
    "Molar energy.",
    1, &EQUnitBinding[127], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_ENTROPY,
    "MOLAR_ENTROPY", "EQC_MOLAR_ENTROPY",
    "Molar entropy.",
    1, &EQUnitBinding[128], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_MASS,
    "MOLAR_MASS", "EQC_MOLAR_MASS",
    "Molar mass.",
    1, &EQUnitBinding[129], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_OPTICAL_ROT_POWER,
    "MOLAR_OPTICAL_ROT_POWER", "EQC_MOLAR_OPTICAL_ROT_POWER",
    "Molar optical rotatory power.",
    1, &EQUnitBinding[130], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLAR_VOLUME,
    "MOLAR_VOLUME", "EQC_MOLAR_VOLUME",
    "Molar volume.",
    1, &EQUnitBinding[131], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOLE_FRACTION,
    "MOLE_FRACTION", "EQC_MOLE_FRACTION",
    "Mole fraction.",
    1, &EQUnitBinding[132], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOMENT_FORCE,
    "MOMENT_FORCE", "EQC_MOMENT_FORCE",
    "Moment of force.",
    1, &EQUnitBinding[133], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOMENT_INERTIA,
    "MOMENT_INERTIA", "EQC_MOMENT_INERTIA",
    "Moment of inertia.",
    1, &EQUnitBinding[134], EDCS_CONCEPT_STAT_ISO  },

    {EQC_MOMENTUM,
    "MOMENTUM", "EQC_MOMENTUM",
    "Momentum.",
    1, &EQUnitBinding[135], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PARTICLE_CURRENT_DENSITY,
    "PARTICLE_CURRENT_DENSITY", "EQC_PARTICLE_CURRENT_DENSITY",
    "Particle current density.",
    1, &EQUnitBinding[136], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PARTICLE_FLUX_DENSITY,
    "PARTICLE_FLUX_DENSITY", "EQC_PARTICLE_FLUX_DENSITY",
    "Particle flux density within an energy range.",
    4, &EQUnitBinding[137], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PERMITTIVITY,
    "PERMITTIVITY", "EQC_PERMITTIVITY",
    "Permittivity.",
    1, &EQUnitBinding[141], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PHOTON_INTENSITY,
    "PHOTON_INTENSITY", "EQC_PHOTON_INTENSITY",
    "Photon intensity.",
    1, &EQUnitBinding[142], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PHOTON_LUMINANCE,
    "PHOTON_LUMINANCE", "EQC_PHOTON_LUMINANCE",
    "Photon luminance.",
    2, &EQUnitBinding[143], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PLANCK_CONSTANT,
    "PLANCK_CONSTANT", "EQC_PLANCK_CONSTANT",
    "Planck constant.",
    1, &EQUnitBinding[145], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PLANE_ANGLE,
    "PLANE_ANGLE", "EQC_PLANE_ANGLE",
    "Plane angle.",
    5, &EQUnitBinding[146], EDCS_CONCEPT_STAT_ISO  },

    {EQC_POWER,
    "POWER", "EQC_POWER",
    "Power.",
    1, &EQUnitBinding[151], EDCS_CONCEPT_STAT_ISO  },

    {EQC_POWER_LEVEL_DIFF_FREQ_GRADIENT,
    "POWER_LEVEL_DIFF_FREQ_GRADIENT", "EQC_POWER_LEVEL_DIFF_FREQ_GRADIENT",
    "Power level difference frequency gradient.",
    1, &EQUnitBinding[152], EDCS_CONCEPT_STAT_ISO  },

    {EQC_POWER_LEVEL_DIFF_LEN_FREQ,
    "POWER_LEVEL_DIFF_LEN_FREQ", "EQC_POWER_LEVEL_DIFF_LEN_FREQ",
    "Power level difference length and frequency gradient.",
    1, &EQUnitBinding[153], EDCS_CONCEPT_STAT_ISO  },

    {EQC_POWER_LEVEL_DIFF_LEN_GRADIENT,
    "POWER_LEVEL_DIFF_LEN_GRADIENT", "EQC_POWER_LEVEL_DIFF_LEN_GRADIENT",
    "Power level difference length gradient.",
    1, &EQUnitBinding[154], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PRESSURE,
    "PRESSURE", "EQC_PRESSURE",
    "Pressure.",
    3, &EQUnitBinding[155], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PRESSURE_CHANGE_RATE,
    "PRESSURE_CHANGE_RATE", "EQC_PRESSURE_CHANGE_RATE",
    "Pressure change rate.",
    1, &EQUnitBinding[158], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PRESSURE_COEFFICIENT,
    "PRESSURE_COEFFICIENT", "EQC_PRESSURE_COEFFICIENT",
    "Pressure coefficient.",
    1, &EQUnitBinding[159], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PRESSURE_POWER_LEVEL,
    "PRESSURE_POWER_LEVEL", "EQC_PRESSURE_POWER_LEVEL",
    "Pressure power level.",
    1, &EQUnitBinding[160], EDCS_CONCEPT_STAT_ISO  },

    {EQC_PURE_NUMBER,
    "PURE_NUMBER", "EQC_PURE_NUMBER",
    "Pure number.",
    2, &EQUnitBinding[161], EDCS_CONCEPT_STAT_ISO  },

    {EQC_QUANTITY_LIGHT,
    "QUANTITY_LIGHT", "EQC_QUANTITY_LIGHT",
    "Quantity of light.",
    2, &EQUnitBinding[163], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RADIANCE,
    "RADIANCE", "EQC_RADIANCE",
    "Radiance.",
    1, &EQUnitBinding[165], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RADIANT_ENERGY_FLUENCE,
    "RADIANT_ENERGY_FLUENCE", "EQC_RADIANT_ENERGY_FLUENCE",
    "Radiant energy fluence.",
    1, &EQUnitBinding[166], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RADIANT_EXITANCE_RATE,
    "RADIANT_EXITANCE_RATE", "EQC_RADIANT_EXITANCE_RATE",
    "Radiant exitance rate.",
    2, &EQUnitBinding[167], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RADIANT_INTENSITY,
    "RADIANT_INTENSITY", "EQC_RADIANT_INTENSITY",
    "Radiant intensity.",
    1, &EQUnitBinding[169], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RADIONUCLIDE_ACTIVITY,
    "RADIONUCLIDE_ACTIVITY", "EQC_RADIONUCLIDE_ACTIVITY",
    "Activity of a radionuclide.",
    2, &EQUnitBinding[170], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RATE,
    "RATE", "EQC_RATE",
    "Rate.",
    2, &EQUnitBinding[172], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RECIPROCAL_PLANE_ANGLE,
    "RECIPROCAL_PLANE_ANGLE", "EQC_RECIPROCAL_PLANE_ANGLE",
    "Reciprocal plane angle.",
    1, &EQUnitBinding[174], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RECIPROCAL_SOLID_ANGLE,
    "RECIPROCAL_SOLID_ANGLE", "EQC_RECIPROCAL_SOLID_ANGLE",
    "Reciprocal solid angle.",
    1, &EQUnitBinding[175], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RECIPROCAL_VOLUMIC_CHARGE,
    "RECIPROCAL_VOLUMIC_CHARGE", "EQC_RECIPROCAL_VOLUMIC_CHARGE",
    "Reciprocal volumic charge.",
    1, &EQUnitBinding[176], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RELUCTANCE,
    "RELUCTANCE", "EQC_RELUCTANCE",
    "Reluctance.",
    1, &EQUnitBinding[177], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RESISTANCE,
    "RESISTANCE", "EQC_RESISTANCE",
    "Electrical resistance.",
    1, &EQUnitBinding[178], EDCS_CONCEPT_STAT_ISO  },

    {EQC_RESISTIVITY,
    "RESISTIVITY", "EQC_RESISTIVITY",
    "Resistivity.",
    1, &EQUnitBinding[179], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SECOND_MOMENT_AREA,
    "SECOND_MOMENT_AREA", "EQC_SECOND_MOMENT_AREA",
    "Second moment of area.",
    1, &EQUnitBinding[180], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SECOND_RADIATION_CONSTANT,
    "SECOND_RADIATION_CONSTANT", "EQC_SECOND_RADIATION_CONSTANT",
    "Second radiation constant.",
    1, &EQUnitBinding[181], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SEEBECK_COEFFICIENT,
    "SEEBECK_COEFFICIENT", "EQC_SEEBECK_COEFFICIENT",
    "Seebeck coefficient.",
    1, &EQUnitBinding[182], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SOLID_ANGLE,
    "SOLID_ANGLE", "EQC_SOLID_ANGLE",
    "Solid angle.",
    1, &EQUnitBinding[183], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECIFIC_ENERGY,
    "SPECIFIC_ENERGY", "EQC_SPECIFIC_ENERGY",
    "Specific energy.",
    1, &EQUnitBinding[184], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECIFIC_HEAT_CAPACITY,
    "SPECIFIC_HEAT_CAPACITY", "EQC_SPECIFIC_HEAT_CAPACITY",
    "Specific heat capacity.",
    2, &EQUnitBinding[185], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECIFIC_VOLUME,
    "SPECIFIC_VOLUME", "EQC_SPECIFIC_VOLUME",
    "Specific volume.",
    1, &EQUnitBinding[187], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECTRAL_ANGULAR_CROSS_SECT,
    "SPECTRAL_ANGULAR_CROSS_SECT", "EQC_SPECTRAL_ANGULAR_CROSS_SECT",
    "Spectral angular cross-section.",
    1, &EQUnitBinding[188], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECTRAL_CONC_VIBRAT_MODES,
    "SPECTRAL_CONC_VIBRAT_MODES", "EQC_SPECTRAL_CONC_VIBRAT_MODES",
    "Spectral concentration of vibrational modes.",
    1, &EQUnitBinding[189], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECTRAL_CROSS_SECTION,
    "SPECTRAL_CROSS_SECTION", "EQC_SPECTRAL_CROSS_SECTION",
    "Spectral cross-section.",
    1, &EQUnitBinding[190], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECTRAL_RAD_ENERGY_DENSITY,
    "SPECTRAL_RAD_ENERGY_DENSITY", "EQC_SPECTRAL_RAD_ENERGY_DENSITY",
    "Spectral radiant energy density.",
    1, &EQUnitBinding[191], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECTRAL_RADIANCE,
    "SPECTRAL_RADIANCE", "EQC_SPECTRAL_RADIANCE",
    "Spectral radiance.",
    1, &EQUnitBinding[192], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECTRAL_RADIANCE_INTEGRATED,
    "SPECTRAL_RADIANCE_INTEGRATED", "EQC_SPECTRAL_RADIANCE_INTEGRATED",
    "Spectral radiance integrated over all directions.",
    1, &EQUnitBinding[193], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPECTRAL_RECIPROCAL_SOLID_ANGLE,
    "SPECTRAL_RECIPROCAL_SOLID_ANGLE", "EQC_SPECTRAL_RECIPROCAL_SOLID_ANGLE",
    "Spectral reciprocal solid angle.",
    2, &EQUnitBinding[194], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SPEED,
    "SPEED", "EQC_SPEED",
    "Speed.",
    5, &EQUnitBinding[196], EDCS_CONCEPT_STAT_ISO  },

    {EQC_STEFAN_BOLTZMAN_CONSTANT,
    "STEFAN_BOLTZMAN_CONSTANT", "EQC_STEFAN_BOLTZMAN_CONSTANT",
    "Stefan-Boltzmann constant.",
    1, &EQUnitBinding[201], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SURFACE_DENSITY,
    "SURFACE_DENSITY", "EQC_SURFACE_DENSITY",
    "Surface density.",
    1, &EQUnitBinding[202], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SURFACE_DENSITY_CHARGE,
    "SURFACE_DENSITY_CHARGE", "EQC_SURFACE_DENSITY_CHARGE",
    "Surface density of charge.",
    1, &EQUnitBinding[203], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SURFACE_DENSITY_MECH_IMPED,
    "SURFACE_DENSITY_MECH_IMPED", "EQC_SURFACE_DENSITY_MECH_IMPED",
    "Surface density of mechanical impedance.",
    1, &EQUnitBinding[204], EDCS_CONCEPT_STAT_ISO  },

    {EQC_SURFACE_TENSION,
    "SURFACE_TENSION", "EQC_SURFACE_TENSION",
    "Surface tension.",
    1, &EQUnitBinding[205], EDCS_CONCEPT_STAT_ISO  },

    {EQC_THERMAL_CONDUCTANCE,
    "THERMAL_CONDUCTANCE", "EQC_THERMAL_CONDUCTANCE",
    "Thermal conductance.",
    1, &EQUnitBinding[206], EDCS_CONCEPT_STAT_ISO  },

    {EQC_THERMAL_CONDUCTIVITY,
    "THERMAL_CONDUCTIVITY", "EQC_THERMAL_CONDUCTIVITY",
    "Thermal conductivity.",
    1, &EQUnitBinding[207], EDCS_CONCEPT_STAT_ISO  },

    {EQC_THERMAL_INSULANCE,
    "THERMAL_INSULANCE", "EQC_THERMAL_INSULANCE",
    "Thermal insulance.",
    1, &EQUnitBinding[208], EDCS_CONCEPT_STAT_ISO  },

    {EQC_THERMAL_RESISTANCE,
    "THERMAL_RESISTANCE", "EQC_THERMAL_RESISTANCE",
    "Thermal resistance.",
    1, &EQUnitBinding[209], EDCS_CONCEPT_STAT_ISO  },

    {EQC_THERMION_EMISSION_CUR_DENS,
    "THERMION_EMISSION_CUR_DENS", "EQC_THERMION_EMISSION_CUR_DENS",
    "Thermionic emission current density.",
    1, &EQUnitBinding[210], EDCS_CONCEPT_STAT_ISO  },

    {EQC_THERMO_TEMP_CHANGE_RATE,
    "THERMO_TEMP_CHANGE_RATE", "EQC_THERMO_TEMP_CHANGE_RATE",
    "Thermodynamic temperature change rate.",
    3, &EQUnitBinding[211], EDCS_CONCEPT_STAT_ISO  },

    {EQC_THERMO_TEMPERATURE,
    "THERMO_TEMPERATURE", "EQC_THERMO_TEMPERATURE",
    "Thermodynamic temperature.",
    2, &EQUnitBinding[214], EDCS_CONCEPT_STAT_ISO  },

    {EQC_TIME,
    "TIME", "EQC_TIME",
    "Time.",
    5, &EQUnitBinding[216], EDCS_CONCEPT_STAT_ISO  },

    {EQC_TOTAL_ATOMIC_STOPPING_POWER,
    "TOTAL_ATOMIC_STOPPING_POWER", "EQC_TOTAL_ATOMIC_STOPPING_POWER",
    "Total atomic stopping power.",
    2, &EQUnitBinding[221], EDCS_CONCEPT_STAT_ISO  },

    {EQC_TOTAL_LINEAR_STOPPING_POWER,
    "TOTAL_LINEAR_STOPPING_POWER", "EQC_TOTAL_LINEAR_STOPPING_POWER",
    "Total linear stopping power.",
    1, &EQUnitBinding[223], EDCS_CONCEPT_STAT_ISO  },

    {EQC_TOTAL_MASS_STOPPING_POWER,
    "TOTAL_MASS_STOPPING_POWER", "EQC_TOTAL_MASS_STOPPING_POWER",
    "Total mass stopping power.",
    2, &EQUnitBinding[224], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUME,
    "VOLUME", "EQC_VOLUME",
    "Volume.",
    2, &EQUnitBinding[226], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUME_DENSITY_CHARGE,
    "VOLUME_DENSITY_CHARGE", "EQC_VOLUME_DENSITY_CHARGE",
    "Volume density of charge.",
    1, &EQUnitBinding[228], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUME_FLOW_RATE,
    "VOLUME_FLOW_RATE", "EQC_VOLUME_FLOW_RATE",
    "Volume flow rate.",
    3, &EQUnitBinding[229], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUME_FRACTION,
    "VOLUME_FRACTION", "EQC_VOLUME_FRACTION",
    "Volume fraction.",
    1, &EQUnitBinding[232], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUMETRIC_ENTITY_DENSITY,
    "VOLUMETRIC_ENTITY_DENSITY", "EQC_VOLUMETRIC_ENTITY_DENSITY",
    "Volumetric entity density.",
    2, &EQUnitBinding[233], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUMETRIC_ENTITY_EMIT_RATE,
    "VOLUMETRIC_ENTITY_EMIT_RATE", "EQC_VOLUMETRIC_ENTITY_EMIT_RATE",
    "Volumetric entity emittance or capture rate.",
    2, &EQUnitBinding[235], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUMIC_ACTIVITY,
    "VOLUMIC_ACTIVITY", "EQC_VOLUMIC_ACTIVITY",
    "Volumic activity.",
    1, &EQUnitBinding[237], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUMIC_DOSE,
    "VOLUMIC_DOSE", "EQC_VOLUMIC_DOSE",
    "Volumic dose.",
    2, &EQUnitBinding[238], EDCS_CONCEPT_STAT_ISO  },

    {EQC_VOLUMIC_MASS,
    "VOLUMIC_MASS", "EQC_VOLUMIC_MASS",
    "Volumic mass.",
    5, &EQUnitBinding[240], EDCS_CONCEPT_STAT_ISO  }

}; /* EDCS_Unit_Equivalence_Dictionary */

/*
 * STRUCT: EDCS_Unit_Equivalence_Label_Entry
 *
 *  Used within this file for the label lookup table.
 */
typedef struct
{
    EDCS_Unit_Equivalence_Code  code;
    EDCS_Unit_Equivalence_Label label;
} EDCS_Unit_Equivalence_Label_Entry;

static const EDCS_Unit_Equivalence_Label_Entry
EDCS_Unit_Equivalence_Labels[] =
{
    {EQC_ABSORBED_DOSE, "ABSORBED_DOSE"},
    {EQC_ABSORBED_DOSE_RATE, "ABSORBED_DOSE_RATE"},
    {EQC_ACCELERATION, "ACCELERATION"},
    {EQC_ACOUSTIC_IMPEDANCE, "ACOUSTIC_IMPEDANCE"},
    {EQC_AMOUNT_SUBSTANCE, "AMOUNT_SUBSTANCE"},
    {EQC_ANGULAR_ACCELERATION, "ANGULAR_ACCELERATION"},
    {EQC_ANGULAR_CROSS_SECTION, "ANGULAR_CROSS_SECTION"},
    {EQC_ANGULAR_IMPULSE, "ANGULAR_IMPULSE"},
    {EQC_ANGULAR_MOMENTUM, "ANGULAR_MOMENTUM"},
    {EQC_ANGULAR_REPETENCY, "ANGULAR_REPETENCY"},
    {EQC_ANGULAR_VELOCITY, "ANGULAR_VELOCITY"},
    {EQC_APPARENT_POWER, "APPARENT_POWER"},
    {EQC_AREA, "AREA"},
    {EQC_AREAL_ENTITY_DENSITY, "AREAL_ENTITY_DENSITY"},
    {EQC_AREIC_ELECTRIC_CURRENT, "AREIC_ELECTRIC_CURRENT"},
    {EQC_AREIC_POWER_LEVEL_DIFF, "AREIC_POWER_LEVEL_DIFF"},
    {EQC_CAPACITANCE, "CAPACITANCE"},
    {EQC_COEFFICIENT_HEAT_TRANSFER, "COEFFICIENT_HEAT_TRANSFER"},
    {EQC_COMPRESSIBILITY, "COMPRESSIBILITY"},
    {EQC_CONCENTRATION, "CONCENTRATION"},
    {EQC_DAMPING_COEFFICIENT, "DAMPING_COEFFICIENT"},
    {EQC_DENSITY_STATES, "DENSITY_STATES"},
    {EQC_DOSE_EQUIVALENT, "DOSE_EQUIVALENT"},
    {EQC_DYNAMIC_VISCOSITY, "DYNAMIC_VISCOSITY"},
    {EQC_ELECTRIC_CHARGE, "ELECTRIC_CHARGE"},
    {EQC_ELECTRIC_CONDUCTANCE, "ELECTRIC_CONDUCTANCE"},
    {EQC_ELECTRIC_CONDUCTIVITY, "ELECTRIC_CONDUCTIVITY"},
    {EQC_ELECTRIC_CURRENT, "ELECTRIC_CURRENT"},
    {EQC_ELECTRIC_DIPOLE_MOMENT, "ELECTRIC_DIPOLE_MOMENT"},
    {EQC_ELECTRIC_FIELD_STRENGTH, "ELECTRIC_FIELD_STRENGTH"},
    {EQC_ELECTRIC_POLARIZABILITY, "ELECTRIC_POLARIZABILITY"},
    {EQC_ELECTRIC_POTENTIAL, "ELECTRIC_POTENTIAL"},
    {EQC_ENERGY, "ENERGY"},
    {EQC_ENERGY_DENSITY, "ENERGY_DENSITY"},
    {EQC_EXPOSURE, "EXPOSURE"},
    {EQC_EXPOSURE_RATE, "EXPOSURE_RATE"},
    {EQC_FIELD_OR_POWER_LEVEL_DIFF, "FIELD_OR_POWER_LEVEL_DIFF"},
    {EQC_FIRST_RADIATION_CONSTANT, "FIRST_RADIATION_CONSTANT"},
    {EQC_FLUX_DENSITY, "FLUX_DENSITY"},
    {EQC_FORCE, "FORCE"},
    {EQC_FREQUENCY, "FREQUENCY"},
    {EQC_FREQUENCY_INTERVAL, "FREQUENCY_INTERVAL"},
    {EQC_GEOPOTENTIAL_ENERGY_LENGTH, "GEOPOTENTIAL_ENERGY_LENGTH"},
    {EQC_GRAD_POWER_LEVEL_DIFF_LEN_FREQ, "GRAD_POWER_LEVEL_DIFF_LEN_FREQ"},
    {EQC_GRAVITATIONAL_FORCE, "GRAVITATIONAL_FORCE"},
    {EQC_GYROMAGNETIC_COEFFICIENT, "GYROMAGNETIC_COEFFICIENT"},
    {EQC_HEAT_CAPACITY, "HEAT_CAPACITY"},
    {EQC_ILLUMINANCE, "ILLUMINANCE"},
    {EQC_IMPULSE, "IMPULSE"},
    {EQC_INDUCTANCE, "INDUCTANCE"},
    {EQC_INV_LENGTH, "INV_LENGTH"},
    {EQC_IRRADIANCE, "IRRADIANCE"},
    {EQC_KINEMATIC_VISCOSITY, "KINEMATIC_VISCOSITY"},
    {EQC_LENGTH, "LENGTH"},
    {EQC_LIGHT_EXPOSURE, "LIGHT_EXPOSURE"},
    {EQC_LINEAR_ENERGY_TRANSFER, "LINEAR_ENERGY_TRANSFER"},
    {EQC_LINEAR_EXPANSION_COEFF, "LINEAR_EXPANSION_COEFF"},
    {EQC_LINEIC_ELECTRIC_CURRENT, "LINEIC_ELECTRIC_CURRENT"},
    {EQC_LINEIC_MASS, "LINEIC_MASS"},
    {EQC_LINEIC_THERMO_TEMP_GRADIENT, "LINEIC_THERMO_TEMP_GRADIENT"},
    {EQC_LORENZ_COEFFICIENT, "LORENZ_COEFFICIENT"},
    {EQC_LOUDNESS, "LOUDNESS"},
    {EQC_LOUDNESS_LEVEL, "LOUDNESS_LEVEL"},
    {EQC_LUMINANCE, "LUMINANCE"},
    {EQC_LUMINANCE_EFFICIENCY, "LUMINANCE_EFFICIENCY"},
    {EQC_LUMINANCE_EXITANCE, "LUMINANCE_EXITANCE"},
    {EQC_LUMINANCE_FLUX, "LUMINANCE_FLUX"},
    {EQC_LUMINANCE_INTENSITY, "LUMINANCE_INTENSITY"},
    {EQC_MAGNETIC_FLUX, "MAGNETIC_FLUX"},
    {EQC_MAGNETIC_FLUX_DENSITY, "MAGNETIC_FLUX_DENSITY"},
    {EQC_MAGNETIC_MOMENT, "MAGNETIC_MOMENT"},
    {EQC_MAGNETIC_PERMEABILITY, "MAGNETIC_PERMEABILITY"},
    {EQC_MAGNETIC_VECTOR_POTENTIAL, "MAGNETIC_VECTOR_POTENTIAL"},
    {EQC_MASS, "MASS"},
    {EQC_MASS_ATTENUATION_COEFF, "MASS_ATTENUATION_COEFF"},
    {EQC_MASS_FLOW_RATE, "MASS_FLOW_RATE"},
    {EQC_MASS_FRACTION, "MASS_FRACTION"},
    {EQC_MASSIC_ACTIVITY, "MASSIC_ACTIVITY"},
    {EQC_MASSIC_OPTICAL_ROT_POWER, "MASSIC_OPTICAL_ROT_POWER"},
    {EQC_MECHANICAL_IMPEDANCE, "MECHANICAL_IMPEDANCE"},
    {EQC_MOBILITY, "MOBILITY"},
    {EQC_MOLALITY_SOLUTE, "MOLALITY_SOLUTE"},
    {EQC_MOLAR_ABSORPTION_COEFF, "MOLAR_ABSORPTION_COEFF"},
    {EQC_MOLAR_CHARGE, "MOLAR_CHARGE"},
    {EQC_MOLAR_CONDUCTIVITY, "MOLAR_CONDUCTIVITY"},
    {EQC_MOLAR_DENSITY, "MOLAR_DENSITY"},
    {EQC_MOLAR_ENERGY, "MOLAR_ENERGY"},
    {EQC_MOLAR_ENTROPY, "MOLAR_ENTROPY"},
    {EQC_MOLAR_MASS, "MOLAR_MASS"},
    {EQC_MOLAR_OPTICAL_ROT_POWER, "MOLAR_OPTICAL_ROT_POWER"},
    {EQC_MOLAR_VOLUME, "MOLAR_VOLUME"},
    {EQC_MOLE_FRACTION, "MOLE_FRACTION"},
    {EQC_MOMENT_FORCE, "MOMENT_FORCE"},
    {EQC_MOMENT_INERTIA, "MOMENT_INERTIA"},
    {EQC_MOMENTUM, "MOMENTUM"},
    {EQC_PARTICLE_CURRENT_DENSITY, "PARTICLE_CURRENT_DENSITY"},
    {EQC_PARTICLE_FLUX_DENSITY, "PARTICLE_FLUX_DENSITY"},
    {EQC_PERMITTIVITY, "PERMITTIVITY"},
    {EQC_PHOTON_INTENSITY, "PHOTON_INTENSITY"},
    {EQC_PHOTON_LUMINANCE, "PHOTON_LUMINANCE"},
    {EQC_PLANCK_CONSTANT, "PLANCK_CONSTANT"},
    {EQC_PLANE_ANGLE, "PLANE_ANGLE"},
    {EQC_POWER, "POWER"},
    {EQC_POWER_LEVEL_DIFF_FREQ_GRADIENT, "POWER_LEVEL_DIFF_FREQ_GRADIENT"},
    {EQC_POWER_LEVEL_DIFF_LEN_FREQ, "POWER_LEVEL_DIFF_LEN_FREQ"},
    {EQC_POWER_LEVEL_DIFF_LEN_GRADIENT, "POWER_LEVEL_DIFF_LEN_GRADIENT"},
    {EQC_PRESSURE, "PRESSURE"},
    {EQC_PRESSURE_CHANGE_RATE, "PRESSURE_CHANGE_RATE"},
    {EQC_PRESSURE_COEFFICIENT, "PRESSURE_COEFFICIENT"},
    {EQC_PRESSURE_POWER_LEVEL, "PRESSURE_POWER_LEVEL"},
    {EQC_PURE_NUMBER, "PURE_NUMBER"},
    {EQC_QUANTITY_LIGHT, "QUANTITY_LIGHT"},
    {EQC_RADIANCE, "RADIANCE"},
    {EQC_RADIANT_ENERGY_FLUENCE, "RADIANT_ENERGY_FLUENCE"},
    {EQC_RADIANT_EXITANCE_RATE, "RADIANT_EXITANCE_RATE"},
    {EQC_RADIANT_INTENSITY, "RADIANT_INTENSITY"},
    {EQC_RADIONUCLIDE_ACTIVITY, "RADIONUCLIDE_ACTIVITY"},
    {EQC_RATE, "RATE"},
    {EQC_RECIPROCAL_PLANE_ANGLE, "RECIPROCAL_PLANE_ANGLE"},
    {EQC_RECIPROCAL_SOLID_ANGLE, "RECIPROCAL_SOLID_ANGLE"},
    {EQC_RECIPROCAL_VOLUMIC_CHARGE, "RECIPROCAL_VOLUMIC_CHARGE"},
    {EQC_RELUCTANCE, "RELUCTANCE"},
    {EQC_RESISTANCE, "RESISTANCE"},
    {EQC_RESISTIVITY, "RESISTIVITY"},
    {EQC_SECOND_MOMENT_AREA, "SECOND_MOMENT_AREA"},
    {EQC_SECOND_RADIATION_CONSTANT, "SECOND_RADIATION_CONSTANT"},
    {EQC_SEEBECK_COEFFICIENT, "SEEBECK_COEFFICIENT"},
    {EQC_SOLID_ANGLE, "SOLID_ANGLE"},
    {EQC_SPECIFIC_ENERGY, "SPECIFIC_ENERGY"},
    {EQC_SPECIFIC_HEAT_CAPACITY, "SPECIFIC_HEAT_CAPACITY"},
    {EQC_SPECIFIC_VOLUME, "SPECIFIC_VOLUME"},
    {EQC_SPECTRAL_ANGULAR_CROSS_SECT, "SPECTRAL_ANGULAR_CROSS_SECT"},
    {EQC_SPECTRAL_CONC_VIBRAT_MODES, "SPECTRAL_CONC_VIBRAT_MODES"},
    {EQC_SPECTRAL_CROSS_SECTION, "SPECTRAL_CROSS_SECTION"},
    {EQC_SPECTRAL_RAD_ENERGY_DENSITY, "SPECTRAL_RAD_ENERGY_DENSITY"},
    {EQC_SPECTRAL_RADIANCE, "SPECTRAL_RADIANCE"},
    {EQC_SPECTRAL_RADIANCE_INTEGRATED, "SPECTRAL_RADIANCE_INTEGRATED"},
    {EQC_SPECTRAL_RECIPROCAL_SOLID_ANGLE, "SPECTRAL_RECIPROCAL_SOLID_ANGLE"},
    {EQC_SPEED, "SPEED"},
    {EQC_STEFAN_BOLTZMAN_CONSTANT, "STEFAN_BOLTZMAN_CONSTANT"},
    {EQC_SURFACE_DENSITY, "SURFACE_DENSITY"},
    {EQC_SURFACE_DENSITY_CHARGE, "SURFACE_DENSITY_CHARGE"},
    {EQC_SURFACE_DENSITY_MECH_IMPED, "SURFACE_DENSITY_MECH_IMPED"},
    {EQC_SURFACE_TENSION, "SURFACE_TENSION"},
    {EQC_THERMAL_CONDUCTANCE, "THERMAL_CONDUCTANCE"},
    {EQC_THERMAL_CONDUCTIVITY, "THERMAL_CONDUCTIVITY"},
    {EQC_THERMAL_INSULANCE, "THERMAL_INSULANCE"},
    {EQC_THERMAL_RESISTANCE, "THERMAL_RESISTANCE"},
    {EQC_THERMION_EMISSION_CUR_DENS, "THERMION_EMISSION_CUR_DENS"},
    {EQC_THERMO_TEMP_CHANGE_RATE, "THERMO_TEMP_CHANGE_RATE"},
    {EQC_THERMO_TEMPERATURE, "THERMO_TEMPERATURE"},
    {EQC_TIME, "TIME"},
    {EQC_TOTAL_ATOMIC_STOPPING_POWER, "TOTAL_ATOMIC_STOPPING_POWER"},
    {EQC_TOTAL_LINEAR_STOPPING_POWER, "TOTAL_LINEAR_STOPPING_POWER"},
    {EQC_TOTAL_MASS_STOPPING_POWER, "TOTAL_MASS_STOPPING_POWER"},
    {EQC_VOLUME, "VOLUME"},
    {EQC_VOLUME_DENSITY_CHARGE, "VOLUME_DENSITY_CHARGE"},
    {EQC_VOLUME_FLOW_RATE, "VOLUME_FLOW_RATE"},
    {EQC_VOLUME_FRACTION, "VOLUME_FRACTION"},
    {EQC_VOLUMETRIC_ENTITY_DENSITY, "VOLUMETRIC_ENTITY_DENSITY"},
    {EQC_VOLUMETRIC_ENTITY_EMIT_RATE, "VOLUMETRIC_ENTITY_EMIT_RATE"},
    {EQC_VOLUMIC_ACTIVITY, "VOLUMIC_ACTIVITY"},
    {EQC_VOLUMIC_DOSE, "VOLUMIC_DOSE"},
    {EQC_VOLUMIC_MASS, "VOLUMIC_MASS"}
}; /* EDCS_Unit_Equivalence_Labels */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareEQLabel
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareEQLabel
(
    const EDCS_Unit_Equivalence_Label_Entry *a_ptr,
    const EDCS_Unit_Equivalence_Label_Entry *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;

    result = edcs_strcmp(a_ptr->label, b_ptr->label);
    return result;
} /* end local_CompareEQLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEQDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetEQDictionaryEntry
(
          EDCS_Unit_Equivalence_Code               eq_code_in,
    const EDCS_Unit_Equivalence_Dictionary_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidUnitEquivalenceCode(eq_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *result_out_ptr = &(EDCS_Unit_Equivalence_Dictionary[eq_code_in-1]);
    }
    return status;
} /* end EDCS_GetEQDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEQCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_LabelToEQCode
(
    const EDCS_Character             *label_in,
          EDCS_Unit_Equivalence_Code *result_out_ptr
)
{
    EDCS_Status_Code                   status = EDCS_SC_SUCCESS;
    EDCS_Unit_Equivalence_Label_Entry *search_result_ptr = NULL, target;

    if (!label_in || !result_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
       *result_out_ptr    = (EDCS_Unit_Equivalence_Code)0;
        target.label      = label_in;
        search_result_ptr = (EDCS_Unit_Equivalence_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_Unit_Equivalence_Labels,
                               EDCS_TOTAL_EQ,
                               sizeof(EDCS_Unit_Equivalence_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_CompareEQLabel
                            );
        if (search_result_ptr)
            *result_out_ptr = search_result_ptr->code;
        else
            status = EDCS_SC_INVALID_INPUT_LABEL;
    }
    return status;
} /* end EDCS_LabelToEQCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitEquivalenceCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintUnitEquivalenceCode
(
    EDCS_Unit_Equivalence_Code eq_code_in
)
{
    static char buffer[256];

    if (!EDCS_ValidUnitEquivalenceCode(eq_code_in))
    {
        sprintf(buffer, "ERROR - ILLEGAL EDCS_Unit_Equivalence_Code VALUE (%i)",
               (int) eq_code_in);
        return buffer;
    }
    else
    {
        return EDCS_Unit_Equivalence_Dictionary[eq_code_in-1].symbolic_constant;
    }
} /* end EDCS_PrintUnitEquivalenceCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEQCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SymbolicConstantToEQCode
(
    const EDCS_Character             *symbolic_in_ptr,
          EDCS_Unit_Equivalence_Code *result_out_ptr
)
{
          EDCS_Status_Code  status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
    const EDCS_Character   *label;

    if (!symbolic_in_ptr || !result_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        /* Symbolic Constants should always be of the form EQC_<EQ_Label>, so
         * we strip off the EQC_ and use the EDCS_LabelToEQCode function
         */
        if (strstr( symbolic_in_ptr, "EQC_" ) == symbolic_in_ptr )
        {
            label = strchr( symbolic_in_ptr, '_' );

            if (label != NULL)
            {
                label++;
                status = EDCS_LabelToEQCode( label, result_out_ptr );

                /* Hand back the correct error code if the label couldn't be found */
                if (status == EDCS_SC_INVALID_INPUT_LABEL)
                {
                    status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
                }
            }
        }
    }
    return status;
} /* end EDCS_SymbolicConstantToEQCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_UnitEquivalenceMembership
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_UnitEquivalenceMembership
(
    EDCS_Unit_Code             eu_code_in,
    EDCS_Unit_Equivalence_Code eq_code_in,
    EDCS_Boolean             * result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;
    EDCS_Count i;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidUnitEquivalenceCode(eq_code_in) || !EDCS_ValidUnitCode(eu_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *result_out_ptr = EDCS_FALSE;

        for (i = 0; i < EDCS_Unit_Equivalence_Dictionary[eq_code_in-1].eu_count
                       && (*result_out_ptr == EDCS_FALSE); i++)
        {
            if (eu_code_in == EDCS_Unit_Equivalence_Dictionary[eq_code_in-1].eu_list[i])
            {
                *result_out_ptr = EDCS_TRUE;
            }
        }
    }
    return status;
}  /* end EDCS_UnitEquivalenceMembership */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitEquivalenceCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidUnitEquivalenceCode
(
    EDCS_Unit_Equivalence_Code eq_code_in
)
{
    if ((eq_code_in < 1) || (eq_code_in > EDCS_TOTAL_EQ))
    {
        return EDCS_FALSE;
    }
    else if (EDCS_Unit_Equivalence_Dictionary[eq_code_in-1].code != eq_code_in)
    {
        return EDCS_FALSE;
    }
    else
    {
        return EDCS_TRUE;
    }
} /* end EDCS_ValidUnitEquivalenceCode */
