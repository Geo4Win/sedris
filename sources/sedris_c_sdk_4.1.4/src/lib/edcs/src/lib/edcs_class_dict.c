/*
 * FILE       : edcs_class_dict.c
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

#include "edcs_class_dict.h"
#include "edcs_internal.h"
#include "edcs_org_schema_dict.h"
#include "edcs_group_dict.h"

static EDCS_Group_Pair
EGBindingForEC[] =
{

    /*
     * First, to avoid lots of duplication with things that only reference
     * a single EGC, output the list.
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_COLOUR, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_FLUID_CONDITION, EOC_GENERAL },
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_RELIGION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Begin output of the lists (for ECs with multiple groups)
     */

    /*
     * Entry 55
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 58
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },

    /*
     * Entry 60
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },

    /*
     * Entry 62
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 67
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 71
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 73
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 75
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 77
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 79
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 81
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 83
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },

    /*
     * Entry 85
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 88
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_FLUID_CONDITION, EOC_GENERAL },

    /*
     * Entry 90
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 92
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 94
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 96
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 99
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 101
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 103
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 105
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 111
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 114
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 118
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },

    /*
     * Entry 120
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 122
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 125
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 128
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 130
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 133
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 136
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 139
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 141
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 147
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 150
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 155
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 159
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 163
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 167
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 173
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 178
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 181
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 186
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 190
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 194
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 196
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 198
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 200
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },

    /*
     * Entry 202
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 207
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 211
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 214
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 218
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 221
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 224
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 229
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 233
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 237
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 241
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 244
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 247
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 251
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 254
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 258
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 261
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 265
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 267
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 270
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 273
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },

    /*
     * Entry 275
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 281
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },

    /*
     * Entry 284
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 287
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 290
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 293
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 295
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 299
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 302
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 309
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 312
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 320
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 322
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 327
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 331
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 333
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 336
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 342
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },

    /*
     * Entry 345
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 349
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 352
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 354
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 358
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 362
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 365
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },

    /*
     * Entry 367
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 369
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 372
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 376
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },

    /*
     * Entry 378
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 381
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 383
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 386
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 388
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 391
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 393
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 396
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 398
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },

    /*
     * Entry 400
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 402
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 405
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 408
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 411
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 413
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 416
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_RELIGION, EOC_GENERAL },

    /*
     * Entry 418
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 420
     */
    { EGC_GEN_COLOUR, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 423
     */
    { EGC_GEN_COLOUR, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 425
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },

    /*
     * Entry 427
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 430
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 434
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 440
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 443
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 447
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 451
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 455
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 458
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 462
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 466
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 470
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 475
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 480
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 483
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 487
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 489
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 492
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 496
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 499
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 501
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 503
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },

    /*
     * Entry 505
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 510
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 514
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 518
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 521
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 524
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LITTORAL, EOC_GENERAL },

    /*
     * Entry 526
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 529
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 533
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 536
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 540
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 542
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 545
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 548
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 550
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 552
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 555
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 557
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 559
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 561
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 564
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },

    /*
     * Entry 566
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 571
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 575
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 580
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 583
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 586
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },

    /*
     * Entry 588
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 591
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },

    /*
     * Entry 594
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 597
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 599
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 603
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 606
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 609
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 612
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 614
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 616
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 618
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 621
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 623
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 626
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 629
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 632
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 636
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 639
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 642
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 645
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 649
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 652
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 654
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 657
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 660
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 662
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 664
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 669
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 673
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },

    /*
     * Entry 675
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 681
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 687
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 691
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },

    /*
     * Entry 693
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },

    /*
     * Entry 696
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 700
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },

    /*
     * Entry 702
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 706
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 711
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 715
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 719
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 724
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 727
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 731
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 733
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 736
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 739
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 741
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },

    /*
     * Entry 743
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 745
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 749
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 751
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 753
     */
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 759
     */
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 763
     */
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 768
     */
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 772
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 778
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 783
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 788
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 791
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 795
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 800
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 803
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 807
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 810
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 814
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 817
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 821
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 824
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 826
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 831
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 835
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 838
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 841
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 844
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },

    /*
     * Entry 846
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },

    /*
     * Entry 848
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 850
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 853
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 856
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 860
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 862
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 865
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 867
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 869
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 872
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 874
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 876
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 880
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 883
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 886
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 888
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 891
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 893
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 895
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 897
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 901
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 904
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 907
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 911
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 916
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 920
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 925
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 931
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 936
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 941
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 946
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 949
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 953
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LAND_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 956
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 959
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 962
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 965
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 967
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 970
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 972
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 975
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 977
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 980
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 984
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 986
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 989
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 991
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 994
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 996
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 999
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1001
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1004
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1008
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1012
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1015
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1020
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1024
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1027
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1031
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1035
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1038
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1041
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1045
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1047
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1050
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1052
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1055
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1058
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 1060
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1062
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1064
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 1066
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1068
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1072
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1074
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 1077
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1081
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 1083
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1087
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1090
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1092
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1094
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 1097
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 1099
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_RECREATION, EOC_GENERAL },

    /*
     * Entry 1101
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 1103
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1105
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1107
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1109
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1112
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },

    /*
     * Entry 1114
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1117
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1119
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 1121
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1123
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1126
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1129
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1131
     */
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1133
     */
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1136
     */
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1138
     */
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1140
     */
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 1142
     */
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1145
     */
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1147
     */
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1149
     */
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 1151
     */
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1154
     */
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1156
     */
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1158
     */
    { EGC_GEN_RELIGION, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 1160
     */
    { EGC_GEN_RELIGION, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1162
     */
    { EGC_GEN_RELIGION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1164
     */
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1166
     */
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1168
     */
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1170
     */
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1173
     */
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1176
     */
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1178
     */
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1180
     */
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 1182
     */
    { EGC_GEN_SURVEY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1184
     */
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1186
     */
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1188
     */
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 1190
     */
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL }

}; /* end EGBindingForEC */

static const EDCS_Classification_Dictionary_Entry
EDCS_Classification_Dictionary[] =
{
    {ECC_ABATIS,
    "ABATIS", "ECC_ABATIS",
    "A defence constructed by placing felled <TREE>s lengthwise one over"
    " the other with their branches towards the enemy's line; an abatis"
    " [SOED, \"abatis\"].",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ABYSS,
    "ABYSS", "ECC_ABYSS",
    "A <WATERBODY_FLOOR> with <<DEPTH_OF_WATERBODY_FLOOR>> greater than 549"
    " metres (approximately 1 800 feet); an abyss.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"abyss\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ACCESS_ZONE,
    "ACCESS_ZONE", "ECC_ACCESS_ZONE",
    "A <TERRAIN_SURFACE_REGION> between a <CONTACT_ZONE> and the first"
    " passable <LAND_TRANSPORTATION_ROUTE>; an access zone.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ACOUSTIC_DATA_COLLECTION_DEVICE,
    "ACOUSTIC_DATA_COLLECTION_DEVICE", "ECC_ACOUSTIC_DATA_COLLECTION_DEVICE",
    "A <DEVICE> used for the collection of acoustic data.",
    2, &(EGBindingForEC[83]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BK010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ACOUSTIC_SIGNATURE_PROPERTY_SET,
    "ACOUSTIC_SIGNATURE_PROPERTY_SET", "ECC_ACOUSTIC_SIGNATURE_PROPERTY_SET",
    "A <PROPERTY_SET> describing the sound spectrum of an acoustic source"
    " and/or emitter; an acoustic signature property set.",
    2, &(EGBindingForEC[94]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ACOUSTIC_STATION,
    "ACOUSTIC_STATION", "ECC_ACOUSTIC_STATION",
    "An <ACOUSTIC_DATA_COLLECTION_DEVICE> and support <STRUCTURE>s; an"
    " acoustic station.",
    2, &(EGBindingForEC[83]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BK010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ACOUSTIC_TRANSDUCER,
    "ACOUSTIC_TRANSDUCER", "ECC_ACOUSTIC_TRANSDUCER",
    "A <DEVICE> to transform acoustic energy to and/or from electrical"
    " energy; an acoustic transducer.",
    3, &(EGBindingForEC[85]),
    EDCS_REF_TYP_INFORMATIVE, "[PUWS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ADMINISTRATION_BUILDING,
    "ADMINISTRATION_BUILDING", "ECC_ADMINISTRATION_BUILDING",
    "A <BUILDING> devoted to the act and/or process of administration or"
    " management.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ADMINISTRATIVE_BOUNDARY,
    "ADMINISTRATIVE_BOUNDARY", "ECC_ADMINISTRATIVE_BOUNDARY",
    "A <BOUNDARY> between administratively controlled <REGION>s.",
    3, &(EGBindingForEC[111]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FA000]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ADMINISTRATIVE_REGION,
    "ADMINISTRATIVE_REGION", "ECC_ADMINISTRATIVE_REGION",
    "A <REGION> controlled by an administrative authority.",
    1, &(EGBindingForEC[2]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: ADMARE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERATION_STRUCTURE,
    "AERATION_STRUCTURE", "ECC_AERATION_STRUCTURE",
    "A <STRUCTURE> for aerating <WATER> by either passing <AIR> through"
    " <WATER> or passing <WATER> through <AIR>.",
    2, &(EGBindingForEC[989]),
    EDCS_REF_TYP_INFORMATIVE, "[BRG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERIAL,
    "AERIAL", "ECC_AERIAL",
    "A <DEVICE> used to transmit and/or receive electromagnetic energy; an"
    " aerial [SOED, \"aerial\", B].",
    4, &(EGBindingForEC[430]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERIAL_CABLE,
    "AERIAL_CABLE", "ECC_AERIAL_CABLE",
    "A <LOAD_CABLE> that is strung between <AERIAL_CABLE_PYLON>s as a"
    " <COMPONENT> of a <CONVEYOR> on which carrier units (for example: cars"
    " and/or buckets) are suspended; an aerial cable.",
    2, &(EGBindingForEC[1178]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERIAL_CABLE_PYLON,
    "AERIAL_CABLE_PYLON", "ECC_AERIAL_CABLE_PYLON",
    "A <PYLON> supporting an <AERIAL_CABLE>; an aerial cable pylon.",
    2, &(EGBindingForEC[1178]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERIAL_CABLE_SET,
    "AERIAL_CABLE_SET", "ECC_AERIAL_CABLE_SET",
    "A <SET> of one or more <AERIAL_CABLE>s.",
    2, &(EGBindingForEC[1178]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERIAL_SUPPORT_MAST,
    "AERIAL_SUPPORT_MAST", "ECC_AERIAL_SUPPORT_MAST",
    "A <MAST> supporting an <AERIAL>.",
    4, &(EGBindingForEC[466]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ021]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERODROME,
    "AERODROME", "ECC_AERODROME",
    "A defined <TRACT> or <WATERBODY_SURFACE_REGION> (including"
    " <BUILDING>s, <FACILITY>s, and/or <EQUIPMENT>) intended to be used"
    " either wholly or in part for the arrival, departure, and movement of"
    " <AIRCRAFT> on a <PLANETARY_SURFACE>; an aerodrome.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_INFORMATIVE, "[IAN14, Volume I]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERODROME_ELEVATION_POINT,
    "AERODROME_ELEVATION_POINT", "ECC_AERODROME_ELEVATION_POINT",
    "The highest <LOCATION> of the usable <RUNWAY>s of an <AERODROME>"
    " measured with respect to a <SURFACE_DATUM>; an aerodrome elevation"
    " point.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB059]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERODROME_LIGHTING,
    "AERODROME_LIGHTING", "ECC_AERODROME_LIGHTING",
    "A <NON_EMPTY_SET> of <LIGHT>s used to: define and outline <COMPONENT>s"
    " of <AERODROME>s such as perimeters, <RUNWAY>s, and <TAXIWAY>s; guide"
    " <AIRCRAFT> while on a <PLANETARY_SURFACE>; and provide guidance to"
    " <AIRCRAFT> on approach for landing.",
    3, &(EGBindingForEC[241]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERODROME_REVETMENT,
    "AERODROME_REVETMENT", "ECC_AERODROME_REVETMENT",
    "A <REVETMENT> at an <AERODROME>.",
    3, &(EGBindingForEC[258]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERODROME_TERMINAL,
    "AERODROME_TERMINAL", "ECC_AERODROME_TERMINAL",
    "A <BUILDING> located at an <AERODROME> used for disembarking and/or"
    " taking on passengers or <CARGO>; an aerodrome terminal.",
    3, &(EGBindingForEC[258]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERONAUTICAL_AID_TO_NAVIGATION,
    "AERONAUTICAL_AID_TO_NAVIGATION", "ECC_AERONAUTICAL_AID_TO_NAVIGATION",
    "An aeronautical <AID_TO_NAVIGATION>.",
    3, &(EGBindingForEC[221]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GA035]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERONAUTICAL_COMM_FACILITY,
    "AERONAUTICAL_COMM_FACILITY", "ECC_AERONAUTICAL_COMM_FACILITY",
    "A <FACILITY> supporting an <AERONAUTICAL_COMM_SERVICE>.",
    4, &(EGBindingForEC[207]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERONAUTICAL_COMM_SERVICE,
    "AERONAUTICAL_COMM_SERVICE", "ECC_AERONAUTICAL_COMM_SERVICE",
    "A telecommunication service that supports aviation; an aeronautical"
    " communication service.",
    3, &(EGBindingForEC[211]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AERONAUTICAL_LEAD_RADIAL,
    "AERONAUTICAL_LEAD_RADIAL", "ECC_AERONAUTICAL_LEAD_RADIAL",
    "A <DIRECTION> that provides at least 3 218,7 metres (2 miles) of lead"
    " to assist in turning an <AIRCRAFT> onto the intermediate portion of"
    " an instrument approach when the angle of intercept is greater than 90"
    " arc degrees; an aeronautical lead radial.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA031]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AEROSOL,
    "AEROSOL", "ECC_AEROSOL",
    "A colloidal <SYSTEM> in which the dispersed phase is composed of"
    " either solid or liquid <PARTICLE>s and the dispersion medium is a"
    " gas, usually <AIR>; an aerosol.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"aerosol\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AGRICULTURAL_FACILITY,
    "AGRICULTURAL_FACILITY", "ECC_AGRICULTURAL_FACILITY",
    "A <FACILITY> involved in crop production, the raising of livestock,"
    " and/or the storage or transportation of either <MATERIAL>s important"
    " to or the results of agricultural production.",
    5, &(EGBindingForEC[150]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AID_TO_NAVIGATION,
    "AID_TO_NAVIGATION", "ECC_AID_TO_NAVIGATION",
    "A <DEVICE> designed to assist in the determination of a safe course"
    " for, or the <LOCATION> of, a <VEHICLE>, and/or to warn of dangers and"
    " obstructions; an aid to navigation. EXAMPLES <LIGHT>, <DISPLAY_SIGN>,"
    " electronic <BEACON>.",
    2, &(EGBindingForEC[616]),
    EDCS_REF_TYP_INFORMATIVE, "[AIM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIR,
    "AIR", "ECC_AIR",
    "The gaseous <MATERIAL>s that comprise an <ATMOSPHERE>.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"atmosphere\", I.1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIR_DEFENCE_ARTILLERY,
    "AIR_DEFENCE_ARTILLERY", "ECC_AIR_DEFENCE_ARTILLERY",
    "Ground based surface to air <WEAPON>s for engaging <AIRCRAFT> and"
    " <MISSILE> targets; air defence artillery.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_INFORMATIVE, "[F3-01]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIR_MASS,
    "AIR_MASS", "ECC_AIR_MASS",
    "A widespread body of <AIR> that was established while situated over a"
    " <REGION> of the <PLANETARY_SURFACE> of the <EARTH> and that undergoes"
    " specific modifications while in transit away from that <REGION>; an"
    " air mass. An air mass is often approximately homogeneous in its"
    " horizontal extent (for example: <<AIR_TEMPERATURE>> and/or moisture"
    " distribution) and the vertical inhomogeneities are approximately the"
    " same over its horizontal extent.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"air mass\", 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIR_TRAFFIC_SERVICE,
    "AIR_TRAFFIC_SERVICE", "ECC_AIR_TRAFFIC_SERVICE",
    "A <NON_EMPTY_SET> of <AERONAUTICAL_COMM_SERVICE>s supporting air"
    " traffic management. EXAMPLES Flight information services, alerting"
    " services, air traffic advisory services, air traffic control services.",
    3, &(EGBindingForEC[211]),
    EDCS_REF_TYP_INFORMATIVE, "[IAN11]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIR_TRANSPORTATION_ROUTE,
    "AIR_TRANSPORTATION_ROUTE", "ECC_AIR_TRANSPORTATION_ROUTE",
    "A <TRANSPORTATION_ROUTE> located principally in the <AIR>.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIR_WARNING_LIGHT,
    "AIR_WARNING_LIGHT", "ECC_AIR_WARNING_LIGHT",
    "A <NON_EMPTY_SET> of <LIGHT>s marking an obstacle that constitutes a"
    " danger to air navigation; an air warning light.",
    3, &(EGBindingForEC[241]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA065]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRBURST_SMOKE,
    "AIRBURST_SMOKE", "ECC_AIRBURST_SMOKE",
    "<SMOKE> resulting from the explosion of a <MUNITION> in the <AIR>;"
    " airburst smoke.",
    3, &(EGBindingForEC[287]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRCRAFT,
    "AIRCRAFT", "ECC_AIRCRAFT",
    "A <VEHICLE> that is used, or intended to be used, for flight in an"
    " <ATMOSPHERE>; an aircraft.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"aircraft\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRCRAFT_CARRIER,
    "AIRCRAFT_CARRIER", "ECC_AIRCRAFT_CARRIER",
    "A <WATER_SURFACE_VESSEL> designed to carry <AIRCRAFT> and operate as a"
    " naval air base, with a flat deck for take off and landing operations"
    " at <SEA>; an aircraft carrier.",
    5, &(EGBindingForEC[224]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"aircraft carrier\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRCRAFT_HANGAR,
    "AIRCRAFT_HANGAR", "ECC_AIRCRAFT_HANGAR",
    "A <BUILDING> used for the storage of <AIRCRAFT>; an aircraft hangar"
    " [SOED, \"hangar\"].",
    3, &(EGBindingForEC[258]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRCRAFT_LANDING_ZONE,
    "AIRCRAFT_LANDING_ZONE", "ECC_AIRCRAFT_LANDING_ZONE",
    "A designated <REGION> of a <PLANETARY_SURFACE> where landing by"
    " <AIRCRAFT> is possible; a landing zone.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRCRAFT_MAINTENANCE_SHOP,
    "AIRCRAFT_MAINTENANCE_SHOP", "ECC_AIRCRAFT_MAINTENANCE_SHOP",
    "A <BUILDING>, usually located at an <AERODROME>, used for keeping"
    " <AIRCRAFT> in a condition of good repair and/or efficiency; an"
    " aircraft maintenance shop.",
    3, &(EGBindingForEC[258]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:29]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRCRAFT_PARKING_FACILITY,
    "AIRCRAFT_PARKING_FACILITY", "ECC_AIRCRAFT_PARKING_FACILITY",
    "A defined paved or hard-packed <TRACT> at an <AERODROME> intended as a"
    " parking <FACILITY> for <AIRCRAFT>. EXAMPLES <APRON>, <HARD_STANDING>.",
    4, &(EGBindingForEC[261]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB015]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRCRAFT_STORAGE_TRACT,
    "AIRCRAFT_STORAGE_TRACT", "ECC_AIRCRAFT_STORAGE_TRACT",
    "A defined paved or hard-packed <TRACT> intended for long-term parking"
    " and storage of <AIRCRAFT>.",
    4, &(EGBindingForEC[261]),
    EDCS_REF_TYP_INFORMATIVE, "[DFAD, 864, \"Aircraft Storage Area\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRCRAFT_WRECKAGE,
    "AIRCRAFT_WRECKAGE", "ECC_AIRCRAFT_WRECKAGE",
    "Wreckage of an <AIRCRAFT> that is isolated, conspicuous, and can be"
    " used as a landmark.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRFIELD,
    "AIRFIELD", "ECC_AIRFIELD",
    "An <AIRPORT> with limited or absent <BUILDING>s, <FACILITY>s, and"
    " <EQUIPMENT>; an airfield.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB006]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRPORT,
    "AIRPORT", "ECC_AIRPORT",
    "A <AERODROME> on <LAND>; an airport.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB007]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRSHIP,
    "AIRSHIP", "ECC_AIRSHIP",
    "A powered <BALLOON> with a main chamber filled with a gas that is less"
    " dense than the surrounding <AIR>; an airship.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRSPACE,
    "AIRSPACE", "ECC_AIRSPACE",
    "An <ATMOSPHERE_REGION> where an <AIRCRAFT> operates; an airspace"
    " [SOED, \"airspace\"].",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GA005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRSPACE_BOUNDARY,
    "AIRSPACE_BOUNDARY", "ECC_AIRSPACE_BOUNDARY",
    "The <BOUNDARY> of an <AIRSPACE>.",
    4, &(EGBindingForEC[214]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRSPACE_BOUNDARY_COMPONENT,
    "AIRSPACE_BOUNDARY_COMPONENT", "ECC_AIRSPACE_BOUNDARY_COMPONENT",
    "A <COMPONENT> of an <AIRSPACE_BOUNDARY>.",
    3, &(EGBindingForEC[218]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GA020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRSPACE_COMPONENT,
    "AIRSPACE_COMPONENT", "ECC_AIRSPACE_COMPONENT",
    "A <COMPONENT> of an <AIRSPACE>.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AIRSTRIP,
    "AIRSTRIP", "ECC_AIRSTRIP",
    "An <AIRFIELD> with very limited <FACILITY>s; an airstrip.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"airstrip\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_ALGA,
    "ALGA", "ECC_ALGA",
    "A <PROTIST> capable of photosynthesis; an alga [SOED, \"alga\"]."
    " EXAMPLES <SEAWEED>, many unicellular and filamentous"
    " <LIVING_ORGANISM>s.",
    1, &(EGBindingForEC[31]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ALKALI_FLAT,
    "ALKALI_FLAT", "ECC_ALKALI_FLAT",
    "A sterile <TERRAIN_PLAIN> containing an excess of alkali, usually"
    " occurring in the bottom of an under-drained <GEOGRAPHIC_BASIN> in an"
    " arid or semi-arid <TERRAIN_SURFACE_REGION>; the <LAND> may be soft,"
    " have low shearing and bearing strength, and a high organic content;"
    " an alkali flat.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DA006]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ALLUVIAL_FAN,
    "ALLUVIAL_FAN", "ECC_ALLUVIAL_FAN",
    "A gently sloping, fan-shaped configuration of the <TERRAIN>, usually"
    " found near the lower termination of a <CANYON>; an alluvial fan.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB230]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMBASSADORIAL_RESIDENCE,
    "AMBASSADORIAL_RESIDENCE", "ECC_AMBASSADORIAL_RESIDENCE",
    "A <BUILDING> serving as the <DWELLING> of a diplomatic official of the"
    " highest rank appointed and accredited as representative in residence"
    " by one government or sovereign to another; an ambassadorial residence.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:65]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMPHIBIAN,
    "AMPHIBIAN", "ECC_AMPHIBIAN",
    "A <VERTEBRATE> of the class Amphibia; an amphibian [SOED,"
    " \"amphibian\", B].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMPHIBIOUS_AIR_CUSHION_VEHICLE,
    "AMPHIBIOUS_AIR_CUSHION_VEHICLE", "ECC_AMPHIBIOUS_AIR_CUSHION_VEHICLE",
    "An <AMPHIBIOUS_VEHICLE> designed to generate and move over a cushion"
    " of trapped <AIR> that supports the <VEHICLE> above the"
    " <PLANETARY_SURFACE>.",
    4, &(EGBindingForEC[803]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMPHIBIOUS_ARMOURED_VEHICLE,
    "AMPHIBIOUS_ARMOURED_VEHICLE", "ECC_AMPHIBIOUS_ARMOURED_VEHICLE",
    "An <AMPHIBIOUS_VEHICLE> that is <<ARMOURED>>.",
    5, &(EGBindingForEC[795]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMPHIBIOUS_UTILITY_VEHICLE,
    "AMPHIBIOUS_UTILITY_VEHICLE", "ECC_AMPHIBIOUS_UTILITY_VEHICLE",
    "An <AMPHIBIOUS_VEHICLE> designed or designated for utility operations.",
    4, &(EGBindingForEC[803]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMPHIBIOUS_VEHICLE,
    "AMPHIBIOUS_VEHICLE", "ECC_AMPHIBIOUS_VEHICLE",
    "A <VEHICLE> capable of operation either on a <WATERBODY_SURFACE> or on"
    " <LAND>; an amphibious vehicle.",
    4, &(EGBindingForEC[803]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMPHITHEATRE,
    "AMPHITHEATRE", "ECC_AMPHITHEATRE",
    "An oval or circular <BUILDING> with seats rising in tiers around the"
    " central open space, used for entertainment and/or public events; an"
    " amphitheatre [SOED, \"amphitheatre\", 1].",
    2, &(EGBindingForEC[1149]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMUSEMENT_PARK,
    "AMUSEMENT_PARK", "ECC_AMUSEMENT_PARK",
    "A predominantly man-made <RECREATIONAL_FACILITY> equipped with"
    " recreational <DEVICE>s; an amusement park.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AMUSEMENT_PARK_ATTRACTION,
    "AMUSEMENT_PARK_ATTRACTION", "ECC_AMUSEMENT_PARK_ATTRACTION",
    "A large <STRUCTURE> located in an <AMUSEMENT_PARK>; an amusement park"
    " attraction.",
    2, &(EGBindingForEC[1154]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANCHOR,
    "ANCHOR", "ECC_ANCHOR",
    "A <DEVICE> normally placed on a <WATERBODY_FLOOR>, attached to a"
    " <LOAD_CABLE>, and used to position a floating <OBJECT> (for example:"
    " a <VESSEL> and/or an <OFFSHORE_PLATFORM>); an anchor.",
    5, &(EGBindingForEC[575]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: ACHPNT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANCHOR_BERTH,
    "ANCHOR_BERTH", "ECC_ANCHOR_BERTH",
    "A designated <WATERBODY_SURFACE_REGION> where a single<VEHICLE> (for"
    " example: a <VESSEL>, a <SEAPLANE>, a <OIL_DRILLING_RIG>, and/or other"
    " watercraft) is anchored or may anchor; an anchor berth.",
    4, &(EGBindingForEC[229]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: ACHBRT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANCHORAGE,
    "ANCHORAGE", "ECC_ANCHORAGE",
    "A <WATERBODY_SURFACE_REGION> where <VESSEL>s may anchor; an anchorage.",
    3, &(EGBindingForEC[835]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: ACHARE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANCHORAGE_COMPLEX,
    "ANCHORAGE_COMPLEX", "ECC_ANCHORAGE_COMPLEX",
    "An <ANCHORAGE> plus related <NAVIGATION_MARK_FIXED>s and/or"
    " <NAVIGATION_MARK_AFLOAT>s; an anchorage complex.",
    3, &(EGBindingForEC[835]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB011]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANEMOMETER,
    "ANEMOMETER", "ECC_ANEMOMETER",
    "A <WIND_INDICATOR> designed to measure total <<WIND_SPEED>> or the"
    " <<SPEED>> of one or more linear (vector) components of the <WIND>; an"
    " anemometer.",
    2, &(EGBindingForEC[365]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"anemometer\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANIMAL,
    "ANIMAL", "ECC_ANIMAL",
    "A <LIVING_ORGANISM> of the kingdom Animalia, having sensation and"
    " voluntary motion, without rigid cell walls, and dependent on organic"
    " substances for food; an animal [SOED, \"animal\", 1.a].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANIMAL_PARK,
    "ANIMAL_PARK", "ECC_ANIMAL_PARK",
    "A <REGION> with a collection of live <NON_HUMAN_ANIMAL>s, usually for"
    " public display; an animal park.",
    4, &(EGBindingForEC[345]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK180]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANIMAL_SANCTUARY,
    "ANIMAL_SANCTUARY", "ECC_ANIMAL_SANCTUARY",
    "A <REGION> that has been set aside for the preservation and protection"
    " of wild <NON_HUMAN_ANIMAL>s; an animal sanctuary.",
    2, &(EGBindingForEC[352]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ANTE_ROOM,
    "ANTE_ROOM", "ECC_ANTE_ROOM",
    "A <ROOM> before or forming an entrance to another; an ante-room [SOED,"
    " \"ante-room\"].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_APARTMENT_HOUSE,
    "APARTMENT_HOUSE", "ECC_APARTMENT_HOUSE",
    "A multi-residence <BUILDING> containing rental accommodations for hire"
    " on a long-term basis; an apartment house.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"apartment house\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_APERTURE,
    "APERTURE", "ECC_APERTURE",
    "An opening and/or hole in an <OBJECT>, especially a <STRUCTURE>; an"
    " aperture.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"aperture\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_APRON,
    "APRON", "ECC_APRON",
    "A usually paved <TRACT> located at an <AERODROME> where <AIRCRAFT> can"
    " park, load or unload, refuel, and/or undergo servicing; an apron"
    " [SOED, \"apron\", II.10].",
    4, &(EGBindingForEC[261]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB015]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AQUEDUCT,
    "AQUEDUCT", "ECC_AQUEDUCT",
    "A <PIPE> or artificial channel designed to transport <WATER> from a"
    " remote source, usually by gravity; an aqueduct.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AQUEDUCT_NEXUS,
    "AQUEDUCT_NEXUS", "ECC_AQUEDUCT_NEXUS",
    "A representation of one or more <AQUEDUCT>s, especially in a"
    " <BUILT_UP_REGION>; an aqueduct centre-line or aqueduct nexus.",
    2, &(EGBindingForEC[975]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARACHNID,
    "ARACHNID", "ECC_ARACHNID",
    "An <ARTHROPOD> of the class Arachnida; an arachnid [SOED,"
    " \"arachnid\"]. EXAMPLES Spider, scorpion, mite, tick.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARBORETUM,
    "ARBORETUM", "ECC_ARBORETUM",
    "A culturally designated <TRACT> where rare <TREE>s are cultivated and"
    " displayed; an arboretum [SOED, \"arboretum\"].",
    5, &(EGBindingForEC[181]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARCADE,
    "ARCADE", "ECC_ARCADE",
    "A covered pedestrian <ROUTE> composed of arches and pillars, usually"
    " open along one or both sides; an arcade.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ151]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARCHAELOGICAL_SITE,
    "ARCHAELOGICAL_SITE", "ECC_ARCHAELOGICAL_SITE",
    "A <SITE> where remains of ancient civilizations and/or the activities"
    " of <HUMAN>s have been discovered; an archaeological site.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL012]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARMISTICE_LINE,
    "ARMISTICE_LINE", "ECC_ARMISTICE_LINE",
    "A <BOUNDARY> established by opposing political groups as a result of"
    " cessation of hostilities; an armistice line.",
    4, &(EGBindingForEC[114]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FA020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARMOURED_BRIDGE_LAUNCHER,
    "ARMOURED_BRIDGE_LAUNCHER", "ECC_ARMOURED_BRIDGE_LAUNCHER",
    "A <COMBAT_SUPPORT_VEHICLE> that is <<ARMOURED>> and is capable of"
    " launching an AVLB; an armoured bridge launcher.",
    4, &(EGBindingForEC[1027]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARMOURED_FIGHTING_VEHICLE,
    "ARMOURED_FIGHTING_VEHICLE", "ECC_ARMOURED_FIGHTING_VEHICLE",
    "A <COMBATANT_VEHICLE> that is <<ARMOURED>> and mounted with guns or"
    " other armaments, often used to move groups of soldiers; an armoured"
    " fighting vehicle. EXAMPLES Infantry fighting <GROUND_VEHICLE>,"
    " armoured personnel carrier, self-propelled <MORTAR>, armoured car,"
    " chemical reconnaissance <VEHICLE>, anti-tank guided missile launcher.",
    4, &(EGBindingForEC[1027]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARMOURED_TRACKED_FIGHTING_VEHICLE,
    "ARMOURED_TRACKED_FIGHTING_VEHICLE", "ECC_ARMOURED_TRACKED_FIGHTING_VEHICLE",
    "A <ARMOURED_TRACKED_VEHICLE> that is heavily <<ARMOURED>>, mounted"
    " with cannon and guns; an armoured tracked fighting vehicle.",
    4, &(EGBindingForEC[1027]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARMOURED_TRACKED_VEHICLE,
    "ARMOURED_TRACKED_VEHICLE", "ECC_ARMOURED_TRACKED_VEHICLE",
    "A closed <COMBATANT_VEHICLE> that is <<ARMOURED>> and moves on"
    " caterpillar treads; an armoured tracked vehicle.",
    4, &(EGBindingForEC[1027]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARMOURED_UTILITY_VEHICLE,
    "ARMOURED_UTILITY_VEHICLE", "ECC_ARMOURED_UTILITY_VEHICLE",
    "A <COMBAT_SUPPORT_VEHICLE> that is <<ARMOURED>>. EXAMPLES Engineering"
    " <GROUND_VEHICLE>, tracked load carrier, towing <VEHICLE>, recovery"
    " <VEHICLE>.",
    4, &(EGBindingForEC[1027]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARMOURY,
    "ARMOURY", "ECC_ARMOURY",
    "A <BUILDING> for storing arms and military <EQUIPMENT>, especially one"
    " serving as headquarters for reserve <MILITARY_PERSONNEL>; an armoury"
    " [AHD, \"armory\", 1.b].",
    3, &(EGBindingForEC[125]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARRESTING_GEAR,
    "ARRESTING_GEAR", "ECC_ARRESTING_GEAR",
    "<EQUIPMENT> (for example: a <LOAD_CABLE> and/or a <BARRIER>) that can"
    " be used to stop an <AIRCRAFT> immediately upon landing; an arresting"
    " gear.",
    3, &(EGBindingForEC[221]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARTHROPOD,
    "ARTHROPOD", "ECC_ARTHROPOD",
    "An <INVERTEBRATE> of the phylum Arthropoda that is characterized by"
    " having a segmented body and jointed limbs; an arthropod [SOED,"
    " \"arthropod\"]. EXAMPLES <INSECT>, <ARACHNID>, <CRUSTACEAN>.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARTIFICIAL_SATELLITE,
    "ARTIFICIAL_SATELLITE", "ECC_ARTIFICIAL_SATELLITE",
    "A <SPACECRAFT> designed to be placed in orbit around a <PLANET> or,"
    " occasionally, another <CELESTIAL_BODY>; an artificial satellite"
    " [SOED, \"satellite\", A.2.c].",
    2, &(EGBindingForEC[1176]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ARTILLERY_BATTERY,
    "ARTILLERY_BATTERY", "ECC_ARTILLERY_BATTERY",
    "An emplacement for one or more pieces of <FIELD_ARTILLERY>; an"
    " artillery battery [SOED, \"battery\", II.4].",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ASPHALT_POOL,
    "ASPHALT_POOL", "ECC_ASPHALT_POOL",
    "A naturally-occurring pool of liquid asphalt.",
    1, &(EGBindingForEC[33]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DA005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ASSEMBLY_PLANT,
    "ASSEMBLY_PLANT", "ECC_ASSEMBLY_PLANT",
    "A <SITE> and associated <BUILDING>s used for the purpose of combining"
    " manufactured <COMPONENT>s to make a completed product; an assembly"
    " plant.",
    4, &(EGBindingForEC[949]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AE010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ASTEROID,
    "ASTEROID", "ECC_ASTEROID",
    "Any of numerous small <CELESTIAL_BODY>s in the <SOLAR_SYSTEM> of the"
    " <SUN>, with orbits lying chiefly between <MARS> and <JUPITER>, and"
    " characteristic <<OUTSIDE_DIAMETER>>s between a few and several"
    " hundred kilometres; a minor planet, planetoid, or asteroid [SOED,"
    " \"asteroid\", A.1].",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ASTRONOMIC_PROPERTY_SET,
    "ASTRONOMIC_PROPERTY_SET", "ECC_ASTRONOMIC_PROPERTY_SET",
    "A <PROPERTY_SET> containing information about <CELESTIAL_BODY>s and"
    " other astronomical matters.",
    2, &(EGBindingForEC[1140]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ASTRONOMICAL_STATION,
    "ASTRONOMICAL_STATION", "ECC_ASTRONOMICAL_STATION",
    "A <STRUCTURE> used for the scientific study of matter in <SPACE>,"
    " especially the <LOCATION>s, dimensions, distribution, motion,"
    " composition, energy, and evolution of <CELESTIAL_BODY>s or celestial"
    " phenomena; an astronomical station.",
    2, &(EGBindingForEC[1166]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ASW_HELICOPTER,
    "ASW_HELICOPTER", "ECC_ASW_HELICOPTER",
    "A <HELICOPTER> designed or designated for ASW operations.",
    4, &(EGBindingForEC[254]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ASW_WINGED_AIRCRAFT,
    "ASW_WINGED_AIRCRAFT", "ECC_ASW_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed or designated for ASW operations.",
    4, &(EGBindingForEC[254]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATHLETIC_COMPLEX,
    "ATHLETIC_COMPLEX", "ECC_ATHLETIC_COMPLEX",
    "A <SITE> and associated <STRUCTURE>s used for recreational exercise"
    " and major sports competitions, which typically serves a large"
    " metropolitan <BUILT_UP_REGION>; an athletic complex.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATHLETIC_FIELD,
    "ATHLETIC_FIELD", "ECC_ATHLETIC_FIELD",
    "An open <TRACT> where sporting events, exercises, and/or games occur;"
    " an athletic field.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATMOSPHERE,
    "ATMOSPHERE", "ECC_ATMOSPHERE",
    "A gaseous envelope gravitationally bound to a <CELESTIAL_BODY>; an"
    " atmosphere.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"atmosphere\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATMOSPHERE_PROPERTY_SET,
    "ATMOSPHERE_PROPERTY_SET", "ECC_ATMOSPHERE_PROPERTY_SET",
    "A <PROPERTY_SET> describing a <LOCATION> in the <ATMOSPHERE> or an"
    " <ATMOSPHERE_REGION>.",
    3, &(EGBindingForEC[388]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATMOSPHERE_REGION,
    "ATMOSPHERE_REGION", "ECC_ATMOSPHERE_REGION",
    "A <REGION> of an <ATMOSPHERE>.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATMOSPHERIC_FRONT,
    "ATMOSPHERIC_FRONT", "ECC_ATMOSPHERIC_FRONT",
    "The <BOUNDARY> or transition zone between <AIR_MASS>s of different"
    " <<AIR_DENSITY>>s; an atmospheric front.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"front\", 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATRIUM,
    "ATRIUM", "ECC_ATRIUM",
    "A central court that is located in a <BUILDING>, rises through one or"
    " more <FLOOR_LEVEL>s, is surrounded by galleries at each <FLOOR_LEVEL>"
    " with <ROOM>s opening off, and is often skylighted; an atrium.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"atrium\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATS_ROUTE,
    "ATS_ROUTE", "ECC_ATS_ROUTE",
    "A specified <AIR_TRANSPORTATION_ROUTE> designed for channelling the"
    " flow of <AIRCRAFT> as necessary for the provision of"
    " <AIR_TRAFFIC_SERVICE>s; an ATS route.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14, Volume I], [IAN11]", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATS_ROUTE_COMPONENT,
    "ATS_ROUTE_COMPONENT", "ECC_ATS_ROUTE_COMPONENT",
    "A <COMPONENT> of an <ATS_ROUTE> that is defined by two <LOCATION>s"
    " specified in a flight plan; these <LOCATION>s are either continental"
    " geographical <LOCATION>s, insular geographical <LOCATION>s, or"
    " <LOCATION>s at which a definite radio fix can be established.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_INFORMATIVE, "[IVAO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATTACK_HELICOPTER,
    "ATTACK_HELICOPTER", "ECC_ATTACK_HELICOPTER",
    "A <HELICOPTER> designed for military attack operations.",
    4, &(EGBindingForEC[254]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATTACK_WINGED_AIRCRAFT,
    "ATTACK_WINGED_AIRCRAFT", "ECC_ATTACK_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed for military attack operations.",
    4, &(EGBindingForEC[254]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ATTIC,
    "ATTIC", "ECC_ATTIC",
    "The highest <FLOOR_LEVEL> of a <BUILDING>, usually immediately under"
    " the beams of the <ROOF>, or a <ROOM> in this location; an attic"
    " [SOED, \"attic\", B.2] or garret.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AUDITORIUM,
    "AUDITORIUM", "ECC_AUDITORIUM",
    "A large <BUILDING> for public meetings and/or performances; an"
    " auditorium.",
    2, &(EGBindingForEC[1149]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"auditorium\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_AURORA,
    "AURORA", "ECC_AURORA",
    "Luminous phenomena, in the form of arcs, bands, draperies, and/or"
    " curtains in a high <ATMOSPHERE_REGION> caused by charged <PARTICLE>s"
    " from <SPACE>, mainly at high latitudes; an aurora.",
    2, &(EGBindingForEC[391]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"aurora\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AURORA_OVAL,
    "AURORA_OVAL", "ECC_AURORA_OVAL",
    "The locus of structured <AURORA> around each <PLANETARY_MAGNETIC_POLE>"
    " of the <EARTH>, roughly forming an oval band between 60 and 70"
    " degrees latitude in both northern and southern hemispheres; an aurora"
    " oval.",
    2, &(EGBindingForEC[391]),
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AUTOMATED_TELLER_MACHINE,
    "AUTOMATED_TELLER_MACHINE", "ECC_AUTOMATED_TELLER_MACHINE",
    "A <DEVICE> that provides money and/or performs banking services when a"
    " special card is inserted and a password is typed in; an automated"
    " teller machine [SOED, \"teller\", II.2.a; \"automated teller"
    " machine\"].",
    2, &(EGBindingForEC[597]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AUTOMOTIVE_PLANT,
    "AUTOMOTIVE_PLANT", "ECC_AUTOMOTIVE_PLANT",
    "A <HEAVY_INDUSTRIAL_FACILITY> used for the purpose of manufacturing"
    " <MOTOR_VEHICLE>s; an automotive plant.",
    6, &(EGBindingForEC[925]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:120]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_AVIATION_NAVIGATION_MARKER,
    "AVIATION_NAVIGATION_MARKER", "ECC_AVIATION_NAVIGATION_MARKER",
    "An <AERONAUTICAL_AID_TO_NAVIGATION> used as a guide to a pilot of an"
    " <AIRCRAFT> seeking a particular <REGION> and/or avoiding a"
    " <MAN_MADE_AIR_OBSTRUCTION>; an aviation navigation marker. EXAMPLES"
    " Flare, distinctive <DISPLAY_SIGN>.",
    3, &(EGBindingForEC[221]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"marker\", 3.c]", EDCS_CONCEPT_STAT_ISO },

    {ECC_AVIATION_WAYPOINT,
    "AVIATION_WAYPOINT", "ECC_AVIATION_WAYPOINT",
    "A <WAYPOINT> used in aviation.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_INFORMATIVE, "[IAN11]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BACKSHORE_PRECISE,
    "BACKSHORE_PRECISE", "ECC_BACKSHORE_PRECISE",
    "The <TERRAIN_STRIP> that is located between the normal limit of the"
    " action of <WATER_WAVE>s above either mean high water springs or mean"
    " higher high water as defined by a National Authority and the maximum"
    " limit of the action of <WATER_WAVE>s; the backshore precise.",
    2, &(EGBindingForEC[1066]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BA022]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BALCONY,
    "BALCONY", "ECC_BALCONY",
    "A platform projecting from the <WALL> of a <BUILDING>, supported by"
    " pillars and/or brackets, and enclosed by a balustrade or low <WALL>;"
    " a balcony or deck.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"balcony\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_BALLOON,
    "BALLOON", "ECC_BALLOON",
    "An <AIRCRAFT> consisting of an airtight envelope designed to rise into"
    " the <ATMOSPHERE> when inflated with a gas that is less dense than"
    " <AIR> (for example: hot <AIR>), carrying a basket or car for"
    " passengers; a balloon.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BAMBOO,
    "BAMBOO", "ECC_BAMBOO",
    "A <PLANT> belonging to the genus Bambusa, Arundinaria, Phyllostachys,"
    " Sasa, or Dendrocalamus, most having hard, hollow stems; a bamboo"
    " [SOED, \"bamboo\", A.1].",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EC010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BAMBOO_TRACT,
    "BAMBOO_TRACT", "ECC_BAMBOO_TRACT",
    "A <TRACT> of <BAMBOO>.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EC010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BANK_BUILDING,
    "BANK_BUILDING", "ECC_BANK_BUILDING",
    "A <BUILDING> housing an establishment for the deposit, custody, and"
    " issue of money; for making loans and discounts; and for making easier"
    " the exchange of funds by certificates, checks, and/or notes; a bank"
    " [SOED, \"bank\", n3.3].",
    2, &(EGBindingForEC[984]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BARN,
    "BARN", "ECC_BARN",
    "A <FARM_BUILDING> that is used to store hay, grain, and implements"
    " and/or to house <NON_HUMAN_ANIMAL>s; a barn [SOED, \"barn\", A.1]"
    " [SOED, \"barn\", A.2].",
    4, &(EGBindingForEC[155]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BARRACK,
    "BARRACK", "ECC_BARRACK",
    "A <BUILDING> used to house <MILITARY_PERSONNEL>, which is typically"
    " large, unadorned, and intended for relatively temporary occupancy; a"
    " barrack.",
    2, &(EGBindingForEC[1119]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"barrack\", 2b]", EDCS_CONCEPT_STAT_ISO },

    {ECC_BARREN_GROUND,
    "BARREN_GROUND", "ECC_BARREN_GROUND",
    "<TERRAIN> so disturbed as to have no identifiable <VEGETATION>; barren"
    " ground.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DA020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BARRIER,
    "BARRIER", "ECC_BARRIER",
    "A physical obstacle that prevents access and/or separates; a barrier"
    " [SOED, \"barrier\", 1].",
    1, &(EGBindingForEC[13]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AP041]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BASEMENT,
    "BASEMENT", "ECC_BASEMENT",
    "A <FLOOR_LEVEL> of a <BUILDING> located wholly or partially below the"
    " level of the <LAND>; a basement [SOED, \"basement\", 1].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BAT,
    "BAT", "ECC_BAT",
    "A flying <MAMMAL> of the order Chiroptera, the members of which are"
    " mainly nocturnal and have forelimbs that support membranous wings"
    " extending to the tail; a bat [SOED, \"bat\", 3].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BATHYMETRIC_PROVINCE,
    "BATHYMETRIC_PROVINCE", "ECC_BATHYMETRIC_PROVINCE",
    "A <WATERBODY_FLOOR_PROVINCE> of homogeneous bathymetric"
    " characteristics; a bathymetric province.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"bathymetric province\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BATTLESHIP,
    "BATTLESHIP", "ECC_BATTLESHIP",
    "A <WATER_SURFACE_VESSEL> of the most heavily armed and <<ARMOURED>>"
    " class, of sufficient size to take part in a main attack; a battleship"
    " [SOED, \"battleship\"].",
    4, &(EGBindingForEC[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BEACH,
    "BEACH", "ECC_BEACH",
    "The <SHORE> of a <WATERBODY> that consists of unconsolidated"
    " <MATERIAL>s (for example: <SAND> and/or small <STONE>s), including"
    " the <FORESHORE> and the <BACKSHORE_PRECISE>; a beach.",
    2, &(EGBindingForEC[1066]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"beach\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BEACH_PROFILE,
    "BEACH_PROFILE", "ECC_BEACH_PROFILE",
    "A representation of the vertical relief of a <WATERBODY_FLOOR> and"
    " adjacent <LAND> along a <LINE> or <SET> of connected <LINE>s"
    " generally established perpendicular to the local <SHORELINE> and"
    " based on <DEPTH_CONTOUR_LINE>s, <SOUNDING>s, and other measurements"
    " of the depth at or below a shared <SURFACE_DATUM>; a beach profile.",
    4, &(EGBindingForEC[1068]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BE050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BEACH_ZONE,
    "BEACH_ZONE", "ECC_BEACH_ZONE",
    "A <TRACT> defined from the <SHORE> inland for a predetermined distance"
    " and/or to the first existence of a <LAND_TRANSPORTATION_ROUTE> and"
    " from the <SHORE> seaward to a predetermined depth; a beach zone.",
    4, &(EGBindingForEC[1004]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BA050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BEACON,
    "BEACON", "ECC_BEACON",
    "A fixed, usually elevated, <DEVICE> that serves as an"
    " <AID_TO_NAVIGATION>, usually functioning by emitting a signal (for"
    " example: a flashing <LIGHT> or a radar pulse) warning of its"
    " <LOCATION>; a beacon.",
    4, &(EGBindingForEC[447]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: BCNSPP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BEDROCK,
    "BEDROCK", "ECC_BEDROCK",
    "Solid <ROCK> underlying alluvial deposits; bedrock [SOED, \"bedrock\"].",
    2, &(EGBindingForEC[1107]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BENCHMARK,
    "BENCHMARK", "ECC_BENCHMARK",
    "A reference mark on a permanent <OBJECT> indicating <<ELEVATION>>; a"
    " benchmark.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZB020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BIOLOGIC_HAZARD_REGION,
    "BIOLOGIC_HAZARD_REGION", "ECC_BIOLOGIC_HAZARD_REGION",
    "A <REGION> in which a biologic substance is present that can kill,"
    " seriously injure, or incapacitate a <HUMAN> and/or <NON_HUMAN_ANIMAL>"
    " through its physiological properties. The biologic substance is"
    " usually dispersed over a <SURFACE> and/or within the <ATMOSPHERE>.",
    3, &(EGBindingForEC[383]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BIOLUMINESCENCE,
    "BIOLUMINESCENCE", "ECC_BIOLUMINESCENCE",
    "The production of light without sensible heat by <LIVING_ORGANISM>s as"
    " a result of chemical reaction either within cells or organs or"
    " extracellulary in some form of secretion; bioluminescence.",
    2, &(EGBindingForEC[1058]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"bioluminescence\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BIRD,
    "BIRD", "ECC_BIRD",
    "A <VERTEBRATE> of the class Aves, characterized by forelimbs as wings"
    " for flight, oviparous reproduction, and care for the young; a bird"
    " [SOED, \"bird\", B].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BLAST_BARRIER,
    "BLAST_BARRIER", "ECC_BLAST_BARRIER",
    "A <BARRIER> used to divert and/or dissipate jet or propeller blast.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB025]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BLAST_FURNACE,
    "BLAST_FURNACE", "ECC_BLAST_FURNACE",
    "A smelting <FURNACE> in which a blast of <AIR> is used, especially one"
    " for iron-smelting using a compressed hot blast of <AIR>; a blast"
    " furnace.",
    3, &(EGBindingForEC[962]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AC010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BLIMP,
    "BLIMP", "ECC_BLIMP",
    "A small <AIRSHIP> that does not have a rigid frame; a blimp.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BLOCKHOUSE,
    "BLOCKHOUSE", "ECC_BLOCKHOUSE",
    "A military <FORTIFICATION> constructed of sturdy <MATERIAL>s (for"
    " example: concrete) and designed with <WALL_LOOPHOLE>s; a blockhouse"
    " [SOED, \"blockhouse\", a].",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOARDWALK,
    "BOARDWALK", "ECC_BOARDWALK",
    "A walkway made of wooden planks; a boardwalk.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOAT_LIFT,
    "BOAT_LIFT", "ECC_BOAT_LIFT",
    "A mechanical <DEVICE> other than a <HYDROGRAPHIC_LOCK> for lifting"
    " <WATER_SURFACE_VESSEL>s between two levels; a boat lift.",
    2, &(EGBindingForEC[700]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOAT_TURNING_BASIN,
    "BOAT_TURNING_BASIN", "ECC_BOAT_TURNING_BASIN",
    "A section of <CANAL> and/or <NAVIGABLE_WATERWAY> in which a barge or"
    " other <WATER_SURFACE_VESSEL> can be turned; a boat turning basin.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOG,
    "BOG", "ECC_BOG",
    "A <WETLAND> having a wet, spongy, acidic substrate composed chiefly of"
    " sphagnum moss and peat in which characteristic <SHRUB>s, herbs, and,"
    " sometimes, <TREE>s usually grow; a bog [AHD, \"bog\", 1a].",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH015]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOLLARD,
    "BOLLARD", "ECC_BOLLARD",
    "A post on a <WHARF> used for fastening <MOORING_LINE>s; a bollard.",
    1, &(EGBindingForEC[19]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOMBER_WINGED_AIRCRAFT,
    "BOMBER_WINGED_AIRCRAFT", "ECC_BOMBER_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed to carry and drop heavy loads of bombs; a"
    " bomber.",
    4, &(EGBindingForEC[254]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOMBORA_REGION,
    "BOMBORA_REGION", "ECC_BOMBORA_REGION",
    "A <WATERBODY_REGION> where <WATER_WAVE>s form over a submerged"
    " offshore <SHOAL>, sometimes (in very calm weather and/or at high"
    " <TIDE>) nearly swelling but in other conditions breaking heavily and"
    " producing a dangerous stretch of broken <WATER>; a bombora.",
    2, &(EGBindingForEC[874]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute, CATWAT:5]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOTANICAL_GARDEN,
    "BOTANICAL_GARDEN", "ECC_BOTANICAL_GARDEN",
    "A culturally designated <TRACT> where <PLANT>s are displayed; a"
    " botanical garden.",
    5, &(EGBindingForEC[181]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EA031]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOTTOM_CHARACTERISTIC,
    "BOTTOM_CHARACTERISTIC", "ECC_BOTTOM_CHARACTERISTIC",
    "A characteristic (for example: consistency, colour, and/or"
    " classification) of the <OCEAN_FLOOR>; bottom characteristic.",
    1, &(EGBindingForEC[52]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BF010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOULDER_FIELD,
    "BOULDER_FIELD", "ECC_BOULDER_FIELD",
    "A <TERRAIN_SURFACE_REGION> characterized by detached masses of <ROCK>"
    " usually having an <<OUTSIDE_DIAMETER>> greater than 25 centimetres; a"
    " boulder field.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOUNDARY,
    "BOUNDARY", "ECC_BOUNDARY",
    "The limits of a <REGION>; that is, a <NON_EMPTY_SET> of <LOCATION>s"
    " characterized by the fact that any <LOCATION> included in the"
    " <NON_EMPTY_SET> is arbitrarily near to <LOCATION>s that are not"
    " contained in the given <REGION> as well as to <LOCATION>s that are"
    " contained in the given <REGION>; a boundary.",
    2, &(EGBindingForEC[540]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOUNDARY_COMPONENT,
    "BOUNDARY_COMPONENT", "ECC_BOUNDARY_COMPONENT",
    "A <COMPONENT> of a <BOUNDARY>.",
    2, &(EGBindingForEC[540]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BOUNDARY_MONUMENT,
    "BOUNDARY_MONUMENT", "ECC_BOUNDARY_MONUMENT",
    "A <MARKER> placed at a <LOCATION> that is associated with a surveyed"
    " <BOUNDARY>; a boundary monument.",
    3, &(EGBindingForEC[545]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZB030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BREACH,
    "BREACH", "ECC_BREACH",
    "An <APERTURE> in an obstacle (for example: a <FORTIFICATION>, a"
    " <WALL>, and/or a <TERRAIN_OBSTACLE>), particularly one caused by"
    " violence or natural decay; a breach.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BREACH_HOLE,
    "BREACH_HOLE", "ECC_BREACH_HOLE",
    "A rough <APERTURE> for entrance and/or egress of <HUMAN>s, typically"
    " about 60 centimetres in diameter; a breach hole.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BREAK_LINE,
    "BREAK_LINE", "ECC_BREAK_LINE",
    "A <LINE> representing the demarcation of a sudden and significant"
    " change in the gradient of the <TERRAIN>; a break-line.",
    3, &(EGBindingForEC[542]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: CA026]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BREAKER_REGION,
    "BREAKER_REGION", "ECC_BREAKER_REGION",
    "A <WATERBODY_REGION> where <WATER_WAVE>s break over off-lying <SHOAL>s"
    " and/or <REEF>s near the <SHORE>; a breaker region.",
    2, &(EGBindingForEC[874]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute, CATWAT:1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BREAKWATER,
    "BREAKWATER", "ECC_BREAKWATER",
    "A <STRUCTURE> that protects a <WATERBODY_REGION> (for example: a"
    " <SHORE>, a <HARBOUR>, an <ANCHORAGE>, and/or a"
    " <WATERBODY_SHELTER_BASIN>) from <WATER_WAVE>s by preventing them from"
    " reaching the protected <REGION> or reducing their magnitude; a"
    " breakwater.",
    4, &(EGBindingForEC[745]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"breakwater\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BRIDGE,
    "BRIDGE", "ECC_BRIDGE",
    "A <STRUCTURE> that connects two <LOCATION>s and provides for the"
    " passage of a <LAND_TRANSPORTATION_ROUTE> over a <TERRAIN_OBSTACLE>"
    " (for example: a <WATERBODY>, a <GULLY>, and/or a <ROAD>); a bridge. A"
    " bridge consists of a <SET> of two or more <BRIDGE_PIER>s or"
    " <BRIDGE_TOWER>s joined by <BRIDGE_SPAN>s.",
    3, &(EGBindingForEC[1047]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: BRIDGE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BRIDGE_PIER,
    "BRIDGE_PIER", "ECC_BRIDGE_PIER",
    "A pillar or abutment that supports a <BRIDGE_SPAN>; a bridge pier.",
    3, &(EGBindingForEC[1047]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ056]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BRIDGE_PLATFORM,
    "BRIDGE_PLATFORM", "ECC_BRIDGE_PLATFORM",
    "A <SITE> that has been sculpted (for example: levelled) to support"
    " and/or secure a <BRIDGE_PIER>; a bridge platform.",
    3, &(EGBindingForEC[1052]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BRIDGE_SPAN,
    "BRIDGE_SPAN", "ECC_BRIDGE_SPAN",
    "A <COMPONENT> of the deck of a <BRIDGE> spanning successive"
    " <BRIDGE_PIER>s; a bridge span.",
    3, &(EGBindingForEC[1047]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ045]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BRIDGE_SUPERSTRUCTURE,
    "BRIDGE_SUPERSTRUCTURE", "ECC_BRIDGE_SUPERSTRUCTURE",
    "A <SUPERSTRUCTURE> of a <BRIDGE>, above the lowest deck; a bridge"
    " superstructure.",
    3, &(EGBindingForEC[1047]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BRIDGE_TOWER,
    "BRIDGE_TOWER", "ECC_BRIDGE_TOWER",
    "A <TOWER> and/or <PYLON> from which the deck of a <BRIDGE> is"
    " suspended; a bridge tower.",
    2, &(EGBindingForEC[1045]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ055]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BRUSH_LAND,
    "BRUSH_LAND", "ECC_BRUSH_LAND",
    "A <TRACT> covered by low-growing woody <PLANT>s; brush land. EXAMPLES"
    " Scrub, brush, bush.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EB020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUCKET_ELEVATOR,
    "BUCKET_ELEVATOR", "ECC_BUCKET_ELEVATOR",
    "<EQUIPMENT>, usually a series of buckets, for raising <MATERIAL>s to a"
    " higher level; a bucket elevator.",
    3, &(EGBindingForEC[594]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AF021]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUDDHIST_TEMPLE,
    "BUDDHIST_TEMPLE", "ECC_BUDDHIST_TEMPLE",
    "A <WORSHIP_PLACE> for Buddhist worship; a Buddhist temple.",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUILDING,
    "BUILDING", "ECC_BUILDING",
    "A fixed, relatively permanent <STRUCTURE> with a <ROOF> and usually"
    " with <WALL>(s) that is designed for use and occupancy by <HUMAN>s; a"
    " building.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: BUISGL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUILDING_COMPONENT,
    "BUILDING_COMPONENT", "ECC_BUILDING_COMPONENT",
    "A <COMPONENT> of a <BUILDING>. EXAMPLES <ROOF>, <WALL>, <DOOR>,"
    " <WINDOW>, <FLOOR>.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUILDING_COMPONENT_ENTRANCE_OR_EXIT,
    "BUILDING_COMPONENT_ENTRANCE_OR_EXIT", "ECC_BUILDING_COMPONENT_ENTRANCE_OR_EXIT",
    "A <STRUCTURE_ENTRANCE_AND_OR_EXIT> between <BUILDING_COMPONENT>s."
    " EXAMPLE The doorway to a landing of a <STAIR>.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUILDING_SUPERSTRUCTURE,
    "BUILDING_SUPERSTRUCTURE", "ECC_BUILDING_SUPERSTRUCTURE",
    "A <SUPERSTRUCTURE> of a <BUILDING> that rises from the <ROOF> but is"
    " not considered to be a <COMPONENT> of the <ROOF>; a building"
    " superstructure.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL018]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUILT_UP_REGION,
    "BUILT_UP_REGION", "ECC_BUILT_UP_REGION",
    "A <TRACT> containing a concentration of <BUILDING>s and other"
    " <STRUCTURE>s; a built-up region.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: BUAARE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUILT_UP_TERRAIN,
    "BUILT_UP_TERRAIN", "ECC_BUILT_UP_TERRAIN",
    "A <TERRAIN_SURFACE_REGION> that has been built-up from its natural"
    " configuration.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUNKER,
    "BUNKER", "ECC_BUNKER",
    "A reinforced underground <SHELTER>, typically resistant to"
    " <MUNITION>s; a bunker [SOED, \"bunker\", 5].",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUOY,
    "BUOY", "ECC_BUOY",
    "A floating <OBJECT>, other than a <LIGHTSHIP>, moored or anchored to a"
    " <WATERBODY_FLOOR> at a particular <LOCATION> and serving a specific"
    " purpose (for example: an <AID_TO_NAVIGATION>); a buoy.",
    4, &(EGBindingForEC[67]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"buoy\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BURIED_ELECTRICAL_CABLE,
    "BURIED_ELECTRICAL_CABLE", "ECC_BURIED_ELECTRICAL_CABLE",
    "An <ELECTRICAL_CABLE> located underground and/or underwater; a buried"
    " electrical cable.",
    2, &(EGBindingForEC[621]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BURIED_POWER_TRANSMISSION_LINE,
    "BURIED_POWER_TRANSMISSION_LINE", "ECC_BURIED_POWER_TRANSMISSION_LINE",
    "A <SYSTEM> of <BURIED_ELECTRICAL_CABLE>s, supports, and conduits that"
    " transmits electricity over distance; a buried power transmission line.",
    2, &(EGBindingForEC[621]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUS_DEPOT,
    "BUS_DEPOT", "ECC_BUS_DEPOT",
    "A <STRUCTURE> where buses or coaches are housed and maintained and"
    " from which they are dispatched for service; a bus depot.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"depot\", 3 b]", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUS_STATION,
    "BUS_STATION", "ECC_BUS_STATION",
    "A <STRUCTURE>, usually in a <TOWN> or <CITY>, that serves as a"
    " <BUS_STOP>, especially for long-distance buses or coaches; a bus"
    " station [SOED, \"bus station\"].",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUS_STOP,
    "BUS_STOP", "ECC_BUS_STOP",
    "A <LOCATION> where buses and coaches regularly stop to take on and/or"
    " let off passengers; a bus-stop [SOED, \"bus-stop\"].",
    3, &(EGBindingForEC[1012]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUSINESS_WINGED_AIRCRAFT,
    "BUSINESS_WINGED_AIRCRAFT", "ECC_BUSINESS_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed or designated for private business use.",
    4, &(EGBindingForEC[233]),
    EDCS_REF_TYP_INFORMATIVE, "[JAWA, Type Classifications, Class 6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_BUTTE,
    "BUTTE", "ECC_BUTTE",
    "A detached, flat-topped <HILL> or tableland that is smaller than a"
    " <MESA> and rises steeply from a surrounding <TERRAIN_PLAIN>; a butte.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"butte\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CABIN,
    "CABIN", "ECC_CABIN",
    "A <BUILDING> at a remote and/or wilderness <LOCATION>; a cabin.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AL101]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CADASTRAL_CONSTRUCTION,
    "CADASTRAL_CONSTRUCTION", "ECC_CADASTRAL_CONSTRUCTION",
    "A <STRUCTURE> with unique characteristics used to support cadastral"
    " surveys.",
    3, &(EGBindingForEC[136]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: IA050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CADASTRAL_CONTROL_POINT,
    "CADASTRAL_CONTROL_POINT", "ECC_CADASTRAL_CONTROL_POINT",
    "A <LOCATION> used for locating and orienting a cadastral survey; a"
    " cadastral control point.",
    3, &(EGBindingForEC[122]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: CTRPNT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAIRN,
    "CAIRN", "ECC_CAIRN",
    "A heap of <ROCK>s piled up as a <MEMORIAL_MONUMENT> or a landmark; a"
    " cairn.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: CAIRNS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAISSON,
    "CAISSON", "ECC_CAISSON",
    "A <GATE> at the end of a <DRY_DOCK> that excludes the <WATER> after"
    " pumping out the <DRY_DOCK>, often containing the pumping engines; a"
    " caisson.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI042]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CALLING_IN_POINT,
    "CALLING_IN_POINT", "ECC_CALLING_IN_POINT",
    "A <LOCATION> some distance from a <HARBOUR> at which the navigator of"
    " a <VESSEL> notifies the authority for that <HARBOUR> of the position"
    " of the <VESSEL>; a calling in point.",
    6, &(EGBindingForEC[105]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CALVARY_CROSS,
    "CALVARY_CROSS", "ECC_CALVARY_CROSS",
    "A <STRUCTURE> that is mounted on a pedestal and composed of an upright"
    " member with a shorter horizontal member centred at approximately two"
    " thirds of the <<HEIGHT>> of the upright member; a Calvary cross.",
    2, &(EGBindingForEC[1160]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL116]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAMBER,
    "CAMBER", "ECC_CAMBER",
    "A small <WATERBODY_SHELTER_BASIN>, usually with a narrow"
    " <STRUCTURE_ENTRANCE>, situated inside a <HARBOUR>; a camber.",
    6, &(EGBindingForEC[681]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"camber\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAMP,
    "CAMP", "ECC_CAMP",
    "A <TRACT> where <TENT>s and/or <BUILDING>s serve as temporary"
    " residences; a camp.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AI030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAMPGROUND,
    "CAMPGROUND", "ECC_CAMPGROUND",
    "A <TRACT> designed for camping; a campground.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CANAL,
    "CANAL", "ECC_CANAL",
    "A man-made or improved natural <WATERCOURSE> used for transportation,"
    " irrigation, and/or movement of <WATER>; a canal.",
    5, &(EGBindingForEC[173]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CANAL_NEXUS,
    "CANAL_NEXUS", "ECC_CANAL_NEXUS",
    "A representation of one or more <CANAL>s, especially in a"
    " <BUILT_UP_REGION>; a canal centre-line or canal nexus.",
    6, &(EGBindingForEC[167]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CANAL_ROUTE,
    "CANAL_ROUTE", "ECC_CANAL_ROUTE",
    "A navigable <MARINE_ROUTE> consisting primarily of <CANAL>s but"
    " sometimes including <WATERBODY>s (for example: <LAKE>s and/or"
    " <RESERVOIR>s).",
    5, &(EGBindingForEC[778]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FC168]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CANYON,
    "CANYON", "ECC_CANYON",
    "A deep <GORGE>, frequently with a <RIVER> at its bottom; a canyon"
    " [SOED, \"canyon\", A].",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAPITOL_BUILDING,
    "CAPITOL_BUILDING", "ECC_CAPITOL_BUILDING",
    "A <BUILDING> in which a national or sub-national legislature meets; a"
    " capitol building.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CARGO,
    "CARGO", "ECC_CARGO",
    "The goods carried by a <VEHICLE>; a cargo [SOED, \"cargo\", 1.a] or"
    " load.",
    2, &(EGBindingForEC[965]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CARGO_CONTAINER,
    "CARGO_CONTAINER", "ECC_CARGO_CONTAINER",
    "A large reusable <CONTAINER> that is designed for the efficient"
    " handling of <CARGO> by accommodating smaller cartons and/or cases in"
    " a single shipment.",
    3, &(EGBindingForEC[594]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CARGO_CONTAINER_FACILITY,
    "CARGO_CONTAINER_FACILITY", "ECC_CARGO_CONTAINER_FACILITY",
    "A <FACILITY> used to store <CARGO_CONTAINER>s.",
    3, &(EGBindingForEC[967]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CARNIVORE,
    "CARNIVORE", "ECC_CARNIVORE",
    "A <MAMMAL> of the order Carnivora; a carnivore. EXAMPLES Dog, cat,"
    " bear, seal.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"carnivore\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_CARPENTRY_BUILDING,
    "CARPENTRY_BUILDING", "ECC_CARPENTRY_BUILDING",
    "A <BUILDING> in which wooden <OBJECT>s are manufactured or repaired; a"
    " carpentry building or a carpentry shop.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:73]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CART_TRACK,
    "CART_TRACK", "ECC_CART_TRACK",
    "An unimproved <ROAD>; a cart track.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AP010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CASTLE,
    "CASTLE", "ECC_CASTLE",
    "A large fortified <NON_EMPTY_SET> of <BUILDING>s with thick <WALL>s,"
    " usually dominating the surrounding <TERRAIN_SURFACE_REGION>; a castle"
    " [SOED, \"castle\", I.1].",
    2, &(EGBindingForEC[1119]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CATALYTIC_CRACKER,
    "CATALYTIC_CRACKER", "ECC_CATALYTIC_CRACKER",
    "A <DEVICE> in which the separation of <PETROLEUM> is carried out in"
    " the presence of a catalyst; a catalytic cracker.",
    2, &(EGBindingForEC[586]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AC020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CATHEDRAL,
    "CATHEDRAL", "ECC_CATHEDRAL",
    "A large, imposing <BUILDING> functioning as a <WORSHIP_PLACE>; a"
    " cathedral [SOED, \"cathedral\", 2].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CATHOLIC_CATHEDRAL,
    "CATHOLIC_CATHEDRAL", "ECC_CATHOLIC_CATHEDRAL",
    "The principal <CHURCH> of a diocese, containing the bishop's throne; a"
    " Catholic cathedral [SOED, \"cathedral\", B.1].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CATWALK,
    "CATWALK", "ECC_CATWALK",
    "A suspended narrow footway or platform; a catwalk.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"catwalk\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAUSEWAY,
    "CAUSEWAY", "ECC_CAUSEWAY",
    "A raised <ROAD> supported by a solid <STRUCTURE> and/or raised <LAND>"
    " providing a <LAND_TRANSPORTATION_ROUTE> across either a wet"
    " <TERRAIN_SURFACE_REGION> or an intertidal <TERRAIN_SURFACE_REGION>; a"
    " causeway.",
    3, &(EGBindingForEC[736]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: CAUSWY]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAVE,
    "CAVE", "ECC_CAVE",
    "A natural subterranean chamber or series of chambers open to the"
    " <PLANETARY_SURFACE>; a cave.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAVITATION,
    "CAVITATION", "ECC_CAVITATION",
    "The turbulent formation, generally mechanically induced and including"
    " growth and collapse, of bubbles in a fluid, occurring when the static"
    " pressure at any <LOCATION> in fluid flow is less than the fluid"
    " vapour pressure; cavitation.",
    1, &(EGBindingForEC[17]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"cavitation\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAVITATION_NOISE,
    "CAVITATION_NOISE", "ECC_CAVITATION_NOISE",
    "The noise produced in a liquid by the collapse of bubbles that have"
    " been created by <CAVITATION>.",
    2, &(EGBindingForEC[88]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"cavitation noise\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CAY,
    "CAY", "ECC_CAY",
    "A small insular <TRACT>, usually of <SAND> or <CORAL>, with scant"
    " <VEGETATION>; a cay or small coral shoal.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"cay\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CEASE_FIRE_LINE,
    "CEASE_FIRE_LINE", "ECC_CEASE_FIRE_LINE",
    "A <LINE> along which active hostilities are suspended; a cease fire"
    " line.",
    2, &(EGBindingForEC[548]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CEILING_CRAWL_SPACE,
    "CEILING_CRAWL_SPACE", "ECC_CEILING_CRAWL_SPACE",
    "A space within a <BUILDING>, located above a <ROOM_CEILING>, and"
    " providing access to ducts and usually of restricted <<HEIGHT>> but"
    " having sufficient <<HEIGHT>> for <HUMAN>s to crawl; a ceiling crawl"
    " space.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CELESTIAL_BODY,
    "CELESTIAL_BODY", "ECC_CELESTIAL_BODY",
    "Any <OBJECT> pertaining to the heavens and constituting a unit for"
    " astronomical study; a celestial body. EXAMPLES <STAR>, <MOON>,"
    " <PLANET>, <COMET>.",
    2, &(EGBindingForEC[77]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"celestial body\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CEMETERY,
    "CEMETERY", "ECC_CEMETERY",
    "A <SITE> and associated <STRUCTURE>s devoted to the burial of the"
    " dead; a cemetery.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: CEMTRY]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CEMETERY_BUILDING,
    "CEMETERY_BUILDING", "ECC_CEMETERY_BUILDING",
    "A <BUILDING> associated with a <CEMETERY>.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:18]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CENTRE_LINE,
    "CENTRE_LINE", "ECC_CENTRE_LINE",
    "A real or imaginary <LINE> indicating and/or marking the"
    " cross-sectional centre of an <OBJECT> along its primary extent; a"
    " centre-line.",
    2, &(EGBindingForEC[73]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CEPHALOPOD,
    "CEPHALOPOD", "ECC_CEPHALOPOD",
    "A <MOLLUSC> of the class Cephalopoda, members of which have a"
    " well-developed head surrounded by tentacles; a cephalopod [SOED,"
    " \"cephlopod\"]. EXAMPLES Cuttlefish, octopus, nautilus, ammonite"
    " (extinct form).",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHAIN,
    "CHAIN", "ECC_CHAIN",
    "A flexible length formed of metal links, rods, or plates, used as a"
    " tensioner and to drag, lift, support, and/or restrain <OBJECT>s; a"
    " chain.",
    2, &(EGBindingForEC[1178]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD074]",
    "[SOED, \"chain\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHANCERY,
    "CHANCERY", "ECC_CHANCERY",
    "A <BUILDING> containing an office for public records; a chancery"
    " [SOED, \"chancery\", 3].",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHANGE_LINE,
    "CHANGE_LINE", "ECC_CHANGE_LINE",
    "A <LINE> within a <REGION> indicating where the properties of the"
    " <REGION> change significantly; a change line.",
    2, &(EGBindingForEC[540]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHANGE_POINT,
    "CHANGE_POINT", "ECC_CHANGE_POINT",
    "A <LOCATION> on a linear <OBJECT> where the properties of the <OBJECT>"
    " change significantly; a change point.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZD015]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHAPEL,
    "CHAPEL", "ECC_CHAPEL",
    "A Christian <WORSHIP_PLACE>, usually smaller than a <CHURCH>, and"
    " especially one that is attached to a larger <BUILDING> (for example:"
    " a private <HOUSE> and/or an institution); a chapel [SOED, \"chapel\","
    " 1].",
    2, &(EGBindingForEC[416]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHECKPOINT,
    "CHECKPOINT", "ECC_CHECKPOINT",
    "An official <SITE> to register, declare, and/or check goods and"
    " <HUMAN>s; a checkpoint.",
    1, &(EGBindingForEC[2]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: CHKPNT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHEMICAL_HAZARD_REGION,
    "CHEMICAL_HAZARD_REGION", "ECC_CHEMICAL_HAZARD_REGION",
    "A <REGION> in which a chemical substance is present that can kill,"
    " seriously injure, and/or incapacitate a <HUMAN> or <NON_HUMAN_ANIMAL>"
    " through its physiological properties. The chemical substance is"
    " usually dispersed over a <SURFACE> and/or within the <ATMOSPHERE>.",
    3, &(EGBindingForEC[393]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHIMNEY,
    "CHIMNEY", "ECC_CHIMNEY",
    "A <COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE> attached to and rising"
    " above the <ROOF> of a <BUILDING>; a chimney.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: CHIMNY]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHRISTIAN_TEMPLE,
    "CHRISTIAN_TEMPLE", "ECC_CHRISTIAN_TEMPLE",
    "A <BUILDING> functioning as a <WORSHIP_PLACE> for public Christian"
    " worship; a Christian temple [SOED, \"temple\", A.I.3].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CHURCH,
    "CHURCH", "ECC_CHURCH",
    "A <BUILDING> functioning as a <WORSHIP_PLACE> for public, especially"
    " Christian, worship; a church [SOED, \"church\", 1].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CIRCULAR_IRRIGATION_SYSTEM,
    "CIRCULAR_IRRIGATION_SYSTEM", "ECC_CIRCULAR_IRRIGATION_SYSTEM",
    "An elevated irrigation <SYSTEM> revolving around a central pivot"
    " <LOCATION>; a circular irrigation system.",
    1, &(EGBindingForEC[3]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AJ010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CISTERN,
    "CISTERN", "ECC_CISTERN",
    "A man-made <CONTAINER> used for the collection and/or storage of"
    " <RAIN>; a cistern.",
    2, &(EGBindingForEC[597]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CITY,
    "CITY", "ECC_CITY",
    "A concentration of <DWELLING>s, <COMMERCIAL_BUILDING>s,"
    " <INDUSTRIAL_BUILDING>s, and other <STRUCTURE>s where <HUMAN>s have"
    " settled that is larger than a <TOWN> and usually smaller than a"
    " <BUILT_UP_REGION>; a city.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CITY_HALL,
    "CITY_HALL", "ECC_CITY_HALL",
    "The <MUNICIPAL_HALL> of a <CITY>.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"city hall\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_CIVILIAN_MOTOR_VEHICLE,
    "CIVILIAN_MOTOR_VEHICLE", "ECC_CIVILIAN_MOTOR_VEHICLE",
    "A <MOTOR_VEHICLE> used for civilian activities.",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CIVILIAN_PERSONNEL,
    "CIVILIAN_PERSONNEL", "ECC_CIVILIAN_PERSONNEL",
    "<PERSONNEL> that are not members of an armed force; civilian personnel.",
    3, &(EGBindingForEC[333]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLAIM_LINE,
    "CLAIM_LINE", "ECC_CLAIM_LINE",
    "A <BOUNDARY> of a <REGION> that is unilaterally claimed by one"
    " political group without the consent of or negotiation with another; a"
    " claim line.",
    3, &(EGBindingForEC[111]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLIFF,
    "CLIFF", "ECC_CLIFF",
    "A vertical or nearly vertical face of <ROCK> in the <TERRAIN> of"
    " considerable <<HEIGHT>>; a cliff.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"cliff\", 1.a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLIFF_BOTTOMLINE,
    "CLIFF_BOTTOMLINE", "ECC_CLIFF_BOTTOMLINE",
    "A <LINE> representing the demarcation of a sudden and significant"
    " change in the gradient of the terrain relief occurring at the bottom"
    " of a <CLIFF>.",
    3, &(EGBindingForEC[542]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB500]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLIFF_DWELLING,
    "CLIFF_DWELLING", "ECC_CLIFF_DWELLING",
    "A <DWELLING> built into the recesses of a <CLIFF>.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLIFF_TOPLINE,
    "CLIFF_TOPLINE", "ECC_CLIFF_TOPLINE",
    "A <LINE> representing the demarcation of a sudden and significant"
    " change in the gradient of the terrain relief occurring at the top of"
    " a <CLIFF>.",
    3, &(EGBindingForEC[542]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB501]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLOSET,
    "CLOSET", "ECC_CLOSET",
    "A small <ROOM> belonging with and opening to a larger <ROOM>; a closet.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"closet\", A.1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLOUD,
    "CLOUD", "ECC_CLOUD",
    "A visible aggregate of minute droplets of <WATER>, <PARTICLE>s of"
    " <ICE>, or both, suspended in the <ATMOSPHERE> above the"
    " <PLANETARY_SURFACE> of the <EARTH>; a cloud.",
    3, &(EGBindingForEC[281]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cloud\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLOUD_BASE,
    "CLOUD_BASE", "ECC_CLOUD_BASE",
    "The lowest level in a specific <CLOUD> or <CLOUD_LAYER> where the"
    " <ATMOSPHERE> contains a perceptible quantity of <PARTICLE>s of the"
    " <CLOUD>; the cloud base.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"cloud base\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLOUD_LAYER,
    "CLOUD_LAYER", "ECC_CLOUD_LAYER",
    "An arrangement of <CLOUD>s, continuous or composed of separated"
    " <COMPONENT>s, where the <<CLOUD_BASE_LEVEL>>s are the same and the"
    " <<CLOUD_THICKNESS>>s are approximately the same; a cloud layer.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cloud layer\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CLOUD_TOP,
    "CLOUD_TOP", "ECC_CLOUD_TOP",
    "The highest level in a specific <CLOUD> or <CLOUD_LAYER> where the"
    " <ATMOSPHERE> contains a perceptible quantity of <PARTICLE>s of the"
    " <CLOUD>; the cloud top.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cloud top\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COAST,
    "COAST", "ECC_COAST",
    "A <TERRAIN_STRIP> of indefinite <<WIDTH>> that extends from the"
    " <COASTLINE> inland to the first major change in the <TERRAIN>; a"
    " coast [SOED, \"coast\", 2].",
    3, &(EGBindingForEC[533]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BA011]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COASTLINE,
    "COASTLINE", "ECC_COASTLINE",
    "The <LAND_WATER_BOUNDARY> where the <COAST> and the <SHORE> are in"
    " contact; a coastline.",
    2, &(EGBindingForEC[524]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: COALNE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COLD_FRONT,
    "COLD_FRONT", "ECC_COLD_FRONT",
    "An <ATMOSPHERIC_FRONT> between warm and cold <AIR_MASS>s that is not"
    " an <OCCLUDED_FRONT> and that moves so that the colder <AIR> replaces"
    " the warmer <AIR>; a cold front.",
    4, &(EGBindingForEC[358]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cold front\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COLLEGIATE_CAMPUS,
    "COLLEGIATE_CAMPUS", "ECC_COLLEGIATE_CAMPUS",
    "The <BUILDING>s and <GROUNDS> of an institution offering special"
    " instruction in professional and/or technical subjects, which may also"
    " include <FACILITY>s for research and the award of advanced degrees; a"
    " university campus or college campus.",
    3, &(EGBindingForEC[986]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMBAT_STORES_VESSEL,
    "COMBAT_STORES_VESSEL", "ECC_COMBAT_STORES_VESSEL",
    "A <WATER_SURFACE_VESSEL> designed or designated to support underway"
    " replenishment of <COMBAT_SUPPORT_VESSEL>s and <COMBATANT_VESSEL>s; a"
    " combat stores vessel.",
    4, &(EGBindingForEC[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMBAT_SUPPORT_VEHICLE,
    "COMBAT_SUPPORT_VEHICLE", "ECC_COMBAT_SUPPORT_VEHICLE",
    "A <GROUND_VEHICLE> designed or designated to provide support and"
    " operational assistance to <COMBATANT_VEHICLE>s; a combat support"
    " vehicle.",
    3, &(EGBindingForEC[1126]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMBAT_SUPPORT_VESSEL,
    "COMBAT_SUPPORT_VESSEL", "ECC_COMBAT_SUPPORT_VESSEL",
    "A <WATER_SURFACE_VESSEL> designed or designated to provide support and"
    " operational assistance to <COMBATANT_VESSEL>s; a combat support"
    " vessel.",
    4, &(EGBindingForEC[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMBATANT_VEHICLE,
    "COMBATANT_VEHICLE", "ECC_COMBATANT_VEHICLE",
    "A <GROUND_VEHICLE> designed or designated to participate in military"
    " combat operations as a combatant.",
    3, &(EGBindingForEC[1126]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMBATANT_VESSEL,
    "COMBATANT_VESSEL", "ECC_COMBATANT_VESSEL",
    "A <WATER_SURFACE_VESSEL> designed or designated to participate in"
    " military combat operations as a combatant.",
    4, &(EGBindingForEC[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE,
    "COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE", "ECC_COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE",
    "A vertical <STRUCTURE> containing a passage and/or flue for"
    " discharging <SMOKE> and gases of combustion; a combustion product"
    " discharge structure.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AF010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMET,
    "COMET", "ECC_COMET",
    "A <CELESTIAL_BODY> that orbits a <STAR> in a highly elliptical path"
    " and, when in the vicinity of that <STAR>, usually has a bright hazy"
    " head and a long more diffuse tail; a comet [SOED, \"comet\", A.1].",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMMERCIAL_BUILDING,
    "COMMERCIAL_BUILDING", "ECC_COMMERCIAL_BUILDING",
    "A <BUILDING> used to conduct business activities; a commercial"
    " building.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:133]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMMERCIAL_HELICOPTER,
    "COMMERCIAL_HELICOPTER", "ECC_COMMERCIAL_HELICOPTER",
    "A <HELICOPTER> designed or designated for use in commerce.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMMERCIAL_WINGED_AIRCRAFT,
    "COMMERCIAL_WINGED_AIRCRAFT", "ECC_COMMERCIAL_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed or designated for use in commerce.",
    4, &(EGBindingForEC[233]),
    EDCS_REF_TYP_INFORMATIVE, "[JAWA, Type Classifications, Class 5]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMMUNICATION_FACILITY,
    "COMMUNICATION_FACILITY", "ECC_COMMUNICATION_FACILITY",
    "A <FACILITY> including one or more <COMMUNICATION_STATION>s.",
    4, &(EGBindingForEC[492]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AT050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMMUNICATION_STATION,
    "COMMUNICATION_STATION", "ECC_COMMUNICATION_STATION",
    "A <BUILDING> in which communication signals are processed and/or"
    " controlled; a communication station. EXAMPLES Telephone switching"
    " station, microwave repeater station, <SATELLITE_GROUND_STATION>,"
    " cellular telephone <EQUIPMENT>, land-line telephone repeater station.",
    3, &(EGBindingForEC[489]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AT050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMMUNICATION_TOWER,
    "COMMUNICATION_TOWER", "ECC_COMMUNICATION_TOWER",
    "A <TOWER> used for supporting an <AERIAL> for transmitting and/or"
    " receiving electronic communication signals.",
    4, &(EGBindingForEC[466]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AT080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMMUNITY_RECREATION_BUILDING,
    "COMMUNITY_RECREATION_BUILDING", "ECC_COMMUNITY_RECREATION_BUILDING",
    "A <BUILDING> used for recreational exercise and minor sports"
    " competitions, which typically serves a small <TOWN>, community, or"
    " local <BUILT_UP_REGION>; a community recreation building or a"
    " community centre.",
    2, &(EGBindingForEC[1149]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"community centre\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMMUNITY_RECREATION_FACILITY,
    "COMMUNITY_RECREATION_FACILITY", "ECC_COMMUNITY_RECREATION_FACILITY",
    "A <FACILITY> including one or more <COMMUNITY_RECREATION_BUILDING>s.",
    3, &(EGBindingForEC[1151]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMPLEX_OUTLINE,
    "COMPLEX_OUTLINE", "ECC_COMPLEX_OUTLINE",
    "The <BOUNDARY> delimiting a <REGION> in which two or more like"
    " <OBJECT>s have the same function; a complex outline.",
    2, &(EGBindingForEC[540]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL045]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMPLEX_TERMINAL_ROUTE,
    "COMPLEX_TERMINAL_ROUTE", "ECC_COMPLEX_TERMINAL_ROUTE",
    "A <NON_EMPTY_SET> of <ATS_ROUTE>s, action points, and various approach"
    " minimum altitudes and distances from the end of a landing <RUNWAY> as"
    " functions of <AIRCRAFT> type and instrument approach procedures; a"
    " complex terminal route.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GA047]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COMPONENT,
    "COMPONENT", "ECC_COMPONENT",
    "An <OBJECT> that is a constituent part of another (aggregate) <OBJECT>"
    " but, by itself, does not fulfill the function of the aggregate; a"
    " component.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONSULATE,
    "CONSULATE", "ECC_CONSULATE",
    "A <BUILDING> housing the residence and/or official premises of an"
    " official appointed by a government to reside in a foreign country,"
    " represent its commercial interests, and assist its citizens there; a"
    " consulate.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:67]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONTACT_ZONE,
    "CONTACT_ZONE", "ECC_CONTACT_ZONE",
    "A <TERRAIN_STRIP> that is 3 metres wide and limited on one side by the"
    " <LAND_WATER_BOUNDARY> of a <WATERBODY> under average water level"
    " conditions; a contact zone.",
    2, &(EGBindingForEC[550]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA041]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONTAINER,
    "CONTAINER", "ECC_CONTAINER",
    "A <DEVICE> designed to contain <MATERIAL>s; a container [SOED,"
    " \"container\"].",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONTOUR,
    "CONTOUR", "ECC_CONTOUR",
    "An elevation or depression <ISOPLETH>; a contour.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: CA010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONTROL_PANEL,
    "CONTROL_PANEL", "ECC_CONTROL_PANEL",
    "A panel on which are mounted switches, dials, and/or other mechanisms"
    " for the remote control and/or operation of <EQUIPMENT> (for example:"
    " electrical <EQUIPMENT>).",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED,\"control panel\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONTROL_TOWER,
    "CONTROL_TOWER", "ECC_CONTROL_TOWER",
    "A <TOWER> that houses <PERSONNEL> and <EQUIPMENT> used to control the"
    " flow of traffic on a <TRANSPORTATION_ROUTE>; a control tower.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONTROL_VALUE,
    "CONTROL_VALUE", "ECC_CONTROL_VALUE",
    "A value of an EDCS Attribute or an algorithmic quantity to be used in"
    " evaluating an algorithmic expression; a control value.",
    1, &(EGBindingForEC[6]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONTROLLED_AIRSPACE,
    "CONTROLLED_AIRSPACE", "ECC_CONTROLLED_AIRSPACE",
    "A designated <AIRSPACE> within which some or all <AIRCRAFT> may be"
    " subjected to air traffic control; a controlled airspace.",
    1, &(EGBindingForEC[4]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONVENT,
    "CONVENT", "ECC_CONVENT",
    "A <RELIGIOUS_COMMUNITY> of women; a convent [SOED, \"convent\", 3].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CONVEYOR,
    "CONVEYOR", "ECC_CONVEYOR",
    "<EQUIPMENT> for moving <MATERIAL>s from place to place on a moving"
    " belt or series of rollers; a conveyor.",
    3, &(EGBindingForEC[594]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: CONVYR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COOLING_TOWER,
    "COOLING_TOWER", "ECC_COOLING_TOWER",
    "A <TOWER> used to cool liquids; a cooling tower.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AF030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CORAL,
    "CORAL", "ECC_CORAL",
    "A hard calcareous <MATERIAL> consisting of the continuous skeleton of"
    " marine coelenterate polyps; coral [SOED, \"coral\", 1].",
    1, &(EGBindingForEC[33]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CORRECTIONAL_BUILDING,
    "CORRECTIONAL_BUILDING", "ECC_CORRECTIONAL_BUILDING",
    "A <BUILDING> within which persons convicted or accused of crimes are"
    " confined; a penitentiary or correctional building.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CORRECTIONAL_FACILITY,
    "CORRECTIONAL_FACILITY", "ECC_CORRECTIONAL_FACILITY",
    "A <FACILITY> including one or more <CORRECTIONAL_BUILDING>s; a"
    " correctional facility.",
    3, &(EGBindingForEC[133]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:123]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_COUNTY_HALL,
    "COUNTY_HALL", "ECC_COUNTY_HALL",
    "A <BUILDING> that houses the main offices of a county government; a"
    " county hall or court-house (US).",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"county hall\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_COURTYARD,
    "COURTYARD", "ECC_COURTYARD",
    "An open <TRACT> surrounded by <WALL>s and/or <BUILDING>s that is"
    " located within the precincts of a large <BUILDING>, <CASTLE>, or"
    " <BUILT_UP_REGION>; a courtyard.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"courtyard\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_COVERED_WATERCOURSE,
    "COVERED_WATERCOURSE", "ECC_COVERED_WATERCOURSE",
    "A covered portion of a <WATERCOURSE>, preventing its observation.",
    3, &(EGBindingForEC[850]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: SA060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CRANE,
    "CRANE", "ECC_CRANE",
    "<EQUIPMENT> for lifting, shifting, and lowering <OBJECT>s or"
    " <MATERIAL>s by means of a swinging boom or with a lifting apparatus"
    " supported on an overhead track; a crane.",
    3, &(EGBindingForEC[591]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: CRANES]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CREVASSE,
    "CREVASSE", "ECC_CREVASSE",
    "A deep crack or fissure in a <GLACIER>, which results from"
    " differential movement of <ICE>, or a deep vertical opening in the"
    " <TERRAIN> that appears after an earthquake; a crevasse.",
    2, &(EGBindingForEC[886]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB060]",
    "[SOED, \"crevasse\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_CREVICE,
    "CREVICE", "ECC_CREVICE",
    "A narrow opening or fissure produced by a crack in the <TERRAIN>,"
    " especially in <ROCK>; a crevice [SOED, \"crevice\", 1].",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CRIB,
    "CRIB", "ECC_CRIB",
    "A permanent <STRUCTURE> set in a <WATERBODY>, framed with heavy wooden"
    " beams, and sunken with debris (for example: <STONE>s), usually"
    " designed to support or elevate <PIPELINE>s; especially a <STRUCTURE>"
    " enclosing a screening <DEVICE> at the offshore end of a potable"
    " <WATER_INTAKE>; a crib.",
    3, &(EGBindingForEC[733]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"crib\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CROP_LAND,
    "CROP_LAND", "ECC_CROP_LAND",
    "A <TRACT> that has been tilled for the planting of crops.",
    4, &(EGBindingForEC[190]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EA010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CROSS_COUNTRY_BARRIER,
    "CROSS_COUNTRY_BARRIER", "ECC_CROSS_COUNTRY_BARRIER",
    "A permanent or semi-permanent <BARRIER> placed across any <TERRAIN> to"
    " prevent <GROUND_VEHICLE> or pedestrian traffic.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CROSSING,
    "CROSSING", "ECC_CROSSING",
    "A <LOCATION> where <LAND_TRANSPORTATION_ROUTE>s intersect or cross at"
    " the same vertical level; a crossing. EXAMPLES Railway crossing, road"
    " intersection, <FORD>.",
    3, &(EGBindingForEC[1012]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ062]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CRUISER,
    "CRUISER", "ECC_CRUISER",
    "A fast, medium tonnage <WATER_SURFACE_VESSEL> operating over a long"
    " cruising radius; a cruiser [AHD, \"cruiser\", 1].",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CRUSTACEAN,
    "CRUSTACEAN", "ECC_CRUSTACEAN",
    "An <ARTHROPOD> of the large class Crustacea, mainly aquatic and"
    " hard-shelled; a crustacean [SOED, \"crustacean\", A]. EXAMPLES Crab,"
    " lobster, shrimp, woodlouse.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CULVERT,
    "CULVERT", "ECC_CULVERT",
    "A <SEWER> or drain crossing under a <ROAD>, <RAILWAY>, or <EMBANKMENT>"
    " without affecting the construction of the crossed <OBJECT>; a culvert.",
    3, &(EGBindingForEC[972]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ065]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CURRENT,
    "CURRENT", "ECC_CURRENT",
    "A body of a fluid that is flowing in a definite <DIRECTION>; a current"
    " [SOED, \"current\", A.2].",
    1, &(EGBindingForEC[17]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BG010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_CUSTOMS_HOUSE,
    "CUSTOMS_HOUSE", "ECC_CUSTOMS_HOUSE",
    "A <GOVERNMENT_BUILDING> serving as a <CHECKPOINT> where customs duties"
    " are collected and shipments or <VEHICLE>s are cleared for entering or"
    " leaving a country; a customs house.",
    3, &(EGBindingForEC[130]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"custom-house\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_CYCLONE,
    "CYCLONE", "ECC_CYCLONE",
    "An <ATMOSPHERE_REGION> in which the <<ATM_PRESSURE>>s are lower than"
    " those of the surrounding <ATMOSPHERE_REGION> at the same"
    " <<ALTITUDE_MSL>>; a depression or cyclone.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"depression/cyclone\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DAM,
    "DAM", "ECC_DAM",
    "A permanent <BARRIER> across a <WATERCOURSE> that is used to impound"
    " <WATER> and/or to control its flow; a dam.",
    2, &(EGBindingForEC[731]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: DAMCON]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DATA_QUALITY_BOUNDARY,
    "DATA_QUALITY_BOUNDARY", "ECC_DATA_QUALITY_BOUNDARY",
    "A <BOUNDARY> between two <DATA_QUALITY_REGION>s.",
    3, &(EGBindingForEC[545]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DATA_QUALITY_REGION,
    "DATA_QUALITY_REGION", "ECC_DATA_QUALITY_REGION",
    "A <REGION> with specific data quality characteristics.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DATUM,
    "DATUM", "ECC_DATUM",
    "An <OBJECT> used as a reference for defining spatial aspects of other"
    " <OBJECT>s; a datum.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DECONTAMINATION_PAD,
    "DECONTAMINATION_PAD", "ECC_DECONTAMINATION_PAD",
    "A <SITE> where a radiologically, biologically, and/or chemically"
    " contaminated <AIRCRAFT> is sent for decontamination; a"
    " decontamination pad.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB160]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEEP_SOUND_CHANNEL,
    "DEEP_SOUND_CHANNEL", "ECC_DEEP_SOUND_CHANNEL",
    "The deepest <SOUND_CHANNEL> in an <OCEAN>.",
    2, &(EGBindingForEC[101]),
    EDCS_REF_TYP_INFORMATIVE, "[PUWS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEEP_WATER_ROUTE,
    "DEEP_WATER_ROUTE", "ECC_DEEP_WATER_ROUTE",
    "A <MARINE_ROUTE> through a deep <WATERBODY> plus related"
    " <NAVIGATION_MARK_FIXED>s and/or <NAVIGATION_MARK_AFLOAT>s; a deep"
    " water route.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FC166]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEFACTO_BOUNDARY,
    "DEFACTO_BOUNDARY", "ECC_DEFACTO_BOUNDARY",
    "A <BOUNDARY> not officially recognized by various governments; a"
    " defacto boundary.",
    3, &(EGBindingForEC[111]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEFENSIVE_POSITION,
    "DEFENSIVE_POSITION", "ECC_DEFENSIVE_POSITION",
    "One or more <STRUCTURE>s constructed for the military defence of a"
    " <SITE> that are resistant to <MUNITION>s; a defensive position.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEFENSIVE_POSITION_DEFILADE,
    "DEFENSIVE_POSITION_DEFILADE", "ECC_DEFENSIVE_POSITION_DEFILADE",
    "A <TERRAIN_SURFACE_REGION> affording protection or shielding from"
    " hostile ground observation and flat projecting fire; the protection"
    " is provided by a <TERRAIN_OBSTACLE> (for example: a"
    " <DEFENSIVE_POSITION>, a <HILL>, and/or a <PARAPET>); a defensive"
    " position defilade.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEFINED_WATER,
    "DEFINED_WATER", "ECC_DEFINED_WATER",
    "A <REGION> plus related <NAVIGATION_MARK_FIXED>s and/or"
    " <NAVIGATION_MARK_AFLOAT>s of a <WATERBODY> delimited for the purposes"
    " of: defining <MARINE_ROUTE>s; communicating port signals or"
    " communicating firing practice signals; or serving as a <WAYPOINT>,"
    " <CALLING_IN_POINT>, or an <ANCHORAGE>; defined water.",
    5, &(EGBindingForEC[470]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FC167]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEMILITARIZED_ZONE,
    "DEMILITARIZED_ZONE", "ECC_DEMILITARIZED_ZONE",
    "A <REGION> where military activity is prohibited; a demilitarized zone.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEPOT,
    "DEPOT", "ECC_DEPOT",
    "A <RAILWAY_STATION> or <BUS_STATION>, usually with an attached"
    " <WAREHOUSE>; a depot.",
    3, &(EGBindingForEC[1038]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"depot\", 3b]", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEPTH_CONTOUR_LINE,
    "DEPTH_CONTOUR_LINE", "ECC_DEPTH_CONTOUR_LINE",
    "An <ISOPLETH> of constant depth at and below a <SURFACE_DATUM>; a"
    " depth contour.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: DEPCNT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEPTH_CURVE,
    "DEPTH_CURVE", "ECC_DEPTH_CURVE",
    "A navigational safety <LINE> indicating that no <SOUNDING> of a lesser"
    " depth exists seaward of the <LINE>, but greater depths may occur on"
    " the shallow side of the <LINE>; a depth curve.",
    4, &(EGBindingForEC[810]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BE010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEPTH_REGION,
    "DEPTH_REGION", "ECC_DEPTH_REGION",
    "A <WATERBODY_REGION> containing <SOUNDING>s within a defined range of"
    " values permanently at or below a reference <SURFACE_DATUM>; a depth"
    " region.",
    2, &(EGBindingForEC[867]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: DEPARE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DESCRIBED_POINT,
    "DESCRIBED_POINT", "ECC_DESCRIBED_POINT",
    "A <LOCATION> at which text pertaining to that <LOCATION> is annotated;"
    " a described point.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: ZD045]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DESERT_REGION,
    "DESERT_REGION", "ECC_DESERT_REGION",
    "A dry, often sandy, <TRACT> of little rainfall, extreme"
    " <<AIR_TEMPERATURE>>s, and sparse <VEGETATION>; a desert region [AHD,"
    " \"desert\", 1.a].",
    2, &(EGBindingForEC[1136]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DESTROYER,
    "DESTROYER", "ECC_DESTROYER",
    "A fast, highly maneuverable <WATER_SURFACE_VESSEL> armed with guns,"
    " torpedoes, and depth charges; a destroyer [AHD, \"destroyer\", 2].",
    4, &(EGBindingForEC[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DETENTION_FACILITY,
    "DETENTION_FACILITY", "ECC_DETENTION_FACILITY",
    "A <FACILITY> for the confinement of <HUMAN>s in lawful detention who"
    " are convicted or accused of crimes; a detention facility.",
    2, &(EGBindingForEC[139]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DEVICE,
    "DEVICE", "ECC_DEVICE",
    "An <OBJECT> designed for a particular function or adapted for a"
    " particular purpose, especially a (simple) mechanical contrivance; a"
    " device [SOED, \"device\", 3].",
    2, &(EGBindingForEC[60]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DIAGNOSTIC_POINT,
    "DIAGNOSTIC_POINT", "ECC_DIAGNOSTIC_POINT",
    "A <LOCATION> used to check the accuracy of a <SYSTEM>; a diagnostic"
    " point.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZB040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DIAMOND_DUST,
    "DIAMOND_DUST", "ECC_DIAMOND_DUST",
    "<SOLID_PRECIPITATION> that falls from a clear sky in very small"
    " crystals of <ICE>, often so tiny that they appear to be suspended in"
    " the <AIR>; diamond dust.",
    3, &(EGBindingForEC[378]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"diamond dust\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DIPLOMATIC_BUILDING,
    "DIPLOMATIC_BUILDING", "ECC_DIPLOMATIC_BUILDING",
    "A <BUILDING> that houses and/or supports the activities of an"
    " ambassador; a diplomatic building.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:96]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DIRECTION,
    "DIRECTION", "ECC_DIRECTION",
    "A direction in relation to a <LOCATION>. EXAMPLES Course, bearing.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"direction\", 1.a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_DIRIGIBLE,
    "DIRIGIBLE", "ECC_DIRIGIBLE",
    "A steerable and self-propelled <AIRSHIP> with a rigid, elongated"
    " frame; a dirigible.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DISCOLOURED_WATER,
    "DISCOLOURED_WATER", "ECC_DISCOLOURED_WATER",
    "A <WATERBODY_REGION> having a colour distinctly different from that of"
    " the surrounding <REGION>; discoloured water.",
    2, &(EGBindingForEC[423]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DISH_AERIAL,
    "DISH_AERIAL", "ECC_DISH_AERIAL",
    "A concave-shaped <AERIAL> that is used for transmitting and/or"
    " receiving electronic signals; a dish aerial.",
    4, &(EGBindingForEC[430]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: DSHAER]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DISPLAY_LIGHT,
    "DISPLAY_LIGHT", "ECC_DISPLAY_LIGHT",
    "A specially constructed <LIGHT> that illuminates <DISPLAY_SIGN>s or"
    " other <STRUCTURE>s; a display light.",
    1, &(EGBindingForEC[29]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DISPLAY_SIGN,
    "DISPLAY_SIGN", "ECC_DISPLAY_SIGN",
    "An upright panel or similar <STRUCTURE> used to convey visual"
    " information; a display sign.",
    1, &(EGBindingForEC[12]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DISPOSAL_SITE,
    "DISPOSAL_SITE", "ECC_DISPOSAL_SITE",
    "A <SITE> for the collection and/or deposition of refuse or discarded"
    " <MATERIAL>; a disposal site.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AB000]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DISTANCE_MARK,
    "DISTANCE_MARK", "ECC_DISTANCE_MARK",
    "A <MARKER> that indicates the value of distance measured from a"
    " starting <LOCATION> and consists of either a solid visible"
    " <STRUCTURE> or a distinct <LOCATION> without a special installation;"
    " a distance mark.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: DISMAR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DISTANCE_POST,
    "DISTANCE_POST", "ECC_DISTANCE_POST",
    "A <MARKER> that designates the distance from a given <LOCATION>; a"
    " distance post.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DISTURBED_SOIL,
    "DISTURBED_SOIL", "ECC_DISTURBED_SOIL",
    "<LAND> so disturbed as to have no identifiable type of <SOIL>;"
    " disturbed soil.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: SA020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DOCK,
    "DOCK", "ECC_DOCK",
    "The space between two <PIER>s; a dock or a slip.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"dock\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DOOR,
    "DOOR", "ECC_DOOR",
    "A hinged or sliding <BARRIER> to the ingress into or egress from a"
    " <COMPONENT> of a <STRUCTURE> or <VEHICLE>; a door [SOED, \"door\","
    " 1.a].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DORMITORY,
    "DORMITORY", "ECC_DORMITORY",
    "A <BUILDING> used to house <CIVILIAN_PERSONNEL> that is typically"
    " large, unadorned, and intended for relatively temporary occupancy; a"
    " dormitory.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"dormitory\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRAGLINE,
    "DRAGLINE", "ECC_DRAGLINE",
    "Excavating <EQUIPMENT> consisting of a steel scoop that swings on"
    " <CHAIN>s from a movable jib; the scoop is cast into the <MATERIAL> to"
    " be excavated and dragged back to the jib where it is lifted and"
    " dumped; a dragline.",
    2, &(EGBindingForEC[586]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRAGON_TEETH,
    "DRAGON_TEETH", "ECC_DRAGON_TEETH",
    "A <NON_EMPTY_SET> of regularly spaced concrete or metal"
    " <TERRAIN_OBSTACLE>s laid in single or multiple rows to prevent the"
    " movement of <GROUND_VEHICLE>s; dragon's teeth or dragon teeth.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DREDGE,
    "DREDGE", "ECC_DREDGE",
    "<EQUIPMENT> for collecting and bringing up <OBJECT>s or <MATERIAL>"
    " from a <WATERBODY_FLOOR> by dragging or scooping; a dredge [SOED,"
    " \"dredge\", 2].",
    5, &(EGBindingForEC[566]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AF050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRILLING_RIG,
    "DRILLING_RIG", "ECC_DRILLING_RIG",
    "A <STRUCTURE> that enables <EQUIPMENT> (for example: a drill and/or"
    " instrumentation) to create a hole or to be deployed in a hole in the"
    " <TERRAIN>; a drilling rig.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"drilling rig\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRILLING_RIG_SUPERSTRUCTURE,
    "DRILLING_RIG_SUPERSTRUCTURE", "ECC_DRILLING_RIG_SUPERSTRUCTURE",
    "The <SUPERSTRUCTURE> of a <DRILLING_RIG> that includes a <TOWER>,"
    " drill floor, and associated <EQUIPMENT>, including <LOAD_CABLE>s,"
    " pulleys, motors, and compressors.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_INFORMATIVE, "[POSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRINKING_TROUGH,
    "DRINKING_TROUGH", "ECC_DRINKING_TROUGH",
    "A man-made open <CONTAINER> holding <WATER> for drinking by"
    " <NON_HUMAN_ANIMAL>s; a drinking trough.",
    3, &(EGBindingForEC[299]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH175]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRIVE_IN_THEATRE,
    "DRIVE_IN_THEATRE", "ECC_DRIVE_IN_THEATRE",
    "A <RECREATIONAL_FACILITY> where motion pictures are shown on"
    " <DRIVE_IN_THEATRE_SCREEN>s while viewers remain in their"
    " <GROUND_VEHICLE>s; a drive in theatre.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRIVE_IN_THEATRE_SCREEN,
    "DRIVE_IN_THEATRE_SCREEN", "ECC_DRIVE_IN_THEATRE_SCREEN",
    "A large outdoor screen <STRUCTURE> for showing motion pictures; a"
    " drive in theatre screen.",
    1, &(EGBindingForEC[39]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRIVEWAY,
    "DRIVEWAY", "ECC_DRIVEWAY",
    "A private <ROAD> alongside, in front of, or leading to a <BUILDING>"
    " (for example: a <HOUSE> and/or a <PARKING_GARAGE>); a driveway [SOED,"
    " \"driveway\"].",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRIZZLE,
    "DRIZZLE", "ECC_DRIZZLE",
    "Fairly uniform <PRECIPITATION> in very fine droplets"
    " (<<OUTSIDE_DIAMETER>> less than 0,5 millimetres) that are located"
    " very close to one another and are falling from a <CLOUD>; drizzle or"
    " mist.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"drizzle\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DROP_GATE,
    "DROP_GATE", "ECC_DROP_GATE",
    "A massive assemblage of <MATERIAL> (for example: concrete blocks"
    " and/or concrete cylinders) that is positioned above a"
    " <LAND_TRANSPORTATION_ROUTE> and is ready to be activated when needed"
    " as a potential <BARRIER> to an advancing enemy ground force; a drop"
    " gate.",
    3, &(EGBindingForEC[1024]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ068]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DROVE,
    "DROVE", "ECC_DROVE",
    "A wide <TRAIL> created by the regular movement of herds of"
    " <NON_HUMAN_ANIMAL>s; a drove.",
    4, &(EGBindingForEC[327]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AP060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRY_DOCK,
    "DRY_DOCK", "ECC_DRY_DOCK",
    "An artificial <WATERBODY_SHELTER_BASIN> fitted with a <MARINE_GATE> or"
    " <CAISSON> into which <VESSEL>s can be floated and the <WATER> pumped"
    " out to expose the bottom of the <VESSEL>; a dry dock or graving dock.",
    5, &(EGBindingForEC[719]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"dock: dry\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRY_LAKE,
    "DRY_LAKE", "ECC_DRY_LAKE",
    "A nearly level <TRACT> at the bottom of an undrained"
    " <GEOGRAPHIC_BASIN> in a <DESERT_REGION>, sometimes temporarily"
    " covered with <WATER>; a dry lake.",
    2, &(EGBindingForEC[865]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DRY_LAND,
    "DRY_LAND", "ECC_DRY_LAND",
    "A <TRACT> neither permanently nor temporarily covered by <WATER>; dry"
    " land.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DA030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DUST,
    "DUST", "ECC_DUST",
    "Solid <MATERIAL>s (for example: <SOIL>) in a minute and fine state of"
    " subdivision, so that the <PARTICLE>s are small and light enough to be"
    " easily raised and carried by the <WIND>; dust [SOED, \"dust\", 1].",
    3, &(EGBindingForEC[284]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DUST_SUSPENSION,
    "DUST_SUSPENSION", "ECC_DUST_SUSPENSION",
    "A <NON_AQUEOUS_CLOUD>, <PLUME>, and/or <PUFF> composed of`<DUST>; a"
    " dust suspension.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DWELLING,
    "DWELLING", "ECC_DWELLING",
    "A <SHELTER> (for example: a <BUILDING>) used for living quarters; a"
    " dwelling.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"dwelling\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_DYKE,
    "DYKE", "ECC_DYKE",
    "An artificial <EMBANKMENT> to contain <WATER>; a dyke.",
    1, &(EGBindingForEC[19]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"dike (or dyke)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_DYKE_TOP,
    "DYKE_TOP", "ECC_DYKE_TOP",
    "The top of a <DYKE>.",
    1, &(EGBindingForEC[19]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: DYKCRW]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EARLY_WARNING_RADAR_SITE,
    "EARLY_WARNING_RADAR_SITE", "ECC_EARLY_WARNING_RADAR_SITE",
    "A <SITE> utilizing long-range radar to detect approaching <AIRCRAFT>"
    " and/or <MISSILE>s; an early warning radar site.",
    3, &(EGBindingForEC[657]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AT020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EARTH,
    "EARTH", "ECC_EARTH",
    "The primary <PLANET> of the <SUN> that is third in distance from the"
    " <SUN>, with an orbital mean <<RADIUS>> of approximately 149,6 million"
    " kilometres; Earth.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EDDY,
    "EDDY", "ECC_EDDY",
    "A circular movement of fluid running contrary to the main flow,"
    " usually formed where <CURRENT>s pass obstructions, between two"
    " adjacent <CURRENT>s flowing counter to each other, or along the edge"
    " of a <CURRENT> that is <<PERMANENT>>; an eddy.",
    1, &(EGBindingForEC[17]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute, CATWAT:2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EDDY_REGION,
    "EDDY_REGION", "ECC_EDDY_REGION",
    "A <REGION> where <EDDY>s occur.",
    1, &(EGBindingForEC[17]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELECTRICAL_CABLE,
    "ELECTRICAL_CABLE", "ECC_ELECTRICAL_CABLE",
    "A <NON_EMPTY_SET> of insulated <WIRE>s formed into one continuous"
    " strand for the purpose of transmitting electrical power or signals;"
    " an electrical cable.",
    3, &(EGBindingForEC[455]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AT005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELECTRICAL_FIELD,
    "ELECTRICAL_FIELD", "ECC_ELECTRICAL_FIELD",
    "A <REGION> where a field of force produced by a electrically charged"
    " <OBJECT> or by a changing <MAGNETIC_FIELD> is found; an electrical"
    " field [SOED, \"electric field\"].",
    1, &(EGBindingForEC[16]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELECTRICAL_SIGNAL_LINE,
    "ELECTRICAL_SIGNAL_LINE", "ECC_ELECTRICAL_SIGNAL_LINE",
    "A <SYSTEM> of <WIRE>s and their supports above the <TERRAIN> that"
    " transmit electrical signals over distance; an electrical signal line."
    " EXAMPLES Telegraph line, telephone line.",
    3, &(EGBindingForEC[455]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AT060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELECTRICAL_SIGNAL_LINE_PYLON,
    "ELECTRICAL_SIGNAL_LINE_PYLON", "ECC_ELECTRICAL_SIGNAL_LINE_PYLON",
    "A <PYLON> and/or <POLE> used to support an <ELECTRICAL_SIGNAL_LINE>.",
    4, &(EGBindingForEC[466]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AT070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELECTRIFIED_RAILWAY_PYLON,
    "ELECTRIFIED_RAILWAY_PYLON", "ECC_ELECTRIFIED_RAILWAY_PYLON",
    "A <PYLON> and/or <POLE> used to support a <POWER_TRANSMISSION_LINE>"
    " associated with an electrified <RAILWAY>.",
    4, &(EGBindingForEC[645]),
    EDCS_REF_TYP_INFORMATIVE, "[DFAD, 536, \"Electrified Railroad Gantries/Pylons\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELECTROMAGNETIC_MATERIAL_PROPERTY_SET,
    "ELECTROMAGNETIC_MATERIAL_PROPERTY_SET", "ECC_ELECTROMAGNETIC_MATERIAL_PROPERTY_SET",
    "A <PROPERTY_SET> describing the electromagnetic properties of the"
    " <MATERIAL>s composing an <OBJECT>.",
    2, &(EGBindingForEC[660]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELECTROMAGNETIC_PULSE,
    "ELECTROMAGNETIC_PULSE", "ECC_ELECTROMAGNETIC_PULSE",
    "A broadband, high-intensity, short duration burst of electromagnetic"
    " radiation; an electromagnetic pulse. The resulting"
    " <ELECTRICAL_FIELD>s and <MAGNETIC_FIELD>s may couple with electrical"
    " and/or electronic <SYSTEM>s to produce damaging current and voltage"
    " surges.",
    1, &(EGBindingForEC[16]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELECTROMAGNETIC_REFRACTIVE_EVAPORATIVE_DUCT,
    "ELECTROMAGNETIC_REFRACTIVE_EVAPORATIVE_DUCT", "ECC_ELECTROMAGNETIC_REFRACTIVE_EVAPORATIVE_DUCT",
    "A layer of the <ATMOSPHERE> that is over a <WATERBODY> and in which"
    " electromagnetic waves launched in certain <DIRECTION>s are guided by"
    " and/or trapped within the layer rather than propagating radially from"
    " their source, caused by a decrease in <<WATER_VAPOUR_PRESSURE>> with"
    " <<HEIGHT_AGL>> due to evaporation; a refractive evaporative duct.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_INFORMATIVE, "[GOSS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELEVATED_ELECTRICAL_CABLE,
    "ELEVATED_ELECTRICAL_CABLE", "ECC_ELEVATED_ELECTRICAL_CABLE",
    "An <ELECTRICAL_CABLE> located above a <PLANETARY_SURFACE>.",
    3, &(EGBindingForEC[455]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AT006]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ELEVATION_CONTOUR_LINE,
    "ELEVATION_CONTOUR_LINE", "ECC_ELEVATION_CONTOUR_LINE",
    "An <ISOPLETH> of constant <<ELEVATION>>; an elevation contour line.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: CA010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EM_PULSE_COMPTON_EFFECT,
    "EM_PULSE_COMPTON_EFFECT", "ECC_EM_PULSE_COMPTON_EFFECT",
    "The <ELECTROMAGNETIC_PULSE> caused by the Compton effect following a"
    " nuclear explosion.",
    1, &(EGBindingForEC[16]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EMBANKMENT,
    "EMBANKMENT", "ECC_EMBANKMENT",
    "A long, raised mound of <SOIL>, <ROCK>, and/or other <MATERIAL>s in"
    " the <TERRAIN>, which is often used to support a"
    " <LAND_TRANSPORTATION_ROUTE>; an embankment [SOED, \"embankment\", 1].",
    4, &(EGBindingForEC[1031]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EMBASSY,
    "EMBASSY", "ECC_EMBASSY",
    "A <BUILDING> housing the office of an ambassador and/or the"
    " ambassador's staff; an embassy [AHD, \"embassy\", 1].",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EMBASSY_COMPOUND,
    "EMBASSY_COMPOUND", "ECC_EMBASSY_COMPOUND",
    "An enclosed <SITE> containing an <EMBASSY>; an embassy compound.",
    3, &(EGBindingForEC[133]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:66]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ENGINE_TEST_CELL,
    "ENGINE_TEST_CELL", "ECC_ENGINE_TEST_CELL",
    "A <STRUCTURE> where engines are tested; an engine test cell.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AF060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ENGINEER_BRIDGE,
    "ENGINEER_BRIDGE", "ECC_ENGINEER_BRIDGE",
    "A temporary <BRIDGE> spanning and providing passage over a"
    " <TERRAIN_OBSTACLE> (for example: a <WATERBODY> and/or a <GULLY>); an"
    " engineer bridge.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ENGINEER_DITCH,
    "ENGINEER_DITCH", "ECC_ENGINEER_DITCH",
    "A <TRENCH> that is constructed to bury <PIPELINE>s,"
    " <ELECTRICAL_SIGNAL_LINE>s, or <POWER_TRANSMISSION_LINE>s; an engineer"
    " ditch.",
    3, &(EGBindingForEC[626]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ENGINEER_TRENCH,
    "ENGINEER_TRENCH", "ECC_ENGINEER_TRENCH",
    "An engineered <TRENCH> or combination <TRENCH> and <PARAPET>, usually"
    " placed to turn, slow, or stop the movement of <MOTOR_VEHICLE>s; an"
    " engineer trench.",
    4, &(EGBindingForEC[1020]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"trench\", 3.a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_EQUIPMENT,
    "EQUIPMENT", "ECC_EQUIPMENT",
    "<OBJECT>s used and/or required for a particular purpose; equipment"
    " [SOED, \"equipment\", 2] or apparatus.",
    2, &(EGBindingForEC[60]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EQUIPMENT_COMPONENT,
    "EQUIPMENT_COMPONENT", "ECC_EQUIPMENT_COMPONENT",
    "A <COMPONENT> of an item of <EQUIPMENT>.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ESCALATOR,
    "ESCALATOR", "ECC_ESCALATOR",
    "<EQUIPMENT> consisting of a moving <STAIR> made on the endless-chain"
    " principle, so that the steps ascend or descend continuously, for"
    " carrying <HUMAN>s up or down; an escalator [SOED, \"escalator\"].",
    2, &(EGBindingForEC[616]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ESCARPMENT,
    "ESCARPMENT", "ECC_ESCARPMENT",
    "A steep, vertical, or overhanging face of <ROCK> and/or <SOIL> in the"
    " <LAND>; an escarpment.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ESKER,
    "ESKER", "ECC_ESKER",
    "A long, narrow <RIDGE> of <SAND> and gravel deposited by a glacial"
    " <RIVER>; an esker.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ESTUARY,
    "ESTUARY", "ECC_ESTUARY",
    "An arm of a <WATERBODY> that extends inland to meet the mouth of a"
    " <RIVER> and includes a mixture of fresh and salt <WATER>; an estuary"
    " [AHD, \"estuary\", 2].",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXCAVATING_MACHINE,
    "EXCAVATING_MACHINE", "ECC_EXCAVATING_MACHINE",
    "<EQUIPMENT> for removing <MATERIAL>s (for example: <SOIL>) from the"
    " <TERRAIN>; an excavating machine.",
    2, &(EGBindingForEC[586]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AF050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXCAVATION,
    "EXCAVATION", "ECC_EXCAVATION",
    "An excavated space in the <TERRAIN>; an excavation [SOED,"
    " \"excavation\", 2], a cavity, or a hollow.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXHIBITION_GROUND,
    "EXHIBITION_GROUND", "ECC_EXHIBITION_GROUND",
    "A <SITE> where permanent <STRUCTURE>s exist to hold outdoor"
    " exhibitions; an exhibition ground.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK091]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXPLOSIVE_CHARGE,
    "EXPLOSIVE_CHARGE", "ECC_EXPLOSIVE_CHARGE",
    "An explosive <DEVICE> that may be detonated to either damage or"
    " destroy <STRUCTURE>s or to move <ROCK>, <SOIL>, and/or other"
    " <MATERIAL>s; an explosive charge.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXPLOSIVE_LAND_MINE,
    "EXPLOSIVE_LAND_MINE", "ECC_EXPLOSIVE_LAND_MINE",
    "An <EXPLOSIVE_MINE> used in land warfare.",
    2, &(EGBindingForEC[612]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"land-mine\", a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXPLOSIVE_MINE,
    "EXPLOSIVE_MINE", "ECC_EXPLOSIVE_MINE",
    "An explosive <DEVICE> located on or below a <PLANETARY_SURFACE>,"
    " usually emplaced for military purposes; an explosive mine [SOED,"
    " \"land-mine\", a].",
    2, &(EGBindingForEC[612]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXPLOSIVE_NAVAL_MINE,
    "EXPLOSIVE_NAVAL_MINE", "ECC_EXPLOSIVE_NAVAL_MINE",
    "An <EXPLOSIVE_MINE> used in naval warfare.",
    3, &(EGBindingForEC[580]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD001]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXPOSED_BEDROCK,
    "EXPOSED_BEDROCK", "ECC_EXPOSED_BEDROCK",
    "A <TERRAIN_SURFACE_REGION> consisting principally of <BEDROCK> that is"
    " covered by less than 10 percent loose <MATERIAL> (for example:"
    " <SOIL>, <SAND>, clay, and/or gravel); exposed bedrock.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: SA030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXTERIOR_HALLWAY,
    "EXTERIOR_HALLWAY", "ECC_EXTERIOR_HALLWAY",
    "A <HALLWAY> along the exterior of a <BUILDING>, often appearing as a"
    " long <BALCONY>.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXTERIOR_WALL,
    "EXTERIOR_WALL", "ECC_EXTERIOR_WALL",
    "A <WALL> forming an exterior section of a <STRUCTURE>.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXTRACTION_FACILITY,
    "EXTRACTION_FACILITY", "ECC_EXTRACTION_FACILITY",
    "A <FACILITY> for extracting and/or exploiting natural resources; an"
    " extraction facility.",
    2, &(EGBindingForEC[970]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: PRDINS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_EXTRACTION_MINE,
    "EXTRACTION_MINE", "ECC_EXTRACTION_MINE",
    "An <EXCAVATION> made in the <TERRAIN> for the purpose of extracting"
    " and/or exploiting natural resources; an extraction mine.",
    3, &(EGBindingForEC[959]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AA010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FABRICATION_BUILDING,
    "FABRICATION_BUILDING", "ECC_FABRICATION_BUILDING",
    "A <BUILDING> used for the purpose of manufacturing <COMPONENT>s, which"
    " may be assembled on-site or elsewhere, to make a completed product; a"
    " fabrication building.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FABRICATION_FACILITY,
    "FABRICATION_FACILITY", "ECC_FABRICATION_FACILITY",
    "A <FACILITY> including one or more <FABRICATION_BUILDING>s.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FACILITY,
    "FACILITY", "ECC_FACILITY",
    "A <REGION> that includes <MAN_MADE_OBJECT>s intended to serve a"
    " particular purpose; a facility.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FACTORY,
    "FACTORY", "ECC_FACTORY",
    "A <BUILDING> containing <EQUIPMENT> for use in manufacturing; a"
    " factory [SOED, \"factory\", 3].",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FAIRGROUND,
    "FAIRGROUND", "ECC_FAIRGROUND",
    "A <SITE> where permanent <STRUCTURE>s exist to hold outdoor fairs,"
    " circuses, and/or exhibitions; a fairground.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FARM,
    "FARM", "ECC_FARM",
    "A <SITE>, including support <STRUCTURE>s, used for agricultural or"
    " aquacultural production; a farm.",
    2, &(EGBindingForEC[198]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FARM_BUILDING,
    "FARM_BUILDING", "ECC_FARM_BUILDING",
    "A <BUILDING> located on a <FARM>.",
    2, &(EGBindingForEC[196]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:19]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FARM_STORAGE_STRUCTURE,
    "FARM_STORAGE_STRUCTURE", "ECC_FARM_STORAGE_STRUCTURE",
    "A <STRUCTURE>, often having a <ROOF>, located on a <FARM> and used for"
    " sheltering livestock and/or storing agricultural products or"
    " <EQUIPMENT>; a farm storage structure.",
    4, &(EGBindingForEC[155]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"barn\", A.2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_FENCE,
    "FENCE", "ECC_FENCE",
    "A man-made <BARRIER> of relatively light construction used as an"
    " enclosure or <BOUNDARY>; a fence.",
    1, &(EGBindingForEC[13]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FENDER_CUSHION,
    "FENDER_CUSHION", "ECC_FENDER_CUSHION",
    "A protective <DEVICE> designed to cushion the impact of a <VESSEL>"
    " against a <STRUCTURE> or other <VESSEL> and to prevent damage; a"
    " fender cushion.",
    4, &(EGBindingForEC[571]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB198]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FERN,
    "FERN", "ECC_FERN",
    "A <PTERIDOPHYTE> of the order Filicopsida, the members of which"
    " reproduce by means of spores borne usually on the underside of the"
    " fronds, which are typically pinnately divided; a fern [SOED,"
    " \"fern\"].",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FERRY,
    "FERRY", "ECC_FERRY",
    "A <WATER_SURFACE_VESSEL> for transporting <HUMAN>s, <GROUND_VEHICLE>s,"
    " or <CARGO> across a <WATERBODY>; a ferry [SOED, \"ferry\", 3.a].",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FERRY_CROSSING,
    "FERRY_CROSSING", "ECC_FERRY_CROSSING",
    "A <MARINE_ROUTE> where a <FERRY> crosses from one <SHORE> to another;"
    " a ferry crossing.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: FERYRT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FERRY_LOCATION,
    "FERRY_LOCATION", "ECC_FERRY_LOCATION",
    "A <LOCATION> where a <FERRY> takes on or discharges its load.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIDUCIAL_POINT,
    "FIDUCIAL_POINT", "ECC_FIDUCIAL_POINT",
    "A <LOCATION> used as a basis of cadastral reference; a fiducial point.",
    3, &(EGBindingForEC[122]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: ID020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIELD_ARTILLERY,
    "FIELD_ARTILLERY", "ECC_FIELD_ARTILLERY",
    "A large-calibre firing <WEAPON>; a field artillery piece. EXAMPLES"
    " Howitzer, cannon.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"artillery\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIGHTER_WINGED_AIRCRAFT,
    "FIGHTER_WINGED_AIRCRAFT", "ECC_FIGHTER_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed for fast maneuver aerial combat"
    " operations; a fighter aircraft [SOED, \"fighter\", 2].",
    4, &(EGBindingForEC[254]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIGHTING_POSITION,
    "FIGHTING_POSITION", "ECC_FIGHTING_POSITION",
    "A configuration of <LAND> and/or <STRUCTURE>s that is intended to"
    " accommodate <MILITARY_PERSONNEL>, military <EQUIPMENT>, and/or"
    " military <GROUND_VEHICLE>s; that provides cover and concealment from"
    " direct and potentially indirect fire; and that affords effective use"
    " of <WEAPON>s; a fighting position.",
    2, &(EGBindingForEC[1117]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FILLED_TERRAIN,
    "FILLED_TERRAIN", "ECC_FILLED_TERRAIN",
    "<BUILT_UP_TERRAIN> that has been brought to a required higher"
    " <<TERRAIN_ELEVATION>> or levelled through the addition of <SOIL>,"
    " <ROCK>, and/or other <MATERIAL>s; filled terrain.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FILTRATION_BED,
    "FILTRATION_BED", "ECC_FILTRATION_BED",
    "A <TRACT> for the treatment of <WATER> that consists of a bed of"
    " porous <MATERIAL> that <WATER> is passed through in order to remove"
    " solids or impurities; a filtration bed.",
    3, &(EGBindingForEC[991]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FILTRATION_BUILDING,
    "FILTRATION_BUILDING", "ECC_FILTRATION_BUILDING",
    "A <BUILDING> that houses <EQUIPMENT> through which a liquid or gas is"
    " passed in order to separate the fluid from suspended particulate"
    " matter; a filtration building.",
    2, &(EGBindingForEC[984]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:84]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIORD,
    "FIORD", "ECC_FIORD",
    "A long, narrow, deep <INLET> of a <WATERBODY> between <TERRAIN> with"
    " steep <<TERRAIN_SLOPE>>s; a fiord [SOED, \"fiord\"].",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIRE_AND_POLICE_STATION,
    "FIRE_AND_POLICE_STATION", "ECC_FIRE_AND_POLICE_STATION",
    "A <PUBLIC_SERVICE_STATION> that houses both a <FIRE_STATION> and a"
    " <POLICE_STATION>.",
    2, &(EGBindingForEC[120]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:723]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIRE_ESCAPE,
    "FIRE_ESCAPE", "ECC_FIRE_ESCAPE",
    "An exterior <STRUCTURE> or <DEVICE> erected for emergency exit in the"
    " event of fire; a fire-escape [AHD, \"fire escape\"]. EXAMPLE An"
    " outside <STAIR> that is attached to a <BUILDING>.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIRE_STATION,
    "FIRE_STATION", "ECC_FIRE_STATION",
    "A <PUBLIC_SERVICE_STATION> that houses both fire-fighting <EQUIPMENT>"
    " and <PERSONNEL>; a fire station [MWCD, \"fire station\"] or firehouse.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FIREBREAK,
    "FIREBREAK", "ECC_FIREBREAK",
    "A cleared or ploughed <TERRAIN_STRIP> that is constructed as a"
    " <BARRIER> against the spread of a forest or prairie fire; a firebreak"
    " [SOED, \"fire-break\"].",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISH,
    "FISH", "ECC_FISH",
    "A cold-blooded aquatic <VERTEBRATE> possessing gills and fins; a fish"
    " [SOED, \"fish\", I.1.a].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISH_HATCHERY,
    "FISH_HATCHERY", "ECC_FISH_HATCHERY",
    "An enclosed <REGION> and associated <STRUCTURE>s used for the breeding"
    " and/or rearing of <FISH>; a fish hatchery.",
    4, &(EGBindingForEC[159]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISH_LADDER,
    "FISH_LADDER", "ECC_FISH_LADDER",
    "A series of ascending pools constructed to enable <FISH> to swim"
    " upstream over (or around) a <DAM>; a fish ladder.",
    3, &(EGBindingForEC[309]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISH_SCHOOL,
    "FISH_SCHOOL", "ECC_FISH_SCHOOL",
    "A naturally occurring grouping of <FISH> that persists over a"
    " significant period; a fish school.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISH_STAKE_REGION,
    "FISH_STAKE_REGION", "ECC_FISH_STAKE_REGION",
    "A <REGION> where <POLE>s or <STAKE>s are placed in shallow <WATER> to"
    " outline a fishing ground or to catch <FISH>.",
    3, &(EGBindingForEC[349]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISH_TRAP,
    "FISH_TRAP", "ECC_FISH_TRAP",
    "A <FENCE> or enclosure <DEVICE> set in a <WATERBODY> to catch <FISH>;"
    " a fish trap.",
    4, &(EGBindingForEC[295]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB110]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISHING_BOAT,
    "FISHING_BOAT", "ECC_FISHING_BOAT",
    "A <WATER_SURFACE_VESSEL> designed or designated to catch <FISH> for"
    " either commercial or leisure purposes; a fishing boat.",
    8, &(EGBindingForEC[312]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISHING_FACILITY,
    "FISHING_FACILITY", "ECC_FISHING_FACILITY",
    "A <FACILITY> involved in fishing, the raising of <FISH>, and/or the"
    " storage or transportation of either <MATERIAL>s important to or the"
    " results of the production of <FISH>.",
    6, &(EGBindingForEC[141]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD079]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FISHING_HARBOUR,
    "FISHING_HARBOUR", "ECC_FISHING_HARBOUR",
    "A <HARBOUR> that is primarily used by <FISHING_BOAT>s.",
    7, &(EGBindingForEC[302]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB105]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLAGPOLE,
    "FLAGPOLE", "ECC_FLAGPOLE",
    "A <POLE> on which a flag is raised; a flagstaff or flagpole.",
    1, &(EGBindingForEC[2]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: FLGSTF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLARE_PIPE,
    "FLARE_PIPE", "ECC_FLARE_PIPE",
    "An open-ended <PIPE> at which waste gases are burned; a flare pipe or"
    " flare stack.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: FLASTK]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLEXIBLE_RESTRAINT,
    "FLEXIBLE_RESTRAINT", "ECC_FLEXIBLE_RESTRAINT",
    "A physical connection between two independent <OBJECT>s (for example:"
    " between a <VESSEL> and a mooring <BUOY> or <BOLLARD>). EXAMPLES"
    " <CHAIN>, <LOAD_CABLE>.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD074]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLIGHT_LEVEL,
    "FLIGHT_LEVEL", "ECC_FLIGHT_LEVEL",
    "A <SURFACE> of constant <<ATM_PRESSURE>> that is measured in relation"
    " to the specific pressure <DATUM> 1 013,25 hectopascals and is"
    " separated from other such <SURFACE>s by specific pressure intervals.",
    2, &(EGBindingForEC[200]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[IAN4, 1.1, \"flight level\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLOATING_BREAKWATER,
    "FLOATING_BREAKWATER", "ECC_FLOATING_BREAKWATER",
    "A <STRUCTURE> consisting of a series of square frames of timber"
    " connected by <MOORING_LINE>s attached to <ANCHOR>s or stone blocks in"
    " such a manner as to form a <BREAKWATER> that protects <VESSEL>s"
    " riding to anchor; a floating breakwater.",
    4, &(EGBindingForEC[715]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"floating breakwater\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLOATING_DOCK,
    "FLOATING_DOCK", "ECC_FLOATING_DOCK",
    "A form of <DRY_DOCK> consisting of a floating <STRUCTURE> of one or"
    " more sections that can be partly submerged by controlled flooding to"
    " receive a <VESSEL> and then raised by pumping out the <WATER> so that"
    " the bottom of the <VESSEL> can be exposed; a floating dock.",
    4, &(EGBindingForEC[715]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"dock: floating\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLOOD_BARRAGE,
    "FLOOD_BARRAGE", "ECC_FLOOD_BARRAGE",
    "An artificial obstruction placed in a <WATERCOURSE> to raise the level"
    " of the <WATER> or to divert it; a flood barrage.",
    1, &(EGBindingForEC[19]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI043]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLOOD_BASIN,
    "FLOOD_BASIN", "ECC_FLOOD_BASIN",
    "A <TRACT> that submerges during the highest known flood in a"
    " <TERRAIN_SURFACE_REGION> or has the potential for being flooded (for"
    " example: by the failure of a <DAM>); a flood basin.",
    2, &(EGBindingForEC[865]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"flood basin\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLOOR,
    "FLOOR", "ECC_FLOOR",
    "A layer of <MATERIAL> (for example: board, brick, and/or stone) in a"
    " <ROOM> or <VEHICLE> on which <HUMAN>s and/or <ANIMAL>s tread; a floor"
    " [SOED, \"floor\", 1.a].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLOOR_CRAWL_SPACE,
    "FLOOR_CRAWL_SPACE", "ECC_FLOOR_CRAWL_SPACE",
    "A space within a <BUILDING>, located under a <FLOOR>, usually of"
    " restricted <<HEIGHT>>, and having sufficient <<HEIGHT>> for <HUMAN>s"
    " to crawl; a floor crawl space.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLOOR_LEVEL,
    "FLOOR_LEVEL", "ECC_FLOOR_LEVEL",
    "A <NON_EMPTY_SET> of <ROOM>s and landings of <STAIR>s in a <BUILDING>"
    " that are on the same or nearly the same level; a floor level or"
    " storey.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"storey\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLUID_BOUNDARY_LAYER,
    "FLUID_BOUNDARY_LAYER", "ECC_FLUID_BOUNDARY_LAYER",
    "The layer of fluid in the immediate vicinity of a <SURFACE> where"
    " frictional forces control fluid flow; a fluid boundary layer.",
    1, &(EGBindingForEC[17]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"boundary layer\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FLUME,
    "FLUME", "ECC_FLUME",
    "An open, inclined <WATERCOURSE> that carries <WATER> for use in such"
    " operations as mining or logging; a flume.",
    2, &(EGBindingForEC[846]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FOG,
    "FOG", "ECC_FOG",
    "A suspension of very small, usually microscopic, droplets of <WATER>"
    " in the <AIR> that reduces the horizontal <<VISIBILITY_DISTANCE>> at a"
    " <PLANETARY_SURFACE>; fog.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"fog\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FOG_REGION,
    "FOG_REGION", "ECC_FOG_REGION",
    "A <REGION> of <FOG> at or near a <PLANETARY_SURFACE>.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FOG_SIGNAL_DEVICE,
    "FOG_SIGNAL_DEVICE", "ECC_FOG_SIGNAL_DEVICE",
    "A <DEVICE> that produces a warning signal as an <AID_TO_NAVIGATION>"
    " during periods of low visibility, especially due to <FOG>.",
    6, &(EGBindingForEC[275]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"fog signal\" (device)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FOOD_OVEN,
    "FOOD_OVEN", "ECC_FOOD_OVEN",
    "<EQUIPMENT> consisting of a chamber or enclosed compartment for"
    " heating, baking, or roasting food; an oven or stove [AHD, \"oven\"].",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FORD,
    "FORD", "ECC_FORD",
    "A shallow <REGION> in a <WATERBODY> used as a <CROSSING> by"
    " <GROUND_VEHICLE>s or <ANIMAL>s; a ford.",
    5, &(EGBindingForEC[322]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FORESHORE,
    "FORESHORE", "ECC_FORESHORE",
    "A <COMPONENT> of the <SHORE> or <BEACH> that lies between the low"
    " water mark and the <COASTLINE> or <SHORELINE>; a foreshore. Foreshore"
    " includes any isolated <TERRAIN_SURFACE_REGION>s which cover and"
    " uncover with the <TIDE> yet are not contiguous with the <COASTLINE>"
    " or <SHORELINE>.",
    2, &(EGBindingForEC[1066]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BA020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FORESHORE_PRECISE,
    "FORESHORE_PRECISE", "ECC_FORESHORE_PRECISE",
    "A <FORESHORE>, the low water mark of which is the <LINE> defined by"
    " mean low water springs or mean lower low water as appropriate and the"
    " <COASTLINE> or <SHORELINE> of which is defined by the normal limit of"
    " <WATER_WAVE> action above mean high water springs or mean higher high"
    " water as appropriate; foreshore precise.",
    2, &(EGBindingForEC[1066]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BA023]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FOREST,
    "FOREST", "ECC_FOREST",
    "A <TRACT> containing a substantial number of closely spaced <TREE>s; a"
    " forest.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EC015]",
    "[SOED, \"forest\", A.1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_FOREST_PRESERVE,
    "FOREST_PRESERVE", "ECC_FOREST_PRESERVE",
    "A <FOREST> that is protected from logging and other human activities"
    " detrimental to the environment; a forest preserve.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FORT,
    "FORT", "ECC_FORT",
    "A permanently fortified <STRUCTURE> that may be stationed with"
    " <MILITARY_PERSONNEL> and is generally walled or heavily fenced with"
    " overwatch positions; a fort.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AH050]",
    "[SOED, \"fort\", I.1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_FORTIFICATION,
    "FORTIFICATION", "ECC_FORTIFICATION",
    "A <STRUCTURE> constructed for the military defence of a <SITE>; a"
    " fortification.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: FORSTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FOUNTAIN,
    "FOUNTAIN", "ECC_FOUNTAIN",
    "A <STRUCTURE> built for one or more jets of <WATER> to spout and fall"
    " into; a fountain [SOED, \"fountain\", 2.a].",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH075]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FREEZING_DRIZZLE,
    "FREEZING_DRIZZLE", "ECC_FREEZING_DRIZZLE",
    "<DRIZZLE> that falls in liquid form but freezes upon impact to form a"
    " coating of <ICE_GLAZE> on the <LAND> and on exposed <OBJECT>s;"
    " freezing drizzle.",
    2, &(EGBindingForEC[376]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"freezing drizzle\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FREEZING_RAIN,
    "FREEZING_RAIN", "ECC_FREEZING_RAIN",
    "<RAIN> that falls in liquid form but freezes upon impact to form a"
    " coating of <ICE_GLAZE> upon the <LAND> and on exposed <OBJECT>s;"
    " freezing rain.",
    2, &(EGBindingForEC[376]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"freezing rain\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FRIGATE,
    "FRIGATE", "ECC_FRIGATE",
    "A <WATER_SURFACE_VESSEL> that is smaller than a <CRUISER> and is"
    " designed for escort operations; a frigate.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"frigate\", 3b]", EDCS_CONCEPT_STAT_ISO },

    {ECC_FROZEN_PRECIPITATION_FIELD,
    "FROZEN_PRECIPITATION_FIELD", "ECC_FROZEN_PRECIPITATION_FIELD",
    "A large <TRACT> that is permanently covered by <SNOW_GROUND_COVER>"
    " and/or <ICE>; a snowfield or an ice-field. EXAMPLES"
    " <PERMANENT_SNOWFIELD>, <ICE_FIELD>.",
    3, &(EGBindingForEC[888]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BJ100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FUNGUS,
    "FUNGUS", "ECC_FUNGUS",
    "A <LIVING_ORGANISM> of the kingdom Fungi, the members of which lack"
    " chlorophyll and grow on and obtain nutriment from organic matter; a"
    " fungus [SOED, \"fungus\"]. EXAMPLES <MUSHROOM>, toadstool, mould,"
    " rust, yeast, fungus constituent of a <LICHEN>.",
    1, &(EGBindingForEC[31]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FURNACE,
    "FURNACE", "ECC_FURNACE",
    "<EQUIPMENT> consisting of a combustion chamber in which items such as"
    " minerals, metals, and ores may be subjected to continuous intense"
    " heat; a furnace [SOED, \"furnace\", A].",
    3, &(EGBindingForEC[962]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_FURNITURE,
    "FURNITURE", "ECC_FURNITURE",
    "Movable, functional <OBJECT>s, whether useful or ornamental, usually"
    " found in a <BUILDING>; furniture [SOED, \"furniture\", 6].",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GALAXY,
    "GALAXY", "ECC_GALAXY",
    "Any of numerous vast systems of <STAR>s, gas, and interstellar dust"
    " that exists separately in the universe and together contain nearly"
    " all of its visible matter; a galaxy [SOED, \"galaxy\", 1b].",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GANTRY,
    "GANTRY", "ECC_GANTRY",
    "A frame <STRUCTURE> raised on side supports to span over or around"
    " something; a gantry.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GASTROPOD,
    "GASTROPOD", "ECC_GASTROPOD",
    "A <MOLLUSC> of the class Gastropoda, the members of which typically"
    " have a flattened ventral foot for locomotion and a univalve shell; a"
    " gastropod. EXAMPLES Snail, slug, whelk, limpet.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"gastropod\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_GATE,
    "GATE", "ECC_GATE",
    "A <BARRIER> that controls passage on a <LAND_TRANSPORTATION_ROUTE>; a"
    " gate.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AP040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GEODETIC_DATUM,
    "GEODETIC_DATUM", "ECC_GEODETIC_DATUM",
    "A datum (see I19111, 4.9) describing the relationship of a coordinate"
    " system (see I19111, 4.7) to the <EARTH>; a geodetic datum or a"
    " horizontal datum.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[I19111, 4.16]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GEOGRAPHIC_BASIN,
    "GEOGRAPHIC_BASIN", "ECC_GEOGRAPHIC_BASIN",
    "The <TERRAIN_SURFACE_REGION> that is drained by a <RIVER> and its"
    " tributaries or that drains into a particular <LAKE> or <SEA>; a"
    " geographic basin.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"basin\" (geography)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GEOGRAPHIC_INFORMATION,
    "GEOGRAPHIC_INFORMATION", "ECC_GEOGRAPHIC_INFORMATION",
    "A <LOCATION> or <REGION> where geographic information or statistics"
    " may apply.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZD012]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GEOLOGIC_FAULT,
    "GEOLOGIC_FAULT", "ECC_GEOLOGIC_FAULT",
    "A fracture in the <TERRAIN> with displacement on one side of the"
    " fracture relative to the other; a geologic fault.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB110]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GEOPHYSICAL_SURVEY_PATH,
    "GEOPHYSICAL_SURVEY_PATH", "ECC_GEOPHYSICAL_SURVEY_PATH",
    "A path marked on the <TERRAIN> resulting from geophysical survey"
    " operations.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FA090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GEOPHYSICAL_SURVEY_POINT,
    "GEOPHYSICAL_SURVEY_POINT", "ECC_GEOPHYSICAL_SURVEY_POINT",
    "A survey <LOCATION> established for the collection of geophysical"
    " data; a geophysical survey point.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FA090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GEOTHERMAL_OBJECT,
    "GEOTHERMAL_OBJECT", "ECC_GEOTHERMAL_OBJECT",
    "A localized <TERRAIN_SURFACE_OBJECT> that is controlled by or derived"
    " from the heat of the interior of a <PLANET>. EXAMPLE Hot <SPRING>.",
    1, &(EGBindingForEC[47]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB115]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GLACIER,
    "GLACIER", "ECC_GLACIER",
    "A large mass of land-based <SNOW_GROUND_COVER> and <ICE> moving slowly"
    " down a slope or <VALLEY_REGION> from above the snowline; a glacier.",
    1, &(EGBindingForEC[23]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BJ030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GLADE,
    "GLADE", "ECC_GLADE",
    "A <TRACT> with few or no <TREE>s that is surrounded by a"
    " <TREED_TRACT>; a clearing or glade.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"glade\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_GOLF_COURSE,
    "GOLF_COURSE", "ECC_GOLF_COURSE",
    "A <TRACT> laid out for playing the game of golf; a golf course.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GOLF_DRIVING_RANGE,
    "GOLF_DRIVING_RANGE", "ECC_GOLF_DRIVING_RANGE",
    "A <TRACT> used for practicing golf shots; a golf driving range.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK101]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GORGE,
    "GORGE", "ECC_GORGE",
    "A deep, narrow <TERRAIN_CHANNEL> with steep rocky sides; a gorge [AHD,"
    " \"gorge\", 1].",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GOVERNMENT_BUILDING,
    "GOVERNMENT_BUILDING", "ECC_GOVERNMENT_BUILDING",
    "A <BUILDING> devoted to the act or process of administration of public"
    " policy in a political unit; a government building.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GOVERNMENT_FACILITY,
    "GOVERNMENT_FACILITY", "ECC_GOVERNMENT_FACILITY",
    "A <FACILITY> including one or more <GOVERNMENT_BUILDING>s; a"
    " government facility.",
    3, &(EGBindingForEC[133]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GRADATION_WORKS,
    "GRADATION_WORKS", "ECC_GRADATION_WORKS",
    "A <STRUCTURE> over which brine trickles and is concentrated through"
    " increased evaporation; a gradation works.",
    2, &(EGBindingForEC[586]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AA060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GRAIN_ELEVATOR,
    "GRAIN_ELEVATOR", "ECC_GRAIN_ELEVATOR",
    "A <NON_EMPTY_SET> of tall <STRUCTURE>s equipped for loading,"
    " unloading, processing, and/or storing grain; a grain elevator.",
    3, &(EGBindingForEC[178]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AM030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GRAIN_STORAGE_STRUCTURE,
    "GRAIN_STORAGE_STRUCTURE", "ECC_GRAIN_STORAGE_STRUCTURE",
    "An enclosed <CONTAINER> used for storing grain or fodder; a grain bin"
    " or grain silo.",
    4, &(EGBindingForEC[163]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: SILBUI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GRANDSTAND,
    "GRANDSTAND", "ECC_GRANDSTAND",
    "A <STRUCTURE> for special viewing of outdoor events that has tiers of"
    " seats or standing room for spectators; a grandstand.",
    1, &(EGBindingForEC[39]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK110]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GRASS,
    "GRASS", "ECC_GRASS",
    "Any <PLANT> of the large cosmopolitan family Gramineae (including"
    " cereals, reeds, and bamboos besides the characteristic <PLANT>s of"
    " pasture-land), members of which typically have erect jointed stems"
    " (culms) bearing narrow bladelike leaves and insignificant flowers, or"
    " any of various <PLANT>s resembling the members of Gramineae in"
    " appearance; grass [SOED, \"grass\", 4.b].",
    1, &(EGBindingForEC[36]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EB015]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GRASS_LAND,
    "GRASS_LAND", "ECC_GRASS_LAND",
    "A <TRACT> covered by <GRASS> that has little or no woody tissue; a"
    " grassland.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EB010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GRAVE_MARKER,
    "GRAVE_MARKER", "ECC_GRAVE_MARKER",
    "A <MARKER>, often located at a <CEMETERY>, indicating an individual"
    " gravesite; a grave marker.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GREEN_SPACE,
    "GREEN_SPACE", "ECC_GREEN_SPACE",
    "A maintained <TRACT> that is covered by <VEGETATION>, which may also"
    " contain pathways, intended to improve the appearance of a"
    " <BUILT_UP_REGION> but not to be a <PARK>; a green space.",
    4, &(EGBindingForEC[1083]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK122]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GREENHOUSE,
    "GREENHOUSE", "ECC_GREENHOUSE",
    "A <BUILDING>, which is often constructed primarily of transparent"
    " <MATERIAL> (for example: glass or plastic), in which"
    " <<AIR_TEMPERATURE>> and <<RELATIVE_HUMIDITY>> can be controlled for"
    " the cultivation and/or protection of <PLANT>s; a greenhouse [SOED,"
    " \"greenhouse\", a].",
    4, &(EGBindingForEC[186]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GROIN,
    "GROIN", "ECC_GROIN",
    "A <STRUCTURE> that normally projects outward from a <SHORE> and"
    " protects a <BEACH> from erosion by disrupting the alongshore movement"
    " of <SAND> and other <SEDIMENT>s but not by preventing <WATER_WAVE>s"
    " from reaching the <SHORE>; a groin.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB043]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GROUND_SURFACE_ELEMENT,
    "GROUND_SURFACE_ELEMENT", "ECC_GROUND_SURFACE_ELEMENT",
    "A surface <SOIL> characteristic of the <LAND>; a ground surface"
    " element.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DA010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GROUND_VEHICLE,
    "GROUND_VEHICLE", "ECC_GROUND_VEHICLE",
    "A <VEHICLE> operating principally on <LAND>; a ground vehicle.",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GROUNDS,
    "GROUNDS", "ECC_GROUNDS",
    "A large enclosed <TRACT> surrounding or attached to a <BUILDING>, most"
    " commonly a <HOUSE>; grounds [SOED, \"ground\", 13].",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GUARD_TOWER,
    "GUARD_TOWER", "ECC_GUARD_TOWER",
    "An elevated enclosed <BUILDING> including one or more <GUARDROOM>s; a"
    " guard tower.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:137]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GUARDHOUSE,
    "GUARDHOUSE", "ECC_GUARDHOUSE",
    "A small enclosed <BUILDING> accommodating a guard or serving as a"
    " <DETENTION_FACILITY>; a guardhouse [SOED, \"guardhouse\"].",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GUARDROOM,
    "GUARDROOM", "ECC_GUARDROOM",
    "A small enclosed <ROOM> accommodating a guard or serving as a"
    " <DETENTION_FACILITY>; a guardroom [SOED, \"guardroom\"].",
    2, &(EGBindingForEC[418]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GUIDED_MISSILE_CRUISER,
    "GUIDED_MISSILE_CRUISER", "ECC_GUIDED_MISSILE_CRUISER",
    "A <CRUISER> equipped with guided <MISSILE>s.",
    4, &(EGBindingForEC[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GUIDED_MISSILE_DESTROYER,
    "GUIDED_MISSILE_DESTROYER", "ECC_GUIDED_MISSILE_DESTROYER",
    "A <DESTROYER> equipped with guided <MISSILE>s.",
    4, &(EGBindingForEC[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GUIDED_MISSILE_FRIGATE,
    "GUIDED_MISSILE_FRIGATE", "ECC_GUIDED_MISSILE_FRIGATE",
    "A <FRIGATE> equipped with guided <MISSILE>s.",
    4, &(EGBindingForEC[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_GULLY,
    "GULLY", "ECC_GULLY",
    "A long, narrow, deep <TERRAIN_CHANNEL> that is caused by erosion and"
    " has steep banks; a gully.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB200]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HAIL,
    "HAIL", "ECC_HAIL",
    "<SOLID_PRECIPITATION> of either transparent or partly or completely"
    " opaque <PARTICLE>s of <ICE> (hailstones), usually spherical, conical,"
    " or irregular in form and of <<OUTSIDE_DIAMETER>> generally between 5"
    " and 50 millimetres, that falls from a <CLOUD> either separately or"
    " agglomerated into irregular lumps; hail.",
    3, &(EGBindingForEC[281]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"hail\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HALLWAY,
    "HALLWAY", "ECC_HALLWAY",
    "An entrance-hall or passage serving as a <ROUTE> to various <ROOM>s in"
    " a <BUILDING>; a hallway [SOED, \"hallway\"] or corridor.",
    3, &(EGBindingForEC[408]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HARBOUR,
    "HARBOUR", "ECC_HARBOUR",
    "A <WATERBODY_REGION> providing <ANCHORAGE> and protection for"
    " <VESSEL>s; a harbour.",
    6, &(EGBindingForEC[675]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HARBOUR_COMPLEX,
    "HARBOUR_COMPLEX", "ECC_HARBOUR_COMPLEX",
    "A <HARBOUR> including one or more <ANCHORAGE_COMPLEX>s; a harbour"
    " complex.",
    6, &(EGBindingForEC[675]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB006]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HARD_STANDING,
    "HARD_STANDING", "ECC_HARD_STANDING",
    "An open <TRACT> with a prepared <SURFACE> of pavement or gravel used"
    " for parking and/or storing <VEHICLE>s, particularly <AIRCRAFT>; a"
    " hard standing [SOED, \"hard standing\"].",
    4, &(EGBindingForEC[261]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HARDENED_AIRCRAFT_SHELTER,
    "HARDENED_AIRCRAFT_SHELTER", "ECC_HARDENED_AIRCRAFT_SHELTER",
    "A reinforced <SHELTER> that is resistant to <MUNITION>s and is"
    " designed for the protection of <AIRCRAFT>; a hardened aircraft"
    " shelter.",
    4, &(EGBindingForEC[247]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HAYSTACK,
    "HAYSTACK", "ECC_HAYSTACK",
    "A regular pile of hay built in the open air; a haystack.",
    3, &(EGBindingForEC[178]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HAZARD_MARKER,
    "HAZARD_MARKER", "ECC_HAZARD_MARKER",
    "A <MARKER> placed near or on a <TERRAIN_SURFACE_REGION> or"
    " <TERRAIN_SURFACE_OBJECT> to identify it as a potential hazard.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HEALTH_OFFICE,
    "HEALTH_OFFICE", "ECC_HEALTH_OFFICE",
    "A <BUILDING> used in the diagnosis and care of outpatients; a health"
    " office or clinic.",
    2, &(EGBindingForEC[984]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HEAT_RADIATOR,
    "HEAT_RADIATOR", "ECC_HEAT_RADIATOR",
    "<EQUIPMENT> consisting of a <STORAGE_TANK> and/or compact array of"
    " <PIPE>s that: has a large surface <<AREA>>; is heated, usually by"
    " circulating steam or hot <WATER>; and gives off warmth by radiation"
    " and convection; a heat radiator [SOED, \"radiator\", 2].",
    2, &(EGBindingForEC[614]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HEATING_FACILITY,
    "HEATING_FACILITY", "ECC_HEATING_FACILITY",
    "A <FACILITY> for the generation of thermal energy for heating purposes.",
    3, &(EGBindingForEC[996]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AD050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HEAVY_INDUSTRIAL_FACILITY,
    "HEAVY_INDUSTRIAL_FACILITY", "ECC_HEAVY_INDUSTRIAL_FACILITY",
    "A <FACILITY> devoted to the processing of <MATERIAL> and/or the"
    " manufacture of goods (for example: steel, aluminum, glass, or"
    " <MOTOR_VEHICLE>s) that generally require significant <EQUIPMENT>,"
    " <MATERIAL>, and energy inputs; a heavy industrial facility.",
    2, &(EGBindingForEC[970]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HEDGEROW,
    "HEDGEROW", "ECC_HEDGEROW",
    "A continuous growth of <SHRUB>s planted as a <FENCE>, a <BOUNDARY>,"
    " and/or a windbreak; a hedgerow.",
    4, &(EGBindingForEC[536]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EA020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HELICOPTER,
    "HELICOPTER", "ECC_HELICOPTER",
    "An <AIRCRAFT> deriving both lift and propulsive power from"
    " horizontally revolving rotor blades and capable of ascending and"
    " descending vertically; a helicopter [SOED, \"helicopter\"].",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HELICOPTER_LANDING_PAD,
    "HELICOPTER_LANDING_PAD", "ECC_HELICOPTER_LANDING_PAD",
    "An improved <SITE> used for take-off and landing VTOL <AIRCRAFT> (for"
    " example: a <HELICOPTER>); a helicopter landing pad.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HELIPORT,
    "HELIPORT", "ECC_HELIPORT",
    "An <AERODROME> or a defined <REGION> on a <STRUCTURE> intended to be"
    " used wholly or in part for the arrival, departure, and/or surface"
    " movement of <HELICOPTER>s; a heliport.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_INFORMATIVE, "[IAN14, Volume II]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HIGH_CLOUD,
    "HIGH_CLOUD", "ECC_HIGH_CLOUD",
    "A <CLOUD> of the genus cirrus, cirrocumulus, or cirrostratus; a high"
    " cloud. Also the top of a <CLOUD> of the genus cumulonimbus or,"
    " occasionally, altostratus.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.2.1.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HIGH_PRESSURE_CENTRE,
    "HIGH_PRESSURE_CENTRE", "ECC_HIGH_PRESSURE_CENTRE",
    "The <LOCATION> of the centre of an <ATMOSPHERE_REGION> of high"
    " <<ATM_PRESSURE>>.",
    2, &(EGBindingForEC[386]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"pressure center\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HILL,
    "HILL", "ECC_HILL",
    "A small, isolated, elevated portion of the <TERRAIN> that is smaller"
    " than a <MOUNTAIN>; a hill.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: HILARE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HINDU_TEMPLE,
    "HINDU_TEMPLE", "ECC_HINDU_TEMPLE",
    "A <WORSHIP_PLACE> for Hindu worship; a Hindu temple.",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HISTORICAL_BUILT_UP_REGION,
    "HISTORICAL_BUILT_UP_REGION", "ECC_HISTORICAL_BUILT_UP_REGION",
    "A <TRACT> containing a concentration of historical <STRUCTURE>s within"
    " an enclosing <BUILT_UP_REGION>.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL021]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HOAR_FROST,
    "HOAR_FROST", "ECC_HOAR_FROST",
    "A deposit of <ICE> (hoar crystals) that generally assumes the form of"
    " scales, needles, feathers, or fans and that forms on <OBJECT>s the"
    " <SURFACE>s of which are sufficiently cooled, usually by nocturnal"
    " radiation, to bring about deposition of the water vapour contained in"
    " the ambient <AIR>; hoar frost.",
    3, &(EGBindingForEC[880]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"hoar frost\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HOLDING_PATTERN_REGION,
    "HOLDING_PATTERN_REGION", "ECC_HOLDING_PATTERN_REGION",
    "A delimited <REGION> within which <AIRCRAFT> follow a holding pattern"
    " while awaiting further clearance instructions.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HOP_FIELD,
    "HOP_FIELD", "ECC_HOP_FIELD",
    "A <TRACT> covered by the systematic planting of hop vines; a hop field.",
    4, &(EGBindingForEC[190]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EA055]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HOPPER,
    "HOPPER", "ECC_HOPPER",
    "A top-loaded, funnel-shaped <STRUCTURE> for temporary holding of loose"
    " <MATERIAL> that will be dispensed from its bottom; a hopper.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AF080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HORSE,
    "HORSE", "ECC_HORSE",
    "A solid-hoofed perissodactyl ungulate <MAMMAL> of the family Equidae;"
    " a horse [SOED, \"horse\", 1].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HOSPITAL_BUILDING,
    "HOSPITAL_BUILDING", "ECC_HOSPITAL_BUILDING",
    "A <BUILDING> used to provide inpatient medical, surgical, or"
    " psychiatric care and treatment for the sick or the injured; a"
    " hospital.",
    2, &(EGBindingForEC[984]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HOSTEL,
    "HOSTEL", "ECC_HOSTEL",
    "A <BUILDING> used to provide supervised, inexpensive lodging for"
    " travellers, especially young travellers; a hostel [AHD, \"hostel\","
    " 1].",
    5, &(EGBindingForEC[920]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HOTEL,
    "HOTEL", "ECC_HOTEL",
    "A <BUILDING> used to provide lodging, and usually meals and other"
    " services, for travellers and other paying guests; a hotel [AHD,"
    " \"hotel\"].",
    5, &(EGBindingForEC[920]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HOUSE,
    "HOUSE", "ECC_HOUSE",
    "A <BUILDING> serving as a <DWELLING> for one or more <HUMAN>s,"
    " especially for a family; a house [AHD, \"house, 1.a\"].",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HULK,
    "HULK", "ECC_HULK",
    "A permanently moored <WATER_SURFACE_VESSEL>; a hulk.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: HULKES]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HUMAN,
    "HUMAN", "ECC_HUMAN",
    "A member of the <ANIMAL> species Homo sapiens; a human [SOED,"
    " \"human\", B.1].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HUMMOCK,
    "HUMMOCK", "ECC_HUMMOCK",
    "A <TRACT> of higher <<TERRAIN_ELEVATION>> than the <WETLAND> that"
    " surrounds it; a hummock.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH077]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HURRICANE,
    "HURRICANE", "ECC_HURRICANE",
    "A warm core <TROPICAL_CYCLONE> with a maximum surface <<WIND_SPEED>>"
    " of 33 metres per second or greater in the North Atlantic, the"
    " Caribbean, the Gulf of Mexico, and in the eastern North Pacific; a"
    " hurricane.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"hurricane\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HUT,
    "HUT", "ECC_HUT",
    "A small, simple, or crude <HOUSE> or <SHELTER>; a hut.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HYDROFOIL_VESSEL,
    "HYDROFOIL_VESSEL", "ECC_HYDROFOIL_VESSEL",
    "A <WATER_SURFACE_VESSEL> supported on airfoil-like pontoons where the"
    " bulk of the hull remains above the <WATERBODY_SURFACE> while in"
    " motion; a hydrofoil.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"hydrofoil\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_HYDROGRAPHIC_LOCK,
    "HYDROGRAPHIC_LOCK", "ECC_HYDROGRAPHIC_LOCK",
    "A <LOCK_BASIN> with a pair or series of <LOCK_GATE>s used for raising"
    " or lowering <VESSEL>s as they pass from one level to another; a"
    " hydrographic lock.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BI030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HYDROGRAPHIC_SURVEY_CONTACT,
    "HYDROGRAPHIC_SURVEY_CONTACT", "ECC_HYDROGRAPHIC_SURVEY_CONTACT",
    "An <UNDERWATER_OBJECT> detected during a hydrographic survey; a"
    " hydrographic survey contact.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_HYDROGRAPHY,
    "HYDROGRAPHY", "ECC_HYDROGRAPHY",
    "A <WATERBODY> and its adjoining <SHORE>s; hydrography.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"hydrography\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_HYDROLOGIC_OBJECT,
    "HYDROLOGIC_OBJECT", "ECC_HYDROLOGIC_OBJECT",
    "A planetary <OBJECT> related to <WATER>; a hydrologic object.",
    2, &(EGBindingForEC[865]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"hydrology\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE,
    "ICE", "ECC_ICE",
    "Frozen <WATER>; ice [SOED, \"ice\", 1.a].",
    1, &(EGBindingForEC[23]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_BOOM,
    "ICE_BOOM", "ECC_ICE_BOOM",
    "A floating <BARRIER> constrained by <ANCHOR>s and used to deflect the"
    " path of floating <ICE> in order to prevent the obstruction of"
    " <HYDROGRAPHIC_LOCK>s or <WATER_INTAKE>s or to prevent damage to"
    " <BRIDGE_PIER>s or other <STRUCTURE>s; an ice boom.",
    5, &(EGBindingForEC[706]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB202]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_CLIFF,
    "ICE_CLIFF", "ECC_ICE_CLIFF",
    "A perpendicular or steep face of a <GLACIER> or <ICE_SHELF> of"
    " considerable <<HEIGHT>>; an ice cliff.",
    1, &(EGBindingForEC[23]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BJ040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_FIELD,
    "ICE_FIELD", "ECC_ICE_FIELD",
    "A <FROZEN_PRECIPITATION_FIELD> that consists of <ICE>; an ice-field.",
    2, &(EGBindingForEC[886]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_GLAZE,
    "ICE_GLAZE", "ECC_ICE_GLAZE",
    "A coating of <ICE>, generally clear and smooth, formed on exposed"
    " <OBJECT>s by the freezing of a film of supercooled <WATER> deposited"
    " by <RAIN>, <DRIZZLE>, or <FOG> or possibly condensed from supercooled"
    " water vapour; ice glaze. <ICE_GLAZE> is denser, harder, and more"
    " transparent than either <RIME> or <HOAR_FROST>.",
    2, &(EGBindingForEC[891]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"glaze\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_KEEL,
    "ICE_KEEL", "ECC_ICE_KEEL",
    "An irregular, linear, downward extension of <ICE> formed where two"
    " moving masses of <ICE> collide on a <WATERBODY>; an ice keel.",
    1, &(EGBindingForEC[23]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"ice keel\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_PEAK,
    "ICE_PEAK", "ECC_ICE_PEAK",
    "A rocky peak that may be perpetually covered with <ICE> and that"
    " projects above a surrounding <ICE_FIELD>; a nunatak or ice peak.",
    3, &(EGBindingForEC[888]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BJ060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_PELLETS,
    "ICE_PELLETS", "ECC_ICE_PELLETS",
    "<SOLID_PRECIPITATION> of transparent or translucent <PARTICLE>s of"
    " <ICE> that are spherical or irregular, rarely conical, and that have"
    " an <<OUTSIDE_DIAMETER>> of 5 millimetres or less; ice pellets."
    " <SMALL_HAIL> is a form of ice pellets.",
    3, &(EGBindingForEC[378]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"ice pellets\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_SHELF,
    "ICE_SHELF", "ECC_ICE_SHELF",
    "A thick sheet of <ICE>, mostly afloat on a <WATERBODY_SURFACE>, with a"
    " level or undulating <SURFACE> that is bounded on the seaward side by"
    " an <ICE_CLIFF> and attached to <LAND>; an ice shelf.",
    2, &(EGBindingForEC[893]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BJ065]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICE_SLUDGE,
    "ICE_SLUDGE", "ECC_ICE_SLUDGE",
    "Spongy whitish lumps of <ICE> a few centimetres in"
    " <<OUTSIDE_DIAMETER>> that are floating on the <WATERBODY_SURFACE> of"
    " a shallow <SEA>; ice sludge.",
    2, &(EGBindingForEC[893]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"sludge\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ICEBERG,
    "ICEBERG", "ECC_ICEBERG",
    "A very large mass of <ICE> floating loose in a <WATERBODY> after"
    " becoming detached from a <GLACIER> or <ICE_SHELF>; an iceberg [SOED,"
    " \"iceberg\", 2].",
    2, &(EGBindingForEC[893]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IFR_REGION,
    "IFR_REGION", "ECC_IFR_REGION",
    "A <REGION> in which IFR should be observed.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_INFORMATIVE, "[AIM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ILS_COMPONENT,
    "ILS_COMPONENT", "ECC_ILS_COMPONENT",
    "An air navigation <COMPONENT> that is essential to the establishment"
    " and execution of a precision approach based on an ILS.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA048]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ILS_TERMINAL_COMPONENT,
    "ILS_TERMINAL_COMPONENT", "ECC_ILS_TERMINAL_COMPONENT",
    "An <ATS_ROUTE_COMPONENT> designated for channelling the flow of air"
    " traffic via ILS terminal procedures.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA049]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INCINERATOR,
    "INCINERATOR", "ECC_INCINERATOR",
    "A permanent <STRUCTURE> used for the disposal of waste products by"
    " burning; an incinerator.",
    2, &(EGBindingForEC[994]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AB020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INDIGENOUS_BURIAL_GROUND,
    "INDIGENOUS_BURIAL_GROUND", "ECC_INDIGENOUS_BURIAL_GROUND",
    "A <CEMETERY> for native peoples, generally without"
    " <MEMORIAL_MONUMENT>s; an indigenous burial ground.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"burial ground\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_INDIGENOUS_PEOPLES_RESERVE,
    "INDIGENOUS_PEOPLES_RESERVE", "ECC_INDIGENOUS_PEOPLES_RESERVE",
    "A <TRACT>and associated <STRUCTURE>s set apart specifically for the"
    " use of a native people; an indigenous peoples reserve.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INDIVIDUAL_FIGHTING_POSITION,
    "INDIVIDUAL_FIGHTING_POSITION", "ECC_INDIVIDUAL_FIGHTING_POSITION",
    "A <FIGHTING_POSITION> designed to accommodate an individual soldier"
    " and that soldier's <EQUIPMENT>.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INDUSTRIAL_BUILDING,
    "INDUSTRIAL_BUILDING", "ECC_INDUSTRIAL_BUILDING",
    "A <BUILDING> used for the manufacture of goods or the processing of"
    " <MATERIAL>s; an industrial building.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INDUSTRIAL_OVEN,
    "INDUSTRIAL_OVEN", "ECC_INDUSTRIAL_OVEN",
    "An industrial <STRUCTURE> used for hardening, burning, or heating"
    " <MATERIAL>s (for example: grain, meal, clay, or wood); an industrial"
    " oven.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INDUSTRIAL_WORKS,
    "INDUSTRIAL_WORKS", "ECC_INDUSTRIAL_WORKS",
    "The <STRUCTURE>s, <GROUNDS>, and <EQUIPMENT> of a manufacturing"
    " <FACILITY>; an industrial works.",
    3, &(EGBindingForEC[953]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AC050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INFANTRY_TRENCH,
    "INFANTRY_TRENCH", "ECC_INFANTRY_TRENCH",
    "A <MILITARY_TRENCH>, typically integrated into a complex <SYSTEM> of"
    " <TERRAIN_OBSTACLE>s, that is used to provide cover, concealment,"
    " protected <FIGHTING_POSITION>s, and communications capability for"
    " infantry.",
    2, &(EGBindingForEC[499]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INFRARED_MATERIAL_PROPERTY_SET,
    "INFRARED_MATERIAL_PROPERTY_SET", "ECC_INFRARED_MATERIAL_PROPERTY_SET",
    "A <PROPERTY_SET> describing the infrared properties of the <MATERIAL>s"
    " composing an <OBJECT>.",
    3, &(EGBindingForEC[654]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INLAND_SHORELINE,
    "INLAND_SHORELINE", "ECC_INLAND_SHORELINE",
    "The <SHORELINE> of an inland <WATERBODY>.",
    2, &(EGBindingForEC[550]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH210]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INLAND_WATER,
    "INLAND_WATER", "ECC_INLAND_WATER",
    "A <WATERBODY> that either does not experience or only minimally"
    " experiences tidal fluctuations; inland water.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH000]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INLAND_WATER_BOTTOM,
    "INLAND_WATER_BOTTOM", "ECC_INLAND_WATER_BOTTOM",
    "A bathymetric <REGION> underlying an <INLAND_WATER_SURFACE>; an inland"
    " water bottom.",
    1, &(EGBindingForEC[52]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INLAND_WATER_ELEVATION,
    "INLAND_WATER_ELEVATION", "ECC_INLAND_WATER_ELEVATION",
    "A <LOCATION> associated with an <INLAND_WATER_SURFACE> with an"
    " <<ELEVATION>>.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: CA035]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INLAND_WATER_SURFACE,
    "INLAND_WATER_SURFACE", "ECC_INLAND_WATER_SURFACE",
    "The <WATERBODY_SURFACE> of an <INLAND_WATER>.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INLET,
    "INLET", "ECC_INLET",
    "A short, narrow <WATERCOURSE> connecting a <MARINE_BAY> or <LAGOON>"
    " with a <SEA>; an inlet.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"inlet\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INS_ALIGNMENT_PAD,
    "INS_ALIGNMENT_PAD", "ECC_INS_ALIGNMENT_PAD",
    "A designated <LOCATION> where the automated INS instruments of"
    " <AIRCRAFT> are reset before taking-off; an INS alignment pad.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INSECT,
    "INSECT", "ECC_INSECT",
    "An <ARTHROPOD> of the superclass Hexapoda, characterized by having six"
    " feet; an insect [SOED, \"hexopod\"].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INSTITUTIONAL_FACILITY,
    "INSTITUTIONAL_FACILITY", "ECC_INSTITUTIONAL_FACILITY",
    "A <FACILITY> housing an established organization or foundation,"
    " especially one dedicated to education, public service, or culture,"
    " that provides for the care of <HUMAN>s who are destitute, disabled,"
    " or mentally ill; an institutional facility.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INTEREST_SITE,
    "INTEREST_SITE", "ECC_INTEREST_SITE",
    "A <SITE> maintained for the public and declared to be of national or"
    " provincial historical significance or interest.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL201]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INTERIOR_WALL,
    "INTERIOR_WALL", "ECC_INTERIOR_WALL",
    "A <WALL> in a <BUILDING> separating two <ROOM>s from each other; an"
    " interior wall.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INTERIOR_WALL_OPENING,
    "INTERIOR_WALL_OPENING", "ECC_INTERIOR_WALL_OPENING",
    "An opening (for example: an uncovered <APERTURE> in an <INTERIOR_WALL>"
    " and/or the space above a <WALL> of partial <<HEIGHT>>) that supports"
    " the passage of <MATERIAL>s or visibility into an adjoining <ROOM>.",
    2, &(EGBindingForEC[411]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INTERNATIONAL_DATE_LINE,
    "INTERNATIONAL_DATE_LINE", "ECC_INTERNATIONAL_DATE_LINE",
    "A <LINE> designated as the place on the <EARTH> where each calendar"
    " day begins; the International Date Line. This <LINE> generally"
    " coincides with the 180^(th) meridian but is modified to avoid <LAND>.",
    2, &(EGBindingForEC[557]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA110]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INTERPLANETARY_MAGNETIC_FIELD,
    "INTERPLANETARY_MAGNETIC_FIELD", "ECC_INTERPLANETARY_MAGNETIC_FIELD",
    "The <MAGNETIC_FIELD> in a <SOLAR_SYSTEM> carried with its"
    " <STELLAR_WIND>.",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INUNDATED_LAND,
    "INUNDATED_LAND", "ECC_INUNDATED_LAND",
    "<LAND> subject to controlled inundation (for example: flooded by the"
    " regulation of the level of a <RESERVOIR>) that is normally associated"
    " with permanently flooded ground in which <TREE>s are still standing;"
    " inundated land.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH091]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_INVERTEBRATE,
    "INVERTEBRATE", "ECC_INVERTEBRATE",
    "An <ANIMAL> without a backbone or spinal column that does not belong"
    " to the subphylum Vertebrata; an invertebrate [SOED, \"invertebrate\"].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IONOSPHERE,
    "IONOSPHERE", "ECC_IONOSPHERE",
    "The <ATMOSPHERE_REGION> of the <EARTH> characterized by ions and free"
    " electrons existing in sufficient quantities to reflect"
    " electromagnetic waves and located roughly between the"
    " <<ALTITUDE_MSL>>s of 70 to 500 kilometres; the ionosphere.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"ionosphere\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IONOSPHERE_ELECTRON_DENSITY_PROPERTY_SET,
    "IONOSPHERE_ELECTRON_DENSITY_PROPERTY_SET", "ECC_IONOSPHERE_ELECTRON_DENSITY_PROPERTY_SET",
    "A <PROPERTY_SET> describing the electron-density related"
    " characteristics of an <IONOSPHERE>.",
    3, &(EGBindingForEC[369]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IONOSPHERE_SCINTILLATION_PROPERTY_SET,
    "IONOSPHERE_SCINTILLATION_PROPERTY_SET", "ECC_IONOSPHERE_SCINTILLATION_PROPERTY_SET",
    "A <PROPERTY_SET> describing the distortion of the propagation of"
    " electromagnetic radiation through an <IONOSPHERE> due to medium"
    " density irregularities; an ionosphere scintillation property set.",
    3, &(EGBindingForEC[369]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IONOSPHERIC_D_REGION,
    "IONOSPHERIC_D_REGION", "ECC_IONOSPHERIC_D_REGION",
    "The lowest daytime <REGION> of the <IONOSPHERE> characterized by weak"
    " concentrations of ions and located roughly between the"
    " <<ALTITUDE_MSL>>s of 50 and 90 kilometres; the D-region or D-layer.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IONOSPHERIC_E_REGION,
    "IONOSPHERIC_E_REGION", "ECC_IONOSPHERIC_E_REGION",
    "A daytime <REGION> of the <IONOSPHERE> characterized by concentrations"
    " of O[sub(2)]^(+) and NO^(+) ions and located roughly between the"
    " <<ALTITUDE_MSL>> s of 85 and 140 kilometres; the E-region or E-layer.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IONOSPHERIC_F1_REGION,
    "IONOSPHERIC_F1_REGION", "ECC_IONOSPHERIC_F1_REGION",
    "A daytime <REGION> of the <IONOSPHERE>, above the"
    " <IONOSPHERIC_E_REGION>, characterized by weak concentrations of"
    " O[sub(2)]^(+) ions and located roughly between the <<ALTITUDE_MSL>>s"
    " of 120 and 200 kilometres; the F1-region or F1-layer.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IONOSPHERIC_F2_REGION,
    "IONOSPHERIC_F2_REGION", "ECC_IONOSPHERIC_F2_REGION",
    "A daytime <REGION> of the <IONOSPHERE>, above the"
    " <IONOSPHERIC_E_REGION>, characterized by weak concentrations of"
    " O[sub(2)]^(+) ions and located roughly between the <<ALTITUDE_MSL>>s"
    " of 200 and 1 500 kilometres; the F2-region or F2-layer.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_IRRIGATION_DITCH,
    "IRRIGATION_DITCH", "ECC_IRRIGATION_DITCH",
    "A <TRENCH> that is constructed for the purpose of irrigation or"
    " drainage; an irrigation ditch.",
    2, &(EGBindingForEC[194]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ISLAND,
    "ISLAND", "ECC_ISLAND",
    "A <TRACT> smaller (usually much smaller) than a continent and"
    " surrounded by a <WATERBODY>; an island.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BA030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ISOGONIC_LINE,
    "ISOGONIC_LINE", "ECC_ISOGONIC_LINE",
    "An <ISOPLETH> that connects <LOCATION>s of equal magnetic variation;"
    " an isogonic line.",
    2, &(EGBindingForEC[652]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZC050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ISOPLETH,
    "ISOPLETH", "ECC_ISOPLETH",
    "A <LINE> defined by <LOCATION>s for which some chosen quantity has the"
    " same value; an isopleth [SOED, \"isopleth\", 1].",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ISTHMUS,
    "ISTHMUS", "ECC_ISTHMUS",
    "A <TERRAIN_STRIP> that is bordered on both sides by <WATERBODY>s and"
    " that connects two larger bodies of <LAND>; an isthmus.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"isthmus\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_JAIL,
    "JAIL", "ECC_JAIL",
    "A local <DETENTION_FACILITY> where the criminally accused are"
    " initially taken to be processed and await trial and where short"
    " (usually less than one year) sentences for criminal misconduct can be"
    " served; a jail.",
    2, &(EGBindingForEC[139]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"jail\", A1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_JETTY,
    "JETTY", "ECC_JETTY",
    "A man-made <BARRIER> built out into or in a <WATERBODY>, primarily to"
    " restrain or direct <WATER_CURRENT>s and <WATER_WAVE>s; a jetty.",
    2, &(EGBindingForEC[751]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB140]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_JUNGLE,
    "JUNGLE", "ECC_JUNGLE",
    "A <TRACT>, especially tropical, overgrown with luxuriant and often"
    " almost impenetrable <VEGETATION>; a jungle [SOED, \"jungle\", 1].",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_JUPITER,
    "JUPITER", "ECC_JUPITER",
    "The primary <PLANET> of the <SUN> that is fifth in distance from the"
    " <SUN>, with an orbital mean <<RADIUS>> of approximately 778,30"
    " million kilometres; Jupiter.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_KELP_BED,
    "KELP_BED", "ECC_KELP_BED",
    "A <WATERBODY_FLOOR_REGION> covered with a significant concentration of"
    " kelp; a kelp bed.",
    4, &(EGBindingForEC[1077]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_KENNEL,
    "KENNEL", "ECC_KENNEL",
    "A <STRUCTURE> used for the breeding, training, or boarding of dogs; a"
    " kennel [AHD, \"kennel\", 3].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_KILN,
    "KILN", "ECC_KILN",
    "An oven for hardening, burning, or drying <MATERIAL>s (for example:"
    " grain, meal, and/or clay), especially a brick-lined oven used to bake"
    " or fire ceramics; a kiln [AHD, \"kiln\"].",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_KUIPER_BELT,
    "KUIPER_BELT", "ECC_KUIPER_BELT",
    "The <REGION> of the <SOLAR_SYSTEM> of the <SUN> beyond the orbit of"
    " <NEPTUNE> where a large number of <COMET>s with short orbital periods"
    " originate; the Kuiper belt.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[BSFG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAGOON,
    "LAGOON", "ECC_LAGOON",
    "An enclosed <REGION> of salt or brackish <WATER> separated from a"
    " larger <WATERBODY> by some more or less effective, but not complete,"
    " <BARRIER> (for example: a low bank of <SAND>); a lagoon.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"lagoon\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAKE,
    "LAKE", "ECC_LAKE",
    "<INLAND_WATER> without significant flow that is surrounded by <LAND>;"
    " a lake.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"lake\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAKE_NEXUS,
    "LAKE_NEXUS", "ECC_LAKE_NEXUS",
    "A representation of a <LAKE> as it connects to related <RIVER_NEXUS>s;"
    " a lake centre-line or lake nexus.",
    2, &(EGBindingForEC[860]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAND,
    "LAND", "ECC_LAND",
    "<TERRAIN> that is not permanently covered by <WATER>; land.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DA030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAND_EASEMENT,
    "LAND_EASEMENT", "ECC_LAND_EASEMENT",
    "A deeded <PARCEL> granting easement for a specific purpose (for"
    " example: overhead <POWER_TRANSMISSION_LINE>s and/or access to a"
    " <PARKING_GARAGE>); a land easement.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAND_FISH_HATCHERY,
    "LAND_FISH_HATCHERY", "ECC_LAND_FISH_HATCHERY",
    "A <FISH_HATCHERY> located entirely on <LAND>.",
    4, &(EGBindingForEC[159]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAND_FLOODING_PERIODICALLY,
    "LAND_FLOODING_PERIODICALLY", "ECC_LAND_FLOODING_PERIODICALLY",
    "A <TERRAIN_SURFACE_REGION> periodically covered by floodwater,"
    " excluding tidal <WATER>s; land flooding periodically.",
    2, &(EGBindingForEC[865]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAND_MINEFIELD,
    "LAND_MINEFIELD", "ECC_LAND_MINEFIELD",
    "A <MINEFIELD> on <LAND>.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAND_TRANSPORTATION_ROUTE,
    "LAND_TRANSPORTATION_ROUTE", "ECC_LAND_TRANSPORTATION_ROUTE",
    "A <TRANSPORTATION_ROUTE> located principally on <LAND>.",
    3, &(EGBindingForEC[1012]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAND_WATER_BOUNDARY,
    "LAND_WATER_BOUNDARY", "ECC_LAND_WATER_BOUNDARY",
    "A <BOUNDARY> where <LAND> is in contact with a <WATERBODY>.",
    3, &(EGBindingForEC[526]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BA010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LANDFILL,
    "LANDFILL", "ECC_LANDFILL",
    "A <TRACT> used for solid waste disposal by burying refuse between"
    " layers of <SOIL> to fill in or reclaim low-lying <LAND>; a landfill"
    " [SOED, \"landfill\", b].",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LANDING_CRAFT,
    "LANDING_CRAFT", "ECC_LANDING_CRAFT",
    "A small <WATER_SURFACE_VESSEL> designed to convey <PERSONNEL> and"
    " <EQUIPMENT> from larger <WATER_SURFACE_VESSEL>s to <SHORE> during"
    " landing operations; a landing-craft [SOED, \"landing-craft\"].",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LANDSLIDE,
    "LANDSLIDE", "ECC_LANDSLIDE",
    "A mass of <MATERIAL> (for example: <SOIL>, <ROCK>, and/or"
    " <VEGETATION>) that has slipped down from a <CLIFF> or <MOUNTAIN>; a"
    " landslide.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB211]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LATERAL_BUOYAGE_INDICATION,
    "LATERAL_BUOYAGE_INDICATION", "ECC_LATERAL_BUOYAGE_INDICATION",
    "A <LOCATION> in a <WATERBODY> where a <DIRECTION> away from seaward is"
    " specified that indicates how a lateral buoyage <SYSTEM> should be"
    " interpreted.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC102]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LAUNCH_PAD,
    "LAUNCH_PAD", "ECC_LAUNCH_PAD",
    "A designated <SITE> or <STRUCTURE> from which a rocket or <MISSILE> is"
    " launched; a launch pad.",
    3, &(EGBindingForEC[1123]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LEDGE,
    "LEDGE", "ECC_LEDGE",
    "A narrow, flat <SURFACE> or shelf, especially one that projects (for"
    " example: from a <CLIFF>); a ledge.",
    1, &(EGBindingForEC[44]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BD119]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LEGATION_BUILDING,
    "LEGATION_BUILDING", "ECC_LEGATION_BUILDING",
    "A <BUILDING> in a foreign country that houses a diplomatic mission"
    " that ranks below an embassy; a legation building.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LEVEE,
    "LEVEE", "ECC_LEVEE",
    "An <EMBANKMENT> to prevent the overflow of a <RIVER>; a levee [SOED,"
    " \"levee\", 2.a.1].",
    2, &(EGBindingForEC[739]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LEVEL_CROSSING,
    "LEVEL_CROSSING", "ECC_LEVEL_CROSSING",
    "A <CROSSING> between a <RAILWAY>and either a <ROAD> or another"
    " <RAILWAY> on the same vertical level; a level crossing or on-grade"
    " crossing.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIBRARY,
    "LIBRARY", "ECC_LIBRARY",
    "A <BUILDING> in which literary and artistic materials (for example:"
    " books, periodicals, newspapers, pamphlets, prints, records, and/or"
    " tapes) are kept for reading, reference, and/or lending; a library"
    " [AHD, \"library\", 1.a].",
    3, &(EGBindingForEC[489]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LICHEN,
    "LICHEN", "ECC_LICHEN",
    "A composite <LIVING_ORGANISM> formed by the association of <ALGA> with"
    " <FUNGUS> and occurring as encrusting or branching friable growths on"
    " <SURFACE>s, to which they give a green, grey, or yellow colour; a"
    " lichen [SOED, \"lichen\"].",
    1, &(EGBindingForEC[31]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIFT,
    "LIFT", "ECC_LIFT",
    "<EQUIPMENT> consisting of a platform, which is often enclosed, that is"
    " raised and lowered in a vertical shaft to transport <HUMAN>s,"
    " <EQUIPMENT>, or <MATERIAL>s; a lift or an elevator (US) [AHD,"
    " \"elevator\", 1.a].",
    2, &(EGBindingForEC[616]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIFT_SHAFT,
    "LIFT_SHAFT", "ECC_LIFT_SHAFT",
    "A vertical passageway in a <BUILDING> used for a <LIFT>; a lift shaft.",
    3, &(EGBindingForEC[408]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIGHT,
    "LIGHT", "ECC_LIGHT",
    "An <OBJECT> that is a source of illumination visible to the eye of"
    " <HUMAN>s; a light [SOED, \"light\", 4].",
    2, &(EGBindingForEC[71]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BC040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIGHT_INDUSTRIAL_FACILITY,
    "LIGHT_INDUSTRIAL_FACILITY", "ECC_LIGHT_INDUSTRIAL_FACILITY",
    "A <FACILITY> devoted to the manufacture of goods (for example:"
    " electronic <DEVICE>s and/or computer software) that generally require"
    " only limited <MATERIAL> and energy inputs; a light industrial"
    " facility.",
    2, &(EGBindingForEC[970]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIGHT_SUPPORT_STRUCTURE,
    "LIGHT_SUPPORT_STRUCTURE", "ECC_LIGHT_SUPPORT_STRUCTURE",
    "A <STRUCTURE> serving as a support for one or more <LIGHT>s.",
    2, &(EGBindingForEC[1060]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AL110]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIGHT_WINGED_AIRCRAFT,
    "LIGHT_WINGED_AIRCRAFT", "ECC_LIGHT_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> with a maximum capacity of 10 persons; a light"
    " aircraft.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIGHTHOUSE,
    "LIGHTHOUSE", "ECC_LIGHTHOUSE",
    "A distinctive <STRUCTURE> exhibiting one or more <LIGHT>s designed to"
    " serve as an <AID_TO_NAVIGATION>; a lighthouse.",
    2, &(EGBindingForEC[1062]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIGHTING,
    "LIGHTING", "ECC_LIGHTING",
    "A <NON_EMPTY_SET> of <LIGHT>s providing illumination for a <REGION> or"
    " <OBJECT>; lighting.",
    1, &(EGBindingForEC[29]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BC035]",
    "[SOED, \"lighting\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIGHTNING,
    "LIGHTNING", "ECC_LIGHTNING",
    "A luminous manifestation accompanying a sudden electrical discharge"
    " that takes place from or inside <CLOUD>s or, less often, from tall"
    " <OBJECT>s on the <PLANETARY_SURFACE> and/or from <MOUNTAIN>s to"
    " <CLOUD>s; lightning.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"lightning\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIGHTSHIP,
    "LIGHTSHIP", "ECC_LIGHTSHIP",
    "A distinctively marked, manned <WATER_SURFACE_VESSEL> anchored or"
    " moored at a defined <LOCATION> to serve as a"
    " <MARINE_AID_TO_NAVIGATION>; a lightship.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: LITVES]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LINE,
    "LINE", "ECC_LINE",
    "A curve connecting a <SET> of two or more <LOCATION>s; a line [SOED,"
    " \"line\", n2.III.14.b] or a curve.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIQUID_DIFFUSER,
    "LIQUID_DIFFUSER", "ECC_LIQUID_DIFFUSER",
    "<EQUIPMENT> located at or below water level where liquids (for"
    " example: cooling <WATER>) are spread out; a diffuser.",
    2, &(EGBindingForEC[564]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: DIFFUS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIVESTOCK_PEN,
    "LIVESTOCK_PEN", "ECC_LIVESTOCK_PEN",
    "An enclosed <TERRAIN_SURFACE_REGION> in which livestock are"
    " temporarily kept; a livestock pen, a feedlot or a stockyard.",
    4, &(EGBindingForEC[159]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AJ030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LIVING_ORGANISM,
    "LIVING_ORGANISM", "ECC_LIVING_ORGANISM",
    "A living thing; a living organism or life-form [SOED, \"life-form\"].",
    1, &(EGBindingForEC[31]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOAD_CABLE,
    "LOAD_CABLE", "ECC_LOAD_CABLE",
    "A <NON_EMPTY_SET> of rope, fibre, or heavy gauge steel <WIRE>s formed"
    " into one continuous strand and used for support, lifting, hauling,"
    " and other load-supporting functions; a cable.",
    2, &(EGBindingForEC[1178]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOCAL_PARK,
    "LOCAL_PARK", "ECC_LOCAL_PARK",
    "A <TRACT> that is maintained for recreational and ornamental purposes"
    " and set aside for public use, generally with few or no <BUILDING>s"
    " and located within a <BUILT_UP_REGION>.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK120]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOCALIZED_ATM_SUSPENSION,
    "LOCALIZED_ATM_SUSPENSION", "ECC_LOCALIZED_ATM_SUSPENSION",
    "A localized <CLOUD> or <NON_AQUEOUS_CLOUD>; a localized atmospheric"
    " suspension.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOCATION,
    "LOCATION", "ECC_LOCATION",
    "A spatial location.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOCATION_PROPERTY_SET,
    "LOCATION_PROPERTY_SET", "ECC_LOCATION_PROPERTY_SET",
    "A <PROPERTY_SET> describing the properties of a <LOCATION>.",
    2, &(EGBindingForEC[1097]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOCK_BASIN,
    "LOCK_BASIN", "ECC_LOCK_BASIN",
    "The portion of a <HYDROGRAPHIC_LOCK> bounded by <LOCK_GATE>s at each"
    " end; a lock basin.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BI031]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOCK_GATE,
    "LOCK_GATE", "ECC_LOCK_GATE",
    "A pair of massive, hinged <DOOR>s at the end of a <LOCK_BASIN>; a lock"
    " gate.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"lock gate(s)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOCOMOTIVE_ENGINE,
    "LOCOMOTIVE_ENGINE", "ECC_LOCOMOTIVE_ENGINE",
    "A self-propelled <GROUND_VEHICLE> designed to move <RAIL_WAGON>s on a"
    " <RAILWAY_TRACK>; a locomotive engine [MWCD, \"locomotive\", 1].",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOG,
    "LOG", "ECC_LOG",
    "An unhewn portion of a felled <TREE>; a log [SOED, \"log\", 1.a].",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOG_BOOM,
    "LOG_BOOM", "ECC_LOG_BOOM",
    "A <WATERBODY_BOOM> designed to keep <LOG>s ready for a <SAWMILL> from"
    " floating away; a log boom.",
    4, &(EGBindingForEC[696]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD071]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOG_CRIB,
    "LOG_CRIB", "ECC_LOG_CRIB",
    "A <LOG_OBSTACLE> that is formed in a cribwork and filled with <SOIL>"
    " and <STONE>s.",
    1, &(EGBindingForEC[28]),
    EDCS_REF_TYP_INFORMATIVE, "[F7-7]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOG_OBSTACLE,
    "LOG_OBSTACLE", "ECC_LOG_OBSTACLE",
    "A <TERRAIN_OBSTACLE> constructed primarily of <LOG>s.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOG_RAMP,
    "LOG_RAMP", "ECC_LOG_RAMP",
    "A <RAMP> used to dump <LOG>s into a <WATERBODY> for transport or to"
    " haul <LOG>s out of the <WATERBODY> for processing; a log ramp.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB221]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOGGING_SITE,
    "LOGGING_SITE", "ECC_LOGGING_SITE",
    "A <TRACT> of <VEGETATION> that is being exploited for lumber"
    " resources; a logging site.",
    3, &(EGBindingForEC[1087]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EE010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOW_CLOUD,
    "LOW_CLOUD", "ECC_LOW_CLOUD",
    "A <CLOUD> of the genus stratocumulus or stratus; a low cloud. Also the"
    " base of a <CLOUD> of the genus cumulus; cumulonimbus; or,"
    " occasionally, nimbostratus.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.2.1.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOW_CLOUD_CEILING_REGION,
    "LOW_CLOUD_CEILING_REGION", "ECC_LOW_CLOUD_CEILING_REGION",
    "An <ATMOSPHERE_REGION> in which the <<ATM_CEILING>> due to <CLOUD>s is"
    " less than 152,4 metres (500 feet) above the <PLANETARY_SURFACE>; a"
    " low cloud ceiling region.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_INFORMATIVE, "[AWS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOW_PRESSURE_CENTRE,
    "LOW_PRESSURE_CENTRE", "ECC_LOW_PRESSURE_CENTRE",
    "The <LOCATION> of the centre of an <ATMOSPHERE_REGION> of low"
    " <<ATM_PRESSURE>>.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"pressure center\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOW_VISIBILITY_REGION,
    "LOW_VISIBILITY_REGION", "ECC_LOW_VISIBILITY_REGION",
    "An <ATMOSPHERE_REGION> of reduced visibility near a"
    " <PLANETARY_SURFACE>; a low visibility region.",
    2, &(EGBindingForEC[381]),
    EDCS_REF_TYP_INFORMATIVE, "[AWS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_LOW_WATER_LINE,
    "LOW_WATER_LINE", "ECC_LOW_WATER_LINE",
    "The intersection of the plane of low water with the <SHORE>; the"
    " <LINE> along a <COAST> or <BEACH> to which the <SEA> recedes at low"
    " water; a low water line or drying line.",
    2, &(EGBindingForEC[1064]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"low water line\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETIC_DATA_DEVICE,
    "MAGNETIC_DATA_DEVICE", "ECC_MAGNETIC_DATA_DEVICE",
    "A <DEVICE> used for the collection of <MAGNETIC_FIELD> data.",
    2, &(EGBindingForEC[559]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BK020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETIC_DISTURBANCE,
    "MAGNETIC_DISTURBANCE", "ECC_MAGNETIC_DISTURBANCE",
    "A localized anomaly in the <MAGNETIC_FIELD> of a <PLANET>; a magnetic"
    " disturbance.",
    1, &(EGBindingForEC[16]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: ZC040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETIC_FIELD,
    "MAGNETIC_FIELD", "ECC_MAGNETIC_FIELD",
    "A <REGION> where a field of force produced by a magnetic <OBJECT> or"
    " by a changing <ELECTRICAL_FIELD> is found; a magnetic field [SOED,"
    " \"magnetic field\"].",
    1, &(EGBindingForEC[16]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETIC_FIELD_PROPERTY_SET,
    "MAGNETIC_FIELD_PROPERTY_SET", "ECC_MAGNETIC_FIELD_PROPERTY_SET",
    "A <PROPERTY_SET> describing the properties of a <MAGNETIC_FIELD>.",
    2, &(EGBindingForEC[660]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETIC_FIELD_SURFACE_PROPERTY_SET,
    "MAGNETIC_FIELD_SURFACE_PROPERTY_SET", "ECC_MAGNETIC_FIELD_SURFACE_PROPERTY_SET",
    "A <PROPERTY_SET> describing the properties of a <MAGNETIC_FIELD> near"
    " a <PLANETARY_SURFACE>.",
    2, &(EGBindingForEC[660]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETIC_STATION,
    "MAGNETIC_STATION", "ECC_MAGNETIC_STATION",
    "A <MAGNETIC_DATA_DEVICE> and support <STRUCTURE>s; a magnetic station.",
    2, &(EGBindingForEC[559]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BK020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETOPAUSE,
    "MAGNETOPAUSE", "ECC_MAGNETOPAUSE",
    "The sharp <BOUNDARY> between a <MAGNETOSPHERE> and the <STELLAR_WIND>;"
    " the magnetopause.",
    4, &(EGBindingForEC[354]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"magnetopause\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETOSPHERE,
    "MAGNETOSPHERE", "ECC_MAGNETOSPHERE",
    "The <REGION> of rarefied ionized gases in the <ATMOSPHERE> of a"
    " <PLANET> in which the dynamical motions are strongly influenced or"
    " even dominated by the <MAGNETIC_FIELD> of that <PLANET>; the"
    " magnetosphere.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"magnetosphere\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAGNETOSPHERE_PLASMA,
    "MAGNETOSPHERE_PLASMA", "ECC_MAGNETOSPHERE_PLASMA",
    "A flux of charged <PARTICLE>s within the <MAGNETOSPHERE>; a"
    " magnetosphere plasma.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAIN_TELECOM_EXCHANGE,
    "MAIN_TELECOM_EXCHANGE", "ECC_MAIN_TELECOM_EXCHANGE",
    "A <STRUCTURE> housing a central <SYSTEM> of switches and other"
    " <EQUIPMENT> that establishes connections between individual"
    " telecommunication <DEVICE>s (for example: a telephone); a main"
    " telecom exchange.",
    2, &(EGBindingForEC[487]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAMMAL,
    "MAMMAL", "ECC_MAMMAL",
    "A furred, warm-blooded <VERTEBRATE> of the class Mammalia, the members"
    " of which are characterized by the possession of mammary glands in the"
    " female and a four-chambered heart; a mammal [SOED, \"mammal\"]."
    " EXAMPLES <HUMAN>, <RODENT>, <BAT>, <WHALE>, ungulate, <CARNIVORE>.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAN_MADE_AIR_OBSTRUCTION,
    "MAN_MADE_AIR_OBSTRUCTION", "ECC_MAN_MADE_AIR_OBSTRUCTION",
    "A man-made <STRUCTURE> of sufficient <<HEIGHT_AGL>> to impede or"
    " obstruct flight operations and cause a hazard to air navigation; a"
    " man-made air obstruction.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB221]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAN_MADE_CLEARING,
    "MAN_MADE_CLEARING", "ECC_MAN_MADE_CLEARING",
    "A cleared or ploughed <TERRAIN_STRIP> designed to: provide access for"
    " a <LAND_TRANSPORTATION_ROUTE>, <PIPELINE>, or"
    " <POWER_TRANSMISSION_LINE>; demarcate a <BOUNDARY>; obtain survey"
    " line-of-sight; or provide a <FIREBREAK>; a man-made clearing.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EC040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAN_MADE_OBJECT,
    "MAN_MADE_OBJECT", "ECC_MAN_MADE_OBJECT",
    "An <OBJECT> made by <HUMAN>s; a man-made object.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MANHOLE,
    "MANHOLE", "ECC_MANHOLE",
    "An <APERTURE> in a utility service <OBJECT> (for example: an item of"
    " <EQUIPMENT>, a <FLOOR>, a <ROAD>, the <LAND>, a <SEWER> and/or other"
    " conduit) through which <PERSONNEL> may pass to gain access to certain"
    " <COMPONENT>s; a manhole [SOED, \"manhole\"].",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MANHOLE_COVER,
    "MANHOLE_COVER", "ECC_MANHOLE_COVER",
    "A cover, which is often made of cast iron, that is designed both for"
    " complete removal and to cover a <MANHOLE>.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MANHOLE_RISER,
    "MANHOLE_RISER", "ECC_MANHOLE_RISER",
    "A <STRUCTURE> that elevates a <MANHOLE> above the surrounding"
    " <SURFACE>; a manhole riser.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MANUFACTURING_FACILITY,
    "MANUFACTURING_FACILITY", "ECC_MANUFACTURING_FACILITY",
    "A <FACILITY> including one or more <FACTORY>s; a manufacturing"
    " facility.",
    4, &(EGBindingForEC[949]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAP,
    "MAP", "ECC_MAP",
    "A graphic representation of natural and artificial <OBJECT>s within a"
    " <REGION>; a map.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"map\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAP_BOUNDARY,
    "MAP_BOUNDARY", "ECC_MAP_BOUNDARY",
    "A <BOUNDARY> that encloses all <OBJECT>s depicted on a <MAP>; a map"
    " boundary.",
    3, &(EGBindingForEC[545]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: IA010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAP_EDGE_FRAME,
    "MAP_EDGE_FRAME", "ECC_MAP_EDGE_FRAME",
    "A graphic representation of the edge of a <MAP>; a map frame.",
    2, &(EGBindingForEC[555]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: IE010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAP_LEGEND,
    "MAP_LEGEND", "ECC_MAP_LEGEND",
    "A <NON_EMPTY_SET> of auxiliary information about a <MAP>; a map legend.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: IE040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAP_LIMITS,
    "MAP_LIMITS", "ECC_MAP_LIMITS",
    "The spatial extent of the <REGION> represented by a <MAP>; map limits.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARABOUT,
    "MARABOUT", "ECC_MARABOUT",
    "A <SHRINE> marking the burial place of an Islamic holy man; a marabout"
    " [SOED, \"marabout\", 2].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_AID_TO_NAVIGATION,
    "MARINE_AID_TO_NAVIGATION", "ECC_MARINE_AID_TO_NAVIGATION",
    "An <AID_TO_NAVIGATION> (for example: a <BEACON> and/or a <BUOY>)"
    " intended to support marine operations.",
    4, &(EGBindingForEC[571]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"aid to navigation\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_BAY,
    "MARINE_BAY", "ECC_MARINE_BAY",
    "A <WATERBODY> partially enclosed by <LAND> but with a wide mouth that"
    " affords access to the <SEA>; a marine bay.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"bay\", n3.1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_CHANNEL,
    "MARINE_CHANNEL", "ECC_MARINE_CHANNEL",
    "The part of a <WATERBODY> that is deep enough for navigation through a"
    " <REGION> otherwise not suitable; a marine channel. EXAMPLE The"
    " deepest part of a <RIVER>, <MARINE_BAY>, or <MARINE_STRAIT> through"
    " which the main <WATERBODY_CURRENT> flows.",
    3, &(EGBindingForEC[788]),
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_CLEARING_LINE,
    "MARINE_CLEARING_LINE", "ECC_MARINE_CLEARING_LINE",
    "A straight <LINE> that separates a safe <WATERBODY_REGION> from a"
    " dangerous <REGION> or that passes clear of a marine navigational"
    " danger; a marine clearing line.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"clearing line\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_FOUL_GROUND,
    "MARINE_FOUL_GROUND", "ECC_MARINE_FOUL_GROUND",
    "A comparatively shallow <WATERBODY_REGION> strewn with"
    " <MARINE_OBSTRUCTION>s (for example: boulders, <CORAL>, and/or"
    " <MARINE_WRECK>s), making it unsuitable for anchoring, grounding,"
    " and/or fishing; marine foul ground.",
    3, &(EGBindingForEC[788]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BD050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_GATE,
    "MARINE_GATE", "ECC_MARINE_GATE",
    "A <BARRIER> that may be swung, drawn, or lowered to block an entrance"
    " or <MARINE_ROUTE> on a <WATERBODY>; a marine gate.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI041]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_GRIDIRON,
    "MARINE_GRIDIRON", "ECC_MARINE_GRIDIRON",
    "A flat frame <STRUCTURE>, usually of parallel timber baulks, erected"
    " on the <FORESHORE> so that a <VESSEL> may dry out on it for painting"
    " or repair at low water; a marine gridiron.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB115]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_GULF,
    "MARINE_GULF", "ECC_MARINE_GULF",
    "A large <WATERBODY_REGION> partially enclosed by <LAND>, especially a"
    " long land-locked portion of a <WATERBODY> opening through a"
    " <MARINE_STRAIT>; a marine gulf.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"gulf\", A.I.1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_LEADING_LIGHTS_LINE,
    "MARINE_LEADING_LIGHTS_LINE", "ECC_MARINE_LEADING_LIGHTS_LINE",
    "A <SET> of two or more marine <LIGHT>s that form a"
    " <MARINE_LEADING_LINE> of a course to be followed.",
    3, &(EGBindingForEC[807]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BC030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_LEADING_LINE,
    "MARINE_LEADING_LINE", "ECC_MARINE_LEADING_LINE",
    "A track along which a <VESSEL> can safely travel that passes through"
    " one or more (usually two) clearly defined <OBJECT>s; a marine leading"
    " line.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_LIGHT_LINE,
    "MARINE_LIGHT_LINE", "ECC_MARINE_LIGHT_LINE",
    "A <NON_EMPTY_SET> of marine <LIGHT>s marking limits, the alignment of"
    " a <ELECTRICAL_CABLE>, or alignments for anchoring or serving a"
    " similar purpose but not marking <DIRECTION>; a marine light line.",
    4, &(EGBindingForEC[510]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BC035]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_LIGHT_SECTOR,
    "MARINE_LIGHT_SECTOR", "ECC_MARINE_LIGHT_SECTOR",
    "A sector defined by bearings from seaward within which a <LIGHT> shows"
    " a specified character or colour or is obscured so that it may serve"
    " as a <MARINE_AID_TO_NAVIGATION>; a marine light sector.",
    3, &(EGBindingForEC[807]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_LIMIT_BOUNDARY,
    "MARINE_LIMIT_BOUNDARY", "ECC_MARINE_LIMIT_BOUNDARY",
    "A <BOUNDARY> separating two <MARINE_REGION>s; a marine limit boundary.",
    4, &(EGBindingForEC[514]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FC021]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_LOCK,
    "MARINE_LOCK", "ECC_MARINE_LOCK",
    "A <HYDROGRAPHIC_LOCK> in a <WATERCOURSE>, permitting a <VESSEL> to"
    " pass from one level to another; a marine lock.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"lock\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_MEASURED_DISTANCE_LINE,
    "MARINE_MEASURED_DISTANCE_LINE", "ECC_MARINE_MEASURED_DISTANCE_LINE",
    "A course, the <<LENGTH>> of which has been accurately measured, that"
    " is used in conjunction with ranges ashore by <VESSEL>s to calibrate"
    " logs, engine revolution counters, and other onboard <EQUIPMENT> and"
    " to determine speed; a marine measured distance line.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FC100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_MINEFIELD,
    "MARINE_MINEFIELD", "ECC_MARINE_MINEFIELD",
    "A marine <MINEFIELD>.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_MOLE,
    "MARINE_MOLE", "ECC_MARINE_MOLE",
    "A substantial masonry <STRUCTURE> that often serves as a <BREAKWATER>"
    " on its outer side while it offers <FACILITY>s where <VESSEL>s are"
    " loaded and discharged on its inner side; a marine mole.",
    5, &(EGBindingForEC[664]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB042]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_NAVIGATION_MARKER,
    "MARINE_NAVIGATION_MARKER", "ECC_MARINE_NAVIGATION_MARKER",
    "A coloured (usually white) mark on a vertical <SURFACE> (for example:"
    " a <CLIFF>, a <ROCKY_OUTCROP>, and/or a <WALL>) that is a conspicuous"
    " landmark for marine navigation; a marine navigation marker.",
    3, &(EGBindingForEC[420]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC055]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_OBJECT,
    "MARINE_OBJECT", "ECC_MARINE_OBJECT",
    "An <OBJECT> relating to or characteristic of <VESSEL>s, shipping,"
    " sailors, or navigation on a <WATERBODY>; a marine object [SOED,"
    " \"marine\", B.2].",
    5, &(EGBindingForEC[62]),
    EDCS_REF_TYP_INFORMATIVE, "[DFAD, 750, \"Maritime Features (General)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_OBSTRUCTION,
    "MARINE_OBSTRUCTION", "ECC_MARINE_OBSTRUCTION",
    "A danger to marine navigation, the exact nature of which is not"
    " specified or has not been determined; a marine obstruction.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: OBSTRN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_PETROLEUM_FIELD,
    "MARINE_PETROLEUM_FIELD", "ECC_MARINE_PETROLEUM_FIELD",
    "A <MARINE_REGION> where <PETROLEUM> is pumped or otherwise removed"
    " from the ground; a marine petroleum field.",
    4, &(EGBindingForEC[768]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_PLATFORM,
    "MARINE_PLATFORM", "ECC_MARINE_PLATFORM",
    "A flat <SURFACE> raised above a <WATERBODY> that serves as a working"
    " stage for conducting offshore operations; a marine platform.",
    3, &(EGBindingForEC[693]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: OFSPLF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_POLICE_STATION,
    "MARINE_POLICE_STATION", "ECC_MARINE_POLICE_STATION",
    "A <POLICE_STATION> that serves a <HARBOUR> or coastal <REGION>; a"
    " marine police station.",
    2, &(EGBindingForEC[118]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:78]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_PORT,
    "MARINE_PORT", "ECC_MARINE_PORT",
    "A marine <FACILITY>, usually located in a <HARBOUR>, that provides"
    " terminal and transfer facilities for loading and discharging <CARGO>"
    " and/or passengers; a marine port.",
    4, &(EGBindingForEC[687]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"port\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_RAMP,
    "MARINE_RAMP", "ECC_MARINE_RAMP",
    "A partially submerged <TERRAIN_SURFACE_REGION> with a hard <SURFACE>"
    " on a <SHORE> for launching and retrieving <VESSEL>s; a marine ramp.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB220]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_REGION,
    "MARINE_REGION", "ECC_MARINE_REGION",
    "A marine <REGION> in which certain activities or factors of"
    " significance to navigation and/or operation apply.",
    4, &(EGBindingForEC[791]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FC031]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_ROUTE,
    "MARINE_ROUTE", "ECC_MARINE_ROUTE",
    "A <TRANSPORTATION_ROUTE> on a <WATERBODY> established for the safe"
    " passage of <VESSEL>s; a marine route.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FC165]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_ROUTE_NEXUS,
    "MARINE_ROUTE_NEXUS", "ECC_MARINE_ROUTE_NEXUS",
    "A representation of one or more <MARINE_ROUTE>s; a marine route"
    " centre-line or marine route nexus.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_SIGNAL_STATION,
    "MARINE_SIGNAL_STATION", "ECC_MARINE_SIGNAL_STATION",
    "A station on <SHORE> from which signals are made to <VESSEL>s; a"
    " marine signal station.",
    3, &(EGBindingForEC[480]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: SISTAT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_SOUND,
    "MARINE_SOUND", "ECC_MARINE_SOUND",
    "A long, relatively wide <WATERBODY> that is larger than a"
    " <MARINE_STRAIT> or a <MARINE_CHANNEL> and that connects larger"
    " <WATERBODY>s (for example: <SEA>s and/or <OCEAN>s); a marine sound"
    " [AHD, \"sound\", 3.1.a].",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_STRAIT,
    "MARINE_STRAIT", "ECC_MARINE_STRAIT",
    "A narrow channel joining two <WATERBODY>s; a marine strait [SOED,"
    " \"strait\", 3].",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARINE_WRECK,
    "MARINE_WRECK", "ECC_MARINE_WRECK",
    "The ruined remains of a stranded or sunken <VESSEL> that has been"
    " rendered useless; a marine wreck.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"wreck\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARKER,
    "MARKER", "ECC_MARKER",
    "An <OBJECT> (for example: a <BOUNDARY_MONUMENT> and/or a"
    " <MEMORIAL_MONUMENT>) marking a <LOCATION> of special interest; a"
    " marker [SOED, \"marker\", 3.b].",
    2, &(EGBindingForEC[73]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BC055]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARKET,
    "MARKET", "ECC_MARKET",
    "An open space or <STRUCTURE> where goods are offered for sale; a"
    " market [SOED, \"market\", 2].",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARKET_PLACE,
    "MARKET_PLACE", "ECC_MARKET_PLACE",
    "A <MARKET> where goods are offered for sale by several vendors; a"
    " market-place [SOED, \"market-place\", a].",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARS,
    "MARS", "ECC_MARS",
    "The primary <PLANET> of the <SUN> that is fourth in distance from the"
    " <SUN> with an orbital mean <<RADIUS>> of approximately 227,94 million"
    " kilometres; Mars.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARSH,
    "MARSH", "ECC_MARSH",
    "A soft, wet, low-lying <WETLAND> that is characterized by grassy"
    " <VEGETATION> and that often forms a transition <REGION> between a"
    " <WATERBODY> and <LAND>; a marsh [AHD, \"marsh\"].",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH095]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MARTELLO_TOWER,
    "MARTELLO_TOWER", "ECC_MARTELLO_TOWER",
    "A stone <TOWER> defending a <COAST> or <HARBOUR> and usually including"
    " a gun platform, ammunition magazine, and accommodations for a"
    " garrison; a Martello tower.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"Martello tower\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_MAST,
    "MAST", "ECC_MAST",
    "A straight piece of timber or a hollow cylinder of wood or metal set"
    " up vertically, or nearly so; a mast.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: MSTCON]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MATERIAL,
    "MATERIAL", "ECC_MATERIAL",
    "The matter of which an <OBJECT> is or may be made; material [SOED,"
    " \"material\", b.1].",
    2, &(EGBindingForEC[75]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MATERIAL_PROPERTY_SET,
    "MATERIAL_PROPERTY_SET", "ECC_MATERIAL_PROPERTY_SET",
    "A <PROPERTY_SET> describing the <MATERIAL>s composing an <OBJECT>.",
    2, &(EGBindingForEC[1112]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MEDICAL_FACILITY,
    "MEDICAL_FACILITY", "ECC_MEDICAL_FACILITY",
    "A <FACILITY> devoted to medical research and/or the practice of"
    " medicine.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MEMORIAL_MONUMENT,
    "MEMORIAL_MONUMENT", "ECC_MEMORIAL_MONUMENT",
    "A <MARKER> erected and/or maintained as a memorial to a person and/or"
    " event; a memorial monument.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: MONUMT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MERCHANT_MARINE_VESSEL,
    "MERCHANT_MARINE_VESSEL", "ECC_MERCHANT_MARINE_VESSEL",
    "A <WATER_SURFACE_VESSEL> designed or designated for use in commerce; a"
    " merchant marine vessel.",
    5, &(EGBindingForEC[763]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MERCURY,
    "MERCURY", "ECC_MERCURY",
    "The primary <PLANET> of the <SUN> that is closest to the <SUN>, with"
    " an orbital mean <<RADIUS>> of approximately 57,91 million kilometres;"
    " Mercury.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESA,
    "MESA", "ECC_MESA",
    "A flat-topped <HILL> or tableland that is larger than a <BUTTE> and"
    " rises steeply from a surrounding <TERRAIN_PLAIN>; a mesa.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"mesa\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH,
    "MESH", "ECC_MESH",
    "An abstract <OBJECT> consisting of three related <NON_EMPTY_SET>s: a"
    " <MESH_NODE_SET>, a <MESH_EDGE_SET>, and a <MESH_FACE_SET>; a mesh.",
    2, &(EGBindingForEC[58]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH_EDGE_PROPERTY_SET,
    "MESH_EDGE_PROPERTY_SET", "ECC_MESH_EDGE_PROPERTY_SET",
    "A <PROPERTY_SET> describing the edges comprising a <MESH>.",
    2, &(EGBindingForEC[293]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH_EDGE_SET,
    "MESH_EDGE_SET", "ECC_MESH_EDGE_SET",
    "The <NON_EMPTY_SET> of edges comprising a <MESH>. Each edge in the"
    " <NON_EMPTY_SET> connects two nodes in the related <MESH_NODE_SET>.",
    1, &(EGBindingForEC[6]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH_FACE_PROPERTY_SET,
    "MESH_FACE_PROPERTY_SET", "ECC_MESH_FACE_PROPERTY_SET",
    "A <PROPERTY_SET> describing the faces comprising a <MESH>.",
    2, &(EGBindingForEC[293]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH_FACE_SET,
    "MESH_FACE_SET", "ECC_MESH_FACE_SET",
    "The <NON_EMPTY_SET> of polygonal faces comprising a <MESH>. The edges"
    " bounding each face in the <NON_EMPTY_SET> are members of the related"
    " <MESH_EDGE_SET>.",
    1, &(EGBindingForEC[6]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH_NODE_PROPERTY_SET,
    "MESH_NODE_PROPERTY_SET", "ECC_MESH_NODE_PROPERTY_SET",
    "A <PROPERTY_SET> describing the nodes comprising a <MESH>.",
    2, &(EGBindingForEC[293]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH_NODE_SET,
    "MESH_NODE_SET", "ECC_MESH_NODE_SET",
    "The <NON_EMPTY_SET> of nodes comprising a <MESH>.",
    1, &(EGBindingForEC[6]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH_SOLID_PROPERTY_SET,
    "MESH_SOLID_PROPERTY_SET", "ECC_MESH_SOLID_PROPERTY_SET",
    "A <PROPERTY_SET> describing the solids comprising a <SOLID_MESH>.",
    2, &(EGBindingForEC[293]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MESH_SOLID_SET,
    "MESH_SOLID_SET", "ECC_MESH_SOLID_SET",
    "The <NON_EMPTY_SET> of polyhedral solids comprising a <SOLID_MESH>."
    " The faces bounding each solid in the <NON_EMPTY_SET> are members of"
    " the related <MESH_FACE_SET>.",
    1, &(EGBindingForEC[6]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MEZZANINE,
    "MEZZANINE", "ECC_MEZZANINE",
    "A low <FLOOR_LEVEL> between two others, especially a low <FLOOR_LEVEL>"
    " between the ground <FLOOR_LEVEL> and the <FLOOR_LEVEL> above or,"
    " occasionally, between the ground <FLOOR_LEVEL> and the <BASEMENT>; a"
    " mezzanine [SOED, \"mezzanine\", A.1].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MIDDLE_CLOUD,
    "MIDDLE_CLOUD", "ECC_MIDDLE_CLOUD",
    "A <CLOUD> of the genus altocumulus, altostratus, or nimbostratus; a"
    " middle cloud. Also portions of a <CLOUD> of the genus cumulus or"
    " cumulonimbus.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.2.1.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MILITARY_FACILITY,
    "MILITARY_FACILITY", "ECC_MILITARY_FACILITY",
    "A military <FACILITY>.",
    2, &(EGBindingForEC[1129]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MILITARY_INSTALLATION,
    "MILITARY_INSTALLATION", "ECC_MILITARY_INSTALLATION",
    "A <TRACT> that is protected by <FORTIFICATION>s or natural advantages"
    " and from which military operations are performed, forward movements"
    " are made, or supplies are furnished; a military installation.",
    2, &(EGBindingForEC[1129]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: SU001]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MILITARY_OPERATIONS_BUILDING,
    "MILITARY_OPERATIONS_BUILDING", "ECC_MILITARY_OPERATIONS_BUILDING",
    "A <BUILDING> devoted to the act or process of managing military forces"
    " or overseeing the conduct of military operations; a military"
    " operations building.",
    3, &(EGBindingForEC[125]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MILITARY_PERSONNEL,
    "MILITARY_PERSONNEL", "ECC_MILITARY_PERSONNEL",
    "<PERSONNEL> who are members of an armed force; military personnel.",
    3, &(EGBindingForEC[333]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MILITARY_TRENCH,
    "MILITARY_TRENCH", "ECC_MILITARY_TRENCH",
    "A <TRENCH> dug for military purposes.",
    2, &(EGBindingForEC[1117]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AH020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MINARET,
    "MINARET", "ECC_MINARET",
    "A tall, slender <TOWER> or turret connected with a <MOSQUE> and"
    " surrounded by one or more projecting <BALCONY>s from which a muezzin"
    " calls at hours of prayer; a minaret [SOED, \"minaret\"].",
    2, &(EGBindingForEC[416]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MINE_COUNTERMEASURE_VESSEL,
    "MINE_COUNTERMEASURE_VESSEL", "ECC_MINE_COUNTERMEASURE_VESSEL",
    "Designed to employ <EXPLOSIVE_NAVAL_MINE>s in warfare or"
    " countermeasures against <EXPLOSIVE_NAVAL_MINE>s while operating in"
    " coastal <WATERBODY_SURFACE_REGION>s; mine countermeasure. Such a"
    " <COMBATANT_VESSEL> is also designed to be carried aboard larger"
    " <VESSEL>s.",
    1, &(EGBindingForEC[51]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MINEFIELD,
    "MINEFIELD", "ECC_MINEFIELD",
    "A <REGION> throughout which <EXPLOSIVE_MINE>s have been laid; a"
    " minefield.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"minefield\", a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_MINERAL_PILE,
    "MINERAL_PILE", "ECC_MINERAL_PILE",
    "A man-made heap of mining or quarrying products that does not contain"
    " waste <MATERIAL>s; a mineral pile.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AM040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MISSILE,
    "MISSILE", "ECC_MISSILE",
    "A destructive projectile that during part or all of its course is"
    " self-propelling and directed by remote control or automatically; a"
    " missile [SOED, \"guided missile\"].",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MISSILE_SITE,
    "MISSILE_SITE", "ECC_MISSILE_SITE",
    "A <SITE> and related <FACILITY>s for storing and launching <MISSILE>s;"
    " a missile site.",
    2, &(EGBindingForEC[1129]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL120]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MISSION,
    "MISSION", "ECC_MISSION",
    "A religious centre established in a <REGION> for missionary,"
    " evangelical, or humanitarian work; a mission [SOED, \"mission\", 4.b].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MIXED_URBAN_REGION,
    "MIXED_URBAN_REGION", "ECC_MIXED_URBAN_REGION",
    "A <TERRAIN_SURFACE_REGION> containing <STRUCTURE>s in combination with"
    " undeveloped and/or agricultural <TRACT>s; a mixed urban region.",
    1, &(EGBindingForEC[3]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MIXED_VEGETATION_LAND,
    "MIXED_VEGETATION_LAND", "ECC_MIXED_VEGETATION_LAND",
    "A <TRACT> covered by a mixture of woody and non-woody <PLANT>s; a"
    " mixed vegetation land.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EE000]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOAT,
    "MOAT", "ECC_MOAT",
    "A <TRENCH>, which is usually filled with <WATER>, that surrounds a"
    " <TRACT> and serves as a <BARRIER>; a moat.",
    1, &(EGBindingForEC[13]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOBILE_BRIDGE_SYSTEM,
    "MOBILE_BRIDGE_SYSTEM", "ECC_MOBILE_BRIDGE_SYSTEM",
    "A <SYSTEM> that is transported on a <VEHICLE> and used to erect"
    " semi-permanent <BRIDGE>s; a mobile bridge system.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOBILE_HOME,
    "MOBILE_HOME", "ECC_MOBILE_HOME",
    "A trailer that is used as a <DWELLING>, has no permanent foundation,"
    " and is designed to be easily moved; a mobile home [MWCD, \"mobile"
    " home\"].",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AI020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOBILE_HOME_PARK,
    "MOBILE_HOME_PARK", "ECC_MOBILE_HOME_PARK",
    "A <SITE> for the long-term parking of <MOBILE_HOME>s; a mobile home"
    " park.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AI020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOLLUSC,
    "MOLLUSC", "ECC_MOLLUSC",
    "An <INVERTEBRATE> of the phylum Mollusca, the members of which have a"
    " soft body and usually a hard shell; a mollusc [SOED,\"mollusc\"]."
    " EXAMPLES Limpet, snail, cuttlefish, oyster, mussel.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MONASTERY,
    "MONASTERY", "ECC_MONASTERY",
    "A <RELIGIOUS_COMMUNITY> of men; a monastery [SOED, \"monastery\"].",
    2, &(EGBindingForEC[1158]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MONERAN,
    "MONERAN", "ECC_MONERAN",
    "A <LIVING_ORGANISM> of the kingdom Monera, which comprises all"
    " prokaryotic single-celled organisms; a moneran [SOED, \"monera\"]."
    " EXAMPLES Bacterium, cyanophyte.",
    1, &(EGBindingForEC[31]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOON,
    "MOON", "ECC_MOON",
    "The only <SATELLITE> of <EARTH>, with an orbital semi-major <<RADIUS>>"
    " of approximately 384 400 kilometres; the Moon.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOORING_DOLPHIN,
    "MOORING_DOLPHIN", "ECC_MOORING_DOLPHIN",
    "One or more <STRUCTURAL_PILE>s used in a <MOORING_FACILITY> or as a"
    " <MARINE_AID_TO_NAVIGATION>; a mooring dolphin.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOORING_FACILITY,
    "MOORING_FACILITY", "ECC_MOORING_FACILITY",
    "A <FACILITY> used for mooring and/or warping a <VESSEL>.",
    2, &(EGBindingForEC[673]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: MORFAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOORING_LINE,
    "MOORING_LINE", "ECC_MOORING_LINE",
    "A <LOAD_CABLE> used for mooring; a mooring line.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOORING_MAST,
    "MOORING_MAST", "ECC_MOORING_MAST",
    "A <MAST> used to secure an <AIRSHIP>; a mooring mast.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ110]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOORING_RING,
    "MOORING_RING", "ECC_MOORING_RING",
    "A metal ring attached to a <STRUCTURE> and used to secure a <VESSEL>;"
    " a mooring ring.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB160]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOORING_TROT,
    "MOORING_TROT", "ECC_MOORING_TROT",
    "An <ANCHOR> and a related <NAVIGATION_MARK_AFLOAT>; a mooring trot.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB021]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MORAINE,
    "MORAINE", "ECC_MORAINE",
    "An accumulation of debris consisting of <SOIL> and <ROCK> that has"
    " been deposited by a <GLACIER>; a moraine.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BJ020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MORMON_TEMPLE,
    "MORMON_TEMPLE", "ECC_MORMON_TEMPLE",
    "A <WORSHIP_PLACE> where sacred Mormon ordinances are administered; a"
    " Mormon temple [SOED, \"temple\", A.I.4].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MORTAR,
    "MORTAR", "ECC_MORTAR",
    "A muzzle loading cannon for firing shells at low velocities, short"
    " ranges, and high trajectories; a mortar [AHD, \"mortar\", 3.a].",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOSQUE,
    "MOSQUE", "ECC_MOSQUE",
    "An Islamic <WORSHIP_PLACE>; a mosque or masjid.",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE, \"mosque\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOSS,
    "MOSS", "ECC_MOSS",
    "A <PLANT> of the class Musci, comprising small bryophtes with"
    " scale-like leaves usually spirally arranged, with a spore-capsule"
    " usually opening by a lid, which grow in crowded masses in <BOG>s or"
    " on <SURFACE>s; or any of certain <ALGA>s, <LICHEN>s, <PTERIDOPHYTE>s,"
    " or flowering <PLANT>s resembling moss in habit; moss [SOED, \"moss\","
    " II 3] or a moss-like plant.",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOTEL,
    "MOTEL", "ECC_MOTEL",
    "A <BUILDING> used to provide lodging for motorists in <ROOM>s usually"
    " having direct access to an open <VEHICLE_LOT>; a motel [AHD,"
    " \"motel\"], motor court, or motor lodge.",
    5, &(EGBindingForEC[920]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOTOR_VEHICLE,
    "MOTOR_VEHICLE", "ECC_MOTOR_VEHICLE",
    "A <GROUND_VEHICLE> powered by a motor and operating principally on"
    " <LAND>; a motor vehicle.",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOTOR_VEHICLE_STATION,
    "MOTOR_VEHICLE_STATION", "ECC_MOTOR_VEHICLE_STATION",
    "A <STRUCTURE> at, or in which, <MOTOR_VEHICLE>s are refuelled,"
    " serviced, and sometimes repaired; a filling station.",
    5, &(EGBindingForEC[936]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOUNTAIN,
    "MOUNTAIN", "ECC_MOUNTAIN",
    "A natural elevation of <TERRAIN> of an altitude that is impressive or"
    " notable relative to adjacent elevations; a mountain.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"mountain\", 1.a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOUNTAIN_PASS,
    "MOUNTAIN_PASS", "ECC_MOUNTAIN_PASS",
    "A <LAND_TRANSPORTATION_ROUTE> through a localized"
    " <TERRAIN_SURFACE_REGION> in a range of <MOUNTAIN>s, where the"
    " <TERRAIN_SURFACE_REGION> is lower in <<TERRAIN_ELEVATION>> than the"
    " adjacent <MOUNTAIN>s; a mountain pass.",
    3, &(EGBindingForEC[1035]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB150]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MOUNTAINOUS_REGION,
    "MOUNTAINOUS_REGION", "ECC_MOUNTAINOUS_REGION",
    "A <TERRAIN_SURFACE_REGION>, the physiography of which consists"
    " predominantly of <MOUNTAIN>s; a mountainous region.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MUD_LINE,
    "MUD_LINE", "ECC_MUD_LINE",
    "A <BOUNDARY> of a <TERRAIN_SURFACE_REGION> of mud that adjoins a"
    " <WATERBODY> and is covered and uncovered depending on the"
    " <<ELEVATION>> of the <TERRAIN> and the current <<ELEVATION>> of the"
    " <WATERBODY_SURFACE>; a mud line.",
    3, &(EGBindingForEC[526]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BE023]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MULTI_UNIT_DWELLING,
    "MULTI_UNIT_DWELLING", "ECC_MULTI_UNIT_DWELLING",
    "A <BUILDING> used as a <DWELLING> by multiple groups of occupants; a"
    " multi-unit dwelling.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:17]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MULTIDOMAIN_VEHICLE,
    "MULTIDOMAIN_VEHICLE", "ECC_MULTIDOMAIN_VEHICLE",
    "A <VEHICLE> capable of operation in more than one environmental"
    " domain; a multidomain vehicle.",
    2, &(EGBindingForEC[1186]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MUNICIPAL_HALL,
    "MUNICIPAL_HALL", "ECC_MUNICIPAL_HALL",
    "A <BUILDING> that contains the offices of the public officials of a"
    " local political unit; a municipal hall.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MUNICIPAL_UTILITY_FACILITY,
    "MUNICIPAL_UTILITY_FACILITY", "ECC_MUNICIPAL_UTILITY_FACILITY",
    "A <FACILITY> devoted to the provision of utility services (for"
    " example: electricity, telecommunications, gas, <WATER>, sewage, trash"
    " collection, and/or trash disposal) to the residents of a locally"
    " governed <REGION> or municipality.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MUNITION,
    "MUNITION", "ECC_MUNITION",
    "A <DEVICE> charged with: explosives; propellant; pyrotechnics;"
    " initiating composition; or nuclear, chemical, or biological"
    " <MATERIAL> for use in military operations (for example: demolitions);"
    " a munition.",
    2, &(EGBindingForEC[612]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"munition\", 3]", EDCS_CONCEPT_STAT_ISO },

    {ECC_MUSEUM_BUILDING,
    "MUSEUM_BUILDING", "ECC_MUSEUM_BUILDING",
    "A <BUILDING> devoted to the acquisition, conservation, study,"
    " exhibition, and educational interpretation of <OBJECT>s having"
    " scientific, historical, or artistic value; a museum [AHD, \"museum\"].",
    2, &(EGBindingForEC[1149]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MUSEUM_FACILITY,
    "MUSEUM_FACILITY", "ECC_MUSEUM_FACILITY",
    "A <FACILITY> including one or more <MUSEUM_BUILDING>s.",
    3, &(EGBindingForEC[1151]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_MUSHROOM,
    "MUSHROOM", "ECC_MUSHROOM",
    "A <FUNGUS> of phylum Basidiomycota, the members of which have a"
    " fleshy, fruiting body, usually rounded or caplike, on a stalk growing"
    " from the ground; a mushroom [SOED, \"mushroom\"].",
    1, &(EGBindingForEC[31]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAMED_LAND_TRACT,
    "NAMED_LAND_TRACT", "ECC_NAMED_LAND_TRACT",
    "A <TRACT> of natural scenery, defined by its geographical"
    " characteristics and known by its proper name.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: LNDRGN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAMED_MAP_LOCATION,
    "NAMED_MAP_LOCATION", "ECC_NAMED_MAP_LOCATION",
    "A <LOCATION> that normally does not appear as a specific,"
    " characterized <OBJECT> on a <MAP> but has a name that is required to"
    " be placed on the <MAP>.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: ZD040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NATIONAL_PARK,
    "NATIONAL_PARK", "ECC_NATIONAL_PARK",
    "An extensive <REGION> of a particular nature that has been defined by"
    " law and is to be protected as a whole; it meets the prerequisites of"
    " a <NATURE_RESERVE> for the largest part and has been influenced by"
    " <HUMAN>s at most only to a small extent; a national park.",
    6, &(EGBindingForEC[336]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NATURAL_AIR_OBSTRUCTION,
    "NATURAL_AIR_OBSTRUCTION", "ECC_NATURAL_AIR_OBSTRUCTION",
    "An existing <OBJECT> of fixed <<HEIGHT_AGL>> or natural growth at a"
    " fixed <LOCATION> within a proscribed <REGION> (for example: adjacent"
    " to an <AERODROME>) with reference to which vertical clearance is or"
    " must be provided during flight operations; a natural air obstruction.",
    3, &(EGBindingForEC[55]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB220]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NATURAL_GAS_RIG,
    "NATURAL_GAS_RIG", "ECC_NATURAL_GAS_RIG",
    "A <RIG> for the collection of natural gas from a <WELL>; a natural gas"
    " rig.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NATURE_RESERVE,
    "NATURE_RESERVE", "ECC_NATURE_RESERVE",
    "A <REGION> that has been legally defined and the nature and landscape"
    " of which require special protection, be it in part or as a whole, in"
    " order to preserve symbioses or biotypes of specific wildlife"
    " <NON_HUMAN_ANIMAL>s or <PLANT>s: for scientific reasons; for reasons"
    " of natural or geographic history; or because of their rareness,"
    " uniqueness, or outstanding beauty; a nature reserve.",
    6, &(EGBindingForEC[336]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA081]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAUTICAL_CLUB,
    "NAUTICAL_CLUB", "ECC_NAUTICAL_CLUB",
    "The <BUILDING>s, <GROUNDS>, and <DOCK>s of an organization that"
    " promotes and supports yachting, sailing, and boating; a nautical"
    " club, yacht club, or sailing club.",
    5, &(EGBindingForEC[826]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:55]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGABLE_WATERWAY,
    "NAVIGABLE_WATERWAY", "ECC_NAVIGABLE_WATERWAY",
    "A <WATERCOURSE> that is usable, sometimes after improvements, as a"
    " commercial <MARINE_ROUTE>; a navigable waterway.",
    6, &(EGBindingForEC[753]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"navigable waters\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGATION_BUOY,
    "NAVIGATION_BUOY", "ECC_NAVIGATION_BUOY",
    "A <BUOY> serving as a <MARINE_AID_TO_NAVIGATION>; a navigation buoy.",
    3, &(EGBindingForEC[841]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGATION_DEVICE,
    "NAVIGATION_DEVICE", "ECC_NAVIGATION_DEVICE",
    "Any visual or electronic <DEVICE>, usually located within a <VEHICLE>,"
    " that provides point-to-point guidance information or <LOCATION> data;"
    " a navigation device or navigation aid.",
    3, &(EGBindingForEC[609]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GA035]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGATION_LIGHT,
    "NAVIGATION_LIGHT", "ECC_NAVIGATION_LIGHT",
    "A specially constructed <DEVICE> that displays a <LIGHT> as an"
    " <AID_TO_NAVIGATION>; a navigation light.",
    3, &(EGBindingForEC[606]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGATION_LINE,
    "NAVIGATION_LINE", "ECC_NAVIGATION_LINE",
    "A <LINE> between two <AID_TO_NAVIGATION>s that extends towards the"
    " <REGION> of navigational interest; a navigation line.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC031]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGATION_MARK_AFLOAT,
    "NAVIGATION_MARK_AFLOAT", "ECC_NAVIGATION_MARK_AFLOAT",
    "A floating <STRUCTURE> providing a reference <LOCATION> for"
    " navigation; an afloat navigation mark.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BC098]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGATION_MARK_FIXED,
    "NAVIGATION_MARK_FIXED", "ECC_NAVIGATION_MARK_FIXED",
    "A fixed <STRUCTURE> providing a reference <LOCATION> for navigation; a"
    " fixed navigation mark.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BC099]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGATION_RADAR_RANGE,
    "NAVIGATION_RADAR_RANGE", "ECC_NAVIGATION_RADAR_RANGE",
    "A <WATERBODY_REGION> within range of a <RADAR_STATION>; inside this"
    " <REGION> a <VESSEL> may request navigation radar assistance from"
    " <SHORE>, particularly in poor visibility.",
    4, &(EGBindingForEC[451]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: RADRNG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NAVIGATION_RESTRICTED_REGION,
    "NAVIGATION_RESTRICTED_REGION", "ECC_NAVIGATION_RESTRICTED_REGION",
    "A <REGION> in which certain aspects of navigation are restricted.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: RESARE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NEAP_TIDE,
    "NEAP_TIDE", "ECC_NEAP_TIDE",
    "The <TIDE>s of decreased range occurring near the times of the first"
    " and last quarter <<MOON_PHASE>>s.",
    2, &(EGBindingForEC[1072]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"tide(s): neap\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NEARSHORE_PRECISE,
    "NEARSHORE_PRECISE", "ECC_NEARSHORE_PRECISE",
    "The <TERRAIN_STRIP> that is located between the 10 metre <DEPTH_CURVE>"
    " and the <LOW_WATER_LINE> defined by either mean low water springs or"
    " mean lower low water as defined by the applicable National Authority;"
    " nearshore precise.",
    2, &(EGBindingForEC[1066]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BA021]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NEBULA,
    "NEBULA", "ECC_NEBULA",
    "An immense body of highly rarefied gas and dust in the interstellar"
    " spaces of <GALAXY>s; a nebula.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"nebula\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_NEPTUNE,
    "NEPTUNE", "ECC_NEPTUNE",
    "The primary <PLANET> of the <SUN> that is normally eighth in distance"
    " from the <SUN>, with an orbital mean <<RADIUS>> of approximately 4"
    " 504,4 million kilometres; Neptune.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NETWORK,
    "NETWORK", "ECC_NETWORK",
    "A <SYSTEM> of inter-connected <OBJECT>s of either the same type or"
    " directly related types; a network.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZD001]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NEWSPAPER_PLANT,
    "NEWSPAPER_PLANT", "ECC_NEWSPAPER_PLANT",
    "A <BUILDING> used in the printing, collating, storage, or distribution"
    " of a newspaper; a newspaper plant.",
    4, &(EGBindingForEC[483]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:85]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NON_AQUEOUS_CLOUD,
    "NON_AQUEOUS_CLOUD", "ECC_NON_AQUEOUS_CLOUD",
    "An <AEROSOL> of non-aqueous <PARTICLE>s (for example: <SMOKE> and/or"
    " <DUST>); a non-aqueous cloud.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"cloud\", 4]", EDCS_CONCEPT_STAT_ISO },

    {ECC_NON_COMMUNICATION_TOWER,
    "NON_COMMUNICATION_TOWER", "ECC_NON_COMMUNICATION_TOWER",
    "A <TOWER> that is used for non-communication purposes (for example:"
    " observation, support, and/or storage).",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL240]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NON_EMPTY_SET,
    "NON_EMPTY_SET", "ECC_NON_EMPTY_SET",
    "A <SET> with at least one member; a non-empty set.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NON_HUMAN_ANIMAL,
    "NON_HUMAN_ANIMAL", "ECC_NON_HUMAN_ANIMAL",
    "An <ANIMAL> other than a <HUMAN> [SOED, \"animal\", A.a].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NON_SUBMARINE_CONTACT,
    "NON_SUBMARINE_CONTACT", "ECC_NON_SUBMARINE_CONTACT",
    "Any <OBJECT> (for example: a <MARINE_WRECK>) on a <WATERBODY_FLOOR>"
    " that could be mistakenly identified as an operable"
    " <SUBMERSIBLE_VESSEL> when detected with acoustic or magnetic sensors;"
    " a non-submarine contact.",
    2, &(EGBindingForEC[749]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PEV, RAG, WDT, WKT, WRN, and WSR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NUCLEAR_REACTOR,
    "NUCLEAR_REACTOR", "ECC_NUCLEAR_REACTOR",
    "<EQUIPMENT>, which may be contained within a <POWER_PLANT> or"
    " <VESSEL>, in which a nuclear chain reaction is initiated, sustained,"
    " and controlled; a nuclear reactor.",
    2, &(EGBindingForEC[597]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AD040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_NUCLEAR_WEAPONS_FACILITY,
    "NUCLEAR_WEAPONS_FACILITY", "ECC_NUCLEAR_WEAPONS_FACILITY",
    "A <FACILITY> used for the construction, assembly, storage, or"
    " dismantling of nuclear <WEAPON>s.",
    3, &(EGBindingForEC[956]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OASIS,
    "OASIS", "ECC_OASIS",
    "A small, isolated, fertile, or green <TRACT> in a <DESERT_REGION>"
    " usually having a <WATERING_PLACE>; an oasis.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EC020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OBJECT,
    "OBJECT", "ECC_OBJECT",
    "A person, place, thing, or concept; an object.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OBJECT_PROPERTY_SET,
    "OBJECT_PROPERTY_SET", "ECC_OBJECT_PROPERTY_SET",
    "A <PROPERTY_SET> describing an <OBJECT>.",
    1, &(EGBindingForEC[37]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OBJECT_SET,
    "OBJECT_SET", "ECC_OBJECT_SET",
    "A <NON_EMPTY_SET> of <OBJECT>s.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OBSERVATION_STATION,
    "OBSERVATION_STATION", "ECC_OBSERVATION_STATION",
    "A station that is equipped for observation and study.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:10]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OBSERVATORY,
    "OBSERVATORY", "ECC_OBSERVATORY",
    "An <OBSERVATION_STATION> designed and equipped for making observations"
    " of astronomical, meteorological, or other natural phenomena; an"
    " observatory [SOED, \"observatory\", 1].",
    2, &(EGBindingForEC[391]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OCCLUDED_FRONT,
    "OCCLUDED_FRONT", "ECC_OCCLUDED_FRONT",
    "A composite of two <ATMOSPHERIC_FRONT>s formed as a <COLD_FRONT>"
    " overtakes a <WARM_FRONT> or a <STATIONARY_FRONT>; an occluded front.",
    4, &(EGBindingForEC[358]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"occluded front\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OCCUPATION_ZONE,
    "OCCUPATION_ZONE", "ECC_OCCUPATION_ZONE",
    "A <REGION> temporarily held and controlled by a hostile military"
    " force; an occupation zone.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OCEAN,
    "OCEAN", "ECC_OCEAN",
    "One of the major divisions of an expanse of salt <WATER> covering a"
    " <PLANETARY_SURFACE>; an ocean.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OCEAN_BASIN,
    "OCEAN_BASIN", "ECC_OCEAN_BASIN",
    "A <TERRAIN_DEPRESSION> of an <OCEAN_FLOOR> approximately"
    " equidimensional in plan view and of variable extent; a basin.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OCEAN_FLOOR,
    "OCEAN_FLOOR", "ECC_OCEAN_FLOOR",
    "The <WATERBODY_FLOOR> of an <OCEAN>.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OFF_ROUTE_BEARING,
    "OFF_ROUTE_BEARING", "ECC_OFF_ROUTE_BEARING",
    "The <DIRECTION> and distance from an <AID_TO_NAVIGATION> to a defined"
    " <WAYPOINT>; an off route bearing.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OFFSHORE_LOADING_FACILITY,
    "OFFSHORE_LOADING_FACILITY", "ECC_OFFSHORE_LOADING_FACILITY",
    "A <FACILITY> located in a <WATERBODY> for loading and unloading"
    " <CARGO>; an offshore loading facility.",
    3, &(EGBindingForEC[835]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OFFSHORE_PLATFORM,
    "OFFSHORE_PLATFORM", "ECC_OFFSHORE_PLATFORM",
    "A <STRUCTURE> placed in a <WATERBODY> and used: for production,"
    " loading, and discharge; as an <OBSERVATION_STATION>; or as a"
    " <SCIENCE_FACILITY>; an offshore platform.",
    2, &(EGBindingForEC[691]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD111]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OIL_BARRIER,
    "OIL_BARRIER", "ECC_OIL_BARRIER",
    "A floating <BARRIER> to stop and contain oil flow on a"
    " <WATERBODY_SURFACE>; an oil barrier.",
    2, &(EGBindingForEC[751]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: OILBAR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OIL_DRILLING_RIG,
    "OIL_DRILLING_RIG", "ECC_OIL_DRILLING_RIG",
    "A <RIG> assembled primarily for the purpose of drilling an oil <WELL>;"
    " an oil drilling rig.",
    2, &(EGBindingForEC[895]),
    EDCS_REF_TYP_INFORMATIVE, "[GOFP, \"drilling rig\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OPEN_AIR_BATH,
    "OPEN_AIR_BATH", "ECC_OPEN_AIR_BATH",
    "An open air bath.",
    1, &(EGBindingForEC[39]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OPEN_WATER,
    "OPEN_WATER", "ECC_OPEN_WATER",
    "A <WATERBODY_REGION> where the <WATER> is flowing or free standing;"
    " open water.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: SA010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OPERA_HOUSE,
    "OPERA_HOUSE", "ECC_OPERA_HOUSE",
    "A <BUILDING> that houses a <THEATRE> designed chiefly for the"
    " performance of operas.",
    2, &(EGBindingForEC[1149]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"opera-house\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_ORCHARD,
    "ORCHARD", "ECC_ORCHARD",
    "A <TREED_TRACT> devoted to the cultivation of fruit or nut <TREE>s; an"
    " orchard [AHD, \"orchard\", 1].",
    4, &(EGBindingForEC[190]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EA040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ORE_REFINERY,
    "ORE_REFINERY", "ECC_ORE_REFINERY",
    "An <INDUSTRIAL_WORKS> for purifying ores (for example: copper and/or"
    " silver) and extracting from them various metal and chemical products;"
    " an ore refinery.",
    3, &(EGBindingForEC[953]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OUTBUILDING,
    "OUTBUILDING", "ECC_OUTBUILDING",
    "A small <BUILDING> that is separate from but is located near a main"
    " <BUILDING>; an outbuilding.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"outbuilding\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_OVERFALL_REGION,
    "OVERFALL_REGION", "ECC_OVERFALL_REGION",
    "A <WATERBODY_REGION> where short, breaking <WATER_WAVE>s are formed on"
    " the <WATERBODY_SURFACE> when a strong <WATER_CURRENT> passes over a"
    " <SHOAL> or other submarine obstruction or meets a contrary"
    " <WATER_CURRENT> or <WIND>; an overfall region.",
    2, &(EGBindingForEC[874]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute, CATWAT:3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OVERHEAD_OBSTRUCTION,
    "OVERHEAD_OBSTRUCTION", "ECC_OVERHEAD_OBSTRUCTION",
    "An overhead obstruction (for example: an underpass, an overhead"
    " <PIPELINE>, and/or the overhang of a <BUILDING>) on a"
    " <TRANSPORTATION_ROUTE>.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL155]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_OVERPASS,
    "OVERPASS", "ECC_OVERPASS",
    "A <BRIDGE> used to provide clearance to traffic on a"
    " <LAND_TRANSPORTATION_ROUTE> at a lower elevation; an overpass.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PACK_ICE,
    "PACK_ICE", "ECC_PACK_ICE",
    "A <REGION> of <ICE> on a <WATERBODY> formed by the drifting and"
    " crushing together of floating floes; the movement of individual floes"
    " is greatly restricted as the pack moves as a single unit.",
    1, &(EGBindingForEC[23]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BJ070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PAGODA,
    "PAGODA", "ECC_PAGODA",
    "A <HINDU_TEMPLE>, <BUDDHIST_TEMPLE>, and/or sacred <BUILDING>, usually"
    " in the form of a many-tiered <TOWER> with <FLOOR_LEVEL>s of"
    " diminishing size, each with an ornamented projecting <ROOF>; a pagoda"
    " [SOED, \"pagoda\", 1].",
    2, &(EGBindingForEC[1158]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PALACE,
    "PALACE", "ECC_PALACE",
    "A <BUILDING> serving, or that has previously served, as the official"
    " residence of a royal personage or high dignitary in a religious"
    " establishment or government; a palace [SOED, \"palace\", 1].",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PALACE_COMPLEX,
    "PALACE_COMPLEX", "ECC_PALACE_COMPLEX",
    "A <PALACE> and one or more associated <BUILDING>s; a palace complex.",
    3, &(EGBindingForEC[133]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:11]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PAPER_MILL,
    "PAPER_MILL", "ECC_PAPER_MILL",
    "A <FACILITY> for processing natural fibres (for example: wood) into"
    " flexible sheets or rolls of paper by deposit from an aqueous"
    " suspension; a paper-mill.",
    2, &(EGBindingForEC[970]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"paper-mill\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_PARAPET,
    "PARAPET", "ECC_PARAPET",
    "An <EMBANKMENT>, especially one on top of a <WALL> or <RAMPART> or in"
    " front of a <MILITARY_TRENCH>, that is built to provide protection"
    " from an enemy's observation and fire, to protect <EQUIPMENT>, to"
    " stabilize an adjacent <STRUCTURE>, or to serve as a"
    " <TERRAIN_OBSTACLE>; a parapet [SOED, \"parapet\", 1.",
    5, &(EGBindingForEC[1015]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PARCEL,
    "PARCEL", "ECC_PARCEL",
    "An administrative subdivision of a <TRACT>; a parcel [SOED,"
    " \"parcel\", 3.a].",
    1, &(EGBindingForEC[2]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: IA040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PARK,
    "PARK", "ECC_PARK",
    "A <REGION> of a <PLANETARY_SURFACE> used for recreational or"
    " ornamental purposes; a park.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK120]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PARKING_GARAGE,
    "PARKING_GARAGE", "ECC_PARKING_GARAGE",
    "A <BUILDING> or indoor space used to park or keep <MOTOR_VEHICLE>s; a"
    " parking garage.",
    3, &(EGBindingForEC[1038]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:21]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PARTICLE,
    "PARTICLE", "ECC_PARTICLE",
    "A minute portion of <MATERIAL>; a particle [SOED, \"particle\", 2].",
    1, &(EGBindingForEC[33]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PARTICLE_ACCELERATOR,
    "PARTICLE_ACCELERATOR", "ECC_PARTICLE_ACCELERATOR",
    "A <DEVICE> for imparting high velocities to charged <PARTICLE>s; a"
    " particle accelerator.",
    2, &(EGBindingForEC[559]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL140]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PATROL_CRAFT,
    "PATROL_CRAFT", "ECC_PATROL_CRAFT",
    "A <WATER_SURFACE_VESSEL> under 100 tonnes in displacement and equipped"
    " for patrol duties on relatively sheltered <WATERBODY_SURFACE_REGION>s"
    " (for example: <HARBOUR>s and/or <RIVER>s); a patrol craft.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PENSTOCK,
    "PENSTOCK", "ECC_PENSTOCK",
    "A <PIPELINE> or channel generally used by hydroelectric <POWER_PLANT>s"
    " or water mills to transport <WATER> by gravity or under pressure; a"
    " penstock.",
    2, &(EGBindingForEC[895]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH110]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PERMAFROST,
    "PERMAFROST", "ECC_PERMAFROST",
    "A layer of <SOIL> or <BEDROCK> at a variable depth beneath the"
    " <SURFACE> of the <LAND> in which the <<TEMPERATURE>> has been below"
    " freezing continuously from a few to thousands of years; permafrost.",
    3, &(EGBindingForEC[1133]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"permafrost\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PERMANENT_SNOWFIELD,
    "PERMANENT_SNOWFIELD", "ECC_PERMANENT_SNOWFIELD",
    "A permanent <SNOWFIELD>.",
    3, &(EGBindingForEC[888]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"snowfield\", 2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PERSONNEL,
    "PERSONNEL", "ECC_PERSONNEL",
    "The <NON_EMPTY_SET> of <HUMAN>s employed by an organization or engaged"
    " in a service; personnel [SOED, \"personnel\", 1.a].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PETROLEUM,
    "PETROLEUM", "ECC_PETROLEUM",
    "A dark viscous liquid consisting chiefly of hydrocarbons that is"
    " sometimes present in <ROCK> and is refined for use (for example: as a"
    " fuel and/or as a source material for manufacturing); petroleum [SOED,"
    " \"petroleum\", 1.a].",
    1, &(EGBindingForEC[33]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PETROLEUM_BUILDING,
    "PETROLEUM_BUILDING", "ECC_PETROLEUM_BUILDING",
    "A <BUILDING> involved in the production or distribution of <PETROLEUM>.",
    4, &(EGBindingForEC[907]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:102]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PETROLEUM_FACILITY,
    "PETROLEUM_FACILITY", "ECC_PETROLEUM_FACILITY",
    "A <FACILITY> including one or more <PETROLEUM_BUILDING>s.",
    5, &(EGBindingForEC[911]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AC040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PETROLEUM_FIELD,
    "PETROLEUM_FIELD", "ECC_PETROLEUM_FIELD",
    "A <TRACT> where <PETROLEUM> is pumped or otherwise removed from the"
    " ground; a petroleum field.",
    4, &(EGBindingForEC[916]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AA052]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PETROLEUM_REFINERY,
    "PETROLEUM_REFINERY", "ECC_PETROLEUM_REFINERY",
    "An <INDUSTRIAL_WORKS> for refining and purifying <PETROLEUM>; a"
    " petroleum refinery.",
    4, &(EGBindingForEC[916]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AC040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PETROLEUM_TANK_FARM,
    "PETROLEUM_TANK_FARM", "ECC_PETROLEUM_TANK_FARM",
    "A <FACILITY> devoted to the storage of <PETROLEUM> through the use of"
    " a collection of, generally above ground, <STORAGE_TANK>s; a petroleum"
    " tank farm [SOED, \"tank farm\"].",
    4, &(EGBindingForEC[916]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PHOSPHORESCENT_REGION,
    "PHOSPHORESCENT_REGION", "ECC_PHOSPHORESCENT_REGION",
    "A phosphorescent <WATERBODY_REGION>.",
    1, &(EGBindingForEC[29]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"phosphoresence\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PICNIC_TRACT,
    "PICNIC_TRACT", "ECC_PICNIC_TRACT",
    "A <TRACT> that has picnic tables for public use.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK061]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PIER,
    "PIER", "ECC_PIER",
    "A long, narrow <STRUCTURE> extending into a <WATERBODY> to afford a"
    " berthing place for <VESSEL>s or to serve as a promenade; a pier.",
    4, &(EGBindingForEC[711]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"pier\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PINGO,
    "PINGO", "ECC_PINGO",
    "A cone or dome shaped mound or <HILL> of peat or <SOIL>, usually with"
    " a core of <ICE>, that is found in <TUNDRA> and is produced by the"
    " pressure of <WATER> or <ICE> accumulating underground and pushing"
    " upward; a pingo.",
    2, &(EGBindingForEC[886]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: PINGOS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PIPE,
    "PIPE", "ECC_PIPE",
    "A hollow cylinder or tube of metal, plastic, or other <MATERIAL> that"
    " is used for the conveyance of slurries, liquids, or gases; a pipe"
    " [SOED, \"pipe\", 3.a].",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ113]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PIPELINE,
    "PIPELINE", "ECC_PIPELINE",
    "A <NON_EMPTY_SET> or connected <SET> of <PIPE>s for conveying liquids,"
    " slurries, or gases for long distances, often underground; a pipeline.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ113]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PIPELINE_TERMINUS,
    "PIPELINE_TERMINUS", "ECC_PIPELINE_TERMINUS",
    "The apparent end of a <PIPELINE> located above the <TERRAIN> where it"
    " enters the <TERRAIN>; a pipeline terminus. This apparent end often"
    " occurs at a pumping or industrial <FACILITY> or where the <PIPELINE>"
    " crosses under a <LAND_TRANSPORTATION_ROUTE>.",
    2, &(EGBindingForEC[895]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PIPING_COMPLEX,
    "PIPING_COMPLEX", "ECC_PIPING_COMPLEX",
    "A <NON_EMPTY_SET> of <PIPE>s and associated pumps used to transfer"
    " slurries, liquids, or gases from one <LOCATION> to another; a piping"
    " complex.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANET,
    "PLANET", "ECC_PLANET",
    "A <CELESTIAL_BODY> revolving in an elliptical orbit around a <STAR>; a"
    " planet [AHD, \"planet\", 1].",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANETARY_MAGNETIC_POLE,
    "PLANETARY_MAGNETIC_POLE", "ECC_PLANETARY_MAGNETIC_POLE",
    "Either of the two <LOCATION>s on a <PLANETARY_SURFACE> where, given"
    " the presence of a planetary <MAGNETIC_FIELD>, the magnetic dip is 90"
    " arc degrees (locally vertical); a planetary magnetic pole.",
    2, &(EGBindingForEC[652]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: ZC051]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANETARY_POLE,
    "PLANETARY_POLE", "ECC_PLANETARY_POLE",
    "Either of the two <LOCATION>s where the axis of rotation of a <PLANET>"
    " intersects the <PLANETARY_SURFACE>; a planetary pole.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"pole\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANETARY_SURFACE,
    "PLANETARY_SURFACE", "ECC_PLANETARY_SURFACE",
    "The <SURFACE> of a <PLANET>, specifically the <SURFACE> of the <LAND>"
    " and/or <WATERBODY>s.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANKTON,
    "PLANKTON", "ECC_PLANKTON",
    "Zooplankton or phytoplankton that is passively floating or drifting in"
    " a <WATERBODY>; plankton [MWCD, \"plankton\"].",
    1, &(EGBindingForEC[31]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANKTON_BLOOM,
    "PLANKTON_BLOOM", "ECC_PLANKTON_BLOOM",
    "An enormous concentration of <PLANKTON> in a <WATERBODY>, caused"
    " either by an explosive or a gradual multiplication and usually"
    " producing an obvious change in the physical appearance of the"
    " <WATERBODY_SURFACE_REGION>, such as discolouration; a plankton bloom.",
    2, &(EGBindingForEC[1090]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"plankton bloom\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANT,
    "PLANT", "ECC_PLANT",
    "A <LIVING_ORGANISM> of the kingdom Plantae, the members of which"
    " typically are fixed to a substrate, able to subsist wholly on"
    " inorganic substances, and move chiefly by growth; a plant [SOED,"
    " \"plant\", 2].",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANT_NURSERY,
    "PLANT_NURSERY", "ECC_PLANT_NURSERY",
    "A <FACILITY> where <PLANT>s are grown for transplanting, seed, or"
    " grafting; a plant nursery.",
    4, &(EGBindingForEC[190]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EA030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLANTATION,
    "PLANTATION", "ECC_PLANTATION",
    "An estate where cash crops are grown on a large scale, especially in"
    " tropical <REGION>s; a plantation [SOED, \"plantation\", 5].",
    3, &(EGBindingForEC[178]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLATEAU,
    "PLATEAU", "ECC_PLATEAU",
    "An elevated <TERRAIN_SURFACE_REGION> that is comparatively flat-topped"
    " and of considerable extent; a plateau.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"plateau\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLUME,
    "PLUME", "ECC_PLUME",
    "An identifiable stream of <AIR> with an <<AIR_TEMPERATURE>> or"
    " composition different from that of its environment; a plume. EXAMPLE"
    " <SMOKE> from a <CHIMNEY>.",
    3, &(EGBindingForEC[290]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"plume\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PLUTO,
    "PLUTO", "ECC_PLUTO",
    "The primary <PLANET> of the <SUN> that is normally ninth in distance"
    " from the <SUN>, travelling in a highly eccentric orbit with an"
    " orbital mean <<RADIUS>> of approximately 5 915,8 million kilometres;"
    " Pluto.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POD,
    "POD", "ECC_POD",
    "A <SET> of two or more seals or <WHALE>s closely clustered together; a"
    " pod.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"pod\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POINT_ABEAM,
    "POINT_ABEAM", "ECC_POINT_ABEAM",
    "The <LOCATION> on a <LINE> that is nearest to and abeam of another"
    " <LOCATION> that is not on the <LINE>; point abeam. EXAMPLE A"
    " <LOCATION> on the centre-line of a <RUNWAY> is abeam a glide slope"
    " <AERIAL> when the distance from the centre-line of the <RUNWAY> to"
    " the glide slope <AERIAL> is at a minimum.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB058]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POLAR_CAP,
    "POLAR_CAP", "ECC_POLAR_CAP",
    "A <REGION> of <ICE> or other frozen <MATERIAL> surrounding a"
    " <PLANETARY_POLE>; a polar cap [SOED, \"polar cap\"].",
    2, &(EGBindingForEC[886]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POLAR_ICE,
    "POLAR_ICE", "ECC_POLAR_ICE",
    "<ICE> that is a permanent feature of <PLANETARY_POLE>s; polar ice.",
    1, &(EGBindingForEC[23]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BJ080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POLE,
    "POLE", "ECC_POLE",
    "A long, slender, more or less cylindrical piece of <MATERIAL> (for"
    " example: wood or metal) used as a support (for example: to hold up a"
    " <TENT>, for <VEGETATION> to climb on, for supporting an"
    " <ELEVATED_ELECTRICAL_CABLE>, and/or for holding up scaffolding); a"
    " pole [SOED, \"pole\", 1.a].",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POLICE_STATION,
    "POLICE_STATION", "ECC_POLICE_STATION",
    "A <PUBLIC_SERVICE_STATION> that serves as the headquarters of a unit"
    " of a police force and that is where those under arrest are first"
    " charged; a police station.",
    1, &(EGBindingForEC[2]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"police station\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_POLYGONAL_FACE,
    "POLYGONAL_FACE", "ECC_POLYGONAL_FACE",
    "A polygon used to model some aspect of an <OBJECT>; a polygonal face.",
    1, &(EGBindingForEC[6]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"face\", II.10]", EDCS_CONCEPT_STAT_DEPRECATED },

    {ECC_POLYNYA,
    "POLYNYA", "ECC_POLYNYA",
    "A large <REGION> of <OPEN_WATER> that is surrounded by floating <ICE>;"
    " a polynya [SOED, \"polynya\"].",
    2, &(EGBindingForEC[844]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PONTOON,
    "PONTOON", "ECC_PONTOON",
    "A broad, flat-bottomed <STRUCTURE> that is rectangular in shape,"
    " resembles a barge, and is designed to float on a <WATERBODY_SURFACE>;"
    " a pontoon.",
    1, &(EGBindingForEC[19]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: PONTON]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PORPOISE,
    "PORPOISE", "ECC_PORPOISE",
    "A small to moderate sized member of the order Cetacea, suborder"
    " Odontoceti, family Phocaenidae; a porpoise.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"porpoise\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POST_OFFICE,
    "POST_OFFICE", "ECC_POST_OFFICE",
    "A <PUBLIC_SERVICE_STATION> where postal business (for example: where"
    " mail is handled and/or where stamps and other postal materials are"
    " sold) may be carried on; a post office.",
    2, &(EGBindingForEC[487]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"post office\", A.1], [SOED, \"post office\", A.2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_POTENTIAL_LANDSLIDE_REGION,
    "POTENTIAL_LANDSLIDE_REGION", "ECC_POTENTIAL_LANDSLIDE_REGION",
    "A <TRACT> with a high potential of slipping down from an elevated"
    " <LOCATION> (for example: a <CLIFF> and/or the side of a <MOUNTAIN>);"
    " a potential landslide region.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB210]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POWER_GENERATION_BUILDING,
    "POWER_GENERATION_BUILDING", "ECC_POWER_GENERATION_BUILDING",
    "A <BUILDING> and associated <EQUIPMENT> used for the generation of"
    " electric power; a power generation building.",
    3, &(EGBindingForEC[629]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AD010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POWER_PLANT,
    "POWER_PLANT", "ECC_POWER_PLANT",
    "A <FACILITY> including one or more <POWER_GENERATION_BUILDING>s; a"
    " power plant.",
    4, &(EGBindingForEC[632]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AD010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POWER_SUBSTATION,
    "POWER_SUBSTATION", "ECC_POWER_SUBSTATION",
    "A <FACILITY>, along a <POWER_TRANSMISSION_LINE>, in which electric"
    " current is transformed and/or distributed; a power substation or"
    " transformer yard.",
    3, &(EGBindingForEC[642]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AD030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POWER_TRANSMISSION_LINE,
    "POWER_TRANSMISSION_LINE", "ECC_POWER_TRANSMISSION_LINE",
    "A <SYSTEM> of <ELEVATED_ELECTRICAL_CABLE>s and associated"
    " <POWER_TRANSMISSION_LINE_PYLON>s that transmit electrical power; a"
    " power transmission line.",
    2, &(EGBindingForEC[621]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AT030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POWER_TRANSMISSION_LINE_PYLON,
    "POWER_TRANSMISSION_LINE_PYLON", "ECC_POWER_TRANSMISSION_LINE_PYLON",
    "A <PYLON> or <POLE> used to support a <POWER_TRANSMISSION_LINE>.",
    3, &(EGBindingForEC[636]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AT040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_POWER_TRANSMISSION_LINE_TERMINUS,
    "POWER_TRANSMISSION_LINE_TERMINUS", "ECC_POWER_TRANSMISSION_LINE_TERMINUS",
    "The terminus of a <POWER_TRANSMISSION_LINE> at a <POWER_PLANT>,"
    " <POWER_SUBSTATION>, transformer, or receiving <FACILITY>.",
    2, &(EGBindingForEC[621]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PRECIPITATION,
    "PRECIPITATION", "ECC_PRECIPITATION",
    "Aqueous <PARTICLE>s in liquid phase or solid phase that originate in"
    " the <ATMOSPHERE> and fall to the <PLANETARY_SURFACE> of the <EARTH>;"
    " precipitation.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"precipitation\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PRECIPITATION_REGION,
    "PRECIPITATION_REGION", "ECC_PRECIPITATION_REGION",
    "A <REGION> where <PRECIPITATION> is occurring.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PRECOLLEGIATE_CAMPUS,
    "PRECOLLEGIATE_CAMPUS", "ECC_PRECOLLEGIATE_CAMPUS",
    "A <FACILITY> used for precollegiate instruction (generally of"
    " children); a precollegiate campus.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:15]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PREPARED_DEFENSIVE_POSITION_SITE,
    "PREPARED_DEFENSIVE_POSITION_SITE", "ECC_PREPARED_DEFENSIVE_POSITION_SITE",
    "A <SITE> containing one or more prepared <DEFENSIVE_POSITION>s.",
    2, &(EGBindingForEC[1129]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PREPARED_DEFENSIVE_TRACT,
    "PREPARED_DEFENSIVE_TRACT", "ECC_PREPARED_DEFENSIVE_TRACT",
    "A <TRACT> containing military <STRUCTURE>s resistant to <MUNITION>s"
    " (for example: a bastion, a <RAMPART>, a <FORTIFICATION>, a"
    " <DEFENSIVE_POSITION>, an <INFANTRY_TRENCH>, and/or a <BUNKER>); a"
    " prepared defensive tract.",
    2, &(EGBindingForEC[1129]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PREPARED_WATERCOURSE_CROSSING,
    "PREPARED_WATERCOURSE_CROSSING", "ECC_PREPARED_WATERCOURSE_CROSSING",
    "A <LOCATION> on a <WATERCOURSE> that has <RAMP>s, <STRUCTURAL_PILE>s,"
    " and/or <PIER>s constructed on one or both <SHORE>s to allow for"
    " suitable future crossing operations using floating <BRIDGE>s or"
    " rafting <EQUIPMENT>; a prepared watercourse crossing.",
    3, &(EGBindingForEC[800]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ111]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PRESSURE_ICE,
    "PRESSURE_ICE", "ECC_PRESSURE_ICE",
    "<ICE> located in a <SEA>, <RIVER>, or <LAKE> that has been deformed or"
    " altered by the lateral stresses of any combination of <WIND>,"
    " <TIDE>s, <WATER_WAVE>s, and <SURF>; pressure ice.",
    3, &(EGBindingForEC[883]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"pressure ice\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PREVAILING_CURRENT,
    "PREVAILING_CURRENT", "ECC_PREVAILING_CURRENT",
    "A <WATERBODY_CURRENT> most frequently observed during a given"
    " observation period, usually a month, season, or year; a prevailing"
    " current.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"prevailing current\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PRISON,
    "PRISON", "ECC_PRISON",
    "A <DETENTION_FACILITY> where long (usually more than one year)"
    " sentences for criminal misconduct can be served; a prison.",
    1, &(EGBindingForEC[2]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"prison\", A.1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_PROCESSING_BUILDING,
    "PROCESSING_BUILDING", "ECC_PROCESSING_BUILDING",
    "A <BUILDING> that is used for the changing or refining of a particular"
    " <MATERIAL>; a processing or treatment building.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:89]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PROCESSING_FACILITY,
    "PROCESSING_FACILITY", "ECC_PROCESSING_FACILITY",
    "A <FACILITY> including one or more <PROCESSING_BUILDING>s; a"
    " processing facility.",
    4, &(EGBindingForEC[949]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AC000]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PROHIBITED_REGION,
    "PROHIBITED_REGION", "ECC_PROHIBITED_REGION",
    "A <REGION>, usually on a <MILITARY_INSTALLATION>, where entrance or"
    " presence of unauthorized <PERSONNEL> is prohibited, typically due to"
    " the presence of unexploded <MUNITION>s, <EXPLOSIVE_MINE>s, or"
    " sensitive environmental habitats; a prohibited region.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PROMONTORY,
    "PROMONTORY", "ECC_PROMONTORY",
    "A high point of <LAND> extending into a <WATERBODY>; a promontory.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"promontory\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PROPERTY_SET,
    "PROPERTY_SET", "ECC_PROPERTY_SET",
    "A <SET> of EDCS Attributes and/or functional relationships between"
    " EDCS Attributes that are applicable to an <OBJECT>, <LOCATION>,"
    " and/or <REGION>; a property set.",
    1, &(EGBindingForEC[37]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PROTECTION_SHED,
    "PROTECTION_SHED", "ECC_PROTECTION_SHED",
    "A <SHELTER> built to protect a section of <ROAD> or <RAILWAY> from"
    " slides of <SNOW_GROUND_COVER> and/or <ROCK>; a protection shed.",
    4, &(EGBindingForEC[876]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL210]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PROTIST,
    "PROTIST", "ECC_PROTIST",
    "A <LIVING_ORGANISM> of the kingdom Protista, the members of which are"
    " simple organisms that are between, or distinct from, <ANIMAL>s and"
    " <PLANT>s, especially a unicellular eukaryote; a protist [SOED,"
    " \"protist\"]. EXAMPLES Protozoan, single-celled <ALGA>.",
    1, &(EGBindingForEC[31]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PTERIDOPHYTE,
    "PTERIDOPHYTE", "ECC_PTERIDOPHYTE",
    "A <PLANT> of the group Pteridophyta; a pteridophyte [SOED,"
    " \"pteridophyte\"]. EXAMPLES <FERN>, horsetail, clubmoss.",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PUBLIC_INN,
    "PUBLIC_INN", "ECC_PUBLIC_INN",
    "A <RESTAURANT> where lodging may be available; a public inn.",
    4, &(EGBindingForEC[949]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"inn\", 3]", EDCS_CONCEPT_STAT_ISO },

    {ECC_PUBLIC_SERVICE_STATION,
    "PUBLIC_SERVICE_STATION", "ECC_PUBLIC_SERVICE_STATION",
    "A station that houses public services and from which operations are"
    " directed or services provided.",
    2, &(EGBindingForEC[120]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PUBLIC_SQUARE,
    "PUBLIC_SQUARE", "ECC_PUBLIC_SQUARE",
    "An open <SITE> that serves as a public meeting <LOCATION> in a <CITY>"
    " or <TOWN>; a plaza or public square.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PUFF,
    "PUFF", "ECC_PUFF",
    "A small, identifiable quantity of <AIR> with a composition different"
    " from that of its environment emitted in one light, abrupt blast; a"
    " puff. EXAMPLE The initial <NON_AQUEOUS_CLOUD> of <SMOKE> from an"
    " explosion.",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PULPIT,
    "PULPIT", "ECC_PULPIT",
    "A raised <STRUCTURE> consisting of an enclosed platform from which the"
    " preacher in a <CHURCH> or <CHAPEL> delivers the sermon; a pulpit"
    " [SOED, \"pulpit\", 2.a].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PUMP_OUT_FACILITY,
    "PUMP_OUT_FACILITY", "ECC_PUMP_OUT_FACILITY",
    "A <FACILITY> with <EQUIPMENT> to pump out waste liquids from"
    " <VEHICLE>s; a pump out facility.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB200]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PUMP_ROOM,
    "PUMP_ROOM", "ECC_PUMP_ROOM",
    "A <BUILDING> or <ROOM> housing pumps for raising, compressing, or"
    " transferring fluids; a pump room or pump house (US).",
    3, &(EGBindingForEC[402]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ116]",
    "[SOED, \"pump room\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_PUMPING_STATION,
    "PUMPING_STATION", "ECC_PUMPING_STATION",
    "A <FACILITY> to move slurries, liquids, or gases by means of pressure"
    " or suction; a pumping station.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ116]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_PYLON,
    "PYLON", "ECC_PYLON",
    "A tall <STRUCTURE> erected as a support; a pylon [SOED, \"pylon\","
    " 4.a].",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_QUARRY,
    "QUARRY", "ECC_QUARRY",
    "An <EXCAVATION> created by removal of <ROCK> by blasting or cutting; a"
    " quarry.",
    3, &(EGBindingForEC[959]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AA012]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RACE_TRACK,
    "RACE_TRACK", "ECC_RACE_TRACK",
    "A course for racing (for example: racing <NON_HUMAN_ANIMAL>s and/or"
    " racing <MOTOR_VEHICLE>s); a racetrack.",
    1, &(EGBindingForEC[39]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK130]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RADAR_DEVICE,
    "RADAR_DEVICE", "ECC_RADAR_DEVICE",
    "A <DEVICE> used for the reception or transmission of radar signals.",
    3, &(EGBindingForEC[427]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AT045]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RADAR_LINE,
    "RADAR_LINE", "ECC_RADAR_LINE",
    "A <LINE> shown on a marine <MAP> corresponding to the <LINE>s seen on"
    " radar displays of <HARBOUR>s; a radar line.",
    4, &(EGBindingForEC[810]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: RADLNE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RADAR_MATERIAL_PROPERTY_SET,
    "RADAR_MATERIAL_PROPERTY_SET", "ECC_RADAR_MATERIAL_PROPERTY_SET",
    "A <PROPERTY_SET> describing the radar properties of the <MATERIAL>s"
    " composing an <OBJECT>.",
    3, &(EGBindingForEC[654]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RADAR_RECEIVER,
    "RADAR_RECEIVER", "ECC_RADAR_RECEIVER",
    "A <DEVICE> used for the reception of radar signals; a radar receiver.",
    2, &(EGBindingForEC[559]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AT045]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RADAR_REFERENCE_LINE,
    "RADAR_REFERENCE_LINE", "ECC_RADAR_REFERENCE_LINE",
    "A <LINE> along which <VESSEL>s are guided by a traffic control centre"
    " located in a <RADAR_STATION>; a radar reference line. This <LINE> is"
    " shown on a marine <MAP> in proximity to a <MARINE_ROUTE>.",
    5, &(EGBindingForEC[475]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FC130]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RADAR_STATION,
    "RADAR_STATION", "ECC_RADAR_STATION",
    "A <RADAR_DEVICE> and support <STRUCTURE>s; a radar station.",
    3, &(EGBindingForEC[427]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: RADSTA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RADAR_TRANSMITTER,
    "RADAR_TRANSMITTER", "ECC_RADAR_TRANSMITTER",
    "A <DEVICE> used for the transmission of radar signals; a radar"
    " transmitter.",
    3, &(EGBindingForEC[427]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AT045]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RADIOLOGIC_HAZARD_REGION,
    "RADIOLOGIC_HAZARD_REGION", "ECC_RADIOLOGIC_HAZARD_REGION",
    "A <REGION> in which a radiologic substance is present that can kill,"
    " seriously injure, or incapacitate a <HUMAN> and/or <ANIMAL> through"
    " its physiological properties. The radiologic substance is usually"
    " dispersed over a <SURFACE> and/or within the <ATMOSPHERE>.",
    4, &(EGBindingForEC[372]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAIL_HEAD,
    "RAIL_HEAD", "ECC_RAIL_HEAD",
    "A <LOCATION> that is the furthest point reached by a <RAILWAY> where"
    " <EQUIPMENT> and/or <MATERIAL>s are loaded onto or unloaded from"
    " <RAIL_WAGON>s; a rail-head [SOED, \"rail-head\", 1] or rail terminus.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AN065]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAIL_TRANSFER_POINT,
    "RAIL_TRANSFER_POINT", "ECC_RAIL_TRANSFER_POINT",
    "A <LOCATION> where <EQUIPMENT> and/or <MATERIAL>s may be loaded onto"
    " or unloaded from a <RAIL_WAGON>; a rail transfer point.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AN065]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAIL_WAGON,
    "RAIL_WAGON", "ECC_RAIL_WAGON",
    "A <GROUND_VEHICLE> that is usually not self-propelled and that travels"
    " on a <RAILWAY_TRACK>; a rail wagon or a railroad car (US).",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY,
    "RAILWAY", "ECC_RAILWAY",
    "A <LAND_TRANSPORTATION_ROUTE> consisting of one or more"
    " <RAILWAY_TRACK>s; a railway, or a railroad (US).",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AN010]",
    "[SOED, \"railway\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_NEXUS,
    "RAILWAY_NEXUS", "ECC_RAILWAY_NEXUS",
    "A representation of one or more <RAILWAY>s, especially in a"
    " <BUILT_UP_REGION>; a railway centre-line or railway nexus.",
    3, &(EGBindingForEC[1012]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_SIDETRACK,
    "RAILWAY_SIDETRACK", "ECC_RAILWAY_SIDETRACK",
    "A stretch of <RAILWAY_TRACK> connected to a main <RAILWAY> and used"
    " for temporary storage, loading, and/or unloading; a railway sidetrack.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AN050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_SIDING,
    "RAILWAY_SIDING", "ECC_RAILWAY_SIDING",
    "A short stretch of <RAILWAY_TRACK> connected at both ends to a main"
    " <RAILWAY> and used to store <RAIL_WAGON>s or enable <TRAIN>s on the"
    " same line to pass; a railway siding [SOED, \"siding\", II.7.a].",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AN050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_SIGNAL_BOX,
    "RAILWAY_SIGNAL_BOX", "ECC_RAILWAY_SIGNAL_BOX",
    "Automated <EQUIPMENT> from which signals are sent to control the"
    " movements of <TRAIN>s; a signal box or signal tower.",
    4, &(EGBindingForEC[443]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:76]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_SIGNAL_STRUCTURE,
    "RAILWAY_SIGNAL_STRUCTURE", "ECC_RAILWAY_SIGNAL_STRUCTURE",
    "An automated or manned <STRUCTURE> located adjacent to a <RAILWAY>"
    " that displays control information to passing <TRAIN>s; a railway"
    " signal structure.",
    3, &(EGBindingForEC[496]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"signal-box\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_SIGNALMAN_HOUSE,
    "RAILWAY_SIGNALMAN_HOUSE", "ECC_RAILWAY_SIGNALMAN_HOUSE",
    "A manned <STRUCTURE> located adjacent to a <RAILWAY> that displays"
    " control information to passing <TRAIN>s; a signalman house.",
    3, &(EGBindingForEC[496]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:76]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_SPUR,
    "RAILWAY_SPUR", "ECC_RAILWAY_SPUR",
    "A short <RAILWAY_TRACK> that connects with the main <RAILWAY> at one"
    " end only; a railway spur [AHD, \"spur track\"].",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AN050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_STATION,
    "RAILWAY_STATION", "ECC_RAILWAY_STATION",
    "A <BUILDING> or stopping place along a <RAILWAY> for taking on and"
    " letting off passengers or for servicing; a railway station.",
    3, &(EGBindingForEC[1038]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"railway station\", IV.16]", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_STORAGE_REPAIR_BUILDING,
    "RAILWAY_STORAGE_REPAIR_BUILDING", "ECC_RAILWAY_STORAGE_REPAIR_BUILDING",
    "A <BUILDING> that is used for the servicing, repair, and/or storage of"
    " <RAIL_WAGON>s and related <EQUIPMENT>.",
    3, &(EGBindingForEC[1038]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"shed\", 1.b]", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_STORAGE_REPAIR_FACILITY,
    "RAILWAY_STORAGE_REPAIR_FACILITY", "ECC_RAILWAY_STORAGE_REPAIR_FACILITY",
    "A <FACILITY> used for the servicing, repair, and/or storage of"
    " <RAIL_WAGON>s and related <EQUIPMENT>.",
    3, &(EGBindingForEC[1052]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:26]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_SWITCH,
    "RAILWAY_SWITCH", "ECC_RAILWAY_SWITCH",
    "A <DEVICE> integrated with a <RAILWAY_TRACK> with which the rails may"
    " be switched to permit access to another <RAILWAY_TRACK>.",
    3, &(EGBindingForEC[603]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AN080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_TABLE,
    "RAILWAY_TABLE", "ECC_RAILWAY_TABLE",
    "A rotating platform with <RAILWAY_TRACK>s used for turning"
    " <LOCOMOTIVE_ENGINE>s or <RAIL_WAGON>s; a railway table [SOED,"
    " \"turntable\", a].",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AN075]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_TRACK,
    "RAILWAY_TRACK", "ECC_RAILWAY_TRACK",
    "A rail or two parallel rails on which a <TRAIN>, tram, or <RAIL_WAGON>"
    " runs; a railway track.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: RAILWY]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_TURNTABLE,
    "RAILWAY_TURNTABLE", "ECC_RAILWAY_TURNTABLE",
    "A <RAILWAY_TABLE>, which may be enclosed within a <STRUCTURE>; a"
    " railway turntable.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AN075]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_YARD,
    "RAILWAY_YARD", "ECC_RAILWAY_YARD",
    "A <SYSTEM> of <RAILWAY_TRACK>s and associated <STRUCTURE>s that are"
    " located within defined limits and that provide for loading,"
    " unloading, and/or assembling <TRAIN>s; a railway yard or marshalling"
    " yard.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AN060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAILWAY_YARD_NEXUS,
    "RAILWAY_YARD_NEXUS", "ECC_RAILWAY_YARD_NEXUS",
    "A representation of a <RAILWAY_YARD> as it connects to related"
    " <RAILWAY>s; a railway yard centre-line or railway yard nexus.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAIN,
    "RAIN", "ECC_RAIN",
    "<PRECIPITATION> of <PARTICLE>s of liquid <WATER> either in the form of"
    " drops of more than 0,5 millimetres in <<OUTSIDE_DIAMETER >> or in the"
    " form of widely scattered drops; rain.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"rain\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAIN_REGION,
    "RAIN_REGION", "ECC_RAIN_REGION",
    "A <REGION> in which <RAIN> is falling.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAMP,
    "RAMP", "ECC_RAMP",
    "An inclined plane, usually man-made, for moving between two levels; a"
    " ramp.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL195]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAMPART,
    "RAMPART", "ECC_RAMPART",
    "A defensive <WALL>, which is sometimes equipped with"
    " <FIELD_ARTILLERY>, that is built to defend a <FORT> or a similar"
    " <DEFENSIVE_POSITION>; a bastion or rampart.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AH010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RANGER_STATION,
    "RANGER_STATION", "ECC_RANGER_STATION",
    "A <BUILDING> housing a warden employed to maintain and protect a"
    " <FOREST> or other natural <REGION> of a <PLANETARY_SURFACE>; a ranger"
    " station.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:14]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAPID,
    "RAPID", "ECC_RAPID",
    "A steep descent in a <WATERCOURSE> causing a swift <WATER_CURRENT>; a"
    " rapid [SOED, \"rapid\", 1].",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH120]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RAY_PATH,
    "RAY_PATH", "ECC_RAY_PATH",
    "An imaginary <LINE> along which energy associated with a <LOCATION> on"
    " a wave front moves; a ray path.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"ray path\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RECONNAISSANCE_HELICOPTER,
    "RECONNAISSANCE_HELICOPTER", "ECC_RECONNAISSANCE_HELICOPTER",
    "A <HELICOPTER> designed or designated for reconnaissance operations.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RECONNAISSANCE_WINGED_AIRCRAFT,
    "RECONNAISSANCE_WINGED_AIRCRAFT", "ECC_RECONNAISSANCE_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed or designated for reconnaissance"
    " operations.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RECREATIONAL_FACILITY,
    "RECREATIONAL_FACILITY", "ECC_RECREATIONAL_FACILITY",
    "A <FACILITY> used for recreation; a recreational facility.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RECREATIONAL_PIER,
    "RECREATIONAL_PIER", "ECC_RECREATIONAL_PIER",
    "A <PIER> used for recreational purposes and not intended as a berthing"
    " place for <VESSEL>s.",
    2, &(EGBindingForEC[741]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK190]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RECYCLING_SITE,
    "RECYCLING_SITE", "ECC_RECYCLING_SITE",
    "A <SITE> engaged in the wrecking, dismantling, storage, recycling,"
    " and/or resale of discarded or scrap products.",
    3, &(EGBindingForEC[904]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AB010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REEF,
    "REEF", "ECC_REEF",
    "An elevation of <ROCK> or <CORAL> at or near enough to the"
    " <WATERBODY_SURFACE> to be a danger to surface <VESSEL>s.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BD120]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REFORMATORY_BUILDING,
    "REFORMATORY_BUILDING", "ECC_REFORMATORY_BUILDING",
    "A <BUILDING> used for the discipline, reformation, and training of"
    " young and/or first offenders; a reformatory building.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REFORMATORY_FACILITY,
    "REFORMATORY_FACILITY", "ECC_REFORMATORY_FACILITY",
    "A <FACILITY> including one or more <REFORMATORY_BUILDING>s; a"
    " reformatory facility.",
    3, &(EGBindingForEC[133]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REFUELLING_TRACK,
    "REFUELLING_TRACK", "ECC_REFUELLING_TRACK",
    "A specific <AIR_TRANSPORTATION_ROUTE> designated for channelling the"
    " flow of air traffic as necessary for the purpose of refuelling; a"
    " refuelling track.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, AUB: 27]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REFUGEE_COMPOUND,
    "REFUGEE_COMPOUND", "ECC_REFUGEE_COMPOUND",
    "A <FACILITY>, which is usually temporary, constructed to house groups"
    " of <HUMAN>s fleeing from their communities in search of refuge (for"
    " example: from war, political oppression, and/or religious"
    " persecution); a refugee compound.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REFUSE_BIN,
    "REFUSE_BIN", "ECC_REFUSE_BIN",
    "A <CONTAINER> that: is of several cubic metres capacity; is used for"
    " the collection of refuse; and is designed to be hoisted and emptied"
    " into a specially equipped <TRUCK> or, occasionally, hauled away; a"
    " refuse bin.",
    2, &(EGBindingForEC[597]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REGION,
    "REGION", "ECC_REGION",
    "A usually contiguous subset of the environment that may include"
    " <TERRAIN>, a <WATERBODY>, the <ATMOSPHERE>, and/or <SPACE>; a region.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REGION_PROPERTY_SET,
    "REGION_PROPERTY_SET", "ECC_REGION_PROPERTY_SET",
    "A <PROPERTY_SET> describing a <REGION>.",
    1, &(EGBindingForEC[37]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REGIONAL_PARK,
    "REGIONAL_PARK", "ECC_REGIONAL_PARK",
    "A significant <TRACT> set aside for public use that generally has few"
    " or no <BUILDING>s, is located away from <BUILT_UP_REGION>s, and is"
    " maintained for recreational and ornamental purposes; a regional park.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REGULATED_LINE,
    "REGULATED_LINE", "ECC_REGULATED_LINE",
    "A <BOUNDARY> established to regulate matters between nations or groups"
    " over a specific territory; a regulated line. EXAMPLES Mandate line,"
    " convention line.",
    3, &(EGBindingForEC[111]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RELATED_OBJECT_SET,
    "RELATED_OBJECT_SET", "ECC_RELATED_OBJECT_SET",
    "A <NON_EMPTY_SET> of related <OBJECT>s.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RELATIVE_DISPLACEMENT_LINE,
    "RELATIVE_DISPLACEMENT_LINE", "ECC_RELATIVE_DISPLACEMENT_LINE",
    "A <LINE> connecting <LOCATION>s having a constant relative vertical"
    " offset from the <TERRAIN>; a relative displacement line.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RELIGIOUS_COMMUNITY,
    "RELIGIOUS_COMMUNITY", "ECC_RELIGIOUS_COMMUNITY",
    "A <NON_EMPTY_SET> of <DWELLING>s, <BUILDING>s, and/or other"
    " <STRUCTURE>s that houses a community of <HUMAN>s under religious"
    " vows; a religious community. EXAMPLES <CONVENT>, <MONASTERY>.",
    2, &(EGBindingForEC[1158]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REPAIR_BUILDING,
    "REPAIR_BUILDING", "ECC_REPAIR_BUILDING",
    "A <BUILDING> used for restoring broken and/or damaged goods (for"
    " example: <EQUIPMENT>) to sound condition; a repair building.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:124]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REPAIR_FACILITY,
    "REPAIR_FACILITY", "ECC_REPAIR_FACILITY",
    "A <FACILITY> including one or more <REPAIR_BUILDING>s; a repair"
    " facility.",
    4, &(EGBindingForEC[949]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REPTILE,
    "REPTILE", "ECC_REPTILE",
    "A <VERTEBRATE> of the class Reptilia, the members of which are"
    " characterized by scaly impermeable skin, poikilothermy, and oviparous"
    " (or ovoviviparous) reproduction; a reptile [SOED, \"reptile\", 1]."
    " EXAMPLES Snake, lizard, turtle, crocodile.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RESERVE,
    "RESERVE", "ECC_RESERVE",
    "A <REGION> set apart by a governmental body, institution, or"
    " individual for a special purpose; a reserve or reservation [SOED,"
    " \"reservation\", 7.a].",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RESERVOIR,
    "RESERVOIR", "ECC_RESERVOIR",
    "A <LOCATION> where anything is collected and stored, generally in"
    " large quantity; especially a pond, <LAKE>, or <WATERBODY_BASIN>,"
    " either natural or artificial, for the storage, regulation, and"
    " control of <WATER>; a reservoir.",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"reservoir\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RESERVOIR_NEXUS,
    "RESERVOIR_NEXUS", "ECC_RESERVOIR_NEXUS",
    "A representation of a <RESERVOIR> as it connects to related"
    " <RIVER_NEXUS>s; a reservoir centre-line or reservoir nexus.",
    2, &(EGBindingForEC[860]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RESIDENTIAL_REGION,
    "RESIDENTIAL_REGION", "ECC_RESIDENTIAL_REGION",
    "A <REGION> of <BUILDING>s primarily devoted to housing a population,"
    " as well as providing a variety of supporting services (for example: a"
    " <POST_OFFICE>, a grocery store, a dry cleaners, a florist, a"
    " <RESTAURANT>, and/or a small <RETAIL_FACILITY>); a residential region.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RESTAURANT,
    "RESTAURANT", "ECC_RESTAURANT",
    "A <BUILDING> or outdoor <SITE> where meals are served to the public; a"
    " restaurant [AHD, \"restaurant\"].",
    4, &(EGBindingForEC[949]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RETAIL_FACILITY,
    "RETAIL_FACILITY", "ECC_RETAIL_FACILITY",
    "A <FACILITY> that is used for retail (for example: for the sale of"
    " goods or commodities in small quantities directly to consumers); a"
    " retail facility.",
    2, &(EGBindingForEC[970]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REVERBERATION,
    "REVERBERATION", "ECC_REVERBERATION",
    "Sound waves scattered back towards their source from an acoustically"
    " reflective <SURFACE> or volume; reverberation.",
    1, &(EGBindingForEC[1]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"reverberation\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_REVETMENT,
    "REVETMENT", "ECC_REVETMENT",
    "A <BARRIER> protecting a <RAMPART> or <WALL>; a revetment [SOED,"
    " \"revetment\", 2].",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RICE_FIELD,
    "RICE_FIELD", "ECC_RICE_FIELD",
    "A <TRACT> that is periodically covered with <WATER> and is used for"
    " growing rice; a rice field.",
    4, &(EGBindingForEC[190]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH135]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIDGE,
    "RIDGE", "ECC_RIDGE",
    "Relatively high <TERRAIN> formed as a long and narrow crest that is"
    " surrounded by lower <TERRAIN>; a ridge.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"ridge\", 2.a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIDGE_LINE,
    "RIDGE_LINE", "ECC_RIDGE_LINE",
    "A <LINE> delineating the top of a <RIDGE>; a ridge line.",
    2, &(EGBindingForEC[1092]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: CA020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIG,
    "RIG", "ECC_RIG",
    "A <SUPERSTRUCTURE> fitted for drilling or lifting operations for"
    " extraction and/or exploitation of natural resources; a rig or"
    " superstructure.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AA040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIME,
    "RIME", "ECC_RIME",
    "A white or milky and opaque granular deposit of <ICE> formed by the"
    " rapid freezing of supercooled drops of <WATER> as they impinge upon"
    " an exposed <OBJECT>; rime. It is denser and harder than <HOAR_FROST>,"
    " but lighter, softer, and less transparent than <ICE_GLAZE>.",
    2, &(EGBindingForEC[891]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"rime\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIP_CURRENT,
    "RIP_CURRENT", "ECC_RIP_CURRENT",
    "A strong, narrow, surface <WATER_CURRENT> flowing away from a"
    " <SHORELINE>.",
    2, &(EGBindingForEC[874]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"rip current\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIPRAP,
    "RIPRAP", "ECC_RIPRAP",
    "A loose assemblage of broken <STONE>s or similar <MATERIAL> that is"
    " erected along a <WATERBODY> or on soft <TERRAIN> as either a"
    " foundation or to protect the underlying <SURFACE> from erosion;"
    " riprap.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB225]",
    "[SOED, \"riprap\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIVER,
    "RIVER", "ECC_RIVER",
    "A natural flowing <WATERCOURSE>; a river or stream.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: RIVERS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIVER_BANK,
    "RIVER_BANK", "ECC_RIVER_BANK",
    "The <WATERBODY_BANK> of a <RIVER>.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH141]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIVER_GAUGING_STATION,
    "RIVER_GAUGING_STATION", "ECC_RIVER_GAUGING_STATION",
    "A <DEVICE> and support <STRUCTURE>s that monitors flow in a <RIVER>; a"
    " river gauging station.",
    2, &(EGBindingForEC[564]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BI070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIVER_NEXUS,
    "RIVER_NEXUS", "ECC_RIVER_NEXUS",
    "A representation of one or more <RIVER>s; a river centre-line or river"
    " nexus.",
    2, &(EGBindingForEC[860]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIVER_ROUTE,
    "RIVER_ROUTE", "ECC_RIVER_ROUTE",
    "The <MARINE_ROUTE> in a <RIVER> suitable for the largest allowed"
    " <VESSEL>s.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH501]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RIVER_VANISHING_POINT,
    "RIVER_VANISHING_POINT", "ECC_RIVER_VANISHING_POINT",
    "The <LOCATION> at which a <RIVER> passes into the <TERRAIN>; a river"
    " vanishing point.",
    2, &(EGBindingForEC[860]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH145]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROAD,
    "ROAD", "ECC_ROAD",
    "A <LAND_TRANSPORTATION_ROUTE> maintained for use by <MOTOR_VEHICLE>s;"
    " a road.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AP030]",
    "[SOED, \"road\", 4.a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROAD_INTERCHANGE,
    "ROAD_INTERCHANGE", "ECC_ROAD_INTERCHANGE",
    "A connection designed to provide traffic access from one <ROAD> to"
    " another; a road interchange.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AP020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROAD_NEXUS,
    "ROAD_NEXUS", "ECC_ROAD_NEXUS",
    "A representation of one or more <ROAD>s, especially in a"
    " <BUILT_UP_REGION>; a road centre-line or road nexus.",
    3, &(EGBindingForEC[1012]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROAD_ROUTE_MARKER,
    "ROAD_ROUTE_MARKER", "ECC_ROAD_ROUTE_MARKER",
    "A <DISPLAY_SIGN> used to designate a <ROAD>; a route marker.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ119]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROADSIDE_REST_STOP,
    "ROADSIDE_REST_STOP", "ECC_ROADSIDE_REST_STOP",
    "A <SITE> adjacent to a <ROAD> usually having <FACILITY>s for <HUMAN>s"
    " and/or <MOTOR_VEHICLE>s; a roadside rest stop.",
    3, &(EGBindingForEC[1052]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ135]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROCK,
    "ROCK", "ECC_ROCK",
    "A hard mineral <MATERIAL> that occurs in bulk as part of a <PLANET>"
    " and is either exposed at the <PLANETARY_SURFACE> or located"
    " underneath; rock [SOED, \"rock\", n.1.3].",
    3, &(EGBindingForEC[1109]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD130]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROCK_DROP,
    "ROCK_DROP", "ECC_ROCK_DROP",
    "A massive assemblage of <MATERIAL>, usually in the form of large"
    " concrete blocks and/or cylinders, suspended above or beside a"
    " <LAND_TRANSPORTATION_ROUTE>, ready to be activated as a potential"
    " <BARRIER>; a rock drop.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROCK_SHED,
    "ROCK_SHED", "ECC_ROCK_SHED",
    "A <PROTECTION_SHED> against slides of <ROCK>; a rock shed.",
    3, &(EGBindingForEC[1038]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A, AL210]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROCKY_LANDMARK,
    "ROCKY_LANDMARK", "ECC_ROCKY_LANDMARK",
    "An isolated rocky formation or single large <ROCK> that is located in"
    " its entirety above the high water mark of a <WATERBODY_SURFACE>, that"
    " is conspicuous and would appear to a mariner as a single <LOCATION>"
    " on <LAND>, and that would be appropriate for use in marine"
    " navigation; a rocky landmark.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB161]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROCKY_OUTCROP,
    "ROCKY_OUTCROP", "ECC_ROCKY_OUTCROP",
    "An outcrop, layers (strata), or beds of <ROCK> on <LAND>; a rocky"
    " outcrop.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB160]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RODENT,
    "RODENT", "ECC_RODENT",
    "A <MAMMAL> of the order Rodentia, the members of which are"
    " characterized by strong continuously-growing incisor teeth and no"
    " canines; a rodent [SOED,\"rodent\", A]. EXAMPLES Rat, mouse,"
    " squirrel, vole, beaver.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROLLING_BLOCK,
    "ROLLING_BLOCK", "ECC_ROLLING_BLOCK",
    "A massive assemblage of <MATERIAL> (usually in the form of concrete"
    " blocks or cylinders) that is positioned alongside a"
    " <LAND_TRANSPORTATION_ROUTE> and is ready to be activated when needed"
    " as a potential <BARRIER> to an advancing enemy ground force; a"
    " rolling block.",
    3, &(EGBindingForEC[1024]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ068]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROOF,
    "ROOF", "ECC_ROOF",
    "The outside upper covering of a <BUILDING>; a building roof [SOED,"
    " \"roof\", 1.a].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROOF_ASSEMBLY,
    "ROOF_ASSEMBLY", "ECC_ROOF_ASSEMBLY",
    "A <ROOF> and its structural support; a roof assembly.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROOM,
    "ROOM", "ECC_ROOM",
    "An interior portion of a <BUILDING> that is divided off by"
    " <BUILDING_COMPONENT>s (for example: <WALL>s, <ROOM_CEILING>s, room"
    " <FLOOR>s, and/or partitions); a room [SOED, \"room\", 8.a].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROOM_CEILING,
    "ROOM_CEILING", "ECC_ROOM_CEILING",
    "The overhead inside lining or suspended undercovering of a <ROOM>; a"
    " room ceiling.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"ceiling\", 4]", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROUNDHOUSE,
    "ROUNDHOUSE", "ECC_ROUNDHOUSE",
    "A circular <BUILDING> containing a <RAILWAY_TURNTABLE>; a roundhouse"
    " [AHD, \"roundhouse\", 1].",
    3, &(EGBindingForEC[1038]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROUTE,
    "ROUTE", "ECC_ROUTE",
    "A way or course of (especially regular) travel from one <LOCATION> to"
    " another <LOCATION>; a route [SOED, \"route\", 1a.].",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GA045, FC165]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROUTE_COMPONENT,
    "ROUTE_COMPONENT", "ECC_ROUTE_COMPONENT",
    "A <COMPONENT> of a <ROUTE>.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROUTE_CONSTRICTION,
    "ROUTE_CONSTRICTION", "ECC_ROUTE_CONSTRICTION",
    "A <LOCATION> where a <ROUTE> narrows from its normal <<WIDTH>>; a"
    " constriction.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A, AQ058]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROUTE_EXPANSION,
    "ROUTE_EXPANSION", "ECC_ROUTE_EXPANSION",
    "A <LOCATION> where a <ROUTE> widens beyond its normal <<WIDTH>>; an"
    " expansion.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A, AQ058]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROUTE_LANE,
    "ROUTE_LANE", "ECC_ROUTE_LANE",
    "A <COMPONENT> of a <LAND_TRANSPORTATION_ROUTE> that is typically"
    " designated by painted lines, is used to segregate the flow of"
    " <GROUND_VEHICLE>s according to speed or intended <DIRECTION>, and has"
    " enough <<WIDTH>> to pass a single file of <GROUND_VEHICLE>s; a route"
    " lane [SOED, \"lane\", 2.d].",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROUTE_SHOULDER,
    "ROUTE_SHOULDER", "ECC_ROUTE_SHOULDER",
    "A <TERRAIN_STRIP> along either side of and adjacent to a <ROAD> or"
    " <RUNWAY> and not normally used by <MOTOR_VEHICLE>s or <AIRCRAFT> but"
    " provided as an allowable margin in case of emergencies; a route"
    " shoulder.",
    4, &(EGBindingForEC[237]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB057]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROUTE_WIDTH_CHANGE,
    "ROUTE_WIDTH_CHANGE", "ECC_ROUTE_WIDTH_CHANGE",
    "A <LOCATION> where a <ROUTE> narrows or expands in <<WIDTH>>.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ058]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ROWHOUSE,
    "ROWHOUSE", "ECC_ROWHOUSE",
    "One of a series of essentially identical residential <BUILDING>s"
    " situated side by side and sharing a common <WALL>; a row house.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUBBLE,
    "RUBBLE", "ECC_RUBBLE",
    "The rubbish of decayed or demolished <STRUCTURE>s, especially"
    " including fragments of brick or <STONE>; rubble [SOED, \"rubble\", 1].",
    1, &(EGBindingForEC[33]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUINS,
    "RUINS", "ECC_RUINS",
    "The deteriorated remains of an unspecified <STRUCTURE>; a ruin.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL200]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUN_OFF,
    "RUN_OFF", "ECC_RUN_OFF",
    "<WATER> that is carried off a <TRACT> by <RIVER>s after having fallen"
    " as <RAIN>; run-off.",
    2, &(EGBindingForEC[872]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"run-off\", 2.b]", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY,
    "RUNWAY", "ECC_RUNWAY",
    "A defined <TRACT>, usually rectangular, used for the conventional"
    " landing and take-off of <AIRCRAFT>; a runway. The <RUNWAY_STOPWAY> is"
    " excluded from this <TRACT>.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB055]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_APPROACH_OIS,
    "RUNWAY_APPROACH_OIS", "ECC_RUNWAY_APPROACH_OIS",
    "An imaginary air navigation OIS consisting of an inclined plane,"
    " symmetrical about the centre-line of the <RUNWAY>, beginning 60,96"
    " metres (200 feet) outward of the <RUNWAY_ENDPOINT>, at the"
    " <<TERRAIN_ELEVATION>> of the <RUNWAY_ENDPOINT>, and extending for 12"
    " 903,04 metres (42 332 feet, or 7 nautical miles minus 200 feet of"
    " <RUNWAY_PRIMARY_OIS>); a Runway Approach OIS. The slope of this"
    " <SURFACE> is 50 to 1 along the centre-line of the <RUNWAY> extended"
    " until it reaches a height of 152,4 metres (500 feet) above the"
    " <<TERRAIN_ELEVATION>> of the <RUNWAY_ENDPOINT> with the lowest"
    " <<TERRAIN_ELEVATION>> on the <AIRPORT>. It then continues"
    " horizontally to a point 12 964 metres (42 532 feet or 7 nautical"
    " miles) from the <RUNWAY_ENDPOINT>. The <<WIDTH>> of this <SURFACE> at"
    " the <RUNWAY_ENDPOINT> is the same as the <RUNWAY_PRIMARY_OIS>, it"
    " flares uniformly, and the <<WIDTH>> at 12 964 metres (42 532 feet)"
    " distance is 4 236,4 metres (13 899 feet).",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA071]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_CONICAL_OIS,
    "RUNWAY_CONICAL_OIS", "ECC_RUNWAY_CONICAL_OIS",
    "An imaginary air navigation OIS extending from the periphery of the"
    " <RUNWAY_INNER_HORIZONTAL_OIS> outward and upward at a slope of 20 to"
    " 1 for a horizontal distance of 2 133,6 metres (7 000 feet) to a"
    " height of 152,4 metres (500 feet) above the height of the lowest"
    " height <RUNWAY_ENDPOINT> and 4 419,6 metres (14 500 feet) from the"
    " centre-line of the <RUNWAY>; a Runway Conical OIS.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA074]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_CONICAL_OUTER_HORIZONTAL_TRANSITIONAL_OIS,
    "RUNWAY_CONICAL_OUTER_HORIZONTAL_TRANSITIONAL_OIS", "ECC_RUNWAY_CONICAL_OUTER_HORIZONTAL_TRANSITIONAL_OIS",
    "An imaginary air navigation OIS connecting the side of the"
    " <RUNWAY_APPROACH_OIS> to the sides of both the <RUNWAY_CONICAL_OIS>"
    " and <RUNWAY_OUTER_HORIZONTAL_OIS>; a runway conical outer horizontal"
    " transitional OIS. This triangular <SURFACE> extends outward,"
    " perpendicular to the extended centre-line of the <RUNWAY> from the"
    " edges of the <RUNWAY_APPROACH_OIS>, at a 7 to 1 slope. The slope of"
    " this <SURFACE> is referenced to the centre-line of the <RUNWAY>.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA076]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_DISPLACED_THRESHOLD,
    "RUNWAY_DISPLACED_THRESHOLD", "ECC_RUNWAY_DISPLACED_THRESHOLD",
    "The designated beginning of the portion of a <RUNWAY> usable for"
    " landing that is located at a point on the <RUNWAY> other than the"
    " designated <RUNWAY_ENDPOINT>, and typically exists at each end of the"
    " <RUNWAY>; a runway displaced threshold.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_ENDPOINT,
    "RUNWAY_ENDPOINT", "ECC_RUNWAY_ENDPOINT",
    "One of the <LOCATION>s at each end of the centre-line of a <RUNWAY>; a"
    " runway endpoint.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB056]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_INNER_HORIZONTAL_OIS,
    "RUNWAY_INNER_HORIZONTAL_OIS", "ECC_RUNWAY_INNER_HORIZONTAL_OIS",
    "An imaginary air navigation OIS defined by two half circles centred on"
    " the <RUNWAY_ENDPOINT>s and joined by tangents; a runway inner"
    " horizontal OIS. The <<RADIUS>>s of the half circles are 2 286 metres"
    " (7 500 feet) and the tangents are parallel to the centre-line of the"
    " <RUNWAY> at a distance of 2 286 metres (7 500 feet). This <SURFACE>"
    " extends horizontally outward from the periphery of the"
    " <RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS> at a <<TERRAIN_ELEVATION>>"
    " of 45,7 metres (150 feet) above the <<TERRAIN_ELEVATION>> of the"
    " <RUNWAY_ENDPOINT> of lowest <<TERRAIN_ELEVATION>>.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA073]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_MARKINGS,
    "RUNWAY_MARKINGS", "ECC_RUNWAY_MARKINGS",
    "A symbol or group of symbols (for example: threshold markings, runway"
    " side stripes, and/or <CENTRE_LINE>s) displayed on the surface of a"
    " <RUNWAY> to convey aeronautical information.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_INFORMATIVE, "[IAN14, \"markings\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_NEXUS,
    "RUNWAY_NEXUS", "ECC_RUNWAY_NEXUS",
    "A representation of one or more <RUNWAY>s; a runway centre-line or"
    " runway nexus.",
    3, &(EGBindingForEC[244]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_OUTER_HORIZONTAL_OIS,
    "RUNWAY_OUTER_HORIZONTAL_OIS", "ECC_RUNWAY_OUTER_HORIZONTAL_OIS",
    "An imaginary air navigation OIS consisting of a horizontal plane,"
    " located 152,4 metres (500 feet) above the <<TERRAIN_ELEVATION>> of"
    " the <RUNWAY_ENDPOINT> with the lowest <<TERRAIN_ELEVATION>>,"
    " extending outward from the outer periphery of the"
    " <RUNWAY_CONICAL_OIS> for a horizontal distance of 8 544,2 metres (28"
    " 032 feet) reaching a distance of 19 963,8 metres (42 532 feet) from"
    " the centre-line of the <RUNWAY>; a runway outer horizontal OIS.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA075]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_OVERRUN,
    "RUNWAY_OVERRUN", "ECC_RUNWAY_OVERRUN",
    "In military aviation exclusively, a stabilized or paved <TRACT>"
    " immediately beyond the end of a <RUNWAY>, of the same <<WIDTH>> as"
    " the <RUNWAY> plus <ROUTE_SHOULDER>s, centred on the extended"
    " centre-line of the <RUNWAY>.",
    3, &(EGBindingForEC[251]),
    EDCS_REF_TYP_INFORMATIVE, "[F7110.65]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS,
    "RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS", "ECC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS",
    "An imaginary air navigation OIS connecting the sides of the"
    " <RUNWAY_PRIMARY_OIS> and <RUNWAY_APPROACH_OIS> to the"
    " <RUNWAY_INNER_HORIZONTAL_OIS>; a runway primary approach transitional"
    " OIS. This <SURFACE> extends outward, perpendicular to the centre-line"
    " of the <RUNWAY>, from the edges of the <RUNWAY_PRIMARY_OIS>, at a"
    " slope of 7 to 1, to a <<WIDTH>> of 320 metres (1 050 feet) and a"
    " <<TERRAIN_ELEVATION>> of 45,7 metres (150 feet) above the"
    " <<TERRAIN_ELEVATION>> of the <RUNWAY_ENDPOINT> of lowest"
    " <<TERRAIN_ELEVATION>>.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA072]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_PRIMARY_OIS,
    "RUNWAY_PRIMARY_OIS", "ECC_RUNWAY_PRIMARY_OIS",
    "An imaginary air navigation OIS that is longitudinally centred on a"
    " <RUNWAY>, equal to the <<LENGTH>> of the <RUNWAY> plus 304,8 metres"
    " (1 000 feet) on each end, and of a <<WIDTH>> of 609,6 metres (2 000"
    " feet); a runway primary OIS.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_RADAR_REFLECTOR,
    "RUNWAY_RADAR_REFLECTOR", "ECC_RUNWAY_RADAR_REFLECTOR",
    "A <DEVICE>, normally placed near the threshold of a <RUNWAY>, used for"
    " reflecting radar signals; a runway radar reflector.",
    5, &(EGBindingForEC[202]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_STOPWAY,
    "RUNWAY_STOPWAY", "ECC_RUNWAY_STOPWAY",
    "A <TRACT> beyond the take-off <RUNWAY_ENDPOINT> that is designated as"
    " able to support an <AIRCRAFT> during an aborted take-off; a runway"
    " stopway.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB045]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_RUNWAY_TOUCHDOWN_ZONE,
    "RUNWAY_TOUCHDOWN_ZONE", "ECC_RUNWAY_TOUCHDOWN_ZONE",
    "The first 914,4 metres (3 000 feet) of the <RUNWAY> beginning at the"
    " <RUNWAY_DISPLACED_THRESHOLD>; a runway touchdown zone.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB046]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SABKHA,
    "SABKHA", "ECC_SABKHA",
    "A natural <TERRAIN_DEPRESSION> in an arid or semi-arid"
    " <TERRAIN_SURFACE_REGION> the bed of which is covered with salt"
    " encrusted clayey <SOIL>; a sabkha or sebkha.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH160]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAFARI_PARK,
    "SAFARI_PARK", "ECC_SAFARI_PARK",
    "An <ANIMAL_PARK> in which wild <NON_HUMAN_ANIMAL>s are allowed to roam"
    " free in an environment designed to resemble their natural habitat and"
    " are observed by visitors riding through the <PARK> in"
    " <MOTOR_VEHICLE>s; a safari park.",
    4, &(EGBindingForEC[345]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAFETY_FAIRWAY,
    "SAFETY_FAIRWAY", "ECC_SAFETY_FAIRWAY",
    "A <MARINE_ROUTE> established for the safe passage of <VESSEL>s through"
    " either offshore <PETROLEUM_FIELD>s or <MINEFIELD>s; a safety fairway.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FC170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAILING_VESSEL,
    "SAILING_VESSEL", "ECC_SAILING_VESSEL",
    "A <WATER_SURFACE_VESSEL> that is primarily moved by the force created"
    " by the effect of the <WIND> on attached sails; a sailing vessel or"
    " sailing ship.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"sailing vessel\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SALT_EVAPORATOR,
    "SALT_EVAPORATOR", "ECC_SALT_EVAPORATOR",
    "A shallow <RESERVOIR>, which is normally man-made, that is used for"
    " the natural evaporation of <WATER> for the collection of salt; a salt"
    " evaporator.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH155]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SALT_PAN,
    "SALT_PAN", "ECC_SALT_PAN",
    "A flat <TRACT> covered by natural salt deposits on its <SURFACE>; a"
    " salt-pan.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: SLTPAN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SANATORIUM,
    "SANATORIUM", "ECC_SANATORIUM",
    "A <FACILITY> that houses an institution for the treatment of chronic"
    " diseases or for medically supervised recuperation; a sanatorium.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"sanatorium\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAND,
    "SAND", "ECC_SAND",
    "A <MATERIAL> consisting of fine <PARTICLE>s of <ROCK>s (mainly"
    " siliceous); sand [SOED, \"sand\", 1.a].",
    2, &(EGBindingForEC[1107]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAND_BAR,
    "SAND_BAR", "ECC_SAND_BAR",
    "A bar and/or low <RIDGE> of <SAND> along the <SHORE> of a <LAKE>,"
    " <RIVER>, or <OCEAN> that is built-up to the <WATERBODY_SURFACE> by"
    " <WATER_WAVE>s or <WATER_CURRENT>s.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"sand-bar\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAND_DUNE,
    "SAND_DUNE", "ECC_SAND_DUNE",
    "A mound or <RIDGE> of loose <SAND> formed by the <WIND>; a sand dune"
    " [SOED, \"dune\"].",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAND_DUNE_REGION,
    "SAND_DUNE_REGION", "ECC_SAND_DUNE_REGION",
    "A <TRACT> covered by <SAND_DUNE>s; a sand dune region.",
    2, &(EGBindingForEC[1131]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAND_LINE,
    "SAND_LINE", "ECC_SAND_LINE",
    "A <LINE> that delineates a <TRACT> of <SAND> from an adjacent"
    " <WATERBODY> and that is covered and uncovered depending on the"
    " <<ELEVATION>> of its <SURFACE> and the current <<ELEVATION>> of the"
    " <WATERBODY_SURFACE>; a sand line.",
    4, &(EGBindingForEC[529]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BE022]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SATELLITE,
    "SATELLITE", "ECC_SATELLITE",
    "A <CELESTIAL_BODY> that revolves around a larger <CELESTIAL_BODY>,"
    " usually a <PLANET>; a satellite [SOED, \"satellite\", A.2.a].",
    2, &(EGBindingForEC[77]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SATELLITE_GROUND_STATION,
    "SATELLITE_GROUND_STATION", "ECC_SATELLITE_GROUND_STATION",
    "A <STRUCTURE> with an associated <AERIAL> used for tracking, control,"
    " transmission, and/or reception of signals from"
    " <ARTIFICIAL_SATELLITE>s; a satellite ground station.",
    4, &(EGBindingForEC[462]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:107]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SATURN,
    "SATURN", "ECC_SATURN",
    "The primary <PLANET> of the <SUN> that is sixth in distance from the"
    " <SUN>, with an orbital mean <<RADIUS>> of approximately 1 429,4"
    " million kilometres; Saturn.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SAWMILL,
    "SAWMILL", "ECC_SAWMILL",
    "A <BUILDING> where <LOG>s are processed into lumber; a sawmill.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"sawmill\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SCENIC_LOOKOUT,
    "SCENIC_LOOKOUT", "ECC_SCENIC_LOOKOUT",
    "A <LOCATION>, which is generally elevated, with <FACILITY>s for"
    " observing the scenery; a scenic lookout.",
    2, &(EGBindingForEC[1099]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK121]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SCHOOL_BUILDING,
    "SCHOOL_BUILDING", "ECC_SCHOOL_BUILDING",
    "A <BUILDING> used for instruction; a school building.",
    2, &(EGBindingForEC[984]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"school\", n1.I.1e]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SCIENCE_BUILDING,
    "SCIENCE_BUILDING", "ECC_SCIENCE_BUILDING",
    "A <BUILDING> supporting scientific experimentation or research,"
    " including scholarly investigation or inquiry, intended to ultimately"
    " result in commercial products; a science building.",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:59]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SCIENCE_FACILITY,
    "SCIENCE_FACILITY", "ECC_SCIENCE_FACILITY",
    "A <FACILITY> including one or more <SCIENCE_BUILDING>s; a science"
    " facility.",
    4, &(EGBindingForEC[949]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SCRAPYARD,
    "SCRAPYARD", "ECC_SCRAPYARD",
    "A <TRACT> used to collect scrap metal for reprocessing; a scrapyard.",
    4, &(EGBindingForEC[897]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"scrapyard\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SCRUB_LAND,
    "SCRUB_LAND", "ECC_SCRUB_LAND",
    "A <TRACT> covered by uncultured <PLANT>s that may have some woody"
    " tissue; scrub land or brush land.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EB015]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEA,
    "SEA", "ECC_SEA",
    "A salty <WATERBODY> more or less confined by continuous <LAND> or"
    " chains of <ISLAND>s and forming a distinct <REGION>; a sea.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEAL_POD,
    "SEAL_POD", "ECC_SEAL_POD",
    "A <POD> of seals.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEAMOUNT,
    "SEAMOUNT", "ECC_SEAMOUNT",
    "A <WATERBODY_FLOOR_PINNACLE> rising 1 000 metres or more from the"
    " <WATERBODY_FLOOR> of a <SEA> or <OCEAN> and of limited extent across"
    " its summit; a seamount.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"seamount\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEAPLANE,
    "SEAPLANE", "ECC_SEAPLANE",
    "An <AIRCRAFT> capable of taking off and landing on a"
    " <WATERBODY_SURFACE>; a seaplane [SOED, \"seaplane\"].",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEAPLANE_BASE,
    "SEAPLANE_BASE", "ECC_SEAPLANE_BASE",
    "A <FACILITY> supporting <SEAPLANE>s; a seaplane base.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB065]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEAPLANE_RUN,
    "SEAPLANE_RUN", "ECC_SEAPLANE_RUN",
    "A designated <REGION> of a <WATERBODY_SURFACE> outlined by visual"
    " markings used by <SEAPLANE>s to land and take off; a seaplane run.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEAWALL,
    "SEAWALL", "ECC_SEAWALL",
    "A <WALL> built to protect a <SHORE> from erosion; a seawall.",
    1, &(EGBindingForEC[19]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB230]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEAWEED,
    "SEAWEED", "ECC_SEAWEED",
    "A <REGION> of large green, brown, or dark red <VEGETATION> (for"
    " example: kelp and/or seaweed) growing in a salt <WATER>, typically"
    " cold, environment.",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEDIMENT,
    "SEDIMENT", "ECC_SEDIMENT",
    "Unconsolidated <MATERIAL> composed of <PARTICLE>s deposited from"
    " either a suspension in <AIR>, <ICE>, or <WATER> or from solution in"
    " <WATER>; sediment [SOED, \"sediment\", 3].",
    1, &(EGBindingForEC[33]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SELF_PROPELLED_ARTILLERY,
    "SELF_PROPELLED_ARTILLERY", "ECC_SELF_PROPELLED_ARTILLERY",
    "Self-propelled <FIELD_ARTILLERY>.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEMINARY,
    "SEMINARY", "ECC_SEMINARY",
    "A <FACILITY> used as a school, especially a theological school, for"
    " the training of priests, ministers, or rabbis; a seminary [AHD,"
    " \"seminary\", 1.a].",
    2, &(EGBindingForEC[1162]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SENIOR_CITIZENS_HOME,
    "SENIOR_CITIZENS_HOME", "ECC_SENIOR_CITIZENS_HOME",
    "A residential <BUILDING> housing a group of elderly <HUMAN>s; a senior"
    " citizens home.",
    2, &(EGBindingForEC[984]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:109]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SET,
    "SET", "ECC_SET",
    "A possibly empty collection of distinct <OBJECT>s; a set.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SETTLEMENT,
    "SETTLEMENT", "ECC_SETTLEMENT",
    "A concentration of <DWELLING>s that is smaller in size than a <TOWN>;"
    " a settlement or village.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AL105]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SETTLING_POND,
    "SETTLING_POND", "ECC_SETTLING_POND",
    "A small <RESERVOIR> where solid matter is precipitated from a liquid"
    " by evaporating or settling; a settling pond.",
    2, &(EGBindingForEC[895]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AC030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SEWER,
    "SEWER", "ECC_SEWER",
    "An artificial channel or conduit, usually covered and under the"
    " <TERRAIN>, for carrying off and discharging waste, storm <WATER>,"
    " and/or refuse from <BUILDING>s and <BUILT_UP_REGION>s; a sewer [SOED,"
    " \"sewer\", 2.a].",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHADOW,
    "SHADOW", "ECC_SHADOW",
    "A <REGION> of partial darkness produced by an <OBJECT> intercepting"
    " rays of light (for example: the direct rays of the <SUN>); a shadow.",
    1, &(EGBindingForEC[29]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"shadow\", A.I.1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHANTY_TOWN,
    "SHANTY_TOWN", "ECC_SHANTY_TOWN",
    "A <TOWN>, or a section of a <TOWN>, consisting chiefly of shacks; a"
    " shanty town.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"shanty town\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHARP_CURVE,
    "SHARP_CURVE", "ECC_SHARP_CURVE",
    "A curve along a <LAND_TRANSPORTATION_ROUTE> that may cause"
    " restrictions in traffic of <GROUND_VEHICLE>s; a sharp curve.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ118]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHEAR_WALL,
    "SHEAR_WALL", "ECC_SHEAR_WALL",
    "The <WALL> of the <EXCAVATION> within a <QUARRY> or <EXTRACTION_MINE>;"
    " a shear wall.",
    3, &(EGBindingForEC[518]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AA011]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHED,
    "SHED", "ECC_SHED",
    "A relatively small <BUILDING>, which usually has one or more open"
    " sides, that is typically used for storage; a shed.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL019]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHEERLEGS,
    "SHEERLEGS", "ECC_SHEERLEGS",
    "Two or three spars standing on end and lashed together aloft that"
    " serve as a derrick or tripod to lift heavy weights, to step or lower"
    " <MAST>s or stacks, or for similar marine purposes; sheer legs.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AF041]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHELLFISH_BED,
    "SHELLFISH_BED", "ECC_SHELLFISH_BED",
    "A <REGION> in a shallow <WATERBODY> where shellfish breed and may be"
    " cultivated; a shellfish bed.",
    3, &(EGBindingForEC[147]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB180]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHELTER,
    "SHELTER", "ECC_SHELTER",
    "A <STRUCTURE> for protecting <EQUIPMENT> or <HUMAN>s; a shelter.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHIPYARD,
    "SHIPYARD", "ECC_SHIPYARD",
    "A <SITE> where <VESSEL>s are built or repaired; a shipyard [SOED,"
    " \"shipyard\"].",
    4, &(EGBindingForEC[759]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHOAL,
    "SHOAL", "ECC_SHOAL",
    "A <MARINE_REGION> over which there is a <<WATER_DEPTH>> of twenty"
    " metres or less, and which is composed of unconsolidated <MATERIAL>,"
    " except <CORAL> or <ROCK>; a shoal.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"shoal (n.)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHOPPING_CENTRE,
    "SHOPPING_CENTRE", "ECC_SHOPPING_CENTRE",
    "A group of <RETAIL_FACILITY>s, often including <RESTAURANT>s and other"
    " businesses, having a common <VEHICLE_LOT>; a shopping centre [AHD,"
    " \"shopping center\"].",
    5, &(EGBindingForEC[931]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHORE,
    "SHORE", "ECC_SHORE",
    "The narrow <TERRAIN_STRIP> in immediate contact with a <WATERBODY>,"
    " including the <TRACT> between high and low water <LINE>s; a shore.",
    3, &(EGBindingForEC[533]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHORE_PROTECTION_STRUCTURE,
    "SHORE_PROTECTION_STRUCTURE", "ECC_SHORE_PROTECTION_STRUCTURE",
    "A <STRUCTURE> that protects a <HARBOUR> or <SHORE> from the forces of"
    " the <SEA>. EXAMPLES <BREAKWATER>, <GROIN>.",
    2, &(EGBindingForEC[743]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHORE_REVETMENT,
    "SHORE_REVETMENT", "ECC_SHORE_REVETMENT",
    "A <REVETMENT> placed along a <SHORE> to stabilize the <WATERBODY_BANK>"
    " and to protect it from the erosive action of flowing <WATER>.",
    2, &(EGBindingForEC[743]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB226]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHORELINE,
    "SHORELINE", "ECC_SHORELINE",
    "The <LAND_WATER_BOUNDARY> between the <SHORE> or <BEACH> and a defined"
    " mean water level; a shoreline. EXAMPLE The high water shoreline would"
    " be the <LAND_WATER_BOUNDARY> with mean high water.",
    2, &(EGBindingForEC[524]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHORELINE_CONSTRUCTION,
    "SHORELINE_CONSTRUCTION", "ECC_SHORELINE_CONSTRUCTION",
    "A fixed (not afloat) artificial <STRUCTURE> attached to a <SHORE> and"
    " normally used for berthing and protection of <VESSEL>s; a shoreline"
    " construction.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: SLCONS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHORELINE_LANDING_PLACE,
    "SHORELINE_LANDING_PLACE", "ECC_SHORELINE_LANDING_PLACE",
    "A <REGION> on a <SHORE> where landing from a <WATERBODY> is possible;"
    " a shoreline landing place.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: LNDPLC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHORELINE_LANDING_STAIR,
    "SHORELINE_LANDING_STAIR", "ECC_SHORELINE_LANDING_STAIR",
    "A <STAIR> on a <SHORE> constructed to connect between the <LAND> and"
    " the <WATERBODY> on different levels; a shoreline landing stair.",
    1, &(EGBindingForEC[19]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: LNDSTS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHOVEL,
    "SHOVEL", "ECC_SHOVEL",
    "<EQUIPMENT> for <EXCAVATION> that moves <MATERIAL>s by a scooping"
    " action; a shovel.",
    2, &(EGBindingForEC[586]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHRIMP_BED,
    "SHRIMP_BED", "ECC_SHRIMP_BED",
    "A naturally occurring, significant grouping of shrimp that persists"
    " over a significant period; a shrimp bed.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHRINE,
    "SHRINE", "ECC_SHRINE",
    "A <WORSHIP_PLACE> or place for devotion; a shrine [SOED, \"shrine\","
    " 6].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SHRUB,
    "SHRUB", "ECC_SHRUB",
    "A low growing, multi-stemmed woody <PLANT>; a shrub [AHD, \"shrub\"].",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SIDEWALK,
    "SIDEWALK", "ECC_SIDEWALK",
    "A paved pedestrian walkway, usually made of concrete, typically"
    " located adjacent and parallel to a <ROAD>; a sidewalk.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"sidewalk\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SIPHON,
    "SIPHON", "ECC_SIPHON",
    "A <PIPE> used for conveying liquid from one level to a lower level,"
    " using the liquid pressure differential to force a column of the"
    " liquid up to a higher level before it falls to the outlet; a siphon"
    " [SOED, \"siphon\", 2.a].",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AJ020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SITE,
    "SITE", "ECC_SITE",
    "The <LOCATION> of an actual or planned <NON_EMPTY_SET> of"
    " <STRUCTURE>s; a site [AHD, \"site\", 1].",
    1, &(EGBindingForEC[32]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SKI_JUMP,
    "SKI_JUMP", "ECC_SKI_JUMP",
    "A <RAMP> used for ski jumping; a ski jump.",
    1, &(EGBindingForEC[39]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK150]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SKI_TRACK,
    "SKI_TRACK", "ECC_SKI_TRACK",
    "A <ROUTE> prepared for skiing; a ski track.",
    4, &(EGBindingForEC[1008]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AK155]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SKYLIGHT,
    "SKYLIGHT", "ECC_SKYLIGHT",
    "A small <APERTURE> filled in with a transparent or translucent"
    " <MATERIAL> (for example: glass) that admits daylight through a <ROOF>"
    " and/or <ROOM_CEILING>; a skylight.",
    2, &(EGBindingForEC[411]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"skylight\", 2]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SLIPWAY,
    "SLIPWAY", "ECC_SLIPWAY",
    "A <RAMP> for launching and recovering <VESSEL>s; a slipway or patent"
    " slip.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: SLIPWY]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SLOPE_REGION,
    "SLOPE_REGION", "ECC_SLOPE_REGION",
    "A <TERRAIN_SURFACE_REGION> where the <<TERRAIN_SLOPE>> is within a set"
    " range of values.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB176]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SLUDGE_GATE,
    "SLUDGE_GATE", "ECC_SLUDGE_GATE",
    "A <GATE> used to regulate the flow of sludge from a <SETTLING_POND>; a"
    " sludge gate.",
    2, &(EGBindingForEC[895]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SLUICE,
    "SLUICE", "ECC_SLUICE",
    "An open, inclined conduit for <WATER> that is fitted with a"
    " <SLUICE_GATE> and may be employed in mine ore washing operations; a"
    " sluice.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI039]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SLUICE_GATE,
    "SLUICE_GATE", "ECC_SLUICE_GATE",
    "A <GATE> used to regulate the flow of <WATER> in a <SLUICE>; a sluice"
    " gate.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BI040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SMALL_CRAFT_FACILITY,
    "SMALL_CRAFT_FACILITY", "ECC_SMALL_CRAFT_FACILITY",
    "A <FACILITY> with functions or services generally of interest for"
    " small craft or pleasure <WATER_SURFACE_VESSEL>s.",
    4, &(EGBindingForEC[831]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB201]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SMALL_HAIL,
    "SMALL_HAIL", "ECC_SMALL_HAIL",
    "<HAIL> with an <<OUTSIDE_DIAMETER>> less than 0,64 centimetre, which"
    " is a form of <ICE_PELLETS>; small hail (US).",
    2, &(EGBindingForEC[376]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"small hail\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SMOKE,
    "SMOKE", "ECC_SMOKE",
    "A visible <NON_AQUEOUS_CLOUD>, <PLUME>, or <PUFF> composed of carbon"
    " and other <PARTICLE>s given off by burning or smouldering"
    " <MATERIAL>s; smoke [SOED, \"smoke\", A.1].",
    2, &(EGBindingForEC[273]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SMOKESTACK,
    "SMOKESTACK", "ECC_SMOKESTACK",
    "A <COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE> consisting of a large, tall"
    " <PIPE> which is often free-standing; a smokestack [AHD,"
    " \"smokestack\"].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SNAG,
    "SNAG", "ECC_SNAG",
    "A stem or trunk of a <TREE> below a <WATERBODY_SURFACE>; a snag.",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BD140]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SNOW_GRAINS,
    "SNOW_GRAINS", "ECC_SNOW_GRAINS",
    "<SOLID_PRECIPITATION> of very small opaque white <PARTICLE>s of <ICE>"
    " that fall from a <CLOUD> and are fairly flat or elongated with"
    " <<OUTSIDE_DIAMETER>>s generally less than 1 millimetre; the solid"
    " equivalent of <DRIZZLE>; snow grains.",
    3, &(EGBindingForEC[378]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"snow grains\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SNOW_GROUND_COVER,
    "SNOW_GROUND_COVER", "ECC_SNOW_GROUND_COVER",
    "The layer formed by <SNOW_PRECIPITATION> as it accumulates on the"
    " <LAND>; snow ground cover.",
    3, &(EGBindingForEC[880]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SNOW_PRECIPITATION,
    "SNOW_PRECIPITATION", "ECC_SNOW_PRECIPITATION",
    "<SOLID_PRECIPITATION> composed of white or translucent crystals of"
    " <ICE> that are chiefly in complex branch hexagonal form and are often"
    " agglomerated into snowflakes or the layer formed by them on the"
    " <LAND>; snow.",
    3, &(EGBindingForEC[378]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"snow\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SNOW_REGION,
    "SNOW_REGION", "ECC_SNOW_REGION",
    "A <REGION> in which <SNOW_PRECIPITATION> is falling.",
    2, &(EGBindingForEC[376]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SNOW_SHED,
    "SNOW_SHED", "ECC_SNOW_SHED",
    "A <PROTECTION_SHED> against slides of <SNOW_GROUND_COVER>; a snow shed.",
    4, &(EGBindingForEC[876]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A, AL210]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SNOWFIELD,
    "SNOWFIELD", "ECC_SNOWFIELD",
    "A <TRACT> covered by <SNOW_GROUND_COVER>; a snowfield.",
    3, &(EGBindingForEC[888]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"snowfield\", 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SODA_EVAPORATOR,
    "SODA_EVAPORATOR", "ECC_SODA_EVAPORATOR",
    "A shallow <RESERVOIR>, normally man-made, used for the natural"
    " evaporation of <WATER> for the collection of soda; soda evaporator.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOIL,
    "SOIL", "ECC_SOIL",
    "A <MATERIAL> composed of fragmented <PARTICLE>s of <ROCK>, decomposed"
    " <PLANT>s, <WATER>, and <AIR> that typically comprises a thin top"
    " layer of the <LAND>; soil [SOED, \"soil\", 4].",
    3, &(EGBindingForEC[1109]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOLAR_PANEL,
    "SOLAR_PANEL", "ECC_SOLAR_PANEL",
    "A <NON_EMPTY_SET> of solar cells for converting sunlight into"
    " electrical energy or heat; a solar panel.",
    3, &(EGBindingForEC[639]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AD020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOLAR_SYSTEM,
    "SOLAR_SYSTEM", "ECC_SOLAR_SYSTEM",
    "A <STAR> and its family of <PLANET>s, natural <SATELLITE>s,"
    " <ASTEROID>s, and <COMET>s that are captured by its gravity; a solar"
    " system.",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOLID_MESH,
    "SOLID_MESH", "ECC_SOLID_MESH",
    "A <MESH> with a related <MESH_SOLID_SET>; a solid mesh.",
    1, &(EGBindingForEC[6]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOLID_PRECIPITATION,
    "SOLID_PRECIPITATION", "ECC_SOLID_PRECIPITATION",
    "<PRECIPITATION> of <ICE>; solid precipitation.",
    3, &(EGBindingForEC[378]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOUND_CHANNEL,
    "SOUND_CHANNEL", "ECC_SOUND_CHANNEL",
    "A horizontal layer in a <WATERBODY> that is bounded by levels at which"
    " the <<WATERBODY_SOUND_SPEED>> is greater than at any level within the"
    " layer; a sound channel.",
    2, &(EGBindingForEC[101]),
    EDCS_REF_TYP_INFORMATIVE, "[PUWS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOUND_CHANNEL_AXIS,
    "SOUND_CHANNEL_AXIS", "ECC_SOUND_CHANNEL_AXIS",
    "The alignment axis in a <SOUND_CHANNEL> determined by the depth at"
    " which the minimum <<WATERBODY_SOUND_SPEED>> occurs.",
    2, &(EGBindingForEC[101]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"sound channel axis\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOUNDING,
    "SOUNDING", "ECC_SOUNDING",
    "A measured <<WATER_DEPTH>> or spot <<WATER_DEPTH>>; a sounding.",
    2, &(EGBindingForEC[1182]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: SOUNDG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SOUNDING_DATUM,
    "SOUNDING_DATUM", "ECC_SOUNDING_DATUM",
    "The vertical, typically tidal, <SURFACE_DATUM> to which <SOUNDING>s"
    " and <<HYDROGRAPHIC_DRYING_HEIGHT>>s are referenced; usually taken to"
    " correspond to a low water stage of the <TIDE>; the sounding datum.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Attribute: VERDAT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPACE,
    "SPACE", "ECC_SPACE",
    "The <REGION> extending in all <DIRECTION>s in which all matter lying"
    " outside celestial body <ATMOSPHERE>s is located; the near vacuum"
    " occupying the <REGION>s between <CELESTIAL_BODY>s; space [SOED,"
    " \"space\", II.12.a].",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPACECRAFT,
    "SPACECRAFT", "ECC_SPACECRAFT",
    "A <VEHICLE> operating mainly in <SPACE>; a spacecraft [SOED,"
    " \"spacecraft\"].",
    3, &(EGBindingForEC[1173]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPACEPORT,
    "SPACEPORT", "ECC_SPACEPORT",
    "A <FACILITY> for the launch, and sometimes the landing, of"
    " <SPACECRAFT>; a spaceport [SOED, \"spaceport\"].",
    3, &(EGBindingForEC[1170]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPECIAL_ELECTRONIC_WINGED_AIRCRAFT,
    "SPECIAL_ELECTRONIC_WINGED_AIRCRAFT", "ECC_SPECIAL_ELECTRONIC_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed or designated for special electronic"
    " operations.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPECIAL_OPERATIONS_HELICOPTER,
    "SPECIAL_OPERATIONS_HELICOPTER", "ECC_SPECIAL_OPERATIONS_HELICOPTER",
    "A <HELICOPTER> designed or designated for special operations.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPECIAL_USE_AIRSPACE,
    "SPECIAL_USE_AIRSPACE", "ECC_SPECIAL_USE_AIRSPACE",
    "An <AIRSPACE> identified by a delimited <REGION> where activities must"
    " be confined because of their nature and/or where limitations may be"
    " imposed on <AIRCRAFT> operations not associated with those"
    " activities; a special use airspace.",
    3, &(EGBindingForEC[267]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GA015]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPECIAL_USE_AIRSPACE_COMPONENT,
    "SPECIAL_USE_AIRSPACE_COMPONENT", "ECC_SPECIAL_USE_AIRSPACE_COMPONENT",
    "A <COMPONENT> of a <SPECIAL_USE_AIRSPACE>.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GA025]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPILLWAY,
    "SPILLWAY", "ECC_SPILLWAY",
    "A passage for surplus <WATER> to run over or around a <DAM>; a"
    " spillway.",
    2, &(EGBindingForEC[848]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH165]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPORTS_ARENA,
    "SPORTS_ARENA", "ECC_SPORTS_ARENA",
    "An arena with tiered seats or terraces for spectators of athletic or"
    " sporting events [SOED, \"stadium\", 3].",
    1, &(EGBindingForEC[39]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK160]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPOT_ELEVATION,
    "SPOT_ELEVATION", "ECC_SPOT_ELEVATION",
    "A designated <LOCATION> with an <<ELEVATION>>; a spot elevation.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: CA030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPRING,
    "SPRING", "ECC_SPRING",
    "A natural outflow of <WATER> from below the <LAND>; a spring.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: SPRING]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SPRING_TIDE,
    "SPRING_TIDE", "ECC_SPRING_TIDE",
    "The <TIDE>s of increased range occurring near the times of the full"
    " and new <<MOON_PHASE>>s.",
    2, &(EGBindingForEC[1072]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"tide(s): spring\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STADIUM,
    "STADIUM", "ECC_STADIUM",
    "A <SPORTS_ARENA> or a <TRACT> used for athletic sports with tiered"
    " seats or terraces for spectators; a stadium [SOED, \"stadium\", 3].",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK160]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STAIR,
    "STAIR", "ECC_STAIR",
    "A series of fixed steps leading from one level to another, especially"
    " such a series leading from one <FLOOR_LEVEL> to another inside a"
    " <STRUCTURE>; a stair [SOED, \"star\", A.I.1].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ150]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STAIR_SET,
    "STAIR_SET", "ECC_STAIR_SET",
    "A <NON_EMPTY_SET> of <STAIR>s connecting three or more <FLOOR_LEVEL>s"
    " in an uninterrupted sequence.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STAKE,
    "STAKE", "ECC_STAKE",
    "A small <MARKER> used to identify <WATER_CHANNEL>s or to mark dangers"
    " (for example: <STONE>s and/or <SHOAL>s); a stake.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BC080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STAR,
    "STAR", "ECC_STAR",
    "A large, coherent, roughly spherical, gaseous <CELESTIAL_BODY> that is"
    " luminous by virtue of internal nuclear reactions; a star [SOED,"
    " \"star\", A.I.1].",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STATIONARY_FRONT,
    "STATIONARY_FRONT", "ECC_STATIONARY_FRONT",
    "An <ATMOSPHERIC_FRONT> between warm and cold <AIR_MASS>s that is"
    " moving at a speed less than 2,575 metres per second (five knots); a"
    " stationary front or a quasi-stationary front.",
    4, &(EGBindingForEC[358]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"stationary front\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STEEL_MILL,
    "STEEL_MILL", "ECC_STEEL_MILL",
    "A <FACILITY> for the production of fabricated structural steel"
    " products (for example: girders and/or plates); a steel mill.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"steel mill\", c]", EDCS_CONCEPT_STAT_ISO },

    {ECC_STEEP_GRADE,
    "STEEP_GRADE", "ECC_STEEP_GRADE",
    "A stretch along a <LAND_TRANSPORTATION_ROUTE> where the slope is high"
    " enough to slow, hinder, or even stop traffic; a steep grade.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ120]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STEEPLE,
    "STEEPLE", "ECC_STEEPLE",
    "A <STRUCTURE>, usually topped by a point, that may be erected on the"
    " <ROOF> of a <BUILDING>; a steeple.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL220]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STELLAR_BURST_RADIO_FREQUENCY_EMISSION,
    "STELLAR_BURST_RADIO_FREQUENCY_EMISSION", "ECC_STELLAR_BURST_RADIO_FREQUENCY_EMISSION",
    "A burst emission from a <STAR> at radio <<WAVELENGTH>>s that often"
    " sweep through a range of <<FREQUENCY>>s and last from minutes to"
    " days; a stellar burst radio frequency emission.",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_INFORMATIVE, "[SEC, \"burst\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STELLAR_ENERGETIC_PARTICLE,
    "STELLAR_ENERGETIC_PARTICLE", "ECC_STELLAR_ENERGETIC_PARTICLE",
    "An energetic charged <PARTICLE> emanating from a <STAR>; a stellar"
    " energetic particle. EXAMPLES Electron, proton, alpha <PARTICLE>.",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {ECC_STELLAR_FLUX_RADIO_FREQUENCY_EMISSION,
    "STELLAR_FLUX_RADIO_FREQUENCY_EMISSION", "ECC_STELLAR_FLUX_RADIO_FREQUENCY_EMISSION",
    "A continuous (flux) emission from a <STAR> at radio <<WAVELENGTH>>s; a"
    " stellar flux radio frequency emission.",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {ECC_STELLAR_WIND,
    "STELLAR_WIND", "ECC_STELLAR_WIND",
    "A high-speed stream of <STELLAR_ENERGETIC_PARTICLE>s in <SPACE>; a"
    " stellar wind.",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_INFORMATIVE, "[GSTT, \"solar wind\"]",
    "[SEC, \"solar wind\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_STONE,
    "STONE", "ECC_STONE",
    "A piece of <ROCK> of a small or moderate size; a stone [SOED,"
    " \"stone\", A.1.a] or rock (US).",
    3, &(EGBindingForEC[1109]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STORAGE_BUNKER,
    "STORAGE_BUNKER", "ECC_STORAGE_BUNKER",
    "A <BUNKER> that is used as a <STORAGE_STRUCTURE>; a storage bunker or"
    " storage mound.",
    2, &(EGBindingForEC[1121]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AM060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STORAGE_CONTAINER,
    "STORAGE_CONTAINER", "ECC_STORAGE_CONTAINER",
    "A <CONTAINER> used for the storage of solid, liquid, or gaseous"
    " <MATERIAL>s; a storage container.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AM011]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STORAGE_DEPOT,
    "STORAGE_DEPOT", "ECC_STORAGE_DEPOT",
    "A <FACILITY> including one of more <STORAGE_STRUCTURE>s; a storage"
    " depot.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AM010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STORAGE_PIT,
    "STORAGE_PIT", "ECC_STORAGE_PIT",
    "An excavated <STORAGE_STRUCTURE> that is lined by an impermeable"
    " <MATERIAL> and surrounded with <SOIL>; a storage pit.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STORAGE_STRUCTURE,
    "STORAGE_STRUCTURE", "ECC_STORAGE_STRUCTURE",
    "A <STRUCTURE> intended for storing <MATERIAL>s or products; a storage"
    " structure.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AM060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STORAGE_TANK,
    "STORAGE_TANK", "ECC_STORAGE_TANK",
    "A <CONTAINER> used for the storage of liquids or gases; a storage tank.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: TNKCON]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRATOPAUSE,
    "STRATOPAUSE", "ECC_STRATOPAUSE",
    "The top of the <TEMPERATURE_INVERSION_LAYER>, if it exists, that form"
    " the upper limit of the <STRATOSPHERE>; the stratopause.",
    3, &(EGBindingForEC[362]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"stratopause\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRATOSPHERE,
    "STRATOSPHERE", "ECC_STRATOSPHERE",
    "The <ATMOSPHERE_REGION> of the <EARTH> extending from the <TROPOPAUSE>"
    " to the <STRATOPAUSE> in which the <<AIR_TEMPERATURE>> generally"
    " increases with <<HEIGHT_AGL>>; the stratosphere.",
    2, &(EGBindingForEC[396]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"stratosphere\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STREET,
    "STREET", "ECC_STREET",
    "A <ROAD> in a <BUILT_UP_REGION>; a street.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STREET_LAMP,
    "STREET_LAMP", "ECC_STREET_LAMP",
    "A <LIGHT>, generally located on a <POLE>, that illuminates a <ROAD> or"
    " a <SIDEWALK>; a street lamp [SOED, \"street lamp\"] or street-light.",
    3, &(EGBindingForEC[1001]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRUCTURAL_PILE,
    "STRUCTURAL_PILE", "ECC_STRUCTURAL_PILE",
    "A <STRUCTURE> consisting of a long, heavy timber or section of steel"
    " or concrete that is forced into the <TERRAIN> to serve as a support"
    " (for example: for a <PIER>); a piling or structural pile.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: PILPNT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRUCTURE,
    "STRUCTURE", "ECC_STRUCTURE",
    "A combination of <COMPONENT>s that are fabricated and interconnected"
    " in accordance with a design; a structure.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"structure\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRUCTURE_ENTRANCE,
    "STRUCTURE_ENTRANCE", "ECC_STRUCTURE_ENTRANCE",
    "A way into a <STRUCTURE>; an entrance [SOED, \"entrance\", 4]."
    " EXAMPLES <GATE>, <HALLWAY>, <DOOR>.",
    2, &(EGBindingForEC[1178]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRUCTURE_ENTRANCE_AND_OR_EXIT,
    "STRUCTURE_ENTRANCE_AND_OR_EXIT", "ECC_STRUCTURE_ENTRANCE_AND_OR_EXIT",
    "A way into, out of, or both into and out of a <STRUCTURE>; an entrance"
    " and/or an exit. EXAMPLES <GATE>, <HALLWAY>, <DOOR>.",
    2, &(EGBindingForEC[1178]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRUCTURE_EXIT,
    "STRUCTURE_EXIT", "ECC_STRUCTURE_EXIT",
    "A way out of a <STRUCTURE>; an exit [SOED, \"exit\", 3]. EXAMPLES"
    " <GATE>, <HALLWAY>, <DOOR>.",
    2, &(EGBindingForEC[1178]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AQ090]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRUCTURE_EXTERIOR,
    "STRUCTURE_EXTERIOR", "ECC_STRUCTURE_EXTERIOR",
    "The <NON_EMPTY_SET> of <EXTERIOR_WALL>s and <ROOF> (if present) of a"
    " <STRUCTURE>.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STRUCTURE_PERIMETER,
    "STRUCTURE_PERIMETER", "ECC_STRUCTURE_PERIMETER",
    "The perimeter of a <STRUCTURE>.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_STUPA,
    "STUPA", "ECC_STUPA",
    "A round, usually dome-shaped, Buddhist <SHRINE> topped with a cupola;"
    " a stupa [SOED, \"stupa\"].",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SUBMERGED_ROCK_FORMATION,
    "SUBMERGED_ROCK_FORMATION", "ECC_SUBMERGED_ROCK_FORMATION",
    "An isolated formation of <ROCK> or a single large <ROCK> that is"
    " located in a <WATERBODY> and is typically submerged but possibly"
    " projects above the <WATERBODY_SURFACE>.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BD130]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SUBMERSIBLE_VESSEL,
    "SUBMERSIBLE_VESSEL", "ECC_SUBMERSIBLE_VESSEL",
    "A <VESSEL> capable of operation either on a <WATERBODY_SURFACE> or"
    " beneath it; a submersible vessel.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SUGAR_CANE,
    "SUGAR_CANE", "ECC_SUGAR_CANE",
    "A <TRACT> of Saccharum officinarum; sugar cane [AHD, \"sugar cane\"].",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SUN,
    "SUN", "ECC_SUN",
    "The central <STAR> of the <SOLAR_SYSTEM> containing the <EARTH>; the"
    " Sun.",
    2, &(EGBindingForEC[662]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"sun\", 1]", EDCS_CONCEPT_STAT_ISO },

    {ECC_SUNSPOT,
    "SUNSPOT", "ECC_SUNSPOT",
    "A relatively cool and dark appearing <REGION> on the photosphere of"
    " the <SUN>; a sunspot.",
    2, &(EGBindingForEC[1168]),
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SUPERSTRUCTURE,
    "SUPERSTRUCTURE", "ECC_SUPERSTRUCTURE",
    "A substantial <STRUCTURE> resting on something else; a superstructure"
    " [SOED, \"superstructure\", 1].",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SUPPLIES_AND_EXPENDABLES,
    "SUPPLIES_AND_EXPENDABLES", "ECC_SUPPLIES_AND_EXPENDABLES",
    "A <NON_EMPTY_SET> of <EQUIPMENT> and/or <MATERIAL> that may be"
    " consumed or discarded after use; supplies and expendables.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SURF,
    "SURF", "ECC_SURF",
    "The belt of nearly continuous, breaking <WATER_WAVE>s along a <SHORE>"
    " or over a submerged bank or <SAND_BAR>; surf.",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SURF_ZONE,
    "SURF_ZONE", "ECC_SURF_ZONE",
    "The <REGION> between the outermost limit of <SURF> and the resulting"
    " limit of <WATER_WAVE> uprush on a <SHORE>; a surf zone.",
    2, &(EGBindingForEC[1190]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"surf zone\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SURFACE,
    "SURFACE", "ECC_SURFACE",
    "An outermost, limiting <COMPONENT> of an <OBJECT> that is immediately"
    " adjacent to another <OBJECT> (for example: an <ATMOSPHERE> and/or"
    " <SPACE>); a surface [SOED, \"surface\", 1.a].",
    2, &(EGBindingForEC[79]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SURFACE_BASED_EM_DUCT,
    "SURFACE_BASED_EM_DUCT", "ECC_SURFACE_BASED_EM_DUCT",
    "A layer of the <ATMOSPHERE> that is adjacent to the"
    " <PLANETARY_SURFACE> of the <EARTH> and in which electromagnetic waves"
    " are trapped due to changes in the index of refraction; a"
    " surface-based electromagnetic duct.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_INFORMATIVE, "[BATT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SURFACE_DATUM,
    "SURFACE_DATUM", "ECC_SURFACE_DATUM",
    "A <DATUM> defining a <SURFACE> from which elevations or depths are"
    " measured. EXAMPLES <VERTICAL_DATUM>, <SOUNDING_DATUM>.",
    2, &(EGBindingForEC[1180]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SURFACE_FISSURE,
    "SURFACE_FISSURE", "ECC_SURFACE_FISSURE",
    "A narrow fissure, crack, and/or rift in the <TERRAIN> or the overlying"
    " <SNOW_GROUND_COVER> or <ICE>; a surface fissure.",
    2, &(EGBindingForEC[886]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SURVEILLANCE_WINGED_AIRCRAFT,
    "SURVEILLANCE_WINGED_AIRCRAFT", "ECC_SURVEILLANCE_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed or designated for surveillance missions.",
    4, &(EGBindingForEC[254]),
    EDCS_REF_TYP_INFORMATIVE, "[JAWA, Type Classifications, Class 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SURVEY_MARKER,
    "SURVEY_MARKER", "ECC_SURVEY_MARKER",
    "A <TERRAIN_SURFACE_OBJECT> (for example: a <MARKER>) with a known"
    " <LOCATION>; a survey marker.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: ZB035]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SWAMP,
    "SWAMP", "ECC_SWAMP",
    "A seasonally flooded, low-lying <WETLAND> with more woody <PLANT>s"
    " than a <MARSH> and better drainage than a <BOG>; a swamp [AHD,"
    " \"swamp\", 1a].",
    4, &(EGBindingForEC[856]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: ED020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SWELL_WAVE,
    "SWELL_WAVE", "ECC_SWELL_WAVE",
    "A surface gravity <WATER_WAVE> that is not growing or being sustained"
    " any longer by the <WIND> but that was generated by the <WIND> some"
    " distance away and is now propagating freely across the"
    " <WATERBODY_SURFACE> away from its <REGION> of generation; a swell"
    " wave.",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SWEPT_REGION,
    "SWEPT_REGION", "ECC_SWEPT_REGION",
    "A <WATERBODY_REGION> that has been determined to be clear of"
    " navigational dangers to a specified depth; a swept region.",
    3, &(EGBindingForEC[788]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: SWPARE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SWIMMING_POOL,
    "SWIMMING_POOL", "ECC_SWIMMING_POOL",
    "A constructed pool used for swimming; a swimming pool [SOED,"
    " \"swimming pool\"].",
    1, &(EGBindingForEC[39]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SYNAGOGUE,
    "SYNAGOGUE", "ECC_SYNAGOGUE",
    "A <WORSHIP_PLACE> for Jewish worship and religious instruction; a"
    " synagogue.",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SYSTEM,
    "SYSTEM", "ECC_SYSTEM",
    "A <NON_EMPTY_SET> of <OBJECT>s arranged or organized for a special"
    " purpose and functioning together as a whole; a system [SOED,"
    " \"system\", 3].",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_SYSTEMATIC_TREE_PLANTING,
    "SYSTEMATIC_TREE_PLANTING", "ECC_SYSTEMATIC_TREE_PLANTING",
    "A <TRACT> covered by systematic plantings of <TREE>s that yield a"
    " product (for example: a fruit and/or a nut).",
    4, &(EGBindingForEC[190]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EA040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TABERNACLE,
    "TABERNACLE", "ECC_TABERNACLE",
    "A <CHURCH> that has been specially designated by religious authority;"
    " a tabernacle.",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TAXIWAY,
    "TAXIWAY", "ECC_TAXIWAY",
    "A prepared <SURFACE> providing access to/from <RUNWAY>s and"
    " <HARD_STANDING>s, <AERODROME_TERMINAL>s, and service and/or other"
    " support operations for <AIRCRAFT>; a taxiway.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: GB075]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TELECOM_SWITCHING_STATION,
    "TELECOM_SWITCHING_STATION", "ECC_TELECOM_SWITCHING_STATION",
    "A <COMMUNICATION_STATION> housing a <SYSTEM> of switches that"
    " establishes connections between individual telecommunication"
    " <DEVICE>s; a telecom switching station.",
    2, &(EGBindingForEC[487]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:40]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TELEFERIC,
    "TELEFERIC", "ECC_TELEFERIC",
    "A transportation <SYSTEM> consisting of <LOAD_CABLE>s strung between"
    " <PYLON>s on which carrier units (for example: cars or buckets"
    " intended to transport <PERSONNEL>, <MATERIAL>, and/or <EQUIPMENT>)"
    " are suspended; an aerial cableway, an aerial tramway, or a teleferic.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: TELPHC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TELESCOPE,
    "TELESCOPE", "ECC_TELESCOPE",
    "A <DEVICE> used for observing distant <OBJECT>s and/or phenomena; a"
    " telescope.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL141]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TEMPERATURE_INVERSION_LAYER,
    "TEMPERATURE_INVERSION_LAYER", "ECC_TEMPERATURE_INVERSION_LAYER",
    "A layer in an <ATMOSPHERE> where the <<AIR_TEMPERATURE>> increases"
    " with <<HEIGHT_AGL>>; temperature inversion layer.",
    2, &(EGBindingForEC[396]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"temperature inversion\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TEMPORARY_ENCAMPMENT,
    "TEMPORARY_ENCAMPMENT", "ECC_TEMPORARY_ENCAMPMENT",
    "A <TRACT> containing a temporary, usually unsheltered, encampment"
    " [SOED, \"encampment\", 1]. EXAMPLE Bivouac.",
    1, &(EGBindingForEC[50]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TENDER,
    "TENDER", "ECC_TENDER",
    "A <WATER_SURFACE_VESSEL> used to attend other <VESSEL>s, especially to"
    " supply goods and provisions, convey orders, and/or carry passengers"
    " to and from <SHORE>; a tender [SOED, \"tender\", 2].",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TENNIS_COMPLEX,
    "TENNIS_COMPLEX", "ECC_TENNIS_COMPLEX",
    "A <SITE> including one of more <TENNIS_COURT>s; a tennis complex.",
    2, &(EGBindingForEC[1156]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TENNIS_COURT,
    "TENNIS_COURT", "ECC_TENNIS_COURT",
    "A court used in playing the game of tennis [SOED, \"tennis-court\"].",
    1, &(EGBindingForEC[39]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TENT,
    "TENT", "ECC_TENT",
    "A portable <SHELTER> of canvas, cloth, or similar <MATERIAL> that is"
    " supported by one or more <POLE>s and stretched and secured by"
    " <LOAD_CABLE>s fastened to pegs driven into the <TERRAIN>; a tent"
    " [SOED, \"tent\", 1.a].",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TENT_DWELLING,
    "TENT_DWELLING", "ECC_TENT_DWELLING",
    "A <TENT> used as a <DWELLING>; a tent dwelling.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN,
    "TERRAIN", "ECC_TERRAIN",
    "The <SURFACE> of the solid portion of a <PLANET>, which may or may not"
    " be covered by <WATER>; terrain or ground.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: LNDARE]",
    "[S32, \"ground\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_CHANNEL,
    "TERRAIN_CHANNEL", "ECC_TERRAIN_CHANNEL",
    "An elongated <TERRAIN_SURFACE_REGION>, especially one that is"
    " relatively narrow, whose longer sides are <TERRAIN_SURFACE_REGION>s"
    " of higher <<TERRAIN_ELEVATION>>; a terrain channel. EXAMPLES"
    " <CANYON>, <GORGE>, dry riverbed.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_CRATER,
    "TERRAIN_CRATER", "ECC_TERRAIN_CRATER",
    "A localized <TERRAIN_DEPRESSION> created by an explosion and/or the"
    " impact of a large or high-velocity projectile upon the <TERRAIN>; a"
    " crater [SOED, \"crater\", 2].",
    2, &(EGBindingForEC[1117]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_CUT,
    "TERRAIN_CUT", "ECC_TERRAIN_CUT",
    "An <EXCAVATION> in the <TERRAIN> to provide passage for a"
    " <LAND_TRANSPORTATION_ROUTE> (for example: a <ROAD>, a <RAILWAY>,"
    " and/or a <CANAL>); a terrain cut.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB070]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_DEPRESSION,
    "TERRAIN_DEPRESSION", "ECC_TERRAIN_DEPRESSION",
    "A <TERRAIN_SURFACE_REGION> of relatively low <<TERRAIN_ELEVATION>>"
    " that is completely surrounded by another <TERRAIN_SURFACE_REGION> of"
    " higher <<TERRAIN_ELEVATION>>; a terrain depression.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_ELEVATION_PROPERTY_SET,
    "TERRAIN_ELEVATION_PROPERTY_SET", "ECC_TERRAIN_ELEVATION_PROPERTY_SET",
    "A <PROPERTY_SET> describing <<TERRAIN_ELEVATION>>s.",
    3, &(EGBindingForEC[1094]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_FILL,
    "TERRAIN_FILL", "ECC_TERRAIN_FILL",
    "A <REGION> of fill that augments a <TERRAIN_SURFACE_REGION>; a terrain"
    " fill.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_OBSTACLE,
    "TERRAIN_OBSTACLE", "ECC_TERRAIN_OBSTACLE",
    "A configuration of <TERRAIN> and/or associated <STRUCTURE>s that"
    " impedes the movement of <GROUND_VEHICLE>s and pedestrian traffic; a"
    " terrain obstacle.",
    3, &(EGBindingForEC[1035]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_PIT,
    "TERRAIN_PIT", "ECC_TERRAIN_PIT",
    "An <EXCAVATION> where gravel, <SAND>, and/or clay are removed for use"
    " elsewhere; a terrain pit.",
    3, &(EGBindingForEC[959]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AA013]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_PLAIN,
    "TERRAIN_PLAIN", "ECC_TERRAIN_PLAIN",
    "A <TERRAIN_SURFACE_REGION> that is comparatively flat; a terrain plain.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"plain\"1.a]", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_STRIP,
    "TERRAIN_STRIP", "ECC_TERRAIN_STRIP",
    "A <TRACT> that is significantly longer in one dimension than the"
    " other; a terrain strip [SOED, \"strip\", 2].",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_SURFACE_OBJECT,
    "TERRAIN_SURFACE_OBJECT", "ECC_TERRAIN_SURFACE_OBJECT",
    "An <OBJECT> located on the <TERRAIN>. EXAMPLE Man-made <STRUCTURE>.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_SURFACE_REGION,
    "TERRAIN_SURFACE_REGION", "ECC_TERRAIN_SURFACE_REGION",
    "A <REGION> of <TERRAIN>, especially one distinguished by natural"
    " features, climate, fauna or flora; a terrain surface region [SOED,"
    " \"region\", 1].",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_TRANSPORTATION_ABATIS,
    "TERRAIN_TRANSPORTATION_ABATIS", "ECC_TERRAIN_TRANSPORTATION_ABATIS",
    "An <ABATIS> blocking movement on a <LAND_TRANSPORTATION_ROUTE>.",
    3, &(EGBindingForEC[1024]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TERRAIN_TRANSPORTATION_GALLERY,
    "TERRAIN_TRANSPORTATION_GALLERY", "ECC_TERRAIN_TRANSPORTATION_GALLERY",
    "A sunken or cut passage along a <LAND_TRANSPORTATION_ROUTE> in"
    " <MOUNTAINOUS_REGION>s constructed to protect <GROUND_VEHICLE>s from"
    " the weather; a terrain transportation gallery. A series of"
    " <APERTURE>s may be present on one side for light or ventilation.",
    3, &(EGBindingForEC[1038]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL075]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TEST_REFERENCE_TRACK,
    "TEST_REFERENCE_TRACK", "ECC_TEST_REFERENCE_TRACK",
    "A surveyed reference track marking the <CENTRE_LINE> of a marine test"
    " range; a test reference track. <VESSEL>s undergoing testing must"
    " maintain position along this track.",
    3, &(EGBindingForEC[821]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FC102]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TEST_SITE,
    "TEST_SITE", "ECC_TEST_SITE",
    "A <SITE> for the testing of technical products and <EQUIPMENT>; a test"
    " site.",
    2, &(EGBindingForEC[970]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FA100]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_THEATRE,
    "THEATRE", "ECC_THEATRE",
    "A <BUILDING>, <ROOM>, or outdoor <STRUCTURE> used for the presentation"
    " of plays, films, or other dramatic performances; a theatre [AHD,"
    " \"theater\", 1].",
    3, &(EGBindingForEC[413]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_THEODOLITE_LINE,
    "THEODOLITE_LINE", "ECC_THEODOLITE_LINE",
    "A <LINE> of known <DIRECTION> from a fixed <LOCATION> that may be used"
    " to determine accurate positions of a <VESSEL> on certain test ranges;"
    " a theodolite line.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FC101]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_THERMAL_MATERIAL_PROPERTY_SET,
    "THERMAL_MATERIAL_PROPERTY_SET", "ECC_THERMAL_MATERIAL_PROPERTY_SET",
    "A <PROPERTY_SET> describing the thermal properties of the <MATERIAL>s"
    " composing an <OBJECT>.",
    3, &(EGBindingForEC[1114]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_THUNDERSTORM,
    "THUNDERSTORM", "ECC_THUNDERSTORM",
    "A storm with thunder and <LIGHTNING> produced by electrically charged"
    " cumulonimbus <CLOUD>s and usually accompanied by heavy <RAIN> and/or"
    " <HAIL>; a thunderstorm.",
    2, &(EGBindingForEC[367]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"thunderstorm\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIDAL_BASIN,
    "TIDAL_BASIN", "ECC_TIDAL_BASIN",
    "A <WATERBODY_SHELTER_BASIN> affected by tidal forces in which <WATER>"
    " can be kept at a desired level by means of a <MARINE_GATE>; a tidal"
    " basin.",
    5, &(EGBindingForEC[783]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"basin: tidal\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIDAL_WATER,
    "TIDAL_WATER", "ECC_TIDAL_WATER",
    "A <WATERBODY> where the level normally fluctuates with the <TIDE>;"
    " tidal water or non-inland water.",
    2, &(EGBindingForEC[874]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BA040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIDE,
    "TIDE", "ECC_TIDE",
    "The alternate rising and falling of a <WATERBODY_SURFACE> due to the"
    " gravitational attraction of the <MOON>, <SUN>, or other"
    " <CELESTIAL_BODY>s; tide [SOED, \"tide\", II.7].",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIDE_DATA_POINT,
    "TIDE_DATA_POINT", "ECC_TIDE_DATA_POINT",
    "A <LOCATION> for which tabulated tidal stream data are given; a tide"
    " data point.",
    2, &(EGBindingForEC[1105]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BG030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIDE_GAUGE,
    "TIDE_GAUGE", "ECC_TIDE_GAUGE",
    "A <DEVICE> for measuring the <<TIDE_LEVEL>>; a tide gauge.",
    3, &(EGBindingForEC[583]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BG020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIDE_LOCK,
    "TIDE_LOCK", "ECC_TIDE_LOCK",
    "A <HYDROGRAPHIC_LOCK> situated between a <WATERBODY_SHELTER_BASIN> or"
    " <CANAL> and tidewater to maintain the <WATER> at a desired level as"
    " the <<TIDE_LEVEL>> changes; a tide lock or guard lock.",
    4, &(EGBindingForEC[727]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"tide lock\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIDE_RIP_REGION,
    "TIDE_RIP_REGION", "ECC_TIDE_RIP_REGION",
    "A <WATERBODY_REGION> where small <WATER_WAVE>s are formed on the"
    " <WATERBODY_SURFACE> by the meeting of opposing tidal <WATER_CURRENT>s"
    " or by a tidal <WATER_CURRENT> crossing an irregular"
    " <WATERBODY_FLOOR>; a tide rip region.",
    2, &(EGBindingForEC[874]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute, CATWAT:4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIDEWAY,
    "TIDEWAY", "ECC_TIDEWAY",
    "A natural <WATERCOURSE> in intertidal <REGION>s where <WATER> flows"
    " during the rise and fall of the <TIDE>; a tideway.",
    2, &(EGBindingForEC[874]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"tideway\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIMBER_YARD,
    "TIMBER_YARD", "ECC_TIMBER_YARD",
    "An open <TRACT> for the storage of wooden lumber and timbers; a timber"
    " yard.",
    4, &(EGBindingForEC[949]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AM031]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIME_ANALYSIS_BASE_SET,
    "TIME_ANALYSIS_BASE_SET", "ECC_TIME_ANALYSIS_BASE_SET",
    "A <NON_EMPTY_SET> of <OBJECT>s with EDCS Attributes that are analyzed"
    " at a common base time.",
    2, &(EGBindingForEC[81]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TIME_FORECAST_TAU_SET,
    "TIME_FORECAST_TAU_SET", "ECC_TIME_FORECAST_TAU_SET",
    "A <NON_EMPTY_SET> of <OBJECT>s with EDCS Attributes that are"
    " forecasted at a time offset from a <TIME_ANALYSIS_BASE_SET> time.",
    2, &(EGBindingForEC[81]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TOPMARK,
    "TOPMARK", "ECC_TOPMARK",
    "A characteristic shape secured at the top of a <BUOY> or <BEACON> to"
    " aid in its identification; a topmark.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"topmark\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TOWED_ARTILLERY,
    "TOWED_ARTILLERY", "ECC_TOWED_ARTILLERY",
    "Towed <FIELD_ARTILLERY>.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TOWED_VEHICLE,
    "TOWED_VEHICLE", "ECC_TOWED_VEHICLE",
    "A <VEHICLE> towed by another.",
    2, &(EGBindingForEC[1186]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TOWER,
    "TOWER", "ECC_TOWER",
    "A relatively tall, narrow <STRUCTURE>, which is usually of square,"
    " circular, or rectangular cross-section, that may either stand alone"
    " or may form part of another <STRUCTURE>; a tower.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: TOWERS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TOWN,
    "TOWN", "ECC_TOWN",
    "A concentration of <DWELLING>s, <COMMERCIAL_BUILDING>s,"
    " <INDUSTRIAL_BUILDING>s, and other <STRUCTURE>s where <HUMAN>s have"
    " settled that is larger than a <SETTLEMENT> and usually smaller than a"
    " <CITY> and/or <BUILT_UP_REGION>; a town.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"town\", 4]", EDCS_CONCEPT_STAT_ISO },

    {ECC_TOWN_HALL,
    "TOWN_HALL", "ECC_TOWN_HALL",
    "The <MUNICIPAL_HALL> of a <TOWN>.",
    2, &(EGBindingForEC[128]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRACK_LINE,
    "TRACK_LINE", "ECC_TRACK_LINE",
    "The path of marine travel as drawn on a <MAP> together with the"
    " <SOUNDING>s and related information collected along that path; a"
    " track line.",
    3, &(EGBindingForEC[821]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BE040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRACK_SWATH,
    "TRACK_SWATH", "ECC_TRACK_SWATH",
    "A <WATERBODY_SURFACE_REGION> of horizontal depth coverage recorded by"
    " sonar array <SYSTEM>s; a track swath.",
    2, &(EGBindingForEC[103]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BE030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRACT,
    "TRACT", "ECC_TRACT",
    "A <REGION> of <LAND>; a tract.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRADING_POST,
    "TRADING_POST", "ECC_TRADING_POST",
    "A <SITE> occupied for purposes of trade, especially in a remote and/or"
    " unsettled <REGION>; a trading post [SOED, \"trading post\"].",
    2, &(EGBindingForEC[970]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRADITIONAL_SETTLEMENT,
    "TRADITIONAL_SETTLEMENT", "ECC_TRADITIONAL_SETTLEMENT",
    "A concentration of simple <DWELLING>s, which are generally <HUT>s,"
    " that are not usually of substantial construction; a traditional"
    " settlement.",
    2, &(EGBindingForEC[1164]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL135]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRAFFIC_SEPARATION_SCHEME,
    "TRAFFIC_SEPARATION_SCHEME", "ECC_TRAFFIC_SEPARATION_SCHEME",
    "A measure for organizing a <TRANSPORTATION_ROUTE> that separates"
    " opposing streams of <VESSEL>s by appropriate means, including the"
    " establishment of <ROUTE_LANE>s; a traffic separation scheme.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"traffic separation scheme\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRAIL,
    "TRAIL", "ECC_TRAIL",
    "A path on <LAND> worn by the passage of <ANIMAL>s; a trail.",
    4, &(EGBindingForEC[327]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AP050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRAIN,
    "TRAIN", "ECC_TRAIN",
    "A number of <RAIL_WAGON>s coupled together, usually including the"
    " <LOCOMOTIVE_ENGINE> by which they are drawn; a train [SOED,"
    " \"train\", 13].",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRAINER_WINGED_AIRCRAFT,
    "TRAINER_WINGED_AIRCRAFT", "ECC_TRAINER_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed or designated for flight training"
    " operations.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRAINING_BUILDING,
    "TRAINING_BUILDING", "ECC_TRAINING_BUILDING",
    "A <BUILDING> used exclusively for training of military, police, fire,"
    " and/or rescue <PERSONNEL>; a training building.",
    3, &(EGBindingForEC[977]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRAINING_FACILITY,
    "TRAINING_FACILITY", "ECC_TRAINING_FACILITY",
    "A <FACILITY> including one or more <TRAINING_BUILDING>s; a training"
    " facility.",
    4, &(EGBindingForEC[980]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FA165]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRANSMISSION_STATION,
    "TRANSMISSION_STATION", "ECC_TRANSMISSION_STATION",
    "A station that is equipped for radio and/or television transmission.",
    3, &(EGBindingForEC[455]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRANSPORT_HELICOPTER,
    "TRANSPORT_HELICOPTER", "ECC_TRANSPORT_HELICOPTER",
    "A <HELICOPTER> designed and/or designated to transport <CARGO>,"
    " <PERSONNEL>, or other <MATERIAL>s.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRANSPORT_WINGED_AIRCRAFT,
    "TRANSPORT_WINGED_AIRCRAFT", "ECC_TRANSPORT_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed and/or designated to transport <CARGO>,"
    " <PERSONNEL>, or other <MATERIAL>s.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRANSPORTATION_BLOCK,
    "TRANSPORTATION_BLOCK", "ECC_TRANSPORTATION_BLOCK",
    "A massive assemblage of <MATERIAL>, usually in the form of concrete"
    " blocks and/or cylinders, positioned alongside (a <ROLLING_BLOCK>) or"
    " above (a <DROP_GATE>) a <LAND_TRANSPORTATION_ROUTE>, ready to be"
    " activated as a potential <BARRIER> to an advancing enemy ground"
    " force; a transportation block.",
    3, &(EGBindingForEC[1024]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ068]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRANSPORTATION_BUILDING,
    "TRANSPORTATION_BUILDING", "ECC_TRANSPORTATION_BUILDING",
    "A <BUILDING> intended to facilitate the transportation of <HUMAN>s"
    " and/or <MATERIAL>s.",
    3, &(EGBindingForEC[1038]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRANSPORTATION_FACILITY,
    "TRANSPORTATION_FACILITY", "ECC_TRANSPORTATION_FACILITY",
    "A <FACILITY> including one or more <TRANSPORTATION_BUILDING>s.",
    4, &(EGBindingForEC[1041]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRANSPORTATION_ROUTE,
    "TRANSPORTATION_ROUTE", "ECC_TRANSPORTATION_ROUTE",
    "A <ROUTE> used for transportation.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRANSPORTATION_STATION,
    "TRANSPORTATION_STATION", "ECC_TRANSPORTATION_STATION",
    "A station that serves as a stopping place along a"
    " <TRANSPORTATION_ROUTE>; a transportation station.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ125]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRAPDOOR,
    "TRAPDOOR", "ECC_TRAPDOOR",
    "A <DOOR> or hatch that is flush with a <SURFACE> and located in a"
    " <FLOOR>, on a <ROOF>, or in a <ROOM_CEILING>; a trapdoor [SOED,"
    " \"trapdoor\", 1].",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TREE,
    "TREE", "ECC_TREE",
    "A woody-perennial <PLANT> that has a self-supporting main stem or"
    " trunk and a definite crown; a tree or tree-like plant.",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Object: TREPNT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TREE_BLOWDOWN,
    "TREE_BLOWDOWN", "ECC_TREE_BLOWDOWN",
    "A <TRACT> on which <TREE>s have been blown down or otherwise levelled;"
    " tree blowdown.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TREE_LINE,
    "TREE_LINE", "ECC_TREE_LINE",
    "A relatively linear arrangement of <TREE>s; a tree line [SOED, \"tree"
    " line\", b].",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TREED_TRACT,
    "TREED_TRACT", "ECC_TREED_TRACT",
    "A <TRACT> covered by a <NON_EMPTY_SET> of <TREE>s; a treed tract."
    " EXAMPLES Copse, thicket, stand of <TREE>s.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EC030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRENCH,
    "TRENCH", "ECC_TRENCH",
    "A long and narrow <EXCAVATION> in the <TERRAIN>; a trench [SOED,"
    " \"trench\", 2.a] or a ditch.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AH020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TROPICAL_CYCLONE,
    "TROPICAL_CYCLONE", "ECC_TROPICAL_CYCLONE",
    "A non-frontal, synoptic-scale <CYCLONE> originating over a tropical or"
    " sub-tropical <WATERBODY> with organized convection and definite"
    " cyclonic surface <WIND> circulation; a tropical cyclone.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"tropical cyclone\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TROPOPAUSE,
    "TROPOPAUSE", "ECC_TROPOPAUSE",
    "The <BOUNDARY> between the <TROPOSPHERE> and the <STRATOSPHERE> where"
    " an abrupt change in the <<TEMPERATURE_LAPSE_RATE>> usually occurs;"
    " the tropopause.",
    4, &(EGBindingForEC[358]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"tropopause\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TROPOSPHERE,
    "TROPOSPHERE", "ECC_TROPOSPHERE",
    "The <ATMOSPHERE_REGION> of the <EARTH>, extending from the"
    " <PLANETARY_SURFACE> to the <TROPOPAUSE>; the troposphere.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"troposphere\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TRUCK,
    "TRUCK", "ECC_TRUCK",
    "A large, strong <MOTOR_VEHICLE> for carrying <CARGO>, <HUMAN>s, and/or"
    " other <MATERIAL>s; a truck [SOED, \"truck\", 3.b].",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TSS_SYSTEM,
    "TSS_SYSTEM", "ECC_TSS_SYSTEM",
    "A <MARINE_OBJECT> that is composed of a deep-water <MARINE_ROUTE> and"
    " the related <NAVIGATION_MARK_AFLOAT>s and/or <NAVIGATION_MARK_FIXED>s"
    " that are placed to delimit specific <TRANSPORTATION_ROUTE>s for"
    " separating traffic within the <MARINE_ROUTE>; a traffic separation"
    " scheme system.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FC040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TSUNAMI,
    "TSUNAMI", "ECC_TSUNAMI",
    "A long-period <WATER_WAVE> produced by a submarine earthquake and/or"
    " volcanic eruption; a tsunami.",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"tsunami\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TUNA_NETTING_REGION,
    "TUNA_NETTING_REGION", "ECC_TUNA_NETTING_REGION",
    "A <WATERBODY_REGION> where nets used for catching tuna have been"
    " deployed.",
    3, &(EGBindingForEC[349]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB111]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TUNDRA,
    "TUNDRA", "ECC_TUNDRA",
    "A prairie-like arctic and sub-arctic climatic <TRACT> that sustains a"
    " growth of low <VEGETATION>; tundra.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BJ110]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TUNNEL,
    "TUNNEL", "ECC_TUNNEL",
    "A passage under the <TERRAIN> that is open at both ends and usually"
    " contains a <LAND_TRANSPORTATION_ROUTE>; a tunnel.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: TUNNEL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TUNNEL_SHELTER,
    "TUNNEL_SHELTER", "ECC_TUNNEL_SHELTER",
    "A <TUNNEL> for the purpose of sheltering <MATERIAL>s, <EQUIPMENT>,"
    " and/or <HUMAN>s; a tunnel shelter.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TURBID_REGION,
    "TURBID_REGION", "ECC_TURBID_REGION",
    "A <WATERBODY_REGION> with increased <<WATER_DIFFUSE_TURBIDITY>>; a"
    " turbid region.",
    1, &(EGBindingForEC[53]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"turbidity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TURNING_BASIN,
    "TURNING_BASIN", "ECC_TURNING_BASIN",
    "An enlargement of a <WATER_CHANNEL> used for turning <VESSEL>s; a"
    " turning basin or manoeuvering basin.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"turning basin\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_TYPHOON,
    "TYPHOON", "ECC_TYPHOON",
    "A <TROPICAL_CYCLONE> with maximum sustained <<WIND_SPEED>>s of 33"
    " metres per second or greater near the centre and that is located in"
    " the western North Pacific; a typhoon.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"typhoon\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNCONTROLLED_AIRSPACE,
    "UNCONTROLLED_AIRSPACE", "ECC_UNCONTROLLED_AIRSPACE",
    "Any <AIRSPACE> in which air traffic control service is not available;"
    " an uncontrolled airspace.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_INFORMATIVE, "[AIM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERGROUND_BUNKER,
    "UNDERGROUND_BUNKER", "ECC_UNDERGROUND_BUNKER",
    "A <BUNKER> that is used as a command and control centre or for"
    " encampment; an underground bunker.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AH060]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERGROUND_DWELLING,
    "UNDERGROUND_DWELLING", "ECC_UNDERGROUND_DWELLING",
    "A <DWELLING> under the <TERRAIN>; an underground dwelling.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL250]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERGROUND_RAILWAY,
    "UNDERGROUND_RAILWAY", "ECC_UNDERGROUND_RAILWAY",
    "A <TUNNEL> under the <TERRAIN> through which a metropolitan electric"
    " <RAILWAY> travels; an underground railway.",
    3, &(EGBindingForEC[649]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: SU002]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERGROUND_WATER,
    "UNDERGROUND_WATER", "ECC_UNDERGROUND_WATER",
    "<WATER> situated under the <TERRAIN> but reachable by <WELL>s;"
    " underground water or phreatic water.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH115]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERMINED_LAND,
    "UNDERMINED_LAND", "ECC_UNDERMINED_LAND",
    "A <TRACT> that was previously undermined through mining activities and"
    " that either has already partly subsided and/or that is in the process"
    " of subsiding; undermined land.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: DB220]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERWATER_COMMUNICATION_DEVICE,
    "UNDERWATER_COMMUNICATION_DEVICE", "ECC_UNDERWATER_COMMUNICATION_DEVICE",
    "A <DEVICE> located in a <WATERBODY> and used to provide two-way"
    " communication; an underwater communication device. EXAMPLE"
    " <ACOUSTIC_TRANSDUCER>.",
    6, &(EGBindingForEC[434]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERWATER_HAZARD,
    "UNDERWATER_HAZARD", "ECC_UNDERWATER_HAZARD",
    "An <UNDERWATER_OBJECT> known to be hazardous to navigation on"
    " <WATERBODY_SURFACE>s; an underwater hazard.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BD000]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERWATER_OBJECT,
    "UNDERWATER_OBJECT", "ECC_UNDERWATER_OBJECT",
    "An <OBJECT> under a <WATERBODY_SURFACE>. EXAMPLE <MARINE_WRECK>.",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD005]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNDERWATER_REGION,
    "UNDERWATER_REGION", "ECC_UNDERWATER_REGION",
    "A <REGION> under a <WATERBODY_SURFACE>.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNMANNED_WINGED_AIRCRAFT,
    "UNMANNED_WINGED_AIRCRAFT", "ECC_UNMANNED_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> operating without a pilot onboard; an unmanned"
    " aircraft.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNMONUMENTED_POINT,
    "UNMONUMENTED_POINT", "ECC_UNMONUMENTED_POINT",
    "A formally recognized survey or reference <LOCATION> that is not"
    " represented by a physical <BOUNDARY_MONUMENT> and/or <BENCHMARK>; an"
    " unmonumented point.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZB031]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UNVEGETATED_LAND,
    "UNVEGETATED_LAND", "ECC_UNVEGETATED_LAND",
    "A <TRACT> with little (less than 5 percent) or no <VEGETATION>;"
    " unvegetated land.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EE020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_URANUS,
    "URANUS", "ECC_URANUS",
    "The primary <PLANET> of the <SUN> that is seventh in distance from the"
    " <SUN>, with an orbital mean <<RADIUS>> of approximately 2 875,0"
    " million kilometres; Uranus.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UTILITY_HELICOPTER,
    "UTILITY_HELICOPTER", "ECC_UTILITY_HELICOPTER",
    "A <HELICOPTER> designed or designated for various utility operations.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UTILITY_VESSEL,
    "UTILITY_VESSEL", "ECC_UTILITY_VESSEL",
    "A <WATER_SURFACE_VESSEL> designed or designated for various utility"
    " operations.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_UTILITY_WINGED_AIRCRAFT,
    "UTILITY_WINGED_AIRCRAFT", "ECC_UTILITY_WINGED_AIRCRAFT",
    "A winged <AIRCRAFT> designed or designated for utility, non-transport"
    " purposes.",
    3, &(EGBindingForEC[270]),
    EDCS_REF_TYP_INFORMATIVE, "[JAWA, Type Classifications, Class 7]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VALLEY_BOTTOM_LINE,
    "VALLEY_BOTTOM_LINE", "ECC_VALLEY_BOTTOM_LINE",
    "A <LINE> representing of the lowest part of a <VALLEY_REGION>; a"
    " valley bottom line.",
    2, &(EGBindingForEC[1092]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: CA025]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VALLEY_REGION,
    "VALLEY_REGION", "ECC_VALLEY_REGION",
    "A low-lying <TERRAIN_SURFACE_REGION> located between <HILL>s and/or"
    " <MOUNTAIN>s and often having a <RIVER> flowing through it; a valley"
    " region.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VARIABLE_DISPLACEMENT_LINE,
    "VARIABLE_DISPLACEMENT_LINE", "ECC_VARIABLE_DISPLACEMENT_LINE",
    "A <LINE> connecting <LOCATION>s having a varying relative vertical"
    " offset from the <TERRAIN>; a variable displacement line.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VEGETABLE_OIL_MILL,
    "VEGETABLE_OIL_MILL", "ECC_VEGETABLE_OIL_MILL",
    "A <BUILDING> that houses <EQUIPMENT> that releases the oils of"
    " vegetable seeds by pressing and/or grinding; a vegetable oil mill.",
    5, &(EGBindingForEC[941]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:71]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VEGETATED_SATURATED_LAND,
    "VEGETATED_SATURATED_LAND", "ECC_VEGETATED_SATURATED_LAND",
    "A saturated <TRACT> that is at times covered with <WATER> and that"
    " supports <VEGETATION> that may include <TREE>s; vegetated saturated"
    " land.",
    4, &(EGBindingForEC[856]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH095]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VEGETATION,
    "VEGETATION", "ECC_VEGETATION",
    "The <PLANT>s in a given <REGION>; vegetation [AHD, \"vegetation\", 2].",
    2, &(EGBindingForEC[1081]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VEHICLE,
    "VEHICLE", "ECC_VEHICLE",
    "<EQUIPMENT> used to provide a means of conveyance for transporting"
    " <MATERIAL>s, <EQUIPMENT>, and/or <HUMAN>s; a vehicle.",
    3, &(EGBindingForEC[618]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"vehicle\", II.6]", EDCS_CONCEPT_STAT_ISO },

    {ECC_VEHICLE_BARRIER,
    "VEHICLE_BARRIER", "ECC_VEHICLE_BARRIER",
    "An obstruction placed across a <LAND_TRANSPORTATION_ROUTE> to prevent"
    " the passage of <VEHICLE>s; a vehicle barrier.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AP041]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VEHICLE_LOT,
    "VEHICLE_LOT", "ECC_VEHICLE_LOT",
    "A <TRACT> used for storing and/or parking <VEHICLE>s and/or <VESSEL>s;"
    " a vehicle lot.",
    3, &(EGBindingForEC[1052]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AQ140]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VEHICLE_SCALE,
    "VEHICLE_SCALE", "ECC_VEHICLE_SCALE",
    "<EQUIPMENT>, which is usually located alongside a <ROAD>, that is used"
    " to determine the weight of <GROUND_VEHICLE>s; a scale.",
    3, &(EGBindingForEC[603]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:133]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VENTILATION_APERTURE,
    "VENTILATION_APERTURE", "ECC_VENTILATION_APERTURE",
    "An <APERTURE>, generally covered, into a <VENTILATION_DUCT> or"
    " <VENTILATION_SHAFT>.",
    2, &(EGBindingForEC[400]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VENTILATION_DUCT,
    "VENTILATION_DUCT", "ECC_VENTILATION_DUCT",
    "A predominantly horizontal duct for the admission of a proper supply"
    " of fresh and/or temperature-controlled <AIR>, especially to a <ROOM>,"
    " <BUILDING>, or other place where the <AIR> readily becomes stagnant"
    " or in need of temperature control; a ventilation duct.",
    3, &(EGBindingForEC[405]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"ventilation duct\", 4.b]", EDCS_CONCEPT_STAT_ISO },

    {ECC_VENTILATION_DUCT_WALL,
    "VENTILATION_DUCT_WALL", "ECC_VENTILATION_DUCT_WALL",
    "The <WALL> and/or casing of a <VENTILATION_DUCT>.",
    2, &(EGBindingForEC[400]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VENTILATION_SHAFT,
    "VENTILATION_SHAFT", "ECC_VENTILATION_SHAFT",
    "A vertical or nearly vertical passageway in a <BUILDING> used for"
    " moving heating, cooling, and/or ventilation <AIR>; a ventilation"
    " shaft.",
    3, &(EGBindingForEC[405]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VENUS,
    "VENUS", "ECC_VENUS",
    "The primary <PLANET> of the <SUN> that is second in distance from the"
    " <SUN> with an orbital mean <<RADIUS>> of approximately 108,2 million"
    " kilometres; Venus.",
    1, &(EGBindingForEC[42]),
    EDCS_REF_TYP_INFORMATIVE, "[PSMOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VERTEBRATE,
    "VERTEBRATE", "ECC_VERTEBRATE",
    "An <ANIMAL> of the subphylum Vertebrata, comprising chordate animals"
    " with a bony and/or cartilaginous skeleton, skull, and spinal column;"
    " a vertebrate [SOED, \"vertebrate\", A]. EXAMPLES <FISH>, <AMPHIBIAN>,"
    " <REPTILE>, <BIRD>, <MAMMAL>.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VERTICAL_DATUM,
    "VERTICAL_DATUM", "ECC_VERTICAL_DATUM",
    "A datum (see I19111, 4.9) to which gravity-related elevations and"
    " heights are referenced; often taken to correspond to MSL; the"
    " vertical datum.",
    2, &(EGBindingForEC[1101]),
    EDCS_REF_TYP_INFORMATIVE, "[I19111, 4.33]",
    "[GMCG]", EDCS_CONCEPT_STAT_ISO },

    {ECC_VESSEL,
    "VESSEL", "ECC_VESSEL",
    "A <VEHICLE> capable of operation on the <WATERBODY_SURFACE>, but which"
    " may also be able to operate beneath it; a vessel.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"vessel\", 4]", EDCS_CONCEPT_STAT_ISO },

    {ECC_VESSEL_BASIN,
    "VESSEL_BASIN", "ECC_VESSEL_BASIN",
    "An enclosure containing <WATER> for a dock for <VESSEL>s; a vessel"
    " basin.",
    3, &(EGBindingForEC[835]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB022]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VESSEL_BERTH,
    "VESSEL_BERTH", "ECC_VESSEL_BERTH",
    "The <LOCATION> where a <VESSEL> lies when secured to a <PIER>,"
    " <WHARF>, and/or <MOORING_DOLPHIN>; may also be a designated"
    " <LOCATION> away from the <COASTLINE>; a vessel berth.",
    3, &(EGBindingForEC[814]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BB020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VESSEL_STORAGE_ANCHORAGE,
    "VESSEL_STORAGE_ANCHORAGE", "ECC_VESSEL_STORAGE_ANCHORAGE",
    "A defined <WATERBODY_REGION> intended for use as a long-term"
    " <ANCHORAGE> and storage for <VESSEL>s; a vessel storage anchorage.",
    4, &(EGBindingForEC[791]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VIADUCT,
    "VIADUCT", "ECC_VIADUCT",
    "A <STRUCTURE> consisting of a series of arches or <TOWER>s supporting"
    " a <LAND_TRANSPORTATION_ROUTE> across a <TERRAIN_DEPRESSION>; a"
    " viaduct.",
    3, &(EGBindingForEC[1047]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"viaduct\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VINEYARD,
    "VINEYARD", "ECC_VINEYARD",
    "A <TRACT> covered by the systematic planting of grape vines; a"
    " vineyard.",
    4, &(EGBindingForEC[190]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: EA050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VOID_COLLECTION,
    "VOID_COLLECTION", "ECC_VOID_COLLECTION",
    "A data collection <REGION> lacking suitable source coverage and/or"
    " where data is not required; a void collection.",
    1, &(EGBindingForEC[46]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: ZD020]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VOLCANIC_DYKE,
    "VOLCANIC_DYKE", "ECC_VOLCANIC_DYKE",
    "A mass of igneous <ROCK> that has intruded upwards through strata,"
    " sometimes showing as a <RIDGE>.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB190]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_VOLCANO,
    "VOLCANO", "ECC_VOLCANO",
    "A <MOUNTAIN> or <HILL>, often conical, formed around a vent in the"
    " <TERRAIN> through which molten <ROCK>, ash, and/or gases are or have"
    " been expelled; a volcano.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: DB180]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WADI,
    "WADI", "ECC_WADI",
    "The dry bed of an intermittent <RIVER>, often with steep sides or"
    " located at the bottom of a <TERRAIN_CHANNEL>; a wadi, a wash, or an"
    " arroyo.",
    2, &(EGBindingForEC[865]),
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"wadi\", 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WADI_NEXUS,
    "WADI_NEXUS", "ECC_WADI_NEXUS",
    "The representation of one or more <WADI>s; a wadi centre-line or wadi"
    " nexus.",
    3, &(EGBindingForEC[862]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WALL,
    "WALL", "ECC_WALL",
    "A solid man-made <BARRIER> of generally heavy <MATERIAL> used as an"
    " enclosure, <BOUNDARY>, or for protection; a wall.",
    3, &(EGBindingForEC[552]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AL260]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WALL_LOOPHOLE,
    "WALL_LOOPHOLE", "ECC_WALL_LOOPHOLE",
    "A small <APERTURE> in a <WALL> in a defended <STRUCTURE> created for"
    " military purposes, typically about 20 centimetres in diameter; a wall"
    " loophole.",
    2, &(EGBindingForEC[1121]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WAREHOUSE,
    "WAREHOUSE", "ECC_WAREHOUSE",
    "A <BUILDING> in which goods or merchandise are stored; a warehouse"
    " [AHD, \"warehouse\", 1].",
    3, &(EGBindingForEC[946]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WARM_FRONT,
    "WARM_FRONT", "ECC_WARM_FRONT",
    "An <ATMOSPHERIC_FRONT> between warm and cold <AIR_MASS>s that moves so"
    " that the warmer <AIR> replaces the colder <AIR>; a warm front.",
    4, &(EGBindingForEC[358]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"warm front\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WASTE_PROCESSING_FACILITY,
    "WASTE_PROCESSING_FACILITY", "ECC_WASTE_PROCESSING_FACILITY",
    "A <FACILITY> where waste is processed through chemical, physical,"
    " biological, or thermal procedures or a combination of those"
    " procedures; a waste processing facility.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AB030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER,
    "WATER", "ECC_WATER",
    "A compound of hydrogen and oxygen, chemical formula H[sub(2)]O [SOED,"
    " \"water\", 1.a].",
    1, &(EGBindingForEC[33]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY,
    "WATERBODY", "ECC_WATERBODY",
    "A particular, designated body of <WATER> forming a physiographic"
    " <OBJECT> [SOED, \"waterbody\"]. EXAMPLES <LAKE>, <OCEAN>, <SEA>,"
    " <RIVER>.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_ACOUSTIC_PROPERTY_SET,
    "WATERBODY_ACOUSTIC_PROPERTY_SET", "ECC_WATERBODY_ACOUSTIC_PROPERTY_SET",
    "A <WATERBODY_PROPERTY_SET> describing acoustic-related properties.",
    3, &(EGBindingForEC[96]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_ACOUSTIC_SIGNATURE_PROPERTY_SET,
    "WATERBODY_ACOUSTIC_SIGNATURE_PROPERTY_SET", "ECC_WATERBODY_ACOUSTIC_SIGNATURE_PROPERTY_SET",
    "An <ACOUSTIC_SIGNATURE_PROPERTY_SET> describing a signal source in a"
    " <WATERBODY>.",
    2, &(EGBindingForEC[94]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_ACOUSTIC_TARGET_STRENGTH_PROPERTY_SET,
    "WATERBODY_ACOUSTIC_TARGET_STRENGTH_PROPERTY_SET", "ECC_WATERBODY_ACOUSTIC_TARGET_STRENGTH_PROPERTY_SET",
    "A <WATERBODY_PROPERTY_SET> describing acoustic target strength"
    " properties (for example: the amount of signal excess added to the"
    " return energy of an active sonar emission based on the reflective"
    " characteristics of an <OBJECT>).",
    3, &(EGBindingForEC[96]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_BANK,
    "WATERBODY_BANK", "ECC_WATERBODY_BANK",
    "The raised or sloping bank of <LAND> adjacent to a"
    " <LAND_WATER_BOUNDARY>; a waterbody bank.",
    3, &(EGBindingForEC[542]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_BASIN,
    "WATERBODY_BASIN", "ECC_WATERBODY_BASIN",
    "A delimited, principal division of a <WATERBODY>; a waterbody basin."
    " EXAMPLE <OCEAN_BASIN>.",
    2, &(EGBindingForEC[865]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"basin\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_BATHYMETRY_PROPERTY_SET,
    "WATERBODY_BATHYMETRY_PROPERTY_SET", "ECC_WATERBODY_BATHYMETRY_PROPERTY_SET",
    "A <WATERBODY_PROPERTY_SET> describing the <<DEPTH_OF_WATERBODY_FLOOR>>"
    " with respect to a <SURFACE_DATUM>; a waterbody bathymetry property"
    " set.",
    2, &(EGBindingForEC[1145]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_BIOLOGIC_SOUND_SOURCE,
    "WATERBODY_BIOLOGIC_SOUND_SOURCE", "ECC_WATERBODY_BIOLOGIC_SOUND_SOURCE",
    "A sound source of a biological nature in a <WATERBODY>. EXAMPLES"
    " <FISH_SCHOOL>, <WHALE_POD>.",
    2, &(EGBindingForEC[90]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_BOOM,
    "WATERBODY_BOOM", "ECC_WATERBODY_BOOM",
    "A floating <BARRIER> used to protect a <RIVER> or the mouth of a"
    " <HARBOUR> or to create a sheltered <WATERBODY_REGION> for storage"
    " purposes; a waterbody boom.",
    4, &(EGBindingForEC[669]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BD123]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_CURRENT,
    "WATERBODY_CURRENT", "ECC_WATERBODY_CURRENT",
    "A large <WATERBODY_REGION> containing a <WATER_CURRENT> that is"
    " relatively homogenous with respect to <<WATERBODY_TEMPERATURE>> or"
    " <<PRACTICAL_SALINITY>> and that differs from that of the adjacent"
    " <REGION>s; a waterbody current.",
    3, &(EGBindingForEC[869]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"current\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_EDDY,
    "WATERBODY_EDDY", "ECC_WATERBODY_EDDY",
    "An <EDDY> in a <WATERBODY>.",
    2, &(EGBindingForEC[872]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BD040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR,
    "WATERBODY_FLOOR", "ECC_WATERBODY_FLOOR",
    "The floor of a <WATERBODY>.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR_CANYON,
    "WATERBODY_FLOOR_CANYON", "ECC_WATERBODY_FLOOR_CANYON",
    "A deep, step-sided <TERRAIN_CHANNEL> in a <WATERBODY_FLOOR> the bottom"
    " of which grades continuously downward; a waterbody floor canyon.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"canyon: submarine\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR_PINNACLE,
    "WATERBODY_FLOOR_PINNACLE", "ECC_WATERBODY_FLOOR_PINNACLE",
    "A significant configuration of <WATERBODY_FLOOR> topography generally"
    " round in shape as viewed from above and of reduced depth at its"
    " centre; a waterbody floor pinnacle.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"pinnacle\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR_PROVINCE,
    "WATERBODY_FLOOR_PROVINCE", "ECC_WATERBODY_FLOOR_PROVINCE",
    "A <WATERBODY_FLOOR_REGION> identifiable by shared physiographic"
    " characteristics that are markedly in contrast with those in the"
    " adjacent <WATERBODY_FLOOR_REGION>s; a waterbody floor province.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[SUFN, \"province\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR_REGION,
    "WATERBODY_FLOOR_REGION", "ECC_WATERBODY_FLOOR_REGION",
    "A <REGION> of a <WATERBODY_FLOOR>.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR_RIDGE,
    "WATERBODY_FLOOR_RIDGE", "ECC_WATERBODY_FLOOR_RIDGE",
    "A <RIDGE> with steep sides and either irregular or smooth topography"
    " in a <WATERBODY_FLOOR>, often separating <WATERBODY_BASIN>s; a ridge.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_INFORMATIVE, "[S32, \"oceanic ridge\"]",
    "[S32, \"ridge\", a/b], [SP35, \"ridge\"], [SUFN, \"RIDGE\"]", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR_SONAR_RETURN,
    "WATERBODY_FLOOR_SONAR_RETURN", "ECC_WATERBODY_FLOOR_SONAR_RETURN",
    "A detectable active sonar return signal, from an <OBJECT> on a"
    " <WATERBODY_FLOOR>.",
    2, &(EGBindingForEC[99]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BE029]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION,
    "WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION", "ECC_WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION",
    "A significant configuration of <WATERBODY_FLOOR> topography.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BF011]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_FLOOR_TRENCH,
    "WATERBODY_FLOOR_TRENCH", "ECC_WATERBODY_FLOOR_TRENCH",
    "A significant long, narrow, and characteristically very deep and"
    " asymmetrical <TERRAIN_CHANNEL> in a <WATERBODY_FLOOR>, with"
    " relatively steep sides; a trench.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: CATSEA:6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_PARTITION,
    "WATERBODY_PARTITION", "ECC_WATERBODY_PARTITION",
    "A <STRUCTURE> separating portions of a <WATERBODY>; a partition.",
    2, &(EGBindingForEC[503]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FC035]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_PROPERTY_SET,
    "WATERBODY_PROPERTY_SET", "ECC_WATERBODY_PROPERTY_SET",
    "A <PROPERTY_SET> describing a <LOCATION> or <REGION> of a <WATERBODY>.",
    2, &(EGBindingForEC[1147]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_REGION,
    "WATERBODY_REGION", "ECC_WATERBODY_REGION",
    "A <REGION> of a <WATERBODY>.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_SHELTER_BASIN,
    "WATERBODY_SHELTER_BASIN", "ECC_WATERBODY_SHELTER_BASIN",
    "A sheltered <WATERBODY> available for port operations and connecting"
    " with another <WATERBODY> (for example: an outer <MARINE_PORT> and/or"
    " a <SEA>) sometimes by means of a <HYDROGRAPHIC_LOCK> or passage; a"
    " waterbody shelter basin.",
    6, &(EGBindingForEC[675]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"basin\" (sheltered)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_SHIPPING_PROPERTY_SET,
    "WATERBODY_SHIPPING_PROPERTY_SET", "ECC_WATERBODY_SHIPPING_PROPERTY_SET",
    "A <WATERBODY_PROPERTY_SET> describing shipping-related properties.",
    6, &(EGBindingForEC[772]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_SURFACE,
    "WATERBODY_SURFACE", "ECC_WATERBODY_SURFACE",
    "The <SURFACE> of a <WATERBODY>.",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_SURFACE_REGION,
    "WATERBODY_SURFACE_REGION", "ECC_WATERBODY_SURFACE_REGION",
    "A <REGION> of a <WATERBODY_SURFACE>.",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_SURFACE_SLICK,
    "WATERBODY_SURFACE_SLICK", "ECC_WATERBODY_SURFACE_SLICK",
    "A <WATERBODY_SURFACE_REGION> that is variable in size and markedly"
    " different in appearance (for example: in colour and/or oiliness) from"
    " adjacent <WATERBODY_SURFACE_REGION>s; a slick.",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"sea slick\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERBODY_TEMPERATURE_PROPERTY_SET,
    "WATERBODY_TEMPERATURE_PROPERTY_SET", "ECC_WATERBODY_TEMPERATURE_PROPERTY_SET",
    "A <WATERBODY_PROPERTY_SET> describing properties related to"
    " <<TEMPERATURE>>.",
    3, &(EGBindingForEC[1142]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_CHANNEL,
    "WATER_CHANNEL", "ECC_WATER_CHANNEL",
    "That part of a <WATERBODY>, sometimes dredged, that is deep enough for"
    " navigation through a <WATERBODY_SURFACE_REGION> that would otherwise"
    " not be navigable; a water channel. It is usually marked by a single"
    " or double line of <MARINE_AID_TO_NAVIGATION>s.",
    4, &(EGBindingForEC[702]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"channel\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_CHANNEL_EDGE,
    "WATER_CHANNEL_EDGE", "ECC_WATER_CHANNEL_EDGE",
    "The <BOUNDARY> delimiting the edge of a <WATER_CHANNEL> plus"
    " associated <NAVIGATION_MARK_AFLOAT>s and/or <NAVIGATION_MARK_FIXED>s;"
    " a water channel edge.",
    5, &(EGBindingForEC[505]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB007]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_CURRENT,
    "WATER_CURRENT", "ECC_WATER_CURRENT",
    "A <CURRENT> in a <WATERBODY>.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: CURENT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_CURRENT_PROPERTY_SET,
    "WATER_CURRENT_PROPERTY_SET", "ECC_WATER_CURRENT_PROPERTY_SET",
    "A <PROPERTY_SET> describing the average <<WATER_CURRENT_SPEED>> within"
    " a <REGION> of a <WATERBODY> as a function of time.",
    1, &(EGBindingForEC[37]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BG040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_DATA_COLLECTION_DEVICE,
    "WATER_DATA_COLLECTION_DEVICE", "ECC_WATER_DATA_COLLECTION_DEVICE",
    "A <DEVICE> used for the collection of hydrographic and oceanographic"
    " data.",
    2, &(EGBindingForEC[564]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BK030]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_DRIVEN_GRISTMILL,
    "WATER_DRIVEN_GRISTMILL", "ECC_WATER_DRIVEN_GRISTMILL",
    "A <STRUCTURE> equipped with water-driven <EQUIPMENT> for grinding"
    " grain into flour or meal; a water driven gristmill.",
    1, &(EGBindingForEC[25]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:22]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_GATHERING_REGION,
    "WATER_GATHERING_REGION", "ECC_WATER_GATHERING_REGION",
    "A protected (restricted use) <TERRAIN_SURFACE_REGION> incorporating"
    " <FACILITY>s for the collection of <WATER>, so designated in order to"
    " protect the <WATER> on and beneath the <TERRAIN> from being"
    " contaminated; a water gathering region.",
    3, &(EGBindingForEC[853]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: FA082]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_INTAKE,
    "WATER_INTAKE", "ECC_WATER_INTAKE",
    "A <SITE> where <WATER> is taken into a channel or <PIPE> from a"
    " <WATERBODY>, generally to supply an <AQUEDUCT> or"
    " <WATER_TREATMENT_FACILITY>; a water intake.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BH011]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_INTAKE_TOWER,
    "WATER_INTAKE_TOWER", "ECC_WATER_INTAKE_TOWER",
    "A <TOWER> associated with a <WATER_INTAKE>; a water intake tower.",
    2, &(EGBindingForEC[731]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BI050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_SURFACE_VESSEL,
    "WATER_SURFACE_VESSEL", "ECC_WATER_SURFACE_VESSEL",
    "A <VESSEL> capable of operation only on a <WATERBODY_SURFACE>; a water"
    " surface vessel. EXAMPLES Barge, boat, ship.",
    3, &(EGBindingForEC[838]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_TOWER,
    "WATER_TOWER", "ECC_WATER_TOWER",
    "A <TOWER> supporting an elevated <STORAGE_TANK> of <WATER>; a water"
    " tower.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: AM080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_TREATMENT_BED,
    "WATER_TREATMENT_BED", "ECC_WATER_TREATMENT_BED",
    "A <TRACT> for the treatment of <WATER> that consists of a bed of"
    " <MATERIAL> where <WATER> is aerated or filtered; a water treatment"
    " bed.",
    3, &(EGBindingForEC[991]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH040]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_TREATMENT_FACILITY,
    "WATER_TREATMENT_FACILITY", "ECC_WATER_TREATMENT_FACILITY",
    "A <FACILITY> including one or more <WATER_TREATMENT_STRUCTURE>s; a"
    " water treatment facility.",
    2, &(EGBindingForEC[999]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_TREATMENT_STRUCTURE,
    "WATER_TREATMENT_STRUCTURE", "ECC_WATER_TREATMENT_STRUCTURE",
    "A <STRUCTURE> containing layers of <MATERIAL> used to filter or aerate"
    " <WATER>; a water treatment structure.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, BFC:84]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_TURBULENCE,
    "WATER_TURBULENCE", "ECC_WATER_TURBULENCE",
    "A disturbance of <WATER> caused by the interaction of any combination"
    " of <WATER_WAVE>s, <WATER_CURRENT>s, <EDDY>s, tidal streams, <WIND>,"
    " <SHOAL>s, and obstructions; water turbulence.",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[FACC, Annex A: BG012]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATER_WAVE,
    "WATER_WAVE", "ECC_WATER_WAVE",
    "One of a succession of undulations that travel over a"
    " <WATERBODY_SURFACE>; a water wave [SOED, \"wave\", I.1.a].",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BG012]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERCOURSE,
    "WATERCOURSE", "ECC_WATERCOURSE",
    "An artificial or natural channel for the conveyance of <WATER>; a"
    " watercourse.",
    2, &(EGBindingForEC[848]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"watercourse\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERFALL,
    "WATERFALL", "ECC_WATERFALL",
    "A vertical or nearly vertical descent of a <WATERCOURSE>; a waterfall.",
    1, &(EGBindingForEC[22]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Object: WATFAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERING_HOLE,
    "WATERING_HOLE", "ECC_WATERING_HOLE",
    "A small natural <TERRAIN_DEPRESSION> in which <WATER> collects,"
    " especially a pool where <NON_HUMAN_ANIMAL>s come to drink; a watering"
    " hole [AHD, \"watering hole\", 1].",
    2, &(EGBindingForEC[320]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BB250]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WATERING_PLACE,
    "WATERING_PLACE", "ECC_WATERING_PLACE",
    "A <REGION> where supplies of <WATER> can be replenished; a watering"
    " place. EXAMPLES <SPRING>, <WELL> of <WATER>, <WATERING_HOLE>.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: BH170]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WAYPOINT,
    "WAYPOINT", "ECC_WAYPOINT",
    "A <LOCATION> used to define a <ROUTE>; a waypoint.",
    2, &(EGBindingForEC[1103]),
    EDCS_REF_TYP_INFORMATIVE, "[IAN11]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WEAPON,
    "WEAPON", "ECC_WEAPON",
    "<EQUIPMENT> intended to inflict bodily harm, especially one used in"
    " warfare to overcome an enemy and/or repel a hostile attack; a weapon"
    " [SOED, \"weapon\", 1a].",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WEAPON_FIGHTING_POS_ACCESS_ROUTE,
    "WEAPON_FIGHTING_POS_ACCESS_ROUTE", "ECC_WEAPON_FIGHTING_POS_ACCESS_ROUTE",
    "The concealed access <RAMP> or <LAND_TRANSPORTATION_ROUTE> leading"
    " from the exterior of a <WEAPON_FIGHTING_POSITION> to the"
    " <WEAPON_FULL_DEFILADE_POSITION> and then to the"
    " <WEAPON_HULL_DEFILADE_POSITION>; a weapon fighting position access"
    " route.",
    3, &(EGBindingForEC[1024]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WEAPON_FIGHTING_POSITION,
    "WEAPON_FIGHTING_POSITION", "ECC_WEAPON_FIGHTING_POSITION",
    "A <FIGHTING_POSITION> designed to accommodate an individual <WEAPON>,"
    " which may be mounted on a <VEHICLE>.",
    2, &(EGBindingForEC[1117]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WEAPON_FULL_DEFILADE_POSITION,
    "WEAPON_FULL_DEFILADE_POSITION", "ECC_WEAPON_FULL_DEFILADE_POSITION",
    "The <REGION> within a <WEAPON_FIGHTING_POSITION> in which the entire"
    " <WEAPON> is hidden from enemy view and fire; a weapon full defilade"
    " position.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WEAPON_HULL_DEFILADE_POSITION,
    "WEAPON_HULL_DEFILADE_POSITION", "ECC_WEAPON_HULL_DEFILADE_POSITION",
    "The <REGION> within a <WEAPON_FIGHTING_POSITION> in which only the"
    " fighting <COMPONENT> of the <WEAPON> is exposed to enemy fire or"
    " view; a weapon hull defilade position.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WEAPON_SYSTEM,
    "WEAPON_SYSTEM", "ECC_WEAPON_SYSTEM",
    "A <WEAPON> together with all the <EQUIPMENT> (for example: detection"
    " and control apparatus, a launcher, and/or a delivery <VEHICLE>)"
    " required to make use of it; a weapon system [SOED, \"weapon system\"].",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WEAPONS_RANGE,
    "WEAPONS_RANGE", "ECC_WEAPONS_RANGE",
    "A <FACILITY> designated for the purpose of discharging firearms or"
    " detonating <MUNITION>s; a weapons range, a firing range, or a gunnery"
    " range.",
    2, &(EGBindingForEC[1129]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: FA015]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WEATHER_STATION,
    "WEATHER_STATION", "ECC_WEATHER_STATION",
    "An <OBSERVATION_STATION> where meteorological data are gathered,"
    " recorded, and released; a weather station.",
    3, &(EGBindingForEC[402]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"weather station\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WELL,
    "WELL", "ECC_WELL",
    "An <EXCAVATION> drilled or dug into the <TERRAIN> for the extraction"
    " of liquids or gases; a well.",
    3, &(EGBindingForEC[901]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AA050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WELL_HEAD,
    "WELL_HEAD", "ECC_WELL_HEAD",
    "<EQUIPMENT> (for example: casing heads, lowermost and intermediate"
    " tubing heads, Christmas tree equipment with valves and fittings,"
    " and/or casing and tubing hangers) used on the <TERRAIN> to maintain"
    " control of an oil <WELL>; a well-head.",
    3, &(EGBindingForEC[588]),
    EDCS_REF_TYP_INFORMATIVE, "[GOFP, \"wellhead\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WET_DOCK,
    "WET_DOCK", "ECC_WET_DOCK",
    "A <DOCK> in which <WATER> can be maintained at any level by closing a"
    " <MARINE_GATE> when the <WATER> is at the desired level; a wet dock.",
    2, &(EGBindingForEC[824]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"dock: wet\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WETLAND,
    "WETLAND", "ECC_WETLAND",
    "A <TERRAIN_SURFACE_REGION> that is inundated or saturated by surface"
    " or ground <WATER> at a frequency and duration sufficient to support,"
    " and that under normal circumstances does support, a prevalence of"
    " <VEGETATION> typically adapted for life in conditions of saturated"
    " <SOIL>; a wetland [AHD, \"wetland\"]. EXAMPLES <SWAMP>, <MARSH>,"
    " <BOG>.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WHALE,
    "WHALE", "ECC_WHALE",
    "A large, marine <MAMMAL> of the order Cetacea, the members of which"
    " have forelimbs as fins, a tail with horizontal flukes, and nasal"
    " openings on top of the head; a whale [SOED, \"whale\", 1].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WHALE_POD,
    "WHALE_POD", "ECC_WHALE_POD",
    "A <POD> of <WHALE>s.",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WHARF,
    "WHARF", "ECC_WHARF",
    "A <STRUCTURE> serving as a berthing place for <VESSEL>s; a wharf.",
    3, &(EGBindingForEC[724]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"wharf\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIND,
    "WIND", "ECC_WIND",
    "A <CURRENT> of <AIR> moving relative to a <PLANETARY_SURFACE>; usually"
    " only the horizontal component is considered; wind.",
    1, &(EGBindingForEC[9]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, \"wind\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIND_INDICATOR,
    "WIND_INDICATOR", "ECC_WIND_INDICATOR",
    "A visual <DEVICE> used to provide <<WIND_DIRECTION>> and"
    " <<WIND_SPEED>> information; a wind indicator.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: GB080]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIND_MOTOR,
    "WIND_MOTOR", "ECC_WIND_MOTOR",
    "<EQUIPMENT> attached to a <TOWER> that generates electrical power from"
    " <WIND>; a wind motor.",
    3, &(EGBindingForEC[561]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AJ051]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIND_ROSE_PROPERTY_SET,
    "WIND_ROSE_PROPERTY_SET", "ECC_WIND_ROSE_PROPERTY_SET",
    "A <PROPERTY_SET> describing the relative frequency of the"
    " <<WIND_DIRECTION>>, and sometimes the frequencies of the"
    " <<WIND_SPEED>>s for different directions, experienced at a given"
    " <LOCATION> over a defined period of record; a wind rose.",
    1, &(EGBindingForEC[37]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"wind rose\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIND_TUNNEL,
    "WIND_TUNNEL", "ECC_WIND_TUNNEL",
    "<EQUIPMENT> through which <AIR> is forced at controlled velocities in"
    " order to study the effects of aerodynamic flow around airfoils, scale"
    " models, or other <OBJECT>s; a wind tunnel [AHD, \"wind tunnel\"].",
    2, &(EGBindingForEC[398]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIND_VANE,
    "WIND_VANE", "ECC_WIND_VANE",
    "A visual <DEVICE> used to indicate or measure <<WIND_DIRECTION>>; a"
    " wind vane.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"wind vane\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIND_WAVE,
    "WIND_WAVE", "ECC_WIND_WAVE",
    "A <WATER_WAVE> generated by friction between the <WIND> and a"
    " <WATERBODY_SURFACE>.",
    1, &(EGBindingForEC[54]),
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WINDMILL,
    "WINDMILL", "ECC_WINDMILL",
    "A <SYSTEM> of vanes attached to a <TOWER> and driven by <WIND>"
    " (excluding <WIND_MOTOR>s); a windmill.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AJ050]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WINDOW,
    "WINDOW", "ECC_WINDOW",
    "An <APERTURE> in a <WALL> or the side of a <BUILDING>, <VEHICLE>, or"
    " other <STRUCTURE> that admits light, <AIR>, or both and affords a"
    " view of what is outside or inside; a window [SOED, \"window\", 1.a].",
    2, &(EGBindingForEC[411]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIRE,
    "WIRE", "ECC_WIRE",
    "Metal wrought into the form of a slender rod or thread; wire [SOED,"
    " \"wire\", 1].",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WIRE_OBSTACLE,
    "WIRE_OBSTACLE", "ECC_WIRE_OBSTACLE",
    "A <TERRAIN_OBSTACLE> constructed of <WIRE>, usually containing barbs"
    " or razors; a wire obstacle.",
    1, &(EGBindingForEC[49]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WOODY_GRASS_LAND,
    "WOODY_GRASS_LAND", "ECC_WOODY_GRASS_LAND",
    "A <TRACT> covered by woody and/or tree-like grasses of the tropical or"
    " temperate <REGION>s that have jointed hollow stems with solid nodes"
    " (for example: <BAMBOO> and/or sugar cane); woody grass land.",
    3, &(EGBindingForEC[1074]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: EC010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WORSHIP_PLACE,
    "WORSHIP_PLACE", "ECC_WORSHIP_PLACE",
    "A place where religious worship is performed, especially a <BUILDING>"
    " designed for this purpose; a place of worship [SOED, \"place of"
    " worship\"]. EXAMPLES <CHAPEL>, <CHURCH>, <MOSQUE>, <SYNAGOGUE>.",
    1, &(EGBindingForEC[40]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_WRECKING_YARD,
    "WRECKING_YARD", "ECC_WRECKING_YARD",
    "An enclosed <TRACT> within which <EQUIPMENT> is dismantled or torn"
    " down; a wrecking yard.",
    3, &(EGBindingForEC[953]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AB010]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ZEBRA,
    "ZEBRA", "ECC_ZEBRA",
    "A wild African <HORSE>, characterized by having an erect mane, whitish"
    " hide and distinctively black stripes; a zebra [SOED, \"zebra\", 1].",
    2, &(EGBindingForEC[331]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ZOO,
    "ZOO", "ECC_ZOO",
    "An <ANIMAL_PARK> where wild <NON_HUMAN_ANIMAL>s are kept for study,"
    " breeding, or exhibition to the public; a zoo [SOED, \"zoo\", 1].",
    3, &(EGBindingForEC[342]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex A: AK180]",
    "", EDCS_CONCEPT_STAT_ISO },

    {ECC_ACOUSTIC_RAY_PATH,
    "ACOUSTIC_RAY_PATH", "ECC_ACOUSTIC_RAY_PATH",
    "An acoustic energy flux <RAY_PATH>.",
    1, &(EGBindingForEC[1]),
    EDCS_REF_TYP_INFORMATIVE, "[COA], [PUWS], [SP35]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_ACOUSTIC_EIGENRAY,
    "ACOUSTIC_EIGENRAY", "ECC_ACOUSTIC_EIGENRAY",
    "An <ACOUSTIC_RAY_PATH> from a specific source <LOCATION> to a specific"
    " observation point <LOCATION>; an acoustic eigenray.",
    2, &(EGBindingForEC[92]),
    EDCS_REF_TYP_INFORMATIVE, "[PUWS], [SP35], [COA]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_BENCH,
    "BENCH", "ECC_BENCH",
    "A long seat, usually of wood or <ROCK>, with or without a back; a"
    " bench [SOED, \"bench\", 1].",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_BUILDING_OVERHANG,
    "BUILDING_OVERHANG", "ECC_BUILDING_OVERHANG",
    "A canopy or <LEDGE> attached to the exterior of a <BUILDING> and"
    " projecting beyond the <EXTERIOR_WALL> of the <BUILDING>; a building"
    " overhang.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_DROP_ZONE,
    "DROP_ZONE", "ECC_DROP_ZONE",
    "The <REGION> of a <PLANETARY_SURFACE> into which <PERSONNEL> or"
    " <EQUIPMENT> are conveyed or dropped by means of a parachute from an"
    " <AIRCRAFT>; a drop zone.",
    2, &(EGBindingForEC[265]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_ELEVATED_EM_DUCT,
    "ELEVATED_EM_DUCT", "ECC_ELEVATED_EM_DUCT",
    "A layer of the <ATMOSPHERE> above a <PLANETARY_SURFACE>, in which"
    " electromagnetic waves are trapped due to changes in the index of"
    " refraction and the bottom of the layer is above the"
    " <PLANETARY_SURFACE>; an elevated electromagnetic duct.",
    1, &(EGBindingForEC[16]),
    EDCS_REF_TYP_INFORMATIVE, "[BATT]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_PLANTER,
    "PLANTER", "ECC_PLANTER",
    "A <CONTAINER> for growing or displaying <PLANT>s; a planter, [SOED,"
    " \"planter\", 6b].",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_ORNAMENT,
    "ORNAMENT", "ECC_ORNAMENT",
    "A physical <OBJECT> serving to adorn, beautify, or embellish; a"
    " decoration, an ornament, [SOED, \"ornament\", 2.a].",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_SECCHI_DISK,
    "SECCHI_DISK", "ECC_SECCHI_DISK",
    "A circular physical <OBJECT>, usually painted flat white, that is used"
    " to measure (subjectively) the <<DEPTH_BELOW_WATERBODY_SURFACE>> to"
    " which a <HUMAN> can see into a <WATERBODY>, in order to measure the"
    " transparency of the <WATER>; Secchi disk.",
    2, &(EGBindingForEC[1188]),
    EDCS_REF_TYP_INFORMATIVE, "[SECCHI]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_TABLE,
    "TABLE", "ECC_TABLE",
    "<FURNITURE> consisting of a raised flat top of solid <MATERIAL> (for"
    " example, wood or <ROCK>) and used to place physical <OBJECT>s on; a"
    " table, [SOED, \"table\", 13].",
    1, &(EGBindingForEC[0]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_POTENTIAL_TEMPERATURE_INVERSION_LAYER,
    "POTENTIAL_TEMPERATURE_INVERSION_LAYER", "ECC_POTENTIAL_TEMPERATURE_INVERSION_LAYER",
    "A layer in an <ATMOSPHERE> where the <<POTENTIAL_AIR_TEMPERATURE>>"
    " increases with <<HEIGHT_AGL>>; potential temperature inversion layer.",
    2, &(EGBindingForEC[396]),
    EDCS_REF_TYP_INFORMATIVE, "[PLKEMMM]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_OCEAN_FLOOR_TOPOGRAPHIC_CONFIGURATION,
    "OCEAN_FLOOR_TOPOGRAPHIC_CONFIGURATION", "ECC_OCEAN_FLOOR_TOPOGRAPHIC_CONFIGURATION",
    "A <WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION> of an <OCEAN_FLOOR>.",
    2, &(EGBindingForEC[1138]),
    EDCS_REF_TYP_INFORMATIVE, "[SUFN, page 2-1, sub-paragraph I-B; \"undersea feature\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_CAVE_NEXUS,
    "CAVE_NEXUS", "ECC_CAVE_NEXUS",
    "A representation network of passages composed of one or more"
    " interconnected <CAVE>s.",
    1, &(EGBindingForEC[35]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_EXTERIOR_WALL_OPENING,
    "EXTERIOR_WALL_OPENING", "ECC_EXTERIOR_WALL_OPENING",
    "An <APERTURE> in an <EXTERIOR_WALL> that supports the passage of"
    " <MATERIAL>s or visibility into the space enclosed by the"
    " <EXTERIOR_WALL>.",
    1, &(EGBindingForEC[10]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_SENSOR,
    "SENSOR", "ECC_SENSOR",
    "A <DEVICE> that detects or measures some condition or property and"
    " records, indicates, or otherwise responds to the information received"
    " [SOED, \"sensor\"].",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_WEAPON_TURRET_DEFILADE_POSITION,
    "WEAPON_TURRET_DEFILADE_POSITION", "ECC_WEAPON_TURRET_DEFILADE_POSITION",
    "The <REGION> within a <WEAPON_FIGHTING_POSITION> in which the hull and"
    " fighting <COMPONENT>s of the <WEAPON> are hidden from enemy view and"
    " fire; a weapon turret defilade position.",
    1, &(EGBindingForEC[34]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_STRUCTURAL_BEAM,
    "STRUCTURAL_BEAM", "ECC_STRUCTURAL_BEAM",
    "A rigid <STRUCTURAL_MEMBER> designed to carry and transfer transverse"
    " loads across space to supporting <COMPONENT>s; a structural beam.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_INFORMATIVE, "[VDARCH, \"beam\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_BICYCLE,
    "BICYCLE", "ECC_BICYCLE",
    "A <GROUND_VEHICLE> having two wheels turned by pedalling, typically"
    " with handle bars at the front and a seat or saddle for the rider; a"
    " bicycle [SOED, \"bicycle\"].",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_BICYCLE_LANE,
    "BICYCLE_LANE", "ECC_BICYCLE_LANE",
    "A <ROUTE_LANE>, typically narrow, that has been designated by"
    " <DISPLAY_SIGN>s and/or pavement markings for preferential or"
    " exclusive use by <BICYCLE>s; a bicycle lane.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_INFORMATIVE, "[MUTCD, \"bicycle lane\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_BUS,
    "BUS", "ECC_BUS",
    "A long <MOTOR_VEHICLE> specifically designed to transport multiple"
    " individual <HUMAN>s, often along a fixed <LAND_TRANSPORTATION_ROUTE>;"
    " a bus.",
    3, &(EGBindingForEC[1055]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, TUC:14]",
    "[AHD, \"bus\", 1]", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_CATCH_BASIN,
    "CATCH_BASIN", "ECC_CATCH_BASIN",
    "A receptacle located where a <STORM_DRAIN> empties into a <SEWER> and"
    " designed to trap solid <OBJECT>s and separate them from waste <WATER>"
    " flowing into the <SEWER>; a catch basin.",
    2, &(EGBindingForEC[597]),
    EDCS_REF_TYP_INFORMATIVE, "[AHD, \"catch basin\", 1], [VDARCH, \"catch basin\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_STRUCTURAL_COLUMN,
    "STRUCTURAL_COLUMN", "ECC_STRUCTURAL_COLUMN",
    "A rigid, relatively slender <STRUCTURAL_MEMBER> designed primarily to"
    " support axial, compressive loads applied at the member ends; a"
    " structural column.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_INFORMATIVE, "[VDARCH, \"column\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_CURB,
    "CURB", "ECC_CURB",
    "A raised border of hard <MATERIAL>, e.g. stone or concrete, often"
    " forming part of a gutter, along the <BOUNDARY> of a"
    " <LAND_TRANSPORTATION_ROUTE> and/or <VEHICLE_LOT>; a curb, also known"
    " as kerb.",
    3, &(EGBindingForEC[521]),
    EDCS_REF_TYP_INFORMATIVE, "[AHD, \"curb\", 1]",
    "[SOED, \"curb\", 8]", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_DISPLAY_SIGN_POLE,
    "DISPLAY_SIGN_POLE", "ECC_DISPLAY_SIGN_POLE",
    "A <POLE> with one or more <DISPLAY_SIGN>s attached.",
    2, &(EGBindingForEC[501]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_ELECTRICAL_SIGNAL_CABLE,
    "ELECTRICAL_SIGNAL_CABLE", "ECC_ELECTRICAL_SIGNAL_CABLE",
    "An <ELECTRICAL_CABLE> for transmitting electrical signals; an"
    " electrical signal cable.",
    3, &(EGBindingForEC[455]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_ELECTRICAL_SIGNAL_CONNECTION_LOCATION,
    "ELECTRICAL_SIGNAL_CONNECTION_LOCATION", "ECC_ELECTRICAL_SIGNAL_CONNECTION_LOCATION",
    "A <LOCATION> at which an external <ELECTRICAL_SIGNAL_CABLE> connects"
    " to the <SYSTEM> of internal <ELECTRICAL_SIGNAL_CABLE>s of a"
    " <BUILDING>; an electrical signal connection location.",
    4, &(EGBindingForEC[458]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_FIRE_HYDRANT,
    "FIRE_HYDRANT", "ECC_FIRE_HYDRANT",
    "A <PIPE> with a <VALVE> for drawing liquid <WATER> directly from a"
    " <WATER_MAIN> and with a <COMPONENT> providing an <APERTURE> to which"
    " a fire-hose can be attached; a fire hydrant [SOED, \"fire hydrant\"].",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_GUARD_RAIL,
    "GUARD_RAIL", "ECC_GUARD_RAIL",
    "A rail that acts as a safeguard to prevent <GROUND_VEHICLE>s and/or"
    " pedestrians from travelling into an unsafe <REGION>; a guard rail.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_MAILBOX,
    "MAILBOX", "ECC_MAILBOX",
    "A <CONTAINER> for delivery and/or collection of mail; a mailbox.",
    3, &(EGBindingForEC[440]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_METER,
    "METER", "ECC_METER",
    "A <DEVICE> for automatically measuring or indicating the quantity,"
    " degree, or rate of something; a meter [SOED, \"meter\", noun 2, 1].",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_PARKING_LANE,
    "PARKING_LANE", "ECC_PARKING_LANE",
    "A <ROUTE_LANE> at the <BOUNDARY> of a <ROAD> that is intended to serve"
    " as a parking <LOCATION> for <MOTOR_VEHICLE>s; a parking lane.",
    3, &(EGBindingForEC[1052]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_PARKING_METER,
    "PARKING_METER", "ECC_PARKING_METER",
    "A <METER>, usually coin-operated, receiving fees and registering the"
    " <<TIME_QUANTITY>> for which a <GROUND_VEHICLE> is allowed to park; a"
    " parking meter.",
    4, &(EGBindingForEC[599]),
    EDCS_REF_TYP_INFORMATIVE, "[SOED, \"parking meter\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_ELECTRICAL_POWER_CABLE,
    "ELECTRICAL_POWER_CABLE", "ECC_ELECTRICAL_POWER_CABLE",
    "An <ELECTRICAL_CABLE> for transmitting electrical power.",
    2, &(EGBindingForEC[621]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_ELECTRICAL_POWER_CONNECTION_LOCATION,
    "ELECTRICAL_POWER_CONNECTION_LOCATION", "ECC_ELECTRICAL_POWER_CONNECTION_LOCATION",
    "A <LOCATION> at which an external <ELECTRICAL_POWER_CABLE> connects to"
    " the <SYSTEM> of internal <ELECTRICAL_POWER_CABLE>s of a <BUILDING>;"
    " an electrical power connection location.",
    3, &(EGBindingForEC[623]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_PUBLIC_TELEPHONE,
    "PUBLIC_TELEPHONE", "ECC_PUBLIC_TELEPHONE",
    "A <TELEPHONE> that accesses the public land line <NETWORK> and is at a"
    " fixed <LOCATION> for use by the general public.",
    2, &(EGBindingForEC[425]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_PUMP,
    "PUMP", "ECC_PUMP",
    "A mechanical <DEVICE> used to move fluid by lifting, suction, or"
    " pressure; a pump.",
    1, &(EGBindingForEC[14]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"pump\", noun, 1]", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_RAILWAY_CROSSING_SIGN,
    "RAILWAY_CROSSING_SIGN", "ECC_RAILWAY_CROSSING_SIGN",
    "A <DISPLAY_SIGN> acting as a <TRAFFIC_CONTROL_DEVICE> that identifies"
    " the <LOCATION> of a <LEVEL_CROSSING> between a <RAILWAY> and a <ROAD>.",
    3, &(EGBindingForEC[603]),
    EDCS_REF_TYP_INFORMATIVE, "[MUTCD, 1A13, \"highway-rail grade crossing\"; 8B, \"signs and"
    " markings\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_ROAD_MARKINGS,
    "ROAD_MARKINGS", "ECC_ROAD_MARKINGS",
    "A symbol or group of symbols displayed as a marking on the <SURFACE>"
    " of a <ROAD> (for example: parking space markings, <SPEED_HUMP>"
    " markings, and/or <CENTRE_LINE>s) as a <TRAFFIC_CONTROL_DEVICE>.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[MUTCD, 3, \"Markings\"]", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_SEWER_LINE,
    "SEWER_LINE", "ECC_SEWER_LINE",
    "A <PIPELINE> for conveying sewage; a sewer line.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_SPEED_HUMP,
    "SPEED_HUMP", "ECC_SPEED_HUMP",
    "A raised strip that is set crosswise into the <SURFACE> of a <ROAD> or"
    " <VEHICLE_LOT> and is designed to slow down <GROUND_VEHICLE>s; a speed"
    " hump.",
    2, &(EGBindingForEC[1050]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"speed hump\"], [AHD, \"speed bump\"]", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_STORM_DRAIN,
    "STORM_DRAIN", "ECC_STORM_DRAIN",
    "A drain, usually located on, below, or near transportation <SURFACE>s,"
    " designed to provide drainage of <PRECIPITATION>; a storm drain.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_STREET_LAMP_POLE,
    "STREET_LAMP_POLE", "ECC_STREET_LAMP_POLE",
    "A <POLE> with one or more attached <STREET_LAMP>s.",
    3, &(EGBindingForEC[1001]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_STRUCTURAL_MEMBER,
    "STRUCTURAL_MEMBER", "ECC_STRUCTURAL_MEMBER",
    "One of the constituent <COMPONENT>s into which a <STRUCTURE> may be"
    " resolved by analysis, having a unitary character and exhibiting a"
    " unique behaviour under an applied load; structural member.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_INFORMATIVE, "[VDARCH, \"structural member\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_WALL_STUD,
    "WALL_STUD", "ECC_WALL_STUD",
    "A slender, upright <STRUCTURAL_MEMBER> of wood or metal that is part"
    " of a series of such members forming the structural frame of a <WALL>;"
    " a wall stud.",
    1, &(EGBindingForEC[43]),
    EDCS_REF_TYP_INFORMATIVE, "[VDARCH, \"stud\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_TELEPHONE,
    "TELEPHONE", "ECC_TELEPHONE",
    "A <DEVICE> for transmitting and receiving speech, sound, and/or"
    " electronic data in the form of a signal passed between instruments"
    " that are part of a communication <NETWORK>; a telephone [SOED,"
    " \"telephone\", A.2].",
    2, &(EGBindingForEC[425]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_TRAFFIC_CONTROL_DEVICE,
    "TRAFFIC_CONTROL_DEVICE", "ECC_TRAFFIC_CONTROL_DEVICE",
    "A <DISPLAY_SIGN>, <TRAFFIC_LIGHT>, <ROAD_MARKINGS>, or other <DEVICE>"
    " used to regulate, warn or guide traffic, placed on, over or adjacent"
    " to a <TRANSPORTATION_ROUTE> by authority of a public agency having"
    " jurisdiction; a traffic control device.",
    2, &(EGBindingForEC[616]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[MUTCD, 1A13, \"traffic control device\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_TRAFFIC_LIGHT,
    "TRAFFIC_LIGHT", "ECC_TRAFFIC_LIGHT",
    "A <TRAFFIC_CONTROL_DEVICE> which uses one or more <LIGHT>s to control"
    " traffic flow by displaying right-of-way information to <VEHICLE>s"
    " and/or pedestrians.",
    2, &(EGBindingForEC[1062]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_TRAFFIC_LIGHT_POLE,
    "TRAFFIC_LIGHT_POLE", "ECC_TRAFFIC_LIGHT_POLE",
    "A <POLE> that supports one or more mounted <TRAFFIC_LIGHT>s.",
    2, &(EGBindingForEC[1184]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_UNDERGROUND_STRUCTURE,
    "UNDERGROUND_STRUCTURE", "ECC_UNDERGROUND_STRUCTURE",
    "An underground <STRUCTURE>, such as a <BUNKER> or underground"
    " <PARKING_GARAGE>.",
    1, &(EGBindingForEC[41]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_VALVE,
    "VALVE", "ECC_VALVE",
    "A <DEVICE> that controls the passage of fluid through a <PIPE> or an"
    " <APERTURE>; a valve [SOED, \"valve\", 6].",
    2, &(EGBindingForEC[597]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {ECC_WATER_MAIN,
    "WATER_MAIN", "ECC_WATER_MAIN",
    "A main <PIPE> or conduit forming a <COMPONENT> of a public or"
    " community <SYSTEM> of <PIPE>s and <VALVE>s conveying non-waste liquid"
    " <WATER> to all service connections.",
    1, &(EGBindingForEC[26]),
    EDCS_REF_TYP_INFORMATIVE, "[VDARCH, \"water main\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY }

}; /* EDCS_Classification_Dictionary */

/*
 * STRUCT: EDCS_Classification_Label_Entry
 *
 *  Used within this file for the label lookup table.
 */
typedef struct
{
    EDCS_Classification_Code  code;
    EDCS_Classification_Label label;
} EDCS_Classification_Label_Entry;

static const EDCS_Classification_Label_Entry
EDCS_Classification_Labels[] =
{
    {ECC_ABATIS, "ABATIS"},
    {ECC_ABYSS, "ABYSS"},
    {ECC_ACCESS_ZONE, "ACCESS_ZONE"},
    {ECC_ACOUSTIC_DATA_COLLECTION_DEVICE, "ACOUSTIC_DATA_COLLECTION_DEVICE"},
    {ECC_ACOUSTIC_EIGENRAY, "ACOUSTIC_EIGENRAY"},
    {ECC_ACOUSTIC_RAY_PATH, "ACOUSTIC_RAY_PATH"},
    {ECC_ACOUSTIC_SIGNATURE_PROPERTY_SET, "ACOUSTIC_SIGNATURE_PROPERTY_SET"},
    {ECC_ACOUSTIC_STATION, "ACOUSTIC_STATION"},
    {ECC_ACOUSTIC_TRANSDUCER, "ACOUSTIC_TRANSDUCER"},
    {ECC_ADMINISTRATION_BUILDING, "ADMINISTRATION_BUILDING"},
    {ECC_ADMINISTRATIVE_BOUNDARY, "ADMINISTRATIVE_BOUNDARY"},
    {ECC_ADMINISTRATIVE_REGION, "ADMINISTRATIVE_REGION"},
    {ECC_AERATION_STRUCTURE, "AERATION_STRUCTURE"},
    {ECC_AERIAL, "AERIAL"},
    {ECC_AERIAL_CABLE, "AERIAL_CABLE"},
    {ECC_AERIAL_CABLE_PYLON, "AERIAL_CABLE_PYLON"},
    {ECC_AERIAL_CABLE_SET, "AERIAL_CABLE_SET"},
    {ECC_AERIAL_SUPPORT_MAST, "AERIAL_SUPPORT_MAST"},
    {ECC_AERODROME, "AERODROME"},
    {ECC_AERODROME_ELEVATION_POINT, "AERODROME_ELEVATION_POINT"},
    {ECC_AERODROME_LIGHTING, "AERODROME_LIGHTING"},
    {ECC_AERODROME_REVETMENT, "AERODROME_REVETMENT"},
    {ECC_AERODROME_TERMINAL, "AERODROME_TERMINAL"},
    {ECC_AERONAUTICAL_AID_TO_NAVIGATION, "AERONAUTICAL_AID_TO_NAVIGATION"},
    {ECC_AERONAUTICAL_COMM_FACILITY, "AERONAUTICAL_COMM_FACILITY"},
    {ECC_AERONAUTICAL_COMM_SERVICE, "AERONAUTICAL_COMM_SERVICE"},
    {ECC_AERONAUTICAL_LEAD_RADIAL, "AERONAUTICAL_LEAD_RADIAL"},
    {ECC_AEROSOL, "AEROSOL"},
    {ECC_AGRICULTURAL_FACILITY, "AGRICULTURAL_FACILITY"},
    {ECC_AID_TO_NAVIGATION, "AID_TO_NAVIGATION"},
    {ECC_AIR, "AIR"},
    {ECC_AIR_DEFENCE_ARTILLERY, "AIR_DEFENCE_ARTILLERY"},
    {ECC_AIR_MASS, "AIR_MASS"},
    {ECC_AIR_TRAFFIC_SERVICE, "AIR_TRAFFIC_SERVICE"},
    {ECC_AIR_TRANSPORTATION_ROUTE, "AIR_TRANSPORTATION_ROUTE"},
    {ECC_AIR_WARNING_LIGHT, "AIR_WARNING_LIGHT"},
    {ECC_AIRBURST_SMOKE, "AIRBURST_SMOKE"},
    {ECC_AIRCRAFT, "AIRCRAFT"},
    {ECC_AIRCRAFT_CARRIER, "AIRCRAFT_CARRIER"},
    {ECC_AIRCRAFT_HANGAR, "AIRCRAFT_HANGAR"},
    {ECC_AIRCRAFT_LANDING_ZONE, "AIRCRAFT_LANDING_ZONE"},
    {ECC_AIRCRAFT_MAINTENANCE_SHOP, "AIRCRAFT_MAINTENANCE_SHOP"},
    {ECC_AIRCRAFT_PARKING_FACILITY, "AIRCRAFT_PARKING_FACILITY"},
    {ECC_AIRCRAFT_STORAGE_TRACT, "AIRCRAFT_STORAGE_TRACT"},
    {ECC_AIRCRAFT_WRECKAGE, "AIRCRAFT_WRECKAGE"},
    {ECC_AIRFIELD, "AIRFIELD"},
    {ECC_AIRPORT, "AIRPORT"},
    {ECC_AIRSHIP, "AIRSHIP"},
    {ECC_AIRSPACE, "AIRSPACE"},
    {ECC_AIRSPACE_BOUNDARY, "AIRSPACE_BOUNDARY"},
    {ECC_AIRSPACE_BOUNDARY_COMPONENT, "AIRSPACE_BOUNDARY_COMPONENT"},
    {ECC_AIRSPACE_COMPONENT, "AIRSPACE_COMPONENT"},
    {ECC_AIRSTRIP, "AIRSTRIP"},
    {ECC_ALGA, "ALGA"},
    {ECC_ALKALI_FLAT, "ALKALI_FLAT"},
    {ECC_ALLUVIAL_FAN, "ALLUVIAL_FAN"},
    {ECC_AMBASSADORIAL_RESIDENCE, "AMBASSADORIAL_RESIDENCE"},
    {ECC_AMPHIBIAN, "AMPHIBIAN"},
    {ECC_AMPHIBIOUS_AIR_CUSHION_VEHICLE, "AMPHIBIOUS_AIR_CUSHION_VEHICLE"},
    {ECC_AMPHIBIOUS_ARMOURED_VEHICLE, "AMPHIBIOUS_ARMOURED_VEHICLE"},
    {ECC_AMPHIBIOUS_UTILITY_VEHICLE, "AMPHIBIOUS_UTILITY_VEHICLE"},
    {ECC_AMPHIBIOUS_VEHICLE, "AMPHIBIOUS_VEHICLE"},
    {ECC_AMPHITHEATRE, "AMPHITHEATRE"},
    {ECC_AMUSEMENT_PARK, "AMUSEMENT_PARK"},
    {ECC_AMUSEMENT_PARK_ATTRACTION, "AMUSEMENT_PARK_ATTRACTION"},
    {ECC_ANCHOR, "ANCHOR"},
    {ECC_ANCHOR_BERTH, "ANCHOR_BERTH"},
    {ECC_ANCHORAGE, "ANCHORAGE"},
    {ECC_ANCHORAGE_COMPLEX, "ANCHORAGE_COMPLEX"},
    {ECC_ANEMOMETER, "ANEMOMETER"},
    {ECC_ANIMAL, "ANIMAL"},
    {ECC_ANIMAL_PARK, "ANIMAL_PARK"},
    {ECC_ANIMAL_SANCTUARY, "ANIMAL_SANCTUARY"},
    {ECC_ANTE_ROOM, "ANTE_ROOM"},
    {ECC_APARTMENT_HOUSE, "APARTMENT_HOUSE"},
    {ECC_APERTURE, "APERTURE"},
    {ECC_APRON, "APRON"},
    {ECC_AQUEDUCT, "AQUEDUCT"},
    {ECC_AQUEDUCT_NEXUS, "AQUEDUCT_NEXUS"},
    {ECC_ARACHNID, "ARACHNID"},
    {ECC_ARBORETUM, "ARBORETUM"},
    {ECC_ARCADE, "ARCADE"},
    {ECC_ARCHAELOGICAL_SITE, "ARCHAELOGICAL_SITE"},
    {ECC_ARMISTICE_LINE, "ARMISTICE_LINE"},
    {ECC_ARMOURED_BRIDGE_LAUNCHER, "ARMOURED_BRIDGE_LAUNCHER"},
    {ECC_ARMOURED_FIGHTING_VEHICLE, "ARMOURED_FIGHTING_VEHICLE"},
    {ECC_ARMOURED_TRACKED_FIGHTING_VEHICLE, "ARMOURED_TRACKED_FIGHTING_VEHICLE"},
    {ECC_ARMOURED_TRACKED_VEHICLE, "ARMOURED_TRACKED_VEHICLE"},
    {ECC_ARMOURED_UTILITY_VEHICLE, "ARMOURED_UTILITY_VEHICLE"},
    {ECC_ARMOURY, "ARMOURY"},
    {ECC_ARRESTING_GEAR, "ARRESTING_GEAR"},
    {ECC_ARTHROPOD, "ARTHROPOD"},
    {ECC_ARTIFICIAL_SATELLITE, "ARTIFICIAL_SATELLITE"},
    {ECC_ARTILLERY_BATTERY, "ARTILLERY_BATTERY"},
    {ECC_ASPHALT_POOL, "ASPHALT_POOL"},
    {ECC_ASSEMBLY_PLANT, "ASSEMBLY_PLANT"},
    {ECC_ASTEROID, "ASTEROID"},
    {ECC_ASTRONOMIC_PROPERTY_SET, "ASTRONOMIC_PROPERTY_SET"},
    {ECC_ASTRONOMICAL_STATION, "ASTRONOMICAL_STATION"},
    {ECC_ASW_HELICOPTER, "ASW_HELICOPTER"},
    {ECC_ASW_WINGED_AIRCRAFT, "ASW_WINGED_AIRCRAFT"},
    {ECC_ATHLETIC_COMPLEX, "ATHLETIC_COMPLEX"},
    {ECC_ATHLETIC_FIELD, "ATHLETIC_FIELD"},
    {ECC_ATMOSPHERE, "ATMOSPHERE"},
    {ECC_ATMOSPHERE_PROPERTY_SET, "ATMOSPHERE_PROPERTY_SET"},
    {ECC_ATMOSPHERE_REGION, "ATMOSPHERE_REGION"},
    {ECC_ATMOSPHERIC_FRONT, "ATMOSPHERIC_FRONT"},
    {ECC_ATRIUM, "ATRIUM"},
    {ECC_ATS_ROUTE, "ATS_ROUTE"},
    {ECC_ATS_ROUTE_COMPONENT, "ATS_ROUTE_COMPONENT"},
    {ECC_ATTACK_HELICOPTER, "ATTACK_HELICOPTER"},
    {ECC_ATTACK_WINGED_AIRCRAFT, "ATTACK_WINGED_AIRCRAFT"},
    {ECC_ATTIC, "ATTIC"},
    {ECC_AUDITORIUM, "AUDITORIUM"},
    {ECC_AURORA, "AURORA"},
    {ECC_AURORA_OVAL, "AURORA_OVAL"},
    {ECC_AUTOMATED_TELLER_MACHINE, "AUTOMATED_TELLER_MACHINE"},
    {ECC_AUTOMOTIVE_PLANT, "AUTOMOTIVE_PLANT"},
    {ECC_AVIATION_NAVIGATION_MARKER, "AVIATION_NAVIGATION_MARKER"},
    {ECC_AVIATION_WAYPOINT, "AVIATION_WAYPOINT"},
    {ECC_BACKSHORE_PRECISE, "BACKSHORE_PRECISE"},
    {ECC_BALCONY, "BALCONY"},
    {ECC_BALLOON, "BALLOON"},
    {ECC_BAMBOO, "BAMBOO"},
    {ECC_BAMBOO_TRACT, "BAMBOO_TRACT"},
    {ECC_BANK_BUILDING, "BANK_BUILDING"},
    {ECC_BARN, "BARN"},
    {ECC_BARRACK, "BARRACK"},
    {ECC_BARREN_GROUND, "BARREN_GROUND"},
    {ECC_BARRIER, "BARRIER"},
    {ECC_BASEMENT, "BASEMENT"},
    {ECC_BAT, "BAT"},
    {ECC_BATHYMETRIC_PROVINCE, "BATHYMETRIC_PROVINCE"},
    {ECC_BATTLESHIP, "BATTLESHIP"},
    {ECC_BEACH, "BEACH"},
    {ECC_BEACH_PROFILE, "BEACH_PROFILE"},
    {ECC_BEACH_ZONE, "BEACH_ZONE"},
    {ECC_BEACON, "BEACON"},
    {ECC_BEDROCK, "BEDROCK"},
    {ECC_BENCH, "BENCH"},
    {ECC_BENCHMARK, "BENCHMARK"},
    {ECC_BICYCLE, "BICYCLE"},
    {ECC_BICYCLE_LANE, "BICYCLE_LANE"},
    {ECC_BIOLOGIC_HAZARD_REGION, "BIOLOGIC_HAZARD_REGION"},
    {ECC_BIOLUMINESCENCE, "BIOLUMINESCENCE"},
    {ECC_BIRD, "BIRD"},
    {ECC_BLAST_BARRIER, "BLAST_BARRIER"},
    {ECC_BLAST_FURNACE, "BLAST_FURNACE"},
    {ECC_BLIMP, "BLIMP"},
    {ECC_BLOCKHOUSE, "BLOCKHOUSE"},
    {ECC_BOARDWALK, "BOARDWALK"},
    {ECC_BOAT_LIFT, "BOAT_LIFT"},
    {ECC_BOAT_TURNING_BASIN, "BOAT_TURNING_BASIN"},
    {ECC_BOG, "BOG"},
    {ECC_BOLLARD, "BOLLARD"},
    {ECC_BOMBER_WINGED_AIRCRAFT, "BOMBER_WINGED_AIRCRAFT"},
    {ECC_BOMBORA_REGION, "BOMBORA_REGION"},
    {ECC_BOTANICAL_GARDEN, "BOTANICAL_GARDEN"},
    {ECC_BOTTOM_CHARACTERISTIC, "BOTTOM_CHARACTERISTIC"},
    {ECC_BOULDER_FIELD, "BOULDER_FIELD"},
    {ECC_BOUNDARY, "BOUNDARY"},
    {ECC_BOUNDARY_COMPONENT, "BOUNDARY_COMPONENT"},
    {ECC_BOUNDARY_MONUMENT, "BOUNDARY_MONUMENT"},
    {ECC_BREACH, "BREACH"},
    {ECC_BREACH_HOLE, "BREACH_HOLE"},
    {ECC_BREAK_LINE, "BREAK_LINE"},
    {ECC_BREAKER_REGION, "BREAKER_REGION"},
    {ECC_BREAKWATER, "BREAKWATER"},
    {ECC_BRIDGE, "BRIDGE"},
    {ECC_BRIDGE_PIER, "BRIDGE_PIER"},
    {ECC_BRIDGE_PLATFORM, "BRIDGE_PLATFORM"},
    {ECC_BRIDGE_SPAN, "BRIDGE_SPAN"},
    {ECC_BRIDGE_SUPERSTRUCTURE, "BRIDGE_SUPERSTRUCTURE"},
    {ECC_BRIDGE_TOWER, "BRIDGE_TOWER"},
    {ECC_BRUSH_LAND, "BRUSH_LAND"},
    {ECC_BUCKET_ELEVATOR, "BUCKET_ELEVATOR"},
    {ECC_BUDDHIST_TEMPLE, "BUDDHIST_TEMPLE"},
    {ECC_BUILDING, "BUILDING"},
    {ECC_BUILDING_COMPONENT, "BUILDING_COMPONENT"},
    {ECC_BUILDING_COMPONENT_ENTRANCE_OR_EXIT, "BUILDING_COMPONENT_ENTRANCE_OR_EXIT"},
    {ECC_BUILDING_OVERHANG, "BUILDING_OVERHANG"},
    {ECC_BUILDING_SUPERSTRUCTURE, "BUILDING_SUPERSTRUCTURE"},
    {ECC_BUILT_UP_REGION, "BUILT_UP_REGION"},
    {ECC_BUILT_UP_TERRAIN, "BUILT_UP_TERRAIN"},
    {ECC_BUNKER, "BUNKER"},
    {ECC_BUOY, "BUOY"},
    {ECC_BURIED_ELECTRICAL_CABLE, "BURIED_ELECTRICAL_CABLE"},
    {ECC_BURIED_POWER_TRANSMISSION_LINE, "BURIED_POWER_TRANSMISSION_LINE"},
    {ECC_BUS, "BUS"},
    {ECC_BUS_DEPOT, "BUS_DEPOT"},
    {ECC_BUS_STATION, "BUS_STATION"},
    {ECC_BUS_STOP, "BUS_STOP"},
    {ECC_BUSINESS_WINGED_AIRCRAFT, "BUSINESS_WINGED_AIRCRAFT"},
    {ECC_BUTTE, "BUTTE"},
    {ECC_CABIN, "CABIN"},
    {ECC_CADASTRAL_CONSTRUCTION, "CADASTRAL_CONSTRUCTION"},
    {ECC_CADASTRAL_CONTROL_POINT, "CADASTRAL_CONTROL_POINT"},
    {ECC_CAIRN, "CAIRN"},
    {ECC_CAISSON, "CAISSON"},
    {ECC_CALLING_IN_POINT, "CALLING_IN_POINT"},
    {ECC_CALVARY_CROSS, "CALVARY_CROSS"},
    {ECC_CAMBER, "CAMBER"},
    {ECC_CAMP, "CAMP"},
    {ECC_CAMPGROUND, "CAMPGROUND"},
    {ECC_CANAL, "CANAL"},
    {ECC_CANAL_NEXUS, "CANAL_NEXUS"},
    {ECC_CANAL_ROUTE, "CANAL_ROUTE"},
    {ECC_CANYON, "CANYON"},
    {ECC_CAPITOL_BUILDING, "CAPITOL_BUILDING"},
    {ECC_CARGO, "CARGO"},
    {ECC_CARGO_CONTAINER, "CARGO_CONTAINER"},
    {ECC_CARGO_CONTAINER_FACILITY, "CARGO_CONTAINER_FACILITY"},
    {ECC_CARNIVORE, "CARNIVORE"},
    {ECC_CARPENTRY_BUILDING, "CARPENTRY_BUILDING"},
    {ECC_CART_TRACK, "CART_TRACK"},
    {ECC_CASTLE, "CASTLE"},
    {ECC_CATALYTIC_CRACKER, "CATALYTIC_CRACKER"},
    {ECC_CATCH_BASIN, "CATCH_BASIN"},
    {ECC_CATHEDRAL, "CATHEDRAL"},
    {ECC_CATHOLIC_CATHEDRAL, "CATHOLIC_CATHEDRAL"},
    {ECC_CATWALK, "CATWALK"},
    {ECC_CAUSEWAY, "CAUSEWAY"},
    {ECC_CAVE, "CAVE"},
    {ECC_CAVE_NEXUS, "CAVE_NEXUS"},
    {ECC_CAVITATION, "CAVITATION"},
    {ECC_CAVITATION_NOISE, "CAVITATION_NOISE"},
    {ECC_CAY, "CAY"},
    {ECC_CEASE_FIRE_LINE, "CEASE_FIRE_LINE"},
    {ECC_CEILING_CRAWL_SPACE, "CEILING_CRAWL_SPACE"},
    {ECC_CELESTIAL_BODY, "CELESTIAL_BODY"},
    {ECC_CEMETERY, "CEMETERY"},
    {ECC_CEMETERY_BUILDING, "CEMETERY_BUILDING"},
    {ECC_CENTRE_LINE, "CENTRE_LINE"},
    {ECC_CEPHALOPOD, "CEPHALOPOD"},
    {ECC_CHAIN, "CHAIN"},
    {ECC_CHANCERY, "CHANCERY"},
    {ECC_CHANGE_LINE, "CHANGE_LINE"},
    {ECC_CHANGE_POINT, "CHANGE_POINT"},
    {ECC_CHAPEL, "CHAPEL"},
    {ECC_CHECKPOINT, "CHECKPOINT"},
    {ECC_CHEMICAL_HAZARD_REGION, "CHEMICAL_HAZARD_REGION"},
    {ECC_CHIMNEY, "CHIMNEY"},
    {ECC_CHRISTIAN_TEMPLE, "CHRISTIAN_TEMPLE"},
    {ECC_CHURCH, "CHURCH"},
    {ECC_CIRCULAR_IRRIGATION_SYSTEM, "CIRCULAR_IRRIGATION_SYSTEM"},
    {ECC_CISTERN, "CISTERN"},
    {ECC_CITY, "CITY"},
    {ECC_CITY_HALL, "CITY_HALL"},
    {ECC_CIVILIAN_MOTOR_VEHICLE, "CIVILIAN_MOTOR_VEHICLE"},
    {ECC_CIVILIAN_PERSONNEL, "CIVILIAN_PERSONNEL"},
    {ECC_CLAIM_LINE, "CLAIM_LINE"},
    {ECC_CLIFF, "CLIFF"},
    {ECC_CLIFF_BOTTOMLINE, "CLIFF_BOTTOMLINE"},
    {ECC_CLIFF_DWELLING, "CLIFF_DWELLING"},
    {ECC_CLIFF_TOPLINE, "CLIFF_TOPLINE"},
    {ECC_CLOSET, "CLOSET"},
    {ECC_CLOUD, "CLOUD"},
    {ECC_CLOUD_BASE, "CLOUD_BASE"},
    {ECC_CLOUD_LAYER, "CLOUD_LAYER"},
    {ECC_CLOUD_TOP, "CLOUD_TOP"},
    {ECC_COAST, "COAST"},
    {ECC_COASTLINE, "COASTLINE"},
    {ECC_COLD_FRONT, "COLD_FRONT"},
    {ECC_COLLEGIATE_CAMPUS, "COLLEGIATE_CAMPUS"},
    {ECC_COMBAT_STORES_VESSEL, "COMBAT_STORES_VESSEL"},
    {ECC_COMBAT_SUPPORT_VEHICLE, "COMBAT_SUPPORT_VEHICLE"},
    {ECC_COMBAT_SUPPORT_VESSEL, "COMBAT_SUPPORT_VESSEL"},
    {ECC_COMBATANT_VEHICLE, "COMBATANT_VEHICLE"},
    {ECC_COMBATANT_VESSEL, "COMBATANT_VESSEL"},
    {ECC_COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE, "COMBUSTION_PRODUCT_DISCHARGE_STRUCTURE"},
    {ECC_COMET, "COMET"},
    {ECC_COMMERCIAL_BUILDING, "COMMERCIAL_BUILDING"},
    {ECC_COMMERCIAL_HELICOPTER, "COMMERCIAL_HELICOPTER"},
    {ECC_COMMERCIAL_WINGED_AIRCRAFT, "COMMERCIAL_WINGED_AIRCRAFT"},
    {ECC_COMMUNICATION_FACILITY, "COMMUNICATION_FACILITY"},
    {ECC_COMMUNICATION_STATION, "COMMUNICATION_STATION"},
    {ECC_COMMUNICATION_TOWER, "COMMUNICATION_TOWER"},
    {ECC_COMMUNITY_RECREATION_BUILDING, "COMMUNITY_RECREATION_BUILDING"},
    {ECC_COMMUNITY_RECREATION_FACILITY, "COMMUNITY_RECREATION_FACILITY"},
    {ECC_COMPLEX_OUTLINE, "COMPLEX_OUTLINE"},
    {ECC_COMPLEX_TERMINAL_ROUTE, "COMPLEX_TERMINAL_ROUTE"},
    {ECC_COMPONENT, "COMPONENT"},
    {ECC_CONSULATE, "CONSULATE"},
    {ECC_CONTACT_ZONE, "CONTACT_ZONE"},
    {ECC_CONTAINER, "CONTAINER"},
    {ECC_CONTOUR, "CONTOUR"},
    {ECC_CONTROL_PANEL, "CONTROL_PANEL"},
    {ECC_CONTROL_TOWER, "CONTROL_TOWER"},
    {ECC_CONTROL_VALUE, "CONTROL_VALUE"},
    {ECC_CONTROLLED_AIRSPACE, "CONTROLLED_AIRSPACE"},
    {ECC_CONVENT, "CONVENT"},
    {ECC_CONVEYOR, "CONVEYOR"},
    {ECC_COOLING_TOWER, "COOLING_TOWER"},
    {ECC_CORAL, "CORAL"},
    {ECC_CORRECTIONAL_BUILDING, "CORRECTIONAL_BUILDING"},
    {ECC_CORRECTIONAL_FACILITY, "CORRECTIONAL_FACILITY"},
    {ECC_COUNTY_HALL, "COUNTY_HALL"},
    {ECC_COURTYARD, "COURTYARD"},
    {ECC_COVERED_WATERCOURSE, "COVERED_WATERCOURSE"},
    {ECC_CRANE, "CRANE"},
    {ECC_CREVASSE, "CREVASSE"},
    {ECC_CREVICE, "CREVICE"},
    {ECC_CRIB, "CRIB"},
    {ECC_CROP_LAND, "CROP_LAND"},
    {ECC_CROSS_COUNTRY_BARRIER, "CROSS_COUNTRY_BARRIER"},
    {ECC_CROSSING, "CROSSING"},
    {ECC_CRUISER, "CRUISER"},
    {ECC_CRUSTACEAN, "CRUSTACEAN"},
    {ECC_CULVERT, "CULVERT"},
    {ECC_CURB, "CURB"},
    {ECC_CURRENT, "CURRENT"},
    {ECC_CUSTOMS_HOUSE, "CUSTOMS_HOUSE"},
    {ECC_CYCLONE, "CYCLONE"},
    {ECC_DAM, "DAM"},
    {ECC_DATA_QUALITY_BOUNDARY, "DATA_QUALITY_BOUNDARY"},
    {ECC_DATA_QUALITY_REGION, "DATA_QUALITY_REGION"},
    {ECC_DATUM, "DATUM"},
    {ECC_DECONTAMINATION_PAD, "DECONTAMINATION_PAD"},
    {ECC_DEEP_SOUND_CHANNEL, "DEEP_SOUND_CHANNEL"},
    {ECC_DEEP_WATER_ROUTE, "DEEP_WATER_ROUTE"},
    {ECC_DEFACTO_BOUNDARY, "DEFACTO_BOUNDARY"},
    {ECC_DEFENSIVE_POSITION, "DEFENSIVE_POSITION"},
    {ECC_DEFENSIVE_POSITION_DEFILADE, "DEFENSIVE_POSITION_DEFILADE"},
    {ECC_DEFINED_WATER, "DEFINED_WATER"},
    {ECC_DEMILITARIZED_ZONE, "DEMILITARIZED_ZONE"},
    {ECC_DEPOT, "DEPOT"},
    {ECC_DEPTH_CONTOUR_LINE, "DEPTH_CONTOUR_LINE"},
    {ECC_DEPTH_CURVE, "DEPTH_CURVE"},
    {ECC_DEPTH_REGION, "DEPTH_REGION"},
    {ECC_DESCRIBED_POINT, "DESCRIBED_POINT"},
    {ECC_DESERT_REGION, "DESERT_REGION"},
    {ECC_DESTROYER, "DESTROYER"},
    {ECC_DETENTION_FACILITY, "DETENTION_FACILITY"},
    {ECC_DEVICE, "DEVICE"},
    {ECC_DIAGNOSTIC_POINT, "DIAGNOSTIC_POINT"},
    {ECC_DIAMOND_DUST, "DIAMOND_DUST"},
    {ECC_DIPLOMATIC_BUILDING, "DIPLOMATIC_BUILDING"},
    {ECC_DIRECTION, "DIRECTION"},
    {ECC_DIRIGIBLE, "DIRIGIBLE"},
    {ECC_DISCOLOURED_WATER, "DISCOLOURED_WATER"},
    {ECC_DISH_AERIAL, "DISH_AERIAL"},
    {ECC_DISPLAY_LIGHT, "DISPLAY_LIGHT"},
    {ECC_DISPLAY_SIGN, "DISPLAY_SIGN"},
    {ECC_DISPLAY_SIGN_POLE, "DISPLAY_SIGN_POLE"},
    {ECC_DISPOSAL_SITE, "DISPOSAL_SITE"},
    {ECC_DISTANCE_MARK, "DISTANCE_MARK"},
    {ECC_DISTANCE_POST, "DISTANCE_POST"},
    {ECC_DISTURBED_SOIL, "DISTURBED_SOIL"},
    {ECC_DOCK, "DOCK"},
    {ECC_DOOR, "DOOR"},
    {ECC_DORMITORY, "DORMITORY"},
    {ECC_DRAGLINE, "DRAGLINE"},
    {ECC_DRAGON_TEETH, "DRAGON_TEETH"},
    {ECC_DREDGE, "DREDGE"},
    {ECC_DRILLING_RIG, "DRILLING_RIG"},
    {ECC_DRILLING_RIG_SUPERSTRUCTURE, "DRILLING_RIG_SUPERSTRUCTURE"},
    {ECC_DRINKING_TROUGH, "DRINKING_TROUGH"},
    {ECC_DRIVE_IN_THEATRE, "DRIVE_IN_THEATRE"},
    {ECC_DRIVE_IN_THEATRE_SCREEN, "DRIVE_IN_THEATRE_SCREEN"},
    {ECC_DRIVEWAY, "DRIVEWAY"},
    {ECC_DRIZZLE, "DRIZZLE"},
    {ECC_DROP_GATE, "DROP_GATE"},
    {ECC_DROP_ZONE, "DROP_ZONE"},
    {ECC_DROVE, "DROVE"},
    {ECC_DRY_DOCK, "DRY_DOCK"},
    {ECC_DRY_LAKE, "DRY_LAKE"},
    {ECC_DRY_LAND, "DRY_LAND"},
    {ECC_DUST, "DUST"},
    {ECC_DUST_SUSPENSION, "DUST_SUSPENSION"},
    {ECC_DWELLING, "DWELLING"},
    {ECC_DYKE, "DYKE"},
    {ECC_DYKE_TOP, "DYKE_TOP"},
    {ECC_EARLY_WARNING_RADAR_SITE, "EARLY_WARNING_RADAR_SITE"},
    {ECC_EARTH, "EARTH"},
    {ECC_EDDY, "EDDY"},
    {ECC_EDDY_REGION, "EDDY_REGION"},
    {ECC_ELECTRICAL_CABLE, "ELECTRICAL_CABLE"},
    {ECC_ELECTRICAL_FIELD, "ELECTRICAL_FIELD"},
    {ECC_ELECTRICAL_POWER_CABLE, "ELECTRICAL_POWER_CABLE"},
    {ECC_ELECTRICAL_POWER_CONNECTION_LOCATION, "ELECTRICAL_POWER_CONNECTION_LOCATION"},
    {ECC_ELECTRICAL_SIGNAL_CABLE, "ELECTRICAL_SIGNAL_CABLE"},
    {ECC_ELECTRICAL_SIGNAL_CONNECTION_LOCATION, "ELECTRICAL_SIGNAL_CONNECTION_LOCATION"},
    {ECC_ELECTRICAL_SIGNAL_LINE, "ELECTRICAL_SIGNAL_LINE"},
    {ECC_ELECTRICAL_SIGNAL_LINE_PYLON, "ELECTRICAL_SIGNAL_LINE_PYLON"},
    {ECC_ELECTRIFIED_RAILWAY_PYLON, "ELECTRIFIED_RAILWAY_PYLON"},
    {ECC_ELECTROMAGNETIC_MATERIAL_PROPERTY_SET, "ELECTROMAGNETIC_MATERIAL_PROPERTY_SET"},
    {ECC_ELECTROMAGNETIC_PULSE, "ELECTROMAGNETIC_PULSE"},
    {ECC_ELECTROMAGNETIC_REFRACTIVE_EVAPORATIVE_DUCT, "ELECTROMAGNETIC_REFRACTIVE_EVAPORATIVE_DUCT"},
    {ECC_ELEVATED_ELECTRICAL_CABLE, "ELEVATED_ELECTRICAL_CABLE"},
    {ECC_ELEVATED_EM_DUCT, "ELEVATED_EM_DUCT"},
    {ECC_ELEVATION_CONTOUR_LINE, "ELEVATION_CONTOUR_LINE"},
    {ECC_EM_PULSE_COMPTON_EFFECT, "EM_PULSE_COMPTON_EFFECT"},
    {ECC_EMBANKMENT, "EMBANKMENT"},
    {ECC_EMBASSY, "EMBASSY"},
    {ECC_EMBASSY_COMPOUND, "EMBASSY_COMPOUND"},
    {ECC_ENGINE_TEST_CELL, "ENGINE_TEST_CELL"},
    {ECC_ENGINEER_BRIDGE, "ENGINEER_BRIDGE"},
    {ECC_ENGINEER_DITCH, "ENGINEER_DITCH"},
    {ECC_ENGINEER_TRENCH, "ENGINEER_TRENCH"},
    {ECC_EQUIPMENT, "EQUIPMENT"},
    {ECC_EQUIPMENT_COMPONENT, "EQUIPMENT_COMPONENT"},
    {ECC_ESCALATOR, "ESCALATOR"},
    {ECC_ESCARPMENT, "ESCARPMENT"},
    {ECC_ESKER, "ESKER"},
    {ECC_ESTUARY, "ESTUARY"},
    {ECC_EXCAVATING_MACHINE, "EXCAVATING_MACHINE"},
    {ECC_EXCAVATION, "EXCAVATION"},
    {ECC_EXHIBITION_GROUND, "EXHIBITION_GROUND"},
    {ECC_EXPLOSIVE_CHARGE, "EXPLOSIVE_CHARGE"},
    {ECC_EXPLOSIVE_LAND_MINE, "EXPLOSIVE_LAND_MINE"},
    {ECC_EXPLOSIVE_MINE, "EXPLOSIVE_MINE"},
    {ECC_EXPLOSIVE_NAVAL_MINE, "EXPLOSIVE_NAVAL_MINE"},
    {ECC_EXPOSED_BEDROCK, "EXPOSED_BEDROCK"},
    {ECC_EXTERIOR_HALLWAY, "EXTERIOR_HALLWAY"},
    {ECC_EXTERIOR_WALL, "EXTERIOR_WALL"},
    {ECC_EXTERIOR_WALL_OPENING, "EXTERIOR_WALL_OPENING"},
    {ECC_EXTRACTION_FACILITY, "EXTRACTION_FACILITY"},
    {ECC_EXTRACTION_MINE, "EXTRACTION_MINE"},
    {ECC_FABRICATION_BUILDING, "FABRICATION_BUILDING"},
    {ECC_FABRICATION_FACILITY, "FABRICATION_FACILITY"},
    {ECC_FACILITY, "FACILITY"},
    {ECC_FACTORY, "FACTORY"},
    {ECC_FAIRGROUND, "FAIRGROUND"},
    {ECC_FARM, "FARM"},
    {ECC_FARM_BUILDING, "FARM_BUILDING"},
    {ECC_FARM_STORAGE_STRUCTURE, "FARM_STORAGE_STRUCTURE"},
    {ECC_FENCE, "FENCE"},
    {ECC_FENDER_CUSHION, "FENDER_CUSHION"},
    {ECC_FERN, "FERN"},
    {ECC_FERRY, "FERRY"},
    {ECC_FERRY_CROSSING, "FERRY_CROSSING"},
    {ECC_FERRY_LOCATION, "FERRY_LOCATION"},
    {ECC_FIDUCIAL_POINT, "FIDUCIAL_POINT"},
    {ECC_FIELD_ARTILLERY, "FIELD_ARTILLERY"},
    {ECC_FIGHTER_WINGED_AIRCRAFT, "FIGHTER_WINGED_AIRCRAFT"},
    {ECC_FIGHTING_POSITION, "FIGHTING_POSITION"},
    {ECC_FILLED_TERRAIN, "FILLED_TERRAIN"},
    {ECC_FILTRATION_BED, "FILTRATION_BED"},
    {ECC_FILTRATION_BUILDING, "FILTRATION_BUILDING"},
    {ECC_FIORD, "FIORD"},
    {ECC_FIRE_AND_POLICE_STATION, "FIRE_AND_POLICE_STATION"},
    {ECC_FIRE_ESCAPE, "FIRE_ESCAPE"},
    {ECC_FIRE_HYDRANT, "FIRE_HYDRANT"},
    {ECC_FIRE_STATION, "FIRE_STATION"},
    {ECC_FIREBREAK, "FIREBREAK"},
    {ECC_FISH, "FISH"},
    {ECC_FISH_HATCHERY, "FISH_HATCHERY"},
    {ECC_FISH_LADDER, "FISH_LADDER"},
    {ECC_FISH_SCHOOL, "FISH_SCHOOL"},
    {ECC_FISH_STAKE_REGION, "FISH_STAKE_REGION"},
    {ECC_FISH_TRAP, "FISH_TRAP"},
    {ECC_FISHING_BOAT, "FISHING_BOAT"},
    {ECC_FISHING_FACILITY, "FISHING_FACILITY"},
    {ECC_FISHING_HARBOUR, "FISHING_HARBOUR"},
    {ECC_FLAGPOLE, "FLAGPOLE"},
    {ECC_FLARE_PIPE, "FLARE_PIPE"},
    {ECC_FLEXIBLE_RESTRAINT, "FLEXIBLE_RESTRAINT"},
    {ECC_FLIGHT_LEVEL, "FLIGHT_LEVEL"},
    {ECC_FLOATING_BREAKWATER, "FLOATING_BREAKWATER"},
    {ECC_FLOATING_DOCK, "FLOATING_DOCK"},
    {ECC_FLOOD_BARRAGE, "FLOOD_BARRAGE"},
    {ECC_FLOOD_BASIN, "FLOOD_BASIN"},
    {ECC_FLOOR, "FLOOR"},
    {ECC_FLOOR_CRAWL_SPACE, "FLOOR_CRAWL_SPACE"},
    {ECC_FLOOR_LEVEL, "FLOOR_LEVEL"},
    {ECC_FLUID_BOUNDARY_LAYER, "FLUID_BOUNDARY_LAYER"},
    {ECC_FLUME, "FLUME"},
    {ECC_FOG, "FOG"},
    {ECC_FOG_REGION, "FOG_REGION"},
    {ECC_FOG_SIGNAL_DEVICE, "FOG_SIGNAL_DEVICE"},
    {ECC_FOOD_OVEN, "FOOD_OVEN"},
    {ECC_FORD, "FORD"},
    {ECC_FORESHORE, "FORESHORE"},
    {ECC_FORESHORE_PRECISE, "FORESHORE_PRECISE"},
    {ECC_FOREST, "FOREST"},
    {ECC_FOREST_PRESERVE, "FOREST_PRESERVE"},
    {ECC_FORT, "FORT"},
    {ECC_FORTIFICATION, "FORTIFICATION"},
    {ECC_FOUNTAIN, "FOUNTAIN"},
    {ECC_FREEZING_DRIZZLE, "FREEZING_DRIZZLE"},
    {ECC_FREEZING_RAIN, "FREEZING_RAIN"},
    {ECC_FRIGATE, "FRIGATE"},
    {ECC_FROZEN_PRECIPITATION_FIELD, "FROZEN_PRECIPITATION_FIELD"},
    {ECC_FUNGUS, "FUNGUS"},
    {ECC_FURNACE, "FURNACE"},
    {ECC_FURNITURE, "FURNITURE"},
    {ECC_GALAXY, "GALAXY"},
    {ECC_GANTRY, "GANTRY"},
    {ECC_GASTROPOD, "GASTROPOD"},
    {ECC_GATE, "GATE"},
    {ECC_GEODETIC_DATUM, "GEODETIC_DATUM"},
    {ECC_GEOGRAPHIC_BASIN, "GEOGRAPHIC_BASIN"},
    {ECC_GEOGRAPHIC_INFORMATION, "GEOGRAPHIC_INFORMATION"},
    {ECC_GEOLOGIC_FAULT, "GEOLOGIC_FAULT"},
    {ECC_GEOPHYSICAL_SURVEY_PATH, "GEOPHYSICAL_SURVEY_PATH"},
    {ECC_GEOPHYSICAL_SURVEY_POINT, "GEOPHYSICAL_SURVEY_POINT"},
    {ECC_GEOTHERMAL_OBJECT, "GEOTHERMAL_OBJECT"},
    {ECC_GLACIER, "GLACIER"},
    {ECC_GLADE, "GLADE"},
    {ECC_GOLF_COURSE, "GOLF_COURSE"},
    {ECC_GOLF_DRIVING_RANGE, "GOLF_DRIVING_RANGE"},
    {ECC_GORGE, "GORGE"},
    {ECC_GOVERNMENT_BUILDING, "GOVERNMENT_BUILDING"},
    {ECC_GOVERNMENT_FACILITY, "GOVERNMENT_FACILITY"},
    {ECC_GRADATION_WORKS, "GRADATION_WORKS"},
    {ECC_GRAIN_ELEVATOR, "GRAIN_ELEVATOR"},
    {ECC_GRAIN_STORAGE_STRUCTURE, "GRAIN_STORAGE_STRUCTURE"},
    {ECC_GRANDSTAND, "GRANDSTAND"},
    {ECC_GRASS, "GRASS"},
    {ECC_GRASS_LAND, "GRASS_LAND"},
    {ECC_GRAVE_MARKER, "GRAVE_MARKER"},
    {ECC_GREEN_SPACE, "GREEN_SPACE"},
    {ECC_GREENHOUSE, "GREENHOUSE"},
    {ECC_GROIN, "GROIN"},
    {ECC_GROUND_SURFACE_ELEMENT, "GROUND_SURFACE_ELEMENT"},
    {ECC_GROUND_VEHICLE, "GROUND_VEHICLE"},
    {ECC_GROUNDS, "GROUNDS"},
    {ECC_GUARD_RAIL, "GUARD_RAIL"},
    {ECC_GUARD_TOWER, "GUARD_TOWER"},
    {ECC_GUARDHOUSE, "GUARDHOUSE"},
    {ECC_GUARDROOM, "GUARDROOM"},
    {ECC_GUIDED_MISSILE_CRUISER, "GUIDED_MISSILE_CRUISER"},
    {ECC_GUIDED_MISSILE_DESTROYER, "GUIDED_MISSILE_DESTROYER"},
    {ECC_GUIDED_MISSILE_FRIGATE, "GUIDED_MISSILE_FRIGATE"},
    {ECC_GULLY, "GULLY"},
    {ECC_HAIL, "HAIL"},
    {ECC_HALLWAY, "HALLWAY"},
    {ECC_HARBOUR, "HARBOUR"},
    {ECC_HARBOUR_COMPLEX, "HARBOUR_COMPLEX"},
    {ECC_HARD_STANDING, "HARD_STANDING"},
    {ECC_HARDENED_AIRCRAFT_SHELTER, "HARDENED_AIRCRAFT_SHELTER"},
    {ECC_HAYSTACK, "HAYSTACK"},
    {ECC_HAZARD_MARKER, "HAZARD_MARKER"},
    {ECC_HEALTH_OFFICE, "HEALTH_OFFICE"},
    {ECC_HEAT_RADIATOR, "HEAT_RADIATOR"},
    {ECC_HEATING_FACILITY, "HEATING_FACILITY"},
    {ECC_HEAVY_INDUSTRIAL_FACILITY, "HEAVY_INDUSTRIAL_FACILITY"},
    {ECC_HEDGEROW, "HEDGEROW"},
    {ECC_HELICOPTER, "HELICOPTER"},
    {ECC_HELICOPTER_LANDING_PAD, "HELICOPTER_LANDING_PAD"},
    {ECC_HELIPORT, "HELIPORT"},
    {ECC_HIGH_CLOUD, "HIGH_CLOUD"},
    {ECC_HIGH_PRESSURE_CENTRE, "HIGH_PRESSURE_CENTRE"},
    {ECC_HILL, "HILL"},
    {ECC_HINDU_TEMPLE, "HINDU_TEMPLE"},
    {ECC_HISTORICAL_BUILT_UP_REGION, "HISTORICAL_BUILT_UP_REGION"},
    {ECC_HOAR_FROST, "HOAR_FROST"},
    {ECC_HOLDING_PATTERN_REGION, "HOLDING_PATTERN_REGION"},
    {ECC_HOP_FIELD, "HOP_FIELD"},
    {ECC_HOPPER, "HOPPER"},
    {ECC_HORSE, "HORSE"},
    {ECC_HOSPITAL_BUILDING, "HOSPITAL_BUILDING"},
    {ECC_HOSTEL, "HOSTEL"},
    {ECC_HOTEL, "HOTEL"},
    {ECC_HOUSE, "HOUSE"},
    {ECC_HULK, "HULK"},
    {ECC_HUMAN, "HUMAN"},
    {ECC_HUMMOCK, "HUMMOCK"},
    {ECC_HURRICANE, "HURRICANE"},
    {ECC_HUT, "HUT"},
    {ECC_HYDROFOIL_VESSEL, "HYDROFOIL_VESSEL"},
    {ECC_HYDROGRAPHIC_LOCK, "HYDROGRAPHIC_LOCK"},
    {ECC_HYDROGRAPHIC_SURVEY_CONTACT, "HYDROGRAPHIC_SURVEY_CONTACT"},
    {ECC_HYDROGRAPHY, "HYDROGRAPHY"},
    {ECC_HYDROLOGIC_OBJECT, "HYDROLOGIC_OBJECT"},
    {ECC_ICE, "ICE"},
    {ECC_ICE_BOOM, "ICE_BOOM"},
    {ECC_ICE_CLIFF, "ICE_CLIFF"},
    {ECC_ICE_FIELD, "ICE_FIELD"},
    {ECC_ICE_GLAZE, "ICE_GLAZE"},
    {ECC_ICE_KEEL, "ICE_KEEL"},
    {ECC_ICE_PEAK, "ICE_PEAK"},
    {ECC_ICE_PELLETS, "ICE_PELLETS"},
    {ECC_ICE_SHELF, "ICE_SHELF"},
    {ECC_ICE_SLUDGE, "ICE_SLUDGE"},
    {ECC_ICEBERG, "ICEBERG"},
    {ECC_IFR_REGION, "IFR_REGION"},
    {ECC_ILS_COMPONENT, "ILS_COMPONENT"},
    {ECC_ILS_TERMINAL_COMPONENT, "ILS_TERMINAL_COMPONENT"},
    {ECC_INCINERATOR, "INCINERATOR"},
    {ECC_INDIGENOUS_BURIAL_GROUND, "INDIGENOUS_BURIAL_GROUND"},
    {ECC_INDIGENOUS_PEOPLES_RESERVE, "INDIGENOUS_PEOPLES_RESERVE"},
    {ECC_INDIVIDUAL_FIGHTING_POSITION, "INDIVIDUAL_FIGHTING_POSITION"},
    {ECC_INDUSTRIAL_BUILDING, "INDUSTRIAL_BUILDING"},
    {ECC_INDUSTRIAL_OVEN, "INDUSTRIAL_OVEN"},
    {ECC_INDUSTRIAL_WORKS, "INDUSTRIAL_WORKS"},
    {ECC_INFANTRY_TRENCH, "INFANTRY_TRENCH"},
    {ECC_INFRARED_MATERIAL_PROPERTY_SET, "INFRARED_MATERIAL_PROPERTY_SET"},
    {ECC_INLAND_SHORELINE, "INLAND_SHORELINE"},
    {ECC_INLAND_WATER, "INLAND_WATER"},
    {ECC_INLAND_WATER_BOTTOM, "INLAND_WATER_BOTTOM"},
    {ECC_INLAND_WATER_ELEVATION, "INLAND_WATER_ELEVATION"},
    {ECC_INLAND_WATER_SURFACE, "INLAND_WATER_SURFACE"},
    {ECC_INLET, "INLET"},
    {ECC_INS_ALIGNMENT_PAD, "INS_ALIGNMENT_PAD"},
    {ECC_INSECT, "INSECT"},
    {ECC_INSTITUTIONAL_FACILITY, "INSTITUTIONAL_FACILITY"},
    {ECC_INTEREST_SITE, "INTEREST_SITE"},
    {ECC_INTERIOR_WALL, "INTERIOR_WALL"},
    {ECC_INTERIOR_WALL_OPENING, "INTERIOR_WALL_OPENING"},
    {ECC_INTERNATIONAL_DATE_LINE, "INTERNATIONAL_DATE_LINE"},
    {ECC_INTERPLANETARY_MAGNETIC_FIELD, "INTERPLANETARY_MAGNETIC_FIELD"},
    {ECC_INUNDATED_LAND, "INUNDATED_LAND"},
    {ECC_INVERTEBRATE, "INVERTEBRATE"},
    {ECC_IONOSPHERE, "IONOSPHERE"},
    {ECC_IONOSPHERE_ELECTRON_DENSITY_PROPERTY_SET, "IONOSPHERE_ELECTRON_DENSITY_PROPERTY_SET"},
    {ECC_IONOSPHERE_SCINTILLATION_PROPERTY_SET, "IONOSPHERE_SCINTILLATION_PROPERTY_SET"},
    {ECC_IONOSPHERIC_D_REGION, "IONOSPHERIC_D_REGION"},
    {ECC_IONOSPHERIC_E_REGION, "IONOSPHERIC_E_REGION"},
    {ECC_IONOSPHERIC_F1_REGION, "IONOSPHERIC_F1_REGION"},
    {ECC_IONOSPHERIC_F2_REGION, "IONOSPHERIC_F2_REGION"},
    {ECC_IRRIGATION_DITCH, "IRRIGATION_DITCH"},
    {ECC_ISLAND, "ISLAND"},
    {ECC_ISOGONIC_LINE, "ISOGONIC_LINE"},
    {ECC_ISOPLETH, "ISOPLETH"},
    {ECC_ISTHMUS, "ISTHMUS"},
    {ECC_JAIL, "JAIL"},
    {ECC_JETTY, "JETTY"},
    {ECC_JUNGLE, "JUNGLE"},
    {ECC_JUPITER, "JUPITER"},
    {ECC_KELP_BED, "KELP_BED"},
    {ECC_KENNEL, "KENNEL"},
    {ECC_KILN, "KILN"},
    {ECC_KUIPER_BELT, "KUIPER_BELT"},
    {ECC_LAGOON, "LAGOON"},
    {ECC_LAKE, "LAKE"},
    {ECC_LAKE_NEXUS, "LAKE_NEXUS"},
    {ECC_LAND, "LAND"},
    {ECC_LAND_EASEMENT, "LAND_EASEMENT"},
    {ECC_LAND_FISH_HATCHERY, "LAND_FISH_HATCHERY"},
    {ECC_LAND_FLOODING_PERIODICALLY, "LAND_FLOODING_PERIODICALLY"},
    {ECC_LAND_MINEFIELD, "LAND_MINEFIELD"},
    {ECC_LAND_TRANSPORTATION_ROUTE, "LAND_TRANSPORTATION_ROUTE"},
    {ECC_LAND_WATER_BOUNDARY, "LAND_WATER_BOUNDARY"},
    {ECC_LANDFILL, "LANDFILL"},
    {ECC_LANDING_CRAFT, "LANDING_CRAFT"},
    {ECC_LANDSLIDE, "LANDSLIDE"},
    {ECC_LATERAL_BUOYAGE_INDICATION, "LATERAL_BUOYAGE_INDICATION"},
    {ECC_LAUNCH_PAD, "LAUNCH_PAD"},
    {ECC_LEDGE, "LEDGE"},
    {ECC_LEGATION_BUILDING, "LEGATION_BUILDING"},
    {ECC_LEVEE, "LEVEE"},
    {ECC_LEVEL_CROSSING, "LEVEL_CROSSING"},
    {ECC_LIBRARY, "LIBRARY"},
    {ECC_LICHEN, "LICHEN"},
    {ECC_LIFT, "LIFT"},
    {ECC_LIFT_SHAFT, "LIFT_SHAFT"},
    {ECC_LIGHT, "LIGHT"},
    {ECC_LIGHT_INDUSTRIAL_FACILITY, "LIGHT_INDUSTRIAL_FACILITY"},
    {ECC_LIGHT_SUPPORT_STRUCTURE, "LIGHT_SUPPORT_STRUCTURE"},
    {ECC_LIGHT_WINGED_AIRCRAFT, "LIGHT_WINGED_AIRCRAFT"},
    {ECC_LIGHTHOUSE, "LIGHTHOUSE"},
    {ECC_LIGHTING, "LIGHTING"},
    {ECC_LIGHTNING, "LIGHTNING"},
    {ECC_LIGHTSHIP, "LIGHTSHIP"},
    {ECC_LINE, "LINE"},
    {ECC_LIQUID_DIFFUSER, "LIQUID_DIFFUSER"},
    {ECC_LIVESTOCK_PEN, "LIVESTOCK_PEN"},
    {ECC_LIVING_ORGANISM, "LIVING_ORGANISM"},
    {ECC_LOAD_CABLE, "LOAD_CABLE"},
    {ECC_LOCAL_PARK, "LOCAL_PARK"},
    {ECC_LOCALIZED_ATM_SUSPENSION, "LOCALIZED_ATM_SUSPENSION"},
    {ECC_LOCATION, "LOCATION"},
    {ECC_LOCATION_PROPERTY_SET, "LOCATION_PROPERTY_SET"},
    {ECC_LOCK_BASIN, "LOCK_BASIN"},
    {ECC_LOCK_GATE, "LOCK_GATE"},
    {ECC_LOCOMOTIVE_ENGINE, "LOCOMOTIVE_ENGINE"},
    {ECC_LOG, "LOG"},
    {ECC_LOG_BOOM, "LOG_BOOM"},
    {ECC_LOG_CRIB, "LOG_CRIB"},
    {ECC_LOG_OBSTACLE, "LOG_OBSTACLE"},
    {ECC_LOG_RAMP, "LOG_RAMP"},
    {ECC_LOGGING_SITE, "LOGGING_SITE"},
    {ECC_LOW_CLOUD, "LOW_CLOUD"},
    {ECC_LOW_CLOUD_CEILING_REGION, "LOW_CLOUD_CEILING_REGION"},
    {ECC_LOW_PRESSURE_CENTRE, "LOW_PRESSURE_CENTRE"},
    {ECC_LOW_VISIBILITY_REGION, "LOW_VISIBILITY_REGION"},
    {ECC_LOW_WATER_LINE, "LOW_WATER_LINE"},
    {ECC_MAGNETIC_DATA_DEVICE, "MAGNETIC_DATA_DEVICE"},
    {ECC_MAGNETIC_DISTURBANCE, "MAGNETIC_DISTURBANCE"},
    {ECC_MAGNETIC_FIELD, "MAGNETIC_FIELD"},
    {ECC_MAGNETIC_FIELD_PROPERTY_SET, "MAGNETIC_FIELD_PROPERTY_SET"},
    {ECC_MAGNETIC_FIELD_SURFACE_PROPERTY_SET, "MAGNETIC_FIELD_SURFACE_PROPERTY_SET"},
    {ECC_MAGNETIC_STATION, "MAGNETIC_STATION"},
    {ECC_MAGNETOPAUSE, "MAGNETOPAUSE"},
    {ECC_MAGNETOSPHERE, "MAGNETOSPHERE"},
    {ECC_MAGNETOSPHERE_PLASMA, "MAGNETOSPHERE_PLASMA"},
    {ECC_MAILBOX, "MAILBOX"},
    {ECC_MAIN_TELECOM_EXCHANGE, "MAIN_TELECOM_EXCHANGE"},
    {ECC_MAMMAL, "MAMMAL"},
    {ECC_MAN_MADE_AIR_OBSTRUCTION, "MAN_MADE_AIR_OBSTRUCTION"},
    {ECC_MAN_MADE_CLEARING, "MAN_MADE_CLEARING"},
    {ECC_MAN_MADE_OBJECT, "MAN_MADE_OBJECT"},
    {ECC_MANHOLE, "MANHOLE"},
    {ECC_MANHOLE_COVER, "MANHOLE_COVER"},
    {ECC_MANHOLE_RISER, "MANHOLE_RISER"},
    {ECC_MANUFACTURING_FACILITY, "MANUFACTURING_FACILITY"},
    {ECC_MAP, "MAP"},
    {ECC_MAP_BOUNDARY, "MAP_BOUNDARY"},
    {ECC_MAP_EDGE_FRAME, "MAP_EDGE_FRAME"},
    {ECC_MAP_LEGEND, "MAP_LEGEND"},
    {ECC_MAP_LIMITS, "MAP_LIMITS"},
    {ECC_MARABOUT, "MARABOUT"},
    {ECC_MARINE_AID_TO_NAVIGATION, "MARINE_AID_TO_NAVIGATION"},
    {ECC_MARINE_BAY, "MARINE_BAY"},
    {ECC_MARINE_CHANNEL, "MARINE_CHANNEL"},
    {ECC_MARINE_CLEARING_LINE, "MARINE_CLEARING_LINE"},
    {ECC_MARINE_FOUL_GROUND, "MARINE_FOUL_GROUND"},
    {ECC_MARINE_GATE, "MARINE_GATE"},
    {ECC_MARINE_GRIDIRON, "MARINE_GRIDIRON"},
    {ECC_MARINE_GULF, "MARINE_GULF"},
    {ECC_MARINE_LEADING_LIGHTS_LINE, "MARINE_LEADING_LIGHTS_LINE"},
    {ECC_MARINE_LEADING_LINE, "MARINE_LEADING_LINE"},
    {ECC_MARINE_LIGHT_LINE, "MARINE_LIGHT_LINE"},
    {ECC_MARINE_LIGHT_SECTOR, "MARINE_LIGHT_SECTOR"},
    {ECC_MARINE_LIMIT_BOUNDARY, "MARINE_LIMIT_BOUNDARY"},
    {ECC_MARINE_LOCK, "MARINE_LOCK"},
    {ECC_MARINE_MEASURED_DISTANCE_LINE, "MARINE_MEASURED_DISTANCE_LINE"},
    {ECC_MARINE_MINEFIELD, "MARINE_MINEFIELD"},
    {ECC_MARINE_MOLE, "MARINE_MOLE"},
    {ECC_MARINE_NAVIGATION_MARKER, "MARINE_NAVIGATION_MARKER"},
    {ECC_MARINE_OBJECT, "MARINE_OBJECT"},
    {ECC_MARINE_OBSTRUCTION, "MARINE_OBSTRUCTION"},
    {ECC_MARINE_PETROLEUM_FIELD, "MARINE_PETROLEUM_FIELD"},
    {ECC_MARINE_PLATFORM, "MARINE_PLATFORM"},
    {ECC_MARINE_POLICE_STATION, "MARINE_POLICE_STATION"},
    {ECC_MARINE_PORT, "MARINE_PORT"},
    {ECC_MARINE_RAMP, "MARINE_RAMP"},
    {ECC_MARINE_REGION, "MARINE_REGION"},
    {ECC_MARINE_ROUTE, "MARINE_ROUTE"},
    {ECC_MARINE_ROUTE_NEXUS, "MARINE_ROUTE_NEXUS"},
    {ECC_MARINE_SIGNAL_STATION, "MARINE_SIGNAL_STATION"},
    {ECC_MARINE_SOUND, "MARINE_SOUND"},
    {ECC_MARINE_STRAIT, "MARINE_STRAIT"},
    {ECC_MARINE_WRECK, "MARINE_WRECK"},
    {ECC_MARKER, "MARKER"},
    {ECC_MARKET, "MARKET"},
    {ECC_MARKET_PLACE, "MARKET_PLACE"},
    {ECC_MARS, "MARS"},
    {ECC_MARSH, "MARSH"},
    {ECC_MARTELLO_TOWER, "MARTELLO_TOWER"},
    {ECC_MAST, "MAST"},
    {ECC_MATERIAL, "MATERIAL"},
    {ECC_MATERIAL_PROPERTY_SET, "MATERIAL_PROPERTY_SET"},
    {ECC_MEDICAL_FACILITY, "MEDICAL_FACILITY"},
    {ECC_MEMORIAL_MONUMENT, "MEMORIAL_MONUMENT"},
    {ECC_MERCHANT_MARINE_VESSEL, "MERCHANT_MARINE_VESSEL"},
    {ECC_MERCURY, "MERCURY"},
    {ECC_MESA, "MESA"},
    {ECC_MESH, "MESH"},
    {ECC_MESH_EDGE_PROPERTY_SET, "MESH_EDGE_PROPERTY_SET"},
    {ECC_MESH_EDGE_SET, "MESH_EDGE_SET"},
    {ECC_MESH_FACE_PROPERTY_SET, "MESH_FACE_PROPERTY_SET"},
    {ECC_MESH_FACE_SET, "MESH_FACE_SET"},
    {ECC_MESH_NODE_PROPERTY_SET, "MESH_NODE_PROPERTY_SET"},
    {ECC_MESH_NODE_SET, "MESH_NODE_SET"},
    {ECC_MESH_SOLID_PROPERTY_SET, "MESH_SOLID_PROPERTY_SET"},
    {ECC_MESH_SOLID_SET, "MESH_SOLID_SET"},
    {ECC_METER, "METER"},
    {ECC_MEZZANINE, "MEZZANINE"},
    {ECC_MIDDLE_CLOUD, "MIDDLE_CLOUD"},
    {ECC_MILITARY_FACILITY, "MILITARY_FACILITY"},
    {ECC_MILITARY_INSTALLATION, "MILITARY_INSTALLATION"},
    {ECC_MILITARY_OPERATIONS_BUILDING, "MILITARY_OPERATIONS_BUILDING"},
    {ECC_MILITARY_PERSONNEL, "MILITARY_PERSONNEL"},
    {ECC_MILITARY_TRENCH, "MILITARY_TRENCH"},
    {ECC_MINARET, "MINARET"},
    {ECC_MINE_COUNTERMEASURE_VESSEL, "MINE_COUNTERMEASURE_VESSEL"},
    {ECC_MINEFIELD, "MINEFIELD"},
    {ECC_MINERAL_PILE, "MINERAL_PILE"},
    {ECC_MISSILE, "MISSILE"},
    {ECC_MISSILE_SITE, "MISSILE_SITE"},
    {ECC_MISSION, "MISSION"},
    {ECC_MIXED_URBAN_REGION, "MIXED_URBAN_REGION"},
    {ECC_MIXED_VEGETATION_LAND, "MIXED_VEGETATION_LAND"},
    {ECC_MOAT, "MOAT"},
    {ECC_MOBILE_BRIDGE_SYSTEM, "MOBILE_BRIDGE_SYSTEM"},
    {ECC_MOBILE_HOME, "MOBILE_HOME"},
    {ECC_MOBILE_HOME_PARK, "MOBILE_HOME_PARK"},
    {ECC_MOLLUSC, "MOLLUSC"},
    {ECC_MONASTERY, "MONASTERY"},
    {ECC_MONERAN, "MONERAN"},
    {ECC_MOON, "MOON"},
    {ECC_MOORING_DOLPHIN, "MOORING_DOLPHIN"},
    {ECC_MOORING_FACILITY, "MOORING_FACILITY"},
    {ECC_MOORING_LINE, "MOORING_LINE"},
    {ECC_MOORING_MAST, "MOORING_MAST"},
    {ECC_MOORING_RING, "MOORING_RING"},
    {ECC_MOORING_TROT, "MOORING_TROT"},
    {ECC_MORAINE, "MORAINE"},
    {ECC_MORMON_TEMPLE, "MORMON_TEMPLE"},
    {ECC_MORTAR, "MORTAR"},
    {ECC_MOSQUE, "MOSQUE"},
    {ECC_MOSS, "MOSS"},
    {ECC_MOTEL, "MOTEL"},
    {ECC_MOTOR_VEHICLE, "MOTOR_VEHICLE"},
    {ECC_MOTOR_VEHICLE_STATION, "MOTOR_VEHICLE_STATION"},
    {ECC_MOUNTAIN, "MOUNTAIN"},
    {ECC_MOUNTAIN_PASS, "MOUNTAIN_PASS"},
    {ECC_MOUNTAINOUS_REGION, "MOUNTAINOUS_REGION"},
    {ECC_MUD_LINE, "MUD_LINE"},
    {ECC_MULTI_UNIT_DWELLING, "MULTI_UNIT_DWELLING"},
    {ECC_MULTIDOMAIN_VEHICLE, "MULTIDOMAIN_VEHICLE"},
    {ECC_MUNICIPAL_HALL, "MUNICIPAL_HALL"},
    {ECC_MUNICIPAL_UTILITY_FACILITY, "MUNICIPAL_UTILITY_FACILITY"},
    {ECC_MUNITION, "MUNITION"},
    {ECC_MUSEUM_BUILDING, "MUSEUM_BUILDING"},
    {ECC_MUSEUM_FACILITY, "MUSEUM_FACILITY"},
    {ECC_MUSHROOM, "MUSHROOM"},
    {ECC_NAMED_LAND_TRACT, "NAMED_LAND_TRACT"},
    {ECC_NAMED_MAP_LOCATION, "NAMED_MAP_LOCATION"},
    {ECC_NATIONAL_PARK, "NATIONAL_PARK"},
    {ECC_NATURAL_AIR_OBSTRUCTION, "NATURAL_AIR_OBSTRUCTION"},
    {ECC_NATURAL_GAS_RIG, "NATURAL_GAS_RIG"},
    {ECC_NATURE_RESERVE, "NATURE_RESERVE"},
    {ECC_NAUTICAL_CLUB, "NAUTICAL_CLUB"},
    {ECC_NAVIGABLE_WATERWAY, "NAVIGABLE_WATERWAY"},
    {ECC_NAVIGATION_BUOY, "NAVIGATION_BUOY"},
    {ECC_NAVIGATION_DEVICE, "NAVIGATION_DEVICE"},
    {ECC_NAVIGATION_LIGHT, "NAVIGATION_LIGHT"},
    {ECC_NAVIGATION_LINE, "NAVIGATION_LINE"},
    {ECC_NAVIGATION_MARK_AFLOAT, "NAVIGATION_MARK_AFLOAT"},
    {ECC_NAVIGATION_MARK_FIXED, "NAVIGATION_MARK_FIXED"},
    {ECC_NAVIGATION_RADAR_RANGE, "NAVIGATION_RADAR_RANGE"},
    {ECC_NAVIGATION_RESTRICTED_REGION, "NAVIGATION_RESTRICTED_REGION"},
    {ECC_NEAP_TIDE, "NEAP_TIDE"},
    {ECC_NEARSHORE_PRECISE, "NEARSHORE_PRECISE"},
    {ECC_NEBULA, "NEBULA"},
    {ECC_NEPTUNE, "NEPTUNE"},
    {ECC_NETWORK, "NETWORK"},
    {ECC_NEWSPAPER_PLANT, "NEWSPAPER_PLANT"},
    {ECC_NON_AQUEOUS_CLOUD, "NON_AQUEOUS_CLOUD"},
    {ECC_NON_COMMUNICATION_TOWER, "NON_COMMUNICATION_TOWER"},
    {ECC_NON_EMPTY_SET, "NON_EMPTY_SET"},
    {ECC_NON_HUMAN_ANIMAL, "NON_HUMAN_ANIMAL"},
    {ECC_NON_SUBMARINE_CONTACT, "NON_SUBMARINE_CONTACT"},
    {ECC_NUCLEAR_REACTOR, "NUCLEAR_REACTOR"},
    {ECC_NUCLEAR_WEAPONS_FACILITY, "NUCLEAR_WEAPONS_FACILITY"},
    {ECC_OASIS, "OASIS"},
    {ECC_OBJECT, "OBJECT"},
    {ECC_OBJECT_PROPERTY_SET, "OBJECT_PROPERTY_SET"},
    {ECC_OBJECT_SET, "OBJECT_SET"},
    {ECC_OBSERVATION_STATION, "OBSERVATION_STATION"},
    {ECC_OBSERVATORY, "OBSERVATORY"},
    {ECC_OCCLUDED_FRONT, "OCCLUDED_FRONT"},
    {ECC_OCCUPATION_ZONE, "OCCUPATION_ZONE"},
    {ECC_OCEAN, "OCEAN"},
    {ECC_OCEAN_BASIN, "OCEAN_BASIN"},
    {ECC_OCEAN_FLOOR, "OCEAN_FLOOR"},
    {ECC_OCEAN_FLOOR_TOPOGRAPHIC_CONFIGURATION, "OCEAN_FLOOR_TOPOGRAPHIC_CONFIGURATION"},
    {ECC_OFF_ROUTE_BEARING, "OFF_ROUTE_BEARING"},
    {ECC_OFFSHORE_LOADING_FACILITY, "OFFSHORE_LOADING_FACILITY"},
    {ECC_OFFSHORE_PLATFORM, "OFFSHORE_PLATFORM"},
    {ECC_OIL_BARRIER, "OIL_BARRIER"},
    {ECC_OIL_DRILLING_RIG, "OIL_DRILLING_RIG"},
    {ECC_OPEN_AIR_BATH, "OPEN_AIR_BATH"},
    {ECC_OPEN_WATER, "OPEN_WATER"},
    {ECC_OPERA_HOUSE, "OPERA_HOUSE"},
    {ECC_ORCHARD, "ORCHARD"},
    {ECC_ORE_REFINERY, "ORE_REFINERY"},
    {ECC_ORNAMENT, "ORNAMENT"},
    {ECC_OUTBUILDING, "OUTBUILDING"},
    {ECC_OVERFALL_REGION, "OVERFALL_REGION"},
    {ECC_OVERHEAD_OBSTRUCTION, "OVERHEAD_OBSTRUCTION"},
    {ECC_OVERPASS, "OVERPASS"},
    {ECC_PACK_ICE, "PACK_ICE"},
    {ECC_PAGODA, "PAGODA"},
    {ECC_PALACE, "PALACE"},
    {ECC_PALACE_COMPLEX, "PALACE_COMPLEX"},
    {ECC_PAPER_MILL, "PAPER_MILL"},
    {ECC_PARAPET, "PARAPET"},
    {ECC_PARCEL, "PARCEL"},
    {ECC_PARK, "PARK"},
    {ECC_PARKING_GARAGE, "PARKING_GARAGE"},
    {ECC_PARKING_LANE, "PARKING_LANE"},
    {ECC_PARKING_METER, "PARKING_METER"},
    {ECC_PARTICLE, "PARTICLE"},
    {ECC_PARTICLE_ACCELERATOR, "PARTICLE_ACCELERATOR"},
    {ECC_PATROL_CRAFT, "PATROL_CRAFT"},
    {ECC_PENSTOCK, "PENSTOCK"},
    {ECC_PERMAFROST, "PERMAFROST"},
    {ECC_PERMANENT_SNOWFIELD, "PERMANENT_SNOWFIELD"},
    {ECC_PERSONNEL, "PERSONNEL"},
    {ECC_PETROLEUM, "PETROLEUM"},
    {ECC_PETROLEUM_BUILDING, "PETROLEUM_BUILDING"},
    {ECC_PETROLEUM_FACILITY, "PETROLEUM_FACILITY"},
    {ECC_PETROLEUM_FIELD, "PETROLEUM_FIELD"},
    {ECC_PETROLEUM_REFINERY, "PETROLEUM_REFINERY"},
    {ECC_PETROLEUM_TANK_FARM, "PETROLEUM_TANK_FARM"},
    {ECC_PHOSPHORESCENT_REGION, "PHOSPHORESCENT_REGION"},
    {ECC_PICNIC_TRACT, "PICNIC_TRACT"},
    {ECC_PIER, "PIER"},
    {ECC_PINGO, "PINGO"},
    {ECC_PIPE, "PIPE"},
    {ECC_PIPELINE, "PIPELINE"},
    {ECC_PIPELINE_TERMINUS, "PIPELINE_TERMINUS"},
    {ECC_PIPING_COMPLEX, "PIPING_COMPLEX"},
    {ECC_PLANET, "PLANET"},
    {ECC_PLANETARY_MAGNETIC_POLE, "PLANETARY_MAGNETIC_POLE"},
    {ECC_PLANETARY_POLE, "PLANETARY_POLE"},
    {ECC_PLANETARY_SURFACE, "PLANETARY_SURFACE"},
    {ECC_PLANKTON, "PLANKTON"},
    {ECC_PLANKTON_BLOOM, "PLANKTON_BLOOM"},
    {ECC_PLANT, "PLANT"},
    {ECC_PLANT_NURSERY, "PLANT_NURSERY"},
    {ECC_PLANTATION, "PLANTATION"},
    {ECC_PLANTER, "PLANTER"},
    {ECC_PLATEAU, "PLATEAU"},
    {ECC_PLUME, "PLUME"},
    {ECC_PLUTO, "PLUTO"},
    {ECC_POD, "POD"},
    {ECC_POINT_ABEAM, "POINT_ABEAM"},
    {ECC_POLAR_CAP, "POLAR_CAP"},
    {ECC_POLAR_ICE, "POLAR_ICE"},
    {ECC_POLE, "POLE"},
    {ECC_POLICE_STATION, "POLICE_STATION"},
    {ECC_POLYGONAL_FACE, "POLYGONAL_FACE"},
    {ECC_POLYNYA, "POLYNYA"},
    {ECC_PONTOON, "PONTOON"},
    {ECC_PORPOISE, "PORPOISE"},
    {ECC_POST_OFFICE, "POST_OFFICE"},
    {ECC_POTENTIAL_LANDSLIDE_REGION, "POTENTIAL_LANDSLIDE_REGION"},
    {ECC_POTENTIAL_TEMPERATURE_INVERSION_LAYER, "POTENTIAL_TEMPERATURE_INVERSION_LAYER"},
    {ECC_POWER_GENERATION_BUILDING, "POWER_GENERATION_BUILDING"},
    {ECC_POWER_PLANT, "POWER_PLANT"},
    {ECC_POWER_SUBSTATION, "POWER_SUBSTATION"},
    {ECC_POWER_TRANSMISSION_LINE, "POWER_TRANSMISSION_LINE"},
    {ECC_POWER_TRANSMISSION_LINE_PYLON, "POWER_TRANSMISSION_LINE_PYLON"},
    {ECC_POWER_TRANSMISSION_LINE_TERMINUS, "POWER_TRANSMISSION_LINE_TERMINUS"},
    {ECC_PRECIPITATION, "PRECIPITATION"},
    {ECC_PRECIPITATION_REGION, "PRECIPITATION_REGION"},
    {ECC_PRECOLLEGIATE_CAMPUS, "PRECOLLEGIATE_CAMPUS"},
    {ECC_PREPARED_DEFENSIVE_POSITION_SITE, "PREPARED_DEFENSIVE_POSITION_SITE"},
    {ECC_PREPARED_DEFENSIVE_TRACT, "PREPARED_DEFENSIVE_TRACT"},
    {ECC_PREPARED_WATERCOURSE_CROSSING, "PREPARED_WATERCOURSE_CROSSING"},
    {ECC_PRESSURE_ICE, "PRESSURE_ICE"},
    {ECC_PREVAILING_CURRENT, "PREVAILING_CURRENT"},
    {ECC_PRISON, "PRISON"},
    {ECC_PROCESSING_BUILDING, "PROCESSING_BUILDING"},
    {ECC_PROCESSING_FACILITY, "PROCESSING_FACILITY"},
    {ECC_PROHIBITED_REGION, "PROHIBITED_REGION"},
    {ECC_PROMONTORY, "PROMONTORY"},
    {ECC_PROPERTY_SET, "PROPERTY_SET"},
    {ECC_PROTECTION_SHED, "PROTECTION_SHED"},
    {ECC_PROTIST, "PROTIST"},
    {ECC_PTERIDOPHYTE, "PTERIDOPHYTE"},
    {ECC_PUBLIC_INN, "PUBLIC_INN"},
    {ECC_PUBLIC_SERVICE_STATION, "PUBLIC_SERVICE_STATION"},
    {ECC_PUBLIC_SQUARE, "PUBLIC_SQUARE"},
    {ECC_PUBLIC_TELEPHONE, "PUBLIC_TELEPHONE"},
    {ECC_PUFF, "PUFF"},
    {ECC_PULPIT, "PULPIT"},
    {ECC_PUMP, "PUMP"},
    {ECC_PUMP_OUT_FACILITY, "PUMP_OUT_FACILITY"},
    {ECC_PUMP_ROOM, "PUMP_ROOM"},
    {ECC_PUMPING_STATION, "PUMPING_STATION"},
    {ECC_PYLON, "PYLON"},
    {ECC_QUARRY, "QUARRY"},
    {ECC_RACE_TRACK, "RACE_TRACK"},
    {ECC_RADAR_DEVICE, "RADAR_DEVICE"},
    {ECC_RADAR_LINE, "RADAR_LINE"},
    {ECC_RADAR_MATERIAL_PROPERTY_SET, "RADAR_MATERIAL_PROPERTY_SET"},
    {ECC_RADAR_RECEIVER, "RADAR_RECEIVER"},
    {ECC_RADAR_REFERENCE_LINE, "RADAR_REFERENCE_LINE"},
    {ECC_RADAR_STATION, "RADAR_STATION"},
    {ECC_RADAR_TRANSMITTER, "RADAR_TRANSMITTER"},
    {ECC_RADIOLOGIC_HAZARD_REGION, "RADIOLOGIC_HAZARD_REGION"},
    {ECC_RAIL_HEAD, "RAIL_HEAD"},
    {ECC_RAIL_TRANSFER_POINT, "RAIL_TRANSFER_POINT"},
    {ECC_RAIL_WAGON, "RAIL_WAGON"},
    {ECC_RAILWAY, "RAILWAY"},
    {ECC_RAILWAY_CROSSING_SIGN, "RAILWAY_CROSSING_SIGN"},
    {ECC_RAILWAY_NEXUS, "RAILWAY_NEXUS"},
    {ECC_RAILWAY_SIDETRACK, "RAILWAY_SIDETRACK"},
    {ECC_RAILWAY_SIDING, "RAILWAY_SIDING"},
    {ECC_RAILWAY_SIGNAL_BOX, "RAILWAY_SIGNAL_BOX"},
    {ECC_RAILWAY_SIGNAL_STRUCTURE, "RAILWAY_SIGNAL_STRUCTURE"},
    {ECC_RAILWAY_SIGNALMAN_HOUSE, "RAILWAY_SIGNALMAN_HOUSE"},
    {ECC_RAILWAY_SPUR, "RAILWAY_SPUR"},
    {ECC_RAILWAY_STATION, "RAILWAY_STATION"},
    {ECC_RAILWAY_STORAGE_REPAIR_BUILDING, "RAILWAY_STORAGE_REPAIR_BUILDING"},
    {ECC_RAILWAY_STORAGE_REPAIR_FACILITY, "RAILWAY_STORAGE_REPAIR_FACILITY"},
    {ECC_RAILWAY_SWITCH, "RAILWAY_SWITCH"},
    {ECC_RAILWAY_TABLE, "RAILWAY_TABLE"},
    {ECC_RAILWAY_TRACK, "RAILWAY_TRACK"},
    {ECC_RAILWAY_TURNTABLE, "RAILWAY_TURNTABLE"},
    {ECC_RAILWAY_YARD, "RAILWAY_YARD"},
    {ECC_RAILWAY_YARD_NEXUS, "RAILWAY_YARD_NEXUS"},
    {ECC_RAIN, "RAIN"},
    {ECC_RAIN_REGION, "RAIN_REGION"},
    {ECC_RAMP, "RAMP"},
    {ECC_RAMPART, "RAMPART"},
    {ECC_RANGER_STATION, "RANGER_STATION"},
    {ECC_RAPID, "RAPID"},
    {ECC_RAY_PATH, "RAY_PATH"},
    {ECC_RECONNAISSANCE_HELICOPTER, "RECONNAISSANCE_HELICOPTER"},
    {ECC_RECONNAISSANCE_WINGED_AIRCRAFT, "RECONNAISSANCE_WINGED_AIRCRAFT"},
    {ECC_RECREATIONAL_FACILITY, "RECREATIONAL_FACILITY"},
    {ECC_RECREATIONAL_PIER, "RECREATIONAL_PIER"},
    {ECC_RECYCLING_SITE, "RECYCLING_SITE"},
    {ECC_REEF, "REEF"},
    {ECC_REFORMATORY_BUILDING, "REFORMATORY_BUILDING"},
    {ECC_REFORMATORY_FACILITY, "REFORMATORY_FACILITY"},
    {ECC_REFUELLING_TRACK, "REFUELLING_TRACK"},
    {ECC_REFUGEE_COMPOUND, "REFUGEE_COMPOUND"},
    {ECC_REFUSE_BIN, "REFUSE_BIN"},
    {ECC_REGION, "REGION"},
    {ECC_REGION_PROPERTY_SET, "REGION_PROPERTY_SET"},
    {ECC_REGIONAL_PARK, "REGIONAL_PARK"},
    {ECC_REGULATED_LINE, "REGULATED_LINE"},
    {ECC_RELATED_OBJECT_SET, "RELATED_OBJECT_SET"},
    {ECC_RELATIVE_DISPLACEMENT_LINE, "RELATIVE_DISPLACEMENT_LINE"},
    {ECC_RELIGIOUS_COMMUNITY, "RELIGIOUS_COMMUNITY"},
    {ECC_REPAIR_BUILDING, "REPAIR_BUILDING"},
    {ECC_REPAIR_FACILITY, "REPAIR_FACILITY"},
    {ECC_REPTILE, "REPTILE"},
    {ECC_RESERVE, "RESERVE"},
    {ECC_RESERVOIR, "RESERVOIR"},
    {ECC_RESERVOIR_NEXUS, "RESERVOIR_NEXUS"},
    {ECC_RESIDENTIAL_REGION, "RESIDENTIAL_REGION"},
    {ECC_RESTAURANT, "RESTAURANT"},
    {ECC_RETAIL_FACILITY, "RETAIL_FACILITY"},
    {ECC_REVERBERATION, "REVERBERATION"},
    {ECC_REVETMENT, "REVETMENT"},
    {ECC_RICE_FIELD, "RICE_FIELD"},
    {ECC_RIDGE, "RIDGE"},
    {ECC_RIDGE_LINE, "RIDGE_LINE"},
    {ECC_RIG, "RIG"},
    {ECC_RIME, "RIME"},
    {ECC_RIP_CURRENT, "RIP_CURRENT"},
    {ECC_RIPRAP, "RIPRAP"},
    {ECC_RIVER, "RIVER"},
    {ECC_RIVER_BANK, "RIVER_BANK"},
    {ECC_RIVER_GAUGING_STATION, "RIVER_GAUGING_STATION"},
    {ECC_RIVER_NEXUS, "RIVER_NEXUS"},
    {ECC_RIVER_ROUTE, "RIVER_ROUTE"},
    {ECC_RIVER_VANISHING_POINT, "RIVER_VANISHING_POINT"},
    {ECC_ROAD, "ROAD"},
    {ECC_ROAD_INTERCHANGE, "ROAD_INTERCHANGE"},
    {ECC_ROAD_MARKINGS, "ROAD_MARKINGS"},
    {ECC_ROAD_NEXUS, "ROAD_NEXUS"},
    {ECC_ROAD_ROUTE_MARKER, "ROAD_ROUTE_MARKER"},
    {ECC_ROADSIDE_REST_STOP, "ROADSIDE_REST_STOP"},
    {ECC_ROCK, "ROCK"},
    {ECC_ROCK_DROP, "ROCK_DROP"},
    {ECC_ROCK_SHED, "ROCK_SHED"},
    {ECC_ROCKY_LANDMARK, "ROCKY_LANDMARK"},
    {ECC_ROCKY_OUTCROP, "ROCKY_OUTCROP"},
    {ECC_RODENT, "RODENT"},
    {ECC_ROLLING_BLOCK, "ROLLING_BLOCK"},
    {ECC_ROOF, "ROOF"},
    {ECC_ROOF_ASSEMBLY, "ROOF_ASSEMBLY"},
    {ECC_ROOM, "ROOM"},
    {ECC_ROOM_CEILING, "ROOM_CEILING"},
    {ECC_ROUNDHOUSE, "ROUNDHOUSE"},
    {ECC_ROUTE, "ROUTE"},
    {ECC_ROUTE_COMPONENT, "ROUTE_COMPONENT"},
    {ECC_ROUTE_CONSTRICTION, "ROUTE_CONSTRICTION"},
    {ECC_ROUTE_EXPANSION, "ROUTE_EXPANSION"},
    {ECC_ROUTE_LANE, "ROUTE_LANE"},
    {ECC_ROUTE_SHOULDER, "ROUTE_SHOULDER"},
    {ECC_ROUTE_WIDTH_CHANGE, "ROUTE_WIDTH_CHANGE"},
    {ECC_ROWHOUSE, "ROWHOUSE"},
    {ECC_RUBBLE, "RUBBLE"},
    {ECC_RUINS, "RUINS"},
    {ECC_RUN_OFF, "RUN_OFF"},
    {ECC_RUNWAY, "RUNWAY"},
    {ECC_RUNWAY_APPROACH_OIS, "RUNWAY_APPROACH_OIS"},
    {ECC_RUNWAY_CONICAL_OIS, "RUNWAY_CONICAL_OIS"},
    {ECC_RUNWAY_CONICAL_OUTER_HORIZONTAL_TRANSITIONAL_OIS, "RUNWAY_CONICAL_OUTER_HORIZONTAL_TRANSITIONAL_OIS"},
    {ECC_RUNWAY_DISPLACED_THRESHOLD, "RUNWAY_DISPLACED_THRESHOLD"},
    {ECC_RUNWAY_ENDPOINT, "RUNWAY_ENDPOINT"},
    {ECC_RUNWAY_INNER_HORIZONTAL_OIS, "RUNWAY_INNER_HORIZONTAL_OIS"},
    {ECC_RUNWAY_MARKINGS, "RUNWAY_MARKINGS"},
    {ECC_RUNWAY_NEXUS, "RUNWAY_NEXUS"},
    {ECC_RUNWAY_OUTER_HORIZONTAL_OIS, "RUNWAY_OUTER_HORIZONTAL_OIS"},
    {ECC_RUNWAY_OVERRUN, "RUNWAY_OVERRUN"},
    {ECC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS, "RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS"},
    {ECC_RUNWAY_PRIMARY_OIS, "RUNWAY_PRIMARY_OIS"},
    {ECC_RUNWAY_RADAR_REFLECTOR, "RUNWAY_RADAR_REFLECTOR"},
    {ECC_RUNWAY_STOPWAY, "RUNWAY_STOPWAY"},
    {ECC_RUNWAY_TOUCHDOWN_ZONE, "RUNWAY_TOUCHDOWN_ZONE"},
    {ECC_SABKHA, "SABKHA"},
    {ECC_SAFARI_PARK, "SAFARI_PARK"},
    {ECC_SAFETY_FAIRWAY, "SAFETY_FAIRWAY"},
    {ECC_SAILING_VESSEL, "SAILING_VESSEL"},
    {ECC_SALT_EVAPORATOR, "SALT_EVAPORATOR"},
    {ECC_SALT_PAN, "SALT_PAN"},
    {ECC_SANATORIUM, "SANATORIUM"},
    {ECC_SAND, "SAND"},
    {ECC_SAND_BAR, "SAND_BAR"},
    {ECC_SAND_DUNE, "SAND_DUNE"},
    {ECC_SAND_DUNE_REGION, "SAND_DUNE_REGION"},
    {ECC_SAND_LINE, "SAND_LINE"},
    {ECC_SATELLITE, "SATELLITE"},
    {ECC_SATELLITE_GROUND_STATION, "SATELLITE_GROUND_STATION"},
    {ECC_SATURN, "SATURN"},
    {ECC_SAWMILL, "SAWMILL"},
    {ECC_SCENIC_LOOKOUT, "SCENIC_LOOKOUT"},
    {ECC_SCHOOL_BUILDING, "SCHOOL_BUILDING"},
    {ECC_SCIENCE_BUILDING, "SCIENCE_BUILDING"},
    {ECC_SCIENCE_FACILITY, "SCIENCE_FACILITY"},
    {ECC_SCRAPYARD, "SCRAPYARD"},
    {ECC_SCRUB_LAND, "SCRUB_LAND"},
    {ECC_SEA, "SEA"},
    {ECC_SEAL_POD, "SEAL_POD"},
    {ECC_SEAMOUNT, "SEAMOUNT"},
    {ECC_SEAPLANE, "SEAPLANE"},
    {ECC_SEAPLANE_BASE, "SEAPLANE_BASE"},
    {ECC_SEAPLANE_RUN, "SEAPLANE_RUN"},
    {ECC_SEAWALL, "SEAWALL"},
    {ECC_SEAWEED, "SEAWEED"},
    {ECC_SECCHI_DISK, "SECCHI_DISK"},
    {ECC_SEDIMENT, "SEDIMENT"},
    {ECC_SELF_PROPELLED_ARTILLERY, "SELF_PROPELLED_ARTILLERY"},
    {ECC_SEMINARY, "SEMINARY"},
    {ECC_SENIOR_CITIZENS_HOME, "SENIOR_CITIZENS_HOME"},
    {ECC_SENSOR, "SENSOR"},
    {ECC_SET, "SET"},
    {ECC_SETTLEMENT, "SETTLEMENT"},
    {ECC_SETTLING_POND, "SETTLING_POND"},
    {ECC_SEWER, "SEWER"},
    {ECC_SEWER_LINE, "SEWER_LINE"},
    {ECC_SHADOW, "SHADOW"},
    {ECC_SHANTY_TOWN, "SHANTY_TOWN"},
    {ECC_SHARP_CURVE, "SHARP_CURVE"},
    {ECC_SHEAR_WALL, "SHEAR_WALL"},
    {ECC_SHED, "SHED"},
    {ECC_SHEERLEGS, "SHEERLEGS"},
    {ECC_SHELLFISH_BED, "SHELLFISH_BED"},
    {ECC_SHELTER, "SHELTER"},
    {ECC_SHIPYARD, "SHIPYARD"},
    {ECC_SHOAL, "SHOAL"},
    {ECC_SHOPPING_CENTRE, "SHOPPING_CENTRE"},
    {ECC_SHORE, "SHORE"},
    {ECC_SHORE_PROTECTION_STRUCTURE, "SHORE_PROTECTION_STRUCTURE"},
    {ECC_SHORE_REVETMENT, "SHORE_REVETMENT"},
    {ECC_SHORELINE, "SHORELINE"},
    {ECC_SHORELINE_CONSTRUCTION, "SHORELINE_CONSTRUCTION"},
    {ECC_SHORELINE_LANDING_PLACE, "SHORELINE_LANDING_PLACE"},
    {ECC_SHORELINE_LANDING_STAIR, "SHORELINE_LANDING_STAIR"},
    {ECC_SHOVEL, "SHOVEL"},
    {ECC_SHRIMP_BED, "SHRIMP_BED"},
    {ECC_SHRINE, "SHRINE"},
    {ECC_SHRUB, "SHRUB"},
    {ECC_SIDEWALK, "SIDEWALK"},
    {ECC_SIPHON, "SIPHON"},
    {ECC_SITE, "SITE"},
    {ECC_SKI_JUMP, "SKI_JUMP"},
    {ECC_SKI_TRACK, "SKI_TRACK"},
    {ECC_SKYLIGHT, "SKYLIGHT"},
    {ECC_SLIPWAY, "SLIPWAY"},
    {ECC_SLOPE_REGION, "SLOPE_REGION"},
    {ECC_SLUDGE_GATE, "SLUDGE_GATE"},
    {ECC_SLUICE, "SLUICE"},
    {ECC_SLUICE_GATE, "SLUICE_GATE"},
    {ECC_SMALL_CRAFT_FACILITY, "SMALL_CRAFT_FACILITY"},
    {ECC_SMALL_HAIL, "SMALL_HAIL"},
    {ECC_SMOKE, "SMOKE"},
    {ECC_SMOKESTACK, "SMOKESTACK"},
    {ECC_SNAG, "SNAG"},
    {ECC_SNOW_GRAINS, "SNOW_GRAINS"},
    {ECC_SNOW_GROUND_COVER, "SNOW_GROUND_COVER"},
    {ECC_SNOW_PRECIPITATION, "SNOW_PRECIPITATION"},
    {ECC_SNOW_REGION, "SNOW_REGION"},
    {ECC_SNOW_SHED, "SNOW_SHED"},
    {ECC_SNOWFIELD, "SNOWFIELD"},
    {ECC_SODA_EVAPORATOR, "SODA_EVAPORATOR"},
    {ECC_SOIL, "SOIL"},
    {ECC_SOLAR_PANEL, "SOLAR_PANEL"},
    {ECC_SOLAR_SYSTEM, "SOLAR_SYSTEM"},
    {ECC_SOLID_MESH, "SOLID_MESH"},
    {ECC_SOLID_PRECIPITATION, "SOLID_PRECIPITATION"},
    {ECC_SOUND_CHANNEL, "SOUND_CHANNEL"},
    {ECC_SOUND_CHANNEL_AXIS, "SOUND_CHANNEL_AXIS"},
    {ECC_SOUNDING, "SOUNDING"},
    {ECC_SOUNDING_DATUM, "SOUNDING_DATUM"},
    {ECC_SPACE, "SPACE"},
    {ECC_SPACECRAFT, "SPACECRAFT"},
    {ECC_SPACEPORT, "SPACEPORT"},
    {ECC_SPECIAL_ELECTRONIC_WINGED_AIRCRAFT, "SPECIAL_ELECTRONIC_WINGED_AIRCRAFT"},
    {ECC_SPECIAL_OPERATIONS_HELICOPTER, "SPECIAL_OPERATIONS_HELICOPTER"},
    {ECC_SPECIAL_USE_AIRSPACE, "SPECIAL_USE_AIRSPACE"},
    {ECC_SPECIAL_USE_AIRSPACE_COMPONENT, "SPECIAL_USE_AIRSPACE_COMPONENT"},
    {ECC_SPEED_HUMP, "SPEED_HUMP"},
    {ECC_SPILLWAY, "SPILLWAY"},
    {ECC_SPORTS_ARENA, "SPORTS_ARENA"},
    {ECC_SPOT_ELEVATION, "SPOT_ELEVATION"},
    {ECC_SPRING, "SPRING"},
    {ECC_SPRING_TIDE, "SPRING_TIDE"},
    {ECC_STADIUM, "STADIUM"},
    {ECC_STAIR, "STAIR"},
    {ECC_STAIR_SET, "STAIR_SET"},
    {ECC_STAKE, "STAKE"},
    {ECC_STAR, "STAR"},
    {ECC_STATIONARY_FRONT, "STATIONARY_FRONT"},
    {ECC_STEEL_MILL, "STEEL_MILL"},
    {ECC_STEEP_GRADE, "STEEP_GRADE"},
    {ECC_STEEPLE, "STEEPLE"},
    {ECC_STELLAR_BURST_RADIO_FREQUENCY_EMISSION, "STELLAR_BURST_RADIO_FREQUENCY_EMISSION"},
    {ECC_STELLAR_ENERGETIC_PARTICLE, "STELLAR_ENERGETIC_PARTICLE"},
    {ECC_STELLAR_FLUX_RADIO_FREQUENCY_EMISSION, "STELLAR_FLUX_RADIO_FREQUENCY_EMISSION"},
    {ECC_STELLAR_WIND, "STELLAR_WIND"},
    {ECC_STONE, "STONE"},
    {ECC_STORAGE_BUNKER, "STORAGE_BUNKER"},
    {ECC_STORAGE_CONTAINER, "STORAGE_CONTAINER"},
    {ECC_STORAGE_DEPOT, "STORAGE_DEPOT"},
    {ECC_STORAGE_PIT, "STORAGE_PIT"},
    {ECC_STORAGE_STRUCTURE, "STORAGE_STRUCTURE"},
    {ECC_STORAGE_TANK, "STORAGE_TANK"},
    {ECC_STORM_DRAIN, "STORM_DRAIN"},
    {ECC_STRATOPAUSE, "STRATOPAUSE"},
    {ECC_STRATOSPHERE, "STRATOSPHERE"},
    {ECC_STREET, "STREET"},
    {ECC_STREET_LAMP, "STREET_LAMP"},
    {ECC_STREET_LAMP_POLE, "STREET_LAMP_POLE"},
    {ECC_STRUCTURAL_BEAM, "STRUCTURAL_BEAM"},
    {ECC_STRUCTURAL_COLUMN, "STRUCTURAL_COLUMN"},
    {ECC_STRUCTURAL_MEMBER, "STRUCTURAL_MEMBER"},
    {ECC_STRUCTURAL_PILE, "STRUCTURAL_PILE"},
    {ECC_STRUCTURE, "STRUCTURE"},
    {ECC_STRUCTURE_ENTRANCE, "STRUCTURE_ENTRANCE"},
    {ECC_STRUCTURE_ENTRANCE_AND_OR_EXIT, "STRUCTURE_ENTRANCE_AND_OR_EXIT"},
    {ECC_STRUCTURE_EXIT, "STRUCTURE_EXIT"},
    {ECC_STRUCTURE_EXTERIOR, "STRUCTURE_EXTERIOR"},
    {ECC_STRUCTURE_PERIMETER, "STRUCTURE_PERIMETER"},
    {ECC_STUPA, "STUPA"},
    {ECC_SUBMERGED_ROCK_FORMATION, "SUBMERGED_ROCK_FORMATION"},
    {ECC_SUBMERSIBLE_VESSEL, "SUBMERSIBLE_VESSEL"},
    {ECC_SUGAR_CANE, "SUGAR_CANE"},
    {ECC_SUN, "SUN"},
    {ECC_SUNSPOT, "SUNSPOT"},
    {ECC_SUPERSTRUCTURE, "SUPERSTRUCTURE"},
    {ECC_SUPPLIES_AND_EXPENDABLES, "SUPPLIES_AND_EXPENDABLES"},
    {ECC_SURF, "SURF"},
    {ECC_SURF_ZONE, "SURF_ZONE"},
    {ECC_SURFACE, "SURFACE"},
    {ECC_SURFACE_BASED_EM_DUCT, "SURFACE_BASED_EM_DUCT"},
    {ECC_SURFACE_DATUM, "SURFACE_DATUM"},
    {ECC_SURFACE_FISSURE, "SURFACE_FISSURE"},
    {ECC_SURVEILLANCE_WINGED_AIRCRAFT, "SURVEILLANCE_WINGED_AIRCRAFT"},
    {ECC_SURVEY_MARKER, "SURVEY_MARKER"},
    {ECC_SWAMP, "SWAMP"},
    {ECC_SWELL_WAVE, "SWELL_WAVE"},
    {ECC_SWEPT_REGION, "SWEPT_REGION"},
    {ECC_SWIMMING_POOL, "SWIMMING_POOL"},
    {ECC_SYNAGOGUE, "SYNAGOGUE"},
    {ECC_SYSTEM, "SYSTEM"},
    {ECC_SYSTEMATIC_TREE_PLANTING, "SYSTEMATIC_TREE_PLANTING"},
    {ECC_TABERNACLE, "TABERNACLE"},
    {ECC_TABLE, "TABLE"},
    {ECC_TAXIWAY, "TAXIWAY"},
    {ECC_TELECOM_SWITCHING_STATION, "TELECOM_SWITCHING_STATION"},
    {ECC_TELEFERIC, "TELEFERIC"},
    {ECC_TELEPHONE, "TELEPHONE"},
    {ECC_TELESCOPE, "TELESCOPE"},
    {ECC_TEMPERATURE_INVERSION_LAYER, "TEMPERATURE_INVERSION_LAYER"},
    {ECC_TEMPORARY_ENCAMPMENT, "TEMPORARY_ENCAMPMENT"},
    {ECC_TENDER, "TENDER"},
    {ECC_TENNIS_COMPLEX, "TENNIS_COMPLEX"},
    {ECC_TENNIS_COURT, "TENNIS_COURT"},
    {ECC_TENT, "TENT"},
    {ECC_TENT_DWELLING, "TENT_DWELLING"},
    {ECC_TERRAIN, "TERRAIN"},
    {ECC_TERRAIN_CHANNEL, "TERRAIN_CHANNEL"},
    {ECC_TERRAIN_CRATER, "TERRAIN_CRATER"},
    {ECC_TERRAIN_CUT, "TERRAIN_CUT"},
    {ECC_TERRAIN_DEPRESSION, "TERRAIN_DEPRESSION"},
    {ECC_TERRAIN_ELEVATION_PROPERTY_SET, "TERRAIN_ELEVATION_PROPERTY_SET"},
    {ECC_TERRAIN_FILL, "TERRAIN_FILL"},
    {ECC_TERRAIN_OBSTACLE, "TERRAIN_OBSTACLE"},
    {ECC_TERRAIN_PIT, "TERRAIN_PIT"},
    {ECC_TERRAIN_PLAIN, "TERRAIN_PLAIN"},
    {ECC_TERRAIN_STRIP, "TERRAIN_STRIP"},
    {ECC_TERRAIN_SURFACE_OBJECT, "TERRAIN_SURFACE_OBJECT"},
    {ECC_TERRAIN_SURFACE_REGION, "TERRAIN_SURFACE_REGION"},
    {ECC_TERRAIN_TRANSPORTATION_ABATIS, "TERRAIN_TRANSPORTATION_ABATIS"},
    {ECC_TERRAIN_TRANSPORTATION_GALLERY, "TERRAIN_TRANSPORTATION_GALLERY"},
    {ECC_TEST_REFERENCE_TRACK, "TEST_REFERENCE_TRACK"},
    {ECC_TEST_SITE, "TEST_SITE"},
    {ECC_THEATRE, "THEATRE"},
    {ECC_THEODOLITE_LINE, "THEODOLITE_LINE"},
    {ECC_THERMAL_MATERIAL_PROPERTY_SET, "THERMAL_MATERIAL_PROPERTY_SET"},
    {ECC_THUNDERSTORM, "THUNDERSTORM"},
    {ECC_TIDAL_BASIN, "TIDAL_BASIN"},
    {ECC_TIDAL_WATER, "TIDAL_WATER"},
    {ECC_TIDE, "TIDE"},
    {ECC_TIDE_DATA_POINT, "TIDE_DATA_POINT"},
    {ECC_TIDE_GAUGE, "TIDE_GAUGE"},
    {ECC_TIDE_LOCK, "TIDE_LOCK"},
    {ECC_TIDE_RIP_REGION, "TIDE_RIP_REGION"},
    {ECC_TIDEWAY, "TIDEWAY"},
    {ECC_TIMBER_YARD, "TIMBER_YARD"},
    {ECC_TIME_ANALYSIS_BASE_SET, "TIME_ANALYSIS_BASE_SET"},
    {ECC_TIME_FORECAST_TAU_SET, "TIME_FORECAST_TAU_SET"},
    {ECC_TOPMARK, "TOPMARK"},
    {ECC_TOWED_ARTILLERY, "TOWED_ARTILLERY"},
    {ECC_TOWED_VEHICLE, "TOWED_VEHICLE"},
    {ECC_TOWER, "TOWER"},
    {ECC_TOWN, "TOWN"},
    {ECC_TOWN_HALL, "TOWN_HALL"},
    {ECC_TRACK_LINE, "TRACK_LINE"},
    {ECC_TRACK_SWATH, "TRACK_SWATH"},
    {ECC_TRACT, "TRACT"},
    {ECC_TRADING_POST, "TRADING_POST"},
    {ECC_TRADITIONAL_SETTLEMENT, "TRADITIONAL_SETTLEMENT"},
    {ECC_TRAFFIC_CONTROL_DEVICE, "TRAFFIC_CONTROL_DEVICE"},
    {ECC_TRAFFIC_LIGHT, "TRAFFIC_LIGHT"},
    {ECC_TRAFFIC_LIGHT_POLE, "TRAFFIC_LIGHT_POLE"},
    {ECC_TRAFFIC_SEPARATION_SCHEME, "TRAFFIC_SEPARATION_SCHEME"},
    {ECC_TRAIL, "TRAIL"},
    {ECC_TRAIN, "TRAIN"},
    {ECC_TRAINER_WINGED_AIRCRAFT, "TRAINER_WINGED_AIRCRAFT"},
    {ECC_TRAINING_BUILDING, "TRAINING_BUILDING"},
    {ECC_TRAINING_FACILITY, "TRAINING_FACILITY"},
    {ECC_TRANSMISSION_STATION, "TRANSMISSION_STATION"},
    {ECC_TRANSPORT_HELICOPTER, "TRANSPORT_HELICOPTER"},
    {ECC_TRANSPORT_WINGED_AIRCRAFT, "TRANSPORT_WINGED_AIRCRAFT"},
    {ECC_TRANSPORTATION_BLOCK, "TRANSPORTATION_BLOCK"},
    {ECC_TRANSPORTATION_BUILDING, "TRANSPORTATION_BUILDING"},
    {ECC_TRANSPORTATION_FACILITY, "TRANSPORTATION_FACILITY"},
    {ECC_TRANSPORTATION_ROUTE, "TRANSPORTATION_ROUTE"},
    {ECC_TRANSPORTATION_STATION, "TRANSPORTATION_STATION"},
    {ECC_TRAPDOOR, "TRAPDOOR"},
    {ECC_TREE, "TREE"},
    {ECC_TREE_BLOWDOWN, "TREE_BLOWDOWN"},
    {ECC_TREE_LINE, "TREE_LINE"},
    {ECC_TREED_TRACT, "TREED_TRACT"},
    {ECC_TRENCH, "TRENCH"},
    {ECC_TROPICAL_CYCLONE, "TROPICAL_CYCLONE"},
    {ECC_TROPOPAUSE, "TROPOPAUSE"},
    {ECC_TROPOSPHERE, "TROPOSPHERE"},
    {ECC_TRUCK, "TRUCK"},
    {ECC_TSS_SYSTEM, "TSS_SYSTEM"},
    {ECC_TSUNAMI, "TSUNAMI"},
    {ECC_TUNA_NETTING_REGION, "TUNA_NETTING_REGION"},
    {ECC_TUNDRA, "TUNDRA"},
    {ECC_TUNNEL, "TUNNEL"},
    {ECC_TUNNEL_SHELTER, "TUNNEL_SHELTER"},
    {ECC_TURBID_REGION, "TURBID_REGION"},
    {ECC_TURNING_BASIN, "TURNING_BASIN"},
    {ECC_TYPHOON, "TYPHOON"},
    {ECC_UNCONTROLLED_AIRSPACE, "UNCONTROLLED_AIRSPACE"},
    {ECC_UNDERGROUND_BUNKER, "UNDERGROUND_BUNKER"},
    {ECC_UNDERGROUND_DWELLING, "UNDERGROUND_DWELLING"},
    {ECC_UNDERGROUND_RAILWAY, "UNDERGROUND_RAILWAY"},
    {ECC_UNDERGROUND_STRUCTURE, "UNDERGROUND_STRUCTURE"},
    {ECC_UNDERGROUND_WATER, "UNDERGROUND_WATER"},
    {ECC_UNDERMINED_LAND, "UNDERMINED_LAND"},
    {ECC_UNDERWATER_COMMUNICATION_DEVICE, "UNDERWATER_COMMUNICATION_DEVICE"},
    {ECC_UNDERWATER_HAZARD, "UNDERWATER_HAZARD"},
    {ECC_UNDERWATER_OBJECT, "UNDERWATER_OBJECT"},
    {ECC_UNDERWATER_REGION, "UNDERWATER_REGION"},
    {ECC_UNMANNED_WINGED_AIRCRAFT, "UNMANNED_WINGED_AIRCRAFT"},
    {ECC_UNMONUMENTED_POINT, "UNMONUMENTED_POINT"},
    {ECC_UNVEGETATED_LAND, "UNVEGETATED_LAND"},
    {ECC_URANUS, "URANUS"},
    {ECC_UTILITY_HELICOPTER, "UTILITY_HELICOPTER"},
    {ECC_UTILITY_VESSEL, "UTILITY_VESSEL"},
    {ECC_UTILITY_WINGED_AIRCRAFT, "UTILITY_WINGED_AIRCRAFT"},
    {ECC_VALLEY_BOTTOM_LINE, "VALLEY_BOTTOM_LINE"},
    {ECC_VALLEY_REGION, "VALLEY_REGION"},
    {ECC_VALVE, "VALVE"},
    {ECC_VARIABLE_DISPLACEMENT_LINE, "VARIABLE_DISPLACEMENT_LINE"},
    {ECC_VEGETABLE_OIL_MILL, "VEGETABLE_OIL_MILL"},
    {ECC_VEGETATED_SATURATED_LAND, "VEGETATED_SATURATED_LAND"},
    {ECC_VEGETATION, "VEGETATION"},
    {ECC_VEHICLE, "VEHICLE"},
    {ECC_VEHICLE_BARRIER, "VEHICLE_BARRIER"},
    {ECC_VEHICLE_LOT, "VEHICLE_LOT"},
    {ECC_VEHICLE_SCALE, "VEHICLE_SCALE"},
    {ECC_VENTILATION_APERTURE, "VENTILATION_APERTURE"},
    {ECC_VENTILATION_DUCT, "VENTILATION_DUCT"},
    {ECC_VENTILATION_DUCT_WALL, "VENTILATION_DUCT_WALL"},
    {ECC_VENTILATION_SHAFT, "VENTILATION_SHAFT"},
    {ECC_VENUS, "VENUS"},
    {ECC_VERTEBRATE, "VERTEBRATE"},
    {ECC_VERTICAL_DATUM, "VERTICAL_DATUM"},
    {ECC_VESSEL, "VESSEL"},
    {ECC_VESSEL_BASIN, "VESSEL_BASIN"},
    {ECC_VESSEL_BERTH, "VESSEL_BERTH"},
    {ECC_VESSEL_STORAGE_ANCHORAGE, "VESSEL_STORAGE_ANCHORAGE"},
    {ECC_VIADUCT, "VIADUCT"},
    {ECC_VINEYARD, "VINEYARD"},
    {ECC_VOID_COLLECTION, "VOID_COLLECTION"},
    {ECC_VOLCANIC_DYKE, "VOLCANIC_DYKE"},
    {ECC_VOLCANO, "VOLCANO"},
    {ECC_WADI, "WADI"},
    {ECC_WADI_NEXUS, "WADI_NEXUS"},
    {ECC_WALL, "WALL"},
    {ECC_WALL_LOOPHOLE, "WALL_LOOPHOLE"},
    {ECC_WALL_STUD, "WALL_STUD"},
    {ECC_WAREHOUSE, "WAREHOUSE"},
    {ECC_WARM_FRONT, "WARM_FRONT"},
    {ECC_WASTE_PROCESSING_FACILITY, "WASTE_PROCESSING_FACILITY"},
    {ECC_WATER, "WATER"},
    {ECC_WATER_CHANNEL, "WATER_CHANNEL"},
    {ECC_WATER_CHANNEL_EDGE, "WATER_CHANNEL_EDGE"},
    {ECC_WATER_CURRENT, "WATER_CURRENT"},
    {ECC_WATER_CURRENT_PROPERTY_SET, "WATER_CURRENT_PROPERTY_SET"},
    {ECC_WATER_DATA_COLLECTION_DEVICE, "WATER_DATA_COLLECTION_DEVICE"},
    {ECC_WATER_DRIVEN_GRISTMILL, "WATER_DRIVEN_GRISTMILL"},
    {ECC_WATER_GATHERING_REGION, "WATER_GATHERING_REGION"},
    {ECC_WATER_INTAKE, "WATER_INTAKE"},
    {ECC_WATER_INTAKE_TOWER, "WATER_INTAKE_TOWER"},
    {ECC_WATER_MAIN, "WATER_MAIN"},
    {ECC_WATER_SURFACE_VESSEL, "WATER_SURFACE_VESSEL"},
    {ECC_WATER_TOWER, "WATER_TOWER"},
    {ECC_WATER_TREATMENT_BED, "WATER_TREATMENT_BED"},
    {ECC_WATER_TREATMENT_FACILITY, "WATER_TREATMENT_FACILITY"},
    {ECC_WATER_TREATMENT_STRUCTURE, "WATER_TREATMENT_STRUCTURE"},
    {ECC_WATER_TURBULENCE, "WATER_TURBULENCE"},
    {ECC_WATER_WAVE, "WATER_WAVE"},
    {ECC_WATERBODY, "WATERBODY"},
    {ECC_WATERBODY_ACOUSTIC_PROPERTY_SET, "WATERBODY_ACOUSTIC_PROPERTY_SET"},
    {ECC_WATERBODY_ACOUSTIC_SIGNATURE_PROPERTY_SET, "WATERBODY_ACOUSTIC_SIGNATURE_PROPERTY_SET"},
    {ECC_WATERBODY_ACOUSTIC_TARGET_STRENGTH_PROPERTY_SET, "WATERBODY_ACOUSTIC_TARGET_STRENGTH_PROPERTY_SET"},
    {ECC_WATERBODY_BANK, "WATERBODY_BANK"},
    {ECC_WATERBODY_BASIN, "WATERBODY_BASIN"},
    {ECC_WATERBODY_BATHYMETRY_PROPERTY_SET, "WATERBODY_BATHYMETRY_PROPERTY_SET"},
    {ECC_WATERBODY_BIOLOGIC_SOUND_SOURCE, "WATERBODY_BIOLOGIC_SOUND_SOURCE"},
    {ECC_WATERBODY_BOOM, "WATERBODY_BOOM"},
    {ECC_WATERBODY_CURRENT, "WATERBODY_CURRENT"},
    {ECC_WATERBODY_EDDY, "WATERBODY_EDDY"},
    {ECC_WATERBODY_FLOOR, "WATERBODY_FLOOR"},
    {ECC_WATERBODY_FLOOR_CANYON, "WATERBODY_FLOOR_CANYON"},
    {ECC_WATERBODY_FLOOR_PINNACLE, "WATERBODY_FLOOR_PINNACLE"},
    {ECC_WATERBODY_FLOOR_PROVINCE, "WATERBODY_FLOOR_PROVINCE"},
    {ECC_WATERBODY_FLOOR_REGION, "WATERBODY_FLOOR_REGION"},
    {ECC_WATERBODY_FLOOR_RIDGE, "WATERBODY_FLOOR_RIDGE"},
    {ECC_WATERBODY_FLOOR_SONAR_RETURN, "WATERBODY_FLOOR_SONAR_RETURN"},
    {ECC_WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION, "WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION"},
    {ECC_WATERBODY_FLOOR_TRENCH, "WATERBODY_FLOOR_TRENCH"},
    {ECC_WATERBODY_PARTITION, "WATERBODY_PARTITION"},
    {ECC_WATERBODY_PROPERTY_SET, "WATERBODY_PROPERTY_SET"},
    {ECC_WATERBODY_REGION, "WATERBODY_REGION"},
    {ECC_WATERBODY_SHELTER_BASIN, "WATERBODY_SHELTER_BASIN"},
    {ECC_WATERBODY_SHIPPING_PROPERTY_SET, "WATERBODY_SHIPPING_PROPERTY_SET"},
    {ECC_WATERBODY_SURFACE, "WATERBODY_SURFACE"},
    {ECC_WATERBODY_SURFACE_REGION, "WATERBODY_SURFACE_REGION"},
    {ECC_WATERBODY_SURFACE_SLICK, "WATERBODY_SURFACE_SLICK"},
    {ECC_WATERBODY_TEMPERATURE_PROPERTY_SET, "WATERBODY_TEMPERATURE_PROPERTY_SET"},
    {ECC_WATERCOURSE, "WATERCOURSE"},
    {ECC_WATERFALL, "WATERFALL"},
    {ECC_WATERING_HOLE, "WATERING_HOLE"},
    {ECC_WATERING_PLACE, "WATERING_PLACE"},
    {ECC_WAYPOINT, "WAYPOINT"},
    {ECC_WEAPON, "WEAPON"},
    {ECC_WEAPON_FIGHTING_POS_ACCESS_ROUTE, "WEAPON_FIGHTING_POS_ACCESS_ROUTE"},
    {ECC_WEAPON_FIGHTING_POSITION, "WEAPON_FIGHTING_POSITION"},
    {ECC_WEAPON_FULL_DEFILADE_POSITION, "WEAPON_FULL_DEFILADE_POSITION"},
    {ECC_WEAPON_HULL_DEFILADE_POSITION, "WEAPON_HULL_DEFILADE_POSITION"},
    {ECC_WEAPON_SYSTEM, "WEAPON_SYSTEM"},
    {ECC_WEAPON_TURRET_DEFILADE_POSITION, "WEAPON_TURRET_DEFILADE_POSITION"},
    {ECC_WEAPONS_RANGE, "WEAPONS_RANGE"},
    {ECC_WEATHER_STATION, "WEATHER_STATION"},
    {ECC_WELL, "WELL"},
    {ECC_WELL_HEAD, "WELL_HEAD"},
    {ECC_WET_DOCK, "WET_DOCK"},
    {ECC_WETLAND, "WETLAND"},
    {ECC_WHALE, "WHALE"},
    {ECC_WHALE_POD, "WHALE_POD"},
    {ECC_WHARF, "WHARF"},
    {ECC_WIND, "WIND"},
    {ECC_WIND_INDICATOR, "WIND_INDICATOR"},
    {ECC_WIND_MOTOR, "WIND_MOTOR"},
    {ECC_WIND_ROSE_PROPERTY_SET, "WIND_ROSE_PROPERTY_SET"},
    {ECC_WIND_TUNNEL, "WIND_TUNNEL"},
    {ECC_WIND_VANE, "WIND_VANE"},
    {ECC_WIND_WAVE, "WIND_WAVE"},
    {ECC_WINDMILL, "WINDMILL"},
    {ECC_WINDOW, "WINDOW"},
    {ECC_WIRE, "WIRE"},
    {ECC_WIRE_OBSTACLE, "WIRE_OBSTACLE"},
    {ECC_WOODY_GRASS_LAND, "WOODY_GRASS_LAND"},
    {ECC_WORSHIP_PLACE, "WORSHIP_PLACE"},
    {ECC_WRECKING_YARD, "WRECKING_YARD"},
    {ECC_ZEBRA, "ZEBRA"},
    {ECC_ZOO, "ZOO"}
}; /* EDCS_Classification_Labels */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareECLabel
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareECLabel
(
    const EDCS_Classification_Label_Entry *a_ptr,
    const EDCS_Classification_Label_Entry *b_ptr
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
} /* end local_CompareECLabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetECDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetECDictionaryEntry
(
          EDCS_Classification_Code               ec_code_in,
    const EDCS_Classification_Dictionary_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidClassificationCode(ec_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *result_out_ptr = &(EDCS_Classification_Dictionary[ec_code_in-1]);
    }
    return status;
} /* end EDCS_GetECDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToECCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_LabelToECCode
(
    const EDCS_Character            *label_in_ptr,
          EDCS_Classification_Code  *result_out_ptr
)
{
    EDCS_Status_Code                 status = EDCS_SC_SUCCESS;
    EDCS_Classification_Label_Entry *search_result_ptr = NULL, target;

    if (!label_in_ptr || !result_out_ptr)
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    else
    {
       *result_out_ptr    = (EDCS_Classification_Code)0;
        target.label   = label_in_ptr;
        search_result_ptr = (EDCS_Classification_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_Classification_Labels,
                               EDCS_TOTAL_EC,
                               sizeof(EDCS_Classification_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_CompareECLabel
                            );
        if (search_result_ptr)
            *result_out_ptr = search_result_ptr->code;
        else
            status = EDCS_SC_INVALID_INPUT_LABEL;
    }
    return status;
} /* end EDCS_LabelToECCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintClassificationCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintClassificationCode
(
    EDCS_Classification_Code ec_code_in
)
{
    static char buffer[256];

    if (!EDCS_ValidClassificationCode(ec_code_in))
    {
        sprintf(buffer, "ERROR - ILLEGAL EDCS_Classification_Code VALUE (%i)",
               (int) ec_code_in);
        return buffer;
    }
    else
    {
        return EDCS_Classification_Dictionary[ec_code_in-1].symbolic_constant;
    }
} /* end EDCS_PrintClassificationCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToECCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SymbolicConstantToECCode
(
    const EDCS_Character           *symbolic_in_ptr,
          EDCS_Classification_Code *result_out_ptr
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
        /* Symbolic Constants should always be of the form ECC_<EC_Label>, so
         * we strip off the ECC_ and use the EDCS_LabelToECCode function
         */
        if ( strstr( symbolic_in_ptr, "ECC_" ) == symbolic_in_ptr )
        {
            label = strchr( symbolic_in_ptr, '_' );

            if (label != NULL)
            {
                label++;
                status = EDCS_LabelToECCode( label, result_out_ptr );

                /* Hand back the correct error code if the label couldn't be found */
                if (status == EDCS_SC_INVALID_INPUT_LABEL)
                {
                    status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
                }
            }
        }
    }
    return status;
} /* end EDCS_SymbolicConstantToECCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidClassificationCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidClassificationCode
(
    EDCS_Classification_Code ec_code_in
)
{
    if ((ec_code_in < 1) || (ec_code_in > EDCS_TOTAL_EC))
    {
        return EDCS_FALSE;
    }
    else if (EDCS_Classification_Dictionary[ec_code_in-1].code != ec_code_in)
    {
        return EDCS_FALSE;
    }
    else
    {
        return EDCS_TRUE;
    }
} /* end EDCS_ValidClassificationCode */
