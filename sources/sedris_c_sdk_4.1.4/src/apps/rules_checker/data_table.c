/*
 * FILE       : data_table.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a transmittal, with
 *    regard to constraints affecting <Data Table> instances.
 *
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "control_link.h"
#include "data_table.h"
#include "image.h"
#include "metadata.h"
#include "prop_set_table.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: IsSpatialAxis
 *
 *  Check if we have an attribute code then it must be primary, secondary, or
 *  tertiary value of a linear or angular coordinate
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
IsSpatialAxis
(
    const SE_Axis_Fields *axis_fields
)
{
    SE_Boolean result = SE_FALSE;

    if ((axis_fields->axis_type == EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE) ||
        (axis_fields->axis_type == EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE) ||
        (axis_fields->axis_type == EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE) ||
        (axis_fields->axis_type == EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE) ||
        (axis_fields->axis_type == EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE))
    {
        result = SE_TRUE;
    }
    return result;
} /* end IsSpatialAxis */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SpatialAxisTypesForSRFTParameters
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
SpatialAxisTypesForSRFTParameters
(
    const SRM_SRFT_Parameters         *srf_template,
          SE_Boolean                  *is_3D,
          EDCS_Attribute_Code         *primary_axis_type,
          EDCS_Attribute_Code         *secondary_axis_type,
          EDCS_Attribute_Code         *tertiary_axis_type,
          SRM_Spatial_Coordinate_Code *coord_code
)
{
    SE_Return_Code ret_code = SE_RETCOD_SUCCESS;

    *is_3D = SE_FALSE;
    *primary_axis_type   = EAC_NULL;
    *secondary_axis_type = EAC_NULL;
    *tertiary_axis_type  = EAC_NULL;
    *coord_code          = (SRM_Spatial_Coordinate_Code)-1;

    switch (srf_template->template_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_CC_3D;
             break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LSR_3D;
             break;

        case SRM_SRFTCOD_CELESTIODETIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_CD_3D;
                                  /* also SRM_SPACOORDCOD_CD_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_PLANETODETIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_PD_3D;
                                  /* also SRM_SPACOORDCOD_PD_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LTSE_3D;
                                  /* also SRM_SPACOORDCOD_LTSE_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LTSAS_3D;
                                  /* also SRM_SPACOORDCOD_LTSAS_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LTSC_3D;
                                  /* also SRM_SPACOORDCOD_LTSC_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LCE_3D;
             break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_CM_3D;
             break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_EI_3D;
             break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_SEC_3D;
             break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_SEQ_3D;
             break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_SME_3D;
             break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_SMD_3D;
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_HAEC_3D;
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_HEEC_3D;
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_HEEQ_3D;
             break;

        case SRM_SRFTCOD_MERCATOR:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_M_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_M_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_OMS_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_OM_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_TM_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_TM_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LCC_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_LCC_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_PS_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_PS_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_EC_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_EC_SURFACE if 2D */
             break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
             *is_3D = SE_FALSE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_NULL;
             *coord_code          = SRM_SPACOORDCOD_LSR_2D;
             break;

        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
             *is_3D = SE_FALSE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_NULL;
             *coord_code          = SRM_SPACOORDCOD_LSA_2D;
             break;

        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
             *is_3D = SE_FALSE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_NULL;
             *coord_code          = SRM_SPACOORDCOD_LSP_2D;
             break;

        default:
             ret_code = SE_RETCOD_FAILURE;
             break;
    }
    return ret_code;
} /* end SpatialAxisTypesForSRFTParameters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SpatialAxisTypesForSRFSCodeInfo
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
SpatialAxisTypesForSRFSCodeInfo
(
    const SRM_SRFS_Code_Info          *srf_set,
          SE_Boolean                  *is_3D,
          EDCS_Attribute_Code         *primary_axis_type,
          EDCS_Attribute_Code         *secondary_axis_type,
          EDCS_Attribute_Code         *tertiary_axis_type,
          SRM_Spatial_Coordinate_Code *coord_code
)
{
    SE_Return_Code ret_code = SE_RETCOD_SUCCESS;

    *is_3D = SE_FALSE;
    *primary_axis_type   = EAC_NULL;
    *secondary_axis_type = EAC_NULL;
    *tertiary_axis_type  = EAC_NULL;
    *coord_code          = (SRM_Spatial_Coordinate_Code)-1;

    switch (srf_set->srfs_code)
    {
        case SRM_SRFSCOD_ALABAMA_SPCS:
        case SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS:
        case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_TM_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_TM_SURFACE if 2D */
             break;

        case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LTSE_3D;
                                  /* also SRM_SPACOORDCOD_LTSE_SURFACE if 2D */
             break;

        case SRM_SRFSCOD_LAMBERT_NTF:
        case SRM_SRFSCOD_WISCONSIN_SPCS:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LCC_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_LCC_SURFACE if 2D */
             break;

        case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_PS_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_PS_SURFACE if 2D */
             break;

        default:
             ret_code = SE_RETCOD_FAILURE;
             break;
    }
    return ret_code;
} /* end SpatialAxisTypesForSRFSCodeInfo */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SpatialAxisTypesForSRFCode
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
SpatialAxisTypesForSRFCode
(
    SRM_SRF_Code                 srf_instance,
    SE_Boolean                  *is_3D,
    EDCS_Attribute_Code         *primary_axis_type,
    EDCS_Attribute_Code         *secondary_axis_type,
    EDCS_Attribute_Code         *tertiary_axis_type,
    SRM_Spatial_Coordinate_Code *coord_code
)
{
    SE_Return_Code ret_code = SE_RETCOD_SUCCESS;

    *is_3D = SE_FALSE;
    *primary_axis_type   = EAC_NULL;
    *secondary_axis_type = EAC_NULL;
    *tertiary_axis_type  = EAC_NULL;
    *coord_code          = (SRM_Spatial_Coordinate_Code)-1;

    switch (srf_instance)
    {
        case SRM_SRFCOD_GEOCENTRIC_WGS_1984:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_CC_3D;
             break;

        case SRM_SRFCOD_GEODETIC_AUSTRALIA_1984:
        case SRM_SRFCOD_GEODETIC_N_AMERICAN_1983:
        case SRM_SRFCOD_GEODETIC_WGS_1984:
        case SRM_SRFCOD_MARS_PLANETOCENTRIC_2000:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_CD_3D;
                                  /* also SRM_SPACOORDCOD_CD_SURFACE if 2D */
             break;


        case SRM_SRFCOD_LAMBERT_93:
        case SRM_SRFCOD_LAMBERT_II_WIDE:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_LCC_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_LCC_SURFACE if 2D */
             break;

        case SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY:
        case SRM_SRFCOD_DELAWARE_SPCS_1983:
        case SRM_SRFCOD_IRISH_GRID_1965:
        case SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989:
        case SRM_SRFCOD_MARYLAND_SPCS_1983:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_LINEAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_TM_AUGMENTED_3D;
                                  /* also SRM_SPACOORDCOD_TM_SURFACE if 2D */
             break;

        case SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000:
             *is_3D = SE_TRUE;
             *primary_axis_type   = EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE;
             *secondary_axis_type = EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE;
             *tertiary_axis_type  = EAC_SPATIAL_LINEAR_TERTIARY_COORDINATE;
             *coord_code          = SRM_SPACOORDCOD_PD_3D;
                                  /* also SRM_SPACOORDCOD_PD_SURFACE if 2D */
             break;

        default:
             ret_code = SE_RETCOD_FAILURE;
             break;
    }
    return ret_code;
} /* end SpatialAxisTypesForSRFCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SpatialAxisTypesForSRFParametersInfo
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
SpatialAxisTypesForSRFParametersInfo
(
    const SRM_SRF_Parameters_Info     *srf_parameters_info,
          SE_Boolean                  *is_3D,
          EDCS_Attribute_Code         *primary_axis_type,
          EDCS_Attribute_Code         *secondary_axis_type,
          EDCS_Attribute_Code         *tertiary_axis_type,
          SRM_Spatial_Coordinate_Code *coord_code
)
{
    SE_Return_Code ret_code = SE_RETCOD_SUCCESS;

    *is_3D = SE_FALSE;
    *primary_axis_type   = EAC_NULL;
    *secondary_axis_type = EAC_NULL;
    *tertiary_axis_type  = EAC_NULL;
    *coord_code          = (SRM_Spatial_Coordinate_Code)-1;

    switch (srf_parameters_info->srf_params_info_code)
    {
        case SRM_SRFPARAMINFCOD_TEMPLATE:
             ret_code = SpatialAxisTypesForSRFTParameters
                        (
                           &(srf_parameters_info->value.srf_template),
                            is_3D,
                            primary_axis_type,
                            secondary_axis_type,
                            tertiary_axis_type,
                            coord_code
                        );
             break;

        case SRM_SRFPARAMINFCOD_SET:
             ret_code = SpatialAxisTypesForSRFSCodeInfo
                        (
                           &(srf_parameters_info->value.srf_set.srfs_code_info),
                            is_3D,
                            primary_axis_type,
                            secondary_axis_type,
                            tertiary_axis_type,
                            coord_code
                        );
             break;

        case SRM_SRFPARAMINFCOD_INSTANCE:
             ret_code = SpatialAxisTypesForSRFCode
                        (
                            srf_parameters_info->value.srf_instance,
                            is_3D,
                            primary_axis_type,
                            secondary_axis_type,
                            tertiary_axis_type,
                            coord_code
                        );
             break;

        default:
             ret_code = SE_RETCOD_FAILURE;
             break;
    }
    return ret_code;
} /* end SpatialAxisTypesForSRFParametersInfo */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CheckSpatialIndexUnit
 *
 *-----------------------------------------------------------------------------
 */
