/*
 * FILE       : edcs_class_dict.h
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all ECs.
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

#ifndef _EDCS_CLASS_DICT_H_INCLUDED_
#define _EDCS_CLASS_DICT_H_INCLUDED_

#include "edcs_types.h"

#define EDCS_TOTAL_EC 1479

/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetECDictionaryEntry
 *
 *   Retrieves dictionary information for the specified EC code.
 *
 * PARAMETERS:
 *
 *   ec_code_in -- The EC code whose dictionary entry is being requested
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
 *   EDCS_SC_INVALID_INPUT_CODE - and no changes are made, if ec_code_in
 *       does not correspond to a valid EC.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetECDictionaryEntry
(
          EDCS_Classification_Code               ec_code_in,
    const EDCS_Classification_Dictionary_Entry **result_out_ptr
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToECCode
 *
 *   Retrieves the EC code corresponding to the given label.
 *
 * PARAMETERS:
 *
 *   ec_label_in_ptr -- The label for which the corresponding EC code is
 *        requested; note that this is the abstract label (i.e., corresponds
 *        to the abstract EDCS specification)
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
 *   EDCS_SC_INVALID_INPUT_LABEL - and no changes are made, if *ec_label_in_ptr
 *       does not correspond to a valid EC.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_LabelToECCode
(
    const EDCS_Character            *ec_label_in_ptr,
          EDCS_Classification_Code  *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToECCode
 *
 *   Retrieves the EC code corresponding to the given symbolic constant name.
 *
 * PARAMETERS:
 *
 *   ec_symbolic_constant_in_ptr -- the symbolic constant for which the
 *        corresponding EC code is requested; note that this is the
 *        language-binding symbolic constant name, rather than the abstract
 *        label (i.e., corresponds to the C language binding standard rather
 *        than the abstract EDCS specification)
 *
 *   result_out_ptr -- pointer to a variable in the user's memory into which
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
 *   EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT - and no changes are made, if
 *       *ec_symbolic_constant_in_ptr does not correspond to a valid EC.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_SymbolicConstantToECCode
(
    const EDCS_Character            *ec_symbolic_constant_in_ptr,
          EDCS_Classification_Code  *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidClassificationCode
 *
 *   Indicates if the given EC code is a valid EDCS Classification Code.
 *
 * PARAMETERS:
 *
 *   ec_code_in -- The EC code whose validity is being checked.
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if a valid EC code was passed in.
 *
 *   EDCS_FALSE - if a non-valid EC code was passed in.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidClassificationCode
(
    EDCS_Classification_Code ec_code_in
);

/*
 * Definition:
 *     A defence constructed by placing felled <TREE>s lengthwise one over
 *     the other with their branches towards the enemy's line; an abatis
 *     [SOED, "abatis"].
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_ABATIS ((EDCS_Classification_Code)1)

/*
 * Definition:
 *     A <WATERBODY_FLOOR> with <<DEPTH_OF_WATERBODY_FLOOR>> greater than 549
 *     metres (approximately 1 800 feet); an abyss.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_ABYSS ((EDCS_Classification_Code)2)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> between a <CONTACT_ZONE> and the first
 *     passable <LAND_TRANSPORTATION_ROUTE>; an access zone.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_ACCESS_ZONE ((EDCS_Classification_Code)3)

/*
 * Definition:
 *     A <DEVICE> used for the collection of acoustic data.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, DEVICE_AND_EQUIPMENT
 */
#define ECC_ACOUSTIC_DATA_COLLECTION_DEVICE ((EDCS_Classification_Code)4)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the sound spectrum of an acoustic source
 *     and/or emitter; an acoustic signature property set.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, PROPERTY_SET
 */
#define ECC_ACOUSTIC_SIGNATURE_PROPERTY_SET ((EDCS_Classification_Code)5)

/*
 * Definition:
 *     An <ACOUSTIC_DATA_COLLECTION_DEVICE> and support <STRUCTURE>s; an
 *     acoustic station.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, DEVICE_AND_EQUIPMENT
 */
#define ECC_ACOUSTIC_STATION ((EDCS_Classification_Code)6)

/*
 * Definition:
 *     A <DEVICE> to transform acoustic energy to and/or from electrical
 *     energy; an acoustic transducer.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, DEVICE_AND_EQUIPMENT, EM_PHENOMENON
 */
#define ECC_ACOUSTIC_TRANSDUCER ((EDCS_Classification_Code)7)

/*
 * Definition:
 *     A <BUILDING> devoted to the act and/or process of administration or
 *     management.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_ADMINISTRATION_BUILDING ((EDCS_Classification_Code)8)

/*
 * Definition:
 *     A <BOUNDARY> between administratively controlled <REGION>s.
 *
 * Group Membership: ADMINISTRATION, DEMARCATION, LOCATION
 */
#define ECC_ADMINISTRATIVE_BOUNDARY ((EDCS_Classification_Code)9)

/*
 * Definition:
 *     A <REGION> controlled by an administrative authority.
 *
 * Group Membership: ADMINISTRATION
 */
#define ECC_ADMINISTRATIVE_REGION ((EDCS_Classification_Code)10)

/*
 * Definition:
 *     A <STRUCTURE> for aerating <WATER> by either passing <AIR> through
 *     <WATER> or passing <WATER> through <AIR>.
 *
 * Group Membership: INFRASTRUCTURE, SUPPORT_STRUCTURE
 */
#define ECC_AERATION_STRUCTURE ((EDCS_Classification_Code)11)

/*
 * Definition:
 *     A <DEVICE> used to transmit and/or receive electromagnetic energy; an
 *     aerial [SOED, "aerial", B].
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_AERIAL ((EDCS_Classification_Code)12)

/*
 * Definition:
 *     A <LOAD_CABLE> that is strung between <AERIAL_CABLE_PYLON>s as a
 *     <COMPONENT> of a <CONVEYOR> on which carrier units (for example: cars
 *     and/or buckets) are suspended; an aerial cable.
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_AERIAL_CABLE ((EDCS_Classification_Code)13)

/*
 * Definition:
 *     A <PYLON> supporting an <AERIAL_CABLE>; an aerial cable pylon.
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_AERIAL_CABLE_PYLON ((EDCS_Classification_Code)14)

/*
 * Definition:
 *     A <SET> of one or more <AERIAL_CABLE>s.
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_AERIAL_CABLE_SET ((EDCS_Classification_Code)15)

/*
 * Definition:
 *     A <MAST> supporting an <AERIAL>.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE, SUPPORT_STRUCTURE
 */
#define ECC_AERIAL_SUPPORT_MAST ((EDCS_Classification_Code)16)

/*
 * Definition:
 *     A defined <TRACT> or <WATERBODY_SURFACE_REGION> (including
 *     <BUILDING>s, <FACILITY>s, and/or <EQUIPMENT>) intended to be used
 *     either wholly or in part for the arrival, departure, and movement of
 *     <AIRCRAFT> on a <PLANETARY_SURFACE>; an aerodrome.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_AERODROME ((EDCS_Classification_Code)17)

/*
 * Definition:
 *     The highest <LOCATION> of the usable <RUNWAY>s of an <AERODROME>
 *     measured with respect to a <SURFACE_DATUM>; an aerodrome elevation
 *     point.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_AERODROME_ELEVATION_POINT ((EDCS_Classification_Code)18)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <LIGHT>s used to: define and outline <COMPONENT>s
 *     of <AERODROME>s such as perimeters, <RUNWAY>s, and <TAXIWAY>s; guide
 *     <AIRCRAFT> while on a <PLANETARY_SURFACE>; and provide guidance to
 *     <AIRCRAFT> on approach for landing.
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_AERODROME_LIGHTING ((EDCS_Classification_Code)19)

/*
 * Definition:
 *     A <REVETMENT> at an <AERODROME>.
 *
 * Group Membership: AIR_TRNSP, SHELTER, TRNSP
 */
#define ECC_AERODROME_REVETMENT ((EDCS_Classification_Code)20)

/*
 * Definition:
 *     A <BUILDING> located at an <AERODROME> used for disembarking and/or
 *     taking on passengers or <CARGO>; an aerodrome terminal.
 *
 * Group Membership: AIR_TRNSP, SHELTER, TRNSP
 */
#define ECC_AERODROME_TERMINAL ((EDCS_Classification_Code)21)

/*
 * Definition:
 *     An aeronautical <AID_TO_NAVIGATION>.
 *
 * Group Membership: AIR_TRNSP, DEVICE_AND_EQUIPMENT, TRNSP
 */
#define ECC_AERONAUTICAL_AID_TO_NAVIGATION ((EDCS_Classification_Code)22)

/*
 * Definition:
 *     A <FACILITY> supporting an <AERONAUTICAL_COMM_SERVICE>.
 *
 * Group Membership: AIR_TRNSP, COMMUNICATION, INFRASTRUCTURE, TRNSP
 */
#define ECC_AERONAUTICAL_COMM_FACILITY ((EDCS_Classification_Code)23)

/*
 * Definition:
 *     A telecommunication service that supports aviation; an aeronautical
 *     communication service.
 *
 * Group Membership: AIR_TRNSP, COMMUNICATION, TRNSP
 */
#define ECC_AERONAUTICAL_COMM_SERVICE ((EDCS_Classification_Code)24)

/*
 * Definition:
 *     A <DIRECTION> that provides at least 3 218,7 metres (2 miles) of lead
 *     to assist in turning an <AIRCRAFT> onto the intermediate portion of
 *     an instrument approach when the angle of intercept is greater than 90
 *     arc degrees; an aeronautical lead radial.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_AERONAUTICAL_LEAD_RADIAL ((EDCS_Classification_Code)25)

/*
 * Definition:
 *     A colloidal <SYSTEM> in which the dispersed phase is composed of
 *     either solid or liquid <PARTICLE>s and the dispersion medium is a
 *     gas, usually <AIR>; an aerosol.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_AEROSOL ((EDCS_Classification_Code)26)

/*
 * Definition:
 *     A <FACILITY> involved in crop production, the raising of livestock,
 *     and/or the storage or transportation of either <MATERIAL>s important
 *     to or the results of agricultural production.
 *
 * Group Membership: AGRICULTURE, ANIMAL, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_AGRICULTURAL_FACILITY ((EDCS_Classification_Code)27)

/*
 * Definition:
 *     A <DEVICE> designed to assist in the determination of a safe course
 *     for, or the <LOCATION> of, a <VEHICLE>, and/or to warn of dangers and
 *     obstructions; an aid to navigation. EXAMPLES <LIGHT>, <DISPLAY_SIGN>,
 *     electronic <BEACON>.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define ECC_AID_TO_NAVIGATION ((EDCS_Classification_Code)28)

/*
 * Definition:
 *     The gaseous <MATERIAL>s that comprise an <ATMOSPHERE>.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_AIR ((EDCS_Classification_Code)29)

/*
 * Definition:
 *     Ground based surface to air <WEAPON>s for engaging <AIRCRAFT> and
 *     <MISSILE> targets; air defence artillery.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_AIR_DEFENCE_ARTILLERY ((EDCS_Classification_Code)30)

/*
 * Definition:
 *     A widespread body of <AIR> that was established while situated over a
 *     <REGION> of the <PLANETARY_SURFACE> of the <EARTH> and that undergoes
 *     specific modifications while in transit away from that <REGION>; an
 *     air mass. An air mass is often approximately homogeneous in its
 *     horizontal extent (for example: <<AIR_TEMPERATURE>> and/or moisture
 *     distribution) and the vertical inhomogeneities are approximately the
 *     same over its horizontal extent.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_AIR_MASS ((EDCS_Classification_Code)31)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <AERONAUTICAL_COMM_SERVICE>s supporting air
 *     traffic management. EXAMPLES Flight information services, alerting
 *     services, air traffic advisory services, air traffic control services.
 *
 * Group Membership: AIR_TRNSP, COMMUNICATION, TRNSP
 */
#define ECC_AIR_TRAFFIC_SERVICE ((EDCS_Classification_Code)32)

/*
 * Definition:
 *     A <TRANSPORTATION_ROUTE> located principally in the <AIR>.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_AIR_TRANSPORTATION_ROUTE ((EDCS_Classification_Code)33)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <LIGHT>s marking an obstacle that constitutes a
 *     danger to air navigation; an air warning light.
 *
 * Group Membership: AIR_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_AIR_WARNING_LIGHT ((EDCS_Classification_Code)34)

/*
 * Definition:
 *     <SMOKE> resulting from the explosion of a <MUNITION> in the <AIR>;
 *     airburst smoke.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, MILITARY_SCIENCE
 */
#define ECC_AIRBURST_SMOKE ((EDCS_Classification_Code)35)

/*
 * Definition:
 *     A <VEHICLE> that is used, or intended to be used, for flight in an
 *     <ATMOSPHERE>; an aircraft.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_AIRCRAFT ((EDCS_Classification_Code)36)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> designed to carry <AIRCRAFT> and operate as a
 *     naval air base, with a flat deck for take off and landing operations
 *     at <SEA>; an aircraft carrier.
 *
 * Group Membership: AIR_TRNSP, HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_AIRCRAFT_CARRIER ((EDCS_Classification_Code)37)

/*
 * Definition:
 *     A <BUILDING> used for the storage of <AIRCRAFT>; an aircraft hangar
 *     [SOED, "hangar"].
 *
 * Group Membership: AIR_TRNSP, SHELTER, TRNSP
 */
#define ECC_AIRCRAFT_HANGAR ((EDCS_Classification_Code)38)

/*
 * Definition:
 *     A designated <REGION> of a <PLANETARY_SURFACE> where landing by
 *     <AIRCRAFT> is possible; a landing zone.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_AIRCRAFT_LANDING_ZONE ((EDCS_Classification_Code)39)

/*
 * Definition:
 *     A <BUILDING>, usually located at an <AERODROME>, used for keeping
 *     <AIRCRAFT> in a condition of good repair and/or efficiency; an
 *     aircraft maintenance shop.
 *
 * Group Membership: AIR_TRNSP, SHELTER, TRNSP
 */
#define ECC_AIRCRAFT_MAINTENANCE_SHOP ((EDCS_Classification_Code)40)

/*
 * Definition:
 *     A defined paved or hard-packed <TRACT> at an <AERODROME> intended as a
 *     parking <FACILITY> for <AIRCRAFT>. EXAMPLES <APRON>, <HARD_STANDING>.
 *
 * Group Membership: AIR_TRNSP, SURFACE_MATERIAL, TRNSP, USAGE_REGION
 */
#define ECC_AIRCRAFT_PARKING_FACILITY ((EDCS_Classification_Code)41)

/*
 * Definition:
 *     A defined paved or hard-packed <TRACT> intended for long-term parking
 *     and storage of <AIRCRAFT>.
 *
 * Group Membership: AIR_TRNSP, SURFACE_MATERIAL, TRNSP, USAGE_REGION
 */
#define ECC_AIRCRAFT_STORAGE_TRACT ((EDCS_Classification_Code)42)

/*
 * Definition:
 *     Wreckage of an <AIRCRAFT> that is isolated, conspicuous, and can be
 *     used as a landmark.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_AIRCRAFT_WRECKAGE ((EDCS_Classification_Code)43)

/*
 * Definition:
 *     An <AIRPORT> with limited or absent <BUILDING>s, <FACILITY>s, and
 *     <EQUIPMENT>; an airfield.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_AIRFIELD ((EDCS_Classification_Code)44)

/*
 * Definition:
 *     A <AERODROME> on <LAND>; an airport.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_AIRPORT ((EDCS_Classification_Code)45)

/*
 * Definition:
 *     A powered <BALLOON> with a main chamber filled with a gas that is less
 *     dense than the surrounding <AIR>; an airship.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_AIRSHIP ((EDCS_Classification_Code)46)

/*
 * Definition:
 *     An <ATMOSPHERE_REGION> where an <AIRCRAFT> operates; an airspace
 *     [SOED, "airspace"].
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_AIRSPACE ((EDCS_Classification_Code)47)

/*
 * Definition:
 *     The <BOUNDARY> of an <AIRSPACE>.
 *
 * Group Membership: AIR_TRNSP, DEMARCATION, LOCATION, TRNSP
 */
#define ECC_AIRSPACE_BOUNDARY ((EDCS_Classification_Code)48)

/*
 * Definition:
 *     A <COMPONENT> of an <AIRSPACE_BOUNDARY>.
 *
 * Group Membership: AIR_TRNSP, DEMARCATION, TRNSP
 */
#define ECC_AIRSPACE_BOUNDARY_COMPONENT ((EDCS_Classification_Code)49)

/*
 * Definition:
 *     A <COMPONENT> of an <AIRSPACE>.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_AIRSPACE_COMPONENT ((EDCS_Classification_Code)50)

/*
 * Definition:
 *     An <AIRFIELD> with very limited <FACILITY>s; an airstrip.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_AIRSTRIP ((EDCS_Classification_Code)51)

/*
 * Definition:
 *     A <PROTIST> capable of photosynthesis; an alga [SOED, "alga"].
 *     EXAMPLES <SEAWEED>, many unicellular and filamentous
 *     <LIVING_ORGANISM>s.
 *
 * Group Membership: LIVING_ORGANISM
 */
#define ECC_ALGA ((EDCS_Classification_Code)52)

/*
 * Definition:
 *     A sterile <TERRAIN_PLAIN> containing an excess of alkali, usually
 *     occurring in the bottom of an under-drained <GEOGRAPHIC_BASIN> in an
 *     arid or semi-arid <TERRAIN_SURFACE_REGION>; the <LAND> may be soft,
 *     have low shearing and bearing strength, and a high organic content;
 *     an alkali flat.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_ALKALI_FLAT ((EDCS_Classification_Code)53)

/*
 * Definition:
 *     A gently sloping, fan-shaped configuration of the <TERRAIN>, usually
 *     found near the lower termination of a <CANYON>; an alluvial fan.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_ALLUVIAL_FAN ((EDCS_Classification_Code)54)

/*
 * Definition:
 *     A <BUILDING> serving as the <DWELLING> of a diplomatic official of the
 *     highest rank appointed and accredited as representative in residence
 *     by one government or sovereign to another; an ambassadorial residence.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_AMBASSADORIAL_RESIDENCE ((EDCS_Classification_Code)55)

/*
 * Definition:
 *     A <VERTEBRATE> of the class Amphibia; an amphibian [SOED, "amphibian",
 *     B].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_AMPHIBIAN ((EDCS_Classification_Code)56)

/*
 * Definition:
 *     An <AMPHIBIOUS_VEHICLE> designed to generate and move over a cushion
 *     of trapped <AIR> that supports the <VEHICLE> above the
 *     <PLANETARY_SURFACE>.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_AMPHIBIOUS_AIR_CUSHION_VEHICLE ((EDCS_Classification_Code)57)

/*
 * Definition:
 *     An <AMPHIBIOUS_VEHICLE> that is <<ARMOURED>>.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LAND_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_AMPHIBIOUS_ARMOURED_VEHICLE ((EDCS_Classification_Code)58)

/*
 * Definition:
 *     An <AMPHIBIOUS_VEHICLE> designed or designated for utility operations.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_AMPHIBIOUS_UTILITY_VEHICLE ((EDCS_Classification_Code)59)

/*
 * Definition:
 *     A <VEHICLE> capable of operation either on a <WATERBODY_SURFACE> or on
 *     <LAND>; an amphibious vehicle.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_AMPHIBIOUS_VEHICLE ((EDCS_Classification_Code)60)

/*
 * Definition:
 *     An oval or circular <BUILDING> with seats rising in tiers around the
 *     central open space, used for entertainment and/or public events; an
 *     amphitheatre [SOED, "amphitheatre", 1].
 *
 * Group Membership: RECREATION, SHELTER
 */
#define ECC_AMPHITHEATRE ((EDCS_Classification_Code)61)

/*
 * Definition:
 *     A predominantly man-made <RECREATIONAL_FACILITY> equipped with
 *     recreational <DEVICE>s; an amusement park.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_AMUSEMENT_PARK ((EDCS_Classification_Code)62)

/*
 * Definition:
 *     A large <STRUCTURE> located in an <AMUSEMENT_PARK>; an amusement park
 *     attraction.
 *
 * Group Membership: RECREATION, SUPPORT_STRUCTURE
 */
#define ECC_AMUSEMENT_PARK_ATTRACTION ((EDCS_Classification_Code)63)

/*
 * Definition:
 *     A <DEVICE> normally placed on a <WATERBODY_FLOOR>, attached to a
 *     <LOAD_CABLE>, and used to position a floating <OBJECT> (for example:
 *     a <VESSEL> and/or an <OFFSHORE_PLATFORM>); an anchor.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_FLOOR
 */
#define ECC_ANCHOR ((EDCS_Classification_Code)64)

/*
 * Definition:
 *     A designated <WATERBODY_SURFACE_REGION> where a single<VEHICLE> (for
 *     example: a <VESSEL>, a <SEAPLANE>, a <OIL_DRILLING_RIG>, and/or other
 *     watercraft) is anchored or may anchor; an anchor berth.
 *
 * Group Membership: AIR_TRNSP, HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_ANCHOR_BERTH ((EDCS_Classification_Code)65)

/*
 * Definition:
 *     A <WATERBODY_SURFACE_REGION> where <VESSEL>s may anchor; an anchorage.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_ANCHORAGE ((EDCS_Classification_Code)66)

/*
 * Definition:
 *     An <ANCHORAGE> plus related <NAVIGATION_MARK_FIXED>s and/or
 *     <NAVIGATION_MARK_AFLOAT>s; an anchorage complex.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_ANCHORAGE_COMPLEX ((EDCS_Classification_Code)67)

/*
 * Definition:
 *     A <WIND_INDICATOR> designed to measure total <<WIND_SPEED>> or the
 *     <<SPEED>> of one or more linear (vector) components of the <WIND>; an
 *     anemometer.
 *
 * Group Membership: ATMOSPHERE, DEVICE_AND_EQUIPMENT
 */
#define ECC_ANEMOMETER ((EDCS_Classification_Code)68)

/*
 * Definition:
 *     A <LIVING_ORGANISM> of the kingdom Animalia, having sensation and
 *     voluntary motion, without rigid cell walls, and dependent on organic
 *     substances for food; an animal [SOED, "animal", 1.a].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_ANIMAL ((EDCS_Classification_Code)69)

/*
 * Definition:
 *     A <REGION> with a collection of live <NON_HUMAN_ANIMAL>s, usually for
 *     public display; an animal park.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, RECREATION, USAGE_REGION
 */
#define ECC_ANIMAL_PARK ((EDCS_Classification_Code)70)

/*
 * Definition:
 *     A <REGION> that has been set aside for the preservation and protection
 *     of wild <NON_HUMAN_ANIMAL>s; an animal sanctuary.
 *
 * Group Membership: ANIMAL, USAGE_REGION
 */
#define ECC_ANIMAL_SANCTUARY ((EDCS_Classification_Code)71)

/*
 * Definition:
 *     A <ROOM> before or forming an entrance to another; an ante-room [SOED,
 *     "ante-room"].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_ANTE_ROOM ((EDCS_Classification_Code)72)

/*
 * Definition:
 *     A multi-residence <BUILDING> containing rental accommodations for hire
 *     on a long-term basis; an apartment house.
 *
 * Group Membership: SHELTER
 */
#define ECC_APARTMENT_HOUSE ((EDCS_Classification_Code)73)

/*
 * Definition:
 *     An opening and/or hole in an <OBJECT>, especially a <STRUCTURE>; an
 *     aperture.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_APERTURE ((EDCS_Classification_Code)74)

/*
 * Definition:
 *     A usually paved <TRACT> located at an <AERODROME> where <AIRCRAFT> can
 *     park, load or unload, refuel, and/or undergo servicing; an apron
 *     [SOED, "apron", II.10].
 *
 * Group Membership: AIR_TRNSP, SURFACE_MATERIAL, TRNSP, USAGE_REGION
 */
#define ECC_APRON ((EDCS_Classification_Code)75)

/*
 * Definition:
 *     A <PIPE> or artificial channel designed to transport <WATER> from a
 *     remote source, usually by gravity; an aqueduct.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_AQUEDUCT ((EDCS_Classification_Code)76)

/*
 * Definition:
 *     A representation of one or more <AQUEDUCT>s, especially in a
 *     <BUILT_UP_REGION>; an aqueduct centre-line or aqueduct nexus.
 *
 * Group Membership: INFRASTRUCTURE, LOCATION
 */
#define ECC_AQUEDUCT_NEXUS ((EDCS_Classification_Code)77)

/*
 * Definition:
 *     An <ARTHROPOD> of the class Arachnida; an arachnid [SOED, "arachnid"].
 *     EXAMPLES Spider, scorpion, mite, tick.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_ARACHNID ((EDCS_Classification_Code)78)

/*
 * Definition:
 *     A culturally designated <TRACT> where rare <TREE>s are cultivated and
 *     displayed; an arboretum [SOED, "arboretum"].
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, RECREATION, USAGE_REGION
 */
#define ECC_ARBORETUM ((EDCS_Classification_Code)79)

/*
 * Definition:
 *     A covered pedestrian <ROUTE> composed of arches and pillars, usually
 *     open along one or both sides; an arcade.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_ARCADE ((EDCS_Classification_Code)80)

/*
 * Definition:
 *     A <SITE> where remains of ancient civilizations and/or the activities
 *     of <HUMAN>s have been discovered; an archaeological site.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_ARCHAELOGICAL_SITE ((EDCS_Classification_Code)81)

/*
 * Definition:
 *     A <BOUNDARY> established by opposing political groups as a result of
 *     cessation of hostilities; an armistice line.
 *
 * Group Membership: ADMINISTRATION, DEMARCATION, LOCATION, MILITARY_SCIENCE
 */
#define ECC_ARMISTICE_LINE ((EDCS_Classification_Code)82)

/*
 * Definition:
 *     A <COMBAT_SUPPORT_VEHICLE> that is <<ARMOURED>> and is capable of
 *     launching an AVLB; an armoured bridge launcher.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ARMOURED_BRIDGE_LAUNCHER ((EDCS_Classification_Code)83)

/*
 * Definition:
 *     A <COMBATANT_VEHICLE> that is <<ARMOURED>> and mounted with guns or
 *     other armaments, often used to move groups of soldiers; an armoured
 *     fighting vehicle. EXAMPLES Infantry fighting <GROUND_VEHICLE>,
 *     armoured personnel carrier, self-propelled <MORTAR>, armoured car,
 *     chemical reconnaissance <VEHICLE>, anti-tank guided missile launcher.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ARMOURED_FIGHTING_VEHICLE ((EDCS_Classification_Code)84)

/*
 * Definition:
 *     A <ARMOURED_TRACKED_VEHICLE> that is heavily <<ARMOURED>>, mounted
 *     with cannon and guns; an armoured tracked fighting vehicle.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ARMOURED_TRACKED_FIGHTING_VEHICLE ((EDCS_Classification_Code)85)

/*
 * Definition:
 *     A closed <COMBATANT_VEHICLE> that is <<ARMOURED>> and moves on
 *     caterpillar treads; an armoured tracked vehicle.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ARMOURED_TRACKED_VEHICLE ((EDCS_Classification_Code)86)

/*
 * Definition:
 *     A <COMBAT_SUPPORT_VEHICLE> that is <<ARMOURED>>. EXAMPLES Engineering
 *     <GROUND_VEHICLE>, tracked load carrier, towing <VEHICLE>, recovery
 *     <VEHICLE>.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ARMOURED_UTILITY_VEHICLE ((EDCS_Classification_Code)87)

/*
 * Definition:
 *     A <BUILDING> for storing arms and military <EQUIPMENT>, especially one
 *     serving as headquarters for reserve <MILITARY_PERSONNEL>; an armoury
 *     [AHD, "armory", 1.b].
 *
 * Group Membership: ADMINISTRATION, MILITARY_SCIENCE, SHELTER
 */
#define ECC_ARMOURY ((EDCS_Classification_Code)88)

/*
 * Definition:
 *     <EQUIPMENT> (for example: a <LOAD_CABLE> and/or a <BARRIER>) that can
 *     be used to stop an <AIRCRAFT> immediately upon landing; an arresting
 *     gear.
 *
 * Group Membership: AIR_TRNSP, DEVICE_AND_EQUIPMENT, TRNSP
 */
#define ECC_ARRESTING_GEAR ((EDCS_Classification_Code)89)

/*
 * Definition:
 *     An <INVERTEBRATE> of the phylum Arthropoda that is characterized by
 *     having a segmented body and jointed limbs; an arthropod [SOED,
 *     "arthropod"]. EXAMPLES <INSECT>, <ARACHNID>, <CRUSTACEAN>.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_ARTHROPOD ((EDCS_Classification_Code)90)

/*
 * Definition:
 *     A <SPACECRAFT> designed to be placed in orbit around a <PLANET> or,
 *     occasionally, another <CELESTIAL_BODY>; an artificial satellite
 *     [SOED, "satellite", A.2.c].
 *
 * Group Membership: SPACE, VEHICLE
 */
#define ECC_ARTIFICIAL_SATELLITE ((EDCS_Classification_Code)91)

/*
 * Definition:
 *     An emplacement for one or more pieces of <FIELD_ARTILLERY>; an
 *     artillery battery [SOED, "battery", II.4].
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_ARTILLERY_BATTERY ((EDCS_Classification_Code)92)

/*
 * Definition:
 *     A naturally-occurring pool of liquid asphalt.
 *
 * Group Membership: MATERIAL
 */
#define ECC_ASPHALT_POOL ((EDCS_Classification_Code)93)

/*
 * Definition:
 *     A <SITE> and associated <BUILDING>s used for the purpose of combining
 *     manufactured <COMPONENT>s to make a completed product; an assembly
 *     plant.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER, USAGE_REGION
 */
#define ECC_ASSEMBLY_PLANT ((EDCS_Classification_Code)94)

/*
 * Definition:
 *     Any of numerous small <CELESTIAL_BODY>s in the <SOLAR_SYSTEM> of the
 *     <SUN>, with orbits lying chiefly between <MARS> and <JUPITER>, and
 *     characteristic <<OUTSIDE_DIAMETER>>s between a few and several
 *     hundred kilometres; a minor planet, planetoid, or asteroid [SOED,
 *     "asteroid", A.1].
 *
 * Group Membership: SPACE
 */
#define ECC_ASTEROID ((EDCS_Classification_Code)95)

/*
 * Definition:
 *     A <PROPERTY_SET> containing information about <CELESTIAL_BODY>s and
 *     other astronomical matters.
 *
 * Group Membership: PROPERTY_SET, SPACE
 */
#define ECC_ASTRONOMIC_PROPERTY_SET ((EDCS_Classification_Code)96)

/*
 * Definition:
 *     A <STRUCTURE> used for the scientific study of matter in <SPACE>,
 *     especially the <LOCATION>s, dimensions, distribution, motion,
 *     composition, energy, and evolution of <CELESTIAL_BODY>s or celestial
 *     phenomena; an astronomical station.
 *
 * Group Membership: SPACE, SUPPORT_STRUCTURE
 */
#define ECC_ASTRONOMICAL_STATION ((EDCS_Classification_Code)97)

/*
 * Definition:
 *     A <HELICOPTER> designed or designated for ASW operations.
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ASW_HELICOPTER ((EDCS_Classification_Code)98)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed or designated for ASW operations.
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ASW_WINGED_AIRCRAFT ((EDCS_Classification_Code)99)

/*
 * Definition:
 *     A <SITE> and associated <STRUCTURE>s used for recreational exercise
 *     and major sports competitions, which typically serves a large
 *     metropolitan <BUILT_UP_REGION>; an athletic complex.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_ATHLETIC_COMPLEX ((EDCS_Classification_Code)100)

/*
 * Definition:
 *     An open <TRACT> where sporting events, exercises, and/or games occur;
 *     an athletic field.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_ATHLETIC_FIELD ((EDCS_Classification_Code)101)

/*
 * Definition:
 *     A gaseous envelope gravitationally bound to a <CELESTIAL_BODY>; an
 *     atmosphere.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_ATMOSPHERE ((EDCS_Classification_Code)102)

/*
 * Definition:
 *     A <PROPERTY_SET> describing a <LOCATION> in the <ATMOSPHERE> or an
 *     <ATMOSPHERE_REGION>.
 *
 * Group Membership: ATMOSPHERE, LOCATION, PROPERTY_SET
 */
#define ECC_ATMOSPHERE_PROPERTY_SET ((EDCS_Classification_Code)103)

/*
 * Definition:
 *     A <REGION> of an <ATMOSPHERE>.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_ATMOSPHERE_REGION ((EDCS_Classification_Code)104)

/*
 * Definition:
 *     The <BOUNDARY> or transition zone between <AIR_MASS>s of different
 *     <<AIR_DENSITY>>s; an atmospheric front.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_ATMOSPHERIC_FRONT ((EDCS_Classification_Code)105)

/*
 * Definition:
 *     A central court that is located in a <BUILDING>, rises through one or
 *     more <FLOOR_LEVEL>s, is surrounded by galleries at each <FLOOR_LEVEL>
 *     with <ROOM>s opening off, and is often skylighted; an atrium.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_ATRIUM ((EDCS_Classification_Code)106)

/*
 * Definition:
 *     A specified <AIR_TRANSPORTATION_ROUTE> designed for channelling the
 *     flow of <AIRCRAFT> as necessary for the provision of
 *     <AIR_TRAFFIC_SERVICE>s; an ATS route.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_ATS_ROUTE ((EDCS_Classification_Code)107)

/*
 * Definition:
 *     A <COMPONENT> of an <ATS_ROUTE> that is defined by two <LOCATION>s
 *     specified in a flight plan; these <LOCATION>s are either continental
 *     geographical <LOCATION>s, insular geographical <LOCATION>s, or
 *     <LOCATION>s at which a definite radio fix can be established.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_ATS_ROUTE_COMPONENT ((EDCS_Classification_Code)108)

/*
 * Definition:
 *     A <HELICOPTER> designed for military attack operations.
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ATTACK_HELICOPTER ((EDCS_Classification_Code)109)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed for military attack operations.
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_ATTACK_WINGED_AIRCRAFT ((EDCS_Classification_Code)110)

/*
 * Definition:
 *     The highest <FLOOR_LEVEL> of a <BUILDING>, usually immediately under
 *     the beams of the <ROOF>, or a <ROOM> in this location; an attic
 *     [SOED, "attic", B.2] or garret.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_ATTIC ((EDCS_Classification_Code)111)

/*
 * Definition:
 *     A large <BUILDING> for public meetings and/or performances; an
 *     auditorium.
 *
 * Group Membership: RECREATION, SHELTER
 */
#define ECC_AUDITORIUM ((EDCS_Classification_Code)112)

/*
 * Definition:
 *     Luminous phenomena, in the form of arcs, bands, draperies, and/or
 *     curtains in a high <ATMOSPHERE_REGION> caused by charged <PARTICLE>s
 *     from <SPACE>, mainly at high latitudes; an aurora.
 *
 * Group Membership: ATMOSPHERE, SPACE
 */
#define ECC_AURORA ((EDCS_Classification_Code)113)

/*
 * Definition:
 *     The locus of structured <AURORA> around each <PLANETARY_MAGNETIC_POLE>
 *     of the <EARTH>, roughly forming an oval band between 60 and 70
 *     degrees latitude in both northern and southern hemispheres; an aurora
 *     oval.
 *
 * Group Membership: ATMOSPHERE, SPACE
 */
#define ECC_AURORA_OVAL ((EDCS_Classification_Code)114)

/*
 * Definition:
 *     A <DEVICE> that provides money and/or performs banking services when a
 *     special card is inserted and a password is typed in; an automated
 *     teller machine [SOED, "teller", II.2.a; "automated teller machine"].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define ECC_AUTOMATED_TELLER_MACHINE ((EDCS_Classification_Code)115)

/*
 * Definition:
 *     A <HEAVY_INDUSTRIAL_FACILITY> used for the purpose of manufacturing
 *     <MOTOR_VEHICLE>s; an automotive plant.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, LAND_TRNSP, SHELTER, TRNSP, USAGE_REGION
 */
#define ECC_AUTOMOTIVE_PLANT ((EDCS_Classification_Code)116)

/*
 * Definition:
 *     An <AERONAUTICAL_AID_TO_NAVIGATION> used as a guide to a pilot of an
 *     <AIRCRAFT> seeking a particular <REGION> and/or avoiding a
 *     <MAN_MADE_AIR_OBSTRUCTION>; an aviation navigation marker. EXAMPLES
 *     Flare, distinctive <DISPLAY_SIGN>.
 *
 * Group Membership: AIR_TRNSP, DEVICE_AND_EQUIPMENT, TRNSP
 */
#define ECC_AVIATION_NAVIGATION_MARKER ((EDCS_Classification_Code)117)

/*
 * Definition:
 *     A <WAYPOINT> used in aviation.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_AVIATION_WAYPOINT ((EDCS_Classification_Code)118)

/*
 * Definition:
 *     The <TERRAIN_STRIP> that is located between the normal limit of the
 *     action of <WATER_WAVE>s above either mean high water springs or mean
 *     higher high water as defined by a National Authority and the maximum
 *     limit of the action of <WATER_WAVE>s; the backshore precise.
 *
 * Group Membership: LITTORAL, PHYSIOGRAPHY
 */
#define ECC_BACKSHORE_PRECISE ((EDCS_Classification_Code)119)

/*
 * Definition:
 *     A platform projecting from the <WALL> of a <BUILDING>, supported by
 *     pillars and/or brackets, and enclosed by a balustrade or low <WALL>;
 *     a balcony or deck.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_BALCONY ((EDCS_Classification_Code)120)

/*
 * Definition:
 *     An <AIRCRAFT> consisting of an airtight envelope designed to rise into
 *     the <ATMOSPHERE> when inflated with a gas that is less dense than
 *     <AIR> (for example: hot <AIR>), carrying a basket or car for
 *     passengers; a balloon.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_BALLOON ((EDCS_Classification_Code)121)

/*
 * Definition:
 *     A <PLANT> belonging to the genus Bambusa, Arundinaria, Phyllostachys,
 *     Sasa, or Dendrocalamus, most having hard, hollow stems; a bamboo
 *     [SOED, "bamboo", A.1].
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_BAMBOO ((EDCS_Classification_Code)122)

/*
 * Definition:
 *     A <TRACT> of <BAMBOO>.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_BAMBOO_TRACT ((EDCS_Classification_Code)123)

/*
 * Definition:
 *     A <BUILDING> housing an establishment for the deposit, custody, and
 *     issue of money; for making loans and discounts; and for making easier
 *     the exchange of funds by certificates, checks, and/or notes; a bank
 *     [SOED, "bank", n3.3].
 *
 * Group Membership: INFRASTRUCTURE, SHELTER
 */
#define ECC_BANK_BUILDING ((EDCS_Classification_Code)124)

/*
 * Definition:
 *     A <FARM_BUILDING> that is used to store hay, grain, and implements
 *     and/or to house <NON_HUMAN_ANIMAL>s; a barn [SOED, "barn", A.1]
 *     [SOED, "barn", A.2].
 *
 * Group Membership: AGRICULTURE, ANIMAL, LIVING_ORGANISM, SHELTER
 */
#define ECC_BARN ((EDCS_Classification_Code)125)

/*
 * Definition:
 *     A <BUILDING> used to house <MILITARY_PERSONNEL>, which is typically
 *     large, unadorned, and intended for relatively temporary occupancy; a
 *     barrack.
 *
 * Group Membership: MILITARY_SCIENCE, SHELTER
 */
#define ECC_BARRACK ((EDCS_Classification_Code)126)

/*
 * Definition:
 *     <TERRAIN> so disturbed as to have no identifiable <VEGETATION>; barren
 *     ground.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_BARREN_GROUND ((EDCS_Classification_Code)127)

/*
 * Definition:
 *     A physical obstacle that prevents access and/or separates; a barrier
 *     [SOED, "barrier", 1].
 *
 * Group Membership: DEMARCATION
 */
#define ECC_BARRIER ((EDCS_Classification_Code)128)

/*
 * Definition:
 *     A <FLOOR_LEVEL> of a <BUILDING> located wholly or partially below the
 *     level of the <LAND>; a basement [SOED, "basement", 1].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_BASEMENT ((EDCS_Classification_Code)129)

/*
 * Definition:
 *     A flying <MAMMAL> of the order Chiroptera, the members of which are
 *     mainly nocturnal and have forelimbs that support membranous wings
 *     extending to the tail; a bat [SOED, "bat", 3].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_BAT ((EDCS_Classification_Code)130)

/*
 * Definition:
 *     A <WATERBODY_FLOOR_PROVINCE> of homogeneous bathymetric
 *     characteristics; a bathymetric province.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_BATHYMETRIC_PROVINCE ((EDCS_Classification_Code)131)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> of the most heavily armed and <<ARMOURED>>
 *     class, of sufficient size to take part in a main attack; a battleship
 *     [SOED, "battleship"].
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_BATTLESHIP ((EDCS_Classification_Code)132)

/*
 * Definition:
 *     The <SHORE> of a <WATERBODY> that consists of unconsolidated
 *     <MATERIAL>s (for example: <SAND> and/or small <STONE>s), including
 *     the <FORESHORE> and the <BACKSHORE_PRECISE>; a beach.
 *
 * Group Membership: LITTORAL, PHYSIOGRAPHY
 */
#define ECC_BEACH ((EDCS_Classification_Code)133)

/*
 * Definition:
 *     A representation of the vertical relief of a <WATERBODY_FLOOR> and
 *     adjacent <LAND> along a <LINE> or <SET> of connected <LINE>s
 *     generally established perpendicular to the local <SHORELINE> and
 *     based on <DEPTH_CONTOUR_LINE>s, <SOUNDING>s, and other measurements
 *     of the depth at or below a shared <SURFACE_DATUM>; a beach profile.
 *
 * Group Membership: LITTORAL, PHYSIOGRAPHY, SURVEY, WATERBODY_FLOOR
 */
#define ECC_BEACH_PROFILE ((EDCS_Classification_Code)134)

/*
 * Definition:
 *     A <TRACT> defined from the <SHORE> inland for a predetermined distance
 *     and/or to the first existence of a <LAND_TRANSPORTATION_ROUTE> and
 *     from the <SHORE> seaward to a predetermined depth; a beach zone.
 *
 * Group Membership: LAND_TRNSP, LITTORAL, PHYSIOGRAPHY, TRNSP
 */
#define ECC_BEACH_ZONE ((EDCS_Classification_Code)135)

/*
 * Definition:
 *     A fixed, usually elevated, <DEVICE> that serves as an
 *     <AID_TO_NAVIGATION>, usually functioning by emitting a signal (for
 *     example: a flashing <LIGHT> or a radar pulse) warning of its
 *     <LOCATION>; a beacon.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, LOCATION, TRNSP
 */
#define ECC_BEACON ((EDCS_Classification_Code)136)

/*
 * Definition:
 *     Solid <ROCK> underlying alluvial deposits; bedrock [SOED, "bedrock"].
 *
 * Group Membership: MATERIAL, PHYSIOGRAPHY
 */
#define ECC_BEDROCK ((EDCS_Classification_Code)137)

/*
 * Definition:
 *     A reference mark on a permanent <OBJECT> indicating <<ELEVATION>>; a
 *     benchmark.
 *
 * Group Membership: SURVEY
 */
#define ECC_BENCHMARK ((EDCS_Classification_Code)138)

/*
 * Definition:
 *     A <REGION> in which a biologic substance is present that can kill,
 *     seriously injure, or incapacitate a <HUMAN> and/or <NON_HUMAN_ANIMAL>
 *     through its physiological properties. The biologic substance is
 *     usually dispersed over a <SURFACE> and/or within the <ATMOSPHERE>.
 *
 * Group Membership: ATMOSPHERE, LIVING_ORGANISM, SURFACE
 */
#define ECC_BIOLOGIC_HAZARD_REGION ((EDCS_Classification_Code)139)

/*
 * Definition:
 *     The production of light without sensible heat by <LIVING_ORGANISM>s as
 *     a result of chemical reaction either within cells or organs or
 *     extracellulary in some form of secretion; bioluminescence.
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, LIVING_ORGANISM
 */
#define ECC_BIOLUMINESCENCE ((EDCS_Classification_Code)140)

/*
 * Definition:
 *     A <VERTEBRATE> of the class Aves, characterized by forelimbs as wings
 *     for flight, oviparous reproduction, and care for the young; a bird
 *     [SOED, "bird", B].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_BIRD ((EDCS_Classification_Code)141)

/*
 * Definition:
 *     A <BARRIER> used to divert and/or dissipate jet or propeller blast.
 *
 * Group Membership: SHELTER
 */
#define ECC_BLAST_BARRIER ((EDCS_Classification_Code)142)

/*
 * Definition:
 *     A smelting <FURNACE> in which a blast of <AIR> is used, especially one
 *     for iron-smelting using a compressed hot blast of <AIR>; a blast
 *     furnace.
 *
 * Group Membership: INDUSTRY, SUPPORT_STRUCTURE, TEMPERATURE
 */
#define ECC_BLAST_FURNACE ((EDCS_Classification_Code)143)

/*
 * Definition:
 *     A small <AIRSHIP> that does not have a rigid frame; a blimp.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_BLIMP ((EDCS_Classification_Code)144)

/*
 * Definition:
 *     A military <FORTIFICATION> constructed of sturdy <MATERIAL>s (for
 *     example: concrete) and designed with <WALL_LOOPHOLE>s; a blockhouse
 *     [SOED, "blockhouse", a].
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_BLOCKHOUSE ((EDCS_Classification_Code)145)

/*
 * Definition:
 *     A walkway made of wooden planks; a boardwalk.
 *
 * Group Membership: TRNSP
 */
#define ECC_BOARDWALK ((EDCS_Classification_Code)146)

/*
 * Definition:
 *     A mechanical <DEVICE> other than a <HYDROGRAPHIC_LOCK> for lifting
 *     <WATER_SURFACE_VESSEL>s between two levels; a boat lift.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP
 */
#define ECC_BOAT_LIFT ((EDCS_Classification_Code)147)

/*
 * Definition:
 *     A section of <CANAL> and/or <NAVIGABLE_WATERWAY> in which a barge or
 *     other <WATER_SURFACE_VESSEL> can be turned; a boat turning basin.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_BOAT_TURNING_BASIN ((EDCS_Classification_Code)148)

/*
 * Definition:
 *     A <WETLAND> having a wet, spongy, acidic substrate composed chiefly of
 *     sphagnum moss and peat in which characteristic <SHRUB>s, herbs, and,
 *     sometimes, <TREE>s usually grow; a bog [AHD, "bog", 1a].
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_BOG ((EDCS_Classification_Code)149)

/*
 * Definition:
 *     A post on a <WHARF> used for fastening <MOORING_LINE>s; a bollard.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT
 */
#define ECC_BOLLARD ((EDCS_Classification_Code)150)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed to carry and drop heavy loads of bombs; a
 *     bomber.
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_BOMBER_WINGED_AIRCRAFT ((EDCS_Classification_Code)151)

/*
 * Definition:
 *     A <WATERBODY_REGION> where <WATER_WAVE>s form over a submerged
 *     offshore <SHOAL>, sometimes (in very calm weather and/or at high
 *     <TIDE>) nearly swelling but in other conditions breaking heavily and
 *     producing a dangerous stretch of broken <WATER>; a bombora.
 *
 * Group Membership: HYDROLOGY, WATERBODY_SURFACE
 */
#define ECC_BOMBORA_REGION ((EDCS_Classification_Code)152)

/*
 * Definition:
 *     A culturally designated <TRACT> where <PLANT>s are displayed; a
 *     botanical garden.
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, RECREATION, USAGE_REGION
 */
#define ECC_BOTANICAL_GARDEN ((EDCS_Classification_Code)153)

/*
 * Definition:
 *     A characteristic (for example: consistency, colour, and/or
 *     classification) of the <OCEAN_FLOOR>; bottom characteristic.
 *
 * Group Membership: WATERBODY_FLOOR
 */
#define ECC_BOTTOM_CHARACTERISTIC ((EDCS_Classification_Code)154)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> characterized by detached masses of <ROCK>
 *     usually having an <<OUTSIDE_DIAMETER>> greater than 25 centimetres; a
 *     boulder field.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_BOULDER_FIELD ((EDCS_Classification_Code)155)

/*
 * Definition:
 *     The limits of a <REGION>; that is, a <NON_EMPTY_SET> of <LOCATION>s
 *     characterized by the fact that any <LOCATION> included in the
 *     <NON_EMPTY_SET> is arbitrarily near to <LOCATION>s that are not
 *     contained in the given <REGION> as well as to <LOCATION>s that are
 *     contained in the given <REGION>; a boundary.
 *
 * Group Membership: DEMARCATION, LOCATION
 */
#define ECC_BOUNDARY ((EDCS_Classification_Code)156)

/*
 * Definition:
 *     A <COMPONENT> of a <BOUNDARY>.
 *
 * Group Membership: DEMARCATION, LOCATION
 */
#define ECC_BOUNDARY_COMPONENT ((EDCS_Classification_Code)157)

/*
 * Definition:
 *     A <MARKER> placed at a <LOCATION> that is associated with a surveyed
 *     <BOUNDARY>; a boundary monument.
 *
 * Group Membership: DEMARCATION, LOCATION, SURVEY
 */
#define ECC_BOUNDARY_MONUMENT ((EDCS_Classification_Code)158)

/*
 * Definition:
 *     An <APERTURE> in an obstacle (for example: a <FORTIFICATION>, a
 *     <WALL>, and/or a <TERRAIN_OBSTACLE>), particularly one caused by
 *     violence or natural decay; a breach.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_BREACH ((EDCS_Classification_Code)159)

/*
 * Definition:
 *     A rough <APERTURE> for entrance and/or egress of <HUMAN>s, typically
 *     about 60 centimetres in diameter; a breach hole.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_BREACH_HOLE ((EDCS_Classification_Code)160)

/*
 * Definition:
 *     A <LINE> representing the demarcation of a sudden and significant
 *     change in the gradient of the <TERRAIN>; a break-line.
 *
 * Group Membership: DEMARCATION, LOCATION, PHYSIOGRAPHY
 */
#define ECC_BREAK_LINE ((EDCS_Classification_Code)161)

/*
 * Definition:
 *     A <WATERBODY_REGION> where <WATER_WAVE>s break over off-lying <SHOAL>s
 *     and/or <REEF>s near the <SHORE>; a breaker region.
 *
 * Group Membership: HYDROLOGY, WATERBODY_SURFACE
 */
#define ECC_BREAKER_REGION ((EDCS_Classification_Code)162)

/*
 * Definition:
 *     A <STRUCTURE> that protects a <WATERBODY_REGION> (for example: a
 *     <SHORE>, a <HARBOUR>, an <ANCHORAGE>, and/or a
 *     <WATERBODY_SHELTER_BASIN>) from <WATER_WAVE>s by preventing them from
 *     reaching the protected <REGION> or reducing their magnitude; a
 *     breakwater.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, SHELTER, SUPPORT_STRUCTURE, WATERBODY_SURFACE
 */
#define ECC_BREAKWATER ((EDCS_Classification_Code)163)

/*
 * Definition:
 *     A <STRUCTURE> that connects two <LOCATION>s and provides for the
 *     passage of a <LAND_TRANSPORTATION_ROUTE> over a <TERRAIN_OBSTACLE>
 *     (for example: a <WATERBODY>, a <GULLY>, and/or a <ROAD>); a bridge. A
 *     bridge consists of a <SET> of two or more <BRIDGE_PIER>s or
 *     <BRIDGE_TOWER>s joined by <BRIDGE_SPAN>s.
 *
 * Group Membership: LAND_TRNSP, SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_BRIDGE ((EDCS_Classification_Code)164)

/*
 * Definition:
 *     A pillar or abutment that supports a <BRIDGE_SPAN>; a bridge pier.
 *
 * Group Membership: LAND_TRNSP, SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_BRIDGE_PIER ((EDCS_Classification_Code)165)

/*
 * Definition:
 *     A <SITE> that has been sculpted (for example: levelled) to support
 *     and/or secure a <BRIDGE_PIER>; a bridge platform.
 *
 * Group Membership: LAND_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_BRIDGE_PLATFORM ((EDCS_Classification_Code)166)

/*
 * Definition:
 *     A <COMPONENT> of the deck of a <BRIDGE> spanning successive
 *     <BRIDGE_PIER>s; a bridge span.
 *
 * Group Membership: LAND_TRNSP, SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_BRIDGE_SPAN ((EDCS_Classification_Code)167)

/*
 * Definition:
 *     A <SUPERSTRUCTURE> of a <BRIDGE>, above the lowest deck; a bridge
 *     superstructure.
 *
 * Group Membership: LAND_TRNSP, SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_BRIDGE_SUPERSTRUCTURE ((EDCS_Classification_Code)168)

/*
 * Definition:
 *     A <TOWER> and/or <PYLON> from which the deck of a <BRIDGE> is
 *     suspended; a bridge tower.
 *
 * Group Membership: LAND_TRNSP, SUPPORT_STRUCTURE
 */
#define ECC_BRIDGE_TOWER ((EDCS_Classification_Code)169)

/*
 * Definition:
 *     A <TRACT> covered by low-growing woody <PLANT>s; brush land. EXAMPLES
 *     Scrub, brush, bush.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_BRUSH_LAND ((EDCS_Classification_Code)170)

/*
 * Definition:
 *     <EQUIPMENT>, usually a series of buckets, for raising <MATERIAL>s to a
 *     higher level; a bucket elevator.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY, TRNSP
 */
#define ECC_BUCKET_ELEVATOR ((EDCS_Classification_Code)171)

/*
 * Definition:
 *     A <WORSHIP_PLACE> for Buddhist worship; a Buddhist temple.
 *
 * Group Membership: RELIGION
 */
#define ECC_BUDDHIST_TEMPLE ((EDCS_Classification_Code)172)

/*
 * Definition:
 *     A fixed, relatively permanent <STRUCTURE> with a <ROOF> and usually
 *     with <WALL>(s) that is designed for use and occupancy by <HUMAN>s; a
 *     building.
 *
 * Group Membership: SHELTER
 */
#define ECC_BUILDING ((EDCS_Classification_Code)173)

/*
 * Definition:
 *     A <COMPONENT> of a <BUILDING>. EXAMPLES <ROOF>, <WALL>, <DOOR>,
 *     <WINDOW>, <FLOOR>.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_BUILDING_COMPONENT ((EDCS_Classification_Code)174)

/*
 * Definition:
 *     A <STRUCTURE_ENTRANCE_AND_OR_EXIT> between <BUILDING_COMPONENT>s.
 *     EXAMPLE The doorway to a landing of a <STAIR>.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_BUILDING_COMPONENT_ENTRANCE_OR_EXIT ((EDCS_Classification_Code)175)

/*
 * Definition:
 *     A <SUPERSTRUCTURE> of a <BUILDING> that rises from the <ROOF> but is
 *     not considered to be a <COMPONENT> of the <ROOF>; a building
 *     superstructure.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_BUILDING_SUPERSTRUCTURE ((EDCS_Classification_Code)176)

/*
 * Definition:
 *     A <TRACT> containing a concentration of <BUILDING>s and other
 *     <STRUCTURE>s; a built-up region.
 *
 * Group Membership: SHELTER
 */
#define ECC_BUILT_UP_REGION ((EDCS_Classification_Code)177)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> that has been built-up from its natural
 *     configuration.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_BUILT_UP_TERRAIN ((EDCS_Classification_Code)178)

/*
 * Definition:
 *     A reinforced underground <SHELTER>, typically resistant to
 *     <MUNITION>s; a bunker [SOED, "bunker", 5].
 *
 * Group Membership: SHELTER
 */
#define ECC_BUNKER ((EDCS_Classification_Code)179)

/*
 * Definition:
 *     A floating <OBJECT>, other than a <LIGHTSHIP>, moored or anchored to a
 *     <WATERBODY_FLOOR> at a particular <LOCATION> and serving a specific
 *     purpose (for example: an <AID_TO_NAVIGATION>); a buoy.
 *
 * Group Membership: ABSTRACT_OBJECT, HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_SURFACE
 */
#define ECC_BUOY ((EDCS_Classification_Code)180)

/*
 * Definition:
 *     An <ELECTRICAL_CABLE> located underground and/or underwater; a buried
 *     electrical cable.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_BURIED_ELECTRICAL_CABLE ((EDCS_Classification_Code)181)

/*
 * Definition:
 *     A <SYSTEM> of <BURIED_ELECTRICAL_CABLE>s, supports, and conduits that
 *     transmits electricity over distance; a buried power transmission line.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_BURIED_POWER_TRANSMISSION_LINE ((EDCS_Classification_Code)182)

/*
 * Definition:
 *     A <STRUCTURE> where buses or coaches are housed and maintained and
 *     from which they are dispatched for service; a bus depot.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_BUS_DEPOT ((EDCS_Classification_Code)183)

/*
 * Definition:
 *     A <STRUCTURE>, usually in a <TOWN> or <CITY>, that serves as a
 *     <BUS_STOP>, especially for long-distance buses or coaches; a bus
 *     station [SOED, "bus station"].
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_BUS_STATION ((EDCS_Classification_Code)184)

/*
 * Definition:
 *     A <LOCATION> where buses and coaches regularly stop to take on and/or
 *     let off passengers; a bus-stop [SOED, "bus-stop"].
 *
 * Group Membership: LAND_TRNSP, LOCATION, TRNSP
 */
#define ECC_BUS_STOP ((EDCS_Classification_Code)185)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed or designated for private business use.
 *
 * Group Membership: AIR_TRNSP, INDUSTRY, TRNSP, VEHICLE
 */
#define ECC_BUSINESS_WINGED_AIRCRAFT ((EDCS_Classification_Code)186)

/*
 * Definition:
 *     A detached, flat-topped <HILL> or tableland that is smaller than a
 *     <MESA> and rises steeply from a surrounding <TERRAIN_PLAIN>; a butte.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_BUTTE ((EDCS_Classification_Code)187)

/*
 * Definition:
 *     A <BUILDING> at a remote and/or wilderness <LOCATION>; a cabin.
 *
 * Group Membership: SHELTER
 */
#define ECC_CABIN ((EDCS_Classification_Code)188)

/*
 * Definition:
 *     A <STRUCTURE> with unique characteristics used to support cadastral
 *     surveys.
 *
 * Group Membership: ADMINISTRATION, SUPPORT_STRUCTURE, SURVEY
 */
#define ECC_CADASTRAL_CONSTRUCTION ((EDCS_Classification_Code)189)

/*
 * Definition:
 *     A <LOCATION> used for locating and orienting a cadastral survey; a
 *     cadastral control point.
 *
 * Group Membership: ADMINISTRATION, LOCATION, SURVEY
 */
#define ECC_CADASTRAL_CONTROL_POINT ((EDCS_Classification_Code)190)

/*
 * Definition:
 *     A heap of <ROCK>s piled up as a <MEMORIAL_MONUMENT> or a landmark; a
 *     cairn.
 *
 * Group Membership: LOCATION
 */
#define ECC_CAIRN ((EDCS_Classification_Code)191)

/*
 * Definition:
 *     A <GATE> at the end of a <DRY_DOCK> that excludes the <WATER> after
 *     pumping out the <DRY_DOCK>, often containing the pumping engines; a
 *     caisson.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_CAISSON ((EDCS_Classification_Code)192)

/*
 * Definition:
 *     A <LOCATION> some distance from a <HARBOUR> at which the navigator of
 *     a <VESSEL> notifies the authority for that <HARBOUR> of the position
 *     of the <VESSEL>; a calling in point.
 *
 * Group Membership: ADMINISTRATION, COMMUNICATION, HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_CALLING_IN_POINT ((EDCS_Classification_Code)193)

/*
 * Definition:
 *     A <STRUCTURE> that is mounted on a pedestal and composed of an upright
 *     member with a shorter horizontal member centred at approximately two
 *     thirds of the <<HEIGHT>> of the upright member; a Calvary cross.
 *
 * Group Membership: RELIGION, SUPPORT_STRUCTURE
 */
#define ECC_CALVARY_CROSS ((EDCS_Classification_Code)194)

/*
 * Definition:
 *     A small <WATERBODY_SHELTER_BASIN>, usually with a narrow
 *     <STRUCTURE_ENTRANCE>, situated inside a <HARBOUR>; a camber.
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, PHYSIOGRAPHY, SHELTER, TRNSP, USAGE_REGION
 */
#define ECC_CAMBER ((EDCS_Classification_Code)195)

/*
 * Definition:
 *     A <TRACT> where <TENT>s and/or <BUILDING>s serve as temporary
 *     residences; a camp.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_CAMP ((EDCS_Classification_Code)196)

/*
 * Definition:
 *     A <TRACT> designed for camping; a campground.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_CAMPGROUND ((EDCS_Classification_Code)197)

/*
 * Definition:
 *     A man-made or improved natural <WATERCOURSE> used for transportation,
 *     irrigation, and/or movement of <WATER>; a canal.
 *
 * Group Membership: AGRICULTURE, HYDROGRAPHIC_TRNSP, HYDROLOGY, INFRASTRUCTURE, TRNSP
 */
#define ECC_CANAL ((EDCS_Classification_Code)198)

/*
 * Definition:
 *     A representation of one or more <CANAL>s, especially in a
 *     <BUILT_UP_REGION>; a canal centre-line or canal nexus.
 *
 * Group Membership: AGRICULTURE, HYDROGRAPHIC_TRNSP, HYDROLOGY, INFRASTRUCTURE, LOCATION, TRNSP
 */
#define ECC_CANAL_NEXUS ((EDCS_Classification_Code)199)

/*
 * Definition:
 *     A navigable <MARINE_ROUTE> consisting primarily of <CANAL>s but
 *     sometimes including <WATERBODY>s (for example: <LAKE>s and/or
 *     <RESERVOIR>s).
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, HYDROLOGY,  INFRASTRUCTURE, LOCATION, TRNSP
 */
#define ECC_CANAL_ROUTE ((EDCS_Classification_Code)200)

/*
 * Definition:
 *     A deep <GORGE>, frequently with a <RIVER> at its bottom; a canyon
 *     [SOED, "canyon", A].
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_CANYON ((EDCS_Classification_Code)201)

/*
 * Definition:
 *     A <BUILDING> in which a national or sub-national legislature meets; a
 *     capitol building.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_CAPITOL_BUILDING ((EDCS_Classification_Code)202)

/*
 * Definition:
 *     The goods carried by a <VEHICLE>; a cargo [SOED, "cargo", 1.a] or load.
 *
 * Group Membership: INDUSTRY, TRNSP
 */
#define ECC_CARGO ((EDCS_Classification_Code)203)

/*
 * Definition:
 *     A large reusable <CONTAINER> that is designed for the efficient
 *     handling of <CARGO> by accommodating smaller cartons and/or cases in
 *     a single shipment.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY, TRNSP
 */
#define ECC_CARGO_CONTAINER ((EDCS_Classification_Code)204)

/*
 * Definition:
 *     A <FACILITY> used to store <CARGO_CONTAINER>s.
 *
 * Group Membership: INDUSTRY, TRNSP, USAGE_REGION
 */
#define ECC_CARGO_CONTAINER_FACILITY ((EDCS_Classification_Code)205)

/*
 * Definition:
 *     A <MAMMAL> of the order Carnivora; a carnivore. EXAMPLES Dog, cat,
 *     bear, seal.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_CARNIVORE ((EDCS_Classification_Code)206)

/*
 * Definition:
 *     A <BUILDING> in which wooden <OBJECT>s are manufactured or repaired; a
 *     carpentry building or a carpentry shop.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_CARPENTRY_BUILDING ((EDCS_Classification_Code)207)

/*
 * Definition:
 *     An unimproved <ROAD>; a cart track.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_CART_TRACK ((EDCS_Classification_Code)208)

/*
 * Definition:
 *     A large fortified <NON_EMPTY_SET> of <BUILDING>s with thick <WALL>s,
 *     usually dominating the surrounding <TERRAIN_SURFACE_REGION>; a castle
 *     [SOED, "castle", I.1].
 *
 * Group Membership: MILITARY_SCIENCE, SHELTER
 */
#define ECC_CASTLE ((EDCS_Classification_Code)209)

/*
 * Definition:
 *     A <DEVICE> in which the separation of <PETROLEUM> is carried out in
 *     the presence of a catalyst; a catalytic cracker.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY
 */
#define ECC_CATALYTIC_CRACKER ((EDCS_Classification_Code)210)

/*
 * Definition:
 *     A large, imposing <BUILDING> functioning as a <WORSHIP_PLACE>; a
 *     cathedral [SOED, "cathedral", 2].
 *
 * Group Membership: RELIGION
 */
#define ECC_CATHEDRAL ((EDCS_Classification_Code)211)

/*
 * Definition:
 *     The principal <CHURCH> of a diocese, containing the bishop's throne; a
 *     Catholic cathedral [SOED, "cathedral", B.1].
 *
 * Group Membership: RELIGION
 */
#define ECC_CATHOLIC_CATHEDRAL ((EDCS_Classification_Code)212)

/*
 * Definition:
 *     A suspended narrow footway or platform; a catwalk.
 *
 * Group Membership: TRNSP
 */
#define ECC_CATWALK ((EDCS_Classification_Code)213)

/*
 * Definition:
 *     A raised <ROAD> supported by a solid <STRUCTURE> and/or raised <LAND>
 *     providing a <LAND_TRANSPORTATION_ROUTE> across either a wet
 *     <TERRAIN_SURFACE_REGION> or an intertidal <TERRAIN_SURFACE_REGION>; a
 *     causeway.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, LAND_TRNSP, TRNSP
 */
#define ECC_CAUSEWAY ((EDCS_Classification_Code)214)

/*
 * Definition:
 *     A natural subterranean chamber or series of chambers open to the
 *     <PLANETARY_SURFACE>; a cave.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_CAVE ((EDCS_Classification_Code)215)

/*
 * Definition:
 *     The turbulent formation, generally mechanically induced and including
 *     growth and collapse, of bubbles in a fluid, occurring when the static
 *     pressure at any <LOCATION> in fluid flow is less than the fluid
 *     vapour pressure; cavitation.
 *
 * Group Membership: FLUID_CONDITION
 */
#define ECC_CAVITATION ((EDCS_Classification_Code)216)

/*
 * Definition:
 *     The noise produced in a liquid by the collapse of bubbles that have
 *     been created by <CAVITATION>.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, FLUID_CONDITION
 */
#define ECC_CAVITATION_NOISE ((EDCS_Classification_Code)217)

/*
 * Definition:
 *     A small insular <TRACT>, usually of <SAND> or <CORAL>, with scant
 *     <VEGETATION>; a cay or small coral shoal.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_CAY ((EDCS_Classification_Code)218)

/*
 * Definition:
 *     A <LINE> along which active hostilities are suspended; a cease fire
 *     line.
 *
 * Group Membership: DEMARCATION, MILITARY_SCIENCE
 */
#define ECC_CEASE_FIRE_LINE ((EDCS_Classification_Code)219)

/*
 * Definition:
 *     A space within a <BUILDING>, located above a <ROOM_CEILING>, and
 *     providing access to ducts and usually of restricted <<HEIGHT>> but
 *     having sufficient <<HEIGHT>> for <HUMAN>s to crawl; a ceiling crawl
 *     space.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_CEILING_CRAWL_SPACE ((EDCS_Classification_Code)220)

/*
 * Definition:
 *     Any <OBJECT> pertaining to the heavens and constituting a unit for
 *     astronomical study; a celestial body. EXAMPLES <STAR>, <MOON>,
 *     <PLANET>, <COMET>.
 *
 * Group Membership: ABSTRACT_OBJECT, SPACE
 */
#define ECC_CELESTIAL_BODY ((EDCS_Classification_Code)221)

/*
 * Definition:
 *     A <SITE> and associated <STRUCTURE>s devoted to the burial of the
 *     dead; a cemetery.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_CEMETERY ((EDCS_Classification_Code)222)

/*
 * Definition:
 *     A <BUILDING> associated with a <CEMETERY>.
 *
 * Group Membership: SHELTER
 */
#define ECC_CEMETERY_BUILDING ((EDCS_Classification_Code)223)

/*
 * Definition:
 *     A real or imaginary <LINE> indicating and/or marking the
 *     cross-sectional centre of an <OBJECT> along its primary extent; a
 *     centre-line.
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define ECC_CENTRE_LINE ((EDCS_Classification_Code)224)

/*
 * Definition:
 *     A <MOLLUSC> of the class Cephalopoda, members of which have a
 *     well-developed head surrounded by tentacles; a cephalopod [SOED,
 *     "cephlopod"]. EXAMPLES Cuttlefish, octopus, nautilus, ammonite
 *     (extinct form).
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_CEPHALOPOD ((EDCS_Classification_Code)225)

/*
 * Definition:
 *     A flexible length formed of metal links, rods, or plates, used as a
 *     tensioner and to drag, lift, support, and/or restrain <OBJECT>s; a
 *     chain.
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_CHAIN ((EDCS_Classification_Code)226)

/*
 * Definition:
 *     A <BUILDING> containing an office for public records; a chancery
 *     [SOED, "chancery", 3].
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_CHANCERY ((EDCS_Classification_Code)227)

/*
 * Definition:
 *     A <LINE> within a <REGION> indicating where the properties of the
 *     <REGION> change significantly; a change line.
 *
 * Group Membership: DEMARCATION, LOCATION
 */
#define ECC_CHANGE_LINE ((EDCS_Classification_Code)228)

/*
 * Definition:
 *     A <LOCATION> on a linear <OBJECT> where the properties of the <OBJECT>
 *     change significantly; a change point.
 *
 * Group Membership: LOCATION
 */
#define ECC_CHANGE_POINT ((EDCS_Classification_Code)229)

/*
 * Definition:
 *     A Christian <WORSHIP_PLACE>, usually smaller than a <CHURCH>, and
 *     especially one that is attached to a larger <BUILDING> (for example:
 *     a private <HOUSE> and/or an institution); a chapel [SOED, "chapel",
 *     1].
 *
 * Group Membership: BUILDING_COMPONENT, RELIGION
 */
#define ECC_CHAPEL ((EDCS_Classification_Code)230)

/*
 * Definition:
 *     An official <SITE> to register, declare, and/or check goods and
 *     <HUMAN>s; a checkpoint.
 *
 * Group Membership: ADMINISTRATION
 */
#define ECC_CHECKPOINT ((EDCS_Classification_Code)231)

/*
 * Definition:
 *     A <REGION> in which a chemical substance is present that can kill,
 *     seriously injure, and/or incapacitate a <HUMAN> or <NON_HUMAN_ANIMAL>
 *     through its physiological properties. The chemical substance is
 *     usually dispersed over a <SURFACE> and/or within the <ATMOSPHERE>.
 *
 * Group Membership: ATMOSPHERE, SURFACE_MATERIAL, SURFACE
 */
#define ECC_CHEMICAL_HAZARD_REGION ((EDCS_Classification_Code)232)

/*
 * Definition:
 *     A <COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE> attached to and rising
 *     above the <ROOF> of a <BUILDING>; a chimney.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_CHIMNEY ((EDCS_Classification_Code)233)

/*
 * Definition:
 *     A <BUILDING> functioning as a <WORSHIP_PLACE> for public Christian
 *     worship; a Christian temple [SOED, "temple", A.I.3].
 *
 * Group Membership: RELIGION
 */
#define ECC_CHRISTIAN_TEMPLE ((EDCS_Classification_Code)234)

/*
 * Definition:
 *     A <BUILDING> functioning as a <WORSHIP_PLACE> for public, especially
 *     Christian, worship; a church [SOED, "church", 1].
 *
 * Group Membership: RELIGION
 */
#define ECC_CHURCH ((EDCS_Classification_Code)235)

/*
 * Definition:
 *     An elevated irrigation <SYSTEM> revolving around a central pivot
 *     <LOCATION>; a circular irrigation system.
 *
 * Group Membership: AGRICULTURE
 */
#define ECC_CIRCULAR_IRRIGATION_SYSTEM ((EDCS_Classification_Code)236)

/*
 * Definition:
 *     A man-made <CONTAINER> used for the collection and/or storage of
 *     <RAIN>; a cistern.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define ECC_CISTERN ((EDCS_Classification_Code)237)

/*
 * Definition:
 *     A concentration of <DWELLING>s, <COMMERCIAL_BUILDING>s,
 *     <INDUSTRIAL_BUILDING>s, and other <STRUCTURE>s where <HUMAN>s have
 *     settled that is larger than a <TOWN> and usually smaller than a
 *     <BUILT_UP_REGION>; a city.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_CITY ((EDCS_Classification_Code)238)

/*
 * Definition:
 *     The <MUNICIPAL_HALL> of a <CITY>.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_CITY_HALL ((EDCS_Classification_Code)239)

/*
 * Definition:
 *     A <MOTOR_VEHICLE> used for civilian activities.
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_CIVILIAN_MOTOR_VEHICLE ((EDCS_Classification_Code)240)

/*
 * Definition:
 *     <PERSONNEL> that are not members of an armed force; civilian personnel.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, MILITARY_SCIENCE
 */
#define ECC_CIVILIAN_PERSONNEL ((EDCS_Classification_Code)241)

/*
 * Definition:
 *     A <BOUNDARY> of a <REGION> that is unilaterally claimed by one
 *     political group without the consent of or negotiation with another; a
 *     claim line.
 *
 * Group Membership: ADMINISTRATION, DEMARCATION, LOCATION
 */
#define ECC_CLAIM_LINE ((EDCS_Classification_Code)242)

/*
 * Definition:
 *     A vertical or nearly vertical face of <ROCK> in the <TERRAIN> of
 *     considerable <<HEIGHT>>; a cliff.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_CLIFF ((EDCS_Classification_Code)243)

/*
 * Definition:
 *     A <LINE> representing the demarcation of a sudden and significant
 *     change in the gradient of the terrain relief occurring at the bottom
 *     of a <CLIFF>.
 *
 * Group Membership: DEMARCATION, LOCATION, PHYSIOGRAPHY
 */
#define ECC_CLIFF_BOTTOMLINE ((EDCS_Classification_Code)244)

/*
 * Definition:
 *     A <DWELLING> built into the recesses of a <CLIFF>.
 *
 * Group Membership: SHELTER
 */
#define ECC_CLIFF_DWELLING ((EDCS_Classification_Code)245)

/*
 * Definition:
 *     A <LINE> representing the demarcation of a sudden and significant
 *     change in the gradient of the terrain relief occurring at the top of
 *     a <CLIFF>.
 *
 * Group Membership: DEMARCATION, LOCATION, PHYSIOGRAPHY
 */
#define ECC_CLIFF_TOPLINE ((EDCS_Classification_Code)246)

/*
 * Definition:
 *     A small <ROOM> belonging with and opening to a larger <ROOM>; a closet.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_CLOSET ((EDCS_Classification_Code)247)

/*
 * Definition:
 *     A visible aggregate of minute droplets of <WATER>, <PARTICLE>s of
 *     <ICE>, or both, suspended in the <ATMOSPHERE> above the
 *     <PLANETARY_SURFACE> of the <EARTH>; a cloud.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, ICE
 */
#define ECC_CLOUD ((EDCS_Classification_Code)248)

/*
 * Definition:
 *     The lowest level in a specific <CLOUD> or <CLOUD_LAYER> where the
 *     <ATMOSPHERE> contains a perceptible quantity of <PARTICLE>s of the
 *     <CLOUD>; the cloud base.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_CLOUD_BASE ((EDCS_Classification_Code)249)

/*
 * Definition:
 *     An arrangement of <CLOUD>s, continuous or composed of separated
 *     <COMPONENT>s, where the <<CLOUD_BASE_LEVEL>>s are the same and the
 *     <<CLOUD_THICKNESS>>s are approximately the same; a cloud layer.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_CLOUD_LAYER ((EDCS_Classification_Code)250)

/*
 * Definition:
 *     The highest level in a specific <CLOUD> or <CLOUD_LAYER> where the
 *     <ATMOSPHERE> contains a perceptible quantity of <PARTICLE>s of the
 *     <CLOUD>; the cloud top.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_CLOUD_TOP ((EDCS_Classification_Code)251)

/*
 * Definition:
 *     A <TERRAIN_STRIP> of indefinite <<WIDTH>> that extends from the
 *     <COASTLINE> inland to the first major change in the <TERRAIN>; a
 *     coast [SOED, "coast", 2].
 *
 * Group Membership: DEMARCATION, LITTORAL, PHYSIOGRAPHY
 */
#define ECC_COAST ((EDCS_Classification_Code)252)

/*
 * Definition:
 *     The <LAND_WATER_BOUNDARY> where the <COAST> and the <SHORE> are in
 *     contact; a coastline.
 *
 * Group Membership: DEMARCATION, LITTORAL
 */
#define ECC_COASTLINE ((EDCS_Classification_Code)253)

/*
 * Definition:
 *     An <ATMOSPHERIC_FRONT> between warm and cold <AIR_MASS>s that is not
 *     an <OCCLUDED_FRONT> and that moves so that the colder <AIR> replaces
 *     the warmer <AIR>; a cold front.
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, LOCATION, TEMPERATURE
 */
#define ECC_COLD_FRONT ((EDCS_Classification_Code)254)

/*
 * Definition:
 *     The <BUILDING>s and <GROUNDS> of an institution offering special
 *     instruction in professional and/or technical subjects, which may also
 *     include <FACILITY>s for research and the award of advanced degrees; a
 *     university campus or college campus.
 *
 * Group Membership: INFRASTRUCTURE, SHELTER, USAGE_REGION
 */
#define ECC_COLLEGIATE_CAMPUS ((EDCS_Classification_Code)255)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> designed or designated to support underway
 *     replenishment of <COMBAT_SUPPORT_VESSEL>s and <COMBATANT_VESSEL>s; a
 *     combat stores vessel.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_COMBAT_STORES_VESSEL ((EDCS_Classification_Code)256)

/*
 * Definition:
 *     A <GROUND_VEHICLE> designed or designated to provide support and
 *     operational assistance to <COMBATANT_VEHICLE>s; a combat support
 *     vehicle.
 *
 * Group Membership: MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_COMBAT_SUPPORT_VEHICLE ((EDCS_Classification_Code)257)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> designed or designated to provide support and
 *     operational assistance to <COMBATANT_VESSEL>s; a combat support
 *     vessel.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_COMBAT_SUPPORT_VESSEL ((EDCS_Classification_Code)258)

/*
 * Definition:
 *     A <GROUND_VEHICLE> designed or designated to participate in military
 *     combat operations as a combatant.
 *
 * Group Membership: MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_COMBATANT_VEHICLE ((EDCS_Classification_Code)259)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> designed or designated to participate in
 *     military combat operations as a combatant.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_COMBATANT_VESSEL ((EDCS_Classification_Code)260)

/*
 * Definition:
 *     A vertical <STRUCTURE> containing a passage and/or flue for
 *     discharging <SMOKE> and gases of combustion; a combustion product
 *     discharge structure.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE ((EDCS_Classification_Code)261)

/*
 * Definition:
 *     A <CELESTIAL_BODY> that orbits a <STAR> in a highly elliptical path
 *     and, when in the vicinity of that <STAR>, usually has a bright hazy
 *     head and a long more diffuse tail; a comet [SOED, "comet", A.1].
 *
 * Group Membership: SPACE
 */
#define ECC_COMET ((EDCS_Classification_Code)262)

/*
 * Definition:
 *     A <BUILDING> used to conduct business activities; a commercial
 *     building.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_COMMERCIAL_BUILDING ((EDCS_Classification_Code)263)

/*
 * Definition:
 *     A <HELICOPTER> designed or designated for use in commerce.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_COMMERCIAL_HELICOPTER ((EDCS_Classification_Code)264)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed or designated for use in commerce.
 *
 * Group Membership: AIR_TRNSP, INDUSTRY, TRNSP, VEHICLE
 */
#define ECC_COMMERCIAL_WINGED_AIRCRAFT ((EDCS_Classification_Code)265)

/*
 * Definition:
 *     A <FACILITY> including one or more <COMMUNICATION_STATION>s.
 *
 * Group Membership: COMMUNICATION, INFRASTRUCTURE, SHELTER, USAGE_REGION
 */
#define ECC_COMMUNICATION_FACILITY ((EDCS_Classification_Code)266)

/*
 * Definition:
 *     A <BUILDING> in which communication signals are processed and/or
 *     controlled; a communication station. EXAMPLES Telephone switching
 *     station, microwave repeater station, <SATELLITE_GROUND_STATION>,
 *     cellular telephone <EQUIPMENT>, land-line telephone repeater station.
 *
 * Group Membership: COMMUNICATION, INFRASTRUCTURE, SHELTER
 */
#define ECC_COMMUNICATION_STATION ((EDCS_Classification_Code)267)

/*
 * Definition:
 *     A <TOWER> used for supporting an <AERIAL> for transmitting and/or
 *     receiving electronic communication signals.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE, SUPPORT_STRUCTURE
 */
#define ECC_COMMUNICATION_TOWER ((EDCS_Classification_Code)268)

/*
 * Definition:
 *     A <BUILDING> used for recreational exercise and minor sports
 *     competitions, which typically serves a small <TOWN>, community, or
 *     local <BUILT_UP_REGION>; a community recreation building or a
 *     community centre.
 *
 * Group Membership: RECREATION, SHELTER
 */
#define ECC_COMMUNITY_RECREATION_BUILDING ((EDCS_Classification_Code)269)

/*
 * Definition:
 *     A <FACILITY> including one or more <COMMUNITY_RECREATION_BUILDING>s.
 *
 * Group Membership: RECREATION, SHELTER, USAGE_REGION
 */
#define ECC_COMMUNITY_RECREATION_FACILITY ((EDCS_Classification_Code)270)

/*
 * Definition:
 *     The <BOUNDARY> delimiting a <REGION> in which two or more like
 *     <OBJECT>s have the same function; a complex outline.
 *
 * Group Membership: DEMARCATION, LOCATION
 */
#define ECC_COMPLEX_OUTLINE ((EDCS_Classification_Code)271)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <ATS_ROUTE>s, action points, and various approach
 *     minimum altitudes and distances from the end of a landing <RUNWAY> as
 *     functions of <AIRCRAFT> type and instrument approach procedures; a
 *     complex terminal route.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_COMPLEX_TERMINAL_ROUTE ((EDCS_Classification_Code)272)

/*
 * Definition:
 *     An <OBJECT> that is a constituent part of another (aggregate) <OBJECT>
 *     but, by itself, does not fulfill the function of the aggregate; a
 *     component.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_COMPONENT ((EDCS_Classification_Code)273)

/*
 * Definition:
 *     A <BUILDING> housing the residence and/or official premises of an
 *     official appointed by a government to reside in a foreign country,
 *     represent its commercial interests, and assist its citizens there; a
 *     consulate.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_CONSULATE ((EDCS_Classification_Code)274)

/*
 * Definition:
 *     A <TERRAIN_STRIP> that is 3 metres wide and limited on one side by the
 *     <LAND_WATER_BOUNDARY> of a <WATERBODY> under average water level
 *     conditions; a contact zone.
 *
 * Group Membership: DEMARCATION, PHYSIOGRAPHY
 */
#define ECC_CONTACT_ZONE ((EDCS_Classification_Code)275)

/*
 * Definition:
 *     A <DEVICE> designed to contain <MATERIAL>s; a container [SOED,
 *     "container"].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_CONTAINER ((EDCS_Classification_Code)276)

/*
 * Definition:
 *     An elevation or depression <ISOPLETH>; a contour.
 *
 * Group Membership: LOCATION
 */
#define ECC_CONTOUR ((EDCS_Classification_Code)277)

/*
 * Definition:
 *     A panel on which are mounted switches, dials, and/or other mechanisms
 *     for the remote control and/or operation of <EQUIPMENT> (for example:
 *     electrical <EQUIPMENT>).
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_CONTROL_PANEL ((EDCS_Classification_Code)278)

/*
 * Definition:
 *     A <TOWER> that houses <PERSONNEL> and <EQUIPMENT> used to control the
 *     flow of traffic on a <TRANSPORTATION_ROUTE>; a control tower.
 *
 * Group Membership: TRNSP
 */
#define ECC_CONTROL_TOWER ((EDCS_Classification_Code)279)

/*
 * Definition:
 *     A value of an EDCS Attribute or an algorithmic quantity to be used in
 *     evaluating an algorithmic expression; a control value.
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define ECC_CONTROL_VALUE ((EDCS_Classification_Code)280)

/*
 * Definition:
 *     A designated <AIRSPACE> within which some or all <AIRCRAFT> may be
 *     subjected to air traffic control; a controlled airspace.
 *
 * Group Membership: AIR_TRNSP
 */
#define ECC_CONTROLLED_AIRSPACE ((EDCS_Classification_Code)281)

/*
 * Definition:
 *     A <RELIGIOUS_COMMUNITY> of women; a convent [SOED, "convent", 3].
 *
 * Group Membership: RELIGION
 */
#define ECC_CONVENT ((EDCS_Classification_Code)282)

/*
 * Definition:
 *     <EQUIPMENT> for moving <MATERIAL>s from place to place on a moving
 *     belt or series of rollers; a conveyor.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY, TRNSP
 */
#define ECC_CONVEYOR ((EDCS_Classification_Code)283)

/*
 * Definition:
 *     A <TOWER> used to cool liquids; a cooling tower.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_COOLING_TOWER ((EDCS_Classification_Code)284)

/*
 * Definition:
 *     A hard calcareous <MATERIAL> consisting of the continuous skeleton of
 *     marine coelenterate polyps; coral [SOED, "coral", 1].
 *
 * Group Membership: MATERIAL
 */
#define ECC_CORAL ((EDCS_Classification_Code)285)

/*
 * Definition:
 *     A <BUILDING> within which persons convicted or accused of crimes are
 *     confined; a penitentiary or correctional building.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_CORRECTIONAL_BUILDING ((EDCS_Classification_Code)286)

/*
 * Definition:
 *     A <FACILITY> including one or more <CORRECTIONAL_BUILDING>s; a
 *     correctional facility.
 *
 * Group Membership: ADMINISTRATION, SHELTER, USAGE_REGION
 */
#define ECC_CORRECTIONAL_FACILITY ((EDCS_Classification_Code)287)

/*
 * Definition:
 *     A <BUILDING> that houses the main offices of a county government; a
 *     county hall or court-house (US).
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_COUNTY_HALL ((EDCS_Classification_Code)288)

/*
 * Definition:
 *     An open <TRACT> surrounded by <WALL>s and/or <BUILDING>s that is
 *     located within the precincts of a large <BUILDING>, <CASTLE>, or
 *     <BUILT_UP_REGION>; a courtyard.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_COURTYARD ((EDCS_Classification_Code)289)

/*
 * Definition:
 *     A covered portion of a <WATERCOURSE>, preventing its observation.
 *
 * Group Membership: HYDROLOGY, INFRASTRUCTURE, SHELTER
 */
#define ECC_COVERED_WATERCOURSE ((EDCS_Classification_Code)290)

/*
 * Definition:
 *     <EQUIPMENT> for lifting, shifting, and lowering <OBJECT>s or
 *     <MATERIAL>s by means of a swinging boom or with a lifting apparatus
 *     supported on an overhead track; a crane.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY, LAND_INDUSTRY
 */
#define ECC_CRANE ((EDCS_Classification_Code)291)

/*
 * Definition:
 *     A deep crack or fissure in a <GLACIER>, which results from
 *     differential movement of <ICE>, or a deep vertical opening in the
 *     <TERRAIN> that appears after an earthquake; a crevasse.
 *
 * Group Membership: ICE, PHYSIOGRAPHY
 */
#define ECC_CREVASSE ((EDCS_Classification_Code)292)

/*
 * Definition:
 *     A narrow opening or fissure produced by a crack in the <TERRAIN>,
 *     especially in <ROCK>; a crevice [SOED, "crevice", 1].
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_CREVICE ((EDCS_Classification_Code)293)

/*
 * Definition:
 *     A permanent <STRUCTURE> set in a <WATERBODY>, framed with heavy wooden
 *     beams, and sunken with debris (for example: <STONE>s), usually
 *     designed to support or elevate <PIPELINE>s; especially a <STRUCTURE>
 *     enclosing a screening <DEVICE> at the offshore end of a potable
 *     <WATER_INTAKE>; a crib.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, INFRASTRUCTURE, SUPPORT_STRUCTURE
 */
#define ECC_CRIB ((EDCS_Classification_Code)294)

/*
 * Definition:
 *     A <TRACT> that has been tilled for the planting of crops.
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_CROP_LAND ((EDCS_Classification_Code)295)

/*
 * Definition:
 *     A permanent or semi-permanent <BARRIER> placed across any <TERRAIN> to
 *     prevent <GROUND_VEHICLE> or pedestrian traffic.
 *
 * Group Membership: TRNSP
 */
#define ECC_CROSS_COUNTRY_BARRIER ((EDCS_Classification_Code)296)

/*
 * Definition:
 *     A <LOCATION> where <LAND_TRANSPORTATION_ROUTE>s intersect or cross at
 *     the same vertical level; a crossing. EXAMPLES Railway crossing, road
 *     intersection, <FORD>.
 *
 * Group Membership: LAND_TRNSP, LOCATION, TRNSP
 */
#define ECC_CROSSING ((EDCS_Classification_Code)297)

/*
 * Definition:
 *     A fast, medium tonnage <WATER_SURFACE_VESSEL> operating over a long
 *     cruising radius; a cruiser [AHD, "cruiser", 1].
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_CRUISER ((EDCS_Classification_Code)298)

/*
 * Definition:
 *     An <ARTHROPOD> of the large class Crustacea, mainly aquatic and
 *     hard-shelled; a crustacean [SOED, "crustacean", A]. EXAMPLES Crab,
 *     lobster, shrimp, woodlouse.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_CRUSTACEAN ((EDCS_Classification_Code)299)

/*
 * Definition:
 *     A <SEWER> or drain crossing under a <ROAD>, <RAILWAY>, or <EMBANKMENT>
 *     without affecting the construction of the crossed <OBJECT>; a culvert.
 *
 * Group Membership: INFRASTRUCTURE, LAND_TRNSP, TRNSP
 */
#define ECC_CULVERT ((EDCS_Classification_Code)300)

/*
 * Definition:
 *     A body of a fluid that is flowing in a definite <DIRECTION>; a current
 *     [SOED, "current", A.2].
 *
 * Group Membership: FLUID_CONDITION
 */
#define ECC_CURRENT ((EDCS_Classification_Code)301)

/*
 * Definition:
 *     A <GOVERNMENT_BUILDING> serving as a <CHECKPOINT> where customs duties
 *     are collected and shipments or <VEHICLE>s are cleared for entering or
 *     leaving a country; a customs house.
 *
 * Group Membership: ADMINISTRATION, SHELTER, TRNSP
 */
#define ECC_CUSTOMS_HOUSE ((EDCS_Classification_Code)302)

/*
 * Definition:
 *     An <ATMOSPHERE_REGION> in which the <<ATM_PRESSURE>>s are lower than
 *     those of the surrounding <ATMOSPHERE_REGION> at the same
 *     <<ALTITUDE_MSL>>; a depression or cyclone.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_CYCLONE ((EDCS_Classification_Code)303)

/*
 * Definition:
 *     A permanent <BARRIER> across a <WATERCOURSE> that is used to impound
 *     <WATER> and/or to control its flow; a dam.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, INFRASTRUCTURE
 */
#define ECC_DAM ((EDCS_Classification_Code)304)

/*
 * Definition:
 *     A <BOUNDARY> between two <DATA_QUALITY_REGION>s.
 *
 * Group Membership: DEMARCATION, LOCATION, SURVEY
 */
#define ECC_DATA_QUALITY_BOUNDARY ((EDCS_Classification_Code)305)

/*
 * Definition:
 *     A <REGION> with specific data quality characteristics.
 *
 * Group Membership: SURVEY
 */
#define ECC_DATA_QUALITY_REGION ((EDCS_Classification_Code)306)

/*
 * Definition:
 *     An <OBJECT> used as a reference for defining spatial aspects of other
 *     <OBJECT>s; a datum.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_DATUM ((EDCS_Classification_Code)307)

/*
 * Definition:
 *     A <SITE> where a radiologically, biologically, and/or chemically
 *     contaminated <AIRCRAFT> is sent for decontamination; a
 *     decontamination pad.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_DECONTAMINATION_PAD ((EDCS_Classification_Code)308)

/*
 * Definition:
 *     The deepest <SOUND_CHANNEL> in an <OCEAN>.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_STATE
 */
#define ECC_DEEP_SOUND_CHANNEL ((EDCS_Classification_Code)309)

/*
 * Definition:
 *     A <MARINE_ROUTE> through a deep <WATERBODY> plus related
 *     <NAVIGATION_MARK_FIXED>s and/or <NAVIGATION_MARK_AFLOAT>s; a deep
 *     water route.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_DEEP_WATER_ROUTE ((EDCS_Classification_Code)310)

/*
 * Definition:
 *     A <BOUNDARY> not officially recognized by various governments; a
 *     defacto boundary.
 *
 * Group Membership: ADMINISTRATION, DEMARCATION, LOCATION
 */
#define ECC_DEFACTO_BOUNDARY ((EDCS_Classification_Code)311)

/*
 * Definition:
 *     One or more <STRUCTURE>s constructed for the military defence of a
 *     <SITE> that are resistant to <MUNITION>s; a defensive position.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_DEFENSIVE_POSITION ((EDCS_Classification_Code)312)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> affording protection or shielding from
 *     hostile ground observation and flat projecting fire; the protection
 *     is provided by a <TERRAIN_OBSTACLE> (for example: a
 *     <DEFENSIVE_POSITION>, a <HILL>, and/or a <PARAPET>); a defensive
 *     position defilade.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_DEFENSIVE_POSITION_DEFILADE ((EDCS_Classification_Code)313)

/*
 * Definition:
 *     A <REGION> plus related <NAVIGATION_MARK_FIXED>s and/or
 *     <NAVIGATION_MARK_AFLOAT>s of a <WATERBODY> delimited for the purposes
 *     of: defining <MARINE_ROUTE>s; communicating port signals or
 *     communicating firing practice signals; or serving as a <WAYPOINT>,
 *     <CALLING_IN_POINT>, or an <ANCHORAGE>; defined water.
 *
 * Group Membership: COMMUNICATION, HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_DEFINED_WATER ((EDCS_Classification_Code)314)

/*
 * Definition:
 *     A <REGION> where military activity is prohibited; a demilitarized zone.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_DEMILITARIZED_ZONE ((EDCS_Classification_Code)315)

/*
 * Definition:
 *     A <RAILWAY_STATION> or <BUS_STATION>, usually with an attached
 *     <WAREHOUSE>; a depot.
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_DEPOT ((EDCS_Classification_Code)316)

/*
 * Definition:
 *     An <ISOPLETH> of constant depth at and below a <SURFACE_DATUM>; a
 *     depth contour.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_DEPTH_CONTOUR_LINE ((EDCS_Classification_Code)317)

/*
 * Definition:
 *     A navigational safety <LINE> indicating that no <SOUNDING> of a lesser
 *     depth exists seaward of the <LINE>, but greater depths may occur on
 *     the shallow side of the <LINE>; a depth curve.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, SURVEY, TRNSP
 */
#define ECC_DEPTH_CURVE ((EDCS_Classification_Code)318)

/*
 * Definition:
 *     A <WATERBODY_REGION> containing <SOUNDING>s within a defined range of
 *     values permanently at or below a reference <SURFACE_DATUM>; a depth
 *     region.
 *
 * Group Membership: HYDROLOGY, SURVEY
 */
#define ECC_DEPTH_REGION ((EDCS_Classification_Code)319)

/*
 * Definition:
 *     A <LOCATION> at which text pertaining to that <LOCATION> is annotated;
 *     a described point.
 *
 * Group Membership: LOCATION
 */
#define ECC_DESCRIBED_POINT ((EDCS_Classification_Code)320)

/*
 * Definition:
 *     A dry, often sandy, <TRACT> of little rainfall, extreme
 *     <<AIR_TEMPERATURE>>s, and sparse <VEGETATION>; a desert region [AHD,
 *     "desert", 1.a].
 *
 * Group Membership: PHYSIOGRAPHY, TEMPERATURE
 */
#define ECC_DESERT_REGION ((EDCS_Classification_Code)321)

/*
 * Definition:
 *     A fast, highly maneuverable <WATER_SURFACE_VESSEL> armed with guns,
 *     torpedoes, and depth charges; a destroyer [AHD, "destroyer", 2].
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_DESTROYER ((EDCS_Classification_Code)322)

/*
 * Definition:
 *     A <FACILITY> for the confinement of <HUMAN>s in lawful detention who
 *     are convicted or accused of crimes; a detention facility.
 *
 * Group Membership: ADMINISTRATION, USAGE_REGION
 */
#define ECC_DETENTION_FACILITY ((EDCS_Classification_Code)323)

/*
 * Definition:
 *     An <OBJECT> designed for a particular function or adapted for a
 *     particular purpose, especially a (simple) mechanical contrivance; a
 *     device [SOED, "device", 3].
 *
 * Group Membership: ABSTRACT_OBJECT, DEVICE_AND_EQUIPMENT
 */
#define ECC_DEVICE ((EDCS_Classification_Code)324)

/*
 * Definition:
 *     A <LOCATION> used to check the accuracy of a <SYSTEM>; a diagnostic
 *     point.
 *
 * Group Membership: LOCATION
 */
#define ECC_DIAGNOSTIC_POINT ((EDCS_Classification_Code)325)

/*
 * Definition:
 *     <SOLID_PRECIPITATION> that falls from a clear sky in very small
 *     crystals of <ICE>, often so tiny that they appear to be suspended in
 *     the <AIR>; diamond dust.
 *
 * Group Membership: ATMOSPHERE, ICE, MATERIAL
 */
#define ECC_DIAMOND_DUST ((EDCS_Classification_Code)326)

/*
 * Definition:
 *     A <BUILDING> that houses and/or supports the activities of an
 *     ambassador; a diplomatic building.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_DIPLOMATIC_BUILDING ((EDCS_Classification_Code)327)

/*
 * Definition:
 *     A direction in relation to a <LOCATION>. EXAMPLES Course, bearing.
 *
 * Group Membership: LOCATION
 */
#define ECC_DIRECTION ((EDCS_Classification_Code)328)

/*
 * Definition:
 *     A steerable and self-propelled <AIRSHIP> with a rigid, elongated
 *     frame; a dirigible.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_DIRIGIBLE ((EDCS_Classification_Code)329)

/*
 * Definition:
 *     A <WATERBODY_REGION> having a colour distinctly different from that of
 *     the surrounding <REGION>; discoloured water.
 *
 * Group Membership: COLOUR, HYDROLOGY
 */
#define ECC_DISCOLOURED_WATER ((EDCS_Classification_Code)330)

/*
 * Definition:
 *     A concave-shaped <AERIAL> that is used for transmitting and/or
 *     receiving electronic signals; a dish aerial.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_DISH_AERIAL ((EDCS_Classification_Code)331)

/*
 * Definition:
 *     A specially constructed <LIGHT> that illuminates <DISPLAY_SIGN>s or
 *     other <STRUCTURE>s; a display light.
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define ECC_DISPLAY_LIGHT ((EDCS_Classification_Code)332)

/*
 * Definition:
 *     An upright panel or similar <STRUCTURE> used to convey visual
 *     information; a display sign.
 *
 * Group Membership: COMMUNICATION
 */
#define ECC_DISPLAY_SIGN ((EDCS_Classification_Code)333)

/*
 * Definition:
 *     A <SITE> for the collection and/or deposition of refuse or discarded
 *     <MATERIAL>; a disposal site.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_DISPOSAL_SITE ((EDCS_Classification_Code)334)

/*
 * Definition:
 *     A <MARKER> that indicates the value of distance measured from a
 *     starting <LOCATION> and consists of either a solid visible
 *     <STRUCTURE> or a distinct <LOCATION> without a special installation;
 *     a distance mark.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_DISTANCE_MARK ((EDCS_Classification_Code)335)

/*
 * Definition:
 *     A <MARKER> that designates the distance from a given <LOCATION>; a
 *     distance post.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_DISTANCE_POST ((EDCS_Classification_Code)336)

/*
 * Definition:
 *     <LAND> so disturbed as to have no identifiable type of <SOIL>;
 *     disturbed soil.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_DISTURBED_SOIL ((EDCS_Classification_Code)337)

/*
 * Definition:
 *     The space between two <PIER>s; a dock or a slip.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_DOCK ((EDCS_Classification_Code)338)

/*
 * Definition:
 *     A hinged or sliding <BARRIER> to the ingress into or egress from a
 *     <COMPONENT> of a <STRUCTURE> or <VEHICLE>; a door [SOED, "door", 1.a].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_DOOR ((EDCS_Classification_Code)339)

/*
 * Definition:
 *     A <BUILDING> used to house <CIVILIAN_PERSONNEL> that is typically
 *     large, unadorned, and intended for relatively temporary occupancy; a
 *     dormitory.
 *
 * Group Membership: SHELTER
 */
#define ECC_DORMITORY ((EDCS_Classification_Code)340)

/*
 * Definition:
 *     Excavating <EQUIPMENT> consisting of a steel scoop that swings on
 *     <CHAIN>s from a movable jib; the scoop is cast into the <MATERIAL> to
 *     be excavated and dragged back to the jib where it is lifted and
 *     dumped; a dragline.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY
 */
#define ECC_DRAGLINE ((EDCS_Classification_Code)341)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of regularly spaced concrete or metal
 *     <TERRAIN_OBSTACLE>s laid in single or multiple rows to prevent the
 *     movement of <GROUND_VEHICLE>s; dragon's teeth or dragon teeth.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_DRAGON_TEETH ((EDCS_Classification_Code)342)

/*
 * Definition:
 *     <EQUIPMENT> for collecting and bringing up <OBJECT>s or <MATERIAL>
 *     from a <WATERBODY_FLOOR> by dragging or scooping; a dredge [SOED,
 *     "dredge", 2].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_INDUSTRY, INDUSTRY, WATERBODY_FLOOR
 */
#define ECC_DREDGE ((EDCS_Classification_Code)343)

/*
 * Definition:
 *     A <STRUCTURE> that enables <EQUIPMENT> (for example: a drill and/or
 *     instrumentation) to create a hole or to be deployed in a hole in the
 *     <TERRAIN>; a drilling rig.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_DRILLING_RIG ((EDCS_Classification_Code)344)

/*
 * Definition:
 *     The <SUPERSTRUCTURE> of a <DRILLING_RIG> that includes a <TOWER>,
 *     drill floor, and associated <EQUIPMENT>, including <LOAD_CABLE>s,
 *     pulleys, motors, and compressors.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_DRILLING_RIG_SUPERSTRUCTURE ((EDCS_Classification_Code)345)

/*
 * Definition:
 *     A man-made open <CONTAINER> holding <WATER> for drinking by
 *     <NON_HUMAN_ANIMAL>s; a drinking trough.
 *
 * Group Membership: ANIMAL, DEVICE_AND_EQUIPMENT, LIVING_ORGANISM
 */
#define ECC_DRINKING_TROUGH ((EDCS_Classification_Code)346)

/*
 * Definition:
 *     A <RECREATIONAL_FACILITY> where motion pictures are shown on
 *     <DRIVE_IN_THEATRE_SCREEN>s while viewers remain in their
 *     <GROUND_VEHICLE>s; a drive in theatre.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_DRIVE_IN_THEATRE ((EDCS_Classification_Code)347)

/*
 * Definition:
 *     A large outdoor screen <STRUCTURE> for showing motion pictures; a
 *     drive in theatre screen.
 *
 * Group Membership: RECREATION
 */
#define ECC_DRIVE_IN_THEATRE_SCREEN ((EDCS_Classification_Code)348)

/*
 * Definition:
 *     A private <ROAD> alongside, in front of, or leading to a <BUILDING>
 *     (for example: a <HOUSE> and/or a <PARKING_GARAGE>); a driveway [SOED,
 *     "driveway"].
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_DRIVEWAY ((EDCS_Classification_Code)349)

/*
 * Definition:
 *     Fairly uniform <PRECIPITATION> in very fine droplets
 *     (<<OUTSIDE_DIAMETER>> less than 0,5 millimetres) that are located
 *     very close to one another and are falling from a <CLOUD>; drizzle or
 *     mist.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_DRIZZLE ((EDCS_Classification_Code)350)

/*
 * Definition:
 *     A massive assemblage of <MATERIAL> (for example: concrete blocks
 *     and/or concrete cylinders) that is positioned above a
 *     <LAND_TRANSPORTATION_ROUTE> and is ready to be activated when needed
 *     as a potential <BARRIER> to an advancing enemy ground force; a drop
 *     gate.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define ECC_DROP_GATE ((EDCS_Classification_Code)351)

/*
 * Definition:
 *     A wide <TRAIL> created by the regular movement of herds of
 *     <NON_HUMAN_ANIMAL>s; a drove.
 *
 * Group Membership: ANIMAL, LAND_TRNSP, LIVING_ORGANISM, TRNSP
 */
#define ECC_DROVE ((EDCS_Classification_Code)352)

/*
 * Definition:
 *     An artificial <WATERBODY_SHELTER_BASIN> fitted with a <MARINE_GATE> or
 *     <CAISSON> into which <VESSEL>s can be floated and the <WATER> pumped
 *     out to expose the bottom of the <VESSEL>; a dry dock or graving dock.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, SHELTER, TRNSP, USAGE_REGION
 */
#define ECC_DRY_DOCK ((EDCS_Classification_Code)353)

/*
 * Definition:
 *     A nearly level <TRACT> at the bottom of an undrained
 *     <GEOGRAPHIC_BASIN> in a <DESERT_REGION>, sometimes temporarily
 *     covered with <WATER>; a dry lake.
 *
 * Group Membership: HYDROLOGY, PHYSIOGRAPHY
 */
#define ECC_DRY_LAKE ((EDCS_Classification_Code)354)

/*
 * Definition:
 *     A <TRACT> neither permanently nor temporarily covered by <WATER>; dry
 *     land.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_DRY_LAND ((EDCS_Classification_Code)355)

/*
 * Definition:
 *     Solid <MATERIAL>s (for example: <SOIL>) in a minute and fine state of
 *     subdivision, so that the <PARTICLE>s are small and light enough to be
 *     easily raised and carried by the <WIND>; dust [SOED, "dust", 1].
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, MATERIAL
 */
#define ECC_DUST ((EDCS_Classification_Code)356)

/*
 * Definition:
 *     A <NON_AQUEOUS_CLOUD>, <PLUME>, and/or <PUFF> composed of`<DUST>; a
 *     dust suspension.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_DUST_SUSPENSION ((EDCS_Classification_Code)357)

/*
 * Definition:
 *     A <SHELTER> (for example: a <BUILDING>) used for living quarters; a
 *     dwelling.
 *
 * Group Membership: SHELTER
 */
#define ECC_DWELLING ((EDCS_Classification_Code)358)

/*
 * Definition:
 *     An artificial <EMBANKMENT> to contain <WATER>; a dyke.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT
 */
#define ECC_DYKE ((EDCS_Classification_Code)359)

/*
 * Definition:
 *     The top of a <DYKE>.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT
 */
#define ECC_DYKE_TOP ((EDCS_Classification_Code)360)

/*
 * Definition:
 *     A <SITE> utilizing long-range radar to detect approaching <AIRCRAFT>
 *     and/or <MISSILE>s; an early warning radar site.
 *
 * Group Membership: EM_PHENOMENON, MILITARY_SCIENCE, USAGE_REGION
 */
#define ECC_EARLY_WARNING_RADAR_SITE ((EDCS_Classification_Code)361)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is third in distance from the
 *     <SUN>, with an orbital mean <<RADIUS>> of approximately 149,6 million
 *     kilometres; Earth.
 *
 * Group Membership: SPACE
 */
#define ECC_EARTH ((EDCS_Classification_Code)362)

/*
 * Definition:
 *     A circular movement of fluid running contrary to the main flow,
 *     usually formed where <CURRENT>s pass obstructions, between two
 *     adjacent <CURRENT>s flowing counter to each other, or along the edge
 *     of a <CURRENT> that is <<PERMANENT>>; an eddy.
 *
 * Group Membership: FLUID_CONDITION
 */
#define ECC_EDDY ((EDCS_Classification_Code)363)

/*
 * Definition:
 *     A <REGION> where <EDDY>s occur.
 *
 * Group Membership: FLUID_CONDITION
 */
#define ECC_EDDY_REGION ((EDCS_Classification_Code)364)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of insulated <WIRE>s formed into one continuous
 *     strand for the purpose of transmitting electrical power or signals;
 *     an electrical cable.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_ELECTRICAL_CABLE ((EDCS_Classification_Code)365)

/*
 * Definition:
 *     A <REGION> where a field of force produced by a electrically charged
 *     <OBJECT> or by a changing <MAGNETIC_FIELD> is found; an electrical
 *     field [SOED, "electric field"].
 *
 * Group Membership: EM_PHENOMENON
 */
#define ECC_ELECTRICAL_FIELD ((EDCS_Classification_Code)366)

/*
 * Definition:
 *     A <SYSTEM> of <WIRE>s and their supports above the <TERRAIN> that
 *     transmit electrical signals over distance; an electrical signal line.
 *     EXAMPLES Telegraph line, telephone line.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_ELECTRICAL_SIGNAL_LINE ((EDCS_Classification_Code)367)

/*
 * Definition:
 *     A <PYLON> and/or <POLE> used to support an <ELECTRICAL_SIGNAL_LINE>.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE, SUPPORT_STRUCTURE
 */
#define ECC_ELECTRICAL_SIGNAL_LINE_PYLON ((EDCS_Classification_Code)368)

/*
 * Definition:
 *     A <PYLON> and/or <POLE> used to support a <POWER_TRANSMISSION_LINE>
 *     associated with an electrified <RAILWAY>.
 *
 * Group Membership: EM_PHENOMENON, LAND_TRNSP, SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_ELECTRIFIED_RAILWAY_PYLON ((EDCS_Classification_Code)369)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the electromagnetic properties of the
 *     <MATERIAL>s composing an <OBJECT>.
 *
 * Group Membership: EM_PHENOMENON, PROPERTY_SET
 */
#define ECC_ELECTROMAGNETIC_MATERIAL_PROPERTY_SET ((EDCS_Classification_Code)370)

/*
 * Definition:
 *     A broadband, high-intensity, short duration burst of electromagnetic
 *     radiation; an electromagnetic pulse. The resulting
 *     <ELECTRICAL_FIELD>s and <MAGNETIC_FIELD>s may couple with electrical
 *     and/or electronic <SYSTEM>s to produce damaging current and voltage
 *     surges.
 *
 * Group Membership: EM_PHENOMENON
 */
#define ECC_ELECTROMAGNETIC_PULSE ((EDCS_Classification_Code)371)

/*
 * Definition:
 *     A layer of the <ATMOSPHERE> that is over a <WATERBODY> and in which
 *     electromagnetic waves launched in certain <DIRECTION>s are guided by
 *     and/or trapped within the layer rather than propagating radially from
 *     their source, caused by a decrease in <<WATER_VAPOUR_PRESSURE>> with
 *     <<HEIGHT_AGL>> due to evaporation; a refractive evaporative duct.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_ELECTROMAGNETIC_REFRACTIVE_EVAPORATIVE_DUCT ((EDCS_Classification_Code)372)

/*
 * Definition:
 *     An <ELECTRICAL_CABLE> located above a <PLANETARY_SURFACE>.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_ELEVATED_ELECTRICAL_CABLE ((EDCS_Classification_Code)373)

/*
 * Definition:
 *     An <ISOPLETH> of constant <<ELEVATION>>; an elevation contour line.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_ELEVATION_CONTOUR_LINE ((EDCS_Classification_Code)374)

/*
 * Definition:
 *     The <ELECTROMAGNETIC_PULSE> caused by the Compton effect following a
 *     nuclear explosion.
 *
 * Group Membership: EM_PHENOMENON
 */
#define ECC_EM_PULSE_COMPTON_EFFECT ((EDCS_Classification_Code)375)

/*
 * Definition:
 *     A long, raised mound of <SOIL>, <ROCK>, and/or other <MATERIAL>s in
 *     the <TERRAIN>, which is often used to support a
 *     <LAND_TRANSPORTATION_ROUTE>; an embankment [SOED, "embankment", 1].
 *
 * Group Membership: LAND_TRNSP, PHYSIOGRAPHY, SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_EMBANKMENT ((EDCS_Classification_Code)376)

/*
 * Definition:
 *     A <BUILDING> housing the office of an ambassador and/or the
 *     ambassador's staff; an embassy [AHD, "embassy", 1].
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_EMBASSY ((EDCS_Classification_Code)377)

/*
 * Definition:
 *     An enclosed <SITE> containing an <EMBASSY>; an embassy compound.
 *
 * Group Membership: ADMINISTRATION, SHELTER, USAGE_REGION
 */
#define ECC_EMBASSY_COMPOUND ((EDCS_Classification_Code)378)

/*
 * Definition:
 *     A <STRUCTURE> where engines are tested; an engine test cell.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_ENGINE_TEST_CELL ((EDCS_Classification_Code)379)

/*
 * Definition:
 *     A temporary <BRIDGE> spanning and providing passage over a
 *     <TERRAIN_OBSTACLE> (for example: a <WATERBODY> and/or a <GULLY>); an
 *     engineer bridge.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_ENGINEER_BRIDGE ((EDCS_Classification_Code)380)

/*
 * Definition:
 *     A <TRENCH> that is constructed to bury <PIPELINE>s,
 *     <ELECTRICAL_SIGNAL_LINE>s, or <POWER_TRANSMISSION_LINE>s; an engineer
 *     ditch.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, PHYSIOGRAPHY
 */
#define ECC_ENGINEER_DITCH ((EDCS_Classification_Code)381)

/*
 * Definition:
 *     An engineered <TRENCH> or combination <TRENCH> and <PARAPET>, usually
 *     placed to turn, slow, or stop the movement of <MOTOR_VEHICLE>s; an
 *     engineer trench.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, PHYSIOGRAPHY, TRNSP
 */
#define ECC_ENGINEER_TRENCH ((EDCS_Classification_Code)382)

/*
 * Definition:
 *     <OBJECT>s used and/or required for a particular purpose; equipment
 *     [SOED, "equipment", 2] or apparatus.
 *
 * Group Membership: ABSTRACT_OBJECT, DEVICE_AND_EQUIPMENT
 */
#define ECC_EQUIPMENT ((EDCS_Classification_Code)383)

/*
 * Definition:
 *     A <COMPONENT> of an item of <EQUIPMENT>.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_EQUIPMENT_COMPONENT ((EDCS_Classification_Code)384)

/*
 * Definition:
 *     <EQUIPMENT> consisting of a moving <STAIR> made on the endless-chain
 *     principle, so that the steps ascend or descend continuously, for
 *     carrying <HUMAN>s up or down; an escalator [SOED, "escalator"].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define ECC_ESCALATOR ((EDCS_Classification_Code)385)

/*
 * Definition:
 *     A steep, vertical, or overhanging face of <ROCK> and/or <SOIL> in the
 *     <LAND>; an escarpment.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_ESCARPMENT ((EDCS_Classification_Code)386)

/*
 * Definition:
 *     A long, narrow <RIDGE> of <SAND> and gravel deposited by a glacial
 *     <RIVER>; an esker.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_ESKER ((EDCS_Classification_Code)387)

/*
 * Definition:
 *     An arm of a <WATERBODY> that extends inland to meet the mouth of a
 *     <RIVER> and includes a mixture of fresh and salt <WATER>; an estuary
 *     [AHD, "estuary", 2].
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_ESTUARY ((EDCS_Classification_Code)388)

/*
 * Definition:
 *     <EQUIPMENT> for removing <MATERIAL>s (for example: <SOIL>) from the
 *     <TERRAIN>; an excavating machine.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY
 */
#define ECC_EXCAVATING_MACHINE ((EDCS_Classification_Code)389)

/*
 * Definition:
 *     An excavated space in the <TERRAIN>; an excavation [SOED,
 *     "excavation", 2], a cavity, or a hollow.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_EXCAVATION ((EDCS_Classification_Code)390)

/*
 * Definition:
 *     A <SITE> where permanent <STRUCTURE>s exist to hold outdoor
 *     exhibitions; an exhibition ground.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_EXHIBITION_GROUND ((EDCS_Classification_Code)391)

/*
 * Definition:
 *     An explosive <DEVICE> that may be detonated to either damage or
 *     destroy <STRUCTURE>s or to move <ROCK>, <SOIL>, and/or other
 *     <MATERIAL>s; an explosive charge.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_EXPLOSIVE_CHARGE ((EDCS_Classification_Code)392)

/*
 * Definition:
 *     An <EXPLOSIVE_MINE> used in land warfare.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, MILITARY_SCIENCE
 */
#define ECC_EXPLOSIVE_LAND_MINE ((EDCS_Classification_Code)393)

/*
 * Definition:
 *     An explosive <DEVICE> located on or below a <PLANETARY_SURFACE>,
 *     usually emplaced for military purposes; an explosive mine [SOED,
 *     "land-mine", a].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, MILITARY_SCIENCE
 */
#define ECC_EXPLOSIVE_MINE ((EDCS_Classification_Code)394)

/*
 * Definition:
 *     An <EXPLOSIVE_MINE> used in naval warfare.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, MILITARY_SCIENCE
 */
#define ECC_EXPLOSIVE_NAVAL_MINE ((EDCS_Classification_Code)395)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> consisting principally of <BEDROCK> that is
 *     covered by less than 10 percent loose <MATERIAL> (for example:
 *     <SOIL>, <SAND>, clay, and/or gravel); exposed bedrock.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_EXPOSED_BEDROCK ((EDCS_Classification_Code)396)

/*
 * Definition:
 *     A <HALLWAY> along the exterior of a <BUILDING>, often appearing as a
 *     long <BALCONY>.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_EXTERIOR_HALLWAY ((EDCS_Classification_Code)397)

/*
 * Definition:
 *     A <WALL> forming an exterior section of a <STRUCTURE>.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_EXTERIOR_WALL ((EDCS_Classification_Code)398)

/*
 * Definition:
 *     A <FACILITY> for extracting and/or exploiting natural resources; an
 *     extraction facility.
 *
 * Group Membership: INDUSTRY, USAGE_REGION
 */
#define ECC_EXTRACTION_FACILITY ((EDCS_Classification_Code)399)

/*
 * Definition:
 *     An <EXCAVATION> made in the <TERRAIN> for the purpose of extracting
 *     and/or exploiting natural resources; an extraction mine.
 *
 * Group Membership: INDUSTRY, PHYSIOGRAPHY, USAGE_REGION
 */
#define ECC_EXTRACTION_MINE ((EDCS_Classification_Code)400)

/*
 * Definition:
 *     A <BUILDING> used for the purpose of manufacturing <COMPONENT>s, which
 *     may be assembled on-site or elsewhere, to make a completed product; a
 *     fabrication building.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_FABRICATION_BUILDING ((EDCS_Classification_Code)401)

/*
 * Definition:
 *     A <FACILITY> including one or more <FABRICATION_BUILDING>s.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_FABRICATION_FACILITY ((EDCS_Classification_Code)402)

/*
 * Definition:
 *     A <REGION> that includes <MAN_MADE_OBJECT>s intended to serve a
 *     particular purpose; a facility.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_FACILITY ((EDCS_Classification_Code)403)

/*
 * Definition:
 *     A <BUILDING> containing <EQUIPMENT> for use in manufacturing; a
 *     factory [SOED, "factory", 3].
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_FACTORY ((EDCS_Classification_Code)404)

/*
 * Definition:
 *     A <SITE> where permanent <STRUCTURE>s exist to hold outdoor fairs,
 *     circuses, and/or exhibitions; a fairground.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_FAIRGROUND ((EDCS_Classification_Code)405)

/*
 * Definition:
 *     A <SITE>, including support <STRUCTURE>s, used for agricultural or
 *     aquacultural production; a farm.
 *
 * Group Membership: AGRICULTURE, USAGE_REGION
 */
#define ECC_FARM ((EDCS_Classification_Code)406)

/*
 * Definition:
 *     A <BUILDING> located on a <FARM>.
 *
 * Group Membership: AGRICULTURE, SHELTER
 */
#define ECC_FARM_BUILDING ((EDCS_Classification_Code)407)

/*
 * Definition:
 *     A <STRUCTURE>, often having a <ROOF>, located on a <FARM> and used for
 *     sheltering livestock and/or storing agricultural products or
 *     <EQUIPMENT>; a farm storage structure.
 *
 * Group Membership: AGRICULTURE, ANIMAL, LIVING_ORGANISM, SHELTER
 */
#define ECC_FARM_STORAGE_STRUCTURE ((EDCS_Classification_Code)408)

/*
 * Definition:
 *     A man-made <BARRIER> of relatively light construction used as an
 *     enclosure or <BOUNDARY>; a fence.
 *
 * Group Membership: DEMARCATION
 */
#define ECC_FENCE ((EDCS_Classification_Code)409)

/*
 * Definition:
 *     A protective <DEVICE> designed to cushion the impact of a <VESSEL>
 *     against a <STRUCTURE> or other <VESSEL> and to prevent damage; a
 *     fender cushion.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_FENDER_CUSHION ((EDCS_Classification_Code)410)

/*
 * Definition:
 *     A <PTERIDOPHYTE> of the order Filicopsida, the members of which
 *     reproduce by means of spores borne usually on the underside of the
 *     fronds, which are typically pinnately divided; a fern [SOED, "fern"].
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_FERN ((EDCS_Classification_Code)411)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> for transporting <HUMAN>s, <GROUND_VEHICLE>s,
 *     or <CARGO> across a <WATERBODY>; a ferry [SOED, "ferry", 3.a].
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_FERRY ((EDCS_Classification_Code)412)

/*
 * Definition:
 *     A <MARINE_ROUTE> where a <FERRY> crosses from one <SHORE> to another;
 *     a ferry crossing.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_FERRY_CROSSING ((EDCS_Classification_Code)413)

/*
 * Definition:
 *     A <LOCATION> where a <FERRY> takes on or discharges its load.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_FERRY_LOCATION ((EDCS_Classification_Code)414)

/*
 * Definition:
 *     A <LOCATION> used as a basis of cadastral reference; a fiducial point.
 *
 * Group Membership: ADMINISTRATION, LOCATION, SURVEY
 */
#define ECC_FIDUCIAL_POINT ((EDCS_Classification_Code)415)

/*
 * Definition:
 *     A large-calibre firing <WEAPON>; a field artillery piece. EXAMPLES
 *     Howitzer, cannon.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_FIELD_ARTILLERY ((EDCS_Classification_Code)416)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed for fast maneuver aerial combat
 *     operations; a fighter aircraft [SOED, "fighter", 2].
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_FIGHTER_WINGED_AIRCRAFT ((EDCS_Classification_Code)417)

/*
 * Definition:
 *     A configuration of <LAND> and/or <STRUCTURE>s that is intended to
 *     accommodate <MILITARY_PERSONNEL>, military <EQUIPMENT>, and/or
 *     military <GROUND_VEHICLE>s; that provides cover and concealment from
 *     direct and potentially indirect fire; and that affords effective use
 *     of <WEAPON>s; a fighting position.
 *
 * Group Membership: MILITARY_SCIENCE, PHYSIOGRAPHY
 */
#define ECC_FIGHTING_POSITION ((EDCS_Classification_Code)418)

/*
 * Definition:
 *     <BUILT_UP_TERRAIN> that has been brought to a required higher
 *     <<TERRAIN_ELEVATION>> or levelled through the addition of <SOIL>,
 *     <ROCK>, and/or other <MATERIAL>s; filled terrain.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_FILLED_TERRAIN ((EDCS_Classification_Code)419)

/*
 * Definition:
 *     A <TRACT> for the treatment of <WATER> that consists of a bed of
 *     porous <MATERIAL> that <WATER> is passed through in order to remove
 *     solids or impurities; a filtration bed.
 *
 * Group Membership: INFRASTRUCTURE, SURFACE_MATERIAL, USAGE_REGION
 */
#define ECC_FILTRATION_BED ((EDCS_Classification_Code)420)

/*
 * Definition:
 *     A <BUILDING> that houses <EQUIPMENT> through which a liquid or gas is
 *     passed in order to separate the fluid from suspended particulate
 *     matter; a filtration building.
 *
 * Group Membership: INFRASTRUCTURE, SHELTER
 */
#define ECC_FILTRATION_BUILDING ((EDCS_Classification_Code)421)

/*
 * Definition:
 *     A long, narrow, deep <INLET> of a <WATERBODY> between <TERRAIN> with
 *     steep <<TERRAIN_SLOPE>>s; a fiord [SOED, "fiord"].
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_FIORD ((EDCS_Classification_Code)422)

/*
 * Definition:
 *     A <PUBLIC_SERVICE_STATION> that houses both a <FIRE_STATION> and a
 *     <POLICE_STATION>.
 *
 * Group Membership: ADMINISTRATION, INFRASTRUCTURE
 */
#define ECC_FIRE_AND_POLICE_STATION ((EDCS_Classification_Code)423)

/*
 * Definition:
 *     An exterior <STRUCTURE> or <DEVICE> erected for emergency exit in the
 *     event of fire; a fire-escape [AHD, "fire escape"]. EXAMPLE An outside
 *     <STAIR> that is attached to a <BUILDING>.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_FIRE_ESCAPE ((EDCS_Classification_Code)424)

/*
 * Definition:
 *     A <PUBLIC_SERVICE_STATION> that houses both fire-fighting <EQUIPMENT>
 *     and <PERSONNEL>; a fire station [MWCD, "fire station"] or firehouse.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_FIRE_STATION ((EDCS_Classification_Code)425)

/*
 * Definition:
 *     A cleared or ploughed <TERRAIN_STRIP> that is constructed as a
 *     <BARRIER> against the spread of a forest or prairie fire; a firebreak
 *     [SOED, "fire-break"].
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_FIREBREAK ((EDCS_Classification_Code)426)

/*
 * Definition:
 *     A cold-blooded aquatic <VERTEBRATE> possessing gills and fins; a fish
 *     [SOED, "fish", I.1.a].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_FISH ((EDCS_Classification_Code)427)

/*
 * Definition:
 *     An enclosed <REGION> and associated <STRUCTURE>s used for the breeding
 *     and/or rearing of <FISH>; a fish hatchery.
 *
 * Group Membership: AGRICULTURE, ANIMAL, LIVING_ORGANISM, USAGE_REGION
 */
#define ECC_FISH_HATCHERY ((EDCS_Classification_Code)428)

/*
 * Definition:
 *     A series of ascending pools constructed to enable <FISH> to swim
 *     upstream over (or around) a <DAM>; a fish ladder.
 *
 * Group Membership: ANIMAL, HYDROGRAPHIC_ARTEFACT, LIVING_ORGANISM
 */
#define ECC_FISH_LADDER ((EDCS_Classification_Code)429)

/*
 * Definition:
 *     A naturally occurring grouping of <FISH> that persists over a
 *     significant period; a fish school.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_FISH_SCHOOL ((EDCS_Classification_Code)430)

/*
 * Definition:
 *     A <REGION> where <POLE>s or <STAKE>s are placed in shallow <WATER> to
 *     outline a fishing ground or to catch <FISH>.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, USAGE_REGION
 */
#define ECC_FISH_STAKE_REGION ((EDCS_Classification_Code)431)

/*
 * Definition:
 *     A <FENCE> or enclosure <DEVICE> set in a <WATERBODY> to catch <FISH>;
 *     a fish trap.
 *
 * Group Membership: ANIMAL, DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, LIVING_ORGANISM
 */
#define ECC_FISH_TRAP ((EDCS_Classification_Code)432)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> designed or designated to catch <FISH> for
 *     either commercial or leisure purposes; a fishing boat.
 *
 * Group Membership: ANIMAL, HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, LIVING_ORGANISM, RECREATION, TRNSP, VEHICLE
 */
#define ECC_FISHING_BOAT ((EDCS_Classification_Code)433)

/*
 * Definition:
 *     A <FACILITY> involved in fishing, the raising of <FISH>, and/or the
 *     storage or transportation of either <MATERIAL>s important to or the
 *     results of the production of <FISH>.
 *
 * Group Membership: AGRICULTURE, ANIMAL, HYDROGRAPHIC_INDUSTRY, INDUSTRY, LIVING_ORGANISM, USAGE_REGION
 */
#define ECC_FISHING_FACILITY ((EDCS_Classification_Code)434)

/*
 * Definition:
 *     A <HARBOUR> that is primarily used by <FISHING_BOAT>s.
 *
 * Group Membership: ANIMAL, HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, LIVING_ORGANISM, SHELTER, TRNSP, USAGE_REGION
 */
#define ECC_FISHING_HARBOUR ((EDCS_Classification_Code)435)

/*
 * Definition:
 *     A <POLE> on which a flag is raised; a flagstaff or flagpole.
 *
 * Group Membership: ADMINISTRATION
 */
#define ECC_FLAGPOLE ((EDCS_Classification_Code)436)

/*
 * Definition:
 *     An open-ended <PIPE> at which waste gases are burned; a flare pipe or
 *     flare stack.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_FLARE_PIPE ((EDCS_Classification_Code)437)

/*
 * Definition:
 *     A physical connection between two independent <OBJECT>s (for example:
 *     between a <VESSEL> and a mooring <BUOY> or <BOLLARD>). EXAMPLES
 *     <CHAIN>, <LOAD_CABLE>.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_FLEXIBLE_RESTRAINT ((EDCS_Classification_Code)438)

/*
 * Definition:
 *     A <SURFACE> of constant <<ATM_PRESSURE>> that is measured in relation
 *     to the specific pressure <DATUM> 1 013,25 hectopascals and is
 *     separated from other such <SURFACE>s by specific pressure intervals.
 *
 * Group Membership: AIR_TRNSP, ATMOSPHERE
 */
#define ECC_FLIGHT_LEVEL ((EDCS_Classification_Code)439)

/*
 * Definition:
 *     A <STRUCTURE> consisting of a series of square frames of timber
 *     connected by <MOORING_LINE>s attached to <ANCHOR>s or stone blocks in
 *     such a manner as to form a <BREAKWATER> that protects <VESSEL>s
 *     riding to anchor; a floating breakwater.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, SHELTER, TRNSP
 */
#define ECC_FLOATING_BREAKWATER ((EDCS_Classification_Code)440)

/*
 * Definition:
 *     A form of <DRY_DOCK> consisting of a floating <STRUCTURE> of one or
 *     more sections that can be partly submerged by controlled flooding to
 *     receive a <VESSEL> and then raised by pumping out the <WATER> so that
 *     the bottom of the <VESSEL> can be exposed; a floating dock.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, SHELTER, TRNSP
 */
#define ECC_FLOATING_DOCK ((EDCS_Classification_Code)441)

/*
 * Definition:
 *     An artificial obstruction placed in a <WATERCOURSE> to raise the level
 *     of the <WATER> or to divert it; a flood barrage.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT
 */
#define ECC_FLOOD_BARRAGE ((EDCS_Classification_Code)442)

/*
 * Definition:
 *     A <TRACT> that submerges during the highest known flood in a
 *     <TERRAIN_SURFACE_REGION> or has the potential for being flooded (for
 *     example: by the failure of a <DAM>); a flood basin.
 *
 * Group Membership: HYDROLOGY, PHYSIOGRAPHY
 */
#define ECC_FLOOD_BASIN ((EDCS_Classification_Code)443)

/*
 * Definition:
 *     A layer of <MATERIAL> (for example: board, brick, and/or stone) in a
 *     <ROOM> or <VEHICLE> on which <HUMAN>s and/or <ANIMAL>s tread; a floor
 *     [SOED, "floor", 1.a].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_FLOOR ((EDCS_Classification_Code)444)

/*
 * Definition:
 *     A space within a <BUILDING>, located under a <FLOOR>, usually of
 *     restricted <<HEIGHT>>, and having sufficient <<HEIGHT>> for <HUMAN>s
 *     to crawl; a floor crawl space.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_FLOOR_CRAWL_SPACE ((EDCS_Classification_Code)445)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <ROOM>s and landings of <STAIR>s in a <BUILDING>
 *     that are on the same or nearly the same level; a floor level or
 *     storey.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_FLOOR_LEVEL ((EDCS_Classification_Code)446)

/*
 * Definition:
 *     The layer of fluid in the immediate vicinity of a <SURFACE> where
 *     frictional forces control fluid flow; a fluid boundary layer.
 *
 * Group Membership: FLUID_CONDITION
 */
#define ECC_FLUID_BOUNDARY_LAYER ((EDCS_Classification_Code)447)

/*
 * Definition:
 *     An open, inclined <WATERCOURSE> that carries <WATER> for use in such
 *     operations as mining or logging; a flume.
 *
 * Group Membership: HYDROLOGY, INDUSTRY
 */
#define ECC_FLUME ((EDCS_Classification_Code)448)

/*
 * Definition:
 *     A suspension of very small, usually microscopic, droplets of <WATER>
 *     in the <AIR> that reduces the horizontal <<VISIBILITY_DISTANCE>> at a
 *     <PLANETARY_SURFACE>; fog.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_FOG ((EDCS_Classification_Code)449)

/*
 * Definition:
 *     A <REGION> of <FOG> at or near a <PLANETARY_SURFACE>.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_FOG_REGION ((EDCS_Classification_Code)450)

/*
 * Definition:
 *     A <DEVICE> that produces a warning signal as an <AID_TO_NAVIGATION>
 *     during periods of low visibility, especially due to <FOG>.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, COMMUNICATION, DEVICE_AND_EQUIPMENT, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_FOG_SIGNAL_DEVICE ((EDCS_Classification_Code)451)

/*
 * Definition:
 *     <EQUIPMENT> consisting of a chamber or enclosed compartment for
 *     heating, baking, or roasting food; an oven or stove [AHD, "oven"].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_FOOD_OVEN ((EDCS_Classification_Code)452)

/*
 * Definition:
 *     A shallow <REGION> in a <WATERBODY> used as a <CROSSING> by
 *     <GROUND_VEHICLE>s or <ANIMAL>s; a ford.
 *
 * Group Membership: ANIMAL, HYDROLOGY, LAND_TRNSP,  LIVING_ORGANISM, TRNSP
 */
#define ECC_FORD ((EDCS_Classification_Code)453)

/*
 * Definition:
 *     A <COMPONENT> of the <SHORE> or <BEACH> that lies between the low
 *     water mark and the <COASTLINE> or <SHORELINE>; a foreshore. Foreshore
 *     includes any isolated <TERRAIN_SURFACE_REGION>s which cover and
 *     uncover with the <TIDE> yet are not contiguous with the <COASTLINE>
 *     or <SHORELINE>.
 *
 * Group Membership: LITTORAL, PHYSIOGRAPHY
 */
#define ECC_FORESHORE ((EDCS_Classification_Code)454)

/*
 * Definition:
 *     A <FORESHORE>, the low water mark of which is the <LINE> defined by
 *     mean low water springs or mean lower low water as appropriate and the
 *     <COASTLINE> or <SHORELINE> of which is defined by the normal limit of
 *     <WATER_WAVE> action above mean high water springs or mean higher high
 *     water as appropriate; foreshore precise.
 *
 * Group Membership: LITTORAL, PHYSIOGRAPHY
 */
#define ECC_FORESHORE_PRECISE ((EDCS_Classification_Code)455)

/*
 * Definition:
 *     A <TRACT> containing a substantial number of closely spaced <TREE>s; a
 *     forest.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_FOREST ((EDCS_Classification_Code)456)

/*
 * Definition:
 *     A <FOREST> that is protected from logging and other human activities
 *     detrimental to the environment; a forest preserve.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_FOREST_PRESERVE ((EDCS_Classification_Code)457)

/*
 * Definition:
 *     A permanently fortified <STRUCTURE> that may be stationed with
 *     <MILITARY_PERSONNEL> and is generally walled or heavily fenced with
 *     overwatch positions; a fort.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_FORT ((EDCS_Classification_Code)458)

/*
 * Definition:
 *     A <STRUCTURE> constructed for the military defence of a <SITE>; a
 *     fortification.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_FORTIFICATION ((EDCS_Classification_Code)459)

/*
 * Definition:
 *     A <STRUCTURE> built for one or more jets of <WATER> to spout and fall
 *     into; a fountain [SOED, "fountain", 2.a].
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_FOUNTAIN ((EDCS_Classification_Code)460)

/*
 * Definition:
 *     <DRIZZLE> that falls in liquid form but freezes upon impact to form a
 *     coating of <ICE_GLAZE> on the <LAND> and on exposed <OBJECT>s;
 *     freezing drizzle.
 *
 * Group Membership: ATMOSPHERE, ICE
 */
#define ECC_FREEZING_DRIZZLE ((EDCS_Classification_Code)461)

/*
 * Definition:
 *     <RAIN> that falls in liquid form but freezes upon impact to form a
 *     coating of <ICE_GLAZE> upon the <LAND> and on exposed <OBJECT>s;
 *     freezing rain.
 *
 * Group Membership: ATMOSPHERE, ICE
 */
#define ECC_FREEZING_RAIN ((EDCS_Classification_Code)462)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> that is smaller than a <CRUISER> and is
 *     designed for escort operations; a frigate.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_FRIGATE ((EDCS_Classification_Code)463)

/*
 * Definition:
 *     A large <TRACT> that is permanently covered by <SNOW_GROUND_COVER>
 *     and/or <ICE>; a snowfield or an ice-field. EXAMPLES
 *     <PERMANENT_SNOWFIELD>, <ICE_FIELD>.
 *
 * Group Membership: ICE, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_FROZEN_PRECIPITATION_FIELD ((EDCS_Classification_Code)464)

/*
 * Definition:
 *     A <LIVING_ORGANISM> of the kingdom Fungi, the members of which lack
 *     chlorophyll and grow on and obtain nutriment from organic matter; a
 *     fungus [SOED, "fungus"]. EXAMPLES <MUSHROOM>, toadstool, mould, rust,
 *     yeast, fungus constituent of a <LICHEN>.
 *
 * Group Membership: LIVING_ORGANISM
 */
#define ECC_FUNGUS ((EDCS_Classification_Code)465)

/*
 * Definition:
 *     <EQUIPMENT> consisting of a combustion chamber in which items such as
 *     minerals, metals, and ores may be subjected to continuous intense
 *     heat; a furnace [SOED, "furnace", A].
 *
 * Group Membership: INDUSTRY, SUPPORT_STRUCTURE, TEMPERATURE
 */
#define ECC_FURNACE ((EDCS_Classification_Code)466)

/*
 * Definition:
 *     Movable, functional <OBJECT>s, whether useful or ornamental, usually
 *     found in a <BUILDING>; furniture [SOED, "furniture", 6].
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_FURNITURE ((EDCS_Classification_Code)467)

/*
 * Definition:
 *     Any of numerous vast systems of <STAR>s, gas, and interstellar dust
 *     that exists separately in the universe and together contain nearly
 *     all of its visible matter; a galaxy [SOED, "galaxy", 1b].
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_GALAXY ((EDCS_Classification_Code)468)

/*
 * Definition:
 *     A frame <STRUCTURE> raised on side supports to span over or around
 *     something; a gantry.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_GANTRY ((EDCS_Classification_Code)469)

/*
 * Definition:
 *     A <MOLLUSC> of the class Gastropoda, the members of which typically
 *     have a flattened ventral foot for locomotion and a univalve shell; a
 *     gastropod. EXAMPLES Snail, slug, whelk, limpet.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_GASTROPOD ((EDCS_Classification_Code)470)

/*
 * Definition:
 *     A <BARRIER> that controls passage on a <LAND_TRANSPORTATION_ROUTE>; a
 *     gate.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_GATE ((EDCS_Classification_Code)471)

/*
 * Definition:
 *     A datum (see I19111, 4.9) describing the relationship of a coordinate
 *     system (see I19111, 4.7) to the <EARTH>; a geodetic datum or a
 *     horizontal datum.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_GEODETIC_DATUM ((EDCS_Classification_Code)472)

/*
 * Definition:
 *     The <TERRAIN_SURFACE_REGION> that is drained by a <RIVER> and its
 *     tributaries or that drains into a particular <LAKE> or <SEA>; a
 *     geographic basin.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_GEOGRAPHIC_BASIN ((EDCS_Classification_Code)473)

/*
 * Definition:
 *     A <LOCATION> or <REGION> where geographic information or statistics
 *     may apply.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_GEOGRAPHIC_INFORMATION ((EDCS_Classification_Code)474)

/*
 * Definition:
 *     A fracture in the <TERRAIN> with displacement on one side of the
 *     fracture relative to the other; a geologic fault.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_GEOLOGIC_FAULT ((EDCS_Classification_Code)475)

/*
 * Definition:
 *     A path marked on the <TERRAIN> resulting from geophysical survey
 *     operations.
 *
 * Group Membership: SURVEY
 */
#define ECC_GEOPHYSICAL_SURVEY_PATH ((EDCS_Classification_Code)476)

/*
 * Definition:
 *     A survey <LOCATION> established for the collection of geophysical
 *     data; a geophysical survey point.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_GEOPHYSICAL_SURVEY_POINT ((EDCS_Classification_Code)477)

/*
 * Definition:
 *     A localized <TERRAIN_SURFACE_OBJECT> that is controlled by or derived
 *     from the heat of the interior of a <PLANET>. EXAMPLE Hot <SPRING>.
 *
 * Group Membership: TEMPERATURE
 */
#define ECC_GEOTHERMAL_OBJECT ((EDCS_Classification_Code)478)

/*
 * Definition:
 *     A large mass of land-based <SNOW_GROUND_COVER> and <ICE> moving slowly
 *     down a slope or <VALLEY_REGION> from above the snowline; a glacier.
 *
 * Group Membership: ICE
 */
#define ECC_GLACIER ((EDCS_Classification_Code)479)

/*
 * Definition:
 *     A <TRACT> with few or no <TREE>s that is surrounded by a
 *     <TREED_TRACT>; a clearing or glade.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_GLADE ((EDCS_Classification_Code)480)

/*
 * Definition:
 *     A <TRACT> laid out for playing the game of golf; a golf course.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_GOLF_COURSE ((EDCS_Classification_Code)481)

/*
 * Definition:
 *     A <TRACT> used for practicing golf shots; a golf driving range.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_GOLF_DRIVING_RANGE ((EDCS_Classification_Code)482)

/*
 * Definition:
 *     A deep, narrow <TERRAIN_CHANNEL> with steep rocky sides; a gorge [AHD,
 *     "gorge", 1].
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_GORGE ((EDCS_Classification_Code)483)

/*
 * Definition:
 *     A <BUILDING> devoted to the act or process of administration of public
 *     policy in a political unit; a government building.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_GOVERNMENT_BUILDING ((EDCS_Classification_Code)484)

/*
 * Definition:
 *     A <FACILITY> including one or more <GOVERNMENT_BUILDING>s; a
 *     government facility.
 *
 * Group Membership: ADMINISTRATION, SHELTER, USAGE_REGION
 */
#define ECC_GOVERNMENT_FACILITY ((EDCS_Classification_Code)485)

/*
 * Definition:
 *     A <STRUCTURE> over which brine trickles and is concentrated through
 *     increased evaporation; a gradation works.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY
 */
#define ECC_GRADATION_WORKS ((EDCS_Classification_Code)486)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of tall <STRUCTURE>s equipped for loading,
 *     unloading, processing, and/or storing grain; a grain elevator.
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT
 */
#define ECC_GRAIN_ELEVATOR ((EDCS_Classification_Code)487)

/*
 * Definition:
 *     An enclosed <CONTAINER> used for storing grain or fodder; a grain bin
 *     or grain silo.
 *
 * Group Membership: AGRICULTURE, DEVICE_AND_EQUIPMENT, LIVING_ORGANISM, PLANT
 */
#define ECC_GRAIN_STORAGE_STRUCTURE ((EDCS_Classification_Code)488)

/*
 * Definition:
 *     A <STRUCTURE> for special viewing of outdoor events that has tiers of
 *     seats or standing room for spectators; a grandstand.
 *
 * Group Membership: RECREATION
 */
#define ECC_GRANDSTAND ((EDCS_Classification_Code)489)

/*
 * Definition:
 *     Any <PLANT> of the large cosmopolitan family Gramineae (including
 *     cereals, reeds, and bamboos besides the characteristic <PLANT>s of
 *     pasture-land), members of which typically have erect jointed stems
 *     (culms) bearing narrow bladelike leaves and insignificant flowers, or
 *     any of various <PLANT>s resembling the members of Gramineae in
 *     appearance; grass [SOED, "grass", 4.b].
 *
 * Group Membership: PLANT
 */
#define ECC_GRASS ((EDCS_Classification_Code)490)

/*
 * Definition:
 *     A <TRACT> covered by <GRASS> that has little or no woody tissue; a
 *     grassland.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_GRASS_LAND ((EDCS_Classification_Code)491)

/*
 * Definition:
 *     A <MARKER>, often located at a <CEMETERY>, indicating an individual
 *     gravesite; a grave marker.
 *
 * Group Membership: LOCATION
 */
#define ECC_GRAVE_MARKER ((EDCS_Classification_Code)492)

/*
 * Definition:
 *     A maintained <TRACT> that is covered by <VEGETATION>, which may also
 *     contain pathways, intended to improve the appearance of a
 *     <BUILT_UP_REGION> but not to be a <PARK>; a green space.
 *
 * Group Membership: LIVING_ORGANISM, PLANT, RECREATION, USAGE_REGION
 */
#define ECC_GREEN_SPACE ((EDCS_Classification_Code)493)

/*
 * Definition:
 *     A <BUILDING>, which is often constructed primarily of transparent
 *     <MATERIAL> (for example: glass or plastic), in which
 *     <<AIR_TEMPERATURE>> and <<RELATIVE_HUMIDITY>> can be controlled for
 *     the cultivation and/or protection of <PLANT>s; a greenhouse [SOED,
 *     "greenhouse", a].
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, SHELTER
 */
#define ECC_GREENHOUSE ((EDCS_Classification_Code)494)

/*
 * Definition:
 *     A <STRUCTURE> that normally projects outward from a <SHORE> and
 *     protects a <BEACH> from erosion by disrupting the alongshore movement
 *     of <SAND> and other <SEDIMENT>s but not by preventing <WATER_WAVE>s
 *     from reaching the <SHORE>; a groin.
 *
 * Group Membership: SHELTER
 */
#define ECC_GROIN ((EDCS_Classification_Code)495)

/*
 * Definition:
 *     A surface <SOIL> characteristic of the <LAND>; a ground surface
 *     element.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_GROUND_SURFACE_ELEMENT ((EDCS_Classification_Code)496)

/*
 * Definition:
 *     A <VEHICLE> operating principally on <LAND>; a ground vehicle.
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_GROUND_VEHICLE ((EDCS_Classification_Code)497)

/*
 * Definition:
 *     A large enclosed <TRACT> surrounding or attached to a <BUILDING>, most
 *     commonly a <HOUSE>; grounds [SOED, "ground", 13].
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_GROUNDS ((EDCS_Classification_Code)498)

/*
 * Definition:
 *     An elevated enclosed <BUILDING> including one or more <GUARDROOM>s; a
 *     guard tower.
 *
 * Group Membership: SHELTER
 */
#define ECC_GUARD_TOWER ((EDCS_Classification_Code)499)

/*
 * Definition:
 *     A small enclosed <BUILDING> accommodating a guard or serving as a
 *     <DETENTION_FACILITY>; a guardhouse [SOED, "guardhouse"].
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_GUARDHOUSE ((EDCS_Classification_Code)500)

/*
 * Definition:
 *     A small enclosed <ROOM> accommodating a guard or serving as a
 *     <DETENTION_FACILITY>; a guardroom [SOED, "guardroom"].
 *
 * Group Membership: BUILDING_COMPONENT, USAGE_REGION
 */
#define ECC_GUARDROOM ((EDCS_Classification_Code)501)

/*
 * Definition:
 *     A <CRUISER> equipped with guided <MISSILE>s.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_GUIDED_MISSILE_CRUISER ((EDCS_Classification_Code)502)

/*
 * Definition:
 *     A <DESTROYER> equipped with guided <MISSILE>s.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_GUIDED_MISSILE_DESTROYER ((EDCS_Classification_Code)503)

/*
 * Definition:
 *     A <FRIGATE> equipped with guided <MISSILE>s.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_GUIDED_MISSILE_FRIGATE ((EDCS_Classification_Code)504)

/*
 * Definition:
 *     A long, narrow, deep <TERRAIN_CHANNEL> that is caused by erosion and
 *     has steep banks; a gully.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_GULLY ((EDCS_Classification_Code)505)

/*
 * Definition:
 *     <SOLID_PRECIPITATION> of either transparent or partly or completely
 *     opaque <PARTICLE>s of <ICE> (hailstones), usually spherical, conical,
 *     or irregular in form and of <<OUTSIDE_DIAMETER>> generally between 5
 *     and 50 millimetres, that falls from a <CLOUD> either separately or
 *     agglomerated into irregular lumps; hail.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, ICE
 */
#define ECC_HAIL ((EDCS_Classification_Code)506)

/*
 * Definition:
 *     An entrance-hall or passage serving as a <ROUTE> to various <ROOM>s in
 *     a <BUILDING>; a hallway [SOED, "hallway"] or corridor.
 *
 * Group Membership: BUILDING_COMPONENT, LAND_TRNSP, TRNSP
 */
#define ECC_HALLWAY ((EDCS_Classification_Code)507)

/*
 * Definition:
 *     A <WATERBODY_REGION> providing <ANCHORAGE> and protection for
 *     <VESSEL>s; a harbour.
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, HYDROLOGY, SHELTER, TRNSP, USAGE_REGION
 */
#define ECC_HARBOUR ((EDCS_Classification_Code)508)

/*
 * Definition:
 *     A <HARBOUR> including one or more <ANCHORAGE_COMPLEX>s; a harbour
 *     complex.
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, HYDROLOGY, SHELTER, TRNSP, USAGE_REGION
 */
#define ECC_HARBOUR_COMPLEX ((EDCS_Classification_Code)509)

/*
 * Definition:
 *     An open <TRACT> with a prepared <SURFACE> of pavement or gravel used
 *     for parking and/or storing <VEHICLE>s, particularly <AIRCRAFT>; a
 *     hard standing [SOED, "hard standing"].
 *
 * Group Membership: AIR_TRNSP, SURFACE_MATERIAL, TRNSP, USAGE_REGION
 */
#define ECC_HARD_STANDING ((EDCS_Classification_Code)510)

/*
 * Definition:
 *     A reinforced <SHELTER> that is resistant to <MUNITION>s and is
 *     designed for the protection of <AIRCRAFT>; a hardened aircraft
 *     shelter.
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, SHELTER, TRNSP
 */
#define ECC_HARDENED_AIRCRAFT_SHELTER ((EDCS_Classification_Code)511)

/*
 * Definition:
 *     A regular pile of hay built in the open air; a haystack.
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT
 */
#define ECC_HAYSTACK ((EDCS_Classification_Code)512)

/*
 * Definition:
 *     A <MARKER> placed near or on a <TERRAIN_SURFACE_REGION> or
 *     <TERRAIN_SURFACE_OBJECT> to identify it as a potential hazard.
 *
 * Group Membership: LOCATION
 */
#define ECC_HAZARD_MARKER ((EDCS_Classification_Code)513)

/*
 * Definition:
 *     A <BUILDING> used in the diagnosis and care of outpatients; a health
 *     office or clinic.
 *
 * Group Membership: INFRASTRUCTURE, SHELTER
 */
#define ECC_HEALTH_OFFICE ((EDCS_Classification_Code)514)

/*
 * Definition:
 *     <EQUIPMENT> consisting of a <STORAGE_TANK> and/or compact array of
 *     <PIPE>s that: has a large surface <<AREA>>; is heated, usually by
 *     circulating steam or hot <WATER>; and gives off warmth by radiation
 *     and convection; a heat radiator [SOED, "radiator", 2].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TEMPERATURE
 */
#define ECC_HEAT_RADIATOR ((EDCS_Classification_Code)515)

/*
 * Definition:
 *     A <FACILITY> for the generation of thermal energy for heating purposes.
 *
 * Group Membership: INFRASTRUCTURE, TEMPERATURE, USAGE_REGION
 */
#define ECC_HEATING_FACILITY ((EDCS_Classification_Code)516)

/*
 * Definition:
 *     A <FACILITY> devoted to the processing of <MATERIAL> and/or the
 *     manufacture of goods (for example: steel, aluminum, glass, or
 *     <MOTOR_VEHICLE>s) that generally require significant <EQUIPMENT>,
 *     <MATERIAL>, and energy inputs; a heavy industrial facility.
 *
 * Group Membership: INDUSTRY, USAGE_REGION
 */
#define ECC_HEAVY_INDUSTRIAL_FACILITY ((EDCS_Classification_Code)517)

/*
 * Definition:
 *     A continuous growth of <SHRUB>s planted as a <FENCE>, a <BOUNDARY>,
 *     and/or a windbreak; a hedgerow.
 *
 * Group Membership: DEMARCATION, LIVING_ORGANISM, PLANT, SHELTER
 */
#define ECC_HEDGEROW ((EDCS_Classification_Code)518)

/*
 * Definition:
 *     An <AIRCRAFT> deriving both lift and propulsive power from
 *     horizontally revolving rotor blades and capable of ascending and
 *     descending vertically; a helicopter [SOED, "helicopter"].
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_HELICOPTER ((EDCS_Classification_Code)519)

/*
 * Definition:
 *     An improved <SITE> used for take-off and landing VTOL <AIRCRAFT> (for
 *     example: a <HELICOPTER>); a helicopter landing pad.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_HELICOPTER_LANDING_PAD ((EDCS_Classification_Code)520)

/*
 * Definition:
 *     An <AERODROME> or a defined <REGION> on a <STRUCTURE> intended to be
 *     used wholly or in part for the arrival, departure, and/or surface
 *     movement of <HELICOPTER>s; a heliport.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_HELIPORT ((EDCS_Classification_Code)521)

/*
 * Definition:
 *     A <CLOUD> of the genus cirrus, cirrocumulus, or cirrostratus; a high
 *     cloud. Also the top of a <CLOUD> of the genus cumulonimbus or,
 *     occasionally, altostratus.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_HIGH_CLOUD ((EDCS_Classification_Code)522)

/*
 * Definition:
 *     The <LOCATION> of the centre of an <ATMOSPHERE_REGION> of high
 *     <<ATM_PRESSURE>>.
 *
 * Group Membership: ATMOSPHERE, LOCATION
 */
#define ECC_HIGH_PRESSURE_CENTRE ((EDCS_Classification_Code)523)

/*
 * Definition:
 *     A small, isolated, elevated portion of the <TERRAIN> that is smaller
 *     than a <MOUNTAIN>; a hill.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_HILL ((EDCS_Classification_Code)524)

/*
 * Definition:
 *     A <WORSHIP_PLACE> for Hindu worship; a Hindu temple.
 *
 * Group Membership: RELIGION
 */
#define ECC_HINDU_TEMPLE ((EDCS_Classification_Code)525)

/*
 * Definition:
 *     A <TRACT> containing a concentration of historical <STRUCTURE>s within
 *     an enclosing <BUILT_UP_REGION>.
 *
 * Group Membership: SHELTER
 */
#define ECC_HISTORICAL_BUILT_UP_REGION ((EDCS_Classification_Code)526)

/*
 * Definition:
 *     A deposit of <ICE> (hoar crystals) that generally assumes the form of
 *     scales, needles, feathers, or fans and that forms on <OBJECT>s the
 *     <SURFACE>s of which are sufficiently cooled, usually by nocturnal
 *     radiation, to bring about deposition of the water vapour contained in
 *     the ambient <AIR>; hoar frost.
 *
 * Group Membership: ICE, MATERIAL, SURFACE_MATERIAL
 */
#define ECC_HOAR_FROST ((EDCS_Classification_Code)527)

/*
 * Definition:
 *     A delimited <REGION> within which <AIRCRAFT> follow a holding pattern
 *     while awaiting further clearance instructions.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_HOLDING_PATTERN_REGION ((EDCS_Classification_Code)528)

/*
 * Definition:
 *     A <TRACT> covered by the systematic planting of hop vines; a hop field.
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_HOP_FIELD ((EDCS_Classification_Code)529)

/*
 * Definition:
 *     A top-loaded, funnel-shaped <STRUCTURE> for temporary holding of loose
 *     <MATERIAL> that will be dispensed from its bottom; a hopper.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_HOPPER ((EDCS_Classification_Code)530)

/*
 * Definition:
 *     A solid-hoofed perissodactyl ungulate <MAMMAL> of the family Equidae;
 *     a horse [SOED, "horse", 1].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_HORSE ((EDCS_Classification_Code)531)

/*
 * Definition:
 *     A <BUILDING> used to provide inpatient medical, surgical, or
 *     psychiatric care and treatment for the sick or the injured; a
 *     hospital.
 *
 * Group Membership: INFRASTRUCTURE, SHELTER
 */
#define ECC_HOSPITAL_BUILDING ((EDCS_Classification_Code)532)

/*
 * Definition:
 *     A <BUILDING> used to provide supervised, inexpensive lodging for
 *     travellers, especially young travellers; a hostel [AHD, "hostel", 1].
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_HOSTEL ((EDCS_Classification_Code)533)

/*
 * Definition:
 *     A <BUILDING> used to provide lodging, and usually meals and other
 *     services, for travellers and other paying guests; a hotel [AHD,
 *     "hotel"].
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_HOTEL ((EDCS_Classification_Code)534)

/*
 * Definition:
 *     A <BUILDING> serving as a <DWELLING> for one or more <HUMAN>s,
 *     especially for a family; a house [AHD, "house, 1.a"].
 *
 * Group Membership: SHELTER
 */
#define ECC_HOUSE ((EDCS_Classification_Code)535)

/*
 * Definition:
 *     A permanently moored <WATER_SURFACE_VESSEL>; a hulk.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_HULK ((EDCS_Classification_Code)536)

/*
 * Definition:
 *     A member of the <ANIMAL> species Homo sapiens; a human [SOED, "human",
 *     B.1].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_HUMAN ((EDCS_Classification_Code)537)

/*
 * Definition:
 *     A <TRACT> of higher <<TERRAIN_ELEVATION>> than the <WETLAND> that
 *     surrounds it; a hummock.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_HUMMOCK ((EDCS_Classification_Code)538)

/*
 * Definition:
 *     A warm core <TROPICAL_CYCLONE> with a maximum surface <<WIND_SPEED>>
 *     of 33 metres per second or greater in the North Atlantic, the
 *     Caribbean, the Gulf of Mexico, and in the eastern North Pacific; a
 *     hurricane.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_HURRICANE ((EDCS_Classification_Code)539)

/*
 * Definition:
 *     A small, simple, or crude <HOUSE> or <SHELTER>; a hut.
 *
 * Group Membership: SHELTER
 */
#define ECC_HUT ((EDCS_Classification_Code)540)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> supported on airfoil-like pontoons where the
 *     bulk of the hull remains above the <WATERBODY_SURFACE> while in
 *     motion; a hydrofoil.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_HYDROFOIL_VESSEL ((EDCS_Classification_Code)541)

/*
 * Definition:
 *     A <LOCK_BASIN> with a pair or series of <LOCK_GATE>s used for raising
 *     or lowering <VESSEL>s as they pass from one level to another; a
 *     hydrographic lock.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_HYDROGRAPHIC_LOCK ((EDCS_Classification_Code)542)

/*
 * Definition:
 *     An <UNDERWATER_OBJECT> detected during a hydrographic survey; a
 *     hydrographic survey contact.
 *
 * Group Membership: SURVEY
 */
#define ECC_HYDROGRAPHIC_SURVEY_CONTACT ((EDCS_Classification_Code)543)

/*
 * Definition:
 *     A <WATERBODY> and its adjoining <SHORE>s; hydrography.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_HYDROGRAPHY ((EDCS_Classification_Code)544)

/*
 * Definition:
 *     A planetary <OBJECT> related to <WATER>; a hydrologic object.
 *
 * Group Membership: HYDROLOGY, PHYSIOGRAPHY
 */
#define ECC_HYDROLOGIC_OBJECT ((EDCS_Classification_Code)545)

/*
 * Definition:
 *     Frozen <WATER>; ice [SOED, "ice", 1.a].
 *
 * Group Membership: ICE
 */
#define ECC_ICE ((EDCS_Classification_Code)546)

/*
 * Definition:
 *     A floating <BARRIER> constrained by <ANCHOR>s and used to deflect the
 *     path of floating <ICE> in order to prevent the obstruction of
 *     <HYDROGRAPHIC_LOCK>s or <WATER_INTAKE>s or to prevent damage to
 *     <BRIDGE_PIER>s or other <STRUCTURE>s; an ice boom.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, ICE, SHELTER, TRNSP
 */
#define ECC_ICE_BOOM ((EDCS_Classification_Code)547)

/*
 * Definition:
 *     A perpendicular or steep face of a <GLACIER> or <ICE_SHELF> of
 *     considerable <<HEIGHT>>; an ice cliff.
 *
 * Group Membership: ICE
 */
#define ECC_ICE_CLIFF ((EDCS_Classification_Code)548)

/*
 * Definition:
 *     A <FROZEN_PRECIPITATION_FIELD> that consists of <ICE>; an ice-field.
 *
 * Group Membership: ICE, PHYSIOGRAPHY
 */
#define ECC_ICE_FIELD ((EDCS_Classification_Code)549)

/*
 * Definition:
 *     A coating of <ICE>, generally clear and smooth, formed on exposed
 *     <OBJECT>s by the freezing of a film of supercooled <WATER> deposited
 *     by <RAIN>, <DRIZZLE>, or <FOG> or possibly condensed from supercooled
 *     water vapour; ice glaze. <ICE_GLAZE> is denser, harder, and more
 *     transparent than either <RIME> or <HOAR_FROST>.
 *
 * Group Membership: ICE, SURFACE_MATERIAL
 */
#define ECC_ICE_GLAZE ((EDCS_Classification_Code)550)

/*
 * Definition:
 *     An irregular, linear, downward extension of <ICE> formed where two
 *     moving masses of <ICE> collide on a <WATERBODY>; an ice keel.
 *
 * Group Membership: ICE
 */
#define ECC_ICE_KEEL ((EDCS_Classification_Code)551)

/*
 * Definition:
 *     A rocky peak that may be perpetually covered with <ICE> and that
 *     projects above a surrounding <ICE_FIELD>; a nunatak or ice peak.
 *
 * Group Membership: ICE, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_ICE_PEAK ((EDCS_Classification_Code)552)

/*
 * Definition:
 *     <SOLID_PRECIPITATION> of transparent or translucent <PARTICLE>s of
 *     <ICE> that are spherical or irregular, rarely conical, and that have
 *     an <<OUTSIDE_DIAMETER>> of 5 millimetres or less; ice pellets.
 *     <SMALL_HAIL> is a form of ice pellets.
 *
 * Group Membership: ATMOSPHERE, ICE, MATERIAL
 */
#define ECC_ICE_PELLETS ((EDCS_Classification_Code)553)

/*
 * Definition:
 *     A thick sheet of <ICE>, mostly afloat on a <WATERBODY_SURFACE>, with a
 *     level or undulating <SURFACE> that is bounded on the seaward side by
 *     an <ICE_CLIFF> and attached to <LAND>; an ice shelf.
 *
 * Group Membership: ICE, WATERBODY_SURFACE
 */
#define ECC_ICE_SHELF ((EDCS_Classification_Code)554)

/*
 * Definition:
 *     Spongy whitish lumps of <ICE> a few centimetres in
 *     <<OUTSIDE_DIAMETER>> that are floating on the <WATERBODY_SURFACE> of
 *     a shallow <SEA>; ice sludge.
 *
 * Group Membership: ICE, WATERBODY_SURFACE
 */
#define ECC_ICE_SLUDGE ((EDCS_Classification_Code)555)

/*
 * Definition:
 *     A very large mass of <ICE> floating loose in a <WATERBODY> after
 *     becoming detached from a <GLACIER> or <ICE_SHELF>; an iceberg [SOED,
 *     "iceberg", 2].
 *
 * Group Membership: ICE, WATERBODY_SURFACE
 */
#define ECC_ICEBERG ((EDCS_Classification_Code)556)

/*
 * Definition:
 *     A <REGION> in which IFR should be observed.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_IFR_REGION ((EDCS_Classification_Code)557)

/*
 * Definition:
 *     An air navigation <COMPONENT> that is essential to the establishment
 *     and execution of a precision approach based on an ILS.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_ILS_COMPONENT ((EDCS_Classification_Code)558)

/*
 * Definition:
 *     An <ATS_ROUTE_COMPONENT> designated for channelling the flow of air
 *     traffic via ILS terminal procedures.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_ILS_TERMINAL_COMPONENT ((EDCS_Classification_Code)559)

/*
 * Definition:
 *     A permanent <STRUCTURE> used for the disposal of waste products by
 *     burning; an incinerator.
 *
 * Group Membership: INFRASTRUCTURE, TEMPERATURE
 */
#define ECC_INCINERATOR ((EDCS_Classification_Code)560)

/*
 * Definition:
 *     A <CEMETERY> for native peoples, generally without
 *     <MEMORIAL_MONUMENT>s; an indigenous burial ground.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_INDIGENOUS_BURIAL_GROUND ((EDCS_Classification_Code)561)

/*
 * Definition:
 *     A <TRACT>and associated <STRUCTURE>s set apart specifically for the
 *     use of a native people; an indigenous peoples reserve.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_INDIGENOUS_PEOPLES_RESERVE ((EDCS_Classification_Code)562)

/*
 * Definition:
 *     A <FIGHTING_POSITION> designed to accommodate an individual soldier
 *     and that soldier's <EQUIPMENT>.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_INDIVIDUAL_FIGHTING_POSITION ((EDCS_Classification_Code)563)

/*
 * Definition:
 *     A <BUILDING> used for the manufacture of goods or the processing of
 *     <MATERIAL>s; an industrial building.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_INDUSTRIAL_BUILDING ((EDCS_Classification_Code)564)

/*
 * Definition:
 *     An industrial <STRUCTURE> used for hardening, burning, or heating
 *     <MATERIAL>s (for example: grain, meal, clay, or wood); an industrial
 *     oven.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_INDUSTRIAL_OVEN ((EDCS_Classification_Code)565)

/*
 * Definition:
 *     The <STRUCTURE>s, <GROUNDS>, and <EQUIPMENT> of a manufacturing
 *     <FACILITY>; an industrial works.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, USAGE_REGION
 */
#define ECC_INDUSTRIAL_WORKS ((EDCS_Classification_Code)566)

/*
 * Definition:
 *     A <MILITARY_TRENCH>, typically integrated into a complex <SYSTEM> of
 *     <TERRAIN_OBSTACLE>s, that is used to provide cover, concealment,
 *     protected <FIGHTING_POSITION>s, and communications capability for
 *     infantry.
 *
 * Group Membership: COMMUNICATION, MILITARY_SCIENCE
 */
#define ECC_INFANTRY_TRENCH ((EDCS_Classification_Code)567)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the infrared properties of the <MATERIAL>s
 *     composing an <OBJECT>.
 *
 * Group Membership: EM_PHENOMENON, MATERIAL, PROPERTY_SET
 */
#define ECC_INFRARED_MATERIAL_PROPERTY_SET ((EDCS_Classification_Code)568)

/*
 * Definition:
 *     The <SHORELINE> of an inland <WATERBODY>.
 *
 * Group Membership: DEMARCATION, PHYSIOGRAPHY
 */
#define ECC_INLAND_SHORELINE ((EDCS_Classification_Code)569)

/*
 * Definition:
 *     A <WATERBODY> that either does not experience or only minimally
 *     experiences tidal fluctuations; inland water.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_INLAND_WATER ((EDCS_Classification_Code)570)

/*
 * Definition:
 *     A bathymetric <REGION> underlying an <INLAND_WATER_SURFACE>; an inland
 *     water bottom.
 *
 * Group Membership: WATERBODY_FLOOR
 */
#define ECC_INLAND_WATER_BOTTOM ((EDCS_Classification_Code)571)

/*
 * Definition:
 *     A <LOCATION> associated with an <INLAND_WATER_SURFACE> with an
 *     <<ELEVATION>>.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_INLAND_WATER_ELEVATION ((EDCS_Classification_Code)572)

/*
 * Definition:
 *     The <WATERBODY_SURFACE> of an <INLAND_WATER>.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_INLAND_WATER_SURFACE ((EDCS_Classification_Code)573)

/*
 * Definition:
 *     A short, narrow <WATERCOURSE> connecting a <MARINE_BAY> or <LAGOON>
 *     with a <SEA>; an inlet.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_INLET ((EDCS_Classification_Code)574)

/*
 * Definition:
 *     A designated <LOCATION> where the automated INS instruments of
 *     <AIRCRAFT> are reset before taking-off; an INS alignment pad.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_INS_ALIGNMENT_PAD ((EDCS_Classification_Code)575)

/*
 * Definition:
 *     An <ARTHROPOD> of the superclass Hexapoda, characterized by having six
 *     feet; an insect [SOED, "hexopod"].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_INSECT ((EDCS_Classification_Code)576)

/*
 * Definition:
 *     A <FACILITY> housing an established organization or foundation,
 *     especially one dedicated to education, public service, or culture,
 *     that provides for the care of <HUMAN>s who are destitute, disabled,
 *     or mentally ill; an institutional facility.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_INSTITUTIONAL_FACILITY ((EDCS_Classification_Code)577)

/*
 * Definition:
 *     A <SITE> maintained for the public and declared to be of national or
 *     provincial historical significance or interest.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_INTEREST_SITE ((EDCS_Classification_Code)578)

/*
 * Definition:
 *     A <WALL> in a <BUILDING> separating two <ROOM>s from each other; an
 *     interior wall.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_INTERIOR_WALL ((EDCS_Classification_Code)579)

/*
 * Definition:
 *     An opening (for example: an uncovered <APERTURE> in an <INTERIOR_WALL>
 *     and/or the space above a <WALL> of partial <<HEIGHT>>) that supports
 *     the passage of <MATERIAL>s or visibility into an adjoining <ROOM>.
 *
 * Group Membership: BUILDING_COMPONENT, LIGHTING_AND_VISIBILITY
 */
#define ECC_INTERIOR_WALL_OPENING ((EDCS_Classification_Code)580)

/*
 * Definition:
 *     A <LINE> designated as the place on the <EARTH> where each calendar
 *     day begins; the International Date Line. This <LINE> generally
 *     coincides with the 180^(th) meridian but is modified to avoid <LAND>.
 *
 * Group Membership: DEMARCATION, TIME
 */
#define ECC_INTERNATIONAL_DATE_LINE ((EDCS_Classification_Code)581)

/*
 * Definition:
 *     The <MAGNETIC_FIELD> in a <SOLAR_SYSTEM> carried with its
 *     <STELLAR_WIND>.
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_INTERPLANETARY_MAGNETIC_FIELD ((EDCS_Classification_Code)582)

/*
 * Definition:
 *     <LAND> subject to controlled inundation (for example: flooded by the
 *     regulation of the level of a <RESERVOIR>) that is normally associated
 *     with permanently flooded ground in which <TREE>s are still standing;
 *     inundated land.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_INUNDATED_LAND ((EDCS_Classification_Code)583)

/*
 * Definition:
 *     An <ANIMAL> without a backbone or spinal column that does not belong
 *     to the subphylum Vertebrata; an invertebrate [SOED, "invertebrate"].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_INVERTEBRATE ((EDCS_Classification_Code)584)

/*
 * Definition:
 *     The <ATMOSPHERE_REGION> of the <EARTH> characterized by ions and free
 *     electrons existing in sufficient quantities to reflect
 *     electromagnetic waves and located roughly between the
 *     <<ALTITUDE_MSL>>s of 70 to 500 kilometres; the ionosphere.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_IONOSPHERE ((EDCS_Classification_Code)585)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the electron-density related
 *     characteristics of an <IONOSPHERE>.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, PROPERTY_SET
 */
#define ECC_IONOSPHERE_ELECTRON_DENSITY_PROPERTY_SET ((EDCS_Classification_Code)586)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the distortion of the propagation of
 *     electromagnetic radiation through an <IONOSPHERE> due to medium
 *     density irregularities; an ionosphere scintillation property set.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, PROPERTY_SET
 */
#define ECC_IONOSPHERE_SCINTILLATION_PROPERTY_SET ((EDCS_Classification_Code)587)

/*
 * Definition:
 *     The lowest daytime <REGION> of the <IONOSPHERE> characterized by weak
 *     concentrations of ions and located roughly between the
 *     <<ALTITUDE_MSL>>s of 50 and 90 kilometres; the D-region or D-layer.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_IONOSPHERIC_D_REGION ((EDCS_Classification_Code)588)

/*
 * Definition:
 *     A daytime <REGION> of the <IONOSPHERE> characterized by concentrations
 *     of O[sub(2)]^(+) and NO^(+) ions and located roughly between the
 *     <<ALTITUDE_MSL>> s of 85 and 140 kilometres; the E-region or E-layer.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_IONOSPHERIC_E_REGION ((EDCS_Classification_Code)589)

/*
 * Definition:
 *     A daytime <REGION> of the <IONOSPHERE>, above the
 *     <IONOSPHERIC_E_REGION>, characterized by weak concentrations of
 *     O[sub(2)]^(+) ions and located roughly between the <<ALTITUDE_MSL>>s
 *     of 120 and 200 kilometres; the F1-region or F1-layer.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_IONOSPHERIC_F1_REGION ((EDCS_Classification_Code)590)

/*
 * Definition:
 *     A daytime <REGION> of the <IONOSPHERE>, above the
 *     <IONOSPHERIC_E_REGION>, characterized by weak concentrations of
 *     O[sub(2)]^(+) ions and located roughly between the <<ALTITUDE_MSL>>s
 *     of 200 and 1 500 kilometres; the F2-region or F2-layer.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_IONOSPHERIC_F2_REGION ((EDCS_Classification_Code)591)

/*
 * Definition:
 *     A <TRENCH> that is constructed for the purpose of irrigation or
 *     drainage; an irrigation ditch.
 *
 * Group Membership: AGRICULTURE, PHYSIOGRAPHY
 */
#define ECC_IRRIGATION_DITCH ((EDCS_Classification_Code)592)

/*
 * Definition:
 *     A <TRACT> smaller (usually much smaller) than a continent and
 *     surrounded by a <WATERBODY>; an island.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_ISLAND ((EDCS_Classification_Code)593)

/*
 * Definition:
 *     An <ISOPLETH> that connects <LOCATION>s of equal magnetic variation;
 *     an isogonic line.
 *
 * Group Membership: EM_PHENOMENON, LOCATION
 */
#define ECC_ISOGONIC_LINE ((EDCS_Classification_Code)594)

/*
 * Definition:
 *     A <LINE> defined by <LOCATION>s for which some chosen quantity has the
 *     same value; an isopleth [SOED, "isopleth", 1].
 *
 * Group Membership: LOCATION
 */
#define ECC_ISOPLETH ((EDCS_Classification_Code)595)

/*
 * Definition:
 *     A <TERRAIN_STRIP> that is bordered on both sides by <WATERBODY>s and
 *     that connects two larger bodies of <LAND>; an isthmus.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_ISTHMUS ((EDCS_Classification_Code)596)

/*
 * Definition:
 *     A local <DETENTION_FACILITY> where the criminally accused are
 *     initially taken to be processed and await trial and where short
 *     (usually less than one year) sentences for criminal misconduct can be
 *     served; a jail.
 *
 * Group Membership: ADMINISTRATION, USAGE_REGION
 */
#define ECC_JAIL ((EDCS_Classification_Code)597)

/*
 * Definition:
 *     A man-made <BARRIER> built out into or in a <WATERBODY>, primarily to
 *     restrain or direct <WATER_CURRENT>s and <WATER_WAVE>s; a jetty.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, WATERBODY_SURFACE
 */
#define ECC_JETTY ((EDCS_Classification_Code)598)

/*
 * Definition:
 *     A <TRACT>, especially tropical, overgrown with luxuriant and often
 *     almost impenetrable <VEGETATION>; a jungle [SOED, "jungle", 1].
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_JUNGLE ((EDCS_Classification_Code)599)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is fifth in distance from the
 *     <SUN>, with an orbital mean <<RADIUS>> of approximately 778,30
 *     million kilometres; Jupiter.
 *
 * Group Membership: SPACE
 */
#define ECC_JUPITER ((EDCS_Classification_Code)600)

/*
 * Definition:
 *     A <WATERBODY_FLOOR_REGION> covered with a significant concentration of
 *     kelp; a kelp bed.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT, WATERBODY_FLOOR
 */
#define ECC_KELP_BED ((EDCS_Classification_Code)601)

/*
 * Definition:
 *     A <STRUCTURE> used for the breeding, training, or boarding of dogs; a
 *     kennel [AHD, "kennel", 3].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_KENNEL ((EDCS_Classification_Code)602)

/*
 * Definition:
 *     An oven for hardening, burning, or drying <MATERIAL>s (for example:
 *     grain, meal, and/or clay), especially a brick-lined oven used to bake
 *     or fire ceramics; a kiln [AHD, "kiln"].
 *
 * Group Membership: INDUSTRY
 */
#define ECC_KILN ((EDCS_Classification_Code)603)

/*
 * Definition:
 *     The <REGION> of the <SOLAR_SYSTEM> of the <SUN> beyond the orbit of
 *     <NEPTUNE> where a large number of <COMET>s with short orbital periods
 *     originate; the Kuiper belt.
 *
 * Group Membership: SPACE
 */
#define ECC_KUIPER_BELT ((EDCS_Classification_Code)604)

/*
 * Definition:
 *     An enclosed <REGION> of salt or brackish <WATER> separated from a
 *     larger <WATERBODY> by some more or less effective, but not complete,
 *     <BARRIER> (for example: a low bank of <SAND>); a lagoon.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_LAGOON ((EDCS_Classification_Code)605)

/*
 * Definition:
 *     <INLAND_WATER> without significant flow that is surrounded by <LAND>;
 *     a lake.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_LAKE ((EDCS_Classification_Code)606)

/*
 * Definition:
 *     A representation of a <LAKE> as it connects to related <RIVER_NEXUS>s;
 *     a lake centre-line or lake nexus.
 *
 * Group Membership: HYDROLOGY, LOCATION
 */
#define ECC_LAKE_NEXUS ((EDCS_Classification_Code)607)

/*
 * Definition:
 *     <TERRAIN> that is not permanently covered by <WATER>; land.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_LAND ((EDCS_Classification_Code)608)

/*
 * Definition:
 *     A deeded <PARCEL> granting easement for a specific purpose (for
 *     example: overhead <POWER_TRANSMISSION_LINE>s and/or access to a
 *     <PARKING_GARAGE>); a land easement.
 *
 * Group Membership: SURVEY
 */
#define ECC_LAND_EASEMENT ((EDCS_Classification_Code)609)

/*
 * Definition:
 *     A <FISH_HATCHERY> located entirely on <LAND>.
 *
 * Group Membership: AGRICULTURE, ANIMAL, LIVING_ORGANISM, USAGE_REGION
 */
#define ECC_LAND_FISH_HATCHERY ((EDCS_Classification_Code)610)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> periodically covered by floodwater,
 *     excluding tidal <WATER>s; land flooding periodically.
 *
 * Group Membership: HYDROLOGY, PHYSIOGRAPHY
 */
#define ECC_LAND_FLOODING_PERIODICALLY ((EDCS_Classification_Code)611)

/*
 * Definition:
 *     A <MINEFIELD> on <LAND>.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_LAND_MINEFIELD ((EDCS_Classification_Code)612)

/*
 * Definition:
 *     A <TRANSPORTATION_ROUTE> located principally on <LAND>.
 *
 * Group Membership: LAND_TRNSP, LOCATION, TRNSP
 */
#define ECC_LAND_TRANSPORTATION_ROUTE ((EDCS_Classification_Code)613)

/*
 * Definition:
 *     A <BOUNDARY> where <LAND> is in contact with a <WATERBODY>.
 *
 * Group Membership: DEMARCATION, LITTORAL, LOCATION
 */
#define ECC_LAND_WATER_BOUNDARY ((EDCS_Classification_Code)614)

/*
 * Definition:
 *     A <TRACT> used for solid waste disposal by burying refuse between
 *     layers of <SOIL> to fill in or reclaim low-lying <LAND>; a landfill
 *     [SOED, "landfill", b].
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_LANDFILL ((EDCS_Classification_Code)615)

/*
 * Definition:
 *     A small <WATER_SURFACE_VESSEL> designed to convey <PERSONNEL> and
 *     <EQUIPMENT> from larger <WATER_SURFACE_VESSEL>s to <SHORE> during
 *     landing operations; a landing-craft [SOED, "landing-craft"].
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_LANDING_CRAFT ((EDCS_Classification_Code)616)

/*
 * Definition:
 *     A mass of <MATERIAL> (for example: <SOIL>, <ROCK>, and/or
 *     <VEGETATION>) that has slipped down from a <CLIFF> or <MOUNTAIN>; a
 *     landslide.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_LANDSLIDE ((EDCS_Classification_Code)617)

/*
 * Definition:
 *     A <LOCATION> in a <WATERBODY> where a <DIRECTION> away from seaward is
 *     specified that indicates how a lateral buoyage <SYSTEM> should be
 *     interpreted.
 *
 * Group Membership: LOCATION
 */
#define ECC_LATERAL_BUOYAGE_INDICATION ((EDCS_Classification_Code)618)

/*
 * Definition:
 *     A designated <SITE> or <STRUCTURE> from which a rocket or <MISSILE> is
 *     launched; a launch pad.
 *
 * Group Membership: MILITARY_SCIENCE, TRNSP, USAGE_REGION
 */
#define ECC_LAUNCH_PAD ((EDCS_Classification_Code)619)

/*
 * Definition:
 *     A narrow, flat <SURFACE> or shelf, especially one that projects (for
 *     example: from a <CLIFF>); a ledge.
 *
 * Group Membership: SURFACE
 */
#define ECC_LEDGE ((EDCS_Classification_Code)620)

/*
 * Definition:
 *     A <BUILDING> in a foreign country that houses a diplomatic mission
 *     that ranks below an embassy; a legation building.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_LEGATION_BUILDING ((EDCS_Classification_Code)621)

/*
 * Definition:
 *     An <EMBANKMENT> to prevent the overflow of a <RIVER>; a levee [SOED,
 *     "levee", 2.a.1].
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, PHYSIOGRAPHY
 */
#define ECC_LEVEE ((EDCS_Classification_Code)622)

/*
 * Definition:
 *     A <CROSSING> between a <RAILWAY>and either a <ROAD> or another
 *     <RAILWAY> on the same vertical level; a level crossing or on-grade
 *     crossing.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_LEVEL_CROSSING ((EDCS_Classification_Code)623)

/*
 * Definition:
 *     A <BUILDING> in which literary and artistic materials (for example:
 *     books, periodicals, newspapers, pamphlets, prints, records, and/or
 *     tapes) are kept for reading, reference, and/or lending; a library
 *     [AHD, "library", 1.a].
 *
 * Group Membership: COMMUNICATION, INFRASTRUCTURE, SHELTER
 */
#define ECC_LIBRARY ((EDCS_Classification_Code)624)

/*
 * Definition:
 *     A composite <LIVING_ORGANISM> formed by the association of <ALGA> with
 *     <FUNGUS> and occurring as encrusting or branching friable growths on
 *     <SURFACE>s, to which they give a green, grey, or yellow colour; a
 *     lichen [SOED, "lichen"].
 *
 * Group Membership: LIVING_ORGANISM
 */
#define ECC_LICHEN ((EDCS_Classification_Code)625)

/*
 * Definition:
 *     <EQUIPMENT> consisting of a platform, which is often enclosed, that is
 *     raised and lowered in a vertical shaft to transport <HUMAN>s,
 *     <EQUIPMENT>, or <MATERIAL>s; a lift or an elevator (US) [AHD,
 *     "elevator", 1.a].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define ECC_LIFT ((EDCS_Classification_Code)626)

/*
 * Definition:
 *     A vertical passageway in a <BUILDING> used for a <LIFT>; a lift shaft.
 *
 * Group Membership: BUILDING_COMPONENT, LAND_TRNSP, TRNSP
 */
#define ECC_LIFT_SHAFT ((EDCS_Classification_Code)627)

/*
 * Definition:
 *     An <OBJECT> that is a source of illumination visible to the eye of
 *     <HUMAN>s; a light [SOED, "light", 4].
 *
 * Group Membership: ABSTRACT_OBJECT, LIGHTING_AND_VISIBILITY
 */
#define ECC_LIGHT ((EDCS_Classification_Code)628)

/*
 * Definition:
 *     A <FACILITY> devoted to the manufacture of goods (for example:
 *     electronic <DEVICE>s and/or computer software) that generally require
 *     only limited <MATERIAL> and energy inputs; a light industrial
 *     facility.
 *
 * Group Membership: INDUSTRY, USAGE_REGION
 */
#define ECC_LIGHT_INDUSTRIAL_FACILITY ((EDCS_Classification_Code)629)

/*
 * Definition:
 *     A <STRUCTURE> serving as a support for one or more <LIGHT>s.
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, SUPPORT_STRUCTURE
 */
#define ECC_LIGHT_SUPPORT_STRUCTURE ((EDCS_Classification_Code)630)

/*
 * Definition:
 *     A winged <AIRCRAFT> with a maximum capacity of 10 persons; a light
 *     aircraft.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_LIGHT_WINGED_AIRCRAFT ((EDCS_Classification_Code)631)

/*
 * Definition:
 *     A distinctive <STRUCTURE> exhibiting one or more <LIGHT>s designed to
 *     serve as an <AID_TO_NAVIGATION>; a lighthouse.
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_LIGHTHOUSE ((EDCS_Classification_Code)632)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <LIGHT>s providing illumination for a <REGION> or
 *     <OBJECT>; lighting.
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define ECC_LIGHTING ((EDCS_Classification_Code)633)

/*
 * Definition:
 *     A luminous manifestation accompanying a sudden electrical discharge
 *     that takes place from or inside <CLOUD>s or, less often, from tall
 *     <OBJECT>s on the <PLANETARY_SURFACE> and/or from <MOUNTAIN>s to
 *     <CLOUD>s; lightning.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_LIGHTNING ((EDCS_Classification_Code)634)

/*
 * Definition:
 *     A distinctively marked, manned <WATER_SURFACE_VESSEL> anchored or
 *     moored at a defined <LOCATION> to serve as a
 *     <MARINE_AID_TO_NAVIGATION>; a lightship.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_LIGHTSHIP ((EDCS_Classification_Code)635)

/*
 * Definition:
 *     A curve connecting a <SET> of two or more <LOCATION>s; a line [SOED,
 *     "line", n2.III.14.b] or a curve.
 *
 * Group Membership: LOCATION
 */
#define ECC_LINE ((EDCS_Classification_Code)636)

/*
 * Definition:
 *     <EQUIPMENT> located at or below water level where liquids (for
 *     example: cooling <WATER>) are spread out; a diffuser.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT
 */
#define ECC_LIQUID_DIFFUSER ((EDCS_Classification_Code)637)

/*
 * Definition:
 *     An enclosed <TERRAIN_SURFACE_REGION> in which livestock are
 *     temporarily kept; a livestock pen, a feedlot or a stockyard.
 *
 * Group Membership: AGRICULTURE, ANIMAL, LIVING_ORGANISM, USAGE_REGION
 */
#define ECC_LIVESTOCK_PEN ((EDCS_Classification_Code)638)

/*
 * Definition:
 *     A living thing; a living organism or life-form [SOED, "life-form"].
 *
 * Group Membership: LIVING_ORGANISM
 */
#define ECC_LIVING_ORGANISM ((EDCS_Classification_Code)639)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of rope, fibre, or heavy gauge steel <WIRE>s formed
 *     into one continuous strand and used for support, lifting, hauling,
 *     and other load-supporting functions; a cable.
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_LOAD_CABLE ((EDCS_Classification_Code)640)

/*
 * Definition:
 *     A <TRACT> that is maintained for recreational and ornamental purposes
 *     and set aside for public use, generally with few or no <BUILDING>s
 *     and located within a <BUILT_UP_REGION>.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_LOCAL_PARK ((EDCS_Classification_Code)641)

/*
 * Definition:
 *     A localized <CLOUD> or <NON_AQUEOUS_CLOUD>; a localized atmospheric
 *     suspension.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_LOCALIZED_ATM_SUSPENSION ((EDCS_Classification_Code)642)

/*
 * Definition:
 *     A spatial location.
 *
 * Group Membership: LOCATION
 */
#define ECC_LOCATION ((EDCS_Classification_Code)643)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the properties of a <LOCATION>.
 *
 * Group Membership: LOCATION, PROPERTY_SET
 */
#define ECC_LOCATION_PROPERTY_SET ((EDCS_Classification_Code)644)

/*
 * Definition:
 *     The portion of a <HYDROGRAPHIC_LOCK> bounded by <LOCK_GATE>s at each
 *     end; a lock basin.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_LOCK_BASIN ((EDCS_Classification_Code)645)

/*
 * Definition:
 *     A pair of massive, hinged <DOOR>s at the end of a <LOCK_BASIN>; a lock
 *     gate.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_LOCK_GATE ((EDCS_Classification_Code)646)

/*
 * Definition:
 *     A self-propelled <GROUND_VEHICLE> designed to move <RAIL_WAGON>s on a
 *     <RAILWAY_TRACK>; a locomotive engine [MWCD, "locomotive", 1].
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_LOCOMOTIVE_ENGINE ((EDCS_Classification_Code)647)

/*
 * Definition:
 *     An unhewn portion of a felled <TREE>; a log [SOED, "log", 1.a].
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_LOG ((EDCS_Classification_Code)648)

/*
 * Definition:
 *     A <WATERBODY_BOOM> designed to keep <LOG>s ready for a <SAWMILL> from
 *     floating away; a log boom.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_INDUSTRY, INDUSTRY, WATERBODY_SURFACE
 */
#define ECC_LOG_BOOM ((EDCS_Classification_Code)649)

/*
 * Definition:
 *     A <LOG_OBSTACLE> that is formed in a cribwork and filled with <SOIL>
 *     and <STONE>s.
 *
 * Group Membership: LAND_TRNSP
 */
#define ECC_LOG_CRIB ((EDCS_Classification_Code)650)

/*
 * Definition:
 *     A <TERRAIN_OBSTACLE> constructed primarily of <LOG>s.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_LOG_OBSTACLE ((EDCS_Classification_Code)651)

/*
 * Definition:
 *     A <RAMP> used to dump <LOG>s into a <WATERBODY> for transport or to
 *     haul <LOG>s out of the <WATERBODY> for processing; a log ramp.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_LOG_RAMP ((EDCS_Classification_Code)652)

/*
 * Definition:
 *     A <TRACT> of <VEGETATION> that is being exploited for lumber
 *     resources; a logging site.
 *
 * Group Membership: LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_LOGGING_SITE ((EDCS_Classification_Code)653)

/*
 * Definition:
 *     A <CLOUD> of the genus stratocumulus or stratus; a low cloud. Also the
 *     base of a <CLOUD> of the genus cumulus; cumulonimbus; or,
 *     occasionally, nimbostratus.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_LOW_CLOUD ((EDCS_Classification_Code)654)

/*
 * Definition:
 *     An <ATMOSPHERE_REGION> in which the <<ATM_CEILING>> due to <CLOUD>s is
 *     less than 152,4 metres (500 feet) above the <PLANETARY_SURFACE>; a
 *     low cloud ceiling region.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_LOW_CLOUD_CEILING_REGION ((EDCS_Classification_Code)655)

/*
 * Definition:
 *     The <LOCATION> of the centre of an <ATMOSPHERE_REGION> of low
 *     <<ATM_PRESSURE>>.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_LOW_PRESSURE_CENTRE ((EDCS_Classification_Code)656)

/*
 * Definition:
 *     An <ATMOSPHERE_REGION> of reduced visibility near a
 *     <PLANETARY_SURFACE>; a low visibility region.
 *
 * Group Membership: ATMOSPHERE, LIGHTING_AND_VISIBILITY
 */
#define ECC_LOW_VISIBILITY_REGION ((EDCS_Classification_Code)657)

/*
 * Definition:
 *     The intersection of the plane of low water with the <SHORE>; the
 *     <LINE> along a <COAST> or <BEACH> to which the <SEA> recedes at low
 *     water; a low water line or drying line.
 *
 * Group Membership: LITTORAL, LOCATION
 */
#define ECC_LOW_WATER_LINE ((EDCS_Classification_Code)658)

/*
 * Definition:
 *     A <DEVICE> used for the collection of <MAGNETIC_FIELD> data.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, EM_PHENOMENON
 */
#define ECC_MAGNETIC_DATA_DEVICE ((EDCS_Classification_Code)659)

/*
 * Definition:
 *     A localized anomaly in the <MAGNETIC_FIELD> of a <PLANET>; a magnetic
 *     disturbance.
 *
 * Group Membership: EM_PHENOMENON
 */
#define ECC_MAGNETIC_DISTURBANCE ((EDCS_Classification_Code)660)

/*
 * Definition:
 *     A <REGION> where a field of force produced by a magnetic <OBJECT> or
 *     by a changing <ELECTRICAL_FIELD> is found; a magnetic field [SOED,
 *     "magnetic field"].
 *
 * Group Membership: EM_PHENOMENON
 */
#define ECC_MAGNETIC_FIELD ((EDCS_Classification_Code)661)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the properties of a <MAGNETIC_FIELD>.
 *
 * Group Membership: EM_PHENOMENON, PROPERTY_SET
 */
#define ECC_MAGNETIC_FIELD_PROPERTY_SET ((EDCS_Classification_Code)662)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the properties of a <MAGNETIC_FIELD> near
 *     a <PLANETARY_SURFACE>.
 *
 * Group Membership: EM_PHENOMENON, PROPERTY_SET
 */
#define ECC_MAGNETIC_FIELD_SURFACE_PROPERTY_SET ((EDCS_Classification_Code)663)

/*
 * Definition:
 *     A <MAGNETIC_DATA_DEVICE> and support <STRUCTURE>s; a magnetic station.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, EM_PHENOMENON
 */
#define ECC_MAGNETIC_STATION ((EDCS_Classification_Code)664)

/*
 * Definition:
 *     The sharp <BOUNDARY> between a <MAGNETOSPHERE> and the <STELLAR_WIND>;
 *     the magnetopause.
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, EM_PHENOMENON, LOCATION
 */
#define ECC_MAGNETOPAUSE ((EDCS_Classification_Code)665)

/*
 * Definition:
 *     The <REGION> of rarefied ionized gases in the <ATMOSPHERE> of a
 *     <PLANET> in which the dynamical motions are strongly influenced or
 *     even dominated by the <MAGNETIC_FIELD> of that <PLANET>; the
 *     magnetosphere.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_MAGNETOSPHERE ((EDCS_Classification_Code)666)

/*
 * Definition:
 *     A flux of charged <PARTICLE>s within the <MAGNETOSPHERE>; a
 *     magnetosphere plasma.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_MAGNETOSPHERE_PLASMA ((EDCS_Classification_Code)667)

/*
 * Definition:
 *     A <STRUCTURE> housing a central <SYSTEM> of switches and other
 *     <EQUIPMENT> that establishes connections between individual
 *     telecommunication <DEVICE>s (for example: a telephone); a main
 *     telecom exchange.
 *
 * Group Membership: COMMUNICATION, INFRASTRUCTURE
 */
#define ECC_MAIN_TELECOM_EXCHANGE ((EDCS_Classification_Code)668)

/*
 * Definition:
 *     A furred, warm-blooded <VERTEBRATE> of the class Mammalia, the members
 *     of which are characterized by the possession of mammary glands in the
 *     female and a four-chambered heart; a mammal [SOED, "mammal"].
 *     EXAMPLES <HUMAN>, <RODENT>, <BAT>, <WHALE>, ungulate, <CARNIVORE>.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_MAMMAL ((EDCS_Classification_Code)669)

/*
 * Definition:
 *     A man-made <STRUCTURE> of sufficient <<HEIGHT_AGL>> to impede or
 *     obstruct flight operations and cause a hazard to air navigation; a
 *     man-made air obstruction.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_MAN_MADE_AIR_OBSTRUCTION ((EDCS_Classification_Code)670)

/*
 * Definition:
 *     A cleared or ploughed <TERRAIN_STRIP> designed to: provide access for
 *     a <LAND_TRANSPORTATION_ROUTE>, <PIPELINE>, or
 *     <POWER_TRANSMISSION_LINE>; demarcate a <BOUNDARY>; obtain survey
 *     line-of-sight; or provide a <FIREBREAK>; a man-made clearing.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_MAN_MADE_CLEARING ((EDCS_Classification_Code)671)

/*
 * Definition:
 *     An <OBJECT> made by <HUMAN>s; a man-made object.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_MAN_MADE_OBJECT ((EDCS_Classification_Code)672)

/*
 * Definition:
 *     An <APERTURE> in a utility service <OBJECT> (for example: an item of
 *     <EQUIPMENT>, a <FLOOR>, a <ROAD>, the <LAND>, a <SEWER> and/or other
 *     conduit) through which <PERSONNEL> may pass to gain access to certain
 *     <COMPONENT>s; a manhole [SOED, "manhole"].
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_MANHOLE ((EDCS_Classification_Code)673)

/*
 * Definition:
 *     A cover, which is often made of cast iron, that is designed both for
 *     complete removal and to cover a <MANHOLE>.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_MANHOLE_COVER ((EDCS_Classification_Code)674)

/*
 * Definition:
 *     A <STRUCTURE> that elevates a <MANHOLE> above the surrounding
 *     <SURFACE>; a manhole riser.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_MANHOLE_RISER ((EDCS_Classification_Code)675)

/*
 * Definition:
 *     A <FACILITY> including one or more <FACTORY>s; a manufacturing
 *     facility.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER, USAGE_REGION
 */
#define ECC_MANUFACTURING_FACILITY ((EDCS_Classification_Code)676)

/*
 * Definition:
 *     A graphic representation of natural and artificial <OBJECT>s within a
 *     <REGION>; a map.
 *
 * Group Membership: SURVEY
 */
#define ECC_MAP ((EDCS_Classification_Code)677)

/*
 * Definition:
 *     A <BOUNDARY> that encloses all <OBJECT>s depicted on a <MAP>; a map
 *     boundary.
 *
 * Group Membership: DEMARCATION, LOCATION, SURVEY
 */
#define ECC_MAP_BOUNDARY ((EDCS_Classification_Code)678)

/*
 * Definition:
 *     A graphic representation of the edge of a <MAP>; a map frame.
 *
 * Group Membership: DEMARCATION, SURVEY
 */
#define ECC_MAP_EDGE_FRAME ((EDCS_Classification_Code)679)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of auxiliary information about a <MAP>; a map legend.
 *
 * Group Membership: SURVEY
 */
#define ECC_MAP_LEGEND ((EDCS_Classification_Code)680)

/*
 * Definition:
 *     The spatial extent of the <REGION> represented by a <MAP>; map limits.
 *
 * Group Membership: SURVEY
 */
#define ECC_MAP_LIMITS ((EDCS_Classification_Code)681)

/*
 * Definition:
 *     A <SHRINE> marking the burial place of an Islamic holy man; a marabout
 *     [SOED, "marabout", 2].
 *
 * Group Membership: RELIGION
 */
#define ECC_MARABOUT ((EDCS_Classification_Code)682)

/*
 * Definition:
 *     An <AID_TO_NAVIGATION> (for example: a <BEACON> and/or a <BUOY>)
 *     intended to support marine operations.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_AID_TO_NAVIGATION ((EDCS_Classification_Code)683)

/*
 * Definition:
 *     A <WATERBODY> partially enclosed by <LAND> but with a wide mouth that
 *     affords access to the <SEA>; a marine bay.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_MARINE_BAY ((EDCS_Classification_Code)684)

/*
 * Definition:
 *     The part of a <WATERBODY> that is deep enough for navigation through a
 *     <REGION> otherwise not suitable; a marine channel. EXAMPLE The
 *     deepest part of a <RIVER>, <MARINE_BAY>, or <MARINE_STRAIT> through
 *     which the main <WATERBODY_CURRENT> flows.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, HYDROLOGY, TRNSP
 */
#define ECC_MARINE_CHANNEL ((EDCS_Classification_Code)685)

/*
 * Definition:
 *     A straight <LINE> that separates a safe <WATERBODY_REGION> from a
 *     dangerous <REGION> or that passes clear of a marine navigational
 *     danger; a marine clearing line.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_MARINE_CLEARING_LINE ((EDCS_Classification_Code)686)

/*
 * Definition:
 *     A comparatively shallow <WATERBODY_REGION> strewn with
 *     <MARINE_OBSTRUCTION>s (for example: boulders, <CORAL>, and/or
 *     <MARINE_WRECK>s), making it unsuitable for anchoring, grounding,
 *     and/or fishing; marine foul ground.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, HYDROLOGY, TRNSP
 */
#define ECC_MARINE_FOUL_GROUND ((EDCS_Classification_Code)687)

/*
 * Definition:
 *     A <BARRIER> that may be swung, drawn, or lowered to block an entrance
 *     or <MARINE_ROUTE> on a <WATERBODY>; a marine gate.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_GATE ((EDCS_Classification_Code)688)

/*
 * Definition:
 *     A flat frame <STRUCTURE>, usually of parallel timber baulks, erected
 *     on the <FORESHORE> so that a <VESSEL> may dry out on it for painting
 *     or repair at low water; a marine gridiron.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_GRIDIRON ((EDCS_Classification_Code)689)

/*
 * Definition:
 *     A large <WATERBODY_REGION> partially enclosed by <LAND>, especially a
 *     long land-locked portion of a <WATERBODY> opening through a
 *     <MARINE_STRAIT>; a marine gulf.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_MARINE_GULF ((EDCS_Classification_Code)690)

/*
 * Definition:
 *     A <SET> of two or more marine <LIGHT>s that form a
 *     <MARINE_LEADING_LINE> of a course to be followed.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_MARINE_LEADING_LIGHTS_LINE ((EDCS_Classification_Code)691)

/*
 * Definition:
 *     A track along which a <VESSEL> can safely travel that passes through
 *     one or more (usually two) clearly defined <OBJECT>s; a marine leading
 *     line.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_LEADING_LINE ((EDCS_Classification_Code)692)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of marine <LIGHT>s marking limits, the alignment of
 *     a <ELECTRICAL_CABLE>, or alignments for anchoring or serving a
 *     similar purpose but not marking <DIRECTION>; a marine light line.
 *
 * Group Membership: DEMARCATION, HYDROGRAPHIC_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_MARINE_LIGHT_LINE ((EDCS_Classification_Code)693)

/*
 * Definition:
 *     A sector defined by bearings from seaward within which a <LIGHT> shows
 *     a specified character or colour or is obscured so that it may serve
 *     as a <MARINE_AID_TO_NAVIGATION>; a marine light sector.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_MARINE_LIGHT_SECTOR ((EDCS_Classification_Code)694)

/*
 * Definition:
 *     A <BOUNDARY> separating two <MARINE_REGION>s; a marine limit boundary.
 *
 * Group Membership: DEMARCATION, HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_MARINE_LIMIT_BOUNDARY ((EDCS_Classification_Code)695)

/*
 * Definition:
 *     A <HYDROGRAPHIC_LOCK> in a <WATERCOURSE>, permitting a <VESSEL> to
 *     pass from one level to another; a marine lock.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_LOCK ((EDCS_Classification_Code)696)

/*
 * Definition:
 *     A course, the <<LENGTH>> of which has been accurately measured, that
 *     is used in conjunction with ranges ashore by <VESSEL>s to calibrate
 *     logs, engine revolution counters, and other onboard <EQUIPMENT> and
 *     to determine speed; a marine measured distance line.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_MARINE_MEASURED_DISTANCE_LINE ((EDCS_Classification_Code)697)

/*
 * Definition:
 *     A marine <MINEFIELD>.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_MARINE_MINEFIELD ((EDCS_Classification_Code)698)

/*
 * Definition:
 *     A substantial masonry <STRUCTURE> that often serves as a <BREAKWATER>
 *     on its outer side while it offers <FACILITY>s where <VESSEL>s are
 *     loaded and discharged on its inner side; a marine mole.
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_MARINE_MOLE ((EDCS_Classification_Code)699)

/*
 * Definition:
 *     A coloured (usually white) mark on a vertical <SURFACE> (for example:
 *     a <CLIFF>, a <ROCKY_OUTCROP>, and/or a <WALL>) that is a conspicuous
 *     landmark for marine navigation; a marine navigation marker.
 *
 * Group Membership: COLOUR, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_NAVIGATION_MARKER ((EDCS_Classification_Code)700)

/*
 * Definition:
 *     An <OBJECT> relating to or characteristic of <VESSEL>s, shipping,
 *     sailors, or navigation on a <WATERBODY>; a marine object [SOED,
 *     "marine", B.2].
 *
 * Group Membership: ABSTRACT_OBJECT, HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, TRNSP
 */
#define ECC_MARINE_OBJECT ((EDCS_Classification_Code)701)

/*
 * Definition:
 *     A danger to marine navigation, the exact nature of which is not
 *     specified or has not been determined; a marine obstruction.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_OBSTRUCTION ((EDCS_Classification_Code)702)

/*
 * Definition:
 *     A <MARINE_REGION> where <PETROLEUM> is pumped or otherwise removed
 *     from the ground; a marine petroleum field.
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROLOGY, INDUSTRY, USAGE_REGION
 */
#define ECC_MARINE_PETROLEUM_FIELD ((EDCS_Classification_Code)703)

/*
 * Definition:
 *     A flat <SURFACE> raised above a <WATERBODY> that serves as a working
 *     stage for conducting offshore operations; a marine platform.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_INDUSTRY, INDUSTRY
 */
#define ECC_MARINE_PLATFORM ((EDCS_Classification_Code)704)

/*
 * Definition:
 *     A <POLICE_STATION> that serves a <HARBOUR> or coastal <REGION>; a
 *     marine police station.
 *
 * Group Membership: ADMINISTRATION, HARBOUR_AND_PORT
 */
#define ECC_MARINE_POLICE_STATION ((EDCS_Classification_Code)705)

/*
 * Definition:
 *     A marine <FACILITY>, usually located in a <HARBOUR>, that provides
 *     terminal and transfer facilities for loading and discharging <CARGO>
 *     and/or passengers; a marine port.
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_MARINE_PORT ((EDCS_Classification_Code)706)

/*
 * Definition:
 *     A partially submerged <TERRAIN_SURFACE_REGION> with a hard <SURFACE>
 *     on a <SHORE> for launching and retrieving <VESSEL>s; a marine ramp.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_RAMP ((EDCS_Classification_Code)707)

/*
 * Definition:
 *     A marine <REGION> in which certain activities or factors of
 *     significance to navigation and/or operation apply.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, HYDROLOGY, TRNSP, USAGE_REGION
 */
#define ECC_MARINE_REGION ((EDCS_Classification_Code)708)

/*
 * Definition:
 *     A <TRANSPORTATION_ROUTE> on a <WATERBODY> established for the safe
 *     passage of <VESSEL>s; a marine route.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_MARINE_ROUTE ((EDCS_Classification_Code)709)

/*
 * Definition:
 *     A representation of one or more <MARINE_ROUTE>s; a marine route
 *     centre-line or marine route nexus.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_MARINE_ROUTE_NEXUS ((EDCS_Classification_Code)710)

/*
 * Definition:
 *     A station on <SHORE> from which signals are made to <VESSEL>s; a
 *     marine signal station.
 *
 * Group Membership: COMMUNICATION, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MARINE_SIGNAL_STATION ((EDCS_Classification_Code)711)

/*
 * Definition:
 *     A long, relatively wide <WATERBODY> that is larger than a
 *     <MARINE_STRAIT> or a <MARINE_CHANNEL> and that connects larger
 *     <WATERBODY>s (for example: <SEA>s and/or <OCEAN>s); a marine sound
 *     [AHD, "sound", 3.1.a].
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_MARINE_SOUND ((EDCS_Classification_Code)712)

/*
 * Definition:
 *     A narrow channel joining two <WATERBODY>s; a marine strait [SOED,
 *     "strait", 3].
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_MARINE_STRAIT ((EDCS_Classification_Code)713)

/*
 * Definition:
 *     The ruined remains of a stranded or sunken <VESSEL> that has been
 *     rendered useless; a marine wreck.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_MARINE_WRECK ((EDCS_Classification_Code)714)

/*
 * Definition:
 *     An <OBJECT> (for example: a <BOUNDARY_MONUMENT> and/or a
 *     <MEMORIAL_MONUMENT>) marking a <LOCATION> of special interest; a
 *     marker [SOED, "marker", 3.b].
 *
 * Group Membership: ABSTRACT_OBJECT, LOCATION
 */
#define ECC_MARKER ((EDCS_Classification_Code)715)

/*
 * Definition:
 *     An open space or <STRUCTURE> where goods are offered for sale; a
 *     market [SOED, "market", 2].
 *
 * Group Membership: INDUSTRY
 */
#define ECC_MARKET ((EDCS_Classification_Code)716)

/*
 * Definition:
 *     A <MARKET> where goods are offered for sale by several vendors; a
 *     market-place [SOED, "market-place", a].
 *
 * Group Membership: INDUSTRY
 */
#define ECC_MARKET_PLACE ((EDCS_Classification_Code)717)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is fourth in distance from the
 *     <SUN> with an orbital mean <<RADIUS>> of approximately 227,94 million
 *     kilometres; Mars.
 *
 * Group Membership: SPACE
 */
#define ECC_MARS ((EDCS_Classification_Code)718)

/*
 * Definition:
 *     A soft, wet, low-lying <WETLAND> that is characterized by grassy
 *     <VEGETATION> and that often forms a transition <REGION> between a
 *     <WATERBODY> and <LAND>; a marsh [AHD, "marsh"].
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_MARSH ((EDCS_Classification_Code)719)

/*
 * Definition:
 *     A stone <TOWER> defending a <COAST> or <HARBOUR> and usually including
 *     a gun platform, ammunition magazine, and accommodations for a
 *     garrison; a Martello tower.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_MARTELLO_TOWER ((EDCS_Classification_Code)720)

/*
 * Definition:
 *     A straight piece of timber or a hollow cylinder of wood or metal set
 *     up vertically, or nearly so; a mast.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_MAST ((EDCS_Classification_Code)721)

/*
 * Definition:
 *     The matter of which an <OBJECT> is or may be made; material [SOED,
 *     "material", b.1].
 *
 * Group Membership: ABSTRACT_OBJECT, MATERIAL
 */
#define ECC_MATERIAL ((EDCS_Classification_Code)722)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the <MATERIAL>s composing an <OBJECT>.
 *
 * Group Membership: MATERIAL, PROPERTY_SET
 */
#define ECC_MATERIAL_PROPERTY_SET ((EDCS_Classification_Code)723)

/*
 * Definition:
 *     A <FACILITY> devoted to medical research and/or the practice of
 *     medicine.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_MEDICAL_FACILITY ((EDCS_Classification_Code)724)

/*
 * Definition:
 *     A <MARKER> erected and/or maintained as a memorial to a person and/or
 *     event; a memorial monument.
 *
 * Group Membership: LOCATION
 */
#define ECC_MEMORIAL_MONUMENT ((EDCS_Classification_Code)725)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> designed or designated for use in commerce; a
 *     merchant marine vessel.
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, TRNSP, VEHICLE
 */
#define ECC_MERCHANT_MARINE_VESSEL ((EDCS_Classification_Code)726)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is closest to the <SUN>, with
 *     an orbital mean <<RADIUS>> of approximately 57,91 million kilometres;
 *     Mercury.
 *
 * Group Membership: SPACE
 */
#define ECC_MERCURY ((EDCS_Classification_Code)727)

/*
 * Definition:
 *     A flat-topped <HILL> or tableland that is larger than a <BUTTE> and
 *     rises steeply from a surrounding <TERRAIN_PLAIN>; a mesa.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_MESA ((EDCS_Classification_Code)728)

/*
 * Definition:
 *     An abstract <OBJECT> consisting of three related <NON_EMPTY_SET>s: a
 *     <MESH_NODE_SET>, a <MESH_EDGE_SET>, and a <MESH_FACE_SET>; a mesh.
 *
 * Group Membership: ABSTRACT_OBJECT, ALGORITHM_RELATED
 */
#define ECC_MESH ((EDCS_Classification_Code)729)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the edges comprising a <MESH>.
 *
 * Group Membership: ALGORITHM_RELATED, PROPERTY_SET
 */
#define ECC_MESH_EDGE_PROPERTY_SET ((EDCS_Classification_Code)730)

/*
 * Definition:
 *     The <NON_EMPTY_SET> of edges comprising a <MESH>. Each edge in the
 *     <NON_EMPTY_SET> connects two nodes in the related <MESH_NODE_SET>.
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define ECC_MESH_EDGE_SET ((EDCS_Classification_Code)731)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the faces comprising a <MESH>.
 *
 * Group Membership: ALGORITHM_RELATED, PROPERTY_SET
 */
#define ECC_MESH_FACE_PROPERTY_SET ((EDCS_Classification_Code)732)

/*
 * Definition:
 *     The <NON_EMPTY_SET> of polygonal faces comprising a <MESH>. The edges
 *     bounding each face in the <NON_EMPTY_SET> are members of the related
 *     <MESH_EDGE_SET>.
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define ECC_MESH_FACE_SET ((EDCS_Classification_Code)733)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the nodes comprising a <MESH>.
 *
 * Group Membership: ALGORITHM_RELATED, PROPERTY_SET
 */
#define ECC_MESH_NODE_PROPERTY_SET ((EDCS_Classification_Code)734)

/*
 * Definition:
 *     The <NON_EMPTY_SET> of nodes comprising a <MESH>.
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define ECC_MESH_NODE_SET ((EDCS_Classification_Code)735)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the solids comprising a <SOLID_MESH>.
 *
 * Group Membership: ALGORITHM_RELATED, PROPERTY_SET
 */
#define ECC_MESH_SOLID_PROPERTY_SET ((EDCS_Classification_Code)736)

/*
 * Definition:
 *     The <NON_EMPTY_SET> of polyhedral solids comprising a <SOLID_MESH>.
 *     The faces bounding each solid in the <NON_EMPTY_SET> are members of
 *     the related <MESH_FACE_SET>.
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define ECC_MESH_SOLID_SET ((EDCS_Classification_Code)737)

/*
 * Definition:
 *     A low <FLOOR_LEVEL> between two others, especially a low <FLOOR_LEVEL>
 *     between the ground <FLOOR_LEVEL> and the <FLOOR_LEVEL> above or,
 *     occasionally, between the ground <FLOOR_LEVEL> and the <BASEMENT>; a
 *     mezzanine [SOED, "mezzanine", A.1].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_MEZZANINE ((EDCS_Classification_Code)738)

/*
 * Definition:
 *     A <CLOUD> of the genus altocumulus, altostratus, or nimbostratus; a
 *     middle cloud. Also portions of a <CLOUD> of the genus cumulus or
 *     cumulonimbus.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_MIDDLE_CLOUD ((EDCS_Classification_Code)739)

/*
 * Definition:
 *     A military <FACILITY>.
 *
 * Group Membership: MILITARY_SCIENCE, USAGE_REGION
 */
#define ECC_MILITARY_FACILITY ((EDCS_Classification_Code)740)

/*
 * Definition:
 *     A <TRACT> that is protected by <FORTIFICATION>s or natural advantages
 *     and from which military operations are performed, forward movements
 *     are made, or supplies are furnished; a military installation.
 *
 * Group Membership: MILITARY_SCIENCE, USAGE_REGION
 */
#define ECC_MILITARY_INSTALLATION ((EDCS_Classification_Code)741)

/*
 * Definition:
 *     A <BUILDING> devoted to the act or process of managing military forces
 *     or overseeing the conduct of military operations; a military
 *     operations building.
 *
 * Group Membership: ADMINISTRATION, MILITARY_SCIENCE, SHELTER
 */
#define ECC_MILITARY_OPERATIONS_BUILDING ((EDCS_Classification_Code)742)

/*
 * Definition:
 *     <PERSONNEL> who are members of an armed force; military personnel.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, MILITARY_SCIENCE
 */
#define ECC_MILITARY_PERSONNEL ((EDCS_Classification_Code)743)

/*
 * Definition:
 *     A <TRENCH> dug for military purposes.
 *
 * Group Membership: MILITARY_SCIENCE, PHYSIOGRAPHY
 */
#define ECC_MILITARY_TRENCH ((EDCS_Classification_Code)744)

/*
 * Definition:
 *     A tall, slender <TOWER> or turret connected with a <MOSQUE> and
 *     surrounded by one or more projecting <BALCONY>s from which a muezzin
 *     calls at hours of prayer; a minaret [SOED, "minaret"].
 *
 * Group Membership: BUILDING_COMPONENT, RELIGION
 */
#define ECC_MINARET ((EDCS_Classification_Code)745)

/*
 * Definition:
 *     Designed to employ <EXPLOSIVE_NAVAL_MINE>s in warfare or
 *     countermeasures against <EXPLOSIVE_NAVAL_MINE>s while operating in
 *     coastal <WATERBODY_SURFACE_REGION>s; mine countermeasure. Such a
 *     <COMBATANT_VESSEL> is also designed to be carried aboard larger
 *     <VESSEL>s.
 *
 * Group Membership: VEHICLE
 */
#define ECC_MINE_COUNTERMEASURE_VESSEL ((EDCS_Classification_Code)746)

/*
 * Definition:
 *     A <REGION> throughout which <EXPLOSIVE_MINE>s have been laid; a
 *     minefield.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_MINEFIELD ((EDCS_Classification_Code)747)

/*
 * Definition:
 *     A man-made heap of mining or quarrying products that does not contain
 *     waste <MATERIAL>s; a mineral pile.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_MINERAL_PILE ((EDCS_Classification_Code)748)

/*
 * Definition:
 *     A destructive projectile that during part or all of its course is
 *     self-propelling and directed by remote control or automatically; a
 *     missile [SOED, "guided missile"].
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_MISSILE ((EDCS_Classification_Code)749)

/*
 * Definition:
 *     A <SITE> and related <FACILITY>s for storing and launching <MISSILE>s;
 *     a missile site.
 *
 * Group Membership: MILITARY_SCIENCE, USAGE_REGION
 */
#define ECC_MISSILE_SITE ((EDCS_Classification_Code)750)

/*
 * Definition:
 *     A religious centre established in a <REGION> for missionary,
 *     evangelical, or humanitarian work; a mission [SOED, "mission", 4.b].
 *
 * Group Membership: RELIGION
 */
#define ECC_MISSION ((EDCS_Classification_Code)751)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> containing <STRUCTURE>s in combination with
 *     undeveloped and/or agricultural <TRACT>s; a mixed urban region.
 *
 * Group Membership: AGRICULTURE
 */
#define ECC_MIXED_URBAN_REGION ((EDCS_Classification_Code)752)

/*
 * Definition:
 *     A <TRACT> covered by a mixture of woody and non-woody <PLANT>s; a
 *     mixed vegetation land.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_MIXED_VEGETATION_LAND ((EDCS_Classification_Code)753)

/*
 * Definition:
 *     A <TRENCH>, which is usually filled with <WATER>, that surrounds a
 *     <TRACT> and serves as a <BARRIER>; a moat.
 *
 * Group Membership: DEMARCATION
 */
#define ECC_MOAT ((EDCS_Classification_Code)754)

/*
 * Definition:
 *     A <SYSTEM> that is transported on a <VEHICLE> and used to erect
 *     semi-permanent <BRIDGE>s; a mobile bridge system.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_MOBILE_BRIDGE_SYSTEM ((EDCS_Classification_Code)755)

/*
 * Definition:
 *     A trailer that is used as a <DWELLING>, has no permanent foundation,
 *     and is designed to be easily moved; a mobile home [MWCD, "mobile
 *     home"].
 *
 * Group Membership: SHELTER
 */
#define ECC_MOBILE_HOME ((EDCS_Classification_Code)756)

/*
 * Definition:
 *     A <SITE> for the long-term parking of <MOBILE_HOME>s; a mobile home
 *     park.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_MOBILE_HOME_PARK ((EDCS_Classification_Code)757)

/*
 * Definition:
 *     An <INVERTEBRATE> of the phylum Mollusca, the members of which have a
 *     soft body and usually a hard shell; a mollusc [SOED,"mollusc"].
 *     EXAMPLES Limpet, snail, cuttlefish, oyster, mussel.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_MOLLUSC ((EDCS_Classification_Code)758)

/*
 * Definition:
 *     A <RELIGIOUS_COMMUNITY> of men; a monastery [SOED, "monastery"].
 *
 * Group Membership: RELIGION, SHELTER
 */
#define ECC_MONASTERY ((EDCS_Classification_Code)759)

/*
 * Definition:
 *     A <LIVING_ORGANISM> of the kingdom Monera, which comprises all
 *     prokaryotic single-celled organisms; a moneran [SOED, "monera"].
 *     EXAMPLES Bacterium, cyanophyte.
 *
 * Group Membership: LIVING_ORGANISM
 */
#define ECC_MONERAN ((EDCS_Classification_Code)760)

/*
 * Definition:
 *     The only <SATELLITE> of <EARTH>, with an orbital semi-major <<RADIUS>>
 *     of approximately 384 400 kilometres; the Moon.
 *
 * Group Membership: SPACE
 */
#define ECC_MOON ((EDCS_Classification_Code)761)

/*
 * Definition:
 *     One or more <STRUCTURAL_PILE>s used in a <MOORING_FACILITY> or as a
 *     <MARINE_AID_TO_NAVIGATION>; a mooring dolphin.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MOORING_DOLPHIN ((EDCS_Classification_Code)762)

/*
 * Definition:
 *     A <FACILITY> used for mooring and/or warping a <VESSEL>.
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP
 */
#define ECC_MOORING_FACILITY ((EDCS_Classification_Code)763)

/*
 * Definition:
 *     A <LOAD_CABLE> used for mooring; a mooring line.
 *
 * Group Membership: TRNSP
 */
#define ECC_MOORING_LINE ((EDCS_Classification_Code)764)

/*
 * Definition:
 *     A <MAST> used to secure an <AIRSHIP>; a mooring mast.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_MOORING_MAST ((EDCS_Classification_Code)765)

/*
 * Definition:
 *     A metal ring attached to a <STRUCTURE> and used to secure a <VESSEL>;
 *     a mooring ring.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MOORING_RING ((EDCS_Classification_Code)766)

/*
 * Definition:
 *     An <ANCHOR> and a related <NAVIGATION_MARK_AFLOAT>; a mooring trot.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_MOORING_TROT ((EDCS_Classification_Code)767)

/*
 * Definition:
 *     An accumulation of debris consisting of <SOIL> and <ROCK> that has
 *     been deposited by a <GLACIER>; a moraine.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_MORAINE ((EDCS_Classification_Code)768)

/*
 * Definition:
 *     A <WORSHIP_PLACE> where sacred Mormon ordinances are administered; a
 *     Mormon temple [SOED, "temple", A.I.4].
 *
 * Group Membership: RELIGION
 */
#define ECC_MORMON_TEMPLE ((EDCS_Classification_Code)769)

/*
 * Definition:
 *     A muzzle loading cannon for firing shells at low velocities, short
 *     ranges, and high trajectories; a mortar [AHD, "mortar", 3.a].
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_MORTAR ((EDCS_Classification_Code)770)

/*
 * Definition:
 *     An Islamic <WORSHIP_PLACE>; a mosque or masjid.
 *
 * Group Membership: RELIGION
 */
#define ECC_MOSQUE ((EDCS_Classification_Code)771)

/*
 * Definition:
 *     A <PLANT> of the class Musci, comprising small bryophtes with
 *     scale-like leaves usually spirally arranged, with a spore-capsule
 *     usually opening by a lid, which grow in crowded masses in <BOG>s or
 *     on <SURFACE>s; or any of certain <ALGA>s, <LICHEN>s, <PTERIDOPHYTE>s,
 *     or flowering <PLANT>s resembling moss in habit; moss [SOED, "moss",
 *     II 3] or a moss-like plant.
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_MOSS ((EDCS_Classification_Code)772)

/*
 * Definition:
 *     A <BUILDING> used to provide lodging for motorists in <ROOM>s usually
 *     having direct access to an open <VEHICLE_LOT>; a motel [AHD,
 *     "motel"], motor court, or motor lodge.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_MOTEL ((EDCS_Classification_Code)773)

/*
 * Definition:
 *     A <GROUND_VEHICLE> powered by a motor and operating principally on
 *     <LAND>; a motor vehicle.
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_MOTOR_VEHICLE ((EDCS_Classification_Code)774)

/*
 * Definition:
 *     A <STRUCTURE> at, or in which, <MOTOR_VEHICLE>s are refuelled,
 *     serviced, and sometimes repaired; a filling station.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_MOTOR_VEHICLE_STATION ((EDCS_Classification_Code)775)

/*
 * Definition:
 *     A natural elevation of <TERRAIN> of an altitude that is impressive or
 *     notable relative to adjacent elevations; a mountain.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_MOUNTAIN ((EDCS_Classification_Code)776)

/*
 * Definition:
 *     A <LAND_TRANSPORTATION_ROUTE> through a localized
 *     <TERRAIN_SURFACE_REGION> in a range of <MOUNTAIN>s, where the
 *     <TERRAIN_SURFACE_REGION> is lower in <<TERRAIN_ELEVATION>> than the
 *     adjacent <MOUNTAIN>s; a mountain pass.
 *
 * Group Membership: LAND_TRNSP, PHYSIOGRAPHY, TRNSP
 */
#define ECC_MOUNTAIN_PASS ((EDCS_Classification_Code)777)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION>, the physiography of which consists
 *     predominantly of <MOUNTAIN>s; a mountainous region.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_MOUNTAINOUS_REGION ((EDCS_Classification_Code)778)

/*
 * Definition:
 *     A <BOUNDARY> of a <TERRAIN_SURFACE_REGION> of mud that adjoins a
 *     <WATERBODY> and is covered and uncovered depending on the
 *     <<ELEVATION>> of the <TERRAIN> and the current <<ELEVATION>> of the
 *     <WATERBODY_SURFACE>; a mud line.
 *
 * Group Membership: DEMARCATION, LITTORAL, LOCATION
 */
#define ECC_MUD_LINE ((EDCS_Classification_Code)779)

/*
 * Definition:
 *     A <BUILDING> used as a <DWELLING> by multiple groups of occupants; a
 *     multi-unit dwelling.
 *
 * Group Membership: SHELTER
 */
#define ECC_MULTI_UNIT_DWELLING ((EDCS_Classification_Code)780)

/*
 * Definition:
 *     A <VEHICLE> capable of operation in more than one environmental
 *     domain; a multidomain vehicle.
 *
 * Group Membership: TRNSP, VEHICLE
 */
#define ECC_MULTIDOMAIN_VEHICLE ((EDCS_Classification_Code)781)

/*
 * Definition:
 *     A <BUILDING> that contains the offices of the public officials of a
 *     local political unit; a municipal hall.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_MUNICIPAL_HALL ((EDCS_Classification_Code)782)

/*
 * Definition:
 *     A <FACILITY> devoted to the provision of utility services (for
 *     example: electricity, telecommunications, gas, <WATER>, sewage, trash
 *     collection, and/or trash disposal) to the residents of a locally
 *     governed <REGION> or municipality.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_MUNICIPAL_UTILITY_FACILITY ((EDCS_Classification_Code)783)

/*
 * Definition:
 *     A <DEVICE> charged with: explosives; propellant; pyrotechnics;
 *     initiating composition; or nuclear, chemical, or biological
 *     <MATERIAL> for use in military operations (for example: demolitions);
 *     a munition.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, MILITARY_SCIENCE
 */
#define ECC_MUNITION ((EDCS_Classification_Code)784)

/*
 * Definition:
 *     A <BUILDING> devoted to the acquisition, conservation, study,
 *     exhibition, and educational interpretation of <OBJECT>s having
 *     scientific, historical, or artistic value; a museum [AHD, "museum"].
 *
 * Group Membership: RECREATION, SHELTER
 */
#define ECC_MUSEUM_BUILDING ((EDCS_Classification_Code)785)

/*
 * Definition:
 *     A <FACILITY> including one or more <MUSEUM_BUILDING>s.
 *
 * Group Membership: RECREATION, SHELTER, USAGE_REGION
 */
#define ECC_MUSEUM_FACILITY ((EDCS_Classification_Code)786)

/*
 * Definition:
 *     A <FUNGUS> of phylum Basidiomycota, the members of which have a
 *     fleshy, fruiting body, usually rounded or caplike, on a stalk growing
 *     from the ground; a mushroom [SOED, "mushroom"].
 *
 * Group Membership: LIVING_ORGANISM
 */
#define ECC_MUSHROOM ((EDCS_Classification_Code)787)

/*
 * Definition:
 *     A <TRACT> of natural scenery, defined by its geographical
 *     characteristics and known by its proper name.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_NAMED_LAND_TRACT ((EDCS_Classification_Code)788)

/*
 * Definition:
 *     A <LOCATION> that normally does not appear as a specific,
 *     characterized <OBJECT> on a <MAP> but has a name that is required to
 *     be placed on the <MAP>.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_NAMED_MAP_LOCATION ((EDCS_Classification_Code)789)

/*
 * Definition:
 *     An extensive <REGION> of a particular nature that has been defined by
 *     law and is to be protected as a whole; it meets the prerequisites of
 *     a <NATURE_RESERVE> for the largest part and has been influenced by
 *     <HUMAN>s at most only to a small extent; a national park.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, PHYSIOGRAPHY, PLANT, RECREATION, USAGE_REGION
 */
#define ECC_NATIONAL_PARK ((EDCS_Classification_Code)790)

/*
 * Definition:
 *     An existing <OBJECT> of fixed <<HEIGHT_AGL>> or natural growth at a
 *     fixed <LOCATION> within a proscribed <REGION> (for example: adjacent
 *     to an <AERODROME>) with reference to which vertical clearance is or
 *     must be provided during flight operations; a natural air obstruction.
 *
 * Group Membership: ABSTRACT_OBJECT, AIR_TRNSP, TRNSP
 */
#define ECC_NATURAL_AIR_OBSTRUCTION ((EDCS_Classification_Code)791)

/*
 * Definition:
 *     A <RIG> for the collection of natural gas from a <WELL>; a natural gas
 *     rig.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_NATURAL_GAS_RIG ((EDCS_Classification_Code)792)

/*
 * Definition:
 *     A <REGION> that has been legally defined and the nature and landscape
 *     of which require special protection, be it in part or as a whole, in
 *     order to preserve symbioses or biotypes of specific wildlife
 *     <NON_HUMAN_ANIMAL>s or <PLANT>s: for scientific reasons; for reasons
 *     of natural or geographic history; or because of their rareness,
 *     uniqueness, or outstanding beauty; a nature reserve.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, PHYSIOGRAPHY, PLANT, RECREATION, USAGE_REGION
 */
#define ECC_NATURE_RESERVE ((EDCS_Classification_Code)793)

/*
 * Definition:
 *     The <BUILDING>s, <GROUNDS>, and <DOCK>s of an organization that
 *     promotes and supports yachting, sailing, and boating; a nautical
 *     club, yacht club, or sailing club.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, RECREATION, SHELTER, USAGE_REGION
 */
#define ECC_NAUTICAL_CLUB ((EDCS_Classification_Code)794)

/*
 * Definition:
 *     A <WATERCOURSE> that is usable, sometimes after improvements, as a
 *     commercial <MARINE_ROUTE>; a navigable waterway.
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, HYDROLOGY, INDUSTRY, LOCATION, TRNSP
 */
#define ECC_NAVIGABLE_WATERWAY ((EDCS_Classification_Code)795)

/*
 * Definition:
 *     A <BUOY> serving as a <MARINE_AID_TO_NAVIGATION>; a navigation buoy.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_SURFACE
 */
#define ECC_NAVIGATION_BUOY ((EDCS_Classification_Code)796)

/*
 * Definition:
 *     Any visual or electronic <DEVICE>, usually located within a <VEHICLE>,
 *     that provides point-to-point guidance information or <LOCATION> data;
 *     a navigation device or navigation aid.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, LOCATION, TRNSP
 */
#define ECC_NAVIGATION_DEVICE ((EDCS_Classification_Code)797)

/*
 * Definition:
 *     A specially constructed <DEVICE> that displays a <LIGHT> as an
 *     <AID_TO_NAVIGATION>; a navigation light.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_NAVIGATION_LIGHT ((EDCS_Classification_Code)798)

/*
 * Definition:
 *     A <LINE> between two <AID_TO_NAVIGATION>s that extends towards the
 *     <REGION> of navigational interest; a navigation line.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_NAVIGATION_LINE ((EDCS_Classification_Code)799)

/*
 * Definition:
 *     A floating <STRUCTURE> providing a reference <LOCATION> for
 *     navigation; an afloat navigation mark.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_NAVIGATION_MARK_AFLOAT ((EDCS_Classification_Code)800)

/*
 * Definition:
 *     A fixed <STRUCTURE> providing a reference <LOCATION> for navigation; a
 *     fixed navigation mark.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_NAVIGATION_MARK_FIXED ((EDCS_Classification_Code)801)

/*
 * Definition:
 *     A <WATERBODY_REGION> within range of a <RADAR_STATION>; inside this
 *     <REGION> a <VESSEL> may request navigation radar assistance from
 *     <SHORE>, particularly in poor visibility.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_NAVIGATION_RADAR_RANGE ((EDCS_Classification_Code)802)

/*
 * Definition:
 *     A <REGION> in which certain aspects of navigation are restricted.
 *
 * Group Membership: TRNSP
 */
#define ECC_NAVIGATION_RESTRICTED_REGION ((EDCS_Classification_Code)803)

/*
 * Definition:
 *     The <TIDE>s of decreased range occurring near the times of the first
 *     and last quarter <<MOON_PHASE>>s.
 *
 * Group Membership: LITTORAL, WATERBODY_SURFACE
 */
#define ECC_NEAP_TIDE ((EDCS_Classification_Code)804)

/*
 * Definition:
 *     The <TERRAIN_STRIP> that is located between the 10 metre <DEPTH_CURVE>
 *     and the <LOW_WATER_LINE> defined by either mean low water springs or
 *     mean lower low water as defined by the applicable National Authority;
 *     nearshore precise.
 *
 * Group Membership: LITTORAL, PHYSIOGRAPHY
 */
#define ECC_NEARSHORE_PRECISE ((EDCS_Classification_Code)805)

/*
 * Definition:
 *     An immense body of highly rarefied gas and dust in the interstellar
 *     spaces of <GALAXY>s; a nebula.
 *
 * Group Membership: SPACE
 */
#define ECC_NEBULA ((EDCS_Classification_Code)806)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is normally eighth in distance
 *     from the <SUN>, with an orbital mean <<RADIUS>> of approximately 4
 *     504,4 million kilometres; Neptune.
 *
 * Group Membership: SPACE
 */
#define ECC_NEPTUNE ((EDCS_Classification_Code)807)

/*
 * Definition:
 *     A <SYSTEM> of inter-connected <OBJECT>s of either the same type or
 *     directly related types; a network.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_NETWORK ((EDCS_Classification_Code)808)

/*
 * Definition:
 *     A <BUILDING> used in the printing, collating, storage, or distribution
 *     of a newspaper; a newspaper plant.
 *
 * Group Membership: COMMUNICATION, INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_NEWSPAPER_PLANT ((EDCS_Classification_Code)809)

/*
 * Definition:
 *     An <AEROSOL> of non-aqueous <PARTICLE>s (for example: <SMOKE> and/or
 *     <DUST>); a non-aqueous cloud.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_NON_AQUEOUS_CLOUD ((EDCS_Classification_Code)810)

/*
 * Definition:
 *     A <TOWER> that is used for non-communication purposes (for example:
 *     observation, support, and/or storage).
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_NON_COMMUNICATION_TOWER ((EDCS_Classification_Code)811)

/*
 * Definition:
 *     A <SET> with at least one member; a non-empty set.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_NON_EMPTY_SET ((EDCS_Classification_Code)812)

/*
 * Definition:
 *     An <ANIMAL> other than a <HUMAN> [SOED, "animal", A.a].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_NON_HUMAN_ANIMAL ((EDCS_Classification_Code)813)

/*
 * Definition:
 *     Any <OBJECT> (for example: a <MARINE_WRECK>) on a <WATERBODY_FLOOR>
 *     that could be mistakenly identified as an operable
 *     <SUBMERSIBLE_VESSEL> when detected with acoustic or magnetic sensors;
 *     a non-submarine contact.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, WATERBODY_FLOOR
 */
#define ECC_NON_SUBMARINE_CONTACT ((EDCS_Classification_Code)814)

/*
 * Definition:
 *     <EQUIPMENT>, which may be contained within a <POWER_PLANT> or
 *     <VESSEL>, in which a nuclear chain reaction is initiated, sustained,
 *     and controlled; a nuclear reactor.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define ECC_NUCLEAR_REACTOR ((EDCS_Classification_Code)815)

/*
 * Definition:
 *     A <FACILITY> used for the construction, assembly, storage, or
 *     dismantling of nuclear <WEAPON>s.
 *
 * Group Membership: INDUSTRY, MILITARY_SCIENCE, USAGE_REGION
 */
#define ECC_NUCLEAR_WEAPONS_FACILITY ((EDCS_Classification_Code)816)

/*
 * Definition:
 *     A small, isolated, fertile, or green <TRACT> in a <DESERT_REGION>
 *     usually having a <WATERING_PLACE>; an oasis.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_OASIS ((EDCS_Classification_Code)817)

/*
 * Definition:
 *     A person, place, thing, or concept; an object.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_OBJECT ((EDCS_Classification_Code)818)

/*
 * Definition:
 *     A <PROPERTY_SET> describing an <OBJECT>.
 *
 * Group Membership: PROPERTY_SET
 */
#define ECC_OBJECT_PROPERTY_SET ((EDCS_Classification_Code)819)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <OBJECT>s.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_OBJECT_SET ((EDCS_Classification_Code)820)

/*
 * Definition:
 *     A station that is equipped for observation and study.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_OBSERVATION_STATION ((EDCS_Classification_Code)821)

/*
 * Definition:
 *     An <OBSERVATION_STATION> designed and equipped for making observations
 *     of astronomical, meteorological, or other natural phenomena; an
 *     observatory [SOED, "observatory", 1].
 *
 * Group Membership: ATMOSPHERE, SPACE
 */
#define ECC_OBSERVATORY ((EDCS_Classification_Code)822)

/*
 * Definition:
 *     A composite of two <ATMOSPHERIC_FRONT>s formed as a <COLD_FRONT>
 *     overtakes a <WARM_FRONT> or a <STATIONARY_FRONT>; an occluded front.
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, LOCATION, TEMPERATURE
 */
#define ECC_OCCLUDED_FRONT ((EDCS_Classification_Code)823)

/*
 * Definition:
 *     A <REGION> temporarily held and controlled by a hostile military
 *     force; an occupation zone.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_OCCUPATION_ZONE ((EDCS_Classification_Code)824)

/*
 * Definition:
 *     One of the major divisions of an expanse of salt <WATER> covering a
 *     <PLANETARY_SURFACE>; an ocean.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_OCEAN ((EDCS_Classification_Code)825)

/*
 * Definition:
 *     A <TERRAIN_DEPRESSION> of an <OCEAN_FLOOR> approximately
 *     equidimensional in plan view and of variable extent; a basin.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_OCEAN_BASIN ((EDCS_Classification_Code)826)

/*
 * Definition:
 *     The <WATERBODY_FLOOR> of an <OCEAN>.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_OCEAN_FLOOR ((EDCS_Classification_Code)827)

/*
 * Definition:
 *     The <DIRECTION> and distance from an <AID_TO_NAVIGATION> to a defined
 *     <WAYPOINT>; an off route bearing.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_OFF_ROUTE_BEARING ((EDCS_Classification_Code)828)

/*
 * Definition:
 *     A <FACILITY> located in a <WATERBODY> for loading and unloading
 *     <CARGO>; an offshore loading facility.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_OFFSHORE_LOADING_FACILITY ((EDCS_Classification_Code)829)

/*
 * Definition:
 *     A <STRUCTURE> placed in a <WATERBODY> and used: for production,
 *     loading, and discharge; as an <OBSERVATION_STATION>; or as a
 *     <SCIENCE_FACILITY>; an offshore platform.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_INDUSTRY
 */
#define ECC_OFFSHORE_PLATFORM ((EDCS_Classification_Code)830)

/*
 * Definition:
 *     A floating <BARRIER> to stop and contain oil flow on a
 *     <WATERBODY_SURFACE>; an oil barrier.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, WATERBODY_SURFACE
 */
#define ECC_OIL_BARRIER ((EDCS_Classification_Code)831)

/*
 * Definition:
 *     A <RIG> assembled primarily for the purpose of drilling an oil <WELL>;
 *     an oil drilling rig.
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE
 */
#define ECC_OIL_DRILLING_RIG ((EDCS_Classification_Code)832)

/*
 * Definition:
 *     An open air bath.
 *
 * Group Membership: RECREATION
 */
#define ECC_OPEN_AIR_BATH ((EDCS_Classification_Code)833)

/*
 * Definition:
 *     A <WATERBODY_REGION> where the <WATER> is flowing or free standing;
 *     open water.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_OPEN_WATER ((EDCS_Classification_Code)834)

/*
 * Definition:
 *     A <BUILDING> that houses a <THEATRE> designed chiefly for the
 *     performance of operas.
 *
 * Group Membership: RECREATION, SHELTER
 */
#define ECC_OPERA_HOUSE ((EDCS_Classification_Code)835)

/*
 * Definition:
 *     A <TREED_TRACT> devoted to the cultivation of fruit or nut <TREE>s; an
 *     orchard [AHD, "orchard", 1].
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_ORCHARD ((EDCS_Classification_Code)836)

/*
 * Definition:
 *     An <INDUSTRIAL_WORKS> for purifying ores (for example: copper and/or
 *     silver) and extracting from them various metal and chemical products;
 *     an ore refinery.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, USAGE_REGION
 */
#define ECC_ORE_REFINERY ((EDCS_Classification_Code)837)

/*
 * Definition:
 *     A small <BUILDING> that is separate from but is located near a main
 *     <BUILDING>; an outbuilding.
 *
 * Group Membership: SHELTER
 */
#define ECC_OUTBUILDING ((EDCS_Classification_Code)838)

/*
 * Definition:
 *     A <WATERBODY_REGION> where short, breaking <WATER_WAVE>s are formed on
 *     the <WATERBODY_SURFACE> when a strong <WATER_CURRENT> passes over a
 *     <SHOAL> or other submarine obstruction or meets a contrary
 *     <WATER_CURRENT> or <WIND>; an overfall region.
 *
 * Group Membership: HYDROLOGY, WATERBODY_SURFACE
 */
#define ECC_OVERFALL_REGION ((EDCS_Classification_Code)839)

/*
 * Definition:
 *     An overhead obstruction (for example: an underpass, an overhead
 *     <PIPELINE>, and/or the overhang of a <BUILDING>) on a
 *     <TRANSPORTATION_ROUTE>.
 *
 * Group Membership: TRNSP
 */
#define ECC_OVERHEAD_OBSTRUCTION ((EDCS_Classification_Code)840)

/*
 * Definition:
 *     A <BRIDGE> used to provide clearance to traffic on a
 *     <LAND_TRANSPORTATION_ROUTE> at a lower elevation; an overpass.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_OVERPASS ((EDCS_Classification_Code)841)

/*
 * Definition:
 *     A <REGION> of <ICE> on a <WATERBODY> formed by the drifting and
 *     crushing together of floating floes; the movement of individual floes
 *     is greatly restricted as the pack moves as a single unit.
 *
 * Group Membership: ICE
 */
#define ECC_PACK_ICE ((EDCS_Classification_Code)842)

/*
 * Definition:
 *     A <HINDU_TEMPLE>, <BUDDHIST_TEMPLE>, and/or sacred <BUILDING>, usually
 *     in the form of a many-tiered <TOWER> with <FLOOR_LEVEL>s of
 *     diminishing size, each with an ornamented projecting <ROOF>; a pagoda
 *     [SOED, "pagoda", 1].
 *
 * Group Membership: RELIGION, SHELTER
 */
#define ECC_PAGODA ((EDCS_Classification_Code)843)

/*
 * Definition:
 *     A <BUILDING> serving, or that has previously served, as the official
 *     residence of a royal personage or high dignitary in a religious
 *     establishment or government; a palace [SOED, "palace", 1].
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_PALACE ((EDCS_Classification_Code)844)

/*
 * Definition:
 *     A <PALACE> and one or more associated <BUILDING>s; a palace complex.
 *
 * Group Membership: ADMINISTRATION, SHELTER, USAGE_REGION
 */
#define ECC_PALACE_COMPLEX ((EDCS_Classification_Code)845)

/*
 * Definition:
 *     A <FACILITY> for processing natural fibres (for example: wood) into
 *     flexible sheets or rolls of paper by deposit from an aqueous
 *     suspension; a paper-mill.
 *
 * Group Membership: INDUSTRY, USAGE_REGION
 */
#define ECC_PAPER_MILL ((EDCS_Classification_Code)846)

/*
 * Definition:
 *     An <EMBANKMENT>, especially one on top of a <WALL> or <RAMPART> or in
 *     front of a <MILITARY_TRENCH>, that is built to provide protection
 *     from an enemy's observation and fire, to protect <EQUIPMENT>, to
 *     stabilize an adjacent <STRUCTURE>, or to serve as a
 *     <TERRAIN_OBSTACLE>; a parapet [SOED, "parapet", 1.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, PHYSIOGRAPHY, SHELTER, TRNSP
 */
#define ECC_PARAPET ((EDCS_Classification_Code)847)

/*
 * Definition:
 *     An administrative subdivision of a <TRACT>; a parcel [SOED, "parcel",
 *     3.a].
 *
 * Group Membership: ADMINISTRATION
 */
#define ECC_PARCEL ((EDCS_Classification_Code)848)

/*
 * Definition:
 *     A <REGION> of a <PLANETARY_SURFACE> used for recreational or
 *     ornamental purposes; a park.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_PARK ((EDCS_Classification_Code)849)

/*
 * Definition:
 *     A <BUILDING> or indoor space used to park or keep <MOTOR_VEHICLE>s; a
 *     parking garage.
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_PARKING_GARAGE ((EDCS_Classification_Code)850)

/*
 * Definition:
 *     A minute portion of <MATERIAL>; a particle [SOED, "particle", 2].
 *
 * Group Membership: MATERIAL
 */
#define ECC_PARTICLE ((EDCS_Classification_Code)851)

/*
 * Definition:
 *     A <DEVICE> for imparting high velocities to charged <PARTICLE>s; a
 *     particle accelerator.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, EM_PHENOMENON
 */
#define ECC_PARTICLE_ACCELERATOR ((EDCS_Classification_Code)852)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> under 100 tonnes in displacement and equipped
 *     for patrol duties on relatively sheltered <WATERBODY_SURFACE_REGION>s
 *     (for example: <HARBOUR>s and/or <RIVER>s); a patrol craft.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_PATROL_CRAFT ((EDCS_Classification_Code)853)

/*
 * Definition:
 *     A <PIPELINE> or channel generally used by hydroelectric <POWER_PLANT>s
 *     or water mills to transport <WATER> by gravity or under pressure; a
 *     penstock.
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE
 */
#define ECC_PENSTOCK ((EDCS_Classification_Code)854)

/*
 * Definition:
 *     A layer of <SOIL> or <BEDROCK> at a variable depth beneath the
 *     <SURFACE> of the <LAND> in which the <<TEMPERATURE>> has been below
 *     freezing continuously from a few to thousands of years; permafrost.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL, TEMPERATURE
 */
#define ECC_PERMAFROST ((EDCS_Classification_Code)855)

/*
 * Definition:
 *     A permanent <SNOWFIELD>.
 *
 * Group Membership: ICE, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_PERMANENT_SNOWFIELD ((EDCS_Classification_Code)856)

/*
 * Definition:
 *     The <NON_EMPTY_SET> of <HUMAN>s employed by an organization or engaged
 *     in a service; personnel [SOED, "personnel", 1.a].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_PERSONNEL ((EDCS_Classification_Code)857)

/*
 * Definition:
 *     A dark viscous liquid consisting chiefly of hydrocarbons that is
 *     sometimes present in <ROCK> and is refined for use (for example: as a
 *     fuel and/or as a source material for manufacturing); petroleum [SOED,
 *     "petroleum", 1.a].
 *
 * Group Membership: MATERIAL
 */
#define ECC_PETROLEUM ((EDCS_Classification_Code)858)

/*
 * Definition:
 *     A <BUILDING> involved in the production or distribution of <PETROLEUM>.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, INFRASTRUCTURE, SHELTER
 */
#define ECC_PETROLEUM_BUILDING ((EDCS_Classification_Code)859)

/*
 * Definition:
 *     A <FACILITY> including one or more <PETROLEUM_BUILDING>s.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, INFRASTRUCTURE, SHELTER, USAGE_REGION
 */
#define ECC_PETROLEUM_FACILITY ((EDCS_Classification_Code)860)

/*
 * Definition:
 *     A <TRACT> where <PETROLEUM> is pumped or otherwise removed from the
 *     ground; a petroleum field.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_PETROLEUM_FIELD ((EDCS_Classification_Code)861)

/*
 * Definition:
 *     An <INDUSTRIAL_WORKS> for refining and purifying <PETROLEUM>; a
 *     petroleum refinery.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_PETROLEUM_REFINERY ((EDCS_Classification_Code)862)

/*
 * Definition:
 *     A <FACILITY> devoted to the storage of <PETROLEUM> through the use of
 *     a collection of, generally above ground, <STORAGE_TANK>s; a petroleum
 *     tank farm [SOED, "tank farm"].
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_PETROLEUM_TANK_FARM ((EDCS_Classification_Code)863)

/*
 * Definition:
 *     A phosphorescent <WATERBODY_REGION>.
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define ECC_PHOSPHORESCENT_REGION ((EDCS_Classification_Code)864)

/*
 * Definition:
 *     A <TRACT> that has picnic tables for public use.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_PICNIC_TRACT ((EDCS_Classification_Code)865)

/*
 * Definition:
 *     A long, narrow <STRUCTURE> extending into a <WATERBODY> to afford a
 *     berthing place for <VESSEL>s or to serve as a promenade; a pier.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, RECREATION, TRNSP
 */
#define ECC_PIER ((EDCS_Classification_Code)866)

/*
 * Definition:
 *     A cone or dome shaped mound or <HILL> of peat or <SOIL>, usually with
 *     a core of <ICE>, that is found in <TUNDRA> and is produced by the
 *     pressure of <WATER> or <ICE> accumulating underground and pushing
 *     upward; a pingo.
 *
 * Group Membership: ICE, PHYSIOGRAPHY
 */
#define ECC_PINGO ((EDCS_Classification_Code)867)

/*
 * Definition:
 *     A hollow cylinder or tube of metal, plastic, or other <MATERIAL> that
 *     is used for the conveyance of slurries, liquids, or gases; a pipe
 *     [SOED, "pipe", 3.a].
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_PIPE ((EDCS_Classification_Code)868)

/*
 * Definition:
 *     A <NON_EMPTY_SET> or connected <SET> of <PIPE>s for conveying liquids,
 *     slurries, or gases for long distances, often underground; a pipeline.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_PIPELINE ((EDCS_Classification_Code)869)

/*
 * Definition:
 *     The apparent end of a <PIPELINE> located above the <TERRAIN> where it
 *     enters the <TERRAIN>; a pipeline terminus. This apparent end often
 *     occurs at a pumping or industrial <FACILITY> or where the <PIPELINE>
 *     crosses under a <LAND_TRANSPORTATION_ROUTE>.
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE
 */
#define ECC_PIPELINE_TERMINUS ((EDCS_Classification_Code)870)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <PIPE>s and associated pumps used to transfer
 *     slurries, liquids, or gases from one <LOCATION> to another; a piping
 *     complex.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_PIPING_COMPLEX ((EDCS_Classification_Code)871)

/*
 * Definition:
 *     A <CELESTIAL_BODY> revolving in an elliptical orbit around a <STAR>; a
 *     planet [AHD, "planet", 1].
 *
 * Group Membership: SPACE
 */
#define ECC_PLANET ((EDCS_Classification_Code)872)

/*
 * Definition:
 *     Either of the two <LOCATION>s on a <PLANETARY_SURFACE> where, given
 *     the presence of a planetary <MAGNETIC_FIELD>, the magnetic dip is 90
 *     arc degrees (locally vertical); a planetary magnetic pole.
 *
 * Group Membership: EM_PHENOMENON, LOCATION
 */
#define ECC_PLANETARY_MAGNETIC_POLE ((EDCS_Classification_Code)873)

/*
 * Definition:
 *     Either of the two <LOCATION>s where the axis of rotation of a <PLANET>
 *     intersects the <PLANETARY_SURFACE>; a planetary pole.
 *
 * Group Membership: LOCATION
 */
#define ECC_PLANETARY_POLE ((EDCS_Classification_Code)874)

/*
 * Definition:
 *     The <SURFACE> of a <PLANET>, specifically the <SURFACE> of the <LAND>
 *     and/or <WATERBODY>s.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_PLANETARY_SURFACE ((EDCS_Classification_Code)875)

/*
 * Definition:
 *     Zooplankton or phytoplankton that is passively floating or drifting in
 *     a <WATERBODY>; plankton [MWCD, "plankton"].
 *
 * Group Membership: LIVING_ORGANISM
 */
#define ECC_PLANKTON ((EDCS_Classification_Code)876)

/*
 * Definition:
 *     An enormous concentration of <PLANKTON> in a <WATERBODY>, caused
 *     either by an explosive or a gradual multiplication and usually
 *     producing an obvious change in the physical appearance of the
 *     <WATERBODY_SURFACE_REGION>, such as discolouration; a plankton bloom.
 *
 * Group Membership: LIVING_ORGANISM, WATERBODY_SURFACE
 */
#define ECC_PLANKTON_BLOOM ((EDCS_Classification_Code)877)

/*
 * Definition:
 *     A <LIVING_ORGANISM> of the kingdom Plantae, the members of which
 *     typically are fixed to a substrate, able to subsist wholly on
 *     inorganic substances, and move chiefly by growth; a plant [SOED,
 *     "plant", 2].
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_PLANT ((EDCS_Classification_Code)878)

/*
 * Definition:
 *     A <FACILITY> where <PLANT>s are grown for transplanting, seed, or
 *     grafting; a plant nursery.
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_PLANT_NURSERY ((EDCS_Classification_Code)879)

/*
 * Definition:
 *     An estate where cash crops are grown on a large scale, especially in
 *     tropical <REGION>s; a plantation [SOED, "plantation", 5].
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT
 */
#define ECC_PLANTATION ((EDCS_Classification_Code)880)

/*
 * Definition:
 *     An elevated <TERRAIN_SURFACE_REGION> that is comparatively flat-topped
 *     and of considerable extent; a plateau.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_PLATEAU ((EDCS_Classification_Code)881)

/*
 * Definition:
 *     An identifiable stream of <AIR> with an <<AIR_TEMPERATURE>> or
 *     composition different from that of its environment; a plume. EXAMPLE
 *     <SMOKE> from a <CHIMNEY>.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE, TEMPERATURE
 */
#define ECC_PLUME ((EDCS_Classification_Code)882)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is normally ninth in distance
 *     from the <SUN>, travelling in a highly eccentric orbit with an
 *     orbital mean <<RADIUS>> of approximately 5 915,8 million kilometres;
 *     Pluto.
 *
 * Group Membership: SPACE
 */
#define ECC_PLUTO ((EDCS_Classification_Code)883)

/*
 * Definition:
 *     A <SET> of two or more seals or <WHALE>s closely clustered together; a
 *     pod.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_POD ((EDCS_Classification_Code)884)

/*
 * Definition:
 *     The <LOCATION> on a <LINE> that is nearest to and abeam of another
 *     <LOCATION> that is not on the <LINE>; point abeam. EXAMPLE A
 *     <LOCATION> on the centre-line of a <RUNWAY> is abeam a glide slope
 *     <AERIAL> when the distance from the centre-line of the <RUNWAY> to
 *     the glide slope <AERIAL> is at a minimum.
 *
 * Group Membership: LOCATION
 */
#define ECC_POINT_ABEAM ((EDCS_Classification_Code)885)

/*
 * Definition:
 *     A <REGION> of <ICE> or other frozen <MATERIAL> surrounding a
 *     <PLANETARY_POLE>; a polar cap [SOED, "polar cap"].
 *
 * Group Membership: ICE, PHYSIOGRAPHY
 */
#define ECC_POLAR_CAP ((EDCS_Classification_Code)886)

/*
 * Definition:
 *     <ICE> that is a permanent feature of <PLANETARY_POLE>s; polar ice.
 *
 * Group Membership: ICE
 */
#define ECC_POLAR_ICE ((EDCS_Classification_Code)887)

/*
 * Definition:
 *     A long, slender, more or less cylindrical piece of <MATERIAL> (for
 *     example: wood or metal) used as a support (for example: to hold up a
 *     <TENT>, for <VEGETATION> to climb on, for supporting an
 *     <ELEVATED_ELECTRICAL_CABLE>, and/or for holding up scaffolding); a
 *     pole [SOED, "pole", 1.a].
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_POLE ((EDCS_Classification_Code)888)

/*
 * Definition:
 *     A <PUBLIC_SERVICE_STATION> that serves as the headquarters of a unit
 *     of a police force and that is where those under arrest are first
 *     charged; a police station.
 *
 * Group Membership: ADMINISTRATION
 */
#define ECC_POLICE_STATION ((EDCS_Classification_Code)889)

/*
 * Definition:
 *     A polygon used to model some aspect of an <OBJECT>; a polygonal face.
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define ECC_POLYGONAL_FACE ((EDCS_Classification_Code)890)

/*
 * Definition:
 *     A large <REGION> of <OPEN_WATER> that is surrounded by floating <ICE>;
 *     a polynya [SOED, "polynya"].
 *
 * Group Membership: HYDROLOGY, ICE
 */
#define ECC_POLYNYA ((EDCS_Classification_Code)891)

/*
 * Definition:
 *     A broad, flat-bottomed <STRUCTURE> that is rectangular in shape,
 *     resembles a barge, and is designed to float on a <WATERBODY_SURFACE>;
 *     a pontoon.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT
 */
#define ECC_PONTOON ((EDCS_Classification_Code)892)

/*
 * Definition:
 *     A small to moderate sized member of the order Cetacea, suborder
 *     Odontoceti, family Phocaenidae; a porpoise.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_PORPOISE ((EDCS_Classification_Code)893)

/*
 * Definition:
 *     A <PUBLIC_SERVICE_STATION> where postal business (for example: where
 *     mail is handled and/or where stamps and other postal materials are
 *     sold) may be carried on; a post office.
 *
 * Group Membership: COMMUNICATION, INFRASTRUCTURE
 */
#define ECC_POST_OFFICE ((EDCS_Classification_Code)894)

/*
 * Definition:
 *     A <TRACT> with a high potential of slipping down from an elevated
 *     <LOCATION> (for example: a <CLIFF> and/or the side of a <MOUNTAIN>);
 *     a potential landslide region.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_POTENTIAL_LANDSLIDE_REGION ((EDCS_Classification_Code)895)

/*
 * Definition:
 *     A <BUILDING> and associated <EQUIPMENT> used for the generation of
 *     electric power; a power generation building.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, SHELTER
 */
#define ECC_POWER_GENERATION_BUILDING ((EDCS_Classification_Code)896)

/*
 * Definition:
 *     A <FACILITY> including one or more <POWER_GENERATION_BUILDING>s; a
 *     power plant.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, SHELTER, USAGE_REGION
 */
#define ECC_POWER_PLANT ((EDCS_Classification_Code)897)

/*
 * Definition:
 *     A <FACILITY>, along a <POWER_TRANSMISSION_LINE>, in which electric
 *     current is transformed and/or distributed; a power substation or
 *     transformer yard.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_POWER_SUBSTATION ((EDCS_Classification_Code)898)

/*
 * Definition:
 *     A <SYSTEM> of <ELEVATED_ELECTRICAL_CABLE>s and associated
 *     <POWER_TRANSMISSION_LINE_PYLON>s that transmit electrical power; a
 *     power transmission line.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_POWER_TRANSMISSION_LINE ((EDCS_Classification_Code)899)

/*
 * Definition:
 *     A <PYLON> or <POLE> used to support a <POWER_TRANSMISSION_LINE>.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, SUPPORT_STRUCTURE
 */
#define ECC_POWER_TRANSMISSION_LINE_PYLON ((EDCS_Classification_Code)900)

/*
 * Definition:
 *     The terminus of a <POWER_TRANSMISSION_LINE> at a <POWER_PLANT>,
 *     <POWER_SUBSTATION>, transformer, or receiving <FACILITY>.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_POWER_TRANSMISSION_LINE_TERMINUS ((EDCS_Classification_Code)901)

/*
 * Definition:
 *     Aqueous <PARTICLE>s in liquid phase or solid phase that originate in
 *     the <ATMOSPHERE> and fall to the <PLANETARY_SURFACE> of the <EARTH>;
 *     precipitation.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_PRECIPITATION ((EDCS_Classification_Code)902)

/*
 * Definition:
 *     A <REGION> where <PRECIPITATION> is occurring.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_PRECIPITATION_REGION ((EDCS_Classification_Code)903)

/*
 * Definition:
 *     A <FACILITY> used for precollegiate instruction (generally of
 *     children); a precollegiate campus.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_PRECOLLEGIATE_CAMPUS ((EDCS_Classification_Code)904)

/*
 * Definition:
 *     A <SITE> containing one or more prepared <DEFENSIVE_POSITION>s.
 *
 * Group Membership: MILITARY_SCIENCE, USAGE_REGION
 */
#define ECC_PREPARED_DEFENSIVE_POSITION_SITE ((EDCS_Classification_Code)905)

/*
 * Definition:
 *     A <TRACT> containing military <STRUCTURE>s resistant to <MUNITION>s
 *     (for example: a bastion, a <RAMPART>, a <FORTIFICATION>, a
 *     <DEFENSIVE_POSITION>, an <INFANTRY_TRENCH>, and/or a <BUNKER>); a
 *     prepared defensive tract.
 *
 * Group Membership: MILITARY_SCIENCE, USAGE_REGION
 */
#define ECC_PREPARED_DEFENSIVE_TRACT ((EDCS_Classification_Code)906)

/*
 * Definition:
 *     A <LOCATION> on a <WATERCOURSE> that has <RAMP>s, <STRUCTURAL_PILE>s,
 *     and/or <PIER>s constructed on one or both <SHORE>s to allow for
 *     suitable future crossing operations using floating <BRIDGE>s or
 *     rafting <EQUIPMENT>; a prepared watercourse crossing.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LAND_TRNSP, TRNSP
 */
#define ECC_PREPARED_WATERCOURSE_CROSSING ((EDCS_Classification_Code)907)

/*
 * Definition:
 *     <ICE> located in a <SEA>, <RIVER>, or <LAKE> that has been deformed or
 *     altered by the lateral stresses of any combination of <WIND>,
 *     <TIDE>s, <WATER_WAVE>s, and <SURF>; pressure ice.
 *
 * Group Membership: ICE, MATERIAL, WATERBODY_SURFACE
 */
#define ECC_PRESSURE_ICE ((EDCS_Classification_Code)908)

/*
 * Definition:
 *     A <WATERBODY_CURRENT> most frequently observed during a given
 *     observation period, usually a month, season, or year; a prevailing
 *     current.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_PREVAILING_CURRENT ((EDCS_Classification_Code)909)

/*
 * Definition:
 *     A <DETENTION_FACILITY> where long (usually more than one year)
 *     sentences for criminal misconduct can be served; a prison.
 *
 * Group Membership: ADMINISTRATION
 */
#define ECC_PRISON ((EDCS_Classification_Code)910)

/*
 * Definition:
 *     A <BUILDING> that is used for the changing or refining of a particular
 *     <MATERIAL>; a processing or treatment building.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_PROCESSING_BUILDING ((EDCS_Classification_Code)911)

/*
 * Definition:
 *     A <FACILITY> including one or more <PROCESSING_BUILDING>s; a
 *     processing facility.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER, USAGE_REGION
 */
#define ECC_PROCESSING_FACILITY ((EDCS_Classification_Code)912)

/*
 * Definition:
 *     A <REGION>, usually on a <MILITARY_INSTALLATION>, where entrance or
 *     presence of unauthorized <PERSONNEL> is prohibited, typically due to
 *     the presence of unexploded <MUNITION>s, <EXPLOSIVE_MINE>s, or
 *     sensitive environmental habitats; a prohibited region.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_PROHIBITED_REGION ((EDCS_Classification_Code)913)

/*
 * Definition:
 *     A high point of <LAND> extending into a <WATERBODY>; a promontory.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_PROMONTORY ((EDCS_Classification_Code)914)

/*
 * Definition:
 *     A <SET> of EDCS Attributes and/or functional relationships between
 *     EDCS Attributes that are applicable to an <OBJECT>, <LOCATION>,
 *     and/or <REGION>; a property set.
 *
 * Group Membership: PROPERTY_SET
 */
#define ECC_PROPERTY_SET ((EDCS_Classification_Code)915)

/*
 * Definition:
 *     A <SHELTER> built to protect a section of <ROAD> or <RAILWAY> from
 *     slides of <SNOW_GROUND_COVER> and/or <ROCK>; a protection shed.
 *
 * Group Membership: ICE, LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_PROTECTION_SHED ((EDCS_Classification_Code)916)

/*
 * Definition:
 *     A <LIVING_ORGANISM> of the kingdom Protista, the members of which are
 *     simple organisms that are between, or distinct from, <ANIMAL>s and
 *     <PLANT>s, especially a unicellular eukaryote; a protist [SOED,
 *     "protist"]. EXAMPLES Protozoan, single-celled <ALGA>.
 *
 * Group Membership: LIVING_ORGANISM
 */
#define ECC_PROTIST ((EDCS_Classification_Code)917)

/*
 * Definition:
 *     A <PLANT> of the group Pteridophyta; a pteridophyte [SOED,
 *     "pteridophyte"]. EXAMPLES <FERN>, horsetail, clubmoss.
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_PTERIDOPHYTE ((EDCS_Classification_Code)918)

/*
 * Definition:
 *     A <RESTAURANT> where lodging may be available; a public inn.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER, USAGE_REGION
 */
#define ECC_PUBLIC_INN ((EDCS_Classification_Code)919)

/*
 * Definition:
 *     A station that houses public services and from which operations are
 *     directed or services provided.
 *
 * Group Membership: ADMINISTRATION, INFRASTRUCTURE
 */
#define ECC_PUBLIC_SERVICE_STATION ((EDCS_Classification_Code)920)

/*
 * Definition:
 *     An open <SITE> that serves as a public meeting <LOCATION> in a <CITY>
 *     or <TOWN>; a plaza or public square.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_PUBLIC_SQUARE ((EDCS_Classification_Code)921)

/*
 * Definition:
 *     A small, identifiable quantity of <AIR> with a composition different
 *     from that of its environment emitted in one light, abrupt blast; a
 *     puff. EXAMPLE The initial <NON_AQUEOUS_CLOUD> of <SMOKE> from an
 *     explosion.
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_PUFF ((EDCS_Classification_Code)922)

/*
 * Definition:
 *     A raised <STRUCTURE> consisting of an enclosed platform from which the
 *     preacher in a <CHURCH> or <CHAPEL> delivers the sermon; a pulpit
 *     [SOED, "pulpit", 2.a].
 *
 * Group Membership: RELIGION
 */
#define ECC_PULPIT ((EDCS_Classification_Code)923)

/*
 * Definition:
 *     A <FACILITY> with <EQUIPMENT> to pump out waste liquids from
 *     <VEHICLE>s; a pump out facility.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_PUMP_OUT_FACILITY ((EDCS_Classification_Code)924)

/*
 * Definition:
 *     A <BUILDING> or <ROOM> housing pumps for raising, compressing, or
 *     transferring fluids; a pump room or pump house (US).
 *
 * Group Membership: BUILDING_COMPONENT, INFRASTRUCTURE, SHELTER
 */
#define ECC_PUMP_ROOM ((EDCS_Classification_Code)925)

/*
 * Definition:
 *     A <FACILITY> to move slurries, liquids, or gases by means of pressure
 *     or suction; a pumping station.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_PUMPING_STATION ((EDCS_Classification_Code)926)

/*
 * Definition:
 *     A tall <STRUCTURE> erected as a support; a pylon [SOED, "pylon", 4.a].
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_PYLON ((EDCS_Classification_Code)927)

/*
 * Definition:
 *     An <EXCAVATION> created by removal of <ROCK> by blasting or cutting; a
 *     quarry.
 *
 * Group Membership: INDUSTRY, PHYSIOGRAPHY, USAGE_REGION
 */
#define ECC_QUARRY ((EDCS_Classification_Code)928)

/*
 * Definition:
 *     A course for racing (for example: racing <NON_HUMAN_ANIMAL>s and/or
 *     racing <MOTOR_VEHICLE>s); a racetrack.
 *
 * Group Membership: RECREATION
 */
#define ECC_RACE_TRACK ((EDCS_Classification_Code)929)

/*
 * Definition:
 *     A <DEVICE> used for the reception or transmission of radar signals.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON
 */
#define ECC_RADAR_DEVICE ((EDCS_Classification_Code)930)

/*
 * Definition:
 *     A <LINE> shown on a marine <MAP> corresponding to the <LINE>s seen on
 *     radar displays of <HARBOUR>s; a radar line.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, SURVEY, TRNSP
 */
#define ECC_RADAR_LINE ((EDCS_Classification_Code)931)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the radar properties of the <MATERIAL>s
 *     composing an <OBJECT>.
 *
 * Group Membership: EM_PHENOMENON, MATERIAL, PROPERTY_SET
 */
#define ECC_RADAR_MATERIAL_PROPERTY_SET ((EDCS_Classification_Code)932)

/*
 * Definition:
 *     A <DEVICE> used for the reception of radar signals; a radar receiver.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, EM_PHENOMENON
 */
#define ECC_RADAR_RECEIVER ((EDCS_Classification_Code)933)

/*
 * Definition:
 *     A <LINE> along which <VESSEL>s are guided by a traffic control centre
 *     located in a <RADAR_STATION>; a radar reference line. This <LINE> is
 *     shown on a marine <MAP> in proximity to a <MARINE_ROUTE>.
 *
 * Group Membership: COMMUNICATION, HYDROGRAPHIC_TRNSP, LOCATION, SURVEY, TRNSP
 */
#define ECC_RADAR_REFERENCE_LINE ((EDCS_Classification_Code)934)

/*
 * Definition:
 *     A <RADAR_DEVICE> and support <STRUCTURE>s; a radar station.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON
 */
#define ECC_RADAR_STATION ((EDCS_Classification_Code)935)

/*
 * Definition:
 *     A <DEVICE> used for the transmission of radar signals; a radar
 *     transmitter.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON
 */
#define ECC_RADAR_TRANSMITTER ((EDCS_Classification_Code)936)

/*
 * Definition:
 *     A <REGION> in which a radiologic substance is present that can kill,
 *     seriously injure, or incapacitate a <HUMAN> and/or <ANIMAL> through
 *     its physiological properties. The radiologic substance is usually
 *     dispersed over a <SURFACE> and/or within the <ATMOSPHERE>.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON, SURFACE_MATERIAL, SURFACE
 */
#define ECC_RADIOLOGIC_HAZARD_REGION ((EDCS_Classification_Code)937)

/*
 * Definition:
 *     A <LOCATION> that is the furthest point reached by a <RAILWAY> where
 *     <EQUIPMENT> and/or <MATERIAL>s are loaded onto or unloaded from
 *     <RAIL_WAGON>s; a rail-head [SOED, "rail-head", 1] or rail terminus.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAIL_HEAD ((EDCS_Classification_Code)938)

/*
 * Definition:
 *     A <LOCATION> where <EQUIPMENT> and/or <MATERIAL>s may be loaded onto
 *     or unloaded from a <RAIL_WAGON>; a rail transfer point.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAIL_TRANSFER_POINT ((EDCS_Classification_Code)939)

/*
 * Definition:
 *     A <GROUND_VEHICLE> that is usually not self-propelled and that travels
 *     on a <RAILWAY_TRACK>; a rail wagon or a railroad car (US).
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_RAIL_WAGON ((EDCS_Classification_Code)940)

/*
 * Definition:
 *     A <LAND_TRANSPORTATION_ROUTE> consisting of one or more
 *     <RAILWAY_TRACK>s; a railway, or a railroad (US).
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY ((EDCS_Classification_Code)941)

/*
 * Definition:
 *     A representation of one or more <RAILWAY>s, especially in a
 *     <BUILT_UP_REGION>; a railway centre-line or railway nexus.
 *
 * Group Membership: LAND_TRNSP, LOCATION, TRNSP
 */
#define ECC_RAILWAY_NEXUS ((EDCS_Classification_Code)942)

/*
 * Definition:
 *     A stretch of <RAILWAY_TRACK> connected to a main <RAILWAY> and used
 *     for temporary storage, loading, and/or unloading; a railway sidetrack.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_SIDETRACK ((EDCS_Classification_Code)943)

/*
 * Definition:
 *     A short stretch of <RAILWAY_TRACK> connected at both ends to a main
 *     <RAILWAY> and used to store <RAIL_WAGON>s or enable <TRAIN>s on the
 *     same line to pass; a railway siding [SOED, "siding", II.7.a].
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_SIDING ((EDCS_Classification_Code)944)

/*
 * Definition:
 *     Automated <EQUIPMENT> from which signals are sent to control the
 *     movements of <TRAIN>s; a signal box or signal tower.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_SIGNAL_BOX ((EDCS_Classification_Code)945)

/*
 * Definition:
 *     An automated or manned <STRUCTURE> located adjacent to a <RAILWAY>
 *     that displays control information to passing <TRAIN>s; a railway
 *     signal structure.
 *
 * Group Membership: COMMUNICATION, LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_SIGNAL_STRUCTURE ((EDCS_Classification_Code)946)

/*
 * Definition:
 *     A manned <STRUCTURE> located adjacent to a <RAILWAY> that displays
 *     control information to passing <TRAIN>s; a signalman house.
 *
 * Group Membership: COMMUNICATION, LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_SIGNALMAN_HOUSE ((EDCS_Classification_Code)947)

/*
 * Definition:
 *     A short <RAILWAY_TRACK> that connects with the main <RAILWAY> at one
 *     end only; a railway spur [AHD, "spur track"].
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_SPUR ((EDCS_Classification_Code)948)

/*
 * Definition:
 *     A <BUILDING> or stopping place along a <RAILWAY> for taking on and
 *     letting off passengers or for servicing; a railway station.
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_RAILWAY_STATION ((EDCS_Classification_Code)949)

/*
 * Definition:
 *     A <BUILDING> that is used for the servicing, repair, and/or storage of
 *     <RAIL_WAGON>s and related <EQUIPMENT>.
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_RAILWAY_STORAGE_REPAIR_BUILDING ((EDCS_Classification_Code)950)

/*
 * Definition:
 *     A <FACILITY> used for the servicing, repair, and/or storage of
 *     <RAIL_WAGON>s and related <EQUIPMENT>.
 *
 * Group Membership: LAND_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_RAILWAY_STORAGE_REPAIR_FACILITY ((EDCS_Classification_Code)951)

/*
 * Definition:
 *     A <DEVICE> integrated with a <RAILWAY_TRACK> with which the rails may
 *     be switched to permit access to another <RAILWAY_TRACK>.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_SWITCH ((EDCS_Classification_Code)952)

/*
 * Definition:
 *     A rotating platform with <RAILWAY_TRACK>s used for turning
 *     <LOCOMOTIVE_ENGINE>s or <RAIL_WAGON>s; a railway table [SOED,
 *     "turntable", a].
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_TABLE ((EDCS_Classification_Code)953)

/*
 * Definition:
 *     A rail or two parallel rails on which a <TRAIN>, tram, or <RAIL_WAGON>
 *     runs; a railway track.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_TRACK ((EDCS_Classification_Code)954)

/*
 * Definition:
 *     A <RAILWAY_TABLE>, which may be enclosed within a <STRUCTURE>; a
 *     railway turntable.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_TURNTABLE ((EDCS_Classification_Code)955)

/*
 * Definition:
 *     A <SYSTEM> of <RAILWAY_TRACK>s and associated <STRUCTURE>s that are
 *     located within defined limits and that provide for loading,
 *     unloading, and/or assembling <TRAIN>s; a railway yard or marshalling
 *     yard.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_YARD ((EDCS_Classification_Code)956)

/*
 * Definition:
 *     A representation of a <RAILWAY_YARD> as it connects to related
 *     <RAILWAY>s; a railway yard centre-line or railway yard nexus.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_YARD_NEXUS ((EDCS_Classification_Code)957)

/*
 * Definition:
 *     <PRECIPITATION> of <PARTICLE>s of liquid <WATER> either in the form of
 *     drops of more than 0,5 millimetres in <<OUTSIDE_DIAMETER >> or in the
 *     form of widely scattered drops; rain.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_RAIN ((EDCS_Classification_Code)958)

/*
 * Definition:
 *     A <REGION> in which <RAIN> is falling.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_RAIN_REGION ((EDCS_Classification_Code)959)

/*
 * Definition:
 *     An inclined plane, usually man-made, for moving between two levels; a
 *     ramp.
 *
 * Group Membership: TRNSP
 */
#define ECC_RAMP ((EDCS_Classification_Code)960)

/*
 * Definition:
 *     A defensive <WALL>, which is sometimes equipped with
 *     <FIELD_ARTILLERY>, that is built to defend a <FORT> or a similar
 *     <DEFENSIVE_POSITION>; a bastion or rampart.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_RAMPART ((EDCS_Classification_Code)961)

/*
 * Definition:
 *     A <BUILDING> housing a warden employed to maintain and protect a
 *     <FOREST> or other natural <REGION> of a <PLANETARY_SURFACE>; a ranger
 *     station.
 *
 * Group Membership: SHELTER
 */
#define ECC_RANGER_STATION ((EDCS_Classification_Code)962)

/*
 * Definition:
 *     A steep descent in a <WATERCOURSE> causing a swift <WATER_CURRENT>; a
 *     rapid [SOED, "rapid", 1].
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_RAPID ((EDCS_Classification_Code)963)

/*
 * Definition:
 *     An imaginary <LINE> along which energy associated with a <LOCATION> on
 *     a wave front moves; a ray path.
 *
 * Group Membership: LOCATION
 */
#define ECC_RAY_PATH ((EDCS_Classification_Code)964)

/*
 * Definition:
 *     A <HELICOPTER> designed or designated for reconnaissance operations.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_RECONNAISSANCE_HELICOPTER ((EDCS_Classification_Code)965)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed or designated for reconnaissance
 *     operations.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_RECONNAISSANCE_WINGED_AIRCRAFT ((EDCS_Classification_Code)966)

/*
 * Definition:
 *     A <FACILITY> used for recreation; a recreational facility.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_RECREATIONAL_FACILITY ((EDCS_Classification_Code)967)

/*
 * Definition:
 *     A <PIER> used for recreational purposes and not intended as a berthing
 *     place for <VESSEL>s.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, RECREATION
 */
#define ECC_RECREATIONAL_PIER ((EDCS_Classification_Code)968)

/*
 * Definition:
 *     A <SITE> engaged in the wrecking, dismantling, storage, recycling,
 *     and/or resale of discarded or scrap products.
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_RECYCLING_SITE ((EDCS_Classification_Code)969)

/*
 * Definition:
 *     An elevation of <ROCK> or <CORAL> at or near enough to the
 *     <WATERBODY_SURFACE> to be a danger to surface <VESSEL>s.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_REEF ((EDCS_Classification_Code)970)

/*
 * Definition:
 *     A <BUILDING> used for the discipline, reformation, and training of
 *     young and/or first offenders; a reformatory building.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_REFORMATORY_BUILDING ((EDCS_Classification_Code)971)

/*
 * Definition:
 *     A <FACILITY> including one or more <REFORMATORY_BUILDING>s; a
 *     reformatory facility.
 *
 * Group Membership: ADMINISTRATION, SHELTER, USAGE_REGION
 */
#define ECC_REFORMATORY_FACILITY ((EDCS_Classification_Code)972)

/*
 * Definition:
 *     A specific <AIR_TRANSPORTATION_ROUTE> designated for channelling the
 *     flow of air traffic as necessary for the purpose of refuelling; a
 *     refuelling track.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_REFUELLING_TRACK ((EDCS_Classification_Code)973)

/*
 * Definition:
 *     A <FACILITY>, which is usually temporary, constructed to house groups
 *     of <HUMAN>s fleeing from their communities in search of refuge (for
 *     example: from war, political oppression, and/or religious
 *     persecution); a refugee compound.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_REFUGEE_COMPOUND ((EDCS_Classification_Code)974)

/*
 * Definition:
 *     A <CONTAINER> that: is of several cubic metres capacity; is used for
 *     the collection of refuse; and is designed to be hoisted and emptied
 *     into a specially equipped <TRUCK> or, occasionally, hauled away; a
 *     refuse bin.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define ECC_REFUSE_BIN ((EDCS_Classification_Code)975)

/*
 * Definition:
 *     A usually contiguous subset of the environment that may include
 *     <TERRAIN>, a <WATERBODY>, the <ATMOSPHERE>, and/or <SPACE>; a region.
 *
 * Group Membership: LOCATION
 */
#define ECC_REGION ((EDCS_Classification_Code)976)

/*
 * Definition:
 *     A <PROPERTY_SET> describing a <REGION>.
 *
 * Group Membership: PROPERTY_SET
 */
#define ECC_REGION_PROPERTY_SET ((EDCS_Classification_Code)977)

/*
 * Definition:
 *     A significant <TRACT> set aside for public use that generally has few
 *     or no <BUILDING>s, is located away from <BUILT_UP_REGION>s, and is
 *     maintained for recreational and ornamental purposes; a regional park.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_REGIONAL_PARK ((EDCS_Classification_Code)978)

/*
 * Definition:
 *     A <BOUNDARY> established to regulate matters between nations or groups
 *     over a specific territory; a regulated line. EXAMPLES Mandate line,
 *     convention line.
 *
 * Group Membership: ADMINISTRATION, DEMARCATION, LOCATION
 */
#define ECC_REGULATED_LINE ((EDCS_Classification_Code)979)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of related <OBJECT>s.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_RELATED_OBJECT_SET ((EDCS_Classification_Code)980)

/*
 * Definition:
 *     A <LINE> connecting <LOCATION>s having a constant relative vertical
 *     offset from the <TERRAIN>; a relative displacement line.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_RELATIVE_DISPLACEMENT_LINE ((EDCS_Classification_Code)981)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <DWELLING>s, <BUILDING>s, and/or other
 *     <STRUCTURE>s that houses a community of <HUMAN>s under religious
 *     vows; a religious community. EXAMPLES <CONVENT>, <MONASTERY>.
 *
 * Group Membership: RELIGION, SHELTER
 */
#define ECC_RELIGIOUS_COMMUNITY ((EDCS_Classification_Code)982)

/*
 * Definition:
 *     A <BUILDING> used for restoring broken and/or damaged goods (for
 *     example: <EQUIPMENT>) to sound condition; a repair building.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_REPAIR_BUILDING ((EDCS_Classification_Code)983)

/*
 * Definition:
 *     A <FACILITY> including one or more <REPAIR_BUILDING>s; a repair
 *     facility.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER, USAGE_REGION
 */
#define ECC_REPAIR_FACILITY ((EDCS_Classification_Code)984)

/*
 * Definition:
 *     A <VERTEBRATE> of the class Reptilia, the members of which are
 *     characterized by scaly impermeable skin, poikilothermy, and oviparous
 *     (or ovoviviparous) reproduction; a reptile [SOED, "reptile", 1].
 *     EXAMPLES Snake, lizard, turtle, crocodile.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_REPTILE ((EDCS_Classification_Code)985)

/*
 * Definition:
 *     A <REGION> set apart by a governmental body, institution, or
 *     individual for a special purpose; a reserve or reservation [SOED,
 *     "reservation", 7.a].
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_RESERVE ((EDCS_Classification_Code)986)

/*
 * Definition:
 *     A <LOCATION> where anything is collected and stored, generally in
 *     large quantity; especially a pond, <LAKE>, or <WATERBODY_BASIN>,
 *     either natural or artificial, for the storage, regulation, and
 *     control of <WATER>; a reservoir.
 *
 * Group Membership: LOCATION
 */
#define ECC_RESERVOIR ((EDCS_Classification_Code)987)

/*
 * Definition:
 *     A representation of a <RESERVOIR> as it connects to related
 *     <RIVER_NEXUS>s; a reservoir centre-line or reservoir nexus.
 *
 * Group Membership: HYDROLOGY, LOCATION
 */
#define ECC_RESERVOIR_NEXUS ((EDCS_Classification_Code)988)

/*
 * Definition:
 *     A <REGION> of <BUILDING>s primarily devoted to housing a population,
 *     as well as providing a variety of supporting services (for example: a
 *     <POST_OFFICE>, a grocery store, a dry cleaners, a florist, a
 *     <RESTAURANT>, and/or a small <RETAIL_FACILITY>); a residential region.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_RESIDENTIAL_REGION ((EDCS_Classification_Code)989)

/*
 * Definition:
 *     A <BUILDING> or outdoor <SITE> where meals are served to the public; a
 *     restaurant [AHD, "restaurant"].
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER, USAGE_REGION
 */
#define ECC_RESTAURANT ((EDCS_Classification_Code)990)

/*
 * Definition:
 *     A <FACILITY> that is used for retail (for example: for the sale of
 *     goods or commodities in small quantities directly to consumers); a
 *     retail facility.
 *
 * Group Membership: INDUSTRY, USAGE_REGION
 */
#define ECC_RETAIL_FACILITY ((EDCS_Classification_Code)991)

/*
 * Definition:
 *     Sound waves scattered back towards their source from an acoustically
 *     reflective <SURFACE> or volume; reverberation.
 *
 * Group Membership: ACOUSTIC_PHENOMENON
 */
#define ECC_REVERBERATION ((EDCS_Classification_Code)992)

/*
 * Definition:
 *     A <BARRIER> protecting a <RAMPART> or <WALL>; a revetment [SOED,
 *     "revetment", 2].
 *
 * Group Membership: SHELTER
 */
#define ECC_REVETMENT ((EDCS_Classification_Code)993)

/*
 * Definition:
 *     A <TRACT> that is periodically covered with <WATER> and is used for
 *     growing rice; a rice field.
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_RICE_FIELD ((EDCS_Classification_Code)994)

/*
 * Definition:
 *     Relatively high <TERRAIN> formed as a long and narrow crest that is
 *     surrounded by lower <TERRAIN>; a ridge.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_RIDGE ((EDCS_Classification_Code)995)

/*
 * Definition:
 *     A <LINE> delineating the top of a <RIDGE>; a ridge line.
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY
 */
#define ECC_RIDGE_LINE ((EDCS_Classification_Code)996)

/*
 * Definition:
 *     A <SUPERSTRUCTURE> fitted for drilling or lifting operations for
 *     extraction and/or exploitation of natural resources; a rig or
 *     superstructure.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_RIG ((EDCS_Classification_Code)997)

/*
 * Definition:
 *     A white or milky and opaque granular deposit of <ICE> formed by the
 *     rapid freezing of supercooled drops of <WATER> as they impinge upon
 *     an exposed <OBJECT>; rime. It is denser and harder than <HOAR_FROST>,
 *     but lighter, softer, and less transparent than <ICE_GLAZE>.
 *
 * Group Membership: ICE, SURFACE_MATERIAL
 */
#define ECC_RIME ((EDCS_Classification_Code)998)

/*
 * Definition:
 *     A strong, narrow, surface <WATER_CURRENT> flowing away from a
 *     <SHORELINE>.
 *
 * Group Membership: HYDROLOGY, WATERBODY_SURFACE
 */
#define ECC_RIP_CURRENT ((EDCS_Classification_Code)999)

/*
 * Definition:
 *     A loose assemblage of broken <STONE>s or similar <MATERIAL> that is
 *     erected along a <WATERBODY> or on soft <TERRAIN> as either a
 *     foundation or to protect the underlying <SURFACE> from erosion;
 *     riprap.
 *
 * Group Membership: SHELTER
 */
#define ECC_RIPRAP ((EDCS_Classification_Code)1000)

/*
 * Definition:
 *     A natural flowing <WATERCOURSE>; a river or stream.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_RIVER ((EDCS_Classification_Code)1001)

/*
 * Definition:
 *     The <WATERBODY_BANK> of a <RIVER>.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_RIVER_BANK ((EDCS_Classification_Code)1002)

/*
 * Definition:
 *     A <DEVICE> and support <STRUCTURE>s that monitors flow in a <RIVER>; a
 *     river gauging station.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT
 */
#define ECC_RIVER_GAUGING_STATION ((EDCS_Classification_Code)1003)

/*
 * Definition:
 *     A representation of one or more <RIVER>s; a river centre-line or river
 *     nexus.
 *
 * Group Membership: HYDROLOGY, LOCATION
 */
#define ECC_RIVER_NEXUS ((EDCS_Classification_Code)1004)

/*
 * Definition:
 *     The <MARINE_ROUTE> in a <RIVER> suitable for the largest allowed
 *     <VESSEL>s.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_RIVER_ROUTE ((EDCS_Classification_Code)1005)

/*
 * Definition:
 *     The <LOCATION> at which a <RIVER> passes into the <TERRAIN>; a river
 *     vanishing point.
 *
 * Group Membership: HYDROLOGY, LOCATION
 */
#define ECC_RIVER_VANISHING_POINT ((EDCS_Classification_Code)1006)

/*
 * Definition:
 *     A <LAND_TRANSPORTATION_ROUTE> maintained for use by <MOTOR_VEHICLE>s;
 *     a road.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_ROAD ((EDCS_Classification_Code)1007)

/*
 * Definition:
 *     A connection designed to provide traffic access from one <ROAD> to
 *     another; a road interchange.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_ROAD_INTERCHANGE ((EDCS_Classification_Code)1008)

/*
 * Definition:
 *     A representation of one or more <ROAD>s, especially in a
 *     <BUILT_UP_REGION>; a road centre-line or road nexus.
 *
 * Group Membership: LAND_TRNSP, LOCATION, TRNSP
 */
#define ECC_ROAD_NEXUS ((EDCS_Classification_Code)1009)

/*
 * Definition:
 *     A <DISPLAY_SIGN> used to designate a <ROAD>; a route marker.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_ROAD_ROUTE_MARKER ((EDCS_Classification_Code)1010)

/*
 * Definition:
 *     A <SITE> adjacent to a <ROAD> usually having <FACILITY>s for <HUMAN>s
 *     and/or <MOTOR_VEHICLE>s; a roadside rest stop.
 *
 * Group Membership: LAND_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_ROADSIDE_REST_STOP ((EDCS_Classification_Code)1011)

/*
 * Definition:
 *     A hard mineral <MATERIAL> that occurs in bulk as part of a <PLANET>
 *     and is either exposed at the <PLANETARY_SURFACE> or located
 *     underneath; rock [SOED, "rock", n.1.3].
 *
 * Group Membership: MATERIAL, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_ROCK ((EDCS_Classification_Code)1012)

/*
 * Definition:
 *     A massive assemblage of <MATERIAL>, usually in the form of large
 *     concrete blocks and/or cylinders, suspended above or beside a
 *     <LAND_TRANSPORTATION_ROUTE>, ready to be activated as a potential
 *     <BARRIER>; a rock drop.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_ROCK_DROP ((EDCS_Classification_Code)1013)

/*
 * Definition:
 *     A <PROTECTION_SHED> against slides of <ROCK>; a rock shed.
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_ROCK_SHED ((EDCS_Classification_Code)1014)

/*
 * Definition:
 *     An isolated rocky formation or single large <ROCK> that is located in
 *     its entirety above the high water mark of a <WATERBODY_SURFACE>, that
 *     is conspicuous and would appear to a mariner as a single <LOCATION>
 *     on <LAND>, and that would be appropriate for use in marine
 *     navigation; a rocky landmark.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_ROCKY_LANDMARK ((EDCS_Classification_Code)1015)

/*
 * Definition:
 *     An outcrop, layers (strata), or beds of <ROCK> on <LAND>; a rocky
 *     outcrop.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_ROCKY_OUTCROP ((EDCS_Classification_Code)1016)

/*
 * Definition:
 *     A <MAMMAL> of the order Rodentia, the members of which are
 *     characterized by strong continuously-growing incisor teeth and no
 *     canines; a rodent [SOED,"rodent", A]. EXAMPLES Rat, mouse, squirrel,
 *     vole, beaver.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_RODENT ((EDCS_Classification_Code)1017)

/*
 * Definition:
 *     A massive assemblage of <MATERIAL> (usually in the form of concrete
 *     blocks or cylinders) that is positioned alongside a
 *     <LAND_TRANSPORTATION_ROUTE> and is ready to be activated when needed
 *     as a potential <BARRIER> to an advancing enemy ground force; a
 *     rolling block.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define ECC_ROLLING_BLOCK ((EDCS_Classification_Code)1018)

/*
 * Definition:
 *     The outside upper covering of a <BUILDING>; a building roof [SOED,
 *     "roof", 1.a].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_ROOF ((EDCS_Classification_Code)1019)

/*
 * Definition:
 *     A <ROOF> and its structural support; a roof assembly.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_ROOF_ASSEMBLY ((EDCS_Classification_Code)1020)

/*
 * Definition:
 *     An interior portion of a <BUILDING> that is divided off by
 *     <BUILDING_COMPONENT>s (for example: <WALL>s, <ROOM_CEILING>s, room
 *     <FLOOR>s, and/or partitions); a room [SOED, "room", 8.a].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_ROOM ((EDCS_Classification_Code)1021)

/*
 * Definition:
 *     The overhead inside lining or suspended undercovering of a <ROOM>; a
 *     room ceiling.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_ROOM_CEILING ((EDCS_Classification_Code)1022)

/*
 * Definition:
 *     A circular <BUILDING> containing a <RAILWAY_TURNTABLE>; a roundhouse
 *     [AHD, "roundhouse", 1].
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_ROUNDHOUSE ((EDCS_Classification_Code)1023)

/*
 * Definition:
 *     A way or course of (especially regular) travel from one <LOCATION> to
 *     another <LOCATION>; a route [SOED, "route", 1a.].
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_ROUTE ((EDCS_Classification_Code)1024)

/*
 * Definition:
 *     A <COMPONENT> of a <ROUTE>.
 *
 * Group Membership: TRNSP
 */
#define ECC_ROUTE_COMPONENT ((EDCS_Classification_Code)1025)

/*
 * Definition:
 *     A <LOCATION> where a <ROUTE> narrows from its normal <<WIDTH>>; a
 *     constriction.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_ROUTE_CONSTRICTION ((EDCS_Classification_Code)1026)

/*
 * Definition:
 *     A <LOCATION> where a <ROUTE> widens beyond its normal <<WIDTH>>; an
 *     expansion.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_ROUTE_EXPANSION ((EDCS_Classification_Code)1027)

/*
 * Definition:
 *     A <COMPONENT> of a <LAND_TRANSPORTATION_ROUTE> that is typically
 *     designated by painted lines, is used to segregate the flow of
 *     <GROUND_VEHICLE>s according to speed or intended <DIRECTION>, and has
 *     enough <<WIDTH>> to pass a single file of <GROUND_VEHICLE>s; a route
 *     lane [SOED, "lane", 2.d].
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_ROUTE_LANE ((EDCS_Classification_Code)1028)

/*
 * Definition:
 *     A <TERRAIN_STRIP> along either side of and adjacent to a <ROAD> or
 *     <RUNWAY> and not normally used by <MOTOR_VEHICLE>s or <AIRCRAFT> but
 *     provided as an allowable margin in case of emergencies; a route
 *     shoulder.
 *
 * Group Membership: AIR_TRNSP, LAND_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_ROUTE_SHOULDER ((EDCS_Classification_Code)1029)

/*
 * Definition:
 *     A <LOCATION> where a <ROUTE> narrows or expands in <<WIDTH>>.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_ROUTE_WIDTH_CHANGE ((EDCS_Classification_Code)1030)

/*
 * Definition:
 *     One of a series of essentially identical residential <BUILDING>s
 *     situated side by side and sharing a common <WALL>; a row house.
 *
 * Group Membership: SHELTER
 */
#define ECC_ROWHOUSE ((EDCS_Classification_Code)1031)

/*
 * Definition:
 *     The rubbish of decayed or demolished <STRUCTURE>s, especially
 *     including fragments of brick or <STONE>; rubble [SOED, "rubble", 1].
 *
 * Group Membership: MATERIAL
 */
#define ECC_RUBBLE ((EDCS_Classification_Code)1032)

/*
 * Definition:
 *     The deteriorated remains of an unspecified <STRUCTURE>; a ruin.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_RUINS ((EDCS_Classification_Code)1033)

/*
 * Definition:
 *     <WATER> that is carried off a <TRACT> by <RIVER>s after having fallen
 *     as <RAIN>; run-off.
 *
 * Group Membership: HYDROLOGY, WATERBODY_STATE
 */
#define ECC_RUN_OFF ((EDCS_Classification_Code)1034)

/*
 * Definition:
 *     A defined <TRACT>, usually rectangular, used for the conventional
 *     landing and take-off of <AIRCRAFT>; a runway. The <RUNWAY_STOPWAY> is
 *     excluded from this <TRACT>.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY ((EDCS_Classification_Code)1035)

/*
 * Definition:
 *     An imaginary air navigation OIS consisting of an inclined plane,
 *     symmetrical about the centre-line of the <RUNWAY>, beginning 60,96
 *     metres (200 feet) outward of the <RUNWAY_ENDPOINT>, at the
 *     <<TERRAIN_ELEVATION>> of the <RUNWAY_ENDPOINT>, and extending for 12
 *     903,04 metres (42 332 feet, or 7 nautical miles minus 200 feet of
 *     <RUNWAY_PRIMARY_OIS>); a Runway Approach OIS. The slope of this
 *     <SURFACE> is 50 to 1 along the centre-line of the <RUNWAY> extended
 *     until it reaches a height of 152,4 metres (500 feet) above the
 *     <<TERRAIN_ELEVATION>> of the <RUNWAY_ENDPOINT> with the lowest
 *     <<TERRAIN_ELEVATION>> on the <AIRPORT>. It then continues
 *     horizontally to a point 12 964 metres (42 532 feet or 7 nautical
 *     miles) from the <RUNWAY_ENDPOINT>. The <<WIDTH>> of this <SURFACE> at
 *     the <RUNWAY_ENDPOINT> is the same as the <RUNWAY_PRIMARY_OIS>, it
 *     flares uniformly, and the <<WIDTH>> at 12 964 metres (42 532 feet)
 *     distance is 4 236,4 metres (13 899 feet).
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_APPROACH_OIS ((EDCS_Classification_Code)1036)

/*
 * Definition:
 *     An imaginary air navigation OIS extending from the periphery of the
 *     <RUNWAY_INNER_HORIZONTAL_OIS> outward and upward at a slope of 20 to
 *     1 for a horizontal distance of 2 133,6 metres (7 000 feet) to a
 *     height of 152,4 metres (500 feet) above the height of the lowest
 *     height <RUNWAY_ENDPOINT> and 4 419,6 metres (14 500 feet) from the
 *     centre-line of the <RUNWAY>; a Runway Conical OIS.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_CONICAL_OIS ((EDCS_Classification_Code)1037)

/*
 * Definition:
 *     An imaginary air navigation OIS connecting the side of the
 *     <RUNWAY_APPROACH_OIS> to the sides of both the <RUNWAY_CONICAL_OIS>
 *     and <RUNWAY_OUTER_HORIZONTAL_OIS>; a runway conical outer horizontal
 *     transitional OIS. This triangular <SURFACE> extends outward,
 *     perpendicular to the extended centre-line of the <RUNWAY> from the
 *     edges of the <RUNWAY_APPROACH_OIS>, at a 7 to 1 slope. The slope of
 *     this <SURFACE> is referenced to the centre-line of the <RUNWAY>.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_CONICAL_OUTER_HORIZONTAL_TRANSITIONAL_OIS ((EDCS_Classification_Code)1038)

/*
 * Definition:
 *     The designated beginning of the portion of a <RUNWAY> usable for
 *     landing that is located at a point on the <RUNWAY> other than the
 *     designated <RUNWAY_ENDPOINT>, and typically exists at each end of the
 *     <RUNWAY>; a runway displaced threshold.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_DISPLACED_THRESHOLD ((EDCS_Classification_Code)1039)

/*
 * Definition:
 *     One of the <LOCATION>s at each end of the centre-line of a <RUNWAY>; a
 *     runway endpoint.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_RUNWAY_ENDPOINT ((EDCS_Classification_Code)1040)

/*
 * Definition:
 *     An imaginary air navigation OIS defined by two half circles centred on
 *     the <RUNWAY_ENDPOINT>s and joined by tangents; a runway inner
 *     horizontal OIS. The <<RADIUS>>s of the half circles are 2 286 metres
 *     (7 500 feet) and the tangents are parallel to the centre-line of the
 *     <RUNWAY> at a distance of 2 286 metres (7 500 feet). This <SURFACE>
 *     extends horizontally outward from the periphery of the
 *     <RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS> at a <<TERRAIN_ELEVATION>>
 *     of 45,7 metres (150 feet) above the <<TERRAIN_ELEVATION>> of the
 *     <RUNWAY_ENDPOINT> of lowest <<TERRAIN_ELEVATION>>.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_INNER_HORIZONTAL_OIS ((EDCS_Classification_Code)1041)

/*
 * Definition:
 *     A symbol or group of symbols (for example: threshold markings, runway
 *     side stripes, and/or <CENTRE_LINE>s) displayed on the surface of a
 *     <RUNWAY> to convey aeronautical information.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_MARKINGS ((EDCS_Classification_Code)1042)

/*
 * Definition:
 *     A representation of one or more <RUNWAY>s; a runway centre-line or
 *     runway nexus.
 *
 * Group Membership: AIR_TRNSP, LOCATION, TRNSP
 */
#define ECC_RUNWAY_NEXUS ((EDCS_Classification_Code)1043)

/*
 * Definition:
 *     An imaginary air navigation OIS consisting of a horizontal plane,
 *     located 152,4 metres (500 feet) above the <<TERRAIN_ELEVATION>> of
 *     the <RUNWAY_ENDPOINT> with the lowest <<TERRAIN_ELEVATION>>,
 *     extending outward from the outer periphery of the
 *     <RUNWAY_CONICAL_OIS> for a horizontal distance of 8 544,2 metres (28
 *     032 feet) reaching a distance of 19 963,8 metres (42 532 feet) from
 *     the centre-line of the <RUNWAY>; a runway outer horizontal OIS.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_OUTER_HORIZONTAL_OIS ((EDCS_Classification_Code)1044)

/*
 * Definition:
 *     In military aviation exclusively, a stabilized or paved <TRACT>
 *     immediately beyond the end of a <RUNWAY>, of the same <<WIDTH>> as
 *     the <RUNWAY> plus <ROUTE_SHOULDER>s, centred on the extended
 *     centre-line of the <RUNWAY>.
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define ECC_RUNWAY_OVERRUN ((EDCS_Classification_Code)1045)

/*
 * Definition:
 *     An imaginary air navigation OIS connecting the sides of the
 *     <RUNWAY_PRIMARY_OIS> and <RUNWAY_APPROACH_OIS> to the
 *     <RUNWAY_INNER_HORIZONTAL_OIS>; a runway primary approach transitional
 *     OIS. This <SURFACE> extends outward, perpendicular to the centre-line
 *     of the <RUNWAY>, from the edges of the <RUNWAY_PRIMARY_OIS>, at a
 *     slope of 7 to 1, to a <<WIDTH>> of 320 metres (1 050 feet) and a
 *     <<TERRAIN_ELEVATION>> of 45,7 metres (150 feet) above the
 *     <<TERRAIN_ELEVATION>> of the <RUNWAY_ENDPOINT> of lowest
 *     <<TERRAIN_ELEVATION>>.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS ((EDCS_Classification_Code)1046)

/*
 * Definition:
 *     An imaginary air navigation OIS that is longitudinally centred on a
 *     <RUNWAY>, equal to the <<LENGTH>> of the <RUNWAY> plus 304,8 metres
 *     (1 000 feet) on each end, and of a <<WIDTH>> of 609,6 metres (2 000
 *     feet); a runway primary OIS.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_PRIMARY_OIS ((EDCS_Classification_Code)1047)

/*
 * Definition:
 *     A <DEVICE>, normally placed near the threshold of a <RUNWAY>, used for
 *     reflecting radar signals; a runway radar reflector.
 *
 * Group Membership: AIR_TRNSP, COMMUNICATION, DEVICE_AND_EQUIPMENT, EM_PHENOMENON, TRNSP
 */
#define ECC_RUNWAY_RADAR_REFLECTOR ((EDCS_Classification_Code)1048)

/*
 * Definition:
 *     A <TRACT> beyond the take-off <RUNWAY_ENDPOINT> that is designated as
 *     able to support an <AIRCRAFT> during an aborted take-off; a runway
 *     stopway.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_STOPWAY ((EDCS_Classification_Code)1049)

/*
 * Definition:
 *     The first 914,4 metres (3 000 feet) of the <RUNWAY> beginning at the
 *     <RUNWAY_DISPLACED_THRESHOLD>; a runway touchdown zone.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_RUNWAY_TOUCHDOWN_ZONE ((EDCS_Classification_Code)1050)

/*
 * Definition:
 *     A natural <TERRAIN_DEPRESSION> in an arid or semi-arid
 *     <TERRAIN_SURFACE_REGION> the bed of which is covered with salt
 *     encrusted clayey <SOIL>; a sabkha or sebkha.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_SABKHA ((EDCS_Classification_Code)1051)

/*
 * Definition:
 *     An <ANIMAL_PARK> in which wild <NON_HUMAN_ANIMAL>s are allowed to roam
 *     free in an environment designed to resemble their natural habitat and
 *     are observed by visitors riding through the <PARK> in
 *     <MOTOR_VEHICLE>s; a safari park.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, RECREATION, USAGE_REGION
 */
#define ECC_SAFARI_PARK ((EDCS_Classification_Code)1052)

/*
 * Definition:
 *     A <MARINE_ROUTE> established for the safe passage of <VESSEL>s through
 *     either offshore <PETROLEUM_FIELD>s or <MINEFIELD>s; a safety fairway.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_SAFETY_FAIRWAY ((EDCS_Classification_Code)1053)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> that is primarily moved by the force created
 *     by the effect of the <WIND> on attached sails; a sailing vessel or
 *     sailing ship.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_SAILING_VESSEL ((EDCS_Classification_Code)1054)

/*
 * Definition:
 *     A shallow <RESERVOIR>, which is normally man-made, that is used for
 *     the natural evaporation of <WATER> for the collection of salt; a salt
 *     evaporator.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_SALT_EVAPORATOR ((EDCS_Classification_Code)1055)

/*
 * Definition:
 *     A flat <TRACT> covered by natural salt deposits on its <SURFACE>; a
 *     salt-pan.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_SALT_PAN ((EDCS_Classification_Code)1056)

/*
 * Definition:
 *     A <FACILITY> that houses an institution for the treatment of chronic
 *     diseases or for medically supervised recuperation; a sanatorium.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_SANATORIUM ((EDCS_Classification_Code)1057)

/*
 * Definition:
 *     A <MATERIAL> consisting of fine <PARTICLE>s of <ROCK>s (mainly
 *     siliceous); sand [SOED, "sand", 1.a].
 *
 * Group Membership: MATERIAL, PHYSIOGRAPHY
 */
#define ECC_SAND ((EDCS_Classification_Code)1058)

/*
 * Definition:
 *     A bar and/or low <RIDGE> of <SAND> along the <SHORE> of a <LAKE>,
 *     <RIVER>, or <OCEAN> that is built-up to the <WATERBODY_SURFACE> by
 *     <WATER_WAVE>s or <WATER_CURRENT>s.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_SAND_BAR ((EDCS_Classification_Code)1059)

/*
 * Definition:
 *     A mound or <RIDGE> of loose <SAND> formed by the <WIND>; a sand dune
 *     [SOED, "dune"].
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_SAND_DUNE ((EDCS_Classification_Code)1060)

/*
 * Definition:
 *     A <TRACT> covered by <SAND_DUNE>s; a sand dune region.
 *
 * Group Membership: PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_SAND_DUNE_REGION ((EDCS_Classification_Code)1061)

/*
 * Definition:
 *     A <LINE> that delineates a <TRACT> of <SAND> from an adjacent
 *     <WATERBODY> and that is covered and uncovered depending on the
 *     <<ELEVATION>> of its <SURFACE> and the current <<ELEVATION>> of the
 *     <WATERBODY_SURFACE>; a sand line.
 *
 * Group Membership: DEMARCATION, LITTORAL, LOCATION, SURFACE_MATERIAL
 */
#define ECC_SAND_LINE ((EDCS_Classification_Code)1062)

/*
 * Definition:
 *     A <CELESTIAL_BODY> that revolves around a larger <CELESTIAL_BODY>,
 *     usually a <PLANET>; a satellite [SOED, "satellite", A.2.a].
 *
 * Group Membership: ABSTRACT_OBJECT, SPACE
 */
#define ECC_SATELLITE ((EDCS_Classification_Code)1063)

/*
 * Definition:
 *     A <STRUCTURE> with an associated <AERIAL> used for tracking, control,
 *     transmission, and/or reception of signals from
 *     <ARTIFICIAL_SATELLITE>s; a satellite ground station.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE, SPACE
 */
#define ECC_SATELLITE_GROUND_STATION ((EDCS_Classification_Code)1064)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is sixth in distance from the
 *     <SUN>, with an orbital mean <<RADIUS>> of approximately 1 429,4
 *     million kilometres; Saturn.
 *
 * Group Membership: SPACE
 */
#define ECC_SATURN ((EDCS_Classification_Code)1065)

/*
 * Definition:
 *     A <BUILDING> where <LOG>s are processed into lumber; a sawmill.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_SAWMILL ((EDCS_Classification_Code)1066)

/*
 * Definition:
 *     A <LOCATION>, which is generally elevated, with <FACILITY>s for
 *     observing the scenery; a scenic lookout.
 *
 * Group Membership: LOCATION, RECREATION
 */
#define ECC_SCENIC_LOOKOUT ((EDCS_Classification_Code)1067)

/*
 * Definition:
 *     A <BUILDING> used for instruction; a school building.
 *
 * Group Membership: INFRASTRUCTURE, SHELTER
 */
#define ECC_SCHOOL_BUILDING ((EDCS_Classification_Code)1068)

/*
 * Definition:
 *     A <BUILDING> supporting scientific experimentation or research,
 *     including scholarly investigation or inquiry, intended to ultimately
 *     result in commercial products; a science building.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_SCIENCE_BUILDING ((EDCS_Classification_Code)1069)

/*
 * Definition:
 *     A <FACILITY> including one or more <SCIENCE_BUILDING>s; a science
 *     facility.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER, USAGE_REGION
 */
#define ECC_SCIENCE_FACILITY ((EDCS_Classification_Code)1070)

/*
 * Definition:
 *     A <TRACT> used to collect scrap metal for reprocessing; a scrapyard.
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE, LAND_INDUSTRY, USAGE_REGION
 */
#define ECC_SCRAPYARD ((EDCS_Classification_Code)1071)

/*
 * Definition:
 *     A <TRACT> covered by uncultured <PLANT>s that may have some woody
 *     tissue; scrub land or brush land.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_SCRUB_LAND ((EDCS_Classification_Code)1072)

/*
 * Definition:
 *     A salty <WATERBODY> more or less confined by continuous <LAND> or
 *     chains of <ISLAND>s and forming a distinct <REGION>; a sea.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_SEA ((EDCS_Classification_Code)1073)

/*
 * Definition:
 *     A <POD> of seals.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_SEAL_POD ((EDCS_Classification_Code)1074)

/*
 * Definition:
 *     A <WATERBODY_FLOOR_PINNACLE> rising 1 000 metres or more from the
 *     <WATERBODY_FLOOR> of a <SEA> or <OCEAN> and of limited extent across
 *     its summit; a seamount.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_SEAMOUNT ((EDCS_Classification_Code)1075)

/*
 * Definition:
 *     An <AIRCRAFT> capable of taking off and landing on a
 *     <WATERBODY_SURFACE>; a seaplane [SOED, "seaplane"].
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_SEAPLANE ((EDCS_Classification_Code)1076)

/*
 * Definition:
 *     A <FACILITY> supporting <SEAPLANE>s; a seaplane base.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_SEAPLANE_BASE ((EDCS_Classification_Code)1077)

/*
 * Definition:
 *     A designated <REGION> of a <WATERBODY_SURFACE> outlined by visual
 *     markings used by <SEAPLANE>s to land and take off; a seaplane run.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_SEAPLANE_RUN ((EDCS_Classification_Code)1078)

/*
 * Definition:
 *     A <WALL> built to protect a <SHORE> from erosion; a seawall.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT
 */
#define ECC_SEAWALL ((EDCS_Classification_Code)1079)

/*
 * Definition:
 *     A <REGION> of large green, brown, or dark red <VEGETATION> (for
 *     example: kelp and/or seaweed) growing in a salt <WATER>, typically
 *     cold, environment.
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_SEAWEED ((EDCS_Classification_Code)1080)

/*
 * Definition:
 *     Unconsolidated <MATERIAL> composed of <PARTICLE>s deposited from
 *     either a suspension in <AIR>, <ICE>, or <WATER> or from solution in
 *     <WATER>; sediment [SOED, "sediment", 3].
 *
 * Group Membership: MATERIAL
 */
#define ECC_SEDIMENT ((EDCS_Classification_Code)1081)

/*
 * Definition:
 *     Self-propelled <FIELD_ARTILLERY>.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_SELF_PROPELLED_ARTILLERY ((EDCS_Classification_Code)1082)

/*
 * Definition:
 *     A <FACILITY> used as a school, especially a theological school, for
 *     the training of priests, ministers, or rabbis; a seminary [AHD,
 *     "seminary", 1.a].
 *
 * Group Membership: RELIGION, USAGE_REGION
 */
#define ECC_SEMINARY ((EDCS_Classification_Code)1083)

/*
 * Definition:
 *     A residential <BUILDING> housing a group of elderly <HUMAN>s; a senior
 *     citizens home.
 *
 * Group Membership: INFRASTRUCTURE, SHELTER
 */
#define ECC_SENIOR_CITIZENS_HOME ((EDCS_Classification_Code)1084)

/*
 * Definition:
 *     A possibly empty collection of distinct <OBJECT>s; a set.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_SET ((EDCS_Classification_Code)1085)

/*
 * Definition:
 *     A concentration of <DWELLING>s that is smaller in size than a <TOWN>;
 *     a settlement or village.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_SETTLEMENT ((EDCS_Classification_Code)1086)

/*
 * Definition:
 *     A small <RESERVOIR> where solid matter is precipitated from a liquid
 *     by evaporating or settling; a settling pond.
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE
 */
#define ECC_SETTLING_POND ((EDCS_Classification_Code)1087)

/*
 * Definition:
 *     An artificial channel or conduit, usually covered and under the
 *     <TERRAIN>, for carrying off and discharging waste, storm <WATER>,
 *     and/or refuse from <BUILDING>s and <BUILT_UP_REGION>s; a sewer [SOED,
 *     "sewer", 2.a].
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_SEWER ((EDCS_Classification_Code)1088)

/*
 * Definition:
 *     A <REGION> of partial darkness produced by an <OBJECT> intercepting
 *     rays of light (for example: the direct rays of the <SUN>); a shadow.
 *
 * Group Membership: LIGHTING_AND_VISIBILITY
 */
#define ECC_SHADOW ((EDCS_Classification_Code)1089)

/*
 * Definition:
 *     A <TOWN>, or a section of a <TOWN>, consisting chiefly of shacks; a
 *     shanty town.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_SHANTY_TOWN ((EDCS_Classification_Code)1090)

/*
 * Definition:
 *     A curve along a <LAND_TRANSPORTATION_ROUTE> that may cause
 *     restrictions in traffic of <GROUND_VEHICLE>s; a sharp curve.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_SHARP_CURVE ((EDCS_Classification_Code)1091)

/*
 * Definition:
 *     The <WALL> of the <EXCAVATION> within a <QUARRY> or <EXTRACTION_MINE>;
 *     a shear wall.
 *
 * Group Membership: DEMARCATION, INDUSTRY, PHYSIOGRAPHY
 */
#define ECC_SHEAR_WALL ((EDCS_Classification_Code)1092)

/*
 * Definition:
 *     A relatively small <BUILDING>, which usually has one or more open
 *     sides, that is typically used for storage; a shed.
 *
 * Group Membership: SHELTER
 */
#define ECC_SHED ((EDCS_Classification_Code)1093)

/*
 * Definition:
 *     Two or three spars standing on end and lashed together aloft that
 *     serve as a derrick or tripod to lift heavy weights, to step or lower
 *     <MAST>s or stacks, or for similar marine purposes; sheer legs.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_SHEERLEGS ((EDCS_Classification_Code)1094)

/*
 * Definition:
 *     A <REGION> in a shallow <WATERBODY> where shellfish breed and may be
 *     cultivated; a shellfish bed.
 *
 * Group Membership: AGRICULTURE, ANIMAL, LIVING_ORGANISM
 */
#define ECC_SHELLFISH_BED ((EDCS_Classification_Code)1095)

/*
 * Definition:
 *     A <STRUCTURE> for protecting <EQUIPMENT> or <HUMAN>s; a shelter.
 *
 * Group Membership: SHELTER
 */
#define ECC_SHELTER ((EDCS_Classification_Code)1096)

/*
 * Definition:
 *     A <SITE> where <VESSEL>s are built or repaired; a shipyard [SOED,
 *     "shipyard"].
 *
 * Group Membership: HYDROGRAPHIC_INDUSTRY, HYDROGRAPHIC_TRNSP, INDUSTRY, TRNSP
 */
#define ECC_SHIPYARD ((EDCS_Classification_Code)1097)

/*
 * Definition:
 *     A <MARINE_REGION> over which there is a <<WATER_DEPTH>> of twenty
 *     metres or less, and which is composed of unconsolidated <MATERIAL>,
 *     except <CORAL> or <ROCK>; a shoal.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_SHOAL ((EDCS_Classification_Code)1098)

/*
 * Definition:
 *     A group of <RETAIL_FACILITY>s, often including <RESTAURANT>s and other
 *     businesses, having a common <VEHICLE_LOT>; a shopping centre [AHD,
 *     "shopping center"].
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, LAND_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_SHOPPING_CENTRE ((EDCS_Classification_Code)1099)

/*
 * Definition:
 *     The narrow <TERRAIN_STRIP> in immediate contact with a <WATERBODY>,
 *     including the <TRACT> between high and low water <LINE>s; a shore.
 *
 * Group Membership: DEMARCATION, LITTORAL, PHYSIOGRAPHY
 */
#define ECC_SHORE ((EDCS_Classification_Code)1100)

/*
 * Definition:
 *     A <STRUCTURE> that protects a <HARBOUR> or <SHORE> from the forces of
 *     the <SEA>. EXAMPLES <BREAKWATER>, <GROIN>.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, SHELTER
 */
#define ECC_SHORE_PROTECTION_STRUCTURE ((EDCS_Classification_Code)1101)

/*
 * Definition:
 *     A <REVETMENT> placed along a <SHORE> to stabilize the <WATERBODY_BANK>
 *     and to protect it from the erosive action of flowing <WATER>.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, SHELTER
 */
#define ECC_SHORE_REVETMENT ((EDCS_Classification_Code)1102)

/*
 * Definition:
 *     The <LAND_WATER_BOUNDARY> between the <SHORE> or <BEACH> and a defined
 *     mean water level; a shoreline. EXAMPLE The high water shoreline would
 *     be the <LAND_WATER_BOUNDARY> with mean high water.
 *
 * Group Membership: DEMARCATION, LITTORAL
 */
#define ECC_SHORELINE ((EDCS_Classification_Code)1103)

/*
 * Definition:
 *     A fixed (not afloat) artificial <STRUCTURE> attached to a <SHORE> and
 *     normally used for berthing and protection of <VESSEL>s; a shoreline
 *     construction.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_SHORELINE_CONSTRUCTION ((EDCS_Classification_Code)1104)

/*
 * Definition:
 *     A <REGION> on a <SHORE> where landing from a <WATERBODY> is possible;
 *     a shoreline landing place.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_SHORELINE_LANDING_PLACE ((EDCS_Classification_Code)1105)

/*
 * Definition:
 *     A <STAIR> on a <SHORE> constructed to connect between the <LAND> and
 *     the <WATERBODY> on different levels; a shoreline landing stair.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT
 */
#define ECC_SHORELINE_LANDING_STAIR ((EDCS_Classification_Code)1106)

/*
 * Definition:
 *     <EQUIPMENT> for <EXCAVATION> that moves <MATERIAL>s by a scooping
 *     action; a shovel.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY
 */
#define ECC_SHOVEL ((EDCS_Classification_Code)1107)

/*
 * Definition:
 *     A naturally occurring, significant grouping of shrimp that persists
 *     over a significant period; a shrimp bed.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_SHRIMP_BED ((EDCS_Classification_Code)1108)

/*
 * Definition:
 *     A <WORSHIP_PLACE> or place for devotion; a shrine [SOED, "shrine", 6].
 *
 * Group Membership: RELIGION
 */
#define ECC_SHRINE ((EDCS_Classification_Code)1109)

/*
 * Definition:
 *     A low growing, multi-stemmed woody <PLANT>; a shrub [AHD, "shrub"].
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_SHRUB ((EDCS_Classification_Code)1110)

/*
 * Definition:
 *     A paved pedestrian walkway, usually made of concrete, typically
 *     located adjacent and parallel to a <ROAD>; a sidewalk.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_SIDEWALK ((EDCS_Classification_Code)1111)

/*
 * Definition:
 *     A <PIPE> used for conveying liquid from one level to a lower level,
 *     using the liquid pressure differential to force a column of the
 *     liquid up to a higher level before it falls to the outlet; a siphon
 *     [SOED, "siphon", 2.a].
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_SIPHON ((EDCS_Classification_Code)1112)

/*
 * Definition:
 *     The <LOCATION> of an actual or planned <NON_EMPTY_SET> of
 *     <STRUCTURE>s; a site [AHD, "site", 1].
 *
 * Group Membership: LOCATION
 */
#define ECC_SITE ((EDCS_Classification_Code)1113)

/*
 * Definition:
 *     A <RAMP> used for ski jumping; a ski jump.
 *
 * Group Membership: RECREATION
 */
#define ECC_SKI_JUMP ((EDCS_Classification_Code)1114)

/*
 * Definition:
 *     A <ROUTE> prepared for skiing; a ski track.
 *
 * Group Membership: LAND_TRNSP, LOCATION, RECREATION, TRNSP
 */
#define ECC_SKI_TRACK ((EDCS_Classification_Code)1115)

/*
 * Definition:
 *     A small <APERTURE> filled in with a transparent or translucent
 *     <MATERIAL> (for example: glass) that admits daylight through a <ROOF>
 *     and/or <ROOM_CEILING>; a skylight.
 *
 * Group Membership: BUILDING_COMPONENT, LIGHTING_AND_VISIBILITY
 */
#define ECC_SKYLIGHT ((EDCS_Classification_Code)1116)

/*
 * Definition:
 *     A <RAMP> for launching and recovering <VESSEL>s; a slipway or patent
 *     slip.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_SLIPWAY ((EDCS_Classification_Code)1117)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> where the <<TERRAIN_SLOPE>> is within a set
 *     range of values.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_SLOPE_REGION ((EDCS_Classification_Code)1118)

/*
 * Definition:
 *     A <GATE> used to regulate the flow of sludge from a <SETTLING_POND>; a
 *     sludge gate.
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE
 */
#define ECC_SLUDGE_GATE ((EDCS_Classification_Code)1119)

/*
 * Definition:
 *     An open, inclined conduit for <WATER> that is fitted with a
 *     <SLUICE_GATE> and may be employed in mine ore washing operations; a
 *     sluice.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_SLUICE ((EDCS_Classification_Code)1120)

/*
 * Definition:
 *     A <GATE> used to regulate the flow of <WATER> in a <SLUICE>; a sluice
 *     gate.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_SLUICE_GATE ((EDCS_Classification_Code)1121)

/*
 * Definition:
 *     A <FACILITY> with functions or services generally of interest for
 *     small craft or pleasure <WATER_SURFACE_VESSEL>s.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, RECREATION, USAGE_REGION
 */
#define ECC_SMALL_CRAFT_FACILITY ((EDCS_Classification_Code)1122)

/*
 * Definition:
 *     <HAIL> with an <<OUTSIDE_DIAMETER>> less than 0,64 centimetre, which
 *     is a form of <ICE_PELLETS>; small hail (US).
 *
 * Group Membership: ATMOSPHERE, ICE
 */
#define ECC_SMALL_HAIL ((EDCS_Classification_Code)1123)

/*
 * Definition:
 *     A visible <NON_AQUEOUS_CLOUD>, <PLUME>, or <PUFF> composed of carbon
 *     and other <PARTICLE>s given off by burning or smouldering
 *     <MATERIAL>s; smoke [SOED, "smoke", A.1].
 *
 * Group Membership: AIRBORNE_PARTICLE, ATMOSPHERE
 */
#define ECC_SMOKE ((EDCS_Classification_Code)1124)

/*
 * Definition:
 *     A <COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE> consisting of a large, tall
 *     <PIPE> which is often free-standing; a smokestack [AHD, "smokestack"].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_SMOKESTACK ((EDCS_Classification_Code)1125)

/*
 * Definition:
 *     A stem or trunk of a <TREE> below a <WATERBODY_SURFACE>; a snag.
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_SNAG ((EDCS_Classification_Code)1126)

/*
 * Definition:
 *     <SOLID_PRECIPITATION> of very small opaque white <PARTICLE>s of <ICE>
 *     that fall from a <CLOUD> and are fairly flat or elongated with
 *     <<OUTSIDE_DIAMETER>>s generally less than 1 millimetre; the solid
 *     equivalent of <DRIZZLE>; snow grains.
 *
 * Group Membership: ATMOSPHERE, ICE, MATERIAL
 */
#define ECC_SNOW_GRAINS ((EDCS_Classification_Code)1127)

/*
 * Definition:
 *     The layer formed by <SNOW_PRECIPITATION> as it accumulates on the
 *     <LAND>; snow ground cover.
 *
 * Group Membership: ICE, MATERIAL, SURFACE_MATERIAL
 */
#define ECC_SNOW_GROUND_COVER ((EDCS_Classification_Code)1128)

/*
 * Definition:
 *     <SOLID_PRECIPITATION> composed of white or translucent crystals of
 *     <ICE> that are chiefly in complex branch hexagonal form and are often
 *     agglomerated into snowflakes or the layer formed by them on the
 *     <LAND>; snow.
 *
 * Group Membership: ATMOSPHERE, ICE, MATERIAL
 */
#define ECC_SNOW_PRECIPITATION ((EDCS_Classification_Code)1129)

/*
 * Definition:
 *     A <REGION> in which <SNOW_PRECIPITATION> is falling.
 *
 * Group Membership: ATMOSPHERE, ICE
 */
#define ECC_SNOW_REGION ((EDCS_Classification_Code)1130)

/*
 * Definition:
 *     A <PROTECTION_SHED> against slides of <SNOW_GROUND_COVER>; a snow shed.
 *
 * Group Membership: ICE, LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_SNOW_SHED ((EDCS_Classification_Code)1131)

/*
 * Definition:
 *     A <TRACT> covered by <SNOW_GROUND_COVER>; a snowfield.
 *
 * Group Membership: ICE, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_SNOWFIELD ((EDCS_Classification_Code)1132)

/*
 * Definition:
 *     A shallow <RESERVOIR>, normally man-made, used for the natural
 *     evaporation of <WATER> for the collection of soda; soda evaporator.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_SODA_EVAPORATOR ((EDCS_Classification_Code)1133)

/*
 * Definition:
 *     A <MATERIAL> composed of fragmented <PARTICLE>s of <ROCK>, decomposed
 *     <PLANT>s, <WATER>, and <AIR> that typically comprises a thin top
 *     layer of the <LAND>; soil [SOED, "soil", 4].
 *
 * Group Membership: MATERIAL, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_SOIL ((EDCS_Classification_Code)1134)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of solar cells for converting sunlight into
 *     electrical energy or heat; a solar panel.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, TEMPERATURE
 */
#define ECC_SOLAR_PANEL ((EDCS_Classification_Code)1135)

/*
 * Definition:
 *     A <STAR> and its family of <PLANET>s, natural <SATELLITE>s,
 *     <ASTEROID>s, and <COMET>s that are captured by its gravity; a solar
 *     system.
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_SOLAR_SYSTEM ((EDCS_Classification_Code)1136)

/*
 * Definition:
 *     A <MESH> with a related <MESH_SOLID_SET>; a solid mesh.
 *
 * Group Membership: ALGORITHM_RELATED
 */
#define ECC_SOLID_MESH ((EDCS_Classification_Code)1137)

/*
 * Definition:
 *     <PRECIPITATION> of <ICE>; solid precipitation.
 *
 * Group Membership: ATMOSPHERE, ICE, MATERIAL
 */
#define ECC_SOLID_PRECIPITATION ((EDCS_Classification_Code)1138)

/*
 * Definition:
 *     A horizontal layer in a <WATERBODY> that is bounded by levels at which
 *     the <<WATERBODY_SOUND_SPEED>> is greater than at any level within the
 *     layer; a sound channel.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_STATE
 */
#define ECC_SOUND_CHANNEL ((EDCS_Classification_Code)1139)

/*
 * Definition:
 *     The alignment axis in a <SOUND_CHANNEL> determined by the depth at
 *     which the minimum <<WATERBODY_SOUND_SPEED>> occurs.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_STATE
 */
#define ECC_SOUND_CHANNEL_AXIS ((EDCS_Classification_Code)1140)

/*
 * Definition:
 *     A measured <<WATER_DEPTH>> or spot <<WATER_DEPTH>>; a sounding.
 *
 * Group Membership: SURVEY, WATERBODY_FLOOR
 */
#define ECC_SOUNDING ((EDCS_Classification_Code)1141)

/*
 * Definition:
 *     The vertical, typically tidal, <SURFACE_DATUM> to which <SOUNDING>s
 *     and <<HYDROGRAPHIC_DRYING_HEIGHT>>s are referenced; usually taken to
 *     correspond to a low water stage of the <TIDE>; the sounding datum.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_SOUNDING_DATUM ((EDCS_Classification_Code)1142)

/*
 * Definition:
 *     The <REGION> extending in all <DIRECTION>s in which all matter lying
 *     outside celestial body <ATMOSPHERE>s is located; the near vacuum
 *     occupying the <REGION>s between <CELESTIAL_BODY>s; space [SOED,
 *     "space", II.12.a].
 *
 * Group Membership: SPACE
 */
#define ECC_SPACE ((EDCS_Classification_Code)1143)

/*
 * Definition:
 *     A <VEHICLE> operating mainly in <SPACE>; a spacecraft [SOED,
 *     "spacecraft"].
 *
 * Group Membership: SPACE, TRNSP, VEHICLE
 */
#define ECC_SPACECRAFT ((EDCS_Classification_Code)1144)

/*
 * Definition:
 *     A <FACILITY> for the launch, and sometimes the landing, of
 *     <SPACECRAFT>; a spaceport [SOED, "spaceport"].
 *
 * Group Membership: SPACE, TRNSP, USAGE_REGION
 */
#define ECC_SPACEPORT ((EDCS_Classification_Code)1145)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed or designated for special electronic
 *     operations.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_SPECIAL_ELECTRONIC_WINGED_AIRCRAFT ((EDCS_Classification_Code)1146)

/*
 * Definition:
 *     A <HELICOPTER> designed or designated for special operations.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_SPECIAL_OPERATIONS_HELICOPTER ((EDCS_Classification_Code)1147)

/*
 * Definition:
 *     An <AIRSPACE> identified by a delimited <REGION> where activities must
 *     be confined because of their nature and/or where limitations may be
 *     imposed on <AIRCRAFT> operations not associated with those
 *     activities; a special use airspace.
 *
 * Group Membership: AIR_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_SPECIAL_USE_AIRSPACE ((EDCS_Classification_Code)1148)

/*
 * Definition:
 *     A <COMPONENT> of a <SPECIAL_USE_AIRSPACE>.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_SPECIAL_USE_AIRSPACE_COMPONENT ((EDCS_Classification_Code)1149)

/*
 * Definition:
 *     A passage for surplus <WATER> to run over or around a <DAM>; a
 *     spillway.
 *
 * Group Membership: HYDROLOGY, INFRASTRUCTURE
 */
#define ECC_SPILLWAY ((EDCS_Classification_Code)1150)

/*
 * Definition:
 *     An arena with tiered seats or terraces for spectators of athletic or
 *     sporting events [SOED, "stadium", 3].
 *
 * Group Membership: RECREATION
 */
#define ECC_SPORTS_ARENA ((EDCS_Classification_Code)1151)

/*
 * Definition:
 *     A designated <LOCATION> with an <<ELEVATION>>; a spot elevation.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_SPOT_ELEVATION ((EDCS_Classification_Code)1152)

/*
 * Definition:
 *     A natural outflow of <WATER> from below the <LAND>; a spring.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_SPRING ((EDCS_Classification_Code)1153)

/*
 * Definition:
 *     The <TIDE>s of increased range occurring near the times of the full
 *     and new <<MOON_PHASE>>s.
 *
 * Group Membership: LITTORAL, WATERBODY_SURFACE
 */
#define ECC_SPRING_TIDE ((EDCS_Classification_Code)1154)

/*
 * Definition:
 *     A <SPORTS_ARENA> or a <TRACT> used for athletic sports with tiered
 *     seats or terraces for spectators; a stadium [SOED, "stadium", 3].
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_STADIUM ((EDCS_Classification_Code)1155)

/*
 * Definition:
 *     A series of fixed steps leading from one level to another, especially
 *     such a series leading from one <FLOOR_LEVEL> to another inside a
 *     <STRUCTURE>; a stair [SOED, "star", A.I.1].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_STAIR ((EDCS_Classification_Code)1156)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <STAIR>s connecting three or more <FLOOR_LEVEL>s
 *     in an uninterrupted sequence.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_STAIR_SET ((EDCS_Classification_Code)1157)

/*
 * Definition:
 *     A small <MARKER> used to identify <WATER_CHANNEL>s or to mark dangers
 *     (for example: <STONE>s and/or <SHOAL>s); a stake.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_STAKE ((EDCS_Classification_Code)1158)

/*
 * Definition:
 *     A large, coherent, roughly spherical, gaseous <CELESTIAL_BODY> that is
 *     luminous by virtue of internal nuclear reactions; a star [SOED,
 *     "star", A.I.1].
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_STAR ((EDCS_Classification_Code)1159)

/*
 * Definition:
 *     An <ATMOSPHERIC_FRONT> between warm and cold <AIR_MASS>s that is
 *     moving at a speed less than 2,575 metres per second (five knots); a
 *     stationary front or a quasi-stationary front.
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, LOCATION, TEMPERATURE
 */
#define ECC_STATIONARY_FRONT ((EDCS_Classification_Code)1160)

/*
 * Definition:
 *     A <FACILITY> for the production of fabricated structural steel
 *     products (for example: girders and/or plates); a steel mill.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_STEEL_MILL ((EDCS_Classification_Code)1161)

/*
 * Definition:
 *     A stretch along a <LAND_TRANSPORTATION_ROUTE> where the slope is high
 *     enough to slow, hinder, or even stop traffic; a steep grade.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_STEEP_GRADE ((EDCS_Classification_Code)1162)

/*
 * Definition:
 *     A <STRUCTURE>, usually topped by a point, that may be erected on the
 *     <ROOF> of a <BUILDING>; a steeple.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_STEEPLE ((EDCS_Classification_Code)1163)

/*
 * Definition:
 *     A burst emission from a <STAR> at radio <<WAVELENGTH>>s that often
 *     sweep through a range of <<FREQUENCY>>s and last from minutes to
 *     days; a stellar burst radio frequency emission.
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_STELLAR_BURST_RADIO_FREQUENCY_EMISSION ((EDCS_Classification_Code)1164)

/*
 * Definition:
 *     An energetic charged <PARTICLE> emanating from a <STAR>; a stellar
 *     energetic particle. EXAMPLES Electron, proton, alpha <PARTICLE>.
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_STELLAR_ENERGETIC_PARTICLE ((EDCS_Classification_Code)1165)

/*
 * Definition:
 *     A continuous (flux) emission from a <STAR> at radio <<WAVELENGTH>>s; a
 *     stellar flux radio frequency emission.
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_STELLAR_FLUX_RADIO_FREQUENCY_EMISSION ((EDCS_Classification_Code)1166)

/*
 * Definition:
 *     A high-speed stream of <STELLAR_ENERGETIC_PARTICLE>s in <SPACE>; a
 *     stellar wind.
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_STELLAR_WIND ((EDCS_Classification_Code)1167)

/*
 * Definition:
 *     A piece of <ROCK> of a small or moderate size; a stone [SOED, "stone",
 *     A.1.a] or rock (US).
 *
 * Group Membership: MATERIAL, PHYSIOGRAPHY, SURFACE_MATERIAL
 */
#define ECC_STONE ((EDCS_Classification_Code)1168)

/*
 * Definition:
 *     A <BUNKER> that is used as a <STORAGE_STRUCTURE>; a storage bunker or
 *     storage mound.
 *
 * Group Membership: MILITARY_SCIENCE, SUPPORT_STRUCTURE
 */
#define ECC_STORAGE_BUNKER ((EDCS_Classification_Code)1169)

/*
 * Definition:
 *     A <CONTAINER> used for the storage of solid, liquid, or gaseous
 *     <MATERIAL>s; a storage container.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_STORAGE_CONTAINER ((EDCS_Classification_Code)1170)

/*
 * Definition:
 *     A <FACILITY> including one of more <STORAGE_STRUCTURE>s; a storage
 *     depot.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_STORAGE_DEPOT ((EDCS_Classification_Code)1171)

/*
 * Definition:
 *     An excavated <STORAGE_STRUCTURE> that is lined by an impermeable
 *     <MATERIAL> and surrounded with <SOIL>; a storage pit.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STORAGE_PIT ((EDCS_Classification_Code)1172)

/*
 * Definition:
 *     A <STRUCTURE> intended for storing <MATERIAL>s or products; a storage
 *     structure.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STORAGE_STRUCTURE ((EDCS_Classification_Code)1173)

/*
 * Definition:
 *     A <CONTAINER> used for the storage of liquids or gases; a storage tank.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_STORAGE_TANK ((EDCS_Classification_Code)1174)

/*
 * Definition:
 *     The top of the <TEMPERATURE_INVERSION_LAYER>, if it exists, that form
 *     the upper limit of the <STRATOSPHERE>; the stratopause.
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, TEMPERATURE
 */
#define ECC_STRATOPAUSE ((EDCS_Classification_Code)1175)

/*
 * Definition:
 *     The <ATMOSPHERE_REGION> of the <EARTH> extending from the <TROPOPAUSE>
 *     to the <STRATOPAUSE> in which the <<AIR_TEMPERATURE>> generally
 *     increases with <<HEIGHT_AGL>>; the stratosphere.
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define ECC_STRATOSPHERE ((EDCS_Classification_Code)1176)

/*
 * Definition:
 *     A <ROAD> in a <BUILT_UP_REGION>; a street.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_STREET ((EDCS_Classification_Code)1177)

/*
 * Definition:
 *     A <LIGHT>, generally located on a <POLE>, that illuminates a <ROAD> or
 *     a <SIDEWALK>; a street lamp [SOED, "street lamp"] or street-light.
 *
 * Group Membership: LAND_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_STREET_LAMP ((EDCS_Classification_Code)1178)

/*
 * Definition:
 *     A <STRUCTURE> consisting of a long, heavy timber or section of steel
 *     or concrete that is forced into the <TERRAIN> to serve as a support
 *     (for example: for a <PIER>); a piling or structural pile.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STRUCTURAL_PILE ((EDCS_Classification_Code)1179)

/*
 * Definition:
 *     A combination of <COMPONENT>s that are fabricated and interconnected
 *     in accordance with a design; a structure.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STRUCTURE ((EDCS_Classification_Code)1180)

/*
 * Definition:
 *     A way into a <STRUCTURE>; an entrance [SOED, "entrance", 4]. EXAMPLES
 *     <GATE>, <HALLWAY>, <DOOR>.
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_STRUCTURE_ENTRANCE ((EDCS_Classification_Code)1181)

/*
 * Definition:
 *     A way into, out of, or both into and out of a <STRUCTURE>; an entrance
 *     and/or an exit. EXAMPLES <GATE>, <HALLWAY>, <DOOR>.
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_STRUCTURE_ENTRANCE_AND_OR_EXIT ((EDCS_Classification_Code)1182)

/*
 * Definition:
 *     A way out of a <STRUCTURE>; an exit [SOED, "exit", 3]. EXAMPLES
 *     <GATE>, <HALLWAY>, <DOOR>.
 *
 * Group Membership: SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_STRUCTURE_EXIT ((EDCS_Classification_Code)1183)

/*
 * Definition:
 *     The <NON_EMPTY_SET> of <EXTERIOR_WALL>s and <ROOF> (if present) of a
 *     <STRUCTURE>.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STRUCTURE_EXTERIOR ((EDCS_Classification_Code)1184)

/*
 * Definition:
 *     The perimeter of a <STRUCTURE>.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STRUCTURE_PERIMETER ((EDCS_Classification_Code)1185)

/*
 * Definition:
 *     A round, usually dome-shaped, Buddhist <SHRINE> topped with a cupola;
 *     a stupa [SOED, "stupa"].
 *
 * Group Membership: RELIGION
 */
#define ECC_STUPA ((EDCS_Classification_Code)1186)

/*
 * Definition:
 *     An isolated formation of <ROCK> or a single large <ROCK> that is
 *     located in a <WATERBODY> and is typically submerged but possibly
 *     projects above the <WATERBODY_SURFACE>.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_SUBMERGED_ROCK_FORMATION ((EDCS_Classification_Code)1187)

/*
 * Definition:
 *     A <VESSEL> capable of operation either on a <WATERBODY_SURFACE> or
 *     beneath it; a submersible vessel.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_SUBMERSIBLE_VESSEL ((EDCS_Classification_Code)1188)

/*
 * Definition:
 *     A <TRACT> of Saccharum officinarum; sugar cane [AHD, "sugar cane"].
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_SUGAR_CANE ((EDCS_Classification_Code)1189)

/*
 * Definition:
 *     The central <STAR> of the <SOLAR_SYSTEM> containing the <EARTH>; the
 *     Sun.
 *
 * Group Membership: EM_PHENOMENON, SPACE
 */
#define ECC_SUN ((EDCS_Classification_Code)1190)

/*
 * Definition:
 *     A relatively cool and dark appearing <REGION> on the photosphere of
 *     the <SUN>; a sunspot.
 *
 * Group Membership: SPACE, TEMPERATURE
 */
#define ECC_SUNSPOT ((EDCS_Classification_Code)1191)

/*
 * Definition:
 *     A substantial <STRUCTURE> resting on something else; a superstructure
 *     [SOED, "superstructure", 1].
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_SUPERSTRUCTURE ((EDCS_Classification_Code)1192)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <EQUIPMENT> and/or <MATERIAL> that may be
 *     consumed or discarded after use; supplies and expendables.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_SUPPLIES_AND_EXPENDABLES ((EDCS_Classification_Code)1193)

/*
 * Definition:
 *     The belt of nearly continuous, breaking <WATER_WAVE>s along a <SHORE>
 *     or over a submerged bank or <SAND_BAR>; surf.
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_SURF ((EDCS_Classification_Code)1194)

/*
 * Definition:
 *     The <REGION> between the outermost limit of <SURF> and the resulting
 *     limit of <WATER_WAVE> uprush on a <SHORE>; a surf zone.
 *
 * Group Membership: WATERBODY_STATE, WATERBODY_SURFACE
 */
#define ECC_SURF_ZONE ((EDCS_Classification_Code)1195)

/*
 * Definition:
 *     An outermost, limiting <COMPONENT> of an <OBJECT> that is immediately
 *     adjacent to another <OBJECT> (for example: an <ATMOSPHERE> and/or
 *     <SPACE>); a surface [SOED, "surface", 1.a].
 *
 * Group Membership: ABSTRACT_OBJECT, SURFACE
 */
#define ECC_SURFACE ((EDCS_Classification_Code)1196)

/*
 * Definition:
 *     A layer of the <ATMOSPHERE> that is adjacent to the
 *     <PLANETARY_SURFACE> of the <EARTH> and in which electromagnetic waves
 *     are trapped due to changes in the index of refraction; a
 *     surface-based electromagnetic duct.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_SURFACE_BASED_EM_DUCT ((EDCS_Classification_Code)1197)

/*
 * Definition:
 *     A <DATUM> defining a <SURFACE> from which elevations or depths are
 *     measured. EXAMPLES <VERTICAL_DATUM>, <SOUNDING_DATUM>.
 *
 * Group Membership: SURFACE, SURVEY
 */
#define ECC_SURFACE_DATUM ((EDCS_Classification_Code)1198)

/*
 * Definition:
 *     A narrow fissure, crack, and/or rift in the <TERRAIN> or the overlying
 *     <SNOW_GROUND_COVER> or <ICE>; a surface fissure.
 *
 * Group Membership: ICE, PHYSIOGRAPHY
 */
#define ECC_SURFACE_FISSURE ((EDCS_Classification_Code)1199)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed or designated for surveillance missions.
 *
 * Group Membership: AIR_TRNSP, MILITARY_SCIENCE, TRNSP, VEHICLE
 */
#define ECC_SURVEILLANCE_WINGED_AIRCRAFT ((EDCS_Classification_Code)1200)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_OBJECT> (for example: a <MARKER>) with a known
 *     <LOCATION>; a survey marker.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_SURVEY_MARKER ((EDCS_Classification_Code)1201)

/*
 * Definition:
 *     A seasonally flooded, low-lying <WETLAND> with more woody <PLANT>s
 *     than a <MARSH> and better drainage than a <BOG>; a swamp [AHD,
 *     "swamp", 1a].
 *
 * Group Membership: HYDROLOGY, LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_SWAMP ((EDCS_Classification_Code)1202)

/*
 * Definition:
 *     A surface gravity <WATER_WAVE> that is not growing or being sustained
 *     any longer by the <WIND> but that was generated by the <WIND> some
 *     distance away and is now propagating freely across the
 *     <WATERBODY_SURFACE> away from its <REGION> of generation; a swell
 *     wave.
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_SWELL_WAVE ((EDCS_Classification_Code)1203)

/*
 * Definition:
 *     A <WATERBODY_REGION> that has been determined to be clear of
 *     navigational dangers to a specified depth; a swept region.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, HYDROLOGY, TRNSP
 */
#define ECC_SWEPT_REGION ((EDCS_Classification_Code)1204)

/*
 * Definition:
 *     A constructed pool used for swimming; a swimming pool [SOED, "swimming
 *     pool"].
 *
 * Group Membership: RECREATION
 */
#define ECC_SWIMMING_POOL ((EDCS_Classification_Code)1205)

/*
 * Definition:
 *     A <WORSHIP_PLACE> for Jewish worship and religious instruction; a
 *     synagogue.
 *
 * Group Membership: RELIGION
 */
#define ECC_SYNAGOGUE ((EDCS_Classification_Code)1206)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <OBJECT>s arranged or organized for a special
 *     purpose and functioning together as a whole; a system [SOED,
 *     "system", 3].
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_SYSTEM ((EDCS_Classification_Code)1207)

/*
 * Definition:
 *     A <TRACT> covered by systematic plantings of <TREE>s that yield a
 *     product (for example: a fruit and/or a nut).
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_SYSTEMATIC_TREE_PLANTING ((EDCS_Classification_Code)1208)

/*
 * Definition:
 *     A <CHURCH> that has been specially designated by religious authority;
 *     a tabernacle.
 *
 * Group Membership: RELIGION
 */
#define ECC_TABERNACLE ((EDCS_Classification_Code)1209)

/*
 * Definition:
 *     A prepared <SURFACE> providing access to/from <RUNWAY>s and
 *     <HARD_STANDING>s, <AERODROME_TERMINAL>s, and service and/or other
 *     support operations for <AIRCRAFT>; a taxiway.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_TAXIWAY ((EDCS_Classification_Code)1210)

/*
 * Definition:
 *     A <COMMUNICATION_STATION> housing a <SYSTEM> of switches that
 *     establishes connections between individual telecommunication
 *     <DEVICE>s; a telecom switching station.
 *
 * Group Membership: COMMUNICATION, INFRASTRUCTURE
 */
#define ECC_TELECOM_SWITCHING_STATION ((EDCS_Classification_Code)1211)

/*
 * Definition:
 *     A transportation <SYSTEM> consisting of <LOAD_CABLE>s strung between
 *     <PYLON>s on which carrier units (for example: cars or buckets
 *     intended to transport <PERSONNEL>, <MATERIAL>, and/or <EQUIPMENT>)
 *     are suspended; an aerial cableway, an aerial tramway, or a teleferic.
 *
 * Group Membership: TRNSP
 */
#define ECC_TELEFERIC ((EDCS_Classification_Code)1212)

/*
 * Definition:
 *     A <DEVICE> used for observing distant <OBJECT>s and/or phenomena; a
 *     telescope.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_TELESCOPE ((EDCS_Classification_Code)1213)

/*
 * Definition:
 *     A layer in an <ATMOSPHERE> where the <<AIR_TEMPERATURE>> increases
 *     with <<HEIGHT_AGL>>; temperature inversion layer.
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define ECC_TEMPERATURE_INVERSION_LAYER ((EDCS_Classification_Code)1214)

/*
 * Definition:
 *     A <TRACT> containing a temporary, usually unsheltered, encampment
 *     [SOED, "encampment", 1]. EXAMPLE Bivouac.
 *
 * Group Membership: USAGE_REGION
 */
#define ECC_TEMPORARY_ENCAMPMENT ((EDCS_Classification_Code)1215)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> used to attend other <VESSEL>s, especially to
 *     supply goods and provisions, convey orders, and/or carry passengers
 *     to and from <SHORE>; a tender [SOED, "tender", 2].
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_TENDER ((EDCS_Classification_Code)1216)

/*
 * Definition:
 *     A <SITE> including one of more <TENNIS_COURT>s; a tennis complex.
 *
 * Group Membership: RECREATION, USAGE_REGION
 */
#define ECC_TENNIS_COMPLEX ((EDCS_Classification_Code)1217)

/*
 * Definition:
 *     A court used in playing the game of tennis [SOED, "tennis-court"].
 *
 * Group Membership: RECREATION
 */
#define ECC_TENNIS_COURT ((EDCS_Classification_Code)1218)

/*
 * Definition:
 *     A portable <SHELTER> of canvas, cloth, or similar <MATERIAL> that is
 *     supported by one or more <POLE>s and stretched and secured by
 *     <LOAD_CABLE>s fastened to pegs driven into the <TERRAIN>; a tent
 *     [SOED, "tent", 1.a].
 *
 * Group Membership: SHELTER
 */
#define ECC_TENT ((EDCS_Classification_Code)1219)

/*
 * Definition:
 *     A <TENT> used as a <DWELLING>; a tent dwelling.
 *
 * Group Membership: SHELTER
 */
#define ECC_TENT_DWELLING ((EDCS_Classification_Code)1220)

/*
 * Definition:
 *     The <SURFACE> of the solid portion of a <PLANET>, which may or may not
 *     be covered by <WATER>; terrain or ground.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TERRAIN ((EDCS_Classification_Code)1221)

/*
 * Definition:
 *     An elongated <TERRAIN_SURFACE_REGION>, especially one that is
 *     relatively narrow, whose longer sides are <TERRAIN_SURFACE_REGION>s
 *     of higher <<TERRAIN_ELEVATION>>; a terrain channel. EXAMPLES
 *     <CANYON>, <GORGE>, dry riverbed.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TERRAIN_CHANNEL ((EDCS_Classification_Code)1222)

/*
 * Definition:
 *     A localized <TERRAIN_DEPRESSION> created by an explosion and/or the
 *     impact of a large or high-velocity projectile upon the <TERRAIN>; a
 *     crater [SOED, "crater", 2].
 *
 * Group Membership: MILITARY_SCIENCE, PHYSIOGRAPHY
 */
#define ECC_TERRAIN_CRATER ((EDCS_Classification_Code)1223)

/*
 * Definition:
 *     An <EXCAVATION> in the <TERRAIN> to provide passage for a
 *     <LAND_TRANSPORTATION_ROUTE> (for example: a <ROAD>, a <RAILWAY>,
 *     and/or a <CANAL>); a terrain cut.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TERRAIN_CUT ((EDCS_Classification_Code)1224)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> of relatively low <<TERRAIN_ELEVATION>>
 *     that is completely surrounded by another <TERRAIN_SURFACE_REGION> of
 *     higher <<TERRAIN_ELEVATION>>; a terrain depression.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TERRAIN_DEPRESSION ((EDCS_Classification_Code)1225)

/*
 * Definition:
 *     A <PROPERTY_SET> describing <<TERRAIN_ELEVATION>>s.
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY, PROPERTY_SET
 */
#define ECC_TERRAIN_ELEVATION_PROPERTY_SET ((EDCS_Classification_Code)1226)

/*
 * Definition:
 *     A <REGION> of fill that augments a <TERRAIN_SURFACE_REGION>; a terrain
 *     fill.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TERRAIN_FILL ((EDCS_Classification_Code)1227)

/*
 * Definition:
 *     A configuration of <TERRAIN> and/or associated <STRUCTURE>s that
 *     impedes the movement of <GROUND_VEHICLE>s and pedestrian traffic; a
 *     terrain obstacle.
 *
 * Group Membership: LAND_TRNSP, PHYSIOGRAPHY, TRNSP
 */
#define ECC_TERRAIN_OBSTACLE ((EDCS_Classification_Code)1228)

/*
 * Definition:
 *     An <EXCAVATION> where gravel, <SAND>, and/or clay are removed for use
 *     elsewhere; a terrain pit.
 *
 * Group Membership: INDUSTRY, PHYSIOGRAPHY, USAGE_REGION
 */
#define ECC_TERRAIN_PIT ((EDCS_Classification_Code)1229)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> that is comparatively flat; a terrain plain.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TERRAIN_PLAIN ((EDCS_Classification_Code)1230)

/*
 * Definition:
 *     A <TRACT> that is significantly longer in one dimension than the
 *     other; a terrain strip [SOED, "strip", 2].
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TERRAIN_STRIP ((EDCS_Classification_Code)1231)

/*
 * Definition:
 *     An <OBJECT> located on the <TERRAIN>. EXAMPLE Man-made <STRUCTURE>.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_TERRAIN_SURFACE_OBJECT ((EDCS_Classification_Code)1232)

/*
 * Definition:
 *     A <REGION> of <TERRAIN>, especially one distinguished by natural
 *     features, climate, fauna or flora; a terrain surface region [SOED,
 *     "region", 1].
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TERRAIN_SURFACE_REGION ((EDCS_Classification_Code)1233)

/*
 * Definition:
 *     An <ABATIS> blocking movement on a <LAND_TRANSPORTATION_ROUTE>.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define ECC_TERRAIN_TRANSPORTATION_ABATIS ((EDCS_Classification_Code)1234)

/*
 * Definition:
 *     A sunken or cut passage along a <LAND_TRANSPORTATION_ROUTE> in
 *     <MOUNTAINOUS_REGION>s constructed to protect <GROUND_VEHICLE>s from
 *     the weather; a terrain transportation gallery. A series of
 *     <APERTURE>s may be present on one side for light or ventilation.
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_TERRAIN_TRANSPORTATION_GALLERY ((EDCS_Classification_Code)1235)

/*
 * Definition:
 *     A surveyed reference track marking the <CENTRE_LINE> of a marine test
 *     range; a test reference track. <VESSEL>s undergoing testing must
 *     maintain position along this track.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, SURVEY, TRNSP
 */
#define ECC_TEST_REFERENCE_TRACK ((EDCS_Classification_Code)1236)

/*
 * Definition:
 *     A <SITE> for the testing of technical products and <EQUIPMENT>; a test
 *     site.
 *
 * Group Membership: INDUSTRY, USAGE_REGION
 */
#define ECC_TEST_SITE ((EDCS_Classification_Code)1237)

/*
 * Definition:
 *     A <BUILDING>, <ROOM>, or outdoor <STRUCTURE> used for the presentation
 *     of plays, films, or other dramatic performances; a theatre [AHD,
 *     "theater", 1].
 *
 * Group Membership: BUILDING_COMPONENT, RECREATION, SHELTER
 */
#define ECC_THEATRE ((EDCS_Classification_Code)1238)

/*
 * Definition:
 *     A <LINE> of known <DIRECTION> from a fixed <LOCATION> that may be used
 *     to determine accurate positions of a <VESSEL> on certain test ranges;
 *     a theodolite line.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_THEODOLITE_LINE ((EDCS_Classification_Code)1239)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the thermal properties of the <MATERIAL>s
 *     composing an <OBJECT>.
 *
 * Group Membership: MATERIAL, PROPERTY_SET, TEMPERATURE
 */
#define ECC_THERMAL_MATERIAL_PROPERTY_SET ((EDCS_Classification_Code)1240)

/*
 * Definition:
 *     A storm with thunder and <LIGHTNING> produced by electrically charged
 *     cumulonimbus <CLOUD>s and usually accompanied by heavy <RAIN> and/or
 *     <HAIL>; a thunderstorm.
 *
 * Group Membership: ATMOSPHERE, EM_PHENOMENON
 */
#define ECC_THUNDERSTORM ((EDCS_Classification_Code)1241)

/*
 * Definition:
 *     A <WATERBODY_SHELTER_BASIN> affected by tidal forces in which <WATER>
 *     can be kept at a desired level by means of a <MARINE_GATE>; a tidal
 *     basin.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, HYDROLOGY, SHELTER, TRNSP, WATERBODY_SURFACE
 */
#define ECC_TIDAL_BASIN ((EDCS_Classification_Code)1242)

/*
 * Definition:
 *     A <WATERBODY> where the level normally fluctuates with the <TIDE>;
 *     tidal water or non-inland water.
 *
 * Group Membership: HYDROLOGY, WATERBODY_SURFACE
 */
#define ECC_TIDAL_WATER ((EDCS_Classification_Code)1243)

/*
 * Definition:
 *     The alternate rising and falling of a <WATERBODY_SURFACE> due to the
 *     gravitational attraction of the <MOON>, <SUN>, or other
 *     <CELESTIAL_BODY>s; tide [SOED, "tide", II.7].
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_TIDE ((EDCS_Classification_Code)1244)

/*
 * Definition:
 *     A <LOCATION> for which tabulated tidal stream data are given; a tide
 *     data point.
 *
 * Group Membership: LOCATION, WATERBODY_SURFACE
 */
#define ECC_TIDE_DATA_POINT ((EDCS_Classification_Code)1245)

/*
 * Definition:
 *     A <DEVICE> for measuring the <<TIDE_LEVEL>>; a tide gauge.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, WATERBODY_SURFACE
 */
#define ECC_TIDE_GAUGE ((EDCS_Classification_Code)1246)

/*
 * Definition:
 *     A <HYDROGRAPHIC_LOCK> situated between a <WATERBODY_SHELTER_BASIN> or
 *     <CANAL> and tidewater to maintain the <WATER> at a desired level as
 *     the <<TIDE_LEVEL>> changes; a tide lock or guard lock.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP, WATERBODY_SURFACE
 */
#define ECC_TIDE_LOCK ((EDCS_Classification_Code)1247)

/*
 * Definition:
 *     A <WATERBODY_REGION> where small <WATER_WAVE>s are formed on the
 *     <WATERBODY_SURFACE> by the meeting of opposing tidal <WATER_CURRENT>s
 *     or by a tidal <WATER_CURRENT> crossing an irregular
 *     <WATERBODY_FLOOR>; a tide rip region.
 *
 * Group Membership: HYDROLOGY, WATERBODY_SURFACE
 */
#define ECC_TIDE_RIP_REGION ((EDCS_Classification_Code)1248)

/*
 * Definition:
 *     A natural <WATERCOURSE> in intertidal <REGION>s where <WATER> flows
 *     during the rise and fall of the <TIDE>; a tideway.
 *
 * Group Membership: HYDROLOGY, WATERBODY_SURFACE
 */
#define ECC_TIDEWAY ((EDCS_Classification_Code)1249)

/*
 * Definition:
 *     An open <TRACT> for the storage of wooden lumber and timbers; a timber
 *     yard.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER, USAGE_REGION
 */
#define ECC_TIMBER_YARD ((EDCS_Classification_Code)1250)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <OBJECT>s with EDCS Attributes that are analyzed
 *     at a common base time.
 *
 * Group Membership: ABSTRACT_OBJECT, TIME
 */
#define ECC_TIME_ANALYSIS_BASE_SET ((EDCS_Classification_Code)1251)

/*
 * Definition:
 *     A <NON_EMPTY_SET> of <OBJECT>s with EDCS Attributes that are
 *     forecasted at a time offset from a <TIME_ANALYSIS_BASE_SET> time.
 *
 * Group Membership: ABSTRACT_OBJECT, TIME
 */
#define ECC_TIME_FORECAST_TAU_SET ((EDCS_Classification_Code)1252)

/*
 * Definition:
 *     A characteristic shape secured at the top of a <BUOY> or <BEACON> to
 *     aid in its identification; a topmark.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_TOPMARK ((EDCS_Classification_Code)1253)

/*
 * Definition:
 *     Towed <FIELD_ARTILLERY>.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_TOWED_ARTILLERY ((EDCS_Classification_Code)1254)

/*
 * Definition:
 *     A <VEHICLE> towed by another.
 *
 * Group Membership: TRNSP, VEHICLE
 */
#define ECC_TOWED_VEHICLE ((EDCS_Classification_Code)1255)

/*
 * Definition:
 *     A relatively tall, narrow <STRUCTURE>, which is usually of square,
 *     circular, or rectangular cross-section, that may either stand alone
 *     or may form part of another <STRUCTURE>; a tower.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_TOWER ((EDCS_Classification_Code)1256)

/*
 * Definition:
 *     A concentration of <DWELLING>s, <COMMERCIAL_BUILDING>s,
 *     <INDUSTRIAL_BUILDING>s, and other <STRUCTURE>s where <HUMAN>s have
 *     settled that is larger than a <SETTLEMENT> and usually smaller than a
 *     <CITY> and/or <BUILT_UP_REGION>; a town.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_TOWN ((EDCS_Classification_Code)1257)

/*
 * Definition:
 *     The <MUNICIPAL_HALL> of a <TOWN>.
 *
 * Group Membership: ADMINISTRATION, SHELTER
 */
#define ECC_TOWN_HALL ((EDCS_Classification_Code)1258)

/*
 * Definition:
 *     The path of marine travel as drawn on a <MAP> together with the
 *     <SOUNDING>s and related information collected along that path; a
 *     track line.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, SURVEY, TRNSP
 */
#define ECC_TRACK_LINE ((EDCS_Classification_Code)1259)

/*
 * Definition:
 *     A <WATERBODY_SURFACE_REGION> of horizontal depth coverage recorded by
 *     sonar array <SYSTEM>s; a track swath.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_SURFACE
 */
#define ECC_TRACK_SWATH ((EDCS_Classification_Code)1260)

/*
 * Definition:
 *     A <REGION> of <LAND>; a tract.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TRACT ((EDCS_Classification_Code)1261)

/*
 * Definition:
 *     A <SITE> occupied for purposes of trade, especially in a remote and/or
 *     unsettled <REGION>; a trading post [SOED, "trading post"].
 *
 * Group Membership: INDUSTRY, USAGE_REGION
 */
#define ECC_TRADING_POST ((EDCS_Classification_Code)1262)

/*
 * Definition:
 *     A concentration of simple <DWELLING>s, which are generally <HUT>s,
 *     that are not usually of substantial construction; a traditional
 *     settlement.
 *
 * Group Membership: SHELTER, USAGE_REGION
 */
#define ECC_TRADITIONAL_SETTLEMENT ((EDCS_Classification_Code)1263)

/*
 * Definition:
 *     A measure for organizing a <TRANSPORTATION_ROUTE> that separates
 *     opposing streams of <VESSEL>s by appropriate means, including the
 *     establishment of <ROUTE_LANE>s; a traffic separation scheme.
 *
 * Group Membership: TRNSP
 */
#define ECC_TRAFFIC_SEPARATION_SCHEME ((EDCS_Classification_Code)1264)

/*
 * Definition:
 *     A path on <LAND> worn by the passage of <ANIMAL>s; a trail.
 *
 * Group Membership: ANIMAL, LAND_TRNSP, LIVING_ORGANISM, TRNSP
 */
#define ECC_TRAIL ((EDCS_Classification_Code)1265)

/*
 * Definition:
 *     A number of <RAIL_WAGON>s coupled together, usually including the
 *     <LOCOMOTIVE_ENGINE> by which they are drawn; a train [SOED, "train",
 *     13].
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_TRAIN ((EDCS_Classification_Code)1266)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed or designated for flight training
 *     operations.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_TRAINER_WINGED_AIRCRAFT ((EDCS_Classification_Code)1267)

/*
 * Definition:
 *     A <BUILDING> used exclusively for training of military, police, fire,
 *     and/or rescue <PERSONNEL>; a training building.
 *
 * Group Membership: INFRASTRUCTURE, MILITARY_SCIENCE, SHELTER
 */
#define ECC_TRAINING_BUILDING ((EDCS_Classification_Code)1268)

/*
 * Definition:
 *     A <FACILITY> including one or more <TRAINING_BUILDING>s; a training
 *     facility.
 *
 * Group Membership: INFRASTRUCTURE, MILITARY_SCIENCE, SHELTER, USAGE_REGION
 */
#define ECC_TRAINING_FACILITY ((EDCS_Classification_Code)1269)

/*
 * Definition:
 *     A station that is equipped for radio and/or television transmission.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_TRANSMISSION_STATION ((EDCS_Classification_Code)1270)

/*
 * Definition:
 *     A <HELICOPTER> designed and/or designated to transport <CARGO>,
 *     <PERSONNEL>, or other <MATERIAL>s.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_TRANSPORT_HELICOPTER ((EDCS_Classification_Code)1271)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed and/or designated to transport <CARGO>,
 *     <PERSONNEL>, or other <MATERIAL>s.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_TRANSPORT_WINGED_AIRCRAFT ((EDCS_Classification_Code)1272)

/*
 * Definition:
 *     A massive assemblage of <MATERIAL>, usually in the form of concrete
 *     blocks and/or cylinders, positioned alongside (a <ROLLING_BLOCK>) or
 *     above (a <DROP_GATE>) a <LAND_TRANSPORTATION_ROUTE>, ready to be
 *     activated as a potential <BARRIER> to an advancing enemy ground
 *     force; a transportation block.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define ECC_TRANSPORTATION_BLOCK ((EDCS_Classification_Code)1273)

/*
 * Definition:
 *     A <BUILDING> intended to facilitate the transportation of <HUMAN>s
 *     and/or <MATERIAL>s.
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP
 */
#define ECC_TRANSPORTATION_BUILDING ((EDCS_Classification_Code)1274)

/*
 * Definition:
 *     A <FACILITY> including one or more <TRANSPORTATION_BUILDING>s.
 *
 * Group Membership: LAND_TRNSP, SHELTER, TRNSP, USAGE_REGION
 */
#define ECC_TRANSPORTATION_FACILITY ((EDCS_Classification_Code)1275)

/*
 * Definition:
 *     A <ROUTE> used for transportation.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_TRANSPORTATION_ROUTE ((EDCS_Classification_Code)1276)

/*
 * Definition:
 *     A station that serves as a stopping place along a
 *     <TRANSPORTATION_ROUTE>; a transportation station.
 *
 * Group Membership: TRNSP
 */
#define ECC_TRANSPORTATION_STATION ((EDCS_Classification_Code)1277)

/*
 * Definition:
 *     A <DOOR> or hatch that is flush with a <SURFACE> and located in a
 *     <FLOOR>, on a <ROOF>, or in a <ROOM_CEILING>; a trapdoor [SOED,
 *     "trapdoor", 1].
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_TRAPDOOR ((EDCS_Classification_Code)1278)

/*
 * Definition:
 *     A woody-perennial <PLANT> that has a self-supporting main stem or
 *     trunk and a definite crown; a tree or tree-like plant.
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_TREE ((EDCS_Classification_Code)1279)

/*
 * Definition:
 *     A <TRACT> on which <TREE>s have been blown down or otherwise levelled;
 *     tree blowdown.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_TREE_BLOWDOWN ((EDCS_Classification_Code)1280)

/*
 * Definition:
 *     A relatively linear arrangement of <TREE>s; a tree line [SOED, "tree
 *     line", b].
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_TREE_LINE ((EDCS_Classification_Code)1281)

/*
 * Definition:
 *     A <TRACT> covered by a <NON_EMPTY_SET> of <TREE>s; a treed tract.
 *     EXAMPLES Copse, thicket, stand of <TREE>s.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_TREED_TRACT ((EDCS_Classification_Code)1282)

/*
 * Definition:
 *     A long and narrow <EXCAVATION> in the <TERRAIN>; a trench [SOED,
 *     "trench", 2.a] or a ditch.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_TRENCH ((EDCS_Classification_Code)1283)

/*
 * Definition:
 *     A non-frontal, synoptic-scale <CYCLONE> originating over a tropical or
 *     sub-tropical <WATERBODY> with organized convection and definite
 *     cyclonic surface <WIND> circulation; a tropical cyclone.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_TROPICAL_CYCLONE ((EDCS_Classification_Code)1284)

/*
 * Definition:
 *     The <BOUNDARY> between the <TROPOSPHERE> and the <STRATOSPHERE> where
 *     an abrupt change in the <<TEMPERATURE_LAPSE_RATE>> usually occurs;
 *     the tropopause.
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, LOCATION, TEMPERATURE
 */
#define ECC_TROPOPAUSE ((EDCS_Classification_Code)1285)

/*
 * Definition:
 *     The <ATMOSPHERE_REGION> of the <EARTH>, extending from the
 *     <PLANETARY_SURFACE> to the <TROPOPAUSE>; the troposphere.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_TROPOSPHERE ((EDCS_Classification_Code)1286)

/*
 * Definition:
 *     A large, strong <MOTOR_VEHICLE> for carrying <CARGO>, <HUMAN>s, and/or
 *     other <MATERIAL>s; a truck [SOED, "truck", 3.b].
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_TRUCK ((EDCS_Classification_Code)1287)

/*
 * Definition:
 *     A <MARINE_OBJECT> that is composed of a deep-water <MARINE_ROUTE> and
 *     the related <NAVIGATION_MARK_AFLOAT>s and/or <NAVIGATION_MARK_FIXED>s
 *     that are placed to delimit specific <TRANSPORTATION_ROUTE>s for
 *     separating traffic within the <MARINE_ROUTE>; a traffic separation
 *     scheme system.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_TSS_SYSTEM ((EDCS_Classification_Code)1288)

/*
 * Definition:
 *     A long-period <WATER_WAVE> produced by a submarine earthquake and/or
 *     volcanic eruption; a tsunami.
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_TSUNAMI ((EDCS_Classification_Code)1289)

/*
 * Definition:
 *     A <WATERBODY_REGION> where nets used for catching tuna have been
 *     deployed.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, USAGE_REGION
 */
#define ECC_TUNA_NETTING_REGION ((EDCS_Classification_Code)1290)

/*
 * Definition:
 *     A prairie-like arctic and sub-arctic climatic <TRACT> that sustains a
 *     growth of low <VEGETATION>; tundra.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_TUNDRA ((EDCS_Classification_Code)1291)

/*
 * Definition:
 *     A passage under the <TERRAIN> that is open at both ends and usually
 *     contains a <LAND_TRANSPORTATION_ROUTE>; a tunnel.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_TUNNEL ((EDCS_Classification_Code)1292)

/*
 * Definition:
 *     A <TUNNEL> for the purpose of sheltering <MATERIAL>s, <EQUIPMENT>,
 *     and/or <HUMAN>s; a tunnel shelter.
 *
 * Group Membership: SHELTER
 */
#define ECC_TUNNEL_SHELTER ((EDCS_Classification_Code)1293)

/*
 * Definition:
 *     A <WATERBODY_REGION> with increased <<WATER_DIFFUSE_TURBIDITY>>; a
 *     turbid region.
 *
 * Group Membership: WATERBODY_STATE
 */
#define ECC_TURBID_REGION ((EDCS_Classification_Code)1294)

/*
 * Definition:
 *     An enlargement of a <WATER_CHANNEL> used for turning <VESSEL>s; a
 *     turning basin or manoeuvering basin.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_TURNING_BASIN ((EDCS_Classification_Code)1295)

/*
 * Definition:
 *     A <TROPICAL_CYCLONE> with maximum sustained <<WIND_SPEED>>s of 33
 *     metres per second or greater near the centre and that is located in
 *     the western North Pacific; a typhoon.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_TYPHOON ((EDCS_Classification_Code)1296)

/*
 * Definition:
 *     Any <AIRSPACE> in which air traffic control service is not available;
 *     an uncontrolled airspace.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_UNCONTROLLED_AIRSPACE ((EDCS_Classification_Code)1297)

/*
 * Definition:
 *     A <BUNKER> that is used as a command and control centre or for
 *     encampment; an underground bunker.
 *
 * Group Membership: SHELTER
 */
#define ECC_UNDERGROUND_BUNKER ((EDCS_Classification_Code)1298)

/*
 * Definition:
 *     A <DWELLING> under the <TERRAIN>; an underground dwelling.
 *
 * Group Membership: SHELTER
 */
#define ECC_UNDERGROUND_DWELLING ((EDCS_Classification_Code)1299)

/*
 * Definition:
 *     A <TUNNEL> under the <TERRAIN> through which a metropolitan electric
 *     <RAILWAY> travels; an underground railway.
 *
 * Group Membership: EM_PHENOMENON, LAND_TRNSP, TRNSP
 */
#define ECC_UNDERGROUND_RAILWAY ((EDCS_Classification_Code)1300)

/*
 * Definition:
 *     <WATER> situated under the <TERRAIN> but reachable by <WELL>s;
 *     underground water or phreatic water.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_UNDERGROUND_WATER ((EDCS_Classification_Code)1301)

/*
 * Definition:
 *     A <TRACT> that was previously undermined through mining activities and
 *     that either has already partly subsided and/or that is in the process
 *     of subsiding; undermined land.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_UNDERMINED_LAND ((EDCS_Classification_Code)1302)

/*
 * Definition:
 *     A <DEVICE> located in a <WATERBODY> and used to provide two-way
 *     communication; an underwater communication device. EXAMPLE
 *     <ACOUSTIC_TRANSDUCER>.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, INFRASTRUCTURE, TRNSP
 */
#define ECC_UNDERWATER_COMMUNICATION_DEVICE ((EDCS_Classification_Code)1303)

/*
 * Definition:
 *     An <UNDERWATER_OBJECT> known to be hazardous to navigation on
 *     <WATERBODY_SURFACE>s; an underwater hazard.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_UNDERWATER_HAZARD ((EDCS_Classification_Code)1304)

/*
 * Definition:
 *     An <OBJECT> under a <WATERBODY_SURFACE>. EXAMPLE <MARINE_WRECK>.
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_UNDERWATER_OBJECT ((EDCS_Classification_Code)1305)

/*
 * Definition:
 *     A <REGION> under a <WATERBODY_SURFACE>.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_UNDERWATER_REGION ((EDCS_Classification_Code)1306)

/*
 * Definition:
 *     A winged <AIRCRAFT> operating without a pilot onboard; an unmanned
 *     aircraft.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_UNMANNED_WINGED_AIRCRAFT ((EDCS_Classification_Code)1307)

/*
 * Definition:
 *     A formally recognized survey or reference <LOCATION> that is not
 *     represented by a physical <BOUNDARY_MONUMENT> and/or <BENCHMARK>; an
 *     unmonumented point.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_UNMONUMENTED_POINT ((EDCS_Classification_Code)1308)

/*
 * Definition:
 *     A <TRACT> with little (less than 5 percent) or no <VEGETATION>;
 *     unvegetated land.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_UNVEGETATED_LAND ((EDCS_Classification_Code)1309)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is seventh in distance from the
 *     <SUN>, with an orbital mean <<RADIUS>> of approximately 2 875,0
 *     million kilometres; Uranus.
 *
 * Group Membership: SPACE
 */
#define ECC_URANUS ((EDCS_Classification_Code)1310)

/*
 * Definition:
 *     A <HELICOPTER> designed or designated for various utility operations.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_UTILITY_HELICOPTER ((EDCS_Classification_Code)1311)

/*
 * Definition:
 *     A <WATER_SURFACE_VESSEL> designed or designated for various utility
 *     operations.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_UTILITY_VESSEL ((EDCS_Classification_Code)1312)

/*
 * Definition:
 *     A winged <AIRCRAFT> designed or designated for utility, non-transport
 *     purposes.
 *
 * Group Membership: AIR_TRNSP, TRNSP, VEHICLE
 */
#define ECC_UTILITY_WINGED_AIRCRAFT ((EDCS_Classification_Code)1313)

/*
 * Definition:
 *     A <LINE> representing of the lowest part of a <VALLEY_REGION>; a
 *     valley bottom line.
 *
 * Group Membership: LOCATION, PHYSIOGRAPHY
 */
#define ECC_VALLEY_BOTTOM_LINE ((EDCS_Classification_Code)1314)

/*
 * Definition:
 *     A low-lying <TERRAIN_SURFACE_REGION> located between <HILL>s and/or
 *     <MOUNTAIN>s and often having a <RIVER> flowing through it; a valley
 *     region.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_VALLEY_REGION ((EDCS_Classification_Code)1315)

/*
 * Definition:
 *     A <LINE> connecting <LOCATION>s having a varying relative vertical
 *     offset from the <TERRAIN>; a variable displacement line.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_VARIABLE_DISPLACEMENT_LINE ((EDCS_Classification_Code)1316)

/*
 * Definition:
 *     A <BUILDING> that houses <EQUIPMENT> that releases the oils of
 *     vegetable seeds by pressing and/or grinding; a vegetable oil mill.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, LIVING_ORGANISM, PLANT, SHELTER
 */
#define ECC_VEGETABLE_OIL_MILL ((EDCS_Classification_Code)1317)

/*
 * Definition:
 *     A saturated <TRACT> that is at times covered with <WATER> and that
 *     supports <VEGETATION> that may include <TREE>s; vegetated saturated
 *     land.
 *
 * Group Membership: HYDROLOGY, LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_VEGETATED_SATURATED_LAND ((EDCS_Classification_Code)1318)

/*
 * Definition:
 *     The <PLANT>s in a given <REGION>; vegetation [AHD, "vegetation", 2].
 *
 * Group Membership: LIVING_ORGANISM, PLANT
 */
#define ECC_VEGETATION ((EDCS_Classification_Code)1319)

/*
 * Definition:
 *     <EQUIPMENT> used to provide a means of conveyance for transporting
 *     <MATERIAL>s, <EQUIPMENT>, and/or <HUMAN>s; a vehicle.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP, VEHICLE
 */
#define ECC_VEHICLE ((EDCS_Classification_Code)1320)

/*
 * Definition:
 *     An obstruction placed across a <LAND_TRANSPORTATION_ROUTE> to prevent
 *     the passage of <VEHICLE>s; a vehicle barrier.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_VEHICLE_BARRIER ((EDCS_Classification_Code)1321)

/*
 * Definition:
 *     A <TRACT> used for storing and/or parking <VEHICLE>s and/or <VESSEL>s;
 *     a vehicle lot.
 *
 * Group Membership: LAND_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_VEHICLE_LOT ((EDCS_Classification_Code)1322)

/*
 * Definition:
 *     <EQUIPMENT>, which is usually located alongside a <ROAD>, that is used
 *     to determine the weight of <GROUND_VEHICLE>s; a scale.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, LAND_TRNSP, TRNSP
 */
#define ECC_VEHICLE_SCALE ((EDCS_Classification_Code)1323)

/*
 * Definition:
 *     An <APERTURE>, generally covered, into a <VENTILATION_DUCT> or
 *     <VENTILATION_SHAFT>.
 *
 * Group Membership: BUILDING_COMPONENT, INFRASTRUCTURE
 */
#define ECC_VENTILATION_APERTURE ((EDCS_Classification_Code)1324)

/*
 * Definition:
 *     A predominantly horizontal duct for the admission of a proper supply
 *     of fresh and/or temperature-controlled <AIR>, especially to a <ROOM>,
 *     <BUILDING>, or other place where the <AIR> readily becomes stagnant
 *     or in need of temperature control; a ventilation duct.
 *
 * Group Membership: BUILDING_COMPONENT, INFRASTRUCTURE, TEMPERATURE
 */
#define ECC_VENTILATION_DUCT ((EDCS_Classification_Code)1325)

/*
 * Definition:
 *     The <WALL> and/or casing of a <VENTILATION_DUCT>.
 *
 * Group Membership: BUILDING_COMPONENT, INFRASTRUCTURE
 */
#define ECC_VENTILATION_DUCT_WALL ((EDCS_Classification_Code)1326)

/*
 * Definition:
 *     A vertical or nearly vertical passageway in a <BUILDING> used for
 *     moving heating, cooling, and/or ventilation <AIR>; a ventilation
 *     shaft.
 *
 * Group Membership: BUILDING_COMPONENT, INFRASTRUCTURE, TEMPERATURE
 */
#define ECC_VENTILATION_SHAFT ((EDCS_Classification_Code)1327)

/*
 * Definition:
 *     The primary <PLANET> of the <SUN> that is second in distance from the
 *     <SUN> with an orbital mean <<RADIUS>> of approximately 108,2 million
 *     kilometres; Venus.
 *
 * Group Membership: SPACE
 */
#define ECC_VENUS ((EDCS_Classification_Code)1328)

/*
 * Definition:
 *     An <ANIMAL> of the subphylum Vertebrata, comprising chordate animals
 *     with a bony and/or cartilaginous skeleton, skull, and spinal column;
 *     a vertebrate [SOED, "vertebrate", A]. EXAMPLES <FISH>, <AMPHIBIAN>,
 *     <REPTILE>, <BIRD>, <MAMMAL>.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_VERTEBRATE ((EDCS_Classification_Code)1329)

/*
 * Definition:
 *     A datum (see I19111, 4.9) to which gravity-related elevations and
 *     heights are referenced; often taken to correspond to MSL; the
 *     vertical datum.
 *
 * Group Membership: LOCATION, SURVEY
 */
#define ECC_VERTICAL_DATUM ((EDCS_Classification_Code)1330)

/*
 * Definition:
 *     A <VEHICLE> capable of operation on the <WATERBODY_SURFACE>, but which
 *     may also be able to operate beneath it; a vessel.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_VESSEL ((EDCS_Classification_Code)1331)

/*
 * Definition:
 *     An enclosure containing <WATER> for a dock for <VESSEL>s; a vessel
 *     basin.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_VESSEL_BASIN ((EDCS_Classification_Code)1332)

/*
 * Definition:
 *     The <LOCATION> where a <VESSEL> lies when secured to a <PIER>,
 *     <WHARF>, and/or <MOORING_DOLPHIN>; may also be a designated
 *     <LOCATION> away from the <COASTLINE>; a vessel berth.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, LOCATION, TRNSP
 */
#define ECC_VESSEL_BERTH ((EDCS_Classification_Code)1333)

/*
 * Definition:
 *     A defined <WATERBODY_REGION> intended for use as a long-term
 *     <ANCHORAGE> and storage for <VESSEL>s; a vessel storage anchorage.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, HYDROLOGY, TRNSP, USAGE_REGION
 */
#define ECC_VESSEL_STORAGE_ANCHORAGE ((EDCS_Classification_Code)1334)

/*
 * Definition:
 *     A <STRUCTURE> consisting of a series of arches or <TOWER>s supporting
 *     a <LAND_TRANSPORTATION_ROUTE> across a <TERRAIN_DEPRESSION>; a
 *     viaduct.
 *
 * Group Membership: LAND_TRNSP, SUPPORT_STRUCTURE, TRNSP
 */
#define ECC_VIADUCT ((EDCS_Classification_Code)1335)

/*
 * Definition:
 *     A <TRACT> covered by the systematic planting of grape vines; a
 *     vineyard.
 *
 * Group Membership: AGRICULTURE, LIVING_ORGANISM, PLANT, USAGE_REGION
 */
#define ECC_VINEYARD ((EDCS_Classification_Code)1336)

/*
 * Definition:
 *     A data collection <REGION> lacking suitable source coverage and/or
 *     where data is not required; a void collection.
 *
 * Group Membership: SURVEY
 */
#define ECC_VOID_COLLECTION ((EDCS_Classification_Code)1337)

/*
 * Definition:
 *     A mass of igneous <ROCK> that has intruded upwards through strata,
 *     sometimes showing as a <RIDGE>.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_VOLCANIC_DYKE ((EDCS_Classification_Code)1338)

/*
 * Definition:
 *     A <MOUNTAIN> or <HILL>, often conical, formed around a vent in the
 *     <TERRAIN> through which molten <ROCK>, ash, and/or gases are or have
 *     been expelled; a volcano.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_VOLCANO ((EDCS_Classification_Code)1339)

/*
 * Definition:
 *     The dry bed of an intermittent <RIVER>, often with steep sides or
 *     located at the bottom of a <TERRAIN_CHANNEL>; a wadi, a wash, or an
 *     arroyo.
 *
 * Group Membership: HYDROLOGY, PHYSIOGRAPHY
 */
#define ECC_WADI ((EDCS_Classification_Code)1340)

/*
 * Definition:
 *     The representation of one or more <WADI>s; a wadi centre-line or wadi
 *     nexus.
 *
 * Group Membership: HYDROLOGY, LOCATION, PHYSIOGRAPHY
 */
#define ECC_WADI_NEXUS ((EDCS_Classification_Code)1341)

/*
 * Definition:
 *     A solid man-made <BARRIER> of generally heavy <MATERIAL> used as an
 *     enclosure, <BOUNDARY>, or for protection; a wall.
 *
 * Group Membership: DEMARCATION, SHELTER, SUPPORT_STRUCTURE
 */
#define ECC_WALL ((EDCS_Classification_Code)1342)

/*
 * Definition:
 *     A small <APERTURE> in a <WALL> in a defended <STRUCTURE> created for
 *     military purposes, typically about 20 centimetres in diameter; a wall
 *     loophole.
 *
 * Group Membership: MILITARY_SCIENCE, SUPPORT_STRUCTURE
 */
#define ECC_WALL_LOOPHOLE ((EDCS_Classification_Code)1343)

/*
 * Definition:
 *     A <BUILDING> in which goods or merchandise are stored; a warehouse
 *     [AHD, "warehouse", 1].
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, SHELTER
 */
#define ECC_WAREHOUSE ((EDCS_Classification_Code)1344)

/*
 * Definition:
 *     An <ATMOSPHERIC_FRONT> between warm and cold <AIR_MASS>s that moves so
 *     that the warmer <AIR> replaces the colder <AIR>; a warm front.
 *
 * Group Membership: ATMOSPHERE, DEMARCATION, LOCATION, TEMPERATURE
 */
#define ECC_WARM_FRONT ((EDCS_Classification_Code)1345)

/*
 * Definition:
 *     A <FACILITY> where waste is processed through chemical, physical,
 *     biological, or thermal procedures or a combination of those
 *     procedures; a waste processing facility.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_WASTE_PROCESSING_FACILITY ((EDCS_Classification_Code)1346)

/*
 * Definition:
 *     A compound of hydrogen and oxygen, chemical formula H[sub(2)]O [SOED,
 *     "water", 1.a].
 *
 * Group Membership: MATERIAL
 */
#define ECC_WATER ((EDCS_Classification_Code)1347)

/*
 * Definition:
 *     A particular, designated body of <WATER> forming a physiographic
 *     <OBJECT> [SOED, "waterbody"]. EXAMPLES <LAKE>, <OCEAN>, <SEA>,
 *     <RIVER>.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_WATERBODY ((EDCS_Classification_Code)1348)

/*
 * Definition:
 *     A <WATERBODY_PROPERTY_SET> describing acoustic-related properties.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, PROPERTY_SET, WATERBODY_STATE
 */
#define ECC_WATERBODY_ACOUSTIC_PROPERTY_SET ((EDCS_Classification_Code)1349)

/*
 * Definition:
 *     An <ACOUSTIC_SIGNATURE_PROPERTY_SET> describing a signal source in a
 *     <WATERBODY>.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, PROPERTY_SET
 */
#define ECC_WATERBODY_ACOUSTIC_SIGNATURE_PROPERTY_SET ((EDCS_Classification_Code)1350)

/*
 * Definition:
 *     A <WATERBODY_PROPERTY_SET> describing acoustic target strength
 *     properties (for example: the amount of signal excess added to the
 *     return energy of an active sonar emission based on the reflective
 *     characteristics of an <OBJECT>).
 *
 * Group Membership: ACOUSTIC_PHENOMENON, PROPERTY_SET, WATERBODY_STATE
 */
#define ECC_WATERBODY_ACOUSTIC_TARGET_STRENGTH_PROPERTY_SET ((EDCS_Classification_Code)1351)

/*
 * Definition:
 *     The raised or sloping bank of <LAND> adjacent to a
 *     <LAND_WATER_BOUNDARY>; a waterbody bank.
 *
 * Group Membership: DEMARCATION, LOCATION, PHYSIOGRAPHY
 */
#define ECC_WATERBODY_BANK ((EDCS_Classification_Code)1352)

/*
 * Definition:
 *     A delimited, principal division of a <WATERBODY>; a waterbody basin.
 *     EXAMPLE <OCEAN_BASIN>.
 *
 * Group Membership: HYDROLOGY, PHYSIOGRAPHY
 */
#define ECC_WATERBODY_BASIN ((EDCS_Classification_Code)1353)

/*
 * Definition:
 *     A <WATERBODY_PROPERTY_SET> describing the <<DEPTH_OF_WATERBODY_FLOOR>>
 *     with respect to a <SURFACE_DATUM>; a waterbody bathymetry property
 *     set.
 *
 * Group Membership: PROPERTY_SET, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_BATHYMETRY_PROPERTY_SET ((EDCS_Classification_Code)1354)

/*
 * Definition:
 *     A sound source of a biological nature in a <WATERBODY>. EXAMPLES
 *     <FISH_SCHOOL>, <WHALE_POD>.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, LIVING_ORGANISM
 */
#define ECC_WATERBODY_BIOLOGIC_SOUND_SOURCE ((EDCS_Classification_Code)1355)

/*
 * Definition:
 *     A floating <BARRIER> used to protect a <RIVER> or the mouth of a
 *     <HARBOUR> or to create a sheltered <WATERBODY_REGION> for storage
 *     purposes; a waterbody boom.
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_ARTEFACT, SHELTER, WATERBODY_SURFACE
 */
#define ECC_WATERBODY_BOOM ((EDCS_Classification_Code)1356)

/*
 * Definition:
 *     A large <WATERBODY_REGION> containing a <WATER_CURRENT> that is
 *     relatively homogenous with respect to <<WATERBODY_TEMPERATURE>> or
 *     <<PRACTICAL_SALINITY>> and that differs from that of the adjacent
 *     <REGION>s; a waterbody current.
 *
 * Group Membership: HYDROLOGY, TEMPERATURE, WATERBODY_STATE
 */
#define ECC_WATERBODY_CURRENT ((EDCS_Classification_Code)1357)

/*
 * Definition:
 *     An <EDDY> in a <WATERBODY>.
 *
 * Group Membership: HYDROLOGY, WATERBODY_STATE
 */
#define ECC_WATERBODY_EDDY ((EDCS_Classification_Code)1358)

/*
 * Definition:
 *     The floor of a <WATERBODY>.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR ((EDCS_Classification_Code)1359)

/*
 * Definition:
 *     A deep, step-sided <TERRAIN_CHANNEL> in a <WATERBODY_FLOOR> the bottom
 *     of which grades continuously downward; a waterbody floor canyon.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR_CANYON ((EDCS_Classification_Code)1360)

/*
 * Definition:
 *     A significant configuration of <WATERBODY_FLOOR> topography generally
 *     round in shape as viewed from above and of reduced depth at its
 *     centre; a waterbody floor pinnacle.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR_PINNACLE ((EDCS_Classification_Code)1361)

/*
 * Definition:
 *     A <WATERBODY_FLOOR_REGION> identifiable by shared physiographic
 *     characteristics that are markedly in contrast with those in the
 *     adjacent <WATERBODY_FLOOR_REGION>s; a waterbody floor province.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR_PROVINCE ((EDCS_Classification_Code)1362)

/*
 * Definition:
 *     A <REGION> of a <WATERBODY_FLOOR>.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR_REGION ((EDCS_Classification_Code)1363)

/*
 * Definition:
 *     A <RIDGE> with steep sides and either irregular or smooth topography
 *     in a <WATERBODY_FLOOR>, often separating <WATERBODY_BASIN>s; a ridge.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR_RIDGE ((EDCS_Classification_Code)1364)

/*
 * Definition:
 *     A detectable active sonar return signal, from an <OBJECT> on a
 *     <WATERBODY_FLOOR>.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR_SONAR_RETURN ((EDCS_Classification_Code)1365)

/*
 * Definition:
 *     A significant configuration of <WATERBODY_FLOOR> topography.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION ((EDCS_Classification_Code)1366)

/*
 * Definition:
 *     A significant long, narrow, and characteristically very deep and
 *     asymmetrical <TERRAIN_CHANNEL> in a <WATERBODY_FLOOR>, with
 *     relatively steep sides; a trench.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_WATERBODY_FLOOR_TRENCH ((EDCS_Classification_Code)1367)

/*
 * Definition:
 *     A <STRUCTURE> separating portions of a <WATERBODY>; a partition.
 *
 * Group Membership: DEMARCATION, HYDROGRAPHIC_ARTEFACT
 */
#define ECC_WATERBODY_PARTITION ((EDCS_Classification_Code)1368)

/*
 * Definition:
 *     A <PROPERTY_SET> describing a <LOCATION> or <REGION> of a <WATERBODY>.
 *
 * Group Membership: PROPERTY_SET, WATERBODY_STATE
 */
#define ECC_WATERBODY_PROPERTY_SET ((EDCS_Classification_Code)1369)

/*
 * Definition:
 *     A <REGION> of a <WATERBODY>.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_WATERBODY_REGION ((EDCS_Classification_Code)1370)

/*
 * Definition:
 *     A sheltered <WATERBODY> available for port operations and connecting
 *     with another <WATERBODY> (for example: an outer <MARINE_PORT> and/or
 *     a <SEA>) sometimes by means of a <HYDROGRAPHIC_LOCK> or passage; a
 *     waterbody shelter basin.
 *
 * Group Membership: HARBOUR_AND_PORT, HYDROGRAPHIC_TRNSP, HYDROLOGY, SHELTER, TRNSP, USAGE_REGION
 */
#define ECC_WATERBODY_SHELTER_BASIN ((EDCS_Classification_Code)1371)

/*
 * Definition:
 *     A <WATERBODY_PROPERTY_SET> describing shipping-related properties.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, HYDROGRAPHIC_INDUSTRY, INDUSTRY, PROPERTY_SET, TRNSP, WATERBODY_STATE
 */
#define ECC_WATERBODY_SHIPPING_PROPERTY_SET ((EDCS_Classification_Code)1372)

/*
 * Definition:
 *     The <SURFACE> of a <WATERBODY>.
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_WATERBODY_SURFACE ((EDCS_Classification_Code)1373)

/*
 * Definition:
 *     A <REGION> of a <WATERBODY_SURFACE>.
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_WATERBODY_SURFACE_REGION ((EDCS_Classification_Code)1374)

/*
 * Definition:
 *     A <WATERBODY_SURFACE_REGION> that is variable in size and markedly
 *     different in appearance (for example: in colour and/or oiliness) from
 *     adjacent <WATERBODY_SURFACE_REGION>s; a slick.
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_WATERBODY_SURFACE_SLICK ((EDCS_Classification_Code)1375)

/*
 * Definition:
 *     A <WATERBODY_PROPERTY_SET> describing properties related to
 *     <<TEMPERATURE>>.
 *
 * Group Membership: PROPERTY_SET, TEMPERATURE, WATERBODY_STATE
 */
#define ECC_WATERBODY_TEMPERATURE_PROPERTY_SET ((EDCS_Classification_Code)1376)

/*
 * Definition:
 *     That part of a <WATERBODY>, sometimes dredged, that is deep enough for
 *     navigation through a <WATERBODY_SURFACE_REGION> that would otherwise
 *     not be navigable; a water channel. It is usually marked by a single
 *     or double line of <MARINE_AID_TO_NAVIGATION>s.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, HYDROLOGY, TRNSP
 */
#define ECC_WATER_CHANNEL ((EDCS_Classification_Code)1377)

/*
 * Definition:
 *     The <BOUNDARY> delimiting the edge of a <WATER_CHANNEL> plus
 *     associated <NAVIGATION_MARK_AFLOAT>s and/or <NAVIGATION_MARK_FIXED>s;
 *     a water channel edge.
 *
 * Group Membership: DEMARCATION, HYDROGRAPHIC_TRNSP, HYDROLOGY, LOCATION, TRNSP
 */
#define ECC_WATER_CHANNEL_EDGE ((EDCS_Classification_Code)1378)

/*
 * Definition:
 *     A <CURRENT> in a <WATERBODY>.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_WATER_CURRENT ((EDCS_Classification_Code)1379)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the average <<WATER_CURRENT_SPEED>> within
 *     a <REGION> of a <WATERBODY> as a function of time.
 *
 * Group Membership: PROPERTY_SET
 */
#define ECC_WATER_CURRENT_PROPERTY_SET ((EDCS_Classification_Code)1380)

/*
 * Definition:
 *     A <DEVICE> used for the collection of hydrographic and oceanographic
 *     data.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, HYDROGRAPHIC_ARTEFACT
 */
#define ECC_WATER_DATA_COLLECTION_DEVICE ((EDCS_Classification_Code)1381)

/*
 * Definition:
 *     A <STRUCTURE> equipped with water-driven <EQUIPMENT> for grinding
 *     grain into flour or meal; a water driven gristmill.
 *
 * Group Membership: INDUSTRY
 */
#define ECC_WATER_DRIVEN_GRISTMILL ((EDCS_Classification_Code)1382)

/*
 * Definition:
 *     A protected (restricted use) <TERRAIN_SURFACE_REGION> incorporating
 *     <FACILITY>s for the collection of <WATER>, so designated in order to
 *     protect the <WATER> on and beneath the <TERRAIN> from being
 *     contaminated; a water gathering region.
 *
 * Group Membership: HYDROLOGY, INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_WATER_GATHERING_REGION ((EDCS_Classification_Code)1383)

/*
 * Definition:
 *     A <SITE> where <WATER> is taken into a channel or <PIPE> from a
 *     <WATERBODY>, generally to supply an <AQUEDUCT> or
 *     <WATER_TREATMENT_FACILITY>; a water intake.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_WATER_INTAKE ((EDCS_Classification_Code)1384)

/*
 * Definition:
 *     A <TOWER> associated with a <WATER_INTAKE>; a water intake tower.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, INFRASTRUCTURE
 */
#define ECC_WATER_INTAKE_TOWER ((EDCS_Classification_Code)1385)

/*
 * Definition:
 *     A <VESSEL> capable of operation only on a <WATERBODY_SURFACE>; a water
 *     surface vessel. EXAMPLES Barge, boat, ship.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP, VEHICLE
 */
#define ECC_WATER_SURFACE_VESSEL ((EDCS_Classification_Code)1386)

/*
 * Definition:
 *     A <TOWER> supporting an elevated <STORAGE_TANK> of <WATER>; a water
 *     tower.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_WATER_TOWER ((EDCS_Classification_Code)1387)

/*
 * Definition:
 *     A <TRACT> for the treatment of <WATER> that consists of a bed of
 *     <MATERIAL> where <WATER> is aerated or filtered; a water treatment
 *     bed.
 *
 * Group Membership: INFRASTRUCTURE, SURFACE_MATERIAL, USAGE_REGION
 */
#define ECC_WATER_TREATMENT_BED ((EDCS_Classification_Code)1388)

/*
 * Definition:
 *     A <FACILITY> including one or more <WATER_TREATMENT_STRUCTURE>s; a
 *     water treatment facility.
 *
 * Group Membership: INFRASTRUCTURE, USAGE_REGION
 */
#define ECC_WATER_TREATMENT_FACILITY ((EDCS_Classification_Code)1389)

/*
 * Definition:
 *     A <STRUCTURE> containing layers of <MATERIAL> used to filter or aerate
 *     <WATER>; a water treatment structure.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_WATER_TREATMENT_STRUCTURE ((EDCS_Classification_Code)1390)

/*
 * Definition:
 *     A disturbance of <WATER> caused by the interaction of any combination
 *     of <WATER_WAVE>s, <WATER_CURRENT>s, <EDDY>s, tidal streams, <WIND>,
 *     <SHOAL>s, and obstructions; water turbulence.
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_WATER_TURBULENCE ((EDCS_Classification_Code)1391)

/*
 * Definition:
 *     One of a succession of undulations that travel over a
 *     <WATERBODY_SURFACE>; a water wave [SOED, "wave", I.1.a].
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_WATER_WAVE ((EDCS_Classification_Code)1392)

/*
 * Definition:
 *     An artificial or natural channel for the conveyance of <WATER>; a
 *     watercourse.
 *
 * Group Membership: HYDROLOGY, INFRASTRUCTURE
 */
#define ECC_WATERCOURSE ((EDCS_Classification_Code)1393)

/*
 * Definition:
 *     A vertical or nearly vertical descent of a <WATERCOURSE>; a waterfall.
 *
 * Group Membership: HYDROLOGY
 */
#define ECC_WATERFALL ((EDCS_Classification_Code)1394)

/*
 * Definition:
 *     A small natural <TERRAIN_DEPRESSION> in which <WATER> collects,
 *     especially a pool where <NON_HUMAN_ANIMAL>s come to drink; a watering
 *     hole [AHD, "watering hole", 1].
 *
 * Group Membership: ANIMAL, HYDROLOGY
 */
#define ECC_WATERING_HOLE ((EDCS_Classification_Code)1395)

/*
 * Definition:
 *     A <REGION> where supplies of <WATER> can be replenished; a watering
 *     place. EXAMPLES <SPRING>, <WELL> of <WATER>, <WATERING_HOLE>.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_WATERING_PLACE ((EDCS_Classification_Code)1396)

/*
 * Definition:
 *     A <LOCATION> used to define a <ROUTE>; a waypoint.
 *
 * Group Membership: LOCATION, TRNSP
 */
#define ECC_WAYPOINT ((EDCS_Classification_Code)1397)

/*
 * Definition:
 *     <EQUIPMENT> intended to inflict bodily harm, especially one used in
 *     warfare to overcome an enemy and/or repel a hostile attack; a weapon
 *     [SOED, "weapon", 1a].
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_WEAPON ((EDCS_Classification_Code)1398)

/*
 * Definition:
 *     The concealed access <RAMP> or <LAND_TRANSPORTATION_ROUTE> leading
 *     from the exterior of a <WEAPON_FIGHTING_POSITION> to the
 *     <WEAPON_FULL_DEFILADE_POSITION> and then to the
 *     <WEAPON_HULL_DEFILADE_POSITION>; a weapon fighting position access
 *     route.
 *
 * Group Membership: LAND_TRNSP, MILITARY_SCIENCE, TRNSP
 */
#define ECC_WEAPON_FIGHTING_POS_ACCESS_ROUTE ((EDCS_Classification_Code)1399)

/*
 * Definition:
 *     A <FIGHTING_POSITION> designed to accommodate an individual <WEAPON>,
 *     which may be mounted on a <VEHICLE>.
 *
 * Group Membership: MILITARY_SCIENCE, PHYSIOGRAPHY
 */
#define ECC_WEAPON_FIGHTING_POSITION ((EDCS_Classification_Code)1400)

/*
 * Definition:
 *     The <REGION> within a <WEAPON_FIGHTING_POSITION> in which the entire
 *     <WEAPON> is hidden from enemy view and fire; a weapon full defilade
 *     position.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_WEAPON_FULL_DEFILADE_POSITION ((EDCS_Classification_Code)1401)

/*
 * Definition:
 *     The <REGION> within a <WEAPON_FIGHTING_POSITION> in which only the
 *     fighting <COMPONENT> of the <WEAPON> is exposed to enemy fire or
 *     view; a weapon hull defilade position.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_WEAPON_HULL_DEFILADE_POSITION ((EDCS_Classification_Code)1402)

/*
 * Definition:
 *     A <WEAPON> together with all the <EQUIPMENT> (for example: detection
 *     and control apparatus, a launcher, and/or a delivery <VEHICLE>)
 *     required to make use of it; a weapon system [SOED, "weapon system"].
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_WEAPON_SYSTEM ((EDCS_Classification_Code)1403)

/*
 * Definition:
 *     A <FACILITY> designated for the purpose of discharging firearms or
 *     detonating <MUNITION>s; a weapons range, a firing range, or a gunnery
 *     range.
 *
 * Group Membership: MILITARY_SCIENCE, USAGE_REGION
 */
#define ECC_WEAPONS_RANGE ((EDCS_Classification_Code)1404)

/*
 * Definition:
 *     An <OBSERVATION_STATION> where meteorological data are gathered,
 *     recorded, and released; a weather station.
 *
 * Group Membership: BUILDING_COMPONENT, INFRASTRUCTURE, SHELTER
 */
#define ECC_WEATHER_STATION ((EDCS_Classification_Code)1405)

/*
 * Definition:
 *     An <EXCAVATION> drilled or dug into the <TERRAIN> for the extraction
 *     of liquids or gases; a well.
 *
 * Group Membership: INDUSTRY, INFRASTRUCTURE, PHYSIOGRAPHY
 */
#define ECC_WELL ((EDCS_Classification_Code)1406)

/*
 * Definition:
 *     <EQUIPMENT> (for example: casing heads, lowermost and intermediate
 *     tubing heads, Christmas tree equipment with valves and fittings,
 *     and/or casing and tubing hangers) used on the <TERRAIN> to maintain
 *     control of an oil <WELL>; a well-head.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INDUSTRY, INFRASTRUCTURE
 */
#define ECC_WELL_HEAD ((EDCS_Classification_Code)1407)

/*
 * Definition:
 *     A <DOCK> in which <WATER> can be maintained at any level by closing a
 *     <MARINE_GATE> when the <WATER> is at the desired level; a wet dock.
 *
 * Group Membership: HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_WET_DOCK ((EDCS_Classification_Code)1408)

/*
 * Definition:
 *     A <TERRAIN_SURFACE_REGION> that is inundated or saturated by surface
 *     or ground <WATER> at a frequency and duration sufficient to support,
 *     and that under normal circumstances does support, a prevalence of
 *     <VEGETATION> typically adapted for life in conditions of saturated
 *     <SOIL>; a wetland [AHD, "wetland"]. EXAMPLES <SWAMP>, <MARSH>, <BOG>.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_WETLAND ((EDCS_Classification_Code)1409)

/*
 * Definition:
 *     A large, marine <MAMMAL> of the order Cetacea, the members of which
 *     have forelimbs as fins, a tail with horizontal flukes, and nasal
 *     openings on top of the head; a whale [SOED, "whale", 1].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_WHALE ((EDCS_Classification_Code)1410)

/*
 * Definition:
 *     A <POD> of <WHALE>s.
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_WHALE_POD ((EDCS_Classification_Code)1411)

/*
 * Definition:
 *     A <STRUCTURE> serving as a berthing place for <VESSEL>s; a wharf.
 *
 * Group Membership: HYDROGRAPHIC_ARTEFACT, HYDROGRAPHIC_TRNSP, TRNSP
 */
#define ECC_WHARF ((EDCS_Classification_Code)1412)

/*
 * Definition:
 *     A <CURRENT> of <AIR> moving relative to a <PLANETARY_SURFACE>; usually
 *     only the horizontal component is considered; wind.
 *
 * Group Membership: ATMOSPHERE
 */
#define ECC_WIND ((EDCS_Classification_Code)1413)

/*
 * Definition:
 *     A visual <DEVICE> used to provide <<WIND_DIRECTION>> and
 *     <<WIND_SPEED>> information; a wind indicator.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_WIND_INDICATOR ((EDCS_Classification_Code)1414)

/*
 * Definition:
 *     <EQUIPMENT> attached to a <TOWER> that generates electrical power from
 *     <WIND>; a wind motor.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_WIND_MOTOR ((EDCS_Classification_Code)1415)

/*
 * Definition:
 *     A <PROPERTY_SET> describing the relative frequency of the
 *     <<WIND_DIRECTION>>, and sometimes the frequencies of the
 *     <<WIND_SPEED>>s for different directions, experienced at a given
 *     <LOCATION> over a defined period of record; a wind rose.
 *
 * Group Membership: PROPERTY_SET
 */
#define ECC_WIND_ROSE_PROPERTY_SET ((EDCS_Classification_Code)1416)

/*
 * Definition:
 *     <EQUIPMENT> through which <AIR> is forced at controlled velocities in
 *     order to study the effects of aerodynamic flow around airfoils, scale
 *     models, or other <OBJECT>s; a wind tunnel [AHD, "wind tunnel"].
 *
 * Group Membership: BUILDING_COMPONENT, DEVICE_AND_EQUIPMENT
 */
#define ECC_WIND_TUNNEL ((EDCS_Classification_Code)1417)

/*
 * Definition:
 *     A visual <DEVICE> used to indicate or measure <<WIND_DIRECTION>>; a
 *     wind vane.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_WIND_VANE ((EDCS_Classification_Code)1418)

/*
 * Definition:
 *     A <WATER_WAVE> generated by friction between the <WIND> and a
 *     <WATERBODY_SURFACE>.
 *
 * Group Membership: WATERBODY_SURFACE
 */
#define ECC_WIND_WAVE ((EDCS_Classification_Code)1419)

/*
 * Definition:
 *     A <SYSTEM> of vanes attached to a <TOWER> and driven by <WIND>
 *     (excluding <WIND_MOTOR>s); a windmill.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_WINDMILL ((EDCS_Classification_Code)1420)

/*
 * Definition:
 *     An <APERTURE> in a <WALL> or the side of a <BUILDING>, <VEHICLE>, or
 *     other <STRUCTURE> that admits light, <AIR>, or both and affords a
 *     view of what is outside or inside; a window [SOED, "window", 1.a].
 *
 * Group Membership: BUILDING_COMPONENT, LIGHTING_AND_VISIBILITY
 */
#define ECC_WINDOW ((EDCS_Classification_Code)1421)

/*
 * Definition:
 *     Metal wrought into the form of a slender rod or thread; wire [SOED,
 *     "wire", 1].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_WIRE ((EDCS_Classification_Code)1422)

/*
 * Definition:
 *     A <TERRAIN_OBSTACLE> constructed of <WIRE>, usually containing barbs
 *     or razors; a wire obstacle.
 *
 * Group Membership: TRNSP
 */
#define ECC_WIRE_OBSTACLE ((EDCS_Classification_Code)1423)

/*
 * Definition:
 *     A <TRACT> covered by woody and/or tree-like grasses of the tropical or
 *     temperate <REGION>s that have jointed hollow stems with solid nodes
 *     (for example: <BAMBOO> and/or sugar cane); woody grass land.
 *
 * Group Membership: LIVING_ORGANISM, PHYSIOGRAPHY, PLANT
 */
#define ECC_WOODY_GRASS_LAND ((EDCS_Classification_Code)1424)

/*
 * Definition:
 *     A place where religious worship is performed, especially a <BUILDING>
 *     designed for this purpose; a place of worship [SOED, "place of
 *     worship"]. EXAMPLES <CHAPEL>, <CHURCH>, <MOSQUE>, <SYNAGOGUE>.
 *
 * Group Membership: RELIGION
 */
#define ECC_WORSHIP_PLACE ((EDCS_Classification_Code)1425)

/*
 * Definition:
 *     An enclosed <TRACT> within which <EQUIPMENT> is dismantled or torn
 *     down; a wrecking yard.
 *
 * Group Membership: INDUSTRY, LAND_INDUSTRY, USAGE_REGION
 */
#define ECC_WRECKING_YARD ((EDCS_Classification_Code)1426)

/*
 * Definition:
 *     A wild African <HORSE>, characterized by having an erect mane, whitish
 *     hide and distinctively black stripes; a zebra [SOED, "zebra", 1].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM
 */
#define ECC_ZEBRA ((EDCS_Classification_Code)1427)

/*
 * Definition:
 *     An <ANIMAL_PARK> where wild <NON_HUMAN_ANIMAL>s are kept for study,
 *     breeding, or exhibition to the public; a zoo [SOED, "zoo", 1].
 *
 * Group Membership: ANIMAL, LIVING_ORGANISM, RECREATION
 */
#define ECC_ZOO ((EDCS_Classification_Code)1428)

/*
 * Definition:
 *     An acoustic energy flux <RAY_PATH>.
 *
 * Group Membership: ACOUSTIC_PHENOMENON
 */
#define ECC_ACOUSTIC_RAY_PATH ((EDCS_Classification_Code)1429)

/*
 * Definition:
 *     An <ACOUSTIC_RAY_PATH> from a specific source <LOCATION> to a specific
 *     observation point <LOCATION>; an acoustic eigenray.
 *
 * Group Membership: ACOUSTIC_PHENOMENON, LOCATION
 */
#define ECC_ACOUSTIC_EIGENRAY ((EDCS_Classification_Code)1430)

/*
 * Definition:
 *     A long seat, usually of wood or <ROCK>, with or without a back; a
 *     bench [SOED, "bench", 1].
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_BENCH ((EDCS_Classification_Code)1431)

/*
 * Definition:
 *     A canopy or <LEDGE> attached to the exterior of a <BUILDING> and
 *     projecting beyond the <EXTERIOR_WALL> of the <BUILDING>; a building
 *     overhang.
 *
 * Group Membership: SHELTER
 */
#define ECC_BUILDING_OVERHANG ((EDCS_Classification_Code)1432)

/*
 * Definition:
 *     The <REGION> of a <PLANETARY_SURFACE> into which <PERSONNEL> or
 *     <EQUIPMENT> are conveyed or dropped by means of a parachute from an
 *     <AIRCRAFT>; a drop zone.
 *
 * Group Membership: AIR_TRNSP, TRNSP
 */
#define ECC_DROP_ZONE ((EDCS_Classification_Code)1433)

/*
 * Definition:
 *     A layer of the <ATMOSPHERE> above a <PLANETARY_SURFACE>, in which
 *     electromagnetic waves are trapped due to changes in the index of
 *     refraction and the bottom of the layer is above the
 *     <PLANETARY_SURFACE>; an elevated electromagnetic duct.
 *
 * Group Membership: EM_PHENOMENON
 */
#define ECC_ELEVATED_EM_DUCT ((EDCS_Classification_Code)1434)

/*
 * Definition:
 *     A <CONTAINER> for growing or displaying <PLANT>s; a planter, [SOED,
 *     "planter", 6b].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_PLANTER ((EDCS_Classification_Code)1435)

/*
 * Definition:
 *     A physical <OBJECT> serving to adorn, beautify, or embellish; a
 *     decoration, an ornament, [SOED, "ornament", 2.a].
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_ORNAMENT ((EDCS_Classification_Code)1436)

/*
 * Definition:
 *     A circular physical <OBJECT>, usually painted flat white, that is used
 *     to measure (subjectively) the <<DEPTH_BELOW_WATERBODY_SURFACE>> to
 *     which a <HUMAN> can see into a <WATERBODY>, in order to measure the
 *     transparency of the <WATER>; Secchi disk.
 *
 * Group Membership: WATERBODY_STATE, HYDROLOGY
 */
#define ECC_SECCHI_DISK ((EDCS_Classification_Code)1437)

/*
 * Definition:
 *     <FURNITURE> consisting of a raised flat top of solid <MATERIAL> (for
 *     example, wood or <ROCK>) and used to place physical <OBJECT>s on; a
 *     table, [SOED, "table", 13].
 *
 * Group Membership: ABSTRACT_OBJECT
 */
#define ECC_TABLE ((EDCS_Classification_Code)1438)

/*
 * Definition:
 *     A layer in an <ATMOSPHERE> where the <<POTENTIAL_AIR_TEMPERATURE>>
 *     increases with <<HEIGHT_AGL>>; potential temperature inversion layer.
 *
 * Group Membership: ATMOSPHERE, TEMPERATURE
 */
#define ECC_POTENTIAL_TEMPERATURE_INVERSION_LAYER ((EDCS_Classification_Code)1439)

/*
 * Definition:
 *     A <WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION> of an <OCEAN_FLOOR>.
 *
 * Group Membership: PHYSIOGRAPHY, WATERBODY_FLOOR
 */
#define ECC_OCEAN_FLOOR_TOPOGRAPHIC_CONFIGURATION ((EDCS_Classification_Code)1440)

/*
 * Definition:
 *     A representation network of passages composed of one or more
 *     interconnected <CAVE>s.
 *
 * Group Membership: PHYSIOGRAPHY
 */
#define ECC_CAVE_NEXUS ((EDCS_Classification_Code)1441)

/*
 * Definition:
 *     An <APERTURE> in an <EXTERIOR_WALL> that supports the passage of
 *     <MATERIAL>s or visibility into the space enclosed by the
 *     <EXTERIOR_WALL>.
 *
 * Group Membership: BUILDING_COMPONENT
 */
#define ECC_EXTERIOR_WALL_OPENING ((EDCS_Classification_Code)1442)

/*
 * Definition:
 *     A <DEVICE> that detects or measures some condition or property and
 *     records, indicates, or otherwise responds to the information received
 *     [SOED, "sensor"].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_SENSOR ((EDCS_Classification_Code)1443)

/*
 * Definition:
 *     The <REGION> within a <WEAPON_FIGHTING_POSITION> in which the hull and
 *     fighting <COMPONENT>s of the <WEAPON> are hidden from enemy view and
 *     fire; a weapon turret defilade position.
 *
 * Group Membership: MILITARY_SCIENCE
 */
#define ECC_WEAPON_TURRET_DEFILADE_POSITION ((EDCS_Classification_Code)1444)

/*
 * Definition:
 *     A rigid <STRUCTURAL_MEMBER> designed to carry and transfer transverse
 *     loads across space to supporting <COMPONENT>s; a structural beam.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STRUCTURAL_BEAM ((EDCS_Classification_Code)1445)

/*
 * Definition:
 *     A <GROUND_VEHICLE> having two wheels turned by pedalling, typically
 *     with handle bars at the front and a seat or saddle for the rider; a
 *     bicycle [SOED, "bicycle"].
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_BICYCLE ((EDCS_Classification_Code)1446)

/*
 * Definition:
 *     A <ROUTE_LANE>, typically narrow, that has been designated by
 *     <DISPLAY_SIGN>s and/or pavement markings for preferential or
 *     exclusive use by <BICYCLE>s; a bicycle lane.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_BICYCLE_LANE ((EDCS_Classification_Code)1447)

/*
 * Definition:
 *     A long <MOTOR_VEHICLE> specifically designed to transport multiple
 *     individual <HUMAN>s, often along a fixed <LAND_TRANSPORTATION_ROUTE>;
 *     a bus.
 *
 * Group Membership: LAND_TRNSP, TRNSP, VEHICLE
 */
#define ECC_BUS ((EDCS_Classification_Code)1448)

/*
 * Definition:
 *     A receptacle located where a <STORM_DRAIN> empties into a <SEWER> and
 *     designed to trap solid <OBJECT>s and separate them from waste <WATER>
 *     flowing into the <SEWER>; a catch basin.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define ECC_CATCH_BASIN ((EDCS_Classification_Code)1449)

/*
 * Definition:
 *     A rigid, relatively slender <STRUCTURAL_MEMBER> designed primarily to
 *     support axial, compressive loads applied at the member ends; a
 *     structural column.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STRUCTURAL_COLUMN ((EDCS_Classification_Code)1450)

/*
 * Definition:
 *     A raised border of hard <MATERIAL>, e.g. stone or concrete, often
 *     forming part of a gutter, along the <BOUNDARY> of a
 *     <LAND_TRANSPORTATION_ROUTE> and/or <VEHICLE_LOT>; a curb, also known
 *     as kerb.
 *
 * Group Membership: DEMARCATION, LAND_TRNSP, TRNSP
 */
#define ECC_CURB ((EDCS_Classification_Code)1451)

/*
 * Definition:
 *     A <POLE> with one or more <DISPLAY_SIGN>s attached.
 *
 * Group Membership: COMMUNICATION, SUPPORT_STRUCTURE
 */
#define ECC_DISPLAY_SIGN_POLE ((EDCS_Classification_Code)1452)

/*
 * Definition:
 *     An <ELECTRICAL_CABLE> for transmitting electrical signals; an
 *     electrical signal cable.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_ELECTRICAL_SIGNAL_CABLE ((EDCS_Classification_Code)1453)

/*
 * Definition:
 *     A <LOCATION> at which an external <ELECTRICAL_SIGNAL_CABLE> connects
 *     to the <SYSTEM> of internal <ELECTRICAL_SIGNAL_CABLE>s of a
 *     <BUILDING>; an electrical signal connection location.
 *
 * Group Membership: COMMUNICATION, EM_PHENOMENON, INFRASTRUCTURE, LOCATION
 */
#define ECC_ELECTRICAL_SIGNAL_CONNECTION_LOCATION ((EDCS_Classification_Code)1454)

/*
 * Definition:
 *     A <PIPE> with a <VALVE> for drawing liquid <WATER> directly from a
 *     <WATER_MAIN> and with a <COMPONENT> providing an <APERTURE> to which
 *     a fire-hose can be attached; a fire hydrant [SOED, "fire hydrant"].
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_FIRE_HYDRANT ((EDCS_Classification_Code)1455)

/*
 * Definition:
 *     A rail that acts as a safeguard to prevent <GROUND_VEHICLE>s and/or
 *     pedestrians from travelling into an unsafe <REGION>; a guard rail.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_GUARD_RAIL ((EDCS_Classification_Code)1456)

/*
 * Definition:
 *     A <CONTAINER> for delivery and/or collection of mail; a mailbox.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define ECC_MAILBOX ((EDCS_Classification_Code)1457)

/*
 * Definition:
 *     A <DEVICE> for automatically measuring or indicating the quantity,
 *     degree, or rate of something; a meter [SOED, "meter", noun 2, 1].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_METER ((EDCS_Classification_Code)1458)

/*
 * Definition:
 *     A <ROUTE_LANE> at the <BOUNDARY> of a <ROAD> that is intended to serve
 *     as a parking <LOCATION> for <MOTOR_VEHICLE>s; a parking lane.
 *
 * Group Membership: LAND_TRNSP, TRNSP, USAGE_REGION
 */
#define ECC_PARKING_LANE ((EDCS_Classification_Code)1459)

/*
 * Definition:
 *     A <METER>, usually coin-operated, receiving fees and registering the
 *     <<TIME_QUANTITY>> for which a <GROUND_VEHICLE> is allowed to park; a
 *     parking meter.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, LAND_TRNSP, TIME, TRNSP
 */
#define ECC_PARKING_METER ((EDCS_Classification_Code)1460)

/*
 * Definition:
 *     An <ELECTRICAL_CABLE> for transmitting electrical power.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE
 */
#define ECC_ELECTRICAL_POWER_CABLE ((EDCS_Classification_Code)1461)

/*
 * Definition:
 *     A <LOCATION> at which an external <ELECTRICAL_POWER_CABLE> connects to
 *     the <SYSTEM> of internal <ELECTRICAL_POWER_CABLE>s of a <BUILDING>;
 *     an electrical power connection location.
 *
 * Group Membership: EM_PHENOMENON, INFRASTRUCTURE, LOCATION
 */
#define ECC_ELECTRICAL_POWER_CONNECTION_LOCATION ((EDCS_Classification_Code)1462)

/*
 * Definition:
 *     A <TELEPHONE> that accesses the public land line <NETWORK> and is at a
 *     fixed <LOCATION> for use by the general public.
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT
 */
#define ECC_PUBLIC_TELEPHONE ((EDCS_Classification_Code)1463)

/*
 * Definition:
 *     A mechanical <DEVICE> used to move fluid by lifting, suction, or
 *     pressure; a pump.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT
 */
#define ECC_PUMP ((EDCS_Classification_Code)1464)

/*
 * Definition:
 *     A <DISPLAY_SIGN> acting as a <TRAFFIC_CONTROL_DEVICE> that identifies
 *     the <LOCATION> of a <LEVEL_CROSSING> between a <RAILWAY> and a <ROAD>.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, LAND_TRNSP, TRNSP
 */
#define ECC_RAILWAY_CROSSING_SIGN ((EDCS_Classification_Code)1465)

/*
 * Definition:
 *     A symbol or group of symbols displayed as a marking on the <SURFACE>
 *     of a <ROAD> (for example: parking space markings, <SPEED_HUMP>
 *     markings, and/or <CENTRE_LINE>s) as a <TRAFFIC_CONTROL_DEVICE>.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_ROAD_MARKINGS ((EDCS_Classification_Code)1466)

/*
 * Definition:
 *     A <PIPELINE> for conveying sewage; a sewer line.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_SEWER_LINE ((EDCS_Classification_Code)1467)

/*
 * Definition:
 *     A raised strip that is set crosswise into the <SURFACE> of a <ROAD> or
 *     <VEHICLE_LOT> and is designed to slow down <GROUND_VEHICLE>s; a speed
 *     hump.
 *
 * Group Membership: LAND_TRNSP, TRNSP
 */
#define ECC_SPEED_HUMP ((EDCS_Classification_Code)1468)

/*
 * Definition:
 *     A drain, usually located on, below, or near transportation <SURFACE>s,
 *     designed to provide drainage of <PRECIPITATION>; a storm drain.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_STORM_DRAIN ((EDCS_Classification_Code)1469)

/*
 * Definition:
 *     A <POLE> with one or more attached <STREET_LAMP>s.
 *
 * Group Membership: LAND_TRNSP, LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_STREET_LAMP_POLE ((EDCS_Classification_Code)1470)

/*
 * Definition:
 *     One of the constituent <COMPONENT>s into which a <STRUCTURE> may be
 *     resolved by analysis, having a unitary character and exhibiting a
 *     unique behaviour under an applied load; structural member.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_STRUCTURAL_MEMBER ((EDCS_Classification_Code)1471)

/*
 * Definition:
 *     A slender, upright <STRUCTURAL_MEMBER> of wood or metal that is part
 *     of a series of such members forming the structural frame of a <WALL>;
 *     a wall stud.
 *
 * Group Membership: SUPPORT_STRUCTURE
 */
#define ECC_WALL_STUD ((EDCS_Classification_Code)1472)

/*
 * Definition:
 *     A <DEVICE> for transmitting and receiving speech, sound, and/or
 *     electronic data in the form of a signal passed between instruments
 *     that are part of a communication <NETWORK>; a telephone [SOED,
 *     "telephone", A.2].
 *
 * Group Membership: COMMUNICATION, DEVICE_AND_EQUIPMENT
 */
#define ECC_TELEPHONE ((EDCS_Classification_Code)1473)

/*
 * Definition:
 *     A <DISPLAY_SIGN>, <TRAFFIC_LIGHT>, <ROAD_MARKINGS>, or other <DEVICE>
 *     used to regulate, warn or guide traffic, placed on, over or adjacent
 *     to a <TRANSPORTATION_ROUTE> by authority of a public agency having
 *     jurisdiction; a traffic control device.
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, TRNSP
 */
#define ECC_TRAFFIC_CONTROL_DEVICE ((EDCS_Classification_Code)1474)

/*
 * Definition:
 *     A <TRAFFIC_CONTROL_DEVICE> which uses one or more <LIGHT>s to control
 *     traffic flow by displaying right-of-way information to <VEHICLE>s
 *     and/or pedestrians.
 *
 * Group Membership: LIGHTING_AND_VISIBILITY, TRNSP
 */
#define ECC_TRAFFIC_LIGHT ((EDCS_Classification_Code)1475)

/*
 * Definition:
 *     A <POLE> that supports one or more mounted <TRAFFIC_LIGHT>s.
 *
 * Group Membership: TRNSP, SUPPORT_STRUCTURE
 */
#define ECC_TRAFFIC_LIGHT_POLE ((EDCS_Classification_Code)1476)

/*
 * Definition:
 *     An underground <STRUCTURE>, such as a <BUNKER> or underground
 *     <PARKING_GARAGE>.
 *
 * Group Membership: SHELTER
 */
#define ECC_UNDERGROUND_STRUCTURE ((EDCS_Classification_Code)1477)

/*
 * Definition:
 *     A <DEVICE> that controls the passage of fluid through a <PIPE> or an
 *     <APERTURE>; a valve [SOED, "valve", 6].
 *
 * Group Membership: DEVICE_AND_EQUIPMENT, INFRASTRUCTURE
 */
#define ECC_VALVE ((EDCS_Classification_Code)1478)

/*
 * Definition:
 *     A main <PIPE> or conduit forming a <COMPONENT> of a public or
 *     community <SYSTEM> of <PIPE>s and <VALVE>s conveying non-waste liquid
 *     <WATER> to all service connections.
 *
 * Group Membership: INFRASTRUCTURE
 */
#define ECC_WATER_MAIN ((EDCS_Classification_Code)1479)

#ifdef __cplusplus
}
#endif

#endif
