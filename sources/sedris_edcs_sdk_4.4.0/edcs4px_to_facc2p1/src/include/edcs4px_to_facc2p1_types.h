/*
 * FILE       : edcs4px_to_facc2p1_types.h
 *
 * PROGRAMMERS: Kevin Wertman (SAIC)
 *
 * DESCRIPTION:
 *    This file contains all types related to mapping from EDCS 4.x codes
 *    to DIGEST FACC Edition 2.1
 *
 * EDCS 4.4 to FACC 2.1 Mapping SDK Release 4.4.0.0 - July 1, 2011
 * - EDCS spec. 4.4
 */

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
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

#ifndef _EDCS4px_TO_FACC2p1_TYPES_H_INCLUDED
#define _EDCS4px_TO_FACC2p1_TYPES_H_INCLUDED

#ifndef _WIN32    /* WIN32 platforms need to dllimport variables */
#define EXPORT_EDCS_SYMBOLS_WIN32
#else
#if defined (SE_TURN_OFF_EDCS_WIN32_IMPORT) || defined (_MAKE_WIN32_STATIC)
      /* exporting, so no dll import needed here */
#define EXPORT_EDCS_SYMBOLS_WIN32
#else
#define EXPORT_EDCS_SYMBOLS_WIN32 __declspec(dllimport)
       /* importing a variable from a dll */
#endif
#endif

#include "edcs.h"
#include "edcs_facc_mapping_types.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 * Mapping type definitions
 */

/*
 * ENUM: FACC_Mapping_Type_Code
 *
 * Used to determine what kind of mapping has taken place
 */
typedef EDCS_Integer FACC_Mapping_Type_Code;

/*
 * FACC_MAP_TYP_ONE_TO_ONE:
 *
 * Mapping is one to one, with only one FACC concept necessary
 * to represent the given EDCS concept.
 */
#define FACC_MAP_TYP_ONE_TO_ONE (FACC_Mapping_Type_Code)1

/*
 * FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED:
 *
 * Mapping is one to one, but in FACC there are additional
 * qualifying concepts necessary to represent the EDCS concept.
 * For example:
 *
 * ADMINISTRATION_BUILDING will map to AL015 for building, but it
 * will also be qualified with BFC_28 which is Building Function
 * Category - Administration Building
 *
 * In these cases the additional_concept_count will be > 0 and the
 * additional_concepts array will be populated with the qualifying
 * concepts.
 */
#define FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED (FACC_Mapping_Type_Code)2

/*
 * FACC_MAP_TYP_ONE_TO_ZERO:
 *
 * Mapping is one to zero, ie there are no concepts in FACC that
 * can be used to represent the given EDCS concept
 */
#define FACC_MAP_TYP_ONE_TO_ZERO (FACC_Mapping_Type_Code)3

/*
 * FACC_MAP_TYP_MAP_TO_CODED:
 *
 * In this case the FACC is a ranged enumerant, but in EDCS the
 * concept uses intervals to map those ranges.  So for specific
 * intervals that either match or are a subset of the ranged enumerant,
 * a mapping will take place.
 */
#define FACC_MAP_TYP_MAP_TO_CODED (FACC_Mapping_Type_Code)4

/*
 * FACC_MAP_TYP_INDETERMINATE:
 *
 * This is a special case.  Some EDCS Attributes map to different
 * FACC codes depending on what value is handed in.  In this case
 * when attempting to map just the EDCS Attribute, the mapping
 * type will be INDETERMINATE, meaning that there will be different
 * FACC codes returned using EDCS_MapAttributeWithValue depending
 * on the value passed in.
 */
#define FACC_MAP_TYP_INDETERMINATE (FACC_Mapping_Type_Code)5

/*
 * FACC_MAP_TYP_SPECIAL_CASE
 *
 * In this case the mapping is special in that it may need
 * user intervention to perform the mapping.  In these cases the
 * notes field will contain the special case information.
 */
#define FACC_MAP_TYP_SPECIAL_CASE (FACC_Mapping_Type_Code)6

/*
 * GLOBAL_CONSTANT: FACC_MAP_TYP_ONE_TO_ONE_CONDITIONAL
 *
 *   The given concept has a single exact replacement, but it
 *   involves a different category of concept, such as an
 *   attribute-with-specific-value mapping to a feature.
 */
#define FACC_MAP_TYP_ONE_TO_ONE_CONDITIONAL (FACC_Mapping_Type_Code)7

/*
 * Structures used in the FACC mapping functions
 */

/*
 * ENUM: FACC_Value_Type
 *
 * This set of definitions is used to define the
 * structure FACC_Attribute_With_Value which is
 * used to represent any FACC attribute code with
 * a given value, be it an integer/enumerant or
 * floating point value, or string.
 */
typedef EDCS_Integer FACC_Value_Type;

#define FACC_VAL_TYP_NULL          (FACC_Value_Type)0
#define FACC_VAL_TYP_CODED         (FACC_Value_Type)1
#define FACC_VAL_TYP_SHORT_INTEGER (FACC_Value_Type)2
#define FACC_VAL_TYP_LONG_INTEGER  (FACC_Value_Type)3
#define FACC_VAL_TYP_FLOAT         (FACC_Value_Type)4
#define FACC_VAL_TYP_TEXT          (FACC_Value_Type)5

