/* SRM API
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 *
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
 *
 *
 *
 *
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 *
 */

/** @file   srm_print.h
    @author Automatically generated file
    @brief  Provides reusable printing functions for various SRM types.
 */

/*
 * For other release dates/detailed changes, contact SAIC.
 */



/*
 * Ensure that srm_print.h is included only once.
 */
#ifndef _SRM_PRINT_H_INCLUDED
#define _SRM_PRINT_H_INCLUDED

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

#include <stdio.h> /* needed for FILE definition */
#include "srm_types.h"


/*-----------------------------------------------------------------------------*/
/** Retrieves the minimum width used when printing floating-point numbers.
    @return min_width -- minimum field width. If the converted argument is smaller
            than min_width, it will be padded on the left with spaces to make up
            the field width.
 */
/*-----------------------------------------------------------------------------*/

EXPORT_DLL extern SRM_Integer_Unsigned
SRM_GetMinWidth(void);


/*-----------------------------------------------------------------------------*/
/** Returns the FILE pointer to which output is directed.
    @return FILE pointer to stream to which output is to be directed
 */
/*-----------------------------------------------------------------------------*/

EXPORT_DLL extern FILE *
SRM_GetOutFilePtr(void);


/*-----------------------------------------------------------------------------*/
/** Retrieves the precision used when printing floating-point numbers.

  @return precision -- number of digits to be printed after the decimal point,
             when printing an SRM_Long_Float
 */
/*-----------------------------------------------------------------------------*/

EXPORT_DLL extern SRM_Integer_Unsigned
SRM_GetPrecision(void);


/*-----------------------------------------------------------------------------*/
/** Sets the minimum width used when printing floating-point numbers.
    @param  min_width -- minimum field width. If the converted argument is smaller
            than min_width, it will be padded on the left with spaces
            to make up the field width.
 */
/*-----------------------------------------------------------------------------*/

EXPORT_DLL extern void
SRM_SetMinWidth
(
    SRM_Integer_Unsigned min_width
);


/*-----------------------------------------------------------------------------*/
/** Sets the FILE pointer to which output is directed.
    @warning If you close this file after calling this function,
             remember that the SE_xxx functions will still
             try to use it.

    @param out_file_ptr -- stream to which output is to be directed

    @return SRM_STATCOD_INACTIONABLE - and nothing is changed, if err_file_ptr
            is NULL
    @return SRM_STATCOD_SUCCESS - otherwise
 */
/*-----------------------------------------------------------------------------*/

EXPORT_DLL extern SRM_Status_Code
SRM_SetOutFilePtr
(
    FILE *out_file_ptr
);


/*-----------------------------------------------------------------------------*/
/** Sets the precision used when printing floating-point numbers.
    @param precision -- number of digits to be printed after the decimal point, when
           when printing an SRM_Float or SRM_Long_Float
 */
/*-----------------------------------------------------------------------------*/

