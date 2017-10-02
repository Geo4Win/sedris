/* SRM API
 *
 * FILE       : srm_default.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Provides pre-initialized global variables containing complete, default
 *   field structures for all struct other types provided by the SRM API.
 *
 * - SRM spec. 4.1
 * SRM SDK Release 4.1.4 - July 1, 2011
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


#include "srm.h"



/*
 * GLOBAL VARIABLE: SRM_CD_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_CD_3D_Coordinate variable.
 */
const SRM_CD_3D_Coordinate
SRM_CD_3D_COORDINATE_DEFAULT =
{
    0.0, /* longitude */
    0.0, /* latitude */
    0.0 /* ellipsoidal_height */
};


/*
 * GLOBAL VARIABLE: SRM_CD_SURFACE_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_CD_Surface_Coordinate variable.
 */
const SRM_CD_Surface_Coordinate
SRM_CD_SURFACE_COORDINATE_DEFAULT =
{
    0.0, /* longitude */
    0.0 /* latitude */
};


/*
 * GLOBAL VARIABLE: SRM_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Coordinate variable.
 */
const SRM_Coordinate
SRM_COORDINATE_DEFAULT =
{
    SRM_SPACOORDCOD_CC_3D, /* spatial_coord_code */
    {{0.0, 0.0, 0.0}} /* coordinate */
};


/*
 * GLOBAL VARIABLE: SRM_COORDINATE_VALID_REGION_ARRAY_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Coordinate_Valid_Region_Array variable.
 */
const SRM_Coordinate_Valid_Region_Array
SRM_COORDINATE_VALID_REGION_ARRAY_DEFAULT =
{
    0, /* length */
    NULL /* valid_region_array */
};


/*
 * GLOBAL VARIABLE: SRM_COORDINATE2D_ARRAY_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Coordinate2D_Array variable.
 */
const SRM_Coordinate2D_Array
SRM_COORDINATE2D_ARRAY_DEFAULT =
{
    0, /* length */
    NULL /* coordinate2D_array */
};


/*
 * GLOBAL VARIABLE: SRM_COORDINATE3D_ARRAY_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Coordinate3D_Array variable.
 */
const SRM_Coordinate3D_Array
SRM_COORDINATE3D_ARRAY_DEFAULT =
{
    0, /* length */
    NULL /* coordinate3D_array */
};


/*
 * GLOBAL VARIABLE: SRM_DIRECTION_ARRAY_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Direction_Array variable.
 */
const SRM_Direction_Array
SRM_DIRECTION_ARRAY_DEFAULT =
{
    0, /* length */
    NULL /* direction_array */
};


/*
 * GLOBAL VARIABLE: SRM_EC_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_EC_Parameters variable.
 */
const SRM_EC_Parameters
SRM_EC_PARAMETERS_DEFAULT =
{
    0.0, /* origin_longitude */
    1.0, /* central_scale */
    0.0, /* false_easting */
    0.0 /* false_northing */
};


/*
 * GLOBAL VARIABLE: SRM_EI_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_EI_3D_Coordinate variable.
 */
const SRM_EI_3D_Coordinate
SRM_EI_3D_COORDINATE_DEFAULT =
{
    0.0, /* right_ascension */
    0.0, /* declination */
    0.0 /* radius */
};


/*
 * GLOBAL VARIABLE: SRM_EUCLIDEAN_2D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Euclidean_2D_Coordinate variable.
 */
const SRM_Euclidean_2D_Coordinate
SRM_EUCLIDEAN_2D_COORDINATE_DEFAULT =
{
    0.0, /* u */
    0.0 /* v */
};


/*
 * GLOBAL VARIABLE: SRM_EUCLIDEAN_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Euclidean_3D_Coordinate variable.
 */
const SRM_Euclidean_3D_Coordinate
SRM_EUCLIDEAN_3D_COORDINATE_DEFAULT =
{
    0.0, /* u */
    0.0, /* v */
    0.0 /* w */
};


/*
 * GLOBAL VARIABLE: SRM_LCC_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LCC_Parameters variable.
 */
