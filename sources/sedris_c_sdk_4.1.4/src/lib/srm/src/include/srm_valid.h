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

/** @file   srm_valid.h
    @author Automatically generated file
    @brief  This file defines the prototypes for the functions that validate the
            data structures used by the SRM API; it is included by srm.h

    @note   This file is for internal use only. Users must not include this
            file, but instead include srm.h.
 */

/*
 * For other release dates/detailed changes, contact SAIC.
 */

/*
 * Ensure that srm_print.h is included only once.
 */
#ifndef _SRM_VALID_H_INCLUDED
#define _SRM_VALID_H_INCLUDED

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

#include <stdio.h> /* needed for FILE */
#include "srm_types.h"


/*-----------------------------------------------------------------------------*/
/** Returns the FILE pointer to which error messages are directed.
    @return FILE pointer to stream to which error messages are to be output.
 */
/*-----------------------------------------------------------------------------*/

EXPORT_DLL extern FILE *
SRM_GetErrorFilePtr(void);


/*-----------------------------------------------------------------------------*/
/** Sets the FILE pointer to which error messages are directed,
    if error messages are requested.

    @warning If you close this file after calling this function,
             remember that the SRM functions will still try to use it.

    @param   err_file_ptr -- stream to which error messages are to be output

    @return  SRM_STATCOD_INACTIONABLE - and nothing is changed, if err_file_ptr is
             NULL.
    @return  SRM_STATCOD_SUCCESS - otherwise.
 */
/*-----------------------------------------------------------------------------*/

EXPORT_DLL extern SRM_Status_Code
SRM_SetErrorFilePtr
(
    FILE *err_file_ptr
);




