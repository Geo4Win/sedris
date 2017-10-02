// SEDRIS Level 0 Read API
//
// FILE:        se_search_coord_sys.cpp
//
// PROGRAMMERS: Michele L. Worley (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: Provides support for SEDRIS Search Boundaries
//              by providing EC specific routines.
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011
//
/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
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

#include <math.h>

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "ErrorHandling.hpp"
#include "se_search_support.hpp"
#include "se_search_util.hpp"
#include "se_search_coord.hpp"
#include "raif_srm_utils.h"
#include "RAIFManager.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


// static  SE_Long_Float   RAIF_FEET_PER_METER  =  3.28083989501312335958;

static bool offset_CD_point3D
(
    const SE_SRF_Context_Info *cd_srf_info,
    const RAIF_SRF_Wrapper    *cd_srf,
    const SRM_Coordinate      *cd_point,
    const SRM_Vector_3D        offset_vector,
          SRM_Coordinate      *offset_point
);

static bool offset_LSR_point3D
(
    const SE_SRF_Context_Info *lsr_srf_info,
    const SRM_Coordinate      *lsr_point,
    const SRM_Vector_3D        offset_vector,
          SRM_Coordinate      *offset_point
);

static SE_Long_Float get_numeric_average
(
    SE_Long_Float weight1,
    SE_Long_Float num1,
    SE_Long_Float weight2,
    SE_Long_Float num2
);

static SE_Long_Float get_angle_average
(
    SE_Long_Float weight1,
    SE_Long_Float angle1,
    SE_Long_Float weight2,
    SE_Long_Float angle2
);


//----------------------------------------------------------------------------
//
// FUNCTION: se_search_coord_get_average_point
//
//----------------------------------------------------------------------------
SE_Boolean se_search_coord_get_average_point
(
    SE_OBJECT_SEARCH_POINT *point1, // IN
    SE_OBJECT_SEARCH_POINT *point2  // IN/OUT
)
{
    SE_Long_Float p1X, p1Y, p1Z, p2X, p2Y, p2Z;
    SE_Long_Float weight1, weight2;

    weight1 = point1->num_contributing_pts;
    weight2 = point2->num_contributing_pts;

    if (point1->point.spatial_coord_code != point2->point.spatial_coord_code )
    {
         raif_mngr->add_err_descr("se_search_coord_get_average_point: point1 and point2 "\
                  "are not in the same SRF");
         return SE_FALSE;
    }

    se_get_coords( &point1->point, &p1X, &p1Y, &p1Z );
    se_get_coords( &point2->point, &p2X, &p2Y, &p2Z );

    // compute averages
    if (!RAIFCoordIsAngular( point1->point.spatial_coord_code ) )
    {
        p2X = get_numeric_average(weight1, p1X, weight2, p2X);
        p2Y = get_numeric_average(weight1, p1Y, weight2, p2Y);

        if (RAIFCoordIs3D( point1->point.spatial_coord_code ) )
            p2Z = get_numeric_average(weight1, p1Z, weight2, p2Z);
    }
    else
    {
        SE_Long_Float total_weight = weight1 + weight2;

        p2Y = get_angle_average(weight1, p1Y, weight2, p2Y);

        // Latitude ranges from -90 to 90
        p2X = (weight1 * (p1X) + weight2 * (p2X)) / total_weight;

        if (RAIFCoordIs3D( point1->point.spatial_coord_code ) )
            p2Z = get_numeric_average(weight1, p1Z, weight2, p2Z);
    }
    se_set_coords( &point2->point, p2X, p2Y, p2Z );

    return SE_TRUE;
} // end se_search_coord_get_average_point


