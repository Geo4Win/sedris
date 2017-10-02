/*
 * SRM API
 *
 * FILE       : srm_valid.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Provides reusable functions for validating variables defined
 *   for various types defined in the SRM API.
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
 * - SRM spec. 4.1
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

#include <stdio.h> /* needed for FILE */
#include <math.h>  /* needed for PC */
#include "srm.h"

/*
 * GLOBAL CONSTANT: CLOSE_DELTA
 *
 *   Margin of error for float comparisons.
 */
static const SRM_Long_Float CLOSE_DELTA = 0.0005;

/*
 * GLOBAL VARIABLE: _ErrHasBeenSet
 *
 *   Whether error file pointer has been set by the user. If
 *   SRM_FALSE, use stderr.
 */
static SRM_Boolean _ErrHasBeenSet = SRM_FALSE;

/*
 * GLOBAL VARIABLE: srm_err_file_ptr
 *
 *   The error file pointer. If this has not been set, use
 *   stderr.
 */
static FILE *srm_err_file_ptr;


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_GetErrorFilePtr
 *
 *-----------------------------------------------------------------------------
 */
FILE *
SRM_GetErrorFilePtr(void)
{
    if (_ErrHasBeenSet)
        return srm_err_file_ptr;
    else
        return stderr;
} /* end SRM_GetErrorFilePtr */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_SetErrorFilePtr
 *
 *-----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_SetErrorFilePtr
(
    FILE *err_file_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (err_file_ptr)
    {
        srm_err_file_ptr = err_file_ptr;
        _ErrHasBeenSet   = SRM_TRUE;
        status = SRM_STATCOD_SUCCESS;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
        srm_err_file_ptr = stderr;
    }
    return status;
} /* end SRM_SetErrorFilePtr */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_GetORMCodeForSRFCode
 *
 *-----------------------------------------------------------------------------
 */
static SRM_ORM_Code
SRM_GetORMCodeForSRFCode
(
    SRM_SRF_Code srf_instance
)
{
    SRM_ORM_Code orm_code = SRM_ORMCOD_UNSPECIFIED;

    switch (srf_instance)
    {
        case SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY:
             orm_code = SRM_ORMCOD_OSGB_1936;
             break;

        case SRM_SRFCOD_BRITISH_OSGRS80_GRID:
             orm_code = SRM_ORMCOD_ETRS_1989;
             break;

        case SRM_SRFCOD_DELAWARE_SPCS_1983:
             orm_code = SRM_ORMCOD_N_AM_1983;
             break;

        case SRM_SRFCOD_GEOCENTRIC_WGS_1984:
             orm_code = SRM_ORMCOD_WGS_1984;
             break;

        case SRM_SRFCOD_GEODETIC_AUSTRALIA_1984:
             orm_code = SRM_ORMCOD_AUSTRALIAN_GEOD_1984;
             break;

        case SRM_SRFCOD_GEODETIC_WGS_1984:
             orm_code = SRM_ORMCOD_WGS_1984;
             break;

        case SRM_SRFCOD_GEODETIC_N_AMERICAN_1983:
             orm_code = SRM_ORMCOD_N_AM_1983;
             break;

        case SRM_SRFCOD_IRISH_GRID_1965:
             orm_code = SRM_ORMCOD_IRELAND_1965;
             break;

        case SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989:
             orm_code = SRM_ORMCOD_ETRS_1989;
             break;

        case SRM_SRFCOD_LAMBERT_93:
             orm_code = SRM_ORMCOD_RGF_1993;
             break;

        case SRM_SRFCOD_LAMBERT_II_WIDE:
             orm_code = SRM_ORMCOD_NTF_1896_PM_PARIS;
             break;

        case SRM_SRFCOD_MARS_PLANETOCENTRIC_2000:
             orm_code = SRM_ORMCOD_MARS_SPHERE_2000;
             break;

        case SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000:
             orm_code = SRM_ORMCOD_MARS_2000;
             break;

        case SRM_SRFCOD_MARYLAND_SPCS_1983:
             orm_code = SRM_ORMCOD_N_AM_1983;
             break;

        default:
             orm_code = SRM_ORMCOD_UNSPECIFIED;
             break;
    } /* end switch */
    return orm_code;
} /* end SRM_GetORMCodeForSRFCode */