SE_Return_Code
local_CheckSpatialIndexUnit
(
          SE_Short_Integer_Unsigned  level,
          SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
          SE_Object                  object,
          SE_FIELDS_PTR              spatial_index_fields,
    const SE_SRF_Context_Info       *srf_context_info
)
{
    SE_Return_Code              ret_code = SE_RETCOD_SUCCESS;
    SE_Boolean                  is_3D = SE_FALSE;
    EDCS_Attribute_Code         primary_axis_type = EAC_NULL,
                                secondary_axis_type = EAC_NULL,
                                tertiary_axis_type = EAC_NULL;
    SRM_Spatial_Coordinate_Code coord_code;

    if (SE_ValidDRMClassFields(spatial_index_fields, SE_FALSE, NULL)
        != SE_TRUE)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "invalid fields");
        ret_code = SE_RETCOD_FAILURE;
    }
    else if ((ret_code = SpatialAxisTypesForSRFParametersInfo
               (&(srf_context_info->srf_parameters_info), &is_3D,
                &primary_axis_type, &secondary_axis_type,
                &tertiary_axis_type, &coord_code)) != SE_RETCOD_SUCCESS)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't retrieve spatial axis types corresponding to "\
           "srf_context_info");
    }
    else
    {
        SE_Spatial_Index_Spacing_Unit spacing_unit;

        switch (spatial_index_fields->tag)
        {
            case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
                 spacing_unit = spatial_index_fields->u.Spatial_Index_Related_Geometry.spacing_unit;
                 break;
            case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY:
                 spacing_unit = spatial_index_fields->u.Spatial_Index_Related_Geometry_Topology.spacing_unit;
                 break;
            case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
                 spacing_unit = spatial_index_fields->u.Spatial_Index_Related_Features.spacing_unit;
                 break;
            case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY:
                 spacing_unit = spatial_index_fields->u.Spatial_Index_Related_Feature_Topology.spacing_unit;
                 break;
            default:
                 return SE_RETCOD_FAILURE;
        } /* end switch */
        if ((primary_axis_type == EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE) &&
            (spacing_unit != SE_SISPACUNITS_ARC_SECOND))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "linear spacing_unit is invalid for SRF that requires "\
               "angular unit");
            ret_code = SE_RETCOD_FAILURE;
        }
        else if ((primary_axis_type == EAC_SPATIAL_LINEAR_PRIMARY_COORDINATE) &&
                 (spacing_unit != SE_SISPACUNITS_METRE))
        {
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "angular spacing_unit is invalid for SRF that requires "\
               "linear unit");
            ret_code = SE_RETCOD_FAILURE;
        }
    }
    return ret_code;
} /* end local_CheckSpatialIndexUnit */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_spatial_axis
 *
 *-----------------------------------------------------------------------------
 */