EXPORT_DLL extern void
SRM_SetPrecision
(
    SRM_Integer_Unsigned precision
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_Axis_Direction into a buffer that is suitable for
     printing.

     @param value -- SRM_Axis_Direction to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintAxisDirection
(
    SRM_Axis_Direction value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_Boolean into a buffer that is suitable for
     printing.

     @param value -- SRM_Boolean to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintBoolean
(
    SRM_Boolean value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_CD_3D_Coordinate.
     @param value_ptr -- pointer to SRM_CD_3D_Coordinate whose contents are to
                  be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintCD3DCoordinate
(
    const SRM_CD_3D_Coordinate *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_CD_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_CD_Surface_Coordinate whose contents
                  are to be printed; if NULL, prints error message and returns
                  to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintCDSurfaceCoordinate
(
    const SRM_CD_Surface_Coordinate *value_ptr,
    const char                      *name_ptr,
          SRM_Integer_Unsigned       level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Coordinate.
     @param value_ptr -- pointer to SRM_Coordinate whose contents are to be
                  printed; if NULL, prints error message and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintCoordinate
(
    const SRM_Coordinate       *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_Coordinate_Valid_Region into a buffer that is
     suitable for printing.

     @param value -- SRM_Coordinate_Valid_Region to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintCoordinateValidRegion
(
    SRM_Coordinate_Valid_Region value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Coordinate_Valid_Region_Array.
     @param value_ptr -- pointer to SRM_Coordinate_Valid_Region_Array whose
                  contents are to be printed; if NULL, prints error message
                  and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintCoordinateValidRegionArray
(
    const SRM_Coordinate_Valid_Region_Array *value_ptr,
    const char                              *name_ptr,
          SRM_Integer_Unsigned               level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_CS_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_CS_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintCSCode
(
    SRM_CS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_DSS_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_DSS_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintDSSCode
(
    SRM_DSS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_EC_Parameters.
     @param value_ptr -- pointer to SRM_EC_Parameters whose contents are to be
                  printed; if NULL, prints error message and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintECParameters
(
    const SRM_EC_Parameters    *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_EI_3D_Coordinate.
     @param value_ptr -- pointer to SRM_EI_3D_Coordinate whose contents are to
                  be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintEI3DCoordinate
(
    const SRM_EI_3D_Coordinate *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Euclidean_2D_Coordinate.
     @param value_ptr -- pointer to SRM_Euclidean_2D_Coordinate whose contents
                  are to be printed; if NULL, prints error message and returns
                  to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintEuclidean2DCoordinate
(
    const SRM_Euclidean_2D_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Euclidean_3D_Coordinate.
     @param value_ptr -- pointer to SRM_Euclidean_3D_Coordinate whose contents
                  are to be printed; if NULL, prints error message and returns
                  to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintEuclidean3DCoordinate
(
    const SRM_Euclidean_3D_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the information in the given SRM_Integer into a buffer that is
     @param value -- SRM_Integer to be processed
 
     @return static buffer, containing an error message if value is invalid;
             otherwise, contains the string label equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/

EXPORT_DLL extern const char *
SRM_PrintInteger
(
    SRM_Integer value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the information in the given SRM_Integer_Positive into a buffer
     @param value -- SRM_Integer_Positive to be processed
 
     @return static buffer, containing an error message if value is invalid;
             otherwise, contains the string label equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/

EXPORT_DLL extern const char *
SRM_PrintIntegerPositive
(
    SRM_Integer_Positive value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the information in the given SRM_Integer_Unsigned into a buffer
     @param value -- SRM_Integer_Unsigned to be processed
 
     @return static buffer, containing an error message if value is invalid;
             otherwise, contains the string label equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/

EXPORT_DLL extern const char *
SRM_PrintIntegerUnsigned
(
    SRM_Integer_Unsigned value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_Interval_Type into a buffer that is suitable for
     printing.

     @param value -- SRM_Interval_Type to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintIntervalType
(
    SRM_Interval_Type value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LCC_Parameters.
     @param value_ptr -- pointer to SRM_LCC_Parameters whose contents are to
                  be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLCCParameters
(
    const SRM_LCC_Parameters   *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LCE_3D_Parameters.
     @param value_ptr -- pointer to SRM_LCE_3D_Parameters whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLCE3DParameters
(
    const SRM_LCE_3D_Parameters *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Local_Tangent_Parameters.
     @param value_ptr -- pointer to SRM_Local_Tangent_Parameters whose
                  contents are to be printed; if NULL, prints error message
                  and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLocalTangentParameters
(
    const SRM_Local_Tangent_Parameters *value_ptr,
    const char                         *name_ptr,
          SRM_Integer_Unsigned          level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the information in the given SRM_Long_Float into a buffer that
     is suitable for printing. The precision and minimum field width to be
     @param value -- SRM_Long_Float to be processed
 
     @return static buffer, containing an error message if value is invalid;
             otherwise, contains the string label equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/

EXPORT_DLL extern const char *
SRM_PrintLongFloat
(
    SRM_Long_Float value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LSA_2D_Coordinate.
     @param value_ptr -- pointer to SRM_LSA_2D_Coordinate whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLSA2DCoordinate
(
    const SRM_LSA_2D_Coordinate *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LSP_2D_Coordinate.
     @param value_ptr -- pointer to SRM_LSP_2D_Coordinate whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLSP2DCoordinate
(
    const SRM_LSP_2D_Coordinate *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LSR_2D_Parameters.
     @param value_ptr -- pointer to SRM_LSR_2D_Parameters whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLSR2DParameters
(
    const SRM_LSR_2D_Parameters *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LSR_3D_Parameters.
     @param value_ptr -- pointer to SRM_LSR_3D_Parameters whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLSR3DParameters
(
    const SRM_LSR_3D_Parameters *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LTSAS_3D_Coordinate.
     @param value_ptr -- pointer to SRM_LTSAS_3D_Coordinate whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLTSAS3DCoordinate
(
    const SRM_LTSAS_3D_Coordinate *value_ptr,
    const char                    *name_ptr,
          SRM_Integer_Unsigned     level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LTSAS_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_LTSAS_Surface_Coordinate whose
                  contents are to be printed; if NULL, prints error message
                  and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLTSASSurfaceCoordinate
(
    const SRM_LTSAS_Surface_Coordinate *value_ptr,
    const char                         *name_ptr,
          SRM_Integer_Unsigned          level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LTSC_3D_Coordinate.
     @param value_ptr -- pointer to SRM_LTSC_3D_Coordinate whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLTSC3DCoordinate
(
    const SRM_LTSC_3D_Coordinate *value_ptr,
    const char                   *name_ptr,
          SRM_Integer_Unsigned    level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LTSC_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_LTSC_Surface_Coordinate whose contents
                  are to be printed; if NULL, prints error message and returns
                  to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLTSCSurfaceCoordinate
(
    const SRM_LTSC_Surface_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LTSE_3D_Coordinate.
     @param value_ptr -- pointer to SRM_LTSE_3D_Coordinate whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLTSE3DCoordinate
(
    const SRM_LTSE_3D_Coordinate *value_ptr,
    const char                   *name_ptr,
          SRM_Integer_Unsigned    level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LTSE_Parameters.
     @param value_ptr -- pointer to SRM_LTSE_Parameters whose contents are to
                  be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLTSEParameters
(
    const SRM_LTSE_Parameters  *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_LTSE_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_LTSE_Surface_Coordinate whose contents
                  are to be printed; if NULL, prints error message and returns
                  to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintLTSESurfaceCoordinate
(
    const SRM_LTSE_Surface_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_M_Parameters.
     @param value_ptr -- pointer to SRM_M_Parameters whose contents are to be
                  printed; if NULL, prints error message and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintMParameters
(
    const SRM_M_Parameters     *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Map_Projection_3D_Coordinate.
     @param value_ptr -- pointer to SRM_Map_Projection_3D_Coordinate whose
                  contents are to be printed; if NULL, prints error message
                  and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintMapProjection3DCoordinate
(
    const SRM_Map_Projection_3D_Coordinate *value_ptr,
    const char                             *name_ptr,
          SRM_Integer_Unsigned              level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Map_Projection_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_Map_Projection_Surface_Coordinate
                  whose contents are to be printed; if NULL, prints error
                  message and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintMapProjectionSurfaceCoordinate
(
    const SRM_Map_Projection_Surface_Coordinate *value_ptr,
    const char                                  *name_ptr,
          SRM_Integer_Unsigned                   level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the information in the given SRM_Matrix_3x3 into a buffer that
     @param value -- SRM_Matrix_3x3 to be processed
 
     @return static buffer, containing an error message if value is invalid;
             otherwise, contains the string label equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/

EXPORT_DLL extern const char *
SRM_PrintMatrix3x3
(
    const SRM_Matrix_3x3 value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the information in the given SRM_Matrix_4x4 into a buffer that
     @param value -- SRM_Matrix_4x4 to be processed
 
     @return static buffer, containing an error message if value is invalid;
             otherwise, contains the string label equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/

EXPORT_DLL extern const char *
SRM_PrintMatrix4x4
(
    const SRM_Matrix_4x4 value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Oblique_Mercator_Parameters.
     @param value_ptr -- pointer to SRM_Oblique_Mercator_Parameters whose
                  contents are to be printed; if NULL, prints error message
                  and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintObliqueMercatorParameters
(
    const SRM_Oblique_Mercator_Parameters *value_ptr,
    const char                            *name_ptr,
          SRM_Integer_Unsigned             level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_ORM_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_ORM_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintORMCode
(
    SRM_ORM_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_ORM_Transformation_2D_Parameters.
     @param value_ptr -- pointer to SRM_ORM_Transformation_2D_Parameters whose
                  contents are to be printed; if NULL, prints error message
                  and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintORMTransformation2DParameters
(
    const SRM_ORM_Transformation_2D_Parameters *value_ptr,
    const char                                 *name_ptr,
          SRM_Integer_Unsigned                  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_ORM_Transformation_3D_Parameters.
     @param value_ptr -- pointer to SRM_ORM_Transformation_3D_Parameters whose
                  contents are to be printed; if NULL, prints error message
                  and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintORMTransformation3DParameters
(
    const SRM_ORM_Transformation_3D_Parameters *value_ptr,
    const char                                 *name_ptr,
          SRM_Integer_Unsigned                  level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_ORMT_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_ORMT_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintORMTCode
(
    SRM_ORMT_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_PD_3D_Coordinate.
     @param value_ptr -- pointer to SRM_PD_3D_Coordinate whose contents are to
                  be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintPD3DCoordinate
(
    const SRM_PD_3D_Coordinate *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_PD_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_PD_Surface_Coordinate whose contents
                  are to be printed; if NULL, prints error message and returns
                  to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintPDSurfaceCoordinate
(
    const SRM_PD_Surface_Coordinate *value_ptr,
    const char                      *name_ptr,
          SRM_Integer_Unsigned       level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_Polar_Aspect into a buffer that is suitable for
     printing.

     @param value -- SRM_Polar_Aspect to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintPolarAspect
(
    SRM_Polar_Aspect value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_PS_Parameters.
     @param value_ptr -- pointer to SRM_PS_Parameters whose contents are to be
                  printed; if NULL, prints error message and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintPSParameters
(
    const SRM_PS_Parameters    *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_RD_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_RD_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintRDCode
(
    SRM_RD_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_RT_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_RT_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintRTCode
(
    SRM_RT_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_Spatial_Coordinate_Code into a buffer that is
     suitable for printing.

     @param value -- SRM_Spatial_Coordinate_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSpatialCoordinateCode
(
    SRM_Spatial_Coordinate_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Spherical_3D_Coordinate.
     @param value_ptr -- pointer to SRM_Spherical_3D_Coordinate whose contents
                  are to be printed; if NULL, prints error message and returns
                  to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintSpherical3DCoordinate
(
    const SRM_Spherical_3D_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRF_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_SRF_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFCode
(
    SRM_SRF_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_SRF_Parameters_Info.
     @param value_ptr -- pointer to SRM_SRF_Parameters_Info whose contents are
                  to be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintSRFParametersInfo
(
    const SRM_SRF_Parameters_Info *value_ptr,
    const char                    *name_ptr,
          SRM_Integer_Unsigned     level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRF_Parameters_Info_Code into a buffer that is
     suitable for printing.

     @param value -- SRM_SRF_Parameters_Info_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFParametersInfoCode
(
    SRM_SRF_Parameters_Info_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_SRF_Reference_Surface_Info.
     @param value_ptr -- pointer to SRM_SRF_Reference_Surface_Info whose
                  contents are to be printed; if NULL, prints error message
                  and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintSRFReferenceSurfaceInfo
(
    const SRM_SRF_Reference_Surface_Info *value_ptr,
    const char                           *name_ptr,
          SRM_Integer_Unsigned            level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRFS_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_SRFS_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFSCode
(
    SRM_SRFS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_SRFS_Code_Info.
     @param value_ptr -- pointer to SRM_SRFS_Code_Info whose contents are to
                  be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintSRFSCodeInfo
(
    const SRM_SRFS_Code_Info   *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_SRFS_Info.
     @param value_ptr -- pointer to SRM_SRFS_Info whose contents are to be
                  printed; if NULL, prints error message and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintSRFSInfo
(
    const SRM_SRFS_Info        *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRFSM_Alabama_SPCS_Code into a buffer that is
     suitable for printing.

     @param value -- SRM_SRFSM_Alabama_SPCS_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFSMAlabamaSPCSCode
(
    SRM_SRFSM_Alabama_SPCS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the information in the given SRM_SRFSM_GTRS_GCS_Code into a
     @param value -- SRM_SRFSM_GTRS_GCS_Code to be processed
 
     @return static buffer, containing an error message if value is invalid;
             otherwise, contains the string label equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/

EXPORT_DLL extern const char *
SRM_PrintSRFSMGTRSGCSCode
(
    SRM_SRFSM_GTRS_GCS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRFSM_Japan_Rectangular_Plane_CS_Code into a
     buffer that is suitable for printing.

     @param value -- SRM_SRFSM_Japan_Rectangular_Plane_CS_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFSMJapanRectangularPlaneCSCode
(
    SRM_SRFSM_Japan_Rectangular_Plane_CS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRFSM_Lambert_NTF_Code into a buffer that is
     suitable for printing.

     @param value -- SRM_SRFSM_Lambert_NTF_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFSMLambertNTFCode
(
    SRM_SRFSM_Lambert_NTF_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRFSM_UPS_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_SRFSM_UPS_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFSMUPSCode
(
    SRM_SRFSM_UPS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRFSM_UTM_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_SRFSM_UTM_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFSMUTMCode
(
    SRM_SRFSM_UTM_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRFSM_Wisconsin_SPCS_Code into a buffer that is
     suitable for printing.

     @param value -- SRM_SRFSM_Wisconsin_SPCS_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFSMWisconsinSPCSCode
(
    SRM_SRFSM_Wisconsin_SPCS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_SRFT_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_SRFT_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintSRFTCode
(
    SRM_SRFT_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_SRFT_Parameters.
     @param value_ptr -- pointer to SRM_SRFT_Parameters whose contents are to
                  be printed; if NULL, prints error message and returns to
                  caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintSRFTParameters
(
    const SRM_SRFT_Parameters  *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the given SRM_Status_Code into a buffer that is suitable for
     printing.

     @param value -- SRM_Status_Code to be processed
  
     @return static buffer, containing error message if value is out of range;
             otherwise, buffer is set to the string name equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern const char *
SRM_PrintStatusCode
(
    SRM_Status_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_TM_Parameters.
     @param value_ptr -- pointer to SRM_TM_Parameters whose contents are to be
                  printed; if NULL, prints error message and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintTMParameters
(
    const SRM_TM_Parameters    *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Prints the information in the given SRM_Unused.
     @param value_ptr -- pointer to SRM_Unused whose contents are to be
                  printed; if NULL, prints error message and returns to caller

  
     @param name_ptr -- optional; name of value_ptr field at the
            caller's level
 
     @param level -- current indentation level. For each level, the output is
                     indented 4 spaces; e.g., level = 0 means no indentation;
                     level = 1 causes an indent of 4 spaces; level = 2 indents
                     8 spaces, level = 3 indents 12 spaces, etc.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern void
SRM_PrintUnused
(
    const SRM_Unused           *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
);


/* *-----------------------------------------------------------------------------*/
/** Translates the information in the given SRM_Vector_3D into a buffer that
     @param value -- SRM_Vector_3D to be processed
 
     @return static buffer, containing an error message if value is invalid;
             otherwise, contains the string label equivalent to value.
 
     @note Note that if you want to keep the results of this function, you must
           copy them out of the pointer that is returned, because the contents of
           the buffer will be overwritten the next time this function is called.
 */
/* *-----------------------------------------------------------------------------*/

EXPORT_DLL extern const char *
SRM_PrintVector3D
(
    const SRM_Vector_3D value
);
#ifdef __cplusplus
}
#endif

#endif /* #ifndef/define/endif for _SRM_PRINT_H_INCLUDED */
