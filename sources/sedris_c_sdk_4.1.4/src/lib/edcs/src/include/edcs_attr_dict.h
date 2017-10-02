/*
 * FILE       : edcs_attr_dict.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all EAs.
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

#ifndef _EDCS_ATTR_DICT_H_INCLUDED_
#define _EDCS_ATTR_DICT_H_INCLUDED_

#include "edcs_types.h"

#define EDCS_TOTAL_EA 1714

/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEADictionaryEntry
 *
 *   Retrieves dictionary information for the given EA.
 *
 * PARAMETERS:
 *
 *   ea_code_in -- The EA code for which information is requested
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into
 *       which a handle to the requested dictionary entry will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *       value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if any
 *       parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_CODE - and no changes are made, if ea_code_in
 *       does not correspond to a valid EA.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetEADictionaryEntry
(
          EDCS_Attribute_Code               ea_code_in,
    const EDCS_Attribute_Dictionary_Entry **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEACode
 *
 *   Retrieves the EA code corresponding to the given label.
 *
 * PARAMETERS:
 *
 *   ea_label_in_ptr -- The label for which the corresponding EA code is
 *       requested; note that this is the language-binding label, rather
 *       than the abstract label (i.e., corresponds to the C language
 *       binding standard rather than the abstract EDCS specification)
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
 *       the output will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *       value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if any
 *       parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_LABEL - and no changes are made, if *ea_label_in_ptr
 *       does not correspond to a valid EA.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_LabelToEACode
(
    const EDCS_Character      *ea_label_in_ptr,
          EDCS_Attribute_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEACode
 *
 *   Retrieves the EA code corresponding to the given symbolic constant name.
 *
 * PARAMETERS:
 *
 *   ea_symbolic_constant_in_ptr -- The symbolic constant for which the
 *        corresponding EA code is requested; note that this is the
 *        language-binding label, rather than the abstract label (i.e.,
 *        corresponds to the C language binding standard rather than the
 *        abstract EDCS specification)
 *
 *   result_out_ptr -- Pointer to a variable in the user's memory into which
 *        the output will be copied
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate value,
 *       if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if any
 *       parameter is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT - and no changes are made,
 *       if *ea_symbolic_constant_in_ptr does not correspond to a valid EA.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_SymbolicConstantToEACode
(
    const EDCS_Character       *ea_symbolic_constant_in_ptr,
          EDCS_Attribute_Code  *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidAttributeCode
 *
 *   Indicates if the given EA code is a valid EDCS Attribute Code.
 *
 * PARAMETERS:
 *
 *   ea_code_in -- The EA code whose validity is being checked.
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if a valid EA code was passed in.
 *
 *   EDCS_FALSE - if a non-valid EA code was passed in.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidAttributeCode
(
    EDCS_Attribute_Code ea_code_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitForAttribute
 *
 *   Indicates if the given EU code is valid for the given EDCS
 *   Attribute Code based on the if the attribute is of type EDCS_AVT_REAL
 *   and the unit is within the attribute's unit equivalence class.
 *
 * PARAMETERS:
 *
 *  eu_code_in -- The EU code whose validity is being checked.
 *
 *  ea_code_in -- The EA code for which the unit validity is being checked.
 *
 *  result_out_ptr -- Handle to a EDCS_Boolean in the users memory space to
 *                    where the TRUE or FALSE result will be placed.
 *
 * RETURNS:
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - if result_out_ptr is NULL.
 *
 *   EDCS_SC_INVALID_INPUT_CODE - if either eu_code_in or ea_code_in are
 *                                not valid EDCS codes.
 *
 *   EDCS_SC_SUCCESS - and result_out_ptr is set to true or false.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_ValidUnitForAttribute
(
    EDCS_Unit_Code       eu_code_in,
    EDCS_Attribute_Code  ea_code_in,
    EDCS_Boolean        *result_out_ptr
);

/*
 * Definition:
 *     The 90^(th) percentile of error in an <<ELEVATION>>; the absolute
 *     elevation accuracy.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_ABSOLUTE_ELEVATION_ACCURACY ((EDCS_Attribute_Code)1)

/*
 * Definition:
 *     The 90^(th) percentile of horizontal circular error of a <LOCATION>
 *     relative to a defined standard; the absolute horizontal accuracy.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_ABSOLUTE_HORIZONTAL_ACCURACY ((EDCS_Attribute_Code)2)

/*
 * Definition:
 *     The ratio of the <<MASS>> of water vapour to the <<VOLUME>> occupied
 *     by the mixture of water vapour and dry <AIR>; the absolute humidity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_ABSOLUTE_HUMIDITY ((EDCS_Attribute_Code)3)

/*
 * Definition:
 *     The 90^(th) percentile of angular error of a geodetic latitude value
 *     of a <LOCATION> relative to a <SURFACE_DATUM>; the absolute latitude
 *     accuracy.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, LOCATION, SURVEY
 */
#define EAC_ABSOLUTE_LATITUDE_ACCURACY ((EDCS_Attribute_Code)4)

/*
 * Definition:
 *     The 90^(th) percentile of angular error of a geodetic longitude value
 *     of a <LOCATION> relative to a <SURFACE_DATUM>; the absolute longitude
 *     accuracy.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, LOCATION, SURVEY
 */
#define EAC_ABSOLUTE_LONGITUDE_ACCURACY ((EDCS_Attribute_Code)5)

/*
 * Definition:
 *     The vertical accuracy of a <LOCATION> relative to a defined standard
 *     expressed in units of length at 90% linear error; the absolute
 *     vertical accuracy.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_ABSOLUTE_VERTICAL_ACCURACY ((EDCS_Attribute_Code)6)

/*
 * Definition:
 *     The type of access direction of an <OBJECT> in reference to allowable
 *     traffic flow.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ACSDIRTY_END
 *    EEC_ACSDIRTY_ENTRY
 *    EEC_ACSDIRTY_EXIT
 *    EEC_ACSDIRTY_START
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_ACCESS_DIRECTION_TYPE ((EDCS_Attribute_Code)7)

/*
 * Definition:
 *     The type of accessibility of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ACSSTAT_CLOSED
 *    EEC_ACSSTAT_CLOSED_LOCKED
 *    EEC_ACSSTAT_LIMITED
 *    EEC_ACSSTAT_LOCKED
 *    EEC_ACSSTAT_OPEN
 *    EEC_ACSSTAT_OPEN_LOCKED
 *    EEC_ACSSTAT_RESTRICTED
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_ACCESSIBILITY_STATUS ((EDCS_Attribute_Code)8)

/*
 * Definition:
 *     The depth of <PRECIPITATION> (water-equivalent) that accumulated over
 *     a measurement <<TIME_QUANTITY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_ACCUM_PRECIP ((EDCS_Attribute_Code)9)

/*
 * Definition:
 *     The <<ACCUM_PRECIP>> during a 24-hour <<TIME_QUANTITY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_ACCUM_PRECIP_24_HOUR ((EDCS_Attribute_Code)10)

/*
 * Definition:
 *     The <<ACCUM_PRECIP_24_HOUR>> expressed as a surface density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO, SURFACE_MATERIAL
 */
#define EAC_ACCUM_PRECIP_24_HOUR_DENSITY ((EDCS_Attribute_Code)11)

/*
 * Definition:
 *     The <<ACCUM_PRECIP>> during a 3-hour <<TIME_QUANTITY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_ACCUM_PRECIP_3_HOUR ((EDCS_Attribute_Code)12)

/*
 * Definition:
 *     The <<ACCUM_PRECIP_3_HOUR>> expressed as a surface density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: ATMOSPHERE, MATERIAL, RATE_OR_RATIO, SURFACE_MATERIAL
 */
#define EAC_ACCUM_PRECIP_3_HOUR_DENSITY ((EDCS_Attribute_Code)13)

/*
 * Definition:
 *     The <<ACCUM_PRECIP>> during a 6-hour <<TIME_QUANTITY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_ACCUM_PRECIP_6_HOUR ((EDCS_Attribute_Code)14)

/*
 * Definition:
 *     The <<ACCUM_PRECIP_6_HOUR>> expressed as a surface density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: ATMOSPHERE, MATERIAL, RATE_OR_RATIO, SURFACE_MATERIAL
 */
#define EAC_ACCUM_PRECIP_6_HOUR_DENSITY ((EDCS_Attribute_Code)15)

/*
 * Definition:
 *     The <<ACCUM_PRECIP>> expressed as a surface density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_ACCUM_PRECIP_DENSITY ((EDCS_Attribute_Code)16)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> prior to the referenced time over which a
 *     <MATERIAL> has accumulated; the accumulation period.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: MATERIAL, SURFACE, TIME
 */
#define EAC_ACCUMULATION_PERIOD ((EDCS_Attribute_Code)17)

/*
 * Definition:
 *     The category of an <<ACCUMULATION_PERIOD>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ACCUMPERCAT_ONE_SECOND
 *    EEC_ACCUMPERCAT_TWO_SECONDS
 *    EEC_ACCUMPERCAT_FIVE_SECONDS
 *    EEC_ACCUMPERCAT_TEN_SECONDS
 *    EEC_ACCUMPERCAT_FIFTEEN_SECONDS
 *    EEC_ACCUMPERCAT_THIRTY_SECONDS
 *    EEC_ACCUMPERCAT_ONE_MINUTE
 *    EEC_ACCUMPERCAT_TWO_MINUTES
 *    EEC_ACCUMPERCAT_FIVE_MINUTES
 *    EEC_ACCUMPERCAT_TEN_MINUTES
 *    EEC_ACCUMPERCAT_FIFTEEN_MINUTES
 *    EEC_ACCUMPERCAT_THIRTY_MINUTES
 *    EEC_ACCUMPERCAT_ONE_HOUR
 *    EEC_ACCUMPERCAT_TWO_HOURS
 *    EEC_ACCUMPERCAT_THREE_HOURS
 *    EEC_ACCUMPERCAT_FOUR_HOURS
 *    EEC_ACCUMPERCAT_SIX_HOURS
 *    EEC_ACCUMPERCAT_EIGHT_HOURS
 *    EEC_ACCUMPERCAT_TWELVE_HOURS
 *    EEC_ACCUMPERCAT_TWENTY_FOUR_HOURS
 *
 * Group Membership: TIME
 */
#define EAC_ACCUMULATION_PERIOD_CATEGORY ((EDCS_Attribute_Code)18)

/*
 * Definition:
 *     The quantity of acoustic energy that is lost at a specific angle due
 *     to interaction of an acoustic signal waveform with either the
 *     <WATERBODY_SURFACE> or the <WATERBODY_FLOOR>; the acoustic boundary
 *     loss.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, COMMUNICATION, RATE_OR_RATIO, WATERBODY_FLOOR, WATERBODY_SURFACE
 */
#define EAC_ACOUSTIC_BOUNDARY_LOSS ((EDCS_Attribute_Code)19)

/*
 * Definition:
 *     The electro-acoustic one-third-octave band centre <<FREQUENCY>>
 *     (approximate).
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ACCNTRFREQ_BAND_1_HZ
 *    EEC_ACCNTRFREQ_BAND_1r25_HZ
 *    EEC_ACCNTRFREQ_BAND_1r6_HZ
 *    EEC_ACCNTRFREQ_BAND_2_HZ
 *    EEC_ACCNTRFREQ_BAND_2r5_HZ
 *    EEC_ACCNTRFREQ_BAND_3r15_HZ
 *    EEC_ACCNTRFREQ_BAND_4_HZ
 *    EEC_ACCNTRFREQ_BAND_5_HZ
 *    EEC_ACCNTRFREQ_BAND_6r3_HZ
 *    EEC_ACCNTRFREQ_BAND_8_HZ
 *    EEC_ACCNTRFREQ_BAND_10_HZ
 *    EEC_ACCNTRFREQ_BAND_12r5_HZ
 *    EEC_ACCNTRFREQ_BAND_16_HZ
 *    EEC_ACCNTRFREQ_BAND_20_HZ
 *    EEC_ACCNTRFREQ_BAND_25_HZ
 *    EEC_ACCNTRFREQ_BAND_31r5_HZ
 *    EEC_ACCNTRFREQ_BAND_40_HZ
 *    EEC_ACCNTRFREQ_BAND_50_HZ
 *    EEC_ACCNTRFREQ_BAND_63_HZ
 *    EEC_ACCNTRFREQ_BAND_80_HZ
 *    EEC_ACCNTRFREQ_BAND_100_HZ
 *    EEC_ACCNTRFREQ_BAND_125_HZ
 *    EEC_ACCNTRFREQ_BAND_160_HZ
 *    EEC_ACCNTRFREQ_BAND_200_HZ
 *    EEC_ACCNTRFREQ_BAND_250_HZ
 *    EEC_ACCNTRFREQ_BAND_315_HZ
 *    EEC_ACCNTRFREQ_BAND_400_HZ
 *    EEC_ACCNTRFREQ_BAND_500_HZ
 *    EEC_ACCNTRFREQ_BAND_630_HZ
 *    EEC_ACCNTRFREQ_BAND_800_HZ
 *    EEC_ACCNTRFREQ_BAND_1000_HZ
 *    EEC_ACCNTRFREQ_BAND_1250_HZ
 *    EEC_ACCNTRFREQ_BAND_1600_HZ
 *    EEC_ACCNTRFREQ_BAND_2000_HZ
 *    EEC_ACCNTRFREQ_BAND_2500_HZ
 *    EEC_ACCNTRFREQ_BAND_3150_HZ
 *    EEC_ACCNTRFREQ_BAND_4000_HZ
 *    EEC_ACCNTRFREQ_BAND_5000_HZ
 *    EEC_ACCNTRFREQ_BAND_6300_HZ
 *    EEC_ACCNTRFREQ_BAND_8000_HZ
 *    EEC_ACCNTRFREQ_BAND_10_KHZ
 *    EEC_ACCNTRFREQ_BAND_12r5_KHZ
 *    EEC_ACCNTRFREQ_BAND_16_KHZ
 *    EEC_ACCNTRFREQ_BAND_20_KHZ
 *    EEC_ACCNTRFREQ_BAND_25_KHZ
 *    EEC_ACCNTRFREQ_BAND_31r5_KHZ
 *    EEC_ACCNTRFREQ_BAND_40_KHZ
 *    EEC_ACCNTRFREQ_BAND_50_KHZ
 *    EEC_ACCNTRFREQ_BAND_63_KHZ
 *    EEC_ACCNTRFREQ_BAND_80_KHZ
 *    EEC_ACCNTRFREQ_BAND_100_KHZ
 *    EEC_ACCNTRFREQ_BAND_125_KHZ
 *    EEC_ACCNTRFREQ_BAND_160_KHZ
 *    EEC_ACCNTRFREQ_BAND_200_KHZ
 *    EEC_ACCNTRFREQ_BAND_250_KHZ
 *    EEC_ACCNTRFREQ_BAND_315_KHZ
 *    EEC_ACCNTRFREQ_BAND_400_KHZ
 *    EEC_ACCNTRFREQ_BAND_500_KHZ
 *    EEC_ACCNTRFREQ_BAND_630_KHZ
 *    EEC_ACCNTRFREQ_BAND_800_KHZ
 *
 * Group Membership: ACOUSTIC_PHENOMENON
 */
#define EAC_ACOUSTIC_CENTRE_FREQUENCY_BAND ((EDCS_Attribute_Code)20)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the fraction of
 *     observations indicating the presence of an acoustic half-channel in a
 *     <WATERBODY>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_ACOUSTIC_HALFCHANNEL_OBSERVATION_FRACTION ((EDCS_Attribute_Code)21)

/*
 * Definition:
 *     The correction factor applied to underwater sound levels that
 *     incorporates acoustic noise related to an <AIRCRAFT> operating in the
 *     marginal ice zone.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ACOUSTIC_PHENOMENON, AIR_TRNSP, ICE, TRNSP
 */
#define EAC_ACOUSTIC_NOISE_MARGINAL_ICE_ZONE_MULTIPLIER ((EDCS_Attribute_Code)22)

/*
 * Definition:
 *     The acoustic noise level correction obtained from a spectral class
 *     curve to be applied to some base acoustic noise level in a
 *     <WATERBODY>; the acoustic noise spectral curve correction.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_ACOUSTIC_NOISE_SPECTRAL_CURVE_CORRECTION ((EDCS_Attribute_Code)23)

/*
 * Definition:
 *     The power level of acoustic energy in a <WATERBODY> measured one metre
 *     from the source acoustic centre in a defined frequency band.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_ACOUSTIC_PWR_LVL_BAND ((EDCS_Attribute_Code)24)

/*
 * Definition:
 *     The ratio of sound wave intensity in a <WATERBODY> in a one hertz band
 *     to a reference intensity measured one metre from the source; the
 *     acoustic power level spectrum.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_ACOUSTIC_PWR_LVL_SPECTRUM ((EDCS_Attribute_Code)25)

/*
 * Definition:
 *     The omnidirectional ambient noise spectrum level correction in a
 *     <WATERBODY> at a specified <<FREQUENCY>> referenced to a 50 hertz
 *     reference level; the acoustic power level spectrum correction.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_ACOUSTIC_PWR_LVL_SPECTRUM_CORRECTION ((EDCS_Attribute_Code)26)

/*
 * Definition:
 *     The type of acoustic reflection from a <WATERBODY_FLOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ACREFLNTY_FROM_WTR_BODY_FLOOR
 *    EEC_ACREFLNTY_FROM_BELOW_WTR_BODY_FLOOR
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_FLOOR
 */
#define EAC_ACOUSTIC_REFLECTION_TYPE ((EDCS_Attribute_Code)27)

/*
 * Definition:
 *     An indication that an <OBJECT> reflects acoustic energy in a specified
 *     band of <<FREQUENCY>>s; acoustic reflector.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, ACOUSTIC_PHENOMENON
 */
#define EAC_ACOUSTIC_REFLECTOR ((EDCS_Attribute_Code)28)

/*
 * Definition:
 *     The column (integrated) acoustic scattering strength (ratio of
 *     returned to incident energy) in a <WATERBODY>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREIC_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_ACOUSTIC_SCATTERING_STRENGTH ((EDCS_Attribute_Code)29)

/*
 * Definition:
 *     The ratio of the intensity of sound returned by a sonar target at a
 *     distance of one metre from the acoustic centre of the target in a
 *     specified <DIRECTION> to the incident intensity from a distant
 *     source; the acoustic target strength.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_ACOUSTIC_TARGET_STRENGTH ((EDCS_Attribute_Code)30)

/*
 * Definition:
 *     The acoustic <<TRANSMISSION_LOSS>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_ACOUSTIC_TRANSMISSION_LOSS ((EDCS_Attribute_Code)31)

/*
 * Definition:
 *     The acoustic <<FREQUENCY>> at which a volume layer scattering strength
 *     in a <WATERBODY> is reported.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_STATE
 */
#define EAC_ACOUSTIC_VOLUME_LAYER_SCATTERING_STRENGTH_FREQUENCY ((EDCS_Attribute_Code)32)

/*
 * Definition:
 *     An indication that an <OBJECT> generates intentional emissions of
 *     acoustic energy used for the purposes of detection, localization,
 *     and/or identification; active acoustic.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, ACOUSTIC_PHENOMENON
 */
#define EAC_ACTIVE_ACOUSTIC ((EDCS_Attribute_Code)33)

/*
 * Definition:
 *     The number of distinct <AERIAL>s on a <STRUCTURE>; the aerial count.
 *
 * Value Type: COUNT
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON, INFRASTRUCTURE, SUPPORT_STRUCTURE
 */
#define EAC_AERIAL_COUNT ((EDCS_Attribute_Code)34)

/*
 * Definition:
 *     The function of an <AERIAL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AERIALFN_AIR_TRAFFIC_CONTROL
 *    EEC_AERIALFN_MARINE_RADIO_SERVICE
 *    EEC_AERIALFN_PUBLIC_SAFETY
 *    EEC_AERIALFN_RADAR
 *    EEC_AERIALFN_RADIO_BROADCAST
 *    EEC_AERIALFN_SATELLITE_UPLINK
 *    EEC_AERIALFN_TELEVISION_BROADCAST
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON, INFRASTRUCTURE
 */
#define EAC_AERIAL_FUNCTION ((EDCS_Attribute_Code)35)

/*
 * Definition:
 *     The structural type of an <AERIAL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AERIALTY_DIPOLE
 *    EEC_AERIALTY_FIXED_PHASED_ARRAY
 *    EEC_AERIALTY_HORN
 *    EEC_AERIALTY_PARABOLIC
 *    EEC_AERIALTY_WHIP
 *    EEC_AERIALTY_YAGI
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON, INFRASTRUCTURE
 */
#define EAC_AERIAL_TYPE ((EDCS_Attribute_Code)36)

/*
 * Definition:
 *     The highest <<ELEVATION>> of the usable <RUNWAY>s of an <AERODROME>,
 *     measured from the MSL <SURFACE_DATUM>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define EAC_AERODROME_ELEVATION ((EDCS_Attribute_Code)37)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of emergency <LIGHTING> at an <AERODROME>. Zero
 *     means no light and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_AERODROME_EMERGENCY_LIGHTING_INTENSITY ((EDCS_Attribute_Code)38)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of external gate <LIGHTING> at an <AERODROME>.
 *     Zero means no light and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_AERODROME_GATE_LIGHTING_INTENSITY ((EDCS_Attribute_Code)39)

/*
 * Definition:
 *     The unique set of numbers preceded by the appropriate country code
 *     that enables an individual <AERODROME> to be uniquely identified
 *     within a database; the aerodrome identification.
 *
 * Value Type: STRING
 *
 * Group Membership: AIR_TRNSP, ALGORITHM_RELATED, IDENTIFICATION, TRNSP
 */
#define EAC_AERODROME_IDENTIFICATION ((EDCS_Attribute_Code)40)

/*
 * Definition:
 *     The type of an <AERODROME>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AERODTY_AERODROME
 *    EEC_AERODTY_AIRFIELD
 *    EEC_AERODTY_AIRPORT
 *    EEC_AERODTY_DAFIF_A
 *    EEC_AERODTY_DAFIF_B
 *    EEC_AERODTY_DAFIF_C
 *    EEC_AERODTY_DAFIF_D
 *    EEC_AERODTY_EMERGENCY
 *    EEC_AERODTY_GENERAL_AVIATION
 *    EEC_AERODTY_GLIDER
 *    EEC_AERODTY_HANG_GLIDER
 *    EEC_AERODTY_HELICOPTER
 *    EEC_AERODTY_HELIPORT
 *    EEC_AERODTY_HELIPORT_AT_HOSPITAL
 *    EEC_AERODTY_MAJOR_AERODROME
 *    EEC_AERODTY_MICROLIGHT
 *    EEC_AERODTY_MINOR_AERODROME
 *    EEC_AERODTY_PARASCENDING
 *    EEC_AERODTY_SEAPLANE_BASE
 *    EEC_AERODTY_UNDEFINED_LANDING
 *    EEC_AERODTY_WINCH_LAUNCHED_HANG_GLIDER
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_AERODROME_TYPE ((EDCS_Attribute_Code)41)

/*
 * Definition:
 *     The type of an aeronautical approach.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AEROAPPTY_FINAL_FIX
 *    EEC_AEROAPPTY_INITIAL_FIX
 *    EEC_AEROAPPTY_NON_PRECISION_INSTRUMENT
 *    EEC_AEROAPPTY_PRECISION_INSTRUMENT
 *    EEC_AEROAPPTY_STOL
 *    EEC_AEROAPPTY_VISUAL
 *
 * Group Membership: AIR_TRNSP
 */
#define EAC_AERONAUTICAL_APPROACH_TYPE ((EDCS_Attribute_Code)42)

/*
 * Definition:
 *     The function of an aeronautical <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AEROFN_AERODROME_TERMINAL
 *    EEC_AEROFN_AID_TO_NAVIGATION_CHANGEOVER
 *    EEC_AEROFN_ALTIMETER_CHANGE
 *    EEC_AEROFN_DECOY
 *    EEC_AEROFN_FEEDER
 *    EEC_AEROFN_MILEAGE_BREAK_DOWN
 *    EEC_AEROFN_RADAR
 *    EEC_AEROFN_SEAPLANE_RUN
 *    EEC_AEROFN_TERMINUS
 *    EEC_AEROFN_TERMINUS_OR_TERMINAL
 *    EEC_AEROFN_TRANSACTION
 *    EEC_AEROFN_UNIDENTIFIED_AIRSTRIP
 *
 * Group Membership: AIR_TRNSP
 */
#define EAC_AERONAUTICAL_FUNCTION ((EDCS_Attribute_Code)43)

/*
 * Definition:
 *     The type of <LIGHTING> or <SYSTEM> of <LIGHTING> that supports
 *     aeronautical navigation; the aeronautical light type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AEROLGTTY_AERODROME_TERMINAL
 *    EEC_AEROLGTTY_AEROMARINE
 *    EEC_AEROLGTTY_ALSF_I
 *    EEC_AEROLGTTY_ALSF_II
 *    EEC_AEROLGTTY_ALTERNATE_CENTRE_LINE
 *    EEC_AEROLGTTY_APAP_ALIGNMENT
 *    EEC_AEROLGTTY_APRON_FLOOD
 *    EEC_AEROLGTTY_ARTICULATED
 *    EEC_AEROLGTTY_AUXILIARY
 *    EEC_AEROLGTTY_BEACON_UNSPECIFIED
 *    EEC_AEROLGTTY_BLINKING_LIGHT
 *    EEC_AEROLGTTY_BOUNDARY
 *    EEC_AEROLGTTY_CALVERT
 *    EEC_AEROLGTTY_CENTRE_AND_DOUBLE_ROW
 *    EEC_AEROLGTTY_CENTRE_LINE_2_CROSSBAR
 *    EEC_AEROLGTTY_CENTRE_LINE_AND_BAR
 *    EEC_AEROLGTTY_CENTRE_LINE_HIGH_INTENSITY
 *    EEC_AEROLGTTY_CENTRE_ROW
 *    EEC_AEROLGTTY_CENTRE_ROW_1_HI_INTENSITY
 *    EEC_AEROLGTTY_CENTRE_ROW_2_HI_INTENSITY
 *    EEC_AEROLGTTY_CONSTANT_BEAM
 *    EEC_AEROLGTTY_CROSS
 *    EEC_AEROLGTTY_FISHING
 *    EEC_AEROLGTTY_FLARES
 *    EEC_AEROLGTTY_FOG_DETECTOR
 *    EEC_AEROLGTTY_FORMER_NATO_STANDARD
 *    EEC_AEROLGTTY_HARBOUR
 *    EEC_AEROLGTTY_HIGH_INTENSITY_RUNWAY
 *    EEC_AEROLGTTY_HONG_KONG_CURVE
 *    EEC_AEROLGTTY_HORIZONTAL
 *    EEC_AEROLGTTY_IDENTIFICATION_BEACON
 *    EEC_AEROLGTTY_LANDING_DIRECTION
 *    EEC_AEROLGTTY_LEFT_ROW_HIGH_INTENSITY
 *    EEC_AEROLGTTY_LEFT_SINGLE_ROW
 *    EEC_AEROLGTTY_LOW_COST_VASI
 *    EEC_AEROLGTTY_LOW_INTENSITY_RUNWAY
 *    EEC_AEROLGTTY_MAJOR
 *    EEC_AEROLGTTY_MALSF
 *    EEC_AEROLGTTY_MALSR
 *    EEC_AEROLGTTY_MEDIUM_INTENSITY_RUNWAY
 *    EEC_AEROLGTTY_MINOR
 *    EEC_AEROLGTTY_NARROW_MULTI_CROSS
 *    EEC_AEROLGTTY_NATO_STANDARD
 *    EEC_AEROLGTTY_NEON_LADDER
 *    EEC_AEROLGTTY_NONE_AVAILABLE
 *    EEC_AEROLGTTY_OBSTRUCTION
 *    EEC_AEROLGTTY_OBSTRUCTION_LIGHTING
 *    EEC_AEROLGTTY_OCCASIONAL
 *    EEC_AEROLGTTY_ODALS
 *    EEC_AEROLGTTY_OPTICAL_LANDING_SYSTEM
 *    EEC_AEROLGTTY_OTHER_AERODROME_LIGHTING
 *    EEC_AEROLGTTY_OTHER_APPROACH_LIGHTING
 *    EEC_AEROLGTTY_OVERRUN_CENTRE_LINE
 *    EEC_AEROLGTTY_PORTABLE_APPROACH
 *    EEC_AEROLGTTY_PORTABLE_RUNWAY
 *    EEC_AEROLGTTY_PRECISION_APPROACH
 *    EEC_AEROLGTTY_PRIMARY
 *    EEC_AEROLGTTY_PRIVATE
 *    EEC_AEROLGTTY_RAIL
 *    EEC_AEROLGTTY_RANGE
 *    EEC_AEROLGTTY_ROTATING_BEACON
 *    EEC_AEROLGTTY_RUNWAY
 *    EEC_AEROLGTTY_RUNWAY_CENTRE_LINE
 *    EEC_AEROLGTTY_RUNWAY_EDGE
 *    EEC_AEROLGTTY_RUNWAY_END
 *    EEC_AEROLGTTY_RUNWAY_FLOOD
 *    EEC_AEROLGTTY_RUNWAY_REGION
 *    EEC_AEROLGTTY_SEASONAL
 *    EEC_AEROLGTTY_SECONDARY
 *    EEC_AEROLGTTY_SEQUENCED_STROBE
 *    EEC_AEROLGTTY_SINGAPORE_CENTRE_LINE
 *    EEC_AEROLGTTY_SINGLE_ROW_CENTRE_LINE
 *    EEC_AEROLGTTY_SSALF
 *    EEC_AEROLGTTY_SSALR
 *    EEC_AEROLGTTY_STROBE
 *    EEC_AEROLGTTY_TAXIWAY_LIGHTING
 *    EEC_AEROLGTTY_THRESHOLD
 *    EEC_AEROLGTTY_TIDAL
 *    EEC_AEROLGTTY_TOUCHDOWN_ZONE_LIGHTING
 *    EEC_AEROLGTTY_TVASI_T_BAR
 *    EEC_AEROLGTTY_TWO_PARALLEL_ROW
 *    EEC_AEROLGTTY_US_AIR_FORCE_OVERRUN
 *    EEC_AEROLGTTY_US_NAVY_PARALLEL_ROW_AND_X
 *    EEC_AEROLGTTY_VARIABLE_INTENSITY_RUNWAY
 *    EEC_AEROLGTTY_VASI
 *    EEC_AEROLGTTY_VASI_2_BAR
 *    EEC_AEROLGTTY_VASI_3_BAR
 *    EEC_AEROLGTTY_VASI_PULSATING
 *    EEC_AEROLGTTY_VASI_WITH_INDICATOR
 *    EEC_AEROLGTTY_VERTICAL
 *    EEC_AEROLGTTY_WIND_INDICATOR
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_AERONAUTICAL_LIGHT_TYPE ((EDCS_Attribute_Code)44)

/*
 * Definition:
 *     The difference between the recorded <<HEIGHT_AGL>> of an <OBJECT>
 *     forming a <NATURAL_AIR_OBSTRUCTION> or <MAN_MADE_AIR_OBSTRUCTION> and
 *     its true <<HEIGHT_AGL>> at 90% probability; the aeronautical
 *     obstruction height accuracy.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define EAC_AERONAUTICAL_OBSTRUCTION_HEIGHT_ACCURACY ((EDCS_Attribute_Code)45)

/*
 * Definition:
 *     The function of an aeronautical point <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AEROPTFN_AERODROME_REFERENCE
 *    EEC_AEROPTFN_ARCP_CONTROL
 *    EEC_AEROPTFN_ARIP_INITIAL
 *    EEC_AEROPTFN_COMPULSORY_REPORT
 *    EEC_AEROPTFN_MISSED_APPROACH
 *    EEC_AEROPTFN_NAVIGATION_CHECK
 *    EEC_AEROPTFN_NON_COMPULSORY_REPORT
 *    EEC_AEROPTFN_VISUAL_DESCENT
 *
 * Group Membership: AIR_TRNSP
 */
#define EAC_AERONAUTICAL_POINT_FUNCTION ((EDCS_Attribute_Code)46)

/*
 * Definition:
 *     The type of an <AIR_TRANSPORTATION_ROUTE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AERORTETY_HIGH_ALTITUDE_ENROUTE
 *    EEC_AERORTETY_LOW_ALTITUDE_ENROUTE
 *    EEC_AERORTETY_LOW_HIGH_ALTITUDE_ENROUTE
 *
 * Group Membership: AIR_TRNSP
 */
#define EAC_AERONAUTICAL_ROUTE_TYPE ((EDCS_Attribute_Code)47)

/*
 * Definition:
 *     The vertical displacement of the lowest <SURFACE> of a layer of an
 *     <AEROSOL> identified by an <<ATM_VERTICAL_REFERENCE>>; the aerosol
 *     layer base level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_AEROSOL_LAYER_BASE_LEVEL ((EDCS_Attribute_Code)48)

/*
 * Definition:
 *     The vertical displacement of the highest <SURFACE> of a layer of an
 *     <AEROSOL> identified by an <<ATM_VERTICAL_REFERENCE>>; the aerosol
 *     layer top level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_AEROSOL_LAYER_TOP_LEVEL ((EDCS_Attribute_Code)49)

/*
 * Definition:
 *     The <PARTICLE> concentration of an <AEROSOL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_DENSITY
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_AEROSOL_PARTICLE_CONCENTRATION ((EDCS_Attribute_Code)50)

/*
 * Definition:
 *     The type of <PARTICLE> in an <AEROSOL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARSLPARTICTY_DUST
 *    EEC_ARSLPARTICTY_HAZE
 *    EEC_ARSLPARTICTY_MARINE
 *    EEC_ARSLPARTICTY_MIST
 *    EEC_ARSLPARTICTY_NITRATES
 *    EEC_ARSLPARTICTY_NO_AEROSOL
 *    EEC_ARSLPARTICTY_OCEAN_SPRAY
 *    EEC_ARSLPARTICTY_SALT_HAZE
 *    EEC_ARSLPARTICTY_SAND
 *    EEC_ARSLPARTICTY_SMOKE
 *    EEC_ARSLPARTICTY_SOOT
 *    EEC_ARSLPARTICTY_SULFATES
 *    EEC_ARSLPARTICTY_VOLCANIC_ASH
 *    EEC_ARSLPARTICTY_VOLCANIC_DUST
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_AEROSOL_PARTICLE_TYPE ((EDCS_Attribute_Code)51)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the production rate of visible flame that is induced by
 *     use of the afterburner of an <AIRCRAFT>; the afterburner induced
 *     flame rate. Zero means no production and one means maximum production.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_AFTERBURNER_INDUCED_FLAME_RATE ((EDCS_Attribute_Code)52)

/*
 * Definition:
 *     The colour pattern of an <OBJECT> (for example: an
 *     <AID_TO_NAVIGATION>, a <BUOY>, a <BEACON>, and/or a
 *     <NAVIGATION_LIGHT>) of importance to navigation.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AIDNAVCOLRPAT_BORDER_STRIPE
 *    EEC_AIDNAVCOLRPAT_CHECKERED
 *    EEC_AIDNAVCOLRPAT_DIAGONAL_STRIPES
 *    EEC_AIDNAVCOLRPAT_HORIZ_BANDS_TOP_TO_BOTTOM
 *    EEC_AIDNAVCOLRPAT_HORIZ_STRIPES
 *    EEC_AIDNAVCOLRPAT_SINGLE_COLOUR
 *    EEC_AIDNAVCOLRPAT_SQUARED
 *    EEC_AIDNAVCOLRPAT_STRIPES_DIRECTION_UNKNOWN
 *    EEC_AIDNAVCOLRPAT_VERTICAL_STRIPES
 *
 * Group Membership: ABSTRACT_OBJECT, COLOUR, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_COLOUR_PATTERN ((EDCS_Attribute_Code)53)

/*
 * Definition:
 *     The textual description of <AID_TO_NAVIGATION>s that are marking an
 *     <OBJECT>. EXAMPLE Marked by <BUOY>s.
 *
 * Value Type: STRING
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_DESCRIPTION ((EDCS_Attribute_Code)54)

/*
 * Definition:
 *     The radius of effectiveness of an <AID_TO_NAVIGATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, DIMENSION, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_EFFECTIVENESS_RADIUS ((EDCS_Attribute_Code)55)

/*
 * Definition:
 *     The colours of an <AID_TO_NAVIGATION> mark.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AIDNAVMKCOLR_BLACK
 *    EEC_AIDNAVMKCOLR_BLACK_RED_BLACK
 *    EEC_AIDNAVMKCOLR_BLACK_YELLOW
 *    EEC_AIDNAVMKCOLR_BLACK_YELLOW_BLACK
 *    EEC_AIDNAVMKCOLR_GREEN
 *    EEC_AIDNAVMKCOLR_GREEN_RED
 *    EEC_AIDNAVMKCOLR_GREEN_RED_GREEN
 *    EEC_AIDNAVMKCOLR_GREEN_WHITE
 *    EEC_AIDNAVMKCOLR_ORANGE
 *    EEC_AIDNAVMKCOLR_RED
 *    EEC_AIDNAVMKCOLR_RED_GREEN
 *    EEC_AIDNAVMKCOLR_RED_GREEN_RED
 *    EEC_AIDNAVMKCOLR_RED_WHITE
 *    EEC_AIDNAVMKCOLR_WHITE
 *    EEC_AIDNAVMKCOLR_YELLOW
 *    EEC_AIDNAVMKCOLR_YELLOW_BLACK
 *    EEC_AIDNAVMKCOLR_YELLOW_BLACK_YELLOW
 *    EEC_AIDNAVMKCOLR_YELLOW_RED_YELLOW
 *
 * Group Membership: COLOUR, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_MARK_COLOUR ((EDCS_Attribute_Code)56)

/*
 * Definition:
 *     The specific <SYSTEM> of marks that serve as an <AID_TO_NAVIGATION>
 *     and to which an <OBJECT> conforms.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AIDNAVMKSYS_IALA
 *    EEC_AIDNAVMKSYS_IALA_REGION_A
 *    EEC_AIDNAVMKSYS_IALA_REGION_B
 *    EEC_AIDNAVMKSYS_NO_SYSTEM_PRESENT
 *    EEC_AIDNAVMKSYS_NON_IALA
 *    EEC_AIDNAVMKSYS_SIGNI
 *    EEC_AIDNAVMKSYS_US_INTRACOASTAL
 *    EEC_AIDNAVMKSYS_US_MODIFIED
 *    EEC_AIDNAVMKSYS_US_OLD
 *    EEC_AIDNAVMKSYS_US_UNIFORM_STATE
 *    EEC_AIDNAVMKSYS_US_WESTERN_RIVER
 *
 * Group Membership: ABSTRACT_OBJECT, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_MARK_SYSTEM ((EDCS_Attribute_Code)57)

/*
 * Definition:
 *     The type of a <MARKER> serving as an <AID_TO_NAVIGATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AIDNAVMARKERTY_ELEC_BEACON
 *    EEC_AIDNAVMARKERTY_ELEC_BEACON_VIS_DAYMARK
 *    EEC_AIDNAVMARKERTY_VIS_BEACON
 *    EEC_AIDNAVMARKERTY_VIS_BEACON_VIS_DAYMARK
 *    EEC_AIDNAVMARKERTY_VIS_DAYMARK
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_MARKER_TYPE ((EDCS_Attribute_Code)58)

/*
 * Definition:
 *     The primary operating range of an <AID_TO_NAVIGATION> beyond which the
 *     capture of the signal is not completely assured.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, DIMENSION, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_PRIMARY_OPERATING_RANGE ((EDCS_Attribute_Code)59)

/*
 * Definition:
 *     The length of range established by <AID_TO_NAVIGATION>s on the <SHORE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, DIMENSION, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_RANGE ((EDCS_Attribute_Code)60)

/*
 * Definition:
 *     The secondary operating range of an <AID_TO_NAVIGATION> beyond which
 *     the capture of the signal is not completely assured.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, DIMENSION, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_SECONDARY_OPERATING_RANGE ((EDCS_Attribute_Code)61)

/*
 * Definition:
 *     The status of an <OBJECT> as an <AID_TO_NAVIGATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AIDNAVSTAT_LIT
 *    EEC_AIDNAVSTAT_MARKED
 *    EEC_AIDNAVSTAT_UNLIT
 *    EEC_AIDNAVSTAT_UNMARKED
 *
 * Group Membership: ABSTRACT_OBJECT, DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_STATUS ((EDCS_Attribute_Code)62)

/*
 * Definition:
 *     The type of a <SYSTEM> of <AID_TO_NAVIGATION>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AIDNAVSYSTY_IALA
 *    EEC_AIDNAVSYSTY_IALA_REGION_A
 *    EEC_AIDNAVSYSTY_IALA_REGION_B
 *    EEC_AIDNAVSYSTY_NON_IALA
 *    EEC_AIDNAVSYSTY_NONCONFORMING
 *    EEC_AIDNAVSYSTY_SIGNI
 *    EEC_AIDNAVSYSTY_US_INTRACOASTAL
 *    EEC_AIDNAVSYSTY_US_MODIFIED
 *    EEC_AIDNAVSYSTY_US_OLD
 *    EEC_AIDNAVSYSTY_US_UNIFORM_STATE
 *    EEC_AIDNAVSYSTY_US_WESTERN_RIVER
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_AID_TO_NAVIGATION_SYSTEM_TYPE ((EDCS_Attribute_Code)63)

/*
 * Definition:
 *     The <<MATERIAL_DENSITY>> of the <AIR>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: ATMOSPHERE, MATERIAL, RATE_OR_RATIO
 */
#define EAC_AIR_DENSITY ((EDCS_Attribute_Code)64)

/*
 * Definition:
 *     The rate at which interior <AIR> leaks out of a <STRUCTURE> expressed
 *     as the fraction of the <<VOLUME>> of <AIR> in the <STRUCTURE> per
 *     unit time; the air exfiltration rate.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RATE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO, SUPPORT_STRUCTURE
 */
#define EAC_AIR_EXFILTRATION_RATE ((EDCS_Attribute_Code)65)

/*
 * Definition:
 *     The rate at which exterior <AIR> leaks into a <STRUCTURE> expressed as
 *     the fraction of the <<VOLUME>> of <AIR> in the <STRUCTURE> per unit
 *     time; the air infiltration rate.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RATE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO, SUPPORT_STRUCTURE
 */
#define EAC_AIR_INFILTRATION_RATE ((EDCS_Attribute_Code)66)

/*
 * Definition:
 *     The <<TEMPERATURE>> of the <AIR> that would be indicated by a
 *     thermometer exposed to the <AIR> at a <LOCATION> sheltered from
 *     direct solar radiation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_AIR_TEMPERATURE ((EDCS_Attribute_Code)67)

/*
 * Definition:
 *     The error in a measurement of an <<AIR_TEMPERATURE>> that is
 *     introduced by uncertainties.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_AIR_TEMPERATURE_ERROR ((EDCS_Attribute_Code)68)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> over which the <<EXTREME_LOW_AIR_TEMPERATURE>>
 *     and/or the <<EXTREME_HIGH_AIR_TEMPERATURE>> are determined.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: ATMOSPHERE, TIME
 */
#define EAC_AIR_TEMPERATURE_PERIOD ((EDCS_Attribute_Code)69)

/*
 * Definition:
 *     The class of an <AIRCRAFT_CARRIER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARCRFCRRCLS_ASTURIAS
 *    EEC_ARCRFCRRCLS_DE_GAULLE
 *    EEC_ARCRFCRRCLS_DORIA
 *    EEC_ARCRFCRRCLS_ENTERPRISE
 *    EEC_ARCRFCRRCLS_GARIBALDI
 *    EEC_ARCRFCRRCLS_INVINCIBLE
 *    EEC_ARCRFCRRCLS_KENNEDY
 *    EEC_ARCRFCRRCLS_KITTY_HAWK
 *    EEC_ARCRFCRRCLS_KUZNETSOV
 *    EEC_ARCRFCRRCLS_NAREUBET
 *    EEC_ARCRFCRRCLS_NIMITZ
 *    EEC_ARCRFCRRCLS_SAO_PAULO
 *    EEC_ARCRFCRRCLS_VIRAAT
 *
 * Group Membership: AIR_TRNSP, HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_AIRCRAFT_CARRIER_CLASS ((EDCS_Attribute_Code)70)

/*
 * Definition:
 *     The operating function of an <AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARCRFFN_AGRICULTURE
 *    EEC_ARCRFFN_AIR_DEFENCE
 *    EEC_ARCRFFN_AMBULANCE
 *    EEC_ARCRFFN_ASW
 *    EEC_ARCRFFN_ATTACK
 *    EEC_ARCRFFN_BOMBER
 *    EEC_ARCRFFN_CARGO
 *    EEC_ARCRFFN_COMMAND_AND_CONTROL
 *    EEC_ARCRFFN_COMMERCIAL
 *    EEC_ARCRFFN_EARLY_WARNING
 *    EEC_ARCRFFN_ELECTRONIC_WARFARE
 *    EEC_ARCRFFN_EXPERIMENTAL
 *    EEC_ARCRFFN_FIGHTER
 *    EEC_ARCRFFN_OBSERVATION
 *    EEC_ARCRFFN_PASSENGER
 *    EEC_ARCRFFN_PATROL
 *    EEC_ARCRFFN_RECONNAISSANCE
 *    EEC_ARCRFFN_RESEARCH
 *    EEC_ARCRFFN_SCOUT
 *    EEC_ARCRFFN_SEARCH_AND_RESCUE
 *    EEC_ARCRFFN_SPECIAL_ELECTRONIC
 *    EEC_ARCRFFN_SPECIAL_OPERATIONS
 *    EEC_ARCRFFN_STRIKE
 *    EEC_ARCRFFN_SURVEILLANCE
 *    EEC_ARCRFFN_TANKER
 *    EEC_ARCRFFN_TARGET
 *    EEC_ARCRFFN_TRAINER
 *    EEC_ARCRFFN_TRANSPORT
 *    EEC_ARCRFFN_UTILITY
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define EAC_AIRCRAFT_FUNCTION ((EDCS_Attribute_Code)71)

/*
 * Definition:
 *     The estimated intensity of the accumulation of <ICE> on exposed
 *     <SURFACE>s of an <AIRCRAFT> that is formed as the <AIRCRAFT> is flown
 *     through supercooled drops of <WATER> in <CLOUD>s or <RAIN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARCRFICINGINT_NO_ICING
 *    EEC_ARCRFICINGINT_TRACE
 *    EEC_ARCRFICINGINT_TRACE_IN_CLOUD
 *    EEC_ARCRFICINGINT_TRACE_IN_PRECIP
 *    EEC_ARCRFICINGINT_LIGHT
 *    EEC_ARCRFICINGINT_LIGHT_IN_CLOUD
 *    EEC_ARCRFICINGINT_LIGHT_IN_PRECIP
 *    EEC_ARCRFICINGINT_MODERATE
 *    EEC_ARCRFICINGINT_MODERATE_IN_CLOUD
 *    EEC_ARCRFICINGINT_MODERATE_IN_PRECIP
 *    EEC_ARCRFICINGINT_SEVERE
 *    EEC_ARCRFICINGINT_SEVERE_IN_CLOUD
 *    EEC_ARCRFICINGINT_SEVERE_IN_PRECIP
 *
 * Group Membership: AIR_TRNSP, ICE, TRNSP, VEHICLE
 */
#define EAC_AIRCRAFT_ICING_INTENSITY ((EDCS_Attribute_Code)72)

/*
 * Definition:
 *     The estimated <<ALTITUDE_MSL>> of the lower <SURFACE> of a layer in
 *     the <ATMOSPHERE> at which an <AIRCRAFT> can be expected to experience
 *     icing.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, ICE, LOCATION, TRNSP
 */
#define EAC_AIRCRAFT_ICING_LEVEL_BASE_ALTITUDE ((EDCS_Attribute_Code)73)

/*
 * Definition:
 *     The estimated <<ALTITUDE_MSL>> of the upper <SURFACE> of a layer in
 *     the <ATMOSPHERE> at which an <AIRCRAFT> can be expected to experience
 *     icing.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, ICE, LOCATION, TRNSP
 */
#define EAC_AIRCRAFT_ICING_LEVEL_TOP_ALTITUDE ((EDCS_Attribute_Code)74)

/*
 * Definition:
 *     The type of <ICE> that is expected to accumulate on the <SURFACE> of
 *     an <AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARCRFICINGTY_CLEAR
 *    EEC_ARCRFICINGTY_FROST
 *    EEC_ARCRFICINGTY_MIXED
 *    EEC_ARCRFICINGTY_NONE_PRESENT
 *    EEC_ARCRFICINGTY_RIME
 *
 * Group Membership: AIR_TRNSP, ICE, TRNSP, VEHICLE
 */
#define EAC_AIRCRAFT_ICING_TYPE ((EDCS_Attribute_Code)75)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional deployment of the landing gear of an <AIRCRAFT>. Zero
 *     means fully retracted and one means fully deployed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_AIRCRAFT_LANDING_GEAR_DEPLOYED_POSITION ((EDCS_Attribute_Code)76)

/*
 * Definition:
 *     The description of any load restrictions that apply to <AIRCRAFT>
 *     using a <FACILITY>.
 *
 * Value Type: STRING
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define EAC_AIRCRAFT_LOAD_RESTRICTIONS ((EDCS_Attribute_Code)77)

/*
 * Definition:
 *     The type of propulsion of an <AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARCRFPRPLTY_ELECTRIC
 *    EEC_ARCRFPRPLTY_JET
 *    EEC_ARCRFPRPLTY_RECIPROCATING_ENGINE
 *    EEC_ARCRFPRPLTY_ROCKET
 *    EEC_ARCRFPRPLTY_TURBOPROP
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define EAC_AIRCRAFT_PROPULSION_TYPE ((EDCS_Attribute_Code)78)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of the lower <SURFACE> of a layer of <ATMOSPHERE>
 *     that is turbulent to <AIRCRAFT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, ATMOSPHERE, LOCATION, TRNSP
 */
#define EAC_AIRCRAFT_TURBULENCE_BASE_ALTITUDE ((EDCS_Attribute_Code)79)

/*
 * Definition:
 *     The rate of occurrence of turbulence experienced by <AIRCRAFT>;
 *     aircraft turbulence frequency.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARCRFTURBFREQ_CONTINUOUS
 *    EEC_ARCRFTURBFREQ_FREQUENT
 *    EEC_ARCRFTURBFREQ_INFREQUENT
 *    EEC_ARCRFTURBFREQ_INTERMITTENT
 *    EEC_ARCRFTURBFREQ_NONE_OCCURRING
 *    EEC_ARCRFTURBFREQ_OCCASIONAL
 *
 * Group Membership: AIR_TRNSP, ATMOSPHERE, TRNSP
 */
#define EAC_AIRCRAFT_TURBULENCE_FREQUENCY ((EDCS_Attribute_Code)80)

/*
 * Definition:
 *     The intensity of turbulence experienced by <AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARCRFTURBINT_NO_TURBULENCE
 *    EEC_ARCRFTURBINT_LIGHT
 *    EEC_ARCRFTURBINT_LIGHT_TO_MODERATE
 *    EEC_ARCRFTURBINT_MODERATE
 *    EEC_ARCRFTURBINT_MODERATE_TO_SEVERE
 *    EEC_ARCRFTURBINT_SEVERE
 *    EEC_ARCRFTURBINT_SEVERE_TO_EXTREME
 *    EEC_ARCRFTURBINT_EXTREME
 *
 * Group Membership: AIR_TRNSP, ATMOSPHERE, TRNSP
 */
#define EAC_AIRCRAFT_TURBULENCE_INTENSITY ((EDCS_Attribute_Code)81)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of the upper <SURFACE> of a layer of <ATMOSPHERE>
 *     that is turbulent to <AIRCRAFT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, ATMOSPHERE, LOCATION, TRNSP
 */
#define EAC_AIRCRAFT_TURBULENCE_TOP_ALTITUDE ((EDCS_Attribute_Code)82)

/*
 * Definition:
 *     The type of an <AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARCRFTY_AIRSHIP
 *    EEC_ARCRFTY_AMPHIBIOUS
 *    EEC_ARCRFTY_BALLOON
 *    EEC_ARCRFTY_BLIMP
 *    EEC_ARCRFTY_DIRIGIBLE
 *    EEC_ARCRFTY_DRONE
 *    EEC_ARCRFTY_FIXED_WING
 *    EEC_ARCRFTY_GLIDER
 *    EEC_ARCRFTY_LIGHT
 *    EEC_ARCRFTY_ROTARY_WING
 *    EEC_ARCRFTY_SPACEPLANE
 *    EEC_ARCRFTY_STOL
 *    EEC_ARCRFTY_UNMANNED_AUTONOMOUS
 *    EEC_ARCRFTY_VARIABLE_WING
 *    EEC_ARCRFTY_VTOL
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define EAC_AIRCRAFT_TYPE ((EDCS_Attribute_Code)83)

/*
 * Definition:
 *     The description of the altitude limits of a <SPECIAL_USE_AIRSPACE>
 *     relative to a <<ATM_VERTICAL_REFERENCE>>.
 *
 * Value Type: STRING
 *
 * Group Membership: AIR_TRNSP, DEMARCATION, TRNSP, USAGE_REGION
 */
#define EAC_AIRSPACE_ALTITUDE_LIMITS ((EDCS_Attribute_Code)84)

/*
 * Definition:
 *     The textual identifier of an <AIRSPACE>.
 *
 * Value Type: STRING
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_AIRSPACE_IDENTIFIER ((EDCS_Attribute_Code)85)

/*
 * Definition:
 *     The type of <AIRSPACE> wherein activities must be confined because of
 *     their nature and/or wherein limitations may be imposed upon
 *     <AIRCRAFT> operations.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARSPCLIMIT_AIR_EXERCISE
 *    EEC_ARSPCLIMIT_ALERT
 *    EEC_ARSPCLIMIT_ANIMAL_PROTECTION
 *    EEC_ARSPCLIMIT_BIRD_BREEDING
 *    EEC_ARSPCLIMIT_BIRD_HAZARD
 *    EEC_ARSPCLIMIT_BIRD_SANCTUARY
 *    EEC_ARSPCLIMIT_CAUTION
 *    EEC_ARSPCLIMIT_CONTROLLED_FIRING
 *    EEC_ARSPCLIMIT_DANGER
 *    EEC_ARSPCLIMIT_DEFENCE
 *    EEC_ARSPCLIMIT_GAS_VENTING_STATION
 *    EEC_ARSPCLIMIT_HAZARD_TO_AIRCRAFT
 *    EEC_ARSPCLIMIT_HELICOPTER_PROTECTION
 *    EEC_ARSPCLIMIT_HIGH_INTENSITY_RADIO
 *    EEC_ARSPCLIMIT_INDUSTRIAL_HAZARDS
 *    EEC_ARSPCLIMIT_INTENSE_AIR_ACTIVITY
 *    EEC_ARSPCLIMIT_LOW_FLY_AVOIDANCE
 *    EEC_ARSPCLIMIT_LOW_FLY_DEDICATED_USER
 *    EEC_ARSPCLIMIT_LOW_FLY_TACTICAL_TRAINING
 *    EEC_ARSPCLIMIT_MEDICAL
 *    EEC_ARSPCLIMIT_MICROLIGHT_FLYING
 *    EEC_ARSPCLIMIT_MILITARY_FLYING
 *    EEC_ARSPCLIMIT_MILITARY_OPERATIONS
 *    EEC_ARSPCLIMIT_NATURE_RESERVE
 *    EEC_ARSPCLIMIT_NON_FREE_FLYING
 *    EEC_ARSPCLIMIT_OPERATING
 *    EEC_ARSPCLIMIT_PARACHUTE_DROP_ZONE
 *    EEC_ARSPCLIMIT_PROHIBITED
 *    EEC_ARSPCLIMIT_PROHIBITED_VFR
 *    EEC_ARSPCLIMIT_PROVOST_MARSHAL
 *    EEC_ARSPCLIMIT_RESTRICTED
 *    EEC_ARSPCLIMIT_SPARSELY_SETTLED
 *    EEC_ARSPCLIMIT_TEMPORARY_RESERVED
 *    EEC_ARSPCLIMIT_TOWN_TO_BE_AVOIDED
 *    EEC_ARSPCLIMIT_WARNING
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_AIRSPACE_LIMITATION ((EDCS_Attribute_Code)86)

/*
 * Definition:
 *     The status of an <AIRSPACE> and any operating restrictions that are
 *     applicable.
 *
 * Value Type: STRING
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_AIRSPACE_OPERATING_RESTRICTIONS ((EDCS_Attribute_Code)87)

/*
 * Definition:
 *     The type of designated <AIRSPACE> within which some or all <AIRCRAFT>
 *     may be subject to air traffic control.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARSPCTY_ACC
 *    EEC_ARSPCTY_ADVISORY
 *    EEC_ARSPCTY_AERODROME_ADVISORY
 *    EEC_ARSPCTY_AERODROME_CZ
 *    EEC_ARSPCTY_AERODROME_RADAR_SERVICE
 *    EEC_ARSPCTY_AERODROME_TRAFFIC_ZONE
 *    EEC_ARSPCTY_AIR_DEFENCE_IDZ
 *    EEC_ARSPCTY_AIR_TO_AIR_REFUELLING
 *    EEC_ARSPCTY_ALTIMETER_SETTING_REGION
 *    EEC_ARSPCTY_ARTCC
 *    EEC_ARSPCTY_ARTCC_SECTOR_DISCRETE
 *    EEC_ARSPCTY_BUFFER_ZONE
 *    EEC_ARSPCTY_CADIZ
 *    EEC_ARSPCTY_CCA
 *    EEC_ARSPCTY_CONTROL_AREA
 *    EEC_ARSPCTY_CONTROL_ZONE
 *    EEC_ARSPCTY_CONTROLLED_AIRSPACE
 *    EEC_ARSPCTY_CONTROLLED_VFR
 *    EEC_ARSPCTY_DEWIZ
 *    EEC_ARSPCTY_DEWMIZ
 *    EEC_ARSPCTY_FIC_FSS
 *    EEC_ARSPCTY_FLIGHT_INR
 *    EEC_ARSPCTY_FRENCH_PERIPHERAL_IDZ
 *    EEC_ARSPCTY_KOREA_LIMITED_IDZ
 *    EEC_ARSPCTY_LFLY_AREA
 *    EEC_ARSPCTY_LFLY_DEDICATED_USER
 *    EEC_ARSPCTY_LFLY_DIVIDING_LINE
 *    EEC_ARSPCTY_LFLY_FLOW_ARROW
 *    EEC_ARSPCTY_LFLY_FLOW_CORRIDOR
 *    EEC_ARSPCTY_LFLY_SUB_BOUNDARY
 *    EEC_ARSPCTY_LFLY_TACT_ROUTE
 *    EEC_ARSPCTY_LFLY_TACT_TRAINING
 *    EEC_ARSPCTY_LFLY_WEATHER_CORRIDOR
 *    EEC_ARSPCTY_MANDATORY_RADIO_AREA
 *    EEC_ARSPCTY_MIDCANADA_IDZ
 *    EEC_ARSPCTY_MLTRY_ATZ
 *    EEC_ARSPCTY_MLTRY_CLIMB_CORRIDOR
 *    EEC_ARSPCTY_MLTRY_COMMON_AREA_CONTROL
 *    EEC_ARSPCTY_MLTRY_CTZ
 *    EEC_ARSPCTY_MLTRY_RADAR_SERVICE_AREA
 *    EEC_ARSPCTY_MLTRY_SECTOR_CONTROL_CENTRE
 *    EEC_ARSPCTY_MLTRY_UPPER
 *    EEC_ARSPCTY_MOUNTAINOUS
 *    EEC_ARSPCTY_OCA
 *    EEC_ARSPCTY_OCA_NON_FAA
 *    EEC_ARSPCTY_POSITIVE_CONTROL_AREA
 *    EEC_ARSPCTY_POSITIVE_CZ
 *    EEC_ARSPCTY_RADAR_AREA
 *    EEC_ARSPCTY_RADAR_AREA_SECTOR_BOUNDARY
 *    EEC_ARSPCTY_RADAR_SERVICE_AREA
 *    EEC_ARSPCTY_SAL_ENTRY
 *    EEC_ARSPCTY_SAL_EXIT
 *    EEC_ARSPCTY_SECURITY_IDZ
 *    EEC_ARSPCTY_SPC_RULES_AREA
 *    EEC_ARSPCTY_SPC_RULES_ZONE
 *    EEC_ARSPCTY_SUB_FLIGHT_INR
 *    EEC_ARSPCTY_TERMINAL_CONTROL
 *    EEC_ARSPCTY_TERMINAL_RADAR_SERVICE_AREA
 *    EEC_ARSPCTY_TRAFFIC_INZ
 *    EEC_ARSPCTY_TRAINING
 *    EEC_ARSPCTY_TRANSITION_AREA
 *    EEC_ARSPCTY_UNCONTROLLED_AIRSPACE
 *    EEC_ARSPCTY_UPPER_ADVISORY_AREA
 *    EEC_ARSPCTY_UPPER_AIRSPACE_CENTRES
 *    EEC_ARSPCTY_UPPER_CONTROL_AREA
 *    EEC_ARSPCTY_UPPER_FLIGHT_INR
 *    EEC_ARSPCTY_VFR_SECTOR_BOUNDARY
 *    EEC_ARSPCTY_ZONE_OF_INTERIOR
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_AIRSPACE_TYPE ((EDCS_Attribute_Code)88)

/*
 * Definition:
 *     The ratio of the reflected electromagnetic radiation to the total
 *     incident electromagnetic radiation incident upon a <SURFACE> (for
 *     example: a <PLANETARY_SURFACE>); albedo.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_ALBEDO ((EDCS_Attribute_Code)89)

/*
 * Definition:
 *     The number of <OBJECT>s of all types within a <REGION>; the all object
 *     count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_ALL_OBJECT_COUNT ((EDCS_Attribute_Code)90)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> of a <WATER_CURRENT> paralleling a
 *     <SHORE>, largely within the <SURF_ZONE>, caused by the excess <WATER>
 *     brought to the <SURF_ZONE> by the small net mass transport of
 *     <WATER_WAVE>s induced by <WIND>; alongshore <WATER_CURRENT>s feed
 *     into rip <WATER_CURRENT>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: LITTORAL, RATE_OR_RATIO
 */
#define EAC_ALONGSHORE_CURRENT_SPEED ((EDCS_Attribute_Code)91)

/*
 * Definition:
 *     The altitude relative to the MSL <SURFACE_DATUM>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_ALTITUDE_MSL ((EDCS_Attribute_Code)92)

/*
 * Definition:
 *     The angular width of an angular sector.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, DIMENSION
 */
#define EAC_ANGULAR_SECTOR_WIDTH ((EDCS_Attribute_Code)93)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of external <LIGHTING> that is used to prevent
 *     collision with/between <VEHICLE>s; the anti-collision light intensity
 *     or brake light intensity. Zero means unlit and one means maximum
 *     intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_ANTI_COLLISION_LIGHT_INTENSITY ((EDCS_Attribute_Code)94)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional <<AREA>> of an <APERTURE> that is covered by <MATERIAL>s
 *     obstructing visibility. Zero means uncovered and one means completely
 *     covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, SUPPORT_STRUCTURE
 */
#define EAC_APERTURE_COVER_FRACTION ((EDCS_Attribute_Code)95)

/*
 * Definition:
 *     The position of the covering (for example: a canopy and/or a hatch) of
 *     an <APERTURE>; the aperture cover position.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_APRCOVPOS_CLOSED
 *    EEC_APRCOVPOS_OPEN
 *    EEC_APRCOVPOS_OPEN_OCCUPANT_VISIBLE
 *    EEC_APRCOVPOS_POPPED
 *    EEC_APRCOVPOS_POPPED_OCCUPANT_VISIBLE
 *
 * Group Membership: LOCATION
 */
#define EAC_APERTURE_COVER_POSITION ((EDCS_Attribute_Code)96)

/*
 * Definition:
 *     The length of the longer of two orthogonal linear axes of an
 *     <APERTURE> measured in the plane of the <APERTURE>; the aperture
 *     length. For a square <APERTURE>, either axis may be measured. For a
 *     round <APERTURE>, the diameter is measured.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, SUPPORT_STRUCTURE
 */
#define EAC_APERTURE_LENGTH ((EDCS_Attribute_Code)97)

/*
 * Definition:
 *     An indication that an <APERTURE> is open.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_APERTURE_OPEN ((EDCS_Attribute_Code)98)

/*
 * Definition:
 *     The state of closure of an <APERTURE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_APERTURESTATE_CLOSED_LOCKED
 *    EEC_APERTURESTATE_CLOSED_UNLOCKED
 *    EEC_APERTURESTATE_FASTENED_SHUT
 *    EEC_APERTURESTATE_OPEN
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_APERTURE_STATE ((EDCS_Attribute_Code)99)

/*
 * Definition:
 *     The length of the shorter of two orthogonal linear axes of an
 *     <APERTURE> measured in the plane of the <APERTURE>; the aperture
 *     width. For a square <APERTURE>, either axis may be measured. For a
 *     round <APERTURE>, the diameter is measured.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, SUPPORT_STRUCTURE
 */
#define EAC_APERTURE_WIDTH ((EDCS_Attribute_Code)100)

/*
 * Definition:
 *     The function of an <APRON> or <HARD_STANDING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_APRNHDSTNDFN_AIRCRAFT_HANGAR_APRON
 *    EEC_APRNHDSTNDFN_ALERT
 *    EEC_APRNHDSTNDFN_BASE_FLIGHT_APRON
 *    EEC_APRNHDSTNDFN_COMPASS_ROSE_HARD_STANDING
 *    EEC_APRNHDSTNDFN_DEPOT_APRON
 *    EEC_APRNHDSTNDFN_DISPERSAL_HARD_STANDING
 *    EEC_APRNHDSTNDFN_ENGINE_RUN_UP_HARD_STANDING
 *    EEC_APRNHDSTNDFN_ENGINE_TEST_PAD
 *    EEC_APRNHDSTNDFN_FIRING_IN_HARD_STANDING
 *    EEC_APRNHDSTNDFN_MAINTENANCE_HARD_STANDING
 *    EEC_APRNHDSTNDFN_OPERATIONAL_APRON
 *    EEC_APRNHDSTNDFN_PAD_HARD_STANDING
 *    EEC_APRNHDSTNDFN_PARKING_HARD_STANDING
 *    EEC_APRNHDSTNDFN_REFUELING_HARD_STANDING
 *    EEC_APRNHDSTNDFN_STUB_APRON
 *    EEC_APRNHDSTNDFN_TRANSIENT_APRON
 *
 * Group Membership: AIR_TRNSP
 */
#define EAC_APRON_HARD_STANDING_FUNCTION ((EDCS_Attribute_Code)101)

/*
 * Definition:
 *     The type of an <AQUEDUCT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AQUETY_CANAL
 *    EEC_AQUETY_ELEVATED_FLUME
 *    EEC_AQUETY_FLUME
 *    EEC_AQUETY_IRRIGATION_DITCH
 *    EEC_AQUETY_ON_TERRAIN
 *    EEC_AQUETY_QANAT
 *    EEC_AQUETY_QANAT_SHAFT
 *    EEC_AQUETY_SLUICE
 *    EEC_AQUETY_UNDERGROUND
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_AQUEDUCT_TYPE ((EDCS_Attribute_Code)102)

/*
 * Definition:
 *     The area of the <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREA
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_AREA ((EDCS_Attribute_Code)103)

/*
 * Definition:
 *     An indication that an <OBJECT> is armoured.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, MILITARY_SCIENCE
 */
#define EAC_ARMOURED ((EDCS_Attribute_Code)104)

/*
 * Definition:
 *     The type of <DEVICE> at the end of a <RUNWAY> that is used to stop
 *     <AIRCRAFT>; the arresting gear type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ARRESTGEARTY_CABLE
 *    EEC_ARRESTGEARTY_JET_BARRIER
 *    EEC_ARRESTGEARTY_NET
 *
 * Group Membership: AIR_TRNSP, DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_ARRESTING_GEAR_TYPE ((EDCS_Attribute_Code)105)

/*
 * Definition:
 *     The angle measured from the major axis of an <OBJECT> clockwise to the
 *     viewing <DIRECTION>; the aspect angle. Zero represents either the
 *     <DIRECTION> of motion, or other unique orientation along the primary
 *     axis, heading directly towards the observer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_ASPECT_ANGLE ((EDCS_Attribute_Code)106)

/*
 * Definition:
 *     The type of a <LANDING_CRAFT> designed for amphibious assault
 *     operations.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ASLTLNDGCRFTTY_CHAHO_CLASS
 *    EEC_ASLTLNDGCRFTTY_CHONG_JIN_CLASS
 *    EEC_ASLTLNDGCRFTTY_KONGBANG_CLASS
 *    EEC_ASLTLNDGCRFTTY_LCAC_CLASS
 *    EEC_ASLTLNDGCRFTTY_MOSKALENKO_CLASS
 *    EEC_ASLTLNDGCRFTTY_OCEAN_CLASS
 *    EEC_ASLTLNDGCRFTTY_POMOMIK_CLASS
 *    EEC_ASLTLNDGCRFTTY_SIR_BEDIVERE_CLASS
 *    EEC_ASLTLNDGCRFTTY_SIR_TRISTRAM_CLASS
 *    EEC_ASLTLNDGCRFTTY_TARAWA_CLASS
 *    EEC_ASLTLNDGCRFTTY_WASP_CLASS
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_ASSAULT_LANDING_CRAFT_TYPE ((EDCS_Attribute_Code)107)

/*
 * Definition:
 *     Narrative or other textual description associated with an <OBJECT>;
 *     the associated text.
 *
 * Value Type: STRING
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_ASSOCIATED_TEXT ((EDCS_Attribute_Code)108)

/*
 * Definition:
 *     An indication that the centroid of an ASW operating <REGION> exists
 *     within the spatial extent of an associated <OBJECT>; ASW centroid
 *     present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, MILITARY_SCIENCE
 */
#define EAC_ASW_CENTROID_PRESENT ((EDCS_Attribute_Code)109)

/*
 * Definition:
 *     The type of an <ASW_WINGED_AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ASWWNGARCRFTY_B_17G
 *    EEC_ASWWNGARCRFTY_H_16
 *    EEC_ASWWNGARCRFTY_HS_2L
 *    EEC_ASWWNGARCRFTY_MARS
 *    EEC_ASWWNGARCRFTY_NIMROD
 *    EEC_ASWWNGARCRFTY_P_3
 *    EEC_ASWWNGARCRFTY_P_2
 *    EEC_ASWWNGARCRFTY_P_2Y
 *    EEC_ASWWNGARCRFTY_P_4M
 *    EEC_ASWWNGARCRFTY_P_5M
 *    EEC_ASWWNGARCRFTY_P_6M
 *    EEC_ASWWNGARCRFTY_PB_2Y_5
 *    EEC_ASWWNGARCRFTY_PB_4Y_1
 *    EEC_ASWWNGARCRFTY_PB_4Y_2
 *    EEC_ASWWNGARCRFTY_PBM
 *    EEC_ASWWNGARCRFTY_PBN_1
 *    EEC_ASWWNGARCRFTY_PBO_1
 *    EEC_ASWWNGARCRFTY_PBY
 *    EEC_ASWWNGARCRFTY_PM_1_2
 *    EEC_ASWWNGARCRFTY_PV_1
 *    EEC_ASWWNGARCRFTY_PV_2
 *    EEC_ASWWNGARCRFTY_R_4D_6
 *    EEC_ASWWNGARCRFTY_SB_2C
 *    EEC_ASWWNGARCRFTY_XP_5Y_1
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_ASW_WINGED_AIRCRAFT_TYPE ((EDCS_Attribute_Code)110)

/*
 * Definition:
 *     The <<HEIGHT_AGL>> of the lowest layer in the <ATMOSPHERE> in which
 *     meteorological conditions are affected significantly by the
 *     <PLANETARY_SURFACE> of the <EARTH>. The value is variable in time and
 *     space and ranges from tens of metres in strongly statically stable
 *     situations to several kilometres in convective conditions over
 *     <DESERT_REGION>s; the atmosphere boundary layer height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_ATM_BOUNDARY_LAYER_HEIGHT ((EDCS_Attribute_Code)111)

/*
 * Definition:
 *     Either the <<HEIGHT_AGL>> of the lowest <CLOUD> or obscuring phenomena
 *     layer aloft that covers half or more of the sky and is predominantly
 *     opaque or the vertical visibility into a surface-based obscuration;
 *     the atmosphere ceiling.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LIGHTING_AND_VISIBILITY, LOCATION
 */
#define EAC_ATM_CEILING ((EDCS_Attribute_Code)112)

/*
 * Definition:
 *     The method used to determine the <<ATM_CEILING>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATMCEILMETH_AIRCRAFT
 *    EEC_ATMCEILMETH_BALLOON
 *    EEC_ATMCEILMETH_CLOUD_OBSERVATION
 *    EEC_ATMCEILMETH_ESTIMATED
 *    EEC_ATMCEILMETH_LASER_CEILOMETER
 *    EEC_ATMCEILMETH_MEASURED
 *    EEC_ATMCEILMETH_MODELED
 *    EEC_ATMCEILMETH_OBSCURATION_LIMIT
 *    EEC_ATMCEILMETH_RADAR
 *    EEC_ATMCEILMETH_ROTATING_BEAM_CEILOMETER
 *    EEC_ATMCEILMETH_STATISTICALLY_DERIVED
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LIGHTING_AND_VISIBILITY
 */
#define EAC_ATM_CEILING_METHOD ((EDCS_Attribute_Code)113)

/*
 * Definition:
 *     The lowest <<ALTITUDE_MSL>> at which the <<AIR_TEMPERATURE>> is 273,15
 *     kelvin (zero degrees Celsius); the atmosphere freezing level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_ATM_FREEZING_LEVEL ((EDCS_Attribute_Code)114)

/*
 * Definition:
 *     The ratio of the <<MASS>> of liquid <WATER> to the <<MASS>> of dry
 *     <AIR> in a unit <<VOLUME>> of <AIR>; the atmosphere liquid water
 *     mixing ratio.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_ATM_LIQUID_WATER_MIXING_RATIO ((EDCS_Attribute_Code)115)

/*
 * Definition:
 *     The pressure exerted by an <ATMOSPHERE> on any <SURFACE> by virtue of
 *     its weight; the atmospheric pressure.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_ATM_PRESSURE ((EDCS_Attribute_Code)116)

/*
 * Definition:
 *     The quantity of change in the <<ATM_PRESSURE>> over a measurement
 *     <<TIME_QUANTITY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_CHANGE_RATE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_ATM_PRESSURE_CHANGE ((EDCS_Attribute_Code)117)

/*
 * Definition:
 *     The absolute value of the <<ATM_PRESSURE_CHANGE>> over a twenty-four
 *     hour <<TIME_QUANTITY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_ATM_PRESSURE_CHANGE_24_HOUR ((EDCS_Attribute_Code)118)

/*
 * Definition:
 *     The absolute value of the <<ATM_PRESSURE_CHANGE>> over a three-hour
 *     <<TIME_QUANTITY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_ATM_PRESSURE_CHANGE_3_HOUR ((EDCS_Attribute_Code)119)

/*
 * Definition:
 *     The quality of an <<ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY>>
 *     measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATMPRESCHGQUAL_GOOD
 *    EEC_ATMPRESCHGQUAL_NO_CHECK
 *    EEC_ATMPRESCHGQUAL_SUSPECT
 *    EEC_ATMPRESCHGQUAL_ERR_CORRECTED
 *    EEC_ATMPRESCHGQUAL_ERR_CORRECTION_SUSPECT
 *    EEC_ATMPRESCHGQUAL_ERR
 *    EEC_ATMPRESCHGQUAL_MISS_SUBST
 *    EEC_ATMPRESCHGQUAL_MISS_SUBST_SUSPECT
 *    EEC_ATMPRESCHGQUAL_MISS
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_ATM_PRESSURE_CHANGE_QUALITY ((EDCS_Attribute_Code)120)

/*
 * Definition:
 *     The qualitative <<ATM_PRESSURE_CHANGE_3_HOUR>>; the atmospheric
 *     pressure change tendency category.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATMPRESCHGTEND_INC_THEN_DEC
 *    EEC_ATMPRESCHGTEND_INC_THEN_STEADY
 *    EEC_ATMPRESCHGTEND_INC_PRESSURE_HIGHER
 *    EEC_ATMPRESCHGTEND_CHANGE_TO_INC
 *    EEC_ATMPRESCHGTEND_STEADY_PRESSURE_EQUAL
 *    EEC_ATMPRESCHGTEND_DEC_THEN_INC
 *    EEC_ATMPRESCHGTEND_DEC_THEN_STEADY
 *    EEC_ATMPRESCHGTEND_DEC_PRESSURE_LESS
 *    EEC_ATMPRESCHGTEND_CHANGE_TO_DEC
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY ((EDCS_Attribute_Code)121)

/*
 * Definition:
 *     The mean of historical (climatology) <<ATM_PRESSURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_ATM_PRESSURE_MEAN_CLIM ((EDCS_Attribute_Code)122)

/*
 * Definition:
 *     The standard deviation of historical (climatology) <<ATM_PRESSURE>>
 *     measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_ATM_PRESSURE_MEAN_CLIM_STD_DEV ((EDCS_Attribute_Code)123)

/*
 * Definition:
 *     The quality of an <<ATM_PRESSURE>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATMPRESQUAL_GOOD
 *    EEC_ATMPRESQUAL_NO_CHECK
 *    EEC_ATMPRESQUAL_SUSPECT
 *    EEC_ATMPRESQUAL_ERR_CORRECTED
 *    EEC_ATMPRESQUAL_ERR_CORRECTION_SUSPECT
 *    EEC_ATMPRESQUAL_ERR
 *    EEC_ATMPRESQUAL_MISS_SUBST
 *    EEC_ATMPRESQUAL_MISS_SUBST_SUSPECT
 *    EEC_ATMPRESQUAL_MISS
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_ATM_PRESSURE_QUALITY ((EDCS_Attribute_Code)124)

/*
 * Definition:
 *     The standard deviation of historical (climatology)
 *     <<ATM_PRESSURE_REDUCED_MSL>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_ATM_PRESSURE_REDUCED_CLIM_STD_DEV ((EDCS_Attribute_Code)125)

/*
 * Definition:
 *     The <<ATM_PRESSURE>> reduced to MSL using standard procedures.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_ATM_PRESSURE_REDUCED_MSL ((EDCS_Attribute_Code)126)

/*
 * Definition:
 *     The technique or method of collecting an <ATMOSPHERE_PROPERTY_SET>
 *     that is a series of measurements collected along a (roughly) vertical
 *     axis; the atmospheric profile measurement technique.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATMPROFLMEAS_AIRCRAFT
 *    EEC_ATMPROFLMEAS_DROPSONDE
 *    EEC_ATMPROFLMEAS_PILOT_BALLOON
 *    EEC_ATMPROFLMEAS_RADIOSONDE
 *    EEC_ATMPROFLMEAS_ROCKETSONDE
 *    EEC_ATMPROFLMEAS_SATELLITE
 *    EEC_ATMPROFLMEAS_WIND_PROFILER
 *
 * Group Membership: ALGORITHM_RELATED, ATMOSPHERE
 */
#define EAC_ATM_PROFILE_MEASUREMENT_TECHNIQUE ((EDCS_Attribute_Code)127)

/*
 * Definition:
 *     The type of turbulence in the <ATMOSPHERE> experienced by <AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATMTURBTY_CLEAR_AIR
 *    EEC_ATMTURBTY_CLOUD
 *    EEC_ATMTURBTY_NO_TURBULENCE
 *    EEC_ATMTURBTY_NOT_SPECIFIED
 *
 * Group Membership: AIR_TRNSP, ATMOSPHERE, TRNSP
 */
#define EAC_ATM_TURBULENCE_TYPE ((EDCS_Attribute_Code)128)

/*
 * Definition:
 *     The <SURFACE_DATUM> and accompanying method of reporting the vertical
 *     displacement to an <OBJECT> (for example: a level in an <ATMOSPHERE>)
 *     in an <ATMOSPHERE>; the atmosphere vertical reference.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATMVERTREFR_ICAO_STD_ATM
 *    EEC_ATMVERTREFR_ICAO_STD_ATM_FLIGHT_LEVEL
 *    EEC_ATMVERTREFR_PLANETARY_SURFACE
 *    EEC_ATMVERTREFR_STATION_ALTIMETER_SETTING
 *    EEC_ATMVERTREFR_TRUE_ALTITUDE
 *
 * Group Membership: ABSTRACT_OBJECT, ATMOSPHERE, SURVEY
 */
#define EAC_ATM_VERTICAL_REFERENCE ((EDCS_Attribute_Code)129)

/*
 * Definition:
 *     The <<LENGTH>> of an <ATS_ROUTE_COMPONENT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, DIMENSION, TRNSP
 */
#define EAC_ATS_ROUTE_COMPONENT_LENGTH ((EDCS_Attribute_Code)130)

/*
 * Definition:
 *     The flight level of an <ATS_ROUTE_COMPONENT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATSRTECMPTLEV_ABOVE_195
 *    EEC_ATSRTECMPTLEV_BELOW_195
 *    EEC_ATSRTECMPTLEV_BOTH_195
 *    EEC_ATSRTECMPTLEV_ABOVE_245
 *    EEC_ATSRTECMPTLEV_BELOW_245
 *    EEC_ATSRTECMPTLEV_BOTH_245
 *    EEC_ATSRTECMPTLEV_NIGHT_LOW_FLYING
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_ATS_ROUTE_COMPONENT_LEVEL ((EDCS_Attribute_Code)131)

/*
 * Definition:
 *     The <<WIDTH>> of an <ATS_ROUTE_COMPONENT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, DIMENSION, TRNSP
 */
#define EAC_ATS_ROUTE_COMPONENT_WIDTH ((EDCS_Attribute_Code)132)

/*
 * Definition:
 *     The lowest published altitude in effect along a <ATS_ROUTE_COMPONENT>
 *     that meets obstacle clearance requirements for the entire
 *     <ATS_ROUTE_COMPONENT> and that assures an acceptable navigation
 *     signal.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, COMMUNICATION, LOCATION, TRNSP
 */
#define EAC_ATS_ROUTE_LOWEST_ALTITUDE ((EDCS_Attribute_Code)133)

/*
 * Definition:
 *     The <DIRECTION> opposite to the flow of an <ATS_ROUTE_COMPONENT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: AIR_TRNSP, ANGULAR_MEASURE, TRNSP
 */
#define EAC_ATS_ROUTE_OPPOSITE_FLOW_DIRECTION ((EDCS_Attribute_Code)134)

/*
 * Definition:
 *     The type of an <ATS_ROUTE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATSRTETY_ADVISORY
 *    EEC_ATSRTETY_AIR_ROUTE
 *    EEC_ATSRTETY_AIRWAY
 *    EEC_ATSRTETY_AREA_NAVIGATION
 *    EEC_ATSRTETY_ATLANTIC
 *    EEC_ATSRTETY_BAHAMAS
 *    EEC_ATSRTETY_CANADIAN_CONTROL
 *    EEC_ATSRTETY_CORRIDOR
 *    EEC_ATSRTETY_DIRECT
 *    EEC_ATSRTETY_HELICOPTER
 *    EEC_ATSRTETY_HELICOPTER_MULTI_ENGINE
 *    EEC_ATSRTETY_JET
 *    EEC_ATSRTETY_LOW_FLYING
 *    EEC_ATSRTETY_MILITARY
 *    EEC_ATSRTETY_NORTH_AMERICA
 *    EEC_ATSRTETY_OCEANIC
 *    EEC_ATSRTETY_PURPLE_AIRWAY
 *    EEC_ATSRTETY_ROYAL_HELICOPTER
 *    EEC_ATSRTETY_ROYAL_LOW_LEVEL
 *    EEC_ATSRTETY_SUBSTITUTE
 *    EEC_ATSRTETY_TACAN
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_ATS_ROUTE_TYPE ((EDCS_Attribute_Code)135)

/*
 * Definition:
 *     The type of use of a designated ATS <AIRSPACE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATSUSETY_AERODROME_CZ
 *    EEC_ATSUSETY_AIR_DEFENCE_ADVISORY
 *    EEC_ATSUSETY_AIR_DEFENCE_IDZ
 *    EEC_ATSUSETY_AIRPORT_ADVISORY
 *    EEC_ATSUSETY_AIRPORT_RADAR_SERVICE
 *    EEC_ATSUSETY_AIRPORT_TRAFFIC
 *    EEC_ATSUSETY_ALTIMETER_CHANGE_BOUNDARY
 *    EEC_ATSUSETY_AREA_CONTROL
 *    EEC_ATSUSETY_ARTCC
 *    EEC_ATSUSETY_ARTCC_SECTOR
 *    EEC_ATSUSETY_BERLIN_CZ
 *    EEC_ATSUSETY_BUFFER_ZONE
 *    EEC_ATSUSETY_CANADIAN_AIR_DEFENCE_IDZ
 *    EEC_ATSUSETY_CLASS_C_CZ
 *    EEC_ATSUSETY_CONTINENTAL_CONTROL
 *    EEC_ATSUSETY_CONTROL_REGION
 *    EEC_ATSUSETY_CONTROL_VFR
 *    EEC_ATSUSETY_CONTROLLED_AIRSPACE
 *    EEC_ATSUSETY_CZ
 *    EEC_ATSUSETY_CZ_NO_FIXED_WING
 *    EEC_ATSUSETY_DEW_EAST_MLTRY_IDZ
 *    EEC_ATSUSETY_DEW_IDZ
 *    EEC_ATSUSETY_FLIGHT_INR
 *    EEC_ATSUSETY_FRENCH_PERIPHERAL_IDZ
 *    EEC_ATSUSETY_ICAO
 *    EEC_ATSUSETY_KOREA_LIMITED_IDZ
 *    EEC_ATSUSETY_LOW_FLYING
 *    EEC_ATSUSETY_MIDCANADA_IDZ
 *    EEC_ATSUSETY_MLTRY_AERODROME_TZ
 *    EEC_ATSUSETY_MLTRY_CLIMB_CORRIDOR
 *    EEC_ATSUSETY_MLTRY_COMMON_REGION_CONTROL
 *    EEC_ATSUSETY_MLTRY_TERMINAL_CZ
 *    EEC_ATSUSETY_MLTRY_UPPER_CZ
 *    EEC_ATSUSETY_MOUNTAINOUS
 *    EEC_ATSUSETY_OCA_FAA
 *    EEC_ATSUSETY_OCA_NON_FAA
 *    EEC_ATSUSETY_POSITIVE_CONTROL_REGION
 *    EEC_ATSUSETY_POSITIVE_CZ
 *    EEC_ATSUSETY_RADAR_REGION
 *    EEC_ATSUSETY_RADAR_SECTOR
 *    EEC_ATSUSETY_REFUELING
 *    EEC_ATSUSETY_REFUELING_OR_TRACK
 *    EEC_ATSUSETY_SECURITY_IDZ
 *    EEC_ATSUSETY_SPECIAL_AIR_TRAFFIC_RULES
 *    EEC_ATSUSETY_SPECIAL_OPERATIONS
 *    EEC_ATSUSETY_SPECIAL_RULES_ZONE
 *    EEC_ATSUSETY_SPECIAL_USE_AIRSPACE
 *    EEC_ATSUSETY_SUB_FLIGHT_INR
 *    EEC_ATSUSETY_TERMINAL_CONTROL
 *    EEC_ATSUSETY_TERMINAL_RADAR_SERVICE
 *    EEC_ATSUSETY_TRACK
 *    EEC_ATSUSETY_TRAFFIC_INZ
 *    EEC_ATSUSETY_TRANSITION
 *    EEC_ATSUSETY_UNCONTROLLED
 *    EEC_ATSUSETY_UPPER_ADVISORY_REGION
 *    EEC_ATSUSETY_UPPER_AIRSPACE_CENTRE
 *    EEC_ATSUSETY_UPPER_CONTROL_REGION
 *    EEC_ATSUSETY_UPPER_FLIGHT_INR
 *    EEC_ATSUSETY_ZONE_OF_INTERIOR
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_ATS_USE_TYPE ((EDCS_Attribute_Code)136)

/*
 * Definition:
 *     An indication that an <OBJECT> is attached to another <OBJECT>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_ATTACHED ((EDCS_Attribute_Code)137)

/*
 * Definition:
 *     The type of an <ATTACK_WINGED_AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ATKWNGARCRFTY_A_1
 *    EEC_ATKWNGARCRFTY_A_2
 *    EEC_ATKWNGARCRFTY_A_3
 *    EEC_ATKWNGARCRFTY_A_4
 *    EEC_ATKWNGARCRFTY_A_5
 *    EEC_ATKWNGARCRFTY_A_6
 *    EEC_ATKWNGARCRFTY_A_7
 *    EEC_ATKWNGARCRFTY_A_9
 *    EEC_ATKWNGARCRFTY_A_10
 *    EEC_ATKWNGARCRFTY_A_12
 *    EEC_ATKWNGARCRFTY_A_26
 *    EEC_ATKWNGARCRFTY_A_37
 *    EEC_ATKWNGARCRFTY_AC_47
 *    EEC_ATKWNGARCRFTY_AC_119
 *    EEC_ATKWNGARCRFTY_AC_130
 *    EEC_ATKWNGARCRFTY_AU_23
 *    EEC_ATKWNGARCRFTY_AU_24
 *    EEC_ATKWNGARCRFTY_AV_8
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_ATTACK_WINGED_AIRCRAFT_TYPE ((EDCS_Attribute_Code)138)

/*
 * Definition:
 *     The type of a <WATER_SURFACE_VESSEL> designed for auxiliary operations.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AUXVESTY_APPLELEAF_CLASS_TANKER
 *    EEC_AUXVESTY_BULLDOG_CLASS_SURVEY
 *    EEC_AUXVESTY_FORT_GRANGE_CLASS_COMBAT_SUPPORT
 *    EEC_AUXVESTY_FORT_VICTORIA_CLASS_CARGO
 *    EEC_AUXVESTY_HECLA_CLASS_SURVEY
 *    EEC_AUXVESTY_MOORHEN_CLASS_SALVAGE
 *    EEC_AUXVESTY_ROEBUCK_CLASS_SURVEY
 *    EEC_AUXVESTY_ROVER_CLASS_OILER
 *    EEC_AUXVESTY_SAL_CLASS_MOORING
 *    EEC_AUXVESTY_STENA_CLASS_REPAIR
 *    EEC_AUXVESTY_TORNADO_CLASS_TORPEDO_RECOVERY
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_AUXILIARY_VESSEL_TYPE ((EDCS_Attribute_Code)139)

/*
 * Definition:
 *     The type of <FACILITY>s available at, or in the near vicinity of, a
 *     <HARBOUR> or marina.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AVAILFACTY_BOAT_LIFT
 *    EEC_AVAILFACTY_BOAT_RAMP
 *    EEC_AVAILFACTY_BOTTLE_GAS
 *    EEC_AVAILFACTY_CAMPGROUND
 *    EEC_AVAILFACTY_CHANDLER
 *    EEC_AVAILFACTY_DESALINATION
 *    EEC_AVAILFACTY_ELECTRICITY
 *    EEC_AVAILFACTY_EMERGENCY_TELEPHONE
 *    EEC_AVAILFACTY_FRESH_WATER
 *    EEC_AVAILFACTY_FUEL_STATION
 *    EEC_AVAILFACTY_HEALTH_OFFICE
 *    EEC_AVAILFACTY_HELIPAD
 *    EEC_AVAILFACTY_HOTEL
 *    EEC_AVAILFACTY_LAUNDERETTE
 *    EEC_AVAILFACTY_MARINE_POLICE_STATION
 *    EEC_AVAILFACTY_NAUTICAL_CLUB
 *    EEC_AVAILFACTY_NONE_AVAILABLE
 *    EEC_AVAILFACTY_PARKING_FOR_BOATS
 *    EEC_AVAILFACTY_PHARMACY
 *    EEC_AVAILFACTY_PICNIC_TRACT
 *    EEC_AVAILFACTY_POSTBOX
 *    EEC_AVAILFACTY_PROVISIONS
 *    EEC_AVAILFACTY_PUBLIC_INN
 *    EEC_AVAILFACTY_PUBLIC_TELEPHONE
 *    EEC_AVAILFACTY_PUBLIC_TOILET
 *    EEC_AVAILFACTY_RECREATIONAL_VEHICLE_PARK
 *    EEC_AVAILFACTY_REFUSE_BIN
 *    EEC_AVAILFACTY_REPAIR_BUILDING
 *    EEC_AVAILFACTY_RESTAURANT
 *    EEC_AVAILFACTY_SAILMAKER
 *    EEC_AVAILFACTY_SCRUBBING_BERTH
 *    EEC_AVAILFACTY_SECURITY
 *    EEC_AVAILFACTY_SEWAGE_PUMP_OUT
 *    EEC_AVAILFACTY_SHIPYARD
 *    EEC_AVAILFACTY_SHOWER
 *    EEC_AVAILFACTY_TICKET_SALE
 *    EEC_AVAILFACTY_VEHICLE_LOT
 *    EEC_AVAILFACTY_VISITORS_BERTH
 *    EEC_AVAILFACTY_VISITORS_MOORING
 *
 * Group Membership: USAGE_REGION
 */
#define EAC_AVAILABLE_FACILITIES_TYPE ((EDCS_Attribute_Code)140)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> over which a measurement has been averaged; the
 *     averaging period.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME
 */
#define EAC_AVERAGING_PERIOD ((EDCS_Attribute_Code)141)

/*
 * Definition:
 *     A category describing the <<AVERAGING_PERIOD>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AVERPERCAT_ONE_SECOND
 *    EEC_AVERPERCAT_TWO_SECONDS
 *    EEC_AVERPERCAT_FIVE_SECONDS
 *    EEC_AVERPERCAT_TEN_SECONDS
 *    EEC_AVERPERCAT_FIFTEEN_SECONDS
 *    EEC_AVERPERCAT_THIRTY_SECONDS
 *    EEC_AVERPERCAT_ONE_MINUTE
 *    EEC_AVERPERCAT_TWO_MINUTES
 *    EEC_AVERPERCAT_FIVE_MINUTES
 *    EEC_AVERPERCAT_TEN_MINUTES
 *    EEC_AVERPERCAT_FIFTEEN_MINUTES
 *    EEC_AVERPERCAT_THIRTY_MINUTES
 *    EEC_AVERPERCAT_ONE_HOUR
 *    EEC_AVERPERCAT_TWO_HOURS
 *    EEC_AVERPERCAT_THREE_HOURS
 *    EEC_AVERPERCAT_FOUR_HOURS
 *    EEC_AVERPERCAT_SIX_HOURS
 *    EEC_AVERPERCAT_EIGHT_HOURS
 *    EEC_AVERPERCAT_TWELVE_HOURS
 *    EEC_AVERPERCAT_TWENTY_FOUR_HOURS
 *
 * Group Membership: TIME
 */
#define EAC_AVERAGING_PERIOD_CATEGORY ((EDCS_Attribute_Code)142)

/*
 * Definition:
 *     The value set of a formatted <<AVIATION_LOCATION_IDENTIFIER>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_AVTLOCIDVALSET_UNCONSTRAINED
 *    EEC_AVTLOCIDVALSET_ICAO
 *    EEC_AVTLOCIDVALSET_US_FAA
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_AVIATION_LOCATION_ID_VALUE_SET ((EDCS_Attribute_Code)143)

/*
 * Definition:
 *     An identifier of an aviation <LOCATION>. The format and values of the
 *     identifier are specified by an <<AVIATION_LOCATION_ID_VALUE_SET>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_AVIATION_LOCATION_IDENTIFIER ((EDCS_Attribute_Code)144)

/*
 * Definition:
 *     The type, <LOCATION>, or purpose of a <BALCONY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BALCONYTY_CHOIR_LOFT
 *    EEC_BALCONYTY_EXTERIOR
 *    EEC_BALCONYTY_INTERIOR
 *    EEC_BALCONYTY_NONE
 *
 * Group Membership: BUILDING_COMPONENT, LOCATION
 */
#define EAC_BALCONY_TYPE ((EDCS_Attribute_Code)145)

/*
 * Definition:
 *     The number of baleen <WHALE>s caught within a one-year
 *     <<TIME_QUANTITY>>.
 *
 * Value Type: COUNT
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define EAC_BALEEN_WHALE_CATCH_PER_YEAR ((EDCS_Attribute_Code)146)

/*
 * Definition:
 *     The description of any load restrictions that apply to barges using a
 *     <MARINE_ROUTE> or marine <FACILITY>.
 *
 * Value Type: STRING
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_BARGE_LOAD_RESTRICTIONS ((EDCS_Attribute_Code)147)

/*
 * Definition:
 *     The <MATERIAL> used to construct a <BASEMENT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BSMTCNSTCTTY_MASONRY
 *    EEC_BSMTCNSTCTTY_POURED_CONCRETE
 *    EEC_BSMTCNSTCTTY_PRECAST_PANEL
 *    EEC_BSMTCNSTCTTY_SOIL
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_BASEMENT_CONSTRUCTION_MATERIAL ((EDCS_Attribute_Code)148)

/*
 * Definition:
 *     The relative portion of a <BEACH>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BEACHPORTN_BACKSHORE
 *    EEC_BEACHPORTN_FORESHORE
 *    EEC_BEACHPORTN_NEARSHORE
 *
 * Group Membership: LITTORAL
 */
#define EAC_BEACH_PORTION ((EDCS_Attribute_Code)149)

/*
 * Definition:
 *     An indication that an <OBJECT> has an associated <BEACON>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_BEACON_PRESENT ((EDCS_Attribute_Code)150)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the first limit of a sector of a <BEACON>
 *     or radio transponder <BEACON>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, DEMARCATION, DEVICE_AND_EQUIPMENT, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_BEACON_SECTOR_FIRST_LIMIT ((EDCS_Attribute_Code)151)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the second limit of a sector of a <LIGHT>
 *     or radio transponder <BEACON>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, DEMARCATION, DEVICE_AND_EQUIPMENT, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_BEACON_SECTOR_SECOND_LIMIT ((EDCS_Attribute_Code)152)

/*
 * Definition:
 *     The horizontal <DIRECTION> (for example: along a track and/or along a
 *     <ROUTE>) of one terrestrial <LOCATION> from another. Formatted in a
 *     Basic Latin string as the angular distance in arc degrees from a
 *     reference <DIRECTION> in 0,1 arc degree increments, followed by a
 *     hyphen, and the followed by the reciprocal bearing. EXAMPLE
 *     "053,1-233,1".
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ANGULAR_MEASURE, LOCATION
 */
#define EAC_BEARING_AND_RECIPROCAL ((EDCS_Attribute_Code)153)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the true course of a <VESSEL> when
 *     proceeding from seaward.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define EAC_BEARING_FROM_SEAWARD ((EDCS_Attribute_Code)154)

/*
 * Definition:
 *     The force of a <WIND> on the Beaufort scale (originally based on the
 *     associated state of a <WATERBODY_SURFACE>).
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BEAUFORTWNDSCL_CALM
 *    EEC_BEAUFORTWNDSCL_LIGHT_AIR
 *    EEC_BEAUFORTWNDSCL_LIGHT_BREEZE
 *    EEC_BEAUFORTWNDSCL_GENTLE_BREEZE
 *    EEC_BEAUFORTWNDSCL_MODERATE_BREEZE
 *    EEC_BEAUFORTWNDSCL_FRESH_BREEZE
 *    EEC_BEAUFORTWNDSCL_STRONG_BREEZE
 *    EEC_BEAUFORTWNDSCL_NEAR_GALE
 *    EEC_BEAUFORTWNDSCL_GALE
 *    EEC_BEAUFORTWNDSCL_STRONG_GALE
 *    EEC_BEAUFORTWNDSCL_STORM
 *    EEC_BEAUFORTWNDSCL_VIOLENT_STORM
 *    EEC_BEAUFORTWNDSCL_HURRICANE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_BEAUFORT_WIND_SCALE ((EDCS_Attribute_Code)155)

/*
 * Definition:
 *     The <<VELOCITY>> of displacement of <BEDROCK> in the same <DIRECTION>
 *     as a compressional (density) wave in the top ten metres of that
 *     <BEDROCK>; the bedrock surface compressional velocity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_BEDROCK_SURFACE_COMPRESSIONAL_VELOCITY ((EDCS_Attribute_Code)156)

/*
 * Definition:
 *     The mean density of the top ten metres of <BEDROCK>; the bedrock
 *     surface density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_BEDROCK_SURFACE_DENSITY ((EDCS_Attribute_Code)157)

/*
 * Definition:
 *     The <<VELOCITY>> of displacement of <BEDROCK> in a <DIRECTION> that is
 *     perpendicular to a compressional (density) wave in the top ten metres
 *     of that <BEDROCK>; the bedrock surface shear velocity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_BEDROCK_SURFACE_SHEAR_VELOCITY ((EDCS_Attribute_Code)158)

/*
 * Definition:
 *     Cloud coverage of the sky below an <OBSERVATION_STATION> located in
 *     the <MOUNTAIN>s on <EARTH>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BLWSTACLDCOV_NONE_PRESENT
 *    EEC_BLWSTACLDCOV_ONE_OKTA
 *    EEC_BLWSTACLDCOV_TWO_OKTA
 *    EEC_BLWSTACLDCOV_THREE_OKTA
 *    EEC_BLWSTACLDCOV_FOUR_OKTA
 *    EEC_BLWSTACLDCOV_FIVE_OKTA
 *    EEC_BLWSTACLDCOV_SIX_OKTA
 *    EEC_BLWSTACLDCOV_SEVEN_OKTA
 *    EEC_BLWSTACLDCOV_EIGHT_OKTA
 *    EEC_BLWSTACLDCOV_SKY_OBSCURED
 *    EEC_BLWSTACLDCOV_PARTIAL_OBSCURATION
 *    EEC_BLWSTACLDCOV_SCATTERED
 *    EEC_BLWSTACLDCOV_BROKEN
 *    EEC_BLWSTACLDCOV_FEW
 *    EEC_BLWSTACLDCOV_INDISCERNABLE
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_BELOW_STATION_CLOUD_COVERAGE ((EDCS_Attribute_Code)159)

/*
 * Definition:
 *     The highest <SURFACE> of a <CLOUD_TOP> or a <CLOUD_LAYER> relative to
 *     an <<ATM_VERTICAL_REFERENCE>> below an <OBSERVATION_STATION> located
 *     in the <MOUNTAIN>s on <EARTH>; the below station cloud top altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_BELOW_STATION_CLOUD_TOP_ALTITUDE ((EDCS_Attribute_Code)160)

/*
 * Definition:
 *     The characteristics of the <CLOUD_TOP> or a <CLOUD_LAYER> below an
 *     <OBSERVATION_STATION> located in the <MOUNTAIN>s on <EARTH>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BLWSTACLDTPCHR_FRAGMENTED
 *    EEC_BLWSTACLDTPCHR_CONT_FLAT_TOPS
 *    EEC_BLWSTACLDTPCHR_SML_BREAKS_FLAT_TOPS
 *    EEC_BLWSTACLDTPCHR_LRG_BREAKS_FLAT_TOPS
 *    EEC_BLWSTACLDTPCHR_CONT_UNDULATING_TOPS
 *    EEC_BLWSTACLDTPCHR_LRG_BREAKS_UNDULATING_TOPS
 *    EEC_BLWSTACLDTPCHR_SML_BREAKS_UNDULATING_TOPS
 *    EEC_BLWSTACLDTPCHR_CONT_TOWERING_TOPS
 *    EEC_BLWSTACLDTPCHR_WAVE_GROUPS_WITH_TOWERING
 *    EEC_BLWSTACLDTPCHR_MULTIPLE_LAYERS_AND_LEVELS
 *    EEC_BLWSTACLDTPCHR_CLOUD_NOT_VISIBLE
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_BELOW_STATION_CLOUD_TOP_CHARACTERISTICS ((EDCS_Attribute_Code)161)

/*
 * Definition:
 *     The type of <CLOUD>s that comprise a <CLOUD_LAYER> below an
 *     <OBSERVATION_STATION> located in the <MOUNTAIN>s on <EARTH>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BLWSTACLDTY_CIRRUS
 *    EEC_BLWSTACLDTY_CIRROCUMULUS
 *    EEC_BLWSTACLDTY_CIRROSTRATUS
 *    EEC_BLWSTACLDTY_ALTOCUMULUS
 *    EEC_BLWSTACLDTY_ALTOSTRATUS
 *    EEC_BLWSTACLDTY_NIMBOSTRATUS
 *    EEC_BLWSTACLDTY_STRATOCUMULUS
 *    EEC_BLWSTACLDTY_STRATUS
 *    EEC_BLWSTACLDTY_CUMULUS
 *    EEC_BLWSTACLDTY_CUMULONIMBUS
 *    EEC_BLWSTACLDTY_NOT_VISIBLE
 *    EEC_BLWSTACLDTY_NO_CLOUDS
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_BELOW_STATION_CLOUD_TYPE ((EDCS_Attribute_Code)162)

/*
 * Definition:
 *     The type of a <BENCHMARK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BNCHMKTY_PRIMARY_ACS
 *    EEC_BNCHMKTY_SECONDARY_ACS
 *
 * Group Membership: SURVEY
 */
#define EAC_BENCHMARK_TYPE ((EDCS_Attribute_Code)163)

/*
 * Definition:
 *     The textual identifier of a <VESSEL_BERTH>.
 *
 * Value Type: STRING
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_BERTH_IDENTIFIER ((EDCS_Attribute_Code)164)

/*
 * Definition:
 *     The type of decked marine <STRUCTURE> at a <VESSEL_BERTH>. The type is
 *     based on configuration and structure.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BERTHTY_PIER
 *    EEC_BERTHTY_QUAY
 *    EEC_BERTHTY_WHARF
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_BERTH_TYPE ((EDCS_Attribute_Code)165)

/*
 * Definition:
 *     An indication that an <OBJECT> supports bidirectional flow.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_BIDIRECTIONAL ((EDCS_Attribute_Code)166)

/*
 * Definition:
 *     The ratio, for a particular material <SURFACE>, of the differential
 *     reflected <<RADIANCE>> into a unit solid angle about a particular
 *     (reflected) <DIRECTION> to the differential incident flux per unit
 *     surface <<AREA>> (irradiance) from a particular (incident)
 *     <DIRECTION>; bi-directional reflectance distribution function or
 *     directional-directional reflectance. This quantity is a function of
 *     the <<INCIDENCE_ZENITH_ANGLE_LOCAL>>, <<INCIDENCE_AZIMUTH_LOCAL>>,
 *     <<REFLECTANCE_ZENITH_ANGLE_LOCAL>>, and
 *     <<REFLECTANCE_AZIMUTH_LOCAL>>. This quantity is spectral (a
 *     distribution function in <<WAVELENGTH>>) and is measured in terms of
 *     inverse solid angle and inverse <<WAVELENGTH>> bin size.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPECTRAL_RECIPROCAL_SOLID_ANGLE
 *
 * Group Membership: ALGORITHM_RELATED, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SURFACE
 */
#define EAC_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION ((EDCS_Attribute_Code)167)

/*
 * Definition:
 *     The concentration of a biologic agent suspended in an <ATMOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: ATMOSPHERE, LIVING_ORGANISM, RATE_OR_RATIO
 */
#define EAC_BIOLOGIC_AGENT_ATM_CONCENTRATION ((EDCS_Attribute_Code)168)

/*
 * Definition:
 *     The concentration of a biologic agent contained in a layer on the
 *     <SURFACE> of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: LIVING_ORGANISM, RATE_OR_RATIO, SURFACE
 */
#define EAC_BIOLOGIC_AGENT_SURFACE_CONCENTRATION ((EDCS_Attribute_Code)169)

/*
 * Definition:
 *     The type of a biologic agent that can kill, seriously injure, or
 *     incapacitate <HUMAN>s or <NON_HUMAN_ANIMAL>s through its
 *     physiological properties.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BIOAGENTTY_ABRIN
 *    EEC_BIOAGENTTY_ACONITINE
 *    EEC_BIOAGENTTY_AFLA
 *    EEC_BIOAGENTTY_AFLATOXIN
 *    EEC_BIOAGENTTY_ALPHA_BUNGARO
 *    EEC_BIOAGENTTY_ALPHA_BUNGAROTOXIN
 *    EEC_BIOAGENTTY_ANA
 *    EEC_BIOAGENTTY_ANATOXIN_A
 *    EEC_BIOAGENTTY_ANTHRAX
 *    EEC_BIOAGENTTY_B1A
 *    EEC_BIOAGENTTY_B2A
 *    EEC_BIOAGENTTY_B3A
 *    EEC_BIOAGENTTY_B3B
 *    EEC_BIOAGENTTY_B4
 *    EEC_BIOAGENTTY_B5
 *    EEC_BIOAGENTTY_BATRACHO
 *    EEC_BIOAGENTTY_BATRACHOTOXIN
 *    EEC_BIOAGENTTY_BETA_BUNGARO
 *    EEC_BIOAGENTTY_BETA_BUNGAROTOXIN
 *    EEC_BIOAGENTTY_BLISTER_AGENT
 *    EEC_BIOAGENTTY_BLOOD_AGENT
 *    EEC_BIOAGENTTY_BOTULINUM_A
 *    EEC_BIOAGENTTY_BOTULINUM_B
 *    EEC_BIOAGENTTY_BOTULINUM_C
 *    EEC_BIOAGENTTY_BOTULINUM_D
 *    EEC_BIOAGENTTY_BOTULINUM_E
 *    EEC_BIOAGENTTY_BOTU_TOXIN_A
 *    EEC_BIOAGENTTY_BOTU_TOXIN_B
 *    EEC_BIOAGENTTY_BOTU_TOXIN_C
 *    EEC_BIOAGENTTY_BOTU_TOXIN_D
 *    EEC_BIOAGENTTY_BOTU_TOXIN_E
 *    EEC_BIOAGENTTY_BOTU_TOXIN_F
 *    EEC_BIOAGENTTY_BOTU_TOXIN_G
 *    EEC_BIOAGENTTY_BREVE
 *    EEC_BIOAGENTTY_BREVE_TOXIN
 *    EEC_BIOAGENTTY_BRUCELLA
 *    EEC_BIOAGENTTY_BRUCELLA_ABORTUS
 *    EEC_BIOAGENTTY_BRUCELLA_CANIS
 *    EEC_BIOAGENTTY_BRUCELLA_MELITENSIS
 *    EEC_BIOAGENTTY_BRUCELLA_NEOTOMAE
 *    EEC_BIOAGENTTY_BRUCELLA_OVIS
 *    EEC_BIOAGENTTY_BRUCELLA_SUIS
 *    EEC_BIOAGENTTY_BRUCELLOSIS
 *    EEC_BIOAGENTTY_CHOKING_AGENT
 *    EEC_BIOAGENTTY_CHOLERA
 *    EEC_BIOAGENTTY_CIGUA
 *    EEC_BIOAGENTTY_CIGUATOXIN
 *    EEC_BIOAGENTTY_COBRO
 *    EEC_BIOAGENTTY_COBROTOXIN
 *    EEC_BIOAGENTTY_CONO
 *    EEC_BIOAGENTTY_CONOTOXIN
 *    EEC_BIOAGENTTY_CRO
 *    EEC_BIOAGENTTY_CROTOXIN
 *    EEC_BIOAGENTTY_DEBROMOAPLYSIA
 *    EEC_BIOAGENTTY_DEBROMOAPLYSIATOXIN
 *    EEC_BIOAGENTTY_DIACETOXYSCIRPENOL
 *    EEC_BIOAGENTTY_DIPTHERIA
 *    EEC_BIOAGENTTY_ERABU
 *    EEC_BIOAGENTTY_ERABUTOXIN
 *    EEC_BIOAGENTTY_GAMMA_BUNGAROTOXIN
 *    EEC_BIOAGENTTY_GRAYANO
 *    EEC_BIOAGENTTY_GRAYANOTOXIN
 *    EEC_BIOAGENTTY_HEAT_LABILE_ENTERO
 *    EEC_BIOAGENTTY_HEAT_STABLE_ENTERO
 *    EEC_BIOAGENTTY_MICROCYSTIN
 *    EEC_BIOAGENTTY_MICROCYSTIN_TOXIN
 *    EEC_BIOAGENTTY_NERVE_AGENT
 *    EEC_BIOAGENTTY_NIVALENOL
 *    EEC_BIOAGENTTY_PALY
 *    EEC_BIOAGENTTY_PALYTOXIN
 *    EEC_BIOAGENTTY_PLAGUE
 *    EEC_BIOAGENTTY_Q_FEVER
 *    EEC_BIOAGENTTY_RICIN
 *    EEC_BIOAGENTTY_SAXI
 *    EEC_BIOAGENTTY_SAXITOXIN
 *    EEC_BIOAGENTTY_SHIGELLA
 *    EEC_BIOAGENTTY_SMALLPOX
 *    EEC_BIOAGENTTY_STAPH_ENTERO_A
 *    EEC_BIOAGENTTY_STAPH_ENTERO_B
 *    EEC_BIOAGENTTY_STAPH_ENTERO_C
 *    EEC_BIOAGENTTY_STAPH_ENTERO_C1
 *    EEC_BIOAGENTTY_STAPH_ENTERO_C2
 *    EEC_BIOAGENTTY_STAPH_ENTERO_C3
 *    EEC_BIOAGENTTY_STAPH_ENTERO_D
 *    EEC_BIOAGENTTY_STAPH_ENTERO_E
 *    EEC_BIOAGENTTY_STAPH_ENTERO_F
 *    EEC_BIOAGENTTY_T_2
 *    EEC_BIOAGENTTY_T2_TOXIN
 *    EEC_BIOAGENTTY_TETANUS
 *    EEC_BIOAGENTTY_TETRODO
 *    EEC_BIOAGENTTY_TETRODOTOXIN
 *    EEC_BIOAGENTTY_TRICHOTHECENE
 *    EEC_BIOAGENTTY_TRICHOTHECENE_MYCO
 *    EEC_BIOAGENTTY_TULARAEMIA
 *    EEC_BIOAGENTTY_VERATRIDINE
 *    EEC_BIOAGENTTY_VOMATOXIN
 *
 * Group Membership: LIVING_ORGANISM
 */
#define EAC_BIOLOGIC_AGENT_TYPE ((EDCS_Attribute_Code)170)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of external <LIGHTING> that is designed for use
 *     under military blackout conditions to prevent collision with/between
 *     <VEHICLE>s; the blackout brake light intensity. Zero means unlit and
 *     one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, MILITARY_SCIENCE, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_BLACKOUT_BRAKE_LIGHT_INTENSITY ((EDCS_Attribute_Code)171)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of internal <LIGHTING> that is designed for use
 *     under military blackout conditions. Zero means unlit and one means
 *     maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, MILITARY_SCIENCE, RATE_OR_RATIO
 */
#define EAC_BLACKOUT_LIGHT_INTENSITY ((EDCS_Attribute_Code)172)

/*
 * Definition:
 *     An indication that blowing <SAND> is present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_BLOWING_SAND ((EDCS_Attribute_Code)173)

/*
 * Definition:
 *     An indication that blowing <SNOW_PRECIPITATION> is present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, ICE
 */
#define EAC_BLOWING_SNOW ((EDCS_Attribute_Code)174)

/*
 * Definition:
 *     The type of a <BOMBER_WINGED_AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BMBWNGARCRFTY_B1A_LANCER_SERIES
 *    EEC_BMBWNGARCRFTY_B1B_LANCER_SERIES
 *    EEC_BMBWNGARCRFTY_B2_SPIRIT_SERIES
 *    EEC_BMBWNGARCRFTY_B52_STRATOFORTRESS_SERIES
 *    EEC_BMBWNGARCRFTY_TU142_BEAR_SERIES
 *    EEC_BMBWNGARCRFTY_TU160_BLACKJACK_SERIES
 *    EEC_BMBWNGARCRFTY_TU26_BACKFIRE_SERIES
 *    EEC_BMBWNGARCRFTY_TU95_BEAR_SERIES
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_BOMBER_WINGED_AIRCRAFT_TYPE ((EDCS_Attribute_Code)175)

/*
 * Definition:
 *     The military allegiance of an <OBJECT> identified by a
 *     <WATERBODY_FLOOR_SONAR_RETURN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BOTRETALEGN_FRIEND
 *    EEC_BOTRETALEGN_HOSTILE
 *    EEC_BOTRETALEGN_NEUTRAL
 *
 * Group Membership: ABSTRACT_OBJECT, ACOUSTIC_PHENOMENON, MILITARY_SCIENCE, WATERBODY_FLOOR
 */
#define EAC_BOTTOM_RETURN_ALLEGIANCE ((EDCS_Attribute_Code)176)

/*
 * Definition:
 *     The status of a <WATERBODY_FLOOR_SONAR_RETURN> indicating the presence
 *     of obstacles.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BOTRETOBSTSTAT_DETECTED
 *    EEC_BOTRETOBSTSTAT_CLASSIFIED
 *    EEC_BOTRETOBSTSTAT_IDENTIFIED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_FLOOR
 */
#define EAC_BOTTOM_RETURN_OBSTACLE_STATUS ((EDCS_Attribute_Code)177)

/*
 * Definition:
 *     The status of a <WATERBODY_FLOOR_SONAR_RETURN> indicating the presence
 *     of a <ROCK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BOTRETROCKSTAT_DETECTED
 *    EEC_BOTRETROCKSTAT_CLASSIFIED
 *    EEC_BOTRETROCKSTAT_IDENTIFIED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_FLOOR
 */
#define EAC_BOTTOM_RETURN_ROCK_STATUS ((EDCS_Attribute_Code)178)

/*
 * Definition:
 *     The status of a <WATERBODY_FLOOR_SONAR_RETURN> indicating the presence
 *     of installations on the <OCEAN_FLOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BOTRETSBEDSTAT_DETECTED
 *    EEC_BOTRETSBEDSTAT_CLASSIFIED
 *    EEC_BOTRETSBEDSTAT_IDENTIFIED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROGRAPHIC_ARTEFACT, WATERBODY_FLOOR
 */
#define EAC_BOTTOM_RETURN_SEABED_STATUS ((EDCS_Attribute_Code)179)

/*
 * Definition:
 *     The status of a <WATERBODY_FLOOR_SONAR_RETURN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BOTRETSTAT_DETECTED
 *    EEC_BOTRETSTAT_CLASSIFIED
 *    EEC_BOTRETSTAT_IDENTIFIED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_FLOOR
 */
#define EAC_BOTTOM_RETURN_STATUS ((EDCS_Attribute_Code)180)

/*
 * Definition:
 *     The numeric identifier of a <WATERBODY_FLOOR_SONAR_RETURN>; the bottom
 *     return track identifier.
 *
 * Value Type: INDEX
 *
 * Group Membership: ACOUSTIC_PHENOMENON, IDENTIFICATION, WATERBODY_FLOOR
 */
#define EAC_BOTTOM_RETURN_TRACK_IDENTIFIER ((EDCS_Attribute_Code)181)

/*
 * Definition:
 *     The type of a <WATERBODY_FLOOR_SONAR_RETURN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BOTRETTY_IDENTITY
 *    EEC_BOTRETTY_OBSTACLE
 *    EEC_BOTRETTY_ROCK
 *    EEC_BOTRETTY_SEABED_INSTALLATION
 *    EEC_BOTRETTY_WRECK
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_FLOOR
 */
#define EAC_BOTTOM_RETURN_TYPE ((EDCS_Attribute_Code)182)

/*
 * Definition:
 *     The status of a <WATERBODY_FLOOR_SONAR_RETURN> indicating a
 *     <MARINE_WRECK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BOTRETWRCKSTAT_DETECTED
 *    EEC_BOTRETWRCKSTAT_CLASSIFIED
 *    EEC_BOTRETWRCKSTAT_IDENTIFIED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE, WATERBODY_FLOOR
 */
#define EAC_BOTTOM_RETURN_WRECK_STATUS ((EDCS_Attribute_Code)183)

/*
 * Definition:
 *     The <<WIDTH>> of an <OBJECT> at its bottom.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_BOTTOM_WIDTH ((EDCS_Attribute_Code)184)

/*
 * Definition:
 *     The name of the political entity on the first side of a <BOUNDARY>.
 *
 * Value Type: STRING
 *
 * Group Membership: ADMINISTRATION, DEMARCATION, IDENTIFICATION
 */
#define EAC_BOUNDARY_FIRST_SIDE_NAME ((EDCS_Attribute_Code)185)

/*
 * Definition:
 *     The name of the political entity on the second side of a <BOUNDARY>.
 *
 * Value Type: STRING
 *
 * Group Membership: ADMINISTRATION, DEMARCATION, IDENTIFICATION
 */
#define EAC_BOUNDARY_SECOND_SIDE_NAME ((EDCS_Attribute_Code)186)

/*
 * Definition:
 *     The status of a <BOUNDARY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BNDRYSTAT_DEFINITE
 *    EEC_BNDRYSTAT_IN_DISPUTE
 *    EEC_BNDRYSTAT_INDEFINITE
 *    EEC_BNDRYSTAT_NOT_DEFINED
 *    EEC_BNDRYSTAT_NOT_RECOG_BY_DATA_PROVIDER
 *    EEC_BNDRYSTAT_RECOG_BY_DATA_PROVIDER
 *
 * Group Membership: DEMARCATION
 */
#define EAC_BOUNDARY_STATUS ((EDCS_Attribute_Code)187)

/*
 * Definition:
 *     The type of a <BOUNDARY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BNDRYTY_ACCESS_ZONE
 *    EEC_BNDRYTY_ADMINISTRATIVE
 *    EEC_BNDRYTY_ADMINISTRATIVE_REGION
 *    EEC_BNDRYTY_AIRSPACE
 *    EEC_BNDRYTY_AIRSPACE_COMPONENT
 *    EEC_BNDRYTY_ARMISTICE_LINE
 *    EEC_BNDRYTY_CEASE_FIRE_LINE
 *    EEC_BNDRYTY_CITY
 *    EEC_BNDRYTY_CITY_PARK
 *    EEC_BNDRYTY_CLAIM_LINE
 *    EEC_BNDRYTY_CONTACT_ZONE
 *    EEC_BNDRYTY_COUNTY
 *    EEC_BNDRYTY_COUNTY_PARK
 *    EEC_BNDRYTY_DE_FACTO
 *    EEC_BNDRYTY_DEMILITARIZED_ZONE
 *    EEC_BNDRYTY_DISPUTED
 *    EEC_BNDRYTY_HISTORICAL
 *    EEC_BNDRYTY_HOLIDAY_REGION
 *    EEC_BNDRYTY_INDIGENOUS_PEOPLES_RESERVE
 *    EEC_BNDRYTY_INTERNATIONAL_DATE_LINE
 *    EEC_BNDRYTY_LOCAL_PARK
 *    EEC_BNDRYTY_MAP
 *    EEC_BNDRYTY_MARINE_LIMIT
 *    EEC_BNDRYTY_MARINE_REGION
 *    EEC_BNDRYTY_NATIONAL
 *    EEC_BNDRYTY_NATIONAL_PARK
 *    EEC_BNDRYTY_NATIONAL_RESERVE_UNSPECIFIED
 *    EEC_BNDRYTY_NAVIGATION_RESTRICTED_REGION
 *    EEC_BNDRYTY_OCCUPATION_ZONE
 *    EEC_BNDRYTY_REGULATED_LINE
 *    EEC_BNDRYTY_STATE
 *    EEC_BNDRYTY_STATE_PARK
 *    EEC_BNDRYTY_STATE_RESERVE_UNSPECIFIED
 *    EEC_BNDRYTY_SWEPT_REGION
 *    EEC_BNDRYTY_TOWN
 *    EEC_BNDRYTY_TRAINING_SITE
 *    EEC_BNDRYTY_VACATION_REGION
 *    EEC_BNDRYTY_WATERSHED_DIVIDE
 *    EEC_BNDRYTY_WEAPONS_RANGE
 *
 * Group Membership: DEMARCATION
 */
#define EAC_BOUNDARY_TYPE ((EDCS_Attribute_Code)188)

/*
 * Definition:
 *     The function or configuration of a branch <RAILWAY>; the branch
 *     railway type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRRAILTY_ANY
 *    EEC_BRRAILTY_PASSING
 *    EEC_BRRAILTY_SIDING
 *    EEC_BRRAILTY_SPUR
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRANCH_RAILWAY_TYPE ((EDCS_Attribute_Code)189)

/*
 * Definition:
 *     The flank towards which the breaking <WATER_WAVE>s are moving in a
 *     <SURF_ZONE> as seen from <VESSEL>s approaching the <BEACH>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRKRFLANK_LEFT
 *    EEC_BRKRFLANK_RIGHT
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_SURFACE
 */
#define EAC_BREAKER_FLANK ((EDCS_Attribute_Code)190)

/*
 * Definition:
 *     The textual identifier (often termed the "number") of a <BRIDGE> and
 *     its <BRIDGE_SPAN>s.
 *
 * Value Type: STRING
 *
 * Group Membership: IDENTIFICATION, LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_AND_SPAN_IDENTIFIER ((EDCS_Attribute_Code)191)

/*
 * Definition:
 *     The type of structural <COMPONENT> of a <BRIDGE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRIDGECMPTTY_ABUTMENT
 *    EEC_BRIDGECMPTTY_DECK
 *    EEC_BRIDGECMPTTY_GUARD_RAIL
 *    EEC_BRIDGECMPTTY_PIER
 *    EEC_BRIDGECMPTTY_RAMP
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_COMPONENT_TYPE ((EDCS_Attribute_Code)192)

/*
 * Definition:
 *     The structural design characteristics of a <BRIDGE> or <BRIDGE_SPAN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRIDGEDES_ARCH
 *    EEC_BRIDGEDES_BAILEY
 *    EEC_BRIDGEDES_CANTILEVER
 *    EEC_BRIDGEDES_DECK
 *    EEC_BRIDGEDES_FLOATING
 *    EEC_BRIDGEDES_GIRDER
 *    EEC_BRIDGEDES_MEDIUM_GIRDER
 *    EEC_BRIDGEDES_MLTRY_ARMOUR_VEH_LAUNCHED
 *    EEC_BRIDGEDES_MLTRY_HEAVY_ASSAULT
 *    EEC_BRIDGEDES_MLTRY_M4T6
 *    EEC_BRIDGEDES_MLTRY_M60A1_EMPLACED_AVLB
 *    EEC_BRIDGEDES_MLTRY_PMP
 *    EEC_BRIDGEDES_MLTRY_TACTICAL
 *    EEC_BRIDGEDES_MLTRY_TMM
 *    EEC_BRIDGEDES_MOBILE_ASSAULT
 *    EEC_BRIDGEDES_MTU20_EMPLACED_AVLB
 *    EEC_BRIDGEDES_RIBBON
 *    EEC_BRIDGEDES_SLAB
 *    EEC_BRIDGEDES_STATIONARY_BRIDGE
 *    EEC_BRIDGEDES_STRINGER_BEAM
 *    EEC_BRIDGEDES_SUSPENSION
 *    EEC_BRIDGEDES_TRANSPORTER_FERRY
 *    EEC_BRIDGEDES_TRUSS
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_DESIGN ((EDCS_Attribute_Code)193)

/*
 * Definition:
 *     The type of <TERRAIN_OBSTACLE> that is spanned by a <BRIDGE>; the
 *     bridge function.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRIDGEFN_BUILDING
 *    EEC_BRIDGEFN_BUILT_UP_REGION
 *    EEC_BRIDGEFN_MAN_MADE_OBSTACLE
 *    EEC_BRIDGEFN_HYDROGRAPHIC_OBSTACLE
 *    EEC_BRIDGEFN_HYPSOGRAPHIC_OBSTACLE
 *    EEC_BRIDGEFN_MAN_MADE_WATERCOURSE
 *    EEC_BRIDGEFN_PATH
 *    EEC_BRIDGEFN_PHYSIOGRAPHIC_OBSTACLE
 *    EEC_BRIDGEFN_RAILWAY
 *    EEC_BRIDGEFN_RIVER
 *    EEC_BRIDGEFN_ROAD
 *    EEC_BRIDGEFN_VEGETATION_OBSTACLE
 *    EEC_BRIDGEFN_WATER_CONTAINMENT
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_FUNCTION ((EDCS_Attribute_Code)194)

/*
 * Definition:
 *     The textual identifier (often termed the "number") of a <BRIDGE>.
 *
 * Value Type: STRING
 *
 * Group Membership: IDENTIFICATION, LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_IDENTIFIER ((EDCS_Attribute_Code)195)

/*
 * Definition:
 *     The reliability of characteristic and load classification information
 *     for a <BRIDGE> based upon the data source.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRIDGEINFRELI_ESTIMATED
 *    EEC_BRIDGEINFRELI_KNOWN
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_INFORMATION_RELIABILITY ((EDCS_Attribute_Code)196)

/*
 * Definition:
 *     The number of levels of a <BRIDGE> that carries <GROUND_VEHICLE>s
 *     and/or <HUMAN>s; the bridge level count.
 *
 * Value Type: COUNT
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_LEVEL_COUNT ((EDCS_Attribute_Code)197)

/*
 * Definition:
 *     The type of movement by which a <BRIDGE_SPAN> allows passage of a
 *     <VESSEL>; the bridge opening type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRIDGEOPNTY_BASCULE
 *    EEC_BRIDGEOPNTY_LIFT
 *    EEC_BRIDGEOPNTY_RETRACTABLE
 *    EEC_BRIDGEOPNTY_SWING
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_OPENING_TYPE ((EDCS_Attribute_Code)198)

/*
 * Definition:
 *     The number of spans in a <BRIDGE> or <AQUEDUCT>; the bridge span count.
 *
 * Value Type: COUNT
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_SPAN_COUNT ((EDCS_Attribute_Code)199)

/*
 * Definition:
 *     An indication that a <BRIDGE_SPAN> moves in some manner to allow
 *     passage underneath.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_SPAN_MOBILE ((EDCS_Attribute_Code)200)

/*
 * Definition:
 *     The type of a moveable <BRIDGE_SPAN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRIDGESPANTY_ARCH_CLOSED_SPANDREL
 *    EEC_BRIDGESPANTY_ARCH_OPEN_SPANDREL
 *    EEC_BRIDGESPANTY_CULVERT
 *    EEC_BRIDGESPANTY_FLOATING
 *    EEC_BRIDGESPANTY_FRAME
 *    EEC_BRIDGESPANTY_MOVEABLE_TRUSS
 *    EEC_BRIDGESPANTY_PLATE
 *    EEC_BRIDGESPANTY_PLATE_BASCULE
 *    EEC_BRIDGESPANTY_PLATE_DRAW
 *    EEC_BRIDGESPANTY_PLATE_VERTICAL_LIFT
 *    EEC_BRIDGESPANTY_RETRACTABLE
 *    EEC_BRIDGESPANTY_SLAB
 *    EEC_BRIDGESPANTY_STRINGER_BEAM
 *    EEC_BRIDGESPANTY_STRINGER_DRAW
 *    EEC_BRIDGESPANTY_STRINGER_VERTICAL_LIFT
 *    EEC_BRIDGESPANTY_TRUSS
 *    EEC_BRIDGESPANTY_UNSPECIFIED_FIXED
 *    EEC_BRIDGESPANTY_VAULT
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_SPAN_TYPE ((EDCS_Attribute_Code)201)

/*
 * Definition:
 *     The type of structural design of a <BRIDGE> or <BRIDGE_SPAN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRIDGESTRTY_ARCH_CLOSED_SPANDREL
 *    EEC_BRIDGESTRTY_ARCH_OPEN_SPANDREL
 *    EEC_BRIDGESTRTY_ARCH_SUSPENSION
 *    EEC_BRIDGESTRTY_BASCULE
 *    EEC_BRIDGESTRTY_CABLE_STAYED
 *    EEC_BRIDGESTRTY_CANTILEVER
 *    EEC_BRIDGESTRTY_COVERED
 *    EEC_BRIDGESTRTY_DECK
 *    EEC_BRIDGESTRTY_DRAW
 *    EEC_BRIDGESTRTY_FIXED
 *    EEC_BRIDGESTRTY_FOOT
 *    EEC_BRIDGESTRTY_GIRDER
 *    EEC_BRIDGESTRTY_LIFT
 *    EEC_BRIDGESTRTY_MOVEABLE_SURFACE
 *    EEC_BRIDGESTRTY_OPENING
 *    EEC_BRIDGESTRTY_PONTOON
 *    EEC_BRIDGESTRTY_RETRACTABLE
 *    EEC_BRIDGESTRTY_SLAB
 *    EEC_BRIDGESTRTY_STRINGER_BEAM
 *    EEC_BRIDGESTRTY_SUSPENSION
 *    EEC_BRIDGESTRTY_SUSPENSION_BOW_STRING
 *    EEC_BRIDGESTRTY_SUSPENSION_CABLE_STAYED
 *    EEC_BRIDGESTRTY_SWING
 *    EEC_BRIDGESTRTY_TOWER_SUSPENSION
 *    EEC_BRIDGESTRTY_TRANSPORTER
 *    EEC_BRIDGESTRTY_TRUSS
 *    EEC_BRIDGESTRTY_UNSPECIFIED_FIXED
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BRIDGE_STRUCTURE_TYPE ((EDCS_Attribute_Code)202)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of <LAND> covered by undergrowth (for example: scrub, brush,
 *     and/or bush); the brush density. Zero means no undergrowth and one
 *     means completely covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT, RATE_OR_RATIO
 */
#define EAC_BRUSH_DENSITY ((EDCS_Attribute_Code)203)

/*
 * Definition:
 *     The designation of a <NON_EMPTY_SET> of closely related Buddhist
 *     religious denominations, often ones which were at one time part of a
 *     single movement but are now separate religious denominations; the
 *     Buddhist denominational family.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BUDDENOMFAM_BUZAN_HA
 *    EEC_BUDDENOMFAM_CHIZAN_HA
 *    EEC_BUDDENOMFAM_MAHAYANA
 *    EEC_BUDDENOMFAM_SHINGON
 *    EEC_BUDDENOMFAM_THERAVADA
 *
 * Group Membership: RELIGION
 */
#define EAC_BUDDHISM_DENOMINATIONAL_FAMILY ((EDCS_Attribute_Code)204)

/*
 * Definition:
 *     The type of a <BUILDING_COMPONENT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BLDGCMPTTY_ANTE_ROOM
 *    EEC_BLDGCMPTTY_APERTURE
 *    EEC_BLDGCMPTTY_ATRIUM
 *    EEC_BLDGCMPTTY_BALCONY
 *    EEC_BLDGCMPTTY_BREACH_HOLE
 *    EEC_BLDGCMPTTY_CATWALK
 *    EEC_BLDGCMPTTY_CHIMNEY
 *    EEC_BLDGCMPTTY_CLOSET
 *    EEC_BLDGCMPTTY_COMBUSTION_PRODUCT_DISCHARGE
 *    EEC_BLDGCMPTTY_CONTROL_PANEL
 *    EEC_BLDGCMPTTY_DOOR
 *    EEC_BLDGCMPTTY_DOORWAY
 *    EEC_BLDGCMPTTY_ENTRANCE_OR_EXIT
 *    EEC_BLDGCMPTTY_ESCALATOR
 *    EEC_BLDGCMPTTY_EXTERIOR_WALL
 *    EEC_BLDGCMPTTY_FIRE_ESCAPE
 *    EEC_BLDGCMPTTY_FLOOR_LEVEL
 *    EEC_BLDGCMPTTY_FURNITURE
 *    EEC_BLDGCMPTTY_GABLE
 *    EEC_BLDGCMPTTY_HALLWAY
 *    EEC_BLDGCMPTTY_HEAT_RADIATOR
 *    EEC_BLDGCMPTTY_INTERIOR_WALL
 *    EEC_BLDGCMPTTY_INTERIOR_WALL_OPENING
 *    EEC_BLDGCMPTTY_LIFT_SHAFT
 *    EEC_BLDGCMPTTY_PULPIT
 *    EEC_BLDGCMPTTY_RAMP
 *    EEC_BLDGCMPTTY_ROOF
 *    EEC_BLDGCMPTTY_ROOM
 *    EEC_BLDGCMPTTY_SKYLIGHT
 *    EEC_BLDGCMPTTY_SMOKESTACK
 *    EEC_BLDGCMPTTY_STAIR
 *    EEC_BLDGCMPTTY_STAIR_SET
 *    EEC_BLDGCMPTTY_STAIRCASE
 *    EEC_BLDGCMPTTY_STEEPLE
 *    EEC_BLDGCMPTTY_SUPERSTRUCTURE
 *    EEC_BLDGCMPTTY_TRAPDOOR
 *    EEC_BLDGCMPTTY_VENTILATION_DUCT
 *    EEC_BLDGCMPTTY_VENTILATION_APERTURE
 *    EEC_BLDGCMPTTY_VENTILATION_SHAFT
 *    EEC_BLDGCMPTTY_WALL_LOOPHOLE
 *    EEC_BLDGCMPTTY_WINDOW
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_BUILDING_COMPONENT_TYPE ((EDCS_Attribute_Code)205)

/*
 * Definition:
 *     The type of technique used to construct a <BUILDING>. The basic
 *     techniques are mass (where the walls carry the load) and framed
 *     (where an internal frame carries the load and walls simply protect
 *     the interior from the elements).
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BLDGCNSTCTTY_AGGREGATE_CLAD_STEEL_FRAME
 *    EEC_BLDGCNSTCTTY_BOX_WALL_CNCRT_MASS
 *    EEC_BLDGCNSTCTTY_BRICK_CLAD_STEEL_FRAME
 *    EEC_BLDGCNSTCTTY_BRICK_CLAD_WOOD_FRAME
 *    EEC_BLDGCNSTCTTY_BRICK_CNCRT_BLOCK_MASS
 *    EEC_BLDGCNSTCTTY_BRICK_MASS
 *    EEC_BLDGCNSTCTTY_CNCRT_BLOCK_MASS
 *    EEC_BLDGCNSTCTTY_CNCRT_MASS
 *    EEC_BLDGCNSTCTTY_DRESSED_STONE_MASS
 *    EEC_BLDGCNSTCTTY_FABRIC_TENSILE_FRAME
 *    EEC_BLDGCNSTCTTY_GEODESIC_FRAME
 *    EEC_BLDGCNSTCTTY_GLASS_CLAD_STEEL_FRAME
 *    EEC_BLDGCNSTCTTY_HALF_TIMBERED_WOOD_FRAME
 *    EEC_BLDGCNSTCTTY_HEAVY_CLAD_STEEL_FRAME
 *    EEC_BLDGCNSTCTTY_LIGHT_CLAD_STEEL_FRAME
 *    EEC_BLDGCNSTCTTY_LIGHT_CLAD_WOOD_FRAME
 *    EEC_BLDGCNSTCTTY_MASONARY_MASS
 *    EEC_BLDGCNSTCTTY_METAL_CLAD_STEEL_FRAME
 *    EEC_BLDGCNSTCTTY_PLASTIC_CLAD_STEEL_FRAME
 *    EEC_BLDGCNSTCTTY_POURED_CNCRT_MASS
 *    EEC_BLDGCNSTCTTY_STONE_MASS
 *    EEC_BLDGCNSTCTTY_STONE_RUBBLE_MASS
 *    EEC_BLDGCNSTCTTY_STUCCO_CLAD_WOOD_FRAME
 *    EEC_BLDGCNSTCTTY_TILT_UP_CNCRT_MASS
 *    EEC_BLDGCNSTCTTY_UNKNOWN_FRAME
 *    EEC_BLDGCNSTCTTY_UNKNOWN_MASS
 *    EEC_BLDGCNSTCTTY_WOOD_CLAD_WOOD_FRAME
 *
 * Group Membership: SHELTER
 */
#define EAC_BUILDING_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)206)

/*
 * Definition:
 *     The type of <MATERIAL> and/or techniques used to construct the
 *     foundation of a <BUILDING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BLDGFOUNDTY_BEAM_ON_GRADE
 *    EEC_BLDGFOUNDTY_COLUMNS_WITH_PILE_CAPS
 *    EEC_BLDGFOUNDTY_INCLINED_SLAB_ON_GRADE
 *    EEC_BLDGFOUNDTY_PILE
 *    EEC_BLDGFOUNDTY_STANDARD_SLAB_ON_GRADE
 *    EEC_BLDGFOUNDTY_STEEL_GIRDER
 *    EEC_BLDGFOUNDTY_STRUCTURAL_SLAB_ON_GRADE
 *    EEC_BLDGFOUNDTY_WALL
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_BUILDING_FOUNDATION_TYPE ((EDCS_Attribute_Code)207)

/*
 * Definition:
 *     The function of a <BUILDING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BLDGFN_ADMINISTRATION
 *    EEC_BLDGFN_AERATION
 *    EEC_BLDGFN_AERODROME_TERMINAL
 *    EEC_BLDGFN_AIRCRAFT_HANGAR
 *    EEC_BLDGFN_AIRCRAFT_MAINTENANCE_SHOP
 *    EEC_BLDGFN_AIRSHIP_MOORING
 *    EEC_BLDGFN_AMBASSADORIAL_RESIDENCE
 *    EEC_BLDGFN_APARTMENT_HOUSE
 *    EEC_BLDGFN_APARTMENT_HOTEL
 *    EEC_BLDGFN_ARBORETUM
 *    EEC_BLDGFN_ARCHAELOGICAL_SITE
 *    EEC_BLDGFN_ARMOURY
 *    EEC_BLDGFN_ASTRONOMICAL_STATION
 *    EEC_BLDGFN_AUDITORIUM
 *    EEC_BLDGFN_AUTOMOTIVE_PLANT
 *    EEC_BLDGFN_BANK_BUILDING
 *    EEC_BLDGFN_BARN
 *    EEC_BLDGFN_BARRACK
 *    EEC_BLDGFN_BATTERY
 *    EEC_BLDGFN_BEACON_STRUCTURE
 *    EEC_BLDGFN_BLOCKHOUSE
 *    EEC_BLDGFN_BUS_STATION
 *    EEC_BLDGFN_CAPITOL
 *    EEC_BLDGFN_CAR_WASH
 *    EEC_BLDGFN_CARPENTRY
 *    EEC_BLDGFN_CASTLE
 *    EEC_BLDGFN_CEMETERY
 *    EEC_BLDGFN_CHANCERY
 *    EEC_BLDGFN_CHIMNEY
 *    EEC_BLDGFN_CHURCH
 *    EEC_BLDGFN_CITY_HALL
 *    EEC_BLDGFN_CLOCK
 *    EEC_BLDGFN_COLLEGIATE
 *    EEC_BLDGFN_COMMERCE
 *    EEC_BLDGFN_COMMERCE_OR_RECREATION
 *    EEC_BLDGFN_COMMUNICATION
 *    EEC_BLDGFN_COMMUNICATION_TOWER
 *    EEC_BLDGFN_COMMUNITY_CENTRE
 *    EEC_BLDGFN_CONSULATE
 *    EEC_BLDGFN_CONTROL_TOWER
 *    EEC_BLDGFN_COOLING_TOWER
 *    EEC_BLDGFN_CORRECTIONAL
 *    EEC_BLDGFN_COUNTY_HALL
 *    EEC_BLDGFN_CUSTOMS_HOUSE
 *    EEC_BLDGFN_DAM
 *    EEC_BLDGFN_DEPENDENTS_HOUSING
 *    EEC_BLDGFN_DEPENDENTS_OR_BIVOUAC
 *    EEC_BLDGFN_DEPOT
 *    EEC_BLDGFN_DIPLOMATIC
 *    EEC_BLDGFN_DISPOSAL_SITE
 *    EEC_BLDGFN_DORMITORY
 *    EEC_BLDGFN_EMBASSY
 *    EEC_BLDGFN_FABRICATION
 *    EEC_BLDGFN_FACTORY
 *    EEC_BLDGFN_FARM
 *    EEC_BLDGFN_FARM_BUILDING
 *    EEC_BLDGFN_FARM_STORAGE
 *    EEC_BLDGFN_FILTRATION
 *    EEC_BLDGFN_FIRE_AND_POLICE_STATION
 *    EEC_BLDGFN_FIRE_STATION
 *    EEC_BLDGFN_FOOD_OVEN
 *    EEC_BLDGFN_FORT
 *    EEC_BLDGFN_GOVERNMENT
 *    EEC_BLDGFN_GOVERNMENT_ADMINISTRATION
 *    EEC_BLDGFN_GOVERNMENT_INSTITUTION
 *    EEC_BLDGFN_GRAIN_STORAGE_STRUCTURE
 *    EEC_BLDGFN_GRANDSTAND
 *    EEC_BLDGFN_GREENHOUSE
 *    EEC_BLDGFN_GUARD_TOWER
 *    EEC_BLDGFN_GUARDHOUSE
 *    EEC_BLDGFN_GUARDROOM
 *    EEC_BLDGFN_HARBOUR_MASTERS_OFFICE
 *    EEC_BLDGFN_HAYSTACK
 *    EEC_BLDGFN_HEALTH_OFFICE
 *    EEC_BLDGFN_HOSPITAL
 *    EEC_BLDGFN_HOSTEL
 *    EEC_BLDGFN_HOTEL
 *    EEC_BLDGFN_HOUSE
 *    EEC_BLDGFN_HUT
 *    EEC_BLDGFN_INDUSTRIAL
 *    EEC_BLDGFN_INDUSTRIAL_OVEN
 *    EEC_BLDGFN_INSTITUTION
 *    EEC_BLDGFN_INTEREST_SITE
 *    EEC_BLDGFN_JAIL
 *    EEC_BLDGFN_KENNEL
 *    EEC_BLDGFN_KILN
 *    EEC_BLDGFN_LEGATION
 *    EEC_BLDGFN_LIBRARY
 *    EEC_BLDGFN_LIGHTHOUSE
 *    EEC_BLDGFN_MARINE_LOCK
 *    EEC_BLDGFN_MARINE_POLICE_STATION
 *    EEC_BLDGFN_MARINE_STATION
 *    EEC_BLDGFN_MARKET
 *    EEC_BLDGFN_MARTELLO_TOWER
 *    EEC_BLDGFN_MEASURING_STATION
 *    EEC_BLDGFN_MEDICAL_CENTRE
 *    EEC_BLDGFN_MEMORIAL_MONUMENT
 *    EEC_BLDGFN_MESS_HALL
 *    EEC_BLDGFN_MILITARY_CIVIL
 *    EEC_BLDGFN_MILITARY_OPERATIONS
 *    EEC_BLDGFN_MISSION
 *    EEC_BLDGFN_MOBILE_HOME
 *    EEC_BLDGFN_MOTEL
 *    EEC_BLDGFN_MOTOR_VEHICLE_STATION
 *    EEC_BLDGFN_MULTI_UNIT_DWELLING
 *    EEC_BLDGFN_MUNICIPAL_HALL
 *    EEC_BLDGFN_MUNICIPAL_UTILITY_FACILITY
 *    EEC_BLDGFN_MUSEUM
 *    EEC_BLDGFN_NAUTICAL_CLUB
 *    EEC_BLDGFN_NEWSPAPER_PLANT
 *    EEC_BLDGFN_NONE_IMPORTANT
 *    EEC_BLDGFN_OBSERVATION_STATION
 *    EEC_BLDGFN_OBSERVATORY
 *    EEC_BLDGFN_OPERA_HOUSE
 *    EEC_BLDGFN_OPERATING_STATION
 *    EEC_BLDGFN_OUTBUILDING
 *    EEC_BLDGFN_PALACE
 *    EEC_BLDGFN_PAPER_MILL
 *    EEC_BLDGFN_PARK
 *    EEC_BLDGFN_PARKING_GARAGE
 *    EEC_BLDGFN_PETROLEUM
 *    EEC_BLDGFN_PIER
 *    EEC_BLDGFN_PILOT_LOOKOUT
 *    EEC_BLDGFN_PILOT_OFFICE
 *    EEC_BLDGFN_POLICE_STATION
 *    EEC_BLDGFN_PORT_CONTROL
 *    EEC_BLDGFN_POST_OFFICE
 *    EEC_BLDGFN_POWER_GENERATION
 *    EEC_BLDGFN_POWER_SUBSTATION
 *    EEC_BLDGFN_POWER_TRANSMISSION_LINE_PYLON
 *    EEC_BLDGFN_PRISON
 *    EEC_BLDGFN_PROCESSING
 *    EEC_BLDGFN_PUBLIC_HEALTH_OFFICE
 *    EEC_BLDGFN_PUBLIC_INN
 *    EEC_BLDGFN_PUMP_ROOM
 *    EEC_BLDGFN_RACE_TRACK
 *    EEC_BLDGFN_RAILWAY_SIGNAL_BOX
 *    EEC_BLDGFN_RAILWAY_SIGNAL_STRUCTURE
 *    EEC_BLDGFN_RAILWAY_SIGNALMAN_HOUSE
 *    EEC_BLDGFN_RAILWAY_STATION
 *    EEC_BLDGFN_RAILWAY_STORAGE_REPAIR
 *    EEC_BLDGFN_RANGER_STATION
 *    EEC_BLDGFN_RECREATION
 *    EEC_BLDGFN_RECREATIONAL_PIER
 *    EEC_BLDGFN_REDOUBT
 *    EEC_BLDGFN_REFORMATORY
 *    EEC_BLDGFN_REFUGE_SHELTER
 *    EEC_BLDGFN_REPAIR_FACILITY
 *    EEC_BLDGFN_RESCUE
 *    EEC_BLDGFN_RESIDENCE
 *    EEC_BLDGFN_RESIDENCE_OR_AGRICULTURE
 *    EEC_BLDGFN_RESTAURANT
 *    EEC_BLDGFN_RETAIL_FACILITY
 *    EEC_BLDGFN_ROAD_MAINTENANCE_STATION
 *    EEC_BLDGFN_ROADSIDE_REST_STOP
 *    EEC_BLDGFN_ROUNDHOUSE
 *    EEC_BLDGFN_RUINS
 *    EEC_BLDGFN_SANATORIUM
 *    EEC_BLDGFN_SATELLITE_GROUND_STATION
 *    EEC_BLDGFN_SAWMILL
 *    EEC_BLDGFN_SCHOOL
 *    EEC_BLDGFN_SCIENCE
 *    EEC_BLDGFN_SEMINARY
 *    EEC_BLDGFN_SENIOR_CITIZENS_HOME
 *    EEC_BLDGFN_SHED
 *    EEC_BLDGFN_SHIPYARD
 *    EEC_BLDGFN_SHOPPING_CENTRE
 *    EEC_BLDGFN_SHRINE
 *    EEC_BLDGFN_SPORTSPLEX
 *    EEC_BLDGFN_STADIUM
 *    EEC_BLDGFN_STEEL_MILL
 *    EEC_BLDGFN_STORAGE_TANK
 *    EEC_BLDGFN_TEL_SHELTER
 *    EEC_BLDGFN_TELEPHONE_EXCHANGE_MAIN
 *    EEC_BLDGFN_TELEPHONE_SWITCHING
 *    EEC_BLDGFN_TELESCOPE
 *    EEC_BLDGFN_TEMPORARY_ENCAMPMENT
 *    EEC_BLDGFN_THEATRE
 *    EEC_BLDGFN_TIMEBALL
 *    EEC_BLDGFN_TOWN_HALL
 *    EEC_BLDGFN_TRADING_POST
 *    EEC_BLDGFN_TRANSPORTATION
 *    EEC_BLDGFN_VEGETABLE_OIL_MILL
 *    EEC_BLDGFN_VEHICLE_SCALE
 *    EEC_BLDGFN_WAREHOUSE
 *    EEC_BLDGFN_WATER_DRIVEN_GRISTMILL
 *    EEC_BLDGFN_WATER_TOWER
 *    EEC_BLDGFN_WEAPONS_RANGE
 *    EEC_BLDGFN_WEATHER_STATION
 *    EEC_BLDGFN_WIND_TUNNEL
 *    EEC_BLDGFN_WIND_VANE
 *    EEC_BLDGFN_WINDMILL
 *    EEC_BLDGFN_WINDSCREEN
 *    EEC_BLDGFN_WORSHIP_PLACE
 *
 * Group Membership: SHELTER
 */
#define EAC_BUILDING_FUNCTION ((EDCS_Attribute_Code)208)

/*
 * Definition:
 *     The relative density of a <BUILT_UP_REGION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BLTUPREGNDENS_SPARSE
 *    EEC_BLTUPREGNDENS_MODERATE
 *    EEC_BLTUPREGNDENS_DENSE
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define EAC_BUILT_UP_REGION_DENSITY ((EDCS_Attribute_Code)209)

/*
 * Definition:
 *     The shape of a <BUOY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BUOYSHAP_BARREL
 *    EEC_BUOYSHAP_CAN
 *    EEC_BUOYSHAP_CONICAL
 *    EEC_BUOYSHAP_PILLAR
 *    EEC_BUOYSHAP_SHUTTLE
 *    EEC_BUOYSHAP_SPAR
 *    EEC_BUOYSHAP_SPHERICAL
 *    EEC_BUOYSHAP_SUPER
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_SURFACE
 */
#define EAC_BUOY_SHAPE ((EDCS_Attribute_Code)210)

/*
 * Definition:
 *     The type of a <BUOY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BUOYTY_ANCHORAGE
 *    EEC_BUOYTY_ANCHORING_PROHIBITED
 *    EEC_BUOYTY_APEX
 *    EEC_BUOYTY_ARTICULATED
 *    EEC_BUOYTY_BERTHING_PERMITTED
 *    EEC_BUOYTY_BERTHING_PROHIBITED
 *    EEC_BUOYTY_BIFURCATION
 *    EEC_BUOYTY_CABLE
 *    EEC_BUOYTY_CARDINAL
 *    EEC_BUOYTY_CAUTION
 *    EEC_BUOYTY_CHANNEL_CENTRE
 *    EEC_BUOYTY_CHANNEL_EDGE_GRADIENT
 *    EEC_BUOYTY_CLEARING_LINE
 *    EEC_BUOYTY_COMPASS_ADJUSTMENT
 *    EEC_BUOYTY_CONTROL
 *    EEC_BUOYTY_DAN
 *    EEC_BUOYTY_DAYBEACON
 *    EEC_BUOYTY_DEGAUSSING_RANGE
 *    EEC_BUOYTY_DIVING
 *    EEC_BUOYTY_DND_CANADA
 *    EEC_BUOYTY_EAST_CARDINAL
 *    EEC_BUOYTY_ELEVATED_ELECTRICAL_CABLE
 *    EEC_BUOYTY_EXPLOSIVES_ANCHORAGE
 *    EEC_BUOYTY_FAIRWAY
 *    EEC_BUOYTY_FERRY_CROSSING
 *    EEC_BUOYTY_FIRING_DANGER
 *    EEC_BUOYTY_FISH_TRAP
 *    EEC_BUOYTY_FLOAT
 *    EEC_BUOYTY_FLOAT_WITH_BEACON
 *    EEC_BUOYTY_FOUL_GROUND
 *    EEC_BUOYTY_GENERAL_WARNING
 *    EEC_BUOYTY_GPS
 *    EEC_BUOYTY_HELIPORT
 *    EEC_BUOYTY_ICE
 *    EEC_BUOYTY_ILLUMINATED
 *    EEC_BUOYTY_INFORMATION
 *    EEC_BUOYTY_INSTALLATION
 *    EEC_BUOYTY_ISOLATED_DANGER
 *    EEC_BUOYTY_JUNCTION
 *    EEC_BUOYTY_KEEPOUT
 *    EEC_BUOYTY_LARGE_AUTOMATED_NAVIGATION
 *    EEC_BUOYTY_LATERAL
 *    EEC_BUOYTY_LEADING
 *    EEC_BUOYTY_LIGHT_FLOAT
 *    EEC_BUOYTY_MARKER_VESSEL
 *    EEC_BUOYTY_MAXIMUM_VESSEL_DRAFT
 *    EEC_BUOYTY_MEASURED_DISTANCE
 *    EEC_BUOYTY_MILITARY_PRACTICE
 *    EEC_BUOYTY_MODIFIED_PORT_LATERAL
 *    EEC_BUOYTY_MODIFIED_STARBOARD_LATERAL
 *    EEC_BUOYTY_MOORING
 *    EEC_BUOYTY_MOORING_WITH_TELEGRAPH
 *    EEC_BUOYTY_MOORING_WITH_TELEPHONE
 *    EEC_BUOYTY_NAVIGATION_COMM_CONTROL
 *    EEC_BUOYTY_NORTH_CARDINAL
 *    EEC_BUOYTY_NOTICE
 *    EEC_BUOYTY_OBSTRUCTION
 *    EEC_BUOYTY_ODAS
 *    EEC_BUOYTY_OUTER_LANDFALL
 *    EEC_BUOYTY_OUTFALL
 *    EEC_BUOYTY_OVERTAKING_PROHIBITED
 *    EEC_BUOYTY_PIPELINE
 *    EEC_BUOYTY_PORT_HAND
 *    EEC_BUOYTY_PORT_HAND_LATERAL
 *    EEC_BUOYTY_PREFERRED_CHANNEL_PORT
 *    EEC_BUOYTY_PREFERRED_CHANNEL_STARBOARD
 *    EEC_BUOYTY_PRIVATE
 *    EEC_BUOYTY_QUARANTINE
 *    EEC_BUOYTY_RECORDING
 *    EEC_BUOYTY_RECREATION_ZONE
 *    EEC_BUOYTY_REDUCED_WAKE
 *    EEC_BUOYTY_REFUGE
 *    EEC_BUOYTY_RESTRICT_HORIZ_CLEAR
 *    EEC_BUOYTY_RESTRICT_VERT_CLEAR
 *    EEC_BUOYTY_SAFE_WATER
 *    EEC_BUOYTY_SEAPLANE_ANCHORAGE
 *    EEC_BUOYTY_SOUND_SHIPS_SIREN
 *    EEC_BUOYTY_SOUTH_CARDINAL
 *    EEC_BUOYTY_SPECIAL_PURPOSE
 *    EEC_BUOYTY_SPEED_LIMIT
 *    EEC_BUOYTY_SPOIL_GROUND
 *    EEC_BUOYTY_STARBOARD_HAND
 *    EEC_BUOYTY_STARBOARD_HAND_LATERAL
 *    EEC_BUOYTY_STOP
 *    EEC_BUOYTY_STRONG_CURRENT
 *    EEC_BUOYTY_SWIMMING
 *    EEC_BUOYTY_TANKER
 *    EEC_BUOYTY_TARGET
 *    EEC_BUOYTY_TELEGRAPH_CABLE
 *    EEC_BUOYTY_TELEPHONE
 *    EEC_BUOYTY_TROT_LINE
 *    EEC_BUOYTY_TSS
 *    EEC_BUOYTY_TWO_WAY_PROHIBITED
 *    EEC_BUOYTY_UNKNOWN_PURPOSE
 *    EEC_BUOYTY_WARPING
 *    EEC_BUOYTY_WAVE_METER
 *    EEC_BUOYTY_WAVERIDER
 *    EEC_BUOYTY_WEST_CARDINAL
 *    EEC_BUOYTY_WORK_IN_PROGRESS
 *    EEC_BUOYTY_WRECK
 *    EEC_BUOYTY_YACHTING
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_SURFACE
 */
#define EAC_BUOY_TYPE ((EDCS_Attribute_Code)211)

/*
 * Definition:
 *     The degree of ease or ability to circumvent a destroyed section of
 *     <BRIDGE>, <TUNNEL>, or <MOUNTAIN_PASS> within a 2 kilometre distance
 *     on each side of the <OBJECT> (ignoring the presence of other similar
 *     <OBJECT>s); the bypass condition.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BYPCND_EASY
 *    EEC_BYPCND_DIFFICULT
 *    EEC_BYPCND_IMPOSSIBLE
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_BYPASS_CONDITION ((EDCS_Attribute_Code)212)

/*
 * Definition:
 *     The type of a cable.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CABLETY_MOORING
 *    EEC_CABLETY_NONE_PRESENT
 *    EEC_CABLETY_POWER_LINE
 *    EEC_CABLETY_POWER_TRANSMISSION_LINE
 *    EEC_CABLETY_TELEGRAPH
 *    EEC_CABLETY_TELEPHONE
 *    EEC_CABLETY_TELEVISION
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, SUPPORT_STRUCTURE
 */
#define EAC_CABLE_TYPE ((EDCS_Attribute_Code)213)

/*
 * Definition:
 *     The calendar date; formatted as specified by <<DATE_FORMAT>> or by
 *     <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TIME
 */
#define EAC_CALENDAR_DATE ((EDCS_Attribute_Code)214)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the total fraction of
 *     reports on the state of a <<SEA_STATE_CATEGORY>> indicating calm sea
 *     state (whether glassy or rippled) during the reporting
 *     <<TIME_PERIOD>>. Zero means no reports indicated calm and one means
 *     all reports indicated calm.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: HYDROLOGY, RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_CALM_SEA_STATE_FRACTION ((EDCS_Attribute_Code)215)

/*
 * Definition:
 *     The <MATERIAL> and/or technique used to camouflage an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CAMOUFLAGETY_DEAD_VEGETATION
 *    EEC_CAMOUFLAGETY_DEBRIS
 *    EEC_CAMOUFLAGETY_DESERT_PAINT
 *    EEC_CAMOUFLAGETY_FOREST_PAINT
 *    EEC_CAMOUFLAGETY_GROWING_VEGETATION
 *    EEC_CAMOUFLAGETY_INERT_TERRAIN_MATERIAL
 *    EEC_CAMOUFLAGETY_NET
 *    EEC_CAMOUFLAGETY_NET_AND_PAINT
 *    EEC_CAMOUFLAGETY_NONE_PRESENT
 *    EEC_CAMOUFLAGETY_URBAN_PAINT
 *    EEC_CAMOUFLAGETY_WINTER_PAINT
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL
 */
#define EAC_CAMOUFLAGE_TYPE ((EDCS_Attribute_Code)216)

/*
 * Definition:
 *     The capacity of an <OBJECT> formatted in a Basic Latin string. The
 *     string contains a number, followed by a unit enclosed in parenthesis
 *     ("( )"), followed by a unit qualifier enclosed in square brackets ("[
 *     ]"). EXAMPLE "100(cars)[per hour]".
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_CAPACITY ((EDCS_Attribute_Code)217)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the case of an <EQUIPMENT> that is buried beneath the
 *     <TERRAIN>. Zero means not buried at all and one means completely
 *     buried.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, RATE_OR_RATIO
 */
#define EAC_CASE_BURIAL_FRACTION ((EDCS_Attribute_Code)218)

/*
 * Definition:
 *     An indication that CAVOK conditions prevail. The indication is TRUE
 *     if: (1) visibility is 10 kilometres or more; (2) there are no
 *     <CLOUD>s below 1,5 kilometres or below the highest minimum sector
 *     altitude, whichever is greater; and (3) there are no cumulonimbus
 *     <CLOUD>s, <PRECIPITATION>, <THUNDERSTORM>s, shallow <FOG>, or low
 *     drifting <SNOW_GROUND_COVER> present; ceiling and visibility OK.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ATMOSPHERE, LIGHTING_AND_VISIBILITY
 */
#define EAC_CEILING_AND_VISIBILITY_OK ((EDCS_Attribute_Code)219)

/*
 * Definition:
 *     The centre <<FREQUENCY>> of a frequency band for which acoustic data
 *     were measured.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: ACOUSTIC_PHENOMENON
 */
#define EAC_CENTRE_FREQUENCY_BAND ((EDCS_Attribute_Code)220)

/*
 * Definition:
 *     The type of an <OBJECT> or phenomenon associated with a <CHANGE_POINT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CHGPTTY_BOUNDARY
 *    EEC_CHGPTTY_HYDROGRAPHY
 *    EEC_CHGPTTY_OBSTACLE
 *    EEC_CHGPTTY_RAILWAY
 *    EEC_CHGPTTY_ROAD
 *    EEC_CHGPTTY_ROAD_OR_RAILWAY
 *    EEC_CHGPTTY_ROAD_WIDTH_CHANGE
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_CHANGE_POINT_TYPE ((EDCS_Attribute_Code)221)

/*
 * Definition:
 *     The single character that is being emitted by a signalling <DEVICE>
 *     (for example: a <LIGHT>, a <BEACON>, and/or a communications
 *     transmitter).
 *
 * Value Type: STRING
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT
 */
#define EAC_CHARACTER_EMITTED ((EDCS_Attribute_Code)222)

/*
 * Definition:
 *     The species of a charged <PARTICLE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CHRGPARTICSPC_ALPHA
 *    EEC_CHRGPARTICSPC_ELECTRON
 *    EEC_CHRGPARTICSPC_HYDROGEN_ION
 *    EEC_CHRGPARTICSPC_OXYGEN_ION
 *    EEC_CHRGPARTICSPC_PROTON
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_CHARGED_PARTICLE_SPECIES ((EDCS_Attribute_Code)223)

/*
 * Definition:
 *     The concentration of a chemical agent suspended in an <ATMOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_CHEMICAL_AGENT_ATM_CONCENTRATION ((EDCS_Attribute_Code)224)

/*
 * Definition:
 *     The concentration of a chemical agent contained in a layer on the
 *     <SURFACE> of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: RATE_OR_RATIO, SURFACE, SURFACE_MATERIAL
 */
#define EAC_CHEMICAL_AGENT_SURFACE_CONCENTRATION ((EDCS_Attribute_Code)225)

/*
 * Definition:
 *     The type of a chemical agent that can kill, seriously injure, or
 *     incapacitate <HUMAN>s or <NON_HUMAN_ANIMAL>s through its
 *     physiological properties.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CHEMAGENTTY_CA
 *    EEC_CHEMAGENTTY_CN
 *    EEC_CHEMAGENTTY_CNB
 *    EEC_CHEMAGENTTY_CNC
 *    EEC_CHEMAGENTTY_CNS
 *    EEC_CHEMAGENTTY_CS
 *    EEC_CHEMAGENTTY_CX
 *    EEC_CHEMAGENTTY_DA
 *    EEC_CHEMAGENTTY_DC
 *    EEC_CHEMAGENTTY_DGA
 *    EEC_CHEMAGENTTY_DGB
 *    EEC_CHEMAGENTTY_DGD
 *    EEC_CHEMAGENTTY_DM
 *    EEC_CHEMAGENTTY_DVX
 *    EEC_CHEMAGENTTY_ED
 *    EEC_CHEMAGENTTY_FOG_OIL
 *    EEC_CHEMAGENTTY_GA
 *    EEC_CHEMAGENTTY_GB
 *    EEC_CHEMAGENTTY_GD
 *    EEC_CHEMAGENTTY_GF
 *    EEC_CHEMAGENTTY_HD
 *    EEC_CHEMAGENTTY_HL
 *    EEC_CHEMAGENTTY_HN_1
 *    EEC_CHEMAGENTTY_HN_2
 *    EEC_CHEMAGENTTY_HN_3
 *    EEC_CHEMAGENTTY_HT
 *    EEC_CHEMAGENTTY_HYDROCHLORIC_ACID
 *    EEC_CHEMAGENTTY_HYDROGEN_CYANIDE
 *    EEC_CHEMAGENTTY_IR_DEFEATING
 *    EEC_CHEMAGENTTY_L
 *    EEC_CHEMAGENTTY_M
 *    EEC_CHEMAGENTTY_MD
 *    EEC_CHEMAGENTTY_OIL
 *    EEC_CHEMAGENTTY_PD
 *    EEC_CHEMAGENTTY_PWP_PHOSPHORUS
 *    EEC_CHEMAGENTTY_Q
 *    EEC_CHEMAGENTTY_RED_PHOSPHORUS
 *    EEC_CHEMAGENTTY_TGA
 *    EEC_CHEMAGENTTY_TGB
 *    EEC_CHEMAGENTTY_TGD
 *    EEC_CHEMAGENTTY_TVX
 *    EEC_CHEMAGENTTY_TYPE_III_IR
 *    EEC_CHEMAGENTTY_VE
 *    EEC_CHEMAGENTTY_VX
 *    EEC_CHEMAGENTTY_WHITE_PHOSPHORUS
 *
 * Group Membership: MATERIAL
 */
#define EAC_CHEMICAL_AGENT_TYPE ((EDCS_Attribute_Code)226)

/*
 * Definition:
 *     The designation of a <NON_EMPTY_SET> of closely related Christian
 *     religious denominations, often ones which were at one time part of a
 *     single movement but are now separate religious denominations; the
 *     Christianity denominational family.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CHRSDENOMFAM_ADVENTIST
 *    EEC_CHRSDENOMFAM_AFRICAN_INDIGENOUS
 *    EEC_CHRSDENOMFAM_ANGLICAN
 *    EEC_CHRSDENOMFAM_APOSTOLIC
 *    EEC_CHRSDENOMFAM_BAPTIST
 *    EEC_CHRSDENOMFAM_CATHOLICISM
 *    EEC_CHRSDENOMFAM_CHRISTIAN_SCIENCE
 *    EEC_CHRSDENOMFAM_CHURCH_OF_CHRIST
 *    EEC_CHRSDENOMFAM_FRIENDS
 *    EEC_CHRSDENOMFAM_JEHOVAHS_WITNESS
 *    EEC_CHRSDENOMFAM_LATTER_DAY_SAINTS
 *    EEC_CHRSDENOMFAM_LUTHERAN
 *    EEC_CHRSDENOMFAM_MENNONITE
 *    EEC_CHRSDENOMFAM_METHODIST
 *    EEC_CHRSDENOMFAM_ORTHODOX
 *    EEC_CHRSDENOMFAM_PENTECOSTALISM
 *    EEC_CHRSDENOMFAM_PRESBYTERIANISM
 *    EEC_CHRSDENOMFAM_PROTESTANTISM
 *    EEC_CHRSDENOMFAM_UNAFFILIATED
 *
 * Group Membership: RELIGION
 */
#define EAC_CHRISTIANITY_DENOMINATIONAL_FAMILY ((EDCS_Attribute_Code)227)

/*
 * Definition:
 *     A character string representing an <OBJECT>; the classification name.
 *     EXAMPLES Grammalogue, index number, order number, classification
 *     number.
 *
 * Value Type: STRING
 *
 * Group Membership: ABSTRACT_OBJECT, IDENTIFICATION
 */
#define EAC_CLASSIFICATION_NAME ((EDCS_Attribute_Code)228)

/*
 * Definition:
 *     An indication that underground clay drainage <PIPE>s are present,
 *     usually in agricultural <REGION>s.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: AGRICULTURE, INFRASTRUCTURE
 */
#define EAC_CLAY_DRAINAGE_PIPES_PRESENT ((EDCS_Attribute_Code)229)

/*
 * Definition:
 *     The vertical displacement of a <CLOUD_BASE> from a <SURFACE_DATUM>
 *     identified by an <<ATM_VERTICAL_REFERENCE>>; the cloud base level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_CLOUD_BASE_LEVEL ((EDCS_Attribute_Code)230)

/*
 * Definition:
 *     The fraction of all lines of sight that are unhampered by <CLOUD>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_CLOUD_FREE_LINE_OF_SIGHT ((EDCS_Attribute_Code)231)

/*
 * Definition:
 *     The liquid <WATER> content of a unit <<VOLUME>> of a <CLOUD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_CLOUD_LIQUID_WATER_CONTENT ((EDCS_Attribute_Code)232)

/*
 * Definition:
 *     The phase (liquid/solid disposition) of the water content of a <CLOUD>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CLDPHAS_LIQUID
 *    EEC_CLDPHAS_MIXED
 *    EEC_CLDPHAS_SOLID
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_CLOUD_PHASE ((EDCS_Attribute_Code)233)

/*
 * Definition:
 *     The type of <CLOUD> that comprises a sky cover layer.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CLDSKYCVRLAYTY_CIRRUS
 *    EEC_CLDSKYCVRLAYTY_CIRROCUMULUS
 *    EEC_CLDSKYCVRLAYTY_CIRROSTRATUS
 *    EEC_CLDSKYCVRLAYTY_ALTOCUMULUS
 *    EEC_CLDSKYCVRLAYTY_ALTOSTRATUS
 *    EEC_CLDSKYCVRLAYTY_NIMBOSTRATUS
 *    EEC_CLDSKYCVRLAYTY_STRATOCUMULUS
 *    EEC_CLDSKYCVRLAYTY_STRATUS
 *    EEC_CLDSKYCVRLAYTY_CUMULUS
 *    EEC_CLDSKYCVRLAYTY_CUMULONIMBUS
 *    EEC_CLDSKYCVRLAYTY_NOT_VISIBLE
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_CLOUD_SKY_COVER_LAYER_TYPE ((EDCS_Attribute_Code)234)

/*
 * Definition:
 *     The vertical distance between a <CLOUD_BASE> and the corresponding
 *     <CLOUD_TOP>; the cloud thickness.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, DIMENSION
 */
#define EAC_CLOUD_THICKNESS ((EDCS_Attribute_Code)235)

/*
 * Definition:
 *     The vertical displacement of a <CLOUD_TOP> from a <SURFACE_DATUM>
 *     identified by an <<ATM_VERTICAL_REFERENCE>>; the cloud top level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_CLOUD_TOP_LEVEL ((EDCS_Attribute_Code)236)

/*
 * Definition:
 *     The <<TEMPERATURE>> of a <CLOUD_TOP> or of the <AIR> near that level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, TEMPERATURE
 */
#define EAC_CLOUD_TOP_TEMPERATURE ((EDCS_Attribute_Code)237)

/*
 * Definition:
 *     The ratio of the <<MASS>> of the liquid <WATER> to the <<MASS>> of dry
 *     <AIR> in a <CLOUD>; the cloud water mixing ratio.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_CLOUD_WATER_MIXING_RATIO ((EDCS_Attribute_Code)238)

/*
 * Definition:
 *     The intensity of colour of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_COLRINT_DARK
 *    EEC_COLRINT_LIGHT
 *
 * Group Membership: COLOUR
 */
#define EAC_COLOUR_INTENSITY ((EDCS_Attribute_Code)239)

/*
 * Definition:
 *     The apparent colouration of an <OBJECT> when viewed in daylight; where
 *     more than a single colour is present, no specific pattern or
 *     regularity of distribution or colour predominance is presumed.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_COLOURATION_AMBER
 *    EEC_COLOURATION_BLACK
 *    EEC_COLOURATION_BLACK_BLUE_GREY
 *    EEC_COLOURATION_BLACK_BROWN
 *    EEC_COLOURATION_BLACK_BROWN_GREY
 *    EEC_COLOURATION_BLACK_GREEN
 *    EEC_COLOURATION_BLACK_GREEN_YELLOW
 *    EEC_COLOURATION_BLACK_GREY
 *    EEC_COLOURATION_BLACK_GREY_TAN
 *    EEC_COLOURATION_BLACK_GREY_WHITE
 *    EEC_COLOURATION_BLACK_RED
 *    EEC_COLOURATION_BLACK_RED_WHITE
 *    EEC_COLOURATION_BLACK_SEAGREEN_TAN
 *    EEC_COLOURATION_BLACK_TAN
 *    EEC_COLOURATION_BLACK_TAN_WHITE
 *    EEC_COLOURATION_BLACK_WHITE
 *    EEC_COLOURATION_BLACK_YELLOW
 *    EEC_COLOURATION_BLUE
 *    EEC_COLOURATION_BLUE_GREEN
 *    EEC_COLOURATION_BLUE_TAN
 *    EEC_COLOURATION_BLUE_TAN_WHITE
 *    EEC_COLOURATION_BLUE_WHITE
 *    EEC_COLOURATION_BLUE_YELLOW
 *    EEC_COLOURATION_BRICKRED
 *    EEC_COLOURATION_BRICKRED_LIGHTPURPLE
 *    EEC_COLOURATION_BRICKRED_PURPLE_WHITE
 *    EEC_COLOURATION_BROWN
 *    EEC_COLOURATION_BROWN_GREEN
 *    EEC_COLOURATION_BROWN_GREY
 *    EEC_COLOURATION_BROWN_LIGHTPURPLE_YELLOW
 *    EEC_COLOURATION_BROWN_RED
 *    EEC_COLOURATION_BROWN_TAN
 *    EEC_COLOURATION_BROWN_YELLOW
 *    EEC_COLOURATION_CHARCOAL
 *    EEC_COLOURATION_CHOCOLATE
 *    EEC_COLOURATION_DARKBROWN
 *    EEC_COLOURATION_DARKCOLOURED
 *    EEC_COLOURATION_DARKGREEN
 *    EEC_COLOURATION_DARKGREY
 *    EEC_COLOURATION_DARKPURPLE
 *    EEC_COLOURATION_DARKRED
 *    EEC_COLOURATION_DARKYELLOW_TAN
 *    EEC_COLOURATION_GOLD_GREY
 *    EEC_COLOURATION_GREEN
 *    EEC_COLOURATION_GREEN_GREY
 *    EEC_COLOURATION_GREEN_RED
 *    EEC_COLOURATION_GREEN_RED_WHITE
 *    EEC_COLOURATION_GREEN_TAN
 *    EEC_COLOURATION_GREEN_WHITE
 *    EEC_COLOURATION_GREEN_YELLOW
 *    EEC_COLOURATION_GREY
 *    EEC_COLOURATION_GREY_RED
 *    EEC_COLOURATION_GREY_TAN
 *    EEC_COLOURATION_GREY_WHITE
 *    EEC_COLOURATION_GREY_YELLOW
 *    EEC_COLOURATION_LIGHTBLUE
 *    EEC_COLOURATION_LIGHTBROWN
 *    EEC_COLOURATION_LIGHTCOLOURED
 *    EEC_COLOURATION_LIGHTGREEN
 *    EEC_COLOURATION_LIGHTGREY
 *    EEC_COLOURATION_LIGHTPURPLE
 *    EEC_COLOURATION_LIGHTRED
 *    EEC_COLOURATION_LIGHTYELLOW
 *    EEC_COLOURATION_MAGENTA
 *    EEC_COLOURATION_MAROON
 *    EEC_COLOURATION_MUSTARD
 *    EEC_COLOURATION_NO_COLOUR
 *    EEC_COLOURATION_OLIVE
 *    EEC_COLOURATION_ORANGE
 *    EEC_COLOURATION_ORANGE_WHITE
 *    EEC_COLOURATION_PEACH
 *    EEC_COLOURATION_PINK
 *    EEC_COLOURATION_RED
 *    EEC_COLOURATION_RED_TAN
 *    EEC_COLOURATION_RED_TAN_WHITE
 *    EEC_COLOURATION_RED_WHITE
 *    EEC_COLOURATION_RED_WHITE_YELLOW
 *    EEC_COLOURATION_RED_YELLOW
 *    EEC_COLOURATION_RUST
 *    EEC_COLOURATION_SILVER
 *    EEC_COLOURATION_TAN
 *    EEC_COLOURATION_WHITE
 *    EEC_COLOURATION_WHITE_YELLOW
 *    EEC_COLOURATION_YELLOW
 *
 * Group Membership: ABSTRACT_OBJECT, COLOUR
 */
#define EAC_COLOURATION ((EDCS_Attribute_Code)240)

/*
 * Definition:
 *     The textual description of unique aspects of the colouration of an
 *     <OBJECT>; colouration information.
 *
 * Value Type: STRING
 *
 * Group Membership: COLOUR
 */
#define EAC_COLOURATION_INFORMATION ((EDCS_Attribute_Code)241)

/*
 * Definition:
 *     The operating function of a <COMBAT_SUPPORT_VESSEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CMBTSUPVESFN_COMBAT_STORES
 *    EEC_CMBTSUPVESFN_COMBAT_SUPPORT
 *    EEC_CMBTSUPVESFN_COMMAND
 *    EEC_CMBTSUPVESFN_CRUISER
 *    EEC_CMBTSUPVESFN_MUNITION_SUPPLY
 *    EEC_CMBTSUPVESFN_SURVEILLANCE
 *    EEC_CMBTSUPVESFN_TENDER
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_COMBAT_SUPPORT_VESSEL_FUNCTION ((EDCS_Attribute_Code)242)

/*
 * Definition:
 *     The type of a <COMBATANT_VESSEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CMBTVESTY_AIRCRAFT_CARRIER
 *    EEC_CMBTVESTY_BATTLESHIP
 *    EEC_CMBTVESTY_DESTROYER
 *    EEC_CMBTVESTY_FRIGATE
 *    EEC_CMBTVESTY_GUIDED_MISSILE_CRUISER
 *    EEC_CMBTVESTY_GUIDED_MISSILE_DESTROYER
 *    EEC_CMBTVESTY_GUIDED_MISSILE_FRIGATE
 *    EEC_CMBTVESTY_MINE_COUNTERMEASURE
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_COMBATANT_VESSEL_TYPE ((EDCS_Attribute_Code)243)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the production rate of visible flame induced by
 *     combustion in an <OBJECT>. Zero means no production at all and one
 *     means maximum production.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_COMBUSTION_INDUCED_FLAME_RATE ((EDCS_Attribute_Code)244)

/*
 * Definition:
 *     The state of combustion of an <OBJECT> and/or its contents.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CMBSTSTATE_NOT_BURNING
 *    EEC_CMBSTSTATE_SMOULDERING
 *    EEC_CMBSTSTATE_SMALL_FIRE
 *    EEC_CMBSTSTATE_MEDIUM_FIRE
 *    EEC_CMBSTSTATE_LARGE_FIRE
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_COMBUSTION_STATE ((EDCS_Attribute_Code)245)

/*
 * Definition:
 *     The type or design series of a <COMMERCIAL_WINGED_AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_COMWNGARCRFTY_AIRBUS_A300_SERIES
 *    EEC_COMWNGARCRFTY_AIRBUS_A340_SERIES
 *    EEC_COMWNGARCRFTY_AIRBUS_A400_SERIES
 *    EEC_COMWNGARCRFTY_B717_SERIES
 *    EEC_COMWNGARCRFTY_B727_SERIES
 *    EEC_COMWNGARCRFTY_B737_SERIES
 *    EEC_COMWNGARCRFTY_B747_SERIES
 *    EEC_COMWNGARCRFTY_B757_SERIES
 *    EEC_COMWNGARCRFTY_B767_SERIES
 *    EEC_COMWNGARCRFTY_B777_SERIES
 *    EEC_COMWNGARCRFTY_DC8_SERIES
 *    EEC_COMWNGARCRFTY_DC9_SERIES
 *    EEC_COMWNGARCRFTY_MD11_SERIES
 *    EEC_COMWNGARCRFTY_MD80_SERIES
 *    EEC_COMWNGARCRFTY_MD81_SERIES
 *    EEC_COMWNGARCRFTY_MD82_SERIES
 *    EEC_COMWNGARCRFTY_MD83_SERIES
 *    EEC_COMWNGARCRFTY_MD88_SERIES
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define EAC_COMMERCIAL_WINGED_AIRCRAFT_TYPE ((EDCS_Attribute_Code)246)

/*
 * Definition:
 *     The communication channel assigned by a controlling authority, often
 *     described by a <<FREQUENCY>>.
 *
 * Value Type: STRING
 *
 * Group Membership: ADMINISTRATION, COMMUNICATION, INFRASTRUCTURE
 */
#define EAC_COMMUNICATION_CHANNEL ((EDCS_Attribute_Code)247)

/*
 * Definition:
 *     The type of a communications <STRUCTURE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_COMMSTRTY_BEACON
 *    EEC_COMMSTRTY_CABLE_STATION
 *    EEC_COMMSTRTY_MICROWAVE_STATION
 *    EEC_COMMSTRTY_MONITORING_STATION
 *    EEC_COMMSTRTY_MULTIPLE_PRESENT
 *    EEC_COMMSTRTY_NAVIGATION_LIGHT
 *    EEC_COMMSTRTY_RADAR_STATION
 *    EEC_COMMSTRTY_RADIO_STATION
 *    EEC_COMMSTRTY_RADOME
 *    EEC_COMMSTRTY_REPEATER
 *    EEC_COMMSTRTY_RESEARCH_STATION
 *    EEC_COMMSTRTY_SATELLITE_GROUND_STATION
 *    EEC_COMMSTRTY_TELEVISION_STATION
 *
 * Group Membership: COMMUNICATION, INFRASTRUCTURE
 */
#define EAC_COMMUNICATION_STRUCTURE_TYPE ((EDCS_Attribute_Code)248)

/*
 * Definition:
 *     The numeric identifier of an <OBJECT> that either consists of
 *     <COMPONENT>s or is itself a <COMPONENT> of another <OBJECT>; complex
 *     component identifier. Such an identifier is used for relating
 *     <OBJECT>s to each other.
 *
 * Value Type: INDEX
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_COMPLEX_COMPONENT_IDENTIFIER ((EDCS_Attribute_Code)249)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of complete concealment of an <OBJECT>. Zero means
 *     unconcealed and one means completely concealed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_CONCEALMENT_FRACTION ((EDCS_Attribute_Code)250)

/*
 * Definition:
 *     The type of conspicuousness of an <OBJECT>. Conspicuous means the
 *     <OBJECT> is easily identifiable and plainly visible under varying
 *     conditions from <HARBOUR>s, approach <WATER_CHANNEL>s, or offshore
 *     because of its size, shape, <<HEIGHT_ABOVE_SURFACE_LEVEL>>, colour,
 *     or composition.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CONSPIC_FROM_AIR
 *    EEC_CONSPIC_FROM_LAND
 *    EEC_CONSPIC_FROM_SEA
 *    EEC_CONSPIC_GENERALLY
 *    EEC_CONSPIC_INCONSPICUOUS
 *    EEC_CONSPIC_NOT_RADAR
 *    EEC_CONSPIC_NOT_VISIBLE_FROM_SEA
 *    EEC_CONSPIC_RADAR_FROM_SEA
 *    EEC_CONSPIC_RADAR_WITH_REFLECTOR
 *    EEC_CONSPIC_VISIBLE_FROM_SEA
 *
 * Group Membership: ABSTRACT_OBJECT, HARBOUR_AND_PORT, LIGHTING_AND_VISIBILITY
 */
#define EAC_CONSPICUOUSNESS ((EDCS_Attribute_Code)251)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of construction completion of a <MAN_MADE_OBJECT>. Zero
 *     means construction has not yet begun and one means construction is
 *     complete.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_CONSTRUCTION_COMPLETION_FRACTION ((EDCS_Attribute_Code)252)

/*
 * Definition:
 *     The type of a <CONTOUR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CNTURTY_BATHYMETRY
 *    EEC_CNTURTY_DEPRESSION
 *    EEC_CNTURTY_ELEVATION
 *
 * Group Membership: LOCATION
 */
#define EAC_CONTOUR_TYPE ((EDCS_Attribute_Code)253)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of the bottom of a layer in an <ATMOSPHERE> where
 *     contrail formation is probable.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_CONTRAIL_LAYER_BASE_ALTITUDE ((EDCS_Attribute_Code)254)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of the top of a layer in an <ATMOSPHERE> where
 *     contrail formation is probable.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_CONTRAIL_LAYER_TOP_ALTITUDE ((EDCS_Attribute_Code)255)

/*
 * Definition:
 *     The persistence status of a contrail.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CONTRAILPERS_NONE_PRESENT
 *    EEC_CONTRAILPERS_NOT_PERSISTENT
 *    EEC_CONTRAILPERS_PERSISTENT
 *
 * Group Membership: AIR_TRNSP, AIRBORNE_PARTICLE, ATMOSPHERE, ICE, TRNSP
 */
#define EAC_CONTRAIL_PERSISTENCE ((EDCS_Attribute_Code)256)

/*
 * Definition:
 *     The state of a <CONTROL_PANEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CTRLPANELSTATE_POWER_OFF
 *    EEC_CTRLPANELSTATE_POWER_ON
 *    EEC_CTRLPANELSTATE_STAND_BY
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define EAC_CONTROL_PANEL_STATE ((EDCS_Attribute_Code)257)

/*
 * Definition:
 *     The kind of <EQUIPMENT> controlled by a <CONTROL_PANEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CTRLPANELTY_ELECTRICAL_SERVICE
 *    EEC_CTRLPANELTY_ESCALATOR
 *    EEC_CTRLPANELTY_HVAC
 *    EEC_CTRLPANELTY_LIFT
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define EAC_CONTROL_PANEL_TYPE ((EDCS_Attribute_Code)258)

/*
 * Definition:
 *     An indication that a <FACILITY> is controlled.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_CONTROLLED ((EDCS_Attribute_Code)259)

/*
 * Definition:
 *     The level or type of an organization or authority responsible for an
 *     <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CTRLAUTH_CITY
 *    EEC_CTRLAUTH_COMMUNAL
 *    EEC_CTRLAUTH_FEDERAL
 *    EEC_CTRLAUTH_INSULAR
 *    EEC_CTRLAUTH_INTERNATIONAL
 *    EEC_CTRLAUTH_INTERSTATE
 *    EEC_CTRLAUTH_JOINT
 *    EEC_CTRLAUTH_MILITARY
 *    EEC_CTRLAUTH_MILITARY_DISTRICT
 *    EEC_CTRLAUTH_NATIONAL
 *    EEC_CTRLAUTH_NON_MILITARY
 *    EEC_CTRLAUTH_PRIVATE
 *    EEC_CTRLAUTH_PROVINCIAL
 *    EEC_CTRLAUTH_REGIONAL
 *    EEC_CTRLAUTH_STATE
 *    EEC_CTRLAUTH_TRIBAL
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_CONTROLLING_AUTHORITY ((EDCS_Attribute_Code)260)

/*
 * Definition:
 *     The ratio of convective heat flux density through a surface <BOUNDARY>
 *     to the gradient of <<TEMPERATURE>> across that <BOUNDARY>; the
 *     convection coefficient.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: COEFFICIENT_HEAT_TRANSFER
 *
 * Group Membership: DEMARCATION, RATE_OR_RATIO, TEMPERATURE
 */
#define EAC_CONVECTION_COEFFICIENT ((EDCS_Attribute_Code)261)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the sky that is covered by convective (cumuliform)
 *     <CLOUD>s. Zero means no convective <CLOUD>s are present and one means
 *     the sky is completely covered by convective <CLOUD>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_CONVECTIVE_CLOUD_LAYER ((EDCS_Attribute_Code)262)

/*
 * Definition:
 *     The component of <<ACCUM_PRECIP_DENSITY>> caused by convective
 *     <PRECIPITATION>. Convective <PRECIPITATION> consists of <PARTICLE>s
 *     forming in the active updraft of a cumulonimbus <CLOUD>, growing
 *     primarily by the collection of droplets through coalescence and/or
 *     riming, and falling out not far from their originating updraft.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_CONVECTIVE_PRECIPITATION_DENSITY ((EDCS_Attribute_Code)263)

/*
 * Definition:
 *     The number of occurrences of a separately specified type of <OBJECT>;
 *     the count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_COUNT ((EDCS_Attribute_Code)264)

/*
 * Definition:
 *     The value set of a formatted <<COUNTRY_IDENTIFIER>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CTRYIDVALSET_UNCONSTRAINED
 *    EEC_CTRYIDVALSET_ISO_2_CHAR_CTRY_CODE
 *    EEC_CTRYIDVALSET_ISO_3_CHAR_CTRY_CODE
 *    EEC_CTRYIDVALSET_ISO_ENGLISH_CTRY_NAME
 *    EEC_CTRYIDVALSET_ISO_FRENCH_CTRY_NAME
 *    EEC_CTRYIDVALSET_UN_CTRY_NAME
 *    EEC_CTRYIDVALSET_US_FIPS_CTRY_CODE
 *    EEC_CTRYIDVALSET_US_FIPS_CTRY_NAME
 *    EEC_CTRYIDVALSET_US_FIPS_PRIN_ADMIN_DIVISION_CODE
 *
 * Group Membership: ADMINISTRATION, IDENTIFICATION
 */
#define EAC_COUNTRY_ID_VALUE_SET ((EDCS_Attribute_Code)265)

/*
 * Definition:
 *     An identifier of a country. The format and values of the identifier
 *     are specified by a <<COUNTRY_ID_VALUE_SET>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ADMINISTRATION, IDENTIFICATION
 */
#define EAC_COUNTRY_IDENTIFIER ((EDCS_Attribute_Code)266)

/*
 * Definition:
 *     An indication that a <COMPONENT> of a <WATERCOURSE> is completely
 *     covered over and connects to uncovered <WATERCOURSE>s at each end; a
 *     covered drain.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, INFRASTRUCTURE, SHELTER
 */
#define EAC_COVERED_DRAIN ((EDCS_Attribute_Code)267)

/*
 * Definition:
 *     The <<LENGTH>> of the covered portion of a <WATERCOURSE>; the covered
 *     drain length.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, HYDROGRAPHIC_ARTEFACT, INFRASTRUCTURE, SHELTER
 */
#define EAC_COVERED_DRAIN_LENGTH ((EDCS_Attribute_Code)268)

/*
 * Definition:
 *     The type of mobility of a <CRANE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CRANEMOBTY_FIXED
 *    EEC_CRANEMOBTY_FLOATING
 *    EEC_CRANEMOBTY_TRAVELING
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_CRANE_MOBILITY_TYPE ((EDCS_Attribute_Code)269)

/*
 * Definition:
 *     The type of a <CRANE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CRANETY_BRIDGE
 *    EEC_CRANETY_CONTAINER
 *    EEC_CRANETY_FIXED
 *    EEC_CRANETY_FLOATING
 *    EEC_CRANETY_ROTATING
 *    EEC_CRANETY_TRAVELING
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_CRANE_TYPE ((EDCS_Attribute_Code)270)

/*
 * Definition:
 *     The altitude of the E layer of free electrons in the <IONOSPHERE> of
 *     the <EARTH>; the critical E layer altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, LOCATION, SPACE
 */
#define EAC_CRITICAL_LAYER_ALTITUDE_E ((EDCS_Attribute_Code)271)

/*
 * Definition:
 *     The altitude of the F[sub(1)] layer of free electrons in the
 *     <IONOSPHERE> of the <EARTH>; the critical F[sub(1)] layer altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, LOCATION, SPACE
 */
#define EAC_CRITICAL_LAYER_ALTITUDE_F1 ((EDCS_Attribute_Code)272)

/*
 * Definition:
 *     The altitude of the F[sub(2)] layer of free electrons in the
 *     <IONOSPHERE> of the <EARTH>; the critical F[sub(2)] layer altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, LOCATION, SPACE
 */
#define EAC_CRITICAL_LAYER_ALTITUDE_F2 ((EDCS_Attribute_Code)273)

/*
 * Definition:
 *     The minimum radio <<FREQUENCY>> that begins to be reflected by the E
 *     layer of free electrons in the <IONOSPHERE> of the <EARTH>; the
 *     critical E layer frequency.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, SPACE
 */
#define EAC_CRITICAL_LAYER_FREQUENCY_E ((EDCS_Attribute_Code)274)

/*
 * Definition:
 *     The minimum radio <<FREQUENCY>> that begins to be reflected by the
 *     F[sub(1)] layer of free electrons in the <IONOSPHERE> of the <EARTH>;
 *     the critical F[sub(1)] layer frequency.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, SPACE
 */
#define EAC_CRITICAL_LAYER_FREQUENCY_F1 ((EDCS_Attribute_Code)275)

/*
 * Definition:
 *     The minimum radio <<FREQUENCY>> that begins to be reflected by the
 *     F[sub(2)] layer of free electrons in the <IONOSPHERE> of the <EARTH>;
 *     the critical F[sub(2)] layer frequency.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, SPACE
 */
#define EAC_CRITICAL_LAYER_FREQUENCY_F2 ((EDCS_Attribute_Code)276)

/*
 * Definition:
 *     The method of traffic control where <ROAD>s cross.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CROSSINGCTRL_NO_CONTROL
 *    EEC_CROSSINGCTRL_SIGNAL_DEVICE
 *    EEC_CROSSINGCTRL_STOP_SIGN
 *    EEC_CROSSINGCTRL_YIELD_SIGN
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_CROSSING_CONTROL ((EDCS_Attribute_Code)277)

/*
 * Definition:
 *     The maximum diameter of the crown of a <SHRUB> or <TREE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIVING_ORGANISM, PLANT
 */
#define EAC_CROWN_DIAMETER ((EDCS_Attribute_Code)278)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of <LAND> that is covered by <BUILDING>s and other cultural
 *     <OBJECT>s; the cultural object density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_CULTURAL_OBJECT_DENSITY ((EDCS_Attribute_Code)279)

/*
 * Definition:
 *     The type of a <CULVERT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CULVTY_BOX_LOAD_BEARING
 *    EEC_CULVTY_BOX_SOIL_BACK_FILLED
 *    EEC_CULVTY_REG_SOIL_BACK_FILLED
 *
 * Group Membership: INFRASTRUCTURE, LAND_TRNSP, TRNSP
 */
#define EAC_CULVERT_TYPE ((EDCS_Attribute_Code)280)

/*
 * Definition:
 *     The total cumulative <<LENGTH>> of <RAILWAY_TRACK> contained within a
 *     delineated <REGION> exclusive of the branch or main trunk lines
 *     running into and/or out of the <REGION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_CUMULATIVE_TRACK_LENGTH ((EDCS_Attribute_Code)281)

/*
 * Definition:
 *     The calendar <<TIME_QUANTITY>> in which data about an <AERODROME> or
 *     <RUNWAY> was added to airport maintenance records or last revised;
 *     the cycle date. Formatted in a Basic Latin string as characters [1-4]
 *     indicating the Gregorian year, and characters [5-6] indicating the 28
 *     day cycle in which the addition or change was made. EXAMPLE "200201"
 *     indicating the first cycle in the year 2002.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: AIR_TRNSP, ALGORITHM_RELATED, TIME, TRNSP
 */
#define EAC_CYCLE_DATE ((EDCS_Attribute_Code)282)

/*
 * Definition:
 *     The sequential number of the peak <TIDE> for a day; the daily tide
 *     index. The value starts at 1 for the first peak <TIDE> for a day and
 *     increases.
 *
 * Value Type: INTEGER
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_DAILY_TIDE_INDEX ((EDCS_Attribute_Code)283)

/*
 * Definition:
 *     The type of face of a <DAM>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DAMFACETY_SLOPED
 *    EEC_DAMFACETY_VERTICAL
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, INFRASTRUCTURE
 */
#define EAC_DAM_FACE_TYPE ((EDCS_Attribute_Code)284)

/*
 * Definition:
 *     The amount of ordinance in equivalent <<MASS>> of TNT required to
 *     cause distinguishable damage to a <STRUCTURE>; the damage weight.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: MILITARY_SCIENCE, SUPPORT_STRUCTURE
 */
#define EAC_DAMAGE_WEIGHT ((EDCS_Attribute_Code)285)

/*
 * Definition:
 *     Criteria describing the collection of data.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DATACOLLCRIT_COLLECTED
 *    EEC_DATACOLLCRIT_DERIVED
 *    EEC_DATACOLLCRIT_DIFFERENT_HEIGHT_THRESHOLD
 *    EEC_DATACOLLCRIT_LOW_DATA_COLLECTION_CRITERIA
 *    EEC_DATACOLLCRIT_NO_AVAILABLE_IMAGERY
 *    EEC_DATACOLLCRIT_NO_AVAILABLE_MAP_SOURCE
 *    EEC_DATACOLLCRIT_NO_SUITABLE_IMAGERY
 *    EEC_DATACOLLCRIT_NOT_COLLECTED
 *    EEC_DATACOLLCRIT_NOT_REQUESTED
 *    EEC_DATACOLLCRIT_NOT_REQUIRED
 *    EEC_DATACOLLCRIT_TOO_ROUGH_TO_COLLECT
 *
 * Group Membership: ALGORITHM_RELATED, SURVEY
 */
#define EAC_DATA_COLLECTION_CRITERIA ((EDCS_Attribute_Code)286)

/*
 * Definition:
 *     The format of a date.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DATEFMT_CALENDAR_DATE
 *    EEC_DATEFMT_YY
 *    EEC_DATEFMT_YYYY
 *    EEC_DATEFMT_YYYY_DDD
 *    EEC_DATEFMT_YYYY_MM
 *    EEC_DATEFMT_YYYY_MM_DD
 *    EEC_DATEFMT_YYYY_WWW
 *    EEC_DATEFMT_YYYY_WWW_D
 *    EEC_DATEFMT_YYYYDDD
 *    EEC_DATEFMT_YYYYMMDD
 *    EEC_DATEFMT_YYYYWWW
 *    EEC_DATEFMT_YYYYWWWD
 *    EEC_DATEFMT_DD
 *    EEC_DATEFMT_DDD
 *    EEC_DATEFMT_ISO
 *    EEC_DATEFMT_MM
 *    EEC_DATEFMT_MM_DD
 *    EEC_DATEFMT_MMDD
 *    EEC_DATEFMT_ORDINAL_DATE
 *    EEC_DATEFMT_W_D
 *    EEC_DATEFMT_WEEK_DATE
 *    EEC_DATEFMT_WWW
 *    EEC_DATEFMT_WWW_D
 *    EEC_DATEFMT_WWWD
 *    EEC_DATEFMT_Y_WWW
 *    EEC_DATEFMT_Y_WWW_D
 *    EEC_DATEFMT_YWWW
 *    EEC_DATEFMT_YWWWD
 *    EEC_DATEFMT_YY_TRUNCATED
 *    EEC_DATEFMT_YY_DDD
 *    EEC_DATEFMT_YY_MM
 *    EEC_DATEFMT_YY_MM_DD
 *    EEC_DATEFMT_YY_WWW
 *    EEC_DATEFMT_YY_WWW_D
 *    EEC_DATEFMT_YYDDD
 *    EEC_DATEFMT_YYMM
 *    EEC_DATEFMT_YYMMDD
 *    EEC_DATEFMT_YYWWW
 *    EEC_DATEFMT_YYWWWD
 *    EEC_DATEFMT_YYY
 *    EEC_DATEFMT_YYYYY
 *    EEC_DATEFMT_YYYYY_DDD
 *    EEC_DATEFMT_YYYYY_MM
 *    EEC_DATEFMT_YYYYY_MM_DD
 *    EEC_DATEFMT_YYYYYDDD
 *    EEC_DATEFMT_YYYYYMMDD
 *
 * Group Membership: TIME
 */
#define EAC_DATE_FORMAT ((EDCS_Attribute_Code)287)

/*
 * Definition:
 *     The format of a date and time of the day.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DATETIMEFMT_ISO
 *    EEC_DATETIMEFMT_YYYYMMDDTHHMMSS
 *    EEC_DATETIMEFMT_YYYY_MM_DDTHH_MM_SS
 *    EEC_DATETIMEFMT_YYYYDDDTHHMMSS
 *    EEC_DATETIMEFMT_YYYY_DDDTHH_MM_SS
 *    EEC_DATETIMEFMT_YYYYWWWDTHHMMSS
 *    EEC_DATETIMEFMT_YYYY_WWW_DTHH_MM_SS
 *    EEC_DATETIMEFMT_REDUCED
 *
 * Group Membership: TIME
 */
#define EAC_DATE_TIME_FORMAT ((EDCS_Attribute_Code)288)

/*
 * Definition:
 *     The date and time, formatted as specified by <<DATE_TIME_FORMAT>>; a
 *     date time group.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TIME
 */
#define EAC_DATE_TIME_GROUP ((EDCS_Attribute_Code)289)

/*
 * Definition:
 *     The ordinal index of a day within the year, starting with 1 on the
 *     1^(st) of January.
 *
 * Value Type: COUNT
 *
 * Group Membership: TIME
 */
#define EAC_DAY_WITHIN_YEAR ((EDCS_Attribute_Code)290)

/*
 * Definition:
 *     The <<DEPTH>> at which the <<SPEED>> of propagation of a compressional
 *     wave achieves its minimum value in a <DEEP_SOUND_CHANNEL>; the deep
 *     sound channel axis depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROLOGY, LOCATION, WATERBODY_STATE
 */
#define EAC_DEEP_SOUND_CHANNEL_AXIS_DEPTH ((EDCS_Attribute_Code)291)

/*
 * Definition:
 *     The topmost of the two <<DEPTH>>s of equal maximum <<SPEED>> of
 *     propagation of compressional waves in a <DEEP_SOUND_CHANNEL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROLOGY, LOCATION, WATERBODY_STATE
 */
#define EAC_DEEP_SOUND_CHANNEL_TOP_DEPTH ((EDCS_Attribute_Code)292)

/*
 * Definition:
 *     The number of <DEFENSIVE_POSITION>s within a delineated <REGION>; the
 *     defensive position count.
 *
 * Value Type: COUNT
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_DEFENSIVE_POSITION_COUNT ((EDCS_Attribute_Code)293)

/*
 * Definition:
 *     The type of a <DEFENSIVE_POSITION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DEFPOSTY_DELIB_FULL_HIDE_ARMOURED_TRACKED_FIGHTING_VEHICLE
 *    EEC_DEFPOSTY_DELIB_MORTAR_FULL_HIDE
 *    EEC_DEFPOSTY_DELIB_MORTAR_NO_FULL_HIDE
 *    EEC_DEFPOSTY_DELIB_NO_FULL_HIDE_ARMOURED_TRACKED_FIGHTING_VEHICLE
 *    EEC_DEFPOSTY_DELIB_PER_DEF_COVERED
 *    EEC_DEFPOSTY_DELIB_PER_DEF_NO_COVER
 *    EEC_DEFPOSTY_DELIB_VEH_DEF_FULL_HIDE
 *    EEC_DEFPOSTY_DELIB_VEH_DEF_NO_FULL_HIDE
 *    EEC_DEFPOSTY_HASTY_PER_DEF_POSITION
 *    EEC_DEFPOSTY_HASTY_VEH_DEF_POSITION
 *    EEC_DEFPOSTY_MACHINE_GUN_BUNKER
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_DEFENSIVE_POSITION_TYPE ((EDCS_Attribute_Code)294)

/*
 * Definition:
 *     An indication that knowledge of the delineation of an <OBJECT> is
 *     certain.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, DEMARCATION, SURVEY
 */
#define EAC_DELINEATION_CERTAIN ((EDCS_Attribute_Code)295)

/*
 * Definition:
 *     The <<PRESSURE_ALTITUDE>> corrected for deviations from the standard
 *     <ATMOSPHERE>; the density altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_DENSITY_ALTITUDE ((EDCS_Attribute_Code)296)

/*
 * Definition:
 *     The distance from a <SURFACE> down to a <LOCATION> or <SURFACE>;
 *     depth. The value is expressed as a positive number.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION, SURFACE
 */
#define EAC_DEPTH ((EDCS_Attribute_Code)297)

/*
 * Definition:
 *     The <<DEPTH>> measured from the highest point of an <OBJECT> at the
 *     level of the surrounding <SURFACE> to the lowest point of that
 *     <OBJECT> below the <SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION, SURFACE
 */
#define EAC_DEPTH_BELOW_SURFACE_LEVEL ((EDCS_Attribute_Code)298)

/*
 * Definition:
 *     The <<DEPTH>> from a <WATERBODY_FLOOR> down to a <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_DEPTH_BELOW_WATERBODY_FLOOR ((EDCS_Attribute_Code)299)

/*
 * Definition:
 *     The <<DEPTH>> of an <OBJECT> below a <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION
 */
#define EAC_DEPTH_BELOW_WATERBODY_SURFACE ((EDCS_Attribute_Code)300)

/*
 * Definition:
 *     The <<DEPTH>> from a <WATERBODY_SURFACE> to a <WATERBODY_FLOOR>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_DEPTH_OF_WATERBODY_FLOOR ((EDCS_Attribute_Code)301)

/*
 * Definition:
 *     The difference between an <<AIR_TEMPERATURE>> at a <LOCATION> and the
 *     <<DEW_POINT_TEMPERATURE>> at that <LOCATION>; the dew point
 *     depression.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_DEW_POINT_DEPRESSION ((EDCS_Attribute_Code)302)

/*
 * Definition:
 *     The error in a measurement of a <<DEW_POINT_TEMPERATURE>> that is
 *     introduced by uncertainties.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_DEW_POINT_ERROR ((EDCS_Attribute_Code)303)

/*
 * Definition:
 *     The historical (climatology) maximum difference between the
 *     <<DEW_POINT_TEMPERATURE>> at an initial time and the
 *     <<DEW_POINT_TEMPERATURE>> at an offset from that time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_DEW_POINT_MAXIMUM_DIFFERENCE_CLIMATOLOGY ((EDCS_Attribute_Code)304)

/*
 * Definition:
 *     The historical (climatology) minimum difference between the
 *     <<DEW_POINT_TEMPERATURE>> at an initial time and the
 *     <<DEW_POINT_TEMPERATURE>> at an offset from that time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_DEW_POINT_MINIMUM_DIFFERENCE_CLIMATOLOGY ((EDCS_Attribute_Code)305)

/*
 * Definition:
 *     The quality of a <<DEW_POINT_TEMPERATURE>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DEWPTQUAL_GOOD
 *    EEC_DEWPTQUAL_NO_CHECK
 *    EEC_DEWPTQUAL_SUSPECT
 *    EEC_DEWPTQUAL_ERR_CORRECTED
 *    EEC_DEWPTQUAL_ERR_CORRECTION_SUSPECT
 *    EEC_DEWPTQUAL_ERR
 *    EEC_DEWPTQUAL_MISS_SUBST
 *    EEC_DEWPTQUAL_MISS_SUBST_SUSPECT
 *    EEC_DEWPTQUAL_MISS
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_DEW_POINT_QUALITY ((EDCS_Attribute_Code)306)

/*
 * Definition:
 *     The <<TEMPERATURE>> to which a given parcel of <AIR> must be cooled at
 *     constant <<ATM_PRESSURE>> and water vapour content in order for
 *     saturation to occur; the dew point temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_DEW_POINT_TEMPERATURE ((EDCS_Attribute_Code)307)

/*
 * Definition:
 *     The correction to the <<DIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL>>,
 *     typically taken at 50 hertz.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_DIR_SHIPPING_NOISE_CORRECTION ((EDCS_Attribute_Code)308)

/*
 * Definition:
 *     In a volume of a <WATERBODY>, the directional shipping noise spectral
 *     power level, typically taken at 50 hertz.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_DIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL ((EDCS_Attribute_Code)309)

/*
 * Definition:
 *     The ratio, for a particular material <SURFACE> and unit solid angle
 *     about a particular incident <DIRECTION>, of the reflected
 *     <<RADIANCE>> into the hemisphere above that <SURFACE> to the incident
 *     <<RADIANCE>>. This quantity is also defined as the integral over the
 *     reflected hemisphere of the BRDF times the cosine of the angle
 *     between the surface normal and the reflection <DIRECTION> times the
 *     differential reflection solid angle. It is a function of the
 *     <<INCIDENCE_ZENITH_ANGLE_LOCAL>> and <<INCIDENCE_AZIMUTH_LOCAL>> of
 *     the incident <<RADIANCE>> and is spectral (a distribution function in
 *     <<WAVELENGTH>>); therefore the quantity is measured in terms of
 *     inverse <<WAVELENGTH>> bin size.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: INV_LENGTH
 *
 * Group Membership: ALGORITHM_RELATED, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, SURFACE
 */
#define EAC_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY ((EDCS_Attribute_Code)310)

/*
 * Definition:
 *     The type of a <DISPLAY_SIGN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DISPSIGNTY_ADVERTISING_BILLBOARD
 *    EEC_DISPSIGNTY_HIGHWAY
 *    EEC_DISPSIGNTY_SCOREBOARD
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_DISPLAY_SIGN_TYPE ((EDCS_Attribute_Code)311)

/*
 * Definition:
 *     An indication that a <TERRAIN_SURFACE_REGION> is dominated by
 *     culturally or naturally dissected <TERRAIN>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_DISSECTED_TERRAIN ((EDCS_Attribute_Code)312)

/*
 * Definition:
 *     The type of the dominant breaking <WATER_WAVE>s tripped by shoaling
 *     <WATER>; dependent on the nature of the <WATERBODY_FLOOR> and <BEACH>
 *     slope.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DOMBRKRTY_PLUNGING
 *    EEC_DOMBRKRTY_SPILLING
 *    EEC_DOMBRKRTY_SURGING
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define EAC_DOMINANT_BREAKER_TYPE ((EDCS_Attribute_Code)313)

/*
 * Definition:
 *     The type of <MATERIAL> and/or techniques used to construct a <DOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DOORCNSTCTTY_FIRE
 *    EEC_DOORCNSTCTTY_GLASS
 *    EEC_DOORCNSTCTTY_METAL_CLAD
 *    EEC_DOORCNSTCTTY_METAL_HOLLOW_CORE
 *    EEC_DOORCNSTCTTY_SOLID_METAL
 *    EEC_DOORCNSTCTTY_SOLID_WOOD
 *    EEC_DOORCNSTCTTY_WOOD_HOLLOW_CORE
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_DOOR_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)314)

/*
 * Definition:
 *     The method in which a <DOOR> opens.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DOOROPNMETH_DOUBLE_SWINGING
 *    EEC_DOOROPNMETH_DOWN
 *    EEC_DOOROPNMETH_LEFT
 *    EEC_DOOROPNMETH_RIGHT
 *    EEC_DOOROPNMETH_UP
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_DOOR_OPENING_METHOD ((EDCS_Attribute_Code)315)

/*
 * Definition:
 *     The type of a <DOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DOORTY_AUTOMATIC_HINGED
 *    EEC_DOORTY_AUTOMATIC_SLIDING
 *    EEC_DOORTY_BLAST_RESISTANT
 *    EEC_DOORTY_DOUBLE_LEAF
 *    EEC_DOORTY_DUTCH
 *    EEC_DOORTY_HINGED
 *    EEC_DOORTY_LIFT
 *    EEC_DOORTY_OVERHEAD
 *    EEC_DOORTY_POCKET
 *    EEC_DOORTY_REVOLVING
 *    EEC_DOORTY_ROLLING
 *    EEC_DOORTY_SINGLE_PANEL_SPRING
 *    EEC_DOORTY_SLIDING
 *    EEC_DOORTY_SLIDING_GARAGE
 *    EEC_DOORTY_TURNSTILE
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_DOOR_TYPE ((EDCS_Attribute_Code)316)

/*
 * Definition:
 *     The type of a <DRAGON_TEETH>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DRAGONTEETHTY_CONCRETE_BLOCK
 *    EEC_DRAGONTEETHTY_CONCRETE_TETRAHEDRON
 *    EEC_DRAGONTEETHTY_LOG_POST
 *    EEC_DRAGONTEETHTY_STEEL_HEDGEHOG
 *    EEC_DRAGONTEETHTY_STEEL_TETRAHEDRON
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_DRAGON_TEETH_TYPE ((EDCS_Attribute_Code)317)

/*
 * Definition:
 *     The method by which a <DROP_GATE> is closed.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DROPGATEMETH_OVERHEAD
 *    EEC_DROPGATEMETH_SIDE
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_DROP_GATE_METHOD ((EDCS_Attribute_Code)318)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the production rate of <DUST> at an <OBJECT> that has
 *     been induced by ground movement or surface <WIND>s. Zero means no
 *     production at all and one means maximum production.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_DUST_PRODUCTION_RATE ((EDCS_Attribute_Code)319)

/*
 * Definition:
 *     The type of a <DWELLING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DWELLTY_APARTMENT
 *    EEC_DWELLTY_COTTAGE
 *    EEC_DWELLTY_DORMITORY
 *    EEC_DWELLTY_HOUSE
 *    EEC_DWELLTY_MOBILE_HOME
 *    EEC_DWELLTY_MOUNTAIN_HUT
 *    EEC_DWELLTY_MULTI_UNIT_DWELLING
 *    EEC_DWELLTY_OUTBUILDING
 *    EEC_DWELLTY_SENIOR_CITIZENS_HOME
 *    EEC_DWELLTY_TEMPORARY_RESIDENCE
 *
 * Group Membership: SHELTER
 */
#define EAC_DWELLING_TYPE ((EDCS_Attribute_Code)320)

/*
 * Definition:
 *     The type of an ecosystem based on a combination of land cover,
 *     floristic properties, climate, and physiognomy.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ECOSYSTY_BAMBOO
 *    EEC_ECOSYSTY_BARE_COASTAL_DUNES
 *    EEC_ECOSYSTY_BARE_DESERT
 *    EEC_ECOSYSTY_BARREN_TUNDRA
 *    EEC_ECOSYSTY_BEACHES_AND_DUNES
 *    EEC_ECOSYSTY_BROADLEAF_CROPS
 *    EEC_ECOSYSTY_COAST_WETLAND_NE
 *    EEC_ECOSYSTY_COAST_WETLAND_NW
 *    EEC_ECOSYSTY_COAST_WETLAND_SE
 *    EEC_ECOSYSTY_COAST_WETLAND_SW
 *    EEC_ECOSYSTY_COASTLINE_FRINGE
 *    EEC_ECOSYSTY_COLD_GRASSLAND
 *    EEC_ECOSYSTY_COLD_IRRIGATED_CROPLAND
 *    EEC_ECOSYSTY_COMPOUND_COASTLINES
 *    EEC_ECOSYSTY_CONIFER_BOREAL_FOREST
 *    EEC_ECOSYSTY_CONIFER_FOREST
 *    EEC_ECOSYSTY_CONIFEROUS_FOREST
 *    EEC_ECOSYSTY_COOL_BROADLEAF_FOREST
 *    EEC_ECOSYSTY_COOL_CONIFER_FOREST
 *    EEC_ECOSYSTY_COOL_CROPS_AND_TOWNS
 *    EEC_ECOSYSTY_COOL_FIELDS_AND_WOODS
 *    EEC_ECOSYSTY_COOL_FOREST_AND_FIELD
 *    EEC_ECOSYSTY_COOL_GRASSES_AND_SHRUBS
 *    EEC_ECOSYSTY_COOL_IRRIGATED_CROPLAND
 *    EEC_ECOSYSTY_COOL_MIXED_FOREST
 *    EEC_ECOSYSTY_COOL_RAIN_FOREST
 *    EEC_ECOSYSTY_COOL_S_HMISPH_MIXED_FORESTS
 *    EEC_ECOSYSTY_CORN_AND_BEANS_CROPLAND
 *    EEC_ECOSYSTY_CROP_AND_WATER_MIXTURES
 *    EEC_ECOSYSTY_CROPS_AND_TOWN
 *    EEC_ECOSYSTY_CROPS_GRASS_SHRUBS
 *    EEC_ECOSYSTY_DECID_BROADLEAF_FOREST
 *    EEC_ECOSYSTY_DECID_BROADLEAF_WOODS
 *    EEC_ECOSYSTY_DECID_CONIFER_FOREST
 *    EEC_ECOSYSTY_DECID_MIXED_BOREAL_FOREST
 *    EEC_ECOSYSTY_DECIDUOUS_TREE_CROP
 *    EEC_ECOSYSTY_DRY_EVERGREEN_WOODS
 *    EEC_ECOSYSTY_DRY_TROPICAL_WOODS
 *    EEC_ECOSYSTY_DRY_WOODY_SCRUB
 *    EEC_ECOSYSTY_EVERGREEN_BROADLEAF
 *    EEC_ECOSYSTY_EVERGREEN_FOREST_FIELDS
 *    EEC_ECOSYSTY_EVERGREEN_TREE_CROP
 *    EEC_ECOSYSTY_FIELDS_AND_WOODY_SAVANNA
 *    EEC_ECOSYSTY_FOREST_AND_FIELD
 *    EEC_ECOSYSTY_GLACIER_ICE
 *    EEC_ECOSYSTY_GLACIER_ROCK
 *    EEC_ECOSYSTY_GRASS_CROPS
 *    EEC_ECOSYSTY_HEATH_SCRUB
 *    EEC_ECOSYSTY_HOT_IRRIGATED_CROPLAND
 *    EEC_ECOSYSTY_HOT_MILD_GRASSES_SHRUBS
 *    EEC_ECOSYSTY_INLAND_WATER
 *    EEC_ECOSYSTY_IRRIGATED_GRASSLAND
 *    EEC_ECOSYSTY_LAND_AND_WATER_RIVERS
 *    EEC_ECOSYSTY_LAND_WATER_AND_SHORE
 *    EEC_ECOSYSTY_LOW_SPARSE_GRASSLAND
 *    EEC_ECOSYSTY_MANGROVE
 *    EEC_ECOSYSTY_MARSH_WETLAND
 *    EEC_ECOSYSTY_MEDITERRANEAN_SCRUB
 *    EEC_ECOSYSTY_MIRE_BOG_FEN
 *    EEC_ECOSYSTY_MIXED_FOREST
 *    EEC_ECOSYSTY_MIXED_FOREST_AND_FIELD
 *    EEC_ECOSYSTY_MOIST_EUCALYPTUS
 *    EEC_ECOSYSTY_MONTANE_TROPICAL_FORESTS
 *    EEC_ECOSYSTY_NARROW_CONIFERS
 *    EEC_ECOSYSTY_POLAR_AND_ALPINE_DESERT
 *    EEC_ECOSYSTY_RAIN_GREEN_TROPICAL_FOREST
 *    EEC_ECOSYSTY_RESIDUAL_DUNES_BEACHES
 *    EEC_ECOSYSTY_RICE_PADDY_AND_FIELD
 *    EEC_ECOSYSTY_ROCKY_CLIFFS_AND_SLOPES
 *    EEC_ECOSYSTY_S_HMISPH_CONIFERS
 *    EEC_ECOSYSTY_S_HMISPH_MIXED_FOREST
 *    EEC_ECOSYSTY_SALT_PLAYAS
 *    EEC_ECOSYSTY_SAND_DESERT
 *    EEC_ECOSYSTY_SANDY_GRASSLAND_SHRUBS
 *    EEC_ECOSYSTY_SAVANNA_WOODS
 *    EEC_ECOSYSTY_SEA_WATER
 *    EEC_ECOSYSTY_SEASONAL_TROPICAL_FOREST
 *    EEC_ECOSYSTY_SEMI_DESERT
 *    EEC_ECOSYSTY_SEMI_DESERT_SAGE
 *    EEC_ECOSYSTY_SEMI_DESERT_SHRUBS
 *    EEC_ECOSYSTY_SHRUB_DECIDUOUS
 *    EEC_ECOSYSTY_SHRUB_EVERGREEN
 *    EEC_ECOSYSTY_SMALL_LEAF_MIXED_WOODS
 *    EEC_ECOSYSTY_SPARSE_DUNES_AND_RIDGES
 *    EEC_ECOSYSTY_SUCCULENT_THORN_SCRUB
 *    EEC_ECOSYSTY_TALL_GRASSES_AND_SHRUBS
 *    EEC_ECOSYSTY_TROPICAL_DEGRADED_FOREST
 *    EEC_ECOSYSTY_TROPICAL_RAINFOREST
 *    EEC_ECOSYSTY_UPLAND_TUNDRA
 *    EEC_ECOSYSTY_URBAN
 *    EEC_ECOSYSTY_VOLCANIC_ROCK
 *    EEC_ECOSYSTY_WATER_AND_ISLAND_FRINGE
 *    EEC_ECOSYSTY_WET_SCLEROPHYLIC_FOREST
 *    EEC_ECOSYSTY_WOODED_TUNDRA
 *    EEC_ECOSYSTY_WOODED_WET_SWAMP
 *    EEC_ECOSYSTY_WOODY_SAVANNA
 *
 * Group Membership: ATMOSPHERE, LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define EAC_ECOSYSTEM_TYPE ((EDCS_Attribute_Code)321)

/*
 * Definition:
 *     The type of an educational <BUILDING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EDUBLDGTY_ACADEMY
 *    EEC_EDUBLDGTY_COLLEGE
 *    EEC_EDUBLDGTY_EDUCATIONAL_CENTRE
 *    EEC_EDUBLDGTY_LYCEUM
 *    EEC_EDUBLDGTY_SEMINARY
 *    EEC_EDUBLDGTY_UNIVERSITY
 *
 * Group Membership: INFRASTRUCTURE, SHELTER
 */
#define EAC_EDUCATIONAL_BUILDING_TYPE ((EDCS_Attribute_Code)322)

/*
 * Definition:
 *     The number of electrons per unit <<VOLUME>>; the electron density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_DENSITY
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_ELECTRON_DENSITY ((EDCS_Attribute_Code)323)

/*
 * Definition:
 *     The <<DEPTH_OF_WATERBODY_FLOOR>> obtained by electronic depth
 *     measuring instruments.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_ELECTRONIC_WATERBODY_FLOOR_DEPTH ((EDCS_Attribute_Code)324)

/*
 * Definition:
 *     The value of the maximum variation in the vertical clearance of an
 *     <ELEVATED_ELECTRICAL_CABLE> due to an accumulation of <ICE>; the
 *     elevated electrical cable icing sag.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, INFRASTRUCTURE
 */
#define EAC_ELEV_ELECTRICAL_CABLE_ICING_SAG ((EDCS_Attribute_Code)325)

/*
 * Definition:
 *     The minimum <<HEIGHT_AGL>> of an <ELEVATED_ELECTRICAL_CABLE> above the
 *     underlying <PLANETARY_SURFACE>; the elevated electrical cable minimum
 *     clearance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, INFRASTRUCTURE
 */
#define EAC_ELEV_ELECTRICAL_CABLE_MINIMUM_HEIGHT ((EDCS_Attribute_Code)326)

/*
 * Definition:
 *     The spacing distance between adjacent <PYLON>s along an
 *     <ELEVATED_ELECTRICAL_CABLE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, INFRASTRUCTURE
 */
#define EAC_ELEV_ELECTRICAL_CABLE_PYLON_SPACING ((EDCS_Attribute_Code)327)

/*
 * Definition:
 *     The maximum vertical distance from the height of an
 *     <ELEVATED_ELECTRICAL_CABLE> at a connection to a <PYLON> to the
 *     lowest point of the <ELEVATED_ELECTRICAL_CABLE>; the elevated
 *     electrical cable sag.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, INFRASTRUCTURE
 */
#define EAC_ELEV_ELECTRICAL_CABLE_SAG ((EDCS_Attribute_Code)328)

/*
 * Definition:
 *     The number of straight segments that may be used to approximate the
 *     catenary shape of an <ELEVATED_ELECTRICAL_CABLE> between adjacent
 *     <PYLON>s; the elevated electrical cable segment count.
 *
 * Value Type: COUNT
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_ELEV_ELECTRICAL_CABLE_SEGMENT_COUNT ((EDCS_Attribute_Code)329)

/*
 * Definition:
 *     The type of suspension of an <ELEVATED_ELECTRICAL_CABLE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ELEVELECCBLTY_MOUNTAIN_CATENARY
 *    EEC_ELEVELECCBLTY_NORMAL_SUSPENSION
 *    EEC_ELEVELECCBLTY_OVERWATER_CATENARY
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_ELEV_ELECTRICAL_CABLE_TYPE ((EDCS_Attribute_Code)330)

/*
 * Definition:
 *     The distance above a <SURFACE_DATUM>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION
 */
#define EAC_ELEVATION ((EDCS_Attribute_Code)331)

/*
 * Definition:
 *     A statement of the accuracy of an <<ELEVATION>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ELEVACCSTMT_ACCURATE
 *    EEC_ELEVACCSTMT_APPROXIMATE
 *
 * Group Membership: SURVEY
 */
#define EAC_ELEVATION_ACCURACY_STATEMENT ((EDCS_Attribute_Code)332)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_LOCAL>> from the horizontal plane at the
 *     observer's location, to either a <LINE> passing through the observer,
 *     or a vector relative to the observer, or the direction from the
 *     observer to an <OBJECT> or <LOCATION>; the elevation angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_ELEVATION_ANGLE ((EDCS_Attribute_Code)333)

/*
 * Definition:
 *     The scientifically-accepted designation for a range of <<FREQUENCY>>s
 *     within the electromagnetic spectrum; the electromagnetic band.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EMBAND_RF
 *    EEC_EMBAND_ULF
 *    EEC_EMBAND_ELF
 *    EEC_EMBAND_VLF
 *    EEC_EMBAND_LF
 *    EEC_EMBAND_MF
 *    EEC_EMBAND_HF
 *    EEC_EMBAND_VHF
 *    EEC_EMBAND_Q
 *    EEC_EMBAND_P
 *    EEC_EMBAND_UHF
 *    EEC_EMBAND_L
 *    EEC_EMBAND_MICROWAVE
 *    EEC_EMBAND_SHF
 *    EEC_EMBAND_S
 *    EEC_EMBAND_C
 *    EEC_EMBAND_X
 *    EEC_EMBAND_KU
 *    EEC_EMBAND_K
 *    EEC_EMBAND_KA
 *    EEC_EMBAND_EHF
 *    EEC_EMBAND_V
 *    EEC_EMBAND_W
 *    EEC_EMBAND_INFRARED
 *    EEC_EMBAND_EXTREME_INFRARED
 *    EEC_EMBAND_SUBMILLIMETRE
 *    EEC_EMBAND_FAR_INFRARED
 *    EEC_EMBAND_INTERMEDIATE_INFRARED
 *    EEC_EMBAND_NEAR_INFRARED
 *    EEC_EMBAND_VISIBLE
 *    EEC_EMBAND_RED
 *    EEC_EMBAND_ORANGE
 *    EEC_EMBAND_YELLOW
 *    EEC_EMBAND_GREEN
 *    EEC_EMBAND_BLUE
 *    EEC_EMBAND_VIOLET
 *    EEC_EMBAND_UV
 *    EEC_EMBAND_NEAR_UV
 *    EEC_EMBAND_FARULTRAVIOLET
 *    EEC_EMBAND_UV_A
 *    EEC_EMBAND_UV_B
 *    EEC_EMBAND_UV_C
 *    EEC_EMBAND_X_RAY
 *    EEC_EMBAND_GAMMA_RAY
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_EM_BAND ((EDCS_Attribute_Code)334)

/*
 * Definition:
 *     The <<HEIGHT_AGL>> of the top of a
 *     <ELECTROMAGNETIC_REFRACTIVE_EVAPORATIVE_DUCT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, LOCATION
 */
#define EAC_EM_EVAPORATIVE_DUCT_HEIGHT ((EDCS_Attribute_Code)335)

/*
 * Definition:
 *     The type(s) of electromagnetic polarization established by an <AERIAL>
 *     of an emitter and/or a receiver.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EMPOLRTY_CIRCULAR
 *    EEC_EMPOLRTY_CROSSED_VERT_HORIZ
 *    EEC_EMPOLRTY_CROSSED_HORIZ_VERT
 *    EEC_EMPOLRTY_ELLIPTICAL
 *    EEC_EMPOLRTY_LINEAR_HORIZONTAL
 *    EEC_EMPOLRTY_LINEAR_VERTICAL
 *    EEC_EMPOLRTY_PARALLEL_INCID_RFLCT_PLANE
 *    EEC_EMPOLRTY_PERPENDICULAR_INCID_RFLCT_PLANE
 *    EEC_EMPOLRTY_RANDOM
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_EM_POLARIZATION_TYPE ((EDCS_Attribute_Code)336)

/*
 * Definition:
 *     The type of condition causing variation in the propagation path of
 *     electromagnetic energy due to interaction of the emitted energy with
 *     the vertical density gradient of the <ATMOSPHERE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EMPROPCND_RADIO_DUCT
 *    EEC_EMPROPCND_STANDARD
 *    EEC_EMPROPCND_SUBSTANDARD
 *    EEC_EMPROPCND_SUPERSTANDARD
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define EAC_EM_PROPAGATION_CONDITION ((EDCS_Attribute_Code)337)

/*
 * Definition:
 *     The quantity of time (duration) of an electromagnetic pulse, as
 *     measured between the half-power points.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: EM_PHENOMENON, TIME
 */
#define EAC_EM_PULSE_DURATION ((EDCS_Attribute_Code)338)

/*
 * Definition:
 *     The peak power of an electromagnetic pulse.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_EM_PULSE_PEAK_POWER ((EDCS_Attribute_Code)339)

/*
 * Definition:
 *     The total energy of an electromagnetic pulse.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: ENERGY
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_EM_PULSE_TOTAL_ENERGY ((EDCS_Attribute_Code)340)

/*
 * Definition:
 *     The electromagnetic <<TRANSMISSION_LOSS>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_EM_TRANSMISSION_LOSS ((EDCS_Attribute_Code)341)

/*
 * Definition:
 *     The ratio of the power emitted by an <OBJECT> at a given
 *     <<TEMPERATURE>> to the power emitted if the body obeyed Planck's
 *     radiation law (black body emission); the emissivity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_EMISSIVITY ((EDCS_Attribute_Code)342)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_GEODETIC>> toward which light is emitted (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_EMITTANCE_AZIMUTH_GEODETIC ((EDCS_Attribute_Code)343)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_LOCAL>> toward which light is emitted (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_EMITTANCE_AZIMUTH_LOCAL ((EDCS_Attribute_Code)344)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_MAGNETIC>> toward which light is emitted (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_EMITTANCE_AZIMUTH_MAGNETIC ((EDCS_Attribute_Code)345)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_HORIZONTAL>> toward which light is emitted
 *     (the <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_EMITTANCE_ELEV_ANGLE_HORIZONTAL ((EDCS_Attribute_Code)346)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_LOCAL>> toward which light is emitted (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_EMITTANCE_ELEV_ANGLE_LOCAL ((EDCS_Attribute_Code)347)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing that linearly-scaled
 *     fractional light intensity that leaves the <SURFACE> of an <OBJECT>
 *     in all <DIRECTION>s with equal magnitude. Zero means minimum
 *     intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_EMITTED_DIFFUSE_LIGHT_SCALED_INTENSITY ((EDCS_Attribute_Code)348)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing that linearly-scaled
 *     fractional light intensity that leaves the <SURFACE> of an <OBJECT>
 *     in a particular <DIRECTION>. Zero means minimum intensity and one
 *     means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_EMITTED_SPECULAR_LIGHT_SCALED_INTENSITY ((EDCS_Attribute_Code)349)

/*
 * Definition:
 *     The maximum vertical distance from <FLOOR> to <ROOM_CEILING> of a
 *     <BUILDING> compartment (for example: a <ROOM> and/or a
 *     <FLOOR_CRAWL_SPACE>; the enclosure maximum height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: BUILDING_COMPONENT, DIMENSION
 */
#define EAC_ENCLOSURE_MAXIMUM_HEIGHT ((EDCS_Attribute_Code)350)

/*
 * Definition:
 *     The minimum vertical distance from <FLOOR> to <ROOM_CEILING> of a
 *     <BUILDING> compartment (for example: a <ROOM> and/or a
 *     <FLOOR_CRAWL_SPACE>; the enclosure maximum height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: BUILDING_COMPONENT, DIMENSION
 */
#define EAC_ENCLOSURE_MINIMUM_HEIGHT ((EDCS_Attribute_Code)351)

/*
 * Definition:
 *     The <<SMOKE_RATE_FRACTION>> of a motor/engine/propulsion <SYSTEM> in
 *     an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_ENGINE_SMOKE_RATE ((EDCS_Attribute_Code)352)

/*
 * Definition:
 *     The type of an <ENGINEER_TRENCH>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ENGTRENCHTY_INFANTRY_TRENCH
 *    EEC_ENGTRENCHTY_SOVIET_ANTI_TANK_DITCH
 *    EEC_ENGTRENCHTY_US_ANTI_TANK_DITCH
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ENGINEER_TRENCH_TYPE ((EDCS_Attribute_Code)353)

/*
 * Definition:
 *     The number of <STRUCTURE_ENTRANCE_AND_OR_EXIT>s of a <STRUCTURE>; the
 *     entrance and/or exit count.
 *
 * Value Type: COUNT
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_ENTRANCE_AND_OR_EXIT_COUNT ((EDCS_Attribute_Code)354)

/*
 * Definition:
 *     The number of <STRUCTURE_ENTRANCE>s of a <STRUCTURE>; the entrance
 *     count.
 *
 * Value Type: COUNT
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_ENTRANCE_COUNT ((EDCS_Attribute_Code)355)

/*
 * Definition:
 *     The certainty of existence of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EXISTCERT_APPROXIMATE
 *    EEC_EXISTCERT_DEFINITE
 *    EEC_EXISTCERT_DOUBTFUL
 *    EEC_EXISTCERT_POSSIBLE
 *    EEC_EXISTCERT_REPORTED
 *
 * Group Membership: ABSTRACT_OBJECT, SURVEY
 */
#define EAC_EXISTENCE_CERTAINTY ((EDCS_Attribute_Code)356)

/*
 * Definition:
 *     The status or existence condition of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EXISTSTAT_ABANDONED
 *    EEC_EXISTSTAT_ALTERNATE
 *    EEC_EXISTSTAT_ANCIENT
 *    EEC_EXISTSTAT_APPROXIMATE
 *    EEC_EXISTSTAT_BLADES_MISSING
 *    EEC_EXISTSTAT_CONTINUOUS_OPERATION
 *    EEC_EXISTSTAT_CONTROLLED
 *    EEC_EXISTSTAT_CORRESPONDS
 *    EEC_EXISTSTAT_DAMAGED
 *    EEC_EXISTSTAT_DEFINITE
 *    EEC_EXISTSTAT_DEFINITE_SHORELINE
 *    EEC_EXISTSTAT_DESTROYED
 *    EEC_EXISTSTAT_DISMANTLED
 *    EEC_EXISTSTAT_DISSIPATING
 *    EEC_EXISTSTAT_DISUSED
 *    EEC_EXISTSTAT_DOES_NOT_CORRESPOND
 *    EEC_EXISTSTAT_DOUBTFUL
 *    EEC_EXISTSTAT_EXTINGUISHED
 *    EEC_EXISTSTAT_HISTORIC
 *    EEC_EXISTSTAT_ILLUMINATED
 *    EEC_EXISTSTAT_INACTIVE
 *    EEC_EXISTSTAT_INCOMPLETE
 *    EEC_EXISTSTAT_INDEFINITE_SHORELINE
 *    EEC_EXISTSTAT_INDETERMINATE
 *    EEC_EXISTSTAT_INTERMITTENT_OPERATION
 *    EEC_EXISTSTAT_ISOLATED
 *    EEC_EXISTSTAT_MAINTAINED
 *    EEC_EXISTSTAT_MAN_MADE
 *    EEC_EXISTSTAT_NATURAL
 *    EEC_EXISTSTAT_NAVIGABLE
 *    EEC_EXISTSTAT_NAVIGABLE_ABANDONED
 *    EEC_EXISTSTAT_NAVIGABLE_OPERATIONAL
 *    EEC_EXISTSTAT_NON_CONTROLLED
 *    EEC_EXISTSTAT_NON_TIDAL
 *    EEC_EXISTSTAT_NOT_ACCESSIBLE
 *    EEC_EXISTSTAT_NOT_ISOLATED
 *    EEC_EXISTSTAT_NOT_MAINTAINED
 *    EEC_EXISTSTAT_NOT_USABLE
 *    EEC_EXISTSTAT_OCCASIONAL
 *    EEC_EXISTSTAT_ON_TEST_COMMISSIONED
 *    EEC_EXISTSTAT_ON_TEST_NOT_COMMISSIONED
 *    EEC_EXISTSTAT_ONE_WAY
 *    EEC_EXISTSTAT_OPERATIONAL
 *    EEC_EXISTSTAT_OPERATIONAL_COMMISSIONED
 *    EEC_EXISTSTAT_OPERATIONAL_NOT_COMMISSIONED
 *    EEC_EXISTSTAT_OUT_OF_SERVICE_COMMISSIONED
 *    EEC_EXISTSTAT_OUT_OF_SERVICE_NOT_COMMISSIONED
 *    EEC_EXISTSTAT_PARTIALLY_DESTROYED
 *    EEC_EXISTSTAT_PERIODIC
 *    EEC_EXISTSTAT_PERMANENT
 *    EEC_EXISTSTAT_PLANNED_CONSTRUCTION
 *    EEC_EXISTSTAT_PROPOSED
 *    EEC_EXISTSTAT_RECOMMENDED
 *    EEC_EXISTSTAT_REPORTED
 *    EEC_EXISTSTAT_RUINED
 *    EEC_EXISTSTAT_SONAR_CONFIRMED
 *    EEC_EXISTSTAT_SONAR_NOT_CONFIRMED
 *    EEC_EXISTSTAT_SWEPT
 *    EEC_EXISTSTAT_SYNCHRONIZED
 *    EEC_EXISTSTAT_TEMPORARY
 *    EEC_EXISTSTAT_TIDAL
 *    EEC_EXISTSTAT_TWO_WAY
 *    EEC_EXISTSTAT_UNDER_CONSTRUCTION
 *    EEC_EXISTSTAT_UNWATCHED
 *    EEC_EXISTSTAT_WATCHED
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_EXISTENCE_STATUS ((EDCS_Attribute_Code)357)

/*
 * Definition:
 *     The number of <STRUCTURE_EXIT>s of a <STRUCTURE>; the exit count.
 *
 * Value Type: COUNT
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_EXIT_COUNT ((EDCS_Attribute_Code)358)

/*
 * Definition:
 *     The areal density of <EXPLOSIVE_MINE>s within a <MINEFIELD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: MILITARY_SCIENCE, RATE_OR_RATIO
 */
#define EAC_EXPLOSIVE_MINE_DENSITY ((EDCS_Attribute_Code)359)

/*
 * Definition:
 *     The type of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EXPLMINETY_ANTIPERSONNEL
 *    EEC_EXPLMINETY_ANTITANK
 *    EEC_EXPLMINETY_ANTITANK_SMART
 *    EEC_EXPLMINETY_AQUATIC_ACTIVE
 *    EEC_EXPLMINETY_AQUATIC_BOTTOM
 *    EEC_EXPLMINETY_AQUATIC_BURIED
 *    EEC_EXPLMINETY_AQUATIC_DRIFTING
 *    EEC_EXPLMINETY_AQUATIC_FLOATING
 *    EEC_EXPLMINETY_AQUATIC_FREE
 *    EEC_EXPLMINETY_AQUATIC_MOORED
 *    EEC_EXPLMINETY_AQUATIC_PROUD
 *    EEC_EXPLMINETY_AQUATIC_WATCHING
 *    EEC_EXPLMINETY_DECOY
 *    EEC_EXPLMINETY_INFLUENCE
 *    EEC_EXPLMINETY_MIXED
 *    EEC_EXPLMINETY_WIDE_AREA
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_EXPLOSIVE_MINE_TYPE ((EDCS_Attribute_Code)360)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the general external <LIGHTING> of an
 *     <OBJECT>. Zero means unlit and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_EXTERIOR_LIGHTING_INTENSITY ((EDCS_Attribute_Code)361)

/*
 * Definition:
 *     The type of <MATERIAL> and/or techniques used to construct an
 *     <EXTERIOR_WALL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_XTRWALLCNSTCT_BRICK
 *    EEC_XTRWALLCNSTCT_GLASS
 *    EEC_XTRWALLCNSTCT_HOLLOW_CONCRETE_BLOCK
 *    EEC_XTRWALLCNSTCT_HOLLOW_FIRED_CLAY_BLOCK
 *    EEC_XTRWALLCNSTCT_MASONRY
 *    EEC_XTRWALLCNSTCT_PREFABRICATED_CONCRETE_TILT_UP
 *    EEC_XTRWALLCNSTCT_REINFORCED_CONCRETE
 *    EEC_XTRWALLCNSTCT_WOOD_PRODUCT
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_EXTERIOR_WALL_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)362)

/*
 * Definition:
 *     The <MATERIAL>s and/or techniques used to fortify an <EXTERIOR_WALL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_XTRWALLFRTF_NONE_PRESENT
 *    EEC_XTRWALLFRTF_ONE_ROW_SANDBAGS
 *    EEC_XTRWALLFRTF_TIMBERS
 *    EEC_XTRWALLFRTF_TWO_ROWS_SANDBAGS
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL, MILITARY_SCIENCE
 */
#define EAC_EXTERIOR_WALL_FORTIFICATION ((EDCS_Attribute_Code)363)

/*
 * Definition:
 *     The <<THICKNESS>> of an <EXTERIOR_WALL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: BUILDING_COMPONENT, DIMENSION
 */
#define EAC_EXTERIOR_WALL_THICKNESS ((EDCS_Attribute_Code)364)

/*
 * Definition:
 *     The applied external paint scheme of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EXTPNTSCM_DESERT_CAMOUFLAGE
 *    EEC_EXTPNTSCM_FOREST_CAMOUFLAGE
 *    EEC_EXTPNTSCM_NONE_PRESENT
 *    EEC_EXTPNTSCM_UNIFORM_COLOUR
 *    EEC_EXTPNTSCM_WINTER_CAMOUFLAGE
 *
 * Group Membership: ABSTRACT_OBJECT, COLOUR
 */
#define EAC_EXTERNAL_PAINT_SCHEME ((EDCS_Attribute_Code)365)

/*
 * Definition:
 *     The type of the external covering of a <WINDOW>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_XTRWNDWCOV_BARS
 *    EEC_XTRWNDWCOV_HURRICANE_SHUTTERS
 *    EEC_XTRWNDWCOV_NONE_PRESENT
 *    EEC_XTRWNDWCOV_WINDOW_SCREEN
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_EXTERNAL_WINDOW_COVERING ((EDCS_Attribute_Code)366)

/*
 * Definition:
 *     For radiation propagating through a medium, the fractional depletion
 *     of <<RADIANCE>> per unit path length; the extinction coefficient loss.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEAR_ENERGY_TRANSFER
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_EXTINCTION_COEFFICIENT ((EDCS_Attribute_Code)367)

/*
 * Definition:
 *     The vertical displacement above a <SURFACE_DATUM> identified by an
 *     <<ATM_VERTICAL_REFERENCE>> at which a given value of
 *     <<EXTINCTION_COEFFICIENT>> occurs; the extinction coefficient level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: GEOPOTENTIAL_ENERGY_LENGTH
 *
 * Group Membership: EM_PHENOMENON, LOCATION
 */
#define EAC_EXTINCTION_COEFFICIENT_LEVEL ((EDCS_Attribute_Code)368)

/*
 * Definition:
 *     The electromagnetic <<WAVELENGTH>> for an <<EXTINCTION_COEFFICIENT>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, EM_PHENOMENON
 */
#define EAC_EXTINCTION_COEFFICIENT_WAVELENGTH ((EDCS_Attribute_Code)369)

/*
 * Definition:
 *     The type of an <EXTRACTION_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_EXTRCTMINETY_BELOW_SURFACE
 *    EEC_EXTRCTMINETY_BORROW
 *    EEC_EXTRCTMINETY_HORIZONTAL_SHAFT
 *    EEC_EXTRCTMINETY_OPEN_PIT
 *    EEC_EXTRCTMINETY_PEAT_CUTTINGS
 *    EEC_EXTRCTMINETY_PLACER
 *    EEC_EXTRCTMINETY_PROSPECT
 *    EEC_EXTRCTMINETY_STRIP
 *    EEC_EXTRCTMINETY_VERTICAL_SHAFT
 *
 * Group Membership: INDUSTRY
 */
#define EAC_EXTRACTION_MINE_TYPE ((EDCS_Attribute_Code)370)

/*
 * Definition:
 *     The maximum (extreme) of a <SET> of <<MAXIMUM_AIR_TEMPERATURE>>s for a
 *     <<TIME_QUANTITY>>; a maximum high air temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_EXTREME_HIGH_AIR_TEMPERATURE ((EDCS_Attribute_Code)371)

/*
 * Definition:
 *     The minimum (extreme) of a <SET> of <<MINIMUM_AIR_TEMPERATURE>>s for a
 *     <<TIME_QUANTITY>>; a minimum low air temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_EXTREME_LOW_AIR_TEMPERATURE ((EDCS_Attribute_Code)372)

/*
 * Definition:
 *     The type of a fabrication industry <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FABTY_HEAVY
 *    EEC_FABTY_LIGHT
 *
 * Group Membership: INDUSTRY
 */
#define EAC_FABRICATION_TYPE ((EDCS_Attribute_Code)373)

/*
 * Definition:
 *     The type of commissioned status of a <FACILITY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FACCMMSSTAT_ON_TEST_COMMISSIONED
 *    EEC_FACCMMSSTAT_ON_TEST_NOT_COMMISSIONED
 *    EEC_FACCMMSSTAT_OPERATIONAL_COMMISSIONED
 *    EEC_FACCMMSSTAT_OPERATIONAL_NOT_COMMISSIONED
 *    EEC_FACCMMSSTAT_OUT_SERVICE_COMMISSIONED
 *    EEC_FACCMMSSTAT_OUT_SERVICE_NOT_COMMISSIONED
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_FACILITY_COMMISSIONED_STATUS ((EDCS_Attribute_Code)374)

/*
 * Definition:
 *     The continuity of operation of a <FACILITY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FACOPCNT_CONTINUOUS
 *    EEC_FACOPCNT_INTERMITTENT
 *    EEC_FACOPCNT_OCCASIONAL
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_FACILITY_OPERATION_CONTINUITY ((EDCS_Attribute_Code)375)

/*
 * Definition:
 *     The agricultural practice in use within an agro-ecosystem; the farming
 *     method.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FARMMETH_CROP_ROTATION
 *    EEC_FARMMETH_GRAZING
 *    EEC_FARMMETH_PERMACULTURE
 *    EEC_FARMMETH_SLASH_AND_BURN
 *
 * Group Membership: AGRICULTURE, USAGE_REGION
 */
#define EAC_FARMING_METHOD ((EDCS_Attribute_Code)376)

/*
 * Definition:
 *     The type of a <FENCE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FENCETY_BARBED_WIRE
 *    EEC_FENCETY_CHAIN_LINK
 *    EEC_FENCETY_CHAIN_LINK_BARBS_ABOVE
 *    EEC_FENCETY_CHAIN_LINK_WITH_SLATS
 *    EEC_FENCETY_LOOSE_STONE
 *    EEC_FENCETY_METAL
 *    EEC_FENCETY_MINEFIELD_LANE
 *    EEC_FENCETY_MINEFIELD_PERIMETER
 *    EEC_FENCETY_STONE
 *    EEC_FENCETY_WOOD
 *
 * Group Membership: DEMARCATION
 */
#define EAC_FENCE_TYPE ((EDCS_Attribute_Code)377)

/*
 * Definition:
 *     The <<LENGTH>> of a <FERRY_CROSSING> between points on opposite
 *     <SHORE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_FERRY_CROSSING_LENGTH ((EDCS_Attribute_Code)378)

/*
 * Definition:
 *     The usual <<TIME_QUANTITY>> taken for a crossing by <FERRY>, including
 *     typical loading and unloading times.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TIME, TRNSP
 */
#define EAC_FERRY_CROSSING_TIME ((EDCS_Attribute_Code)379)

/*
 * Definition:
 *     The type of <ROUTE> which a <FERRY> follows.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FERRYRTETY_CABLE
 *    EEC_FERRYRTETY_FREE_MOVING
 *    EEC_FERRYRTETY_ICE
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_FERRY_ROUTE_TYPE ((EDCS_Attribute_Code)380)

/*
 * Definition:
 *     The geometric layout used in placing seeds or young <PLANT>s on a
 *     <TRACT> used for agriculture; the field pattern.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FIELDPAT_LINEAR
 *    EEC_FIELDPAT_REGULAR
 *    EEC_FIELDPAT_TERRACED
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define EAC_FIELD_PATTERN ((EDCS_Attribute_Code)381)

/*
 * Definition:
 *     The type of a <FIGHTER_WINGED_AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FGTWNGARCRFTY_F_1
 *    EEC_FGTWNGARCRFTY_F_2
 *    EEC_FGTWNGARCRFTY_F_3
 *    EEC_FGTWNGARCRFTY_F_4
 *    EEC_FGTWNGARCRFTY_F_5
 *    EEC_FGTWNGARCRFTY_F_6
 *    EEC_FGTWNGARCRFTY_F_7
 *    EEC_FGTWNGARCRFTY_F_8
 *    EEC_FGTWNGARCRFTY_F_9
 *    EEC_FGTWNGARCRFTY_F_10
 *    EEC_FGTWNGARCRFTY_F_11
 *    EEC_FGTWNGARCRFTY_F_12
 *    EEC_FGTWNGARCRFTY_F_14
 *    EEC_FGTWNGARCRFTY_F_15
 *    EEC_FGTWNGARCRFTY_F_16
 *    EEC_FGTWNGARCRFTY_F_17
 *    EEC_FGTWNGARCRFTY_F_18
 *    EEC_FGTWNGARCRFTY_F_19
 *    EEC_FGTWNGARCRFTY_F_20
 *    EEC_FGTWNGARCRFTY_F_21
 *    EEC_FGTWNGARCRFTY_F_22
 *    EEC_FGTWNGARCRFTY_F_23
 *    EEC_FGTWNGARCRFTY_F_100
 *    EEC_FGTWNGARCRFTY_F_101
 *    EEC_FGTWNGARCRFTY_F_102
 *    EEC_FGTWNGARCRFTY_F_104
 *    EEC_FGTWNGARCRFTY_F_105
 *    EEC_FGTWNGARCRFTY_F_106
 *    EEC_FGTWNGARCRFTY_F_107
 *    EEC_FGTWNGARCRFTY_F_108
 *    EEC_FGTWNGARCRFTY_F_110
 *    EEC_FGTWNGARCRFTY_F_111
 *    EEC_FGTWNGARCRFTY_F_117
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_FIGHTER_WINGED_AIRCRAFT_TYPE ((EDCS_Attribute_Code)382)

/*
 * Definition:
 *     The type of an <OBJECT> that is filled with <MATERIAL> (for example:
 *     <SOIL> and/or <ROCK>); fill type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FILLTY_EMBANKMENT
 *    EEC_FILLTY_FILLED_TERRAIN
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_FILL_TYPE ((EDCS_Attribute_Code)383)

/*
 * Definition:
 *     An indication that the retracting, lowest section of a <FIRE_ESCAPE>
 *     is extended for use.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: BUILDING_COMPONENT, INFRASTRUCTURE
 */
#define EAC_FIRE_ESCAPE_EXTENDED ((EDCS_Attribute_Code)384)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the extent of physical injury/damage to an <OBJECT>
 *     affecting its capability to project firepower. Zero means not capable
 *     at all and one means fully capable.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, MILITARY_SCIENCE, RATE_OR_RATIO
 */
#define EAC_FIRE_POWER_DAMAGE ((EDCS_Attribute_Code)385)

/*
 * Definition:
 *     The type of a <FISHING_FACILITY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FISHFACTY_STAKE
 *    EEC_FISHFACTY_TRAP
 *    EEC_FISHFACTY_TUNA_NET
 *    EEC_FISHFACTY_WEIR
 *
 * Group Membership: ANIMAL, HYDROGRAPHIC_INDUSTRY, INDUSTRY, LIVING_ORGANISM, USAGE_REGION
 */
#define EAC_FISHING_FACILITY_TYPE ((EDCS_Attribute_Code)386)

/*
 * Definition:
 *     The areal density of <FISHING_BOAT>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: ANIMAL, HYDROGRAPHIC_TRNSP, LIVING_ORGANISM, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_FISHING_VESSEL_DENSITY ((EDCS_Attribute_Code)387)

/*
 * Definition:
 *     The type of <MATERIAL> and/or techniques used to construct a <FLOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FLRCNSTCTTY_BRICK
 *    EEC_FLRCNSTCTTY_COBBLE
 *    EEC_FLRCNSTCTTY_CONCRETE
 *    EEC_FLRCNSTCTTY_DIMENSION_LUMBER
 *    EEC_FLRCNSTCTTY_EARTHEN
 *    EEC_FLRCNSTCTTY_ENGINEERED_LUMBER
 *    EEC_FLRCNSTCTTY_REINFORCED_CONCRETE
 *    EEC_FLRCNSTCTTY_STEEL
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_FLOOR_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)388)

/*
 * Definition:
 *     The type of the covering of a <FLOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FLRCOVTY_CARPET
 *    EEC_FLRCOVTY_CERAMIC_TILE
 *    EEC_FLRCOVTY_CONCRETE
 *    EEC_FLRCOVTY_FIRED_CLAY_TILE
 *    EEC_FLRCOVTY_NONE_PRESENT
 *    EEC_FLRCOVTY_SHEET_VINYL
 *    EEC_FLRCOVTY_SLATE
 *    EEC_FLRCOVTY_THATCH
 *    EEC_FLRCOVTY_VINYL_TILE
 *    EEC_FLRCOVTY_WOOD
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_FLOOR_COVERING_TYPE ((EDCS_Attribute_Code)389)

/*
 * Definition:
 *     The number of <FLOOR_LEVEL>s for accommodating <HUMAN>s or <EQUIPMENT>
 *     in a <BUILDING>, possibly different from the number of stories in the
 *     <BUILDING>. <FLOOR_LEVEL>s may include underground <FLOOR_LEVEL>s as
 *     well as above ground <FLOOR_LEVEL>s; the floor level count.
 *
 * Value Type: COUNT
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_FLOOR_LEVEL_COUNT ((EDCS_Attribute_Code)390)

/*
 * Definition:
 *     The numeric identifier of a <FLOOR_LEVEL>.
 *
 * Value Type: INDEX
 *
 * Group Membership: BUILDING_COMPONENT, IDENTIFICATION
 */
#define EAC_FLOOR_LEVEL_IDENTIFIER ((EDCS_Attribute_Code)391)

/*
 * Definition:
 *     The <DIRECTION> of flow.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_FLOW_DIRECTION ((EDCS_Attribute_Code)392)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional <<AREA>> of a <REGION> of a <PLANETARY_SURFACE> that is
 *     covered by <FOG>, as seen from above. Zero means no coverage at all
 *     and one means complete coverage.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_FOG_COVERAGE_FRACTION ((EDCS_Attribute_Code)393)

/*
 * Definition:
 *     An indication that an <OBJECT> has an associated detector light for
 *     <FOG>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, AIRBORNE_PARTICLE, ATMOSPHERE, LIGHTING_AND_VISIBILITY
 */
#define EAC_FOG_DETECTOR_LIGHT_PRESENT ((EDCS_Attribute_Code)394)

/*
 * Definition:
 *     The <<EXTINCTION_COEFFICIENT>> due to <FOG>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEAR_ENERGY_TRANSFER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_FOG_EXTINCTION_COEFFICIENT ((EDCS_Attribute_Code)395)

/*
 * Definition:
 *     An indication that <FOG> is present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_FOG_PRESENT ((EDCS_Attribute_Code)396)

/*
 * Definition:
 *     The probability of the occurrence of <FOG>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_FOG_PROBABILITY ((EDCS_Attribute_Code)397)

/*
 * Definition:
 *     The type of mechanism of signal generation in the presence of <FOG>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FOGSIGGENTY_AUTOMATIC
 *    EEC_FOGSIGGENTY_HAND
 *    EEC_FOGSIGGENTY_WAVE_ACTION
 *    EEC_FOGSIGGENTY_WIND
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, COMMUNICATION
 */
#define EAC_FOG_SIGNAL_GENERATION_TYPE ((EDCS_Attribute_Code)398)

/*
 * Definition:
 *     The height of a bank of <FOG> relative to the local <TERRAIN>, where
 *     the base of the <FOG> is assumed to be at ground level; fog thickness.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, DIMENSION
 */
#define EAC_FOG_THICKNESS ((EDCS_Attribute_Code)399)

/*
 * Definition:
 *     The state of the foliage within a delineated <REGION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FOLIAGESTATE_LOW_DENSITY_LOW_CHLOROPHYLL
 *    EEC_FOLIAGESTATE_MEDIUM_DENSITY_HIGH_CHLOROPHYLL
 *    EEC_FOLIAGESTATE_HIGH_DENSITY_LOW_CHLOROPHYLL
 *    EEC_FOLIAGESTATE_HIGH_DENSITY_HIGH_CHLOROPHYLL
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define EAC_FOLIAGE_STATE ((EDCS_Attribute_Code)400)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the external <LIGHTING> used to maintain
 *     spatial relationships with/by <VEHICLE>s; the formation, running, or
 *     tail light intensity. Zero means unlit and one means maximum
 *     intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_FORMATION_RUNNING_LIGHT_INTENSITY ((EDCS_Attribute_Code)401)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the total composition of an <OBJECT>; fractional content.
 *     Zero means that there is no contribution and one means that the
 *     <OBJECT> is homogeneous.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_FRACTIONAL_CONTENT ((EDCS_Attribute_Code)402)

/*
 * Definition:
 *     The frequency of an audio, electromagnetic, or light wave.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: ACOUSTIC_PHENOMENON
 */
#define EAC_FREQUENCY ((EDCS_Attribute_Code)403)

/*
 * Definition:
 *     In a <WATERBODY>, the frequency-independent acoustic scattering level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_FREQUENCY_INDEPENDENT_ACOUSTIC_SCATTERING_LEVEL ((EDCS_Attribute_Code)404)

/*
 * Definition:
 *     The type of a <FRIGATE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FRIGTY_GRISHA_I_CLASS_ASW_CORVETTE
 *    EEC_FRIGTY_GRISHA_III_CLASS_ASW_CORVETTE
 *    EEC_FRIGTY_GRISHA_V_CLASS_ASW
 *    EEC_FRIGTY_PARCHIM_II_CLASS
 *    EEC_FRIGTY_THETIS_CLASS
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_FRIGATE_TYPE ((EDCS_Attribute_Code)405)

/*
 * Definition:
 *     The association of the front, or long, axis of an <OBJECT> to an axis
 *     of a reference local orthonormal coordinate system.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FRONTAXISREFR_NEGATIVE_X
 *    EEC_FRONTAXISREFR_NEGATIVE_Y
 *    EEC_FRONTAXISREFR_NEGATIVE_Z
 *    EEC_FRONTAXISREFR_NO_FRONT_PRESENT
 *    EEC_FRONTAXISREFR_POSITIVE_X
 *    EEC_FRONTAXISREFR_POSITIVE_Y
 *    EEC_FRONTAXISREFR_POSITIVE_Z
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_FRONT_AND_AXIS_REFERENCE ((EDCS_Attribute_Code)406)

/*
 * Definition:
 *     The <<DEPTH>> from the <TERRAIN> to the base of a layer of frozen
 *     <SOIL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, MATERIAL, PHYSIOGRAPHY
 */
#define EAC_FROZEN_SOIL_LAYER_BOTTOM_DEPTH ((EDCS_Attribute_Code)407)

/*
 * Definition:
 *     The <<DEPTH>> from the <TERRAIN> to the top of a layer of frozen
 *     <SOIL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, MATERIAL, PHYSIOGRAPHY
 */
#define EAC_FROZEN_SOIL_LAYER_TOP_DEPTH ((EDCS_Attribute_Code)408)

/*
 * Definition:
 *     The type of frozen <PRECIPITATION> and/or frozen <WATER> that is
 *     present covering a <SURFACE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FROZSRFCVRTY_ICE
 *    EEC_FROZSRFCVRTY_MIXED_SNOW_AND_ICE
 *    EEC_FROZSRFCVRTY_NONE_PRESENT
 *    EEC_FROZSRFCVRTY_SLUSH
 *    EEC_FROZSRFCVRTY_SNOW
 *    EEC_FROZSRFCVRTY_SNOW_OVER_ICE
 *
 * Group Membership: ICE
 */
#define EAC_FROZEN_SURFACE_COVER_TYPE ((EDCS_Attribute_Code)409)

/*
 * Definition:
 *     The type of fuel <FACILITY>s available at or in the near vicinity.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FUELFACAVAIL_AVIATION_FUEL
 *    EEC_FUELFACAVAIL_BUTANE
 *    EEC_FUELFACAVAIL_COAL
 *    EEC_FUELFACAVAIL_COMPRESSED_NATURAL_GAS
 *    EEC_FUELFACAVAIL_DIESEL
 *    EEC_FUELFACAVAIL_ETHANOL
 *    EEC_FUELFACAVAIL_KEROSENE
 *    EEC_FUELFACAVAIL_LIQUIFIED_PETROLEUM_GAS
 *    EEC_FUELFACAVAIL_LUBRICANTS
 *    EEC_FUELFACAVAIL_METHANE
 *    EEC_FUELFACAVAIL_NONE_PRESENT
 *    EEC_FUELFACAVAIL_OIL
 *    EEC_FUELFACAVAIL_PETROL
 *    EEC_FUELFACAVAIL_SPECIAL
 *    EEC_FUELFACAVAIL_WATER
 *
 * Group Membership: INFRASTRUCTURE, TRNSP, USAGE_REGION
 */
#define EAC_FUEL_FACILITIES_AVAILABLE ((EDCS_Attribute_Code)410)

/*
 * Definition:
 *     The number of fully functional <RUNWAY>s at an <AERODROME>; the
 *     functional runway count.
 *
 * Value Type: COUNT
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_FUNCTIONAL_RUNWAY_COUNT ((EDCS_Attribute_Code)411)

/*
 * Definition:
 *     The general condition or functionality of an <OBJECT> regardless of
 *     its primary purpose.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FNSTAT_ABANDONED
 *    EEC_FNSTAT_DAMAGED
 *    EEC_FNSTAT_DESTROYED
 *    EEC_FNSTAT_DISMANTLED
 *    EEC_FNSTAT_DISSIPATING
 *    EEC_FNSTAT_INACTIVE
 *    EEC_FNSTAT_INCOMPLETE
 *    EEC_FNSTAT_NOT_USABLE
 *    EEC_FNSTAT_OCCASIONAL
 *    EEC_FNSTAT_OPERATIONAL
 *    EEC_FNSTAT_PARTIALLY_DESTROYED
 *    EEC_FNSTAT_PROPOSED
 *    EEC_FNSTAT_RECOMMENDED
 *    EEC_FNSTAT_RUINED
 *    EEC_FNSTAT_TEMPORARILY_UNUSED
 *    EEC_FNSTAT_UNDER_CONSTRUCTION
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_FUNCTIONAL_STATUS ((EDCS_Attribute_Code)412)

/*
 * Definition:
 *     The general function or use of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FNUSE_AGRICULTURE
 *    EEC_FNUSE_ANIMAL_SANCTUARY
 *    EEC_FNUSE_AVALANCHE
 *    EEC_FNUSE_CABLE_PIPE_SIGN
 *    EEC_FNUSE_CAUSEWAY
 *    EEC_FNUSE_COMMERCE
 *    EEC_FNUSE_CONTAINER
 *    EEC_FNUSE_DRAG_STRIP
 *    EEC_FNUSE_DUGOUT
 *    EEC_FNUSE_DYKE
 *    EEC_FNUSE_FILTRATION_POND
 *    EEC_FNUSE_FIREBREAK
 *    EEC_FNUSE_FLOOD_BARRAGE
 *    EEC_FNUSE_FLOOD_CONTROL
 *    EEC_FNUSE_FOREST_PRESERVE
 *    EEC_FNUSE_INDUSTRY
 *    EEC_FNUSE_INSTITUTION
 *    EEC_FNUSE_IRRIGATION
 *    EEC_FNUSE_LEVEE
 *    EEC_FNUSE_LEVEE_OR_DYKE
 *    EEC_FNUSE_MARINE
 *    EEC_FNUSE_MEDICAL
 *    EEC_FNUSE_MIXED_URBAN
 *    EEC_FNUSE_PRISONER
 *    EEC_FNUSE_RECREATION
 *    EEC_FNUSE_REFUGEE
 *    EEC_FNUSE_RESERVE
 *    EEC_FNUSE_RESIDENCE
 *    EEC_FNUSE_RETAINING
 *    EEC_FNUSE_SCHOOL
 *    EEC_FNUSE_TOURIST
 *    EEC_FNUSE_TRANSPORTATION
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_FUNCTIONAL_USE ((EDCS_Attribute_Code)413)

/*
 * Definition:
 *     The type of <FURNITURE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FRNTTY_BOX
 *    EEC_FRNTTY_CHAIR
 *    EEC_FRNTTY_CRATE
 *    EEC_FRNTTY_DESK
 *    EEC_FRNTTY_FILING_CABINET
 *    EEC_FRNTTY_SHELVES
 *    EEC_FRNTTY_TABLE
 *    EEC_FRNTTY_BENCH
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_FURNITURE_TYPE ((EDCS_Attribute_Code)414)

/*
 * Definition:
 *     The type of a <GATE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GATETY_CROSSING
 *    EEC_GATETY_RESTRICTED_ACCESS
 *    EEC_GATETY_TOLL
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_GATE_TYPE ((EDCS_Attribute_Code)415)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the extent of physical injury/damage to an <OBJECT>. Zero
 *     means healthy or undamaged, and one means death or complete
 *     destruction.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_GENERAL_DAMAGE_FRACTION ((EDCS_Attribute_Code)416)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_GEODETIC>> in the horizontal plane at the
 *     observer's <LOCATION>, to either a <LINE> passing through the
 *     observer, or a vector relative to the observer, or the <DIRECTION>
 *     from the observer to an <OBJECT> or <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_GEODETIC_AZIMUTH ((EDCS_Attribute_Code)417)

/*
 * Definition:
 *     The designation of a <GEODETIC_DATUM>; geodetic datum identifier.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GDDTMID_ADINDAN
 *    EEC_GDDTMID_ADINDAN_BURKINA_FASO
 *    EEC_GDDTMID_ADINDAN_CAMEROON
 *    EEC_GDDTMID_ADINDAN_ETHIOPIA
 *    EEC_GDDTMID_ADINDAN_MALI
 *    EEC_GDDTMID_ADINDAN_MEAN_SOLUTION
 *    EEC_GDDTMID_ADINDAN_SENEGAL
 *    EEC_GDDTMID_ADINDAN_SUDAN
 *    EEC_GDDTMID_AFGOOYE_SOMALIA
 *    EEC_GDDTMID_AIN_EL_ABD_1970
 *    EEC_GDDTMID_AIN_EL_ABD_1970_BAHRAIN
 *    EEC_GDDTMID_AIN_EL_ABD_1970_SAUDI
 *    EEC_GDDTMID_AMERICAN_SAMOA_1962
 *    EEC_GDDTMID_AMERSFOORT_1885_1903
 *    EEC_GDDTMID_ANNA_1_ASTRO_1965
 *    EEC_GDDTMID_ANTIGUA_ISLAND_ASTRO_1943
 *    EEC_GDDTMID_ARC_1935_AFRICA
 *    EEC_GDDTMID_ARC_1950
 *    EEC_GDDTMID_ARC_1950_BOTSWANA
 *    EEC_GDDTMID_ARC_1950_BURUNDI
 *    EEC_GDDTMID_ARC_1950_LESOTHO
 *    EEC_GDDTMID_ARC_1950_MALAWI
 *    EEC_GDDTMID_ARC_1950_MEAN_SOLUTION
 *    EEC_GDDTMID_ARC_1950_SWAZILAND
 *    EEC_GDDTMID_ARC_1950_ZAIRE
 *    EEC_GDDTMID_ARC_1950_ZAMBIA
 *    EEC_GDDTMID_ARC_1950_ZIMBABWE
 *    EEC_GDDTMID_ARC_1960
 *    EEC_GDDTMID_ARC_1960_KENYA
 *    EEC_GDDTMID_ARC_1960_MEAN_SOLUTION
 *    EEC_GDDTMID_ARC_1960_TANZANIA
 *    EEC_GDDTMID_ASCENSION_ISLAND_1958
 *    EEC_GDDTMID_ASTRO_BEACON_E_1945
 *    EEC_GDDTMID_ASTRO_DOS_71_4
 *    EEC_GDDTMID_ASTRO_STATION_1952
 *    EEC_GDDTMID_ASTRO_TERN_IS_1961
 *    EEC_GDDTMID_AUSTRALIAN_GEOD_1966
 *    EEC_GDDTMID_AUSTRALIAN_GEOD_1984
 *    EEC_GDDTMID_AV_TERRESTRIAL_SYSTEM_1977
 *    EEC_GDDTMID_AYABELLE_LIGHTHOUSE
 *    EEC_GDDTMID_BEKAA_BASE_SOUTH_END
 *    EEC_GDDTMID_BELGIUM_1950
 *    EEC_GDDTMID_BELGIUM_1972
 *    EEC_GDDTMID_BELLEVUE_IGN
 *    EEC_GDDTMID_BERMUDA_1957
 *    EEC_GDDTMID_BERN_1898
 *    EEC_GDDTMID_BERN_1898_ZERO
 *    EEC_GDDTMID_BISSAU
 *    EEC_GDDTMID_BJZ54
 *    EEC_GDDTMID_BJZ54_MODIFIED
 *    EEC_GDDTMID_BOGOTA_OBS
 *    EEC_GDDTMID_BOGOTA_OBS_ZERO
 *    EEC_GDDTMID_BUKIT_RIMPAH
 *    EEC_GDDTMID_CAMACUPA_BASE_SW_END
 *    EEC_GDDTMID_CAMP_AREA_ASTRO
 *    EEC_GDDTMID_CAMPO_INCHAUSPE
 *    EEC_GDDTMID_CANTON_ASTRO_1966
 *    EEC_GDDTMID_CAPE_CANAVERAL
 *    EEC_GDDTMID_CAPE_SOUTH_AFRICA
 *    EEC_GDDTMID_CARTHAGE
 *    EEC_GDDTMID_CHATHAM_ASTRO_1971
 *    EEC_GDDTMID_CHUA_ASTRO
 *    EEC_GDDTMID_COMP_GEOD_DU_QUEBEC_1977
 *    EEC_GDDTMID_CONAKRY_PYRAMID
 *    EEC_GDDTMID_CORREGO_ALEGRE
 *    EEC_GDDTMID_CSG67_GUYANA
 *    EEC_GDDTMID_DABOLA
 *    EEC_GDDTMID_DCS3_LIGHTHOUSE
 *    EEC_GDDTMID_DECEPTION_ISLAND
 *    EEC_GDDTMID_DJAKARTA
 *    EEC_GDDTMID_DJAKARTA_ZERO
 *    EEC_GDDTMID_DOMINICA_ASTRO_M12
 *    EEC_GDDTMID_DOS_1968
 *    EEC_GDDTMID_EASTER_ISLAND_1967
 *    EEC_GDDTMID_ETRS_1989
 *    EEC_GDDTMID_EUR_1950
 *    EEC_GDDTMID_EUR_1950_CYPRUS
 *    EEC_GDDTMID_EUR_1950_EGYPT
 *    EEC_GDDTMID_EUR_1950_ENGLAND
 *    EEC_GDDTMID_EUR_1950_GREECE
 *    EEC_GDDTMID_EUR_1950_IRAN
 *    EEC_GDDTMID_EUR_1950_IRAQ
 *    EEC_GDDTMID_EUR_1950_MALTA
 *    EEC_GDDTMID_EUR_1950_MEAN_SOLUTION
 *    EEC_GDDTMID_EUR_1950_NORWAY
 *    EEC_GDDTMID_EUR_1950_PORTUGAL
 *    EEC_GDDTMID_EUR_1950_SARDINIA
 *    EEC_GDDTMID_EUR_1950_SCOTLAND
 *    EEC_GDDTMID_EUR_1950_SICILY
 *    EEC_GDDTMID_EUR_1950_TUNISIA
 *    EEC_GDDTMID_EUR_1950_W_EUROPE
 *    EEC_GDDTMID_EUR_1979
 *    EEC_GDDTMID_FORT_THOMAS_1955
 *    EEC_GDDTMID_GAN_1970
 *    EEC_GDDTMID_GANDAJIKA_BASE
 *    EEC_GDDTMID_GDZ80
 *    EEC_GDDTMID_GEOCENTRIC_DATUM_AUSTRALIA
 *    EEC_GDDTMID_GEODETIC_DATUM_1949
 *    EEC_GDDTMID_GRACIOSA_BASE_SW_1948
 *    EEC_GDDTMID_GREEK_DATUM
 *    EEC_GDDTMID_GREEK_GRS_1987
 *    EEC_GDDTMID_GUAM_1963
 *    EEC_GDDTMID_GUNONG_SEGARA
 *    EEC_GDDTMID_GUNONG_SERINDUNG
 *    EEC_GDDTMID_GUX_1_ASTRO
 *    EEC_GDDTMID_HERAT_NORTH
 *    EEC_GDDTMID_HERMANNSKOGEL
 *    EEC_GDDTMID_HJORSEY_1955
 *    EEC_GDDTMID_HONG_KONG_1929
 *    EEC_GDDTMID_HONG_KONG_1963
 *    EEC_GDDTMID_HU_TZU_SHAN
 *    EEC_GDDTMID_HUNGARIAN_1972
 *    EEC_GDDTMID_INDIAN
 *    EEC_GDDTMID_INDIAN_1954
 *    EEC_GDDTMID_INDIAN_1954_THAILAND
 *    EEC_GDDTMID_INDIAN_1960
 *    EEC_GDDTMID_INDIAN_1960_CON_SON_ISLAND
 *    EEC_GDDTMID_INDIAN_1960_VIETNAM_16N
 *    EEC_GDDTMID_INDIAN_1975
 *    EEC_GDDTMID_INDIAN_1975_THAILAND_1977
 *    EEC_GDDTMID_INDIAN_BANGLADESH
 *    EEC_GDDTMID_INDIAN_NEPAL
 *    EEC_GDDTMID_INDIAN_PAKISTAN
 *    EEC_GDDTMID_INDIAN_THAILAND_VIETNAM
 *    EEC_GDDTMID_INDONESIAN_1974
 *    EEC_GDDTMID_IRELAND_1965
 *    EEC_GDDTMID_ISTS_061_ASTRO_1968
 *    EEC_GDDTMID_ISTS_073_ASTRO_1969
 *    EEC_GDDTMID_JOHNSTON_ISLAND_1961
 *    EEC_GDDTMID_KALIANPUR
 *    EEC_GDDTMID_KANDAWALA
 *    EEC_GDDTMID_KCS_2_SIERRA_LEONE
 *    EEC_GDDTMID_KERGUELEN_ISLAND_1949
 *    EEC_GDDTMID_KERTAU_1948
 *    EEC_GDDTMID_KKJ_FINLAND
 *    EEC_GDDTMID_KOREAN_GEODETIC_1995
 *    EEC_GDDTMID_KUSAIE_ASTRO_1951
 *    EEC_GDDTMID_KUWAIT_OIL_COMPANY_K28
 *    EEC_GDDTMID_LC5_ASTRO_1961
 *    EEC_GDDTMID_LEIGON
 *    EEC_GDDTMID_LIBERIA_1964
 *    EEC_GDDTMID_LISBON_D73
 *    EEC_GDDTMID_LOCAL_ASTRONOMICAL
 *    EEC_GDDTMID_LOCAL_UNSPECIFIED
 *    EEC_GDDTMID_LOMA_QUINTANA
 *    EEC_GDDTMID_LUZON
 *    EEC_GDDTMID_LUZON_APPROXIMATE
 *    EEC_GDDTMID_LUZON_MINDANAO_ISLAND
 *    EEC_GDDTMID_LUZON_PHILIPPINES
 *    EEC_GDDTMID_M_PORALOKO
 *    EEC_GDDTMID_MAHE_1971
 *    EEC_GDDTMID_MANOKWARI
 *    EEC_GDDTMID_MARCO_ASTRO
 *    EEC_GDDTMID_MARTINIQUE_FORT_DESAIX
 *    EEC_GDDTMID_MASSAWA
 *    EEC_GDDTMID_MAYOTTE_COMBANI
 *    EEC_GDDTMID_MERCHICH
 *    EEC_GDDTMID_MIDWAY_ASTRO_1961
 *    EEC_GDDTMID_MINNA
 *    EEC_GDDTMID_MINNA_CAMEROON
 *    EEC_GDDTMID_MINNA_NIGERIA
 *    EEC_GDDTMID_MONTJONG_LOWE
 *    EEC_GDDTMID_MONTSERRAT_ASTRO_1958
 *    EEC_GDDTMID_MOUNT_DILLON
 *    EEC_GDDTMID_N_AM_1927
 *    EEC_GDDTMID_N_AM_1927_ALASKA
 *    EEC_GDDTMID_N_AM_1927_ALBERTA
 *    EEC_GDDTMID_N_AM_1927_BAHAMAS
 *    EEC_GDDTMID_N_AM_1927_CANADA_MEAN
 *    EEC_GDDTMID_N_AM_1927_CANAL_ZONE
 *    EEC_GDDTMID_N_AM_1927_CARIBBEAN
 *    EEC_GDDTMID_N_AM_1927_CENTRAL_AMERICA
 *    EEC_GDDTMID_N_AM_1927_CONUS_MEAN
 *    EEC_GDDTMID_N_AM_1927_CUBA
 *    EEC_GDDTMID_N_AM_1927_EAST_ALEUTIAN
 *    EEC_GDDTMID_N_AM_1927_EASTERN_US
 *    EEC_GDDTMID_N_AM_1927_HAYES_GREENLAND
 *    EEC_GDDTMID_N_AM_1927_MANITOBA_ONTARIO
 *    EEC_GDDTMID_N_AM_1927_MEXICO
 *    EEC_GDDTMID_N_AM_1927_NEWFOUNDLAND
 *    EEC_GDDTMID_N_AM_1927_NORTHWEST_TERR
 *    EEC_GDDTMID_N_AM_1927_SAN_SALVADOR
 *    EEC_GDDTMID_N_AM_1927_WEST_ALEUTIAN
 *    EEC_GDDTMID_N_AM_1927_WESTERN_US
 *    EEC_GDDTMID_N_AM_1927_YUKON
 *    EEC_GDDTMID_N_AM_1983
 *    EEC_GDDTMID_N_AM_1983_ALASKA
 *    EEC_GDDTMID_N_AM_1983_ALEUTIANS
 *    EEC_GDDTMID_N_AM_1983_CANADA
 *    EEC_GDDTMID_N_AM_1983_CONUS
 *    EEC_GDDTMID_N_AM_1983_HAWAII
 *    EEC_GDDTMID_N_AM_1983_MEXICO
 *    EEC_GDDTMID_N_SAHARA_1959
 *    EEC_GDDTMID_NAHRWAN
 *    EEC_GDDTMID_NAHRWAN_MASIRAH_OMAN
 *    EEC_GDDTMID_NAHRWAN_REVISED
 *    EEC_GDDTMID_NAHRWAN_SAUDI_ARABIA
 *    EEC_GDDTMID_NAHRWAN_UAE
 *    EEC_GDDTMID_NAPARIMA
 *    EEC_GDDTMID_NEW_FRENCH_ZERO
 *    EEC_GDDTMID_OBSERV_METEORO_1939
 *    EEC_GDDTMID_OCOTOPEQUE_GUATEMALA
 *    EEC_GDDTMID_OLD_EGYPTIAN_1907
 *    EEC_GDDTMID_OLD_HAWAIIAN
 *    EEC_GDDTMID_OLD_HAWAIIAN_HAWAII
 *    EEC_GDDTMID_OLD_HAWAIIAN_INT
 *    EEC_GDDTMID_OLD_HAWAIIAN_INT_HAWAII
 *    EEC_GDDTMID_OLD_HAWAIIAN_INT_KAUAI
 *    EEC_GDDTMID_OLD_HAWAIIAN_INT_MAUI
 *    EEC_GDDTMID_OLD_HAWAIIAN_INT_MEAN_SOLUTION
 *    EEC_GDDTMID_OLD_HAWAIIAN_INT_OAHU
 *    EEC_GDDTMID_OLD_HAWAIIAN_KAUAI
 *    EEC_GDDTMID_OLD_HAWAIIAN_MAUI
 *    EEC_GDDTMID_OLD_HAWAIIAN_MEAN_SOLUTION
 *    EEC_GDDTMID_OLD_HAWAIIAN_OAHU
 *    EEC_GDDTMID_FAHUD
 *    EEC_GDDTMID_OSGB_1936
 *    EEC_GDDTMID_OSGB_1936_ENG_ISLE_OF_MAN
 *    EEC_GDDTMID_OSGB_1936_ENGLAND
 *    EEC_GDDTMID_OSGB_1936_MEAN_SOLUTION
 *    EEC_GDDTMID_OSGB_1936_SCOTLAND
 *    EEC_GDDTMID_OSGB_1936_WALES
 *    EEC_GDDTMID_OSLO_OBS_OLD
 *    EEC_GDDTMID_PADANG_BASE_WEST
 *    EEC_GDDTMID_PADANG_BASE_WEST_ZERO
 *    EEC_GDDTMID_PALESTINE_1928
 *    EEC_GDDTMID_PICO_DE_LAS_NIEVES
 *    EEC_GDDTMID_PITCAIRN_ASTRO_1967
 *    EEC_GDDTMID_POINT_58_MEAN_SOLUTION
 *    EEC_GDDTMID_POINTE_NOIRE_1948
 *    EEC_GDDTMID_PORTO_SANTO_1936
 *    EEC_GDDTMID_POTSDAM
 *    EEC_GDDTMID_PROV_S_AM_1956
 *    EEC_GDDTMID_PROV_S_AM_1956_BOLIVIA
 *    EEC_GDDTMID_PROV_S_AM_1956_COLOMBIA
 *    EEC_GDDTMID_PROV_S_AM_1956_ECUADOR
 *    EEC_GDDTMID_PROV_S_AM_1956_GUYANA
 *    EEC_GDDTMID_PROV_S_AM_1956_MEAN_SOLUTION
 *    EEC_GDDTMID_PROV_S_AM_1956_N_CHILE_19S
 *    EEC_GDDTMID_PROV_S_AM_1956_PERU
 *    EEC_GDDTMID_PROV_S_AM_1956_S_CHILE_43S
 *    EEC_GDDTMID_PROV_S_AM_1956_VENEZUELA
 *    EEC_GDDTMID_PROV_S_CHILEAN_1963
 *    EEC_GDDTMID_PUERTO_RICO
 *    EEC_GDDTMID_PULKOVO_1942
 *    EEC_GDDTMID_QATAR_NATIONAL
 *    EEC_GDDTMID_QORNOQ
 *    EEC_GDDTMID_RAUENBERG
 *    EEC_GDDTMID_RECONN_TRIANG_MOROCCO
 *    EEC_GDDTMID_REUNION_1947
 *    EEC_GDDTMID_RIKETS_1990_ZERO
 *    EEC_GDDTMID_ROME_1940
 *    EEC_GDDTMID_ROME_1940_ZERO
 *    EEC_GDDTMID_S_AFRICAN
 *    EEC_GDDTMID_S_AM_1969
 *    EEC_GDDTMID_S_AM_1969_ARGENTINA
 *    EEC_GDDTMID_S_AM_1969_BALTRA
 *    EEC_GDDTMID_S_AM_1969_BOLIVIA
 *    EEC_GDDTMID_S_AM_1969_BRAZIL
 *    EEC_GDDTMID_S_AM_1969_CHILE
 *    EEC_GDDTMID_S_AM_1969_COLOMBIA
 *    EEC_GDDTMID_S_AM_1969_ECUADOR
 *    EEC_GDDTMID_S_AM_1969_GUYANA
 *    EEC_GDDTMID_S_AM_1969_MEAN_SOLUTION
 *    EEC_GDDTMID_S_AM_1969_PARAGUAY
 *    EEC_GDDTMID_S_AM_1969_PERU
 *    EEC_GDDTMID_S_AM_1969_TRINIDAD_TOBAGO
 *    EEC_GDDTMID_S_AM_1969_VENEZUELA
 *    EEC_GDDTMID_S_ASIA
 *    EEC_GDDTMID_S_JTSK
 *    EEC_GDDTMID_S42_PULKOVO_1958
 *    EEC_GDDTMID_SAINTE_ANNE_I_1984
 *    EEC_GDDTMID_SANTO_DOS_1965
 *    EEC_GDDTMID_SAO_BRAZ
 *    EEC_GDDTMID_SAPPER_HILL_1943
 *    EEC_GDDTMID_SCHWARZECK
 *    EEC_GDDTMID_SELVAGEM_GRANDE_1938
 *    EEC_GDDTMID_SIERRA_LEONE_1960
 *    EEC_GDDTMID_SOVIET_GEODETIC_1985
 *    EEC_GDDTMID_SOVIET_GEODETIC_1990
 *    EEC_GDDTMID_ST_PIERRE_ET_MIQUELON_1950
 *    EEC_GDDTMID_STOCKHOLM_1938
 *    EEC_GDDTMID_SYDNEY_OBSERVATORY
 *    EEC_GDDTMID_TANANARIVE_OBS_1925
 *    EEC_GDDTMID_TANANARIVE_OBS_ZERO_1925
 *    EEC_GDDTMID_TIMBALAI_1948
 *    EEC_GDDTMID_TIMBALAI_1968
 *    EEC_GDDTMID_TOKYO
 *    EEC_GDDTMID_TOKYO_JAPAN
 *    EEC_GDDTMID_TOKYO_KOREA_1997
 *    EEC_GDDTMID_TOKYO_MEAN_SOLUTION
 *    EEC_GDDTMID_TOKYO_OKINAWA
 *    EEC_GDDTMID_TRINIDAD_1903
 *    EEC_GDDTMID_TRISTAN_ASTRO_1968
 *    EEC_GDDTMID_VITI_LEVU_1916
 *    EEC_GDDTMID_VOIROL_1874
 *    EEC_GDDTMID_VOIROL_1874_ZERO
 *    EEC_GDDTMID_VOIROL_1960_ALGERIA
 *    EEC_GDDTMID_VOIROL_1960_ZERO_ALGERIA
 *    EEC_GDDTMID_WAKE_ENIWETOK_1960
 *    EEC_GDDTMID_WAKE_ISLAND_ASTRO_1952
 *    EEC_GDDTMID_WGS_1960
 *    EEC_GDDTMID_WGS_1966
 *    EEC_GDDTMID_WGS_1972
 *    EEC_GDDTMID_WGS_1984
 *    EEC_GDDTMID_YACARE_URUGUAY
 *    EEC_GDDTMID_ZANDERIJ_SURINAME
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_GEODETIC_DATUM_IDENTIFIER ((EDCS_Attribute_Code)418)

/*
 * Definition:
 *     The maximum distance at which the curvature of the <PLANETARY_SURFACE>
 *     and refraction due to the <ATMOSPHERE> permit a <LIGHT> to be seen
 *     from a particular height of eye without regard to the luminous
 *     intensity of the <LIGHT>; the geographic light range.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_GEOGRAPHIC_LIGHT_RANGE ((EDCS_Attribute_Code)419)

/*
 * Definition:
 *     The <REGION> of the <EARTH> in which an <OBJECT> is located.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GEOREGN_AFRICA
 *    EEC_GEOREGN_ANTARCTIC
 *    EEC_GEOREGN_ARCTIC
 *    EEC_GEOREGN_ASIA
 *    EEC_GEOREGN_AUSTRALIA
 *    EEC_GEOREGN_EUROPE
 *    EEC_GEOREGN_NORTH_AMERICA
 *    EEC_GEOREGN_OCEANIA
 *    EEC_GEOREGN_SOUTH_AMERICA
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_GEOGRAPHIC_REGION ((EDCS_Attribute_Code)420)

/*
 * Definition:
 *     The <<DEPTH>> of an <OBJECT> below the mean level of the surrounding
 *     <TERRAIN> as determined by a corresponding digital elevation matrix;
 *     if not obtainable, the mean <<DEPTH>> is used; the geomorphic depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_GEOMORPHIC_DEPTH ((EDCS_Attribute_Code)421)

/*
 * Definition:
 *     The height of an <OBJECT> above the mean level of the surrounding
 *     <TERRAIN> as determined by a corresponding digital elevation matrix;
 *     the geomorphic height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_GEOMORPHIC_HEIGHT ((EDCS_Attribute_Code)422)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of a given <LOCATION> in the <ATMOSPHERE> in
 *     units proportional to the potential energy of unit <<MASS>>
 *     (geopotential); the geopotential altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: GEOPOTENTIAL_ENERGY_LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_GEOPOTENTIAL_ALTITUDE ((EDCS_Attribute_Code)423)

/*
 * Definition:
 *     The vertical angle at which an <AIRCRAFT> should properly descend to a
 *     touchdown point; the glide slope angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: AIR_TRNSP, ANGULAR_MEASURE, TRNSP
 */
#define EAC_GLIDE_SLOPE_ANGLE ((EDCS_Attribute_Code)424)

/*
 * Definition:
 *     The angle subtended by the glint vector and the surface normal, where
 *     the glint vector is the vector that bisects the source vector and the
 *     viewing vector at a <SURFACE>. Used by the Phong and
 *     Sandford-Robertson BRDF models.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ALGORITHM_RELATED, ANGULAR_MEASURE, SURFACE
 */
#define EAC_GLINT_ANGLE ((EDCS_Attribute_Code)425)

/*
 * Definition:
 *     The type and/or number of <TERRAIN_SURFACE_OBJECT> (for example: a
 *     <TERRAIN_CUT> and/or an <EMBANKMENT>) sides for which the local
 *     <TERRAIN> has been graded.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GRDTY_NO_SIDES
 *    EEC_GRDTY_ONE_SIDE
 *    EEC_GRDTY_TWO_SIDES
 *    EEC_GRDTY_MORE_THAN_TWO_SIDES
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_GRADING_TYPE ((EDCS_Attribute_Code)426)

/*
 * Definition:
 *     An indication that a passageway is blocked by one or more locked or
 *     fixed grates; grating present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: TRNSP
 */
#define EAC_GRATING_PRESENT ((EDCS_Attribute_Code)427)

/*
 * Definition:
 *     The manner in which a grid cell formed by four adjacent data values is
 *     divided into two triangular <POLYGONAL_FACE>s along a cell diagonal;
 *     the grid diagonalization.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GRIDDIAG_LOWERLEFT_UPPERRIGHT
 *    EEC_GRIDDIAG_UPPERLEFT_LOWERRIGHT
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define EAC_GRID_DIAGONALIZATION ((EDCS_Attribute_Code)428)

/*
 * Definition:
 *     The function of a <GROUND_VEHICLE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GNDVEHFN_AIR_DEFENCE_ARTILLERY
 *    EEC_GNDVEHFN_ANTI_TANK
 *    EEC_GNDVEHFN_ARMOURED_BRIDGE_LAUNCHER
 *    EEC_GNDVEHFN_ARMOURED_FIGHTING_VEHICLE
 *    EEC_GNDVEHFN_ARMOURED_TRACKED_FIGHTING_VEHICLE
 *    EEC_GNDVEHFN_ARMOURED_UTILITY_VEHICLE
 *    EEC_GNDVEHFN_COMBAT_SUPPORT_VEHICLE
 *    EEC_GNDVEHFN_COMBATANT_VEHICLE
 *    EEC_GNDVEHFN_FIELD_ARTILLERY
 *    EEC_GNDVEHFN_MISSILE
 *    EEC_GNDVEHFN_MOBILE_BRIDGE_SYSTEM
 *    EEC_GNDVEHFN_MORTAR
 *    EEC_GNDVEHFN_MOTOR_VEHICLE
 *    EEC_GNDVEHFN_MULTIDOMAIN
 *    EEC_GNDVEHFN_RECONNAISSANCE
 *    EEC_GNDVEHFN_RECOVERY
 *    EEC_GNDVEHFN_SELF_PROPELLED_ARTILLERY
 *    EEC_GNDVEHFN_TANK_DESTROYER
 *    EEC_GNDVEHFN_TOWED_VEHICLE
 *    EEC_GNDVEHFN_TRUCK
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define EAC_GROUND_VEHICLE_FUNCTION ((EDCS_Attribute_Code)429)

/*
 * Definition:
 *     The propulsion type or technique of a <GROUND_VEHICLE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GNDVEHPRPLTY_AIR_CUSHION
 *    EEC_GNDVEHPRPLTY_HALF_TRACK
 *    EEC_GNDVEHPRPLTY_TOWED
 *    EEC_GNDVEHPRPLTY_TRACKED
 *    EEC_GNDVEHPRPLTY_WHEELED
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define EAC_GROUND_VEHICLE_PROPULSION_TYPE ((EDCS_Attribute_Code)430)

/*
 * Definition:
 *     The identification of a specific geotile within the Geotile Reference
 *     System (GTRS) formatted in a Basic Latin string. The string contains
 *     a 6-digit alphanumeric designation, the first two letters of which
 *     are the encompassing GTRS megatile, the next two digits are the
 *     easting index of the geotile within the megatile, and the last two
 *     digits are the northing index of the geotile within the megatile. The
 *     2 letter designation of the GTRS megatile is based on the location of
 *     its south-west corner and is composed of a letter designating the
 *     longitudinal position of the megatile followed by a letter
 *     designating the latitudinal position of the megatile. Between 60
 *     degree N and 60 degree S there are 24 longitudinal zones of megatiles
 *     each of 15 arc degrees width beginning at 180 degree W and extending
 *     eastward through 360 arc degrees of longitude. These zones are
 *     lettered from A to Z inclusive (omitting I and O). Between 60 degree
 *     N and 90 degree N and between 60 degree S and 90 degree S there are
 *     12 longitudinal zones of megatiles each of 30 arc degrees width
 *     beginning at 180 degree W and extending eastward through 360 arc
 *     degrees of longitude. These zones are lettered as A, C, E, G, J, L,
 *     N, Q, S, U, W and Y. There are 12 latitudinal bands of megatiles each
 *     of 15 arc degrees height, beginning at 90 degree S and extending
 *     northward through 180 arc degrees of latitude. These are lettered
 *     from A to M inclusive (omitting I). This 2 letter designation thus
 *     divides the earth's surface into 288 GTRS megatiles. The index of a
 *     GTRS geotile within a GTRS megatile is based on the location of its
 *     south-west corner and is composed of two digits designating the
 *     relative longitudinal position of the geotile followed by two digits
 *     designating the relative latitudinal position of the geotile. Between
 *     60 degree N and 60 degree S there are 15 longitudinal zones of
 *     geotiles within a megatile, each of 1 arc degree width extending
 *     eastward from the western edge of the megatile. These zones are
 *     numbered from 00 to 14 inclusive. Between 60 degree and 71 degree (N
 *     or S) there are 15 longitudinal zones of geotiles within a megatile,
 *     each of 2 arc degrees width extending eastward from the western edge
 *     of the megatile. These zones are even numbered from 00 to 28
 *     inclusive. Between 71 degreeo and 78 degree (N or S) there are 10
 *     longitudinal zones of geotiles within a megatile, each of 3 arc
 *     degrees width extending eastward from the western edge of the
 *     megatile. These zones are numbered 00, 03, 06, 09, 12, 15, 18, 21, 24
 *     and 27. Between 78 degree and 80 degree (N or S) there are 6
 *     longitudinal zones of geotiles within a megatile, each of 5 arc
 *     degrees width extending eastward from the western edge of the
 *     megatile. These zones are numbered 00, 05, 10, 15, 20 and 25. Between
 *     80 degree and 84 degree (N or S) there are 5 longitudinal zones of
 *     geotiles within a megatile, each of 6 arc degrees width extending
 *     eastward from the western edge of the megatile. These zones are
 *     numbered 00, 06, 12, 18 and 24. Between 84 degree and 86 degree (N or
 *     S) there are 3 longitudinal zones of geotiles within a megatile, each
 *     of 10 arc degrees width extending eastward from the western edge of
 *     the megatile. These zones are numbered 00, 10 and 20. Between 86
 *     degreeo and 88 degree (N or S) there are 2 longitudinal zones of
 *     geotiles within a megatile, each of 15 arc degrees width extending
 *     eastward from the western edge of the megatile. These zones are
 *     numbered 00 and 15. Between 88 degree and 90 degree (N or S) there is
 *     a single longitudinal zone of geotiles within a megatile of 30 arc
 *     degrees. This zone is numbered 00. There are 15 latitudinal bands of
 *     geotiles within a megatile, each of 1 arc degree height, extending
 *     northward from the southern edge of the megatile. These bands are
 *     numbered from 00 to 14 inclusive. This 2 letter designation thus
 *     divides a GTRS megatile into as many as 225 GTRS geotiles. EXAMPLE
 *     The location 24 degree N 37 degree E corresponds to the south-west
 *     corner of the GTRS geotile designated "QH0709".
 *
 * Value Type: STRING
 *
 * Group Membership: IDENTIFICATION, LOCATION
 */
#define EAC_GTRS_GEOTILE ((EDCS_Attribute_Code)431)

/*
 * Definition:
 *     The type of a <GUIDED_MISSILE_DESTROYER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GDEMSSLDSTTY_MANCHESTER_CLASS_TYPE_42
 *    EEC_GDEMSSLDSTTY_SHEFFIELD_CLASS_TYPE_42_BATCH_1
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_GUIDED_MISSILE_DESTROYER_TYPE ((EDCS_Attribute_Code)432)

/*
 * Definition:
 *     The type of a <GUIDED_MISSILE_FRIGATE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_GDEMSSLFRIGTY_BROADSWORD_BOXER_TYPE_22_CLASS
 *    EEC_GDEMSSLFRIGTY_BROADSWORD_CORNWALL_TYPE_22_CLASS
 *    EEC_GDEMSSLFRIGTY_DUKE_CLASS_TYPE_23
 *    EEC_GDEMSSLFRIGTY_NANUCHKA_I_CLASS_CORVETTE
 *    EEC_GDEMSSLFRIGTY_NANUCHKA_III_CLASS_CORVETTE
 *    EEC_GDEMSSLFRIGTY_NANUCHKA_IV_CLASS_CORVETTE
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_GUIDED_MISSILE_FRIGATE_TYPE ((EDCS_Attribute_Code)433)

/*
 * Definition:
 *     An indication that an <OBJECT> has support <WIRE>s; guyed.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, SUPPORT_STRUCTURE
 */
#define EAC_GUYED ((EDCS_Attribute_Code)434)

/*
 * Definition:
 *     The <<OUTSIDE_DIAMETER>> of the largest <HAIL> observed; hail size.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, ICE
 */
#define EAC_HAIL_SIZE ((EDCS_Attribute_Code)435)

/*
 * Definition:
 *     The type of a <HALLWAY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HALLWAYTY_CIRCULATING
 *    EEC_HALLWAYTY_LINEAR
 *
 * Group Membership: BUILDING_COMPONENT, LAND_TRNSP, TRNSP
 */
#define EAC_HALLWAY_TYPE ((EDCS_Attribute_Code)436)

/*
 * Definition:
 *     The type of operation and/or service supported by a <FACILITY> at a
 *     <HARBOUR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HARBRFACTY_BULK
 *    EEC_HARBRFACTY_CONTAINER
 *    EEC_HARBRFACTY_FERRY
 *    EEC_HARBRFACTY_FISHING
 *    EEC_HARBRFACTY_MARINA
 *    EEC_HARBRFACTY_NAVAL_BASE
 *    EEC_HARBRFACTY_PASSENGER
 *    EEC_HARBRFACTY_ROLLON_ROLLOFF_FERRY
 *    EEC_HARBRFACTY_SHIPYARD
 *    EEC_HARBRFACTY_TANKER
 *    EEC_HARBRFACTY_TIMBER_YARD
 *
 * Group Membership: HARBOUR_AND_PORT, USAGE_REGION
 */
#define EAC_HARBOUR_FACILITY_TYPE ((EDCS_Attribute_Code)437)

/*
 * Definition:
 *     The textual identifier of a <HARBOUR>.
 *
 * Value Type: STRING
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROLOGY, IDENTIFICATION, USAGE_REGION
 */
#define EAC_HARBOUR_IDENTIFIER ((EDCS_Attribute_Code)438)

/*
 * Definition:
 *     The type of a <HAZARD_MARKER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HAZMARKERTY_BIOLOGICAL
 *    EEC_HAZMARKERTY_CONSTRUCTION
 *    EEC_HAZMARKERTY_MINEFIELD_LANE
 *    EEC_HAZMARKERTY_MINEFIELD_PERIMETER
 *    EEC_HAZMARKERTY_OVERHEAD_OBSTRUCTION
 *    EEC_HAZMARKERTY_PIPELINE
 *    EEC_HAZMARKERTY_RADIOLOGICAL_CONTAMINATION
 *    EEC_HAZMARKERTY_SURFACE_OBSTRUCTION
 *    EEC_HAZMARKERTY_TRAFFIC_DANGER
 *    EEC_HAZMARKERTY_TRAFFIC_JUNCTION
 *    EEC_HAZMARKERTY_UNDERGROUND
 *    EEC_HAZMARKERTY_WIND
 *    EEC_HAZMARKERTY_WORKMEN
 *
 * Group Membership: LOCATION
 */
#define EAC_HAZARD_MARKER_TYPE ((EDCS_Attribute_Code)439)

/*
 * Definition:
 *     The severity of a hazard.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HAZSEV_DANGEROUS
 *    EEC_HAZSEV_NON_DANGEROUS
 *    EEC_HAZSEV_NON_DANGEROUS_SURFACE_NAVIGATION
 *    EEC_HAZSEV_OBSTRUCTION
 *
 * Group Membership: TRNSP
 */
#define EAC_HAZARD_SEVERITY ((EDCS_Attribute_Code)440)

/*
 * Definition:
 *     The type of hazardous gas present within an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HAZGASTY_CHEMICAL_AGENT
 *    EEC_HAZGASTY_FLAMMABLE_SEWAGE
 *    EEC_HAZGASTY_NONE_PRESENT
 *    EEC_HAZGASTY_NONFLAMMABLE_SEWAGE
 *
 * Group Membership: ABSTRACT_OBJECT, ATMOSPHERE
 */
#define EAC_HAZARDOUS_GAS_TYPE ((EDCS_Attribute_Code)441)

/*
 * Definition:
 *     The probability of heavy accretion of <ICE> on the <SURFACE>s of
 *     <MARINE_OBJECT>s. Such accretion can occur on <SURFACE>s on top of,
 *     over, or near a <WATERBODY_SURFACE> when the ambient
 *     <<AIR_TEMPERATURE>> is equal to or below 271,15 kelvin (-2 degrees
 *     Celsius) and the <<WIND_SPEED>> is greater than or equal to 11,32
 *     metres per second (22 knots).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ICE, RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_HEAVY_ICE_ACCRETION_PROBABILITY ((EDCS_Attribute_Code)442)

/*
 * Definition:
 *     The vertical distance from a <LOCATION> on the base (lowest point) of
 *     an <OBJECT> to a <LOCATION> on its top (highest point) that gives the
 *     greatest value of distance; the height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_HEIGHT ((EDCS_Attribute_Code)443)

/*
 * Definition:
 *     The height measured vertically from a <FLOOR> to the <LOCATION> on the
 *     base (lowest point) of an <OBJECT> that gives the least value of
 *     height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_HEIGHT_ABOVE_FLOOR ((EDCS_Attribute_Code)444)

/*
 * Definition:
 *     The <<HEIGHT>> of an <OBJECT> on a <PLANETARY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_HEIGHT_ABOVE_SURFACE_LEVEL ((EDCS_Attribute_Code)445)

/*
 * Definition:
 *     The height of an <OBJECT> measured vertically from a <WATERBODY_FLOOR>
 *     to the base (lowest portion) of the <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION, WATERBODY_FLOOR
 */
#define EAC_HEIGHT_ABOVE_WATERBODY_FLOOR ((EDCS_Attribute_Code)446)

/*
 * Definition:
 *     The distance of an <OBJECT> above a <PLANETARY_SURFACE>; the height
 *     AGL.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_HEIGHT_AGL ((EDCS_Attribute_Code)447)

/*
 * Definition:
 *     The number of <HELICOPTER_LANDING_PAD>s associated with an <OBJECT>;
 *     the helipad count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ABSTRACT_OBJECT, AIR_TRNSP, TRNSP
 */
#define EAC_HELIPAD_COUNT ((EDCS_Attribute_Code)448)

/*
 * Definition:
 *     The ratio, for a particular material <SURFACE> and unit solid angle
 *     about a particular reflection <DIRECTION>, of the reflected
 *     <<RADIANCE>> into that solid angle to the purely diffuse, total
 *     incident <<RADIANCE>> from the hemisphere above that <SURFACE>. This
 *     quantity is also defined as the integral over the incident hemisphere
 *     of the BRDF times the cosine of the angle between the surface normal
 *     and the incidence <DIRECTION> times the differential incident solid
 *     angle. It is a function of the <<REFLECTANCE_ZENITH_ANGLE_LOCAL>> and
 *     <<REFLECTANCE_AZIMUTH_LOCAL>> of the reflected <<RADIANCE>> and is
 *     spectral (a distribution function in <<WAVELENGTH>>); therefore the
 *     quantity is measured in terms of inverse <<WAVELENGTH>> bin size.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: INV_LENGTH
 *
 * Group Membership: ALGORITHM_RELATED, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, SURFACE
 */
#define EAC_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY ((EDCS_Attribute_Code)449)

/*
 * Definition:
 *     The ratio, for a particular material <SURFACE>, of the flux density
 *     reflected into the hemisphere above this <SURFACE> to the flux
 *     density incident upon it from all <DIRECTION>s within this
 *     hemisphere. This quantity is also defined as the ratio A/B, where A
 *     is the integral (over the incident hemisphere) of the incident
 *     <<RADIANCE>> times the cosine of the angle between the surface normal
 *     and the incident <DIRECTION> times the
 *     <<DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY>> times the unit solid
 *     incident angle and B is the same integral without the
 *     <<DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY>>. This quantity may also be
 *     known as the "total" or "bi-hemispherical" reflectivity and is
 *     spectral (a distribution function in <<WAVELENGTH>>); therefore the
 *     quantity is measured in terms of inverse <<WAVELENGTH>> bin size.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: INV_LENGTH
 *
 * Group Membership: ALGORITHM_RELATED, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, SURFACE
 */
#define EAC_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY ((EDCS_Attribute_Code)450)

/*
 * Definition:
 *     The <<DEPTH_BELOW_WATERBODY_SURFACE>> of the lower (bottom) <BOUNDARY>
 *     of a high frequency scattering layer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DEMARCATION, LOCATION, WATERBODY_STATE
 */
#define EAC_HF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH ((EDCS_Attribute_Code)451)

/*
 * Definition:
 *     The <<DEPTH_BELOW_WATERBODY_SURFACE>> of the upper (top) <BOUNDARY> of
 *     a high frequency scattering layer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DEMARCATION, LOCATION, WATERBODY_STATE
 */
#define EAC_HF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH ((EDCS_Attribute_Code)452)

/*
 * Definition:
 *     In a <WATERBODY>, the numeric identifier of a high frequency bottom
 *     loss <REGION>.
 *
 * Value Type: INDEX
 *
 * Group Membership: IDENTIFICATION
 */
#define EAC_HF_BOTTOM_LOSS_REGION_IDENTIFIER ((EDCS_Attribute_Code)453)

/*
 * Definition:
 *     The <<CLOUD_BASE_LEVEL>> of a <HIGH_CLOUD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_HIGH_CLOUD_BASE_LEVEL ((EDCS_Attribute_Code)454)

/*
 * Definition:
 *     The fraction of the sky covered by <HIGH_CLOUD>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_HIGH_CLOUD_COVERAGE ((EDCS_Attribute_Code)455)

/*
 * Definition:
 *     The genus of a <HIGH_CLOUD>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HIGHCLDGENUS_CIRROCUMULUS
 *    EEC_HIGHCLDGENUS_CIRROSTRATUS
 *    EEC_HIGHCLDGENUS_CIRRUS
 *    EEC_HIGHCLDGENUS_NONE_PRESENT
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_HIGH_CLOUD_GENUS ((EDCS_Attribute_Code)456)

/*
 * Definition:
 *     The <<CLOUD_TOP_LEVEL>> of a <HIGH_CLOUD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_HIGH_CLOUD_TOP_LEVEL ((EDCS_Attribute_Code)457)

/*
 * Definition:
 *     The type of observed <HIGH_CLOUD>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HIGHCLDTYOBV_NO_HIGH_CLOUDS
 *    EEC_HIGHCLDTYOBV_CIRRUS_FIBRATUS
 *    EEC_HIGHCLDTYOBV_PATCHY_SPISSATUS
 *    EEC_HIGHCLDTYOBV_CIRRUS_SPISSATUS
 *    EEC_HIGHCLDTYOBV_CIRRUS_UNCINUS
 *    EEC_HIGHCLDTYOBV_CIRRUS_le45_ARC_DEGREE
 *    EEC_HIGHCLDTYOBV_CIRRUS_gt45_ARC_DEGREE
 *    EEC_HIGHCLDTYOBV_CRSTRAT_COVERING_SKY
 *    EEC_HIGHCLDTYOBV_CRSTRAT_INVADING
 *    EEC_HIGHCLDTYOBV_CIRROCUMULUS
 *    EEC_HIGHCLDTYOBV_HIGH_CLOUDS_INVISIBLE
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_HIGH_CLOUD_TYPE_OBSERVED ((EDCS_Attribute_Code)458)

/*
 * Definition:
 *     The greatest <<HEIGHT_AGL>> of all <LOCATION>s in or on the boundary
 *     of an <AIRSPACE>; the highest airspace altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define EAC_HIGHEST_AIRSPACE_ALTITUDE ((EDCS_Attribute_Code)459)

/*
 * Definition:
 *     The <<HIGHEST_AIRSPACE_ALTITUDE>> limit.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, DEMARCATION, LOCATION, TRNSP
 */
#define EAC_HIGHEST_AIRSPACE_ALTITUDE_LIMIT ((EDCS_Attribute_Code)460)

/*
 * Definition:
 *     The highest annual mean level of ground <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, HYDROLOGY
 */
#define EAC_HIGHEST_ANNUAL_GROUND_WATER_LEVEL ((EDCS_Attribute_Code)461)

/*
 * Definition:
 *     The greatest <<ELEVATION>> to any <LOCATION> associated with an
 *     <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_HIGHEST_ELEVATION ((EDCS_Attribute_Code)462)

/*
 * Definition:
 *     The designation of a <NON_EMPTY_SET> of closely related Hindu
 *     religious traditions, often ones which were at one time part of a
 *     single movement but are now separate religious denominations; the
 *     Hinduism denominational family.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HNDDENOMFAM_ARYA_SAMAJ
 *    EEC_HNDDENOMFAM_NEOHINDUISM
 *    EEC_HNDDENOMFAM_SHAIVITE
 *    EEC_HNDDENOMFAM_VAISHNAVITE
 *
 * Group Membership: RELIGION
 */
#define EAC_HINDUISM_DENOMINATIONAL_FAMILY ((EDCS_Attribute_Code)463)

/*
 * Definition:
 *     The historical (climatology) probability of a line of sight free of
 *     <CLOUD>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_HISTORICAL_CLOUD_FREE_LINE_OF_SIGHT_CLIMATOLOGY ((EDCS_Attribute_Code)464)

/*
 * Definition:
 *     The historical significance of a <STRUCTURE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HISTSIGNIF_ANCIENT
 *    EEC_HISTSIGNIF_HISTORIC
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_HISTORICAL_SIGNIFICANCE ((EDCS_Attribute_Code)465)

/*
 * Definition:
 *     The horizontal distance available to pass a load that extends
 *     laterally beyond the wheels of a <GROUND_VEHICLE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_HORIZONTAL_CLEARANCE ((EDCS_Attribute_Code)466)

/*
 * Definition:
 *     An indication that limited <<HORIZONTAL_CLEARANCE>> is present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_HORIZONTAL_CLEARANCE_LIMITED ((EDCS_Attribute_Code)467)

/*
 * Definition:
 *     The maximum distributed load per unit <<AREA>> that a horizontal
 *     <SURFACE> can support; the horizontal load bearing capacity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: RATE_OR_RATIO, SURFACE
 */
#define EAC_HORIZONTAL_LOAD_BEARING_CAPACITY ((EDCS_Attribute_Code)468)

/*
 * Definition:
 *     The number of beds within a <HOSPITAL_BUILDING> or <MEDICAL_FACILITY>.
 *
 * Value Type: COUNT
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define EAC_HOSPITAL_BED_CAPACITY ((EDCS_Attribute_Code)469)

/*
 * Definition:
 *     The ordinal index of the hour within the day, starting with the number
 *     "0" at midnight.
 *
 * Value Type: COUNT
 *
 * Group Membership: TIME
 */
#define EAC_HOUR_WITHIN_DAY ((EDCS_Attribute_Code)470)

/*
 * Definition:
 *     The type of a <HULK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HULKTY_ACCOMMODATION
 *    EEC_HULKTY_FLOATING_BREAKWATER
 *    EEC_HULKTY_HISTORIC_SHIP
 *    EEC_HULKTY_MUSEUM
 *    EEC_HULKTY_RESTAURANT
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_HULK_TYPE ((EDCS_Attribute_Code)471)

/*
 * Definition:
 *     The function for which a <HUMAN> has responsibility.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HUMANFN_ASTRONAUT
 *    EEC_HUMANFN_BORDER_GUARD
 *    EEC_HUMANFN_CIVILIAN
 *    EEC_HUMANFN_DIVER
 *    EEC_HUMANFN_GUARD
 *    EEC_HUMANFN_MILITARY
 *    EEC_HUMANFN_PARACHUTIST
 *    EEC_HUMANFN_PARAMILITARY
 *    EEC_HUMANFN_PILOT
 *    EEC_HUMANFN_POLICE_FORCE
 *    EEC_HUMANFN_RESCUE
 *    EEC_HUMANFN_RESERVIST
 *    EEC_HUMANFN_SWIMMER
 *
 * Group Membership: INDUSTRY
 */
#define EAC_HUMAN_FUNCTION ((EDCS_Attribute_Code)472)

/*
 * Definition:
 *     The expected function of a <HUMAN> in a particular setting or
 *     situation; the human role [SOED, "role", 2.I].
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HUMANROLE_ASTRONAUT
 *    EEC_HUMANROLE_BORDER_GUARD
 *    EEC_HUMANROLE_CIVILIAN
 *    EEC_HUMANROLE_DIVER
 *    EEC_HUMANROLE_GUARD
 *    EEC_HUMANROLE_MILITARY
 *    EEC_HUMANROLE_NATIONAL_GUARD
 *    EEC_HUMANROLE_PARACHUTIST
 *    EEC_HUMANROLE_PARAMILITARY
 *    EEC_HUMANROLE_PILOT
 *    EEC_HUMANROLE_POLICE_FORCE
 *    EEC_HUMANROLE_RESCUE
 *    EEC_HUMANROLE_SWIMMER
 *
 * Group Membership: INDUSTRY
 */
#define EAC_HUMAN_ROLE ((EDCS_Attribute_Code)473)

/*
 * Definition:
 *     The type of <BARRIER> to hydrographic flow that an <OBJECT> presents.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HYDRGBARTY_BARRAGE
 *    EEC_HYDRGBARTY_DAM
 *    EEC_HYDRGBARTY_LOCK
 *    EEC_HYDRGBARTY_MARINE_GATE
 *    EEC_HYDRGBARTY_RAPID
 *    EEC_HYDRGBARTY_WATERFALL
 *    EEC_HYDRGBARTY_WEIR
 *
 * Group Membership: ABSTRACT_OBJECT, HYDROGRAPHIC_ARTEFACT, HYDROLOGY
 */
#define EAC_HYDROGRAPHIC_BARRIER_TYPE ((EDCS_Attribute_Code)474)

/*
 * Definition:
 *     The least <<DEPTH>> of any <LOCATION> on an <OBJECT> that lies below
 *     the <WATERBODY_SURFACE>. The <<DEPTH>> is in reference to a
 *     <SURFACE_DATUM>; the hydrographic depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_HYDROGRAPHIC_DEPTH ((EDCS_Attribute_Code)475)

/*
 * Definition:
 *     A category describing the <<HYDROGRAPHIC_DEPTH>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HYDRGDEPCAT_ABOVE_SURFACE
 *    EEC_HYDRGDEPCAT_AWASH_AT_SOUNDING_DATUM
 *    EEC_HYDRGDEPCAT_COVERS_AND_UNCOVERS
 *    EEC_HYDRGDEPCAT_SUBMERGED
 *
 * Group Membership: LOCATION
 */
#define EAC_HYDROGRAPHIC_DEPTH_CATEGORY ((EDCS_Attribute_Code)476)

/*
 * Definition:
 *     The accuracy or availability of <<HYDROGRAPHIC_DEPTH>> information for
 *     an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HYDRGDEPINF_KNOWN_OTHER
 *    EEC_HYDRGDEPINF_KNOWN_WIRE_DRAG
 *    EEC_HYDRGDEPINF_UNKNOWN
 *    EEC_HYDRGDEPINF_UNKNOWN_BUT_SAFE
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_HYDROGRAPHIC_DEPTH_INFORMATION ((EDCS_Attribute_Code)477)

/*
 * Definition:
 *     The elevation of a hydrographic <OBJECT> that tidal waters cover and
 *     uncover measured to the highest <LOCATION> on the <OBJECT> in
 *     reference to a <SOUNDING_DATUM>; the hydrographic drying height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LITTORAL, LOCATION
 */
#define EAC_HYDROGRAPHIC_DRYING_HEIGHT ((EDCS_Attribute_Code)478)

/*
 * Definition:
 *     The origin of a hydrographic <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HYDRGOBJORIG_CONTROLLED
 *    EEC_HYDRGOBJORIG_MAN_MADE
 *    EEC_HYDRGOBJORIG_NATURAL
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROLOGY
 */
#define EAC_HYDROGRAPHIC_OBJECT_ORIGIN ((EDCS_Attribute_Code)479)

/*
 * Definition:
 *     The type of a <HYDROGRAPHIC_SURVEY_CONTACT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HYDRGSURVCONTY_NOT_SUBMERSIBLE_VESSEL
 *    EEC_HYDRGSURVCONTY_SUBMERSIBLE_VESSEL
 *
 * Group Membership: SURVEY
 */
#define EAC_HYDROGRAPHIC_SURVEY_CONTACT_TYPE ((EDCS_Attribute_Code)480)

/*
 * Definition:
 *     The persistence of a <HYDROLOGIC_OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HYDRLPERM_DRY
 *    EEC_HYDRLPERM_NON_PERENNIAL
 *    EEC_HYDRLPERM_PERENNIAL
 *    EEC_HYDRLPERM_PERENNIAL_OR_PERMANENT
 *    EEC_HYDRLPERM_PERMANENT
 *
 * Group Membership: HYDROLOGY, TIME
 */
#define EAC_HYDROLOGIC_PERMANENCE ((EDCS_Attribute_Code)481)

/*
 * Definition:
 *     The type of a hypsographic portrayal <LINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_HYPSGPRTRYLTY_APPROX_DEPR
 *    EEC_HYPSGPRTRYLTY_APPROX_INDEX
 *    EEC_HYPSGPRTRYLTY_APPROX_INTERM_DEPR
 *    EEC_HYPSGPRTRYLTY_CARRYING_CONTOUR
 *    EEC_HYPSGPRTRYLTY_CONNECTOR
 *    EEC_HYPSGPRTRYLTY_ERRONEOUS
 *    EEC_HYPSGPRTRYLTY_FORM_LINE
 *    EEC_HYPSGPRTRYLTY_INDEX
 *    EEC_HYPSGPRTRYLTY_INDEX_DEPR
 *    EEC_HYPSGPRTRYLTY_INDEX_MOUND
 *    EEC_HYPSGPRTRYLTY_INTERM
 *    EEC_HYPSGPRTRYLTY_INTERM_APPROX
 *    EEC_HYPSGPRTRYLTY_INTERM_DEPR
 *    EEC_HYPSGPRTRYLTY_INTERM_MOUND
 *    EEC_HYPSGPRTRYLTY_SUPP
 *    EEC_HYPSGPRTRYLTY_SUPP_APPROX
 *    EEC_HYPSGPRTRYLTY_SUPP_CARRYING_CONTOUR
 *    EEC_HYPSGPRTRYLTY_SUPP_DEPR
 *    EEC_HYPSGPRTRYLTY_SUPP_DEPR_APPROX
 *    EEC_HYPSGPRTRYLTY_SUPP_ONE_HALF
 *    EEC_HYPSGPRTRYLTY_SUPP_ONE_QUARTER
 *    EEC_HYPSGPRTRYLTY_TRANSITION
 *    EEC_HYPSGPRTRYLTY_TRANSITION_OR_ERRONEOUS
 *
 * Group Membership: LOCATION
 */
#define EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE ((EDCS_Attribute_Code)482)

/*
 * Definition:
 *     The class of an ICAO <AIRSPACE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ICAOARSPCCLS_A
 *    EEC_ICAOARSPCCLS_B
 *    EEC_ICAOARSPCCLS_C
 *    EEC_ICAOARSPCCLS_D
 *    EEC_ICAOARSPCCLS_E
 *    EEC_ICAOARSPCCLS_F
 *    EEC_ICAOARSPCCLS_G
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_ICAO_AIRSPACE_CLASS ((EDCS_Attribute_Code)483)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of a <WATERBODY_SURFACE> that is covered by floating <ICE>.
 *     Zero means no floating <ICE> is present and one means the
 *     <WATERBODY_SURFACE> is completely covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ICE, RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_ICE_COVERAGE_FRACTION ((EDCS_Attribute_Code)484)

/*
 * Definition:
 *     An indication that a <WATERBODY_SURFACE> is covered with <ICE>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ICE, WATERBODY_SURFACE
 */
#define EAC_ICE_COVERED ((EDCS_Attribute_Code)485)

/*
 * Definition:
 *     The root-mean-square <<DEPTH>> of the layer of surface <ICE> within a
 *     delineated <WATERBODY_SURFACE_REGION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_ICE_DRAFT_ROOT_MEAN_SQUARE ((EDCS_Attribute_Code)486)

/*
 * Definition:
 *     The areal density of <ICE_KEEL>s within a delineated
 *     <WATERBODY_SURFACE_REGION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: ICE, RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_ICE_KEEL_DENSITY ((EDCS_Attribute_Code)487)

/*
 * Definition:
 *     The <<THICKNESS>> of a layer of <ICE> on a <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_ICE_LAYER_THICKNESS ((EDCS_Attribute_Code)488)

/*
 * Definition:
 *     The type of any deposit or coating of <ICE> on an <OBJECT> caused by
 *     the impingement and freezing of liquid (usually supercooled)
 *     hydrometeors; the icing type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ICINGTY_CLEAR_ICE
 *    EEC_ICINGTY_HARD_RIME
 *    EEC_ICINGTY_HOAR_FROST
 *    EEC_ICINGTY_ICE_GLAZE
 *    EEC_ICINGTY_RIME
 *    EEC_ICINGTY_SOFT_RIME
 *
 * Group Membership: ICE
 */
#define EAC_ICING_TYPE ((EDCS_Attribute_Code)489)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the transient illumination intensity that is associated
 *     with an <OBJECT> and that has been induced by ignition of a
 *     combustible <MATERIAL>. EXAMPLE Launch of a <MUNITION>. Zero means no
 *     intensity at all and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_IGNITION_FLASH_INTENSITY ((EDCS_Attribute_Code)490)

/*
 * Definition:
 *     The photometric equivalent of irradiance that is obtained by
 *     integrating spectral irradiance weighted by luminous efficiency over
 *     the visible spectrum; the illuminance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RADIANT_ENERGY_FLUENCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_ILLUMINANCE ((EDCS_Attribute_Code)491)

/*
 * Definition:
 *     The amount of <<ILLUMINANCE>> that is direct (rather than diffuse).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RADIANT_ENERGY_FLUENCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_ILLUMINANCE_DIRECT ((EDCS_Attribute_Code)492)

/*
 * Definition:
 *     The <<ILLUMINANCE_DIRECT>> from the principal source of illumination
 *     (for example: the <SUN> and/or an illumination flare).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RADIANT_ENERGY_FLUENCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_ILLUMINANCE_DIRECT_FROM_PRINCIPAL_SOURCE ((EDCS_Attribute_Code)493)

/*
 * Definition:
 *     An indication that an <OBJECT> has been adopted by the IMO.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_IMO_ADOPTED ((EDCS_Attribute_Code)494)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_GEODETIC>> toward the source of incident light
 *     (the <DIRECTION> negative to the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_INCIDENCE_AZIMUTH_GEODETIC ((EDCS_Attribute_Code)495)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_LOCAL>> toward the source of incident light (the
 *     <DIRECTION> negative to the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_INCIDENCE_AZIMUTH_LOCAL ((EDCS_Attribute_Code)496)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_MAGNETIC>> toward the source of incident light
 *     (the <DIRECTION> negative to the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_INCIDENCE_AZIMUTH_MAGNETIC ((EDCS_Attribute_Code)497)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_HORIZONTAL>> toward the source of incident
 *     light (the <DIRECTION> negative to the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_INCIDENCE_ELEV_ANGLE_HORIZONTAL ((EDCS_Attribute_Code)498)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_LOCAL>> toward the source of incident light
 *     (the <DIRECTION> negative to the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_INCIDENCE_ELEV_ANGLE_LOCAL ((EDCS_Attribute_Code)499)

/*
 * Definition:
 *     The angle at a <LOCATION> on a <SURFACE> between the vectors A and B,
 *     where A is the surface normal vector and B is the <DIRECTION> from
 *     which the source light is incident on that point (the negative of the
 *     Poynting vector). The positive sense is clockwise when looking in the
 *     <DIRECTION> of the cross product AxB.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SURFACE
 */
#define EAC_INCIDENCE_ZENITH_ANGLE_LOCAL ((EDCS_Attribute_Code)500)

/*
 * Definition:
 *     The rate of flow (flux) of heat to a <SYSTEM> due to infrared
 *     radiation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, TEMPERATURE
 */
#define EAC_INFRARED_HEAT_FLUX ((EDCS_Attribute_Code)501)

/*
 * Definition:
 *     The permanence of an inland hydrographic <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_INLHYDRGPERM_EPHEMERAL
 *    EEC_INLHYDRGPERM_INTERMITTENT
 *    EEC_INLHYDRGPERM_PERENNIAL
 *
 * Group Membership: TIME, HYDROLOGY
 */
#define EAC_INLAND_HYDROGRAPHIC_PERMANENCE ((EDCS_Attribute_Code)502)

/*
 * Definition:
 *     An indication that an <OBJECT> in <INLAND_WATER> is an obstruction to
 *     the movement of <VESSEL>s.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, HYDROGRAPHIC_TRNSP, HYDROLOGY, TRNSP
 */
#define EAC_INLAND_WATER_OBSTRUCTION ((EDCS_Attribute_Code)503)

/*
 * Definition:
 *     The diameter of a cylindrical or spherical <OBJECT> measured using the
 *     inside <SURFACE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_INSIDE_DIAMETER ((EDCS_Attribute_Code)504)

/*
 * Definition:
 *     The type of an installation <BUOY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_INSTBUOYTY_CATENARY_ANCHOR
 *    EEC_INSTBUOYTY_SINGLE
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_SURFACE
 */
#define EAC_INSTALLATION_BUOY_TYPE ((EDCS_Attribute_Code)505)

/*
 * Definition:
 *     The ratio, for a particular material <SURFACE>, of the differential
 *     reflected <<RADIANCE>> into a unit solid angle about a particular
 *     (reflected) <DIRECTION> to the differential incident flux per unit
 *     surface <<AREA>> (irradiance) from a particular (incident)
 *     <DIRECTION>; bi-directional reflectance distribution function or
 *     directional-directional reflectance. This quantity is a function of
 *     the incident and reflected zenith and azimuth angles. This quantity
 *     is wavelength-band integrated, the units are inverse solid angle, and
 *     the particular band is specified separately.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RECIPROCAL_SOLID_ANGLE
 *
 * Group Membership: ALGORITHM_RELATED, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SURFACE
 */
#define EAC_INTEG_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION ((EDCS_Attribute_Code)506)

/*
 * Definition:
 *     The ratio, for a particular material <SURFACE> and unit solid angle
 *     about a particular incident <DIRECTION>, of the reflected
 *     <<RADIANCE>> into the hemisphere above that <SURFACE> to the incident
 *     <<RADIANCE>>. This quantity is also defined as the integral over the
 *     reflected hemisphere of the BRDF times the cosine of the angle
 *     between the surface normal and the reflection <DIRECTION> times the
 *     differential reflection solid angle. It is a function of the zenith
 *     and azimuth angles of the incident light and is wavelength-band
 *     integrated; therefore the quantity is unitless and the particular
 *     band is specified separately.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, SURFACE
 */
#define EAC_INTEG_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY ((EDCS_Attribute_Code)507)

/*
 * Definition:
 *     The ratio, for a particular material <SURFACE> and unit solid angle
 *     about a particular reflection <DIRECTION>, of the reflected
 *     <<RADIANCE>> into that solid angle to the purely diffuse, total
 *     incident <<RADIANCE>> from the hemisphere above that <SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, SURFACE
 */
#define EAC_INTEG_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY ((EDCS_Attribute_Code)508)

/*
 * Definition:
 *     The ratio, for a particular material <SURFACE> and unit solid angle
 *     about a particular reflection <DIRECTION>, of the reflected
 *     <<RADIANCE>> into that solid angle to the purely diffuse, total
 *     incident <<RADIANCE>> from the hemisphere above that <SURFACE>. This
 *     quantity is also defined as the integral over the incident hemisphere
 *     of the BRDF times the cosine of the angle between the surface normal
 *     and the incidence <DIRECTION> times the differential incident solid
 *     angle. It is a function of the zenith and azimuth angles of the
 *     reflected light and is wavelength-band integrated; therefore the
 *     quantity is unitless and the particular band is specified separately.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, SURFACE
 */
#define EAC_INTEG_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY ((EDCS_Attribute_Code)509)

/*
 * Definition:
 *     The traversability provided at a four-way <ROAD_INTERCHANGE> between
 *     the entry segments of adjacent <ROAD>s. Each entry segment
 *     necessarily connects to an opposing exiting segment (two pairs are
 *     thus formed) and optionally to either of the adjacent left or right
 *     entry segments. The first entry segment is that entering the
 *     interchange in the <DIRECTION> of the associated <BRIDGE_SPAN>; the
 *     remaining three entry segments are ordered in a counter-clockwise
 *     <DIRECTION> with the third entry serving as the exit for the first
 *     entry, and similarly the fourth for the second. Formatted in a Basic
 *     Latin string containing exactly four characters with the i^(th)
 *     character corresponding to traversability from the i^(th) entry (i =
 *     1, 2, 3 and 4). Each character position in the string contains one of
 *     the characters N (no turns), R (right turn), L (left turn) or B (both
 *     right and left turn). EXAMPLE "NRBL" means no turns from first entry;
 *     right turn from second entry; right and left turn from third entry;
 *     and left turn from fourth entry.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_INTERCHANGE_TRAVERSABILITY ((EDCS_Attribute_Code)510)

/*
 * Definition:
 *     The reason an <OBJECT> is of interest.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_INTRSTTY_FAMOUS_RESIDENCE
 *    EEC_INTRSTTY_HISTORIC_BATTLEFIELD
 *    EEC_INTRSTTY_HISTORIC_MONUMENT
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_INTEREST_TYPE ((EDCS_Attribute_Code)511)

/*
 * Definition:
 *     The number of complete exchanges of the interior <AIR> in a
 *     <STRUCTURE> per unit time; the interior air exchange rate.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RATE
 *
 * Group Membership: ATMOSPHERE, BUILDING_COMPONENT, RATE_OR_RATIO
 */
#define EAC_INTERIOR_AIR_EXCHANGE_RATE ((EDCS_Attribute_Code)512)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the general internal <LIGHTING> of an
 *     <OBJECT>. Zero means unlit and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_INTERIOR_LIGHTING_INTENSITY ((EDCS_Attribute_Code)513)

/*
 * Definition:
 *     The type of <MATERIAL> and/or techniques used to construct an
 *     <INTERIOR_WALL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_INTRWALLCNSTCT_CONCRETE
 *    EEC_INTRWALLCNSTCT_GYPSUM_ON_METAL
 *    EEC_INTRWALLCNSTCT_GYPSUM_ON_WOOD
 *    EEC_INTRWALLCNSTCT_HOLLOW_CONCRETE_BLOCK
 *    EEC_INTRWALLCNSTCT_HOLLOW_FIRED_CLAY_BLOCK
 *    EEC_INTRWALLCNSTCT_LATH_PLASTER
 *    EEC_INTRWALLCNSTCT_MASONRY
 *    EEC_INTRWALLCNSTCT_REINFORCED_CONCRETE
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_INTERIOR_WALL_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)514)

/*
 * Definition:
 *     The <<SPEED>> of any internal convective flow within an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_INTERNAL_FLOW_SPEED ((EDCS_Attribute_Code)515)

/*
 * Definition:
 *     The internal <<TEMPERATURE>> of a <MATERIAL> or <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL, TEMPERATURE
 */
#define EAC_INTERNAL_TEMPERATURE ((EDCS_Attribute_Code)516)

/*
 * Definition:
 *     The <<SPEED>> of eastward drift of the electromagnetic scintillation
 *     density irregularities in an <IONOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, RATE_OR_RATIO, SPACE
 */
#define EAC_IONOSPHERIC_SCINT_EAST_DRIFT ((EDCS_Attribute_Code)517)

/*
 * Definition:
 *     The upper limit on the size of the electromagnetic scintillation
 *     density irregularities in an <IONOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, EM_PHENOMENON, SPACE
 */
#define EAC_IONOSPHERIC_SCINT_MAXIMUM_SIZE ((EDCS_Attribute_Code)518)

/*
 * Definition:
 *     The <<SPEED>> of northward drift of the electromagnetic scintillation
 *     density irregularities in an <IONOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, RATE_OR_RATIO, SPACE
 */
#define EAC_IONOSPHERIC_SCINT_NORTH_DRIFT ((EDCS_Attribute_Code)519)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of the equivalent electromagnetic scintillation
 *     phase screen in an <IONOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, LOCATION, SPACE
 */
#define EAC_IONOSPHERIC_SCINT_PHASE_ALTITUDE ((EDCS_Attribute_Code)520)

/*
 * Definition:
 *     The angle between the electromagnetic scintillation irregularities and
 *     <LINE>s of the local <MAGNETIC_FIELD>; the ionospheric scintillation
 *     structure angle. If zero, all ionospheric plasma density
 *     irregularities are aligned along the local <MAGNETIC_FIELD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON
 */
#define EAC_IONOSPHERIC_SCINT_STRUCTURE_ANGLE ((EDCS_Attribute_Code)521)

/*
 * Definition:
 *     The <<SPEED>> of upward drift of the electromagnetic scintillation
 *     density irregularities in an <IONOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO, SPACE
 */
#define EAC_IONOSPHERIC_SCINT_UP_DRIFT ((EDCS_Attribute_Code)522)

/*
 * Definition:
 *     The method used to supply crops with <WATER>; the irrigation method.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_IRRIGMETH_DITCH
 *    EEC_IRRIGMETH_SPRINKLER
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define EAC_IRRIGATION_METHOD ((EDCS_Attribute_Code)523)

/*
 * Definition:
 *     The designation of a <NON_EMPTY_SET> of closely related Islamic
 *     religious denominations, often ones which were at one time part of a
 *     single movement but are now separate religious denominations; the
 *     Islamic denominational family.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ISLMDENOMFAM_AHMADIYA
 *    EEC_ISLMDENOMFAM_ALAWITE
 *    EEC_ISLMDENOMFAM_BADAWIYA
 *    EEC_ISLMDENOMFAM_HANAFITE
 *    EEC_ISLMDENOMFAM_HANBALITE
 *    EEC_ISLMDENOMFAM_ISMAILI
 *    EEC_ISLMDENOMFAM_ITHNA_ASHARI
 *    EEC_ISLMDENOMFAM_MADARIYA
 *    EEC_ISLMDENOMFAM_MALAKITE
 *    EEC_ISLMDENOMFAM_NATION_OF_ISLAM
 *    EEC_ISLMDENOMFAM_QADIRIYA
 *    EEC_ISLMDENOMFAM_SHAFFITE
 *    EEC_ISLMDENOMFAM_SHIA
 *    EEC_ISLMDENOMFAM_SUFI
 *    EEC_ISLMDENOMFAM_SUNNI
 *    EEC_ISLMDENOMFAM_WAHABI
 *    EEC_ISLMDENOMFAM_ZAYDI
 *
 * Group Membership: RELIGION
 */
#define EAC_ISLAMIC_DENOMINATIONAL_FAMILY ((EDCS_Attribute_Code)524)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of a standard isobaric <SURFACE> in units
 *     proportional to the potential energy of unit <<MASS>> (geopotential)
 *     at that <SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: GEOPOTENTIAL_ENERGY_LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_ISOBARIC_SURFACE_LEVEL ((EDCS_Attribute_Code)525)

/*
 * Definition:
 *     An indication that a <FACILITY> is isolated.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_ISOLATED ((EDCS_Attribute_Code)526)

/*
 * Definition:
 *     An indication that a communication line is in the open (isolated), as
 *     opposed to being in the midst of other <OBJECT>s (not isolated).
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: COMMUNICATION, INFRASTRUCTURE
 */
#define EAC_ISOLATED_COMMUNICATION_LINE ((EDCS_Attribute_Code)527)

/*
 * Definition:
 *     The designation of a <NON_EMPTY_SET> of closely related Jain religious
 *     denominations, often ones which were at one time part of a single
 *     movement but are now separate religious denominations; the Jainism
 *     denominational family.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_JAINDENOMFAM_DIGAMBARA
 *    EEC_JAINDENOMFAM_SVETAMBARA
 *
 * Group Membership: RELIGION
 */
#define EAC_JAINISM_DENOMINATIONAL_FAMILY ((EDCS_Attribute_Code)528)

/*
 * Definition:
 *     The designation of a <NON_EMPTY_SET> of closely related Jewish
 *     religious denominations, often ones which were at one time part of a
 *     single movement but are now separate religious denominations; the
 *     Judaism denominational family.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_JUDDENOMFAM_ASHKENHAZI
 *    EEC_JUDDENOMFAM_CONSERVATIVE
 *    EEC_JUDDENOMFAM_ORIENTAL
 *    EEC_JUDDENOMFAM_ORTHODOX
 *    EEC_JUDDENOMFAM_REFORM
 *    EEC_JUDDENOMFAM_SEFARDI
 *    EEC_JUDDENOMFAM_UNAFFILIATED
 *
 * Group Membership: RELIGION
 */
#define EAC_JUDAISM_DENOMINATIONAL_FAMILY ((EDCS_Attribute_Code)529)

/*
 * Definition:
 *     The <<JULIAN_DAY>> number for the preceding noon plus the fraction of
 *     the day since that instant; the Julian date (terrestrial time). A
 *     Julian date (terrestrial time) begins at 12 hours 0 minutes 0
 *     seconds, and the length of a day is 86 400 seconds.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: TIME
 */
#define EAC_JULIAN_DATE_TERRESTRIAL_TIME ((EDCS_Attribute_Code)530)

/*
 * Definition:
 *     The Julian day number associated with the solar day defined as the
 *     number assigned to a day in a continuous count of days beginning with
 *     the Julian day number 0 assigned to the day starting at Greenwich
 *     mean noon on 1 January 4 713 BCE, Julian proleptic calendar -4 712.
 *
 * Value Type: COUNT
 *
 * Group Membership: TIME
 */
#define EAC_JULIAN_DAY ((EDCS_Attribute_Code)531)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional coverage of kelp within a delineated <WATERBODY_REGION>.
 *     Zero means no kelp is present and one means the <WATERBODY_REGION> is
 *     completely covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIVING_ORGANISM, PLANT, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_KELP_COVERAGE ((EDCS_Attribute_Code)532)

/*
 * Definition:
 *     An indication that a fixed or moveable ladder is present within or on
 *     an <OBJECT>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_LADDER_PRESENT ((EDCS_Attribute_Code)533)

/*
 * Definition:
 *     The parameter used in the Lambert Law equation for calculating
 *     <WATERBODY_FLOOR> acoustic scattering; the Lambert Law constant.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_FLOOR
 */
#define EAC_LAMBERT_LAW_CONSTANT ((EDCS_Attribute_Code)534)

/*
 * Definition:
 *     The length of a <LAND_TRANSPORTATION_ROUTE> segment having a slope
 *     (rise/run) greater than 0,07 for a <ROAD>, or greater than 0,03 for a
 *     <RAILWAY>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_LAND_ROUTE_SLOPE_SEGMENT_LENGTH ((EDCS_Attribute_Code)535)

/*
 * Definition:
 *     The type of a <LAND_TRANSPORTATION_ROUTE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LDRTETY_TRAIL
 *    EEC_LDRTETY_SECONDARY_ROAD
 *    EEC_LDRTETY_PRIMARY_ROAD
 *    EEC_LDRTETY_SUPER_HIGHWAY
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_LAND_ROUTE_TYPE ((EDCS_Attribute_Code)536)

/*
 * Definition:
 *     The type of weather conditions under which a
 *     <LAND_TRANSPORTATION_ROUTE> is usable.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LDRTEUSBLWXTY_ALL
 *    EEC_LDRTEUSBLWXTY_ALL_LIMITED_TRAFFIC
 *    EEC_LDRTEUSBLWXTY_FAIR_AND_DRY_ONLY
 *    EEC_LDRTEUSBLWXTY_WINTER_ONLY
 *
 * Group Membership: ATMOSPHERE, LAND_TRNSP, TRNSP
 */
#define EAC_LAND_ROUTE_USABLE_WEATHER_TYPE ((EDCS_Attribute_Code)537)

/*
 * Definition:
 *     The composition of the <SURFACE> of a <LAND_TRANSPORTATION_ROUTE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LDTRNSPRTESRF_ASPHALT
 *    EEC_LDTRNSPRTESRF_BITUMINOUS
 *    EEC_LDTRNSPRTESRF_BRICK
 *    EEC_LDTRNSPRTESRF_CLAY
 *    EEC_LDTRNSPRTESRF_COMPOSITE_ge_50_PCT_PERMANENT
 *    EEC_LDTRNSPRTESRF_COMPOSITE_lt_50_PCT_PERMANENT
 *    EEC_LDTRNSPRTESRF_CONCRETE
 *    EEC_LDTRNSPRTESRF_CORAL
 *    EEC_LDTRNSPRTESRF_CORDUROY
 *    EEC_LDTRNSPRTESRF_GRADED_SOIL
 *    EEC_LDTRNSPRTESRF_GRAVEL
 *    EEC_LDTRNSPRTESRF_HARD
 *    EEC_LDTRNSPRTESRF_ICE
 *    EEC_LDTRNSPRTESRF_LATERITE
 *    EEC_LDTRNSPRTESRF_LOOSE
 *    EEC_LDTRNSPRTESRF_MACADAM
 *    EEC_LDTRNSPRTESRF_MEMBRANE
 *    EEC_LDTRNSPRTESRF_MIXED_IN_PLACE
 *    EEC_LDTRNSPRTESRF_MIXED_CONCRETE_ASPHALT
 *    EEC_LDTRNSPRTESRF_NATURAL
 *    EEC_LDTRNSPRTESRF_PERMANENT
 *    EEC_LDTRNSPRTESRF_SAND
 *    EEC_LDTRNSPRTESRF_SNOW
 *    EEC_LDTRNSPRTESRF_SOD
 *    EEC_LDTRNSPRTESRF_STEEL_GRATING
 *    EEC_LDTRNSPRTESRF_STEEL_PLANKING
 *    EEC_LDTRNSPRTESRF_TEMPORARY
 *    EEC_LDTRNSPRTESRF_UNGRADED
 *    EEC_LDTRNSPRTESRF_UNPAVED
 *    EEC_LDTRNSPRTESRF_WOOD
 *
 * Group Membership: LAND_TRNSP, MATERIAL, SURFACE_MATERIAL, TRNSP
 */
#define EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE ((EDCS_Attribute_Code)538)

/*
 * Definition:
 *     An indication that a median divider is present between multiple
 *     <ROUTE_LANE>s or tracks in a <LAND_TRANSPORTATION_ROUTE>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_LAND_TRNSP_MEDIAN_PRESENT ((EDCS_Attribute_Code)539)

/*
 * Definition:
 *     The <<WIDTH>> of the divider between multiple <ROUTE_LANE>s or tracks
 *     in a <LAND_TRANSPORTATION_ROUTE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_LAND_TRNSP_MEDIAN_WIDTH ((EDCS_Attribute_Code)540)

/*
 * Definition:
 *     The type of a <LANDING_CRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LNDGCRFTTY_ASSAULT
 *    EEC_LNDGCRFTTY_ASSAULT_CARGO
 *    EEC_LNDGCRFTTY_DOCK_LANDING
 *    EEC_LNDGCRFTTY_LCAC
 *    EEC_LNDGCRFTTY_TANK_LANDING
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_LANDING_CRAFT_TYPE ((EDCS_Attribute_Code)541)

/*
 * Definition:
 *     The <<LENGTH>> of a <RUNWAY> that is declared available and suitable
 *     for the ground run of an <AIRCRAFT> landing; the landing distance
 *     available.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, DIMENSION, TRNSP
 */
#define EAC_LANDING_DISTANCE_AVAILABLE ((EDCS_Attribute_Code)542)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of external <LIGHTING> on an <AIRCRAFT> that is
 *     used to illuminate the <LAND> during landing procedures. Zero means
 *     unlit and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_LANDING_LIGHT_INTENSITY ((EDCS_Attribute_Code)543)

/*
 * Definition:
 *     The number of <ROUTE_LANE>s in a <TRANSPORTATION_ROUTE>; the lane
 *     count.
 *
 * Value Type: COUNT
 *
 * Group Membership: TRNSP
 */
#define EAC_LANE_COUNT ((EDCS_Attribute_Code)544)

/*
 * Definition:
 *     The type of lane marking on a <ROAD> or <RUNWAY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LANEMKTY_CENTRE_DASH
 *    EEC_LANEMKTY_CENTRE_SOLID
 *    EEC_LANEMKTY_SIDES_SOLID
 *    EEC_LANEMKTY_SIDES_SOLID_CTR_DASH
 *    EEC_LANEMKTY_SIDES_SOLID_CTR_SOLID
 *
 * Group Membership: AIR_TRNSP, LAND_TRNSP, TRNSP
 */
#define EAC_LANE_MARKING_TYPE ((EDCS_Attribute_Code)545)

/*
 * Definition:
 *     The component of <<ACCUM_PRECIP_DENSITY>> caused by a non-convective
 *     meteorological phenomenon in a mesoscale or larger <REGION>; the
 *     large scale precipitation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_LARGE_SCALE_PRECIPITATION ((EDCS_Attribute_Code)546)

/*
 * Definition:
 *     The areal density of large tanker <WATER_SURFACE_VESSEL>s (dead weight
 *     greater than 159 000 kilograms (approximately 175 000 tons) and less
 *     than or equal to 318 000 kilograms (approximately 350 000 tons);
 *     <<LENGTH>> of approximately 300 to 325 metres) in a
 *     <WATERBODY_SURFACE_REGION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_LARGE_TANKER_DENSITY ((EDCS_Attribute_Code)547)

/*
 * Definition:
 *     The rate of heat flow per unit <<MASS>> for a <SYSTEM> in a
 *     reversible, isobaric-isothermic change of phase; the latent heat flux.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: RATE_OR_RATIO, TEMPERATURE
 */
#define EAC_LATENT_HEAT_FLUX ((EDCS_Attribute_Code)548)

/*
 * Definition:
 *     The amount of energy per unit <<MASS>> of an <OBJECT> required to
 *     change its <<PHYSICAL_STATE>> from solid to liquid; the latent heat
 *     of fusion.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPECIFIC_ENERGY
 *
 * Group Membership: ABSTRACT_OBJECT, FLUID_CONDITION, TEMPERATURE
 */
#define EAC_LATENT_HEAT_FUSION ((EDCS_Attribute_Code)549)

/*
 * Definition:
 *     The amount of energy per unit <<MASS>> of an <OBJECT> required to
 *     change its <<PHYSICAL_STATE>> from solid to gas; the latent heat of
 *     sublimation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPECIFIC_ENERGY
 *
 * Group Membership: ABSTRACT_OBJECT, FLUID_CONDITION, TEMPERATURE
 */
#define EAC_LATENT_HEAT_SUBLIMATION ((EDCS_Attribute_Code)550)

/*
 * Definition:
 *     The amount of energy per unit <<MASS>> of an <OBJECT> required to
 *     change its <<PHYSICAL_STATE>> from liquid to gas; the latent heat of
 *     vapourization.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPECIFIC_ENERGY
 *
 * Group Membership: ABSTRACT_OBJECT, FLUID_CONDITION, TEMPERATURE
 */
#define EAC_LATENT_HEAT_VAPOURIZATION ((EDCS_Attribute_Code)551)

/*
 * Definition:
 *     The single sided leaf area (projected) per unit <<AREA>> of <LAND>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIVING_ORGANISM, PLANT, RATE_OR_RATIO
 */
#define EAC_LEAF_AREA_INDEX ((EDCS_Attribute_Code)552)

/*
 * Definition:
 *     The angle from the horizontal plane to the portion above the mean
 *     level of the <WATERBODY_SURFACE> of the left <WATERBODY_BANK> (facing
 *     downstream) of a <WATERCOURSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_LEFT_ABOVE_BANK_ANGLE ((EDCS_Attribute_Code)553)

/*
 * Definition:
 *     The <<TERRAIN_SLOPE>> of the portion above the mean level of the
 *     <WATERBODY_SURFACE> of the left <WATERBODY_BANK> (facing downstream)
 *     of a <WATERCOURSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_LEFT_ABOVE_BANK_SLOPE ((EDCS_Attribute_Code)554)

/*
 * Definition:
 *     The <<HEIGHT>> of the left <WATERBODY_BANK> (facing downstream) of a
 *     <WATERCOURSE> measured from the mean level of the <WATER> to the
 *     first break in <<TERRAIN_SLOPE>> above the mean level of the <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION
 */
#define EAC_LEFT_BANK_HEIGHT ((EDCS_Attribute_Code)555)

/*
 * Definition:
 *     The <<TERRAIN_SLOPE>> of the left <WATERBODY_BANK> (facing downstream)
 *     of a <WATERCOURSE> measured from the mean level of the <WATER> to the
 *     first accessible break in slope above the mean level of the <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_LEFT_BANK_SLOPE ((EDCS_Attribute_Code)556)

/*
 * Definition:
 *     The <<SOIL_CONE_INDEX>> of a left <WATERBODY_BANK>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: MATERIAL, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define EAC_LEFT_BANK_SOIL_CONE_INDEX ((EDCS_Attribute_Code)557)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional density of <VEGETATION> found on the left <WATERBODY_BANK>
 *     (facing downstream) of a <WATERCOURSE> as a linearly-scaled fraction
 *     of bank <<AREA>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIVING_ORGANISM, PLANT, RATE_OR_RATIO
 */
#define EAC_LEFT_BANK_VEGETATION_DENSITY ((EDCS_Attribute_Code)558)

/*
 * Definition:
 *     The angle from the horizontal plane to the portion below the mean
 *     level of the <WATERBODY_SURFACE> of the left <WATERBODY_BANK> (facing
 *     downstream) of a <WATERCOURSE>, below the mean level of the <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_LEFT_BELOW_BANK_ANGLE ((EDCS_Attribute_Code)559)

/*
 * Definition:
 *     The <<TERRAIN_SLOPE>> of the portion below the mean level of the
 *     <WATERBODY_SURFACE> of the left <WATERBODY_BANK> (facing downstream)
 *     of a <WATERCOURSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_LEFT_BELOW_BANK_SLOPE ((EDCS_Attribute_Code)560)

/*
 * Definition:
 *     The <<TERRAIN_SLOPE>> of the left bank of a <TERRAIN_SURFACE_OBJECT>
 *     (for example: a <TERRAIN_CUT> and/or an <EMBANKMENT>).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: PHYSIOGRAPHY, RATE_OR_RATIO
 */
#define EAC_LEFT_TERRAIN_BANK_SLOPE ((EDCS_Attribute_Code)561)

/*
 * Definition:
 *     The length measured in the horizontal plane of the longer of two
 *     orthogonal linear axes of an <OBJECT>; the length. For a square
 *     <OBJECT>, either axis may be measured. For a round <OBJECT>, the
 *     <<OUTSIDE_DIAMETER>> is measured. For a <BRIDGE>, the distance
 *     between the <BRIDGE_PIER>s is measured.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_LENGTH ((EDCS_Attribute_Code)562)

/*
 * Definition:
 *     The <<DEPTH_BELOW_WATERBODY_SURFACE>> of the lower (bottom) <BOUNDARY>
 *     of a low frequency scattering layer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DEMARCATION, LOCATION, WATERBODY_STATE
 */
#define EAC_LF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH ((EDCS_Attribute_Code)563)

/*
 * Definition:
 *     The <<DEPTH_BELOW_WATERBODY_SURFACE>> of the upper (top) boundary of a
 *     low frequency scattering layer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DEMARCATION, LOCATION, WATERBODY_STATE
 */
#define EAC_LF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH ((EDCS_Attribute_Code)564)

/*
 * Definition:
 *     In a <WATERBODY>, the numeric identifier of a low frequency bottom
 *     loss <REGION>.
 *
 * Value Type: INDEX
 *
 * Group Membership: IDENTIFICATION, WATERBODY_STATE
 */
#define EAC_LF_BOTTOM_LOSS_REGION_IDENTIFIER ((EDCS_Attribute_Code)565)

/*
 * Definition:
 *     The type of a <LIFT> based on the kind of <OBJECT>s it is intended to
 *     transport.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LIFTTY_FREIGHT
 *    EEC_LIFTTY_PERSONNEL
 *
 * Group Membership: TRNSP
 */
#define EAC_LIFT_TYPE ((EDCS_Attribute_Code)566)

/*
 * Definition:
 *     A stability index used to determine the occurrence of severe weather;
 *     the lifted atmosphere stability index. The lifted atmosphere
 *     stability index, LI, is defined by LI = T[sub(5)] -
 *     LT[sub(S)](degrees Celsius), where T[sub(5)] is the dry-bulb
 *     <<AIR_TEMPERATURE>> at 500 hectopascals and LT[sub(S)] is the
 *     <<AIR_TEMPERATURE>> of a parcel of <AIR> at the <PLANETARY_SURFACE>
 *     lifted adiabatically to 500 hectopascals.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_LIFTED_ATMOSPHERE_STABILITY_INDEX ((EDCS_Attribute_Code)567)

/*
 * Definition:
 *     The maximum weight that an <EQUIPMENT> can lift; the lifting capacity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_LIFTING_CAPACITY ((EDCS_Attribute_Code)568)

/*
 * Definition:
 *     Twice the angle from the beam axis at which the intensity of a <LIGHT>
 *     is 10 percent of its maximum value; for an omni-directional light,
 *     360 arc degrees; the light beam spread.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_BEAM_SPREAD ((EDCS_Attribute_Code)569)

/*
 * Definition:
 *     The colour emitted from a <LIGHT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTCOLR_AMBER
 *    EEC_LGTCOLR_BLUE
 *    EEC_LGTCOLR_GREEN
 *    EEC_LGTCOLR_MAGENTA
 *    EEC_LGTCOLR_ORANGE
 *    EEC_LGTCOLR_RED
 *    EEC_LGTCOLR_WHITE
 *    EEC_LGTCOLR_YELLOW
 *
 * Group Membership: COLOUR, LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_COLOUR ((EDCS_Attribute_Code)570)

/*
 * Definition:
 *     The <<ELEVATION>> of a <LIGHT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, LOCATION
 */
#define EAC_LIGHT_ELEVATION ((EDCS_Attribute_Code)571)

/*
 * Definition:
 *     The exhibition condition of a <LIGHT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTEXHIBCND_CONSTANT
 *    EEC_LGTEXHIBCND_DAYTIME
 *    EEC_LGTEXHIBCND_NIGHT_TIME
 *    EEC_LGTEXHIBCND_REDUCED_VISIBILITY
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_EXHIBITION_CONDITION ((EDCS_Attribute_Code)572)

/*
 * Definition:
 *     The function of a <LIGHT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTFN_AEROLIGHT
 *    EEC_LGTFN_AIR_OBSTRUCTION
 *    EEC_LGTFN_BEARING
 *    EEC_LGTFN_DIRECTIONAL
 *    EEC_LGTFN_EMERGENCY
 *    EEC_LGTFN_FLOOD
 *    EEC_LGTFN_FOG_DETECTOR
 *    EEC_LGTFN_FRONT
 *    EEC_LGTFN_FRONT_OR_LOWER
 *    EEC_LGTFN_LEADING
 *    EEC_LGTFN_LOWER
 *    EEC_LGTFN_MIDDLE
 *    EEC_LGTFN_REAR
 *    EEC_LGTFN_REAR_OR_UPPER
 *    EEC_LGTFN_SPOTLIGHT
 *    EEC_LGTFN_STRIP
 *    EEC_LGTFN_SUBSIDIARY
 *    EEC_LGTFN_UPPER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_FUNCTION ((EDCS_Attribute_Code)573)

/*
 * Definition:
 *     The probability of light accretion of <ICE> on the <SURFACE>s of
 *     <MARINE_OBJECT>s. Such accretion can occur on <SURFACE>s on top of,
 *     over, or near a <WATERBODY_SURFACE> when the ambient
 *     <<AIR_TEMPERATURE>> is equal to or below 271,15 kelvin (-2 degrees
 *     Celsius) and the <<WIND_SPEED>> is greater than or equal to 11,32
 *     metres per second (22 knots).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ICE, MATERIAL, RATE_OR_RATIO, SURFACE_MATERIAL, WATERBODY_SURFACE
 */
#define EAC_LIGHT_ICE_ACCRETION_PROBABILITY ((EDCS_Attribute_Code)574)

/*
 * Definition:
 *     The number of <LIGHT>s of identical character that exist as a
 *     co-located <SET>; the light multiplicity.
 *
 * Value Type: COUNT
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_MULTIPLICITY ((EDCS_Attribute_Code)575)

/*
 * Definition:
 *     The type of sequence, grouping, and/or distinctive character of a
 *     <LIGHT>; the light pattern.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTPAT_ALTERNATING
 *    EEC_LGTPAT_COMPOSITE_GROUP_FLASH
 *    EEC_LGTPAT_COMPOSITE_GROUP_OCCULTING
 *    EEC_LGTPAT_DIRECTIONAL
 *    EEC_LGTPAT_DIRECTIONAL_MOIRE
 *    EEC_LGTPAT_FIXED
 *    EEC_LGTPAT_FIXED_ALTERNATING_FLASHING
 *    EEC_LGTPAT_FIXED_FLASHING
 *    EEC_LGTPAT_FIXED_GROUP_FLASHING
 *    EEC_LGTPAT_FIXED_LONG_FLASHING
 *    EEC_LGTPAT_FLASH_ALTERNATING
 *    EEC_LGTPAT_FLASHING
 *    EEC_LGTPAT_FLASHING_LONG_FLASH
 *    EEC_LGTPAT_GROUP_ALTERNATING
 *    EEC_LGTPAT_GROUP_FLASHING
 *    EEC_LGTPAT_GROUP_OCCULTING
 *    EEC_LGTPAT_GROUP_QUICK_FLASH
 *    EEC_LGTPAT_GROUP_VERY_QUICK
 *    EEC_LGTPAT_INTENSIFIED
 *    EEC_LGTPAT_INTERRUPTED_QUICK_FLASH
 *    EEC_LGTPAT_INTERRUPTED_ULTRA_QUICK
 *    EEC_LGTPAT_INTERRUPTED_VERY_QUICK
 *    EEC_LGTPAT_ISOPHASE
 *    EEC_LGTPAT_LIGHTED
 *    EEC_LGTPAT_LONG_FLASHING
 *    EEC_LGTPAT_LONG_FLASHING_ALTERNATING
 *    EEC_LGTPAT_MORSE_CODE
 *    EEC_LGTPAT_OCCULTING
 *    EEC_LGTPAT_OCCULTING_ALTERNATING
 *    EEC_LGTPAT_OCCULTING_FLASH
 *    EEC_LGTPAT_QUICK_FLASH
 *    EEC_LGTPAT_QUICK_PLUS_LONG_FLASH
 *    EEC_LGTPAT_THREE_FIXED_HORIZONTAL
 *    EEC_LGTPAT_THREE_FIXED_VERTICAL
 *    EEC_LGTPAT_TWO_FIXED_HORIZONTAL
 *    EEC_LGTPAT_TWO_FIXED_VERTICAL
 *    EEC_LGTPAT_ULTRA_PLUS_LONG_FLASH
 *    EEC_LGTPAT_ULTRA_QUICK_FLASH
 *    EEC_LGTPAT_UNLIGHTED
 *    EEC_LGTPAT_VERY_QUICK_FLASH
 *    EEC_LGTPAT_VERY_QUICK_PLUS_LONG_FLASH
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_PATTERN ((EDCS_Attribute_Code)576)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> occupied by an entire cycle of intervals of
 *     light and dark of a <LIGHT>; the light period.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, TIME
 */
#define EAC_LIGHT_PERIOD ((EDCS_Attribute_Code)577)

/*
 * Definition:
 *     The relative horizontal <LOCATION> of a <LIGHT> in a range of two or
 *     three <LIGHT>s; the light relative position.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTRELLOC_FRONT
 *    EEC_LGTRELLOC_MIDDLE
 *    EEC_LGTRELLOC_REAR
 *    EEC_LGTRELLOC_SHARED
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_RELATIVE_LOCATION ((EDCS_Attribute_Code)578)

/*
 * Definition:
 *     The horizontal angular sector limits of the visibility of a <LIGHT>;
 *     limits of sectors and arcs of visibility are arranged clockwise and
 *     are given from seaward toward the <LIGHT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, DEMARCATION, LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_SECTOR_ANGLE ((EDCS_Attribute_Code)579)

/*
 * Definition:
 *     An indication that a <LIGHT> is supervised.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_SUPERVISED ((EDCS_Attribute_Code)580)

/*
 * Definition:
 *     The type of a <LIGHT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTTY_DISPLAY
 *    EEC_LGTTY_SPOTLIGHT
 *    EEC_LGTTY_STREET_LAMP
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_TYPE ((EDCS_Attribute_Code)581)

/*
 * Definition:
 *     The type of specific visibility of a <LIGHT>, with respect to the
 *     intensity of the <LIGHT> and ease of recognition.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTVIS_DELIBERATELY_RESTRICTED
 *    EEC_LGTVIS_FAINT
 *    EEC_LGTVIS_HIGH_INTENSITY
 *    EEC_LGTVIS_INTENSIFIED
 *    EEC_LGTVIS_LOW_INTENSITY
 *    EEC_LGTVIS_OBSCURED
 *    EEC_LGTVIS_PARTIALLY_OBSCURED
 *    EEC_LGTVIS_UNINTENSIFIED
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_VISIBILITY ((EDCS_Attribute_Code)582)

/*
 * Definition:
 *     A set of two numbers defining the range of visibility at a <LIGHT> in
 *     nautical miles; formatted in a Basic Latin string as a pair of
 *     numbers separated by a slash ("/") if only two visibilities exist or
 *     by a dash ("-") separating the greatest and least visibilities if
 *     three or more visibilities exist.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHT_VISIBILITY_RANGES ((EDCS_Attribute_Code)583)

/*
 * Definition:
 *     The qualitative characterization of lighting intensity.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTCHR_BRIGHTLY_LIT
 *    EEC_LGTCHR_DIMLY_LIT
 *    EEC_LGTCHR_LIGHTS_OFF
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_LIGHTING_CHARACTERIZATION ((EDCS_Attribute_Code)584)

/*
 * Definition:
 *     The strength of the discharge current flowing in a stroke of
 *     <LIGHTNING>, usually in the return stroke.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: ELECTRIC_CURRENT
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define EAC_LIGHTNING_CURRENT_STRENGTH ((EDCS_Attribute_Code)585)

/*
 * Definition:
 *     The quantity of the chi-square statistical agreement between
 *     cloud-to-ground detections of <LIGHTNING>; the lightning data
 *     consistency.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ALGORITHM_RELATED, ATMOSPHERE, EM_PHENOMENON
 */
#define EAC_LIGHTNING_DATA_CONSISTENCY ((EDCS_Attribute_Code)586)

/*
 * Definition:
 *     The number of detectors reporting a <LIGHTNING> discharge; the
 *     lightning detector count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define EAC_LIGHTNING_DETECTOR_COUNT ((EDCS_Attribute_Code)587)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the semi-major axis of the error ellipse
 *     of the <LOCATION> of a stroke of <LIGHTNING>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, ATMOSPHERE, EM_PHENOMENON
 */
#define EAC_LIGHTNING_LOC_ERR_ELLPS_ANGLE ((EDCS_Attribute_Code)588)

/*
 * Definition:
 *     The <<LENGTH>> of the semi-major axis of the error ellipse at the
 *     <LOCATION> of a stroke of <LIGHTNING>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, EM_PHENOMENON
 */
#define EAC_LIGHTNING_LOC_ERR_ELLPS_MAJOR_AXIS ((EDCS_Attribute_Code)589)

/*
 * Definition:
 *     The <<LENGTH>> of the semi-minor axis of the error ellipse at the
 *     <LOCATION> of a stroke of <LIGHTNING>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, EM_PHENOMENON
 */
#define EAC_LIGHTNING_LOC_ERR_ELLPS_MINOR_AXIS ((EDCS_Attribute_Code)590)

/*
 * Definition:
 *     The polarity of a stroke of <LIGHTNING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LGTNINGPOL_NEGATIVE
 *    EEC_LGTNINGPOL_POSITIVE
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define EAC_LIGHTNING_POLARITY ((EDCS_Attribute_Code)591)

/*
 * Definition:
 *     The probability that <LIGHTNING> will occur.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_LIGHTNING_PROBABILITY ((EDCS_Attribute_Code)592)

/*
 * Definition:
 *     The number of strokes of <LIGHTNING> that constitute a single
 *     <LIGHTNING> discharge; the lightning stroke count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define EAC_LIGHTNING_STROKE_COUNT ((EDCS_Attribute_Code)593)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> added to the observation time of a stroke of
 *     <LIGHTNING> to account for increased accuracy; the lightning time
 *     adjustment.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, TIME
 */
#define EAC_LIGHTNING_TIME_ADJUSTMENT ((EDCS_Attribute_Code)594)

/*
 * Definition:
 *     The coefficient denoting the rate of reduction in value over the unit
 *     <<LENGTH>>; the linear attenuation coefficient.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: INV_LENGTH
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_LINEAR_ATTENUATION_COEFFICIENT ((EDCS_Attribute_Code)595)

/*
 * Definition:
 *     The amount of liquid an <OBJECT> is capable of carrying, storing, or
 *     delivering; the liquid capacity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUME
 *
 * Group Membership: ABSTRACT_OBJECT, FLUID_CONDITION, TRNSP
 */
#define EAC_LIQUID_CAPACITY ((EDCS_Attribute_Code)596)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in a <SURF_ZONE> in the geodetic east-west
 *     <DIRECTION>, where east is positive; the littoral current east speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_LITTORAL_CURRENT_EAST_SPEED ((EDCS_Attribute_Code)597)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in a <SURF_ZONE> in the geodetic
 *     south-north <DIRECTION>, where north is positive; the littoral
 *     current north speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_LITTORAL_CURRENT_NORTH_SPEED ((EDCS_Attribute_Code)598)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in a <SURF_ZONE> in the X <DIRECTION> of a
 *     projection-based coordinate system, where +X is positive; the
 *     littoral current "U" speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_LITTORAL_CURRENT_U_SPEED ((EDCS_Attribute_Code)599)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in a <SURF_ZONE> in the Y <DIRECTION> of a
 *     projection-based coordinate system, where +Y is positive; the
 *     littoral current "V" speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_LITTORAL_CURRENT_V_SPEED ((EDCS_Attribute_Code)600)

/*
 * Definition:
 *     A common name for a <LIVING_ORGANISM>.
 *
 * Value Type: STRING
 *
 * Group Membership: IDENTIFICATION, LIVING_ORGANISM
 */
#define EAC_LIVING_ORGANISM_COMMON_NAME ((EDCS_Attribute_Code)601)

/*
 * Definition:
 *     The two-part Latinized name for a <LIVING_ORGANISM>, consisting of a
 *     capitalized generic name followed by a usually non-capitalized
 *     specific epithet; a scientific name or a binomial name.
 *
 * Value Type: STRING
 *
 * Group Membership: IDENTIFICATION, LIVING_ORGANISM
 */
#define EAC_LIVING_ORGANISM_SCIENTIFIC_NAME ((EDCS_Attribute_Code)602)

/*
 * Definition:
 *     The dynamic live load weight-bearing capacity of a <BRIDGE> or
 *     <BRIDGE_SPAN> for one-way, tracked <GROUND_VEHICLE> traffic in MLC
 *     units; also known as the military load classification, type 3. MLC
 *     values are calculated in part from the size, cross-sectional shape,
 *     and <MATERIAL> of the stringers under the <BRIDGE_SPAN>s; they are
 *     similar to, but not the same as, short tons.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_LOAD_CLASS_ONE_WAY_TRACKED ((EDCS_Attribute_Code)603)

/*
 * Definition:
 *     The dynamic live load weight-bearing capacity of a <BRIDGE> or
 *     <BRIDGE_SPAN> for one-way, wheeled <GROUND_VEHICLE> traffic in MLC
 *     units; also known as the military load classification, type 1. MLC
 *     values are calculated in part from the size, cross-sectional shape,
 *     and <MATERIAL> of the stringers under the <BRIDGE_SPAN>s; they are
 *     similar to, but not the same as, short tons.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_LOAD_CLASS_ONE_WAY_WHEELED ((EDCS_Attribute_Code)604)

/*
 * Definition:
 *     The dynamic live load weight-bearing capacity of a <BRIDGE> or
 *     <BRIDGE_SPAN> for two-way, tracked <GROUND_VEHICLE> traffic in MLC
 *     units; also known as the military load classification, type 4. MLC
 *     values are calculated in part from the size, cross-sectional shape,
 *     and <MATERIAL> of the stringers under the <BRIDGE_SPAN>s; they are
 *     similar to, but not the same as, short tons.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_LOAD_CLASS_TWO_WAY_TRACKED ((EDCS_Attribute_Code)605)

/*
 * Definition:
 *     The dynamic live load weight-bearing capacity of a <BRIDGE> or
 *     <BRIDGE_SPAN> for two-way, wheeled <GROUND_VEHICLE> traffic in MLC
 *     units; also known as the military load classification, type 2. MLC
 *     values are calculated in part from the size, cross-sectional shape,
 *     and <MATERIAL> of the stringers under the <BRIDGE_SPAN>s; they are
 *     similar to, but not the same as, short tons.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_LOAD_CLASS_TWO_WAY_WHEELED ((EDCS_Attribute_Code)606)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_LOCAL>> in the horizontal plane at the observer's
 *     location from an azimuthal reference vector, to either a <LINE>
 *     passing through the observer, or a vector relative to the observer,
 *     or the direction from the observer to an <OBJECT> or <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_LOCAL_AZIMUTH ((EDCS_Attribute_Code)607)

/*
 * Definition:
 *     The method used to determine the accuracy of a <LOCATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LOCACCMETH_APPROXIMATED
 *    EEC_LOCACCMETH_CALCULATED
 *    EEC_LOCACCMETH_ESTIMATED
 *    EEC_LOCACCMETH_INADEQUATELY_SURVEYED
 *    EEC_LOCACCMETH_KNOWN
 *    EEC_LOCACCMETH_REPORTED_BUT_UNRELIABLE
 *    EEC_LOCACCMETH_REPORTED_NOT_CONFIRMED
 *    EEC_LOCACCMETH_REPORTED_NOT_SURVEYED
 *    EEC_LOCACCMETH_SURVEYED
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_LOCATION_ACCURACY_METHOD ((EDCS_Attribute_Code)608)

/*
 * Definition:
 *     A statement of the accuracy of a <LOCATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LOCACCSTMT_ACCURATE
 *    EEC_LOCACCSTMT_APPROXIMATE
 *    EEC_LOCACCSTMT_DISPUTED
 *    EEC_LOCACCSTMT_DOUBTFUL
 *    EEC_LOCACCSTMT_INACCURATE
 *    EEC_LOCACCSTMT_PRECISE
 *    EEC_LOCACCSTMT_UNDISPUTED
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_LOCATION_ACCURACY_STATEMENT ((EDCS_Attribute_Code)609)

/*
 * Definition:
 *     The <<LENGTH>> of the longest <BRIDGE_SPAN> of a <BRIDGE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_LONGEST_BRIDGE_SPAN_LENGTH ((EDCS_Attribute_Code)610)

/*
 * Definition:
 *     The <<CLOUD_BASE_LEVEL>> of a <LOW_CLOUD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_LOW_CLOUD_BASE_LEVEL ((EDCS_Attribute_Code)611)

/*
 * Definition:
 *     The fraction of the sky covered by <LOW_CLOUD>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_LOW_CLOUD_COVERAGE ((EDCS_Attribute_Code)612)

/*
 * Definition:
 *     The genus of a <LOW_CLOUD>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LOWCLDGENUS_CUMULONIMBUS
 *    EEC_LOWCLDGENUS_CUMULUS
 *    EEC_LOWCLDGENUS_NONE_PRESENT
 *    EEC_LOWCLDGENUS_STRATOCUMULUS
 *    EEC_LOWCLDGENUS_STRATUS
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_LOW_CLOUD_GENUS ((EDCS_Attribute_Code)613)

/*
 * Definition:
 *     The <<CLOUD_TOP_LEVEL>> of a <LOW_CLOUD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_LOW_CLOUD_TOP_LEVEL ((EDCS_Attribute_Code)614)

/*
 * Definition:
 *     The type of observed <LOW_CLOUD>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LOWCLDTYOBV_NO_LOW_CLOUDS
 *    EEC_LOWCLDTYOBV_CUMULUS_HUMULIS
 *    EEC_LOWCLDTYOBV_CUMULUS_MEDIOCRIS
 *    EEC_LOWCLDTYOBV_CMNIMB_CALVUS
 *    EEC_LOWCLDTYOBV_STRATCM_CUMULOGEN
 *    EEC_LOWCLDTYOBV_STRATCM_OTHER
 *    EEC_LOWCLDTYOBV_STRATUS_NEBULOSUS
 *    EEC_LOWCLDTYOBV_STRATUS_FRACTUS
 *    EEC_LOWCLDTYOBV_CUMULUS_AND_STRATO
 *    EEC_LOWCLDTYOBV_CMNIMB_CAPILLATUS
 *    EEC_LOWCLDTYOBV_LOW_CLOUDS_INVISIBLE
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_LOW_CLOUD_TYPE_OBSERVED ((EDCS_Attribute_Code)615)

/*
 * Definition:
 *     The <<TEMPERATURE>> of the <SOIL> between five and 100 centimetres
 *     below the <SURFACE> of the <TERRAIN>; the lower layer soil
 *     temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: MATERIAL, TEMPERATURE
 */
#define EAC_LOWER_LAYER_SOIL_TEMPERATURE ((EDCS_Attribute_Code)616)

/*
 * Definition:
 *     The least <<HEIGHT_AGL>> of all <LOCATION>s in or on the boundary of
 *     an <AIRSPACE>; the lowest airspace altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define EAC_LOWEST_AIRSPACE_ALTITUDE ((EDCS_Attribute_Code)617)

/*
 * Definition:
 *     The <<LOWEST_AIRSPACE_ALTITUDE>> limit.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, DEMARCATION, LOCATION, TRNSP
 */
#define EAC_LOWEST_AIRSPACE_ALTITUDE_LIMIT ((EDCS_Attribute_Code)618)

/*
 * Definition:
 *     The lowest annual mean level of ground <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, HYDROLOGY
 */
#define EAC_LOWEST_ANNUAL_GROUND_WATER_LEVEL ((EDCS_Attribute_Code)619)

/*
 * Definition:
 *     The <<CLOUD_BASE_LEVEL>>of the lowest <CLOUD>; the lowest cloud base
 *     level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_LOWEST_CLOUD_BASE_LEVEL ((EDCS_Attribute_Code)620)

/*
 * Definition:
 *     A category indicating the fraction of the sky covered by <LOW_CLOUD>s
 *     or, if no <LOW_CLOUD>s are present, the fraction of the sky covered
 *     by <MIDDLE_CLOUD>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_LOWESTCLDCOV_NONE_PRESENT
 *    EEC_LOWESTCLDCOV_ONE_OKTA
 *    EEC_LOWESTCLDCOV_TWO_OKTA
 *    EEC_LOWESTCLDCOV_THREE_OKTA
 *    EEC_LOWESTCLDCOV_FOUR_OKTA
 *    EEC_LOWESTCLDCOV_FIVE_OKTA
 *    EEC_LOWESTCLDCOV_SIX_OKTA
 *    EEC_LOWESTCLDCOV_SEVEN_OKTA
 *    EEC_LOWESTCLDCOV_EIGHT_OKTA
 *    EEC_LOWESTCLDCOV_PARTIAL_OBSCURATION
 *    EEC_LOWESTCLDCOV_SKY_OBSCURED
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LIGHTING_AND_VISIBILITY
 */
#define EAC_LOWEST_CLOUD_COVER_CATEGORY ((EDCS_Attribute_Code)621)

/*
 * Definition:
 *     The least <<ELEVATION>> to any <LOCATION> associated with an <OBJECT>;
 *     the lowest elevation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_LOWEST_ELEVATION ((EDCS_Attribute_Code)622)

/*
 * Definition:
 *     The maximum distance at which a <LIGHT> can be seen under existing
 *     visibility conditions and taking no account of the <<HEIGHT_AGL>> of
 *     the <LIGHT>, the <<HEIGHT_AGL>> of the observer's eye, the curvature
 *     of the <EARTH>, or interference from background <LIGHTING>; the
 *     luminous light range.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIGHTING_AND_VISIBILITY
 */
#define EAC_LUMINOUS_LIGHT_RANGE ((EDCS_Attribute_Code)623)

/*
 * Definition:
 *     The diffused lunar incident flux (irradiance) per unit <<AREA>> of the
 *     <SURFACE> of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE, SURFACE
 */
#define EAC_LUNAR_DIFFUSED_IRRADIANCE ((EDCS_Attribute_Code)624)

/*
 * Definition:
 *     The direct lunar incident flux (irradiance) per unit <<AREA>> of the
 *     <SURFACE> of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE, SURFACE
 */
#define EAC_LUNAR_DIRECT_IRRADIANCE ((EDCS_Attribute_Code)625)

/*
 * Definition:
 *     The fraction of the apparent circular disk of the <MOON> that is
 *     illuminated by the <SUN>; the lunar illumination fraction.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, SPACE
 */
#define EAC_LUNAR_ILLUMINATION_FRACTION ((EDCS_Attribute_Code)626)

/*
 * Definition:
 *     The lunar <<INCIDENCE_AZIMUTH_GEODETIC>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_LUNAR_RADIANCE_AZIMUTH_GEODETIC ((EDCS_Attribute_Code)627)

/*
 * Definition:
 *     The lunar <<INCIDENCE_ELEV_ANGLE_HORIZONTAL>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_LUNAR_RADIANCE_ELEV_ANGLE_HORIZONTAL ((EDCS_Attribute_Code)628)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_MAGNETIC>> in the horizontal plane at the
 *     observer's <LOCATION> to either a <LINE> passing through the
 *     observer, a vector relative to the observer, or the <DIRECTION> from
 *     the observer to an <OBJECT> or <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_MAGNETIC_AZIMUTH ((EDCS_Attribute_Code)629)

/*
 * Definition:
 *     A 3-hourly equivalent amplitude index of geomagnetic activity at a
 *     specific solar electromagnetic flux <OBSERVATION_STATION> on the
 *     <EARTH>, related to the 3-hourly <<MAGNETIC_FIELD_K>> index and
 *     ranging in value from 0 to 400; the magnetic field A.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_A ((EDCS_Attribute_Code)630)

/*
 * Definition:
 *     A daily index of magnetic activity derived as the average of eight
 *     consecutive 3-hourly <<MAGNETIC_FIELD_A>> values.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_A_DAILY ((EDCS_Attribute_Code)631)

/*
 * Definition:
 *     The difference between the <MAGNETIC_FIELD> of a <PLANET> declination
 *     of the disturbance <REGION> and the <MAGNETIC_FIELD> declination of
 *     the surrounding <REGION>; the magnetic field anomaly.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_ANOMALY ((EDCS_Attribute_Code)632)

/*
 * Definition:
 *     A daily averaged <<MAGNETIC_FIELD_A>> of a <PLANET> based on data from
 *     specific solar electromagnetic flux stations; the magnetic field
 *     A[sub(P)].
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_AP ((EDCS_Attribute_Code)633)

/*
 * Definition:
 *     The declination angle between magnetic north and geodetic north of the
 *     <MAGNETIC_FIELD> of a <PLANET>. The value is determined as a
 *     horizontal angle measured east (positive value) or west (negative
 *     value) according to whether magnetic north lies east or west of
 *     geodetic north.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_DECLINATION_ANGLE ((EDCS_Attribute_Code)634)

/*
 * Definition:
 *     The strength of the geodetic east vector component of the
 *     <MAGNETIC_FIELD> of a <PLANET>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_EAST_COMPONENT ((EDCS_Attribute_Code)635)

/*
 * Definition:
 *     The strength of the full vector component of the <MAGNETIC_FIELD> of a
 *     <PLANET>. The value is the vector sum of the
 *     <<MAGNETIC_FIELD_EAST_COMPONENT>>,
 *     <<MAGNETIC_FIELD_NORTH_COMPONENT>>, and
 *     <<MAGNETIC_FIELD_VERTICAL_COMPONENT>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_FULL_COMPONENT ((EDCS_Attribute_Code)636)

/*
 * Definition:
 *     The strength of the horizontal vector component of the
 *     <MAGNETIC_FIELD> of a <PLANET>. The value is the vector sum of the
 *     <<MAGNETIC_FIELD_EAST_COMPONENT>> and
 *     <<MAGNETIC_FIELD_NORTH_COMPONENT>>; the magnetic field horizontal
 *     component.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_HORIZONTAL_COMPONENT ((EDCS_Attribute_Code)637)

/*
 * Definition:
 *     The inclination angle between the <MAGNETIC_FIELD> of a <PLANET> and
 *     the local horizontal plane. The angle is positive downwards.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_INCLINATION_ANGLE ((EDCS_Attribute_Code)638)

/*
 * Definition:
 *     A 3-hourly quasi-logarithmic planetary index of magnetic activity,
 *     representing a value measuring the two horizontal (x,y) components of
 *     the <MAGNETIC_FIELD> at a specific solar electromagnetic flux
 *     <OBSERVATION_STATION> on the <EARTH>; the magnetic field K[sub(P)].
 *     K[sub(P)] = 0 represents a 2,5 nanoTesla variation from the quiet day
 *     value, and K[sub(P)] = 9 represents a 666 nanoTesla variation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_K ((EDCS_Attribute_Code)639)

/*
 * Definition:
 *     A daily index of magnetic activity derived as the average of eight
 *     consecutive 3-hourly <<MAGNETIC_FIELD_K>> values.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_K_DAILY ((EDCS_Attribute_Code)640)

/*
 * Definition:
 *     A daily averaged planetary <<MAGNETIC_FIELD_K>> based on data from
 *     specific solar electromagnetic flux stations; the magnetic field
 *     K[sub(P)].
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_KP ((EDCS_Attribute_Code)641)

/*
 * Definition:
 *     The strength of the <MAGNETIC_FIELD> of a <PLANET> as measured in
 *     orbit, in the <DIRECTION> normal to the plane formed by the spin axis
 *     of an <ARTIFICIAL_SATELLITE> and the <DIRECTION> of the <PLANET>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_NORMAL ((EDCS_Attribute_Code)642)

/*
 * Definition:
 *     The strength of the geodetic north vector component of the
 *     <MAGNETIC_FIELD> of a <PLANET>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_NORTH_COMPONENT ((EDCS_Attribute_Code)643)

/*
 * Definition:
 *     The strength of the <MAGNETIC_FIELD> of a <PLANET> as measured in
 *     orbit, in the <DIRECTION> parallel to the spin axis of an
 *     <ARTIFICIAL_SATELLITE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_PARALLEL ((EDCS_Attribute_Code)644)

/*
 * Definition:
 *     The strength of the <MAGNETIC_FIELD> of a <PLANET> as measured in
 *     orbit, in the <DIRECTION> of the <PLANET>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_PLANETWARD ((EDCS_Attribute_Code)645)

/*
 * Definition:
 *     The strength of the <MAGNETIC_FIELD> of a <PLANET> as measured in
 *     orbit. The value is determined by the magnitude of the total
 *     <MAGNETIC_FIELD> vector.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_TOTAL ((EDCS_Attribute_Code)646)

/*
 * Definition:
 *     The strength of the vertical vector component of the <MAGNETIC_FIELD>
 *     of a <PLANET>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETIC_FIELD_VERTICAL_COMPONENT ((EDCS_Attribute_Code)647)

/*
 * Definition:
 *     The angle subtended at the geomagnetic axis between the geomagnetic
 *     midnight meridian and the meridian that passes through the location
 *     expressed as hours where 15 arc degrees is equivalent to 1 hour. The
 *     geomagnetic meridian containing the sub-solar point defines
 *     geomagnetic local noon and the opposite meridian defines geomagnetic
 *     midnight.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME
 */
#define EAC_MAGNETIC_LOCAL_TIME ((EDCS_Attribute_Code)648)

/*
 * Definition:
 *     The total flux of charged <PARTICLE>s (plasma) in a <MAGNETOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PARTICLE_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MAGNETOSPHERE_PLASMA_FLUX ((EDCS_Attribute_Code)649)

/*
 * Definition:
 *     An indication that an <OBJECT> is maintained.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_MAINTAINED ((EDCS_Attribute_Code)650)

/*
 * Definition:
 *     An indication that an <OBJECT> is man-made.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_MAN_MADE ((EDCS_Attribute_Code)651)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the extent of physical injury/damage to an <OBJECT>
 *     affecting its capability to manoeuvre. Zero means no damage at all
 *     and one means completely immobilized.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, MILITARY_SCIENCE
 */
#define EAC_MANOEUVRE_DAMAGE_FRACTION ((EDCS_Attribute_Code)652)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the marginal ice zone
 *     cover as a linearly-scaled fraction of complete cover, where the
 *     <BOUNDARY> of the <ICE> is defined as occurring at 0,4.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ICE, RATE_OR_RATIO
 */
#define EAC_MARGINAL_ICE_ZONE_COVER_FRACTION ((EDCS_Attribute_Code)653)

/*
 * Definition:
 *     The characteristic geometric shape of a marine <BEACON>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARBEACSHAP_ARTICULATED
 *    EEC_MARBEACSHAP_ARTICULATED_DAYMARK
 *    EEC_MARBEACSHAP_BUOYANT
 *    EEC_MARBEACSHAP_CAIRN
 *    EEC_MARBEACSHAP_LATTICE
 *    EEC_MARBEACSHAP_POLE
 *    EEC_MARBEACSHAP_RECTANGLE_DAYMARK
 *    EEC_MARBEACSHAP_SQUARE_DAYMARK
 *    EEC_MARBEACSHAP_STAKE
 *    EEC_MARBEACSHAP_STRUCTURAL_PILE
 *    EEC_MARBEACSHAP_TOWER
 *    EEC_MARBEACSHAP_TRIANGLE_DAYMARK
 *    EEC_MARBEACSHAP_WITHY
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_BEACON_SHAPE ((EDCS_Attribute_Code)654)

/*
 * Definition:
 *     The type of limit <BOUNDARY> of a <MARINE_REGION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARBNDRYLIMTY_APPROXIMATE_BATHYMETRY
 *    EEC_MARBNDRYLIMTY_ARMISTICE
 *    EEC_MARBNDRYLIMTY_CLEARING_LINE
 *    EEC_MARBNDRYLIMTY_COLREGS_DEMARCATION_LINE
 *    EEC_MARBNDRYLIMTY_CONTIGUOUS_ZONE
 *    EEC_MARBNDRYLIMTY_CONTINENTAL_SHELF
 *    EEC_MARBNDRYLIMTY_CUSTOMS
 *    EEC_MARBNDRYLIMTY_DANGER_LINE
 *    EEC_MARBNDRYLIMTY_EXCLUSIVE_ECONOMIC
 *    EEC_MARBNDRYLIMTY_FISHING_ZONE
 *    EEC_MARBNDRYLIMTY_GULF_STREAM
 *    EEC_MARBNDRYLIMTY_HARBOUR
 *    EEC_MARBNDRYLIMTY_INTERNATIONAL_BOUNDARY
 *    EEC_MARBNDRYLIMTY_MANAGEMENT_AND_ZONING
 *    EEC_MARBNDRYLIMTY_MARINE_LIMIT_GENERAL
 *    EEC_MARBNDRYLIMTY_THREE_NAUTICAL_MILE_LINE
 *    EEC_MARBNDRYLIMTY_TRAFFIC_SERVICES
 *    EEC_MARBNDRYLIMTY_TRRT_WATERS_BASELINE
 *    EEC_MARBNDRYLIMTY_TRRT_WATERS
 *    EEC_MARBNDRYLIMTY_TSS_SEPARATION
 *
 * Group Membership: DEMARCATION, HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_MARINE_BOUNDARY_LIMIT_TYPE ((EDCS_Attribute_Code)655)

/*
 * Definition:
 *     The type of construction used for a <MARINE_OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARCNSTCTTY_BOULDER_AND_FILL
 *    EEC_MARCNSTCTTY_GENERAL_SOLID_FACE
 *    EEC_MARCNSTCTTY_MASONRY
 *    EEC_MARCNSTCTTY_OPEN_PILINGS
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT
 */
#define EAC_MARINE_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)656)

/*
 * Definition:
 *     The initial limit of visibility of a <MARINE_LIGHT_SECTOR> expressed
 *     as a <<BEARING_FROM_SEAWARD>>; the marine light sector initial angle.
 *     Limits of sectors and arcs of visibility are arranged clockwise with
 *     respect to the <LIGHT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, DEMARCATION, HYDROGRAPHIC_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_MARINE_LIGHT_SECTOR_INITIAL_ANGLE ((EDCS_Attribute_Code)657)

/*
 * Definition:
 *     The terminal limit of visibility of a <MARINE_LIGHT_SECTOR> expressed
 *     as a <<BEARING_FROM_SEAWARD>>; the marine light sector terminal
 *     angle. Limits of sectors and arcs of visibility are arranged
 *     clockwise with respect to the <LIGHT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, DEMARCATION, HYDROGRAPHIC_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_MARINE_LIGHT_SECTOR_TERMINAL_ANGLE ((EDCS_Attribute_Code)658)

/*
 * Definition:
 *     The type of <LIGHT> used for marine navigation.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARLGTTY_DIRECTIONAL
 *    EEC_MARLGTTY_HORIZONTALLY_DISPOSED
 *    EEC_MARLGTTY_LIGHTED_BEACON
 *    EEC_MARLGTTY_MOIRE_EFFECT
 *    EEC_MARLGTTY_OCCASIONAL
 *    EEC_MARLGTTY_SECTORED
 *    EEC_MARLGTTY_STRIP
 *    EEC_MARLGTTY_VERTICALLY_DISPOSED
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_MARINE_LIGHT_TYPE ((EDCS_Attribute_Code)659)

/*
 * Definition:
 *     The type and/or number of <AID_TO_NAVIGATION>s associated with a
 *     <MARINE_LEADING_LINE> or <MARINE_CLEARING_LINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARLNASSATNAV_DIRECTIONAL_LIGHT
 *    EEC_MARLNASSATNAV_DIRECTIONAL_RADIO_BEACON
 *    EEC_MARLNASSATNAV_LEADING_RADIO_TRANSPONDER
 *    EEC_MARLNASSATNAV_MEASURED_DISTANCE_MARKERS
 *    EEC_MARLNASSATNAV_MOIRE_EFFECT_LIGHT
 *    EEC_MARLNASSATNAV_MULTIPLE_BEACON
 *    EEC_MARLNASSATNAV_MULTIPLE_LIGHT
 *    EEC_MARLNASSATNAV_MULTIPLE_OBJECT
 *    EEC_MARLNASSATNAV_SINGLE_OBJECT
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_LINE_ASSOCIATED_ATNAV ((EDCS_Attribute_Code)660)

/*
 * Definition:
 *     A description of the <AID_TO_NAVIGATION>s that form a marine
 *     navigation <LINE>. EXAMPLE Description of a <MARINE_LEADING_LINE>.
 *
 * Value Type: STRING
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_LINE_ATNAV_DESCRIPTION ((EDCS_Attribute_Code)661)

/*
 * Definition:
 *     The type of a marine navigation <LINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARNAVLNTY_CLEARING_LINE
 *    EEC_MARNAVLNTY_TRANSIT_LINE
 *    EEC_MARNAVLNTY_UNDEFINED
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_NAVIGATION_LINE_TYPE ((EDCS_Attribute_Code)662)

/*
 * Definition:
 *     An indication that a <MARINE_ROUTE> has an <OVERHEAD_OBSTRUCTION>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_OVERHEAD_OBSTRUCTION ((EDCS_Attribute_Code)663)

/*
 * Definition:
 *     The pilot boarding method for <VESSEL>s using marine pilot services.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARPLTBRDMETH_COMES_FROM_SHORE_ON_VESSEL
 *    EEC_MARPLTBRDMETH_HELICOPTER
 *    EEC_MARPLTBRDMETH_PILOT_CRUISING_VESSEL
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_PILOT_BOARDING_METHOD ((EDCS_Attribute_Code)664)

/*
 * Definition:
 *     The <VEHICLE> by which marine pilots are transferred to and from
 *     <VESSEL>s using pilot services.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARPLTBRDVEH_BOAT
 *    EEC_MARPLTBRDVEH_HELICOPTER
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_MARINE_PILOT_BOARDING_VEHICLE ((EDCS_Attribute_Code)665)

/*
 * Definition:
 *     The pilot district for which a marine pilot is responsible.
 *
 * Value Type: STRING
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_PILOT_DISTRICT ((EDCS_Attribute_Code)666)

/*
 * Definition:
 *     The textual identifier of a <MARINE_PORT>.
 *
 * Value Type: STRING
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, IDENTIFICATION, TRNSP, USAGE_REGION
 */
#define EAC_MARINE_PORT_IDENTIFIER ((EDCS_Attribute_Code)667)

/*
 * Definition:
 *     The type of a <MARINE_REGION>, describing some aspect of significance
 *     to marine operations.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARREGNTY_ABANDONED_DRILL_MINEFIELD
 *    EEC_MARREGNTY_ANCHORAGE_FOR_24_HOURS
 *    EEC_MARREGNTY_ANCHORAGE_GENERAL
 *    EEC_MARREGNTY_ANCHORING_BERTHS
 *    EEC_MARREGNTY_ANCHORING_FISHING_PRHBT
 *    EEC_MARREGNTY_ANCHORING_PRHBT
 *    EEC_MARREGNTY_ANCHORING_RSTRCT
 *    EEC_MARREGNTY_ARTIFACT_REMOVAL_PRHBT
 *    EEC_MARREGNTY_ASW_OPERATING
 *    EEC_MARREGNTY_ATLANTIC_FLEET_WEAPONS
 *    EEC_MARREGNTY_BIRD_SANCTUARY
 *    EEC_MARREGNTY_BOMBING_STRAFING_TARGETS
 *    EEC_MARREGNTY_CABLE_AND_PIPELINE
 *    EEC_MARREGNTY_CARGO_TRNSHP
 *    EEC_MARREGNTY_CARGO_TRNSHP_PRHBT
 *    EEC_MARREGNTY_CAUTION
 *    EEC_MARREGNTY_CHEMICAL_DUMPING_GROUND
 *    EEC_MARREGNTY_CONSTRUCTION_PRHBT
 *    EEC_MARREGNTY_CONTIGUOUS_ZONE
 *    EEC_MARREGNTY_CONTINENTAL_SHELF
 *    EEC_MARREGNTY_CUSTOMS
 *    EEC_MARREGNTY_DANGER_OF_STRANDING
 *    EEC_MARREGNTY_DEEP_DRAFT_ANCHORAGE
 *    EEC_MARREGNTY_DEGAUSSING_RANGE
 *    EEC_MARREGNTY_DEVELOPMENT
 *    EEC_MARREGNTY_DISCHARGING_PRHBT
 *    EEC_MARREGNTY_DISCHARGING_RSTRCT
 *    EEC_MARREGNTY_DIVING_PRHBT
 *    EEC_MARREGNTY_DIVING_RSTRCT
 *    EEC_MARREGNTY_DOCK
 *    EEC_MARREGNTY_DRAGGING_PRHBT
 *    EEC_MARREGNTY_DREDGED_CHANNEL
 *    EEC_MARREGNTY_DREDGING
 *    EEC_MARREGNTY_DREDGING_PRHBT
 *    EEC_MARREGNTY_DREDGING_RSTRCT
 *    EEC_MARREGNTY_DRILL_MINEFIELD
 *    EEC_MARREGNTY_DRILLING_PRHBT
 *    EEC_MARREGNTY_DRILLING_RSTRCT
 *    EEC_MARREGNTY_ECOLOGICAL_RESERVE
 *    EEC_MARREGNTY_ENTRY_PRHBT
 *    EEC_MARREGNTY_ENTRY_RSTRCT
 *    EEC_MARREGNTY_EVAPORITES
 *    EEC_MARREGNTY_EXCLUSIVE_ECONOMIC_ZONE
 *    EEC_MARREGNTY_EXERCISE_AREA_LIMIT
 *    EEC_MARREGNTY_EXPLORE_PRHBT
 *    EEC_MARREGNTY_EXPLORE_RSTRCT
 *    EEC_MARREGNTY_EXPLOSIVE_ANCHORAGE
 *    EEC_MARREGNTY_EXPLOSIVE_DUMPING_GROUND
 *    EEC_MARREGNTY_FAIRWAY
 *    EEC_MARREGNTY_FIRING_DANGER
 *    EEC_MARREGNTY_FISH_SANCTUARY
 *    EEC_MARREGNTY_FISH_TRAP
 *    EEC_MARREGNTY_FISHERY_ZONE
 *    EEC_MARREGNTY_FISHING_GROUND
 *    EEC_MARREGNTY_FISHING_PRHBT
 *    EEC_MARREGNTY_FISHING_RSTRCT
 *    EEC_MARREGNTY_FORACS_V_LIMITS
 *    EEC_MARREGNTY_FORMER_MINE_DANGER
 *    EEC_MARREGNTY_FREE_PORT
 *    EEC_MARREGNTY_GAME_PRESERVE
 *    EEC_MARREGNTY_GAS_FIELD
 *    EEC_MARREGNTY_HARBOUR
 *    EEC_MARREGNTY_HAZMAT_DUMPING_GROUND
 *    EEC_MARREGNTY_HISTORIC_WRECK
 *    EEC_MARREGNTY_HISTORIC_WRECK_RSTRCT
 *    EEC_MARREGNTY_INCINERATION
 *    EEC_MARREGNTY_INSHORE_TRAFFIC_ZONE
 *    EEC_MARREGNTY_INTAKE
 *    EEC_MARREGNTY_INWATER_TRACKING_RANGE
 *    EEC_MARREGNTY_LANDING_PRHBT
 *    EEC_MARREGNTY_LATERITE
 *    EEC_MARREGNTY_LCAC
 *    EEC_MARREGNTY_MAJOR_NAVY_OPERATING
 *    EEC_MARREGNTY_MARINE_FARM
 *    EEC_MARREGNTY_MARINE_SANCTUARY
 *    EEC_MARREGNTY_MILITARY
 *    EEC_MARREGNTY_MILITARY_PRACTICE
 *    EEC_MARREGNTY_MINE_DANGER
 *    EEC_MARREGNTY_MINE_LAYING_PRACTICE
 *    EEC_MARREGNTY_MINEFIELD
 *    EEC_MARREGNTY_MINESWEPT_CHANNEL
 *    EEC_MARREGNTY_MINOR_NAVY_OPERATING
 *    EEC_MARREGNTY_MISSILE_TEST
 *    EEC_MARREGNTY_NAMED_OPERATING
 *    EEC_MARREGNTY_NATURE_RESERVE
 *    EEC_MARREGNTY_NAVAL_DEFENCE_SEA
 *    EEC_MARREGNTY_NAVAL_OPERATIONS
 *    EEC_MARREGNTY_NAVIGATIONAL_AID
 *    EEC_MARREGNTY_NO_WAKE
 *    EEC_MARREGNTY_NUCLEAR_DUMPING_GROUND
 *    EEC_MARREGNTY_OFFSHORE_PRODUCTION
 *    EEC_MARREGNTY_OUTFALL
 *    EEC_MARREGNTY_PETROLEUM_FIELD
 *    EEC_MARREGNTY_PILOT_BOARDING
 *    EEC_MARREGNTY_PIPELINE
 *    EEC_MARREGNTY_PRACTICE_IN_GENERAL
 *    EEC_MARREGNTY_PRECAUTIONARY
 *    EEC_MARREGNTY_PRHBT
 *    EEC_MARREGNTY_PROTECTED
 *    EEC_MARREGNTY_QUARANTINE_ANCHORAGE
 *    EEC_MARREGNTY_RECLAMATION
 *    EEC_MARREGNTY_RESEARCH
 *    EEC_MARREGNTY_RESERVED_ANCHORAGE
 *    EEC_MARREGNTY_ROUNDABOUT_ZONE
 *    EEC_MARREGNTY_RSTRCT
 *    EEC_MARREGNTY_SAFETY_FAIRWAY
 *    EEC_MARREGNTY_SAFETY_ZONE
 *    EEC_MARREGNTY_SEA_TEST_RANGE
 *    EEC_MARREGNTY_SEAL_SANCTUARY
 *    EEC_MARREGNTY_SEAPLANE_ANCHORAGE
 *    EEC_MARREGNTY_SEAPLANE_RUN
 *    EEC_MARREGNTY_SEPARATION_ZONE
 *    EEC_MARREGNTY_SEWER
 *    EEC_MARREGNTY_SMALL_CRAFT_ANCHORAGE
 *    EEC_MARREGNTY_SMALL_CRAFT_MOORING
 *    EEC_MARREGNTY_SPEED_RSTRCT
 *    EEC_MARREGNTY_SPOIL_GROUND
 *    EEC_MARREGNTY_SRF_FREE_LANE
 *    EEC_MARREGNTY_SRF_OPERATING_MAJOR
 *    EEC_MARREGNTY_SRF_OPERATING_MINOR
 *    EEC_MARREGNTY_SRF_VESSEL_SAFETY_LANE
 *    EEC_MARREGNTY_STOPPING_PRHBT
 *    EEC_MARREGNTY_SUB_OPERATING
 *    EEC_MARREGNTY_SUB_SRF_TRANSIT_LANE
 *    EEC_MARREGNTY_SUB_SUBMERGED_TRANSIT_LANE
 *    EEC_MARREGNTY_SUB_WARNING
 *    EEC_MARREGNTY_SWEPT_BY_WIRE_DRAG
 *    EEC_MARREGNTY_SWIMMING
 *    EEC_MARREGNTY_TANKER_ANCHORAGE
 *    EEC_MARREGNTY_SWINGING
 *    EEC_MARREGNTY_TERRITORIAL_SEA
 *    EEC_MARREGNTY_SUB_CABLE
 *    EEC_MARREGNTY_SUB_DANGER
 *    EEC_MARREGNTY_SUB_EXERCISE
 *    EEC_MARREGNTY_SUB_GUNNERY_EXERCISE
 *    EEC_MARREGNTY_TIME_LIMITED_ANCHORAGE
 *    EEC_MARREGNTY_TO_BE_AVOIDED
 *    EEC_MARREGNTY_TORPEDO_PRACTICE
 *    EEC_MARREGNTY_TRAWLING_PRHBT
 *    EEC_MARREGNTY_TRAWLING_RSTRCT
 *    EEC_MARREGNTY_TSS_CROSSING
 *    EEC_MARREGNTY_UNDERWATER_TELEPHONE_TEST
 *    EEC_MARREGNTY_UNEXPLODED_MUNITIONS
 *    EEC_MARREGNTY_UNRESTRICTED_ANCHORAGE
 *    EEC_MARREGNTY_UNSURVEYED
 *    EEC_MARREGNTY_VESSEL_DUMPING_GROUND
 *    EEC_MARREGNTY_WAITING
 *    EEC_MARREGNTY_WATER_SKIING
 *    EEC_MARREGNTY_WORKS_IN_PROGRESS
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_MARINE_REGION_TYPE ((EDCS_Attribute_Code)668)

/*
 * Definition:
 *     The type of a marine rescue <PUBLIC_SERVICE_STATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARRESCUESTATY_EMERGENCY_RADIO
 *    EEC_MARRESCUESTATY_FIRST_AID_EQUIPMENT
 *    EEC_MARRESCUESTATY_INTERTIDAL_REFUGE
 *    EEC_MARRESCUESTATY_LIFEBOAT
 *    EEC_MARRESCUESTATY_LIFEBOAT_AND_ROCKET
 *    EEC_MARRESCUESTATY_MOORED_LIFEBOAT
 *    EEC_MARRESCUESTATY_ROCKET
 *    EEC_MARRESCUESTATY_SHIPWRECK_REFUGE
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_MARINE_RESCUE_STATION_TYPE ((EDCS_Attribute_Code)669)

/*
 * Definition:
 *     The type of a <MARINE_ROUTE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARRTETY_CENTRE_LINE
 *    EEC_MARRTETY_DEEP_WATER
 *    EEC_MARRTETY_DEEP_WATER_CENTRE_LINE
 *    EEC_MARRTETY_DEEP_WATER_PART
 *    EEC_MARRTETY_LIMITED_ACCESS
 *    EEC_MARRTETY_MEASURED_DISTANCE_LINE
 *    EEC_MARRTETY_PRIMARY
 *    EEC_MARRTETY_Q
 *    EEC_MARRTETY_RADAR_GUIDED_TRACK
 *    EEC_MARRTETY_RECOMMENDED
 *    EEC_MARRTETY_SAFETY
 *    EEC_MARRTETY_SECONDARY
 *    EEC_MARRTETY_TRACK
 *    EEC_MARRTETY_TRACK_DEEP_DRAFT
 *    EEC_MARRTETY_TRACK_NOT_DEEP_DRAFT
 *    EEC_MARRTETY_TRAFFIC_DIRECTION
 *    EEC_MARRTETY_TRAFFIC_LANE_PART
 *    EEC_MARRTETY_TRANSIT
 *    EEC_MARRTETY_TSS_ROUNDABOUT_LANE
 *    EEC_MARRTETY_TSS_TRACK
 *    EEC_MARRTETY_TSS_TRAFFIC_LANE
 *    EEC_MARRTETY_TWO_WAY
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_ROUTE_TYPE ((EDCS_Attribute_Code)670)

/*
 * Definition:
 *     The type of activity conducted at a marine station.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARSTAACTV_BARRAGE_SIGNAL
 *    EEC_MARSTAACTV_BERTHING_SIGNAL
 *    EEC_MARSTAACTV_BRIDGE_SIGNAL
 *    EEC_MARSTAACTV_COASTGUARD
 *    EEC_MARSTAACTV_DOCK_SIGNAL
 *    EEC_MARSTAACTV_DREDGING_SIGNAL
 *    EEC_MARSTAACTV_FIRING_PRACTICE_SIGNAL
 *    EEC_MARSTAACTV_INT_PORT_TRAFFIC_SIGNALS
 *    EEC_MARSTAACTV_LOCK_SIGNAL
 *    EEC_MARSTAACTV_MARINE_POLICE
 *    EEC_MARSTAACTV_PILOT
 *    EEC_MARSTAACTV_PILOT_LOOKOUT
 *    EEC_MARSTAACTV_PORT_CONTROL
 *    EEC_MARSTAACTV_PORT_ENTER_DEPART_SIGNAL
 *    EEC_MARSTAACTV_RADAR_SURVEILLANCE
 *    EEC_MARSTAACTV_RESCUE
 *    EEC_MARSTAACTV_SIGNAL
 *    EEC_MARSTAACTV_STORM_SIGNAL
 *    EEC_MARSTAACTV_STREAM_SIGNAL
 *    EEC_MARSTAACTV_TIDAL_CURRENT_SIGNAL
 *    EEC_MARSTAACTV_TIDE_SIGNAL
 *    EEC_MARSTAACTV_TIME_SIGNAL_LIGHT
 *    EEC_MARSTAACTV_TRAFFIC_SIGNAL
 *    EEC_MARSTAACTV_UNMANNED_OCEAN
 *    EEC_MARSTAACTV_WARNING
 *    EEC_MARSTAACTV_WEATHER_SIGNAL
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_MARINE_STATION_ACTIVITY ((EDCS_Attribute_Code)671)

/*
 * Definition:
 *     The type of <EQUIPMENT> at a marine station.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARSTAEQ_BOMIS
 *    EEC_MARSTAEQ_CAMERA
 *    EEC_MARSTAEQ_FIREBOAT
 *    EEC_MARSTAEQ_FOG_SIGNAL
 *    EEC_MARSTAEQ_FORACS_TRANSDUCER
 *    EEC_MARSTAEQ_ICE_SIGNAL
 *    EEC_MARSTAEQ_LIFEBOAT
 *    EEC_MARSTAEQ_LIFEBOAT_OR_RESCUE
 *    EEC_MARSTAEQ_NMH
 *    EEC_MARSTAEQ_RADAR_TARGET
 *    EEC_MARSTAEQ_RESCUE
 *    EEC_MARSTAEQ_SEMAPHORE
 *    EEC_MARSTAEQ_SIGNAL_MAST
 *    EEC_MARSTAEQ_SIGNAL_TRAFFIC
 *    EEC_MARSTAEQ_SONAR_TARGET
 *    EEC_MARSTAEQ_STA
 *    EEC_MARSTAEQ_THEODOLITE
 *    EEC_MARSTAEQ_TIME_BALL
 *    EEC_MARSTAEQ_TRANSIT_HUT
 *    EEC_MARSTAEQ_UNDERWATER_EMERGENCY_WARNING_SYSTEM
 *    EEC_MARSTAEQ_UNDERWATER_TELEPHONE
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define EAC_MARINE_STATION_EQUIPMENT ((EDCS_Attribute_Code)672)

/*
 * Definition:
 *     The type of a marine survey.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARSURVTY_CONTROLLED
 *    EEC_MARSURVTY_EXAMINATION
 *    EEC_MARSURVTY_NOT_PERFORMED
 *    EEC_MARSURVTY_PASSAGE
 *    EEC_MARSURVTY_REMOTE
 *    EEC_MARSURVTY_SKETCH
 *
 * Group Membership: SURVEY
 */
#define EAC_MARINE_SURVEY_TYPE ((EDCS_Attribute_Code)673)

/*
 * Definition:
 *     The tonnage of a <MARINE_WRECK>, a <HULK>, or other <VESSEL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_MARINE_TONNAGE ((EDCS_Attribute_Code)674)

/*
 * Definition:
 *     The type of restrictions, <DIRECTION>, and other characteristics of
 *     marine tracks.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARTRKTY_BASED_ON_FIXED_MARKS
 *    EEC_MARTRKTY_MANDATORY_DIRECTION
 *    EEC_MARTRKTY_MAXIMUM_AUTHORIZED_DRAFT
 *    EEC_MARTRKTY_NOT_BASED_ON_FIXED_MARKS
 *    EEC_MARTRKTY_RECOMMENDED_DIRECTION
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_TRACK_TYPE ((EDCS_Attribute_Code)675)

/*
 * Definition:
 *     The type of a marine traffic signal.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARTRAFSIGTY_BERTHING
 *    EEC_MARTRAFSIGTY_BRIDGE_PASSAGE
 *    EEC_MARTRAFSIGTY_DOCK
 *    EEC_MARTRAFSIGTY_DREDGING
 *    EEC_MARTRAFSIGTY_FLOOD_BARRAGE
 *    EEC_MARTRAFSIGTY_INTERNATIONAL_PORT_TRAFFIC
 *    EEC_MARTRAFSIGTY_LOCK
 *    EEC_MARTRAFSIGTY_PORT_CONTROL
 *    EEC_MARTRAFSIGTY_PORT_ENTER_DEPART
 *    EEC_MARTRAFSIGTY_TRAFFIC_CONTROL_LIGHT
 *
 * Group Membership: COMMUNICATION
 */
#define EAC_MARINE_TRAFFIC_SIGNAL_TYPE ((EDCS_Attribute_Code)676)

/*
 * Definition:
 *     The type of <COMPONENT> of a marine <TRAFFIC_SEPARATION_SCHEME>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARTSSCMPT_ARROW
 *    EEC_MARTSSCMPT_INBOUND_AREA
 *    EEC_MARTSSCMPT_OUTBOUND_AREA
 *    EEC_MARTSSCMPT_OUTER_BOUNDARY
 *    EEC_MARTSSCMPT_SEP_ZONE_AREA
 *    EEC_MARTSSCMPT_SEP_ZONE_LINE
 *    EEC_MARTSSCMPT_SEP_ZONE_POINT
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARINE_TSS_COMPONENT ((EDCS_Attribute_Code)677)

/*
 * Definition:
 *     The type of a <MARINE_OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARUSE_ALTERNATE_ENTRY
 *    EEC_MARUSE_ALTERNATE_ENTRY_EXIT
 *    EEC_MARUSE_ALTERNATE_EXIT
 *    EEC_MARUSE_ANCHOR_POINT
 *    EEC_MARUSE_BUTTS
 *    EEC_MARUSE_CLOCK
 *    EEC_MARUSE_COMPASS_ADJUSTMENT
 *    EEC_MARUSE_MANDATORY
 *    EEC_MARUSE_MARINE_STATION
 *    EEC_MARUSE_PROHIBITED_REGION
 *    EEC_MARUSE_RESERVED
 *    EEC_MARUSE_ROLLON_ROLLOFF_BERTH
 *    EEC_MARUSE_SINGLE_POINT_MOORING
 *    EEC_MARUSE_TIMEBALL
 *    EEC_MARUSE_TURNING
 *    EEC_MARUSE_VESSEL_BERTH
 *
 * Group Membership: HYDROGRAPHIC_TRNSP
 */
#define EAC_MARINE_USE ((EDCS_Attribute_Code)678)

/*
 * Definition:
 *     The type of a marine warning signal station.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARWARNSIGTY_CABLE
 *    EEC_MARWARNSIGTY_DANGER
 *    EEC_MARWARNSIGTY_DISTRESS
 *    EEC_MARWARNSIGTY_DIVING
 *    EEC_MARWARNSIGTY_ICE
 *    EEC_MARWARNSIGTY_MARINE_OBSTRUCTION
 *    EEC_MARWARNSIGTY_MILITARY_PRACTICE
 *    EEC_MARWARNSIGTY_STORM
 *    EEC_MARWARNSIGTY_TIDAL_STREAM
 *    EEC_MARWARNSIGTY_TIDE
 *    EEC_MARWARNSIGTY_TIDE_GAUGE
 *    EEC_MARWARNSIGTY_TIDE_SCALE
 *    EEC_MARWARNSIGTY_TIME
 *    EEC_MARWARNSIGTY_WATER_LEVEL_GAUGE
 *    EEC_MARWARNSIGTY_WEATHER
 *
 * Group Membership: COMMUNICATION
 */
#define EAC_MARINE_WARNING_SIGNAL_TYPE ((EDCS_Attribute_Code)679)

/*
 * Definition:
 *     The status of a <MARINE_WRECK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARWRCKSTAT_DANGEROUS
 *    EEC_MARWRCKSTAT_NON_DANGEROUS
 *    EEC_MARWRCKSTAT_REMAINS
 *    EEC_MARWRCKSTAT_SHOWING_HULL
 *    EEC_MARWRCKSTAT_SHOWING_MAST
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_MARINE_WRECK_STATUS ((EDCS_Attribute_Code)680)

/*
 * Definition:
 *     The type of a <MARINE_WRECK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARWRCKTY_AIRCRAFT
 *    EEC_MARWRCKTY_AIRCRAFT_CARRIER
 *    EEC_MARWRCKTY_ANOMALIES
 *    EEC_MARWRCKTY_AUXILIARY
 *    EEC_MARWRCKTY_BARGE
 *    EEC_MARWRCKTY_BATTLESHIP
 *    EEC_MARWRCKTY_BULK_CARRIER
 *    EEC_MARWRCKTY_BUOY
 *    EEC_MARWRCKTY_CAISSON
 *    EEC_MARWRCKTY_CARGO
 *    EEC_MARWRCKTY_COASTER
 *    EEC_MARWRCKTY_CRUISER
 *    EEC_MARWRCKTY_DESTROYER
 *    EEC_MARWRCKTY_DREDGE
 *    EEC_MARWRCKTY_DRILL_VESSEL
 *    EEC_MARWRCKTY_EXPLOSIVES
 *    EEC_MARWRCKTY_FERRY
 *    EEC_MARWRCKTY_FISHING_BOAT
 *    EEC_MARWRCKTY_FISHING_REEF
 *    EEC_MARWRCKTY_FRIGATE
 *    EEC_MARWRCKTY_GAS_CARRIER
 *    EEC_MARWRCKTY_GUNBOAT
 *    EEC_MARWRCKTY_HOSPITAL_SHIP
 *    EEC_MARWRCKTY_HYDRO_SURVEY
 *    EEC_MARWRCKTY_JUNK
 *    EEC_MARWRCKTY_LANDING_CRAFT_INFANTRY
 *    EEC_MARWRCKTY_LANDING_SHIP_INFANTRY
 *    EEC_MARWRCKTY_LANDING_SHIP_TANK
 *    EEC_MARWRCKTY_LASH_VESSEL
 *    EEC_MARWRCKTY_LIGHTSHIP
 *    EEC_MARWRCKTY_MINE_HANDLING
 *    EEC_MARWRCKTY_NET_TENDER
 *    EEC_MARWRCKTY_OBSTRUCTION
 *    EEC_MARWRCKTY_PASSENGER_CARGO
 *    EEC_MARWRCKTY_PATROL_CRAFT
 *    EEC_MARWRCKTY_PINNACLE
 *    EEC_MARWRCKTY_ROLLON_ROLLOFF_CONTAINER_VESSEL
 *    EEC_MARWRCKTY_SAILING_VESSEL
 *    EEC_MARWRCKTY_SEA_BEE_LASH_BARGE
 *    EEC_MARWRCKTY_SUBCHASER
 *    EEC_MARWRCKTY_SUBMARINE
 *    EEC_MARWRCKTY_SUBMARINE_FLOAT
 *    EEC_MARWRCKTY_SURVEY_VESSEL
 *    EEC_MARWRCKTY_TANKER
 *    EEC_MARWRCKTY_TARGET
 *    EEC_MARWRCKTY_TENDER_SUB_PLANE_RIG
 *    EEC_MARWRCKTY_TORPEDO_BOAT
 *    EEC_MARWRCKTY_TRANSPORT
 *    EEC_MARWRCKTY_TRAWLER
 *    EEC_MARWRCKTY_TUG
 *    EEC_MARWRCKTY_VERY_LARGE_CONTAINER
 *    EEC_MARWRCKTY_VESSEL_DEBRIS
 *    EEC_MARWRCKTY_WELL_HEAD
 *    EEC_MARWRCKTY_YACHT
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_MARINE_WRECK_TYPE ((EDCS_Attribute_Code)681)

/*
 * Definition:
 *     The publication date of a Notice To Mariners. The date is formatted as
 *     specified by <<DATE_FORMAT>> or by <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TIME, TRNSP
 */
#define EAC_MARINER_NOTICE_DATE ((EDCS_Attribute_Code)682)

/*
 * Definition:
 *     The type of a <MARINE_AID_TO_NAVIGATION> (for example: a <BEACON>
 *     and/or a <BUOY>). This type is evidenced using a mark, sign, or
 *     signal indicating the purpose of that <MARINE_AID_TO_NAVIGATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MARKTY_ANCHORAGE
 *    EEC_MARKTY_ANCHORING_PROHIBITED
 *    EEC_MARKTY_ARTIFICIAL_REEF
 *    EEC_MARKTY_BARGE
 *    EEC_MARKTY_BERTHING_PERMITTED
 *    EEC_MARKTY_BERTHING_PROHIBITED
 *    EEC_MARKTY_CABLE
 *    EEC_MARKTY_CARDINAL
 *    EEC_MARKTY_CAUTIONARY
 *    EEC_MARKTY_CHANNEL_EDGE_GRADIENT
 *    EEC_MARKTY_CHANNEL_SEPARATION
 *    EEC_MARKTY_CLEARING
 *    EEC_MARKTY_CONTROL
 *    EEC_MARKTY_DAYBEACON
 *    EEC_MARKTY_DAYMARK
 *    EEC_MARKTY_DEGAUSSING_RANGE
 *    EEC_MARKTY_DIVING
 *    EEC_MARKTY_EAST_CARDINAL
 *    EEC_MARKTY_ELEVATED_ELECTRICAL_CABLE
 *    EEC_MARKTY_ENTRY_PROHIBITED
 *    EEC_MARKTY_FERRY_CROSSING
 *    EEC_MARKTY_FIRING_DANGER
 *    EEC_MARKTY_FOUL_GROUND
 *    EEC_MARKTY_GENERAL_WARNING
 *    EEC_MARKTY_GPS
 *    EEC_MARKTY_HELIPORT
 *    EEC_MARKTY_ILLUMINATED
 *    EEC_MARKTY_INFORMATION
 *    EEC_MARKTY_INSTALLATION
 *    EEC_MARKTY_KEEPOUT
 *    EEC_MARKTY_LATERAL
 *    EEC_MARKTY_LEADING
 *    EEC_MARKTY_MARINE_FARM
 *    EEC_MARKTY_MARKER_SHIP
 *    EEC_MARKTY_MAXIMUM_VESSEL_DRAFT
 *    EEC_MARKTY_MEASURED_DISTANCE
 *    EEC_MARKTY_MILITARY_PRACTICE
 *    EEC_MARKTY_MODIFIED_PORT_LATERAL
 *    EEC_MARKTY_MODIFIED_STARBOARD_LATERAL
 *    EEC_MARKTY_MOORING
 *    EEC_MARKTY_NORTH_CARDINAL
 *    EEC_MARKTY_NOTICE
 *    EEC_MARKTY_ODAS
 *    EEC_MARKTY_OUTFALL
 *    EEC_MARKTY_OVERTAKING_PROHIBITED
 *    EEC_MARKTY_PIPELINE
 *    EEC_MARKTY_PORT_HAND_LATERAL
 *    EEC_MARKTY_PRIVATE
 *    EEC_MARKTY_QUARANTINE
 *    EEC_MARKTY_RADAR_TRANSPONDER
 *    EEC_MARKTY_RECORDING
 *    EEC_MARKTY_RECREATION_ZONE
 *    EEC_MARKTY_REDUCED_WAKE
 *    EEC_MARKTY_REFUGE
 *    EEC_MARKTY_REFUGE_BEACON
 *    EEC_MARKTY_RSTRCT_HORIZ_CLEARANCE
 *    EEC_MARKTY_RSTRCT_VERT_CLEARANCE
 *    EEC_MARKTY_SAFE_WATER
 *    EEC_MARKTY_SEAPLANE_ANCHORAGE
 *    EEC_MARKTY_SEAPLANE_LANDING
 *    EEC_MARKTY_SOUND_SHIPS_SIREN
 *    EEC_MARKTY_SOUTH_CARDINAL
 *    EEC_MARKTY_SPECIAL_PURPOSE
 *    EEC_MARKTY_SPEED_LIMIT
 *    EEC_MARKTY_SPOIL_GROUND
 *    EEC_MARKTY_STARBOARD_HAND_LATERAL
 *    EEC_MARKTY_STOP
 *    EEC_MARKTY_STRONG_CURRENT
 *    EEC_MARKTY_SWIMMING
 *    EEC_MARKTY_TARGET
 *    EEC_MARKTY_TELEPHONE
 *    EEC_MARKTY_TRAFFIC_SEPARATION_SCHEME
 *    EEC_MARKTY_TWO_WAY_PROHIBITED
 *    EEC_MARKTY_UNKNOWN_PURPOSE
 *    EEC_MARKTY_WELL_HEAD
 *    EEC_MARKTY_WEST_CARDINAL
 *    EEC_MARKTY_WORK_IN_PROGRESS
 *    EEC_MARKTY_YACHTING
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MARK_TYPE ((EDCS_Attribute_Code)683)

/*
 * Definition:
 *     The mass of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_MASS ((EDCS_Attribute_Code)684)

/*
 * Definition:
 *     The ratio of the extinction coefficient to the <<MATERIAL_DENSITY>> of
 *     the transmission medium; alternatively, the natural logarithm of
 *     <<TRANSMISSIVITY>> divided by <<LENGTH>> of propagation and again by
 *     <<MATERIAL_DENSITY>>; the mass extinction coefficient.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_ATTENUATION_COEFF
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_MASS_EXTINCTION_COEFFICIENT ((EDCS_Attribute_Code)685)

/*
 * Definition:
 *     The type of <EQUIPMENT> a <MAST> is intended to support.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MASTTY_COMMUNICATIONS
 *    EEC_MASTTY_ILLUMINATION
 *    EEC_MASTTY_MICROWAVE
 *    EEC_MASTTY_RADIO
 *    EEC_MASTTY_TELEVISION
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define EAC_MAST_TYPE ((EDCS_Attribute_Code)686)

/*
 * Definition:
 *     The <<MASS>> per unit <<VOLUME>> of a <MATERIAL>; the material density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_MATERIAL_DENSITY ((EDCS_Attribute_Code)687)

/*
 * Definition:
 *     The <FACILITY>s available at a <LOCATION> or in the near vicinity for
 *     the handling of <MATERIAL>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MATHANDFAC_BULK_FUEL
 *    EEC_MATHANDFAC_BULK_GRAIN
 *    EEC_MATHANDFAC_BULK_LIQUID
 *    EEC_MATHANDFAC_BULK_ORE
 *    EEC_MATHANDFAC_CIVILIAN_LABOUR
 *    EEC_MATHANDFAC_CONTAINER
 *    EEC_MATHANDFAC_CONTAINER_TRAILER
 *    EEC_MATHANDFAC_CRANE
 *    EEC_MATHANDFAC_DOCK_LEVELLING
 *    EEC_MATHANDFAC_FORKLIFT
 *    EEC_MATHANDFAC_NONE_PRESENT
 *    EEC_MATHANDFAC_RAIL_TRANSFER_EQUIPMENT
 *    EEC_MATHANDFAC_ROLLON_ROLLOFF
 *    EEC_MATHANDFAC_STRADDLE_CARRIER
 *    EEC_MATHANDFAC_SYNCROLIFT
 *
 * Group Membership: USAGE_REGION
 */
#define EAC_MATERIAL_HANDLING_FACILITIES ((EDCS_Attribute_Code)688)

/*
 * Definition:
 *     The <<WATERBODY_TEMPERATURE>> that is one standard deviation above a
 *     <<MEAN_WATERBODY_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_MAX_WATERBODY_TEMP_1_STD_DEV ((EDCS_Attribute_Code)689)

/*
 * Definition:
 *     The <<WATERBODY_TEMPERATURE>> that is two standard deviations above a
 *     <<MEAN_WATERBODY_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_MAX_WATERBODY_TEMP_2_STD_DEV ((EDCS_Attribute_Code)690)

/*
 * Definition:
 *     The <<WATERBODY_TEMPERATURE>> that is three standard deviations above
 *     a <<MEAN_WATERBODY_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_MAX_WATERBODY_TEMP_3_STD_DEV ((EDCS_Attribute_Code)691)

/*
 * Definition:
 *     The maximum <<TEMPERATURE>> that a particular <MATERIAL> or <OBJECT>
 *     can achieve.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL, TEMPERATURE
 */
#define EAC_MAXIMUM_ACHIEVABLE_TEMPERATURE ((EDCS_Attribute_Code)692)

/*
 * Definition:
 *     The maximum <<AIR_TEMPERATURE>> that occurred at a given <LOCATION>
 *     during a specific <<TIME_PERIOD>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MAXIMUM_AIR_TEMPERATURE ((EDCS_Attribute_Code)693)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> for which a <<MAXIMUM_AIR_TEMPERATURE>> was
 *     recorded.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: ATMOSPHERE, TIME
 */
#define EAC_MAXIMUM_AIR_TEMPERATURE_PERIOD ((EDCS_Attribute_Code)694)

/*
 * Definition:
 *     The highest altitude in an <AIR_TRANSPORTATION_ROUTE> at which
 *     adequate reception of <AID_TO_NAVIGATION> signals is assured; the
 *     maximum authorized altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, COMMUNICATION, LOCATION, TRNSP
 */
#define EAC_MAXIMUM_AUTHORIZED_ALTITUDE ((EDCS_Attribute_Code)695)

/*
 * Definition:
 *     The <<MAXIMUM_WAVE_HEIGHT>> in a <SURF_ZONE>; the maximum breaker
 *     height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_MAXIMUM_BREAKER_HEIGHT ((EDCS_Attribute_Code)696)

/*
 * Definition:
 *     The maximum <<DEPTH>> within a <WATERBODY_FLOOR_REGION> defined by a
 *     <DEPTH_CONTOUR_LINE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_MAXIMUM_CONTOUR_DEPTH ((EDCS_Attribute_Code)697)

/*
 * Definition:
 *     The maximum <<WATER_CURRENT_SPEED>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_MAXIMUM_CURRENT_SPEED ((EDCS_Attribute_Code)698)

/*
 * Definition:
 *     The maximum <<DEW_POINT_TEMPERATURE>> from a series of samples.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MAXIMUM_DEW_POINT_TEMPERATURE ((EDCS_Attribute_Code)699)

/*
 * Definition:
 *     The highest <FLIGHT_LEVEL> assigned by air traffic control; the
 *     maximum flight level. The values are expressed as flight level values
 *     by first dividing by 30,48 metres (100 feet) and then rounding to
 *     nearest 304,8 metres (1 000 feet) in accordance with the structure of
 *     the ICAO Standard Atmosphere. EXAMPLE The value for the 500
 *     hectopascals level is 180,0, corresponding to the ICAO standard
 *     height 5 574 metres (18 289 feet).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_MAXIMUM_FLIGHT_LEVEL ((EDCS_Attribute_Code)700)

/*
 * Definition:
 *     The maximum <<DEPTH>> (draft) of <ICE_KEEL>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_MAXIMUM_ICE_KEEL_DRAFT ((EDCS_Attribute_Code)701)

/*
 * Definition:
 *     The maximum height (or depth) of <TERRAIN_OBSTACLE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LAND_TRNSP, LOCATION, TRNSP
 */
#define EAC_MAXIMUM_OBSTACLE_HEIGHT ((EDCS_Attribute_Code)702)

/*
 * Definition:
 *     The maximum of a <SET> of <<OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL>>
 *     measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_MAXIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL ((EDCS_Attribute_Code)703)

/*
 * Definition:
 *     The intensity of electromagnetic radiation per unit solid angle in the
 *     <DIRECTION> for which the value is maximal; the maximum radiant
 *     intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RADIANT_INTENSITY
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_MAXIMUM_RADIANT_INTENSITY ((EDCS_Attribute_Code)704)

/*
 * Definition:
 *     The maximum depth of non-flowing/standing <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, PHYSIOGRAPHY, WATERBODY_STATE
 */
#define EAC_MAXIMUM_STANDING_WATER_DEPTH ((EDCS_Attribute_Code)705)

/*
 * Definition:
 *     The maximum <<TERRAIN_ELEVATION>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY
 */
#define EAC_MAXIMUM_TERRAIN_ELEVATION ((EDCS_Attribute_Code)706)

/*
 * Definition:
 *     The greatest distance between a <LAND_TRANSPORTATION_ROUTE> and any
 *     obstruction vertically above it; the maximum vertical clearance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_MAXIMUM_VERTICAL_CLEARANCE ((EDCS_Attribute_Code)707)

/*
 * Definition:
 *     The maximum range of visibility into an <OBJECT> (for example: a
 *     forest).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION, LIGHTING_AND_VISIBILITY
 */
#define EAC_MAXIMUM_VISIBILITY_RANGE ((EDCS_Attribute_Code)708)

/*
 * Definition:
 *     The maximum voltage available on an <ELECTRICAL_CABLE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: ELECTRIC_POTENTIAL
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE
 */
#define EAC_MAXIMUM_VOLTAGE ((EDCS_Attribute_Code)709)

/*
 * Definition:
 *     The maximum <<WATER_DEPTH>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_MAXIMUM_WATER_DEPTH ((EDCS_Attribute_Code)710)

/*
 * Definition:
 *     The mean <<HEIGHT>> of the highest tenth of <WATER_WAVE>s on a
 *     <WATERBODY_SURFACE>, measured from trough to crest.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_MAXIMUM_WAVE_HEIGHT ((EDCS_Attribute_Code)711)

/*
 * Definition:
 *     The maximum <<WIND_GUST_SPREAD>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_MAXIMUM_WIND_GUST_SPREAD ((EDCS_Attribute_Code)712)

/*
 * Definition:
 *     The maximum or peak <<WIND_SPEED>> including gusts.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_MAXIMUM_WIND_SPEED ((EDCS_Attribute_Code)713)

/*
 * Definition:
 *     The mean historical (climatology) <<AIR_DENSITY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_MEAN_AIR_DENSITY_CLIM ((EDCS_Attribute_Code)714)

/*
 * Definition:
 *     The standard deviation of <<MEAN_AIR_DENSITY_CLIM>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_MEAN_AIR_DENSITY_CLIM_STD_DEV ((EDCS_Attribute_Code)715)

/*
 * Definition:
 *     The mean <<AIR_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_AIR_TEMP ((EDCS_Attribute_Code)716)

/*
 * Definition:
 *     The mean historical (climatology) <<AIR_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_AIR_TEMP_CLIM ((EDCS_Attribute_Code)717)

/*
 * Definition:
 *     The standard deviation of <<MEAN_AIR_TEMP_CLIM>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_AIR_TEMP_CLIM_STD_DEV ((EDCS_Attribute_Code)718)

/*
 * Definition:
 *     The historical (climatology) quantity of mean difference between the
 *     mean <<AIR_TEMPERATURE>> at an initial time and the mean
 *     <<AIR_TEMPERATURE>> at an offset from that time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_AIR_TEMP_DIFFERENCE_CLIM ((EDCS_Attribute_Code)719)

/*
 * Definition:
 *     The historical (climatology) quantity of maximum difference between
 *     the mean <<AIR_TEMPERATURE>> at an initial time and the mean
 *     <<AIR_TEMPERATURE>> at an offset from that time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_AIR_TEMP_MAX_DIFFERENCE_CLIM ((EDCS_Attribute_Code)720)

/*
 * Definition:
 *     The historical (climatology) quantity of minimum difference between
 *     the mean <<AIR_TEMPERATURE>> at an initial time and the mean
 *     <<AIR_TEMPERATURE>> at an offset from that time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_AIR_TEMP_MIN_DIFFERENCE_CLIM ((EDCS_Attribute_Code)721)

/*
 * Definition:
 *     The standard deviation of <<MEAN_AIR_WATER_TEMP_DIFFERENCE>>
 *     measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE, WATERBODY_SURFACE
 */
#define EAC_MEAN_AIR_WATER_TEMP_DIFF_CLIM_STD_DEV ((EDCS_Attribute_Code)722)

/*
 * Definition:
 *     The mean difference between an <<AIR_TEMPERATURE>> and an adjacent
 *     <<WATERBODY_SURFACE_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE, WATERBODY_SURFACE
 */
#define EAC_MEAN_AIR_WATER_TEMP_DIFFERENCE ((EDCS_Attribute_Code)723)

/*
 * Definition:
 *     The mean <<OUTSIDE_DIAMETER>> of the drops of <WATER> in a <CLOUD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, DIMENSION
 */
#define EAC_MEAN_CLOUD_DROP_DIAMETER ((EDCS_Attribute_Code)724)

/*
 * Definition:
 *     The mean of the historical (climatology) measured
 *     <<DEW_POINT_TEMPERATURE>>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_DEW_POINT_CLIMATOLOGY ((EDCS_Attribute_Code)725)

/*
 * Definition:
 *     The standard deviation of <<MEAN_DEW_POINT_CLIMATOLOGY>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_DEW_POINT_CLIMATOLOGY_STD_DEV ((EDCS_Attribute_Code)726)

/*
 * Definition:
 *     The mean <<DEW_POINT_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MEAN_DEW_POINT_TEMPERATURE ((EDCS_Attribute_Code)727)

/*
 * Definition:
 *     The mean rate of loss as a function of time of <WATER> from an
 *     <OBJECT> due to evaporation and transpiration.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUME_FLOW_RATE
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_MEAN_EVAP_TRANSPIRATION_RATE ((EDCS_Attribute_Code)728)

/*
 * Definition:
 *     The mean historical (climatology) altitude of <LOCATION>s in the
 *     <ATMOSPHERE> expressed into the geopotential of those altitudes.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: GEOPOTENTIAL_ENERGY_LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_MEAN_GEOPOTENTIAL_ALT_CLIM ((EDCS_Attribute_Code)729)

/*
 * Definition:
 *     The standard deviation of <<MEAN_GEOPOTENTIAL_ALT_CLIM>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: GEOPOTENTIAL_ENERGY_LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_MEAN_GEOPOTENTIAL_ALT_CLIM_STD_DEV ((EDCS_Attribute_Code)730)

/*
 * Definition:
 *     The mean <<DEPTH>> (draft) of <ICE> on a <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_MEAN_ICE_DRAFT ((EDCS_Attribute_Code)731)

/*
 * Definition:
 *     The standard deviation of <<MEAN_ICE_DRAFT>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_MEAN_ICE_DRAFT_STD_DEV ((EDCS_Attribute_Code)732)

/*
 * Definition:
 *     The mean <<DEPTH>> (draft) of <ICE_KEEL>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_MEAN_ICE_KEEL_DRAFT ((EDCS_Attribute_Code)733)

/*
 * Definition:
 *     The standard deviation of <<MEAN_ICE_KEEL_DRAFT>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_MEAN_ICE_KEEL_DRAFT_STD_DEV ((EDCS_Attribute_Code)734)

/*
 * Definition:
 *     The mean separation distance between <ICE_KEEL>s measured between the
 *     peaks of the <ICE_KEEL>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_MEAN_ICE_KEEL_SEPARATION ((EDCS_Attribute_Code)735)

/*
 * Definition:
 *     The standard deviation of <<MEAN_ICE_KEEL_SEPARATION>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_MEAN_ICE_KEEL_SEPARATION_STD_DEV ((EDCS_Attribute_Code)736)

/*
 * Definition:
 *     The mean luminous intensity of a <LIGHT> within its
 *     <<LIGHT_BEAM_SPREAD>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LUMINANCE_INTENSITY
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_MEAN_LUMINOUS_INTENSITY ((EDCS_Attribute_Code)737)

/*
 * Definition:
 *     The mean declination angle between magnetic north and geodetic north
 *     of the <MAGNETIC_FIELD> of a <PLANET>, typically averaged over one
 *     hour.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, SPACE
 */
#define EAC_MEAN_MAGNETIC_FIELD_DECLINATION_ANGLE ((EDCS_Attribute_Code)738)

/*
 * Definition:
 *     The mean <<MAGNETIC_FIELD_EAST_COMPONENT>> measured as a horizontal
 *     angle east (positive value) or west (negative value) according to
 *     whether magnetic north lies east or west of geodetic north, typically
 *     averaged over one hour.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MEAN_MAGNETIC_FIELD_EAST_COMPONENT ((EDCS_Attribute_Code)739)

/*
 * Definition:
 *     The mean strength of the full vector component of the <MAGNETIC_FIELD>
 *     of a <PLANET> (vector sum of all components), typically averaged over
 *     one hour.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MEAN_MAGNETIC_FIELD_FULL_COMPONENT ((EDCS_Attribute_Code)740)

/*
 * Definition:
 *     The mean <<MAGNETIC_FIELD_HORIZONTAL_COMPONENT>> (vector sum of
 *     <<MAGNETIC_FIELD_EAST_COMPONENT>> and
 *     <<MAGNETIC_FIELD_NORTH_COMPONENT>>), typically averaged over one hour.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MEAN_MAGNETIC_FIELD_HORIZONTAL_COMPONENT ((EDCS_Attribute_Code)741)

/*
 * Definition:
 *     The mean <<MAGNETIC_FIELD_INCLINATION_ANGLE>>, typically averaged over
 *     one hour.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, SPACE
 */
#define EAC_MEAN_MAGNETIC_FIELD_INCLINATION_ANGLE ((EDCS_Attribute_Code)742)

/*
 * Definition:
 *     The mean <<MAGNETIC_FIELD_NORTH_COMPONENT>>, typically averaged over
 *     one hour.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MEAN_MAGNETIC_FIELD_NORTH_COMPONENT ((EDCS_Attribute_Code)743)

/*
 * Definition:
 *     The mean <<MAGNETIC_FIELD_VERTICAL_COMPONENT>>, typically averaged
 *     over one hour.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MAGNETIC_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_MEAN_MAGNETIC_FIELD_VERTICAL_COMPONENT ((EDCS_Attribute_Code)744)

/*
 * Definition:
 *     The mean diameter of individual <OBJECT>s within a delineated <REGION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_MEAN_OBJECT_DIAMETER ((EDCS_Attribute_Code)745)

/*
 * Definition:
 *     The mean distance between the centroids of adjacent <OBJECT>s within a
 *     delineated <REGION>; the mean object spacing.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_MEAN_OBJECT_SPACING ((EDCS_Attribute_Code)746)

/*
 * Definition:
 *     The mean rate of potential loss of <WATER> from the <SOIL> due to
 *     evaporation and transpiration.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUME_FLOW_RATE
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_MEAN_POTENTIAL_SOIL_EVAP_TRANSPIRATION_RATE ((EDCS_Attribute_Code)747)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> required for two successive primary
 *     breaking <WATER_WAVE> crests in a wave spectra to pass a fixed point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_MEAN_PRIMARY_BREAKER_PERIOD ((EDCS_Attribute_Code)748)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> required for two successive primary
 *     <WATER_WAVE> crests (combined <WIND_WAVE> and <SWELL_WAVE>) in a wave
 *     spectra to pass a fixed point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_MEAN_PRIMARY_WAVE_PERIOD ((EDCS_Attribute_Code)749)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> required for two successive secondary
 *     breaking <WATER_WAVE> crests in a wave spectra to pass a fixed point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_MEAN_SECONDARY_BREAKER_PERIOD ((EDCS_Attribute_Code)750)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> required for two successive secondary
 *     <WATER_WAVE> crests in a wave spectra to pass a fixed point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_MEAN_SECONDARY_WAVE_PERIOD ((EDCS_Attribute_Code)751)

/*
 * Definition:
 *     The mean <<MEAN_EVAP_TRANSPIRATION_RATE >> of the <SOIL> of a
 *     <TERRAIN_SURFACE_REGION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUME_FLOW_RATE
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_MEAN_SOIL_EVAP_TRANSPIRATION_RATE ((EDCS_Attribute_Code)752)

/*
 * Definition:
 *     The mean rate of change as a function of time of long wave (4 to 80
 *     micrometres) solar radiation incident on a <SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SPACE, SURFACE
 */
#define EAC_MEAN_SOLAR_LONGWAVE_RADIATION ((EDCS_Attribute_Code)753)

/*
 * Definition:
 *     The mean seasonal high <<WATER_DEPTH>> in an <INLAND_WATER> exclusive
 *     of high water due to runoff.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: HYDROLOGY, LOCATION, TIME, WATERBODY_FLOOR
 */
#define EAC_MEAN_SSNL_HIGH_WATER_DEPTH ((EDCS_Attribute_Code)754)

/*
 * Definition:
 *     The mean seasonal high <<WATER_CURRENT_SPEED>>, estimated within the
 *     delineation of an <INLAND_WATER>, exclusive of high water due to
 *     runoff.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: HYDROLOGY, RATE_OR_RATIO, TIME, WATERBODY_STATE
 */
#define EAC_MEAN_SSNL_HIGH_WATER_SPEED ((EDCS_Attribute_Code)755)

/*
 * Definition:
 *     The mean seasonal low <<WATER_DEPTH>> in an <INLAND_WATER> exclusive
 *     of low water due to drought.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: HYDROLOGY, LOCATION, TIME, WATERBODY_FLOOR
 */
#define EAC_MEAN_SSNL_LOW_WATER_DEPTH ((EDCS_Attribute_Code)756)

/*
 * Definition:
 *     The mean seasonal low <<WATER_CURRENT_SPEED>> in an <INLAND_WATER>
 *     exclusive of low water due to drought.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: HYDROLOGY, RATE_OR_RATIO, TIME, WATERBODY_STATE
 */
#define EAC_MEAN_SSNL_LOW_WATER_SPEED ((EDCS_Attribute_Code)757)

/*
 * Definition:
 *     The mean <<STEM_DIAMETER>> of <VEGETATION> measured at a
 *     <<HEIGHT_AGL>> of 1,4 metres.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define EAC_MEAN_STEM_DIAMETER ((EDCS_Attribute_Code)758)

/*
 * Definition:
 *     The mean stem spacing of <VEGETATION> measured at a <<HEIGHT_AGL>> of
 *     1,4 metres.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define EAC_MEAN_STEM_SPACING ((EDCS_Attribute_Code)759)

/*
 * Definition:
 *     The mean <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which
 *     <SWELL_WAVE>s are arriving.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_MEAN_SWELL_WAVE_DIRECTION ((EDCS_Attribute_Code)760)

/*
 * Definition:
 *     The mean <<HEIGHT>> of <SWELL_WAVE>s measured from trough to crest.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_MEAN_SWELL_WAVE_HEIGHT ((EDCS_Attribute_Code)761)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> required for the crests of two successive
 *     <SWELL_WAVE>s to pass a fixed point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_MEAN_SWELL_WAVE_PERIOD ((EDCS_Attribute_Code)762)

/*
 * Definition:
 *     The mean of <<TERRAIN_ELEVATION>>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY
 */
#define EAC_MEAN_TERRAIN_ELEVATION ((EDCS_Attribute_Code)763)

/*
 * Definition:
 *     The standard deviation of <<MEAN_TERRAIN_ELEVATION>>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY
 */
#define EAC_MEAN_TERRAIN_ELEVATION_STD_DEV ((EDCS_Attribute_Code)764)

/*
 * Definition:
 *     The mean <<DEPTH>> from a tidal <SURFACE_DATUM> to the
 *     <WATERBODY_FLOOR>; the mean tidal water depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LOCATION, WATERBODY_FLOOR
 */
#define EAC_MEAN_TIDAL_WATER_DEPTH ((EDCS_Attribute_Code)765)

/*
 * Definition:
 *     The standard deviation of <<MEAN_WATERBODY_TEMPERATURE>>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_MEAN_WATERBODY_TEMP_STD_DEV ((EDCS_Attribute_Code)766)

/*
 * Definition:
 *     The mean of <<WATERBODY_TEMPERATURE>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_MEAN_WATERBODY_TEMPERATURE ((EDCS_Attribute_Code)767)

/*
 * Definition:
 *     The mean of <<WATER_DEPTH>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_MEAN_WATER_DEPTH ((EDCS_Attribute_Code)768)

/*
 * Definition:
 *     The mean <<WATER_CURRENT_SPEED>>, estimated within the delineation of
 *     a <WATERBODY>, exclusive of high <WATER_CURRENT>s due to runoff or
 *     low <WATER_CURRENT>s due to drought.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_MEAN_WATER_SPEED ((EDCS_Attribute_Code)769)

/*
 * Definition:
 *     The mean <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which
 *     significant <WATER_WAVE>s (combined <WIND_WAVE>s and <SWELL_WAVE>s)
 *     in the wave spectra are arriving.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_MEAN_WAVE_DIRECTION ((EDCS_Attribute_Code)770)

/*
 * Definition:
 *     The mean apparent <<HEIGHT>> of <WATER_WAVE>s (combined <WIND_WAVE>s
 *     and <SWELL_WAVE>s) measured from trough to crest.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_MEAN_WAVE_HEIGHT ((EDCS_Attribute_Code)771)

/*
 * Definition:
 *     The standard deviation of <<MEAN_WAVE_HEIGHT>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_MEAN_WAVE_HEIGHT_STD_DEV ((EDCS_Attribute_Code)772)

/*
 * Definition:
 *     The mean distance between the crests of two successive <WATER_WAVE>s
 *     (combined <WIND_WAVE>s and <SWELL_WAVE>s); the mean wave length.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_MEAN_WAVE_LENGTH ((EDCS_Attribute_Code)773)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> required for two successive <WATER_WAVE>s
 *     (<WIND_WAVE> and <SWELL_WAVE>) in a wave spectra to pass a fixed
 *     point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_MEAN_WAVE_PERIOD ((EDCS_Attribute_Code)774)

/*
 * Definition:
 *     The mean <<WIND_SPEED>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_MEAN_WIND_SPEED ((EDCS_Attribute_Code)775)

/*
 * Definition:
 *     The standard deviation of <<MEAN_WIND_SPEED>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_MEAN_WIND_SPEED_STD_DEV ((EDCS_Attribute_Code)776)

/*
 * Definition:
 *     The mean <<WIND_WAVE_HEIGHT>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_MEAN_WIND_WAVE_HEIGHT ((EDCS_Attribute_Code)777)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> required for the crests of two successive
 *     <WIND_WAVE>s to pass a fixed point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_MEAN_WIND_WAVE_PERIOD ((EDCS_Attribute_Code)778)

/*
 * Definition:
 *     The depth below a <SURFACE> at which a measurement was taken.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_MEASUREMENT_DEPTH ((EDCS_Attribute_Code)779)

/*
 * Definition:
 *     The <<HEIGHT>> above a <SURFACE> at which a measurement was taken.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION
 */
#define EAC_MEASUREMENT_HEIGHT ((EDCS_Attribute_Code)780)

/*
 * Definition:
 *     The type of a <MERCHANT_MARINE_VESSEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MRCHMARVESTY_ADEPT_CLASS_TUGBOAT
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, TRNSP, VEHICLE
 */
#define EAC_MERCHANT_MARINE_VESSEL_TYPE ((EDCS_Attribute_Code)781)

/*
 * Definition:
 *     The areal density of merchant <WATER_SURFACE_VESSEL>s (gross weight
 *     greater than 907 000 kilograms (approximately 1 000 tons); <<LENGTH>>
 *     greater than 18 metres) in a <WATERBODY_SURFACE_REGION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, RATE_OR_RATIO, TRNSP, VEHICLE, WATERBODY_SURFACE
 */
#define EAC_MERCHANT_VESSEL_DENSITY ((EDCS_Attribute_Code)782)

/*
 * Definition:
 *     The measured distance of a meteorological transmissivity observation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION
 */
#define EAC_MET_TRANSMISSITIVITY_DISTANCE ((EDCS_Attribute_Code)783)

/*
 * Definition:
 *     The electromagnetic <<WAVELENGTH>> used for a meteorological
 *     transmissivity distance observation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, EM_PHENOMENON
 */
#define EAC_MET_TRANSMISSITIVITY_WAVELENGTH ((EDCS_Attribute_Code)784)

/*
 * Definition:
 *     The distance at which an ideal observer can detect a high-contrast
 *     target assuming a detection contrast threshold of 0,02 and a target
 *     inherent contrast of 1,0; the meteorological range.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIGHTING_AND_VISIBILITY
 */
#define EAC_METEOROLOGICAL_RANGE ((EDCS_Attribute_Code)785)

/*
 * Definition:
 *     The <<CLOUD_BASE_LEVEL>> of a <MIDDLE_CLOUD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_MIDDLE_CLOUD_BASE_LEVEL ((EDCS_Attribute_Code)786)

/*
 * Definition:
 *     The fraction of the sky covered by <MIDDLE_CLOUD>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_MIDDLE_CLOUD_COVERAGE ((EDCS_Attribute_Code)787)

/*
 * Definition:
 *     The genus of a <MIDDLE_CLOUD>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MIDCLDGENUS_ALTOCUMULUS
 *    EEC_MIDCLDGENUS_ALTOSTRATUS
 *    EEC_MIDCLDGENUS_NIMBOSTRATUS
 *    EEC_MIDCLDGENUS_NONE_PRESENT
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_MIDDLE_CLOUD_GENUS ((EDCS_Attribute_Code)788)

/*
 * Definition:
 *     The <<CLOUD_TOP_LEVEL>> of a <MIDDLE_CLOUD>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LOCATION
 */
#define EAC_MIDDLE_CLOUD_TOP_LEVEL ((EDCS_Attribute_Code)789)

/*
 * Definition:
 *     The type of observed <MIDDLE_CLOUD>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MIDCLDTYOBV_NO_MIDDLE_CLOUDS
 *    EEC_MIDCLDTYOBV_ALTOSTRATUS_TRANSLUCIDUS
 *    EEC_MIDCLDTYOBV_ALTOSTRATUS_OPACUS
 *    EEC_MIDCLDTYOBV_SINGLE_LEVEL_ALTOCM
 *    EEC_MIDCLDTYOBV_ALTOCM_PATCHES
 *    EEC_MIDCLDTYOBV_ALTOCM_TRANSLUCIDUS
 *    EEC_MIDCLDTYOBV_ALTOCM_CUMULOGEN
 *    EEC_MIDCLDTYOBV_MULTILAYER_ALTOCM
 *    EEC_MIDCLDTYOBV_ALTOCM_CASTELLANUS
 *    EEC_MIDCLDTYOBV_CHAOTIC_ALTOCM
 *    EEC_MIDCLDTYOBV_MIDDLE_CLOUDS_INVISIBLE
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_MIDDLE_CLOUD_TYPE_OBSERVED ((EDCS_Attribute_Code)790)

/*
 * Definition:
 *     The type of a military asset. EXAMPLES <VEHICLE>, <EQUIPMENT>,
 *     <PERSONNEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MILASSETTY_AIR_DEFENCE_ARTILLERY
 *    EEC_MILASSETTY_ARMOURED_FIGHTING_VEHICLE
 *    EEC_MILASSETTY_ARMOURED_TRACKED_FIGHTING_VEHICLE
 *    EEC_MILASSETTY_ARMOURED_UTILITY_VEHICLE
 *    EEC_MILASSETTY_ARMOURED_VEHICLE
 *    EEC_MILASSETTY_C4I_SYSTEM
 *    EEC_MILASSETTY_CIVILIAN_VEHICLE
 *    EEC_MILASSETTY_FIELD_ARTILLERY
 *    EEC_MILASSETTY_HEAVY_EQUIPMENT_TRANSPORT
 *    EEC_MILASSETTY_INFANTRY
 *    EEC_MILASSETTY_LARGE_TRACK_UTILITY_VEHICLE
 *    EEC_MILASSETTY_LARGE_WHEEL_UTILITY_VEHICLE
 *    EEC_MILASSETTY_MORTAR
 *    EEC_MILASSETTY_SELF_PROPELLED_ARTILLERY
 *    EEC_MILASSETTY_SMALL_TRACK_UTILITY_VEHICLE
 *    EEC_MILASSETTY_SMALL_WHEEL_UTILITY_VEHICLE
 *    EEC_MILASSETTY_SUPPORT_EQUIPMENT
 *    EEC_MILASSETTY_TOWED_ARTILLERY
 *    EEC_MILASSETTY_TRAILER
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MILITARY_ASSET_TYPE ((EDCS_Attribute_Code)791)

/*
 * Definition:
 *     Information identifying and/or describing a <BRIDGE>, typically one
 *     that is subject to preplanned military interdiction.
 *
 * Value Type: STRING
 *
 * Group Membership: IDENTIFICATION, LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_MILITARY_BRIDGE_INFORMATION ((EDCS_Attribute_Code)792)

/*
 * Definition:
 *     The military allegiance of the force responsible for the creation or
 *     maintenance of a <MAN_MADE_OBJECT>. The value is specified in the
 *     following manner: (1) All allegiances are from the perspective of the
 *     nation or force providing the classification. The "nation or force
 *     providing the classification" is not defined in this International
 *     Standard and must be determined from the context in which this EA is
 *     used. (2) In a conflict that involves more than two mutual
 *     combatants, nine additional enumerants are defined for identification
 *     of the combatants. The number nine was chosen because, historically,
 *     more than nine groups are unlikely to simultaneously engage in mutual
 *     hostilities. (3) The groups identified by each of the nine additional
 *     enumerants are not defined in this International Standard and must be
 *     determined by the context in which this EA is used.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MILFORCALEGN_FRIEND
 *    EEC_MILFORCALEGN_HOSTILE
 *    EEC_MILFORCALEGN_NEUTRAL
 *    EEC_MILFORCALEGN_ALTERNATE_1
 *    EEC_MILFORCALEGN_ALTERNATE_2
 *    EEC_MILFORCALEGN_ALTERNATE_3
 *    EEC_MILFORCALEGN_ALTERNATE_4
 *    EEC_MILFORCALEGN_ALTERNATE_5
 *    EEC_MILFORCALEGN_ALTERNATE_6
 *    EEC_MILFORCALEGN_ALTERNATE_7
 *    EEC_MILFORCALEGN_ALTERNATE_8
 *    EEC_MILFORCALEGN_ALTERNATE_9
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MILITARY_FORCE_ALLEGIANCE ((EDCS_Attribute_Code)793)

/*
 * Definition:
 *     The type of use of a military <REGION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MILUSE_AMMUNITION_STORAGE
 *    EEC_MILUSE_AMMUNITION_SUPPLY
 *    EEC_MILUSE_BULK_STORAGE
 *    EEC_MILUSE_INSTALLATION
 *    EEC_MILUSE_MAINTENANCE
 *    EEC_MILUSE_POL
 *    EEC_MILUSE_POL_OR_BULK_STORAGE
 *
 * Group Membership: MILITARY_SCIENCE, USAGE_REGION
 */
#define EAC_MILITARY_USE ((EDCS_Attribute_Code)794)

/*
 * Definition:
 *     The <<WATERBODY_TEMPERATURE>> that is one standard deviation below a
 *     <<MEAN_WATERBODY_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_MIN_WATERBODY_TEMP_1_STD_DEV ((EDCS_Attribute_Code)795)

/*
 * Definition:
 *     The <<WATERBODY_TEMPERATURE>> that is two standard deviations below a
 *     <<MEAN_WATERBODY_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_MIN_WATERBODY_TEMP_2_STD_DEV ((EDCS_Attribute_Code)796)

/*
 * Definition:
 *     The <<WATERBODY_TEMPERATURE>> that is three standard deviations below
 *     a <<MEAN_WATERBODY_TEMPERATURE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_MIN_WATERBODY_TEMP_3_STD_DEV ((EDCS_Attribute_Code)797)

/*
 * Definition:
 *     The type of acoustic actuation of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEACACT_AUDIO_FREQUENCY
 *    EEC_MINEACACT_HIGH_FREQUENCY
 *    EEC_MINEACACT_LOW_FREQUENCY
 *    EEC_MINEACACT_MULTIPLE_FREQUENCY
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MILITARY_SCIENCE
 */
#define EAC_MINE_ACOUSTIC_ACTUATION ((EDCS_Attribute_Code)798)

/*
 * Definition:
 *     The type of actuation of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEACT_CONTROLLED
 *    EEC_MINEACT_INDEPENDENT
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_ACTUATION ((EDCS_Attribute_Code)799)

/*
 * Definition:
 *     The <<MILITARY_FORCE_ALLEGIANCE>> of the force responsible for the
 *     creation or maintenance of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEALEGN_FRIEND
 *    EEC_MINEALEGN_HOSTILE
 *    EEC_MINEALEGN_NEUTRAL
 *    EEC_MINEALEGN_ALTERNATE_1
 *    EEC_MINEALEGN_ALTERNATE_2
 *    EEC_MINEALEGN_ALTERNATE_3
 *    EEC_MINEALEGN_ALTERNATE_4
 *    EEC_MINEALEGN_ALTERNATE_5
 *    EEC_MINEALEGN_ALTERNATE_6
 *    EEC_MINEALEGN_ALTERNATE_7
 *    EEC_MINEALEGN_ALTERNATE_8
 *    EEC_MINEALEGN_ALTERNATE_9
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_ALLEGIANCE ((EDCS_Attribute_Code)800)

/*
 * Definition:
 *     The type of anti-hunting capability of an <EXPLOSIVE_NAVAL_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEAHTY_ACOUSTIC_IMPEDANCE
 *    EEC_MINEAHTY_ACOUSTIC_TRANSPARENCY
 *    EEC_MINEAHTY_ANECHOIC_COATING
 *    EEC_MINEAHTY_AUTOMATIC_MINE_BURIAL
 *    EEC_MINEAHTY_IRREGULAR_SHAPING
 *    EEC_MINEAHTY_NON_METALLIC_CASE
 *    EEC_MINEAHTY_SONAR_DECOYS
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, MILITARY_SCIENCE
 */
#define EAC_MINE_ANTI_HUNTING_TYPE ((EDCS_Attribute_Code)801)

/*
 * Definition:
 *     The type of anti-recovery capability of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEARTY_MOORING_LEVEL_SWITCH
 *    EEC_MINEARTY_STRIPPING_EQUIPMENT
 *    EEC_MINEARTY_SWITCH
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, MILITARY_SCIENCE
 */
#define EAC_MINE_ANTI_RECOVERY_TYPE ((EDCS_Attribute_Code)802)

/*
 * Definition:
 *     The type of anti-sweep <WIRE> capability of an <EXPLOSIVE_NAVAL_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEASWTY_CHAIN_MOORING
 *    EEC_MINEASWTY_CUTTER
 *    EEC_MINEASWTY_GRAPNEL
 *    EEC_MINEASWTY_SENSITIVE_TUBING
 *    EEC_MINEASWTY_SPROCKET
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, MILITARY_SCIENCE
 */
#define EAC_MINE_ANTI_SWEEP_WIRE_TYPE ((EDCS_Attribute_Code)803)

/*
 * Definition:
 *     The type of cableless control method of an <EXPLOSIVE_NAVAL_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINECABLSACT_ALTERNATING_CURRENT
 *    EEC_MINECABLSACT_EXPLICIT
 *    EEC_MINECABLSACT_FREQUENCY
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, MILITARY_SCIENCE
 */
#define EAC_MINE_CABLELESS_ACTUATION ((EDCS_Attribute_Code)804)

/*
 * Definition:
 *     The type of capability of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINECPBLTY_ACTIVE
 *    EEC_MINECPBLTY_BOUQUET
 *    EEC_MINECPBLTY_CREEPING
 *    EEC_MINECPBLTY_DRIFTING
 *    EEC_MINECPBLTY_HOMING
 *    EEC_MINECPBLTY_MOBILE
 *    EEC_MINECPBLTY_OSCILLATING
 *    EEC_MINECPBLTY_RISING
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, MILITARY_SCIENCE
 */
#define EAC_MINE_CAPABILITY_TYPE ((EDCS_Attribute_Code)805)

/*
 * Definition:
 *     The <<MASS>> of an <EXPLOSIVE_MINE> charge; the mine charge size.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_CHARGE_SIZE ((EDCS_Attribute_Code)806)

/*
 * Definition:
 *     The type of independent contact actuation of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINECONACT_CONTACT
 *    EEC_MINECONACT_ROD
 *    EEC_MINECONACT_SNAGLINE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_CONTACT_ACTUATION ((EDCS_Attribute_Code)807)

/*
 * Definition:
 *     The type of actuation control method of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINECTRLMETH_CABLE
 *    EEC_MINECTRLMETH_CABLELESS
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_CONTROL_METHOD ((EDCS_Attribute_Code)808)

/*
 * Definition:
 *     The number of <EXPLOSIVE_MINE>s within a <MINEFIELD>; the mine count.
 *
 * Value Type: COUNT
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_COUNT ((EDCS_Attribute_Code)809)

/*
 * Definition:
 *     The type of a <WATER_SURFACE_VESSEL> designed for countermeasure or
 *     laying operations for <EXPLOSIVE_NAVAL_MINE>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINECNMVESTY_HUNT_CLASS_PATROL_CRAFT
 *    EEC_MINECNMVESTY_SANDOWN_CLASS_MINEHUNTER
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define EAC_MINE_COUNTERMEASURE_VESSEL_TYPE ((EDCS_Attribute_Code)810)

/*
 * Definition:
 *     The type of independent actuation of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEINDEPACT_CONTACT
 *    EEC_MINEINDEPACT_INFLUENCE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_INDEPENDENT_ACTUATION ((EDCS_Attribute_Code)811)

/*
 * Definition:
 *     The type of actuation influences of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEINFLACT_ACOUSTIC
 *    EEC_MINEINFLACT_COMBINED
 *    EEC_MINEINFLACT_MAGNETIC
 *    EEC_MINEINFLACT_PRESSURE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_INFLUENCE_ACTUATION ((EDCS_Attribute_Code)812)

/*
 * Definition:
 *     The special information characteristic type of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEINFTY_DEVICE
 *    EEC_MINEINFTY_SUBTYPE
 *    EEC_MINEINFTY_USE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_INFORMATION_TYPE ((EDCS_Attribute_Code)813)

/*
 * Definition:
 *     The sensitivity of a magnetic activation <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEMAGSENS_COARSE
 *    EEC_MINEMAGSENS_MIDSENSITIVE
 *    EEC_MINEMAGSENS_SENSITIVE
 *
 * Group Membership: EM_PHENOMENON, MILITARY_SCIENCE
 */
#define EAC_MINE_MAGNETIC_SENSITIVITY ((EDCS_Attribute_Code)814)

/*
 * Definition:
 *     The position type of a moored <EXPLOSIVE_NAVAL_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEMOORPOS_DEEP_MOORED
 *    EEC_MINEMOORPOS_SHORT_TETHERED
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, LOCATION, MILITARY_SCIENCE
 */
#define EAC_MINE_MOORED_POSITION_TYPE ((EDCS_Attribute_Code)815)

/*
 * Definition:
 *     The military operational use of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEOPUSE_ANTISURFACE_EFFECT_VEHICLE
 *    EEC_MINEOPUSE_CONTINENTAL_SHELF
 *    EEC_MINEOPUSE_DEEP_WATER
 *    EEC_MINEOPUSE_GENERAL_PURPOSE_GROUND
 *    EEC_MINEOPUSE_MARINE_ANTIINVASION
 *    EEC_MINEOPUSE_MEDIUM_DEPTH_ANTISUBMARINE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_OPERATIONAL_USE ((EDCS_Attribute_Code)816)

/*
 * Definition:
 *     The type of actuation, independent of other actuation methods, of an
 *     <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEOTHACTUSE_COSMIC_RAY
 *    EEC_MINEOTHACTUSE_ELECTRIC_FIELD
 *    EEC_MINEOTHACTUSE_INFRARED
 *    EEC_MINEOTHACTUSE_LASER_SENSOR
 *    EEC_MINEOTHACTUSE_REDISTRIBUTION
 *    EEC_MINEOTHACTUSE_SEISMIC
 *    EEC_MINEOTHACTUSE_VELOCITY_FIELD
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_OTHER_ACTUATION_TYPE ((EDCS_Attribute_Code)817)

/*
 * Definition:
 *     The subsidiary information for an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEOTHINFTY_IDENTITY
 *    EEC_MINEOTHINFTY_LOCATION
 *    EEC_MINEOTHINFTY_SPECIAL_INFORMATION
 *    EEC_MINEOTHINFTY_STATUS
 *    EEC_MINEOTHINFTY_TYPE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_OTHER_INFORMATION_TYPE ((EDCS_Attribute_Code)818)

/*
 * Definition:
 *     The type of position of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINEPOSTY_GROUND
 *    EEC_MINEPOSTY_MOORED
 *
 * Group Membership: LOCATION, MILITARY_SCIENCE
 */
#define EAC_MINE_POSITION_TYPE ((EDCS_Attribute_Code)819)

/*
 * Definition:
 *     The type of special capabilities of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINESPCLCPBLTY_ANTICOUNTERMINING
 *    EEC_MINESPCLCPBLTY_ANTIHUNTING
 *    EEC_MINESPCLCPBLTY_ANTILIFT
 *    EEC_MINESPCLCPBLTY_ANTIRECOVERY
 *    EEC_MINESPCLCPBLTY_ANTISWEEP_WIRE
 *    EEC_MINESPCLCPBLTY_ANTIWATCHING
 *    EEC_MINESPCLCPBLTY_ARMING_DELAY
 *    EEC_MINESPCLCPBLTY_DELAYED_RISING
 *    EEC_MINESPCLCPBLTY_FLOODER
 *    EEC_MINESPCLCPBLTY_INFLUENCE_RELEASE_SINKER
 *    EEC_MINESPCLCPBLTY_INTERMITTENT_ARMING
 *    EEC_MINESPCLCPBLTY_OBSTRUCTOR
 *    EEC_MINESPCLCPBLTY_STERILIZER
 *    EEC_MINESPCLCPBLTY_VESSEL_COUNT
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_SPECIAL_CAPABILITY_TYPE ((EDCS_Attribute_Code)820)

/*
 * Definition:
 *     The status of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINESTAT_AFLOAT
 *    EEC_MINESTAT_COUNTERMINED
 *    EEC_MINESTAT_DISPOSED
 *    EEC_MINESTAT_EXPLODED
 *    EEC_MINESTAT_FOULED
 *    EEC_MINESTAT_NEUTRALIZED
 *    EEC_MINESTAT_RECOVERED
 *    EEC_MINESTAT_REMOVED
 *    EEC_MINESTAT_RENDERED_SAFE
 *    EEC_MINESTAT_SUNK
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_STATUS ((EDCS_Attribute_Code)821)

/*
 * Definition:
 *     An indication that a <WATERBODY_REGION> has been swept for
 *     <EXPLOSIVE_MINE>s.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, HYDROGRAPHIC_TRNSP
 */
#define EAC_MINE_SWEPT ((EDCS_Attribute_Code)822)

/*
 * Definition:
 *     The military tactical use of an <EXPLOSIVE_MINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MINETACTUSE_ANTIHOVERCRAFT
 *    EEC_MINETACTUSE_ANTIHUNTER
 *    EEC_MINETACTUSE_ANTISWEEPER
 *    EEC_MINETACTUSE_DISPOSAL_CHARGE
 *    EEC_MINETACTUSE_DRILL
 *    EEC_MINETACTUSE_EXERCISE
 *    EEC_MINETACTUSE_EXERCISE_FILLED
 *    EEC_MINETACTUSE_EXPLOSIVE_FILLED
 *    EEC_MINETACTUSE_PRACTICE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINE_TACTICAL_USE ((EDCS_Attribute_Code)823)

/*
 * Definition:
 *     The numeric identifier of an <EXPLOSIVE_NAVAL_MINE> track.
 *
 * Value Type: INDEX
 *
 * Group Membership: IDENTIFICATION, MILITARY_SCIENCE
 */
#define EAC_MINE_TRACK_IDENTIFIER ((EDCS_Attribute_Code)824)

/*
 * Definition:
 *     The delivery method by which a <MINEFIELD> is created.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MNFLDDLVMETH_AERIAL_AND_ARTILLERY_DELIVERED
 *    EEC_MNFLDDLVMETH_CUSTOMIZED
 *    EEC_MNFLDDLVMETH_HAND_EMPLACED
 *    EEC_MNFLDDLVMETH_MECHANICAL
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINEFIELD_DELIVERY_METHOD ((EDCS_Attribute_Code)825)

/*
 * Definition:
 *     The type of a <MINEFIELD> based on its functional purpose.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MNFLDTY_DELIBERATE_PROTECTIVE_CONVENTIONAL
 *    EEC_MNFLDTY_HASTY_PROTECTIVE_CONVENTIONAL
 *    EEC_MNFLDTY_HASTY_PROTECTIVE_SCATTERED
 *    EEC_MNFLDTY_INTERDICTION
 *    EEC_MNFLDTY_PHONY
 *    EEC_MNFLDTY_POINT
 *    EEC_MNFLDTY_TACTICAL
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MINEFIELD_TYPE ((EDCS_Attribute_Code)826)

/*
 * Definition:
 *     The lowest <<AIR_TEMPERATURE>> attained during a <<TIME_QUANTITY>>;
 *     the minimum air temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MINIMUM_AIR_TEMPERATURE ((EDCS_Attribute_Code)827)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> for which a <<MINIMUM_AIR_TEMPERATURE>> was
 *     recorded.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: ATMOSPHERE, TIME
 */
#define EAC_MINIMUM_AIR_TEMPERATURE_PERIOD ((EDCS_Attribute_Code)828)

/*
 * Definition:
 *     The minimum depth within a <WATERBODY_FLOOR_REGION> defined by a
 *     <DEPTH_CONTOUR_LINE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_MINIMUM_CONTOUR_DEPTH ((EDCS_Attribute_Code)829)

/*
 * Definition:
 *     The minimum <<WATER_CURRENT_SPEED>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_MINIMUM_CURRENT_SPEED ((EDCS_Attribute_Code)830)

/*
 * Definition:
 *     The minimum <<DEW_POINT_TEMPERATURE>> from a series of samples.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_MINIMUM_DEW_POINT_TEMPERATURE ((EDCS_Attribute_Code)831)

/*
 * Definition:
 *     The lowest altitude between radio fixes that assures acceptable
 *     navigational signal coverage and meets obstacle clearance
 *     requirements; the minimum enroute altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, COMMUNICATION, LOCATION, TRNSP
 */
#define EAC_MINIMUM_ENROUTE_ALTITUDE ((EDCS_Attribute_Code)832)

/*
 * Definition:
 *     The lowest <FLIGHT_LEVEL> assigned by air traffic control; the minimum
 *     flight level. The values are expressed as flight level values by
 *     first dividing by 30,48 metres (100 feet) and then rounding to
 *     nearest 304,8 metres (1 000 feet) in accordance with the structure of
 *     the ICAO Standard Atmosphere. EXAMPLE The value for the 500
 *     hectopascals level is 180,0, corresponding to the ICAO standard
 *     height 5 574 metres (18 289 feet).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_MINIMUM_FLIGHT_LEVEL ((EDCS_Attribute_Code)833)

/*
 * Definition:
 *     The minimum draft (depth) of <ICE_KEEL>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, ICE, WATERBODY_SURFACE
 */
#define EAC_MINIMUM_ICE_KEEL_DRAFT ((EDCS_Attribute_Code)834)

/*
 * Definition:
 *     The minimum of <<OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_MINIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL ((EDCS_Attribute_Code)835)

/*
 * Definition:
 *     The minimum safe <<ALTITUDE_MSL>> that provides a 304,8 metre (1 000
 *     foot) obstacle clearance within an <AIRSPACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define EAC_MINIMUM_SAFE_ALTITUDE ((EDCS_Attribute_Code)836)

/*
 * Definition:
 *     The minimum of <<TERRAIN_ELEVATION>>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY
 */
#define EAC_MINIMUM_TERRAIN_ELEVATION ((EDCS_Attribute_Code)837)

/*
 * Definition:
 *     The ordinal index of a minute within the day, starting with the number
 *     "0" at midnight.
 *
 * Value Type: COUNT
 *
 * Group Membership: TIME
 */
#define EAC_MINUTE_WITHIN_DAY ((EDCS_Attribute_Code)838)

/*
 * Definition:
 *     The ordinal index of a minute within the hour. The index starts with
 *     the number "0" at the beginning of the hour.
 *
 * Value Type: COUNT
 *
 * Group Membership: TIME
 */
#define EAC_MINUTE_WITHIN_HOUR ((EDCS_Attribute_Code)839)

/*
 * Definition:
 *     The type of a <MISSILE_SITE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MSSLSITETY_ANTIBALLISTIC
 *    EEC_MSSLSITETY_INTERCONTINENTAL_BALLISTIC
 *    EEC_MSSLSITETY_INTERMEDIATE_RANGE_BALLISTIC
 *    EEC_MSSLSITETY_MEDIUM_RANGE_BALLISTIC
 *    EEC_MSSLSITETY_SA1
 *    EEC_MSSLSITETY_SA2
 *    EEC_MSSLSITETY_SA3
 *    EEC_MSSLSITETY_SA4
 *    EEC_MSSLSITETY_SA5
 *    EEC_MSSLSITETY_SA6
 *    EEC_MSSLSITETY_SA7
 *    EEC_MSSLSITETY_SA8
 *    EEC_MSSLSITETY_SA9
 *    EEC_MSSLSITETY_SURFACE_TO_AIR
 *    EEC_MSSLSITETY_SURFACE_TO_SURFACE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MISSILE_SITE_TYPE ((EDCS_Attribute_Code)840)

/*
 * Definition:
 *     The type of missing information.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MISSINFTY_TERRAIN_RELIEF
 *
 * Group Membership: SURVEY
 */
#define EAC_MISSING_INFORMATION_TYPE ((EDCS_Attribute_Code)841)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the extent of physical injury/damage to an <OBJECT> (for
 *     example: a critical sensor/emitter <AERIAL> and/or subsystem)
 *     specific to the mission. Zero means no damage at all and one means
 *     maximum damage.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, MILITARY_SCIENCE, RATE_OR_RATIO
 */
#define EAC_MISSION_SPECIFIC_DAMAGE_FRACTION ((EDCS_Attribute_Code)842)

/*
 * Definition:
 *     The depth of the top of a surface mixing layer measured from a
 *     <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_STATE
 */
#define EAC_MIXING_LAYER_DEPTH ((EDCS_Attribute_Code)843)

/*
 * Definition:
 *     The standard deviation of <<MIXING_LAYER_DEPTH>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_STATE
 */
#define EAC_MIXING_LAYER_DEPTH_STD_DEV ((EDCS_Attribute_Code)844)

/*
 * Definition:
 *     The gradient of <<TEMPERATURE>> across a surface mixing layer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 *
 * Group Membership: TEMPERATURE
 */
#define EAC_MIXING_LAYER_TEMP_GRAD ((EDCS_Attribute_Code)845)

/*
 * Definition:
 *     The standard deviation of <<MIXING_LAYER_TEMP_GRAD>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 *
 * Group Membership: TEMPERATURE
 */
#define EAC_MIXING_LAYER_TEMP_GRAD_STD_DEV ((EDCS_Attribute_Code)846)

/*
 * Definition:
 *     In a <SYSTEM> of moist <AIR>, the ratio of the <<MASS>> of <WATER>
 *     vapour to the <<MASS>> of dry <AIR>; the mixing ratio.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_MIXING_RATIO ((EDCS_Attribute_Code)847)

/*
 * Definition:
 *     A dimensionless number that provides a relative measure of the
 *     severity of the conditions likely to be encountered in the
 *     <SURF_ZONE>; the modified surf index.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define EAC_MODIFIED_SURF_INDEX ((EDCS_Attribute_Code)848)

/*
 * Definition:
 *     The ratio of the tensile stress to tensile strain for a <MATERIAL>;
 *     the modulus of elasticity or Young's modulus.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_MODULUS_OF_ELASTICITY ((EDCS_Attribute_Code)849)

/*
 * Definition:
 *     An indication that an <OBJECT> is actively monitored.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_MONITORED ((EDCS_Attribute_Code)850)

/*
 * Definition:
 *     The month of the year in the Gregorian calendar.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MONTH_JANUARY
 *    EEC_MONTH_FEBRUARY
 *    EEC_MONTH_MARCH
 *    EEC_MONTH_APRIL
 *    EEC_MONTH_MAY
 *    EEC_MONTH_JUNE
 *    EEC_MONTH_JULY
 *    EEC_MONTH_AUGUST
 *    EEC_MONTH_SEPTEMBER
 *    EEC_MONTH_OCTOBER
 *    EEC_MONTH_NOVEMBER
 *    EEC_MONTH_DECEMBER
 *
 * Group Membership: TIME
 */
#define EAC_MONTH ((EDCS_Attribute_Code)851)

/*
 * Definition:
 *     The phase of the <MOON>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MOONPHAS_NEW_MOON
 *    EEC_MOONPHAS_WAXING_CRESCENT
 *    EEC_MOONPHAS_FIRST_QUARTER
 *    EEC_MOONPHAS_WAXING_GIBBOUS
 *    EEC_MOONPHAS_FULL_MOON
 *    EEC_MOONPHAS_WANING_GIBBOUS
 *    EEC_MOONPHAS_LAST_QUARTER
 *    EEC_MOONPHAS_WANING_CRESCENT
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_MOON_PHASE ((EDCS_Attribute_Code)852)

/*
 * Definition:
 *     The number of complete phases of the <MOON> since 00:00:00 UTC, 1
 *     January 1970; the moon phase count.
 *
 * Value Type: COUNT
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_MOON_PHASE_COUNT ((EDCS_Attribute_Code)853)

/*
 * Definition:
 *     The time at which a <<MOON_PHASE>> occurs since 00:00:00 UTC, 1
 *     January 1970.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, SPACE, TIME
 */
#define EAC_MOON_PHASE_TIME ((EDCS_Attribute_Code)854)

/*
 * Definition:
 *     The <<TIME_OF_DAY>> of moonrise. The time is defined to occur when the
 *     geometric zenith distance of the centre of the <MOON> is 90,5666 arc
 *     degrees plus the apparent angular <<RADIUS>> of the <MOON> minus the
 *     apparent angular horizontal parallax of the <MOON>; that is, under
 *     normal atmospheric conditions at MSL, the upper limb of the <MOON>
 *     will then appear to be tangent with a level, unobstructed eastern
 *     horizon. No account is taken of the <<MOON_PHASE>>; that is, the
 *     <MOON> is always regarded as a disk in the sky and the upper limb
 *     might be dark. The 34 arc minute geometric depression of the centre
 *     of the <MOON> used for the computations is used to account for
 *     atmospheric refraction. The apparent angular <<RADIUS>> of the <MOON>
 *     varies from 15 to 17 arc minutes and its apparent angular horizontal
 *     parallax varies from 54 to 61 arc minutes.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, SPACE, TIME
 */
#define EAC_MOONRISE_TIME ((EDCS_Attribute_Code)855)

/*
 * Definition:
 *     The <<TIME_OF_DAY>> of moonset. The time is defined to occur when the
 *     geometric zenith distance of the centre of the <MOON> is 90,5666 arc
 *     degrees plus the apparent angular <<RADIUS>> of the <MOON> minus the
 *     apparent angular horizontal parallax of the <MOON>; that is, under
 *     normal atmospheric conditions at MSL, the upper limb of the <MOON>
 *     will then appear to be tangent with a level, unobstructed western
 *     horizon. No account is taken of the <<MOON_PHASE>>; that is, the
 *     <MOON> is always regarded as a disk in the sky and the upper limb
 *     might be dark. The 34 arc minute geometric depression of the centre
 *     of the <MOON> used for the computations is used to account for
 *     atmospheric refraction. The apparent angular <<RADIUS>> of the <MOON>
 *     varies from 15 to 17 arc minutes and its apparent angular horizontal
 *     parallax varies from 54 to 61 arc minutes.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, SPACE, TIME
 */
#define EAC_MOONSET_TIME ((EDCS_Attribute_Code)856)

/*
 * Definition:
 *     The type of connection used in a mooring <SYSTEM>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MOORCONNTY_FLEXIBLE_RESTRAINT
 *    EEC_MOORCONNTY_MOORING_BUOY
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_MOORING_CONNECTION_TYPE ((EDCS_Attribute_Code)857)

/*
 * Definition:
 *     The type of a <MOORING_FACILITY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MOORFACTY_BOLLARD
 *    EEC_MOORFACTY_DEVIATION_DOLPHIN
 *    EEC_MOORFACTY_DOLPHIN
 *    EEC_MOORFACTY_NONE_PRESENT
 *    EEC_MOORFACTY_STRUCTURAL_PILE
 *    EEC_MOORFACTY_TIE_UP_WALL
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_MOORING_FACILITY_TYPE ((EDCS_Attribute_Code)858)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the production rate of contrails, vapour trails, or other
 *     ionization phenomena that is induced by movement of a <VEHICLE>
 *     through the <ATMOSPHERE>. Zero means no contrail at all and one means
 *     maximum production.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO, TRNSP
 */
#define EAC_MOVEMENT_INDUCED_CONTRAIL_PRODUCTION_RATE ((EDCS_Attribute_Code)859)

/*
 * Definition:
 *     The qualitative degree to which <TERRAIN> or a
 *     <LAND_TRANSPORTATION_ROUTE> has been degraded by the passage of
 *     <GROUND_VEHICLE>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MLTPSSRFDGRD_NONE_PRESENT
 *    EEC_MLTPSSRFDGRD_MODERATE
 *    EEC_MLTPSSRFDGRD_HEAVY
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_MULTIPASS_SURFACE_DEGRADATION ((EDCS_Attribute_Code)860)

/*
 * Definition:
 *     An indication that an <OBJECT> represents more than one instance of
 *     that type of <OBJECT> type; multiple.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_MULTIPLE ((EDCS_Attribute_Code)861)

/*
 * Definition:
 *     An indication that multiple obstruction <LIGHT>s are associated with
 *     an <OBJECT>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, LIGHTING_AND_VISIBILITY
 */
#define EAC_MULTIPLE_OBSTRUCTION_LIGHTS ((EDCS_Attribute_Code)862)

/*
 * Definition:
 *     The number of detonations of <MUNITION>s within a delineated <REGION>;
 *     the munition burst count.
 *
 * Value Type: COUNT
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MUNITION_BURST_COUNT ((EDCS_Attribute_Code)863)

/*
 * Definition:
 *     The type of fuse used in a <MUNITION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MUNFUSETY_INFRARED
 *    EEC_MUNFUSETY_MAGNETIC
 *    EEC_MUNFUSETY_PRESSURE
 *    EEC_MUNFUSETY_SEISMIC
 *    EEC_MUNFUSETY_TILT_ROD
 *    EEC_MUNFUSETY_TRIP_WIRE
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_MUNITION_FUSE_TYPE ((EDCS_Attribute_Code)864)

/*
 * Definition:
 *     The level of protection against <MUNITION>s that a <STRUCTURE>
 *     provides for its contents.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MUNPROTLEV_NO_PROTECTION
 *    EEC_MUNPROTLEV_SOFT
 *    EEC_MUNPROTLEV_SEMI_HARDENED
 *    EEC_MUNPROTLEV_HARDENED
 *
 * Group Membership: MILITARY_SCIENCE, SHELTER, SUPPORT_STRUCTURE
 */
#define EAC_MUNITION_PROTECTION_LEVEL ((EDCS_Attribute_Code)865)

/*
 * Definition:
 *     A textual identifier or code used to denote an <OBJECT>; the name.
 *
 * Value Type: STRING
 *
 * Group Membership: ABSTRACT_OBJECT, IDENTIFICATION
 */
#define EAC_NAME ((EDCS_Attribute_Code)866)

/*
 * Definition:
 *     The national paint scheme applied to an <OBJECT>. The values are
 *     specified by a <<NATIONAL_PAINT_SCHEME_VALUE_SET>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ABSTRACT_OBJECT, COLOUR
 */
#define EAC_NATIONAL_PAINT_SCHEME ((EDCS_Attribute_Code)867)

/*
 * Definition:
 *     The value set of a formatted <<NATIONAL_PAINT_SCHEME>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NATLPNTVALSET_UNCONSTRAINED
 *    EEC_NATLPNTVALSET_HISTORICAL
 *    EEC_NATLPNTVALSET_ISO_ENGLISH_CTRY_NAME
 *
 * Group Membership: COLOUR
 */
#define EAC_NATIONAL_PAINT_SCHEME_VALUE_SET ((EDCS_Attribute_Code)868)

/*
 * Definition:
 *     The type of distribution of native <DWELLING>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NATSETTLTY_CENTRALIZED
 *    EEC_NATSETTLTY_CONTINUOUS
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define EAC_NATIVE_SETTLEMENT_TYPE ((EDCS_Attribute_Code)869)

/*
 * Definition:
 *     The type of a <MARINE_GATE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NAUTGATETY_CAISSON
 *    EEC_NAUTGATETY_DYKE
 *    EEC_NAUTGATETY_FLOOD_BARRAGE
 *    EEC_NAUTGATETY_GENERAL
 *    EEC_NAUTGATETY_LOCK
 *    EEC_NAUTGATETY_SLUICE
 *    EEC_NAUTGATETY_TIDAL
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_NAUTICAL_GATE_TYPE ((EDCS_Attribute_Code)870)

/*
 * Definition:
 *     The type of navigability of a <WATERBODY_SURFACE_REGION> by large
 *     <VESSEL>s (for example: ocean going); navigable status.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NAVSTAT_NAVIGABLE
 *    EEC_NAVSTAT_NAVIGABLE_ABANDONED
 *    EEC_NAVSTAT_NAVIGABLE_OPERATIONAL
 *    EEC_NAVSTAT_NAVIGABLE_PERIODIC_RESTRICTION
 *    EEC_NAVSTAT_NOT_NAVIGABLE
 *
 * Group Membership: HYDROGRAPHIC_TRNSP
 */
#define EAC_NAVIGABLE_STATUS ((EDCS_Attribute_Code)871)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of external <LIGHTING> that is used to
 *     illuminate the environment in the <DIRECTION> of travel of a
 *     <VEHICLE>; the navigation or head light intensity. Zero means minimum
 *     intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_NAVIGATION_LIGHT_INTENSITY ((EDCS_Attribute_Code)872)

/*
 * Definition:
 *     The type of <LINE> defining a marine navigation path.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NAVPATHTY_GEODESIC
 *    EEC_NAVPATHTY_LOXODROME
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_NAVIGATION_PATH_TYPE ((EDCS_Attribute_Code)873)

/*
 * Definition:
 *     The type of technology used in electronic navigation. The value is
 *     either a type of <EQUIPMENT> or the name of a <SYSTEM>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NAVSYSTY_AERO_RADIO
 *    EEC_NAVSYSTY_AERO_RADIO_RANGE
 *    EEC_NAVSYSTY_AERODROME_SURV_RADAR
 *    EEC_NAVSYSTY_AIR_ROUTE_SURV_RADAR
 *    EEC_NAVSYSTY_BONE_MARKER
 *    EEC_NAVSYSTY_CHAIKA
 *    EEC_NAVSYSTY_CIRCULAR_RADIO_BEACON
 *    EEC_NAVSYSTY_CONSOL_BEACON
 *    EEC_NAVSYSTY_DECCA
 *    EEC_NAVSYSTY_DIFFERENTIAL_GPS
 *    EEC_NAVSYSTY_DIRECTIONAL_RADIO_BEACON
 *    EEC_NAVSYSTY_DISTANCE_FINDING
 *    EEC_NAVSYSTY_DME
 *    EEC_NAVSYSTY_FAN_MARKER_BEACON
 *    EEC_NAVSYSTY_GCA
 *    EEC_NAVSYSTY_GCI
 *    EEC_NAVSYSTY_GLIDE_SLOPE
 *    EEC_NAVSYSTY_GPS
 *    EEC_NAVSYSTY_HIFIX
 *    EEC_NAVSYSTY_HYPERFIX
 *    EEC_NAVSYSTY_ILS
 *    EEC_NAVSYSTY_ILS_OR_DME
 *    EEC_NAVSYSTY_LOCALIZER
 *    EEC_NAVSYSTY_LOCALIZER_DIRECTION_AID
 *    EEC_NAVSYSTY_LOCALIZER_WITH_DME
 *    EEC_NAVSYSTY_LOCATOR_WITHOUT_DME_INNER_MARKER
 *    EEC_NAVSYSTY_LORAN_C
 *    EEC_NAVSYSTY_MICROWAVE
 *    EEC_NAVSYSTY_MLS
 *    EEC_NAVSYSTY_MLS_AZIMUTH_GUIDE
 *    EEC_NAVSYSTY_MLS_ELEVATION_GUIDE
 *    EEC_NAVSYSTY_NDB
 *    EEC_NAVSYSTY_NDB_OR_DME
 *    EEC_NAVSYSTY_NONE_PRESENT
 *    EEC_NAVSYSTY_OMEGA
 *    EEC_NAVSYSTY_PAR
 *    EEC_NAVSYSTY_PAR_TOUCHDOWN_REFLECTOR
 *    EEC_NAVSYSTY_PRECISION_APPROACH_PATH_INDICATOR
 *    EEC_NAVSYSTY_QTG_STATION
 *    EEC_NAVSYSTY_RACON
 *    EEC_NAVSYSTY_RADAR
 *    EEC_NAVSYSTY_RADAR_AERIAL
 *    EEC_NAVSYSTY_RADAR_REFLECTOR
 *    EEC_NAVSYSTY_RADAR_STATION
 *    EEC_NAVSYSTY_RADIO
 *    EEC_NAVSYSTY_RADIO_BEACON
 *    EEC_NAVSYSTY_RADIO_BEACON_TYPE_UNKNOWN
 *    EEC_NAVSYSTY_RADIO_RANGE
 *    EEC_NAVSYSTY_RADIO_STATION
 *    EEC_NAVSYSTY_RADIO_TELEGRAPH
 *    EEC_NAVSYSTY_RADIO_TELEPHONE
 *    EEC_NAVSYSTY_RAMARK
 *    EEC_NAVSYSTY_RADIO_DIRECTION_FINDING
 *    EEC_NAVSYSTY_ROTATING_LOOP_RADIO_BEACON
 *    EEC_NAVSYSTY_SIMPLIFIED_DIRECTIONAL
 *    EEC_NAVSYSTY_SYLEDIS
 *    EEC_NAVSYSTY_TACTICAL_AIR
 *    EEC_NAVSYSTY_TELEVISION
 *    EEC_NAVSYSTY_TORAN
 *    EEC_NAVSYSTY_TRICOLOUR_PANEL
 *    EEC_NAVSYSTY_TRICOLOUR_VASI
 *    EEC_NAVSYSTY_TVASI
 *    EEC_NAVSYSTY_VASI
 *    EEC_NAVSYSTY_VASI_PULSATING
 *    EEC_NAVSYSTY_VFR_TEST_SIGNAL_MAKER
 *    EEC_NAVSYSTY_VOR
 *    EEC_NAVSYSTY_VOR_AND_DME
 *    EEC_NAVSYSTY_VOR_TACAN
 *    EEC_NAVSYSTY_VORTAC
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_NAVIGATION_SYSTEM_TYPE ((EDCS_Attribute_Code)874)

/*
 * Definition:
 *     The maximum distance at which a <LIGHT> can be seen in clear weather
 *     as defined by the International Visibility Code; the nominal light
 *     range.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIGHTING_AND_VISIBILITY
 */
#define EAC_NOMINAL_LIGHT_RANGE ((EDCS_Attribute_Code)875)

/*
 * Definition:
 *     The class of a non-regulatory <AIRSPACE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NONREGARSPCCLS_SPECIAL_USE
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_NON_REGULATORY_AIRSPACE_CLASS ((EDCS_Attribute_Code)876)

/*
 * Definition:
 *     The date of reporting of a <NON_SUBMARINE_CONTACT>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROGRAPHIC_TRNSP, TIME, TRNSP, WATERBODY_FLOOR
 */
#define EAC_NON_SUB_CONTACT_DATE ((EDCS_Attribute_Code)877)

/*
 * Definition:
 *     The accuracy of the <LOCATION> of a <NON_SUBMARINE_CONTACT>. When the
 *     accuracy is uncertain, the value 10 000 kilometres is used.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROGRAPHIC_TRNSP, LOCATION, TRNSP, WATERBODY_FLOOR
 */
#define EAC_NON_SUB_CONTACT_POSITION_ACCURACY ((EDCS_Attribute_Code)878)

/*
 * Definition:
 *     The source of a reported <NON_SUBMARINE_CONTACT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NSUBSRC_ABSTRACTS_1914_18
 *    EEC_NSUBSRC_AMERICAN_SHIP_CASUALTIES_WW_I
 *    EEC_NSUBSRC_BHO_CHART
 *    EEC_NSUBSRC_BHO_FILES
 *    EEC_NSUBSRC_BHO_NOTICE_TO_MARINERS
 *    EEC_NSUBSRC_BHO_WRECK_INFORMATION
 *    EEC_NSUBSRC_BRITISH_1921_WRECK_CHARTS
 *    EEC_NSUBSRC_BRITISH_1961_WRECK_CHARTS
 *    EEC_NSUBSRC_BRITISH_MERCHANT_VESSELS
 *    EEC_NSUBSRC_BRITISH_SHIPS_LOST_WW_II
 *    EEC_NSUBSRC_COMNAVFE
 *    EEC_NSUBSRC_COMNAVPAC
 *    EEC_NSUBSRC_DANISH_1914_18_SHIP_LOSSES
 *    EEC_NSUBSRC_DUTCH_WRECK_LIST
 *    EEC_NSUBSRC_DANISH_1914_18_WAR_LOSSES
 *    EEC_NSUBSRC_DUTCH_WW_I_MERCHANT_LOSSES
 *    EEC_NSUBSRC_FRENCH_WW_I_NAVAL_LOSSES
 *    EEC_NSUBSRC_GERMAN_WW_II_SUBMARINE_LOSSES
 *    EEC_NSUBSRC_GREEK_WW_II_LOSSES
 *    EEC_NSUBSRC_ITALIAN_WW_I_MERCHANT_LOSSES
 *    EEC_NSUBSRC_ITALIAN_WW_I_NAVAL_LOSSES
 *    EEC_NSUBSRC_ITALIAN_WW_II_NAVAL_LOSSES
 *    EEC_NSUBSRC_ITALIAN_NAVAL_SURVEY_CHARTS
 *    EEC_NSUBSRC_ITALIAN_NAVY_SURVEY
 *    EEC_NSUBSRC_JAPAN_NAVAL_LOST_WW_II
 *    EEC_NSUBSRC_JAPAN_NAVY_IN_WW_II
 *    EEC_NSUBSRC_LLOYDS_UNDERWRITERS
 *    EEC_NSUBSRC_MAD_VERIFIED
 *    EEC_NSUBSRC_MARITIME_COMMISSION
 *    EEC_NSUBSRC_MERCHANT_VESSELS_US_LOST
 *    EEC_NSUBSRC_NAVAL_CHRONOLOGY_WW_II
 *    EEC_NSUBSRC_NAVAL_LOSSES
 *    EEC_NSUBSRC_NORTH_SEA_FISHING_CHARTS
 *    EEC_NSUBSRC_NORWEGIAN_1914_18_LOSSES
 *    EEC_NSUBSRC_OFFICE_OF_NAVAL_INTELLIGENCE
 *    EEC_NSUBSRC_OMAN_NATIONAL_HYDROGRAPHIC_OFFICE
 *    EEC_NSUBSRC_PHOTOGRAPHS_OF_PINNACLES
 *    EEC_NSUBSRC_PORTUGAL_HYDROGRAPHIC_OFFICE
 *    EEC_NSUBSRC_RADIO_NAVIGATION_WARNING
 *    EEC_NSUBSRC_RCN_WRECK_PUB_272
 *    EEC_NSUBSRC_SHIP_VISIT
 *    EEC_NSUBSRC_SHIPPING_CASUALTIES
 *    EEC_NSUBSRC_SHIPS_SUNK_BY_GERMANY
 *    EEC_NSUBSRC_SONAR_VERIFIED
 *    EEC_NSUBSRC_SPANISH_HYDROGRAPHIC_OFFICE
 *    EEC_NSUBSRC_SPANISH_WW_I_MERCHANT_LOSSES
 *    EEC_NSUBSRC_SWEDISH_1914_20_MERCHANT_LOSS
 *    EEC_NSUBSRC_SWEDISH_BOARD_SHIPPING
 *    EEC_NSUBSRC_TENTH_FLEET_RECORDS_OP374
 *    EEC_NSUBSRC_US_COAST_AND_GEODETIC_SURVEY
 *    EEC_NSUBSRC_US_COAST_GUARD_DISTRICTS
 *    EEC_NSUBSRC_US_COAST_GUARD_RECORDS
 *    EEC_NSUBSRC_US_LOSSES_DIRECTOR_FLEET_OPERATIONS
 *    EEC_NSUBSRC_US_NAVY_AT_WAR_1941_45
 *    EEC_NSUBSRC_US_NAVY_SONAR
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_FLOOR
 */
#define EAC_NON_SUB_CONTACT_SOURCE ((EDCS_Attribute_Code)879)

/*
 * Definition:
 *     The type of source of a reported <NON_SUBMARINE_CONTACT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_NSUBSRCTY_ACTION
 *    EEC_NSUBSRCTY_CASUALTY
 *    EEC_NSUBSRCTY_CHART
 *    EEC_NSUBSRCTY_CHART_RECORDS
 *    EEC_NSUBSRCTY_MAGNETIC_ANOMALY_DETECTOR
 *    EEC_NSUBSRCTY_MINESWEEPER
 *    EEC_NSUBSRCTY_NORTH_SEA_FISHING_CHARTS
 *    EEC_NSUBSRCTY_NOTICE_TO_MARINERS
 *    EEC_NSUBSRCTY_PHOTOGRAPH
 *    EEC_NSUBSRCTY_POSITION_ACCURATE_FIELD_CHECK
 *    EEC_NSUBSRCTY_SALVAGE
 *    EEC_NSUBSRCTY_SONAR
 *    EEC_NSUBSRCTY_SURVEY
 *    EEC_NSUBSRCTY_SURVIVOR
 *    EEC_NSUBSRCTY_UK_HYDROGRAPHIC_RECORDS
 *    EEC_NSUBSRCTY_UNSPECIFIED_DETECTOR
 *    EEC_NSUBSRCTY_US_COAST_GUARD_RECORDS
 *    EEC_NSUBSRCTY_US_COAST_SURVEY
 *    EEC_NSUBSRCTY_US_NAVY
 *    EEC_NSUBSRCTY_US_WRECK_LIST
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_FLOOR
 */
#define EAC_NON_SUB_CONTACT_SOURCE_TYPE ((EDCS_Attribute_Code)880)

/*
 * Definition:
 *     The numeric identifier of a <NON_SUBMARINE_CONTACT>.
 *
 * Value Type: INDEX
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROGRAPHIC_TRNSP, IDENTIFICATION, TRNSP, WATERBODY_FLOOR
 */
#define EAC_NON_SUB_CONTACT_WRECK_IDENTIFIER ((EDCS_Attribute_Code)881)

/*
 * Definition:
 *     The null attribute concept; provided for information processing
 *     applications.
 *
 * Value Type: NULL
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define EAC_NULL ((EDCS_Attribute_Code)882)

/*
 * Definition:
 *     A numeric identifier used to reference values in a data structure; an
 *     index.
 *
 * Value Type: INDEX
 *
 * Group Membership: ALGORITHM_RELATED, IDENTIFICATION
 */
#define EAC_NUMERIC_IDENTIFIER ((EDCS_Attribute_Code)883)

/*
 * Definition:
 *     The numeric identifier of an <OBJECT>.
 *
 * Value Type: INDEX
 *
 * Group Membership: ABSTRACT_OBJECT, IDENTIFICATION
 */
#define EAC_NUMERIC_OBJECT_IDENTIFIER ((EDCS_Attribute_Code)884)

/*
 * Definition:
 *     The portion or aspect of an <OBJECT> in relation to the <TERRAIN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBJASP_BODY
 *    EEC_OBJASP_CUT
 *    EEC_OBJASP_CUT_TRANSITION
 *    EEC_OBJASP_EMBANK
 *    EEC_OBJASP_EMBANK_OR_CUT_TRANSITION
 *    EEC_OBJASP_EMBANK_TRANSITION
 *    EEC_OBJASP_LEFT_CUT
 *    EEC_OBJASP_LEFT_CUT_TRANSITION
 *    EEC_OBJASP_LEFT_EMBANK
 *    EEC_OBJASP_LEFT_EMBANK_OR_CUT_TRANSITION
 *    EEC_OBJASP_LEFT_EMBANK_TRANSITION
 *    EEC_OBJASP_LEFT_SHOULDER
 *    EEC_OBJASP_RIGHT_CUT
 *    EEC_OBJASP_RIGHT_CUT_TRANSITION
 *    EEC_OBJASP_RIGHT_EMBANK
 *    EEC_OBJASP_RIGHT_EMBANK_OR_CUT_TRANSITION
 *    EEC_OBJASP_RIGHT_EMBANK_TRANSITION
 *    EEC_OBJASP_RIGHT_SHOULDER
 *    EEC_OBJASP_SHOULDER
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY
 */
#define EAC_OBJECT_ASPECT ((EDCS_Attribute_Code)885)

/*
 * Definition:
 *     The <<HEIGHT_AGL>> of the base (lowest point) of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_OBJECT_BASE_HEIGHT ((EDCS_Attribute_Code)886)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the bearing of an <OBJECT> from an
 *     observer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_OBJECT_BEARING_GEODETIC ((EDCS_Attribute_Code)887)

/*
 * Definition:
 *     The type of configuration of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBJCFG_DISPERSED
 *    EEC_OBJCFG_DIVIDED_DIFFERENT_WIDTHS
 *    EEC_OBJCFG_DIVIDED_SAME_WIDTH
 *    EEC_OBJCFG_DOUBLE
 *    EEC_OBJCFG_INCLINED
 *    EEC_OBJCFG_JUXTAPOSITION
 *    EEC_OBJCFG_NON_DIVIDED
 *    EEC_OBJCFG_SINGLE
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_OBJECT_CONFIGURATION ((EDCS_Attribute_Code)888)

/*
 * Definition:
 *     An indication of whether the <OBJECT> has a recognizable
 *     <<OBJECT_CONFIGURATION>>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_OBJECT_CONFIGURATION_QUALITY ((EDCS_Attribute_Code)889)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the predominant linear pattern of the
 *     elements within an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE, LOCATION
 */
#define EAC_OBJECT_ELEMENT_GEODETIC_ORIENTATION ((EDCS_Attribute_Code)890)

/*
 * Definition:
 *     The base number used within a specific geographic <REGION> to assign
 *     identification numbers to new <OBJECT>s.
 *
 * Value Type: INTEGER
 *
 * Group Membership: IDENTIFICATION, SURVEY
 */
#define EAC_OBJECT_IDENTIFICATION_BASE_NUMBER ((EDCS_Attribute_Code)891)

/*
 * Definition:
 *     The label applied to an <OBJECT>.
 *
 * Value Type: STRING
 *
 * Group Membership: ABSTRACT_OBJECT, IDENTIFICATION
 */
#define EAC_OBJECT_LABEL ((EDCS_Attribute_Code)892)

/*
 * Definition:
 *     The relative importance of an <OBJECT> as an ordinal rank.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBJORDRANK_FIRST
 *    EEC_OBJORDRANK_SECOND
 *    EEC_OBJORDRANK_THIRD
 *    EEC_OBJORDRANK_FOURTH
 *    EEC_OBJORDRANK_FIFTH
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_OBJECT_ORDINAL_RANK ((EDCS_Attribute_Code)893)

/*
 * Definition:
 *     The orientation of the usual axis of an <OBJECT> with respect to the
 *     vertical <DIRECTION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBJORNTWRTVERT_HORIZONTAL
 *    EEC_OBJORNTWRTVERT_INVERTED
 *    EEC_OBJORNTWRTVERT_LEANING
 *    EEC_OBJORNTWRTVERT_ON_SIDE
 *    EEC_OBJORNTWRTVERT_UPRIGHT
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_OBJECT_ORIENTATION_WRT_VERTICAL ((EDCS_Attribute_Code)894)

/*
 * Definition:
 *     The shape of the polygon associated with a <NON_EMPTY_SET> of
 *     <POLYGONAL_FACE>s of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBJPOLYFCSHAP_EQUILATERAL_TRIANGLE
 *    EEC_OBJPOLYFCSHAP_HEXAGON
 *    EEC_OBJPOLYFCSHAP_OCTAGON
 *    EEC_OBJPOLYFCSHAP_PENTAGON
 *    EEC_OBJPOLYFCSHAP_RECTANGLE
 *    EEC_OBJPOLYFCSHAP_RIGHT_ISOSCELES_TRIANGLE
 *    EEC_OBJPOLYFCSHAP_RIGHT_TRIANGLE
 *    EEC_OBJPOLYFCSHAP_SQUARE
 *    EEC_OBJPOLYFCSHAP_TRIANGLE
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define EAC_OBJECT_POLYGONAL_FACE_SHAPE ((EDCS_Attribute_Code)895)

/*
 * Definition:
 *     A rate associated with an <OBJECT>. The value is formatted in a Basic
 *     Latin string. The string contains a number, followed by a unit
 *     enclosed in parenthesis ("( )"), followed by a unit qualifier
 *     enclosed in square brackets ("[ ]"). EXAMPLE "100(cars)[per hour]"
 *     associated with a <BRIDGE> as the rate at which cars cross the
 *     <BRIDGE>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_OBJECT_RATE ((EDCS_Attribute_Code)896)

/*
 * Definition:
 *     The type of an <OBJECT_SET>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBJSETTY_AERONAUTICAL
 *    EEC_OBJSETTY_AERONAUTICAL_OBSTRUCTION
 *    EEC_OBJSETTY_AID_TO_NAVIGATION
 *    EEC_OBJSETTY_AIRSPACE
 *    EEC_OBJSETTY_ATS_ROUTE
 *    EEC_OBJSETTY_BEACH
 *    EEC_OBJSETTY_BOUNDARY
 *    EEC_OBJSETTY_COASTLINE
 *    EEC_OBJSETTY_CULTURAL_LANDMARK
 *    EEC_OBJSETTY_DATA_QUALITY
 *    EEC_OBJSETTY_DATABASE_BOUNDARY
 *    EEC_OBJSETTY_DEMARCATION
 *    EEC_OBJSETTY_ELEVATION
 *    EEC_OBJSETTY_FIXED_UNDERWATER_OBJECT
 *    EEC_OBJSETTY_GROUND_OBSTACLE
 *    EEC_OBJSETTY_HYDRO
 *    EEC_OBJSETTY_HYDRO_AID_TO_NAVIGATION
 *    EEC_OBJSETTY_HYDRO_DANGER
 *    EEC_OBJSETTY_HYDRO_LIMITS
 *    EEC_OBJSETTY_HYPSOGRAPHY
 *    EEC_OBJSETTY_INDUSTRY
 *    EEC_OBJSETTY_INLAND_WATER
 *    EEC_OBJSETTY_LAND_COVER
 *    EEC_OBJSETTY_MARINE_ENVIRONMENT
 *    EEC_OBJSETTY_MARINE_LIMIT
 *    EEC_OBJSETTY_MARINE_NAVIGATION
 *    EEC_OBJSETTY_MARINE_OBSTRUCTION
 *    EEC_OBJSETTY_MARINE_OVERVIEW
 *    EEC_OBJSETTY_MARINE_SHORE
 *    EEC_OBJSETTY_MILITARY_AIRSPACE
 *    EEC_OBJSETTY_MILITARY_STRUCTURE
 *    EEC_OBJSETTY_OCEAN_ENVIRONMENT
 *    EEC_OBJSETTY_OCEAN_FLOOR
 *    EEC_OBJSETTY_OVERVIEW
 *    EEC_OBJSETTY_PHYSIOGRAPHY
 *    EEC_OBJSETTY_PLACE_NAME
 *    EEC_OBJSETTY_PLANETARY_SCIENCE
 *    EEC_OBJSETTY_POLITICAL_ENTITY
 *    EEC_OBJSETTY_POPULATION
 *    EEC_OBJSETTY_PORT_AND_HARBOUR
 *    EEC_OBJSETTY_RAILWAY
 *    EEC_OBJSETTY_ROAD
 *    EEC_OBJSETTY_SHORE_STRUCTURE
 *    EEC_OBJSETTY_TERMINAL_PROCEDURE
 *    EEC_OBJSETTY_TERRAIN_COMPOSITION
 *    EEC_OBJSETTY_TERRAIN_CONFIGURATION
 *    EEC_OBJSETTY_TERRAIN_TRANSPORTATION_ROUTE
 *    EEC_OBJSETTY_TILE_SET
 *    EEC_OBJSETTY_TRACK_SWATH
 *    EEC_OBJSETTY_UNDERWATER_OBJECT
 *    EEC_OBJSETTY_UTILITY
 *    EEC_OBJSETTY_VEGETATION
 *    EEC_OBJSETTY_WATER_BODY_BATHYMETRY
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_OBJECT_SET_TYPE ((EDCS_Attribute_Code)897)

/*
 * Definition:
 *     An indication that an <OBJECT> is shaded from direct sunlight or solar
 *     loading.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, LIGHTING_AND_VISIBILITY
 */
#define EAC_OBJECT_SHADED ((EDCS_Attribute_Code)898)

/*
 * Definition:
 *     The irradiance from the sky (downwelling) onto an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: ABSTRACT_OBJECT, LIGHTING_AND_VISIBILITY
 */
#define EAC_OBJECT_SKY_IRRADIANCE ((EDCS_Attribute_Code)899)

/*
 * Definition:
 *     From a <LOCATION> of maximum visibility through an <OBJECT> (for
 *     example: a <FENCE> and/or a <TREE_LINE>), the ratio of the number of
 *     geometric rays from that <LOCATION> that are within the <REGION>
 *     delineated by an <OBJECT> but do not intersect that <OBJECT> to the
 *     total number of geometric rays from that <LOCATION> that are within
 *     that same <REGION>; transmittance fraction.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_OBJECT_TRANSMITTANCE_FRACTION ((EDCS_Attribute_Code)900)

/*
 * Definition:
 *     The areal density of <OBJECT>s of a specified type.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_OBJECT_TYPE_DENSITY ((EDCS_Attribute_Code)901)

/*
 * Definition:
 *     The numeric identifier of a variation of a type of <OBJECT>; object
 *     variant. All variations of the type of an <OBJECT> have a common
 *     supertype.
 *
 * Value Type: INDEX
 *
 * Group Membership: ABSTRACT_OBJECT, IDENTIFICATION
 */
#define EAC_OBJECT_VARIANT ((EDCS_Attribute_Code)902)

/*
 * Definition:
 *     The vertical distance measured from the lowest point of the base of an
 *     <OBJECT> (downhill side/downstream side) to the prevailing <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_OBJECT_VERTICAL_DISPLACEMENT ((EDCS_Attribute_Code)903)

/*
 * Definition:
 *     The type of obscurant present in an <ATMOSPHERE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBSCTY_ADVECTION_FOG
 *    EEC_OBSCTY_BLOWING_SNOW
 *    EEC_OBSCTY_DESERT_HAZE
 *    EEC_OBSCTY_DESERT_SUMMER
 *    EEC_OBSCTY_DESERT_WINTER
 *    EEC_OBSCTY_DUSTSTORM
 *    EEC_OBSCTY_HAZE
 *    EEC_OBSCTY_MARINE_HAZE
 *    EEC_OBSCTY_NONE_PRESENT
 *    EEC_OBSCTY_RADIATION_FOG
 *    EEC_OBSCTY_RURAL_HAZE
 *    EEC_OBSCTY_SNOW
 *    EEC_OBSCTY_TEMPERATE_SUMMER_DAY
 *    EEC_OBSCTY_TEMPERATE_SUMMER_NIGHT
 *    EEC_OBSCTY_TEMPERATE_WINTER
 *    EEC_OBSCTY_TROPOSPHERIC
 *    EEC_OBSCTY_URBAN_HAZE
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LIGHTING_AND_VISIBILITY
 */
#define EAC_OBSCURANT_TYPE ((EDCS_Attribute_Code)904)

/*
 * Definition:
 *     An indication that one or more observation decks are present on an
 *     <OBJECT>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_OBSERVATION_DECK_PRESENT ((EDCS_Attribute_Code)905)

/*
 * Definition:
 *     The type of an observation platform.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBVPLATTY_AIRCRAFT
 *    EEC_OBVPLATTY_BUOY
 *    EEC_OBVPLATTY_FIXED_WEATHER_STATION
 *    EEC_OBVPLATTY_GEOPHYSICAL_SATELLITE
 *    EEC_OBVPLATTY_HUMAN
 *    EEC_OBVPLATTY_METEOROLOGIC_OBSERVATION_TOWER
 *    EEC_OBVPLATTY_MOTOR_VEHICLE
 *    EEC_OBVPLATTY_VESSEL
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_OBSERVATION_PLATFORM_TYPE ((EDCS_Attribute_Code)906)

/*
 * Definition:
 *     The time at which an observation was made since the epoch 00:00:00
 *     UTC, January 1, 1970 Common Era.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME
 */
#define EAC_OBSERVATION_TIME_EPOCH_1970 ((EDCS_Attribute_Code)907)

/*
 * Definition:
 *     The type of report of observed visibility.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OBVVISRPTTY_MINIMUM
 *    EEC_OBVVISRPTTY_PRVL
 *    EEC_OBVVISRPTTY_PRVL_VAR_HIGH
 *    EEC_OBVVISRPTTY_PRVL_VAR_LOW
 *    EEC_OBVVISRPTTY_SECTOR
 *    EEC_OBVVISRPTTY_TOWER
 *    EEC_OBVVISRPTTY_TOWER_VAR_HIGH
 *    EEC_OBVVISRPTTY_TOWER_VAR_LOW
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_OBSERVED_VISIBILITY_REPORT_TYPE ((EDCS_Attribute_Code)908)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the geodetic east-west
 *     <DIRECTION>, where east is positive.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_OCEAN_CURRENT_EAST_SPEED ((EDCS_Attribute_Code)909)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the geodetic south-north
 *     <DIRECTION>, where north is positive.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_OCEAN_CURRENT_NORTH_SPEED ((EDCS_Attribute_Code)910)

/*
 * Definition:
 *     The U component (geodetic west-east <DIRECTION>, where east is
 *     positive) of the <<WATER_CURRENT_SPEED>> in an <OCEAN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_OCEAN_CURRENT_U ((EDCS_Attribute_Code)911)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the X <DIRECTION> of a
 *     projection-based coordinate system, where +X is positive; the "U"
 *     speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_OCEAN_CURRENT_U_SPEED ((EDCS_Attribute_Code)912)

/*
 * Definition:
 *     The V component (geodetic south-north <DIRECTION>, where north is
 *     positive) of the <<WATER_CURRENT_SPEED>> in an <OCEAN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_OCEAN_CURRENT_V ((EDCS_Attribute_Code)913)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the Y <DIRECTION> of a
 *     projection-based coordinate system, where +Y is positive; the "V"
 *     speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_OCEAN_CURRENT_V_SPEED ((EDCS_Attribute_Code)914)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the down-up <DIRECTION>
 *     where up is positive; the ocean current W.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_OCEAN_CURRENT_W ((EDCS_Attribute_Code)915)

/*
 * Definition:
 *     The ratio of the electrical conductivity of <WATER> in an <OCEAN> to
 *     the electrical conductivity of a potassium chloride standard
 *     solution, in which the mass fraction of potassium chloride is 32,4356
 *     x 10^(-6). Both conductivities are measured at a given
 *     <<WATERBODY_TEMPERATURE>> and a pressure of 1 standard atmosphere. A
 *     ratio of 1 corresponds to a <<PRACTICAL_SALINITY>> of 35.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_OCEAN_ELECTRICAL_CONDUCTIVITY_RATIO ((EDCS_Attribute_Code)916)

/*
 * Definition:
 *     The name of a <REGION> of an <OCEAN_FLOOR> that has measurable relief
 *     or is delimited by relief. The value is formatted in a Basic Latin
 *     string and contains the name for a kind of feature of the
 *     <OCEAN_FLOOR> that may be found in [SUFN].
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: IDENTIFICATION, WATERBODY_FLOOR
 */
#define EAC_OCEAN_FLOOR_REGION_NAME ((EDCS_Attribute_Code)917)

/*
 * Definition:
 *     The type of a named <REGION> of the <OCEAN_FLOOR> that has measurable
 *     relief or is delimited by relief.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OCFLRREGNNAMTY_ABYSSAL_HILLS
 *    EEC_OCFLRREGNNAMTY_ABYSSAL_PLAIN
 *    EEC_OCFLRREGNNAMTY_APRON
 *    EEC_OCFLRREGNNAMTY_ARCHIPELAGIC_APRON
 *    EEC_OCFLRREGNNAMTY_BANK
 *    EEC_OCFLRREGNNAMTY_BANK_SET
 *    EEC_OCFLRREGNNAMTY_BASIN
 *    EEC_OCFLRREGNNAMTY_BORDERLAND
 *    EEC_OCFLRREGNNAMTY_CALDERA
 *    EEC_OCFLRREGNNAMTY_CANYON
 *    EEC_OCFLRREGNNAMTY_CANYON_SET
 *    EEC_OCFLRREGNNAMTY_CAP
 *    EEC_OCFLRREGNNAMTY_CNTNTL_MARGIN
 *    EEC_OCFLRREGNNAMTY_CNTNTL_RISE
 *    EEC_OCFLRREGNNAMTY_CNTNTL_SHELF
 *    EEC_OCFLRREGNNAMTY_CNTNTL_SLOPE
 *    EEC_OCFLRREGNNAMTY_DEEP
 *    EEC_OCFLRREGNNAMTY_ESCARPMENT
 *    EEC_OCFLRREGNNAMTY_FAN
 *    EEC_OCFLRREGNNAMTY_FRACTURE_ZONE
 *    EEC_OCFLRREGNNAMTY_GUYOT
 *    EEC_OCFLRREGNNAMTY_GUYOT_SET
 *    EEC_OCFLRREGNNAMTY_HILL
 *    EEC_OCFLRREGNNAMTY_HILL_SET
 *    EEC_OCFLRREGNNAMTY_HOLE
 *    EEC_OCFLRREGNNAMTY_KNOLL
 *    EEC_OCFLRREGNNAMTY_KNOLL_SET
 *    EEC_OCFLRREGNNAMTY_LEVEE
 *    EEC_OCFLRREGNNAMTY_MEDIAN_VALLEY
 *    EEC_OCFLRREGNNAMTY_MID_OCEANIC_RIDGE
 *    EEC_OCFLRREGNNAMTY_MOAT
 *    EEC_OCFLRREGNNAMTY_MOUNTAIN_SET
 *    EEC_OCFLRREGNNAMTY_PASSAGE
 *    EEC_OCFLRREGNNAMTY_PEAK
 *    EEC_OCFLRREGNNAMTY_PINNACLE
 *    EEC_OCFLRREGNNAMTY_PLAIN
 *    EEC_OCFLRREGNNAMTY_PLATEAU
 *    EEC_OCFLRREGNNAMTY_PROMONTORY
 *    EEC_OCFLRREGNNAMTY_PROVINCE
 *    EEC_OCFLRREGNNAMTY_REEF
 *    EEC_OCFLRREGNNAMTY_REEF_SET
 *    EEC_OCFLRREGNNAMTY_RIDGE
 *    EEC_OCFLRREGNNAMTY_RIDGE_SET
 *    EEC_OCFLRREGNNAMTY_RISE
 *    EEC_OCFLRREGNNAMTY_SADDLE
 *    EEC_OCFLRREGNNAMTY_SEABIGHT
 *    EEC_OCFLRREGNNAMTY_SEA_CHANNEL
 *    EEC_OCFLRREGNNAMTY_SEAMOUNT
 *    EEC_OCFLRREGNNAMTY_SEAMOUNT_CHAIN
 *    EEC_OCFLRREGNNAMTY_SEAMOUNT_GROUP
 *    EEC_OCFLRREGNNAMTY_SEAMOUNT_PROVINCE
 *    EEC_OCFLRREGNNAMTY_SEAMOUNT_SET
 *    EEC_OCFLRREGNNAMTY_SHELF
 *    EEC_OCFLRREGNNAMTY_SHELF_EDGE
 *    EEC_OCFLRREGNNAMTY_SHOAL
 *    EEC_OCFLRREGNNAMTY_SHOAL_SET
 *    EEC_OCFLRREGNNAMTY_SILL
 *    EEC_OCFLRREGNNAMTY_SLOPE
 *    EEC_OCFLRREGNNAMTY_SOUND
 *    EEC_OCFLRREGNNAMTY_SPUR
 *    EEC_OCFLRREGNNAMTY_TERRACE
 *    EEC_OCFLRREGNNAMTY_TRENCH
 *    EEC_OCFLRREGNNAMTY_TROUGH
 *    EEC_OCFLRREGNNAMTY_VALLEY
 *    EEC_OCFLRREGNNAMTY_ZONE
 *
 * Group Membership: WATERBODY_FLOOR
 */
#define EAC_OCEAN_FLOOR_REGION_NAME_TYPE ((EDCS_Attribute_Code)918)

/*
 * Definition:
 *     The name of an <OCEAN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OCEANNAME_ANTARCTIC
 *    EEC_OCEANNAME_ARCTIC
 *    EEC_OCEANNAME_ATLANTIC
 *    EEC_OCEANNAME_INDIAN
 *    EEC_OCEANNAME_NORTH_ATLANTIC
 *    EEC_OCEANNAME_NORTH_PACIFIC
 *    EEC_OCEANNAME_PACIFIC
 *    EEC_OCEANNAME_SOUTH_ATLANTIC
 *    EEC_OCEANNAME_SOUTH_CHINA
 *    EEC_OCEANNAME_SOUTH_PACIFIC
 *
 * Group Membership: HYDROLOGY, IDENTIFICATION
 */
#define EAC_OCEAN_NAME ((EDCS_Attribute_Code)919)

/*
 * Definition:
 *     The type of an offshore platform.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OFFSHPLATTY_ACCOMMODATION
 *    EEC_OFFSHPLATTY_ARTICULATED_LOADING
 *    EEC_OFFSHPLATTY_ARTIFICIAL_ISLAND
 *    EEC_OFFSHPLATTY_FLOATING_PRODUCTION_VESSEL
 *    EEC_OFFSHPLATTY_MOORING_TOWER
 *    EEC_OFFSHPLATTY_NAVIGATION_AID_SUPPORT
 *    EEC_OFFSHPLATTY_OBSERVATION
 *    EEC_OFFSHPLATTY_OBSERVATION_RESEARCH
 *    EEC_OFFSHPLATTY_OIL_DERRICK
 *    EEC_OFFSHPLATTY_PRODUCTION
 *    EEC_OFFSHPLATTY_RESEARCH
 *    EEC_OFFSHPLATTY_SINGLE_ANCHOR_LEG_MOORING
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_OFFSHORE_PLATFORM_TYPE ((EDCS_Attribute_Code)920)

/*
 * Definition:
 *     The type of an <OIL_BARRIER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OILBARTY_FLOATING
 *    EEC_OILBARTY_OIL_RETENTION_PIPE
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, WATERBODY_SURFACE
 */
#define EAC_OIL_BARRIER_TYPE ((EDCS_Attribute_Code)921)

/*
 * Definition:
 *     An indication that an <OIL_DRILLING_RIG> exists within a delineated
 *     <REGION>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE
 */
#define EAC_OILRIG_PRESENT ((EDCS_Attribute_Code)922)

/*
 * Definition:
 *     A qualitative estimate of the degree of confidence in the
 *     <<OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL>> at a specified <<FREQUENCY>>,
 *     based on the quantity and variability of the measurements.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OMNDSHPNSECNF_LOW
 *    EEC_OMNDSHPNSECNF_MEDIUM
 *    EEC_OMNDSHPNSECNF_HIGH
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_STATE
 */
#define EAC_OMNIDIR_SHIP_NOISE_CONFIDENCE ((EDCS_Attribute_Code)923)

/*
 * Definition:
 *     The correction to the <<OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_OMNIDIR_SHIP_NOISE_CORRECTION ((EDCS_Attribute_Code)924)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> required for omnidirectional shipping noise to
 *     decorrelate and/or disperse, typically taken at 50 hertz.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: ACOUSTIC_PHENOMENON, TIME
 */
#define EAC_OMNIDIR_SHIP_NOISE_DECORRELATION_TIME ((EDCS_Attribute_Code)925)

/*
 * Definition:
 *     The degree of spatial variation of omnidirectional shipping noise,
 *     typically taken at 50 hertz.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_OMNIDIR_SHIP_NOISE_SPATIAL_VARIATION ((EDCS_Attribute_Code)926)

/*
 * Definition:
 *     The omnidirectional shipping noise spectral power level in a
 *     <<VOLUME>> of a <WATERBODY>, typically taken at 50 hertz.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL ((EDCS_Attribute_Code)927)

/*
 * Definition:
 *     A number between 0 and 1 representing a linearly-scaled fraction
 *     specifying the degree of line of sight blockage. The value is, on
 *     average, the fraction of the cross-sectional <<AREA>> of a
 *     non-homogeneous <OBJECT> that completely blocks the line of sight;
 *     the opacity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_OPACITY ((EDCS_Attribute_Code)928)

/*
 * Definition:
 *     The conditions during which the use of an <OBJECT> (for example: a
 *     <FACILITY> and/or an <AIRSPACE>) is restricted.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OPERRESTTY_DAYTIME_ONLY
 *    EEC_OPERRESTTY_NIGHT_TIME_ONLY
 *    EEC_OPERRESTTY_NO_RESTRICTIONS
 *    EEC_OPERRESTTY_PRONE_TO_FLOODING
 *    EEC_OPERRESTTY_PRONE_TO_ICE
 *    EEC_OPERRESTTY_PRONE_TO_SNOW
 *    EEC_OPERRESTTY_SPECIAL_RESTRICTIONS
 *
 * Group Membership: ABSTRACT_OBJECT, USAGE_REGION
 */
#define EAC_OPERATING_RESTRICTIONS_TYPE ((EDCS_Attribute_Code)929)

/*
 * Definition:
 *     The times during which the use of an <OBJECT> (for example: a
 *     <FACILITY> and/or an <AIRSPACE>) is unrestricted.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OPERTIME_CONTINUOUS
 *    EEC_OPERTIME_DAYTIME
 *    EEC_OPERTIME_NIGHT_TIME
 *    EEC_OPERTIME_SUMMER_TIME_APRIL_OCTOBER
 *    EEC_OPERTIME_WINTER_TIME_NOVEMBER_MARCH
 *
 * Group Membership: ABSTRACT_OBJECT, TIME, USAGE_REGION
 */
#define EAC_OPERATING_TIME ((EDCS_Attribute_Code)930)

/*
 * Definition:
 *     An indication that an <OBJECT> is operational.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, USAGE_REGION
 */
#define EAC_OPERATIONAL ((EDCS_Attribute_Code)931)

/*
 * Definition:
 *     A measure of fluctuations in the index of refraction at optical
 *     <<WAVELENGTH>>s resulting from turbulence in the <ATMOSPHERE>. The
 *     value is measured by the refractive index structure parameter that
 *     represents the correlation of refractive indices over distances of a
 *     few metres; the optical turbulence intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_DENSITY
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_OPTICAL_TURBULENCE_INTENSITY ((EDCS_Attribute_Code)932)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> measured in the local horizontal plane normal
 *     to the vertical axis of an <OBJECT> to the major (longitudinal) axis
 *     of the <OBJECT>. If the <OBJECT> is square, a value from 0 to 90 arc
 *     degrees (or equivalent) is recorded. If the <OBJECT> is circular, 360
 *     arc degrees (or equivalent) is recorded.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_ORIENTATION_ANGLE ((EDCS_Attribute_Code)933)

/*
 * Definition:
 *     The diameter of a cylindrical or spherical <OBJECT> measured using the
 *     outside <SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_OUTSIDE_DIAMETER ((EDCS_Attribute_Code)934)

/*
 * Definition:
 *     The vertical distance measured from the lowest point at the level of
 *     the <TERRAIN> or <WATERBODY_SURFACE> to the highest portion of a
 *     <BRIDGE>, including any <BRIDGE_SUPERSTRUCTURE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_OVERALL_BRIDGE_HEIGHT ((EDCS_Attribute_Code)935)

/*
 * Definition:
 *     The overall vertical dimension that includes all <COMPONENT>s of an
 *     <OBJECT>, including both those above and those below the <TERRAIN>
 *     (for a <TERRAIN_SURFACE_OBJECT>) or <WATERBODY_SURFACE> (for an
 *     <OBJECT> on a <WATERBODY_SURFACE>).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_OVERALL_VERTICAL_DIMENSION ((EDCS_Attribute_Code)936)

/*
 * Definition:
 *     The least distance between a <LAND_TRANSPORTATION_ROUTE> and any
 *     <OVERHEAD_OBSTRUCTION> vertically above it; the overhead clearance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_OVERHEAD_CLEARANCE ((EDCS_Attribute_Code)937)

/*
 * Definition:
 *     An indication that a <DEFENSIVE_POSITION> provides protection (cover)
 *     from the effects of overhead detonation of <MUNITION>s.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: MILITARY_SCIENCE, SHELTER
 */
#define EAC_OVERHEAD_COVER ((EDCS_Attribute_Code)938)

/*
 * Definition:
 *     An indication that there is an <OVERHEAD_OBSTRUCTION> less than 4,3
 *     metres above a <LAND_TRANSPORTATION_ROUTE>; overhead obstructed.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_OVERHEAD_OBSTRUCTED ((EDCS_Attribute_Code)939)

/*
 * Definition:
 *     The type of an <OVERHEAD_OBSTRUCTION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_OVRHDOBSTNTY_BRIDGE_SUPERSTRUCTURE
 *    EEC_OVRHDOBSTNTY_HIGH_TENSION_POWERLINE
 *    EEC_OVRHDOBSTNTY_RAILWAY_POWERLINE
 *    EEC_OVRHDOBSTNTY_ROOF
 *    EEC_OVRHDOBSTNTY_VIADUCT_ARCH_CONSTRUCTION
 *    EEC_OVRHDOBSTNTY_VIADUCT_FRAME_CONSTRUCTION
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_OVERHEAD_OBSTRUCTION_TYPE ((EDCS_Attribute_Code)940)

/*
 * Definition:
 *     The total number of nominally parallel <LINE>s within an <OBJECT>; the
 *     parallel line count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_PARALLEL_LINE_COUNT ((EDCS_Attribute_Code)941)

/*
 * Definition:
 *     The type of a <PARAPET>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PARAPETTY_EARTHEN_WALL
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_PARAPET_TYPE ((EDCS_Attribute_Code)942)

/*
 * Definition:
 *     The energy of a charged <PARTICLE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: ENERGY
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_PARTICLE_ENERGY ((EDCS_Attribute_Code)943)

/*
 * Definition:
 *     An indication that a <WATERBODY> is partitioned.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: HYDROLOGY, WATERBODY_STATE
 */
#define EAC_PARTITIONED_WATERBODY ((EDCS_Attribute_Code)944)

/*
 * Definition:
 *     A method of categorizing the stability of an <ATMOSPHERE_REGION> of
 *     the <EARTH> in terms of the horizontal surface <<WIND_SPEED>>, the
 *     amount of solar radiation (insolation), and the
 *     <<TOTAL_CLOUD_COVERAGE>>; the Pasquill atmosphere stability index.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PASQATMSTAB_CATEGORY_A
 *    EEC_PASQATMSTAB_CATEGORY_A_B
 *    EEC_PASQATMSTAB_CATEGORY_B
 *    EEC_PASQATMSTAB_CATEGORY_B_C
 *    EEC_PASQATMSTAB_CATEGORY_C
 *    EEC_PASQATMSTAB_CATEGORY_C_D
 *    EEC_PASQATMSTAB_CATEGORY_D
 *    EEC_PASQATMSTAB_CATEGORY_E
 *    EEC_PASQATMSTAB_CATEGORY_F
 *    EEC_PASQATMSTAB_CATEGORY_G
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_PASQUILL_ATMOSPHERE_STABILITY_INDEX ((EDCS_Attribute_Code)945)

/*
 * Definition:
 *     An indication that a passageway is blocked to the movement of
 *     <VEHICLE>s and/or <PERSONNEL>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: TRNSP
 */
#define EAC_PASSAGE_BLOCKED ((EDCS_Attribute_Code)946)

/*
 * Definition:
 *     An indication that an <OBJECT> generates acoustic energy not intended
 *     for the purposes of detection, localization, and/or identification;
 *     passive acoustic.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, ACOUSTIC_PHENOMENON
 */
#define EAC_PASSIVE_ACOUSTIC ((EDCS_Attribute_Code)947)

/*
 * Definition:
 *     The number of independent, parallel paths (for example: a
 *     <RAILWAY_TRACK> and/or a <ROUTE_LANE>) in both <DIRECTION>s within a
 *     <LAND_TRANSPORTATION_ROUTE>; the path count.
 *
 * Value Type: COUNT
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_PATH_COUNT ((EDCS_Attribute_Code)948)

/*
 * Definition:
 *     The type of a <PATROL_CRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PTLCRFTTY_AB_21_CLASS
 *    EEC_PTLCRFTTY_AB_25_CLASS
 *    EEC_PTLCRFTTY_ABJAY_CLASS
 *    EEC_PTLCRFTTY_ACHIMITA_CLASS
 *    EEC_PTLCRFTTY_ADDIRIYAH_CLASS
 *    EEC_PTLCRFTTY_AGDLEK_CLASS
 *    EEC_PTLCRFTTY_AGUINALDO_CLASS
 *    EEC_PTLCRFTTY_AL_BOOM_CLASS
 *    EEC_PTLCRFTTY_AL_BUSHRA_CLASS
 *    EEC_PTLCRFTTY_AL_ISAR_CLASS
 *    EEC_PTLCRFTTY_AL_MABRUKAH_CLASS
 *    EEC_PTLCRFTTY_AL_MANAMA_CLASS
 *    EEC_PTLCRFTTY_AL_RIFFA_CLASS
 *    EEC_PTLCRFTTY_AL_ZATUM_CLASS
 *    EEC_PTLCRFTTY_ALBATROS_MISSILE_BOAT_CLASS
 *    EEC_PTLCRFTTY_ALBATROS_POLAR_CLASS
 *    EEC_PTLCRFTTY_ALBORAN_CLASS
 *    EEC_PTLCRFTTY_ALFEREZ_SOBRAL_SOTOYOMO_CLASS
 *    EEC_PTLCRFTTY_ALMARADIM_CLASS
 *    EEC_PTLCRFTTY_ALMIRANTE_BALSAM_CLASS
 *    EEC_PTLCRFTTY_AMAZONAS_CLASS
 *    EEC_PTLCRFTTY_AMBASSADOR_III_CLASS
 *    EEC_PTLCRFTTY_AMER_CLASS
 *    EEC_PTLCRFTTY_ANAGA_CLASS
 *    EEC_PTLCRFTTY_ANDAU_CLASS
 *    EEC_PTLCRFTTY_ANDRADE_CLASS
 *    EEC_PTLCRFTTY_ANTARCTIC_CLASS
 *    EEC_PTLCRFTTY_ANTIPLIARCHOS_LASCOS_CLASS
 *    EEC_PTLCRFTTY_ARDHANA_CLASS
 *    EEC_PTLCRFTTY_ARMATOLOS_CLASS
 *    EEC_PTLCRFTTY_ARNALA_CLASS
 *    EEC_PTLCRFTTY_ASHEVILLE_CLASS
 *    EEC_PTLCRFTTY_AYAM_CLASS
 *    EEC_PTLCRFTTY_AZMAT_CLASS
 *    EEC_PTLCRFTTY_BADR_CLASS
 *    EEC_PTLCRFTTY_BAKASSI_CLASS
 *    EEC_PTLCRFTTY_BALIKPAPAN_CLASS
 *    EEC_PTLCRFTTY_BANIYAS_CLASS
 *    EEC_PTLCRFTTY_BARCELO_CLASS
 *    EEC_PTLCRFTTY_BARNEGAT_CLASS
 *    EEC_PTLCRFTTY_BARRACUDA_CLASS
 *    EEC_PTLCRFTTY_BARSO_CLASS
 *    EEC_PTLCRFTTY_BARZAN_CLASS
 *    EEC_PTLCRFTTY_BATILLO_CLASS
 *    EEC_PTLCRFTTY_BESKYTTEREN_CLASS
 *    EEC_PTLCRFTTY_BETELGEUSE_CLASS
 *    EEC_PTLCRFTTY_BISHKALI_CLASS
 *    EEC_PTLCRFTTY_BIZERTE_CLASS
 *    EEC_PTLCRFTTY_BORA_CLASS
 *    EEC_PTLCRFTTY_BOULINGUI_CLASS
 *    EEC_PTLCRFTTY_BPS_500_CLASS
 *    EEC_PTLCRFTTY_BRACUI_CLASS
 *    EEC_PTLCRFTTY_BULTA_STORM_CLASS
 *    EEC_PTLCRFTTY_BURUN_CLASS
 *    EEC_PTLCRFTTY_BURYA_CLASS
 *    EEC_PTLCRFTTY_CACINE_CLASS
 *    EEC_PTLCRFTTY_CAMBIASO_CLASS
 *    EEC_PTLCRFTTY_CANNON_CLASS
 *    EEC_PTLCRFTTY_CAPE_CLASS
 *    EEC_PTLCRFTTY_CASMA_CLASS
 *    EEC_PTLCRFTTY_CASSIOPEA_CLASS
 *    EEC_PTLCRFTTY_CASTLE_CLASS
 *    EEC_PTLCRFTTY_CHEROKEE_CLASS
 *    EEC_PTLCRFTTY_CHILREU_CLASS
 *    EEC_PTLCRFTTY_CHONBURI_CLASS
 *    EEC_PTLCRFTTY_CONSTITUCION__CLASS
 *    EEC_PTLCRFTTY_COUTINHO_CLASS
 *    EEC_PTLCRFTTY_CYCLONE_CLASS
 *    EEC_PTLCRFTTY_DAMSAH_CLASS
 *    EEC_PTLCRFTTY_DEMOCRATA_CLASS
 *    EEC_PTLCRFTTY_DERGACH_CLASS
 *    EEC_PTLCRFTTY_DESCUBIERTA_CLASS
 *    EEC_PTLCRFTTY_DHOFAR_CLASS
 *    EEC_PTLCRFTTY_DJEBEL_CHINOISE_CLASS
 *    EEC_PTLCRFTTY_DOGAN_CLASS
 *    EEC_PTLCRFTTY_DURDHARSHA_CLASS
 *    EEC_PTLCRFTTY_DZATA_CLASS
 *    EEC_PTLCRFTTY_DZUKAS_STORM_CLASS
 *    EEC_PTLCRFTTY_EILAT_CLASS
 *    EEC_PTLCRFTTY_EITHNE_CLASS
 *    EEC_PTLCRFTTY_EL_LAHIQ_CLASS
 *    EEC_PTLCRFTTY_EL_YADEKH_CLASS
 *    EEC_PTLCRFTTY_EMER_CLASS
 *    EEC_PTLCRFTTY_ENRIQUILLO_SOTOYOMO_CLASS
 *    EEC_PTLCRFTTY_EREBUS_CLASS
 *    EEC_PTLCRFTTY_ESPEROS_CLASS
 *    EEC_PTLCRFTTY_EXPLORATORE_CLASS
 *    EEC_PTLCRFTTY_FATEH_CLASS
 *    EEC_PTLCRFTTY_FEARLESS_ASW_CLASS
 *    EEC_PTLCRFTTY_FEARLESS_MISSILE_CLASS
 *    EEC_PTLCRFTTY_FLAMANT_CLASS
 *    EEC_PTLCRFTTY_FLAMENCO_CLASS
 *    EEC_PTLCRFTTY_FLYVEFISKEN_CLASS
 *    EEC_PTLCRFTTY_FORT_CHARLES_CLASS
 *    EEC_PTLCRFTTY_FPB_42_CLASS
 *    EEC_PTLCRFTTY_FREMANTLE_CLASS
 *    EEC_PTLCRFTTY_FULGOSI_CLASS
 *    EEC_PTLCRFTTY_FULMAR_CLASS
 *    EEC_PTLCRFTTY_GEOULA_CLASS
 *    EEC_PTLCRFTTY_GEPARD_CLASS
 *    EEC_PTLCRFTTY_GORNIK_CLASS
 *    EEC_PTLCRFTTY_GOTEBORG_CLASS
 *    EEC_PTLCRFTTY_GRAJAU_CLASS
 *    EEC_PTLCRFTTY_GREBE_CLASS
 *    EEC_PTLCRFTTY_GRISHA_II_CLASS
 *    EEC_PTLCRFTTY_GRISHA_III_ASW_CLASS
 *    EEC_PTLCRFTTY_GRISHA_III_CLASS
 *    EEC_PTLCRFTTY_GRISHA_IV_CLASS
 *    EEC_PTLCRFTTY_GRISHA_V_ASW_CLASS
 *    EEC_PTLCRFTTY_GRISHA_V_CLASS
 *    EEC_PTLCRFTTY_GRIVITA_CLASS
 *    EEC_PTLCRFTTY_GRONZY_CLASS
 *    EEC_PTLCRFTTY_GUARDIAMARINA_RIQUELME_CLASS
 *    EEC_PTLCRFTTY_GUARDIAN_CLASS
 *    EEC_PTLCRFTTY_GUAYMURAS_CLASS
 *    EEC_PTLCRFTTY_HAI_OU_CLASS
 *    EEC_PTLCRFTTY_HAIJIU_CLASS
 *    EEC_PTLCRFTTY_HAINAN_ASW_CLASS
 *    EEC_PTLCRFTTY_HAINAN_CLASS
 *    EEC_PTLCRFTTY_HAINYEKO_OSPREY_CLASS
 *    EEC_PTLCRFTTY_HAIQING_CLASS
 *    EEC_PTLCRFTTY_HAIZHU_CLASS
 *    EEC_PTLCRFTTY_HAIZHUI_CLASS
 *    EEC_PTLCRFTTY_HAMINA_CLASS
 *    EEC_PTLCRFTTY_HANDALAN_CLASS
 *    EEC_PTLCRFTTY_HAUK_CLASS
 *    EEC_PTLCRFTTY_HAYABUSA_CLASS
 *    EEC_PTLCRFTTY_HEL_CLASS
 *    EEC_PTLCRFTTY_HELSINKI_CLASS
 *    EEC_PTLCRFTTY_HERNANDES_CLASS
 *    EEC_PTLCRFTTY_HETZ_CLASS
 *    EEC_PTLCRFTTY_HISAR_CLASS
 *    EEC_PTLCRFTTY_HOLZINGER_CLASS
 *    EEC_PTLCRFTTY_HOUJIAN_CLASS
 *    EEC_PTLCRFTTY_HOUKO_CLASS
 *    EEC_PTLCRFTTY_HOUNAN_CLASS
 *    EEC_PTLCRFTTY_HOUXIN_CLASS
 *    EEC_PTLCRFTTY_HUA_HIN_CLASS
 *    EEC_PTLCRFTTY_HUANGFENG_CLASS
 *    EEC_PTLCRFTTY_HUDONG_CLASS
 *    EEC_PTLCRFTTY_HUNT_CLASS
 *    EEC_PTLCRFTTY_IMPERIAL_MARINHEIRO_CLASS
 *    EEC_PTLCRFTTY_IN_DAW_OSPREY_CLASS
 *    EEC_PTLCRFTTY_INTREPIDA_CLASS
 *    EEC_PTLCRFTTY_IPOPLIARCHOS_ARLIOTIS_CLASS
 *    EEC_PTLCRFTTY_IQUIQUE_CLASS
 *    EEC_PTLCRFTTY_IRIGOYEN_CLASS
 *    EEC_PTLCRFTTY_ISLAND_CLASS
 *    EEC_PTLCRFTTY_ISLAND_OFFSHORE_CLASS
 *    EEC_PTLCRFTTY_JACINTO_CLASS
 *    EEC_PTLCRFTTY_JAGAREN_CLASS
 *    EEC_PTLCRFTTY_JALALAT_CLASS
 *    EEC_PTLCRFTTY_JAYESAGARA_CLASS
 *    EEC_PTLCRFTTY_JERONG_CLASS
 *    EEC_PTLCRFTTY_JING_CHIANG_CLASS
 *    EEC_PTLCRFTTY_JURA_CLASS
 *    EEC_PTLCRFTTY_KAGITINGAN_CLASS
 *    EEC_PTLCRFTTY_KALEV_CLASS
 *    EEC_PTLCRFTTY_KAMAN_CLASS
 *    EEC_PTLCRFTTY_KAPAK_CLASS
 *    EEC_PTLCRFTTY_KAPAREN_CLASS
 *    EEC_PTLCRFTTY_KARNIPHULI_CLASS
 *    EEC_PTLCRFTTY_KARTAL_CLASS
 *    EEC_PTLCRFTTY_KASZUB_CLASS
 *    EEC_PTLCRFTTY_KELEFSTIS_STAMOU_CLASS
 *    EEC_PTLCRFTTY_KHAMRONSIN_CLASS
 *    EEC_PTLCRFTTY_KHATTABI_CLASS
 *    EEC_PTLCRFTTY_KILIC_CLASS
 *    EEC_PTLCRFTTY_KILURKI_11__CLASS
 *    EEC_PTLCRFTTY_KINGSTON_CLASS
 *    EEC_PTLCRFTTY_KOGALNICEANU_CLASS
 *    EEC_PTLCRFTTY_KONCAR_CLASS
 *    EEC_PTLCRFTTY_KONDOR_CLASS
 *    EEC_PTLCRFTTY_KONDOR_I_CLASS
 *    EEC_PTLCRFTTY_KREMENCHUK_CLASS
 *    EEC_PTLCRFTTY_KRESIMIR_CLASS
 *    EEC_PTLCRFTTY_KRONSTADT_CLASS
 *    EEC_PTLCRFTTY_KUKULKAN_BROADSWORD_CLASS
 *    EEC_PTLCRFTTY_KUNAKHOVICH_CLASS
 *    EEC_PTLCRFTTY_KWANG_HUA_CLASS
 *    EEC_PTLCRFTTY_LA_GALITE_CLASS
 *    EEC_PTLCRFTTY_LAKSAMANA_CLASS
 *    EEC_PTLCRFTTY_LAMDA_CLASS
 *    EEC_PTLCRFTTY_LARDENT_CLASS
 *    EEC_PTLCRFTTY_LARKANA_CLASS
 *    EEC_PTLCRFTTY_LAUDACIEUSE_CLASS
 *    EEC_PTLCRFTTY_LAUDACIEUX_CLASS
 *    EEC_PTLCRFTTY_LAZAGA_CLASS
 *    EEC_PTLCRFTTY_LETYASHTI_CLASS
 *    EEC_PTLCRFTTY_LUNG_CHIANG_CLASS
 *    EEC_PTLCRFTTY_LUSHUN_CLASS
 *    EEC_PTLCRFTTY_MALVAR_CLASS
 *    EEC_PTLCRFTTY_MANDAU_CLASS
 *    EEC_PTLCRFTTY_MANTA_CLASS
 *    EEC_PTLCRFTTY_MARANON_CLASS
 *    EEC_PTLCRFTTY_MATKA_CLASS
 *    EEC_PTLCRFTTY_MEGHNA_CLASS
 *    EEC_PTLCRFTTY_MEKO_A100_CLASS
 *    EEC_PTLCRFTTY_MICALVI_CLASS
 *    EEC_PTLCRFTTY_MIRNA_CLASS
 *    EEC_PTLCRFTTY_MITAR_ACEV_CLASS
 *    EEC_PTLCRFTTY_MOA_CLASS
 *    EEC_PTLCRFTTY_MUBARRAZ_CLASS
 *    EEC_PTLCRFTTY_MUKHA_CLASS
 *    EEC_PTLCRFTTY_MULNIYA_TARANTUL_CLASS
 *    EEC_PTLCRFTTY_MURATURE_CLASS
 *    EEC_PTLCRFTTY_MURRAY_JIP_CLASS
 *    EEC_PTLCRFTTY_MUSYTARI_CLASS
 *    EEC_PTLCRFTTY_NALUCA_CLASS
 *    EEC_PTLCRFTTY_NANAWA_CLASS
 *    EEC_PTLCRFTTY_NANUCHKA_IV_CLASS
 *    EEC_PTLCRFTTY_NAOS_CLASS
 *    EEC_PTLCRFTTY_NATYA_CLASS
 *    EEC_PTLCRFTTY_NEMEIS_CLASS
 *    EEC_PTLCRFTTY_NEW_CLASS
 *    EEC_PTLCRFTTY_NEW_MISSILE_CLASS
 *    EEC_PTLCRFTTY_NIKI_CLASS
 *    EEC_PTLCRFTTY_NIKOPOL_CLASS
 *    EEC_PTLCRFTTY_NIRBHOY_HAINAN_CLASS
 *    EEC_PTLCRFTTY_NOVI_GRAD_CLASS
 *    EEC_PTLCRFTTY_NOVIEMBRE_15_VIGILANT_CLASS
 *    EEC_PTLCRFTTY_OCTOBER_6_CLASS
 *    EEC_PTLCRFTTY_OKBA_CLASS
 *    EEC_PTLCRFTTY_OLIVIERI_CLASS
 *    EEC_PTLCRFTTY_ORKAN_CLASS
 *    EEC_PTLCRFTTY_ORLA_CLASS
 *    EEC_PTLCRFTTY_ORMI_CLASS
 *    EEC_PTLCRFTTY_ORYX_CLASS
 *    EEC_PTLCRFTTY_OSA_CLASS
 *    EEC_PTLCRFTTY_OSA_I_CLASS
 *    EEC_PTLCRFTTY_OSA_II_CLASS
 *    EEC_PTLCRFTTY_OSA_II_TYPE_205_CLASS
 *    EEC_PTLCRFTTY_OUMAR_CLASS
 *    EEC_PTLCRFTTY_P121_CLASS
 *    EEC_PTLCRFTTY_PACIFIC_FORUM_CLASS
 *    EEC_PTLCRFTTY_PADMA_CLASS
 *    EEC_PTLCRFTTY_PANDRONG_CLASS
 *    EEC_PTLCRFTTY_PANQUIACO_CLASS
 *    EEC_PTLCRFTTY_PARAKRAMABAHU_HAIQING_CLASS
 *    EEC_PTLCRFTTY_PARCHIM_II_CLASS
 *    EEC_PTLCRFTTY_PARNAIBA_CLASS
 *    EEC_PTLCRFTTY_PARVIN_CLASS
 *    EEC_PTLCRFTTY_PATRA_CLASS
 *    EEC_PTLCRFTTY_PAUK_ASW_CLASS
 *    EEC_PTLCRFTTY_PAUK_CLASS
 *    EEC_PTLCRFTTY_PCL_CLASS
 *    EEC_PTLCRFTTY_PEDRO_TEIXEIRA_CLASS
 *    EEC_PTLCRFTTY_PERDANA_CLASS
 *    EEC_PTLCRFTTY_PETYA_CLASS
 *    EEC_PTLCRFTTY_PETYA_II_CLASS
 *    EEC_PTLCRFTTY_PETYA_II_LARGE_CLASS
 *    EEC_PTLCRFTTY_PETYA_III_CLASS
 *    EEC_PTLCRFTTY_PETYA_III_LARGE_CLASS
 *    EEC_PTLCRFTTY_PEZOPOULOS_CLASS
 *    EEC_PTLCRFTTY_PGM_43_CLASS
 *    EEC_PTLCRFTTY_PILICA_CLASS
 *    EEC_PTLCRFTTY_PIRANA_CLASS
 *    EEC_PTLCRFTTY_PRABRARAPAK_CLASS
 *    EEC_PTLCRFTTY_PRACHAND_CLASS
 *    EEC_PTLCRFTTY_PRESTOL_BOTELLO_ADMIRABLE_CLASS
 *    EEC_PTLCRFTTY_PROMETEY_CLASS
 *    EEC_PTLCRFTTY_PROTECTOR_CLASS
 *    EEC_PTLCRFTTY_PULAU_ROTE_CLASS
 *    EEC_PTLCRFTTY_PYROPOLITIS_CLASS
 *    EEC_PTLCRFTTY_QARQ_CLASS
 *    EEC_PTLCRFTTY_QUINTANA_CLASS
 *    EEC_PTLCRFTTY_QUITO_CLASS
 *    EEC_PTLCRFTTY_RABHI_CLASS
 *    EEC_PTLCRFTTY_RADE_KONCAR_CLASS
 *    EEC_PTLCRFTTY_RAIS_BARGACH_CLASS
 *    EEC_PTLCRFTTY_RAIS_HAMIDOU_CLASS
 *    EEC_PTLCRFTTY_RAMADAN_CLASS
 *    EEC_PTLCRFTTY_RANARISI_CLASS
 *    EEC_PTLCRFTTY_RATCHARIT_CLASS
 *    EEC_PTLCRFTTY_RAUMA_CLASS
 *    EEC_PTLCRFTTY_RESHEF_CLASS
 *    EEC_PTLCRFTTY_RESHITELNI_CLASS
 *    EEC_PTLCRFTTY_RIO_HACHA_CLASS
 *    EEC_PTLCRFTTY_RIVER_CLASS
 *    EEC_PTLCRFTTY_RIZAL_CLASS
 *    EEC_PTLCRFTTY_ROISIN_CLASS
 *    EEC_PTLCRFTTY_RORAIMA_CLASS
 *    EEC_PTLCRFTTY_SALTO_CLASS
 *    EEC_PTLCRFTTY_SARIWON_TRAL_CLASS
 *    EEC_PTLCRFTTY_SATTAHIP_CLASS
 *    EEC_PTLCRFTTY_SBD_MK3_CLASS
 *    EEC_PTLCRFTTY_SDB_MK3_CLASS
 *    EEC_PTLCRFTTY_SEA_WOLF_CLASS
 *    EEC_PTLCRFTTY_SEPTEMBER_25_BROADSWORD_CLASS
 *    EEC_PTLCRFTTY_SERVIOLA_CLASS
 *    EEC_PTLCRFTTY_SHAHEED_CLASS
 *    EEC_PTLCRFTTY_SHANGHAI_II_CLASS
 *    EEC_PTLCRFTTY_SHERSHEN_CLASS
 *    EEC_PTLCRFTTY_SHERSHEN_TORPEDO_CLASS
 *    EEC_PTLCRFTTY_SHUPAVU_CLASS
 *    EEC_PTLCRFTTY_SIBARU_CLASS
 *    EEC_PTLCRFTTY_SIDDIQ_CLASS
 *    EEC_PTLCRFTTY_SIERRA_CLASS
 *    EEC_PTLCRFTTY_SINPO_CLASS
 *    EEC_PTLCRFTTY_SIRIO_CLASS
 *    EEC_PTLCRFTTY_SKJOLD_CLASS
 *    EEC_PTLCRFTTY_SMALL_412_CLASS
 *    EEC_PTLCRFTTY_SMALL_421_CLASS
 *    EEC_PTLCRFTTY_SMIRDAN_CLASS
 *    EEC_PTLCRFTTY_SMUTS_CLASS
 *    EEC_PTLCRFTTY_SO1_CLASS
 *    EEC_PTLCRFTTY_SOIMUL_CLASS
 *    EEC_PTLCRFTTY_SONYA_CLASS
 *    EEC_PTLCRFTTY_STENKA_CLASS
 *    EEC_PTLCRFTTY_STERNE_CLASS
 *    EEC_PTLCRFTTY_STOCKHOLM_CLASS
 *    EEC_PTLCRFTTY_STORIONE_CLASS
 *    EEC_PTLCRFTTY_SUDUVIS_CLASS
 *    EEC_PTLCRFTTY_SUKANYA_CLASS
 *    EEC_PTLCRFTTY_SULEV_KONDOR_I_CLASS
 *    EEC_PTLCRFTTY_SUPER_VITA_CLASS
 *    EEC_PTLCRFTTY_SWIFTSHIPS_CLASS
 *    EEC_PTLCRFTTY_T_301_CLASS
 *    EEC_PTLCRFTTY_T_43_CLASS
 *    EEC_PTLCRFTTY_T11_CLASS
 *    EEC_PTLCRFTTY_T91_CLASS
 *    EEC_PTLCRFTTY_T93_CLASS
 *    EEC_PTLCRFTTY_TAECHONG_CLASS
 *    EEC_PTLCRFTTY_TARANTUL_CLASS
 *    EEC_PTLCRFTTY_TARANTUL_I_CLASS
 *    EEC_PTLCRFTTY_TARANTUL_II_CLASS
 *    EEC_PTLCRFTTY_TARANTUL_III_CLASS
 *    EEC_PTLCRFTTY_TAZARKA_CLASS
 *    EEC_PTLCRFTTY_TIGER_CLASS
 *    EEC_PTLCRFTTY_TODAK_CLASS
 *    EEC_PTLCRFTTY_TOWN_CLASS
 *    EEC_PTLCRFTTY_TRABZON_CLASS
 *    EEC_PTLCRFTTY_TRITAO_CLASS
 *    EEC_PTLCRFTTY_TSYURUPYNSK_CLASS
 *    EEC_PTLCRFTTY_TURUNMAA_CLASS
 *    EEC_PTLCRFTTY_TURYA_CLASS
 *    EEC_PTLCRFTTY_TURYA_SHTORM_CLASS
 *    EEC_PTLCRFTTY_URIBE_CLASS
 *    EEC_PTLCRFTTY_UTIQUE_CLASS
 *    EEC_PTLCRFTTY_UZGOROD_CLASS
 *    EEC_PTLCRFTTY_VALAS_BALSAM_CLASS
 *    EEC_PTLCRFTTY_VALLE_CLASS
 *    EEC_PTLCRFTTY_VAMBOLA_CLASS
 *    EEC_PTLCRFTTY_VB_76_CLASS
 *    EEC_PTLCRFTTY_VEER_CLASS
 *    EEC_PTLCRFTTY_VELARDE_CLASS
 *    EEC_PTLCRFTTY_VIESTURUS_CLASS
 *    EEC_PTLCRFTTY_VIGAYURG_CLASS
 *    EEC_PTLCRFTTY_VIGILANT_CLASS
 *    EEC_PTLCRFTTY_VISBY_CLASS
 *    EEC_PTLCRFTTY_VOSPER_CLASS
 *    EEC_PTLCRFTTY_WAIGEO_CLASS
 *    EEC_PTLCRFTTY_Y301_CLASS
 *    EEC_PTLCRFTTY_Y311_CLASS
 *    EEC_PTLCRFTTY_YAN_GYI_AUNG_ADMIRABLE_CLASS
 *    EEC_PTLCRFTTY_YAN_SIT_AUNG_HAINAN_CLASS
 *    EEC_PTLCRFTTY_YELVA_CLASS
 *    EEC_PTLCRFTTY_YEVGENYA_CLASS
 *    EEC_PTLCRFTTY_YILDIZ_CLASS
 *    EEC_PTLCRFTTY_YSTAD_CLASS
 *    EEC_PTLCRFTTY_ZBORUL_CLASS
 *    EEC_PTLCRFTTY_ZIBENS_OSA_I_CLASS
 *    EEC_PTLCRFTTY_ZIYAD_CLASS
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_PATROL_CRAFT_TYPE ((EDCS_Attribute_Code)949)

/*
 * Definition:
 *     The maximum or minimum height reached by a rising or falling <TIDE>,
 *     respectively, relative to a <SURFACE_DATUM>; peak tide height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_SURFACE
 */
#define EAC_PEAK_TIDE_HEIGHT ((EDCS_Attribute_Code)950)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> since midnight at which a <<PEAK_TIDE_HEIGHT>>
 *     is reached.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_PEAK_TIDE_TIME ((EDCS_Attribute_Code)951)

/*
 * Definition:
 *     The type of a peak <TIDE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PEAKTIDETY_LOW
 *    EEC_PEAKTIDETY_HIGH
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define EAC_PEAK_TIDE_TYPE ((EDCS_Attribute_Code)952)

/*
 * Definition:
 *     The number of pedestrians an <OBJECT> can accommodate.
 *
 * Value Type: COUNT
 *
 * Group Membership: ABSTRACT_OBJECT, TRNSP
 */
#define EAC_PEDESTRIAN_CAPACITY ((EDCS_Attribute_Code)953)

/*
 * Definition:
 *     The number of pedestrians per <<TIME_QUANTITY>> formatted in a Basic
 *     Latin string using structured text. The string contains a number,
 *     followed by a unit enclosed in parenthesis ("( )"), followed by a
 *     unit qualifier enclosed in square brackets ("[ ]"). EXAMPLE
 *     "100(persons)[per hour]".
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: RATE_OR_RATIO, TRNSP
 */
#define EAC_PEDESTRIAN_RATE ((EDCS_Attribute_Code)954)

/*
 * Definition:
 *     The traversability of an <OBJECT> by a pedestrian.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PEDTRAV_TUNNEL_WITH_PATH
 *    EEC_PEDTRAV_TUNNEL_WITHOUT_PATH
 *    EEC_PEDTRAV_WATER_BODY_NOT_WADABLE
 *    EEC_PEDTRAV_WATER_BODY_WADABLE
 *
 * Group Membership: TRNSP
 */
#define EAC_PEDESTRIAN_TRAVERSABILITY ((EDCS_Attribute_Code)955)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> within a cyclic repeating phenomenon, typically
 *     the intervals of light and eclipse of a <LIGHTHOUSE>; the periodic
 *     cycle time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME
 */
#define EAC_PERIODIC_CYCLE_TIME ((EDCS_Attribute_Code)956)

/*
 * Definition:
 *     The end of the active period for a seasonal <OBJECT> (for example: a
 *     <BUOY>). The value is formatted as specified by <<DATE_FORMAT>> or by
 *     <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ABSTRACT_OBJECT, TIME
 */
#define EAC_PERIODIC_END_DATE ((EDCS_Attribute_Code)957)

/*
 * Definition:
 *     The <<MONTH>> in which restrictions end on the use of an <OBJECT> due
 *     to climate or other limitations; the periodic restriction end.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PERDCRESTEND_JANUARY
 *    EEC_PERDCRESTEND_FEBRUARY
 *    EEC_PERDCRESTEND_MARCH
 *    EEC_PERDCRESTEND_APRIL
 *    EEC_PERDCRESTEND_MAY
 *    EEC_PERDCRESTEND_JUNE
 *    EEC_PERDCRESTEND_JULY
 *    EEC_PERDCRESTEND_AUGUST
 *    EEC_PERDCRESTEND_SEPTEMBER
 *    EEC_PERDCRESTEND_OCTOBER
 *    EEC_PERDCRESTEND_NOVEMBER
 *    EEC_PERDCRESTEND_DECEMBER
 *
 * Group Membership: ABSTRACT_OBJECT, TIME, USAGE_REGION
 */
#define EAC_PERIODIC_RESTRICTION_END ((EDCS_Attribute_Code)958)

/*
 * Definition:
 *     The <<MONTH>> in which restrictions begin on the use of an <OBJECT>
 *     due to climate or other limitations; the periodic restriction start.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PERDCRESTSTRT_JANUARY
 *    EEC_PERDCRESTSTRT_FEBRUARY
 *    EEC_PERDCRESTSTRT_MARCH
 *    EEC_PERDCRESTSTRT_APRIL
 *    EEC_PERDCRESTSTRT_MAY
 *    EEC_PERDCRESTSTRT_JUNE
 *    EEC_PERDCRESTSTRT_JULY
 *    EEC_PERDCRESTSTRT_AUGUST
 *    EEC_PERDCRESTSTRT_SEPTEMBER
 *    EEC_PERDCRESTSTRT_OCTOBER
 *    EEC_PERDCRESTSTRT_NOVEMBER
 *    EEC_PERDCRESTSTRT_DECEMBER
 *
 * Group Membership: ABSTRACT_OBJECT, TIME, USAGE_REGION
 */
#define EAC_PERIODIC_RESTRICTION_START ((EDCS_Attribute_Code)959)

/*
 * Definition:
 *     The type of restriction on the use of an <OBJECT> due to climate or
 *     other limitations; the periodic restriction type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PERDCRESTTY_CLOSED
 *    EEC_PERDCRESTTY_PERMANENT_ICE
 *    EEC_PERDCRESTTY_SUBJECT_TO_ICE
 *    EEC_PERDCRESTTY_PERENNIALLY_OPEN
 *    EEC_PERDCRESTTY_TEMPORARY
 *    EEC_PERDCRESTTY_JANUARY_CLOSED
 *    EEC_PERDCRESTTY_FEBRUARY_CLOSED
 *    EEC_PERDCRESTTY_MARCH_CLOSED
 *    EEC_PERDCRESTTY_APRIL_CLOSED
 *    EEC_PERDCRESTTY_MAY_CLOSED
 *    EEC_PERDCRESTTY_JUNE_CLOSED
 *    EEC_PERDCRESTTY_JULY_CLOSED
 *    EEC_PERDCRESTTY_AUGUST_CLOSED
 *    EEC_PERDCRESTTY_SEPTEMBER_CLOSED
 *    EEC_PERDCRESTTY_OCTOBER_CLOSED
 *    EEC_PERDCRESTTY_NOVEMBER_CLOSED
 *    EEC_PERDCRESTTY_DECEMBER_CLOSED
 *
 * Group Membership: ABSTRACT_OBJECT, USAGE_REGION
 */
#define EAC_PERIODIC_RESTRICTION_TYPE ((EDCS_Attribute_Code)960)

/*
 * Definition:
 *     The start of the active period for a seasonal <OBJECT> (for example: a
 *     <BUOY>). The value is formatted as specified by <<DATE_FORMAT>> or by
 *     <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ABSTRACT_OBJECT, TIME
 */
#define EAC_PERIODIC_START_DATE ((EDCS_Attribute_Code)961)

/*
 * Definition:
 *     An indication that an <OBJECT> is permanent (as opposed to temporary).
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, TIME
 */
#define EAC_PERMANENT ((EDCS_Attribute_Code)962)

/*
 * Definition:
 *     The logarithm of the reciprocal of hydrogen ion concentration in gram
 *     atoms per litre; the pH.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: MATERIAL
 */
#define EAC_PH ((EDCS_Attribute_Code)963)

/*
 * Definition:
 *     An indication that a physical obstruction, stopping or blocking a
 *     <ROUTE>, is present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: TRNSP
 */
#define EAC_PHYSICAL_OBSTRUCTION ((EDCS_Attribute_Code)964)

/*
 * Definition:
 *     The physical state of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PHYSSTATE_BOSE_EINSTEIN_CONDENSATE
 *    EEC_PHYSSTATE_GAS
 *    EEC_PHYSSTATE_LIQUID
 *    EEC_PHYSSTATE_PLASMA
 *    EEC_PHYSSTATE_SOLID
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_PHYSICAL_STATE ((EDCS_Attribute_Code)965)

/*
 * Definition:
 *     Specifies the resource site where a request for a pictorial
 *     representation of an <OBJECT> is available; the pictorial resource
 *     request. The value is formatted in a Basic Latin string as specified
 *     by [URI].
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define EAC_PICTORIAL_RESOURCE_REQUEST ((EDCS_Attribute_Code)966)

/*
 * Definition:
 *     The type of a <PIPELINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PIPELNTY_BUBBLER_SYSTEM
 *    EEC_PIPELNTY_GENERIC
 *    EEC_PIPELNTY_OUTFALL
 *    EEC_PIPELNTY_SEWER
 *    EEC_PIPELNTY_SUPPLY
 *    EEC_PIPELNTY_TRANSPORT
 *    EEC_PIPELNTY_VALVE
 *    EEC_PIPELNTY_WATER_INTAKE
 *    EEC_PIPELNTY_WATER
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_PIPELINE_TYPE ((EDCS_Attribute_Code)967)

/*
 * Definition:
 *     The angular distance about the pitch axis of an <OBJECT> measured in
 *     the local vertical plane from the local horizontal clockwise
 *     (upwards) to the forward axis of the <OBJECT>. The forward axis of
 *     the <OBJECT> is the axis which passes through the <OBJECT> centre and
 *     is directed towards/through the forward part or <SURFACE> (front) of
 *     the <OBJECT>. The pitch axis of the <OBJECT> is normal to the forward
 *     axis in the horizontal plane of the <OBJECT> and forms a two
 *     dimensional right-handed <SYSTEM>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_PITCH_ANGLE ((EDCS_Attribute_Code)968)

/*
 * Definition:
 *     The <<DEW_POINT_DEPRESSION>> 1,25 to 2,0 metres above a
 *     <PLANETARY_SURFACE> at a <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_PLANETARY_SRF_DEW_POINT_DEPRESSION ((EDCS_Attribute_Code)969)

/*
 * Definition:
 *     The <<DEW_POINT_TEMPERATURE>> 1,25 to 2,0 metres above a
 *     <PLANETARY_SURFACE> at a <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_PLANETARY_SRF_DEW_POINT_TEMPERATURE ((EDCS_Attribute_Code)970)

/*
 * Definition:
 *     The <<AIR_TEMPERATURE>> 1,25 to 2,0 metres above a <PLANETARY_SURFACE>
 *     at a <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_PLANETARY_SURFACE_AIR_TEMPERATURE ((EDCS_Attribute_Code)971)

/*
 * Definition:
 *     The <<ATM_PRESSURE>> at a <PLANETARY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_PLANETARY_SURFACE_ATM_PRESSURE ((EDCS_Attribute_Code)972)

/*
 * Definition:
 *     The total solar and lunar contribution to the level of <<ILLUMINANCE>>
 *     at a <PLANETARY_SURFACE> as a function of <LOCATION>, date, time, and
 *     meteorological conditions.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RADIANT_ENERGY_FLUENCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_PLANETARY_SURFACE_ILLUMINANCE_LEVEL ((EDCS_Attribute_Code)973)

/*
 * Definition:
 *     The <<TEMPERATURE>> of a <PLANETARY_SURFACE> at a <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE
 */
#define EAC_PLANETARY_SURFACE_TEMPERATURE ((EDCS_Attribute_Code)974)

/*
 * Definition:
 *     The type of a <COMPONENT> of a <PLANT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PLNTCMPTTY_FOLIAGE
 *    EEC_PLNTCMPTTY_STEM
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define EAC_PLANT_COMPONENT_TYPE ((EDCS_Attribute_Code)975)

/*
 * Definition:
 *     The number of platforms at a <TRANSPORTATION_STATION>; the platform
 *     count.
 *
 * Value Type: COUNT
 *
 * Group Membership: TRNSP
 */
#define EAC_PLATFORM_COUNT ((EDCS_Attribute_Code)976)

/*
 * Definition:
 *     The number of platoons and associated <EQUIPMENT> that an <OBJECT> can
 *     accommodate; the platoon accommodation capacity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, MILITARY_SCIENCE
 */
#define EAC_PLATOON_ACCOMMODATION_CAPACITY ((EDCS_Attribute_Code)977)

/*
 * Definition:
 *     The fraction of breaking <WATER_WAVE>s that are plunging. Plunging
 *     means that the <WATER_WAVE> peaks up until it is an advancing
 *     vertical wall of <WATER>, the crest then curls far over and descends
 *     violently into the preceding trough where the <SURFACE> of the
 *     <WATER> is essentially horizontal; a considerable amount of <AIR> is
 *     trapped in this process and this <AIR> escapes explosively behind the
 *     <WATER_WAVE>, throwing <WATER> high above the <SURFACE> and producing
 *     a loud explosive sound.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_PLUNGING_BREAKER_FRACTION ((EDCS_Attribute_Code)978)

/*
 * Definition:
 *     The general type of a point <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PTOBJTY_AGGREGATE
 *    EEC_PTOBJTY_DESTROYED_STRUCTURE
 *    EEC_PTOBJTY_HORIZONTAL_STRUCTURE
 *    EEC_PTOBJTY_MULTI_ELEVATION_STRUCTURE
 *    EEC_PTOBJTY_SOIL_LOCATION
 *    EEC_PTOBJTY_SPATIAL_LOCATION
 *    EEC_PTOBJTY_TERRAIN_CONFORMAL
 *    EEC_PTOBJTY_VERTICAL_STRUCTURE
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_POINT_OBJECT_TYPE ((EDCS_Attribute_Code)979)

/*
 * Definition:
 *     The ratio of change in length in the direction of applied stress to
 *     change in width that is perpendicular to the direction of applied
 *     stress of a <MATERIAL> when placed under tension; the Poisson ratio.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_POISSON_RATIO ((EDCS_Attribute_Code)980)

/*
 * Definition:
 *     The type of <OBJECT> represented by a <POLYGONAL_FACE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_POLYFACETY_BUILDING
 *    EEC_POLYFACETY_BUILDING_COMPONENT
 *    EEC_POLYFACETY_LAND
 *    EEC_POLYFACETY_TERRAIN
 *    EEC_POLYFACETY_WATER_BODY_FLOOR
 *    EEC_POLYFACETY_WATER_BODY_SURFACE
 *
 * Group Membership: ABSTRACT_OBJECT, ALGORITHM_RELATED
 */
#define EAC_POLYGONAL_FACE_TYPE ((EDCS_Attribute_Code)981)

/*
 * Definition:
 *     The type of a pond.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PONDTY_FISH
 *    EEC_PONDTY_RESERVOIR
 *    EEC_PONDTY_WASTE
 *
 * Group Membership: USAGE_REGION
 */
#define EAC_POND_TYPE ((EDCS_Attribute_Code)982)

/*
 * Definition:
 *     The type of a populated place.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_POPPLCTY_CITY
 *    EEC_POPPLCTY_HAMLET
 *    EEC_POPPLCTY_INLAND_VILLAGE
 *    EEC_POPPLCTY_SETTLEMENT
 *    EEC_POPPLCTY_SHANTY_TOWN
 *    EEC_POPPLCTY_TENT_DWELLINGS
 *    EEC_POPPLCTY_TRADITIONAL_SETTLEMENT
 *    EEC_POPPLCTY_VILLAGE
 *
 * Group Membership: USAGE_REGION
 */
#define EAC_POPULATED_PLACE_TYPE ((EDCS_Attribute_Code)983)

/*
 * Definition:
 *     The number of <HUMAN>s within a delineated <REGION>; the population.
 *
 * Value Type: COUNT
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define EAC_POPULATION ((EDCS_Attribute_Code)984)

/*
 * Definition:
 *     The posture of a <HUMAN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_POSTURE_CRAWLING
 *    EEC_POSTURE_CROUCHING
 *    EEC_POSTURE_DEAD
 *    EEC_POSTURE_DETAINED
 *    EEC_POSTURE_JUMPING
 *    EEC_POSTURE_KNEELING
 *    EEC_POSTURE_KNEELING_FIRING
 *    EEC_POSTURE_PARACHUTING
 *    EEC_POSTURE_PRONE
 *    EEC_POSTURE_PRONE_FIRING
 *    EEC_POSTURE_SITTING
 *    EEC_POSTURE_SQUATTING
 *    EEC_POSTURE_SURRENDERING
 *    EEC_POSTURE_SWIMMING
 *    EEC_POSTURE_UPRIGHT_FIRING
 *    EEC_POSTURE_UPRIGHT_RUNNING
 *    EEC_POSTURE_UPRIGHT_STANDING_STILL
 *    EEC_POSTURE_UPRIGHT_WALKING
 *    EEC_POSTURE_WADING
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define EAC_POSTURE ((EDCS_Attribute_Code)985)

/*
 * Definition:
 *     The <<AIR_TEMPERATURE>> that a parcel of dry <AIR> would have, if
 *     brought adiabatically from its initial state to the standard pressure
 *     of 100 kilopascals (1 000 millibars); the potential air temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_POTENTIAL_AIR_TEMPERATURE ((EDCS_Attribute_Code)986)

/*
 * Definition:
 *     The electrical power generating capacity of an <OBJECT>; the power
 *     generating capacity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER
 *
 * Group Membership: ABSTRACT_OBJECT, EM_PHENOMENON, INFRASTRUCTURE
 */
#define EAC_POWER_GENERATING_CAPACITY ((EDCS_Attribute_Code)987)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional power generation of an <OBJECT> with the associated noise
 *     and heat. Zero means none at all and one means maximum.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, EM_PHENOMENON, INFRASTRUCTURE, RATE_OR_RATIO
 */
#define EAC_POWER_GENERATION_RATE ((EDCS_Attribute_Code)988)

/*
 * Definition:
 *     The technology used by a <POWER_PLANT> to produce electricity.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PWRPLNTTY_HYDRO_ELECTRIC
 *    EEC_PWRPLNTTY_INTERNAL_COMBUSTION
 *    EEC_PWRPLNTTY_NUCLEAR
 *    EEC_PWRPLNTTY_SOLAR
 *    EEC_PWRPLNTTY_THERMAL
 *    EEC_PWRPLNTTY_TIDAL
 *    EEC_PWRPLNTTY_WIND
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, USAGE_REGION
 */
#define EAC_POWER_PLANT_TYPE ((EDCS_Attribute_Code)989)

/*
 * Definition:
 *     A measure of the <<MASS>> of dissolved <MATERIAL> in seawater as
 *     determined by the <<OCEAN_ELECTRICAL_CONDUCTIVITY_RATIO>> at a
 *     <<TEMPERATURE>> of 288,15 kelvin (15 degrees Celsius) and the
 *     pressure of one standard atmosphere; practical salinity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_PRACTICAL_SALINITY ((EDCS_Attribute_Code)990)

/*
 * Definition:
 *     The total water vapour contained in a vertical column of unit
 *     cross-sectional <<AREA>> extending between two <<HEIGHT_AGL>>s of an
 *     <ATMOSPHERE>; the precipitable water.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_PRECIPITABLE_WATER ((EDCS_Attribute_Code)991)

/*
 * Definition:
 *     The total <<PRECIPITABLE_WATER>> contained in a column of unit cross
 *     section extending from the <PLANETARY_SURFACE> to the top of the
 *     <ATMOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_PRECIPITABLE_WATER_TOTAL ((EDCS_Attribute_Code)992)

/*
 * Definition:
 *     The intensity of <PRECIPITATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRECIPINT_NO_PRECIPITATION_PRESENT
 *    EEC_PRECIPINT_LIGHT
 *    EEC_PRECIPINT_MODERATE
 *    EEC_PRECIPINT_HEAVY
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_PRECIPITATION_INTENSITY ((EDCS_Attribute_Code)993)

/*
 * Definition:
 *     The power level of acoustic noise energy in a <WATERBODY> due to
 *     <PRECIPITATION> onto the <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, ATMOSPHERE, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_PRECIPITATION_NOISE_POWER_LEVEL ((EDCS_Attribute_Code)994)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> prior to the referenced time over which
 *     <PRECIPITATION> accumulated.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: ATMOSPHERE, TIME
 */
#define EAC_PRECIPITATION_PERIOD ((EDCS_Attribute_Code)995)

/*
 * Definition:
 *     The state (liquid/solid disposition) of precipitable <WATER>; the
 *     precipitation phase.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRECIPPHAS_LIQUID
 *    EEC_PRECIPPHAS_MIXED
 *    EEC_PRECIPPHAS_SOLID
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_PRECIPITATION_PHASE ((EDCS_Attribute_Code)996)

/*
 * Definition:
 *     The rate of <PRECIPITATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_PRECIPITATION_RATE ((EDCS_Attribute_Code)997)

/*
 * Definition:
 *     The type of <PRECIPITATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRECIPTY_DIAMOND_DUST
 *    EEC_PRECIPTY_DRIZZLE
 *    EEC_PRECIPTY_FREEZING_DRIZZLE
 *    EEC_PRECIPTY_FREEZING_RAIN
 *    EEC_PRECIPTY_GRAUPEL
 *    EEC_PRECIPTY_HAIL
 *    EEC_PRECIPTY_ICE_CRYSTALS
 *    EEC_PRECIPTY_ICE_PELLETS
 *    EEC_PRECIPTY_LIQUID_PRECIP_FREEZING
 *    EEC_PRECIPTY_LIQUID_PRECIP_NOT_FREEZING
 *    EEC_PRECIPTY_NO_PRECIP
 *    EEC_PRECIPTY_PRECIP
 *    EEC_PRECIPTY_RAIN
 *    EEC_PRECIPTY_RAIN_AND_DRIZZLE
 *    EEC_PRECIPTY_RAIN_AND_HAIL
 *    EEC_PRECIPTY_RAIN_AND_SNOW
 *    EEC_PRECIPTY_SLEET
 *    EEC_PRECIPTY_SMALL_HAIL
 *    EEC_PRECIPTY_SNOW
 *    EEC_PRECIPTY_SNOW_GRAINS
 *    EEC_PRECIPTY_SNOW_PELLETS
 *    EEC_PRECIPTY_SOLID_PRECIP
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_PRECIPITATION_TYPE ((EDCS_Attribute_Code)998)

/*
 * Definition:
 *     The predominant (greater than 50 percent) <<DEPTH>> within the
 *     <REGION> delineated by an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_PREDOMINANT_DEPTH_WITHIN_OBJECT ((EDCS_Attribute_Code)999)

/*
 * Definition:
 *     The predominant (greater than 50 percent) <<HEIGHT_AGL>> of an
 *     <OBJECT>. If not obtainable, then the mean <<HEIGHT_AGL>> of the
 *     <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_PREDOMINANT_HEIGHT ((EDCS_Attribute_Code)1000)

/*
 * Definition:
 *     The predominant (greater than 50 percent) height within the <REGION>
 *     delineated by an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_PREDOMINANT_HEIGHT_WITHIN_OBJECT ((EDCS_Attribute_Code)1001)

/*
 * Definition:
 *     The predominant type of other <OBJECT>s within a <<RADIUS>> of 457
 *     metres (1 500 feet) of an <OBJECT> of interest.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PREDSURNDTY_OPEN_TERRAIN
 *    EEC_PREDSURNDTY_STRUCTURES
 *    EEC_PREDSURNDTY_TREES
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_PREDOMINANT_SURROUND_TYPE ((EDCS_Attribute_Code)1002)

/*
 * Definition:
 *     The predominant (greater than 50 percent) <<HEIGHT_AGL>> of
 *     <VEGETATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define EAC_PREDOMINANT_VEGETATION_HEIGHT ((EDCS_Attribute_Code)1003)

/*
 * Definition:
 *     The predominant (greater than 50 percent) <<WATER_DEPTH>> determined
 *     at the greatest depth along a cross section of the <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_PREDOMINANT_WATER_DEPTH ((EDCS_Attribute_Code)1004)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the extent to which an <OBJECT> has been prepared for
 *     destruction by <EXPLOSIVE_CHARGE>s. Zero means no preparation at all
 *     and one means completely prepared.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_PREPARED_EXPLOSIVE_DESTRUCTION_COMPLETION_FRACTION ((EDCS_Attribute_Code)1005)

/*
 * Definition:
 *     The type of weather existing at an automated <WEATHER_STATION> at the
 *     time of observation.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRSNTWXTYAUT_BLOWING_DRFT_SNOW_SAND
 *    EEC_PRSNTWXTYAUT_CLD_DISSOLVING
 *    EEC_PRSNTWXTYAUT_CLD_FORMING
 *    EEC_PRSNTWXTYAUT_DIAMOND_DUST
 *    EEC_PRSNTWXTYAUT_DISTANT_LIGHTNING
 *    EEC_PRSNTWXTYAUT_DRZL
 *    EEC_PRSNTWXTYAUT_DRZL_NF_PREV_HOUR
 *    EEC_PRSNTWXTYAUT_FOG_NO_CHG
 *    EEC_PRSNTWXTYAUT_FOG_PATCHES
 *    EEC_PRSNTWXTYAUT_FOG_PRESENT
 *    EEC_PRSNTWXTYAUT_FOG_PREVIOUS_HOUR
 *    EEC_PRSNTWXTYAUT_FOG_RIME
 *    EEC_PRSNTWXTYAUT_FOG_THICK
 *    EEC_PRSNTWXTYAUT_FOG_THIN
 *    EEC_PRSNTWXTYAUT_FRZ_RAIN_DRZL_PREV
 *    EEC_PRSNTWXTYAUT_HAZE_VISIB_lt_1r0_KM
 *    EEC_PRSNTWXTYAUT_HAZE_VISIB_gt_1r0_KM
 *    EEC_PRSNTWXTYAUT_HVY_DRZL_FRZ
 *    EEC_PRSNTWXTYAUT_HVY_DRZL_NF
 *    EEC_PRSNTWXTYAUT_HVY_ICE_PLLT
 *    EEC_PRSNTWXTYAUT_HVY_LQD_PRECIP
 *    EEC_PRSNTWXTYAUT_HVY_PRECIP
 *    EEC_PRSNTWXTYAUT_HVY_RAIN_FRZ
 *    EEC_PRSNTWXTYAUT_HVY_RAIN_NF
 *    EEC_PRSNTWXTYAUT_HVY_RAIN_SHOWERS
 *    EEC_PRSNTWXTYAUT_HVY_SNOW
 *    EEC_PRSNTWXTYAUT_HVY_SNOW_SHOWERS
 *    EEC_PRSNTWXTYAUT_HVY_SOLID_PRECIP
 *    EEC_PRSNTWXTYAUT_HVY_THND_HAIL
 *    EEC_PRSNTWXTYAUT_HVY_THND_NO_PRECIP
 *    EEC_PRSNTWXTYAUT_HVY_THND_PRECIP
 *    EEC_PRSNTWXTYAUT_MIST
 *    EEC_PRSNTWXTYAUT_MOD_DRZL_FRZ
 *    EEC_PRSNTWXTYAUT_MOD_DRZL_NF
 *    EEC_PRSNTWXTYAUT_MOD_FRZ_PRECIP
 *    EEC_PRSNTWXTYAUT_MOD_HVY_RAIN_DRZL
 *    EEC_PRSNTWXTYAUT_MOD_HVY_RAIN_SNOW
 *    EEC_PRSNTWXTYAUT_MOD_ICE_PLLT
 *    EEC_PRSNTWXTYAUT_MOD_RAIN_FRZ
 *    EEC_PRSNTWXTYAUT_MOD_RAIN_NF
 *    EEC_PRSNTWXTYAUT_MOD_RAIN_SHOWERS
 *    EEC_PRSNTWXTYAUT_MOD_SNOW
 *    EEC_PRSNTWXTYAUT_MOD_SNOW_SHOWERS
 *    EEC_PRSNTWXTYAUT_NO_SIG_WEATHER
 *    EEC_PRSNTWXTYAUT_PRECIP
 *    EEC_PRSNTWXTYAUT_PRECIP_PREV_HOUR
 *    EEC_PRSNTWXTYAUT_RAIN
 *    EEC_PRSNTWXTYAUT_RAIN_NF_PREV_HOUR
 *    EEC_PRSNTWXTYAUT_SHOWERS
 *    EEC_PRSNTWXTYAUT_SKY_UNCHANGED
 *    EEC_PRSNTWXTYAUT_SL_DRZL_FRZ
 *    EEC_PRSNTWXTYAUT_SL_DRZL_NF
 *    EEC_PRSNTWXTYAUT_SL_ICE_PLLT
 *    EEC_PRSNTWXTYAUT_SL_MOD_FRZ_PRECIP
 *    EEC_PRSNTWXTYAUT_SL_MOD_LQD_PRECIP
 *    EEC_PRSNTWXTYAUT_SL_MOD_SOLID_PRECIP
 *    EEC_PRSNTWXTYAUT_SL_MOD_THND_HAIL
 *    EEC_PRSNTWXTYAUT_SL_MOD_THND_NO_PRECIP
 *    EEC_PRSNTWXTYAUT_SL_MOD_THND_PRECIP
 *    EEC_PRSNTWXTYAUT_SL_PRECIP
 *    EEC_PRSNTWXTYAUT_SL_RAIN_DRZL
 *    EEC_PRSNTWXTYAUT_SL_RAIN_FRZ
 *    EEC_PRSNTWXTYAUT_SL_RAIN_NF
 *    EEC_PRSNTWXTYAUT_SL_RAIN_SHOWERS
 *    EEC_PRSNTWXTYAUT_SL_RAIN_SNOW
 *    EEC_PRSNTWXTYAUT_SL_SNOW
 *    EEC_PRSNTWXTYAUT_SL_SNOW_SHOWERS
 *    EEC_PRSNTWXTYAUT_SNOW
 *    EEC_PRSNTWXTYAUT_SNOW_PREV_HOUR
 *    EEC_PRSNTWXTYAUT_SQUALLS
 *    EEC_PRSNTWXTYAUT_THND
 *    EEC_PRSNTWXTYAUT_THND_PREV_HOUR
 *    EEC_PRSNTWXTYAUT_TORNADO
 *    EEC_PRSNTWXTYAUT_VIOLENT_RAIN_SHOWERS
 *    EEC_PRSNTWXTYAUT_VISIB_lt_1r0_KM_BLOWING_DRFT_SNOW_SAND
 *    EEC_PRSNTWXTYAUT_VISIB_gt_1r0_KM_BLOWING_DRFT_SNOW_SAND
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_PRESENT_WEATHER_TYPE_AUTOMATED ((EDCS_Attribute_Code)1006)

/*
 * Definition:
 *     The type of weather existing at a manual <WEATHER_STATION> at the time
 *     of observation.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRSNTWXTYMAN_BLOWING_SNOW_HVY
 *    EEC_PRSNTWXTYMAN_BLOWING_SNOW_SL_OR_MOD
 *    EEC_PRSNTWXTYMAN_CLD_DISSOLVING_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_CLD_FORMING_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_DIAMOND_DUST
 *    EEC_PRSNTWXTYMAN_DRFT_SNOW_HVY
 *    EEC_PRSNTWXTYMAN_DRFT_SNOW_SL_OR_MOD
 *    EEC_PRSNTWXTYMAN_DRZL_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_DUST_IN_SUSPENSION_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_DUST_OR_SAND_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_DUST_OR_SAND_STORM_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_DUST_OR_SAND_WHIRLS_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_FOG_CONTINUOUS_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_FOG_NOT_AT_STATION
 *    EEC_PRSNTWXTYMAN_FOG_PATCHES
 *    EEC_PRSNTWXTYMAN_FOG_PATCHES_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_FOG_OR_ICE_FOG_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_FOG_NO_CHG_INVIS_SKY
 *    EEC_PRSNTWXTYMAN_FOG_RIME_INVIS_SKY
 *    EEC_PRSNTWXTYMAN_FOG_THICK_INVIS_SKY
 *    EEC_PRSNTWXTYMAN_FOG_THIN_INVIS_SKY
 *    EEC_PRSNTWXTYMAN_FOG_NO_CHG_VIS_SKY
 *    EEC_PRSNTWXTYMAN_FOG_RIME_VIS_SKY
 *    EEC_PRSNTWXTYMAN_FOG_THICK_VIS_SKY
 *    EEC_PRSNTWXTYMAN_FOG_THIN_VIS_SKY
 *    EEC_PRSNTWXTYMAN_FRZ_RAIN_DRZL_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_FUNNEL_CLD_PREV_HOUR_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_HAIL_OR_RAIN_SHOWERS_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_HAZE_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_HVY_DRZL_NF_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_HVY_DRZL_NF_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_HVY_RAIN_NF_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_HVY_RAIN_NF_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_HVY_SNFLK_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_HVY_SNFLK_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_HVY_THND_HAIL
 *    EEC_PRSNTWXTYMAN_HVY_THND_NO_HAIL
 *    EEC_PRSNTWXTYMAN_ICE_PLLT
 *    EEC_PRSNTWXTYMAN_LIGHTNING_VISIBLE_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_MIST_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_MOD_DRZL_NF_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_MOD_DRZL_NF_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_MOD_HVY_DRZL_AND_RAIN
 *    EEC_PRSNTWXTYMAN_MOD_HVY_FRZ_DRZL
 *    EEC_PRSNTWXTYMAN_MOD_HVY_FRZ_RAIN
 *    EEC_PRSNTWXTYMAN_MOD_HVY_HAIL_SHOWERS
 *    EEC_PRSNTWXTYMAN_MOD_HVY_RAIN
 *    EEC_PRSNTWXTYMAN_MOD_HVY_RAIN_DRZL_SNOW
 *    EEC_PRSNTWXTYMAN_MOD_HVY_RAIN_SHOWER
 *    EEC_PRSNTWXTYMAN_MOD_HVY_MIXED_RAIN_SNOW
 *    EEC_PRSNTWXTYMAN_MOD_HVY_SNOW_MIXED
 *    EEC_PRSNTWXTYMAN_MOD_HVY_SNOW_PLLT_SHOWER
 *    EEC_PRSNTWXTYMAN_MOD_HVY_SNOW_SHOWER
 *    EEC_PRSNTWXTYMAN_MOD_RAIN_NF_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_MOD_RAIN_NF_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_MOD_SNFLK_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_MOD_SNFLK_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_NO_CLD_DEVL_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_PRECIP_NEAR_STATION
 *    EEC_PRSNTWXTYMAN_PRECIP_gt_5r0_KM
 *    EEC_PRSNTWXTYMAN_PRECIP_NOT_SURFACE
 *    EEC_PRSNTWXTYMAN_RAIN_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_RAIN_SHOWERS_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_RAIN_SNOW_ICE_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_SKY_UNCHANGED_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_SL_DRZL_AND_RAIN
 *    EEC_PRSNTWXTYMAN_SL_DRZL_NF_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_SL_DRZL_NF_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_SL_FRZ_DRZL
 *    EEC_PRSNTWXTYMAN_SL_FRZ_RAIN
 *    EEC_PRSNTWXTYMAN_SL_HAIL_SHOWERS
 *    EEC_PRSNTWXTYMAN_SL_MOD_DSSS_DEC
 *    EEC_PRSNTWXTYMAN_SL_MOD_DSSS_INC
 *    EEC_PRSNTWXTYMAN_SL_MOD_DSSS_NO_CHG
 *    EEC_PRSNTWXTYMAN_SL_MOD_THND_HAIL
 *    EEC_PRSNTWXTYMAN_SL_MOD_THND_NO_HAIL
 *    EEC_PRSNTWXTYMAN_SL_RAIN
 *    EEC_PRSNTWXTYMAN_SL_RAIN_NF_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_SL_RAIN_NF_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_SL_RAIN_SHOWER
 *    EEC_PRSNTWXTYMAN_SL_RAIN_SNOW_DRZL
 *    EEC_PRSNTWXTYMAN_SL_RAIN_SNOW_MIXED
 *    EEC_PRSNTWXTYMAN_SL_SNOW_MIXED
 *    EEC_PRSNTWXTYMAN_SL_SNOW_PLLT_SHOWER
 *    EEC_PRSNTWXTYMAN_SL_SNOW_SHOWER
 *    EEC_PRSNTWXTYMAN_SL_SNFLK_CONTINUOUS
 *    EEC_PRSNTWXTYMAN_SL_SNFLK_INTERMITTENT
 *    EEC_PRSNTWXTYMAN_SNOW_GRAINS
 *    EEC_PRSNTWXTYMAN_SNOW_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_SNOW_RAIN_SHOWER_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_SQUALLS_IN_SIGHT_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_STAR_SNOW_CRYSTALS
 *    EEC_PRSNTWXTYMAN_SVR_DSSS_DEC
 *    EEC_PRSNTWXTYMAN_SVR_DSSS_INC
 *    EEC_PRSNTWXTYMAN_SVR_DSSS_NO_CHG
 *    EEC_PRSNTWXTYMAN_THND_NO_PRECIP
 *    EEC_PRSNTWXTYMAN_THND_PREV_HOUR
 *    EEC_PRSNTWXTYMAN_THND_SAND_DUST
 *    EEC_PRSNTWXTYMAN_VIOLENT_RAIN_SHOWER
 *    EEC_PRSNTWXTYMAN_VIS_REDUCED_BY_SMOKE_NO_PRECIP
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_PRESENT_WEATHER_TYPE_MANUAL ((EDCS_Attribute_Code)1007)

/*
 * Definition:
 *     The type of a special weather event or observation.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRSNTWXTYSPCL_ARCTIC_ANTARCTIC_SEA_SMOKE
 *    EEC_PRSNTWXTYSPCL_BLOWING_SNOW_INDETERMINATE
 *    EEC_PRSNTWXTYSPCL_BLOWING_SPRAY
 *    EEC_PRSNTWXTYSPCL_CLEAR_SKY_SNOW_OR_ICE_PRECIP
 *    EEC_PRSNTWXTYSPCL_DENSE_FOG_lt_30_METRE_VISIB
 *    EEC_PRSNTWXTYSPCL_DENSE_FOG_30_60_METRE_VISIB
 *    EEC_PRSNTWXTYSPCL_DENSE_FOG_60_90_METRE_VISIB
 *    EEC_PRSNTWXTYSPCL_DEW_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_DRFT_DUST_OR_SAND
 *    EEC_PRSNTWXTYSPCL_DRZL_lt_0r1_MMPH
 *    EEC_PRSNTWXTYSPCL_DRZL_0r1_TO_0r19_MMPH
 *    EEC_PRSNTWXTYSPCL_DRZL_0r2_TO_0r39_MMPH
 *    EEC_PRSNTWXTYSPCL_DRZL_0r4_TO_0r79_MMPH
 *    EEC_PRSNTWXTYSPCL_DRZL_0r8_TO_1r59_MMPH
 *    EEC_PRSNTWXTYSPCL_DRZL_1r6_TO_3r19_MMPH
 *    EEC_PRSNTWXTYSPCL_DRZL_3r20_TO_6r39_MMPH
 *    EEC_PRSNTWXTYSPCL_DRZL_gt_6r4_MMPH
 *    EEC_PRSNTWXTYSPCL_DRZL_AND_SNOW
 *    EEC_PRSNTWXTYSPCL_DRY_THUNDERSTORM
 *    EEC_PRSNTWXTYSPCL_DUST_HAZE_VISIB_lt_1r0_KM
 *    EEC_PRSNTWXTYSPCL_DUST_OR_SAND_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_FOG_IN_VALLEYS
 *    EEC_PRSNTWXTYSPCL_FOG_ON_SEA
 *    EEC_PRSNTWXTYSPCL_FOG_OVER_ICE
 *    EEC_PRSNTWXTYSPCL_FREEZING_RAIN
 *    EEC_PRSNTWXTYSPCL_HAIL
 *    EEC_PRSNTWXTYSPCL_HAIL_RAIN_SNOW
 *    EEC_PRSNTWXTYSPCL_HAIL_RAIN
 *    EEC_PRSNTWXTYSPCL_HAIL_SNOW
 *    EEC_PRSNTWXTYSPCL_HARD_RIME_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_HOAR_FROST_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_ICE_CRUST_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_ICE_GLAZE_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_LIGHTNING_CLOUD_TO_SURFACE
 *    EEC_PRSNTWXTYSPCL_MISSING_BUT_EXPECTED
 *    EEC_PRSNTWXTYSPCL_NO_OBSERVATION
 *    EEC_PRSNTWXTYSPCL_NO_SIGNIF_PHENOMENON
 *    EEC_PRSNTWXTYSPCL_RAIN
 *    EEC_PRSNTWXTYSPCL_RAIN_lt_1r0_MMPH
 *    EEC_PRSNTWXTYSPCL_RAIN_1r0_TO_1r19_MMPH
 *    EEC_PRSNTWXTYSPCL_RAIN_2r0_TO_3r9_MMPH
 *    EEC_PRSNTWXTYSPCL_RAIN_4r0_TO_7r9_MMPH
 *    EEC_PRSNTWXTYSPCL_RAIN_8r0_TO_15r9_MMPH
 *    EEC_PRSNTWXTYSPCL_RAIN_16r0_TO_31r9_MMPH
 *    EEC_PRSNTWXTYSPCL_RAIN_32r0_TO_63r9_MMPH
 *    EEC_PRSNTWXTYSPCL_RAIN_gt_64r0_MMPH
 *    EEC_PRSNTWXTYSPCL_RAIN_SNOW_MIXED
 *    EEC_PRSNTWXTYSPCL_SHWR_OVER_MOUNTAINS
 *    EEC_PRSNTWXTYSPCL_SHWR_OVER_SEA
 *    EEC_PRSNTWXTYSPCL_SNOW
 *    EEC_PRSNTWXTYSPCL_SNOW_lt_1r0_CMPH
 *    EEC_PRSNTWXTYSPCL_SNOW_1r0_TO_1r9_CMPH
 *    EEC_PRSNTWXTYSPCL_SNOW_2r0_TO_3r9_CMPH
 *    EEC_PRSNTWXTYSPCL_SNOW_4r0_TO_7r9_CMPH
 *    EEC_PRSNTWXTYSPCL_SNOW_8r0_TO_15r9_CMPH
 *    EEC_PRSNTWXTYSPCL_SNOW_16r0_TO_31r9_CMPH
 *    EEC_PRSNTWXTYSPCL_SNOW_32r0_TO_63r9_CMPH
 *    EEC_PRSNTWXTYSPCL_SNOW_gt_64r0_CMPH
 *    EEC_PRSNTWXTYSPCL_SNOW_HAZE
 *    EEC_PRSNTWXTYSPCL_SNOW_PLLT
 *    EEC_PRSNTWXTYSPCL_SNOW_PLLT_MIXED_RAIN_SNOW
 *    EEC_PRSNTWXTYSPCL_SNOW_PLLT_RAIN
 *    EEC_PRSNTWXTYSPCL_SNOW_PLLT_SNOW
 *    EEC_PRSNTWXTYSPCL_SOFT_RIME_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_STEAM_FOG_LAND
 *    EEC_PRSNTWXTYSPCL_STEAM_FOG_WATER
 *    EEC_PRSNTWXTYSPCL_SUB_0_DUSTSTORM_SANDSTORM
 *    EEC_PRSNTWXTYSPCL_SUSPENDED_VOLCANIC_ASH
 *    EEC_PRSNTWXTYSPCL_TORNADO
 *    EEC_PRSNTWXTYSPCL_VOLCANIC_ASH_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_WALL_DUST_SAND
 *    EEC_PRSNTWXTYSPCL_WET_SNOW_DEPOSITION
 *    EEC_PRSNTWXTYSPCL_WET_SNOW_FREEZING
 *    EEC_PRSNTWXTYSPCL_WHITEOUT
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_PRESENT_WEATHER_TYPE_SPECIAL ((EDCS_Attribute_Code)1008)

/*
 * Definition:
 *     The quality of a <<PRESSURE_ALTIMETER_SETTING>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRESALTQUAL_GOOD
 *    EEC_PRESALTQUAL_NO_CHECK
 *    EEC_PRESALTQUAL_SUSPECT
 *    EEC_PRESALTQUAL_ERR_CORRECTED
 *    EEC_PRESALTQUAL_ERR_CORRECTION_SUSPECT
 *    EEC_PRESALTQUAL_ERR
 *    EEC_PRESALTQUAL_MISS_SUBST
 *    EEC_PRESALTQUAL_MISS_SUBST_SUSPECT
 *    EEC_PRESALTQUAL_MISS
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_PRESSURE_ALTIMETER_QUALITY ((EDCS_Attribute_Code)1009)

/*
 * Definition:
 *     The value of the <<ATM_PRESSURE>> used to adjust the subscale of a
 *     pressure altimeter so that it indicates the vertical distance of an
 *     <AIRCRAFT> above a known <<ATM_VERTICAL_REFERENCE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_PRESSURE_ALTIMETER_SETTING ((EDCS_Attribute_Code)1010)

/*
 * Definition:
 *     The altitude that corresponds to a given <FLIGHT_LEVEL>; the pressure
 *     altitude.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_PRESSURE_ALTITUDE ((EDCS_Attribute_Code)1011)

/*
 * Definition:
 *     A category describing the <<PRI_WEAPON_DEPLOYED_POSITION>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRIWEAPPOSCAT_DEPLOYED
 *    EEC_PRIWEAPPOSCAT_IN_FIRING_POSITION
 *    EEC_PRIWEAPPOSCAT_NO_WEAPON_PRESENT
 *    EEC_PRIWEAPPOSCAT_STOWED
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_PRI_WEAPON_DEPLOYED_POS_CATEGORY ((EDCS_Attribute_Code)1012)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional deployment of the primary <WEAPON_SYSTEM> of an <OBJECT>.
 *     Zero means fully stowed/retracted and one means fully deployed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: MILITARY_SCIENCE, RATE_OR_RATIO
 */
#define EAC_PRI_WEAPON_DEPLOYED_POSITION ((EDCS_Attribute_Code)1013)

/*
 * Definition:
 *     An indication that an <OBJECT> is primary.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_PRIMARY ((EDCS_Attribute_Code)1014)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional deployment of the primary <AERIAL> on an <OBJECT>. Zero
 *     means fully stowed/retracted and one means fully deployed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, INFRASTRUCTURE, RATE_OR_RATIO
 */
#define EAC_PRIMARY_AERIAL_DEPLOYED_POSITION ((EDCS_Attribute_Code)1015)

/*
 * Definition:
 *     The <<VELOCITY>> component of an <OBJECT> along the primary axis of a
 *     defined spatial reference frame.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_PRIMARY_AXIS_VELOCITY_COMPONENT ((EDCS_Attribute_Code)1016)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_GEODETIC>> of a <LINE> drawn perpendicular to the
 *     <DIRECTION> of propagation of primary breaking <WATER_WAVE>s in the
 *     wave spectra of a <SURF_ZONE>; the primary breaker azimuth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_PRIMARY_BREAKER_AZIMUTH ((EDCS_Attribute_Code)1017)

/*
 * Definition:
 *     The horizontal angle the primary breaking <WATER_WAVE>s make with
 *     respect to the <BEACH>. The angle varies from zero when the <LINE> of
 *     the <WATER_WAVE>s parallels the <BEACH> to 90 arc degrees on either
 *     the right or left flank as seen from <VESSEL>s approaching the
 *     <BEACH>; the primary breaker relative angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_PRIMARY_BREAKER_RELATIVE_ANGLE ((EDCS_Attribute_Code)1018)

/*
 * Definition:
 *     The designated primary broadcast <<FREQUENCY>> for a communications
 *     <DEVICE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define EAC_PRIMARY_BROADCAST_FREQUENCY ((EDCS_Attribute_Code)1019)

/*
 * Definition:
 *     The primary by-product of a production, mining, or agricultural
 *     activity.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRIBYPROD_ASH
 *    EEC_PRIBYPROD_CINDER
 *    EEC_PRIBYPROD_ERODED_LAND
 *    EEC_PRIBYPROD_MATTE
 *    EEC_PRIBYPROD_MUD
 *    EEC_PRIBYPROD_NO_BYPRODUCT
 *    EEC_PRIBYPROD_RADIOACTIVE_MATERIAL
 *    EEC_PRIBYPROD_REFUSE
 *    EEC_PRIBYPROD_RUBBLE
 *    EEC_PRIBYPROD_SAWDUST
 *    EEC_PRIBYPROD_SAWDUST_WOODCHIP
 *    EEC_PRIBYPROD_SCRAP_METAL
 *    EEC_PRIBYPROD_SEWAGE
 *    EEC_PRIBYPROD_SILT
 *    EEC_PRIBYPROD_SLAG
 *    EEC_PRIBYPROD_SLUDGE
 *    EEC_PRIBYPROD_TAILINGS
 *    EEC_PRIBYPROD_WASTE
 *    EEC_PRIBYPROD_WOODCHIP
 *
 * Group Membership: AGRICULTURE, INDUSTRY
 */
#define EAC_PRIMARY_BYPRODUCT ((EDCS_Attribute_Code)1020)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional opening of the primary <DOOR> of an <OBJECT>. Zero means
 *     fully closed and one means fully open.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_PRIMARY_DOOR_OPEN_POSITION ((EDCS_Attribute_Code)1021)

/*
 * Definition:
 *     The <LOCATION> of the primary (general) <STRUCTURE_ENTRANCE> as
 *     observed from outside the <STRUCTURE> looking towards its front.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRIENTLOC_BACK_CENTRE_ABOVE_GRADE
 *    EEC_PRIENTLOC_BACK_CENTRE_BELOW_GRADE
 *    EEC_PRIENTLOC_BACK_CENTRE_ON_GRADE
 *    EEC_PRIENTLOC_BACK_LEFT_ABOVE_GRADE
 *    EEC_PRIENTLOC_BACK_LEFT_BELOW_GRADE
 *    EEC_PRIENTLOC_BACK_LEFT_ON_GRADE
 *    EEC_PRIENTLOC_BACK_RIGHT_ABOVE_GRADE
 *    EEC_PRIENTLOC_BACK_RIGHT_BELOW_GRADE
 *    EEC_PRIENTLOC_BACK_RIGHT_ON_GRADE
 *    EEC_PRIENTLOC_FRONT_CENTRE_ABOVE_GRADE
 *    EEC_PRIENTLOC_FRONT_CENTRE_BELOW_GRADE
 *    EEC_PRIENTLOC_FRONT_CENTRE_ON_GRADE
 *    EEC_PRIENTLOC_FRONT_LEFT_ABOVE_GRADE
 *    EEC_PRIENTLOC_FRONT_LEFT_BELOW_GRADE
 *    EEC_PRIENTLOC_FRONT_LEFT_ON_GRADE
 *    EEC_PRIENTLOC_FRONT_RIGHT_ABOVE_GRADE
 *    EEC_PRIENTLOC_FRONT_RIGHT_BELOW_GRADE
 *    EEC_PRIENTLOC_FRONT_RIGHT_ON_GRADE
 *    EEC_PRIENTLOC_LEFT_SIDE_ABOVE_GRADE
 *    EEC_PRIENTLOC_LEFT_SIDE_BELOW_GRADE
 *    EEC_PRIENTLOC_LEFT_SIDE_ON_GRADE
 *    EEC_PRIENTLOC_RIGHT_SIDE_ABOVE_GRADE
 *    EEC_PRIENTLOC_RIGHT_SIDE_BELOW_GRADE
 *    EEC_PRIENTLOC_RIGHT_SIDE_ON_GRADE
 *    EEC_PRIENTLOC_UNKNOWN_LOCATION
 *
 * Group Membership: LOCATION, SUPPORT_STRUCTURE
 */
#define EAC_PRIMARY_ENTRANCE_LOCATION ((EDCS_Attribute_Code)1022)

/*
 * Definition:
 *     The type of primary <MATERIAL> of which an <OBJECT> is composed.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRIMATTY_ALUMINUM
 *    EEC_PRIMATTY_AMMUNITION
 *    EEC_PRIMATTY_ASH
 *    EEC_PRIMATTY_ASPHALT
 *    EEC_PRIMATTY_BASALT
 *    EEC_PRIMATTY_BEDROCK
 *    EEC_PRIMATTY_BLACK_BODY
 *    EEC_PRIMATTY_BOULDER
 *    EEC_PRIMATTY_BRICK
 *    EEC_PRIMATTY_BROADLEAF_TREES_SUMMER
 *    EEC_PRIMATTY_BROADLEAF_TREES_WINTER
 *    EEC_PRIMATTY_CALCAREOUS
 *    EEC_PRIMATTY_CEMENT
 *    EEC_PRIMATTY_CHALK
 *    EEC_PRIMATTY_CHEMICAL
 *    EEC_PRIMATTY_CINDER
 *    EEC_PRIMATTY_CIRRIPEDIA
 *    EEC_PRIMATTY_CLAY
 *    EEC_PRIMATTY_CLAY_TILE
 *    EEC_PRIMATTY_COAL
 *    EEC_PRIMATTY_COBBLE
 *    EEC_PRIMATTY_COKE
 *    EEC_PRIMATTY_COMPOSITION
 *    EEC_PRIMATTY_CONCRETE
 *    EEC_PRIMATTY_CONGLOMERATE
 *    EEC_PRIMATTY_COPPER
 *    EEC_PRIMATTY_CORAL
 *    EEC_PRIMATTY_CORAL_HEAD
 *    EEC_PRIMATTY_DESALINATED_WATER
 *    EEC_PRIMATTY_DIAMOND
 *    EEC_PRIMATTY_DIATOMACEOUS_EARTH
 *    EEC_PRIMATTY_DIORITE
 *    EEC_PRIMATTY_DOLOMITE
 *    EEC_PRIMATTY_DRY_SNOW
 *    EEC_PRIMATTY_EVAPORITE
 *    EEC_PRIMATTY_EXPLOSIVE
 *    EEC_PRIMATTY_FABRIC
 *    EEC_PRIMATTY_FIBREGLASS
 *    EEC_PRIMATTY_FIBREBOARD
 *    EEC_PRIMATTY_FIRST_YEAR_ICE
 *    EEC_PRIMATTY_FLYSCH
 *    EEC_PRIMATTY_FOOD
 *    EEC_PRIMATTY_FORAMINIFERA
 *    EEC_PRIMATTY_FRESH_WATER
 *    EEC_PRIMATTY_FROZEN_WATER
 *    EEC_PRIMATTY_FUCUS
 *    EEC_PRIMATTY_GABBRO
 *    EEC_PRIMATTY_GAS
 *    EEC_PRIMATTY_GLASS
 *    EEC_PRIMATTY_GLASS_REINFORCED_PLASTIC
 *    EEC_PRIMATTY_GLOBIGERINA
 *    EEC_PRIMATTY_GOLD
 *    EEC_PRIMATTY_GRANITE
 *    EEC_PRIMATTY_GRASS
 *    EEC_PRIMATTY_GRAVEL
 *    EEC_PRIMATTY_GREENSTONE
 *    EEC_PRIMATTY_GROUND
 *    EEC_PRIMATTY_GROUND_SHELL
 *    EEC_PRIMATTY_HEAT
 *    EEC_PRIMATTY_ICE
 *    EEC_PRIMATTY_IRON
 *    EEC_PRIMATTY_LAVA
 *    EEC_PRIMATTY_LEAD
 *    EEC_PRIMATTY_LIMESTONE
 *    EEC_PRIMATTY_LOESS
 *    EEC_PRIMATTY_LUMBER
 *    EEC_PRIMATTY_MACADAM
 *    EEC_PRIMATTY_MADREPORE
 *    EEC_PRIMATTY_MANGANESE
 *    EEC_PRIMATTY_MARBLE
 *    EEC_PRIMATTY_MARL
 *    EEC_PRIMATTY_MASONRY
 *    EEC_PRIMATTY_MATTE
 *    EEC_PRIMATTY_METAL
 *    EEC_PRIMATTY_METAL_ROOF
 *    EEC_PRIMATTY_MUD
 *    EEC_PRIMATTY_MULTI_YEAR_ICE
 *    EEC_PRIMATTY_MULTIPLE_MATERIALS
 *    EEC_PRIMATTY_MUSSEL
 *    EEC_PRIMATTY_OIL
 *    EEC_PRIMATTY_OIL_BLISTER
 *    EEC_PRIMATTY_OOZE
 *    EEC_PRIMATTY_OYSTER
 *    EEC_PRIMATTY_PACKED_SOIL
 *    EEC_PRIMATTY_PAPER
 *    EEC_PRIMATTY_PART_METAL
 *    EEC_PRIMATTY_PEBBLE
 *    EEC_PRIMATTY_PETROL
 *    EEC_PRIMATTY_PINE_TREE
 *    EEC_PRIMATTY_PLANT_MATERIAL
 *    EEC_PRIMATTY_PLASTIC
 *    EEC_PRIMATTY_POLYZOA
 *    EEC_PRIMATTY_PORPHYRY
 *    EEC_PRIMATTY_PRESTRESSED_CONCRETE
 *    EEC_PRIMATTY_PTEROPOD
 *    EEC_PRIMATTY_PUMICE
 *    EEC_PRIMATTY_QUARTZ
 *    EEC_PRIMATTY_RADIOACTIVE_MATERIAL
 *    EEC_PRIMATTY_RADIOLARIAN
 *    EEC_PRIMATTY_REINFORCED_CONCRETE
 *    EEC_PRIMATTY_ROCK
 *    EEC_PRIMATTY_RUBBER
 *    EEC_PRIMATTY_RUBBLE
 *    EEC_PRIMATTY_SALT
 *    EEC_PRIMATTY_SAND
 *    EEC_PRIMATTY_SANDSTONE
 *    EEC_PRIMATTY_SCHIST
 *    EEC_PRIMATTY_SCORIA
 *    EEC_PRIMATTY_SCRUB
 *    EEC_PRIMATTY_SEA_TANGLE
 *    EEC_PRIMATTY_SEA_WATER
 *    EEC_PRIMATTY_SEAWEED
 *    EEC_PRIMATTY_SEWAGE
 *    EEC_PRIMATTY_SHALE
 *    EEC_PRIMATTY_SHELL
 *    EEC_PRIMATTY_SHINGLE
 *    EEC_PRIMATTY_SILT
 *    EEC_PRIMATTY_SILVER
 *    EEC_PRIMATTY_SLAG
 *    EEC_PRIMATTY_SLUDGE
 *    EEC_PRIMATTY_SNOW
 *    EEC_PRIMATTY_SOIL
 *    EEC_PRIMATTY_SPICULE
 *    EEC_PRIMATTY_SPOIL
 *    EEC_PRIMATTY_SPOIL_OR_TAILINGS
 *    EEC_PRIMATTY_SPONGE
 *    EEC_PRIMATTY_STEEL
 *    EEC_PRIMATTY_STONE
 *    EEC_PRIMATTY_SUGAR
 *    EEC_PRIMATTY_TAILINGS
 *    EEC_PRIMATTY_THATCH
 *    EEC_PRIMATTY_TRAVERTINE
 *    EEC_PRIMATTY_TUFA
 *    EEC_PRIMATTY_URANIUM
 *    EEC_PRIMATTY_VEGETATION_PRODUCT
 *    EEC_PRIMATTY_VINYL
 *    EEC_PRIMATTY_VOLCANIC
 *    EEC_PRIMATTY_VOLCANIC_ASH
 *    EEC_PRIMATTY_WATER
 *    EEC_PRIMATTY_WET_SNOW
 *    EEC_PRIMATTY_WHITEBODY
 *    EEC_PRIMATTY_WOOD
 *    EEC_PRIMATTY_ZINC
 *    EEC_PRIMATTY_PLASTER
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL
 */
#define EAC_PRIMARY_MATERIAL_TYPE ((EDCS_Attribute_Code)1023)

/*
 * Definition:
 *     The DAFIF two character code identifying the primary operating agency
 *     of an <AERODROME>; formatted in a Basic Latin string as specified by
 *     [DAFIF, Sec. 201.A.17].
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ADMINISTRATION, AIR_TRNSP, TRNSP
 */
#define EAC_PRIMARY_OPERATING_AGENCY_IDENTIFIER ((EDCS_Attribute_Code)1024)

/*
 * Definition:
 *     The primary product resulting from a production, mining, or
 *     agricultural activity.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRIPROD_AIRCRAFT
 *    EEC_PRIPROD_ALUMINUM
 *    EEC_PRIPROD_AMMUNITION
 *    EEC_PRIPROD_ASPHALT
 *    EEC_PRIPROD_BAMBOO
 *    EEC_PRIPROD_BANANA
 *    EEC_PRIPROD_BASALT
 *    EEC_PRIPROD_BAUXITE
 *    EEC_PRIPROD_BEDROCK
 *    EEC_PRIPROD_BIOLOGIC_AGENT
 *    EEC_PRIPROD_BIVALVE_MOLLUSC
 *    EEC_PRIPROD_BOULDER
 *    EEC_PRIPROD_BRICK
 *    EEC_PRIPROD_CALCAREOUS
 *    EEC_PRIPROD_CEMENT
 *    EEC_PRIPROD_CHEMICAL
 *    EEC_PRIPROD_CHEMICAL_AGENT
 *    EEC_PRIPROD_CHEMICAL_BIOLOGIC_AGENT
 *    EEC_PRIPROD_CLAY
 *    EEC_PRIPROD_COAL
 *    EEC_PRIPROD_COBBLE
 *    EEC_PRIPROD_COFFEE
 *    EEC_PRIPROD_COKE
 *    EEC_PRIPROD_COMPOSITION
 *    EEC_PRIPROD_CONCRETE
 *    EEC_PRIPROD_CONGLOMERATE
 *    EEC_PRIPROD_CONSUMER_GOODS
 *    EEC_PRIPROD_CONTROLLED_SUBSTANCE
 *    EEC_PRIPROD_COPPER
 *    EEC_PRIPROD_CORAL
 *    EEC_PRIPROD_COTTON
 *    EEC_PRIPROD_CRUSTACEAN
 *    EEC_PRIPROD_CULTIVATED_SHELLFISH
 *    EEC_PRIPROD_CULTURED_PEARL
 *    EEC_PRIPROD_DESALINATED_WATER
 *    EEC_PRIPROD_DIAMOND
 *    EEC_PRIPROD_DIATOMACEOUS_EARTH
 *    EEC_PRIPROD_DOLOMITE
 *    EEC_PRIPROD_DRINKING_WATER
 *    EEC_PRIPROD_ELECTRICITY
 *    EEC_PRIPROD_EXPLOSIVE
 *    EEC_PRIPROD_FISH
 *    EEC_PRIPROD_FLYSCH
 *    EEC_PRIPROD_FOOD
 *    EEC_PRIPROD_FROZEN_MATERIAL
 *    EEC_PRIPROD_FROZEN_WATER
 *    EEC_PRIPROD_FRUIT_AND_NUT
 *    EEC_PRIPROD_GAS
 *    EEC_PRIPROD_GLASS
 *    EEC_PRIPROD_GOLD
 *    EEC_PRIPROD_GRAIN
 *    EEC_PRIPROD_GRANITE
 *    EEC_PRIPROD_GRASS
 *    EEC_PRIPROD_GRAVEL
 *    EEC_PRIPROD_GREENSTONE
 *    EEC_PRIPROD_GROUND_SHELL
 *    EEC_PRIPROD_HEAT
 *    EEC_PRIPROD_ICE
 *    EEC_PRIPROD_IRON
 *    EEC_PRIPROD_LEAD
 *    EEC_PRIPROD_LIME
 *    EEC_PRIPROD_LIQUIFIED_NATURAL_GAS
 *    EEC_PRIPROD_LIQUIFIED_PETROLEUM_GAS
 *    EEC_PRIPROD_LUMBER
 *    EEC_PRIPROD_MACADAM
 *    EEC_PRIPROD_MANGANESE
 *    EEC_PRIPROD_MARBLE
 *    EEC_PRIPROD_MASONRY
 *    EEC_PRIPROD_MEDICAL_SUPPLIES
 *    EEC_PRIPROD_METAL
 *    EEC_PRIPROD_MILK
 *    EEC_PRIPROD_MINERAL_OIL
 *    EEC_PRIPROD_MOTOR_VEHICLE
 *    EEC_PRIPROD_NO_PRODUCT
 *    EEC_PRIPROD_NON_SOLID_HYDROCARBON_FUEL
 *    EEC_PRIPROD_OIL
 *    EEC_PRIPROD_ORDNANCE
 *    EEC_PRIPROD_ORE
 *    EEC_PRIPROD_PALM
 *    EEC_PRIPROD_PALMETTO
 *    EEC_PRIPROD_PAPER
 *    EEC_PRIPROD_PEBBLE
 *    EEC_PRIPROD_PERSONNEL
 *    EEC_PRIPROD_PETROL
 *    EEC_PRIPROD_PETROLEUM
 *    EEC_PRIPROD_PLANT_MATERIAL
 *    EEC_PRIPROD_PLASTIC
 *    EEC_PRIPROD_PORPHYRY
 *    EEC_PRIPROD_POTABLE_WATER
 *    EEC_PRIPROD_PRESTRESSED_CONCRETE
 *    EEC_PRIPROD_PUMICE
 *    EEC_PRIPROD_QUARTZ
 *    EEC_PRIPROD_RADIOACTIVE_MATERIAL
 *    EEC_PRIPROD_RADIOLOGIC_AGENT
 *    EEC_PRIPROD_REINFORCED_CONCRETE
 *    EEC_PRIPROD_RICE
 *    EEC_PRIPROD_ROCK
 *    EEC_PRIPROD_RUBBER
 *    EEC_PRIPROD_SALT
 *    EEC_PRIPROD_SAND
 *    EEC_PRIPROD_SANDSTONE
 *    EEC_PRIPROD_SCHIST
 *    EEC_PRIPROD_SCORIA
 *    EEC_PRIPROD_SEAWEED
 *    EEC_PRIPROD_SEWAGE
 *    EEC_PRIPROD_SHELL
 *    EEC_PRIPROD_SHINGLE
 *    EEC_PRIPROD_SILK
 *    EEC_PRIPROD_SILVER
 *    EEC_PRIPROD_SNOW
 *    EEC_PRIPROD_SOIL
 *    EEC_PRIPROD_SPONGE
 *    EEC_PRIPROD_STEEL
 *    EEC_PRIPROD_STONE
 *    EEC_PRIPROD_SUGAR
 *    EEC_PRIPROD_TALC
 *    EEC_PRIPROD_TELECOMMUNICATION
 *    EEC_PRIPROD_TEXTILE
 *    EEC_PRIPROD_THATCH
 *    EEC_PRIPROD_TIMBER
 *    EEC_PRIPROD_TOBACCO
 *    EEC_PRIPROD_TRAVERTINE
 *    EEC_PRIPROD_TUFA
 *    EEC_PRIPROD_URANIUM
 *    EEC_PRIPROD_VEGETATION_PRODUCT
 *    EEC_PRIPROD_WATER
 *    EEC_PRIPROD_WINE
 *    EEC_PRIPROD_WOOD
 *    EEC_PRIPROD_WOODCHIP
 *    EEC_PRIPROD_ZINC
 *
 * Group Membership: AGRICULTURE, INDUSTRY
 */
#define EAC_PRIMARY_PRODUCT ((EDCS_Attribute_Code)1025)

/*
 * Definition:
 *     The primary raw <MATERIAL> involved in a production activity.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRIRAWMAT_ALUMINUM
 *    EEC_PRIRAWMAT_ASPHALT
 *    EEC_PRIRAWMAT_BAMBOO
 *    EEC_PRIRAWMAT_BASALT
 *    EEC_PRIRAWMAT_BAUXITE
 *    EEC_PRIRAWMAT_BEDROCK
 *    EEC_PRIRAWMAT_BOULDER
 *    EEC_PRIRAWMAT_CALCAREOUS
 *    EEC_PRIRAWMAT_CEMENT
 *    EEC_PRIRAWMAT_CHEMICAL
 *    EEC_PRIRAWMAT_CLAY
 *    EEC_PRIRAWMAT_COAL
 *    EEC_PRIRAWMAT_COBBLE
 *    EEC_PRIRAWMAT_COKE
 *    EEC_PRIRAWMAT_CONGLOMERATE
 *    EEC_PRIRAWMAT_COPPER
 *    EEC_PRIRAWMAT_CORAL
 *    EEC_PRIRAWMAT_COTTON
 *    EEC_PRIRAWMAT_DESALINATED_WATER
 *    EEC_PRIRAWMAT_DIAMOND
 *    EEC_PRIRAWMAT_DIATOMACEOUS_EARTH
 *    EEC_PRIRAWMAT_DOLOMITE
 *    EEC_PRIRAWMAT_ELECTRICITY
 *    EEC_PRIRAWMAT_FLYSCH
 *    EEC_PRIRAWMAT_FROZEN_MATERIAL
 *    EEC_PRIRAWMAT_FROZEN_WATER
 *    EEC_PRIRAWMAT_GAS
 *    EEC_PRIRAWMAT_GLASS
 *    EEC_PRIRAWMAT_GOLD
 *    EEC_PRIRAWMAT_GRAIN
 *    EEC_PRIRAWMAT_GRANITE
 *    EEC_PRIRAWMAT_GRASS
 *    EEC_PRIRAWMAT_GRAVEL
 *    EEC_PRIRAWMAT_GREENSTONE
 *    EEC_PRIRAWMAT_GROUND_SHELL
 *    EEC_PRIRAWMAT_HEAT
 *    EEC_PRIRAWMAT_ICE
 *    EEC_PRIRAWMAT_IRON
 *    EEC_PRIRAWMAT_LEAD
 *    EEC_PRIRAWMAT_LIME
 *    EEC_PRIRAWMAT_LIQUIFIED_NATURAL_GAS
 *    EEC_PRIRAWMAT_LIQUIFIED_PETROLEUM_GAS
 *    EEC_PRIRAWMAT_LUMBER
 *    EEC_PRIRAWMAT_MANGANESE
 *    EEC_PRIRAWMAT_MARBLE
 *    EEC_PRIRAWMAT_METAL
 *    EEC_PRIRAWMAT_MINERAL_OIL
 *    EEC_PRIRAWMAT_NO_RAW_MATERIAL
 *    EEC_PRIRAWMAT_NON_SOLID_HYDROCARBON_FUEL
 *    EEC_PRIRAWMAT_OIL
 *    EEC_PRIRAWMAT_ORE
 *    EEC_PRIRAWMAT_PALM
 *    EEC_PRIRAWMAT_PALMETTO
 *    EEC_PRIRAWMAT_PAPER
 *    EEC_PRIRAWMAT_PEBBLE
 *    EEC_PRIRAWMAT_PETROLEUM
 *    EEC_PRIRAWMAT_PLANT_MATERIAL
 *    EEC_PRIRAWMAT_PLASTIC
 *    EEC_PRIRAWMAT_PORPHYRY
 *    EEC_PRIRAWMAT_PUMICE
 *    EEC_PRIRAWMAT_QUARTZ
 *    EEC_PRIRAWMAT_RADIOACTIVE_MATERIAL
 *    EEC_PRIRAWMAT_ROCK
 *    EEC_PRIRAWMAT_RUBBER
 *    EEC_PRIRAWMAT_SALT
 *    EEC_PRIRAWMAT_SAND
 *    EEC_PRIRAWMAT_SANDSTONE
 *    EEC_PRIRAWMAT_SAWDUST_WOODCHIP
 *    EEC_PRIRAWMAT_SCHIST
 *    EEC_PRIRAWMAT_SCORIA
 *    EEC_PRIRAWMAT_SCRAP_METAL
 *    EEC_PRIRAWMAT_SEAWEED
 *    EEC_PRIRAWMAT_SEWAGE
 *    EEC_PRIRAWMAT_SHELL
 *    EEC_PRIRAWMAT_SILK
 *    EEC_PRIRAWMAT_SILVER
 *    EEC_PRIRAWMAT_SNOW
 *    EEC_PRIRAWMAT_SOIL
 *    EEC_PRIRAWMAT_SPICULE
 *    EEC_PRIRAWMAT_SPONGE
 *    EEC_PRIRAWMAT_STEEL
 *    EEC_PRIRAWMAT_STONE
 *    EEC_PRIRAWMAT_SUGAR
 *    EEC_PRIRAWMAT_TALC
 *    EEC_PRIRAWMAT_TEXTILE
 *    EEC_PRIRAWMAT_THATCH
 *    EEC_PRIRAWMAT_TIMBER
 *    EEC_PRIRAWMAT_TOBACCO
 *    EEC_PRIRAWMAT_TRAVERTINE
 *    EEC_PRIRAWMAT_TUFA
 *    EEC_PRIRAWMAT_URANIUM
 *    EEC_PRIRAWMAT_VEGETATION_PRODUCT
 *    EEC_PRIRAWMAT_VOLCANIC_ASH
 *    EEC_PRIRAWMAT_WATER
 *    EEC_PRIRAWMAT_WOOD
 *    EEC_PRIRAWMAT_WOODCHIP
 *    EEC_PRIRAWMAT_ZINC
 *
 * Group Membership: INDUSTRY, MATERIAL
 */
#define EAC_PRIMARY_RAW_MATERIAL ((EDCS_Attribute_Code)1026)

/*
 * Definition:
 *     The <<VELOCITY>> of the <AIR> along the primary <SURFACE>, generally
 *     the top, front, or outer side of a layer of <MATERIAL> or an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, MATERIAL, RATE_OR_RATIO, SURFACE
 */
#define EAC_PRIMARY_SURFACE_AIR_VELOCITY ((EDCS_Attribute_Code)1027)

/*
 * Definition:
 *     The <<TEMPERATURE>> of the medium in contact with the primary
 *     <SURFACE> of an <OBJECT>, generally the top, front, or outer side of
 *     a layer of <MATERIAL>, that is typically used as a boundary condition
 *     in thermal solutions.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: MATERIAL, SURFACE, TEMPERATURE
 */
#define EAC_PRIMARY_SURFACE_TEMPERATURE ((EDCS_Attribute_Code)1028)

/*
 * Definition:
 *     The physical boundary condition at the primary <SURFACE> of an
 *     <OBJECT>, generally the top, front, or outer side of a layer of
 *     <MATERIAL>, that accounts for the thermal interface of the <OBJECT>
 *     with the environment at that <SURFACE>; the primary surface thermal
 *     condition.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRISRFTHERMCND_AERODYNAMICALLY_HEATED
 *    EEC_PRISRFTHERMCND_AMB_AIR_AMB_SPEED_INFLUENCED
 *    EEC_PRISRFTHERMCND_AMB_AIR_FIXED
 *    EEC_PRISRFTHERMCND_AMB_AIR_INFLUENCED
 *    EEC_PRISRFTHERMCND_AMB_TEMP_LOCAL_AIR_INFLUENCED
 *    EEC_PRISRFTHERMCND_ARTIFICIAL_STEADY_STATE
 *    EEC_PRISRFTHERMCND_ENGINE_INFLUENCED
 *    EEC_PRISRFTHERMCND_EXTREMELY_HOT_FORCED
 *    EEC_PRISRFTHERMCND_FIXED_SURFACE_TEMP
 *    EEC_PRISRFTHERMCND_GROUND_TEMP_INFLUENCED
 *    EEC_PRISRFTHERMCND_LOCAL_AIR_TEMP_SPEED_INFLUENCED
 *    EEC_PRISRFTHERMCND_ROOM_TEMP_FORCED
 *    EEC_PRISRFTHERMCND_WARMED_PASSIVELY
 *
 * Group Membership: MATERIAL, SURFACE
 */
#define EAC_PRIMARY_SURFACE_THERMAL_CONDITION ((EDCS_Attribute_Code)1029)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which primary
 *     <SWELL_WAVE>s are arriving.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_PRIMARY_SWELL_WAVE_DIRECTION ((EDCS_Attribute_Code)1030)

/*
 * Definition:
 *     The mean height of the significant (highest one-third) primary
 *     <SWELL_WAVE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_PRIMARY_SWELL_WAVE_HEIGHT ((EDCS_Attribute_Code)1031)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> that a complete cycle (usually crest to
 *     crest or trough to trough) of a primary <SWELL_WAVE> takes to pass a
 *     given fixed point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_PRIMARY_SWELL_WAVE_PERIOD ((EDCS_Attribute_Code)1032)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which significant
 *     <WATER_WAVE>s in the wave spectra are arriving.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_PRIMARY_WAVE_DIRECTION ((EDCS_Attribute_Code)1033)

/*
 * Definition:
 *     A value representing the priority of this <OBJECT> as compared to
 *     other <OBJECT>s which overlap in spatial extent. A higher value means
 *     a higher priority.
 *
 * Value Type: INTEGER
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_PRIORITY ((EDCS_Attribute_Code)1034)

/*
 * Definition:
 *     A name that is assigned to an <OBJECT> to support processing internal
 *     to an information <SYSTEM>.
 *
 * Value Type: STRING
 *
 * Group Membership: ABSTRACT_OBJECT, ALGORITHM_RELATED, IDENTIFICATION
 */
#define EAC_PROCESSING_NAME ((EDCS_Attribute_Code)1035)

/*
 * Definition:
 *     The source of data values of a <PROPERTY_SET>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRPSETDATSRC_ANALYSIS
 *    EEC_PRPSETDATSRC_CLIMATOLOGIC
 *    EEC_PRPSETDATSRC_FORECAST
 *    EEC_PRPSETDATSRC_OBSERVATION
 *
 * Group Membership: PROPERTY_SET
 */
#define EAC_PROPERTY_SET_DATA_SOURCE ((EDCS_Attribute_Code)1036)

/*
 * Definition:
 *     The spatial domain of a <PROPERTY_SET>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PRPSETSPATDMN_LAYER
 *    EEC_PRPSETSPATDMN_LOCAL
 *    EEC_PRPSETSPATDMN_PLANETARY_SURFACE
 *    EEC_PRPSETSPATDMN_PRESSURE_SURFACE
 *    EEC_PRPSETSPATDMN_PROFILE
 *    EEC_PRPSETSPATDMN_SURFACE
 *    EEC_PRPSETSPATDMN_TERRAIN_SURFACE
 *    EEC_PRPSETSPATDMN_VOLUME
 *    EEC_PRPSETSPATDMN_WATER_BODY_FLOOR
 *
 * Group Membership: PROPERTY_SET
 */
#define EAC_PROPERTY_SET_SPATIAL_DOMAIN ((EDCS_Attribute_Code)1037)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> relative to a specified zero hour at which a
 *     <PROPERTY_SET> is valid.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: PROPERTY_SET, TIME
 */
#define EAC_PROPERTY_SET_VALID_TIME ((EDCS_Attribute_Code)1038)

/*
 * Definition:
 *     The type of a <PROTECTION_SHED>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PROTSHEDTY_OUTBUILDING
 *    EEC_PROTSHEDTY_ROCK_SHED
 *    EEC_PROTSHEDTY_SNOW_SHED
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_PROTECTION_SHED_TYPE ((EDCS_Attribute_Code)1039)

/*
 * Definition:
 *     The type of a <FACILITY> that is normally used for accommodating the
 *     public but is not a permanent or long-term <DWELLING>; public
 *     accommodation type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PUBACCOMTY_HOSTEL
 *    EEC_PUBACCOMTY_HOTEL
 *    EEC_PUBACCOMTY_MOTEL
 *    EEC_PUBACCOMTY_OUTBUILDING
 *    EEC_PUBACCOMTY_PUBLIC_INN
 *    EEC_PUBACCOMTY_RESTAURANT
 *    EEC_PUBACCOMTY_TEMPORARY_RESIDENCE
 *
 * Group Membership: INFRASTRUCTURE, SHELTER
 */
#define EAC_PUBLIC_ACCOMMODATION_TYPE ((EDCS_Attribute_Code)1040)

/*
 * Definition:
 *     A reference to a specific paragraph in a publication.
 *
 * Value Type: STRING
 *
 * Group Membership: COMMUNICATION
 */
#define EAC_PUBLICATION_REFERENCE ((EDCS_Attribute_Code)1041)

/*
 * Definition:
 *     The specific <<FREQUENCY>> of a radar transponder <BEACON>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: COMMUNICATION, TRNSP
 */
#define EAC_RADAR_BEACON_FREQUENCY ((EDCS_Attribute_Code)1042)

/*
 * Definition:
 *     The ratio of the radar power (or flux) per unit solid angle reflected
 *     from an <OBJECT> toward a sensor and 4(pi) times the incident power
 *     density; the radar cross section.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREA
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_RADAR_CROSS_SECTION ((EDCS_Attribute_Code)1043)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the radar reflective side of an <OBJECT>;
 *     the radar reflector angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_RADAR_REFLECTOR_ANGLE ((EDCS_Attribute_Code)1044)

/*
 * Definition:
 *     An indication that an <OBJECT> has an associated radar reflector
 *     <DEVICE>; radar reflector present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, DEVICE_AND_EQUIPMENT
 */
#define EAC_RADAR_REFLECTOR_PRESENT ((EDCS_Attribute_Code)1045)

/*
 * Definition:
 *     The type of an <OBJECT> based on the predominant exposed <MATERIAL> of
 *     the <SURFACE> of the <OBJECT>; the radar significance factor.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RADRSIGNIFFACT_ASPHALT
 *    EEC_RADRSIGNIFFACT_COMPOSITION
 *    EEC_RADRSIGNIFFACT_CONCRETE
 *    EEC_RADRSIGNIFFACT_EARTHEN_WORKS
 *    EEC_RADRSIGNIFFACT_FROZEN_WATER
 *    EEC_RADRSIGNIFFACT_MARSH
 *    EEC_RADRSIGNIFFACT_MASONRY
 *    EEC_RADRSIGNIFFACT_METAL
 *    EEC_RADRSIGNIFFACT_OIL
 *    EEC_RADRSIGNIFFACT_PART_METAL
 *    EEC_RADRSIGNIFFACT_ROCK
 *    EEC_RADRSIGNIFFACT_SAND
 *    EEC_RADRSIGNIFFACT_SOIL
 *    EEC_RADRSIGNIFFACT_TREES
 *    EEC_RADRSIGNIFFACT_WATER
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL, SURFACE, SURFACE_MATERIAL
 */
#define EAC_RADAR_SIGNIFICANCE_FACTOR ((EDCS_Attribute_Code)1046)

/*
 * Definition:
 *     The type of a <RADAR_STATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RADRSTATY_AERODROME
 *    EEC_RADRSTATY_AIR_DEFENCE
 *    EEC_RADRSTATY_COASTAL
 *    EEC_RADRSTATY_MARINE_TRAFFIC_SURVEILLANCE
 *
 * Group Membership: COMMUNICATION
 */
#define EAC_RADAR_STATION_TYPE ((EDCS_Attribute_Code)1047)

/*
 * Definition:
 *     The radar surface clutter expressed in mean <<RADAR_CROSS_SECTION>>
 *     per unit <<AREA>> of <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_RADAR_TERRAIN_CLUTTER ((EDCS_Attribute_Code)1048)

/*
 * Definition:
 *     The type of a radar transponder <BEACON>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RADRTRNSPNDTY_LEADING_LINE_RACON
 *    EEC_RADRTRNSPNDTY_RACON_TRANSPONDER
 *    EEC_RADRTRNSPNDTY_RAMARK_BEACON
 *
 * Group Membership: TRNSP
 */
#define EAC_RADAR_TRANSPONDER_TYPE ((EDCS_Attribute_Code)1049)

/*
 * Definition:
 *     The radar surface clutter expressed in mean <<RADAR_CROSS_SECTION>>
 *     per unit <<AREA>> of <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define EAC_RADAR_WATERBODY_SURFACE_CLUTTER ((EDCS_Attribute_Code)1050)

/*
 * Definition:
 *     The radiant power per unit source <<AREA>> per unit solid angle; the
 *     radiance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RADIANCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_RADIANCE ((EDCS_Attribute_Code)1051)

/*
 * Definition:
 *     The amount of fluctuation (peak amplitude) of the<<RADIANCE>> (or
 *     luminance) of a <SURFACE> over a twenty-four hour <<TIME_QUANTITY>>,
 *     expressed as a value from 0 to 255.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SURFACE
 */
#define EAC_RADIANCE_FLUCTUATION_24_HOUR ((EDCS_Attribute_Code)1052)

/*
 * Definition:
 *     The angular phase of <<RADIANCE>> amplitude assuming a sine wave
 *     fluctuation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_RADIANCE_PHASE ((EDCS_Attribute_Code)1053)

/*
 * Definition:
 *     The radiant energy crossing a unit area from one side; the radiant
 *     flux density. The same quantity is designated as either the
 *     irradiance (when it is a received flux) or the exitance (when it is
 *     an emitted flux).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SURFACE
 */
#define EAC_RADIANT_FLUX_DENSITY ((EDCS_Attribute_Code)1054)

/*
 * Definition:
 *     Short <<WAVELENGTH>> (less than 4 microns) <<RADIANT_FLUX_DENSITY>>
 *     incident downward on a <PLANETARY_SURFACE> as direct solar radiation;
 *     the radiative flux downwelling.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_RADIATIVE_FLUX_DOWNWELLING ((EDCS_Attribute_Code)1055)

/*
 * Definition:
 *     The net (upward minus downward) long <<WAVELENGTH>> (greater than 4
 *     microns) thermal <<RADIANT_FLUX_DENSITY>> from a <PLANETARY_SURFACE>;
 *     the radiative flux upwelling.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_RADIATIVE_FLUX_UPWELLING ((EDCS_Attribute_Code)1056)

/*
 * Definition:
 *     The type of a marine radio <COMMUNICATION_STATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RADIOSTATY_AERONAUTICAL_BEACON
 *    EEC_RADIOSTATY_CIRCULAR_MARINE
 *    EEC_RADIOSTATY_COASTAL_PROVIDING_QTG
 *    EEC_RADIOSTATY_CONSOL_BEACON
 *    EEC_RADIOSTATY_DIRECTIONAL_BEACON
 *    EEC_RADIOSTATY_RADIO_DIRECTION_FINDING
 *    EEC_RADIOSTATY_ROTATING_PATTERN_BEACON
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE
 */
#define EAC_RADIO_STATION_TYPE ((EDCS_Attribute_Code)1057)

/*
 * Definition:
 *     The concentration of a radiologic agent suspended in an <ATMOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_RADIOLOGIC_AGENT_ATM_CONCENTRATION ((EDCS_Attribute_Code)1058)

/*
 * Definition:
 *     The concentration of a radiologic agent contained in a layer on the
 *     <SURFACE> of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SURFACE, SURFACE_MATERIAL
 */
#define EAC_RADIOLOGIC_AGENT_SURFACE_CONCENTRATION ((EDCS_Attribute_Code)1059)

/*
 * Definition:
 *     The type of a radiologic agent that can kill, seriously injure, or
 *     incapacitate <HUMAN>s or <NON_HUMAN_ANIMAL>s through its
 *     physiological properties.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RADLAGENTTY_ALKALI_METAL
 *    EEC_RADLAGENTTY_ALKALINE_EARTH
 *    EEC_RADLAGENTTY_BORON
 *    EEC_RADLAGENTTY_CESIUM_137
 *    EEC_RADLAGENTTY_CHALCOGEN
 *    EEC_RADLAGENTTY_COBALT_60
 *    EEC_RADLAGENTTY_CONCRETE
 *    EEC_RADLAGENTTY_EARLY_TRANSITION_ELEMENT
 *    EEC_RADLAGENTTY_HALOGEN
 *    EEC_RADLAGENTTY_LESS_VOLATILE_MAIN_GROUP
 *    EEC_RADLAGENTTY_MORE_VOLATILE_MAIN_GROUP
 *    EEC_RADLAGENTTY_NOBLE_GAS
 *    EEC_RADLAGENTTY_PLATINOID
 *    EEC_RADLAGENTTY_TETRAVALENT
 *    EEC_RADLAGENTTY_TRIVALENT
 *    EEC_RADLAGENTTY_URANIUM
 *    EEC_RADLAGENTTY_WATER
 *
 * Group Membership: EM_PHENOMENON, MATERIAL
 */
#define EAC_RADIOLOGIC_AGENT_TYPE ((EDCS_Attribute_Code)1060)

/*
 * Definition:
 *     The <<MASS>> of a radiologic substance contained in an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_RADIOLOGIC_MASS ((EDCS_Attribute_Code)1061)

/*
 * Definition:
 *     The radius of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_RADIUS ((EDCS_Attribute_Code)1062)

/*
 * Definition:
 *     The vertical distance from the <FLOOR> to the top of a railing.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION
 */
#define EAC_RAILING_HEIGHT ((EDCS_Attribute_Code)1063)

/*
 * Definition:
 *     The type of a railing.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RAILINGTY_BALUSTRADE
 *    EEC_RAILINGTY_NONE_PRESENT
 *    EEC_RAILINGTY_SHORT_WALL
 *    EEC_RAILINGTY_WALL_HANDRAIL
 *    EEC_RAILINGTY_ESCALATOR_HANDRAIL
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define EAC_RAILING_TYPE ((EDCS_Attribute_Code)1064)

/*
 * Definition:
 *     The distance between a single pair of rails of a <RAILWAY_TRACK>
 *     measured along the shortest distance from inside rail to inside rail;
 *     the railway gauge.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_RAILWAY_GAUGE ((EDCS_Attribute_Code)1065)

/*
 * Definition:
 *     The category of a <<RAILWAY_GAUGE>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RAILGAUGECAT_ANY
 *    EEC_RAILGAUGECAT_BROAD
 *    EEC_RAILGAUGECAT_NARROW
 *    EEC_RAILGAUGECAT_NORMAL_COUNTRY_SPECIFIC
 *    EEC_RAILGAUGECAT_STANDARD
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_RAILWAY_GAUGE_CATEGORY ((EDCS_Attribute_Code)1066)

/*
 * Definition:
 *     The maximum load allowable on any single axle of a <RAIL_WAGON> or
 *     <LOCOMOTIVE_ENGINE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_RAILWAY_MAXIMUM_AXLE_LOAD ((EDCS_Attribute_Code)1067)

/*
 * Definition:
 *     The maximum load allowable on a <RAILWAY>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_RAILWAY_MAXIMUM_LOAD ((EDCS_Attribute_Code)1068)

/*
 * Definition:
 *     The source of electrical power for a <RAILWAY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RAILPWRSRC_ELECTRIFIED_TRACK
 *    EEC_RAILPWRSRC_NON_ELECTRIFIED
 *    EEC_RAILPWRSRC_OVERHEAD_ELECTRIFIED
 *
 * Group Membership: EM_PHENOMENON, LAND_TRNSP, TRNSP
 */
#define EAC_RAILWAY_POWER_SOURCE ((EDCS_Attribute_Code)1069)

/*
 * Definition:
 *     The arrangement of <RAILWAY_TRACK>s in both <DIRECTION>s on a single
 *     bed.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RAILTRKARR_DOUBLE
 *    EEC_RAILTRKARR_JUXTAPOSITION
 *    EEC_RAILTRKARR_MULTIPLE_ARRANGEMENTS
 *    EEC_RAILTRKARR_SINGLE
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_RAILWAY_TRACK_ARRANGEMENT ((EDCS_Attribute_Code)1070)

/*
 * Definition:
 *     The type of a <SYSTEM> of <RAILWAY>s used to support various
 *     transportation uses.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RAILTY_ABANDONED
 *    EEC_RAILTY_BRANCH_LINE
 *    EEC_RAILTY_CAR_LINE
 *    EEC_RAILTY_DRILL_TRACK
 *    EEC_RAILTY_HOUSE_TRACK
 *    EEC_RAILTY_IN_ROAD
 *    EEC_RAILTY_INCLINED
 *    EEC_RAILTY_INDUSTRIAL
 *    EEC_RAILTY_JOINT_TRACK
 *    EEC_RAILTY_LADDER_TRACK
 *    EEC_RAILTY_LOGGING
 *    EEC_RAILTY_MAIN_LINE
 *    EEC_RAILTY_MARINE
 *    EEC_RAILTY_MINIATURE
 *    EEC_RAILTY_MONORAIL
 *    EEC_RAILTY_MUSEUM
 *    EEC_RAILTY_PAIRED_TRACK
 *    EEC_RAILTY_PASSENGER
 *    EEC_RAILTY_RAPID_TRANSIT_ROUTE
 *    EEC_RAILTY_RIP_TRACK
 *    EEC_RAILTY_SIDE_TRACK
 *    EEC_RAILTY_STUB_TRACK
 *    EEC_RAILTY_SUBWAY
 *    EEC_RAILTY_TEAM_TRACK
 *    EEC_RAILTY_TRAMWAY
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_RAILWAY_TYPE ((EDCS_Attribute_Code)1071)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional deployment of a <RAMP> or <GATE> of an <OBJECT>. Zero
 *     means fully stowed/retracted/closed and one means fully deployed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, TRNSP
 */
#define EAC_RAMP_DEPLOYED_POSITION ((EDCS_Attribute_Code)1072)

/*
 * Definition:
 *     In North America, the relative difficulty of traversing a <RAPID>,
 *     based on the Safety Code of American Whitewater; the rapid class.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RAPIDCLS_I
 *    EEC_RAPIDCLS_II
 *    EEC_RAPIDCLS_III
 *    EEC_RAPIDCLS_IV
 *    EEC_RAPIDCLS_V
 *    EEC_RAPIDCLS_VI
 *
 * Group Membership: HYDROLOGY, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_RAPID_CLASS ((EDCS_Attribute_Code)1073)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional light intensity received by an <OBJECT> from all
 *     unlocalized sources. Zero means minimum intensity and one means
 *     maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_RECEIVED_AMBIENT_LIGHT_SCALED_INTENSITY ((EDCS_Attribute_Code)1074)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional light intensity received by an <OBJECT> from the diffuse
 *     radiation leaving a particular localized source. Zero means minimum
 *     intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_RECEIVED_DIFFUSE_LIGHT_SCALED_INTENSITY ((EDCS_Attribute_Code)1075)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional light intensity received by an <OBJECT> from the specular
 *     radiation leaving a particular localized source. Zero means minimum
 *     intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_RECEIVED_SPECULAR_LIGHT_SCALED_INTENSITY ((EDCS_Attribute_Code)1076)

/*
 * Definition:
 *     An indication that an <OBJECT> complies with a recommended track.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, TRNSP
 */
#define EAC_RECOMMENDED_TRACK ((EDCS_Attribute_Code)1077)

/*
 * Definition:
 *     The date when the given information concerning the <OBJECT> was
 *     recorded, captured, edited, or deleted. The value is formatted as
 *     specified by <<DATE_FORMAT>> or by <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TIME
 */
#define EAC_RECORDING_DATE ((EDCS_Attribute_Code)1078)

/*
 * Definition:
 *     The type of a <<RECORDING_DATE>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RCRDDATETY_AERIAL_PHOTOGRAPHY
 *    EEC_RCRDDATETY_AIR_INFORMATION
 *    EEC_RCRDDATETY_APPROXIMATE
 *    EEC_RCRDDATETY_COMPILATION
 *    EEC_RCRDDATETY_COPYRIGHT
 *    EEC_RCRDDATETY_CREATION
 *    EEC_RCRDDATETY_CYCLE
 *    EEC_RCRDDATETY_DIGITIZING
 *    EEC_RCRDDATETY_DISTRIBUTED
 *    EEC_RCRDDATETY_DOWNGRADING
 *    EEC_RCRDDATETY_DRAWN
 *    EEC_RCRDDATETY_EARLIEST_SOURCE
 *    EEC_RCRDDATETY_EDITION
 *    EEC_RCRDDATETY_FIELD_CLASSIFICATION
 *    EEC_RCRDDATETY_FIELD_EXAMINATION
 *    EEC_RCRDDATETY_INFORMATION_AS_OF
 *    EEC_RCRDDATETY_INTELLIGENCE
 *    EEC_RCRDDATETY_INTERPRETABLE
 *    EEC_RCRDDATETY_LATEST_SOURCE
 *    EEC_RCRDDATETY_MAGNETIC_INFO
 *    EEC_RCRDDATETY_MAP_EDIT
 *    EEC_RCRDDATETY_NOTICE_TO_MARINERS
 *    EEC_RCRDDATETY_PERISHABLE_INFORMATION
 *    EEC_RCRDDATETY_PROCESSING
 *    EEC_RCRDDATETY_PUBLISHED
 *    EEC_RCRDDATETY_RECEIPT
 *    EEC_RCRDDATETY_REVISION
 *    EEC_RCRDDATETY_SIGNIFICANT
 *    EEC_RCRDDATETY_SOURCE
 *    EEC_RCRDDATETY_SPECIFICATION
 *    EEC_RCRDDATETY_SURVEY
 *
 * Group Membership: TIME
 */
#define EAC_RECORDING_DATE_TYPE ((EDCS_Attribute_Code)1079)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_GEODETIC>> toward which light is reflected (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_REFLECTANCE_AZIMUTH_GEODETIC ((EDCS_Attribute_Code)1080)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_LOCAL>> toward which light is reflected (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_REFLECTANCE_AZIMUTH_LOCAL ((EDCS_Attribute_Code)1081)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_MAGNETIC>> toward which light is reflected (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_REFLECTANCE_AZIMUTH_MAGNETIC ((EDCS_Attribute_Code)1082)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_HORIZONTAL>> toward which light is reflected
 *     (the <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_REFLECTANCE_ELEV_ANGLE_HORIZONTAL ((EDCS_Attribute_Code)1083)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_LOCAL>> toward which light is reflected (the
 *     <DIRECTION> of the unit Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_REFLECTANCE_ELEV_ANGLE_LOCAL ((EDCS_Attribute_Code)1084)

/*
 * Definition:
 *     The angle at a <LOCATION> on a <SURFACE> between the vectors A and B,
 *     where A is the surface normal vector and B is the <DIRECTION> toward
 *     the sampling of radiation reflected from the <SURFACE> at that
 *     <LOCATION>. The positive sense is clockwise when looking in the
 *     <DIRECTION> of the cross product AxB.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, SURFACE
 */
#define EAC_REFLECTANCE_ZENITH_ANGLE_LOCAL ((EDCS_Attribute_Code)1085)

/*
 * Definition:
 *     The imaginary part of a complex refraction index. The complex
 *     refraction index is the square root of the product of the complex
 *     relative permittivity and permeability of the <MATERIAL>. The
 *     imaginary part of the complex refraction index can also be derived
 *     from the attenuation index or absorption coefficient of the
 *     <MATERIAL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: MATERIAL
 */
#define EAC_REFRACTION_INDEX_IMAGINARY_PART ((EDCS_Attribute_Code)1086)

/*
 * Definition:
 *     The real part of a complex refraction index. The complex refraction
 *     index is the square root of the product of the complex relative
 *     permittivity and permeability of the <MATERIAL>. The real part of a
 *     complex refraction index can also be derived from the attenuation
 *     index or absorption coefficient of the <MATERIAL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: MATERIAL
 */
#define EAC_REFRACTION_INDEX_REAL_PART ((EDCS_Attribute_Code)1087)

/*
 * Definition:
 *     The architectural style of a <STRUCTURE> based on the <REGION> of the
 *     <EARTH> where it is commonly used or other important characteristics;
 *     the regional style.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_REGNSTYLE_AFRICA
 *    EEC_REGNSTYLE_ANTARCTICA
 *    EEC_REGNSTYLE_ARCTIC
 *    EEC_REGNSTYLE_ASIA
 *    EEC_REGNSTYLE_AUSTRALIA
 *    EEC_REGNSTYLE_CENTRAL_AMERICA
 *    EEC_REGNSTYLE_CENTRAL_ASIA
 *    EEC_REGNSTYLE_EASTERN_EUROPE
 *    EEC_REGNSTYLE_EUROPE
 *    EEC_REGNSTYLE_MODERN_INDUSTRIAL_CONSTRUCTION
 *    EEC_REGNSTYLE_NORTH_AMERICA
 *    EEC_REGNSTYLE_NORTH_EAST_ASIA
 *    EEC_REGNSTYLE_NORTHERN_EUROPE
 *    EEC_REGNSTYLE_PACIFIC_ISLANDS
 *    EEC_REGNSTYLE_SOUTH_AMERICA
 *    EEC_REGNSTYLE_SOUTH_EAST_ASIA
 *    EEC_REGNSTYLE_SOUTHERN_EUROPE
 *    EEC_REGNSTYLE_SOUTH_WEST_ASIA
 *    EEC_REGNSTYLE_WESTERN_EUROPE
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_REGIONAL_STYLE ((EDCS_Attribute_Code)1088)

/*
 * Definition:
 *     The horizontal accuracy of a <LOCATION> relative to another horizontal
 *     <LOCATION> expressed in units of length at 90% circular error.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_RELATIVE_HORIZONTAL_ACCURACY ((EDCS_Attribute_Code)1089)

/*
 * Definition:
 *     The ratio of vapour pressure to saturation vapour pressure, where
 *     vapour pressure is the pressure exerted by the molecules of water
 *     vapour and saturation vapour pressure is the pressure exerted by
 *     molecules of water vapour in <AIR> that has attained saturation; the
 *     relative humidity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_RELATIVE_HUMIDITY ((EDCS_Attribute_Code)1090)

/*
 * Definition:
 *     The error in a measurement of <<RELATIVE_HUMIDITY>> that is introduced
 *     by uncertainties.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_RELATIVE_HUMIDITY_ERROR ((EDCS_Attribute_Code)1091)

/*
 * Definition:
 *     The <<RELATIVE_HUMIDITY>> at the time of the lowest
 *     <<AIR_TEMPERATURE>> for the preceding twenty-four hours.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_RELATIVE_HUMIDITY_MINIMUM_TEMPERATURE ((EDCS_Attribute_Code)1092)

/*
 * Definition:
 *     The <LOCATION> of an <OBJECT> relative to the surrounding <REGION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RELLOC_ABOVE_SRF
 *    EEC_RELLOC_ABOVE_SRF_HGT_KNOWN
 *    EEC_RELLOC_ABOVE_SRF_HGT_UNKNOWN
 *    EEC_RELLOC_ABOVE_WTR_BODY_FLOOR
 *    EEC_RELLOC_AWASH_AT_CHART_DATUM
 *    EEC_RELLOC_BELOW_WTR_BODY_FLOOR
 *    EEC_RELLOC_BELOW_WTR_BODY_SURFACE
 *    EEC_RELLOC_COVERED_ge_20_M_AND_lt_30_M
 *    EEC_RELLOC_COVERED_ge_30_M
 *    EEC_RELLOC_COVERED_INTERMITTENTLY
 *    EEC_RELLOC_COVERED_lt_20_M
 *    EEC_RELLOC_DEPRESSED
 *    EEC_RELLOC_DEPTH_KNOWN
 *    EEC_RELLOC_DEPTH_KNOWN_CLEARED
 *    EEC_RELLOC_DEPTH_UNKNOWN
 *    EEC_RELLOC_DEPTH_UNKNOWN_BUT_SAFE
 *    EEC_RELLOC_ELEVATED
 *    EEC_RELLOC_EXACT_POSITION_KNOWN
 *    EEC_RELLOC_EXACT_POSITION_UNKNOWN
 *    EEC_RELLOC_FUNNEL_SHOWING
 *    EEC_RELLOC_HEIGHT_ABOVE_BOTTOM
 *    EEC_RELLOC_HULL_SHOWING
 *    EEC_RELLOC_INLAND
 *    EEC_RELLOC_MASTS_AND_FUNNEL_SHOWING
 *    EEC_RELLOC_MASTS_SHOWING
 *    EEC_RELLOC_NON_FLOATING
 *    EEC_RELLOC_NOT_SUBMERGED
 *    EEC_RELLOC_OFFSHORE
 *    EEC_RELLOC_ON_STRUCTURE
 *    EEC_RELLOC_ON_TERRAIN
 *    EEC_RELLOC_ON_TOWER
 *    EEC_RELLOC_ON_VEHICLE
 *    EEC_RELLOC_ON_WTR_BODY_FLOOR
 *    EEC_RELLOC_ON_WTR_BODY_SURFACE
 *    EEC_RELLOC_OVERHEAD
 *    EEC_RELLOC_PARTIALLY_SUBMERGED
 *    EEC_RELLOC_SUPERSTRUCTURE_SHOWING
 *    EEC_RELLOC_UNDERGROUND
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_RELATIVE_LOCATION ((EDCS_Attribute_Code)1093)

/*
 * Definition:
 *     The angular distance about the vertical axis of an <OBJECT> measured
 *     in the local horizontal plane from the positive x-axis of an external
 *     (relative) coordinate system clockwise (viewed from above) to the
 *     major (longitudinal) axis of the <OBJECT>; the relative orientation
 *     angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_RELATIVE_ORIENTATION_ANGLE ((EDCS_Attribute_Code)1094)

/*
 * Definition:
 *     The vertical accuracy of a <LOCATION> relative to another vertical
 *     <LOCATION>, expressed in units of length at 90% linear error.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_RELATIVE_VERTICAL_ACCURACY ((EDCS_Attribute_Code)1095)

/*
 * Definition:
 *     The releasability restrictions of information about an <OBJECT>.
 *
 * Value Type: STRING
 *
 * Group Membership: COMMUNICATION
 */
#define EAC_RELEASABILITY_RESTRICTIONS ((EDCS_Attribute_Code)1096)

/*
 * Definition:
 *     A designation denoting a religion or system of belief; the religious
 *     designation.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RELIGDESIG_AGNOSTICISM
 *    EEC_RELIGDESIG_ATHEISM
 *    EEC_RELIGDESIG_BAHAISM
 *    EEC_RELIGDESIG_BUDDHISM
 *    EEC_RELIGDESIG_CAODAISM
 *    EEC_RELIGDESIG_CHINESE_TRADITIONAL
 *    EEC_RELIGDESIG_CHRISTIANITY
 *    EEC_RELIGDESIG_HINDUISM
 *    EEC_RELIGDESIG_ISLAM
 *    EEC_RELIGDESIG_JAINISM
 *    EEC_RELIGDESIG_JUDAISM
 *    EEC_RELIGDESIG_NEO_PAGANISM
 *    EEC_RELIGDESIG_NEW_RELIGIONS
 *    EEC_RELIGDESIG_NON_BUDDHISM
 *    EEC_RELIGDESIG_NON_CHRISTIANITY
 *    EEC_RELIGDESIG_NON_HINDUISM
 *    EEC_RELIGDESIG_NON_ISLAM
 *    EEC_RELIGDESIG_NON_JUDAISM
 *    EEC_RELIGDESIG_PRIMAL_INDIGENOUS
 *    EEC_RELIGDESIG_RASTAFARIANISM
 *    EEC_RELIGDESIG_SCIENTOLOGY
 *    EEC_RELIGDESIG_SHINTO
 *    EEC_RELIGDESIG_SIKHISM
 *    EEC_RELIGDESIG_SPIRITISM
 *    EEC_RELIGDESIG_UNITARIAN_UNIVERSALISM
 *    EEC_RELIGDESIG_YORUBA
 *    EEC_RELIGDESIG_ZOROASTRIANISM
 *
 * Group Membership: RELIGION
 */
#define EAC_RELIGIOUS_DESIGNATION ((EDCS_Attribute_Code)1097)

/*
 * Definition:
 *     The manner that a <RESERVOIR> contains <WATER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RESRVRTY_CONSTRUCTED_BASIN
 *    EEC_RESRVRTY_DAM_IMPOUND
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, INFRASTRUCTURE
 */
#define EAC_RESERVOIR_TYPE ((EDCS_Attribute_Code)1098)

/*
 * Definition:
 *     The power level of acoustic energy in a <WATERBODY> due to reflection
 *     of active acoustic emissions from non-target <OBJECT>s; the
 *     reverberation noise.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_REVERBERATION_NOISE_POWER_LEVEL ((EDCS_Attribute_Code)1099)

/*
 * Definition:
 *     The non-dimensional ratio of the inertial force to the viscous force
 *     in fluid motion, usually ranging between 0,0 and 1,0 x 10^(5); the
 *     Reynolds number.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: FLUID_CONDITION, RATE_OR_RATIO
 */
#define EAC_REYNOLDS_NUMBER ((EDCS_Attribute_Code)1100)

/*
 * Definition:
 *     A characterization of the <DIRECTION>s from an <OBJECT> that produce
 *     the greatest reflectivity potential to electromagnetic radiation; the
 *     radio frequency directivity.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RFDIRECTIVITY_UNIDIRECTIONAL
 *    EEC_RFDIRECTIVITY_BIDIRECTIONAL
 *    EEC_RFDIRECTIVITY_OMNIDIRECTIONAL
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_RF_DIRECTIVITY ((EDCS_Attribute_Code)1101)

/*
 * Definition:
 *     The index of refraction for the propagation of electromagnetic waves
 *     at radio <<FREQUENCY>>s in an <ATMOSPHERE> that has been modified to
 *     account for the curvature of a <PLANETARY_SURFACE>. The index of
 *     refraction is the ratio of the <<WAVELENGTH>> or phase velocity of an
 *     electromagnetic wave in a vacuum to that in the medium or substance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_RF_REFRACTIVE_INDEX_MODIFIED ((EDCS_Attribute_Code)1102)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing a linearly-scaled
 *     fraction specifying the blue component of a colour measurement in the
 *     RGB colour model.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ALGORITHM_RELATED, COLOUR, RATE_OR_RATIO
 */
#define EAC_RGB_COLOUR_BLUE ((EDCS_Attribute_Code)1103)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing a linearly-scaled
 *     fraction specifying the green component of a colour measurement in
 *     the RGB colour model.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ALGORITHM_RELATED, COLOUR, RATE_OR_RATIO
 */
#define EAC_RGB_COLOUR_GREEN ((EDCS_Attribute_Code)1104)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing a linearly-scaled
 *     fraction specifying the red component of a colour measurement in the
 *     RGB colour model.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ALGORITHM_RELATED, COLOUR, RATE_OR_RATIO
 */
#define EAC_RGB_COLOUR_RED ((EDCS_Attribute_Code)1105)

/*
 * Definition:
 *     The angle from the horizontal plane to the portion above the mean
 *     level of the <WATERBODY_SURFACE> of the right <WATERBODY_BANK>
 *     (facing downstream) of a <WATERCOURSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_RIGHT_ABOVE_BANK_ANGLE ((EDCS_Attribute_Code)1106)

/*
 * Definition:
 *     The <<TERRAIN_SLOPE>> of the portion above the mean level of the
 *     <WATERBODY_SURFACE> of the right <WATERBODY_BANK> (facing downstream)
 *     of a <WATERCOURSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_RIGHT_ABOVE_BANK_SLOPE ((EDCS_Attribute_Code)1107)

/*
 * Definition:
 *     The <<HEIGHT>> of the right <WATERBODY_BANK> (facing downstream) of a
 *     <WATERCOURSE> measured from the mean level of the <WATER> to the
 *     first break in <<TERRAIN_SLOPE>> above the mean level of the <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_RIGHT_BANK_HEIGHT ((EDCS_Attribute_Code)1108)

/*
 * Definition:
 *     The <<TERRAIN_SLOPE>> of the right <WATERBODY_BANK> (facing
 *     downstream) of a <WATERCOURSE> measured from the mean level of the
 *     <WATER> to the first accessible break in slope above the mean level
 *     of the <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_RIGHT_BANK_SLOPE ((EDCS_Attribute_Code)1109)

/*
 * Definition:
 *     The <<SOIL_CONE_INDEX>> of a right <WATERBODY_BANK>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: MATERIAL, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define EAC_RIGHT_BANK_SOIL_CONE_INDEX ((EDCS_Attribute_Code)1110)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional density of <VEGETATION> found on the right
 *     <WATERBODY_BANK> (facing downstream) of a <WATERCOURSE> as a
 *     linearly-scaled fraction of bank <<AREA>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIVING_ORGANISM, PLANT, RATE_OR_RATIO
 */
#define EAC_RIGHT_BANK_VEGETATION_DENSITY ((EDCS_Attribute_Code)1111)

/*
 * Definition:
 *     The angle from the horizontal plane to the portion below the mean
 *     level of the <WATERBODY_SURFACE> of the right <WATERBODY_BANK>
 *     (facing downstream) of a <WATERCOURSE>, below the mean level of the
 *     <WATER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_RIGHT_BELOW_BANK_ANGLE ((EDCS_Attribute_Code)1112)

/*
 * Definition:
 *     The <<TERRAIN_SLOPE>> of the portion below the mean level of the
 *     <WATERBODY_SURFACE> of the right <WATERBODY_BANK> (facing downstream)
 *     of a <WATERCOURSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_RIGHT_BELOW_BANK_SLOPE ((EDCS_Attribute_Code)1113)

/*
 * Definition:
 *     The <<TERRAIN_SLOPE>> of the right bank of a <TERRAIN_SURFACE_OBJECT>
 *     (for example: a <TERRAIN_CUT> and/or an <EMBANKMENT>).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: PHYSIOGRAPHY, RATE_OR_RATIO
 */
#define EAC_RIGHT_TERRAIN_BANK_SLOPE ((EDCS_Attribute_Code)1114)

/*
 * Definition:
 *     An indication that a <RIP_CURRENT> is present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define EAC_RIP_CURRENT_PRESENT ((EDCS_Attribute_Code)1115)

/*
 * Definition:
 *     The <<WATER_CURRENT_SPEED>> of a <RIP_CURRENT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_RIP_CURRENT_SPEED ((EDCS_Attribute_Code)1116)

/*
 * Definition:
 *     The physical arrangement of a <ROAD_INTERCHANGE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RDINTCHGTY_CLOVERLEAF
 *    EEC_RDINTCHGTY_DIAMOND
 *    EEC_RDINTCHGTY_FORK
 *    EEC_RDINTCHGTY_ROUNDABOUT
 *    EEC_RDINTCHGTY_STAGGERED_RAMPS
 *    EEC_RDINTCHGTY_STANDARD_RAMPS
 *    EEC_RDINTCHGTY_SYMMETRICAL_RAMPS
 *    EEC_RDINTCHGTY_TRUMPET
 *    EEC_RDINTCHGTY_TURBAN
 *    EEC_RDINTCHGTY_WYE
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_INTERCHANGE_TYPE ((EDCS_Attribute_Code)1117)

/*
 * Definition:
 *     The type of connectivity among <ROAD>s meeting at a junction.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RDJUNCCONNY_FULL
 *    EEC_RDJUNCCONNY_RESTRICTED
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_JUNCTION_CONNECTIVITY ((EDCS_Attribute_Code)1118)

/*
 * Definition:
 *     The type of adjacency of a <ROUTE_LANE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RDLANEADJ_BOTH
 *    EEC_RDLANEADJ_LEFT
 *    EEC_RDLANEADJ_NONE_ADJACENT
 *    EEC_RDLANEADJ_RIGHT
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_LANE_ADJACENCY ((EDCS_Attribute_Code)1119)

/*
 * Definition:
 *     The type of traffic control at the end of a <ROUTE_LANE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RDLANECTRLTY_STOP_SIGN
 *    EEC_RDLANECTRLTY_TRAFFIC_LIGHT
 *    EEC_RDLANECTRLTY_YIELD_SIGN
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_LANE_CONTROL_TYPE ((EDCS_Attribute_Code)1120)

/*
 * Definition:
 *     The state of the traffic <LIGHT> at the end of a <ROUTE_LANE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RDLANELGTSTATE_FLASHING_RED
 *    EEC_RDLANELGTSTATE_FLASHING_YELLOW
 *    EEC_RDLANELGTSTATE_GREEN
 *    EEC_RDLANELGTSTATE_GREEN_NO_TURN_ARROW
 *    EEC_RDLANELGTSTATE_GREEN_TURN_ARROW
 *    EEC_RDLANELGTSTATE_RED
 *    EEC_RDLANELGTSTATE_YELLOW
 *
 * Group Membership: LAND_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_ROAD_LANE_LIGHT_STATE ((EDCS_Attribute_Code)1121)

/*
 * Definition:
 *     The type of passing allowed on a <ROUTE_LANE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RDLANEPASSING_BOTH
 *    EEC_RDLANEPASSING_LEFT
 *    EEC_RDLANEPASSING_NONE_ALLOWED
 *    EEC_RDLANEPASSING_RIGHT
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_LANE_PASSING ((EDCS_Attribute_Code)1122)

/*
 * Definition:
 *     The turning <DIRECTION> allowed at the end of a <ROUTE_LANE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RDLANETURN_LEFT_U_TURN_THROUGH
 *    EEC_RDLANETURN_LEFT_TURN_THROUGH
 *    EEC_RDLANETURN_LEFT_ONLY
 *    EEC_RDLANETURN_NONE_ALLOWED
 *    EEC_RDLANETURN_RIGHT_LEFT_U_TURN_THROUGH
 *    EEC_RDLANETURN_RIGHT_LEFT_THROUGH
 *    EEC_RDLANETURN_RIGHT_LEFT_TURN_ONLY
 *    EEC_RDLANETURN_RIGHT_U_TURN_THROUGH
 *    EEC_RDLANETURN_RIGHT_TURN_THROUGH
 *    EEC_RDLANETURN_RIGHT_ONLY
 *    EEC_RDLANETURN_U_TURN_THROUGH
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_LANE_TURN ((EDCS_Attribute_Code)1123)

/*
 * Definition:
 *     An indication that a <ROAD> is illuminated by <STREET_LAMP>s; road
 *     lighting present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LAND_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_ROAD_LIGHTING_PRESENT ((EDCS_Attribute_Code)1124)

/*
 * Definition:
 *     The minimum <<WIDTH>> the travelled way of a <ROAD>. The value is the
 *     sum of the <<WIDTH>>s of included <ROUTE_LANE>s. The <<WIDTH>>s of
 *     adjacent hard paved shoulders, <SIDEWALK>s, and other pathways are
 *     excluded.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_MINIMUM_TRAVELLED_WAY_WIDTH ((EDCS_Attribute_Code)1125)

/*
 * Definition:
 *     The <<WIDTH>> of a second travelled way that is the lesser <<WIDTH>>
 *     of the two travelled ways in a divided <ROAD>. The value is the sum
 *     of the <<WIDTH>>s of included <ROUTE_LANE>s. The <<WIDTH>>s of
 *     adjacent hard paved shoulders, <SIDEWALK>s, and other pathways are
 *     excluded.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_SECOND_TRAVELLED_WAY_WIDTH ((EDCS_Attribute_Code)1126)

/*
 * Definition:
 *     The total usable <<WIDTH>> of a travelled way of a <ROAD>. The value
 *     is the sum of the <<WIDTH>>s of included <ROUTE_LANE>s, adjacent hard
 *     paved shoulders, unobstructed hard paved median, <SIDEWALK>s, and
 *     other pathways. The <<WIDTH>>s of parking lots, turn-offs, and
 *     unpaved medians are excluded.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_TOTAL_USABLE_WIDTH ((EDCS_Attribute_Code)1127)

/*
 * Definition:
 *     The type of a <ROAD>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RDTY_RAPID_TRANSIT
 *    EEC_RDTY_SERVICE_LANE
 *    EEC_RDTY_STREET
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROAD_TYPE ((EDCS_Attribute_Code)1128)

/*
 * Definition:
 *     The structure of a <ROCKY_OUTCROP> or other formation of <ROCK>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROCKFORMSTR_COLUMNAR
 *    EEC_ROCKFORMSTR_NEEDLE
 *    EEC_ROCKFORMSTR_PINNACLE
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_ROCK_FORMATION_STRUCTURE ((EDCS_Attribute_Code)1129)

/*
 * Definition:
 *     The angular distance about the forward axis of an <OBJECT> measured in
 *     the local vertical plane from the local vertical clockwise to the
 *     vertical axis of the <OBJECT>. The forward axis of the <OBJECT> is
 *     the axis that passes through the centre of the <OBJECT> and is
 *     directed towards/through the forward part or <SURFACE> (front) of the
 *     <OBJECT>. Clockwise rotation about the forward axis (the axis of
 *     roll) is determined in the <DIRECTION> of the front of the <OBJECT>
 *     (right hand rule). The vertical axis of the <OBJECT> is normal to its
 *     forward axis.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_ROLL_ANGLE ((EDCS_Attribute_Code)1130)

/*
 * Definition:
 *     The type of a rolling-stock.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROLLSTOCKTY_BOLSTER
 *    EEC_ROLLSTOCKTY_BOX
 *    EEC_ROLLSTOCKTY_BUFFER
 *    EEC_ROLLSTOCKTY_BUFFET
 *    EEC_ROLLSTOCKTY_CABOOSE
 *    EEC_ROLLSTOCKTY_COACH
 *    EEC_ROLLSTOCKTY_COVERED_HOPPER
 *    EEC_ROLLSTOCKTY_CRYOGENIC
 *    EEC_ROLLSTOCKTY_DEPRESSED_CENTRE
 *    EEC_ROLLSTOCKTY_DINING
 *    EEC_ROLLSTOCKTY_FLAT
 *    EEC_ROLLSTOCKTY_FREIGHT
 *    EEC_ROLLSTOCKTY_GONDOLA
 *    EEC_ROLLSTOCKTY_HEAVY_DUTY
 *    EEC_ROLLSTOCKTY_HOPPER
 *    EEC_ROLLSTOCKTY_IDLER
 *    EEC_ROLLSTOCKTY_LOCOMOTIVE_ENGINE
 *    EEC_ROLLSTOCKTY_NON_PRESSURE_TANK
 *    EEC_ROLLSTOCKTY_OBSERVATION
 *    EEC_ROLLSTOCKTY_OPEN_TOPPED_HOPPER
 *    EEC_ROLLSTOCKTY_PNEUMATIC_HOPPER
 *    EEC_ROLLSTOCKTY_PRESSURE_TANK
 *    EEC_ROLLSTOCKTY_SCHNABEL
 *    EEC_ROLLSTOCKTY_SLEEPING
 *    EEC_ROLLSTOCKTY_TUBE
 *    EEC_ROLLSTOCKTY_VAN
 *    EEC_ROLLSTOCKTY_WELL
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define EAC_ROLLING_STOCK_TYPE ((EDCS_Attribute_Code)1131)

/*
 * Definition:
 *     The type of a <ROOF_ASSEMBLY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROOFASMBLTY_ASPHALT_SHINGLE
 *    EEC_ROOFASMBLTY_BUILT_UP_ACRYLIC
 *    EEC_ROOFASMBLTY_BUILT_UP_AGGREGATE
 *    EEC_ROOFASMBLTY_BUILT_UP_ASPHALT
 *    EEC_ROOFASMBLTY_BUILT_UP_COAL_TAR
 *    EEC_ROOFASMBLTY_BUILT_UP_FABRIC
 *    EEC_ROOFASMBLTY_BUILT_UP_GLASS_MAT
 *    EEC_ROOFASMBLTY_BUILT_UP_MINERAL_SURFACE_INORGANIC_CAP_SHEET
 *    EEC_ROOFASMBLTY_CLAY_AND_CONCRETE_TILE
 *    EEC_ROOFASMBLTY_LIQUID_APPLIED
 *    EEC_ROOFASMBLTY_METAL_PANEL_AND_SHINGLE
 *    EEC_ROOFASMBLTY_MINERAL_SURFACED_ROLL_ROOFING
 *    EEC_ROOFASMBLTY_POLYMER_MODIFIED_BITUMEM
 *    EEC_ROOFASMBLTY_SLATE
 *    EEC_ROOFASMBLTY_SPRAY_POLYURETHANE_FOAM
 *    EEC_ROOFASMBLTY_THATCH
 *    EEC_ROOFASMBLTY_THERMOSET_SINGLE_PLY
 *    EEC_ROOFASMBLTY_WOOD_SHAKE
 *    EEC_ROOFASMBLTY_WOOD_SHINGLE
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_ROOF_ASSEMBLY_TYPE ((EDCS_Attribute_Code)1132)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional <<AREA>> of a <TRACT> that is covered by <ROOF>s. Zero
 *     means no <ROOF>s are present and one means the <REGION> of <LAND> is
 *     completely covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: BUILDING_COMPONENT, RATE_OR_RATIO
 */
#define EAC_ROOF_COVER_FRACTION ((EDCS_Attribute_Code)1133)

/*
 * Definition:
 *     The framing type of a <ROOF>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROOFFRAMINGTY_CONCRETE_OVER_STEEL_DECK
 *    EEC_ROOFFRAMINGTY_CONCRETE_SLAB
 *    EEC_ROOFFRAMINGTY_CUT_ROOF
 *    EEC_ROOFFRAMINGTY_METAL_TRUSS
 *    EEC_ROOFFRAMINGTY_WOOD_TRUSS
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_ROOF_FRAMING_TYPE ((EDCS_Attribute_Code)1134)

/*
 * Definition:
 *     The maximum load per unit <<AREA>> that a <ROOF> can support; the load
 *     bearing capacity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: BUILDING_COMPONENT, RATE_OR_RATIO
 */
#define EAC_ROOF_LOAD_BEARING_CAPACITY ((EDCS_Attribute_Code)1135)

/*
 * Definition:
 *     The predominant visual pattern of the <SURFACE> of a <ROOF>. The value
 *     usually describes the shape and arrangement of shingles, but may also
 *     describe smooth, corrugated, and gravel <ROOF>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROOFPREDPAT_BAMBOO
 *    EEC_ROOFPREDPAT_CORRUGATED
 *    EEC_ROOFPREDPAT_DIAMOND
 *    EEC_ROOFPREDPAT_FISHSCALE
 *    EEC_ROOFPREDPAT_GRAVEL
 *    EEC_ROOFPREDPAT_MOSAIC
 *    EEC_ROOFPREDPAT_MOTTLED
 *    EEC_ROOFPREDPAT_MULTIPLE_PATTERNS_PRESENT
 *    EEC_ROOFPREDPAT_NO_PATTERN_PRESENT
 *    EEC_ROOFPREDPAT_OCTAGON
 *    EEC_ROOFPREDPAT_RECTANGULAR
 *    EEC_ROOFPREDPAT_REGULAR
 *    EEC_ROOFPREDPAT_SLATE
 *    EEC_ROOFPREDPAT_SMOOTH
 *    EEC_ROOFPREDPAT_SOIL
 *    EEC_ROOFPREDPAT_SQUARE
 *    EEC_ROOFPREDPAT_THATCH
 *
 * Group Membership: BUILDING_COMPONENT, SURFACE
 */
#define EAC_ROOF_PREDOMINANT_PATTERN ((EDCS_Attribute_Code)1136)

/*
 * Definition:
 *     The predominant outermost <MATERIAL> of which the <SURFACE> of a
 *     <ROOF> is constructed.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROOFPREDSRFMAT_ALUMINUM
 *    EEC_ROOFPREDSRFMAT_ASPHALT
 *    EEC_ROOFPREDSRFMAT_CEMENT
 *    EEC_ROOFPREDSRFMAT_CINDER
 *    EEC_ROOFPREDSRFMAT_CLAY
 *    EEC_ROOFPREDSRFMAT_COBBLE
 *    EEC_ROOFPREDSRFMAT_CONCRETE
 *    EEC_ROOFPREDSRFMAT_CONGLOMERATE
 *    EEC_ROOFPREDSRFMAT_COPPER
 *    EEC_ROOFPREDSRFMAT_GLASS
 *    EEC_ROOFPREDSRFMAT_GRAVEL
 *    EEC_ROOFPREDSRFMAT_IRON
 *    EEC_ROOFPREDSRFMAT_LEAD
 *    EEC_ROOFPREDSRFMAT_MARBLE
 *    EEC_ROOFPREDSRFMAT_METAL
 *    EEC_ROOFPREDSRFMAT_MULTIPLE_MATERIALS
 *    EEC_ROOFPREDSRFMAT_NO_ROOF
 *    EEC_ROOFPREDSRFMAT_PLANT_MATERIAL
 *    EEC_ROOFPREDSRFMAT_PLASTIC
 *    EEC_ROOFPREDSRFMAT_REINFORCED_CONCRETE
 *    EEC_ROOFPREDSRFMAT_SAND_AND_GRAVEL
 *    EEC_ROOFPREDSRFMAT_SHINGLE
 *    EEC_ROOFPREDSRFMAT_SOD
 *    EEC_ROOFPREDSRFMAT_SOD_OR_THATCH
 *    EEC_ROOFPREDSRFMAT_STEEL
 *    EEC_ROOFPREDSRFMAT_THATCH
 *    EEC_ROOFPREDSRFMAT_WOOD
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL, SURFACE, SURFACE_MATERIAL
 */
#define EAC_ROOF_PREDOMINANT_SURFACE_MATERIAL ((EDCS_Attribute_Code)1137)

/*
 * Definition:
 *     The shape of a <ROOF>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROOFSHAP_CURVED
 *    EEC_ROOFSHAP_DOME
 *    EEC_ROOFSHAP_FLAT
 *    EEC_ROOFSHAP_FLAT_WITH_CLERESTORY
 *    EEC_ROOFSHAP_FLAT_WITH_SMOKESTACKS
 *    EEC_ROOFSHAP_FLAT_WITH_TOWER_AND_CLERESTORY
 *    EEC_ROOFSHAP_GABLE_PITCHED
 *    EEC_ROOFSHAP_GABLE_WITH_CLERESTORY
 *    EEC_ROOFSHAP_GABLE_WITH_TOWER
 *    EEC_ROOFSHAP_MULTIPLE_SURFACES
 *    EEC_ROOFSHAP_NO_CLERESTORY
 *    EEC_ROOFSHAP_NO_ROOF_PRESENT
 *    EEC_ROOFSHAP_PEAKED
 *    EEC_ROOFSHAP_SAWTOOTH
 *    EEC_ROOFSHAP_VARIED_LEVELS
 *    EEC_ROOFSHAP_WITH_CLERESTORY
 *    EEC_ROOFSHAP_WITH_CUPOLA
 *    EEC_ROOFSHAP_WITH_LONGITUDINAL_MONITOR
 *    EEC_ROOFSHAP_WITH_MINARET
 *    EEC_ROOFSHAP_WITH_MODIFIED_CLERESTORY
 *    EEC_ROOFSHAP_WITH_STEEPLE
 *    EEC_ROOFSHAP_WITH_TOWER
 *    EEC_ROOFSHAP_WITH_TRANSVERSE_CLERESTORY
 *    EEC_ROOFSHAP_WITH_TURRET
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_ROOF_SHAPE ((EDCS_Attribute_Code)1138)

/*
 * Definition:
 *     The type of <MATERIAL> overlaid on the frame of a <ROOF> to which the
 *     roofing <MATERIAL> is then attached; the roof sheathing type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROOFSHTHTY_DIMENSION_LUMBER
 *    EEC_ROOFSHTHTY_ENGINEERED_LUMBER
 *    EEC_ROOFSHTHTY_METAL_SHEET
 *    EEC_ROOFSHTHTY_REINFORCED_CONCRETE
 *    EEC_ROOFSHTHTY_NONE_PRESENT
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_ROOF_SHEATHING_TYPE ((EDCS_Attribute_Code)1139)

/*
 * Definition:
 *     The architectural style of a <ROOF>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ROOFSTYLE_CONICAL
 *    EEC_ROOFSTYLE_CROSS_GABLE
 *    EEC_ROOFSTYLE_FLAT
 *    EEC_ROOFSTYLE_GABLE
 *    EEC_ROOFSTYLE_GAMBREL
 *    EEC_ROOFSTYLE_HIP
 *    EEC_ROOFSTYLE_HIP_AND_GABLE
 *    EEC_ROOFSTYLE_HIP_ON_GABLE
 *    EEC_ROOFSTYLE_HIP_WITH_CROSS_GABLES
 *    EEC_ROOFSTYLE_KICKED_EAVES
 *    EEC_ROOFSTYLE_MANSARD
 *    EEC_ROOFSTYLE_PYRAMID
 *    EEC_ROOFSTYLE_SALT_BOX
 *    EEC_ROOFSTYLE_SHED
 *    EEC_ROOFSTYLE_DOMED
 *    EEC_ROOFSTYLE_NO_ROOF
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_ROOF_STYLE ((EDCS_Attribute_Code)1140)

/*
 * Definition:
 *     The type of <MATERIAL> and/or techniques used to construct a
 *     <ROOM_CEILING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RMCEILCNSTCTTY_DIMENSION_LUMBER
 *    EEC_RMCEILCNSTCTTY_DROPPED_CEILING_WITH_TILES
 *    EEC_RMCEILCNSTCTTY_ENGINEERED_LUMBER
 *    EEC_RMCEILCNSTCTTY_GYPSUM_WALLBOARD
 *    EEC_RMCEILCNSTCTTY_LATH_AND_PLASTER
 *    EEC_RMCEILCNSTCTTY_REINFORCED_CONCRETE
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_ROOM_CEILING_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)1141)

/*
 * Definition:
 *     The alternative official designation assigned to a
 *     <LAND_TRANSPORTATION_ROUTE>. EXAMPLES "I-95", "A-1", "M-2".
 *
 * Value Type: STRING
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROUTE_ALTERNATIVE_DESIGNATION ((EDCS_Attribute_Code)1142)

/*
 * Definition:
 *     The type of a <ROUTE_CONSTRICTION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RTECONSTY_BUILDING_PASSAGE
 *    EEC_RTECONSTY_GATEWAY
 *    EEC_RTECONSTY_NARROW_PASS
 *    EEC_RTECONSTY_UNDERPASS
 *
 * Group Membership: TRNSP
 */
#define EAC_ROUTE_CONSTRICTION_TYPE ((EDCS_Attribute_Code)1143)

/*
 * Definition:
 *     The type of shape attributed to the crossing of two or more
 *     <TRANSPORTATION_ROUTE>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RTECROSSINGTY_INTERSECTION
 *    EEC_RTECROSSINGTY_STAR_SHAPED_BRANCHING
 *    EEC_RTECROSSINGTY_T_JUNCTION
 *
 * Group Membership: TRNSP
 */
#define EAC_ROUTE_CROSSING_TYPE ((EDCS_Attribute_Code)1144)

/*
 * Definition:
 *     The official designation assigned to a <LAND_TRANSPORTATION_ROUTE>.
 *     EXAMPLES "I-95", "M-2", "A-1".
 *
 * Value Type: STRING
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_ROUTE_DESIGNATION ((EDCS_Attribute_Code)1145)

/*
 * Definition:
 *     The type of a <ROUTE_EXPANSION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RTEEXPNTY_ROAD_SIDING
 *
 * Group Membership: TRNSP
 */
#define EAC_ROUTE_EXPANSION_TYPE ((EDCS_Attribute_Code)1146)

/*
 * Definition:
 *     The weather conditions under which a <LAND_TRANSPORTATION_ROUTE> is
 *     passable or remains open.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RTEWXTY_ALL_WEATHER
 *    EEC_RTEWXTY_FAIR_WEATHER
 *    EEC_RTEWXTY_LIMITED_ALL_WEATHER
 *
 * Group Membership: ATMOSPHERE, LAND_TRNSP, TRNSP
 */
#define EAC_ROUTE_WEATHER_TYPE ((EDCS_Attribute_Code)1147)

/*
 * Definition:
 *     The number of rows comprising an <OBJECT>; the row count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_ROW_COUNT ((EDCS_Attribute_Code)1148)

/*
 * Definition:
 *     The distance between each row comprising an <OBJECT>; may be either a
 *     mean value, or a constant value where rows are equally spaced.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_ROW_DISTANCE ((EDCS_Attribute_Code)1149)

/*
 * Definition:
 *     The distance between the <COMPONENT>s within each row comprising an
 *     <OBJECT>. The distance may be either a mean value or a constant value
 *     when <COMPONENT>s are equally spaced within a row; the row spacing
 *     internal.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_ROW_SPACING_INTERNAL ((EDCS_Attribute_Code)1150)

/*
 * Definition:
 *     The ability of <RUBBLE> to resist sliding or collapsing under stress;
 *     the rubble stability.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RUBBLESTAB_LOOSE
 *    EEC_RUBBLESTAB_CONSOLIDATED
 *
 * Group Membership: MATERIAL
 */
#define EAC_RUBBLE_STABILITY ((EDCS_Attribute_Code)1151)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the angle of approach indicator <LIGHT>s (for
 *     example: VASI and/or PAPI) on a <RUNWAY>. Zero means minimum
 *     intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_APPROACH_ANGLE_LIGHT_INTENSITY ((EDCS_Attribute_Code)1152)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the approach <LIGHT>s on a <RUNWAY>. Zero
 *     means minimum intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_APPROACH_LIGHT_INTENSITY ((EDCS_Attribute_Code)1153)

/*
 * Definition:
 *     The section distance from the beginning of a <RUNWAY_APPROACH_OIS>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, DIMENSION, TRNSP
 */
#define EAC_RUNWAY_APPROACH_OIS_DISTANCE ((EDCS_Attribute_Code)1154)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the <LIGHT>s that mark the centre-line of a
 *     <RUNWAY>. Zero means minimum intensity and one means maximum
 *     intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_CENTRE_LIGHT_INTENSITY ((EDCS_Attribute_Code)1155)

/*
 * Definition:
 *     The number of <RUNWAY>s at an <AERODROME>; the runway count.
 *
 * Value Type: COUNT
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_RUNWAY_COUNT ((EDCS_Attribute_Code)1156)

/*
 * Definition:
 *     The distance from the <RUNWAY_ENDPOINT> to that point of the <RUNWAY>
 *     usable for landing; the displaced threshold distance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, DIMENSION, TRNSP
 */
#define EAC_RUNWAY_DISPLACED_THRESHOLD_DISTANCE ((EDCS_Attribute_Code)1157)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the edge <LIGHT>s on a <RUNWAY>. Zero means
 *     minimum intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_EDGE_LIGHT_INTENSITY ((EDCS_Attribute_Code)1158)

/*
 * Definition:
 *     An indication of the <<TERRAIN_ELEVATION>> of the end of a <RUNWAY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RNWYEND_HIGH
 *    EEC_RNWYEND_LOW
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_RUNWAY_END ((EDCS_Attribute_Code)1159)

/*
 * Definition:
 *     A two character string containing two decimal digits between "01" to
 *     "36" inclusive and defined as follows. When there is a single
 *     <RUNWAY>, two parallel <RUNWAY>s, or three parallel <RUNWAY>s, the
 *     two digit whole number nearest to one-tenth of the
 *     <<MAGNETIC_AZIMUTH>> (for example: a <<MAGNETIC_AZIMUTH>> of 274
 *     degrees would be represented as "27") of the centre-line of the
 *     <RUNWAY> in the direction of approach; the runway end bearing. When
 *     there are four to six parallel runways, one set of two or three
 *     adjacent runways shall be numbered with the two digit whole number
 *     nearest to one-tenth of the magnetic azimuth and the other set of two
 *     or three adjacent runways numbered to the next nearest whole number.
 *     When these rules would give a single digit number, it shall be
 *     preceded by a zero.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: AIR_TRNSP, ANGULAR_MEASURE, TRNSP
 */
#define EAC_RUNWAY_END_BEARING ((EDCS_Attribute_Code)1160)

/*
 * Definition:
 *     The <<ELEVATION>> of a <RUNWAY_ENDPOINT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define EAC_RUNWAY_ENDPOINT_ELEVATION ((EDCS_Attribute_Code)1161)

/*
 * Definition:
 *     The higher degree identification of a <RUNWAY>. The value is formatted
 *     in a Basic Latin string that begins with a two-character identifier
 *     ranging from 19-36, determined from the approach direction, derived
 *     from the <RUNWAY> magnetic heading (high end) rounded to the nearest
 *     ten arc degrees, and divided by ten; the runway high end identifier.
 *     Designated in accordance with appropriate host nation documents.
 *     Analyst derived <RUNWAY> numbers will use six arc degrees as the
 *     break off point for the next highest number. In the case of parallel
 *     runways, a third character is added to differentiate between left
 *     (L), right (R), centre (C), or STOL (S) <RUNWAY> positions. A fourth
 *     character, (T) True is added when the <RUNWAY> identifier and heading
 *     are true with no magnetic variation applied.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_RUNWAY_HIGH_END_IDENTIFIER ((EDCS_Attribute_Code)1162)

/*
 * Definition:
 *     The identification of a <RUNWAY>. The value is formatted in a Basic
 *     Latin string that begins with a two-character identifier ranging from
 *     01-36, derived from the <RUNWAY> geodetic heading, rounded to the
 *     nearest ten arc degrees and divided by ten. In the case of parallel
 *     <RUNWAY>s, a third character is added to differentiate between left
 *     (L), right (R), centre (C), or STOL (S) <RUNWAY> positions.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_RUNWAY_IDENTIFIER ((EDCS_Attribute_Code)1163)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the <LIGHTING> on a <RUNWAY>. Zero means
 *     minimum intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_LIGHTING_INTENSITY ((EDCS_Attribute_Code)1164)

/*
 * Definition:
 *     The lower degree identification of a <RUNWAY>. The value is formatted
 *     in a Basic Latin string that begins with a two-character identifier
 *     ranging from 01-18, determined from the approach direction, derived
 *     from the <RUNWAY> magnetic heading (low end) rounded to the nearest
 *     ten arc degrees and divided by ten; the runway low end identifier.
 *     Designated in accordance with appropriate host nation documents.
 *     Analyst derived <RUNWAY> numbers will use six arc degrees as the
 *     break off point for the next highest number. In the case of parallel
 *     <RUNWAY>s, a third character is added to differentiate between left
 *     (L), right (R), centre (C), and STOL (S) runway positions. A fourth
 *     character (T) True is added when the <RUNWAY> identifier and heading
 *     are true with no magnetic variation applied.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_RUNWAY_LOW_END_IDENTIFIER ((EDCS_Attribute_Code)1165)

/*
 * Definition:
 *     A number identifying a quadrant of a <RUNWAY> OIS as defined by the
 *     centre-line of the <RUNWAY> and a perpendicular to the centre-line of
 *     the <RUNWAY> intersecting at the centre point of the <RUNWAY>. The
 *     centre point of the <RUNWAY> is defined as falling midway between the
 *     <RUNWAY_ENDPOINT>s. Quadrant identifiers are assigned such that
 *     quadrants 1 and 2 are on one side and quadrants 3 and 4 are on the
 *     other side of the centre-line of the <RUNWAY>. Quadrant identifiers
 *     only apply to the following imaginary air navigation OISs of
 *     <RUNWAY>s: inner horizontal, conical, and outer horizontal.
 *
 * Value Type: INDEX
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_RUNWAY_OIS_QUADRANT ((EDCS_Attribute_Code)1166)

/*
 * Definition:
 *     The type of offline <OBJECT> to which the point on a <RUNWAY> is abeam.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RNWYPTABEAMTY_GLIDE_SLOPE
 *    EEC_RNWYPTABEAMTY_LOCALIZER
 *    EEC_RNWYPTABEAMTY_MLS_AZIMUTH_GUIDE
 *    EEC_RNWYPTABEAMTY_MLS_ELEVATION_GUIDE
 *    EEC_RNWYPTABEAMTY_OFFSET_LOCALIZER_DIRECTION_AID
 *    EEC_RNWYPTABEAMTY_OFFSET_SIMPLIFIED_DIRECTIONAL_FACILITY
 *    EEC_RNWYPTABEAMTY_PAR
 *    EEC_RNWYPTABEAMTY_PAR_TOUCHDOWN_REFLECTOR
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_RUNWAY_POINT_ABEAM_TYPE ((EDCS_Attribute_Code)1167)

/*
 * Definition:
 *     A number identifying a section of the imaginary <RUNWAY> air
 *     navigation primary approach transitional OIS. The <RUNWAY> primary
 *     approach transitional OIS is divided into two groups of sections: (1)
 *     Those sections corresponding to (and lateral of) the <RUNWAY> primary
 *     OIS sections which are (a) the approximately 914,4 metres (3 000
 *     feet) sections starting from the <RUNWAY_ENDPOINT>s and working
 *     inward, and (b) any middle section left over from (a); and (2) Those
 *     sections are lateral of the <RUNWAY> primary OIS and runway approach
 *     OIS, extending from the <RUNWAY> end outward. Each of these sections
 *     is numbered.
 *
 * Value Type: INDEX
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS_SECTION ((EDCS_Attribute_Code)1168)

/*
 * Definition:
 *     A number identifying a section of the imaginary <RUNWAY> air
 *     navigation primary OIS. The <RUNWAY> primary OIS is divided into
 *     sections: (a) the 60,96 metre (200 feet) sections of the <RUNWAY>
 *     primary OIS from the <RUNWAY_ENDPOINT>s and working outward, (b) the
 *     approximately 914,4 metres (3 000 feet) sections starting from the
 *     <RUNWAY_ENDPOINT>s and working inward, and (c) any middle section
 *     left over from (b). Each of these sections is numbered.
 *
 * Value Type: INDEX
 *
 * Group Membership: AIR_TRNSP, IDENTIFICATION, TRNSP
 */
#define EAC_RUNWAY_PRIMARY_OIS_SECTION ((EDCS_Attribute_Code)1169)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the end identifier <LIGHT>s on a <RUNWAY>;
 *     the runway REIL intensity. Zero means unlit and one means maximum
 *     intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_REIL_INTENSITY ((EDCS_Attribute_Code)1170)

/*
 * Definition:
 *     The relative position of a <RUNWAY> in a <SET> of one to three
 *     parallel <RUNWAY>s with a given <<RUNWAY_END_BEARING>> as viewed by
 *     an approaching <AIRCRAFT> to the <SET> of <RUNWAY>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RNWYRELPOS_UNDESIGNATED
 *    EEC_RNWYRELPOS_LEFT
 *    EEC_RNWYRELPOS_CENTRE
 *    EEC_RNWYRELPOS_RIGHT
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define EAC_RUNWAY_RELATIVE_POSITION ((EDCS_Attribute_Code)1171)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the stop bar <LIGHT>s on a <RUNWAY>. Zero
 *     means minimum intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_STOP_BAR_LIGHT_INTENSITY ((EDCS_Attribute_Code)1172)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the strobe <LIGHT>s on a <RUNWAY>. Zero means
 *     minimum intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_STROBE_LIGHT_INTENSITY ((EDCS_Attribute_Code)1173)

/*
 * Definition:
 *     The condition of the <SURFACE> of a <RUNWAY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RNWYSRFCND_CLEAR
 *    EEC_RNWYSRFCND_FLOODED
 *    EEC_RNWYSRFCND_PATCHY_ICE
 *    EEC_RNWYSRFCND_PATCHY_WET
 *    EEC_RNWYSRFCND_SNOW
 *    EEC_RNWYSRFCND_TOTAL_ICE
 *    EEC_RNWYSRFCND_WET_RUBBER
 *
 * Group Membership: AIR_TRNSP, SURFACE, TRNSP
 */
#define EAC_RUNWAY_SURFACE_CONDITION ((EDCS_Attribute_Code)1174)

/*
 * Definition:
 *     The <<LENGTH>> of takeoff distance on a <RUNWAY> plus the <<LENGTH>>
 *     of the <RUNWAY_OVERRUN>, if available.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, DIMENSION, TRNSP
 */
#define EAC_RUNWAY_TAKEOFF_DISTANCE_AVAILABLE ((EDCS_Attribute_Code)1175)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the threshold <LIGHT>s on a <RUNWAY>. Zero
 *     means minimum intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_THRESHOLD_LIGHT_INTENSITY ((EDCS_Attribute_Code)1176)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the touch down <LIGHT>s on a <RUNWAY>. Zero
 *     means minimum intensity and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_RUNWAY_TOUCH_DOWN_LIGHT_INTENSITY ((EDCS_Attribute_Code)1177)

/*
 * Definition:
 *     The highest <<ELEVATION>> in the first 914,4 metres (3 000 feet) of
 *     the end of the usable landing <SURFACE> of a <RUNWAY>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define EAC_RUNWAY_TOUCHDOWN_ZONE_ELEVATION ((EDCS_Attribute_Code)1178)

/*
 * Definition:
 *     The visibility along an identified <RUNWAY> determined from a specific
 *     point on the <RUNWAY> with the observer facing in the same
 *     <DIRECTION> as a pilot using the <RUNWAY>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_RUNWAY_VISIBILITY ((EDCS_Attribute_Code)1179)

/*
 * Definition:
 *     The maximum horizontal distance down an identified <RUNWAY> that a
 *     pilot of an <AIRCRAFT> on the centre-line of the <RUNWAY> can see the
 *     surface <RUNWAY_MARKINGS> or the <LIGHT>s delineating the <RUNWAY> or
 *     identifying the centre-line of the <RUNWAY>; the runway visual range.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_RUNWAY_VISUAL_RANGE ((EDCS_Attribute_Code)1180)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the characteristic alignment of a
 *     <SAND_DUNE> as caused by the prevailing <WIND>s; the sand dune
 *     orientation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, ATMOSPHERE, PHYSIOGRAPHY
 */
#define EAC_SAND_DUNE_ORIENTATION ((EDCS_Attribute_Code)1181)

/*
 * Definition:
 *     The name of a <SATELLITE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SATNAME_ADRASTEA
 *    EEC_SATNAME_AMALTHEA
 *    EEC_SATNAME_ANANKE
 *    EEC_SATNAME_ARIEL
 *    EEC_SATNAME_ATLAS
 *    EEC_SATNAME_BELINDA
 *    EEC_SATNAME_BIANCA
 *    EEC_SATNAME_CALIBAN
 *    EEC_SATNAME_CALLISTO
 *    EEC_SATNAME_CALYPSO
 *    EEC_SATNAME_CARME
 *    EEC_SATNAME_CHARON
 *    EEC_SATNAME_CORDELIA
 *    EEC_SATNAME_CRESSIDA
 *    EEC_SATNAME_DEIMOS
 *    EEC_SATNAME_DESDEMONA
 *    EEC_SATNAME_DESPINA
 *    EEC_SATNAME_DIONE
 *    EEC_SATNAME_ELARA
 *    EEC_SATNAME_ENCELADUS
 *    EEC_SATNAME_EPIMETHEUS
 *    EEC_SATNAME_EUROPA
 *    EEC_SATNAME_GALATEA
 *    EEC_SATNAME_GANYMEDE
 *    EEC_SATNAME_HELENE
 *    EEC_SATNAME_HIMALIA
 *    EEC_SATNAME_HYPERION
 *    EEC_SATNAME_IAPETUS
 *    EEC_SATNAME_IO
 *    EEC_SATNAME_JANUS
 *    EEC_SATNAME_JULIET
 *    EEC_SATNAME_LARISSA
 *    EEC_SATNAME_LEDA
 *    EEC_SATNAME_LYSITHEA
 *    EEC_SATNAME_METIS
 *    EEC_SATNAME_MIMAS
 *    EEC_SATNAME_MIRANDA
 *    EEC_SATNAME_MOON
 *    EEC_SATNAME_NAIAD
 *    EEC_SATNAME_NEREID
 *    EEC_SATNAME_OBERON
 *    EEC_SATNAME_OPHELIA
 *    EEC_SATNAME_PAN
 *    EEC_SATNAME_PANDORA
 *    EEC_SATNAME_PASIPHAE
 *    EEC_SATNAME_PHOBOS
 *    EEC_SATNAME_PHOEBE
 *    EEC_SATNAME_PORTIA
 *    EEC_SATNAME_PROMETHEUS
 *    EEC_SATNAME_PROSPERO
 *    EEC_SATNAME_PROTEUS
 *    EEC_SATNAME_PUCK
 *    EEC_SATNAME_RHEA
 *    EEC_SATNAME_ROSALIND
 *    EEC_SATNAME_SETEBOS
 *    EEC_SATNAME_SINOPE
 *    EEC_SATNAME_STEPHANO
 *    EEC_SATNAME_SYCORAX
 *    EEC_SATNAME_TELESTO
 *    EEC_SATNAME_TETHYS
 *    EEC_SATNAME_THALASSA
 *    EEC_SATNAME_THEBE
 *    EEC_SATNAME_TITAN
 *    EEC_SATNAME_TITANIA
 *    EEC_SATNAME_TRITON
 *    EEC_SATNAME_UMBRIEL
 *
 * Group Membership: IDENTIFICATION, SPACE
 */
#define EAC_SATELLITE_NAME ((EDCS_Attribute_Code)1182)

/*
 * Definition:
 *     A category describing the <<SCND_WEAPON_DEPLOYED_POSITION>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SECWEAPPOSCAT_DEPLOYED
 *    EEC_SECWEAPPOSCAT_IN_FIRING_POSITION
 *    EEC_SECWEAPPOSCAT_NO_WEAPON_PRESENT
 *    EEC_SECWEAPPOSCAT_STOWED
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_SCND_WEAPON_DEPLOYED_POS_CATEGORY ((EDCS_Attribute_Code)1183)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional deployment of the secondary <WEAPON_SYSTEM> of an
 *     <OBJECT>. Zero means fully stowed/retracted and one means fully
 *     deployed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: MILITARY_SCIENCE, RATE_OR_RATIO
 */
#define EAC_SCND_WEAPON_DEPLOYED_POSITION ((EDCS_Attribute_Code)1184)

/*
 * Definition:
 *     The type of scrap.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SCRAPTY_MOTOR_VEHICLE
 *
 * Group Membership: INDUSTRY
 */
#define EAC_SCRAP_TYPE ((EDCS_Attribute_Code)1185)

/*
 * Definition:
 *     The type of <ICE> in the sea.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SEAICETY_DEBRIS_COVERED
 *    EEC_SEAICETY_FAST
 *    EEC_SEAICETY_GLACIER
 *    EEC_SEAICETY_GROWLER
 *    EEC_SEAICETY_NONE_PRESENT
 *    EEC_SEAICETY_PACK
 *    EEC_SEAICETY_PANCAKE
 *    EEC_SEAICETY_PEAK
 *    EEC_SEAICETY_POLAR
 *    EEC_SEAICETY_SEA
 *
 * Group Membership: ICE
 */
#define EAC_SEA_ICE_TYPE ((EDCS_Attribute_Code)1186)

/*
 * Definition:
 *     The name of a major <WATERBODY> (for example: a <SEA>, a
 *     <MARINE_STRAIT>, a <MARINE_GULF>, and/or a <MARINE_BAY>); the sea
 *     name.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SEANAME_ADRIATIC_SEA
 *    EEC_SEANAME_AEGEAN_SEA
 *    EEC_SEANAME_ALBORAN_SEA
 *    EEC_SEANAME_AMUNDSEN_SEA
 *    EEC_SEANAME_ANADYRSKIY_ZALIV
 *    EEC_SEANAME_ANDAMAN_SEA
 *    EEC_SEANAME_ARABIAN_SEA
 *    EEC_SEANAME_ARAFURA_SEA
 *    EEC_SEANAME_ARU_SEA
 *    EEC_SEANAME_BAFFIN_BAY
 *    EEC_SEANAME_BALEAR_SEA
 *    EEC_SEANAME_BALI_SEA
 *    EEC_SEANAME_BALTIC_SEA
 *    EEC_SEANAME_BANDA_SEA
 *    EEC_SEANAME_BARENTS_SEA
 *    EEC_SEANAME_BASS_STRAIT
 *    EEC_SEANAME_BAY_OF_BENGAL
 *    EEC_SEANAME_BAY_OF_BISCAY
 *    EEC_SEANAME_BAY_OF_BOTHNIA
 *    EEC_SEANAME_BAY_OF_FUNDY
 *    EEC_SEANAME_BEAUFORT_SEA
 *    EEC_SEANAME_BELLINGSHAUSEN_SEA
 *    EEC_SEANAME_BERING_SEA
 *    EEC_SEANAME_BISMARCK_SEA
 *    EEC_SEANAME_BLACK_SEA
 *    EEC_SEANAME_BO_HAI
 *    EEC_SEANAME_BOTHNIAN_SEA
 *    EEC_SEANAME_BRANSFIELD_STRAIT
 *    EEC_SEANAME_BRISTOL_CHANNEL
 *    EEC_SEANAME_CARIBBEAN_SEA
 *    EEC_SEANAME_CASPIAN_SEA
 *    EEC_SEANAME_CELEBES_SEA
 *    EEC_SEANAME_CELTIC_SEA
 *    EEC_SEANAME_CENTRAL_BALTIC_SEA
 *    EEC_SEANAME_CERAM_SEA
 *    EEC_SEANAME_CHUCKCHI_SEA
 *    EEC_SEANAME_COASTAL_WATERS_SOUTHEAST_ALASKA_BRITISH_COLUMBIA
 *    EEC_SEANAME_CORAL_SEA
 *    EEC_SEANAME_COSMONAUTS_SEA
 *    EEC_SEANAME_DAVIS_SEA
 *    EEC_SEANAME_DAVIS_STRAIT
 *    EEC_SEANAME_DEAD_SEA
 *    EEC_SEANAME_DOVER_STRAIT
 *    EEC_SEANAME_DRAKE_PASSAGE
 *    EEC_SEANAME_DUMONT_DURVILLE_SEA
 *    EEC_SEANAME_EAST_CHINA_SEA
 *    EEC_SEANAME_EAST_SIBERIAN_SEA
 *    EEC_SEANAME_EASTERN_BASIN_MEDITERRANEAN_SEA
 *    EEC_SEANAME_ENGLISH_CHANNEL
 *    EEC_SEANAME_FLORES_SEA
 *    EEC_SEANAME_GREAT_AUSTRALIAN_BIGHT
 *    EEC_SEANAME_GREAT_BARRIER_REEF
 *    EEC_SEANAME_GREENLAND_SEA
 *    EEC_SEANAME_GULF_OF_ADEN
 *    EEC_SEANAME_GULF_OF_ALASKA
 *    EEC_SEANAME_GULF_OF_AQABA
 *    EEC_SEANAME_GULF_OF_BERAU
 *    EEC_SEANAME_GULF_OF_BONE
 *    EEC_SEANAME_GULF_OF_BOTHNIA
 *    EEC_SEANAME_GULF_OF_CALIFORNIA
 *    EEC_SEANAME_GULF_OF_CARPENTARIA
 *    EEC_SEANAME_GULF_OF_FINLAND
 *    EEC_SEANAME_GULF_OF_GUINEA
 *    EEC_SEANAME_GULF_OF_MANNAR
 *    EEC_SEANAME_GULF_OF_MEXICO
 *    EEC_SEANAME_GULF_OF_OMAN
 *    EEC_SEANAME_GULF_OF_PANAMA
 *    EEC_SEANAME_GULF_OF_PAPUA
 *    EEC_SEANAME_GULF_OF_RIGA
 *    EEC_SEANAME_GULF_OF_ST_LAWRENCE
 *    EEC_SEANAME_GULF_OF_SUEZ
 *    EEC_SEANAME_GULF_OF_THAILAND
 *    EEC_SEANAME_GULF_OF_TOMINI
 *    EEC_SEANAME_GULF_OF_TONKIN
 *    EEC_SEANAME_HALMAHERA_SEA
 *    EEC_SEANAME_HUDSON_BAY
 *    EEC_SEANAME_HUDSON_STRAIT
 *    EEC_SEANAME_ICELAND_SEA
 *    EEC_SEANAME_INNER_SEAS
 *    EEC_SEANAME_IONIAN_SEA
 *    EEC_SEANAME_IRISH_SEA_AND_ST_GEORGES_CHANNEL
 *    EEC_SEANAME_JAWA_SEA
 *    EEC_SEANAME_JOSEPH_BONAPARTE_GULF
 *    EEC_SEANAME_KARA_SEA
 *    EEC_SEANAME_KATTEGAT
 *    EEC_SEANAME_LABRADOR_SEA
 *    EEC_SEANAME_LAKSHADWEEP_SEA
 *    EEC_SEANAME_LAPTEV_SEA
 *    EEC_SEANAME_LAZAREV_SEA
 *    EEC_SEANAME_LIAODONG_WAN
 *    EEC_SEANAME_LIGURE_SEA
 *    EEC_SEANAME_LILLEBAELT
 *    EEC_SEANAME_LINCOLN_SEA
 *    EEC_SEANAME_MAKASSAR_STRAIT
 *    EEC_SEANAME_MALACCA_STRAIT
 *    EEC_SEANAME_MALUKU_SEA
 *    EEC_SEANAME_MAWSON_SEA
 *    EEC_SEANAME_MCMURDO_SOUND
 *    EEC_SEANAME_MEDITERRANEAN_SEA
 *    EEC_SEANAME_MOZAMBIQUE_CHANNEL
 *    EEC_SEANAME_NATUNA_SEA
 *    EEC_SEANAME_NORTH_SEA
 *    EEC_SEANAME_NORTHWESTERN_PASSAGES
 *    EEC_SEANAME_NORWEGIAN_SEA
 *    EEC_SEANAME_PALK_STRAIT_AND_BAY
 *    EEC_SEANAME_PERSIAN_GULF
 *    EEC_SEANAME_PHILIPPINE_SEA
 *    EEC_SEANAME_RED_SEA
 *    EEC_SEANAME_RIISER_LARSEN_SEA
 *    EEC_SEANAME_RIO_DE_LA_PLATA
 *    EEC_SEANAME_ROSS_SEA
 *    EEC_SEANAME_SAWU_SEA
 *    EEC_SEANAME_SCOTIA_SEA
 *    EEC_SEANAME_SEA_OF_AZOV
 *    EEC_SEANAME_SEA_OF_CRETE
 *    EEC_SEANAME_SEA_OF_JAPAN
 *    EEC_SEANAME_SEA_OF_MARMARA
 *    EEC_SEANAME_SEA_OF_OKHOTSK
 *    EEC_SEANAME_SETO_NAIKAI
 *    EEC_SEANAME_SINGAPORE_STRAIT
 *    EEC_SEANAME_SKAGERRAK
 *    EEC_SEANAME_SODRUZHETSVA_SEA
 *    EEC_SEANAME_SOLOMON_SEA
 *    EEC_SEANAME_SOMOV_SEA
 *    EEC_SEANAME_SOUND_SEA
 *    EEC_SEANAME_SOUTH_CHINA_SEA
 *    EEC_SEANAME_STOREBAELT
 *    EEC_SEANAME_STRAIT_OF_GIBRALTAR
 *    EEC_SEANAME_STRAIT_OF_SICILIA
 *    EEC_SEANAME_SULAWESI_SEA
 *    EEC_SEANAME_SULU_SEA
 *    EEC_SEANAME_SUMBA_STRAIT
 *    EEC_SEANAME_SUNDA_STRAIT
 *    EEC_SEANAME_TAI_WAN_STRAIT
 *    EEC_SEANAME_TASMAN_SEA
 *    EEC_SEANAME_TATARSKIY_PROLIV
 *    EEC_SEANAME_THE_SOUND
 *    EEC_SEANAME_TIMOR_SEA
 *    EEC_SEANAME_TIRRENO_SEA
 *    EEC_SEANAME_TORRES_STRAIT
 *    EEC_SEANAME_TRYOSHNIKOVA_GULF
 *    EEC_SEANAME_TYRRHENIAN_SEA
 *    EEC_SEANAME_WEDDELL_SEA
 *    EEC_SEANAME_WESTERN_BASIN_MEDITERRANEAN_SEA
 *    EEC_SEANAME_WHITE_SEA
 *    EEC_SEANAME_YELLOW_SEA
 *
 * Group Membership: IDENTIFICATION, HYDROLOGY
 */
#define EAC_SEA_NAME ((EDCS_Attribute_Code)1187)

/*
 * Definition:
 *     The roughness of a <WATERBODY_SURFACE> in terms of the Douglas
 *     sea-state scale, a <SYSTEM> of categorized mean <WATER_WAVE> heights;
 *     the sea state category.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SEASTATECAT_CALM_GLASSY
 *    EEC_SEASTATECAT_CALM_RIPPLED
 *    EEC_SEASTATECAT_SMOOTH_WAVELETS
 *    EEC_SEASTATECAT_SLIGHT
 *    EEC_SEASTATECAT_MODERATE
 *    EEC_SEASTATECAT_ROUGH
 *    EEC_SEASTATECAT_VERY_ROUGH
 *    EEC_SEASTATECAT_HIGH
 *    EEC_SEASTATECAT_VERY_HIGH
 *    EEC_SEASTATECAT_PHENOMENAL
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define EAC_SEA_STATE_CATEGORY ((EDCS_Attribute_Code)1188)

/*
 * Definition:
 *     The power level of acoustic noise energy in a <WATERBODY> due to
 *     <WATER_WAVE>s; the sea state noise.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_POWER_LEVEL
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_SEA_STATE_NOISE_POWER_LEVEL ((EDCS_Attribute_Code)1189)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of moveable external <LIGHTING> that is used to
 *     illuminate the environment in arbitrary <DIRECTION>s; the spotlight,
 *     flashlight or search light intensity. Zero means unlit and one means
 *     maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_SEARCH_LIGHT_INTENSITY ((EDCS_Attribute_Code)1190)

/*
 * Definition:
 *     The division of the year (one of four) marked by the passage of the
 *     <SUN> through an equinox or solstice.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SEASON_SPRING
 *    EEC_SEASON_SUMMER
 *    EEC_SEASON_AUTUMN
 *    EEC_SEASON_WINTER
 *
 * Group Membership: TIME
 */
#define EAC_SEASON ((EDCS_Attribute_Code)1191)

/*
 * Definition:
 *     The season in which the <TENT>s of a nomadic people are at a given
 *     <LOCATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SSNTENTLOC_SUMMER
 *    EEC_SSNTENTLOC_WINTER
 *
 * Group Membership: SHELTER, TIME
 */
#define EAC_SEASONAL_TENT_LOCATION ((EDCS_Attribute_Code)1192)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional deployment position of the secondary <AERIAL> on an
 *     <OBJECT>. Zero means fully stowed/retracted and one means fully
 *     deployed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, INFRASTRUCTURE, RATE_OR_RATIO
 */
#define EAC_SECONDARY_AERIAL_DEPLOYED_POSITION ((EDCS_Attribute_Code)1193)

/*
 * Definition:
 *     The <<VELOCITY>> component of an <OBJECT> along the secondary axis of
 *     a defined spatial reference frame.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_SECONDARY_AXIS_VELOCITY_COMPONENT ((EDCS_Attribute_Code)1194)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_GEODETIC>> of a <LINE> drawn perpendicular to the
 *     <DIRECTION> of propagation of secondary breaking <WATER_WAVE>s in the
 *     wave spectra of a <SURF_ZONE>; the secondary breaker azimuth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_SECONDARY_BREAKER_AZIMUTH ((EDCS_Attribute_Code)1195)

/*
 * Definition:
 *     The horizontal angle the secondary breaking <WATER_WAVE>s make with
 *     respect to the <BEACH>. The value increases from 0 when the <LINE> of
 *     the <WATER_WAVE>s parallels the <BEACH>, towards 90 arc degrees on
 *     either the right or left flank as seen from <VESSEL>s approaching the
 *     <BEACH>; the secondary breaker relative angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_SECONDARY_BREAKER_RELATIVE_ANGLE ((EDCS_Attribute_Code)1196)

/*
 * Definition:
 *     The designated secondary broadcast <<FREQUENCY>> for a communications
 *     <DEVICE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FREQUENCY
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define EAC_SECONDARY_BROADCAST_FREQUENCY ((EDCS_Attribute_Code)1197)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional opening of the secondary <DOOR> of an <OBJECT>. Zero means
 *     fully closed and one means fully open.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_SECONDARY_DOOR_OPEN_POSITION ((EDCS_Attribute_Code)1198)

/*
 * Definition:
 *     The characteristics of the composition of the secondary <MATERIAL> of
 *     an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SECMATCHR_BROKEN
 *    EEC_SECMATCHR_CALCAREOUS
 *    EEC_SECMATCHR_COARSE
 *    EEC_SECMATCHR_DECAYED
 *    EEC_SECMATCHR_FINE_PARTICLES
 *    EEC_SECMATCHR_FLINTY
 *    EEC_SECMATCHR_GLACIAL
 *    EEC_SECMATCHR_GRITTY
 *    EEC_SECMATCHR_GROUND
 *    EEC_SECMATCHR_HARD
 *    EEC_SECMATCHR_LARGE_PARTICLES
 *    EEC_SECMATCHR_MEDIUM_PARTICLES
 *    EEC_SECMATCHR_ROCKY
 *    EEC_SECMATCHR_ROTTEN
 *    EEC_SECMATCHR_SMALL_PARTICLES
 *    EEC_SECMATCHR_SOFT
 *    EEC_SECMATCHR_SPECKLED
 *    EEC_SECMATCHR_STICKY
 *    EEC_SECMATCHR_STIFF
 *    EEC_SECMATCHR_STREAKY
 *    EEC_SECMATCHR_TENACIOUS
 *    EEC_SECMATCHR_UNEVEN
 *    EEC_SECMATCHR_VARIED
 *    EEC_SECMATCHR_VOLCANIC
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL
 */
#define EAC_SECONDARY_MATERIAL_CHARACTERISTIC ((EDCS_Attribute_Code)1199)

/*
 * Definition:
 *     The type of composition of the secondary <MATERIAL> of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SECMATTY_ASH
 *    EEC_SECMATTY_ASPHALT
 *    EEC_SECMATTY_BOULDER
 *    EEC_SECMATTY_CHALK
 *    EEC_SECMATTY_CINDER
 *    EEC_SECMATTY_CIRRIPEDIA
 *    EEC_SECMATTY_CLAY
 *    EEC_SECMATTY_CLAY_TILE
 *    EEC_SECMATTY_COBBLE
 *    EEC_SECMATTY_COKE
 *    EEC_SECMATTY_CONCRETE
 *    EEC_SECMATTY_CORAL
 *    EEC_SECMATTY_CORAL_HEAD
 *    EEC_SECMATTY_DIATOMACEOUS_EARTH
 *    EEC_SECMATTY_EVAPORITE
 *    EEC_SECMATTY_FABRIC
 *    EEC_SECMATTY_FORAMINIFERA
 *    EEC_SECMATTY_FUCUS
 *    EEC_SECMATTY_GLASS_REINFORCED_PLASTIC
 *    EEC_SECMATTY_GLOBIGERINA
 *    EEC_SECMATTY_GRASS
 *    EEC_SECMATTY_GRAVEL
 *    EEC_SECMATTY_GROUND
 *    EEC_SECMATTY_LAVA
 *    EEC_SECMATTY_LOESS
 *    EEC_SECMATTY_MADREPORE
 *    EEC_SECMATTY_MANGANESE
 *    EEC_SECMATTY_MARL
 *    EEC_SECMATTY_MATTE
 *    EEC_SECMATTY_MUD
 *    EEC_SECMATTY_MUSSEL
 *    EEC_SECMATTY_NONE_REPORTED
 *    EEC_SECMATTY_OOZE
 *    EEC_SECMATTY_OYSTER
 *    EEC_SECMATTY_PEBBLE
 *    EEC_SECMATTY_PLANT_MATERIAL
 *    EEC_SECMATTY_POLYZOA
 *    EEC_SECMATTY_PTEROPOD
 *    EEC_SECMATTY_PUMICE
 *    EEC_SECMATTY_QUARTZ
 *    EEC_SECMATTY_RADIOLARIAN
 *    EEC_SECMATTY_ROCK
 *    EEC_SECMATTY_RUBBER
 *    EEC_SECMATTY_SAND
 *    EEC_SECMATTY_SCHIST
 *    EEC_SECMATTY_SCORIA
 *    EEC_SECMATTY_SEA_TANGLE
 *    EEC_SECMATTY_SEAWEED
 *    EEC_SECMATTY_SHELL
 *    EEC_SECMATTY_SHINGLE
 *    EEC_SECMATTY_SILT
 *    EEC_SECMATTY_SOIL
 *    EEC_SECMATTY_SPICULE
 *    EEC_SECMATTY_SPONGE
 *    EEC_SECMATTY_STONE
 *    EEC_SECMATTY_THATCH
 *    EEC_SECMATTY_TUFA
 *    EEC_SECMATTY_URANIUM
 *    EEC_SECMATTY_VEGETATION_PRODUCT
 *    EEC_SECMATTY_VINYL
 *    EEC_SECMATTY_VOLCANIC
 *    EEC_SECMATTY_VOLCANIC_ASH
 *    EEC_SECMATTY_WATER
 *    EEC_SECMATTY_WOOD
 *    EEC_SECMATTY_ZINC
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL
 */
#define EAC_SECONDARY_MATERIAL_TYPE ((EDCS_Attribute_Code)1200)

/*
 * Definition:
 *     The <<VELOCITY>> of the <AIR> along the secondary <SURFACE> of an
 *     <OBJECT>, generally the bottom, back, or inner side of a layer of
 *     <MATERIAL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, MATERIAL, RATE_OR_RATIO, SURFACE
 */
#define EAC_SECONDARY_SURFACE_AIR_VELOCITY ((EDCS_Attribute_Code)1201)

/*
 * Definition:
 *     The <<TEMPERATURE>> of the medium in contact with the secondary
 *     <SURFACE> of an <OBJECT>, generally the top, front, or outer side of
 *     a layer of <MATERIAL>; typically used as a boundary condition in
 *     thermal solutions.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: MATERIAL, SURFACE, TEMPERATURE
 */
#define EAC_SECONDARY_SURFACE_TEMPERATURE ((EDCS_Attribute_Code)1202)

/*
 * Definition:
 *     The physical boundary condition at the secondary <SURFACE> of an
 *     <OBJECT>, generally the top, front, or outer side of a layer of
 *     <MATERIAL>, that accounts for the thermal interface of an <OBJECT>
 *     with the environment at that <SURFACE>; the secondary surface thermal
 *     condition.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SECSRFTHERMCND_AERODYNAMICALLY_HEATED
 *    EEC_SECSRFTHERMCND_AMB_AIR_AMB_SPEED_INFLUENCED
 *    EEC_SECSRFTHERMCND_AMB_AIR_FIXED
 *    EEC_SECSRFTHERMCND_AMB_AIR_INFLUENCED
 *    EEC_SECSRFTHERMCND_AMB_TEMP_LOCAL_AIR_INFLUENCED
 *    EEC_SECSRFTHERMCND_ARTIFICIAL_STEADY_STATE
 *    EEC_SECSRFTHERMCND_ENGINE_INFLUENCED
 *    EEC_SECSRFTHERMCND_EXTREMELY_HOT_FORCED
 *    EEC_SECSRFTHERMCND_FIXED_SURFACE_TEMP
 *    EEC_SECSRFTHERMCND_GROUND_TEMP_INFLUENCED
 *    EEC_SECSRFTHERMCND_LOCAL_AIR_TEMP_SPEED_INFLUENCED
 *    EEC_SECSRFTHERMCND_ROOM_TEMP_FORCED
 *    EEC_SECSRFTHERMCND_WARMED_PASSIVELY
 *
 * Group Membership: MATERIAL, SURFACE
 */
#define EAC_SECONDARY_SURFACE_THERMAL_CONDITION ((EDCS_Attribute_Code)1203)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which secondary
 *     <SWELL_WAVE>s are arriving.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_SECONDARY_SWELL_WAVE_DIRECTION ((EDCS_Attribute_Code)1204)

/*
 * Definition:
 *     The mean <<HEIGHT>> of the significant (highest one-third) secondary
 *     <SWELL_WAVE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_SECONDARY_SWELL_WAVE_HEIGHT ((EDCS_Attribute_Code)1205)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> that a complete cycle (usually crest to
 *     crest or trough to trough) of a secondary <SWELL_WAVE> takes to pass
 *     a given fixed point.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_SECONDARY_SWELL_WAVE_PERIOD ((EDCS_Attribute_Code)1206)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which secondary
 *     <WATER_WAVE>s (combined <WIND_WAVE> and <SWELL_WAVE>) in the wave
 *     spectra are arriving.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_SECONDARY_WAVE_DIRECTION ((EDCS_Attribute_Code)1207)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> of an angular sector for
 *     which the measurement applies.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_SECTOR_DIRECTION ((EDCS_Attribute_Code)1208)

/*
 * Definition:
 *     The highest level of security associated with an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SECULEV_US_UNCLASSIFIED
 *    EEC_SECULEV_US_CONFIDENTIAL
 *    EEC_SECULEV_US_RESTRICTED
 *    EEC_SECULEV_US_SECRET
 *    EEC_SECULEV_US_TOP_SECRET
 *
 * Group Membership: ABSTRACT_OBJECT, MILITARY_SCIENCE
 */
#define EAC_SECURITY_LEVEL ((EDCS_Attribute_Code)1209)

/*
 * Definition:
 *     The type of a security lock.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SECULOCKTY_CIPHER
 *    EEC_SECULOCKTY_DOUBLE_CYLINDER_CYLINDRICAL
 *    EEC_SECULOCKTY_ELECTROMAGNETIC
 *    EEC_SECULOCKTY_INTERIOR_DRAWBOLT
 *    EEC_SECULOCKTY_INTERIOR_LATCH
 *    EEC_SECULOCKTY_MORTISED
 *    EEC_SECULOCKTY_NO_LOCK
 *    EEC_SECULOCKTY_PADLOCK
 *    EEC_SECULOCKTY_PRIVACY
 *    EEC_SECULOCKTY_SINGLE_CYLINDER_CYLINDRICAL
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define EAC_SECURITY_LOCK_TYPE ((EDCS_Attribute_Code)1210)

/*
 * Definition:
 *     The quantity of frequency dependence of the absorption and scattering
 *     of acoustic energy as it travels through a <WATERBODY_FLOOR> in
 *     <<WATER_DEPTH>>s of 200 metres or less; the sediment attenuation
 *     exponent.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_ATTENUATION_FREQUENCY_EXPONENT ((EDCS_Attribute_Code)1211)

/*
 * Definition:
 *     The rate of change with respect to <<DEPTH_BELOW_WATERBODY_FLOOR>> of
 *     the distance and frequency gradient of the absorption and scattering
 *     of acoustic energy travelling through <SEDIMENT>; the sediment
 *     attenuation gradient.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_LEN_FREQ
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_ATTENUATION_GRADIENT ((EDCS_Attribute_Code)1212)

/*
 * Definition:
 *     The ratio of reflected acoustic energy to the incident acoustic energy
 *     at a <WATERBODY_FLOOR> sediment/basement interface; the sediment
 *     basement reflection coefficient.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_BASEMENT_REFLECTION_COEFFICIENT ((EDCS_Attribute_Code)1213)

/*
 * Definition:
 *     The density of layers of deep <SEDIMENT>s located below near-surface
 *     <SEDIMENT>s on a <WATERBODY_FLOOR>; the sediment below layers density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_BELOW_LAYERS_DENSITY ((EDCS_Attribute_Code)1214)

/*
 * Definition:
 *     The depth and frequency gradient of absorption and scattering of
 *     compressional waves while travelling through a layer of <SEDIMENT>;
 *     the sediment compressional attenuation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_LEN_FREQ
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MATERIAL, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_COMP_ATTENUATION ((EDCS_Attribute_Code)1215)

/*
 * Definition:
 *     The <<SPEED>> of propagation of compressional waves in a <SEDIMENT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_COMP_WAVE_SPEED ((EDCS_Attribute_Code)1216)

/*
 * Definition:
 *     The <<SPEED>> of propagation of compressional waves profile curvature
 *     parameter of a layer of <SEDIMENT>; the sound speed profile curvature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MATERIAL, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_COMP_WAVE_SPEED_CURVATURE ((EDCS_Attribute_Code)1217)

/*
 * Definition:
 *     The rate at which the <<SPEED>> of propagation of compressional waves
 *     changes with depth in <SEDIMENT>, evaluated at a water-sediment
 *     interface.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RATE
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MATERIAL, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_COMP_WAVE_SPEED_GRADIENT_TOP ((EDCS_Attribute_Code)1218)

/*
 * Definition:
 *     The electrical conductivity of <SEDIMENT> on a <WATERBODY_FLOOR>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: ELECTRIC_CONDUCTIVITY
 *
 * Group Membership: EM_PHENOMENON, MATERIAL, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_CONDUCTIVITY ((EDCS_Attribute_Code)1219)

/*
 * Definition:
 *     The negative of the logarithm to the base 2 of the grain diameter of
 *     <SEDIMENT> expressed in millimetres; the grain size.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: DIMENSION, MATERIAL
 */
#define EAC_SEDIMENT_GRAIN_SIZE ((EDCS_Attribute_Code)1220)

/*
 * Definition:
 *     The <<MATERIAL_DENSITY>> of a layer of <SEDIMENT> on a
 *     <WATERBODY_FLOOR>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_LAYER_DENSITY ((EDCS_Attribute_Code)1221)

/*
 * Definition:
 *     The mean background <<THICKNESS>> of the layers of <SEDIMENT> located
 *     just below a <WATERBODY_FLOOR>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, MATERIAL, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_MEAN_BACKGROUND_THICKNESS ((EDCS_Attribute_Code)1222)

/*
 * Definition:
 *     The angle between a layer of <SEDIMENT> on a <WATERBODY_FLOOR> and a
 *     compressional wave that is reflected from it; the sediment
 *     reflectivity angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ACOUSTIC_PHENOMENON, ANGULAR_MEASURE, MATERIAL, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_REFLECTIVITY_ANGLE ((EDCS_Attribute_Code)1223)

/*
 * Definition:
 *     The depth and frequency gradient of absorption and scattering of shear
 *     waves while travelling through a layer of <SEDIMENT>; the sediment
 *     shear attenuation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_LEN_FREQ
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MATERIAL, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_SHEAR_ATTENUATION ((EDCS_Attribute_Code)1224)

/*
 * Definition:
 *     The <<SPEED>> of propagation of shear waves in a <SEDIMENT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MATERIAL, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_SHEAR_WAVE_SPEED ((EDCS_Attribute_Code)1225)

/*
 * Definition:
 *     The absorption and scattering coefficient of compressional waves
 *     travelling through <SEDIMENT> just below a <WATERBODY_FLOOR>; the
 *     sediment surface attenuation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_LEN_FREQ
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MATERIAL, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_SRF_ATTENUATION ((EDCS_Attribute_Code)1226)

/*
 * Definition:
 *     The distance and frequency gradient of <<SEDIMENT_SRF_ATTENUATION>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: GRAD_POWER_LEVEL_DIFF_LEN_FREQ
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MATERIAL, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_SRF_ATTENUATION_GRADIENT ((EDCS_Attribute_Code)1227)

/*
 * Definition:
 *     The <<MATERIAL_DENSITY>> of the top-most layer of <SEDIMENT> on a
 *     <WATERBODY_FLOOR>; the sediment surface density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_SURFACE_DENSITY ((EDCS_Attribute_Code)1228)

/*
 * Definition:
 *     The <<MATERIAL_DENSITY>> of a surficial layer of <SEDIMENT> on a
 *     <WATERBODY_FLOOR>; the sediment thin-layer density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_THIN_LAYER_DENSITY ((EDCS_Attribute_Code)1229)

/*
 * Definition:
 *     The <<THICKNESS>> of the surficial thin-layer of <SEDIMENT> on a
 *     <WATERBODY_FLOOR>; the sediment thin-layer <<THICKNESS>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, MATERIAL, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_THIN_LAYER_THICKNESS ((EDCS_Attribute_Code)1230)

/*
 * Definition:
 *     The quantity of time required for compressional waves to travel
 *     vertically from a <WATERBODY_FLOOR> to the sediment/basement
 *     interface and back to the <SURFACE> of that <WATERBODY_FLOOR>; the
 *     sediment two-way travel time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: ACOUSTIC_PHENOMENON, TIME, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_TWO_WAY_TRAVEL_TIME ((EDCS_Attribute_Code)1231)

/*
 * Definition:
 *     The ratio of the <<SPEED>> of compressional waves in a <SEDIMENT> to
 *     that in the column of <WATER> above it.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ACOUSTIC_PHENOMENON, MATERIAL, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_SEDIMENT_WATER_COMP_WAVE_SPEED_RATIO ((EDCS_Attribute_Code)1232)

/*
 * Definition:
 *     The rate of heat flow between a <PLANETARY_SURFACE> and the
 *     <ATMOSPHERE>; the sensible heat flux.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: RATE_OR_RATIO, TEMPERATURE
 */
#define EAC_SENSIBLE_HEAT_FLUX ((EDCS_Attribute_Code)1233)

/*
 * Definition:
 *     The branch of a military service or organization.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SVCBR_AIR_FORCE
 *    EEC_SVCBR_ARMY
 *    EEC_SVCBR_COASTGUARD
 *    EEC_SVCBR_JOINT
 *    EEC_SVCBR_MARINES
 *    EEC_SVCBR_NAVY
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_SERVICE_BRANCH ((EDCS_Attribute_Code)1234)

/*
 * Definition:
 *     An indication that severe weather is present. Severe weather is any
 *     atmospheric condition potentially destructive or hazardous to
 *     <HUMAN>s.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_SEVERE_WEATHER_PRESENT ((EDCS_Attribute_Code)1235)

/*
 * Definition:
 *     The radius of curvature of a <SHARP_CURVE> in a
 *     <LAND_TRANSPORTATION_ROUTE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_SHARP_CURVE_RADIUS ((EDCS_Attribute_Code)1236)

/*
 * Definition:
 *     An indication that an <OBJECT> (for example: a linear stand of
 *     <TREE>s) functions as a shelter belt, protecting other <OBJECT>s from
 *     the effects of adverse weather.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, ATMOSPHERE
 */
#define EAC_SHELTER_BELT ((EDCS_Attribute_Code)1237)

/*
 * Definition:
 *     The measurement status of a shipping noise level in a <WATERBODY>;
 *     typically taken at 50 hertz.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SHPNSEMEASSTAT_MEASURED
 *    EEC_SHPNSEMEASSTAT_NOT_MEASURED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_STATE
 */
#define EAC_SHIPPING_NOISE_MEASUREMENT_STATUS ((EDCS_Attribute_Code)1238)

/*
 * Definition:
 *     The seasonally adjusted acoustic noise characteristics (for example:
 *     spectral class, standard deviation, and/or decibels per octave
 *     roll-off) in a <WATERBODY> due to distant shipping; the shipping
 *     noise season type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SHPNSESSNTY_JANUARY_SUMMER
 *    EEC_SHPNSESSNTY_JANUARY_WINTER
 *    EEC_SHPNSESSNTY_FEBRUARY_SUMMER
 *    EEC_SHPNSESSNTY_FEBRUARY_WINTER
 *    EEC_SHPNSESSNTY_MARCH_SUMMER
 *    EEC_SHPNSESSNTY_MARCH_WINTER
 *    EEC_SHPNSESSNTY_APRIL_SUMMER
 *    EEC_SHPNSESSNTY_APRIL_WINTER
 *    EEC_SHPNSESSNTY_MAY_SUMMER
 *    EEC_SHPNSESSNTY_MAY_WINTER
 *    EEC_SHPNSESSNTY_JUNE_SUMMER
 *    EEC_SHPNSESSNTY_JUNE_WINTER
 *    EEC_SHPNSESSNTY_JULY_SUMMER
 *    EEC_SHPNSESSNTY_JULY_WINTER
 *    EEC_SHPNSESSNTY_AUGUST_SUMMER
 *    EEC_SHPNSESSNTY_AUGUST_WINTER
 *    EEC_SHPNSESSNTY_SEPTEMBER_SUMMER
 *    EEC_SHPNSESSNTY_SEPTEMBER_WINTER
 *    EEC_SHPNSESSNTY_OCTOBER_SUMMER
 *    EEC_SHPNSESSNTY_OCTOBER_WINTER
 *    EEC_SHPNSESSNTY_NOVEMBER_SUMMER
 *    EEC_SHPNSESSNTY_NOVEMBER_WINTER
 *    EEC_SHPNSESSNTY_DECEMBER_SUMMER
 *    EEC_SHPNSESSNTY_DECEMBER_WINTER
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_STATE
 */
#define EAC_SHIPPING_NOISE_SEASON_TYPE ((EDCS_Attribute_Code)1239)

/*
 * Definition:
 *     The gradient in the shipping noise spectral power level in a
 *     <WATERBODY> as a function of <<FREQUENCY>>, typically above 300
 *     hertz; the shipping noise roll-off.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_FREQ_GRADIENT
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL_ROLL_OFF ((EDCS_Attribute_Code)1240)

/*
 * Definition:
 *     The standard deviation of shipping noise spectral power level
 *     measurements in a <WATERBODY>; typically taken at 50 hertz.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_SHIPPING_NOISE_STD_DEV ((EDCS_Attribute_Code)1241)

/*
 * Definition:
 *     An indication that the delineation of a <SHORELINE> is definite.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT,  HYDROLOGY
 */
#define EAC_SHORELINE_DELINEATED ((EDCS_Attribute_Code)1242)

/*
 * Definition:
 *     The topography and types of <MATERIAL> found on a <SHORE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SHORLNPHYSIOG_ARTIFICIAL
 *    EEC_SHORLNPHYSIOG_FLAT
 *    EEC_SHORLNPHYSIOG_GLACIER
 *    EEC_SHORLNPHYSIOG_HILLOCKS
 *    EEC_SHORLNPHYSIOG_ICE_COAST
 *    EEC_SHORLNPHYSIOG_SANDY
 *    EEC_SHORLNPHYSIOG_SHINGLY
 *    EEC_SHORLNPHYSIOG_STEEP
 *    EEC_SHORLNPHYSIOG_STEEP_COAST
 *    EEC_SHORLNPHYSIOG_STONY
 *    EEC_SHORLNPHYSIOG_STONY_SHINGLY_MIX
 *
 * Group Membership: LITTORAL, MATERIAL, PHYSIOGRAPHY
 */
#define EAC_SHORELINE_PHYSIOGRAPHY ((EDCS_Attribute_Code)1243)

/*
 * Definition:
 *     The type of physical characteristics of a <SHORELINE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SHORLNTY_CORAL
 *    EEC_SHORLNTY_ICE
 *    EEC_SHORLNTY_MANGROVE
 *    EEC_SHORLNTY_MARSHY
 *    EEC_SHORLNTY_ROCKY
 *    EEC_SHORLNTY_RUBBLE
 *    EEC_SHORLNTY_SANDY
 *    EEC_SHORLNTY_SHELLY
 *    EEC_SHORLNTY_SHINGLY
 *    EEC_SHORLNTY_STONY
 *    EEC_SHORLNTY_STONY_SHINGLY_MIX
 *
 * Group Membership: LITTORAL, PHYSIOGRAPHY
 */
#define EAC_SHORELINE_TYPE ((EDCS_Attribute_Code)1244)

/*
 * Definition:
 *     The degree of stability of the layer of the <ATMOSPHERE> extending
 *     from a level near the <PLANETARY_SURFACE> of the <EARTH> to the 500
 *     hectopascals (500 millibar) pressure as calculated by the Showalter
 *     method; the Showalter atmosphere stability index.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_SHOWALTER_ATMOSPHERE_STABILITY_INDEX ((EDCS_Attribute_Code)1245)

/*
 * Definition:
 *     The sides of an <OBJECT> that are visible.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SIDESVIS_BOTH_SIDES
 *    EEC_SIDESVIS_LEFT
 *    EEC_SIDESVIS_RIGHT
 *
 * Group Membership: ABSTRACT_OBJECT, LIGHTING_AND_VISIBILITY
 */
#define EAC_SIDES_VISIBLE ((EDCS_Attribute_Code)1246)

/*
 * Definition:
 *     The <<WIND_OMEGA>> through a pressure <SURFACE> normalized by the
 *     <<ATM_PRESSURE>> at the <PLANETARY_SURFACE> of the <EARTH>; the sigma
 *     coordinate vertical velocity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RATE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_SIGMA_COORDINATE_VERTICAL_VELOCITY ((EDCS_Attribute_Code)1247)

/*
 * Definition:
 *     The rate of change per unit time of <<SIGMA_WIDTH_CROSSWIND>>; the
 *     sigma crosswind spreading rate.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_SIGMA_CROSSWIND_SPREADING_RATE ((EDCS_Attribute_Code)1248)

/*
 * Definition:
 *     The rate of change per unit time of <<SIGMA_WIDTH_DOWNWIND>>; the
 *     sigma downwind spreading rate.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_SIGMA_DOWNWIND_SPREADING_RATE ((EDCS_Attribute_Code)1249)

/*
 * Definition:
 *     The rate of change per unit time of <<SIGMA_WIDTH_VERTICAL>>; the
 *     sigma vertical spreading rate.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_SIGMA_VERTICAL_SPREADING_RATE ((EDCS_Attribute_Code)1250)

/*
 * Definition:
 *     The horizontal dimension of a <PLUME> or <PUFF> measured in the
 *     crosswind dimension between points that are symmetric about the
 *     centre of <<MASS>> where 68% of the total <<MASS>> is found; the
 *     sigma width crosswind.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, DIMENSION
 */
#define EAC_SIGMA_WIDTH_CROSSWIND ((EDCS_Attribute_Code)1251)

/*
 * Definition:
 *     The horizontal dimension of a <PLUME> or <PUFF> measured in the
 *     downwind dimension between points that are symmetric about the centre
 *     of <<MASS>> where 68% of the total <<MASS>> is found; the sigma width
 *     downwind.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, DIMENSION
 */
#define EAC_SIGMA_WIDTH_DOWNWIND ((EDCS_Attribute_Code)1252)

/*
 * Definition:
 *     The vertical height of a <PLUME> or <PUFF> measured along the vertical
 *     dimension between points that are symmetric about the centre of
 *     <<MASS>> where 68% of the total <<MASS>> is found; the vertical sigma
 *     width.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, DIMENSION
 */
#define EAC_SIGMA_WIDTH_VERTICAL ((EDCS_Attribute_Code)1253)

/*
 * Definition:
 *     A characterization of the signal light emitted by one or more <LIGHT>s
 *     at one <LOCATION>. This information is formatted in a Basic Latin
 *     string giving the class, number, and colours of flashes or
 *     occultations. EXAMPLES "Q(6)+L F1", "VQ G", "L F1 (3+2)WR".
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: COLOUR, COMMUNICATION, LIGHTING_AND_VISIBILITY
 */
#define EAC_SIGNAL_LIGHT_CHARACTER ((EDCS_Attribute_Code)1254)

/*
 * Definition:
 *     The temporal pattern of one complete period of a repeating signal
 *     <LIGHT>. The pattern is formatted in a Basic Latin string as a list
 *     of relative duty cycle lengths representing the alternating on and
 *     off times of the signal beginning with the length of an ON signal.
 *     The duty cycle lengths are expressed as integers separated by commas;
 *     spaces are ignored.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: COMMUNICATION, LIGHTING_AND_VISIBILITY
 */
#define EAC_SIGNAL_LIGHT_PATTERN ((EDCS_Attribute_Code)1255)

/*
 * Definition:
 *     The number of flashes/occultations in a group flashing/occulting
 *     <<SIGNAL_LIGHT_PATTERN>>; the signal light pattern count.
 *
 * Value Type: COUNT
 *
 * Group Membership: COMMUNICATION, LIGHTING_AND_VISIBILITY
 */
#define EAC_SIGNAL_LIGHT_PATTERN_COUNT ((EDCS_Attribute_Code)1256)

/*
 * Definition:
 *     The specification of the sequence of <<TIME_QUANTITY>>s occupied by
 *     intervals of light and dark (eclipse) of a signal <LIGHT>.
 *
 * Value Type: STRING
 *
 * Group Membership: COMMUNICATION, TIME, LIGHTING_AND_VISIBILITY
 */
#define EAC_SIGNAL_LIGHT_SEQUENCE ((EDCS_Attribute_Code)1257)

/*
 * Definition:
 *     The mean <<HEIGHT>> measured from trough to crest of the significant
 *     (highest one-third) primary breaking <WATER_WAVE>s in a <SURF_ZONE>
 *     wave spectrum.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_SIGNIF_PRIMARY_BREAKER_HEIGHT ((EDCS_Attribute_Code)1258)

/*
 * Definition:
 *     The mean <<HEIGHT>> measured from trough to crest of the significant
 *     (highest one-third) secondary breaking <WATER_WAVE>s in a <SURF_ZONE>
 *     wave spectrum.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_SIGNIF_SECONDARY_BREAKER_HEIGHT ((EDCS_Attribute_Code)1259)

/*
 * Definition:
 *     The mean <<HEIGHT>> measured from trough to crest of the significant
 *     (highest one-third) <SWELL_WAVE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_SIGNIF_SWELL_WAVE_HEIGHT ((EDCS_Attribute_Code)1260)

/*
 * Definition:
 *     The mean <<HEIGHT>> measured from trough to crest of the significant
 *     (highest one-third) <WATER_WAVE>s (combined <WIND_WAVE>s and
 *     <SWELL_WAVE>s).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_SIGNIF_WAVE_HEIGHT ((EDCS_Attribute_Code)1261)

/*
 * Definition:
 *     The mean height of the significant (highest one-third) <WIND_WAVE>s,
 *     measured from trough to crest.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_SIGNIF_WIND_WAVE_HEIGHT ((EDCS_Attribute_Code)1262)

/*
 * Definition:
 *     The estimated load bearing capacity of a <LAND_TRANSPORTATION_ROUTE>
 *     for a single wheel of a <GROUND_VEHICLE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_SINGLE_WHEEL_BEARING_LOAD ((EDCS_Attribute_Code)1263)

/*
 * Definition:
 *     A means of quantifying the combined effect of low <<AIR_TEMPERATURE>>
 *     and <<WIND_SPEED>> on the body <<TEMPERATURE>> of <HUMAN>s that may
 *     result in hypothermia, expressed as an equivalent <<AIR_TEMPERATURE>>
 *     in degrees Celsius given by the formula: 0,0817 * [(5,5488 * V^(0,5))
 *     + 5,81 + (0,5592 * V)] * [T - 33,0] + 33,0 where V is the
 *     <<WIND_SPEED>> in metres per second at a <<HEIGHT_AGL>> of 10 metres
 *     (approximately 33 feet) and T is the <<AIR_TEMPERATURE>> in degrees
 *     Celsius; the Siple-Passel Wind Chill Index.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_SIPLE_PASSEL_WIND_CHILL_INDEX ((EDCS_Attribute_Code)1264)

/*
 * Definition:
 *     The ratio of sky luminance to non-sky luminance; the sky ground ratio.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_SKY_GROUND_LUMINANCE_RATIO ((EDCS_Attribute_Code)1265)

/*
 * Definition:
 *     The fraction of the sky that is covered by <FOG> or other low-altitude
 *     atmospheric phenomena, determined at a <PLANETARY_SURFACE>; the sky
 *     obscuration fraction.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_SKY_OBSCURATION_FRACTION ((EDCS_Attribute_Code)1266)

/*
 * Definition:
 *     A fixed value of magnetic variation applied within <EQUIPMENT>
 *     functioning as an <AID_TO_NAVIGATION> to the true <DIRECTION> in
 *     order to obtain the magnetic values for radials, courses and
 *     headings; a slaved declination.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_SLAVED_DECLINATION ((EDCS_Attribute_Code)1267)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the production rate of <SMOKE> by an <OBJECT>. Zero means
 *     no <SMOKE> at all and one means maximum production.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_SMOKE_RATE_FRACTION ((EDCS_Attribute_Code)1268)

/*
 * Definition:
 *     The number of <SMOKESTACK>s associated with an <OBJECT>; the
 *     smokestack count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ABSTRACT_OBJECT, AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define EAC_SMOKESTACK_COUNT ((EDCS_Attribute_Code)1269)

/*
 * Definition:
 *     The <<DEPTH>> of <SNOW_GROUND_COVER> that has accumulated over an
 *     <<ACCUMULATION_PERIOD>> or <<ACCUMULATION_PERIOD_CATEGORY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, ICE, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_SNOW_ACCUM_DEPTH ((EDCS_Attribute_Code)1270)

/*
 * Definition:
 *     The <<DEPTH>> of the liquid <WATER> that is equivalent in content to
 *     the <SNOW_GROUND_COVER> (not <ICE>) that has accumulated over an
 *     <<ACCUMULATION_PERIOD>> or <<ACCUMULATION_PERIOD_CATEGORY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, ICE, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_SNOW_ACCUM_DEPTH_EQUIVALENT ((EDCS_Attribute_Code)1271)

/*
 * Definition:
 *     The time difference between the reference date and the date of the
 *     last measurable <SNOW_PRECIPITATION>; the snow age.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: ATMOSPHERE, ICE, TIME
 */
#define EAC_SNOW_AGE ((EDCS_Attribute_Code)1272)

/*
 * Definition:
 *     The density of accumulated <SNOW_PRECIPITATION> on an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: ATMOSPHERE, ICE, MATERIAL, RATE_OR_RATIO, SURFACE, SURFACE_MATERIAL
 */
#define EAC_SNOW_DENSITY ((EDCS_Attribute_Code)1273)

/*
 * Definition:
 *     A category describing the <<SNOW_ONLY_DEPTH>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SNOWDEPCAT_NONE_PRESENT
 *    EEC_SNOWDEPCAT_TRACE
 *    EEC_SNOWDEPCAT_SLIGHT
 *    EEC_SNOWDEPCAT_ANY
 *    EEC_SNOWDEPCAT_LIGHT
 *    EEC_SNOWDEPCAT_LIGHT_TO_MODERATE
 *    EEC_SNOWDEPCAT_MODERATE
 *    EEC_SNOWDEPCAT_MODERATE_TO_HEAVY
 *    EEC_SNOWDEPCAT_HEAVY
 *
 * Group Membership: ATMOSPHERE, ICE, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_SNOW_DEPTH_CATEGORY ((EDCS_Attribute_Code)1274)

/*
 * Definition:
 *     The maximum height of drifts of <SNOW_GROUND_COVER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, ICE, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_SNOW_DRIFT_HEIGHT ((EDCS_Attribute_Code)1275)

/*
 * Definition:
 *     The melting rate of <SNOW_GROUND_COVER> as measured by
 *     <<SNOW_ONLY_DEPTH>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ICE, MATERIAL, RATE_OR_RATIO, SURFACE_MATERIAL
 */
#define EAC_SNOW_MELTING_RATE ((EDCS_Attribute_Code)1276)

/*
 * Definition:
 *     The depth of the <SNOW_GROUND_COVER> that may be over <TERRAIN>,
 *     <TERRAIN> covered by <ICE>, or floating <ICE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, ICE, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_SNOW_ONLY_DEPTH ((EDCS_Attribute_Code)1277)

/*
 * Definition:
 *     The <<VELOCITY>> of displacement of <SOIL> in the same <DIRECTION> as
 *     the compressional (density) wave through that <SOIL> (V[sub(P)]); the
 *     soil compressional velocity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_SOIL_COMPRESSIONAL_VELOCITY ((EDCS_Attribute_Code)1278)

/*
 * Definition:
 *     The force per unit basal area required to push a cone penetrometer
 *     through an increment of <SOIL>; typically measured at depths from 0,0
 *     to 0,6 metres; the soil cone index.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: MATERIAL
 */
#define EAC_SOIL_CONE_INDEX ((EDCS_Attribute_Code)1279)

/*
 * Definition:
 *     The average <<MATERIAL_DENSITY>> of the <SOIL>, between the <SURFACE>
 *     of the <TERRAIN> and the <BEDROCK>, after it has been dried to a
 *     constant <<MASS>> at 378,15 kelvin (105 degrees Celsius).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMIC_MASS
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_SOIL_DENSITY_DRY ((EDCS_Attribute_Code)1280)

/*
 * Definition:
 *     The <<DEPTH>> of <SOIL> or unconsolidated <MATERIAL> from the
 *     <SURFACE> of the <TERRAIN> to <BEDROCK>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, MATERIAL
 */
#define EAC_SOIL_DEPTH ((EDCS_Attribute_Code)1281)

/*
 * Definition:
 *     The <<DEPTH>> of the top of a layer of <SOIL> measured from the
 *     <SURFACE> of the <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, MATERIAL
 */
#define EAC_SOIL_LAYER_DEPTH ((EDCS_Attribute_Code)1282)

/*
 * Definition:
 *     The <<MASS>> of <WATER> contained between <<SOIL_LAYER_DEPTH>> 5 and
 *     <<SOIL_LAYER_DEPTH>> 100 centimetres; the lower layer soil moisture
 *     mass.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: HYDROLOGY, MATERIAL, RATE_OR_RATIO
 */
#define EAC_SOIL_MOISTURE_MASS_LOWER_LAYER ((EDCS_Attribute_Code)1283)

/*
 * Definition:
 *     The <<MASS>> of <WATER> contained between <<SOIL_LAYER_DEPTH>> 0 and
 *     <<SOIL_LAYER_DEPTH>> 5 centimetres below the <SURFACE> of the
 *     <TERRAIN>; the top layer soil moisture mass.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: HYDROLOGY, MATERIAL, RATE_OR_RATIO
 */
#define EAC_SOIL_MOISTURE_MASS_TOP_LAYER ((EDCS_Attribute_Code)1284)

/*
 * Definition:
 *     The coefficient in an exponential model of attenuation of seismic
 *     waves by <SOIL>; the soil seismic absorption coefficient. If A and
 *     A[sub(0)] are resultant and initial amplitudes, respectively, at a
 *     given <<FREQUENCY>>, x the distance travelled and a the soil seismic
 *     absorption coefficient, they are related by the equation: A =
 *     A[sub(0)] * exp(-ax).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ALGORITHM_RELATED, MATERIAL
 */
#define EAC_SOIL_SEISMIC_ABSORPTION_COEFFICIENT ((EDCS_Attribute_Code)1285)

/*
 * Definition:
 *     The <<VELOCITY>> of displacement of <SOIL> in the <DIRECTION>
 *     perpendicular to the compressional (density) wave through that <SOIL>
 *     (V[sub(S)]); the soil shear velocity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO
 */
#define EAC_SOIL_SHEAR_VELOCITY ((EDCS_Attribute_Code)1286)

/*
 * Definition:
 *     The <<TEMPERATURE>> of the <SOIL> at the <SURFACE> of the <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: MATERIAL, TEMPERATURE
 */
#define EAC_SOIL_SURFACE_TEMPERATURE ((EDCS_Attribute_Code)1287)

/*
 * Definition:
 *     The USCS type of the <SOIL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SOILTY_CLAYEY_GRAVEL
 *    EEC_SOILTY_CLAYEY_SAND
 *    EEC_SOILTY_EVAPORITE
 *    EEC_SOILTY_FAT_CLAY
 *    EEC_SOILTY_LEAN_CLAY
 *    EEC_SOILTY_MICRACEOUS
 *    EEC_SOILTY_NOT_EVALUATED
 *    EEC_SOILTY_ORGANIC_CLAY
 *    EEC_SOILTY_ORGANIC_SILT_CLAY
 *    EEC_SOILTY_PEAT
 *    EEC_SOILTY_POORLY_GRADED_GRAVEL
 *    EEC_SOILTY_POORLY_GRADED_SAND
 *    EEC_SOILTY_SILT_FINE_SAND
 *    EEC_SOILTY_SILT_FINE_SAND_AND_LEAN_CLAY
 *    EEC_SOILTY_SILTY_AND_CLAYEY_SAND
 *    EEC_SOILTY_SILTY_GRAVEL_SAND
 *    EEC_SOILTY_SILTY_SAND
 *    EEC_SOILTY_WELL_GRADED_GRAVEL
 *    EEC_SOILTY_WELL_GRADED_SAND
 *
 * Group Membership: MATERIAL
 */
#define EAC_SOIL_TYPE ((EDCS_Attribute_Code)1288)

/*
 * Definition:
 *     The <WATER> lost from the <SOIL> upon drying to constant <<MASS>> at
 *     378,15 kelvin (105 degrees Celsius). The value is expressed as the
 *     fractional <<MASS>> of <WATER> per unit <<MASS>> of wet <SOIL>; the
 *     soil water mass.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: HYDROLOGY, MATERIAL, RATE_OR_RATIO
 */
#define EAC_SOIL_WATER_MASS ((EDCS_Attribute_Code)1289)

/*
 * Definition:
 *     The <WATER> lost from the <SOIL> upon drying to constant <<MASS>> at
 *     378,15 kelvin (105 degrees Celsius). The value is expressed as the
 *     fractional <<VOLUME>> of <WATER> per unit bulk <<VOLUME>> of wet
 *     <SOIL>; the soil water volume.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUME_FRACTION
 *
 * Group Membership: HYDROLOGY, MATERIAL, RATE_OR_RATIO
 */
#define EAC_SOIL_WATER_VOLUME ((EDCS_Attribute_Code)1290)

/*
 * Definition:
 *     A category describing the content of liquid and solid <WATER> in the
 *     <SOIL> of a <TERRAIN_SURFACE_REGION>; the soil wetness category.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SOILWETNCAT_FROZEN
 *    EEC_SOILWETNCAT_FROZEN_OR_PERMAFROST
 *    EEC_SOILWETNCAT_MOIST
 *    EEC_SOILWETNCAT_PERENNIALLY_DRY
 *    EEC_SOILWETNCAT_PERMAFROST
 *    EEC_SOILWETNCAT_SATURATED
 *    EEC_SOILWETNCAT_WATERLOGGED
 *    EEC_SOILWETNCAT_WET
 *
 * Group Membership: HYDROLOGY, MATERIAL
 */
#define EAC_SOIL_WETNESS_CATEGORY ((EDCS_Attribute_Code)1291)

/*
 * Definition:
 *     The diffuse solar incident flux per unit <<AREA>> of the <SURFACE> of
 *     an <OBJECT>; the solar diffuse irradiance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, SPACE, SURFACE
 */
#define EAC_SOLAR_DIFFUSE_IRRADIANCE ((EDCS_Attribute_Code)1292)

/*
 * Definition:
 *     The direct solar incident flux per unit <<AREA>> of the <SURFACE> of
 *     an <OBJECT>; the solar direct irradiance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, SPACE, SURFACE
 */
#define EAC_SOLAR_DIRECT_IRRADIANCE ((EDCS_Attribute_Code)1293)

/*
 * Definition:
 *     The solar <<INCIDENCE_AZIMUTH_GEODETIC>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_SOLAR_RADIANCE_AZIMUTH_GEODETIC ((EDCS_Attribute_Code)1294)

/*
 * Definition:
 *     The solar <<INCIDENCE_AZIMUTH_LOCAL>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_SOLAR_RADIANCE_AZIMUTH_LOCAL ((EDCS_Attribute_Code)1295)

/*
 * Definition:
 *     The solar <<INCIDENCE_AZIMUTH_MAGNETIC>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_SOLAR_RADIANCE_AZIMUTH_MAGNETIC ((EDCS_Attribute_Code)1296)

/*
 * Definition:
 *     The solar <<INCIDENCE_ELEV_ANGLE_HORIZONTAL>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_SOLAR_RADIANCE_ELEV_ANGLE_HORIZONTAL ((EDCS_Attribute_Code)1297)

/*
 * Definition:
 *     The solar <<INCIDENCE_ELEV_ANGLE_LOCAL>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE
 */
#define EAC_SOLAR_RADIANCE_ELEV_ANGLE_LOCAL ((EDCS_Attribute_Code)1298)

/*
 * Definition:
 *     The rate of solar radiation received over a twenty-four hour
 *     <<TIME_QUANTITY>>; the solar radiation cumulative.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: IRRADIANCE
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SPACE
 */
#define EAC_SOLAR_RADIATION_CUMULATIVE ((EDCS_Attribute_Code)1299)

/*
 * Definition:
 *     An indication that the presence of an <OBJECT> has been confirmed by
 *     sonar.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT,  HYDROGRAPHIC_ARTEFACT
 */
#define EAC_SONAR_CONFIRMATION ((EDCS_Attribute_Code)1300)

/*
 * Definition:
 *     The depth of the layer near a <WATERBODY_SURFACE> into which sound
 *     rays are trapped by upward refraction effects; the sonic layer depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ACOUSTIC_PHENOMENON, LOCATION, WATERBODY_STATE
 */
#define EAC_SONIC_LAYER_DEPTH ((EDCS_Attribute_Code)1301)

/*
 * Definition:
 *     An indication that an audible marine signal is generated by a
 *     <MARINE_AID_TO_NAVIGATION>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ACOUSTIC_PHENOMENON, COMMUNICATION
 */
#define EAC_SOUND_SIGNAL_PRESENT ((EDCS_Attribute_Code)1302)

/*
 * Definition:
 *     The means used to generate an audible marine signal; the sound signal
 *     type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SNDSIGTY_BELL
 *    EEC_SNDSIGTY_DIAPHONE
 *    EEC_SNDSIGTY_EXPLOSIVE
 *    EEC_SNDSIGTY_GONG
 *    EEC_SNDSIGTY_GUN
 *    EEC_SNDSIGTY_HORN
 *    EEC_SNDSIGTY_NAUTOPHONE
 *    EEC_SNDSIGTY_RADIO_FOG
 *    EEC_SNDSIGTY_REED
 *    EEC_SNDSIGTY_SIREN
 *    EEC_SNDSIGTY_SUBMARINE_CONNECTED
 *    EEC_SNDSIGTY_SUBMARINE_FOG_BELL
 *    EEC_SNDSIGTY_SUBMARINE_NOT_CONNECTED
 *    EEC_SNDSIGTY_SUBMARINE_OSCILLATOR
 *    EEC_SNDSIGTY_TYFON
 *    EEC_SNDSIGTY_WHISTLE
 *
 * Group Membership: ACOUSTIC_PHENOMENON, COMMUNICATION
 */
#define EAC_SOUND_SIGNAL_TYPE ((EDCS_Attribute_Code)1303)

/*
 * Definition:
 *     The type of a <SOUNDING_DATUM>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SNDGDTMTY_APPROX_LOWEST_ASTRONOMICAL_TIDE
 *    EEC_SNDGDTMTY_APPROX_MEAN_LOW_SPRINGS
 *    EEC_SNDGDTMTY_APPROX_MEAN_LOW_WATER
 *    EEC_SNDGDTMTY_APPROX_MEAN_LOWER_LOW_WATER
 *    EEC_SNDGDTMTY_APPROX_MEAN_SEA_LEVEL
 *    EEC_SNDGDTMTY_CHART_DATUM_UNSPECIFIED
 *    EEC_SNDGDTMTY_EQUINOCTIAL_SPRING_LOW_WATER
 *    EEC_SNDGDTMTY_HGHR_HIGH_LARGE_TIDE
 *    EEC_SNDGDTMTY_HGHR_HIGH_WATER
 *    EEC_SNDGDTMTY_HIGH_WATER
 *    EEC_SNDGDTMTY_HIGH_WATER_SPRINGS
 *    EEC_SNDGDTMTY_HIGHEST_ASTRONOMICAL_TIDE
 *    EEC_SNDGDTMTY_HIGHEST_HIGH_WATER
 *    EEC_SNDGDTMTY_HIGHEST_NORMAL_HIGH_WATER
 *    EEC_SNDGDTMTY_IGLD_1985
 *    EEC_SNDGDTMTY_INDIAN_SPRING_HIGH_WATER
 *    EEC_SNDGDTMTY_INDIAN_SPRING_LOW_WATER
 *    EEC_SNDGDTMTY_LOCAL_DATUM
 *    EEC_SNDGDTMTY_LOW_WATER
 *    EEC_SNDGDTMTY_LOW_WATER_SPRINGS
 *    EEC_SNDGDTMTY_LOWER_LOW_LARGE_TIDE
 *    EEC_SNDGDTMTY_LOWER_LOW_WATER
 *    EEC_SNDGDTMTY_LOWEST_ASTRONOMICAL_TIDE
 *    EEC_SNDGDTMTY_LOWEST_LOW_SPRINGS
 *    EEC_SNDGDTMTY_LOWEST_LOW_WATER
 *    EEC_SNDGDTMTY_MEAN_HGHR_HIGH_SPRINGS
 *    EEC_SNDGDTMTY_MEAN_HGHR_HIGH_WATER
 *    EEC_SNDGDTMTY_MEAN_HIGH_NEAPS
 *    EEC_SNDGDTMTY_MEAN_HIGH_SPRINGS
 *    EEC_SNDGDTMTY_MEAN_HIGH_WATER
 *    EEC_SNDGDTMTY_MEAN_LOW_NEAPS
 *    EEC_SNDGDTMTY_MEAN_LOW_SPRINGS
 *    EEC_SNDGDTMTY_MEAN_LOW_WATER
 *    EEC_SNDGDTMTY_MEAN_LOWER_LOW_SPRINGS
 *    EEC_SNDGDTMTY_MEAN_LOWER_LOW_WATER
 *    EEC_SNDGDTMTY_MEAN_SEA_LEVEL
 *    EEC_SNDGDTMTY_MEAN_TIDE_LEVEL
 *    EEC_SNDGDTMTY_MEAN_WATER_LEVEL
 *    EEC_SNDGDTMTY_NATIONAL_DATUM
 *    EEC_SNDGDTMTY_NEAP_TIDE
 *    EEC_SNDGDTMTY_NEARLY_HIGHEST_HIGH
 *    EEC_SNDGDTMTY_NEARLY_LOWEST_LOW_WATER
 *    EEC_SNDGDTMTY_SPRING_TIDE
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_SOUNDING_DATUM_TYPE ((EDCS_Attribute_Code)1304)

/*
 * Definition:
 *     The type of exposition of a <<DEPTH_OF_WATERBODY_FLOOR>> measured by
 *     sounding with respect to the surrounding <REGION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SNDGEXPOS_DEEPER
 *    EEC_SNDGEXPOS_SHALLOWER
 *    EEC_SNDGEXPOS_WITHIN_RANGE
 *
 * Group Membership: SURVEY, WATERBODY_FLOOR
 */
#define EAC_SOUNDING_EXPOSITION ((EDCS_Attribute_Code)1305)

/*
 * Definition:
 *     Additional information about a <<DEPTH_OF_WATERBODY_FLOOR>> measured
 *     by sounding.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SNDGINF_ADEQUATE
 *    EEC_SNDGINF_DEPTH_KNOWN
 *    EEC_SNDGINF_DEPTH_UNKNOWN
 *    EEC_SNDGINF_DOUBTFUL
 *    EEC_SNDGINF_DRYING_HEIGHTS
 *    EEC_SNDGINF_IN_POSITION_US
 *    EEC_SNDGINF_IN_POSITION_IHO
 *    EEC_SNDGINF_LEAST_DEPTH_KNOWN
 *    EEC_SNDGINF_LEAST_DEPTH_UNKNOWN_BUT_SAFE
 *    EEC_SNDGINF_MAINTAINED_DEPTH
 *    EEC_SNDGINF_NO_BOTTOM_FOUND
 *    EEC_SNDGINF_NO_BOTTOM_FOUND_AT_DEPTH
 *    EEC_SNDGINF_NOT_ROUTINELY_MAINTAINED
 *    EEC_SNDGINF_OUT_OF_POSITION
 *    EEC_SNDGINF_REPORTED_NOT_CONFIRMED
 *    EEC_SNDGINF_REPORTED_NOT_SURVEYED
 *    EEC_SNDGINF_UNRELIABLE
 *    EEC_SNDGINF_UNRELIABLE_IHO
 *    EEC_SNDGINF_UNRELIABLE_US
 *
 * Group Membership: SURVEY, WATERBODY_FLOOR
 */
#define EAC_SOUNDING_INFORMATION ((EDCS_Attribute_Code)1306)

/*
 * Definition:
 *     The type of sounding technique and/or method of measurement of a
 *     <<DEPTH_OF_WATERBODY_FLOOR>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SNDGMEASTECH_COMPUTER_GENERATED
 *    EEC_SNDGMEASTECH_DIVER
 *    EEC_SNDGMEASTECH_ECHO_SOUNDER
 *    EEC_SNDGMEASTECH_ELECTROMAGNETIC_SENSOR
 *    EEC_SNDGMEASTECH_LASER
 *    EEC_SNDGMEASTECH_LEAD_LINE
 *    EEC_SNDGMEASTECH_LEVELING
 *    EEC_SNDGMEASTECH_MULTI_BEAM
 *    EEC_SNDGMEASTECH_PHOTOGRAMMETRY
 *    EEC_SNDGMEASTECH_SATELLITE_IMAGERY
 *    EEC_SNDGMEASTECH_SIDE_SCAN_SONAR
 *    EEC_SNDGMEASTECH_SWEPT_SIDE_SCAN_SONAR
 *    EEC_SNDGMEASTECH_SWEPT_VERTICAL_ACOUSTIC
 *    EEC_SNDGMEASTECH_WIRE_DRAG
 *
 * Group Membership: SURVEY, WATERBODY_FLOOR
 */
#define EAC_SOUNDING_MEASUREMENT_TECHNIQUE ((EDCS_Attribute_Code)1307)

/*
 * Definition:
 *     The type of correction that has been added to or subtracted from a
 *     sounding velocity instrument reading to obtain the correct
 *     <<DEPTH_OF_WATERBODY_FLOOR>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SNDGVEL_CORRECTED_BY_OTHER_MEANS
 *    EEC_SNDGVEL_MATHEWS_TABLES
 *    EEC_SNDGVEL_SOUND_VELOCITY_METER
 *    EEC_SNDGVEL_SOUNDER_1500_CALIBRATED
 *    EEC_SNDGVEL_SOUNDER_4800_CALIBRATED
 *
 * Group Membership: SURVEY, WATERBODY_FLOOR
 */
#define EAC_SOUNDING_VELOCITY_CORRECTION_TYPE ((EDCS_Attribute_Code)1308)

/*
 * Definition:
 *     The source from which the identification of an <OBJECT> was captured
 *     or upgraded.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SOURCE_BATHYMETRY_0r1_ARC_MINUTE_DIGITAL_DATA_BASE
 *    EEC_SOURCE_BATHYMETRY_0r5_ARC_MINUTE_DIGITAL_DATA_BASE
 *    EEC_SOURCE_BATHYMETRY_5r0_ARC_MINUTE_DIGITAL_DATA_BASE
 *    EEC_SOURCE_BATHYMETRY_VARIABLE_DIGITAL_DATA_BASE
 *    EEC_SOURCE_CARTOGRAPHIC
 *    EEC_SOURCE_CITY_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_CITY_COMPRESSED_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_DIGITAL_AERONAUTICAL_FLIGHT_INFORMATION_FILE
 *    EEC_SOURCE_DIGITAL_MEAN_ELEVATION_DATA
 *    EEC_SOURCE_DIGITAL_NAUTICAL_CHART
 *    EEC_SOURCE_DIGITAL_POINT_POSITIONING_DATA_BASE
 *    EEC_SOURCE_ELEVATION_7r5_ARC_MINUTE_DIGITAL_MODEL
 *    EEC_SOURCE_IMAGE_1_M_CONTROLLED_BASE
 *    EEC_SOURCE_IMAGE_10_M_CONTROLLED_BASE
 *    EEC_SOURCE_IMAGE_3_M_CONTROLLED_BASE
 *    EEC_SOURCE_IMAGE_5_M_CONTROLLED_BASE
 *    EEC_SOURCE_INTERIM_TERRAIN_DATA
 *    EEC_SOURCE_JOG_250K_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_JOG_250K_COMPRESSED_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_JOG_250K_FEATURE_FOUNDATION_DATA
 *    EEC_SOURCE_LANDSAT
 *    EEC_SOURCE_LEVEL_0_DIGITAL_TERRAIN_ELEVATION_DATA
 *    EEC_SOURCE_LEVEL_0_VECTOR_MAP
 *    EEC_SOURCE_LEVEL_1_DIGITAL_FEATURE_ANALYSIS_DATA
 *    EEC_SOURCE_LEVEL_1_DIGITAL_TERRAIN_ELEVATION_DATA
 *    EEC_SOURCE_LEVEL_1_DIGITAL_TOPOGRAPHIC_DATA
 *    EEC_SOURCE_LEVEL_1_VECTOR_MAP
 *    EEC_SOURCE_LEVEL_1C_DIGITAL_FEATURE_ANALYSIS_DATA
 *    EEC_SOURCE_LEVEL_2_DIGITAL_FEATURE_ANALYSIS_DATA
 *    EEC_SOURCE_LEVEL_2_DIGITAL_TERRAIN_ELEVATION_DATA
 *    EEC_SOURCE_LEVEL_2_DIGITAL_TOPOGRAPHIC_DATA
 *    EEC_SOURCE_LEVEL_2_VECTOR_MAP
 *    EEC_SOURCE_LEVEL_3_DIGITAL_TERRAIN_ELEVATION_DATA
 *    EEC_SOURCE_LEVEL_3_DIGITAL_TOPOGRAPHIC_DATA
 *    EEC_SOURCE_LEVEL_3C_DIGITAL_FEATURE_ANALYSIS_DATA
 *    EEC_SOURCE_LEVEL_4_DIGITAL_TERRAIN_ELEVATION_DATA
 *    EEC_SOURCE_LEVEL_4_DIGITAL_TOPOGRAPHIC_DATA
 *    EEC_SOURCE_LEVEL_5_DIGITAL_TERRAIN_ELEVATION_DATA
 *    EEC_SOURCE_LEVEL_5_DIGITAL_TOPOGRAPHIC_DATA
 *    EEC_SOURCE_LITTORAL_WARFARE_DATA
 *    EEC_SOURCE_MONO_IMAGERY
 *    EEC_SOURCE_ONC_1M_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_ONC_1M_COMPRESSED_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_ONC_1M_DIGITAL_CHART_OF_WORLD
 *    EEC_SOURCE_PLANNING_INTERIM_TERRAIN_DATA
 *    EEC_SOURCE_REPORTED
 *    EEC_SOURCE_SPOT
 *    EEC_SOURCE_STEREO_IMAGERY
 *    EEC_SOURCE_SURVEY_SOURCE
 *    EEC_SOURCE_TLM_100K_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_TLM_100K_COMPRESSED_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_TLM_50K_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_TLM_50K_COMPRESSED_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_TLM_50K_FEATURE_FOUNDATION_DATA
 *    EEC_SOURCE_TPC_500K_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_TPC_500K_COMPRESSED_ARC_DIGITIZED_RASTER_GRAPHIC
 *    EEC_SOURCE_URBAN_VECTOR_MAP
 *    EEC_SOURCE_VECTOR_INTERIM_TERRAIN_DATA
 *    EEC_SOURCE_WORLD_VECTOR_SHORELINE
 *
 * Group Membership: IDENTIFICATION
 */
#define EAC_SOURCE ((EDCS_Attribute_Code)1309)

/*
 * Definition:
 *     The date a source data set (for example: a <MAP>) was originally
 *     compiled. The date is formatted as specified by <<DATE_FORMAT>> or by
 *     <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TIME
 */
#define EAC_SOURCE_DATA_SET_COMPILE_DATE ((EDCS_Attribute_Code)1310)

/*
 * Definition:
 *     The edition of a source data set (for example: a <MAP>).
 *
 * Value Type: STRING
 *
 * Group Membership: IDENTIFICATION
 */
#define EAC_SOURCE_DATA_SET_EDITION ((EDCS_Attribute_Code)1311)

/*
 * Definition:
 *     General information about, and description of conditions within, a
 *     source data set (for example: a <MAP>).
 *
 * Value Type: STRING
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define EAC_SOURCE_DATA_SET_GENERAL_INFORMATION ((EDCS_Attribute_Code)1312)

/*
 * Definition:
 *     The name or identification number of the first source data set (for
 *     example: a <MAP>).
 *
 * Value Type: STRING
 *
 * Group Membership: IDENTIFICATION
 */
#define EAC_SOURCE_DATA_SET_NAME ((EDCS_Attribute_Code)1313)

/*
 * Definition:
 *     The date a source data set (for example: a <MAP>) was last printed.
 *     The date is formatted as specified by <<DATE_FORMAT>> or by
 *     <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TIME
 */
#define EAC_SOURCE_DATA_SET_PRINT_DATE ((EDCS_Attribute_Code)1314)

/*
 * Definition:
 *     The date a source data set (for example: a <MAP>) was last revised.
 *     The date is formatted as specified by <<DATE_FORMAT>> or by
 *     <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TIME
 */
#define EAC_SOURCE_DATA_SET_REVISION_DATE ((EDCS_Attribute_Code)1315)

/*
 * Definition:
 *     The angular primary axis coordinate value for a defined spatial
 *     reference frame.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE ((EDCS_Attribute_Code)1316)

/*
 * Definition:
 *     The angular secondary axis coordinate value for a defined spatial
 *     reference frame.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE ((EDCS_Attribute_Code)1317)

/*
 * Definition:
 *     The linear primary axis coordinate value for a defined spatial
 *     reference frame.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE ((EDCS_Attribute_Code)1318)

/*
 * Definition:
 *     The linear secondary axis coordinate value for a defined spatial
 *     reference frame.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE ((EDCS_Attribute_Code)1319)

/*
 * Definition:
 *     The linear tertiary axis coordinate value for a defined spatial
 *     reference frame.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION
 */
#define EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE ((EDCS_Attribute_Code)1320)

/*
 * Definition:
 *     The ratio of the <<MATERIAL_DENSITY>> of a substance to that of
 *     <WATER> at 277,15 kelvin (4 degrees Celsius); the specific gravity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_SPECIFIC_GRAVITY ((EDCS_Attribute_Code)1321)

/*
 * Definition:
 *     The quantity of energy required to raise the <<TEMPERATURE>> of a unit
 *     <<MASS>> of a <MATERIAL> by one kelvin; the specific heat.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPECIFIC_HEAT_CAPACITY
 *
 * Group Membership: MATERIAL, TEMPERATURE
 */
#define EAC_SPECIFIC_HEAT ((EDCS_Attribute_Code)1322)

/*
 * Definition:
 *     The ratio of the <<MASS>> of water vapour to the total <<MASS>> of a
 *     <<VOLUME>> of moist <AIR>; the specific humidity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS_FRACTION
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_SPECIFIC_HUMIDITY ((EDCS_Attribute_Code)1323)

/*
 * Definition:
 *     A measure of the rate of motion of an <OBJECT>; speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_SPEED ((EDCS_Attribute_Code)1324)

/*
 * Definition:
 *     The number of sperm <WHALE>s caught within a one-year
 *     <<TIME_QUANTITY>>.
 *
 * Value Type: COUNT
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define EAC_SPERM_WHALE_CATCH_PER_YEAR ((EDCS_Attribute_Code)1325)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of breaking <WATER_WAVE>s that are spilling. Spilling is a
 *     breaking process wherein the <WATER_WAVE> peaks up until it is very
 *     steep but not vertical; only the top most portion of the <WATER_WAVE>
 *     curls over and descends on the forward slope of the advancing
 *     <WATER_WAVE> where it then slides down into the trough. This process
 *     starts at scattered foci which coalesce until the <WATER_WAVE>
 *     becomes an advancing <LINE> of foam.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_SPILLING_BREAKER_FRACTION ((EDCS_Attribute_Code)1326)

/*
 * Definition:
 *     The type of sport or exercise performed on an <ATHLETIC_FIELD> or
 *     <SPORTS_ARENA>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SPORTTY_AMERICAN_FOOTBALL
 *    EEC_SPORTTY_ASSOCIATION_FOOTBALL
 *    EEC_SPORTTY_AUSTRALIAN_RULES_FOOTBALL
 *    EEC_SPORTTY_CANADIAN_FOOTBALL
 *    EEC_SPORTTY_RUGBY
 *    EEC_SPORTTY_TROTTING
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define EAC_SPORT_TYPE ((EDCS_Attribute_Code)1327)

/*
 * Definition:
 *     The type of a <<TERRAIN_ELEVATION>> measurement at a <LOCATION>; the
 *     spot elevation type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SPOTELEVTY_NON_TERRAIN_SURFACE
 *    EEC_SPOTELEVTY_OUT_OF_POSITION
 *    EEC_SPOTELEVTY_SUMMIT
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_SPOT_ELEVATION_TYPE ((EDCS_Attribute_Code)1328)

/*
 * Definition:
 *     The type of a <SPRING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SPRTY_ARTESIAN
 *    EEC_SPRTY_FUMAROLE
 *    EEC_SPRTY_GEYSER
 *    EEC_SPRTY_HOT_SPRING
 *    EEC_SPRTY_WALLED_IN
 *
 * Group Membership: HYDROLOGY
 */
#define EAC_SPRING_TYPE ((EDCS_Attribute_Code)1329)

/*
 * Definition:
 *     The type of <MATERIAL> and/or techniques used to construct a <STAIR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_STAIRCNSTCTTY_ENGINEERED_LUMBER
 *    EEC_STAIRCNSTCTTY_LUMBER
 *    EEC_STAIRCNSTCTTY_REINFORCED_CONCRETE
 *    EEC_STAIRCNSTCTTY_STEEL
 *    EEC_STAIRCNSTCTTY_STEEL_WITH_CONCRETE_FILL
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_STAIR_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)1330)

/*
 * Definition:
 *     The architectural style of a <STAIR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_STAIRSTYLE_CIRCULAR
 *    EEC_STAIRSTYLE_EXTERIOR_OPEN
 *    EEC_STAIRSTYLE_INTERIOR_ENCLOSED
 *    EEC_STAIRSTYLE_INTERIOR_OPEN
 *    EEC_STAIRSTYLE_DOG_LEG
 *    EEC_STAIRSTYLE_HALF_TURN
 *    EEC_STAIRSTYLE_STRAIGHT_RUN
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_STAIR_STYLE ((EDCS_Attribute_Code)1331)

/*
 * Definition:
 *     A scalar governing the aerodynamic heat transfer coefficient of an
 *     <OBJECT>; the Stanton number.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_STANTON_NUMBER ((EDCS_Attribute_Code)1332)

/*
 * Definition:
 *     The stellar flux of alpha <PARTICLE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PARTICLE_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_ALPHA_FLUX ((EDCS_Attribute_Code)1333)

/*
 * Definition:
 *     The stellar flux of electrons.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PARTICLE_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_ELECTRON_FLUX ((EDCS_Attribute_Code)1334)

/*
 * Definition:
 *     The stellar electromagnetic flux level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_EM_FLUX ((EDCS_Attribute_Code)1335)

/*
 * Definition:
 *     The stellar flux of protons.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PARTICLE_FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_PROTON_FLUX ((EDCS_Attribute_Code)1336)

/*
 * Definition:
 *     The intensity of <STELLAR_FLUX_RADIO_FREQUENCY_EMISSION> at 10,7
 *     centimetre <<WAVELENGTH>> (2,8 gigahertz).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_RF_FLUX_10r7 ((EDCS_Attribute_Code)1337)

/*
 * Definition:
 *     The time of the maximum electromagnetic flux of a
 *     <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise event relative to the
 *     beginning of the day (midnight).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: EM_PHENOMENON, SPACE, TIME
 */
#define EAC_STELLAR_RF_NB_MAXIMUM_TIME ((EDCS_Attribute_Code)1338)

/*
 * Definition:
 *     The quality of a <<STELLAR_RF_NB_MAXIMUM_TIME>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRNBMAXTIMQUAL_BEGAN_BEFORE
 *    EEC_SRNBMAXTIMQUAL_LASTED_LONGER
 *    EEC_SRNBMAXTIMQUAL_MEASUREMENT_UNCERTAINTY
 *
 * Group Membership: EM_PHENOMENON, SPACE, TIME
 */
#define EAC_STELLAR_RF_NB_MAXIMUM_TIME_QUALITY ((EDCS_Attribute_Code)1339)

/*
 * Definition:
 *     The mean electromagnetic flux of a
 *     <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise event.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_RF_NB_MEAN_FLUX ((EDCS_Attribute_Code)1340)

/*
 * Definition:
 *     The quality of a <<STELLAR_RF_NB_MEAN_FLUX>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRNBMNFLUXQUAL_BEGAN_BEFORE
 *    EEC_SRNBMNFLUXQUAL_LASTED_LONGER
 *    EEC_SRNBMNFLUXQUAL_MEASUREMENT_UNCERTAINTY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_RF_NB_MEAN_FLUX_QUALITY ((EDCS_Attribute_Code)1341)

/*
 * Definition:
 *     The peak electromagnetic flux of a
 *     <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise event.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FLUX_DENSITY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_RF_NB_PEAK_FLUX ((EDCS_Attribute_Code)1342)

/*
 * Definition:
 *     The quality of a <<STELLAR_RF_NB_PEAK_FLUX>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRNBPKFLUXQUAL_BEGAN_BEFORE
 *    EEC_SRNBPKFLUXQUAL_LASTED_LONGER
 *    EEC_SRNBPKFLUXQUAL_MEASUREMENT_UNCERTAINTY
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_RF_NB_PEAK_FLUX_QUALITY ((EDCS_Attribute_Code)1343)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> of a <STELLAR_BURST_RADIO_FREQUENCY_EMISSION>
 *     noise event.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: EM_PHENOMENON, SPACE, TIME
 */
#define EAC_STELLAR_RF_NB_PERIOD ((EDCS_Attribute_Code)1344)

/*
 * Definition:
 *     The quality of a <<STELLAR_RF_NB_PERIOD>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRNBPERQUAL_BEGAN_BEFORE
 *    EEC_SRNBPERQUAL_LASTED_LONGER
 *    EEC_SRNBPERQUAL_MEASUREMENT_UNCERTAINTY
 *
 * Group Membership: EM_PHENOMENON, SPACE, TIME
 */
#define EAC_STELLAR_RF_NB_PERIOD_QUALITY ((EDCS_Attribute_Code)1345)

/*
 * Definition:
 *     A descriptive or explanatory comment (remarks) regarding a
 *     <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise event.
 *
 * Value Type: STRING
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_RF_NB_REMARKS ((EDCS_Attribute_Code)1346)

/*
 * Definition:
 *     The starting time of a <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise
 *     event relative to the beginning of the day (midnight).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: EM_PHENOMENON, SPACE, TIME
 */
#define EAC_STELLAR_RF_NB_START ((EDCS_Attribute_Code)1347)

/*
 * Definition:
 *     The quality of a <<STELLAR_RF_NB_START>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRNBSTRTQUAL_BEGAN_BEFORE
 *    EEC_SRNBSTRTQUAL_LASTED_LONGER
 *    EEC_SRNBSTRTQUAL_MEASUREMENT_UNCERTAINTY
 *
 * Group Membership: EM_PHENOMENON, SPACE, TIME
 */
#define EAC_STELLAR_RF_NB_START_QUALITY ((EDCS_Attribute_Code)1348)

/*
 * Definition:
 *     The <<TEMPERATURE>> of ionized <PARTICLE>s in a <STELLAR_WIND>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: EM_PHENOMENON, SPACE, TEMPERATURE
 */
#define EAC_STELLAR_WIND_ION_TEMPERATURE ((EDCS_Attribute_Code)1349)

/*
 * Definition:
 *     The density of protons in a <STELLAR_WIND>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_DENSITY
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SPACE
 */
#define EAC_STELLAR_WIND_PROTON_DENSITY ((EDCS_Attribute_Code)1350)

/*
 * Definition:
 *     The <<SPEED>> of a <STELLAR_WIND>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SPACE
 */
#define EAC_STELLAR_WIND_SPEED ((EDCS_Attribute_Code)1351)

/*
 * Definition:
 *     The <<STELLAR_WIND_SPEED>> in the <DIRECTION> of the <SUN> (in the
 *     ecliptic plane) and positive towards the <SUN>; the stellar wind
 *     speed GSE X.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SPACE
 */
#define EAC_STELLAR_WIND_SPEED_GSE_X ((EDCS_Attribute_Code)1352)

/*
 * Definition:
 *     The <<STELLAR_WIND_SPEED>> in the ecliptic plane in a <DIRECTION>
 *     perpendicular to the <DIRECTION> of the <SUN>, pointing generally
 *     opposite to the <DIRECTION> of revolution of the <EARTH> about the
 *     <SUN>, and positive in the contra-revolution <DIRECTION>; the stellar
 *     wind speed GSE Y.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SPACE
 */
#define EAC_STELLAR_WIND_SPEED_GSE_Y ((EDCS_Attribute_Code)1353)

/*
 * Definition:
 *     The <<STELLAR_WIND_SPEED>> perpendicular to the ecliptic plane and
 *     positive towards the <STAR> Polaris; the stellar wind speed GSE Z.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SPACE
 */
#define EAC_STELLAR_WIND_SPEED_GSE_Z ((EDCS_Attribute_Code)1354)

/*
 * Definition:
 *     The intensity (flux) of stellar x-rays in the L-band (0,1 - 0,8
 *     nanometres <<WAVELENGTH>>).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RADIANT_EXITANCE_RATE
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_X_RAY_FLUX_L_BAND ((EDCS_Attribute_Code)1355)

/*
 * Definition:
 *     The intensity (flux) of stellar x-rays in the S-band (0,05 - 0,4
 *     nanometres <<WAVELENGTH>>).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RADIANT_EXITANCE_RATE
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_STELLAR_X_RAY_FLUX_S_BAND ((EDCS_Attribute_Code)1356)

/*
 * Definition:
 *     The diameter of the stem/trunk of a <PLANT> measured at a
 *     <<HEIGHT_AGL>> of 1,4 metres.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIVING_ORGANISM, PLANT
 */
#define EAC_STEM_DIAMETER ((EDCS_Attribute_Code)1357)

/*
 * Definition:
 *     The type of storage <FACILITY>s available at or in the near vicinity
 *     of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_STORFACTY_AMMUNITION
 *    EEC_STORFACTY_DIESEL_OIL
 *    EEC_STORFACTY_DUTCH_BARN
 *    EEC_STORFACTY_EXPLOSIVE
 *    EEC_STORFACTY_FOOD
 *    EEC_STORFACTY_GAS
 *    EEC_STORFACTY_GRAIN
 *    EEC_STORFACTY_GRAVEL
 *    EEC_STORFACTY_HARD_STANDING_ONLY
 *    EEC_STORFACTY_LIQUID
 *    EEC_STORFACTY_NONE_AVAILABLE
 *    EEC_STORFACTY_OIL
 *    EEC_STORFACTY_ORE
 *    EEC_STORFACTY_PETROL
 *    EEC_STORFACTY_SALT
 *    EEC_STORFACTY_SAND
 *    EEC_STORFACTY_SOFT_STANDING_ONLY
 *    EEC_STORFACTY_SPECIALIZED_WAREHOUSE
 *    EEC_STORFACTY_WAREHOUSE
 *    EEC_STORFACTY_WATER
 *
 * Group Membership: ABSTRACT_OBJECT, USAGE_REGION
 */
#define EAC_STORAGE_FACILITY_TYPE ((EDCS_Attribute_Code)1358)

/*
 * Definition:
 *     The type of a <STRUCTURAL_PILE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_STRPILETY_POST
 *    EEC_STRPILETY_SNAG
 *    EEC_STRPILETY_STAKE
 *    EEC_STRPILETY_TRIPODAL
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_STRUCTURAL_PILE_TYPE ((EDCS_Attribute_Code)1359)

/*
 * Definition:
 *     The areal density of <STRUCTURE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: RATE_OR_RATIO, SUPPORT_STRUCTURE
 */
#define EAC_STRUCTURE_DENSITY ((EDCS_Attribute_Code)1360)

/*
 * Definition:
 *     The type of <LIGHTING> on or in a <STRUCTURE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_STRLGTTY_FLOODLIT
 *    EEC_STRLGTTY_ILLUMINATED
 *    EEC_STRLGTTY_NOT_FLOODLIT
 *
 * Group Membership: ABSTRACT_OBJECT, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_STRUCTURE_LIGHTING_TYPE ((EDCS_Attribute_Code)1361)

/*
 * Definition:
 *     The type/degree to which a <STRUCTURE> provides protection to itself
 *     or its contents by resisting the effects of an explosion, a
 *     <MUNITION>, and a natural disaster (for example: a hurricane, a
 *     tornado, and/or an earthquake).
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_STRPROTTY_NO_PROTECTION
 *    EEC_STRPROTTY_SOFT
 *    EEC_STRPROTTY_SEMI_HARDENED
 *    EEC_STRPROTTY_HARDENED
 *
 * Group Membership: MILITARY_SCIENCE, SHELTER, SUPPORT_STRUCTURE
 */
#define EAC_STRUCTURE_PROTECTION_TYPE ((EDCS_Attribute_Code)1362)

/*
 * Definition:
 *     The geometric form or configuration of an <OBJECT>; the structure
 *     shape.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_STRSHAP_A_FRAME
 *    EEC_STRSHAP_AIRSHIP
 *    EEC_STRSHAP_ARCH
 *    EEC_STRSHAP_ARTIFICIAL_MOUNTAIN
 *    EEC_STRSHAP_BARREL
 *    EEC_STRSHAP_BLIMP
 *    EEC_STRSHAP_BOARD
 *    EEC_STRSHAP_BULLET
 *    EEC_STRSHAP_COLUMN
 *    EEC_STRSHAP_CRESCENT
 *    EEC_STRSHAP_CROSS
 *    EEC_STRSHAP_CUBIC
 *    EEC_STRSHAP_CYLINDER
 *    EEC_STRSHAP_CYLINDER_PEAKED
 *    EEC_STRSHAP_CYLINDER_PEAKED_WITH_TOWER
 *    EEC_STRSHAP_CYLINDER_UPRIGHT
 *    EEC_STRSHAP_CYLINDER_WITH_DOMED_TOP
 *    EEC_STRSHAP_CYLINDER_WITH_FLAT_TOP
 *    EEC_STRSHAP_DIAMOND_SHAPED
 *    EEC_STRSHAP_DOME
 *    EEC_STRSHAP_DRAGON_TEETH
 *    EEC_STRSHAP_ENCLOSED
 *    EEC_STRSHAP_FERRIS_WHEEL
 *    EEC_STRSHAP_FUNNEL
 *    EEC_STRSHAP_H_FRAME
 *    EEC_STRSHAP_HIGH_RISE
 *    EEC_STRSHAP_I_BEAM
 *    EEC_STRSHAP_I_FRAME
 *    EEC_STRSHAP_IRREGULAR
 *    EEC_STRSHAP_LATERAL
 *    EEC_STRSHAP_MAST
 *    EEC_STRSHAP_MOUND
 *    EEC_STRSHAP_MULTIPLE_ARCH
 *    EEC_STRSHAP_OBELISK
 *    EEC_STRSHAP_OPEN
 *    EEC_STRSHAP_OPEN_ENDED
 *    EEC_STRSHAP_OVAL
 *    EEC_STRSHAP_PEAKED
 *    EEC_STRSHAP_PILLAR
 *    EEC_STRSHAP_PILLAR_OR_SPINDLE
 *    EEC_STRSHAP_PLAQUE
 *    EEC_STRSHAP_POLE
 *    EEC_STRSHAP_PYRAMID
 *    EEC_STRSHAP_RECTANGULAR
 *    EEC_STRSHAP_RIPPLE
 *    EEC_STRSHAP_ROLLER_COASTER
 *    EEC_STRSHAP_ROUND
 *    EEC_STRSHAP_RUIN
 *    EEC_STRSHAP_SCANNER
 *    EEC_STRSHAP_SOLID
 *    EEC_STRSHAP_SPAR
 *    EEC_STRSHAP_SPHERICAL_HEMISPHERICAL
 *    EEC_STRSHAP_SPHERICAL_WITH_COLUMNS
 *    EEC_STRSHAP_SPINDLE
 *    EEC_STRSHAP_SPIRE
 *    EEC_STRSHAP_SQUARE
 *    EEC_STRSHAP_STAR
 *    EEC_STRSHAP_STATUE
 *    EEC_STRSHAP_SUPERBUOY
 *    EEC_STRSHAP_T_FRAME
 *    EEC_STRSHAP_TELESCOPING_GASHOLDER
 *    EEC_STRSHAP_TETRAHEDRON
 *    EEC_STRSHAP_TOWER
 *    EEC_STRSHAP_TOWER_MOUNTED_RADOME
 *    EEC_STRSHAP_TRANSVERSE
 *    EEC_STRSHAP_TRIPOD
 *    EEC_STRSHAP_TRUSS
 *    EEC_STRSHAP_VESSEL_HULL
 *    EEC_STRSHAP_WINDMOTOR
 *    EEC_STRSHAP_WITH_RADOME
 *    EEC_STRSHAP_Y_FRAME
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_STRUCTURE_SHAPE ((EDCS_Attribute_Code)1363)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing linearly-scaled
 *     fractional canopy cover of <TREE>s during the summer within a
 *     delineated <REGION> of <LAND>. Zero means no cover and one means
 *     completely covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT, RATE_OR_RATIO, TIME
 */
#define EAC_SUMMER_CANOPY_COVER_FRACTION ((EDCS_Attribute_Code)1364)

/*
 * Definition:
 *     The <<TIME_OF_DAY>> of sunrise. The time of sunrise is defined to
 *     occur when the geometric zenith distance of the centre of the <SUN>
 *     is 90,8333 arc degrees; that is, the centre of the <SUN> is
 *     geometrically 50 arc minutes below a horizontal plane for an observer
 *     at MSL with a level, unobstructed eastern horizon under average
 *     atmospheric conditions. The upper limb of the <SUN> will then appear
 *     to be tangent to the eastern horizon. The 50 arc minute geometric
 *     depression of the centre of the <SUN> used for the computations is
 *     obtained by adding the average apparent <<RADIUS>> of the <SUN> (16
 *     arc minutes) to the average amount of atmospheric refraction at the
 *     horizon (34 arc minutes).
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE, TIME
 */
#define EAC_SUNRISE_TIME ((EDCS_Attribute_Code)1365)

/*
 * Definition:
 *     The <<TIME_OF_DAY>> of sunset. The time of sunset is defined to occur
 *     when the geometric zenith distance of the centre of the <SUN> is
 *     90,8333 arc degrees; that is, the centre of the <SUN> is
 *     geometrically 50 arc minutes below a horizontal plane for an observer
 *     at MSL with a level, unobstructed western horizon under average
 *     atmospheric conditions. The upper limb of the <SUN> will then appear
 *     to be tangent to the western horizon. The 50 arc minute geometric
 *     depression of the centre of the <SUN> used for the computations is
 *     obtained by adding the average apparent <<RADIUS>> of the <SUN> (16
 *     arc minutes) to the average amount of atmospheric refraction at the
 *     horizon (34 arc minutes).
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: EM_PHENOMENON, LIGHTING_AND_VISIBILITY, SPACE, TIME
 */
#define EAC_SUNSET_TIME ((EDCS_Attribute_Code)1366)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> over which an observation of solar
 *     <<ILLUMINANCE>> was taken; the sunshine observation period.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: EM_PHENOMENON, SPACE, TIME
 */
#define EAC_SUNSHINE_OBSERVATION_PERIOD ((EDCS_Attribute_Code)1367)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> that solar irradiation occurred; the sunshine
 *     period.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: EM_PHENOMENON, SPACE, TIME
 */
#define EAC_SUNSHINE_PERIOD ((EDCS_Attribute_Code)1368)

/*
 * Definition:
 *     The number of <SUNSPOT>s observed; the sunspot number (SSN).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_SUNSPOT_NUMBER ((EDCS_Attribute_Code)1369)

/*
 * Definition:
 *     The total number of <SUNSPOT>s plus ten times the number of <SUNSPOT>
 *     groups in a given <<TIME_QUANTITY>>(usually one month); the sunspot
 *     number index.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define EAC_SUNSPOT_NUMBER_INDEX ((EDCS_Attribute_Code)1370)

/*
 * Definition:
 *     The lateral slope (rise/run) of a <LAND_TRANSPORTATION_ROUTE>; the
 *     superelevation.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_SUPERELEVATION ((EDCS_Attribute_Code)1371)

/*
 * Definition:
 *     The areal density of supertanker <WATER_SURFACE_VESSEL>s. A
 *     supertanker <WATER_SURFACE_VESSEL> is characterized by a dead weight
 *     greater than 318 000 kilograms (approximately 350 000 tons) and a
 *     <<LENGTH>> greater than 325 metres).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_SUPERTANKER_DENSITY ((EDCS_Attribute_Code)1372)

/*
 * Definition:
 *     The maximum angle between the <SURFACE> of an <OBJECT> and a
 *     perpendicular to the local gravity vector. The value is selected to
 *     be between 0 and 90 arc degrees (or equivalent).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, SURFACE
 */
#define EAC_SURFACE_ANGLE ((EDCS_Attribute_Code)1373)

/*
 * Definition:
 *     The negative of the ratio of the flux returned (reflected directly
 *     back in the <DIRECTION> of incidence) to the incident flux in
 *     decibels of the <SURFACE> of an <OBJECT>; the surface backscatter.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: RATE_OR_RATIO, SURFACE
 */
#define EAC_SURFACE_BACKSCATTER ((EDCS_Attribute_Code)1374)

/*
 * Definition:
 *     The category of the <SURFACE> of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRFCAT_EXTERIOR
 *    EEC_SRFCAT_INTERIOR
 *
 * Group Membership: SURFACE
 */
#define EAC_SURFACE_CATEGORY ((EDCS_Attribute_Code)1375)

/*
 * Definition:
 *     The principal characteristic type of a <SURFACE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRFCHRTY_BARE
 *    EEC_SRFCHRTY_BROKEN
 *    EEC_SRFCHRTY_CALCAREOUS
 *    EEC_SRFCHRTY_COARSE
 *    EEC_SRFCHRTY_DECAYED
 *    EEC_SRFCHRTY_FINE_PARTICLES
 *    EEC_SRFCHRTY_FLINTY
 *    EEC_SRFCHRTY_GLACIAL
 *    EEC_SRFCHRTY_GRITTY
 *    EEC_SRFCHRTY_GROUND
 *    EEC_SRFCHRTY_HARD
 *    EEC_SRFCHRTY_KARST
 *    EEC_SRFCHRTY_LARGE_PARTICLES
 *    EEC_SRFCHRTY_MEDIUM_PARTICLES
 *    EEC_SRFCHRTY_MEMBRANE
 *    EEC_SRFCHRTY_ROCKY
 *    EEC_SRFCHRTY_ROTTEN
 *    EEC_SRFCHRTY_SMALL_PARTICLES
 *    EEC_SRFCHRTY_SOFT
 *    EEC_SRFCHRTY_SPECKLED
 *    EEC_SRFCHRTY_SPRINGS_IN_SEABED
 *    EEC_SRFCHRTY_STICKY
 *    EEC_SRFCHRTY_STIFF
 *    EEC_SRFCHRTY_STREAKY
 *    EEC_SRFCHRTY_TENACIOUS
 *    EEC_SRFCHRTY_UNEVEN
 *    EEC_SRFCHRTY_UNSTABLE
 *    EEC_SRFCHRTY_UNSURFACED
 *    EEC_SRFCHRTY_VARIED
 *    EEC_SRFCHRTY_VOLCANIC
 *
 * Group Membership: SURFACE
 */
#define EAC_SURFACE_CHARACTERISTIC_TYPE ((EDCS_Attribute_Code)1376)

/*
 * Definition:
 *     The ratio of absorbed to incident electromagnetic flux at a <SURFACE>;
 *     the surface electromagnetic absorptivity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SURFACE
 */
#define EAC_SURFACE_EM_ABSORPTIVITY ((EDCS_Attribute_Code)1377)

/*
 * Definition:
 *     The <<SURFACE_EM_ABSORPTIVITY>> of all appreciable solar flux (from
 *     about 0,0 to 3,0 micrometres in <<WAVELENGTH>>); if expressed in
 *     decibels, the negative of the value is used; the surface solar
 *     electromagnetic absorptivity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO, SURFACE
 */
#define EAC_SURFACE_EM_ABSORPTIVITY_SOLAR ((EDCS_Attribute_Code)1378)

/*
 * Definition:
 *     The <<HEIGHT_AGL>> of the top of a <SURFACE_BASED_EM_DUCT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: EM_PHENOMENON, LOCATION
 */
#define EAC_SURFACE_EM_DUCT_HEIGHT ((EDCS_Attribute_Code)1379)

/*
 * Definition:
 *     The strength of a <SURFACE_BASED_EM_DUCT> as defined by the difference
 *     between the maximum and minimum <<RF_REFRACTIVE_INDEX_MODIFIED>> of a
 *     trapping layer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON
 */
#define EAC_SURFACE_EM_DUCT_STRENGTH ((EDCS_Attribute_Code)1380)

/*
 * Definition:
 *     The composition of the <MATERIAL> of the <SURFACE> of an <OBJECT>
 *     excluding internal structural <MATERIAL>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRFMATTY_AIRCRAFT
 *    EEC_SRFMATTY_ALUMINUM
 *    EEC_SRFMATTY_AMMUNITION
 *    EEC_SRFMATTY_ASH
 *    EEC_SRFMATTY_ASPHALT
 *    EEC_SRFMATTY_BASALT
 *    EEC_SRFMATTY_BEDROCK
 *    EEC_SRFMATTY_BITUMINOUS
 *    EEC_SRFMATTY_BOULDER
 *    EEC_SRFMATTY_BRICK
 *    EEC_SRFMATTY_CALCAREOUS
 *    EEC_SRFMATTY_CEMENT
 *    EEC_SRFMATTY_CHALK
 *    EEC_SRFMATTY_CHEMICAL
 *    EEC_SRFMATTY_CINDER
 *    EEC_SRFMATTY_CIRRIPEDIA
 *    EEC_SRFMATTY_CLAY
 *    EEC_SRFMATTY_COAL
 *    EEC_SRFMATTY_COBBLE
 *    EEC_SRFMATTY_COKE
 *    EEC_SRFMATTY_COMPOSITE_ge_50_PCT_PERMANENT
 *    EEC_SRFMATTY_COMPOSITE_lt_50_PCT_PERMANENT
 *    EEC_SRFMATTY_COMPOSITION
 *    EEC_SRFMATTY_CONCRETE
 *    EEC_SRFMATTY_CONGLOMERATE
 *    EEC_SRFMATTY_COPPER
 *    EEC_SRFMATTY_CORAL
 *    EEC_SRFMATTY_CORAL_HEAD
 *    EEC_SRFMATTY_DESALINATED_WATER
 *    EEC_SRFMATTY_DIAMOND
 *    EEC_SRFMATTY_DIATOMACEOUS_EARTH
 *    EEC_SRFMATTY_DIORITE
 *    EEC_SRFMATTY_DISTORTED_SURFACE
 *    EEC_SRFMATTY_DOLOMITE
 *    EEC_SRFMATTY_EARTHEN
 *    EEC_SRFMATTY_ELECTRIC
 *    EEC_SRFMATTY_ERODED_LAND
 *    EEC_SRFMATTY_EVAPORITE
 *    EEC_SRFMATTY_EXPLOSIVE
 *    EEC_SRFMATTY_FABRIC
 *    EEC_SRFMATTY_FIBREGLASS
 *    EEC_SRFMATTY_FLYSCH
 *    EEC_SRFMATTY_FOOD
 *    EEC_SRFMATTY_FORAMINIFERA
 *    EEC_SRFMATTY_FROZEN_WATER
 *    EEC_SRFMATTY_FUCUS
 *    EEC_SRFMATTY_GABBRO
 *    EEC_SRFMATTY_GAS
 *    EEC_SRFMATTY_GIBBSITE
 *    EEC_SRFMATTY_GLASS
 *    EEC_SRFMATTY_GLOBIGERINA
 *    EEC_SRFMATTY_GOLD
 *    EEC_SRFMATTY_GRADED_SOIL
 *    EEC_SRFMATTY_GRANITE
 *    EEC_SRFMATTY_GRASS
 *    EEC_SRFMATTY_GRAVEL
 *    EEC_SRFMATTY_GREENSTONE
 *    EEC_SRFMATTY_GROUND
 *    EEC_SRFMATTY_GROUND_SHELL
 *    EEC_SRFMATTY_HERBACEOUS_VEGETATION
 *    EEC_SRFMATTY_ICE
 *    EEC_SRFMATTY_IRON
 *    EEC_SRFMATTY_KARST
 *    EEC_SRFMATTY_KELP
 *    EEC_SRFMATTY_LATERITE
 *    EEC_SRFMATTY_LAVA
 *    EEC_SRFMATTY_LEAD
 *    EEC_SRFMATTY_LOESS
 *    EEC_SRFMATTY_LUMBER
 *    EEC_SRFMATTY_MACADAM
 *    EEC_SRFMATTY_MACADAM_CRUSHED_ROCK
 *    EEC_SRFMATTY_MADREPORE
 *    EEC_SRFMATTY_MANGANESE
 *    EEC_SRFMATTY_MARBLE
 *    EEC_SRFMATTY_MARL
 *    EEC_SRFMATTY_MASONRY
 *    EEC_SRFMATTY_MATTE
 *    EEC_SRFMATTY_MEMBRANE
 *    EEC_SRFMATTY_METAL
 *    EEC_SRFMATTY_MIXED_IN_PLACE
 *    EEC_SRFMATTY_MUD
 *    EEC_SRFMATTY_MULTIPLE_MATERIALS
 *    EEC_SRFMATTY_MUSSEL
 *    EEC_SRFMATTY_NON_TREED_VEGETATION
 *    EEC_SRFMATTY_OIL
 *    EEC_SRFMATTY_OIL_BLISTER
 *    EEC_SRFMATTY_OOZE
 *    EEC_SRFMATTY_OYSTER
 *    EEC_SRFMATTY_PAINT
 *    EEC_SRFMATTY_PAPER
 *    EEC_SRFMATTY_PART_METAL
 *    EEC_SRFMATTY_PEAT
 *    EEC_SRFMATTY_PEBBLE
 *    EEC_SRFMATTY_PEM_MIX
 *    EEC_SRFMATTY_PERMANENT_HARD
 *    EEC_SRFMATTY_PETROL
 *    EEC_SRFMATTY_PLASTER
 *    EEC_SRFMATTY_PLASTIC
 *    EEC_SRFMATTY_POLYZOA
 *    EEC_SRFMATTY_PORPHYRY
 *    EEC_SRFMATTY_PRESTRESSED_CONCRETE
 *    EEC_SRFMATTY_PTEROPOD
 *    EEC_SRFMATTY_PUMICE
 *    EEC_SRFMATTY_QUARTZ
 *    EEC_SRFMATTY_RADIOACTIVE_MATERIAL
 *    EEC_SRFMATTY_RADIOLARIAN
 *    EEC_SRFMATTY_REINFORCED_CONCRETE
 *    EEC_SRFMATTY_RIPRAP
 *    EEC_SRFMATTY_ROCK
 *    EEC_SRFMATTY_RUBBER
 *    EEC_SRFMATTY_RUBBLE
 *    EEC_SRFMATTY_SALT
 *    EEC_SRFMATTY_SAND
 *    EEC_SRFMATTY_SAND_AND_BOULDERS
 *    EEC_SRFMATTY_SAND_AND_GRAVEL
 *    EEC_SRFMATTY_SAND_AND_MUD
 *    EEC_SRFMATTY_SAND_GRADED_ROLLED_OILED
 *    EEC_SRFMATTY_SAND_WAVE
 *    EEC_SRFMATTY_SANDSTONE
 *    EEC_SRFMATTY_SCHIST
 *    EEC_SRFMATTY_SCORIA
 *    EEC_SRFMATTY_SEA_TANGLE
 *    EEC_SRFMATTY_SEAWEED
 *    EEC_SRFMATTY_SEWAGE
 *    EEC_SRFMATTY_SHELL
 *    EEC_SRFMATTY_SHINGLE
 *    EEC_SRFMATTY_SILT
 *    EEC_SRFMATTY_SILVER
 *    EEC_SRFMATTY_SLAG
 *    EEC_SRFMATTY_SLUDGE
 *    EEC_SRFMATTY_SNOW
 *    EEC_SRFMATTY_SOIL
 *    EEC_SRFMATTY_SPICULE
 *    EEC_SRFMATTY_SPOIL
 *    EEC_SRFMATTY_SPOIL_OR_TAILINGS
 *    EEC_SRFMATTY_SPONGE
 *    EEC_SRFMATTY_STEEL
 *    EEC_SRFMATTY_STONE
 *    EEC_SRFMATTY_SUGAR
 *    EEC_SRFMATTY_TAILINGS
 *    EEC_SRFMATTY_TEXTILE
 *    EEC_SRFMATTY_THATCH
 *    EEC_SRFMATTY_TRAVERTINE
 *    EEC_SRFMATTY_TREED_VEGETATION
 *    EEC_SRFMATTY_TREES
 *    EEC_SRFMATTY_TUFA
 *    EEC_SRFMATTY_URANIUM
 *    EEC_SRFMATTY_VEGETATED_WETLAND
 *    EEC_SRFMATTY_VEGETATION_PRODUCT
 *    EEC_SRFMATTY_VINYL
 *    EEC_SRFMATTY_VOLCANIC
 *    EEC_SRFMATTY_VOLCANIC_ASH
 *    EEC_SRFMATTY_WATER
 *    EEC_SRFMATTY_WOOD
 *    EEC_SRFMATTY_ZINC
 *
 * Group Membership: MATERIAL, SURFACE, SURFACE_MATERIAL
 */
#define EAC_SURFACE_MATERIAL_TYPE ((EDCS_Attribute_Code)1381)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the ratio of the
 *     reflected flux to the incident flux at a <SURFACE>; the surface
 *     reflectivity. Zero means no reflection and one means total reflection.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, SURFACE
 */
#define EAC_SURFACE_REFLECTIVITY ((EDCS_Attribute_Code)1382)

/*
 * Definition:
 *     An indication that a <SURFACE> (for example: wet grass and/or wet clay
 *     <SOIL>) is slippery.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: SURFACE
 */
#define EAC_SURFACE_SLIPPERY ((EDCS_Attribute_Code)1383)

/*
 * Definition:
 *     The maximum slope (rise/run) of the <SURFACE> of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, SURFACE
 */
#define EAC_SURFACE_SLOPE ((EDCS_Attribute_Code)1384)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> of maximum
 *     <<SURFACE_SLOPE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, SURFACE
 */
#define EAC_SURFACE_SLOPE_ORIENTATION ((EDCS_Attribute_Code)1385)

/*
 * Definition:
 *     The <<TEMPERATURE>> of a <SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: SURFACE, TEMPERATURE
 */
#define EAC_SURFACE_TEMPERATURE ((EDCS_Attribute_Code)1386)

/*
 * Definition:
 *     The index used to describe the thermal (radiance) characteristic of a
 *     <SURFACE>.
 *
 * Value Type: INDEX
 *
 * Group Membership: ALGORITHM_RELATED, SURFACE, TEMPERATURE
 */
#define EAC_SURFACE_THERMAL_INDEX ((EDCS_Attribute_Code)1387)

/*
 * Definition:
 *     The type of thermal (radiance) model being used to determine the
 *     interpretation of the thermal index describing the thermal (radiance)
 *     characteristic of a <SURFACE>. That value is used to index one or
 *     more thermal model-specific lookup tables in order to predict,
 *     display, or analyze thermal signatures.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRFTHERMMDL_E_S_CCTT
 *    EEC_SRFTHERMMDL_LMIS_A2ATD
 *    EEC_SRFTHERMMDL_LMIS_AGPT
 *    EEC_SRFTHERMMDL_LMIS_KAM20
 *
 * Group Membership: ALGORITHM_RELATED, SURFACE, TEMPERATURE
 */
#define EAC_SURFACE_THERMAL_MODEL ((EDCS_Attribute_Code)1388)

/*
 * Definition:
 *     The degree of dominance of the effect of shading from the <SUN> (in
 *     the respective sensor domain) over the thermally derived values. The
 *     values are between 0 and 1 inclusive with zero being minimally and
 *     one being maximally (but not necessarily completely) dominant. The
 *     exact interpretation of this value is determined by the thermal model
 *     being used.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, SURFACE
 */
#define EAC_SURFACE_THERMAL_SUNSHADING_DOMINANCE ((EDCS_Attribute_Code)1389)

/*
 * Definition:
 *     The degree of dominance of the visual texture of an image (in the
 *     respective sensor domain) over the thermally derived values. The
 *     values are between 0 and 1 inclusive with zero being minimally and
 *     one being maximally (but not necessarily completely) dominant. The
 *     exact interpretation of this value is determined by the thermal model
 *     being used.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, SURFACE
 */
#define EAC_SURFACE_THERMAL_VISUAL_DOMINANCE ((EDCS_Attribute_Code)1390)

/*
 * Definition:
 *     The <<WIND_SPEED>> 10 metres above a <PLANETARY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_SURFACE_WIND_SPEED ((EDCS_Attribute_Code)1391)

/*
 * Definition:
 *     The estimated general depth of <SOIL> or unconsolidated surficial
 *     <MATERIAL>s on the <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, MATERIAL, PHYSIOGRAPHY
 */
#define EAC_SURFICIAL_DEPTH ((EDCS_Attribute_Code)1392)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of breaking <WATER_WAVE>s that are surging. Surging means
 *     that the <WATER_WAVE> crest tends to advance faster than the base of
 *     the <WATER_WAVE> to suggest the formation of a plunging breaker,
 *     however, the <WATER_WAVE> base then advances faster than the crest,
 *     the plunging is arrested, and the breaker surges up the <BEACH> as a
 *     wall of <WATER> which may, or may not, be white water. Zero means no
 *     breaking <WATER_WAVE>s are surging and one means all are surging.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_SURGING_BREAKER_FRACTION ((EDCS_Attribute_Code)1393)

/*
 * Definition:
 *     The type of a winged surveillance <AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SRVLWNGARCRFTY_AN74_MADCAP_SERIES
 *    EEC_SRVLWNGARCRFTY_E2C_MODEL_HAWKEYE_SERIES
 *    EEC_SRVLWNGARCRFTY_E3A_AWACS_SENTRY_SERIES
 *    EEC_SRVLWNGARCRFTY_TU126_MOSS_SERIES
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define EAC_SURVEILLANCE_WINGED_AIRCRAFT_TYPE ((EDCS_Attribute_Code)1394)

/*
 * Definition:
 *     The type of a control point established by surveying methods.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SURVCTRLPTTY_ASTRONOMIC_OBS_STATION
 *    EEC_SURVCTRLPTTY_ASTRONOMIC_POS
 *    EEC_SURVCTRLPTTY_BENCHMARK
 *    EEC_SURVCTRLPTTY_BOUNDARY_MARKER
 *    EEC_SURVCTRLPTTY_FIXED_POS
 *    EEC_SURVCTRLPTTY_GEODETIC_POS
 *    EEC_SURVCTRLPTTY_HORIZ_MAIN_STATION
 *    EEC_SURVCTRLPTTY_HORIZ_POS
 *    EEC_SURVCTRLPTTY_HORIZ_POS_AND_BENCHMARK
 *    EEC_SURVCTRLPTTY_HORIZ_SECONDARY_STATION
 *    EEC_SURVCTRLPTTY_TRIANGULATION_POINT
 *    EEC_SURVCTRLPTTY_VERT_MAIN_STATION
 *    EEC_SURVCTRLPTTY_VERT_POS
 *    EEC_SURVCTRLPTTY_VERT_SECONDARY_STATION
 *
 * Group Membership: SURVEY
 */
#define EAC_SURVEY_CONTROL_POINT_TYPE ((EDCS_Attribute_Code)1395)

/*
 * Definition:
 *     The end date of a survey. The value is formatted as specified by
 *     <<DATE_FORMAT>> or by <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: SURVEY, TIME
 */
#define EAC_SURVEY_END_DATE ((EDCS_Attribute_Code)1396)

/*
 * Definition:
 *     The qualifier of a survey for an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SURVQUAL_INADEQUATE
 *    EEC_SURVQUAL_NOT_SURVEYED
 *    EEC_SURVQUAL_SURVEYED
 *
 * Group Membership: ABSTRACT_OBJECT, SURVEY
 */
#define EAC_SURVEY_QUALIFIER ((EDCS_Attribute_Code)1397)

/*
 * Definition:
 *     The start date of a survey. The value is formatted as specified by
 *     <<DATE_FORMAT>> or by <<DATE_TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: SURVEY, TIME
 */
#define EAC_SURVEY_START_DATE ((EDCS_Attribute_Code)1398)

/*
 * Definition:
 *     The <<DEPTH>> of a <ROOM_CEILING> suspended from the <SURFACE> above;
 *     the suspended ceiling depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: BUILDING_COMPONENT, LOCATION
 */
#define EAC_SUSPENDED_CEILING_DEPTH ((EDCS_Attribute_Code)1399)

/*
 * Definition:
 *     An indication that an <OBJECT> is synchronized.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_SYNCHRONIZED ((EDCS_Attribute_Code)1400)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> required for a <SYSTEM> exposed to some
 *     discontinuous change in environment to return to the state it would
 *     exhibit after an indefinitely long time; the system relaxation time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME
 */
#define EAC_SYSTEM_RELAXATION_TIME ((EDCS_Attribute_Code)1401)

/*
 * Definition:
 *     The areal density of tanker <WATER_SURFACE_VESSEL>s. A tanker
 *     <WATER_SURFACE_VESSEL> is characterized by a gross weight greater
 *     than 907 000 kilograms (approximately 1 000 tons), a dead weight less
 *     than or equal to 159 000 kilograms (approximately 175 000 tons), and
 *     a <<LENGTH>> of approximately 18 to 300 metres).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_TANKER_DENSITY ((EDCS_Attribute_Code)1402)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the <LIGHTING> on a <TAXIWAY>. Zero means
 *     unlit and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP
 */
#define EAC_TAXIWAY_LIGHTING_INTENSITY ((EDCS_Attribute_Code)1403)

/*
 * Definition:
 *     The type of a <TELESCOPE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TELESCOPETY_OPTICAL
 *    EEC_TELESCOPETY_PARABOLIC_RADIO_AERIAL
 *    EEC_TELESCOPETY_RADIO_AERIAL_ARRAY
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define EAC_TELESCOPE_TYPE ((EDCS_Attribute_Code)1404)

/*
 * Definition:
 *     The state of a <MATERIAL> or <OBJECT> with regard to objective warmth
 *     or coldness, referred to a standard of comparison; temperature [SOED,
 *     "temperature", 7.a].
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE
 */
#define EAC_TEMPERATURE ((EDCS_Attribute_Code)1405)

/*
 * Definition:
 *     The thermal contrast of an <OBJECT> expressed as the difference
 *     between the <<TEMPERATURE>> of the <OBJECT> and the <<TEMPERATURE>>
 *     of the apparent background.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ABSTRACT_OBJECT, TEMPERATURE
 */
#define EAC_TEMPERATURE_CONTRAST ((EDCS_Attribute_Code)1406)

/*
 * Definition:
 *     The vertical distance to the base of a <TEMPERATURE_INVERSION_LAYER>
 *     from a reference <SURFACE> identified by an
 *     <<ATM_VERTICAL_REFERENCE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION, TEMPERATURE
 */
#define EAC_TEMPERATURE_INVRSN_LAYER_BASE ((EDCS_Attribute_Code)1407)

/*
 * Definition:
 *     The <<TEMPERATURE_LAPSE_RATE>> in a <TEMPERATURE_INVERSION_LAYER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_TEMPERATURE_INVRSN_LAYER_LAPSE_RATE ((EDCS_Attribute_Code)1408)

/*
 * Definition:
 *     The vertical distance to the top of a <TEMPERATURE_INVERSION_LAYER>
 *     from a reference <SURFACE> identified by an
 *     <<ATM_VERTICAL_REFERENCE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION, TEMPERATURE
 */
#define EAC_TEMPERATURE_INVRSN_LAYER_TOP ((EDCS_Attribute_Code)1409)

/*
 * Definition:
 *     The rate of decrease of the <<AIR_TEMPERATURE>> as a function of
 *     <<HEIGHT_AGL>>. A decrease in <<AIR_TEMPERATURE>> with <<HEIGHT_AGL>>
 *     is reported as a positive number.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO, TEMPERATURE
 */
#define EAC_TEMPERATURE_LAPSE_RATE ((EDCS_Attribute_Code)1410)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional opening of the deployable or extension <TENT> of an
 *     <OBJECT>. Zero means fully stowed/retracted/closed and one means
 *     fully deployed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_TENT_DEPLOYMENT_FRACTION ((EDCS_Attribute_Code)1411)

/*
 * Definition:
 *     The <<ALBEDO>> of <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: EM_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_TERRAIN_ALBEDO ((EDCS_Attribute_Code)1412)

/*
 * Definition:
 *     The predominant distance across the bottom of a localized
 *     <TERRAIN_CHANNEL> measured perpendicular to its <CENTRE_LINE>; the
 *     terrain channel width.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, PHYSIOGRAPHY
 */
#define EAC_TERRAIN_CHANNEL_WIDTH ((EDCS_Attribute_Code)1413)

/*
 * Definition:
 *     The predominant distance across the crest of a localized <RIDGE> (for
 *     example: a <DAM> and/or a <PARAPET>) on the <TERRAIN>, as measured
 *     perpendicular to its <CENTRE_LINE>; terrain crest width.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, PHYSIOGRAPHY
 */
#define EAC_TERRAIN_CREST_WIDTH ((EDCS_Attribute_Code)1414)

/*
 * Definition:
 *     The <<ELEVATION>> of the <TERRAIN> at a <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY
 */
#define EAC_TERRAIN_ELEVATION ((EDCS_Attribute_Code)1415)

/*
 * Definition:
 *     The minimum horizontal bridging distance between the banks of a
 *     localized <TERRAIN_CHANNEL> measured perpendicular to its
 *     <CENTRE_LINE>; the terrain gap width.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, PHYSIOGRAPHY
 */
#define EAC_TERRAIN_GAP_WIDTH ((EDCS_Attribute_Code)1416)

/*
 * Definition:
 *     A description of the morphology of the <TERRAIN>.
 *
 * Value Type: STRING
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_TERRAIN_MORPHOLOGY_DESCRIPTION ((EDCS_Attribute_Code)1417)

/*
 * Definition:
 *     The type of the morphology of the <TERRAIN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TERMRPHTY_ACTIVE_SAND_DUNES
 *    EEC_TERMRPHTY_ANGULAR
 *    EEC_TERMRPHTY_BOULDER_FIELD
 *    EEC_TERMRPHTY_CONTAINING_SABKHAS
 *    EEC_TERMRPHTY_DEEP_EROSIONAL_GULLIES
 *    EEC_TERMRPHTY_DISSECTED_FLOODPLAIN
 *    EEC_TERMRPHTY_FROST_POLYGONS
 *    EEC_TERMRPHTY_GRAVEL_PIT
 *    EEC_TERMRPHTY_HIGH_LANDSLIDE_POTENTIAL
 *    EEC_TERMRPHTY_HIGHLY_DISSECTED
 *    EEC_TERMRPHTY_HIGHLY_DISTORTED
 *    EEC_TERMRPHTY_HIGHLY_FRACTURED_ROCK
 *    EEC_TERMRPHTY_HUMMOCKY
 *    EEC_TERMRPHTY_IRREGULAR_SURFACE_DEEP_FRACTURES
 *    EEC_TERMRPHTY_KARST_LARGE_HILLS
 *    EEC_TERMRPHTY_KARST_LOW_MOUNDS
 *    EEC_TERMRPHTY_KARST_NUMEROUS_SINKHOLES
 *    EEC_TERMRPHTY_KARST_SINKHOLES_SOLUTION_VALLEYS
 *    EEC_TERMRPHTY_MANY_BOULDERS
 *    EEC_TERMRPHTY_MANY_CANALS
 *    EEC_TERMRPHTY_MANY_COBBLES
 *    EEC_TERMRPHTY_MANY_CREVASSES
 *    EEC_TERMRPHTY_MANY_DYKED_FIELDS
 *    EEC_TERMRPHTY_MANY_DYKES
 *    EEC_TERMRPHTY_MANY_FENCES
 *    EEC_TERMRPHTY_MANY_HEDGEROWS
 *    EEC_TERMRPHTY_MANY_MEANDER_SCARS
 *    EEC_TERMRPHTY_MANY_ROCK_OUTCROPS
 *    EEC_TERMRPHTY_MANY_SMALL_LAKES
 *    EEC_TERMRPHTY_MANY_STONE_WALLS
 *    EEC_TERMRPHTY_MANY_TERRACED_FIELDS
 *    EEC_TERMRPHTY_MANY_TERRACES
 *    EEC_TERMRPHTY_MOD_DISSECTED
 *    EEC_TERMRPHTY_MOD_DISSECTED_ROCK_OUTCROPS
 *    EEC_TERMRPHTY_NO_SURFACE_ROUGHNESS
 *    EEC_TERMRPHTY_PARALLEL_SOIL_MOUNDS
 *    EEC_TERMRPHTY_PLAYA
 *    EEC_TERMRPHTY_QUARRY
 *    EEC_TERMRPHTY_QUARRY_OR_GRAVEL_PIT
 *    EEC_TERMRPHTY_QUARRY_OR_SAND_PIT
 *    EEC_TERMRPHTY_ROUGH
 *    EEC_TERMRPHTY_ROUNDED
 *    EEC_TERMRPHTY_RUGGED_BEDROCK_SURFACE
 *    EEC_TERMRPHTY_RUGGED_ROCKY_OUTCROPS
 *    EEC_TERMRPHTY_SALT_EVAPORATORS
 *    EEC_TERMRPHTY_SAND_DUNES
 *    EEC_TERMRPHTY_SAND_DUNES_HIGH
 *    EEC_TERMRPHTY_SAND_DUNES_LOW
 *    EEC_TERMRPHTY_SAND_PIT
 *    EEC_TERMRPHTY_SCATTERED_BOULDERS
 *    EEC_TERMRPHTY_SOLIFLUCTION_LOBES
 *    EEC_TERMRPHTY_STABILIZED_SAND_DUNES
 *    EEC_TERMRPHTY_STEEP_RUGGED_DISSECTED
 *    EEC_TERMRPHTY_STONY_BOULDERS
 *    EEC_TERMRPHTY_STONY_GULLIES
 *    EEC_TERMRPHTY_STONY_ROCKCROPS
 *    EEC_TERMRPHTY_STONY_ROCKS
 *    EEC_TERMRPHTY_STONY_SCATTERED_BOULDERS
 *    EEC_TERMRPHTY_STONY_TRACTS
 *    EEC_TERMRPHTY_STRIP_MINES
 *    EEC_TERMRPHTY_TALUS_SLOPE
 *    EEC_TERMRPHTY_UNCOHESIVE_SURFACE_FLAT
 *    EEC_TERMRPHTY_UNWEATHERED_LAVA
 *    EEC_TERMRPHTY_WADI
 *    EEC_TERMRPHTY_WASTE_PILES
 *    EEC_TERMRPHTY_WEATHERED_LAVA
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_TERRAIN_MORPHOLOGY_TYPE ((EDCS_Attribute_Code)1418)

/*
 * Definition:
 *     The type of a <TERRAIN_OBSTACLE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TEROBSTTY_ABATIS
 *    EEC_TEROBSTTY_ANTI_TANK_DITCH
 *    EEC_TEROBSTTY_ANTIPERSONNEL_WIRE
 *    EEC_TEROBSTTY_ANTIVEHICLE_WIRE
 *    EEC_TEROBSTTY_CRATERS
 *    EEC_TEROBSTTY_CRIB_BLOCK
 *    EEC_TEROBSTTY_DELIBERATE_CRATER
 *    EEC_TEROBSTTY_DOUBLE_STRAND_CONCERTINA
 *    EEC_TEROBSTTY_DRAGON_TEETH
 *    EEC_TEROBSTTY_EARTHEN_WALL
 *    EEC_TEROBSTTY_EMBANKMENT
 *    EEC_TEROBSTTY_EMPLACED_BOULDER
 *    EEC_TEROBSTTY_HASTY_CRATER
 *    EEC_TEROBSTTY_HEDGE_HOGS
 *    EEC_TEROBSTTY_LINEAR_CONCRETE_BARRIER
 *    EEC_TEROBSTTY_LOG_CRIB
 *    EEC_TEROBSTTY_LOG_HURDLE
 *    EEC_TEROBSTTY_LOG_POSTS
 *    EEC_TEROBSTTY_PARAPET
 *    EEC_TEROBSTTY_ROADBLOCK
 *    EEC_TEROBSTTY_ROADBLOCK_OR_CRIB_BLOCK
 *    EEC_TEROBSTTY_RUBBLE
 *    EEC_TEROBSTTY_SINGLE_STRAND_CONCERTINA
 *    EEC_TEROBSTTY_TERRAIN_TRANSPORTATION_ABATIS
 *    EEC_TEROBSTTY_TETRAHEDRONS
 *    EEC_TEROBSTTY_TRENCH
 *    EEC_TEROBSTTY_TRENCH_WITH_PARAPET
 *    EEC_TEROBSTTY_TRIPLE_STRAND_CONCERTINA
 *    EEC_TEROBSTTY_WIRE_ROAD_BLOCK
 *    EEC_TEROBSTTY_FORTIFICATION_WALL
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_TERRAIN_OBSTACLE_TYPE ((EDCS_Attribute_Code)1419)

/*
 * Definition:
 *     The roughness of the <TERRAIN> calculated using the RMS value of
 *     <<TERRAIN_ELEVATION>>s measured at a spatial frequency of
 *     approximately 0,3 metres after removing the trend surface.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, PHYSIOGRAPHY
 */
#define EAC_TERRAIN_ROUGHNESS_ROOT_MEAN_SQUARE ((EDCS_Attribute_Code)1420)

/*
 * Definition:
 *     The slope (rise/run) of the <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: PHYSIOGRAPHY, RATE_OR_RATIO
 */
#define EAC_TERRAIN_SLOPE ((EDCS_Attribute_Code)1421)

/*
 * Definition:
 *     The type of marking (for example: a rut, charring by fire, and/or
 *     ploughing) that indicates disturbance to the naturally occurring
 *     <SURFACE> of the <LAND>; the terrain surface marking type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TERSRFMKTY_BURNT
 *    EEC_TERSRFMKTY_CHURNED
 *    EEC_TERSRFMKTY_GENERALLY_DISTURBED
 *    EEC_TERSRFMKTY_NO_MARKS_PRESENT
 *    EEC_TERSRFMKTY_PLOUGHED
 *    EEC_TERSRFMKTY_RAKED
 *    EEC_TERSRFMKTY_RUTTED
 *    EEC_TERSRFMKTY_TRACKED_VEHICLE
 *    EEC_TERSRFMKTY_WHEELED_VEHICLE
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_TERRAIN_SURFACE_MARKING_TYPE ((EDCS_Attribute_Code)1422)

/*
 * Definition:
 *     A coarse measure of the trafficability of the <TERRAIN> as it affects
 *     the movement of ground forces (for example: a military unit, a
 *     military <GROUND_VEHICLE>, and/or infantry).
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TERTRAFCORS_BOULDER_COVERED
 *    EEC_TERTRAFCORS_DEEP_WATER
 *    EEC_TERTRAFCORS_NOT_TRAVERSABLE
 *    EEC_TERTRAFCORS_PACKED_SOIL
 *    EEC_TERTRAFCORS_RAILWAY
 *    EEC_TERTRAFCORS_ROAD
 *    EEC_TERTRAFCORS_STONY
 *    EEC_TERTRAFCORS_SHALLOW_WATER
 *    EEC_TERTRAFCORS_SOFT_SOIL
 *    EEC_TERTRAFCORS_UNKNOWN_SOIL
 *    EEC_TERTRAFCORS_WATER_BODY_FLOOR
 *    EEC_TERTRAFCORS_WATER_BODY_SURFACE
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_TERRAIN_TRAFFICABILITY_COARSE ((EDCS_Attribute_Code)1423)

/*
 * Definition:
 *     A fine measure of the trafficability of the <TERRAIN> as it affects
 *     the movement of ground forces (for example: a military unit, a
 *     military <GROUND_VEHICLE>, and/or infantry).
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TERTRAFFINE_TYPE_0
 *    EEC_TERTRAFFINE_TYPE_1
 *    EEC_TERTRAFFINE_TYPE_2
 *    EEC_TERTRAFFINE_TYPE_3
 *    EEC_TERTRAFFINE_TYPE_4
 *    EEC_TERTRAFFINE_TYPE_5
 *    EEC_TERTRAFFINE_TYPE_6
 *    EEC_TERTRAFFINE_TYPE_7
 *    EEC_TERTRAFFINE_TYPE_8
 *    EEC_TERTRAFFINE_TYPE_9
 *    EEC_TERTRAFFINE_TYPE_10
 *    EEC_TERTRAFFINE_TYPE_11
 *    EEC_TERTRAFFINE_TYPE_12
 *    EEC_TERTRAFFINE_TYPE_13
 *    EEC_TERTRAFFINE_TYPE_14
 *    EEC_TERTRAFFINE_TYPE_15
 *    EEC_TERTRAFFINE_TYPE_16
 *    EEC_TERTRAFFINE_TYPE_17
 *    EEC_TERTRAFFINE_TYPE_18
 *    EEC_TERTRAFFINE_TYPE_19
 *    EEC_TERTRAFFINE_TYPE_20
 *    EEC_TERTRAFFINE_TYPE_21
 *    EEC_TERTRAFFINE_TYPE_22
 *    EEC_TERTRAFFINE_TYPE_23
 *    EEC_TERTRAFFINE_TYPE_24
 *    EEC_TERTRAFFINE_TYPE_25
 *    EEC_TERTRAFFINE_TYPE_26
 *    EEC_TERTRAFFINE_TYPE_27
 *    EEC_TERTRAFFINE_TYPE_28
 *    EEC_TERTRAFFINE_TYPE_29
 *    EEC_TERTRAFFINE_TYPE_30
 *    EEC_TERTRAFFINE_TYPE_31
 *    EEC_TERTRAFFINE_TYPE_32
 *    EEC_TERTRAFFINE_TYPE_33
 *    EEC_TERTRAFFINE_TYPE_34
 *    EEC_TERTRAFFINE_TYPE_35
 *    EEC_TERTRAFFINE_TYPE_36
 *    EEC_TERTRAFFINE_TYPE_37
 *    EEC_TERTRAFFINE_TYPE_38
 *    EEC_TERTRAFFINE_TYPE_39
 *    EEC_TERTRAFFINE_TYPE_40
 *    EEC_TERTRAFFINE_TYPE_41
 *    EEC_TERTRAFFINE_TYPE_42
 *    EEC_TERTRAFFINE_TYPE_43
 *    EEC_TERTRAFFINE_TYPE_44
 *    EEC_TERTRAFFINE_TYPE_45
 *    EEC_TERTRAFFINE_TYPE_46
 *    EEC_TERTRAFFINE_TYPE_47
 *    EEC_TERTRAFFINE_TYPE_48
 *    EEC_TERTRAFFINE_TYPE_49
 *    EEC_TERTRAFFINE_TYPE_50
 *    EEC_TERTRAFFINE_TYPE_51
 *    EEC_TERTRAFFINE_TYPE_52
 *    EEC_TERTRAFFINE_TYPE_53
 *    EEC_TERTRAFFINE_TYPE_54
 *    EEC_TERTRAFFINE_TYPE_55
 *    EEC_TERTRAFFINE_TYPE_56
 *    EEC_TERTRAFFINE_TYPE_57
 *    EEC_TERTRAFFINE_TYPE_58
 *    EEC_TERTRAFFINE_TYPE_59
 *    EEC_TERTRAFFINE_TYPE_60
 *    EEC_TERTRAFFINE_TYPE_61
 *    EEC_TERTRAFFINE_TYPE_62
 *    EEC_TERTRAFFINE_TYPE_63
 *    EEC_TERTRAFFINE_TYPE_64
 *    EEC_TERTRAFFINE_TYPE_65
 *    EEC_TERTRAFFINE_TYPE_66
 *    EEC_TERTRAFFINE_TYPE_67
 *    EEC_TERTRAFFINE_TYPE_68
 *    EEC_TERTRAFFINE_TYPE_69
 *    EEC_TERTRAFFINE_TYPE_70
 *    EEC_TERTRAFFINE_TYPE_71
 *    EEC_TERTRAFFINE_TYPE_72
 *    EEC_TERTRAFFINE_TYPE_73
 *    EEC_TERTRAFFINE_TYPE_74
 *    EEC_TERTRAFFINE_TYPE_75
 *    EEC_TERTRAFFINE_TYPE_76
 *    EEC_TERTRAFFINE_TYPE_77
 *    EEC_TERTRAFFINE_TYPE_78
 *    EEC_TERTRAFFINE_TYPE_79
 *    EEC_TERTRAFFINE_TYPE_80
 *    EEC_TERTRAFFINE_TYPE_81
 *    EEC_TERTRAFFINE_TYPE_82
 *    EEC_TERTRAFFINE_TYPE_83
 *    EEC_TERTRAFFINE_TYPE_84
 *    EEC_TERTRAFFINE_TYPE_85
 *    EEC_TERTRAFFINE_TYPE_86
 *    EEC_TERTRAFFINE_TYPE_87
 *    EEC_TERTRAFFINE_TYPE_88
 *    EEC_TERTRAFFINE_TYPE_89
 *    EEC_TERTRAFFINE_TYPE_90
 *    EEC_TERTRAFFINE_TYPE_91
 *    EEC_TERTRAFFINE_TYPE_92
 *    EEC_TERTRAFFINE_TYPE_93
 *    EEC_TERTRAFFINE_TYPE_94
 *    EEC_TERTRAFFINE_TYPE_95
 *    EEC_TERTRAFFINE_TYPE_96
 *    EEC_TERTRAFFINE_TYPE_97
 *    EEC_TERTRAFFINE_TYPE_98
 *    EEC_TERTRAFFINE_TYPE_99
 *    EEC_TERTRAFFINE_TYPE_100
 *    EEC_TERTRAFFINE_TYPE_101
 *    EEC_TERTRAFFINE_TYPE_102
 *    EEC_TERTRAFFINE_TYPE_103
 *    EEC_TERTRAFFINE_TYPE_104
 *    EEC_TERTRAFFINE_TYPE_105
 *    EEC_TERTRAFFINE_TYPE_106
 *    EEC_TERTRAFFINE_TYPE_107
 *    EEC_TERTRAFFINE_TYPE_108
 *    EEC_TERTRAFFINE_TYPE_109
 *    EEC_TERTRAFFINE_TYPE_110
 *    EEC_TERTRAFFINE_TYPE_111
 *    EEC_TERTRAFFINE_TYPE_112
 *    EEC_TERTRAFFINE_TYPE_113
 *    EEC_TERTRAFFINE_TYPE_114
 *    EEC_TERTRAFFINE_TYPE_115
 *    EEC_TERTRAFFINE_TYPE_116
 *    EEC_TERTRAFFINE_TYPE_117
 *    EEC_TERTRAFFINE_TYPE_118
 *    EEC_TERTRAFFINE_TYPE_119
 *    EEC_TERTRAFFINE_TYPE_120
 *    EEC_TERTRAFFINE_TYPE_121
 *    EEC_TERTRAFFINE_TYPE_122
 *    EEC_TERTRAFFINE_TYPE_123
 *    EEC_TERTRAFFINE_TYPE_124
 *    EEC_TERTRAFFINE_TYPE_125
 *    EEC_TERTRAFFINE_TYPE_126
 *    EEC_TERTRAFFINE_TYPE_127
 *    EEC_TERTRAFFINE_TYPE_128
 *    EEC_TERTRAFFINE_TYPE_129
 *    EEC_TERTRAFFINE_TYPE_130
 *    EEC_TERTRAFFINE_TYPE_131
 *    EEC_TERTRAFFINE_TYPE_132
 *    EEC_TERTRAFFINE_TYPE_133
 *    EEC_TERTRAFFINE_TYPE_134
 *    EEC_TERTRAFFINE_TYPE_135
 *    EEC_TERTRAFFINE_TYPE_136
 *    EEC_TERTRAFFINE_TYPE_137
 *    EEC_TERTRAFFINE_TYPE_138
 *    EEC_TERTRAFFINE_TYPE_139
 *    EEC_TERTRAFFINE_TYPE_140
 *    EEC_TERTRAFFINE_TYPE_141
 *    EEC_TERTRAFFINE_TYPE_142
 *    EEC_TERTRAFFINE_TYPE_143
 *    EEC_TERTRAFFINE_TYPE_144
 *    EEC_TERTRAFFINE_TYPE_145
 *    EEC_TERTRAFFINE_TYPE_146
 *    EEC_TERTRAFFINE_TYPE_147
 *    EEC_TERTRAFFINE_TYPE_148
 *    EEC_TERTRAFFINE_TYPE_149
 *    EEC_TERTRAFFINE_TYPE_150
 *    EEC_TERTRAFFINE_TYPE_151
 *    EEC_TERTRAFFINE_TYPE_152
 *    EEC_TERTRAFFINE_TYPE_153
 *    EEC_TERTRAFFINE_TYPE_154
 *    EEC_TERTRAFFINE_TYPE_155
 *    EEC_TERTRAFFINE_TYPE_156
 *    EEC_TERTRAFFINE_TYPE_157
 *    EEC_TERTRAFFINE_TYPE_158
 *    EEC_TERTRAFFINE_TYPE_159
 *    EEC_TERTRAFFINE_TYPE_160
 *    EEC_TERTRAFFINE_TYPE_161
 *    EEC_TERTRAFFINE_TYPE_162
 *    EEC_TERTRAFFINE_TYPE_163
 *    EEC_TERTRAFFINE_TYPE_164
 *    EEC_TERTRAFFINE_TYPE_165
 *    EEC_TERTRAFFINE_TYPE_166
 *    EEC_TERTRAFFINE_TYPE_167
 *    EEC_TERTRAFFINE_TYPE_168
 *    EEC_TERTRAFFINE_TYPE_169
 *    EEC_TERTRAFFINE_TYPE_170
 *    EEC_TERTRAFFINE_TYPE_171
 *    EEC_TERTRAFFINE_TYPE_172
 *    EEC_TERTRAFFINE_TYPE_173
 *    EEC_TERTRAFFINE_TYPE_174
 *    EEC_TERTRAFFINE_TYPE_175
 *    EEC_TERTRAFFINE_TYPE_176
 *    EEC_TERTRAFFINE_TYPE_177
 *    EEC_TERTRAFFINE_TYPE_178
 *    EEC_TERTRAFFINE_TYPE_179
 *    EEC_TERTRAFFINE_TYPE_180
 *    EEC_TERTRAFFINE_TYPE_181
 *    EEC_TERTRAFFINE_TYPE_182
 *    EEC_TERTRAFFINE_TYPE_183
 *    EEC_TERTRAFFINE_TYPE_184
 *    EEC_TERTRAFFINE_TYPE_185
 *    EEC_TERTRAFFINE_TYPE_186
 *    EEC_TERTRAFFINE_TYPE_187
 *    EEC_TERTRAFFINE_TYPE_188
 *    EEC_TERTRAFFINE_TYPE_189
 *    EEC_TERTRAFFINE_TYPE_190
 *    EEC_TERTRAFFINE_TYPE_191
 *    EEC_TERTRAFFINE_TYPE_192
 *    EEC_TERTRAFFINE_TYPE_193
 *    EEC_TERTRAFFINE_TYPE_194
 *    EEC_TERTRAFFINE_TYPE_195
 *    EEC_TERTRAFFINE_TYPE_196
 *    EEC_TERTRAFFINE_TYPE_197
 *    EEC_TERTRAFFINE_TYPE_198
 *    EEC_TERTRAFFINE_TYPE_199
 *    EEC_TERTRAFFINE_TYPE_200
 *    EEC_TERTRAFFINE_TYPE_201
 *    EEC_TERTRAFFINE_TYPE_202
 *    EEC_TERTRAFFINE_TYPE_203
 *    EEC_TERTRAFFINE_TYPE_204
 *    EEC_TERTRAFFINE_TYPE_205
 *    EEC_TERTRAFFINE_TYPE_206
 *    EEC_TERTRAFFINE_TYPE_207
 *    EEC_TERTRAFFINE_TYPE_208
 *    EEC_TERTRAFFINE_TYPE_209
 *    EEC_TERTRAFFINE_TYPE_210
 *    EEC_TERTRAFFINE_TYPE_211
 *    EEC_TERTRAFFINE_TYPE_212
 *    EEC_TERTRAFFINE_TYPE_213
 *    EEC_TERTRAFFINE_TYPE_214
 *    EEC_TERTRAFFINE_TYPE_215
 *    EEC_TERTRAFFINE_TYPE_216
 *    EEC_TERTRAFFINE_TYPE_217
 *    EEC_TERTRAFFINE_TYPE_218
 *    EEC_TERTRAFFINE_TYPE_219
 *    EEC_TERTRAFFINE_TYPE_220
 *    EEC_TERTRAFFINE_TYPE_221
 *    EEC_TERTRAFFINE_TYPE_222
 *    EEC_TERTRAFFINE_TYPE_223
 *    EEC_TERTRAFFINE_TYPE_224
 *    EEC_TERTRAFFINE_TYPE_225
 *    EEC_TERTRAFFINE_TYPE_226
 *    EEC_TERTRAFFINE_TYPE_227
 *    EEC_TERTRAFFINE_TYPE_228
 *    EEC_TERTRAFFINE_TYPE_229
 *    EEC_TERTRAFFINE_TYPE_230
 *    EEC_TERTRAFFINE_TYPE_231
 *    EEC_TERTRAFFINE_TYPE_232
 *    EEC_TERTRAFFINE_TYPE_233
 *    EEC_TERTRAFFINE_TYPE_234
 *    EEC_TERTRAFFINE_TYPE_235
 *    EEC_TERTRAFFINE_TYPE_236
 *    EEC_TERTRAFFINE_TYPE_237
 *    EEC_TERTRAFFINE_TYPE_238
 *    EEC_TERTRAFFINE_TYPE_239
 *    EEC_TERTRAFFINE_TYPE_240
 *    EEC_TERTRAFFINE_TYPE_241
 *    EEC_TERTRAFFINE_TYPE_242
 *    EEC_TERTRAFFINE_TYPE_243
 *    EEC_TERTRAFFINE_TYPE_244
 *    EEC_TERTRAFFINE_TYPE_245
 *    EEC_TERTRAFFINE_TYPE_246
 *    EEC_TERTRAFFINE_TYPE_247
 *    EEC_TERTRAFFINE_TYPE_248
 *    EEC_TERTRAFFINE_TYPE_249
 *    EEC_TERTRAFFINE_TYPE_250
 *    EEC_TERTRAFFINE_TYPE_251
 *    EEC_TERTRAFFINE_TYPE_252
 *    EEC_TERTRAFFINE_TYPE_253
 *    EEC_TERTRAFFINE_TYPE_254
 *    EEC_TERTRAFFINE_TYPE_255
 *    EEC_TERTRAFFINE_TYPE_256
 *    EEC_TERTRAFFINE_TYPE_257
 *    EEC_TERTRAFFINE_TYPE_258
 *    EEC_TERTRAFFINE_TYPE_259
 *    EEC_TERTRAFFINE_TYPE_260
 *    EEC_TERTRAFFINE_TYPE_261
 *    EEC_TERTRAFFINE_TYPE_262
 *    EEC_TERTRAFFINE_TYPE_263
 *    EEC_TERTRAFFINE_TYPE_264
 *    EEC_TERTRAFFINE_TYPE_265
 *    EEC_TERTRAFFINE_TYPE_266
 *    EEC_TERTRAFFINE_TYPE_267
 *    EEC_TERTRAFFINE_TYPE_268
 *    EEC_TERTRAFFINE_TYPE_269
 *    EEC_TERTRAFFINE_TYPE_270
 *    EEC_TERTRAFFINE_TYPE_271
 *    EEC_TERTRAFFINE_TYPE_272
 *    EEC_TERTRAFFINE_TYPE_273
 *    EEC_TERTRAFFINE_TYPE_274
 *    EEC_TERTRAFFINE_TYPE_275
 *    EEC_TERTRAFFINE_TYPE_276
 *    EEC_TERTRAFFINE_TYPE_277
 *    EEC_TERTRAFFINE_TYPE_278
 *    EEC_TERTRAFFINE_TYPE_279
 *    EEC_TERTRAFFINE_TYPE_280
 *    EEC_TERTRAFFINE_TYPE_281
 *    EEC_TERTRAFFINE_TYPE_282
 *    EEC_TERTRAFFINE_TYPE_283
 *    EEC_TERTRAFFINE_TYPE_284
 *    EEC_TERTRAFFINE_TYPE_285
 *    EEC_TERTRAFFINE_TYPE_286
 *    EEC_TERTRAFFINE_TYPE_287
 *    EEC_TERTRAFFINE_TYPE_288
 *    EEC_TERTRAFFINE_TYPE_289
 *    EEC_TERTRAFFINE_TYPE_290
 *    EEC_TERTRAFFINE_TYPE_291
 *    EEC_TERTRAFFINE_TYPE_292
 *    EEC_TERTRAFFINE_TYPE_293
 *    EEC_TERTRAFFINE_TYPE_294
 *    EEC_TERTRAFFINE_TYPE_295
 *    EEC_TERTRAFFINE_TYPE_296
 *    EEC_TERTRAFFINE_TYPE_297
 *    EEC_TERTRAFFINE_TYPE_298
 *    EEC_TERTRAFFINE_TYPE_299
 *    EEC_TERTRAFFINE_TYPE_300
 *    EEC_TERTRAFFINE_TYPE_301
 *    EEC_TERTRAFFINE_TYPE_302
 *    EEC_TERTRAFFINE_TYPE_303
 *    EEC_TERTRAFFINE_TYPE_304
 *    EEC_TERTRAFFINE_TYPE_305
 *    EEC_TERTRAFFINE_TYPE_306
 *    EEC_TERTRAFFINE_TYPE_307
 *    EEC_TERTRAFFINE_TYPE_308
 *    EEC_TERTRAFFINE_TYPE_309
 *    EEC_TERTRAFFINE_TYPE_310
 *    EEC_TERTRAFFINE_TYPE_311
 *    EEC_TERTRAFFINE_TYPE_312
 *    EEC_TERTRAFFINE_TYPE_313
 *    EEC_TERTRAFFINE_TYPE_314
 *    EEC_TERTRAFFINE_TYPE_315
 *    EEC_TERTRAFFINE_TYPE_316
 *    EEC_TERTRAFFINE_TYPE_317
 *    EEC_TERTRAFFINE_TYPE_318
 *    EEC_TERTRAFFINE_TYPE_319
 *    EEC_TERTRAFFINE_TYPE_320
 *    EEC_TERTRAFFINE_TYPE_321
 *    EEC_TERTRAFFINE_TYPE_322
 *    EEC_TERTRAFFINE_TYPE_323
 *    EEC_TERTRAFFINE_TYPE_324
 *    EEC_TERTRAFFINE_TYPE_325
 *    EEC_TERTRAFFINE_TYPE_326
 *    EEC_TERTRAFFINE_TYPE_327
 *    EEC_TERTRAFFINE_TYPE_328
 *    EEC_TERTRAFFINE_TYPE_329
 *    EEC_TERTRAFFINE_TYPE_330
 *    EEC_TERTRAFFINE_TYPE_331
 *    EEC_TERTRAFFINE_TYPE_332
 *    EEC_TERTRAFFINE_TYPE_333
 *    EEC_TERTRAFFINE_TYPE_334
 *    EEC_TERTRAFFINE_TYPE_335
 *    EEC_TERTRAFFINE_TYPE_336
 *    EEC_TERTRAFFINE_TYPE_337
 *    EEC_TERTRAFFINE_TYPE_338
 *    EEC_TERTRAFFINE_TYPE_339
 *    EEC_TERTRAFFINE_TYPE_340
 *    EEC_TERTRAFFINE_TYPE_341
 *    EEC_TERTRAFFINE_TYPE_342
 *    EEC_TERTRAFFINE_TYPE_343
 *    EEC_TERTRAFFINE_TYPE_344
 *    EEC_TERTRAFFINE_TYPE_345
 *    EEC_TERTRAFFINE_TYPE_346
 *    EEC_TERTRAFFINE_TYPE_347
 *    EEC_TERTRAFFINE_TYPE_348
 *    EEC_TERTRAFFINE_TYPE_349
 *    EEC_TERTRAFFINE_TYPE_350
 *    EEC_TERTRAFFINE_TYPE_351
 *    EEC_TERTRAFFINE_TYPE_352
 *    EEC_TERTRAFFINE_TYPE_353
 *    EEC_TERTRAFFINE_TYPE_354
 *    EEC_TERTRAFFINE_TYPE_355
 *    EEC_TERTRAFFINE_TYPE_356
 *    EEC_TERTRAFFINE_TYPE_357
 *    EEC_TERTRAFFINE_TYPE_358
 *    EEC_TERTRAFFINE_TYPE_359
 *    EEC_TERTRAFFINE_TYPE_360
 *    EEC_TERTRAFFINE_TYPE_361
 *    EEC_TERTRAFFINE_TYPE_362
 *    EEC_TERTRAFFINE_TYPE_363
 *    EEC_TERTRAFFINE_TYPE_364
 *    EEC_TERTRAFFINE_TYPE_365
 *    EEC_TERTRAFFINE_TYPE_366
 *    EEC_TERTRAFFINE_TYPE_367
 *    EEC_TERTRAFFINE_TYPE_368
 *    EEC_TERTRAFFINE_TYPE_369
 *    EEC_TERTRAFFINE_TYPE_370
 *    EEC_TERTRAFFINE_TYPE_371
 *    EEC_TERTRAFFINE_TYPE_372
 *    EEC_TERTRAFFINE_TYPE_373
 *    EEC_TERTRAFFINE_TYPE_374
 *    EEC_TERTRAFFINE_TYPE_375
 *    EEC_TERTRAFFINE_TYPE_376
 *    EEC_TERTRAFFINE_TYPE_377
 *    EEC_TERTRAFFINE_TYPE_378
 *    EEC_TERTRAFFINE_TYPE_379
 *    EEC_TERTRAFFINE_TYPE_380
 *    EEC_TERTRAFFINE_TYPE_381
 *    EEC_TERTRAFFINE_TYPE_382
 *    EEC_TERTRAFFINE_TYPE_383
 *    EEC_TERTRAFFINE_TYPE_384
 *    EEC_TERTRAFFINE_TYPE_385
 *    EEC_TERTRAFFINE_TYPE_386
 *    EEC_TERTRAFFINE_TYPE_387
 *    EEC_TERTRAFFINE_TYPE_388
 *    EEC_TERTRAFFINE_TYPE_389
 *    EEC_TERTRAFFINE_TYPE_390
 *    EEC_TERTRAFFINE_TYPE_391
 *    EEC_TERTRAFFINE_TYPE_392
 *    EEC_TERTRAFFINE_TYPE_393
 *    EEC_TERTRAFFINE_TYPE_394
 *    EEC_TERTRAFFINE_TYPE_395
 *    EEC_TERTRAFFINE_TYPE_396
 *    EEC_TERTRAFFINE_TYPE_397
 *    EEC_TERTRAFFINE_TYPE_398
 *    EEC_TERTRAFFINE_TYPE_399
 *    EEC_TERTRAFFINE_TYPE_400
 *    EEC_TERTRAFFINE_TYPE_401
 *    EEC_TERTRAFFINE_TYPE_402
 *    EEC_TERTRAFFINE_TYPE_403
 *    EEC_TERTRAFFINE_TYPE_404
 *    EEC_TERTRAFFINE_TYPE_405
 *    EEC_TERTRAFFINE_TYPE_406
 *    EEC_TERTRAFFINE_TYPE_407
 *    EEC_TERTRAFFINE_TYPE_408
 *    EEC_TERTRAFFINE_TYPE_409
 *    EEC_TERTRAFFINE_TYPE_410
 *    EEC_TERTRAFFINE_TYPE_411
 *    EEC_TERTRAFFINE_TYPE_412
 *    EEC_TERTRAFFINE_TYPE_413
 *    EEC_TERTRAFFINE_TYPE_414
 *    EEC_TERTRAFFINE_TYPE_415
 *    EEC_TERTRAFFINE_TYPE_416
 *    EEC_TERTRAFFINE_TYPE_417
 *    EEC_TERTRAFFINE_TYPE_418
 *    EEC_TERTRAFFINE_TYPE_419
 *    EEC_TERTRAFFINE_TYPE_420
 *    EEC_TERTRAFFINE_TYPE_421
 *    EEC_TERTRAFFINE_TYPE_422
 *    EEC_TERTRAFFINE_TYPE_423
 *    EEC_TERTRAFFINE_TYPE_424
 *    EEC_TERTRAFFINE_TYPE_425
 *    EEC_TERTRAFFINE_TYPE_426
 *    EEC_TERTRAFFINE_TYPE_427
 *    EEC_TERTRAFFINE_TYPE_428
 *    EEC_TERTRAFFINE_TYPE_429
 *    EEC_TERTRAFFINE_TYPE_430
 *    EEC_TERTRAFFINE_TYPE_431
 *    EEC_TERTRAFFINE_TYPE_432
 *    EEC_TERTRAFFINE_TYPE_433
 *    EEC_TERTRAFFINE_TYPE_434
 *    EEC_TERTRAFFINE_TYPE_435
 *    EEC_TERTRAFFINE_TYPE_436
 *    EEC_TERTRAFFINE_TYPE_437
 *    EEC_TERTRAFFINE_TYPE_438
 *    EEC_TERTRAFFINE_TYPE_439
 *    EEC_TERTRAFFINE_TYPE_440
 *    EEC_TERTRAFFINE_TYPE_441
 *    EEC_TERTRAFFINE_TYPE_442
 *    EEC_TERTRAFFINE_TYPE_443
 *    EEC_TERTRAFFINE_TYPE_444
 *    EEC_TERTRAFFINE_TYPE_445
 *    EEC_TERTRAFFINE_TYPE_446
 *    EEC_TERTRAFFINE_TYPE_447
 *    EEC_TERTRAFFINE_TYPE_448
 *    EEC_TERTRAFFINE_TYPE_449
 *    EEC_TERTRAFFINE_TYPE_450
 *    EEC_TERTRAFFINE_TYPE_451
 *    EEC_TERTRAFFINE_TYPE_452
 *    EEC_TERTRAFFINE_TYPE_453
 *    EEC_TERTRAFFINE_TYPE_454
 *    EEC_TERTRAFFINE_TYPE_455
 *    EEC_TERTRAFFINE_TYPE_456
 *    EEC_TERTRAFFINE_TYPE_457
 *    EEC_TERTRAFFINE_TYPE_458
 *    EEC_TERTRAFFINE_TYPE_459
 *    EEC_TERTRAFFINE_TYPE_460
 *    EEC_TERTRAFFINE_TYPE_461
 *    EEC_TERTRAFFINE_TYPE_462
 *    EEC_TERTRAFFINE_TYPE_463
 *    EEC_TERTRAFFINE_TYPE_464
 *    EEC_TERTRAFFINE_TYPE_465
 *    EEC_TERTRAFFINE_TYPE_466
 *    EEC_TERTRAFFINE_TYPE_467
 *    EEC_TERTRAFFINE_TYPE_468
 *    EEC_TERTRAFFINE_TYPE_469
 *    EEC_TERTRAFFINE_TYPE_470
 *    EEC_TERTRAFFINE_TYPE_471
 *    EEC_TERTRAFFINE_TYPE_472
 *    EEC_TERTRAFFINE_TYPE_473
 *    EEC_TERTRAFFINE_TYPE_474
 *    EEC_TERTRAFFINE_TYPE_475
 *    EEC_TERTRAFFINE_TYPE_476
 *    EEC_TERTRAFFINE_TYPE_477
 *    EEC_TERTRAFFINE_TYPE_478
 *    EEC_TERTRAFFINE_TYPE_479
 *    EEC_TERTRAFFINE_TYPE_480
 *    EEC_TERTRAFFINE_TYPE_481
 *    EEC_TERTRAFFINE_TYPE_482
 *    EEC_TERTRAFFINE_TYPE_483
 *    EEC_TERTRAFFINE_TYPE_484
 *    EEC_TERTRAFFINE_TYPE_485
 *    EEC_TERTRAFFINE_TYPE_486
 *    EEC_TERTRAFFINE_TYPE_487
 *    EEC_TERTRAFFINE_TYPE_488
 *    EEC_TERTRAFFINE_TYPE_489
 *    EEC_TERTRAFFINE_TYPE_490
 *    EEC_TERTRAFFINE_TYPE_491
 *    EEC_TERTRAFFINE_TYPE_492
 *    EEC_TERTRAFFINE_TYPE_493
 *    EEC_TERTRAFFINE_TYPE_494
 *    EEC_TERTRAFFINE_TYPE_495
 *    EEC_TERTRAFFINE_TYPE_496
 *    EEC_TERTRAFFINE_TYPE_497
 *    EEC_TERTRAFFINE_TYPE_498
 *    EEC_TERTRAFFINE_TYPE_499
 *    EEC_TERTRAFFINE_TYPE_500
 *    EEC_TERTRAFFINE_TYPE_501
 *    EEC_TERTRAFFINE_TYPE_502
 *    EEC_TERTRAFFINE_TYPE_503
 *    EEC_TERTRAFFINE_TYPE_504
 *    EEC_TERTRAFFINE_TYPE_505
 *    EEC_TERTRAFFINE_TYPE_506
 *    EEC_TERTRAFFINE_TYPE_507
 *    EEC_TERTRAFFINE_TYPE_508
 *    EEC_TERTRAFFINE_TYPE_509
 *    EEC_TERTRAFFINE_TYPE_510
 *    EEC_TERTRAFFINE_TYPE_511
 *    EEC_TERTRAFFINE_TYPE_512
 *    EEC_TERTRAFFINE_TYPE_513
 *    EEC_TERTRAFFINE_TYPE_514
 *    EEC_TERTRAFFINE_TYPE_515
 *    EEC_TERTRAFFINE_TYPE_516
 *    EEC_TERTRAFFINE_TYPE_517
 *    EEC_TERTRAFFINE_TYPE_518
 *    EEC_TERTRAFFINE_TYPE_519
 *    EEC_TERTRAFFINE_TYPE_520
 *    EEC_TERTRAFFINE_TYPE_521
 *    EEC_TERTRAFFINE_TYPE_522
 *    EEC_TERTRAFFINE_TYPE_523
 *    EEC_TERTRAFFINE_TYPE_524
 *    EEC_TERTRAFFINE_TYPE_525
 *    EEC_TERTRAFFINE_TYPE_526
 *    EEC_TERTRAFFINE_TYPE_527
 *    EEC_TERTRAFFINE_TYPE_528
 *    EEC_TERTRAFFINE_TYPE_529
 *    EEC_TERTRAFFINE_TYPE_530
 *    EEC_TERTRAFFINE_TYPE_531
 *    EEC_TERTRAFFINE_TYPE_532
 *    EEC_TERTRAFFINE_TYPE_533
 *    EEC_TERTRAFFINE_TYPE_534
 *    EEC_TERTRAFFINE_TYPE_535
 *    EEC_TERTRAFFINE_TYPE_536
 *    EEC_TERTRAFFINE_TYPE_537
 *    EEC_TERTRAFFINE_TYPE_538
 *    EEC_TERTRAFFINE_TYPE_539
 *    EEC_TERTRAFFINE_TYPE_540
 *    EEC_TERTRAFFINE_TYPE_541
 *    EEC_TERTRAFFINE_TYPE_542
 *    EEC_TERTRAFFINE_TYPE_543
 *    EEC_TERTRAFFINE_TYPE_544
 *    EEC_TERTRAFFINE_TYPE_545
 *    EEC_TERTRAFFINE_TYPE_546
 *    EEC_TERTRAFFINE_TYPE_547
 *    EEC_TERTRAFFINE_TYPE_548
 *    EEC_TERTRAFFINE_TYPE_549
 *    EEC_TERTRAFFINE_TYPE_550
 *    EEC_TERTRAFFINE_TYPE_551
 *    EEC_TERTRAFFINE_TYPE_552
 *    EEC_TERTRAFFINE_TYPE_553
 *    EEC_TERTRAFFINE_TYPE_554
 *    EEC_TERTRAFFINE_TYPE_555
 *    EEC_TERTRAFFINE_TYPE_556
 *    EEC_TERTRAFFINE_TYPE_557
 *    EEC_TERTRAFFINE_TYPE_558
 *    EEC_TERTRAFFINE_TYPE_559
 *    EEC_TERTRAFFINE_TYPE_560
 *    EEC_TERTRAFFINE_TYPE_561
 *    EEC_TERTRAFFINE_TYPE_562
 *    EEC_TERTRAFFINE_TYPE_563
 *    EEC_TERTRAFFINE_TYPE_564
 *    EEC_TERTRAFFINE_TYPE_565
 *    EEC_TERTRAFFINE_TYPE_566
 *    EEC_TERTRAFFINE_TYPE_567
 *    EEC_TERTRAFFINE_TYPE_568
 *    EEC_TERTRAFFINE_TYPE_569
 *    EEC_TERTRAFFINE_TYPE_570
 *    EEC_TERTRAFFINE_TYPE_571
 *    EEC_TERTRAFFINE_TYPE_572
 *    EEC_TERTRAFFINE_TYPE_573
 *    EEC_TERTRAFFINE_TYPE_574
 *    EEC_TERTRAFFINE_TYPE_575
 *    EEC_TERTRAFFINE_TYPE_576
 *    EEC_TERTRAFFINE_TYPE_577
 *    EEC_TERTRAFFINE_TYPE_578
 *    EEC_TERTRAFFINE_TYPE_579
 *    EEC_TERTRAFFINE_TYPE_580
 *    EEC_TERTRAFFINE_TYPE_581
 *    EEC_TERTRAFFINE_TYPE_582
 *    EEC_TERTRAFFINE_TYPE_583
 *    EEC_TERTRAFFINE_TYPE_584
 *    EEC_TERTRAFFINE_TYPE_585
 *    EEC_TERTRAFFINE_TYPE_586
 *    EEC_TERTRAFFINE_TYPE_587
 *    EEC_TERTRAFFINE_TYPE_588
 *    EEC_TERTRAFFINE_TYPE_589
 *    EEC_TERTRAFFINE_TYPE_590
 *    EEC_TERTRAFFINE_TYPE_591
 *    EEC_TERTRAFFINE_TYPE_592
 *    EEC_TERTRAFFINE_TYPE_593
 *    EEC_TERTRAFFINE_TYPE_594
 *    EEC_TERTRAFFINE_TYPE_595
 *    EEC_TERTRAFFINE_TYPE_596
 *    EEC_TERTRAFFINE_TYPE_597
 *    EEC_TERTRAFFINE_TYPE_598
 *    EEC_TERTRAFFINE_TYPE_599
 *    EEC_TERTRAFFINE_TYPE_600
 *    EEC_TERTRAFFINE_TYPE_601
 *    EEC_TERTRAFFINE_TYPE_602
 *    EEC_TERTRAFFINE_TYPE_603
 *    EEC_TERTRAFFINE_TYPE_604
 *    EEC_TERTRAFFINE_TYPE_605
 *    EEC_TERTRAFFINE_TYPE_606
 *    EEC_TERTRAFFINE_TYPE_607
 *    EEC_TERTRAFFINE_TYPE_608
 *    EEC_TERTRAFFINE_TYPE_609
 *    EEC_TERTRAFFINE_TYPE_610
 *    EEC_TERTRAFFINE_TYPE_611
 *    EEC_TERTRAFFINE_TYPE_612
 *    EEC_TERTRAFFINE_TYPE_613
 *    EEC_TERTRAFFINE_TYPE_614
 *    EEC_TERTRAFFINE_TYPE_615
 *    EEC_TERTRAFFINE_TYPE_616
 *    EEC_TERTRAFFINE_TYPE_617
 *    EEC_TERTRAFFINE_TYPE_618
 *    EEC_TERTRAFFINE_TYPE_619
 *    EEC_TERTRAFFINE_TYPE_620
 *    EEC_TERTRAFFINE_TYPE_621
 *    EEC_TERTRAFFINE_TYPE_622
 *    EEC_TERTRAFFINE_TYPE_623
 *    EEC_TERTRAFFINE_TYPE_624
 *    EEC_TERTRAFFINE_TYPE_625
 *    EEC_TERTRAFFINE_TYPE_626
 *    EEC_TERTRAFFINE_TYPE_627
 *    EEC_TERTRAFFINE_TYPE_628
 *    EEC_TERTRAFFINE_TYPE_629
 *    EEC_TERTRAFFINE_TYPE_630
 *    EEC_TERTRAFFINE_TYPE_631
 *    EEC_TERTRAFFINE_TYPE_632
 *    EEC_TERTRAFFINE_TYPE_633
 *    EEC_TERTRAFFINE_TYPE_634
 *    EEC_TERTRAFFINE_TYPE_635
 *    EEC_TERTRAFFINE_TYPE_636
 *    EEC_TERTRAFFINE_TYPE_637
 *    EEC_TERTRAFFINE_TYPE_638
 *    EEC_TERTRAFFINE_TYPE_639
 *    EEC_TERTRAFFINE_TYPE_640
 *    EEC_TERTRAFFINE_TYPE_641
 *    EEC_TERTRAFFINE_TYPE_642
 *    EEC_TERTRAFFINE_TYPE_643
 *    EEC_TERTRAFFINE_TYPE_644
 *    EEC_TERTRAFFINE_TYPE_645
 *    EEC_TERTRAFFINE_TYPE_646
 *    EEC_TERTRAFFINE_TYPE_647
 *    EEC_TERTRAFFINE_TYPE_648
 *    EEC_TERTRAFFINE_TYPE_649
 *    EEC_TERTRAFFINE_TYPE_650
 *    EEC_TERTRAFFINE_TYPE_651
 *    EEC_TERTRAFFINE_TYPE_652
 *    EEC_TERTRAFFINE_TYPE_653
 *    EEC_TERTRAFFINE_TYPE_654
 *    EEC_TERTRAFFINE_TYPE_655
 *    EEC_TERTRAFFINE_TYPE_656
 *    EEC_TERTRAFFINE_TYPE_657
 *    EEC_TERTRAFFINE_TYPE_658
 *    EEC_TERTRAFFINE_TYPE_659
 *    EEC_TERTRAFFINE_TYPE_660
 *    EEC_TERTRAFFINE_TYPE_661
 *    EEC_TERTRAFFINE_TYPE_662
 *    EEC_TERTRAFFINE_TYPE_663
 *    EEC_TERTRAFFINE_TYPE_664
 *    EEC_TERTRAFFINE_TYPE_665
 *    EEC_TERTRAFFINE_TYPE_666
 *    EEC_TERTRAFFINE_TYPE_667
 *    EEC_TERTRAFFINE_TYPE_668
 *    EEC_TERTRAFFINE_TYPE_669
 *    EEC_TERTRAFFINE_TYPE_670
 *    EEC_TERTRAFFINE_TYPE_671
 *    EEC_TERTRAFFINE_TYPE_672
 *    EEC_TERTRAFFINE_TYPE_673
 *    EEC_TERTRAFFINE_TYPE_674
 *    EEC_TERTRAFFINE_TYPE_675
 *    EEC_TERTRAFFINE_TYPE_676
 *    EEC_TERTRAFFINE_TYPE_677
 *    EEC_TERTRAFFINE_TYPE_678
 *    EEC_TERTRAFFINE_TYPE_679
 *    EEC_TERTRAFFINE_TYPE_680
 *    EEC_TERTRAFFINE_TYPE_681
 *    EEC_TERTRAFFINE_TYPE_682
 *    EEC_TERTRAFFINE_TYPE_683
 *    EEC_TERTRAFFINE_TYPE_684
 *    EEC_TERTRAFFINE_TYPE_685
 *    EEC_TERTRAFFINE_TYPE_686
 *    EEC_TERTRAFFINE_TYPE_687
 *    EEC_TERTRAFFINE_TYPE_688
 *    EEC_TERTRAFFINE_TYPE_689
 *    EEC_TERTRAFFINE_TYPE_690
 *    EEC_TERTRAFFINE_TYPE_691
 *    EEC_TERTRAFFINE_TYPE_692
 *    EEC_TERTRAFFINE_TYPE_693
 *    EEC_TERTRAFFINE_TYPE_694
 *    EEC_TERTRAFFINE_TYPE_695
 *    EEC_TERTRAFFINE_TYPE_696
 *    EEC_TERTRAFFINE_TYPE_697
 *    EEC_TERTRAFFINE_TYPE_698
 *    EEC_TERTRAFFINE_TYPE_699
 *    EEC_TERTRAFFINE_TYPE_700
 *    EEC_TERTRAFFINE_TYPE_701
 *    EEC_TERTRAFFINE_TYPE_702
 *    EEC_TERTRAFFINE_TYPE_703
 *    EEC_TERTRAFFINE_TYPE_704
 *    EEC_TERTRAFFINE_TYPE_705
 *    EEC_TERTRAFFINE_TYPE_706
 *    EEC_TERTRAFFINE_TYPE_707
 *    EEC_TERTRAFFINE_TYPE_708
 *    EEC_TERTRAFFINE_TYPE_709
 *    EEC_TERTRAFFINE_TYPE_710
 *    EEC_TERTRAFFINE_TYPE_711
 *    EEC_TERTRAFFINE_TYPE_712
 *    EEC_TERTRAFFINE_TYPE_713
 *    EEC_TERTRAFFINE_TYPE_714
 *    EEC_TERTRAFFINE_TYPE_715
 *    EEC_TERTRAFFINE_TYPE_716
 *    EEC_TERTRAFFINE_TYPE_717
 *    EEC_TERTRAFFINE_TYPE_718
 *    EEC_TERTRAFFINE_TYPE_719
 *    EEC_TERTRAFFINE_TYPE_720
 *    EEC_TERTRAFFINE_TYPE_721
 *    EEC_TERTRAFFINE_TYPE_722
 *    EEC_TERTRAFFINE_TYPE_723
 *    EEC_TERTRAFFINE_TYPE_724
 *    EEC_TERTRAFFINE_TYPE_725
 *    EEC_TERTRAFFINE_TYPE_726
 *    EEC_TERTRAFFINE_TYPE_727
 *    EEC_TERTRAFFINE_TYPE_728
 *    EEC_TERTRAFFINE_TYPE_729
 *    EEC_TERTRAFFINE_TYPE_730
 *    EEC_TERTRAFFINE_TYPE_731
 *    EEC_TERTRAFFINE_TYPE_732
 *    EEC_TERTRAFFINE_TYPE_733
 *    EEC_TERTRAFFINE_TYPE_734
 *    EEC_TERTRAFFINE_TYPE_735
 *    EEC_TERTRAFFINE_TYPE_736
 *    EEC_TERTRAFFINE_TYPE_737
 *    EEC_TERTRAFFINE_TYPE_738
 *    EEC_TERTRAFFINE_TYPE_739
 *    EEC_TERTRAFFINE_TYPE_740
 *    EEC_TERTRAFFINE_TYPE_741
 *    EEC_TERTRAFFINE_TYPE_742
 *    EEC_TERTRAFFINE_TYPE_743
 *    EEC_TERTRAFFINE_TYPE_744
 *    EEC_TERTRAFFINE_TYPE_745
 *    EEC_TERTRAFFINE_TYPE_746
 *    EEC_TERTRAFFINE_TYPE_747
 *    EEC_TERTRAFFINE_TYPE_748
 *    EEC_TERTRAFFINE_TYPE_749
 *    EEC_TERTRAFFINE_TYPE_750
 *    EEC_TERTRAFFINE_TYPE_751
 *    EEC_TERTRAFFINE_TYPE_752
 *    EEC_TERTRAFFINE_TYPE_753
 *    EEC_TERTRAFFINE_TYPE_754
 *    EEC_TERTRAFFINE_TYPE_755
 *    EEC_TERTRAFFINE_TYPE_756
 *    EEC_TERTRAFFINE_TYPE_757
 *    EEC_TERTRAFFINE_TYPE_758
 *    EEC_TERTRAFFINE_TYPE_759
 *    EEC_TERTRAFFINE_TYPE_760
 *    EEC_TERTRAFFINE_TYPE_761
 *    EEC_TERTRAFFINE_TYPE_762
 *    EEC_TERTRAFFINE_TYPE_763
 *    EEC_TERTRAFFINE_TYPE_764
 *    EEC_TERTRAFFINE_TYPE_765
 *    EEC_TERTRAFFINE_TYPE_766
 *    EEC_TERTRAFFINE_TYPE_767
 *    EEC_TERTRAFFINE_TYPE_768
 *    EEC_TERTRAFFINE_TYPE_769
 *    EEC_TERTRAFFINE_TYPE_770
 *    EEC_TERTRAFFINE_TYPE_771
 *    EEC_TERTRAFFINE_TYPE_772
 *    EEC_TERTRAFFINE_TYPE_773
 *    EEC_TERTRAFFINE_TYPE_774
 *    EEC_TERTRAFFINE_TYPE_775
 *    EEC_TERTRAFFINE_TYPE_776
 *    EEC_TERTRAFFINE_TYPE_777
 *    EEC_TERTRAFFINE_TYPE_778
 *    EEC_TERTRAFFINE_TYPE_779
 *    EEC_TERTRAFFINE_TYPE_780
 *    EEC_TERTRAFFINE_TYPE_781
 *    EEC_TERTRAFFINE_TYPE_782
 *    EEC_TERTRAFFINE_TYPE_783
 *    EEC_TERTRAFFINE_TYPE_784
 *    EEC_TERTRAFFINE_TYPE_785
 *    EEC_TERTRAFFINE_TYPE_786
 *    EEC_TERTRAFFINE_TYPE_787
 *    EEC_TERTRAFFINE_TYPE_788
 *    EEC_TERTRAFFINE_TYPE_789
 *    EEC_TERTRAFFINE_TYPE_790
 *    EEC_TERTRAFFINE_TYPE_791
 *    EEC_TERTRAFFINE_TYPE_792
 *    EEC_TERTRAFFINE_TYPE_793
 *    EEC_TERTRAFFINE_TYPE_794
 *    EEC_TERTRAFFINE_TYPE_795
 *    EEC_TERTRAFFINE_TYPE_796
 *    EEC_TERTRAFFINE_TYPE_797
 *    EEC_TERTRAFFINE_TYPE_798
 *    EEC_TERTRAFFINE_TYPE_799
 *    EEC_TERTRAFFINE_TYPE_800
 *    EEC_TERTRAFFINE_TYPE_801
 *    EEC_TERTRAFFINE_TYPE_802
 *    EEC_TERTRAFFINE_TYPE_803
 *    EEC_TERTRAFFINE_TYPE_804
 *    EEC_TERTRAFFINE_TYPE_805
 *    EEC_TERTRAFFINE_TYPE_806
 *    EEC_TERTRAFFINE_TYPE_807
 *    EEC_TERTRAFFINE_TYPE_808
 *    EEC_TERTRAFFINE_TYPE_809
 *    EEC_TERTRAFFINE_TYPE_810
 *    EEC_TERTRAFFINE_TYPE_811
 *    EEC_TERTRAFFINE_TYPE_812
 *    EEC_TERTRAFFINE_TYPE_813
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_TERRAIN_TRAFFICABILITY_FINE ((EDCS_Attribute_Code)1424)

/*
 * Definition:
 *     A medium measure of the trafficability of the <TERRAIN> as it affects
 *     the movement of ground forces (for example: a military unit, a
 *     military <GROUND_VEHICLE>, and/or infantry).
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TERTRAFMED_TYPE_0
 *    EEC_TERTRAFMED_TYPE_1
 *    EEC_TERTRAFMED_TYPE_2
 *    EEC_TERTRAFMED_TYPE_3
 *    EEC_TERTRAFMED_TYPE_4
 *    EEC_TERTRAFMED_TYPE_5
 *    EEC_TERTRAFMED_TYPE_6
 *    EEC_TERTRAFMED_TYPE_7
 *    EEC_TERTRAFMED_TYPE_8
 *    EEC_TERTRAFMED_TYPE_9
 *    EEC_TERTRAFMED_TYPE_10
 *    EEC_TERTRAFMED_TYPE_11
 *    EEC_TERTRAFMED_TYPE_12
 *    EEC_TERTRAFMED_TYPE_13
 *    EEC_TERTRAFMED_TYPE_14
 *    EEC_TERTRAFMED_TYPE_15
 *    EEC_TERTRAFMED_TYPE_16
 *    EEC_TERTRAFMED_TYPE_17
 *    EEC_TERTRAFMED_TYPE_18
 *    EEC_TERTRAFMED_TYPE_19
 *    EEC_TERTRAFMED_TYPE_20
 *    EEC_TERTRAFMED_TYPE_21
 *    EEC_TERTRAFMED_TYPE_22
 *    EEC_TERTRAFMED_TYPE_23
 *    EEC_TERTRAFMED_TYPE_24
 *    EEC_TERTRAFMED_TYPE_25
 *    EEC_TERTRAFMED_TYPE_26
 *    EEC_TERTRAFMED_TYPE_27
 *    EEC_TERTRAFMED_TYPE_28
 *    EEC_TERTRAFMED_TYPE_29
 *    EEC_TERTRAFMED_TYPE_30
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define EAC_TERRAIN_TRAFFICABILITY_MEDIUM ((EDCS_Attribute_Code)1425)

/*
 * Definition:
 *     The <<VELOCITY>> component of an <OBJECT> along the tertiary axis of a
 *     defined spatial reference frame.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_TERTIARY_AXIS_VELOCITY_COMPONENT ((EDCS_Attribute_Code)1426)

/*
 * Definition:
 *     The textual identifier (often termed the "number") of an <OBJECT>.
 *
 * Value Type: STRING
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_TEXTUAL_OBJECT_IDENTIFIER ((EDCS_Attribute_Code)1427)

/*
 * Definition:
 *     The proportionality factor between energy flux and the gradient of
 *     <<TEMPERATURE>>; thermal conductivity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMAL_CONDUCTIVITY
 *
 * Group Membership: MATERIAL, RATE_OR_RATIO, TEMPERATURE
 */
#define EAC_THERMAL_CONDUCTIVITY ((EDCS_Attribute_Code)1428)

/*
 * Definition:
 *     The thermal penetration (effective depth) of variation in
 *     <<TEMPERATURE>> within a <MATERIAL>over a diurnal cycle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION, TEMPERATURE
 */
#define EAC_THERMAL_PENETRATION_DEPTH ((EDCS_Attribute_Code)1429)

/*
 * Definition:
 *     The gradient of <<TEMPERATURE>> within a thermocline. A thermocline is
 *     that <REGION> in a thermally stratified <WATERBODY> in which the
 *     <<WATERBODY_TEMPERATURE>> decrease with <<DEPTH>> is greater than
 *     that of the <WATER> above and below it.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_THERMOCLINE_TEMP_GRADIENT ((EDCS_Attribute_Code)1430)

/*
 * Definition:
 *     The standard deviation of <<THERMOCLINE_TEMP_GRADIENT>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_THERMOCLINE_TEMP_GRADIENT_STD_DEV ((EDCS_Attribute_Code)1431)

/*
 * Definition:
 *     The distance between two opposite <SURFACE>s of an <OBJECT>, usually
 *     the distance of smallest measure; the thickness.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_THICKNESS ((EDCS_Attribute_Code)1432)

/*
 * Definition:
 *     The intensity of a <THUNDERSTORM> as determined by its
 *     <<PRECIPITATION_RATE>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TSTORMINT_LIGHT
 *    EEC_TSTORMINT_MODERATE
 *    EEC_TSTORMINT_HEAVY
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_THUNDERSTORM_INTENSITY ((EDCS_Attribute_Code)1433)

/*
 * Definition:
 *     The maximum <<WIND_SPEED>> measured within a <THUNDERSTORM>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_THUNDERSTORM_MAXIMUM_WIND_SPEED ((EDCS_Attribute_Code)1434)

/*
 * Definition:
 *     An indication that a <THUNDERSTORM> is present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_THUNDERSTORM_PRESENT ((EDCS_Attribute_Code)1435)

/*
 * Definition:
 *     The probability of the occurrence of a <THUNDERSTORM>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_THUNDERSTORM_PROBABILITY ((EDCS_Attribute_Code)1436)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of the top of a <THUNDERSTORM>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define EAC_THUNDERSTORM_TOP_ALTITUDE ((EDCS_Attribute_Code)1437)

/*
 * Definition:
 *     A level of a <WATERBODY> defined by some phase of the <TIDE>, from
 *     which water <<DEPTH>>s and <<TIDE_LEVEL>>s are reckoned; the tidal
 *     datum.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TIDALDATUM_CHART_DATUM
 *    EEC_TIDALDATUM_HIGHEST_ASTRONOMICAL_TIDE
 *    EEC_TIDALDATUM_LOWEST_ASTRONOMICAL_TIDE
 *    EEC_TIDALDATUM_MEAN_HIGH_WTR
 *    EEC_TIDALDATUM_MEAN_HIGH_WTR_NEAPS
 *    EEC_TIDALDATUM_MEAN_HIGH_WTR_SPRINGS
 *    EEC_TIDALDATUM_MEAN_HIGHER_HIGH_WTR
 *    EEC_TIDALDATUM_MEAN_HIGHER_LOW_WTR
 *    EEC_TIDALDATUM_MEAN_LOW_WTR
 *    EEC_TIDALDATUM_MEAN_LOW_WTR_NEAPS
 *    EEC_TIDALDATUM_MEAN_LOW_WTR_SPRINGS
 *    EEC_TIDALDATUM_MEAN_LOWER_HIGH_WTR
 *    EEC_TIDALDATUM_MEAN_LOWER_LOW_WTR
 *    EEC_TIDALDATUM_MEAN_SEA_LEVEL
 *    EEC_TIDALDATUM_MEAN_TIDE_LEVEL
 *
 * Group Membership: LITTORAL, WATERBODY_SURFACE
 */
#define EAC_TIDAL_DATUM ((EDCS_Attribute_Code)1438)

/*
 * Definition:
 *     An indication that an <OBJECT> is affected by the <TIDE>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT, WATERBODY_SURFACE
 */
#define EAC_TIDE_INFLUENCED ((EDCS_Attribute_Code)1439)

/*
 * Definition:
 *     The <<HEIGHT>> above a <<TIDAL_DATUM>> of a <WATERBODY_SURFACE>
 *     influenced by the <TIDE>; the tide level.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_SURFACE
 */
#define EAC_TIDE_LEVEL ((EDCS_Attribute_Code)1440)

/*
 * Definition:
 *     The coordinate value for a defined temporal reference frame; the time
 *     coordinate.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME
 */
#define EAC_TIME_COORDINATE ((EDCS_Attribute_Code)1441)

/*
 * Definition:
 *     The division of the day (one of several) marked by the passage of the
 *     <SUN> through its diurnal cycle; the time division within the day.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TIMEDIVWTHNDAY_SUNRISE
 *    EEC_TIMEDIVWTHNDAY_DAYTIME
 *    EEC_TIMEDIVWTHNDAY_SUNSET
 *    EEC_TIMEDIVWTHNDAY_NIGHT_TIME
 *    EEC_TIMEDIVWTHNDAY_CONTINUOUS
 *
 * Group Membership: TIME
 */
#define EAC_TIME_DIVISION_WITHIN_DAY ((EDCS_Attribute_Code)1442)

/*
 * Definition:
 *     The format of a time of the day.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TIMEFMT_COORDINATED_UNIVERSAL_TIME
 *    EEC_TIMEFMT_HH
 *    EEC_TIMEFMT_HH_MM
 *    EEC_TIMEFMT_HH_MM_SS
 *    EEC_TIMEFMT_HH_MM_SS_HH_MM
 *    EEC_TIMEFMT_HH_MM_SS_S
 *    EEC_TIMEFMT_HH_MM_SSZ
 *    EEC_TIMEFMT_HHMM
 *    EEC_TIMEFMT_HHMMSS
 *    EEC_TIMEFMT_HHMMSS_HHMM
 *    EEC_TIMEFMT_HHMMSS_S
 *    EEC_TIMEFMT_HHMMSSZ
 *    EEC_TIMEFMT_ISO
 *    EEC_TIMEFMT_LOCAL
 *    EEC_TIMEFMT_MM
 *    EEC_TIMEFMT_MM_M
 *    EEC_TIMEFMT_MM_SS
 *    EEC_TIMEFMT_MM_SS_S
 *    EEC_TIMEFMT_MMSS
 *    EEC_TIMEFMT_MMSS_S
 *    EEC_TIMEFMT_SS
 *    EEC_TIMEFMT_SS_S
 *
 * Group Membership: TIME
 */
#define EAC_TIME_FORMAT ((EDCS_Attribute_Code)1443)

/*
 * Definition:
 *     A time of the day formatted as a <<TIME_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TIME
 */
#define EAC_TIME_OF_DAY ((EDCS_Attribute_Code)1444)

/*
 * Definition:
 *     A period of time; formatted as specified by <<TIME_PERIOD_FORMAT>>.
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TIME
 */
#define EAC_TIME_PERIOD ((EDCS_Attribute_Code)1445)

/*
 * Definition:
 *     The format of a period of time.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TIMEPERFMT_ISO
 *    EEC_TIMEPERFMT_PERIOD_START_END
 *    EEC_TIMEPERFMT_DURATION
 *    EEC_TIMEPERFMT_PERIOD_START_DURATION
 *    EEC_TIMEPERFMT_PERIOD_DURATION_END
 *    EEC_TIMEPERFMT_REDUCED
 *
 * Group Membership: TIME
 */
#define EAC_TIME_PERIOD_FORMAT ((EDCS_Attribute_Code)1446)

/*
 * Definition:
 *     A quantity of time (period).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME
 */
#define EAC_TIME_QUANTITY ((EDCS_Attribute_Code)1447)

/*
 * Definition:
 *     The <<TEMPERATURE>> of the <SOIL> between zero and five centimetres
 *     below the <SURFACE> of the <TERRAIN>; the top layer soil temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: PHYSIOGRAPHY, TEMPERATURE
 */
#define EAC_TOP_LAYER_SOIL_TEMPERATURE ((EDCS_Attribute_Code)1448)

/*
 * Definition:
 *     The <<WIDTH>> of an <OBJECT> at its top.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_TOP_WIDTH ((EDCS_Attribute_Code)1449)

/*
 * Definition:
 *     The shape of a <TOPMARK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TPMKSHAP_BESOM_POINT_DOWN
 *    EEC_TPMKSHAP_BESOM_POINT_UP
 *    EEC_TPMKSHAP_BOARD
 *    EEC_TPMKSHAP_CONE_POINT_DOWN
 *    EEC_TPMKSHAP_CONE_POINT_UP
 *    EEC_TPMKSHAP_CROSS_SHAPED
 *    EEC_TPMKSHAP_CUBE_POINT_UP
 *    EEC_TPMKSHAP_CYLINDER
 *    EEC_TPMKSHAP_RHOMBUS
 *    EEC_TPMKSHAP_SPHERE
 *    EEC_TPMKSHAP_TWO_CONES_BASE_TO_BASE
 *    EEC_TPMKSHAP_TWO_CONES_POINT_TO_POINT
 *    EEC_TPMKSHAP_TWO_CONES_POINTS_DOWNWARD
 *    EEC_TPMKSHAP_TWO_CONES_POINTS_UPWARD
 *    EEC_TPMKSHAP_TWO_SPHERES
 *    EEC_TPMKSHAP_X_SHAPED
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_TOPMARK_SHAPE ((EDCS_Attribute_Code)1450)

/*
 * Definition:
 *     The type of a <TOPMARK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TPMKTY_BALL
 *    EEC_TPMKTY_BALL_FILLED
 *    EEC_TPMKTY_BALL_OPEN
 *    EEC_TPMKTY_BALL_OVER_CONE
 *    EEC_TPMKTY_BROOM_POINT_DOWN
 *    EEC_TPMKTY_BROOM_POINT_UP
 *    EEC_TPMKTY_CAN
 *    EEC_TPMKTY_CAN_FILLED
 *    EEC_TPMKTY_CAN_OPEN
 *    EEC_TPMKTY_CAN_OVER_BALL_OPEN
 *    EEC_TPMKTY_CIRCLE
 *    EEC_TPMKTY_CIRCLE_OVER_TRIANGLE_POINT_UP
 *    EEC_TPMKTY_CONE_OVER_BALL
 *    EEC_TPMKTY_CONE_POINT_DOWNWARDS
 *    EEC_TPMKTY_CONE_POINT_UPWARDS
 *    EEC_TPMKTY_CROSS_OVER_BALL_FILLED
 *    EEC_TPMKTY_CROSS_OVER_BALL_OPEN
 *    EEC_TPMKTY_DIAMOND
 *    EEC_TPMKTY_DIAMOND_OVER_BALL_FILLED
 *    EEC_TPMKTY_DOUBLE_BALL_OPEN
 *    EEC_TPMKTY_DOUBLE_CONE_POINTS_APART
 *    EEC_TPMKTY_EAST_MARK
 *    EEC_TPMKTY_FLAG
 *    EEC_TPMKTY_ISOLATED_DANGER
 *    EEC_TPMKTY_NONE_PRESENT
 *    EEC_TPMKTY_NORTH_MARK
 *    EEC_TPMKTY_NUN
 *    EEC_TPMKTY_OPTICAL_REFLECTOR
 *    EEC_TPMKTY_OTHER_SHAPE
 *    EEC_TPMKTY_PERCH
 *    EEC_TPMKTY_PORT_HAND
 *    EEC_TPMKTY_RECTANGLE_HORIZONTAL
 *    EEC_TPMKTY_RECTANGLE_VERTICAL
 *    EEC_TPMKTY_RHOMBUS_OVER_CIRCLE
 *    EEC_TPMKTY_SAFE_WATER
 *    EEC_TPMKTY_SOUTH_MARK
 *    EEC_TPMKTY_SPECIAL_X
 *    EEC_TPMKTY_SPHERE_OVER_RHOMBUS
 *    EEC_TPMKTY_SQUARE
 *    EEC_TPMKTY_ST_ANDREWS_CROSS
 *    EEC_TPMKTY_STARBOARD_HAND
 *    EEC_TPMKTY_T_SHAPE
 *    EEC_TPMKTY_TRAPEZIUM_DOWN
 *    EEC_TPMKTY_TRAPEZIUM_UP
 *    EEC_TPMKTY_TRI_POINT_UP_OVER_CIRCLE
 *    EEC_TPMKTY_TRIANGLE_POINT_DOWN
 *    EEC_TPMKTY_TRIANGLE_POINT_UP
 *    EEC_TPMKTY_TWO_UPRIGHT_CROSSES
 *    EEC_TPMKTY_UPRIGHT_CROSS
 *    EEC_TPMKTY_UPRIGHT_CROSS_OVER_CIRCLE
 *    EEC_TPMKTY_WEST_MARK
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_TOPMARK_TYPE ((EDCS_Attribute_Code)1451)

/*
 * Definition:
 *     A category describing the <<TOTAL_CLOUD_COVERAGE>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TOTCLDCOVCAT_NONE_PRESENT
 *    EEC_TOTCLDCOVCAT_ONE_OKTA
 *    EEC_TOTCLDCOVCAT_TWO_OKTA
 *    EEC_TOTCLDCOVCAT_THREE_OKTA
 *    EEC_TOTCLDCOVCAT_FOUR_OKTA
 *    EEC_TOTCLDCOVCAT_FIVE_OKTA
 *    EEC_TOTCLDCOVCAT_SIX_OKTA
 *    EEC_TOTCLDCOVCAT_SEVEN_OKTA
 *    EEC_TOTCLDCOVCAT_EIGHT_OKTA
 *    EEC_TOTCLDCOVCAT_SKY_OBSCURED
 *    EEC_TOTCLDCOVCAT_PARTIAL_OBSCURATION
 *    EEC_TOTCLDCOVCAT_SCATTERED
 *    EEC_TOTCLDCOVCAT_BROKEN
 *    EEC_TOTCLDCOVCAT_FEW
 *    EEC_TOTCLDCOVCAT_INDISCERNABLE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_TOTAL_CLOUD_COVER_CATEGORY ((EDCS_Attribute_Code)1452)

/*
 * Definition:
 *     The fraction of the sky hidden by all <CLOUD>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_TOTAL_CLOUD_COVERAGE ((EDCS_Attribute_Code)1453)

/*
 * Definition:
 *     The maximum equivalent quantity of free electrons vertically above a
 *     <LOCATION>; the total electron count.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_TOTAL_ELECTRON_CONTENT ((EDCS_Attribute_Code)1454)

/*
 * Definition:
 *     The total depth of <SNOW_GROUND_COVER> and/or <ICE> on the <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, ICE, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_TOTAL_SNOW_ICE_DEPTH ((EDCS_Attribute_Code)1455)

/*
 * Definition:
 *     The depth of the liquid <WATER> that is equivalent in content to the
 *     <<TOTAL_SNOW_ICE_DEPTH>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DIMENSION, ICE, MATERIAL, SURFACE_MATERIAL
 */
#define EAC_TOTAL_SNOW_ICE_DEPTH_EQUIVALENT ((EDCS_Attribute_Code)1456)

/*
 * Definition:
 *     A touristic name for an <OBJECT> that exists in addition to a
 *     geographic name.
 *
 * Value Type: STRING
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_TOURISTIC_NAME ((EDCS_Attribute_Code)1457)

/*
 * Definition:
 *     The type of a <TOWED_VEHICLE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TOWEDVEHTY_CARGO_TRAILER
 *    EEC_TOWEDVEHTY_CHEMICAL_DECONTAMINATION_TRAILER
 *    EEC_TOWEDVEHTY_EQUIPMENT_TRANSPORT_TRAILER
 *    EEC_TOWEDVEHTY_FUEL_TRAILER
 *    EEC_TOWEDVEHTY_GENERATOR_TRAILER
 *    EEC_TOWEDVEHTY_LIMBER
 *    EEC_TOWEDVEHTY_MAINTENANCE_EQUIPMENT_TRAILER
 *    EEC_TOWEDVEHTY_WATER_TRAILER
 *
 * Group Membership: TRNSP, VEHICLE
 */
#define EAC_TOWED_VEHICLE_TYPE ((EDCS_Attribute_Code)1458)

/*
 * Definition:
 *     The purpose of a <TOWER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TOWERTY_BELL
 *    EEC_TOWERTY_BRIDGE
 *    EEC_TOWERTY_BROADCAST
 *    EEC_TOWERTY_CONTROL
 *    EEC_TOWERTY_COOLING
 *    EEC_TOWERTY_ELECTRICITY
 *    EEC_TOWERTY_FIRE
 *    EEC_TOWERTY_ILLUMINATION
 *    EEC_TOWERTY_LOOKOUT
 *    EEC_TOWERTY_LORAN
 *    EEC_TOWERTY_MICROWAVE
 *    EEC_TOWERTY_MOORING_ARTICULATED
 *    EEC_TOWERTY_MOORING
 *    EEC_TOWERTY_MULTIPLE_USE
 *    EEC_TOWERTY_OBSERVATION
 *    EEC_TOWERTY_POWER_TRANSMISSION_LINE_PYLON
 *    EEC_TOWERTY_RADAR
 *    EEC_TOWERTY_RADIO
 *    EEC_TOWERTY_RADIO_OR_TELEVISION
 *    EEC_TOWERTY_RECREATION
 *    EEC_TOWERTY_TELEVISION
 *    EEC_TOWERTY_WATCH
 *    EEC_TOWERTY_WATER
 *    EEC_TOWERTY_WIRELESS_RADIO
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_TOWER_TYPE ((EDCS_Attribute_Code)1459)

/*
 * Definition:
 *     The negative of the propagation range gradient of the ratio of
 *     transmitted to incident flux, generally expressed as a decibel power
 *     ratio per length of range of an <OBJECT>; the transmission
 *     attenuation gradient.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_LEN_GRADIENT
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_TRANSMISSION_ATTENUATION_GRADIENT ((EDCS_Attribute_Code)1460)

/*
 * Definition:
 *     The negative of the ratio of energy density at an end <LOCATION> to
 *     that at a starting <LOCATION>, generally expressed in decibels; the
 *     transmission loss.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: FIELD_OR_POWER_LEVEL_DIFF
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_TRANSMISSION_LOSS ((EDCS_Attribute_Code)1461)

/*
 * Definition:
 *     The ratio of transmitted to incident flux from one traversal through a
 *     homogeneous <MATERIAL> or <OBJECT>; the transmissivity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL, RATE_OR_RATIO
 */
#define EAC_TRANSMISSIVITY ((EDCS_Attribute_Code)1462)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_GEODETIC>> toward which light is transmitted (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_TRANSMITTED_AZIMUTH_GEODETIC ((EDCS_Attribute_Code)1463)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_LOCAL>> toward which light is transmitted (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_TRANSMITTED_AZIMUTH_LOCAL ((EDCS_Attribute_Code)1464)

/*
 * Definition:
 *     The <<VECTOR_AZIMUTH_MAGNETIC>> toward which light is transmitted (the
 *     <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_TRANSMITTED_AZIMUTH_MAGNETIC ((EDCS_Attribute_Code)1465)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_HORIZONTAL>> toward which light is transmitted
 *     (the <DIRECTION> of the Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_TRANSMITTED_ELEV_ANGLE_HORIZONTAL ((EDCS_Attribute_Code)1466)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_LOCAL>> of the transmitted light <DIRECTION>
 *     vector (unit Poynting vector).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, EM_PHENOMENON, LIGHTING_AND_VISIBILITY
 */
#define EAC_TRANSMITTED_ELEV_ANGLE_LOCAL ((EDCS_Attribute_Code)1467)

/*
 * Definition:
 *     The capacity of a <VEHICLE> for the transport and/or storage of
 *     <CARGO>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MASS
 *
 * Group Membership: TRNSP, VEHICLE
 */
#define EAC_TRANSPORT_CAPACITY ((EDCS_Attribute_Code)1468)

/*
 * Definition:
 *     The design series of a <TRANSPORT_HELICOPTER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TRNPHELOTY_AH_6J
 *    EEC_TRNPHELOTY_CH_3
 *    EEC_TRNPHELOTY_CH_46
 *    EEC_TRNPHELOTY_CH_47
 *    EEC_TRNPHELOTY_CH_47A
 *    EEC_TRNPHELOTY_CH_47B
 *    EEC_TRNPHELOTY_CH_47C
 *    EEC_TRNPHELOTY_CH_47D
 *    EEC_TRNPHELOTY_CH_53
 *    EEC_TRNPHELOTY_HH_65
 *    EEC_TRNPHELOTY_OH_58
 *    EEC_TRNPHELOTY_OH_6A
 *    EEC_TRNPHELOTY_SH_2
 *    EEC_TRNPHELOTY_SH_3
 *    EEC_TRNPHELOTY_SH_60
 *    EEC_TRNPHELOTY_TH_57
 *    EEC_TRNPHELOTY_TH_6
 *    EEC_TRNPHELOTY_UH_1
 *    EEC_TRNPHELOTY_UH_60
 *    EEC_TRNPHELOTY_V_22
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define EAC_TRANSPORT_HELICOPTER_TYPE ((EDCS_Attribute_Code)1469)

/*
 * Definition:
 *     The type of a <LANDING_CRAFT> designed for transport dock operations.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TRNPLNDGCRFTTY_TAI_WU_CLASS_TRANSPORT_DOCK
 *    EEC_TRNPLNDGCRFTTY_WU_KANG_CLASS_TRANSPORT_DOCK
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_TRANSPORT_LANDING_CRAFT_TYPE ((EDCS_Attribute_Code)1470)

/*
 * Definition:
 *     The type of a <TRANSPORT_WINGED_AIRCRAFT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TRNPWNGARCRFTY_B707_KC137_SERIES
 *    EEC_TRNPWNGARCRFTY_B707_T17_SERIES
 *    EEC_TRNPWNGARCRFTY_B707_TANKER_SERIES
 *    EEC_TRNPWNGARCRFTY_B707_TRANSPORT_SERIES
 *    EEC_TRNPWNGARCRFTY_KA6D_INTRUDER_SERIES
 *    EEC_TRNPWNGARCRFTY_KC10_EXTENDER_SERIES
 *    EEC_TRNPWNGARCRFTY_KC130_MODEL_382_HERCULES_SERIES_TRANSPORT
 *    EEC_TRNPWNGARCRFTY_KC130H_MODEL_382_HERCULES_SERIES_TRANSPORT
 *    EEC_TRNPWNGARCRFTY_KC135_STRATOTANKER_SERIES
 *    EEC_TRNPWNGARCRFTY_KC135E_STRATOTANKER_SERIES
 *    EEC_TRNPWNGARCRFTY_KC135R_STRATOTANKER_SERIES
 *    EEC_TRNPWNGARCRFTY_L1011_SERIES_TANKER_TRANSPORT
 *    EEC_TRNPWNGARCRFTY_VC10_SERIES_TANKER_TRANSPORT
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define EAC_TRANSPORT_WINGED_AIRCRAFT_TYPE ((EDCS_Attribute_Code)1471)

/*
 * Definition:
 *     The <<HEIGHT>> of the bed of a <LAND_TRANSPORTATION_ROUTE> above the
 *     surrounding <TERRAIN>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LAND_TRNSP, LOCATION, TRNSP
 */
#define EAC_TRANSPORTATION_BED_HEIGHT ((EDCS_Attribute_Code)1472)

/*
 * Definition:
 *     The total distance along a <TRANSPORTATION_ROUTE> between two
 *     <LOCATION>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, TRNSP
 */
#define EAC_TRANSPORTATION_ROUTE_LENGTH ((EDCS_Attribute_Code)1473)

/*
 * Definition:
 *     The type of primary user, function, or authority of a transportation
 *     <SYSTEM>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TRNSPUSE_ACCESS_ROAD
 *    EEC_TRNSPUSE_AIR
 *    EEC_TRNSPUSE_AIR_TRAFFIC_CONTROL
 *    EEC_TRNSPUSE_AIRCRAFT
 *    EEC_TRNSPUSE_AQUEDUCT
 *    EEC_TRNSPUSE_AUTOMOTIVE
 *    EEC_TRNSPUSE_BICYCLE
 *    EEC_TRNSPUSE_BOAT
 *    EEC_TRNSPUSE_BUS
 *    EEC_TRNSPUSE_CANAL
 *    EEC_TRNSPUSE_CARAVAN_ROUTE
 *    EEC_TRNSPUSE_CHAIR_LIFT
 *    EEC_TRNSPUSE_HIGHWAY
 *    EEC_TRNSPUSE_INDUSTRIAL_VESSEL
 *    EEC_TRNSPUSE_MARINE
 *    EEC_TRNSPUSE_MINERALS
 *    EEC_TRNSPUSE_MOTORCYCLE
 *    EEC_TRNSPUSE_NO_TRANSPORT_USE
 *    EEC_TRNSPUSE_NON_HUMAN_ANIMAL
 *    EEC_TRNSPUSE_PASSENGER
 *    EEC_TRNSPUSE_PATH
 *    EEC_TRNSPUSE_PEDESTRIAN
 *    EEC_TRNSPUSE_PIPELINE
 *    EEC_TRNSPUSE_PORTAGE
 *    EEC_TRNSPUSE_RAILWAY
 *    EEC_TRNSPUSE_ROAD
 *    EEC_TRNSPUSE_ROAD_AND_RAILWAY
 *    EEC_TRNSPUSE_ROAD_AND_RUNWAY
 *    EEC_TRNSPUSE_SHIP
 *    EEC_TRNSPUSE_SHIPPING_LANE
 *    EEC_TRNSPUSE_SKI_TOW
 *    EEC_TRNSPUSE_SLEIGH_TOW
 *    EEC_TRNSPUSE_SLIP_OR_ACCESS_ROAD
 *    EEC_TRNSPUSE_SLIP_ROAD
 *    EEC_TRNSPUSE_STREET
 *    EEC_TRNSPUSE_SUBWAY
 *    EEC_TRNSPUSE_THROUGH_ROUTE
 *    EEC_TRNSPUSE_TOW_PATH
 *    EEC_TRNSPUSE_UTILITY
 *    EEC_TRNSPUSE_VEHICLE_AND_PEDESTRIAN
 *    EEC_TRNSPUSE_WATERWAY
 *
 * Group Membership: ADMINISTRATION, TRNSP
 */
#define EAC_TRANSPORTATION_USE ((EDCS_Attribute_Code)1474)

/*
 * Definition:
 *     The <<HEIGHT_AGL>> to the lowest significant canopy branch of the
 *     bottom of the canopy of a <TREE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIVING_ORGANISM, PLANT
 */
#define EAC_TREE_CANOPY_BOTTOM_HEIGHT ((EDCS_Attribute_Code)1475)

/*
 * Definition:
 *     The number of levels of canopy in a <TREED_TRACT> or <FOREST>; the
 *     tree canopy level count.
 *
 * Value Type: COUNT
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define EAC_TREE_CANOPY_LEVEL_COUNT ((EDCS_Attribute_Code)1476)

/*
 * Definition:
 *     The number of <TREE>s; the tree count.
 *
 * Value Type: COUNT
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define EAC_TREE_COUNT ((EDCS_Attribute_Code)1477)

/*
 * Definition:
 *     The mean distance between centres of adjacent <TREE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIVING_ORGANISM, PLANT
 */
#define EAC_TREE_SPACING ((EDCS_Attribute_Code)1478)

/*
 * Definition:
 *     The type of a <NON_EMPTY_SET> of <TREE>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TREETY_DECIDUOUS
 *    EEC_TREETY_EVERGREEN
 *    EEC_TREETY_MIXED
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define EAC_TREE_TYPE ((EDCS_Attribute_Code)1479)

/*
 * Definition:
 *     The <<ALTITUDE_MSL>> of the <TROPOPAUSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, LOCATION
 */
#define EAC_TROPOPAUSE_ALTITUDE ((EDCS_Attribute_Code)1480)

/*
 * Definition:
 *     An indication that the <TROPOPAUSE> is present.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, TEMPERATURE
 */
#define EAC_TROPOPAUSE_PRESENT ((EDCS_Attribute_Code)1481)

/*
 * Definition:
 *     The <<ATM_PRESSURE>> at the <TROPOPAUSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE, DEMARCATION
 */
#define EAC_TROPOPAUSE_PRESSURE ((EDCS_Attribute_Code)1482)

/*
 * Definition:
 *     The <<AIR_TEMPERATURE>> at the <TROPOPAUSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, TEMPERATURE
 */
#define EAC_TROPOPAUSE_TEMPERATURE ((EDCS_Attribute_Code)1483)

/*
 * Definition:
 *     The load class of a <TRUCK>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TRUCKLOADCLS_HEAVY
 *    EEC_TRUCKLOADCLS_LIGHT
 *    EEC_TRUCKLOADCLS_MEDIUM
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define EAC_TRUCK_LOAD_CLASS ((EDCS_Attribute_Code)1484)

/*
 * Definition:
 *     An indication that a marine <TSS_SYSTEM> has been adopted by the IMO.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_TSS_IMO_ADOPTED ((EDCS_Attribute_Code)1485)

/*
 * Definition:
 *     The characteristic cross-sectional shape of a <TUNNEL> when viewed
 *     from the ends.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TNLXSECT_ARCH
 *    EEC_TNLXSECT_BOX
 *    EEC_TNLXSECT_CIRCULAR
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_TUNNEL_CROSS_SECTION ((EDCS_Attribute_Code)1486)

/*
 * Definition:
 *     An indication that information is known about the <<HEIGHT>> to which
 *     a <MARINE_OBJECT> may be uncovered by the <TIDE>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define EAC_UNCOVERING_HEIGHT_KNOWN ((EDCS_Attribute_Code)1487)

/*
 * Definition:
 *     The clearance below a <BRIDGE> measured from the lowest level of the
 *     bridged <SURFACE> to the base of the lower of either a cross beam or
 *     lowest deck of the <BRIDGE>; the underbridge clearance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_UNDERBRIDGE_CLEARANCE ((EDCS_Attribute_Code)1488)

/*
 * Definition:
 *     The characteristics of the composition of the <MATERIAL> underlying
 *     the <SURFACE> of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_UNDRMATCHR_BROKEN
 *    EEC_UNDRMATCHR_CALCAREOUS
 *    EEC_UNDRMATCHR_COARSE
 *    EEC_UNDRMATCHR_DECAYED
 *    EEC_UNDRMATCHR_FINE_PARTICLES
 *    EEC_UNDRMATCHR_FLINTY
 *    EEC_UNDRMATCHR_GLACIAL
 *    EEC_UNDRMATCHR_GRITTY
 *    EEC_UNDRMATCHR_GROUND
 *    EEC_UNDRMATCHR_HARD
 *    EEC_UNDRMATCHR_LARGE_PARTICLES
 *    EEC_UNDRMATCHR_MASONRY
 *    EEC_UNDRMATCHR_MEDIUM_PARTICLES
 *    EEC_UNDRMATCHR_ROCKY
 *    EEC_UNDRMATCHR_ROTTEN
 *    EEC_UNDRMATCHR_SMALL_PARTICLES
 *    EEC_UNDRMATCHR_SOFT
 *    EEC_UNDRMATCHR_SPECKLED
 *    EEC_UNDRMATCHR_STICKY
 *    EEC_UNDRMATCHR_STIFF
 *    EEC_UNDRMATCHR_STREAKY
 *    EEC_UNDRMATCHR_TENACIOUS
 *    EEC_UNDRMATCHR_UNEVEN
 *    EEC_UNDRMATCHR_VARIED
 *    EEC_UNDRMATCHR_VOLCANIC
 *
 * Group Membership: MATERIAL
 */
#define EAC_UNDERLYING_MATERIAL_CHARACTERISTIC ((EDCS_Attribute_Code)1489)

/*
 * Definition:
 *     The type of composition of the <MATERIAL> underlying the <SURFACE> of
 *     an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_UNDRMATTY_ASH
 *    EEC_UNDRMATTY_BOULDER
 *    EEC_UNDRMATTY_CHALK
 *    EEC_UNDRMATTY_CINDER
 *    EEC_UNDRMATTY_CIRRIPEDIA
 *    EEC_UNDRMATTY_CLAY
 *    EEC_UNDRMATTY_COBBLE
 *    EEC_UNDRMATTY_CORAL
 *    EEC_UNDRMATTY_CORAL_HEAD
 *    EEC_UNDRMATTY_DIATOMACEOUS_EARTH
 *    EEC_UNDRMATTY_EVAPORITE
 *    EEC_UNDRMATTY_FORAMINIFERA
 *    EEC_UNDRMATTY_FUCUS
 *    EEC_UNDRMATTY_GLASS_REINFORCED_PLASTIC
 *    EEC_UNDRMATTY_GLOBIGERINA
 *    EEC_UNDRMATTY_GRASS
 *    EEC_UNDRMATTY_GRAVEL
 *    EEC_UNDRMATTY_GROUND
 *    EEC_UNDRMATTY_LAVA
 *    EEC_UNDRMATTY_MADREPORE
 *    EEC_UNDRMATTY_MANGANESE
 *    EEC_UNDRMATTY_MARL
 *    EEC_UNDRMATTY_MATTE
 *    EEC_UNDRMATTY_MUD
 *    EEC_UNDRMATTY_MUSSEL
 *    EEC_UNDRMATTY_OOZE
 *    EEC_UNDRMATTY_OYSTER
 *    EEC_UNDRMATTY_PEBBLE
 *    EEC_UNDRMATTY_PLANT_MATERIAL
 *    EEC_UNDRMATTY_POLYZOA
 *    EEC_UNDRMATTY_PTEROPOD
 *    EEC_UNDRMATTY_PUMICE
 *    EEC_UNDRMATTY_QUARTZ
 *    EEC_UNDRMATTY_RADIOLARIAN
 *    EEC_UNDRMATTY_ROCK
 *    EEC_UNDRMATTY_SAND
 *    EEC_UNDRMATTY_SCHIST
 *    EEC_UNDRMATTY_SCORIA
 *    EEC_UNDRMATTY_SEA_TANGLE
 *    EEC_UNDRMATTY_SEAWEED
 *    EEC_UNDRMATTY_SHELL
 *    EEC_UNDRMATTY_SHINGLE
 *    EEC_UNDRMATTY_SILT
 *    EEC_UNDRMATTY_SPICULE
 *    EEC_UNDRMATTY_SPONGE
 *    EEC_UNDRMATTY_STONE
 *    EEC_UNDRMATTY_THATCH
 *    EEC_UNDRMATTY_TUFA
 *    EEC_UNDRMATTY_URANIUM
 *    EEC_UNDRMATTY_VEGETATION_PRODUCT
 *    EEC_UNDRMATTY_VOLCANIC
 *    EEC_UNDRMATTY_VOLCANIC_ASH
 *    EEC_UNDRMATTY_WATER
 *    EEC_UNDRMATTY_WOOD
 *    EEC_UNDRMATTY_ZINC
 *
 * Group Membership: MATERIAL
 */
#define EAC_UNDERLYING_MATERIAL_TYPE ((EDCS_Attribute_Code)1490)

/*
 * Definition:
 *     The height of an <OBJECT> above a <WATERCOURSE> measured on the
 *     upstream side.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define EAC_UPSTREAM_HEIGHT ((EDCS_Attribute_Code)1491)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the <LIGHTING> on an urban <BUILDING>. Zero
 *     means unlit and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_URBAN_BUILDING_LIGHTING_INTENSITY ((EDCS_Attribute_Code)1492)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional intensity of the <LIGHTING> on an urban <STREET>. Zero
 *     means unlit and one means maximum intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LAND_TRNSP, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO, TRNSP, USAGE_REGION
 */
#define EAC_URBAN_STREET_LIGHTING_INTENSITY ((EDCS_Attribute_Code)1493)

/*
 * Definition:
 *     The predominant geometric configuration of <STREET>s found within a
 *     delineated <TERRAIN_SURFACE_REGION>; urban street pattern.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_URBSTREETPAT_CURVILINEAR_CLUSTER
 *    EEC_URBSTREETPAT_IRREG_GRID
 *    EEC_URBSTREETPAT_IRREG_RADIAL
 *    EEC_URBSTREETPAT_LINEAR_STRIP
 *    EEC_URBSTREETPAT_MIXED_CLUSTER
 *    EEC_URBSTREETPAT_MIXED_GRID
 *    EEC_URBSTREETPAT_MIXED_RADIAL
 *    EEC_URBSTREETPAT_REG_GRID
 *    EEC_URBSTREETPAT_REG_RADIAL
 *
 * Group Membership: LAND_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_URBAN_STREET_PATTERN ((EDCS_Attribute_Code)1494)

/*
 * Definition:
 *     The type of an urban terrain zone based on the characterization of
 *     <BUILDING>s and their density.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_URBTERZNTY_ATTACHED_1
 *    EEC_URBTERZNTY_ATTACHED_2
 *    EEC_URBTERZNTY_ATTACHED_3
 *    EEC_URBTERZNTY_ATTACHED_4
 *    EEC_URBTERZNTY_ATTACHED_5
 *    EEC_URBTERZNTY_ATTACHED_6
 *    EEC_URBTERZNTY_ATTACHED_BUILDINGS
 *    EEC_URBTERZNTY_CLOSE_SET_BUILDINGS
 *    EEC_URBTERZNTY_DISCRETE_CLUST_1
 *    EEC_URBTERZNTY_DISCRETE_CLUST_2
 *    EEC_URBTERZNTY_DISCRETE_CLUST_3
 *    EEC_URBTERZNTY_DISCRETE_CLUST_4
 *    EEC_URBTERZNTY_DISCRETE_CLUST_5
 *    EEC_URBTERZNTY_DISCRETE_CLUST_6
 *    EEC_URBTERZNTY_DISCRETE_CLUST_8
 *    EEC_URBTERZNTY_DISCRETE_OPEN_1
 *    EEC_URBTERZNTY_DISCRETE_OPEN_2
 *    EEC_URBTERZNTY_DISCRETE_OPEN_3
 *    EEC_URBTERZNTY_DISCRETE_OPEN_4
 *    EEC_URBTERZNTY_DISCRETE_OPEN_5
 *    EEC_URBTERZNTY_DISCRETE_OPEN_6
 *    EEC_URBTERZNTY_DOES_NOT_CONFORM
 *    EEC_URBTERZNTY_WIDELY_SPACED_BUILDINGS
 *
 * Group Membership: USAGE_REGION
 */
#define EAC_URBAN_TERRAIN_ZONE_TYPE ((EDCS_Attribute_Code)1495)

/*
 * Definition:
 *     The usable <<LENGTH>> of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_USABLE_LENGTH ((EDCS_Attribute_Code)1496)

/*
 * Definition:
 *     The primary user, function, or controlling authority of an <OBJECT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_USAGE_ADVERTISING_BILLBOARD
 *    EEC_USAGE_AERODROME_TERMINAL
 *    EEC_USAGE_AGRICULTURE
 *    EEC_USAGE_AID_TO_NAVIGATION_CHANGEOVER
 *    EEC_USAGE_AIRCRAFT_CONTROL
 *    EEC_USAGE_AIRCRAFT_FACILITY
 *    EEC_USAGE_AIRCRAFT_HANGAR_APRON
 *    EEC_USAGE_ALERT_APRON_OR_HARDSTAND
 *    EEC_USAGE_ALTERNATE_ENTRY
 *    EEC_USAGE_ALTERNATE_ENTRY_OR_EXIT
 *    EEC_USAGE_ALTERNATE_EXIT
 *    EEC_USAGE_ALTIMETER_CHANGE
 *    EEC_USAGE_ANCHOR_POINT
 *    EEC_USAGE_ANIMAL_SANCTUARY
 *    EEC_USAGE_APARTMENT
 *    EEC_USAGE_ARCP
 *    EEC_USAGE_ARIP
 *    EEC_USAGE_AS_FILL
 *    EEC_USAGE_AVALANCHE
 *    EEC_USAGE_BASE_FLIGHT_APRON
 *    EEC_USAGE_BUTTS
 *    EEC_USAGE_CABLE_PIPE_SIGN
 *    EEC_USAGE_CAUSEWAY
 *    EEC_USAGE_CITY
 *    EEC_USAGE_CLOCK
 *    EEC_USAGE_CLOSED
 *    EEC_USAGE_COMMERCE
 *    EEC_USAGE_COMMERCE_OR_RECREATION
 *    EEC_USAGE_COMMUNAL
 *    EEC_USAGE_COMMUNICATION
 *    EEC_USAGE_COMPASS_ADJUSTMENT
 *    EEC_USAGE_COMPASS_ROSE_HARDSTAND
 *    EEC_USAGE_COMPULSORY_REPORT_POINTS
 *    EEC_USAGE_CONTAINER
 *    EEC_USAGE_DECOY
 *    EEC_USAGE_DEPOT_APRON
 *    EEC_USAGE_DISPERSAL_HARDSTAND
 *    EEC_USAGE_DRAG_STRIP
 *    EEC_USAGE_DRINKING_WATER
 *    EEC_USAGE_DUGOUT
 *    EEC_USAGE_DYKE
 *    EEC_USAGE_ENGINE_RUN_UP_HARDSTAND
 *    EEC_USAGE_ENGINE_TEST_PAD
 *    EEC_USAGE_ENTRY
 *    EEC_USAGE_ENTRY_OR_STARTING
 *    EEC_USAGE_EXIT
 *    EEC_USAGE_EXIT_OR_END
 *    EEC_USAGE_FEDERAL
 *    EEC_USAGE_FEEDER
 *    EEC_USAGE_FILL
 *    EEC_USAGE_FILTRATION_POND
 *    EEC_USAGE_FINAL_APPROACH_FIX
 *    EEC_USAGE_FIREBREAK
 *    EEC_USAGE_FIRING_IN_HARDSTAND
 *    EEC_USAGE_FLOOD_BARRAGE
 *    EEC_USAGE_FLOOD_CONTROL
 *    EEC_USAGE_FOREST_PRESERVE
 *    EEC_USAGE_GOVERNMENT
 *    EEC_USAGE_GOVERNMENT_OR_INSTITUTION
 *    EEC_USAGE_HIGH_ALTITUDE_ENROUTE
 *    EEC_USAGE_HIGHWAY_SIGN
 *    EEC_USAGE_HOTEL
 *    EEC_USAGE_INDIGENOUS_BURIAL_GROUND
 *    EEC_USAGE_INDUSTRY
 *    EEC_USAGE_INITIAL_APPROACH_FIX
 *    EEC_USAGE_INSTITUTION
 *    EEC_USAGE_INSULAR
 *    EEC_USAGE_INTAKE
 *    EEC_USAGE_INTERNATIONAL
 *    EEC_USAGE_INTERSTATE
 *    EEC_USAGE_IRRIGATION
 *    EEC_USAGE_JOINT
 *    EEC_USAGE_LEVEE
 *    EEC_USAGE_LEVEE_OR_DYKE
 *    EEC_USAGE_LIMITED
 *    EEC_USAGE_LOW_ALTITUDE_ENROUTE
 *    EEC_USAGE_LOW_HIGH_ALTITUDE_ENROUTE
 *    EEC_USAGE_MAINTENANCE_HARDSTAND
 *    EEC_USAGE_MANDATORY
 *    EEC_USAGE_MARINE
 *    EEC_USAGE_MARINE_STATION
 *    EEC_USAGE_MEDICAL
 *    EEC_USAGE_MILEAGE_BREAK_DOWN
 *    EEC_USAGE_MILITARY
 *    EEC_USAGE_MILITARY_DISTRICT
 *    EEC_USAGE_MINING
 *    EEC_USAGE_MISSED_APPROACH_POINT
 *    EEC_USAGE_MIXED_URBAN
 *    EEC_USAGE_MOTEL
 *    EEC_USAGE_NATIONAL
 *    EEC_USAGE_NATIONAL_SUBDIVISION
 *    EEC_USAGE_NAVIGATION_CHECK_POINT
 *    EEC_USAGE_NOMAD
 *    EEC_USAGE_NON_COMPULSORY_REPORT_POINTS
 *    EEC_USAGE_NON_MILITARY
 *    EEC_USAGE_NON_PRECISION_INSTRUMENT_APPROACH
 *    EEC_USAGE_OIL_EXPLORATION
 *    EEC_USAGE_OPEN
 *    EEC_USAGE_OPERATIONAL_APRON
 *    EEC_USAGE_OUTFALL
 *    EEC_USAGE_PAD_HARDSTAND
 *    EEC_USAGE_PARKING_HARDSTAND
 *    EEC_USAGE_POWER
 *    EEC_USAGE_PRECISION_INSTRUMENT_APPROACH
 *    EEC_USAGE_PRIMARY
 *    EEC_USAGE_PRISONER
 *    EEC_USAGE_PRIVATE
 *    EEC_USAGE_PROHIBITED_AREA
 *    EEC_USAGE_PROVINCIAL
 *    EEC_USAGE_PUBLIC
 *    EEC_USAGE_QUATERNARY
 *    EEC_USAGE_QUINTARY
 *    EEC_USAGE_RADAR
 *    EEC_USAGE_RECREATION
 *    EEC_USAGE_RECREATION_OR_INDUSTRY
 *    EEC_USAGE_REFUELLING_HARDSTAND
 *    EEC_USAGE_REFUGEE
 *    EEC_USAGE_REGIONAL
 *    EEC_USAGE_RESERVE
 *    EEC_USAGE_RESERVED
 *    EEC_USAGE_RESIDENCE
 *    EEC_USAGE_RESIDENCE_OR_AGRICULTURE
 *    EEC_USAGE_RESTRICTED
 *    EEC_USAGE_RETAIL
 *    EEC_USAGE_RETAINING
 *    EEC_USAGE_ROCK_SHED
 *    EEC_USAGE_SCHOOL
 *    EEC_USAGE_SCOREBOARD
 *    EEC_USAGE_SEAPLANE_RUN
 *    EEC_USAGE_SECONDARY
 *    EEC_USAGE_SINGLE_POINT_MOORING
 *    EEC_USAGE_SNOW_SHED
 *    EEC_USAGE_STATE
 *    EEC_USAGE_STOL_APPROACH
 *    EEC_USAGE_STUB_APRON
 *    EEC_USAGE_TELEGRAPH
 *    EEC_USAGE_TELEPHONE
 *    EEC_USAGE_TEMPORARY_RESIDENCE
 *    EEC_USAGE_TERMINUS
 *    EEC_USAGE_TERMINUS_OR_TERMINAL
 *    EEC_USAGE_TERTIARY
 *    EEC_USAGE_TIMEBALL
 *    EEC_USAGE_TOURIST
 *    EEC_USAGE_TRANSACTION
 *    EEC_USAGE_TRANSIENT_APRON
 *    EEC_USAGE_TRANSPORTATION
 *    EEC_USAGE_TRIANGULATION
 *    EEC_USAGE_TRIBAL
 *    EEC_USAGE_TURNING
 *    EEC_USAGE_UNIDENTIFIED_AIRSTRIP
 *    EEC_USAGE_UNPOPULATED
 *    EEC_USAGE_UTILITY_OR_COMMUNICATION
 *    EEC_USAGE_VESSEL_BERTH
 *    EEC_USAGE_VISUAL_APPROACH
 *    EEC_USAGE_VISUAL_DESCENT_POINT
 *
 * Group Membership: ABSTRACT_OBJECT, ADMINISTRATION, USAGE_REGION
 */
#define EAC_USAGE ((EDCS_Attribute_Code)1497)

/*
 * Definition:
 *     The type of a <FACILITY> that is primarily used for utility provision
 *     purposes.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_UTILUSE_DRINKING_WATER
 *    EEC_UTILUSE_OUTBUILDING
 *    EEC_UTILUSE_OUTFALL
 *    EEC_UTILUSE_POWER
 *    EEC_UTILUSE_TELEGRAPH
 *    EEC_UTILUSE_TELEPHONE
 *    EEC_UTILUSE_TRIANGULATION
 *    EEC_UTILUSE_UTILITY_COMMUNICATION
 *    EEC_UTILUSE_WATER_INTAKE
 *    EEC_UTILUSE_WASTE_PROCESSING
 *    EEC_UTILUSE_WATER_TREATMENT
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_UTILITY_USE ((EDCS_Attribute_Code)1498)

/*
 * Definition:
 *     A number between 0 and 1 representing the linearly-scaled fraction of
 *     <<SEA_STATE_CATEGORY>> reports indicating varying
 *     <<SEA_STATE_CATEGORY>>; the variable sea state fraction.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_VARIABLE_SEA_STATE_FRACTION ((EDCS_Attribute_Code)1499)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the ending extreme in <<WIND_DIRECTION>>
 *     under variable <<WIND_DIRECTION>> conditions. Variable wind end
 *     direction is normally only reported for <<WIND_SPEED>>s exceeding
 *     3,09 metres per second (six knots) and the variability must equal or
 *     exceed a range of 60 arc degrees during the preceding two minutes.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, ATMOSPHERE
 */
#define EAC_VARIABLE_WIND_END_DIRECTION ((EDCS_Attribute_Code)1500)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the starting extreme in <<WIND_DIRECTION>>
 *     under variable <<WIND_DIRECTION>> conditions. Variable wind start
 *     direction is normally only reported for <<WIND_SPEED>>s exceeding
 *     3,09 metres per second (six knots) and the variability must equal or
 *     exceed a range of 60 arc degrees during the preceding two minutes.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, ATMOSPHERE
 */
#define EAC_VARIABLE_WIND_START_DIRECTION ((EDCS_Attribute_Code)1501)

/*
 * Definition:
 *     The smallest angle from vector A to vector B where A is a particular
 *     reference vector fixed in the local x-y plane, perpendicular to the
 *     local normal and defined by the projection onto this plane of the
 *     vector toward geodetic north and B is the projection onto the surface
 *     plane of the vector of interest. The positive sense is clockwise when
 *     looking in the <DIRECTION> of the cross product AxB.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_VECTOR_AZIMUTH_GEODETIC ((EDCS_Attribute_Code)1502)

/*
 * Definition:
 *     The smallest angle from vector A to vector B where A is the local
 *     x-axis fixed in the local x-y plane, perpendicular to the local
 *     normal) and B is the projection onto the surface plane of the vector
 *     of interest. The positive sense is clockwise when looking in the
 *     <DIRECTION> of the cross product AxB.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_VECTOR_AZIMUTH_LOCAL ((EDCS_Attribute_Code)1503)

/*
 * Definition:
 *     The smallest angle from vector A to vector B where A is the reference
 *     vector with origin in the local x-y plane, perpendicular to the local
 *     normal, and defined by the projection onto this plane of the vector
 *     toward magnetic north and B is the projection onto the surface plane
 *     of the vector of interest. The positive sense is clockwise when
 *     looking in the <DIRECTION> of the cross product AxB.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_VECTOR_AZIMUTH_MAGNETIC ((EDCS_Attribute_Code)1504)

/*
 * Definition:
 *     The <<VECTOR_ELEV_ANGLE_LOCAL>> with respect to the local x-y plane,
 *     perpendicular to the local normal.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_VECTOR_ELEV_ANGLE_HORIZONTAL ((EDCS_Attribute_Code)1505)

/*
 * Definition:
 *     The smallest angle from vector A to vector B where B is the vector of
 *     interest and A is the projection of B on the local x-y plane,
 *     perpendicular to the local normal; the elevation angle. The positive
 *     sense is clockwise when looking in the <DIRECTION> of the cross
 *     product AxB.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE
 */
#define EAC_VECTOR_ELEV_ANGLE_LOCAL ((EDCS_Attribute_Code)1506)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional restriction of the <<SPEED>> of ground <GROUND_VEHICLE>s
 *     as a fraction of maximum speed. Zero means no restriction (maximum
 *     speed) and one means completely restricted and immobilized.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LAND_TRNSP, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_VEGETATION_RESTRICTED_SPEED ((EDCS_Attribute_Code)1507)

/*
 * Definition:
 *     The type of <VEGETATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VEGTY_AGRI_SCATTERED_FORESTS
 *    EEC_VEGTY_AGRI_SCATTERED_TREES
 *    EEC_VEGTY_ALMOND
 *    EEC_VEGTY_ALPINE_TUNDRA
 *    EEC_VEGTY_APPLE
 *    EEC_VEGTY_ARTEMISIA
 *    EEC_VEGTY_ASH
 *    EEC_VEGTY_BAMBOO
 *    EEC_VEGTY_BEECH
 *    EEC_VEGTY_BIRCH
 *    EEC_VEGTY_BLACK_SPRUCE
 *    EEC_VEGTY_BOG
 *    EEC_VEGTY_BRUSHLAND_MEDIUM_TO_DENSE
 *    EEC_VEGTY_BRUSHLAND_OPEN_TO_MEDIUM
 *    EEC_VEGTY_CAROB
 *    EEC_VEGTY_CASUARINA
 *    EEC_VEGTY_CHESTNUT
 *    EEC_VEGTY_CITRUS
 *    EEC_VEGTY_CONIFER
 *    EEC_VEGTY_CORK_OAK
 *    EEC_VEGTY_CRANBERRY
 *    EEC_VEGTY_CYPRESS
 *    EEC_VEGTY_DECIDUOUS_UNSPECIFIED
 *    EEC_VEGTY_DRY_CROPS
 *    EEC_VEGTY_ELM
 *    EEC_VEGTY_EUCALYPTUS
 *    EEC_VEGTY_EVERGREEN_UNSPECIFIED
 *    EEC_VEGTY_FILAO
 *    EEC_VEGTY_FIR
 *    EEC_VEGTY_FOREST_CLEARING
 *    EEC_VEGTY_GARDEN
 *    EEC_VEGTY_GRASS
 *    EEC_VEGTY_GRASS_LAND
 *    EEC_VEGTY_GRASS_LAND_SCATTERED_TREES
 *    EEC_VEGTY_GROVE
 *    EEC_VEGTY_HARDWOOD
 *    EEC_VEGTY_HAZEL
 *    EEC_VEGTY_HEATH
 *    EEC_VEGTY_ILEX
 *    EEC_VEGTY_JOSHUA_TREE
 *    EEC_VEGTY_KELP
 *    EEC_VEGTY_LARCH
 *    EEC_VEGTY_MAIZE
 *    EEC_VEGTY_MANGROVE
 *    EEC_VEGTY_MAPLE
 *    EEC_VEGTY_MARSH
 *    EEC_VEGTY_MIXED_CROPS
 *    EEC_VEGTY_MIXED_DECIDUOUS
 *    EEC_VEGTY_MIXED_TREES
 *    EEC_VEGTY_MOSS
 *    EEC_VEGTY_MOUNTAIN_BIRCH
 *    EEC_VEGTY_NIPA_PALM
 *    EEC_VEGTY_NON_TREED
 *    EEC_VEGTY_OAK
 *    EEC_VEGTY_OLIVE
 *    EEC_VEGTY_PALM
 *    EEC_VEGTY_PEACH
 *    EEC_VEGTY_PEAT
 *    EEC_VEGTY_PINE
 *    EEC_VEGTY_POPLAR
 *    EEC_VEGTY_REED
 *    EEC_VEGTY_RHANTERIUM
 *    EEC_VEGTY_RICE_FIELD
 *    EEC_VEGTY_SARGASSUM
 *    EEC_VEGTY_SEA_GRASS
 *    EEC_VEGTY_SEAWEED
 *    EEC_VEGTY_SWAMP
 *    EEC_VEGTY_SWAMP_DECIDUOUS
 *    EEC_VEGTY_SWAMP_EVERGREEN
 *    EEC_VEGTY_SWAMP_MANGROVE
 *    EEC_VEGTY_SWAMP_MIXED
 *    EEC_VEGTY_SYSTEMATIC_DECIDUOUS_PLANTING
 *    EEC_VEGTY_SYSTEMATIC_EVERGREEN_PLANTING
 *    EEC_VEGTY_SYSTEMATIC_MIXED_PLANTING
 *    EEC_VEGTY_SYSTEMATIC_PALM_PLANTING
 *    EEC_VEGTY_SYSTEMATIC_PLANTING
 *    EEC_VEGTY_TROPICAL_GRASS
 *    EEC_VEGTY_TUNDRA
 *    EEC_VEGTY_TUNDRA_BUSH_SCRUB
 *    EEC_VEGTY_TUNDRA_HERBACEOUS
 *    EEC_VEGTY_TUNDRA_WET
 *    EEC_VEGTY_VINEYARDS_HOPS_GINSENG
 *    EEC_VEGTY_WALNUT
 *    EEC_VEGTY_WET_CROPS
 *    EEC_VEGTY_WHEAT
 *    EEC_VEGTY_WITH_TREES
 *    EEC_VEGTY_WITHOUT_TREES
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define EAC_VEGETATION_TYPE ((EDCS_Attribute_Code)1508)

/*
 * Definition:
 *     The number of <VEHICLE>s that an <OBJECT> can accommodate; the vehicle
 *     capacity.
 *
 * Value Type: COUNT
 *
 * Group Membership: ABSTRACT_OBJECT, TRNSP
 */
#define EAC_VEHICLE_CAPACITY ((EDCS_Attribute_Code)1509)

/*
 * Definition:
 *     The type of vehicle maintenance <FACILITY>s available at a <LOCATION>
 *     or in the near vicinity.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VEHMAINTAVAIL_AIRCRAFT_FABRICATION
 *    EEC_VEHMAINTAVAIL_AIRCRAFT_REPAIR
 *    EEC_VEHMAINTAVAIL_BARGE_FABRICATION
 *    EEC_VEHMAINTAVAIL_BARGE_REPAIR
 *    EEC_VEHMAINTAVAIL_BOAT_HOIST
 *    EEC_VEHMAINTAVAIL_GENERAL_FABRICATION
 *    EEC_VEHMAINTAVAIL_GENERAL_ELECTRICAL_FABRICATION
 *    EEC_VEHMAINTAVAIL_GENERAL_MECHANICAL_FABRICATION
 *    EEC_VEHMAINTAVAIL_INSPECTION_RAMP
 *    EEC_VEHMAINTAVAIL_LOCOMOTIVE_FABRICATION
 *    EEC_VEHMAINTAVAIL_LOCOMOTIVE_REPAIR
 *    EEC_VEHMAINTAVAIL_NONE_AVAILABLE
 *    EEC_VEHMAINTAVAIL_ROAD_VEH_FABRICATION
 *    EEC_VEHMAINTAVAIL_ROAD_VEH_REPAIR
 *    EEC_VEHMAINTAVAIL_SAIL_FABRICATION
 *    EEC_VEHMAINTAVAIL_VESSEL_FABRICATION
 *    EEC_VEHMAINTAVAIL_VESSEL_REPAIR
 *    EEC_VEHMAINTAVAIL_VESSEL_SALVAGE
 *
 * Group Membership: TRNSP, USAGE_REGION
 */
#define EAC_VEHICLE_MAINTENANCE_AVAILABLE ((EDCS_Attribute_Code)1510)

/*
 * Definition:
 *     The marking displayed on a <VEHICLE>, typically including echelon
 *     designation and coded bumper number. The marking is formatted in a
 *     Basic Latin string containing twelve characters as specified by
 *     [EBEV, Section 4.5, Entity Marking - Character Set].
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: TRNSP, VEHICLE
 */
#define EAC_VEHICLE_MARKING ((EDCS_Attribute_Code)1511)

/*
 * Definition:
 *     The type or origin of <SMOKE> from a <VEHICLE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VEHSMOKTY_ENGINE
 *    EEC_VEHSMOKTY_ENGINE_WITH_PLUME
 *    EEC_VEHSMOKTY_NONE_PRESENT
 *    EEC_VEHSMOKTY_PLUME
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, TRNSP
 */
#define EAC_VEHICLE_SMOKE_TYPE ((EDCS_Attribute_Code)1512)

/*
 * Definition:
 *     The total <<AREA>> of a <STRUCTURE> which can be used for the storage
 *     of <VEHICLE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREA
 *
 * Group Membership: DIMENSION, SUPPORT_STRUCTURE, TRNSP
 */
#define EAC_VEHICLE_STORAGE_AREA ((EDCS_Attribute_Code)1513)

/*
 * Definition:
 *     The <<HEIGHT>> of the primary <STRUCTURE_ENTRANCE_AND_OR_EXIT> for
 *     <VEHICLE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, SUPPORT_STRUCTURE, TRNSP
 */
#define EAC_VEHICLE_STORAGE_DOOR_PRI_HEIGHT ((EDCS_Attribute_Code)1514)

/*
 * Definition:
 *     The <<WIDTH>> of the primary <STRUCTURE_ENTRANCE_AND_OR_EXIT> for
 *     <VEHICLE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, SUPPORT_STRUCTURE, TRNSP
 */
#define EAC_VEHICLE_STORAGE_DOOR_PRI_WIDTH ((EDCS_Attribute_Code)1515)

/*
 * Definition:
 *     The type of flow-pattern of <VEHICLE>s on a <TRANSPORTATION_ROUTE>;
 *     the vehicle traffic flow.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VEHTRAFFLOW_INBOUND
 *    EEC_VEHTRAFFLOW_ONE_WAY
 *    EEC_VEHTRAFFLOW_OUTBOUND
 *    EEC_VEHTRAFFLOW_TWO_WAY
 *
 * Group Membership: TRNSP
 */
#define EAC_VEHICLE_TRAFFIC_FLOW ((EDCS_Attribute_Code)1516)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> of <VEHICLE>s on a
 *     <TRANSPORTATION_ROUTE>; the vehicle traffic geodetic direction.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, TRNSP
 */
#define EAC_VEHICLE_TRAFFIC_GEODETIC_DIRECTION ((EDCS_Attribute_Code)1517)

/*
 * Definition:
 *     The maximum <<SPEED>> legally permitted on a given stretch of a
 *     <LAND_TRANSPORTATION_ROUTE>; the vehicular speed limit.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: LAND_TRNSP, RATE_OR_RATIO, TRNSP
 */
#define EAC_VEHICULAR_SPEED_LIMIT ((EDCS_Attribute_Code)1518)

/*
 * Definition:
 *     <<SPEED>> in a <DIRECTION>; velocity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO
 */
#define EAC_VELOCITY ((EDCS_Attribute_Code)1519)

/*
 * Definition:
 *     The fraction of <PARTICLE>s in the <AIR> removed as the <AIR> makes a
 *     single pass through ventilation filters; the ventilation filter
 *     efficiency.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, INFRASTRUCTURE, RATE_OR_RATIO
 */
#define EAC_VENTILATION_FILTER_EFFICIENCY ((EDCS_Attribute_Code)1520)

/*
 * Definition:
 *     The rate at which a ventilation <SYSTEM> draws in exterior <AIR>. The
 *     rate is expressed as the fraction of the <<VOLUME>> of <AIR> in the
 *     <STRUCTURE> drawn in per unit time.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RATE
 *
 * Group Membership: ATMOSPHERE, INFRASTRUCTURE, RATE_OR_RATIO, SUPPORT_STRUCTURE
 */
#define EAC_VENTILATION_INFILTRATION_RATE ((EDCS_Attribute_Code)1521)

/*
 * Definition:
 *     The vertical clearance of an <OBJECT> (for example: a closed lifting
 *     <BRIDGE>) in its closed condition measured from the ground <SURFACE>
 *     underneath to the <OBJECT> overhead.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_VERTICAL_CLEARANCE_CLOSED ((EDCS_Attribute_Code)1522)

/*
 * Definition:
 *     The vertical clearance of an <OBJECT> (for example: an opened lifting
 *     <BRIDGE>) in its opened condition measured from the ground <SURFACE>
 *     underneath to the <OBJECT> overhead.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_VERTICAL_CLEARANCE_OPENED ((EDCS_Attribute_Code)1523)

/*
 * Definition:
 *     The safe vertical clearance of an <OBJECT> measured from the ground
 *     <SURFACE> underneath to the <OBJECT> overhead.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_VERTICAL_CLEARANCE_SAFE ((EDCS_Attribute_Code)1524)

/*
 * Definition:
 *     The designation of a <VERTICAL_DATUM>; vertical datum identifier.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VERTDTMID_EARTH_GRAVITATIONAL_MODEL_1996
 *    EEC_VERTDTMID_MEAN_SEA_LEVEL
 *    EEC_VERTDTMID_WGS_1984_ELLIPSOID
 *    EEC_VERTDTMID_WGS_1984_GEOID
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_VERTICAL_DATUM_IDENTIFIER ((EDCS_Attribute_Code)1525)

/*
 * Definition:
 *     The maximum distributed load per unit cross-section a vertical
 *     <OBJECT> can support; the vertical load bearing capacity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SURFACE_DENSITY
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_VERTICAL_LOAD_BEARING_CAPACITY ((EDCS_Attribute_Code)1526)

/*
 * Definition:
 *     The quality of a vertical measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VERTMEASQUAL_ESTIMATED
 *    EEC_VERTMEASQUAL_MEASURED
 *
 * Group Membership: LOCATION, SURVEY
 */
#define EAC_VERTICAL_MEASUREMENT_QUALITY ((EDCS_Attribute_Code)1527)

/*
 * Definition:
 *     An indication that a vertical passage (for example: a <RAMP>,
 *     a<STAIR>, and/or an <ESCALATOR>) in a <STRUCTURE> is fully enclosed
 *     by <WALL>s on both sides.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define EAC_VERTICAL_PASSAGE_ENCLOSED ((EDCS_Attribute_Code)1528)

/*
 * Definition:
 *     The areal density of <WATER_SURFACE_VESSEL>s in a <REGION> of a
 *     <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, RATE_OR_RATIO, TRNSP, VEHICLE
 */
#define EAC_VESSEL_DENSITY ((EDCS_Attribute_Code)1529)

/*
 * Definition:
 *     The category of <<VESSEL_DENSITY>>, determined according to induced
 *     ambient acoustic noise levels in a <WATERBODY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VESDENSACLEV_REMOTE
 *    EEC_VESDENSACLEV_LIGHT
 *    EEC_VESDENSACLEV_MODERATE
 *    EEC_VESDENSACLEV_HEAVY
 *
 * Group Membership: ACOUSTIC_PHENOMENON, HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_VESSEL_DENSITY_ACOUSTIC_LEVEL_CATEGORY ((EDCS_Attribute_Code)1530)

/*
 * Definition:
 *     The operating function of a <VESSEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VESFN_AIR_SUPPORT
 *    EEC_VESFN_AMMUNITION_SUPPLY
 *    EEC_VESFN_BATTLESHIP
 *    EEC_VESFN_COMBAT
 *    EEC_VESFN_COMBAT_STORES
 *    EEC_VESFN_COMBAT_SUPPORT
 *    EEC_VESFN_COMMAND
 *    EEC_VESFN_COMMERCIAL
 *    EEC_VESFN_CRUISER
 *    EEC_VESFN_DESTROYER
 *    EEC_VESFN_FRIGATE
 *    EEC_VESFN_GUIDED_MISSILE_CRUISER
 *    EEC_VESFN_GUIDED_MISSILE_DESTROYER
 *    EEC_VESFN_GUIDED_MISSILE_FRIGATE
 *    EEC_VESFN_GUNNERY
 *    EEC_VESFN_ICEBREAKER
 *    EEC_VESFN_MERCHANT_MARINE
 *    EEC_VESFN_PATROL
 *    EEC_VESFN_PLEASURE
 *    EEC_VESFN_SALVAGE
 *    EEC_VESFN_SURVEILLANCE
 *    EEC_VESFN_SURVIVAL
 *    EEC_VESFN_TENDER
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_VESSEL_FUNCTION ((EDCS_Attribute_Code)1531)

/*
 * Definition:
 *     The description of any load restrictions that apply to <VESSEL>s using
 *     a <MARINE_ROUTE> or marine <FACILITY>.
 *
 * Value Type: STRING
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define EAC_VESSEL_LOAD_RESTRICTIONS ((EDCS_Attribute_Code)1532)

/*
 * Definition:
 *     The type of a <VESSEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VESTY_AUXILIARY
 *    EEC_VESTY_BARGE
 *    EEC_VESTY_CIVILIAN
 *    EEC_VESTY_HYDROFOIL
 *    EEC_VESTY_LIFE_RAFT
 *    EEC_VESTY_LOGISTIC
 *    EEC_VESTY_MISSILE
 *    EEC_VESTY_PATROL_CRAFT
 *    EEC_VESTY_TANKER
 *    EEC_VESTY_TUGBOAT
 *    EEC_VESTY_UTILITY
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define EAC_VESSEL_TYPE ((EDCS_Attribute_Code)1533)

/*
 * Definition:
 *     An indication that an <OBJECT> contains a view <APERTURE> (for
 *     example: a peephole or small <WINDOW> in a <DOOR>).
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_VIEW_OPENING_PRESENT ((EDCS_Attribute_Code)1534)

/*
 * Definition:
 *     In a <SYSTEM> of moist <AIR>, the <<AIR_TEMPERATURE>> of dry <AIR>
 *     having the same <<AIR_DENSITY>> and <<ATM_PRESSURE>> as the moist
 *     <AIR>; the virtual air temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_VIRTUAL_AIR_TEMPERATURE ((EDCS_Attribute_Code)1535)

/*
 * Definition:
 *     The greatest distance in a given <DIRECTION> at which it is just
 *     possible to see and identify with the unaided eye either: (1) in the
 *     daytime, a prominent dark <OBJECT> against the sky at the horizon or
 *     (2) at night, a known, preferably unfocused, moderately intense
 *     <LIGHT>; visibility distance.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LIGHTING_AND_VISIBILITY
 */
#define EAC_VISIBILITY_DISTANCE ((EDCS_Attribute_Code)1536)

/*
 * Definition:
 *     The quality of a <<VISIBILITY_DISTANCE>> observation.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VISDISTQUAL_ERRONEOUS
 *    EEC_VISDISTQUAL_GOOD
 *    EEC_VISDISTQUAL_NO_CHECK
 *    EEC_VISDISTQUAL_SUSPECT
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_VISIBILITY_DISTANCE_QUALITY ((EDCS_Attribute_Code)1537)

/*
 * Definition:
 *     An indication that a reported <<VISIBILITY_DISTANCE>> observation is
 *     variable.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define EAC_VISIBILITY_DISTANCE_VARIABLE ((EDCS_Attribute_Code)1538)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional opacity (or alpha) of an <OBJECT> in the visual spectrum.
 *     The value is determined by how much light fails to penetrate through
 *     the <OBJECT>. Zero means that no light is blocked (all light
 *     penetrates) and one means that all light is blocked.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, LIGHTING_AND_VISIBILITY, RATE_OR_RATIO
 */
#define EAC_VISUAL_OPACITY ((EDCS_Attribute_Code)1539)

/*
 * Definition:
 *     An indication that a visual reflector is present on an
 *     <AID_TO_NAVIGATION>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define EAC_VISUAL_REFLECTOR_PRESENT ((EDCS_Attribute_Code)1540)

/*
 * Definition:
 *     The mean apparent <<HEIGHT>> of <WATER_WAVE>s that is determined
 *     visually and measured from trough to crest; the visual wave height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_VISUAL_WAVE_HEIGHT ((EDCS_Attribute_Code)1541)

/*
 * Definition:
 *     The type of morphology of the <TERRAIN> created by volcanic activity;
 *     the volcanic formation type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_VOLCFORMTY_CALDERA
 *    EEC_VOLCFORMTY_CINDER_CONE
 *    EEC_VOLCFORMTY_COMPOSITE
 *    EEC_VOLCFORMTY_CONICAL
 *    EEC_VOLCFORMTY_SHIELD
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_VOLCANIC_FORMATION_TYPE ((EDCS_Attribute_Code)1542)

/*
 * Definition:
 *     The nominal voltage level of supplied electrical power to a
 *     transportation <SYSTEM>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: ELECTRIC_POTENTIAL
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, TRNSP
 */
#define EAC_VOLTAGE_LEVEL ((EDCS_Attribute_Code)1543)

/*
 * Definition:
 *     The internal volume of an <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUME
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_VOLUME ((EDCS_Attribute_Code)1544)

/*
 * Definition:
 *     The negative of the depth gradient of the ratio of the flux returned
 *     (reflected directly back in the <DIRECTION> of incidence) to the
 *     incident flux (generally in decibels per metre of depth) for an
 *     <OBJECT>; the volume backscatter gradient.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER_LEVEL_DIFF_LEN_GRADIENT
 *
 * Group Membership: ABSTRACT_OBJECT, RATE_OR_RATIO
 */
#define EAC_VOLUME_BACKSCATTER_GRADIENT ((EDCS_Attribute_Code)1545)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the production rate of <WATERBODY_SURFACE> wakes induced
 *     by the movement of a <VESSEL> relative to <WATER_WAVE>s and
 *     <WATER_CURRENT>s. Zero means no wake at all and one means maximum
 *     intensity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, RATE_OR_RATIO, TRNSP, WATERBODY_SURFACE
 */
#define EAC_WAKE_INTENSITY ((EDCS_Attribute_Code)1546)

/*
 * Definition:
 *     The predominant visual pattern of the exterior <SURFACE>s of the
 *     <EXTERIOR_WALL>s of a <STRUCTURE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WALLPREDPAT_BRICK
 *    EEC_WALLPREDPAT_CLAPBOARD
 *    EEC_WALLPREDPAT_CORRUGATED
 *    EEC_WALLPREDPAT_LOG
 *    EEC_WALLPREDPAT_MOSAIC
 *    EEC_WALLPREDPAT_MULTIPLE_PATTERNS_PRESENT
 *    EEC_WALLPREDPAT_NO_PATTERN_PRESENT
 *    EEC_WALLPREDPAT_RECTANGULAR
 *    EEC_WALLPREDPAT_RUBBLE
 *    EEC_WALLPREDPAT_SMOOTH
 *    EEC_WALLPREDPAT_STUCCO
 *    EEC_WALLPREDPAT_TIMBER_FRAME
 *    EEC_WALLPREDPAT_WINDOW_WITH_GLASS
 *
 * Group Membership: SUPPORT_STRUCTURE, SURFACE
 */
#define EAC_WALL_PREDOMINANT_PATTERN ((EDCS_Attribute_Code)1547)

/*
 * Definition:
 *     The predominant outermost <MATERIAL> covering the <SURFACE> of a
 *     <WALL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WALLPREDSRFMAT_ALUMINUM
 *    EEC_WALLPREDSRFMAT_CEMENT
 *    EEC_WALLPREDSRFMAT_COBBLE
 *    EEC_WALLPREDSRFMAT_CONCRETE
 *    EEC_WALLPREDSRFMAT_CONGLOMERATE
 *    EEC_WALLPREDSRFMAT_EARTHEN
 *    EEC_WALLPREDSRFMAT_GLASS
 *    EEC_WALLPREDSRFMAT_MARBLE
 *    EEC_WALLPREDSRFMAT_MASONRY
 *    EEC_WALLPREDSRFMAT_METAL
 *    EEC_WALLPREDSRFMAT_MUD
 *    EEC_WALLPREDSRFMAT_NO_WALL_PRESENT
 *    EEC_WALLPREDSRFMAT_PLASTIC
 *    EEC_WALLPREDSRFMAT_REINFORCED_CONCRETE
 *    EEC_WALLPREDSRFMAT_SHINGLE
 *    EEC_WALLPREDSRFMAT_STEEL
 *    EEC_WALLPREDSRFMAT_STONE
 *    EEC_WALLPREDSRFMAT_VINYL
 *    EEC_WALLPREDSRFMAT_WOOD
 *
 * Group Membership: MATERIAL, SUPPORT_STRUCTURE, SURFACE, SURFACE_MATERIAL
 */
#define EAC_WALL_PREDOMINANT_SURFACE_MATERIAL ((EDCS_Attribute_Code)1548)

/*
 * Definition:
 *     The type of a <WALL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WALLTY_RETAINING
 *    EEC_WALLTY_STANDING
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_WALL_TYPE ((EDCS_Attribute_Code)1549)

/*
 * Definition:
 *     A type of <<ACOUSTIC_TRANSMISSION_LOSS>> model or database for
 *     <WATERBODY>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRACTRNMLOSS_ASPM
 *    EEC_WTRACTRNMLOSS_ASTRAL
 *    EEC_WTRACTRNMLOSS_CASS
 *    EEC_WTRACTRNMLOSS_FEPE
 *    EEC_WTRACTRNMLOSS_GRAB
 *    EEC_WTRACTRNMLOSS_KRAKEN
 *    EEC_WTRACTRNMLOSS_RAM
 *    EEC_WTRACTRNMLOSS_RAYMODE
 *
 * Group Membership: ACOUSTIC_PHENOMENON, ALGORITHM_RELATED, WATERBODY_STATE
 */
#define EAC_WATER_ACOUSTIC_TRANS_LOSS_MODEL ((EDCS_Attribute_Code)1550)

/*
 * Definition:
 *     A measurement of the reduction of transparency of a liquid caused
 *     attenuation due to by the presence of undissolved matter; turbidity.
 *     The measurement shall be made in accordance with the procedures
 *     specified in 6.4 of I7027.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, WATERBODY_STATE
 */
#define EAC_WATER_ATTENUATION_TURBIDITY ((EDCS_Attribute_Code)1551)

/*
 * Definition:
 *     A type of acoustic ambient noise spectral model or database for
 *     <WATERBODY>s.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRBDACAMBNSE_ANDES
 *    EEC_WTRBDACAMBNSE_ASAPS
 *    EEC_WTRBDACAMBNSE_ASNM
 *    EEC_WTRBDACAMBNSE_DANES
 *    EEC_WTRBDACAMBNSE_FANM
 *    EEC_WTRBDACAMBNSE_HITS
 *    EEC_WTRBDACAMBNSE_RANDI
 *    EEC_WTRBDACAMBNSE_SN
 *    EEC_WTRBDACAMBNSE_WRN
 *
 * Group Membership: ACOUSTIC_PHENOMENON, ALGORITHM_RELATED, WATERBODY_STATE
 */
#define EAC_WATERBODY_ACOUSTIC_AMBIENT_NOISE_SPECTRAL_MODEL ((EDCS_Attribute_Code)1552)

/*
 * Definition:
 *     The rate of photon emittance of visible light from <LIVING_ORGANISM>s
 *     in a <WATERBODY>; the waterbody luminescence.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: VOLUMETRIC_ENTITY_EMIT_RATE
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, LIVING_ORGANISM, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_WATERBODY_BIOLUMINESCENCE ((EDCS_Attribute_Code)1553)

/*
 * Definition:
 *     The areal density of <OBJECT>s on a <WATERBODY_FLOOR_REGION> that
 *     appear to acoustic sensors to be, but that are not, <EXPLOSIVE_MINE>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: AREAL_ENTITY_DENSITY
 *
 * Group Membership: ABSTRACT_OBJECT, ACOUSTIC_PHENOMENON, MILITARY_SCIENCE, RATE_OR_RATIO, WATERBODY_FLOOR
 */
#define EAC_WATERBODY_FLOOR_CLUTTER_DENSITY ((EDCS_Attribute_Code)1554)

/*
 * Definition:
 *     The type of a <WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRBDFLRCFG_BREAK_IN_SLOPE
 *    EEC_WTRBDFLRCFG_DEPRESSION_FLAT_BOTTOM
 *    EEC_WTRBDFLRCFG_DEPRESSION_SEDIMENT_FILLED
 *    EEC_WTRBDFLRCFG_DEPRESSION_STEEP_SIDED
 *    EEC_WTRBDFLRCFG_DEPRESSION_V_SHAPED
 *    EEC_WTRBDFLRCFG_DOUBLE_BREAK_IN_SLOPE
 *    EEC_WTRBDFLRCFG_ELEVATION_FLAT_TOPPED
 *    EEC_WTRBDFLRCFG_ELEVATION_PEAKED
 *    EEC_WTRBDFLRCFG_ELEVATION_ROUNDED
 *    EEC_WTRBDFLRCFG_SCARP_PROBABLY_FAULTED
 *    EEC_WTRBDFLRCFG_SLUMP_DEBRIS
 *    EEC_WTRBDFLRCFG_SLUMPED_BLOCKS
 *    EEC_WTRBDFLRCFG_STEP
 *    EEC_WTRBDFLRCFG_TERRACE
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define EAC_WATERBODY_FLOOR_CONFIGURATION ((EDCS_Attribute_Code)1555)

/*
 * Definition:
 *     The mean angle between the horizontal plane at a <WATERBODY_FLOOR> and
 *     the scattered acoustic rays; the waterbody floor grazing angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ACOUSTIC_PHENOMENON, ANGULAR_MEASURE, WATERBODY_FLOOR
 */
#define EAC_WATERBODY_FLOOR_GRAZING_ANGLE ((EDCS_Attribute_Code)1556)

/*
 * Definition:
 *     The predominant type of <MATERIAL> composing a <WATERBODY_FLOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRBDFLRMATTY_BEDROCK
 *    EEC_WTRBDFLRMATTY_CLAY_AND_SILT
 *    EEC_WTRBDFLRMATTY_CORAL
 *    EEC_WTRBDFLRMATTY_GRAVEL_AND_COBBLE
 *    EEC_WTRBDFLRMATTY_MIXED
 *    EEC_WTRBDFLRMATTY_PAVED
 *    EEC_WTRBDFLRMATTY_PEAT
 *    EEC_WTRBDFLRMATTY_ROCK_AND_BOULDER
 *    EEC_WTRBDFLRMATTY_ROCKY_OUTCROP
 *    EEC_WTRBDFLRMATTY_SAND
 *    EEC_WTRBDFLRMATTY_SAND_AND_GRAVEL
 *    EEC_WTRBDFLRMATTY_SAND_AND_MUD
 *    EEC_WTRBDFLRMATTY_SILTY_SAND
 *    EEC_WTRBDFLRMATTY_SLASH
 *    EEC_WTRBDFLRMATTY_SNAGS
 *    EEC_WTRBDFLRMATTY_SAND_OVER_MUD
 *
 * Group Membership: MATERIAL, SURFACE_MATERIAL, WATERBODY_FLOOR
 */
#define EAC_WATERBODY_FLOOR_MATERIAL_TYPE ((EDCS_Attribute_Code)1557)

/*
 * Definition:
 *     The morphology of a <WATERBODY_FLOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRBDFLRMRPH_ABYSSAL_HILLS
 *    EEC_WTRBDFLRMRPH_ABYSSAL_PLAIN
 *    EEC_WTRBDFLRMRPH_APRON
 *    EEC_WTRBDFLRMRPH_ARCHIPELAGIC_APRON
 *    EEC_WTRBDFLRMRPH_BANK
 *    EEC_WTRBDFLRMRPH_BASIN
 *    EEC_WTRBDFLRMRPH_BENCH
 *    EEC_WTRBDFLRMRPH_BORDERLAND
 *    EEC_WTRBDFLRMRPH_CANYON
 *    EEC_WTRBDFLRMRPH_CANYON_LAND
 *    EEC_WTRBDFLRMRPH_CNTNTL_MARGIN
 *    EEC_WTRBDFLRMRPH_CNTNTL_RISE
 *    EEC_WTRBDFLRMRPH_CRATER
 *    EEC_WTRBDFLRMRPH_DEEP
 *    EEC_WTRBDFLRMRPH_ESCARPMENT
 *    EEC_WTRBDFLRMRPH_FAN
 *    EEC_WTRBDFLRMRPH_FLAT
 *    EEC_WTRBDFLRMRPH_FRACTURE_ZONE
 *    EEC_WTRBDFLRMRPH_GAP
 *    EEC_WTRBDFLRMRPH_GAT
 *    EEC_WTRBDFLRMRPH_GUYOT
 *    EEC_WTRBDFLRMRPH_HILL
 *    EEC_WTRBDFLRMRPH_HOLE
 *    EEC_WTRBDFLRMRPH_KNOLL
 *    EEC_WTRBDFLRMRPH_LEDGE
 *    EEC_WTRBDFLRMRPH_LEVEE
 *    EEC_WTRBDFLRMRPH_LOWLAND
 *    EEC_WTRBDFLRMRPH_MARINE_BAY
 *    EEC_WTRBDFLRMRPH_MEDIAN_VALLEY
 *    EEC_WTRBDFLRMRPH_MOAT
 *    EEC_WTRBDFLRMRPH_MOUNTAIN
 *    EEC_WTRBDFLRMRPH_MUD_FLAT
 *    EEC_WTRBDFLRMRPH_NARROW
 *    EEC_WTRBDFLRMRPH_NONE_IDENTIFIED
 *    EEC_WTRBDFLRMRPH_PEAK
 *    EEC_WTRBDFLRMRPH_PINNACLE
 *    EEC_WTRBDFLRMRPH_PLATEAU
 *    EEC_WTRBDFLRMRPH_PROVINCE
 *    EEC_WTRBDFLRMRPH_REEF
 *    EEC_WTRBDFLRMRPH_RIDGE
 *    EEC_WTRBDFLRMRPH_RISE
 *    EEC_WTRBDFLRMRPH_SADDLE
 *    EEC_WTRBDFLRMRPH_SEA_CHANNEL
 *    EEC_WTRBDFLRMRPH_SEAMOUNT
 *    EEC_WTRBDFLRMRPH_SEAMOUNT_CHAIN
 *    EEC_WTRBDFLRMRPH_SHELF
 *    EEC_WTRBDFLRMRPH_SHELF_EDGE
 *    EEC_WTRBDFLRMRPH_SHOAL
 *    EEC_WTRBDFLRMRPH_SILL
 *    EEC_WTRBDFLRMRPH_SLOPE
 *    EEC_WTRBDFLRMRPH_SPUR
 *    EEC_WTRBDFLRMRPH_TERRACE
 *    EEC_WTRBDFLRMRPH_TRENCH
 *    EEC_WTRBDFLRMRPH_TROUGH
 *    EEC_WTRBDFLRMRPH_VALLEY
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define EAC_WATERBODY_FLOOR_MORPHOLOGY ((EDCS_Attribute_Code)1558)

/*
 * Definition:
 *     The type of a <TERRAIN_SURFACE_OBJECT> that is located on a
 *     <WATERBODY_FLOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRBDFLROBJTY_FISH_HAVEN
 *    EEC_WTRBDFLROBJTY_PINNACLE
 *    EEC_WTRBDFLROBJTY_REDUCED_DEPTH
 *    EEC_WTRBDFLROBJTY_SHOALING
 *    EEC_WTRBDFLROBJTY_SUBMERGED_PRODUCTION_PLATFORM
 *    EEC_WTRBDFLROBJTY_UNEXPLODED_MUNITION
 *    EEC_WTRBDFLROBJTY_UNKNOWN_OBSTRUCTION
 *    EEC_WTRBDFLROBJTY_UNSPECIFIED_NON_SUB_CONTACT
 *    EEC_WTRBDFLROBJTY_WELL_HEAD
 *    EEC_WTRBDFLROBJTY_WRECK
 *
 * Group Membership: WATERBODY_FLOOR
 */
#define EAC_WATERBODY_FLOOR_OBJECT_TYPE ((EDCS_Attribute_Code)1559)

/*
 * Definition:
 *     A qualitative characterization of the roughness of a <WATERBODY_FLOOR>
 *     at spatial frequencies relevant to <EXPLOSIVE_MINE> detection; the
 *     waterbody floor roughness category.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRBDFLRRGH_SMOOTH
 *    EEC_WTRBDFLRRGH_MODERATE
 *    EEC_WTRBDFLRRGH_ROUGH
 *
 * Group Membership: MILITARY_SCIENCE, PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define EAC_WATERBODY_FLOOR_ROUGHNESS_CATEGORY ((EDCS_Attribute_Code)1560)

/*
 * Definition:
 *     The type of the acoustic properties of a
 *     <WATERBODY_ACOUSTIC_PROPERTY_SET>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRBDPRPSETAC_ACTIVE_HIGHLIGHT
 *    EEC_WTRBDPRPSETAC_AMBIENT_NOISE
 *    EEC_WTRBDPRPSETAC_BIOLOGIC_NOISE
 *    EEC_WTRBDPRPSETAC_LOSS
 *    EEC_WTRBDPRPSETAC_MARGINAL_ICE_ZONE_NOISE
 *    EEC_WTRBDPRPSETAC_RAIN_NOISE
 *    EEC_WTRBDPRPSETAC_RESIDUAL_NOISE
 *    EEC_WTRBDPRPSETAC_REVERBERATION
 *    EEC_WTRBDPRPSETAC_SCATTERING_STRENGTH
 *    EEC_WTRBDPRPSETAC_SEA_STATE_NOISE
 *    EEC_WTRBDPRPSETAC_SENSOR
 *    EEC_WTRBDPRPSETAC_SHIPPING_NOISE
 *    EEC_WTRBDPRPSETAC_SIGNAL
 *    EEC_WTRBDPRPSETAC_SOUND_SPEED
 *    EEC_WTRBDPRPSETAC_TEMPERATURE
 *
 * Group Membership: ACOUSTIC_PHENOMENON, PROPERTY_SET, WATERBODY_STATE
 */
#define EAC_WATERBODY_PROPERTY_SET_ACOUSTIC_TYPE ((EDCS_Attribute_Code)1561)

/*
 * Definition:
 *     The <<SPEED>> of sound in a <WATERBODY>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_WATERBODY_SOUND_SPEED ((EDCS_Attribute_Code)1562)

/*
 * Definition:
 *     The method of observation, measurement, collection, prediction, or
 *     estimation of one or more characteristics of a <WATERBODY_SURFACE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRBDSRFOBV_AT_SURFACE
 *    EEC_WTRBDSRFOBV_BELOW_SURFACE
 *    EEC_WTRBDSRFOBV_BUCKET_MEASURED
 *    EEC_WTRBDSRFOBV_MODEL_BASED
 *    EEC_WTRBDSRFOBV_NOT_SPECIFIED
 *    EEC_WTRBDSRFOBV_REMOTELY_MEASURED
 *    EEC_WTRBDSRFOBV_VESSEL_INJECTION
 *
 * Group Membership: LOCATION, WATERBODY_SURFACE
 */
#define EAC_WATERBODY_SURFACE_DATA_OBSERVATION_METHOD ((EDCS_Attribute_Code)1563)

/*
 * Definition:
 *     The mean angle between the horizontal plane at a <WATERBODY_SURFACE>
 *     and scattered acoustic rays; the waterbody surface grazing angle.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ACOUSTIC_PHENOMENON, ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_WATERBODY_SURFACE_GRAZING_ANGLE ((EDCS_Attribute_Code)1564)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional <<AREA>> of a <WATERBODY_SURFACE> that is covered by
 *     <ICE>. Zero means no <ICE> is present and one means the
 *     <WATERBODY_SURFACE> is completely covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ICE, RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_WATERBODY_SURFACE_ICE_FRACTION ((EDCS_Attribute_Code)1565)

/*
 * Definition:
 *     The instantaneous height of a <WATERBODY_SURFACE> above a
 *     <VERTICAL_DATUM> or <SOUNDING_DATUM>. For <OCEAN>s and <SEA>s the
 *     <SOUNDING_DATUM> is defined as MSL corrected for the <TIDE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_WATERBODY_SURFACE_INSTANTANEOUS_HEIGHT ((EDCS_Attribute_Code)1566)

/*
 * Definition:
 *     The <<WATERBODY_TEMPERATURE>> measured, estimated, or predicted at or
 *     near a <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_SURFACE
 */
#define EAC_WATERBODY_SURFACE_TEMPERATURE ((EDCS_Attribute_Code)1567)

/*
 * Definition:
 *     The U component (geodetic west-east direction, where east is positive)
 *     of the stress on a <WATERBODY_SURFACE> induced by <WIND>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MOMENTUM
 *
 * Group Membership: ATMOSPHERE, WATERBODY_SURFACE
 */
#define EAC_WATERBODY_SURFACE_U_WIND_STRESS ((EDCS_Attribute_Code)1568)

/*
 * Definition:
 *     The V component (geodetic south-north direction, where north is
 *     positive) of the stress on a <WATERBODY_SURFACE> induced by <WIND>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MOMENTUM
 *
 * Group Membership: ATMOSPHERE, WATERBODY_SURFACE
 */
#define EAC_WATERBODY_SURFACE_V_WIND_STRESS ((EDCS_Attribute_Code)1569)

/*
 * Definition:
 *     The total stress on a <WATERBODY_SURFACE> induced by <WIND>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MOMENTUM
 *
 * Group Membership: ATMOSPHERE, WATERBODY_SURFACE
 */
#define EAC_WATERBODY_SURFACE_WIND_STRESS ((EDCS_Attribute_Code)1570)

/*
 * Definition:
 *     The <<TEMPERATURE>> of a <WATERBODY>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: TEMPERATURE, WATERBODY_STATE
 */
#define EAC_WATERBODY_TEMPERATURE ((EDCS_Attribute_Code)1571)

/*
 * Definition:
 *     The minimum safe horizontal distance between adjacent <STRUCTURE>s on
 *     either side of a <WATER_CHANNEL>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, SUPPORT_STRUCTURE, TRNSP
 */
#define EAC_WATER_CHANNEL_SAFE_HORIZONTAL_CLEARANCE ((EDCS_Attribute_Code)1572)

/*
 * Definition:
 *     The type of a <WATER_CHANNEL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRCHNLTY_LAGOONAL
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define EAC_WATER_CHANNEL_TYPE ((EDCS_Attribute_Code)1573)

/*
 * Definition:
 *     The <<MONTH>> of appearance of a <WATER_CURRENT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRCURAPMON_JANUARY
 *    EEC_WTRCURAPMON_FEBRUARY
 *    EEC_WTRCURAPMON_MARCH
 *    EEC_WTRCURAPMON_APRIL
 *    EEC_WTRCURAPMON_MAY
 *    EEC_WTRCURAPMON_JUNE
 *    EEC_WTRCURAPMON_JULY
 *    EEC_WTRCURAPMON_AUGUST
 *    EEC_WTRCURAPMON_SEPTEMBER
 *    EEC_WTRCURAPMON_OCTOBER
 *    EEC_WTRCURAPMON_NOVEMBER
 *    EEC_WTRCURAPMON_DECEMBER
 *
 * Group Membership: TIME, WATERBODY_STATE
 */
#define EAC_WATER_CURRENT_APPEARANCE_MONTH ((EDCS_Attribute_Code)1574)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> of a <WATER_CURRENT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_STATE
 */
#define EAC_WATER_CURRENT_DIRECTION ((EDCS_Attribute_Code)1575)

/*
 * Definition:
 *     The <<MONTH>> of disappearance of a <WATER_CURRENT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRCURDISAPMON_JANUARY
 *    EEC_WTRCURDISAPMON_FEBRUARY
 *    EEC_WTRCURDISAPMON_MARCH
 *    EEC_WTRCURDISAPMON_APRIL
 *    EEC_WTRCURDISAPMON_MAY
 *    EEC_WTRCURDISAPMON_JUNE
 *    EEC_WTRCURDISAPMON_JULY
 *    EEC_WTRCURDISAPMON_AUGUST
 *    EEC_WTRCURDISAPMON_SEPTEMBER
 *    EEC_WTRCURDISAPMON_OCTOBER
 *    EEC_WTRCURDISAPMON_NOVEMBER
 *    EEC_WTRCURDISAPMON_DECEMBER
 *
 * Group Membership: TIME, WATERBODY_STATE
 */
#define EAC_WATER_CURRENT_DISAPPEARANCE_MONTH ((EDCS_Attribute_Code)1576)

/*
 * Definition:
 *     The reference time of a measurement of a <WATER_CURRENT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRCURREFR_AT_HIGH_WATER
 *    EEC_WTRCURREFR_ONE_HOUR_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_TWO_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_THREE_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_FOUR_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_FIVE_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_SIX_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_SEVEN_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_EIGHT_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_NINE_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_TEN_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_ELEVEN_HRS_AFT_HIGH_WATER
 *    EEC_WTRCURREFR_AT_TIDE
 *    EEC_WTRCURREFR_ONE_HOUR_AFT_TIDE
 *    EEC_WTRCURREFR_TWO_HRS_AFT_TIDE
 *    EEC_WTRCURREFR_THREE_HRS_AFT_TIDE
 *    EEC_WTRCURREFR_FOUR_HRS_AFT_TIDE
 *    EEC_WTRCURREFR_FIVE_HRS_AFT_TIDE
 *    EEC_WTRCURREFR_SIX_HRS_AFT_TIDE
 *    EEC_WTRCURREFR_FIVE_HRS_BEFORE_TIDE
 *    EEC_WTRCURREFR_FOUR_HRS_BEFORE_TIDE
 *    EEC_WTRCURREFR_THREE_HRS_BEFORE_TIDE
 *    EEC_WTRCURREFR_TWO_HRS_BEFORE_TIDE
 *    EEC_WTRCURREFR_ONE_HOUR_BEFORE_TIDE
 *
 * Group Membership: TIME, WATERBODY_STATE
 */
#define EAC_WATER_CURRENT_REFERENCE ((EDCS_Attribute_Code)1577)

/*
 * Definition:
 *     The <<SPEED>> of a <WATER_CURRENT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_STATE
 */
#define EAC_WATER_CURRENT_SPEED ((EDCS_Attribute_Code)1578)

/*
 * Definition:
 *     The type of a <WATER_CURRENT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRCURTY_EBB_TIDE
 *    EEC_WTRCURTY_FLOOD_TIDE
 *    EEC_WTRCURTY_GENERAL_FLOW
 *    EEC_WTRCURTY_LONGSHORE
 *    EEC_WTRCURTY_NON_EBB_FLOOD_TIDAL
 *    EEC_WTRCURTY_OCEAN
 *    EEC_WTRCURTY_RIVER
 *    EEC_WTRCURTY_RIP
 *    EEC_WTRCURTY_TIDAL
 *    EEC_WTRCURTY_WIND_DRIVEN
 *
 * Group Membership: WATERBODY_STATE
 */
#define EAC_WATER_CURRENT_TYPE ((EDCS_Attribute_Code)1579)

/*
 * Definition:
 *     The depth of <WATER> from a <SURFACE_DATUM> to a <WATERBODY_FLOOR>, as
 *     a positive number.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: LOCATION, WATERBODY_FLOOR
 */
#define EAC_WATER_DEPTH ((EDCS_Attribute_Code)1580)

/*
 * Definition:
 *     A measurement of the reduction of transparency of a liquid caused by
 *     diffusion due to the presence of undissolved matter; turbidity. The
 *     measurement shall be made in accordance with the procedures specified
 *     in 6.3 of I7027.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, WATERBODY_STATE
 */
#define EAC_WATER_DIFFUSE_TURBIDITY ((EDCS_Attribute_Code)1581)

/*
 * Definition:
 *     The effect of surrounding <WATER> on an <OBJECT>; the water level
 *     effect.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRLEVEFF_ALWAYS_DRY
 *    EEC_WTRLEVEFF_ALWAYS_UNDER_WATER
 *    EEC_WTRLEVEFF_AWASH
 *    EEC_WTRLEVEFF_COVERS_AND_UNCOVERS
 *    EEC_WTRLEVEFF_DRYING
 *    EEC_WTRLEVEFF_FLOATING
 *    EEC_WTRLEVEFF_PARTIALLY_SUBMERGED
 *    EEC_WTRLEVEFF_SUBJECT_TO_INUNDATION
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_WATER_LEVEL_EFFECT ((EDCS_Attribute_Code)1582)

/*
 * Definition:
 *     The quality of <WATER> for drinking.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRQUAL_CONTAMINATED
 *    EEC_WTRQUAL_NON_POTABLE
 *    EEC_WTRQUAL_POTABLE
 *    EEC_WTRQUAL_TREATABLE
 *
 * Group Membership: INFRASTRUCTURE, WATERBODY_STATE
 */
#define EAC_WATER_QUALITY ((EDCS_Attribute_Code)1583)

/*
 * Definition:
 *     The mean depth of a zone of saturation in the subsurface <TERRAIN>
 *     except where bounded by an impermeable body (for example: <ROCK>) in
 *     which no water table exists; the water table depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: HYDROLOGY, LOCATION
 */
#define EAC_WATER_TABLE_DEPTH ((EDCS_Attribute_Code)1584)

/*
 * Definition:
 *     The type of available <WATER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRTY_ALKALINE
 *    EEC_WTRTY_BRACKISH
 *    EEC_WTRTY_FRESH
 *    EEC_WTRTY_MINERAL
 *    EEC_WTRTY_POTABLE
 *    EEC_WTRTY_SALT
 *
 * Group Membership: INFRASTRUCTURE, WATERBODY_STATE
 */
#define EAC_WATER_TYPE ((EDCS_Attribute_Code)1585)

/*
 * Definition:
 *     The partial pressure of water vapour in an <ATMOSPHERE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WATER_VAPOUR_PRESSURE ((EDCS_Attribute_Code)1586)

/*
 * Definition:
 *     The type of trough-like depression that is normally occupied by a
 *     <WATERCOURSE>; the watercourse channel type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRCRSCHNLTY_BRAIDED
 *    EEC_WTRCRSCHNLTY_CHANNELIZED
 *    EEC_WTRCRSCHNLTY_GORGE
 *    EEC_WTRCRSCHNLTY_MEANDERING
 *    EEC_WTRCRSCHNLTY_NON_MEANDERING
 *    EEC_WTRCRSCHNLTY_OXBOW
 *    EEC_WTRCRSCHNLTY_WADI
 *
 * Group Membership: HYDROLOGY, PHYSIOGRAPHY
 */
#define EAC_WATERCOURSE_CHANNEL_TYPE ((EDCS_Attribute_Code)1587)

/*
 * Definition:
 *     The predominant <<TERRAIN_GAP_WIDTH>>, measured between the tops of
 *     the first accessible breaks in slope above mean water level on each
 *     bank of a <WATERCOURSE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, HYDROLOGY
 */
#define EAC_WATERCOURSE_GAP_WIDTH ((EDCS_Attribute_Code)1588)

/*
 * Definition:
 *     The type of the sink of a <WATERCOURSE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WTRCRSSINKTY_DISAPPEARING
 *    EEC_WTRCRSSINKTY_DISSIPATING
 *    EEC_WTRCRSSINKTY_OTHER_DISAPPEARING
 *    EEC_WTRCRSSINKTY_SINKHOLE_DISAPPEARING
 *
 * Group Membership: HYDROLOGY, INFRASTRUCTURE
 */
#define EAC_WATERCOURSE_SINK_TYPE ((EDCS_Attribute_Code)1589)

/*
 * Definition:
 *     The power represented by a spectrum of <WATER_WAVE>s at a particular
 *     centre <<FREQUENCY>> and centre <DIRECTION>; the wave spectral
 *     density.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: POWER
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define EAC_WAVE_SPECTRAL_DENSITY ((EDCS_Attribute_Code)1590)

/*
 * Definition:
 *     The rate of occurrence of <WATER_WAVE>s bearing whitecaps on their
 *     crests due to <WIND>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: RATE_OR_RATIO, WATERBODY_SURFACE
 */
#define EAC_WAVE_WHITECAP_RATE ((EDCS_Attribute_Code)1591)

/*
 * Definition:
 *     The distance in a periodic wave between two points of corresponding
 *     phase in consecutive cycles; the wavelength [AHD, "wavelength", 1].
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION
 */
#define EAC_WAVELENGTH ((EDCS_Attribute_Code)1592)

/*
 * Definition:
 *     The type of an <AVIATION_WAYPOINT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WAYPTTY_AERODROME
 *    EEC_WAYPTTY_ATC_COMPULSORY
 *    EEC_WAYPTTY_BACK_COURSE_MARKER
 *    EEC_WAYPTTY_DME_FIX
 *    EEC_WAYPTTY_END_CONTINUOUS_AIRWAY
 *    EEC_WAYPTTY_ESSENTIAL
 *    EEC_WAYPTTY_FAN_MARKER
 *    EEC_WAYPTTY_FINAL_APPROACH_COURSE_FIX
 *    EEC_WAYPTTY_FINAL_APPROACH_FIX
 *    EEC_WAYPTTY_FIRST_LEG_MISSED_APPROACH
 *    EEC_WAYPTTY_GATEWAY_FIX
 *    EEC_WAYPTTY_HOLDING_FIX
 *    EEC_WAYPTTY_INITIAL_APPROACH_FIX
 *    EEC_WAYPTTY_INNER_MARKER
 *    EEC_WAYPTTY_MIDDLE_MARKER
 *    EEC_WAYPTTY_MISSED_APPROACH_POINT
 *    EEC_WAYPTTY_NON_ESSENTIAL
 *    EEC_WAYPTTY_OFF_AIRWAY
 *    EEC_WAYPTTY_OUTER_MARKER
 *    EEC_WAYPTTY_RUNWAY
 *    EEC_WAYPTTY_RUNWAY_END_COORDINATE
 *    EEC_WAYPTTY_TRANSITION_ESSENTIAL
 *    EEC_WAYPTTY_UNCHARTED_AIRWAY_INTERSECT
 *    EEC_WAYPTTY_VOR_VORDME_VORTAC
 *
 * Group Membership: TRNSP
 */
#define EAC_WAYPOINT_TYPE ((EDCS_Attribute_Code)1593)

/*
 * Definition:
 *     The type of a <WEAPONS_RANGE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WEAPRNGTY_DEMOLITION_AREA
 *    EEC_WEAPRNGTY_FIELD_ARTILLERY
 *    EEC_WEAPRNGTY_GRENADE
 *    EEC_WEAPRNGTY_IMPACT_AREA
 *    EEC_WEAPRNGTY_SMALL_ARMS
 *    EEC_WEAPRNGTY_TANK
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_WEAPONS_RANGE_TYPE ((EDCS_Attribute_Code)1594)

/*
 * Definition:
 *     The technique or method of weather measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WXMEASTECH_AUTOMATED
 *    EEC_WXMEASTECH_MANUAL
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WEATHER_MEASUREMENT_TECHNIQUE ((EDCS_Attribute_Code)1595)

/*
 * Definition:
 *     The type of a <WELL>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WELLTY_ARTESIAN
 *    EEC_WELLTY_DRILLED
 *    EEC_WELLTY_DUG
 *    EEC_WELLTY_DUG_OR_DRILLED
 *    EEC_WELLTY_FOUNTAIN
 *    EEC_WELLTY_WALLED_IN
 *    EEC_WELLTY_WATERING_HOLE
 *
 * Group Membership: INDUSTRY
 */
#define EAC_WELL_TYPE ((EDCS_Attribute_Code)1596)

/*
 * Definition:
 *     The <<AIR_TEMPERATURE>> that a parcel of <AIR> would have, if cooled
 *     adiabatically at constant <<ATM_PRESSURE>> to the water vapour
 *     saturation point by evaporation of <WATER> into it, with all latent
 *     heat being supplied by the parcel of <AIR>; the wet bulb air
 *     temperature.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_WET_BULB_AIR_TEMPERATURE ((EDCS_Attribute_Code)1597)

/*
 * Definition:
 *     The <<WATERCOURSE_GAP_WIDTH>> at low <TIDE>; the wet gap width.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_WET_GAP_WIDTH ((EDCS_Attribute_Code)1598)

/*
 * Definition:
 *     The <<SOIL_TYPE>> further categorized by its wet weather
 *     trafficability characteristics.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WETSOILTRAF_CH
 *    EEC_WETSOILTRAF_GC_SC_CL
 *    EEC_WETSOILTRAF_GM_SM_ML_ML_AND_CL_MH_OL_OH
 *    EEC_WETSOILTRAF_GW_GP_SW_SP
 *    EEC_WETSOILTRAF_NOT_EVALUATED
 *    EEC_WETSOILTRAF_PT
 *
 * Group Membership: ATMOSPHERE, LAND_TRNSP, TRNSP
 */
#define EAC_WET_SOIL_TRAFFICABILITY ((EDCS_Attribute_Code)1599)

/*
 * Definition:
 *     The type and/or structure of a <WETLAND>; the wetland surface form.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WETLSRFTY_ATLANTIC_PLATEAU_BOG
 *    EEC_WETLSRFTY_BASIN_BOG
 *    EEC_WETLSRFTY_BASIN_SWAMP
 *    EEC_WETLSRFTY_BLANKET_BOG
 *    EEC_WETLSRFTY_DOMED_BOG
 *    EEC_WETLSRFTY_FLAT_BOG
 *    EEC_WETLSRFTY_HORIZONTAL_FEN
 *    EEC_WETLSRFTY_LOWLAND_POLYGON_BOG
 *    EEC_WETLSRFTY_NORTHERN_RIBBED_FEN
 *    EEC_WETLSRFTY_PALSA_BOG
 *    EEC_WETLSRFTY_PEAT_PLATEAU_BOG
 *    EEC_WETLSRFTY_POLYGONAL_PEAT_PLATEAU_BOG
 *    EEC_WETLSRFTY_SHALLOW_BASIN_MARSH
 *    EEC_WETLSRFTY_SHORE_FEN
 *    EEC_WETLSRFTY_SHORE_MARSH
 *    EEC_WETLSRFTY_SLOPE_BOG
 *    EEC_WETLSRFTY_SLOPE_FEN
 *    EEC_WETLSRFTY_STREAM_MARSH
 *    EEC_WETLSRFTY_STREAM_SWAMP
 *    EEC_WETLSRFTY_STRING_BOG
 *    EEC_WETLSRFTY_VENEER_BOG
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define EAC_WETLAND_SURFACE_FORM ((EDCS_Attribute_Code)1600)

/*
 * Definition:
 *     The length of the shorter of two orthogonal linear axes of an
 *     <OBJECT>, measured in the horizontal plane. For a square <OBJECT>,
 *     either axis may be measured; for a round <OBJECT>, the diameter is
 *     measured. For a <BRIDGE>, the distance perpendicular to the axis
 *     between the <BRIDGE_PIER>s is measured.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ABSTRACT_OBJECT, DIMENSION
 */
#define EAC_WIDTH ((EDCS_Attribute_Code)1601)

/*
 * Definition:
 *     The vorticity of <WIND> determined with respect to an absolute
 *     coordinate system; the wind absolute vorticity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: ANGULAR_VELOCITY
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_ABSOLUTE_VORTICITY ((EDCS_Attribute_Code)1602)

/*
 * Definition:
 *     The historical (climatology) fraction of calm <<WIND_SPEED>>s (less
 *     than 2,575 metres per second or equivalently five knots).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_CALM_FRACTION_CLIMATOLOGY ((EDCS_Attribute_Code)1603)

/*
 * Definition:
 *     A categorization of <WIND> based on <<WIND_SPEED>> and its variability.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WNDCAT_CALM
 *    EEC_WNDCAT_NO_GUSTS
 *    EEC_WNDCAT_SQUALL
 *    EEC_WNDCAT_VARIABLE
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WIND_CATEGORY ((EDCS_Attribute_Code)1604)

/*
 * Definition:
 *     A means of quantifying the combined effect of low <<AIR_TEMPERATURE>>
 *     and <<WIND_SPEED>> on the body <<TEMPERATURE>> of <HUMAN>s that may
 *     result in hypothermia. The value is expressed as an equivalent
 *     <<TEMPERATURE>> in degrees Celsius given by the formula: 13,1267 +
 *     (1,1187 * T) - (13,9468 * V^(0,16)) + (0,4863 * T * V^(0,16)) where V
 *     is the <<WIND_SPEED>> in metres per second at a <<HEIGHT_AGL>> of 1,5
 *     metres (approximately 5 feet) and T is the <<AIR_TEMPERATURE>> in
 *     degrees Celsius; the wind chill temperature index.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: THERMO_TEMPERATURE
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_WIND_CHILL_TEMPERATURE_INDEX ((EDCS_Attribute_Code)1605)

/*
 * Definition:
 *     The historical (climatology) quantity of the ratio of the standard
 *     deviation of the <<WIND_SPEED_U>> to the standard deviation of the
 *     <<WIND_SPEED_V>>, for a defined period of record; the wind
 *     circularity coefficient climatology.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_CIRCULARITY_COEFFICIENT_CLIMATOLOGY ((EDCS_Attribute_Code)1606)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which the <WIND> is
 *     blowing.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, ATMOSPHERE
 */
#define EAC_WIND_DIRECTION ((EDCS_Attribute_Code)1607)

/*
 * Definition:
 *     The mean historical (climatology) <<WIND_DIRECTION>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, ATMOSPHERE
 */
#define EAC_WIND_DIRECTION_CLIMATOLOGY ((EDCS_Attribute_Code)1608)

/*
 * Definition:
 *     The historical (climatology) <<WIND_DIRECTION>> categorized by
 *     cardinal vector octant (a 45 arc degree sector centred on a cardinal
 *     direction).
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WNDOCTDIRCLIM_NORTH
 *    EEC_WNDOCTDIRCLIM_NORTH_EAST
 *    EEC_WNDOCTDIRCLIM_EAST
 *    EEC_WNDOCTDIRCLIM_SOUTH_EAST
 *    EEC_WNDOCTDIRCLIM_SOUTH
 *    EEC_WNDOCTDIRCLIM_SOUTH_WEST
 *    EEC_WNDOCTDIRCLIM_WEST
 *    EEC_WNDOCTDIRCLIM_NORTH_WEST
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WIND_DIRECTION_OCTANT_CLIMATOLOGY ((EDCS_Attribute_Code)1609)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of observations reporting <<WIND_DIRECTION>>s within a
 *     cardinal vector octant (a 45 arc degree sector centred on a cardinal
 *     <DIRECTION>).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_DIRECTION_OCTANT_FRACTION ((EDCS_Attribute_Code)1610)

/*
 * Definition:
 *     The quality of a <<WIND_DIRECTION>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WNDDIRQUAL_ERRONEOUS
 *    EEC_WNDDIRQUAL_GOOD
 *    EEC_WNDDIRQUAL_NO_CHECK
 *    EEC_WNDDIRQUAL_SUSPECT
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WIND_DIRECTION_QUALITY ((EDCS_Attribute_Code)1611)

/*
 * Definition:
 *     The angular range of the <<WIND_DIRECTION>> during a relatively short
 *     reporting period.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, ATMOSPHERE
 */
#define EAC_WIND_DIRECTION_VARIABILITY ((EDCS_Attribute_Code)1612)

/*
 * Definition:
 *     The horizontal expansion or spreading out of the vector field of the
 *     <WIND>; the wind divergence.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: RATE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_DIVERGENCE ((EDCS_Attribute_Code)1613)

/*
 * Definition:
 *     The type of measuring <EQUIPMENT> used to measure a <<WIND_DIRECTION>>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WNDEQTY_LORAN_C
 *    EEC_WNDEQTY_OPTICAL_THEODOLITE
 *    EEC_WNDEQTY_PRESSURE_WITH_WIND
 *    EEC_WNDEQTY_PRESSURE_WITH_WIND_FAILED
 *    EEC_WNDEQTY_RADAR_EQUIPMENT
 *    EEC_WNDEQTY_RADIO_THEODOLITE
 *    EEC_WNDEQTY_SATELLITE
 *    EEC_WNDEQTY_VLF_OMEGA
 *    EEC_WNDEQTY_WIND_PROFILER
 *
 * Group Membership: ATMOSPHERE, DEVICE_AND_EQUIPMENT
 */
#define EAC_WIND_EQUIPMENT_TYPE ((EDCS_Attribute_Code)1614)

/*
 * Definition:
 *     The fraction of historical (climatology) gale force <<WIND_SPEED>>s
 *     (greater than or equal to 17,49 metres per second or equivalently 34
 *     knots).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_GALE_FORCE_RATE_CLIMATOLOGY ((EDCS_Attribute_Code)1615)

/*
 * Definition:
 *     The <<SPEED>> of a sudden, brief increase in <<WIND_SPEED>>; the wind
 *     gust speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_GUST_SPEED ((EDCS_Attribute_Code)1616)

/*
 * Definition:
 *     The difference between adjacent peaks and lulls in <<WIND_SPEED>>; the
 *     wind gust spread.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_GUST_SPREAD ((EDCS_Attribute_Code)1617)

/*
 * Definition:
 *     The vertical rate of movement of <AIR> relative to pressure
 *     coordinates, where downward is positive; the wind omega.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PRESSURE_CHANGE_RATE
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_OMEGA ((EDCS_Attribute_Code)1618)

/*
 * Definition:
 *     The vorticity of <WIND> determined with respect to a system of
 *     coordinates fixed relative to a <PLANETARY_SURFACE>; the wind
 *     relative vorticity.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: ANGULAR_VELOCITY
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_RELATIVE_VORTICITY ((EDCS_Attribute_Code)1619)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the response to the <<WIND_SPEED>> and/or
 *     <<WIND_DIRECTION>> of an <OBJECT>. Zero means no wind response at all
 *     and one means maximum response.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ABSTRACT_OBJECT, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_RESPONSE_FRACTION ((EDCS_Attribute_Code)1620)

/*
 * Definition:
 *     The ratio of the distance covered by moving <AIR> to the
 *     <<TIME_QUANTITY>> taken to cover it; the wind speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED ((EDCS_Attribute_Code)1621)

/*
 * Definition:
 *     The minimum <<WIND_SPEED>> that is greater than 20 percent of the
 *     <<WIND_SPEED_CLIMATOLOGY>>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_20_PERCENTILE_CLIMATOLOGY ((EDCS_Attribute_Code)1622)

/*
 * Definition:
 *     The minimum <<WIND_SPEED>> that is greater than 50 percent of the
 *     <<WIND_SPEED_CLIMATOLOGY>>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_50_PERCENTILE_CLIMATOLOGY ((EDCS_Attribute_Code)1623)

/*
 * Definition:
 *     The minimum <<WIND_SPEED>> that is greater than 80 percent of the
 *     <<WIND_SPEED_CLIMATOLOGY>>s.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_80_PERCENTILE_CLIMATOLOGY ((EDCS_Attribute_Code)1624)

/*
 * Definition:
 *     The mean historical (climatology) <<WIND_SPEED>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_CLIMATOLOGY ((EDCS_Attribute_Code)1625)

/*
 * Definition:
 *     The standard deviation of <<WIND_SPEED_CLIMATOLOGY>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_CLIMATOLOGY_STD_DEV ((EDCS_Attribute_Code)1626)

/*
 * Definition:
 *     The number of reports including values for both <<WIND_SPEED>> and
 *     <<WIND_DIRECTION>>; the wind speed and direction report count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WIND_SPEED_DIRECTION_REPORT_COUNT ((EDCS_Attribute_Code)1627)

/*
 * Definition:
 *     The <<WIND_SPEED>> in the geodetic east-west direction, where east is
 *     positive.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_EAST ((EDCS_Attribute_Code)1628)

/*
 * Definition:
 *     The standard deviation of <<WIND_SPEED_EAST_CLIMATOLOGY>> measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_EAST_CLIM_STD_DEV ((EDCS_Attribute_Code)1629)

/*
 * Definition:
 *     The mean historical (climatology) <<WIND_SPEED_EAST>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_EAST_CLIMATOLOGY ((EDCS_Attribute_Code)1630)

/*
 * Definition:
 *     The error introduced by uncertainties in a measurement of a
 *     <<WIND_SPEED_EAST>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_EAST_ERROR ((EDCS_Attribute_Code)1631)

/*
 * Definition:
 *     The <<WIND_SPEED>> in the geodetic north-south direction, where north
 *     is positive.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_NORTH ((EDCS_Attribute_Code)1632)

/*
 * Definition:
 *     The standard deviation of <<WIND_SPEED_NORTH_CLIMATOLOGY>>
 *     measurements.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_NORTH_CLIM_STD_DEV ((EDCS_Attribute_Code)1633)

/*
 * Definition:
 *     The mean historical (climatology) <<WIND_SPEED_NORTH>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_NORTH_CLIMATOLOGY ((EDCS_Attribute_Code)1634)

/*
 * Definition:
 *     The error introduced by uncertainties in a measurement of a
 *     <<WIND_SPEED_NORTH>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_NORTH_ERROR ((EDCS_Attribute_Code)1635)

/*
 * Definition:
 *     The historical (climatology) <<WIND_SPEED>> categorized by cardinal
 *     vector octant (a 45 arc degree sector centred on a cardinal
 *     direction).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_OCTANT_CLIMATOLOGY ((EDCS_Attribute_Code)1636)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of observations reporting <<WIND_SPEED>>s within a cardinal
 *     vector octant (a 45 arc degree sector centred on a cardinal
 *     <DIRECTION>).
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_OCTANT_FRACTION ((EDCS_Attribute_Code)1637)

/*
 * Definition:
 *     The number of reports including values for <<WIND_SPEED>> only; the
 *     wind speed only count.
 *
 * Value Type: COUNT
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WIND_SPEED_ONLY_COUNT ((EDCS_Attribute_Code)1638)

/*
 * Definition:
 *     The quality of a <<WIND_SPEED>> measurement.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WNDSPDQUAL_ERRONEOUS
 *    EEC_WNDSPDQUAL_GOOD
 *    EEC_WNDSPDQUAL_NO_CHECK
 *    EEC_WNDSPDQUAL_SUSPECT
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WIND_SPEED_QUALITY ((EDCS_Attribute_Code)1639)

/*
 * Definition:
 *     The component of <<WIND_SPEED>> in the X <DIRECTION> of a projected
 *     coordinate system, where +X is positive; the wind speed U.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_U ((EDCS_Attribute_Code)1640)

/*
 * Definition:
 *     The component of <<WIND_SPEED>> in the Y <DIRECTION> of a projected
 *     coordinate system, where +Y is positive; the wind speed V.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_V ((EDCS_Attribute_Code)1641)

/*
 * Definition:
 *     The component of <<WIND_SPEED>> in the Z <DIRECTION> (vertical axis)
 *     of the coordinate system of the measurement, where +Z is positive;
 *     the wind speed W.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_SPEED_W ((EDCS_Attribute_Code)1642)

/*
 * Definition:
 *     The fraction of historical (climatology) <<WIND_SPEED>>s of 2,575
 *     metres per second (five knots) or greater.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_VARIABLE_FRACTION_CLIMATOLOGY ((EDCS_Attribute_Code)1643)

/*
 * Definition:
 *     The magnitude of the vector defined by the
 *     <<WIND_SPEED_EAST_CLIMATOLOGY>> and the
 *     <<WIND_SPEED_NORTH_CLIMATOLOGY>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_WIND_VECTOR_SPEED_CLIMATOLOGY ((EDCS_Attribute_Code)1644)

/*
 * Definition:
 *     The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which <WIND_WAVE>s
 *     are arriving.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ANGULAR_MEASURE, WATERBODY_SURFACE
 */
#define EAC_WIND_WAVE_DIRECTION ((EDCS_Attribute_Code)1645)

/*
 * Definition:
 *     The <<HEIGHT>> measured vertically from the trough to the crest of a
 *     <WIND_WAVE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, WATERBODY_SURFACE
 */
#define EAC_WIND_WAVE_HEIGHT ((EDCS_Attribute_Code)1646)

/*
 * Definition:
 *     The mean <<TIME_QUANTITY>> a complete cycle (usually crest to crest or
 *     trough to trough) of a <WIND_WAVE> takes to pass a given <LOCATION>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME, WATERBODY_SURFACE
 */
#define EAC_WIND_WAVE_PERIOD ((EDCS_Attribute_Code)1647)

/*
 * Definition:
 *     The type of <MATERIAL> filling the <APERTURE> of a <WINDOW>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WNDWMATTY_ACRYLIC_PLASTIC
 *    EEC_WNDWMATTY_FROSTED_GLASS
 *    EEC_WNDWMATTY_LAMINATED_GLASS
 *    EEC_WNDWMATTY_NONE
 *    EEC_WNDWMATTY_REFLECTIVE_GLASS
 *    EEC_WNDWMATTY_TEMPERED_GLASS
 *    EEC_WNDWMATTY_TINTED_GLASS
 *    EEC_WNDWMATTY_UNTEMPERED_GLASS
 *    EEC_WNDWMATTY_WIRE_GLASS
 *    EEC_WNDWMATTY_FIBREGLASS
 *    EEC_WNDWMATTY_KEVLAR
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_WINDOW_MATERIAL_TYPE ((EDCS_Attribute_Code)1648)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fractional canopy cover of <TREE>s during the winter within a
 *     delineated <REGION> of <LAND>. Zero means no cover and one means
 *     completely covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIVING_ORGANISM, PLANT, RATE_OR_RATIO, TIME
 */
#define EAC_WINTER_CANOPY_COVER_FRACTION ((EDCS_Attribute_Code)1649)

/*
 * Definition:
 *     The number of <WIRE>s associated with a <STRUCTURE> (for example: a
 *     <POWER_TRANSMISSION_LINE> and/or a <POWER_TRANSMISSION_LINE_PYLON>);
 *     the wire count.
 *
 * Value Type: COUNT
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_WIRE_COUNT ((EDCS_Attribute_Code)1650)

/*
 * Definition:
 *     An indication that an <APERTURE> is covered with a mesh of <WIRE>s;
 *     wire mesh covered.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_WIRE_MESH_COVERED ((EDCS_Attribute_Code)1651)

/*
 * Definition:
 *     The number of strands comprising a <WIRE_OBSTACLE>; the wire strand
 *     count.
 *
 * Value Type: COUNT
 *
 * Group Membership: TRNSP
 */
#define EAC_WIRE_STRAND_COUNT ((EDCS_Attribute_Code)1652)

/*
 * Definition:
 *     The WMO identifier number for a <WEATHER_STATION>; formatted in a
 *     Basic Latin string as specified by [WMO9A, "Record Layout of the
 *     Station Data File", field 5].
 *
 * Value Type: CONSTRAINED_STRING
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_WMO_STATION_IDENTIFIER ((EDCS_Attribute_Code)1653)

/*
 * Definition:
 *     A number between 0 and 1 inclusive representing the linearly-scaled
 *     fraction of the <TERRAIN> that is covered by woody <VEGETATION>
 *     within a delineated <TRACT>; the woody vegetation density. Zero means
 *     no woody <VEGETATION> is present and one means the <TRACT> is
 *     completely covered.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: LIVING_ORGANISM, PLANT, RATE_OR_RATIO, TIME
 */
#define EAC_WOODY_VEGETATION_DENSITY ((EDCS_Attribute_Code)1654)

/*
 * Definition:
 *     The type of work in progress.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WRKINPROGTY_LAND_RECLAMATION
 *    EEC_WRKINPROGTY_STRUCTURE_CONSTRUCTION
 *
 * Group Membership: INDUSTRY, USAGE_REGION
 */
#define EAC_WORK_IN_PROGRESS_TYPE ((EDCS_Attribute_Code)1655)

/*
 * Definition:
 *     The type of a <WORSHIP_PLACE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WORSHIPPLACETY_BUDDHIST_TEMPLE
 *    EEC_WORSHIPPLACETY_CATHEDRAL
 *    EEC_WORSHIPPLACETY_CATHOLIC_CATHEDRAL
 *    EEC_WORSHIPPLACETY_CHAPEL
 *    EEC_WORSHIPPLACETY_CHRISTIAN_TEMPLE
 *    EEC_WORSHIPPLACETY_CHURCH
 *    EEC_WORSHIPPLACETY_CONVENT
 *    EEC_WORSHIPPLACETY_HINDU_TEMPLE
 *    EEC_WORSHIPPLACETY_MARABOUT
 *    EEC_WORSHIPPLACETY_MINARET
 *    EEC_WORSHIPPLACETY_MISSION
 *    EEC_WORSHIPPLACETY_MONASTERY
 *    EEC_WORSHIPPLACETY_MORMON_TEMPLE
 *    EEC_WORSHIPPLACETY_MOSQUE
 *    EEC_WORSHIPPLACETY_PAGODA
 *    EEC_WORSHIPPLACETY_RELIGIOUS_COMMUNITY
 *    EEC_WORSHIPPLACETY_SHRINE
 *    EEC_WORSHIPPLACETY_STUPA
 *    EEC_WORSHIPPLACETY_SYNAGOGUE
 *    EEC_WORSHIPPLACETY_TABERNACLE
 *    EEC_WORSHIPPLACETY_UNSPECIFIED
 *
 * Group Membership: RELIGION
 */
#define EAC_WORSHIP_PLACE_TYPE ((EDCS_Attribute_Code)1656)

/*
 * Definition:
 *     The angular distance measured in the local horizontal plane about the
 *     local vertical axis from planetary geodetic north counter clockwise
 *     (viewed from above) to the forward axis of an <OBJECT>; the yaw
 *     angle. The forward axis of the <OBJECT> is the axis that passes
 *     through the <OBJECT> centre and is directed towards the forward part
 *     or <SURFACE> (front) of the <OBJECT>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PLANE_ANGLE
 *
 * Group Membership: ABSTRACT_OBJECT, ANGULAR_MEASURE
 */
#define EAC_YAW_ANGLE ((EDCS_Attribute_Code)1657)

/*
 * Definition:
 *     The<<TIME_QUANTITY>> as measured by the Gregorian calendar in whole
 *     years since the beginning of the Common Era.
 *
 * Value Type: INTEGER
 *
 * Group Membership: TIME
 */
#define EAC_YEAR_COMMON_ERA ((EDCS_Attribute_Code)1658)

/*
 * Definition:
 *     The designation of a <NON_EMPTY_SET> of closely related Zoroastrian
 *     religious denominations, often ones which were at one time part of a
 *     single movement but are now separate religious denominations; the
 *     Zoroastrianism denominational family.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_ZORDENOMFAM_PARSI
 *
 * Group Membership: RELIGION
 */
#define EAC_ZOROASTRIANISM_DENOMINATIONAL_FAMILY ((EDCS_Attribute_Code)1659)

/*
 * Definition:
 *     Indication that a physical <OBJECT> is breached [SOED, "breach", B].
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_BREACHED ((EDCS_Attribute_Code)1660)

/*
 * Definition:
 *     Indication that a physical <OBJECT> is buoyant [SOED, "buoyant"].
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_BUOYANT ((EDCS_Attribute_Code)1661)

/*
 * Definition:
 *     The shape of a <DOOR>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_DOORSHAP_ARCHED
 *    EEC_DOORSHAP_RECTANGULAR
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_DOOR_SHAPE ((EDCS_Attribute_Code)1662)

/*
 * Definition:
 *     The vertical displacement of the bottom of an <ELEVATED_EM_DUCT> from
 *     a <SURFACE_DATUM> identified by an <<ATM_VERTICAL_REFERENCE>>; the
 *     elevated duct layer bottom.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, LOCATION
 */
#define EAC_ELEVATED_EM_DUCT_BOTTOM ((EDCS_Attribute_Code)1663)

/*
 * Definition:
 *     The vertical displacement of the top of an <ELEVATED_EM_DUCT> from a
 *     <SURFACE_DATUM> identified by an <<ATM_VERTICAL_REFERENCE>>; the
 *     elevated duct layer top.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, LOCATION
 */
#define EAC_ELEVATED_EM_DUCT_TOP ((EDCS_Attribute_Code)1664)

/*
 * Definition:
 *     The strength of an <ELEVATED_EM_DUCT> as defined by the difference
 *     between the maximum and minimum <<RF_REFRACTIVE_INDEX_MODIFIED>> of
 *     the duct layer.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define EAC_ELEVATED_EM_DUCT_STRENGTH ((EDCS_Attribute_Code)1665)

/*
 * Definition:
 *     The mean vertical distance from <FLOOR> to <ROOM_CEILING> of a
 *     compartment in a <BUILDING> (for example: a <ROOM> or a
 *     <FLOOR_CRAWL_SPACE>); the enclosure mean height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: BUILDING_COMPONENT, DIMENSION
 */
#define EAC_ENCLOSURE_MEAN_HEIGHT ((EDCS_Attribute_Code)1666)

/*
 * Definition:
 *     Indication that a <WATERBODY> is fordable.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LAND_TRNSP, TRNSP, WATERBODY_STATE
 */
#define EAC_FORDABLE ((EDCS_Attribute_Code)1667)

/*
 * Definition:
 *     Indication that the <<TEMPERATURE>> of a <MAN_MADE_OBJECT> is being
 *     influenced by an internal heat source.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: TEMPERATURE
 */
#define EAC_INTERNALLY_HEATED ((EDCS_Attribute_Code)1668)

/*
 * Definition:
 *     The <<DEPTH_BELOW_WATERBODY_SURFACE>> at which a <SECCHI_DISK>
 *     disappears from view for an observer located above the
 *     <WATERBODY_SURFACE>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: HYDROLOGY, WATERBODY_STATE
 */
#define EAC_SECCHI_DEPTH ((EDCS_Attribute_Code)1669)

/*
 * Definition:
 *     The vertical distance to the base of a
 *     <POTENTIAL_TEMPERATURE_INVERSION_LAYER> from a reference <SURFACE>
 *     identified by an <<ATM_VERTICAL_REFERENCE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION, TEMPERATURE
 */
#define EAC_POTENTIAL_TEMPERATURE_BASE_INVERSION_LAYER ((EDCS_Attribute_Code)1670)

/*
 * Definition:
 *     The vertical distance to the top of a
 *     <POTENTIAL_TEMPERATURE_INVERSION_LAYER> from a reference <SURFACE>
 *     identified by an <<ATM_VERTICAL_REFERENCE>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE, LOCATION, TEMPERATURE
 */
#define EAC_POTENTIAL_TEMPERATURE_TOP_INVERSION_LAYER ((EDCS_Attribute_Code)1671)

/*
 * Definition:
 *     The <<POTENTIAL_TEMPERATURE_LAPSE_RATE>> in a
 *     <POTENTIAL_TEMPERATURE_INVERSION_LAYER>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define EAC_POTENTIAL_TEMP_INVRSN_LAYER_LAPSE_RATE ((EDCS_Attribute_Code)1672)

/*
 * Definition:
 *     The rate of change of the <<POTENTIAL_AIR_TEMPERATURE>> as a function
 *     of <<HEIGHT_AGL>>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LINEIC_THERMO_TEMP_GRADIENT
 *
 * Group Membership: ATMOSPHERE, RATE_OR_RATIO, TEMPERATURE
 */
#define EAC_POTENTIAL_TEMPERATURE_LAPSE_RATE ((EDCS_Attribute_Code)1673)

/*
 * Definition:
 *     The non-dimensional ratio of the kinematic viscosity to the thermal
 *     diffusivity, usually about 1 for the atmosphere and about 7 for
 *     water; the Prandtl number.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: FLUID_CONDITION, RATE_OR_RATIO
 */
#define EAC_PRANDTL_NUMBER ((EDCS_Attribute_Code)1674)

/*
 * Definition:
 *     The non-dimensional ratio of the internal force to the force of
 *     gravity for fluid flow given by the ratio of the fluid velocity to
 *     the square root of the product of gravitational acceleration and the
 *     characteristic length; Froude number type 1.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: FLUID_CONDITION, RATE_OR_RATIO
 */
#define EAC_FROUDE_NUMBER_TYPE_1 ((EDCS_Attribute_Code)1675)

/*
 * Definition:
 *     The non-dimensional ratio of the internal force to the force of
 *     gravity for fluid flow. It is equal to the square of
 *     <<FROUDE_NUMBER_TYPE_1>>; Froude number type 2.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: FLUID_CONDITION, RATE_OR_RATIO
 */
#define EAC_FROUDE_NUMBER_TYPE_2 ((EDCS_Attribute_Code)1676)

/*
 * Definition:
 *     A modified Froude number used for atmospheric flows over <HILL>s or
 *     other obstacles given by the non-dimensional ratio of the fluid speed
 *     to the product of Brunt-Vaisala frequency and a characteristic
 *     length; internal Froude number atmospheric.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: FLUID_CONDITION, RATE_OR_RATIO
 */
#define EAC_INTERNAL_FROUDE_NUMBER_ATM ((EDCS_Attribute_Code)1677)

/*
 * Definition:
 *     A non-dimensional number arising from the study of shearing flows of a
 *     stratified fluid defined as the product of the acceleration of
 *     gravity and a measure of the vertical stability, divided by the
 *     square of the vertical shear; Richardson number.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: FLUID_CONDITION, RATE_OR_RATIO
 */
#define EAC_RICHARDSON_NUMBER ((EDCS_Attribute_Code)1678)

/*
 * Definition:
 *     A form of the <<RICHARDSON_NUMBER>> expressed using gradients.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: FLUID_CONDITION, RATE_OR_RATIO
 */
#define EAC_GRADIENT_RICHARDSON_NUMBER ((EDCS_Attribute_Code)1679)

/*
 * Definition:
 *     An estimate of the <<GRADIENT_RICHARDSON_NUMBER>> formed by
 *     approximating local gradients by finite difference across layers;
 *     bulk Richardson number.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: PURE_NUMBER
 *
 * Group Membership: FLUID_CONDITION, RATE_OR_RATIO
 */
#define EAC_BULK_RICHARDSON_NUMBER ((EDCS_Attribute_Code)1680)

/*
 * Definition:
 *     The height above the displacement plane at which the
 *     <<MEAN_WIND_SPEED>> becomes zero when extrapolating the logarithmic
 *     wind-speed profile downward through the atmospheric surface layer;
 *     aerodynamic roughness length.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: ATMOSPHERE
 */
#define EAC_AERODYNAMIC_ROUGHNESS_LENGTH ((EDCS_Attribute_Code)1681)

/*
 * Definition:
 *     The <<TIME_QUANTITY>> that an <OBJECT> (e.g. a <MINEFIELD> or
 *     <STREET_LAMP>) is active; active duration.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: TIME
 *
 * Group Membership: TIME
 */
#define EAC_ACTIVE_DURATION ((EDCS_Attribute_Code)1682)

/*
 * Definition:
 *     The <<SOUND_SPEED>> in <AIR>.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, ATMOSPHERE, RATE_OR_RATIO
 */
#define EAC_AIR_SOUND_SPEED ((EDCS_Attribute_Code)1683)

/*
 * Definition:
 *     Indication that a <BREACH> has been marked.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_BREACH_MARKED ((EDCS_Attribute_Code)1684)

/*
 * Definition:
 *     A <GROUND_VEHICLE> that has the capability to transport a
 *     <BRIDGE_SPAN>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BRIDGESPANTVTY_LEOPARD
 *    EEC_BRIDGESPANTVTY_M1A1
 *    EEC_BRIDGESPANTVTY_M60A1
 *    EEC_BRIDGESPANTVTY_MTU20
 *    EEC_BRIDGESPANTVTY_TRUCK
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_BRIDGE_SPAN_TRANSPORT_VEHICLE_TYPE ((EDCS_Attribute_Code)1685)

/*
 * Definition:
 *     The number of platoons with associated <EQUIPMENT> that can added to a
 *     <DEFENSIVE_POSITION> at the current time. This is equal to the
 *     <<PLATOON_ACCOMODATION_CAPACITY>> of the <DEFENSIVE_POSITION> minus
 *     the number of platoons that are currently in the
 *     <DEFENSIVE_POSITION>; platoon accomodation availability count.
 *
 * Value Type: COUNT
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_PLATOON_ACCOMMODATION_AVAILABILITY_COUNT ((EDCS_Attribute_Code)1686)

/*
 * Definition:
 *     Defines a <FIGHTING_POSITION> as primary, alternate, or supplementary.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_FIGHTINGPOSTY_ALTERNATE
 *    EEC_FIGHTINGPOSTY_PRIMARY
 *    EEC_FIGHTINGPOSTY_SUPPLEMENTARY
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_FIGHTING_POSITION_TYPE ((EDCS_Attribute_Code)1687)

/*
 * Definition:
 *     The type of <SENSOR>s in a security system.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SECUSYSTY_ALARM_SCREEN
 *    EEC_SECUSYSTY_AUDIO_DETECTOR
 *    EEC_SECUSYSTY_DOOR_SWITCH
 *    EEC_SECUSYSTY_MOTION_SENSOR
 *    EEC_SECUSYSTY_PRESSURE_PAD
 *    EEC_SECUSYSTY_VIBRATION_SENSOR
 *    EEC_SECUSYSTY_WINDOW_FOIL
 *    EEC_SECUSYSTY_HEAT_SENSOR
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define EAC_SECURITY_SYSTEM_TYPE ((EDCS_Attribute_Code)1688)

/*
 * Definition:
 *     The <<SPEED>> at which sound passes through a medium, depending on the
 *     <<TEMPERATURE>> and other properties of the medium; sound speed.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: ACOUSTIC_PHENOMENON, RATE_OR_RATIO
 */
#define EAC_SOUND_SPEED ((EDCS_Attribute_Code)1689)

/*
 * Definition:
 *     The type of <MATERIAL> and/or techniques used to construct a <WALL>;
 *     wall construction type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WALLCNSTCTTY_CONCRETE
 *    EEC_WALLCNSTCTTY_GLASS
 *    EEC_WALLCNSTCTTY_GYPSUM_ON_METAL
 *    EEC_WALLCNSTCTTY_GYPSUM_ON_WOOD
 *    EEC_WALLCNSTCTTY_HOLLOW_CONCRETE_BLOCK
 *    EEC_WALLCNSTCTTY_HOLLOW_FIRED_CLAY_BLOCK
 *    EEC_WALLCNSTCTTY_LATH_PLASTER
 *    EEC_WALLCNSTCTTY_MASONRY
 *    EEC_WALLCNSTCTTY_PREFABRICATED_CONCRETE_TILT_UP
 *    EEC_WALLCNSTCTTY_REINFORCED_CONCRETE
 *    EEC_WALLCNSTCTTY_SANDBAGS
 *    EEC_WALLCNSTCTTY_WOOD_PRODUCT
 *    EEC_WALLCNSTCTTY_CORRUGATED_STEEL
 *    EEC_WALLCNSTCTTY_STEEL_STUDS_WITH_STUCCO
 *
 * Group Membership: BUILDING_COMPONENT, MATERIAL
 */
#define EAC_WALL_CONSTRUCTION_TYPE ((EDCS_Attribute_Code)1690)

/*
 * Definition:
 *     Indication that a physical <OBJECT> is anchored, sometimes by use of
 *     an <ANCHOR>.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define EAC_ANCHORED ((EDCS_Attribute_Code)1691)

/*
 * Definition:
 *     A textual identifier for a military or civilian force, e.g. platoon,
 *     squadron, disorderly crowd, emergency services unit, police; force
 *     identifier.
 *
 * Value Type: STRING
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define EAC_FORCE_IDENTIFIER ((EDCS_Attribute_Code)1692)

/*
 * Definition:
 *     The type of a <BUS_STOP>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BUSSTPTY_PUBLIC_TRANSIT
 *    EEC_BUSSTPTY_SCHOOL
 *
 * Group Membership: LAND_TRNSP, LOCATION, TRNSP
 */
#define EAC_BUS_STOP_TYPE ((EDCS_Attribute_Code)1693)

/*
 * Definition:
 *     The vertical distance from crest top to trough bottom of a corrugated
 *     <SURFACE>; corrugation depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION
 */
#define EAC_CORRUGATION_DEPTH ((EDCS_Attribute_Code)1694)

/*
 * Definition:
 *     The <<WIDTH>> of one period of the corrugation wave in a corrugated
 *     <SURFACE>; corrugation pitch.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION
 */
#define EAC_CORRUGATION_PITCH ((EDCS_Attribute_Code)1695)

/*
 * Definition:
 *     The vertical distance from the top of the <CURB> to the <SURFACE> of a
 *     <LAND_TRANSPORTATION_ROUTE>; curb height.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, TRNSP
 */
#define EAC_CURB_HEIGHT ((EDCS_Attribute_Code)1696)

/*
 * Definition:
 *     The type of a <CURB>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_CRBTY_INCLINED
 *    EEC_CRBTY_NONE
 *    EEC_CRBTY_ROUNDED
 *    EEC_CRBTY_SQUARED
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_CURB_TYPE ((EDCS_Attribute_Code)1697)

/*
 * Definition:
 *     The type of the internal covering of a <WINDOW>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_INTWNDWCVRG_CURTAIN
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_INTERIOR_WINDOW_COVERING ((EDCS_Attribute_Code)1698)

/*
 * Definition:
 *     The type of a <MAILBOX>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_MLBXTY_COMMERCIAL
 *    EEC_MLBXTY_PRIVATE_ROADSIDE
 *    EEC_MLBXTY_PUBLIC
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define EAC_MAILBOX_TYPE ((EDCS_Attribute_Code)1699)

/*
 * Definition:
 *     An indication that parking spaces in the designated <TRACT> have
 *     <PARKING_METER>s; metered parking.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define EAC_METERED_PARKING ((EDCS_Attribute_Code)1700)

/*
 * Definition:
 *     The type of <MATERIAL> used to construct a <PIPE>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_PIPCNSTRNMATTY_ABS_PLASTIC
 *    EEC_PIPCNSTRNMATTY_CAST_IRON
 *    EEC_PIPCNSTRNMATTY_COPPER
 *    EEC_PIPCNSTRNMATTY_PVC
 *
 * Group Membership: INFRASTRUCTURE, MATERIAL
 */
#define EAC_PIPE_CONSTRUCTION_MATERIAL_TYPE ((EDCS_Attribute_Code)1701)

/*
 * Definition:
 *     An indication that a <STRUCTURE> is reinforced for support.
 *
 * Value Type: BOOLEAN
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define EAC_REINFORCED ((EDCS_Attribute_Code)1702)

/*
 * Definition:
 *     That portion of the <<WIDTH>> of a <ROAD> that is illuminated.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, LAND_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define EAC_ROAD_ILLUMINATED_WIDTH ((EDCS_Attribute_Code)1703)

/*
 * Definition:
 *     The shape of a <ROOM_CEILING>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_RMCLNGSHP_ARCHED
 *    EEC_RMCLNGSHP_FLAT
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_ROOM_CEILING_SHAPE ((EDCS_Attribute_Code)1704)

/*
 * Definition:
 *     The type of a <SEWER>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_SWRTY_COMBINED
 *    EEC_SWRTY_SANITARY
 *    EEC_SWRTY_STORM
 *
 * Group Membership: INFRASTRUCTURE
 */
#define EAC_SEWER_TYPE ((EDCS_Attribute_Code)1705)

/*
 * Definition:
 *     The dimension of the cross-section of a <WALL_STUD> that is
 *     perpendicular to the <SURFACE> of the associated <WALL>; wall stud
 *     depth.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: LENGTH
 *
 * Group Membership: DIMENSION, SUPPORT_STRUCTURE
 */
#define EAC_WALL_STUD_DEPTH ((EDCS_Attribute_Code)1706)

/*
 * Definition:
 *     The maximum sustainable stress in a <MATERIAL> under elongation
 *     stress; tensile strength [SOED, "tensile strength"].
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: MOMENTUM
 *
 * Group Membership: MATERIAL
 */
#define EAC_TENSILE_STRENGTH ((EDCS_Attribute_Code)1707)

/*
 * Definition:
 *     The <<FLOOR_LEVEL_IDENTIFIER>> of the top <FLOOR_LEVEL> of a
 *     <BUILDING>, where top <FLOOR_LEVEL> excludes the <ROOF> unless a
 *     penthouse is situated on the <ROOF>.
 *
 * Value Type: INDEX
 *
 * Group Membership: BUILDING_COMPONENT, IDENTIFICATION
 */
#define EAC_TOP_FLOOR_LEVEL_IDENTIFIER ((EDCS_Attribute_Code)1708)

/*
 * Definition:
 *     The method by which a <TRAFFIC_LIGHT> is mounted to a
 *     <TRAFFIC_LIGHT_POLE>; traffic light mount type.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TRFCLGTMNTTY_SIDE_BRACKET
 *    EEC_TRFCLGTMNTTY_LOAD_CABLE
 *    EEC_TRFCLGTMNTTY_PEDESTAL
 *    EEC_TRFCLGTMNTTY_STEEL_MAST_ARM
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, SUPPORT_STRUCTURE
 */
#define EAC_TRAFFIC_LIGHT_MOUNT_TYPE ((EDCS_Attribute_Code)1709)

/*
 * Definition:
 *     The type of a <TRAFFIC_LIGHT>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_TRFCLGTTY_SINGLE_LIGHT
 *    EEC_TRFCLGTTY_SPLIT_TRIPLE
 *    EEC_TRFCLGTTY_TRIPLE_LIGHT
 *    EEC_TRFCLGTTY_TRIPLE_TURN_LIGHT
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, LAND_TRNSP, TRNSP
 */
#define EAC_TRAFFIC_LIGHT_TYPE ((EDCS_Attribute_Code)1710)

/*
 * Definition:
 *     The minimum <<SPEED>> legally permitted on a given stretch of a
 *     <TRANSPORTATION_ROUTE>; the vehicular minimum speed limit.
 *
 * Value Type: REAL
 *
 * Unit Equivalence Class: SPEED
 *
 * Group Membership: LAND_TRNSP, RATE_OR_RATIO, TRNSP
 */
#define EAC_VEHICULAR_MINIMUM_SPEED_LIMIT ((EDCS_Attribute_Code)1711)

/*
 * Definition:
 *     The type of a <WINDOW> based on the manner in which it operates.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_WNDWTY_AWNING
 *    EEC_WNDWTY_CASEMENT
 *    EEC_WNDWTY_DOUBLE_HUNG
 *    EEC_WNDWTY_FIXED
 *    EEC_WNDWTY_HORIZONTAL_SLIDING
 *    EEC_WNDWTY_PIVOTED
 *    EEC_WNDWTY_SINGLE_HUNG
 *
 * Group Membership: BUILDING_COMPONENT, LIGHTING_AND_VISIBILITY
 */
#define EAC_WINDOW_TYPE ((EDCS_Attribute_Code)1712)

/*
 * Definition:
 *     The configuration of a <BALCONY>.
 *
 * Value Type: ENUMERATION
 *
 * Possible Enumerators:
 *    EEC_BALCCONFIG_INDIVIDUAL
 *    EEC_BALCCONFIG_WRAP_AROUND
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define EAC_BALCONY_CONFIGURATION ((EDCS_Attribute_Code)1713)

/*
 * Definition:
 *     The <<FLOOR_LEVEL_IDENTIFIER>> of the bottom <FLOOR_LEVEL> of a
 *     <BUILDING>, where bottom <FLOOR_LEVEL> includes any <BASEMENT>s
 *     and/or <PARKING_GARAGE>s.
 *
 * Value Type: INDEX
 *
 * Group Membership: BUILDING_COMPONENT, IDENTIFICATION
 */
#define EAC_BOTTOM_FLOOR_LEVEL_IDENTIFIER ((EDCS_Attribute_Code)1714)

#ifdef __cplusplus
}
#endif

#endif