static void
check_spatial_axis
(
          SE_Short_Integer_Unsigned    level,
          SE_DRM_Class                 path[MAX_CHECKER_PATH_LENGTH],
          SE_FIELDS_PTR                axis_fields,
          SE_Object                    axis,
          SE_Boolean                   is_3D,
          EDCS_Attribute_Code          primary_axis_type,
          EDCS_Attribute_Code          secondary_axis_type,
          EDCS_Attribute_Code          tertiary_axis_type,
          SRM_Spatial_Coordinate_Code  coord_code,
    const SE_SRF_Context_Info         *srf_context_info
)
{
    SE_Boolean           valid = SE_FALSE;
    char                 msg_buf[512];
    EDCS_Unit_Code       axis_unit = EUC_UNITLESS;
    EDCS_Unit_Scale_Code axis_scale = ESC_UNI;

    path[level] = axis_fields->tag;

    switch (axis_fields->tag)
    {
        case SE_CLS_DRM_INTERVAL_AXIS:
             axis_unit  = axis_fields->u.Interval_Axis.value_unit;
             axis_scale = axis_fields->u.Interval_Axis.value_scale;
             break;
        case SE_CLS_DRM_IRREGULAR_AXIS:
             axis_unit  = axis_fields->u.Irregular_Axis.value_unit;
             axis_scale = axis_fields->u.Irregular_Axis.value_scale;
             break;
        case SE_CLS_DRM_REGULAR_AXIS:
             axis_unit  = axis_fields->u.Regular_Axis.value_unit;
             axis_scale = axis_fields->u.Regular_Axis.value_scale;
             break;
        default:
             se_message(axis, path[level], level, path, MSGTYP_ERROR,
                 "<Axis> subclass is not compatible with requirements "\
                 "on spatial <Axis> EAs; run syntax_checker");
             return;
    }

    if (axis_fields->u.Axis.axis_type == primary_axis_type)
    {
        if (axis_fields->u.Axis.axis_type ==
            EAC_SPATIAL_ANGULAR_PRIMARY_COORDINATE)
        {
            if (axis_unit != srf_context_info->angular_unit)
            {
                se_message(axis, path[level], level, path, MSGTYP_ERROR,
                  "value_unit for <Axis> does not match "\
                  "srf_context_info.angular_unit for <Property Grid>");
            }
        }
        else
        {
            if ((axis_unit != srf_context_info->linear_unit) ||
                (axis_scale != srf_context_info->linear_scale))
            {
                se_message(axis, path[level], level, path, MSGTYP_ERROR,
                  "value_unit and value_scale for <Axis> "\
                  "do not match srf_context_info.linear_unit and "\
                  "srf_context_info.linear_scale for <Property Grid>");
            }
        }
    }
    else if (axis_fields->u.Axis.axis_type == secondary_axis_type)
    {
        if (axis_fields->u.Axis.axis_type ==
            EAC_SPATIAL_ANGULAR_SECONDARY_COORDINATE)
        {
            if (axis_unit != srf_context_info->angular_unit)
            {
                se_message(axis, path[level], level, path, MSGTYP_ERROR,
                  "value_unit for <Axis> does not match "\
                  "srf_context_info.angular_unit for <Property Grid>");
            }
        }
        else
        {
            if ((axis_unit != srf_context_info->linear_unit) ||
                (axis_scale != srf_context_info->linear_scale))
            {
                se_message(axis, path[level], level, path, MSGTYP_ERROR,
                  "value_unit and value_scale for <Axis> "\
                  "do not match srf_context_info.linear_unit and "\
                  "srf_context_info.linear_scale for <Property Grid>");
            }
        }
    }
    else if ((is_3D == SE_TRUE) &&
             (axis_fields->u.Axis.axis_type == tertiary_axis_type))
    {
        /* tertiary is always linear */
        if ((axis_unit != srf_context_info->linear_unit) ||
            (axis_scale != srf_context_info->linear_scale))
        {
            se_message(axis, path[level], level, path, MSGTYP_ERROR,
              "value_unit and value_scale for <Axis> "\
              "do not match srf_context_info.linear_unit and "\
              "srf_context_info.linear_scale for <Property Grid>");
        }
    }
    else
    {
        const EDCS_Attribute_Dictionary_Entry *ac_dict_entry = NULL;

        if (EDCS_GetEADictionaryEntry(axis_fields->u.Axis.axis_type,
            &ac_dict_entry) == EDCS_SC_SUCCESS)
        {
            sprintf(msg_buf, "axis_type %s invalid for spatial <Axis> "\
                    "in this <Property Grid> instance's SRF",
                    EDCS_PrintAttributeCode(axis_fields->u.Axis.axis_type));
        }
        else
        {
            sprintf(msg_buf, "axis_type has invalid EDCS_Attribute_Code");
        }
        se_message(axis, path[level], level, path, MSGTYP_ERROR, msg_buf);
    }
} /* end check_spatial_axis */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_property_table_reference
 *
 *   Check the given object for:
 *   - <<Characteristics Of Property Table Reference>>
 *   - valid control link, if it has one
 *
 *-----------------------------------------------------------------------------
 */
