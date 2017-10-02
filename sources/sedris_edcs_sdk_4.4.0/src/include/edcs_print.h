/* EDCS API
 *
 * FILE       : edcs_print.h
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains print functions for all EDCS types.
 *
 * - EDCS spec. 4.4
 * EDCS SDK Release 4.4.0 - July 1, 2011
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


/*
 * Ensure that edcs_print.h is included only once.
 */
#ifndef _EDCS_PRINT_H_INCLUDED
#define _EDCS_PRINT_H_INCLUDED
#include <stdio.h> /* needed for FILE definition */
#include "edcs_types.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetMinWidth
 *
 *   Retrieves the minimum width used when printing floating-point numbers.
 *
 * PARAMETERS:
 *
 *   nothing
 *
 * RETURNS:
 *
 *   min_width -- minimum field width. If the converted argument is smaller
 *                than min_width, it will be padded on the left with spaces
 *                to make up the field width.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Count
EDCS_GetMinWidth(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetOutFilePtr
 *
 *   Returns the FILE pointer to which output is directed.
 *
 * PARAMETERS:
 *
 *   nothing
 *
 * RETURNS:
 *
 *   FILE pointer to stream to which output is to be directed
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern FILE *
EDCS_GetOutFilePtr(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetPrecision
 *
 *   Retrieves the precision used when printing floating-point numbers.
 *
 * PARAMETERS:
 *
 *   nothing
 *
 * RETURNS:
 *
 *   precision -- number of digits to be printed after the decimal point, when
 *                printing an EDCS_Long_Float
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Count
EDCS_GetPrecision(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SetMinWidth
 *
 *   Sets the minimum width used when printing floating-point numbers.
 *
 * PARAMETERS:
 *
 *   min_width -- minimum field width. If the converted argument is smaller
 *                than min_width, it will be padded on the left with spaces
 *                to make up the field width.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_SetMinWidth
(
    EDCS_Count min_width
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SetOutFilePtr
 *
 *   Sets the FILE pointer to which output is directed.
 *
 *   WARNING: If you close this file after calling this function,
 *            remember that the SE_xxx functions will still
 *            try to use it.
 *
 * PARAMETERS:
 *
 *   out_file_ptr -- stream to which output is to be directed
 *
 * RETURNS:
 *
 *   EDCS_SC_OTHER_FAILURE - and nothing is changed, if err_file_ptr is NULL
 *
 *   EDCS_SC_SUCCESS - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_SetOutFilePtr
(
    FILE *out_file_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SetPrecision
 *
 *   Sets the precision used when printing floating-point numbers.
 *
 * PARAMETERS:
 *
 *   precision -- number of digits to be printed after the decimal point, when
 *                when printing an EDCS_Long_Float
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_SetPrecision
(
    EDCS_Count precision
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeCode
 *
 *   Translates the given EDCS_Attribute_Code into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Attribute_Code to be processed
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
EDCS_PrintAttributeCode
(
    EDCS_Attribute_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeDictionaryEntry
 *
 *   Prints the information in the given EDCS_Attribute_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Attribute_Dictionary_Entry whose contents
 *                are to be printed; if NULL, prints error message and returns
 *                to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintAttributeDictionaryEntry
(
    const EDCS_Attribute_Dictionary_Entry *value_ptr,
    const char                            *name_ptr,
          EDCS_Count                       level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeLabel
 *
 *   Translates the information in the given EDCS_Attribute_Label into a
 *   buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Attribute_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintAttributeLabel
(
    EDCS_Attribute_Label value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeValue
 *
 *   Prints the information in the given EDCS_Attribute_Value.
 *
 * PARAMETERS:
 *
 *   ea_code -- meaning for this item
 *
 *   value_ptr -- pointer to EDCS_Attribute_Value whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintAttributeValue
(
          EDCS_Attribute_Code  ea_code,
    const EDCS_Attribute_Value *value_ptr,
    const char                 *name_ptr,
          EDCS_Count            level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintAttributeValueType
 *
 *   Translates the given EDCS_Attribute_Value_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Attribute_Value_Type to be processed
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
EDCS_PrintAttributeValueType
(
    EDCS_Attribute_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintBoolean
 *
 *   Translates the given EDCS_Boolean into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Boolean to be processed
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
EDCS_PrintBoolean
(
    EDCS_Boolean value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintCharacter
 *
 *   Translates the information in the given EDCS_Character into a buffer that
 *   is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Character to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintCharacter
(
    EDCS_Character value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintClassificationCode
 *
 *   Translates the given EDCS_Classification_Code into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Classification_Code to be processed
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
EDCS_PrintClassificationCode
(
    EDCS_Classification_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintClassificationDictionaryEntry
 *
 *   Prints the information in the given EDCS_Classification_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Classification_Dictionary_Entry whose
 *                contents are to be printed; if NULL, prints error message
 *                and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintClassificationDictionaryEntry
(
    const EDCS_Classification_Dictionary_Entry *value_ptr,
    const char                                 *name_ptr,
          EDCS_Count                            level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintClassificationLabel
 *
 *   Translates the information in the given EDCS_Classification_Label into a
 *   buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Classification_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintClassificationLabel
(
    EDCS_Classification_Label value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintConceptStatus
 *
 *   Translates the given EDCS_Concept_Status into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Concept_Status to be processed
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
EDCS_PrintConceptStatus
(
    EDCS_Concept_Status value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintCount
 *
 *   Translates the information in the given EDCS_Count into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Count to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintCount
(
    EDCS_Count value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintCountInterval
 *
 *   Prints the information in the given EDCS_Count_Interval.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Count_Interval whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintCountInterval
(
    const EDCS_Count_Interval *value_ptr,
    const char                *name_ptr,
          EDCS_Count           level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintCountValue
 *
 *   Prints the information in the given EDCS_Count_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Count_Value whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintCountValue
(
    const EDCS_Count_Value *value_ptr,
    const char             *name_ptr,
          EDCS_Count        level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintDictionaryType
 *
 *   Translates the given EDCS_Dictionary_Type into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Dictionary_Type to be processed
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
EDCS_PrintDictionaryType
(
    EDCS_Dictionary_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintEnumerantCode
 *
 *   Translates the given EDCS_Enumerant_Code into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   ea_code_in - the EA to which the EE belongs.
 *
 *   ee_code_in - the EE whose string label will be returned
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
EDCS_PrintEnumerantCode
(
    const EDCS_Attribute_Code ea_code_in,
    const EDCS_Enumerant_Code ee_code_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintEnumerantDictionaryEntry
 *
 *   Prints the information in the given EDCS_Enumerant_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Enumerant_Dictionary_Entry whose contents
 *                are to be printed; if NULL, prints error message and returns
 *                to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintEnumerantDictionaryEntry
(
    const EDCS_Enumerant_Dictionary_Entry *value_ptr,
    const char                            *name_ptr,
          EDCS_Count                       level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintEnumerantLabel
 *
 *   Translates the information in the given EDCS_Enumerant_Label into a
 *   buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Enumerant_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintEnumerantLabel
(
    EDCS_Enumerant_Label value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintGroupCode
 *
 *   Translates the given EDCS_Group_Code into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   eo_code_in - the EO to which the EG belongs.
 *
 *   eg_code_in - the EG whose string label will be returned
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
EDCS_PrintGroupCode
(
    const EDCS_Organization_Schema_Code eo_code_in,
    const EDCS_Group_Code        eg_code_in
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintGroupDictionaryEntry
 *
 *   Prints the information in the given EDCS_Group_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Group_Dictionary_Entry whose contents are to
 *                be printed; if NULL, prints error message and returns to
 *                caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintGroupDictionaryEntry
(
    const EDCS_Group_Dictionary_Entry *value_ptr,
    const char                        *name_ptr,
          EDCS_Count                   level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintGroupLabel
 *
 *   Translates the information in the given EDCS_Group_Label into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Group_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintGroupLabel
(
    EDCS_Group_Label value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintGroupPair
 *
 *   Prints the information in the given EDCS_Group_Pair.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Group_Pair whose contents are to be printed;
 *                if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintGroupPair
(
    const EDCS_Group_Pair *value_ptr,
    const char            *name_ptr,
          EDCS_Count       level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintInteger
 *
 *   Translates the information in the given EDCS_Integer into a buffer that
 *   is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Integer to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintInteger
(
    EDCS_Integer value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintIntegerInterval
 *
 *   Prints the information in the given EDCS_Integer_Interval.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Integer_Interval whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintIntegerInterval
(
    const EDCS_Integer_Interval *value_ptr,
    const char                  *name_ptr,
          EDCS_Count             level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintIntegerValue
 *
 *   Prints the information in the given EDCS_Integer_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Integer_Value whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintIntegerValue
(
    const EDCS_Integer_Value *value_ptr,
    const char               *name_ptr,
          EDCS_Count          level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintISO3166Entry
 *
 *   Prints the information in the given EDCS_ISO_3166_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_ISO_3166_Entry whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintISO3166Entry
(
    const EDCS_ISO_3166_Entry *value_ptr,
    const char                *name_ptr,
          EDCS_Count           level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintISO639Entry
 *
 *   Prints the information in the given EDCS_ISO_639_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_ISO_639_Entry whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintISO639Entry
(
    const EDCS_ISO_639_Entry *value_ptr,
    const char               *name_ptr,
          EDCS_Count          level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintLocale
 *
 *   Prints the information in the given EDCS_Locale.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Locale whose contents are to be printed; if
 *                NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintLocale
(
    const EDCS_Locale *value_ptr,
    const char        *name_ptr,
          EDCS_Count   level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintLongFloat
 *
 *   Translates the information in the given EDCS_Long_Float into a buffer
 *   that is suitable for printing. The precision and minimum field width to
 *   be used are set by EDCS_SetPrecision and EDCS_SetMinWidth.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Long_Float to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintLongFloat
(
    EDCS_Long_Float value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintLongFloatInterval
 *
 *   Prints the information in the given EDCS_Long_Float_Interval.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Long_Float_Interval whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintLongFloatInterval
(
    const EDCS_Long_Float_Interval *value_ptr,
    const char                     *name_ptr,
          EDCS_Count                level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintLongFloatValue
 *
 *   Prints the information in the given EDCS_Long_Float_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Long_Float_Value whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintLongFloatValue
(
    const EDCS_Long_Float_Value *value_ptr,
    const char                  *name_ptr,
          EDCS_Count             level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintNull
 *
 *   Translates the given EDCS_Null into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Null to be processed
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
EDCS_PrintNull
(
    EDCS_Null value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintNumericValueType
 *
 *   Translates the given EDCS_Numeric_Value_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Numeric_Value_Type to be processed
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
EDCS_PrintNumericValueType
(
    EDCS_Numeric_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintOrganizationSchemaCode
 *
 *   Translates the given EDCS_Organization_Schema_Code into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Organization_Schema_Code to be processed
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
EDCS_PrintOrganizationSchemaCode
(
    EDCS_Organization_Schema_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintOrganizationSchemaDictionaryEntry
 *
 *   Prints the information in the given EDCS_Organization_Schema_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Organization_Schema_Dictionary_Entry whose
 *                contents are to be printed; if NULL, prints error message
 *                and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintOrganizationSchemaDictionaryEntry
(
    const EDCS_Organization_Schema_Dictionary_Entry *value_ptr,
    const char                                      *name_ptr,
          EDCS_Count                                 level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintOrganizationSchemaLabel
 *
 *   Translates the information in the given EDCS_Organization_Schema_Label
 *   into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Organization_Schema_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintOrganizationSchemaLabel
(
    EDCS_Organization_Schema_Label value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintRealValue
 *
 *   Prints the information in the given EDCS_Real_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Real_Value whose contents are to be printed;
 *                if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintRealValue
(
    const EDCS_Real_Value *value_ptr,
    const char            *name_ptr,
          EDCS_Count       level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintReferenceType
 *
 *   Translates the given EDCS_Reference_Type into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Reference_Type to be processed
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
EDCS_PrintReferenceType
(
    EDCS_Reference_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintStatusCode
 *
 *   Translates the given EDCS_Status_Code into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Status_Code to be processed
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
EDCS_PrintStatusCode
(
    EDCS_Status_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintString
 *
 *   Prints the information in the given EDCS_String.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_String whose contents are to be printed; if
 *                NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintString
(
    const EDCS_String *value_ptr,
    const char        *name_ptr,
          EDCS_Count   level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitCode
 *
 *   Translates the given EDCS_Unit_Code into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Unit_Code to be processed
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
EDCS_PrintUnitCode
(
    EDCS_Unit_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitConcept
 *
 *   Prints the information in the given EDCS_Unit_Concept.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Unit_Concept whose contents are to be
 *                printed; if NULL, prints error message and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintUnitConcept
(
    const EDCS_Unit_Concept *value_ptr,
    const char              *name_ptr,
          EDCS_Count         level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitDictionaryEntry
 *
 *   Prints the information in the given EDCS_Unit_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Unit_Dictionary_Entry whose contents are to
 *                be printed; if NULL, prints error message and returns to
 *                caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintUnitDictionaryEntry
(
    const EDCS_Unit_Dictionary_Entry *value_ptr,
    const char                       *name_ptr,
          EDCS_Count                  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitEquivalenceCode
 *
 *   Translates the given EDCS_Unit_Equivalence_Code into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Unit_Equivalence_Code to be processed
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
EDCS_PrintUnitEquivalenceCode
(
    EDCS_Unit_Equivalence_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitEquivalenceDictionaryEntry
 *
 *   Prints the information in the given EDCS_Unit_Equivalence_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Unit_Equivalence_Dictionary_Entry whose
 *                contents are to be printed; if NULL, prints error message
 *                and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintUnitEquivalenceDictionaryEntry
(
    const EDCS_Unit_Equivalence_Dictionary_Entry *value_ptr,
    const char                                   *name_ptr,
          EDCS_Count                              level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitEquivalenceLabel
 *
 *   Translates the information in the given EDCS_Unit_Equivalence_Label into
 *   a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Unit_Equivalence_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintUnitEquivalenceLabel
(
    EDCS_Unit_Equivalence_Label value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitLabel
 *
 *   Translates the information in the given EDCS_Unit_Label into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Unit_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintUnitLabel
(
    EDCS_Unit_Label value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitScaleCode
 *
 *   Translates the given EDCS_Unit_Scale_Code into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Unit_Scale_Code to be processed
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
EDCS_PrintUnitScaleCode
(
    EDCS_Unit_Scale_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitScaleDictionaryEntry
 *
 *   Prints the information in the given EDCS_Unit_Scale_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Unit_Scale_Dictionary_Entry whose contents
 *                are to be printed; if NULL, prints error message and returns
 *                to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintUnitScaleDictionaryEntry
(
    const EDCS_Unit_Scale_Dictionary_Entry *value_ptr,
    const char                             *name_ptr,
          EDCS_Count                        level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitScaleLabel
 *
 *   Translates the information in the given EDCS_Unit_Scale_Label into a
 *   buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Unit_Scale_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintUnitScaleLabel
(
    EDCS_Unit_Scale_Label value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitStatus
 *
 *   Translates the given EDCS_Unit_Status into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Unit_Status to be processed
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
EDCS_PrintUnitStatus
(
    EDCS_Unit_Status value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintValueCharacteristicApplicability
 *
 *   Translates the given EDCS_Value_Characteristic_Applicability into a
 *   buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Value_Characteristic_Applicability to be processed
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
EDCS_PrintValueCharacteristicApplicability
(
    EDCS_Value_Characteristic_Applicability value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintValueCharacteristicCode
 *
 *   Translates the given EDCS_Value_Characteristic_Code into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Value_Characteristic_Code to be processed
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
EDCS_PrintValueCharacteristicCode
(
    EDCS_Value_Characteristic_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintValueCharacteristicDictionaryEntry
 *
 *   Prints the information in the given EDCS_Value_Characteristic_Dictionary_Entry.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Value_Characteristic_Dictionary_Entry whose
 *                contents are to be printed; if NULL, prints error message
 *                and returns to caller
 *
 *   name_ptr -- optional; name of value_ptr field at the caller's level
 *
 *   level -- current indentation level. For each level, the output is
 *            indented 4 spaces; e.g., level = 0 means no indentation;
 *            level = 1 causes an indent of 4 spaces; level = 2 indents
 *            8 spaces, level = 3 indents 12 spaces, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
EDCS_PrintValueCharacteristicDictionaryEntry
(
    const EDCS_Value_Characteristic_Dictionary_Entry *value_ptr,
    const char                                       *name_ptr,
          EDCS_Count                                  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintValueCharacteristicLabel
 *
 *   Translates the information in the given EDCS_Value_Characteristic_Label
 *   into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- EDCS_Value_Characteristic_Label to be processed
 *
 * RETURNS:
 *
 *   static buffer, containing an error message if value is invalid; otherwise,
 *   contains the string label equivalent to value.
 *
 *   Note that if you want to keep the results of this function, you must
 *   copy them out of the pointer that is returned, because the contents of
 *   the buffer will be overwritten the next time this function is called.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern const char *
EDCS_PrintValueCharacteristicLabel
(
    EDCS_Value_Characteristic_Label value
);
#ifdef __cplusplus
}
#endif

#endif /* #ifndef/define/endif for _EDCS_PRINT_H_INCLUDED */