//----------------------------------------------------------------------------
//
SE_Boolean se_offset_coord
(
    SRM_Coordinate               *coord,
    SE_Long_Float              delta_x,
    SE_Long_Float              delta_y,
    SE_Spatial_Index_Spacing_Unit  units
)
{
    SE_Boolean  result = SE_TRUE;
    SE_Long_Float px, py, pz;

    se_get_coords(coord, &px, &py, &pz);

    switch( coord->spatial_coord_code )
    {
        case SRM_SPACOORDCOD_CD_SURFACE:
            if (units == SE_SISPACUNITS_ARC_SECOND)
            {
                py += delta_x * SE_ARC_DEGREES_PER_ARC_SECOND;
                px += delta_y * SE_ARC_DEGREES_PER_ARC_SECOND;
            }
            else
            {
                raif_mngr->add_err_descr("se_offset_coord: 2D non-arcsecond units");
                result = SE_FALSE;
            }
            break;

        case SRM_SPACOORDCOD_LSR_2D :
        case SRM_SPACOORDCOD_EC_SURFACE :
        case SRM_SPACOORDCOD_PS_SURFACE :
        case SRM_SPACOORDCOD_LCC_SURFACE :
        case SRM_SPACOORDCOD_TM_SURFACE :
        case SRM_SPACOORDCOD_LTSE_SURFACE :
        case SRM_SPACOORDCOD_M_SURFACE :
        case SRM_SPACOORDCOD_OMS_SURFACE :
            if (units == SE_SISPACUNITS_METRE)
            {
                px += delta_x;
                py += delta_y;
            }
            else
            {
                raif_mngr->add_err_descr("se_offset_coord: 2D non-meter units");
                result = SE_FALSE;
            }
            break;
        case SRM_SPACOORDCOD_CD_3D :
        case SRM_SPACOORDCOD_CM_3D :
        case SRM_SPACOORDCOD_EI_3D :
        case SRM_SPACOORDCOD_SEC_3D :
        case SRM_SPACOORDCOD_SMD_3D :
        case SRM_SPACOORDCOD_SME_3D :
            if (units == SE_SISPACUNITS_ARC_SECOND)
            {
                py += delta_x * SE_ARC_DEGREES_PER_ARC_SECOND;
                px += delta_y * SE_ARC_DEGREES_PER_ARC_SECOND;
            }
            else
            {
                raif_mngr->add_err_descr("se_offset_coord: 3D non-arcsecond units");
                result = SE_FALSE;
            }
            break;
        case SRM_SPACOORDCOD_CC_3D :
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D :
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D :
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D :
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D :
        case SRM_SPACOORDCOD_LTSE_3D :
        case SRM_SPACOORDCOD_LSR_3D :
            if (units == SE_SISPACUNITS_METRE)
            {
                px += delta_x;
                py += delta_y;
            }
            else
            {
                raif_mngr->add_err_descr("se_offset_coord: 3D non-meter units");
                result = SE_FALSE;
            }
            break;

        default:
            raif_mngr->add_err_descr("se_offset_coord: unknown 3D COORD_CODE");
            result = SE_FALSE;
            break;
    }

    if (result )
    {
        se_set_coords(coord, px, py, pz);
    }
    return result;
}


//----------------------------------------------------------------------------
//
// FUNCTION: se_offset_point
//
//----------------------------------------------------------------------------
SE_Boolean se_offset_point
(
    const SE_SRF_Context_Info *srf_info,
          SRM_Coordinate      *point,
    const SRM_Vector_3D       offset_vector,
          SRM_Coordinate      *offset_point
)
{
    RAIF_SRF_Wrapper   srf;

    if (RAIFCreateSRFWrapper(srf_info, &srf) != SRM_STATCOD_SUCCESS)
    {
        raif_mngr->add_err_descr( "se_offset_point: Unable to initialize SRF\n");
        return SE_FALSE;
    }
    else
    {
        if (RAIFSRFIs2D(srf.srft_code))
        {
            raif_mngr->add_err_descr("se_offset_point: Couldn't determine SRF dimensionality.");
            RAIFDestroySRMObjectReference( &srf );
            return SE_FALSE;
        }
        RAIFDestroySRMObjectReference( &srf );
    }

    if (RAIFCoordIs2D( point->spatial_coord_code ))
    {
        raif_mngr->add_err_descr("se_offset_point: 2D not implemented");
        return SE_FALSE;
    }
    else if (SE_ValidCoordinateForSRFContextInfo( point, srf_info ) )
    {
        raif_mngr->add_err_descr("se_offset_point: mismatched 3D SRF parameters");
        return SE_FALSE;
    }

    // Note that we will just use any of the access members in the union
    // since it is a union.

    switch( point->spatial_coord_code )
    {
        case SRM_SPACOORDCOD_CD_3D:
            if(offset_CD_point3D( srf_info, &srf, point, offset_vector, offset_point))
                return SE_TRUE;
            else
                return SE_FALSE;

        case SRM_SPACOORDCOD_CC_3D:
        case SRM_SPACOORDCOD_LTSE_3D:
            offset_point->coordinate.cc_3d.u = point->coordinate.cc_3d.u + offset_vector[0];
            offset_point->coordinate.cc_3d.v = point->coordinate.cc_3d.v + offset_vector[1];
            offset_point->coordinate.cc_3d.w = point->coordinate.cc_3d.w + offset_vector[2];
            return SE_TRUE;

        case SRM_SPACOORDCOD_CM_3D:
        case SRM_SPACOORDCOD_EI_3D:
        case SRM_SPACOORDCOD_SEC_3D:
        case SRM_SPACOORDCOD_SME_3D:
        case SRM_SPACOORDCOD_SMD_3D:
            raif_mngr->add_err_descr("se_search_offset_point: Target SRF not supported.");
            return SE_FALSE;

        case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
        case SRM_SPACOORDCOD_M_AUGMENTED_3D:
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
            break;

        case SRM_SPACOORDCOD_LSR_3D:
            if(offset_LSR_point3D( srf_info, point, offset_vector, offset_point))
                return SE_TRUE;
            else
                return SE_FALSE;

        default:
            raif_mngr->add_err_descr("se_offset_point: unknown SRF");
            return SE_FALSE;
    }
    return SE_TRUE;
} // end se_offset_point