void
check_property_table_reference
(
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class                   path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                      object,
    SE_FIELDS_PTR                  fields_ptr,
    SE_INTERFACE_TEMPLATE_WRAPPER *interface_template,
    SE_LOCAL_SUMMARY              *summary
)
{
    SE_Object     next_object = NULL, table_object = NULL;
    SE_FIELDS_PTR next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_PROPERTY_TABLE_REFERENCE;

    if (SE_GetAssociate(object, SE_CLS_DRM_PROPERTY_TABLE,
        SE_ITRBEH_RESOLVE, &table_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_Object   library_object = NULL;
        SE_Iterator iter = NULL;
        SE_Boolean  found_axis = SE_FALSE;

        if (SE_GetAggregate(table_object, SE_CLS_DRM_DATA_TABLE_LIBRARY,
            SE_ITRBEH_RESOLVE, &library_object, NULL) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_property_table_reference:SE_GetAggregate");
            se_message(object, path[level], level, path, MSGTYP_ERROR,
               "violates <<Characteristics Of Property Table Reference>>, part (a)");
        }
        if (library_object)
            SE_FreeObject(library_object);
       /*
        * now to check <Property Table> for the referenced <Axis>,
        * both axis_type and axis_value_count
        */
        if (local_InitializeComponentIterator3(table_object, search_filter,
             &iter) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("check_property_table_reference:SE_InitializeComponentIterator");
            se_message(table_object, SE_CLS_DRM_PROPERTY_TABLE, level+1, path,
               MSGTYP_ERROR, "can't initialize component iter");
        }
        else
        {
            while ((found_axis != SE_TRUE) &&
                   (SE_IsIteratorComplete(iter) == SE_FALSE))
            {
                if (SE_GetNextObjectOnly(iter, &next_object) !=
                    SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus
                    ("check_property_table_reference:SE_GetNextObject");
                    continue;
                }
                else if (SE_GetFields(next_object, GetGlobalStore(level),
                         &next_fields_ptr) != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus
                    ("check_property_table_reference:SE_GetFields");
                    path[level+1] = SE_CLS_DRM_PROPERTY_TABLE;
                    se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
                       MSGTYP_ERROR,
                       "Can't get fields for <Property Table>'s component");
                }
                else if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_AXIS] &&
                         next_fields_ptr->u.Axis.axis_type ==
                         fields_ptr->u.Property_Table_Reference.axis_type)
                {
                    found_axis = SE_TRUE;
                    if (next_fields_ptr->u.Axis.axis_value_count <
                      (fields_ptr->u.Property_Table_Reference.index_on_axis+1))
                    {
                        se_message(object, path[level], level, path,
                           MSGTYP_ERROR, "violates "\
        "<<Characteristics Of Property Table Reference>>, part (c)");
                    }
                }
                SE_FreeObject(next_object);
            }
            if (found_axis != SE_TRUE)
            {
                se_message(object, path[level], level, path, MSGTYP_ERROR,
        "violates <<Characteristics Of Property Table Reference>>, part (b)");
            }
        }
    }
    else
    {
        printLastFnctStatus("check_property_table_reference:GetAssociate");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't get associated <Property Table>");
    }
    next_object = NULL;

    if (table_object)
    {
        SE_FreeObject(table_object);
        table_object = NULL;
    }

    if (SE_GetComponent(object,
           SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK,
           SE_FALSE, SE_FALSE, SE_ITRBEH_RESOLVE,
          &next_object, NULL) == SE_RETCOD_SUCCESS)
    {
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            check_control_link(level+1, path, next_object, next_fields_ptr,
                interface_template, summary);
        }
        else
        {
            printLastFnctStatus
            ("check_property_table_reference:SE_GetFields");
            se_message(next_object,
               SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK,
               level+1, path, MSGTYP_ERROR, "can't get fields");
        }
    }

    if (next_object)
        SE_FreeObject(next_object);
} /* end check_property_table_reference */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_table_property_description
 *
 *-----------------------------------------------------------------------------
 */