const SRM_LCC_Parameters
SRM_LCC_PARAMETERS_DEFAULT =
{
    0.0, /* origin_longitude */
    0.0, /* origin_latitude */
    0.0, /* latitude1 */
    0.0, /* latitude2 */
    0.0, /* false_easting */
    0.0 /* false_northing */
};


/*
 * GLOBAL VARIABLE: SRM_LCE_3D_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LCE_3D_Parameters variable.
 */
const SRM_LCE_3D_Parameters
SRM_LCE_3D_PARAMETERS_DEFAULT =
{
    0.0, 0.0, 0.0, /* lococentre */
    1.0, 0.0, 0.0, /* primary_axis */
    0.0, 1.0, 0.0 /* secondary_axis */
};


/*
 * GLOBAL VARIABLE: SRM_LOCAL_TANGENT_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Local_Tangent_Parameters variable.
 */
const SRM_Local_Tangent_Parameters
SRM_LOCAL_TANGENT_PARAMETERS_DEFAULT =
{
    0.0, /* geodetic_longitude */
    0.0, /* geodetic_latitude */
    0.0, /* azimuth */
    0.0 /* height_offset */
};


/*
 * GLOBAL VARIABLE: SRM_LSA_2D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LSA_2D_Coordinate variable.
 */
const SRM_LSA_2D_Coordinate
SRM_LSA_2D_COORDINATE_DEFAULT =
{
    0.0, /* azimuth */
    0.0 /* radius */
};


/*
 * GLOBAL VARIABLE: SRM_LSP_2D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LSP_2D_Coordinate variable.
 */
const SRM_LSP_2D_Coordinate
SRM_LSP_2D_COORDINATE_DEFAULT =
{
    0.0, /* angle */
    0.0 /* radius */
};


/*
 * GLOBAL VARIABLE: SRM_LSR_2D_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LSR_2D_Parameters variable.
 */
const SRM_LSR_2D_Parameters
SRM_LSR_2D_PARAMETERS_DEFAULT =
{
    SRM_AXDIR_POSITIVE_PRIMARY_AXIS /* forward_direction */
};


/*
 * GLOBAL VARIABLE: SRM_LSR_3D_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LSR_3D_Parameters variable.
 */
const SRM_LSR_3D_Parameters
SRM_LSR_3D_PARAMETERS_DEFAULT =
{
    SRM_AXDIR_POSITIVE_PRIMARY_AXIS, /* forward_direction */
    SRM_AXDIR_POSITIVE_SECONDARY_AXIS /* up_direction */
};


/*
 * GLOBAL VARIABLE: SRM_LTSAS_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LTSAS_3D_Coordinate variable.
 */
const SRM_LTSAS_3D_Coordinate
SRM_LTSAS_3D_COORDINATE_DEFAULT =
{
    0.0, /* azimuth */
    0.0, /* angle */
    0.0 /* radius */
};


/*
 * GLOBAL VARIABLE: SRM_LTSAS_SURFACE_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LTSAS_Surface_Coordinate variable.
 */
const SRM_LTSAS_Surface_Coordinate
SRM_LTSAS_SURFACE_COORDINATE_DEFAULT =
{
    0.0, /* azimuth */
    0.0 /* angle */
};


/*
 * GLOBAL VARIABLE: SRM_LTSC_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LTSC_3D_Coordinate variable.
 */
const SRM_LTSC_3D_Coordinate
SRM_LTSC_3D_COORDINATE_DEFAULT =
{
    0.0, /* angle */
    0.0, /* radius */
    0.0 /* height */
};


/*
 * GLOBAL VARIABLE: SRM_LTSC_SURFACE_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LTSC_Surface_Coordinate variable.
 */
const SRM_LTSC_Surface_Coordinate
SRM_LTSC_SURFACE_COORDINATE_DEFAULT =
{
    0.0, /* angle */
    0.0 /* radius */
};


/*
 * GLOBAL VARIABLE: SRM_LTSE_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LTSE_3D_Coordinate variable.
 */
const SRM_LTSE_3D_Coordinate
SRM_LTSE_3D_COORDINATE_DEFAULT =
{
    0.0, /* x */
    0.0, /* y */
    0.0 /* height */
};


/*
 * GLOBAL VARIABLE: SRM_LTSE_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LTSE_Parameters variable.
 */