//----------------------------------------------------------------------------
//
// FUNCTION: matrix_mult
//
//   Apply a transformation matrix to a vector to get a vector.
//
//----------------------------------------------------------------------------
static void matrix_mult
(
    const SRM_Matrix_3x3 mat_ptr,
    const SRM_Vector_3D  vec_ptr,
          SRM_Vector_3D  result_ptr
)
{
    SE_Byte_Unsigned i,j;

    for(i = 0; i < 3; i++)
    {
        result_ptr[i] = 0.0;
        for(j = 0; j < 3; j++)
        {
            result_ptr[i] += mat_ptr[i][j] * vec_ptr[j];
        }
    }
}


//----------------------------------------------------------------------------
//
// FUNCTION: build_ENU_matrix
//
//   Builds a 3x3 matrix to orient an east/north/up coordinate system in
//   space. The matrix has three columns, which are unit east, north, and
//   up vectors in that order.
//
//   Although it is not trivially obvious, these formulas work for a
//   geodetic coordinate system with theta as longitude and phi as
//   geodetic latitude.
//
// PARAMETERS:
//
//   theta_in_radians -- the longitude or right ascension value; in radians;
//     can range from -EDCS_PI to EDCS_PI
//
//   phi_in_radians -- the elevation or declination value; in radians;
//     can range from -EDCS_PI/2.0 to EDCS_PI/2.0
//
//   out_matrix --  expressed in a coordinate system with the x-axis pointing
//     to theta=0 and phi=0, the y-axis pointing to theta=EDCS_PI/2.0 and
//     phi=0, and the z-axis pointing to phi=EDCS_PI/2.0.
//
//
// RETURNS:
//
//   An error is returned if either angle is out of range or if phi
//   is less than 1 degree from +-EDCS_PI/2.0.
//
//----------------------------------------------------------------------------
static SE_Boolean
build_ENU_matrix
(
    SE_Long_Float   theta_in_radians,
    SE_Long_Float   phi_in_radians,
    SRM_Matrix_3x3  out_matrix
)
{
    SE_Long_Float cos_theta, sin_theta, cos_phi, sin_phi;

    if (fabs(theta_in_radians) > EDCS_LF_PI ||
        fabs(phi_in_radians) > (89.0 *SE_RADIANS_PER_DEGREE))
        return SE_FALSE;

    cos_theta = cos(theta_in_radians);
    sin_theta = sin(theta_in_radians);
    cos_phi   = cos(phi_in_radians);
    sin_phi   = sin(phi_in_radians);

    /* East */
    out_matrix[0][0] = - sin_theta;
    out_matrix[1][0] = cos_theta;
    out_matrix[2][0] = 0.0;

    /* North */
    out_matrix[0][1] = - cos_theta * sin_phi;
    out_matrix[1][1] = - sin_theta* sin_phi;
    out_matrix[2][1] = cos_phi;

    /* Up */
    out_matrix[2][0] = cos_theta * cos_phi;
    out_matrix[2][1] = sin_theta * cos_phi;
    out_matrix[2][2] = sin_phi;

    return SE_TRUE;
}