/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidAxisDirection */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidAxisDirection
(
    SRM_Axis_Direction value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_AXDIR_POSITIVE_PRIMARY_AXIS:
        case SRM_AXDIR_POSITIVE_SECONDARY_AXIS:
        case SRM_AXDIR_POSITIVE_TERTIARY_AXIS:
        case SRM_AXDIR_NEGATIVE_PRIMARY_AXIS:
        case SRM_AXDIR_NEGATIVE_SECONDARY_AXIS:
        case SRM_AXDIR_NEGATIVE_TERTIARY_AXIS:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidAxisDirection */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidBoolean */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidBoolean
(
    SRM_Boolean value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_FALSE:
        case SRM_TRUE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidBoolean */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidCD3DCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidCD3DCoordinate
(
    const SRM_CD_3D_Coordinate *value_ptr,
          SRM_Boolean           print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidCD3DCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->longitude < -180.0-CLOSE_DELTA) || (value_ptr->longitude > 180.0+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidCD3DCoordinate: longitude"\
                    " out of range [-180.0, 180.0]!\n");
    }
    if ((value_ptr->latitude < -90.0-CLOSE_DELTA) || (value_ptr->latitude > 90.0+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidCD3DCoordinate: latitude"\
                    " out of range [-90.0, 90.0]!\n");
    }
    return result;
} /* end SRM_ValidCD3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidCDSurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidCDSurfaceCoordinate
(
    const SRM_CD_Surface_Coordinate *value_ptr,
          SRM_Boolean                print_error,
          SRM_Integer_Unsigned      *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidCDSurfaceCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->longitude < -180.0-CLOSE_DELTA) || (value_ptr->longitude > 180.0+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidCDSurfaceCoordinate: longitude"\
                    " out of range [-180.0, 180.0]!\n");
    }
    if ((value_ptr->latitude < -90.0-CLOSE_DELTA) || (value_ptr->latitude > 90.0+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidCDSurfaceCoordinate: latitude"\
                    " out of range [-90.0, 90.0]!\n");
    }
    return result;
} /* end SRM_ValidCDSurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidCoordinate
(
    const SRM_Coordinate *value_ptr,
          SRM_Boolean     print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->spatial_coord_code)
    {
        case SRM_SPACOORDCOD_CC_3D:
            break;

        case SRM_SPACOORDCOD_CD_3D:
            if (!SRM_ValidCD3DCoordinate(&(value_ptr->coordinate.cd_3d),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_CD_3D_Coordinate value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_CD_SURFACE:
            if (!SRM_ValidCDSurfaceCoordinate(
                      &(value_ptr->coordinate.cd_surface), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_CD_Surface_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_CM_3D:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(value_ptr->coordinate.cm_3d), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Spherical_3D_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
            break;

        case SRM_SPACOORDCOD_EC_SURFACE:
            break;

        case SRM_SPACOORDCOD_EI_3D:
            if (!SRM_ValidEI3DCoordinate(&(value_ptr->coordinate.ei_3d),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_EI_3D_Coordinate value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_HAEC_3D:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(value_ptr->coordinate.haec_3d), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Spherical_3D_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_HEEC_3D:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(value_ptr->coordinate.heec_3d), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Spherical_3D_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_HEEQ_3D:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(value_ptr->coordinate.heeq_3d), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Spherical_3D_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
            break;

        case SRM_SPACOORDCOD_LCC_SURFACE:
            break;

        case SRM_SPACOORDCOD_LSA_2D:
            break;

        case SRM_SPACOORDCOD_LSP_2D:
            if (!SRM_ValidLSA2DCoordinate(&(value_ptr->coordinate.lsa_2d),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_LSA_2D_Coordinate value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_LSR_2D:
            if (!SRM_ValidLSP2DCoordinate(&(value_ptr->coordinate.lsp_2d),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_LSP_2D_Coordinate value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_LSR_3D:
            break;

        case SRM_SPACOORDCOD_LCE_3D:
            break;

        case SRM_SPACOORDCOD_LTSAS_3D:
            if (!SRM_ValidLTSAS3DCoordinate(&(value_ptr->coordinate.ltsas_3d),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_LTSAS_3D_Coordinate value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_LTSAS_SURFACE:
            break;

        case SRM_SPACOORDCOD_LTSC_3D:
            if (!SRM_ValidLTSC3DCoordinate(&(value_ptr->coordinate.ltsc_3d),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_LTSC_3D_Coordinate value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_LTSC_SURFACE:
            if (!SRM_ValidLTSCSurfaceCoordinate(
                      &(value_ptr->coordinate.ltsc_surface), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_LTSC_Surface_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_LTSE_3D:
            break;

        case SRM_SPACOORDCOD_LTSE_SURFACE:
            break;

        case SRM_SPACOORDCOD_M_AUGMENTED_3D:
            break;

        case SRM_SPACOORDCOD_M_SURFACE:
            break;

        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
            break;

        case SRM_SPACOORDCOD_OMS_SURFACE:
            break;

        case SRM_SPACOORDCOD_PD_3D:
            if (!SRM_ValidPD3DCoordinate(&(value_ptr->coordinate.pd_3d),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_PD_3D_Coordinate value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_PD_SURFACE:
            if (!SRM_ValidPDSurfaceCoordinate(
                      &(value_ptr->coordinate.pd_surface), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_PD_Surface_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
            break;

        case SRM_SPACOORDCOD_PS_SURFACE:
            break;

        case SRM_SPACOORDCOD_SEC_3D:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(value_ptr->coordinate.sec_3d), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Spherical_3D_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_SEQ_3D:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(value_ptr->coordinate.seq_3d), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Spherical_3D_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_SMD_3D:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(value_ptr->coordinate.smd_3d), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Spherical_3D_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_SME_3D:
            if (!SRM_ValidSpherical3DCoordinate(
                      &(value_ptr->coordinate.sme_3d), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Spherical_3D_Coordinate"\
                           " value\n");
                }
            }
            break;

        case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
            break;

        case SRM_SPACOORDCOD_TM_SURFACE:
            break;

        default:
             result = SRM_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SRM_Spatial_Coordinate_Code value"\
                         " (%d)\n", (int) value_ptr->spatial_coord_code);
             break;
    } /* end switch */
    return result;
} /* end SRM_ValidCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidCoordinateValidRegion */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidCoordinateValidRegion
(
    SRM_Coordinate_Valid_Region value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_COORDVALRGN_VALID:
        case SRM_COORDVALRGN_EXTENDED_VALID:
        case SRM_COORDVALRGN_DEFINED:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidCoordinateValidRegion */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidCoordinateValidRegionArray */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidCoordinateValidRegionArray
(
    const SRM_Coordinate_Valid_Region_Array *value_ptr,
          SRM_Boolean                        print_error,
          SRM_Integer_Unsigned              *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidCoordinateValidRegionArray: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->valid_region_array && (value_ptr->length>0))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->valid_region_array for"\
                   " value_ptr->length == %u\n",(unsigned int)
                    value_ptr->length);
        }
    }
    else
    {
        SRM_Integer_Unsigned i;

        for (i = 0; i < (SRM_Integer_Unsigned)value_ptr->length; i++)
        {
            if (!SRM_ValidCoordinateValidRegion(value_ptr->valid_region_array[i]))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Invalid enumerant %d found, expected SRM_Coordinate_Valid_Region\n", (int)value_ptr->valid_region_array[i]);
            }
        } /* end for i */
    }
    return result;
} /* end SRM_ValidCoordinateValidRegionArray */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidCoordinate2DArray */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidCoordinate2DArray
(
    const SRM_Coordinate2D_Array *value_ptr,
          SRM_Boolean             print_error,
          SRM_Integer_Unsigned   *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidCoordinate2DArray: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->coordinate2D_array && (value_ptr->length>0))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->coordinate2D_array for"\
                   " value_ptr->length == %u\n",(unsigned int)
                    value_ptr->length);
        }
    }
    return result;
} /* end SRM_ValidCoordinate2DArray */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidCoordinate3DArray */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidCoordinate3DArray
(
    const SRM_Coordinate3D_Array *value_ptr,
          SRM_Boolean             print_error,
          SRM_Integer_Unsigned   *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidCoordinate3DArray: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->coordinate3D_array && (value_ptr->length>0))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->coordinate3D_array for"\
                   " value_ptr->length == %u\n",(unsigned int)
                    value_ptr->length);
        }
    }
    return result;
} /* end SRM_ValidCoordinate3DArray */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidCSCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidCSCode
(
    SRM_CS_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_CSCOD_UNSPECIFIED:
        case SRM_CSCOD_EUCLIDEAN_3D:
        case SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D:
        case SRM_CSCOD_SPHERICAL:
        case SRM_CSCOD_LOCOCENTRIC_SPHERICAL:
        case SRM_CSCOD_AZIMUTHAL_SPHERICAL:
        case SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL_SPHERICAL:
        case SRM_CSCOD_GEODETIC:
        case SRM_CSCOD_PLANETODETIC:
        case SRM_CSCOD_CYLINDRICAL:
        case SRM_CSCOD_LOCOCENTRIC_CYLINDRICAL:
        case SRM_CSCOD_MERCATOR:
        case SRM_CSCOD_OBLIQUE_MERCATOR_SPHERICAL:
        case SRM_CSCOD_TRANSVERSE_MERCATOR:
        case SRM_CSCOD_LAMBERT_CONFORMAL_CONIC:
        case SRM_CSCOD_POLAR_STEREOGRAPHIC:
        case SRM_CSCOD_EQUIDISTANT_CYLINDRICAL:
        case SRM_CSCOD_SURFACE_GEODETIC:
        case SRM_CSCOD_SURFACE_PLANETODETIC:
        case SRM_CSCOD_LOCOCENTRIC_SURFACE_EUCLIDEAN:
        case SRM_CSCOD_LOCOCENTRIC_SURFACE_AZIMUTHAL:
        case SRM_CSCOD_LOCOCENTRIC_SURFACE_POLAR:
        case SRM_CSCOD_EUCLIDEAN_2D:
        case SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_2D:
        case SRM_CSCOD_AZIMUTHAL:
        case SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL:
        case SRM_CSCOD_POLAR:
        case SRM_CSCOD_LOCOCENTRIC_POLAR:
        case SRM_CSCOD_EUCLIDEAN_1D:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidDirectionArray */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidDirectionArray
(
    const SRM_Direction_Array *value_ptr,
          SRM_Boolean          print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidDirectionArray: NULL value_ptr\n");
        }
        return result;
    }

    if (!value_ptr->direction_array && (value_ptr->length>0))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr,"NULL value_ptr->direction_array for"\
                   " value_ptr->length == %u\n",(unsigned int)
                    value_ptr->length);
        }
    }
    return result;
} /* end SRM_ValidDirectionArray */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidDSSCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidDSSCode
(
    SRM_DSS_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_DSSCOD_UNSPECIFIED:
        case SRM_DSSCOD_EGM96_GEOID:
        case SRM_DSSCOD_IGLD_1955:
        case SRM_DSSCOD_IGLD_1985:
        case SRM_DSSCOD_MSL:
        case SRM_DSSCOD_NAVD_1988:
        case SRM_DSSCOD_NGVD_1929:
        case SRM_DSSCOD_OSGM_2002:
        case SRM_DSSCOD_WGS84_ELLIPSOID:
        case SRM_DSSCOD_EGM84_GEOID:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidDSSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidECParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidECParameters
(
    const SRM_EC_Parameters *value_ptr,
          SRM_Boolean        print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidECParameters: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->central_scale < 0.75-CLOSE_DELTA) || (value_ptr->central_scale > 1.25+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidECParameters: central_scale"\
                    " out of range [0.75, 1.25]!\n");
    }
    return result;
} /* end SRM_ValidECParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidEI3DCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidEI3DCoordinate
(
    const SRM_EI_3D_Coordinate *value_ptr,
          SRM_Boolean           print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidEI3DCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->radius <= -CLOSE_DELTA)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidEI3DCoordinate: radius"\
                    " <= 0.0!\n");
    }
    return result;
} /* end SRM_ValidEI3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidIntegerPositive */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidIntegerPositive
(
    SRM_Integer_Positive value
)
{
    SRM_Boolean result = SRM_TRUE;

    if (value < 1)
        result = SRM_FALSE;

    return result;
} /* end SRM_ValidIntegerPositive */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidIntervalType */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidIntervalType
(
    SRM_Interval_Type value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_IVLTYP_OPEN_INTERVAL:
        case SRM_IVLTYP_GE_LT_INTERVAL:
        case SRM_IVLTYP_GT_LE_INTERVAL:
        case SRM_IVLTYP_CLOSED_INTERVAL:
        case SRM_IVLTYP_GT_SEMI_INTERVAL:
        case SRM_IVLTYP_GE_SEMI_INTERVAL:
        case SRM_IVLTYP_LT_SEMI_INTERVAL:
        case SRM_IVLTYP_LE_SEMI_INTERVAL:
        case SRM_IVLTYP_UNBOUNDED:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidIntervalType */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLocalTangentParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLocalTangentParameters
(
    const SRM_Local_Tangent_Parameters *value_ptr,
          SRM_Boolean                   print_error,
          SRM_Integer_Unsigned         *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLocalTangentParameters: NULL value_ptr\n");
        }
        return result;
    }

    return result;
} /* end SRM_ValidLocalTangentParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLSA2DCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLSA2DCoordinate
(
    const SRM_LSA_2D_Coordinate *value_ptr,
          SRM_Boolean            print_error,
          SRM_Integer_Unsigned  *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLSA2DCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->radius <= -CLOSE_DELTA)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidLSA2DCoordinate: radius"\
                    " <= 0.0!\n");
    }
    return result;
} /* end SRM_ValidLSA2DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLSP2DCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLSP2DCoordinate
(
    const SRM_LSP_2D_Coordinate *value_ptr,
          SRM_Boolean            print_error,
          SRM_Integer_Unsigned  *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLSP2DCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->radius <= -CLOSE_DELTA)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidLSP2DCoordinate: radius"\
                    " <= 0.0!\n");
    }
    return result;
} /* end SRM_ValidLSP2DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLSR2DParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLSR2DParameters
(
    const SRM_LSR_2D_Parameters *value_ptr,
          SRM_Boolean            print_error,
          SRM_Integer_Unsigned  *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLSR2DParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SRM_ValidAxisDirection(value_ptr->forward_direction))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SRM_Axis_Direction value (%d)\n", (int)
                value_ptr->forward_direction);
    }
    else if ((value_ptr->forward_direction ==
             SRM_AXDIR_POSITIVE_TERTIARY_AXIS) ||
            (value_ptr->forward_direction ==
             SRM_AXDIR_NEGATIVE_TERTIARY_AXIS))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "SRM_ValidLSR2DParameters: invalid "\
                 "forward_direction %s\n",
                 SRM_PrintAxisDirection(value_ptr->forward_direction));
    }
    return result;
} /* end SRM_ValidLSR2DParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLSR3DParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLSR3DParameters
(
    const SRM_LSR_3D_Parameters *value_ptr,
          SRM_Boolean            print_error,
          SRM_Integer_Unsigned  *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLSR3DParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SRM_ValidAxisDirection(value_ptr->forward_direction))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SRM_Axis_Direction value (%d)\n", (int)
                value_ptr->forward_direction);
    }
    switch (value_ptr->up_direction)
    {
        case SRM_AXDIR_POSITIVE_PRIMARY_AXIS:
        case SRM_AXDIR_NEGATIVE_PRIMARY_AXIS:
             if ((value_ptr->forward_direction ==
                  SRM_AXDIR_POSITIVE_PRIMARY_AXIS) ||
                 (value_ptr->forward_direction ==
                  SRM_AXDIR_NEGATIVE_PRIMARY_AXIS))
             {
                 result = SRM_FALSE;
                 if (error_count_ptr)
                     (*error_count_ptr)++;
                 if (print_error)
                     fprintf(f_ptr,
                             "Can't have forward_direction and "\
                             "up_direction lying on the same axis\n");
             }
             break;

        case SRM_AXDIR_POSITIVE_SECONDARY_AXIS:
        case SRM_AXDIR_NEGATIVE_SECONDARY_AXIS:
             if ((value_ptr->forward_direction ==
                  SRM_AXDIR_POSITIVE_SECONDARY_AXIS) ||
                 (value_ptr->forward_direction ==
                  SRM_AXDIR_NEGATIVE_SECONDARY_AXIS))
             {
                 result = SRM_FALSE;
                 if (error_count_ptr)
                     (*error_count_ptr)++;
                 if (print_error)
                     fprintf(f_ptr,
                             "Can't have forward_direction and "\
                             "up_direction lying on the same axis\n");
             }
             break;

        case SRM_AXDIR_POSITIVE_TERTIARY_AXIS:
        case SRM_AXDIR_NEGATIVE_TERTIARY_AXIS:
             if ((value_ptr->forward_direction ==
                  SRM_AXDIR_POSITIVE_TERTIARY_AXIS) ||
                 (value_ptr->forward_direction ==
                  SRM_AXDIR_NEGATIVE_TERTIARY_AXIS))
             {
                 result = SRM_FALSE;
                 if (error_count_ptr)
                     (*error_count_ptr)++;
                 if (print_error)
                     fprintf(f_ptr,
                             "Can't have forward_direction and "\
                             "up_direction lying on the same axis\n");
             }
             break;

        default:
             result = SRM_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr,
                         "Illegal SRM_Axis_Direction value (%s)\n",
                         SRM_PrintAxisDirection(value_ptr->up_direction));
             break;
    } /* end switch */

    return result;
} /* end SRM_ValidLSR3DParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLTSAS3DCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLTSAS3DCoordinate
(
    const SRM_LTSAS_3D_Coordinate *value_ptr,
          SRM_Boolean              print_error,
          SRM_Integer_Unsigned    *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLTSAS3DCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->radius <= -CLOSE_DELTA)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidLTSAS3DCoordinate: radius"\
                    " <= 0.0!\n");
    }
    return result;
} /* end SRM_ValidLTSAS3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLTSC3DCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLTSC3DCoordinate
(
    const SRM_LTSC_3D_Coordinate *value_ptr,
          SRM_Boolean             print_error,
          SRM_Integer_Unsigned   *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLTSC3DCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->radius <= -CLOSE_DELTA)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidLTSC3DCoordinate: radius"\
                    " <= 0.0!\n");
    }
    return result;
} /* end SRM_ValidLTSC3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLTSCSurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLTSCSurfaceCoordinate
(
    const SRM_LTSC_Surface_Coordinate *value_ptr,
          SRM_Boolean                  print_error,
          SRM_Integer_Unsigned        *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLTSCSurfaceCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->radius <= -CLOSE_DELTA)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidLTSCSurfaceCoordinate: radius"\
                    " <= 0.0!\n");
    }
    return result;
} /* end SRM_ValidLTSCSurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidLTSEParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidLTSEParameters
(
    const SRM_LTSE_Parameters *value_ptr,
          SRM_Boolean          print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidLTSEParameters: NULL value_ptr\n");
        }
        return result;
    }

    return result;
} /* end SRM_ValidLTSEParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidMParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidMParameters
(
    const SRM_M_Parameters *value_ptr,
          SRM_Boolean       print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidMParameters: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->central_scale < 0.75-CLOSE_DELTA) || (value_ptr->central_scale > 1.25+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidMParameters: central_scale"\
                    " out of range [0.75, 1.25]!\n");
    }
    return result;
} /* end SRM_ValidMParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidObliqueMercatorParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidObliqueMercatorParameters
(
    const SRM_Oblique_Mercator_Parameters *value_ptr,
          SRM_Boolean                      print_error,
          SRM_Integer_Unsigned            *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidObliqueMercatorParameters: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->central_scale < 0.75-CLOSE_DELTA) || (value_ptr->central_scale > 1.25+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidObliqueMercatorParameters: central_scale"\
                    " out of range [0.75, 1.25]!\n");
    }
    return result;
} /* end SRM_ValidObliqueMercatorParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidORMCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidORMCode
(
    SRM_ORM_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_ORMCOD_UNSPECIFIED:
        case SRM_ORMCOD_ABSTRACT_2D:
        case SRM_ORMCOD_ABSTRACT_3D:
        case SRM_ORMCOD_ADINDAN_1991:
        case SRM_ORMCOD_ADRASTEA_2000:
        case SRM_ORMCOD_AFGOOYE_1987:
        case SRM_ORMCOD_AIN_EL_ABD_1970:
        case SRM_ORMCOD_AMALTHEA_2000:
        case SRM_ORMCOD_AMERICAN_SAMOA_1962:
        case SRM_ORMCOD_ANNA_1_1965:
        case SRM_ORMCOD_ANTIGUA_1943:
        case SRM_ORMCOD_ARC_1950:
        case SRM_ORMCOD_ARC_1960:
        case SRM_ORMCOD_ARIEL_1988:
        case SRM_ORMCOD_ASCENSION_1958:
        case SRM_ORMCOD_ATLAS_1988:
        case SRM_ORMCOD_AUSTRALIAN_GEOD_1966:
        case SRM_ORMCOD_AUSTRALIAN_GEOD_1984:
        case SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991:
        case SRM_ORMCOD_BEACON_E_1945:
        case SRM_ORMCOD_BELINDA_1988:
        case SRM_ORMCOD_BELLEVUE_IGN_1987:
        case SRM_ORMCOD_BERMUDA_1957:
        case SRM_ORMCOD_BIANCA_1988:
        case SRM_ORMCOD_BISSAU_1991:
        case SRM_ORMCOD_BOGOTA_OBS_1987:
        case SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA:
        case SRM_ORMCOD_BUKIT_RIMPAH_1987:
        case SRM_ORMCOD_CALLISTO_2000:
        case SRM_ORMCOD_CALYPSO_1988:
        case SRM_ORMCOD_CAMP_AREA_1987:
        case SRM_ORMCOD_CAMPO_INCHAUSPE_1969:
        case SRM_ORMCOD_CANTON_1966:
        case SRM_ORMCOD_CAPE_1987:
        case SRM_ORMCOD_CAPE_CANAVERAL_1991:
        case SRM_ORMCOD_CARTHAGE_1987:
        case SRM_ORMCOD_CHARON_1991:
        case SRM_ORMCOD_CHATHAM_1971:
        case SRM_ORMCOD_CHUA_1987:
        case SRM_ORMCOD_COAMPS_1998:
        case SRM_ORMCOD_CORDELIA_1988:
        case SRM_ORMCOD_CORREGO_ALEGRE_1987:
        case SRM_ORMCOD_CRESSIDA_1988:
        case SRM_ORMCOD_DABOLA_1991:
        case SRM_ORMCOD_DECEPTION_1993:
        case SRM_ORMCOD_DEIMOS_1988:
        case SRM_ORMCOD_DESDEMONA_1988:
        case SRM_ORMCOD_DESPINA_1991:
        case SRM_ORMCOD_DIONE_1982:
        case SRM_ORMCOD_DJAKARTA_1987:
        case SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA:
        case SRM_ORMCOD_DOS_1968:
        case SRM_ORMCOD_DOS_71_4_1987:
        case SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950:
        case SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE:
        case SRM_ORMCOD_EARTH_INERTIAL_J2000r0:
        case SRM_ORMCOD_EARTH_SOLAR_ECLIPTIC:
        case SRM_ORMCOD_EARTH_SOLAR_EQUATORIAL:
        case SRM_ORMCOD_EARTH_SOLAR_MAG_DIPOLE:
        case SRM_ORMCOD_EARTH_SOLAR_MAGNETOSPHERIC:
        case SRM_ORMCOD_EASTER_1967:
        case SRM_ORMCOD_ENCELADUS_1994:
        case SRM_ORMCOD_EPIMETHEUS_1988:
        case SRM_ORMCOD_EROS_2000:
        case SRM_ORMCOD_ESTONIA_1937:
        case SRM_ORMCOD_ETRS_1989:
        case SRM_ORMCOD_EUROPA_2000:
        case SRM_ORMCOD_EUROPE_1950:
        case SRM_ORMCOD_EUROPE_1979:
        case SRM_ORMCOD_FAHUD_1987:
        case SRM_ORMCOD_FORT_THOMAS_1955:
        case SRM_ORMCOD_GALATEA_1991:
        case SRM_ORMCOD_GAN_1970:
        case SRM_ORMCOD_GANYMEDE_2000:
        case SRM_ORMCOD_GASPRA_1991:
        case SRM_ORMCOD_GDA_1994:
        case SRM_ORMCOD_GEODETIC_DATUM_1949:
        case SRM_ORMCOD_GEOMAGNETIC_1945:
        case SRM_ORMCOD_GEOMAGNETIC_1950:
        case SRM_ORMCOD_GEOMAGNETIC_1955:
        case SRM_ORMCOD_GEOMAGNETIC_1960:
        case SRM_ORMCOD_GEOMAGNETIC_1965:
        case SRM_ORMCOD_GEOMAGNETIC_1970:
        case SRM_ORMCOD_GEOMAGNETIC_1975:
        case SRM_ORMCOD_GEOMAGNETIC_1980:
        case SRM_ORMCOD_GEOMAGNETIC_1985:
        case SRM_ORMCOD_GEOMAGNETIC_1990:
        case SRM_ORMCOD_GEOMAGNETIC_1995:
        case SRM_ORMCOD_GEOMAGNETIC_2000:
        case SRM_ORMCOD_GRACIOSA_BASE_SW_1948:
        case SRM_ORMCOD_GUAM_1963:
        case SRM_ORMCOD_GUNONG_SEGARA_1987:
        case SRM_ORMCOD_GUX_1_1987:
        case SRM_ORMCOD_HELENE_1992:
        case SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_J2000r0:
        case SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE:
        case SRM_ORMCOD_HELIO_EARTH_ECLIPTIC:
        case SRM_ORMCOD_HELIO_EARTH_EQUATORIAL:
        case SRM_ORMCOD_HERAT_NORTH_1987:
        case SRM_ORMCOD_HERMANNSKOGEL_1871:
        case SRM_ORMCOD_HJORSEY_1955:
        case SRM_ORMCOD_HONG_KONG_1963:
        case SRM_ORMCOD_HU_TZU_SHAN_1991:
        case SRM_ORMCOD_IAPETUS_1988:
        case SRM_ORMCOD_IDA_1991:
        case SRM_ORMCOD_INDIAN_1916:
        case SRM_ORMCOD_INDIAN_1954:
        case SRM_ORMCOD_INDIAN_1956:
        case SRM_ORMCOD_INDIAN_1960:
        case SRM_ORMCOD_INDIAN_1962:
        case SRM_ORMCOD_INDIAN_1975:
        case SRM_ORMCOD_INDONESIAN_1974:
        case SRM_ORMCOD_IO_2000:
        case SRM_ORMCOD_IRELAND_1965:
        case SRM_ORMCOD_ISTS_061_1968:
        case SRM_ORMCOD_ISTS_073_1969:
        case SRM_ORMCOD_JANUS_1988:
        case SRM_ORMCOD_JGD_2000:
        case SRM_ORMCOD_JOHNSTON_1961:
        case SRM_ORMCOD_JULIET_1988:
        case SRM_ORMCOD_JUPITER_1988:
        case SRM_ORMCOD_JUPITER_INERTIAL:
        case SRM_ORMCOD_JUPITER_MAGNETIC_1993:
        case SRM_ORMCOD_JUPITER_SOLAR_ECLIPTIC:
        case SRM_ORMCOD_JUPITER_SOLAR_EQUATORIAL:
        case SRM_ORMCOD_JUPITER_SOLAR_MAG_DIPOLE:
        case SRM_ORMCOD_JUPITER_SOLAR_MAG_ECLIPTIC:
        case SRM_ORMCOD_KANDAWALA_1987:
        case SRM_ORMCOD_KERGUELEN_1949:
        case SRM_ORMCOD_KERTAU_1948:
        case SRM_ORMCOD_KOREAN_GEODETIC_1995:
        case SRM_ORMCOD_KUSAIE_1951:
        case SRM_ORMCOD_LARISSA_1991:
        case SRM_ORMCOD_LC5_1961:
        case SRM_ORMCOD_LEIGON_1991:
        case SRM_ORMCOD_LIBERIA_1964:
        case SRM_ORMCOD_LUZON_1987:
        case SRM_ORMCOD_M_PORALOKO_1991:
        case SRM_ORMCOD_MAHE_1971:
        case SRM_ORMCOD_MARCUS_STATION_1952:
        case SRM_ORMCOD_MARS_2000:
        case SRM_ORMCOD_MARS_INERTIAL:
        case SRM_ORMCOD_MARS_SPHERE_2000:
        case SRM_ORMCOD_MASS_1999:
        case SRM_ORMCOD_MASSAWA_1987:
        case SRM_ORMCOD_MERCHICH_1987:
        case SRM_ORMCOD_MERCURY_1988:
        case SRM_ORMCOD_MERCURY_INERTIAL:
        case SRM_ORMCOD_METIS_2000:
        case SRM_ORMCOD_MIDWAY_1961:
        case SRM_ORMCOD_MIMAS_1994:
        case SRM_ORMCOD_MINNA_1991:
        case SRM_ORMCOD_MIRANDA_1988:
        case SRM_ORMCOD_MM5_1997:
        case SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989:
        case SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989:
        case SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989:
        case SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989:
        case SRM_ORMCOD_MODTRAN_TROPICAL_1989:
        case SRM_ORMCOD_MONTSERRAT_1958:
        case SRM_ORMCOD_MOON_1991:
        case SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989:
        case SRM_ORMCOD_N_AM_1927:
        case SRM_ORMCOD_N_AM_1983:
        case SRM_ORMCOD_N_SAHARA_1959:
        case SRM_ORMCOD_NAHRWAN_1987:
        case SRM_ORMCOD_NAIAD_1991:
        case SRM_ORMCOD_NAPARIMA_1991:
        case SRM_ORMCOD_NEPTUNE_1991:
        case SRM_ORMCOD_NEPTUNE_INERTIAL:
        case SRM_ORMCOD_NEPTUNE_MAGNETIC_1993:
        case SRM_ORMCOD_NOGAPS_1988:
        case SRM_ORMCOD_NTF_1896:
        case SRM_ORMCOD_NTF_1896_PM_PARIS:
        case SRM_ORMCOD_OBERON_1988:
        case SRM_ORMCOD_OBSERV_METEORO_1939:
        case SRM_ORMCOD_OLD_EGYPTIAN_1907:
        case SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987:
        case SRM_ORMCOD_OLD_HAWAIIAN_INT_1987:
        case SRM_ORMCOD_OPHELIA_1988:
        case SRM_ORMCOD_OSGB_1936:
        case SRM_ORMCOD_PAN_1991:
        case SRM_ORMCOD_PANDORA_1988:
        case SRM_ORMCOD_PHOBOS_1988:
        case SRM_ORMCOD_PHOEBE_1988:
        case SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987:
        case SRM_ORMCOD_PITCAIRN_1967:
        case SRM_ORMCOD_PLUTO_1994:
        case SRM_ORMCOD_PLUTO_INERTIAL:
        case SRM_ORMCOD_POINT_58_1991:
        case SRM_ORMCOD_POINTE_NOIRE_1948:
        case SRM_ORMCOD_PORTIA_1988:
        case SRM_ORMCOD_PORTO_SANTO_1936:
        case SRM_ORMCOD_PROMETHEUS_1988:
        case SRM_ORMCOD_PROTEUS_1991:
        case SRM_ORMCOD_PROV_S_AM_1956:
        case SRM_ORMCOD_PROV_S_CHILEAN_1963:
        case SRM_ORMCOD_PUCK_1988:
        case SRM_ORMCOD_PUERTO_RICO_1987:
        case SRM_ORMCOD_PULKOVO_1942:
        case SRM_ORMCOD_QATAR_NATIONAL_1974:
        case SRM_ORMCOD_QORNOQ_1987:
        case SRM_ORMCOD_REUNION_1947:
        case SRM_ORMCOD_RGF_1993:
        case SRM_ORMCOD_RHEA_1988:
        case SRM_ORMCOD_ROME_1940:
        case SRM_ORMCOD_ROME_1940_PM_ROME:
        case SRM_ORMCOD_ROSALIND_1988:
        case SRM_ORMCOD_S_AM_1969:
        case SRM_ORMCOD_S_ASIA_1987:
        case SRM_ORMCOD_S_JTSK_1993:
        case SRM_ORMCOD_S42_PULKOVO:
        case SRM_ORMCOD_SANTO_DOS_1965:
        case SRM_ORMCOD_SAO_BRAZ_1987:
        case SRM_ORMCOD_SAPPER_HILL_1943:
        case SRM_ORMCOD_SATURN_1988:
        case SRM_ORMCOD_SATURN_INERTIAL:
        case SRM_ORMCOD_SATURN_MAGNETIC_1993:
        case SRM_ORMCOD_SCHWARZECK_1991:
        case SRM_ORMCOD_SELVAGEM_GRANDE_1938:
        case SRM_ORMCOD_SIERRA_LEONE_1960:
        case SRM_ORMCOD_SIRGAS_2000:
        case SRM_ORMCOD_SUN_1992:
        case SRM_ORMCOD_TANANARIVE_OBS_1925:
        case SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS:
        case SRM_ORMCOD_TELESTO_1988:
        case SRM_ORMCOD_TERN_1961:
        case SRM_ORMCOD_TETHYS_1991:
        case SRM_ORMCOD_THALASSA_1991:
        case SRM_ORMCOD_THEBE_2000:
        case SRM_ORMCOD_TIMBALAI_EVEREST_1948:
        case SRM_ORMCOD_TITAN_1982:
        case SRM_ORMCOD_TITANIA_1988:
        case SRM_ORMCOD_TOKYO_1991:
        case SRM_ORMCOD_TRISTAN_1968:
        case SRM_ORMCOD_TRITON_1991:
        case SRM_ORMCOD_UMBRIEL_1988:
        case SRM_ORMCOD_URANUS_1988:
        case SRM_ORMCOD_URANUS_INERTIAL:
        case SRM_ORMCOD_URANUS_MAGNETIC_1993:
        case SRM_ORMCOD_VENUS_1991:
        case SRM_ORMCOD_VENUS_INERTIAL:
        case SRM_ORMCOD_VITI_LEVU_1916:
        case SRM_ORMCOD_VOIROL_1874:
        case SRM_ORMCOD_VOIROL_1874_PM_PARIS:
        case SRM_ORMCOD_VOIROL_1960:
        case SRM_ORMCOD_VOIROL_1960_PM_PARIS:
        case SRM_ORMCOD_WAKE_1952:
        case SRM_ORMCOD_WAKE_ENIWETOK_1960:
        case SRM_ORMCOD_WGS_1972:
        case SRM_ORMCOD_WGS_1984:
        case SRM_ORMCOD_YACARE_1987:
        case SRM_ORMCOD_ZANDERIJ_1987:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidORMCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidORMTCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidORMTCode
(
    SRM_ORMT_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_ORMTCOD_UNSPECIFIED:
        case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
        case SRM_ORMTCOD_SPHERE:
        case SRM_ORMTCOD_OBLATE_ELLIPSOID:
        case SRM_ORMTCOD_PROLATE_ELLIPSOID:
        case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
        case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
        case SRM_ORMTCOD_SPHERE_ORIGIN:
        case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
        case SRM_ORMTCOD_TRI_PLANE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidORMTCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidPD3DCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidPD3DCoordinate
(
    const SRM_PD_3D_Coordinate *value_ptr,
          SRM_Boolean           print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidPD3DCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->longitude < -180.0-CLOSE_DELTA) || (value_ptr->longitude > 180.0+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidPD3DCoordinate: longitude"\
                    " out of range [-180.0, 180.0]!\n");
    }
    if ((value_ptr->latitude < -90.0-CLOSE_DELTA) || (value_ptr->latitude > 90.0+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidPD3DCoordinate: latitude"\
                    " out of range [-90.0, 90.0]!\n");
    }
    return result;
} /* end SRM_ValidPD3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidPDSurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidPDSurfaceCoordinate
(
    const SRM_PD_Surface_Coordinate *value_ptr,
          SRM_Boolean                print_error,
          SRM_Integer_Unsigned      *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidPDSurfaceCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->longitude < -180.0-CLOSE_DELTA) || (value_ptr->longitude > 180.0+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidPDSurfaceCoordinate: longitude"\
                    " out of range [-180.0, 180.0]!\n");
    }
    if ((value_ptr->latitude < -90.0-CLOSE_DELTA) || (value_ptr->latitude > 90.0+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidPDSurfaceCoordinate: latitude"\
                    " out of range [-90.0, 90.0]!\n");
    }
    return result;
} /* end SRM_ValidPDSurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidPolarAspect */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidPolarAspect
(
    SRM_Polar_Aspect value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_PLRASP_NORTH:
        case SRM_PLRASP_SOUTH:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidPolarAspect */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidPSParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidPSParameters
(
    const SRM_PS_Parameters *value_ptr,
          SRM_Boolean        print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidPSParameters: NULL value_ptr\n");
        }
        return result;
    }

    if (!SRM_ValidPolarAspect(value_ptr->polar_aspect))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SRM_Polar_Aspect value (%d)\n", (int)
                value_ptr->polar_aspect);
    }
    if ((value_ptr->central_scale < 0.75-CLOSE_DELTA) || (value_ptr->central_scale > 1.25+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidPSParameters: central_scale"\
                    " out of range [0.75, 1.25]!\n");
    }
    return result;
} /* end SRM_ValidPSParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidRDCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidRDCode
(
    SRM_RD_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_RDCOD_ORIGIN_2D:
        case SRM_RDCOD_X_UNIT_POINT_2D:
        case SRM_RDCOD_Y_UNIT_POINT_2D:
        case SRM_RDCOD_ORIGIN_3D:
        case SRM_RDCOD_X_UNIT_POINT_3D:
        case SRM_RDCOD_Y_UNIT_POINT_3D:
        case SRM_RDCOD_Z_UNIT_POINT_3D:
        case SRM_RDCOD_X_AXIS_2D:
        case SRM_RDCOD_Y_AXIS_2D:
        case SRM_RDCOD_X_AXIS_3D:
        case SRM_RDCOD_Y_AXIS_3D:
        case SRM_RDCOD_Z_AXIS_3D:
        case SRM_RDCOD_XY_PLANE_3D:
        case SRM_RDCOD_XZ_PLANE_3D:
        case SRM_RDCOD_YZ_PLANE_3D:
        case SRM_RDCOD_ADRASTEA_2000:
        case SRM_RDCOD_AIRY_1830:
        case SRM_RDCOD_AMALTHEA_2000:
        case SRM_RDCOD_ANANKE_1988:
        case SRM_RDCOD_APL_4r5_1968:
        case SRM_RDCOD_ARIEL_1988:
        case SRM_RDCOD_ATLAS_1988:
        case SRM_RDCOD_AUSTRALIAN_NATIONAL_1966:
        case SRM_RDCOD_AVERAGE_TERRESTRIAL_1977:
        case SRM_RDCOD_BELINDA_1988:
        case SRM_RDCOD_BESSEL_1841_ETHIOPIA:
        case SRM_RDCOD_BESSEL_1841_NAMIBIA:
        case SRM_RDCOD_BIANCA_1988:
        case SRM_RDCOD_CALLISTO_2000:
        case SRM_RDCOD_CALYPSO_1988:
        case SRM_RDCOD_CARME_1988:
        case SRM_RDCOD_CHARON_1991:
        case SRM_RDCOD_CLARKE_1858:
        case SRM_RDCOD_CLARKE_1858_MODIFIED:
        case SRM_RDCOD_CLARKE_1866:
        case SRM_RDCOD_CLARKE_1880:
        case SRM_RDCOD_CLARKE_1880_CAPE:
        case SRM_RDCOD_CLARKE_1880_FIJI:
        case SRM_RDCOD_CLARKE_1880_IGN:
        case SRM_RDCOD_CLARKE_1880_PALESTINE:
        case SRM_RDCOD_CLARKE_1880_SYRIA:
        case SRM_RDCOD_COAMPS_1998:
        case SRM_RDCOD_CORDELIA_1988:
        case SRM_RDCOD_CRESSIDA_1988:
        case SRM_RDCOD_DANISH_1876:
        case SRM_RDCOD_DEIMOS_1988:
        case SRM_RDCOD_DELAMBRE_1810:
        case SRM_RDCOD_DESDEMONA_1988:
        case SRM_RDCOD_DESPINA_1991:
        case SRM_RDCOD_DIONE_1982:
        case SRM_RDCOD_ELARA_1988:
        case SRM_RDCOD_ENCELADUS_1994:
        case SRM_RDCOD_EPIMETHEUS_1988:
        case SRM_RDCOD_EROS_2000:
        case SRM_RDCOD_EUROPA_2000:
        case SRM_RDCOD_EVEREST_ADJ_1937:
        case SRM_RDCOD_EVEREST_1948:
        case SRM_RDCOD_EVEREST_1956:
        case SRM_RDCOD_EVEREST_REVISED_1962:
        case SRM_RDCOD_EVEREST_1969:
        case SRM_RDCOD_EVEREST_BRUNEI_1967:
        case SRM_RDCOD_FISCHER_1960:
        case SRM_RDCOD_FISCHER_1968:
        case SRM_RDCOD_GALATEA_1991:
        case SRM_RDCOD_GANYMEDE_2000:
        case SRM_RDCOD_GASPRA_1991:
        case SRM_RDCOD_GRS_1967:
        case SRM_RDCOD_GRS_1980:
        case SRM_RDCOD_HELENE_1992:
        case SRM_RDCOD_HELMERT_1906:
        case SRM_RDCOD_HIMALIA_1988:
        case SRM_RDCOD_HOUGH_1960:
        case SRM_RDCOD_HYPERION_2000:
        case SRM_RDCOD_IAG_1975:
        case SRM_RDCOD_IAPETUS_1988:
        case SRM_RDCOD_IDA_1991:
        case SRM_RDCOD_INDONESIAN_1974:
        case SRM_RDCOD_INTERNATIONAL_1924:
        case SRM_RDCOD_IO_2000:
        case SRM_RDCOD_JANUS_1988:
        case SRM_RDCOD_JULIET_1988:
        case SRM_RDCOD_JUPITER_1988:
        case SRM_RDCOD_KLEOPATRA_2000:
        case SRM_RDCOD_KRASSOVSKY_1940:
        case SRM_RDCOD_KRAYENHOFF_1827:
        case SRM_RDCOD_LARISSA_1991:
        case SRM_RDCOD_LEDA_1988:
        case SRM_RDCOD_LYSITHEA_1988:
        case SRM_RDCOD_MARS_2000:
        case SRM_RDCOD_MARS_SPHERE_2000:
        case SRM_RDCOD_MASS_1999:
        case SRM_RDCOD_MERCURY_1988:
        case SRM_RDCOD_METIS_2000:
        case SRM_RDCOD_MIMAS_1994:
        case SRM_RDCOD_MIRANDA_1988:
        case SRM_RDCOD_MM5_1997:
        case SRM_RDCOD_MODIFIED_AIRY_1849:
        case SRM_RDCOD_MODIFIED_FISCHER_1960:
        case SRM_RDCOD_MODTRAN_MIDLATITUDE_1989:
        case SRM_RDCOD_MODTRAN_SUBARCTIC_1989:
        case SRM_RDCOD_MODTRAN_TROPICAL_1989:
        case SRM_RDCOD_MOON_1991:
        case SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989:
        case SRM_RDCOD_NAIAD_1991:
        case SRM_RDCOD_NEPTUNE_1991:
        case SRM_RDCOD_NEREID_1991:
        case SRM_RDCOD_NOGAPS_1988:
        case SRM_RDCOD_OBERON_1988:
        case SRM_RDCOD_OPHELIA_1988:
        case SRM_RDCOD_PAN_1991:
        case SRM_RDCOD_PANDORA_1988:
        case SRM_RDCOD_PASIPHAE_1988:
        case SRM_RDCOD_PHOBOS_1988:
        case SRM_RDCOD_PHOEBE_1988:
        case SRM_RDCOD_PLESSIS_MODIFIED_1817:
        case SRM_RDCOD_PLUTO_1994:
        case SRM_RDCOD_PORTIA_1988:
        case SRM_RDCOD_PROMETHEUS_1988:
        case SRM_RDCOD_PROTEUS_1991:
        case SRM_RDCOD_PUCK_1988:
        case SRM_RDCOD_RHEA_1988:
        case SRM_RDCOD_ROSALIND_1988:
        case SRM_RDCOD_SATURN_1988:
        case SRM_RDCOD_SINOPE_1988:
        case SRM_RDCOD_SOUTH_AMERICAN_1969:
        case SRM_RDCOD_SOVIET_GEODETIC_1985:
        case SRM_RDCOD_SOVIET_GEODETIC_1990:
        case SRM_RDCOD_STRUVE_1860:
        case SRM_RDCOD_SUN_1992:
        case SRM_RDCOD_TELESTO_1988:
        case SRM_RDCOD_TETHYS_1991:
        case SRM_RDCOD_THALASSA_1991:
        case SRM_RDCOD_THEBE_2000:
        case SRM_RDCOD_TITAN_1982:
        case SRM_RDCOD_TITANIA_1988:
        case SRM_RDCOD_TRITON_1991:
        case SRM_RDCOD_UMBRIEL_1988:
        case SRM_RDCOD_URANUS_1988:
        case SRM_RDCOD_VENUS_1991:
        case SRM_RDCOD_WALBECK_AMS_1963:
        case SRM_RDCOD_WALBECK_PLANHEFT_1942:
        case SRM_RDCOD_WAR_OFFICE_1924:
        case SRM_RDCOD_WGS_1960:
        case SRM_RDCOD_WGS_1966:
        case SRM_RDCOD_WGS_1984:
        case SRM_RDCOD_WGS_1972:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidRDCode */
