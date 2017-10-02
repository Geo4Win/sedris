/*
 * FILE       : edcs_org_schema_dict.c
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

#include "edcs_org_schema_dict.h"
#include "edcs_internal.h"
#include "edcs_group_dict.h"
#include "edcs_attr_dict.h"
#include "edcs_class_dict.h"

const EDCS_Group_Dictionary_Entry
EDCS_Group_Dictionary[] =
{
    /* Groups for EOC_GENERAL */
    { EOC_GENERAL, EGC_GEN_ABSTRACT_OBJECT,
    "ABSTRACT_OBJECT", "EGC_GEN_ABSTRACT_OBJECT",
    "ECs that either are or are related to abstract <OBJECT>s; EAs that"
    " specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_ACOUSTIC_PHENOMENON,
    "ACOUSTIC_PHENOMENON", "EGC_GEN_ACOUSTIC_PHENOMENON",
    "ECs that either are or are related to acoustic phenomena; EAs that"
    " specify the state of such concepts. For the purposes of this concept"
    " definition, an acoustic phenomenon is a phenomenon related to the"
    " production, propagation, reception, and processing of sound signals,"
    " signal characteristics and interfering noise, reverberation, and"
    " scattering.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_ADMINISTRATION,
    "ADMINISTRATION", "EGC_GEN_ADMINISTRATION",
    "ECs that either are or are related to administration; EAs that specify"
    " the state of such concepts. EXAMPLES Management, legal, government,"
    " financial activities.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_AGRICULTURE,
    "AGRICULTURE", "EGC_GEN_AGRICULTURE",
    "ECs that either are or are related to agriculture; EAs that specify"
    " the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_AIR_TRNSP,
    "AIR_TRNSP", "EGC_GEN_AIR_TRNSP",
    "ECs that are members of the TRNSP and involve <AIRCRAFT>; EAs that"
    " specify the state of such ECs.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_AIRBORNE_PARTICLE,
    "AIRBORNE_PARTICLE", "EGC_GEN_AIRBORNE_PARTICLE",
    "ECs that are or are related to airborne particles; EAs that specify"
    " the state of such concepts. For the purposes of this concept"
    " definition, airborne particles are unconsolidated fine <PARTICLE>s of"
    " solid and/or liquid <MATERIAL> that are suspended in <AIR>.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_ALGORITHM_RELATED,
    "ALGORITHM_RELATED", "EGC_GEN_ALGORITHM_RELATED",
    "ECs that are used by algorithms and/or are related to algorithms; EAs"
    " that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_ANGULAR_MEASURE,
    "ANGULAR_MEASURE", "EGC_GEN_ANGULAR_MEASURE",
    "EAs that are measurements of either plane or solid angles.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_ANIMAL,
    "ANIMAL", "EGC_GEN_ANIMAL",
    "ECs that either are or are related to <ANIMAL>s; EAs that specify the"
    " state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_ATMOSPHERE,
    "ATMOSPHERE", "EGC_GEN_ATMOSPHERE",
    "ECs that either are or are related to an <ATMOSPHERE> and/or a natural"
    " phenomenon that occurs in an <ATMOSPHERE>; EAs that specify the state"
    " of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_BUILDING_COMPONENT,
    "BUILDING_COMPONENT", "EGC_GEN_BUILDING_COMPONENT",
    "ECs that either are or are related to <BUILDING_COMPONENT>s; EAs that"
    " specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_COLOUR,
    "COLOUR", "EGC_GEN_COLOUR",
    "ECs that are <OBJECT>s specified by their colour; EAs that specify"
    " and/or measure the colour or <<COLOURATION>> of <OBJECT>s.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_COMMUNICATION,
    "COMMUNICATION", "EGC_GEN_COMMUNICATION",
    "ECs that either are or are related to communication; EAs that specify"
    " the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_DEMARCATION,
    "DEMARCATION", "EGC_GEN_DEMARCATION",
    "ECs that either are or are related to demarcation; EAs that specify"
    " the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_DEVICE_AND_EQUIPMENT,
    "DEVICE_AND_EQUIPMENT", "EGC_GEN_DEVICE_AND_EQUIPMENT",
    "ECs that either are or are related to <DEVICE>s and/or <EQUIPMENT>;"
    " EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_DIMENSION,
    "DIMENSION", "EGC_GEN_DIMENSION",
    "EAs that are measurements of size, capacity, and/or dimension.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_EM_PHENOMENON,
    "EM_PHENOMENON", "EGC_GEN_EM_PHENOMENON",
    "ECs that either are or are related to electric fields and/or"
    " <MAGNETIC_FIELD>s; EAs that specify the state of such concepts;"
    " electromagnetic phenomenon.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_FLUID_CONDITION,
    "FLUID_CONDITION", "EGC_GEN_FLUID_CONDITION",
    "ECs that either are or are related to fluids; EAs that specify the"
    " state of such concepts; fluid condition.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_HARBOUR_AND_PORT,
    "HARBOUR_AND_PORT", "EGC_GEN_HARBOUR_AND_PORT",
    "ECs that either are or are related to <HARBOUR>s or <MARINE_PORT>s;"
    " EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_HYDROGRAPHIC_ARTEFACT,
    "HYDROGRAPHIC_ARTEFACT", "EGC_GEN_HYDROGRAPHIC_ARTEFACT",
    "ECs that either are or are related to artefacts involving a"
    " <WATERBODY>; EAs that specify the state of such concepts;"
    " hydrographic artefact.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_HYDROGRAPHIC_INDUSTRY,
    "HYDROGRAPHIC_INDUSTRY", "EGC_GEN_HYDROGRAPHIC_INDUSTRY",
    "ECs that are members of INDUSTRY and that involve a <WATERBODY>; EAs"
    " that specify the state of such ECs; hydrographic artefact.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_HYDROGRAPHIC_TRNSP,
    "HYDROGRAPHIC_TRNSP", "EGC_GEN_HYDROGRAPHIC_TRNSP",
    "ECs that are members of TRNSP and involve a <WATERBODY>; EAs that"
    " specify the state of such ECs; hydrographic transportation.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_HYDROLOGY,
    "HYDROLOGY", "EGC_GEN_HYDROLOGY",
    "ECs that relate to hydrology; EAs that specify the state of such"
    " concepts. For the purposes of this concept definition, hydrology is"
    " the branch of science that deals with <WATERBODY>s found on and/or"
    " below a <PLANETARY_SURFACE> and in inland <REGION>s.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_ICE,
    "ICE", "EGC_GEN_ICE",
    "ECs that are <OBJECT>s composed at least in part of <ICE>; EAs that"
    " specify the state of such <OBJECT>s.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_IDENTIFICATION,
    "IDENTIFICATION", "EGC_GEN_IDENTIFICATION",
    "EAs that uniquely identify <OBJECT>s.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_INDUSTRY,
    "INDUSTRY", "EGC_GEN_INDUSTRY",
    "ECs that either are or are related to industrial <OBJECT>s and/or"
    " industries; EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_INFRASTRUCTURE,
    "INFRASTRUCTURE", "EGC_GEN_INFRASTRUCTURE",
    "ECs that either are or are related to infrastructure <OBJECT>s; EAs"
    " that specify the state of such concepts. For the purposes of this"
    " concept definition, an infrastructure <OBJECT> is a basic supporting"
    " utility, <EQUIPMENT>, and/or <FACILITY>.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_LAND_INDUSTRY,
    "LAND_INDUSTRY", "EGC_GEN_LAND_INDUSTRY",
    "ECs that belong to INDUSTRY and involve a <REGION> of <LAND>; EAs that"
    " specify the state of such ECs.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_LAND_TRNSP,
    "LAND_TRNSP", "EGC_GEN_LAND_TRNSP",
    "ECs that belong to TRNSP and involve <LAND>; EAs that specify the"
    " state of such ECs.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_LIGHTING_AND_VISIBILITY,
    "LIGHTING_AND_VISIBILITY", "EGC_GEN_LIGHTING_AND_VISIBILITY",
    "ECs that are related to lighting and/or visibility; EAs that specify"
    " the state of lighting and/or visibility.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_LITTORAL,
    "LITTORAL", "EGC_GEN_LITTORAL",
    "ECs that either are or are related to littoral <REGION>s; EAs that"
    " specify the state of such concepts. For the purposes of this concept"
    " definition, a littoral <REGION> is a <SHORE> where a normal cycle of"
    " exposure and submersion by <WATER> occurs.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_LIVING_ORGANISM,
    "LIVING_ORGANISM", "EGC_GEN_LIVING_ORGANISM",
    "ECs that either are or are related to <LIVING_ORGANISM>s; EAs that"
    " specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_LOCATION,
    "LOCATION", "EGC_GEN_LOCATION",
    "ECs that either are or are related to the specification of"
    " <LOCATION>s; EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_MATERIAL,
    "MATERIAL", "EGC_GEN_MATERIAL",
    "ECs that either are or are related to <MATERIAL>s; EAs that specify"
    " the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_MILITARY_SCIENCE,
    "MILITARY_SCIENCE", "EGC_GEN_MILITARY_SCIENCE",
    "ECs that either are or are related to military science; EAs that"
    " specify the state of such concepts. For the purposes of this concept"
    " definition, military science is the organization, operation,"
    " construction, installation, <EQUIPMENT>, and/or <MATERIAL> of a"
    " national armed force.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_PHYSIOGRAPHY,
    "PHYSIOGRAPHY", "EGC_GEN_PHYSIOGRAPHY",
    "ECs that either are or are related to physiographic <OBJECT>s; EAs"
    " that specify the state of such concepts. For the purposes of this"
    " concept definition, physiography is physical geography (the natural"
    " features and inanimate phenomena of a <PLANETARY_SURFACE>).",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_PLANT,
    "PLANT", "EGC_GEN_PLANT",
    "ECs that either are or are related to <PLANT>s; EAs that specify the"
    " state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_PROPERTY_SET,
    "PROPERTY_SET", "EGC_GEN_PROPERTY_SET",
    "ECs that are <PROPERTY_SET>s; EAs that either describe or are members"
    " of <PROPERTY_SET>s.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_RATE_OR_RATIO,
    "RATE_OR_RATIO", "EGC_GEN_RATE_OR_RATIO",
    "EAs that are measurements expressed as a rate and/or ratio.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_RECREATION,
    "RECREATION", "EGC_GEN_RECREATION",
    "ECs that either are or are related to recreational <OBJECT>s; EAs that"
    " specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_RELIGION,
    "RELIGION", "EGC_GEN_RELIGION",
    "ECs that are <OBJECT>s related to a religion and/or system of belief;"
    " EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_SHELTER,
    "SHELTER", "EGC_GEN_SHELTER",
    "ECs that either are or are related to <SHELTER>s; EAs that specify the"
    " state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_SPACE,
    "SPACE", "EGC_GEN_SPACE",
    "ECs that either are or are related to <SPACE>; EAs that specify the"
    " state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_SUPPORT_STRUCTURE,
    "SUPPORT_STRUCTURE", "EGC_GEN_SUPPORT_STRUCTURE",
    "ECs that either are or are related to <STRUCTURE>s other than"
    " <BUILDING>s; EAs that specify the state of such concepts; support"
    " structure.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_SURFACE,
    "SURFACE", "EGC_GEN_SURFACE",
    "ECs that either are or are related to <SURFACE>s; EAs that specify the"
    " state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_SURFACE_MATERIAL,
    "SURFACE_MATERIAL", "EGC_GEN_SURFACE_MATERIAL",
    "ECs that either are or are related to <MATERIAL>s at and/or on a"
    " <SURFACE>; EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_SURVEY,
    "SURVEY", "EGC_GEN_SURVEY",
    "ECs that either are or are related to <LOCATION>s determined through"
    " the use of surveying techniques; EAs that specify the state of such"
    " concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_TEMPERATURE,
    "TEMPERATURE", "EGC_GEN_TEMPERATURE",
    "ECs that either are or are related to <<TEMPERATURE>>; EAs that"
    " specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_TIME,
    "TIME", "EGC_GEN_TIME",
    "ECs that are related to time; EAs that specify the state of such"
    " concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_TRNSP,
    "TRNSP", "EGC_GEN_TRNSP",
    "ECs that either are or are related to transportation or travel; EAs"
    " that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_USAGE_REGION,
    "USAGE_REGION", "EGC_GEN_USAGE_REGION",
    "ECs that either or are related to <REGION>s and/or <OBJECT>s based on"
    " how they are used; EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_VEHICLE,
    "VEHICLE", "EGC_GEN_VEHICLE",
    "ECs that either are or are related to <VEHICLE>s; EAs that specify the"
    " state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_WATERBODY_FLOOR,
    "WATERBODY_FLOOR", "EGC_GEN_WATERBODY_FLOOR",
    "ECs that either are or are related to the characteristics of"
    " <WATERBODY_FLOOR>s; EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_WATERBODY_STATE,
    "WATERBODY_STATE", "EGC_GEN_WATERBODY_STATE",
    "ECs that either are or are related to particular modes, states, and/or"
    " circumstances of a <WATERBODY>; EAs that specify the state of such"
    " concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    { EOC_GENERAL, EGC_GEN_WATERBODY_SURFACE,
    "WATERBODY_SURFACE", "EGC_GEN_WATERBODY_SURFACE",
    "ECs that either are or are related to characteristics of"
    " <WATERBODY_SURFACE>s; EAs that specify the state of such concepts.",
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO }

}; /* end EDCS_Group_Dictionary */