/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_Axis_Direction.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidAxisDirection
(
    SRM_Axis_Direction value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_Boolean.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidBoolean
(
    SRM_Boolean value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_CD_3D_Coordinate.
     @param value_ptr -- pointer to SRM_CD_3D_Coordinate whose contents are to
                  be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_CD_3D_Coordinate is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidCD3DCoordinate
(
    const SRM_CD_3D_Coordinate *value_ptr,
          SRM_Boolean           print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_CD_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_CD_Surface_Coordinate whose contents
                  are to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_CD_Surface_Coordinate is stored;
       if NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidCDSurfaceCoordinate
(
    const SRM_CD_Surface_Coordinate *value_ptr,
          SRM_Boolean                print_error,
          SRM_Integer_Unsigned      *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_Coordinate.
     @param value_ptr -- pointer to SRM_Coordinate whose contents are to be
                  checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_Coordinate is stored; if NULL, no
       counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidCoordinate
(
    const SRM_Coordinate *value_ptr,
          SRM_Boolean     print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_Coordinate_Valid_Region.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidCoordinateValidRegion
(
    SRM_Coordinate_Valid_Region value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_Coordinate_Valid_Region_Array.
     @param value_ptr -- pointer to SRM_Coordinate_Valid_Region_Array whose
                  contents are to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_Coordinate_Valid_Region_Array is
       stored; if NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidCoordinateValidRegionArray
(
    const SRM_Coordinate_Valid_Region_Array *value_ptr,
          SRM_Boolean                        print_error,
          SRM_Integer_Unsigned              *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_Coordinate2D_Array.
     @param value_ptr -- pointer to SRM_Coordinate2D_Array whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_Coordinate2D_Array is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidCoordinate2DArray
(
    const SRM_Coordinate2D_Array *value_ptr,
          SRM_Boolean             print_error,
          SRM_Integer_Unsigned   *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_Coordinate3D_Array.
     @param value_ptr -- pointer to SRM_Coordinate3D_Array whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_Coordinate3D_Array is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidCoordinate3DArray
(
    const SRM_Coordinate3D_Array *value_ptr,
          SRM_Boolean             print_error,
          SRM_Integer_Unsigned   *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_CS_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidCSCode
(
    SRM_CS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_Direction_Array.
     @param value_ptr -- pointer to SRM_Direction_Array whose contents are to
                  be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_Direction_Array is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidDirectionArray
(
    const SRM_Direction_Array *value_ptr,
          SRM_Boolean          print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_DSS_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidDSSCode
(
    SRM_DSS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_EC_Parameters.
     @param value_ptr -- pointer to SRM_EC_Parameters whose contents are to be
                  checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_EC_Parameters is stored; if NULL,
       no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidECParameters
(
    const SRM_EC_Parameters *value_ptr,
          SRM_Boolean        print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_EI_3D_Coordinate.
     @param value_ptr -- pointer to SRM_EI_3D_Coordinate whose contents are to
                  be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_EI_3D_Coordinate is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidEI3DCoordinate
(
    const SRM_EI_3D_Coordinate *value_ptr,
          SRM_Boolean           print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks that the given SRM_Integer_Positive contains a valid value.
    @param value -- SRM_Integer_Positive whose contents are to be processed
    @return SRM_TRUE - if value is valid

     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidIntegerPositive
(
    SRM_Integer_Positive value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_Interval_Type.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidIntervalType
(
    SRM_Interval_Type value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_Local_Tangent_Parameters.
     @param value_ptr -- pointer to SRM_Local_Tangent_Parameters whose
                  contents are to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_Local_Tangent_Parameters is
       stored; if NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLocalTangentParameters
(
    const SRM_Local_Tangent_Parameters *value_ptr,
          SRM_Boolean                   print_error,
          SRM_Integer_Unsigned         *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_LSA_2D_Coordinate.
     @param value_ptr -- pointer to SRM_LSA_2D_Coordinate whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_LSA_2D_Coordinate is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLSA2DCoordinate
(
    const SRM_LSA_2D_Coordinate *value_ptr,
          SRM_Boolean            print_error,
          SRM_Integer_Unsigned  *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_LSP_2D_Coordinate.
     @param value_ptr -- pointer to SRM_LSP_2D_Coordinate whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_LSP_2D_Coordinate is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLSP2DCoordinate
(
    const SRM_LSP_2D_Coordinate *value_ptr,
          SRM_Boolean            print_error,
          SRM_Integer_Unsigned  *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_LSR_2D_Parameters.
     @param value_ptr -- pointer to SRM_LSR_2D_Parameters whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_LSR_2D_Parameters is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLSR2DParameters
(
    const SRM_LSR_2D_Parameters *value_ptr,
          SRM_Boolean            print_error,
          SRM_Integer_Unsigned  *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_LSR_3D_Parameters.
     @param value_ptr -- pointer to SRM_LSR_3D_Parameters whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_LSR_3D_Parameters is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLSR3DParameters
(
    const SRM_LSR_3D_Parameters *value_ptr,
          SRM_Boolean            print_error,
          SRM_Integer_Unsigned  *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_LTSAS_3D_Coordinate.
     @param value_ptr -- pointer to SRM_LTSAS_3D_Coordinate whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_LTSAS_3D_Coordinate is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLTSAS3DCoordinate
(
    const SRM_LTSAS_3D_Coordinate *value_ptr,
          SRM_Boolean              print_error,
          SRM_Integer_Unsigned    *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_LTSC_3D_Coordinate.
     @param value_ptr -- pointer to SRM_LTSC_3D_Coordinate whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_LTSC_3D_Coordinate is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLTSC3DCoordinate
(
    const SRM_LTSC_3D_Coordinate *value_ptr,
          SRM_Boolean             print_error,
          SRM_Integer_Unsigned   *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_LTSC_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_LTSC_Surface_Coordinate whose contents
                  are to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_LTSC_Surface_Coordinate is stored;
       if NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLTSCSurfaceCoordinate
(
    const SRM_LTSC_Surface_Coordinate *value_ptr,
          SRM_Boolean                  print_error,
          SRM_Integer_Unsigned        *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_LTSE_Parameters.
     @param value_ptr -- pointer to SRM_LTSE_Parameters whose contents are to
                  be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_LTSE_Parameters is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidLTSEParameters
(
    const SRM_LTSE_Parameters *value_ptr,
          SRM_Boolean          print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_M_Parameters.
     @param value_ptr -- pointer to SRM_M_Parameters whose contents are to be
                  checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_M_Parameters is stored; if NULL,
       no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidMParameters
(
    const SRM_M_Parameters *value_ptr,
          SRM_Boolean       print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_Oblique_Mercator_Parameters.
     @param value_ptr -- pointer to SRM_Oblique_Mercator_Parameters whose
                  contents are to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_Oblique_Mercator_Parameters is
       stored; if NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidObliqueMercatorParameters
(
    const SRM_Oblique_Mercator_Parameters *value_ptr,
          SRM_Boolean                      print_error,
          SRM_Integer_Unsigned            *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_ORM_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidORMCode
(
    SRM_ORM_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_ORMT_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidORMTCode
(
    SRM_ORMT_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_PD_3D_Coordinate.
     @param value_ptr -- pointer to SRM_PD_3D_Coordinate whose contents are to
                  be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_PD_3D_Coordinate is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidPD3DCoordinate
(
    const SRM_PD_3D_Coordinate *value_ptr,
          SRM_Boolean           print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_PD_Surface_Coordinate.
     @param value_ptr -- pointer to SRM_PD_Surface_Coordinate whose contents
                  are to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_PD_Surface_Coordinate is stored;
       if NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidPDSurfaceCoordinate
(
    const SRM_PD_Surface_Coordinate *value_ptr,
          SRM_Boolean                print_error,
          SRM_Integer_Unsigned      *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_Polar_Aspect.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidPolarAspect
(
    SRM_Polar_Aspect value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_PS_Parameters.
     @param value_ptr -- pointer to SRM_PS_Parameters whose contents are to be
                  checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_PS_Parameters is stored; if NULL,
       no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidPSParameters
(
    const SRM_PS_Parameters *value_ptr,
          SRM_Boolean        print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_RD_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidRDCode
(
    SRM_RD_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_RT_Code.
     @param orm_code -- SRM_ORM_Code for rt_code to be checked

     @param rt_code -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidRTCode
(
    SRM_ORM_Code orm_code,
    SRM_RT_Code  rt_code
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_Spatial_Coordinate_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSpatialCoordinateCode
(
    SRM_Spatial_Coordinate_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_Spherical_3D_Coordinate.
     @param value_ptr -- pointer to SRM_Spherical_3D_Coordinate whose contents
                  are to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_Spherical_3D_Coordinate is stored;
       if NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSpherical3DCoordinate
(
    const SRM_Spherical_3D_Coordinate *value_ptr,
          SRM_Boolean                  print_error,
          SRM_Integer_Unsigned        *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRF_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFCode
(
    SRM_SRF_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_SRF_Parameters_Info.
     @param value_ptr -- pointer to SRM_SRF_Parameters_Info whose contents are
                  to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_SRF_Parameters_Info is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFParametersInfo
(
    const SRM_SRF_Parameters_Info *value_ptr,
          SRM_Boolean              print_error,
          SRM_Integer_Unsigned    *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRF_Parameters_Info_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFParametersInfoCode
(
    SRM_SRF_Parameters_Info_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_SRF_Reference_Surface_Info.
     @param value_ptr -- pointer to SRM_SRF_Reference_Surface_Info whose
                  contents are to be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_SRF_Reference_Surface_Info is
       stored; if NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFReferenceSurfaceInfo
(
    const SRM_SRF_Reference_Surface_Info *value_ptr,
          SRM_Boolean                     print_error,
          SRM_Integer_Unsigned           *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRFS_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSCode
(
    SRM_SRFS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_SRFS_Code_Info.
     @param value_ptr -- pointer to SRM_SRFS_Code_Info whose contents are to
                  be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_SRFS_Code_Info is stored; if NULL,
       no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSCodeInfo
(
    const SRM_SRFS_Code_Info *value_ptr,
          SRM_Boolean         print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_SRFS_Info.
     @param value_ptr -- pointer to SRM_SRFS_Info whose contents are to be
                  checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_SRFS_Info is stored; if NULL, no
       counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSInfo
(
    const SRM_SRFS_Info *value_ptr,
          SRM_Boolean    print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRFSM_Alabama_SPCS_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSMAlabamaSPCSCode
(
    SRM_SRFSM_Alabama_SPCS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid
   SRM_SRFSM_Japan_Rectangular_Plane_CS_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSMJapanRectangularPlaneCSCode
(
    SRM_SRFSM_Japan_Rectangular_Plane_CS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRFSM_Lambert_NTF_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSMLambertNTFCode
(
    SRM_SRFSM_Lambert_NTF_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRFSM_UPS_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSMUPSCode
(
    SRM_SRFSM_UPS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRFSM_UTM_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSMUTMCode
(
    SRM_SRFSM_UTM_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRFSM_Wisconsin_SPCS_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFSMWisconsinSPCSCode
(
    SRM_SRFSM_Wisconsin_SPCS_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_SRFT_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFTCode
(
    SRM_SRFT_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_SRFT_Parameters.
     @param value_ptr -- pointer to SRM_SRFT_Parameters whose contents are to
                  be checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_SRFT_Parameters is stored; if
       NULL, no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidSRFTParameters
(
    const SRM_SRFT_Parameters *value_ptr,
          SRM_Boolean          print_error,
          SRM_Integer_Unsigned *error_count_ptr
);


/* *-----------------------------------------------------------------------------*/
/** Checks if the given value is a valid SRM_Status_Code.
     @param value -- value to be checked

     @return SRM_TRUE - if value is valid
 
     @return SRM_FALSE - otherwise
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidStatusCode
(
    SRM_Status_Code value
);


/* *-----------------------------------------------------------------------------*/
/** Checks the information in the given SRM_TM_Parameters.
     @param value_ptr -- pointer to SRM_TM_Parameters whose contents are to be
                  checked.

     @param print_error -- whether to print error messages.

     @param error_count_ptr -- pointer to a variable in which the error count
                               for this SRM_TM_Parameters is stored; if NULL,
       no counting is performed.
     @return SRM_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
                       information.

     @return SRM_FALSE - otherwise.
 */
/* *-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Boolean
SRM_ValidTMParameters
(
    const SRM_TM_Parameters *value_ptr,
          SRM_Boolean        print_error,
          SRM_Integer_Unsigned *error_count_ptr
);
#ifdef __cplusplus
}
#endif
#endif
