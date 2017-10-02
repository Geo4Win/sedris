// SEDRIS Reference API Implementation Framework
//
// Produced by: The SEDRIS Team
//
// FILE:        HashTable.cpp
//
// PROGRAMMERS: Greg Hull, Jesse Campos (SAIC)
//
// DESCRIPTION: SRM related utilites for RAIF
//
// - API spec. 4.1
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#include <math.h>
#include "srm.h"
#include "raif_srm_utils.h"
#include "ErrorHandling.hpp"
#include "RAIFTypes.hpp"


SRM_Status_Code
RAIFCreateSRFWrapper
(
    const SE_SRF_Context_Info *src_context_info,
          RAIF_SRF_Wrapper    *new_srf
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (SE_GetSRFTCodeFromSRFContextInfo(src_context_info,
        &(new_srf->srft_code)) != SRM_STATCOD_SUCCESS)
    {
        err_handler->add_err_descr("RAIFCreateSRFWrapper: "\
           "SE_GetSRFTCodeFromSRFContextInfo failed");
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (SE_CreateObjectReferenceFromSRFContextInfo
             (src_context_info, &(new_srf->srf)) !=
             SRM_STATCOD_SUCCESS)
    {
        err_handler->add_err_descr("RAIFCreateSRFWrapper: "\
          "SE_CreateObjectReferenceFromSRFContextInfo failed");
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        new_srf->angular_unit = src_context_info->angular_unit;
        new_srf->linear_unit  = src_context_info->linear_unit;
        new_srf->linear_scale = src_context_info->linear_scale;

        if (src_context_info->use_dss_code != SE_TRUE)
            new_srf->dss_code = SRM_DSSCOD_UNSPECIFIED;
        else
            new_srf->dss_code = src_context_info->dss_code;
    }
    return status;
}


// The SRM calls use object references, the RAIF
// calls use the srft_code and the spatial_coord_code

bool
RAIFSRFIs2D( SRM_SRFT_Code srft_code)
{
    if (srft_code == SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D ||
        srft_code == SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D ||
        srft_code == SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D)
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool
RAIFCoordIs2D(SRM_Spatial_Coordinate_Code coord_code)
{
    switch (coord_code)
    {
        case SRM_SPACOORDCOD_LSA_2D:
        case SRM_SPACOORDCOD_LSP_2D:
        case SRM_SPACOORDCOD_LSR_2D:
            return true;

        default:
            return false;
    }
}


bool
RAIFCoordIs3D( SRM_Spatial_Coordinate_Code coord_code)
{
    switch (coord_code)
    {
        case SRM_SPACOORDCOD_CC_3D:
        case SRM_SPACOORDCOD_CD_3D:
        case SRM_SPACOORDCOD_CM_3D:
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
        case SRM_SPACOORDCOD_EI_3D:
        case SRM_SPACOORDCOD_HAEC_3D:
        case SRM_SPACOORDCOD_HEEC_3D:
        case SRM_SPACOORDCOD_HEEQ_3D:
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
        case SRM_SPACOORDCOD_LSR_3D:
        case SRM_SPACOORDCOD_LCE_3D:
        case SRM_SPACOORDCOD_LTSAS_3D:
        case SRM_SPACOORDCOD_LTSC_3D:
        case SRM_SPACOORDCOD_LTSE_3D:
        case SRM_SPACOORDCOD_M_AUGMENTED_3D:
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
        case SRM_SPACOORDCOD_PD_3D:
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
        case SRM_SPACOORDCOD_SEC_3D:
        case SRM_SPACOORDCOD_SEQ_3D:
        case SRM_SPACOORDCOD_SMD_3D:
        case SRM_SPACOORDCOD_SME_3D:
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
            return true;

        default:
            return false;
    }
}

bool
RAIFCoordIsSurface( SRM_Spatial_Coordinate_Code coord_code)
{

    switch (coord_code)
    {
        case SRM_SPACOORDCOD_CD_SURFACE:
        case SRM_SPACOORDCOD_EC_SURFACE:
        case SRM_SPACOORDCOD_LCC_SURFACE:
        case SRM_SPACOORDCOD_LTSAS_SURFACE:
        case SRM_SPACOORDCOD_LTSC_SURFACE:
        case SRM_SPACOORDCOD_LTSE_SURFACE:
        case SRM_SPACOORDCOD_M_SURFACE:
        case SRM_SPACOORDCOD_OMS_SURFACE:
        case SRM_SPACOORDCOD_PD_SURFACE:
        case SRM_SPACOORDCOD_PS_SURFACE:
        case SRM_SPACOORDCOD_TM_SURFACE:
            return true;

        default:
            return false;
    }
}


bool
RAIFCoordIsAngular( SRM_Spatial_Coordinate_Code coord_code)
{
    switch(coord_code)
   {
      case SRM_SPACOORDCOD_LSP_2D:
      case SRM_SPACOORDCOD_LSA_2D:
      case SRM_SPACOORDCOD_LTSC_3D:
      case SRM_SPACOORDCOD_LTSC_SURFACE:
      case SRM_SPACOORDCOD_CD_3D:
      case SRM_SPACOORDCOD_CD_SURFACE:
      case SRM_SPACOORDCOD_CM_3D:
      case SRM_SPACOORDCOD_EI_3D:
      case SRM_SPACOORDCOD_SEC_3D:
      case SRM_SPACOORDCOD_SEQ_3D:
      case SRM_SPACOORDCOD_SME_3D:
      case SRM_SPACOORDCOD_SMD_3D:
      case SRM_SPACOORDCOD_HAEC_3D:
      case SRM_SPACOORDCOD_HEEC_3D:
      case SRM_SPACOORDCOD_HEEQ_3D:
      case SRM_SPACOORDCOD_LTSAS_3D:
      case SRM_SPACOORDCOD_LTSAS_SURFACE:
            return true;

      default:
            return false;
    }
}

// get only the angular coordinates, return the number set 0,1,2 or 3
//
SRM_Integer
GetNumberOfAngularCoordValues( const SRM_Coordinate  *coord_in_ptr)
{
    SRM_Integer num_ang_coords=0;

    switch (coord_in_ptr->spatial_coord_code)
    {
        case SRM_SPACOORDCOD_LSP_2D:
        case SRM_SPACOORDCOD_LSA_2D:
        case SRM_SPACOORDCOD_LTSC_3D:
        case SRM_SPACOORDCOD_LTSC_SURFACE:
             num_ang_coords=1;
             break;
        case SRM_SPACOORDCOD_CD_3D:
        case SRM_SPACOORDCOD_CD_SURFACE:
        case SRM_SPACOORDCOD_CM_3D:
        case SRM_SPACOORDCOD_EI_3D:
        case SRM_SPACOORDCOD_SEC_3D:
        case SRM_SPACOORDCOD_SEQ_3D:
        case SRM_SPACOORDCOD_SME_3D:
        case SRM_SPACOORDCOD_SMD_3D:
        case SRM_SPACOORDCOD_HAEC_3D:
        case SRM_SPACOORDCOD_HEEC_3D:
        case SRM_SPACOORDCOD_HEEQ_3D:
        case SRM_SPACOORDCOD_LTSAS_3D:
        case SRM_SPACOORDCOD_LTSAS_SURFACE:
             num_ang_coords=2;
             break;
        default:
             num_ang_coords=0;
             break;
    }
    return num_ang_coords;
}


// can also use this as a way to map just the coordinate codes by ignoring
// the coordinate values.
//
SRM_Status_Code
CreateCoordinate3DFrom2D
(
    const SRM_Coordinate *coord2d,
          SRM_Coordinate *coord3d,
          SRM_Long_Float  elev
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (coord2d->spatial_coord_code)
    {
        case SRM_SPACOORDCOD_LSA_2D :
             fprintf(stderr, "SRM_SPACOORDCOD_LSA_2D has no corresponding 3D coordinate\n");
             status = SRM_STATCOD_INACTIONABLE;
             break;
        case SRM_SPACOORDCOD_CD_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_CD_3D;
             coord3d->coordinate.cd_3d.latitude =
                      coord2d->coordinate.cd_surface.latitude;
             coord3d->coordinate.cd_3d.longitude =
                      coord2d->coordinate.cd_surface.longitude;
             coord3d->coordinate.cd_3d.ellipsoidal_height = elev;
             break;
        case SRM_SPACOORDCOD_EC_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_EC_AUGMENTED_3D;
             coord3d->coordinate.ec_aug_3d.easting =
                      coord2d->coordinate.ec_surface.easting;
             coord3d->coordinate.ec_aug_3d.northing =
                      coord2d->coordinate.ec_surface.northing;
             coord3d->coordinate.ec_aug_3d.ellipsoidal_height = elev;
             break;
        case SRM_SPACOORDCOD_LCC_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_LCC_AUGMENTED_3D;
             coord3d->coordinate.lcc_aug_3d.easting =
                      coord2d->coordinate.lcc_surface.easting;
             coord3d->coordinate.lcc_aug_3d.northing =
                      coord2d->coordinate.lcc_surface.northing;
             coord3d->coordinate.lcc_aug_3d.ellipsoidal_height = elev;
             break;
        case SRM_SPACOORDCOD_LSR_2D :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_LSR_3D;
             coord3d->coordinate.lsr_3d.u=
                      coord2d->coordinate.lsr_2d.u;
             coord3d->coordinate.lsr_3d.v=
                      coord2d->coordinate.lsr_2d.v;
             coord3d->coordinate.lsr_3d.w= elev;
             break;
        case SRM_SPACOORDCOD_LTSAS_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_LTSAS_3D;
             coord3d->coordinate.ltsas_3d.azimuth =
                      coord2d->coordinate.ltsas_surface.azimuth;
             coord3d->coordinate.ltsas_3d.angle=
                      coord2d->coordinate.ltsas_surface.angle;
             coord3d->coordinate.ltsas_3d.radius = elev;
             break;
        case SRM_SPACOORDCOD_LTSC_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_LTSC_3D;
             coord3d->coordinate.ltsc_3d.angle =
                      coord2d->coordinate.ltsc_surface.angle;
             coord3d->coordinate.ltsc_3d.radius=
                      coord2d->coordinate.ltsc_surface.radius;
             coord3d->coordinate.ltsc_3d.height = elev;
             break;
        case SRM_SPACOORDCOD_LTSE_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_LTSE_3D;
             coord3d->coordinate.ltse_3d.x =
                      coord2d->coordinate.ltse_surface.x;
             coord3d->coordinate.ltse_3d.y =
                      coord2d->coordinate.ltse_surface.y;
             coord3d->coordinate.ltse_3d.height = elev;
             break;
        case SRM_SPACOORDCOD_OMS_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_OMS_AUGMENTED_3D;
             coord3d->coordinate.oms_aug_3d.easting =
                      coord2d->coordinate.oms_surface.easting;
             coord3d->coordinate.oms_aug_3d.northing =
                      coord2d->coordinate.oms_surface.northing;
             coord3d->coordinate.oms_aug_3d.ellipsoidal_height = elev;
             break;
        case SRM_SPACOORDCOD_M_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_M_AUGMENTED_3D;
             coord3d->coordinate.m_aug_3d.easting =
                      coord2d->coordinate.m_surface.easting;
             coord3d->coordinate.m_aug_3d.northing =
                      coord2d->coordinate.m_surface.northing;
             coord3d->coordinate.m_aug_3d.ellipsoidal_height = elev;
             break;
        case SRM_SPACOORDCOD_LSP_2D :
             fprintf(stderr,"SRM_COORD_CODE_POLAR has no corresponding 3D coordinate\n");
             status = SRM_STATCOD_INACTIONABLE;
             break;
        case SRM_SPACOORDCOD_PS_SURFACE :
             coord3d->spatial_coord_code = SRM_SPACOORDCOD_PS_AUGMENTED_3D;
             coord3d->coordinate.ps_aug_3d.easting =
                      coord2d->coordinate.ps_surface.easting;
             coord3d->coordinate.ps_aug_3d.northing =
                      coord2d->coordinate.ps_surface.northing;
             coord3d->coordinate.ps_aug_3d.ellipsoidal_height = elev;
             break;
        case SRM_SPACOORDCOD_TM_SURFACE :
             coord3d->spatial_coord_code  = SRM_SPACOORDCOD_TM_AUGMENTED_3D;
             coord3d->coordinate.tm_aug_3d.easting =
                      coord2d->coordinate.tm_surface.easting;
             coord3d->coordinate.tm_aug_3d.northing =
                      coord2d->coordinate.tm_surface.northing;
             coord3d->coordinate.tm_aug_3d.ellipsoidal_height = elev;
             break;
        default:
             fprintf(stderr,"CreateCoordinate3DFrom2D:"
                    "Unrecognized Coordinate Code\n");
             status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
             break;
    }
    return status;
}

// This used to be inplemented in the release
//
SRM_Status_Code
ConvertSearchBoundsDimensionality( const SE_Search_Bounds *src_ptr,
                                         SE_Search_Dimension  dimension,
                                         SE_Search_Bounds *dest_ptr)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (dimension == SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE &&
         RAIFCoordIs3D( src_ptr->minimum_point.spatial_coord_code))
    {
        if ((status=SRM_DeriveCoordinate2DFrom3D(&src_ptr->minimum_point,
            &dest_ptr->minimum_point)) != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr,"ConvertSearchBoundsDimensionality: "\
             "error - 2D or surface search dimension, can't derive "\
             "dest_ptr->minimum_point\n");
        }
        else if ((status=SRM_DeriveCoordinate2DFrom3D(&src_ptr->maximum_point,
                 &dest_ptr->maximum_point)) != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr,"ConvertSearchBoundsDimensionality: "\
             "error - 2D or surface search dimension, can't derive "\
             "dest_ptr->maximum_point\n");
        }
    }
    else if (dimension == SE_SEARCHDIM_THREE_DIMENSIONAL &&
             (RAIFCoordIs2D(src_ptr->minimum_point.spatial_coord_code) ||
              RAIFCoordIsSurface(src_ptr->minimum_point.spatial_coord_code)))
    {
        if ((status=CreateCoordinate3DFrom2D(&src_ptr->minimum_point,
            &dest_ptr->minimum_point, SE_NEGATIVE_INFINITY))
            != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr,"ConvertSearchBoundsDimensionality: "\
             "error - 3D search dimension, can't derive "\
             "dest_ptr->minimum_point\n");
        }
        else if ((status=CreateCoordinate3DFrom2D( &src_ptr->maximum_point,
                 &dest_ptr->maximum_point, SE_NEGATIVE_INFINITY))
                 != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr,"ConvertSearchBoundsDimensionality: "\
             "error - 3D search dimension, can't derive "\
             "dest_ptr->maximum_point\n");
        }
    }
    else
    {
        *dest_ptr = *src_ptr;
    }
    return status;
} /* end SE_ConvertSearchBoundsDimensionality */