/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ValidRTCode
 *
 *-----------------------------------------------------------------------------
 */
SRM_Boolean
SRM_ValidRTCode
(
    SRM_ORM_Code orm_code,
    SRM_RT_Code  rt_code
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (rt_code)
    {
        case SRM_RTCOD_UNSPECIFIED:
             if ((orm_code != SRM_ORMCOD_UNSPECIFIED)
              && (orm_code != SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950)
              && (orm_code != SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE)
              && (orm_code != SRM_ORMCOD_EARTH_INERTIAL_J2000r0))
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ABSTRACT_2D_IDENTITY:
             if (orm_code != SRM_ORMCOD_ABSTRACT_2D)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ABSTRACT_3D_IDENTITY:
             if (orm_code != SRM_ORMCOD_ABSTRACT_3D)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ADINDAN_1991_BURKINA_FASO:
        case SRM_RTCOD_ADINDAN_1991_CAMEROON:
        case SRM_RTCOD_ADINDAN_1991_ETHIOPIA:
        case SRM_RTCOD_ADINDAN_1991_MALI:
        case SRM_RTCOD_ADINDAN_1991_MEAN_SOLUTION:
        case SRM_RTCOD_ADINDAN_1991_SENEGAL:
        case SRM_RTCOD_ADINDAN_1991_SUDAN:
             if (orm_code != SRM_ORMCOD_ADINDAN_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ADRASTEA_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_ADRASTEA_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_AFGOOYE_1987_SOMALIA:
             if (orm_code != SRM_ORMCOD_AFGOOYE_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_AIN_EL_ABD_1970_BAHRAIN_ISLAND:
        case SRM_RTCOD_AIN_EL_ABD_1970_SAUDI_ARABIA:
             if (orm_code != SRM_ORMCOD_AIN_EL_ABD_1970)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_AMALTHEA_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_AMALTHEA_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS:
             if (orm_code != SRM_ORMCOD_AMERICAN_SAMOA_1962)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ANNA_1_1965_COCOS_ISLANDS:
             if (orm_code != SRM_ORMCOD_ANNA_1_1965)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS:
             if (orm_code != SRM_ORMCOD_ANTIGUA_1943)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ARC_1950_3_ZIMBABWE:
        case SRM_RTCOD_ARC_1950_BOTSWANA:
        case SRM_RTCOD_ARC_1950_BURUNDI:
        case SRM_RTCOD_ARC_1950_LESOTHO:
        case SRM_RTCOD_ARC_1950_MALAWI:
        case SRM_RTCOD_ARC_1950_MEAN_SOLUTION:
        case SRM_RTCOD_ARC_1950_SWAZILAND:
        case SRM_RTCOD_ARC_1950_ZAIRE:
        case SRM_RTCOD_ARC_1950_ZAMBIA:
             if (orm_code != SRM_ORMCOD_ARC_1950)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ARC_1960_3_KENYA:
        case SRM_RTCOD_ARC_1960_MEAN_SOLUTION:
        case SRM_RTCOD_ARC_1960_TANZANIA:
             if (orm_code != SRM_ORMCOD_ARC_1960)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ARIEL_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_ARIEL_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ASCENSION_1958_ASCENSION_ISLAND:
             if (orm_code != SRM_ORMCOD_ASCENSION_1958)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ATLAS_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_ATLAS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA:
             if (orm_code != SRM_ORMCOD_AUSTRALIAN_GEOD_1966)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA:
        case SRM_RTCOD_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA:
             if (orm_code != SRM_ORMCOD_AUSTRALIAN_GEOD_1984)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_AYABELLE_LIGHTHOUSE_1991_DJIBOUTI:
             if (orm_code != SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BEACON_E_1945_IWO_JIMA_ISLAND:
             if (orm_code != SRM_ORMCOD_BEACON_E_1945)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BELINDA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_BELINDA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS:
             if (orm_code != SRM_ORMCOD_BELLEVUE_IGN_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BERMUDA_1957_BERMUDA:
             if (orm_code != SRM_ORMCOD_BERMUDA_1957)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BIANCA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_BIANCA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BISSAU_1991_GUINEA_BISSAU:
             if (orm_code != SRM_ORMCOD_BISSAU_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BOGOTA_OBS_1987_COLOMBIA:
             if (orm_code != SRM_ORMCOD_BOGOTA_OBS_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BOGOTA_OBS_1987_PM_BOGOTA_COLOMBIA:
             if (orm_code != SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS:
             if (orm_code != SRM_ORMCOD_BUKIT_RIMPAH_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CALLISTO_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_CALLISTO_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CALYPSO_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_CALYPSO_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CAMP_AREA_1987_MCMURDO_CAMP:
             if (orm_code != SRM_ORMCOD_CAMP_AREA_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CAMPO_INCHAUSPE_1969_ARGENTINA:
             if (orm_code != SRM_ORMCOD_CAMPO_INCHAUSPE_1969)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CANTON_1966_PHOENIX_ISLANDS:
             if (orm_code != SRM_ORMCOD_CANTON_1966)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CAPE_1987_SOUTH_AFRICA:
             if (orm_code != SRM_ORMCOD_CAPE_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CAPE_CANAVERAL_1991_MEAN_SOLUTION:
             if (orm_code != SRM_ORMCOD_CAPE_CANAVERAL_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CARTHAGE_1987_TUNISIA:
             if (orm_code != SRM_ORMCOD_CARTHAGE_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CHARON_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_CHARON_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CHATHAM_1971_CHATHAM_ISLANDS:
             if (orm_code != SRM_ORMCOD_CHATHAM_1971)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CHUA_1987_PARAGUAY:
             if (orm_code != SRM_ORMCOD_CHUA_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_COAMPS_1998_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_COAMPS_1998)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CORDELIA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_CORDELIA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CORREGO_ALEGRE_1987_BRAZIL:
             if (orm_code != SRM_ORMCOD_CORREGO_ALEGRE_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_CRESSIDA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_CRESSIDA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DABOLA_1991_GUINEA:
             if (orm_code != SRM_ORMCOD_DABOLA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DECEPTION_1993_DECEPTION_ISLAND:
             if (orm_code != SRM_ORMCOD_DECEPTION_1993)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DEIMOS_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_DEIMOS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DESDEMONA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_DESDEMONA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DESPINA_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_DESPINA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DIONE_1982_IDENTITY:
             if (orm_code != SRM_ORMCOD_DIONE_1982)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DJAKARTA_1987_PM_DJAKARTA_SUMATRA:
             if (orm_code != SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DJAKARTA_1987_SUMATRA:
             if (orm_code != SRM_ORMCOD_DJAKARTA_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DOS_1968_GIZO_ISLAND:
             if (orm_code != SRM_ORMCOD_DOS_1968)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_DOS_71_4_1987_ST_HELENA_ISLAND:
             if (orm_code != SRM_ORMCOD_DOS_71_4_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_EASTER_1967_EASTER_ISLAND:
             if (orm_code != SRM_ORMCOD_EASTER_1967)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ENCELADUS_1994_IDENTITY:
             if (orm_code != SRM_ORMCOD_ENCELADUS_1994)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_EPIMETHEUS_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_EPIMETHEUS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_EROS_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_EROS_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ESTONIA_1937_ESTONIA:
             if (orm_code != SRM_ORMCOD_ESTONIA_1937)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ETRS_1989_IDENTITY_BY_MEASUREMENT:
             if (orm_code != SRM_ORMCOD_ETRS_1989)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_EUROPA_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_EUROPA_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_EUROPE_1950_3_CYPRUS:
        case SRM_RTCOD_EUROPE_1950_CHANNEL_ISLANDS:
        case SRM_RTCOD_EUROPE_1950_EGYPT:
        case SRM_RTCOD_EUROPE_1950_ENGLAND_SCOTLAND:
        case SRM_RTCOD_EUROPE_1950_GREECE:
        case SRM_RTCOD_EUROPE_1950_IRAN:
        case SRM_RTCOD_EUROPE_1950_IRAQ:
        case SRM_RTCOD_EUROPE_1950_IRELAND:
        case SRM_RTCOD_EUROPE_1950_MALTA:
        case SRM_RTCOD_EUROPE_1950_MEAN_SOLUTION:
        case SRM_RTCOD_EUROPE_1950_NORWAY:
        case SRM_RTCOD_EUROPE_1950_PORTUGAL_SPAIN:
        case SRM_RTCOD_EUROPE_1950_SARDINIA:
        case SRM_RTCOD_EUROPE_1950_SICILY:
        case SRM_RTCOD_EUROPE_1950_TUNISIA:
        case SRM_RTCOD_EUROPE_1950_W_EUROPE_MEAN_SOLUTION:
             if (orm_code != SRM_ORMCOD_EUROPE_1950)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_EUROPE_1979_MEAN_SOLUTION:
             if (orm_code != SRM_ORMCOD_EUROPE_1979)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_FAHUD_1987_3_OMAN:
        case SRM_RTCOD_FAHUD_1987_7_OMAN:
             if (orm_code != SRM_ORMCOD_FAHUD_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS:
             if (orm_code != SRM_ORMCOD_FORT_THOMAS_1955)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GALATEA_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_GALATEA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GAN_1970_MALDIVES:
             if (orm_code != SRM_ORMCOD_GAN_1970)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GANYMEDE_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_GANYMEDE_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GASPRA_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_GASPRA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GDA_1994_IDENTITY_BY_MEASUREMENT:
             if (orm_code != SRM_ORMCOD_GDA_1994)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEODETIC_DATUM_1949_3_NEW_ZEALAND:
        case SRM_RTCOD_GEODETIC_DATUM_1949_7_NEW_ZEALAND:
             if (orm_code != SRM_ORMCOD_GEODETIC_DATUM_1949)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1945_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1945)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1950_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1950)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1955_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1955)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1960_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1960)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1965_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1965)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1970_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1970)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1975_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1975)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1980_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1980)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1985_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1985)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1990_DGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1990)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_1995_IGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_1995)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GEOMAGNETIC_2000_IGRF:
             if (orm_code != SRM_ORMCOD_GEOMAGNETIC_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES:
             if (orm_code != SRM_ORMCOD_GRACIOSA_BASE_SW_1948)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GUAM_1963_GUAM:
             if (orm_code != SRM_ORMCOD_GUAM_1963)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND:
             if (orm_code != SRM_ORMCOD_GUNONG_SEGARA_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_GUX_1_1987_GUADALCANAL_ISLAND:
             if (orm_code != SRM_ORMCOD_GUX_1_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_HELENE_1992_IDENTITY:
             if (orm_code != SRM_ORMCOD_HELENE_1992)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_HERAT_NORTH_1987_AFGHANISTAN:
             if (orm_code != SRM_ORMCOD_HERAT_NORTH_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_HERMANNSKOGEL_1871_3_YUGOSLAVIA:
             if (orm_code != SRM_ORMCOD_HERMANNSKOGEL_1871)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_HJORSEY_1955_ICELAND:
             if (orm_code != SRM_ORMCOD_HJORSEY_1955)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_HONG_KONG_1963_HONG_KONG:
             if (orm_code != SRM_ORMCOD_HONG_KONG_1963)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_HU_TZU_SHAN_1991_TAIWAN:
             if (orm_code != SRM_ORMCOD_HU_TZU_SHAN_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_IAPETUS_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_IAPETUS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_IDA_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_IDA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_INDIAN_1916_3_BANGLADESH:
        case SRM_RTCOD_INDIAN_1916_7_BANGLADESH:
             if (orm_code != SRM_ORMCOD_INDIAN_1916)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_INDIAN_1954_THAILAND:
             if (orm_code != SRM_ORMCOD_INDIAN_1954)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_INDIAN_1956_INDIA_NEPAL:
             if (orm_code != SRM_ORMCOD_INDIAN_1956)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_INDIAN_1960_CON_SON_ISLAND:
        case SRM_RTCOD_INDIAN_1960_VIETNAM_16_N:
             if (orm_code != SRM_ORMCOD_INDIAN_1960)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_INDIAN_1962_PAKISTAN:
             if (orm_code != SRM_ORMCOD_INDIAN_1962)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_INDIAN_1975_1991_THAILAND:
        case SRM_RTCOD_INDIAN_1975_1997_THAILAND:
             if (orm_code != SRM_ORMCOD_INDIAN_1975)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_INDONESIAN_1974_INDONESIA:
             if (orm_code != SRM_ORMCOD_INDONESIAN_1974)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_IO_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_IO_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_IRELAND_1965_3_IRELAND:
        case SRM_RTCOD_IRELAND_1965_7_IRELAND:
             if (orm_code != SRM_ORMCOD_IRELAND_1965)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ISTS_061_1968_SOUTH_GEORGIA_ISLAND:
             if (orm_code != SRM_ORMCOD_ISTS_061_1968)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ISTS_073_1969_DIEGO_GARCIA:
             if (orm_code != SRM_ORMCOD_ISTS_073_1969)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_JANUS_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_JANUS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_JGD_2000_IDENTITY_BY_MEASUREMENT:
             if (orm_code != SRM_ORMCOD_JGD_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_JOHNSTON_1961_JOHNSTON_ISLAND:
             if (orm_code != SRM_ORMCOD_JOHNSTON_1961)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_JULIET_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_JULIET_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_JUPITER_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_JUPITER_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_JUPITER_MAGNETIC_1993_VOYAGER:
             if (orm_code != SRM_ORMCOD_JUPITER_MAGNETIC_1993)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_KANDAWALA_1987_3_SRI_LANKA:
             if (orm_code != SRM_ORMCOD_KANDAWALA_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_KERGUELEN_1949_KERGUELEN_ISLAND:
             if (orm_code != SRM_ORMCOD_KERGUELEN_1949)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_KERTAU_1948_3_W_MALAYSIA_SINGAPORE:
             if (orm_code != SRM_ORMCOD_KERTAU_1948)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_KOREAN_GEODETIC_1995_SOUTH_KOREA:
             if (orm_code != SRM_ORMCOD_KOREAN_GEODETIC_1995)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_KUSAIE_1951_CAROLINE_ISLANDS:
             if (orm_code != SRM_ORMCOD_KUSAIE_1951)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_LARISSA_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_LARISSA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_LC5_1961_CAYMAN_BRAC_ISLAND:
             if (orm_code != SRM_ORMCOD_LC5_1961)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_LEIGON_1991_3_GHANA:
        case SRM_RTCOD_LEIGON_1991_7_GHANA:
             if (orm_code != SRM_ORMCOD_LEIGON_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_LIBERIA_1964_LIBERIA:
             if (orm_code != SRM_ORMCOD_LIBERIA_1964)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_LUZON_1987_MINDANAO_ISLAND:
        case SRM_RTCOD_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND:
             if (orm_code != SRM_ORMCOD_LUZON_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_M_PORALOKO_1991_GABON:
             if (orm_code != SRM_ORMCOD_M_PORALOKO_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MAHE_1971_MAHE_ISLAND:
             if (orm_code != SRM_ORMCOD_MAHE_1971)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MARCUS_STATION_1952_MARCUS_ISLANDS:
             if (orm_code != SRM_ORMCOD_MARCUS_STATION_1952)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MARS_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_MARS_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MARS_SPHERE_2000_GLOBAL:
             if (orm_code != SRM_ORMCOD_MARS_SPHERE_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MASS_1999_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_MASS_1999)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MASSAWA_1987_ERITREA_ETHIOPIA:
             if (orm_code != SRM_ORMCOD_MASSAWA_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MERCHICH_1987_MOROCCO:
             if (orm_code != SRM_ORMCOD_MERCHICH_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MERCURY_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_MERCURY_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_METIS_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_METIS_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MIDWAY_1961_MIDWAY_ISLANDS:
             if (orm_code != SRM_ORMCOD_MIDWAY_1961)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MIMAS_1994_IDENTITY:
             if (orm_code != SRM_ORMCOD_MIMAS_1994)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MINNA_1991_CAMEROON:
        case SRM_RTCOD_MINNA_1991_NIGERIA:
             if (orm_code != SRM_ORMCOD_MINNA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MIRANDA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_MIRANDA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MM5_1997_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_MM5_1997)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MODTRAN_MIDLATITUDE_N_1989_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MODTRAN_MIDLATITUDE_S_1989_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MODTRAN_SUBARCTIC_N_1989_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MODTRAN_SUBARCTIC_S_1989_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_MODTRAN_TROPICAL_1989)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS:
             if (orm_code != SRM_ORMCOD_MONTSERRAT_1958)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MOON_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_MOON_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_MULTIGEN_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS:
        case SRM_RTCOD_N_AM_1927_ALBERTA_BRITISH_COLUMBIA:
        case SRM_RTCOD_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND:
        case SRM_RTCOD_N_AM_1927_CANADA:
        case SRM_RTCOD_N_AM_1927_CANAL_ZONE:
        case SRM_RTCOD_N_AM_1927_CARIBBEAN:
        case SRM_RTCOD_N_AM_1927_CENTRAL_AMERICA:
        case SRM_RTCOD_N_AM_1927_CONTINENTAL_US:
        case SRM_RTCOD_N_AM_1927_CUBA:
        case SRM_RTCOD_N_AM_1927_EAST_ALEUTIAN_ISLANDS:
        case SRM_RTCOD_N_AM_1927_EASTERN_CANADA:
        case SRM_RTCOD_N_AM_1927_EASTERN_US:
        case SRM_RTCOD_N_AM_1927_HAYES_PENINSULA:
        case SRM_RTCOD_N_AM_1927_MANITOBA_ONTARIO:
        case SRM_RTCOD_N_AM_1927_MEXICO:
        case SRM_RTCOD_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN:
        case SRM_RTCOD_N_AM_1927_SAN_SALVADOR_ISLAND:
        case SRM_RTCOD_N_AM_1927_WEST_ALEUTIAN_ISLANDS:
        case SRM_RTCOD_N_AM_1927_WESTERN_US:
        case SRM_RTCOD_N_AM_1927_YUKON:
             if (orm_code != SRM_ORMCOD_N_AM_1927)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS:
        case SRM_RTCOD_N_AM_1983_ALEUTIAN_ISLANDS:
        case SRM_RTCOD_N_AM_1983_CANADA:
        case SRM_RTCOD_N_AM_1983_CONTINENTAL_US:
        case SRM_RTCOD_N_AM_1983_HAWAII:
        case SRM_RTCOD_N_AM_1983_MEXICO_CENTRAL_AMERICA:
             if (orm_code != SRM_ORMCOD_N_AM_1983)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_N_SAHARA_1959_ALGERIA:
             if (orm_code != SRM_ORMCOD_N_SAHARA_1959)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_NAHRWAN_1987_MASIRAH_ISLAND:
        case SRM_RTCOD_NAHRWAN_1987_SAUDI_ARABIA:
        case SRM_RTCOD_NAHRWAN_1987_UNITED_ARAB_EMIRATES:
             if (orm_code != SRM_ORMCOD_NAHRWAN_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_NAIAD_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_NAIAD_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_NAPARIMA_1991_TRINIDAD_TOBAGO:
             if (orm_code != SRM_ORMCOD_NAPARIMA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_NEPTUNE_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_NEPTUNE_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_NEPTUNE_MAGNETIC_1993_VOYAGER:
             if (orm_code != SRM_ORMCOD_NEPTUNE_MAGNETIC_1993)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_NOGAPS_1988_IDENTITY_BY_DEFAULT:
             if (orm_code != SRM_ORMCOD_NOGAPS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_NTF_1896_FRANCE:
             if (orm_code != SRM_ORMCOD_NTF_1896)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_NTF_1896_PM_PARIS_FRANCE:
             if (orm_code != SRM_ORMCOD_NTF_1896_PM_PARIS)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_OBERON_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_OBERON_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS:
             if (orm_code != SRM_ORMCOD_OBSERV_METEORO_1939)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_OLD_EGYPTIAN_1907_EGYPT:
             if (orm_code != SRM_ORMCOD_OLD_EGYPTIAN_1907)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_HAWAII:
        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_KAUAI:
        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MAUI:
        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MEAN_SOLUTION:
        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_OAHU:
             if (orm_code != SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_HAWAII:
        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_KAUAI:
        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MAUI:
        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MEAN_SOLUTION:
        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_OAHU:
             if (orm_code != SRM_ORMCOD_OLD_HAWAIIAN_INT_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_OPHELIA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_OPHELIA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_OSGB_1936_3_MEAN_SOLUTION:
        case SRM_RTCOD_OSGB_1936_7_GREAT_BRITAIN:
        case SRM_RTCOD_OSGB_1936_ENGLAND:
        case SRM_RTCOD_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES:
        case SRM_RTCOD_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS:
        case SRM_RTCOD_OSGB_1936_WALES:
             if (orm_code != SRM_ORMCOD_OSGB_1936)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PAN_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_PAN_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PANDORA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_PANDORA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PHOBOS_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_PHOBOS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PHOEBE_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_PHOEBE_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PICO_DE_LAS_NIEVES_1987_CANARY_ISLANDS:
             if (orm_code != SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PITCAIRN_1967_PITCAIRN_ISLAND:
             if (orm_code != SRM_ORMCOD_PITCAIRN_1967)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PLUTO_1994_IDENTITY:
             if (orm_code != SRM_ORMCOD_PLUTO_1994)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_POINT_58_1991_MEAN_SOLUTION:
             if (orm_code != SRM_ORMCOD_POINT_58_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_POINTE_NOIRE_1948_CONGO:
             if (orm_code != SRM_ORMCOD_POINTE_NOIRE_1948)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PORTIA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_PORTIA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS:
             if (orm_code != SRM_ORMCOD_PORTO_SANTO_1936)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PROMETHEUS_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_PROMETHEUS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PROTEUS_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_PROTEUS_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PROV_S_AM_1956_3_VENEZUELA:
        case SRM_RTCOD_PROV_S_AM_1956_7_VENEZUELA:
        case SRM_RTCOD_PROV_S_AM_1956_BOLIVIA:
        case SRM_RTCOD_PROV_S_AM_1956_COLOMBIA:
        case SRM_RTCOD_PROV_S_AM_1956_ECUADOR:
        case SRM_RTCOD_PROV_S_AM_1956_GUYANA:
        case SRM_RTCOD_PROV_S_AM_1956_MEAN_SOLUTION:
        case SRM_RTCOD_PROV_S_AM_1956_N_CHILE_19_S:
        case SRM_RTCOD_PROV_S_AM_1956_PERU:
        case SRM_RTCOD_PROV_S_AM_1956_S_CHILE_43_S:
             if (orm_code != SRM_ORMCOD_PROV_S_AM_1956)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PROV_S_CHILEAN_1963_SOUTH_CHILE:
             if (orm_code != SRM_ORMCOD_PROV_S_CHILEAN_1963)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PUCK_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_PUCK_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS:
             if (orm_code != SRM_ORMCOD_PUERTO_RICO_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_PULKOVO_1942_RUSSIA:
             if (orm_code != SRM_ORMCOD_PULKOVO_1942)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_QATAR_NATIONAL_1974_3_QATAR:
             if (orm_code != SRM_ORMCOD_QATAR_NATIONAL_1974)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_QORNOQ_1987_SOUTH_GREENLAND:
             if (orm_code != SRM_ORMCOD_QORNOQ_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_REUNION_1947_MASCARENE_ISLANDS:
             if (orm_code != SRM_ORMCOD_REUNION_1947)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_RGF_1993_IDENTITY_BY_MEASUREMENT:
             if (orm_code != SRM_ORMCOD_RGF_1993)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_RHEA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_RHEA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ROME_1940_PM_ROME_SARDINIA:
             if (orm_code != SRM_ORMCOD_ROME_1940_PM_ROME)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ROME_1940_SARDINIA:
             if (orm_code != SRM_ORMCOD_ROME_1940)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ROSALIND_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_ROSALIND_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_S_AM_1969_ARGENTINA:
        case SRM_RTCOD_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS:
        case SRM_RTCOD_S_AM_1969_BOLIVIA:
        case SRM_RTCOD_S_AM_1969_BRAZIL:
        case SRM_RTCOD_S_AM_1969_CHILE:
        case SRM_RTCOD_S_AM_1969_COLOMBIA:
        case SRM_RTCOD_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS:
        case SRM_RTCOD_S_AM_1969_GUYANA:
        case SRM_RTCOD_S_AM_1969_MEAN_SOLUTION:
        case SRM_RTCOD_S_AM_1969_PARAGUAY:
        case SRM_RTCOD_S_AM_1969_PERU:
        case SRM_RTCOD_S_AM_1969_TRINIDAD_TOBAGO:
        case SRM_RTCOD_S_AM_1969_VENEZUELA:
             if (orm_code != SRM_ORMCOD_S_AM_1969)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_S_ASIA_1987_SINGAPORE:
             if (orm_code != SRM_ORMCOD_S_ASIA_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_S_JTSK_1993_CZECH_REP:
        case SRM_RTCOD_S_JTSK_1993_CZECH_REP_SLOVAKIA:
             if (orm_code != SRM_ORMCOD_S_JTSK_1993)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_S42_PULKOVO_3_POLAND:
        case SRM_RTCOD_S42_PULKOVO_ALBANIA:
        case SRM_RTCOD_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA:
        case SRM_RTCOD_S42_PULKOVO_G_ROMANIA:
        case SRM_RTCOD_S42_PULKOVO_HUNGARY:
        case SRM_RTCOD_S42_PULKOVO_KAZAKHSTAN:
        case SRM_RTCOD_S42_PULKOVO_LATVIA:
             if (orm_code != SRM_ORMCOD_S42_PULKOVO)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND:
             if (orm_code != SRM_ORMCOD_SANTO_DOS_1965)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS:
             if (orm_code != SRM_ORMCOD_SAO_BRAZ_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS:
             if (orm_code != SRM_ORMCOD_SAPPER_HILL_1943)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SATURN_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_SATURN_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SATURN_MAGNETIC_1993_VOYAGER:
             if (orm_code != SRM_ORMCOD_SATURN_MAGNETIC_1993)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SCHWARZECK_1991_NAMIBIA:
             if (orm_code != SRM_ORMCOD_SCHWARZECK_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS:
             if (orm_code != SRM_ORMCOD_SELVAGEM_GRANDE_1938)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SIERRA_LEONE_1960_SIERRA_LEONE:
             if (orm_code != SRM_ORMCOD_SIERRA_LEONE_1960)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SIRGAS_2000_IDENTITY_BY_MEASUREMENT:
             if (orm_code != SRM_ORMCOD_SIRGAS_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_SUN_1992_IDENTITY:
             if (orm_code != SRM_ORMCOD_SUN_1992)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TANANARIVE_OBS_1925_3_MADAGASCAR:
             if (orm_code != SRM_ORMCOD_TANANARIVE_OBS_1925)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TANANARIVE_OBS_1925_PM_PARIS_3_MADAGASCAR:
             if (orm_code != SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TELESTO_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_TELESTO_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TERN_1961_TERN_ISLAND:
             if (orm_code != SRM_ORMCOD_TERN_1961)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TETHYS_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_TETHYS_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_THALASSA_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_THALASSA_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_THEBE_2000_IDENTITY:
             if (orm_code != SRM_ORMCOD_THEBE_2000)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TIMBALAI_EVEREST_1948_3_BRUNEI_E_MALAYSIA:
        case SRM_RTCOD_TIMBALAI_EVEREST_1948_7_BRUNEI_E_MALAYSIA:
             if (orm_code != SRM_ORMCOD_TIMBALAI_EVEREST_1948)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TITAN_1982_IDENTITY:
             if (orm_code != SRM_ORMCOD_TITAN_1982)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TITANIA_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_TITANIA_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TOKYO_1991_JAPAN:
        case SRM_RTCOD_TOKYO_1991_MEAN_SOLUTION:
        case SRM_RTCOD_TOKYO_1991_OKINAWA:
        case SRM_RTCOD_TOKYO_1991_1991_SOUTH_KOREA:
        case SRM_RTCOD_TOKYO_1991_1997_SOUTH_KOREA:
             if (orm_code != SRM_ORMCOD_TOKYO_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TRISTAN_1968_TRISTAN_DA_CUNHA:
             if (orm_code != SRM_ORMCOD_TRISTAN_1968)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_TRITON_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_TRITON_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_UMBRIEL_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_UMBRIEL_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_URANUS_1988_IDENTITY:
             if (orm_code != SRM_ORMCOD_URANUS_1988)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_URANUS_MAGNETIC_1993_VOYAGER:
             if (orm_code != SRM_ORMCOD_URANUS_MAGNETIC_1993)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_VENUS_1991_IDENTITY:
             if (orm_code != SRM_ORMCOD_VENUS_1991)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_VITI_LEVU_1916_VITI_LEVU_ISLANDS:
             if (orm_code != SRM_ORMCOD_VITI_LEVU_1916)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_VOIROL_1874_ALGERIA:
             if (orm_code != SRM_ORMCOD_VOIROL_1874)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_VOIROL_1874_PM_PARIS_ALGERIA:
             if (orm_code != SRM_ORMCOD_VOIROL_1874_PM_PARIS)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_VOIROL_1960_ALGERIA:
             if (orm_code != SRM_ORMCOD_VOIROL_1960)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_VOIROL_1960_PM_PARIS_ALGERIA:
             if (orm_code != SRM_ORMCOD_VOIROL_1960_PM_PARIS)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_WAKE_1952_WAKE_ATOLL:
             if (orm_code != SRM_ORMCOD_WAKE_1952)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS:
             if (orm_code != SRM_ORMCOD_WAKE_ENIWETOK_1960)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_WGS_1972_GLOBAL:
             if (orm_code != SRM_ORMCOD_WGS_1972)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_WGS_1984_IDENTITY:
             if (orm_code != SRM_ORMCOD_WGS_1984)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_YACARE_1987_URUGUAY:
             if (orm_code != SRM_ORMCOD_YACARE_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        case SRM_RTCOD_ZANDERIJ_1987_SURINAME:
             if (orm_code != SRM_ORMCOD_ZANDERIJ_1987)
             {
                 result = SRM_FALSE;
             }
             break;

        default:
             result = SRM_FALSE;
             break;
    } /* end switch */
    return result;
} /* end SRM_ValidRTCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSpatialCoordinateCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSpatialCoordinateCode
(
    SRM_Spatial_Coordinate_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SPACOORDCOD_CC_3D:
        case SRM_SPACOORDCOD_CD_3D:
        case SRM_SPACOORDCOD_CD_SURFACE:
        case SRM_SPACOORDCOD_CM_3D:
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
        case SRM_SPACOORDCOD_EC_SURFACE:
        case SRM_SPACOORDCOD_EI_3D:
        case SRM_SPACOORDCOD_HAEC_3D:
        case SRM_SPACOORDCOD_HEEC_3D:
        case SRM_SPACOORDCOD_HEEQ_3D:
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
        case SRM_SPACOORDCOD_LCC_SURFACE:
        case SRM_SPACOORDCOD_LSA_2D:
        case SRM_SPACOORDCOD_LSP_2D:
        case SRM_SPACOORDCOD_LSR_2D:
        case SRM_SPACOORDCOD_LSR_3D:
        case SRM_SPACOORDCOD_LCE_3D:
        case SRM_SPACOORDCOD_LTSAS_3D:
        case SRM_SPACOORDCOD_LTSAS_SURFACE:
        case SRM_SPACOORDCOD_LTSC_3D:
        case SRM_SPACOORDCOD_LTSC_SURFACE:
        case SRM_SPACOORDCOD_LTSE_3D:
        case SRM_SPACOORDCOD_LTSE_SURFACE:
        case SRM_SPACOORDCOD_M_AUGMENTED_3D:
        case SRM_SPACOORDCOD_M_SURFACE:
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
        case SRM_SPACOORDCOD_OMS_SURFACE:
        case SRM_SPACOORDCOD_PD_3D:
        case SRM_SPACOORDCOD_PD_SURFACE:
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
        case SRM_SPACOORDCOD_PS_SURFACE:
        case SRM_SPACOORDCOD_SEC_3D:
        case SRM_SPACOORDCOD_SEQ_3D:
        case SRM_SPACOORDCOD_SMD_3D:
        case SRM_SPACOORDCOD_SME_3D:
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
        case SRM_SPACOORDCOD_TM_SURFACE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSpatialCoordinateCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSpherical3DCoordinate */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSpherical3DCoordinate
(
    const SRM_Spherical_3D_Coordinate *value_ptr,
          SRM_Boolean                  print_error,
          SRM_Integer_Unsigned        *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidSpherical3DCoordinate: NULL value_ptr\n");
        }
        return result;
    }

    if (value_ptr->radius <= -CLOSE_DELTA)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidSpherical3DCoordinate: radius"\
                    " <= 0.0!\n");
    }
    return result;
} /* end SRM_ValidSpherical3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFCode
(
    SRM_SRF_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFCOD_UNSPECIFIED:
        case SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY:
        case SRM_SRFCOD_BRITISH_OSGRS80_GRID:
        case SRM_SRFCOD_DELAWARE_SPCS_1983:
        case SRM_SRFCOD_GEOCENTRIC_WGS_1984:
        case SRM_SRFCOD_GEODETIC_AUSTRALIA_1984:
        case SRM_SRFCOD_GEODETIC_WGS_1984:
        case SRM_SRFCOD_GEODETIC_N_AMERICAN_1983:
        case SRM_SRFCOD_IRISH_GRID_1965:
        case SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989:
        case SRM_SRFCOD_LAMBERT_93:
        case SRM_SRFCOD_LAMBERT_II_WIDE:
        case SRM_SRFCOD_MARS_PLANETOCENTRIC_2000:
        case SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000:
        case SRM_SRFCOD_MARYLAND_SPCS_1983:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFParametersInfo */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFParametersInfo
(
    const SRM_SRF_Parameters_Info *value_ptr,
          SRM_Boolean              print_error,
          SRM_Integer_Unsigned    *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidSRFParametersInfo: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->srf_params_info_code)
    {
        case SRM_SRFPARAMINFCOD_TEMPLATE:
            if (!SRM_ValidSRFTParameters(&(value_ptr->value.srf_template),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_SRFT_Parameters value\n");
                }
            }
            if ((result == SRM_TRUE) &&
                !SRM_ValidRTCode(value_ptr->value.srf_template.orm_code,
                value_ptr->rt_code))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "rt_code not valid for orm_code!\n");
                }
            }
            break;

        case SRM_SRFPARAMINFCOD_SET:
            if (!SRM_ValidSRFSInfo(&(value_ptr->value.srf_set), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_SRFS_Info value\n");
                }
            }
            if ((result == SRM_TRUE) &&
                !SRM_ValidRTCode(value_ptr->value.srf_set.orm_code,
                value_ptr->rt_code))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "rt_code not valid for orm_code!\n");
                }
            }
            break;

        case SRM_SRFPARAMINFCOD_INSTANCE:
            if (!SRM_ValidSRFCode(value_ptr->value.srf_instance))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SRM_SRF_Code value (%d)\n", (int)
                        value_ptr->value.srf_instance);
            }
            else if ( !SRM_ValidRTCode( SRM_GetORMCodeForSRFCode(
                        value_ptr->value.srf_instance), value_ptr->rt_code))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Error in SRM_ValidSRFParametersInfo:"\
                            " illegal rt_code for srf_instance's implicit"\
                            " orm_code (%s)\n", SRM_PrintORMCode
                        (SRM_GetORMCodeForSRFCode(value_ptr->value.srf_instance)));
            }
            break;

        default:
             result = SRM_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SRM_SRF_Parameters_Info_Code value"\
                         " (%d)\n", (int) value_ptr->srf_params_info_code);
             break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFParametersInfo */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFParametersInfoCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFParametersInfoCode
(
    SRM_SRF_Parameters_Info_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFPARAMINFCOD_TEMPLATE:
        case SRM_SRFPARAMINFCOD_SET:
        case SRM_SRFPARAMINFCOD_INSTANCE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFParametersInfoCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFReferenceSurfaceInfo */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFReferenceSurfaceInfo
(
    const SRM_SRF_Reference_Surface_Info *value_ptr,
          SRM_Boolean                     print_error,
          SRM_Integer_Unsigned           *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidSRFReferenceSurfaceInfo: NULL value_ptr\n");
        }
        return result;
    }

    if (!SRM_ValidDSSCode(value_ptr->dss_code))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SRM_DSS_Code value (%d)\n", (int)
                value_ptr->dss_code);
    }
    if (!SRM_ValidSRFParametersInfo(&(value_ptr->srf_parameters_info),
              print_error, error_count_ptr))
    {
        result = SRM_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SRM_SRF_Parameters_Info value\n");
        }
    }
    return result;
} /* end SRM_ValidSRFReferenceSurfaceInfo */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSCode
(
    SRM_SRFS_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFSCOD_UNSPECIFIED:
        case SRM_SRFSCOD_ALABAMA_SPCS:
        case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM:
        case SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS:
        case SRM_SRFSCOD_LAMBERT_NTF:
        case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC:
        case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR:
        case SRM_SRFSCOD_WISCONSIN_SPCS:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSCodeInfo */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSCodeInfo
(
    const SRM_SRFS_Code_Info *value_ptr,
          SRM_Boolean         print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidSRFSCodeInfo: NULL value_ptr\n");
        }
        return result;
    }

    switch (value_ptr->srfs_code)
    {
        case SRM_SRFSCOD_UNSPECIFIED:
            break;

        case SRM_SRFSCOD_ALABAMA_SPCS:
            if (!SRM_ValidSRFSMAlabamaSPCSCode
               (value_ptr->value.srfsm_alabama_spcs))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SRM_SRFSM_Alabama_SPCS_Code"\
                            " value (%d)\n", (int)
                        value_ptr->value.srfsm_alabama_spcs);
            }
            break;

        case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM:
            break;

        case SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS:
            if (!SRM_ValidSRFSMJapanRectangularPlaneCSCode
               (value_ptr->value.srfsm_japan_rectangular_plane_cs))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal"\
                            " SRM_SRFSM_Japan_Rectangular_Plane_CS_Code"\
                            " value (%d)\n", (int)
                        value_ptr->value.srfsm_japan_rectangular_plane_cs);
            }
            break;

        case SRM_SRFSCOD_LAMBERT_NTF:
            if (!SRM_ValidSRFSMLambertNTFCode
               (value_ptr->value.srfsm_lambert_ntf))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SRM_SRFSM_Lambert_NTF_Code value"\
                            " (%d)\n", (int)
                        value_ptr->value.srfsm_lambert_ntf);
            }
            break;

        case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC:
            if (!SRM_ValidSRFSMUPSCode(value_ptr->value.srfsm_ups))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SRM_SRFSM_UPS_Code value (%d)\n",
                        (int) value_ptr->value.srfsm_ups);
            }
            break;

        case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR:
            if (!SRM_ValidSRFSMUTMCode(value_ptr->value.srfsm_utm))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SRM_SRFSM_UTM_Code value (%d)\n",
                        (int) value_ptr->value.srfsm_utm);
            }
            break;

        case SRM_SRFSCOD_WISCONSIN_SPCS:
            if (!SRM_ValidSRFSMWisconsinSPCSCode
               (value_ptr->value.srfsm_wisconsin_spcs))
            {
                result = SRM_FALSE;
                if (error_count_ptr)
                    (*error_count_ptr)++;
                if (print_error)
                    fprintf(f_ptr, "Illegal SRM_SRFSM_Wisconsin_SPCS_Code"\
                            " value (%d)\n", (int)
                        value_ptr->value.srfsm_wisconsin_spcs);
            }
            break;

        default:
             result = SRM_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SRM_SRFS_Code value (%d)\n", (int)
                         value_ptr->srfs_code);
             break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFSCodeInfo */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSInfo */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSInfo
(
    const SRM_SRFS_Info *value_ptr,
          SRM_Boolean    print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidSRFSInfo: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->orm_code == SRM_ORMCOD_UNSPECIFIED) ||
       !SRM_ValidORMCode(value_ptr->orm_code))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SRM_ORM_Code value (%d)\n", (int)
                value_ptr->orm_code);
    }
    if (!SRM_ValidSRFSCodeInfo(&(value_ptr->srfs_code_info), print_error,
              error_count_ptr))
    {
        result = SRM_FALSE;
        if (print_error)
        {
            fprintf(f_ptr, "Illegal SRM_SRFS_Code_Info value\n");
        }
    }
    return result;
} /* end SRM_ValidSRFSInfo */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSMAlabamaSPCSCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSMAlabamaSPCSCode
(
    SRM_SRFSM_Alabama_SPCS_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFSMALCOD_WEST_ZONE:
        case SRM_SRFSMALCOD_EAST_ZONE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFSMAlabamaSPCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSMJapanRectangularPlaneCSCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSMJapanRectangularPlaneCSCode
(
    SRM_SRFSM_Japan_Rectangular_Plane_CS_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFSMJPRPCSCOD_ZONE_I:
        case SRM_SRFSMJPRPCSCOD_ZONE_II:
        case SRM_SRFSMJPRPCSCOD_ZONE_III:
        case SRM_SRFSMJPRPCSCOD_ZONE_IV:
        case SRM_SRFSMJPRPCSCOD_ZONE_V:
        case SRM_SRFSMJPRPCSCOD_ZONE_VI:
        case SRM_SRFSMJPRPCSCOD_ZONE_VII:
        case SRM_SRFSMJPRPCSCOD_ZONE_VIII:
        case SRM_SRFSMJPRPCSCOD_ZONE_IX:
        case SRM_SRFSMJPRPCSCOD_ZONE_X:
        case SRM_SRFSMJPRPCSCOD_ZONE_XI:
        case SRM_SRFSMJPRPCSCOD_ZONE_XII:
        case SRM_SRFSMJPRPCSCOD_ZONE_XIII:
        case SRM_SRFSMJPRPCSCOD_ZONE_XIV:
        case SRM_SRFSMJPRPCSCOD_ZONE_XV:
        case SRM_SRFSMJPRPCSCOD_ZONE_XVI:
        case SRM_SRFSMJPRPCSCOD_ZONE_XVII:
        case SRM_SRFSMJPRPCSCOD_ZONE_XVIII:
        case SRM_SRFSMJPRPCSCOD_ZONE_XIX:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFSMJapanRectangularPlaneCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSMLambertNTFCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSMLambertNTFCode
(
    SRM_SRFSM_Lambert_NTF_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFSMLAMNTFCOD_ZONE_I:
        case SRM_SRFSMLAMNTFCOD_ZONE_II:
        case SRM_SRFSMLAMNTFCOD_ZONE_III:
        case SRM_SRFSMLAMNTFCOD_ZONE_IV:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFSMLambertNTFCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSMUPSCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSMUPSCode
(
    SRM_SRFSM_UPS_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFSMUPSCOD_NORTHERN_POLE:
        case SRM_SRFSMUPSCOD_SOUTHERN_POLE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFSMUPSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSMUTMCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSMUTMCode
(
    SRM_SRFSM_UTM_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFSMUTMCOD_ZONE_1_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_2_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_3_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_4_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_5_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_6_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_7_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_8_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_9_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_11_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_13_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_14_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_15_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_16_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_17_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_18_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_19_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_20_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_21_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_22_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_23_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_24_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_25_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_26_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_27_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_28_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_29_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_30_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_31_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_32_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_33_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_34_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_35_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_36_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_37_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_38_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_39_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_40_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_41_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_42_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_43_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_44_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_45_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_46_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_47_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_48_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_49_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_50_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_51_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_52_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_53_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_54_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_55_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_56_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_57_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_58_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_59_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_60_NORTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_1_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_2_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_3_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_4_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_5_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_6_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_7_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_8_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_9_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_10_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_11_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_12_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_13_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_14_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_15_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_16_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_17_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_18_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_19_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_20_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_21_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_22_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_23_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_24_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_25_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_26_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_27_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_28_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_29_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_30_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_31_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_32_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_33_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_34_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_35_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_36_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_37_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_38_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_39_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_40_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_41_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_42_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_43_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_44_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_45_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_46_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_47_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_48_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_49_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_50_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_51_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_52_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_53_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_54_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_55_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_56_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_57_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_58_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_59_SOUTHERN_HEMISPHERE:
        case SRM_SRFSMUTMCOD_ZONE_60_SOUTHERN_HEMISPHERE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFSMUTMCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFSMWisconsinSPCSCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFSMWisconsinSPCSCode
(
    SRM_SRFSM_Wisconsin_SPCS_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFSMWNSPCSCOD_SOUTH_ZONE:
        case SRM_SRFSMWNSPCSCOD_CENTRAL_ZONE:
        case SRM_SRFSMWNSPCSCOD_NORTH_ZONE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFSMWisconsinSPCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFTCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFTCode
(
    SRM_SRFT_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
        case SRM_SRFTCOD_CELESTIODETIC:
        case SRM_SRFTCOD_PLANETODETIC:
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
        case SRM_SRFTCOD_CELESTIOMAGNETIC:
        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
        case SRM_SRFTCOD_MERCATOR:
        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFTCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidSRFTParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidSRFTParameters
(
    const SRM_SRFT_Parameters *value_ptr,
          SRM_Boolean          print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidSRFTParameters: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->orm_code == SRM_ORMCOD_UNSPECIFIED) ||
       !SRM_ValidORMCode(value_ptr->orm_code))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Illegal SRM_ORM_Code value (%d)\n", (int)
                value_ptr->orm_code);
    }
    switch (value_ptr->template_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            if (!SRM_ValidLSR3DParameters(
                      &(value_ptr->parameters.lsr_3d_srf_parameters),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_LSR_3D_Parameters value\n");
                }
            }
            if (value_ptr->orm_code != SRM_ORMCOD_ABSTRACT_3D)
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "orm_code != SRM_ORMCOD_ABSTRACT_3D for"\
                           " SRM_LSR_3D_Parameters\n");
                }
            }
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            if (!SRM_ValidLTSEParameters(
                      &(value_ptr->parameters.ltse_srf_parameters),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_LTSE_Parameters value\n");
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            if (!SRM_ValidLocalTangentParameters(
                      &(value_ptr->parameters.ltsas_srf_parameters),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Local_Tangent_Parameters"\
                           " value\n");
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            if (!SRM_ValidLocalTangentParameters(
                      &(value_ptr->parameters.ltsc_srf_parameters),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Local_Tangent_Parameters"\
                           " value\n");
                }
            }
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            break;

        case SRM_SRFTCOD_MERCATOR:
            if (!SRM_ValidMParameters(
                      &(value_ptr->parameters.m_srf_parameters), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_M_Parameters value\n");
                }
            }
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            if (!SRM_ValidObliqueMercatorParameters(
                      &(value_ptr->parameters.oms_srf_parameters),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_Oblique_Mercator_Parameters"\
                           " value\n");
                }
            }
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            if (!SRM_ValidTMParameters(
                      &(value_ptr->parameters.tm_srf_parameters), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_TM_Parameters value\n");
                }
            }
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            if (!SRM_ValidPSParameters(
                      &(value_ptr->parameters.ps_srf_parameters), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_PS_Parameters value\n");
                }
            }
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            if (!SRM_ValidECParameters(
                      &(value_ptr->parameters.ec_srf_parameters), print_error,
                      error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_EC_Parameters value\n");
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
            if (!SRM_ValidLSR2DParameters(
                      &(value_ptr->parameters.lsr_2d_srf_parameters),
                      print_error, error_count_ptr))
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "Illegal SRM_LSR_2D_Parameters value\n");
                }
            }
            if (value_ptr->orm_code != SRM_ORMCOD_ABSTRACT_2D)
            {
                result = SRM_FALSE;
                if (print_error)
                {
                    fprintf(f_ptr, "orm_code != SRM_ORMCOD_ABSTRACT_2D for"\
                           " SRM_LSR_2D_Parameters\n");
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
            break;

        default:
             result = SRM_FALSE;
             if (error_count_ptr)
                 (*error_count_ptr)++;
             if (print_error)
                 fprintf(f_ptr, "Illegal SRM_SRFT_Code value (%d)\n", (int)
                         value_ptr->template_code);
             break;
    } /* end switch */
    return result;
} /* end SRM_ValidSRFTParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidStatusCode */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidStatusCode
(
    SRM_Status_Code value
)
{
    SRM_Boolean result = SRM_TRUE;

    switch (value)
    {
        case SRM_STATCOD_SUCCESS:
        case SRM_STATCOD_INVALID_SRF:
        case SRM_STATCOD_INVALID_SOURCE_SRF:
        case SRM_STATCOD_INVALID_SOURCE_COORDINATE:
        case SRM_STATCOD_INVALID_TARGET_COORDINATE:
        case SRM_STATCOD_INVALID_POINT1_COORDINATE:
        case SRM_STATCOD_INVALID_POINT2_COORDINATE:
        case SRM_STATCOD_OPERATION_UNSUPPORTED:
        case SRM_STATCOD_INVALID_SOURCE_DIRECTION:
        case SRM_STATCOD_INVALID_TARGET_DIRECTION:
        case SRM_STATCOD_INVALID_CODE:
        case SRM_STATCOD_INVALID_INPUT:
        case SRM_STATCOD_CREATION_FAILURE:
        case SRM_STATCOD_DESTRUCTION_FAILURE:
        case SRM_STATCOD_FLOATING_OVERFLOW:
        case SRM_STATCOD_FLOATING_UNDERFLOW:
        case SRM_STATCOD_FLOATING_POINT_ERROR:
        case SRM_STATCOD_MEMORY_ALLOCATION_ERROR:
        case SRM_STATCOD_BUFFER_OVERFLOW:
        case SRM_STATCOD_ENUMERATION_VALUE_INVALID:
        case SRM_STATCOD_INVALID_SOURCE_ORIENTATION:
        case SRM_STATCOD_INVALID_TARGET_ORIENTATION:
        case SRM_STATCOD_NOT_IMPLEMENTED:
        case SRM_STATCOD_INACTIONABLE:
            break;

        default:
            result = SRM_FALSE;
            break;
    } /* end switch */
    return result;
} /* end SRM_ValidStatusCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_ValidTMParameters */

/* *-----------------------------------------------------------------------------*/
SRM_Boolean
SRM_ValidTMParameters
(
    const SRM_TM_Parameters *value_ptr,
          SRM_Boolean        print_error,
          SRM_Integer_Unsigned *error_count_ptr
)
{
    SRM_Boolean  result = SRM_TRUE;
    FILE        *f_ptr = NULL;

    if (print_error)
        f_ptr = SRM_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = SRM_FALSE;
        if (error_count_ptr)
        {
            (*error_count_ptr)++;
        }
        if (print_error)
        {
            fprintf(f_ptr, "SRM_ValidTMParameters: NULL value_ptr\n");
        }
        return result;
    }

    if ((value_ptr->central_scale < 0.75-CLOSE_DELTA) || (value_ptr->central_scale > 1.25+CLOSE_DELTA))
    {
        result = SRM_FALSE;
        if (error_count_ptr)
            (*error_count_ptr)++;
        if (print_error)
            fprintf(f_ptr, "Error in SRM_ValidTMParameters: central_scale"\
                    " out of range [0.75, 1.25]!\n");
    }
    return result;
} /* end SRM_ValidTMParameters */