typedef struct
{
    EDCS_Organization_Schema_Code  eo_code;
    EDCS_Group_Code                eg_code;
    const EDCS_Character         * eg_symbolic_constant;
} EDCS_Group_Label_Entry;

const EDCS_Group_Label_Entry
EDCS_Group_Labels[] =
{
    { EOC_GENERAL,
      EGC_GEN_ABSTRACT_OBJECT,
      "EGC_GEN_ABSTRACT_OBJECT"},
    { EOC_GENERAL,
      EGC_GEN_ACOUSTIC_PHENOMENON,
      "EGC_GEN_ACOUSTIC_PHENOMENON"},
    { EOC_GENERAL,
      EGC_GEN_ADMINISTRATION,
      "EGC_GEN_ADMINISTRATION"},
    { EOC_GENERAL,
      EGC_GEN_AGRICULTURE,
      "EGC_GEN_AGRICULTURE"},
    { EOC_GENERAL,
      EGC_GEN_AIR_TRNSP,
      "EGC_GEN_AIR_TRNSP"},
    { EOC_GENERAL,
      EGC_GEN_AIRBORNE_PARTICLE,
      "EGC_GEN_AIRBORNE_PARTICLE"},
    { EOC_GENERAL,
      EGC_GEN_ALGORITHM_RELATED,
      "EGC_GEN_ALGORITHM_RELATED"},
    { EOC_GENERAL,
      EGC_GEN_ANGULAR_MEASURE,
      "EGC_GEN_ANGULAR_MEASURE"},
    { EOC_GENERAL,
      EGC_GEN_ANIMAL,
      "EGC_GEN_ANIMAL"},
    { EOC_GENERAL,
      EGC_GEN_ATMOSPHERE,
      "EGC_GEN_ATMOSPHERE"},
    { EOC_GENERAL,
      EGC_GEN_BUILDING_COMPONENT,
      "EGC_GEN_BUILDING_COMPONENT"},
    { EOC_GENERAL,
      EGC_GEN_COLOUR,
      "EGC_GEN_COLOUR"},
    { EOC_GENERAL,
      EGC_GEN_COMMUNICATION,
      "EGC_GEN_COMMUNICATION"},
    { EOC_GENERAL,
      EGC_GEN_DEMARCATION,
      "EGC_GEN_DEMARCATION"},
    { EOC_GENERAL,
      EGC_GEN_DEVICE_AND_EQUIPMENT,
      "EGC_GEN_DEVICE_AND_EQUIPMENT"},
    { EOC_GENERAL,
      EGC_GEN_DIMENSION,
      "EGC_GEN_DIMENSION"},
    { EOC_GENERAL,
      EGC_GEN_EM_PHENOMENON,
      "EGC_GEN_EM_PHENOMENON"},
    { EOC_GENERAL,
      EGC_GEN_FLUID_CONDITION,
      "EGC_GEN_FLUID_CONDITION"},
    { EOC_GENERAL,
      EGC_GEN_HARBOUR_AND_PORT,
      "EGC_GEN_HARBOUR_AND_PORT"},
    { EOC_GENERAL,
      EGC_GEN_HYDROGRAPHIC_ARTEFACT,
      "EGC_GEN_HYDROGRAPHIC_ARTEFACT"},
    { EOC_GENERAL,
      EGC_GEN_HYDROGRAPHIC_INDUSTRY,
      "EGC_GEN_HYDROGRAPHIC_INDUSTRY"},
    { EOC_GENERAL,
      EGC_GEN_HYDROGRAPHIC_TRNSP,
      "EGC_GEN_HYDROGRAPHIC_TRNSP"},
    { EOC_GENERAL,
      EGC_GEN_HYDROLOGY,
      "EGC_GEN_HYDROLOGY"},
    { EOC_GENERAL,
      EGC_GEN_ICE,
      "EGC_GEN_ICE"},
    { EOC_GENERAL,
      EGC_GEN_IDENTIFICATION,
      "EGC_GEN_IDENTIFICATION"},
    { EOC_GENERAL,
      EGC_GEN_INDUSTRY,
      "EGC_GEN_INDUSTRY"},
    { EOC_GENERAL,
      EGC_GEN_INFRASTRUCTURE,
      "EGC_GEN_INFRASTRUCTURE"},
    { EOC_GENERAL,
      EGC_GEN_LAND_INDUSTRY,
      "EGC_GEN_LAND_INDUSTRY"},
    { EOC_GENERAL,
      EGC_GEN_LAND_TRNSP,
      "EGC_GEN_LAND_TRNSP"},
    { EOC_GENERAL,
      EGC_GEN_LIGHTING_AND_VISIBILITY,
      "EGC_GEN_LIGHTING_AND_VISIBILITY"},
    { EOC_GENERAL,
      EGC_GEN_LITTORAL,
      "EGC_GEN_LITTORAL"},
    { EOC_GENERAL,
      EGC_GEN_LIVING_ORGANISM,
      "EGC_GEN_LIVING_ORGANISM"},
    { EOC_GENERAL,
      EGC_GEN_LOCATION,
      "EGC_GEN_LOCATION"},
    { EOC_GENERAL,
      EGC_GEN_MATERIAL,
      "EGC_GEN_MATERIAL"},
    { EOC_GENERAL,
      EGC_GEN_MILITARY_SCIENCE,
      "EGC_GEN_MILITARY_SCIENCE"},
    { EOC_GENERAL,
      EGC_GEN_PHYSIOGRAPHY,
      "EGC_GEN_PHYSIOGRAPHY"},
    { EOC_GENERAL,
      EGC_GEN_PLANT,
      "EGC_GEN_PLANT"},
    { EOC_GENERAL,
      EGC_GEN_PROPERTY_SET,
      "EGC_GEN_PROPERTY_SET"},
    { EOC_GENERAL,
      EGC_GEN_RATE_OR_RATIO,
      "EGC_GEN_RATE_OR_RATIO"},
    { EOC_GENERAL,
      EGC_GEN_RECREATION,
      "EGC_GEN_RECREATION"},
    { EOC_GENERAL,
      EGC_GEN_RELIGION,
      "EGC_GEN_RELIGION"},
    { EOC_GENERAL,
      EGC_GEN_SHELTER,
      "EGC_GEN_SHELTER"},
    { EOC_GENERAL,
      EGC_GEN_SPACE,
      "EGC_GEN_SPACE"},
    { EOC_GENERAL,
      EGC_GEN_SUPPORT_STRUCTURE,
      "EGC_GEN_SUPPORT_STRUCTURE"},
    { EOC_GENERAL,
      EGC_GEN_SURFACE,
      "EGC_GEN_SURFACE"},
    { EOC_GENERAL,
      EGC_GEN_SURFACE_MATERIAL,
      "EGC_GEN_SURFACE_MATERIAL"},
    { EOC_GENERAL,
      EGC_GEN_SURVEY,
      "EGC_GEN_SURVEY"},
    { EOC_GENERAL,
      EGC_GEN_TEMPERATURE,
      "EGC_GEN_TEMPERATURE"},
    { EOC_GENERAL,
      EGC_GEN_TIME,
      "EGC_GEN_TIME"},
    { EOC_GENERAL,
      EGC_GEN_TRNSP,
      "EGC_GEN_TRNSP"},
    { EOC_GENERAL,
      EGC_GEN_USAGE_REGION,
      "EGC_GEN_USAGE_REGION"},
    { EOC_GENERAL,
      EGC_GEN_VEHICLE,
      "EGC_GEN_VEHICLE"},
    { EOC_GENERAL,
      EGC_GEN_WATERBODY_FLOOR,
      "EGC_GEN_WATERBODY_FLOOR"},
    { EOC_GENERAL,
      EGC_GEN_WATERBODY_STATE,
      "EGC_GEN_WATERBODY_STATE"},
    { EOC_GENERAL,
      EGC_GEN_WATERBODY_SURFACE,
      "EGC_GEN_WATERBODY_SURFACE"}
}; /* EDCS_Group_Labels */