/*
 * STRUCT: FACC_Attribute_With_Value
 *
 * This structure will be returned from the call
 * EDCS_to_FACC_MapAttributeWithValue, and is also
 * used inside the classificaton and attribute mapping
 * structures below
 */
typedef struct
{
    FACC_2p1_Attribute_Code facc_attribute_code;
    FACC_Value_Type value_type;
    union
    {
              EDCS_Integer     facc_coded_value;
              EDCS_Integer     facc_short_integer_value;
              EDCS_Integer     facc_long_integer_value;
              EDCS_Long_Float  facc_float_value;
        const char            *facc_text_value;
    } u;
} FACC_Attribute_With_Value;

/*
 * STRUCT: FACC_Feature_Mapping_Structure
 *
 * This structure will be returned from the call
 * EDCS_to_FACC_MapClassificationCode.
 *
 * If the mapping_type field is FACC_MAP_TYP_ONE_TO_ONE
 * then the additional concepts fields will be empty and
 * the facc_feature_code field will have the FACC feature
 * code.
 *
 * If the mapping_type field is FACC_MAP_TYP_ONE_TO_ONE_QUALIFIED
 * then the additional concepts fields will be populated with
 * concepts that qualify the FACC feature code in facc_feature_code
 *
 * If the mapping_type field is FACC_MAP_TYP_ONE_TO_ZERO
 * then all fields, except the notes field, will be 0 or NULL.
 *
 * In this version of the library, the mapping_type should be no other
 * case for mapping classification codes
 */

typedef struct
{
          FACC_Mapping_Type_Code     mapping_type;
          FACC_2p1_Feature_Code      facc_feature_code;
          EDCS_Integer               additional_concept_count;
          FACC_Attribute_With_Value *additional_concepts;
    const char                      *notes;
} FACC_Feature_Mapping_Structure;

/*
 * STRUCT: FACC_Attribute_Mapping_Structure
 *
 * This structure will be returned from the call
 * EDCS_to_FACC_MapAttributeCode
 *
 * If the mapping_type field is FACC_MAP_TYP_ONE_TO_ONE
 * then the additional concepts fields will be empty and
 * the facc_attribute_code field will have the FACC attribute
 * code.  If the FACC attribute is one that has some sort of
 * units associated with it, the target_unit and target_scale
 * will reflect that unit and can be used in EDCS_ConvertUnitAndScale
 * to get a result with the correct unit and scale to use in FACC.
 *
 * If the mapping_type field is FACC_MAP_TYP_ONE_TO_ZERO
 * then all fields, except the notes field, will be 0 or NULL.
 *
 * If the mapping type field is FACC_MAP_TYP_INDETERMINATE
 * then the fields will be populated only if one of the possible
 * attribute codes that the attribute will map to is of FACC Value
 * type SHORT_INTEGER.
 *
 * If the mapping type field is FACC_MAP_TYP_MAP_TO_CODED
 * then the facc_attribute_code field will be populated with the
 * FACC Coded attribute that the different intervals will end up
 * mapping to.
 *
 * If the mapping type field is FACC_MAP_TYP_SPECIAL_CASE
 * then the fields may contain the FACC attribute code information
 * that it will map to, and the notes field will contain information
 * about special steps that must be made to complete the mapping.
 */
typedef struct
{
          FACC_Mapping_Type_Code   mapping_type;
          FACC_2p1_Attribute_Code  facc_attribute_code;
          FACC_Value_Type          facc_target_value_type;
          EDCS_Unit_Code           facc_target_unit_code;
          EDCS_Unit_Scale_Code     facc_target_scale_code;
    const char                    *notes;
} FACC_Attribute_Mapping_Structure;

/*
 * STRUCT: FACC_Attribute_With_Value_Mapping_Structure
 *
 * This structure will be returned from the call
 * EDCS_to_FACC_MapAttributeWithValue
 *
 * If the mapping_type field is FACC_MAP_TYP_ONE_TO_ONE then
 * the facc_attribute_with_value structure will be populated
 * with the FACC Attribute Code and the corresponding value
 * If applicable, the unit and scale of the value will be
 * proper for the FACC Attribute Code.
 *
 * If the mapping_type field is FACC_MAP_TYP_ONE_TO_ZERO then
 * no mapping could be found for the EDCS attribute or for the
 * specific value given with the EDCS attribute.
 *
 */
typedef struct
{
          FACC_Mapping_Type_Code     mapping_type;
          FACC_Attribute_With_Value  facc_attribute_with_value;
    const char                      *notes;
} FACC_Attribute_With_Value_Mapping_Structure;

/*
 * STRUCT: EDCS_Attribute_Value_Entry
 */
typedef struct
{
    EDCS_Boolean         is_ev;
    union
    {
        EDCS_Attribute_Value           ea_value;
        EDCS_Value_Characteristic_Code ev_code;
    } u;
} EDCS_Attribute_Value_Entry;

#ifdef __cplusplus
}
#endif

#endif
