/*
 * FILE       : facc_mapping_types.h
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *              Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *    This file contains structures helpful for mapping from
 *    previous versions of EDCS or other coding standards to
 *    the current EDCS codes
 *
 * EDCS SDK Release 4.4.0 - July 1, 2011
 * - EDCS spec. 4.4
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

#ifndef _FACC_MAP_TYPES_H_INCLUDED
#define _FACC_MAP_TYPES_H_INCLUDED

#if !defined(_WIN32)
#define EXPORT_DLL
#elif !defined(EXPORT_DLL)
#if defined(_LIB)
#define EXPORT_DLL
#elif defined(_USRDLL)
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#endif /* _WIN32 && EXPORT_DLL */

#include "edcs.h"
#include "edcs_mapping_util.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/* structures needed to FACC mapping functions */

typedef EDCS_Integer FACC_2p1_Attribute_Integer_Code;

typedef struct
{
    char tag[5];
} FACC_2p1_Feature_Code;

typedef struct
{
    char tag[3];
} FACC_2p1_Attribute_Code;

/*
 * REGISTERABLE ENUM: FACC_2p1_Mapping_Type_Code
 *
 *   Specifies the type and multiplicity of a given forward
 *   mapping.
 */
typedef EDCS_Integer FACC_2p1_Mapping_Type_Code;

/*
 * GLOBAL_CONSTANT: FACC_MAP_TYP_ONE_TO_ZERO
 *
 *   There is no forward mapping for the given concept.
 *
 *   In any mapping data structure with an entry list,
 *   the entry list will be null.  Check the information
 *   field for relevant information.
 */
#define FACC_MAP_TYP_ONE_TO_ZERO  (FACC_2p1_Mapping_Type_Code)1

/*
 * GLOBAL_CONSTANT: FACC_MAP_TYP_ONE_TO_ONE
 *
 *   The given concept has an exact mapping to a single
 *   concept in the target version of EDCS.
 *
 *   In any mapping data structure with an entry list, there
 *   will be exactly one unique replacement entry in the list.
 *   There may or may not be information in the information
 *   field for this case.
 */
#define FACC_MAP_TYP_ONE_TO_ONE (FACC_2p1_Mapping_Type_Code)2

/*
 * GLOBAL_CONSTANT: FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED
 *
 *   The given concept has been mapped to two or more concepts
 *   in the target version of EDCS.
 *
 *   This occurs only within mapping data structures that have
 *   entry lists. In this case, the entry list will have
 *   more than 1 entry, and the information field may have
 *   relevant information.
 */
#define FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED (FACC_2p1_Mapping_Type_Code)3

/*
 * GLOBAL_CONSTANT: FACC_MAP_TYP_ONE_TO_ONE_CONDITIONAL
 *
 *   The given concept has a single exact replacement, but it is either
 *   the old concept was an EA whose enumerants did not all map to the
 *   same EA, or it mapped to a different concept.
 */
#define FACC_MAP_TYP_ONE_TO_ONE_CONDITIONAL (FACC_2p1_Mapping_Type_Code)4

/*
 * GLOBAL_CONSTANT: FACC_MAP_TYP_CHANGE_IN_DATATYPE
 *
 *   The concept has a one-to-one mapping, but the datatype used to
 *   realize the concept has changed.
 */
#define FACC_MAP_TYP_CHANGE_IN_DATATYPE     (FACC_2p1_Mapping_Type_Code)5

/*
 * GLOBAL_CONSTANT: FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC
 *
 *    The concept has a one-to-one mapping, but the new concept is an
 *    EDCS_Value_Characteristic Concept.
 */
#define FACC_MAP_TYP_CHANGE_TO_CHARACTERISTIC     (FACC_2p1_Mapping_Type_Code)6

/*
 * GLOBAL_CONSTANT: FACC_MAP_TYP_SPECIAL_CASE
 *
 *   The mapping from this concept is not implemented in the code but
 *   the description of the mapping will be in the information
 *   field of the mapping structure.  There will be no mapping entries
 *   in the list.
 */
#define FACC_MAP_TYP_SPECIAL_CASE           (FACC_2p1_Mapping_Type_Code)7

typedef struct
{
    FACC_2p1_Mapping_Type_Code  map_type;
    EDCS_Classification_Code    ec_code;
    EDCS_Integer                num_entries;
    EDCS_Mapping_Entry         *entry_list;
    EDCS_Character             *information;
} FACC_2p1_Class_Mapping_Structure;

typedef struct
{
    FACC_2p1_Mapping_Type_Code   map_type;
    EDCS_Attribute_Code          ea_code;
    EDCS_Integer                 num_entries;
    EDCS_Mapping_Entry          *entry_list;
    EDCS_Character              *information;
} FACC_2p1_Attribute_Mapping_Structure;

typedef struct
{
    FACC_2p1_Mapping_Type_Code  map_type;
    EDCS_Attribute_Code         ea_code;
    EDCS_Enumerant_Code         ee_code;
    EDCS_Integer                num_entries;
    EDCS_Mapping_Entry         *entry_list;
    EDCS_Character             *information;
} FACC_2p1_Enumerant_Mapping_Structure;

typedef struct
{
    FACC_2p1_Mapping_Type_Code  map_type;
    EDCS_Unit_Code              eu_code;
    EDCS_Unit_Scale_Code        es_code;
    EDCS_Character             *information;
} FACC_2p1_Unit_Mapping_Structure;

#ifdef __cplusplus
}
#endif

#endif
