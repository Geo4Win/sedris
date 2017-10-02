/*
 * FILE       : edcs_util.h
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   EDCS utilities.
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
 * Ensure that edcs_util.h is only included once.
 */
#ifndef _EDCS_UTIL_H_INCLUDED
#define _EDCS_UTIL_H_INCLUDED
/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "edcs_types.h"

#define EDCS_GetStringAsCharString(string_ptr)\
        (((string_ptr)==NULL) ? NULL: (string_ptr)->characters)

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CloneAttributeValue
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      EDCS_Attribute_Value structure.  In order to reliably duplicate
 *      this data, developers should use the EDCS_CloneAttributeValue()
 *      function.
 *
 *   2) The caller is responsible for calling EDCS_FreeAttributeValue()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the EDCS_Attribute_Value that is to be duplicated
 *
 *   dest_ptr - a pointer to an EDCS_Attribute_Value structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_CloneAttributeValue
(
    const EDCS_Attribute_Value *src_ptr,
          EDCS_Attribute_Value *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareAttributeValues
 *
 *  When comparing:
 *
 *       integers, floats: normal mathematical rules apply
 *
 *       EEs, EVs: underlying compare functions for those codes apply
 *
 *       boolean to boolean:  FALSE is less than TRUE
 *
 *       string to string: strcmp() rules apply
 *
 *       boolean to anything but a boolean: FALSE is 0, TRUE is 1,
 *                                          and a numeric comparison is used
 *
 *       string to anything but a string: the string is 0,
 *                                        and a numeric comparison is used
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to 1st EDCS_Attribute_Value to be compared
 *
 *   b_ptr - pointer to 2nd EDCS_Attribute_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareAttributeValues
(
    const EDCS_Attribute_Value *a_ptr,
    const EDCS_Attribute_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_FreeAttributeValue
 *
 *   Frees any internal pointers in the data in the given EDCS_Attribute_Value
 *   structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   EDCS_CloneAttributeValue(), if dealloc_func_in_ptr is not
 *                   specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the EDCS_Attribute_Value whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if EDCS_CloneAttributeValue()
 *     was used.)
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_FreeAttributeValue
(
    EDCS_Attribute_Value *to_free,
    void                 (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_FreeString
 *
 *   Frees any internal pointers in the data in the given EDCS_String
 *   structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   EDCS_CloneString(), if dealloc_func_in_ptr is not
 *                   specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the EDCS_String whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if EDCS_CloneString() was
 *     used.)
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_FreeString
(
    EDCS_String *to_free,
    void        (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetCountryCodeEntry
 *
 *   Given a 3-character country code, retrieves information
 *   about that country code.
 *
 * PARAMETERS:
 *
 *   country_code - the country_code for which information is being retrieved
 *
 *   result_out_ptr - a pointer to the EDCS_ISO_3166_Entry variable
 *     into which a handle to the information will be placed
 *
 * RETURNS:
 *
 *  EDCS_SC_SUCCESS - and result_out_ptr is set to the appropriate value,
 *    if valid parameters were passed in.
 *
 *  EDCS_SC_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *    unchanged, if country_code or result_out_ptr is NULL.
 *
 *  EDCS_SC_OTHER_FAILURE - and *result_out_ptr is left unchanged, if
 *    country_code is not valid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetCountryCodeEntry
(
    const EDCS_Character        country_code[],
    const EDCS_ISO_3166_Entry **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetLanguageCodeEntry
 *
 *   Given a 2-character language code, retrieves information
 *   about that language code.
 *
 * PARAMETERS:
 *
 *   language_code - the language_code for which information is being retrieved
 *
 *   result_out_ptr - a pointer to the EDCS_ISO_639_Entry variable
 *     into which a handle to the information will be placed
 *
 * RETURNS:
 *
 *  EDCS_SC_SUCCESS - and result_out_ptr is set to the appropriate value,
 *    if valid parameters were passed in.
 *
 *  EDCS_SC_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *    unchanged, if language_code or result_out_ptr is NULL.
 *
 *  EDCS_SC_OTHER_FAILURE - and *result_out_ptr is left unchanged, if
 *    language_code is not valid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_GetLanguageCodeEntry
(
    const EDCS_Character       language_code[],
    const EDCS_ISO_639_Entry **result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_AttributeValueToLongFloat
 *
 *   Converts an EDCS_Attribute_Value to an EDCS_Long_Float.
 *
 *   When converting:
 *
 *     boolean: FALSE is 0, TRUE is 1
 *
 *     string: the string is treated as 0
 *
 *     all others: normal mathematical rules apply
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the EDCS_Attribute_Value to be converted
 *
 *   result_out_ptr - pointer to the EDCS_Long_Float where the result will be
 *     stored
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter is NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and *result_out_ptr is set to zero (0), if
 *     *value_ptr is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_AttributeValueToLongFloat
(
    const EDCS_Attribute_Value *value_ptr,
          EDCS_Long_Float      *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SetString
 *
 *  Creates an EDCS_String given a C string. If locale_ptr is
 *  NULL, EDCS_LOCALE_DEFAULT is used as the locale.
 *
 * PARAMETERS:
 *
 *   locale_ptr - (optional) EDCS_Locale to populate output.
 *
 *   c_str_ptr - C string to populate output
 *
 *   string_out_ptr - EDCS_String being populated
 *
 * RETURNS:
 *
 *  EDCS_SC_SUCCESS -  and *string_out_ptr is populated
 *    from c_str_ptr, if valid parameters were passed in and
 *    all operations succeeded.
 *
 *  EDCS_SC_NULL_REQUIRED_PARAMETER - if string_out_ptr
 *    was NULL.
 *
 *  EDCS_SC_OTHER_FAILURE - if memory allocation failed.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_SetString
(
    const EDCS_Locale *locale_ptr,
    const char        *c_str_ptr,
          EDCS_String *string_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: EDCS_SetStringWithDefaultLocale
 *
 *  Shortcut for a common case, setting the EDCS_String with
 *  EDCS_LOCALE_DEFAULT.
 *
 * PARAMETERS:
 *
 *   see EDCS_SetString()
 *
 * RETURNS:
 *
 *   see EDCS_SetString()
 *
 *-----------------------------------------------------------------------------
 */
#define EDCS_SetStringWithDefaultLocale( \
            c_str_ptr, \
            string_out_ptr \
        ) \
        EDCS_SetString \
        ( \
            NULL, /* locale_ptr */ \
            (c_str_ptr), \
            (string_out_ptr) \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CloneString
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      EDCS_String structure.  In order to reliably duplicate this data,
 *      developers should use the EDCS_CloneString() function.
 *
 *   2) The caller is responsible for calling EDCS_FreeString()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the string that is to be duplicated
 *
 *   dest_ptr - a pointer to an EDCS_String structure within memory managed by
 *     the caller.  Non-dynamically allocated fields in this structure will
 *     be directly populated with data from the input fields.  Dynamically
 *     allocated data will be allocated by this function, then copied from
 *     the input structure.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_CloneString
(
    const EDCS_String *src_ptr,
          EDCS_String *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareCharacters
 *
 *   Compares two EDCS_Characters, on the assumption that they are defined
 *   by the same EDCS_Locale.  This function's signature is compatible
 *   with qsort.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_Character to be compared
 *
 *   b_ptr - handle to 2nd EDCS_Character to be compared
 *
 * RETURNS:
 *
 *   -1 if *a_ptr <  *b_ptr
 *
 *    0 if *a_ptr == *b_ptr
 *
 *    1 if *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareCharacters
(
    const EDCS_Character *a_ptr,
    const EDCS_Character *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareCountIntervals
 *
 *   Compares two EDCS_Count_Intervals.  This function's signature
 *   is compatible with qsort.
 *
 *   The comparison compares lower bounds, then uses upper bounds to
 *   break any ties. If the lower bound and upper bound values match,
 *   closed bounds are considered less than open bounds.
 *
 *   In this instance, the compare operation is as follows. Note that
 *   it does not behave differently if either interval is invalid; it
 *   is the user's responsibility to check for valid input.
 *
 *   1. If either argument is NULL, then the result is based on
 *      comparing the pointers.
 *
 *   2. If the two lower bounds are unequal, the comparison of the
 *      lower bound values determines the result of the compare
 *      operation on the intervals
 *
 *   3. If the two lower bounds are equal, then
 *
 *      3.1) If the interval types are equal, then the comparison of the
 *           upper bounds determines the interval comparison result.
 *
 *      3.2) If the interval types are not equal, and if one interval
 *           has a closed lower bound but the other does not, the
 *           interval with the closed lower bound is determined to be
 *           "less than" the interval with the open lower bound.
 *
 *      3.3) Otherwise,
 *
 *           3.3.1) If the upper bound values are unequal, then
 *                  the comparison of the upper bound values determines
 *                  the result
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_Count_Interval to be compared
 *
 *   b_ptr - handle to 2nd EDCS_Count_Interval to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareCountIntervals
(
    const EDCS_Count_Interval *a_ptr,
    const EDCS_Count_Interval *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareCountValues
 *
 *  Compares two EDCS_Count_Value types.  This function's signature
 *  is compatible with qsort.
 *
 *  The comparison compares lower bounds, then uses upper bounds to
 *  break any ties ( see EDCS_CompareCountIntervals ). If the lower
 *  bound and upper bound values match, closed bounds are considered
 *  less than open bounds.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_Count_Value to be compared
 *
 *   b_ptr - handle to 2nd EDCS_Count_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareCountValues
(
    const EDCS_Count_Value *a_ptr,
    const EDCS_Count_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareIntegerIntervals
 *
 *   Compares two EDCS_Integer_Intervals.  This function's signature
 *   is compatible with qsort. See EDCS_CompareLongFloatIntervals() for
 *   a description of the algorithm used.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_Integer_Interval to be compared
 *
 *   b_ptr - handle to 2nd EDCS_Integer_Interval to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareIntegerIntervals
(
    const EDCS_Integer_Interval *a_ptr,
    const EDCS_Integer_Interval *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareIntegerValues
 *
 *  Compares two EDCS_Integer_Value types.  This function's signature
 *  is compatible with qsort.
 *
 *  The comparison compares lower bounds, then uses upper bounds to
 *  break any ties ( see EDCS_CompareIntegerIntervals ). If the lower
 *  bound and upper bound values match, closed bounds are considered
 *  less than open bounds.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_Integer_Value to be compared
 *
 *   b_ptr - handle to 2nd EDCS_Integer_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareIntegerValues
(
    const EDCS_Integer_Value *a_ptr,
    const EDCS_Integer_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareLocales
 *
 *   Compares two EDCS_Locales.  This function's signature
 *   is compatible with qsort.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_Locale to be compared
 *
 *   b_ptr - handle to 2nd EDCS_Locale to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareLocales
(
    const EDCS_Locale *a_ptr,
    const EDCS_Locale *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareLongFloatIntervals
 *
 *   Compares two EDCS_Long_Float_Intervals.  This function's signature
 *   is compatible with qsort.
 *
 *   The comparison compares lower bounds, then uses upper bounds to
 *   break any ties. If the lower bound and upper bound values match,
 *   closed bounds are considered less than open bounds.
 *
 *   In this instance, the compare operation is as follows. Note that
 *   it does not behave differently if either interval is invalid; it
 *   is the user's responsibility to check for valid input.
 *
 *   1. If either argument is NULL, then the result is based on
 *      comparing the pointers.
 *
 *   2. If the two lower bounds are unequal, the comparison of the
 *      lower bound values determines the result of the compare
 *      operation on the intervals
 *
 *   3. If the two lower bounds are equal, then
 *
 *      3.1) If the interval types are equal, then the comparison of the
 *           upper bounds determines the interval comparison result.
 *
 *      3.2) If the interval types are not equal, and if one interval
 *           has a closed lower bound but the other does not, the
 *           interval with the closed lower bound is determined to be
 *           "less than" the interval with the open lower bound.
 *
 *      3.3) Otherwise,
 *
 *           3.3.1) If the upper bound values are unequal, then
 *                  the comparison of the upper bound values determines
 *                  the result
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_Long_Float_Interval to be compared
 *
 *   b_ptr - handle to 2nd EDCS_Long_Float_Interval to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareLongFloatIntervals
(
    const EDCS_Long_Float_Interval *a_ptr,
    const EDCS_Long_Float_Interval *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareLongFloatValues
 *
 *  Compares two EDCS_Integer_Value types.  This function's signature
 *  is compatible with qsort.
 *
 *  The comparison compares lower bounds, then uses upper bounds to
 *  break any ties ( see EDCS_CompareLongFloatIntervals ). If the lower
 *  bound and upper bound values match, closed bounds are considered
 *  less than open bounds.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_Long_Float_Value to be compared
 *
 *   b_ptr - handle to 2nd EDCS_Long_Float_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareLongFloatValues
(
    const EDCS_Long_Float_Value *a_ptr,
    const EDCS_Long_Float_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_CompareStrings
 *
 *   Compares two EDCS_Strings.  This function's signature
 *   is compatible with qsort.
 *
 *   If the locales match, this is a string comparison; otherwise, the
 *   result is determined by the locale comparison.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st EDCS_String to be compared
 *
 *   b_ptr - handle to 2nd EDCS_String to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
EDCS_CompareStrings
(
    const EDCS_String *a_ptr,
    const EDCS_String *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_IsStateApplicable
 *
 *   Determines if the given ea_code_in is state-applicable.
 *
 * PARAMETERS:
 *
 *   ea_code_in - the EA for which the determination is being made
 *
 *   result_out_ptr - pointer to a variable in the user's memory space where
 *     the result will be copied
 *
 * RETURNS:
 *
 *    EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately, if
 *      valid parameters were passed in.
 *
 *    EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *      result_out_ptr is NULL.
 *
 *    EDCS_SC_INVALID_INPUT_CODE - and *result_out_ptr is set to EDCS_FALSE,
 *      if ea_code_in is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_IsStateApplicable
(
    EDCS_Attribute_Code  ea_code_in,
    EDCS_Boolean        *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_IsStringEmpty
 *
 *   Checks whether the given EDCS_String is an "empty" string.
 *
 *   NOTE: Do NOT use a pointer comparison on the string value with
 *         edcs_empty_string; a string is empty if it is of length zero,
 *         not just if it equals edcs_empty_string.
 *
 * PARAMETERS:
 *
 *   string_ptr - pointer to the EDCS_String being checked
 *
 *   result_out_ptr - pointer to a variable in the user's memory space where
 *     the result will be stored
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set to the appropriate
 *     value, if valid parameters were passed in.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     string_ptr or result_out_ptr is NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and *result_out_ptr is set to EDCS_FALSE, if
 *     string_ptr->characters is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_IsStringEmpty
(
    const EDCS_String  *string_ptr,
          EDCS_Boolean *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToAttributeValueType
 *
 *   Retrieves the EDCS_Attribute_Value_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToAttributeValueType
(
    const char                      *enum_name_in_ptr,
          EDCS_Attribute_Value_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToBoolean
 *
 *   Retrieves the EDCS_Boolean corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToBoolean
(
    const char         *enum_name_in_ptr,
          EDCS_Boolean *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToConceptStatus
 *
 *   Retrieves the EDCS_Concept_Status corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToConceptStatus
(
    const char                *enum_name_in_ptr,
          EDCS_Concept_Status *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToDictionaryType
 *
 *   Retrieves the EDCS_Dictionary_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToDictionaryType
(
    const char                 *enum_name_in_ptr,
          EDCS_Dictionary_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToNull
 *
 *   Retrieves the EDCS_Null corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToNull
(
    const char      *enum_name_in_ptr,
          EDCS_Null *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToNumericValueType
 *
 *   Retrieves the EDCS_Numeric_Value_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToNumericValueType
(
    const char                    *enum_name_in_ptr,
          EDCS_Numeric_Value_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToReferenceType
 *
 *   Retrieves the EDCS_Reference_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToReferenceType
(
    const char                *enum_name_in_ptr,
          EDCS_Reference_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToStatusCode
 *
 *   Retrieves the EDCS_Status_Code corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToStatusCode
(
    const char             *enum_name_in_ptr,
          EDCS_Status_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToUnitStatus
 *
 *   Retrieves the EDCS_Unit_Status corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToUnitStatus
(
    const char             *enum_name_in_ptr,
          EDCS_Unit_Status *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_EnumNameToValueCharacteristicApplicability
 *
 *   Retrieves the EDCS_Value_Characteristic_Applicability corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   EDCS_SC_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   EDCS_SC_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   EDCS_SC_OTHER_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Status_Code
EDCS_EnumNameToValueCharacteristicApplicability
(
    const char                                    *enum_name_in_ptr,
          EDCS_Value_Characteristic_Applicability *result_out_ptr
);


#ifdef __cplusplus
}
#endif

#endif