static SE_Return_Code
check_table_property_description
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_Element_Code_Queue     *eac_queue_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code ret_status = SE_RETCOD_SUCCESS;
    SE_Iterator    iter = NULL;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;
    SE_Boolean                     tpd_fields_valid = SE_TRUE;
    SE_Element_Code_Queue          eac_val_queue;
    EDCS_Value_Characteristic_Code pc_meaning[EDCS_TOTAL_EV];
    SE_Integer_Unsigned            pc_count = 0, i = 0;

    path[level] = fields_ptr->tag;

    if (SE_ValidDRMClassFields(fields_ptr, SE_FALSE, NULL) != SE_TRUE)
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR_SYNTAX,
           "invalid fields");
        tpd_fields_valid = SE_FALSE;
        ret_status = SE_RETCOD_FAILURE;
    }

    if (local_InitializeComponentIterator3(object, search_filter, &iter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_tbl_prop_description:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "can't initialize component iter");
        return SE_RETCOD_FAILURE;
    }
    eac_val_queue.head = NULL;
    eac_val_queue.tail = NULL;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_tbl_prop_description:SE_GetNextObject");
            ret_status = SE_RETCOD_FAILURE;
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_PROPERTY_VALUE:
                     if (check_property_value(level+1, path, next_object,
                         next_fields_ptr, &eac_val_queue, summary) != SE_RETCOD_SUCCESS)
                     {
                         ret_status = SE_RETCOD_FAILURE;
                     }
                     break;

                case SE_CLS_DRM_PROPERTY_CHARACTERISTIC:
                     if (tpd_fields_valid != SE_TRUE)
                         break;

                     switch (fields_ptr->u.Table_Property_Description.value_type)
                     {
                         case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
                         case SE_DTDATAVALTYP_LONG_FLOAT:
                              if (next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_REAL)
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - real-valued <Table Property Description>, "\
                                    "requires real <Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_SINGLE_INTEGER:
                         case SE_DTDATAVALTYP_INTEGER:
                              if (next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_INTEGER)
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - integer-valued <Table Property Description>, "\
                                    "requires integer <Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_SINGLE_COUNT:
                         case SE_DTDATAVALTYP_COUNT:
                              if (next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_COUNT)
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - count-valued <Table Property Description>, "\
                                    "requires count <Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_INDEX:
                              if (next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_INDEX)
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - index-valued <Table Property Description>, "\
                                    "requires index <Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_STRING:
                              if (next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_STRING)
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - string-valued <Table Property Description>, "\
                                    "requires string <Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_CONSTRAINED_STRING:
                              if (next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_CONSTRAINED_STRING)
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - constrained string-valued "\
                                    "<Table Property Description>, "\
                                    "requires constrained string <Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_KEY:
                              if (next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_KEY)
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - key-valued <Table Property Description>, "\
                                    "requires key <Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_ENUMERATION:
                              if ((next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_ENUMERATION) &&
                                 !((next_fields_ptr->u.Property_Characteristic.
                                   characteristic_value.attribute_value_type ==
                                   EDCS_AVT_INTEGER) &&
                                   (next_fields_ptr->u.Property_Characteristic.
                                   characteristic_value.value.integer_value.
                                   numeric_value_type == EDCS_NVT_SINGLE_VALUE)))
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - EE-valued <Table Property Description>, "\
                                    "requires EE or single integer valued "\
                                    "<Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_BOOLEAN:
                              if (next_fields_ptr->u.Property_Characteristic.
                                  characteristic_value.attribute_value_type !=
                                  EDCS_AVT_BOOLEAN)
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - Boolean-valued <Table Property Description>, "\
                                    "requires Boolean valued "\
                                    "<Property Characteristic>");
                              }
                              break;
                         case SE_DTDATAVALTYP_INDEX_CODE:
                              if ((next_fields_ptr->u.Property_Characteristic.
                                   characteristic_value.attribute_value_type !=
                                   EDCS_AVT_COUNT) ||
                                  (next_fields_ptr->u.Property_Characteristic.
                                   characteristic_value.value.count_value.
                                   numeric_value_type != EDCS_NVT_SINGLE_VALUE))
                              {
                                  se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "violates <<Property Characteristic Constraints>>"\
                                    " - index-code-valued "\
                                    "<Table Property Description>, "\
                                    "requires single count valued "\
                                    "<Property Characteristic>");
                              }
                              break;

                         default:
                              se_message(next_object, next_fields_ptr->tag,
                                level+1, path, MSGTYP_ERROR,
                                "unrecognized value type for "\
                                "<Table Property Description>");
                             break;
                     } /* end switch */

                     for (i = 0; i < pc_count; i++)
                     {
                         if (next_fields_ptr->u.Property_Characteristic.meaning !=
                             pc_meaning[i])
                         {
                             pc_meaning[pc_count] =
                               next_fields_ptr->u.Property_Characteristic.meaning;
                             pc_count++;
                         }
                         else
                         {
                             se_message(next_object, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
                               level+1, path, MSGTYP_ERROR,
                           "violates <<Property Characteristic Constraints>> - "\
                           "meaning not unique among this "\
                           "<Table Property Description>'s "\
                           "<Property Characteristic> components");
                         }
                     } /* end for */
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_tbl_prop_description:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path, MSGTYP_ERROR,
               "can't get fields");
            ret_status = SE_RETCOD_FAILURE;
        } /* end if */
        SE_FreeObject(next_object);
    }
    local_FreeElementCodeQueue(&eac_val_queue);

    if (ret_status == SE_RETCOD_SUCCESS)
    {
        SE_Boolean              is_unique = SE_FALSE;
        SE_Classification_Entry class_entry;

        if (check_classification_data(level, path, object, fields_ptr,
            &class_entry, summary) == SE_TRUE)
        {
            is_unique = local_AddElementCodeToQueue
                        (&(fields_ptr->u.Table_Property_Description.meaning),
                         &class_entry, eac_queue_ptr);

           /*
            * $$$ if SE_IDXCODE_DATA_TABLE_COMPONENT
            * $$$ or SE_IDXCODE_DATA_TABLE_LIBRARY,
            * $$$ need to have been passed a classification entry
            * $$$ along with it to tell whether it is truly unique
            *
            * $$$ if <Property Value> components, need to check them
            * $$$ to tell whether it is truly unique
            */
            if ((is_unique != SE_TRUE) &&
                ((fields_ptr->u.Table_Property_Description.meaning.code_type !=
                  SE_ELEMTYPCOD_INDEX) ||
                 ((fields_ptr->u.Table_Property_Description.meaning.code_type ==
                   SE_IDXCODE_DATA_TABLE_COMPONENT) ||
                  (fields_ptr->u.Table_Property_Description.meaning.code_type ==
                   SE_IDXCODE_DATA_TABLE_LIBRARY))))
            {
                se_message(object, path[level], level, path, MSGTYP_ERROR,
                   "<Table Property Description> instance's meaning field "\
                   "value is not unique for <Data Table>");
            }
        }
    }
    SE_FreeIterator(iter);

    return ret_status;
} /* end check_table_property_description */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_data_table
 *
 *-----------------------------------------------------------------------------
 */