//----------------------------------------------------------------------------
static bool
offset_CD_point3D
(
    const SE_SRF_Context_Info *cd_srf_info,
    const RAIF_SRF_Wrapper    *cd_srf,
    const SRM_Coordinate      *cd_point,
    const SRM_Vector_3D        offset_vector,
          SRM_Coordinate      *offset_point
)
{
    bool                status = true;
    SRM_Vector_3D       offset_in_CC;
    SRM_Matrix_3x3      CD_orientation_matrix;
    SE_SRF_Context_Info cc_srf_info;
    SRM_Coordinate      cc_point;
    RAIF_SRF_Wrapper    cc_srf;

    /*
     * Find the orientation of the east/north/up system in CD
     */
    if (!build_ENU_matrix(cd_point->coordinate.cd_3d.longitude*SE_RADIANS_PER_DEGREE,
                          cd_point->coordinate.cd_3d.latitude*SE_RADIANS_PER_DEGREE,
                          CD_orientation_matrix))
    {
        raif_mngr->add_err_descr("offset_CD_point3D: Can't build local Cartesian matrix.");
        return false;
    }

    /*
     * Express the offset in CC
     */
    matrix_mult( CD_orientation_matrix, offset_vector, offset_in_CC);

    /*
     * Convert the base point to CC. Use the cd srf info but change the code
     */

    if (cd_srf_info->srf_parameters_info.srf_params_info_code != SRM_SRFPARAMINFCOD_TEMPLATE)
    {
        raif_mngr->add_err_descr("offset_CD_point3D: Don't support srf info not using parameters");
        return false;
    }
    memcpy( &cc_srf_info, cd_srf_info, sizeof( SE_SRF_Context_Info ));

    cc_srf_info.srf_parameters_info.value.srf_template.template_code = SRM_SRFTCOD_CELESTIOCENTRIC;

    if (RAIFCreateSRFWrapper(&cc_srf_info, &cc_srf) != SRM_STATCOD_SUCCESS)
    {
        raif_mngr->add_err_descr( "offset_CD_point3D: Unable to create CC SRF");
        status = false;
    }
    else if (RAIFChangeCoordSRFFromSRF( cd_srf, cd_point, &cc_srf,
        &cc_point) != SRM_STATCOD_SUCCESS)
    {
        raif_mngr->add_err_descr( "offset_CD_point3D: Unable to convert CD coordinate");
        status = false;
    }
    else
    {
       /*
        * Add the offset and convert back to CD
        */
        cc_point.coordinate.cc_3d.u += offset_in_CC[0];
        cc_point.coordinate.cc_3d.v += offset_in_CC[1];
        cc_point.coordinate.cc_3d.w += offset_in_CC[2];

        if (RAIFChangeCoordSRFFromSRF( &cc_srf, &cc_point, cd_srf,
            offset_point) != SRM_STATCOD_SUCCESS)
        {
            raif_mngr->add_err_descr("offset_CD_point3D: Can't convert point back to CD.");
            status = false;
        }
        else
        {
            RAIFDestroySRMObjectReference(&cc_srf);
        }
    }
    return status;
} // end offset_CD_point3D


