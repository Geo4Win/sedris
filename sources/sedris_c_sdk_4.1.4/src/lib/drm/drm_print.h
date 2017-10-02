/* SEDRIS DRM API
 *
 * FILE       : drm_print.h
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Contains print functions for all SEDRIS DRM types, and for
 *   an object's fields.
 *
 * - DRM spec. 4.1
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
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
 * Ensure that drm_print.h is included only once.
 */
#ifndef _DRM_PRINT_H_INCLUDED
#define _DRM_PRINT_H_INCLUDED

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

#include "drm_types.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetMinWidth
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
EXPORT_DLL extern SE_Integer_Unsigned
SE_GetMinWidth(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetOutFilePtr
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
SE_GetOutFilePtr(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetPrecision
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
 *                printing an SE_Float or SE_Long_Float
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Integer_Unsigned
SE_GetPrecision(void);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetMinWidth
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
SE_SetMinWidth
(
    SE_Integer_Unsigned min_width
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetOutFilePtr
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
 *   SE_DRM_STAT_CODE_FAILURE - and nothing is changed, if err_file_ptr is NULL
 *
 *   SE_DRM_STAT_CODE_SUCCESS - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetOutFilePtr
(
    FILE *out_file_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetPrecision
 *
 *   Sets the precision used when printing floating-point numbers.
 *
 * PARAMETERS:
 *
 *   precision -- number of digits to be printed after the decimal point, when
 *                when printing an SE_Float or SE_Long_Float
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_SetPrecision
(
    SE_Integer_Unsigned precision
);
/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDRMClassFields
 *
 *   Prints the object's fields.
 *
 * PARAMETERS:
 *
 *   field_ptr -- pointer to fields to print
 *
 *   name_ptr -- optional; name of field_ptr at the caller's level
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
void
SE_PrintDRMClassFields
(
          SE_FIELDS_PTR  field_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);

#define SE_PrintFields( \
            field_ptr, \
            name_ptr, \
            level \
        ) \
        SE_PrintDRMClassFields \
        ( \
            (field_ptr), \
            (name_ptr), \
            (level) \
        )




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAddress
 *
 *   Prints the information in the given SE_Address.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Address whose contents are to be printed; if
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
SE_PrintAddress
(
    const SE_Address          *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAPI
 *
 *   Translates the given SE_API into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_API to be processed
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
SE_PrintAPI
(
    SE_API value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintAxisAlignment
 *
 *   Translates the given SE_Axis_Alignment into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Axis_Alignment to be processed
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
SE_PrintAxisAlignment
(
    SE_Axis_Alignment value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintBoolean
 *
 *   Translates the given SE_Boolean into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Boolean to be processed
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
SE_PrintBoolean
(
    SE_Boolean value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintByte
 *
 *   Translates the information in the given SE_Byte into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Byte to be processed
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
SE_PrintByte
(
    SE_Byte value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintBytePositive
 *
 *   Translates the information in the given SE_Byte_Positive into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Byte_Positive to be processed
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
SE_PrintBytePositive
(
    SE_Byte_Positive value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintByteUnsigned
 *
 *   Translates the information in the given SE_Byte_Unsigned into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Byte_Unsigned to be processed
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
SE_PrintByteUnsigned
(
    SE_Byte_Unsigned value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCameraProjectionType
 *
 *   Translates the given SE_Camera_Projection_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Camera_Projection_Type to be processed
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
SE_PrintCameraProjectionType
(
    SE_Camera_Projection_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCharacter
 *
 *   Translates the information in the given SE_Character into a buffer that
 *   is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Character to be processed
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
SE_PrintCharacter
(
    SE_Character value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCIOnlineFunctionCode
 *
 *   Translates the given SE_CI_OnlineFunctionCode into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_CI_OnlineFunctionCode to be processed
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
SE_PrintCIOnlineFunctionCode
(
    SE_CI_OnlineFunctionCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCIOnlineResource
 *
 *   Prints the information in the given SE_CI_OnlineResource.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_CI_OnlineResource whose contents are to be
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
SE_PrintCIOnlineResource
(
    const SE_CI_OnlineResource *value_ptr,
    const char                 *name_ptr,
          SE_Integer_Unsigned   level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCIRoleCode
 *
 *   Translates the given SE_CI_RoleCode into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_CI_RoleCode to be processed
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
SE_PrintCIRoleCode
(
    SE_CI_RoleCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCMYData
 *
 *   Prints the information in the given SE_CMY_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_CMY_Data whose contents are to be printed; if
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
SE_PrintCMYData
(
    const SE_CMY_Data         *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCMYKData
 *
 *   Prints the information in the given SE_CMYK_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_CMYK_Data whose contents are to be printed; if
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
SE_PrintCMYKData
(
    const SE_CMYK_Data        *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintColourBinding
 *
 *   Translates the given SE_Colour_Binding into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Colour_Binding to be processed
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
SE_PrintColourBinding
(
    SE_Colour_Binding value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintColourData
 *
 *   Prints the information in the given SE_Colour_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Colour_Data whose contents are to be printed;
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
SE_PrintColourData
(
    const SE_Colour_Data      *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintColourMapping
 *
 *   Prints the information in the given SE_Colour_Mapping.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Colour_Mapping whose contents are to be
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
SE_PrintColourMapping
(
    const SE_Colour_Mapping   *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintColourModel
 *
 *   Translates the given SE_Colour_Model into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Colour_Model to be processed
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
SE_PrintColourModel
(
    SE_Colour_Model value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintContactInformation
 *
 *   Prints the information in the given SE_Contact_Information.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Contact_Information whose contents are to be
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
SE_PrintContactInformation
(
    const SE_Contact_Information *value_ptr,
    const char                   *name_ptr,
          SE_Integer_Unsigned     level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintCountIntervalValue
 *
 *   Prints the information in the given SE_Count_Interval_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Count_Interval_Value whose contents are to be
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
SE_PrintCountIntervalValue
(
    const SE_Count_Interval_Value *value_ptr,
    const char                    *name_ptr,
          SE_Integer_Unsigned      level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDataQualityElement
 *
 *   Prints the information in the given SE_Data_Quality_Element.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Data_Quality_Element whose contents are to be
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
SE_PrintDataQualityElement
(
    const SE_Data_Quality_Element *value_ptr,
    const char                    *name_ptr,
          SE_Integer_Unsigned      level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDataTableDataValueType
 *
 *   Translates the given SE_Data_Table_Data_Value_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Data_Table_Data_Value_Type to be processed
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
SE_PrintDataTableDataValueType
(
    SE_Data_Table_Data_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDisplaySide
 *
 *   Prints the information in the given SE_Display_Side.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Display_Side whose contents are to be printed;
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
SE_PrintDisplaySide
(
    const SE_Display_Side     *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDisplayStyle
 *
 *   Prints the information in the given SE_Display_Style.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Display_Style whose contents are to be
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
SE_PrintDisplayStyle
(
    const SE_Display_Style    *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDRMClass
 *
 *   Translates the given SE_DRM_Class into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_DRM_Class to be processed
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
SE_PrintDRMClass
(
    SE_DRM_Class value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDRMStatusCode
 *
 *   Translates the given SE_DRM_Status_Code into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_DRM_Status_Code to be processed
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
SE_PrintDRMStatusCode
(
    SE_DRM_Status_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintDRMType
 *
 *   Translates the given SE_DRM_Type into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_DRM_Type to be processed
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
SE_PrintDRMType
(
    SE_DRM_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintElementType
 *
 *   Prints the information in the given SE_Element_Type.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Element_Type whose contents are to be printed;
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
SE_PrintElementType
(
    const SE_Element_Type     *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintElementTypeCode
 *
 *   Translates the given SE_Element_Type_Code into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Element_Type_Code to be processed
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
SE_PrintElementTypeCode
(
    SE_Element_Type_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintEnumerantStructure
 *
 *   Prints the information in the given SE_Enumerant_Structure.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Enumerant_Structure whose contents are to be
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
SE_PrintEnumerantStructure
(
    const SE_Enumerant_Structure *value_ptr,
    const char                   *name_ptr,
          SE_Integer_Unsigned     level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintFeatureTopologyLevel
 *
 *   Translates the given SE_Feature_Topology_Level into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Feature_Topology_Level to be processed
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
SE_PrintFeatureTopologyLevel
(
    SE_Feature_Topology_Level value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintFieldModifier
 *
 *   Translates the given SE_Field_Modifier into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Field_Modifier to be processed
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
SE_PrintFieldModifier
(
    SE_Field_Modifier value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintFloat
 *
 *   Translates the information in the given SE_Float into a buffer that is
 *   suitable for printing. The precision and minimum field width to be used
 *   are set by SE_SetPrecision and SE_SetMinWidth.
 *
 * PARAMETERS:
 *
 *   value -- SE_Float to be processed
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
SE_PrintFloat
(
    SE_Float value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintFontStyle
 *
 *   Translates the given SE_Font_Style into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Font_Style to be processed
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
SE_PrintFontStyle
(
    SE_Font_Style value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintFunctionalAssociationMeaningType
 *
 *   Translates the given SE_Functional_Association_Meaning_Type into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Functional_Association_Meaning_Type to be processed
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
SE_PrintFunctionalAssociationMeaningType
(
    SE_Functional_Association_Meaning_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintGeometricCentreCode
 *
 *   Translates the given SE_Geometric_Centre_Code into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Geometric_Centre_Code to be processed
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
SE_PrintGeometricCentreCode
(
    SE_Geometric_Centre_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintGeometryTopologyLevel
 *
 *   Translates the given SE_Geometry_Topology_Level into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Geometry_Topology_Level to be processed
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
SE_PrintGeometryTopologyLevel
(
    SE_Geometry_Topology_Level value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintGridOverlapOperator
 *
 *   Translates the given SE_Grid_Overlap_Operator into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Grid_Overlap_Operator to be processed
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
SE_PrintGridOverlapOperator
(
    SE_Grid_Overlap_Operator value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHLSData
 *
 *   Prints the information in the given SE_HLS_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_HLS_Data whose contents are to be printed; if
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
SE_PrintHLSData
(
    const SE_HLS_Data         *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHSMultiplicityCode
 *
 *   Translates the given SE_HS_Multiplicity_Code into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_HS_Multiplicity_Code to be processed
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
SE_PrintHSMultiplicityCode
(
    SE_HS_Multiplicity_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintHSVData
 *
 *   Prints the information in the given SE_HSV_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_HSV_Data whose contents are to be printed; if
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
SE_PrintHSVData
(
    const SE_HSV_Data         *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageComponentType
 *
 *   Translates the given SE_Image_Component_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Image_Component_Type to be processed
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
SE_PrintImageComponentType
(
    SE_Image_Component_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageMappingMethod
 *
 *   Translates the given SE_Image_Mapping_Method into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Image_Mapping_Method to be processed
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
SE_PrintImageMappingMethod
(
    SE_Image_Mapping_Method value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageMIPExtents
 *
 *   Prints the information in the given SE_Image_MIP_Extents.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Image_MIP_Extents whose contents are to be
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
SE_PrintImageMIPExtents
(
    const SE_Image_MIP_Extents *value_ptr,
    const char                 *name_ptr,
          SE_Integer_Unsigned   level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageProjectionType
 *
 *   Translates the given SE_Image_Projection_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Image_Projection_Type to be processed
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
SE_PrintImageProjectionType
(
    SE_Image_Projection_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageScanDirection
 *
 *   Translates the given SE_Image_Scan_Direction into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Image_Scan_Direction to be processed
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
SE_PrintImageScanDirection
(
    SE_Image_Scan_Direction value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageScanDirectionZ
 *
 *   Translates the given SE_Image_Scan_Direction_Z into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Image_Scan_Direction_Z to be processed
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
SE_PrintImageScanDirectionZ
(
    SE_Image_Scan_Direction_Z value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageSignature
 *
 *   Translates the given SE_Image_Signature into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Image_Signature to be processed
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
SE_PrintImageSignature
(
    SE_Image_Signature value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintImageWrap
 *
 *   Translates the given SE_Image_Wrap into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Image_Wrap to be processed
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
SE_PrintImageWrap
(
    SE_Image_Wrap value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIndexCode
 *
 *   Translates the given SE_Index_Code into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Index_Code to be processed
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
SE_PrintIndexCode
(
    SE_Index_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintInteger
 *
 *   Translates the information in the given SE_Integer into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Integer to be processed
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
SE_PrintInteger
(
    SE_Integer value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIntegerIntervalValue
 *
 *   Prints the information in the given SE_Integer_Interval_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Integer_Interval_Value whose contents are to
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
SE_PrintIntegerIntervalValue
(
    const SE_Integer_Interval_Value *value_ptr,
    const char                      *name_ptr,
          SE_Integer_Unsigned        level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIntegerPositive
 *
 *   Translates the information in the given SE_Integer_Positive into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Integer_Positive to be processed
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
SE_PrintIntegerPositive
(
    SE_Integer_Positive value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIntegerUnsigned
 *
 *   Translates the information in the given SE_Integer_Unsigned into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Integer_Unsigned to be processed
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
SE_PrintIntegerUnsigned
(
    SE_Integer_Unsigned value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintInterpolationType
 *
 *   Translates the given SE_Interpolation_Type into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Interpolation_Type to be processed
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
SE_PrintInterpolationType
(
    SE_Interpolation_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIntervalType
 *
 *   Translates the given SE_Interval_Type into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Interval_Type to be processed
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
SE_PrintIntervalType
(
    SE_Interval_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIntervalValue
 *
 *   Prints the information in the given SE_Interval_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Interval_Value whose contents are to be
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
SE_PrintIntervalValue
(
    const SE_Interval_Value   *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintIntervalValueType
 *
 *   Translates the given SE_Interval_Value_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Interval_Value_Type to be processed
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
SE_PrintIntervalValueType
(
    SE_Interval_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLocale
 *
 *   Prints the information in the given SE_Locale.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Locale whose contents are to be printed; if
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
SE_PrintLocale
(
    const SE_Locale           *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLODDataType
 *
 *   Translates the given SE_LOD_Data_Type into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_LOD_Data_Type to be processed
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
SE_PrintLODDataType
(
    SE_LOD_Data_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLongFloat
 *
 *   Translates the information in the given SE_Long_Float into a buffer that
 *   is suitable for printing. The precision and minimum field width to be
 *   used are set by SE_SetPrecision and SE_SetMinWidth.
 *
 * PARAMETERS:
 *
 *   value -- SE_Long_Float to be processed
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
SE_PrintLongFloat
(
    SE_Long_Float value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLongFloatIntervalValue
 *
 *   Prints the information in the given SE_Long_Float_Interval_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Long_Float_Interval_Value whose contents are
 *                to be printed; if NULL, prints error message and returns to
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
SE_PrintLongFloatIntervalValue
(
    const SE_Long_Float_Interval_Value *value_ptr,
    const char                         *name_ptr,
          SE_Integer_Unsigned           level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLongFloatValue
 *
 *   Prints the information in the given SE_Long_Float_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Long_Float_Value whose contents are to be
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
SE_PrintLongFloatValue
(
    const SE_Long_Float_Value *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintLSRTransformationAxis
 *
 *   Translates the given SE_LSR_Transformation_Axis into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_LSR_Transformation_Axis to be processed
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
SE_PrintLSRTransformationAxis
(
    SE_LSR_Transformation_Axis value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintMDClassificationCode
 *
 *   Translates the given SE_MD_ClassificationCode into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_MD_ClassificationCode to be processed
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
SE_PrintMDClassificationCode
(
    SE_MD_ClassificationCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintMDKeywordTypeCode
 *
 *   Translates the given SE_MD_KeywordTypeCode into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_MD_KeywordTypeCode to be processed
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
SE_PrintMDKeywordTypeCode
(
    SE_MD_KeywordTypeCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintMDRestrictionCode
 *
 *   Translates the given SE_MD_RestrictionCode into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_MD_RestrictionCode to be processed
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
SE_PrintMDRestrictionCode
(
    SE_MD_RestrictionCode value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintMediaFormat
 *
 *   Translates the given SE_Media_Format into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Media_Format to be processed
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
SE_PrintMediaFormat
(
    SE_Media_Format value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintModelReferenceType
 *
 *   Translates the given SE_Model_Reference_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Model_Reference_Type to be processed
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
SE_PrintModelReferenceType
(
    SE_Model_Reference_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintMonth
 *
 *   Translates the given SE_Month into a buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Month to be processed
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
SE_PrintMonth
(
    SE_Month value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintMultiplicity
 *
 *   Translates the given SE_Multiplicity into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Multiplicity to be processed
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
SE_PrintMultiplicity
(
    SE_Multiplicity value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintOctant
 *
 *   Translates the given SE_Octant into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Octant to be processed
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
SE_PrintOctant
(
    SE_Octant value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintOctet
 *
 *   Translates the information in the given SE_Octet into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Octet to be processed
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
SE_PrintOctet
(
    SE_Octet value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintOrderingReason
 *
 *   Translates the given SE_Ordering_Reason into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Ordering_Reason to be processed
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
SE_PrintOrderingReason
(
    SE_Ordering_Reason value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPixelFillMethod
 *
 *   Translates the given SE_Pixel_Fill_Method into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Pixel_Fill_Method to be processed
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
SE_PrintPixelFillMethod
(
    SE_Pixel_Fill_Method value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPointLightDisplayType
 *
 *   Translates the given SE_Point_Light_Display_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Point_Light_Display_Type to be processed
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
SE_PrintPointLightDisplayType
(
    SE_Point_Light_Display_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPolygonFlag
 *
 *   Prints the information in the given SE_Polygon_Flag.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Polygon_Flag whose contents are to be printed;
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
SE_PrintPolygonFlag
(
    const SE_Polygon_Flag     *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPredefFuncArgStructure
 *
 *   Prints the information in the given SE_Predef_Func_Arg_Structure.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Predef_Func_Arg_Structure whose contents are
 *                to be printed; if NULL, prints error message and returns to
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
SE_PrintPredefFuncArgStructure
(
    const SE_Predef_Func_Arg_Structure *value_ptr,
    const char                         *name_ptr,
          SE_Integer_Unsigned           level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPredefFuncStructure
 *
 *   Prints the information in the given SE_Predef_Func_Structure.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Predef_Func_Structure whose contents are to be
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
SE_PrintPredefFuncStructure
(
    const SE_Predef_Func_Structure *value_ptr,
    const char                     *name_ptr,
          SE_Integer_Unsigned       level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPredefinedFunction
 *
 *   Translates the given SE_Predefined_Function into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Predefined_Function to be processed
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
SE_PrintPredefinedFunction
(
    SE_Predefined_Function value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPresentIn
 *
 *   Translates the given SE_Present_In into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Present_In to be processed
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
SE_PrintPresentIn
(
    SE_Present_In value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPresentationDomain
 *
 *   Prints the information in the given SE_Presentation_Domain.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Presentation_Domain whose contents are to be
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
SE_PrintPresentationDomain
(
    const SE_Presentation_Domain *value_ptr,
    const char                   *name_ptr,
          SE_Integer_Unsigned     level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPropertyCode
 *
 *   Prints the information in the given SE_Property_Code.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Property_Code whose contents are to be
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
SE_PrintPropertyCode
(
    const SE_Property_Code    *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintPropertyCodeType
 *
 *   Translates the given SE_Property_Code_Type into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Property_Code_Type to be processed
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
SE_PrintPropertyCodeType
(
    SE_Property_Code_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintQuadrant
 *
 *   Translates the given SE_Quadrant into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Quadrant to be processed
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
SE_PrintQuadrant
(
    SE_Quadrant value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintReferenceSurfaceElevationSelect
 *
 *   Translates the given SE_Reference_Surface_Elevation_Select into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Reference_Surface_Elevation_Select to be processed
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
SE_PrintReferenceSurfaceElevationSelect
(
    SE_Reference_Surface_Elevation_Select value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintReferenceSurfaceLODSelect
 *
 *   Translates the given SE_Reference_Surface_LOD_Select into a buffer that
 *   is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Reference_Surface_LOD_Select to be processed
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
SE_PrintReferenceSurfaceLODSelect
(
    SE_Reference_Surface_LOD_Select value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintReferenceVectorType
 *
 *   Translates the given SE_Reference_Vector_Type into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Reference_Vector_Type to be processed
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
SE_PrintReferenceVectorType
(
    SE_Reference_Vector_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintRGBData
 *
 *   Prints the information in the given SE_RGB_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_RGB_Data whose contents are to be printed; if
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
SE_PrintRGBData
(
    const SE_RGB_Data         *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintRotationData
 *
 *   Prints the information in the given SE_Rotation_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Rotation_Data whose contents are to be
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
SE_PrintRotationData
(
    const SE_Rotation_Data    *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSeason
 *
 *   Translates the given SE_Season into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Season to be processed
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
SE_PrintSeason
(
    SE_Season value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintShadingMethod
 *
 *   Translates the given SE_Shading_Method into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Shading_Method to be processed
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
SE_PrintShadingMethod
(
    SE_Shading_Method value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintShortInteger
 *
 *   Translates the information in the given SE_Short_Integer into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Short_Integer to be processed
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
SE_PrintShortInteger
(
    SE_Short_Integer value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintShortIntegerPositive
 *
 *   Translates the information in the given SE_Short_Integer_Positive into a
 *   buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Short_Integer_Positive to be processed
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
SE_PrintShortIntegerPositive
(
    SE_Short_Integer_Positive value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintShortIntegerUnsigned
 *
 *   Translates the information in the given SE_Short_Integer_Unsigned into a
 *   buffer that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Short_Integer_Unsigned to be processed
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
SE_PrintShortIntegerUnsigned
(
    SE_Short_Integer_Unsigned value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSingleValue
 *
 *   Prints the information in the given SE_Single_Value.
 *
 * PARAMETERS:
 *
 *   ea_code -- meaning for this item
 *
 *   value_ptr -- pointer to SE_Single_Value whose contents are to be printed;
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
SE_PrintSingleValue
(
          EDCS_Attribute_Code ea_code,
    const SE_Single_Value     *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSingleValueType
 *
 *   Translates the given SE_Single_Value_Type into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Single_Value_Type to be processed
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
SE_PrintSingleValueType
(
    SE_Single_Value_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSoundFormat
 *
 *   Translates the given SE_Sound_Format into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Sound_Format to be processed
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
SE_PrintSoundFormat
(
    SE_Sound_Format value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSpacingType
 *
 *   Translates the given SE_Spacing_Type into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Spacing_Type to be processed
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
SE_PrintSpacingType
(
    SE_Spacing_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSpatialAssociationMeaningType
 *
 *   Translates the given SE_Spatial_Association_Meaning_Type into a buffer
 *   that is suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Spatial_Association_Meaning_Type to be processed
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
SE_PrintSpatialAssociationMeaningType
(
    SE_Spatial_Association_Meaning_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSpatialIndexSpacingUnit
 *
 *   Translates the given SE_Spatial_Index_Spacing_Unit into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Spatial_Index_Spacing_Unit to be processed
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
SE_PrintSpatialIndexSpacingUnit
(
    SE_Spatial_Index_Spacing_Unit value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSRFContextInfo
 *
 *   Prints the information in the given SE_SRF_Context_Info.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_SRF_Context_Info whose contents are to be
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
SE_PrintSRFContextInfo
(
    const SE_SRF_Context_Info *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintStateMismatchBehaviour
 *
 *   Translates the given SE_State_Mismatch_Behaviour into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_State_Mismatch_Behaviour to be processed
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
SE_PrintStateMismatchBehaviour
(
    SE_State_Mismatch_Behaviour value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintString
 *
 *   Prints the information in the given SE_String.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_String whose contents are to be printed; if
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
SE_PrintString
(
    const SE_String           *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintSymbolFormat
 *
 *   Translates the given SE_Symbol_Format into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Symbol_Format to be processed
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
SE_PrintSymbolFormat
(
    SE_Symbol_Format value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTelephoneInformation
 *
 *   Prints the information in the given SE_Telephone_Information.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Telephone_Information whose contents are to be
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
SE_PrintTelephoneInformation
(
    const SE_Telephone_Information *value_ptr,
    const char                     *name_ptr,
          SE_Integer_Unsigned       level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTextFont
 *
 *   Prints the information in the given SE_Text_Font.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Text_Font whose contents are to be printed; if
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
SE_PrintTextFont
(
    const SE_Text_Font        *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeConfiguration
 *
 *   Translates the given SE_Time_Configuration into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Time_Configuration to be processed
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
SE_PrintTimeConfiguration
(
    SE_Time_Configuration value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeDataType
 *
 *   Translates the given SE_Time_Data_Type into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Time_Data_Type to be processed
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
SE_PrintTimeDataType
(
    SE_Time_Data_Type value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeDayOfYearValue
 *
 *   Prints the information in the given SE_Time_Day_Of_Year_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_Day_Of_Year_Value whose contents are to
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
SE_PrintTimeDayOfYearValue
(
    const SE_Time_Day_Of_Year_Value *value_ptr,
    const char                      *name_ptr,
          SE_Integer_Unsigned        level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeMValue
 *
 *   Prints the information in the given SE_Time_M_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_M_Value whose contents are to be printed;
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
SE_PrintTimeMValue
(
    const SE_Time_M_Value     *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeMDHValue
 *
 *   Prints the information in the given SE_Time_MD_H_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_MD_H_Value whose contents are to be
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
SE_PrintTimeMDHValue
(
    const SE_Time_MD_H_Value  *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeMDHMValue
 *
 *   Prints the information in the given SE_Time_MD_HM_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_MD_HM_Value whose contents are to be
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
SE_PrintTimeMDHMValue
(
    const SE_Time_MD_HM_Value *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeMDHMSValue
 *
 *   Prints the information in the given SE_Time_MD_HMS_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_MD_HMS_Value whose contents are to be
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
SE_PrintTimeMDHMSValue
(
    const SE_Time_MD_HMS_Value *value_ptr,
    const char                 *name_ptr,
          SE_Integer_Unsigned   level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeOfDay
 *
 *   Translates the given SE_Time_Of_Day into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Time_Of_Day to be processed
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
SE_PrintTimeOfDay
(
    SE_Time_Of_Day value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeSignificance
 *
 *   Translates the given SE_Time_Significance into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Time_Significance to be processed
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
SE_PrintTimeSignificance
(
    SE_Time_Significance value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeValue
 *
 *   Prints the information in the given SE_Time_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_Value whose contents are to be printed;
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
SE_PrintTimeValue
(
    const SE_Time_Value       *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYValue
 *
 *   Prints the information in the given SE_Time_Y_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_Y_Value whose contents are to be printed;
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
SE_PrintTimeYValue
(
    const SE_Time_Y_Value     *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYDHValue
 *
 *   Prints the information in the given SE_Time_YD_H_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YD_H_Value whose contents are to be
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
SE_PrintTimeYDHValue
(
    const SE_Time_YD_H_Value  *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYDHMValue
 *
 *   Prints the information in the given SE_Time_YD_HM_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YD_HM_Value whose contents are to be
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
SE_PrintTimeYDHMValue
(
    const SE_Time_YD_HM_Value *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYDHMSValue
 *
 *   Prints the information in the given SE_Time_YD_HMS_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YD_HMS_Value whose contents are to be
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
SE_PrintTimeYDHMSValue
(
    const SE_Time_YD_HMS_Value *value_ptr,
    const char                 *name_ptr,
          SE_Integer_Unsigned   level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYDValue
 *
 *   Prints the information in the given SE_Time_YD_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YD_Value whose contents are to be
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
SE_PrintTimeYDValue
(
    const SE_Time_YD_Value    *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYMDHValue
 *
 *   Prints the information in the given SE_Time_YMD_H_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YMD_H_Value whose contents are to be
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
SE_PrintTimeYMDHValue
(
    const SE_Time_YMD_H_Value *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYMDHMValue
 *
 *   Prints the information in the given SE_Time_YMD_HM_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YMD_HM_Value whose contents are to be
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
SE_PrintTimeYMDHMValue
(
    const SE_Time_YMD_HM_Value *value_ptr,
    const char                 *name_ptr,
          SE_Integer_Unsigned   level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYMDHMSValue
 *
 *   Prints the information in the given SE_Time_YMD_HMS_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YMD_HMS_Value whose contents are to be
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
SE_PrintTimeYMDHMSValue
(
    const SE_Time_YMD_HMS_Value *value_ptr,
    const char                  *name_ptr,
          SE_Integer_Unsigned    level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTimeYMDValue
 *
 *   Prints the information in the given SE_Time_YMD_Value.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_Time_YMD_Value whose contents are to be
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
SE_PrintTimeYMDValue
(
    const SE_Time_YMD_Value   *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintTypeClassification
 *
 *   Translates the given SE_Type_Classification into a buffer that is
 *   suitable for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Type_Classification to be processed
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
SE_PrintTypeClassification
(
    SE_Type_Classification value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintUnderlineStyle
 *
 *   Translates the given SE_Underline_Style into a buffer that is suitable
 *   for printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Underline_Style to be processed
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
SE_PrintUnderlineStyle
(
    SE_Underline_Style value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintUnionReason
 *
 *   Translates the given SE_Union_Reason into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Union_Reason to be processed
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
SE_PrintUnionReason
(
    SE_Union_Reason value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintURL
 *
 *   Prints the information in the given SE_URL.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_URL whose contents are to be printed; if NULL,
 *                prints error message and returns to caller
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
SE_PrintURL
(
    const SE_URL              *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintURN
 *
 *   Prints the information in the given SE_URN.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_URN whose contents are to be printed; if NULL,
 *                prints error message and returns to caller
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
SE_PrintURN
(
    const SE_URN              *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintVariableCode
 *
 *   Translates the given SE_Variable_Code into a buffer that is suitable for
 *   printing.
 *
 * PARAMETERS:
 *
 *   value -- SE_Variable_Code to be processed
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
SE_PrintVariableCode
(
    SE_Variable_Code value
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_PrintYIQData
 *
 *   Prints the information in the given SE_YIQ_Data.
 *
 * PARAMETERS:
 *
 *   value_ptr -- pointer to SE_YIQ_Data whose contents are to be printed; if
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
SE_PrintYIQData
(
    const SE_YIQ_Data         *value_ptr,
    const char                *name_ptr,
          SE_Integer_Unsigned  level
);
#ifdef __cplusplus
}
#endif

#endif /* #ifndef/define/endif for _DRM_PRINT_H_INCLUDED */