void
check_data_table
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code        status = SE_RETCOD_SUCCESS;
    SE_Iterator           iter = NULL;
    SE_Object             next_object = NULL;
    SE_FIELDS_PTR         next_fields_ptr = NULL;
    SE_Integer_Unsigned   axis_count = 0, data_table_comp_count = 0,
                          imf_comp_count = 0, ptr_comp_count = 0;
    SE_Boolean            data_table_comp_ref = SE_FALSE,
                          imf_comp_ref = SE_FALSE, is_3D = SE_FALSE,
                          ptr_comp_ref = SE_FALSE;
    EDCS_Attribute_Code   primary_axis_type,
                          secondary_axis_type,
                          tertiary_axis_type;
    SE_Element_Code_Queue axis_type_list, tpd_meaning_list;
    SRM_Spatial_Coordinate_Code coord_code;
    SE_LOCAL_CONTEXT            local_context;

    path[level] = fields_ptr->tag;

    SE_InitializeLocalContext
    (
        level,
        path,
        object,
        fields_ptr,
        NULL,
       &local_context
    );
   /*
    * Do not need to check for unresolved <Property Set Index>
    * components - they cannot occur in this context
    */
    imf_comp_count = local_context.expected_texture_coordinate_count;

    if ((fields_ptr->tag == SE_CLS_DRM_PROPERTY_GRID) &&
        (SpatialAxisTypesForSRFParametersInfo
        (&(fields_ptr->u.Property_Grid.srf_context_info.srf_parameters_info),
        &is_3D, &primary_axis_type, &secondary_axis_type,
        &tertiary_axis_type, &coord_code) != SE_RETCOD_SUCCESS))
    {
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't retrieve spatial axis types corresponding to "\
           "srf_context_info");
        return;
    }
    else if (local_InitializeComponentIterator3(object, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("check_data_table:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize component iter");
        return;
    }
    tpd_meaning_list.head = NULL;
    tpd_meaning_list.tail = NULL;
    axis_type_list.head = NULL;
    axis_type_list.tail = NULL;
    axis_count          = 0;

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_data_table:SE_GetNextObject");
            break;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            switch (next_fields_ptr->tag)
            {
                case SE_CLS_DRM_PROPERTY_GRID:
                case SE_CLS_DRM_PROPERTY_TABLE:
                     data_table_comp_count++;
                     check_data_table(level+1, path, next_object,
                        next_fields_ptr, summary);
                     break;

                case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
                     ptr_comp_count++;
                     check_attribute(level+1, path, next_object,
                         next_fields_ptr,
                         NULL, summary); /* no control links to resolve for this case */
                     break;

                case SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION:
                     check_table_property_description(level+1, path, next_object,
                         next_fields_ptr, &tpd_meaning_list, summary);
                     if (next_fields_ptr->u.Table_Property_Description.
                         meaning.code_type == SE_ELEMTYPCOD_INDEX)
                     {
                         switch (next_fields_ptr->u.Table_Property_Description.
                                 meaning.code.index)
                         {
                             case SE_IDXCODE_DATA_TABLE_COMPONENT:
                                  data_table_comp_ref = SE_TRUE;
                                  break;
                          /* case SE_IDXCODE_DATA_TABLE_LIBRARY:
                                  break; */
                             case SE_IDXCODE_IMAGE_MAPPING_FUNCTION:
                                  imf_comp_ref = SE_TRUE;
                                  break;
                             case SE_IDXCODE_PROP_TABLE_REF_COMPONENT:
                                  ptr_comp_ref = SE_TRUE;
                                  break;
                         }
                     }
                     break;

                default:
                     if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_AXIS])
                     {
                         if (IsSpatialAxis(&(next_fields_ptr->u.Axis)))
                         {
                             if (fields_ptr->tag == SE_CLS_DRM_PROPERTY_GRID)
                             {
                                 check_spatial_axis(level+1, path,
                                     next_fields_ptr, next_object, is_3D,
                                     primary_axis_type,
                                     secondary_axis_type,
                                     tertiary_axis_type, coord_code,
                                     &(fields_ptr->u.Property_Grid.srf_context_info));

                                 if (axis_count >=
                                     fields_ptr->u.Property_Grid.spatial_axes_count)
                                 {
                                     se_message(next_object, next_fields_ptr->tag,
                                        level+1, path, MSGTYP_ERROR,
                                        "violates <<Spatial Axis Constraints>>, part (b);");
                                 }
                             }
                             else
                             {
                                 se_message(next_object, next_fields_ptr->tag,
                                    level+1, path, MSGTYP_ERROR,
                                    "only <Property Grid> can have spatial <Axis>");
                             }
                         }
                         else if ((fields_ptr->tag == SE_CLS_DRM_PROPERTY_GRID) &&
                                  (axis_count <
                                   fields_ptr->u.Property_Grid.spatial_axes_count))
                         {
                             se_message(next_object, next_fields_ptr->tag,
                                level+1, path, MSGTYP_ERROR,
                                "violates <<Axis Type Restrictions>>, part (c)");
                         }
                         if (local_AddAttributeCodeToQueue
                               (&(next_fields_ptr->u.Axis.axis_type),
                                &axis_type_list) != SE_TRUE)
                         {
                             se_message(next_object, next_fields_ptr->tag,
                                level+1, path, MSGTYP_ERROR,
                                "<Data Table> can only have one <Axis> for a"\
                                " given axis_type");
                         }
                         axis_count++;
                     }
                     else
                     {
                         check_attribute(level+1, path, next_object,
                             next_fields_ptr,
                             NULL, summary); /* no control links to resolve for this case */
                     }
                     break;
            } /* end switch */
        }
        else
        {
            printLastFnctStatus("check_data_table:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        } /* end if */
        SE_FreeObject(next_object);
    }
    local_FreeElementCodeQueue(&axis_type_list);
    local_FreeElementCodeQueue(&tpd_meaning_list);

    SE_FreeIterator(iter);

   /*
    * $$$ needs to be more sophisticated - check number of <Data Table>s
    * $$$ with a given (and possibly qualified) <Classification Data>
    */
    if ((data_table_comp_ref == SE_TRUE) &&
        (data_table_comp_count < 1))
    {
        se_message(object, fields_ptr->tag, level, path, MSGTYP_ERROR,
           "has SE_IDXCODE_DATA_TABLE_COMPONENT <Table Property Description>"\
           " but no <Data Table> components");
    }
    else if ((data_table_comp_ref != SE_TRUE) &&
             (data_table_comp_count > 0))
    {
        se_message(object, fields_ptr->tag, level, path, MSGTYP_WARNING,
           "has <Data Table> components but no "\
           "SE_IDXCODE_DATA_TABLE_COMPONENT <Table Property Description>");
    }

    if ((imf_comp_ref == SE_TRUE) &&
        (imf_comp_count < 1))
    {
        se_message(object, fields_ptr->tag, level, path, MSGTYP_ERROR,
           "has SE_IDXCODE_IMAGE_MAPPING_FUNCTION <Table Property Description>"\
           " but no <Image Mapping Function> components");
    }
    else if ((imf_comp_ref != SE_TRUE) &&
             (imf_comp_count > 0))
    {
        se_message(object, fields_ptr->tag, level, path, MSGTYP_WARNING,
           "has <Image Mapping Function> components but no "\
           "SE_IDXCODE_IMAGE_MAPPING_FUNCTION <Table Property Description>");
    }

    if ((ptr_comp_ref == SE_TRUE) &&
        (ptr_comp_count < 1))
    {
        se_message(object, fields_ptr->tag, level, path, MSGTYP_ERROR,
           "has SE_IDXCODE_PROP_TABLE_REF_COMPONENT <Table Property Description>"\
           " but no <Property Table Reference> components");
    }
    else if ((ptr_comp_ref != SE_TRUE) &&
             (ptr_comp_count > 0))
    {
        se_message(object, fields_ptr->tag, level, path, MSGTYP_WARNING,
           "has <Property Table Reference> components but no "\
           "SE_IDXCODE_PROP_TABLE_REF_COMPONENT <Table Property Description>");
    }
} /* end check_data_table */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_data_table_library
 *
 *   Check the Data Table Library and its components for the following
 *   constraints:
 *   <<Mandatory Metadata>>
 *
 *-----------------------------------------------------------------------------
 */
