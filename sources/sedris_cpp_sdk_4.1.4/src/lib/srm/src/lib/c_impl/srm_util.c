/*
 * FILE       : srm_util.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Various useful functions.
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

#include <stdio.h>
#include <math.h>
#include <string.h> /* for memcpy() */
#include "srm.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_GetVersionInformation
 *
 *-----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_GetVersionInformation
(
    SRM_Integer_Positive *major_SRM_version,
    SRM_Integer_Unsigned *minor_SRM_version,
    char                 *interim_SRM_version
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!major_SRM_version || !minor_SRM_version || !interim_SRM_version)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        *major_SRM_version   = SRM_MAJOR_VERSION;
        *minor_SRM_version   = SRM_MINOR_VERSION;
        *interim_SRM_version = SRM_INTERIM_VERSION;
    }
    return status;
} /* end SRM_GetVersionInformation */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_CoordinateEqual
 *
 *-----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_CoordinateEqual
(
    const SRM_Coordinate *a_ptr,
    const SRM_Coordinate *b_ptr,
          SRM_Boolean    *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (!a_ptr || !b_ptr)
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else if (a_ptr->spatial_coord_code != b_ptr->spatial_coord_code)
    {
        *result_out_ptr = SRM_FALSE;
        status = SRM_STATCOD_OPERATION_UNSUPPORTED;
    }
    else
    {
        *result_out_ptr = SRM_FALSE;
        switch (a_ptr->spatial_coord_code)
        {
            case SRM_SPACOORDCOD_CC_3D:
                if ((a_ptr->coordinate.cc_3d.u == b_ptr->coordinate.cc_3d.u)
                 && (a_ptr->coordinate.cc_3d.v == b_ptr->coordinate.cc_3d.v)
                 && (a_ptr->coordinate.cc_3d.w == b_ptr->coordinate.cc_3d.w))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_CD_3D:
                if ((a_ptr->coordinate.cd_3d.ellipsoidal_height ==
                     b_ptr->coordinate.cd_3d.ellipsoidal_height)
                 && (a_ptr->coordinate.cd_3d.latitude ==
                     b_ptr->coordinate.cd_3d.latitude)
                 && (a_ptr->coordinate.cd_3d.longitude ==
                     b_ptr->coordinate.cd_3d.longitude))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_CD_SURFACE:
                if ((a_ptr->coordinate.cd_surface.latitude ==
                     b_ptr->coordinate.cd_surface.latitude)
                 && (a_ptr->coordinate.cd_surface.longitude ==
                     b_ptr->coordinate.cd_surface.longitude))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_CM_3D:
                if ((a_ptr->coordinate.cm_3d.latitude ==
                     b_ptr->coordinate.cm_3d.latitude)
                 && (a_ptr->coordinate.cm_3d.longitude ==
                     b_ptr->coordinate.cm_3d.longitude)
                 && (a_ptr->coordinate.cm_3d.radius ==
                     b_ptr->coordinate.cm_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
                if ((a_ptr->coordinate.ec_aug_3d.easting ==
                     b_ptr->coordinate.ec_aug_3d.easting)
                 && (a_ptr->coordinate.ec_aug_3d.ellipsoidal_height ==
                     b_ptr->coordinate.ec_aug_3d.ellipsoidal_height)
                 && (a_ptr->coordinate.ec_aug_3d.northing ==
                     b_ptr->coordinate.ec_aug_3d.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_EC_SURFACE:
                if ((a_ptr->coordinate.ec_surface.easting ==
                     b_ptr->coordinate.ec_surface.easting)
                 && (a_ptr->coordinate.ec_surface.northing ==
                     b_ptr->coordinate.ec_surface.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_EI_3D:
                if ((a_ptr->coordinate.ei_3d.declination ==
                     b_ptr->coordinate.ei_3d.declination)
                 && (a_ptr->coordinate.ei_3d.radius ==
                     b_ptr->coordinate.ei_3d.radius)
                 && (a_ptr->coordinate.ei_3d.right_ascension ==
                     b_ptr->coordinate.ei_3d.right_ascension))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_HAEC_3D:
                if ((a_ptr->coordinate.haec_3d.latitude ==
                     b_ptr->coordinate.haec_3d.latitude)
                 && (a_ptr->coordinate.haec_3d.longitude ==
                     b_ptr->coordinate.haec_3d.longitude)
                 && (a_ptr->coordinate.haec_3d.radius ==
                     b_ptr->coordinate.haec_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_HEEC_3D:
                if ((a_ptr->coordinate.heec_3d.latitude ==
                     b_ptr->coordinate.heec_3d.latitude)
                 && (a_ptr->coordinate.heec_3d.longitude ==
                     b_ptr->coordinate.heec_3d.longitude)
                 && (a_ptr->coordinate.heec_3d.radius ==
                     b_ptr->coordinate.heec_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_HEEQ_3D:
                if ((a_ptr->coordinate.heeq_3d.latitude ==
                     b_ptr->coordinate.heeq_3d.latitude)
                 && (a_ptr->coordinate.heeq_3d.longitude ==
                     b_ptr->coordinate.heeq_3d.longitude)
                 && (a_ptr->coordinate.heeq_3d.radius ==
                     b_ptr->coordinate.heeq_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
                if ((a_ptr->coordinate.lcc_aug_3d.easting ==
                     b_ptr->coordinate.lcc_aug_3d.easting)
                 && (a_ptr->coordinate.lcc_aug_3d.ellipsoidal_height ==
                     b_ptr->coordinate.lcc_aug_3d.ellipsoidal_height)
                 && (a_ptr->coordinate.lcc_aug_3d.northing ==
                     b_ptr->coordinate.lcc_aug_3d.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LCC_SURFACE:
                if ((a_ptr->coordinate.lcc_surface.easting ==
                     b_ptr->coordinate.lcc_surface.easting)
                 && (a_ptr->coordinate.lcc_surface.northing ==
                     b_ptr->coordinate.lcc_surface.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LSA_2D:
                if ((a_ptr->coordinate.lsa_2d.azimuth ==
                     b_ptr->coordinate.lsa_2d.azimuth)
                 && (a_ptr->coordinate.lsa_2d.radius ==
                     b_ptr->coordinate.lsa_2d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LSP_2D:
                if ((a_ptr->coordinate.lsp_2d.angle ==
                     b_ptr->coordinate.lsp_2d.angle)
                 && (a_ptr->coordinate.lsp_2d.radius ==
                     b_ptr->coordinate.lsp_2d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LSR_2D:
                if ((a_ptr->coordinate.lsr_2d.u ==
                     b_ptr->coordinate.lsr_2d.u)
                 && (a_ptr->coordinate.lsr_2d.v ==
                     b_ptr->coordinate.lsr_2d.v))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LSR_3D:
                if ((a_ptr->coordinate.lsr_3d.u ==
                     b_ptr->coordinate.lsr_3d.u)
                 && (a_ptr->coordinate.lsr_3d.v ==
                     b_ptr->coordinate.lsr_3d.v)
                 && (a_ptr->coordinate.lsr_3d.w ==
                     b_ptr->coordinate.lsr_3d.w))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LCE_3D:
                if ((a_ptr->coordinate.lce_3d.u ==
                     b_ptr->coordinate.lce_3d.u)
                 && (a_ptr->coordinate.lce_3d.v ==
                     b_ptr->coordinate.lce_3d.v)
                 && (a_ptr->coordinate.lce_3d.w ==
                     b_ptr->coordinate.lce_3d.w))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LTSAS_3D:
                if ((a_ptr->coordinate.ltsas_3d.angle ==
                     b_ptr->coordinate.ltsas_3d.angle)
                 && (a_ptr->coordinate.ltsas_3d.azimuth ==
                     b_ptr->coordinate.ltsas_3d.azimuth)
                 && (a_ptr->coordinate.ltsas_3d.radius ==
                     b_ptr->coordinate.ltsas_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LTSAS_SURFACE:
                if ((a_ptr->coordinate.ltsas_surface.angle ==
                     b_ptr->coordinate.ltsas_surface.angle)
                 && (a_ptr->coordinate.ltsas_surface.azimuth ==
                     b_ptr->coordinate.ltsas_surface.azimuth))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LTSC_3D:
                if ((a_ptr->coordinate.ltsc_3d.angle ==
                     b_ptr->coordinate.ltsc_3d.angle)
                 && (a_ptr->coordinate.ltsc_3d.height ==
                     b_ptr->coordinate.ltsc_3d.height)
                 && (a_ptr->coordinate.ltsc_3d.radius ==
                     b_ptr->coordinate.ltsc_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LTSC_SURFACE:
                if ((a_ptr->coordinate.ltsc_surface.angle ==
                     b_ptr->coordinate.ltsc_surface.angle)
                 && (a_ptr->coordinate.ltsc_surface.radius ==
                     b_ptr->coordinate.ltsc_surface.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LTSE_3D:
                if ((a_ptr->coordinate.ltse_3d.x ==
                     b_ptr->coordinate.ltse_3d.x)
                 && (a_ptr->coordinate.ltse_3d.y ==
                     b_ptr->coordinate.ltse_3d.y)
                 && (a_ptr->coordinate.ltse_3d.height ==
                     b_ptr->coordinate.ltse_3d.height))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_LTSE_SURFACE:
                if ((a_ptr->coordinate.ltse_surface.x ==
                     b_ptr->coordinate.ltse_surface.x)
                 && (a_ptr->coordinate.ltse_surface.y ==
                     b_ptr->coordinate.ltse_surface.y))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_M_AUGMENTED_3D:
                if ((a_ptr->coordinate.m_aug_3d.easting ==
                     b_ptr->coordinate.m_aug_3d.easting)
                 && (a_ptr->coordinate.m_aug_3d.ellipsoidal_height ==
                     b_ptr->coordinate.m_aug_3d.ellipsoidal_height)
                 && (a_ptr->coordinate.m_aug_3d.northing ==
                     b_ptr->coordinate.m_aug_3d.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_M_SURFACE:
                if ((a_ptr->coordinate.m_surface.easting ==
                     b_ptr->coordinate.m_surface.easting)
                 && (a_ptr->coordinate.m_surface.northing ==
                     b_ptr->coordinate.m_surface.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
                if ((a_ptr->coordinate.oms_aug_3d.easting ==
                     b_ptr->coordinate.oms_aug_3d.easting)
                 && (a_ptr->coordinate.oms_aug_3d.ellipsoidal_height ==
                     b_ptr->coordinate.oms_aug_3d.ellipsoidal_height)
                 && (a_ptr->coordinate.oms_aug_3d.northing ==
                     b_ptr->coordinate.oms_aug_3d.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_OMS_SURFACE:
                if ((a_ptr->coordinate.oms_surface.easting ==
                     b_ptr->coordinate.oms_surface.easting)
                 && (a_ptr->coordinate.oms_surface.northing ==
                     b_ptr->coordinate.oms_surface.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_PD_3D:
                if ((a_ptr->coordinate.pd_3d.ellipsoidal_height ==
                     b_ptr->coordinate.pd_3d.ellipsoidal_height)
                 && (a_ptr->coordinate.pd_3d.latitude ==
                     b_ptr->coordinate.pd_3d.latitude)
                 && (a_ptr->coordinate.pd_3d.longitude ==
                     b_ptr->coordinate.pd_3d.longitude))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_PD_SURFACE:
                if ((a_ptr->coordinate.pd_surface.latitude ==
                     b_ptr->coordinate.pd_surface.latitude)
                 && (a_ptr->coordinate.pd_surface.longitude ==
                     b_ptr->coordinate.pd_surface.longitude))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
                if ((a_ptr->coordinate.ps_aug_3d.easting ==
                     b_ptr->coordinate.ps_aug_3d.easting)
                 && (a_ptr->coordinate.ps_aug_3d.ellipsoidal_height ==
                     b_ptr->coordinate.ps_aug_3d.ellipsoidal_height)
                 && (a_ptr->coordinate.ps_aug_3d.northing ==
                     b_ptr->coordinate.ps_aug_3d.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_PS_SURFACE:
                if ((a_ptr->coordinate.ps_surface.easting ==
                     b_ptr->coordinate.ps_surface.easting)
                 && (a_ptr->coordinate.ps_surface.northing ==
                     b_ptr->coordinate.ps_surface.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_SEC_3D:
                if ((a_ptr->coordinate.sec_3d.latitude ==
                     b_ptr->coordinate.sec_3d.latitude)
                 && (a_ptr->coordinate.sec_3d.longitude ==
                     b_ptr->coordinate.sec_3d.longitude)
                 && (a_ptr->coordinate.sec_3d.radius ==
                     b_ptr->coordinate.sec_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_SEQ_3D:
                if ((a_ptr->coordinate.seq_3d.latitude ==
                     b_ptr->coordinate.seq_3d.latitude)
                 && (a_ptr->coordinate.seq_3d.longitude ==
                     b_ptr->coordinate.seq_3d.longitude)
                 && (a_ptr->coordinate.seq_3d.radius ==
                     b_ptr->coordinate.seq_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_SMD_3D:
                if ((a_ptr->coordinate.smd_3d.latitude ==
                     b_ptr->coordinate.smd_3d.latitude)
                 && (a_ptr->coordinate.smd_3d.longitude ==
                     b_ptr->coordinate.smd_3d.longitude)
                 && (a_ptr->coordinate.smd_3d.radius ==
                     b_ptr->coordinate.smd_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_SME_3D:
                if ((a_ptr->coordinate.sme_3d.latitude ==
                     b_ptr->coordinate.sme_3d.latitude)
                 && (a_ptr->coordinate.sme_3d.longitude ==
                     b_ptr->coordinate.sme_3d.longitude)
                 && (a_ptr->coordinate.sme_3d.radius ==
                     b_ptr->coordinate.sme_3d.radius))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
                if ((a_ptr->coordinate.tm_aug_3d.easting ==
                     b_ptr->coordinate.tm_aug_3d.easting)
                 && (a_ptr->coordinate.tm_aug_3d.ellipsoidal_height ==
                     b_ptr->coordinate.tm_aug_3d.ellipsoidal_height)
                 && (a_ptr->coordinate.tm_aug_3d.northing ==
                     b_ptr->coordinate.tm_aug_3d.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            case SRM_SPACOORDCOD_TM_SURFACE:
                if ((a_ptr->coordinate.tm_surface.easting ==
                     b_ptr->coordinate.tm_surface.easting)
                 && (a_ptr->coordinate.tm_surface.northing ==
                     b_ptr->coordinate.tm_surface.northing))
                {
                    *result_out_ptr = SRM_TRUE;
                }
                break;

            default:
                 status = SRM_STATCOD_OPERATION_UNSUPPORTED;
                 break;
        } /* end switch */
    }
    return status;
} /* end SRM_CoordinateEqual */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_DeriveCoordinate2DFrom3D
 *
 *-----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_DeriveCoordinate2DFrom3D
(
    const SRM_Coordinate *coord_3d_ptr,
          SRM_Coordinate *coord_2d_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!coord_2d_ptr)
    {
        status = SRM_STATCOD_INVALID_TARGET_COORDINATE;
    }
    else if (!coord_3d_ptr)
    {
        status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else
    {
        switch (coord_3d_ptr->spatial_coord_code)
        {
            case SRM_SPACOORDCOD_LSR_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_LSR_2D;
                coord_2d_ptr->coordinate.lsr_2d.u = coord_3d_ptr->coordinate.lsr_3d.u;
                coord_2d_ptr->coordinate.lsr_2d.v = coord_3d_ptr->coordinate.lsr_3d.v;
                break;
            case SRM_SPACOORDCOD_CD_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_CD_SURFACE;
                coord_2d_ptr->coordinate.cd_surface.longitude = coord_3d_ptr->coordinate.cd_3d.longitude;
                coord_2d_ptr->coordinate.cd_surface.latitude  = coord_3d_ptr->coordinate.cd_3d.latitude;
                break;
            case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_EC_SURFACE;
                coord_2d_ptr->coordinate.ec_surface.easting  = coord_3d_ptr->coordinate.ec_aug_3d.easting;
                coord_2d_ptr->coordinate.ec_surface.northing = coord_3d_ptr->coordinate.ec_aug_3d.northing;
                break;
            case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_LCC_SURFACE;
                coord_2d_ptr->coordinate.lcc_surface.easting  = coord_3d_ptr->coordinate.lcc_aug_3d.easting;
                coord_2d_ptr->coordinate.lcc_surface.northing = coord_3d_ptr->coordinate.lcc_aug_3d.northing;
                break;
            case SRM_SPACOORDCOD_M_AUGMENTED_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_M_SURFACE;
                coord_2d_ptr->coordinate.m_surface.easting  = coord_3d_ptr->coordinate.m_aug_3d.easting;
                coord_2d_ptr->coordinate.m_surface.northing = coord_3d_ptr->coordinate.m_aug_3d.northing;
                break;
            case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_OMS_SURFACE;
                coord_2d_ptr->coordinate.oms_surface.easting  = coord_3d_ptr->coordinate.oms_aug_3d.easting;
                coord_2d_ptr->coordinate.oms_surface.northing = coord_3d_ptr->coordinate.oms_aug_3d.northing;
                break;
            case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_PS_SURFACE;
                coord_2d_ptr->coordinate.ps_surface.easting  = coord_3d_ptr->coordinate.ps_aug_3d.easting;
                coord_2d_ptr->coordinate.ps_surface.northing = coord_3d_ptr->coordinate.ps_aug_3d.northing;
                break;
            case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_TM_SURFACE;
                coord_2d_ptr->coordinate.tm_surface.easting  = coord_3d_ptr->coordinate.tm_aug_3d.easting;
                coord_2d_ptr->coordinate.tm_surface.northing = coord_3d_ptr->coordinate.tm_aug_3d.northing;
                break;
            case SRM_SPACOORDCOD_LTSAS_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_LTSAS_SURFACE;
                coord_2d_ptr->coordinate.ltsas_surface.azimuth = coord_3d_ptr->coordinate.ltsas_3d.azimuth;
                coord_2d_ptr->coordinate.ltsas_surface.angle   = coord_3d_ptr->coordinate.ltsas_3d.angle;
                break;
            case SRM_SPACOORDCOD_LTSC_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_LTSC_SURFACE;
                coord_2d_ptr->coordinate.ltsc_surface.angle  = coord_3d_ptr->coordinate.ltsc_3d.angle;
                coord_2d_ptr->coordinate.ltsc_surface.radius = coord_3d_ptr->coordinate.ltsc_3d.radius;
                break;
            case SRM_SPACOORDCOD_LTSE_3D:
                coord_2d_ptr->spatial_coord_code = SRM_SPACOORDCOD_LTSE_SURFACE;
                coord_2d_ptr->coordinate.ltse_surface.x = coord_3d_ptr->coordinate.ltse_3d.x;
                coord_2d_ptr->coordinate.ltse_surface.y = coord_3d_ptr->coordinate.ltse_3d.y;
                break;
            default:
                 status = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
                 break;
        }
    }
    return status;
} /* end SRM_DeriveCoordinate2DFrom3D*/


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_CrossProduct
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_CrossProduct
(
   const SRM_Vector_3D a_ptr,
   const SRM_Vector_3D b_ptr,
         SRM_Vector_3D result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!a_ptr || !b_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        result_out_ptr[0] = a_ptr[1] * b_ptr[2] - b_ptr[1] * a_ptr[2];
        result_out_ptr[1] = a_ptr[2] * b_ptr[0] - b_ptr[2] * a_ptr[0];
        result_out_ptr[2] = a_ptr[0] * b_ptr[1] - a_ptr[1] * b_ptr[0];
    }
    return status;
} /* end SRM_CrossProduct */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_DotProduct
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_DotProduct
(
   const SRM_Vector_3D   a_ptr,
   const SRM_Vector_3D   b_ptr,
         SRM_Long_Float *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!a_ptr || !b_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        (*result_out_ptr) = (a_ptr[0] * b_ptr[0]) +
                            (a_ptr[1] * b_ptr[1]) +
                            (a_ptr[2] * b_ptr[2]);
    }
    return status;
} /* end SRM_DotProduct */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToAxisDirection
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToAxisDirection
(
    const char *enum_name_in_ptr,
          SRM_Axis_Direction *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_AXDIR_POSITIVE_PRIMARY_AXIS") == 0)
    {
        *result_out_ptr = SRM_AXDIR_POSITIVE_PRIMARY_AXIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_AXDIR_POSITIVE_SECONDARY_AXIS") == 0)
    {
        *result_out_ptr = SRM_AXDIR_POSITIVE_SECONDARY_AXIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_AXDIR_POSITIVE_TERTIARY_AXIS") == 0)
    {
        *result_out_ptr = SRM_AXDIR_POSITIVE_TERTIARY_AXIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_AXDIR_NEGATIVE_PRIMARY_AXIS") == 0)
    {
        *result_out_ptr = SRM_AXDIR_NEGATIVE_PRIMARY_AXIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_AXDIR_NEGATIVE_SECONDARY_AXIS") == 0)
    {
        *result_out_ptr = SRM_AXDIR_NEGATIVE_SECONDARY_AXIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_AXDIR_NEGATIVE_TERTIARY_AXIS") == 0)
    {
        *result_out_ptr = SRM_AXDIR_NEGATIVE_TERTIARY_AXIS;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToAxisDirection */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToBoolean
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToBoolean
(
    const char *enum_name_in_ptr,
          SRM_Boolean *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_FALSE") == 0)
    {
        *result_out_ptr = SRM_FALSE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_TRUE") == 0)
    {
        *result_out_ptr = SRM_TRUE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToBoolean */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToCoordinateValidRegion
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToCoordinateValidRegion
(
    const char *enum_name_in_ptr,
          SRM_Coordinate_Valid_Region *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_COORDVALRGN_VALID") == 0)
    {
        *result_out_ptr = SRM_COORDVALRGN_VALID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_COORDVALRGN_EXTENDED_VALID") == 0)
    {
        *result_out_ptr = SRM_COORDVALRGN_EXTENDED_VALID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_COORDVALRGN_DEFINED") == 0)
    {
        *result_out_ptr = SRM_COORDVALRGN_DEFINED;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToCoordinateValidRegion */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToCSCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToCSCode
(
    const char *enum_name_in_ptr,
          SRM_CS_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_CSCOD_", 10) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_UNSPECIFIED") == 0)
    {
        *result_out_ptr = SRM_CSCOD_UNSPECIFIED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_EUCLIDEAN_3D") == 0)
    {
        *result_out_ptr = SRM_CSCOD_EUCLIDEAN_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_SPHERICAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_SPHERICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_SPHERICAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_SPHERICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_AZIMUTHAL_SPHERICAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_AZIMUTHAL_SPHERICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL_SPHERICAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL_SPHERICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_GEODETIC") == 0)
    {
        *result_out_ptr = SRM_CSCOD_GEODETIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_PLANETODETIC") == 0)
    {
        *result_out_ptr = SRM_CSCOD_PLANETODETIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_CYLINDRICAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_CYLINDRICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_CYLINDRICAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_CYLINDRICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_MERCATOR") == 0)
    {
        *result_out_ptr = SRM_CSCOD_MERCATOR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_OBLIQUE_MERCATOR_SPHERICAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_OBLIQUE_MERCATOR_SPHERICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_TRANSVERSE_MERCATOR") == 0)
    {
        *result_out_ptr = SRM_CSCOD_TRANSVERSE_MERCATOR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LAMBERT_CONFORMAL_CONIC") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LAMBERT_CONFORMAL_CONIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_POLAR_STEREOGRAPHIC") == 0)
    {
        *result_out_ptr = SRM_CSCOD_POLAR_STEREOGRAPHIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_EQUIDISTANT_CYLINDRICAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_EQUIDISTANT_CYLINDRICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_SURFACE_GEODETIC") == 0)
    {
        *result_out_ptr = SRM_CSCOD_SURFACE_GEODETIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_SURFACE_PLANETODETIC") == 0)
    {
        *result_out_ptr = SRM_CSCOD_SURFACE_PLANETODETIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_SURFACE_EUCLIDEAN") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_SURFACE_EUCLIDEAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_SURFACE_AZIMUTHAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_SURFACE_AZIMUTHAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_SURFACE_POLAR") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_SURFACE_POLAR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_EUCLIDEAN_2D") == 0)
    {
        *result_out_ptr = SRM_CSCOD_EUCLIDEAN_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_2D") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_AZIMUTHAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_AZIMUTHAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_POLAR") == 0)
    {
        *result_out_ptr = SRM_CSCOD_POLAR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_LOCOCENTRIC_POLAR") == 0)
    {
        *result_out_ptr = SRM_CSCOD_LOCOCENTRIC_POLAR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_CSCOD_EUCLIDEAN_1D") == 0)
    {
        *result_out_ptr = SRM_CSCOD_EUCLIDEAN_1D;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToCSCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToDSSCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToDSSCode
(
    const char *enum_name_in_ptr,
          SRM_DSS_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_DSSCOD_", 11) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_UNSPECIFIED") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_UNSPECIFIED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_EGM96_GEOID") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_EGM96_GEOID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_IGLD_1955") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_IGLD_1955;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_IGLD_1985") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_IGLD_1985;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_MSL") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_MSL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_NAVD_1988") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_NAVD_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_NGVD_1929") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_NGVD_1929;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_OSGM_2002") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_OSGM_2002;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_WGS84_ELLIPSOID") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_WGS84_ELLIPSOID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_DSSCOD_EGM84_GEOID") == 0)
    {
        *result_out_ptr = SRM_DSSCOD_EGM84_GEOID;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToDSSCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToIntervalType
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToIntervalType
(
    const char *enum_name_in_ptr,
          SRM_Interval_Type *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_OPEN_INTERVAL") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_OPEN_INTERVAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_GE_LT_INTERVAL") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_GE_LT_INTERVAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_GT_LE_INTERVAL") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_GT_LE_INTERVAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_CLOSED_INTERVAL") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_CLOSED_INTERVAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_GT_SEMI_INTERVAL") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_GT_SEMI_INTERVAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_GE_SEMI_INTERVAL") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_GE_SEMI_INTERVAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_LT_SEMI_INTERVAL") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_LT_SEMI_INTERVAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_LE_SEMI_INTERVAL") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_LE_SEMI_INTERVAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_IVLTYP_UNBOUNDED") == 0)
    {
        *result_out_ptr = SRM_IVLTYP_UNBOUNDED;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToIntervalType */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToORMCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToORMCode
(
    const char *enum_name_in_ptr,
          SRM_ORM_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_ORMCOD_", 11) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EXPERIMENTAL_NGA_MAX") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EXPERIMENTAL_NGA_MAX;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_UNSPECIFIED") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_UNSPECIFIED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ABSTRACT_2D") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ABSTRACT_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ABSTRACT_3D") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ABSTRACT_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ADINDAN_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ADINDAN_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ADRASTEA_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ADRASTEA_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_AFGOOYE_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_AFGOOYE_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_AIN_EL_ABD_1970") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_AIN_EL_ABD_1970;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_AMALTHEA_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_AMALTHEA_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_AMERICAN_SAMOA_1962") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_AMERICAN_SAMOA_1962;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ANNA_1_1965") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ANNA_1_1965;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ANTIGUA_1943") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ANTIGUA_1943;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ARC_1950") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ARC_1950;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ARC_1960") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ARC_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ARIEL_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ARIEL_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ASCENSION_1958") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ASCENSION_1958;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ATLAS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ATLAS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_AUSTRALIAN_GEOD_1966") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_AUSTRALIAN_GEOD_1966;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_AUSTRALIAN_GEOD_1984") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_AUSTRALIAN_GEOD_1984;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BEACON_E_1945") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BEACON_E_1945;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BELINDA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BELINDA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BELLEVUE_IGN_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BELLEVUE_IGN_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BERMUDA_1957") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BERMUDA_1957;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BIANCA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BIANCA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BISSAU_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BISSAU_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BOGOTA_OBS_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BOGOTA_OBS_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_BUKIT_RIMPAH_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_BUKIT_RIMPAH_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CALLISTO_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CALLISTO_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CALYPSO_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CALYPSO_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CAMP_AREA_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CAMP_AREA_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CAMPO_INCHAUSPE_1969") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CAMPO_INCHAUSPE_1969;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CANTON_1966") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CANTON_1966;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CAPE_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CAPE_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CAPE_CANAVERAL_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CAPE_CANAVERAL_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CARTHAGE_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CARTHAGE_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CHARON_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CHARON_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CHATHAM_1971") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CHATHAM_1971;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CHUA_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CHUA_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_COAMPS_1998") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_COAMPS_1998;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CORDELIA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CORDELIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CORREGO_ALEGRE_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CORREGO_ALEGRE_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_CRESSIDA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_CRESSIDA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DABOLA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DABOLA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DECEPTION_1993") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DECEPTION_1993;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DEIMOS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DEIMOS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DESDEMONA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DESDEMONA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DESPINA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DESPINA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DIONE_1982") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DIONE_1982;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DJAKARTA_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DJAKARTA_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DOS_1968") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DOS_1968;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_DOS_71_4_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_DOS_71_4_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EARTH_INERTIAL_J2000r0") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EARTH_INERTIAL_J2000r0;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EARTH_SOLAR_ECLIPTIC") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EARTH_SOLAR_ECLIPTIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EARTH_SOLAR_EQUATORIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EARTH_SOLAR_EQUATORIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EARTH_SOLAR_MAG_DIPOLE") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EARTH_SOLAR_MAG_DIPOLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EARTH_SOLAR_MAGNETOSPHERIC") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EARTH_SOLAR_MAGNETOSPHERIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EASTER_1967") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EASTER_1967;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ENCELADUS_1994") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ENCELADUS_1994;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EPIMETHEUS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EPIMETHEUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EROS_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EROS_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ESTONIA_1937") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ESTONIA_1937;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ETRS_1989") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ETRS_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EUROPA_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EUROPA_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EUROPE_1950") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EUROPE_1950;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_EUROPE_1979") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_EUROPE_1979;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_FAHUD_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_FAHUD_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_FORT_THOMAS_1955") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_FORT_THOMAS_1955;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GALATEA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GALATEA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GAN_1970") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GAN_1970;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GANYMEDE_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GANYMEDE_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GASPRA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GASPRA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GDA_1994") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GDA_1994;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEODETIC_DATUM_1949") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEODETIC_DATUM_1949;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1945") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1945;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1950") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1950;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1955") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1955;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1960") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1965") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1965;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1970") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1970;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1975") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1975;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1980") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1980;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1985") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1985;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1990") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1990;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_1995") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_1995;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GEOMAGNETIC_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GEOMAGNETIC_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GRACIOSA_BASE_SW_1948") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GRACIOSA_BASE_SW_1948;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GUAM_1963") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GUAM_1963;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GUNONG_SEGARA_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GUNONG_SEGARA_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_GUX_1_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_GUX_1_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HELENE_1992") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HELENE_1992;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_J2000r0") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_J2000r0;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HELIO_EARTH_ECLIPTIC") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HELIO_EARTH_ECLIPTIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HELIO_EARTH_EQUATORIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HELIO_EARTH_EQUATORIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HERAT_NORTH_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HERAT_NORTH_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HERMANNSKOGEL_1871") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HERMANNSKOGEL_1871;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HJORSEY_1955") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HJORSEY_1955;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HONG_KONG_1963") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HONG_KONG_1963;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_HU_TZU_SHAN_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_HU_TZU_SHAN_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_IAPETUS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_IAPETUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_IDA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_IDA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_INDIAN_1916") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_INDIAN_1916;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_INDIAN_1954") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_INDIAN_1954;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_INDIAN_1956") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_INDIAN_1956;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_INDIAN_1960") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_INDIAN_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_INDIAN_1962") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_INDIAN_1962;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_INDIAN_1975") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_INDIAN_1975;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_INDONESIAN_1974") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_INDONESIAN_1974;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_IO_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_IO_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_IRELAND_1965") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_IRELAND_1965;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ISTS_061_1968") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ISTS_061_1968;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ISTS_073_1969") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ISTS_073_1969;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JANUS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JANUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JGD_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JGD_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JOHNSTON_1961") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JOHNSTON_1961;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JULIET_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JULIET_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JUPITER_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JUPITER_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JUPITER_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JUPITER_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JUPITER_MAGNETIC_1993") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JUPITER_MAGNETIC_1993;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JUPITER_SOLAR_ECLIPTIC") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JUPITER_SOLAR_ECLIPTIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JUPITER_SOLAR_EQUATORIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JUPITER_SOLAR_EQUATORIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JUPITER_SOLAR_MAG_DIPOLE") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JUPITER_SOLAR_MAG_DIPOLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_JUPITER_SOLAR_MAG_ECLIPTIC") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_JUPITER_SOLAR_MAG_ECLIPTIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_KANDAWALA_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_KANDAWALA_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_KERGUELEN_1949") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_KERGUELEN_1949;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_KERTAU_1948") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_KERTAU_1948;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_KOREAN_GEODETIC_1995") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_KOREAN_GEODETIC_1995;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_KUSAIE_1951") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_KUSAIE_1951;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_LARISSA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_LARISSA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_LC5_1961") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_LC5_1961;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_LEIGON_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_LEIGON_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_LIBERIA_1964") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_LIBERIA_1964;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_LUZON_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_LUZON_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_M_PORALOKO_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_M_PORALOKO_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MAHE_1971") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MAHE_1971;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MARCUS_STATION_1952") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MARCUS_STATION_1952;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MARS_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MARS_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MARS_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MARS_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MARS_SPHERE_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MARS_SPHERE_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MASS_1999") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MASS_1999;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MASSAWA_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MASSAWA_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MERCHICH_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MERCHICH_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MERCURY_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MERCURY_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MERCURY_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MERCURY_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_METIS_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_METIS_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MIDWAY_1961") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MIDWAY_1961;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MIMAS_1994") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MIMAS_1994;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MINNA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MINNA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MIRANDA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MIRANDA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MM5_1997") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MM5_1997;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MODTRAN_TROPICAL_1989") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MODTRAN_TROPICAL_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MONTSERRAT_1958") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MONTSERRAT_1958;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MOON_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MOON_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_N_AM_1927") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_N_AM_1927;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_N_AM_1983") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_N_AM_1983;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_N_SAHARA_1959") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_N_SAHARA_1959;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NAHRWAN_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NAHRWAN_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NAIAD_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NAIAD_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NAPARIMA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NAPARIMA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NEPTUNE_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NEPTUNE_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NEPTUNE_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NEPTUNE_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NEPTUNE_MAGNETIC_1993") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NEPTUNE_MAGNETIC_1993;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NOGAPS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NOGAPS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NTF_1896") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NTF_1896;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_NTF_1896_PM_PARIS") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_NTF_1896_PM_PARIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_OBERON_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_OBERON_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_OBSERV_METEORO_1939") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_OBSERV_METEORO_1939;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_OLD_EGYPTIAN_1907") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_OLD_EGYPTIAN_1907;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_OLD_HAWAIIAN_INT_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_OLD_HAWAIIAN_INT_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_OPHELIA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_OPHELIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_OSGB_1936") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_OSGB_1936;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PAN_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PAN_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PANDORA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PANDORA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PHOBOS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PHOBOS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PHOEBE_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PHOEBE_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PITCAIRN_1967") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PITCAIRN_1967;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PLUTO_1994") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PLUTO_1994;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PLUTO_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PLUTO_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_POINT_58_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_POINT_58_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_POINTE_NOIRE_1948") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_POINTE_NOIRE_1948;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PORTIA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PORTIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PORTO_SANTO_1936") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PORTO_SANTO_1936;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PROMETHEUS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PROMETHEUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PROTEUS_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PROTEUS_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PROV_S_AM_1956") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PROV_S_AM_1956;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PROV_S_CHILEAN_1963") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PROV_S_CHILEAN_1963;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PUCK_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PUCK_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PUERTO_RICO_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PUERTO_RICO_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_PULKOVO_1942") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_PULKOVO_1942;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_QATAR_NATIONAL_1974") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_QATAR_NATIONAL_1974;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_QORNOQ_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_QORNOQ_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_REUNION_1947") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_REUNION_1947;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_RGF_1993") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_RGF_1993;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_RHEA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_RHEA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ROME_1940") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ROME_1940;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ROME_1940_PM_ROME") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ROME_1940_PM_ROME;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ROSALIND_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ROSALIND_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_S_AM_1969") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_S_AM_1969;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_S_ASIA_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_S_ASIA_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_S_JTSK_1993") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_S_JTSK_1993;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_S42_PULKOVO") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_S42_PULKOVO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SANTO_DOS_1965") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SANTO_DOS_1965;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SAO_BRAZ_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SAO_BRAZ_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SAPPER_HILL_1943") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SAPPER_HILL_1943;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SATURN_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SATURN_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SATURN_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SATURN_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SATURN_MAGNETIC_1993") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SATURN_MAGNETIC_1993;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SCHWARZECK_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SCHWARZECK_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SELVAGEM_GRANDE_1938") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SELVAGEM_GRANDE_1938;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SIERRA_LEONE_1960") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SIERRA_LEONE_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SIRGAS_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SIRGAS_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_SUN_1992") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_SUN_1992;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TANANARIVE_OBS_1925") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TANANARIVE_OBS_1925;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TELESTO_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TELESTO_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TERN_1961") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TERN_1961;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TETHYS_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TETHYS_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_THALASSA_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_THALASSA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_THEBE_2000") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_THEBE_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TIMBALAI_EVEREST_1948") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TIMBALAI_EVEREST_1948;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TITAN_1982") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TITAN_1982;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TITANIA_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TITANIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TOKYO_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TOKYO_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TRISTAN_1968") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TRISTAN_1968;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_TRITON_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_TRITON_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_UMBRIEL_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_UMBRIEL_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_URANUS_1988") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_URANUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_URANUS_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_URANUS_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_URANUS_MAGNETIC_1993") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_URANUS_MAGNETIC_1993;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_VENUS_1991") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_VENUS_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_VENUS_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_VENUS_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_VITI_LEVU_1916") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_VITI_LEVU_1916;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_VOIROL_1874") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_VOIROL_1874;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_VOIROL_1874_PM_PARIS") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_VOIROL_1874_PM_PARIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_VOIROL_1960") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_VOIROL_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_VOIROL_1960_PM_PARIS") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_VOIROL_1960_PM_PARIS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_WAKE_1952") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_WAKE_1952;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_WAKE_ENIWETOK_1960") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_WAKE_ENIWETOK_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_WGS_1972") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_WGS_1972;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_WGS_1984") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_WGS_1984;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_YACARE_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_YACARE_1987;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMCOD_ZANDERIJ_1987") == 0)
    {
        *result_out_ptr = SRM_ORMCOD_ZANDERIJ_1987;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToORMCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToORMTCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToORMTCode
(
    const char *enum_name_in_ptr,
          SRM_ORMT_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_ORMTCOD_", 12) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_UNSPECIFIED") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_UNSPECIFIED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_BI_AXIS_ORIGIN_2D") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_BI_AXIS_ORIGIN_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_SPHERE") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_SPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_OBLATE_ELLIPSOID") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_OBLATE_ELLIPSOID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_PROLATE_ELLIPSOID") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_PROLATE_ELLIPSOID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_BI_AXIS_ORIGIN_3D") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_BI_AXIS_ORIGIN_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_SPHERE_ORIGIN") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_SPHERE_ORIGIN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_ORMTCOD_TRI_PLANE") == 0)
    {
        *result_out_ptr = SRM_ORMTCOD_TRI_PLANE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToORMTCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToPolarAspect
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToPolarAspect
(
    const char *enum_name_in_ptr,
          SRM_Polar_Aspect *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_PLRASP_NORTH") == 0)
    {
        *result_out_ptr = SRM_PLRASP_NORTH;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_PLRASP_SOUTH") == 0)
    {
        *result_out_ptr = SRM_PLRASP_SOUTH;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToPolarAspect */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToRDCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToRDCode
(
    const char *enum_name_in_ptr,
          SRM_RD_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_RDCOD_", 10) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ORIGIN_2D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ORIGIN_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_X_UNIT_POINT_2D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_X_UNIT_POINT_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_Y_UNIT_POINT_2D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_Y_UNIT_POINT_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ORIGIN_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ORIGIN_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_X_UNIT_POINT_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_X_UNIT_POINT_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_Y_UNIT_POINT_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_Y_UNIT_POINT_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_Z_UNIT_POINT_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_Z_UNIT_POINT_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_X_AXIS_2D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_X_AXIS_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_Y_AXIS_2D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_Y_AXIS_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_X_AXIS_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_X_AXIS_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_Y_AXIS_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_Y_AXIS_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_Z_AXIS_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_Z_AXIS_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_XY_PLANE_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_XY_PLANE_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_XZ_PLANE_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_XZ_PLANE_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_YZ_PLANE_3D") == 0)
    {
        *result_out_ptr = SRM_RDCOD_YZ_PLANE_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ADRASTEA_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ADRASTEA_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_AIRY_1830") == 0)
    {
        *result_out_ptr = SRM_RDCOD_AIRY_1830;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_AMALTHEA_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_AMALTHEA_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ANANKE_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ANANKE_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_APL_4r5_1968") == 0)
    {
        *result_out_ptr = SRM_RDCOD_APL_4r5_1968;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ARIEL_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ARIEL_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ATLAS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ATLAS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_AUSTRALIAN_NATIONAL_1966") == 0)
    {
        *result_out_ptr = SRM_RDCOD_AUSTRALIAN_NATIONAL_1966;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_AVERAGE_TERRESTRIAL_1977") == 0)
    {
        *result_out_ptr = SRM_RDCOD_AVERAGE_TERRESTRIAL_1977;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_BELINDA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_BELINDA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_BESSEL_1841_ETHIOPIA") == 0)
    {
        *result_out_ptr = SRM_RDCOD_BESSEL_1841_ETHIOPIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_BESSEL_1841_NAMIBIA") == 0)
    {
        *result_out_ptr = SRM_RDCOD_BESSEL_1841_NAMIBIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_BIANCA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_BIANCA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CALLISTO_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CALLISTO_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CALYPSO_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CALYPSO_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CARME_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CARME_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CHARON_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CHARON_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1858") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1858;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1858_MODIFIED") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1858_MODIFIED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1866") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1866;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1880") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1880;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1880_CAPE") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1880_CAPE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1880_FIJI") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1880_FIJI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1880_IGN") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1880_IGN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1880_PALESTINE") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1880_PALESTINE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CLARKE_1880_SYRIA") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CLARKE_1880_SYRIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_COAMPS_1998") == 0)
    {
        *result_out_ptr = SRM_RDCOD_COAMPS_1998;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CORDELIA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CORDELIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_CRESSIDA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_CRESSIDA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_DANISH_1876") == 0)
    {
        *result_out_ptr = SRM_RDCOD_DANISH_1876;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_DEIMOS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_DEIMOS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_DELAMBRE_1810") == 0)
    {
        *result_out_ptr = SRM_RDCOD_DELAMBRE_1810;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_DESDEMONA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_DESDEMONA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_DESPINA_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_DESPINA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_DIONE_1982") == 0)
    {
        *result_out_ptr = SRM_RDCOD_DIONE_1982;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ELARA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ELARA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ENCELADUS_1994") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ENCELADUS_1994;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EPIMETHEUS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EPIMETHEUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EROS_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EROS_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EUROPA_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EUROPA_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EVEREST_ADJ_1937") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EVEREST_ADJ_1937;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EVEREST_1948") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EVEREST_1948;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EVEREST_1956") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EVEREST_1956;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EVEREST_REVISED_1962") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EVEREST_REVISED_1962;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EVEREST_1969") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EVEREST_1969;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_EVEREST_BRUNEI_1967") == 0)
    {
        *result_out_ptr = SRM_RDCOD_EVEREST_BRUNEI_1967;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_FISCHER_1960") == 0)
    {
        *result_out_ptr = SRM_RDCOD_FISCHER_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_FISCHER_1968") == 0)
    {
        *result_out_ptr = SRM_RDCOD_FISCHER_1968;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_GALATEA_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_GALATEA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_GANYMEDE_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_GANYMEDE_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_GASPRA_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_GASPRA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_GRS_1967") == 0)
    {
        *result_out_ptr = SRM_RDCOD_GRS_1967;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_GRS_1980") == 0)
    {
        *result_out_ptr = SRM_RDCOD_GRS_1980;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_HELENE_1992") == 0)
    {
        *result_out_ptr = SRM_RDCOD_HELENE_1992;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_HELMERT_1906") == 0)
    {
        *result_out_ptr = SRM_RDCOD_HELMERT_1906;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_HIMALIA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_HIMALIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_HOUGH_1960") == 0)
    {
        *result_out_ptr = SRM_RDCOD_HOUGH_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_HYPERION_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_HYPERION_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_IAG_1975") == 0)
    {
        *result_out_ptr = SRM_RDCOD_IAG_1975;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_IAPETUS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_IAPETUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_IDA_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_IDA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_INDONESIAN_1974") == 0)
    {
        *result_out_ptr = SRM_RDCOD_INDONESIAN_1974;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_INTERNATIONAL_1924") == 0)
    {
        *result_out_ptr = SRM_RDCOD_INTERNATIONAL_1924;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_IO_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_IO_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_JANUS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_JANUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_JULIET_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_JULIET_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_JUPITER_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_JUPITER_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_KLEOPATRA_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_KLEOPATRA_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_KRASSOVSKY_1940") == 0)
    {
        *result_out_ptr = SRM_RDCOD_KRASSOVSKY_1940;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_KRAYENHOFF_1827") == 0)
    {
        *result_out_ptr = SRM_RDCOD_KRAYENHOFF_1827;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_LARISSA_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_LARISSA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_LEDA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_LEDA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_LYSITHEA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_LYSITHEA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MARS_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MARS_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MARS_SPHERE_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MARS_SPHERE_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MASS_1999") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MASS_1999;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MERCURY_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MERCURY_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_METIS_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_METIS_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MIMAS_1994") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MIMAS_1994;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MIRANDA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MIRANDA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MM5_1997") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MM5_1997;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MODIFIED_AIRY_1849") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MODIFIED_AIRY_1849;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MODIFIED_FISCHER_1960") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MODIFIED_FISCHER_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MODTRAN_MIDLATITUDE_1989") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MODTRAN_MIDLATITUDE_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MODTRAN_SUBARCTIC_1989") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MODTRAN_SUBARCTIC_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MODTRAN_TROPICAL_1989") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MODTRAN_TROPICAL_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MOON_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MOON_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989") == 0)
    {
        *result_out_ptr = SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_NAIAD_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_NAIAD_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_NEPTUNE_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_NEPTUNE_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_NEREID_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_NEREID_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_NOGAPS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_NOGAPS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_OBERON_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_OBERON_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_OPHELIA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_OPHELIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PAN_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PAN_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PANDORA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PANDORA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PASIPHAE_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PASIPHAE_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PHOBOS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PHOBOS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PHOEBE_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PHOEBE_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PLESSIS_MODIFIED_1817") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PLESSIS_MODIFIED_1817;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PLUTO_1994") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PLUTO_1994;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PORTIA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PORTIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PROMETHEUS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PROMETHEUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PROTEUS_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PROTEUS_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_PUCK_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_PUCK_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_RHEA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_RHEA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_ROSALIND_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_ROSALIND_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_SATURN_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_SATURN_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_SINOPE_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_SINOPE_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_SOUTH_AMERICAN_1969") == 0)
    {
        *result_out_ptr = SRM_RDCOD_SOUTH_AMERICAN_1969;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_SOVIET_GEODETIC_1985") == 0)
    {
        *result_out_ptr = SRM_RDCOD_SOVIET_GEODETIC_1985;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_SOVIET_GEODETIC_1990") == 0)
    {
        *result_out_ptr = SRM_RDCOD_SOVIET_GEODETIC_1990;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_STRUVE_1860") == 0)
    {
        *result_out_ptr = SRM_RDCOD_STRUVE_1860;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_SUN_1992") == 0)
    {
        *result_out_ptr = SRM_RDCOD_SUN_1992;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_TELESTO_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_TELESTO_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_TETHYS_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_TETHYS_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_THALASSA_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_THALASSA_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_THEBE_2000") == 0)
    {
        *result_out_ptr = SRM_RDCOD_THEBE_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_TITAN_1982") == 0)
    {
        *result_out_ptr = SRM_RDCOD_TITAN_1982;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_TITANIA_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_TITANIA_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_TRITON_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_TRITON_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_UMBRIEL_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_UMBRIEL_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_URANUS_1988") == 0)
    {
        *result_out_ptr = SRM_RDCOD_URANUS_1988;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_VENUS_1991") == 0)
    {
        *result_out_ptr = SRM_RDCOD_VENUS_1991;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_WALBECK_AMS_1963") == 0)
    {
        *result_out_ptr = SRM_RDCOD_WALBECK_AMS_1963;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_WALBECK_PLANHEFT_1942") == 0)
    {
        *result_out_ptr = SRM_RDCOD_WALBECK_PLANHEFT_1942;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_WAR_OFFICE_1924") == 0)
    {
        *result_out_ptr = SRM_RDCOD_WAR_OFFICE_1924;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_WGS_1960") == 0)
    {
        *result_out_ptr = SRM_RDCOD_WGS_1960;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_WGS_1966") == 0)
    {
        *result_out_ptr = SRM_RDCOD_WGS_1966;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_WGS_1984") == 0)
    {
        *result_out_ptr = SRM_RDCOD_WGS_1984;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RDCOD_WGS_1972") == 0)
    {
        *result_out_ptr = SRM_RDCOD_WGS_1972;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToRDCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToRTCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToRTCode
(
    const char *enum_name_in_ptr,
          SRM_RT_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_RTCOD_", 10) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EXPERIMENTAL_NGA_SPHERE_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EXPERIMENTAL_NGA_SPHERE_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EXPERIMENTAL_NGA_MAX_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EXPERIMENTAL_NGA_MAX_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_UNSPECIFIED") == 0)
    {
        *result_out_ptr = SRM_RTCOD_UNSPECIFIED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ABSTRACT_2D_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ABSTRACT_2D_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ABSTRACT_3D_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ABSTRACT_3D_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ADINDAN_1991_BURKINA_FASO") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ADINDAN_1991_BURKINA_FASO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ADINDAN_1991_CAMEROON") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ADINDAN_1991_CAMEROON;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ADINDAN_1991_ETHIOPIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ADINDAN_1991_ETHIOPIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ADINDAN_1991_MALI") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ADINDAN_1991_MALI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ADINDAN_1991_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ADINDAN_1991_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ADINDAN_1991_SENEGAL") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ADINDAN_1991_SENEGAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ADINDAN_1991_SUDAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ADINDAN_1991_SUDAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ADRASTEA_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ADRASTEA_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AFGOOYE_1987_SOMALIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AFGOOYE_1987_SOMALIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AIN_EL_ABD_1970_BAHRAIN_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AIN_EL_ABD_1970_BAHRAIN_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AIN_EL_ABD_1970_SAUDI_ARABIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AIN_EL_ABD_1970_SAUDI_ARABIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AMALTHEA_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AMALTHEA_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ANNA_1_1965_COCOS_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ANNA_1_1965_COCOS_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_3_ZIMBABWE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_3_ZIMBABWE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_BOTSWANA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_BOTSWANA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_BURUNDI") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_BURUNDI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_LESOTHO") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_LESOTHO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_MALAWI") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_MALAWI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_SWAZILAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_SWAZILAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_ZAIRE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_ZAIRE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1950_ZAMBIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1950_ZAMBIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1960_3_KENYA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1960_3_KENYA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1960_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1960_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARC_1960_TANZANIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARC_1960_TANZANIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ARIEL_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ARIEL_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ASCENSION_1958_ASCENSION_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ASCENSION_1958_ASCENSION_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ATLAS_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ATLAS_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_AYABELLE_LIGHTHOUSE_1991_DJIBOUTI") == 0)
    {
        *result_out_ptr = SRM_RTCOD_AYABELLE_LIGHTHOUSE_1991_DJIBOUTI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BEACON_E_1945_IWO_JIMA_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BEACON_E_1945_IWO_JIMA_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BELINDA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BELINDA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BERMUDA_1957_BERMUDA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BERMUDA_1957_BERMUDA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BIANCA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BIANCA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BISSAU_1991_GUINEA_BISSAU") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BISSAU_1991_GUINEA_BISSAU;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BOGOTA_OBS_1987_COLOMBIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BOGOTA_OBS_1987_COLOMBIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BOGOTA_OBS_1987_PM_BOGOTA_COLOMBIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BOGOTA_OBS_1987_PM_BOGOTA_COLOMBIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CALLISTO_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CALLISTO_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CALYPSO_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CALYPSO_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CAMP_AREA_1987_MCMURDO_CAMP") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CAMP_AREA_1987_MCMURDO_CAMP;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CAMPO_INCHAUSPE_1969_ARGENTINA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CAMPO_INCHAUSPE_1969_ARGENTINA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CANTON_1966_PHOENIX_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CANTON_1966_PHOENIX_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CAPE_1987_SOUTH_AFRICA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CAPE_1987_SOUTH_AFRICA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CAPE_CANAVERAL_1991_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CAPE_CANAVERAL_1991_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CARTHAGE_1987_TUNISIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CARTHAGE_1987_TUNISIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CHARON_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CHARON_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CHATHAM_1971_CHATHAM_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CHATHAM_1971_CHATHAM_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CHUA_1987_PARAGUAY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CHUA_1987_PARAGUAY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_COAMPS_1998_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_COAMPS_1998_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CORDELIA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CORDELIA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CORREGO_ALEGRE_1987_BRAZIL") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CORREGO_ALEGRE_1987_BRAZIL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_CRESSIDA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_CRESSIDA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DABOLA_1991_GUINEA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DABOLA_1991_GUINEA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DECEPTION_1993_DECEPTION_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DECEPTION_1993_DECEPTION_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DEIMOS_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DEIMOS_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DESDEMONA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DESDEMONA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DESPINA_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DESPINA_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DIONE_1982_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DIONE_1982_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DJAKARTA_1987_PM_DJAKARTA_SUMATRA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DJAKARTA_1987_PM_DJAKARTA_SUMATRA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DJAKARTA_1987_SUMATRA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DJAKARTA_1987_SUMATRA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DOS_1968_GIZO_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DOS_1968_GIZO_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_DOS_71_4_1987_ST_HELENA_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_DOS_71_4_1987_ST_HELENA_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EASTER_1967_EASTER_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EASTER_1967_EASTER_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ENCELADUS_1994_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ENCELADUS_1994_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EPIMETHEUS_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EPIMETHEUS_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EROS_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EROS_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ESTONIA_1937_ESTONIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ESTONIA_1937_ESTONIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ETRS_1989_IDENTITY_BY_MEASUREMENT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ETRS_1989_IDENTITY_BY_MEASUREMENT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPA_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPA_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_3_CYPRUS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_3_CYPRUS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_CHANNEL_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_CHANNEL_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_EGYPT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_EGYPT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_ENGLAND_SCOTLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_ENGLAND_SCOTLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_GREECE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_GREECE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_IRAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_IRAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_IRAQ") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_IRAQ;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_IRELAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_IRELAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_MALTA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_MALTA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_NORWAY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_NORWAY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_PORTUGAL_SPAIN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_PORTUGAL_SPAIN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_SARDINIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_SARDINIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_SICILY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_SICILY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_TUNISIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_TUNISIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1950_W_EUROPE_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1950_W_EUROPE_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_EUROPE_1979_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_EUROPE_1979_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_FAHUD_1987_3_OMAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_FAHUD_1987_3_OMAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_FAHUD_1987_7_OMAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_FAHUD_1987_7_OMAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GALATEA_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GALATEA_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GAN_1970_MALDIVES") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GAN_1970_MALDIVES;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GANYMEDE_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GANYMEDE_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GASPRA_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GASPRA_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GDA_1994_IDENTITY_BY_MEASUREMENT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GDA_1994_IDENTITY_BY_MEASUREMENT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEODETIC_DATUM_1949_3_NEW_ZEALAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEODETIC_DATUM_1949_3_NEW_ZEALAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEODETIC_DATUM_1949_7_NEW_ZEALAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEODETIC_DATUM_1949_7_NEW_ZEALAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1945_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1945_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1950_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1950_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1955_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1955_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1960_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1960_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1965_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1965_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1970_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1970_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1975_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1975_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1980_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1980_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1985_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1985_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1990_DGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1990_DGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_1995_IGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_1995_IGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GEOMAGNETIC_2000_IGRF") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GEOMAGNETIC_2000_IGRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GUAM_1963_GUAM") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GUAM_1963_GUAM;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_GUX_1_1987_GUADALCANAL_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_GUX_1_1987_GUADALCANAL_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_HELENE_1992_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_HELENE_1992_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_HERAT_NORTH_1987_AFGHANISTAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_HERAT_NORTH_1987_AFGHANISTAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_HERMANNSKOGEL_1871_3_YUGOSLAVIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_HERMANNSKOGEL_1871_3_YUGOSLAVIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_HJORSEY_1955_ICELAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_HJORSEY_1955_ICELAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_HONG_KONG_1963_HONG_KONG") == 0)
    {
        *result_out_ptr = SRM_RTCOD_HONG_KONG_1963_HONG_KONG;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_HU_TZU_SHAN_1991_TAIWAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_HU_TZU_SHAN_1991_TAIWAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_IAPETUS_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_IAPETUS_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_IDA_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_IDA_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1916_3_BANGLADESH") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1916_3_BANGLADESH;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1916_7_BANGLADESH") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1916_7_BANGLADESH;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1954_THAILAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1954_THAILAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1956_INDIA_NEPAL") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1956_INDIA_NEPAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1960_CON_SON_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1960_CON_SON_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1960_VIETNAM_16_N") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1960_VIETNAM_16_N;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1962_PAKISTAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1962_PAKISTAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1975_1991_THAILAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1975_1991_THAILAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDIAN_1975_1997_THAILAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDIAN_1975_1997_THAILAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_INDONESIAN_1974_INDONESIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_INDONESIAN_1974_INDONESIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_IO_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_IO_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_IRELAND_1965_3_IRELAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_IRELAND_1965_3_IRELAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_IRELAND_1965_7_IRELAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_IRELAND_1965_7_IRELAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ISTS_061_1968_SOUTH_GEORGIA_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ISTS_061_1968_SOUTH_GEORGIA_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ISTS_073_1969_DIEGO_GARCIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ISTS_073_1969_DIEGO_GARCIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_JANUS_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_JANUS_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_JGD_2000_IDENTITY_BY_MEASUREMENT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_JGD_2000_IDENTITY_BY_MEASUREMENT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_JOHNSTON_1961_JOHNSTON_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_JOHNSTON_1961_JOHNSTON_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_JULIET_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_JULIET_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_JUPITER_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_JUPITER_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_JUPITER_MAGNETIC_1993_VOYAGER") == 0)
    {
        *result_out_ptr = SRM_RTCOD_JUPITER_MAGNETIC_1993_VOYAGER;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_KANDAWALA_1987_3_SRI_LANKA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_KANDAWALA_1987_3_SRI_LANKA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_KERGUELEN_1949_KERGUELEN_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_KERGUELEN_1949_KERGUELEN_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_KERTAU_1948_3_W_MALAYSIA_SINGAPORE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_KERTAU_1948_3_W_MALAYSIA_SINGAPORE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_KOREAN_GEODETIC_1995_SOUTH_KOREA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_KOREAN_GEODETIC_1995_SOUTH_KOREA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_KUSAIE_1951_CAROLINE_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_KUSAIE_1951_CAROLINE_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_LARISSA_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_LARISSA_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_LC5_1961_CAYMAN_BRAC_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_LC5_1961_CAYMAN_BRAC_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_LEIGON_1991_3_GHANA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_LEIGON_1991_3_GHANA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_LEIGON_1991_7_GHANA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_LEIGON_1991_7_GHANA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_LIBERIA_1964_LIBERIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_LIBERIA_1964_LIBERIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_LUZON_1987_MINDANAO_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_LUZON_1987_MINDANAO_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_M_PORALOKO_1991_GABON") == 0)
    {
        *result_out_ptr = SRM_RTCOD_M_PORALOKO_1991_GABON;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MAHE_1971_MAHE_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MAHE_1971_MAHE_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MARCUS_STATION_1952_MARCUS_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MARCUS_STATION_1952_MARCUS_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MARS_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MARS_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MARS_SPHERE_2000_GLOBAL") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MARS_SPHERE_2000_GLOBAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MASS_1999_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MASS_1999_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MASSAWA_1987_ERITREA_ETHIOPIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MASSAWA_1987_ERITREA_ETHIOPIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MERCHICH_1987_MOROCCO") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MERCHICH_1987_MOROCCO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MERCURY_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MERCURY_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_METIS_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_METIS_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MIDWAY_1961_MIDWAY_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MIDWAY_1961_MIDWAY_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MIMAS_1994_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MIMAS_1994_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MINNA_1991_CAMEROON") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MINNA_1991_CAMEROON;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MINNA_1991_NIGERIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MINNA_1991_NIGERIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MIRANDA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MIRANDA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MM5_1997_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MM5_1997_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MODTRAN_MIDLATITUDE_N_1989_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MODTRAN_MIDLATITUDE_N_1989_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MODTRAN_MIDLATITUDE_S_1989_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MODTRAN_MIDLATITUDE_S_1989_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MODTRAN_SUBARCTIC_N_1989_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MODTRAN_SUBARCTIC_N_1989_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MODTRAN_SUBARCTIC_S_1989_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MODTRAN_SUBARCTIC_S_1989_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MOON_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MOON_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_MULTIGEN_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_MULTIGEN_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_ALBERTA_BRITISH_COLUMBIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_ALBERTA_BRITISH_COLUMBIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_CANADA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_CANADA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_CANAL_ZONE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_CANAL_ZONE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_CARIBBEAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_CARIBBEAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_CENTRAL_AMERICA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_CENTRAL_AMERICA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_CONTINENTAL_US") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_CONTINENTAL_US;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_CUBA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_CUBA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_EAST_ALEUTIAN_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_EAST_ALEUTIAN_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_EASTERN_CANADA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_EASTERN_CANADA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_EASTERN_US") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_EASTERN_US;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_HAYES_PENINSULA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_HAYES_PENINSULA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_MANITOBA_ONTARIO") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_MANITOBA_ONTARIO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_MEXICO") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_MEXICO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_SAN_SALVADOR_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_SAN_SALVADOR_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_WEST_ALEUTIAN_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_WEST_ALEUTIAN_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_WESTERN_US") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_WESTERN_US;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1927_YUKON") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1927_YUKON;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1983_ALEUTIAN_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1983_ALEUTIAN_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1983_CANADA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1983_CANADA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1983_CONTINENTAL_US") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1983_CONTINENTAL_US;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1983_HAWAII") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1983_HAWAII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_AM_1983_MEXICO_CENTRAL_AMERICA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_AM_1983_MEXICO_CENTRAL_AMERICA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_N_SAHARA_1959_ALGERIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_N_SAHARA_1959_ALGERIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NAHRWAN_1987_MASIRAH_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NAHRWAN_1987_MASIRAH_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NAHRWAN_1987_SAUDI_ARABIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NAHRWAN_1987_SAUDI_ARABIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NAHRWAN_1987_UNITED_ARAB_EMIRATES") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NAHRWAN_1987_UNITED_ARAB_EMIRATES;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NAIAD_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NAIAD_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NAPARIMA_1991_TRINIDAD_TOBAGO") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NAPARIMA_1991_TRINIDAD_TOBAGO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NEPTUNE_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NEPTUNE_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NEPTUNE_MAGNETIC_1993_VOYAGER") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NEPTUNE_MAGNETIC_1993_VOYAGER;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NOGAPS_1988_IDENTITY_BY_DEFAULT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NOGAPS_1988_IDENTITY_BY_DEFAULT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NTF_1896_FRANCE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NTF_1896_FRANCE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_NTF_1896_PM_PARIS_FRANCE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_NTF_1896_PM_PARIS_FRANCE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OBERON_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OBERON_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_EGYPTIAN_1907_EGYPT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_EGYPTIAN_1907_EGYPT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_HAWAII") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_HAWAII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_KAUAI") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_KAUAI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MAUI") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MAUI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_OAHU") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_OAHU;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_HAWAII") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_INT_1987_HAWAII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_KAUAI") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_INT_1987_KAUAI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MAUI") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MAUI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_OAHU") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OLD_HAWAIIAN_INT_1987_OAHU;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OPHELIA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OPHELIA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OSGB_1936_3_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OSGB_1936_3_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OSGB_1936_7_GREAT_BRITAIN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OSGB_1936_7_GREAT_BRITAIN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OSGB_1936_ENGLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OSGB_1936_ENGLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_OSGB_1936_WALES") == 0)
    {
        *result_out_ptr = SRM_RTCOD_OSGB_1936_WALES;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PAN_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PAN_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PANDORA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PANDORA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PHOBOS_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PHOBOS_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PHOEBE_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PHOEBE_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PICO_DE_LAS_NIEVES_1987_CANARY_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PICO_DE_LAS_NIEVES_1987_CANARY_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PITCAIRN_1967_PITCAIRN_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PITCAIRN_1967_PITCAIRN_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PLUTO_1994_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PLUTO_1994_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_POINT_58_1991_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_POINT_58_1991_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_POINTE_NOIRE_1948_CONGO") == 0)
    {
        *result_out_ptr = SRM_RTCOD_POINTE_NOIRE_1948_CONGO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PORTIA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PORTIA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROMETHEUS_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROMETHEUS_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROTEUS_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROTEUS_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_3_VENEZUELA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_3_VENEZUELA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_7_VENEZUELA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_7_VENEZUELA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_BOLIVIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_BOLIVIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_COLOMBIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_COLOMBIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_ECUADOR") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_ECUADOR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_GUYANA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_GUYANA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_N_CHILE_19_S") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_N_CHILE_19_S;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_PERU") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_PERU;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_AM_1956_S_CHILE_43_S") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_AM_1956_S_CHILE_43_S;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PROV_S_CHILEAN_1963_SOUTH_CHILE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PROV_S_CHILEAN_1963_SOUTH_CHILE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PUCK_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PUCK_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_PULKOVO_1942_RUSSIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_PULKOVO_1942_RUSSIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_QATAR_NATIONAL_1974_3_QATAR") == 0)
    {
        *result_out_ptr = SRM_RTCOD_QATAR_NATIONAL_1974_3_QATAR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_QORNOQ_1987_SOUTH_GREENLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_QORNOQ_1987_SOUTH_GREENLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_REUNION_1947_MASCARENE_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_REUNION_1947_MASCARENE_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_RGF_1993_IDENTITY_BY_MEASUREMENT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_RGF_1993_IDENTITY_BY_MEASUREMENT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_RHEA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_RHEA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ROME_1940_PM_ROME_SARDINIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ROME_1940_PM_ROME_SARDINIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ROME_1940_SARDINIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ROME_1940_SARDINIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ROSALIND_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ROSALIND_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_ARGENTINA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_ARGENTINA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_BOLIVIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_BOLIVIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_BRAZIL") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_BRAZIL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_CHILE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_CHILE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_COLOMBIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_COLOMBIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_GUYANA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_GUYANA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_PARAGUAY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_PARAGUAY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_PERU") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_PERU;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_TRINIDAD_TOBAGO") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_TRINIDAD_TOBAGO;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_AM_1969_VENEZUELA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_AM_1969_VENEZUELA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_ASIA_1987_SINGAPORE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_ASIA_1987_SINGAPORE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_JTSK_1993_CZECH_REP") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_JTSK_1993_CZECH_REP;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S_JTSK_1993_CZECH_REP_SLOVAKIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S_JTSK_1993_CZECH_REP_SLOVAKIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S42_PULKOVO_3_POLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S42_PULKOVO_3_POLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S42_PULKOVO_ALBANIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S42_PULKOVO_ALBANIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S42_PULKOVO_G_ROMANIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S42_PULKOVO_G_ROMANIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S42_PULKOVO_HUNGARY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S42_PULKOVO_HUNGARY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S42_PULKOVO_KAZAKHSTAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S42_PULKOVO_KAZAKHSTAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_S42_PULKOVO_LATVIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_S42_PULKOVO_LATVIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SATURN_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SATURN_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SATURN_MAGNETIC_1993_VOYAGER") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SATURN_MAGNETIC_1993_VOYAGER;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SCHWARZECK_1991_NAMIBIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SCHWARZECK_1991_NAMIBIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SIERRA_LEONE_1960_SIERRA_LEONE") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SIERRA_LEONE_1960_SIERRA_LEONE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SIRGAS_2000_IDENTITY_BY_MEASUREMENT") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SIRGAS_2000_IDENTITY_BY_MEASUREMENT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_SUN_1992_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_SUN_1992_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TANANARIVE_OBS_1925_3_MADAGASCAR") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TANANARIVE_OBS_1925_3_MADAGASCAR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TANANARIVE_OBS_1925_PM_PARIS_3_MADAGASCAR") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TANANARIVE_OBS_1925_PM_PARIS_3_MADAGASCAR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TELESTO_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TELESTO_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TERN_1961_TERN_ISLAND") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TERN_1961_TERN_ISLAND;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TETHYS_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TETHYS_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_THALASSA_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_THALASSA_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_THEBE_2000_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_THEBE_2000_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TIMBALAI_EVEREST_1948_3_BRUNEI_E_MALAYSIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TIMBALAI_EVEREST_1948_3_BRUNEI_E_MALAYSIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TIMBALAI_EVEREST_1948_7_BRUNEI_E_MALAYSIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TIMBALAI_EVEREST_1948_7_BRUNEI_E_MALAYSIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TITAN_1982_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TITAN_1982_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TITANIA_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TITANIA_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TOKYO_1991_JAPAN") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TOKYO_1991_JAPAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TOKYO_1991_MEAN_SOLUTION") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TOKYO_1991_MEAN_SOLUTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TOKYO_1991_OKINAWA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TOKYO_1991_OKINAWA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TOKYO_1991_1991_SOUTH_KOREA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TOKYO_1991_1991_SOUTH_KOREA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TOKYO_1991_1997_SOUTH_KOREA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TOKYO_1991_1997_SOUTH_KOREA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TRISTAN_1968_TRISTAN_DA_CUNHA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TRISTAN_1968_TRISTAN_DA_CUNHA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_TRITON_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_TRITON_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_UMBRIEL_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_UMBRIEL_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_URANUS_1988_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_URANUS_1988_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_URANUS_MAGNETIC_1993_VOYAGER") == 0)
    {
        *result_out_ptr = SRM_RTCOD_URANUS_MAGNETIC_1993_VOYAGER;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_VENUS_1991_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_VENUS_1991_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_VITI_LEVU_1916_VITI_LEVU_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_VITI_LEVU_1916_VITI_LEVU_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_VOIROL_1874_ALGERIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_VOIROL_1874_ALGERIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_VOIROL_1874_PM_PARIS_ALGERIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_VOIROL_1874_PM_PARIS_ALGERIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_VOIROL_1960_ALGERIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_VOIROL_1960_ALGERIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_VOIROL_1960_PM_PARIS_ALGERIA") == 0)
    {
        *result_out_ptr = SRM_RTCOD_VOIROL_1960_PM_PARIS_ALGERIA;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_WAKE_1952_WAKE_ATOLL") == 0)
    {
        *result_out_ptr = SRM_RTCOD_WAKE_1952_WAKE_ATOLL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS") == 0)
    {
        *result_out_ptr = SRM_RTCOD_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_WGS_1972_GLOBAL") == 0)
    {
        *result_out_ptr = SRM_RTCOD_WGS_1972_GLOBAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_WGS_1984_IDENTITY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_WGS_1984_IDENTITY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_YACARE_1987_URUGUAY") == 0)
    {
        *result_out_ptr = SRM_RTCOD_YACARE_1987_URUGUAY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_RTCOD_ZANDERIJ_1987_SURINAME") == 0)
    {
        *result_out_ptr = SRM_RTCOD_ZANDERIJ_1987_SURINAME;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToRTCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSpatialCoordinateCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSpatialCoordinateCode
(
    const char *enum_name_in_ptr,
          SRM_Spatial_Coordinate_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_", 16) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_CC_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_CC_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_CD_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_CD_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_CD_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_CD_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_CM_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_CM_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_EC_AUGMENTED_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_EC_AUGMENTED_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_EC_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_EC_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_EI_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_EI_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_HAEC_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_HAEC_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_HEEC_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_HEEC_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_HEEQ_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_HEEQ_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LCC_AUGMENTED_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LCC_AUGMENTED_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LCC_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LCC_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LSA_2D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LSA_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LSP_2D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LSP_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LSR_2D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LSR_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LSR_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LSR_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LCE_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LCE_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LTSAS_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LTSAS_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LTSAS_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LTSAS_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LTSC_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LTSC_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LTSC_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LTSC_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LTSE_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LTSE_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_LTSE_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_LTSE_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_M_AUGMENTED_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_M_AUGMENTED_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_M_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_M_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_OMS_AUGMENTED_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_OMS_AUGMENTED_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_OMS_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_OMS_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_PD_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_PD_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_PD_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_PD_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_PS_AUGMENTED_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_PS_AUGMENTED_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_PS_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_PS_SURFACE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_SEC_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_SEC_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_SEQ_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_SEQ_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_SMD_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_SMD_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_SME_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_SME_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_TM_AUGMENTED_3D") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_TM_AUGMENTED_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SPACOORDCOD_TM_SURFACE") == 0)
    {
        *result_out_ptr = SRM_SPACOORDCOD_TM_SURFACE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSpatialCoordinateCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFCode
(
    const char *enum_name_in_ptr,
          SRM_SRF_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFCOD_", 11) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_UNSPECIFIED") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_UNSPECIFIED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_BRITISH_OSGRS80_GRID") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_BRITISH_OSGRS80_GRID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_DELAWARE_SPCS_1983") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_DELAWARE_SPCS_1983;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_GEOCENTRIC_WGS_1984") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_GEOCENTRIC_WGS_1984;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_GEODETIC_AUSTRALIA_1984") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_GEODETIC_AUSTRALIA_1984;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_GEODETIC_WGS_1984") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_GEODETIC_WGS_1984;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_GEODETIC_N_AMERICAN_1983") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_GEODETIC_N_AMERICAN_1983;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_IRISH_GRID_1965") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_IRISH_GRID_1965;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_LAMBERT_93") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_LAMBERT_93;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_LAMBERT_II_WIDE") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_LAMBERT_II_WIDE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_MARS_PLANETOCENTRIC_2000") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_MARS_PLANETOCENTRIC_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFCOD_MARYLAND_SPCS_1983") == 0)
    {
        *result_out_ptr = SRM_SRFCOD_MARYLAND_SPCS_1983;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFParametersInfoCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFParametersInfoCode
(
    const char *enum_name_in_ptr,
          SRM_SRF_Parameters_Info_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFPARAMINFCOD_", 19) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFPARAMINFCOD_TEMPLATE") == 0)
    {
        *result_out_ptr = SRM_SRFPARAMINFCOD_TEMPLATE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFPARAMINFCOD_SET") == 0)
    {
        *result_out_ptr = SRM_SRFPARAMINFCOD_SET;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFPARAMINFCOD_INSTANCE") == 0)
    {
        *result_out_ptr = SRM_SRFPARAMINFCOD_INSTANCE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFParametersInfoCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFSCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFSCode
(
    const char *enum_name_in_ptr,
          SRM_SRFS_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFSCOD_", 12) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSCOD_UNSPECIFIED") == 0)
    {
        *result_out_ptr = SRM_SRFSCOD_UNSPECIFIED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSCOD_ALABAMA_SPCS") == 0)
    {
        *result_out_ptr = SRM_SRFSCOD_ALABAMA_SPCS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM") == 0)
    {
        *result_out_ptr = SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS") == 0)
    {
        *result_out_ptr = SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSCOD_LAMBERT_NTF") == 0)
    {
        *result_out_ptr = SRM_SRFSCOD_LAMBERT_NTF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC") == 0)
    {
        *result_out_ptr = SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR") == 0)
    {
        *result_out_ptr = SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSCOD_WISCONSIN_SPCS") == 0)
    {
        *result_out_ptr = SRM_SRFSCOD_WISCONSIN_SPCS;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFSCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFSMAlabamaSPCSCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFSMAlabamaSPCSCode
(
    const char *enum_name_in_ptr,
          SRM_SRFSM_Alabama_SPCS_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFSMALCOD_", 15) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMALCOD_WEST_ZONE") == 0)
    {
        *result_out_ptr = SRM_SRFSMALCOD_WEST_ZONE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMALCOD_EAST_ZONE") == 0)
    {
        *result_out_ptr = SRM_SRFSMALCOD_EAST_ZONE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFSMAlabamaSPCSCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFSMJapanRectangularPlaneCSCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFSMJapanRectangularPlaneCSCode
(
    const char *enum_name_in_ptr,
          SRM_SRFSM_Japan_Rectangular_Plane_CS_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_", 19) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_I") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_I;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_II") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_II;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_III") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_III;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_IV") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_IV;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_V") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_V;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_VI") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_VI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_VII") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_VII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_VIII") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_VIII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_IX") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_IX;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_X") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_X;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XI") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XII") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XIII") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XIII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XIV") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XIV;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XV") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XV;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XVI") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XVI;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XVII") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XVII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XVIII") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XVIII;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMJPRPCSCOD_ZONE_XIX") == 0)
    {
        *result_out_ptr = SRM_SRFSMJPRPCSCOD_ZONE_XIX;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFSMJapanRectangularPlaneCSCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFSMLambertNTFCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFSMLambertNTFCode
(
    const char *enum_name_in_ptr,
          SRM_SRFSM_Lambert_NTF_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFSMLAMNTFCOD_", 19) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMLAMNTFCOD_ZONE_I") == 0)
    {
        *result_out_ptr = SRM_SRFSMLAMNTFCOD_ZONE_I;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMLAMNTFCOD_ZONE_II") == 0)
    {
        *result_out_ptr = SRM_SRFSMLAMNTFCOD_ZONE_II;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMLAMNTFCOD_ZONE_III") == 0)
    {
        *result_out_ptr = SRM_SRFSMLAMNTFCOD_ZONE_III;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMLAMNTFCOD_ZONE_IV") == 0)
    {
        *result_out_ptr = SRM_SRFSMLAMNTFCOD_ZONE_IV;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFSMLambertNTFCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFSMUPSCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFSMUPSCode
(
    const char *enum_name_in_ptr,
          SRM_SRFSM_UPS_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFSMUPSCOD_", 16) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUPSCOD_NORTHERN_POLE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUPSCOD_NORTHERN_POLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUPSCOD_SOUTHERN_POLE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUPSCOD_SOUTHERN_POLE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFSMUPSCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFSMUTMCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFSMUTMCode
(
    const char *enum_name_in_ptr,
          SRM_SRFSM_UTM_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_", 16) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_1_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_1_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_2_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_2_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_3_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_3_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_4_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_4_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_5_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_5_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_6_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_6_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_7_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_7_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_8_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_8_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_9_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_9_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_11_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_11_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_13_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_13_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_14_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_14_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_15_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_15_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_16_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_16_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_17_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_17_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_18_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_18_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_19_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_19_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_20_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_20_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_21_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_21_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_22_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_22_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_23_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_23_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_24_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_24_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_25_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_25_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_26_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_26_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_27_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_27_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_28_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_28_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_29_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_29_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_30_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_30_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_31_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_31_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_32_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_32_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_33_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_33_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_34_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_34_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_35_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_35_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_36_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_36_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_37_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_37_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_38_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_38_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_39_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_39_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_40_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_40_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_41_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_41_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_42_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_42_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_43_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_43_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_44_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_44_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_45_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_45_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_46_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_46_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_47_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_47_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_48_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_48_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_49_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_49_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_50_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_50_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_51_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_51_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_52_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_52_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_53_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_53_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_54_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_54_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_55_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_55_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_56_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_56_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_57_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_57_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_58_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_58_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_59_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_59_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_60_NORTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_60_NORTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_1_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_1_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_2_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_2_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_3_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_3_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_4_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_4_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_5_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_5_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_6_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_6_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_7_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_7_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_8_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_8_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_9_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_9_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_10_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_10_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_11_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_11_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_12_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_12_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_13_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_13_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_14_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_14_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_15_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_15_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_16_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_16_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_17_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_17_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_18_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_18_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_19_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_19_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_20_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_20_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_21_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_21_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_22_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_22_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_23_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_23_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_24_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_24_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_25_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_25_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_26_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_26_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_27_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_27_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_28_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_28_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_29_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_29_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_30_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_30_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_31_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_31_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_32_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_32_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_33_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_33_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_34_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_34_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_35_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_35_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_36_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_36_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_37_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_37_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_38_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_38_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_39_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_39_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_40_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_40_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_41_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_41_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_42_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_42_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_43_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_43_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_44_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_44_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_45_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_45_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_46_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_46_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_47_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_47_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_48_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_48_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_49_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_49_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_50_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_50_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_51_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_51_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_52_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_52_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_53_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_53_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_54_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_54_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_55_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_55_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_56_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_56_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_57_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_57_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_58_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_58_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_59_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_59_SOUTHERN_HEMISPHERE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMUTMCOD_ZONE_60_SOUTHERN_HEMISPHERE") == 0)
    {
        *result_out_ptr = SRM_SRFSMUTMCOD_ZONE_60_SOUTHERN_HEMISPHERE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFSMUTMCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFSMWisconsinSPCSCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFSMWisconsinSPCSCode
(
    const char *enum_name_in_ptr,
          SRM_SRFSM_Wisconsin_SPCS_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFSMWNSPCSCOD_", 19) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMWNSPCSCOD_SOUTH_ZONE") == 0)
    {
        *result_out_ptr = SRM_SRFSMWNSPCSCOD_SOUTH_ZONE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMWNSPCSCOD_CENTRAL_ZONE") == 0)
    {
        *result_out_ptr = SRM_SRFSMWNSPCSCOD_CENTRAL_ZONE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFSMWNSPCSCOD_NORTH_ZONE") == 0)
    {
        *result_out_ptr = SRM_SRFSMWNSPCSCOD_NORTH_ZONE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFSMWisconsinSPCSCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToSRFTCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToSRFTCode
(
    const char *enum_name_in_ptr,
          SRM_SRFT_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_SRFTCOD_", 12) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_CELESTIOCENTRIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_CELESTIOCENTRIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_CELESTIODETIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_CELESTIODETIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_PLANETODETIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_PLANETODETIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_CELESTIOMAGNETIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_CELESTIOMAGNETIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_EQUATORIAL_INERTIAL") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_EQUATORIAL_INERTIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_SOLAR_ECLIPTIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_SOLAR_ECLIPTIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_SOLAR_EQUATORIAL") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_SOLAR_EQUATORIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_MERCATOR") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_MERCATOR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_TRANSVERSE_MERCATOR") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_TRANSVERSE_MERCATOR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_POLAR_STEREOGRAPHIC") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_POLAR_STEREOGRAPHIC;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D") == 0)
    {
        *result_out_ptr = SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToSRFTCode */


/*
 *------------------------------------------------------------------------------
 *
 * FUNCTION: SRM_EnumNameToStatusCode
 *
 *------------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_EnumNameToStatusCode
(
    const char *enum_name_in_ptr,
          SRM_Status_Code *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strncmp(enum_name_in_ptr,
             "SRM_STATCOD_", 12) != 0)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_SUCCESS") == 0)
    {
        *result_out_ptr = SRM_STATCOD_SUCCESS;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_SRF") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_SRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_SOURCE_SRF") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_SOURCE_SRF;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_SOURCE_COORDINATE") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_SOURCE_COORDINATE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_TARGET_COORDINATE") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_TARGET_COORDINATE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_POINT1_COORDINATE") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_POINT1_COORDINATE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_POINT2_COORDINATE") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_POINT2_COORDINATE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_OPERATION_UNSUPPORTED") == 0)
    {
        *result_out_ptr = SRM_STATCOD_OPERATION_UNSUPPORTED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_SOURCE_DIRECTION") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_SOURCE_DIRECTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_TARGET_DIRECTION") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_TARGET_DIRECTION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_CODE") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_CODE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_INPUT") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_INPUT;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_CREATION_FAILURE") == 0)
    {
        *result_out_ptr = SRM_STATCOD_CREATION_FAILURE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_DESTRUCTION_FAILURE") == 0)
    {
        *result_out_ptr = SRM_STATCOD_DESTRUCTION_FAILURE;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_FLOATING_OVERFLOW") == 0)
    {
        *result_out_ptr = SRM_STATCOD_FLOATING_OVERFLOW;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_FLOATING_UNDERFLOW") == 0)
    {
        *result_out_ptr = SRM_STATCOD_FLOATING_UNDERFLOW;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_FLOATING_POINT_ERROR") == 0)
    {
        *result_out_ptr = SRM_STATCOD_FLOATING_POINT_ERROR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_MEMORY_ALLOCATION_ERROR") == 0)
    {
        *result_out_ptr = SRM_STATCOD_MEMORY_ALLOCATION_ERROR;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_BUFFER_OVERFLOW") == 0)
    {
        *result_out_ptr = SRM_STATCOD_BUFFER_OVERFLOW;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_ENUMERATION_VALUE_INVALID") == 0)
    {
        *result_out_ptr = SRM_STATCOD_ENUMERATION_VALUE_INVALID;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_SOURCE_ORIENTATION") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_SOURCE_ORIENTATION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INVALID_TARGET_ORIENTATION") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INVALID_TARGET_ORIENTATION;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_NOT_IMPLEMENTED") == 0)
    {
        *result_out_ptr = SRM_STATCOD_NOT_IMPLEMENTED;
    }
    else if (strcmp(enum_name_in_ptr,
             "SRM_STATCOD_INACTIONABLE") == 0)
    {
        *result_out_ptr = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_EnumNameToStatusCode */




/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_Matrix3x3Add
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_Matrix3x3Add
(
    const SRM_Matrix_3x3 a_ptr,
    const SRM_Matrix_3x3 b_ptr,
          SRM_Matrix_3x3 result_out_ptr
)
{
    SRM_Status_Code      status = SRM_STATCOD_SUCCESS;
    SRM_Integer_Unsigned i, j;

    if (!a_ptr || !b_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        for (j = 0; j < 3; j++)
        {
            for (i = 0; i < 3; i++)
            {
                result_out_ptr[i][j] = a_ptr[i][j] + b_ptr[i][j];
            }
        }
    }
    return status;
} /* end SRM_Matrix3x3Add */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_Matrix3x3Multiply
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_Matrix3x3Multiply
(
    const SRM_Matrix_3x3 a_ptr,
    const SRM_Matrix_3x3 b_ptr,
          SRM_Matrix_3x3 result_out_ptr
)
{
    SRM_Status_Code      status = SRM_STATCOD_SUCCESS;
    SRM_Integer_Unsigned i, j;

    if (!a_ptr || !b_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        SRM_Matrix_3x3 tmp_matrix;

        for (j = 0; j < 3; j++)
        {
            for (i = 0; i < 3; i++)
            {
                tmp_matrix[i][j] = a_ptr[i][0] * b_ptr[0][j]
                                 + a_ptr[i][1] * b_ptr[1][j]
                                 + a_ptr[i][2] * b_ptr[2][j];
            }
        }
        memcpy(result_out_ptr, tmp_matrix, sizeof(SRM_Matrix_3x3));
    }
    return status;
} /* end SRM_Matrix3x3Multiply */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_Matrix3x3Sub
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_Matrix3x3Sub
(
    const SRM_Matrix_3x3 a_ptr,
    const SRM_Matrix_3x3 b_ptr,
          SRM_Matrix_3x3 result_out_ptr
)
{
    SRM_Status_Code      status = SRM_STATCOD_SUCCESS;
    SRM_Integer_Unsigned i, j;

    if (!a_ptr || !b_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        for (j = 0; j < 3; j++)
        {
            for (i = 0; i < 3; i++)
            {
                result_out_ptr[i][j] = a_ptr[i][j] - b_ptr[i][j];
            }
        }
    }
    return status;
} /* end SRM_Matrix3x3Sub */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_Matrix4x4Add
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_Matrix4x4Add
(
    const SRM_Matrix_4x4 a_ptr,
    const SRM_Matrix_4x4 b_ptr,
          SRM_Matrix_4x4 result_out_ptr
)
{
    SRM_Status_Code      status = SRM_STATCOD_SUCCESS;
    SRM_Integer_Unsigned i, j;

    if (!a_ptr || !b_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        for (j = 0; j < 4; j++)
        {
            for (i = 0; i < 4; i++)
            {
                result_out_ptr[i][j] = a_ptr[i][j] + b_ptr[i][j];
            }
        }
    }
    return status;
} /* end SRM_Matrix4x4Add */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_Matrix4x4Multiply
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_Matrix4x4Multiply
(
    const SRM_Matrix_4x4 a_ptr,
    const SRM_Matrix_4x4 b_ptr,
          SRM_Matrix_4x4 result_out_ptr
)
{
    SRM_Status_Code      status = SRM_STATCOD_SUCCESS;
    SRM_Integer_Unsigned i, j;

    if (!a_ptr || !b_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        SRM_Matrix_4x4 tmp_matrix;

        for (j = 0; j < 4; j++)
        {
            for (i = 0; i < 4; i++)
            {
                tmp_matrix[i][j] = a_ptr[i][0] * b_ptr[0][j]
                                 + a_ptr[i][1] * b_ptr[1][j]
                                 + a_ptr[i][2] * b_ptr[2][j]
                                 + a_ptr[i][3] * b_ptr[3][j];
            }
        }
        memcpy(result_out_ptr, tmp_matrix, sizeof(SRM_Matrix_4x4));
    }
    return status;
} /* end SRM_Matrix4x4Multiply */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_Matrix4x4Sub
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_Matrix4x4Sub
(
    const SRM_Matrix_4x4 a_ptr,
    const SRM_Matrix_4x4 b_ptr,
          SRM_Matrix_4x4 result_out_ptr
)
{
    SRM_Status_Code      status = SRM_STATCOD_SUCCESS;
    SRM_Integer_Unsigned i, j;

    if (!a_ptr || !b_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        for (j = 0; j < 4; j++)
        {
            for (i = 0; i < 4; i++)
            {
                result_out_ptr[i][j] = a_ptr[i][j] - b_ptr[i][j];
            }
        }
    }
    return status;
} /* end SRM_Matrix4x4Sub */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_VectorMagnitude
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_VectorMagnitude
(
    const SRM_Vector_3D   vec_ptr,
          SRM_Long_Float *result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!vec_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        *result_out_ptr = sqrt((vec_ptr[0] * vec_ptr[0]) +
                               (vec_ptr[1] * vec_ptr[1]) +
                               (vec_ptr[2] * vec_ptr[2]));
    }
    return status;
} /* end SRM_VectorMagnitude */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_VectorMultByScalar
 *
 *----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_VectorMultByScalar
(
    const SRM_Vector_3D  vec_ptr,
          SRM_Long_Float scalar,
          SRM_Vector_3D  result_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!vec_ptr || !result_out_ptr)
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    else
    {
        result_out_ptr[0] = vec_ptr[0] * scalar;
        result_out_ptr[1] = vec_ptr[1] * scalar;
        result_out_ptr[2] = vec_ptr[2] * scalar;
    }
    return status;
} /* end SRM_VectorMultByScalar */
