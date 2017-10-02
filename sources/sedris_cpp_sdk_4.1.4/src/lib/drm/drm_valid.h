/*
 * FILE       : drm_valid.h
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains prototypes for validating functions for all SEDRIS types,
 *   and for an object's fields.
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
 *   in order to insure that a given variable has valid values;
 *   for example, SE_ValidDRMClassFields() may be used by applications
 *   that check that transmittals are valid, e.g. syntax_checker.
 *
 * - DRM spec. 4.1
 * SEDRIS C++ SDK Release 4.1.4 - July 1, 2011
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
 * Ensure that drm_valid.h is included only once.
 */
#ifndef _DRM_VALID_H_INCLUDED
#define _DRM_VALID_H_INCLUDED

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

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "drm_types.h"


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetErrorFilePtr
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
SE_GetErrorFilePtr(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetErrorFilePtr
 *
 *   Sets the FILE pointer to which error messages are directed,
 *   if error messages are requested.
 *
 *   WARNING: If you close this file after calling this function,
 *            remember that the SE functions will still try to use it.
 *
 * PARAMETERS:
 *
 *   err_file_ptr -- stream to which error messages are to be output
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_FAILURE - and nothing is changed, if err_file_ptr is NULL
 *
 *   SE_DRM_STAT_CODE_SUCCESS - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetErrorFilePtr
(
    FILE *err_file_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCMYData
 *
 *   Checks the information in the given SE_CMY_Data; all values must be
 *   between 0.0 and 1.0, inclusive.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_CMY_Data whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_CMY_Data is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidCMYData
(
    const SE_CMY_Data          *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCMYKData
 *
 *   Checks the information in the given SE_CMYK_Data; all values must be
 *   between 0.0 and 1.0, inclusive.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_CMYK_Data whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_CMYK_Data is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidCMYKData
(
    const SE_CMYK_Data        *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHLSData
 *
 *   Checks the information in the given SE_HLS_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_HLS_Data whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_HLS_Data is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidHLSData
(
    const SE_HLS_Data         *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHSVData
 *
 *   Checks the information in the given SE_HSV_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_HSV_Data whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_HSV_Data is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidHSVData
(
    const SE_HSV_Data         *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLocale
 *
 *   Checks the information in the given SE_Locale.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Locale whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Locale is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidLocale
(
    const SE_Locale           *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidRGBData
 *
 *   Checks the information in the given SE_RGB_Data; all values must be
 *   between 0.0 and 1.0, inclusive.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_RGB_Data whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_RGB_Data is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidRGBData
(
    const SE_RGB_Data         *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);
/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDRMClassFields
 *
 *   Checks the information in the given SE_DRM_Class_Fields, but does not
 *   check constraints that involve checking an object's relationships with
 *   other objects.
 *
 * PARAMETERS:
 *
 *   field_ptr -- fields to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for this
 *     SE_FIELDS_PTR is stored; if NULL, no error counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if fields_ptr is non-NULL and *fields_ptr is valid
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDRMClassFields
(
    SE_FIELDS_PTR        field_ptr,
    SE_Boolean           print_error,
    SE_Integer_Unsigned *error_count_ptr
);

#define SE_ValidFields( \
            field_ptr, \
            print_error, \
            error_count_ptr \
        ) \
        SE_ValidDRMClassFields \
        ( \
            (field_ptr), \
            (print_error), \
            (error_count_ptr) \
        )




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidNonNullString
 *
 *   Checks that given SE_String is valid and contains a non-empty string.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_String whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_String is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidNonNullString
(
    const SE_String           *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAddress
 *
 *   Checks the information in the given SE_Address.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Address whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Address is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAddress
(
    const SE_Address *value_ptr,
          SE_Boolean  print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAPI
 *
 *   Checks if the given value is a valid SE_API.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAPI
(
    SE_API value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidAxisAlignment
 *
 *   Checks if the given value is a valid SE_Axis_Alignment.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidAxisAlignment
(
    SE_Axis_Alignment value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidBoolean
 *
 *   Checks if the given value is a valid SE_Boolean.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidBoolean
(
    SE_Boolean value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidBytePositive
 *
 *   Checks that the given SE_Byte_Positive contains a valid value.
 *
 * PARAMETERS:
 *
 *   value -- SE_Byte_Positive whose contents are to be processed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidBytePositive
(
    SE_Byte_Positive value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCameraProjectionType
 *
 *   Checks if the given value is a valid SE_Camera_Projection_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidCameraProjectionType
(
    SE_Camera_Projection_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCIOnlineFunctionCode
 *
 *   Checks if the given value is a valid SE_CI_OnlineFunctionCode.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidCIOnlineFunctionCode
(
    SE_CI_OnlineFunctionCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCIOnlineResource
 *
 *   Checks the information in the given SE_CI_OnlineResource.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_CI_OnlineResource whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_CI_OnlineResource is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidCIOnlineResource
(
    const SE_CI_OnlineResource *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCIRoleCode
 *
 *   Checks if the given value is a valid SE_CI_RoleCode.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidCIRoleCode
(
    SE_CI_RoleCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidColourBinding
 *
 *   Checks if the given value is a valid SE_Colour_Binding.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidColourBinding
(
    SE_Colour_Binding value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidColourData
 *
 *   Checks the information in the given SE_Colour_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Colour_Data whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Colour_Data is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidColourData
(
    const SE_Colour_Data *value_ptr,
          SE_Boolean      print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidColourMapping
 *
 *   Checks the information in the given SE_Colour_Mapping.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Colour_Mapping whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Colour_Mapping is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidColourMapping
(
    const SE_Colour_Mapping *value_ptr,
          SE_Boolean         print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidColourModel
 *
 *   Checks if the given value is a valid SE_Colour_Model.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidColourModel
(
    SE_Colour_Model value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidContactInformation
 *
 *   Checks the information in the given SE_Contact_Information.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Contact_Information whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Contact_Information is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidContactInformation
(
    const SE_Contact_Information *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCountIntervalValue
 *
 *   Checks the information in the given SE_Count_Interval_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Count_Interval_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Count_Interval_Value is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidCountIntervalValue
(
    const SE_Count_Interval_Value *value_ptr,
          SE_Boolean               print_error,
          SE_Integer_Unsigned     *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDataQualityElement
 *
 *   Checks the information in the given SE_Data_Quality_Element.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Data_Quality_Element whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Data_Quality_Element is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDataQualityElement
(
    const SE_Data_Quality_Element *value_ptr,
          SE_Boolean               print_error,
          SE_Integer_Unsigned     *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDataTableDataValueType
 *
 *   Checks if the given value is a valid SE_Data_Table_Data_Value_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDataTableDataValueType
(
    SE_Data_Table_Data_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDisplaySide
 *
 *   Checks the information in the given SE_Display_Side.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Display_Side whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Display_Side is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDisplaySide
(
    const SE_Display_Side *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDisplayStyle
 *
 *   Checks the information in the given SE_Display_Style.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Display_Style whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Display_Style is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDisplayStyle
(
    const SE_Display_Style *value_ptr,
          SE_Boolean        print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDRMClass
 *
 *   Checks if the given value is a valid SE_DRM_Class.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDRMClass
(
    SE_DRM_Class value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDRMStatusCode
 *
 *   Checks if the given value is a valid SE_DRM_Status_Code.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDRMStatusCode
(
    SE_DRM_Status_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDRMType
 *
 *   Checks if the given value is a valid SE_DRM_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDRMType
(
    SE_DRM_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidElementType
 *
 *   Checks the information in the given SE_Element_Type.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Element_Type whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Element_Type is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidElementType
(
    const SE_Element_Type *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidElementTypeCode
 *
 *   Checks if the given value is a valid SE_Element_Type_Code.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidElementTypeCode
(
    SE_Element_Type_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidEnumerantStructure
 *
 *   Checks the information in the given SE_Enumerant_Structure.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Enumerant_Structure whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Enumerant_Structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidEnumerantStructure
(
    const SE_Enumerant_Structure *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidFeatureTopologyLevel
 *
 *   Checks if the given value is a valid SE_Feature_Topology_Level.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidFeatureTopologyLevel
(
    SE_Feature_Topology_Level value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidFieldModifier
 *
 *   Checks if the given value is a valid SE_Field_Modifier.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidFieldModifier
(
    SE_Field_Modifier value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidFontStyle
 *
 *   Checks if the given value is a valid SE_Font_Style.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidFontStyle
(
    SE_Font_Style value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidFunctionalAssociationMeaningType
 *
 *   Checks if the given value is a valid
 * SE_Functional_Association_Meaning_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidFunctionalAssociationMeaningType
(
    SE_Functional_Association_Meaning_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGeometricCentreCode
 *
 *   Checks if the given value is a valid SE_Geometric_Centre_Code.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidGeometricCentreCode
(
    SE_Geometric_Centre_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGeometryTopologyLevel
 *
 *   Checks if the given value is a valid SE_Geometry_Topology_Level.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidGeometryTopologyLevel
(
    SE_Geometry_Topology_Level value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidGridOverlapOperator
 *
 *   Checks if the given value is a valid SE_Grid_Overlap_Operator.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidGridOverlapOperator
(
    SE_Grid_Overlap_Operator value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidHSMultiplicityCode
 *
 *   Checks if the given value is a valid SE_HS_Multiplicity_Code.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidHSMultiplicityCode
(
    SE_HS_Multiplicity_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageComponentType
 *
 *   Checks if the given value is a valid SE_Image_Component_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageComponentType
(
    SE_Image_Component_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageMappingMethod
 *
 *   Checks if the given value is a valid SE_Image_Mapping_Method.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageMappingMethod
(
    SE_Image_Mapping_Method value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageMIPExtents
 *
 *   Checks the information in the given SE_Image_MIP_Extents.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Image_MIP_Extents whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Image_MIP_Extents is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageMIPExtents
(
    const SE_Image_MIP_Extents *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageProjectionType
 *
 *   Checks if the given value is a valid SE_Image_Projection_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageProjectionType
(
    SE_Image_Projection_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageScanDirection
 *
 *   Checks if the given value is a valid SE_Image_Scan_Direction.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageScanDirection
(
    SE_Image_Scan_Direction value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageScanDirectionZ
 *
 *   Checks if the given value is a valid SE_Image_Scan_Direction_Z.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageScanDirectionZ
(
    SE_Image_Scan_Direction_Z value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageSignature
 *
 *   Checks if the given value is a valid SE_Image_Signature.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageSignature
(
    SE_Image_Signature value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidImageWrap
 *
 *   Checks if the given value is a valid SE_Image_Wrap.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidImageWrap
(
    SE_Image_Wrap value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIndexCode
 *
 *   Checks if the given value is a valid SE_Index_Code.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidIndexCode
(
    SE_Index_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntegerIntervalValue
 *
 *   Checks the information in the given SE_Integer_Interval_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Integer_Interval_Value whose contents are to
 *                be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Integer_Interval_Value is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidIntegerIntervalValue
(
    const SE_Integer_Interval_Value *value_ptr,
          SE_Boolean                 print_error,
          SE_Integer_Unsigned       *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntegerPositive
 *
 *   Checks that the given SE_Integer_Positive contains a valid value.
 *
 * PARAMETERS:
 *
 *   value -- SE_Integer_Positive whose contents are to be processed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidIntegerPositive
(
    SE_Integer_Positive value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidInterpolationType
 *
 *   Checks if the given value is a valid SE_Interpolation_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidInterpolationType
(
    SE_Interpolation_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntervalType
 *
 *   Checks if the given value is a valid SE_Interval_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidIntervalType
(
    SE_Interval_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntervalValue
 *
 *   Checks the information in the given SE_Interval_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Interval_Value whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Interval_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidIntervalValue
(
    const SE_Interval_Value *value_ptr,
          SE_Boolean         print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidIntervalValueType
 *
 *   Checks if the given value is a valid SE_Interval_Value_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidIntervalValueType
(
    SE_Interval_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLODDataType
 *
 *   Checks if the given value is a valid SE_LOD_Data_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidLODDataType
(
    SE_LOD_Data_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLongFloatIntervalValue
 *
 *   Checks the information in the given SE_Long_Float_Interval_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Long_Float_Interval_Value whose contents are
 *                to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Long_Float_Interval_Value is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidLongFloatIntervalValue
(
    const SE_Long_Float_Interval_Value *value_ptr,
          SE_Boolean                    print_error,
          SE_Integer_Unsigned          *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLongFloatValue
 *
 *   Checks the information in the given SE_Long_Float_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Long_Float_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Long_Float_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidLongFloatValue
(
    const SE_Long_Float_Value *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidLSRTransformationAxis
 *
 *   Checks if the given value is a valid SE_LSR_Transformation_Axis.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidLSRTransformationAxis
(
    SE_LSR_Transformation_Axis value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMDClassificationCode
 *
 *   Checks if the given value is a valid SE_MD_ClassificationCode.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidMDClassificationCode
(
    SE_MD_ClassificationCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMDKeywordTypeCode
 *
 *   Checks if the given value is a valid SE_MD_KeywordTypeCode.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidMDKeywordTypeCode
(
    SE_MD_KeywordTypeCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMDRestrictionCode
 *
 *   Checks if the given value is a valid SE_MD_RestrictionCode.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidMDRestrictionCode
(
    SE_MD_RestrictionCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMediaFormat
 *
 *   Checks if the given value is a valid SE_Media_Format.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidMediaFormat
(
    SE_Media_Format value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidModelReferenceType
 *
 *   Checks if the given value is a valid SE_Model_Reference_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidModelReferenceType
(
    SE_Model_Reference_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMonth
 *
 *   Checks if the given value is a valid SE_Month.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidMonth
(
    SE_Month value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidMultiplicity
 *
 *   Checks if the given value is a valid SE_Multiplicity.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidMultiplicity
(
    SE_Multiplicity value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidOctant
 *
 *   Checks if the given value is a valid SE_Octant.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidOctant
(
    SE_Octant value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidOrderingReason
 *
 *   Checks if the given value is a valid SE_Ordering_Reason.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidOrderingReason
(
    SE_Ordering_Reason value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPixelFillMethod
 *
 *   Checks if the given value is a valid SE_Pixel_Fill_Method.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPixelFillMethod
(
    SE_Pixel_Fill_Method value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPointLightDisplayType
 *
 *   Checks if the given value is a valid SE_Point_Light_Display_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPointLightDisplayType
(
    SE_Point_Light_Display_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPolygonFlag
 *
 *   Checks the information in the given SE_Polygon_Flag.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Polygon_Flag whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Polygon_Flag is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPolygonFlag
(
    const SE_Polygon_Flag *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPredefFuncArgStructure
 *
 *   Checks the information in the given SE_Predef_Func_Arg_Structure.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Predef_Func_Arg_Structure whose contents are
 *                to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Predef_Func_Arg_Structure is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPredefFuncArgStructure
(
    const SE_Predef_Func_Arg_Structure *value_ptr,
          SE_Boolean                    print_error,
          SE_Integer_Unsigned          *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPredefFuncStructure
 *
 *   Checks the information in the given SE_Predef_Func_Structure.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Predef_Func_Structure whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Predef_Func_Structure is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPredefFuncStructure
(
    const SE_Predef_Func_Structure *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPredefinedFunction
 *
 *   Checks if the given value is a valid SE_Predefined_Function.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPredefinedFunction
(
    SE_Predefined_Function value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPresentIn
 *
 *   Checks if the given value is a valid SE_Present_In.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPresentIn
(
    SE_Present_In value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPresentationDomain
 *
 *   Checks the information in the given SE_Presentation_Domain.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Presentation_Domain whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Presentation_Domain is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPresentationDomain
(
    const SE_Presentation_Domain *value_ptr,
          SE_Boolean              print_error,
          SE_Integer_Unsigned    *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPropertyCode
 *
 *   Checks the information in the given SE_Property_Code.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Property_Code whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Property_Code is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPropertyCode
(
    const SE_Property_Code *value_ptr,
          SE_Boolean        print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidPropertyCodeType
 *
 *   Checks if the given value is a valid SE_Property_Code_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidPropertyCodeType
(
    SE_Property_Code_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidQuadrant
 *
 *   Checks if the given value is a valid SE_Quadrant.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidQuadrant
(
    SE_Quadrant value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidReferenceSurfaceElevationSelect
 *
 *   Checks if the given value is a valid
 * SE_Reference_Surface_Elevation_Select.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidReferenceSurfaceElevationSelect
(
    SE_Reference_Surface_Elevation_Select value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidReferenceSurfaceLODSelect
 *
 *   Checks if the given value is a valid SE_Reference_Surface_LOD_Select.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidReferenceSurfaceLODSelect
(
    SE_Reference_Surface_LOD_Select value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidReferenceVectorType
 *
 *   Checks if the given value is a valid SE_Reference_Vector_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidReferenceVectorType
(
    SE_Reference_Vector_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSeason
 *
 *   Checks if the given value is a valid SE_Season.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSeason
(
    SE_Season value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidShadingMethod
 *
 *   Checks if the given value is a valid SE_Shading_Method.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidShadingMethod
(
    SE_Shading_Method value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidShortIntegerPositive
 *
 *   Checks that the given SE_Short_Integer_Positive contains a valid value.
 *
 * PARAMETERS:
 *
 *   value -- SE_Short_Integer_Positive whose contents are to be processed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidShortIntegerPositive
(
    SE_Short_Integer_Positive value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSingleValue
 *
 *   Checks the information in the given SE_Single_Value.
 *
 * PARAMETERS:
 *
 *   attr_code -- meaning
 *
 *   value_ptr -- pointer to SE_Single_Value whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Single_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSingleValue
(
          EDCS_Attribute_Code     attr_code,
    const SE_Single_Value *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSingleValueType
 *
 *   Checks if the given value is a valid SE_Single_Value_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSingleValueType
(
    SE_Single_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSoundFormat
 *
 *   Checks if the given value is a valid SE_Sound_Format.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSoundFormat
(
    SE_Sound_Format value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSpacingType
 *
 *   Checks if the given value is a valid SE_Spacing_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSpacingType
(
    SE_Spacing_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSpatialAssociationMeaningType
 *
 *   Checks if the given value is a valid SE_Spatial_Association_Meaning_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSpatialAssociationMeaningType
(
    SE_Spatial_Association_Meaning_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSpatialIndexSpacingUnit
 *
 *   Checks if the given value is a valid SE_Spatial_Index_Spacing_Unit.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSpatialIndexSpacingUnit
(
    SE_Spatial_Index_Spacing_Unit value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSRFContextInfo
 *
 *   Checks the information in the given SE_SRF_Context_Info.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_SRF_Context_Info whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_SRF_Context_Info is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSRFContextInfo
(
    const SE_SRF_Context_Info *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidStateMismatchBehaviour
 *
 *   Checks if the given value is a valid SE_State_Mismatch_Behaviour.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidStateMismatchBehaviour
(
    SE_State_Mismatch_Behaviour value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidString
 *
 *   Checks the information in the given SE_String.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_String whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_String is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidString
(
    const SE_String *value_ptr,
          SE_Boolean  print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidSymbolFormat
 *
 *   Checks if the given value is a valid SE_Symbol_Format.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidSymbolFormat
(
    SE_Symbol_Format value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTelephoneInformation
 *
 *   Checks the information in the given SE_Telephone_Information.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Telephone_Information whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Telephone_Information is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTelephoneInformation
(
    const SE_Telephone_Information *value_ptr,
          SE_Boolean                print_error,
          SE_Integer_Unsigned      *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTextFont
 *
 *   Checks the information in the given SE_Text_Font.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Text_Font whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Text_Font is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTextFont
(
    const SE_Text_Font *value_ptr,
          SE_Boolean    print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeConfiguration
 *
 *   Checks if the given value is a valid SE_Time_Configuration.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeConfiguration
(
    SE_Time_Configuration value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeDataType
 *
 *   Checks if the given value is a valid SE_Time_Data_Type.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeDataType
(
    SE_Time_Data_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeDayOfYearValue
 *
 *   Checks the information in the given SE_Time_Day_Of_Year_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_Day_Of_Year_Value whose contents are to
 *                be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_Day_Of_Year_Value is stored; if NULL, no counting is
 *     performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeDayOfYearValue
(
    const SE_Time_Day_Of_Year_Value *value_ptr,
          SE_Boolean                 print_error,
          SE_Integer_Unsigned       *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMValue
 *
 *   Checks the information in the given SE_Time_M_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_M_Value whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_M_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeMValue
(
    const SE_Time_M_Value *value_ptr,
          SE_Boolean       print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMDHValue
 *
 *   Checks the information in the given SE_Time_MD_H_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_MD_H_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_MD_H_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeMDHValue
(
    const SE_Time_MD_H_Value *value_ptr,
          SE_Boolean          print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMDHMValue
 *
 *   Checks the information in the given SE_Time_MD_HM_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_MD_HM_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_MD_HM_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeMDHMValue
(
    const SE_Time_MD_HM_Value *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeMDHMSValue
 *
 *   Checks the information in the given SE_Time_MD_HMS_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_MD_HMS_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_MD_HMS_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeMDHMSValue
(
    const SE_Time_MD_HMS_Value *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeOfDay
 *
 *   Checks if the given value is a valid SE_Time_Of_Day.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeOfDay
(
    SE_Time_Of_Day value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeSignificance
 *
 *   Checks if the given value is a valid SE_Time_Significance.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeSignificance
(
    SE_Time_Significance value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeValue
 *
 *   Checks the information in the given SE_Time_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_Value whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeValue
(
    const SE_Time_Value *value_ptr,
          SE_Boolean     print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYDHValue
 *
 *   Checks the information in the given SE_Time_YD_H_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YD_H_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_YD_H_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeYDHValue
(
    const SE_Time_YD_H_Value *value_ptr,
          SE_Boolean          print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYDHMValue
 *
 *   Checks the information in the given SE_Time_YD_HM_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YD_HM_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_YD_HM_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeYDHMValue
(
    const SE_Time_YD_HM_Value *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYDHMSValue
 *
 *   Checks the information in the given SE_Time_YD_HMS_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YD_HMS_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_YD_HMS_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeYDHMSValue
(
    const SE_Time_YD_HMS_Value *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYDValue
 *
 *   Checks the information in the given SE_Time_YD_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YD_Value whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_YD_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeYDValue
(
    const SE_Time_YD_Value *value_ptr,
          SE_Boolean        print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYMDHValue
 *
 *   Checks the information in the given SE_Time_YMD_H_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YMD_H_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_YMD_H_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeYMDHValue
(
    const SE_Time_YMD_H_Value *value_ptr,
          SE_Boolean           print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYMDHMValue
 *
 *   Checks the information in the given SE_Time_YMD_HM_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YMD_HM_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_YMD_HM_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeYMDHMValue
(
    const SE_Time_YMD_HM_Value *value_ptr,
          SE_Boolean            print_error,
          SE_Integer_Unsigned  *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYMDHMSValue
 *
 *   Checks the information in the given SE_Time_YMD_HMS_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YMD_HMS_Value whose contents are to be
 *                checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_YMD_HMS_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeYMDHMSValue
(
    const SE_Time_YMD_HMS_Value *value_ptr,
          SE_Boolean             print_error,
          SE_Integer_Unsigned   *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTimeYMDValue
 *
 *   Checks the information in the given SE_Time_YMD_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YMD_Value whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_Time_YMD_Value is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTimeYMDValue
(
    const SE_Time_YMD_Value *value_ptr,
          SE_Boolean         print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidTypeClassification
 *
 *   Checks if the given value is a valid SE_Type_Classification.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidTypeClassification
(
    SE_Type_Classification value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidUnderlineStyle
 *
 *   Checks if the given value is a valid SE_Underline_Style.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidUnderlineStyle
(
    SE_Underline_Style value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidUnionReason
 *
 *   Checks if the given value is a valid SE_Union_Reason.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidUnionReason
(
    SE_Union_Reason value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidURL
 *
 *   Checks the information in the given SE_URL.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_URL whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_URL is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidURL
(
    const SE_URL *value_ptr,
          SE_Boolean  print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidURN
 *
 *   Checks the information in the given SE_URN.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_URN whose contents are to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for
 *     this SE_URN is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidURN
(
    const SE_URN *value_ptr,
          SE_Boolean  print_error,
          SE_Integer_Unsigned *error_count_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidVariableCode
 *
 *   Checks if the given value is a valid SE_Variable_Code.
 *
 * PARAMETERS:
 *
 *   value -- value to be checked
 *
 * RETURNS:
 *
 *   SE_TRUE - if value is valid
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidVariableCode
(
    SE_Variable_Code value
);
#ifdef __cplusplus
}
#endif
#endif
