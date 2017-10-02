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

/** @file   srm_util.h
    @author Automatically generated file
    @brief  Various useful functions.
 */

/*
 * For other release dates/detailed changes, contact SAIC.
 */

#ifndef _SRM_UTIL_H_INCLUDED
#define _SRM_UTIL_H_INCLUDED

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

#include "srm_types.h"

/*-----------------------------------------------------------------------------*/
/**   Compares the values in a_ptr and b_ptr and reports in result_out_ptr
           whether a_ptr's value equals b_ptr's value.

    @param a_ptr - 1st coordinate operand

    @param b_ptr - 2nd coordinate operand

    @param result_out_ptr - a SRM_Boolean variable in the user's
             memory space where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set to the appropriate
             result, if valid parameters were passed in.
    @return
           SRM_STATCOD_INVALID_SOURCE_COORDINATE - and no changes are made,
             if a_ptr or b_ptr is NULL.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if
             result_out_ptr is NULL.
    @return
           SRM_STATCOD_OPERATION_UNSUPPORTED - and result_out_ptr is set to
             SRM_FALSE, if a_ptr->spatial_coord_code does not equal
             b_ptr->spatial_coord_code.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_CoordinateEqual
(
    const SRM_Coordinate *a_ptr,
    const SRM_Coordinate *b_ptr,
          SRM_Boolean    *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Computes the cross product of two vectors.

    @param a_ptr - 1st vector operand

    @param b_ptr - 2nd vector operand

    @param result_out_ptr - a SRM_Vector_3D variable in the user's
             memory space where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set to the appropriate
             result, if valid parameters were passed in.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if
             result_out_ptr, a_ptr, or b_ptr is NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_CrossProduct
(
    const SRM_Vector_3D a_ptr,
    const SRM_Vector_3D b_ptr,
          SRM_Vector_3D result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Given a 3D coordinate, expressed in an SRF that has a corresponding 2D
           SRF, constructs the corresponding 2D representation (i.e., without the
           z/elevation portion of the 3D, in the proper 2D SRF).

    @param coord_3d_ptr - pointer to the 3D coordinate for which we are obtaining the
          corresponding 2D coordinate.

    @param coord_2d_ptr - pointer to the 2D coordinate that we are deriving.

    @return
           SRM_STATCOD_SUCCESS - and *coord_2d_ptr is set to the appropriate
             result, if valid parameters were passed in.
    @return
           SRM_STATCOD_INVALID_TARGET_COORDINATE - and *coord_2d_ptr is
             left unchanged, if coord_2d_ptr is NULL.
    @return
           SRM_STATCOD_INVALID_SOURCE_COORDINATE - and *coord_2d_ptr is
             left unchanged, if coord_3d_ptr is NULL, or is expressed in a
             3D SRF that has no corresponding 2D SRF.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_DeriveCoordinate2DFrom3D
(
    const SRM_Coordinate *coord_3d_ptr,
          SRM_Coordinate *coord_2d_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Computes the dot product of 2 vectors.

    @param a_ptr - 1st vector operand

    @param b_ptr - 2nd vector operand

    @param result_out_ptr - pointer to an SRM_Long_Float variable in the user's
             memory space where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set to the appropriate
             result, if valid parameters were passed in.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if
             result_out_ptr, a_ptr, or b_ptr is NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_DotProduct
(
    const SRM_Vector_3D   a_ptr,
    const SRM_Vector_3D   b_ptr,
          SRM_Long_Float *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   This function returns the version of the implementation of the
           SRM used to define the given transmittal.
     
           Major versions are specified by an integer that is incremented
           whenever large changes are made to the implementation.
     
           Minor versions are specified by an integer that is incremented
           whenever any small changes are made to the implementation.
     
           Interim versions are specified using a lower case letter that
           is incremented whenever a new interim version of the
           implementation is released.

    @param major_SRM_version - a pointer to a SRM_Integer_Positive in the
             user's memory space that will be set to an integer value
             greater than or equal to 1

    @param minor_SRM_version - a pointer to a SRM_Integer_Unsigned in the
             user's memory space that will be set to an integer value
             between 0 and 99, inclusive

    @param interim_SRM_version - a pointer to a char in the user's memory
             space that will be set to a value between 'a' and 'z' inclusive.
             If it was not an interim version of the SRM, then the value will
             be set to '\0'.

    @return
           SRM_STATCOD_SUCCESS - and the output parameters are set, if
             valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and the output parameters are left
             unchanged, if major_SRM_version, minor_SRM_version, or
             interim_SRM_version was NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_GetVersionInformation
(
    SRM_Integer_Positive *major_SRM_version,
    SRM_Integer_Unsigned *minor_SRM_version,
    char                 *interim_SRM_version
);


/*-----------------------------------------------------------------------------*/
/**   Adds two SRM_Matrix_3x3 matrices.

    @param a_ptr - pointer to 1st operand

    @param b_ptr - pointer to 2nd operand

    @param result_out_ptr - pointer to result.

    @return
           SRM_STATCOD_SUCCESS - if valid parameters were passed in and all
             operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and *result_out_ptr is left
             unchanged, if result_out_ptr, a_ptr, or b_ptr was NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_Matrix3x3Add
(
    const SRM_Matrix_3x3 a_ptr,
    const SRM_Matrix_3x3 b_ptr,
          SRM_Matrix_3x3 result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**  Multiplies two SRM_Matrix_3x3 matrices.

    @param a_ptr - pointer to 1st operand

    @param b_ptr - pointer to 2nd operand

    @param result_out_ptr - pointer to result.

    @return
           SRM_STATCOD_SUCCESS - if valid parameters were passed in and all
             operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and *result_out_ptr is left
             unchanged, if result_out_ptr, a_ptr, or b_ptr was NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_Matrix3x3Multiply
(
    const SRM_Matrix_3x3 a_ptr,
    const SRM_Matrix_3x3 b_ptr,
          SRM_Matrix_3x3 result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Subtracts the matrix in *b_ptr from the matrix in *a_ptr.

    @param a_ptr - pointer to 1st operand

    @param b_ptr - pointer to 2nd operand

    @param result_out_ptr - pointer to result.

    @return
           SRM_STATCOD_SUCCESS - if valid parameters were passed in and all
             operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and *result_out_ptr is left
             unchanged, if result_out_ptr, a_ptr, or b_ptr was NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_Matrix3x3Sub
(
    const SRM_Matrix_3x3 a_ptr,
    const SRM_Matrix_3x3 b_ptr,
          SRM_Matrix_3x3 result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Adds two SRM_Matrix_4x4 matrices.

    @param a_ptr - pointer to 1st operand

    @param b_ptr - pointer to 2nd operand

    @param result_out_ptr - pointer to result.

    @return
           SRM_STATCOD_SUCCESS - if valid parameters were passed in and all
             operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and *result_out_ptr is left
             unchanged, if result_out_ptr, a_ptr, or b_ptr was NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_Matrix4x4Add
(
    const SRM_Matrix_4x4 a_ptr,
    const SRM_Matrix_4x4 b_ptr,
          SRM_Matrix_4x4 result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Multiplies two SRM_Matrix_4x4 matrices.

    @param a_ptr - pointer to 1st operand

    @param b_ptr - pointer to 2nd operand

    @param result_out_ptr - pointer to result.

    @return
           SRM_STATCOD_SUCCESS - if valid parameters were passed in and all
             operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and *result_out_ptr is left
             unchanged, if result_out_ptr, a_ptr, or b_ptr was NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_Matrix4x4Multiply
(
    const SRM_Matrix_4x4 a_ptr,
    const SRM_Matrix_4x4 b_ptr,
          SRM_Matrix_4x4 result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Subtracts the matrix in *b_ptr from the matrix in *a_ptr.

    @param a_ptr - pointer to 1st operand

    @param b_ptr - pointer to 2nd operand

    @param result_out_ptr - pointer to result.

    @return
           SRM_STATCOD_SUCCESS - if valid parameters were passed in and all
             operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and *result_out_ptr is left
             unchanged, if result_out_ptr, a_ptr, or b_ptr was NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_Matrix4x4Sub
(
    const SRM_Matrix_4x4 a_ptr,
    const SRM_Matrix_4x4 b_ptr,
          SRM_Matrix_4x4 result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Computes the magnitude of a vector.

    @param vec_ptr - pointer to the vector operand

    @param result_out_ptr - pointer to an SRM_Long_Float variable in the user's
             memory space where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set to the appropriate
             value, if valid parameters were passed in.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if
             result_out_ptr or vec_ptr is NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_VectorMagnitude
(
    const SRM_Vector_3D   vec_ptr,
          SRM_Long_Float *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**    Multiplies vec_ptr's vector by scalar, returns the result in
            *result_out_ptr.

    @param vec_ptr - pointer to the vector operand

    @param scalar - the scalar multiplier.

    @param result_out_ptr - pointer to an SRM_Vector_3D variable in the user's
             memory space where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set to the appropriate
             value, if valid parameters were passed in.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if
             result_out_ptr or vec_ptr is NULL.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_VectorMultByScalar
(
    const SRM_Vector_3D  vec_ptr,
          SRM_Long_Float scalar,
          SRM_Vector_3D  result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_Axis_Direction corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToAxisDirection
(
    const char               *enum_name_in_ptr,
          SRM_Axis_Direction *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_Boolean corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToBoolean
(
    const char        *enum_name_in_ptr,
          SRM_Boolean *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_Coordinate_Valid_Region corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToCoordinateValidRegion
(
    const char                        *enum_name_in_ptr,
          SRM_Coordinate_Valid_Region *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_CS_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToCSCode
(
    const char        *enum_name_in_ptr,
          SRM_CS_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_DSS_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToDSSCode
(
    const char         *enum_name_in_ptr,
          SRM_DSS_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_Interval_Type corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToIntervalType
(
    const char              *enum_name_in_ptr,
          SRM_Interval_Type *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_ORM_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToORMCode
(
    const char         *enum_name_in_ptr,
          SRM_ORM_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_ORMT_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToORMTCode
(
    const char          *enum_name_in_ptr,
          SRM_ORMT_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_Polar_Aspect corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToPolarAspect
(
    const char             *enum_name_in_ptr,
          SRM_Polar_Aspect *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_RD_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToRDCode
(
    const char        *enum_name_in_ptr,
          SRM_RD_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_RT_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToRTCode
(
    const char        *enum_name_in_ptr,
          SRM_RT_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_Spatial_Coordinate_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSpatialCoordinateCode
(
    const char                        *enum_name_in_ptr,
          SRM_Spatial_Coordinate_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRF_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFCode
(
    const char         *enum_name_in_ptr,
          SRM_SRF_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRF_Parameters_Info_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFParametersInfoCode
(
    const char                         *enum_name_in_ptr,
          SRM_SRF_Parameters_Info_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRFS_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFSCode
(
    const char          *enum_name_in_ptr,
          SRM_SRFS_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRFSM_Alabama_SPCS_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFSMAlabamaSPCSCode
(
    const char                        *enum_name_in_ptr,
          SRM_SRFSM_Alabama_SPCS_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRFSM_Japan_Rectangular_Plane_CS_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFSMJapanRectangularPlaneCSCode
(
    const char                                      *enum_name_in_ptr,
          SRM_SRFSM_Japan_Rectangular_Plane_CS_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRFSM_Lambert_NTF_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFSMLambertNTFCode
(
    const char                       *enum_name_in_ptr,
          SRM_SRFSM_Lambert_NTF_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRFSM_UPS_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFSMUPSCode
(
    const char               *enum_name_in_ptr,
          SRM_SRFSM_UPS_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRFSM_UTM_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFSMUTMCode
(
    const char               *enum_name_in_ptr,
          SRM_SRFSM_UTM_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRFSM_Wisconsin_SPCS_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFSMWisconsinSPCSCode
(
    const char                          *enum_name_in_ptr,
          SRM_SRFSM_Wisconsin_SPCS_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_SRFT_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToSRFTCode
(
    const char          *enum_name_in_ptr,
          SRM_SRFT_Code *result_out_ptr
);


/*-----------------------------------------------------------------------------*/
/**   Retrieves the SRM_Status_Code corresponding to the given string.

    @param enum_name_in_ptr - enumerant name to be processed

    @param result_out_ptr - pointer to a variable in the user's memory space
            where the result will be stored.

    @return
           SRM_STATCOD_SUCCESS - and *result_out_ptr is set appropriately,
             if valid parameters were passed in and all operations succeeded.
    @return
           SRM_STATCOD_INACTIONABLE - and no changes are made, if any parameter was
             NULL or invalid.
 */
/*-----------------------------------------------------------------------------*/
EXPORT_DLL extern SRM_Status_Code
SRM_EnumNameToStatusCode
(
    const char            *enum_name_in_ptr,
          SRM_Status_Code *result_out_ptr
);


#ifdef __cplusplus
}
#endif

#endif