static SRM_Status_Code
RAIFVerticalOffset
(
    const RAIF_SRF_Wrapper *my_srf,
    const SRM_Coordinate   *old_coord,
          SRM_DSS_Code      dss_code,
          SRM_Long_Float   *vertical_offset_ptr
)
{
    SRM_Status_Code       status = SRM_STATCOD_SUCCESS;
    SRM_SurfaceCoordinate temp_surf_src_coord;

    *vertical_offset_ptr = 0.0;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIODETIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_CD_3D)
             {
                 status = ((SRM_Celestiodetic *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.cd_3d.longitude,
                              old_coord->coordinate.cd_3d.latitude,
                             &temp_surf_src_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_CD_SURFACE)
             {
                 status = ((SRM_Celestiodetic *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.cd_surface.longitude,
                              old_coord->coordinate.cd_surface.latitude,
                             &temp_surf_src_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }

             if (status == SRM_STATCOD_SUCCESS)
             {
                 status = ((SRM_Celestiodetic *)
                          (my_srf->srf))->methods->VerticalOffset
                          (
                              my_srf->srf,
                              dss_code,
                             &temp_surf_src_coord,
                              vertical_offset_ptr
                          );

                 if (((SRM_Celestiodetic *)(my_srf->srf))->methods->
                     DestroySurfaceCoordinate(my_srf->srf, &temp_surf_src_coord)
                     != SRM_STATCOD_SUCCESS)
                 {
                     // Do not reset function's status if this didn't succeed.
                     // Not being able to destroy temp_surf_src_coord isn't ideal,
                     // but doesn't invalidate the result.
                     err_handler->add_err_descr("RAIFVerticalOffset: Could not Destroy SurfaceCoordinate\n");
                 }
             }
             break;
        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_EC_AUGMENTED_3D)
             {
                 status = ((SRM_EquidistantCylindrical *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.ec_aug_3d.easting,
                              old_coord->coordinate.ec_aug_3d.northing,
                             &temp_surf_src_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_EC_SURFACE)
             {
                 status = ((SRM_EquidistantCylindrical *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.ec_surface.easting,
                              old_coord->coordinate.ec_surface.northing,
                             &temp_surf_src_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }

             if (status == SRM_STATCOD_SUCCESS)
             {
                 status = ((SRM_EquidistantCylindrical *)
                          (my_srf->srf))->methods->VerticalOffset
                          (
                              my_srf->srf,
                              dss_code,
                             &temp_surf_src_coord,
                              vertical_offset_ptr
                          );

                 if (((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->
                     DestroySurfaceCoordinate(my_srf->srf, &temp_surf_src_coord)
                     != SRM_STATCOD_SUCCESS)
                 {
                     // Do not reset function's status if this didn't succeed.
                     // Not being able to destroy temp_surf_src_coord isn't ideal,
                     // but doesn't invalidate the result.
                     err_handler->add_err_descr("RAIFVerticalOffset: Could not Destroy SurfaceCoordinate\n");
                 }
             }
             break;
        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LCC_AUGMENTED_3D)
             {
                 status = ((SRM_LambertConformalConic *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.lcc_aug_3d.easting,
                              old_coord->coordinate.lcc_aug_3d.northing,
                             &temp_surf_src_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LCC_SURFACE)
             {
                 status = ((SRM_LambertConformalConic *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.lcc_surface.easting,
                              old_coord->coordinate.lcc_surface.northing,
                             &temp_surf_src_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }

             if (status == SRM_STATCOD_SUCCESS)
             {
                 status = ((SRM_LambertConformalConic *)
                          (my_srf->srf))->methods->VerticalOffset
                          (
                              my_srf->srf,
                              dss_code,
                             &temp_surf_src_coord,
                              vertical_offset_ptr
                          );

                 if (((SRM_LambertConformalConic *)(my_srf->srf))->methods->
                     DestroySurfaceCoordinate(my_srf->srf, &temp_surf_src_coord)
                     != SRM_STATCOD_SUCCESS)
                 {
                     // Do not reset function's status if this didn't succeed.
                     // Not being able to destroy temp_surf_src_coord isn't ideal,
                     // but doesn't invalidate the result.
                     err_handler->add_err_descr("RAIFVerticalOffset: Could not Destroy SurfaceCoordinate\n");
                 }
             }
             break;
        case SRM_SRFTCOD_MERCATOR:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_M_AUGMENTED_3D)
             {
                 status = ((SRM_Mercator *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.m_aug_3d.easting,
                              old_coord->coordinate.m_aug_3d.northing,
                             &temp_surf_src_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_M_SURFACE)
             {
                 status = ((SRM_Mercator *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.m_surface.easting,
                              old_coord->coordinate.m_surface.northing,
                             &temp_surf_src_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }

             if (status == SRM_STATCOD_SUCCESS)
             {
                 status = ((SRM_Mercator *)
                          (my_srf->srf))->methods->VerticalOffset
                          (
                              my_srf->srf,
                              dss_code,
                             &temp_surf_src_coord,
                              vertical_offset_ptr
                          );

                 if (((SRM_Mercator *)(my_srf->srf))->methods->
                     DestroySurfaceCoordinate(my_srf->srf, &temp_surf_src_coord)
                     != SRM_STATCOD_SUCCESS)
                 {
                     // Do not reset function's status if this didn't succeed.
                     // Not being able to destroy temp_surf_src_coord isn't ideal,
                     // but doesn't invalidate the result.
                     err_handler->add_err_descr("RAIFVerticalOffset: Could not Destroy SurfaceCoordinate\n");
                 }
             }
             break;
        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_OMS_AUGMENTED_3D)
             {
                 status = ((SRM_ObliqueMercatorSpherical *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.oms_aug_3d.easting,
                              old_coord->coordinate.oms_aug_3d.northing,
                             &temp_surf_src_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_OMS_SURFACE)
             {
                 status = ((SRM_ObliqueMercatorSpherical *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.oms_surface.easting,
                              old_coord->coordinate.oms_surface.northing,
                             &temp_surf_src_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }

             if (status == SRM_STATCOD_SUCCESS)
             {
                 status = ((SRM_ObliqueMercatorSpherical *)
                          (my_srf->srf))->methods->VerticalOffset
                          (
                              my_srf->srf,
                              dss_code,
                             &temp_surf_src_coord,
                              vertical_offset_ptr
                          );

                 if (((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->
                     DestroySurfaceCoordinate(my_srf->srf, &temp_surf_src_coord)
                     != SRM_STATCOD_SUCCESS)
                 {
                     // Do not reset function's status if this didn't succeed.
                     // Not being able to destroy temp_surf_src_coord isn't ideal,
                     // but doesn't invalidate the result.
                     err_handler->add_err_descr("RAIFVerticalOffset: Could not Destroy SurfaceCoordinate\n");
                 }
             }
             break;
        case SRM_SRFTCOD_PLANETODETIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_PD_3D)
             {
                 status = ((SRM_Planetodetic *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.pd_3d.longitude,
                              old_coord->coordinate.pd_3d.latitude,
                             &temp_surf_src_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_PD_SURFACE)
             {
                 status = ((SRM_Planetodetic *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.pd_surface.longitude,
                              old_coord->coordinate.pd_surface.latitude,
                             &temp_surf_src_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }

             if (status == SRM_STATCOD_SUCCESS)
             {
                 status = ((SRM_Planetodetic *)
                          (my_srf->srf))->methods->VerticalOffset
                          (
                              my_srf->srf,
                              dss_code,
                             &temp_surf_src_coord,
                              vertical_offset_ptr
                          );

                 if (((SRM_Planetodetic *)(my_srf->srf))->methods->
                     DestroySurfaceCoordinate(my_srf->srf, &temp_surf_src_coord)
                     != SRM_STATCOD_SUCCESS)
                 {
                     // Do not reset function's status if this didn't succeed.
                     // Not being able to destroy temp_surf_src_coord isn't ideal,
                     // but doesn't invalidate the result.
                     err_handler->add_err_descr("RAIFVerticalOffset: Could not Destroy SurfaceCoordinate\n");
                 }
             }
             break;
        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_PS_AUGMENTED_3D)
             {
                 status = ((SRM_PolarStereographic *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.ps_aug_3d.easting,
                              old_coord->coordinate.ps_aug_3d.northing,
                             &temp_surf_src_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_PS_SURFACE)
             {
                 status = ((SRM_PolarStereographic *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.ps_surface.easting,
                              old_coord->coordinate.ps_surface.northing,
                             &temp_surf_src_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }

             if (status == SRM_STATCOD_SUCCESS)
             {
                 status = ((SRM_PolarStereographic *)
                          (my_srf->srf))->methods->VerticalOffset
                          (
                              my_srf->srf,
                              dss_code,
                             &temp_surf_src_coord,
                              vertical_offset_ptr
                          );

                 if (((SRM_PolarStereographic *)(my_srf->srf))->methods->
                     DestroySurfaceCoordinate(my_srf->srf, &temp_surf_src_coord)
                     != SRM_STATCOD_SUCCESS)
                 {
                     // Do not reset function's status if this didn't succeed.
                     // Not being able to destroy temp_surf_src_coord isn't ideal,
                     // but doesn't invalidate the result.
                     err_handler->add_err_descr("RAIFVerticalOffset: Could not Destroy SurfaceCoordinate\n");
                 }
             }
             break;
        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_TM_AUGMENTED_3D)
             {
                 status = ((SRM_TransverseMercator *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.tm_aug_3d.easting,
                              old_coord->coordinate.tm_aug_3d.northing,
                             &temp_surf_src_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_TM_SURFACE)
             {
                 status = ((SRM_TransverseMercator *)
                          (my_srf->srf))->methods->CreateSurfaceCoordinate
                          (
                              my_srf->srf,
                              old_coord->coordinate.tm_surface.easting,
                              old_coord->coordinate.tm_surface.northing,
                             &temp_surf_src_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }

             if (status == SRM_STATCOD_SUCCESS)
             {
                 status = ((SRM_TransverseMercator *)
                          (my_srf->srf))->methods->VerticalOffset
                          (
                              my_srf->srf,
                              dss_code,
                             &temp_surf_src_coord,
                              vertical_offset_ptr
                          );

                 if (((SRM_TransverseMercator *)(my_srf->srf))->methods->
                     DestroySurfaceCoordinate(my_srf->srf, &temp_surf_src_coord)
                     != SRM_STATCOD_SUCCESS)
                 {
                     // Do not reset function's status if this didn't succeed.
                     // Not being able to destroy temp_surf_src_coord isn't ideal,
                     // but doesn't invalidate the result.
                     err_handler->add_err_descr("RAIFVerticalOffset: Could not Destroy SurfaceCoordinate\n");
                 }
             }
             break;

        default:
            err_handler->add_err_descr("RAIFVerticalOffset: SRFT does not have ellipsoidal height\n");
            return status;
    }
    return status;
} // end RAIFVerticalOffset


SRM_Status_Code
RAIFChangeCoordSRFFromContextInfo
(
    const SE_SRF_Context_Info *src_srf_info,
    const SRM_Coordinate      *src_coord_in,
    const SE_SRF_Context_Info *dest_srf_info,
          SRM_Coordinate      *dest_coord_out
)
{
    SRM_Status_Code         status = SRM_STATCOD_SUCCESS;
    RAIF_SRF_Wrapper        src_srf, dest_srf;
    SRM_Coordinate          temp_src_coord, temp_dest_coord;

    //
    // BEGIN: ACTUAL CONVERSION USING SRM
    //
    if (RAIFCreateSRFWrapper(src_srf_info, &src_srf) != SRM_STATCOD_SUCCESS)
    {
        err_handler->add_err_descr( "RAIFChangeCoordSRFFromContextInfo: "\
           "Unable to initialize source SRF");
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (RAIFCreateSRFWrapper(dest_srf_info, &dest_srf) != SRM_STATCOD_SUCCESS)
    {
        err_handler->add_err_descr( "RAIFChangeCoordSRFFromContextInfo: "\
           "Unable to initialize destination SRF");
        RAIFDestroySRMObjectReference( &src_srf);
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        //
        // If a linear third coordinate value is being used, and a
        // dss_code is being used, correct for the source
        // vertical offset separation
        //
/*
        if ((num_angular_coord_values <= 2 && num_coord_values == 3) &&
            ((src_srf_info->use_dss_code) &&
             (src_srf_info->dss_code != SRM_DSSCOD_UNSPECIFIED)))
        {
            SRM_Long_Float        vertical_offset = 0.0;

            status = SRM_VerticalOffset(src_srf.srf, src_srf_info->dss_code,
                                        &temp_surf_src_coord, &vertical_offset);
        }
*/
        if (RAIFChangeCoordSRFFromSRF(&src_srf, &temp_src_coord,
            &dest_srf, &temp_dest_coord) != SRM_STATCOD_SUCCESS)
        {
            err_handler->add_err_descr( "RAIFChangeCoordSRFFromContextInfo: "\
            "RAIFChangeCoordSRFFromSRF failed, cannot convert SRM_Coordinate");
            status = SRM_STATCOD_INACTIONABLE;
        }
        RAIFDestroySRMObjectReference( &src_srf);
        RAIFDestroySRMObjectReference( &dest_srf);
    }
    return status;
}

// This function will take the src_srf and call the right function necessary
// to convert the coordinate.
// Based on the type of SRF given in the RAIF SRF struct use a switch
// statement to call the right method.
SRM_Status_Code
RAIFChangeCoordSRFFromSRF
(
    const RAIF_SRF_Wrapper *src_srf,
    const SRM_Coordinate   *src_coord_in,
    const RAIF_SRF_Wrapper *dest_srf,
          SRM_Coordinate   *dest_coord_out
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    bool            src_coord_is_3D =
                       RAIFCoordIs3D(src_coord_in->spatial_coord_code);
    SRM_Coordinate  temp_src_coord, temp_dest_coord;
    EDCS_Boolean    euc_same = EDCS_FALSE;
    SRM_Integer     num_angular_coord_values, num_coord_values;
    EDCS_Real_Value coord_val1, coord_val2;

    // Set the src_coord and then use it to convert into linear or angular values
    // Yes it is cheating because it is a union, so we can grab using the first
    temp_src_coord.spatial_coord_code = src_coord_in->spatial_coord_code;
    temp_src_coord.coordinate.cc_3d.u = src_coord_in->coordinate.cc_3d.u;
    temp_src_coord.coordinate.cc_3d.v = src_coord_in->coordinate.cc_3d.v;
    temp_src_coord.coordinate.cc_3d.w = src_coord_in->coordinate.cc_3d.w;

    // Determine how many coordinate values are angular and how many are linear
    // if there are angular measures then check that the units is valid and
    // use an EDCS function to convert the values to EUC_RADIAN

    num_coord_values = (RAIFCoordIs3D( src_coord_in->spatial_coord_code) ? 3 : 2);
    num_angular_coord_values = GetNumberOfAngularCoordValues( src_coord_in);

    // The SRM uses radians for all angular measures. If the src_srf_info
    // uses angular measures, and src_srf_info->angular_unit isn't EUC_RADIAN:
    // 1) check that it can be converted to EUC_RADIAN, then
    // 2) perform the conversion
    if ((num_angular_coord_values > 0) &&
        (src_srf->angular_unit != EUC_RADIAN))
    {
        if (EDCS_UnitsAreEquivalent( EUC_RADIAN,
            src_srf->angular_unit, &euc_same) != EDCS_SC_SUCCESS)
        {
            err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
               "EDCS_UnitsAreEquivalent failed");
            return SRM_STATCOD_INACTIONABLE;
        }
        else if (euc_same != EDCS_TRUE)
        {
            err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
               "srf_info has invalid angular unit");
            return SRM_STATCOD_INACTIONABLE;
        }
        else
        {
            coord_val1.unit  = src_srf->angular_unit;
            coord_val1.unit_scale = ESC_UNI;
            coord_val2.unit  = EUC_RADIAN;
            coord_val2.unit_scale = ESC_UNI;

            coord_val1.value = temp_src_coord.coordinate.cc_3d.u;

            if (EDCS_ConvertQuantityValue( &coord_val1, &coord_val2)
                                             == EDCS_SC_SUCCESS)
            {
                temp_src_coord.coordinate.cc_3d.u = coord_val2.value;
            }
            else
            {
                err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                    "Error converting 1st angular coord value to radians.");
                return SRM_STATCOD_INACTIONABLE;
            }

            // There aren't any srfs with 3 angular coordinates
            if (num_angular_coord_values > 1)
            {
                coord_val1.value = temp_src_coord.coordinate.cc_3d.v;

                if (EDCS_ConvertQuantityValue( &coord_val1, &coord_val2)
                                                 == EDCS_SC_SUCCESS)
                {
                    temp_src_coord.coordinate.cc_3d.v = coord_val2.value;
                }
                else
                {
                   err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                      "Error converting 2nd angular coord value to radians.");
                   return SRM_STATCOD_INACTIONABLE;
                }
            }
        }
    } // end convert angular measures to EUC_RADIAN

    // The SRM uses metres for all linear measures. If the src_srf_info
    // uses linear measures, and src_srf_info->linear_unit isn't EUC_METRE:
    // 1) check that the linear unit/scale can be converted to EUC_METRE, then
    // 2) perform the conversion
    if (((num_coord_values - num_angular_coord_values) > 0) &&
        ((src_srf->linear_unit != EUC_METRE) ||
         (src_srf->linear_scale != ESC_UNI)))
    {
       if (EDCS_UnitsAreEquivalent( EUC_METRE,
           src_srf->linear_unit, &euc_same) != EDCS_SC_SUCCESS)
       {
          err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
            "EDCS_UnitsAreEquivalent failed for linear unit");
          return SRM_STATCOD_INACTIONABLE;
       }
       else if (euc_same != EDCS_TRUE)
       {
          err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
             "srf_info has invalid linear unit");
          return SRM_STATCOD_INACTIONABLE;
       }
       else
       {
          coord_val1.unit  = src_srf->linear_unit;
          coord_val1.unit_scale = src_srf->linear_scale;
          coord_val2.unit  = EUC_METRE;
          coord_val2.unit_scale = ESC_UNI;

          // convert the first coordinate value to metres if its a linear value
          //
          if (num_angular_coord_values <= 0)
          {
             coord_val1.value = temp_src_coord.coordinate.cc_3d.u;

             if (EDCS_ConvertQuantityValue( &coord_val1, &coord_val2)
                                            == EDCS_SC_SUCCESS)
             {
                 temp_src_coord.coordinate.cc_3d.u = coord_val2.value;
             }
             else
             {
                err_handler->add_err_descr(
                     "RAIFChangeCoordSRFFromSRF: "\
                     "Error converting 1st angular coord value to radians.");
                return SRM_STATCOD_INACTIONABLE;
             }
          }

          // convert the second coordinate value to metres if its a linear value
          //
          if (num_angular_coord_values <= 1)
          {
             coord_val1.value = temp_src_coord.coordinate.cc_3d.v;

             if (EDCS_ConvertQuantityValue(&coord_val1, &coord_val2)
                                             == EDCS_SC_SUCCESS)
             {
                 temp_src_coord.coordinate.cc_3d.v = coord_val2.value;
             }
             else
             {
                err_handler->add_err_descr(
                     "RAIFChangeCoordSRFFromSRF: "\
                     "Error converting 2nd angular coord value to radians.");
                return SRM_STATCOD_INACTIONABLE;
             }
          }

          // convert the third coordinate value to metres if its a linear value
          //
          if (num_angular_coord_values <= 2 && num_coord_values == 3)
          {
             coord_val1.value = temp_src_coord.coordinate.cc_3d.w;

             if (EDCS_ConvertQuantityValue(&coord_val1, &coord_val2)
                                             == EDCS_SC_SUCCESS)
             {
                 temp_src_coord.coordinate.cc_3d.w = coord_val2.value;
             }
             else
             {
                err_handler->add_err_descr(
                      "RAIFChangeCoordSRFFromSRF: "\
                      "Error converting 2nd angular coord value to radians.");
                return SRM_STATCOD_INACTIONABLE;
             }
          }
       }
    } // end convert linear measures to EUC_METRE

    switch (dest_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_CC_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,
                    &target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                        "Could not create target Coordinate3D");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                        "Could not create source Coordinate3D");
                }
                else if ((status = ((SRM_Celestiocentric *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                       "Could not ChangeCoordinate3DSRF");
                }
                else if ((status = ((SRM_Celestiocentric *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord,
                    &(temp_dest_coord.coordinate.cc_3d.u),
                    &(temp_dest_coord.coordinate.cc_3d.v),
                    &(temp_dest_coord.coordinate.cc_3d.w))) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                       "Could not GetCoordinate3DValues");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf, &target_srm_coord)
                        != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                           "Could not Destroy target Coordinate3D");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord)
                        != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                           "Could not Destroy source Coordinate3D");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_CD_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_CD_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf,&temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_Celestiodetic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_CD_3D)
                    {
                        if ((status = ((SRM_Celestiodetic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.cd_3d.longitude, &temp_dest_coord.coordinate.cd_3d.latitude,
                            &temp_dest_coord.coordinate.cd_3d.ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_ellipsoidal_height = 0.0;

                        if ((status = ((SRM_Celestiodetic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.cd_surface.longitude, &temp_dest_coord.coordinate.cd_surface.latitude,
                            &dummy_ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_CM_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf,&temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_Celestiomagnetic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_Celestiomagnetic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.cm_3d.longitude,&temp_dest_coord.coordinate.cm_3d.latitude,
                    &temp_dest_coord.coordinate.cm_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_EI_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf,&temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_EquatorialInertial *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_EquatorialInertial *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.ei_3d.right_ascension,&temp_dest_coord.coordinate.ei_3d.declination,
                    &temp_dest_coord.coordinate.ei_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_EC_AUGMENTED_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_EC_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf,&temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_EquidistantCylindrical *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    SRM_Long_Float dummy_ellipsoidal_height = 0.0;

                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_EC_AUGMENTED_3D)
                    {
                        if ((status = ((SRM_EquidistantCylindrical *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ec_aug_3d.easting, &temp_dest_coord.coordinate.ec_aug_3d.northing,
                            &temp_dest_coord.coordinate.ec_aug_3d.ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        if ((status = ((SRM_EquidistantCylindrical *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ec_surface.easting, &temp_dest_coord.coordinate.ec_surface.northing,
                            &dummy_ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_HAEC_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_HeliosphericAriesEcliptic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_HeliosphericAriesEcliptic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.haec_3d.longitude, &temp_dest_coord.coordinate.haec_3d.latitude,
                    &temp_dest_coord.coordinate.haec_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_HEEC_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_HeliosphericEarthEcliptic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_HeliosphericEarthEcliptic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.heec_3d.longitude, &temp_dest_coord.coordinate.heec_3d.latitude,
                    &temp_dest_coord.coordinate.heec_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_HEEQ_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_HeliosphericEarthEquatorial *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_HeliosphericEarthEquatorial *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.heeq_3d.longitude, &temp_dest_coord.coordinate.heeq_3d.latitude,
                    &temp_dest_coord.coordinate.heeq_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LCC_AUGMENTED_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LCC_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_LambertConformalConic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    SRM_Long_Float dummy_ellipsoidal_height = 0.0;

                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_LCC_AUGMENTED_3D)
                    {
                        if ((status = ((SRM_LambertConformalConic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.lcc_aug_3d.easting, &temp_dest_coord.coordinate.lcc_aug_3d.northing,
                            &temp_dest_coord.coordinate.lcc_aug_3d.ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        if ((status = ((SRM_LambertConformalConic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.lcc_surface.easting, &temp_dest_coord.coordinate.lcc_surface.northing,
                            &dummy_ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
            {
                SRM_Coordinate2D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_LSA_2D;

                if ((status = RAIFCreateCoordinate2D(dest_srf,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate2D\n");
                }
                else if ((status = RAIFCreateCoordinate2D(src_srf,
                         temp_src_coord.coordinate.lsa_2d.azimuth,
                         temp_src_coord.coordinate.lsa_2d.radius,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate2D\n");
                }
                else if ((status = ((SRM_LocalSpaceAzimuthal *)(dest_srf->srf))->methods->ChangeCoordinate2DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate2D\n");
                }
                else if ((status = ((SRM_LocalSpaceAzimuthal *)(dest_srf->srf))->methods->GetCoordinate2DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.lsa_2d.azimuth, &temp_dest_coord.coordinate.lsa_2d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate2DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate2D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate2D\n");
                    }
                    if (RAIFDestroyCoordinate2D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate2D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
            {
                SRM_Coordinate2D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_LSP_2D;

                if ((status = RAIFCreateCoordinate2D(dest_srf,0,0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate2D\n");
                }
                else if ((status = RAIFCreateCoordinate2D(src_srf,
                         temp_src_coord.coordinate.lsp_2d.angle,
                         temp_src_coord.coordinate.lsp_2d.radius,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate2D\n");
                }
                else if ((status = ((SRM_LocalSpacePolar *)(dest_srf->srf))->methods->ChangeCoordinate2DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate2D\n");
                }
                else if ((status = ((SRM_LocalSpacePolar *)(dest_srf->srf))->methods->GetCoordinate2DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.lsp_2d.angle, &temp_dest_coord.coordinate.lsp_2d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate2DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate2D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate2D\n");
                    }
                    if (RAIFDestroyCoordinate2D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate2D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
            {
                SRM_Coordinate2D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_LSR_2D;

                if ((status = RAIFCreateCoordinate2D(dest_srf,0,0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate2D\n");
                }
                else if ((status = RAIFCreateCoordinate2D(src_srf,temp_src_coord.coordinate.lsr_2d.u,
                          temp_src_coord.coordinate.lsr_2d.v, &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate2D\n");
                }
                else if ((status = ((SRM_LocalSpaceRectangular2D *)(dest_srf->srf))->methods->ChangeCoordinate2DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate2D\n");
                }
                else if ((status = ((SRM_LocalSpaceRectangular2D *)(dest_srf->srf))->methods->GetCoordinate2DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.lsr_2d.u, &temp_dest_coord.coordinate.lsr_2d.v)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate2DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate2D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate2D\n");
                    }
                    if (RAIFDestroyCoordinate2D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate2D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LSR_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LSR_2D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_LocalSpaceRectangular3D *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_LSR_3D)
                    {
                        if ((status = ((SRM_LocalSpaceRectangular3D *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.lsr_3d.u, &temp_dest_coord.coordinate.lsr_3d.v,
                            &temp_dest_coord.coordinate.lsr_3d.w)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_w = 0.0;

                        if ((status = ((SRM_LocalSpaceRectangular3D *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.lsr_2d.u, &temp_dest_coord.coordinate.lsr_2d.v,
                            &dummy_w)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LTSAS_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LTSAS_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0,0,0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_LTSAS_3D)
                    {
                        if ((status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ltsas_3d.azimuth, &temp_dest_coord.coordinate.ltsas_3d.angle,
                            &temp_dest_coord.coordinate.ltsas_3d.radius)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_radius = 0.0;

                        if ((status=((SRM_LocalTangentSpaceAzimuthalSpherical *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ltsas_surface.azimuth, &temp_dest_coord.coordinate.ltsas_surface.angle,
                            &dummy_radius)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LTSC_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LTSC_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_LocalTangentSpaceCylindrical *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_LTSC_3D)
                    {
                        if ((status = ((SRM_LocalTangentSpaceCylindrical *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ltsc_3d.angle, &temp_dest_coord.coordinate.ltsc_3d.radius,
                            &temp_dest_coord.coordinate.ltsc_3d.height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_height = 0.0;

                        if ((status = ((SRM_LocalTangentSpaceCylindrical *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ltsc_surface.angle, &temp_dest_coord.coordinate.ltsc_surface.radius,
                            &dummy_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LTSE_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_LTSE_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_LocalTangentSpaceEuclidean *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_LTSE_3D)
                    {
                        if ((status = ((SRM_LocalTangentSpaceEuclidean *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ltse_3d.x, &temp_dest_coord.coordinate.ltse_3d.y,
                            &temp_dest_coord.coordinate.ltse_3d.height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_height = 0.0;

                        if ((status = ((SRM_LocalTangentSpaceEuclidean *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ltse_surface.x, &temp_dest_coord.coordinate.ltse_surface.y,
                            &dummy_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code =  SRM_SPACOORDCOD_LCE_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_LococentricEuclidean3D *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_LococentricEuclidean3D *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.lce_3d.u, &temp_dest_coord.coordinate.lce_3d.v,
                    &temp_dest_coord.coordinate.lce_3d.w)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_MERCATOR:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_M_AUGMENTED_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_M_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_Mercator *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_M_AUGMENTED_3D)
                    {
                        if ((status = ((SRM_Mercator *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.m_aug_3d.easting, &temp_dest_coord.coordinate.m_aug_3d.northing,
                            &temp_dest_coord.coordinate.m_aug_3d.ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_ellipsoidal_height = 0.0;

                        if ((status = ((SRM_Mercator *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.m_surface.easting, &temp_dest_coord.coordinate.m_surface.northing,
                            &dummy_ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_OMS_AUGMENTED_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_OMS_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_ObliqueMercatorSpherical *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_OMS_AUGMENTED_3D)
                    {
                        if ((status = ((SRM_ObliqueMercatorSpherical *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.oms_aug_3d.easting, &temp_dest_coord.coordinate.oms_aug_3d.northing,
                            &temp_dest_coord.coordinate.oms_aug_3d.ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_ellipsoidal_height = 0.0;

                        if ((status = ((SRM_ObliqueMercatorSpherical *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.oms_surface.easting, &temp_dest_coord.coordinate.oms_surface.northing,
                            &dummy_ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_PD_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_PD_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                    &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_Planetodetic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy target_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_PD_3D)
                    {
                        if ((status = ((SRM_Planetodetic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.pd_3d.longitude, &temp_dest_coord.coordinate.pd_3d.latitude,
                            &temp_dest_coord.coordinate.pd_3d.ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_ellipsoidal_height = 0.0;

                        if ((status = ((SRM_Planetodetic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.pd_surface.longitude, &temp_dest_coord.coordinate.pd_surface.latitude,
                            &dummy_ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                    {
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            {
                SRM_Coordinate3D target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_PS_AUGMENTED_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_PS_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_PolarStereographic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_PS_AUGMENTED_3D)
                    {
                        if ((status = ((SRM_PolarStereographic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ps_aug_3d.easting, &temp_dest_coord.coordinate.ps_aug_3d.northing,
                            &temp_dest_coord.coordinate.ps_aug_3d.ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_ellipsoidal_height = 0.0;

                        if ((status = ((SRM_PolarStereographic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.ps_surface.easting, &temp_dest_coord.coordinate.ps_surface.northing,
                            &dummy_ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_SEC_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_SolarEcliptic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_SolarEcliptic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.sec_3d.longitude, &temp_dest_coord.coordinate.sec_3d.latitude,
                    &temp_dest_coord.coordinate.sec_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_SEQ_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_SolarEquatorial *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_SolarEquatorial *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.seq_3d.longitude, &temp_dest_coord.coordinate.seq_3d.latitude,
                    &temp_dest_coord.coordinate.sec_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_SMD_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_SolarMagneticDipole *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_SolarMagneticDipole *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.smd_3d.longitude, &temp_dest_coord.coordinate.smd_3d.latitude,
                    &temp_dest_coord.coordinate.smd_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            {
                SRM_Coordinate3D  target_srm_coord, source_srm_coord;
                temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_SME_3D;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_SolarMagneticEcliptic *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if ((status = ((SRM_SolarMagneticEcliptic *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                    &target_srm_coord, &temp_dest_coord.coordinate.sme_3d.longitude, &temp_dest_coord.coordinate.sme_3d.latitude,
                    &temp_dest_coord.coordinate.sme_3d.radius)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                }
                else
                {
                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                    if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy source_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                    }
                }
            }
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            {
                SRM_Coordinate3D target_srm_coord, source_srm_coord;

                if (src_coord_is_3D)
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_TM_AUGMENTED_3D;
                else
                    temp_dest_coord.spatial_coord_code = SRM_SPACOORDCOD_TM_SURFACE;

                if ((status = RAIFCreateCoordinate3D(dest_srf,0.0,0.0,0.0,&target_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create target Coordinate3D\n");
                }
                else if ((status = RAIFCreateCoordinate3D(src_srf, &temp_src_coord,
                         &source_srm_coord)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not create source Coordinate3D\n");
                }
                else if ((status = ((SRM_TransverseMercator *)(dest_srf->srf))->methods->ChangeCoordinate3DSRF
                    (dest_srf->srf,src_srf->srf, &source_srm_coord, &target_srm_coord, NULL)) != SRM_STATCOD_SUCCESS)
                {
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not ChangeCoordinate3D\n");
                }
                else if (RAIFDestroyCoordinate3D(src_srf, &source_srm_coord) != SRM_STATCOD_SUCCESS)
                {
                    // Do not reset function's status if this didn't succeed.
                    // At this point we have calculated a good result; not
                    // being able to destroy source_srm_coord isn't ideal,
                    // but doesn't invalidate that result.
                    err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy source Coordinate3D\n");
                }

                if (status == SRM_STATCOD_SUCCESS)
                {
                    if (temp_dest_coord.spatial_coord_code == SRM_SPACOORDCOD_TM_AUGMENTED_3D)
                    {
                        if ((status = ((SRM_TransverseMercator *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.tm_aug_3d.easting,
                            &temp_dest_coord.coordinate.tm_aug_3d.northing,
                            &temp_dest_coord.coordinate.tm_aug_3d.ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }
                    else
                    {
                        SRM_Long_Float dummy_ellipsoidal_height = 0.0;

                        if ((status = ((SRM_TransverseMercator *)(dest_srf->srf))->methods->GetCoordinate3DValues(dest_srf->srf,
                            &target_srm_coord, &temp_dest_coord.coordinate.tm_surface.easting,
                            &temp_dest_coord.coordinate.tm_surface.northing,
                            &dummy_ellipsoidal_height)) != SRM_STATCOD_SUCCESS)
                        {
                            err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not GetCoordinate3DValues\n");
                        }
                    }

                    if (RAIFDestroyCoordinate3D(dest_srf,&target_srm_coord) != SRM_STATCOD_SUCCESS)
                    {
                        // Do not reset function's status if this didn't succeed.
                        // At this point we have calculated a good result; not
                        // being able to destroy target_srm_coord isn't ideal,
                        // but doesn't invalidate that result.
                        err_handler->add_err_descr("ChangeCoordSRFFromSRF: Could not Destroy target Coordinate3D\n");
                    }
                }
            }
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: Encountered undefined SRFT\n");
            break;
    }

    if (status != SRM_STATCOD_SUCCESS)
    {
        err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: Error in converting coordinate\n");
        return status;
    }

    //
    // END: ACTUAL CONVERSION USING SRM
    //

    //
    // tmp_dest_coord units are now in radians/meters so we need to convert
    // them back to the units of the dest srf_info and put it in the
    // dest_coord_out
    //

    // Determine how many are angular and how many are linear
    // if there are angular measures then check that the units are valid and
    // use an edcs function to convert the values to EUC_RADIAN
    //
    num_coord_values = (RAIFCoordIs3D( temp_dest_coord.spatial_coord_code) ? 3 : 2);
    num_angular_coord_values = GetNumberOfAngularCoordValues( &temp_dest_coord);

    dest_coord_out->spatial_coord_code = temp_dest_coord.spatial_coord_code;
    // these values will be reset below by unit conversion as needed
    dest_coord_out->coordinate.cc_3d.u = temp_dest_coord.coordinate.cc_3d.u;
    dest_coord_out->coordinate.cc_3d.v = temp_dest_coord.coordinate.cc_3d.v;
    dest_coord_out->coordinate.cc_3d.w = temp_dest_coord.coordinate.cc_3d.w;

    if ((num_angular_coord_values > 0) &&
        (dest_srf->angular_unit != EUC_RADIAN))
    {
       if (EDCS_UnitsAreEquivalent( EUC_RADIAN,
           dest_srf->angular_unit, &euc_same) != EDCS_SC_SUCCESS)
       {
          err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
             "EDCS_UnitsAreEquivalent failed (dest coord)");
          return SRM_STATCOD_INACTIONABLE;
       }
       else if (euc_same != EDCS_TRUE)
       {
          err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
             "srf_info has invalid angular unit (dest coord)");
          return SRM_STATCOD_INACTIONABLE;
       }
       else
       {
          coord_val1.unit       = EUC_RADIAN;
          coord_val1.unit_scale = ESC_UNI;
          coord_val2.unit       = dest_srf->angular_unit;
          coord_val2.unit_scale = ESC_UNI;

          // convert the first coordinate to radians
          //
          coord_val1.value = temp_dest_coord.coordinate.cc_3d.u;

          if (EDCS_ConvertQuantityValue(&coord_val1, &coord_val2)
                                          == EDCS_SC_SUCCESS)
          {
              dest_coord_out->coordinate.cc_3d.u = coord_val2.value;
          }
          else
          {
             err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                "Error converting 1st angular coord value to radians.");
             return SRM_STATCOD_INACTIONABLE;
          }

          if (num_angular_coord_values > 1)
          {
             coord_val1.value = temp_dest_coord.coordinate.cc_3d.v;

             if (EDCS_ConvertQuantityValue(&coord_val1, &coord_val2)
                                           == EDCS_SC_SUCCESS)
             {
                 dest_coord_out->coordinate.cc_3d.v = coord_val2.value;
             }
             else
             {
                err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                   "Error converting 2nd angular coord value to radians.");
                return SRM_STATCOD_INACTIONABLE;
             }
          }
       }
    }

    //
    // validate the linear units/scale and convert linear coordinates if needed
    //
    if ((num_coord_values - num_angular_coord_values > 0) &&
        ((dest_srf->linear_unit != EUC_METRE) ||
         (dest_srf->linear_scale != ESC_UNI)))
    {
       if (EDCS_UnitsAreEquivalent( EUC_METRE,
           dest_srf->linear_unit, &euc_same) != EDCS_SC_SUCCESS)
       {
          err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
             "EDCS_UnitsAreEquivalent failed for linear unit");
          status = SRM_STATCOD_INACTIONABLE;
       }
       else if (euc_same != EDCS_TRUE)
       {
          err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
             "srf_info has invalid linear unit");
          status = SRM_STATCOD_INACTIONABLE;
       }
       else
       {
          coord_val1.unit       = EUC_METRE;
          coord_val1.unit_scale = ESC_UNI;
          coord_val2.unit       = dest_srf->linear_unit;
          coord_val2.unit_scale = dest_srf->linear_scale;

          // convert the first coordinate value to metres if its a linear value
          //
          if (num_angular_coord_values <= 0)
          {
             coord_val1.value = temp_dest_coord.coordinate.cc_3d.u;

             if (EDCS_ConvertQuantityValue( &coord_val1, &coord_val2)
                                            == EDCS_SC_SUCCESS)
             {
                 dest_coord_out->coordinate.cc_3d.u = coord_val2.value;
             }
             else
             {
                err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                    "Error converting 1st angular coord value to radians.");
                return SRM_STATCOD_INACTIONABLE;
             }
          }

          // convert the second coordinate value to metres if its a linear value
          //
          if (num_angular_coord_values <= 1)
          {
             coord_val1.value = temp_dest_coord.coordinate.cc_3d.v;

             if (EDCS_ConvertQuantityValue( &coord_val1, &coord_val2)
                                              == EDCS_SC_SUCCESS)
             {
                 dest_coord_out->coordinate.cc_3d.v = coord_val2.value;
             }
             else
             {
                err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                   "Error converting 2nd angular coord value to radians.");
                return SRM_STATCOD_INACTIONABLE;
             }
          }

          // convert the third coordinate value to metres if its a linear value
          //
          if (num_angular_coord_values <= 2 &&
              num_coord_values == 3)
          {
             coord_val1.value = temp_dest_coord.coordinate.cc_3d.w;

             if (EDCS_ConvertQuantityValue( &coord_val1, &coord_val2)
                                              == EDCS_SC_SUCCESS)
             {
                 dest_coord_out->coordinate.cc_3d.w = coord_val2.value;
             }
             else
             {
                err_handler->add_err_descr("RAIFChangeCoordSRFFromSRF: "\
                   "Error converting 2nd angular coord value to radians.");
                status = SRM_STATCOD_INACTIONABLE;
             }
          }
       }
    }
    return status;
} // end RAIFChangeCoordSRFFromSRF


// Given the RAIF_SRF_Wrapper will call the right destroy method

SRM_Status_Code
RAIFDestroySRMObjectReference( RAIF_SRF_Wrapper *my_srf)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
            status = ((SRM_LocalSpaceAzimuthal *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
            status = ((SRM_LocalSpacePolar *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
            status = ((SRM_LocalSpaceRectangular2D *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->Destroy(my_srf->srf);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("DestroySRMObjectReference: Encountered undefined SRFT\n");
            break;
    }

    if(status != SRM_STATCOD_SUCCESS)
    {
        err_handler->add_err_descr("DestroySRMObjectReference: Unable to destroy SRF\n");
    }
    else
    {
        my_srf->srf = NULL;
    }
    return status;
}


// Create coordinate 2D.

SRM_Status_Code
RAIFCreateCoordinate2D
(
    const RAIF_SRF_Wrapper *my_srf,
          SRM_Long_Float    ord1,
          SRM_Long_Float    ord2,
          SRM_Coordinate2D *new_coord
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
            status = ((SRM_LocalSpaceAzimuthal *)(my_srf->srf))->methods->CreateCoordinate2D(my_srf->srf,
                ord1, ord2, new_coord);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
            status = ((SRM_LocalSpacePolar *)(my_srf->srf))->methods->CreateCoordinate2D(my_srf->srf,
                ord1, ord2, new_coord);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
            status = ((SRM_LocalSpaceRectangular2D *)(my_srf->srf))->methods->CreateCoordinate2D(my_srf->srf,
                ord1, ord2, new_coord);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFCreateCoordinate2D: Encountered undefined SRFT for 2D\n");
            break;
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFCreateCoordinate2D: Unable to create Coordinate2D\n");

    return status;
}



// Given the RAIF_SRF_Wrapper and the SRM_Coordinate, call
// the right SRF to create a coordinate 3D
SRM_Status_Code
RAIFCreateCoordinate3D
(
    const RAIF_SRF_Wrapper *my_srf,
    const SRM_Coordinate   *old_coord,
          SRM_Coordinate3D *new_coord
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_CC_3D)
             {
                 status = ((SRM_Celestiocentric *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.cc_3d.u,
                              old_coord->coordinate.cc_3d.v,
                              old_coord->coordinate.cc_3d.w,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_CELESTIODETIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_CD_3D)
             {
                 status = ((SRM_Celestiodetic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.cd_3d.longitude,
                              old_coord->coordinate.cd_3d.latitude,
                              old_coord->coordinate.cd_3d.ellipsoidal_height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_CD_SURFACE)
             {
                 status = ((SRM_Celestiodetic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.cd_surface.longitude,
                              old_coord->coordinate.cd_surface.latitude,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_CM_3D)
             {
                 status = ((SRM_Celestiomagnetic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.cm_3d.longitude,
                              old_coord->coordinate.cm_3d.latitude,
                              old_coord->coordinate.cm_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_EC_AUGMENTED_3D)
             {
                 status = ((SRM_EquidistantCylindrical *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ec_aug_3d.easting,
                              old_coord->coordinate.ec_aug_3d.northing,
                              old_coord->coordinate.ec_aug_3d.ellipsoidal_height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_EC_SURFACE)
             {
                 status = ((SRM_EquidistantCylindrical *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ec_surface.easting,
                              old_coord->coordinate.ec_surface.northing,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_EI_3D)
             {
                 status = ((SRM_EquatorialInertial *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ei_3d.right_ascension,
                              old_coord->coordinate.ei_3d.declination,
                              old_coord->coordinate.ei_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_HAEC_3D)
             {
                 status = ((SRM_HeliosphericAriesEcliptic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.haec_3d.longitude,
                              old_coord->coordinate.haec_3d.latitude,
                              old_coord->coordinate.haec_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_HEEC_3D)
             {
                 status = ((SRM_HeliosphericEarthEcliptic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.heec_3d.longitude,
                              old_coord->coordinate.heec_3d.latitude,
                              old_coord->coordinate.heec_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_HEEQ_3D)
             {
                 status = ((SRM_HeliosphericEarthEquatorial *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.heeq_3d.longitude,
                              old_coord->coordinate.heeq_3d.latitude,
                              old_coord->coordinate.heeq_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LCC_AUGMENTED_3D)
             {
                 status = ((SRM_LambertConformalConic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.lcc_aug_3d.easting,
                              old_coord->coordinate.lcc_aug_3d.northing,
                              old_coord->coordinate.lcc_aug_3d.ellipsoidal_height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LCC_SURFACE)
             {
                 status = ((SRM_LambertConformalConic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.lcc_aug_3d.easting,
                              old_coord->coordinate.lcc_aug_3d.northing,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LSR_3D)
             {
                 status = ((SRM_LocalSpaceRectangular3D *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.lsr_3d.u,
                              old_coord->coordinate.lsr_3d.v,
                              old_coord->coordinate.lsr_3d.w,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LSR_2D)
             {
                 status = ((SRM_LocalSpaceRectangular3D *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.lsr_3d.u,
                              old_coord->coordinate.lsr_3d.v,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LTSAS_3D)
             {
                 status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ltsas_3d.azimuth,
                              old_coord->coordinate.ltsas_3d.angle,
                              old_coord->coordinate.ltsas_3d.radius,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LTSAS_SURFACE)
             {
                 status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ltsas_surface.azimuth,
                              old_coord->coordinate.ltsas_surface.angle,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LTSC_3D)
             {
                 status = ((SRM_LocalTangentSpaceCylindrical *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ltsc_3d.angle,
                              old_coord->coordinate.ltsc_3d.radius,
                              old_coord->coordinate.ltsc_3d.height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LTSC_SURFACE)
             {
                 status = ((SRM_LocalTangentSpaceCylindrical *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ltsc_surface.angle,
                              old_coord->coordinate.ltsc_surface.radius,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LTSE_3D)
             {
                 status = ((SRM_LocalTangentSpaceEuclidean *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ltse_3d.x,
                              old_coord->coordinate.ltse_3d.y,
                              old_coord->coordinate.ltse_3d.height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LTSE_SURFACE)
             {
                 status = ((SRM_LocalTangentSpaceEuclidean *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ltse_surface.x,
                              old_coord->coordinate.ltse_surface.y,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_LCE_3D)
             {
                 status = ((SRM_LococentricEuclidean3D *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.lce_3d.u,
                              old_coord->coordinate.lce_3d.v,
                              old_coord->coordinate.lce_3d.w,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_MERCATOR:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_M_AUGMENTED_3D)
             {
                 status = ((SRM_Mercator *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.m_aug_3d.easting,
                              old_coord->coordinate.m_aug_3d.northing,
                              old_coord->coordinate.m_aug_3d.ellipsoidal_height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_M_SURFACE)
             {
                 status = ((SRM_Mercator *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.m_surface.easting,
                              old_coord->coordinate.m_surface.northing,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_OMS_AUGMENTED_3D)
             {
                 status = ((SRM_ObliqueMercatorSpherical *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.oms_aug_3d.easting,
                              old_coord->coordinate.oms_aug_3d.northing,
                              old_coord->coordinate.oms_aug_3d.ellipsoidal_height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_OMS_SURFACE)
             {
                 status = ((SRM_ObliqueMercatorSpherical *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.oms_surface.easting,
                              old_coord->coordinate.oms_surface.northing,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_PLANETODETIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_PD_3D)
             {
                 status = ((SRM_Planetodetic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.pd_3d.longitude,
                              old_coord->coordinate.pd_3d.latitude,
                              old_coord->coordinate.pd_3d.ellipsoidal_height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_PD_SURFACE)
             {
                 status = ((SRM_Planetodetic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.pd_surface.longitude,
                              old_coord->coordinate.pd_surface.latitude,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_PS_AUGMENTED_3D)
             {
                 status = ((SRM_PolarStereographic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ps_aug_3d.easting,
                              old_coord->coordinate.ps_aug_3d.northing,
                              old_coord->coordinate.ps_aug_3d.ellipsoidal_height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_PS_SURFACE)
             {
                 status = ((SRM_PolarStereographic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.ps_surface.easting,
                              old_coord->coordinate.ps_surface.northing,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_SEC_3D)
             {
                 status = ((SRM_SolarEcliptic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.sec_3d.longitude,
                              old_coord->coordinate.sec_3d.latitude,
                              old_coord->coordinate.sec_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_SEQ_3D)
             {
                 status = ((SRM_SolarEquatorial *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.seq_3d.longitude,
                              old_coord->coordinate.seq_3d.latitude,
                              old_coord->coordinate.seq_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_SMD_3D)
             {
                 status = ((SRM_SolarMagneticDipole *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.smd_3d.longitude,
                              old_coord->coordinate.smd_3d.latitude,
                              old_coord->coordinate.smd_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_SME_3D)
             {
                 status = ((SRM_SolarMagneticEcliptic *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.sme_3d.longitude,
                              old_coord->coordinate.sme_3d.latitude,
                              old_coord->coordinate.sme_3d.radius,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
             if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_TM_AUGMENTED_3D)
             {
                 status = ((SRM_TransverseMercator *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.tm_aug_3d.easting,
                              old_coord->coordinate.tm_aug_3d.northing,
                              old_coord->coordinate.tm_aug_3d.ellipsoidal_height,
                              new_coord
                          );
             }
             else if (old_coord->spatial_coord_code == SRM_SPACOORDCOD_TM_SURFACE)
             {
                 status = ((SRM_TransverseMercator *)
                          (my_srf->srf))->methods->CreateCoordinate3D
                          (
                              my_srf->srf,
                              old_coord->coordinate.tm_surface.easting,
                              old_coord->coordinate.tm_surface.northing,
                              0.0,
                              new_coord
                          );
             }
             else
             {
                 status = SRM_STATCOD_INACTIONABLE;
             }
             break;

        default:
             status = SRM_STATCOD_INACTIONABLE;
             err_handler->add_err_descr("RAIFCreateCoordinate3D: Encountered undefined SRFT\n");
             break;
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFCreateCoordinate3D: Unable to create Coordinate3D\n");

    return status;
}


// Given the RAIF_SRF_Wrapper and the three values will will call
// the right SRF to create a coordinate 3D

SRM_Status_Code
RAIFCreateCoordinate3D
(
    const RAIF_SRF_Wrapper *my_srf,
          SRM_Long_Float    ord1,
          SRM_Long_Float    ord2,
          SRM_Long_Float    ord3,
          SRM_Coordinate3D *new_coord
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->CreateCoordinate3D(my_srf->srf,
                ord1, ord2, ord3, new_coord);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFCreateCoordinate3D: Encountered undefined SRFT\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFCreateCoordinate3D: Unable to create Coordinate3D\n");

    return status;
}



// Destroy the coordinate 3D. Note this just deallocates the internal representation in the
// SRM API.

SRM_Status_Code
RAIFDestroyCoordinate3D( const RAIF_SRF_Wrapper *my_srf, SRM_Coordinate3D *my_coord)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
             status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                my_coord);
             break;

        case SRM_SRFTCOD_CELESTIODETIC:
             status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                            my_coord);
             break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
             status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                               my_coord);
             break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
             status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                    my_coord);
             break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
             status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                     my_coord);
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
             status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                        my_coord);
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
             status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                        my_coord);
             break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
             status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                          my_coord);
             break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
                status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                        my_coord);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
                status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                          my_coord);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
                status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                              my_coord);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
                status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                           my_coord);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
                status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                       my_coord);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                         my_coord);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                   my_coord);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                           my_coord);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                   my_coord);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                     my_coord);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                    my_coord);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                      my_coord);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                      my_coord);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                        my_coord);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->DestroyCoordinate3D(my_srf->srf,
                                                     my_coord);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("DestroySRMObjectReference: Encountered undefined SRFT for 3D\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFDestroySRMCoordinate3D: Unable to destroy Coordinate3D\n");

    return status;
}


// Destroy the coordinate 2D. Note this just deallocates the internal representation in the
// SRM API.

SRM_Status_Code
RAIFDestroyCoordinate2D( const RAIF_SRF_Wrapper *my_srf, SRM_Coordinate2D *my_coord)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
            status = ((SRM_LocalSpaceAzimuthal *)(my_srf->srf))->methods->DestroyCoordinate2D(my_srf->srf,
                                                      my_coord);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
            status = ((SRM_LocalSpacePolar *)(my_srf->srf))->methods->DestroyCoordinate2D(my_srf->srf,
                                                      my_coord);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
            status = ((SRM_LocalSpaceRectangular2D *)(my_srf->srf))->methods->DestroyCoordinate2D(my_srf->srf,
                                                          my_coord);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFDestroySRMCoordinate2D: Encountered undefined SRFT for 2D\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFDestroySRMCoordinate2D: Unable to destroy Coordinate2D\n");

    return status;
}


//
//
//  DIRECTION RELATED FUNCTIONS START HERE
//
//


// Given the RAIF_SRF_Wrapper and the three values will will call the right SRF to create a direction
SRM_Status_Code
RAIFCreateDirection( const RAIF_SRF_Wrapper *my_srf, const SRM_Coordinate3D *ref_coord, SRM_Long_Float ord1,
                     SRM_Long_Float ord2, SRM_Long_Float ord3, SRM_Direction *new_direction)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->CreateDirection(my_srf->srf,ref_coord,
                ord1, ord2, ord3, new_direction);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFCreateDirection: Encountered undefined SRFT\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFCreateDirection: Unable to create Direction3D\n");

    return status;
}


// Given two SRFs converts the src direction in the src SRF to the dest SRF in
// dest coord.
SRM_Status_Code
RAIFChangeDirectionSRF( const RAIF_SRF_Wrapper *src_srf,  const SRM_Direction *src_direction_in,
                        const RAIF_SRF_Wrapper *dest_srf, SRM_Direction *dest_direction_out)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (dest_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(src_srf->srf))->methods->ChangeDirectionSRF(dest_srf->srf,src_srf->srf,
                src_direction_in, dest_direction_out, NULL);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFChaneDirectionSRF: Encountered undefined SRFT\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFCreateDirection: Unable to create Direction3D\n");

    return status;
}


// Given the RAIF_SRF_Wrapper and the three values will will call the right SRF to get direction values
SRM_Status_Code
RAIFGetDirectionValues( const RAIF_SRF_Wrapper *my_srf, const SRM_Direction *my_direction, SRM_Coordinate3D *my_ref_coord,
                        SRM_Long_Float *ord1,SRM_Long_Float *ord2, SRM_Long_Float *ord3)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->GetDirectionValues(my_srf->srf, my_direction,
                        my_ref_coord, ord1, ord2, ord3);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFGetDirectionValues: Encountered undefined SRFT\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFGetDirectionValues: Unable to get Direction values\n");

    return status;
}



// Given the RAIF_SRF_Wrapper will call the right destroy method for the direction
SRM_Status_Code
RAIFDestroyDirection( const RAIF_SRF_Wrapper *my_srf, SRM_Direction *my_direction)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                   my_direction);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                 my_direction);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                    my_direction);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                      my_direction);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                      my_direction);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                         my_direction);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                         my_direction);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                           my_direction);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                     my_direction);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                       my_direction);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                               my_direction);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                        my_direction);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                          my_direction);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                      my_direction);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                my_direction);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                        my_direction);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                my_direction);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                      my_direction);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                 my_direction);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                   my_direction);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                       my_direction);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                     my_direction);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->DestroyDirection(my_srf->srf,
                                                      my_direction);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFDestroyDirection: Encountered undefined SRFT for 3D\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFDestroyDirection: Unable to destroy Direction\n");

    return status;
}


//
//
//  DIRECTION RELATED FUNCTIONS END HERE
//
//



//
//
//  ORIENTATION RELATED FUNCTIONS START HERE
//
//

SRM_Status_Code
RAIFCreateOrientation( const RAIF_SRF_Wrapper *my_srf, const SRM_Coordinate3D *ref_coord,
                       SRM_Matrix_3x3 matrix, SRM_Orientation *new_orientation)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix, new_orientation);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix, new_orientation);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix, new_orientation);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->CreateOrientation(my_srf->srf,ref_coord,
                        matrix,new_orientation);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFCreateOrientation: Encountered undefined SRFT\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFCreateOrientation: Unable to create Orientation3D\n");

    return status;
}


// Given two SRFs converts the src orientation in the src SRF to the dest SRF in
// dest coord.
SRM_Status_Code
RAIFChangeOrientationSRF( const RAIF_SRF_Wrapper *src_srf,  const SRM_Orientation *src_orientation_in,
                          const RAIF_SRF_Wrapper *dest_srf, SRM_Orientation *dest_orientation_out)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (dest_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(src_srf->srf))->methods->ChangeOrientationSRF(dest_srf->srf,src_srf->srf,
                src_orientation_in, dest_orientation_out, NULL);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFChaneOrientationSRF: Encountered undefined SRFT\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFCreateOrientation: Unable to create Orientation3D\n");

    return status;
}


// Given the RAIF_SRF_Wrapper and the three values will will call the right SRF to get orientation values
SRM_Status_Code
RAIFGetOrientationValues( const RAIF_SRF_Wrapper *my_srf, const SRM_Orientation *my_orientation,
                          SRM_Coordinate3D *my_ref_coord, SRM_Matrix_3x3 * matrix)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->GetOrientationValues(my_srf->srf, my_orientation,
                        my_ref_coord, matrix);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFGetOrientationValues: Encountered undefined SRFT\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFGetOrientationValues: Unable to get Orientation values\n");

    return status;
}



// Given the RAIF_SRF_Wrapper will call the right destroy method for the orientation
SRM_Status_Code
RAIFDestroyOrientation( const RAIF_SRF_Wrapper *my_srf, SRM_Orientation *my_orientation)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    switch (my_srf->srft_code)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
            status = ((SRM_Celestiocentric *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                     my_orientation);
            break;

        case SRM_SRFTCOD_CELESTIODETIC:
            status = ((SRM_Celestiodetic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                   my_orientation);
            break;

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
            status = ((SRM_Celestiomagnetic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                      my_orientation);
            break;

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
            status = ((SRM_EquatorialInertial *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                    my_orientation);
            break;

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
            status = ((SRM_EquidistantCylindrical *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                        my_orientation);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
            status = ((SRM_HeliosphericAriesEcliptic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                           my_orientation);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
            status = ((SRM_HeliosphericEarthEcliptic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                           my_orientation);
            break;

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
            status = ((SRM_HeliosphericEarthEquatorial *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                         my_orientation);
            break;

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
            status = ((SRM_LambertConformalConic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                       my_orientation);
            break;

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
            status = ((SRM_LocalSpaceRectangular3D *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                         my_orientation);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
            status = ((SRM_LocalTangentSpaceAzimuthalSpherical *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                             my_orientation);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
            status = ((SRM_LocalTangentSpaceCylindrical *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                          my_orientation);
            break;

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
            status = ((SRM_LocalTangentSpaceEuclidean *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                        my_orientation);
            break;

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
            status = ((SRM_LococentricEuclidean3D *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                        my_orientation);
            break;

        case SRM_SRFTCOD_MERCATOR:
            status = ((SRM_Mercator *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                  my_orientation);
            break;

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
            status = ((SRM_ObliqueMercatorSpherical *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                          my_orientation);
            break;

        case SRM_SRFTCOD_PLANETODETIC:
            status = ((SRM_Planetodetic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                  my_orientation);
            break;

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
            status = ((SRM_PolarStereographic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                    my_orientation);
            break;

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
            status = ((SRM_SolarEcliptic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                   my_orientation);
            break;

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
            status = ((SRM_SolarEquatorial *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                     my_orientation);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
            status = ((SRM_SolarMagneticDipole *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                     my_orientation);
            break;

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
            status = ((SRM_SolarMagneticEcliptic *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                       my_orientation);
            break;

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
            status = ((SRM_TransverseMercator *)(my_srf->srf))->methods->DestroyOrientation(my_srf->srf,
                                                    my_orientation);
            break;

        default:
            status = SRM_STATCOD_INACTIONABLE;
            err_handler->add_err_descr("RAIFDestroyOrientation: Encountered undefined SRFT for 3D\n");
    }

    if(status != SRM_STATCOD_SUCCESS)
        err_handler->add_err_descr("RAIFDestroyOrientation: Unable to destroy Orientation\n");

    return status;
}


//
//
//  ORIENTATION RELATED FUNCTIONS END HERE
//
//