const SRM_LTSE_Parameters
SRM_LTSE_PARAMETERS_DEFAULT =
{
    0.0, /* geodetic_longitude */
    0.0, /* geodetic_latitude */
    0.0, /* azimuth */
    0.0, /* x_false_origin */
    0.0, /* y_false_origin */
    0.0 /* height_offset */
};


/*
 * GLOBAL VARIABLE: SRM_LTSE_SURFACE_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_LTSE_Surface_Coordinate variable.
 */
const SRM_LTSE_Surface_Coordinate
SRM_LTSE_SURFACE_COORDINATE_DEFAULT =
{
    0.0, /* x */
    0.0 /* y */
};


/*
 * GLOBAL VARIABLE: SRM_M_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_M_Parameters variable.
 */
const SRM_M_Parameters
SRM_M_PARAMETERS_DEFAULT =
{
    0.0, /* origin_longitude */
    1.0, /* central_scale */
    0.0, /* false_easting */
    0.0 /* false_northing */
};


/*
 * GLOBAL VARIABLE: SRM_MAP_PROJECTION_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Map_Projection_3D_Coordinate variable.
 */
const SRM_Map_Projection_3D_Coordinate
SRM_MAP_PROJECTION_3D_COORDINATE_DEFAULT =
{
    0.0, /* easting */
    0.0, /* northing */
    0.0 /* ellipsoidal_height */
};


/*
 * GLOBAL VARIABLE: SRM_MAP_PROJECTION_SURFACE_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Map_Projection_Surface_Coordinate variable.
 */
const SRM_Map_Projection_Surface_Coordinate
SRM_MAP_PROJECTION_SURFACE_COORDINATE_DEFAULT =
{
    0.0, /* easting */
    0.0 /* northing */
};


/*
 * GLOBAL VARIABLE: SRM_MATRIX_3X3_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Matrix_3x3 variable.
 */
const SRM_Matrix_3x3
SRM_MATRIX_3X3_DEFAULT =
{
    1.0, 0.0, 0.0,
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0
};


/*
 * GLOBAL VARIABLE: SRM_MATRIX_4X4_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Matrix_4x4 variable.
 */
const SRM_Matrix_4x4
SRM_MATRIX_4X4_DEFAULT =
{
    1.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 1.0
};


/*
 * GLOBAL VARIABLE: SRM_OBLIQUE_MERCATOR_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Oblique_Mercator_Parameters variable.
 */
const SRM_Oblique_Mercator_Parameters
SRM_OBLIQUE_MERCATOR_PARAMETERS_DEFAULT =
{
    0.0, /* longitude1 */
    0.0, /* latitude1 */
    0.0, /* longitude2 */
    0.0, /* latitude2 */
    1.0, /* central_scale */
    0.0, /* false_easting */
    0.0 /* false_northing */
};


/*
 * GLOBAL VARIABLE: SRM_ORM_TRANSFORMATION_2D_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_ORM_Transformation_2D_Parameters variable.
 */
const SRM_ORM_Transformation_2D_Parameters
SRM_ORM_TRANSFORMATION_2D_PARAMETERS_DEFAULT =
{
    0.0, /* delta_x */
    0.0, /* delta_y */
    0.0, /* omega */
    0.0 /* delta_s */
};


/*
 * GLOBAL VARIABLE: SRM_ORM_TRANSFORMATION_3D_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_ORM_Transformation_3D_Parameters variable.
 */
const SRM_ORM_Transformation_3D_Parameters
SRM_ORM_TRANSFORMATION_3D_PARAMETERS_DEFAULT =
{
    0.0, /* delta_x */
    0.0, /* delta_y */
    0.0, /* delta_z */
    0.0, /* omega_1 */
    0.0, /* omega_2 */
    0.0, /* omega_3 */
    0.0 /* delta_s */
};


/*
 * GLOBAL VARIABLE: SRM_PD_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_PD_3D_Coordinate variable.
 */
const SRM_PD_3D_Coordinate
SRM_PD_3D_COORDINATE_DEFAULT =
{
    0.0, /* longitude */
    0.0, /* latitude */
    0.0 /* ellipsoidal_height */
};