static const EDCS_Organization_Schema_Dictionary_Entry
EDCS_Organization_Schema_Dictionary[] =
{
    {EOC_GENERAL,
    "GENERAL", "EOC_GENERAL",
    "A schema based on natural and/or scientific principles.",
     55, &EDCS_Group_Dictionary[0],
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO }

}; /* EDCS_Organization_Schema_Dictionary */

/*
 * STRUCT: EDCS_Organization_Schema_Label_Entry
 *
 *  Used within this file for the label lookup table.
 */
typedef struct
{
    EDCS_Organization_Schema_Code  code;
    EDCS_Organization_Schema_Label label;
} EDCS_Organization_Schema_Label_Entry;

static const EDCS_Organization_Schema_Label_Entry
EDCS_Organization_Schema_Labels[] =
{
    {EOC_GENERAL, "GENERAL"}
}; /* EDCS_Organization_Schema_Labels */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareEGSymbolicConstant
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareEGSymbolicConstant
(
    const EDCS_Group_Label_Entry *a_ptr,
    const EDCS_Group_Label_Entry *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;

    result = edcs_strcmp(a_ptr->eg_symbolic_constant, b_ptr->eg_symbolic_constant);

    return result;
} /* end local_CompareEGSymbolicConstant */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareEOLabel
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareEOLabel
(
    const EDCS_Organization_Schema_Label_Entry *a_ptr,
    const EDCS_Organization_Schema_Label_Entry *b_ptr
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
} /* end local_CompareEOLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEGDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetEGDictionaryEntry
(
          EDCS_Organization_Schema_Code eo_code_in,
          EDCS_Group_Code               eg_code_in,
    const EDCS_Group_Dictionary_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidOrganizationSchemaCode(eo_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else if (!EDCS_ValidGroupCode(eo_code_in, eg_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *result_out_ptr = &(EDCS_Organization_Schema_Dictionary[eo_code_in-1].eg_list[eg_code_in-1]);
    }
    return status;
} /* end EDCS_GetEGDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEODictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetEODictionaryEntry
(
          EDCS_Organization_Schema_Code               eo_code_in,
    const EDCS_Organization_Schema_Dictionary_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidOrganizationSchemaCode(eo_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *result_out_ptr = &(EDCS_Organization_Schema_Dictionary[eo_code_in-1]);
    }
    return status;
} /* end EDCS_GetEODictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEOCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_LabelToEOCode
(
    const EDCS_Character                 *label_in_ptr,
          EDCS_Organization_Schema_Code  *result_out_ptr
)
{
    EDCS_Status_Code                      status = EDCS_SC_SUCCESS;
    EDCS_Organization_Schema_Label_Entry *search_result_ptr = NULL, target;

    if (!label_in_ptr || !result_out_ptr)
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    else
    {
       *result_out_ptr = (EDCS_Organization_Schema_Code)0;
        target.label   = label_in_ptr;
        search_result_ptr = (EDCS_Organization_Schema_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_Organization_Schema_Labels,
                               EDCS_TOTAL_EO,
                               sizeof(EDCS_Organization_Schema_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_CompareEOLabel
                            );
        if (search_result_ptr)
            *result_out_ptr = search_result_ptr->code;
        else
            status = EDCS_SC_INVALID_INPUT_CODE;
    }
    return status;
} /* end EDCS_LabelToEOCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEGCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_LabelToEGCode
(
    const EDCS_Character                *eo_label_in_ptr,
    const EDCS_Character                *eg_label_in_ptr,
          EDCS_Organization_Schema_Code *eo_code_out_ptr,
          EDCS_Group_Code               *eg_code_out_ptr
)
{
    EDCS_Status_Code              status = EDCS_SC_SUCCESS;
    EDCS_Organization_Schema_Code eo_code;
    EDCS_Count                    i;

    if (!eg_label_in_ptr || !eo_label_in_ptr || !eo_code_out_ptr || !eg_code_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if ((status = EDCS_LabelToEOCode(eo_label_in_ptr, &eo_code)) == EDCS_SC_SUCCESS)
    {
        status = EDCS_SC_INVALID_INPUT_LABEL;

        for (i = 0; i < EDCS_Organization_Schema_Dictionary[eo_code-1].eg_count && status != EDCS_SC_SUCCESS; i++)
        {
            if (!edcs_strcmp(EDCS_Organization_Schema_Dictionary[eo_code-1].eg_list[i].label, eg_label_in_ptr))
            {
                *eo_code_out_ptr = eo_code;
                *eg_code_out_ptr = EDCS_Organization_Schema_Dictionary[eo_code-1].eg_list[i].eg_code;
                status = EDCS_SC_SUCCESS;
            }
        }
    }
    return status;
} /* end EDCS_LabelToEGCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintGroupCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintGroupCode
(
    EDCS_Organization_Schema_Code eo_code_in,
    EDCS_Group_Code        eg_code_in
)
{
    static char buffer[256];

    if (!EDCS_ValidOrganizationSchemaCode(eo_code_in))
    {
        sprintf(buffer, "ERROR - ILLEGAL EDCS_Organization_Schema_Code VALUE (%i)",
               (int) eo_code_in);
        return buffer;
    }
    else if (!EDCS_ValidGroupCode(eo_code_in, eg_code_in))
    {
        sprintf(buffer, "ERROR - ILLEGAL EDCS_Group_Code VALUE (%i)",
               (int) eg_code_in);
        return buffer;
    }
    else
    {
        return EDCS_Organization_Schema_Dictionary[eo_code_in-1].eg_list[eg_code_in-1].symbolic_constant;
    }
} /* end EDCS_PrintGroupCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintOrganizationSchemaCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintOrganizationSchemaCode
(
    EDCS_Organization_Schema_Code eo_code_in
)
{
    static char buffer[256];

    if (!EDCS_ValidOrganizationSchemaCode(eo_code_in))
    {
        sprintf(buffer, "ERROR - ILLEGAL EDCS_Organization_Schema_Code VALUE (%i)",
               (int) eo_code_in);
        return buffer;
    }
    else
    {
        return EDCS_Organization_Schema_Dictionary[eo_code_in-1].symbolic_constant;
    }
} /* end EDCS_PrintOrganizationSchemaCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEGCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SymbolicConstantToEGCode
(
    const EDCS_Character                *eg_symbolic_constant,
          EDCS_Organization_Schema_Code *eo_code_out_ptr,
          EDCS_Group_Code               *eg_code_out_ptr
)
{
    EDCS_Status_Code        status = EDCS_SC_SUCCESS;
    EDCS_Group_Label_Entry *search_result_ptr = NULL, target;

    if (!eg_symbolic_constant || !eo_code_out_ptr || !eg_code_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
       *eo_code_out_ptr                = (EDCS_Organization_Schema_Code)0;
       *eg_code_out_ptr                = (EDCS_Group_Code)0;
        target.eg_symbolic_constant    = eg_symbolic_constant;

        search_result_ptr = (EDCS_Group_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_Group_Labels,
                               EDCS_TOTAL_EG,
                               sizeof(EDCS_Group_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_CompareEGSymbolicConstant
                            );

        if (search_result_ptr)
        {
            *eo_code_out_ptr = search_result_ptr->eo_code;
            *eg_code_out_ptr = search_result_ptr->eg_code;
        }
        else
        {
            status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
        }
    }
    return status;
} /* end EDCS_SymbolicConstantToEGCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEOCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SymbolicConstantToEOCode
(
    const EDCS_Character                *symbolic_in_ptr,
          EDCS_Organization_Schema_Code *result_out_ptr
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
        /* Symbolic constants should always be of the form EOC_<EO_Label>, so
         * we strip off the EOC_ and use the EDCS_LabelToEOCode function
         */
        if (strstr(symbolic_in_ptr, "EOC_") == symbolic_in_ptr)
        {
            label = strchr(symbolic_in_ptr, '_');

            if (label != NULL)
            {
                label++;
                status = EDCS_LabelToEOCode(label, result_out_ptr);

                /* Hand back the correct error code if the label couldn't be found */
                if (status == EDCS_SC_INVALID_INPUT_LABEL)
                {
                    status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
                }
            }
        }
    }
    return status;
} /* end EDCS_SymbolicConstantToEOCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidGroupCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidGroupCode
(
    EDCS_Organization_Schema_Code eo_code_in,
    EDCS_Group_Code               eg_code_in
)
{
    if (!EDCS_ValidOrganizationSchemaCode(eo_code_in))
    {
        return EDCS_FALSE;
    }
    else
    {
        if ((EDCS_Organization_Schema_Dictionary[eo_code_in-1].eg_count == 0) ||
           (eg_code_in < 1) ||
           (eg_code_in > (EDCS_Group_Code) EDCS_Organization_Schema_Dictionary[eo_code_in-1].eg_count))
        {
            return EDCS_FALSE;
        }
        else if (EDCS_Organization_Schema_Dictionary[eo_code_in-1].eg_list[eg_code_in-1].eg_code != eg_code_in)
        {
            return EDCS_FALSE;
        }
        else
        {
            return EDCS_TRUE;
        }
    }
} /* end EDCS_ValidGroupCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidOrganizationSchemaCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidOrganizationSchemaCode
(
    EDCS_Organization_Schema_Code eo_code_in
)
{
    if (eo_code_in < 1 || eo_code_in > EDCS_TOTAL_EO)
    {
        return EDCS_FALSE;
    }
    else if (EDCS_Organization_Schema_Dictionary[eo_code_in-1].code != eo_code_in)
    {
        return EDCS_FALSE;
    }
    else
    {
        return EDCS_TRUE;
    }
} /* end EDCS_ValidOrganizationSchemaCode */