void
check_data_table_library
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_SUMMARY          *summary
)
{
    SE_Return_Code status = SE_RETCOD_SUCCESS;
    SE_Iterator    iter = NULL;
    SE_Object      next_object = NULL;
    SE_FIELDS_PTR  next_fields_ptr = NULL;

    path[level] = SE_CLS_DRM_DATA_TABLE_LIBRARY;

    if (local_InitializeComponentIterator3(object, search_filter,
        &iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("check_data_table_library:SE_InitializeComponentIterator");
        se_message(object, path[level], level, path, MSGTYP_ERROR,
           "Can't initialize component iter");
        return;
    }

    while (SE_IsIteratorComplete(iter) == SE_FALSE)
    {
        if (SE_GetNextObjectOnly(iter, &next_object) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("check_data_table_library:SE_GetNextObject");
            continue;
        }
        SE_UpdateAnalysisCounts();

        if (SE_GetFields(next_object, GetGlobalStore(level), &next_fields_ptr)
            == SE_RETCOD_SUCCESS)
        {
            SE_UpdateLocalSummaryFromFields(summary, next_fields_ptr);

            if (SE_IsA[next_fields_ptr->tag][SE_CLS_DRM_DATA_TABLE])
            {
                check_data_table(level+1, path, next_object,
                    next_fields_ptr, summary);
            }
            else
            {
                check_attribute( level+1, path, next_object, next_fields_ptr,
                    NULL, /* no control links to resolve for this case */
                    summary);
            }
        }
        else
        {
            printLastFnctStatus("check_data_table_library:SE_GetFields");
            se_message(next_object, SE_CLS_DRM_NULL, level+1, path,
               MSGTYP_ERROR, "Can't get fields");
        }
        SE_FreeObject(next_object);
    }
    SE_FreeIterator(iter);
} /* end check_data_table_library */
