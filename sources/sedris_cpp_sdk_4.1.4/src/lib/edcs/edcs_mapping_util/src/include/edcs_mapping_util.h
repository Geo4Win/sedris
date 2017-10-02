/*
 * FILE       : edcs_mapping_util.h
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *      Main header for EDCS mapping utility SDK.
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

#ifndef _EDCS_MAPPING_UTIL_H_INCLUDED_
#define _EDCS_MAPPING_UTIL_H_INCLUDED_

#include "edcs.h"

#undef EXPORT_DLL
#define EXPORT_DLL
/*
 * Allow C++ compilers to use this API without problems.
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 * REGISTERABLE ENUM: EDCS_Mapping_Entry_Type_Code
 *
 *   Specifies the mapping of an individual target in a
 *   mapping structure's entry list.
 */
typedef EDCS_Integer EDCS_Mapping_Entry_Type_Code;

/*
 * GLOBAL_CONSTANT: EDCS_MAP_ENTRY_TYP_ATTR
 *
 *   The target is an EA.
 */
#define EDCS_MAP_ENTRY_TYP_ATTR (EDCS_Mapping_Entry_Type_Code)1

/*
 * GLOBAL_CONSTANT: EDCS_MAP_ENTRY_TYP_ATTR_VAL
 *
 *   The target is an EA with a specific value.
 */
#define EDCS_MAP_ENTRY_TYP_ATTR_VAL (EDCS_Mapping_Entry_Type_Code)2

/*
 * GLOBAL_CONSTANT: EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC
 *
 *   The target is an EV.
 */
#define EDCS_MAP_ENTRY_TYP_VALUE_CHARACTERISTIC (EDCS_Mapping_Entry_Type_Code)3

/*
 * GLOBAL_CONSTANT: EDCS_MAP_ENTRY_TYP_CLASS
 *
 *   The target is an EC.
 */
#define EDCS_MAP_ENTRY_TYP_CLASS (EDCS_Mapping_Entry_Type_Code)4

/*
 * STRUCT: EDCS_Attribute_With_Value_Entry
 *
 *   Provides forward mapping information in the case where an
 *   EA with a specific value is the target.
 */
typedef struct
{
    EDCS_Attribute_Code  ea_code;
    EDCS_Attribute_Value ea_value;
} EDCS_Attribute_With_Value_Entry;

/*
 * STRUCT: EDCS_Value_Characteristic_Code_Entry
 *
 *   Provides forward mapping information in the case where an
 *   EA is the target, with a specific EV.
 */
typedef struct
{
    EDCS_Attribute_Code            ea_code;
    EDCS_Value_Characteristic_Code ev_code;
} EDCS_Value_Characteristic_Code_Entry;

/*
 * STRUCT: EDCS_Mapping_Entry
 *
 *   Specifies the mapping of an individual target in a
 *   mapping structure's entry list.
 */
typedef struct
{
    EDCS_Mapping_Entry_Type_Code type;

    union
    {
        EDCS_Attribute_Code                  attribute_entry;
        EDCS_Attribute_With_Value_Entry      attr_value_entry;
        EDCS_Value_Characteristic_Code_Entry characteristic_entry;
        EDCS_Classification_Code             class_entry;
    } u;
} EDCS_Mapping_Entry;

/*
 * REGISTERABLE ENUM: EDCS_Mapping_Type_Code
 *
 *   Specifies the type and multiplicity of a given forward
 *   mapping.
 */
typedef EDCS_Integer EDCS_Mapping_Type_Code;

/*
 * GLOBAL_CONSTANT: EDCS_MAPPING_TYP_ONE_TO_ZERO
 *
 *   There is no forward mapping for the given concept.
 *
 *   In any mapping data structure with an entry list,
 *   the entry list will be null.  Check the notes
 *   field for relevant information.
 */
#define EDCS_MAPPING_TYP_ONE_TO_ZERO (EDCS_Mapping_Type_Code)1

/*
 * GLOBAL_CONSTANT: EDCS_MAPPING_TYP_ONE_TO_ONE
 *
 *   The given concept has an exact mapping to a single
 *   concept in the target version of EDCS.
 *
 *   In any mapping data structure with an entry list, there
 *   will be exactly one unique replacement entry in the list.
 *   There may or may not be information in the notes field
 *   for this case.
 */
#define EDCS_MAPPING_TYP_ONE_TO_ONE (EDCS_Mapping_Type_Code)2

/*
 * GLOBAL_CONSTANT: EDCS_MAPPING_TYP_ONE_TO_ONE_CONDITIONAL
 *
 *   The given concept has a single exact replacement, but it
 *   involves a different category of concept, such as an
 *   EA-with-specific-value mapping to an EC.
 */
#define EDCS_MAPPING_TYP_ONE_TO_ONE_CONDITIONAL (EDCS_Mapping_Type_Code)3

/*
 * GLOBAL_CONSTANT: EDCS_MAPPING_TYP_ONE_TO_ONE_QUALIFIED
 *
 *   The given concept has been mapped to a combination of two or more
 *   concepts in the target version of EDCS.
 *
 *   This occurs only within mapping data structures that have
 *   entry lists. In this case, the entry list will have one or
 *   more entries, and the notes field may have relevant
 *   information.
 */
