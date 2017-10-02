/*
 * FILE       : edcs_attr_dict.c
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

#include "edcs_attr_dict.h"
#include "edcs_internal.h"
#include "edcs_org_schema_dict.h"
#include "edcs_group_dict.h"
#include "edcs_unit_dict.h"
#include "edcs_unit_equivalence_dict.h"

static EDCS_Group_Pair
EGBindingForEA[] =
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
     * Begin output of the lists (for EAs with multiple groups)
     */

    /*
     * Entry 55
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },

    /*
     * Entry 57
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 59
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 61
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 66
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 70
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 73
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 76
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },

    /*
     * Entry 79
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 83
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },

    /*
     * Entry 85
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },

    /*
     * Entry 88
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },

    /*
     * Entry 90
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 93
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },

    /*
     * Entry 95
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 98
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 101
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_COLOUR, EOC_GENERAL },

    /*
     * Entry 103
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_COLOUR, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 106
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 109
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },

    /*
     * Entry 111
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 114
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },

    /*
     * Entry 116
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 119
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 122
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 125
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 128
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 132
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 135
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 139
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_FLUID_CONDITION, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 142
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_FLUID_CONDITION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 145
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 148
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 151
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },

    /*
     * Entry 153
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 157
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },

    /*
     * Entry 159
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 161
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 164
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 166
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 169
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 171
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 174
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 178
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 181
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 183
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 186
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 188
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 190
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 192
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 194
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 196
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 199
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 201
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 203
     */
    { EGC_GEN_ABSTRACT_OBJECT, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 205
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 209
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 212
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 216
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 219
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 222
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 225
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 229
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },

    /*
     * Entry 231
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 236
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 239
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 244
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 249
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 254
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 258
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 263
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 267
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 271
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 274
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 277
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 281
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 284
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 286
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 289
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 291
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 294
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 297
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 299
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 302
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 304
     */
    { EGC_GEN_ACOUSTIC_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 306
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 309
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 312
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },

    /*
     * Entry 315
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },

    /*
     * Entry 317
     */
    { EGC_GEN_ADMINISTRATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 319
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },

    /*
     * Entry 321
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 323
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 327
     */
    { EGC_GEN_AGRICULTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 329
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 334
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 339
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 343
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 347
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 350
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 354
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 357
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 361
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 365
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 369
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 372
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 375
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 380
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 384
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 388
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 392
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 395
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 398
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 402
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 405
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 408
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 412
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 416
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 419
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 421
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 424
     */
    { EGC_GEN_AIR_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 427
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },

    /*
     * Entry 429
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },

    /*
     * Entry 432
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },

    /*
     * Entry 435
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },

    /*
     * Entry 438
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 442
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 445
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 449
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 453
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 456
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 459
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 462
     */
    { EGC_GEN_AIRBORNE_PARTICLE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 465
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 468
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },

    /*
     * Entry 470
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 473
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_COLOUR, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 476
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 481
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 485
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },

    /*
     * Entry 487
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 489
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 492
     */
    { EGC_GEN_ALGORITHM_RELATED, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 494
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },

    /*
     * Entry 496
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 499
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 502
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 507
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 512
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 515
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 518
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },

    /*
     * Entry 520
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 522
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 525
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 529
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 533
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 536
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 539
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 543
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 545
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 547
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 550
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 552
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 554
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 556
     */
    { EGC_GEN_ANGULAR_MEASURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 558
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 563
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 569
     */
    { EGC_GEN_ANIMAL, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 571
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 574
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },

    /*
     * Entry 576
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 579
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 582
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },

    /*
     * Entry 584
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },

    /*
     * Entry 586
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 589
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 593
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },

    /*
     * Entry 596
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 601
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 605
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 607
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 611
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 614
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 618
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 621
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 625
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 628
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 631
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 637
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 641
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 644
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 648
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 651
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 653
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 657
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 660
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 662
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 665
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 668
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 672
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 676
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 678
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 681
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 684
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 687
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 689
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 692
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 694
     */
    { EGC_GEN_ATMOSPHERE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 696
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },

    /*
     * Entry 698
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },

    /*
     * Entry 700
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 702
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 705
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 707
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 709
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 711
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 714
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 718
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 720
     */
    { EGC_GEN_BUILDING_COMPONENT, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 722
     */
    { EGC_GEN_COLOUR, EOC_GENERAL },
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 725
     */
    { EGC_GEN_COLOUR, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 727
     */
    { EGC_GEN_COLOUR, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 729
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },

    /*
     * Entry 731
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 735
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 740
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 745
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 748
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 752
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 755
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 757
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 759
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 762
     */
    { EGC_GEN_COMMUNICATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 764
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 768
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 771
     */
    { EGC_GEN_DEMARCATION, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 774
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 777
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 780
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 782
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 785
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 787
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 789
     */
    { EGC_GEN_DEVICE_AND_EQUIPMENT, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 791
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },

    /*
     * Entry 793
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 796
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 801
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 805
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 808
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 810
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 813
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 816
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 818
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 822
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 825
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 827
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 831
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 834
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 837
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 839
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 842
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 845
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 847
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 850
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 852
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 855
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 857
     */
    { EGC_GEN_DIMENSION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 859
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 861
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 864
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 867
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 870
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 873
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },

    /*
     * Entry 875
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 879
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 885
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 888
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 892
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 896
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 901
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 904
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 908
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 912
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 915
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 917
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 919
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 922
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 924
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 926
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 929
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 933
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 936
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 940
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 943
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 945
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 948
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 951
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 954
     */
    { EGC_GEN_EM_PHENOMENON, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 956
     */
    { EGC_GEN_FLUID_CONDITION, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 958
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 963
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 967
     */
    { EGC_GEN_HARBOUR_AND_PORT, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 969
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 974
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 977
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 981
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 983
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 985
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 988
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 991
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 993
     */
    { EGC_GEN_HYDROGRAPHIC_ARTEFACT, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 995
     */
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1001
     */
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1008
     */
    { EGC_GEN_HYDROGRAPHIC_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1013
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1016
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1019
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1022
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1026
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1030
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1034
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1037
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1039
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1042
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1045
     */
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1048
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_HYDROGRAPHIC_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1051
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },

    /*
     * Entry 1053
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 1055
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 1057
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1061
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1063
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1066
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1068
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1072
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1075
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1077
     */
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1079
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1083
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1088
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1090
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1093
     */
    { EGC_GEN_ICE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1095
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 1097
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1101
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1104
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },

    /*
     * Entry 1106
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 1108
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 1110
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 1112
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 1114
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1116
     */
    { EGC_GEN_IDENTIFICATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1118
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },

    /*
     * Entry 1120
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1122
     */
    { EGC_GEN_INDUSTRY, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1124
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1127
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1129
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 1131
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1134
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1136
     */
    { EGC_GEN_INFRASTRUCTURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1138
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1143
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1146
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1149
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1153
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1156
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1159
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1163
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1165
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1168
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1171
     */
    { EGC_GEN_LAND_TRNSP, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1174
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1178
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 1180
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1182
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1185
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL },

    /*
     * Entry 1189
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },

    /*
     * Entry 1191
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_SPACE, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1194
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1196
     */
    { EGC_GEN_LIGHTING_AND_VISIBILITY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1198
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_LOCATION, EOC_GENERAL },

    /*
     * Entry 1200
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1203
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1205
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1207
     */
    { EGC_GEN_LITTORAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1209
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1213
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1218
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },

    /*
     * Entry 1220
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1223
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1227
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_PLANT, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1231
     */
    { EGC_GEN_LIVING_ORGANISM, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 1234
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1236
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1239
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },

    /*
     * Entry 1241
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },

    /*
     * Entry 1243
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1245
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_SURVEY, EOC_GENERAL },

    /*
     * Entry 1247
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1249
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1251
     */
    { EGC_GEN_LOCATION, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1253
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1256
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1258
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1261
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1264
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1267
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1270
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1274
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 1276
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1279
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1282
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1285
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1288
     */
    { EGC_GEN_MATERIAL, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1290
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1293
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1295
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },

    /*
     * Entry 1297
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1300
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1302
     */
    { EGC_GEN_MILITARY_SCIENCE, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1304
     */
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },

    /*
     * Entry 1306
     */
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1308
     */
    { EGC_GEN_PHYSIOGRAPHY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1310
     */
    { EGC_GEN_PROPERTY_SET, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1312
     */
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },

    /*
     * Entry 1314
     */
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 1316
     */
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_SURFACE_MATERIAL, EOC_GENERAL },

    /*
     * Entry 1319
     */
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1321
     */
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1323
     */
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1325
     */
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1327
     */
    { EGC_GEN_RATE_OR_RATIO, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1329
     */
    { EGC_GEN_RECREATION, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1331
     */
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1333
     */
    { EGC_GEN_SHELTER, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1335
     */
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_SURFACE, EOC_GENERAL },

    /*
     * Entry 1337
     */
    { EGC_GEN_SUPPORT_STRUCTURE, EOC_GENERAL },
    { EGC_GEN_TRNSP, EOC_GENERAL },

    /*
     * Entry 1339
     */
    { EGC_GEN_SURFACE, EOC_GENERAL },
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },

    /*
     * Entry 1341
     */
    { EGC_GEN_SURVEY, EOC_GENERAL },
    { EGC_GEN_TIME, EOC_GENERAL },

    /*
     * Entry 1343
     */
    { EGC_GEN_SURVEY, EOC_GENERAL },
    { EGC_GEN_WATERBODY_FLOOR, EOC_GENERAL },

    /*
     * Entry 1345
     */
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1347
     */
    { EGC_GEN_TEMPERATURE, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1349
     */
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_HYDROLOGY, EOC_GENERAL },

    /*
     * Entry 1351
     */
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_WATERBODY_STATE, EOC_GENERAL },

    /*
     * Entry 1353
     */
    { EGC_GEN_TIME, EOC_GENERAL },
    { EGC_GEN_WATERBODY_SURFACE, EOC_GENERAL },

    /*
     * Entry 1355
     */
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_USAGE_REGION, EOC_GENERAL },

    /*
     * Entry 1357
     */
    { EGC_GEN_TRNSP, EOC_GENERAL },
    { EGC_GEN_VEHICLE, EOC_GENERAL }

}; /* end EGBindingForEA */

/*
 *  declaring it here so we can reference it from the
 *  enumerated attribute dictionary entries.  Look in
 *  edcs_enum_dict.c for the definition.
 */
extern EDCS_Enumerant_Dictionary_Entry EDCS_Enumerant_Dictionary[];
static const EDCS_Attribute_Dictionary_Entry
EDCS_Attribute_Dictionary[] =
{
    {EAC_ABSOLUTE_ELEVATION_ACCURACY,
    "ABSOLUTE_ELEVATION_ACCURACY", "EAC_ABSOLUTE_ELEVATION_ACCURACY",
    "The 90^(th) percentile of error in an <<ELEVATION>>; the absolute"
    " elevation accuracy.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1245]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[MCGA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ABSOLUTE_HORIZONTAL_ACCURACY,
    "ABSOLUTE_HORIZONTAL_ACCURACY", "EAC_ABSOLUTE_HORIZONTAL_ACCURACY",
    "The 90^(th) percentile of horizontal circular error of a <LOCATION>"
    " relative to a defined standard; the absolute horizontal accuracy.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1245]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AHA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ABSOLUTE_HUMIDITY,
    "ABSOLUTE_HUMIDITY", "EAC_ABSOLUTE_HUMIDITY",
    "The ratio of the <<MASS>> of water vapour to the <<VOLUME>> occupied"
    " by the mixture of water vapour and dry <AIR>; the absolute humidity.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"absolute humidity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ABSOLUTE_LATITUDE_ACCURACY,
    "ABSOLUTE_LATITUDE_ACCURACY", "EAC_ABSOLUTE_LATITUDE_ACCURACY",
    "The 90^(th) percentile of angular error of a geodetic latitude value"
    " of a <LOCATION> relative to a <SURFACE_DATUM>; the absolute latitude"
    " accuracy.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[547]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ALA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ABSOLUTE_LONGITUDE_ACCURACY,
    "ABSOLUTE_LONGITUDE_ACCURACY", "EAC_ABSOLUTE_LONGITUDE_ACCURACY",
    "The 90^(th) percentile of angular error of a geodetic longitude value"
    " of a <LOCATION> relative to a <SURFACE_DATUM>; the absolute longitude"
    " accuracy.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[547]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ALO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ABSOLUTE_VERTICAL_ACCURACY,
    "ABSOLUTE_VERTICAL_ACCURACY", "EAC_ABSOLUTE_VERTICAL_ACCURACY",
    "The vertical accuracy of a <LOCATION> relative to a defined standard"
    " expressed in units of length at 90% linear error; the absolute"
    " vertical accuracy.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1245]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AVA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCESS_DIRECTION_TYPE,
    "ACCESS_DIRECTION_TYPE", "EAC_ACCESS_DIRECTION_TYPE",
    "The type of access direction of an <OBJECT> in reference to allowable"
    " traffic flow.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 4, &(EDCS_Enumerant_Dictionary[0]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: ADT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCESSIBILITY_STATUS,
    "ACCESSIBILITY_STATUS", "EAC_ACCESSIBILITY_STATUS",
    "The type of accessibility of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 7, &(EDCS_Enumerant_Dictionary[4]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: ACS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUM_PRECIP,
    "ACCUM_PRECIP", "EAC_ACCUM_PRECIP",
    "The depth of <PRECIPITATION> (water-equivalent) that accumulated over"
    " a measurement <<TIME_QUANTITY>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[601]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 12.7.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUM_PRECIP_24_HOUR,
    "ACCUM_PRECIP_24_HOUR", "EAC_ACCUM_PRECIP_24_HOUR",
    "The <<ACCUM_PRECIP>> during a 24-hour <<TIME_QUANTITY>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[601]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 12.7.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUM_PRECIP_24_HOUR_DENSITY,
    "ACCUM_PRECIP_24_HOUR_DENSITY", "EAC_ACCUM_PRECIP_24_HOUR_DENSITY",
    "The <<ACCUM_PRECIP_24_HOUR>> expressed as a surface density.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    3, &(EGBindingForEA[1258]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 12.7.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUM_PRECIP_3_HOUR,
    "ACCUM_PRECIP_3_HOUR", "EAC_ACCUM_PRECIP_3_HOUR",
    "The <<ACCUM_PRECIP>> during a 3-hour <<TIME_QUANTITY>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[601]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 12.7.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUM_PRECIP_3_HOUR_DENSITY,
    "ACCUM_PRECIP_3_HOUR_DENSITY", "EAC_ACCUM_PRECIP_3_HOUR_DENSITY",
    "The <<ACCUM_PRECIP_3_HOUR>> expressed as a surface density.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    4, &(EGBindingForEA[672]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 12.7.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUM_PRECIP_6_HOUR,
    "ACCUM_PRECIP_6_HOUR", "EAC_ACCUM_PRECIP_6_HOUR",
    "The <<ACCUM_PRECIP>> during a 6-hour <<TIME_QUANTITY>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[601]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 12.7.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUM_PRECIP_6_HOUR_DENSITY,
    "ACCUM_PRECIP_6_HOUR_DENSITY", "EAC_ACCUM_PRECIP_6_HOUR_DENSITY",
    "The <<ACCUM_PRECIP_6_HOUR>> expressed as a surface density.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    4, &(EGBindingForEA[672]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 12.7.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUM_PRECIP_DENSITY,
    "ACCUM_PRECIP_DENSITY", "EAC_ACCUM_PRECIP_DENSITY",
    "The <<ACCUM_PRECIP>> expressed as a surface density.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, I.1, Part B, BUFR Code Table B.13]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUMULATION_PERIOD,
    "ACCUMULATION_PERIOD", "EAC_ACCUMULATION_PERIOD",
    "The <<TIME_QUANTITY>> prior to the referenced time over which a"
    " <MATERIAL> has accumulated; the accumulation period.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[1282]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACCUMULATION_PERIOD_CATEGORY,
    "ACCUMULATION_PERIOD_CATEGORY", "EAC_ACCUMULATION_PERIOD_CATEGORY",
    "The category of an <<ACCUMULATION_PERIOD>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 20, &(EDCS_Enumerant_Dictionary[11]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_BOUNDARY_LOSS,
    "ACOUSTIC_BOUNDARY_LOSS", "EAC_ACOUSTIC_BOUNDARY_LOSS",
    "The quantity of acoustic energy that is lost at a specific angle due"
    " to interaction of an acoustic signal waveform with either the"
    " <WATERBODY_SURFACE> or the <WATERBODY_FLOOR>; the acoustic boundary"
    " loss.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    5, &(EGBindingForEA[231]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_CENTRE_FREQUENCY_BAND,
    "ACOUSTIC_CENTRE_FREQUENCY_BAND", "EAC_ACOUSTIC_CENTRE_FREQUENCY_BAND",
    "The electro-acoustic one-third-octave band centre <<FREQUENCY>>"
    " (approximate).",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[1]), 60, &(EDCS_Enumerant_Dictionary[31]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[I266]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_HALFCHANNEL_OBSERVATION_FRACTION,
    "ACOUSTIC_HALFCHANNEL_OBSERVATION_FRACTION", "EAC_ACOUSTIC_HALFCHANNEL_OBSERVATION_FRACTION",
    "A number between 0 and 1 inclusive representing the fraction of"
    " observations indicating the presence of an acoustic half-channel in a"
    " <WATERBODY>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_NOISE_MARGINAL_ICE_ZONE_MULTIPLIER,
    "ACOUSTIC_NOISE_MARGINAL_ICE_ZONE_MULTIPLIER", "EAC_ACOUSTIC_NOISE_MARGINAL_ICE_ZONE_MULTIPLIER",
    "The correction factor applied to underwater sound levels that"
    " incorporates acoustic noise related to an <AIRCRAFT> operating in the"
    " marginal ice zone.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[205]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_NOISE_SPECTRAL_CURVE_CORRECTION,
    "ACOUSTIC_NOISE_SPECTRAL_CURVE_CORRECTION", "EAC_ACOUSTIC_NOISE_SPECTRAL_CURVE_CORRECTION",
    "The acoustic noise level correction obtained from a spectral class"
    " curve to be applied to some base acoustic noise level in a"
    " <WATERBODY>; the acoustic noise spectral curve correction.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_PWR_LVL_BAND,
    "ACOUSTIC_PWR_LVL_BAND", "EAC_ACOUSTIC_PWR_LVL_BAND",
    "The power level of acoustic energy in a <WATERBODY> measured one metre"
    " from the source acoustic centre in a defined frequency band.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_PWR_LVL_SPECTRUM,
    "ACOUSTIC_PWR_LVL_SPECTRUM", "EAC_ACOUSTIC_PWR_LVL_SPECTRUM",
    "The ratio of sound wave intensity in a <WATERBODY> in a one hertz band"
    " to a reference intensity measured one metre from the source; the"
    " acoustic power level spectrum.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_PWR_LVL_SPECTRUM_CORRECTION,
    "ACOUSTIC_PWR_LVL_SPECTRUM_CORRECTION", "EAC_ACOUSTIC_PWR_LVL_SPECTRUM_CORRECTION",
    "The omnidirectional ambient noise spectrum level correction in a"
    " <WATERBODY> at a specified <<FREQUENCY>> referenced to a 50 hertz"
    " reference level; the acoustic power level spectrum correction.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_REFLECTION_TYPE,
    "ACOUSTIC_REFLECTION_TYPE", "EAC_ACOUSTIC_REFLECTION_TYPE",
    "The type of acoustic reflection from a <WATERBODY_FLOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[302]), 2, &(EDCS_Enumerant_Dictionary[91]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_REFLECTOR,
    "ACOUSTIC_REFLECTOR", "EAC_ACOUSTIC_REFLECTOR",
    "An indication that an <OBJECT> reflects acoustic energy in a specified"
    " band of <<FREQUENCY>>s; acoustic reflector.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[59]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"acoustic reflectivity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_SCATTERING_STRENGTH,
    "ACOUSTIC_SCATTERING_STRENGTH", "EAC_ACOUSTIC_SCATTERING_STRENGTH",
    "The column (integrated) acoustic scattering strength (ratio of"
    " returned to incident energy) in a <WATERBODY>.",
    EDCS_AVT_REAL, EQC_AREIC_POWER_LEVEL_DIFF,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Volume Scattering Strength Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_TARGET_STRENGTH,
    "ACOUSTIC_TARGET_STRENGTH", "EAC_ACOUSTIC_TARGET_STRENGTH",
    "The ratio of the intensity of sound returned by a sonar target at a"
    " distance of one metre from the acoustic centre of the target in a"
    " specified <DIRECTION> to the incident intensity from a distant"
    " source; the acoustic target strength.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    2, &(EGBindingForEA[289]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_TRANSMISSION_LOSS,
    "ACOUSTIC_TRANSMISSION_LOSS", "EAC_ACOUSTIC_TRANSMISSION_LOSS",
    "The acoustic <<TRANSMISSION_LOSS>>.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    2, &(EGBindingForEA[289]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACOUSTIC_VOLUME_LAYER_SCATTERING_STRENGTH_FREQUENCY,
    "ACOUSTIC_VOLUME_LAYER_SCATTERING_STRENGTH_FREQUENCY", "EAC_ACOUSTIC_VOLUME_LAYER_SCATTERING_STRENGTH_FREQUENCY",
    "The acoustic <<FREQUENCY>> at which a volume layer scattering strength"
    " in a <WATERBODY> is reported.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    2, &(EGBindingForEA[304]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Volume Scattering Strength Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ACTIVE_ACOUSTIC,
    "ACTIVE_ACOUSTIC", "EAC_ACTIVE_ACOUSTIC",
    "An indication that an <OBJECT> generates intentional emissions of"
    " acoustic energy used for the purposes of detection, localization,"
    " and/or identification; active acoustic.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[59]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERIAL_COUNT,
    "AERIAL_COUNT", "EAC_AERIAL_COUNT",
    "The number of distinct <AERIAL>s on a <STRUCTURE>; the aerial count.",
    EDCS_AVT_COUNT, 0,
    5, &(EGBindingForEA[735]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERIAL_FUNCTION,
    "AERIAL_FUNCTION", "EAC_AERIAL_FUNCTION",
    "The function of an <AERIAL>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[731]), 7, &(EDCS_Enumerant_Dictionary[93]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERIAL_TYPE,
    "AERIAL_TYPE", "EAC_AERIAL_TYPE",
    "The structural type of an <AERIAL>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[731]), 6, &(EDCS_Enumerant_Dictionary[100]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERODROME_ELEVATION,
    "AERODROME_ELEVATION", "EAC_AERODROME_ELEVATION",
    "The highest <<ELEVATION>> of the usable <RUNWAY>s of an <AERODROME>,"
    " measured from the MSL <SURFACE_DATUM>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[405]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ZV3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERODROME_EMERGENCY_LIGHTING_INTENSITY,
    "AERODROME_EMERGENCY_LIGHTING_INTENSITY", "EAC_AERODROME_EMERGENCY_LIGHTING_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of emergency <LIGHTING> at an <AERODROME>. Zero"
    " means no light and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    5, &(EGBindingForEA[375]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERODROME_GATE_LIGHTING_INTENSITY,
    "AERODROME_GATE_LIGHTING_INTENSITY", "EAC_AERODROME_GATE_LIGHTING_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of external gate <LIGHTING> at an <AERODROME>."
    " Zero means no light and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    5, &(EGBindingForEA[375]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERODROME_IDENTIFICATION,
    "AERODROME_IDENTIFICATION", "EAC_AERODROME_IDENTIFICATION",
    "The unique set of numbers preceded by the appropriate country code"
    " that enables an individual <AERODROME> to be uniquely identified"
    " within a database; the aerodrome identification.",
    EDCS_AVT_STRING, 0,
    4, &(EGBindingForEA[339]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[DAFIF, Sec. 201.A.1, \"Airport Identification\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERODROME_TYPE,
    "AERODROME_TYPE", "EAC_AERODROME_TYPE",
    "The type of an <AERODROME>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[421]), 21, &(EDCS_Enumerant_Dictionary[106]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: APT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERONAUTICAL_APPROACH_TYPE,
    "AERONAUTICAL_APPROACH_TYPE", "EAC_AERONAUTICAL_APPROACH_TYPE",
    "The type of an aeronautical approach.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[4]), 6, &(EDCS_Enumerant_Dictionary[127]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: AAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERONAUTICAL_FUNCTION,
    "AERONAUTICAL_FUNCTION", "EAC_AERONAUTICAL_FUNCTION",
    "The function of an aeronautical <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[4]), 12, &(EDCS_Enumerant_Dictionary[133]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: AMC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERONAUTICAL_LIGHT_TYPE,
    "AERONAUTICAL_LIGHT_TYPE", "EAC_AERONAUTICAL_LIGHT_TYPE",
    "The type of <LIGHTING> or <SYSTEM> of <LIGHTING> that supports"
    " aeronautical navigation; the aeronautical light type.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[402]), 91, &(EDCS_Enumerant_Dictionary[145]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LFA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERONAUTICAL_OBSTRUCTION_HEIGHT_ACCURACY,
    "AERONAUTICAL_OBSTRUCTION_HEIGHT_ACCURACY", "EAC_AERONAUTICAL_OBSTRUCTION_HEIGHT_ACCURACY",
    "The difference between the recorded <<HEIGHT_AGL>> of an <OBJECT>"
    " forming a <NATURAL_AIR_OBSTRUCTION> or <MAN_MADE_AIR_OBSTRUCTION> and"
    " its true <<HEIGHT_AGL>> at 90% probability; the aeronautical"
    " obstruction height accuracy.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[405]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AHO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERONAUTICAL_POINT_FUNCTION,
    "AERONAUTICAL_POINT_FUNCTION", "EAC_AERONAUTICAL_POINT_FUNCTION",
    "The function of an aeronautical point <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[4]), 8, &(EDCS_Enumerant_Dictionary[236]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: APC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AERONAUTICAL_ROUTE_TYPE,
    "AERONAUTICAL_ROUTE_TYPE", "EAC_AERONAUTICAL_ROUTE_TYPE",
    "The type of an <AIR_TRANSPORTATION_ROUTE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[4]), 3, &(EDCS_Enumerant_Dictionary[244]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: ART]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AEROSOL_LAYER_BASE_LEVEL,
    "AEROSOL_LAYER_BASE_LEVEL", "EAC_AEROSOL_LAYER_BASE_LEVEL",
    "The vertical displacement of the lowest <SURFACE> of a layer of an"
    " <AEROSOL> identified by an <<ATM_VERTICAL_REFERENCE>>; the aerosol"
    " layer base level.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AEROSOL_LAYER_TOP_LEVEL,
    "AEROSOL_LAYER_TOP_LEVEL", "EAC_AEROSOL_LAYER_TOP_LEVEL",
    "The vertical displacement of the highest <SURFACE> of a layer of an"
    " <AEROSOL> identified by an <<ATM_VERTICAL_REFERENCE>>; the aerosol"
    " layer top level.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"AEROSOL-ANALYSIS-FORECAST top height dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AEROSOL_PARTICLE_CONCENTRATION,
    "AEROSOL_PARTICLE_CONCENTRATION", "EAC_AEROSOL_PARTICLE_CONCENTRATION",
    "The <PARTICLE> concentration of an <AEROSOL>.",
    EDCS_AVT_REAL, EQC_VOLUMETRIC_ENTITY_DENSITY,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[PRUP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AEROSOL_PARTICLE_TYPE,
    "AEROSOL_PARTICLE_TYPE", "EAC_AEROSOL_PARTICLE_TYPE",
    "The type of <PARTICLE> in an <AEROSOL>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 14, &(EDCS_Enumerant_Dictionary[247]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AFTERBURNER_INDUCED_FLAME_RATE,
    "AFTERBURNER_INDUCED_FLAME_RATE", "EAC_AFTERBURNER_INDUCED_FLAME_RATE",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the production rate of visible flame that is induced by"
    " use of the afterburner of an <AIRCRAFT>; the afterburner induced"
    " flame rate. Zero means no production and one means maximum production.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[412]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.2, Bit: 16 (Afterburner)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_COLOUR_PATTERN,
    "AID_TO_NAVIGATION_COLOUR_PATTERN", "EAC_AID_TO_NAVIGATION_COLOUR_PATTERN",
    "The colour pattern of an <OBJECT> (for example: an"
    " <AID_TO_NAVIGATION>, a <BUOY>, a <BEACON>, and/or a"
    " <NAVIGATION_LIGHT>) of importance to navigation.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[103]), 9, &(EDCS_Enumerant_Dictionary[261]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PAT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_DESCRIPTION,
    "AID_TO_NAVIGATION_DESCRIPTION", "EAC_AID_TO_NAVIGATION_DESCRIPTION",
    "The textual description of <AID_TO_NAVIGATION>s that are marking an"
    " <OBJECT>. EXAMPLE Marked by <BUOY>s.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[789]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DAN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_EFFECTIVENESS_RADIUS,
    "AID_TO_NAVIGATION_EFFECTIVENESS_RADIUS", "EAC_AID_TO_NAVIGATION_EFFECTIVENESS_RADIUS",
    "The radius of effectiveness of an <AID_TO_NAVIGATION>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[774]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RAN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_MARK_COLOUR,
    "AID_TO_NAVIGATION_MARK_COLOUR", "EAC_AID_TO_NAVIGATION_MARK_COLOUR",
    "The colours of an <AID_TO_NAVIGATION> mark.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[727]), 18, &(EDCS_Enumerant_Dictionary[270]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MAR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_MARK_SYSTEM,
    "AID_TO_NAVIGATION_MARK_SYSTEM", "EAC_AID_TO_NAVIGATION_MARK_SYSTEM",
    "The specific <SYSTEM> of marks that serve as an <AID_TO_NAVIGATION>"
    " and to which an <OBJECT> conforms.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[199]), 11, &(EDCS_Enumerant_Dictionary[288]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: MARSYS]",
    "[FACC, Annex B: NMS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_MARKER_TYPE,
    "AID_TO_NAVIGATION_MARKER_TYPE", "EAC_AID_TO_NAVIGATION_MARKER_TYPE",
    "The type of a <MARKER> serving as an <AID_TO_NAVIGATION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[789]), 5, &(EDCS_Enumerant_Dictionary[299]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BDT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_PRIMARY_OPERATING_RANGE,
    "AID_TO_NAVIGATION_PRIMARY_OPERATING_RANGE", "EAC_AID_TO_NAVIGATION_PRIMARY_OPERATING_RANGE",
    "The primary operating range of an <AID_TO_NAVIGATION> beyond which the"
    " capture of the signal is not completely assured.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[774]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ORC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_RANGE,
    "AID_TO_NAVIGATION_RANGE", "EAC_AID_TO_NAVIGATION_RANGE",
    "The length of range established by <AID_TO_NAVIGATION>s on the <SHORE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[774]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LRP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_SECONDARY_OPERATING_RANGE,
    "AID_TO_NAVIGATION_SECONDARY_OPERATING_RANGE", "EAC_AID_TO_NAVIGATION_SECONDARY_OPERATING_RANGE",
    "The secondary operating range of an <AID_TO_NAVIGATION> beyond which"
    " the capture of the signal is not completely assured.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[774]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OR2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_STATUS,
    "AID_TO_NAVIGATION_STATUS", "EAC_AID_TO_NAVIGATION_STATUS",
    "The status of an <OBJECT> as an <AID_TO_NAVIGATION>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[111]), 4, &(EDCS_Enumerant_Dictionary[304]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ATN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AID_TO_NAVIGATION_SYSTEM_TYPE,
    "AID_TO_NAVIGATION_SYSTEM_TYPE", "EAC_AID_TO_NAVIGATION_SYSTEM_TYPE",
    "The type of a <SYSTEM> of <AID_TO_NAVIGATION>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[789]), 11, &(EDCS_Enumerant_Dictionary[308]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: IAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIR_DENSITY,
    "AIR_DENSITY", "EAC_AIR_DENSITY",
    "The <<MATERIAL_DENSITY>> of the <AIR>.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    3, &(EGBindingForEA[665]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"air density\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIR_EXFILTRATION_RATE,
    "AIR_EXFILTRATION_RATE", "EAC_AIR_EXFILTRATION_RATE",
    "The rate at which interior <AIR> leaks out of a <STRUCTURE> expressed"
    " as the fraction of the <<VOLUME>> of <AIR> in the <STRUCTURE> per"
    " unit time; the air exfiltration rate.",
    EDCS_AVT_REAL, EQC_RATE,
    3, &(EGBindingForEA[681]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HVACS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIR_INFILTRATION_RATE,
    "AIR_INFILTRATION_RATE", "EAC_AIR_INFILTRATION_RATE",
    "The rate at which exterior <AIR> leaks into a <STRUCTURE> expressed as"
    " the fraction of the <<VOLUME>> of <AIR> in the <STRUCTURE> per unit"
    " time; the air infiltration rate.",
    EDCS_AVT_REAL, EQC_RATE,
    3, &(EGBindingForEA[681]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HVACS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIR_TEMPERATURE,
    "AIR_TEMPERATURE", "EAC_AIR_TEMPERATURE",
    "The <<TEMPERATURE>> of the <AIR> that would be indicated by a"
    " thermometer exposed to the <AIR> at a <LOCATION> sheltered from"
    " direct solar radiation.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"air temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIR_TEMPERATURE_ERROR,
    "AIR_TEMPERATURE_ERROR", "EAC_AIR_TEMPERATURE_ERROR",
    "The error in a measurement of an <<AIR_TEMPERATURE>> that is"
    " introduced by uncertainties.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIR_TEMPERATURE_PERIOD,
    "AIR_TEMPERATURE_PERIOD", "EAC_AIR_TEMPERATURE_PERIOD",
    "The <<TIME_QUANTITY>> over which the <<EXTREME_LOW_AIR_TEMPERATURE>>"
    " and/or the <<EXTREME_HIGH_AIR_TEMPERATURE>> are determined.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[692]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_CARRIER_CLASS,
    "AIRCRAFT_CARRIER_CLASS", "EAC_AIRCRAFT_CARRIER_CLASS",
    "The class of an <AIRCRAFT_CARRIER>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[380]), 13, &(EDCS_Enumerant_Dictionary[319]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_FUNCTION,
    "AIRCRAFT_FUNCTION", "EAC_AIRCRAFT_FUNCTION",
    "The operating function of an <AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[424]), 29, &(EDCS_Enumerant_Dictionary[332]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_ICING_INTENSITY,
    "AIRCRAFT_ICING_INTENSITY", "EAC_AIRCRAFT_ICING_INTENSITY",
    "The estimated intensity of the accumulation of <ICE> on exposed"
    " <SURFACE>s of an <AIRCRAFT> that is formed as the <AIRCRAFT> is flown"
    " through supercooled drops of <WATER> in <CLOUD>s or <RAIN>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[388]), 13, &(EDCS_Enumerant_Dictionary[361]),
    EDCS_REF_TYP_INFORMATIVE, "[AWS, Table 3.4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_ICING_LEVEL_BASE_ALTITUDE,
    "AIRCRAFT_ICING_LEVEL_BASE_ALTITUDE", "EAC_AIRCRAFT_ICING_LEVEL_BASE_ALTITUDE",
    "The estimated <<ALTITUDE_MSL>> of the lower <SURFACE> of a layer in"
    " the <ATMOSPHERE> at which an <AIRCRAFT> can be expected to experience"
    " icing.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[384]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"icing level\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_ICING_LEVEL_TOP_ALTITUDE,
    "AIRCRAFT_ICING_LEVEL_TOP_ALTITUDE", "EAC_AIRCRAFT_ICING_LEVEL_TOP_ALTITUDE",
    "The estimated <<ALTITUDE_MSL>> of the upper <SURFACE> of a layer in"
    " the <ATMOSPHERE> at which an <AIRCRAFT> can be expected to experience"
    " icing.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[384]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"icing level\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_ICING_TYPE,
    "AIRCRAFT_ICING_TYPE", "EAC_AIRCRAFT_ICING_TYPE",
    "The type of <ICE> that is expected to accumulate on the <SURFACE> of"
    " an <AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[388]), 5, &(EDCS_Enumerant_Dictionary[374]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"aircraft icing\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_LANDING_GEAR_DEPLOYED_POSITION,
    "AIRCRAFT_LANDING_GEAR_DEPLOYED_POSITION", "EAC_AIRCRAFT_LANDING_GEAR_DEPLOYED_POSITION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional deployment of the landing gear of an <AIRCRAFT>. Zero"
    " means fully retracted and one means fully deployed.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[412]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_LOAD_RESTRICTIONS,
    "AIRCRAFT_LOAD_RESTRICTIONS", "EAC_AIRCRAFT_LOAD_RESTRICTIONS",
    "The description of any load restrictions that apply to <AIRCRAFT>"
    " using a <FACILITY>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[424]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ALC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_PROPULSION_TYPE,
    "AIRCRAFT_PROPULSION_TYPE", "EAC_AIRCRAFT_PROPULSION_TYPE",
    "The type of propulsion of an <AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[424]), 5, &(EDCS_Enumerant_Dictionary[379]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_TURBULENCE_BASE_ALTITUDE,
    "AIRCRAFT_TURBULENCE_BASE_ALTITUDE", "EAC_AIRCRAFT_TURBULENCE_BASE_ALTITUDE",
    "The <<ALTITUDE_MSL>> of the lower <SURFACE> of a layer of <ATMOSPHERE>"
    " that is turbulent to <AIRCRAFT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[350]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"AIRCRAFT-TURBULENCE-OBSERVATION base dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_TURBULENCE_FREQUENCY,
    "AIRCRAFT_TURBULENCE_FREQUENCY", "EAC_AIRCRAFT_TURBULENCE_FREQUENCY",
    "The rate of occurrence of turbulence experienced by <AIRCRAFT>;"
    " aircraft turbulence frequency.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[354]), 6, &(EDCS_Enumerant_Dictionary[384]),
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"AIRCRAFT-TURBULENCE-OBSERVATION frequency code\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_TURBULENCE_INTENSITY,
    "AIRCRAFT_TURBULENCE_INTENSITY", "EAC_AIRCRAFT_TURBULENCE_INTENSITY",
    "The intensity of turbulence experienced by <AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[354]), 8, &(EDCS_Enumerant_Dictionary[390]),
    EDCS_REF_TYP_INFORMATIVE, "[AIM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_TURBULENCE_TOP_ALTITUDE,
    "AIRCRAFT_TURBULENCE_TOP_ALTITUDE", "EAC_AIRCRAFT_TURBULENCE_TOP_ALTITUDE",
    "The <<ALTITUDE_MSL>> of the upper <SURFACE> of a layer of <ATMOSPHERE>"
    " that is turbulent to <AIRCRAFT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[350]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"AIRCRAFT-TURBULENCE-OBSERVATION top dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRCRAFT_TYPE,
    "AIRCRAFT_TYPE", "EAC_AIRCRAFT_TYPE",
    "The type of an <AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[424]), 15, &(EDCS_Enumerant_Dictionary[398]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRSPACE_ALTITUDE_LIMITS,
    "AIRSPACE_ALTITUDE_LIMITS", "EAC_AIRSPACE_ALTITUDE_LIMITS",
    "The description of the altitude limits of a <SPECIAL_USE_AIRSPACE>"
    " relative to a <<ATM_VERTICAL_REFERENCE>>.",
    EDCS_AVT_STRING, 0,
    4, &(EGBindingForEA[365]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SUA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRSPACE_IDENTIFIER,
    "AIRSPACE_IDENTIFIER", "EAC_AIRSPACE_IDENTIFIER",
    "The textual identifier of an <AIRSPACE>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[392]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AIA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRSPACE_LIMITATION,
    "AIRSPACE_LIMITATION", "EAC_AIRSPACE_LIMITATION",
    "The type of <AIRSPACE> wherein activities must be confined because of"
    " their nature and/or wherein limitations may be imposed upon"
    " <AIRCRAFT> operations.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[421]), 35, &(EDCS_Enumerant_Dictionary[413]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AUL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRSPACE_OPERATING_RESTRICTIONS,
    "AIRSPACE_OPERATING_RESTRICTIONS", "EAC_AIRSPACE_OPERATING_RESTRICTIONS",
    "The status of an <AIRSPACE> and any operating restrictions that are"
    " applicable.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[419]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AUS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AIRSPACE_TYPE,
    "AIRSPACE_TYPE", "EAC_AIRSPACE_TYPE",
    "The type of designated <AIRSPACE> within which some or all <AIRCRAFT>"
    " may be subject to air traffic control.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 68, &(EDCS_Enumerant_Dictionary[448]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AUB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ALBEDO,
    "ALBEDO", "EAC_ALBEDO",
    "The ratio of the reflected electromagnetic radiation to the total"
    " incident electromagnetic radiation incident upon a <SURFACE> (for"
    " example: a <PLANETARY_SURFACE>); albedo.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[924]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"albedo\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ALL_OBJECT_COUNT,
    "ALL_OBJECT_COUNT", "EAC_ALL_OBJECT_COUNT",
    "The number of <OBJECT>s of all types within a <REGION>; the all object"
    " count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ALONGSHORE_CURRENT_SPEED,
    "ALONGSHORE_CURRENT_SPEED", "EAC_ALONGSHORE_CURRENT_SPEED",
    "The <<WATER_CURRENT_SPEED>> of a <WATER_CURRENT> paralleling a"
    " <SHORE>, largely within the <SURF_ZONE>, caused by the excess <WATER>"
    " brought to the <SURF_ZONE> by the small net mass transport of"
    " <WATER_WAVE>s induced by <WIND>; alongshore <WATER_CURRENT>s feed"
    " into rip <WATER_CURRENT>s.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1205]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ALTITUDE_MSL,
    "ALTITUDE_MSL", "EAC_ALTITUDE_MSL",
    "The altitude relative to the MSL <SURFACE_DATUM>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.7.4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ANGULAR_SECTOR_WIDTH,
    "ANGULAR_SECTOR_WIDTH", "EAC_ANGULAR_SECTOR_WIDTH",
    "The angular width of an angular sector.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[518]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ANTI_COLLISION_LIGHT_INTENSITY,
    "ANTI_COLLISION_LIGHT_INTENSITY", "EAC_ANTI_COLLISION_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of external <LIGHTING> that is used to prevent"
    " collision with/between <VEHICLE>s; the anti-collision light intensity"
    " or brake light intensity. Zero means unlit and one means maximum"
    " intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    5, &(EGBindingForEA[896]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.2, Bit: 16 (Anti-Collision Lights)]",
    "[EBEV, 4.3.1.1, Bit: 14 (Brake Lights)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_APERTURE_COVER_FRACTION,
    "APERTURE_COVER_FRACTION", "EAC_APERTURE_COVER_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional <<AREA>> of an <APERTURE> that is covered by <MATERIAL>s"
    " obstructing visibility. Zero means uncovered and one means completely"
    " covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1182]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bits: 9-11 (Hatch)]",
    "[EBEV, 4.3.1.2, Bits: 9-11 (Canopy)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_APERTURE_COVER_POSITION,
    "APERTURE_COVER_POSITION", "EAC_APERTURE_COVER_POSITION",
    "The position of the covering (for example: a canopy and/or a hatch) of"
    " an <APERTURE>; the aperture cover position.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[32]), 5, &(EDCS_Enumerant_Dictionary[516]),
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bits: 9-11 (Hatch)]",
    "[EBEV, 4.3.1.2, Bits: 9-11 (Canopy)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_APERTURE_LENGTH,
    "APERTURE_LENGTH", "EAC_APERTURE_LENGTH",
    "The length of the longer of two orthogonal linear axes of an"
    " <APERTURE> measured in the plane of the <APERTURE>; the aperture"
    " length. For a square <APERTURE>, either axis may be measured. For a"
    " round <APERTURE>, the diameter is measured.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[850]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_APERTURE_OPEN,
    "APERTURE_OPEN", "EAC_APERTURE_OPEN",
    "An indication that an <APERTURE> is open.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[43]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_APERTURE_STATE,
    "APERTURE_STATE", "EAC_APERTURE_STATE",
    "The state of closure of an <APERTURE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[43]), 4, &(EDCS_Enumerant_Dictionary[521]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_APERTURE_WIDTH,
    "APERTURE_WIDTH", "EAC_APERTURE_WIDTH",
    "The length of the shorter of two orthogonal linear axes of an"
    " <APERTURE> measured in the plane of the <APERTURE>; the aperture"
    " width. For a square <APERTURE>, either axis may be measured. For a"
    " round <APERTURE>, the diameter is measured.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[850]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_APRON_HARD_STANDING_FUNCTION,
    "APRON_HARD_STANDING_FUNCTION", "EAC_APRON_HARD_STANDING_FUNCTION",
    "The function of an <APRON> or <HARD_STANDING>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[4]), 16, &(EDCS_Enumerant_Dictionary[525]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: HAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AQUEDUCT_TYPE,
    "AQUEDUCT_TYPE", "EAC_AQUEDUCT_TYPE",
    "The type of an <AQUEDUCT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 9, &(EDCS_Enumerant_Dictionary[541]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ATC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AREA,
    "AREA", "EAC_AREA",
    "The area of the <OBJECT>.",
    EDCS_AVT_REAL, EQC_AREA,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ARH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ARMOURED,
    "ARMOURED", "EAC_ARMOURED",
    "An indication that an <OBJECT> is armoured.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[181]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"armoured\", 1]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ARRESTING_GEAR_TYPE,
    "ARRESTING_GEAR_TYPE", "EAC_ARRESTING_GEAR_TYPE",
    "The type of <DEVICE> at the end of a <RUNWAY> that is used to stop"
    " <AIRCRAFT>; the arresting gear type.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[369]), 3, &(EDCS_Enumerant_Dictionary[550]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AGC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ASPECT_ANGLE,
    "ASPECT_ANGLE", "EAC_ASPECT_ANGLE",
    "The angle measured from the major axis of an <OBJECT> clockwise to the"
    " viewing <DIRECTION>; the aspect angle. Zero represents either the"
    " <DIRECTION> of motion, or other unique orientation along the primary"
    " axis, heading directly towards the observer.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ASSAULT_LANDING_CRAFT_TYPE,
    "ASSAULT_LANDING_CRAFT_TYPE", "EAC_ASSAULT_LANDING_CRAFT_TYPE",
    "The type of a <LANDING_CRAFT> designed for amphibious assault"
    " operations.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 11, &(EDCS_Enumerant_Dictionary[553]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ASSOCIATED_TEXT,
    "ASSOCIATED_TEXT", "EAC_ASSOCIATED_TEXT",
    "Narrative or other textual description associated with an <OBJECT>;"
    " the associated text.",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TXT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ASW_CENTROID_PRESENT,
    "ASW_CENTROID_PRESENT", "EAC_ASW_CENTROID_PRESENT",
    "An indication that the centroid of an ASW operating <REGION> exists"
    " within the spatial extent of an associated <OBJECT>; ASW centroid"
    " present.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[181]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Wind and Residual Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ASW_WINGED_AIRCRAFT_TYPE,
    "ASW_WINGED_AIRCRAFT_TYPE", "EAC_ASW_WINGED_AIRCRAFT_TYPE",
    "The type of an <ASW_WINGED_AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[408]), 24, &(EDCS_Enumerant_Dictionary[564]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_BOUNDARY_LAYER_HEIGHT,
    "ATM_BOUNDARY_LAYER_HEIGHT", "EAC_ATM_BOUNDARY_LAYER_HEIGHT",
    "The <<HEIGHT_AGL>> of the lowest layer in the <ATMOSPHERE> in which"
    " meteorological conditions are affected significantly by the"
    " <PLANETARY_SURFACE> of the <EARTH>. The value is variable in time and"
    " space and ranges from tens of metres in strongly statically stable"
    " situations to several kilometres in convective conditions over"
    " <DESERT_REGION>s; the atmosphere boundary layer height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_CEILING,
    "ATM_CEILING", "EAC_ATM_CEILING",
    "Either the <<HEIGHT_AGL>> of the lowest <CLOUD> or obscuring phenomena"
    " layer aloft that covers half or more of the sky and is predominantly"
    " opaque or the vertical visibility into a surface-based obscuration;"
    " the atmosphere ceiling.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[445]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_CEILING_METHOD,
    "ATM_CEILING_METHOD", "EAC_ATM_CEILING_METHOD",
    "The method used to determine the <<ATM_CEILING>>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[442]), 11, &(EDCS_Enumerant_Dictionary[588]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"cloud height indicator\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_FREEZING_LEVEL,
    "ATM_FREEZING_LEVEL", "EAC_ATM_FREEZING_LEVEL",
    "The lowest <<ALTITUDE_MSL>> at which the <<AIR_TEMPERATURE>> is 273,15"
    " kelvin (zero degrees Celsius); the atmosphere freezing level.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"freezing level\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_LIQUID_WATER_MIXING_RATIO,
    "ATM_LIQUID_WATER_MIXING_RATIO", "EAC_ATM_LIQUID_WATER_MIXING_RATIO",
    "The ratio of the <<MASS>> of liquid <WATER> to the <<MASS>> of dry"
    " <AIR> in a unit <<VOLUME>> of <AIR>; the atmosphere liquid water"
    " mixing ratio.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"liquid water mixing ratio\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE,
    "ATM_PRESSURE", "EAC_ATM_PRESSURE",
    "The pressure exerted by an <ATMOSPHERE> on any <SURFACE> by virtue of"
    " its weight; the atmospheric pressure.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"atmospheric pressure\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_CHANGE,
    "ATM_PRESSURE_CHANGE", "EAC_ATM_PRESSURE_CHANGE",
    "The quantity of change in the <<ATM_PRESSURE>> over a measurement"
    " <<TIME_QUANTITY>>.",
    EDCS_AVT_REAL, EQC_PRESSURE_CHANGE_RATE,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO306, Volume 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_CHANGE_24_HOUR,
    "ATM_PRESSURE_CHANGE_24_HOUR", "EAC_ATM_PRESSURE_CHANGE_24_HOUR",
    "The absolute value of the <<ATM_PRESSURE_CHANGE>> over a twenty-four"
    " hour <<TIME_QUANTITY>>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO306, Volume 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_CHANGE_3_HOUR,
    "ATM_PRESSURE_CHANGE_3_HOUR", "EAC_ATM_PRESSURE_CHANGE_3_HOUR",
    "The absolute value of the <<ATM_PRESSURE_CHANGE>> over a three-hour"
    " <<TIME_QUANTITY>>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO306, Volume 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_CHANGE_QUALITY,
    "ATM_PRESSURE_CHANGE_QUALITY", "EAC_ATM_PRESSURE_CHANGE_QUALITY",
    "The quality of an <<ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY>>"
    " measurement.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 9, &(EDCS_Enumerant_Dictionary[599]),
    EDCS_REF_TYP_INFORMATIVE, "[QCMO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY,
    "ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY", "EAC_ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY",
    "The qualitative <<ATM_PRESSURE_CHANGE_3_HOUR>>; the atmospheric"
    " pressure change tendency category.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 9, &(EDCS_Enumerant_Dictionary[608]),
    EDCS_REF_TYP_INFORMATIVE, "[WMO306]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_MEAN_CLIM,
    "ATM_PRESSURE_MEAN_CLIM", "EAC_ATM_PRESSURE_MEAN_CLIM",
    "The mean of historical (climatology) <<ATM_PRESSURE>>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"ATMOSPHERIC-PRESSURE-CLIMATOLOGY mean pressure rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_MEAN_CLIM_STD_DEV,
    "ATM_PRESSURE_MEAN_CLIM_STD_DEV", "EAC_ATM_PRESSURE_MEAN_CLIM_STD_DEV",
    "The standard deviation of historical (climatology) <<ATM_PRESSURE>>"
    " measurements.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"ATMOSPHERIC-PRESSURE-OBSERVATION-LEVEL pressure quality"
    " code\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_QUALITY,
    "ATM_PRESSURE_QUALITY", "EAC_ATM_PRESSURE_QUALITY",
    "The quality of an <<ATM_PRESSURE>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 9, &(EDCS_Enumerant_Dictionary[617]),
    EDCS_REF_TYP_INFORMATIVE, "[QCMO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_REDUCED_CLIM_STD_DEV,
    "ATM_PRESSURE_REDUCED_CLIM_STD_DEV", "EAC_ATM_PRESSURE_REDUCED_CLIM_STD_DEV",
    "The standard deviation of historical (climatology)"
    " <<ATM_PRESSURE_REDUCED_MSL>> measurements.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "[GMET]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PRESSURE_REDUCED_MSL,
    "ATM_PRESSURE_REDUCED_MSL", "EAC_ATM_PRESSURE_REDUCED_MSL",
    "The <<ATM_PRESSURE>> reduced to MSL using standard procedures.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "[GMET]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_PROFILE_MEASUREMENT_TECHNIQUE,
    "ATM_PROFILE_MEASUREMENT_TECHNIQUE", "EAC_ATM_PROFILE_MEASUREMENT_TECHNIQUE",
    "The technique or method of collecting an <ATMOSPHERE_PROPERTY_SET>"
    " that is a series of measurements collected along a (roughly) vertical"
    " axis; the atmospheric profile measurement technique.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[468]), 7, &(EDCS_Enumerant_Dictionary[626]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_TURBULENCE_TYPE,
    "ATM_TURBULENCE_TYPE", "EAC_ATM_TURBULENCE_TYPE",
    "The type of turbulence in the <ATMOSPHERE> experienced by <AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[354]), 4, &(EDCS_Enumerant_Dictionary[633]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"aircraft turbulence\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATM_VERTICAL_REFERENCE,
    "ATM_VERTICAL_REFERENCE", "EAC_ATM_VERTICAL_REFERENCE",
    "The <SURFACE_DATUM> and accompanying method of reporting the vertical"
    " displacement to an <OBJECT> (for example: a level in an <ATMOSPHERE>)"
    " in an <ATMOSPHERE>; the atmosphere vertical reference.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[98]), 5, &(EDCS_Enumerant_Dictionary[637]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ICL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATS_ROUTE_COMPONENT_LENGTH,
    "ATS_ROUTE_COMPONENT_LENGTH", "EAC_ATS_ROUTE_COMPONENT_LENGTH",
    "The <<LENGTH>> of an <ATS_ROUTE_COMPONENT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[372]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ALN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATS_ROUTE_COMPONENT_LEVEL,
    "ATS_ROUTE_COMPONENT_LEVEL", "EAC_ATS_ROUTE_COMPONENT_LEVEL",
    "The flight level of an <ATS_ROUTE_COMPONENT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 7, &(EDCS_Enumerant_Dictionary[642]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ATL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATS_ROUTE_COMPONENT_WIDTH,
    "ATS_ROUTE_COMPONENT_WIDTH", "EAC_ATS_ROUTE_COMPONENT_WIDTH",
    "The <<WIDTH>> of an <ATS_ROUTE_COMPONENT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[372]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATS_ROUTE_LOWEST_ALTITUDE,
    "ATS_ROUTE_LOWEST_ALTITUDE", "EAC_ATS_ROUTE_LOWEST_ALTITUDE",
    "The lowest published altitude in effect along a <ATS_ROUTE_COMPONENT>"
    " that meets obstacle clearance requirements for the entire"
    " <ATS_ROUTE_COMPONENT> and that assures an acceptable navigation"
    " signal.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[357]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MOC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATS_ROUTE_OPPOSITE_FLOW_DIRECTION,
    "ATS_ROUTE_OPPOSITE_FLOW_DIRECTION", "EAC_ATS_ROUTE_OPPOSITE_FLOW_DIRECTION",
    "The <DIRECTION> opposite to the flow of an <ATS_ROUTE_COMPONENT>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[347]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ODF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATS_ROUTE_TYPE,
    "ATS_ROUTE_TYPE", "EAC_ATS_ROUTE_TYPE",
    "The type of an <ATS_ROUTE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 21, &(EDCS_Enumerant_Dictionary[649]),
    EDCS_REF_TYP_INFORMATIVE, "[IAN11]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATS_USE_TYPE,
    "ATS_USE_TYPE", "EAC_ATS_USE_TYPE",
    "The type of use of a designated ATS <AIRSPACE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[421]), 59, &(EDCS_Enumerant_Dictionary[670]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AUA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATTACHED,
    "ATTACHED", "EAC_ATTACHED",
    "An indication that an <OBJECT> is attached to another <OBJECT>.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"attach\", 5]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ATTACK_WINGED_AIRCRAFT_TYPE,
    "ATTACK_WINGED_AIRCRAFT_TYPE", "EAC_ATTACK_WINGED_AIRCRAFT_TYPE",
    "The type of an <ATTACK_WINGED_AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[408]), 18, &(EDCS_Enumerant_Dictionary[729]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AUXILIARY_VESSEL_TYPE,
    "AUXILIARY_VESSEL_TYPE", "EAC_AUXILIARY_VESSEL_TYPE",
    "The type of a <WATER_SURFACE_VESSEL> designed for auxiliary operations.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 11, &(EDCS_Enumerant_Dictionary[747]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AVAILABLE_FACILITIES_TYPE,
    "AVAILABLE_FACILITIES_TYPE", "EAC_AVAILABLE_FACILITIES_TYPE",
    "The type of <FACILITY>s available at, or in the near vicinity of, a"
    " <HARBOUR> or marina.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[50]), 39, &(EDCS_Enumerant_Dictionary[758]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AFA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AVERAGING_PERIOD,
    "AVERAGING_PERIOD", "EAC_AVERAGING_PERIOD",
    "The <<TIME_QUANTITY>> over which a measurement has been averaged; the"
    " averaging period.",
    EDCS_AVT_REAL, EQC_TIME,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AVERAGING_PERIOD_CATEGORY,
    "AVERAGING_PERIOD_CATEGORY", "EAC_AVERAGING_PERIOD_CATEGORY",
    "A category describing the <<AVERAGING_PERIOD>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 20, &(EDCS_Enumerant_Dictionary[797]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AVIATION_LOCATION_ID_VALUE_SET,
    "AVIATION_LOCATION_ID_VALUE_SET", "EAC_AVIATION_LOCATION_ID_VALUE_SET",
    "The value set of a formatted <<AVIATION_LOCATION_IDENTIFIER>>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[392]), 3, &(EDCS_Enumerant_Dictionary[817]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_AVIATION_LOCATION_IDENTIFIER,
    "AVIATION_LOCATION_IDENTIFIER", "EAC_AVIATION_LOCATION_IDENTIFIER",
    "An identifier of an aviation <LOCATION>. The format and values of the"
    " identifier are specified by an <<AVIATION_LOCATION_ID_VALUE_SET>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[392]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: IKO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BALCONY_TYPE,
    "BALCONY_TYPE", "EAC_BALCONY_TYPE",
    "The type, <LOCATION>, or purpose of a <BALCONY>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[707]), 4, &(EDCS_Enumerant_Dictionary[820]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BALEEN_WHALE_CATCH_PER_YEAR,
    "BALEEN_WHALE_CATCH_PER_YEAR", "EAC_BALEEN_WHALE_CATCH_PER_YEAR",
    "The number of baleen <WHALE>s caught within a one-year"
    " <<TIME_QUANTITY>>.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[569]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Wind and Residual Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BARGE_LOAD_RESTRICTIONS,
    "BARGE_LOAD_RESTRICTIONS", "EAC_BARGE_LOAD_RESTRICTIONS",
    "The description of any load restrictions that apply to barges using a"
    " <MARINE_ROUTE> or marine <FACILITY>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[1039]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BLC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BASEMENT_CONSTRUCTION_MATERIAL,
    "BASEMENT_CONSTRUCTION_MATERIAL", "EAC_BASEMENT_CONSTRUCTION_MATERIAL",
    "The <MATERIAL> used to construct a <BASEMENT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 4, &(EDCS_Enumerant_Dictionary[824]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEACH_PORTION,
    "BEACH_PORTION", "EAC_BEACH_PORTION",
    "The relative portion of a <BEACH>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[30]), 3, &(EDCS_Enumerant_Dictionary[828]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BIT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEACON_PRESENT,
    "BEACON_PRESENT", "EAC_BEACON_PRESENT",
    "An indication that an <OBJECT> has an associated <BEACON>.",
    EDCS_AVT_BOOLEAN, 0,
    3, &(EGBindingForEA[111]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEACON_SECTOR_FIRST_LIMIT,
    "BEACON_SECTOR_FIRST_LIMIT", "EAC_BEACON_SECTOR_FIRST_LIMIT",
    "The <<GEODETIC_AZIMUTH>> of the first limit of a sector of a <BEACON>"
    " or radio transponder <BEACON>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    5, &(EGBindingForEA[502]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SC1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEACON_SECTOR_SECOND_LIMIT,
    "BEACON_SECTOR_SECOND_LIMIT", "EAC_BEACON_SECTOR_SECOND_LIMIT",
    "The <<GEODETIC_AZIMUTH>> of the second limit of a sector of a <LIGHT>"
    " or radio transponder <BEACON>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    5, &(EGBindingForEA[502]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SC2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEARING_AND_RECIPROCAL,
    "BEARING_AND_RECIPROCAL", "EAC_BEARING_AND_RECIPROCAL",
    "The horizontal <DIRECTION> (for example: along a track and/or along a"
    " <ROUTE>) of one terrestrial <LOCATION> from another. Formatted in a"
    " Basic Latin string as the angular distance in arc degrees from a"
    " reference <DIRECTION> in 0,1 arc degree increments, followed by a"
    " hyphen, and the followed by the reciprocal bearing. EXAMPLE"
    " \"053,1-233,1\".",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[545]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRR]",
    "[BOWD]", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEARING_FROM_SEAWARD,
    "BEARING_FROM_SEAWARD", "EAC_BEARING_FROM_SEAWARD",
    "The <<GEODETIC_AZIMUTH>> of the true course of a <VESSEL> when"
    " proceeding from seaward.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[539]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEAUFORT_WIND_SCALE,
    "BEAUFORT_WIND_SCALE", "EAC_BEAUFORT_WIND_SCALE",
    "The force of a <WIND> on the Beaufort scale (originally based on the"
    " associated state of a <WATERBODY_SURFACE>).",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 13, &(EDCS_Enumerant_Dictionary[831]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"Beaufort scale\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEDROCK_SURFACE_COMPRESSIONAL_VELOCITY,
    "BEDROCK_SURFACE_COMPRESSIONAL_VELOCITY", "EAC_BEDROCK_SURFACE_COMPRESSIONAL_VELOCITY",
    "The <<VELOCITY>> of displacement of <BEDROCK> in the same <DIRECTION>"
    " as a compressional (density) wave in the top ten metres of that"
    " <BEDROCK>; the bedrock surface compressional velocity.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEDROCK_SURFACE_DENSITY,
    "BEDROCK_SURFACE_DENSITY", "EAC_BEDROCK_SURFACE_DENSITY",
    "The mean density of the top ten metres of <BEDROCK>; the bedrock"
    " surface density.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BEDROCK_SURFACE_SHEAR_VELOCITY,
    "BEDROCK_SURFACE_SHEAR_VELOCITY", "EAC_BEDROCK_SURFACE_SHEAR_VELOCITY",
    "The <<VELOCITY>> of displacement of <BEDROCK> in a <DIRECTION> that is"
    " perpendicular to a compressional (density) wave in the top ten metres"
    " of that <BEDROCK>; the bedrock surface shear velocity.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BELOW_STATION_CLOUD_COVERAGE,
    "BELOW_STATION_CLOUD_COVERAGE", "EAC_BELOW_STATION_CLOUD_COVERAGE",
    "Cloud coverage of the sky below an <OBSERVATION_STATION> located in"
    " the <MOUNTAIN>s on <EARTH>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 15, &(EDCS_Enumerant_Dictionary[844]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.7.7]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BELOW_STATION_CLOUD_TOP_ALTITUDE,
    "BELOW_STATION_CLOUD_TOP_ALTITUDE", "EAC_BELOW_STATION_CLOUD_TOP_ALTITUDE",
    "The highest <SURFACE> of a <CLOUD_TOP> or a <CLOUD_LAYER> relative to"
    " an <<ATM_VERTICAL_REFERENCE>> below an <OBSERVATION_STATION> located"
    " in the <MOUNTAIN>s on <EARTH>; the below station cloud top altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Sections II.7.4 and II.7.7]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BELOW_STATION_CLOUD_TOP_CHARACTERISTICS,
    "BELOW_STATION_CLOUD_TOP_CHARACTERISTICS", "EAC_BELOW_STATION_CLOUD_TOP_CHARACTERISTICS",
    "The characteristics of the <CLOUD_TOP> or a <CLOUD_LAYER> below an"
    " <OBSERVATION_STATION> located in the <MOUNTAIN>s on <EARTH>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 11, &(EDCS_Enumerant_Dictionary[859]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.7.7]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BELOW_STATION_CLOUD_TYPE,
    "BELOW_STATION_CLOUD_TYPE", "EAC_BELOW_STATION_CLOUD_TYPE",
    "The type of <CLOUD>s that comprise a <CLOUD_LAYER> below an"
    " <OBSERVATION_STATION> located in the <MOUNTAIN>s on <EARTH>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 12, &(EDCS_Enumerant_Dictionary[870]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.7.7]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BENCHMARK_TYPE,
    "BENCHMARK_TYPE", "EAC_BENCHMARK_TYPE",
    "The type of a <BENCHMARK>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[46]), 2, &(EDCS_Enumerant_Dictionary[882]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TY3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BERTH_IDENTIFIER,
    "BERTH_IDENTIFIER", "EAC_BERTH_IDENTIFIER",
    "The textual identifier of a <VESSEL_BERTH>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[1013]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BER]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BERTH_TYPE,
    "BERTH_TYPE", "EAC_BERTH_TYPE",
    "The type of decked marine <STRUCTURE> at a <VESSEL_BERTH>. The type is"
    " based on configuration and structure.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[974]), 3, &(EDCS_Enumerant_Dictionary[884]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PWC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BIDIRECTIONAL,
    "BIDIRECTIONAL", "EAC_BIDIRECTIONAL",
    "An indication that an <OBJECT> supports bidirectional flow.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: BDS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION,
    "BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION", "EAC_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION",
    "The ratio, for a particular material <SURFACE>, of the differential"
    " reflected <<RADIANCE>> into a unit solid angle about a particular"
    " (reflected) <DIRECTION> to the differential incident flux per unit"
    " surface <<AREA>> (irradiance) from a particular (incident)"
    " <DIRECTION>; bi-directional reflectance distribution function or"
    " directional-directional reflectance. This quantity is a function of"
    " the <<INCIDENCE_ZENITH_ANGLE_LOCAL>>, <<INCIDENCE_AZIMUTH_LOCAL>>,"
    " <<REFLECTANCE_ZENITH_ANGLE_LOCAL>>, and"
    " <<REFLECTANCE_AZIMUTH_LOCAL>>. This quantity is spectral (a"
    " distribution function in <<WAVELENGTH>>) and is measured in terms of"
    " inverse solid angle and inverse <<WAVELENGTH>> bin size.",
    EDCS_AVT_REAL, EQC_SPECTRAL_RECIPROCAL_SOLID_ANGLE,
    4, &(EGBindingForEA[481]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BIOLOGIC_AGENT_ATM_CONCENTRATION,
    "BIOLOGIC_AGENT_ATM_CONCENTRATION", "EAC_BIOLOGIC_AGENT_ATM_CONCENTRATION",
    "The concentration of a biologic agent suspended in an <ATMOSPHERE>.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    3, &(EGBindingForEA[657]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BIOLOGIC_AGENT_SURFACE_CONCENTRATION,
    "BIOLOGIC_AGENT_SURFACE_CONCENTRATION", "EAC_BIOLOGIC_AGENT_SURFACE_CONCENTRATION",
    "The concentration of a biologic agent contained in a layer on the"
    " <SURFACE> of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    3, &(EGBindingForEA[1231]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BIOLOGIC_AGENT_TYPE,
    "BIOLOGIC_AGENT_TYPE", "EAC_BIOLOGIC_AGENT_TYPE",
    "The type of a biologic agent that can kill, seriously injure, or"
    " incapacitate <HUMAN>s or <NON_HUMAN_ANIMAL>s through its"
    " physiological properties.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[31]), 96, &(EDCS_Enumerant_Dictionary[887]),
    EDCS_REF_TYP_INFORMATIVE, "[MCBA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BLACKOUT_BRAKE_LIGHT_INTENSITY,
    "BLACKOUT_BRAKE_LIGHT_INTENSITY", "EAC_BLACKOUT_BRAKE_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of external <LIGHTING> that is designed for use"
    " under military blackout conditions to prevent collision with/between"
    " <VEHICLE>s; the blackout brake light intensity. Zero means unlit and"
    " one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    6, &(EGBindingForEA[879]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 26 (Blackout Brake)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BLACKOUT_LIGHT_INTENSITY,
    "BLACKOUT_LIGHT_INTENSITY", "EAC_BLACKOUT_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of internal <LIGHTING> that is designed for use"
    " under military blackout conditions. Zero means unlit and one means"
    " maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[875]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 26 (Blackout)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BLOWING_SAND,
    "BLOWING_SAND", "EAC_BLOWING_SAND",
    "An indication that blowing <SAND> is present.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[427]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO306, Part B]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BLOWING_SNOW,
    "BLOWING_SNOW", "EAC_BLOWING_SNOW",
    "An indication that blowing <SNOW_PRECIPITATION> is present.",
    EDCS_AVT_BOOLEAN, 0,
    3, &(EGBindingForEA[435]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO306, Part B]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOMBER_WINGED_AIRCRAFT_TYPE,
    "BOMBER_WINGED_AIRCRAFT_TYPE", "EAC_BOMBER_WINGED_AIRCRAFT_TYPE",
    "The type of a <BOMBER_WINGED_AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[408]), 8, &(EDCS_Enumerant_Dictionary[983]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_RETURN_ALLEGIANCE,
    "BOTTOM_RETURN_ALLEGIANCE", "EAC_BOTTOM_RETURN_ALLEGIANCE",
    "The military allegiance of an <OBJECT> identified by a"
    " <WATERBODY_FLOOR_SONAR_RETURN>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[66]), 3, &(EDCS_Enumerant_Dictionary[991]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_RETURN_OBSTACLE_STATUS,
    "BOTTOM_RETURN_OBSTACLE_STATUS", "EAC_BOTTOM_RETURN_OBSTACLE_STATUS",
    "The status of a <WATERBODY_FLOOR_SONAR_RETURN> indicating the presence"
    " of obstacles.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[302]), 3, &(EDCS_Enumerant_Dictionary[994]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_RETURN_ROCK_STATUS,
    "BOTTOM_RETURN_ROCK_STATUS", "EAC_BOTTOM_RETURN_ROCK_STATUS",
    "The status of a <WATERBODY_FLOOR_SONAR_RETURN> indicating the presence"
    " of a <ROCK>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[302]), 3, &(EDCS_Enumerant_Dictionary[997]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BCR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_RETURN_SEABED_STATUS,
    "BOTTOM_RETURN_SEABED_STATUS", "EAC_BOTTOM_RETURN_SEABED_STATUS",
    "The status of a <WATERBODY_FLOOR_SONAR_RETURN> indicating the presence"
    " of installations on the <OCEAN_FLOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[236]), 3, &(EDCS_Enumerant_Dictionary[1000]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BSR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_RETURN_STATUS,
    "BOTTOM_RETURN_STATUS", "EAC_BOTTOM_RETURN_STATUS",
    "The status of a <WATERBODY_FLOOR_SONAR_RETURN>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[302]), 3, &(EDCS_Enumerant_Dictionary[1003]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_RETURN_TRACK_IDENTIFIER,
    "BOTTOM_RETURN_TRACK_IDENTIFIER", "EAC_BOTTOM_RETURN_TRACK_IDENTIFIER",
    "The numeric identifier of a <WATERBODY_FLOOR_SONAR_RETURN>; the bottom"
    " return track identifier.",
    EDCS_AVT_INDEX, 0,
    3, &(EGBindingForEA[271]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_RETURN_TYPE,
    "BOTTOM_RETURN_TYPE", "EAC_BOTTOM_RETURN_TYPE",
    "The type of a <WATERBODY_FLOOR_SONAR_RETURN>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[302]), 5, &(EDCS_Enumerant_Dictionary[1006]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_RETURN_WRECK_STATUS,
    "BOTTOM_RETURN_WRECK_STATUS", "EAC_BOTTOM_RETURN_WRECK_STATUS",
    "The status of a <WATERBODY_FLOOR_SONAR_RETURN> indicating a"
    " <MARINE_WRECK>.",
    EDCS_AVT_ENUMERATION, 0,
    5, &(EGBindingForEA[258]), 3, &(EDCS_Enumerant_Dictionary[1011]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRW]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOTTOM_WIDTH,
    "BOTTOM_WIDTH", "EAC_BOTTOM_WIDTH",
    "The <<WIDTH>> of an <OBJECT> at its bottom.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WD6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOUNDARY_FIRST_SIDE_NAME,
    "BOUNDARY_FIRST_SIDE_NAME", "EAC_BOUNDARY_FIRST_SIDE_NAME",
    "The name of the political entity on the first side of a <BOUNDARY>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[312]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NM3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOUNDARY_SECOND_SIDE_NAME,
    "BOUNDARY_SECOND_SIDE_NAME", "EAC_BOUNDARY_SECOND_SIDE_NAME",
    "The name of the political entity on the second side of a <BOUNDARY>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[312]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NM4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOUNDARY_STATUS,
    "BOUNDARY_STATUS", "EAC_BOUNDARY_STATUS",
    "The status of a <BOUNDARY>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[13]), 6, &(EDCS_Enumerant_Dictionary[1014]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BST]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BOUNDARY_TYPE,
    "BOUNDARY_TYPE", "EAC_BOUNDARY_TYPE",
    "The type of a <BOUNDARY>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[13]), 39, &(EDCS_Enumerant_Dictionary[1020]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRANCH_RAILWAY_TYPE,
    "BRANCH_RAILWAY_TYPE", "EAC_BRANCH_RAILWAY_TYPE",
    "The function or configuration of a branch <RAILWAY>; the branch"
    " railway type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 4, &(EDCS_Enumerant_Dictionary[1059]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RSA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BREAKER_FLANK,
    "BREAKER_FLANK", "EAC_BREAKER_FLANK",
    "The flank towards which the breaking <WATER_WAVE>s are moving in a"
    " <SURF_ZONE> as seen from <VESSEL>s approaching the <BEACH>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1045]), 2, &(EDCS_Enumerant_Dictionary[1063]),
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4, \"breaker angle\"]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_AND_SPAN_IDENTIFIER,
    "BRIDGE_AND_SPAN_IDENTIFIER", "EAC_BRIDGE_AND_SPAN_IDENTIFIER",
    "The textual identifier (often termed the \"number\") of a <BRIDGE> and"
    " its <BRIDGE_SPAN>s.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[1101]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_COMPONENT_TYPE,
    "BRIDGE_COMPONENT_TYPE", "EAC_BRIDGE_COMPONENT_TYPE",
    "The type of structural <COMPONENT> of a <BRIDGE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 5, &(EDCS_Enumerant_Dictionary[1065]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_DESIGN,
    "BRIDGE_DESIGN", "EAC_BRIDGE_DESIGN",
    "The structural design characteristics of a <BRIDGE> or <BRIDGE_SPAN>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 23, &(EDCS_Enumerant_Dictionary[1070]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BDC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_FUNCTION,
    "BRIDGE_FUNCTION", "EAC_BRIDGE_FUNCTION",
    "The type of <TERRAIN_OBSTACLE> that is spanned by a <BRIDGE>; the"
    " bridge function.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 13, &(EDCS_Enumerant_Dictionary[1093]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_IDENTIFIER,
    "BRIDGE_IDENTIFIER", "EAC_BRIDGE_IDENTIFIER",
    "The textual identifier (often termed the \"number\") of a <BRIDGE>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[1101]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BSN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_INFORMATION_RELIABILITY,
    "BRIDGE_INFORMATION_RELIABILITY", "EAC_BRIDGE_INFORMATION_RELIABILITY",
    "The reliability of characteristic and load classification information"
    " for a <BRIDGE> based upon the data source.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 2, &(EDCS_Enumerant_Dictionary[1106]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RBC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_LEVEL_COUNT,
    "BRIDGE_LEVEL_COUNT", "EAC_BRIDGE_LEVEL_COUNT",
    "The number of levels of a <BRIDGE> that carries <GROUND_VEHICLE>s"
    " and/or <HUMAN>s; the bridge level count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_OPENING_TYPE,
    "BRIDGE_OPENING_TYPE", "EAC_BRIDGE_OPENING_TYPE",
    "The type of movement by which a <BRIDGE_SPAN> allows passage of a"
    " <VESSEL>; the bridge opening type.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1016]), 4, &(EDCS_Enumerant_Dictionary[1108]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BOT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_SPAN_COUNT,
    "BRIDGE_SPAN_COUNT", "EAC_BRIDGE_SPAN_COUNT",
    "The number of spans in a <BRIDGE> or <AQUEDUCT>; the bridge span count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NOS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_SPAN_MOBILE,
    "BRIDGE_SPAN_MOBILE", "EAC_BRIDGE_SPAN_MOBILE",
    "An indication that a <BRIDGE_SPAN> moves in some manner to allow"
    " passage underneath.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_SPAN_TYPE,
    "BRIDGE_SPAN_TYPE", "EAC_BRIDGE_SPAN_TYPE",
    "The type of a moveable <BRIDGE_SPAN>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 18, &(EDCS_Enumerant_Dictionary[1112]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BSP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRIDGE_STRUCTURE_TYPE,
    "BRIDGE_STRUCTURE_TYPE", "EAC_BRIDGE_STRUCTURE_TYPE",
    "The type of structural design of a <BRIDGE> or <BRIDGE_SPAN>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 27, &(EDCS_Enumerant_Dictionary[1130]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BRUSH_DENSITY,
    "BRUSH_DENSITY", "EAC_BRUSH_DENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of <LAND> covered by undergrowth (for example: scrub, brush,"
    " and/or bush); the brush density. Zero means no undergrowth and one"
    " means completely covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[1209]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DMB and BUD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BUDDHISM_DENOMINATIONAL_FAMILY,
    "BUDDHISM_DENOMINATIONAL_FAMILY", "EAC_BUDDHISM_DENOMINATIONAL_FAMILY",
    "The designation of a <NON_EMPTY_SET> of closely related Buddhist"
    " religious denominations, often ones which were at one time part of a"
    " single movement but are now separate religious denominations; the"
    " Buddhist denominational family.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 5, &(EDCS_Enumerant_Dictionary[1157]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BUILDING_COMPONENT_TYPE,
    "BUILDING_COMPONENT_TYPE", "EAC_BUILDING_COMPONENT_TYPE",
    "The type of a <BUILDING_COMPONENT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 41, &(EDCS_Enumerant_Dictionary[1162]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BUILDING_CONSTRUCTION_TYPE,
    "BUILDING_CONSTRUCTION_TYPE", "EAC_BUILDING_CONSTRUCTION_TYPE",
    "The type of technique used to construct a <BUILDING>. The basic"
    " techniques are mass (where the walls carry the load) and framed"
    " (where an internal frame carries the load and walls simply protect"
    " the interior from the elements).",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[41]), 27, &(EDCS_Enumerant_Dictionary[1203]),
    EDCS_REF_TYP_INFORMATIVE, "[UTZB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BUILDING_FOUNDATION_TYPE,
    "BUILDING_FOUNDATION_TYPE", "EAC_BUILDING_FOUNDATION_TYPE",
    "The type of <MATERIAL> and/or techniques used to construct the"
    " foundation of a <BUILDING>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 8, &(EDCS_Enumerant_Dictionary[1230]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BUILDING_FUNCTION,
    "BUILDING_FUNCTION", "EAC_BUILDING_FUNCTION",
    "The function of a <BUILDING>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[41]), 194, &(EDCS_Enumerant_Dictionary[1238]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BFC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BUILT_UP_REGION_DENSITY,
    "BUILT_UP_REGION_DENSITY", "EAC_BUILT_UP_REGION_DENSITY",
    "The relative density of a <BUILT_UP_REGION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1333]), 3, &(EDCS_Enumerant_Dictionary[1432]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BUOY_SHAPE,
    "BUOY_SHAPE", "EAC_BUOY_SHAPE",
    "The shape of a <BUOY>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[977]), 8, &(EDCS_Enumerant_Dictionary[1435]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: BOYSHP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BUOY_TYPE,
    "BUOY_TYPE", "EAC_BUOY_TYPE",
    "The type of a <BUOY>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[977]), 101, &(EDCS_Enumerant_Dictionary[1443]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BUT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BYPASS_CONDITION,
    "BYPASS_CONDITION", "EAC_BYPASS_CONDITION",
    "The degree of ease or ability to circumvent a destroyed section of"
    " <BRIDGE>, <TUNNEL>, or <MOUNTAIN_PASS> within a 2 kilometre distance"
    " on each side of the <OBJECT> (ignoring the presence of other similar"
    " <OBJECT>s); the bypass condition.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 3, &(EDCS_Enumerant_Dictionary[1544]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BCC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CABLE_TYPE,
    "CABLE_TYPE", "EAC_CABLE_TYPE",
    "The type of a cable.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[861]), 7, &(EDCS_Enumerant_Dictionary[1547]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CAB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CALENDAR_DATE,
    "CALENDAR_DATE", "EAC_CALENDAR_DATE",
    "The calendar date; formatted as specified by <<DATE_FORMAT>> or by"
    " <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CDV]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CALM_SEA_STATE_FRACTION,
    "CALM_SEA_STATE_FRACTION", "EAC_CALM_SEA_STATE_FRACTION",
    "A number between 0 and 1 inclusive representing the total fraction of"
    " reports on the state of a <<SEA_STATE_CATEGORY>> indicating calm sea"
    " state (whether glassy or rippled) during the reporting"
    " <<TIME_PERIOD>>. Zero means no reports indicated calm and one means"
    " all reports indicated calm.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1072]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CAMOUFLAGE_TYPE,
    "CAMOUFLAGE_TYPE", "EAC_CAMOUFLAGE_TYPE",
    "The <MATERIAL> and/or technique used to camouflage an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[169]), 11, &(EDCS_Enumerant_Dictionary[1554]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CAPACITY,
    "CAPACITY", "EAC_CAPACITY",
    "The capacity of an <OBJECT> formatted in a Basic Latin string. The"
    " string contains a number, followed by a unit enclosed in parenthesis"
    " (\"( )\"), followed by a unit qualifier enclosed in square brackets"
    " (\"[ ]\"). EXAMPLE \"100(cars)[per hour]\".",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CAP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CASE_BURIAL_FRACTION,
    "CASE_BURIAL_FRACTION", "EAC_CASE_BURIAL_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the case of an <EQUIPMENT> that is buried beneath the"
    " <TERRAIN>. Zero means not buried at all and one means completely"
    " buried.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[785]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CEILING_AND_VISIBILITY_OK,
    "CEILING_AND_VISIBILITY_OK", "EAC_CEILING_AND_VISIBILITY_OK",
    "An indication that CAVOK conditions prevail. The indication is TRUE"
    " if: (1) visibility is 10 kilometres or more; (2) there are no"
    " <CLOUD>s below 1,5 kilometres or below the highest minimum sector"
    " altitude, whichever is greater; and (3) there are no cumulonimbus"
    " <CLOUD>s, <PRECIPITATION>, <THUNDERSTORM>s, shallow <FOG>, or low"
    " drifting <SNOW_GROUND_COVER> present; ceiling and visibility OK.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[651]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, V1.1, Part A, 15.10]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CENTRE_FREQUENCY_BAND,
    "CENTRE_FREQUENCY_BAND", "EAC_CENTRE_FREQUENCY_BAND",
    "The centre <<FREQUENCY>> of a frequency band for which acoustic data"
    " were measured.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    1, &(EGBindingForEA[1]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"ACOUSTIC-PROPAGATION-MEASUREMENT center frequency rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CHANGE_POINT_TYPE,
    "CHANGE_POINT_TYPE", "EAC_CHANGE_POINT_TYPE",
    "The type of an <OBJECT> or phenomenon associated with a <CHANGE_POINT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 7, &(EDCS_Enumerant_Dictionary[1565]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PCI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CHARACTER_EMITTED,
    "CHARACTER_EMITTED", "EAC_CHARACTER_EMITTED",
    "The single character that is being emitted by a signalling <DEVICE>"
    " (for example: a <LIGHT>, a <BEACON>, and/or a communications"
    " transmitter).",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[729]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MCA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CHARGED_PARTICLE_SPECIES,
    "CHARGED_PARTICLE_SPECIES", "EAC_CHARGED_PARTICLE_SPECIES",
    "The species of a charged <PARTICLE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[16]), 5, &(EDCS_Enumerant_Dictionary[1572]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CHEMICAL_AGENT_ATM_CONCENTRATION,
    "CHEMICAL_AGENT_ATM_CONCENTRATION", "EAC_CHEMICAL_AGENT_ATM_CONCENTRATION",
    "The concentration of a chemical agent suspended in an <ATMOSPHERE>.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CHEMICAL_AGENT_SURFACE_CONCENTRATION,
    "CHEMICAL_AGENT_SURFACE_CONCENTRATION", "EAC_CHEMICAL_AGENT_SURFACE_CONCENTRATION",
    "The concentration of a chemical agent contained in a layer on the"
    " <SURFACE> of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    3, &(EGBindingForEA[1316]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CHEMICAL_AGENT_TYPE,
    "CHEMICAL_AGENT_TYPE", "EAC_CHEMICAL_AGENT_TYPE",
    "The type of a chemical agent that can kill, seriously injure, or"
    " incapacitate <HUMAN>s or <NON_HUMAN_ANIMAL>s through its"
    " physiological properties.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[33]), 45, &(EDCS_Enumerant_Dictionary[1577]),
    EDCS_REF_TYP_INFORMATIVE, "[MCBA]",
    "[EMED]", EDCS_CONCEPT_STAT_ISO },

    {EAC_CHRISTIANITY_DENOMINATIONAL_FAMILY,
    "CHRISTIANITY_DENOMINATIONAL_FAMILY", "EAC_CHRISTIANITY_DENOMINATIONAL_FAMILY",
    "The designation of a <NON_EMPTY_SET> of closely related Christian"
    " religious denominations, often ones which were at one time part of a"
    " single movement but are now separate religious denominations; the"
    " Christianity denominational family.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 19, &(EDCS_Enumerant_Dictionary[1622]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLASSIFICATION_NAME,
    "CLASSIFICATION_NAME", "EAC_CLASSIFICATION_NAME",
    "A character string representing an <OBJECT>; the classification name."
    " EXAMPLES Grammalogue, index number, order number, classification"
    " number.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[157]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NA3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLAY_DRAINAGE_PIPES_PRESENT,
    "CLAY_DRAINAGE_PIPES_PRESENT", "EAC_CLAY_DRAINAGE_PIPES_PRESENT",
    "An indication that underground clay drainage <PIPE>s are present,"
    " usually in agricultural <REGION>s.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[321]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_BASE_LEVEL,
    "CLOUD_BASE_LEVEL", "EAC_CLOUD_BASE_LEVEL",
    "The vertical displacement of a <CLOUD_BASE> from a <SURFACE_DATUM>"
    " identified by an <<ATM_VERTICAL_REFERENCE>>; the cloud base level.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO407]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_FREE_LINE_OF_SIGHT,
    "CLOUD_FREE_LINE_OF_SIGHT", "EAC_CLOUD_FREE_LINE_OF_SIGHT",
    "The fraction of all lines of sight that are unhampered by <CLOUD>s.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[449]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cloud-free line of sight]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_LIQUID_WATER_CONTENT,
    "CLOUD_LIQUID_WATER_CONTENT", "EAC_CLOUD_LIQUID_WATER_CONTENT",
    "The liquid <WATER> content of a unit <<VOLUME>> of a <CLOUD>.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[PRUP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_PHASE,
    "CLOUD_PHASE", "EAC_CLOUD_PHASE",
    "The phase (liquid/solid disposition) of the water content of a <CLOUD>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 3, &(EDCS_Enumerant_Dictionary[1641]),
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SKY-COVER-LAYER cloud type code\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_SKY_COVER_LAYER_TYPE,
    "CLOUD_SKY_COVER_LAYER_TYPE", "EAC_CLOUD_SKY_COVER_LAYER_TYPE",
    "The type of <CLOUD> that comprises a sky cover layer.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 11, &(EDCS_Enumerant_Dictionary[1644]),
    EDCS_REF_TYP_INFORMATIVE, "[WMO306, Part A, Symbol C, note (1), page I.1-B-6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_THICKNESS,
    "CLOUD_THICKNESS", "EAC_CLOUD_THICKNESS",
    "The vertical distance between a <CLOUD_BASE> and the corresponding"
    " <CLOUD_TOP>; the cloud thickness.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[432]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_TOP_LEVEL,
    "CLOUD_TOP_LEVEL", "EAC_CLOUD_TOP_LEVEL",
    "The vertical displacement of a <CLOUD_TOP> from a <SURFACE_DATUM>"
    " identified by an <<ATM_VERTICAL_REFERENCE>>; the cloud top level.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO407]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_TOP_TEMPERATURE,
    "CLOUD_TOP_TEMPERATURE", "EAC_CLOUD_TOP_TEMPERATURE",
    "The <<TEMPERATURE>> of a <CLOUD_TOP> or of the <AIR> near that level.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[459]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cloud top temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CLOUD_WATER_MIXING_RATIO,
    "CLOUD_WATER_MIXING_RATIO", "EAC_CLOUD_WATER_MIXING_RATIO",
    "The ratio of the <<MASS>> of the liquid <WATER> to the <<MASS>> of dry"
    " <AIR> in a <CLOUD>; the cloud water mixing ratio.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COLOUR_INTENSITY,
    "COLOUR_INTENSITY", "EAC_COLOUR_INTENSITY",
    "The intensity of colour of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[11]), 2, &(EDCS_Enumerant_Dictionary[1655]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CIC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COLOURATION,
    "COLOURATION", "EAC_COLOURATION",
    "The apparent colouration of an <OBJECT> when viewed in daylight; where"
    " more than a single colour is present, no specific pattern or"
    " regularity of distribution or colour predominance is presumed.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[101]), 84, &(EDCS_Enumerant_Dictionary[1657]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CCC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COLOURATION_INFORMATION,
    "COLOURATION_INFORMATION", "EAC_COLOURATION_INFORMATION",
    "The textual description of unique aspects of the colouration of an"
    " <OBJECT>; colouration information.",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[11]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CCR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COMBAT_SUPPORT_VESSEL_FUNCTION,
    "COMBAT_SUPPORT_VESSEL_FUNCTION", "EAC_COMBAT_SUPPORT_VESSEL_FUNCTION",
    "The operating function of a <COMBAT_SUPPORT_VESSEL>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[1022]), 7, &(EDCS_Enumerant_Dictionary[1741]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COMBATANT_VESSEL_TYPE,
    "COMBATANT_VESSEL_TYPE", "EAC_COMBATANT_VESSEL_TYPE",
    "The type of a <COMBATANT_VESSEL>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[1022]), 8, &(EDCS_Enumerant_Dictionary[1748]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COMBUSTION_INDUCED_FLAME_RATE,
    "COMBUSTION_INDUCED_FLAME_RATE", "EAC_COMBUSTION_INDUCED_FLAME_RATE",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the production rate of visible flame induced by"
    " combustion in an <OBJECT>. Zero means no production at all and one"
    " means maximum production.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 15 (Flaming)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COMBUSTION_STATE,
    "COMBUSTION_STATE", "EAC_COMBUSTION_STATE",
    "The state of combustion of an <OBJECT> and/or its contents.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 5, &(EDCS_Enumerant_Dictionary[1756]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COMMERCIAL_WINGED_AIRCRAFT_TYPE,
    "COMMERCIAL_WINGED_AIRCRAFT_TYPE", "EAC_COMMERCIAL_WINGED_AIRCRAFT_TYPE",
    "The type or design series of a <COMMERCIAL_WINGED_AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[424]), 18, &(EDCS_Enumerant_Dictionary[1761]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COMMUNICATION_CHANNEL,
    "COMMUNICATION_CHANNEL", "EAC_COMMUNICATION_CHANNEL",
    "The communication channel assigned by a controlling authority, often"
    " described by a <<FREQUENCY>>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[309]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CHL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COMMUNICATION_STRUCTURE_TYPE,
    "COMMUNICATION_STRUCTURE_TYPE", "EAC_COMMUNICATION_STRUCTURE_TYPE",
    "The type of a communications <STRUCTURE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[755]), 13, &(EDCS_Enumerant_Dictionary[1779]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COMPLEX_COMPONENT_IDENTIFIER,
    "COMPLEX_COMPONENT_IDENTIFIER", "EAC_COMPLEX_COMPONENT_IDENTIFIER",
    "The numeric identifier of an <OBJECT> that either consists of"
    " <COMPONENT>s or is itself a <COMPONENT> of another <OBJECT>; complex"
    " component identifier. Such an identifier is used for relating"
    " <OBJECT>s to each other.",
    EDCS_AVT_INDEX, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONCEALMENT_FRACTION,
    "CONCEALMENT_FRACTION", "EAC_CONCEALMENT_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of complete concealment of an <OBJECT>. Zero means"
    " unconcealed and one means completely concealed.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 19 (Concealed)]",
    "[EBEV, Sec. 4.3.3, Bit: 33 (Concealed Stationary)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONSPICUOUSNESS,
    "CONSPICUOUSNESS", "EAC_CONSPICUOUSNESS",
    "The type of conspicuousness of an <OBJECT>. Conspicuous means the"
    " <OBJECT> is easily identifiable and plainly visible under varying"
    " conditions from <HARBOUR>s, approach <WATER_CHANNEL>s, or offshore"
    " because of its size, shape, <<HEIGHT_ABOVE_SURFACE_LEVEL>>, colour,"
    " or composition.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[145]), 10, &(EDCS_Enumerant_Dictionary[1792]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: COC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONSTRUCTION_COMPLETION_FRACTION,
    "CONSTRUCTION_COMPLETION_FRACTION", "EAC_CONSTRUCTION_COMPLETION_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of construction completion of a <MAN_MADE_OBJECT>. Zero"
    " means construction has not yet begun and one means construction is"
    " complete.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONTOUR_TYPE,
    "CONTOUR_TYPE", "EAC_CONTOUR_TYPE",
    "The type of a <CONTOUR>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[32]), 3, &(EDCS_Enumerant_Dictionary[1802]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: COT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONTRAIL_LAYER_BASE_ALTITUDE,
    "CONTRAIL_LAYER_BASE_ALTITUDE", "EAC_CONTRAIL_LAYER_BASE_ALTITUDE",
    "The <<ALTITUDE_MSL>> of the bottom of a layer in an <ATMOSPHERE> where"
    " contrail formation is probable.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONTRAIL_LAYER_TOP_ALTITUDE,
    "CONTRAIL_LAYER_TOP_ALTITUDE", "EAC_CONTRAIL_LAYER_TOP_ALTITUDE",
    "The <<ALTITUDE_MSL>> of the top of a layer in an <ATMOSPHERE> where"
    " contrail formation is probable.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONTRAIL_PERSISTENCE,
    "CONTRAIL_PERSISTENCE", "EAC_CONTRAIL_PERSISTENCE",
    "The persistence status of a contrail.",
    EDCS_AVT_ENUMERATION, 0,
    5, &(EGBindingForEA[329]), 3, &(EDCS_Enumerant_Dictionary[1805]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONTROL_PANEL_STATE,
    "CONTROL_PANEL_STATE", "EAC_CONTROL_PANEL_STATE",
    "The state of a <CONTROL_PANEL>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[14]), 3, &(EDCS_Enumerant_Dictionary[1808]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONTROL_PANEL_TYPE,
    "CONTROL_PANEL_TYPE", "EAC_CONTROL_PANEL_TYPE",
    "The kind of <EQUIPMENT> controlled by a <CONTROL_PANEL>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[14]), 4, &(EDCS_Enumerant_Dictionary[1811]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONTROLLED,
    "CONTROLLED", "EAC_CONTROLLED",
    "An indication that a <FACILITY> is controlled.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: CNS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONTROLLING_AUTHORITY,
    "CONTROLLING_AUTHORITY", "EAC_CONTROLLING_AUTHORITY",
    "The level or type of an organization or authority responsible for an"
    " <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 16, &(EDCS_Enumerant_Dictionary[1815]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: CAA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONVECTION_COEFFICIENT,
    "CONVECTION_COEFFICIENT", "EAC_CONVECTION_COEFFICIENT",
    "The ratio of convective heat flux density through a surface <BOUNDARY>"
    " to the gradient of <<TEMPERATURE>> across that <BOUNDARY>; the"
    " convection coefficient.",
    EDCS_AVT_REAL, EQC_COEFFICIENT_HEAT_TRANSFER,
    3, &(EGBindingForEA[771]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"convection coefficient\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONVECTIVE_CLOUD_LAYER,
    "CONVECTIVE_CLOUD_LAYER", "EAC_CONVECTIVE_CLOUD_LAYER",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the sky that is covered by convective (cumuliform)"
    " <CLOUD>s. Zero means no convective <CLOUD>s are present and one means"
    " the sky is completely covered by convective <CLOUD>s.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CONVECTIVE_PRECIPITATION_DENSITY,
    "CONVECTIVE_PRECIPITATION_DENSITY", "EAC_CONVECTIVE_PRECIPITATION_DENSITY",
    "The component of <<ACCUM_PRECIP_DENSITY>> caused by convective"
    " <PRECIPITATION>. Convective <PRECIPITATION> consists of <PARTICLE>s"
    " forming in the active updraft of a cumulonimbus <CLOUD>, growing"
    " primarily by the collection of droplets through coalescence and/or"
    " riming, and falling out not far from their originating updraft.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"convective precipitation\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COUNT,
    "COUNT", "EAC_COUNT",
    "The number of occurrences of a separately specified type of <OBJECT>;"
    " the count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COUNTRY_ID_VALUE_SET,
    "COUNTRY_ID_VALUE_SET", "EAC_COUNTRY_ID_VALUE_SET",
    "The value set of a formatted <<COUNTRY_IDENTIFIER>>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[315]), 9, &(EDCS_Enumerant_Dictionary[1831]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COUNTRY_IDENTIFIER,
    "COUNTRY_IDENTIFIER", "EAC_COUNTRY_IDENTIFIER",
    "An identifier of a country. The format and values of the identifier"
    " are specified by a <<COUNTRY_ID_VALUE_SET>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[315]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NA4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COVERED_DRAIN,
    "COVERED_DRAIN", "EAC_COVERED_DRAIN",
    "An indication that a <COMPONENT> of a <WATERCOURSE> is completely"
    " covered over and connects to uncovered <WATERCOURSE>s at each end; a"
    " covered drain.",
    EDCS_AVT_BOOLEAN, 0,
    3, &(EGBindingForEA[985]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CDA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_COVERED_DRAIN_LENGTH,
    "COVERED_DRAIN_LENGTH", "EAC_COVERED_DRAIN_LENGTH",
    "The <<LENGTH>> of the covered portion of a <WATERCOURSE>; the covered"
    " drain length.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[801]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CDL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CRANE_MOBILITY_TYPE,
    "CRANE_MOBILITY_TYPE", "EAC_CRANE_MOBILITY_TYPE",
    "The type of mobility of a <CRANE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[789]), 3, &(EDCS_Enumerant_Dictionary[1840]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CRM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CRANE_TYPE,
    "CRANE_TYPE", "EAC_CRANE_TYPE",
    "The type of a <CRANE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[789]), 6, &(EDCS_Enumerant_Dictionary[1843]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CRA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CRITICAL_LAYER_ALTITUDE_E,
    "CRITICAL_LAYER_ALTITUDE_E", "EAC_CRITICAL_LAYER_ALTITUDE_E",
    "The altitude of the E layer of free electrons in the <IONOSPHERE> of"
    " the <EARTH>; the critical E layer altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[614]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CRITICAL_LAYER_ALTITUDE_F1,
    "CRITICAL_LAYER_ALTITUDE_F1", "EAC_CRITICAL_LAYER_ALTITUDE_F1",
    "The altitude of the F[sub(1)] layer of free electrons in the"
    " <IONOSPHERE> of the <EARTH>; the critical F[sub(1)] layer altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[614]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CRITICAL_LAYER_ALTITUDE_F2,
    "CRITICAL_LAYER_ALTITUDE_F2", "EAC_CRITICAL_LAYER_ALTITUDE_F2",
    "The altitude of the F[sub(2)] layer of free electrons in the"
    " <IONOSPHERE> of the <EARTH>; the critical F[sub(2)] layer altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[614]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CRITICAL_LAYER_FREQUENCY_E,
    "CRITICAL_LAYER_FREQUENCY_E", "EAC_CRITICAL_LAYER_FREQUENCY_E",
    "The minimum radio <<FREQUENCY>> that begins to be reflected by the E"
    " layer of free electrons in the <IONOSPHERE> of the <EARTH>; the"
    " critical E layer frequency.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    3, &(EGBindingForEA[625]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CRITICAL_LAYER_FREQUENCY_F1,
    "CRITICAL_LAYER_FREQUENCY_F1", "EAC_CRITICAL_LAYER_FREQUENCY_F1",
    "The minimum radio <<FREQUENCY>> that begins to be reflected by the"
    " F[sub(1)] layer of free electrons in the <IONOSPHERE> of the <EARTH>;"
    " the critical F[sub(1)] layer frequency.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    3, &(EGBindingForEA[625]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CRITICAL_LAYER_FREQUENCY_F2,
    "CRITICAL_LAYER_FREQUENCY_F2", "EAC_CRITICAL_LAYER_FREQUENCY_F2",
    "The minimum radio <<FREQUENCY>> that begins to be reflected by the"
    " F[sub(2)] layer of free electrons in the <IONOSPHERE> of the <EARTH>;"
    " the critical F[sub(2)] layer frequency.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    3, &(EGBindingForEA[625]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CROSSING_CONTROL,
    "CROSSING_CONTROL", "EAC_CROSSING_CONTROL",
    "The method of traffic control where <ROAD>s cross.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 4, &(EDCS_Enumerant_Dictionary[1849]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CROWN_DIAMETER,
    "CROWN_DIAMETER", "EAC_CROWN_DIAMETER",
    "The maximum diameter of the crown of a <SHRUB> or <TREE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[831]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CULTURAL_OBJECT_DENSITY,
    "CULTURAL_OBJECT_DENSITY", "EAC_CULTURAL_OBJECT_DENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of <LAND> that is covered by <BUILDING>s and other cultural"
    " <OBJECT>s; the cultural object density.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CFD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CULVERT_TYPE,
    "CULVERT_TYPE", "EAC_CULVERT_TYPE",
    "The type of a <CULVERT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1124]), 3, &(EDCS_Enumerant_Dictionary[1853]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CUMULATIVE_TRACK_LENGTH,
    "CUMULATIVE_TRACK_LENGTH", "EAC_CUMULATIVE_TRACK_LENGTH",
    "The total cumulative <<LENGTH>> of <RAILWAY_TRACK> contained within a"
    " delineated <REGION> exclusive of the branch or main trunk lines"
    " running into and/or out of the <REGION>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CTL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_CYCLE_DATE,
    "CYCLE_DATE", "EAC_CYCLE_DATE",
    "The calendar <<TIME_QUANTITY>> in which data about an <AERODROME> or"
    " <RUNWAY> was added to airport maintenance records or last revised;"
    " the cycle date. Formatted in a Basic Latin string as characters [1-4]"
    " indicating the Gregorian year, and characters [5-6] indicating the 28"
    " day cycle in which the addition or change was made. EXAMPLE"
    " \"200201\" indicating the first cycle in the year 2002.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    4, &(EGBindingForEA[343]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[DAFIF, Sec. 107.C, \"Century/Cycle Date\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DAILY_TIDE_INDEX,
    "DAILY_TIDE_INDEX", "EAC_DAILY_TIDE_INDEX",
    "The sequential number of the peak <TIDE> for a day; the daily tide"
    " index. The value starts at 1 for the first peak <TIDE> for a day and"
    " increases.",
    EDCS_AVT_INTEGER, 0,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DAM_FACE_TYPE,
    "DAM_FACE_TYPE", "EAC_DAM_FACE_TYPE",
    "The type of face of a <DAM>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[983]), 2, &(EDCS_Enumerant_Dictionary[1856]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DFT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DAMAGE_WEIGHT,
    "DAMAGE_WEIGHT", "EAC_DAMAGE_WEIGHT",
    "The amount of ordinance in equivalent <<MASS>> of TNT required to"
    " cause distinguishable damage to a <STRUCTURE>; the damage weight.",
    EDCS_AVT_REAL, EQC_MASS,
    2, &(EGBindingForEA[1300]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DATA_COLLECTION_CRITERIA,
    "DATA_COLLECTION_CRITERIA", "EAC_DATA_COLLECTION_CRITERIA",
    "Criteria describing the collection of data.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[492]), 11, &(EDCS_Enumerant_Dictionary[1858]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DATE_FORMAT,
    "DATE_FORMAT", "EAC_DATE_FORMAT",
    "The format of a date.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 46, &(EDCS_Enumerant_Dictionary[1869]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DATE_TIME_FORMAT,
    "DATE_TIME_FORMAT", "EAC_DATE_TIME_FORMAT",
    "The format of a date and time of the day.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 8, &(EDCS_Enumerant_Dictionary[1915]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DATE_TIME_GROUP,
    "DATE_TIME_GROUP", "EAC_DATE_TIME_GROUP",
    "The date and time, formatted as specified by <<DATE_TIME_FORMAT>>; a"
    " date time group.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"date-time group\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DAY_WITHIN_YEAR,
    "DAY_WITHIN_YEAR", "EAC_DAY_WITHIN_YEAR",
    "The ordinal index of a day within the year, starting with 1 on the"
    " 1^(st) of January.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEEP_SOUND_CHANNEL_AXIS_DEPTH,
    "DEEP_SOUND_CHANNEL_AXIS_DEPTH", "EAC_DEEP_SOUND_CHANNEL_AXIS_DEPTH",
    "The <<DEPTH>> at which the <<SPEED>> of propagation of a compressional"
    " wave achieves its minimum value in a <DEEP_SOUND_CHANNEL>; the deep"
    " sound channel axis depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[267]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEEP_SOUND_CHANNEL_TOP_DEPTH,
    "DEEP_SOUND_CHANNEL_TOP_DEPTH", "EAC_DEEP_SOUND_CHANNEL_TOP_DEPTH",
    "The topmost of the two <<DEPTH>>s of equal maximum <<SPEED>> of"
    " propagation of compressional waves in a <DEEP_SOUND_CHANNEL>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[267]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEFENSIVE_POSITION_COUNT,
    "DEFENSIVE_POSITION_COUNT", "EAC_DEFENSIVE_POSITION_COUNT",
    "The number of <DEFENSIVE_POSITION>s within a delineated <REGION>; the"
    " defensive position count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[34]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEFENSIVE_POSITION_TYPE,
    "DEFENSIVE_POSITION_TYPE", "EAC_DEFENSIVE_POSITION_TYPE",
    "The type of a <DEFENSIVE_POSITION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 11, &(EDCS_Enumerant_Dictionary[1923]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DELINEATION_CERTAIN,
    "DELINEATION_CERTAIN", "EAC_DELINEATION_CERTAIN",
    "An indication that knowledge of the delineation of an <OBJECT> is"
    " certain.",
    EDCS_AVT_BOOLEAN, 0,
    3, &(EGBindingForEA[106]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: COD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DENSITY_ALTITUDE,
    "DENSITY_ALTITUDE", "EAC_DENSITY_ALTITUDE",
    "The <<PRESSURE_ALTITUDE>> corrected for deviations from the standard"
    " <ATMOSPHERE>; the density altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"density altitude\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEPTH,
    "DEPTH", "EAC_DEPTH",
    "The distance from a <SURFACE> down to a <LOCATION> or <SURFACE>;"
    " depth. The value is expressed as a positive number.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[119]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"depth\", 1]", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEPTH_BELOW_SURFACE_LEVEL,
    "DEPTH_BELOW_SURFACE_LEVEL", "EAC_DEPTH_BELOW_SURFACE_LEVEL",
    "The <<DEPTH>> measured from the highest point of an <OBJECT> at the"
    " level of the surrounding <SURFACE> to the lowest point of that"
    " <OBJECT> below the <SURFACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[119]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DEP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEPTH_BELOW_WATERBODY_FLOOR,
    "DEPTH_BELOW_WATERBODY_FLOOR", "EAC_DEPTH_BELOW_WATERBODY_FLOOR",
    "The <<DEPTH>> from a <WATERBODY_FLOOR> down to a <LOCATION>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEPTH_BELOW_WATERBODY_SURFACE,
    "DEPTH_BELOW_WATERBODY_SURFACE", "EAC_DEPTH_BELOW_WATERBODY_SURFACE",
    "The <<DEPTH>> of an <OBJECT> below a <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[15]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DEP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEPTH_OF_WATERBODY_FLOOR,
    "DEPTH_OF_WATERBODY_FLOOR", "EAC_DEPTH_OF_WATERBODY_FLOOR",
    "The <<DEPTH>> from a <WATERBODY_SURFACE> to a <WATERBODY_FLOOR>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DW1, DW2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEW_POINT_DEPRESSION,
    "DEW_POINT_DEPRESSION", "EAC_DEW_POINT_DEPRESSION",
    "The difference between an <<AIR_TEMPERATURE>> at a <LOCATION> and the"
    " <<DEW_POINT_TEMPERATURE>> at that <LOCATION>; the dew point"
    " depression.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"dewpoint depression\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEW_POINT_ERROR,
    "DEW_POINT_ERROR", "EAC_DEW_POINT_ERROR",
    "The error in a measurement of a <<DEW_POINT_TEMPERATURE>> that is"
    " introduced by uncertainties.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"AIR-TEMPERATURE-ANALYSIS-FORECAST dewpoint-temperature error"
    " quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEW_POINT_MAXIMUM_DIFFERENCE_CLIMATOLOGY,
    "DEW_POINT_MAXIMUM_DIFFERENCE_CLIMATOLOGY", "EAC_DEW_POINT_MAXIMUM_DIFFERENCE_CLIMATOLOGY",
    "The historical (climatology) maximum difference between the"
    " <<DEW_POINT_TEMPERATURE>> at an initial time and the"
    " <<DEW_POINT_TEMPERATURE>> at an offset from that time.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEW_POINT_MINIMUM_DIFFERENCE_CLIMATOLOGY,
    "DEW_POINT_MINIMUM_DIFFERENCE_CLIMATOLOGY", "EAC_DEW_POINT_MINIMUM_DIFFERENCE_CLIMATOLOGY",
    "The historical (climatology) minimum difference between the"
    " <<DEW_POINT_TEMPERATURE>> at an initial time and the"
    " <<DEW_POINT_TEMPERATURE>> at an offset from that time.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEW_POINT_QUALITY,
    "DEW_POINT_QUALITY", "EAC_DEW_POINT_QUALITY",
    "The quality of a <<DEW_POINT_TEMPERATURE>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 9, &(EDCS_Enumerant_Dictionary[1934]),
    EDCS_REF_TYP_INFORMATIVE, "[QCMO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DEW_POINT_TEMPERATURE,
    "DEW_POINT_TEMPERATURE", "EAC_DEW_POINT_TEMPERATURE",
    "The <<TEMPERATURE>> to which a given parcel of <AIR> must be cooled at"
    " constant <<ATM_PRESSURE>> and water vapour content in order for"
    " saturation to occur; the dew point temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"dewpoint temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DIR_SHIPPING_NOISE_CORRECTION,
    "DIR_SHIPPING_NOISE_CORRECTION", "EAC_DIR_SHIPPING_NOISE_CORRECTION",
    "The correction to the <<DIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL>>,"
    " typically taken at 50 hertz.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL,
    "DIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL", "EAC_DIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL",
    "In a volume of a <WATERBODY>, the directional shipping noise spectral"
    " power level, typically taken at 50 hertz.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY,
    "DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY", "EAC_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY",
    "The ratio, for a particular material <SURFACE> and unit solid angle"
    " about a particular incident <DIRECTION>, of the reflected"
    " <<RADIANCE>> into the hemisphere above that <SURFACE> to the incident"
    " <<RADIANCE>>. This quantity is also defined as the integral over the"
    " reflected hemisphere of the BRDF times the cosine of the angle"
    " between the surface normal and the reflection <DIRECTION> times the"
    " differential reflection solid angle. It is a function of the"
    " <<INCIDENCE_ZENITH_ANGLE_LOCAL>> and <<INCIDENCE_AZIMUTH_LOCAL>> of"
    " the incident <<RADIANCE>> and is spectral (a distribution function in"
    " <<WAVELENGTH>>); therefore the quantity is measured in terms of"
    " inverse <<WAVELENGTH>> bin size.",
    EDCS_AVT_REAL, EQC_INV_LENGTH,
    5, &(EGBindingForEA[476]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DISPLAY_SIGN_TYPE,
    "DISPLAY_SIGN_TYPE", "EAC_DISPLAY_SIGN_TYPE",
    "The type of a <DISPLAY_SIGN>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 3, &(EDCS_Enumerant_Dictionary[1943]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: SIA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DISSECTED_TERRAIN,
    "DISSECTED_TERRAIN", "EAC_DISSECTED_TERRAIN",
    "An indication that a <TERRAIN_SURFACE_REGION> is dominated by"
    " culturally or naturally dissected <TERRAIN>.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[35]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DOMINANT_BREAKER_TYPE,
    "DOMINANT_BREAKER_TYPE", "EAC_DOMINANT_BREAKER_TYPE",
    "The type of the dominant breaking <WATER_WAVE>s tripped by shoaling"
    " <WATER>; dependent on the nature of the <WATERBODY_FLOOR> and <BEACH>"
    " slope.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[54]), 3, &(EDCS_Enumerant_Dictionary[1946]),
    EDCS_REF_TYP_INFORMATIVE, "[JSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DOOR_CONSTRUCTION_TYPE,
    "DOOR_CONSTRUCTION_TYPE", "EAC_DOOR_CONSTRUCTION_TYPE",
    "The type of <MATERIAL> and/or techniques used to construct a <DOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 7, &(EDCS_Enumerant_Dictionary[1949]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DOOR_OPENING_METHOD,
    "DOOR_OPENING_METHOD", "EAC_DOOR_OPENING_METHOD",
    "The method in which a <DOOR> opens.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 5, &(EDCS_Enumerant_Dictionary[1956]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DOOR_TYPE,
    "DOOR_TYPE", "EAC_DOOR_TYPE",
    "The type of a <DOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 15, &(EDCS_Enumerant_Dictionary[1961]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DRAGON_TEETH_TYPE,
    "DRAGON_TEETH_TYPE", "EAC_DRAGON_TEETH_TYPE",
    "The type of a <DRAGON_TEETH>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 5, &(EDCS_Enumerant_Dictionary[1976]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DROP_GATE_METHOD,
    "DROP_GATE_METHOD", "EAC_DROP_GATE_METHOD",
    "The method by which a <DROP_GATE> is closed.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 2, &(EDCS_Enumerant_Dictionary[1981]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DGC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DUST_PRODUCTION_RATE,
    "DUST_PRODUCTION_RATE", "EAC_DUST_PRODUCTION_RATE",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the production rate of <DUST> at an <OBJECT> that has"
    " been induced by ground movement or surface <WIND>s. Zero means no"
    " production at all and one means maximum production.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bits: 7-8 (Trailing Effects)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_DWELLING_TYPE,
    "DWELLING_TYPE", "EAC_DWELLING_TYPE",
    "The type of a <DWELLING>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[41]), 10, &(EDCS_Enumerant_Dictionary[1983]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: DDC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ECOSYSTEM_TYPE,
    "ECOSYSTEM_TYPE", "EAC_ECOSYSTEM_TYPE",
    "The type of an ecosystem based on a combination of land cover,"
    " floristic properties, climate, and physiognomy.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[653]), 96, &(EDCS_Enumerant_Dictionary[1993]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EDUCATIONAL_BUILDING_TYPE,
    "EDUCATIONAL_BUILDING_TYPE", "EAC_EDUCATIONAL_BUILDING_TYPE",
    "The type of an educational <BUILDING>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1129]), 6, &(EDCS_Enumerant_Dictionary[2089]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: EBT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELECTRON_DENSITY,
    "ELECTRON_DENSITY", "EAC_ELECTRON_DENSITY",
    "The number of electrons per unit <<VOLUME>>; the electron density.",
    EDCS_AVT_REAL, EQC_VOLUMETRIC_ENTITY_DENSITY,
    2, &(EGBindingForEA[924]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELECTRONIC_WATERBODY_FLOOR_DEPTH,
    "ELECTRONIC_WATERBODY_FLOOR_DEPTH", "EAC_ELECTRONIC_WATERBODY_FLOOR_DEPTH",
    "The <<DEPTH_OF_WATERBODY_FLOOR>> obtained by electronic depth"
    " measuring instruments.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: EDP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEV_ELECTRICAL_CABLE_ICING_SAG,
    "ELEV_ELECTRICAL_CABLE_ICING_SAG", "EAC_ELEV_ELECTRICAL_CABLE_ICING_SAG",
    "The value of the maximum variation in the vertical clearance of an"
    " <ELEVATED_ELECTRICAL_CABLE> due to an accumulation of <ICE>; the"
    " elevated electrical cable icing sag.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[810]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ICE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEV_ELECTRICAL_CABLE_MINIMUM_HEIGHT,
    "ELEV_ELECTRICAL_CABLE_MINIMUM_HEIGHT", "EAC_ELEV_ELECTRICAL_CABLE_MINIMUM_HEIGHT",
    "The minimum <<HEIGHT_AGL>> of an <ELEVATED_ELECTRICAL_CABLE> above the"
    " underlying <PLANETARY_SURFACE>; the elevated electrical cable minimum"
    " clearance.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[816]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEV_ELECTRICAL_CABLE_PYLON_SPACING,
    "ELEV_ELECTRICAL_CABLE_PYLON_SPACING", "EAC_ELEV_ELECTRICAL_CABLE_PYLON_SPACING",
    "The spacing distance between adjacent <PYLON>s along an"
    " <ELEVATED_ELECTRICAL_CABLE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[816]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEV_ELECTRICAL_CABLE_SAG,
    "ELEV_ELECTRICAL_CABLE_SAG", "EAC_ELEV_ELECTRICAL_CABLE_SAG",
    "The maximum vertical distance from the height of an"
    " <ELEVATED_ELECTRICAL_CABLE> at a connection to a <PYLON> to the"
    " lowest point of the <ELEVATED_ELECTRICAL_CABLE>; the elevated"
    " electrical cable sag.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[816]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEV_ELECTRICAL_CABLE_SEGMENT_COUNT,
    "ELEV_ELECTRICAL_CABLE_SEGMENT_COUNT", "EAC_ELEV_ELECTRICAL_CABLE_SEGMENT_COUNT",
    "The number of straight segments that may be used to approximate the"
    " catenary shape of an <ELEVATED_ELECTRICAL_CABLE> between adjacent"
    " <PYLON>s; the elevated electrical cable segment count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[26]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEV_ELECTRICAL_CABLE_TYPE,
    "ELEV_ELECTRICAL_CABLE_TYPE", "EAC_ELEV_ELECTRICAL_CABLE_TYPE",
    "The type of suspension of an <ELEVATED_ELECTRICAL_CABLE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 3, &(EDCS_Enumerant_Dictionary[2095]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TST]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEVATION,
    "ELEVATION", "EAC_ELEVATION",
    "The distance above a <SURFACE_DATUM>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[15]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"elevation\", 3.c]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEVATION_ACCURACY_STATEMENT,
    "ELEVATION_ACCURACY_STATEMENT", "EAC_ELEVATION_ACCURACY_STATEMENT",
    "A statement of the accuracy of an <<ELEVATION>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[46]), 2, &(EDCS_Enumerant_Dictionary[2098]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ELA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ELEVATION_ANGLE,
    "ELEVATION_ANGLE", "EAC_ELEVATION_ANGLE",
    "The <<VECTOR_ELEV_ANGLE_LOCAL>> from the horizontal plane at the"
    " observer's location, to either a <LINE> passing through the observer,"
    " or a vector relative to the observer, or the direction from the"
    " observer to an <OBJECT> or <LOCATION>; the elevation angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EM_BAND,
    "EM_BAND", "EAC_EM_BAND",
    "The scientifically-accepted designation for a range of <<FREQUENCY>>s"
    " within the electromagnetic spectrum; the electromagnetic band.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[16]), 44, &(EDCS_Enumerant_Dictionary[2100]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EM_EVAPORATIVE_DUCT_HEIGHT,
    "EM_EVAPORATIVE_DUCT_HEIGHT", "EAC_EM_EVAPORATIVE_DUCT_HEIGHT",
    "The <<HEIGHT_AGL>> of the top of a"
    " <ELECTROMAGNETIC_REFRACTIVE_EVAPORATIVE_DUCT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[611]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EM_POLARIZATION_TYPE,
    "EM_POLARIZATION_TYPE", "EAC_EM_POLARIZATION_TYPE",
    "The type(s) of electromagnetic polarization established by an <AERIAL>"
    " of an emitter and/or a receiver.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[16]), 9, &(EDCS_Enumerant_Dictionary[2144]),
    EDCS_REF_TYP_INFORMATIVE, "[PES]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EM_PROPAGATION_CONDITION,
    "EM_PROPAGATION_CONDITION", "EAC_EM_PROPAGATION_CONDITION",
    "The type of condition causing variation in the propagation path of"
    " electromagnetic energy due to interaction of the emitted energy with"
    " the vertical density gradient of the <ATMOSPHERE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[605]), 4, &(EDCS_Enumerant_Dictionary[2153]),
    EDCS_REF_TYP_INFORMATIVE, "[BATT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EM_PULSE_DURATION,
    "EM_PULSE_DURATION", "EAC_EM_PULSE_DURATION",
    "The quantity of time (duration) of an electromagnetic pulse, as"
    " measured between the half-power points.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[954]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EM_PULSE_PEAK_POWER,
    "EM_PULSE_PEAK_POWER", "EAC_EM_PULSE_PEAK_POWER",
    "The peak power of an electromagnetic pulse.",
    EDCS_AVT_REAL, EQC_POWER,
    1, &(EGBindingForEA[16]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EM_PULSE_TOTAL_ENERGY,
    "EM_PULSE_TOTAL_ENERGY", "EAC_EM_PULSE_TOTAL_ENERGY",
    "The total energy of an electromagnetic pulse.",
    EDCS_AVT_REAL, EQC_ENERGY,
    1, &(EGBindingForEA[16]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EM_TRANSMISSION_LOSS,
    "EM_TRANSMISSION_LOSS", "EAC_EM_TRANSMISSION_LOSS",
    "The electromagnetic <<TRANSMISSION_LOSS>>.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    2, &(EGBindingForEA[924]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EMISSIVITY,
    "EMISSIVITY", "EAC_EMISSIVITY",
    "The ratio of the power emitted by an <OBJECT> at a given"
    " <<TEMPERATURE>> to the power emitted if the body obeyed Planck's"
    " radiation law (black body emission); the emissivity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"emissivity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EMITTANCE_AZIMUTH_GEODETIC,
    "EMITTANCE_AZIMUTH_GEODETIC", "EAC_EMITTANCE_AZIMUTH_GEODETIC",
    "The <<VECTOR_AZIMUTH_GEODETIC>> toward which light is emitted (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EMITTANCE_AZIMUTH_LOCAL,
    "EMITTANCE_AZIMUTH_LOCAL", "EAC_EMITTANCE_AZIMUTH_LOCAL",
    "The <<VECTOR_AZIMUTH_LOCAL>> toward which light is emitted (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EMITTANCE_AZIMUTH_MAGNETIC,
    "EMITTANCE_AZIMUTH_MAGNETIC", "EAC_EMITTANCE_AZIMUTH_MAGNETIC",
    "The <<VECTOR_AZIMUTH_MAGNETIC>> toward which light is emitted (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EMITTANCE_ELEV_ANGLE_HORIZONTAL,
    "EMITTANCE_ELEV_ANGLE_HORIZONTAL", "EAC_EMITTANCE_ELEV_ANGLE_HORIZONTAL",
    "The <<VECTOR_ELEV_ANGLE_HORIZONTAL>> toward which light is emitted"
    " (the <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EMITTANCE_ELEV_ANGLE_LOCAL,
    "EMITTANCE_ELEV_ANGLE_LOCAL", "EAC_EMITTANCE_ELEV_ANGLE_LOCAL",
    "The <<VECTOR_ELEV_ANGLE_LOCAL>> toward which light is emitted (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EMITTED_DIFFUSE_LIGHT_SCALED_INTENSITY,
    "EMITTED_DIFFUSE_LIGHT_SCALED_INTENSITY", "EAC_EMITTED_DIFFUSE_LIGHT_SCALED_INTENSITY",
    "A number between 0 and 1 inclusive representing that linearly-scaled"
    " fractional light intensity that leaves the <SURFACE> of an <OBJECT>"
    " in all <DIRECTION>s with equal magnitude. Zero means minimum"
    " intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[885]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[ICP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EMITTED_SPECULAR_LIGHT_SCALED_INTENSITY,
    "EMITTED_SPECULAR_LIGHT_SCALED_INTENSITY", "EAC_EMITTED_SPECULAR_LIGHT_SCALED_INTENSITY",
    "A number between 0 and 1 inclusive representing that linearly-scaled"
    " fractional light intensity that leaves the <SURFACE> of an <OBJECT>"
    " in a particular <DIRECTION>. Zero means minimum intensity and one"
    " means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[885]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[ICP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ENCLOSURE_MAXIMUM_HEIGHT,
    "ENCLOSURE_MAXIMUM_HEIGHT", "EAC_ENCLOSURE_MAXIMUM_HEIGHT",
    "The maximum vertical distance from <FLOOR> to <ROOM_CEILING> of a"
    " <BUILDING> compartment (for example: a <ROOM> and/or a"
    " <FLOOR_CRAWL_SPACE>; the enclosure maximum height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[696]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ENCLOSURE_MINIMUM_HEIGHT,
    "ENCLOSURE_MINIMUM_HEIGHT", "EAC_ENCLOSURE_MINIMUM_HEIGHT",
    "The minimum vertical distance from <FLOOR> to <ROOM_CEILING> of a"
    " <BUILDING> compartment (for example: a <ROOM> and/or a"
    " <FLOOR_CRAWL_SPACE>; the enclosure maximum height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[696]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ENGINE_SMOKE_RATE,
    "ENGINE_SMOKE_RATE", "EAC_ENGINE_SMOKE_RATE",
    "The <<SMOKE_RATE_FRACTION>> of a motor/engine/propulsion <SYSTEM> in"
    " an <OBJECT>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bits: 5-6 (Smoke)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ENGINEER_TRENCH_TYPE,
    "ENGINEER_TRENCH_TYPE", "EAC_ENGINEER_TRENCH_TYPE",
    "The type of an <ENGINEER_TRENCH>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 3, &(EDCS_Enumerant_Dictionary[2157]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ENTRANCE_AND_OR_EXIT_COUNT,
    "ENTRANCE_AND_OR_EXIT_COUNT", "EAC_ENTRANCE_AND_OR_EXIT_COUNT",
    "The number of <STRUCTURE_ENTRANCE_AND_OR_EXIT>s of a <STRUCTURE>; the"
    " entrance and/or exit count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[43]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ENTRANCE_COUNT,
    "ENTRANCE_COUNT", "EAC_ENTRANCE_COUNT",
    "The number of <STRUCTURE_ENTRANCE>s of a <STRUCTURE>; the entrance"
    " count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[43]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXISTENCE_CERTAINTY,
    "EXISTENCE_CERTAINTY", "EAC_EXISTENCE_CERTAINTY",
    "The certainty of existence of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[190]), 5, &(EDCS_Enumerant_Dictionary[2160]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: COE]",
    "", EDCS_CONCEPT_STAT_DEPRECATED },

    {EAC_EXISTENCE_STATUS,
    "EXISTENCE_STATUS", "EAC_EXISTENCE_STATUS",
    "The status or existence condition of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 65, &(EDCS_Enumerant_Dictionary[2165]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: EXS]",
    "", EDCS_CONCEPT_STAT_DEPRECATED },

    {EAC_EXIT_COUNT,
    "EXIT_COUNT", "EAC_EXIT_COUNT",
    "The number of <STRUCTURE_EXIT>s of a <STRUCTURE>; the exit count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[43]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXPLOSIVE_MINE_DENSITY,
    "EXPLOSIVE_MINE_DENSITY", "EAC_EXPLOSIVE_MINE_DENSITY",
    "The areal density of <EXPLOSIVE_MINE>s within a <MINEFIELD>.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    2, &(EGBindingForEA[1293]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"minefield density\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXPLOSIVE_MINE_TYPE,
    "EXPLOSIVE_MINE_TYPE", "EAC_EXPLOSIVE_MINE_TYPE",
    "The type of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 16, &(EDCS_Enumerant_Dictionary[2230]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTERIOR_LIGHTING_INTENSITY,
    "EXTERIOR_LIGHTING_INTENSITY", "EAC_EXTERIOR_LIGHTING_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the general external <LIGHTING> of an"
    " <OBJECT>. Zero means unlit and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[885]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.5, Bit: 28 (Exterior Lights)]",
    "[EBEV, 4.3.9, Bit: 12 (Lights)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTERIOR_WALL_CONSTRUCTION_TYPE,
    "EXTERIOR_WALL_CONSTRUCTION_TYPE", "EAC_EXTERIOR_WALL_CONSTRUCTION_TYPE",
    "The type of <MATERIAL> and/or techniques used to construct an"
    " <EXTERIOR_WALL>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 8, &(EDCS_Enumerant_Dictionary[2246]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTERIOR_WALL_FORTIFICATION,
    "EXTERIOR_WALL_FORTIFICATION", "EAC_EXTERIOR_WALL_FORTIFICATION",
    "The <MATERIAL>s and/or techniques used to fortify an <EXTERIOR_WALL>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[711]), 4, &(EDCS_Enumerant_Dictionary[2254]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTERIOR_WALL_THICKNESS,
    "EXTERIOR_WALL_THICKNESS", "EAC_EXTERIOR_WALL_THICKNESS",
    "The <<THICKNESS>> of an <EXTERIOR_WALL>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[696]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTERNAL_PAINT_SCHEME,
    "EXTERNAL_PAINT_SCHEME", "EAC_EXTERNAL_PAINT_SCHEME",
    "The applied external paint scheme of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[101]), 5, &(EDCS_Enumerant_Dictionary[2258]),
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 0 (Paint Scheme)]",
    "[EBEV, 4.3.1.1, Bits: 17-18 (Camouflage Type)], [EBEV, 4.3.3, Bits:"
    " 28-29 (Camouflage Type)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTERNAL_WINDOW_COVERING,
    "EXTERNAL_WINDOW_COVERING", "EAC_EXTERNAL_WINDOW_COVERING",
    "The type of the external covering of a <WINDOW>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 4, &(EDCS_Enumerant_Dictionary[2263]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTINCTION_COEFFICIENT,
    "EXTINCTION_COEFFICIENT", "EAC_EXTINCTION_COEFFICIENT",
    "For radiation propagating through a medium, the fractional depletion"
    " of <<RADIANCE>> per unit path length; the extinction coefficient loss.",
    EDCS_AVT_REAL, EQC_LINEAR_ENERGY_TRANSFER,
    1, &(EGBindingForEA[16]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"extinction coefficient\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTINCTION_COEFFICIENT_LEVEL,
    "EXTINCTION_COEFFICIENT_LEVEL", "EAC_EXTINCTION_COEFFICIENT_LEVEL",
    "The vertical displacement above a <SURFACE_DATUM> identified by an"
    " <<ATM_VERTICAL_REFERENCE>> at which a given value of"
    " <<EXTINCTION_COEFFICIENT>> occurs; the extinction coefficient level.",
    EDCS_AVT_REAL, EQC_GEOPOTENTIAL_ENERGY_LENGTH,
    2, &(EGBindingForEA[915]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"EXTINCTION-COEFFICIENT-OBSERVATION height dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTINCTION_COEFFICIENT_WAVELENGTH,
    "EXTINCTION_COEFFICIENT_WAVELENGTH", "EAC_EXTINCTION_COEFFICIENT_WAVELENGTH",
    "The electromagnetic <<WAVELENGTH>> for an <<EXTINCTION_COEFFICIENT>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[791]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"EXTINCTION-COEFFICIENT-ANALYSIS-FORECAST wavelength"
    " dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTRACTION_MINE_TYPE,
    "EXTRACTION_MINE_TYPE", "EAC_EXTRACTION_MINE_TYPE",
    "The type of an <EXTRACTION_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[25]), 9, &(EDCS_Enumerant_Dictionary[2267]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MIN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTREME_HIGH_AIR_TEMPERATURE,
    "EXTREME_HIGH_AIR_TEMPERATURE", "EAC_EXTREME_HIGH_AIR_TEMPERATURE",
    "The maximum (extreme) of a <SET> of <<MAXIMUM_AIR_TEMPERATURE>>s for a"
    " <<TIME_QUANTITY>>; a maximum high air temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"extreme air temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_EXTREME_LOW_AIR_TEMPERATURE,
    "EXTREME_LOW_AIR_TEMPERATURE", "EAC_EXTREME_LOW_AIR_TEMPERATURE",
    "The minimum (extreme) of a <SET> of <<MINIMUM_AIR_TEMPERATURE>>s for a"
    " <<TIME_QUANTITY>>; a minimum low air temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"extreme air temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FABRICATION_TYPE,
    "FABRICATION_TYPE", "EAC_FABRICATION_TYPE",
    "The type of a fabrication industry <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[25]), 2, &(EDCS_Enumerant_Dictionary[2276]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FTP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FACILITY_COMMISSIONED_STATUS,
    "FACILITY_COMMISSIONED_STATUS", "EAC_FACILITY_COMMISSIONED_STATUS",
    "The type of commissioned status of a <FACILITY>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 6, &(EDCS_Enumerant_Dictionary[2278]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: CMS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FACILITY_OPERATION_CONTINUITY,
    "FACILITY_OPERATION_CONTINUITY", "EAC_FACILITY_OPERATION_CONTINUITY",
    "The continuity of operation of a <FACILITY>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 3, &(EDCS_Enumerant_Dictionary[2284]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: COS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FARMING_METHOD,
    "FARMING_METHOD", "EAC_FARMING_METHOD",
    "The agricultural practice in use within an agro-ecosystem; the farming"
    " method.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[327]), 4, &(EDCS_Enumerant_Dictionary[2287]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FENCE_TYPE,
    "FENCE_TYPE", "EAC_FENCE_TYPE",
    "The type of a <FENCE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[13]), 10, &(EDCS_Enumerant_Dictionary[2291]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FTI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FERRY_CROSSING_LENGTH,
    "FERRY_CROSSING_LENGTH", "EAC_FERRY_CROSSING_LENGTH",
    "The <<LENGTH>> of a <FERRY_CROSSING> between points on opposite"
    " <SHORE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[805]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FCL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FERRY_CROSSING_TIME,
    "FERRY_CROSSING_TIME", "EAC_FERRY_CROSSING_TIME",
    "The usual <<TIME_QUANTITY>> taken for a crossing by <FERRY>, including"
    " typical loading and unloading times.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[1034]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FCT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FERRY_ROUTE_TYPE,
    "FERRY_ROUTE_TYPE", "EAC_FERRY_ROUTE_TYPE",
    "The type of <ROUTE> which a <FERRY> follows.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 3, &(EDCS_Enumerant_Dictionary[2301]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FER]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FIELD_PATTERN,
    "FIELD_PATTERN", "EAC_FIELD_PATTERN",
    "The geometric layout used in placing seeds or young <PLANT>s on a"
    " <TRACT> used for agriculture; the field pattern.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[323]), 3, &(EDCS_Enumerant_Dictionary[2304]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FIGHTER_WINGED_AIRCRAFT_TYPE,
    "FIGHTER_WINGED_AIRCRAFT_TYPE", "EAC_FIGHTER_WINGED_AIRCRAFT_TYPE",
    "The type of a <FIGHTER_WINGED_AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[408]), 33, &(EDCS_Enumerant_Dictionary[2307]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FILL_TYPE,
    "FILL_TYPE", "EAC_FILL_TYPE",
    "The type of an <OBJECT> that is filled with <MATERIAL> (for example:"
    " <SOIL> and/or <ROCK>); fill type.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[35]), 2, &(EDCS_Enumerant_Dictionary[2340]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: FIC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FIRE_ESCAPE_EXTENDED,
    "FIRE_ESCAPE_EXTENDED", "EAC_FIRE_ESCAPE_EXTENDED",
    "An indication that the retracting, lowest section of a <FIRE_ESCAPE>"
    " is extended for use.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[700]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FIRE_POWER_DAMAGE,
    "FIRE_POWER_DAMAGE", "EAC_FIRE_POWER_DAMAGE",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the extent of physical injury/damage to an <OBJECT>"
    " affecting its capability to project firepower. Zero means not capable"
    " at all and one means fully capable.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[183]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 2 (Firepower)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FISHING_FACILITY_TYPE,
    "FISHING_FACILITY_TYPE", "EAC_FISHING_FACILITY_TYPE",
    "The type of a <FISHING_FACILITY>.",
    EDCS_AVT_ENUMERATION, 0,
    5, &(EGBindingForEA[558]), 4, &(EDCS_Enumerant_Dictionary[2342]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FFC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FISHING_VESSEL_DENSITY,
    "FISHING_VESSEL_DENSITY", "EAC_FISHING_VESSEL_DENSITY",
    "The areal density of <FISHING_BOAT>s.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    6, &(EGBindingForEA[563]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Historical Temporal Shipping Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FLOOR_CONSTRUCTION_TYPE,
    "FLOOR_CONSTRUCTION_TYPE", "EAC_FLOOR_CONSTRUCTION_TYPE",
    "The type of <MATERIAL> and/or techniques used to construct a <FLOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 8, &(EDCS_Enumerant_Dictionary[2346]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FLOOR_COVERING_TYPE,
    "FLOOR_COVERING_TYPE", "EAC_FLOOR_COVERING_TYPE",
    "The type of the covering of a <FLOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 10, &(EDCS_Enumerant_Dictionary[2354]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FLOOR_LEVEL_COUNT,
    "FLOOR_LEVEL_COUNT", "EAC_FLOOR_LEVEL_COUNT",
    "The number of <FLOOR_LEVEL>s for accommodating <HUMAN>s or <EQUIPMENT>"
    " in a <BUILDING>, possibly different from the number of stories in the"
    " <BUILDING>. <FLOOR_LEVEL>s may include underground <FLOOR_LEVEL>s as"
    " well as above ground <FLOOR_LEVEL>s; the floor level count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[10]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FLOOR_LEVEL_IDENTIFIER,
    "FLOOR_LEVEL_IDENTIFIER", "EAC_FLOOR_LEVEL_IDENTIFIER",
    "The numeric identifier of a <FLOOR_LEVEL>.",
    EDCS_AVT_INDEX, 0,
    2, &(EGBindingForEA[698]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FLOW_DIRECTION,
    "FLOW_DIRECTION", "EAC_FLOW_DIRECTION",
    "The <DIRECTION> of flow.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DOF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FOG_COVERAGE_FRACTION,
    "FOG_COVERAGE_FRACTION", "EAC_FOG_COVERAGE_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional <<AREA>> of a <REGION> of a <PLANETARY_SURFACE> that is"
    " covered by <FOG>, as seen from above. Zero means no coverage at all"
    " and one means complete coverage.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[449]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FOG_DETECTOR_LIGHT_PRESENT,
    "FOG_DETECTOR_LIGHT_PRESENT", "EAC_FOG_DETECTOR_LIGHT_PRESENT",
    "An indication that an <OBJECT> has an associated detector light for"
    " <FOG>.",
    EDCS_AVT_BOOLEAN, 0,
    4, &(EGBindingForEA[79]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FDT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FOG_EXTINCTION_COEFFICIENT,
    "FOG_EXTINCTION_COEFFICIENT", "EAC_FOG_EXTINCTION_COEFFICIENT",
    "The <<EXTINCTION_COEFFICIENT>> due to <FOG>.",
    EDCS_AVT_REAL, EQC_LINEAR_ENERGY_TRANSFER,
    2, &(EGBindingForEA[427]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"extinction coefficient\"]",
    "[WMO182, \"fog\"]", EDCS_CONCEPT_STAT_ISO },

    {EAC_FOG_PRESENT,
    "FOG_PRESENT", "EAC_FOG_PRESENT",
    "An indication that <FOG> is present.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[427]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FOG_PROBABILITY,
    "FOG_PROBABILITY", "EAC_FOG_PROBABILITY",
    "The probability of the occurrence of <FOG>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"CLOUD-ANALYSIS-FORECAST fog probability rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FOG_SIGNAL_GENERATION_TYPE,
    "FOG_SIGNAL_GENERATION_TYPE", "EAC_FOG_SIGNAL_GENERATION_TYPE",
    "The type of mechanism of signal generation in the presence of <FOG>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[429]), 4, &(EDCS_Enumerant_Dictionary[2364]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GEN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FOG_THICKNESS,
    "FOG_THICKNESS", "EAC_FOG_THICKNESS",
    "The height of a bank of <FOG> relative to the local <TERRAIN>, where"
    " the base of the <FOG> is assumed to be at ground level; fog thickness.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[432]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FOLIAGE_STATE,
    "FOLIAGE_STATE", "EAC_FOLIAGE_STATE",
    "The state of the foliage within a delineated <REGION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1218]), 4, &(EDCS_Enumerant_Dictionary[2368]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FORMATION_RUNNING_LIGHT_INTENSITY,
    "FORMATION_RUNNING_LIGHT_INTENSITY", "EAC_FORMATION_RUNNING_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the external <LIGHTING> used to maintain"
    " spatial relationships with/by <VEHICLE>s; the formation, running, or"
    " tail light intensity. Zero means unlit and one means maximum"
    " intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    5, &(EGBindingForEA[896]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.2, Bit: 24 (Formation Lights)]",
    "[EBEV, 4.3.1.1, Bit: 13 (Tail Lights)], [EBEV, 4.3.1.3, Bit: 12"
    " (Running Lights)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_FRACTIONAL_CONTENT,
    "FRACTIONAL_CONTENT", "EAC_FRACTIONAL_CONTENT",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the total composition of an <OBJECT>; fractional content."
    " Zero means that there is no contribution and one means that the"
    " <OBJECT> is homogeneous.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PCC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FREQUENCY,
    "FREQUENCY", "EAC_FREQUENCY",
    "The frequency of an audio, electromagnetic, or light wave.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    1, &(EGBindingForEA[1]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"frequency\", 4.b]", EDCS_CONCEPT_STAT_ISO },

    {EAC_FREQUENCY_INDEPENDENT_ACOUSTIC_SCATTERING_LEVEL,
    "FREQUENCY_INDEPENDENT_ACOUSTIC_SCATTERING_LEVEL", "EAC_FREQUENCY_INDEPENDENT_ACOUSTIC_SCATTERING_LEVEL",
    "In a <WATERBODY>, the frequency-independent acoustic scattering level.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Volume Scattering Strength Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FRIGATE_TYPE,
    "FRIGATE_TYPE", "EAC_FRIGATE_TYPE",
    "The type of a <FRIGATE>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[1022]), 5, &(EDCS_Enumerant_Dictionary[2372]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FRONT_AND_AXIS_REFERENCE,
    "FRONT_AND_AXIS_REFERENCE", "EAC_FRONT_AND_AXIS_REFERENCE",
    "The association of the front, or long, axis of an <OBJECT> to an axis"
    " of a reference local orthonormal coordinate system.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 7, &(EDCS_Enumerant_Dictionary[2377]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FROZEN_SOIL_LAYER_BOTTOM_DEPTH,
    "FROZEN_SOIL_LAYER_BOTTOM_DEPTH", "EAC_FROZEN_SOIL_LAYER_BOTTOM_DEPTH",
    "The <<DEPTH>> from the <TERRAIN> to the base of a layer of frozen"
    " <SOIL>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[1236]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"ENVIRONMENTAL-SOIL-OBSERVATION frozen depth dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FROZEN_SOIL_LAYER_TOP_DEPTH,
    "FROZEN_SOIL_LAYER_TOP_DEPTH", "EAC_FROZEN_SOIL_LAYER_TOP_DEPTH",
    "The <<DEPTH>> from the <TERRAIN> to the top of a layer of frozen"
    " <SOIL>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[1236]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"ENVIRONMENTAL-SOIL-OBSERVATION frozen depth dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FROZEN_SURFACE_COVER_TYPE,
    "FROZEN_SURFACE_COVER_TYPE", "EAC_FROZEN_SURFACE_COVER_TYPE",
    "The type of frozen <PRECIPITATION> and/or frozen <WATER> that is"
    " present covering a <SURFACE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[23]), 6, &(EDCS_Enumerant_Dictionary[2384]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SIC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FUEL_FACILITIES_AVAILABLE,
    "FUEL_FACILITIES_AVAILABLE", "EAC_FUEL_FACILITIES_AVAILABLE",
    "The type of fuel <FACILITY>s available at or in the near vicinity.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1131]), 15, &(EDCS_Enumerant_Dictionary[2390]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FFA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FUNCTIONAL_RUNWAY_COUNT,
    "FUNCTIONAL_RUNWAY_COUNT", "EAC_FUNCTIONAL_RUNWAY_COUNT",
    "The number of fully functional <RUNWAY>s at an <AERODROME>; the"
    " functional runway count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[419]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FUNCTIONAL_STATUS,
    "FUNCTIONAL_STATUS", "EAC_FUNCTIONAL_STATUS",
    "The general condition or functionality of an <OBJECT> regardless of"
    " its primary purpose.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 16, &(EDCS_Enumerant_Dictionary[2405]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: FUN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FUNCTIONAL_USE,
    "FUNCTIONAL_USE", "EAC_FUNCTIONAL_USE",
    "The general function or use of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 32, &(EDCS_Enumerant_Dictionary[2421]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: FUC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_FURNITURE_TYPE,
    "FURNITURE_TYPE", "EAC_FURNITURE_TYPE",
    "The type of <FURNITURE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 8, &(EDCS_Enumerant_Dictionary[2453]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GATE_TYPE,
    "GATE_TYPE", "EAC_GATE_TYPE",
    "The type of a <GATE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 3, &(EDCS_Enumerant_Dictionary[2461]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GENERAL_DAMAGE_FRACTION,
    "GENERAL_DAMAGE_FRACTION", "EAC_GENERAL_DAMAGE_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the extent of physical injury/damage to an <OBJECT>. Zero"
    " means healthy or undamaged, and one means death or complete"
    " destruction.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bits: 3-4 (Damage)]",
    "[EBEV, 4.3.3, Bits: 3-4 (Health)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_GEODETIC_AZIMUTH,
    "GEODETIC_AZIMUTH", "EAC_GEODETIC_AZIMUTH",
    "The <<VECTOR_AZIMUTH_GEODETIC>> in the horizontal plane at the"
    " observer's <LOCATION>, to either a <LINE> passing through the"
    " observer, or a vector relative to the observer, or the <DIRECTION>"
    " from the observer to an <OBJECT> or <LOCATION>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GEODETIC_DATUM_IDENTIFIER,
    "GEODETIC_DATUM_IDENTIFIER", "EAC_GEODETIC_DATUM_IDENTIFIER",
    "The designation of a <GEODETIC_DATUM>; geodetic datum identifier.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1245]), 307, &(EDCS_Enumerant_Dictionary[2464]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HOD and HZD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GEOGRAPHIC_LIGHT_RANGE,
    "GEOGRAPHIC_LIGHT_RANGE", "EAC_GEOGRAPHIC_LIGHT_RANGE",
    "The maximum distance at which the curvature of the <PLANETARY_SURFACE>"
    " and refraction due to the <ATMOSPHERE> permit a <LIGHT> to be seen"
    " from a particular height of eye without regard to the luminous"
    " intensity of the <LIGHT>; the geographic light range.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[793]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GEOGRAPHIC_REGION,
    "GEOGRAPHIC_REGION", "EAC_GEOGRAPHIC_REGION",
    "The <REGION> of the <EARTH> in which an <OBJECT> is located.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[164]), 9, &(EDCS_Enumerant_Dictionary[2771]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GEO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GEOMORPHIC_DEPTH,
    "GEOMORPHIC_DEPTH", "EAC_GEOMORPHIC_DEPTH",
    "The <<DEPTH>> of an <OBJECT> below the mean level of the surrounding"
    " <TERRAIN> as determined by a corresponding digital elevation matrix;"
    " if not obtainable, the mean <<DEPTH>> is used; the geomorphic depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GPD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GEOMORPHIC_HEIGHT,
    "GEOMORPHIC_HEIGHT", "EAC_GEOMORPHIC_HEIGHT",
    "The height of an <OBJECT> above the mean level of the surrounding"
    " <TERRAIN> as determined by a corresponding digital elevation matrix;"
    " the geomorphic height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GEH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GEOPOTENTIAL_ALTITUDE,
    "GEOPOTENTIAL_ALTITUDE", "EAC_GEOPOTENTIAL_ALTITUDE",
    "The <<ALTITUDE_MSL>> of a given <LOCATION> in the <ATMOSPHERE> in"
    " units proportional to the potential energy of unit <<MASS>>"
    " (geopotential); the geopotential altitude.",
    EDCS_AVT_REAL, EQC_GEOPOTENTIAL_ENERGY_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"geopotential altitude\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GLIDE_SLOPE_ANGLE,
    "GLIDE_SLOPE_ANGLE", "EAC_GLIDE_SLOPE_ANGLE",
    "The vertical angle at which an <AIRCRAFT> should properly descend to a"
    " touchdown point; the glide slope angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[347]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GSA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GLINT_ANGLE,
    "GLINT_ANGLE", "EAC_GLINT_ANGLE",
    "The angle subtended by the glint vector and the surface normal, where"
    " the glint vector is the vector that bisects the source vector and the"
    " viewing vector at a <SURFACE>. Used by the Phong and"
    " Sandford-Robertson BRDF models.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[465]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WATT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GRADING_TYPE,
    "GRADING_TYPE", "EAC_GRADING_TYPE",
    "The type and/or number of <TERRAIN_SURFACE_OBJECT> (for example: a"
    " <TERRAIN_CUT> and/or an <EMBANKMENT>) sides for which the local"
    " <TERRAIN> has been graded.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[35]), 4, &(EDCS_Enumerant_Dictionary[2780]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GRATING_PRESENT,
    "GRATING_PRESENT", "EAC_GRATING_PRESENT",
    "An indication that a passageway is blocked by one or more locked or"
    " fixed grates; grating present.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[49]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GRID_DIAGONALIZATION,
    "GRID_DIAGONALIZATION", "EAC_GRID_DIAGONALIZATION",
    "The manner in which a grid cell formed by four adjacent data values is"
    " divided into two triangular <POLYGONAL_FACE>s along a cell diagonal;"
    " the grid diagonalization.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[6]), 2, &(EDCS_Enumerant_Dictionary[2784]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GROUND_VEHICLE_FUNCTION,
    "GROUND_VEHICLE_FUNCTION", "EAC_GROUND_VEHICLE_FUNCTION",
    "The function of a <GROUND_VEHICLE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1168]), 20, &(EDCS_Enumerant_Dictionary[2786]),
    EDCS_REF_TYP_INFORMATIVE, "[F3-01]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GROUND_VEHICLE_PROPULSION_TYPE,
    "GROUND_VEHICLE_PROPULSION_TYPE", "EAC_GROUND_VEHICLE_PROPULSION_TYPE",
    "The propulsion type or technique of a <GROUND_VEHICLE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1168]), 5, &(EDCS_Enumerant_Dictionary[2806]),
    EDCS_REF_TYP_INFORMATIVE, "[F3-01]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GTRS_GEOTILE,
    "GTRS_GEOTILE", "EAC_GTRS_GEOTILE",
    "The identification of a specific geotile within the Geotile Reference"
    " System (GTRS) formatted in a Basic Latin string. The string contains"
    " a 6-digit alphanumeric designation, the first two letters of which"
    " are the encompassing GTRS megatile, the next two digits are the"
    " easting index of the geotile within the megatile, and the last two"
    " digits are the northing index of the geotile within the megatile. The"
    " 2 letter designation of the GTRS megatile is based on the location of"
    " its south-west corner and is composed of a letter designating the"
    " longitudinal position of the megatile followed by a letter"
    " designating the latitudinal position of the megatile. Between 60"
    " degree N and 60 degree S there are 24 longitudinal zones of megatiles"
    " each of 15 arc degrees width beginning at 180 degree W and extending"
    " eastward through 360 arc degrees of longitude. These zones are"
    " lettered from A to Z inclusive (omitting I and O). Between 60 degree"
    " N and 90 degree N and between 60 degree S and 90 degree S there are"
    " 12 longitudinal zones of megatiles each of 30 arc degrees width"
    " beginning at 180 degree W and extending eastward through 360 arc"
    " degrees of longitude. These zones are lettered as A, C, E, G, J, L,"
    " N, Q, S, U, W and Y. There are 12 latitudinal bands of megatiles each"
    " of 15 arc degrees height, beginning at 90 degree S and extending"
    " northward through 180 arc degrees of latitude. These are lettered"
    " from A to M inclusive (omitting I). This 2 letter designation thus"
    " divides the earth's surface into 288 GTRS megatiles. The index of a"
    " GTRS geotile within a GTRS megatile is based on the location of its"
    " south-west corner and is composed of two digits designating the"
    " relative longitudinal position of the geotile followed by two digits"
    " designating the relative latitudinal position of the geotile. Between"
    " 60 degree N and 60 degree S there are 15 longitudinal zones of"
    " geotiles within a megatile, each of 1 arc degree width extending"
    " eastward from the western edge of the megatile. These zones are"
    " numbered from 00 to 14 inclusive. Between 60 degree and 71 degree (N"
    " or S) there are 15 longitudinal zones of geotiles within a megatile,"
    " each of 2 arc degrees width extending eastward from the western edge"
    " of the megatile. These zones are even numbered from 00 to 28"
    " inclusive. Between 71 degreeo and 78 degree (N or S) there are 10"
    " longitudinal zones of geotiles within a megatile, each of 3 arc"
    " degrees width extending eastward from the western edge of the"
    " megatile. These zones are numbered 00, 03, 06, 09, 12, 15, 18, 21, 24"
    " and 27. Between 78 degree and 80 degree (N or S) there are 6"
    " longitudinal zones of geotiles within a megatile, each of 5 arc"
    " degrees width extending eastward from the western edge of the"
    " megatile. These zones are numbered 00, 05, 10, 15, 20 and 25. Between"
    " 80 degree and 84 degree (N or S) there are 5 longitudinal zones of"
    " geotiles within a megatile, each of 6 arc degrees width extending"
    " eastward from the western edge of the megatile. These zones are"
    " numbered 00, 06, 12, 18 and 24. Between 84 degree and 86 degree (N or"
    " S) there are 3 longitudinal zones of geotiles within a megatile, each"
    " of 10 arc degrees width extending eastward from the western edge of"
    " the megatile. These zones are numbered 00, 10 and 20. Between 86"
    " degreeo and 88 degree (N or S) there are 2 longitudinal zones of"
    " geotiles within a megatile, each of 15 arc degrees width extending"
    " eastward from the western edge of the megatile. These zones are"
    " numbered 00 and 15. Between 88 degree and 90 degree (N or S) there is"
    " a single longitudinal zone of geotiles within a megatile of 30 arc"
    " degrees. This zone is numbered 00. There are 15 latitudinal bands of"
    " geotiles within a megatile, each of 1 arc degree height, extending"
    " northward from the southern edge of the megatile. These bands are"
    " numbered from 00 to 14 inclusive. This 2 letter designation thus"
    " divides a GTRS megatile into as many as 225 GTRS geotiles. EXAMPLE"
    " The location 24 degree N 37 degree E corresponds to the south-west"
    " corner of the GTRS geotile designated \"QH0709\".",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[1106]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GTRS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GUIDED_MISSILE_DESTROYER_TYPE,
    "GUIDED_MISSILE_DESTROYER_TYPE", "EAC_GUIDED_MISSILE_DESTROYER_TYPE",
    "The type of a <GUIDED_MISSILE_DESTROYER>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[1022]), 2, &(EDCS_Enumerant_Dictionary[2811]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GUIDED_MISSILE_FRIGATE_TYPE,
    "GUIDED_MISSILE_FRIGATE_TYPE", "EAC_GUIDED_MISSILE_FRIGATE_TYPE",
    "The type of a <GUIDED_MISSILE_FRIGATE>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[1022]), 6, &(EDCS_Enumerant_Dictionary[2813]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_GUYED,
    "GUYED", "EAC_GUYED",
    "An indication that an <OBJECT> has support <WIRE>s; guyed.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[188]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GUG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HAIL_SIZE,
    "HAIL_SIZE", "EAC_HAIL_SIZE",
    "The <<OUTSIDE_DIAMETER>> of the largest <HAIL> observed; hail size.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[593]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"DOPPLER-WEATHER-RADAR-HAIL-INDEX hail size code\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HALLWAY_TYPE,
    "HALLWAY_TYPE", "EAC_HALLWAY_TYPE",
    "The type of a <HALLWAY>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[702]), 2, &(EDCS_Enumerant_Dictionary[2819]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HARBOUR_FACILITY_TYPE,
    "HARBOUR_FACILITY_TYPE", "EAC_HARBOUR_FACILITY_TYPE",
    "The type of operation and/or service supported by a <FACILITY> at a"
    " <HARBOUR>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[967]), 11, &(EDCS_Enumerant_Dictionary[2821]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FHC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HARBOUR_IDENTIFIER,
    "HARBOUR_IDENTIFIER", "EAC_HARBOUR_IDENTIFIER",
    "The textual identifier of a <HARBOUR>.",
    EDCS_AVT_STRING, 0,
    4, &(EGBindingForEA[963]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HID]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HAZARD_MARKER_TYPE,
    "HAZARD_MARKER_TYPE", "EAC_HAZARD_MARKER_TYPE",
    "The type of a <HAZARD_MARKER>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[32]), 13, &(EDCS_Enumerant_Dictionary[2832]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HAZARD_SEVERITY,
    "HAZARD_SEVERITY", "EAC_HAZARD_SEVERITY",
    "The severity of a hazard.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 4, &(EDCS_Enumerant_Dictionary[2845]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SOH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HAZARDOUS_GAS_TYPE,
    "HAZARDOUS_GAS_TYPE", "EAC_HAZARDOUS_GAS_TYPE",
    "The type of hazardous gas present within an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[93]), 4, &(EDCS_Enumerant_Dictionary[2849]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HEAVY_ICE_ACCRETION_PROBABILITY,
    "HEAVY_ICE_ACCRETION_PROBABILITY", "EAC_HEAVY_ICE_ACCRETION_PROBABILITY",
    "The probability of heavy accretion of <ICE> on the <SURFACE>s of"
    " <MARINE_OBJECT>s. Such accretion can occur on <SURFACE>s on top of,"
    " over, or near a <WATERBODY_SURFACE> when the ambient"
    " <<AIR_TEMPERATURE>> is equal to or below 271,15 kelvin (-2 degrees"
    " Celsius) and the <<WIND_SPEED>> is greater than or equal to 11,32"
    " metres per second (22 knots).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1090]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGC1, Chapter 7, \"ship ice accretion\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HEIGHT,
    "HEIGHT", "EAC_HEIGHT",
    "The vertical distance from a <LOCATION> on the base (lowest point) of"
    " an <OBJECT> to a <LOCATION> on its top (highest point) that gives the"
    " greatest value of distance; the height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HEIGHT_ABOVE_FLOOR,
    "HEIGHT_ABOVE_FLOOR", "EAC_HEIGHT_ABOVE_FLOOR",
    "The height measured vertically from a <FLOOR> to the <LOCATION> on the"
    " base (lowest point) of an <OBJECT> that gives the least value of"
    " height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HEIGHT_ABOVE_SURFACE_LEVEL,
    "HEIGHT_ABOVE_SURFACE_LEVEL", "EAC_HEIGHT_ABOVE_SURFACE_LEVEL",
    "The <<HEIGHT>> of an <OBJECT> on a <PLANETARY_SURFACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HGF and HGT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HEIGHT_ABOVE_WATERBODY_FLOOR,
    "HEIGHT_ABOVE_WATERBODY_FLOOR", "EAC_HEIGHT_ABOVE_WATERBODY_FLOOR",
    "The height of an <OBJECT> measured vertically from a <WATERBODY_FLOOR>"
    " to the base (lowest portion) of the <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[166]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HSB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HEIGHT_AGL,
    "HEIGHT_AGL", "EAC_HEIGHT_AGL",
    "The distance of an <OBJECT> above a <PLANETARY_SURFACE>; the height"
    " AGL.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.7.4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HELIPAD_COUNT,
    "HELIPAD_COUNT", "EAC_HELIPAD_COUNT",
    "The number of <HELICOPTER_LANDING_PAD>s associated with an <OBJECT>;"
    " the helipad count.",
    EDCS_AVT_COUNT, 0,
    3, &(EGBindingForEA[73]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY,
    "HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY", "EAC_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY",
    "The ratio, for a particular material <SURFACE> and unit solid angle"
    " about a particular reflection <DIRECTION>, of the reflected"
    " <<RADIANCE>> into that solid angle to the purely diffuse, total"
    " incident <<RADIANCE>> from the hemisphere above that <SURFACE>. This"
    " quantity is also defined as the integral over the incident hemisphere"
    " of the BRDF times the cosine of the angle between the surface normal"
    " and the incidence <DIRECTION> times the differential incident solid"
    " angle. It is a function of the <<REFLECTANCE_ZENITH_ANGLE_LOCAL>> and"
    " <<REFLECTANCE_AZIMUTH_LOCAL>> of the reflected <<RADIANCE>> and is"
    " spectral (a distribution function in <<WAVELENGTH>>); therefore the"
    " quantity is measured in terms of inverse <<WAVELENGTH>> bin size.",
    EDCS_AVT_REAL, EQC_INV_LENGTH,
    5, &(EGBindingForEA[476]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY,
    "HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY", "EAC_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY",
    "The ratio, for a particular material <SURFACE>, of the flux density"
    " reflected into the hemisphere above this <SURFACE> to the flux"
    " density incident upon it from all <DIRECTION>s within this"
    " hemisphere. This quantity is also defined as the ratio A/B, where A"
    " is the integral (over the incident hemisphere) of the incident"
    " <<RADIANCE>> times the cosine of the angle between the surface normal"
    " and the incident <DIRECTION> times the"
    " <<DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY>> times the unit solid"
    " incident angle and B is the same integral without the"
    " <<DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY>>. This quantity may also be"
    " known as the \"total\" or \"bi-hemispherical\" reflectivity and is"
    " spectral (a distribution function in <<WAVELENGTH>>); therefore the"
    " quantity is measured in terms of inverse <<WAVELENGTH>> bin size.",
    EDCS_AVT_REAL, EQC_INV_LENGTH,
    5, &(EGBindingForEA[476]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH,
    "HF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH", "EAC_HF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH",
    "The <<DEPTH_BELOW_WATERBODY_SURFACE>> of the lower (bottom) <BOUNDARY>"
    " of a high frequency scattering layer.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[768]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Volume Scattering Strength Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH,
    "HF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH", "EAC_HF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH",
    "The <<DEPTH_BELOW_WATERBODY_SURFACE>> of the upper (top) <BOUNDARY> of"
    " a high frequency scattering layer.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[768]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Volume Scattering Strength Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HF_BOTTOM_LOSS_REGION_IDENTIFIER,
    "HF_BOTTOM_LOSS_REGION_IDENTIFIER", "EAC_HF_BOTTOM_LOSS_REGION_IDENTIFIER",
    "In a <WATERBODY>, the numeric identifier of a high frequency bottom"
    " loss <REGION>.",
    EDCS_AVT_INDEX, 0,
    1, &(EGBindingForEA[24]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, High-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGH_CLOUD_BASE_LEVEL,
    "HIGH_CLOUD_BASE_LEVEL", "EAC_HIGH_CLOUD_BASE_LEVEL",
    "The <<CLOUD_BASE_LEVEL>> of a <HIGH_CLOUD>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO407]",
    "[WMO8]", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGH_CLOUD_COVERAGE,
    "HIGH_CLOUD_COVERAGE", "EAC_HIGH_CLOUD_COVERAGE",
    "The fraction of the sky covered by <HIGH_CLOUD>s.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cloud cover\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGH_CLOUD_GENUS,
    "HIGH_CLOUD_GENUS", "EAC_HIGH_CLOUD_GENUS",
    "The genus of a <HIGH_CLOUD>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 4, &(EDCS_Enumerant_Dictionary[2853]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.8.2.3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGH_CLOUD_TOP_LEVEL,
    "HIGH_CLOUD_TOP_LEVEL", "EAC_HIGH_CLOUD_TOP_LEVEL",
    "The <<CLOUD_TOP_LEVEL>> of a <HIGH_CLOUD>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO407]",
    "[GMET]", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGH_CLOUD_TYPE_OBSERVED,
    "HIGH_CLOUD_TYPE_OBSERVED", "EAC_HIGH_CLOUD_TYPE_OBSERVED",
    "The type of observed <HIGH_CLOUD>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 11, &(EDCS_Enumerant_Dictionary[2857]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, Volume 1, Code table 0516]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGHEST_AIRSPACE_ALTITUDE,
    "HIGHEST_AIRSPACE_ALTITUDE", "EAC_HIGHEST_AIRSPACE_ALTITUDE",
    "The greatest <<HEIGHT_AGL>> of all <LOCATION>s in or on the boundary"
    " of an <AIRSPACE>; the highest airspace altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[405]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AV2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGHEST_AIRSPACE_ALTITUDE_LIMIT,
    "HIGHEST_AIRSPACE_ALTITUDE_LIMIT", "EAC_HIGHEST_AIRSPACE_ALTITUDE_LIMIT",
    "The <<HIGHEST_AIRSPACE_ALTITUDE>> limit.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[361]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AZ2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGHEST_ANNUAL_GROUND_WATER_LEVEL,
    "HIGHEST_ANNUAL_GROUND_WATER_LEVEL", "EAC_HIGHEST_ANNUAL_GROUND_WATER_LEVEL",
    "The highest annual mean level of ground <WATER>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[808]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DP1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HIGHEST_ELEVATION,
    "HIGHEST_ELEVATION", "EAC_HIGHEST_ELEVATION",
    "The greatest <<ELEVATION>> to any <LOCATION> associated with an"
    " <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ZVF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HINDUISM_DENOMINATIONAL_FAMILY,
    "HINDUISM_DENOMINATIONAL_FAMILY", "EAC_HINDUISM_DENOMINATIONAL_FAMILY",
    "The designation of a <NON_EMPTY_SET> of closely related Hindu"
    " religious traditions, often ones which were at one time part of a"
    " single movement but are now separate religious denominations; the"
    " Hinduism denominational family.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 4, &(EDCS_Enumerant_Dictionary[2868]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HISTORICAL_CLOUD_FREE_LINE_OF_SIGHT_CLIMATOLOGY,
    "HISTORICAL_CLOUD_FREE_LINE_OF_SIGHT_CLIMATOLOGY", "EAC_HISTORICAL_CLOUD_FREE_LINE_OF_SIGHT_CLIMATOLOGY",
    "The historical (climatology) probability of a line of sight free of"
    " <CLOUD>s.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HISTORICAL_SIGNIFICANCE,
    "HISTORICAL_SIGNIFICANCE", "EAC_HISTORICAL_SIGNIFICANCE",
    "The historical significance of a <STRUCTURE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 2, &(EDCS_Enumerant_Dictionary[2872]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: HSS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HORIZONTAL_CLEARANCE,
    "HORIZONTAL_CLEARANCE", "EAC_HORIZONTAL_CLEARANCE",
    "The horizontal distance available to pass a load that extends"
    " laterally beyond the wheels of a <GROUND_VEHICLE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HCA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HORIZONTAL_CLEARANCE_LIMITED,
    "HORIZONTAL_CLEARANCE_LIMITED", "EAC_HORIZONTAL_CLEARANCE_LIMITED",
    "An indication that limited <<HORIZONTAL_CLEARANCE>> is present.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HCC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HORIZONTAL_LOAD_BEARING_CAPACITY,
    "HORIZONTAL_LOAD_BEARING_CAPACITY", "EAC_HORIZONTAL_LOAD_BEARING_CAPACITY",
    "The maximum distributed load per unit <<AREA>> that a horizontal"
    " <SURFACE> can support; the horizontal load bearing capacity.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    2, &(EGBindingForEA[1314]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HOSPITAL_BED_CAPACITY,
    "HOSPITAL_BED_CAPACITY", "EAC_HOSPITAL_BED_CAPACITY",
    "The number of beds within a <HOSPITAL_BUILDING> or <MEDICAL_FACILITY>.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[1134]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HOUR_WITHIN_DAY,
    "HOUR_WITHIN_DAY", "EAC_HOUR_WITHIN_DAY",
    "The ordinal index of the hour within the day, starting with the number"
    " \"0\" at midnight.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HULK_TYPE,
    "HULK_TYPE", "EAC_HULK_TYPE",
    "The type of a <HULK>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 5, &(EDCS_Enumerant_Dictionary[2874]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HLK]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HUMAN_FUNCTION,
    "HUMAN_FUNCTION", "EAC_HUMAN_FUNCTION",
    "The function for which a <HUMAN> has responsibility.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[25]), 13, &(EDCS_Enumerant_Dictionary[2879]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HUMAN_ROLE,
    "HUMAN_ROLE", "EAC_HUMAN_ROLE",
    "The expected function of a <HUMAN> in a particular setting or"
    " situation; the human role [SOED, \"role\", 2.I].",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[25]), 13, &(EDCS_Enumerant_Dictionary[2892]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYDROGRAPHIC_BARRIER_TYPE,
    "HYDROGRAPHIC_BARRIER_TYPE", "EAC_HYDROGRAPHIC_BARRIER_TYPE",
    "The type of <BARRIER> to hydrographic flow that an <OBJECT> presents.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[148]), 7, &(EDCS_Enumerant_Dictionary[2905]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DWT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYDROGRAPHIC_DEPTH,
    "HYDROGRAPHIC_DEPTH", "EAC_HYDROGRAPHIC_DEPTH",
    "The least <<DEPTH>> of any <LOCATION> on an <OBJECT> that lies below"
    " the <WATERBODY_SURFACE>. The <<DEPTH>> is in reference to a"
    " <SURFACE_DATUM>; the hydrographic depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYDROGRAPHIC_DEPTH_CATEGORY,
    "HYDROGRAPHIC_DEPTH_CATEGORY", "EAC_HYDROGRAPHIC_DEPTH_CATEGORY",
    "A category describing the <<HYDROGRAPHIC_DEPTH>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[32]), 4, &(EDCS_Enumerant_Dictionary[2912]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VRR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYDROGRAPHIC_DEPTH_INFORMATION,
    "HYDROGRAPHIC_DEPTH_INFORMATION", "EAC_HYDROGRAPHIC_DEPTH_INFORMATION",
    "The accuracy or availability of <<HYDROGRAPHIC_DEPTH>> information for"
    " an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1245]), 4, &(EDCS_Enumerant_Dictionary[2916]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HDI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYDROGRAPHIC_DRYING_HEIGHT,
    "HYDROGRAPHIC_DRYING_HEIGHT", "EAC_HYDROGRAPHIC_DRYING_HEIGHT",
    "The elevation of a hydrographic <OBJECT> that tidal waters cover and"
    " uncover measured to the highest <LOCATION> on the <OBJECT> in"
    " reference to a <SOUNDING_DATUM>; the hydrographic drying height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1198]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HDH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYDROGRAPHIC_OBJECT_ORIGIN,
    "HYDROGRAPHIC_OBJECT_ORIGIN", "EAC_HYDROGRAPHIC_OBJECT_ORIGIN",
    "The origin of a hydrographic <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[981]), 3, &(EDCS_Enumerant_Dictionary[2920]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HOC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYDROGRAPHIC_SURVEY_CONTACT_TYPE,
    "HYDROGRAPHIC_SURVEY_CONTACT_TYPE", "EAC_HYDROGRAPHIC_SURVEY_CONTACT_TYPE",
    "The type of a <HYDROGRAPHIC_SURVEY_CONTACT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[46]), 2, &(EDCS_Enumerant_Dictionary[2923]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYDROLOGIC_PERMANENCE,
    "HYDROLOGIC_PERMANENCE", "EAC_HYDROLOGIC_PERMANENCE",
    "The persistence of a <HYDROLOGIC_OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1075]), 5, &(EDCS_Enumerant_Dictionary[2925]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HYC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE,
    "HYPSOGRAPHIC_PORTRAYAL_TYPE", "EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE",
    "The type of a hypsographic portrayal <LINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[32]), 23, &(EDCS_Enumerant_Dictionary[2930]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HQC]",
    "[SDLG], [DCW]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ICAO_AIRSPACE_CLASS,
    "ICAO_AIRSPACE_CLASS", "EAC_ICAO_AIRSPACE_CLASS",
    "The class of an ICAO <AIRSPACE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 7, &(EDCS_Enumerant_Dictionary[2953]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[IAN11, 2.6.1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ICE_COVERAGE_FRACTION,
    "ICE_COVERAGE_FRACTION", "EAC_ICE_COVERAGE_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of a <WATERBODY_SURFACE> that is covered by floating <ICE>."
    " Zero means no floating <ICE> is present and one means the"
    " <WATERBODY_SURFACE> is completely covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1090]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ICE_COVERED,
    "ICE_COVERED", "EAC_ICE_COVERED",
    "An indication that a <WATERBODY_SURFACE> is covered with <ICE>.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1093]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"HIGH-RESOLUTION-ICE-EDGE-NOISE under-ice code\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ICE_DRAFT_ROOT_MEAN_SQUARE,
    "ICE_DRAFT_ROOT_MEAN_SQUARE", "EAC_ICE_DRAFT_ROOT_MEAN_SQUARE",
    "The root-mean-square <<DEPTH>> of the layer of surface <ICE> within a"
    " delineated <WATERBODY_SURFACE_REGION>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ICE_KEEL_DENSITY,
    "ICE_KEEL_DENSITY", "EAC_ICE_KEEL_DENSITY",
    "The areal density of <ICE_KEEL>s within a delineated"
    " <WATERBODY_SURFACE_REGION>.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    3, &(EGBindingForEA[1090]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ICE_LAYER_THICKNESS,
    "ICE_LAYER_THICKNESS", "EAC_ICE_LAYER_THICKNESS",
    "The <<THICKNESS>> of a layer of <ICE> on a <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"HYDROLOGICAL-OBSERVATION ice thickness dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ICING_TYPE,
    "ICING_TYPE", "EAC_ICING_TYPE",
    "The type of any deposit or coating of <ICE> on an <OBJECT> caused by"
    " the impingement and freezing of liquid (usually supercooled)"
    " hydrometeors; the icing type.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[23]), 6, &(EDCS_Enumerant_Dictionary[2960]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IGNITION_FLASH_INTENSITY,
    "IGNITION_FLASH_INTENSITY", "EAC_IGNITION_FLASH_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the transient illumination intensity that is associated"
    " with an <OBJECT> and that has been induced by ignition of a"
    " combustible <MATERIAL>. EXAMPLE Launch of a <MUNITION>. Zero means no"
    " intensity at all and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[135]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.2, Bit: 16 (Launch Flash)]",
    "[EBEV, 4.3.1.1, Bit: 16 (Launcher)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ILLUMINANCE,
    "ILLUMINANCE", "EAC_ILLUMINANCE",
    "The photometric equivalent of irradiance that is obtained by"
    " integrating spectral irradiance weighted by luminous efficiency over"
    " the visible spectrum; the illuminance.",
    EDCS_AVT_REAL, EQC_RADIANT_ENERGY_FLUENCE,
    2, &(EGBindingForEA[873]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"illuminance\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ILLUMINANCE_DIRECT,
    "ILLUMINANCE_DIRECT", "EAC_ILLUMINANCE_DIRECT",
    "The amount of <<ILLUMINANCE>> that is direct (rather than diffuse).",
    EDCS_AVT_REAL, EQC_RADIANT_ENERGY_FLUENCE,
    2, &(EGBindingForEA[873]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ILLUMINANCE_DIRECT_FROM_PRINCIPAL_SOURCE,
    "ILLUMINANCE_DIRECT_FROM_PRINCIPAL_SOURCE", "EAC_ILLUMINANCE_DIRECT_FROM_PRINCIPAL_SOURCE",
    "The <<ILLUMINANCE_DIRECT>> from the principal source of illumination"
    " (for example: the <SUN> and/or an illumination flare).",
    EDCS_AVT_REAL, EQC_RADIANT_ENERGY_FLUENCE,
    3, &(EGBindingForEA[901]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IMO_ADOPTED,
    "IMO_ADOPTED", "EAC_IMO_ADOPTED",
    "An indication that an <OBJECT> has been adopted by the IMO.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: IAS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INCIDENCE_AZIMUTH_GEODETIC,
    "INCIDENCE_AZIMUTH_GEODETIC", "EAC_INCIDENCE_AZIMUTH_GEODETIC",
    "The <<VECTOR_AZIMUTH_GEODETIC>> toward the source of incident light"
    " (the <DIRECTION> negative to the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INCIDENCE_AZIMUTH_LOCAL,
    "INCIDENCE_AZIMUTH_LOCAL", "EAC_INCIDENCE_AZIMUTH_LOCAL",
    "The <<VECTOR_AZIMUTH_LOCAL>> toward the source of incident light (the"
    " <DIRECTION> negative to the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INCIDENCE_AZIMUTH_MAGNETIC,
    "INCIDENCE_AZIMUTH_MAGNETIC", "EAC_INCIDENCE_AZIMUTH_MAGNETIC",
    "The <<VECTOR_AZIMUTH_MAGNETIC>> toward the source of incident light"
    " (the <DIRECTION> negative to the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INCIDENCE_ELEV_ANGLE_HORIZONTAL,
    "INCIDENCE_ELEV_ANGLE_HORIZONTAL", "EAC_INCIDENCE_ELEV_ANGLE_HORIZONTAL",
    "The <<VECTOR_ELEV_ANGLE_HORIZONTAL>> toward the source of incident"
    " light (the <DIRECTION> negative to the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INCIDENCE_ELEV_ANGLE_LOCAL,
    "INCIDENCE_ELEV_ANGLE_LOCAL", "EAC_INCIDENCE_ELEV_ANGLE_LOCAL",
    "The <<VECTOR_ELEV_ANGLE_LOCAL>> toward the source of incident light"
    " (the <DIRECTION> negative to the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INCIDENCE_ZENITH_ANGLE_LOCAL,
    "INCIDENCE_ZENITH_ANGLE_LOCAL", "EAC_INCIDENCE_ZENITH_ANGLE_LOCAL",
    "The angle at a <LOCATION> on a <SURFACE> between the vectors A and B,"
    " where A is the surface normal vector and B is the <DIRECTION> from"
    " which the source light is incident on that point (the negative of the"
    " Poynting vector). The positive sense is clockwise when looking in the"
    " <DIRECTION> of the cross product AxB.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[529]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INFRARED_HEAT_FLUX,
    "INFRARED_HEAT_FLUX", "EAC_INFRARED_HEAT_FLUX",
    "The rate of flow (flux) of heat to a <SYSTEM> due to infrared"
    " radiation.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    3, &(EGBindingForEA[940]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INLAND_HYDROGRAPHIC_PERMANENCE,
    "INLAND_HYDROGRAPHIC_PERMANENCE", "EAC_INLAND_HYDROGRAPHIC_PERMANENCE",
    "The permanence of an inland hydrographic <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1349]), 3, &(EDCS_Enumerant_Dictionary[2966]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AHC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INLAND_WATER_OBSTRUCTION,
    "INLAND_WATER_OBSTRUCTION", "EAC_INLAND_WATER_OBSTRUCTION",
    "An indication that an <OBJECT> in <INLAND_WATER> is an obstruction to"
    " the movement of <VESSEL>s.",
    EDCS_AVT_BOOLEAN, 0,
    4, &(EGBindingForEA[153]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: IWO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INSIDE_DIAMETER,
    "INSIDE_DIAMETER", "EAC_INSIDE_DIAMETER",
    "The diameter of a cylindrical or spherical <OBJECT> measured using the"
    " inside <SURFACE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INSTALLATION_BUOY_TYPE,
    "INSTALLATION_BUOY_TYPE", "EAC_INSTALLATION_BUOY_TYPE",
    "The type of an installation <BUOY>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[977]), 2, &(EDCS_Enumerant_Dictionary[2969]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: IBC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTEG_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION,
    "INTEG_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION", "EAC_INTEG_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION",
    "The ratio, for a particular material <SURFACE>, of the differential"
    " reflected <<RADIANCE>> into a unit solid angle about a particular"
    " (reflected) <DIRECTION> to the differential incident flux per unit"
    " surface <<AREA>> (irradiance) from a particular (incident)"
    " <DIRECTION>; bi-directional reflectance distribution function or"
    " directional-directional reflectance. This quantity is a function of"
    " the incident and reflected zenith and azimuth angles. This quantity"
    " is wavelength-band integrated, the units are inverse solid angle, and"
    " the particular band is specified separately.",
    EDCS_AVT_REAL, EQC_RECIPROCAL_SOLID_ANGLE,
    4, &(EGBindingForEA[481]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTEG_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY,
    "INTEG_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY", "EAC_INTEG_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY",
    "The ratio, for a particular material <SURFACE> and unit solid angle"
    " about a particular incident <DIRECTION>, of the reflected"
    " <<RADIANCE>> into the hemisphere above that <SURFACE> to the incident"
    " <<RADIANCE>>. This quantity is also defined as the integral over the"
    " reflected hemisphere of the BRDF times the cosine of the angle"
    " between the surface normal and the reflection <DIRECTION> times the"
    " differential reflection solid angle. It is a function of the zenith"
    " and azimuth angles of the incident light and is wavelength-band"
    " integrated; therefore the quantity is unitless and the particular"
    " band is specified separately.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[892]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTEG_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY,
    "INTEG_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY", "EAC_INTEG_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY",
    "The ratio, for a particular material <SURFACE> and unit solid angle"
    " about a particular reflection <DIRECTION>, of the reflected"
    " <<RADIANCE>> into that solid angle to the purely diffuse, total"
    " incident <<RADIANCE>> from the hemisphere above that <SURFACE>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[892]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTEG_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY,
    "INTEG_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY", "EAC_INTEG_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY",
    "The ratio, for a particular material <SURFACE> and unit solid angle"
    " about a particular reflection <DIRECTION>, of the reflected"
    " <<RADIANCE>> into that solid angle to the purely diffuse, total"
    " incident <<RADIANCE>> from the hemisphere above that <SURFACE>. This"
    " quantity is also defined as the integral over the incident hemisphere"
    " of the BRDF times the cosine of the angle between the surface normal"
    " and the incidence <DIRECTION> times the differential incident solid"
    " angle. It is a function of the zenith and azimuth angles of the"
    " reflected light and is wavelength-band integrated; therefore the"
    " quantity is unitless and the particular band is specified separately.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[892]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTERCHANGE_TRAVERSABILITY,
    "INTERCHANGE_TRAVERSABILITY", "EAC_INTERCHANGE_TRAVERSABILITY",
    "The traversability provided at a four-way <ROAD_INTERCHANGE> between"
    " the entry segments of adjacent <ROAD>s. Each entry segment"
    " necessarily connects to an opposing exiting segment (two pairs are"
    " thus formed) and optionally to either of the adjacent left or right"
    " entry segments. The first entry segment is that entering the"
    " interchange in the <DIRECTION> of the associated <BRIDGE_SPAN>; the"
    " remaining three entry segments are ordered in a counter-clockwise"
    " <DIRECTION> with the third entry serving as the exit for the first"
    " entry, and similarly the fourth for the second. Formatted in a Basic"
    " Latin string containing exactly four characters with the i^(th)"
    " character corresponding to traversability from the i^(th) entry (i ="
    " 1, 2, 3 and 4). Each character position in the string contains one of"
    " the characters N (no turns), R (right turn), L (left turn) or B (both"
    " right and left turn). EXAMPLE \"NRBL\" means no turns from first"
    " entry; right turn from second entry; right and left turn from third"
    " entry; and left turn from fourth entry.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTEREST_TYPE,
    "INTEREST_TYPE", "EAC_INTEREST_TYPE",
    "The reason an <OBJECT> is of interest.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 3, &(EDCS_Enumerant_Dictionary[2971]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: POI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTERIOR_AIR_EXCHANGE_RATE,
    "INTERIOR_AIR_EXCHANGE_RATE", "EAC_INTERIOR_AIR_EXCHANGE_RATE",
    "The number of complete exchanges of the interior <AIR> in a"
    " <STRUCTURE> per unit time; the interior air exchange rate.",
    EDCS_AVT_REAL, EQC_RATE,
    3, &(EGBindingForEA[571]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HVACS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTERIOR_LIGHTING_INTENSITY,
    "INTERIOR_LIGHTING_INTENSITY", "EAC_INTERIOR_LIGHTING_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the general internal <LIGHTING> of an"
    " <OBJECT>. Zero means unlit and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1180]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 29 (Interior Lights)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTERIOR_WALL_CONSTRUCTION_TYPE,
    "INTERIOR_WALL_CONSTRUCTION_TYPE", "EAC_INTERIOR_WALL_CONSTRUCTION_TYPE",
    "The type of <MATERIAL> and/or techniques used to construct an"
    " <INTERIOR_WALL>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 8, &(EDCS_Enumerant_Dictionary[2974]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTERNAL_FLOW_SPEED,
    "INTERNAL_FLOW_SPEED", "EAC_INTERNAL_FLOW_SPEED",
    "The <<SPEED>> of any internal convective flow within an <OBJECT>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_INTERNAL_TEMPERATURE,
    "INTERNAL_TEMPERATURE", "EAC_INTERNAL_TEMPERATURE",
    "The internal <<TEMPERATURE>> of a <MATERIAL> or <OBJECT>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[178]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IONOSPHERIC_SCINT_EAST_DRIFT,
    "IONOSPHERIC_SCINT_EAST_DRIFT", "EAC_IONOSPHERIC_SCINT_EAST_DRIFT",
    "The <<SPEED>> of eastward drift of the electromagnetic scintillation"
    " density irregularities in an <IONOSPHERE>.",
    EDCS_AVT_REAL, EQC_SPEED,
    4, &(EGBindingForEA[621]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IONSP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IONOSPHERIC_SCINT_MAXIMUM_SIZE,
    "IONOSPHERIC_SCINT_MAXIMUM_SIZE", "EAC_IONOSPHERIC_SCINT_MAXIMUM_SIZE",
    "The upper limit on the size of the electromagnetic scintillation"
    " density irregularities in an <IONOSPHERE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[589]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IONSP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IONOSPHERIC_SCINT_NORTH_DRIFT,
    "IONOSPHERIC_SCINT_NORTH_DRIFT", "EAC_IONOSPHERIC_SCINT_NORTH_DRIFT",
    "The <<SPEED>> of northward drift of the electromagnetic scintillation"
    " density irregularities in an <IONOSPHERE>.",
    EDCS_AVT_REAL, EQC_SPEED,
    4, &(EGBindingForEA[621]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IONSP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IONOSPHERIC_SCINT_PHASE_ALTITUDE,
    "IONOSPHERIC_SCINT_PHASE_ALTITUDE", "EAC_IONOSPHERIC_SCINT_PHASE_ALTITUDE",
    "The <<ALTITUDE_MSL>> of the equivalent electromagnetic scintillation"
    " phase screen in an <IONOSPHERE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[614]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IONSP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IONOSPHERIC_SCINT_STRUCTURE_ANGLE,
    "IONOSPHERIC_SCINT_STRUCTURE_ANGLE", "EAC_IONOSPHERIC_SCINT_STRUCTURE_ANGLE",
    "The angle between the electromagnetic scintillation irregularities and"
    " <LINE>s of the local <MAGNETIC_FIELD>; the ionospheric scintillation"
    " structure angle. If zero, all ionospheric plasma density"
    " irregularities are aligned along the local <MAGNETIC_FIELD>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[520]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IONSP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IONOSPHERIC_SCINT_UP_DRIFT,
    "IONOSPHERIC_SCINT_UP_DRIFT", "EAC_IONOSPHERIC_SCINT_UP_DRIFT",
    "The <<SPEED>> of upward drift of the electromagnetic scintillation"
    " density irregularities in an <IONOSPHERE>.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[678]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IONSP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_IRRIGATION_METHOD,
    "IRRIGATION_METHOD", "EAC_IRRIGATION_METHOD",
    "The method used to supply crops with <WATER>; the irrigation method.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[323]), 2, &(EDCS_Enumerant_Dictionary[2982]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ISLAMIC_DENOMINATIONAL_FAMILY,
    "ISLAMIC_DENOMINATIONAL_FAMILY", "EAC_ISLAMIC_DENOMINATIONAL_FAMILY",
    "The designation of a <NON_EMPTY_SET> of closely related Islamic"
    " religious denominations, often ones which were at one time part of a"
    " single movement but are now separate religious denominations; the"
    " Islamic denominational family.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 17, &(EDCS_Enumerant_Dictionary[2984]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ISOBARIC_SURFACE_LEVEL,
    "ISOBARIC_SURFACE_LEVEL", "EAC_ISOBARIC_SURFACE_LEVEL",
    "The <<ALTITUDE_MSL>> of a standard isobaric <SURFACE> in units"
    " proportional to the potential energy of unit <<MASS>> (geopotential)"
    " at that <SURFACE>.",
    EDCS_AVT_REAL, EQC_GEOPOTENTIAL_ENERGY_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, Part 1, symbolic code, \"hhh\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ISOLATED,
    "ISOLATED", "EAC_ISOLATED",
    "An indication that a <FACILITY> is isolated.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: ISS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ISOLATED_COMMUNICATION_LINE,
    "ISOLATED_COMMUNICATION_LINE", "EAC_ISOLATED_COMMUNICATION_LINE",
    "An indication that a communication line is in the open (isolated), as"
    " opposed to being in the midst of other <OBJECT>s (not isolated).",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[755]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CLI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_JAINISM_DENOMINATIONAL_FAMILY,
    "JAINISM_DENOMINATIONAL_FAMILY", "EAC_JAINISM_DENOMINATIONAL_FAMILY",
    "The designation of a <NON_EMPTY_SET> of closely related Jain religious"
    " denominations, often ones which were at one time part of a single"
    " movement but are now separate religious denominations; the Jainism"
    " denominational family.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 2, &(EDCS_Enumerant_Dictionary[3001]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_JUDAISM_DENOMINATIONAL_FAMILY,
    "JUDAISM_DENOMINATIONAL_FAMILY", "EAC_JUDAISM_DENOMINATIONAL_FAMILY",
    "The designation of a <NON_EMPTY_SET> of closely related Jewish"
    " religious denominations, often ones which were at one time part of a"
    " single movement but are now separate religious denominations; the"
    " Judaism denominational family.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 7, &(EDCS_Enumerant_Dictionary[3003]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_JULIAN_DATE_TERRESTRIAL_TIME,
    "JULIAN_DATE_TERRESTRIAL_TIME", "EAC_JULIAN_DATE_TERRESTRIAL_TIME",
    "The <<JULIAN_DAY>> number for the preceding noon plus the fraction of"
    " the day since that instant; the Julian date (terrestrial time). A"
    " Julian date (terrestrial time) begins at 12 hours 0 minutes 0"
    " seconds, and the length of a day is 86 400 seconds.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SIED, 2.26]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_JULIAN_DAY,
    "JULIAN_DAY", "EAC_JULIAN_DAY",
    "The Julian day number associated with the solar day defined as the"
    " number assigned to a day in a continuous count of days beginning with"
    " the Julian day number 0 assigned to the day starting at Greenwich"
    " mean noon on 1 January 4 713 BCE, Julian proleptic calendar -4 712.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SIED, 2.26]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_KELP_COVERAGE,
    "KELP_COVERAGE", "EAC_KELP_COVERAGE",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional coverage of kelp within a delineated <WATERBODY_REGION>."
    " Zero means no kelp is present and one means the <WATERBODY_REGION> is"
    " completely covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[1227]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DMK]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LADDER_PRESENT,
    "LADDER_PRESENT", "EAC_LADDER_PRESENT",
    "An indication that a fixed or moveable ladder is present within or on"
    " an <OBJECT>.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LAMBERT_LAW_CONSTANT,
    "LAMBERT_LAW_CONSTANT", "EAC_LAMBERT_LAW_CONSTANT",
    "The parameter used in the Lambert Law equation for calculating"
    " <WATERBODY_FLOOR> acoustic scattering; the Lambert Law constant.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[302]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_LAND_ROUTE_SLOPE_SEGMENT_LENGTH,
    "LAND_ROUTE_SLOPE_SEGMENT_LENGTH", "EAC_LAND_ROUTE_SLOPE_SEGMENT_LENGTH",
    "The length of a <LAND_TRANSPORTATION_ROUTE> segment having a slope"
    " (rise/run) greater than 0,07 for a <ROAD>, or greater than 0,03 for a"
    " <RAILWAY>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LOG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LAND_ROUTE_TYPE,
    "LAND_ROUTE_TYPE", "EAC_LAND_ROUTE_TYPE",
    "The type of a <LAND_TRANSPORTATION_ROUTE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 4, &(EDCS_Enumerant_Dictionary[3010]),
    EDCS_REF_TYP_INFORMATIVE, "[COSAM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LAND_ROUTE_USABLE_WEATHER_TYPE,
    "LAND_ROUTE_USABLE_WEATHER_TYPE", "EAC_LAND_ROUTE_USABLE_WEATHER_TYPE",
    "The type of weather conditions under which a"
    " <LAND_TRANSPORTATION_ROUTE> is usable.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[648]), 4, &(EDCS_Enumerant_Dictionary[3014]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE,
    "LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE", "EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE",
    "The composition of the <SURFACE> of a <LAND_TRANSPORTATION_ROUTE>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[1149]), 30, &(EDCS_Enumerant_Dictionary[3018]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RST]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LAND_TRNSP_MEDIAN_PRESENT,
    "LAND_TRNSP_MEDIAN_PRESENT", "EAC_LAND_TRNSP_MEDIAN_PRESENT",
    "An indication that a median divider is present between multiple"
    " <ROUTE_LANE>s or tracks in a <LAND_TRANSPORTATION_ROUTE>.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LAND_TRNSP_MEDIAN_WIDTH,
    "LAND_TRNSP_MEDIAN_WIDTH", "EAC_LAND_TRNSP_MEDIAN_WIDTH",
    "The <<WIDTH>> of the divider between multiple <ROUTE_LANE>s or tracks"
    " in a <LAND_TRANSPORTATION_ROUTE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LANDING_CRAFT_TYPE,
    "LANDING_CRAFT_TYPE", "EAC_LANDING_CRAFT_TYPE",
    "The type of a <LANDING_CRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 5, &(EDCS_Enumerant_Dictionary[3048]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LANDING_DISTANCE_AVAILABLE,
    "LANDING_DISTANCE_AVAILABLE", "EAC_LANDING_DISTANCE_AVAILABLE",
    "The <<LENGTH>> of a <RUNWAY> that is declared available and suitable"
    " for the ground run of an <AIRCRAFT> landing; the landing distance"
    " available.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[372]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[DAFIF, Sec. 201.B.37, \"Landing Distance Available\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LANDING_LIGHT_INTENSITY,
    "LANDING_LIGHT_INTENSITY", "EAC_LANDING_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of external <LIGHTING> on an <AIRCRAFT> that is"
    " used to illuminate the <LAND> during landing procedures. Zero means"
    " unlit and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[412]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.2, Bit: 12 (Landing Lights)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LANE_COUNT,
    "LANE_COUNT", "EAC_LANE_COUNT",
    "The number of <ROUTE_LANE>s in a <TRANSPORTATION_ROUTE>; the lane"
    " count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[49]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LANE_MARKING_TYPE,
    "LANE_MARKING_TYPE", "EAC_LANE_MARKING_TYPE",
    "The type of lane marking on a <ROAD> or <RUNWAY>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[395]), 5, &(EDCS_Enumerant_Dictionary[3053]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LARGE_SCALE_PRECIPITATION,
    "LARGE_SCALE_PRECIPITATION", "EAC_LARGE_SCALE_PRECIPITATION",
    "The component of <<ACCUM_PRECIP_DENSITY>> caused by a non-convective"
    " meteorological phenomenon in a mesoscale or larger <REGION>; the"
    " large scale precipitation.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LARGE_TANKER_DENSITY,
    "LARGE_TANKER_DENSITY", "EAC_LARGE_TANKER_DENSITY",
    "The areal density of large tanker <WATER_SURFACE_VESSEL>s (dead weight"
    " greater than 159 000 kilograms (approximately 175 000 tons) and less"
    " than or equal to 318 000 kilograms (approximately 350 000 tons);"
    " <<LENGTH>> of approximately 300 to 325 metres) in a"
    " <WATERBODY_SURFACE_REGION>.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    6, &(EGBindingForEA[995]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Historical Temporal Shipping Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LATENT_HEAT_FLUX,
    "LATENT_HEAT_FLUX", "EAC_LATENT_HEAT_FLUX",
    "The rate of heat flow per unit <<MASS>> for a <SYSTEM> in a"
    " reversible, isobaric-isothermic change of phase; the latent heat flux.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    2, &(EGBindingForEA[1319]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LATENT_HEAT_FUSION,
    "LATENT_HEAT_FUSION", "EAC_LATENT_HEAT_FUSION",
    "The amount of energy per unit <<MASS>> of an <OBJECT> required to"
    " change its <<PHYSICAL_STATE>> from solid to liquid; the latent heat"
    " of fusion.",
    EDCS_AVT_REAL, EQC_SPECIFIC_ENERGY,
    3, &(EGBindingForEA[139]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"latent heat (fusion)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LATENT_HEAT_SUBLIMATION,
    "LATENT_HEAT_SUBLIMATION", "EAC_LATENT_HEAT_SUBLIMATION",
    "The amount of energy per unit <<MASS>> of an <OBJECT> required to"
    " change its <<PHYSICAL_STATE>> from solid to gas; the latent heat of"
    " sublimation.",
    EDCS_AVT_REAL, EQC_SPECIFIC_ENERGY,
    3, &(EGBindingForEA[139]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"latent heat (sublimation)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LATENT_HEAT_VAPOURIZATION,
    "LATENT_HEAT_VAPOURIZATION", "EAC_LATENT_HEAT_VAPOURIZATION",
    "The amount of energy per unit <<MASS>> of an <OBJECT> required to"
    " change its <<PHYSICAL_STATE>> from liquid to gas; the latent heat of"
    " vapourization.",
    EDCS_AVT_REAL, EQC_SPECIFIC_ENERGY,
    3, &(EGBindingForEA[139]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"latent heat (vaporization)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEAF_AREA_INDEX,
    "LEAF_AREA_INDEX", "EAC_LEAF_AREA_INDEX",
    "The single sided leaf area (projected) per unit <<AREA>> of <LAND>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1220]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[ESRT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_ABOVE_BANK_ANGLE,
    "LEFT_ABOVE_BANK_ANGLE", "EAC_LEFT_ABOVE_BANK_ANGLE",
    "The angle from the horizontal plane to the portion above the mean"
    " level of the <WATERBODY_SURFACE> of the left <WATERBODY_BANK> (facing"
    " downstream) of a <WATERCOURSE>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BGL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_ABOVE_BANK_SLOPE,
    "LEFT_ABOVE_BANK_SLOPE", "EAC_LEFT_ABOVE_BANK_SLOPE",
    "The <<TERRAIN_SLOPE>> of the portion above the mean level of the"
    " <WATERBODY_SURFACE> of the left <WATERBODY_BANK> (facing downstream)"
    " of a <WATERCOURSE>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BGL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_BANK_HEIGHT,
    "LEFT_BANK_HEIGHT", "EAC_LEFT_BANK_HEIGHT",
    "The <<HEIGHT>> of the left <WATERBODY_BANK> (facing downstream) of a"
    " <WATERCOURSE> measured from the mean level of the <WATER> to the"
    " first break in <<TERRAIN_SLOPE>> above the mean level of the <WATER>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[15]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BHL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_BANK_SLOPE,
    "LEFT_BANK_SLOPE", "EAC_LEFT_BANK_SLOPE",
    "The <<TERRAIN_SLOPE>> of the left <WATERBODY_BANK> (facing downstream)"
    " of a <WATERCOURSE> measured from the mean level of the <WATER> to the"
    " first accessible break in slope above the mean level of the <WATER>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SL1 and SL2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_BANK_SOIL_CONE_INDEX,
    "LEFT_BANK_SOIL_CONE_INDEX", "EAC_LEFT_BANK_SOIL_CONE_INDEX",
    "The <<SOIL_CONE_INDEX>> of a left <WATERBODY_BANK>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    3, &(EGBindingForEA[1253]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_BANK_VEGETATION_DENSITY,
    "LEFT_BANK_VEGETATION_DENSITY", "EAC_LEFT_BANK_VEGETATION_DENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional density of <VEGETATION> found on the left <WATERBODY_BANK>"
    " (facing downstream) of a <WATERCOURSE> as a linearly-scaled fraction"
    " of bank <<AREA>>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1220]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BVL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_BELOW_BANK_ANGLE,
    "LEFT_BELOW_BANK_ANGLE", "EAC_LEFT_BELOW_BANK_ANGLE",
    "The angle from the horizontal plane to the portion below the mean"
    " level of the <WATERBODY_SURFACE> of the left <WATERBODY_BANK> (facing"
    " downstream) of a <WATERCOURSE>, below the mean level of the <WATER>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BWL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_BELOW_BANK_SLOPE,
    "LEFT_BELOW_BANK_SLOPE", "EAC_LEFT_BELOW_BANK_SLOPE",
    "The <<TERRAIN_SLOPE>> of the portion below the mean level of the"
    " <WATERBODY_SURFACE> of the left <WATERBODY_BANK> (facing downstream)"
    " of a <WATERCOURSE>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BWL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LEFT_TERRAIN_BANK_SLOPE,
    "LEFT_TERRAIN_BANK_SLOPE", "EAC_LEFT_TERRAIN_BANK_SLOPE",
    "The <<TERRAIN_SLOPE>> of the left bank of a <TERRAIN_SURFACE_OBJECT>"
    " (for example: a <TERRAIN_CUT> and/or an <EMBANKMENT>).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1304]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LENGTH,
    "LENGTH", "EAC_LENGTH",
    "The length measured in the horizontal plane of the longer of two"
    " orthogonal linear axes of an <OBJECT>; the length. For a square"
    " <OBJECT>, either axis may be measured. For a round <OBJECT>, the"
    " <<OUTSIDE_DIAMETER>> is measured. For a <BRIDGE>, the distance"
    " between the <BRIDGE_PIER>s is measured.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LEF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH,
    "LF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH", "EAC_LF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH",
    "The <<DEPTH_BELOW_WATERBODY_SURFACE>> of the lower (bottom) <BOUNDARY>"
    " of a low frequency scattering layer.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[768]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Volume Scattering Strength Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH,
    "LF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH", "EAC_LF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH",
    "The <<DEPTH_BELOW_WATERBODY_SURFACE>> of the upper (top) boundary of a"
    " low frequency scattering layer.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[768]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Volume Scattering Strength Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LF_BOTTOM_LOSS_REGION_IDENTIFIER,
    "LF_BOTTOM_LOSS_REGION_IDENTIFIER", "EAC_LF_BOTTOM_LOSS_REGION_IDENTIFIER",
    "In a <WATERBODY>, the numeric identifier of a low frequency bottom"
    " loss <REGION>.",
    EDCS_AVT_INDEX, 0,
    2, &(EGBindingForEA[1116]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIFT_TYPE,
    "LIFT_TYPE", "EAC_LIFT_TYPE",
    "The type of a <LIFT> based on the kind of <OBJECT>s it is intended to"
    " transport.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 2, &(EDCS_Enumerant_Dictionary[3058]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIFTED_ATMOSPHERE_STABILITY_INDEX,
    "LIFTED_ATMOSPHERE_STABILITY_INDEX", "EAC_LIFTED_ATMOSPHERE_STABILITY_INDEX",
    "A stability index used to determine the occurrence of severe weather;"
    " the lifted atmosphere stability index. The lifted atmosphere"
    " stability index, LI, is defined by LI = T[sub(5)] -"
    " LT[sub(S)](degrees Celsius), where T[sub(5)] is the dry-bulb"
    " <<AIR_TEMPERATURE>> at 500 hectopascals and LT[sub(S)] is the"
    " <<AIR_TEMPERATURE>> of a parcel of <AIR> at the <PLANETARY_SURFACE>"
    " lifted adiabatically to 500 hectopascals.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"lifted index - LI\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIFTING_CAPACITY,
    "LIFTING_CAPACITY", "EAC_LIFTING_CAPACITY",
    "The maximum weight that an <EQUIPMENT> can lift; the lifting capacity.",
    EDCS_AVT_REAL, EQC_MASS,
    2, &(EGBindingForEA[789]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_BEAM_SPREAD,
    "LIGHT_BEAM_SPREAD", "EAC_LIGHT_BEAM_SPREAD",
    "Twice the angle from the beam axis at which the intensity of a <LIGHT>"
    " is 10 percent of its maximum value; for an omni-directional light,"
    " 360 arc degrees; the light beam spread.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[543]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IEFE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_COLOUR,
    "LIGHT_COLOUR", "EAC_LIGHT_COLOUR",
    "The colour emitted from a <LIGHT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[725]), 8, &(EDCS_Enumerant_Dictionary[3060]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_ELEVATION,
    "LIGHT_ELEVATION", "EAC_LIGHT_ELEVATION",
    "The <<ELEVATION>> of a <LIGHT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1178]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: EOL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_EXHIBITION_CONDITION,
    "LIGHT_EXHIBITION_CONDITION", "EAC_LIGHT_EXHIBITION_CONDITION",
    "The exhibition condition of a <LIGHT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 4, &(EDCS_Enumerant_Dictionary[3068]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: EXCLIT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_FUNCTION,
    "LIGHT_FUNCTION", "EAC_LIGHT_FUNCTION",
    "The function of a <LIGHT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 18, &(EDCS_Enumerant_Dictionary[3072]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LFC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_ICE_ACCRETION_PROBABILITY,
    "LIGHT_ICE_ACCRETION_PROBABILITY", "EAC_LIGHT_ICE_ACCRETION_PROBABILITY",
    "The probability of light accretion of <ICE> on the <SURFACE>s of"
    " <MARINE_OBJECT>s. Such accretion can occur on <SURFACE>s on top of,"
    " over, or near a <WATERBODY_SURFACE> when the ambient"
    " <<AIR_TEMPERATURE>> is equal to or below 271,15 kelvin (-2 degrees"
    " Celsius) and the <<WIND_SPEED>> is greater than or equal to 11,32"
    " metres per second (22 knots).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    5, &(EGBindingForEA[1083]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGC1, Chapter 7, \"ship ice accretion\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_MULTIPLICITY,
    "LIGHT_MULTIPLICITY", "EAC_LIGHT_MULTIPLICITY",
    "The number of <LIGHT>s of identical character that exist as a"
    " co-located <SET>; the light multiplicity.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[29]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MOL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_PATTERN,
    "LIGHT_PATTERN", "EAC_LIGHT_PATTERN",
    "The type of sequence, grouping, and/or distinctive character of a"
    " <LIGHT>; the light pattern.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 41, &(EDCS_Enumerant_Dictionary[3090]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CHA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_PERIOD,
    "LIGHT_PERIOD", "EAC_LIGHT_PERIOD",
    "The <<TIME_QUANTITY>> occupied by an entire cycle of intervals of"
    " light and dark of a <LIGHT>; the light period.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1194]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PER]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_RELATIVE_LOCATION,
    "LIGHT_RELATIVE_LOCATION", "EAC_LIGHT_RELATIVE_LOCATION",
    "The relative horizontal <LOCATION> of a <LIGHT> in a range of two or"
    " three <LIGHT>s; the light relative position.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 4, &(EDCS_Enumerant_Dictionary[3131]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RGS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_SECTOR_ANGLE,
    "LIGHT_SECTOR_ANGLE", "EAC_LIGHT_SECTOR_ANGLE",
    "The horizontal angular sector limits of the visibility of a <LIGHT>;"
    " limits of sectors and arcs of visibility are arranged clockwise and"
    " are given from seaward toward the <LIGHT>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[512]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LSA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_SUPERVISED,
    "LIGHT_SUPERVISED", "EAC_LIGHT_SUPERVISED",
    "An indication that a <LIGHT> is supervised.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[29]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SUP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_TYPE,
    "LIGHT_TYPE", "EAC_LIGHT_TYPE",
    "The type of a <LIGHT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 3, &(EDCS_Enumerant_Dictionary[3135]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_VISIBILITY,
    "LIGHT_VISIBILITY", "EAC_LIGHT_VISIBILITY",
    "The type of specific visibility of a <LIGHT>, with respect to the"
    " intensity of the <LIGHT> and ease of recognition.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 8, &(EDCS_Enumerant_Dictionary[3138]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VIS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHT_VISIBILITY_RANGES,
    "LIGHT_VISIBILITY_RANGES", "EAC_LIGHT_VISIBILITY_RANGES",
    "A set of two numbers defining the range of visibility at a <LIGHT> in"
    " nautical miles; formatted in a Basic Latin string as a pair of"
    " numbers separated by a slash (\"/\") if only two visibilities exist"
    " or by a dash (\"-\") separating the greatest and least visibilities"
    " if three or more visibilities exist.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[29]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MLR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTING_CHARACTERIZATION,
    "LIGHTING_CHARACTERIZATION", "EAC_LIGHTING_CHARACTERIZATION",
    "The qualitative characterization of lighting intensity.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 3, &(EDCS_Enumerant_Dictionary[3146]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_CURRENT_STRENGTH,
    "LIGHTNING_CURRENT_STRENGTH", "EAC_LIGHTNING_CURRENT_STRENGTH",
    "The strength of the discharge current flowing in a stroke of"
    " <LIGHTNING>, usually in the return stroke.",
    EDCS_AVT_REAL, EQC_ELECTRIC_CURRENT,
    2, &(EGBindingForEA[605]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"lightning current\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_DATA_CONSISTENCY,
    "LIGHTNING_DATA_CONSISTENCY", "EAC_LIGHTNING_DATA_CONSISTENCY",
    "The quantity of the chi-square statistical agreement between"
    " cloud-to-ground detections of <LIGHTNING>; the lightning data"
    " consistency.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[470]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_DETECTOR_COUNT,
    "LIGHTNING_DETECTOR_COUNT", "EAC_LIGHTNING_DETECTOR_COUNT",
    "The number of detectors reporting a <LIGHTNING> discharge; the"
    " lightning detector count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[605]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_LOC_ERR_ELLPS_ANGLE,
    "LIGHTNING_LOC_ERR_ELLPS_ANGLE", "EAC_LIGHTNING_LOC_ERR_ELLPS_ANGLE",
    "The <<GEODETIC_AZIMUTH>> of the semi-major axis of the error ellipse"
    " of the <LOCATION> of a stroke of <LIGHTNING>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[496]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_LOC_ERR_ELLPS_MAJOR_AXIS,
    "LIGHTNING_LOC_ERR_ELLPS_MAJOR_AXIS", "EAC_LIGHTNING_LOC_ERR_ELLPS_MAJOR_AXIS",
    "The <<LENGTH>> of the semi-major axis of the error ellipse at the"
    " <LOCATION> of a stroke of <LIGHTNING>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[586]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_LOC_ERR_ELLPS_MINOR_AXIS,
    "LIGHTNING_LOC_ERR_ELLPS_MINOR_AXIS", "EAC_LIGHTNING_LOC_ERR_ELLPS_MINOR_AXIS",
    "The <<LENGTH>> of the semi-minor axis of the error ellipse at the"
    " <LOCATION> of a stroke of <LIGHTNING>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[586]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_POLARITY,
    "LIGHTNING_POLARITY", "EAC_LIGHTNING_POLARITY",
    "The polarity of a stroke of <LIGHTNING>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[605]), 2, &(EDCS_Enumerant_Dictionary[3149]),
    EDCS_REF_TYP_INFORMATIVE, "[GENM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_PROBABILITY,
    "LIGHTNING_PROBABILITY", "EAC_LIGHTNING_PROBABILITY",
    "The probability that <LIGHTNING> will occur.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[618]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_STROKE_COUNT,
    "LIGHTNING_STROKE_COUNT", "EAC_LIGHTNING_STROKE_COUNT",
    "The number of strokes of <LIGHTNING> that constitute a single"
    " <LIGHTNING> discharge; the lightning stroke count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[605]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIGHTNING_TIME_ADJUSTMENT,
    "LIGHTNING_TIME_ADJUSTMENT", "EAC_LIGHTNING_TIME_ADJUSTMENT",
    "The <<TIME_QUANTITY>> added to the observation time of a stroke of"
    " <LIGHTNING> to account for increased accuracy; the lightning time"
    " adjustment.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[628]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AAL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LINEAR_ATTENUATION_COEFFICIENT,
    "LINEAR_ATTENUATION_COEFFICIENT", "EAC_LINEAR_ATTENUATION_COEFFICIENT",
    "The coefficient denoting the rate of reduction in value over the unit"
    " <<LENGTH>>; the linear attenuation coefficient.",
    EDCS_AVT_REAL, EQC_INV_LENGTH,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIQUID_CAPACITY,
    "LIQUID_CAPACITY", "EAC_LIQUID_CAPACITY",
    "The amount of liquid an <OBJECT> is capable of carrying, storing, or"
    " delivering; the liquid capacity.",
    EDCS_AVT_REAL, EQC_VOLUME,
    3, &(EGBindingForEA[142]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LITTORAL_CURRENT_EAST_SPEED,
    "LITTORAL_CURRENT_EAST_SPEED", "EAC_LITTORAL_CURRENT_EAST_SPEED",
    "The <<WATER_CURRENT_SPEED>> in a <SURF_ZONE> in the geodetic east-west"
    " <DIRECTION>, where east is positive; the littoral current east speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LITTORAL_CURRENT_NORTH_SPEED,
    "LITTORAL_CURRENT_NORTH_SPEED", "EAC_LITTORAL_CURRENT_NORTH_SPEED",
    "The <<WATER_CURRENT_SPEED>> in a <SURF_ZONE> in the geodetic"
    " south-north <DIRECTION>, where north is positive; the littoral"
    " current north speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LITTORAL_CURRENT_U_SPEED,
    "LITTORAL_CURRENT_U_SPEED", "EAC_LITTORAL_CURRENT_U_SPEED",
    "The <<WATER_CURRENT_SPEED>> in a <SURF_ZONE> in the X <DIRECTION> of a"
    " projection-based coordinate system, where +X is positive; the"
    " littoral current \"U\" speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LITTORAL_CURRENT_V_SPEED,
    "LITTORAL_CURRENT_V_SPEED", "EAC_LITTORAL_CURRENT_V_SPEED",
    "The <<WATER_CURRENT_SPEED>> in a <SURF_ZONE> in the Y <DIRECTION> of a"
    " projection-based coordinate system, where +Y is positive; the"
    " littoral current \"V\" speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIVING_ORGANISM_COMMON_NAME,
    "LIVING_ORGANISM_COMMON_NAME", "EAC_LIVING_ORGANISM_COMMON_NAME",
    "A common name for a <LIVING_ORGANISM>.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[1104]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LIVING_ORGANISM_SCIENTIFIC_NAME,
    "LIVING_ORGANISM_SCIENTIFIC_NAME", "EAC_LIVING_ORGANISM_SCIENTIFIC_NAME",
    "The two-part Latinized name for a <LIVING_ORGANISM>, consisting of a"
    " capitalized generic name followed by a usually non-capitalized"
    " specific epithet; a scientific name or a binomial name.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[1104]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOAD_CLASS_ONE_WAY_TRACKED,
    "LOAD_CLASS_ONE_WAY_TRACKED", "EAC_LOAD_CLASS_ONE_WAY_TRACKED",
    "The dynamic live load weight-bearing capacity of a <BRIDGE> or"
    " <BRIDGE_SPAN> for one-way, tracked <GROUND_VEHICLE> traffic in MLC"
    " units; also known as the military load classification, type 3. MLC"
    " values are calculated in part from the size, cross-sectional shape,"
    " and <MATERIAL> of the stringers under the <BRIDGE_SPAN>s; they are"
    " similar to, but not the same as, short tons.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1153]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LC3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOAD_CLASS_ONE_WAY_WHEELED,
    "LOAD_CLASS_ONE_WAY_WHEELED", "EAC_LOAD_CLASS_ONE_WAY_WHEELED",
    "The dynamic live load weight-bearing capacity of a <BRIDGE> or"
    " <BRIDGE_SPAN> for one-way, wheeled <GROUND_VEHICLE> traffic in MLC"
    " units; also known as the military load classification, type 1. MLC"
    " values are calculated in part from the size, cross-sectional shape,"
    " and <MATERIAL> of the stringers under the <BRIDGE_SPAN>s; they are"
    " similar to, but not the same as, short tons.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1153]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LC1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOAD_CLASS_TWO_WAY_TRACKED,
    "LOAD_CLASS_TWO_WAY_TRACKED", "EAC_LOAD_CLASS_TWO_WAY_TRACKED",
    "The dynamic live load weight-bearing capacity of a <BRIDGE> or"
    " <BRIDGE_SPAN> for two-way, tracked <GROUND_VEHICLE> traffic in MLC"
    " units; also known as the military load classification, type 4. MLC"
    " values are calculated in part from the size, cross-sectional shape,"
    " and <MATERIAL> of the stringers under the <BRIDGE_SPAN>s; they are"
    " similar to, but not the same as, short tons.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1153]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LC4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOAD_CLASS_TWO_WAY_WHEELED,
    "LOAD_CLASS_TWO_WAY_WHEELED", "EAC_LOAD_CLASS_TWO_WAY_WHEELED",
    "The dynamic live load weight-bearing capacity of a <BRIDGE> or"
    " <BRIDGE_SPAN> for two-way, wheeled <GROUND_VEHICLE> traffic in MLC"
    " units; also known as the military load classification, type 2. MLC"
    " values are calculated in part from the size, cross-sectional shape,"
    " and <MATERIAL> of the stringers under the <BRIDGE_SPAN>s; they are"
    " similar to, but not the same as, short tons.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1153]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LC2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOCAL_AZIMUTH,
    "LOCAL_AZIMUTH", "EAC_LOCAL_AZIMUTH",
    "The <<VECTOR_AZIMUTH_LOCAL>> in the horizontal plane at the observer's"
    " location from an azimuthal reference vector, to either a <LINE>"
    " passing through the observer, or a vector relative to the observer,"
    " or the direction from the observer to an <OBJECT> or <LOCATION>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOCATION_ACCURACY_METHOD,
    "LOCATION_ACCURACY_METHOD", "EAC_LOCATION_ACCURACY_METHOD",
    "The method used to determine the accuracy of a <LOCATION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1245]), 9, &(EDCS_Enumerant_Dictionary[3151]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Attribute: QUAPOS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOCATION_ACCURACY_STATEMENT,
    "LOCATION_ACCURACY_STATEMENT", "EAC_LOCATION_ACCURACY_STATEMENT",
    "A statement of the accuracy of a <LOCATION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1245]), 7, &(EDCS_Enumerant_Dictionary[3160]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ACC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LONGEST_BRIDGE_SPAN_LENGTH,
    "LONGEST_BRIDGE_SPAN_LENGTH", "EAC_LONGEST_BRIDGE_SPAN_LENGTH",
    "The <<LENGTH>> of the longest <BRIDGE_SPAN> of a <BRIDGE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SPL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOW_CLOUD_BASE_LEVEL,
    "LOW_CLOUD_BASE_LEVEL", "EAC_LOW_CLOUD_BASE_LEVEL",
    "The <<CLOUD_BASE_LEVEL>> of a <LOW_CLOUD>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO407]",
    "[WMO8]", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOW_CLOUD_COVERAGE,
    "LOW_CLOUD_COVERAGE", "EAC_LOW_CLOUD_COVERAGE",
    "The fraction of the sky covered by <LOW_CLOUD>s.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cloud cover\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOW_CLOUD_GENUS,
    "LOW_CLOUD_GENUS", "EAC_LOW_CLOUD_GENUS",
    "The genus of a <LOW_CLOUD>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 5, &(EDCS_Enumerant_Dictionary[3167]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.8.2.1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOW_CLOUD_TOP_LEVEL,
    "LOW_CLOUD_TOP_LEVEL", "EAC_LOW_CLOUD_TOP_LEVEL",
    "The <<CLOUD_TOP_LEVEL>> of a <LOW_CLOUD>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO407]",
    "[WMO8]", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOW_CLOUD_TYPE_OBSERVED,
    "LOW_CLOUD_TYPE_OBSERVED", "EAC_LOW_CLOUD_TYPE_OBSERVED",
    "The type of observed <LOW_CLOUD>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 11, &(EDCS_Enumerant_Dictionary[3172]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.8.2.1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOWER_LAYER_SOIL_TEMPERATURE,
    "LOWER_LAYER_SOIL_TEMPERATURE", "EAC_LOWER_LAYER_SOIL_TEMPERATURE",
    "The <<TEMPERATURE>> of the <SOIL> between five and 100 centimetres"
    " below the <SURFACE> of the <TERRAIN>; the lower layer soil"
    " temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1288]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WEDER]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOWEST_AIRSPACE_ALTITUDE,
    "LOWEST_AIRSPACE_ALTITUDE", "EAC_LOWEST_AIRSPACE_ALTITUDE",
    "The least <<HEIGHT_AGL>> of all <LOCATION>s in or on the boundary of"
    " an <AIRSPACE>; the lowest airspace altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[405]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AV1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOWEST_AIRSPACE_ALTITUDE_LIMIT,
    "LOWEST_AIRSPACE_ALTITUDE_LIMIT", "EAC_LOWEST_AIRSPACE_ALTITUDE_LIMIT",
    "The <<LOWEST_AIRSPACE_ALTITUDE>> limit.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[361]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AZ1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOWEST_ANNUAL_GROUND_WATER_LEVEL,
    "LOWEST_ANNUAL_GROUND_WATER_LEVEL", "EAC_LOWEST_ANNUAL_GROUND_WATER_LEVEL",
    "The lowest annual mean level of ground <WATER>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[808]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DP2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOWEST_CLOUD_BASE_LEVEL,
    "LOWEST_CLOUD_BASE_LEVEL", "EAC_LOWEST_CLOUD_BASE_LEVEL",
    "The <<CLOUD_BASE_LEVEL>>of the lowest <CLOUD>; the lowest cloud base"
    " level.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, I.1, Part A, Section B: Symbolic Letters]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOWEST_CLOUD_COVER_CATEGORY,
    "LOWEST_CLOUD_COVER_CATEGORY", "EAC_LOWEST_CLOUD_COVER_CATEGORY",
    "A category indicating the fraction of the sky covered by <LOW_CLOUD>s"
    " or, if no <LOW_CLOUD>s are present, the fraction of the sky covered"
    " by <MIDDLE_CLOUD>s.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[442]), 11, &(EDCS_Enumerant_Dictionary[3183]),
    EDCS_REF_TYP_INFORMATIVE, "[WMO407, Paragraph II.7.3, \"Total cloud cover and cloud amount\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LOWEST_ELEVATION,
    "LOWEST_ELEVATION", "EAC_LOWEST_ELEVATION",
    "The least <<ELEVATION>> to any <LOCATION> associated with an <OBJECT>;"
    " the lowest elevation.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ZV6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LUMINOUS_LIGHT_RANGE,
    "LUMINOUS_LIGHT_RANGE", "EAC_LUMINOUS_LIGHT_RANGE",
    "The maximum distance at which a <LIGHT> can be seen under existing"
    " visibility conditions and taking no account of the <<HEIGHT_AGL>> of"
    " the <LIGHT>, the <<HEIGHT_AGL>> of the observer's eye, the curvature"
    " of the <EARTH>, or interference from background <LIGHTING>; the"
    " luminous light range.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[825]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LUNAR_DIFFUSED_IRRADIANCE,
    "LUNAR_DIFFUSED_IRRADIANCE", "EAC_LUNAR_DIFFUSED_IRRADIANCE",
    "The diffused lunar incident flux (irradiance) per unit <<AREA>> of the"
    " <SURFACE> of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    4, &(EGBindingForEA[904]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LUNAR_DIRECT_IRRADIANCE,
    "LUNAR_DIRECT_IRRADIANCE", "EAC_LUNAR_DIRECT_IRRADIANCE",
    "The direct lunar incident flux (irradiance) per unit <<AREA>> of the"
    " <SURFACE> of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    4, &(EGBindingForEA[904]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LUNAR_ILLUMINATION_FRACTION,
    "LUNAR_ILLUMINATION_FRACTION", "EAC_LUNAR_ILLUMINATION_FRACTION",
    "The fraction of the apparent circular disk of the <MOON> that is"
    " illuminated by the <SUN>; the lunar illumination fraction.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[888]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LUNAR_RADIANCE_AZIMUTH_GEODETIC,
    "LUNAR_RADIANCE_AZIMUTH_GEODETIC", "EAC_LUNAR_RADIANCE_AZIMUTH_GEODETIC",
    "The lunar <<INCIDENCE_AZIMUTH_GEODETIC>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[525]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_LUNAR_RADIANCE_ELEV_ANGLE_HORIZONTAL,
    "LUNAR_RADIANCE_ELEV_ANGLE_HORIZONTAL", "EAC_LUNAR_RADIANCE_ELEV_ANGLE_HORIZONTAL",
    "The lunar <<INCIDENCE_ELEV_ANGLE_HORIZONTAL>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[525]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_AZIMUTH,
    "MAGNETIC_AZIMUTH", "EAC_MAGNETIC_AZIMUTH",
    "The <<VECTOR_AZIMUTH_MAGNETIC>> in the horizontal plane at the"
    " observer's <LOCATION> to either a <LINE> passing through the"
    " observer, a vector relative to the observer, or the <DIRECTION> from"
    " the observer to an <OBJECT> or <LOCATION>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_A,
    "MAGNETIC_FIELD_A", "EAC_MAGNETIC_FIELD_A",
    "A 3-hourly equivalent amplitude index of geomagnetic activity at a"
    " specific solar electromagnetic flux <OBSERVATION_STATION> on the"
    " <EARTH>, related to the 3-hourly <<MAGNETIC_FIELD_K>> index and"
    " ranging in value from 0 to 400; the magnetic field A.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_A_DAILY,
    "MAGNETIC_FIELD_A_DAILY", "EAC_MAGNETIC_FIELD_A_DAILY",
    "A daily index of magnetic activity derived as the average of eight"
    " consecutive 3-hourly <<MAGNETIC_FIELD_A>> values.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_ANOMALY,
    "MAGNETIC_FIELD_ANOMALY", "EAC_MAGNETIC_FIELD_ANOMALY",
    "The difference between the <MAGNETIC_FIELD> of a <PLANET> declination"
    " of the disturbance <REGION> and the <MAGNETIC_FIELD> declination of"
    " the surrounding <REGION>; the magnetic field anomaly.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[533]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VAV]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_AP,
    "MAGNETIC_FIELD_AP", "EAC_MAGNETIC_FIELD_AP",
    "A daily averaged <<MAGNETIC_FIELD_A>> of a <PLANET> based on data from"
    " specific solar electromagnetic flux stations; the magnetic field"
    " A[sub(P)].",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_DECLINATION_ANGLE,
    "MAGNETIC_FIELD_DECLINATION_ANGLE", "EAC_MAGNETIC_FIELD_DECLINATION_ANGLE",
    "The declination angle between magnetic north and geodetic north of the"
    " <MAGNETIC_FIELD> of a <PLANET>. The value is determined as a"
    " horizontal angle measured east (positive value) or west (negative"
    " value) according to whether magnetic north lies east or west of"
    " geodetic north.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[533]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MAG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_EAST_COMPONENT,
    "MAGNETIC_FIELD_EAST_COMPONENT", "EAC_MAGNETIC_FIELD_EAST_COMPONENT",
    "The strength of the geodetic east vector component of the"
    " <MAGNETIC_FIELD> of a <PLANET>.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_FULL_COMPONENT,
    "MAGNETIC_FIELD_FULL_COMPONENT", "EAC_MAGNETIC_FIELD_FULL_COMPONENT",
    "The strength of the full vector component of the <MAGNETIC_FIELD> of a"
    " <PLANET>. The value is the vector sum of the"
    " <<MAGNETIC_FIELD_EAST_COMPONENT>>,"
    " <<MAGNETIC_FIELD_NORTH_COMPONENT>>, and"
    " <<MAGNETIC_FIELD_VERTICAL_COMPONENT>>.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_HORIZONTAL_COMPONENT,
    "MAGNETIC_FIELD_HORIZONTAL_COMPONENT", "EAC_MAGNETIC_FIELD_HORIZONTAL_COMPONENT",
    "The strength of the horizontal vector component of the"
    " <MAGNETIC_FIELD> of a <PLANET>. The value is the vector sum of the"
    " <<MAGNETIC_FIELD_EAST_COMPONENT>> and"
    " <<MAGNETIC_FIELD_NORTH_COMPONENT>>; the magnetic field horizontal"
    " component.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_INCLINATION_ANGLE,
    "MAGNETIC_FIELD_INCLINATION_ANGLE", "EAC_MAGNETIC_FIELD_INCLINATION_ANGLE",
    "The inclination angle between the <MAGNETIC_FIELD> of a <PLANET> and"
    " the local horizontal plane. The angle is positive downwards.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[533]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_K,
    "MAGNETIC_FIELD_K", "EAC_MAGNETIC_FIELD_K",
    "A 3-hourly quasi-logarithmic planetary index of magnetic activity,"
    " representing a value measuring the two horizontal (x,y) components of"
    " the <MAGNETIC_FIELD> at a specific solar electromagnetic flux"
    " <OBSERVATION_STATION> on the <EARTH>; the magnetic field K[sub(P)]."
    " K[sub(P)] = 0 represents a 2,5 nanoTesla variation from the quiet day"
    " value, and K[sub(P)] = 9 represents a 666 nanoTesla variation.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_K_DAILY,
    "MAGNETIC_FIELD_K_DAILY", "EAC_MAGNETIC_FIELD_K_DAILY",
    "A daily index of magnetic activity derived as the average of eight"
    " consecutive 3-hourly <<MAGNETIC_FIELD_K>> values.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_KP,
    "MAGNETIC_FIELD_KP", "EAC_MAGNETIC_FIELD_KP",
    "A daily averaged planetary <<MAGNETIC_FIELD_K>> based on data from"
    " specific solar electromagnetic flux stations; the magnetic field"
    " K[sub(P)].",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_NORMAL,
    "MAGNETIC_FIELD_NORMAL", "EAC_MAGNETIC_FIELD_NORMAL",
    "The strength of the <MAGNETIC_FIELD> of a <PLANET> as measured in"
    " orbit, in the <DIRECTION> normal to the plane formed by the spin axis"
    " of an <ARTIFICIAL_SATELLITE> and the <DIRECTION> of the <PLANET>.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_NORTH_COMPONENT,
    "MAGNETIC_FIELD_NORTH_COMPONENT", "EAC_MAGNETIC_FIELD_NORTH_COMPONENT",
    "The strength of the geodetic north vector component of the"
    " <MAGNETIC_FIELD> of a <PLANET>.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_PARALLEL,
    "MAGNETIC_FIELD_PARALLEL", "EAC_MAGNETIC_FIELD_PARALLEL",
    "The strength of the <MAGNETIC_FIELD> of a <PLANET> as measured in"
    " orbit, in the <DIRECTION> parallel to the spin axis of an"
    " <ARTIFICIAL_SATELLITE>.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_PLANETWARD,
    "MAGNETIC_FIELD_PLANETWARD", "EAC_MAGNETIC_FIELD_PLANETWARD",
    "The strength of the <MAGNETIC_FIELD> of a <PLANET> as measured in"
    " orbit, in the <DIRECTION> of the <PLANET>.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_TOTAL,
    "MAGNETIC_FIELD_TOTAL", "EAC_MAGNETIC_FIELD_TOTAL",
    "The strength of the <MAGNETIC_FIELD> of a <PLANET> as measured in"
    " orbit. The value is determined by the magnitude of the total"
    " <MAGNETIC_FIELD> vector.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_FIELD_VERTICAL_COMPONENT,
    "MAGNETIC_FIELD_VERTICAL_COMPONENT", "EAC_MAGNETIC_FIELD_VERTICAL_COMPONENT",
    "The strength of the vertical vector component of the <MAGNETIC_FIELD>"
    " of a <PLANET>.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SPWEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETIC_LOCAL_TIME,
    "MAGNETIC_LOCAL_TIME", "EAC_MAGNETIC_LOCAL_TIME",
    "The angle subtended at the geomagnetic axis between the geomagnetic"
    " midnight meridian and the meridian that passes through the location"
    " expressed as hours where 15 arc degrees is equivalent to 1 hour. The"
    " geomagnetic meridian containing the sub-solar point defines"
    " geomagnetic local noon and the opposite meridian defines geomagnetic"
    " midnight.",
    EDCS_AVT_REAL, EQC_TIME,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SEC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAGNETOSPHERE_PLASMA_FLUX,
    "MAGNETOSPHERE_PLASMA_FLUX", "EAC_MAGNETOSPHERE_PLASMA_FLUX",
    "The total flux of charged <PARTICLE>s (plasma) in a <MAGNETOSPHERE>.",
    EDCS_AVT_REAL, EQC_PARTICLE_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAINTAINED,
    "MAINTAINED", "EAC_MAINTAINED",
    "An indication that an <OBJECT> is maintained.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MAS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAN_MADE,
    "MAN_MADE", "EAC_MAN_MADE",
    "An indication that an <OBJECT> is man-made.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: ASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MANOEUVRE_DAMAGE_FRACTION,
    "MANOEUVRE_DAMAGE_FRACTION", "EAC_MANOEUVRE_DAMAGE_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the extent of physical injury/damage to an <OBJECT>"
    " affecting its capability to manoeuvre. Zero means no damage at all"
    " and one means completely immobilized.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[181]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 1 (Mobility)]",
    "[EBEV, 4.3.1.2, Bit: 1 (Propulsion)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARGINAL_ICE_ZONE_COVER_FRACTION,
    "MARGINAL_ICE_ZONE_COVER_FRACTION", "EAC_MARGINAL_ICE_ZONE_COVER_FRACTION",
    "A number between 0 and 1 inclusive representing the marginal ice zone"
    " cover as a linearly-scaled fraction of complete cover, where the"
    " <BOUNDARY> of the <ICE> is defined as occurring at 0,4.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1088]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_BEACON_SHAPE,
    "MARINE_BEACON_SHAPE", "EAC_MARINE_BEACON_SHAPE",
    "The characteristic geometric shape of a marine <BEACON>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[777]), 13, &(EDCS_Enumerant_Dictionary[3194]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SHP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_BOUNDARY_LIMIT_TYPE,
    "MARINE_BOUNDARY_LIMIT_TYPE", "EAC_MARINE_BOUNDARY_LIMIT_TYPE",
    "The type of limit <BOUNDARY> of a <MARINE_REGION>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[764]), 20, &(EDCS_Enumerant_Dictionary[3207]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MBL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_CONSTRUCTION_TYPE,
    "MARINE_CONSTRUCTION_TYPE", "EAC_MARINE_CONSTRUCTION_TYPE",
    "The type of construction used for a <MARINE_OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[19]), 4, &(EDCS_Enumerant_Dictionary[3227]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_LIGHT_SECTOR_INITIAL_ANGLE,
    "MARINE_LIGHT_SECTOR_INITIAL_ANGLE", "EAC_MARINE_LIGHT_SECTOR_INITIAL_ANGLE",
    "The initial limit of visibility of a <MARINE_LIGHT_SECTOR> expressed"
    " as a <<BEARING_FROM_SEAWARD>>; the marine light sector initial angle."
    " Limits of sectors and arcs of visibility are arranged clockwise with"
    " respect to the <LIGHT>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    5, &(EGBindingForEA[507]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LSI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_LIGHT_SECTOR_TERMINAL_ANGLE,
    "MARINE_LIGHT_SECTOR_TERMINAL_ANGLE", "EAC_MARINE_LIGHT_SECTOR_TERMINAL_ANGLE",
    "The terminal limit of visibility of a <MARINE_LIGHT_SECTOR> expressed"
    " as a <<BEARING_FROM_SEAWARD>>; the marine light sector terminal"
    " angle. Limits of sectors and arcs of visibility are arranged"
    " clockwise with respect to the <LIGHT>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    5, &(EGBindingForEA[507]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LST]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_LIGHT_TYPE,
    "MARINE_LIGHT_TYPE", "EAC_MARINE_LIGHT_TYPE",
    "The type of <LIGHT> used for marine navigation.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1019]), 8, &(EDCS_Enumerant_Dictionary[3231]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HLT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_LINE_ASSOCIATED_ATNAV,
    "MARINE_LINE_ASSOCIATED_ATNAV", "EAC_MARINE_LINE_ASSOCIATED_ATNAV",
    "The type and/or number of <AID_TO_NAVIGATION>s associated with a"
    " <MARINE_LEADING_LINE> or <MARINE_CLEARING_LINE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[777]), 9, &(EDCS_Enumerant_Dictionary[3239]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LAF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_LINE_ATNAV_DESCRIPTION,
    "MARINE_LINE_ATNAV_DESCRIPTION", "EAC_MARINE_LINE_ATNAV_DESCRIPTION",
    "A description of the <AID_TO_NAVIGATION>s that form a marine"
    " navigation <LINE>. EXAMPLE Description of a <MARINE_LEADING_LINE>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[777]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: CATNAV]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_NAVIGATION_LINE_TYPE,
    "MARINE_NAVIGATION_LINE_TYPE", "EAC_MARINE_NAVIGATION_LINE_TYPE",
    "The type of a marine navigation <LINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 3, &(EDCS_Enumerant_Dictionary[3248]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NLC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_OVERHEAD_OBSTRUCTION,
    "MARINE_OVERHEAD_OBSTRUCTION", "EAC_MARINE_OVERHEAD_OBSTRUCTION",
    "An indication that a <MARINE_ROUTE> has an <OVERHEAD_OBSTRUCTION>.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1037]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OWO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_PILOT_BOARDING_METHOD,
    "MARINE_PILOT_BOARDING_METHOD", "EAC_MARINE_PILOT_BOARDING_METHOD",
    "The pilot boarding method for <VESSEL>s using marine pilot services.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 3, &(EDCS_Enumerant_Dictionary[3251]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PBP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_PILOT_BOARDING_VEHICLE,
    "MARINE_PILOT_BOARDING_VEHICLE", "EAC_MARINE_PILOT_BOARDING_VEHICLE",
    "The <VEHICLE> by which marine pilots are transferred to and from"
    " <VESSEL>s using pilot services.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 2, &(EDCS_Enumerant_Dictionary[3254]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PBV]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_PILOT_DISTRICT,
    "MARINE_PILOT_DISTRICT", "EAC_MARINE_PILOT_DISTRICT",
    "The pilot district for which a marine pilot is responsible.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[1037]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PIL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_PORT_IDENTIFIER,
    "MARINE_PORT_IDENTIFIER", "EAC_MARINE_PORT_IDENTIFIER",
    "The textual identifier of a <MARINE_PORT>.",
    EDCS_AVT_STRING, 0,
    5, &(EGBindingForEA[958]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WPI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_REGION_TYPE,
    "MARINE_REGION_TYPE", "EAC_MARINE_REGION_TYPE",
    "The type of a <MARINE_REGION>, describing some aspect of significance"
    " to marine operations.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1039]), 149, &(EDCS_Enumerant_Dictionary[3256]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_RESCUE_STATION_TYPE,
    "MARINE_RESCUE_STATION_TYPE", "EAC_MARINE_RESCUE_STATION_TYPE",
    "The type of a marine rescue <PUBLIC_SERVICE_STATION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 8, &(EDCS_Enumerant_Dictionary[3405]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_ROUTE_TYPE,
    "MARINE_ROUTE_TYPE", "EAC_MARINE_ROUTE_TYPE",
    "The type of a <MARINE_ROUTE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 22, &(EDCS_Enumerant_Dictionary[3413]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RTT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_STATION_ACTIVITY,
    "MARINE_STATION_ACTIVITY", "EAC_MARINE_STATION_ACTIVITY",
    "The type of activity conducted at a marine station.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 26, &(EDCS_Enumerant_Dictionary[3435]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_STATION_EQUIPMENT,
    "MARINE_STATION_EQUIPMENT", "EAC_MARINE_STATION_EQUIPMENT",
    "The type of <EQUIPMENT> at a marine station.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[780]), 21, &(EDCS_Enumerant_Dictionary[3461]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_SURVEY_TYPE,
    "MARINE_SURVEY_TYPE", "EAC_MARINE_SURVEY_TYPE",
    "The type of a marine survey.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[46]), 6, &(EDCS_Enumerant_Dictionary[3482]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: SURTYP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_TONNAGE,
    "MARINE_TONNAGE", "EAC_MARINE_TONNAGE",
    "The tonnage of a <MARINE_WRECK>, a <HULK>, or other <VESSEL>.",
    EDCS_AVT_REAL, EQC_MASS,
    3, &(EGBindingForEA[1042]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TNG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_TRACK_TYPE,
    "MARINE_TRACK_TYPE", "EAC_MARINE_TRACK_TYPE",
    "The type of restrictions, <DIRECTION>, and other characteristics of"
    " marine tracks.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 5, &(EDCS_Enumerant_Dictionary[3488]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MTT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_TRAFFIC_SIGNAL_TYPE,
    "MARINE_TRAFFIC_SIGNAL_TYPE", "EAC_MARINE_TRAFFIC_SIGNAL_TYPE",
    "The type of a marine traffic signal.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[12]), 10, &(EDCS_Enumerant_Dictionary[3493]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SIT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_TSS_COMPONENT,
    "MARINE_TSS_COMPONENT", "EAC_MARINE_TSS_COMPONENT",
    "The type of <COMPONENT> of a marine <TRAFFIC_SEPARATION_SCHEME>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 7, &(EDCS_Enumerant_Dictionary[3503]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TSP]",
    "[S32, \"traffic separation scheme\"]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_USE,
    "MARINE_USE", "EAC_MARINE_USE",
    "The type of a <MARINE_OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[21]), 16, &(EDCS_Enumerant_Dictionary[3510]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: MUC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_WARNING_SIGNAL_TYPE,
    "MARINE_WARNING_SIGNAL_TYPE", "EAC_MARINE_WARNING_SIGNAL_TYPE",
    "The type of a marine warning signal station.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[12]), 15, &(EDCS_Enumerant_Dictionary[3526]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SAW]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_WRECK_STATUS,
    "MARINE_WRECK_STATUS", "EAC_MARINE_WRECK_STATUS",
    "The status of a <MARINE_WRECK>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 5, &(EDCS_Enumerant_Dictionary[3541]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WRK]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINE_WRECK_TYPE,
    "MARINE_WRECK_TYPE", "EAC_MARINE_WRECK_TYPE",
    "The type of a <MARINE_WRECK>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 54, &(EDCS_Enumerant_Dictionary[3546]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WKT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARINER_NOTICE_DATE,
    "MARINER_NOTICE_DATE", "EAC_MARINER_NOTICE_DATE",
    "The publication date of a Notice To Mariners. The date is formatted as"
    " specified by <<DATE_FORMAT>> or by <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[1034]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NMD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MARK_TYPE,
    "MARK_TYPE", "EAC_MARK_TYPE",
    "The type of a <MARINE_AID_TO_NAVIGATION> (for example: a <BEACON>"
    " and/or a <BUOY>). This type is evidenced using a mark, sign, or"
    " signal indicating the purpose of that <MARINE_AID_TO_NAVIGATION>.",
    EDCS_AVT_ENUMERATION, 0,
    5, &(EGBindingForEA[740]), 78, &(EDCS_Enumerant_Dictionary[3600]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: CATSPM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MASS,
    "MASS", "EAC_MASS",
    "The mass of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_MASS,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MASS_EXTINCTION_COEFFICIENT,
    "MASS_EXTINCTION_COEFFICIENT", "EAC_MASS_EXTINCTION_COEFFICIENT",
    "The ratio of the extinction coefficient to the <<MATERIAL_DENSITY>> of"
    " the transmission medium; alternatively, the natural logarithm of"
    " <<TRANSMISSIVITY>> divided by <<LENGTH>> of propagation and again by"
    " <<MATERIAL_DENSITY>>; the mass extinction coefficient.",
    EDCS_AVT_REAL, EQC_MASS_ATTENUATION_COEFF,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IEOS, 6.2.3.4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAST_TYPE,
    "MAST_TYPE", "EAC_MAST_TYPE",
    "The type of <EQUIPMENT> a <MAST> is intended to support.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[14]), 5, &(EDCS_Enumerant_Dictionary[3678]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MATERIAL_DENSITY,
    "MATERIAL_DENSITY", "EAC_MATERIAL_DENSITY",
    "The <<MASS>> per unit <<VOLUME>> of a <MATERIAL>; the material density.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MATERIAL_HANDLING_FACILITIES,
    "MATERIAL_HANDLING_FACILITIES", "EAC_MATERIAL_HANDLING_FACILITIES",
    "The <FACILITY>s available at a <LOCATION> or in the near vicinity for"
    " the handling of <MATERIAL>s.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[50]), 15, &(EDCS_Enumerant_Dictionary[3683]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MHF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAX_WATERBODY_TEMP_1_STD_DEV,
    "MAX_WATERBODY_TEMP_1_STD_DEV", "EAC_MAX_WATERBODY_TEMP_1_STD_DEV",
    "The <<WATERBODY_TEMPERATURE>> that is one standard deviation above a"
    " <<MEAN_WATERBODY_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAX_WATERBODY_TEMP_2_STD_DEV,
    "MAX_WATERBODY_TEMP_2_STD_DEV", "EAC_MAX_WATERBODY_TEMP_2_STD_DEV",
    "The <<WATERBODY_TEMPERATURE>> that is two standard deviations above a"
    " <<MEAN_WATERBODY_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAX_WATERBODY_TEMP_3_STD_DEV,
    "MAX_WATERBODY_TEMP_3_STD_DEV", "EAC_MAX_WATERBODY_TEMP_3_STD_DEV",
    "The <<WATERBODY_TEMPERATURE>> that is three standard deviations above"
    " a <<MEAN_WATERBODY_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_ACHIEVABLE_TEMPERATURE,
    "MAXIMUM_ACHIEVABLE_TEMPERATURE", "EAC_MAXIMUM_ACHIEVABLE_TEMPERATURE",
    "The maximum <<TEMPERATURE>> that a particular <MATERIAL> or <OBJECT>"
    " can achieve.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[178]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_AIR_TEMPERATURE,
    "MAXIMUM_AIR_TEMPERATURE", "EAC_MAXIMUM_AIR_TEMPERATURE",
    "The maximum <<AIR_TEMPERATURE>> that occurred at a given <LOCATION>"
    " during a specific <<TIME_PERIOD>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"maximum temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_AIR_TEMPERATURE_PERIOD,
    "MAXIMUM_AIR_TEMPERATURE_PERIOD", "EAC_MAXIMUM_AIR_TEMPERATURE_PERIOD",
    "The <<TIME_QUANTITY>> for which a <<MAXIMUM_AIR_TEMPERATURE>> was"
    " recorded.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[692]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"DAILY-WEATHER-SUMMARY maximum air temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_AUTHORIZED_ALTITUDE,
    "MAXIMUM_AUTHORIZED_ALTITUDE", "EAC_MAXIMUM_AUTHORIZED_ALTITUDE",
    "The highest altitude in an <AIR_TRANSPORTATION_ROUTE> at which"
    " adequate reception of <AID_TO_NAVIGATION> signals is assured; the"
    " maximum authorized altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[357]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MAA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_BREAKER_HEIGHT,
    "MAXIMUM_BREAKER_HEIGHT", "EAC_MAXIMUM_BREAKER_HEIGHT",
    "The <<MAXIMUM_WAVE_HEIGHT>> in a <SURF_ZONE>; the maximum breaker"
    " height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_CONTOUR_DEPTH,
    "MAXIMUM_CONTOUR_DEPTH", "EAC_MAXIMUM_CONTOUR_DEPTH",
    "The maximum <<DEPTH>> within a <WATERBODY_FLOOR_REGION> defined by a"
    " <DEPTH_CONTOUR_LINE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CVH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_CURRENT_SPEED,
    "MAXIMUM_CURRENT_SPEED", "EAC_MAXIMUM_CURRENT_SPEED",
    "The maximum <<WATER_CURRENT_SPEED>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CRX]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_DEW_POINT_TEMPERATURE,
    "MAXIMUM_DEW_POINT_TEMPERATURE", "EAC_MAXIMUM_DEW_POINT_TEMPERATURE",
    "The maximum <<DEW_POINT_TEMPERATURE>> from a series of samples.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"AIR-TEMPERATURE-LEVEL-SUMMARY maximum dew-point"
    " temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_FLIGHT_LEVEL,
    "MAXIMUM_FLIGHT_LEVEL", "EAC_MAXIMUM_FLIGHT_LEVEL",
    "The highest <FLIGHT_LEVEL> assigned by air traffic control; the"
    " maximum flight level. The values are expressed as flight level values"
    " by first dividing by 30,48 metres (100 feet) and then rounding to"
    " nearest 304,8 metres (1 000 feet) in accordance with the structure of"
    " the ICAO Standard Atmosphere. EXAMPLE The value for the 500"
    " hectopascals level is 180,0, corresponding to the ICAO standard"
    " height 5 574 metres (18 289 feet).",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[ISAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_ICE_KEEL_DRAFT,
    "MAXIMUM_ICE_KEEL_DRAFT", "EAC_MAXIMUM_ICE_KEEL_DRAFT",
    "The maximum <<DEPTH>> (draft) of <ICE_KEEL>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_OBSTACLE_HEIGHT,
    "MAXIMUM_OBSTACLE_HEIGHT", "EAC_MAXIMUM_OBSTACLE_HEIGHT",
    "The maximum height (or depth) of <TERRAIN_OBSTACLE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[1146]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OHD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL,
    "MAXIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL", "EAC_MAXIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL",
    "The maximum of a <SET> of <<OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL>>"
    " measurements.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_RADIANT_INTENSITY,
    "MAXIMUM_RADIANT_INTENSITY", "EAC_MAXIMUM_RADIANT_INTENSITY",
    "The intensity of electromagnetic radiation per unit solid angle in the"
    " <DIRECTION> for which the value is maximal; the maximum radiant"
    " intensity.",
    EDCS_AVT_REAL, EQC_RADIANT_INTENSITY,
    1, &(EGBindingForEA[16]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_STANDING_WATER_DEPTH,
    "MAXIMUM_STANDING_WATER_DEPTH", "EAC_MAXIMUM_STANDING_WATER_DEPTH",
    "The maximum depth of non-flowing/standing <WATER>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[847]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_TERRAIN_ELEVATION,
    "MAXIMUM_TERRAIN_ELEVATION", "EAC_MAXIMUM_TERRAIN_ELEVATION",
    "The maximum <<TERRAIN_ELEVATION>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1241]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_VERTICAL_CLEARANCE,
    "MAXIMUM_VERTICAL_CLEARANCE", "EAC_MAXIMUM_VERTICAL_CLEARANCE",
    "The greatest distance between a <LAND_TRANSPORTATION_ROUTE> and any"
    " obstruction vertically above it; the maximum vertical clearance.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MVC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_VISIBILITY_RANGE,
    "MAXIMUM_VISIBILITY_RANGE", "EAC_MAXIMUM_VISIBILITY_RANGE",
    "The maximum range of visibility into an <OBJECT> (for example: a"
    " forest).",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[116]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_VOLTAGE,
    "MAXIMUM_VOLTAGE", "EAC_MAXIMUM_VOLTAGE",
    "The maximum voltage available on an <ELECTRICAL_CABLE>.",
    EDCS_AVT_REAL, EQC_ELECTRIC_POTENTIAL,
    2, &(EGBindingForEA[859]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: KVA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_WATER_DEPTH,
    "MAXIMUM_WATER_DEPTH", "EAC_MAXIMUM_WATER_DEPTH",
    "The maximum <<WATER_DEPTH>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_WAVE_HEIGHT,
    "MAXIMUM_WAVE_HEIGHT", "EAC_MAXIMUM_WAVE_HEIGHT",
    "The mean <<HEIGHT>> of the highest tenth of <WATER_WAVE>s on a"
    " <WATERBODY_SURFACE>, measured from trough to crest.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGC1, Chapter 6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_WIND_GUST_SPREAD,
    "MAXIMUM_WIND_GUST_SPREAD", "EAC_MAXIMUM_WIND_GUST_SPREAD",
    "The maximum <<WIND_GUST_SPREAD>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-GUST-OBSERVATION maximum spread quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MAXIMUM_WIND_SPEED,
    "MAXIMUM_WIND_SPEED", "EAC_MAXIMUM_WIND_SPEED",
    "The maximum or peak <<WIND_SPEED>> including gusts.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_DENSITY_CLIM,
    "MEAN_AIR_DENSITY_CLIM", "EAC_MEAN_AIR_DENSITY_CLIM",
    "The mean historical (climatology) <<AIR_DENSITY>>.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_DENSITY_CLIM_STD_DEV,
    "MEAN_AIR_DENSITY_CLIM_STD_DEV", "EAC_MEAN_AIR_DENSITY_CLIM_STD_DEV",
    "The standard deviation of <<MEAN_AIR_DENSITY_CLIM>> measurements.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_TEMP,
    "MEAN_AIR_TEMP", "EAC_MEAN_AIR_TEMP",
    "The mean <<AIR_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_TEMP_CLIM,
    "MEAN_AIR_TEMP_CLIM", "EAC_MEAN_AIR_TEMP_CLIM",
    "The mean historical (climatology) <<AIR_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_TEMP_CLIM_STD_DEV,
    "MEAN_AIR_TEMP_CLIM_STD_DEV", "EAC_MEAN_AIR_TEMP_CLIM_STD_DEV",
    "The standard deviation of <<MEAN_AIR_TEMP_CLIM>> measurements.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_TEMP_DIFFERENCE_CLIM,
    "MEAN_AIR_TEMP_DIFFERENCE_CLIM", "EAC_MEAN_AIR_TEMP_DIFFERENCE_CLIM",
    "The historical (climatology) quantity of mean difference between the"
    " mean <<AIR_TEMPERATURE>> at an initial time and the mean"
    " <<AIR_TEMPERATURE>> at an offset from that time.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_TEMP_MAX_DIFFERENCE_CLIM,
    "MEAN_AIR_TEMP_MAX_DIFFERENCE_CLIM", "EAC_MEAN_AIR_TEMP_MAX_DIFFERENCE_CLIM",
    "The historical (climatology) quantity of maximum difference between"
    " the mean <<AIR_TEMPERATURE>> at an initial time and the mean"
    " <<AIR_TEMPERATURE>> at an offset from that time.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_TEMP_MIN_DIFFERENCE_CLIM,
    "MEAN_AIR_TEMP_MIN_DIFFERENCE_CLIM", "EAC_MEAN_AIR_TEMP_MIN_DIFFERENCE_CLIM",
    "The historical (climatology) quantity of minimum difference between"
    " the mean <<AIR_TEMPERATURE>> at an initial time and the mean"
    " <<AIR_TEMPERATURE>> at an offset from that time.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_WATER_TEMP_DIFF_CLIM_STD_DEV,
    "MEAN_AIR_WATER_TEMP_DIFF_CLIM_STD_DEV", "EAC_MEAN_AIR_WATER_TEMP_DIFF_CLIM_STD_DEV",
    "The standard deviation of <<MEAN_AIR_WATER_TEMP_DIFFERENCE>>"
    " measurements.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[689]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_AIR_WATER_TEMP_DIFFERENCE,
    "MEAN_AIR_WATER_TEMP_DIFFERENCE", "EAC_MEAN_AIR_WATER_TEMP_DIFFERENCE",
    "The mean difference between an <<AIR_TEMPERATURE>> and an adjacent"
    " <<WATERBODY_SURFACE_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[689]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_CLOUD_DROP_DIAMETER,
    "MEAN_CLOUD_DROP_DIAMETER", "EAC_MEAN_CLOUD_DROP_DIAMETER",
    "The mean <<OUTSIDE_DIAMETER>> of the drops of <WATER> in a <CLOUD>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[432]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_DEW_POINT_CLIMATOLOGY,
    "MEAN_DEW_POINT_CLIMATOLOGY", "EAC_MEAN_DEW_POINT_CLIMATOLOGY",
    "The mean of the historical (climatology) measured"
    " <<DEW_POINT_TEMPERATURE>>s.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_DEW_POINT_CLIMATOLOGY_STD_DEV,
    "MEAN_DEW_POINT_CLIMATOLOGY_STD_DEV", "EAC_MEAN_DEW_POINT_CLIMATOLOGY_STD_DEV",
    "The standard deviation of <<MEAN_DEW_POINT_CLIMATOLOGY>> measurements.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_DEW_POINT_TEMPERATURE,
    "MEAN_DEW_POINT_TEMPERATURE", "EAC_MEAN_DEW_POINT_TEMPERATURE",
    "The mean <<DEW_POINT_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_EVAP_TRANSPIRATION_RATE,
    "MEAN_EVAP_TRANSPIRATION_RATE", "EAC_MEAN_EVAP_TRANSPIRATION_RATE",
    "The mean rate of loss as a function of time of <WATER> from an"
    " <OBJECT> due to evaporation and transpiration.",
    EDCS_AVT_REAL, EQC_VOLUME_FLOW_RATE,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_GEOPOTENTIAL_ALT_CLIM,
    "MEAN_GEOPOTENTIAL_ALT_CLIM", "EAC_MEAN_GEOPOTENTIAL_ALT_CLIM",
    "The mean historical (climatology) altitude of <LOCATION>s in the"
    " <ATMOSPHERE> expressed into the geopotential of those altitudes.",
    EDCS_AVT_REAL, EQC_GEOPOTENTIAL_ENERGY_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_GEOPOTENTIAL_ALT_CLIM_STD_DEV,
    "MEAN_GEOPOTENTIAL_ALT_CLIM_STD_DEV", "EAC_MEAN_GEOPOTENTIAL_ALT_CLIM_STD_DEV",
    "The standard deviation of <<MEAN_GEOPOTENTIAL_ALT_CLIM>> measurements.",
    EDCS_AVT_REAL, EQC_GEOPOTENTIAL_ENERGY_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_ICE_DRAFT,
    "MEAN_ICE_DRAFT", "EAC_MEAN_ICE_DRAFT",
    "The mean <<DEPTH>> (draft) of <ICE> on a <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_ICE_DRAFT_STD_DEV,
    "MEAN_ICE_DRAFT_STD_DEV", "EAC_MEAN_ICE_DRAFT_STD_DEV",
    "The standard deviation of <<MEAN_ICE_DRAFT>> measurements.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_ICE_KEEL_DRAFT,
    "MEAN_ICE_KEEL_DRAFT", "EAC_MEAN_ICE_KEEL_DRAFT",
    "The mean <<DEPTH>> (draft) of <ICE_KEEL>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_ICE_KEEL_DRAFT_STD_DEV,
    "MEAN_ICE_KEEL_DRAFT_STD_DEV", "EAC_MEAN_ICE_KEEL_DRAFT_STD_DEV",
    "The standard deviation of <<MEAN_ICE_KEEL_DRAFT>> measurements.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_ICE_KEEL_SEPARATION,
    "MEAN_ICE_KEEL_SEPARATION", "EAC_MEAN_ICE_KEEL_SEPARATION",
    "The mean separation distance between <ICE_KEEL>s measured between the"
    " peaks of the <ICE_KEEL>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_ICE_KEEL_SEPARATION_STD_DEV,
    "MEAN_ICE_KEEL_SEPARATION_STD_DEV", "EAC_MEAN_ICE_KEEL_SEPARATION_STD_DEV",
    "The standard deviation of <<MEAN_ICE_KEEL_SEPARATION>> measurements.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_LUMINOUS_INTENSITY,
    "MEAN_LUMINOUS_INTENSITY", "EAC_MEAN_LUMINOUS_INTENSITY",
    "The mean luminous intensity of a <LIGHT> within its"
    " <<LIGHT_BEAM_SPREAD>>.",
    EDCS_AVT_REAL, EQC_LUMINANCE_INTENSITY,
    2, &(EGBindingForEA[873]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IEFE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_MAGNETIC_FIELD_DECLINATION_ANGLE,
    "MEAN_MAGNETIC_FIELD_DECLINATION_ANGLE", "EAC_MEAN_MAGNETIC_FIELD_DECLINATION_ANGLE",
    "The mean declination angle between magnetic north and geodetic north"
    " of the <MAGNETIC_FIELD> of a <PLANET>, typically averaged over one"
    " hour.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[533]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_MAGNETIC_FIELD_EAST_COMPONENT,
    "MEAN_MAGNETIC_FIELD_EAST_COMPONENT", "EAC_MEAN_MAGNETIC_FIELD_EAST_COMPONENT",
    "The mean <<MAGNETIC_FIELD_EAST_COMPONENT>> measured as a horizontal"
    " angle east (positive value) or west (negative value) according to"
    " whether magnetic north lies east or west of geodetic north, typically"
    " averaged over one hour.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_MAGNETIC_FIELD_FULL_COMPONENT,
    "MEAN_MAGNETIC_FIELD_FULL_COMPONENT", "EAC_MEAN_MAGNETIC_FIELD_FULL_COMPONENT",
    "The mean strength of the full vector component of the <MAGNETIC_FIELD>"
    " of a <PLANET> (vector sum of all components), typically averaged over"
    " one hour.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_MAGNETIC_FIELD_HORIZONTAL_COMPONENT,
    "MEAN_MAGNETIC_FIELD_HORIZONTAL_COMPONENT", "EAC_MEAN_MAGNETIC_FIELD_HORIZONTAL_COMPONENT",
    "The mean <<MAGNETIC_FIELD_HORIZONTAL_COMPONENT>> (vector sum of"
    " <<MAGNETIC_FIELD_EAST_COMPONENT>> and"
    " <<MAGNETIC_FIELD_NORTH_COMPONENT>>), typically averaged over one hour.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_MAGNETIC_FIELD_INCLINATION_ANGLE,
    "MEAN_MAGNETIC_FIELD_INCLINATION_ANGLE", "EAC_MEAN_MAGNETIC_FIELD_INCLINATION_ANGLE",
    "The mean <<MAGNETIC_FIELD_INCLINATION_ANGLE>>, typically averaged over"
    " one hour.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[533]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_MAGNETIC_FIELD_NORTH_COMPONENT,
    "MEAN_MAGNETIC_FIELD_NORTH_COMPONENT", "EAC_MEAN_MAGNETIC_FIELD_NORTH_COMPONENT",
    "The mean <<MAGNETIC_FIELD_NORTH_COMPONENT>>, typically averaged over"
    " one hour.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_MAGNETIC_FIELD_VERTICAL_COMPONENT,
    "MEAN_MAGNETIC_FIELD_VERTICAL_COMPONENT", "EAC_MEAN_MAGNETIC_FIELD_VERTICAL_COMPONENT",
    "The mean <<MAGNETIC_FIELD_VERTICAL_COMPONENT>>, typically averaged"
    " over one hour.",
    EDCS_AVT_REAL, EQC_MAGNETIC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_OBJECT_DIAMETER,
    "MEAN_OBJECT_DIAMETER", "EAC_MEAN_OBJECT_DIAMETER",
    "The mean diameter of individual <OBJECT>s within a delineated <REGION>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_OBJECT_SPACING,
    "MEAN_OBJECT_SPACING", "EAC_MEAN_OBJECT_SPACING",
    "The mean distance between the centroids of adjacent <OBJECT>s within a"
    " delineated <REGION>; the mean object spacing.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_POTENTIAL_SOIL_EVAP_TRANSPIRATION_RATE,
    "MEAN_POTENTIAL_SOIL_EVAP_TRANSPIRATION_RATE", "EAC_MEAN_POTENTIAL_SOIL_EVAP_TRANSPIRATION_RATE",
    "The mean rate of potential loss of <WATER> from the <SOIL> due to"
    " evaporation and transpiration.",
    EDCS_AVT_REAL, EQC_VOLUME_FLOW_RATE,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_PRIMARY_BREAKER_PERIOD,
    "MEAN_PRIMARY_BREAKER_PERIOD", "EAC_MEAN_PRIMARY_BREAKER_PERIOD",
    "The mean <<TIME_QUANTITY>> required for two successive primary"
    " breaking <WATER_WAVE> crests in a wave spectra to pass a fixed point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_PRIMARY_WAVE_PERIOD,
    "MEAN_PRIMARY_WAVE_PERIOD", "EAC_MEAN_PRIMARY_WAVE_PERIOD",
    "The mean <<TIME_QUANTITY>> required for two successive primary"
    " <WATER_WAVE> crests (combined <WIND_WAVE> and <SWELL_WAVE>) in a wave"
    " spectra to pass a fixed point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SECONDARY_BREAKER_PERIOD,
    "MEAN_SECONDARY_BREAKER_PERIOD", "EAC_MEAN_SECONDARY_BREAKER_PERIOD",
    "The mean <<TIME_QUANTITY>> required for two successive secondary"
    " breaking <WATER_WAVE> crests in a wave spectra to pass a fixed point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SECONDARY_WAVE_PERIOD,
    "MEAN_SECONDARY_WAVE_PERIOD", "EAC_MEAN_SECONDARY_WAVE_PERIOD",
    "The mean <<TIME_QUANTITY>> required for two successive secondary"
    " <WATER_WAVE> crests in a wave spectra to pass a fixed point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO306, I.2, Part B, GRIB Code Table 2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SOIL_EVAP_TRANSPIRATION_RATE,
    "MEAN_SOIL_EVAP_TRANSPIRATION_RATE", "EAC_MEAN_SOIL_EVAP_TRANSPIRATION_RATE",
    "The mean <<MEAN_EVAP_TRANSPIRATION_RATE >> of the <SOIL> of a"
    " <TERRAIN_SURFACE_REGION>.",
    EDCS_AVT_REAL, EQC_VOLUME_FLOW_RATE,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SOLAR_LONGWAVE_RADIATION,
    "MEAN_SOLAR_LONGWAVE_RADIATION", "EAC_MEAN_SOLAR_LONGWAVE_RADIATION",
    "The mean rate of change as a function of time of long wave (4 to 80"
    " micrometres) solar radiation incident on a <SURFACE>.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    4, &(EGBindingForEA[929]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SSNL_HIGH_WATER_DEPTH,
    "MEAN_SSNL_HIGH_WATER_DEPTH", "EAC_MEAN_SSNL_HIGH_WATER_DEPTH",
    "The mean seasonal high <<WATER_DEPTH>> in an <INLAND_WATER> exclusive"
    " of high water due to runoff.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[1057]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: YDH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SSNL_HIGH_WATER_SPEED,
    "MEAN_SSNL_HIGH_WATER_SPEED", "EAC_MEAN_SSNL_HIGH_WATER_SPEED",
    "The mean seasonal high <<WATER_CURRENT_SPEED>>, estimated within the"
    " delineation of an <INLAND_WATER>, exclusive of high water due to"
    " runoff.",
    EDCS_AVT_REAL, EQC_SPEED,
    4, &(EGBindingForEA[1068]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: YVH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SSNL_LOW_WATER_DEPTH,
    "MEAN_SSNL_LOW_WATER_DEPTH", "EAC_MEAN_SSNL_LOW_WATER_DEPTH",
    "The mean seasonal low <<WATER_DEPTH>> in an <INLAND_WATER> exclusive"
    " of low water due to drought.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[1057]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: YDL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SSNL_LOW_WATER_SPEED,
    "MEAN_SSNL_LOW_WATER_SPEED", "EAC_MEAN_SSNL_LOW_WATER_SPEED",
    "The mean seasonal low <<WATER_CURRENT_SPEED>> in an <INLAND_WATER>"
    " exclusive of low water due to drought.",
    EDCS_AVT_REAL, EQC_SPEED,
    4, &(EGBindingForEA[1068]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: YVL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_STEM_DIAMETER,
    "MEAN_STEM_DIAMETER", "EAC_MEAN_STEM_DIAMETER",
    "The mean <<STEM_DIAMETER>> of <VEGETATION> measured at a"
    " <<HEIGHT_AGL>> of 1,4 metres.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[827]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SDR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_STEM_SPACING,
    "MEAN_STEM_SPACING", "EAC_MEAN_STEM_SPACING",
    "The mean stem spacing of <VEGETATION> measured at a <<HEIGHT_AGL>> of"
    " 1,4 metres.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[827]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SWELL_WAVE_DIRECTION,
    "MEAN_SWELL_WAVE_DIRECTION", "EAC_MEAN_SWELL_WAVE_DIRECTION",
    "The mean <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which"
    " <SWELL_WAVE>s are arriving.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WAVE-FORECAST-ANALYSIS swell wave mean direction angle\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SWELL_WAVE_HEIGHT,
    "MEAN_SWELL_WAVE_HEIGHT", "EAC_MEAN_SWELL_WAVE_HEIGHT",
    "The mean <<HEIGHT>> of <SWELL_WAVE>s measured from trough to crest.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WAVE-FORECAST-ANALYSIS swell wave mean height dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_SWELL_WAVE_PERIOD,
    "MEAN_SWELL_WAVE_PERIOD", "EAC_MEAN_SWELL_WAVE_PERIOD",
    "The mean <<TIME_QUANTITY>> required for the crests of two successive"
    " <SWELL_WAVE>s to pass a fixed point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WAVE-FORECAST-ANALYSIS swell wave mean period quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_TERRAIN_ELEVATION,
    "MEAN_TERRAIN_ELEVATION", "EAC_MEAN_TERRAIN_ELEVATION",
    "The mean of <<TERRAIN_ELEVATION>>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1241]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_TERRAIN_ELEVATION_STD_DEV,
    "MEAN_TERRAIN_ELEVATION_STD_DEV", "EAC_MEAN_TERRAIN_ELEVATION_STD_DEV",
    "The standard deviation of <<MEAN_TERRAIN_ELEVATION>>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1241]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_TIDAL_WATER_DEPTH,
    "MEAN_TIDAL_WATER_DEPTH", "EAC_MEAN_TIDAL_WATER_DEPTH",
    "The mean <<DEPTH>> from a tidal <SURFACE_DATUM> to the"
    " <WATERBODY_FLOOR>; the mean tidal water depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[834]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WATERBODY_TEMP_STD_DEV,
    "MEAN_WATERBODY_TEMP_STD_DEV", "EAC_MEAN_WATERBODY_TEMP_STD_DEV",
    "The standard deviation of <<MEAN_WATERBODY_TEMPERATURE>>s.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WATERBODY_TEMPERATURE,
    "MEAN_WATERBODY_TEMPERATURE", "EAC_MEAN_WATERBODY_TEMPERATURE",
    "The mean of <<WATERBODY_TEMPERATURE>> measurements.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"OCEAN-CURRENT-STATISTIC-SET mean water temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WATER_DEPTH,
    "MEAN_WATER_DEPTH", "EAC_MEAN_WATER_DEPTH",
    "The mean of <<WATER_DEPTH>> measurements.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WDA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WATER_SPEED,
    "MEAN_WATER_SPEED", "EAC_MEAN_WATER_SPEED",
    "The mean <<WATER_CURRENT_SPEED>>, estimated within the delineation of"
    " a <WATERBODY>, exclusive of high <WATER_CURRENT>s due to runoff or"
    " low <WATER_CURRENT>s due to drought.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WAVE_DIRECTION,
    "MEAN_WAVE_DIRECTION", "EAC_MEAN_WAVE_DIRECTION",
    "The mean <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which"
    " significant <WATER_WAVE>s (combined <WIND_WAVE>s and <SWELL_WAVE>s)"
    " in the wave spectra are arriving.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WAVE_HEIGHT,
    "MEAN_WAVE_HEIGHT", "EAC_MEAN_WAVE_HEIGHT",
    "The mean apparent <<HEIGHT>> of <WATER_WAVE>s (combined <WIND_WAVE>s"
    " and <SWELL_WAVE>s) measured from trough to crest.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WAVE_HEIGHT_STD_DEV,
    "MEAN_WAVE_HEIGHT_STD_DEV", "EAC_MEAN_WAVE_HEIGHT_STD_DEV",
    "The standard deviation of <<MEAN_WAVE_HEIGHT>> measurements.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WAVE_LENGTH,
    "MEAN_WAVE_LENGTH", "EAC_MEAN_WAVE_LENGTH",
    "The mean distance between the crests of two successive <WATER_WAVE>s"
    " (combined <WIND_WAVE>s and <SWELL_WAVE>s); the mean wave length.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WAVE_PERIOD,
    "MEAN_WAVE_PERIOD", "EAC_MEAN_WAVE_PERIOD",
    "The mean <<TIME_QUANTITY>> required for two successive <WATER_WAVE>s"
    " (<WIND_WAVE> and <SWELL_WAVE>) in a wave spectra to pass a fixed"
    " point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WIND_SPEED,
    "MEAN_WIND_SPEED", "EAC_MEAN_WIND_SPEED",
    "The mean <<WIND_SPEED>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WIND_SPEED_STD_DEV,
    "MEAN_WIND_SPEED_STD_DEV", "EAC_MEAN_WIND_SPEED_STD_DEV",
    "The standard deviation of <<MEAN_WIND_SPEED>> measurements.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WIND_WAVE_HEIGHT,
    "MEAN_WIND_WAVE_HEIGHT", "EAC_MEAN_WIND_WAVE_HEIGHT",
    "The mean <<WIND_WAVE_HEIGHT>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WAVE-FORECAST-ANALYSIS significant wave height dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEAN_WIND_WAVE_PERIOD,
    "MEAN_WIND_WAVE_PERIOD", "EAC_MEAN_WIND_WAVE_PERIOD",
    "The mean <<TIME_QUANTITY>> required for the crests of two successive"
    " <WIND_WAVE>s to pass a fixed point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WAVE-SPECTRUM mean wave period quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEASUREMENT_DEPTH,
    "MEASUREMENT_DEPTH", "EAC_MEASUREMENT_DEPTH",
    "The depth below a <SURFACE> at which a measurement was taken.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MEASUREMENT_HEIGHT,
    "MEASUREMENT_HEIGHT", "EAC_MEASUREMENT_HEIGHT",
    "The <<HEIGHT>> above a <SURFACE> at which a measurement was taken.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[15]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MERCHANT_MARINE_VESSEL_TYPE,
    "MERCHANT_MARINE_VESSEL_TYPE", "EAC_MERCHANT_MARINE_VESSEL_TYPE",
    "The type of a <MERCHANT_MARINE_VESSEL>.",
    EDCS_AVT_ENUMERATION, 0,
    5, &(EGBindingForEA[1008]), 1, &(EDCS_Enumerant_Dictionary[3698]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MERCHANT_VESSEL_DENSITY,
    "MERCHANT_VESSEL_DENSITY", "EAC_MERCHANT_VESSEL_DENSITY",
    "The areal density of merchant <WATER_SURFACE_VESSEL>s (gross weight"
    " greater than 907 000 kilograms (approximately 1 000 tons); <<LENGTH>>"
    " greater than 18 metres) in a <WATERBODY_SURFACE_REGION>.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    7, &(EGBindingForEA[1001]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Historical Temporal Shipping Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MET_TRANSMISSITIVITY_DISTANCE,
    "MET_TRANSMISSITIVITY_DISTANCE", "EAC_MET_TRANSMISSITIVITY_DISTANCE",
    "The measured distance of a meteorological transmissivity observation.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[584]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MET_TRANSMISSITIVITY_WAVELENGTH,
    "MET_TRANSMISSITIVITY_WAVELENGTH", "EAC_MET_TRANSMISSITIVITY_WAVELENGTH",
    "The electromagnetic <<WAVELENGTH>> used for a meteorological"
    " transmissivity distance observation.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[586]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_METEOROLOGICAL_RANGE,
    "METEOROLOGICAL_RANGE", "EAC_METEOROLOGICAL_RANGE",
    "The distance at which an ideal observer can detect a high-contrast"
    " target assuming a detection contrast threshold of 0,02 and a target"
    " inherent contrast of 1,0; the meteorological range.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[825]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIDDLE_CLOUD_BASE_LEVEL,
    "MIDDLE_CLOUD_BASE_LEVEL", "EAC_MIDDLE_CLOUD_BASE_LEVEL",
    "The <<CLOUD_BASE_LEVEL>> of a <MIDDLE_CLOUD>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO407]",
    "[WMO8]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIDDLE_CLOUD_COVERAGE,
    "MIDDLE_CLOUD_COVERAGE", "EAC_MIDDLE_CLOUD_COVERAGE",
    "The fraction of the sky covered by <MIDDLE_CLOUD>s.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"cloud cover\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIDDLE_CLOUD_GENUS,
    "MIDDLE_CLOUD_GENUS", "EAC_MIDDLE_CLOUD_GENUS",
    "The genus of a <MIDDLE_CLOUD>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 4, &(EDCS_Enumerant_Dictionary[3699]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO407, Section II.8.2.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIDDLE_CLOUD_TOP_LEVEL,
    "MIDDLE_CLOUD_TOP_LEVEL", "EAC_MIDDLE_CLOUD_TOP_LEVEL",
    "The <<CLOUD_TOP_LEVEL>> of a <MIDDLE_CLOUD>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[453]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO407]",
    "[GMET]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIDDLE_CLOUD_TYPE_OBSERVED,
    "MIDDLE_CLOUD_TYPE_OBSERVED", "EAC_MIDDLE_CLOUD_TYPE_OBSERVED",
    "The type of observed <MIDDLE_CLOUD>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[427]), 11, &(EDCS_Enumerant_Dictionary[3703]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, Volume 1, Code table 0515]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MILITARY_ASSET_TYPE,
    "MILITARY_ASSET_TYPE", "EAC_MILITARY_ASSET_TYPE",
    "The type of a military asset. EXAMPLES <VEHICLE>, <EQUIPMENT>,"
    " <PERSONNEL>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 19, &(EDCS_Enumerant_Dictionary[3714]),
    EDCS_REF_TYP_INFORMATIVE, "[F3-01]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MILITARY_BRIDGE_INFORMATION,
    "MILITARY_BRIDGE_INFORMATION", "EAC_MILITARY_BRIDGE_INFORMATION",
    "Information identifying and/or describing a <BRIDGE>, typically one"
    " that is subject to preplanned military interdiction.",
    EDCS_AVT_STRING, 0,
    4, &(EGBindingForEA[1097]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MBI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MILITARY_FORCE_ALLEGIANCE,
    "MILITARY_FORCE_ALLEGIANCE", "EAC_MILITARY_FORCE_ALLEGIANCE",
    "The military allegiance of the force responsible for the creation or"
    " maintenance of a <MAN_MADE_OBJECT>. The value is specified in the"
    " following manner: (1) All allegiances are from the perspective of the"
    " nation or force providing the classification. The \"nation or force"
    " providing the classification\" is not defined in this International"
    " Standard and must be determined from the context in which this EA is"
    " used. (2) In a conflict that involves more than two mutual"
    " combatants, nine additional enumerants are defined for identification"
    " of the combatants. The number nine was chosen because, historically,"
    " more than nine groups are unlikely to simultaneously engage in mutual"
    " hostilities. (3) The groups identified by each of the nine additional"
    " enumerants are not defined in this International Standard and must be"
    " determined by the context in which this EA is used.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 12, &(EDCS_Enumerant_Dictionary[3733]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MILITARY_USE,
    "MILITARY_USE", "EAC_MILITARY_USE",
    "The type of use of a military <REGION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1302]), 7, &(EDCS_Enumerant_Dictionary[3745]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIN_WATERBODY_TEMP_1_STD_DEV,
    "MIN_WATERBODY_TEMP_1_STD_DEV", "EAC_MIN_WATERBODY_TEMP_1_STD_DEV",
    "The <<WATERBODY_TEMPERATURE>> that is one standard deviation below a"
    " <<MEAN_WATERBODY_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIN_WATERBODY_TEMP_2_STD_DEV,
    "MIN_WATERBODY_TEMP_2_STD_DEV", "EAC_MIN_WATERBODY_TEMP_2_STD_DEV",
    "The <<WATERBODY_TEMPERATURE>> that is two standard deviations below a"
    " <<MEAN_WATERBODY_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIN_WATERBODY_TEMP_3_STD_DEV,
    "MIN_WATERBODY_TEMP_3_STD_DEV", "EAC_MIN_WATERBODY_TEMP_3_STD_DEV",
    "The <<WATERBODY_TEMPERATURE>> that is three standard deviations below"
    " a <<MEAN_WATERBODY_TEMPERATURE>>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_ACOUSTIC_ACTUATION,
    "MINE_ACOUSTIC_ACTUATION", "EAC_MINE_ACOUSTIC_ACTUATION",
    "The type of acoustic actuation of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[284]), 4, &(EDCS_Enumerant_Dictionary[3752]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MIA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_ACTUATION,
    "MINE_ACTUATION", "EAC_MINE_ACTUATION",
    "The type of actuation of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 2, &(EDCS_Enumerant_Dictionary[3756]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MNA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_ALLEGIANCE,
    "MINE_ALLEGIANCE", "EAC_MINE_ALLEGIANCE",
    "The <<MILITARY_FORCE_ALLEGIANCE>> of the force responsible for the"
    " creation or maintenance of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 12, &(EDCS_Enumerant_Dictionary[3758]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MID]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_ANTI_HUNTING_TYPE,
    "MINE_ANTI_HUNTING_TYPE", "EAC_MINE_ANTI_HUNTING_TYPE",
    "The type of anti-hunting capability of an <EXPLOSIVE_NAVAL_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[991]), 7, &(EDCS_Enumerant_Dictionary[3770]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MSH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_ANTI_RECOVERY_TYPE,
    "MINE_ANTI_RECOVERY_TYPE", "EAC_MINE_ANTI_RECOVERY_TYPE",
    "The type of anti-recovery capability of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[991]), 3, &(EDCS_Enumerant_Dictionary[3777]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MSR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_ANTI_SWEEP_WIRE_TYPE,
    "MINE_ANTI_SWEEP_WIRE_TYPE", "EAC_MINE_ANTI_SWEEP_WIRE_TYPE",
    "The type of anti-sweep <WIRE> capability of an <EXPLOSIVE_NAVAL_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[991]), 5, &(EDCS_Enumerant_Dictionary[3780]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MSW]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_CABLELESS_ACTUATION,
    "MINE_CABLELESS_ACTUATION", "EAC_MINE_CABLELESS_ACTUATION",
    "The type of cableless control method of an <EXPLOSIVE_NAVAL_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[991]), 3, &(EDCS_Enumerant_Dictionary[3785]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MNL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_CAPABILITY_TYPE,
    "MINE_CAPABILITY_TYPE", "EAC_MINE_CAPABILITY_TYPE",
    "The type of capability of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[991]), 8, &(EDCS_Enumerant_Dictionary[3788]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MPO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_CHARGE_SIZE,
    "MINE_CHARGE_SIZE", "EAC_MINE_CHARGE_SIZE",
    "The <<MASS>> of an <EXPLOSIVE_MINE> charge; the mine charge size.",
    EDCS_AVT_REAL, EQC_MASS,
    1, &(EGBindingForEA[34]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MPG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_CONTACT_ACTUATION,
    "MINE_CONTACT_ACTUATION", "EAC_MINE_CONTACT_ACTUATION",
    "The type of independent contact actuation of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 3, &(EDCS_Enumerant_Dictionary[3796]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MIC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_CONTROL_METHOD,
    "MINE_CONTROL_METHOD", "EAC_MINE_CONTROL_METHOD",
    "The type of actuation control method of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 2, &(EDCS_Enumerant_Dictionary[3799]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MNC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_COUNT,
    "MINE_COUNT", "EAC_MINE_COUNT",
    "The number of <EXPLOSIVE_MINE>s within a <MINEFIELD>; the mine count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[34]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_COUNTERMEASURE_VESSEL_TYPE,
    "MINE_COUNTERMEASURE_VESSEL_TYPE", "EAC_MINE_COUNTERMEASURE_VESSEL_TYPE",
    "The type of a <WATER_SURFACE_VESSEL> designed for countermeasure or"
    " laying operations for <EXPLOSIVE_NAVAL_MINE>s.",
    EDCS_AVT_ENUMERATION, 0,
    5, &(EGBindingForEA[969]), 2, &(EDCS_Enumerant_Dictionary[3801]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_INDEPENDENT_ACTUATION,
    "MINE_INDEPENDENT_ACTUATION", "EAC_MINE_INDEPENDENT_ACTUATION",
    "The type of independent actuation of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 2, &(EDCS_Enumerant_Dictionary[3803]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MNI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_INFLUENCE_ACTUATION,
    "MINE_INFLUENCE_ACTUATION", "EAC_MINE_INFLUENCE_ACTUATION",
    "The type of actuation influences of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 4, &(EDCS_Enumerant_Dictionary[3805]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MII]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_INFORMATION_TYPE,
    "MINE_INFORMATION_TYPE", "EAC_MINE_INFORMATION_TYPE",
    "The special information characteristic type of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 3, &(EDCS_Enumerant_Dictionary[3809]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MSI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_MAGNETIC_SENSITIVITY,
    "MINE_MAGNETIC_SENSITIVITY", "EAC_MINE_MAGNETIC_SENSITIVITY",
    "The sensitivity of a magnetic activation <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[922]), 3, &(EDCS_Enumerant_Dictionary[3812]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MIM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_MOORED_POSITION_TYPE,
    "MINE_MOORED_POSITION_TYPE", "EAC_MINE_MOORED_POSITION_TYPE",
    "The position type of a moored <EXPLOSIVE_NAVAL_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[988]), 2, &(EDCS_Enumerant_Dictionary[3815]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MPM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_OPERATIONAL_USE,
    "MINE_OPERATIONAL_USE", "EAC_MINE_OPERATIONAL_USE",
    "The military operational use of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 6, &(EDCS_Enumerant_Dictionary[3817]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MSU]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_OTHER_ACTUATION_TYPE,
    "MINE_OTHER_ACTUATION_TYPE", "EAC_MINE_OTHER_ACTUATION_TYPE",
    "The type of actuation, independent of other actuation methods, of an"
    " <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 7, &(EDCS_Enumerant_Dictionary[3823]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MIO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_OTHER_INFORMATION_TYPE,
    "MINE_OTHER_INFORMATION_TYPE", "EAC_MINE_OTHER_INFORMATION_TYPE",
    "The subsidiary information for an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 5, &(EDCS_Enumerant_Dictionary[3830]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MAT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_POSITION_TYPE,
    "MINE_POSITION_TYPE", "EAC_MINE_POSITION_TYPE",
    "The type of position of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1239]), 2, &(EDCS_Enumerant_Dictionary[3835]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MPC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_SPECIAL_CAPABILITY_TYPE,
    "MINE_SPECIAL_CAPABILITY_TYPE", "EAC_MINE_SPECIAL_CAPABILITY_TYPE",
    "The type of special capabilities of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 14, &(EDCS_Enumerant_Dictionary[3837]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MSD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_STATUS,
    "MINE_STATUS", "EAC_MINE_STATUS",
    "The status of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 10, &(EDCS_Enumerant_Dictionary[3851]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_SWEPT,
    "MINE_SWEPT", "EAC_MINE_SWEPT",
    "An indication that a <WATERBODY_REGION> has been swept for"
    " <EXPLOSIVE_MINE>s.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[151]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: MSS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_TACTICAL_USE,
    "MINE_TACTICAL_USE", "EAC_MINE_TACTICAL_USE",
    "The military tactical use of an <EXPLOSIVE_MINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 9, &(EDCS_Enumerant_Dictionary[3861]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MMT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINE_TRACK_IDENTIFIER,
    "MINE_TRACK_IDENTIFIER", "EAC_MINE_TRACK_IDENTIFIER",
    "The numeric identifier of an <EXPLOSIVE_NAVAL_MINE> track.",
    EDCS_AVT_INDEX, 0,
    2, &(EGBindingForEA[1108]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MTN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINEFIELD_DELIVERY_METHOD,
    "MINEFIELD_DELIVERY_METHOD", "EAC_MINEFIELD_DELIVERY_METHOD",
    "The delivery method by which a <MINEFIELD> is created.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 4, &(EDCS_Enumerant_Dictionary[3870]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINEFIELD_TYPE,
    "MINEFIELD_TYPE", "EAC_MINEFIELD_TYPE",
    "The type of a <MINEFIELD> based on its functional purpose.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 7, &(EDCS_Enumerant_Dictionary[3874]),
    EDCS_REF_TYP_INFORMATIVE, "[F5-102]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_AIR_TEMPERATURE,
    "MINIMUM_AIR_TEMPERATURE", "EAC_MINIMUM_AIR_TEMPERATURE",
    "The lowest <<AIR_TEMPERATURE>> attained during a <<TIME_QUANTITY>>;"
    " the minimum air temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, page 396]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_AIR_TEMPERATURE_PERIOD,
    "MINIMUM_AIR_TEMPERATURE_PERIOD", "EAC_MINIMUM_AIR_TEMPERATURE_PERIOD",
    "The <<TIME_QUANTITY>> for which a <<MINIMUM_AIR_TEMPERATURE>> was"
    " recorded.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[692]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"DAILY-WEATHER-SUMMARY minimum air temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_CONTOUR_DEPTH,
    "MINIMUM_CONTOUR_DEPTH", "EAC_MINIMUM_CONTOUR_DEPTH",
    "The minimum depth within a <WATERBODY_FLOOR_REGION> defined by a"
    " <DEPTH_CONTOUR_LINE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CVL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_CURRENT_SPEED,
    "MINIMUM_CURRENT_SPEED", "EAC_MINIMUM_CURRENT_SPEED",
    "The minimum <<WATER_CURRENT_SPEED>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CRN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_DEW_POINT_TEMPERATURE,
    "MINIMUM_DEW_POINT_TEMPERATURE", "EAC_MINIMUM_DEW_POINT_TEMPERATURE",
    "The minimum <<DEW_POINT_TEMPERATURE>> from a series of samples.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_ENROUTE_ALTITUDE,
    "MINIMUM_ENROUTE_ALTITUDE", "EAC_MINIMUM_ENROUTE_ALTITUDE",
    "The lowest altitude between radio fixes that assures acceptable"
    " navigational signal coverage and meets obstacle clearance"
    " requirements; the minimum enroute altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[357]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_FLIGHT_LEVEL,
    "MINIMUM_FLIGHT_LEVEL", "EAC_MINIMUM_FLIGHT_LEVEL",
    "The lowest <FLIGHT_LEVEL> assigned by air traffic control; the minimum"
    " flight level. The values are expressed as flight level values by"
    " first dividing by 30,48 metres (100 feet) and then rounding to"
    " nearest 304,8 metres (1 000 feet) in accordance with the structure of"
    " the ICAO Standard Atmosphere. EXAMPLE The value for the 500"
    " hectopascals level is 180,0, corresponding to the ICAO standard"
    " height 5 574 metres (18 289 feet).",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[ISAC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_ICE_KEEL_DRAFT,
    "MINIMUM_ICE_KEEL_DRAFT", "EAC_MINIMUM_ICE_KEEL_DRAFT",
    "The minimum draft (depth) of <ICE_KEEL>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[813]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, ICECAP Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL,
    "MINIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL", "EAC_MINIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL",
    "The minimum of <<OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL>> measurements.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_SAFE_ALTITUDE,
    "MINIMUM_SAFE_ALTITUDE", "EAC_MINIMUM_SAFE_ALTITUDE",
    "The minimum safe <<ALTITUDE_MSL>> that provides a 304,8 metre (1 000"
    " foot) obstacle clearance within an <AIRSPACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[405]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AZ3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINIMUM_TERRAIN_ELEVATION,
    "MINIMUM_TERRAIN_ELEVATION", "EAC_MINIMUM_TERRAIN_ELEVATION",
    "The minimum of <<TERRAIN_ELEVATION>>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1241]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINUTE_WITHIN_DAY,
    "MINUTE_WITHIN_DAY", "EAC_MINUTE_WITHIN_DAY",
    "The ordinal index of a minute within the day, starting with the number"
    " \"0\" at midnight.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MINUTE_WITHIN_HOUR,
    "MINUTE_WITHIN_HOUR", "EAC_MINUTE_WITHIN_HOUR",
    "The ordinal index of a minute within the hour. The index starts with"
    " the number \"0\" at the beginning of the hour.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MISSILE_SITE_TYPE,
    "MISSILE_SITE_TYPE", "EAC_MISSILE_SITE_TYPE",
    "The type of a <MISSILE_SITE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 15, &(EDCS_Enumerant_Dictionary[3881]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MST]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MISSING_INFORMATION_TYPE,
    "MISSING_INFORMATION_TYPE", "EAC_MISSING_INFORMATION_TYPE",
    "The type of missing information.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[46]), 1, &(EDCS_Enumerant_Dictionary[3896]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VCT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MISSION_SPECIFIC_DAMAGE_FRACTION,
    "MISSION_SPECIFIC_DAMAGE_FRACTION", "EAC_MISSION_SPECIFIC_DAMAGE_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the extent of physical injury/damage to an <OBJECT> (for"
    " example: a critical sensor/emitter <AERIAL> and/or subsystem)"
    " specific to the mission. Zero means no damage at all and one means"
    " maximum damage.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[183]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.9, Bit: 2 (Mission)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIXING_LAYER_DEPTH,
    "MIXING_LAYER_DEPTH", "EAC_MIXING_LAYER_DEPTH",
    "The depth of the top of a surface mixing layer measured from a"
    " <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1249]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIXING_LAYER_DEPTH_STD_DEV,
    "MIXING_LAYER_DEPTH_STD_DEV", "EAC_MIXING_LAYER_DEPTH_STD_DEV",
    "The standard deviation of <<MIXING_LAYER_DEPTH>> measurements.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1249]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIXING_LAYER_TEMP_GRAD,
    "MIXING_LAYER_TEMP_GRAD", "EAC_MIXING_LAYER_TEMP_GRAD",
    "The gradient of <<TEMPERATURE>> across a surface mixing layer.",
    EDCS_AVT_REAL, EQC_LINEIC_THERMO_TEMP_GRADIENT,
    1, &(EGBindingForEA[47]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIXING_LAYER_TEMP_GRAD_STD_DEV,
    "MIXING_LAYER_TEMP_GRAD_STD_DEV", "EAC_MIXING_LAYER_TEMP_GRAD_STD_DEV",
    "The standard deviation of <<MIXING_LAYER_TEMP_GRAD>> measurements.",
    EDCS_AVT_REAL, EQC_LINEIC_THERMO_TEMP_GRADIENT,
    1, &(EGBindingForEA[47]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MIXING_RATIO,
    "MIXING_RATIO", "EAC_MIXING_RATIO",
    "In a <SYSTEM> of moist <AIR>, the ratio of the <<MASS>> of <WATER>"
    " vapour to the <<MASS>> of dry <AIR>; the mixing ratio.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"mixing ratio\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MODIFIED_SURF_INDEX,
    "MODIFIED_SURF_INDEX", "EAC_MODIFIED_SURF_INDEX",
    "A dimensionless number that provides a relative measure of the"
    " severity of the conditions likely to be encountered in the"
    " <SURF_ZONE>; the modified surf index.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[54]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MODULUS_OF_ELASTICITY,
    "MODULUS_OF_ELASTICITY", "EAC_MODULUS_OF_ELASTICITY",
    "The ratio of the tensile stress to tensile strain for a <MATERIAL>;"
    " the modulus of elasticity or Young's modulus.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[I31-3, 3-18.1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MONITORED,
    "MONITORED", "EAC_MONITORED",
    "An indication that an <OBJECT> is actively monitored.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: MOS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MONTH,
    "MONTH", "EAC_MONTH",
    "The month of the year in the Gregorian calendar.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 12, &(EDCS_Enumerant_Dictionary[3897]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"month\", 1]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MOON_PHASE,
    "MOON_PHASE", "EAC_MOON_PHASE",
    "The phase of the <MOON>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1189]), 8, &(EDCS_Enumerant_Dictionary[3909]),
    EDCS_REF_TYP_INFORMATIVE, "[PMPMI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MOON_PHASE_COUNT,
    "MOON_PHASE_COUNT", "EAC_MOON_PHASE_COUNT",
    "The number of complete phases of the <MOON> since 00:00:00 UTC, 1"
    " January 1970; the moon phase count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[1189]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MOON_PHASE_TIME,
    "MOON_PHASE_TIME", "EAC_MOON_PHASE_TIME",
    "The time at which a <<MOON_PHASE>> occurs since 00:00:00 UTC, 1"
    " January 1970.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[1191]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MOONRISE_TIME,
    "MOONRISE_TIME", "EAC_MOONRISE_TIME",
    "The <<TIME_OF_DAY>> of moonrise. The time is defined to occur when the"
    " geometric zenith distance of the centre of the <MOON> is 90,5666 arc"
    " degrees plus the apparent angular <<RADIUS>> of the <MOON> minus the"
    " apparent angular horizontal parallax of the <MOON>; that is, under"
    " normal atmospheric conditions at MSL, the upper limb of the <MOON>"
    " will then appear to be tangent with a level, unobstructed eastern"
    " horizon. No account is taken of the <<MOON_PHASE>>; that is, the"
    " <MOON> is always regarded as a disk in the sky and the upper limb"
    " might be dark. The 34 arc minute geometric depression of the centre"
    " of the <MOON> used for the computations is used to account for"
    " atmospheric refraction. The apparent angular <<RADIUS>> of the <MOON>"
    " varies from 15 to 17 arc minutes and its apparent angular horizontal"
    " parallax varies from 54 to 61 arc minutes.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[1191]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SIED]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MOONSET_TIME,
    "MOONSET_TIME", "EAC_MOONSET_TIME",
    "The <<TIME_OF_DAY>> of moonset. The time is defined to occur when the"
    " geometric zenith distance of the centre of the <MOON> is 90,5666 arc"
    " degrees plus the apparent angular <<RADIUS>> of the <MOON> minus the"
    " apparent angular horizontal parallax of the <MOON>; that is, under"
    " normal atmospheric conditions at MSL, the upper limb of the <MOON>"
    " will then appear to be tangent with a level, unobstructed western"
    " horizon. No account is taken of the <<MOON_PHASE>>; that is, the"
    " <MOON> is always regarded as a disk in the sky and the upper limb"
    " might be dark. The 34 arc minute geometric depression of the centre"
    " of the <MOON> used for the computations is used to account for"
    " atmospheric refraction. The apparent angular <<RADIUS>> of the <MOON>"
    " varies from 15 to 17 arc minutes and its apparent angular horizontal"
    " parallax varies from 54 to 61 arc minutes.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[1191]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SIED]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MOORING_CONNECTION_TYPE,
    "MOORING_CONNECTION_TYPE", "EAC_MOORING_CONNECTION_TYPE",
    "The type of connection used in a mooring <SYSTEM>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 2, &(EDCS_Enumerant_Dictionary[3917]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MCT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MOORING_FACILITY_TYPE,
    "MOORING_FACILITY_TYPE", "EAC_MOORING_FACILITY_TYPE",
    "The type of a <MOORING_FACILITY>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1039]), 6, &(EDCS_Enumerant_Dictionary[3919]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MWF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MOVEMENT_INDUCED_CONTRAIL_PRODUCTION_RATE,
    "MOVEMENT_INDUCED_CONTRAIL_PRODUCTION_RATE", "EAC_MOVEMENT_INDUCED_CONTRAIL_PRODUCTION_RATE",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the production rate of contrails, vapour trails, or other"
    " ionization phenomena that is induced by movement of a <VEHICLE>"
    " through the <ATMOSPHERE>. Zero means no contrail at all and one means"
    " maximum production.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    5, &(EGBindingForEA[334]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.2, Bits: 7-8 (Trailing Effects)]",
    "[EBEV, 4.3.2, Bits: 7-8 (Trailing Effects)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_MULTIPASS_SURFACE_DEGRADATION,
    "MULTIPASS_SURFACE_DEGRADATION", "EAC_MULTIPASS_SURFACE_DEGRADATION",
    "The qualitative degree to which <TERRAIN> or a"
    " <LAND_TRANSPORTATION_ROUTE> has been degraded by the passage of"
    " <GROUND_VEHICLE>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 3, &(EDCS_Enumerant_Dictionary[3925]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MULTIPLE,
    "MULTIPLE", "EAC_MULTIPLE",
    "An indication that an <OBJECT> represents more than one instance of"
    " that type of <OBJECT> type; multiple.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MULTIPLE_OBSTRUCTION_LIGHTS,
    "MULTIPLE_OBSTRUCTION_LIGHTS", "EAC_MULTIPLE_OBSTRUCTION_LIGHTS",
    "An indication that multiple obstruction <LIGHT>s are associated with"
    " an <OBJECT>.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[159]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OLQ]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MUNITION_BURST_COUNT,
    "MUNITION_BURST_COUNT", "EAC_MUNITION_BURST_COUNT",
    "The number of detonations of <MUNITION>s within a delineated <REGION>;"
    " the munition burst count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[34]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MUNITION_FUSE_TYPE,
    "MUNITION_FUSE_TYPE", "EAC_MUNITION_FUSE_TYPE",
    "The type of fuse used in a <MUNITION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 6, &(EDCS_Enumerant_Dictionary[3928]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_MUNITION_PROTECTION_LEVEL,
    "MUNITION_PROTECTION_LEVEL", "EAC_MUNITION_PROTECTION_LEVEL",
    "The level of protection against <MUNITION>s that a <STRUCTURE>"
    " provides for its contents.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1297]), 4, &(EDCS_Enumerant_Dictionary[3934]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NAME,
    "NAME", "EAC_NAME",
    "A textual identifier or code used to denote an <OBJECT>; the name.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[157]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NAM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NATIONAL_PAINT_SCHEME,
    "NATIONAL_PAINT_SCHEME", "EAC_NATIONAL_PAINT_SCHEME",
    "The national paint scheme applied to an <OBJECT>. The values are"
    " specified by a <<NATIONAL_PAINT_SCHEME_VALUE_SET>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[101]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.2.2 Country]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NATIONAL_PAINT_SCHEME_VALUE_SET,
    "NATIONAL_PAINT_SCHEME_VALUE_SET", "EAC_NATIONAL_PAINT_SCHEME_VALUE_SET",
    "The value set of a formatted <<NATIONAL_PAINT_SCHEME>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[11]), 3, &(EDCS_Enumerant_Dictionary[3938]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NATIVE_SETTLEMENT_TYPE,
    "NATIVE_SETTLEMENT_TYPE", "EAC_NATIVE_SETTLEMENT_TYPE",
    "The type of distribution of native <DWELLING>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1333]), 2, &(EDCS_Enumerant_Dictionary[3941]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NAS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NAUTICAL_GATE_TYPE,
    "NAUTICAL_GATE_TYPE", "EAC_NAUTICAL_GATE_TYPE",
    "The type of a <MARINE_GATE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[974]), 7, &(EDCS_Enumerant_Dictionary[3943]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GNC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NAVIGABLE_STATUS,
    "NAVIGABLE_STATUS", "EAC_NAVIGABLE_STATUS",
    "The type of navigability of a <WATERBODY_SURFACE_REGION> by large"
    " <VESSEL>s (for example: ocean going); navigable status.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[21]), 5, &(EDCS_Enumerant_Dictionary[3950]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: NVS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NAVIGATION_LIGHT_INTENSITY,
    "NAVIGATION_LIGHT_INTENSITY", "EAC_NAVIGATION_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of external <LIGHTING> that is used to"
    " illuminate the environment in the <DIRECTION> of travel of a"
    " <VEHICLE>; the navigation or head light intensity. Zero means minimum"
    " intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[1185]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.2, Bit: 13 (Navigation Lights)]",
    "[EBEV, 4.3.1.1, Bit: 12 (Head Lights)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_NAVIGATION_PATH_TYPE,
    "NAVIGATION_PATH_TYPE", "EAC_NAVIGATION_PATH_TYPE",
    "The type of <LINE> defining a marine navigation path.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 2, &(EDCS_Enumerant_Dictionary[3955]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LNC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NAVIGATION_SYSTEM_TYPE,
    "NAVIGATION_SYSTEM_TYPE", "EAC_NAVIGATION_SYSTEM_TYPE",
    "The type of technology used in electronic navigation. The value is"
    " either a type of <EQUIPMENT> or the name of a <SYSTEM>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[789]), 69, &(EDCS_Enumerant_Dictionary[3957]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NST and NS2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NOMINAL_LIGHT_RANGE,
    "NOMINAL_LIGHT_RANGE", "EAC_NOMINAL_LIGHT_RANGE",
    "The maximum distance at which a <LIGHT> can be seen in clear weather"
    " as defined by the International Visibility Code; the nominal light"
    " range.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[825]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NON_REGULATORY_AIRSPACE_CLASS,
    "NON_REGULATORY_AIRSPACE_CLASS", "EAC_NON_REGULATORY_AIRSPACE_CLASS",
    "The class of a non-regulatory <AIRSPACE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 1, &(EDCS_Enumerant_Dictionary[4026]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NON_SUB_CONTACT_DATE,
    "NON_SUB_CONTACT_DATE", "EAC_NON_SUB_CONTACT_DATE",
    "The date of reporting of a <NON_SUBMARINE_CONTACT>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    5, &(EGBindingForEA[249]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WDT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NON_SUB_CONTACT_POSITION_ACCURACY,
    "NON_SUB_CONTACT_POSITION_ACCURACY", "EAC_NON_SUB_CONTACT_POSITION_ACCURACY",
    "The accuracy of the <LOCATION> of a <NON_SUBMARINE_CONTACT>. When the"
    " accuracy is uncertain, the value 10 000 kilometres is used.",
    EDCS_AVT_REAL, EQC_LENGTH,
    5, &(EGBindingForEA[244]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PEV]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NON_SUB_CONTACT_SOURCE,
    "NON_SUB_CONTACT_SOURCE", "EAC_NON_SUB_CONTACT_SOURCE",
    "The source of a reported <NON_SUBMARINE_CONTACT>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[263]), 55, &(EDCS_Enumerant_Dictionary[4027]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WSR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NON_SUB_CONTACT_SOURCE_TYPE,
    "NON_SUB_CONTACT_SOURCE_TYPE", "EAC_NON_SUB_CONTACT_SOURCE_TYPE",
    "The type of source of a reported <NON_SUBMARINE_CONTACT>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[263]), 20, &(EDCS_Enumerant_Dictionary[4082]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RAG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NON_SUB_CONTACT_WRECK_IDENTIFIER,
    "NON_SUB_CONTACT_WRECK_IDENTIFIER", "EAC_NON_SUB_CONTACT_WRECK_IDENTIFIER",
    "The numeric identifier of a <NON_SUBMARINE_CONTACT>.",
    EDCS_AVT_INDEX, 0,
    5, &(EGBindingForEA[239]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WRN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NULL,
    "NULL", "EAC_NULL",
    "The null attribute concept; provided for information processing"
    " applications.",
    EDCS_AVT_NULL, 0,
    1, &(EGBindingForEA[6]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"null\", 4.b]", EDCS_CONCEPT_STAT_ISO },

    {EAC_NUMERIC_IDENTIFIER,
    "NUMERIC_IDENTIFIER", "EAC_NUMERIC_IDENTIFIER",
    "A numeric identifier used to reference values in a data structure; an"
    " index.",
    EDCS_AVT_INDEX, 0,
    2, &(EGBindingForEA[485]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_NUMERIC_OBJECT_IDENTIFIER,
    "NUMERIC_OBJECT_IDENTIFIER", "EAC_NUMERIC_OBJECT_IDENTIFIER",
    "The numeric identifier of an <OBJECT>.",
    EDCS_AVT_INDEX, 0,
    2, &(EGBindingForEA[157]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: UID]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_ASPECT,
    "OBJECT_ASPECT", "EAC_OBJECT_ASPECT",
    "The portion or aspect of an <OBJECT> in relation to the <TERRAIN>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1241]), 19, &(EDCS_Enumerant_Dictionary[4102]),
    EDCS_REF_TYP_INFORMATIVE, "[CATT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_BASE_HEIGHT,
    "OBJECT_BASE_HEIGHT", "EAC_OBJECT_BASE_HEIGHT",
    "The <<HEIGHT_AGL>> of the base (lowest point) of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_BEARING_GEODETIC,
    "OBJECT_BEARING_GEODETIC", "EAC_OBJECT_BEARING_GEODETIC",
    "The <<GEODETIC_AZIMUTH>> of the bearing of an <OBJECT> from an"
    " observer.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_CONFIGURATION,
    "OBJECT_CONFIGURATION", "EAC_OBJECT_CONFIGURATION",
    "The type of configuration of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 8, &(EDCS_Enumerant_Dictionary[4121]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FCO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_CONFIGURATION_QUALITY,
    "OBJECT_CONFIGURATION_QUALITY", "EAC_OBJECT_CONFIGURATION_QUALITY",
    "An indication of whether the <OBJECT> has a recognizable"
    " <<OBJECT_CONFIGURATION>>.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, FCO:8 and 9]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_ELEMENT_GEODETIC_ORIENTATION,
    "OBJECT_ELEMENT_GEODETIC_ORIENTATION", "EAC_OBJECT_ELEMENT_GEODETIC_ORIENTATION",
    "The <<GEODETIC_AZIMUTH>> of the predominant linear pattern of the"
    " elements within an <OBJECT>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[90]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FEO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_IDENTIFICATION_BASE_NUMBER,
    "OBJECT_IDENTIFICATION_BASE_NUMBER", "EAC_OBJECT_IDENTIFICATION_BASE_NUMBER",
    "The base number used within a specific geographic <REGION> to assign"
    " identification numbers to new <OBJECT>s.",
    EDCS_AVT_INTEGER, 0,
    2, &(EGBindingForEA[1112]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_LABEL,
    "OBJECT_LABEL", "EAC_OBJECT_LABEL",
    "The label applied to an <OBJECT>.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[157]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LAB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_ORDINAL_RANK,
    "OBJECT_ORDINAL_RANK", "EAC_OBJECT_ORDINAL_RANK",
    "The relative importance of an <OBJECT> as an ordinal rank.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 5, &(EDCS_Enumerant_Dictionary[4129]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ORD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_ORIENTATION_WRT_VERTICAL,
    "OBJECT_ORIENTATION_WRT_VERTICAL", "EAC_OBJECT_ORIENTATION_WRT_VERTICAL",
    "The orientation of the usual axis of an <OBJECT> with respect to the"
    " vertical <DIRECTION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 5, &(EDCS_Enumerant_Dictionary[4134]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FVO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_POLYGONAL_FACE_SHAPE,
    "OBJECT_POLYGONAL_FACE_SHAPE", "EAC_OBJECT_POLYGONAL_FACE_SHAPE",
    "The shape of the polygon associated with a <NON_EMPTY_SET> of"
    " <POLYGONAL_FACE>s of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[6]), 9, &(EDCS_Enumerant_Dictionary[4139]),
    EDCS_REF_TYP_INFORMATIVE, "[CATT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_RATE,
    "OBJECT_RATE", "EAC_OBJECT_RATE",
    "A rate associated with an <OBJECT>. The value is formatted in a Basic"
    " Latin string. The string contains a number, followed by a unit"
    " enclosed in parenthesis (\"( )\"), followed by a unit qualifier"
    " enclosed in square brackets (\"[ ]\"). EXAMPLE \"100(cars)[per"
    " hour]\" associated with a <BRIDGE> as the rate at which cars cross"
    " the <BRIDGE>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FTR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_SET_TYPE,
    "OBJECT_SET_TYPE", "EAC_OBJECT_SET_TYPE",
    "The type of an <OBJECT_SET>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 53, &(EDCS_Enumerant_Dictionary[4148]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_SHADED,
    "OBJECT_SHADED", "EAC_OBJECT_SHADED",
    "An indication that an <OBJECT> is shaded from direct sunlight or solar"
    " loading.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[159]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_SKY_IRRADIANCE,
    "OBJECT_SKY_IRRADIANCE", "EAC_OBJECT_SKY_IRRADIANCE",
    "The irradiance from the sky (downwelling) onto an <OBJECT>.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    2, &(EGBindingForEA[159]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_TRANSMITTANCE_FRACTION,
    "OBJECT_TRANSMITTANCE_FRACTION", "EAC_OBJECT_TRANSMITTANCE_FRACTION",
    "From a <LOCATION> of maximum visibility through an <OBJECT> (for"
    " example: a <FENCE> and/or a <TREE_LINE>), the ratio of the number of"
    " geometric rays from that <LOCATION> that are within the <REGION>"
    " delineated by an <OBJECT> but do not intersect that <OBJECT> to the"
    " total number of geometric rays from that <LOCATION> that are within"
    " that same <REGION>; transmittance fraction.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[161]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_TYPE_DENSITY,
    "OBJECT_TYPE_DENSITY", "EAC_OBJECT_TYPE_DENSITY",
    "The areal density of <OBJECT>s of a specified type.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DMF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_VARIANT,
    "OBJECT_VARIANT", "EAC_OBJECT_VARIANT",
    "The numeric identifier of a variation of a type of <OBJECT>; object"
    " variant. All variations of the type of an <OBJECT> have a common"
    " supertype.",
    EDCS_AVT_INDEX, 0,
    2, &(EGBindingForEA[157]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBJECT_VERTICAL_DISPLACEMENT,
    "OBJECT_VERTICAL_DISPLACEMENT", "EAC_OBJECT_VERTICAL_DISPLACEMENT",
    "The vertical distance measured from the lowest point of the base of an"
    " <OBJECT> (downhill side/downstream side) to the prevailing <TERRAIN>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBSCURANT_TYPE,
    "OBSCURANT_TYPE", "EAC_OBSCURANT_TYPE",
    "The type of obscurant present in an <ATMOSPHERE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[442]), 17, &(EDCS_Enumerant_Dictionary[4201]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBSERVATION_DECK_PRESENT,
    "OBSERVATION_DECK_PRESENT", "EAC_OBSERVATION_DECK_PRESENT",
    "An indication that one or more observation decks are present on an"
    " <OBJECT>.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBSERVATION_PLATFORM_TYPE,
    "OBSERVATION_PLATFORM_TYPE", "EAC_OBSERVATION_PLATFORM_TYPE",
    "The type of an observation platform.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 8, &(EDCS_Enumerant_Dictionary[4218]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBSERVATION_TIME_EPOCH_1970,
    "OBSERVATION_TIME_EPOCH_1970", "EAC_OBSERVATION_TIME_EPOCH_1970",
    "The time at which an observation was made since the epoch 00:00:00"
    " UTC, January 1, 1970 Common Era.",
    EDCS_AVT_REAL, EQC_TIME,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OBSERVED_VISIBILITY_REPORT_TYPE,
    "OBSERVED_VISIBILITY_REPORT_TYPE", "EAC_OBSERVED_VISIBILITY_REPORT_TYPE",
    "The type of report of observed visibility.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 8, &(EDCS_Enumerant_Dictionary[4226]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_CURRENT_EAST_SPEED,
    "OCEAN_CURRENT_EAST_SPEED", "EAC_OCEAN_CURRENT_EAST_SPEED",
    "The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the geodetic east-west"
    " <DIRECTION>, where east is positive.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_CURRENT_NORTH_SPEED,
    "OCEAN_CURRENT_NORTH_SPEED", "EAC_OCEAN_CURRENT_NORTH_SPEED",
    "The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the geodetic south-north"
    " <DIRECTION>, where north is positive.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_CURRENT_U,
    "OCEAN_CURRENT_U", "EAC_OCEAN_CURRENT_U",
    "The U component (geodetic west-east <DIRECTION>, where east is"
    " positive) of the <<WATER_CURRENT_SPEED>> in an <OCEAN>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"CURRENT-PROFILE-ELEMENT u component velocity rate\"]",
    "[NPDM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_CURRENT_U_SPEED,
    "OCEAN_CURRENT_U_SPEED", "EAC_OCEAN_CURRENT_U_SPEED",
    "The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the X <DIRECTION> of a"
    " projection-based coordinate system, where +X is positive; the \"U\""
    " speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_CURRENT_V,
    "OCEAN_CURRENT_V", "EAC_OCEAN_CURRENT_V",
    "The V component (geodetic south-north <DIRECTION>, where north is"
    " positive) of the <<WATER_CURRENT_SPEED>> in an <OCEAN>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"CURRENT-PROFILE-ELEMENT v component velocity rate\"]",
    "[NPDM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_CURRENT_V_SPEED,
    "OCEAN_CURRENT_V_SPEED", "EAC_OCEAN_CURRENT_V_SPEED",
    "The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the Y <DIRECTION> of a"
    " projection-based coordinate system, where +Y is positive; the \"V\""
    " speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_CURRENT_W,
    "OCEAN_CURRENT_W", "EAC_OCEAN_CURRENT_W",
    "The <<WATER_CURRENT_SPEED>> in an <OCEAN> in the down-up <DIRECTION>"
    " where up is positive; the ocean current W.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"CURRENT-PROFILE-ELEMENT w component velocity rate\"]",
    "[NPDM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_ELECTRICAL_CONDUCTIVITY_RATIO,
    "OCEAN_ELECTRICAL_CONDUCTIVITY_RATIO", "EAC_OCEAN_ELECTRICAL_CONDUCTIVITY_RATIO",
    "The ratio of the electrical conductivity of <WATER> in an <OCEAN> to"
    " the electrical conductivity of a potassium chloride standard"
    " solution, in which the mass fraction of potassium chloride is 32,4356"
    " x 10^(-6). Both conductivities are measured at a given"
    " <<WATERBODY_TEMPERATURE>> and a pressure of 1 standard atmosphere. A"
    " ratio of 1 corresponds to a <<PRACTICAL_SALINITY>> of 35.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[ISUO, Clause VI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_FLOOR_REGION_NAME,
    "OCEAN_FLOOR_REGION_NAME", "EAC_OCEAN_FLOOR_REGION_NAME",
    "The name of a <REGION> of an <OCEAN_FLOOR> that has measurable relief"
    " or is delimited by relief. The value is formatted in a Basic Latin"
    " string and contains the name for a kind of feature of the"
    " <OCEAN_FLOOR> that may be found in [SUFN].",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[1114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SUFN, page 2-5, \"UNDERSEA FEATURE NAME PROPOSAL\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_FLOOR_REGION_NAME_TYPE,
    "OCEAN_FLOOR_REGION_NAME_TYPE", "EAC_OCEAN_FLOOR_REGION_NAME_TYPE",
    "The type of a named <REGION> of the <OCEAN_FLOOR> that has measurable"
    " relief or is delimited by relief.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[52]), 65, &(EDCS_Enumerant_Dictionary[4234]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[SUFN, page 2-1, sub-paragraph I-B]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OCEAN_NAME,
    "OCEAN_NAME", "EAC_OCEAN_NAME",
    "The name of an <OCEAN>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1051]), 10, &(EDCS_Enumerant_Dictionary[4299]),
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OFFSHORE_PLATFORM_TYPE,
    "OFFSHORE_PLATFORM_TYPE", "EAC_OFFSHORE_PLATFORM_TYPE",
    "The type of an offshore platform.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 12, &(EDCS_Enumerant_Dictionary[4309]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OPC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OIL_BARRIER_TYPE,
    "OIL_BARRIER_TYPE", "EAC_OIL_BARRIER_TYPE",
    "The type of an <OIL_BARRIER>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[993]), 2, &(EDCS_Enumerant_Dictionary[4321]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OBC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OILRIG_PRESENT,
    "OILRIG_PRESENT", "EAC_OILRIG_PRESENT",
    "An indication that an <OIL_DRILLING_RIG> exists within a delineated"
    " <REGION>.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1118]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Wind and Residual Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OMNIDIR_SHIP_NOISE_CONFIDENCE,
    "OMNIDIR_SHIP_NOISE_CONFIDENCE", "EAC_OMNIDIR_SHIP_NOISE_CONFIDENCE",
    "A qualitative estimate of the degree of confidence in the"
    " <<OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL>> at a specified <<FREQUENCY>>,"
    " based on the quantity and variability of the measurements.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[304]), 3, &(EDCS_Enumerant_Dictionary[4323]),
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OMNIDIR_SHIP_NOISE_CORRECTION,
    "OMNIDIR_SHIP_NOISE_CORRECTION", "EAC_OMNIDIR_SHIP_NOISE_CORRECTION",
    "The correction to the <<OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL>>.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    2, &(EGBindingForEA[289]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OMNIDIR_SHIP_NOISE_DECORRELATION_TIME,
    "OMNIDIR_SHIP_NOISE_DECORRELATION_TIME", "EAC_OMNIDIR_SHIP_NOISE_DECORRELATION_TIME",
    "The <<TIME_QUANTITY>> required for omnidirectional shipping noise to"
    " decorrelate and/or disperse, typically taken at 50 hertz.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[297]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OMNIDIR_SHIP_NOISE_SPATIAL_VARIATION,
    "OMNIDIR_SHIP_NOISE_SPATIAL_VARIATION", "EAC_OMNIDIR_SHIP_NOISE_SPATIAL_VARIATION",
    "The degree of spatial variation of omnidirectional shipping noise,"
    " typically taken at 50 hertz.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    2, &(EGBindingForEA[289]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL,
    "OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL", "EAC_OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL",
    "The omnidirectional shipping noise spectral power level in a"
    " <<VOLUME>> of a <WATERBODY>, typically taken at 50 hertz.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    2, &(EGBindingForEA[289]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OPACITY,
    "OPACITY", "EAC_OPACITY",
    "A number between 0 and 1 representing a linearly-scaled fraction"
    " specifying the degree of line of sight blockage. The value is, on"
    " average, the fraction of the cross-sectional <<AREA>> of a"
    " non-homogeneous <OBJECT> that completely blocks the line of sight;"
    " the opacity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[161]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OPERATING_RESTRICTIONS_TYPE,
    "OPERATING_RESTRICTIONS_TYPE", "EAC_OPERATING_RESTRICTIONS_TYPE",
    "The conditions during which the use of an <OBJECT> (for example: a"
    " <FACILITY> and/or an <AIRSPACE>) is restricted.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[201]), 7, &(EDCS_Enumerant_Dictionary[4326]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ORS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OPERATING_TIME,
    "OPERATING_TIME", "EAC_OPERATING_TIME",
    "The times during which the use of an <OBJECT> (for example: a"
    " <FACILITY> and/or an <AIRSPACE>) is unrestricted.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[196]), 5, &(EDCS_Enumerant_Dictionary[4333]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OPERATIONAL,
    "OPERATIONAL", "EAC_OPERATIONAL",
    "An indication that an <OBJECT> is operational.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[201]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OPS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OPTICAL_TURBULENCE_INTENSITY,
    "OPTICAL_TURBULENCE_INTENSITY", "EAC_OPTICAL_TURBULENCE_INTENSITY",
    "A measure of fluctuations in the index of refraction at optical"
    " <<WAVELENGTH>>s resulting from turbulence in the <ATMOSPHERE>. The"
    " value is measured by the refractive index structure parameter that"
    " represents the correlation of refractive indices over distances of a"
    " few metres; the optical turbulence intensity.",
    EDCS_AVT_REAL, EQC_VOLUMETRIC_ENTITY_DENSITY,
    4, &(EGBindingForEA[607]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AFGL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ORIENTATION_ANGLE,
    "ORIENTATION_ANGLE", "EAC_ORIENTATION_ANGLE",
    "The <<GEODETIC_AZIMUTH>> measured in the local horizontal plane normal"
    " to the vertical axis of an <OBJECT> to the major (longitudinal) axis"
    " of the <OBJECT>. If the <OBJECT> is square, a value from 0 to 90 arc"
    " degrees (or equivalent) is recorded. If the <OBJECT> is circular, 360"
    " arc degrees (or equivalent) is recorded.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: AOO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OUTSIDE_DIAMETER,
    "OUTSIDE_DIAMETER", "EAC_OUTSIDE_DIAMETER",
    "The diameter of a cylindrical or spherical <OBJECT> measured using the"
    " outside <SURFACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OVERALL_BRIDGE_HEIGHT,
    "OVERALL_BRIDGE_HEIGHT", "EAC_OVERALL_BRIDGE_HEIGHT",
    "The vertical distance measured from the lowest point at the level of"
    " the <TERRAIN> or <WATERBODY_SURFACE> to the highest portion of a"
    " <BRIDGE>, including any <BRIDGE_SUPERSTRUCTURE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OHB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OVERALL_VERTICAL_DIMENSION,
    "OVERALL_VERTICAL_DIMENSION", "EAC_OVERALL_VERTICAL_DIMENSION",
    "The overall vertical dimension that includes all <COMPONENT>s of an"
    " <OBJECT>, including both those above and those below the <TERRAIN>"
    " (for a <TERRAIN_SURFACE_OBJECT>) or <WATERBODY_SURFACE> (for an"
    " <OBJECT> on a <WATERBODY_SURFACE>).",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OVERHEAD_CLEARANCE,
    "OVERHEAD_CLEARANCE", "EAC_OVERHEAD_CLEARANCE",
    "The least distance between a <LAND_TRANSPORTATION_ROUTE> and any"
    " <OVERHEAD_OBSTRUCTION> vertically above it; the overhead clearance.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OHC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OVERHEAD_COVER,
    "OVERHEAD_COVER", "EAC_OVERHEAD_COVER",
    "An indication that a <DEFENSIVE_POSITION> provides protection (cover)"
    " from the effects of overhead detonation of <MUNITION>s.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1295]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OVERHEAD_OBSTRUCTED,
    "OVERHEAD_OBSTRUCTED", "EAC_OVERHEAD_OBSTRUCTED",
    "An indication that there is an <OVERHEAD_OBSTRUCTION> less than 4,3"
    " metres above a <LAND_TRANSPORTATION_ROUTE>; overhead obstructed.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OCC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_OVERHEAD_OBSTRUCTION_TYPE,
    "OVERHEAD_OBSTRUCTION_TYPE", "EAC_OVERHEAD_OBSTRUCTION_TYPE",
    "The type of an <OVERHEAD_OBSTRUCTION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 6, &(EDCS_Enumerant_Dictionary[4338]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: OOC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PARALLEL_LINE_COUNT,
    "PARALLEL_LINE_COUNT", "EAC_PARALLEL_LINE_COUNT",
    "The total number of nominally parallel <LINE>s within an <OBJECT>; the"
    " parallel line count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NPL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PARAPET_TYPE,
    "PARAPET_TYPE", "EAC_PARAPET_TYPE",
    "The type of a <PARAPET>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1153]), 1, &(EDCS_Enumerant_Dictionary[4344]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PARTICLE_ENERGY,
    "PARTICLE_ENERGY", "EAC_PARTICLE_ENERGY",
    "The energy of a charged <PARTICLE>.",
    EDCS_AVT_REAL, EQC_ENERGY,
    1, &(EGBindingForEA[16]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PARTITIONED_WATERBODY,
    "PARTITIONED_WATERBODY", "EAC_PARTITIONED_WATERBODY",
    "An indication that a <WATERBODY> is partitioned.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1077]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PASQUILL_ATMOSPHERE_STABILITY_INDEX,
    "PASQUILL_ATMOSPHERE_STABILITY_INDEX", "EAC_PASQUILL_ATMOSPHERE_STABILITY_INDEX",
    "A method of categorizing the stability of an <ATMOSPHERE_REGION> of"
    " the <EARTH> in terms of the horizontal surface <<WIND_SPEED>>, the"
    " amount of solar radiation (insolation), and the"
    " <<TOTAL_CLOUD_COVERAGE>>; the Pasquill atmosphere stability index.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 10, &(EDCS_Enumerant_Dictionary[4345]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"Pasquill stability classes\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PASSAGE_BLOCKED,
    "PASSAGE_BLOCKED", "EAC_PASSAGE_BLOCKED",
    "An indication that a passageway is blocked to the movement of"
    " <VEHICLE>s and/or <PERSONNEL>.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[49]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PASSIVE_ACOUSTIC,
    "PASSIVE_ACOUSTIC", "EAC_PASSIVE_ACOUSTIC",
    "An indication that an <OBJECT> generates acoustic energy not intended"
    " for the purposes of detection, localization, and/or identification;"
    " passive acoustic.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[59]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_PATH_COUNT,
    "PATH_COUNT", "EAC_PATH_COUNT",
    "The number of independent, parallel paths (for example: a"
    " <RAILWAY_TRACK> and/or a <ROUTE_LANE>) in both <DIRECTION>s within a"
    " <LAND_TRANSPORTATION_ROUTE>; the path count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LTN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PATROL_CRAFT_TYPE,
    "PATROL_CRAFT_TYPE", "EAC_PATROL_CRAFT_TYPE",
    "The type of a <PATROL_CRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 363, &(EDCS_Enumerant_Dictionary[4355]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PEAK_TIDE_HEIGHT,
    "PEAK_TIDE_HEIGHT", "EAC_PEAK_TIDE_HEIGHT",
    "The maximum or minimum height reached by a rising or falling <TIDE>,"
    " respectively, relative to a <SURFACE_DATUM>; peak tide height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1251]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PEAK_TIDE_TIME,
    "PEAK_TIDE_TIME", "EAC_PEAK_TIDE_TIME",
    "The <<TIME_QUANTITY>> since midnight at which a <<PEAK_TIDE_HEIGHT>>"
    " is reached.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PEAK_TIDE_TYPE,
    "PEAK_TIDE_TYPE", "EAC_PEAK_TIDE_TYPE",
    "The type of a peak <TIDE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[54]), 2, &(EDCS_Enumerant_Dictionary[4718]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PEDESTRIAN_CAPACITY,
    "PEDESTRIAN_CAPACITY", "EAC_PEDESTRIAN_CAPACITY",
    "The number of pedestrians an <OBJECT> can accommodate.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[199]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PCU]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PEDESTRIAN_RATE,
    "PEDESTRIAN_RATE", "EAC_PEDESTRIAN_RATE",
    "The number of pedestrians per <<TIME_QUANTITY>> formatted in a Basic"
    " Latin string using structured text. The string contains a number,"
    " followed by a unit enclosed in parenthesis (\"( )\"), followed by a"
    " unit qualifier enclosed in square brackets (\"[ ]\"). EXAMPLE"
    " \"100(persons)[per hour]\".",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[1321]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PDR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PEDESTRIAN_TRAVERSABILITY,
    "PEDESTRIAN_TRAVERSABILITY", "EAC_PEDESTRIAN_TRAVERSABILITY",
    "The traversability of an <OBJECT> by a pedestrian.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 4, &(EDCS_Enumerant_Dictionary[4720]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TRA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PERIODIC_CYCLE_TIME,
    "PERIODIC_CYCLE_TIME", "EAC_PERIODIC_CYCLE_TIME",
    "The <<TIME_QUANTITY>> within a cyclic repeating phenomenon, typically"
    " the intervals of light and eclipse of a <LIGHTHOUSE>; the periodic"
    " cycle time.",
    EDCS_AVT_REAL, EQC_TIME,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PERIODIC_END_DATE,
    "PERIODIC_END_DATE", "EAC_PERIODIC_END_DATE",
    "The end of the active period for a seasonal <OBJECT> (for example: a"
    " <BUOY>). The value is formatted as specified by <<DATE_FORMAT>> or by"
    " <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[194]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PDE and DTE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PERIODIC_RESTRICTION_END,
    "PERIODIC_RESTRICTION_END", "EAC_PERIODIC_RESTRICTION_END",
    "The <<MONTH>> in which restrictions end on the use of an <OBJECT> due"
    " to climate or other limitations; the periodic restriction end.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[196]), 12, &(EDCS_Enumerant_Dictionary[4724]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PR1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PERIODIC_RESTRICTION_START,
    "PERIODIC_RESTRICTION_START", "EAC_PERIODIC_RESTRICTION_START",
    "The <<MONTH>> in which restrictions begin on the use of an <OBJECT>"
    " due to climate or other limitations; the periodic restriction start.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[196]), 12, &(EDCS_Enumerant_Dictionary[4736]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PR2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PERIODIC_RESTRICTION_TYPE,
    "PERIODIC_RESTRICTION_TYPE", "EAC_PERIODIC_RESTRICTION_TYPE",
    "The type of restriction on the use of an <OBJECT> due to climate or"
    " other limitations; the periodic restriction type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[201]), 17, &(EDCS_Enumerant_Dictionary[4748]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PRC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PERIODIC_START_DATE,
    "PERIODIC_START_DATE", "EAC_PERIODIC_START_DATE",
    "The start of the active period for a seasonal <OBJECT> (for example: a"
    " <BUOY>). The value is formatted as specified by <<DATE_FORMAT>> or by"
    " <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[194]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PDS and DTS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PERMANENT,
    "PERMANENT", "EAC_PERMANENT",
    "An indication that an <OBJECT> is permanent (as opposed to temporary).",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[194]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PRM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PH,
    "PH", "EAC_PH",
    "The logarithm of the reciprocal of hydrogen ion concentration in gram"
    " atoms per litre; the pH.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[33]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"pH\"]", EDCS_CONCEPT_STAT_ISO },

    {EAC_PHYSICAL_OBSTRUCTION,
    "PHYSICAL_OBSTRUCTION", "EAC_PHYSICAL_OBSTRUCTION",
    "An indication that a physical obstruction, stopping or blocking a"
    " <ROUTE>, is present.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[49]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PHYSICAL_STATE,
    "PHYSICAL_STATE", "EAC_PHYSICAL_STATE",
    "The physical state of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 5, &(EDCS_Enumerant_Dictionary[4765]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PST]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PICTORIAL_RESOURCE_REQUEST,
    "PICTORIAL_RESOURCE_REQUEST", "EAC_PICTORIAL_RESOURCE_REQUEST",
    "Specifies the resource site where a request for a pictorial"
    " representation of an <OBJECT> is available; the pictorial resource"
    " request. The value is formatted in a Basic Latin string as specified"
    " by [URI].",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[6]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PIC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PIPELINE_TYPE,
    "PIPELINE_TYPE", "EAC_PIPELINE_TYPE",
    "The type of a <PIPELINE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 9, &(EDCS_Enumerant_Dictionary[4770]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PLT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PITCH_ANGLE,
    "PITCH_ANGLE", "EAC_PITCH_ANGLE",
    "The angular distance about the pitch axis of an <OBJECT> measured in"
    " the local vertical plane from the local horizontal clockwise"
    " (upwards) to the forward axis of the <OBJECT>. The forward axis of"
    " the <OBJECT> is the axis which passes through the <OBJECT> centre and"
    " is directed towards/through the forward part or <SURFACE> (front) of"
    " the <OBJECT>. The pitch axis of the <OBJECT> is normal to the forward"
    " axis in the horizontal plane of the <OBJECT> and forms a two"
    " dimensional right-handed <SYSTEM>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLANETARY_SRF_DEW_POINT_DEPRESSION,
    "PLANETARY_SRF_DEW_POINT_DEPRESSION", "EAC_PLANETARY_SRF_DEW_POINT_DEPRESSION",
    "The <<DEW_POINT_DEPRESSION>> 1,25 to 2,0 metres above a"
    " <PLANETARY_SURFACE> at a <LOCATION>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO8, Section 2.1.4.1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLANETARY_SRF_DEW_POINT_TEMPERATURE,
    "PLANETARY_SRF_DEW_POINT_TEMPERATURE", "EAC_PLANETARY_SRF_DEW_POINT_TEMPERATURE",
    "The <<DEW_POINT_TEMPERATURE>> 1,25 to 2,0 metres above a"
    " <PLANETARY_SURFACE> at a <LOCATION>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO8, Section 2.1.4.1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLANETARY_SURFACE_AIR_TEMPERATURE,
    "PLANETARY_SURFACE_AIR_TEMPERATURE", "EAC_PLANETARY_SURFACE_AIR_TEMPERATURE",
    "The <<AIR_TEMPERATURE>> 1,25 to 2,0 metres above a <PLANETARY_SURFACE>"
    " at a <LOCATION>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO8, Section 2.1.4.1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLANETARY_SURFACE_ATM_PRESSURE,
    "PLANETARY_SURFACE_ATM_PRESSURE", "EAC_PLANETARY_SURFACE_ATM_PRESSURE",
    "The <<ATM_PRESSURE>> at a <PLANETARY_SURFACE>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLANETARY_SURFACE_ILLUMINANCE_LEVEL,
    "PLANETARY_SURFACE_ILLUMINANCE_LEVEL", "EAC_PLANETARY_SURFACE_ILLUMINANCE_LEVEL",
    "The total solar and lunar contribution to the level of <<ILLUMINANCE>>"
    " at a <PLANETARY_SURFACE> as a function of <LOCATION>, date, time, and"
    " meteorological conditions.",
    EDCS_AVT_REAL, EQC_RADIANT_ENERGY_FLUENCE,
    3, &(EGBindingForEA[901]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLANETARY_SURFACE_TEMPERATURE,
    "PLANETARY_SURFACE_TEMPERATURE", "EAC_PLANETARY_SURFACE_TEMPERATURE",
    "The <<TEMPERATURE>> of a <PLANETARY_SURFACE> at a <LOCATION>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    1, &(EGBindingForEA[47]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLANT_COMPONENT_TYPE,
    "PLANT_COMPONENT_TYPE", "EAC_PLANT_COMPONENT_TYPE",
    "The type of a <COMPONENT> of a <PLANT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1218]), 2, &(EDCS_Enumerant_Dictionary[4779]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLATFORM_COUNT,
    "PLATFORM_COUNT", "EAC_PLATFORM_COUNT",
    "The number of platforms at a <TRANSPORTATION_STATION>; the platform"
    " count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[49]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLATOON_ACCOMMODATION_CAPACITY,
    "PLATOON_ACCOMMODATION_CAPACITY", "EAC_PLATOON_ACCOMMODATION_CAPACITY",
    "The number of platoons and associated <EQUIPMENT> that an <OBJECT> can"
    " accommodate; the platoon accommodation capacity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[181]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PLUNGING_BREAKER_FRACTION,
    "PLUNGING_BREAKER_FRACTION", "EAC_PLUNGING_BREAKER_FRACTION",
    "The fraction of breaking <WATER_WAVE>s that are plunging. Plunging"
    " means that the <WATER_WAVE> peaks up until it is an advancing"
    " vertical wall of <WATER>, the crest then curls far over and descends"
    " violently into the preceding trough where the <SURFACE> of the"
    " <WATER> is essentially horizontal; a considerable amount of <AIR> is"
    " trapped in this process and this <AIR> escapes explosively behind the"
    " <WATER_WAVE>, throwing <WATER> high above the <SURFACE> and producing"
    " a loud explosive sound.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1327]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POINT_OBJECT_TYPE,
    "POINT_OBJECT_TYPE", "EAC_POINT_OBJECT_TYPE",
    "The general type of a point <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 8, &(EDCS_Enumerant_Dictionary[4781]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POISSON_RATIO,
    "POISSON_RATIO", "EAC_POISSON_RATIO",
    "The ratio of change in length in the direction of applied stress to"
    " change in width that is perpendicular to the direction of applied"
    " stress of a <MATERIAL> when placed under tension; the Poisson ratio.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APDS, \"Poisson ratio\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POLYGONAL_FACE_TYPE,
    "POLYGONAL_FACE_TYPE", "EAC_POLYGONAL_FACE_TYPE",
    "The type of <OBJECT> represented by a <POLYGONAL_FACE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[83]), 6, &(EDCS_Enumerant_Dictionary[4789]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_DEPRECATED },

    {EAC_POND_TYPE,
    "POND_TYPE", "EAC_POND_TYPE",
    "The type of a pond.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[50]), 3, &(EDCS_Enumerant_Dictionary[4795]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: POP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POPULATED_PLACE_TYPE,
    "POPULATED_PLACE_TYPE", "EAC_POPULATED_PLACE_TYPE",
    "The type of a populated place.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[50]), 8, &(EDCS_Enumerant_Dictionary[4798]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POPULATION,
    "POPULATION", "EAC_POPULATION",
    "The number of <HUMAN>s within a delineated <REGION>; the population.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[569]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PPL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POSTURE,
    "POSTURE", "EAC_POSTURE",
    "The posture of a <HUMAN>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[569]), 19, &(EDCS_Enumerant_Dictionary[4806]),
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.3, Bits: 16-19 (Life Form State)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POTENTIAL_AIR_TEMPERATURE,
    "POTENTIAL_AIR_TEMPERATURE", "EAC_POTENTIAL_AIR_TEMPERATURE",
    "The <<AIR_TEMPERATURE>> that a parcel of dry <AIR> would have, if"
    " brought adiabatically from its initial state to the standard pressure"
    " of 100 kilopascals (1 000 millibars); the potential air temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"potential air temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POWER_GENERATING_CAPACITY,
    "POWER_GENERATING_CAPACITY", "EAC_POWER_GENERATING_CAPACITY",
    "The electrical power generating capacity of an <OBJECT>; the power"
    " generating capacity.",
    EDCS_AVT_REAL, EQC_POWER,
    3, &(EGBindingForEA[125]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: EPW]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POWER_GENERATION_RATE,
    "POWER_GENERATION_RATE", "EAC_POWER_GENERATION_RATE",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional power generation of an <OBJECT> with the associated noise"
    " and heat. Zero means none at all and one means maximum.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[128]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 22 (Power-plant Status)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_POWER_PLANT_TYPE,
    "POWER_PLANT_TYPE", "EAC_POWER_PLANT_TYPE",
    "The technology used by a <POWER_PLANT> to produce electricity.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[867]), 7, &(EDCS_Enumerant_Dictionary[4825]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PPC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRACTICAL_SALINITY,
    "PRACTICAL_SALINITY", "EAC_PRACTICAL_SALINITY",
    "A measure of the <<MASS>> of dissolved <MATERIAL> in seawater as"
    " determined by the <<OCEAN_ELECTRICAL_CONDUCTIVITY_RATIO>> at a"
    " <<TEMPERATURE>> of 288,15 kelvin (15 degrees Celsius) and the"
    " pressure of one standard atmosphere; practical salinity.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    3, &(EGBindingForEA[1267]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[ISUO, Clause VI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRECIPITABLE_WATER,
    "PRECIPITABLE_WATER", "EAC_PRECIPITABLE_WATER",
    "The total water vapour contained in a vertical column of unit"
    " cross-sectional <<AREA>> extending between two <<HEIGHT_AGL>>s of an"
    " <ATMOSPHERE>; the precipitable water.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRECIPITABLE_WATER_TOTAL,
    "PRECIPITABLE_WATER_TOTAL", "EAC_PRECIPITABLE_WATER_TOTAL",
    "The total <<PRECIPITABLE_WATER>> contained in a column of unit cross"
    " section extending from the <PLANETARY_SURFACE> to the top of the"
    " <ATMOSPHERE>.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRECIPITATION_INTENSITY,
    "PRECIPITATION_INTENSITY", "EAC_PRECIPITATION_INTENSITY",
    "The intensity of <PRECIPITATION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 4, &(EDCS_Enumerant_Dictionary[4832]),
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, Section 8.4.1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRECIPITATION_NOISE_POWER_LEVEL,
    "PRECIPITATION_NOISE_POWER_LEVEL", "EAC_PRECIPITATION_NOISE_POWER_LEVEL",
    "The power level of acoustic noise energy in a <WATERBODY> due to"
    " <PRECIPITATION> onto the <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    4, &(EGBindingForEA[225]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRECIPITATION_PERIOD,
    "PRECIPITATION_PERIOD", "EAC_PRECIPITATION_PERIOD",
    "The <<TIME_QUANTITY>> prior to the referenced time over which"
    " <PRECIPITATION> accumulated.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[692]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRECIPITATION_PHASE,
    "PRECIPITATION_PHASE", "EAC_PRECIPITATION_PHASE",
    "The state (liquid/solid disposition) of precipitable <WATER>; the"
    " precipitation phase.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 3, &(EDCS_Enumerant_Dictionary[4836]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRECIPITATION_RATE,
    "PRECIPITATION_RATE", "EAC_PRECIPITATION_RATE",
    "The rate of <PRECIPITATION>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRECIPITATION_TYPE,
    "PRECIPITATION_TYPE", "EAC_PRECIPITATION_TYPE",
    "The type of <PRECIPITATION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 22, &(EDCS_Enumerant_Dictionary[4839]),
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PREDOMINANT_DEPTH_WITHIN_OBJECT,
    "PREDOMINANT_DEPTH_WITHIN_OBJECT", "EAC_PREDOMINANT_DEPTH_WITHIN_OBJECT",
    "The predominant (greater than 50 percent) <<DEPTH>> within the"
    " <REGION> delineated by an <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PFE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PREDOMINANT_HEIGHT,
    "PREDOMINANT_HEIGHT", "EAC_PREDOMINANT_HEIGHT",
    "The predominant (greater than 50 percent) <<HEIGHT_AGL>> of an"
    " <OBJECT>. If not obtainable, then the mean <<HEIGHT_AGL>> of the"
    " <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PREDOMINANT_HEIGHT_WITHIN_OBJECT,
    "PREDOMINANT_HEIGHT_WITHIN_OBJECT", "EAC_PREDOMINANT_HEIGHT_WITHIN_OBJECT",
    "The predominant (greater than 50 percent) height within the <REGION>"
    " delineated by an <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PFH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PREDOMINANT_SURROUND_TYPE,
    "PREDOMINANT_SURROUND_TYPE", "EAC_PREDOMINANT_SURROUND_TYPE",
    "The predominant type of other <OBJECT>s within a <<RADIUS>> of 457"
    " metres (1 500 feet) of an <OBJECT> of interest.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 3, &(EDCS_Enumerant_Dictionary[4861]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PREDOMINANT_VEGETATION_HEIGHT,
    "PREDOMINANT_VEGETATION_HEIGHT", "EAC_PREDOMINANT_VEGETATION_HEIGHT",
    "The predominant (greater than 50 percent) <<HEIGHT_AGL>> of"
    " <VEGETATION>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[827]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VH1, VH2, and VH3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PREDOMINANT_WATER_DEPTH,
    "PREDOMINANT_WATER_DEPTH", "EAC_PREDOMINANT_WATER_DEPTH",
    "The predominant (greater than 50 percent) <<WATER_DEPTH>> determined"
    " at the greatest depth along a cross section of the <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DW2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PREPARED_EXPLOSIVE_DESTRUCTION_COMPLETION_FRACTION,
    "PREPARED_EXPLOSIVE_DESTRUCTION_COMPLETION_FRACTION", "EAC_PREPARED_EXPLOSIVE_DESTRUCTION_COMPLETION_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the extent to which an <OBJECT> has been prepared for"
    " destruction by <EXPLOSIVE_CHARGE>s. Zero means no preparation at all"
    " and one means completely prepared.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRESENT_WEATHER_TYPE_AUTOMATED,
    "PRESENT_WEATHER_TYPE_AUTOMATED", "EAC_PRESENT_WEATHER_TYPE_AUTOMATED",
    "The type of weather existing at an automated <WEATHER_STATION> at the"
    " time of observation.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 76, &(EDCS_Enumerant_Dictionary[4864]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, Code table 4680, \"present weather reported from an automatic"
    " weather station\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRESENT_WEATHER_TYPE_MANUAL,
    "PRESENT_WEATHER_TYPE_MANUAL", "EAC_PRESENT_WEATHER_TYPE_MANUAL",
    "The type of weather existing at a manual <WEATHER_STATION> at the time"
    " of observation.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 100, &(EDCS_Enumerant_Dictionary[4940]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, Code table 4677, \"present weather reported from a manned"
    " weather station\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRESENT_WEATHER_TYPE_SPECIAL,
    "PRESENT_WEATHER_TYPE_SPECIAL", "EAC_PRESENT_WEATHER_TYPE_SPECIAL",
    "The type of a special weather event or observation.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 74, &(EDCS_Enumerant_Dictionary[5040]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, Code table 4687, \"present weather phenomenon not specified"
    " in Code table 4677\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRESSURE_ALTIMETER_QUALITY,
    "PRESSURE_ALTIMETER_QUALITY", "EAC_PRESSURE_ALTIMETER_QUALITY",
    "The quality of a <<PRESSURE_ALTIMETER_SETTING>>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 9, &(EDCS_Enumerant_Dictionary[5114]),
    EDCS_REF_TYP_INFORMATIVE, "[QCMO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRESSURE_ALTIMETER_SETTING,
    "PRESSURE_ALTIMETER_SETTING", "EAC_PRESSURE_ALTIMETER_SETTING",
    "The value of the <<ATM_PRESSURE>> used to adjust the subscale of a"
    " pressure altimeter so that it indicates the vertical distance of an"
    " <AIRCRAFT> above a known <<ATM_VERTICAL_REFERENCE>>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    2, &(EGBindingForEA[419]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"altimeter setting\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRESSURE_ALTITUDE,
    "PRESSURE_ALTITUDE", "EAC_PRESSURE_ALTITUDE",
    "The altitude that corresponds to a given <FLIGHT_LEVEL>; the pressure"
    " altitude.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRI_WEAPON_DEPLOYED_POS_CATEGORY,
    "PRI_WEAPON_DEPLOYED_POS_CATEGORY", "EAC_PRI_WEAPON_DEPLOYED_POS_CATEGORY",
    "A category describing the <<PRI_WEAPON_DEPLOYED_POSITION>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 4, &(EDCS_Enumerant_Dictionary[5123]),
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.3, Bits: 24-25 (Weapon 1)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRI_WEAPON_DEPLOYED_POSITION,
    "PRI_WEAPON_DEPLOYED_POSITION", "EAC_PRI_WEAPON_DEPLOYED_POSITION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional deployment of the primary <WEAPON_SYSTEM> of an <OBJECT>."
    " Zero means fully stowed/retracted and one means fully deployed.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1293]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.3, Weapon 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY,
    "PRIMARY", "EAC_PRIMARY",
    "An indication that an <OBJECT> is primary.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: PRS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_AERIAL_DEPLOYED_POSITION,
    "PRIMARY_AERIAL_DEPLOYED_POSITION", "EAC_PRIMARY_AERIAL_DEPLOYED_POSITION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional deployment of the primary <AERIAL> on an <OBJECT>. Zero"
    " means fully stowed/retracted and one means fully deployed.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[748]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.6, Bit: 16 (Antenna)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_AXIS_VELOCITY_COMPONENT,
    "PRIMARY_AXIS_VELOCITY_COMPONENT", "EAC_PRIMARY_AXIS_VELOCITY_COMPONENT",
    "The <<VELOCITY>> component of an <OBJECT> along the primary axis of a"
    " defined spatial reference frame.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_BREAKER_AZIMUTH,
    "PRIMARY_BREAKER_AZIMUTH", "EAC_PRIMARY_BREAKER_AZIMUTH",
    "The <<VECTOR_AZIMUTH_GEODETIC>> of a <LINE> drawn perpendicular to the"
    " <DIRECTION> of propagation of primary breaking <WATER_WAVE>s in the"
    " wave spectra of a <SURF_ZONE>; the primary breaker azimuth.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_BREAKER_RELATIVE_ANGLE,
    "PRIMARY_BREAKER_RELATIVE_ANGLE", "EAC_PRIMARY_BREAKER_RELATIVE_ANGLE",
    "The horizontal angle the primary breaking <WATER_WAVE>s make with"
    " respect to the <BEACH>. The angle varies from zero when the <LINE> of"
    " the <WATER_WAVE>s parallels the <BEACH> to 90 arc degrees on either"
    " the right or left flank as seen from <VESSEL>s approaching the"
    " <BEACH>; the primary breaker relative angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_BROADCAST_FREQUENCY,
    "PRIMARY_BROADCAST_FREQUENCY", "EAC_PRIMARY_BROADCAST_FREQUENCY",
    "The designated primary broadcast <<FREQUENCY>> for a communications"
    " <DEVICE>.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    3, &(EGBindingForEA[745]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BRF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_BYPRODUCT,
    "PRIMARY_BYPRODUCT", "EAC_PRIMARY_BYPRODUCT",
    "The primary by-product of a production, mining, or agricultural"
    " activity.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[319]), 19, &(EDCS_Enumerant_Dictionary[5127]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_DOOR_OPEN_POSITION,
    "PRIMARY_DOOR_OPEN_POSITION", "EAC_PRIMARY_DOOR_OPEN_POSITION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional opening of the primary <DOOR> of an <OBJECT>. Zero means"
    " fully closed and one means fully open.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_ENTRANCE_LOCATION,
    "PRIMARY_ENTRANCE_LOCATION", "EAC_PRIMARY_ENTRANCE_LOCATION",
    "The <LOCATION> of the primary (general) <STRUCTURE_ENTRANCE> as"
    " observed from outside the <STRUCTURE> looking towards its front.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1243]), 25, &(EDCS_Enumerant_Dictionary[5146]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_MATERIAL_TYPE,
    "PRIMARY_MATERIAL_TYPE", "EAC_PRIMARY_MATERIAL_TYPE",
    "The type of primary <MATERIAL> of which an <OBJECT> is composed.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[169]), 144, &(EDCS_Enumerant_Dictionary[5171]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MCC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_OPERATING_AGENCY_IDENTIFIER,
    "PRIMARY_OPERATING_AGENCY_IDENTIFIER", "EAC_PRIMARY_OPERATING_AGENCY_IDENTIFIER",
    "The DAFIF two character code identifying the primary operating agency"
    " of an <AERODROME>; formatted in a Basic Latin string as specified by"
    " [DAFIF, Sec. 201.A.17].",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[306]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[DAFIF, Sec. 201.A.19, \"Primary Operating Agency\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_PRODUCT,
    "PRIMARY_PRODUCT", "EAC_PRIMARY_PRODUCT",
    "The primary product resulting from a production, mining, or"
    " agricultural activity.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[319]), 130, &(EDCS_Enumerant_Dictionary[5315]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PRO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_RAW_MATERIAL,
    "PRIMARY_RAW_MATERIAL", "EAC_PRIMARY_RAW_MATERIAL",
    "The primary raw <MATERIAL> involved in a production activity.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1120]), 97, &(EDCS_Enumerant_Dictionary[5445]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_SURFACE_AIR_VELOCITY,
    "PRIMARY_SURFACE_AIR_VELOCITY", "EAC_PRIMARY_SURFACE_AIR_VELOCITY",
    "The <<VELOCITY>> of the <AIR> along the primary <SURFACE>, generally"
    " the top, front, or outer side of a layer of <MATERIAL> or an <OBJECT>.",
    EDCS_AVT_REAL, EQC_SPEED,
    4, &(EGBindingForEA[668]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_SURFACE_TEMPERATURE,
    "PRIMARY_SURFACE_TEMPERATURE", "EAC_PRIMARY_SURFACE_TEMPERATURE",
    "The <<TEMPERATURE>> of the medium in contact with the primary"
    " <SURFACE> of an <OBJECT>, generally the top, front, or outer side of"
    " a layer of <MATERIAL>, that is typically used as a boundary condition"
    " in thermal solutions.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[1279]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_SURFACE_THERMAL_CONDITION,
    "PRIMARY_SURFACE_THERMAL_CONDITION", "EAC_PRIMARY_SURFACE_THERMAL_CONDITION",
    "The physical boundary condition at the primary <SURFACE> of an"
    " <OBJECT>, generally the top, front, or outer side of a layer of"
    " <MATERIAL>, that accounts for the thermal interface of the <OBJECT>"
    " with the environment at that <SURFACE>; the primary surface thermal"
    " condition.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1274]), 13, &(EDCS_Enumerant_Dictionary[5542]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_SWELL_WAVE_DIRECTION,
    "PRIMARY_SWELL_WAVE_DIRECTION", "EAC_PRIMARY_SWELL_WAVE_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which primary"
    " <SWELL_WAVE>s are arriving.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_SWELL_WAVE_HEIGHT,
    "PRIMARY_SWELL_WAVE_HEIGHT", "EAC_PRIMARY_SWELL_WAVE_HEIGHT",
    "The mean height of the significant (highest one-third) primary"
    " <SWELL_WAVE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_SWELL_WAVE_PERIOD,
    "PRIMARY_SWELL_WAVE_PERIOD", "EAC_PRIMARY_SWELL_WAVE_PERIOD",
    "The mean <<TIME_QUANTITY>> that a complete cycle (usually crest to"
    " crest or trough to trough) of a primary <SWELL_WAVE> takes to pass a"
    " given fixed point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIMARY_WAVE_DIRECTION,
    "PRIMARY_WAVE_DIRECTION", "EAC_PRIMARY_WAVE_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which significant"
    " <WATER_WAVE>s in the wave spectra are arriving.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PRIORITY,
    "PRIORITY", "EAC_PRIORITY",
    "A value representing the priority of this <OBJECT> as compared to"
    " other <OBJECT>s which overlap in spatial extent. A higher value means"
    " a higher priority.",
    EDCS_AVT_INTEGER, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PROCESSING_NAME,
    "PROCESSING_NAME", "EAC_PROCESSING_NAME",
    "A name that is assigned to an <OBJECT> to support processing internal"
    " to an information <SYSTEM>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[85]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PROPERTY_SET_DATA_SOURCE,
    "PROPERTY_SET_DATA_SOURCE", "EAC_PROPERTY_SET_DATA_SOURCE",
    "The source of data values of a <PROPERTY_SET>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[37]), 4, &(EDCS_Enumerant_Dictionary[5555]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PROPERTY_SET_SPATIAL_DOMAIN,
    "PROPERTY_SET_SPATIAL_DOMAIN", "EAC_PROPERTY_SET_SPATIAL_DOMAIN",
    "The spatial domain of a <PROPERTY_SET>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[37]), 9, &(EDCS_Enumerant_Dictionary[5559]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PROPERTY_SET_VALID_TIME,
    "PROPERTY_SET_VALID_TIME", "EAC_PROPERTY_SET_VALID_TIME",
    "The <<TIME_QUANTITY>> relative to a specified zero hour at which a"
    " <PROPERTY_SET> is valid.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1310]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PROTECTION_SHED_TYPE,
    "PROTECTION_SHED_TYPE", "EAC_PROTECTION_SHED_TYPE",
    "The type of a <PROTECTION_SHED>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 3, &(EDCS_Enumerant_Dictionary[5568]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: SUC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PUBLIC_ACCOMMODATION_TYPE,
    "PUBLIC_ACCOMMODATION_TYPE", "EAC_PUBLIC_ACCOMMODATION_TYPE",
    "The type of a <FACILITY> that is normally used for accommodating the"
    " public but is not a permanent or long-term <DWELLING>; public"
    " accommodation type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1129]), 7, &(EDCS_Enumerant_Dictionary[5571]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: PAF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_PUBLICATION_REFERENCE,
    "PUBLICATION_REFERENCE", "EAC_PUBLICATION_REFERENCE",
    "A reference to a specific paragraph in a publication.",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[12]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PBR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_BEACON_FREQUENCY,
    "RADAR_BEACON_FREQUENCY", "EAC_RADAR_BEACON_FREQUENCY",
    "The specific <<FREQUENCY>> of a radar transponder <BEACON>.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    2, &(EGBindingForEA[762]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RFQ]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_CROSS_SECTION,
    "RADAR_CROSS_SECTION", "EAC_RADAR_CROSS_SECTION",
    "The ratio of the radar power (or flux) per unit solid angle reflected"
    " from an <OBJECT> toward a sensor and 4(pi) times the incident power"
    " density; the radar cross section.",
    EDCS_AVT_REAL, EQC_AREA,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[RDP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_REFLECTOR_ANGLE,
    "RADAR_REFLECTOR_ANGLE", "EAC_RADAR_REFLECTOR_ANGLE",
    "The <<GEODETIC_AZIMUTH>> of the radar reflective side of an <OBJECT>;"
    " the radar reflector angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ARR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_REFLECTOR_PRESENT,
    "RADAR_REFLECTOR_PRESENT", "EAC_RADAR_REFLECTOR_PRESENT",
    "An indication that an <OBJECT> has an associated radar reflector"
    " <DEVICE>; radar reflector present.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[109]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: REF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_SIGNIFICANCE_FACTOR,
    "RADAR_SIGNIFICANCE_FACTOR", "EAC_RADAR_SIGNIFICANCE_FACTOR",
    "The type of an <OBJECT> based on the predominant exposed <MATERIAL> of"
    " the <SURFACE> of the <OBJECT>; the radar significance factor.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[174]), 15, &(EDCS_Enumerant_Dictionary[5578]),
    EDCS_REF_TYP_INFORMATIVE, "[DFAD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_STATION_TYPE,
    "RADAR_STATION_TYPE", "EAC_RADAR_STATION_TYPE",
    "The type of a <RADAR_STATION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[12]), 4, &(EDCS_Enumerant_Dictionary[5593]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RAS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_TERRAIN_CLUTTER,
    "RADAR_TERRAIN_CLUTTER", "EAC_RADAR_TERRAIN_CLUTTER",
    "The radar surface clutter expressed in mean <<RADAR_CROSS_SECTION>>"
    " per unit <<AREA>> of <TERRAIN>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[924]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BATT]",
    "[RDP]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_TRANSPONDER_TYPE,
    "RADAR_TRANSPONDER_TYPE", "EAC_RADAR_TRANSPONDER_TYPE",
    "The type of a radar transponder <BEACON>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 3, &(EDCS_Enumerant_Dictionary[5597]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RTB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADAR_WATERBODY_SURFACE_CLUTTER,
    "RADAR_WATERBODY_SURFACE_CLUTTER", "EAC_RADAR_WATERBODY_SURFACE_CLUTTER",
    "The radar surface clutter expressed in mean <<RADAR_CROSS_SECTION>>"
    " per unit <<AREA>> of <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[54]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BATT]",
    "[RDP]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIANCE,
    "RADIANCE", "EAC_RADIANCE",
    "The radiant power per unit source <<AREA>> per unit solid angle; the"
    " radiance.",
    EDCS_AVT_REAL, EQC_RADIANCE,
    2, &(EGBindingForEA[873]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"radiance\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIANCE_FLUCTUATION_24_HOUR,
    "RADIANCE_FLUCTUATION_24_HOUR", "EAC_RADIANCE_FLUCTUATION_24_HOUR",
    "The amount of fluctuation (peak amplitude) of the<<RADIANCE>> (or"
    " luminance) of a <SURFACE> over a twenty-four hour <<TIME_QUANTITY>>,"
    " expressed as a value from 0 to 255.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[912]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIANCE_PHASE,
    "RADIANCE_PHASE", "EAC_RADIANCE_PHASE",
    "The angular phase of <<RADIANCE>> amplitude assuming a sine wave"
    " fluctuation.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIANT_FLUX_DENSITY,
    "RADIANT_FLUX_DENSITY", "EAC_RADIANT_FLUX_DENSITY",
    "The radiant energy crossing a unit area from one side; the radiant"
    " flux density. The same quantity is designated as either the"
    " irradiance (when it is a received flux) or the exitance (when it is"
    " an emitted flux).",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    3, &(EGBindingForEA[912]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"radiant flux density\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIATIVE_FLUX_DOWNWELLING,
    "RADIATIVE_FLUX_DOWNWELLING", "EAC_RADIATIVE_FLUX_DOWNWELLING",
    "Short <<WAVELENGTH>> (less than 4 microns) <<RADIANT_FLUX_DENSITY>>"
    " incident downward on a <PLANETARY_SURFACE> as direct solar radiation;"
    " the radiative flux downwelling.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    2, &(EGBindingForEA[873]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIATIVE_FLUX_UPWELLING,
    "RADIATIVE_FLUX_UPWELLING", "EAC_RADIATIVE_FLUX_UPWELLING",
    "The net (upward minus downward) long <<WAVELENGTH>> (greater than 4"
    " microns) thermal <<RADIANT_FLUX_DENSITY>> from a <PLANETARY_SURFACE>;"
    " the radiative flux upwelling.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    2, &(EGBindingForEA[873]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIO_STATION_TYPE,
    "RADIO_STATION_TYPE", "EAC_RADIO_STATION_TYPE",
    "The type of a marine radio <COMMUNICATION_STATION>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[752]), 7, &(EDCS_Enumerant_Dictionary[5600]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ROS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIOLOGIC_AGENT_ATM_CONCENTRATION,
    "RADIOLOGIC_AGENT_ATM_CONCENTRATION", "EAC_RADIOLOGIC_AGENT_ATM_CONCENTRATION",
    "The concentration of a radiologic agent suspended in an <ATMOSPHERE>.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    3, &(EGBindingForEA[618]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIOLOGIC_AGENT_SURFACE_CONCENTRATION,
    "RADIOLOGIC_AGENT_SURFACE_CONCENTRATION", "EAC_RADIOLOGIC_AGENT_SURFACE_CONCENTRATION",
    "The concentration of a radiologic agent contained in a layer on the"
    " <SURFACE> of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    4, &(EGBindingForEA[936]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIOLOGIC_AGENT_TYPE,
    "RADIOLOGIC_AGENT_TYPE", "EAC_RADIOLOGIC_AGENT_TYPE",
    "The type of a radiologic agent that can kill, seriously injure, or"
    " incapacitate <HUMAN>s or <NON_HUMAN_ANIMAL>s through its"
    " physiological properties.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[917]), 17, &(EDCS_Enumerant_Dictionary[5607]),
    EDCS_REF_TYP_INFORMATIVE, "[MELC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIOLOGIC_MASS,
    "RADIOLOGIC_MASS", "EAC_RADIOLOGIC_MASS",
    "The <<MASS>> of a radiologic substance contained in an <OBJECT>.",
    EDCS_AVT_REAL, EQC_MASS,
    1, &(EGBindingForEA[16]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RADIUS,
    "RADIUS", "EAC_RADIUS",
    "The radius of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILING_HEIGHT,
    "RAILING_HEIGHT", "EAC_RAILING_HEIGHT",
    "The vertical distance from the <FLOOR> to the top of a railing.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[15]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILING_TYPE,
    "RAILING_TYPE", "EAC_RAILING_TYPE",
    "The type of a railing.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[14]), 5, &(EDCS_Enumerant_Dictionary[5624]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILWAY_GAUGE,
    "RAILWAY_GAUGE", "EAC_RAILWAY_GAUGE",
    "The distance between a single pair of rails of a <RAILWAY_TRACK>"
    " measured along the shortest distance from inside rail to inside rail;"
    " the railway gauge.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GAW]",
    "[SOED, \"gauge\", 4]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILWAY_GAUGE_CATEGORY,
    "RAILWAY_GAUGE_CATEGORY", "EAC_RAILWAY_GAUGE_CATEGORY",
    "The category of a <<RAILWAY_GAUGE>>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[822]), 5, &(EDCS_Enumerant_Dictionary[5629]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RGC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILWAY_MAXIMUM_AXLE_LOAD,
    "RAILWAY_MAXIMUM_AXLE_LOAD", "EAC_RAILWAY_MAXIMUM_AXLE_LOAD",
    "The maximum load allowable on any single axle of a <RAIL_WAGON> or"
    " <LOCOMOTIVE_ENGINE>.",
    EDCS_AVT_REAL, EQC_MASS,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RMA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILWAY_MAXIMUM_LOAD,
    "RAILWAY_MAXIMUM_LOAD", "EAC_RAILWAY_MAXIMUM_LOAD",
    "The maximum load allowable on a <RAILWAY>.",
    EDCS_AVT_REAL, EQC_MASS,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RMT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILWAY_POWER_SOURCE,
    "RAILWAY_POWER_SOURCE", "EAC_RAILWAY_POWER_SOURCE",
    "The source of electrical power for a <RAILWAY>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[870]), 3, &(EDCS_Enumerant_Dictionary[5634]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RRA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILWAY_TRACK_ARRANGEMENT,
    "RAILWAY_TRACK_ARRANGEMENT", "EAC_RAILWAY_TRACK_ARRANGEMENT",
    "The arrangement of <RAILWAY_TRACK>s in both <DIRECTION>s on a single"
    " bed.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 4, &(EDCS_Enumerant_Dictionary[5637]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RTA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAILWAY_TYPE,
    "RAILWAY_TYPE", "EAC_RAILWAY_TYPE",
    "The type of a <SYSTEM> of <RAILWAY>s used to support various"
    " transportation uses.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 25, &(EDCS_Enumerant_Dictionary[5641]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RRC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAMP_DEPLOYED_POSITION,
    "RAMP_DEPLOYED_POSITION", "EAC_RAMP_DEPLOYED_POSITION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional deployment of a <RAMP> or <GATE> of an <OBJECT>. Zero"
    " means fully stowed/retracted/closed and one means fully deployed.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1321]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 25 (Ramp)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RAPID_CLASS,
    "RAPID_CLASS", "EAC_RAPID_CLASS",
    "In North America, the relative difficulty of traversing a <RAPID>,"
    " based on the Safety Code of American Whitewater; the rapid class.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1048]), 6, &(EDCS_Enumerant_Dictionary[5666]),
    EDCS_REF_TYP_INFORMATIVE, "[SCAW]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RECEIVED_AMBIENT_LIGHT_SCALED_INTENSITY,
    "RECEIVED_AMBIENT_LIGHT_SCALED_INTENSITY", "EAC_RECEIVED_AMBIENT_LIGHT_SCALED_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional light intensity received by an <OBJECT> from all"
    " unlocalized sources. Zero means minimum intensity and one means"
    " maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[885]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGPP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RECEIVED_DIFFUSE_LIGHT_SCALED_INTENSITY,
    "RECEIVED_DIFFUSE_LIGHT_SCALED_INTENSITY", "EAC_RECEIVED_DIFFUSE_LIGHT_SCALED_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional light intensity received by an <OBJECT> from the diffuse"
    " radiation leaving a particular localized source. Zero means minimum"
    " intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[885]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGPP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RECEIVED_SPECULAR_LIGHT_SCALED_INTENSITY,
    "RECEIVED_SPECULAR_LIGHT_SCALED_INTENSITY", "EAC_RECEIVED_SPECULAR_LIGHT_SCALED_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional light intensity received by an <OBJECT> from the specular"
    " radiation leaving a particular localized source. Zero means minimum"
    " intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[885]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGPP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RECOMMENDED_TRACK,
    "RECOMMENDED_TRACK", "EAC_RECOMMENDED_TRACK",
    "An indication that an <OBJECT> complies with a recommended track.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[199]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: RTS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RECORDING_DATE,
    "RECORDING_DATE", "EAC_RECORDING_DATE",
    "The date when the given information concerning the <OBJECT> was"
    " recorded, captured, edited, or deleted. The value is formatted as"
    " specified by <<DATE_FORMAT>> or by <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RCD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RECORDING_DATE_TYPE,
    "RECORDING_DATE_TYPE", "EAC_RECORDING_DATE_TYPE",
    "The type of a <<RECORDING_DATE>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 31, &(EDCS_Enumerant_Dictionary[5672]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CDP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REFLECTANCE_AZIMUTH_GEODETIC,
    "REFLECTANCE_AZIMUTH_GEODETIC", "EAC_REFLECTANCE_AZIMUTH_GEODETIC",
    "The <<VECTOR_AZIMUTH_GEODETIC>> toward which light is reflected (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REFLECTANCE_AZIMUTH_LOCAL,
    "REFLECTANCE_AZIMUTH_LOCAL", "EAC_REFLECTANCE_AZIMUTH_LOCAL",
    "The <<VECTOR_AZIMUTH_LOCAL>> toward which light is reflected (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REFLECTANCE_AZIMUTH_MAGNETIC,
    "REFLECTANCE_AZIMUTH_MAGNETIC", "EAC_REFLECTANCE_AZIMUTH_MAGNETIC",
    "The <<VECTOR_AZIMUTH_MAGNETIC>> toward which light is reflected (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REFLECTANCE_ELEV_ANGLE_HORIZONTAL,
    "REFLECTANCE_ELEV_ANGLE_HORIZONTAL", "EAC_REFLECTANCE_ELEV_ANGLE_HORIZONTAL",
    "The <<VECTOR_ELEV_ANGLE_HORIZONTAL>> toward which light is reflected"
    " (the <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REFLECTANCE_ELEV_ANGLE_LOCAL,
    "REFLECTANCE_ELEV_ANGLE_LOCAL", "EAC_REFLECTANCE_ELEV_ANGLE_LOCAL",
    "The <<VECTOR_ELEV_ANGLE_LOCAL>> toward which light is reflected (the"
    " <DIRECTION> of the unit Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REFLECTANCE_ZENITH_ANGLE_LOCAL,
    "REFLECTANCE_ZENITH_ANGLE_LOCAL", "EAC_REFLECTANCE_ZENITH_ANGLE_LOCAL",
    "The angle at a <LOCATION> on a <SURFACE> between the vectors A and B,"
    " where A is the surface normal vector and B is the <DIRECTION> toward"
    " the sampling of radiation reflected from the <SURFACE> at that"
    " <LOCATION>. The positive sense is clockwise when looking in the"
    " <DIRECTION> of the cross product AxB.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[536]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REFRACTION_INDEX_IMAGINARY_PART,
    "REFRACTION_INDEX_IMAGINARY_PART", "EAC_REFRACTION_INDEX_IMAGINARY_PART",
    "The imaginary part of a complex refraction index. The complex"
    " refraction index is the square root of the product of the complex"
    " relative permittivity and permeability of the <MATERIAL>. The"
    " imaginary part of the complex refraction index can also be derived"
    " from the attenuation index or absorption coefficient of the"
    " <MATERIAL>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[33]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REFRACTION_INDEX_REAL_PART,
    "REFRACTION_INDEX_REAL_PART", "EAC_REFRACTION_INDEX_REAL_PART",
    "The real part of a complex refraction index. The complex refraction"
    " index is the square root of the product of the complex relative"
    " permittivity and permeability of the <MATERIAL>. The real part of a"
    " complex refraction index can also be derived from the attenuation"
    " index or absorption coefficient of the <MATERIAL>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[33]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REGIONAL_STYLE,
    "REGIONAL_STYLE", "EAC_REGIONAL_STYLE",
    "The architectural style of a <STRUCTURE> based on the <REGION> of the"
    " <EARTH> where it is commonly used or other important characteristics;"
    " the regional style.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[43]), 19, &(EDCS_Enumerant_Dictionary[5703]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELATIVE_HORIZONTAL_ACCURACY,
    "RELATIVE_HORIZONTAL_ACCURACY", "EAC_RELATIVE_HORIZONTAL_ACCURACY",
    "The horizontal accuracy of a <LOCATION> relative to another horizontal"
    " <LOCATION> expressed in units of length at 90% circular error.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1245]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[MCGA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELATIVE_HUMIDITY,
    "RELATIVE_HUMIDITY", "EAC_RELATIVE_HUMIDITY",
    "The ratio of vapour pressure to saturation vapour pressure, where"
    " vapour pressure is the pressure exerted by the molecules of water"
    " vapour and saturation vapour pressure is the pressure exerted by"
    " molecules of water vapour in <AIR> that has attained saturation; the"
    " relative humidity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELATIVE_HUMIDITY_ERROR,
    "RELATIVE_HUMIDITY_ERROR", "EAC_RELATIVE_HUMIDITY_ERROR",
    "The error in a measurement of <<RELATIVE_HUMIDITY>> that is introduced"
    " by uncertainties.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"AIR-TEMPERATURE-ANALYSIS-FORECAST relative humidity error"
    " quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELATIVE_HUMIDITY_MINIMUM_TEMPERATURE,
    "RELATIVE_HUMIDITY_MINIMUM_TEMPERATURE", "EAC_RELATIVE_HUMIDITY_MINIMUM_TEMPERATURE",
    "The <<RELATIVE_HUMIDITY>> at the time of the lowest"
    " <<AIR_TEMPERATURE>> for the preceding twenty-four hours.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELATIVE_LOCATION,
    "RELATIVE_LOCATION", "EAC_RELATIVE_LOCATION",
    "The <LOCATION> of an <OBJECT> relative to the surrounding <REGION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[164]), 38, &(EDCS_Enumerant_Dictionary[5722]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TRK]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELATIVE_ORIENTATION_ANGLE,
    "RELATIVE_ORIENTATION_ANGLE", "EAC_RELATIVE_ORIENTATION_ANGLE",
    "The angular distance about the vertical axis of an <OBJECT> measured"
    " in the local horizontal plane from the positive x-axis of an external"
    " (relative) coordinate system clockwise (viewed from above) to the"
    " major (longitudinal) axis of the <OBJECT>; the relative orientation"
    " angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELATIVE_VERTICAL_ACCURACY,
    "RELATIVE_VERTICAL_ACCURACY", "EAC_RELATIVE_VERTICAL_ACCURACY",
    "The vertical accuracy of a <LOCATION> relative to another vertical"
    " <LOCATION>, expressed in units of length at 90% linear error.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1245]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[MCGA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELEASABILITY_RESTRICTIONS,
    "RELEASABILITY_RESTRICTIONS", "EAC_RELEASABILITY_RESTRICTIONS",
    "The releasability restrictions of information about an <OBJECT>.",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[12]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: QLE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RELIGIOUS_DESIGNATION,
    "RELIGIOUS_DESIGNATION", "EAC_RELIGIOUS_DESIGNATION",
    "A designation denoting a religion or system of belief; the religious"
    " designation.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 27, &(EDCS_Enumerant_Dictionary[5760]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RESERVOIR_TYPE,
    "RESERVOIR_TYPE", "EAC_RESERVOIR_TYPE",
    "The manner that a <RESERVOIR> contains <WATER>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[983]), 2, &(EDCS_Enumerant_Dictionary[5787]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RTP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_REVERBERATION_NOISE_POWER_LEVEL,
    "REVERBERATION_NOISE_POWER_LEVEL", "EAC_REVERBERATION_NOISE_POWER_LEVEL",
    "The power level of acoustic energy in a <WATERBODY> due to reflection"
    " of active acoustic emissions from non-target <OBJECT>s; the"
    " reverberation noise.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_REYNOLDS_NUMBER,
    "REYNOLDS_NUMBER", "EAC_REYNOLDS_NUMBER",
    "The non-dimensional ratio of the inertial force to the viscous force"
    " in fluid motion, usually ranging between 0,0 and 1,0 x 10^(5); the"
    " Reynolds number.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[956]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RF_DIRECTIVITY,
    "RF_DIRECTIVITY", "EAC_RF_DIRECTIVITY",
    "A characterization of the <DIRECTION>s from an <OBJECT> that produce"
    " the greatest reflectivity potential to electromagnetic radiation; the"
    " radio frequency directivity.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 3, &(EDCS_Enumerant_Dictionary[5789]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DIR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RF_REFRACTIVE_INDEX_MODIFIED,
    "RF_REFRACTIVE_INDEX_MODIFIED", "EAC_RF_REFRACTIVE_INDEX_MODIFIED",
    "The index of refraction for the propagation of electromagnetic waves"
    " at radio <<FREQUENCY>>s in an <ATMOSPHERE> that has been modified to"
    " account for the curvature of a <PLANETARY_SURFACE>. The index of"
    " refraction is the ratio of the <<WAVELENGTH>> or phase velocity of an"
    " electromagnetic wave in a vacuum to that in the medium or substance.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[924]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RGB_COLOUR_BLUE,
    "RGB_COLOUR_BLUE", "EAC_RGB_COLOUR_BLUE",
    "A number between 0 and 1 inclusive representing a linearly-scaled"
    " fraction specifying the blue component of a colour measurement in the"
    " RGB colour model.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[473]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGPP, Chapter 13]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RGB_COLOUR_GREEN,
    "RGB_COLOUR_GREEN", "EAC_RGB_COLOUR_GREEN",
    "A number between 0 and 1 inclusive representing a linearly-scaled"
    " fraction specifying the green component of a colour measurement in"
    " the RGB colour model.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[473]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGPP, Chapter 13]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RGB_COLOUR_RED,
    "RGB_COLOUR_RED", "EAC_RGB_COLOUR_RED",
    "A number between 0 and 1 inclusive representing a linearly-scaled"
    " fraction specifying the red component of a colour measurement in the"
    " RGB colour model.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[473]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGPP, Chapter 13]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_ABOVE_BANK_ANGLE,
    "RIGHT_ABOVE_BANK_ANGLE", "EAC_RIGHT_ABOVE_BANK_ANGLE",
    "The angle from the horizontal plane to the portion above the mean"
    " level of the <WATERBODY_SURFACE> of the right <WATERBODY_BANK>"
    " (facing downstream) of a <WATERCOURSE>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BGR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_ABOVE_BANK_SLOPE,
    "RIGHT_ABOVE_BANK_SLOPE", "EAC_RIGHT_ABOVE_BANK_SLOPE",
    "The <<TERRAIN_SLOPE>> of the portion above the mean level of the"
    " <WATERBODY_SURFACE> of the right <WATERBODY_BANK> (facing downstream)"
    " of a <WATERCOURSE>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BGR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_BANK_HEIGHT,
    "RIGHT_BANK_HEIGHT", "EAC_RIGHT_BANK_HEIGHT",
    "The <<HEIGHT>> of the right <WATERBODY_BANK> (facing downstream) of a"
    " <WATERCOURSE> measured from the mean level of the <WATER> to the"
    " first break in <<TERRAIN_SLOPE>> above the mean level of the <WATER>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BHR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_BANK_SLOPE,
    "RIGHT_BANK_SLOPE", "EAC_RIGHT_BANK_SLOPE",
    "The <<TERRAIN_SLOPE>> of the right <WATERBODY_BANK> (facing"
    " downstream) of a <WATERCOURSE> measured from the mean level of the"
    " <WATER> to the first accessible break in slope above the mean level"
    " of the <WATER>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SR1 and SR2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_BANK_SOIL_CONE_INDEX,
    "RIGHT_BANK_SOIL_CONE_INDEX", "EAC_RIGHT_BANK_SOIL_CONE_INDEX",
    "The <<SOIL_CONE_INDEX>> of a right <WATERBODY_BANK>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    3, &(EGBindingForEA[1253]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_BANK_VEGETATION_DENSITY,
    "RIGHT_BANK_VEGETATION_DENSITY", "EAC_RIGHT_BANK_VEGETATION_DENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional density of <VEGETATION> found on the right"
    " <WATERBODY_BANK> (facing downstream) of a <WATERCOURSE> as a"
    " linearly-scaled fraction of bank <<AREA>>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1220]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BVR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_BELOW_BANK_ANGLE,
    "RIGHT_BELOW_BANK_ANGLE", "EAC_RIGHT_BELOW_BANK_ANGLE",
    "The angle from the horizontal plane to the portion below the mean"
    " level of the <WATERBODY_SURFACE> of the right <WATERBODY_BANK>"
    " (facing downstream) of a <WATERCOURSE>, below the mean level of the"
    " <WATER>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BWR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_BELOW_BANK_SLOPE,
    "RIGHT_BELOW_BANK_SLOPE", "EAC_RIGHT_BELOW_BANK_SLOPE",
    "The <<TERRAIN_SLOPE>> of the portion below the mean level of the"
    " <WATERBODY_SURFACE> of the right <WATERBODY_BANK> (facing downstream)"
    " of a <WATERCOURSE>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BWR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIGHT_TERRAIN_BANK_SLOPE,
    "RIGHT_TERRAIN_BANK_SLOPE", "EAC_RIGHT_TERRAIN_BANK_SLOPE",
    "The <<TERRAIN_SLOPE>> of the right bank of a <TERRAIN_SURFACE_OBJECT>"
    " (for example: a <TERRAIN_CUT> and/or an <EMBANKMENT>).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1304]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIP_CURRENT_PRESENT,
    "RIP_CURRENT_PRESENT", "EAC_RIP_CURRENT_PRESENT",
    "An indication that a <RIP_CURRENT> is present.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[54]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"rip current\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RIP_CURRENT_SPEED,
    "RIP_CURRENT_SPEED", "EAC_RIP_CURRENT_SPEED",
    "The <<WATER_CURRENT_SPEED>> of a <RIP_CURRENT>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1327]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"rip current\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_INTERCHANGE_TYPE,
    "ROAD_INTERCHANGE_TYPE", "EAC_ROAD_INTERCHANGE_TYPE",
    "The physical arrangement of a <ROAD_INTERCHANGE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 10, &(EDCS_Enumerant_Dictionary[5792]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RIT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_JUNCTION_CONNECTIVITY,
    "ROAD_JUNCTION_CONNECTIVITY", "EAC_ROAD_JUNCTION_CONNECTIVITY",
    "The type of connectivity among <ROAD>s meeting at a junction.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 2, &(EDCS_Enumerant_Dictionary[5802]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: JCR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_LANE_ADJACENCY,
    "ROAD_LANE_ADJACENCY", "EAC_ROAD_LANE_ADJACENCY",
    "The type of adjacency of a <ROUTE_LANE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 4, &(EDCS_Enumerant_Dictionary[5804]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_LANE_CONTROL_TYPE,
    "ROAD_LANE_CONTROL_TYPE", "EAC_ROAD_LANE_CONTROL_TYPE",
    "The type of traffic control at the end of a <ROUTE_LANE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 3, &(EDCS_Enumerant_Dictionary[5808]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_LANE_LIGHT_STATE,
    "ROAD_LANE_LIGHT_STATE", "EAC_ROAD_LANE_LIGHT_STATE",
    "The state of the traffic <LIGHT> at the end of a <ROUTE_LANE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1143]), 7, &(EDCS_Enumerant_Dictionary[5811]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_LANE_PASSING,
    "ROAD_LANE_PASSING", "EAC_ROAD_LANE_PASSING",
    "The type of passing allowed on a <ROUTE_LANE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 4, &(EDCS_Enumerant_Dictionary[5818]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_LANE_TURN,
    "ROAD_LANE_TURN", "EAC_ROAD_LANE_TURN",
    "The turning <DIRECTION> allowed at the end of a <ROUTE_LANE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 11, &(EDCS_Enumerant_Dictionary[5822]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_LIGHTING_PRESENT,
    "ROAD_LIGHTING_PRESENT", "EAC_ROAD_LIGHTING_PRESENT",
    "An indication that a <ROAD> is illuminated by <STREET_LAMP>s; road"
    " lighting present.",
    EDCS_AVT_BOOLEAN, 0,
    3, &(EGBindingForEA[1143]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_MINIMUM_TRAVELLED_WAY_WIDTH,
    "ROAD_MINIMUM_TRAVELLED_WAY_WIDTH", "EAC_ROAD_MINIMUM_TRAVELLED_WAY_WIDTH",
    "The minimum <<WIDTH>> the travelled way of a <ROAD>. The value is the"
    " sum of the <<WIDTH>>s of included <ROUTE_LANE>s. The <<WIDTH>>s of"
    " adjacent hard paved shoulders, <SIDEWALK>s, and other pathways are"
    " excluded.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_SECOND_TRAVELLED_WAY_WIDTH,
    "ROAD_SECOND_TRAVELLED_WAY_WIDTH", "EAC_ROAD_SECOND_TRAVELLED_WAY_WIDTH",
    "The <<WIDTH>> of a second travelled way that is the lesser <<WIDTH>>"
    " of the two travelled ways in a divided <ROAD>. The value is the sum"
    " of the <<WIDTH>>s of included <ROUTE_LANE>s. The <<WIDTH>>s of"
    " adjacent hard paved shoulders, <SIDEWALK>s, and other pathways are"
    " excluded.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WT2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_TOTAL_USABLE_WIDTH,
    "ROAD_TOTAL_USABLE_WIDTH", "EAC_ROAD_TOTAL_USABLE_WIDTH",
    "The total usable <<WIDTH>> of a travelled way of a <ROAD>. The value"
    " is the sum of the <<WIDTH>>s of included <ROUTE_LANE>s, adjacent hard"
    " paved shoulders, unobstructed hard paved median, <SIDEWALK>s, and"
    " other pathways. The <<WIDTH>>s of parking lots, turn-offs, and"
    " unpaved medians are excluded.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROAD_TYPE,
    "ROAD_TYPE", "EAC_ROAD_TYPE",
    "The type of a <ROAD>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 3, &(EDCS_Enumerant_Dictionary[5833]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RDT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROCK_FORMATION_STRUCTURE,
    "ROCK_FORMATION_STRUCTURE", "EAC_ROCK_FORMATION_STRUCTURE",
    "The structure of a <ROCKY_OUTCROP> or other formation of <ROCK>s.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[35]), 3, &(EDCS_Enumerant_Dictionary[5836]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RKF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROLL_ANGLE,
    "ROLL_ANGLE", "EAC_ROLL_ANGLE",
    "The angular distance about the forward axis of an <OBJECT> measured in"
    " the local vertical plane from the local vertical clockwise to the"
    " vertical axis of the <OBJECT>. The forward axis of the <OBJECT> is"
    " the axis that passes through the centre of the <OBJECT> and is"
    " directed towards/through the forward part or <SURFACE> (front) of the"
    " <OBJECT>. Clockwise rotation about the forward axis (the axis of"
    " roll) is determined in the <DIRECTION> of the front of the <OBJECT>"
    " (right hand rule). The vertical axis of the <OBJECT> is normal to its"
    " forward axis.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROLLING_STOCK_TYPE,
    "ROLLING_STOCK_TYPE", "EAC_ROLLING_STOCK_TYPE",
    "The type of a rolling-stock.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1168]), 27, &(EDCS_Enumerant_Dictionary[5839]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"rolling-stock\", a]", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_ASSEMBLY_TYPE,
    "ROOF_ASSEMBLY_TYPE", "EAC_ROOF_ASSEMBLY_TYPE",
    "The type of a <ROOF_ASSEMBLY>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 19, &(EDCS_Enumerant_Dictionary[5866]),
    EDCS_REF_TYP_INFORMATIVE, "[IBC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_COVER_FRACTION,
    "ROOF_COVER_FRACTION", "EAC_ROOF_COVER_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional <<AREA>> of a <TRACT> that is covered by <ROOF>s. Zero"
    " means no <ROOF>s are present and one means the <REGION> of <LAND> is"
    " completely covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[718]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DMR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_FRAMING_TYPE,
    "ROOF_FRAMING_TYPE", "EAC_ROOF_FRAMING_TYPE",
    "The framing type of a <ROOF>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 5, &(EDCS_Enumerant_Dictionary[5885]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_LOAD_BEARING_CAPACITY,
    "ROOF_LOAD_BEARING_CAPACITY", "EAC_ROOF_LOAD_BEARING_CAPACITY",
    "The maximum load per unit <<AREA>> that a <ROOF> can support; the load"
    " bearing capacity.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    2, &(EGBindingForEA[718]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_PREDOMINANT_PATTERN,
    "ROOF_PREDOMINANT_PATTERN", "EAC_ROOF_PREDOMINANT_PATTERN",
    "The predominant visual pattern of the <SURFACE> of a <ROOF>. The value"
    " usually describes the shape and arrangement of shingles, but may also"
    " describe smooth, corrugated, and gravel <ROOF>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[720]), 17, &(EDCS_Enumerant_Dictionary[5890]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_PREDOMINANT_SURFACE_MATERIAL,
    "ROOF_PREDOMINANT_SURFACE_MATERIAL", "EAC_ROOF_PREDOMINANT_SURFACE_MATERIAL",
    "The predominant outermost <MATERIAL> of which the <SURFACE> of a"
    " <ROOF> is constructed.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[714]), 27, &(EDCS_Enumerant_Dictionary[5907]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_SHAPE,
    "ROOF_SHAPE", "EAC_ROOF_SHAPE",
    "The shape of a <ROOF>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 24, &(EDCS_Enumerant_Dictionary[5934]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SSR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_SHEATHING_TYPE,
    "ROOF_SHEATHING_TYPE", "EAC_ROOF_SHEATHING_TYPE",
    "The type of <MATERIAL> overlaid on the frame of a <ROOF> to which the"
    " roofing <MATERIAL> is then attached; the roof sheathing type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 5, &(EDCS_Enumerant_Dictionary[5958]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOF_STYLE,
    "ROOF_STYLE", "EAC_ROOF_STYLE",
    "The architectural style of a <ROOF>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 16, &(EDCS_Enumerant_Dictionary[5963]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROOM_CEILING_CONSTRUCTION_TYPE,
    "ROOM_CEILING_CONSTRUCTION_TYPE", "EAC_ROOM_CEILING_CONSTRUCTION_TYPE",
    "The type of <MATERIAL> and/or techniques used to construct a"
    " <ROOM_CEILING>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 6, &(EDCS_Enumerant_Dictionary[5979]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROUTE_ALTERNATIVE_DESIGNATION,
    "ROUTE_ALTERNATIVE_DESIGNATION", "EAC_ROUTE_ALTERNATIVE_DESIGNATION",
    "The alternative official designation assigned to a"
    " <LAND_TRANSPORTATION_ROUTE>. EXAMPLES \"I-95\", \"A-1\", \"M-2\".",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RN2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROUTE_CONSTRICTION_TYPE,
    "ROUTE_CONSTRICTION_TYPE", "EAC_ROUTE_CONSTRICTION_TYPE",
    "The type of a <ROUTE_CONSTRICTION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 4, &(EDCS_Enumerant_Dictionary[5985]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CCA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROUTE_CROSSING_TYPE,
    "ROUTE_CROSSING_TYPE", "EAC_ROUTE_CROSSING_TYPE",
    "The type of shape attributed to the crossing of two or more"
    " <TRANSPORTATION_ROUTE>s.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 3, &(EDCS_Enumerant_Dictionary[5989]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CRC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROUTE_DESIGNATION,
    "ROUTE_DESIGNATION", "EAC_ROUTE_DESIGNATION",
    "The official designation assigned to a <LAND_TRANSPORTATION_ROUTE>."
    " EXAMPLES \"I-95\", \"M-2\", \"A-1\".",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RTN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROUTE_EXPANSION_TYPE,
    "ROUTE_EXPANSION_TYPE", "EAC_ROUTE_EXPANSION_TYPE",
    "The type of a <ROUTE_EXPANSION>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 1, &(EDCS_Enumerant_Dictionary[5992]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROUTE_WEATHER_TYPE,
    "ROUTE_WEATHER_TYPE", "EAC_ROUTE_WEATHER_TYPE",
    "The weather conditions under which a <LAND_TRANSPORTATION_ROUTE> is"
    " passable or remains open.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[648]), 3, &(EDCS_Enumerant_Dictionary[5993]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROW_COUNT,
    "ROW_COUNT", "EAC_ROW_COUNT",
    "The number of rows comprising an <OBJECT>; the row count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROW_DISTANCE,
    "ROW_DISTANCE", "EAC_ROW_DISTANCE",
    "The distance between each row comprising an <OBJECT>; may be either a"
    " mean value, or a constant value where rows are equally spaced.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ROW_SPACING_INTERNAL,
    "ROW_SPACING_INTERNAL", "EAC_ROW_SPACING_INTERNAL",
    "The distance between the <COMPONENT>s within each row comprising an"
    " <OBJECT>. The distance may be either a mean value or a constant value"
    " when <COMPONENT>s are equally spaced within a row; the row spacing"
    " internal.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUBBLE_STABILITY,
    "RUBBLE_STABILITY", "EAC_RUBBLE_STABILITY",
    "The ability of <RUBBLE> to resist sliding or collapsing under stress;"
    " the rubble stability.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[33]), 2, &(EDCS_Enumerant_Dictionary[5996]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_APPROACH_ANGLE_LIGHT_INTENSITY,
    "RUNWAY_APPROACH_ANGLE_LIGHT_INTENSITY", "EAC_RUNWAY_APPROACH_ANGLE_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the angle of approach indicator <LIGHT>s (for"
    " example: VASI and/or PAPI) on a <RUNWAY>. Zero means minimum"
    " intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_APPROACH_LIGHT_INTENSITY,
    "RUNWAY_APPROACH_LIGHT_INTENSITY", "EAC_RUNWAY_APPROACH_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the approach <LIGHT>s on a <RUNWAY>. Zero"
    " means minimum intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_APPROACH_OIS_DISTANCE,
    "RUNWAY_APPROACH_OIS_DISTANCE", "EAC_RUNWAY_APPROACH_OIS_DISTANCE",
    "The section distance from the beginning of a <RUNWAY_APPROACH_OIS>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[372]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ASS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_CENTRE_LIGHT_INTENSITY,
    "RUNWAY_CENTRE_LIGHT_INTENSITY", "EAC_RUNWAY_CENTRE_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the <LIGHT>s that mark the centre-line of a"
    " <RUNWAY>. Zero means minimum intensity and one means maximum"
    " intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_COUNT,
    "RUNWAY_COUNT", "EAC_RUNWAY_COUNT",
    "The number of <RUNWAY>s at an <AERODROME>; the runway count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[419]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_DISPLACED_THRESHOLD_DISTANCE,
    "RUNWAY_DISPLACED_THRESHOLD_DISTANCE", "EAC_RUNWAY_DISPLACED_THRESHOLD_DISTANCE",
    "The distance from the <RUNWAY_ENDPOINT> to that point of the <RUNWAY>"
    " usable for landing; the displaced threshold distance.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[372]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DTF and DTM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_EDGE_LIGHT_INTENSITY,
    "RUNWAY_EDGE_LIGHT_INTENSITY", "EAC_RUNWAY_EDGE_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the edge <LIGHT>s on a <RUNWAY>. Zero means"
    " minimum intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_END,
    "RUNWAY_END", "EAC_RUNWAY_END",
    "An indication of the <<TERRAIN_ELEVATION>> of the end of a <RUNWAY>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 2, &(EDCS_Enumerant_Dictionary[5998]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RWT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_END_BEARING,
    "RUNWAY_END_BEARING", "EAC_RUNWAY_END_BEARING",
    "A two character string containing two decimal digits between \"01\" to"
    " \"36\" inclusive and defined as follows. When there is a single"
    " <RUNWAY>, two parallel <RUNWAY>s, or three parallel <RUNWAY>s, the"
    " two digit whole number nearest to one-tenth of the"
    " <<MAGNETIC_AZIMUTH>> (for example: a <<MAGNETIC_AZIMUTH>> of 274"
    " degrees would be represented as \"27\") of the centre-line of the"
    " <RUNWAY> in the direction of approach; the runway end bearing. When"
    " there are four to six parallel runways, one set of two or three"
    " adjacent runways shall be numbered with the two digit whole number"
    " nearest to one-tenth of the magnetic azimuth and the other set of two"
    " or three adjacent runways numbered to the next nearest whole number."
    " When these rules would give a single digit number, it shall be"
    " preceded by a zero.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[347]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[IAN14, 5.2.2.4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_ENDPOINT_ELEVATION,
    "RUNWAY_ENDPOINT_ELEVATION", "EAC_RUNWAY_ENDPOINT_ELEVATION",
    "The <<ELEVATION>> of a <RUNWAY_ENDPOINT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[405]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: EHF, EHM, ELF, ELM, OHF, OHM, OLF, and OLM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_HIGH_END_IDENTIFIER,
    "RUNWAY_HIGH_END_IDENTIFIER", "EAC_RUNWAY_HIGH_END_IDENTIFIER",
    "The higher degree identification of a <RUNWAY>. The value is formatted"
    " in a Basic Latin string that begins with a two-character identifier"
    " ranging from 19-36, determined from the approach direction, derived"
    " from the <RUNWAY> magnetic heading (high end) rounded to the nearest"
    " ten arc degrees, and divided by ten; the runway high end identifier."
    " Designated in accordance with appropriate host nation documents."
    " Analyst derived <RUNWAY> numbers will use six arc degrees as the"
    " break off point for the next highest number. In the case of parallel"
    " runways, a third character is added to differentiate between left"
    " (L), right (R), centre (C), or STOL (S) <RUNWAY> positions. A fourth"
    " character, (T) True is added when the <RUNWAY> identifier and heading"
    " are true with no magnetic variation applied.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[392]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[DAFIF, Sec. 201.B.2, \"Identifier (High End)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_IDENTIFIER,
    "RUNWAY_IDENTIFIER", "EAC_RUNWAY_IDENTIFIER",
    "The identification of a <RUNWAY>. The value is formatted in a Basic"
    " Latin string that begins with a two-character identifier ranging from"
    " 01-36, derived from the <RUNWAY> geodetic heading, rounded to the"
    " nearest ten arc degrees and divided by ten. In the case of parallel"
    " <RUNWAY>s, a third character is added to differentiate between left"
    " (L), right (R), centre (C), or STOL (S) <RUNWAY> positions.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[392]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RID]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_LIGHTING_INTENSITY,
    "RUNWAY_LIGHTING_INTENSITY", "EAC_RUNWAY_LIGHTING_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the <LIGHTING> on a <RUNWAY>. Zero means"
    " minimum intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_LOW_END_IDENTIFIER,
    "RUNWAY_LOW_END_IDENTIFIER", "EAC_RUNWAY_LOW_END_IDENTIFIER",
    "The lower degree identification of a <RUNWAY>. The value is formatted"
    " in a Basic Latin string that begins with a two-character identifier"
    " ranging from 01-18, determined from the approach direction, derived"
    " from the <RUNWAY> magnetic heading (low end) rounded to the nearest"
    " ten arc degrees and divided by ten; the runway low end identifier."
    " Designated in accordance with appropriate host nation documents."
    " Analyst derived <RUNWAY> numbers will use six arc degrees as the"
    " break off point for the next highest number. In the case of parallel"
    " <RUNWAY>s, a third character is added to differentiate between left"
    " (L), right (R), centre (C), and STOL (S) runway positions. A fourth"
    " character (T) True is added when the <RUNWAY> identifier and heading"
    " are true with no magnetic variation applied.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[392]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[DAFIF, Sec. 201.B.3, \"Runway Identifier (Low End)\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_OIS_QUADRANT,
    "RUNWAY_OIS_QUADRANT", "EAC_RUNWAY_OIS_QUADRANT",
    "A number identifying a quadrant of a <RUNWAY> OIS as defined by the"
    " centre-line of the <RUNWAY> and a perpendicular to the centre-line of"
    " the <RUNWAY> intersecting at the centre point of the <RUNWAY>. The"
    " centre point of the <RUNWAY> is defined as falling midway between the"
    " <RUNWAY_ENDPOINT>s. Quadrant identifiers are assigned such that"
    " quadrants 1 and 2 are on one side and quadrants 3 and 4 are on the"
    " other side of the centre-line of the <RUNWAY>. Quadrant identifiers"
    " only apply to the following imaginary air navigation OISs of"
    " <RUNWAY>s: inner horizontal, conical, and outer horizontal.",
    EDCS_AVT_INDEX, 0,
    3, &(EGBindingForEA[392]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: QUD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_POINT_ABEAM_TYPE,
    "RUNWAY_POINT_ABEAM_TYPE", "EAC_RUNWAY_POINT_ABEAM_TYPE",
    "The type of offline <OBJECT> to which the point on a <RUNWAY> is abeam.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 8, &(EDCS_Enumerant_Dictionary[6000]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PAB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS_SECTION,
    "RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS_SECTION", "EAC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS_SECTION",
    "A number identifying a section of the imaginary <RUNWAY> air"
    " navigation primary approach transitional OIS. The <RUNWAY> primary"
    " approach transitional OIS is divided into two groups of sections: (1)"
    " Those sections corresponding to (and lateral of) the <RUNWAY> primary"
    " OIS sections which are (a) the approximately 914,4 metres (3 000"
    " feet) sections starting from the <RUNWAY_ENDPOINT>s and working"
    " inward, and (b) any middle section left over from (a); and (2) Those"
    " sections are lateral of the <RUNWAY> primary OIS and runway approach"
    " OIS, extending from the <RUNWAY> end outward. Each of these sections"
    " is numbered.",
    EDCS_AVT_INDEX, 0,
    3, &(EGBindingForEA[392]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PAN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_PRIMARY_OIS_SECTION,
    "RUNWAY_PRIMARY_OIS_SECTION", "EAC_RUNWAY_PRIMARY_OIS_SECTION",
    "A number identifying a section of the imaginary <RUNWAY> air"
    " navigation primary OIS. The <RUNWAY> primary OIS is divided into"
    " sections: (a) the 60,96 metre (200 feet) sections of the <RUNWAY>"
    " primary OIS from the <RUNWAY_ENDPOINT>s and working outward, (b) the"
    " approximately 914,4 metres (3 000 feet) sections starting from the"
    " <RUNWAY_ENDPOINT>s and working inward, and (c) any middle section"
    " left over from (b). Each of these sections is numbered.",
    EDCS_AVT_INDEX, 0,
    3, &(EGBindingForEA[392]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PSN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_REIL_INTENSITY,
    "RUNWAY_REIL_INTENSITY", "EAC_RUNWAY_REIL_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the end identifier <LIGHT>s on a <RUNWAY>;"
    " the runway REIL intensity. Zero means unlit and one means maximum"
    " intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_RELATIVE_POSITION,
    "RUNWAY_RELATIVE_POSITION", "EAC_RUNWAY_RELATIVE_POSITION",
    "The relative position of a <RUNWAY> in a <SET> of one to three"
    " parallel <RUNWAY>s with a given <<RUNWAY_END_BEARING>> as viewed by"
    " an approaching <AIRCRAFT> to the <SET> of <RUNWAY>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[419]), 4, &(EDCS_Enumerant_Dictionary[6008]),
    EDCS_REF_TYP_INFORMATIVE, "[IAN14, 5.2.2.4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_STOP_BAR_LIGHT_INTENSITY,
    "RUNWAY_STOP_BAR_LIGHT_INTENSITY", "EAC_RUNWAY_STOP_BAR_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the stop bar <LIGHT>s on a <RUNWAY>. Zero"
    " means minimum intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_STROBE_LIGHT_INTENSITY,
    "RUNWAY_STROBE_LIGHT_INTENSITY", "EAC_RUNWAY_STROBE_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the strobe <LIGHT>s on a <RUNWAY>. Zero means"
    " minimum intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_SURFACE_CONDITION,
    "RUNWAY_SURFACE_CONDITION", "EAC_RUNWAY_SURFACE_CONDITION",
    "The condition of the <SURFACE> of a <RUNWAY>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[416]), 7, &(EDCS_Enumerant_Dictionary[6012]),
    EDCS_REF_TYP_INFORMATIVE, "[AF15111, 11.3.4, \"Runway Condition\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_TAKEOFF_DISTANCE_AVAILABLE,
    "RUNWAY_TAKEOFF_DISTANCE_AVAILABLE", "EAC_RUNWAY_TAKEOFF_DISTANCE_AVAILABLE",
    "The <<LENGTH>> of takeoff distance on a <RUNWAY> plus the <<LENGTH>>"
    " of the <RUNWAY_OVERRUN>, if available.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[372]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[DAFIF, Sec. 201.B.34, \"Takeoff Distance Available\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_THRESHOLD_LIGHT_INTENSITY,
    "RUNWAY_THRESHOLD_LIGHT_INTENSITY", "EAC_RUNWAY_THRESHOLD_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the threshold <LIGHT>s on a <RUNWAY>. Zero"
    " means minimum intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_TOUCH_DOWN_LIGHT_INTENSITY,
    "RUNWAY_TOUCH_DOWN_LIGHT_INTENSITY", "EAC_RUNWAY_TOUCH_DOWN_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the touch down <LIGHT>s on a <RUNWAY>. Zero"
    " means minimum intensity and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[IAN14]", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_TOUCHDOWN_ZONE_ELEVATION,
    "RUNWAY_TOUCHDOWN_ZONE_ELEVATION", "EAC_RUNWAY_TOUCHDOWN_ZONE_ELEVATION",
    "The highest <<ELEVATION>> in the first 914,4 metres (3 000 feet) of"
    " the end of the usable landing <SURFACE> of a <RUNWAY>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[405]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: THM, TLM, TZH, and TZL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_VISIBILITY,
    "RUNWAY_VISIBILITY", "EAC_RUNWAY_VISIBILITY",
    "The visibility along an identified <RUNWAY> determined from a specific"
    " point on the <RUNWAY> with the observer facing in the same"
    " <DIRECTION> as a pilot using the <RUNWAY>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[402]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"runway visibility\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_RUNWAY_VISUAL_RANGE,
    "RUNWAY_VISUAL_RANGE", "EAC_RUNWAY_VISUAL_RANGE",
    "The maximum horizontal distance down an identified <RUNWAY> that a"
    " pilot of an <AIRCRAFT> on the centre-line of the <RUNWAY> can see the"
    " surface <RUNWAY_MARKINGS> or the <LIGHT>s delineating the <RUNWAY> or"
    " identifying the centre-line of the <RUNWAY>; the runway visual range.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[402]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"runway visual range\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SAND_DUNE_ORIENTATION,
    "SAND_DUNE_ORIENTATION", "EAC_SAND_DUNE_ORIENTATION",
    "The <<GEODETIC_AZIMUTH>> of the characteristic alignment of a"
    " <SAND_DUNE> as caused by the prevailing <WIND>s; the sand dune"
    " orientation.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[499]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SDO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SATELLITE_NAME,
    "SATELLITE_NAME", "EAC_SATELLITE_NAME",
    "The name of a <SATELLITE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1110]), 66, &(EDCS_Enumerant_Dictionary[6019]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SCND_WEAPON_DEPLOYED_POS_CATEGORY,
    "SCND_WEAPON_DEPLOYED_POS_CATEGORY", "EAC_SCND_WEAPON_DEPLOYED_POS_CATEGORY",
    "A category describing the <<SCND_WEAPON_DEPLOYED_POSITION>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 4, &(EDCS_Enumerant_Dictionary[6085]),
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.3, Bits: 24-25 (Weapon 2)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SCND_WEAPON_DEPLOYED_POSITION,
    "SCND_WEAPON_DEPLOYED_POSITION", "EAC_SCND_WEAPON_DEPLOYED_POSITION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional deployment of the secondary <WEAPON_SYSTEM> of an"
    " <OBJECT>. Zero means fully stowed/retracted and one means fully"
    " deployed.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1293]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.3, Weapon 2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SCRAP_TYPE,
    "SCRAP_TYPE", "EAC_SCRAP_TYPE",
    "The type of scrap.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[25]), 1, &(EDCS_Enumerant_Dictionary[6089]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WSC]",
    "[SOED, \"scrap\", 1.4]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEA_ICE_TYPE,
    "SEA_ICE_TYPE", "EAC_SEA_ICE_TYPE",
    "The type of <ICE> in the sea.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[23]), 10, &(EDCS_Enumerant_Dictionary[6090]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ICC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEA_NAME,
    "SEA_NAME", "EAC_SEA_NAME",
    "The name of a major <WATERBODY> (for example: a <SEA>, a"
    " <MARINE_STRAIT>, a <MARINE_GULF>, and/or a <MARINE_BAY>); the sea"
    " name.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1095]), 146, &(EDCS_Enumerant_Dictionary[6100]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[LOS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEA_STATE_CATEGORY,
    "SEA_STATE_CATEGORY", "EAC_SEA_STATE_CATEGORY",
    "The roughness of a <WATERBODY_SURFACE> in terms of the Douglas"
    " sea-state scale, a <SYSTEM> of categorized mean <WATER_WAVE> heights;"
    " the sea state category.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[54]), 10, &(EDCS_Enumerant_Dictionary[6246]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO306, Volume I.1, Part A, Code table 37000, Symbolic Letter S -"
    " State of the sea]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEA_STATE_NOISE_POWER_LEVEL,
    "SEA_STATE_NOISE_POWER_LEVEL", "EAC_SEA_STATE_NOISE_POWER_LEVEL",
    "The power level of acoustic noise energy in a <WATERBODY> due to"
    " <WATER_WAVE>s; the sea state noise.",
    EDCS_AVT_REAL, EQC_PRESSURE_POWER_LEVEL,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEARCH_LIGHT_INTENSITY,
    "SEARCH_LIGHT_INTENSITY", "EAC_SEARCH_LIGHT_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of moveable external <LIGHTING> that is used to"
    " illuminate the environment in arbitrary <DIRECTION>s; the spotlight,"
    " flashlight or search light intensity. Zero means unlit and one means"
    " maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1180]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 28 (Spot Lights)]",
    "[EBEV, 4.3.3, Bit: 12 (Flash Lights)]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEASON,
    "SEASON", "EAC_SEASON",
    "The division of the year (one of four) marked by the passage of the"
    " <SUN> through an equinox or solstice.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 4, &(EDCS_Enumerant_Dictionary[6256]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEASONAL_TENT_LOCATION,
    "SEASONAL_TENT_LOCATION", "EAC_SEASONAL_TENT_LOCATION",
    "The season in which the <TENT>s of a nomadic people are at a given"
    " <LOCATION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1331]), 2, &(EDCS_Enumerant_Dictionary[6260]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: STL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_AERIAL_DEPLOYED_POSITION,
    "SECONDARY_AERIAL_DEPLOYED_POSITION", "EAC_SECONDARY_AERIAL_DEPLOYED_POSITION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional deployment position of the secondary <AERIAL> on an"
    " <OBJECT>. Zero means fully stowed/retracted and one means fully"
    " deployed.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[748]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.6, Antenna]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_AXIS_VELOCITY_COMPONENT,
    "SECONDARY_AXIS_VELOCITY_COMPONENT", "EAC_SECONDARY_AXIS_VELOCITY_COMPONENT",
    "The <<VELOCITY>> component of an <OBJECT> along the secondary axis of"
    " a defined spatial reference frame.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_BREAKER_AZIMUTH,
    "SECONDARY_BREAKER_AZIMUTH", "EAC_SECONDARY_BREAKER_AZIMUTH",
    "The <<VECTOR_AZIMUTH_GEODETIC>> of a <LINE> drawn perpendicular to the"
    " <DIRECTION> of propagation of secondary breaking <WATER_WAVE>s in the"
    " wave spectra of a <SURF_ZONE>; the secondary breaker azimuth.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_BREAKER_RELATIVE_ANGLE,
    "SECONDARY_BREAKER_RELATIVE_ANGLE", "EAC_SECONDARY_BREAKER_RELATIVE_ANGLE",
    "The horizontal angle the secondary breaking <WATER_WAVE>s make with"
    " respect to the <BEACH>. The value increases from 0 when the <LINE> of"
    " the <WATER_WAVE>s parallels the <BEACH>, towards 90 arc degrees on"
    " either the right or left flank as seen from <VESSEL>s approaching the"
    " <BEACH>; the secondary breaker relative angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_BROADCAST_FREQUENCY,
    "SECONDARY_BROADCAST_FREQUENCY", "EAC_SECONDARY_BROADCAST_FREQUENCY",
    "The designated secondary broadcast <<FREQUENCY>> for a communications"
    " <DEVICE>.",
    EDCS_AVT_REAL, EQC_FREQUENCY,
    3, &(EGBindingForEA[745]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BR2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_DOOR_OPEN_POSITION,
    "SECONDARY_DOOR_OPEN_POSITION", "EAC_SECONDARY_DOOR_OPEN_POSITION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional opening of the secondary <DOOR> of an <OBJECT>. Zero means"
    " fully closed and one means fully open.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_MATERIAL_CHARACTERISTIC,
    "SECONDARY_MATERIAL_CHARACTERISTIC", "EAC_SECONDARY_MATERIAL_CHARACTERISTIC",
    "The characteristics of the composition of the secondary <MATERIAL> of"
    " an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[169]), 24, &(EDCS_Enumerant_Dictionary[6262]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_MATERIAL_TYPE,
    "SECONDARY_MATERIAL_TYPE", "EAC_SECONDARY_MATERIAL_TYPE",
    "The type of composition of the secondary <MATERIAL> of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[169]), 65, &(EDCS_Enumerant_Dictionary[6286]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MCS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_SURFACE_AIR_VELOCITY,
    "SECONDARY_SURFACE_AIR_VELOCITY", "EAC_SECONDARY_SURFACE_AIR_VELOCITY",
    "The <<VELOCITY>> of the <AIR> along the secondary <SURFACE> of an"
    " <OBJECT>, generally the bottom, back, or inner side of a layer of"
    " <MATERIAL>.",
    EDCS_AVT_REAL, EQC_SPEED,
    4, &(EGBindingForEA[668]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_SURFACE_TEMPERATURE,
    "SECONDARY_SURFACE_TEMPERATURE", "EAC_SECONDARY_SURFACE_TEMPERATURE",
    "The <<TEMPERATURE>> of the medium in contact with the secondary"
    " <SURFACE> of an <OBJECT>, generally the top, front, or outer side of"
    " a layer of <MATERIAL>; typically used as a boundary condition in"
    " thermal solutions.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[1279]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_SURFACE_THERMAL_CONDITION,
    "SECONDARY_SURFACE_THERMAL_CONDITION", "EAC_SECONDARY_SURFACE_THERMAL_CONDITION",
    "The physical boundary condition at the secondary <SURFACE> of an"
    " <OBJECT>, generally the top, front, or outer side of a layer of"
    " <MATERIAL>, that accounts for the thermal interface of an <OBJECT>"
    " with the environment at that <SURFACE>; the secondary surface thermal"
    " condition.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1274]), 13, &(EDCS_Enumerant_Dictionary[6351]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_SWELL_WAVE_DIRECTION,
    "SECONDARY_SWELL_WAVE_DIRECTION", "EAC_SECONDARY_SWELL_WAVE_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which secondary"
    " <SWELL_WAVE>s are arriving.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_SWELL_WAVE_HEIGHT,
    "SECONDARY_SWELL_WAVE_HEIGHT", "EAC_SECONDARY_SWELL_WAVE_HEIGHT",
    "The mean <<HEIGHT>> of the significant (highest one-third) secondary"
    " <SWELL_WAVE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_SWELL_WAVE_PERIOD,
    "SECONDARY_SWELL_WAVE_PERIOD", "EAC_SECONDARY_SWELL_WAVE_PERIOD",
    "The mean <<TIME_QUANTITY>> that a complete cycle (usually crest to"
    " crest or trough to trough) of a secondary <SWELL_WAVE> takes to pass"
    " a given fixed point.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECONDARY_WAVE_DIRECTION,
    "SECONDARY_WAVE_DIRECTION", "EAC_SECONDARY_WAVE_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which secondary"
    " <WATER_WAVE>s (combined <WIND_WAVE> and <SWELL_WAVE>) in the wave"
    " spectra are arriving.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "[JSM, section 508]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECTOR_DIRECTION,
    "SECTOR_DIRECTION", "EAC_SECTOR_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> of an angular sector for"
    " which the measurement applies.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECURITY_LEVEL,
    "SECURITY_LEVEL", "EAC_SECURITY_LEVEL",
    "The highest level of security associated with an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[181]), 5, &(EDCS_Enumerant_Dictionary[6364]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SEC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SECURITY_LOCK_TYPE,
    "SECURITY_LOCK_TYPE", "EAC_SECURITY_LOCK_TYPE",
    "The type of a security lock.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[14]), 10, &(EDCS_Enumerant_Dictionary[6369]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"lock\", I1]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_ATTENUATION_FREQUENCY_EXPONENT,
    "SEDIMENT_ATTENUATION_FREQUENCY_EXPONENT", "EAC_SEDIMENT_ATTENUATION_FREQUENCY_EXPONENT",
    "The quantity of frequency dependence of the absorption and scattering"
    " of acoustic energy as it travels through a <WATERBODY_FLOOR> in"
    " <<WATER_DEPTH>>s of 200 metres or less; the sediment attenuation"
    " exponent.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[302]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_ATTENUATION_GRADIENT,
    "SEDIMENT_ATTENUATION_GRADIENT", "EAC_SEDIMENT_ATTENUATION_GRADIENT",
    "The rate of change with respect to <<DEPTH_BELOW_WATERBODY_FLOOR>> of"
    " the distance and frequency gradient of the absorption and scattering"
    " of acoustic energy travelling through <SEDIMENT>; the sediment"
    " attenuation gradient.",
    EDCS_AVT_REAL, EQC_POWER_LEVEL_DIFF_LEN_FREQ,
    3, &(EGBindingForEA[291]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_BASEMENT_REFLECTION_COEFFICIENT,
    "SEDIMENT_BASEMENT_REFLECTION_COEFFICIENT", "EAC_SEDIMENT_BASEMENT_REFLECTION_COEFFICIENT",
    "The ratio of reflected acoustic energy to the incident acoustic energy"
    " at a <WATERBODY_FLOOR> sediment/basement interface; the sediment"
    " basement reflection coefficient.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[291]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_BELOW_LAYERS_DENSITY,
    "SEDIMENT_BELOW_LAYERS_DENSITY", "EAC_SEDIMENT_BELOW_LAYERS_DENSITY",
    "The density of layers of deep <SEDIMENT>s located below near-surface"
    " <SEDIMENT>s on a <WATERBODY_FLOOR>; the sediment below layers density.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    2, &(EGBindingForEA[1323]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_COMP_ATTENUATION,
    "SEDIMENT_COMP_ATTENUATION", "EAC_SEDIMENT_COMP_ATTENUATION",
    "The depth and frequency gradient of absorption and scattering of"
    " compressional waves while travelling through a layer of <SEDIMENT>;"
    " the sediment compressional attenuation.",
    EDCS_AVT_REAL, EQC_POWER_LEVEL_DIFF_LEN_FREQ,
    3, &(EGBindingForEA[281]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_COMP_WAVE_SPEED,
    "SEDIMENT_COMP_WAVE_SPEED", "EAC_SEDIMENT_COMP_WAVE_SPEED",
    "The <<SPEED>> of propagation of compressional waves in a <SEDIMENT>.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[291]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_COMP_WAVE_SPEED_CURVATURE,
    "SEDIMENT_COMP_WAVE_SPEED_CURVATURE", "EAC_SEDIMENT_COMP_WAVE_SPEED_CURVATURE",
    "The <<SPEED>> of propagation of compressional waves profile curvature"
    " parameter of a layer of <SEDIMENT>; the sound speed profile curvature.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[281]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_COMP_WAVE_SPEED_GRADIENT_TOP,
    "SEDIMENT_COMP_WAVE_SPEED_GRADIENT_TOP", "EAC_SEDIMENT_COMP_WAVE_SPEED_GRADIENT_TOP",
    "The rate at which the <<SPEED>> of propagation of compressional waves"
    " changes with depth in <SEDIMENT>, evaluated at a water-sediment"
    " interface.",
    EDCS_AVT_REAL, EQC_RATE,
    4, &(EGBindingForEA[277]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_CONDUCTIVITY,
    "SEDIMENT_CONDUCTIVITY", "EAC_SEDIMENT_CONDUCTIVITY",
    "The electrical conductivity of <SEDIMENT> on a <WATERBODY_FLOOR>.",
    EDCS_AVT_REAL, EQC_ELECTRIC_CONDUCTIVITY,
    3, &(EGBindingForEA[919]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_GRAIN_SIZE,
    "SEDIMENT_GRAIN_SIZE", "EAC_SEDIMENT_GRAIN_SIZE",
    "The negative of the logarithm to the base 2 of the grain diameter of"
    " <SEDIMENT> expressed in millimetres; the grain size.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[837]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_LAYER_DENSITY,
    "SEDIMENT_LAYER_DENSITY", "EAC_SEDIMENT_LAYER_DENSITY",
    "The <<MATERIAL_DENSITY>> of a layer of <SEDIMENT> on a"
    " <WATERBODY_FLOOR>.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    3, &(EGBindingForEA[1264]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_MEAN_BACKGROUND_THICKNESS,
    "SEDIMENT_MEAN_BACKGROUND_THICKNESS", "EAC_SEDIMENT_MEAN_BACKGROUND_THICKNESS",
    "The mean background <<THICKNESS>> of the layers of <SEDIMENT> located"
    " just below a <WATERBODY_FLOOR>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[842]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_REFLECTIVITY_ANGLE,
    "SEDIMENT_REFLECTIVITY_ANGLE", "EAC_SEDIMENT_REFLECTIVITY_ANGLE",
    "The angle between a layer of <SEDIMENT> on a <WATERBODY_FLOOR> and a"
    " compressional wave that is reflected from it; the sediment"
    " reflectivity angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[212]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_SHEAR_ATTENUATION,
    "SEDIMENT_SHEAR_ATTENUATION", "EAC_SEDIMENT_SHEAR_ATTENUATION",
    "The depth and frequency gradient of absorption and scattering of shear"
    " waves while travelling through a layer of <SEDIMENT>; the sediment"
    " shear attenuation.",
    EDCS_AVT_REAL, EQC_POWER_LEVEL_DIFF_LEN_FREQ,
    3, &(EGBindingForEA[281]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_SHEAR_WAVE_SPEED,
    "SEDIMENT_SHEAR_WAVE_SPEED", "EAC_SEDIMENT_SHEAR_WAVE_SPEED",
    "The <<SPEED>> of propagation of shear waves in a <SEDIMENT>.",
    EDCS_AVT_REAL, EQC_SPEED,
    4, &(EGBindingForEA[277]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_SRF_ATTENUATION,
    "SEDIMENT_SRF_ATTENUATION", "EAC_SEDIMENT_SRF_ATTENUATION",
    "The absorption and scattering coefficient of compressional waves"
    " travelling through <SEDIMENT> just below a <WATERBODY_FLOOR>; the"
    " sediment surface attenuation.",
    EDCS_AVT_REAL, EQC_POWER_LEVEL_DIFF_LEN_FREQ,
    3, &(EGBindingForEA[281]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_SRF_ATTENUATION_GRADIENT,
    "SEDIMENT_SRF_ATTENUATION_GRADIENT", "EAC_SEDIMENT_SRF_ATTENUATION_GRADIENT",
    "The distance and frequency gradient of <<SEDIMENT_SRF_ATTENUATION>>.",
    EDCS_AVT_REAL, EQC_GRAD_POWER_LEVEL_DIFF_LEN_FREQ,
    4, &(EGBindingForEA[277]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_SURFACE_DENSITY,
    "SEDIMENT_SURFACE_DENSITY", "EAC_SEDIMENT_SURFACE_DENSITY",
    "The <<MATERIAL_DENSITY>> of the top-most layer of <SEDIMENT> on a"
    " <WATERBODY_FLOOR>; the sediment surface density.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    3, &(EGBindingForEA[1264]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_THIN_LAYER_DENSITY,
    "SEDIMENT_THIN_LAYER_DENSITY", "EAC_SEDIMENT_THIN_LAYER_DENSITY",
    "The <<MATERIAL_DENSITY>> of a surficial layer of <SEDIMENT> on a"
    " <WATERBODY_FLOOR>; the sediment thin-layer density.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    3, &(EGBindingForEA[1264]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_THIN_LAYER_THICKNESS,
    "SEDIMENT_THIN_LAYER_THICKNESS", "EAC_SEDIMENT_THIN_LAYER_THICKNESS",
    "The <<THICKNESS>> of the surficial thin-layer of <SEDIMENT> on a"
    " <WATERBODY_FLOOR>; the sediment thin-layer <<THICKNESS>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[842]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_TWO_WAY_TRAVEL_TIME,
    "SEDIMENT_TWO_WAY_TRAVEL_TIME", "EAC_SEDIMENT_TWO_WAY_TRAVEL_TIME",
    "The quantity of time required for compressional waves to travel"
    " vertically from a <WATERBODY_FLOOR> to the sediment/basement"
    " interface and back to the <SURFACE> of that <WATERBODY_FLOOR>; the"
    " sediment two-way travel time.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[299]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEDIMENT_WATER_COMP_WAVE_SPEED_RATIO,
    "SEDIMENT_WATER_COMP_WAVE_SPEED_RATIO", "EAC_SEDIMENT_WATER_COMP_WAVE_SPEED_RATIO",
    "The ratio of the <<SPEED>> of compressional waves in a <SEDIMENT> to"
    " that in the column of <WATER> above it.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[277]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Low-Frequency Bottom-Loss Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SENSIBLE_HEAT_FLUX,
    "SENSIBLE_HEAT_FLUX", "EAC_SENSIBLE_HEAT_FLUX",
    "The rate of heat flow between a <PLANETARY_SURFACE> and the"
    " <ATMOSPHERE>; the sensible heat flux.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    2, &(EGBindingForEA[1319]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SERVICE_BRANCH,
    "SERVICE_BRANCH", "EAC_SERVICE_BRANCH",
    "The branch of a military service or organization.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 6, &(EDCS_Enumerant_Dictionary[6379]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: YSU]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SEVERE_WEATHER_PRESENT,
    "SEVERE_WEATHER_PRESENT", "EAC_SEVERE_WEATHER_PRESENT",
    "An indication that severe weather is present. Severe weather is any"
    " atmospheric condition potentially destructive or hazardous to"
    " <HUMAN>s.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"severe weather\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHARP_CURVE_RADIUS,
    "SHARP_CURVE_RADIUS", "EAC_SHARP_CURVE_RADIUS",
    "The radius of curvature of a <SHARP_CURVE> in a"
    " <LAND_TRANSPORTATION_ROUTE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: RAD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHELTER_BELT,
    "SHELTER_BELT", "EAC_SHELTER_BELT",
    "An indication that an <OBJECT> (for example: a linear stand of"
    " <TREE>s) functions as a shelter belt, protecting other <OBJECT>s from"
    " the effects of adverse weather.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[93]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SBC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHIPPING_NOISE_MEASUREMENT_STATUS,
    "SHIPPING_NOISE_MEASUREMENT_STATUS", "EAC_SHIPPING_NOISE_MEASUREMENT_STATUS",
    "The measurement status of a shipping noise level in a <WATERBODY>;"
    " typically taken at 50 hertz.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[304]), 2, &(EDCS_Enumerant_Dictionary[6385]),
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHIPPING_NOISE_SEASON_TYPE,
    "SHIPPING_NOISE_SEASON_TYPE", "EAC_SHIPPING_NOISE_SEASON_TYPE",
    "The seasonally adjusted acoustic noise characteristics (for example:"
    " spectral class, standard deviation, and/or decibels per octave"
    " roll-off) in a <WATERBODY> due to distant shipping; the shipping"
    " noise season type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[304]), 24, &(EDCS_Enumerant_Dictionary[6387]),
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL_ROLL_OFF,
    "SHIPPING_NOISE_SPECTRAL_POWER_LEVEL_ROLL_OFF", "EAC_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL_ROLL_OFF",
    "The gradient in the shipping noise spectral power level in a"
    " <WATERBODY> as a function of <<FREQUENCY>>, typically above 300"
    " hertz; the shipping noise roll-off.",
    EDCS_AVT_REAL, EQC_POWER_LEVEL_DIFF_FREQ_GRADIENT,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHIPPING_NOISE_STD_DEV,
    "SHIPPING_NOISE_STD_DEV", "EAC_SHIPPING_NOISE_STD_DEV",
    "The standard deviation of shipping noise spectral power level"
    " measurements in a <WATERBODY>; typically taken at 50 hertz.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Shipping Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHORELINE_DELINEATED,
    "SHORELINE_DELINEATED", "EAC_SHORELINE_DELINEATED",
    "An indication that the delineation of a <SHORELINE> is definite.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[57]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: SHD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHORELINE_PHYSIOGRAPHY,
    "SHORELINE_PHYSIOGRAPHY", "EAC_SHORELINE_PHYSIOGRAPHY",
    "The topography and types of <MATERIAL> found on a <SHORE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1200]), 11, &(EDCS_Enumerant_Dictionary[6411]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SHO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHORELINE_TYPE,
    "SHORELINE_TYPE", "EAC_SHORELINE_TYPE",
    "The type of physical characteristics of a <SHORELINE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1203]), 11, &(EDCS_Enumerant_Dictionary[6422]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SLT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SHOWALTER_ATMOSPHERE_STABILITY_INDEX,
    "SHOWALTER_ATMOSPHERE_STABILITY_INDEX", "EAC_SHOWALTER_ATMOSPHERE_STABILITY_INDEX",
    "The degree of stability of the layer of the <ATMOSPHERE> extending"
    " from a level near the <PLANETARY_SURFACE> of the <EARTH> to the 500"
    " hectopascals (500 millibar) pressure as calculated by the Showalter"
    " method; the Showalter atmosphere stability index.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"Showalter's stability index\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIDES_VISIBLE,
    "SIDES_VISIBLE", "EAC_SIDES_VISIBLE",
    "The sides of an <OBJECT> that are visible.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[159]), 3, &(EDCS_Enumerant_Dictionary[6433]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGMA_COORDINATE_VERTICAL_VELOCITY,
    "SIGMA_COORDINATE_VERTICAL_VELOCITY", "EAC_SIGMA_COORDINATE_VERTICAL_VELOCITY",
    "The <<WIND_OMEGA>> through a pressure <SURFACE> normalized by the"
    " <<ATM_PRESSURE>> at the <PLANETARY_SURFACE> of the <EARTH>; the sigma"
    " coordinate vertical velocity.",
    EDCS_AVT_REAL, EQC_RATE,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO306, Volume I.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGMA_CROSSWIND_SPREADING_RATE,
    "SIGMA_CROSSWIND_SPREADING_RATE", "EAC_SIGMA_CROSSWIND_SPREADING_RATE",
    "The rate of change per unit time of <<SIGMA_WIDTH_CROSSWIND>>; the"
    " sigma crosswind spreading rate.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APMD, 4.8.5]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGMA_DOWNWIND_SPREADING_RATE,
    "SIGMA_DOWNWIND_SPREADING_RATE", "EAC_SIGMA_DOWNWIND_SPREADING_RATE",
    "The rate of change per unit time of <<SIGMA_WIDTH_DOWNWIND>>; the"
    " sigma downwind spreading rate.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APMD, 4.8.5]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGMA_VERTICAL_SPREADING_RATE,
    "SIGMA_VERTICAL_SPREADING_RATE", "EAC_SIGMA_VERTICAL_SPREADING_RATE",
    "The rate of change per unit time of <<SIGMA_WIDTH_VERTICAL>>; the"
    " sigma vertical spreading rate.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGMA_WIDTH_CROSSWIND,
    "SIGMA_WIDTH_CROSSWIND", "EAC_SIGMA_WIDTH_CROSSWIND",
    "The horizontal dimension of a <PLUME> or <PUFF> measured in the"
    " crosswind dimension between points that are symmetric about the"
    " centre of <<MASS>> where 68% of the total <<MASS>> is found; the"
    " sigma width crosswind.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[432]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APMD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGMA_WIDTH_DOWNWIND,
    "SIGMA_WIDTH_DOWNWIND", "EAC_SIGMA_WIDTH_DOWNWIND",
    "The horizontal dimension of a <PLUME> or <PUFF> measured in the"
    " downwind dimension between points that are symmetric about the centre"
    " of <<MASS>> where 68% of the total <<MASS>> is found; the sigma width"
    " downwind.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[432]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APMD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGMA_WIDTH_VERTICAL,
    "SIGMA_WIDTH_VERTICAL", "EAC_SIGMA_WIDTH_VERTICAL",
    "The vertical height of a <PLUME> or <PUFF> measured along the vertical"
    " dimension between points that are symmetric about the centre of"
    " <<MASS>> where 68% of the total <<MASS>> is found; the vertical sigma"
    " width.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[432]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[APMD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNAL_LIGHT_CHARACTER,
    "SIGNAL_LIGHT_CHARACTER", "EAC_SIGNAL_LIGHT_CHARACTER",
    "A characterization of the signal light emitted by one or more <LIGHT>s"
    " at one <LOCATION>. This information is formatted in a Basic Latin"
    " string giving the class, number, and colours of flashes or"
    " occultations. EXAMPLES \"Q(6)+L F1\", \"VQ G\", \"L F1 (3+2)WR\".",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    3, &(EGBindingForEA[722]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: COL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNAL_LIGHT_PATTERN,
    "SIGNAL_LIGHT_PATTERN", "EAC_SIGNAL_LIGHT_PATTERN",
    "The temporal pattern of one complete period of a repeating signal"
    " <LIGHT>. The pattern is formatted in a Basic Latin string as a list"
    " of relative duty cycle lengths representing the alternating on and"
    " off times of the signal beginning with the length of an ON signal."
    " The duty cycle lengths are expressed as integers separated by commas;"
    " spaces are ignored.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[757]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GRP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNAL_LIGHT_PATTERN_COUNT,
    "SIGNAL_LIGHT_PATTERN_COUNT", "EAC_SIGNAL_LIGHT_PATTERN_COUNT",
    "The number of flashes/occultations in a group flashing/occulting"
    " <<SIGNAL_LIGHT_PATTERN>>; the signal light pattern count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[757]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: LCN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNAL_LIGHT_SEQUENCE,
    "SIGNAL_LIGHT_SEQUENCE", "EAC_SIGNAL_LIGHT_SEQUENCE",
    "The specification of the sequence of <<TIME_QUANTITY>>s occupied by"
    " intervals of light and dark (eclipse) of a signal <LIGHT>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[759]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SEQ]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNIF_PRIMARY_BREAKER_HEIGHT,
    "SIGNIF_PRIMARY_BREAKER_HEIGHT", "EAC_SIGNIF_PRIMARY_BREAKER_HEIGHT",
    "The mean <<HEIGHT>> measured from trough to crest of the significant"
    " (highest one-third) primary breaking <WATER_WAVE>s in a <SURF_ZONE>"
    " wave spectrum.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNIF_SECONDARY_BREAKER_HEIGHT,
    "SIGNIF_SECONDARY_BREAKER_HEIGHT", "EAC_SIGNIF_SECONDARY_BREAKER_HEIGHT",
    "The mean <<HEIGHT>> measured from trough to crest of the significant"
    " (highest one-third) secondary breaking <WATER_WAVE>s in a <SURF_ZONE>"
    " wave spectrum.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM2, Chapter 4]",
    "[JSM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNIF_SWELL_WAVE_HEIGHT,
    "SIGNIF_SWELL_WAVE_HEIGHT", "EAC_SIGNIF_SWELL_WAVE_HEIGHT",
    "The mean <<HEIGHT>> measured from trough to crest of the significant"
    " (highest one-third) <SWELL_WAVE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGC1, Chapter 6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNIF_WAVE_HEIGHT,
    "SIGNIF_WAVE_HEIGHT", "EAC_SIGNIF_WAVE_HEIGHT",
    "The mean <<HEIGHT>> measured from trough to crest of the significant"
    " (highest one-third) <WATER_WAVE>s (combined <WIND_WAVE>s and"
    " <SWELL_WAVE>s).",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGC1, Chapter 6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIGNIF_WIND_WAVE_HEIGHT,
    "SIGNIF_WIND_WAVE_HEIGHT", "EAC_SIGNIF_WIND_WAVE_HEIGHT",
    "The mean height of the significant (highest one-third) <WIND_WAVE>s,"
    " measured from trough to crest.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGC1, Chapter 6]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SINGLE_WHEEL_BEARING_LOAD,
    "SINGLE_WHEEL_BEARING_LOAD", "EAC_SINGLE_WHEEL_BEARING_LOAD",
    "The estimated load bearing capacity of a <LAND_TRANSPORTATION_ROUTE>"
    " for a single wheel of a <GROUND_VEHICLE>.",
    EDCS_AVT_REAL, EQC_MASS,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SWL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SIPLE_PASSEL_WIND_CHILL_INDEX,
    "SIPLE_PASSEL_WIND_CHILL_INDEX", "EAC_SIPLE_PASSEL_WIND_CHILL_INDEX",
    "A means of quantifying the combined effect of low <<AIR_TEMPERATURE>>"
    " and <<WIND_SPEED>> on the body <<TEMPERATURE>> of <HUMAN>s that may"
    " result in hypothermia, expressed as an equivalent <<AIR_TEMPERATURE>>"
    " in degrees Celsius given by the formula: 0,0817 * [(5,5488 * V^(0,5))"
    " + 5,81 + (0,5592 * V)] * [T - 33,0] + 33,0 where V is the"
    " <<WIND_SPEED>> in metres per second at a <<HEIGHT_AGL>> of 10 metres"
    " (approximately 33 feet) and T is the <<AIR_TEMPERATURE>> in degrees"
    " Celsius; the Siple-Passel Wind Chill Index.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SKY_GROUND_LUMINANCE_RATIO,
    "SKY_GROUND_LUMINANCE_RATIO", "EAC_SKY_GROUND_LUMINANCE_RATIO",
    "The ratio of sky luminance to non-sky luminance; the sky ground ratio.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[29]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SKY_OBSCURATION_FRACTION,
    "SKY_OBSCURATION_FRACTION", "EAC_SKY_OBSCURATION_FRACTION",
    "The fraction of the sky that is covered by <FOG> or other low-altitude"
    " atmospheric phenomena, determined at a <PLANETARY_SURFACE>; the sky"
    " obscuration fraction.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[449]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SLAVED_DECLINATION,
    "SLAVED_DECLINATION", "EAC_SLAVED_DECLINATION",
    "A fixed value of magnetic variation applied within <EQUIPMENT>"
    " functioning as an <AID_TO_NAVIGATION> to the true <DIRECTION> in"
    " order to obtain the magnetic values for radials, courses and"
    " headings; a slaved declination.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[515]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SVA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SMOKE_RATE_FRACTION,
    "SMOKE_RATE_FRACTION", "EAC_SMOKE_RATE_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the production rate of <SMOKE> by an <OBJECT>. Zero means"
    " no <SMOKE> at all and one means maximum production.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[456]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bits: 5-6 (Smoke)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SMOKESTACK_COUNT,
    "SMOKESTACK_COUNT", "EAC_SMOKESTACK_COUNT",
    "The number of <SMOKESTACK>s associated with an <OBJECT>; the"
    " smokestack count.",
    EDCS_AVT_COUNT, 0,
    3, &(EGBindingForEA[76]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SNOW_ACCUM_DEPTH,
    "SNOW_ACCUM_DEPTH", "EAC_SNOW_ACCUM_DEPTH",
    "The <<DEPTH>> of <SNOW_GROUND_COVER> that has accumulated over an"
    " <<ACCUMULATION_PERIOD>> or <<ACCUMULATION_PERIOD_CATEGORY>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    5, &(EGBindingForEA[596]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 12.7.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SNOW_ACCUM_DEPTH_EQUIVALENT,
    "SNOW_ACCUM_DEPTH_EQUIVALENT", "EAC_SNOW_ACCUM_DEPTH_EQUIVALENT",
    "The <<DEPTH>> of the liquid <WATER> that is equivalent in content to"
    " the <SNOW_GROUND_COVER> (not <ICE>) that has accumulated over an"
    " <<ACCUMULATION_PERIOD>> or <<ACCUMULATION_PERIOD_CATEGORY>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    5, &(EGBindingForEA[596]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SNOW_AGE,
    "SNOW_AGE", "EAC_SNOW_AGE",
    "The time difference between the reference date and the date of the"
    " last measurable <SNOW_PRECIPITATION>; the snow age.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[641]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SNOW-ANALYSIS-FORECAST age quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SNOW_DENSITY,
    "SNOW_DENSITY", "EAC_SNOW_DENSITY",
    "The density of accumulated <SNOW_PRECIPITATION> on an <OBJECT>.",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    6, &(EGBindingForEA[631]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SNOW_DEPTH_CATEGORY,
    "SNOW_DEPTH_CATEGORY", "EAC_SNOW_DEPTH_CATEGORY",
    "A category describing the <<SNOW_ONLY_DEPTH>>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[637]), 9, &(EDCS_Enumerant_Dictionary[6436]),
    EDCS_REF_TYP_INFORMATIVE, "[CMIS, Table 3-1, \"Snow Depth Ranges\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SNOW_DRIFT_HEIGHT,
    "SNOW_DRIFT_HEIGHT", "EAC_SNOW_DRIFT_HEIGHT",
    "The maximum height of drifts of <SNOW_GROUND_COVER>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    5, &(EGBindingForEA[596]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SNOW-DEPTH drift height dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SNOW_MELTING_RATE,
    "SNOW_MELTING_RATE", "EAC_SNOW_MELTING_RATE",
    "The melting rate of <SNOW_GROUND_COVER> as measured by"
    " <<SNOW_ONLY_DEPTH>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    4, &(EGBindingForEA[1079]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SNOW-ANALYSIS-FORECAST melting rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SNOW_ONLY_DEPTH,
    "SNOW_ONLY_DEPTH", "EAC_SNOW_ONLY_DEPTH",
    "The depth of the <SNOW_GROUND_COVER> that may be over <TERRAIN>,"
    " <TERRAIN> covered by <ICE>, or floating <ICE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    5, &(EGBindingForEA[596]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_COMPRESSIONAL_VELOCITY,
    "SOIL_COMPRESSIONAL_VELOCITY", "EAC_SOIL_COMPRESSIONAL_VELOCITY",
    "The <<VELOCITY>> of displacement of <SOIL> in the same <DIRECTION> as"
    " the compressional (density) wave through that <SOIL> (V[sub(P)]); the"
    " soil compressional velocity.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_CONE_INDEX,
    "SOIL_CONE_INDEX", "EAC_SOIL_CONE_INDEX",
    "The force per unit basal area required to push a cone penetrometer"
    " through an increment of <SOIL>; typically measured at depths from 0,0"
    " to 0,6 metres; the soil cone index.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    1, &(EGBindingForEA[33]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SMSP, Tables 31 and 32]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_DENSITY_DRY,
    "SOIL_DENSITY_DRY", "EAC_SOIL_DENSITY_DRY",
    "The average <<MATERIAL_DENSITY>> of the <SOIL>, between the <SURFACE>"
    " of the <TERRAIN> and the <BEDROCK>, after it has been dried to a"
    " constant <<MASS>> at 378,15 kelvin (105 degrees Celsius).",
    EDCS_AVT_REAL, EQC_VOLUMIC_MASS,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[DESCI, \"bulk density\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_DEPTH,
    "SOIL_DEPTH", "EAC_SOIL_DEPTH",
    "The <<DEPTH>> of <SOIL> or unconsolidated <MATERIAL> from the"
    " <SURFACE> of the <TERRAIN> to <BEDROCK>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[837]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SDE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_LAYER_DEPTH,
    "SOIL_LAYER_DEPTH", "EAC_SOIL_LAYER_DEPTH",
    "The <<DEPTH>> of the top of a layer of <SOIL> measured from the"
    " <SURFACE> of the <TERRAIN>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1234]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_MOISTURE_MASS_LOWER_LAYER,
    "SOIL_MOISTURE_MASS_LOWER_LAYER", "EAC_SOIL_MOISTURE_MASS_LOWER_LAYER",
    "The <<MASS>> of <WATER> contained between <<SOIL_LAYER_DEPTH>> 5 and"
    " <<SOIL_LAYER_DEPTH>> 100 centimetres; the lower layer soil moisture"
    " mass.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    3, &(EGBindingForEA[1063]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WDFH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_MOISTURE_MASS_TOP_LAYER,
    "SOIL_MOISTURE_MASS_TOP_LAYER", "EAC_SOIL_MOISTURE_MASS_TOP_LAYER",
    "The <<MASS>> of <WATER> contained between <<SOIL_LAYER_DEPTH>> 0 and"
    " <<SOIL_LAYER_DEPTH>> 5 centimetres below the <SURFACE> of the"
    " <TERRAIN>; the top layer soil moisture mass.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    3, &(EGBindingForEA[1063]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WDFH]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_SEISMIC_ABSORPTION_COEFFICIENT,
    "SOIL_SEISMIC_ABSORPTION_COEFFICIENT", "EAC_SOIL_SEISMIC_ABSORPTION_COEFFICIENT",
    "The coefficient in an exponential model of attenuation of seismic"
    " waves by <SOIL>; the soil seismic absorption coefficient. If A and"
    " A[sub(0)] are resultant and initial amplitudes, respectively, at a"
    " given <<FREQUENCY>>, x the distance travelled and a the soil seismic"
    " absorption coefficient, they are related by the equation: A ="
    " A[sub(0)] * exp(-ax).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[487]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_SHEAR_VELOCITY,
    "SOIL_SHEAR_VELOCITY", "EAC_SOIL_SHEAR_VELOCITY",
    "The <<VELOCITY>> of displacement of <SOIL> in the <DIRECTION>"
    " perpendicular to the compressional (density) wave through that <SOIL>"
    " (V[sub(S)]); the soil shear velocity.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1256]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_SURFACE_TEMPERATURE,
    "SOIL_SURFACE_TEMPERATURE", "EAC_SOIL_SURFACE_TEMPERATURE",
    "The <<TEMPERATURE>> of the <SOIL> at the <SURFACE> of the <TERRAIN>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1288]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SOIL-TEMPERATURE-OBSERVATION soil temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_TYPE,
    "SOIL_TYPE", "EAC_SOIL_TYPE",
    "The USCS type of the <SOIL>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[33]), 19, &(EDCS_Enumerant_Dictionary[6445]),
    EDCS_REF_TYP_INFORMATIVE, "[LAMB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_WATER_MASS,
    "SOIL_WATER_MASS", "EAC_SOIL_WATER_MASS",
    "The <WATER> lost from the <SOIL> upon drying to constant <<MASS>> at"
    " 378,15 kelvin (105 degrees Celsius). The value is expressed as the"
    " fractional <<MASS>> of <WATER> per unit <<MASS>> of wet <SOIL>; the"
    " soil water mass.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    3, &(EGBindingForEA[1063]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[STWC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_WATER_VOLUME,
    "SOIL_WATER_VOLUME", "EAC_SOIL_WATER_VOLUME",
    "The <WATER> lost from the <SOIL> upon drying to constant <<MASS>> at"
    " 378,15 kelvin (105 degrees Celsius). The value is expressed as the"
    " fractional <<VOLUME>> of <WATER> per unit bulk <<VOLUME>> of wet"
    " <SOIL>; the soil water volume.",
    EDCS_AVT_REAL, EQC_VOLUME_FRACTION,
    3, &(EGBindingForEA[1063]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[STWC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOIL_WETNESS_CATEGORY,
    "SOIL_WETNESS_CATEGORY", "EAC_SOIL_WETNESS_CATEGORY",
    "A category describing the content of liquid and solid <WATER> in the"
    " <SOIL> of a <TERRAIN_SURFACE_REGION>; the soil wetness category.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1061]), 8, &(EDCS_Enumerant_Dictionary[6464]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SWC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOLAR_DIFFUSE_IRRADIANCE,
    "SOLAR_DIFFUSE_IRRADIANCE", "EAC_SOLAR_DIFFUSE_IRRADIANCE",
    "The diffuse solar incident flux per unit <<AREA>> of the <SURFACE> of"
    " an <OBJECT>; the solar diffuse irradiance.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    3, &(EGBindingForEA[945]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOLAR_DIRECT_IRRADIANCE,
    "SOLAR_DIRECT_IRRADIANCE", "EAC_SOLAR_DIRECT_IRRADIANCE",
    "The direct solar incident flux per unit <<AREA>> of the <SURFACE> of"
    " an <OBJECT>; the solar direct irradiance.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    3, &(EGBindingForEA[945]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOLAR_RADIANCE_AZIMUTH_GEODETIC,
    "SOLAR_RADIANCE_AZIMUTH_GEODETIC", "EAC_SOLAR_RADIANCE_AZIMUTH_GEODETIC",
    "The solar <<INCIDENCE_AZIMUTH_GEODETIC>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[525]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOLAR_RADIANCE_AZIMUTH_LOCAL,
    "SOLAR_RADIANCE_AZIMUTH_LOCAL", "EAC_SOLAR_RADIANCE_AZIMUTH_LOCAL",
    "The solar <<INCIDENCE_AZIMUTH_LOCAL>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[525]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOLAR_RADIANCE_AZIMUTH_MAGNETIC,
    "SOLAR_RADIANCE_AZIMUTH_MAGNETIC", "EAC_SOLAR_RADIANCE_AZIMUTH_MAGNETIC",
    "The solar <<INCIDENCE_AZIMUTH_MAGNETIC>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[525]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOLAR_RADIANCE_ELEV_ANGLE_HORIZONTAL,
    "SOLAR_RADIANCE_ELEV_ANGLE_HORIZONTAL", "EAC_SOLAR_RADIANCE_ELEV_ANGLE_HORIZONTAL",
    "The solar <<INCIDENCE_ELEV_ANGLE_HORIZONTAL>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[525]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOLAR_RADIANCE_ELEV_ANGLE_LOCAL,
    "SOLAR_RADIANCE_ELEV_ANGLE_LOCAL", "EAC_SOLAR_RADIANCE_ELEV_ANGLE_LOCAL",
    "The solar <<INCIDENCE_ELEV_ANGLE_LOCAL>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    4, &(EGBindingForEA[525]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOLAR_RADIATION_CUMULATIVE,
    "SOLAR_RADIATION_CUMULATIVE", "EAC_SOLAR_RADIATION_CUMULATIVE",
    "The rate of solar radiation received over a twenty-four hour"
    " <<TIME_QUANTITY>>; the solar radiation cumulative.",
    EDCS_AVT_REAL, EQC_IRRADIANCE,
    3, &(EGBindingForEA[926]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SONAR_CONFIRMATION,
    "SONAR_CONFIRMATION", "EAC_SONAR_CONFIRMATION",
    "An indication that the presence of an <OBJECT> has been confirmed by"
    " sonar.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[55]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: SCS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SONIC_LAYER_DEPTH,
    "SONIC_LAYER_DEPTH", "EAC_SONIC_LAYER_DEPTH",
    "The depth of the layer near a <WATERBODY_SURFACE> into which sound"
    " rays are trapped by upward refraction effects; the sonic layer depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[274]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"sonic layer depth\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOUND_SIGNAL_PRESENT,
    "SOUND_SIGNAL_PRESENT", "EAC_SOUND_SIGNAL_PRESENT",
    "An indication that an audible marine signal is generated by a"
    " <MARINE_AID_TO_NAVIGATION>.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[229]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, SST:16]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOUND_SIGNAL_TYPE,
    "SOUND_SIGNAL_TYPE", "EAC_SOUND_SIGNAL_TYPE",
    "The means used to generate an audible marine signal; the sound signal"
    " type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[229]), 16, &(EDCS_Enumerant_Dictionary[6472]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SST]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOUNDING_DATUM_TYPE,
    "SOUNDING_DATUM_TYPE", "EAC_SOUNDING_DATUM_TYPE",
    "The type of a <SOUNDING_DATUM>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1245]), 43, &(EDCS_Enumerant_Dictionary[6488]),
    EDCS_REF_TYP_INFORMATIVE, "[S57A, Attribute: VERDAT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOUNDING_EXPOSITION,
    "SOUNDING_EXPOSITION", "EAC_SOUNDING_EXPOSITION",
    "The type of exposition of a <<DEPTH_OF_WATERBODY_FLOOR>> measured by"
    " sounding with respect to the surrounding <REGION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1343]), 3, &(EDCS_Enumerant_Dictionary[6531]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SOU]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOUNDING_INFORMATION,
    "SOUNDING_INFORMATION", "EAC_SOUNDING_INFORMATION",
    "Additional information about a <<DEPTH_OF_WATERBODY_FLOOR>> measured"
    " by sounding.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1343]), 19, &(EDCS_Enumerant_Dictionary[6534]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SND]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOUNDING_MEASUREMENT_TECHNIQUE,
    "SOUNDING_MEASUREMENT_TECHNIQUE", "EAC_SOUNDING_MEASUREMENT_TECHNIQUE",
    "The type of sounding technique and/or method of measurement of a"
    " <<DEPTH_OF_WATERBODY_FLOOR>>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1343]), 14, &(EDCS_Enumerant_Dictionary[6553]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: TECSOU]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOUNDING_VELOCITY_CORRECTION_TYPE,
    "SOUNDING_VELOCITY_CORRECTION_TYPE", "EAC_SOUNDING_VELOCITY_CORRECTION_TYPE",
    "The type of correction that has been added to or subtracted from a"
    " sounding velocity instrument reading to obtain the correct"
    " <<DEPTH_OF_WATERBODY_FLOOR>>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1343]), 5, &(EDCS_Enumerant_Dictionary[6567]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SVC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOURCE,
    "SOURCE", "EAC_SOURCE",
    "The source from which the identification of an <OBJECT> was captured"
    " or upgraded.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[24]), 59, &(EDCS_Enumerant_Dictionary[6572]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: STC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOURCE_DATA_SET_COMPILE_DATE,
    "SOURCE_DATA_SET_COMPILE_DATE", "EAC_SOURCE_DATA_SET_COMPILE_DATE",
    "The date a source data set (for example: a <MAP>) was originally"
    " compiled. The date is formatted as specified by <<DATE_FORMAT>> or by"
    " <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOURCE_DATA_SET_EDITION,
    "SOURCE_DATA_SET_EDITION", "EAC_SOURCE_DATA_SET_EDITION",
    "The edition of a source data set (for example: a <MAP>).",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[24]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOURCE_DATA_SET_GENERAL_INFORMATION,
    "SOURCE_DATA_SET_GENERAL_INFORMATION", "EAC_SOURCE_DATA_SET_GENERAL_INFORMATION",
    "General information about, and description of conditions within, a"
    " source data set (for example: a <MAP>).",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[6]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOURCE_DATA_SET_NAME,
    "SOURCE_DATA_SET_NAME", "EAC_SOURCE_DATA_SET_NAME",
    "The name or identification number of the first source data set (for"
    " example: a <MAP>).",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[24]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOURCE_DATA_SET_PRINT_DATE,
    "SOURCE_DATA_SET_PRINT_DATE", "EAC_SOURCE_DATA_SET_PRINT_DATE",
    "The date a source data set (for example: a <MAP>) was last printed."
    " The date is formatted as specified by <<DATE_FORMAT>> or by"
    " <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SOURCE_DATA_SET_REVISION_DATE,
    "SOURCE_DATA_SET_REVISION_DATE", "EAC_SOURCE_DATA_SET_REVISION_DATE",
    "The date a source data set (for example: a <MAP>) was last revised."
    " The date is formatted as specified by <<DATE_FORMAT>> or by"
    " <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE,
    "SPATIAL_ANGULAR_PRIMARY_COORDINATE", "EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE",
    "The angular primary axis coordinate value for a defined spatial"
    " reference frame.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE,
    "SPATIAL_ANGULAR_SECONDARY_COORDINATE", "EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE",
    "The angular secondary axis coordinate value for a defined spatial"
    " reference frame.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE,
    "SPATIAL_LINEAR_PRIMARY_COORDINATE", "EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE",
    "The linear primary axis coordinate value for a defined spatial"
    " reference frame.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE,
    "SPATIAL_LINEAR_SECONDARY_COORDINATE", "EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE",
    "The linear secondary axis coordinate value for a defined spatial"
    " reference frame.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE,
    "SPATIAL_LINEAR_TERTIARY_COORDINATE", "EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE",
    "The linear tertiary axis coordinate value for a defined spatial"
    " reference frame.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[32]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPECIFIC_GRAVITY,
    "SPECIFIC_GRAVITY", "EAC_SPECIFIC_GRAVITY",
    "The ratio of the <<MATERIAL_DENSITY>> of a substance to that of"
    " <WATER> at 277,15 kelvin (4 degrees Celsius); the specific gravity.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"specific gravity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPECIFIC_HEAT,
    "SPECIFIC_HEAT", "EAC_SPECIFIC_HEAT",
    "The quantity of energy required to raise the <<TEMPERATURE>> of a unit"
    " <<MASS>> of a <MATERIAL> by one kelvin; the specific heat.",
    EDCS_AVT_REAL, EQC_SPECIFIC_HEAT_CAPACITY,
    2, &(EGBindingForEA[1288]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, S2210]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPECIFIC_HUMIDITY,
    "SPECIFIC_HUMIDITY", "EAC_SPECIFIC_HUMIDITY",
    "The ratio of the <<MASS>> of water vapour to the total <<MASS>> of a"
    " <<VOLUME>> of moist <AIR>; the specific humidity.",
    EDCS_AVT_REAL, EQC_MASS_FRACTION,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"specific humidity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPEED,
    "SPEED", "EAC_SPEED",
    "A measure of the rate of motion of an <OBJECT>; speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPERM_WHALE_CATCH_PER_YEAR,
    "SPERM_WHALE_CATCH_PER_YEAR", "EAC_SPERM_WHALE_CATCH_PER_YEAR",
    "The number of sperm <WHALE>s caught within a one-year"
    " <<TIME_QUANTITY>>.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[569]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Wind and Residual Noise Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPILLING_BREAKER_FRACTION,
    "SPILLING_BREAKER_FRACTION", "EAC_SPILLING_BREAKER_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of breaking <WATER_WAVE>s that are spilling. Spilling is a"
    " breaking process wherein the <WATER_WAVE> peaks up until it is very"
    " steep but not vertical; only the top most portion of the <WATER_WAVE>"
    " curls over and descends on the forward slope of the advancing"
    " <WATER_WAVE> where it then slides down into the trough. This process"
    " starts at scattered foci which coalesce until the <WATER_WAVE>"
    " becomes an advancing <LINE> of foam.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1327]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPORT_TYPE,
    "SPORT_TYPE", "EAC_SPORT_TYPE",
    "The type of sport or exercise performed on an <ATHLETIC_FIELD> or"
    " <SPORTS_ARENA>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1329]), 6, &(EDCS_Enumerant_Dictionary[6631]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPOT_ELEVATION_TYPE,
    "SPOT_ELEVATION_TYPE", "EAC_SPOT_ELEVATION_TYPE",
    "The type of a <<TERRAIN_ELEVATION>> measurement at a <LOCATION>; the"
    " spot elevation type.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[35]), 3, &(EDCS_Enumerant_Dictionary[6637]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SPE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SPRING_TYPE,
    "SPRING_TYPE", "EAC_SPRING_TYPE",
    "The type of a <SPRING>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[22]), 5, &(EDCS_Enumerant_Dictionary[6640]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SWT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STAIR_CONSTRUCTION_TYPE,
    "STAIR_CONSTRUCTION_TYPE", "EAC_STAIR_CONSTRUCTION_TYPE",
    "The type of <MATERIAL> and/or techniques used to construct a <STAIR>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 5, &(EDCS_Enumerant_Dictionary[6645]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STAIR_STYLE,
    "STAIR_STYLE", "EAC_STAIR_STYLE",
    "The architectural style of a <STAIR>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 7, &(EDCS_Enumerant_Dictionary[6650]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STANTON_NUMBER,
    "STANTON_NUMBER", "EAC_STANTON_NUMBER",
    "A scalar governing the aerodynamic heat transfer coefficient of an"
    " <OBJECT>; the Stanton number.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, S2690]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_ALPHA_FLUX,
    "STELLAR_ALPHA_FLUX", "EAC_STELLAR_ALPHA_FLUX",
    "The stellar flux of alpha <PARTICLE>s.",
    EDCS_AVT_REAL, EQC_PARTICLE_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_ELECTRON_FLUX,
    "STELLAR_ELECTRON_FLUX", "EAC_STELLAR_ELECTRON_FLUX",
    "The stellar flux of electrons.",
    EDCS_AVT_REAL, EQC_PARTICLE_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_EM_FLUX,
    "STELLAR_EM_FLUX", "EAC_STELLAR_EM_FLUX",
    "The stellar electromagnetic flux level.",
    EDCS_AVT_REAL, EQC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_PROTON_FLUX,
    "STELLAR_PROTON_FLUX", "EAC_STELLAR_PROTON_FLUX",
    "The stellar flux of protons.",
    EDCS_AVT_REAL, EQC_PARTICLE_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_FLUX_10r7,
    "STELLAR_RF_FLUX_10r7", "EAC_STELLAR_RF_FLUX_10r7",
    "The intensity of <STELLAR_FLUX_RADIO_FREQUENCY_EMISSION> at 10,7"
    " centimetre <<WAVELENGTH>> (2,8 gigahertz).",
    EDCS_AVT_REAL, EQC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"F-TEN-FORECAST-RECORD solar radio flux rate\"]",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_MAXIMUM_TIME,
    "STELLAR_RF_NB_MAXIMUM_TIME", "EAC_STELLAR_RF_NB_MAXIMUM_TIME",
    "The time of the maximum electromagnetic flux of a"
    " <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise event relative to the"
    " beginning of the day (midnight).",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[951]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_MAXIMUM_TIME_QUALITY,
    "STELLAR_RF_NB_MAXIMUM_TIME_QUALITY", "EAC_STELLAR_RF_NB_MAXIMUM_TIME_QUALITY",
    "The quality of a <<STELLAR_RF_NB_MAXIMUM_TIME>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[951]), 3, &(EDCS_Enumerant_Dictionary[6657]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_MEAN_FLUX,
    "STELLAR_RF_NB_MEAN_FLUX", "EAC_STELLAR_RF_NB_MEAN_FLUX",
    "The mean electromagnetic flux of a"
    " <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise event.",
    EDCS_AVT_REAL, EQC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_MEAN_FLUX_QUALITY,
    "STELLAR_RF_NB_MEAN_FLUX_QUALITY", "EAC_STELLAR_RF_NB_MEAN_FLUX_QUALITY",
    "The quality of a <<STELLAR_RF_NB_MEAN_FLUX>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[943]), 3, &(EDCS_Enumerant_Dictionary[6660]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_PEAK_FLUX,
    "STELLAR_RF_NB_PEAK_FLUX", "EAC_STELLAR_RF_NB_PEAK_FLUX",
    "The peak electromagnetic flux of a"
    " <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise event.",
    EDCS_AVT_REAL, EQC_FLUX_DENSITY,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_PEAK_FLUX_QUALITY,
    "STELLAR_RF_NB_PEAK_FLUX_QUALITY", "EAC_STELLAR_RF_NB_PEAK_FLUX_QUALITY",
    "The quality of a <<STELLAR_RF_NB_PEAK_FLUX>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[943]), 3, &(EDCS_Enumerant_Dictionary[6663]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_PERIOD,
    "STELLAR_RF_NB_PERIOD", "EAC_STELLAR_RF_NB_PERIOD",
    "The <<TIME_QUANTITY>> of a <STELLAR_BURST_RADIO_FREQUENCY_EMISSION>"
    " noise event.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[951]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_PERIOD_QUALITY,
    "STELLAR_RF_NB_PERIOD_QUALITY", "EAC_STELLAR_RF_NB_PERIOD_QUALITY",
    "The quality of a <<STELLAR_RF_NB_PERIOD>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[951]), 3, &(EDCS_Enumerant_Dictionary[6666]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_REMARKS,
    "STELLAR_RF_NB_REMARKS", "EAC_STELLAR_RF_NB_REMARKS",
    "A descriptive or explanatory comment (remarks) regarding a"
    " <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise event.",
    EDCS_AVT_STRING, 0,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_START,
    "STELLAR_RF_NB_START", "EAC_STELLAR_RF_NB_START",
    "The starting time of a <STELLAR_BURST_RADIO_FREQUENCY_EMISSION> noise"
    " event relative to the beginning of the day (midnight).",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[951]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_RF_NB_START_QUALITY,
    "STELLAR_RF_NB_START_QUALITY", "EAC_STELLAR_RF_NB_START_QUALITY",
    "The quality of a <<STELLAR_RF_NB_START>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[951]), 3, &(EDCS_Enumerant_Dictionary[6669]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_WIND_ION_TEMPERATURE,
    "STELLAR_WIND_ION_TEMPERATURE", "EAC_STELLAR_WIND_ION_TEMPERATURE",
    "The <<TEMPERATURE>> of ionized <PARTICLE>s in a <STELLAR_WIND>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[948]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_WIND_PROTON_DENSITY,
    "STELLAR_WIND_PROTON_DENSITY", "EAC_STELLAR_WIND_PROTON_DENSITY",
    "The density of protons in a <STELLAR_WIND>.",
    EDCS_AVT_REAL, EQC_VOLUMETRIC_ENTITY_DENSITY,
    3, &(EGBindingForEA[926]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_WIND_SPEED,
    "STELLAR_WIND_SPEED", "EAC_STELLAR_WIND_SPEED",
    "The <<SPEED>> of a <STELLAR_WIND>.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[926]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_WIND_SPEED_GSE_X,
    "STELLAR_WIND_SPEED_GSE_X", "EAC_STELLAR_WIND_SPEED_GSE_X",
    "The <<STELLAR_WIND_SPEED>> in the <DIRECTION> of the <SUN> (in the"
    " ecliptic plane) and positive towards the <SUN>; the stellar wind"
    " speed GSE X.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[926]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_WIND_SPEED_GSE_Y,
    "STELLAR_WIND_SPEED_GSE_Y", "EAC_STELLAR_WIND_SPEED_GSE_Y",
    "The <<STELLAR_WIND_SPEED>> in the ecliptic plane in a <DIRECTION>"
    " perpendicular to the <DIRECTION> of the <SUN>, pointing generally"
    " opposite to the <DIRECTION> of revolution of the <EARTH> about the"
    " <SUN>, and positive in the contra-revolution <DIRECTION>; the stellar"
    " wind speed GSE Y.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[926]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_WIND_SPEED_GSE_Z,
    "STELLAR_WIND_SPEED_GSE_Z", "EAC_STELLAR_WIND_SPEED_GSE_Z",
    "The <<STELLAR_WIND_SPEED>> perpendicular to the ecliptic plane and"
    " positive towards the <STAR> Polaris; the stellar wind speed GSE Z.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[926]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_X_RAY_FLUX_L_BAND,
    "STELLAR_X_RAY_FLUX_L_BAND", "EAC_STELLAR_X_RAY_FLUX_L_BAND",
    "The intensity (flux) of stellar x-rays in the L-band (0,1 - 0,8"
    " nanometres <<WAVELENGTH>>).",
    EDCS_AVT_REAL, EQC_RADIANT_EXITANCE_RATE,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STELLAR_X_RAY_FLUX_S_BAND,
    "STELLAR_X_RAY_FLUX_S_BAND", "EAC_STELLAR_X_RAY_FLUX_S_BAND",
    "The intensity (flux) of stellar x-rays in the S-band (0,05 - 0,4"
    " nanometres <<WAVELENGTH>>).",
    EDCS_AVT_REAL, EQC_RADIANT_EXITANCE_RATE,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[GSTT], [SEC]", EDCS_CONCEPT_STAT_ISO },

    {EAC_STEM_DIAMETER,
    "STEM_DIAMETER", "EAC_STEM_DIAMETER",
    "The diameter of the stem/trunk of a <PLANT> measured at a"
    " <<HEIGHT_AGL>> of 1,4 metres.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[831]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STORAGE_FACILITY_TYPE,
    "STORAGE_FACILITY_TYPE", "EAC_STORAGE_FACILITY_TYPE",
    "The type of storage <FACILITY>s available at or in the near vicinity"
    " of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[201]), 20, &(EDCS_Enumerant_Dictionary[6672]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SFA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STRUCTURAL_PILE_TYPE,
    "STRUCTURAL_PILE_TYPE", "EAC_STRUCTURAL_PILE_TYPE",
    "The type of a <STRUCTURAL_PILE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[43]), 4, &(EDCS_Enumerant_Dictionary[6692]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PLC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STRUCTURE_DENSITY,
    "STRUCTURE_DENSITY", "EAC_STRUCTURE_DENSITY",
    "The areal density of <STRUCTURE>s.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    2, &(EGBindingForEA[1312]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DMS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STRUCTURE_LIGHTING_TYPE,
    "STRUCTURE_LIGHTING_TYPE", "EAC_STRUCTURE_LIGHTING_TYPE",
    "The type of <LIGHTING> on or in a <STRUCTURE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[132]), 3, &(EDCS_Enumerant_Dictionary[6696]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: FLT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STRUCTURE_PROTECTION_TYPE,
    "STRUCTURE_PROTECTION_TYPE", "EAC_STRUCTURE_PROTECTION_TYPE",
    "The type/degree to which a <STRUCTURE> provides protection to itself"
    " or its contents by resisting the effects of an explosion, a"
    " <MUNITION>, and a natural disaster (for example: a hurricane, a"
    " tornado, and/or an earthquake).",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1297]), 4, &(EDCS_Enumerant_Dictionary[6699]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_STRUCTURE_SHAPE,
    "STRUCTURE_SHAPE", "EAC_STRUCTURE_SHAPE",
    "The geometric form or configuration of an <OBJECT>; the structure"
    " shape.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 71, &(EDCS_Enumerant_Dictionary[6703]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUMMER_CANOPY_COVER_FRACTION,
    "SUMMER_CANOPY_COVER_FRACTION", "EAC_SUMMER_CANOPY_COVER_FRACTION",
    "A number between 0 and 1 inclusive representing linearly-scaled"
    " fractional canopy cover of <TREE>s during the summer within a"
    " delineated <REGION> of <LAND>. Zero means no cover and one means"
    " completely covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    5, &(EGBindingForEA[1213]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: STR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUNRISE_TIME,
    "SUNRISE_TIME", "EAC_SUNRISE_TIME",
    "The <<TIME_OF_DAY>> of sunrise. The time of sunrise is defined to"
    " occur when the geometric zenith distance of the centre of the <SUN>"
    " is 90,8333 arc degrees; that is, the centre of the <SUN> is"
    " geometrically 50 arc minutes below a horizontal plane for an observer"
    " at MSL with a level, unobstructed eastern horizon under average"
    " atmospheric conditions. The upper limb of the <SUN> will then appear"
    " to be tangent to the eastern horizon. The 50 arc minute geometric"
    " depression of the centre of the <SUN> used for the computations is"
    " obtained by adding the average apparent <<RADIUS>> of the <SUN> (16"
    " arc minutes) to the average amount of atmospheric refraction at the"
    " horizon (34 arc minutes).",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    4, &(EGBindingForEA[908]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SIED]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUNSET_TIME,
    "SUNSET_TIME", "EAC_SUNSET_TIME",
    "The <<TIME_OF_DAY>> of sunset. The time of sunset is defined to occur"
    " when the geometric zenith distance of the centre of the <SUN> is"
    " 90,8333 arc degrees; that is, the centre of the <SUN> is"
    " geometrically 50 arc minutes below a horizontal plane for an observer"
    " at MSL with a level, unobstructed western horizon under average"
    " atmospheric conditions. The upper limb of the <SUN> will then appear"
    " to be tangent to the western horizon. The 50 arc minute geometric"
    " depression of the centre of the <SUN> used for the computations is"
    " obtained by adding the average apparent <<RADIUS>> of the <SUN> (16"
    " arc minutes) to the average amount of atmospheric refraction at the"
    " horizon (34 arc minutes).",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    4, &(EGBindingForEA[908]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SIED]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUNSHINE_OBSERVATION_PERIOD,
    "SUNSHINE_OBSERVATION_PERIOD", "EAC_SUNSHINE_OBSERVATION_PERIOD",
    "The <<TIME_QUANTITY>> over which an observation of solar"
    " <<ILLUMINANCE>> was taken; the sunshine observation period.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[951]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SUNSHINE-OBSERVATION reporting period quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUNSHINE_PERIOD,
    "SUNSHINE_PERIOD", "EAC_SUNSHINE_PERIOD",
    "The <<TIME_QUANTITY>> that solar irradiation occurred; the sunshine"
    " period.",
    EDCS_AVT_REAL, EQC_TIME,
    3, &(EGBindingForEA[951]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SUNSHINE-OBSERVATION sunshine duration quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUNSPOT_NUMBER,
    "SUNSPOT_NUMBER", "EAC_SUNSPOT_NUMBER",
    "The number of <SUNSPOT>s observed; the sunspot number (SSN).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUNSPOT_NUMBER_INDEX,
    "SUNSPOT_NUMBER_INDEX", "EAC_SUNSPOT_NUMBER_INDEX",
    "The total number of <SUNSPOT>s plus ten times the number of <SUNSPOT>"
    " groups in a given <<TIME_QUANTITY>>(usually one month); the sunspot"
    " number index.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[943]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUPERELEVATION,
    "SUPERELEVATION", "EAC_SUPERELEVATION",
    "The lateral slope (rise/run) of a <LAND_TRANSPORTATION_ROUTE>; the"
    " superelevation.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUPERTANKER_DENSITY,
    "SUPERTANKER_DENSITY", "EAC_SUPERTANKER_DENSITY",
    "The areal density of supertanker <WATER_SURFACE_VESSEL>s. A"
    " supertanker <WATER_SURFACE_VESSEL> is characterized by a dead weight"
    " greater than 318 000 kilograms (approximately 350 000 tons) and a"
    " <<LENGTH>> greater than 325 metres).",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    6, &(EGBindingForEA[995]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Historical Temporal Shipping Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_ANGLE,
    "SURFACE_ANGLE", "EAC_SURFACE_ANGLE",
    "The maximum angle between the <SURFACE> of an <OBJECT> and a"
    " perpendicular to the local gravity vector. The value is selected to"
    " be between 0 and 90 arc degrees (or equivalent).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[550]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_BACKSCATTER,
    "SURFACE_BACKSCATTER", "EAC_SURFACE_BACKSCATTER",
    "The negative of the ratio of the flux returned (reflected directly"
    " back in the <DIRECTION> of incidence) to the incident flux in"
    " decibels of the <SURFACE> of an <OBJECT>; the surface backscatter.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    2, &(EGBindingForEA[1314]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, B0080, \"back-scattering\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_CATEGORY,
    "SURFACE_CATEGORY", "EAC_SURFACE_CATEGORY",
    "The category of the <SURFACE> of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[44]), 2, &(EDCS_Enumerant_Dictionary[6774]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_CHARACTERISTIC_TYPE,
    "SURFACE_CHARACTERISTIC_TYPE", "EAC_SURFACE_CHARACTERISTIC_TYPE",
    "The principal characteristic type of a <SURFACE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[44]), 30, &(EDCS_Enumerant_Dictionary[6776]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: PSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_EM_ABSORPTIVITY,
    "SURFACE_EM_ABSORPTIVITY", "EAC_SURFACE_EM_ABSORPTIVITY",
    "The ratio of absorbed to incident electromagnetic flux at a <SURFACE>;"
    " the surface electromagnetic absorptivity.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    3, &(EGBindingForEA[933]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_EM_ABSORPTIVITY_SOLAR,
    "SURFACE_EM_ABSORPTIVITY_SOLAR", "EAC_SURFACE_EM_ABSORPTIVITY_SOLAR",
    "The <<SURFACE_EM_ABSORPTIVITY>> of all appreciable solar flux (from"
    " about 0,0 to 3,0 micrometres in <<WAVELENGTH>>); if expressed in"
    " decibels, the negative of the value is used; the surface solar"
    " electromagnetic absorptivity.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    3, &(EGBindingForEA[933]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_EM_DUCT_HEIGHT,
    "SURFACE_EM_DUCT_HEIGHT", "EAC_SURFACE_EM_DUCT_HEIGHT",
    "The <<HEIGHT_AGL>> of the top of a <SURFACE_BASED_EM_DUCT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[915]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BATT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_EM_DUCT_STRENGTH,
    "SURFACE_EM_DUCT_STRENGTH", "EAC_SURFACE_EM_DUCT_STRENGTH",
    "The strength of a <SURFACE_BASED_EM_DUCT> as defined by the difference"
    " between the maximum and minimum <<RF_REFRACTIVE_INDEX_MODIFIED>> of a"
    " trapping layer.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[16]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HITN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_MATERIAL_TYPE,
    "SURFACE_MATERIAL_TYPE", "EAC_SURFACE_MATERIAL_TYPE",
    "The composition of the <MATERIAL> of the <SURFACE> of an <OBJECT>"
    " excluding internal structural <MATERIAL>s.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1276]), 155, &(EDCS_Enumerant_Dictionary[6806]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SMC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_REFLECTIVITY,
    "SURFACE_REFLECTIVITY", "EAC_SURFACE_REFLECTIVITY",
    "A number between 0 and 1 inclusive representing the ratio of the"
    " reflected flux to the incident flux at a <SURFACE>; the surface"
    " reflectivity. Zero means no reflection and one means total reflection.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1314]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_SLIPPERY,
    "SURFACE_SLIPPERY", "EAC_SURFACE_SLIPPERY",
    "An indication that a <SURFACE> (for example: wet grass and/or wet clay"
    " <SOIL>) is slippery.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[44]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_SLOPE,
    "SURFACE_SLOPE", "EAC_SURFACE_SLOPE",
    "The maximum slope (rise/run) of the <SURFACE> of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1314]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SGC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_SLOPE_ORIENTATION,
    "SURFACE_SLOPE_ORIENTATION", "EAC_SURFACE_SLOPE_ORIENTATION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> of maximum"
    " <<SURFACE_SLOPE>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[550]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SGO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_TEMPERATURE,
    "SURFACE_TEMPERATURE", "EAC_SURFACE_TEMPERATURE",
    "The <<TEMPERATURE>> of a <SURFACE>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1339]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_THERMAL_INDEX,
    "SURFACE_THERMAL_INDEX", "EAC_SURFACE_THERMAL_INDEX",
    "The index used to describe the thermal (radiance) characteristic of a"
    " <SURFACE>.",
    EDCS_AVT_INDEX, 0,
    3, &(EGBindingForEA[489]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_THERMAL_MODEL,
    "SURFACE_THERMAL_MODEL", "EAC_SURFACE_THERMAL_MODEL",
    "The type of thermal (radiance) model being used to determine the"
    " interpretation of the thermal index describing the thermal (radiance)"
    " characteristic of a <SURFACE>. That value is used to index one or"
    " more thermal model-specific lookup tables in order to predict,"
    " display, or analyze thermal signatures.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[489]), 4, &(EDCS_Enumerant_Dictionary[6961]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_THERMAL_SUNSHADING_DOMINANCE,
    "SURFACE_THERMAL_SUNSHADING_DOMINANCE", "EAC_SURFACE_THERMAL_SUNSHADING_DOMINANCE",
    "The degree of dominance of the effect of shading from the <SUN> (in"
    " the respective sensor domain) over the thermally derived values. The"
    " values are between 0 and 1 inclusive with zero being minimally and"
    " one being maximally (but not necessarily completely) dominant. The"
    " exact interpretation of this value is determined by the thermal model"
    " being used.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1314]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_THERMAL_VISUAL_DOMINANCE,
    "SURFACE_THERMAL_VISUAL_DOMINANCE", "EAC_SURFACE_THERMAL_VISUAL_DOMINANCE",
    "The degree of dominance of the visual texture of an image (in the"
    " respective sensor domain) over the thermally derived values. The"
    " values are between 0 and 1 inclusive with zero being minimally and"
    " one being maximally (but not necessarily completely) dominant. The"
    " exact interpretation of this value is determined by the thermal model"
    " being used.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1314]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFACE_WIND_SPEED,
    "SURFACE_WIND_SPEED", "EAC_SURFACE_WIND_SPEED",
    "The <<WIND_SPEED>> 10 metres above a <PLANETARY_SURFACE>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, S3850]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURFICIAL_DEPTH,
    "SURFICIAL_DEPTH", "EAC_SURFICIAL_DEPTH",
    "The estimated general depth of <SOIL> or unconsolidated surficial"
    " <MATERIAL>s on the <TERRAIN>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[839]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SM1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURGING_BREAKER_FRACTION,
    "SURGING_BREAKER_FRACTION", "EAC_SURGING_BREAKER_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of breaking <WATER_WAVE>s that are surging. Surging means"
    " that the <WATER_WAVE> crest tends to advance faster than the base of"
    " the <WATER_WAVE> to suggest the formation of a plunging breaker,"
    " however, the <WATER_WAVE> base then advances faster than the crest,"
    " the plunging is arrested, and the breaker surges up the <BEACH> as a"
    " wall of <WATER> which may, or may not, be white water. Zero means no"
    " breaking <WATER_WAVE>s are surging and one means all are surging.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1327]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURVEILLANCE_WINGED_AIRCRAFT_TYPE,
    "SURVEILLANCE_WINGED_AIRCRAFT_TYPE", "EAC_SURVEILLANCE_WINGED_AIRCRAFT_TYPE",
    "The type of a winged surveillance <AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[424]), 4, &(EDCS_Enumerant_Dictionary[6965]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURVEY_CONTROL_POINT_TYPE,
    "SURVEY_CONTROL_POINT_TYPE", "EAC_SURVEY_CONTROL_POINT_TYPE",
    "The type of a control point established by surveying methods.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[46]), 14, &(EDCS_Enumerant_Dictionary[6969]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CPA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURVEY_END_DATE,
    "SURVEY_END_DATE", "EAC_SURVEY_END_DATE",
    "The end date of a survey. The value is formatted as specified by"
    " <<DATE_FORMAT>> or by <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[1341]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SUE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURVEY_QUALIFIER,
    "SURVEY_QUALIFIER", "EAC_SURVEY_QUALIFIER",
    "The qualifier of a survey for an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[190]), 3, &(EDCS_Enumerant_Dictionary[6983]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: SUR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SURVEY_START_DATE,
    "SURVEY_START_DATE", "EAC_SURVEY_START_DATE",
    "The start date of a survey. The value is formatted as specified by"
    " <<DATE_FORMAT>> or by <<DATE_TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[1341]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SUS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SUSPENDED_CEILING_DEPTH,
    "SUSPENDED_CEILING_DEPTH", "EAC_SUSPENDED_CEILING_DEPTH",
    "The <<DEPTH>> of a <ROOM_CEILING> suspended from the <SURFACE> above;"
    " the suspended ceiling depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[707]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SYNCHRONIZED,
    "SYNCHRONIZED", "EAC_SYNCHRONIZED",
    "An indication that an <OBJECT> is synchronized.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: SYC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_SYSTEM_RELAXATION_TIME,
    "SYSTEM_RELAXATION_TIME", "EAC_SYSTEM_RELAXATION_TIME",
    "The <<TIME_QUANTITY>> required for a <SYSTEM> exposed to some"
    " discontinuous change in environment to return to the state it would"
    " exhibit after an indefinitely long time; the system relaxation time.",
    EDCS_AVT_REAL, EQC_TIME,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SP35, \"relaxation time\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TANKER_DENSITY,
    "TANKER_DENSITY", "EAC_TANKER_DENSITY",
    "The areal density of tanker <WATER_SURFACE_VESSEL>s. A tanker"
    " <WATER_SURFACE_VESSEL> is characterized by a gross weight greater"
    " than 907 000 kilograms (approximately 1 000 tons), a dead weight less"
    " than or equal to 159 000 kilograms (approximately 175 000 tons), and"
    " a <<LENGTH>> of approximately 18 to 300 metres).",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    6, &(EGBindingForEA[995]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Historical Temporal Shipping Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TAXIWAY_LIGHTING_INTENSITY,
    "TAXIWAY_LIGHTING_INTENSITY", "EAC_TAXIWAY_LIGHTING_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the <LIGHTING> on a <TAXIWAY>. Zero means"
    " unlit and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[398]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TELESCOPE_TYPE,
    "TELESCOPE_TYPE", "EAC_TELESCOPE_TYPE",
    "The type of a <TELESCOPE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[14]), 3, &(EDCS_Enumerant_Dictionary[6986]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TEL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TEMPERATURE,
    "TEMPERATURE", "EAC_TEMPERATURE",
    "The state of a <MATERIAL> or <OBJECT> with regard to objective warmth"
    " or coldness, referred to a standard of comparison; temperature [SOED,"
    " \"temperature\", 7.a].",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    1, &(EGBindingForEA[47]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TEMPERATURE_CONTRAST,
    "TEMPERATURE_CONTRAST", "EAC_TEMPERATURE_CONTRAST",
    "The thermal contrast of an <OBJECT> expressed as the difference"
    " between the <<TEMPERATURE>> of the <OBJECT> and the <<TEMPERATURE>>"
    " of the apparent background.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[192]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TEMPERATURE_INVRSN_LAYER_BASE,
    "TEMPERATURE_INVRSN_LAYER_BASE", "EAC_TEMPERATURE_INVRSN_LAYER_BASE",
    "The vertical distance to the base of a <TEMPERATURE_INVERSION_LAYER>"
    " from a reference <SURFACE> identified by an"
    " <<ATM_VERTICAL_REFERENCE>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[662]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TEMPERATURE_INVRSN_LAYER_LAPSE_RATE,
    "TEMPERATURE_INVRSN_LAYER_LAPSE_RATE", "EAC_TEMPERATURE_INVRSN_LAYER_LAPSE_RATE",
    "The <<TEMPERATURE_LAPSE_RATE>> in a <TEMPERATURE_INVERSION_LAYER>.",
    EDCS_AVT_REAL, EQC_LINEIC_THERMO_TEMP_GRADIENT,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"temperature lapse rate\"]",
    "[WMO182, \"temperature inversion\"]", EDCS_CONCEPT_STAT_ISO },

    {EAC_TEMPERATURE_INVRSN_LAYER_TOP,
    "TEMPERATURE_INVRSN_LAYER_TOP", "EAC_TEMPERATURE_INVRSN_LAYER_TOP",
    "The vertical distance to the top of a <TEMPERATURE_INVERSION_LAYER>"
    " from a reference <SURFACE> identified by an"
    " <<ATM_VERTICAL_REFERENCE>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[662]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TEMPERATURE_LAPSE_RATE,
    "TEMPERATURE_LAPSE_RATE", "EAC_TEMPERATURE_LAPSE_RATE",
    "The rate of decrease of the <<AIR_TEMPERATURE>> as a function of"
    " <<HEIGHT_AGL>>. A decrease in <<AIR_TEMPERATURE>> with <<HEIGHT_AGL>>"
    " is reported as a positive number.",
    EDCS_AVT_REAL, EQC_LINEIC_THERMO_TEMP_GRADIENT,
    3, &(EGBindingForEA[684]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TENT_DEPLOYMENT_FRACTION,
    "TENT_DEPLOYMENT_FRACTION", "EAC_TENT_DEPLOYMENT_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional opening of the deployable or extension <TENT> of an"
    " <OBJECT>. Zero means fully stowed/retracted/closed and one means"
    " fully deployed.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bit: 24 (Tent)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_ALBEDO,
    "TERRAIN_ALBEDO", "EAC_TERRAIN_ALBEDO",
    "The <<ALBEDO>> of <TERRAIN>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[924]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SOIL-ANALYSIS-FORECAST surface albedo rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_CHANNEL_WIDTH,
    "TERRAIN_CHANNEL_WIDTH", "EAC_TERRAIN_CHANNEL_WIDTH",
    "The predominant distance across the bottom of a localized"
    " <TERRAIN_CHANNEL> measured perpendicular to its <CENTRE_LINE>; the"
    " terrain channel width.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[845]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_CREST_WIDTH,
    "TERRAIN_CREST_WIDTH", "EAC_TERRAIN_CREST_WIDTH",
    "The predominant distance across the crest of a localized <RIDGE> (for"
    " example: a <DAM> and/or a <PARAPET>) on the <TERRAIN>, as measured"
    " perpendicular to its <CENTRE_LINE>; terrain crest width.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[845]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WOC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_ELEVATION,
    "TERRAIN_ELEVATION", "EAC_TERRAIN_ELEVATION",
    "The <<ELEVATION>> of the <TERRAIN> at a <LOCATION>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1241]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_GAP_WIDTH,
    "TERRAIN_GAP_WIDTH", "EAC_TERRAIN_GAP_WIDTH",
    "The minimum horizontal bridging distance between the banks of a"
    " localized <TERRAIN_CHANNEL> measured perpendicular to its"
    " <CENTRE_LINE>; the terrain gap width.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[845]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WD3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_MORPHOLOGY_DESCRIPTION,
    "TERRAIN_MORPHOLOGY_DESCRIPTION", "EAC_TERRAIN_MORPHOLOGY_DESCRIPTION",
    "A description of the morphology of the <TERRAIN>.",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[35]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TSR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_MORPHOLOGY_TYPE,
    "TERRAIN_MORPHOLOGY_TYPE", "EAC_TERRAIN_MORPHOLOGY_TYPE",
    "The type of the morphology of the <TERRAIN>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[35]), 66, &(EDCS_Enumerant_Dictionary[6989]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SRD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_OBSTACLE_TYPE,
    "TERRAIN_OBSTACLE_TYPE", "EAC_TERRAIN_OBSTACLE_TYPE",
    "The type of a <TERRAIN_OBSTACLE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 30, &(EDCS_Enumerant_Dictionary[7055]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_ROUGHNESS_ROOT_MEAN_SQUARE,
    "TERRAIN_ROUGHNESS_ROOT_MEAN_SQUARE", "EAC_TERRAIN_ROUGHNESS_ROOT_MEAN_SQUARE",
    "The roughness of the <TERRAIN> calculated using the RMS value of"
    " <<TERRAIN_ELEVATION>>s measured at a spatial frequency of"
    " approximately 0,3 metres after removing the trend surface.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[845]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GL892]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_SLOPE,
    "TERRAIN_SLOPE", "EAC_TERRAIN_SLOPE",
    "The slope (rise/run) of the <TERRAIN>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1304]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GSC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_SURFACE_MARKING_TYPE,
    "TERRAIN_SURFACE_MARKING_TYPE", "EAC_TERRAIN_SURFACE_MARKING_TYPE",
    "The type of marking (for example: a rut, charring by fire, and/or"
    " ploughing) that indicates disturbance to the naturally occurring"
    " <SURFACE> of the <LAND>; the terrain surface marking type.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[35]), 9, &(EDCS_Enumerant_Dictionary[7085]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_TRAFFICABILITY_COARSE,
    "TERRAIN_TRAFFICABILITY_COARSE", "EAC_TERRAIN_TRAFFICABILITY_COARSE",
    "A coarse measure of the trafficability of the <TERRAIN> as it affects"
    " the movement of ground forces (for example: a military unit, a"
    " military <GROUND_VEHICLE>, and/or infantry).",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1153]), 12, &(EDCS_Enumerant_Dictionary[7094]),
    EDCS_REF_TYP_INFORMATIVE, "[TTMS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_TRAFFICABILITY_FINE,
    "TERRAIN_TRAFFICABILITY_FINE", "EAC_TERRAIN_TRAFFICABILITY_FINE",
    "A fine measure of the trafficability of the <TERRAIN> as it affects"
    " the movement of ground forces (for example: a military unit, a"
    " military <GROUND_VEHICLE>, and/or infantry).",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1153]), 814, &(EDCS_Enumerant_Dictionary[7106]),
    EDCS_REF_TYP_INFORMATIVE, "[TTMS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERRAIN_TRAFFICABILITY_MEDIUM,
    "TERRAIN_TRAFFICABILITY_MEDIUM", "EAC_TERRAIN_TRAFFICABILITY_MEDIUM",
    "A medium measure of the trafficability of the <TERRAIN> as it affects"
    " the movement of ground forces (for example: a military unit, a"
    " military <GROUND_VEHICLE>, and/or infantry).",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1153]), 31, &(EDCS_Enumerant_Dictionary[7920]),
    EDCS_REF_TYP_INFORMATIVE, "[TTMS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TERTIARY_AXIS_VELOCITY_COMPONENT,
    "TERTIARY_AXIS_VELOCITY_COMPONENT", "EAC_TERTIARY_AXIS_VELOCITY_COMPONENT",
    "The <<VELOCITY>> component of an <OBJECT> along the tertiary axis of a"
    " defined spatial reference frame.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TEXTUAL_OBJECT_IDENTIFIER,
    "TEXTUAL_OBJECT_IDENTIFIER", "EAC_TEXTUAL_OBJECT_IDENTIFIER",
    "The textual identifier (often termed the \"number\") of an <OBJECT>.",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BEN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_THERMAL_CONDUCTIVITY,
    "THERMAL_CONDUCTIVITY", "EAC_THERMAL_CONDUCTIVITY",
    "The proportionality factor between energy flux and the gradient of"
    " <<TEMPERATURE>>; thermal conductivity.",
    EDCS_AVT_REAL, EQC_THERMAL_CONDUCTIVITY,
    3, &(EGBindingForEA[1261]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"thermal conductivity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_THERMAL_PENETRATION_DEPTH,
    "THERMAL_PENETRATION_DEPTH", "EAC_THERMAL_PENETRATION_DEPTH",
    "The thermal penetration (effective depth) of variation in"
    " <<TEMPERATURE>> within a <MATERIAL>over a diurnal cycle.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[122]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[POC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_THERMOCLINE_TEMP_GRADIENT,
    "THERMOCLINE_TEMP_GRADIENT", "EAC_THERMOCLINE_TEMP_GRADIENT",
    "The gradient of <<TEMPERATURE>> within a thermocline. A thermocline is"
    " that <REGION> in a thermally stratified <WATERBODY> in which the"
    " <<WATERBODY_TEMPERATURE>> decrease with <<DEPTH>> is greater than"
    " that of the <WATER> above and below it.",
    EDCS_AVT_REAL, EQC_LINEIC_THERMO_TEMP_GRADIENT,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_THERMOCLINE_TEMP_GRADIENT_STD_DEV,
    "THERMOCLINE_TEMP_GRADIENT_STD_DEV", "EAC_THERMOCLINE_TEMP_GRADIENT_STD_DEV",
    "The standard deviation of <<THERMOCLINE_TEMP_GRADIENT>> measurements.",
    EDCS_AVT_REAL, EQC_LINEIC_THERMO_TEMP_GRADIENT,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_THICKNESS,
    "THICKNESS", "EAC_THICKNESS",
    "The distance between two opposite <SURFACE>s of an <OBJECT>, usually"
    " the distance of smallest measure; the thickness.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_THUNDERSTORM_INTENSITY,
    "THUNDERSTORM_INTENSITY", "EAC_THUNDERSTORM_INTENSITY",
    "The intensity of a <THUNDERSTORM> as determined by its"
    " <<PRECIPITATION_RATE>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 3, &(EDCS_Enumerant_Dictionary[7951]),
    EDCS_REF_TYP_INFORMATIVE, "[FMH1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_THUNDERSTORM_MAXIMUM_WIND_SPEED,
    "THUNDERSTORM_MAXIMUM_WIND_SPEED", "EAC_THUNDERSTORM_MAXIMUM_WIND_SPEED",
    "The maximum <<WIND_SPEED>> measured within a <THUNDERSTORM>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_THUNDERSTORM_PRESENT,
    "THUNDERSTORM_PRESENT", "EAC_THUNDERSTORM_PRESENT",
    "An indication that a <THUNDERSTORM> is present.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_THUNDERSTORM_PROBABILITY,
    "THUNDERSTORM_PROBABILITY", "EAC_THUNDERSTORM_PROBABILITY",
    "The probability of the occurrence of a <THUNDERSTORM>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_THUNDERSTORM_TOP_ALTITUDE,
    "THUNDERSTORM_TOP_ALTITUDE", "EAC_THUNDERSTORM_TOP_ALTITUDE",
    "The <<ALTITUDE_MSL>> of the top of a <THUNDERSTORM>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[660]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIDAL_DATUM,
    "TIDAL_DATUM", "EAC_TIDAL_DATUM",
    "A level of a <WATERBODY> defined by some phase of the <TIDE>, from"
    " which water <<DEPTH>>s and <<TIDE_LEVEL>>s are reckoned; the tidal"
    " datum.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1207]), 15, &(EDCS_Enumerant_Dictionary[7954]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S32, \"datum: tidal\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIDE_INFLUENCED,
    "TIDE_INFLUENCED", "EAC_TIDE_INFLUENCED",
    "An indication that an <OBJECT> is affected by the <TIDE>.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[203]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TID]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIDE_LEVEL,
    "TIDE_LEVEL", "EAC_TIDE_LEVEL",
    "The <<HEIGHT>> above a <<TIDAL_DATUM>> of a <WATERBODY_SURFACE>"
    " influenced by the <TIDE>; the tide level.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1251]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JSM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIME_COORDINATE,
    "TIME_COORDINATE", "EAC_TIME_COORDINATE",
    "The coordinate value for a defined temporal reference frame; the time"
    " coordinate.",
    EDCS_AVT_REAL, EQC_TIME,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIME_DIVISION_WITHIN_DAY,
    "TIME_DIVISION_WITHIN_DAY", "EAC_TIME_DIVISION_WITHIN_DAY",
    "The division of the day (one of several) marked by the passage of the"
    " <SUN> through its diurnal cycle; the time division within the day.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 5, &(EDCS_Enumerant_Dictionary[7969]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIME_FORMAT,
    "TIME_FORMAT", "EAC_TIME_FORMAT",
    "The format of a time of the day.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 22, &(EDCS_Enumerant_Dictionary[7974]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIME_OF_DAY,
    "TIME_OF_DAY", "EAC_TIME_OF_DAY",
    "A time of the day formatted as a <<TIME_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIME_PERIOD,
    "TIME_PERIOD", "EAC_TIME_PERIOD",
    "A period of time; formatted as specified by <<TIME_PERIOD_FORMAT>>.",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIME_PERIOD_FORMAT,
    "TIME_PERIOD_FORMAT", "EAC_TIME_PERIOD_FORMAT",
    "The format of a period of time.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[48]), 6, &(EDCS_Enumerant_Dictionary[7996]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TIME_QUANTITY,
    "TIME_QUANTITY", "EAC_TIME_QUANTITY",
    "A quantity of time (period).",
    EDCS_AVT_REAL, EQC_TIME,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TIM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOP_LAYER_SOIL_TEMPERATURE,
    "TOP_LAYER_SOIL_TEMPERATURE", "EAC_TOP_LAYER_SOIL_TEMPERATURE",
    "The <<TEMPERATURE>> of the <SOIL> between zero and five centimetres"
    " below the <SURFACE> of the <TERRAIN>; the top layer soil temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1306]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WEDER]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOP_WIDTH,
    "TOP_WIDTH", "EAC_TOP_WIDTH",
    "The <<WIDTH>> of an <OBJECT> at its top.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WD5]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOPMARK_SHAPE,
    "TOPMARK_SHAPE", "EAC_TOPMARK_SHAPE",
    "The shape of a <TOPMARK>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 16, &(EDCS_Enumerant_Dictionary[8002]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOPMARK_TYPE,
    "TOPMARK_TYPE", "EAC_TOPMARK_TYPE",
    "The type of a <TOPMARK>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1037]), 51, &(EDCS_Enumerant_Dictionary[8018]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TMC and TOP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOTAL_CLOUD_COVER_CATEGORY,
    "TOTAL_CLOUD_COVER_CATEGORY", "EAC_TOTAL_CLOUD_COVER_CATEGORY",
    "A category describing the <<TOTAL_CLOUD_COVERAGE>>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 15, &(EDCS_Enumerant_Dictionary[8069]),
    EDCS_REF_TYP_INFORMATIVE, "[WMO8, \"total cloud cover\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOTAL_CLOUD_COVERAGE,
    "TOTAL_CLOUD_COVERAGE", "EAC_TOTAL_CLOUD_COVERAGE",
    "The fraction of the sky hidden by all <CLOUD>s.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"total cloud cover\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOTAL_ELECTRON_CONTENT,
    "TOTAL_ELECTRON_CONTENT", "EAC_TOTAL_ELECTRON_CONTENT",
    "The maximum equivalent quantity of free electrons vertically above a"
    " <LOCATION>; the total electron count.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TASC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOTAL_SNOW_ICE_DEPTH,
    "TOTAL_SNOW_ICE_DEPTH", "EAC_TOTAL_SNOW_ICE_DEPTH",
    "The total depth of <SNOW_GROUND_COVER> and/or <ICE> on the <TERRAIN>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    5, &(EGBindingForEA[596]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO306]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOTAL_SNOW_ICE_DEPTH_EQUIVALENT,
    "TOTAL_SNOW_ICE_DEPTH_EQUIVALENT", "EAC_TOTAL_SNOW_ICE_DEPTH_EQUIVALENT",
    "The depth of the liquid <WATER> that is equivalent in content to the"
    " <<TOTAL_SNOW_ICE_DEPTH>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    5, &(EGBindingForEA[596]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOURISTIC_NAME,
    "TOURISTIC_NAME", "EAC_TOURISTIC_NAME",
    "A touristic name for an <OBJECT> that exists in addition to a"
    " geographic name.",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: NA2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOWED_VEHICLE_TYPE,
    "TOWED_VEHICLE_TYPE", "EAC_TOWED_VEHICLE_TYPE",
    "The type of a <TOWED_VEHICLE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1357]), 8, &(EDCS_Enumerant_Dictionary[8084]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TOWER_TYPE,
    "TOWER_TYPE", "EAC_TOWER_TYPE",
    "The purpose of a <TOWER>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[43]), 24, &(EDCS_Enumerant_Dictionary[8092]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TTC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSMISSION_ATTENUATION_GRADIENT,
    "TRANSMISSION_ATTENUATION_GRADIENT", "EAC_TRANSMISSION_ATTENUATION_GRADIENT",
    "The negative of the propagation range gradient of the ratio of"
    " transmitted to incident flux, generally expressed as a decibel power"
    " ratio per length of range of an <OBJECT>; the transmission"
    " attenuation gradient.",
    EDCS_AVT_REAL, EQC_POWER_LEVEL_DIFF_LEN_GRADIENT,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSMISSION_LOSS,
    "TRANSMISSION_LOSS", "EAC_TRANSMISSION_LOSS",
    "The negative of the ratio of energy density at an end <LOCATION> to"
    " that at a starting <LOCATION>, generally expressed in decibels; the"
    " transmission loss.",
    EDCS_AVT_REAL, EQC_FIELD_OR_POWER_LEVEL_DIFF,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSMISSIVITY,
    "TRANSMISSIVITY", "EAC_TRANSMISSIVITY",
    "The ratio of transmitted to incident flux from one traversal through a"
    " homogeneous <MATERIAL> or <OBJECT>; the transmissivity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[171]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"transmissivity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSMITTED_AZIMUTH_GEODETIC,
    "TRANSMITTED_AZIMUTH_GEODETIC", "EAC_TRANSMITTED_AZIMUTH_GEODETIC",
    "The <<VECTOR_AZIMUTH_GEODETIC>> toward which light is transmitted (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSMITTED_AZIMUTH_LOCAL,
    "TRANSMITTED_AZIMUTH_LOCAL", "EAC_TRANSMITTED_AZIMUTH_LOCAL",
    "The <<VECTOR_AZIMUTH_LOCAL>> toward which light is transmitted (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSMITTED_AZIMUTH_MAGNETIC,
    "TRANSMITTED_AZIMUTH_MAGNETIC", "EAC_TRANSMITTED_AZIMUTH_MAGNETIC",
    "The <<VECTOR_AZIMUTH_MAGNETIC>> toward which light is transmitted (the"
    " <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSMITTED_ELEV_ANGLE_HORIZONTAL,
    "TRANSMITTED_ELEV_ANGLE_HORIZONTAL", "EAC_TRANSMITTED_ELEV_ANGLE_HORIZONTAL",
    "The <<VECTOR_ELEV_ANGLE_HORIZONTAL>> toward which light is transmitted"
    " (the <DIRECTION> of the Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSMITTED_ELEV_ANGLE_LOCAL,
    "TRANSMITTED_ELEV_ANGLE_LOCAL", "EAC_TRANSMITTED_ELEV_ANGLE_LOCAL",
    "The <<VECTOR_ELEV_ANGLE_LOCAL>> of the transmitted light <DIRECTION>"
    " vector (unit Poynting vector).",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[522]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSPORT_CAPACITY,
    "TRANSPORT_CAPACITY", "EAC_TRANSPORT_CAPACITY",
    "The capacity of a <VEHICLE> for the transport and/or storage of"
    " <CARGO>.",
    EDCS_AVT_REAL, EQC_MASS,
    2, &(EGBindingForEA[1357]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSPORT_HELICOPTER_TYPE,
    "TRANSPORT_HELICOPTER_TYPE", "EAC_TRANSPORT_HELICOPTER_TYPE",
    "The design series of a <TRANSPORT_HELICOPTER>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[424]), 20, &(EDCS_Enumerant_Dictionary[8116]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSPORT_LANDING_CRAFT_TYPE,
    "TRANSPORT_LANDING_CRAFT_TYPE", "EAC_TRANSPORT_LANDING_CRAFT_TYPE",
    "The type of a <LANDING_CRAFT> designed for transport dock operations.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 2, &(EDCS_Enumerant_Dictionary[8136]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSPORT_WINGED_AIRCRAFT_TYPE,
    "TRANSPORT_WINGED_AIRCRAFT_TYPE", "EAC_TRANSPORT_WINGED_AIRCRAFT_TYPE",
    "The type of a <TRANSPORT_WINGED_AIRCRAFT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[424]), 13, &(EDCS_Enumerant_Dictionary[8138]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSPORTATION_BED_HEIGHT,
    "TRANSPORTATION_BED_HEIGHT", "EAC_TRANSPORTATION_BED_HEIGHT",
    "The <<HEIGHT>> of the bed of a <LAND_TRANSPORTATION_ROUTE> above the"
    " surrounding <TERRAIN>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[1146]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSPORTATION_ROUTE_LENGTH,
    "TRANSPORTATION_ROUTE_LENGTH", "EAC_TRANSPORTATION_ROUTE_LENGTH",
    "The total distance along a <TRANSPORTATION_ROUTE> between two"
    " <LOCATION>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[855]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TLN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRANSPORTATION_USE,
    "TRANSPORTATION_USE", "EAC_TRANSPORTATION_USE",
    "The type of primary user, function, or authority of a transportation"
    " <SYSTEM>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[317]), 41, &(EDCS_Enumerant_Dictionary[8151]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TUC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TREE_CANOPY_BOTTOM_HEIGHT,
    "TREE_CANOPY_BOTTOM_HEIGHT", "EAC_TREE_CANOPY_BOTTOM_HEIGHT",
    "The <<HEIGHT_AGL>> to the lowest significant canopy branch of the"
    " bottom of the canopy of a <TREE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[831]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[DST]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TREE_CANOPY_LEVEL_COUNT,
    "TREE_CANOPY_LEVEL_COUNT", "EAC_TREE_CANOPY_LEVEL_COUNT",
    "The number of levels of canopy in a <TREED_TRACT> or <FOREST>; the"
    " tree canopy level count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[1218]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TCL]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TREE_COUNT,
    "TREE_COUNT", "EAC_TREE_COUNT",
    "The number of <TREE>s; the tree count.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[1218]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TREE_SPACING,
    "TREE_SPACING", "EAC_TREE_SPACING",
    "The mean distance between centres of adjacent <TREE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[831]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TSD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TREE_TYPE,
    "TREE_TYPE", "EAC_TREE_TYPE",
    "The type of a <NON_EMPTY_SET> of <TREE>s.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1218]), 3, &(EDCS_Enumerant_Dictionary[8192]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TRE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TROPOPAUSE_ALTITUDE,
    "TROPOPAUSE_ALTITUDE", "EAC_TROPOPAUSE_ALTITUDE",
    "The <<ALTITUDE_MSL>> of the <TROPOPAUSE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[576]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TROPOPAUSE_PRESENT,
    "TROPOPAUSE_PRESENT", "EAC_TROPOPAUSE_PRESENT",
    "An indication that the <TROPOPAUSE> is present.",
    EDCS_AVT_BOOLEAN, 0,
    3, &(EGBindingForEA[579]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"TROPOPAUSE indicator code\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TROPOPAUSE_PRESSURE,
    "TROPOPAUSE_PRESSURE", "EAC_TROPOPAUSE_PRESSURE",
    "The <<ATM_PRESSURE>> at the <TROPOPAUSE>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    2, &(EGBindingForEA[574]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"TROPOPAUSE-ANALYSIS-FORECAST lowest tropopause pressure"
    " rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TROPOPAUSE_TEMPERATURE,
    "TROPOPAUSE_TEMPERATURE", "EAC_TROPOPAUSE_TEMPERATURE",
    "The <<AIR_TEMPERATURE>> at the <TROPOPAUSE>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    3, &(EGBindingForEA[579]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"TROPOPAUSE-ANALYSIS-FORECAST temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TRUCK_LOAD_CLASS,
    "TRUCK_LOAD_CLASS", "EAC_TRUCK_LOAD_CLASS",
    "The load class of a <TRUCK>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1168]), 3, &(EDCS_Enumerant_Dictionary[8195]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TSS_IMO_ADOPTED,
    "TSS_IMO_ADOPTED", "EAC_TSS_IMO_ADOPTED",
    "An indication that a marine <TSS_SYSTEM> has been adopted by the IMO.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1037]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TSS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_TUNNEL_CROSS_SECTION,
    "TUNNEL_CROSS_SECTION", "EAC_TUNNEL_CROSS_SECTION",
    "The characteristic cross-sectional shape of a <TUNNEL> when viewed"
    " from the ends.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 3, &(EDCS_Enumerant_Dictionary[8198]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TCS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_UNCOVERING_HEIGHT_KNOWN,
    "UNCOVERING_HEIGHT_KNOWN", "EAC_UNCOVERING_HEIGHT_KNOWN",
    "An indication that information is known about the <<HEIGHT>> to which"
    " a <MARINE_OBJECT> may be uncovered by the <TIDE>.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[54]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HDI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_UNDERBRIDGE_CLEARANCE,
    "UNDERBRIDGE_CLEARANCE", "EAC_UNDERBRIDGE_CLEARANCE",
    "The clearance below a <BRIDGE> measured from the lowest level of the"
    " bridged <SURFACE> to the base of the lower of either a cross beam or"
    " lowest deck of the <BRIDGE>; the underbridge clearance.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: UBD]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_UNDERLYING_MATERIAL_CHARACTERISTIC,
    "UNDERLYING_MATERIAL_CHARACTERISTIC", "EAC_UNDERLYING_MATERIAL_CHARACTERISTIC",
    "The characteristics of the composition of the <MATERIAL> underlying"
    " the <SURFACE> of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[33]), 25, &(EDCS_Enumerant_Dictionary[8201]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: UMC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_UNDERLYING_MATERIAL_TYPE,
    "UNDERLYING_MATERIAL_TYPE", "EAC_UNDERLYING_MATERIAL_TYPE",
    "The type of composition of the <MATERIAL> underlying the <SURFACE> of"
    " an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[33]), 55, &(EDCS_Enumerant_Dictionary[8226]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MCU]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_UPSTREAM_HEIGHT,
    "UPSTREAM_HEIGHT", "EAC_UPSTREAM_HEIGHT",
    "The height of an <OBJECT> above a <WATERCOURSE> measured on the"
    " upstream side.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[164]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HGU]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_URBAN_BUILDING_LIGHTING_INTENSITY,
    "URBAN_BUILDING_LIGHTING_INTENSITY", "EAC_URBAN_BUILDING_LIGHTING_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the <LIGHTING> on an urban <BUILDING>. Zero"
    " means unlit and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1180]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_URBAN_STREET_LIGHTING_INTENSITY,
    "URBAN_STREET_LIGHTING_INTENSITY", "EAC_URBAN_STREET_LIGHTING_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional intensity of the <LIGHTING> on an urban <STREET>. Zero"
    " means unlit and one means maximum intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    5, &(EGBindingForEA[1138]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_URBAN_STREET_PATTERN,
    "URBAN_STREET_PATTERN", "EAC_URBAN_STREET_PATTERN",
    "The predominant geometric configuration of <STREET>s found within a"
    " delineated <TERRAIN_SURFACE_REGION>; urban street pattern.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1165]), 9, &(EDCS_Enumerant_Dictionary[8281]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: USP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_URBAN_TERRAIN_ZONE_TYPE,
    "URBAN_TERRAIN_ZONE_TYPE", "EAC_URBAN_TERRAIN_ZONE_TYPE",
    "The type of an urban terrain zone based on the characterization of"
    " <BUILDING>s and their density.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[50]), 23, &(EDCS_Enumerant_Dictionary[8290]),
    EDCS_REF_TYP_INFORMATIVE, "[UTZB]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_USABLE_LENGTH,
    "USABLE_LENGTH", "EAC_USABLE_LENGTH",
    "The usable <<LENGTH>> of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_USAGE,
    "USAGE", "EAC_USAGE",
    "The primary user, function, or controlling authority of an <OBJECT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[70]), 155, &(EDCS_Enumerant_Dictionary[8313]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: USE]",
    "", EDCS_CONCEPT_STAT_DEPRECATED },

    {EAC_UTILITY_USE,
    "UTILITY_USE", "EAC_UTILITY_USE",
    "The type of a <FACILITY> that is primarily used for utility provision"
    " purposes.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 11, &(EDCS_Enumerant_Dictionary[8468]),
    EDCS_REF_TYP_INFORMATIVE, "[FAD, Annex B: UUC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VARIABLE_SEA_STATE_FRACTION,
    "VARIABLE_SEA_STATE_FRACTION", "EAC_VARIABLE_SEA_STATE_FRACTION",
    "A number between 0 and 1 representing the linearly-scaled fraction of"
    " <<SEA_STATE_CATEGORY>> reports indicating varying"
    " <<SEA_STATE_CATEGORY>>; the variable sea state fraction.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1327]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VARIABLE_WIND_END_DIRECTION,
    "VARIABLE_WIND_END_DIRECTION", "EAC_VARIABLE_WIND_END_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the ending extreme in <<WIND_DIRECTION>>"
    " under variable <<WIND_DIRECTION>> conditions. Variable wind end"
    " direction is normally only reported for <<WIND_SPEED>>s exceeding"
    " 3,09 metres per second (six knots) and the variability must equal or"
    " exceed a range of 60 arc degrees during the preceding two minutes.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[494]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VARIABLE_WIND_START_DIRECTION,
    "VARIABLE_WIND_START_DIRECTION", "EAC_VARIABLE_WIND_START_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the starting extreme in <<WIND_DIRECTION>>"
    " under variable <<WIND_DIRECTION>> conditions. Variable wind start"
    " direction is normally only reported for <<WIND_SPEED>>s exceeding"
    " 3,09 metres per second (six knots) and the variability must equal or"
    " exceed a range of 60 arc degrees during the preceding two minutes.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[494]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VECTOR_AZIMUTH_GEODETIC,
    "VECTOR_AZIMUTH_GEODETIC", "EAC_VECTOR_AZIMUTH_GEODETIC",
    "The smallest angle from vector A to vector B where A is a particular"
    " reference vector fixed in the local x-y plane, perpendicular to the"
    " local normal and defined by the projection onto this plane of the"
    " vector toward geodetic north and B is the projection onto the surface"
    " plane of the vector of interest. The positive sense is clockwise when"
    " looking in the <DIRECTION> of the cross product AxB.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VECTOR_AZIMUTH_LOCAL,
    "VECTOR_AZIMUTH_LOCAL", "EAC_VECTOR_AZIMUTH_LOCAL",
    "The smallest angle from vector A to vector B where A is the local"
    " x-axis fixed in the local x-y plane, perpendicular to the local"
    " normal) and B is the projection onto the surface plane of the vector"
    " of interest. The positive sense is clockwise when looking in the"
    " <DIRECTION> of the cross product AxB.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VECTOR_AZIMUTH_MAGNETIC,
    "VECTOR_AZIMUTH_MAGNETIC", "EAC_VECTOR_AZIMUTH_MAGNETIC",
    "The smallest angle from vector A to vector B where A is the reference"
    " vector with origin in the local x-y plane, perpendicular to the local"
    " normal, and defined by the projection onto this plane of the vector"
    " toward magnetic north and B is the projection onto the surface plane"
    " of the vector of interest. The positive sense is clockwise when"
    " looking in the <DIRECTION> of the cross product AxB.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VECTOR_ELEV_ANGLE_HORIZONTAL,
    "VECTOR_ELEV_ANGLE_HORIZONTAL", "EAC_VECTOR_ELEV_ANGLE_HORIZONTAL",
    "The <<VECTOR_ELEV_ANGLE_LOCAL>> with respect to the local x-y plane,"
    " perpendicular to the local normal.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VECTOR_ELEV_ANGLE_LOCAL,
    "VECTOR_ELEV_ANGLE_LOCAL", "EAC_VECTOR_ELEV_ANGLE_LOCAL",
    "The smallest angle from vector A to vector B where B is the vector of"
    " interest and A is the projection of B on the local x-y plane,"
    " perpendicular to the local normal; the elevation angle. The positive"
    " sense is clockwise when looking in the <DIRECTION> of the cross"
    " product AxB.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    1, &(EGBindingForEA[7]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[TRHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEGETATION_RESTRICTED_SPEED,
    "VEGETATION_RESTRICTED_SPEED", "EAC_VEGETATION_RESTRICTED_SPEED",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional restriction of the <<SPEED>> of ground <GROUND_VEHICLE>s"
    " as a fraction of maximum speed. Zero means no restriction (maximum"
    " speed) and one means completely restricted and immobilized.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[1159]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VRC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEGETATION_TYPE,
    "VEGETATION_TYPE", "EAC_VEGETATION_TYPE",
    "The type of <VEGETATION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1218]), 87, &(EDCS_Enumerant_Dictionary[8479]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VEG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_CAPACITY,
    "VEHICLE_CAPACITY", "EAC_VEHICLE_CAPACITY",
    "The number of <VEHICLE>s that an <OBJECT> can accommodate; the vehicle"
    " capacity.",
    EDCS_AVT_COUNT, 0,
    2, &(EGBindingForEA[199]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VEC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_MAINTENANCE_AVAILABLE,
    "VEHICLE_MAINTENANCE_AVAILABLE", "EAC_VEHICLE_MAINTENANCE_AVAILABLE",
    "The type of vehicle maintenance <FACILITY>s available at a <LOCATION>"
    " or in the near vicinity.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1355]), 18, &(EDCS_Enumerant_Dictionary[8566]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: MFA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_MARKING,
    "VEHICLE_MARKING", "EAC_VEHICLE_MARKING",
    "The marking displayed on a <VEHICLE>, typically including echelon"
    " designation and coded bumper number. The marking is formatted in a"
    " Basic Latin string containing twelve characters as specified by"
    " [EBEV, Section 4.5, Entity Marking - Character Set].",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    2, &(EGBindingForEA[1357]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.5 (Entity Marking)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_SMOKE_TYPE,
    "VEHICLE_SMOKE_TYPE", "EAC_VEHICLE_SMOKE_TYPE",
    "The type or origin of <SMOKE> from a <VEHICLE>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[462]), 4, &(EDCS_Enumerant_Dictionary[8584]),
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.1, Bits: 5-6 (Smoke)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_STORAGE_AREA,
    "VEHICLE_STORAGE_AREA", "EAC_VEHICLE_STORAGE_AREA",
    "The total <<AREA>> of a <STRUCTURE> which can be used for the storage"
    " of <VEHICLE>s.",
    EDCS_AVT_REAL, EQC_AREA,
    3, &(EGBindingForEA[852]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_STORAGE_DOOR_PRI_HEIGHT,
    "VEHICLE_STORAGE_DOOR_PRI_HEIGHT", "EAC_VEHICLE_STORAGE_DOOR_PRI_HEIGHT",
    "The <<HEIGHT>> of the primary <STRUCTURE_ENTRANCE_AND_OR_EXIT> for"
    " <VEHICLE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[852]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_STORAGE_DOOR_PRI_WIDTH,
    "VEHICLE_STORAGE_DOOR_PRI_WIDTH", "EAC_VEHICLE_STORAGE_DOOR_PRI_WIDTH",
    "The <<WIDTH>> of the primary <STRUCTURE_ENTRANCE_AND_OR_EXIT> for"
    " <VEHICLE>s.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[852]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_TRAFFIC_FLOW,
    "VEHICLE_TRAFFIC_FLOW", "EAC_VEHICLE_TRAFFIC_FLOW",
    "The type of flow-pattern of <VEHICLE>s on a <TRANSPORTATION_ROUTE>;"
    " the vehicle traffic flow.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 4, &(EDCS_Enumerant_Dictionary[8588]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: TRF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICLE_TRAFFIC_GEODETIC_DIRECTION,
    "VEHICLE_TRAFFIC_GEODETIC_DIRECTION", "EAC_VEHICLE_TRAFFIC_GEODETIC_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> of <VEHICLE>s on a"
    " <TRANSPORTATION_ROUTE>; the vehicle traffic geodetic direction.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[552]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DF1, DF2, DF3, and DF4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VEHICULAR_SPEED_LIMIT,
    "VEHICULAR_SPEED_LIMIT", "EAC_VEHICULAR_SPEED_LIMIT",
    "The maximum <<SPEED>> legally permitted on a given stretch of a"
    " <LAND_TRANSPORTATION_ROUTE>; the vehicular speed limit.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[1156]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SPM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VELOCITY,
    "VELOCITY", "EAC_VELOCITY",
    "<<SPEED>> in a <DIRECTION>; velocity.",
    EDCS_AVT_REAL, EQC_SPEED,
    1, &(EGBindingForEA[38]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[SOED, \"velocity\", 3]", EDCS_CONCEPT_STAT_ISO },

    {EAC_VENTILATION_FILTER_EFFICIENCY,
    "VENTILATION_FILTER_EFFICIENCY", "EAC_VENTILATION_FILTER_EFFICIENCY",
    "The fraction of <PARTICLE>s in the <AIR> removed as the <AIR> makes a"
    " single pass through ventilation filters; the ventilation filter"
    " efficiency.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    4, &(EGBindingForEA[438]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HVACS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VENTILATION_INFILTRATION_RATE,
    "VENTILATION_INFILTRATION_RATE", "EAC_VENTILATION_INFILTRATION_RATE",
    "The rate at which a ventilation <SYSTEM> draws in exterior <AIR>. The"
    " rate is expressed as the fraction of the <<VOLUME>> of <AIR> in the"
    " <STRUCTURE> drawn in per unit time.",
    EDCS_AVT_REAL, EQC_RATE,
    4, &(EGBindingForEA[644]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HVACS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VERTICAL_CLEARANCE_CLOSED,
    "VERTICAL_CLEARANCE_CLOSED", "EAC_VERTICAL_CLEARANCE_CLOSED",
    "The vertical clearance of an <OBJECT> (for example: a closed lifting"
    " <BRIDGE>) in its closed condition measured from the ground <SURFACE>"
    " underneath to the <OBJECT> overhead.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VCC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VERTICAL_CLEARANCE_OPENED,
    "VERTICAL_CLEARANCE_OPENED", "EAC_VERTICAL_CLEARANCE_OPENED",
    "The vertical clearance of an <OBJECT> (for example: an opened lifting"
    " <BRIDGE>) in its opened condition measured from the ground <SURFACE>"
    " underneath to the <OBJECT> overhead.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VCO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VERTICAL_CLEARANCE_SAFE,
    "VERTICAL_CLEARANCE_SAFE", "EAC_VERTICAL_CLEARANCE_SAFE",
    "The safe vertical clearance of an <OBJECT> measured from the ground"
    " <SURFACE> underneath to the <OBJECT> overhead.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VCS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VERTICAL_DATUM_IDENTIFIER,
    "VERTICAL_DATUM_IDENTIFIER", "EAC_VERTICAL_DATUM_IDENTIFIER",
    "The designation of a <VERTICAL_DATUM>; vertical datum identifier.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1245]), 4, &(EDCS_Enumerant_Dictionary[8592]),
    EDCS_REF_TYP_INFORMATIVE, "[GMCG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VERTICAL_LOAD_BEARING_CAPACITY,
    "VERTICAL_LOAD_BEARING_CAPACITY", "EAC_VERTICAL_LOAD_BEARING_CAPACITY",
    "The maximum distributed load per unit cross-section a vertical"
    " <OBJECT> can support; the vertical load bearing capacity.",
    EDCS_AVT_REAL, EQC_SURFACE_DENSITY,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VERTICAL_MEASUREMENT_QUALITY,
    "VERTICAL_MEASUREMENT_QUALITY", "EAC_VERTICAL_MEASUREMENT_QUALITY",
    "The quality of a vertical measurement.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1245]), 2, &(EDCS_Enumerant_Dictionary[8596]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VEM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VERTICAL_PASSAGE_ENCLOSED,
    "VERTICAL_PASSAGE_ENCLOSED", "EAC_VERTICAL_PASSAGE_ENCLOSED",
    "An indication that a vertical passage (for example: a <RAMP>,"
    " a<STAIR>, and/or an <ESCALATOR>) in a <STRUCTURE> is fully enclosed"
    " by <WALL>s on both sides.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1337]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VESSEL_DENSITY,
    "VESSEL_DENSITY", "EAC_VESSEL_DENSITY",
    "The areal density of <WATER_SURFACE_VESSEL>s in a <REGION> of a"
    " <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    4, &(EGBindingForEA[1026]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Historical Temporal Shipping Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VESSEL_DENSITY_ACOUSTIC_LEVEL_CATEGORY,
    "VESSEL_DENSITY_ACOUSTIC_LEVEL_CATEGORY", "EAC_VESSEL_DENSITY_ACOUSTIC_LEVEL_CATEGORY",
    "The category of <<VESSEL_DENSITY>>, determined according to induced"
    " ambient acoustic noise levels in a <WATERBODY>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[254]), 4, &(EDCS_Enumerant_Dictionary[8598]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS], [WENZ]", EDCS_CONCEPT_STAT_ISO },

    {EAC_VESSEL_FUNCTION,
    "VESSEL_FUNCTION", "EAC_VESSEL_FUNCTION",
    "The operating function of a <VESSEL>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 23, &(EDCS_Enumerant_Dictionary[8602]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VESSEL_LOAD_RESTRICTIONS,
    "VESSEL_LOAD_RESTRICTIONS", "EAC_VESSEL_LOAD_RESTRICTIONS",
    "The description of any load restrictions that apply to <VESSEL>s using"
    " a <MARINE_ROUTE> or marine <FACILITY>.",
    EDCS_AVT_STRING, 0,
    3, &(EGBindingForEA[1039]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SLC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VESSEL_TYPE,
    "VESSEL_TYPE", "EAC_VESSEL_TYPE",
    "The type of a <VESSEL>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1042]), 11, &(EDCS_Enumerant_Dictionary[8625]),
    EDCS_REF_TYP_INFORMATIVE, "[OAML, Historical Temporal Shipping Database]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VIEW_OPENING_PRESENT,
    "VIEW_OPENING_PRESENT", "EAC_VIEW_OPENING_PRESENT",
    "An indication that an <OBJECT> contains a view <APERTURE> (for"
    " example: a peephole or small <WINDOW> in a <DOOR>).",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VIRTUAL_AIR_TEMPERATURE,
    "VIRTUAL_AIR_TEMPERATURE", "EAC_VIRTUAL_AIR_TEMPERATURE",
    "In a <SYSTEM> of moist <AIR>, the <<AIR_TEMPERATURE>> of dry <AIR>"
    " having the same <<AIR_DENSITY>> and <<ATM_PRESSURE>> as the moist"
    " <AIR>; the virtual air temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"virtual air temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VISIBILITY_DISTANCE,
    "VISIBILITY_DISTANCE", "EAC_VISIBILITY_DISTANCE",
    "The greatest distance in a given <DIRECTION> at which it is just"
    " possible to see and identify with the unaided eye either: (1) in the"
    " daytime, a prominent dark <OBJECT> against the sky at the horizon or"
    " (2) at night, a known, preferably unfocused, moderately intense"
    " <LIGHT>; visibility distance.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[825]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VISIBILITY_DISTANCE_QUALITY,
    "VISIBILITY_DISTANCE_QUALITY", "EAC_VISIBILITY_DISTANCE_QUALITY",
    "The quality of a <<VISIBILITY_DISTANCE>> observation.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[29]), 4, &(EDCS_Enumerant_Dictionary[8636]),
    EDCS_REF_TYP_INFORMATIVE, "[QCMO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VISIBILITY_DISTANCE_VARIABLE,
    "VISIBILITY_DISTANCE_VARIABLE", "EAC_VISIBILITY_DISTANCE_VARIABLE",
    "An indication that a reported <<VISIBILITY_DISTANCE>> observation is"
    " variable.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[29]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"VISIBILITY-OBSERVATION variability code\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VISUAL_OPACITY,
    "VISUAL_OPACITY", "EAC_VISUAL_OPACITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional opacity (or alpha) of an <OBJECT> in the visual spectrum."
    " The value is determined by how much light fails to penetrate through"
    " the <OBJECT>. Zero means that no light is blocked (all light"
    " penetrates) and one means that all light is blocked.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[161]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[CGPP]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VISUAL_REFLECTOR_PRESENT,
    "VISUAL_REFLECTOR_PRESENT", "EAC_VISUAL_REFLECTOR_PRESENT",
    "An indication that a visual reflector is present on an"
    " <AID_TO_NAVIGATION>.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[789]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VRF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VISUAL_WAVE_HEIGHT,
    "VISUAL_WAVE_HEIGHT", "EAC_VISUAL_WAVE_HEIGHT",
    "The mean apparent <<HEIGHT>> of <WATER_WAVE>s that is determined"
    " visually and measured from trough to crest; the visual wave height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VOLCANIC_FORMATION_TYPE,
    "VOLCANIC_FORMATION_TYPE", "EAC_VOLCANIC_FORMATION_TYPE",
    "The type of morphology of the <TERRAIN> created by volcanic activity;"
    " the volcanic formation type.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[35]), 5, &(EDCS_Enumerant_Dictionary[8640]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: VGT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VOLTAGE_LEVEL,
    "VOLTAGE_LEVEL", "EAC_VOLTAGE_LEVEL",
    "The nominal voltage level of supplied electrical power to a"
    " transportation <SYSTEM>.",
    EDCS_AVT_REAL, EQC_ELECTRIC_POTENTIAL,
    3, &(EGBindingForEA[864]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: ETN]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VOLUME,
    "VOLUME", "EAC_VOLUME",
    "The internal volume of an <OBJECT>.",
    EDCS_AVT_REAL, EQC_VOLUME,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_VOLUME_BACKSCATTER_GRADIENT,
    "VOLUME_BACKSCATTER_GRADIENT", "EAC_VOLUME_BACKSCATTER_GRADIENT",
    "The negative of the depth gradient of the ratio of the flux returned"
    " (reflected directly back in the <DIRECTION> of incidence) to the"
    " incident flux (generally in decibels per metre of depth) for an"
    " <OBJECT>; the volume backscatter gradient.",
    EDCS_AVT_REAL, EQC_POWER_LEVEL_DIFF_LEN_GRADIENT,
    2, &(EGBindingForEA[186]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WAKE_INTENSITY,
    "WAKE_INTENSITY", "EAC_WAKE_INTENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the production rate of <WATERBODY_SURFACE> wakes induced"
    " by the movement of a <VESSEL> relative to <WATER_WAVE>s and"
    " <WATER_CURRENT>s. Zero means no wake at all and one means maximum"
    " intensity.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[1030]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[EBEV, 4.3.1.3, Bits: 7-8 (Trailing Effects)]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WALL_PREDOMINANT_PATTERN,
    "WALL_PREDOMINANT_PATTERN", "EAC_WALL_PREDOMINANT_PATTERN",
    "The predominant visual pattern of the exterior <SURFACE>s of the"
    " <EXTERIOR_WALL>s of a <STRUCTURE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1335]), 13, &(EDCS_Enumerant_Dictionary[8645]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WALL_PREDOMINANT_SURFACE_MATERIAL,
    "WALL_PREDOMINANT_SURFACE_MATERIAL", "EAC_WALL_PREDOMINANT_SURFACE_MATERIAL",
    "The predominant outermost <MATERIAL> covering the <SURFACE> of a"
    " <WALL>.",
    EDCS_AVT_ENUMERATION, 0,
    4, &(EGBindingForEA[1270]), 19, &(EDCS_Enumerant_Dictionary[8658]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WALL_TYPE,
    "WALL_TYPE", "EAC_WALL_TYPE",
    "The type of a <WALL>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[43]), 2, &(EDCS_Enumerant_Dictionary[8677]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WTI]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_ACOUSTIC_TRANS_LOSS_MODEL,
    "WATER_ACOUSTIC_TRANS_LOSS_MODEL", "EAC_WATER_ACOUSTIC_TRANS_LOSS_MODEL",
    "A type of <<ACOUSTIC_TRANSMISSION_LOSS>> model or database for"
    " <WATERBODY>s.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[209]), 8, &(EDCS_Enumerant_Dictionary[8679]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_ATTENUATION_TURBIDITY,
    "WATER_ATTENUATION_TURBIDITY", "EAC_WATER_ATTENUATION_TURBIDITY",
    "A measurement of the reduction of transparency of a liquid caused"
    " attenuation due to by the presence of undissolved matter; turbidity."
    " The measurement shall be made in accordance with the procedures"
    " specified in 6.4 of I7027.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1196]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[I7027, 6.3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_ACOUSTIC_AMBIENT_NOISE_SPECTRAL_MODEL,
    "WATERBODY_ACOUSTIC_AMBIENT_NOISE_SPECTRAL_MODEL", "EAC_WATERBODY_ACOUSTIC_AMBIENT_NOISE_SPECTRAL_MODEL",
    "A type of acoustic ambient noise spectral model or database for"
    " <WATERBODY>s.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[209]), 9, &(EDCS_Enumerant_Dictionary[8687]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_BIOLUMINESCENCE,
    "WATERBODY_BIOLUMINESCENCE", "EAC_WATERBODY_BIOLUMINESCENCE",
    "The rate of photon emittance of visible light from <LIVING_ORGANISM>s"
    " in a <WATERBODY>; the waterbody luminescence.",
    EDCS_AVT_REAL, EQC_VOLUMETRIC_ENTITY_EMIT_RATE,
    4, &(EGBindingForEA[1174]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"BIOLUMINESCENCE-ANALYSIS-FORECAST luminance rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_FLOOR_CLUTTER_DENSITY,
    "WATERBODY_FLOOR_CLUTTER_DENSITY", "EAC_WATERBODY_FLOOR_CLUTTER_DENSITY",
    "The areal density of <OBJECT>s on a <WATERBODY_FLOOR_REGION> that"
    " appear to acoustic sensors to be, but that are not, <EXPLOSIVE_MINE>s.",
    EDCS_AVT_REAL, EQC_AREAL_ENTITY_DENSITY,
    5, &(EGBindingForEA[61]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_FLOOR_CONFIGURATION,
    "WATERBODY_FLOOR_CONFIGURATION", "EAC_WATERBODY_FLOOR_CONFIGURATION",
    "The type of a <WATERBODY_FLOOR_TOPOGRAPHIC_CONFIGURATION>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1308]), 14, &(EDCS_Enumerant_Dictionary[8696]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BCT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_FLOOR_GRAZING_ANGLE,
    "WATERBODY_FLOOR_GRAZING_ANGLE", "EAC_WATERBODY_FLOOR_GRAZING_ANGLE",
    "The mean angle between the horizontal plane at a <WATERBODY_FLOOR> and"
    " the scattered acoustic rays; the waterbody floor grazing angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[216]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_FLOOR_MATERIAL_TYPE,
    "WATERBODY_FLOOR_MATERIAL_TYPE", "EAC_WATERBODY_FLOOR_MATERIAL_TYPE",
    "The predominant type of <MATERIAL> composing a <WATERBODY_FLOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1285]), 16, &(EDCS_Enumerant_Dictionary[8710]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BMC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_FLOOR_MORPHOLOGY,
    "WATERBODY_FLOOR_MORPHOLOGY", "EAC_WATERBODY_FLOOR_MORPHOLOGY",
    "The morphology of a <WATERBODY_FLOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1308]), 55, &(EDCS_Enumerant_Dictionary[8726]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[S57A, Attribute: CATSEA]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_FLOOR_OBJECT_TYPE,
    "WATERBODY_FLOOR_OBJECT_TYPE", "EAC_WATERBODY_FLOOR_OBJECT_TYPE",
    "The type of a <TERRAIN_SURFACE_OBJECT> that is located on a"
    " <WATERBODY_FLOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[52]), 10, &(EDCS_Enumerant_Dictionary[8781]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SFC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_FLOOR_ROUGHNESS_CATEGORY,
    "WATERBODY_FLOOR_ROUGHNESS_CATEGORY", "EAC_WATERBODY_FLOOR_ROUGHNESS_CATEGORY",
    "A qualitative characterization of the roughness of a <WATERBODY_FLOOR>"
    " at spatial frequencies relevant to <EXPLOSIVE_MINE> detection; the"
    " waterbody floor roughness category.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1290]), 3, &(EDCS_Enumerant_Dictionary[8791]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_PROPERTY_SET_ACOUSTIC_TYPE,
    "WATERBODY_PROPERTY_SET_ACOUSTIC_TYPE", "EAC_WATERBODY_PROPERTY_SET_ACOUSTIC_TYPE",
    "The type of the acoustic properties of a"
    " <WATERBODY_ACOUSTIC_PROPERTY_SET>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[286]), 15, &(EDCS_Enumerant_Dictionary[8794]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SOUND_SPEED,
    "WATERBODY_SOUND_SPEED", "EAC_WATERBODY_SOUND_SPEED",
    "The <<SPEED>> of sound in a <WATERBODY>.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[294]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SURFACE_DATA_OBSERVATION_METHOD,
    "WATERBODY_SURFACE_DATA_OBSERVATION_METHOD", "EAC_WATERBODY_SURFACE_DATA_OBSERVATION_METHOD",
    "The method of observation, measurement, collection, prediction, or"
    " estimation of one or more characteristics of a <WATERBODY_SURFACE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1251]), 7, &(EDCS_Enumerant_Dictionary[8809]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SURFACE_GRAZING_ANGLE,
    "WATERBODY_SURFACE_GRAZING_ANGLE", "EAC_WATERBODY_SURFACE_GRAZING_ANGLE",
    "The mean angle between the horizontal plane at a <WATERBODY_SURFACE>"
    " and scattered acoustic rays; the waterbody surface grazing angle.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    3, &(EGBindingForEA[219]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[PUWS]", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SURFACE_ICE_FRACTION,
    "WATERBODY_SURFACE_ICE_FRACTION", "EAC_WATERBODY_SURFACE_ICE_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional <<AREA>> of a <WATERBODY_SURFACE> that is covered by"
    " <ICE>. Zero means no <ICE> is present and one means the"
    " <WATERBODY_SURFACE> is completely covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[1090]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SURFACE_INSTANTANEOUS_HEIGHT,
    "WATERBODY_SURFACE_INSTANTANEOUS_HEIGHT", "EAC_WATERBODY_SURFACE_INSTANTANEOUS_HEIGHT",
    "The instantaneous height of a <WATERBODY_SURFACE> above a"
    " <VERTICAL_DATUM> or <SOUNDING_DATUM>. For <OCEAN>s and <SEA>s the"
    " <SOUNDING_DATUM> is defined as MSL corrected for the <TIDE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SURFACE_TEMPERATURE,
    "WATERBODY_SURFACE_TEMPERATURE", "EAC_WATERBODY_SURFACE_TEMPERATURE",
    "The <<WATERBODY_TEMPERATURE>> measured, estimated, or predicted at or"
    " near a <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1347]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SURFACE_U_WIND_STRESS,
    "WATERBODY_SURFACE_U_WIND_STRESS", "EAC_WATERBODY_SURFACE_U_WIND_STRESS",
    "The U component (geodetic west-east direction, where east is positive)"
    " of the stress on a <WATERBODY_SURFACE> induced by <WIND>.",
    EDCS_AVT_REAL, EQC_MOMENTUM,
    2, &(EGBindingForEA[694]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WAVE-FORECAST-ANALYSIS wind stress u component rate\"]",
    "[NPDM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SURFACE_V_WIND_STRESS,
    "WATERBODY_SURFACE_V_WIND_STRESS", "EAC_WATERBODY_SURFACE_V_WIND_STRESS",
    "The V component (geodetic south-north direction, where north is"
    " positive) of the stress on a <WATERBODY_SURFACE> induced by <WIND>.",
    EDCS_AVT_REAL, EQC_MOMENTUM,
    2, &(EGBindingForEA[694]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WAVE-FORECAST-ANALYSIS wind stress v component rate\"]",
    "[NPDM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_SURFACE_WIND_STRESS,
    "WATERBODY_SURFACE_WIND_STRESS", "EAC_WATERBODY_SURFACE_WIND_STRESS",
    "The total stress on a <WATERBODY_SURFACE> induced by <WIND>.",
    EDCS_AVT_REAL, EQC_MOMENTUM,
    2, &(EGBindingForEA[694]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[NPDM]", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERBODY_TEMPERATURE,
    "WATERBODY_TEMPERATURE", "EAC_WATERBODY_TEMPERATURE",
    "The <<TEMPERATURE>> of a <WATERBODY>.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[1345]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"SEA-SURFACE-TEMPERATURE-OBSERVATION water temperature\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_CHANNEL_SAFE_HORIZONTAL_CLEARANCE,
    "WATER_CHANNEL_SAFE_HORIZONTAL_CLEARANCE", "EAC_WATER_CHANNEL_SAFE_HORIZONTAL_CLEARANCE",
    "The minimum safe horizontal distance between adjacent <STRUCTURE>s on"
    " either side of a <WATER_CHANNEL>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    5, &(EGBindingForEA[796]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SHC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_CHANNEL_TYPE,
    "WATER_CHANNEL_TYPE", "EAC_WATER_CHANNEL_TYPE",
    "The type of a <WATER_CHANNEL>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[974]), 1, &(EDCS_Enumerant_Dictionary[8816]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CHT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_CURRENT_APPEARANCE_MONTH,
    "WATER_CURRENT_APPEARANCE_MONTH", "EAC_WATER_CURRENT_APPEARANCE_MONTH",
    "The <<MONTH>> of appearance of a <WATER_CURRENT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1351]), 12, &(EDCS_Enumerant_Dictionary[8817]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HS1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_CURRENT_DIRECTION,
    "WATER_CURRENT_DIRECTION", "EAC_WATER_CURRENT_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> of a <WATER_CURRENT>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[554]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: D60-D71 and D80-D91]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_CURRENT_DISAPPEARANCE_MONTH,
    "WATER_CURRENT_DISAPPEARANCE_MONTH", "EAC_WATER_CURRENT_DISAPPEARANCE_MONTH",
    "The <<MONTH>> of disappearance of a <WATER_CURRENT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1351]), 12, &(EDCS_Enumerant_Dictionary[8829]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HS2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_CURRENT_REFERENCE,
    "WATER_CURRENT_REFERENCE", "EAC_WATER_CURRENT_REFERENCE",
    "The reference time of a measurement of a <WATER_CURRENT>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1351]), 24, &(EDCS_Enumerant_Dictionary[8841]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B, C60-C80 and D60-D91]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_CURRENT_SPEED,
    "WATER_CURRENT_SPEED", "EAC_WATER_CURRENT_SPEED",
    "The <<SPEED>> of a <WATER_CURRENT>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[1325]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CRS]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_CURRENT_TYPE,
    "WATER_CURRENT_TYPE", "EAC_WATER_CURRENT_TYPE",
    "The type of a <WATER_CURRENT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[53]), 10, &(EDCS_Enumerant_Dictionary[8865]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: CUR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_DEPTH,
    "WATER_DEPTH", "EAC_WATER_DEPTH",
    "The depth of <WATER> from a <SURFACE_DATUM> to a <WATERBODY_FLOOR>, as"
    " a positive number.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1247]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"BATHYMETRIC-MEASUREMENT ocean floor depth dimension\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_DIFFUSE_TURBIDITY,
    "WATER_DIFFUSE_TURBIDITY", "EAC_WATER_DIFFUSE_TURBIDITY",
    "A measurement of the reduction of transparency of a liquid caused by"
    " diffusion due to the presence of undissolved matter; turbidity. The"
    " measurement shall be made in accordance with the procedures specified"
    " in 6.3 of I7027.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1196]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[I7027, 6.3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_LEVEL_EFFECT,
    "WATER_LEVEL_EFFECT", "EAC_WATER_LEVEL_EFFECT",
    "The effect of surrounding <WATER> on an <OBJECT>; the water level"
    " effect.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[0]), 8, &(EDCS_Enumerant_Dictionary[8875]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WLE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_QUALITY,
    "WATER_QUALITY", "EAC_WATER_QUALITY",
    "The quality of <WATER> for drinking.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1136]), 4, &(EDCS_Enumerant_Dictionary[8883]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: YWQ]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_TABLE_DEPTH,
    "WATER_TABLE_DEPTH", "EAC_WATER_TABLE_DEPTH",
    "The mean depth of a zone of saturation in the subsurface <TERRAIN>"
    " except where bounded by an impermeable body (for example: <ROCK>) in"
    " which no water table exists; the water table depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1055]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: YWT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_TYPE,
    "WATER_TYPE", "EAC_WATER_TYPE",
    "The type of available <WATER>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1136]), 6, &(EDCS_Enumerant_Dictionary[8887]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: SCC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATER_VAPOUR_PRESSURE,
    "WATER_VAPOUR_PRESSURE", "EAC_WATER_VAPOUR_PRESSURE",
    "The partial pressure of water vapour in an <ATMOSPHERE>.",
    EDCS_AVT_REAL, EQC_PRESSURE,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERCOURSE_CHANNEL_TYPE,
    "WATERCOURSE_CHANNEL_TYPE", "EAC_WATERCOURSE_CHANNEL_TYPE",
    "The type of trough-like depression that is normally occupied by a"
    " <WATERCOURSE>; the watercourse channel type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1066]), 7, &(EDCS_Enumerant_Dictionary[8893]),
    EDCS_REF_TYP_INFORMATIVE, "[FPG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERCOURSE_GAP_WIDTH,
    "WATERCOURSE_GAP_WIDTH", "EAC_WATERCOURSE_GAP_WIDTH",
    "The predominant <<TERRAIN_GAP_WIDTH>>, measured between the tops of"
    " the first accessible breaks in slope above mean water level on each"
    " bank of a <WATERCOURSE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[808]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: GW1, GW2, and GW3]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WATERCOURSE_SINK_TYPE,
    "WATERCOURSE_SINK_TYPE", "EAC_WATERCOURSE_SINK_TYPE",
    "The type of the sink of a <WATERCOURSE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1053]), 4, &(EDCS_Enumerant_Dictionary[8900]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WAVE_SPECTRAL_DENSITY,
    "WAVE_SPECTRAL_DENSITY", "EAC_WAVE_SPECTRAL_DENSITY",
    "The power represented by a spectrum of <WATER_WAVE>s at a particular"
    " centre <<FREQUENCY>> and centre <DIRECTION>; the wave spectral"
    " density.",
    EDCS_AVT_REAL, EQC_POWER,
    1, &(EGBindingForEA[54]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[PPO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WAVE_WHITECAP_RATE,
    "WAVE_WHITECAP_RATE", "EAC_WAVE_WHITECAP_RATE",
    "The rate of occurrence of <WATER_WAVE>s bearing whitecaps on their"
    " crests due to <WIND>.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[1327]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[BOWD, Chapter 37]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WAVELENGTH,
    "WAVELENGTH", "EAC_WAVELENGTH",
    "The distance in a periodic wave between two points of corresponding"
    " phase in consecutive cycles; the wavelength [AHD, \"wavelength\", 1].",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[15]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WAYPOINT_TYPE,
    "WAYPOINT_TYPE", "EAC_WAYPOINT_TYPE",
    "The type of an <AVIATION_WAYPOINT>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[49]), 24, &(EDCS_Enumerant_Dictionary[8904]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WPT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WEAPONS_RANGE_TYPE,
    "WEAPONS_RANGE_TYPE", "EAC_WEAPONS_RANGE_TYPE",
    "The type of a <WEAPONS_RANGE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 6, &(EDCS_Enumerant_Dictionary[8928]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: FRT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WEATHER_MEASUREMENT_TECHNIQUE,
    "WEATHER_MEASUREMENT_TECHNIQUE", "EAC_WEATHER_MEASUREMENT_TECHNIQUE",
    "The technique or method of weather measurement.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 2, &(EDCS_Enumerant_Dictionary[8934]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WELL_TYPE,
    "WELL_TYPE", "EAC_WELL_TYPE",
    "The type of a <WELL>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[25]), 7, &(EDCS_Enumerant_Dictionary[8936]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WFT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WET_BULB_AIR_TEMPERATURE,
    "WET_BULB_AIR_TEMPERATURE", "EAC_WET_BULB_AIR_TEMPERATURE",
    "The <<AIR_TEMPERATURE>> that a parcel of <AIR> would have, if cooled"
    " adiabatically at constant <<ATM_PRESSURE>> to the water vapour"
    " saturation point by evaporation of <WATER> into it, with all latent"
    " heat being supplied by the parcel of <AIR>; the wet bulb air"
    " temperature.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WET_GAP_WIDTH,
    "WET_GAP_WIDTH", "EAC_WET_GAP_WIDTH",
    "The <<WATERCOURSE_GAP_WIDTH>> at low <TIDE>; the wet gap width.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WD4]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WET_SOIL_TRAFFICABILITY,
    "WET_SOIL_TRAFFICABILITY", "EAC_WET_SOIL_TRAFFICABILITY",
    "The <<SOIL_TYPE>> further categorized by its wet weather"
    " trafficability characteristics.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[648]), 6, &(EDCS_Enumerant_Dictionary[8943]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: STG]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WETLAND_SURFACE_FORM,
    "WETLAND_SURFACE_FORM", "EAC_WETLAND_SURFACE_FORM",
    "The type and/or structure of a <WETLAND>; the wetland surface form.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[35]), 21, &(EDCS_Enumerant_Dictionary[8949]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: BOC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIDTH,
    "WIDTH", "EAC_WIDTH",
    "The length of the shorter of two orthogonal linear axes of an"
    " <OBJECT>, measured in the horizontal plane. For a square <OBJECT>,"
    " either axis may be measured; for a round <OBJECT>, the diameter is"
    " measured. For a <BRIDGE>, the distance perpendicular to the axis"
    " between the <BRIDGE_PIER>s is measured.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[114]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WGF]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_ABSOLUTE_VORTICITY,
    "WIND_ABSOLUTE_VORTICITY", "EAC_WIND_ABSOLUTE_VORTICITY",
    "The vorticity of <WIND> determined with respect to an absolute"
    " coordinate system; the wind absolute vorticity.",
    EDCS_AVT_REAL, EQC_ANGULAR_VELOCITY,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"absolute vorticity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_CALM_FRACTION_CLIMATOLOGY,
    "WIND_CALM_FRACTION_CLIMATOLOGY", "EAC_WIND_CALM_FRACTION_CLIMATOLOGY",
    "The historical (climatology) fraction of calm <<WIND_SPEED>>s (less"
    " than 2,575 metres per second or equivalently five knots).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_CATEGORY,
    "WIND_CATEGORY", "EAC_WIND_CATEGORY",
    "A categorization of <WIND> based on <<WIND_SPEED>> and its variability.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 4, &(EDCS_Enumerant_Dictionary[8970]),
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-ANALYSIS-FORECAST wind type code\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_CHILL_TEMPERATURE_INDEX,
    "WIND_CHILL_TEMPERATURE_INDEX", "EAC_WIND_CHILL_TEMPERATURE_INDEX",
    "A means of quantifying the combined effect of low <<AIR_TEMPERATURE>>"
    " and <<WIND_SPEED>> on the body <<TEMPERATURE>> of <HUMAN>s that may"
    " result in hypothermia. The value is expressed as an equivalent"
    " <<TEMPERATURE>> in degrees Celsius given by the formula: 13,1267 +"
    " (1,1187 * T) - (13,9468 * V^(0,16)) + (0,4863 * T * V^(0,16)) where V"
    " is the <<WIND_SPEED>> in metres per second at a <<HEIGHT_AGL>> of 1,5"
    " metres (approximately 5 feet) and T is the <<AIR_TEMPERATURE>> in"
    " degrees Celsius; the wind chill temperature index.",
    EDCS_AVT_REAL, EQC_THERMO_TEMPERATURE,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NWSWC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_CIRCULARITY_COEFFICIENT_CLIMATOLOGY,
    "WIND_CIRCULARITY_COEFFICIENT_CLIMATOLOGY", "EAC_WIND_CIRCULARITY_COEFFICIENT_CLIMATOLOGY",
    "The historical (climatology) quantity of the ratio of the standard"
    " deviation of the <<WIND_SPEED_U>> to the standard deviation of the"
    " <<WIND_SPEED_V>>, for a defined period of record; the wind"
    " circularity coefficient climatology.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_DIRECTION,
    "WIND_DIRECTION", "EAC_WIND_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which the <WIND> is"
    " blowing.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[494]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"wind direction\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_DIRECTION_CLIMATOLOGY,
    "WIND_DIRECTION_CLIMATOLOGY", "EAC_WIND_DIRECTION_CLIMATOLOGY",
    "The mean historical (climatology) <<WIND_DIRECTION>>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[494]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_DIRECTION_OCTANT_CLIMATOLOGY,
    "WIND_DIRECTION_OCTANT_CLIMATOLOGY", "EAC_WIND_DIRECTION_OCTANT_CLIMATOLOGY",
    "The historical (climatology) <<WIND_DIRECTION>> categorized by"
    " cardinal vector octant (a 45 arc degree sector centred on a cardinal"
    " direction).",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 8, &(EDCS_Enumerant_Dictionary[8974]),
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY mean direction angle\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_DIRECTION_OCTANT_FRACTION,
    "WIND_DIRECTION_OCTANT_FRACTION", "EAC_WIND_DIRECTION_OCTANT_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of observations reporting <<WIND_DIRECTION>>s within a"
    " cardinal vector octant (a 45 arc degree sector centred on a cardinal"
    " <DIRECTION>).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_DIRECTION_QUALITY,
    "WIND_DIRECTION_QUALITY", "EAC_WIND_DIRECTION_QUALITY",
    "The quality of a <<WIND_DIRECTION>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 4, &(EDCS_Enumerant_Dictionary[8982]),
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_DIRECTION_VARIABILITY,
    "WIND_DIRECTION_VARIABILITY", "EAC_WIND_DIRECTION_VARIABILITY",
    "The angular range of the <<WIND_DIRECTION>> during a relatively short"
    " reporting period.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[494]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FMH1, 5.4.2]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_DIVERGENCE,
    "WIND_DIVERGENCE", "EAC_WIND_DIVERGENCE",
    "The horizontal expansion or spreading out of the vector field of the"
    " <WIND>; the wind divergence.",
    EDCS_AVT_REAL, EQC_RATE,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_EQUIPMENT_TYPE,
    "WIND_EQUIPMENT_TYPE", "EAC_WIND_EQUIPMENT_TYPE",
    "The type of measuring <EQUIPMENT> used to measure a <<WIND_DIRECTION>>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[582]), 9, &(EDCS_Enumerant_Dictionary[8986]),
    EDCS_REF_TYP_INFORMATIVE, "[WMO306]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_GALE_FORCE_RATE_CLIMATOLOGY,
    "WIND_GALE_FORCE_RATE_CLIMATOLOGY", "EAC_WIND_GALE_FORCE_RATE_CLIMATOLOGY",
    "The fraction of historical (climatology) gale force <<WIND_SPEED>>s"
    " (greater than or equal to 17,49 metres per second or equivalently 34"
    " knots).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_GUST_SPEED,
    "WIND_GUST_SPEED", "EAC_WIND_GUST_SPEED",
    "The <<SPEED>> of a sudden, brief increase in <<WIND_SPEED>>; the wind"
    " gust speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182, \"gust\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_GUST_SPREAD,
    "WIND_GUST_SPREAD", "EAC_WIND_GUST_SPREAD",
    "The difference between adjacent peaks and lulls in <<WIND_SPEED>>; the"
    " wind gust spread.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[F5-33]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_OMEGA,
    "WIND_OMEGA", "EAC_WIND_OMEGA",
    "The vertical rate of movement of <AIR> relative to pressure"
    " coordinates, where downward is positive; the wind omega.",
    EDCS_AVT_REAL, EQC_PRESSURE_CHANGE_RATE,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO182]",
    "[GMET]", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_RELATIVE_VORTICITY,
    "WIND_RELATIVE_VORTICITY", "EAC_WIND_RELATIVE_VORTICITY",
    "The vorticity of <WIND> determined with respect to a system of"
    " coordinates fixed relative to a <PLANETARY_SURFACE>; the wind"
    " relative vorticity.",
    EDCS_AVT_REAL, EQC_ANGULAR_VELOCITY,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"relative vorticity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_RESPONSE_FRACTION,
    "WIND_RESPONSE_FRACTION", "EAC_WIND_RESPONSE_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the response to the <<WIND_SPEED>> and/or"
    " <<WIND_DIRECTION>> of an <OBJECT>. Zero means no wind response at all"
    " and one means maximum response.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    3, &(EGBindingForEA[95]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED,
    "WIND_SPEED", "EAC_WIND_SPEED",
    "The ratio of the distance covered by moving <AIR> to the"
    " <<TIME_QUANTITY>> taken to cover it; the wind speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"wind speed\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_20_PERCENTILE_CLIMATOLOGY,
    "WIND_SPEED_20_PERCENTILE_CLIMATOLOGY", "EAC_WIND_SPEED_20_PERCENTILE_CLIMATOLOGY",
    "The minimum <<WIND_SPEED>> that is greater than 20 percent of the"
    " <<WIND_SPEED_CLIMATOLOGY>>s.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY twenty percentile rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_50_PERCENTILE_CLIMATOLOGY,
    "WIND_SPEED_50_PERCENTILE_CLIMATOLOGY", "EAC_WIND_SPEED_50_PERCENTILE_CLIMATOLOGY",
    "The minimum <<WIND_SPEED>> that is greater than 50 percent of the"
    " <<WIND_SPEED_CLIMATOLOGY>>s.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY fifty percentile rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_80_PERCENTILE_CLIMATOLOGY,
    "WIND_SPEED_80_PERCENTILE_CLIMATOLOGY", "EAC_WIND_SPEED_80_PERCENTILE_CLIMATOLOGY",
    "The minimum <<WIND_SPEED>> that is greater than 80 percent of the"
    " <<WIND_SPEED_CLIMATOLOGY>>s.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY eighty percentile rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_CLIMATOLOGY,
    "WIND_SPEED_CLIMATOLOGY", "EAC_WIND_SPEED_CLIMATOLOGY",
    "The mean historical (climatology) <<WIND_SPEED>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY mean speed rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_CLIMATOLOGY_STD_DEV,
    "WIND_SPEED_CLIMATOLOGY_STD_DEV", "EAC_WIND_SPEED_CLIMATOLOGY_STD_DEV",
    "The standard deviation of <<WIND_SPEED_CLIMATOLOGY>> measurements.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_DIRECTION_REPORT_COUNT,
    "WIND_SPEED_DIRECTION_REPORT_COUNT", "EAC_WIND_SPEED_DIRECTION_REPORT_COUNT",
    "The number of reports including values for both <<WIND_SPEED>> and"
    " <<WIND_DIRECTION>>; the wind speed and direction report count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_EAST,
    "WIND_SPEED_EAST", "EAC_WIND_SPEED_EAST",
    "The <<WIND_SPEED>> in the geodetic east-west direction, where east is"
    " positive.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_EAST_CLIM_STD_DEV,
    "WIND_SPEED_EAST_CLIM_STD_DEV", "EAC_WIND_SPEED_EAST_CLIM_STD_DEV",
    "The standard deviation of <<WIND_SPEED_EAST_CLIMATOLOGY>> measurements.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY standard deviation east-west wind speed"
    " quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_EAST_CLIMATOLOGY,
    "WIND_SPEED_EAST_CLIMATOLOGY", "EAC_WIND_SPEED_EAST_CLIMATOLOGY",
    "The mean historical (climatology) <<WIND_SPEED_EAST>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_EAST_ERROR,
    "WIND_SPEED_EAST_ERROR", "EAC_WIND_SPEED_EAST_ERROR",
    "The error introduced by uncertainties in a measurement of a"
    " <<WIND_SPEED_EAST>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-ANALYSIS-FORECAST u component error quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_NORTH,
    "WIND_SPEED_NORTH", "EAC_WIND_SPEED_NORTH",
    "The <<WIND_SPEED>> in the geodetic north-south direction, where north"
    " is positive.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_NORTH_CLIM_STD_DEV,
    "WIND_SPEED_NORTH_CLIM_STD_DEV", "EAC_WIND_SPEED_NORTH_CLIM_STD_DEV",
    "The standard deviation of <<WIND_SPEED_NORTH_CLIMATOLOGY>>"
    " measurements.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY standard deviation north-south wind speed"
    " quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_NORTH_CLIMATOLOGY,
    "WIND_SPEED_NORTH_CLIMATOLOGY", "EAC_WIND_SPEED_NORTH_CLIMATOLOGY",
    "The mean historical (climatology) <<WIND_SPEED_NORTH>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_NORTH_ERROR,
    "WIND_SPEED_NORTH_ERROR", "EAC_WIND_SPEED_NORTH_ERROR",
    "The error introduced by uncertainties in a measurement of a"
    " <<WIND_SPEED_NORTH>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-ANALYSIS-FORECAST v component error quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_OCTANT_CLIMATOLOGY,
    "WIND_SPEED_OCTANT_CLIMATOLOGY", "EAC_WIND_SPEED_OCTANT_CLIMATOLOGY",
    "The historical (climatology) <<WIND_SPEED>> categorized by cardinal"
    " vector octant (a 45 arc degree sector centred on a cardinal"
    " direction).",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY mean speed rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_OCTANT_FRACTION,
    "WIND_SPEED_OCTANT_FRACTION", "EAC_WIND_SPEED_OCTANT_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of observations reporting <<WIND_SPEED>>s within a cardinal"
    " vector octant (a 45 arc degree sector centred on a cardinal"
    " <DIRECTION>).",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY direction observation quantity\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_ONLY_COUNT,
    "WIND_SPEED_ONLY_COUNT", "EAC_WIND_SPEED_ONLY_COUNT",
    "The number of reports including values for <<WIND_SPEED>> only; the"
    " wind speed only count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_QUALITY,
    "WIND_SPEED_QUALITY", "EAC_WIND_SPEED_QUALITY",
    "The quality of a <<WIND_SPEED>> measurement.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[9]), 4, &(EDCS_Enumerant_Dictionary[8995]),
    EDCS_REF_TYP_INFORMATIVE, "[QCMO]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_U,
    "WIND_SPEED_U", "EAC_WIND_SPEED_U",
    "The component of <<WIND_SPEED>> in the X <DIRECTION> of a projected"
    " coordinate system, where +X is positive; the wind speed U.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_V,
    "WIND_SPEED_V", "EAC_WIND_SPEED_V",
    "The component of <<WIND_SPEED>> in the Y <DIRECTION> of a projected"
    " coordinate system, where +Y is positive; the wind speed V.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_SPEED_W,
    "WIND_SPEED_W", "EAC_WIND_SPEED_W",
    "The component of <<WIND_SPEED>> in the Z <DIRECTION> (vertical axis)"
    " of the coordinate system of the measurement, where +Z is positive;"
    " the wind speed W.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[NPDM]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_VARIABLE_FRACTION_CLIMATOLOGY,
    "WIND_VARIABLE_FRACTION_CLIMATOLOGY", "EAC_WIND_VARIABLE_FRACTION_CLIMATOLOGY",
    "The fraction of historical (climatology) <<WIND_SPEED>>s of 2,575"
    " metres per second (five knots) or greater.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_VECTOR_SPEED_CLIMATOLOGY,
    "WIND_VECTOR_SPEED_CLIMATOLOGY", "EAC_WIND_VECTOR_SPEED_CLIMATOLOGY",
    "The magnitude of the vector defined by the"
    " <<WIND_SPEED_EAST_CLIMATOLOGY>> and the"
    " <<WIND_SPEED_NORTH_CLIMATOLOGY>>.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[676]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[JMCDM, \"WIND-CLIMATOLOGY vector mean wind velocity rate\"]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_WAVE_DIRECTION,
    "WIND_WAVE_DIRECTION", "EAC_WIND_WAVE_DIRECTION",
    "The <<GEODETIC_AZIMUTH>> of the <DIRECTION> from which <WIND_WAVE>s"
    " are arriving.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[556]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_WAVE_HEIGHT,
    "WIND_WAVE_HEIGHT", "EAC_WIND_WAVE_HEIGHT",
    "The <<HEIGHT>> measured vertically from the trough to the crest of a"
    " <WIND_WAVE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[857]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIND_WAVE_PERIOD,
    "WIND_WAVE_PERIOD", "EAC_WIND_WAVE_PERIOD",
    "The mean <<TIME_QUANTITY>> a complete cycle (usually crest to crest or"
    " trough to trough) of a <WIND_WAVE> takes to pass a given <LOCATION>.",
    EDCS_AVT_REAL, EQC_TIME,
    2, &(EGBindingForEA[1353]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[AGM1, Chapter 1]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WINDOW_MATERIAL_TYPE,
    "WINDOW_MATERIAL_TYPE", "EAC_WINDOW_MATERIAL_TYPE",
    "The type of <MATERIAL> filling the <APERTURE> of a <WINDOW>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 11, &(EDCS_Enumerant_Dictionary[8999]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WINTER_CANOPY_COVER_FRACTION,
    "WINTER_CANOPY_COVER_FRACTION", "EAC_WINTER_CANOPY_COVER_FRACTION",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fractional canopy cover of <TREE>s during the winter within a"
    " delineated <REGION> of <LAND>. Zero means no cover and one means"
    " completely covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[1223]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WTR]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIRE_COUNT,
    "WIRE_COUNT", "EAC_WIRE_COUNT",
    "The number of <WIRE>s associated with a <STRUCTURE> (for example: a"
    " <POWER_TRANSMISSION_LINE> and/or a <POWER_TRANSMISSION_LINE_PYLON>);"
    " the wire count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[43]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIRE_MESH_COVERED,
    "WIRE_MESH_COVERED", "EAC_WIRE_MESH_COVERED",
    "An indication that an <APERTURE> is covered with a mesh of <WIRE>s;"
    " wire mesh covered.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[43]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WIRE_STRAND_COUNT,
    "WIRE_STRAND_COUNT", "EAC_WIRE_STRAND_COUNT",
    "The number of strands comprising a <WIRE_OBSTACLE>; the wire strand"
    " count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[49]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WMO_STATION_IDENTIFIER,
    "WMO_STATION_IDENTIFIER", "EAC_WMO_STATION_IDENTIFIER",
    "The WMO identifier number for a <WEATHER_STATION>; formatted in a"
    " Basic Latin string as specified by [WMO9A, \"Record Layout of the"
    " Station Data File\", field 5].",
    EDCS_AVT_CONSTRAINED_STRING, 0,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[WMO9A]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WOODY_VEGETATION_DENSITY,
    "WOODY_VEGETATION_DENSITY", "EAC_WOODY_VEGETATION_DENSITY",
    "A number between 0 and 1 inclusive representing the linearly-scaled"
    " fraction of the <TERRAIN> that is covered by woody <VEGETATION>"
    " within a delineated <TRACT>; the woody vegetation density. Zero means"
    " no woody <VEGETATION> is present and one means the <TRACT> is"
    " completely covered.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    4, &(EGBindingForEA[1223]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: DRW]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WORK_IN_PROGRESS_TYPE,
    "WORK_IN_PROGRESS_TYPE", "EAC_WORK_IN_PROGRESS_TYPE",
    "The type of work in progress.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1122]), 2, &(EDCS_Enumerant_Dictionary[9010]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: WPC]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_WORSHIP_PLACE_TYPE,
    "WORSHIP_PLACE_TYPE", "EAC_WORSHIP_PLACE_TYPE",
    "The type of a <WORSHIP_PLACE>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 21, &(EDCS_Enumerant_Dictionary[9012]),
    EDCS_REF_TYP_INFORMATIVE, "[FACC, Annex B: HWT]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_YAW_ANGLE,
    "YAW_ANGLE", "EAC_YAW_ANGLE",
    "The angular distance measured in the local horizontal plane about the"
    " local vertical axis from planetary geodetic north counter clockwise"
    " (viewed from above) to the forward axis of an <OBJECT>; the yaw"
    " angle. The forward axis of the <OBJECT> is the axis that passes"
    " through the <OBJECT> centre and is directed towards the forward part"
    " or <SURFACE> (front) of the <OBJECT>.",
    EDCS_AVT_REAL, EQC_PLANE_ANGLE,
    2, &(EGBindingForEA[88]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_YEAR_COMMON_ERA,
    "YEAR_COMMON_ERA", "EAC_YEAR_COMMON_ERA",
    "The<<TIME_QUANTITY>> as measured by the Gregorian calendar in whole"
    " years since the beginning of the Common Era.",
    EDCS_AVT_INTEGER, 0,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_ZOROASTRIANISM_DENOMINATIONAL_FAMILY,
    "ZOROASTRIANISM_DENOMINATIONAL_FAMILY", "EAC_ZOROASTRIANISM_DENOMINATIONAL_FAMILY",
    "The designation of a <NON_EMPTY_SET> of closely related Zoroastrian"
    " religious denominations, often ones which were at one time part of a"
    " single movement but are now separate religious denominations; the"
    " Zoroastrianism denominational family.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[40]), 1, &(EDCS_Enumerant_Dictionary[9033]),
    EDCS_REF_TYP_INFORMATIVE, "[WCE]",
    "", EDCS_CONCEPT_STAT_ISO },

    {EAC_BREACHED,
    "BREACHED", "EAC_BREACHED",
    "Indication that a physical <OBJECT> is breached [SOED, \"breach\", B].",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_BUOYANT,
    "BUOYANT", "EAC_BUOYANT",
    "Indication that a physical <OBJECT> is buoyant [SOED, \"buoyant\"].",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_DOOR_SHAPE,
    "DOOR_SHAPE", "EAC_DOOR_SHAPE",
    "The shape of a <DOOR>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 2, &(EDCS_Enumerant_Dictionary[9034]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_ELEVATED_EM_DUCT_BOTTOM,
    "ELEVATED_EM_DUCT_BOTTOM", "EAC_ELEVATED_EM_DUCT_BOTTOM",
    "The vertical displacement of the bottom of an <ELEVATED_EM_DUCT> from"
    " a <SURFACE_DATUM> identified by an <<ATM_VERTICAL_REFERENCE>>; the"
    " elevated duct layer bottom.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[611]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HITN]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_ELEVATED_EM_DUCT_TOP,
    "ELEVATED_EM_DUCT_TOP", "EAC_ELEVATED_EM_DUCT_TOP",
    "The vertical displacement of the top of an <ELEVATED_EM_DUCT> from a"
    " <SURFACE_DATUM> identified by an <<ATM_VERTICAL_REFERENCE>>; the"
    " elevated duct layer top.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[611]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HITN]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_ELEVATED_EM_DUCT_STRENGTH,
    "ELEVATED_EM_DUCT_STRENGTH", "EAC_ELEVATED_EM_DUCT_STRENGTH",
    "The strength of an <ELEVATED_EM_DUCT> as defined by the difference"
    " between the maximum and minimum <<RF_REFRACTIVE_INDEX_MODIFIED>> of"
    " the duct layer.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[605]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[HITN]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_ENCLOSURE_MEAN_HEIGHT,
    "ENCLOSURE_MEAN_HEIGHT", "EAC_ENCLOSURE_MEAN_HEIGHT",
    "The mean vertical distance from <FLOOR> to <ROOM_CEILING> of a"
    " compartment in a <BUILDING> (for example: a <ROOM> or a"
    " <FLOOR_CRAWL_SPACE>); the enclosure mean height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[696]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_FORDABLE,
    "FORDABLE", "EAC_FORDABLE",
    "Indication that a <WATERBODY> is fordable.",
    EDCS_AVT_BOOLEAN, 0,
    3, &(EGBindingForEA[1171]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_INTERNALLY_HEATED,
    "INTERNALLY_HEATED", "EAC_INTERNALLY_HEATED",
    "Indication that the <<TEMPERATURE>> of a <MAN_MADE_OBJECT> is being"
    " influenced by an internal heat source.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[47]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_SECCHI_DEPTH,
    "SECCHI_DEPTH", "EAC_SECCHI_DEPTH",
    "The <<DEPTH_BELOW_WATERBODY_SURFACE>> at which a <SECCHI_DISK>"
    " disappears from view for an observer located above the"
    " <WATERBODY_SURFACE>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[1077]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SECCHI]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_POTENTIAL_TEMPERATURE_BASE_INVERSION_LAYER,
    "POTENTIAL_TEMPERATURE_BASE_INVERSION_LAYER", "EAC_POTENTIAL_TEMPERATURE_BASE_INVERSION_LAYER",
    "The vertical distance to the base of a"
    " <POTENTIAL_TEMPERATURE_INVERSION_LAYER> from a reference <SURFACE>"
    " identified by an <<ATM_VERTICAL_REFERENCE>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[662]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[PLKEMMM]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_POTENTIAL_TEMPERATURE_TOP_INVERSION_LAYER,
    "POTENTIAL_TEMPERATURE_TOP_INVERSION_LAYER", "EAC_POTENTIAL_TEMPERATURE_TOP_INVERSION_LAYER",
    "The vertical distance to the top of a"
    " <POTENTIAL_TEMPERATURE_INVERSION_LAYER> from a reference <SURFACE>"
    " identified by an <<ATM_VERTICAL_REFERENCE>>.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[662]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[PLKEMMM]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_POTENTIAL_TEMP_INVRSN_LAYER_LAPSE_RATE,
    "POTENTIAL_TEMP_INVRSN_LAYER_LAPSE_RATE", "EAC_POTENTIAL_TEMP_INVRSN_LAYER_LAPSE_RATE",
    "The <<POTENTIAL_TEMPERATURE_LAPSE_RATE>> in a"
    " <POTENTIAL_TEMPERATURE_INVERSION_LAYER>.",
    EDCS_AVT_REAL, EQC_LINEIC_THERMO_TEMP_GRADIENT,
    2, &(EGBindingForEA[687]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[PLKEMMM]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_POTENTIAL_TEMPERATURE_LAPSE_RATE,
    "POTENTIAL_TEMPERATURE_LAPSE_RATE", "EAC_POTENTIAL_TEMPERATURE_LAPSE_RATE",
    "The rate of change of the <<POTENTIAL_AIR_TEMPERATURE>> as a function"
    " of <<HEIGHT_AGL>>.",
    EDCS_AVT_REAL, EQC_LINEIC_THERMO_TEMP_GRADIENT,
    3, &(EGBindingForEA[684]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[PLKEMMM]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_PRANDTL_NUMBER,
    "PRANDTL_NUMBER", "EAC_PRANDTL_NUMBER",
    "The non-dimensional ratio of the kinematic viscosity to the thermal"
    " diffusivity, usually about 1 for the atmosphere and about 7 for"
    " water; the Prandtl number.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[956]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[KUNDUFM]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_FROUDE_NUMBER_TYPE_1,
    "FROUDE_NUMBER_TYPE_1", "EAC_FROUDE_NUMBER_TYPE_1",
    "The non-dimensional ratio of the internal force to the force of"
    " gravity for fluid flow given by the ratio of the fluid velocity to"
    " the square root of the product of gravitational acceleration and the"
    " characteristic length; Froude number type 1.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[956]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[YIH]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_FROUDE_NUMBER_TYPE_2,
    "FROUDE_NUMBER_TYPE_2", "EAC_FROUDE_NUMBER_TYPE_2",
    "The non-dimensional ratio of the internal force to the force of"
    " gravity for fluid flow. It is equal to the square of"
    " <<FROUDE_NUMBER_TYPE_1>>; Froude number type 2.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[956]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"Froude Number(Fr)\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_INTERNAL_FROUDE_NUMBER_ATM,
    "INTERNAL_FROUDE_NUMBER_ATM", "EAC_INTERNAL_FROUDE_NUMBER_ATM",
    "A modified Froude number used for atmospheric flows over <HILL>s or"
    " other obstacles given by the non-dimensional ratio of the fluid speed"
    " to the product of Brunt-Vaisala frequency and a characteristic"
    " length; internal Froude number atmospheric.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[956]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"Froude Number\", #2]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_RICHARDSON_NUMBER,
    "RICHARDSON_NUMBER", "EAC_RICHARDSON_NUMBER",
    "A non-dimensional number arising from the study of shearing flows of a"
    " stratified fluid defined as the product of the acceleration of"
    " gravity and a measure of the vertical stability, divided by the"
    " square of the vertical shear; Richardson number.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[956]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"Richardson number\"]",
    "[GMET, \"Richardson number\"]", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_GRADIENT_RICHARDSON_NUMBER,
    "GRADIENT_RICHARDSON_NUMBER", "EAC_GRADIENT_RICHARDSON_NUMBER",
    "A form of the <<RICHARDSON_NUMBER>> expressed using gradients.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[956]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"Gradient Richardson number\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_BULK_RICHARDSON_NUMBER,
    "BULK_RICHARDSON_NUMBER", "EAC_BULK_RICHARDSON_NUMBER",
    "An estimate of the <<GRADIENT_RICHARDSON_NUMBER>> formed by"
    " approximating local gradients by finite difference across layers;"
    " bulk Richardson number.",
    EDCS_AVT_REAL, EQC_PURE_NUMBER,
    2, &(EGBindingForEA[956]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"Bulk Richardson number\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_AERODYNAMIC_ROUGHNESS_LENGTH,
    "AERODYNAMIC_ROUGHNESS_LENGTH", "EAC_AERODYNAMIC_ROUGHNESS_LENGTH",
    "The height above the displacement plane at which the"
    " <<MEAN_WIND_SPEED>> becomes zero when extrapolating the logarithmic"
    " wind-speed profile downward through the atmospheric surface layer;"
    " aerodynamic roughness length.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[9]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[GMET, \"aerodynamic roughness length\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_ACTIVE_DURATION,
    "ACTIVE_DURATION", "EAC_ACTIVE_DURATION",
    "The <<TIME_QUANTITY>> that an <OBJECT> (e.g. a <MINEFIELD> or"
    " <STREET_LAMP>) is active; active duration.",
    EDCS_AVT_REAL, EQC_TIME,
    1, &(EGBindingForEA[48]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_AIR_SOUND_SPEED,
    "AIR_SOUND_SPEED", "EAC_AIR_SOUND_SPEED",
    "The <<SOUND_SPEED>> in <AIR>.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[222]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "",
    "[WMO182]", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_BREACH_MARKED,
    "BREACH_MARKED", "EAC_BREACH_MARKED",
    "Indication that a <BREACH> has been marked.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[34]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_BRIDGE_SPAN_TRANSPORT_VEHICLE_TYPE,
    "BRIDGE_SPAN_TRANSPORT_VEHICLE_TYPE", "EAC_BRIDGE_SPAN_TRANSPORT_VEHICLE_TYPE",
    "A <GROUND_VEHICLE> that has the capability to transport a"
    " <BRIDGE_SPAN>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 5, &(EDCS_Enumerant_Dictionary[9036]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "[JMVL]", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_PLATOON_ACCOMMODATION_AVAILABILITY_COUNT,
    "PLATOON_ACCOMMODATION_AVAILABILITY_COUNT", "EAC_PLATOON_ACCOMMODATION_AVAILABILITY_COUNT",
    "The number of platoons with associated <EQUIPMENT> that can added to a"
    " <DEFENSIVE_POSITION> at the current time. This is equal to the"
    " <<PLATOON_ACCOMODATION_CAPACITY>> of the <DEFENSIVE_POSITION> minus"
    " the number of platoons that are currently in the"
    " <DEFENSIVE_POSITION>; platoon accomodation availability count.",
    EDCS_AVT_COUNT, 0,
    1, &(EGBindingForEA[34]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_FIGHTING_POSITION_TYPE,
    "FIGHTING_POSITION_TYPE", "EAC_FIGHTING_POSITION_TYPE",
    "Defines a <FIGHTING_POSITION> as primary, alternate, or supplementary.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[34]), 3, &(EDCS_Enumerant_Dictionary[9041]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_SECURITY_SYSTEM_TYPE,
    "SECURITY_SYSTEM_TYPE", "EAC_SECURITY_SYSTEM_TYPE",
    "The type of <SENSOR>s in a security system.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[14]), 8, &(EDCS_Enumerant_Dictionary[9044]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_SOUND_SPEED,
    "SOUND_SPEED", "EAC_SOUND_SPEED",
    "The <<SPEED>> at which sound passes through a medium, depending on the"
    " <<TEMPERATURE>> and other properties of the medium; sound speed.",
    EDCS_AVT_REAL, EQC_SPEED,
    2, &(EGBindingForEA[289]), 0, NULL,
    EDCS_REF_TYP_PRESCRIPTIVE, "[WMO182, \"sound velocity\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_WALL_CONSTRUCTION_TYPE,
    "WALL_CONSTRUCTION_TYPE", "EAC_WALL_CONSTRUCTION_TYPE",
    "The type of <MATERIAL> and/or techniques used to construct a <WALL>;"
    " wall construction type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[709]), 14, &(EDCS_Enumerant_Dictionary[9052]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_ANCHORED,
    "ANCHORED", "EAC_ANCHORED",
    "Indication that a physical <OBJECT> is anchored, sometimes by use of"
    " an <ANCHOR>.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[0]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_FORCE_IDENTIFIER,
    "FORCE_IDENTIFIER", "EAC_FORCE_IDENTIFIER",
    "A textual identifier for a military or civilian force, e.g. platoon,"
    " squadron, disorderly crowd, emergency services unit, police; force"
    " identifier.",
    EDCS_AVT_STRING, 0,
    1, &(EGBindingForEA[34]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_BUS_STOP_TYPE,
    "BUS_STOP_TYPE", "EAC_BUS_STOP_TYPE",
    "The type of a <BUS_STOP>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[1146]), 2, &(EDCS_Enumerant_Dictionary[9066]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_CORRUGATION_DEPTH,
    "CORRUGATION_DEPTH", "EAC_CORRUGATION_DEPTH",
    "The vertical distance from crest top to trough bottom of a corrugated"
    " <SURFACE>; corrugation depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[15]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_CORRUGATION_PITCH,
    "CORRUGATION_PITCH", "EAC_CORRUGATION_PITCH",
    "The <<WIDTH>> of one period of the corrugation wave in a corrugated"
    " <SURFACE>; corrugation pitch.",
    EDCS_AVT_REAL, EQC_LENGTH,
    1, &(EGBindingForEA[15]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_CURB_HEIGHT,
    "CURB_HEIGHT", "EAC_CURB_HEIGHT",
    "The vertical distance from the top of the <CURB> to the <SURFACE> of a"
    " <LAND_TRANSPORTATION_ROUTE>; curb height.",
    EDCS_AVT_REAL, EQC_LENGTH,
    3, &(EGBindingForEA[822]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_CURB_TYPE,
    "CURB_TYPE", "EAC_CURB_TYPE",
    "The type of a <CURB>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1163]), 4, &(EDCS_Enumerant_Dictionary[9068]),
    EDCS_REF_TYP_INFORMATIVE, "[PLAX]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_INTERIOR_WINDOW_COVERING,
    "INTERIOR_WINDOW_COVERING", "EAC_INTERIOR_WINDOW_COVERING",
    "The type of the internal covering of a <WINDOW>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 1, &(EDCS_Enumerant_Dictionary[9072]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_MAILBOX_TYPE,
    "MAILBOX_TYPE", "EAC_MAILBOX_TYPE",
    "The type of a <MAILBOX>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[745]), 3, &(EDCS_Enumerant_Dictionary[9073]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_METERED_PARKING,
    "METERED_PARKING", "EAC_METERED_PARKING",
    "An indication that parking spaces in the designated <TRACT> have"
    " <PARKING_METER>s; metered parking.",
    EDCS_AVT_BOOLEAN, 0,
    2, &(EGBindingForEA[1163]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_PIPE_CONSTRUCTION_MATERIAL_TYPE,
    "PIPE_CONSTRUCTION_MATERIAL_TYPE", "EAC_PIPE_CONSTRUCTION_MATERIAL_TYPE",
    "The type of <MATERIAL> used to construct a <PIPE>.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[1127]), 4, &(EDCS_Enumerant_Dictionary[9076]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_REINFORCED,
    "REINFORCED", "EAC_REINFORCED",
    "An indication that a <STRUCTURE> is reinforced for support.",
    EDCS_AVT_BOOLEAN, 0,
    1, &(EGBindingForEA[43]), 0, NULL,
    EDCS_REF_TYP_INFORMATIVE, "[SOED, \"reinforce\", verb, 1]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_ROAD_ILLUMINATED_WIDTH,
    "ROAD_ILLUMINATED_WIDTH", "EAC_ROAD_ILLUMINATED_WIDTH",
    "That portion of the <<WIDTH>> of a <ROAD> that is illuminated.",
    EDCS_AVT_REAL, EQC_LENGTH,
    4, &(EGBindingForEA[818]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_ROOM_CEILING_SHAPE,
    "ROOM_CEILING_SHAPE", "EAC_ROOM_CEILING_SHAPE",
    "The shape of a <ROOM_CEILING>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 2, &(EDCS_Enumerant_Dictionary[9080]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_SEWER_TYPE,
    "SEWER_TYPE", "EAC_SEWER_TYPE",
    "The type of a <SEWER>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[26]), 3, &(EDCS_Enumerant_Dictionary[9082]),
    EDCS_REF_TYP_INFORMATIVE, "[DES, \"sewer\"]",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_WALL_STUD_DEPTH,
    "WALL_STUD_DEPTH", "EAC_WALL_STUD_DEPTH",
    "The dimension of the cross-section of a <WALL_STUD> that is"
    " perpendicular to the <SURFACE> of the associated <WALL>; wall stud"
    " depth.",
    EDCS_AVT_REAL, EQC_LENGTH,
    2, &(EGBindingForEA[850]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_TENSILE_STRENGTH,
    "TENSILE_STRENGTH", "EAC_TENSILE_STRENGTH",
    "The maximum sustainable stress in a <MATERIAL> under elongation"
    " stress; tensile strength [SOED, \"tensile strength\"].",
    EDCS_AVT_REAL, EQC_MOMENTUM,
    1, &(EGBindingForEA[33]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_TOP_FLOOR_LEVEL_IDENTIFIER,
    "TOP_FLOOR_LEVEL_IDENTIFIER", "EAC_TOP_FLOOR_LEVEL_IDENTIFIER",
    "The <<FLOOR_LEVEL_IDENTIFIER>> of the top <FLOOR_LEVEL> of a"
    " <BUILDING>, where top <FLOOR_LEVEL> excludes the <ROOF> unless a"
    " penthouse is situated on the <ROOF>.",
    EDCS_AVT_INDEX, 0,
    2, &(EGBindingForEA[698]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_TRAFFIC_LIGHT_MOUNT_TYPE,
    "TRAFFIC_LIGHT_MOUNT_TYPE", "EAC_TRAFFIC_LIGHT_MOUNT_TYPE",
    "The method by which a <TRAFFIC_LIGHT> is mounted to a"
    " <TRAFFIC_LIGHT_POLE>; traffic light mount type.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[787]), 4, &(EDCS_Enumerant_Dictionary[9085]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_TRAFFIC_LIGHT_TYPE,
    "TRAFFIC_LIGHT_TYPE", "EAC_TRAFFIC_LIGHT_TYPE",
    "The type of a <TRAFFIC_LIGHT>.",
    EDCS_AVT_ENUMERATION, 0,
    3, &(EGBindingForEA[782]), 4, &(EDCS_Enumerant_Dictionary[9089]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_VEHICULAR_MINIMUM_SPEED_LIMIT,
    "VEHICULAR_MINIMUM_SPEED_LIMIT", "EAC_VEHICULAR_MINIMUM_SPEED_LIMIT",
    "The minimum <<SPEED>> legally permitted on a given stretch of a"
    " <TRANSPORTATION_ROUTE>; the vehicular minimum speed limit.",
    EDCS_AVT_REAL, EQC_SPEED,
    3, &(EGBindingForEA[1156]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_WINDOW_TYPE,
    "WINDOW_TYPE", "EAC_WINDOW_TYPE",
    "The type of a <WINDOW> based on the manner in which it operates.",
    EDCS_AVT_ENUMERATION, 0,
    2, &(EGBindingForEA[705]), 7, &(EDCS_Enumerant_Dictionary[9093]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_BALCONY_CONFIGURATION,
    "BALCONY_CONFIGURATION", "EAC_BALCONY_CONFIGURATION",
    "The configuration of a <BALCONY>.",
    EDCS_AVT_ENUMERATION, 0,
    1, &(EGBindingForEA[10]), 2, &(EDCS_Enumerant_Dictionary[9100]),
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY },

    {EAC_BOTTOM_FLOOR_LEVEL_IDENTIFIER,
    "BOTTOM_FLOOR_LEVEL_IDENTIFIER", "EAC_BOTTOM_FLOOR_LEVEL_IDENTIFIER",
    "The <<FLOOR_LEVEL_IDENTIFIER>> of the bottom <FLOOR_LEVEL> of a"
    " <BUILDING>, where bottom <FLOOR_LEVEL> includes any <BASEMENT>s"
    " and/or <PARKING_GARAGE>s.",
    EDCS_AVT_INDEX, 0,
    2, &(EGBindingForEA[698]), 0, NULL,
    EDCS_REF_TYP_NOT_APPLICABLE, "",
    "", EDCS_CONCEPT_STAT_REGISTRY }

}; /* EDCS_Attribute_Dictionary */

/*
 * STRUCT: EDCS_Attribute_Label_Entry
 *
 *  Used within this file for the label lookup table.
 */
typedef struct
{
    EDCS_Attribute_Code  code;
    EDCS_Attribute_Label label;
} EDCS_Attribute_Label_Entry;

static const EDCS_Attribute_Label_Entry
EDCS_Attribute_Labels[] =
{
    {EAC_ABSOLUTE_ELEVATION_ACCURACY, "ABSOLUTE_ELEVATION_ACCURACY"},

    {EAC_ABSOLUTE_HORIZONTAL_ACCURACY, "ABSOLUTE_HORIZONTAL_ACCURACY"},

    {EAC_ABSOLUTE_HUMIDITY, "ABSOLUTE_HUMIDITY"},

    {EAC_ABSOLUTE_LATITUDE_ACCURACY, "ABSOLUTE_LATITUDE_ACCURACY"},

    {EAC_ABSOLUTE_LONGITUDE_ACCURACY, "ABSOLUTE_LONGITUDE_ACCURACY"},

    {EAC_ABSOLUTE_VERTICAL_ACCURACY, "ABSOLUTE_VERTICAL_ACCURACY"},

    {EAC_ACCESS_DIRECTION_TYPE, "ACCESS_DIRECTION_TYPE"},

    {EAC_ACCESSIBILITY_STATUS, "ACCESSIBILITY_STATUS"},

    {EAC_ACCUM_PRECIP, "ACCUM_PRECIP"},

    {EAC_ACCUM_PRECIP_24_HOUR, "ACCUM_PRECIP_24_HOUR"},

    {EAC_ACCUM_PRECIP_24_HOUR_DENSITY, "ACCUM_PRECIP_24_HOUR_DENSITY"},

    {EAC_ACCUM_PRECIP_3_HOUR, "ACCUM_PRECIP_3_HOUR"},

    {EAC_ACCUM_PRECIP_3_HOUR_DENSITY, "ACCUM_PRECIP_3_HOUR_DENSITY"},

    {EAC_ACCUM_PRECIP_6_HOUR, "ACCUM_PRECIP_6_HOUR"},

    {EAC_ACCUM_PRECIP_6_HOUR_DENSITY, "ACCUM_PRECIP_6_HOUR_DENSITY"},

    {EAC_ACCUM_PRECIP_DENSITY, "ACCUM_PRECIP_DENSITY"},

    {EAC_ACCUMULATION_PERIOD, "ACCUMULATION_PERIOD"},

    {EAC_ACCUMULATION_PERIOD_CATEGORY, "ACCUMULATION_PERIOD_CATEGORY"},

    {EAC_ACOUSTIC_BOUNDARY_LOSS, "ACOUSTIC_BOUNDARY_LOSS"},

    {EAC_ACOUSTIC_CENTRE_FREQUENCY_BAND, "ACOUSTIC_CENTRE_FREQUENCY_BAND"},

    {EAC_ACOUSTIC_HALFCHANNEL_OBSERVATION_FRACTION, "ACOUSTIC_HALFCHANNEL_OBSERVATION_FRACTION"},

    {EAC_ACOUSTIC_NOISE_MARGINAL_ICE_ZONE_MULTIPLIER, "ACOUSTIC_NOISE_MARGINAL_ICE_ZONE_MULTIPLIER"},

    {EAC_ACOUSTIC_NOISE_SPECTRAL_CURVE_CORRECTION, "ACOUSTIC_NOISE_SPECTRAL_CURVE_CORRECTION"},

    {EAC_ACOUSTIC_PWR_LVL_BAND, "ACOUSTIC_PWR_LVL_BAND"},

    {EAC_ACOUSTIC_PWR_LVL_SPECTRUM, "ACOUSTIC_PWR_LVL_SPECTRUM"},

    {EAC_ACOUSTIC_PWR_LVL_SPECTRUM_CORRECTION, "ACOUSTIC_PWR_LVL_SPECTRUM_CORRECTION"},

    {EAC_ACOUSTIC_REFLECTION_TYPE, "ACOUSTIC_REFLECTION_TYPE"},

    {EAC_ACOUSTIC_REFLECTOR, "ACOUSTIC_REFLECTOR"},

    {EAC_ACOUSTIC_SCATTERING_STRENGTH, "ACOUSTIC_SCATTERING_STRENGTH"},

    {EAC_ACOUSTIC_TARGET_STRENGTH, "ACOUSTIC_TARGET_STRENGTH"},

    {EAC_ACOUSTIC_TRANSMISSION_LOSS, "ACOUSTIC_TRANSMISSION_LOSS"},

    {EAC_ACOUSTIC_VOLUME_LAYER_SCATTERING_STRENGTH_FREQUENCY, "ACOUSTIC_VOLUME_LAYER_SCATTERING_STRENGTH_FREQUENCY"},

    {EAC_ACTIVE_ACOUSTIC, "ACTIVE_ACOUSTIC"},

    {EAC_ACTIVE_DURATION, "ACTIVE_DURATION"},

    {EAC_AERIAL_COUNT, "AERIAL_COUNT"},

    {EAC_AERIAL_FUNCTION, "AERIAL_FUNCTION"},

    {EAC_AERIAL_TYPE, "AERIAL_TYPE"},

    {EAC_AERODROME_ELEVATION, "AERODROME_ELEVATION"},

    {EAC_AERODROME_EMERGENCY_LIGHTING_INTENSITY, "AERODROME_EMERGENCY_LIGHTING_INTENSITY"},

    {EAC_AERODROME_GATE_LIGHTING_INTENSITY, "AERODROME_GATE_LIGHTING_INTENSITY"},

    {EAC_AERODROME_IDENTIFICATION, "AERODROME_IDENTIFICATION"},

    {EAC_AERODROME_TYPE, "AERODROME_TYPE"},

    {EAC_AERODYNAMIC_ROUGHNESS_LENGTH, "AERODYNAMIC_ROUGHNESS_LENGTH"},

    {EAC_AERONAUTICAL_APPROACH_TYPE, "AERONAUTICAL_APPROACH_TYPE"},

    {EAC_AERONAUTICAL_FUNCTION, "AERONAUTICAL_FUNCTION"},

    {EAC_AERONAUTICAL_LIGHT_TYPE, "AERONAUTICAL_LIGHT_TYPE"},

    {EAC_AERONAUTICAL_OBSTRUCTION_HEIGHT_ACCURACY, "AERONAUTICAL_OBSTRUCTION_HEIGHT_ACCURACY"},

    {EAC_AERONAUTICAL_POINT_FUNCTION, "AERONAUTICAL_POINT_FUNCTION"},

    {EAC_AERONAUTICAL_ROUTE_TYPE, "AERONAUTICAL_ROUTE_TYPE"},

    {EAC_AEROSOL_LAYER_BASE_LEVEL, "AEROSOL_LAYER_BASE_LEVEL"},

    {EAC_AEROSOL_LAYER_TOP_LEVEL, "AEROSOL_LAYER_TOP_LEVEL"},

    {EAC_AEROSOL_PARTICLE_CONCENTRATION, "AEROSOL_PARTICLE_CONCENTRATION"},

    {EAC_AEROSOL_PARTICLE_TYPE, "AEROSOL_PARTICLE_TYPE"},

    {EAC_AFTERBURNER_INDUCED_FLAME_RATE, "AFTERBURNER_INDUCED_FLAME_RATE"},

    {EAC_AID_TO_NAVIGATION_COLOUR_PATTERN, "AID_TO_NAVIGATION_COLOUR_PATTERN"},

    {EAC_AID_TO_NAVIGATION_DESCRIPTION, "AID_TO_NAVIGATION_DESCRIPTION"},

    {EAC_AID_TO_NAVIGATION_EFFECTIVENESS_RADIUS, "AID_TO_NAVIGATION_EFFECTIVENESS_RADIUS"},

    {EAC_AID_TO_NAVIGATION_MARK_COLOUR, "AID_TO_NAVIGATION_MARK_COLOUR"},

    {EAC_AID_TO_NAVIGATION_MARK_SYSTEM, "AID_TO_NAVIGATION_MARK_SYSTEM"},

    {EAC_AID_TO_NAVIGATION_MARKER_TYPE, "AID_TO_NAVIGATION_MARKER_TYPE"},

    {EAC_AID_TO_NAVIGATION_PRIMARY_OPERATING_RANGE, "AID_TO_NAVIGATION_PRIMARY_OPERATING_RANGE"},

    {EAC_AID_TO_NAVIGATION_RANGE, "AID_TO_NAVIGATION_RANGE"},

    {EAC_AID_TO_NAVIGATION_SECONDARY_OPERATING_RANGE, "AID_TO_NAVIGATION_SECONDARY_OPERATING_RANGE"},

    {EAC_AID_TO_NAVIGATION_STATUS, "AID_TO_NAVIGATION_STATUS"},

    {EAC_AID_TO_NAVIGATION_SYSTEM_TYPE, "AID_TO_NAVIGATION_SYSTEM_TYPE"},

    {EAC_AIR_DENSITY, "AIR_DENSITY"},

    {EAC_AIR_EXFILTRATION_RATE, "AIR_EXFILTRATION_RATE"},

    {EAC_AIR_INFILTRATION_RATE, "AIR_INFILTRATION_RATE"},

    {EAC_AIR_SOUND_SPEED, "AIR_SOUND_SPEED"},

    {EAC_AIR_TEMPERATURE, "AIR_TEMPERATURE"},

    {EAC_AIR_TEMPERATURE_ERROR, "AIR_TEMPERATURE_ERROR"},

    {EAC_AIR_TEMPERATURE_PERIOD, "AIR_TEMPERATURE_PERIOD"},

    {EAC_AIRCRAFT_CARRIER_CLASS, "AIRCRAFT_CARRIER_CLASS"},

    {EAC_AIRCRAFT_FUNCTION, "AIRCRAFT_FUNCTION"},

    {EAC_AIRCRAFT_ICING_INTENSITY, "AIRCRAFT_ICING_INTENSITY"},

    {EAC_AIRCRAFT_ICING_LEVEL_BASE_ALTITUDE, "AIRCRAFT_ICING_LEVEL_BASE_ALTITUDE"},

    {EAC_AIRCRAFT_ICING_LEVEL_TOP_ALTITUDE, "AIRCRAFT_ICING_LEVEL_TOP_ALTITUDE"},

    {EAC_AIRCRAFT_ICING_TYPE, "AIRCRAFT_ICING_TYPE"},

    {EAC_AIRCRAFT_LANDING_GEAR_DEPLOYED_POSITION, "AIRCRAFT_LANDING_GEAR_DEPLOYED_POSITION"},

    {EAC_AIRCRAFT_LOAD_RESTRICTIONS, "AIRCRAFT_LOAD_RESTRICTIONS"},

    {EAC_AIRCRAFT_PROPULSION_TYPE, "AIRCRAFT_PROPULSION_TYPE"},

    {EAC_AIRCRAFT_TURBULENCE_BASE_ALTITUDE, "AIRCRAFT_TURBULENCE_BASE_ALTITUDE"},

    {EAC_AIRCRAFT_TURBULENCE_FREQUENCY, "AIRCRAFT_TURBULENCE_FREQUENCY"},

    {EAC_AIRCRAFT_TURBULENCE_INTENSITY, "AIRCRAFT_TURBULENCE_INTENSITY"},

    {EAC_AIRCRAFT_TURBULENCE_TOP_ALTITUDE, "AIRCRAFT_TURBULENCE_TOP_ALTITUDE"},

    {EAC_AIRCRAFT_TYPE, "AIRCRAFT_TYPE"},

    {EAC_AIRSPACE_ALTITUDE_LIMITS, "AIRSPACE_ALTITUDE_LIMITS"},

    {EAC_AIRSPACE_IDENTIFIER, "AIRSPACE_IDENTIFIER"},

    {EAC_AIRSPACE_LIMITATION, "AIRSPACE_LIMITATION"},

    {EAC_AIRSPACE_OPERATING_RESTRICTIONS, "AIRSPACE_OPERATING_RESTRICTIONS"},

    {EAC_AIRSPACE_TYPE, "AIRSPACE_TYPE"},

    {EAC_ALBEDO, "ALBEDO"},

    {EAC_ALL_OBJECT_COUNT, "ALL_OBJECT_COUNT"},

    {EAC_ALONGSHORE_CURRENT_SPEED, "ALONGSHORE_CURRENT_SPEED"},

    {EAC_ALTITUDE_MSL, "ALTITUDE_MSL"},

    {EAC_ANCHORED, "ANCHORED"},

    {EAC_ANGULAR_SECTOR_WIDTH, "ANGULAR_SECTOR_WIDTH"},

    {EAC_ANTI_COLLISION_LIGHT_INTENSITY, "ANTI_COLLISION_LIGHT_INTENSITY"},

    {EAC_APERTURE_COVER_FRACTION, "APERTURE_COVER_FRACTION"},

    {EAC_APERTURE_COVER_POSITION, "APERTURE_COVER_POSITION"},

    {EAC_APERTURE_LENGTH, "APERTURE_LENGTH"},

    {EAC_APERTURE_OPEN, "APERTURE_OPEN"},

    {EAC_APERTURE_STATE, "APERTURE_STATE"},

    {EAC_APERTURE_WIDTH, "APERTURE_WIDTH"},

    {EAC_APRON_HARD_STANDING_FUNCTION, "APRON_HARD_STANDING_FUNCTION"},

    {EAC_AQUEDUCT_TYPE, "AQUEDUCT_TYPE"},

    {EAC_AREA, "AREA"},

    {EAC_ARMOURED, "ARMOURED"},

    {EAC_ARRESTING_GEAR_TYPE, "ARRESTING_GEAR_TYPE"},

    {EAC_ASPECT_ANGLE, "ASPECT_ANGLE"},

    {EAC_ASSAULT_LANDING_CRAFT_TYPE, "ASSAULT_LANDING_CRAFT_TYPE"},

    {EAC_ASSOCIATED_TEXT, "ASSOCIATED_TEXT"},

    {EAC_ASW_CENTROID_PRESENT, "ASW_CENTROID_PRESENT"},

    {EAC_ASW_WINGED_AIRCRAFT_TYPE, "ASW_WINGED_AIRCRAFT_TYPE"},

    {EAC_ATM_BOUNDARY_LAYER_HEIGHT, "ATM_BOUNDARY_LAYER_HEIGHT"},

    {EAC_ATM_CEILING, "ATM_CEILING"},

    {EAC_ATM_CEILING_METHOD, "ATM_CEILING_METHOD"},

    {EAC_ATM_FREEZING_LEVEL, "ATM_FREEZING_LEVEL"},

    {EAC_ATM_LIQUID_WATER_MIXING_RATIO, "ATM_LIQUID_WATER_MIXING_RATIO"},

    {EAC_ATM_PRESSURE, "ATM_PRESSURE"},

    {EAC_ATM_PRESSURE_CHANGE, "ATM_PRESSURE_CHANGE"},

    {EAC_ATM_PRESSURE_CHANGE_24_HOUR, "ATM_PRESSURE_CHANGE_24_HOUR"},

    {EAC_ATM_PRESSURE_CHANGE_3_HOUR, "ATM_PRESSURE_CHANGE_3_HOUR"},

    {EAC_ATM_PRESSURE_CHANGE_QUALITY, "ATM_PRESSURE_CHANGE_QUALITY"},

    {EAC_ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY, "ATM_PRESSURE_CHANGE_TENDENCY_CATEGORY"},

    {EAC_ATM_PRESSURE_MEAN_CLIM, "ATM_PRESSURE_MEAN_CLIM"},

    {EAC_ATM_PRESSURE_MEAN_CLIM_STD_DEV, "ATM_PRESSURE_MEAN_CLIM_STD_DEV"},

    {EAC_ATM_PRESSURE_QUALITY, "ATM_PRESSURE_QUALITY"},

    {EAC_ATM_PRESSURE_REDUCED_CLIM_STD_DEV, "ATM_PRESSURE_REDUCED_CLIM_STD_DEV"},

    {EAC_ATM_PRESSURE_REDUCED_MSL, "ATM_PRESSURE_REDUCED_MSL"},

    {EAC_ATM_PROFILE_MEASUREMENT_TECHNIQUE, "ATM_PROFILE_MEASUREMENT_TECHNIQUE"},

    {EAC_ATM_TURBULENCE_TYPE, "ATM_TURBULENCE_TYPE"},

    {EAC_ATM_VERTICAL_REFERENCE, "ATM_VERTICAL_REFERENCE"},

    {EAC_ATS_ROUTE_COMPONENT_LENGTH, "ATS_ROUTE_COMPONENT_LENGTH"},

    {EAC_ATS_ROUTE_COMPONENT_LEVEL, "ATS_ROUTE_COMPONENT_LEVEL"},

    {EAC_ATS_ROUTE_COMPONENT_WIDTH, "ATS_ROUTE_COMPONENT_WIDTH"},

    {EAC_ATS_ROUTE_LOWEST_ALTITUDE, "ATS_ROUTE_LOWEST_ALTITUDE"},

    {EAC_ATS_ROUTE_OPPOSITE_FLOW_DIRECTION, "ATS_ROUTE_OPPOSITE_FLOW_DIRECTION"},

    {EAC_ATS_ROUTE_TYPE, "ATS_ROUTE_TYPE"},

    {EAC_ATS_USE_TYPE, "ATS_USE_TYPE"},

    {EAC_ATTACHED, "ATTACHED"},

    {EAC_ATTACK_WINGED_AIRCRAFT_TYPE, "ATTACK_WINGED_AIRCRAFT_TYPE"},

    {EAC_AUXILIARY_VESSEL_TYPE, "AUXILIARY_VESSEL_TYPE"},

    {EAC_AVAILABLE_FACILITIES_TYPE, "AVAILABLE_FACILITIES_TYPE"},

    {EAC_AVERAGING_PERIOD, "AVERAGING_PERIOD"},

    {EAC_AVERAGING_PERIOD_CATEGORY, "AVERAGING_PERIOD_CATEGORY"},

    {EAC_AVIATION_LOCATION_ID_VALUE_SET, "AVIATION_LOCATION_ID_VALUE_SET"},

    {EAC_AVIATION_LOCATION_IDENTIFIER, "AVIATION_LOCATION_IDENTIFIER"},

    {EAC_BALCONY_CONFIGURATION, "BALCONY_CONFIGURATION"},

    {EAC_BALCONY_TYPE, "BALCONY_TYPE"},

    {EAC_BALEEN_WHALE_CATCH_PER_YEAR, "BALEEN_WHALE_CATCH_PER_YEAR"},

    {EAC_BARGE_LOAD_RESTRICTIONS, "BARGE_LOAD_RESTRICTIONS"},

    {EAC_BASEMENT_CONSTRUCTION_MATERIAL, "BASEMENT_CONSTRUCTION_MATERIAL"},

    {EAC_BEACH_PORTION, "BEACH_PORTION"},

    {EAC_BEACON_PRESENT, "BEACON_PRESENT"},

    {EAC_BEACON_SECTOR_FIRST_LIMIT, "BEACON_SECTOR_FIRST_LIMIT"},

    {EAC_BEACON_SECTOR_SECOND_LIMIT, "BEACON_SECTOR_SECOND_LIMIT"},

    {EAC_BEARING_AND_RECIPROCAL, "BEARING_AND_RECIPROCAL"},

    {EAC_BEARING_FROM_SEAWARD, "BEARING_FROM_SEAWARD"},

    {EAC_BEAUFORT_WIND_SCALE, "BEAUFORT_WIND_SCALE"},

    {EAC_BEDROCK_SURFACE_COMPRESSIONAL_VELOCITY, "BEDROCK_SURFACE_COMPRESSIONAL_VELOCITY"},

    {EAC_BEDROCK_SURFACE_DENSITY, "BEDROCK_SURFACE_DENSITY"},

    {EAC_BEDROCK_SURFACE_SHEAR_VELOCITY, "BEDROCK_SURFACE_SHEAR_VELOCITY"},

    {EAC_BELOW_STATION_CLOUD_COVERAGE, "BELOW_STATION_CLOUD_COVERAGE"},

    {EAC_BELOW_STATION_CLOUD_TOP_ALTITUDE, "BELOW_STATION_CLOUD_TOP_ALTITUDE"},

    {EAC_BELOW_STATION_CLOUD_TOP_CHARACTERISTICS, "BELOW_STATION_CLOUD_TOP_CHARACTERISTICS"},

    {EAC_BELOW_STATION_CLOUD_TYPE, "BELOW_STATION_CLOUD_TYPE"},

    {EAC_BENCHMARK_TYPE, "BENCHMARK_TYPE"},

    {EAC_BERTH_IDENTIFIER, "BERTH_IDENTIFIER"},

    {EAC_BERTH_TYPE, "BERTH_TYPE"},

    {EAC_BIDIRECTIONAL, "BIDIRECTIONAL"},

    {EAC_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION, "BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION"},

    {EAC_BIOLOGIC_AGENT_ATM_CONCENTRATION, "BIOLOGIC_AGENT_ATM_CONCENTRATION"},

    {EAC_BIOLOGIC_AGENT_SURFACE_CONCENTRATION, "BIOLOGIC_AGENT_SURFACE_CONCENTRATION"},

    {EAC_BIOLOGIC_AGENT_TYPE, "BIOLOGIC_AGENT_TYPE"},

    {EAC_BLACKOUT_BRAKE_LIGHT_INTENSITY, "BLACKOUT_BRAKE_LIGHT_INTENSITY"},

    {EAC_BLACKOUT_LIGHT_INTENSITY, "BLACKOUT_LIGHT_INTENSITY"},

    {EAC_BLOWING_SAND, "BLOWING_SAND"},

    {EAC_BLOWING_SNOW, "BLOWING_SNOW"},

    {EAC_BOMBER_WINGED_AIRCRAFT_TYPE, "BOMBER_WINGED_AIRCRAFT_TYPE"},

    {EAC_BOTTOM_FLOOR_LEVEL_IDENTIFIER, "BOTTOM_FLOOR_LEVEL_IDENTIFIER"},

    {EAC_BOTTOM_RETURN_ALLEGIANCE, "BOTTOM_RETURN_ALLEGIANCE"},

    {EAC_BOTTOM_RETURN_OBSTACLE_STATUS, "BOTTOM_RETURN_OBSTACLE_STATUS"},

    {EAC_BOTTOM_RETURN_ROCK_STATUS, "BOTTOM_RETURN_ROCK_STATUS"},

    {EAC_BOTTOM_RETURN_SEABED_STATUS, "BOTTOM_RETURN_SEABED_STATUS"},

    {EAC_BOTTOM_RETURN_STATUS, "BOTTOM_RETURN_STATUS"},

    {EAC_BOTTOM_RETURN_TRACK_IDENTIFIER, "BOTTOM_RETURN_TRACK_IDENTIFIER"},

    {EAC_BOTTOM_RETURN_TYPE, "BOTTOM_RETURN_TYPE"},

    {EAC_BOTTOM_RETURN_WRECK_STATUS, "BOTTOM_RETURN_WRECK_STATUS"},

    {EAC_BOTTOM_WIDTH, "BOTTOM_WIDTH"},

    {EAC_BOUNDARY_FIRST_SIDE_NAME, "BOUNDARY_FIRST_SIDE_NAME"},

    {EAC_BOUNDARY_SECOND_SIDE_NAME, "BOUNDARY_SECOND_SIDE_NAME"},

    {EAC_BOUNDARY_STATUS, "BOUNDARY_STATUS"},

    {EAC_BOUNDARY_TYPE, "BOUNDARY_TYPE"},

    {EAC_BRANCH_RAILWAY_TYPE, "BRANCH_RAILWAY_TYPE"},

    {EAC_BREACH_MARKED, "BREACH_MARKED"},

    {EAC_BREACHED, "BREACHED"},

    {EAC_BREAKER_FLANK, "BREAKER_FLANK"},

    {EAC_BRIDGE_AND_SPAN_IDENTIFIER, "BRIDGE_AND_SPAN_IDENTIFIER"},

    {EAC_BRIDGE_COMPONENT_TYPE, "BRIDGE_COMPONENT_TYPE"},

    {EAC_BRIDGE_DESIGN, "BRIDGE_DESIGN"},

    {EAC_BRIDGE_FUNCTION, "BRIDGE_FUNCTION"},

    {EAC_BRIDGE_IDENTIFIER, "BRIDGE_IDENTIFIER"},

    {EAC_BRIDGE_INFORMATION_RELIABILITY, "BRIDGE_INFORMATION_RELIABILITY"},

    {EAC_BRIDGE_LEVEL_COUNT, "BRIDGE_LEVEL_COUNT"},

    {EAC_BRIDGE_OPENING_TYPE, "BRIDGE_OPENING_TYPE"},

    {EAC_BRIDGE_SPAN_COUNT, "BRIDGE_SPAN_COUNT"},

    {EAC_BRIDGE_SPAN_MOBILE, "BRIDGE_SPAN_MOBILE"},

    {EAC_BRIDGE_SPAN_TRANSPORT_VEHICLE_TYPE, "BRIDGE_SPAN_TRANSPORT_VEHICLE_TYPE"},

    {EAC_BRIDGE_SPAN_TYPE, "BRIDGE_SPAN_TYPE"},

    {EAC_BRIDGE_STRUCTURE_TYPE, "BRIDGE_STRUCTURE_TYPE"},

    {EAC_BRUSH_DENSITY, "BRUSH_DENSITY"},

    {EAC_BUDDHISM_DENOMINATIONAL_FAMILY, "BUDDHISM_DENOMINATIONAL_FAMILY"},

    {EAC_BUILDING_COMPONENT_TYPE, "BUILDING_COMPONENT_TYPE"},

    {EAC_BUILDING_CONSTRUCTION_TYPE, "BUILDING_CONSTRUCTION_TYPE"},

    {EAC_BUILDING_FOUNDATION_TYPE, "BUILDING_FOUNDATION_TYPE"},

    {EAC_BUILDING_FUNCTION, "BUILDING_FUNCTION"},

    {EAC_BUILT_UP_REGION_DENSITY, "BUILT_UP_REGION_DENSITY"},

    {EAC_BULK_RICHARDSON_NUMBER, "BULK_RICHARDSON_NUMBER"},

    {EAC_BUOY_SHAPE, "BUOY_SHAPE"},

    {EAC_BUOY_TYPE, "BUOY_TYPE"},

    {EAC_BUOYANT, "BUOYANT"},

    {EAC_BUS_STOP_TYPE, "BUS_STOP_TYPE"},

    {EAC_BYPASS_CONDITION, "BYPASS_CONDITION"},

    {EAC_CABLE_TYPE, "CABLE_TYPE"},

    {EAC_CALENDAR_DATE, "CALENDAR_DATE"},

    {EAC_CALM_SEA_STATE_FRACTION, "CALM_SEA_STATE_FRACTION"},

    {EAC_CAMOUFLAGE_TYPE, "CAMOUFLAGE_TYPE"},

    {EAC_CAPACITY, "CAPACITY"},

    {EAC_CASE_BURIAL_FRACTION, "CASE_BURIAL_FRACTION"},

    {EAC_CEILING_AND_VISIBILITY_OK, "CEILING_AND_VISIBILITY_OK"},

    {EAC_CENTRE_FREQUENCY_BAND, "CENTRE_FREQUENCY_BAND"},

    {EAC_CHANGE_POINT_TYPE, "CHANGE_POINT_TYPE"},

    {EAC_CHARACTER_EMITTED, "CHARACTER_EMITTED"},

    {EAC_CHARGED_PARTICLE_SPECIES, "CHARGED_PARTICLE_SPECIES"},

    {EAC_CHEMICAL_AGENT_ATM_CONCENTRATION, "CHEMICAL_AGENT_ATM_CONCENTRATION"},

    {EAC_CHEMICAL_AGENT_SURFACE_CONCENTRATION, "CHEMICAL_AGENT_SURFACE_CONCENTRATION"},

    {EAC_CHEMICAL_AGENT_TYPE, "CHEMICAL_AGENT_TYPE"},

    {EAC_CHRISTIANITY_DENOMINATIONAL_FAMILY, "CHRISTIANITY_DENOMINATIONAL_FAMILY"},

    {EAC_CLASSIFICATION_NAME, "CLASSIFICATION_NAME"},

    {EAC_CLAY_DRAINAGE_PIPES_PRESENT, "CLAY_DRAINAGE_PIPES_PRESENT"},

    {EAC_CLOUD_BASE_LEVEL, "CLOUD_BASE_LEVEL"},

    {EAC_CLOUD_FREE_LINE_OF_SIGHT, "CLOUD_FREE_LINE_OF_SIGHT"},

    {EAC_CLOUD_LIQUID_WATER_CONTENT, "CLOUD_LIQUID_WATER_CONTENT"},

    {EAC_CLOUD_PHASE, "CLOUD_PHASE"},

    {EAC_CLOUD_SKY_COVER_LAYER_TYPE, "CLOUD_SKY_COVER_LAYER_TYPE"},

    {EAC_CLOUD_THICKNESS, "CLOUD_THICKNESS"},

    {EAC_CLOUD_TOP_LEVEL, "CLOUD_TOP_LEVEL"},

    {EAC_CLOUD_TOP_TEMPERATURE, "CLOUD_TOP_TEMPERATURE"},

    {EAC_CLOUD_WATER_MIXING_RATIO, "CLOUD_WATER_MIXING_RATIO"},

    {EAC_COLOUR_INTENSITY, "COLOUR_INTENSITY"},

    {EAC_COLOURATION, "COLOURATION"},

    {EAC_COLOURATION_INFORMATION, "COLOURATION_INFORMATION"},

    {EAC_COMBAT_SUPPORT_VESSEL_FUNCTION, "COMBAT_SUPPORT_VESSEL_FUNCTION"},

    {EAC_COMBATANT_VESSEL_TYPE, "COMBATANT_VESSEL_TYPE"},

    {EAC_COMBUSTION_INDUCED_FLAME_RATE, "COMBUSTION_INDUCED_FLAME_RATE"},

    {EAC_COMBUSTION_STATE, "COMBUSTION_STATE"},

    {EAC_COMMERCIAL_WINGED_AIRCRAFT_TYPE, "COMMERCIAL_WINGED_AIRCRAFT_TYPE"},

    {EAC_COMMUNICATION_CHANNEL, "COMMUNICATION_CHANNEL"},

    {EAC_COMMUNICATION_STRUCTURE_TYPE, "COMMUNICATION_STRUCTURE_TYPE"},

    {EAC_COMPLEX_COMPONENT_IDENTIFIER, "COMPLEX_COMPONENT_IDENTIFIER"},

    {EAC_CONCEALMENT_FRACTION, "CONCEALMENT_FRACTION"},

    {EAC_CONSPICUOUSNESS, "CONSPICUOUSNESS"},

    {EAC_CONSTRUCTION_COMPLETION_FRACTION, "CONSTRUCTION_COMPLETION_FRACTION"},

    {EAC_CONTOUR_TYPE, "CONTOUR_TYPE"},

    {EAC_CONTRAIL_LAYER_BASE_ALTITUDE, "CONTRAIL_LAYER_BASE_ALTITUDE"},

    {EAC_CONTRAIL_LAYER_TOP_ALTITUDE, "CONTRAIL_LAYER_TOP_ALTITUDE"},

    {EAC_CONTRAIL_PERSISTENCE, "CONTRAIL_PERSISTENCE"},

    {EAC_CONTROL_PANEL_STATE, "CONTROL_PANEL_STATE"},

    {EAC_CONTROL_PANEL_TYPE, "CONTROL_PANEL_TYPE"},

    {EAC_CONTROLLED, "CONTROLLED"},

    {EAC_CONTROLLING_AUTHORITY, "CONTROLLING_AUTHORITY"},

    {EAC_CONVECTION_COEFFICIENT, "CONVECTION_COEFFICIENT"},

    {EAC_CONVECTIVE_CLOUD_LAYER, "CONVECTIVE_CLOUD_LAYER"},

    {EAC_CONVECTIVE_PRECIPITATION_DENSITY, "CONVECTIVE_PRECIPITATION_DENSITY"},

    {EAC_CORRUGATION_DEPTH, "CORRUGATION_DEPTH"},

    {EAC_CORRUGATION_PITCH, "CORRUGATION_PITCH"},

    {EAC_COUNT, "COUNT"},

    {EAC_COUNTRY_ID_VALUE_SET, "COUNTRY_ID_VALUE_SET"},

    {EAC_COUNTRY_IDENTIFIER, "COUNTRY_IDENTIFIER"},

    {EAC_COVERED_DRAIN, "COVERED_DRAIN"},

    {EAC_COVERED_DRAIN_LENGTH, "COVERED_DRAIN_LENGTH"},

    {EAC_CRANE_MOBILITY_TYPE, "CRANE_MOBILITY_TYPE"},

    {EAC_CRANE_TYPE, "CRANE_TYPE"},

    {EAC_CRITICAL_LAYER_ALTITUDE_E, "CRITICAL_LAYER_ALTITUDE_E"},

    {EAC_CRITICAL_LAYER_ALTITUDE_F1, "CRITICAL_LAYER_ALTITUDE_F1"},

    {EAC_CRITICAL_LAYER_ALTITUDE_F2, "CRITICAL_LAYER_ALTITUDE_F2"},

    {EAC_CRITICAL_LAYER_FREQUENCY_E, "CRITICAL_LAYER_FREQUENCY_E"},

    {EAC_CRITICAL_LAYER_FREQUENCY_F1, "CRITICAL_LAYER_FREQUENCY_F1"},

    {EAC_CRITICAL_LAYER_FREQUENCY_F2, "CRITICAL_LAYER_FREQUENCY_F2"},

    {EAC_CROSSING_CONTROL, "CROSSING_CONTROL"},

    {EAC_CROWN_DIAMETER, "CROWN_DIAMETER"},

    {EAC_CULTURAL_OBJECT_DENSITY, "CULTURAL_OBJECT_DENSITY"},

    {EAC_CULVERT_TYPE, "CULVERT_TYPE"},

    {EAC_CUMULATIVE_TRACK_LENGTH, "CUMULATIVE_TRACK_LENGTH"},

    {EAC_CURB_HEIGHT, "CURB_HEIGHT"},

    {EAC_CURB_TYPE, "CURB_TYPE"},

    {EAC_CYCLE_DATE, "CYCLE_DATE"},

    {EAC_DAILY_TIDE_INDEX, "DAILY_TIDE_INDEX"},

    {EAC_DAM_FACE_TYPE, "DAM_FACE_TYPE"},

    {EAC_DAMAGE_WEIGHT, "DAMAGE_WEIGHT"},

    {EAC_DATA_COLLECTION_CRITERIA, "DATA_COLLECTION_CRITERIA"},

    {EAC_DATE_FORMAT, "DATE_FORMAT"},

    {EAC_DATE_TIME_FORMAT, "DATE_TIME_FORMAT"},

    {EAC_DATE_TIME_GROUP, "DATE_TIME_GROUP"},

    {EAC_DAY_WITHIN_YEAR, "DAY_WITHIN_YEAR"},

    {EAC_DEEP_SOUND_CHANNEL_AXIS_DEPTH, "DEEP_SOUND_CHANNEL_AXIS_DEPTH"},

    {EAC_DEEP_SOUND_CHANNEL_TOP_DEPTH, "DEEP_SOUND_CHANNEL_TOP_DEPTH"},

    {EAC_DEFENSIVE_POSITION_COUNT, "DEFENSIVE_POSITION_COUNT"},

    {EAC_DEFENSIVE_POSITION_TYPE, "DEFENSIVE_POSITION_TYPE"},

    {EAC_DELINEATION_CERTAIN, "DELINEATION_CERTAIN"},

    {EAC_DENSITY_ALTITUDE, "DENSITY_ALTITUDE"},

    {EAC_DEPTH, "DEPTH"},

    {EAC_DEPTH_BELOW_SURFACE_LEVEL, "DEPTH_BELOW_SURFACE_LEVEL"},

    {EAC_DEPTH_BELOW_WATERBODY_FLOOR, "DEPTH_BELOW_WATERBODY_FLOOR"},

    {EAC_DEPTH_BELOW_WATERBODY_SURFACE, "DEPTH_BELOW_WATERBODY_SURFACE"},

    {EAC_DEPTH_OF_WATERBODY_FLOOR, "DEPTH_OF_WATERBODY_FLOOR"},

    {EAC_DEW_POINT_DEPRESSION, "DEW_POINT_DEPRESSION"},

    {EAC_DEW_POINT_ERROR, "DEW_POINT_ERROR"},

    {EAC_DEW_POINT_MAXIMUM_DIFFERENCE_CLIMATOLOGY, "DEW_POINT_MAXIMUM_DIFFERENCE_CLIMATOLOGY"},

    {EAC_DEW_POINT_MINIMUM_DIFFERENCE_CLIMATOLOGY, "DEW_POINT_MINIMUM_DIFFERENCE_CLIMATOLOGY"},

    {EAC_DEW_POINT_QUALITY, "DEW_POINT_QUALITY"},

    {EAC_DEW_POINT_TEMPERATURE, "DEW_POINT_TEMPERATURE"},

    {EAC_DIR_SHIPPING_NOISE_CORRECTION, "DIR_SHIPPING_NOISE_CORRECTION"},

    {EAC_DIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL, "DIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL"},

    {EAC_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY, "DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY"},

    {EAC_DISPLAY_SIGN_TYPE, "DISPLAY_SIGN_TYPE"},

    {EAC_DISSECTED_TERRAIN, "DISSECTED_TERRAIN"},

    {EAC_DOMINANT_BREAKER_TYPE, "DOMINANT_BREAKER_TYPE"},

    {EAC_DOOR_CONSTRUCTION_TYPE, "DOOR_CONSTRUCTION_TYPE"},

    {EAC_DOOR_OPENING_METHOD, "DOOR_OPENING_METHOD"},

    {EAC_DOOR_SHAPE, "DOOR_SHAPE"},

    {EAC_DOOR_TYPE, "DOOR_TYPE"},

    {EAC_DRAGON_TEETH_TYPE, "DRAGON_TEETH_TYPE"},

    {EAC_DROP_GATE_METHOD, "DROP_GATE_METHOD"},

    {EAC_DUST_PRODUCTION_RATE, "DUST_PRODUCTION_RATE"},

    {EAC_DWELLING_TYPE, "DWELLING_TYPE"},

    {EAC_ECOSYSTEM_TYPE, "ECOSYSTEM_TYPE"},

    {EAC_EDUCATIONAL_BUILDING_TYPE, "EDUCATIONAL_BUILDING_TYPE"},

    {EAC_ELECTRON_DENSITY, "ELECTRON_DENSITY"},

    {EAC_ELECTRONIC_WATERBODY_FLOOR_DEPTH, "ELECTRONIC_WATERBODY_FLOOR_DEPTH"},

    {EAC_ELEV_ELECTRICAL_CABLE_ICING_SAG, "ELEV_ELECTRICAL_CABLE_ICING_SAG"},

    {EAC_ELEV_ELECTRICAL_CABLE_MINIMUM_HEIGHT, "ELEV_ELECTRICAL_CABLE_MINIMUM_HEIGHT"},

    {EAC_ELEV_ELECTRICAL_CABLE_PYLON_SPACING, "ELEV_ELECTRICAL_CABLE_PYLON_SPACING"},

    {EAC_ELEV_ELECTRICAL_CABLE_SAG, "ELEV_ELECTRICAL_CABLE_SAG"},

    {EAC_ELEV_ELECTRICAL_CABLE_SEGMENT_COUNT, "ELEV_ELECTRICAL_CABLE_SEGMENT_COUNT"},

    {EAC_ELEV_ELECTRICAL_CABLE_TYPE, "ELEV_ELECTRICAL_CABLE_TYPE"},

    {EAC_ELEVATED_EM_DUCT_BOTTOM, "ELEVATED_EM_DUCT_BOTTOM"},

    {EAC_ELEVATED_EM_DUCT_STRENGTH, "ELEVATED_EM_DUCT_STRENGTH"},

    {EAC_ELEVATED_EM_DUCT_TOP, "ELEVATED_EM_DUCT_TOP"},

    {EAC_ELEVATION, "ELEVATION"},

    {EAC_ELEVATION_ACCURACY_STATEMENT, "ELEVATION_ACCURACY_STATEMENT"},

    {EAC_ELEVATION_ANGLE, "ELEVATION_ANGLE"},

    {EAC_EM_BAND, "EM_BAND"},

    {EAC_EM_EVAPORATIVE_DUCT_HEIGHT, "EM_EVAPORATIVE_DUCT_HEIGHT"},

    {EAC_EM_POLARIZATION_TYPE, "EM_POLARIZATION_TYPE"},

    {EAC_EM_PROPAGATION_CONDITION, "EM_PROPAGATION_CONDITION"},

    {EAC_EM_PULSE_DURATION, "EM_PULSE_DURATION"},

    {EAC_EM_PULSE_PEAK_POWER, "EM_PULSE_PEAK_POWER"},

    {EAC_EM_PULSE_TOTAL_ENERGY, "EM_PULSE_TOTAL_ENERGY"},

    {EAC_EM_TRANSMISSION_LOSS, "EM_TRANSMISSION_LOSS"},

    {EAC_EMISSIVITY, "EMISSIVITY"},

    {EAC_EMITTANCE_AZIMUTH_GEODETIC, "EMITTANCE_AZIMUTH_GEODETIC"},

    {EAC_EMITTANCE_AZIMUTH_LOCAL, "EMITTANCE_AZIMUTH_LOCAL"},

    {EAC_EMITTANCE_AZIMUTH_MAGNETIC, "EMITTANCE_AZIMUTH_MAGNETIC"},

    {EAC_EMITTANCE_ELEV_ANGLE_HORIZONTAL, "EMITTANCE_ELEV_ANGLE_HORIZONTAL"},

    {EAC_EMITTANCE_ELEV_ANGLE_LOCAL, "EMITTANCE_ELEV_ANGLE_LOCAL"},

    {EAC_EMITTED_DIFFUSE_LIGHT_SCALED_INTENSITY, "EMITTED_DIFFUSE_LIGHT_SCALED_INTENSITY"},

    {EAC_EMITTED_SPECULAR_LIGHT_SCALED_INTENSITY, "EMITTED_SPECULAR_LIGHT_SCALED_INTENSITY"},

    {EAC_ENCLOSURE_MAXIMUM_HEIGHT, "ENCLOSURE_MAXIMUM_HEIGHT"},

    {EAC_ENCLOSURE_MEAN_HEIGHT, "ENCLOSURE_MEAN_HEIGHT"},

    {EAC_ENCLOSURE_MINIMUM_HEIGHT, "ENCLOSURE_MINIMUM_HEIGHT"},

    {EAC_ENGINE_SMOKE_RATE, "ENGINE_SMOKE_RATE"},

    {EAC_ENGINEER_TRENCH_TYPE, "ENGINEER_TRENCH_TYPE"},

    {EAC_ENTRANCE_AND_OR_EXIT_COUNT, "ENTRANCE_AND_OR_EXIT_COUNT"},

    {EAC_ENTRANCE_COUNT, "ENTRANCE_COUNT"},

    {EAC_EXISTENCE_CERTAINTY, "EXISTENCE_CERTAINTY"},

    {EAC_EXISTENCE_STATUS, "EXISTENCE_STATUS"},

    {EAC_EXIT_COUNT, "EXIT_COUNT"},

    {EAC_EXPLOSIVE_MINE_DENSITY, "EXPLOSIVE_MINE_DENSITY"},

    {EAC_EXPLOSIVE_MINE_TYPE, "EXPLOSIVE_MINE_TYPE"},

    {EAC_EXTERIOR_LIGHTING_INTENSITY, "EXTERIOR_LIGHTING_INTENSITY"},

    {EAC_EXTERIOR_WALL_CONSTRUCTION_TYPE, "EXTERIOR_WALL_CONSTRUCTION_TYPE"},

    {EAC_EXTERIOR_WALL_FORTIFICATION, "EXTERIOR_WALL_FORTIFICATION"},

    {EAC_EXTERIOR_WALL_THICKNESS, "EXTERIOR_WALL_THICKNESS"},

    {EAC_EXTERNAL_PAINT_SCHEME, "EXTERNAL_PAINT_SCHEME"},

    {EAC_EXTERNAL_WINDOW_COVERING, "EXTERNAL_WINDOW_COVERING"},

    {EAC_EXTINCTION_COEFFICIENT, "EXTINCTION_COEFFICIENT"},

    {EAC_EXTINCTION_COEFFICIENT_LEVEL, "EXTINCTION_COEFFICIENT_LEVEL"},

    {EAC_EXTINCTION_COEFFICIENT_WAVELENGTH, "EXTINCTION_COEFFICIENT_WAVELENGTH"},

    {EAC_EXTRACTION_MINE_TYPE, "EXTRACTION_MINE_TYPE"},

    {EAC_EXTREME_HIGH_AIR_TEMPERATURE, "EXTREME_HIGH_AIR_TEMPERATURE"},

    {EAC_EXTREME_LOW_AIR_TEMPERATURE, "EXTREME_LOW_AIR_TEMPERATURE"},

    {EAC_FABRICATION_TYPE, "FABRICATION_TYPE"},

    {EAC_FACILITY_COMMISSIONED_STATUS, "FACILITY_COMMISSIONED_STATUS"},

    {EAC_FACILITY_OPERATION_CONTINUITY, "FACILITY_OPERATION_CONTINUITY"},

    {EAC_FARMING_METHOD, "FARMING_METHOD"},

    {EAC_FENCE_TYPE, "FENCE_TYPE"},

    {EAC_FERRY_CROSSING_LENGTH, "FERRY_CROSSING_LENGTH"},

    {EAC_FERRY_CROSSING_TIME, "FERRY_CROSSING_TIME"},

    {EAC_FERRY_ROUTE_TYPE, "FERRY_ROUTE_TYPE"},

    {EAC_FIELD_PATTERN, "FIELD_PATTERN"},

    {EAC_FIGHTER_WINGED_AIRCRAFT_TYPE, "FIGHTER_WINGED_AIRCRAFT_TYPE"},

    {EAC_FIGHTING_POSITION_TYPE, "FIGHTING_POSITION_TYPE"},

    {EAC_FILL_TYPE, "FILL_TYPE"},

    {EAC_FIRE_ESCAPE_EXTENDED, "FIRE_ESCAPE_EXTENDED"},

    {EAC_FIRE_POWER_DAMAGE, "FIRE_POWER_DAMAGE"},

    {EAC_FISHING_FACILITY_TYPE, "FISHING_FACILITY_TYPE"},

    {EAC_FISHING_VESSEL_DENSITY, "FISHING_VESSEL_DENSITY"},

    {EAC_FLOOR_CONSTRUCTION_TYPE, "FLOOR_CONSTRUCTION_TYPE"},

    {EAC_FLOOR_COVERING_TYPE, "FLOOR_COVERING_TYPE"},

    {EAC_FLOOR_LEVEL_COUNT, "FLOOR_LEVEL_COUNT"},

    {EAC_FLOOR_LEVEL_IDENTIFIER, "FLOOR_LEVEL_IDENTIFIER"},

    {EAC_FLOW_DIRECTION, "FLOW_DIRECTION"},

    {EAC_FOG_COVERAGE_FRACTION, "FOG_COVERAGE_FRACTION"},

    {EAC_FOG_DETECTOR_LIGHT_PRESENT, "FOG_DETECTOR_LIGHT_PRESENT"},

    {EAC_FOG_EXTINCTION_COEFFICIENT, "FOG_EXTINCTION_COEFFICIENT"},

    {EAC_FOG_PRESENT, "FOG_PRESENT"},

    {EAC_FOG_PROBABILITY, "FOG_PROBABILITY"},

    {EAC_FOG_SIGNAL_GENERATION_TYPE, "FOG_SIGNAL_GENERATION_TYPE"},

    {EAC_FOG_THICKNESS, "FOG_THICKNESS"},

    {EAC_FOLIAGE_STATE, "FOLIAGE_STATE"},

    {EAC_FORCE_IDENTIFIER, "FORCE_IDENTIFIER"},

    {EAC_FORDABLE, "FORDABLE"},

    {EAC_FORMATION_RUNNING_LIGHT_INTENSITY, "FORMATION_RUNNING_LIGHT_INTENSITY"},

    {EAC_FRACTIONAL_CONTENT, "FRACTIONAL_CONTENT"},

    {EAC_FREQUENCY, "FREQUENCY"},

    {EAC_FREQUENCY_INDEPENDENT_ACOUSTIC_SCATTERING_LEVEL, "FREQUENCY_INDEPENDENT_ACOUSTIC_SCATTERING_LEVEL"},

    {EAC_FRIGATE_TYPE, "FRIGATE_TYPE"},

    {EAC_FRONT_AND_AXIS_REFERENCE, "FRONT_AND_AXIS_REFERENCE"},

    {EAC_FROUDE_NUMBER_TYPE_1, "FROUDE_NUMBER_TYPE_1"},

    {EAC_FROUDE_NUMBER_TYPE_2, "FROUDE_NUMBER_TYPE_2"},

    {EAC_FROZEN_SOIL_LAYER_BOTTOM_DEPTH, "FROZEN_SOIL_LAYER_BOTTOM_DEPTH"},

    {EAC_FROZEN_SOIL_LAYER_TOP_DEPTH, "FROZEN_SOIL_LAYER_TOP_DEPTH"},

    {EAC_FROZEN_SURFACE_COVER_TYPE, "FROZEN_SURFACE_COVER_TYPE"},

    {EAC_FUEL_FACILITIES_AVAILABLE, "FUEL_FACILITIES_AVAILABLE"},

    {EAC_FUNCTIONAL_RUNWAY_COUNT, "FUNCTIONAL_RUNWAY_COUNT"},

    {EAC_FUNCTIONAL_STATUS, "FUNCTIONAL_STATUS"},

    {EAC_FUNCTIONAL_USE, "FUNCTIONAL_USE"},

    {EAC_FURNITURE_TYPE, "FURNITURE_TYPE"},

    {EAC_GATE_TYPE, "GATE_TYPE"},

    {EAC_GENERAL_DAMAGE_FRACTION, "GENERAL_DAMAGE_FRACTION"},

    {EAC_GEODETIC_AZIMUTH, "GEODETIC_AZIMUTH"},

    {EAC_GEODETIC_DATUM_IDENTIFIER, "GEODETIC_DATUM_IDENTIFIER"},

    {EAC_GEOGRAPHIC_LIGHT_RANGE, "GEOGRAPHIC_LIGHT_RANGE"},

    {EAC_GEOGRAPHIC_REGION, "GEOGRAPHIC_REGION"},

    {EAC_GEOMORPHIC_DEPTH, "GEOMORPHIC_DEPTH"},

    {EAC_GEOMORPHIC_HEIGHT, "GEOMORPHIC_HEIGHT"},

    {EAC_GEOPOTENTIAL_ALTITUDE, "GEOPOTENTIAL_ALTITUDE"},

    {EAC_GLIDE_SLOPE_ANGLE, "GLIDE_SLOPE_ANGLE"},

    {EAC_GLINT_ANGLE, "GLINT_ANGLE"},

    {EAC_GRADIENT_RICHARDSON_NUMBER, "GRADIENT_RICHARDSON_NUMBER"},

    {EAC_GRADING_TYPE, "GRADING_TYPE"},

    {EAC_GRATING_PRESENT, "GRATING_PRESENT"},

    {EAC_GRID_DIAGONALIZATION, "GRID_DIAGONALIZATION"},

    {EAC_GROUND_VEHICLE_FUNCTION, "GROUND_VEHICLE_FUNCTION"},

    {EAC_GROUND_VEHICLE_PROPULSION_TYPE, "GROUND_VEHICLE_PROPULSION_TYPE"},

    {EAC_GTRS_GEOTILE, "GTRS_GEOTILE"},

    {EAC_GUIDED_MISSILE_DESTROYER_TYPE, "GUIDED_MISSILE_DESTROYER_TYPE"},

    {EAC_GUIDED_MISSILE_FRIGATE_TYPE, "GUIDED_MISSILE_FRIGATE_TYPE"},

    {EAC_GUYED, "GUYED"},

    {EAC_HAIL_SIZE, "HAIL_SIZE"},

    {EAC_HALLWAY_TYPE, "HALLWAY_TYPE"},

    {EAC_HARBOUR_FACILITY_TYPE, "HARBOUR_FACILITY_TYPE"},

    {EAC_HARBOUR_IDENTIFIER, "HARBOUR_IDENTIFIER"},

    {EAC_HAZARD_MARKER_TYPE, "HAZARD_MARKER_TYPE"},

    {EAC_HAZARD_SEVERITY, "HAZARD_SEVERITY"},

    {EAC_HAZARDOUS_GAS_TYPE, "HAZARDOUS_GAS_TYPE"},

    {EAC_HEAVY_ICE_ACCRETION_PROBABILITY, "HEAVY_ICE_ACCRETION_PROBABILITY"},

    {EAC_HEIGHT, "HEIGHT"},

    {EAC_HEIGHT_ABOVE_FLOOR, "HEIGHT_ABOVE_FLOOR"},

    {EAC_HEIGHT_ABOVE_SURFACE_LEVEL, "HEIGHT_ABOVE_SURFACE_LEVEL"},

    {EAC_HEIGHT_ABOVE_WATERBODY_FLOOR, "HEIGHT_ABOVE_WATERBODY_FLOOR"},

    {EAC_HEIGHT_AGL, "HEIGHT_AGL"},

    {EAC_HELIPAD_COUNT, "HELIPAD_COUNT"},

    {EAC_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY, "HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY"},

    {EAC_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY, "HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY"},

    {EAC_HF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH, "HF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH"},

    {EAC_HF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH, "HF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH"},

    {EAC_HF_BOTTOM_LOSS_REGION_IDENTIFIER, "HF_BOTTOM_LOSS_REGION_IDENTIFIER"},

    {EAC_HIGH_CLOUD_BASE_LEVEL, "HIGH_CLOUD_BASE_LEVEL"},

    {EAC_HIGH_CLOUD_COVERAGE, "HIGH_CLOUD_COVERAGE"},

    {EAC_HIGH_CLOUD_GENUS, "HIGH_CLOUD_GENUS"},

    {EAC_HIGH_CLOUD_TOP_LEVEL, "HIGH_CLOUD_TOP_LEVEL"},

    {EAC_HIGH_CLOUD_TYPE_OBSERVED, "HIGH_CLOUD_TYPE_OBSERVED"},

    {EAC_HIGHEST_AIRSPACE_ALTITUDE, "HIGHEST_AIRSPACE_ALTITUDE"},

    {EAC_HIGHEST_AIRSPACE_ALTITUDE_LIMIT, "HIGHEST_AIRSPACE_ALTITUDE_LIMIT"},

    {EAC_HIGHEST_ANNUAL_GROUND_WATER_LEVEL, "HIGHEST_ANNUAL_GROUND_WATER_LEVEL"},

    {EAC_HIGHEST_ELEVATION, "HIGHEST_ELEVATION"},

    {EAC_HINDUISM_DENOMINATIONAL_FAMILY, "HINDUISM_DENOMINATIONAL_FAMILY"},

    {EAC_HISTORICAL_CLOUD_FREE_LINE_OF_SIGHT_CLIMATOLOGY, "HISTORICAL_CLOUD_FREE_LINE_OF_SIGHT_CLIMATOLOGY"},

    {EAC_HISTORICAL_SIGNIFICANCE, "HISTORICAL_SIGNIFICANCE"},

    {EAC_HORIZONTAL_CLEARANCE, "HORIZONTAL_CLEARANCE"},

    {EAC_HORIZONTAL_CLEARANCE_LIMITED, "HORIZONTAL_CLEARANCE_LIMITED"},

    {EAC_HORIZONTAL_LOAD_BEARING_CAPACITY, "HORIZONTAL_LOAD_BEARING_CAPACITY"},

    {EAC_HOSPITAL_BED_CAPACITY, "HOSPITAL_BED_CAPACITY"},

    {EAC_HOUR_WITHIN_DAY, "HOUR_WITHIN_DAY"},

    {EAC_HULK_TYPE, "HULK_TYPE"},

    {EAC_HUMAN_FUNCTION, "HUMAN_FUNCTION"},

    {EAC_HUMAN_ROLE, "HUMAN_ROLE"},

    {EAC_HYDROGRAPHIC_BARRIER_TYPE, "HYDROGRAPHIC_BARRIER_TYPE"},

    {EAC_HYDROGRAPHIC_DEPTH, "HYDROGRAPHIC_DEPTH"},

    {EAC_HYDROGRAPHIC_DEPTH_CATEGORY, "HYDROGRAPHIC_DEPTH_CATEGORY"},

    {EAC_HYDROGRAPHIC_DEPTH_INFORMATION, "HYDROGRAPHIC_DEPTH_INFORMATION"},

    {EAC_HYDROGRAPHIC_DRYING_HEIGHT, "HYDROGRAPHIC_DRYING_HEIGHT"},

    {EAC_HYDROGRAPHIC_OBJECT_ORIGIN, "HYDROGRAPHIC_OBJECT_ORIGIN"},

    {EAC_HYDROGRAPHIC_SURVEY_CONTACT_TYPE, "HYDROGRAPHIC_SURVEY_CONTACT_TYPE"},

    {EAC_HYDROLOGIC_PERMANENCE, "HYDROLOGIC_PERMANENCE"},

    {EAC_HYPSOGRAPHIC_PORTRAYAL_TYPE, "HYPSOGRAPHIC_PORTRAYAL_TYPE"},

    {EAC_ICAO_AIRSPACE_CLASS, "ICAO_AIRSPACE_CLASS"},

    {EAC_ICE_COVERAGE_FRACTION, "ICE_COVERAGE_FRACTION"},

    {EAC_ICE_COVERED, "ICE_COVERED"},

    {EAC_ICE_DRAFT_ROOT_MEAN_SQUARE, "ICE_DRAFT_ROOT_MEAN_SQUARE"},

    {EAC_ICE_KEEL_DENSITY, "ICE_KEEL_DENSITY"},

    {EAC_ICE_LAYER_THICKNESS, "ICE_LAYER_THICKNESS"},

    {EAC_ICING_TYPE, "ICING_TYPE"},

    {EAC_IGNITION_FLASH_INTENSITY, "IGNITION_FLASH_INTENSITY"},

    {EAC_ILLUMINANCE, "ILLUMINANCE"},

    {EAC_ILLUMINANCE_DIRECT, "ILLUMINANCE_DIRECT"},

    {EAC_ILLUMINANCE_DIRECT_FROM_PRINCIPAL_SOURCE, "ILLUMINANCE_DIRECT_FROM_PRINCIPAL_SOURCE"},

    {EAC_IMO_ADOPTED, "IMO_ADOPTED"},

    {EAC_INCIDENCE_AZIMUTH_GEODETIC, "INCIDENCE_AZIMUTH_GEODETIC"},

    {EAC_INCIDENCE_AZIMUTH_LOCAL, "INCIDENCE_AZIMUTH_LOCAL"},

    {EAC_INCIDENCE_AZIMUTH_MAGNETIC, "INCIDENCE_AZIMUTH_MAGNETIC"},

    {EAC_INCIDENCE_ELEV_ANGLE_HORIZONTAL, "INCIDENCE_ELEV_ANGLE_HORIZONTAL"},

    {EAC_INCIDENCE_ELEV_ANGLE_LOCAL, "INCIDENCE_ELEV_ANGLE_LOCAL"},

    {EAC_INCIDENCE_ZENITH_ANGLE_LOCAL, "INCIDENCE_ZENITH_ANGLE_LOCAL"},

    {EAC_INFRARED_HEAT_FLUX, "INFRARED_HEAT_FLUX"},

    {EAC_INLAND_HYDROGRAPHIC_PERMANENCE, "INLAND_HYDROGRAPHIC_PERMANENCE"},

    {EAC_INLAND_WATER_OBSTRUCTION, "INLAND_WATER_OBSTRUCTION"},

    {EAC_INSIDE_DIAMETER, "INSIDE_DIAMETER"},

    {EAC_INSTALLATION_BUOY_TYPE, "INSTALLATION_BUOY_TYPE"},

    {EAC_INTEG_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION, "INTEG_BIDIRECTIONAL_REFLECTANCE_DISTRIBUTION_FUNCTION"},

    {EAC_INTEG_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY, "INTEG_DIRECTIONAL_HEMISPHERICAL_REFLECTIVITY"},

    {EAC_INTEG_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY, "INTEG_HEMISPHERICAL_DIRECTIONAL_REFLECTIVITY"},

    {EAC_INTEG_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY, "INTEG_HEMISPHERICAL_HEMISPHERICAL_REFLECTIVITY"},

    {EAC_INTERCHANGE_TRAVERSABILITY, "INTERCHANGE_TRAVERSABILITY"},

    {EAC_INTEREST_TYPE, "INTEREST_TYPE"},

    {EAC_INTERIOR_AIR_EXCHANGE_RATE, "INTERIOR_AIR_EXCHANGE_RATE"},

    {EAC_INTERIOR_LIGHTING_INTENSITY, "INTERIOR_LIGHTING_INTENSITY"},

    {EAC_INTERIOR_WALL_CONSTRUCTION_TYPE, "INTERIOR_WALL_CONSTRUCTION_TYPE"},

    {EAC_INTERIOR_WINDOW_COVERING, "INTERIOR_WINDOW_COVERING"},

    {EAC_INTERNAL_FLOW_SPEED, "INTERNAL_FLOW_SPEED"},

    {EAC_INTERNAL_FROUDE_NUMBER_ATM, "INTERNAL_FROUDE_NUMBER_ATM"},

    {EAC_INTERNAL_TEMPERATURE, "INTERNAL_TEMPERATURE"},

    {EAC_INTERNALLY_HEATED, "INTERNALLY_HEATED"},

    {EAC_IONOSPHERIC_SCINT_EAST_DRIFT, "IONOSPHERIC_SCINT_EAST_DRIFT"},

    {EAC_IONOSPHERIC_SCINT_MAXIMUM_SIZE, "IONOSPHERIC_SCINT_MAXIMUM_SIZE"},

    {EAC_IONOSPHERIC_SCINT_NORTH_DRIFT, "IONOSPHERIC_SCINT_NORTH_DRIFT"},

    {EAC_IONOSPHERIC_SCINT_PHASE_ALTITUDE, "IONOSPHERIC_SCINT_PHASE_ALTITUDE"},

    {EAC_IONOSPHERIC_SCINT_STRUCTURE_ANGLE, "IONOSPHERIC_SCINT_STRUCTURE_ANGLE"},

    {EAC_IONOSPHERIC_SCINT_UP_DRIFT, "IONOSPHERIC_SCINT_UP_DRIFT"},

    {EAC_IRRIGATION_METHOD, "IRRIGATION_METHOD"},

    {EAC_ISLAMIC_DENOMINATIONAL_FAMILY, "ISLAMIC_DENOMINATIONAL_FAMILY"},

    {EAC_ISOBARIC_SURFACE_LEVEL, "ISOBARIC_SURFACE_LEVEL"},

    {EAC_ISOLATED, "ISOLATED"},

    {EAC_ISOLATED_COMMUNICATION_LINE, "ISOLATED_COMMUNICATION_LINE"},

    {EAC_JAINISM_DENOMINATIONAL_FAMILY, "JAINISM_DENOMINATIONAL_FAMILY"},

    {EAC_JUDAISM_DENOMINATIONAL_FAMILY, "JUDAISM_DENOMINATIONAL_FAMILY"},

    {EAC_JULIAN_DATE_TERRESTRIAL_TIME, "JULIAN_DATE_TERRESTRIAL_TIME"},

    {EAC_JULIAN_DAY, "JULIAN_DAY"},

    {EAC_KELP_COVERAGE, "KELP_COVERAGE"},

    {EAC_LADDER_PRESENT, "LADDER_PRESENT"},

    {EAC_LAMBERT_LAW_CONSTANT, "LAMBERT_LAW_CONSTANT"},

    {EAC_LAND_ROUTE_SLOPE_SEGMENT_LENGTH, "LAND_ROUTE_SLOPE_SEGMENT_LENGTH"},

    {EAC_LAND_ROUTE_TYPE, "LAND_ROUTE_TYPE"},

    {EAC_LAND_ROUTE_USABLE_WEATHER_TYPE, "LAND_ROUTE_USABLE_WEATHER_TYPE"},

    {EAC_LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE, "LAND_TRANSPORTATION_ROUTE_SURFACE_TYPE"},

    {EAC_LAND_TRNSP_MEDIAN_PRESENT, "LAND_TRNSP_MEDIAN_PRESENT"},

    {EAC_LAND_TRNSP_MEDIAN_WIDTH, "LAND_TRNSP_MEDIAN_WIDTH"},

    {EAC_LANDING_CRAFT_TYPE, "LANDING_CRAFT_TYPE"},

    {EAC_LANDING_DISTANCE_AVAILABLE, "LANDING_DISTANCE_AVAILABLE"},

    {EAC_LANDING_LIGHT_INTENSITY, "LANDING_LIGHT_INTENSITY"},

    {EAC_LANE_COUNT, "LANE_COUNT"},

    {EAC_LANE_MARKING_TYPE, "LANE_MARKING_TYPE"},

    {EAC_LARGE_SCALE_PRECIPITATION, "LARGE_SCALE_PRECIPITATION"},

    {EAC_LARGE_TANKER_DENSITY, "LARGE_TANKER_DENSITY"},

    {EAC_LATENT_HEAT_FLUX, "LATENT_HEAT_FLUX"},

    {EAC_LATENT_HEAT_FUSION, "LATENT_HEAT_FUSION"},

    {EAC_LATENT_HEAT_SUBLIMATION, "LATENT_HEAT_SUBLIMATION"},

    {EAC_LATENT_HEAT_VAPOURIZATION, "LATENT_HEAT_VAPOURIZATION"},

    {EAC_LEAF_AREA_INDEX, "LEAF_AREA_INDEX"},

    {EAC_LEFT_ABOVE_BANK_ANGLE, "LEFT_ABOVE_BANK_ANGLE"},

    {EAC_LEFT_ABOVE_BANK_SLOPE, "LEFT_ABOVE_BANK_SLOPE"},

    {EAC_LEFT_BANK_HEIGHT, "LEFT_BANK_HEIGHT"},

    {EAC_LEFT_BANK_SLOPE, "LEFT_BANK_SLOPE"},

    {EAC_LEFT_BANK_SOIL_CONE_INDEX, "LEFT_BANK_SOIL_CONE_INDEX"},

    {EAC_LEFT_BANK_VEGETATION_DENSITY, "LEFT_BANK_VEGETATION_DENSITY"},

    {EAC_LEFT_BELOW_BANK_ANGLE, "LEFT_BELOW_BANK_ANGLE"},

    {EAC_LEFT_BELOW_BANK_SLOPE, "LEFT_BELOW_BANK_SLOPE"},

    {EAC_LEFT_TERRAIN_BANK_SLOPE, "LEFT_TERRAIN_BANK_SLOPE"},

    {EAC_LENGTH, "LENGTH"},

    {EAC_LF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH, "LF_ACOUSTIC_SCTR_LAYER_BOTTOM_DEPTH"},

    {EAC_LF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH, "LF_ACOUSTIC_SCTR_LAYER_TOP_DEPTH"},

    {EAC_LF_BOTTOM_LOSS_REGION_IDENTIFIER, "LF_BOTTOM_LOSS_REGION_IDENTIFIER"},

    {EAC_LIFT_TYPE, "LIFT_TYPE"},

    {EAC_LIFTED_ATMOSPHERE_STABILITY_INDEX, "LIFTED_ATMOSPHERE_STABILITY_INDEX"},

    {EAC_LIFTING_CAPACITY, "LIFTING_CAPACITY"},

    {EAC_LIGHT_BEAM_SPREAD, "LIGHT_BEAM_SPREAD"},

    {EAC_LIGHT_COLOUR, "LIGHT_COLOUR"},

    {EAC_LIGHT_ELEVATION, "LIGHT_ELEVATION"},

    {EAC_LIGHT_EXHIBITION_CONDITION, "LIGHT_EXHIBITION_CONDITION"},

    {EAC_LIGHT_FUNCTION, "LIGHT_FUNCTION"},

    {EAC_LIGHT_ICE_ACCRETION_PROBABILITY, "LIGHT_ICE_ACCRETION_PROBABILITY"},

    {EAC_LIGHT_MULTIPLICITY, "LIGHT_MULTIPLICITY"},

    {EAC_LIGHT_PATTERN, "LIGHT_PATTERN"},

    {EAC_LIGHT_PERIOD, "LIGHT_PERIOD"},

    {EAC_LIGHT_RELATIVE_LOCATION, "LIGHT_RELATIVE_LOCATION"},

    {EAC_LIGHT_SECTOR_ANGLE, "LIGHT_SECTOR_ANGLE"},

    {EAC_LIGHT_SUPERVISED, "LIGHT_SUPERVISED"},

    {EAC_LIGHT_TYPE, "LIGHT_TYPE"},

    {EAC_LIGHT_VISIBILITY, "LIGHT_VISIBILITY"},

    {EAC_LIGHT_VISIBILITY_RANGES, "LIGHT_VISIBILITY_RANGES"},

    {EAC_LIGHTING_CHARACTERIZATION, "LIGHTING_CHARACTERIZATION"},

    {EAC_LIGHTNING_CURRENT_STRENGTH, "LIGHTNING_CURRENT_STRENGTH"},

    {EAC_LIGHTNING_DATA_CONSISTENCY, "LIGHTNING_DATA_CONSISTENCY"},

    {EAC_LIGHTNING_DETECTOR_COUNT, "LIGHTNING_DETECTOR_COUNT"},

    {EAC_LIGHTNING_LOC_ERR_ELLPS_ANGLE, "LIGHTNING_LOC_ERR_ELLPS_ANGLE"},

    {EAC_LIGHTNING_LOC_ERR_ELLPS_MAJOR_AXIS, "LIGHTNING_LOC_ERR_ELLPS_MAJOR_AXIS"},

    {EAC_LIGHTNING_LOC_ERR_ELLPS_MINOR_AXIS, "LIGHTNING_LOC_ERR_ELLPS_MINOR_AXIS"},

    {EAC_LIGHTNING_POLARITY, "LIGHTNING_POLARITY"},

    {EAC_LIGHTNING_PROBABILITY, "LIGHTNING_PROBABILITY"},

    {EAC_LIGHTNING_STROKE_COUNT, "LIGHTNING_STROKE_COUNT"},

    {EAC_LIGHTNING_TIME_ADJUSTMENT, "LIGHTNING_TIME_ADJUSTMENT"},

    {EAC_LINEAR_ATTENUATION_COEFFICIENT, "LINEAR_ATTENUATION_COEFFICIENT"},

    {EAC_LIQUID_CAPACITY, "LIQUID_CAPACITY"},

    {EAC_LITTORAL_CURRENT_EAST_SPEED, "LITTORAL_CURRENT_EAST_SPEED"},

    {EAC_LITTORAL_CURRENT_NORTH_SPEED, "LITTORAL_CURRENT_NORTH_SPEED"},

    {EAC_LITTORAL_CURRENT_U_SPEED, "LITTORAL_CURRENT_U_SPEED"},

    {EAC_LITTORAL_CURRENT_V_SPEED, "LITTORAL_CURRENT_V_SPEED"},

    {EAC_LIVING_ORGANISM_COMMON_NAME, "LIVING_ORGANISM_COMMON_NAME"},

    {EAC_LIVING_ORGANISM_SCIENTIFIC_NAME, "LIVING_ORGANISM_SCIENTIFIC_NAME"},

    {EAC_LOAD_CLASS_ONE_WAY_TRACKED, "LOAD_CLASS_ONE_WAY_TRACKED"},

    {EAC_LOAD_CLASS_ONE_WAY_WHEELED, "LOAD_CLASS_ONE_WAY_WHEELED"},

    {EAC_LOAD_CLASS_TWO_WAY_TRACKED, "LOAD_CLASS_TWO_WAY_TRACKED"},

    {EAC_LOAD_CLASS_TWO_WAY_WHEELED, "LOAD_CLASS_TWO_WAY_WHEELED"},

    {EAC_LOCAL_AZIMUTH, "LOCAL_AZIMUTH"},

    {EAC_LOCATION_ACCURACY_METHOD, "LOCATION_ACCURACY_METHOD"},

    {EAC_LOCATION_ACCURACY_STATEMENT, "LOCATION_ACCURACY_STATEMENT"},

    {EAC_LONGEST_BRIDGE_SPAN_LENGTH, "LONGEST_BRIDGE_SPAN_LENGTH"},

    {EAC_LOW_CLOUD_BASE_LEVEL, "LOW_CLOUD_BASE_LEVEL"},

    {EAC_LOW_CLOUD_COVERAGE, "LOW_CLOUD_COVERAGE"},

    {EAC_LOW_CLOUD_GENUS, "LOW_CLOUD_GENUS"},

    {EAC_LOW_CLOUD_TOP_LEVEL, "LOW_CLOUD_TOP_LEVEL"},

    {EAC_LOW_CLOUD_TYPE_OBSERVED, "LOW_CLOUD_TYPE_OBSERVED"},

    {EAC_LOWER_LAYER_SOIL_TEMPERATURE, "LOWER_LAYER_SOIL_TEMPERATURE"},

    {EAC_LOWEST_AIRSPACE_ALTITUDE, "LOWEST_AIRSPACE_ALTITUDE"},

    {EAC_LOWEST_AIRSPACE_ALTITUDE_LIMIT, "LOWEST_AIRSPACE_ALTITUDE_LIMIT"},

    {EAC_LOWEST_ANNUAL_GROUND_WATER_LEVEL, "LOWEST_ANNUAL_GROUND_WATER_LEVEL"},

    {EAC_LOWEST_CLOUD_BASE_LEVEL, "LOWEST_CLOUD_BASE_LEVEL"},

    {EAC_LOWEST_CLOUD_COVER_CATEGORY, "LOWEST_CLOUD_COVER_CATEGORY"},

    {EAC_LOWEST_ELEVATION, "LOWEST_ELEVATION"},

    {EAC_LUMINOUS_LIGHT_RANGE, "LUMINOUS_LIGHT_RANGE"},

    {EAC_LUNAR_DIFFUSED_IRRADIANCE, "LUNAR_DIFFUSED_IRRADIANCE"},

    {EAC_LUNAR_DIRECT_IRRADIANCE, "LUNAR_DIRECT_IRRADIANCE"},

    {EAC_LUNAR_ILLUMINATION_FRACTION, "LUNAR_ILLUMINATION_FRACTION"},

    {EAC_LUNAR_RADIANCE_AZIMUTH_GEODETIC, "LUNAR_RADIANCE_AZIMUTH_GEODETIC"},

    {EAC_LUNAR_RADIANCE_ELEV_ANGLE_HORIZONTAL, "LUNAR_RADIANCE_ELEV_ANGLE_HORIZONTAL"},

    {EAC_MAGNETIC_AZIMUTH, "MAGNETIC_AZIMUTH"},

    {EAC_MAGNETIC_FIELD_A, "MAGNETIC_FIELD_A"},

    {EAC_MAGNETIC_FIELD_A_DAILY, "MAGNETIC_FIELD_A_DAILY"},

    {EAC_MAGNETIC_FIELD_ANOMALY, "MAGNETIC_FIELD_ANOMALY"},

    {EAC_MAGNETIC_FIELD_AP, "MAGNETIC_FIELD_AP"},

    {EAC_MAGNETIC_FIELD_DECLINATION_ANGLE, "MAGNETIC_FIELD_DECLINATION_ANGLE"},

    {EAC_MAGNETIC_FIELD_EAST_COMPONENT, "MAGNETIC_FIELD_EAST_COMPONENT"},

    {EAC_MAGNETIC_FIELD_FULL_COMPONENT, "MAGNETIC_FIELD_FULL_COMPONENT"},

    {EAC_MAGNETIC_FIELD_HORIZONTAL_COMPONENT, "MAGNETIC_FIELD_HORIZONTAL_COMPONENT"},

    {EAC_MAGNETIC_FIELD_INCLINATION_ANGLE, "MAGNETIC_FIELD_INCLINATION_ANGLE"},

    {EAC_MAGNETIC_FIELD_K, "MAGNETIC_FIELD_K"},

    {EAC_MAGNETIC_FIELD_K_DAILY, "MAGNETIC_FIELD_K_DAILY"},

    {EAC_MAGNETIC_FIELD_KP, "MAGNETIC_FIELD_KP"},

    {EAC_MAGNETIC_FIELD_NORMAL, "MAGNETIC_FIELD_NORMAL"},

    {EAC_MAGNETIC_FIELD_NORTH_COMPONENT, "MAGNETIC_FIELD_NORTH_COMPONENT"},

    {EAC_MAGNETIC_FIELD_PARALLEL, "MAGNETIC_FIELD_PARALLEL"},

    {EAC_MAGNETIC_FIELD_PLANETWARD, "MAGNETIC_FIELD_PLANETWARD"},

    {EAC_MAGNETIC_FIELD_TOTAL, "MAGNETIC_FIELD_TOTAL"},

    {EAC_MAGNETIC_FIELD_VERTICAL_COMPONENT, "MAGNETIC_FIELD_VERTICAL_COMPONENT"},

    {EAC_MAGNETIC_LOCAL_TIME, "MAGNETIC_LOCAL_TIME"},

    {EAC_MAGNETOSPHERE_PLASMA_FLUX, "MAGNETOSPHERE_PLASMA_FLUX"},

    {EAC_MAILBOX_TYPE, "MAILBOX_TYPE"},

    {EAC_MAINTAINED, "MAINTAINED"},

    {EAC_MAN_MADE, "MAN_MADE"},

    {EAC_MANOEUVRE_DAMAGE_FRACTION, "MANOEUVRE_DAMAGE_FRACTION"},

    {EAC_MARGINAL_ICE_ZONE_COVER_FRACTION, "MARGINAL_ICE_ZONE_COVER_FRACTION"},

    {EAC_MARINE_BEACON_SHAPE, "MARINE_BEACON_SHAPE"},

    {EAC_MARINE_BOUNDARY_LIMIT_TYPE, "MARINE_BOUNDARY_LIMIT_TYPE"},

    {EAC_MARINE_CONSTRUCTION_TYPE, "MARINE_CONSTRUCTION_TYPE"},

    {EAC_MARINE_LIGHT_SECTOR_INITIAL_ANGLE, "MARINE_LIGHT_SECTOR_INITIAL_ANGLE"},

    {EAC_MARINE_LIGHT_SECTOR_TERMINAL_ANGLE, "MARINE_LIGHT_SECTOR_TERMINAL_ANGLE"},

    {EAC_MARINE_LIGHT_TYPE, "MARINE_LIGHT_TYPE"},

    {EAC_MARINE_LINE_ASSOCIATED_ATNAV, "MARINE_LINE_ASSOCIATED_ATNAV"},

    {EAC_MARINE_LINE_ATNAV_DESCRIPTION, "MARINE_LINE_ATNAV_DESCRIPTION"},

    {EAC_MARINE_NAVIGATION_LINE_TYPE, "MARINE_NAVIGATION_LINE_TYPE"},

    {EAC_MARINE_OVERHEAD_OBSTRUCTION, "MARINE_OVERHEAD_OBSTRUCTION"},

    {EAC_MARINE_PILOT_BOARDING_METHOD, "MARINE_PILOT_BOARDING_METHOD"},

    {EAC_MARINE_PILOT_BOARDING_VEHICLE, "MARINE_PILOT_BOARDING_VEHICLE"},

    {EAC_MARINE_PILOT_DISTRICT, "MARINE_PILOT_DISTRICT"},

    {EAC_MARINE_PORT_IDENTIFIER, "MARINE_PORT_IDENTIFIER"},

    {EAC_MARINE_REGION_TYPE, "MARINE_REGION_TYPE"},

    {EAC_MARINE_RESCUE_STATION_TYPE, "MARINE_RESCUE_STATION_TYPE"},

    {EAC_MARINE_ROUTE_TYPE, "MARINE_ROUTE_TYPE"},

    {EAC_MARINE_STATION_ACTIVITY, "MARINE_STATION_ACTIVITY"},

    {EAC_MARINE_STATION_EQUIPMENT, "MARINE_STATION_EQUIPMENT"},

    {EAC_MARINE_SURVEY_TYPE, "MARINE_SURVEY_TYPE"},

    {EAC_MARINE_TONNAGE, "MARINE_TONNAGE"},

    {EAC_MARINE_TRACK_TYPE, "MARINE_TRACK_TYPE"},

    {EAC_MARINE_TRAFFIC_SIGNAL_TYPE, "MARINE_TRAFFIC_SIGNAL_TYPE"},

    {EAC_MARINE_TSS_COMPONENT, "MARINE_TSS_COMPONENT"},

    {EAC_MARINE_USE, "MARINE_USE"},

    {EAC_MARINE_WARNING_SIGNAL_TYPE, "MARINE_WARNING_SIGNAL_TYPE"},

    {EAC_MARINE_WRECK_STATUS, "MARINE_WRECK_STATUS"},

    {EAC_MARINE_WRECK_TYPE, "MARINE_WRECK_TYPE"},

    {EAC_MARINER_NOTICE_DATE, "MARINER_NOTICE_DATE"},

    {EAC_MARK_TYPE, "MARK_TYPE"},

    {EAC_MASS, "MASS"},

    {EAC_MASS_EXTINCTION_COEFFICIENT, "MASS_EXTINCTION_COEFFICIENT"},

    {EAC_MAST_TYPE, "MAST_TYPE"},

    {EAC_MATERIAL_DENSITY, "MATERIAL_DENSITY"},

    {EAC_MATERIAL_HANDLING_FACILITIES, "MATERIAL_HANDLING_FACILITIES"},

    {EAC_MAX_WATERBODY_TEMP_1_STD_DEV, "MAX_WATERBODY_TEMP_1_STD_DEV"},

    {EAC_MAX_WATERBODY_TEMP_2_STD_DEV, "MAX_WATERBODY_TEMP_2_STD_DEV"},

    {EAC_MAX_WATERBODY_TEMP_3_STD_DEV, "MAX_WATERBODY_TEMP_3_STD_DEV"},

    {EAC_MAXIMUM_ACHIEVABLE_TEMPERATURE, "MAXIMUM_ACHIEVABLE_TEMPERATURE"},

    {EAC_MAXIMUM_AIR_TEMPERATURE, "MAXIMUM_AIR_TEMPERATURE"},

    {EAC_MAXIMUM_AIR_TEMPERATURE_PERIOD, "MAXIMUM_AIR_TEMPERATURE_PERIOD"},

    {EAC_MAXIMUM_AUTHORIZED_ALTITUDE, "MAXIMUM_AUTHORIZED_ALTITUDE"},

    {EAC_MAXIMUM_BREAKER_HEIGHT, "MAXIMUM_BREAKER_HEIGHT"},

    {EAC_MAXIMUM_CONTOUR_DEPTH, "MAXIMUM_CONTOUR_DEPTH"},

    {EAC_MAXIMUM_CURRENT_SPEED, "MAXIMUM_CURRENT_SPEED"},

    {EAC_MAXIMUM_DEW_POINT_TEMPERATURE, "MAXIMUM_DEW_POINT_TEMPERATURE"},

    {EAC_MAXIMUM_FLIGHT_LEVEL, "MAXIMUM_FLIGHT_LEVEL"},

    {EAC_MAXIMUM_ICE_KEEL_DRAFT, "MAXIMUM_ICE_KEEL_DRAFT"},

    {EAC_MAXIMUM_OBSTACLE_HEIGHT, "MAXIMUM_OBSTACLE_HEIGHT"},

    {EAC_MAXIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL, "MAXIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL"},

    {EAC_MAXIMUM_RADIANT_INTENSITY, "MAXIMUM_RADIANT_INTENSITY"},

    {EAC_MAXIMUM_STANDING_WATER_DEPTH, "MAXIMUM_STANDING_WATER_DEPTH"},

    {EAC_MAXIMUM_TERRAIN_ELEVATION, "MAXIMUM_TERRAIN_ELEVATION"},

    {EAC_MAXIMUM_VERTICAL_CLEARANCE, "MAXIMUM_VERTICAL_CLEARANCE"},

    {EAC_MAXIMUM_VISIBILITY_RANGE, "MAXIMUM_VISIBILITY_RANGE"},

    {EAC_MAXIMUM_VOLTAGE, "MAXIMUM_VOLTAGE"},

    {EAC_MAXIMUM_WATER_DEPTH, "MAXIMUM_WATER_DEPTH"},

    {EAC_MAXIMUM_WAVE_HEIGHT, "MAXIMUM_WAVE_HEIGHT"},

    {EAC_MAXIMUM_WIND_GUST_SPREAD, "MAXIMUM_WIND_GUST_SPREAD"},

    {EAC_MAXIMUM_WIND_SPEED, "MAXIMUM_WIND_SPEED"},

    {EAC_MEAN_AIR_DENSITY_CLIM, "MEAN_AIR_DENSITY_CLIM"},

    {EAC_MEAN_AIR_DENSITY_CLIM_STD_DEV, "MEAN_AIR_DENSITY_CLIM_STD_DEV"},

    {EAC_MEAN_AIR_TEMP, "MEAN_AIR_TEMP"},

    {EAC_MEAN_AIR_TEMP_CLIM, "MEAN_AIR_TEMP_CLIM"},

    {EAC_MEAN_AIR_TEMP_CLIM_STD_DEV, "MEAN_AIR_TEMP_CLIM_STD_DEV"},

    {EAC_MEAN_AIR_TEMP_DIFFERENCE_CLIM, "MEAN_AIR_TEMP_DIFFERENCE_CLIM"},

    {EAC_MEAN_AIR_TEMP_MAX_DIFFERENCE_CLIM, "MEAN_AIR_TEMP_MAX_DIFFERENCE_CLIM"},

    {EAC_MEAN_AIR_TEMP_MIN_DIFFERENCE_CLIM, "MEAN_AIR_TEMP_MIN_DIFFERENCE_CLIM"},

    {EAC_MEAN_AIR_WATER_TEMP_DIFF_CLIM_STD_DEV, "MEAN_AIR_WATER_TEMP_DIFF_CLIM_STD_DEV"},

    {EAC_MEAN_AIR_WATER_TEMP_DIFFERENCE, "MEAN_AIR_WATER_TEMP_DIFFERENCE"},

    {EAC_MEAN_CLOUD_DROP_DIAMETER, "MEAN_CLOUD_DROP_DIAMETER"},

    {EAC_MEAN_DEW_POINT_CLIMATOLOGY, "MEAN_DEW_POINT_CLIMATOLOGY"},

    {EAC_MEAN_DEW_POINT_CLIMATOLOGY_STD_DEV, "MEAN_DEW_POINT_CLIMATOLOGY_STD_DEV"},

    {EAC_MEAN_DEW_POINT_TEMPERATURE, "MEAN_DEW_POINT_TEMPERATURE"},

    {EAC_MEAN_EVAP_TRANSPIRATION_RATE, "MEAN_EVAP_TRANSPIRATION_RATE"},

    {EAC_MEAN_GEOPOTENTIAL_ALT_CLIM, "MEAN_GEOPOTENTIAL_ALT_CLIM"},

    {EAC_MEAN_GEOPOTENTIAL_ALT_CLIM_STD_DEV, "MEAN_GEOPOTENTIAL_ALT_CLIM_STD_DEV"},

    {EAC_MEAN_ICE_DRAFT, "MEAN_ICE_DRAFT"},

    {EAC_MEAN_ICE_DRAFT_STD_DEV, "MEAN_ICE_DRAFT_STD_DEV"},

    {EAC_MEAN_ICE_KEEL_DRAFT, "MEAN_ICE_KEEL_DRAFT"},

    {EAC_MEAN_ICE_KEEL_DRAFT_STD_DEV, "MEAN_ICE_KEEL_DRAFT_STD_DEV"},

    {EAC_MEAN_ICE_KEEL_SEPARATION, "MEAN_ICE_KEEL_SEPARATION"},

    {EAC_MEAN_ICE_KEEL_SEPARATION_STD_DEV, "MEAN_ICE_KEEL_SEPARATION_STD_DEV"},

    {EAC_MEAN_LUMINOUS_INTENSITY, "MEAN_LUMINOUS_INTENSITY"},

    {EAC_MEAN_MAGNETIC_FIELD_DECLINATION_ANGLE, "MEAN_MAGNETIC_FIELD_DECLINATION_ANGLE"},

    {EAC_MEAN_MAGNETIC_FIELD_EAST_COMPONENT, "MEAN_MAGNETIC_FIELD_EAST_COMPONENT"},

    {EAC_MEAN_MAGNETIC_FIELD_FULL_COMPONENT, "MEAN_MAGNETIC_FIELD_FULL_COMPONENT"},

    {EAC_MEAN_MAGNETIC_FIELD_HORIZONTAL_COMPONENT, "MEAN_MAGNETIC_FIELD_HORIZONTAL_COMPONENT"},

    {EAC_MEAN_MAGNETIC_FIELD_INCLINATION_ANGLE, "MEAN_MAGNETIC_FIELD_INCLINATION_ANGLE"},

    {EAC_MEAN_MAGNETIC_FIELD_NORTH_COMPONENT, "MEAN_MAGNETIC_FIELD_NORTH_COMPONENT"},

    {EAC_MEAN_MAGNETIC_FIELD_VERTICAL_COMPONENT, "MEAN_MAGNETIC_FIELD_VERTICAL_COMPONENT"},

    {EAC_MEAN_OBJECT_DIAMETER, "MEAN_OBJECT_DIAMETER"},

    {EAC_MEAN_OBJECT_SPACING, "MEAN_OBJECT_SPACING"},

    {EAC_MEAN_POTENTIAL_SOIL_EVAP_TRANSPIRATION_RATE, "MEAN_POTENTIAL_SOIL_EVAP_TRANSPIRATION_RATE"},

    {EAC_MEAN_PRIMARY_BREAKER_PERIOD, "MEAN_PRIMARY_BREAKER_PERIOD"},

    {EAC_MEAN_PRIMARY_WAVE_PERIOD, "MEAN_PRIMARY_WAVE_PERIOD"},

    {EAC_MEAN_SECONDARY_BREAKER_PERIOD, "MEAN_SECONDARY_BREAKER_PERIOD"},

    {EAC_MEAN_SECONDARY_WAVE_PERIOD, "MEAN_SECONDARY_WAVE_PERIOD"},

    {EAC_MEAN_SOIL_EVAP_TRANSPIRATION_RATE, "MEAN_SOIL_EVAP_TRANSPIRATION_RATE"},

    {EAC_MEAN_SOLAR_LONGWAVE_RADIATION, "MEAN_SOLAR_LONGWAVE_RADIATION"},

    {EAC_MEAN_SSNL_HIGH_WATER_DEPTH, "MEAN_SSNL_HIGH_WATER_DEPTH"},

    {EAC_MEAN_SSNL_HIGH_WATER_SPEED, "MEAN_SSNL_HIGH_WATER_SPEED"},

    {EAC_MEAN_SSNL_LOW_WATER_DEPTH, "MEAN_SSNL_LOW_WATER_DEPTH"},

    {EAC_MEAN_SSNL_LOW_WATER_SPEED, "MEAN_SSNL_LOW_WATER_SPEED"},

    {EAC_MEAN_STEM_DIAMETER, "MEAN_STEM_DIAMETER"},

    {EAC_MEAN_STEM_SPACING, "MEAN_STEM_SPACING"},

    {EAC_MEAN_SWELL_WAVE_DIRECTION, "MEAN_SWELL_WAVE_DIRECTION"},

    {EAC_MEAN_SWELL_WAVE_HEIGHT, "MEAN_SWELL_WAVE_HEIGHT"},

    {EAC_MEAN_SWELL_WAVE_PERIOD, "MEAN_SWELL_WAVE_PERIOD"},

    {EAC_MEAN_TERRAIN_ELEVATION, "MEAN_TERRAIN_ELEVATION"},

    {EAC_MEAN_TERRAIN_ELEVATION_STD_DEV, "MEAN_TERRAIN_ELEVATION_STD_DEV"},

    {EAC_MEAN_TIDAL_WATER_DEPTH, "MEAN_TIDAL_WATER_DEPTH"},

    {EAC_MEAN_WATER_DEPTH, "MEAN_WATER_DEPTH"},

    {EAC_MEAN_WATER_SPEED, "MEAN_WATER_SPEED"},

    {EAC_MEAN_WATERBODY_TEMP_STD_DEV, "MEAN_WATERBODY_TEMP_STD_DEV"},

    {EAC_MEAN_WATERBODY_TEMPERATURE, "MEAN_WATERBODY_TEMPERATURE"},

    {EAC_MEAN_WAVE_DIRECTION, "MEAN_WAVE_DIRECTION"},

    {EAC_MEAN_WAVE_HEIGHT, "MEAN_WAVE_HEIGHT"},

    {EAC_MEAN_WAVE_HEIGHT_STD_DEV, "MEAN_WAVE_HEIGHT_STD_DEV"},

    {EAC_MEAN_WAVE_LENGTH, "MEAN_WAVE_LENGTH"},

    {EAC_MEAN_WAVE_PERIOD, "MEAN_WAVE_PERIOD"},

    {EAC_MEAN_WIND_SPEED, "MEAN_WIND_SPEED"},

    {EAC_MEAN_WIND_SPEED_STD_DEV, "MEAN_WIND_SPEED_STD_DEV"},

    {EAC_MEAN_WIND_WAVE_HEIGHT, "MEAN_WIND_WAVE_HEIGHT"},

    {EAC_MEAN_WIND_WAVE_PERIOD, "MEAN_WIND_WAVE_PERIOD"},

    {EAC_MEASUREMENT_DEPTH, "MEASUREMENT_DEPTH"},

    {EAC_MEASUREMENT_HEIGHT, "MEASUREMENT_HEIGHT"},

    {EAC_MERCHANT_MARINE_VESSEL_TYPE, "MERCHANT_MARINE_VESSEL_TYPE"},

    {EAC_MERCHANT_VESSEL_DENSITY, "MERCHANT_VESSEL_DENSITY"},

    {EAC_MET_TRANSMISSITIVITY_DISTANCE, "MET_TRANSMISSITIVITY_DISTANCE"},

    {EAC_MET_TRANSMISSITIVITY_WAVELENGTH, "MET_TRANSMISSITIVITY_WAVELENGTH"},

    {EAC_METEOROLOGICAL_RANGE, "METEOROLOGICAL_RANGE"},

    {EAC_METERED_PARKING, "METERED_PARKING"},

    {EAC_MIDDLE_CLOUD_BASE_LEVEL, "MIDDLE_CLOUD_BASE_LEVEL"},

    {EAC_MIDDLE_CLOUD_COVERAGE, "MIDDLE_CLOUD_COVERAGE"},

    {EAC_MIDDLE_CLOUD_GENUS, "MIDDLE_CLOUD_GENUS"},

    {EAC_MIDDLE_CLOUD_TOP_LEVEL, "MIDDLE_CLOUD_TOP_LEVEL"},

    {EAC_MIDDLE_CLOUD_TYPE_OBSERVED, "MIDDLE_CLOUD_TYPE_OBSERVED"},

    {EAC_MILITARY_ASSET_TYPE, "MILITARY_ASSET_TYPE"},

    {EAC_MILITARY_BRIDGE_INFORMATION, "MILITARY_BRIDGE_INFORMATION"},

    {EAC_MILITARY_FORCE_ALLEGIANCE, "MILITARY_FORCE_ALLEGIANCE"},

    {EAC_MILITARY_USE, "MILITARY_USE"},

    {EAC_MIN_WATERBODY_TEMP_1_STD_DEV, "MIN_WATERBODY_TEMP_1_STD_DEV"},

    {EAC_MIN_WATERBODY_TEMP_2_STD_DEV, "MIN_WATERBODY_TEMP_2_STD_DEV"},

    {EAC_MIN_WATERBODY_TEMP_3_STD_DEV, "MIN_WATERBODY_TEMP_3_STD_DEV"},

    {EAC_MINE_ACOUSTIC_ACTUATION, "MINE_ACOUSTIC_ACTUATION"},

    {EAC_MINE_ACTUATION, "MINE_ACTUATION"},

    {EAC_MINE_ALLEGIANCE, "MINE_ALLEGIANCE"},

    {EAC_MINE_ANTI_HUNTING_TYPE, "MINE_ANTI_HUNTING_TYPE"},

    {EAC_MINE_ANTI_RECOVERY_TYPE, "MINE_ANTI_RECOVERY_TYPE"},

    {EAC_MINE_ANTI_SWEEP_WIRE_TYPE, "MINE_ANTI_SWEEP_WIRE_TYPE"},

    {EAC_MINE_CABLELESS_ACTUATION, "MINE_CABLELESS_ACTUATION"},

    {EAC_MINE_CAPABILITY_TYPE, "MINE_CAPABILITY_TYPE"},

    {EAC_MINE_CHARGE_SIZE, "MINE_CHARGE_SIZE"},

    {EAC_MINE_CONTACT_ACTUATION, "MINE_CONTACT_ACTUATION"},

    {EAC_MINE_CONTROL_METHOD, "MINE_CONTROL_METHOD"},

    {EAC_MINE_COUNT, "MINE_COUNT"},

    {EAC_MINE_COUNTERMEASURE_VESSEL_TYPE, "MINE_COUNTERMEASURE_VESSEL_TYPE"},

    {EAC_MINE_INDEPENDENT_ACTUATION, "MINE_INDEPENDENT_ACTUATION"},

    {EAC_MINE_INFLUENCE_ACTUATION, "MINE_INFLUENCE_ACTUATION"},

    {EAC_MINE_INFORMATION_TYPE, "MINE_INFORMATION_TYPE"},

    {EAC_MINE_MAGNETIC_SENSITIVITY, "MINE_MAGNETIC_SENSITIVITY"},

    {EAC_MINE_MOORED_POSITION_TYPE, "MINE_MOORED_POSITION_TYPE"},

    {EAC_MINE_OPERATIONAL_USE, "MINE_OPERATIONAL_USE"},

    {EAC_MINE_OTHER_ACTUATION_TYPE, "MINE_OTHER_ACTUATION_TYPE"},

    {EAC_MINE_OTHER_INFORMATION_TYPE, "MINE_OTHER_INFORMATION_TYPE"},

    {EAC_MINE_POSITION_TYPE, "MINE_POSITION_TYPE"},

    {EAC_MINE_SPECIAL_CAPABILITY_TYPE, "MINE_SPECIAL_CAPABILITY_TYPE"},

    {EAC_MINE_STATUS, "MINE_STATUS"},

    {EAC_MINE_SWEPT, "MINE_SWEPT"},

    {EAC_MINE_TACTICAL_USE, "MINE_TACTICAL_USE"},

    {EAC_MINE_TRACK_IDENTIFIER, "MINE_TRACK_IDENTIFIER"},

    {EAC_MINEFIELD_DELIVERY_METHOD, "MINEFIELD_DELIVERY_METHOD"},

    {EAC_MINEFIELD_TYPE, "MINEFIELD_TYPE"},

    {EAC_MINIMUM_AIR_TEMPERATURE, "MINIMUM_AIR_TEMPERATURE"},

    {EAC_MINIMUM_AIR_TEMPERATURE_PERIOD, "MINIMUM_AIR_TEMPERATURE_PERIOD"},

    {EAC_MINIMUM_CONTOUR_DEPTH, "MINIMUM_CONTOUR_DEPTH"},

    {EAC_MINIMUM_CURRENT_SPEED, "MINIMUM_CURRENT_SPEED"},

    {EAC_MINIMUM_DEW_POINT_TEMPERATURE, "MINIMUM_DEW_POINT_TEMPERATURE"},

    {EAC_MINIMUM_ENROUTE_ALTITUDE, "MINIMUM_ENROUTE_ALTITUDE"},

    {EAC_MINIMUM_FLIGHT_LEVEL, "MINIMUM_FLIGHT_LEVEL"},

    {EAC_MINIMUM_ICE_KEEL_DRAFT, "MINIMUM_ICE_KEEL_DRAFT"},

    {EAC_MINIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL, "MINIMUM_OMNIDIR_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL"},

    {EAC_MINIMUM_SAFE_ALTITUDE, "MINIMUM_SAFE_ALTITUDE"},

    {EAC_MINIMUM_TERRAIN_ELEVATION, "MINIMUM_TERRAIN_ELEVATION"},

    {EAC_MINUTE_WITHIN_DAY, "MINUTE_WITHIN_DAY"},

    {EAC_MINUTE_WITHIN_HOUR, "MINUTE_WITHIN_HOUR"},

    {EAC_MISSILE_SITE_TYPE, "MISSILE_SITE_TYPE"},

    {EAC_MISSING_INFORMATION_TYPE, "MISSING_INFORMATION_TYPE"},

    {EAC_MISSION_SPECIFIC_DAMAGE_FRACTION, "MISSION_SPECIFIC_DAMAGE_FRACTION"},

    {EAC_MIXING_LAYER_DEPTH, "MIXING_LAYER_DEPTH"},

    {EAC_MIXING_LAYER_DEPTH_STD_DEV, "MIXING_LAYER_DEPTH_STD_DEV"},

    {EAC_MIXING_LAYER_TEMP_GRAD, "MIXING_LAYER_TEMP_GRAD"},

    {EAC_MIXING_LAYER_TEMP_GRAD_STD_DEV, "MIXING_LAYER_TEMP_GRAD_STD_DEV"},

    {EAC_MIXING_RATIO, "MIXING_RATIO"},

    {EAC_MODIFIED_SURF_INDEX, "MODIFIED_SURF_INDEX"},

    {EAC_MODULUS_OF_ELASTICITY, "MODULUS_OF_ELASTICITY"},

    {EAC_MONITORED, "MONITORED"},

    {EAC_MONTH, "MONTH"},

    {EAC_MOON_PHASE, "MOON_PHASE"},

    {EAC_MOON_PHASE_COUNT, "MOON_PHASE_COUNT"},

    {EAC_MOON_PHASE_TIME, "MOON_PHASE_TIME"},

    {EAC_MOONRISE_TIME, "MOONRISE_TIME"},

    {EAC_MOONSET_TIME, "MOONSET_TIME"},

    {EAC_MOORING_CONNECTION_TYPE, "MOORING_CONNECTION_TYPE"},

    {EAC_MOORING_FACILITY_TYPE, "MOORING_FACILITY_TYPE"},

    {EAC_MOVEMENT_INDUCED_CONTRAIL_PRODUCTION_RATE, "MOVEMENT_INDUCED_CONTRAIL_PRODUCTION_RATE"},

    {EAC_MULTIPASS_SURFACE_DEGRADATION, "MULTIPASS_SURFACE_DEGRADATION"},

    {EAC_MULTIPLE, "MULTIPLE"},

    {EAC_MULTIPLE_OBSTRUCTION_LIGHTS, "MULTIPLE_OBSTRUCTION_LIGHTS"},

    {EAC_MUNITION_BURST_COUNT, "MUNITION_BURST_COUNT"},

    {EAC_MUNITION_FUSE_TYPE, "MUNITION_FUSE_TYPE"},

    {EAC_MUNITION_PROTECTION_LEVEL, "MUNITION_PROTECTION_LEVEL"},

    {EAC_NAME, "NAME"},

    {EAC_NATIONAL_PAINT_SCHEME, "NATIONAL_PAINT_SCHEME"},

    {EAC_NATIONAL_PAINT_SCHEME_VALUE_SET, "NATIONAL_PAINT_SCHEME_VALUE_SET"},

    {EAC_NATIVE_SETTLEMENT_TYPE, "NATIVE_SETTLEMENT_TYPE"},

    {EAC_NAUTICAL_GATE_TYPE, "NAUTICAL_GATE_TYPE"},

    {EAC_NAVIGABLE_STATUS, "NAVIGABLE_STATUS"},

    {EAC_NAVIGATION_LIGHT_INTENSITY, "NAVIGATION_LIGHT_INTENSITY"},

    {EAC_NAVIGATION_PATH_TYPE, "NAVIGATION_PATH_TYPE"},

    {EAC_NAVIGATION_SYSTEM_TYPE, "NAVIGATION_SYSTEM_TYPE"},

    {EAC_NOMINAL_LIGHT_RANGE, "NOMINAL_LIGHT_RANGE"},

    {EAC_NON_REGULATORY_AIRSPACE_CLASS, "NON_REGULATORY_AIRSPACE_CLASS"},

    {EAC_NON_SUB_CONTACT_DATE, "NON_SUB_CONTACT_DATE"},

    {EAC_NON_SUB_CONTACT_POSITION_ACCURACY, "NON_SUB_CONTACT_POSITION_ACCURACY"},

    {EAC_NON_SUB_CONTACT_SOURCE, "NON_SUB_CONTACT_SOURCE"},

    {EAC_NON_SUB_CONTACT_SOURCE_TYPE, "NON_SUB_CONTACT_SOURCE_TYPE"},

    {EAC_NON_SUB_CONTACT_WRECK_IDENTIFIER, "NON_SUB_CONTACT_WRECK_IDENTIFIER"},

    {EAC_NULL, "NULL"},

    {EAC_NUMERIC_IDENTIFIER, "NUMERIC_IDENTIFIER"},

    {EAC_NUMERIC_OBJECT_IDENTIFIER, "NUMERIC_OBJECT_IDENTIFIER"},

    {EAC_OBJECT_ASPECT, "OBJECT_ASPECT"},

    {EAC_OBJECT_BASE_HEIGHT, "OBJECT_BASE_HEIGHT"},

    {EAC_OBJECT_BEARING_GEODETIC, "OBJECT_BEARING_GEODETIC"},

    {EAC_OBJECT_CONFIGURATION, "OBJECT_CONFIGURATION"},

    {EAC_OBJECT_CONFIGURATION_QUALITY, "OBJECT_CONFIGURATION_QUALITY"},

    {EAC_OBJECT_ELEMENT_GEODETIC_ORIENTATION, "OBJECT_ELEMENT_GEODETIC_ORIENTATION"},

    {EAC_OBJECT_IDENTIFICATION_BASE_NUMBER, "OBJECT_IDENTIFICATION_BASE_NUMBER"},

    {EAC_OBJECT_LABEL, "OBJECT_LABEL"},

    {EAC_OBJECT_ORDINAL_RANK, "OBJECT_ORDINAL_RANK"},

    {EAC_OBJECT_ORIENTATION_WRT_VERTICAL, "OBJECT_ORIENTATION_WRT_VERTICAL"},

    {EAC_OBJECT_POLYGONAL_FACE_SHAPE, "OBJECT_POLYGONAL_FACE_SHAPE"},

    {EAC_OBJECT_RATE, "OBJECT_RATE"},

    {EAC_OBJECT_SET_TYPE, "OBJECT_SET_TYPE"},

    {EAC_OBJECT_SHADED, "OBJECT_SHADED"},

    {EAC_OBJECT_SKY_IRRADIANCE, "OBJECT_SKY_IRRADIANCE"},

    {EAC_OBJECT_TRANSMITTANCE_FRACTION, "OBJECT_TRANSMITTANCE_FRACTION"},

    {EAC_OBJECT_TYPE_DENSITY, "OBJECT_TYPE_DENSITY"},

    {EAC_OBJECT_VARIANT, "OBJECT_VARIANT"},

    {EAC_OBJECT_VERTICAL_DISPLACEMENT, "OBJECT_VERTICAL_DISPLACEMENT"},

    {EAC_OBSCURANT_TYPE, "OBSCURANT_TYPE"},

    {EAC_OBSERVATION_DECK_PRESENT, "OBSERVATION_DECK_PRESENT"},

    {EAC_OBSERVATION_PLATFORM_TYPE, "OBSERVATION_PLATFORM_TYPE"},

    {EAC_OBSERVATION_TIME_EPOCH_1970, "OBSERVATION_TIME_EPOCH_1970"},

    {EAC_OBSERVED_VISIBILITY_REPORT_TYPE, "OBSERVED_VISIBILITY_REPORT_TYPE"},

    {EAC_OCEAN_CURRENT_EAST_SPEED, "OCEAN_CURRENT_EAST_SPEED"},

    {EAC_OCEAN_CURRENT_NORTH_SPEED, "OCEAN_CURRENT_NORTH_SPEED"},

    {EAC_OCEAN_CURRENT_U, "OCEAN_CURRENT_U"},

    {EAC_OCEAN_CURRENT_U_SPEED, "OCEAN_CURRENT_U_SPEED"},

    {EAC_OCEAN_CURRENT_V, "OCEAN_CURRENT_V"},

    {EAC_OCEAN_CURRENT_V_SPEED, "OCEAN_CURRENT_V_SPEED"},

    {EAC_OCEAN_CURRENT_W, "OCEAN_CURRENT_W"},

    {EAC_OCEAN_ELECTRICAL_CONDUCTIVITY_RATIO, "OCEAN_ELECTRICAL_CONDUCTIVITY_RATIO"},

    {EAC_OCEAN_FLOOR_REGION_NAME, "OCEAN_FLOOR_REGION_NAME"},

    {EAC_OCEAN_FLOOR_REGION_NAME_TYPE, "OCEAN_FLOOR_REGION_NAME_TYPE"},

    {EAC_OCEAN_NAME, "OCEAN_NAME"},

    {EAC_OFFSHORE_PLATFORM_TYPE, "OFFSHORE_PLATFORM_TYPE"},

    {EAC_OIL_BARRIER_TYPE, "OIL_BARRIER_TYPE"},

    {EAC_OILRIG_PRESENT, "OILRIG_PRESENT"},

    {EAC_OMNIDIR_SHIP_NOISE_CONFIDENCE, "OMNIDIR_SHIP_NOISE_CONFIDENCE"},

    {EAC_OMNIDIR_SHIP_NOISE_CORRECTION, "OMNIDIR_SHIP_NOISE_CORRECTION"},

    {EAC_OMNIDIR_SHIP_NOISE_DECORRELATION_TIME, "OMNIDIR_SHIP_NOISE_DECORRELATION_TIME"},

    {EAC_OMNIDIR_SHIP_NOISE_SPATIAL_VARIATION, "OMNIDIR_SHIP_NOISE_SPATIAL_VARIATION"},

    {EAC_OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL, "OMNIDIR_SHIP_NOISE_SPCT_PWR_LVL"},

    {EAC_OPACITY, "OPACITY"},

    {EAC_OPERATING_RESTRICTIONS_TYPE, "OPERATING_RESTRICTIONS_TYPE"},

    {EAC_OPERATING_TIME, "OPERATING_TIME"},

    {EAC_OPERATIONAL, "OPERATIONAL"},

    {EAC_OPTICAL_TURBULENCE_INTENSITY, "OPTICAL_TURBULENCE_INTENSITY"},

    {EAC_ORIENTATION_ANGLE, "ORIENTATION_ANGLE"},

    {EAC_OUTSIDE_DIAMETER, "OUTSIDE_DIAMETER"},

    {EAC_OVERALL_BRIDGE_HEIGHT, "OVERALL_BRIDGE_HEIGHT"},

    {EAC_OVERALL_VERTICAL_DIMENSION, "OVERALL_VERTICAL_DIMENSION"},

    {EAC_OVERHEAD_CLEARANCE, "OVERHEAD_CLEARANCE"},

    {EAC_OVERHEAD_COVER, "OVERHEAD_COVER"},

    {EAC_OVERHEAD_OBSTRUCTED, "OVERHEAD_OBSTRUCTED"},

    {EAC_OVERHEAD_OBSTRUCTION_TYPE, "OVERHEAD_OBSTRUCTION_TYPE"},

    {EAC_PARALLEL_LINE_COUNT, "PARALLEL_LINE_COUNT"},

    {EAC_PARAPET_TYPE, "PARAPET_TYPE"},

    {EAC_PARTICLE_ENERGY, "PARTICLE_ENERGY"},

    {EAC_PARTITIONED_WATERBODY, "PARTITIONED_WATERBODY"},

    {EAC_PASQUILL_ATMOSPHERE_STABILITY_INDEX, "PASQUILL_ATMOSPHERE_STABILITY_INDEX"},

    {EAC_PASSAGE_BLOCKED, "PASSAGE_BLOCKED"},

    {EAC_PASSIVE_ACOUSTIC, "PASSIVE_ACOUSTIC"},

    {EAC_PATH_COUNT, "PATH_COUNT"},

    {EAC_PATROL_CRAFT_TYPE, "PATROL_CRAFT_TYPE"},

    {EAC_PEAK_TIDE_HEIGHT, "PEAK_TIDE_HEIGHT"},

    {EAC_PEAK_TIDE_TIME, "PEAK_TIDE_TIME"},

    {EAC_PEAK_TIDE_TYPE, "PEAK_TIDE_TYPE"},

    {EAC_PEDESTRIAN_CAPACITY, "PEDESTRIAN_CAPACITY"},

    {EAC_PEDESTRIAN_RATE, "PEDESTRIAN_RATE"},

    {EAC_PEDESTRIAN_TRAVERSABILITY, "PEDESTRIAN_TRAVERSABILITY"},

    {EAC_PERIODIC_CYCLE_TIME, "PERIODIC_CYCLE_TIME"},

    {EAC_PERIODIC_END_DATE, "PERIODIC_END_DATE"},

    {EAC_PERIODIC_RESTRICTION_END, "PERIODIC_RESTRICTION_END"},

    {EAC_PERIODIC_RESTRICTION_START, "PERIODIC_RESTRICTION_START"},

    {EAC_PERIODIC_RESTRICTION_TYPE, "PERIODIC_RESTRICTION_TYPE"},

    {EAC_PERIODIC_START_DATE, "PERIODIC_START_DATE"},

    {EAC_PERMANENT, "PERMANENT"},

    {EAC_PH, "PH"},

    {EAC_PHYSICAL_OBSTRUCTION, "PHYSICAL_OBSTRUCTION"},

    {EAC_PHYSICAL_STATE, "PHYSICAL_STATE"},

    {EAC_PICTORIAL_RESOURCE_REQUEST, "PICTORIAL_RESOURCE_REQUEST"},

    {EAC_PIPE_CONSTRUCTION_MATERIAL_TYPE, "PIPE_CONSTRUCTION_MATERIAL_TYPE"},

    {EAC_PIPELINE_TYPE, "PIPELINE_TYPE"},

    {EAC_PITCH_ANGLE, "PITCH_ANGLE"},

    {EAC_PLANETARY_SRF_DEW_POINT_DEPRESSION, "PLANETARY_SRF_DEW_POINT_DEPRESSION"},

    {EAC_PLANETARY_SRF_DEW_POINT_TEMPERATURE, "PLANETARY_SRF_DEW_POINT_TEMPERATURE"},

    {EAC_PLANETARY_SURFACE_AIR_TEMPERATURE, "PLANETARY_SURFACE_AIR_TEMPERATURE"},

    {EAC_PLANETARY_SURFACE_ATM_PRESSURE, "PLANETARY_SURFACE_ATM_PRESSURE"},

    {EAC_PLANETARY_SURFACE_ILLUMINANCE_LEVEL, "PLANETARY_SURFACE_ILLUMINANCE_LEVEL"},

    {EAC_PLANETARY_SURFACE_TEMPERATURE, "PLANETARY_SURFACE_TEMPERATURE"},

    {EAC_PLANT_COMPONENT_TYPE, "PLANT_COMPONENT_TYPE"},

    {EAC_PLATFORM_COUNT, "PLATFORM_COUNT"},

    {EAC_PLATOON_ACCOMMODATION_AVAILABILITY_COUNT, "PLATOON_ACCOMMODATION_AVAILABILITY_COUNT"},

    {EAC_PLATOON_ACCOMMODATION_CAPACITY, "PLATOON_ACCOMMODATION_CAPACITY"},

    {EAC_PLUNGING_BREAKER_FRACTION, "PLUNGING_BREAKER_FRACTION"},

    {EAC_POINT_OBJECT_TYPE, "POINT_OBJECT_TYPE"},

    {EAC_POISSON_RATIO, "POISSON_RATIO"},

    {EAC_POLYGONAL_FACE_TYPE, "POLYGONAL_FACE_TYPE"},

    {EAC_POND_TYPE, "POND_TYPE"},

    {EAC_POPULATED_PLACE_TYPE, "POPULATED_PLACE_TYPE"},

    {EAC_POPULATION, "POPULATION"},

    {EAC_POSTURE, "POSTURE"},

    {EAC_POTENTIAL_AIR_TEMPERATURE, "POTENTIAL_AIR_TEMPERATURE"},

    {EAC_POTENTIAL_TEMP_INVRSN_LAYER_LAPSE_RATE, "POTENTIAL_TEMP_INVRSN_LAYER_LAPSE_RATE"},

    {EAC_POTENTIAL_TEMPERATURE_BASE_INVERSION_LAYER, "POTENTIAL_TEMPERATURE_BASE_INVERSION_LAYER"},

    {EAC_POTENTIAL_TEMPERATURE_LAPSE_RATE, "POTENTIAL_TEMPERATURE_LAPSE_RATE"},

    {EAC_POTENTIAL_TEMPERATURE_TOP_INVERSION_LAYER, "POTENTIAL_TEMPERATURE_TOP_INVERSION_LAYER"},

    {EAC_POWER_GENERATING_CAPACITY, "POWER_GENERATING_CAPACITY"},

    {EAC_POWER_GENERATION_RATE, "POWER_GENERATION_RATE"},

    {EAC_POWER_PLANT_TYPE, "POWER_PLANT_TYPE"},

    {EAC_PRACTICAL_SALINITY, "PRACTICAL_SALINITY"},

    {EAC_PRANDTL_NUMBER, "PRANDTL_NUMBER"},

    {EAC_PRECIPITABLE_WATER, "PRECIPITABLE_WATER"},

    {EAC_PRECIPITABLE_WATER_TOTAL, "PRECIPITABLE_WATER_TOTAL"},

    {EAC_PRECIPITATION_INTENSITY, "PRECIPITATION_INTENSITY"},

    {EAC_PRECIPITATION_NOISE_POWER_LEVEL, "PRECIPITATION_NOISE_POWER_LEVEL"},

    {EAC_PRECIPITATION_PERIOD, "PRECIPITATION_PERIOD"},

    {EAC_PRECIPITATION_PHASE, "PRECIPITATION_PHASE"},

    {EAC_PRECIPITATION_RATE, "PRECIPITATION_RATE"},

    {EAC_PRECIPITATION_TYPE, "PRECIPITATION_TYPE"},

    {EAC_PREDOMINANT_DEPTH_WITHIN_OBJECT, "PREDOMINANT_DEPTH_WITHIN_OBJECT"},

    {EAC_PREDOMINANT_HEIGHT, "PREDOMINANT_HEIGHT"},

    {EAC_PREDOMINANT_HEIGHT_WITHIN_OBJECT, "PREDOMINANT_HEIGHT_WITHIN_OBJECT"},

    {EAC_PREDOMINANT_SURROUND_TYPE, "PREDOMINANT_SURROUND_TYPE"},

    {EAC_PREDOMINANT_VEGETATION_HEIGHT, "PREDOMINANT_VEGETATION_HEIGHT"},

    {EAC_PREDOMINANT_WATER_DEPTH, "PREDOMINANT_WATER_DEPTH"},

    {EAC_PREPARED_EXPLOSIVE_DESTRUCTION_COMPLETION_FRACTION, "PREPARED_EXPLOSIVE_DESTRUCTION_COMPLETION_FRACTION"},

    {EAC_PRESENT_WEATHER_TYPE_AUTOMATED, "PRESENT_WEATHER_TYPE_AUTOMATED"},

    {EAC_PRESENT_WEATHER_TYPE_MANUAL, "PRESENT_WEATHER_TYPE_MANUAL"},

    {EAC_PRESENT_WEATHER_TYPE_SPECIAL, "PRESENT_WEATHER_TYPE_SPECIAL"},

    {EAC_PRESSURE_ALTIMETER_QUALITY, "PRESSURE_ALTIMETER_QUALITY"},

    {EAC_PRESSURE_ALTIMETER_SETTING, "PRESSURE_ALTIMETER_SETTING"},

    {EAC_PRESSURE_ALTITUDE, "PRESSURE_ALTITUDE"},

    {EAC_PRI_WEAPON_DEPLOYED_POS_CATEGORY, "PRI_WEAPON_DEPLOYED_POS_CATEGORY"},

    {EAC_PRI_WEAPON_DEPLOYED_POSITION, "PRI_WEAPON_DEPLOYED_POSITION"},

    {EAC_PRIMARY, "PRIMARY"},

    {EAC_PRIMARY_AERIAL_DEPLOYED_POSITION, "PRIMARY_AERIAL_DEPLOYED_POSITION"},

    {EAC_PRIMARY_AXIS_VELOCITY_COMPONENT, "PRIMARY_AXIS_VELOCITY_COMPONENT"},

    {EAC_PRIMARY_BREAKER_AZIMUTH, "PRIMARY_BREAKER_AZIMUTH"},

    {EAC_PRIMARY_BREAKER_RELATIVE_ANGLE, "PRIMARY_BREAKER_RELATIVE_ANGLE"},

    {EAC_PRIMARY_BROADCAST_FREQUENCY, "PRIMARY_BROADCAST_FREQUENCY"},

    {EAC_PRIMARY_BYPRODUCT, "PRIMARY_BYPRODUCT"},

    {EAC_PRIMARY_DOOR_OPEN_POSITION, "PRIMARY_DOOR_OPEN_POSITION"},

    {EAC_PRIMARY_ENTRANCE_LOCATION, "PRIMARY_ENTRANCE_LOCATION"},

    {EAC_PRIMARY_MATERIAL_TYPE, "PRIMARY_MATERIAL_TYPE"},

    {EAC_PRIMARY_OPERATING_AGENCY_IDENTIFIER, "PRIMARY_OPERATING_AGENCY_IDENTIFIER"},

    {EAC_PRIMARY_PRODUCT, "PRIMARY_PRODUCT"},

    {EAC_PRIMARY_RAW_MATERIAL, "PRIMARY_RAW_MATERIAL"},

    {EAC_PRIMARY_SURFACE_AIR_VELOCITY, "PRIMARY_SURFACE_AIR_VELOCITY"},

    {EAC_PRIMARY_SURFACE_TEMPERATURE, "PRIMARY_SURFACE_TEMPERATURE"},

    {EAC_PRIMARY_SURFACE_THERMAL_CONDITION, "PRIMARY_SURFACE_THERMAL_CONDITION"},

    {EAC_PRIMARY_SWELL_WAVE_DIRECTION, "PRIMARY_SWELL_WAVE_DIRECTION"},

    {EAC_PRIMARY_SWELL_WAVE_HEIGHT, "PRIMARY_SWELL_WAVE_HEIGHT"},

    {EAC_PRIMARY_SWELL_WAVE_PERIOD, "PRIMARY_SWELL_WAVE_PERIOD"},

    {EAC_PRIMARY_WAVE_DIRECTION, "PRIMARY_WAVE_DIRECTION"},

    {EAC_PRIORITY, "PRIORITY"},

    {EAC_PROCESSING_NAME, "PROCESSING_NAME"},

    {EAC_PROPERTY_SET_DATA_SOURCE, "PROPERTY_SET_DATA_SOURCE"},

    {EAC_PROPERTY_SET_SPATIAL_DOMAIN, "PROPERTY_SET_SPATIAL_DOMAIN"},

    {EAC_PROPERTY_SET_VALID_TIME, "PROPERTY_SET_VALID_TIME"},

    {EAC_PROTECTION_SHED_TYPE, "PROTECTION_SHED_TYPE"},

    {EAC_PUBLIC_ACCOMMODATION_TYPE, "PUBLIC_ACCOMMODATION_TYPE"},

    {EAC_PUBLICATION_REFERENCE, "PUBLICATION_REFERENCE"},

    {EAC_RADAR_BEACON_FREQUENCY, "RADAR_BEACON_FREQUENCY"},

    {EAC_RADAR_CROSS_SECTION, "RADAR_CROSS_SECTION"},

    {EAC_RADAR_REFLECTOR_ANGLE, "RADAR_REFLECTOR_ANGLE"},

    {EAC_RADAR_REFLECTOR_PRESENT, "RADAR_REFLECTOR_PRESENT"},

    {EAC_RADAR_SIGNIFICANCE_FACTOR, "RADAR_SIGNIFICANCE_FACTOR"},

    {EAC_RADAR_STATION_TYPE, "RADAR_STATION_TYPE"},

    {EAC_RADAR_TERRAIN_CLUTTER, "RADAR_TERRAIN_CLUTTER"},

    {EAC_RADAR_TRANSPONDER_TYPE, "RADAR_TRANSPONDER_TYPE"},

    {EAC_RADAR_WATERBODY_SURFACE_CLUTTER, "RADAR_WATERBODY_SURFACE_CLUTTER"},

    {EAC_RADIANCE, "RADIANCE"},

    {EAC_RADIANCE_FLUCTUATION_24_HOUR, "RADIANCE_FLUCTUATION_24_HOUR"},

    {EAC_RADIANCE_PHASE, "RADIANCE_PHASE"},

    {EAC_RADIANT_FLUX_DENSITY, "RADIANT_FLUX_DENSITY"},

    {EAC_RADIATIVE_FLUX_DOWNWELLING, "RADIATIVE_FLUX_DOWNWELLING"},

    {EAC_RADIATIVE_FLUX_UPWELLING, "RADIATIVE_FLUX_UPWELLING"},

    {EAC_RADIO_STATION_TYPE, "RADIO_STATION_TYPE"},

    {EAC_RADIOLOGIC_AGENT_ATM_CONCENTRATION, "RADIOLOGIC_AGENT_ATM_CONCENTRATION"},

    {EAC_RADIOLOGIC_AGENT_SURFACE_CONCENTRATION, "RADIOLOGIC_AGENT_SURFACE_CONCENTRATION"},

    {EAC_RADIOLOGIC_AGENT_TYPE, "RADIOLOGIC_AGENT_TYPE"},

    {EAC_RADIOLOGIC_MASS, "RADIOLOGIC_MASS"},

    {EAC_RADIUS, "RADIUS"},

    {EAC_RAILING_HEIGHT, "RAILING_HEIGHT"},

    {EAC_RAILING_TYPE, "RAILING_TYPE"},

    {EAC_RAILWAY_GAUGE, "RAILWAY_GAUGE"},

    {EAC_RAILWAY_GAUGE_CATEGORY, "RAILWAY_GAUGE_CATEGORY"},

    {EAC_RAILWAY_MAXIMUM_AXLE_LOAD, "RAILWAY_MAXIMUM_AXLE_LOAD"},

    {EAC_RAILWAY_MAXIMUM_LOAD, "RAILWAY_MAXIMUM_LOAD"},

    {EAC_RAILWAY_POWER_SOURCE, "RAILWAY_POWER_SOURCE"},

    {EAC_RAILWAY_TRACK_ARRANGEMENT, "RAILWAY_TRACK_ARRANGEMENT"},

    {EAC_RAILWAY_TYPE, "RAILWAY_TYPE"},

    {EAC_RAMP_DEPLOYED_POSITION, "RAMP_DEPLOYED_POSITION"},

    {EAC_RAPID_CLASS, "RAPID_CLASS"},

    {EAC_RECEIVED_AMBIENT_LIGHT_SCALED_INTENSITY, "RECEIVED_AMBIENT_LIGHT_SCALED_INTENSITY"},

    {EAC_RECEIVED_DIFFUSE_LIGHT_SCALED_INTENSITY, "RECEIVED_DIFFUSE_LIGHT_SCALED_INTENSITY"},

    {EAC_RECEIVED_SPECULAR_LIGHT_SCALED_INTENSITY, "RECEIVED_SPECULAR_LIGHT_SCALED_INTENSITY"},

    {EAC_RECOMMENDED_TRACK, "RECOMMENDED_TRACK"},

    {EAC_RECORDING_DATE, "RECORDING_DATE"},

    {EAC_RECORDING_DATE_TYPE, "RECORDING_DATE_TYPE"},

    {EAC_REFLECTANCE_AZIMUTH_GEODETIC, "REFLECTANCE_AZIMUTH_GEODETIC"},

    {EAC_REFLECTANCE_AZIMUTH_LOCAL, "REFLECTANCE_AZIMUTH_LOCAL"},

    {EAC_REFLECTANCE_AZIMUTH_MAGNETIC, "REFLECTANCE_AZIMUTH_MAGNETIC"},

    {EAC_REFLECTANCE_ELEV_ANGLE_HORIZONTAL, "REFLECTANCE_ELEV_ANGLE_HORIZONTAL"},

    {EAC_REFLECTANCE_ELEV_ANGLE_LOCAL, "REFLECTANCE_ELEV_ANGLE_LOCAL"},

    {EAC_REFLECTANCE_ZENITH_ANGLE_LOCAL, "REFLECTANCE_ZENITH_ANGLE_LOCAL"},

    {EAC_REFRACTION_INDEX_IMAGINARY_PART, "REFRACTION_INDEX_IMAGINARY_PART"},

    {EAC_REFRACTION_INDEX_REAL_PART, "REFRACTION_INDEX_REAL_PART"},

    {EAC_REGIONAL_STYLE, "REGIONAL_STYLE"},

    {EAC_REINFORCED, "REINFORCED"},

    {EAC_RELATIVE_HORIZONTAL_ACCURACY, "RELATIVE_HORIZONTAL_ACCURACY"},

    {EAC_RELATIVE_HUMIDITY, "RELATIVE_HUMIDITY"},

    {EAC_RELATIVE_HUMIDITY_ERROR, "RELATIVE_HUMIDITY_ERROR"},

    {EAC_RELATIVE_HUMIDITY_MINIMUM_TEMPERATURE, "RELATIVE_HUMIDITY_MINIMUM_TEMPERATURE"},

    {EAC_RELATIVE_LOCATION, "RELATIVE_LOCATION"},

    {EAC_RELATIVE_ORIENTATION_ANGLE, "RELATIVE_ORIENTATION_ANGLE"},

    {EAC_RELATIVE_VERTICAL_ACCURACY, "RELATIVE_VERTICAL_ACCURACY"},

    {EAC_RELEASABILITY_RESTRICTIONS, "RELEASABILITY_RESTRICTIONS"},

    {EAC_RELIGIOUS_DESIGNATION, "RELIGIOUS_DESIGNATION"},

    {EAC_RESERVOIR_TYPE, "RESERVOIR_TYPE"},

    {EAC_REVERBERATION_NOISE_POWER_LEVEL, "REVERBERATION_NOISE_POWER_LEVEL"},

    {EAC_REYNOLDS_NUMBER, "REYNOLDS_NUMBER"},

    {EAC_RF_DIRECTIVITY, "RF_DIRECTIVITY"},

    {EAC_RF_REFRACTIVE_INDEX_MODIFIED, "RF_REFRACTIVE_INDEX_MODIFIED"},

    {EAC_RGB_COLOUR_BLUE, "RGB_COLOUR_BLUE"},

    {EAC_RGB_COLOUR_GREEN, "RGB_COLOUR_GREEN"},

    {EAC_RGB_COLOUR_RED, "RGB_COLOUR_RED"},

    {EAC_RICHARDSON_NUMBER, "RICHARDSON_NUMBER"},

    {EAC_RIGHT_ABOVE_BANK_ANGLE, "RIGHT_ABOVE_BANK_ANGLE"},

    {EAC_RIGHT_ABOVE_BANK_SLOPE, "RIGHT_ABOVE_BANK_SLOPE"},

    {EAC_RIGHT_BANK_HEIGHT, "RIGHT_BANK_HEIGHT"},

    {EAC_RIGHT_BANK_SLOPE, "RIGHT_BANK_SLOPE"},

    {EAC_RIGHT_BANK_SOIL_CONE_INDEX, "RIGHT_BANK_SOIL_CONE_INDEX"},

    {EAC_RIGHT_BANK_VEGETATION_DENSITY, "RIGHT_BANK_VEGETATION_DENSITY"},

    {EAC_RIGHT_BELOW_BANK_ANGLE, "RIGHT_BELOW_BANK_ANGLE"},

    {EAC_RIGHT_BELOW_BANK_SLOPE, "RIGHT_BELOW_BANK_SLOPE"},

    {EAC_RIGHT_TERRAIN_BANK_SLOPE, "RIGHT_TERRAIN_BANK_SLOPE"},

    {EAC_RIP_CURRENT_PRESENT, "RIP_CURRENT_PRESENT"},

    {EAC_RIP_CURRENT_SPEED, "RIP_CURRENT_SPEED"},

    {EAC_ROAD_ILLUMINATED_WIDTH, "ROAD_ILLUMINATED_WIDTH"},

    {EAC_ROAD_INTERCHANGE_TYPE, "ROAD_INTERCHANGE_TYPE"},

    {EAC_ROAD_JUNCTION_CONNECTIVITY, "ROAD_JUNCTION_CONNECTIVITY"},

    {EAC_ROAD_LANE_ADJACENCY, "ROAD_LANE_ADJACENCY"},

    {EAC_ROAD_LANE_CONTROL_TYPE, "ROAD_LANE_CONTROL_TYPE"},

    {EAC_ROAD_LANE_LIGHT_STATE, "ROAD_LANE_LIGHT_STATE"},

    {EAC_ROAD_LANE_PASSING, "ROAD_LANE_PASSING"},

    {EAC_ROAD_LANE_TURN, "ROAD_LANE_TURN"},

    {EAC_ROAD_LIGHTING_PRESENT, "ROAD_LIGHTING_PRESENT"},

    {EAC_ROAD_MINIMUM_TRAVELLED_WAY_WIDTH, "ROAD_MINIMUM_TRAVELLED_WAY_WIDTH"},

    {EAC_ROAD_SECOND_TRAVELLED_WAY_WIDTH, "ROAD_SECOND_TRAVELLED_WAY_WIDTH"},

    {EAC_ROAD_TOTAL_USABLE_WIDTH, "ROAD_TOTAL_USABLE_WIDTH"},

    {EAC_ROAD_TYPE, "ROAD_TYPE"},

    {EAC_ROCK_FORMATION_STRUCTURE, "ROCK_FORMATION_STRUCTURE"},

    {EAC_ROLL_ANGLE, "ROLL_ANGLE"},

    {EAC_ROLLING_STOCK_TYPE, "ROLLING_STOCK_TYPE"},

    {EAC_ROOF_ASSEMBLY_TYPE, "ROOF_ASSEMBLY_TYPE"},

    {EAC_ROOF_COVER_FRACTION, "ROOF_COVER_FRACTION"},

    {EAC_ROOF_FRAMING_TYPE, "ROOF_FRAMING_TYPE"},

    {EAC_ROOF_LOAD_BEARING_CAPACITY, "ROOF_LOAD_BEARING_CAPACITY"},

    {EAC_ROOF_PREDOMINANT_PATTERN, "ROOF_PREDOMINANT_PATTERN"},

    {EAC_ROOF_PREDOMINANT_SURFACE_MATERIAL, "ROOF_PREDOMINANT_SURFACE_MATERIAL"},

    {EAC_ROOF_SHAPE, "ROOF_SHAPE"},

    {EAC_ROOF_SHEATHING_TYPE, "ROOF_SHEATHING_TYPE"},

    {EAC_ROOF_STYLE, "ROOF_STYLE"},

    {EAC_ROOM_CEILING_CONSTRUCTION_TYPE, "ROOM_CEILING_CONSTRUCTION_TYPE"},

    {EAC_ROOM_CEILING_SHAPE, "ROOM_CEILING_SHAPE"},

    {EAC_ROUTE_ALTERNATIVE_DESIGNATION, "ROUTE_ALTERNATIVE_DESIGNATION"},

    {EAC_ROUTE_CONSTRICTION_TYPE, "ROUTE_CONSTRICTION_TYPE"},

    {EAC_ROUTE_CROSSING_TYPE, "ROUTE_CROSSING_TYPE"},

    {EAC_ROUTE_DESIGNATION, "ROUTE_DESIGNATION"},

    {EAC_ROUTE_EXPANSION_TYPE, "ROUTE_EXPANSION_TYPE"},

    {EAC_ROUTE_WEATHER_TYPE, "ROUTE_WEATHER_TYPE"},

    {EAC_ROW_COUNT, "ROW_COUNT"},

    {EAC_ROW_DISTANCE, "ROW_DISTANCE"},

    {EAC_ROW_SPACING_INTERNAL, "ROW_SPACING_INTERNAL"},

    {EAC_RUBBLE_STABILITY, "RUBBLE_STABILITY"},

    {EAC_RUNWAY_APPROACH_ANGLE_LIGHT_INTENSITY, "RUNWAY_APPROACH_ANGLE_LIGHT_INTENSITY"},

    {EAC_RUNWAY_APPROACH_LIGHT_INTENSITY, "RUNWAY_APPROACH_LIGHT_INTENSITY"},

    {EAC_RUNWAY_APPROACH_OIS_DISTANCE, "RUNWAY_APPROACH_OIS_DISTANCE"},

    {EAC_RUNWAY_CENTRE_LIGHT_INTENSITY, "RUNWAY_CENTRE_LIGHT_INTENSITY"},

    {EAC_RUNWAY_COUNT, "RUNWAY_COUNT"},

    {EAC_RUNWAY_DISPLACED_THRESHOLD_DISTANCE, "RUNWAY_DISPLACED_THRESHOLD_DISTANCE"},

    {EAC_RUNWAY_EDGE_LIGHT_INTENSITY, "RUNWAY_EDGE_LIGHT_INTENSITY"},

    {EAC_RUNWAY_END, "RUNWAY_END"},

    {EAC_RUNWAY_END_BEARING, "RUNWAY_END_BEARING"},

    {EAC_RUNWAY_ENDPOINT_ELEVATION, "RUNWAY_ENDPOINT_ELEVATION"},

    {EAC_RUNWAY_HIGH_END_IDENTIFIER, "RUNWAY_HIGH_END_IDENTIFIER"},

    {EAC_RUNWAY_IDENTIFIER, "RUNWAY_IDENTIFIER"},

    {EAC_RUNWAY_LIGHTING_INTENSITY, "RUNWAY_LIGHTING_INTENSITY"},

    {EAC_RUNWAY_LOW_END_IDENTIFIER, "RUNWAY_LOW_END_IDENTIFIER"},

    {EAC_RUNWAY_OIS_QUADRANT, "RUNWAY_OIS_QUADRANT"},

    {EAC_RUNWAY_POINT_ABEAM_TYPE, "RUNWAY_POINT_ABEAM_TYPE"},

    {EAC_RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS_SECTION, "RUNWAY_PRIMARY_APPROACH_TRANSITIONAL_OIS_SECTION"},

    {EAC_RUNWAY_PRIMARY_OIS_SECTION, "RUNWAY_PRIMARY_OIS_SECTION"},

    {EAC_RUNWAY_REIL_INTENSITY, "RUNWAY_REIL_INTENSITY"},

    {EAC_RUNWAY_RELATIVE_POSITION, "RUNWAY_RELATIVE_POSITION"},

    {EAC_RUNWAY_STOP_BAR_LIGHT_INTENSITY, "RUNWAY_STOP_BAR_LIGHT_INTENSITY"},

    {EAC_RUNWAY_STROBE_LIGHT_INTENSITY, "RUNWAY_STROBE_LIGHT_INTENSITY"},

    {EAC_RUNWAY_SURFACE_CONDITION, "RUNWAY_SURFACE_CONDITION"},

    {EAC_RUNWAY_TAKEOFF_DISTANCE_AVAILABLE, "RUNWAY_TAKEOFF_DISTANCE_AVAILABLE"},

    {EAC_RUNWAY_THRESHOLD_LIGHT_INTENSITY, "RUNWAY_THRESHOLD_LIGHT_INTENSITY"},

    {EAC_RUNWAY_TOUCH_DOWN_LIGHT_INTENSITY, "RUNWAY_TOUCH_DOWN_LIGHT_INTENSITY"},

    {EAC_RUNWAY_TOUCHDOWN_ZONE_ELEVATION, "RUNWAY_TOUCHDOWN_ZONE_ELEVATION"},

    {EAC_RUNWAY_VISIBILITY, "RUNWAY_VISIBILITY"},

    {EAC_RUNWAY_VISUAL_RANGE, "RUNWAY_VISUAL_RANGE"},

    {EAC_SAND_DUNE_ORIENTATION, "SAND_DUNE_ORIENTATION"},

    {EAC_SATELLITE_NAME, "SATELLITE_NAME"},

    {EAC_SCND_WEAPON_DEPLOYED_POS_CATEGORY, "SCND_WEAPON_DEPLOYED_POS_CATEGORY"},

    {EAC_SCND_WEAPON_DEPLOYED_POSITION, "SCND_WEAPON_DEPLOYED_POSITION"},

    {EAC_SCRAP_TYPE, "SCRAP_TYPE"},

    {EAC_SEA_ICE_TYPE, "SEA_ICE_TYPE"},

    {EAC_SEA_NAME, "SEA_NAME"},

    {EAC_SEA_STATE_CATEGORY, "SEA_STATE_CATEGORY"},

    {EAC_SEA_STATE_NOISE_POWER_LEVEL, "SEA_STATE_NOISE_POWER_LEVEL"},

    {EAC_SEARCH_LIGHT_INTENSITY, "SEARCH_LIGHT_INTENSITY"},

    {EAC_SEASON, "SEASON"},

    {EAC_SEASONAL_TENT_LOCATION, "SEASONAL_TENT_LOCATION"},

    {EAC_SECCHI_DEPTH, "SECCHI_DEPTH"},

    {EAC_SECONDARY_AERIAL_DEPLOYED_POSITION, "SECONDARY_AERIAL_DEPLOYED_POSITION"},

    {EAC_SECONDARY_AXIS_VELOCITY_COMPONENT, "SECONDARY_AXIS_VELOCITY_COMPONENT"},

    {EAC_SECONDARY_BREAKER_AZIMUTH, "SECONDARY_BREAKER_AZIMUTH"},

    {EAC_SECONDARY_BREAKER_RELATIVE_ANGLE, "SECONDARY_BREAKER_RELATIVE_ANGLE"},

    {EAC_SECONDARY_BROADCAST_FREQUENCY, "SECONDARY_BROADCAST_FREQUENCY"},

    {EAC_SECONDARY_DOOR_OPEN_POSITION, "SECONDARY_DOOR_OPEN_POSITION"},

    {EAC_SECONDARY_MATERIAL_CHARACTERISTIC, "SECONDARY_MATERIAL_CHARACTERISTIC"},

    {EAC_SECONDARY_MATERIAL_TYPE, "SECONDARY_MATERIAL_TYPE"},

    {EAC_SECONDARY_SURFACE_AIR_VELOCITY, "SECONDARY_SURFACE_AIR_VELOCITY"},

    {EAC_SECONDARY_SURFACE_TEMPERATURE, "SECONDARY_SURFACE_TEMPERATURE"},

    {EAC_SECONDARY_SURFACE_THERMAL_CONDITION, "SECONDARY_SURFACE_THERMAL_CONDITION"},

    {EAC_SECONDARY_SWELL_WAVE_DIRECTION, "SECONDARY_SWELL_WAVE_DIRECTION"},

    {EAC_SECONDARY_SWELL_WAVE_HEIGHT, "SECONDARY_SWELL_WAVE_HEIGHT"},

    {EAC_SECONDARY_SWELL_WAVE_PERIOD, "SECONDARY_SWELL_WAVE_PERIOD"},

    {EAC_SECONDARY_WAVE_DIRECTION, "SECONDARY_WAVE_DIRECTION"},

    {EAC_SECTOR_DIRECTION, "SECTOR_DIRECTION"},

    {EAC_SECURITY_LEVEL, "SECURITY_LEVEL"},

    {EAC_SECURITY_LOCK_TYPE, "SECURITY_LOCK_TYPE"},

    {EAC_SECURITY_SYSTEM_TYPE, "SECURITY_SYSTEM_TYPE"},

    {EAC_SEDIMENT_ATTENUATION_FREQUENCY_EXPONENT, "SEDIMENT_ATTENUATION_FREQUENCY_EXPONENT"},

    {EAC_SEDIMENT_ATTENUATION_GRADIENT, "SEDIMENT_ATTENUATION_GRADIENT"},

    {EAC_SEDIMENT_BASEMENT_REFLECTION_COEFFICIENT, "SEDIMENT_BASEMENT_REFLECTION_COEFFICIENT"},

    {EAC_SEDIMENT_BELOW_LAYERS_DENSITY, "SEDIMENT_BELOW_LAYERS_DENSITY"},

    {EAC_SEDIMENT_COMP_ATTENUATION, "SEDIMENT_COMP_ATTENUATION"},

    {EAC_SEDIMENT_COMP_WAVE_SPEED, "SEDIMENT_COMP_WAVE_SPEED"},

    {EAC_SEDIMENT_COMP_WAVE_SPEED_CURVATURE, "SEDIMENT_COMP_WAVE_SPEED_CURVATURE"},

    {EAC_SEDIMENT_COMP_WAVE_SPEED_GRADIENT_TOP, "SEDIMENT_COMP_WAVE_SPEED_GRADIENT_TOP"},

    {EAC_SEDIMENT_CONDUCTIVITY, "SEDIMENT_CONDUCTIVITY"},

    {EAC_SEDIMENT_GRAIN_SIZE, "SEDIMENT_GRAIN_SIZE"},

    {EAC_SEDIMENT_LAYER_DENSITY, "SEDIMENT_LAYER_DENSITY"},

    {EAC_SEDIMENT_MEAN_BACKGROUND_THICKNESS, "SEDIMENT_MEAN_BACKGROUND_THICKNESS"},

    {EAC_SEDIMENT_REFLECTIVITY_ANGLE, "SEDIMENT_REFLECTIVITY_ANGLE"},

    {EAC_SEDIMENT_SHEAR_ATTENUATION, "SEDIMENT_SHEAR_ATTENUATION"},

    {EAC_SEDIMENT_SHEAR_WAVE_SPEED, "SEDIMENT_SHEAR_WAVE_SPEED"},

    {EAC_SEDIMENT_SRF_ATTENUATION, "SEDIMENT_SRF_ATTENUATION"},

    {EAC_SEDIMENT_SRF_ATTENUATION_GRADIENT, "SEDIMENT_SRF_ATTENUATION_GRADIENT"},

    {EAC_SEDIMENT_SURFACE_DENSITY, "SEDIMENT_SURFACE_DENSITY"},

    {EAC_SEDIMENT_THIN_LAYER_DENSITY, "SEDIMENT_THIN_LAYER_DENSITY"},

    {EAC_SEDIMENT_THIN_LAYER_THICKNESS, "SEDIMENT_THIN_LAYER_THICKNESS"},

    {EAC_SEDIMENT_TWO_WAY_TRAVEL_TIME, "SEDIMENT_TWO_WAY_TRAVEL_TIME"},

    {EAC_SEDIMENT_WATER_COMP_WAVE_SPEED_RATIO, "SEDIMENT_WATER_COMP_WAVE_SPEED_RATIO"},

    {EAC_SENSIBLE_HEAT_FLUX, "SENSIBLE_HEAT_FLUX"},

    {EAC_SERVICE_BRANCH, "SERVICE_BRANCH"},

    {EAC_SEVERE_WEATHER_PRESENT, "SEVERE_WEATHER_PRESENT"},

    {EAC_SEWER_TYPE, "SEWER_TYPE"},

    {EAC_SHARP_CURVE_RADIUS, "SHARP_CURVE_RADIUS"},

    {EAC_SHELTER_BELT, "SHELTER_BELT"},

    {EAC_SHIPPING_NOISE_MEASUREMENT_STATUS, "SHIPPING_NOISE_MEASUREMENT_STATUS"},

    {EAC_SHIPPING_NOISE_SEASON_TYPE, "SHIPPING_NOISE_SEASON_TYPE"},

    {EAC_SHIPPING_NOISE_SPECTRAL_POWER_LEVEL_ROLL_OFF, "SHIPPING_NOISE_SPECTRAL_POWER_LEVEL_ROLL_OFF"},

    {EAC_SHIPPING_NOISE_STD_DEV, "SHIPPING_NOISE_STD_DEV"},

    {EAC_SHORELINE_DELINEATED, "SHORELINE_DELINEATED"},

    {EAC_SHORELINE_PHYSIOGRAPHY, "SHORELINE_PHYSIOGRAPHY"},

    {EAC_SHORELINE_TYPE, "SHORELINE_TYPE"},

    {EAC_SHOWALTER_ATMOSPHERE_STABILITY_INDEX, "SHOWALTER_ATMOSPHERE_STABILITY_INDEX"},

    {EAC_SIDES_VISIBLE, "SIDES_VISIBLE"},

    {EAC_SIGMA_COORDINATE_VERTICAL_VELOCITY, "SIGMA_COORDINATE_VERTICAL_VELOCITY"},

    {EAC_SIGMA_CROSSWIND_SPREADING_RATE, "SIGMA_CROSSWIND_SPREADING_RATE"},

    {EAC_SIGMA_DOWNWIND_SPREADING_RATE, "SIGMA_DOWNWIND_SPREADING_RATE"},

    {EAC_SIGMA_VERTICAL_SPREADING_RATE, "SIGMA_VERTICAL_SPREADING_RATE"},

    {EAC_SIGMA_WIDTH_CROSSWIND, "SIGMA_WIDTH_CROSSWIND"},

    {EAC_SIGMA_WIDTH_DOWNWIND, "SIGMA_WIDTH_DOWNWIND"},

    {EAC_SIGMA_WIDTH_VERTICAL, "SIGMA_WIDTH_VERTICAL"},

    {EAC_SIGNAL_LIGHT_CHARACTER, "SIGNAL_LIGHT_CHARACTER"},

    {EAC_SIGNAL_LIGHT_PATTERN, "SIGNAL_LIGHT_PATTERN"},

    {EAC_SIGNAL_LIGHT_PATTERN_COUNT, "SIGNAL_LIGHT_PATTERN_COUNT"},

    {EAC_SIGNAL_LIGHT_SEQUENCE, "SIGNAL_LIGHT_SEQUENCE"},

    {EAC_SIGNIF_PRIMARY_BREAKER_HEIGHT, "SIGNIF_PRIMARY_BREAKER_HEIGHT"},

    {EAC_SIGNIF_SECONDARY_BREAKER_HEIGHT, "SIGNIF_SECONDARY_BREAKER_HEIGHT"},

    {EAC_SIGNIF_SWELL_WAVE_HEIGHT, "SIGNIF_SWELL_WAVE_HEIGHT"},

    {EAC_SIGNIF_WAVE_HEIGHT, "SIGNIF_WAVE_HEIGHT"},

    {EAC_SIGNIF_WIND_WAVE_HEIGHT, "SIGNIF_WIND_WAVE_HEIGHT"},

    {EAC_SINGLE_WHEEL_BEARING_LOAD, "SINGLE_WHEEL_BEARING_LOAD"},

    {EAC_SIPLE_PASSEL_WIND_CHILL_INDEX, "SIPLE_PASSEL_WIND_CHILL_INDEX"},

    {EAC_SKY_GROUND_LUMINANCE_RATIO, "SKY_GROUND_LUMINANCE_RATIO"},

    {EAC_SKY_OBSCURATION_FRACTION, "SKY_OBSCURATION_FRACTION"},

    {EAC_SLAVED_DECLINATION, "SLAVED_DECLINATION"},

    {EAC_SMOKE_RATE_FRACTION, "SMOKE_RATE_FRACTION"},

    {EAC_SMOKESTACK_COUNT, "SMOKESTACK_COUNT"},

    {EAC_SNOW_ACCUM_DEPTH, "SNOW_ACCUM_DEPTH"},

    {EAC_SNOW_ACCUM_DEPTH_EQUIVALENT, "SNOW_ACCUM_DEPTH_EQUIVALENT"},

    {EAC_SNOW_AGE, "SNOW_AGE"},

    {EAC_SNOW_DENSITY, "SNOW_DENSITY"},

    {EAC_SNOW_DEPTH_CATEGORY, "SNOW_DEPTH_CATEGORY"},

    {EAC_SNOW_DRIFT_HEIGHT, "SNOW_DRIFT_HEIGHT"},

    {EAC_SNOW_MELTING_RATE, "SNOW_MELTING_RATE"},

    {EAC_SNOW_ONLY_DEPTH, "SNOW_ONLY_DEPTH"},

    {EAC_SOIL_COMPRESSIONAL_VELOCITY, "SOIL_COMPRESSIONAL_VELOCITY"},

    {EAC_SOIL_CONE_INDEX, "SOIL_CONE_INDEX"},

    {EAC_SOIL_DENSITY_DRY, "SOIL_DENSITY_DRY"},

    {EAC_SOIL_DEPTH, "SOIL_DEPTH"},

    {EAC_SOIL_LAYER_DEPTH, "SOIL_LAYER_DEPTH"},

    {EAC_SOIL_MOISTURE_MASS_LOWER_LAYER, "SOIL_MOISTURE_MASS_LOWER_LAYER"},

    {EAC_SOIL_MOISTURE_MASS_TOP_LAYER, "SOIL_MOISTURE_MASS_TOP_LAYER"},

    {EAC_SOIL_SEISMIC_ABSORPTION_COEFFICIENT, "SOIL_SEISMIC_ABSORPTION_COEFFICIENT"},

    {EAC_SOIL_SHEAR_VELOCITY, "SOIL_SHEAR_VELOCITY"},

    {EAC_SOIL_SURFACE_TEMPERATURE, "SOIL_SURFACE_TEMPERATURE"},

    {EAC_SOIL_TYPE, "SOIL_TYPE"},

    {EAC_SOIL_WATER_MASS, "SOIL_WATER_MASS"},

    {EAC_SOIL_WATER_VOLUME, "SOIL_WATER_VOLUME"},

    {EAC_SOIL_WETNESS_CATEGORY, "SOIL_WETNESS_CATEGORY"},

    {EAC_SOLAR_DIFFUSE_IRRADIANCE, "SOLAR_DIFFUSE_IRRADIANCE"},

    {EAC_SOLAR_DIRECT_IRRADIANCE, "SOLAR_DIRECT_IRRADIANCE"},

    {EAC_SOLAR_RADIANCE_AZIMUTH_GEODETIC, "SOLAR_RADIANCE_AZIMUTH_GEODETIC"},

    {EAC_SOLAR_RADIANCE_AZIMUTH_LOCAL, "SOLAR_RADIANCE_AZIMUTH_LOCAL"},

    {EAC_SOLAR_RADIANCE_AZIMUTH_MAGNETIC, "SOLAR_RADIANCE_AZIMUTH_MAGNETIC"},

    {EAC_SOLAR_RADIANCE_ELEV_ANGLE_HORIZONTAL, "SOLAR_RADIANCE_ELEV_ANGLE_HORIZONTAL"},

    {EAC_SOLAR_RADIANCE_ELEV_ANGLE_LOCAL, "SOLAR_RADIANCE_ELEV_ANGLE_LOCAL"},

    {EAC_SOLAR_RADIATION_CUMULATIVE, "SOLAR_RADIATION_CUMULATIVE"},

    {EAC_SONAR_CONFIRMATION, "SONAR_CONFIRMATION"},

    {EAC_SONIC_LAYER_DEPTH, "SONIC_LAYER_DEPTH"},

    {EAC_SOUND_SIGNAL_PRESENT, "SOUND_SIGNAL_PRESENT"},

    {EAC_SOUND_SIGNAL_TYPE, "SOUND_SIGNAL_TYPE"},

    {EAC_SOUND_SPEED, "SOUND_SPEED"},

    {EAC_SOUNDING_DATUM_TYPE, "SOUNDING_DATUM_TYPE"},

    {EAC_SOUNDING_EXPOSITION, "SOUNDING_EXPOSITION"},

    {EAC_SOUNDING_INFORMATION, "SOUNDING_INFORMATION"},

    {EAC_SOUNDING_MEASUREMENT_TECHNIQUE, "SOUNDING_MEASUREMENT_TECHNIQUE"},

    {EAC_SOUNDING_VELOCITY_CORRECTION_TYPE, "SOUNDING_VELOCITY_CORRECTION_TYPE"},

    {EAC_SOURCE, "SOURCE"},

    {EAC_SOURCE_DATA_SET_COMPILE_DATE, "SOURCE_DATA_SET_COMPILE_DATE"},

    {EAC_SOURCE_DATA_SET_EDITION, "SOURCE_DATA_SET_EDITION"},

    {EAC_SOURCE_DATA_SET_GENERAL_INFORMATION, "SOURCE_DATA_SET_GENERAL_INFORMATION"},

    {EAC_SOURCE_DATA_SET_NAME, "SOURCE_DATA_SET_NAME"},

    {EAC_SOURCE_DATA_SET_PRINT_DATE, "SOURCE_DATA_SET_PRINT_DATE"},

    {EAC_SOURCE_DATA_SET_REVISION_DATE, "SOURCE_DATA_SET_REVISION_DATE"},

    {EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE, "SPATIAL_ANGULAR_PRIMARY_COORDINATE"},

    {EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE, "SPATIAL_ANGULAR_SECONDARY_COORDINATE"},

    {EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE, "SPATIAL_LINEAR_PRIMARY_COORDINATE"},

    {EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE, "SPATIAL_LINEAR_SECONDARY_COORDINATE"},

    {EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE, "SPATIAL_LINEAR_TERTIARY_COORDINATE"},

    {EAC_SPECIFIC_GRAVITY, "SPECIFIC_GRAVITY"},

    {EAC_SPECIFIC_HEAT, "SPECIFIC_HEAT"},

    {EAC_SPECIFIC_HUMIDITY, "SPECIFIC_HUMIDITY"},

    {EAC_SPEED, "SPEED"},

    {EAC_SPERM_WHALE_CATCH_PER_YEAR, "SPERM_WHALE_CATCH_PER_YEAR"},

    {EAC_SPILLING_BREAKER_FRACTION, "SPILLING_BREAKER_FRACTION"},

    {EAC_SPORT_TYPE, "SPORT_TYPE"},

    {EAC_SPOT_ELEVATION_TYPE, "SPOT_ELEVATION_TYPE"},

    {EAC_SPRING_TYPE, "SPRING_TYPE"},

    {EAC_STAIR_CONSTRUCTION_TYPE, "STAIR_CONSTRUCTION_TYPE"},

    {EAC_STAIR_STYLE, "STAIR_STYLE"},

    {EAC_STANTON_NUMBER, "STANTON_NUMBER"},

    {EAC_STELLAR_ALPHA_FLUX, "STELLAR_ALPHA_FLUX"},

    {EAC_STELLAR_ELECTRON_FLUX, "STELLAR_ELECTRON_FLUX"},

    {EAC_STELLAR_EM_FLUX, "STELLAR_EM_FLUX"},

    {EAC_STELLAR_PROTON_FLUX, "STELLAR_PROTON_FLUX"},

    {EAC_STELLAR_RF_FLUX_10r7, "STELLAR_RF_FLUX_10r7"},

    {EAC_STELLAR_RF_NB_MAXIMUM_TIME, "STELLAR_RF_NB_MAXIMUM_TIME"},

    {EAC_STELLAR_RF_NB_MAXIMUM_TIME_QUALITY, "STELLAR_RF_NB_MAXIMUM_TIME_QUALITY"},

    {EAC_STELLAR_RF_NB_MEAN_FLUX, "STELLAR_RF_NB_MEAN_FLUX"},

    {EAC_STELLAR_RF_NB_MEAN_FLUX_QUALITY, "STELLAR_RF_NB_MEAN_FLUX_QUALITY"},

    {EAC_STELLAR_RF_NB_PEAK_FLUX, "STELLAR_RF_NB_PEAK_FLUX"},

    {EAC_STELLAR_RF_NB_PEAK_FLUX_QUALITY, "STELLAR_RF_NB_PEAK_FLUX_QUALITY"},

    {EAC_STELLAR_RF_NB_PERIOD, "STELLAR_RF_NB_PERIOD"},

    {EAC_STELLAR_RF_NB_PERIOD_QUALITY, "STELLAR_RF_NB_PERIOD_QUALITY"},

    {EAC_STELLAR_RF_NB_REMARKS, "STELLAR_RF_NB_REMARKS"},

    {EAC_STELLAR_RF_NB_START, "STELLAR_RF_NB_START"},

    {EAC_STELLAR_RF_NB_START_QUALITY, "STELLAR_RF_NB_START_QUALITY"},

    {EAC_STELLAR_WIND_ION_TEMPERATURE, "STELLAR_WIND_ION_TEMPERATURE"},

    {EAC_STELLAR_WIND_PROTON_DENSITY, "STELLAR_WIND_PROTON_DENSITY"},

    {EAC_STELLAR_WIND_SPEED, "STELLAR_WIND_SPEED"},

    {EAC_STELLAR_WIND_SPEED_GSE_X, "STELLAR_WIND_SPEED_GSE_X"},

    {EAC_STELLAR_WIND_SPEED_GSE_Y, "STELLAR_WIND_SPEED_GSE_Y"},

    {EAC_STELLAR_WIND_SPEED_GSE_Z, "STELLAR_WIND_SPEED_GSE_Z"},

    {EAC_STELLAR_X_RAY_FLUX_L_BAND, "STELLAR_X_RAY_FLUX_L_BAND"},

    {EAC_STELLAR_X_RAY_FLUX_S_BAND, "STELLAR_X_RAY_FLUX_S_BAND"},

    {EAC_STEM_DIAMETER, "STEM_DIAMETER"},

    {EAC_STORAGE_FACILITY_TYPE, "STORAGE_FACILITY_TYPE"},

    {EAC_STRUCTURAL_PILE_TYPE, "STRUCTURAL_PILE_TYPE"},

    {EAC_STRUCTURE_DENSITY, "STRUCTURE_DENSITY"},

    {EAC_STRUCTURE_LIGHTING_TYPE, "STRUCTURE_LIGHTING_TYPE"},

    {EAC_STRUCTURE_PROTECTION_TYPE, "STRUCTURE_PROTECTION_TYPE"},

    {EAC_STRUCTURE_SHAPE, "STRUCTURE_SHAPE"},

    {EAC_SUMMER_CANOPY_COVER_FRACTION, "SUMMER_CANOPY_COVER_FRACTION"},

    {EAC_SUNRISE_TIME, "SUNRISE_TIME"},

    {EAC_SUNSET_TIME, "SUNSET_TIME"},

    {EAC_SUNSHINE_OBSERVATION_PERIOD, "SUNSHINE_OBSERVATION_PERIOD"},

    {EAC_SUNSHINE_PERIOD, "SUNSHINE_PERIOD"},

    {EAC_SUNSPOT_NUMBER, "SUNSPOT_NUMBER"},

    {EAC_SUNSPOT_NUMBER_INDEX, "SUNSPOT_NUMBER_INDEX"},

    {EAC_SUPERELEVATION, "SUPERELEVATION"},

    {EAC_SUPERTANKER_DENSITY, "SUPERTANKER_DENSITY"},

    {EAC_SURFACE_ANGLE, "SURFACE_ANGLE"},

    {EAC_SURFACE_BACKSCATTER, "SURFACE_BACKSCATTER"},

    {EAC_SURFACE_CATEGORY, "SURFACE_CATEGORY"},

    {EAC_SURFACE_CHARACTERISTIC_TYPE, "SURFACE_CHARACTERISTIC_TYPE"},

    {EAC_SURFACE_EM_ABSORPTIVITY, "SURFACE_EM_ABSORPTIVITY"},

    {EAC_SURFACE_EM_ABSORPTIVITY_SOLAR, "SURFACE_EM_ABSORPTIVITY_SOLAR"},

    {EAC_SURFACE_EM_DUCT_HEIGHT, "SURFACE_EM_DUCT_HEIGHT"},

    {EAC_SURFACE_EM_DUCT_STRENGTH, "SURFACE_EM_DUCT_STRENGTH"},

    {EAC_SURFACE_MATERIAL_TYPE, "SURFACE_MATERIAL_TYPE"},

    {EAC_SURFACE_REFLECTIVITY, "SURFACE_REFLECTIVITY"},

    {EAC_SURFACE_SLIPPERY, "SURFACE_SLIPPERY"},

    {EAC_SURFACE_SLOPE, "SURFACE_SLOPE"},

    {EAC_SURFACE_SLOPE_ORIENTATION, "SURFACE_SLOPE_ORIENTATION"},

    {EAC_SURFACE_TEMPERATURE, "SURFACE_TEMPERATURE"},

    {EAC_SURFACE_THERMAL_INDEX, "SURFACE_THERMAL_INDEX"},

    {EAC_SURFACE_THERMAL_MODEL, "SURFACE_THERMAL_MODEL"},

    {EAC_SURFACE_THERMAL_SUNSHADING_DOMINANCE, "SURFACE_THERMAL_SUNSHADING_DOMINANCE"},

    {EAC_SURFACE_THERMAL_VISUAL_DOMINANCE, "SURFACE_THERMAL_VISUAL_DOMINANCE"},

    {EAC_SURFACE_WIND_SPEED, "SURFACE_WIND_SPEED"},

    {EAC_SURFICIAL_DEPTH, "SURFICIAL_DEPTH"},

    {EAC_SURGING_BREAKER_FRACTION, "SURGING_BREAKER_FRACTION"},

    {EAC_SURVEILLANCE_WINGED_AIRCRAFT_TYPE, "SURVEILLANCE_WINGED_AIRCRAFT_TYPE"},

    {EAC_SURVEY_CONTROL_POINT_TYPE, "SURVEY_CONTROL_POINT_TYPE"},

    {EAC_SURVEY_END_DATE, "SURVEY_END_DATE"},

    {EAC_SURVEY_QUALIFIER, "SURVEY_QUALIFIER"},

    {EAC_SURVEY_START_DATE, "SURVEY_START_DATE"},

    {EAC_SUSPENDED_CEILING_DEPTH, "SUSPENDED_CEILING_DEPTH"},

    {EAC_SYNCHRONIZED, "SYNCHRONIZED"},

    {EAC_SYSTEM_RELAXATION_TIME, "SYSTEM_RELAXATION_TIME"},

    {EAC_TANKER_DENSITY, "TANKER_DENSITY"},

    {EAC_TAXIWAY_LIGHTING_INTENSITY, "TAXIWAY_LIGHTING_INTENSITY"},

    {EAC_TELESCOPE_TYPE, "TELESCOPE_TYPE"},

    {EAC_TEMPERATURE, "TEMPERATURE"},

    {EAC_TEMPERATURE_CONTRAST, "TEMPERATURE_CONTRAST"},

    {EAC_TEMPERATURE_INVRSN_LAYER_BASE, "TEMPERATURE_INVRSN_LAYER_BASE"},

    {EAC_TEMPERATURE_INVRSN_LAYER_LAPSE_RATE, "TEMPERATURE_INVRSN_LAYER_LAPSE_RATE"},

    {EAC_TEMPERATURE_INVRSN_LAYER_TOP, "TEMPERATURE_INVRSN_LAYER_TOP"},

    {EAC_TEMPERATURE_LAPSE_RATE, "TEMPERATURE_LAPSE_RATE"},

    {EAC_TENSILE_STRENGTH, "TENSILE_STRENGTH"},

    {EAC_TENT_DEPLOYMENT_FRACTION, "TENT_DEPLOYMENT_FRACTION"},

    {EAC_TERRAIN_ALBEDO, "TERRAIN_ALBEDO"},

    {EAC_TERRAIN_CHANNEL_WIDTH, "TERRAIN_CHANNEL_WIDTH"},

    {EAC_TERRAIN_CREST_WIDTH, "TERRAIN_CREST_WIDTH"},

    {EAC_TERRAIN_ELEVATION, "TERRAIN_ELEVATION"},

    {EAC_TERRAIN_GAP_WIDTH, "TERRAIN_GAP_WIDTH"},

    {EAC_TERRAIN_MORPHOLOGY_DESCRIPTION, "TERRAIN_MORPHOLOGY_DESCRIPTION"},

    {EAC_TERRAIN_MORPHOLOGY_TYPE, "TERRAIN_MORPHOLOGY_TYPE"},

    {EAC_TERRAIN_OBSTACLE_TYPE, "TERRAIN_OBSTACLE_TYPE"},

    {EAC_TERRAIN_ROUGHNESS_ROOT_MEAN_SQUARE, "TERRAIN_ROUGHNESS_ROOT_MEAN_SQUARE"},

    {EAC_TERRAIN_SLOPE, "TERRAIN_SLOPE"},

    {EAC_TERRAIN_SURFACE_MARKING_TYPE, "TERRAIN_SURFACE_MARKING_TYPE"},

    {EAC_TERRAIN_TRAFFICABILITY_COARSE, "TERRAIN_TRAFFICABILITY_COARSE"},

    {EAC_TERRAIN_TRAFFICABILITY_FINE, "TERRAIN_TRAFFICABILITY_FINE"},

    {EAC_TERRAIN_TRAFFICABILITY_MEDIUM, "TERRAIN_TRAFFICABILITY_MEDIUM"},

    {EAC_TERTIARY_AXIS_VELOCITY_COMPONENT, "TERTIARY_AXIS_VELOCITY_COMPONENT"},

    {EAC_TEXTUAL_OBJECT_IDENTIFIER, "TEXTUAL_OBJECT_IDENTIFIER"},

    {EAC_THERMAL_CONDUCTIVITY, "THERMAL_CONDUCTIVITY"},

    {EAC_THERMAL_PENETRATION_DEPTH, "THERMAL_PENETRATION_DEPTH"},

    {EAC_THERMOCLINE_TEMP_GRADIENT, "THERMOCLINE_TEMP_GRADIENT"},

    {EAC_THERMOCLINE_TEMP_GRADIENT_STD_DEV, "THERMOCLINE_TEMP_GRADIENT_STD_DEV"},

    {EAC_THICKNESS, "THICKNESS"},

    {EAC_THUNDERSTORM_INTENSITY, "THUNDERSTORM_INTENSITY"},

    {EAC_THUNDERSTORM_MAXIMUM_WIND_SPEED, "THUNDERSTORM_MAXIMUM_WIND_SPEED"},

    {EAC_THUNDERSTORM_PRESENT, "THUNDERSTORM_PRESENT"},

    {EAC_THUNDERSTORM_PROBABILITY, "THUNDERSTORM_PROBABILITY"},

    {EAC_THUNDERSTORM_TOP_ALTITUDE, "THUNDERSTORM_TOP_ALTITUDE"},

    {EAC_TIDAL_DATUM, "TIDAL_DATUM"},

    {EAC_TIDE_INFLUENCED, "TIDE_INFLUENCED"},

    {EAC_TIDE_LEVEL, "TIDE_LEVEL"},

    {EAC_TIME_COORDINATE, "TIME_COORDINATE"},

    {EAC_TIME_DIVISION_WITHIN_DAY, "TIME_DIVISION_WITHIN_DAY"},

    {EAC_TIME_FORMAT, "TIME_FORMAT"},

    {EAC_TIME_OF_DAY, "TIME_OF_DAY"},

    {EAC_TIME_PERIOD, "TIME_PERIOD"},

    {EAC_TIME_PERIOD_FORMAT, "TIME_PERIOD_FORMAT"},

    {EAC_TIME_QUANTITY, "TIME_QUANTITY"},

    {EAC_TOP_FLOOR_LEVEL_IDENTIFIER, "TOP_FLOOR_LEVEL_IDENTIFIER"},

    {EAC_TOP_LAYER_SOIL_TEMPERATURE, "TOP_LAYER_SOIL_TEMPERATURE"},

    {EAC_TOP_WIDTH, "TOP_WIDTH"},

    {EAC_TOPMARK_SHAPE, "TOPMARK_SHAPE"},

    {EAC_TOPMARK_TYPE, "TOPMARK_TYPE"},

    {EAC_TOTAL_CLOUD_COVER_CATEGORY, "TOTAL_CLOUD_COVER_CATEGORY"},

    {EAC_TOTAL_CLOUD_COVERAGE, "TOTAL_CLOUD_COVERAGE"},

    {EAC_TOTAL_ELECTRON_CONTENT, "TOTAL_ELECTRON_CONTENT"},

    {EAC_TOTAL_SNOW_ICE_DEPTH, "TOTAL_SNOW_ICE_DEPTH"},

    {EAC_TOTAL_SNOW_ICE_DEPTH_EQUIVALENT, "TOTAL_SNOW_ICE_DEPTH_EQUIVALENT"},

    {EAC_TOURISTIC_NAME, "TOURISTIC_NAME"},

    {EAC_TOWED_VEHICLE_TYPE, "TOWED_VEHICLE_TYPE"},

    {EAC_TOWER_TYPE, "TOWER_TYPE"},

    {EAC_TRAFFIC_LIGHT_MOUNT_TYPE, "TRAFFIC_LIGHT_MOUNT_TYPE"},

    {EAC_TRAFFIC_LIGHT_TYPE, "TRAFFIC_LIGHT_TYPE"},

    {EAC_TRANSMISSION_ATTENUATION_GRADIENT, "TRANSMISSION_ATTENUATION_GRADIENT"},

    {EAC_TRANSMISSION_LOSS, "TRANSMISSION_LOSS"},

    {EAC_TRANSMISSIVITY, "TRANSMISSIVITY"},

    {EAC_TRANSMITTED_AZIMUTH_GEODETIC, "TRANSMITTED_AZIMUTH_GEODETIC"},

    {EAC_TRANSMITTED_AZIMUTH_LOCAL, "TRANSMITTED_AZIMUTH_LOCAL"},

    {EAC_TRANSMITTED_AZIMUTH_MAGNETIC, "TRANSMITTED_AZIMUTH_MAGNETIC"},

    {EAC_TRANSMITTED_ELEV_ANGLE_HORIZONTAL, "TRANSMITTED_ELEV_ANGLE_HORIZONTAL"},

    {EAC_TRANSMITTED_ELEV_ANGLE_LOCAL, "TRANSMITTED_ELEV_ANGLE_LOCAL"},

    {EAC_TRANSPORT_CAPACITY, "TRANSPORT_CAPACITY"},

    {EAC_TRANSPORT_HELICOPTER_TYPE, "TRANSPORT_HELICOPTER_TYPE"},

    {EAC_TRANSPORT_LANDING_CRAFT_TYPE, "TRANSPORT_LANDING_CRAFT_TYPE"},

    {EAC_TRANSPORT_WINGED_AIRCRAFT_TYPE, "TRANSPORT_WINGED_AIRCRAFT_TYPE"},

    {EAC_TRANSPORTATION_BED_HEIGHT, "TRANSPORTATION_BED_HEIGHT"},

    {EAC_TRANSPORTATION_ROUTE_LENGTH, "TRANSPORTATION_ROUTE_LENGTH"},

    {EAC_TRANSPORTATION_USE, "TRANSPORTATION_USE"},

    {EAC_TREE_CANOPY_BOTTOM_HEIGHT, "TREE_CANOPY_BOTTOM_HEIGHT"},

    {EAC_TREE_CANOPY_LEVEL_COUNT, "TREE_CANOPY_LEVEL_COUNT"},

    {EAC_TREE_COUNT, "TREE_COUNT"},

    {EAC_TREE_SPACING, "TREE_SPACING"},

    {EAC_TREE_TYPE, "TREE_TYPE"},

    {EAC_TROPOPAUSE_ALTITUDE, "TROPOPAUSE_ALTITUDE"},

    {EAC_TROPOPAUSE_PRESENT, "TROPOPAUSE_PRESENT"},

    {EAC_TROPOPAUSE_PRESSURE, "TROPOPAUSE_PRESSURE"},

    {EAC_TROPOPAUSE_TEMPERATURE, "TROPOPAUSE_TEMPERATURE"},

    {EAC_TRUCK_LOAD_CLASS, "TRUCK_LOAD_CLASS"},

    {EAC_TSS_IMO_ADOPTED, "TSS_IMO_ADOPTED"},

    {EAC_TUNNEL_CROSS_SECTION, "TUNNEL_CROSS_SECTION"},

    {EAC_UNCOVERING_HEIGHT_KNOWN, "UNCOVERING_HEIGHT_KNOWN"},

    {EAC_UNDERBRIDGE_CLEARANCE, "UNDERBRIDGE_CLEARANCE"},

    {EAC_UNDERLYING_MATERIAL_CHARACTERISTIC, "UNDERLYING_MATERIAL_CHARACTERISTIC"},

    {EAC_UNDERLYING_MATERIAL_TYPE, "UNDERLYING_MATERIAL_TYPE"},

    {EAC_UPSTREAM_HEIGHT, "UPSTREAM_HEIGHT"},

    {EAC_URBAN_BUILDING_LIGHTING_INTENSITY, "URBAN_BUILDING_LIGHTING_INTENSITY"},

    {EAC_URBAN_STREET_LIGHTING_INTENSITY, "URBAN_STREET_LIGHTING_INTENSITY"},

    {EAC_URBAN_STREET_PATTERN, "URBAN_STREET_PATTERN"},

    {EAC_URBAN_TERRAIN_ZONE_TYPE, "URBAN_TERRAIN_ZONE_TYPE"},

    {EAC_USABLE_LENGTH, "USABLE_LENGTH"},

    {EAC_USAGE, "USAGE"},

    {EAC_UTILITY_USE, "UTILITY_USE"},

    {EAC_VARIABLE_SEA_STATE_FRACTION, "VARIABLE_SEA_STATE_FRACTION"},

    {EAC_VARIABLE_WIND_END_DIRECTION, "VARIABLE_WIND_END_DIRECTION"},

    {EAC_VARIABLE_WIND_START_DIRECTION, "VARIABLE_WIND_START_DIRECTION"},

    {EAC_VECTOR_AZIMUTH_GEODETIC, "VECTOR_AZIMUTH_GEODETIC"},

    {EAC_VECTOR_AZIMUTH_LOCAL, "VECTOR_AZIMUTH_LOCAL"},

    {EAC_VECTOR_AZIMUTH_MAGNETIC, "VECTOR_AZIMUTH_MAGNETIC"},

    {EAC_VECTOR_ELEV_ANGLE_HORIZONTAL, "VECTOR_ELEV_ANGLE_HORIZONTAL"},

    {EAC_VECTOR_ELEV_ANGLE_LOCAL, "VECTOR_ELEV_ANGLE_LOCAL"},

    {EAC_VEGETATION_RESTRICTED_SPEED, "VEGETATION_RESTRICTED_SPEED"},

    {EAC_VEGETATION_TYPE, "VEGETATION_TYPE"},

    {EAC_VEHICLE_CAPACITY, "VEHICLE_CAPACITY"},

    {EAC_VEHICLE_MAINTENANCE_AVAILABLE, "VEHICLE_MAINTENANCE_AVAILABLE"},

    {EAC_VEHICLE_MARKING, "VEHICLE_MARKING"},

    {EAC_VEHICLE_SMOKE_TYPE, "VEHICLE_SMOKE_TYPE"},

    {EAC_VEHICLE_STORAGE_AREA, "VEHICLE_STORAGE_AREA"},

    {EAC_VEHICLE_STORAGE_DOOR_PRI_HEIGHT, "VEHICLE_STORAGE_DOOR_PRI_HEIGHT"},

    {EAC_VEHICLE_STORAGE_DOOR_PRI_WIDTH, "VEHICLE_STORAGE_DOOR_PRI_WIDTH"},

    {EAC_VEHICLE_TRAFFIC_FLOW, "VEHICLE_TRAFFIC_FLOW"},

    {EAC_VEHICLE_TRAFFIC_GEODETIC_DIRECTION, "VEHICLE_TRAFFIC_GEODETIC_DIRECTION"},

    {EAC_VEHICULAR_MINIMUM_SPEED_LIMIT, "VEHICULAR_MINIMUM_SPEED_LIMIT"},

    {EAC_VEHICULAR_SPEED_LIMIT, "VEHICULAR_SPEED_LIMIT"},

    {EAC_VELOCITY, "VELOCITY"},

    {EAC_VENTILATION_FILTER_EFFICIENCY, "VENTILATION_FILTER_EFFICIENCY"},

    {EAC_VENTILATION_INFILTRATION_RATE, "VENTILATION_INFILTRATION_RATE"},

    {EAC_VERTICAL_CLEARANCE_CLOSED, "VERTICAL_CLEARANCE_CLOSED"},

    {EAC_VERTICAL_CLEARANCE_OPENED, "VERTICAL_CLEARANCE_OPENED"},

    {EAC_VERTICAL_CLEARANCE_SAFE, "VERTICAL_CLEARANCE_SAFE"},

    {EAC_VERTICAL_DATUM_IDENTIFIER, "VERTICAL_DATUM_IDENTIFIER"},

    {EAC_VERTICAL_LOAD_BEARING_CAPACITY, "VERTICAL_LOAD_BEARING_CAPACITY"},

    {EAC_VERTICAL_MEASUREMENT_QUALITY, "VERTICAL_MEASUREMENT_QUALITY"},

    {EAC_VERTICAL_PASSAGE_ENCLOSED, "VERTICAL_PASSAGE_ENCLOSED"},

    {EAC_VESSEL_DENSITY, "VESSEL_DENSITY"},

    {EAC_VESSEL_DENSITY_ACOUSTIC_LEVEL_CATEGORY, "VESSEL_DENSITY_ACOUSTIC_LEVEL_CATEGORY"},

    {EAC_VESSEL_FUNCTION, "VESSEL_FUNCTION"},

    {EAC_VESSEL_LOAD_RESTRICTIONS, "VESSEL_LOAD_RESTRICTIONS"},

    {EAC_VESSEL_TYPE, "VESSEL_TYPE"},

    {EAC_VIEW_OPENING_PRESENT, "VIEW_OPENING_PRESENT"},

    {EAC_VIRTUAL_AIR_TEMPERATURE, "VIRTUAL_AIR_TEMPERATURE"},

    {EAC_VISIBILITY_DISTANCE, "VISIBILITY_DISTANCE"},

    {EAC_VISIBILITY_DISTANCE_QUALITY, "VISIBILITY_DISTANCE_QUALITY"},

    {EAC_VISIBILITY_DISTANCE_VARIABLE, "VISIBILITY_DISTANCE_VARIABLE"},

    {EAC_VISUAL_OPACITY, "VISUAL_OPACITY"},

    {EAC_VISUAL_REFLECTOR_PRESENT, "VISUAL_REFLECTOR_PRESENT"},

    {EAC_VISUAL_WAVE_HEIGHT, "VISUAL_WAVE_HEIGHT"},

    {EAC_VOLCANIC_FORMATION_TYPE, "VOLCANIC_FORMATION_TYPE"},

    {EAC_VOLTAGE_LEVEL, "VOLTAGE_LEVEL"},

    {EAC_VOLUME, "VOLUME"},

    {EAC_VOLUME_BACKSCATTER_GRADIENT, "VOLUME_BACKSCATTER_GRADIENT"},

    {EAC_WAKE_INTENSITY, "WAKE_INTENSITY"},

    {EAC_WALL_CONSTRUCTION_TYPE, "WALL_CONSTRUCTION_TYPE"},

    {EAC_WALL_PREDOMINANT_PATTERN, "WALL_PREDOMINANT_PATTERN"},

    {EAC_WALL_PREDOMINANT_SURFACE_MATERIAL, "WALL_PREDOMINANT_SURFACE_MATERIAL"},

    {EAC_WALL_STUD_DEPTH, "WALL_STUD_DEPTH"},

    {EAC_WALL_TYPE, "WALL_TYPE"},

    {EAC_WATER_ACOUSTIC_TRANS_LOSS_MODEL, "WATER_ACOUSTIC_TRANS_LOSS_MODEL"},

    {EAC_WATER_ATTENUATION_TURBIDITY, "WATER_ATTENUATION_TURBIDITY"},

    {EAC_WATER_CHANNEL_SAFE_HORIZONTAL_CLEARANCE, "WATER_CHANNEL_SAFE_HORIZONTAL_CLEARANCE"},

    {EAC_WATER_CHANNEL_TYPE, "WATER_CHANNEL_TYPE"},

    {EAC_WATER_CURRENT_APPEARANCE_MONTH, "WATER_CURRENT_APPEARANCE_MONTH"},

    {EAC_WATER_CURRENT_DIRECTION, "WATER_CURRENT_DIRECTION"},

    {EAC_WATER_CURRENT_DISAPPEARANCE_MONTH, "WATER_CURRENT_DISAPPEARANCE_MONTH"},

    {EAC_WATER_CURRENT_REFERENCE, "WATER_CURRENT_REFERENCE"},

    {EAC_WATER_CURRENT_SPEED, "WATER_CURRENT_SPEED"},

    {EAC_WATER_CURRENT_TYPE, "WATER_CURRENT_TYPE"},

    {EAC_WATER_DEPTH, "WATER_DEPTH"},

    {EAC_WATER_DIFFUSE_TURBIDITY, "WATER_DIFFUSE_TURBIDITY"},

    {EAC_WATER_LEVEL_EFFECT, "WATER_LEVEL_EFFECT"},

    {EAC_WATER_QUALITY, "WATER_QUALITY"},

    {EAC_WATER_TABLE_DEPTH, "WATER_TABLE_DEPTH"},

    {EAC_WATER_TYPE, "WATER_TYPE"},

    {EAC_WATER_VAPOUR_PRESSURE, "WATER_VAPOUR_PRESSURE"},

    {EAC_WATERBODY_ACOUSTIC_AMBIENT_NOISE_SPECTRAL_MODEL, "WATERBODY_ACOUSTIC_AMBIENT_NOISE_SPECTRAL_MODEL"},

    {EAC_WATERBODY_BIOLUMINESCENCE, "WATERBODY_BIOLUMINESCENCE"},

    {EAC_WATERBODY_FLOOR_CLUTTER_DENSITY, "WATERBODY_FLOOR_CLUTTER_DENSITY"},

    {EAC_WATERBODY_FLOOR_CONFIGURATION, "WATERBODY_FLOOR_CONFIGURATION"},

    {EAC_WATERBODY_FLOOR_GRAZING_ANGLE, "WATERBODY_FLOOR_GRAZING_ANGLE"},

    {EAC_WATERBODY_FLOOR_MATERIAL_TYPE, "WATERBODY_FLOOR_MATERIAL_TYPE"},

    {EAC_WATERBODY_FLOOR_MORPHOLOGY, "WATERBODY_FLOOR_MORPHOLOGY"},

    {EAC_WATERBODY_FLOOR_OBJECT_TYPE, "WATERBODY_FLOOR_OBJECT_TYPE"},

    {EAC_WATERBODY_FLOOR_ROUGHNESS_CATEGORY, "WATERBODY_FLOOR_ROUGHNESS_CATEGORY"},

    {EAC_WATERBODY_PROPERTY_SET_ACOUSTIC_TYPE, "WATERBODY_PROPERTY_SET_ACOUSTIC_TYPE"},

    {EAC_WATERBODY_SOUND_SPEED, "WATERBODY_SOUND_SPEED"},

    {EAC_WATERBODY_SURFACE_DATA_OBSERVATION_METHOD, "WATERBODY_SURFACE_DATA_OBSERVATION_METHOD"},

    {EAC_WATERBODY_SURFACE_GRAZING_ANGLE, "WATERBODY_SURFACE_GRAZING_ANGLE"},

    {EAC_WATERBODY_SURFACE_ICE_FRACTION, "WATERBODY_SURFACE_ICE_FRACTION"},

    {EAC_WATERBODY_SURFACE_INSTANTANEOUS_HEIGHT, "WATERBODY_SURFACE_INSTANTANEOUS_HEIGHT"},

    {EAC_WATERBODY_SURFACE_TEMPERATURE, "WATERBODY_SURFACE_TEMPERATURE"},

    {EAC_WATERBODY_SURFACE_U_WIND_STRESS, "WATERBODY_SURFACE_U_WIND_STRESS"},

    {EAC_WATERBODY_SURFACE_V_WIND_STRESS, "WATERBODY_SURFACE_V_WIND_STRESS"},

    {EAC_WATERBODY_SURFACE_WIND_STRESS, "WATERBODY_SURFACE_WIND_STRESS"},

    {EAC_WATERBODY_TEMPERATURE, "WATERBODY_TEMPERATURE"},

    {EAC_WATERCOURSE_CHANNEL_TYPE, "WATERCOURSE_CHANNEL_TYPE"},

    {EAC_WATERCOURSE_GAP_WIDTH, "WATERCOURSE_GAP_WIDTH"},

    {EAC_WATERCOURSE_SINK_TYPE, "WATERCOURSE_SINK_TYPE"},

    {EAC_WAVE_SPECTRAL_DENSITY, "WAVE_SPECTRAL_DENSITY"},

    {EAC_WAVE_WHITECAP_RATE, "WAVE_WHITECAP_RATE"},

    {EAC_WAVELENGTH, "WAVELENGTH"},

    {EAC_WAYPOINT_TYPE, "WAYPOINT_TYPE"},

    {EAC_WEAPONS_RANGE_TYPE, "WEAPONS_RANGE_TYPE"},

    {EAC_WEATHER_MEASUREMENT_TECHNIQUE, "WEATHER_MEASUREMENT_TECHNIQUE"},

    {EAC_WELL_TYPE, "WELL_TYPE"},

    {EAC_WET_BULB_AIR_TEMPERATURE, "WET_BULB_AIR_TEMPERATURE"},

    {EAC_WET_GAP_WIDTH, "WET_GAP_WIDTH"},

    {EAC_WET_SOIL_TRAFFICABILITY, "WET_SOIL_TRAFFICABILITY"},

    {EAC_WETLAND_SURFACE_FORM, "WETLAND_SURFACE_FORM"},

    {EAC_WIDTH, "WIDTH"},

    {EAC_WIND_ABSOLUTE_VORTICITY, "WIND_ABSOLUTE_VORTICITY"},

    {EAC_WIND_CALM_FRACTION_CLIMATOLOGY, "WIND_CALM_FRACTION_CLIMATOLOGY"},

    {EAC_WIND_CATEGORY, "WIND_CATEGORY"},

    {EAC_WIND_CHILL_TEMPERATURE_INDEX, "WIND_CHILL_TEMPERATURE_INDEX"},

    {EAC_WIND_CIRCULARITY_COEFFICIENT_CLIMATOLOGY, "WIND_CIRCULARITY_COEFFICIENT_CLIMATOLOGY"},

    {EAC_WIND_DIRECTION, "WIND_DIRECTION"},

    {EAC_WIND_DIRECTION_CLIMATOLOGY, "WIND_DIRECTION_CLIMATOLOGY"},

    {EAC_WIND_DIRECTION_OCTANT_CLIMATOLOGY, "WIND_DIRECTION_OCTANT_CLIMATOLOGY"},

    {EAC_WIND_DIRECTION_OCTANT_FRACTION, "WIND_DIRECTION_OCTANT_FRACTION"},

    {EAC_WIND_DIRECTION_QUALITY, "WIND_DIRECTION_QUALITY"},

    {EAC_WIND_DIRECTION_VARIABILITY, "WIND_DIRECTION_VARIABILITY"},

    {EAC_WIND_DIVERGENCE, "WIND_DIVERGENCE"},

    {EAC_WIND_EQUIPMENT_TYPE, "WIND_EQUIPMENT_TYPE"},

    {EAC_WIND_GALE_FORCE_RATE_CLIMATOLOGY, "WIND_GALE_FORCE_RATE_CLIMATOLOGY"},

    {EAC_WIND_GUST_SPEED, "WIND_GUST_SPEED"},

    {EAC_WIND_GUST_SPREAD, "WIND_GUST_SPREAD"},

    {EAC_WIND_OMEGA, "WIND_OMEGA"},

    {EAC_WIND_RELATIVE_VORTICITY, "WIND_RELATIVE_VORTICITY"},

    {EAC_WIND_RESPONSE_FRACTION, "WIND_RESPONSE_FRACTION"},

    {EAC_WIND_SPEED, "WIND_SPEED"},

    {EAC_WIND_SPEED_20_PERCENTILE_CLIMATOLOGY, "WIND_SPEED_20_PERCENTILE_CLIMATOLOGY"},

    {EAC_WIND_SPEED_50_PERCENTILE_CLIMATOLOGY, "WIND_SPEED_50_PERCENTILE_CLIMATOLOGY"},

    {EAC_WIND_SPEED_80_PERCENTILE_CLIMATOLOGY, "WIND_SPEED_80_PERCENTILE_CLIMATOLOGY"},

    {EAC_WIND_SPEED_CLIMATOLOGY, "WIND_SPEED_CLIMATOLOGY"},

    {EAC_WIND_SPEED_CLIMATOLOGY_STD_DEV, "WIND_SPEED_CLIMATOLOGY_STD_DEV"},

    {EAC_WIND_SPEED_DIRECTION_REPORT_COUNT, "WIND_SPEED_DIRECTION_REPORT_COUNT"},

    {EAC_WIND_SPEED_EAST, "WIND_SPEED_EAST"},

    {EAC_WIND_SPEED_EAST_CLIM_STD_DEV, "WIND_SPEED_EAST_CLIM_STD_DEV"},

    {EAC_WIND_SPEED_EAST_CLIMATOLOGY, "WIND_SPEED_EAST_CLIMATOLOGY"},

    {EAC_WIND_SPEED_EAST_ERROR, "WIND_SPEED_EAST_ERROR"},

    {EAC_WIND_SPEED_NORTH, "WIND_SPEED_NORTH"},

    {EAC_WIND_SPEED_NORTH_CLIM_STD_DEV, "WIND_SPEED_NORTH_CLIM_STD_DEV"},

    {EAC_WIND_SPEED_NORTH_CLIMATOLOGY, "WIND_SPEED_NORTH_CLIMATOLOGY"},

    {EAC_WIND_SPEED_NORTH_ERROR, "WIND_SPEED_NORTH_ERROR"},

    {EAC_WIND_SPEED_OCTANT_CLIMATOLOGY, "WIND_SPEED_OCTANT_CLIMATOLOGY"},

    {EAC_WIND_SPEED_OCTANT_FRACTION, "WIND_SPEED_OCTANT_FRACTION"},

    {EAC_WIND_SPEED_ONLY_COUNT, "WIND_SPEED_ONLY_COUNT"},

    {EAC_WIND_SPEED_QUALITY, "WIND_SPEED_QUALITY"},

    {EAC_WIND_SPEED_U, "WIND_SPEED_U"},

    {EAC_WIND_SPEED_V, "WIND_SPEED_V"},

    {EAC_WIND_SPEED_W, "WIND_SPEED_W"},

    {EAC_WIND_VARIABLE_FRACTION_CLIMATOLOGY, "WIND_VARIABLE_FRACTION_CLIMATOLOGY"},

    {EAC_WIND_VECTOR_SPEED_CLIMATOLOGY, "WIND_VECTOR_SPEED_CLIMATOLOGY"},

    {EAC_WIND_WAVE_DIRECTION, "WIND_WAVE_DIRECTION"},

    {EAC_WIND_WAVE_HEIGHT, "WIND_WAVE_HEIGHT"},

    {EAC_WIND_WAVE_PERIOD, "WIND_WAVE_PERIOD"},

    {EAC_WINDOW_MATERIAL_TYPE, "WINDOW_MATERIAL_TYPE"},

    {EAC_WINDOW_TYPE, "WINDOW_TYPE"},

    {EAC_WINTER_CANOPY_COVER_FRACTION, "WINTER_CANOPY_COVER_FRACTION"},

    {EAC_WIRE_COUNT, "WIRE_COUNT"},

    {EAC_WIRE_MESH_COVERED, "WIRE_MESH_COVERED"},

    {EAC_WIRE_STRAND_COUNT, "WIRE_STRAND_COUNT"},

    {EAC_WMO_STATION_IDENTIFIER, "WMO_STATION_IDENTIFIER"},

    {EAC_WOODY_VEGETATION_DENSITY, "WOODY_VEGETATION_DENSITY"},

    {EAC_WORK_IN_PROGRESS_TYPE, "WORK_IN_PROGRESS_TYPE"},

    {EAC_WORSHIP_PLACE_TYPE, "WORSHIP_PLACE_TYPE"},

    {EAC_YAW_ANGLE, "YAW_ANGLE"},

    {EAC_YEAR_COMMON_ERA, "YEAR_COMMON_ERA"},

    {EAC_ZOROASTRIANISM_DENOMINATIONAL_FAMILY, "ZOROASTRIANISM_DENOMINATIONAL_FAMILY"}

}; /* EDCS_Attribute_Labels */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareEALabel
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareEALabel
(
    const EDCS_Attribute_Label_Entry *a_ptr,
    const EDCS_Attribute_Label_Entry *b_ptr
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
} /* end local_CompareEALabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEADictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetEADictionaryEntry
(
    EDCS_Attribute_Code               ea_code_in,
    const EDCS_Attribute_Dictionary_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidAttributeCode(ea_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *result_out_ptr = &(EDCS_Attribute_Dictionary[ea_code_in-1]);
    }
    return status;
} /* end EDCS_GetEADictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEACode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_LabelToEACode
(
    const EDCS_Character       *label_in,
          EDCS_Attribute_Code  *result_out_ptr
)
{
    EDCS_Status_Code            status = EDCS_SC_SUCCESS;
    EDCS_Attribute_Label_Entry *search_result_ptr = NULL, target;

    if (!label_in || !result_out_ptr)
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    else
    {
       *result_out_ptr = (EDCS_Attribute_Code)0;
        target.label   = label_in;
        search_result_ptr = (EDCS_Attribute_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_Attribute_Labels,
                               EDCS_TOTAL_EA,
                               sizeof(EDCS_Attribute_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_CompareEALabel
                            );
        if (search_result_ptr)
            *result_out_ptr = search_result_ptr->code;
        else
            status = EDCS_SC_INVALID_INPUT_LABEL;
    }
    return status;
} /* end EDCS_LabelToEACode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintAttributeCode
(
     EDCS_Attribute_Code ea_code_in
)
{
    static char buffer[256];

    if (!EDCS_ValidAttributeCode(ea_code_in))
    {
        sprintf(buffer, "ERROR - ILLEGAL EDCS_Attribute_Code VALUE (%i)",
               (int) ea_code_in);
        return buffer;
    }
    else
    {
        return EDCS_Attribute_Dictionary[ea_code_in-1].symbolic_constant;
    }
} /* end EDCS_PrintAttributeCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEACode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SymbolicConstantToEACode
(
    const EDCS_Character      *symbolic_in_ptr,
          EDCS_Attribute_Code *result_out_ptr
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
        /* Symbolic Constants should always be of the form EAC_<EA_Label>, so
         * we strip off the EAC_ and use the EDCS_LabelToEACode function
         */
        if (strstr( symbolic_in_ptr, "EAC_" ) == symbolic_in_ptr )
        {
            label = strchr( symbolic_in_ptr, '_' );

            if (label != NULL)
            {
                label++;
                status = EDCS_LabelToEACode( label, result_out_ptr );

                /* Hand back the correct error code if the label couldn't be found */
                if (status == EDCS_SC_INVALID_INPUT_LABEL)
                {
                    status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
                }
            }
        }
    }
    return status;
} /* end EDCS_SymbolicConstantToEACode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidAttributeCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidAttributeCode
(
    EDCS_Attribute_Code ea_code_in
)
{
    if (ea_code_in < 1 || ea_code_in > EDCS_TOTAL_EA)
    {
        return EDCS_FALSE;
    }
    else if (EDCS_Attribute_Dictionary[ea_code_in-1].code != ea_code_in)
    {
        return EDCS_FALSE;
    }
    else
    {
        return EDCS_TRUE;
    }
} /* end EDCS_ValidAttributeCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitForAttribute
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_ValidUnitForAttribute
(
    EDCS_Unit_Code       eu_code_in,
    EDCS_Attribute_Code  ea_code_in,
    EDCS_Boolean        *result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;
    EDCS_Boolean membership;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidAttributeCode(ea_code_in) ||
             !EDCS_ValidUnitCode(eu_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else if (EDCS_Attribute_Dictionary[ea_code_in-1].value_type != EDCS_AVT_REAL)
    {
        *result_out_ptr = EDCS_FALSE;
    }
    else
    {
        *result_out_ptr = EDCS_FALSE;

        status = EDCS_UnitEquivalenceMembership
                 (eu_code_in,
                  EDCS_Attribute_Dictionary[ea_code_in-1].eq_class,
                 &membership );

        if (status == EDCS_SC_SUCCESS && membership == EDCS_TRUE)
        {
            *result_out_ptr = EDCS_TRUE;
        }
    }
    return status;
} /* end EDCS_ValidUnitForAttribute */