//
// FUNCTION: offset_LSR_point
//
static bool
offset_LSR_point3D( const SE_SRF_Context_Info    *lsr_srf_info,
                    const SRM_Coordinate         *point,
                    const SRM_Vector_3D           offset_vector,
                    SRM_Coordinate               *offset_point )
{
    bool status = true;

    if (lsr_srf_info->srf_parameters_info.srf_params_info_code != SRM_SRFPARAMINFCOD_TEMPLATE)
    {
        raif_mngr->add_err_descr("offset_LSR_point3D: Don't support srf info not using parameters");
        return false;
    }

  /*
   * Add the offset. We need to make its orientation match that of the
   * original location. Remember that the subscripts of the offset are
   * 0 = primary, 1 = secondary and 2 = tertiary
   */
    switch( lsr_srf_info->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.up_direction)
    {
    case SRM_AXDIR_POSITIVE_PRIMARY_AXIS :
        offset_point->coordinate.lsr_3d.w += offset_vector[0];
        switch(lsr_srf_info->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.forward_direction)
        {
        case SRM_AXDIR_POSITIVE_SECONDARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[1];
            offset_point->coordinate.lsr_3d.v += offset_vector[2];
            break;
        case SRM_AXDIR_NEGATIVE_SECONDARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[1];
            offset_point->coordinate.lsr_3d.v += offset_vector[2];
            break;
        case SRM_AXDIR_POSITIVE_TERTIARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[2];
            offset_point->coordinate.lsr_3d.v -= offset_vector[1];
            break;
        case SRM_AXDIR_NEGATIVE_TERTIARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[2];
            offset_point->coordinate.lsr_3d.v += offset_vector[1];
            break;
        default:
            raif_mngr->add_err_descr("offset_LSR_point3D: bad orientation of LSR.");
            status = SE_FALSE;
            break;
        }
        break;

    case SRM_AXDIR_NEGATIVE_PRIMARY_AXIS :
        offset_point->coordinate.lsr_3d.w = -offset_vector[0];
        switch(lsr_srf_info->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.forward_direction)
        {
        case SRM_AXDIR_POSITIVE_SECONDARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[1];
            offset_point->coordinate.lsr_3d.v -= offset_vector[2];
            break;
        case SRM_AXDIR_NEGATIVE_SECONDARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[1];
            offset_point->coordinate.lsr_3d.v += offset_vector[2];
            break;
        case SRM_AXDIR_POSITIVE_TERTIARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[2];
            offset_point->coordinate.lsr_3d.v += offset_vector[1];
            break;
        case SRM_AXDIR_NEGATIVE_TERTIARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[2];
            offset_point->coordinate.lsr_3d.v -= offset_vector[1];
            break;
        default:
            raif_mngr->add_err_descr("offset_LSR_point3D: bad orientation of LSR.");
            status = SE_FALSE;
            break;
        }
        break;

    case SRM_AXDIR_POSITIVE_SECONDARY_AXIS :
        offset_point->coordinate.lsr_3d.w += offset_vector[1];
        switch(lsr_srf_info->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.forward_direction)
        {
        case SRM_AXDIR_POSITIVE_PRIMARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[0];
            offset_point->coordinate.lsr_3d.v -= offset_vector[2];
            break;
        case SRM_AXDIR_NEGATIVE_PRIMARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[0];
            offset_point->coordinate.lsr_3d.v += offset_vector[2];
            break;
        case SRM_AXDIR_POSITIVE_TERTIARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[2];
            offset_point->coordinate.lsr_3d.v += offset_vector[0];
            break;
        case SRM_AXDIR_NEGATIVE_TERTIARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[2];
            offset_point->coordinate.lsr_3d.v -= offset_vector[0];
            break;
        default:
            raif_mngr->add_err_descr("offset_LSR_point3D: bad orientation of LSR.");
            status = SE_FALSE;
            break;
        }
        break;

    case SRM_AXDIR_NEGATIVE_SECONDARY_AXIS :
        offset_point->coordinate.lsr_3d.w = -offset_vector[1];
        switch(lsr_srf_info->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.forward_direction)
        {
        case SRM_AXDIR_POSITIVE_PRIMARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[0];
            offset_point->coordinate.lsr_3d.v += offset_vector[2];
            break;
        case SRM_AXDIR_NEGATIVE_PRIMARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[0];
            offset_point->coordinate.lsr_3d.v -= offset_vector[2];
            break;
        case SRM_AXDIR_POSITIVE_TERTIARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[2];
            offset_point->coordinate.lsr_3d.v -= offset_vector[0];
            break;
        case SRM_AXDIR_NEGATIVE_TERTIARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[2];
            offset_point->coordinate.lsr_3d.v += offset_vector[0];
            break;
        default:
            raif_mngr->add_err_descr("offset_LSR_point3D: bad orientation of LSR.");
            status = SE_FALSE;
            break;
        }
        break;

    case SRM_AXDIR_POSITIVE_TERTIARY_AXIS :
        offset_point->coordinate.lsr_3d.w += offset_vector[2];
        switch(lsr_srf_info->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.forward_direction)
        {
        case SRM_AXDIR_POSITIVE_PRIMARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[0];
            offset_point->coordinate.lsr_3d.v += offset_vector[1];
            break;
        case SRM_AXDIR_NEGATIVE_PRIMARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[0];
            offset_point->coordinate.lsr_3d.v -= offset_vector[1];
            break;
        case SRM_AXDIR_POSITIVE_SECONDARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[1];
            offset_point->coordinate.lsr_3d.v -= offset_vector[0];
            break;
        case SRM_AXDIR_NEGATIVE_SECONDARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[1];
            offset_point->coordinate.lsr_3d.v += offset_vector[0];
            break;
        default:
            raif_mngr->add_err_descr("offset_LSR_point3D: bad orientation of LSR.");
            status = SE_FALSE;
            break;
        }
        break;

    case SRM_AXDIR_NEGATIVE_TERTIARY_AXIS :
        offset_point->coordinate.lsr_3d.w = -offset_vector[2];
        switch(lsr_srf_info->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters.forward_direction)
        {
        case SRM_AXDIR_POSITIVE_PRIMARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[0];
            offset_point->coordinate.lsr_3d.v -= offset_vector[1];
            break;
        case SRM_AXDIR_NEGATIVE_PRIMARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[0];
            offset_point->coordinate.lsr_3d.v += offset_vector[1];
            break;
        case SRM_AXDIR_POSITIVE_SECONDARY_AXIS:
            offset_point->coordinate.lsr_3d.u += offset_vector[1];
            offset_point->coordinate.lsr_3d.v += offset_vector[0];
            break;
        case SRM_AXDIR_NEGATIVE_SECONDARY_AXIS:
            offset_point->coordinate.lsr_3d.u -= offset_vector[1];
            offset_point->coordinate.lsr_3d.v -= offset_vector[0];
            break;
        default:
            raif_mngr->add_err_descr("offset_LSR_point3D: bad orientation of LSR.");
            status = SE_FALSE;
            break;
        }
        break;
    }
    return status;
} /* end offset_LSR_point3D */