#define EDCS_MAPPING_TYP_ONE_TO_ONE_QUALIFIED (EDCS_Mapping_Type_Code)4

/*
 * GLOBAL_CONSTANT: EDCS_MAPPING_TYP_ONE_TO_MANY
 *
 *   The mapping for the given concept could be one of many concepts
 *   in the target version of EDCS. The description of the possible
 *   mappings will be in the notes field of the mapping structure.
 *   There will be no mapping entries in the entry list.
 */
#define EDCS_MAPPING_TYP_ONE_TO_MANY (EDCS_Mapping_Type_Code)5

/*
 * GLOBAL_CONSTANT: EDCS_MAPPING_TYP_CHANGE_IN_DATATYPE
 *
 *   The given concept has a one-to-one mapping, but the new concept
 *   is realized by a different data type than was the old concept.
 *
 *   This mapping type only occurs when mapping EA and EE concepts.
 */
#define EDCS_MAPPING_TYP_CHANGE_IN_DATATYPE (EDCS_Mapping_Type_Code)6

/*
 * GLOBAL_CONSTANT: EDCS_MAPPING_TYP_CHANGE_TO_CHARACTERISTIC
 *
 *   The given concept has a one-to-one mapping, but the new concept
 *   is an EDCS Attribute with an EDCS Value Characteristic.
 *
 *   This mapping type only occurs when mapping EA and EE concepts.
 */
#define EDCS_MAPPING_TYP_CHANGE_TO_CHARACTERISTIC (EDCS_Mapping_Type_Code)7

/*
 * GLOBAL_CONSTANT: EDCS_MAPPING_TYP_SPECIAL_CASE
 *
 *   The mapping for the given concept is not implemented in the code
 *   but the description of the mapping will be in the notes field
 *   of the mapping structure.  There will be no mapping entries in
 *   the entry list.
 */
#define EDCS_MAPPING_TYP_SPECIAL_CASE (EDCS_Mapping_Type_Code)8


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_MapUtilGetImplVerInfo
 *
 *   This function returns a string representing the current version of the
 *   EDCS mapping utility library implementation.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   The appropriate string representing the current version of this mapping
 *   library implementation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_MapUtilGetImplVerInfo
(
    void
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeWithValueEntry
 *
 *   Prints the information in the given EDCS_Attribute_With_Value_Entry.
 *
 * PARAMETERS:
 *
 *  value_ptr - pointer to EDCS_Attribute_With_Value_Entry whose contents
 *    are to be printed; if NULL, prints error message and returns to
 *    caller
 *
 *  name_ptr - optional; name of value_ptr field at the caller's level
 *
 *  level - current indentation level. For each level, the output is indented
 *    4 spaces; e.g., level = 0 means no indentation; level = 1 causes an
 *    indent of 4 spaces; level = 2 indents 8 spaces; level = 3 indents
 *    12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintAttributeWithValueEntry
(
    const EDCS_Attribute_With_Value_Entry *value_ptr,
    const char                       *name_ptr,
          EDCS_Count                  level
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintMappingEntry
 *
 *   Prints the information in the given EDCS_Mapping_Entry.
 *
 * PARAMETERS:
 *
 *  value_ptr - pointer to EDCS_Mapping_Entry whose contents are to
 *    be printed; if NULL, prints error message and returns to caller
 *
 *  name_ptr - optional; name of value_ptr field at the caller's level
 *
 *  level - current indentation level. For each level, the output is indented
 *    4 spaces; e.g., level = 0 means no indentation; level = 1 causes an
 *    indent of 4 spaces; level = 2 indents 8 spaces; level = 3 indents
 *    12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintMappingEntry
(
    const EDCS_Mapping_Entry *value_ptr,
    const char               *name_ptr,
          EDCS_Count          level
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintValueCharacteristicCodeEntry
 *
 *   Prints the information in the given
 *   EDCS_Value_Characteristic_Code_Entry.
 *
 * PARAMETERS:
 *
 *  value_ptr - pointer to EDCS_Value_Characteristic_Code_Entry
 *    whose contents are to be printed; if NULL, prints error message and
 *    returns to caller
 *
 *  name_ptr - optional; name of value_ptr field at the caller's level
 *
 *  level - current indentation level. For each level, the output is indented
 *    4 spaces; e.g., level = 0 means no indentation; level = 1 causes an
 *    indent of 4 spaces; level = 2 indents 8 spaces; level = 3 indents
 *    12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintValueCharacteristicCodeEntry
(
    const EDCS_Value_Characteristic_Code_Entry *value_ptr,
    const char                                 *name_ptr,
          EDCS_Count                            level
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintMappingEntryTypeCode
 *
 *   Translates the given EDCS_Mapping_Entry_Type_Code into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *  value - EDCS_Mapping_Entry_Type_Code to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintMappingEntryTypeCode
(
    EDCS_Mapping_Entry_Type_Code value
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintMappingTypeCode
 *
 *   Translates the given EDCS_Mapping_Type_Code into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *  value - EDCS_Mapping_Type_Code to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing error message if value is out of range;
 *   otherwise, buffer is set to the string name equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintMappingTypeCode
(
    EDCS_Mapping_Type_Code value
);

#ifdef __cplusplus
}
#endif

#endif