/*
 * GLOBAL VARIABLE: SRM_PD_SURFACE_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_PD_Surface_Coordinate variable.
 */
const SRM_PD_Surface_Coordinate
SRM_PD_SURFACE_COORDINATE_DEFAULT =
{
    0.0, /* longitude */
    0.0 /* latitude */
};


/*
 * GLOBAL VARIABLE: SRM_PS_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_PS_Parameters variable.
 */
const SRM_PS_Parameters
SRM_PS_PARAMETERS_DEFAULT =
{
    SRM_PLRASP_NORTH, /* polar_aspect */
    0.0, /* origin_longitude */
    1.0, /* central_scale */
    0.0, /* false_easting */
    0.0 /* false_northing */
};


/*
 * GLOBAL VARIABLE: SRM_SPHERICAL_3D_COORDINATE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Spherical_3D_Coordinate variable.
 */
const SRM_Spherical_3D_Coordinate
SRM_SPHERICAL_3D_COORDINATE_DEFAULT =
{
    0.0, /* longitude */
    0.0, /* latitude */
    0.0 /* radius */
};


/*
 * GLOBAL VARIABLE: SRM_SRF_PARAMETERS_INFO_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_SRF_Parameters_Info variable.
 */
const SRM_SRF_Parameters_Info
SRM_SRF_PARAMETERS_INFO_DEFAULT =
{
    SRM_SRFPARAMINFCOD_TEMPLATE, /* srf_params_info_code */
    SRM_RTCOD_UNSPECIFIED, /* rt_code */
    {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}} /* value */
};


/*
 * GLOBAL VARIABLE: SRM_SRF_REFERENCE_SURFACE_INFO_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_SRF_Reference_Surface_Info variable.
 */
const SRM_SRF_Reference_Surface_Info
SRM_SRF_REFERENCE_SURFACE_INFO_DEFAULT =
{
    SRM_DSSCOD_UNSPECIFIED, /* dss_code */
    {SRM_SRFPARAMINFCOD_TEMPLATE, SRM_RTCOD_UNSPECIFIED, {{SRM_SRFTCOD_CELESTIOCENTRIC, SRM_ORMCOD_UNSPECIFIED, {{0}}}}} /* srf_parameters_info */
};


/*
 * GLOBAL VARIABLE: SRM_SRFS_CODE_INFO_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_SRFS_Code_Info variable.
 */
const SRM_SRFS_Code_Info
SRM_SRFS_CODE_INFO_DEFAULT =
{
    SRM_SRFSCOD_UNSPECIFIED, /* srfs_code */
    {0} /* value */
};


/*
 * GLOBAL VARIABLE: SRM_SRFS_INFO_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_SRFS_Info variable.
 */
const SRM_SRFS_Info
SRM_SRFS_INFO_DEFAULT =
{
    SRM_ORMCOD_UNSPECIFIED, /* orm_code */
    {SRM_SRFSCOD_UNSPECIFIED, {0}} /* srfs_code_info */
};


/*
 * GLOBAL VARIABLE: SRM_SRFT_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_SRFT_Parameters variable.
 */
const SRM_SRFT_Parameters
SRM_SRFT_PARAMETERS_DEFAULT =
{
    SRM_SRFTCOD_CELESTIOCENTRIC, /* template_code */
    SRM_ORMCOD_UNSPECIFIED, /* orm_code */
    {{0}} /* parameters */
};


/*
 * GLOBAL VARIABLE: SRM_TM_PARAMETERS_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_TM_Parameters variable.
 */
const SRM_TM_Parameters
SRM_TM_PARAMETERS_DEFAULT =
{
    0.0, /* origin_longitude */
    0.0, /* origin_latitude */
    1.0, /* central_scale */
    0.0, /* false_easting */
    0.0 /* false_northing */
};


/*
 * GLOBAL VARIABLE: SRM_UNUSED_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Unused variable.
 */
const SRM_Unused
SRM_UNUSED_DEFAULT =
{
    0 /* unused */
};


/*
 * GLOBAL VARIABLE: SRM_VECTOR_3D_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   SRM_Vector_3D variable.
 */
const SRM_Vector_3D
SRM_VECTOR_3D_DEFAULT =
{
    0.0, 0.0, 0.0
};
