/*
 * FILE       : edcs_valid.h
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains prototypes for validating functions for all EDCS types.
 *
 *   A type's validating function checks that:
 *   - any enumerators have valid values
 *   - any array that is allocated at run-time is non-NULL if
 *     it has a non-zero array count
 *
 *   Some types do not have validating functions because they
 *   contain nothing that can be checked. For a struct type,
 *   the corresponding validating function will check only
 *   those fields that need validating.
 *
 *   These functions are intended for use by any application
 *   in order to insure that a given variable has valid values.
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
 * Ensure that edcs_valid.h is included only once.
 */
#ifndef _EDCS_VALID_H_INCLUDED
#define _EDCS_VALID_H_INCLUDED
/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h> /* needed for FILE */
#include "edcs_types.h"


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetErrorFilePtr
 *
 *   Returns the FILE pointer to which error messages are directed.
 *
 * PARAMETERS:
 *
 *   nothing
 *
 * RETURNS:
 *
 *   FILE pointer to stream to which error messages are to be output
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern FILE *
EDCS_GetErrorFilePtr(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SetErrorFilePtr
 *
 *   Sets the FILE pointer to which error messages are directed,
 *   if error messages are requested.
 *
 *   WARNING: If you close this file after calling this function,
 *            remember that the EDCS functions will still try to use it.
 *
 * PARAMETERS:
 *
 *   err_file_ptr -- stream to which error messages are to be output
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
EDCS_SetErrorFilePtr
(
    FILE *err_file_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidLocale
 *
 *   Checks the information in the given EDCS_Locale.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Locale whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Locale is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidLocale
(
    const EDCS_Locale           *value_ptr,
          EDCS_Boolean           print_error,
          EDCS_Count            *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidNonNullString
 *
 *   Checks that given EDCS_String is valid and contains a non-empty string.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_String whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_String is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidNonNullString
(
    const EDCS_String           *value_ptr,
          EDCS_Boolean           print_error,
          EDCS_Count            *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidAttributeValue
 *
 *   Checks the information in the given EDCS_Attribute_Value.
 *
 * PARAMETERS:
 *
 *   attr_code -- meaning
 *
 *   value_ptr -- pointer to EDCS_Attribute_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Attribute_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidAttributeValue
(
          EDCS_Attribute_Code     attr_code,
    const EDCS_Attribute_Value *value_ptr,
          EDCS_Boolean          print_error,
          EDCS_Count           *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidAttributeValueType
 *
 *   Checks if the given value is a valid EDCS_Attribute_Value_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidAttributeValueType
(
    EDCS_Attribute_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidBoolean
 *
 *   Checks if the given value is a valid EDCS_Boolean.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidBoolean
(
    EDCS_Boolean value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidConceptStatus
 *
 *   Checks if the given value is a valid EDCS_Concept_Status.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidConceptStatus
(
    EDCS_Concept_Status value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidCountInterval
 *
 *   Checks the information in the given EDCS_Count_Interval.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Count_Interval whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Count_Interval is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidCountInterval
(
    const EDCS_Count_Interval *value_ptr,
          EDCS_Boolean         print_error,
          EDCS_Count          *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidCountValue
 *
 *   Checks the information in the given EDCS_Count_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Count_Value whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Count_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidCountValue
(
    const EDCS_Count_Value *value_ptr,
          EDCS_Boolean      print_error,
          EDCS_Count       *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidDictionaryType
 *
 *   Checks if the given value is a valid EDCS_Dictionary_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidDictionaryType
(
    EDCS_Dictionary_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidIntegerInterval
 *
 *   Checks the information in the given EDCS_Integer_Interval.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Integer_Interval whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Integer_Interval is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidIntegerInterval
(
    const EDCS_Integer_Interval *value_ptr,
          EDCS_Boolean           print_error,
          EDCS_Count            *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidIntegerValue
 *
 *   Checks the information in the given EDCS_Integer_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Integer_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Integer_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidIntegerValue
(
    const EDCS_Integer_Value *value_ptr,
          EDCS_Boolean        print_error,
          EDCS_Count         *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidLongFloatInterval
 *
 *   Checks the information in the given EDCS_Long_Float_Interval.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Long_Float_Interval whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Long_Float_Interval is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidLongFloatInterval
(
    const EDCS_Long_Float_Interval *value_ptr,
          EDCS_Boolean              print_error,
          EDCS_Count               *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidLongFloatValue
 *
 *   Checks the information in the given EDCS_Long_Float_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Long_Float_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Long_Float_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidLongFloatValue
(
    const EDCS_Long_Float_Value *value_ptr,
          EDCS_Boolean           print_error,
          EDCS_Count            *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidNull
 *
 *   Checks if the given value is a valid EDCS_Null.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidNull
(
    EDCS_Null value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidNumericValueType
 *
 *   Checks if the given value is a valid EDCS_Numeric_Value_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidNumericValueType
(
    EDCS_Numeric_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidRealValue
 *
 *   Checks the information in the given EDCS_Real_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_Real_Value whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_Real_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidRealValue
(
    const EDCS_Real_Value *value_ptr,
          EDCS_Boolean     print_error,
          EDCS_Count      *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidReferenceType
 *
 *   Checks if the given value is a valid EDCS_Reference_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidReferenceType
(
    EDCS_Reference_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidStatusCode
 *
 *   Checks if the given value is a valid EDCS_Status_Code.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidStatusCode
(
    EDCS_Status_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidString
 *
 *   Checks the information in the given EDCS_String.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to EDCS_String whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this EDCS_String is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidString
(
    const EDCS_String *value_ptr,
          EDCS_Boolean  print_error,
          EDCS_Count  *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitStatus
 *
 *   Checks if the given value is a valid EDCS_Unit_Status.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidUnitStatus
(
    EDCS_Unit_Status value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidValueCharacteristicApplicability
 *
 *   Checks if the given value is a valid
 * EDCS_Value_Characteristic_Applicability.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   EDCS_TRUE - if value is valid
 *
 *   EDCS_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern EDCS_Boolean
EDCS_ValidValueCharacteristicApplicability
(
    EDCS_Value_Characteristic_Applicability value
);
#ifdef __cplusplus
}
#endif
#endif