//----------------------------------------------------------------------------
//
// FUNCTION: get_numeric_average
//
//----------------------------------------------------------------------------
SE_Long_Float get_numeric_average
(
    SE_Long_Float weight1,
    SE_Long_Float num1,
    SE_Long_Float weight2,
    SE_Long_Float num2
)
{
    SE_Long_Float total_weight = weight1 + weight2;
    SE_Long_Float avg;

    if (total_weight == 0.0)
    {
        avg = 0.0;
    }
    else if (num1 == SE_NEGATIVE_INFINITY)
    {
        if (num2 == SE_POSITIVE_INFINITY)
        {
            if (weight1 == weight2)
                avg = 0.0;
            else if (weight1 > weight2)
                avg = SE_NEGATIVE_INFINITY;
            else /* weight1 < weight2 */
                avg = SE_POSITIVE_INFINITY;
        }
        else if (weight1 == 0.0)
            avg = num2;
        else
            avg = SE_NEGATIVE_INFINITY;
    }
    else if (num1 == SE_POSITIVE_INFINITY)
    {
        if (num2 == SE_NEGATIVE_INFINITY)
        {
            if (weight1 == weight2)
                avg = 0.0;
            else if (weight1 > weight2)
                avg = SE_POSITIVE_INFINITY;
            else /* weight1 < weight2 */
                avg = SE_NEGATIVE_INFINITY;
        }
        else if (weight1 == 0.0)
            avg = num2;
        else
            avg = SE_POSITIVE_INFINITY;
    }
    else if (num2 == SE_NEGATIVE_INFINITY || num2 == SE_POSITIVE_INFINITY)
    {
         /* but num1 is finite */
        if(weight2 == 0.0)
            avg = num1;
        else
            avg = num2;
    }
    else /* both are finite */
    {
        avg = (weight1 * num1 + weight2 * num2) / total_weight;
    }
    return avg;
} // end get_numeric_average


//----------------------------------------------------------------------------
//
// FUNCTION: get_angle_average
//
//   We need to average two special kinds of quantities:
//   - angles like longitude that have a singular value at 180/-180
//   - and numbers that can take on infinite values.
//
//----------------------------------------------------------------------------
SE_Long_Float get_angle_average
(
    SE_Long_Float weight1,
    SE_Long_Float angle1,
    SE_Long_Float weight2,
    SE_Long_Float angle2
)
{
    SE_Long_Float angle_diff;
    SE_Long_Float total_weight = weight1 + weight2;
    SE_Long_Float avg_angle;

    /*
     * In which direction are the angles closer?
     */
    angle_diff = angle2-angle1;
    if (total_weight == 0.0)
    {
        avg_angle = 0.0;
    }
    else if(fabs(angle_diff) <= 180.0)
    {
        avg_angle = (weight1 * angle1 + weight2 * angle2)/total_weight;
    }
    else
    {
        if (angle1 < 0.0)
        {
            avg_angle = (weight1 * (angle1 + 360.0) + weight2 * angle2) /
                        total_weight;
        }
        else /* angle2 < 0.0 */
        {
            avg_angle = (weight1 * angle1 + weight2 * (angle2 + 360.0))/
                        total_weight;
        }
        if (avg_angle < 360.0)
            avg_angle += 360.0;
    }
    return avg_angle;
} /* end get_angle_average */
