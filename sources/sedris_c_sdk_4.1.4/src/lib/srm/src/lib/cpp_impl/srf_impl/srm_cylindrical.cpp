/*
 * SRM API
 *
 * FILE       : srm_cylindrical.cpp
 *
 * PROGRAMMERS: Cameron Kellough (SRI)
 *
 * DESCRIPTION: Provide reusable functions for conversions between
 *              SRFs based on cylindrical coordinates and position
 *              space (CC for object's reference ORM).
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
 * For other release dates/detailed changes, contact SRI or SAIC.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "srm_types.h"
#include "srm_ctypes.h"
#include "srm_sincos.h"
#include "srm_internal.h"

void
set_LCTP_LTSE_constants
(
    IMPL_LOC_TAN_CYL_SRFP            *lctp_srf_src,
    IMPL_LOC_TAN_EUCLIDEAN_SRFP      *ltse_srf_tgt,
    SRM_LCTP_LTSE_Specific_Constants *lctp_ltse_spec
)
{
    lctp_ltse_spec->LCTP_Azimuth=lctp_srf_src->azimuth;
    lctp_ltse_spec->LCTP_Height_Offset=lctp_srf_src->height_offset;
    lctp_ltse_spec->LTSE_Azimuth=ltse_srf_tgt->azimuth;
    lctp_ltse_spec->LTSE_Height_Offset=ltse_srf_tgt->height_offset;
}


Impl_Status
Impl_ChangeCylindrical_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    SRM_LCTP_LTSE_Specific_Constants* lctp_ltse_spec= (SRM_LCTP_LTSE_Specific_Constants*) constants;

    const SRM_Long_Float
    *theta_ptr=  &source_generic_coordinate[0],
    *rho_ptr=    &source_generic_coordinate[1],
    *zeta_ptr=   &source_generic_coordinate[2];

    SRM_Long_Float
    *x_ptr=&dest_generic_coordinate[0],
    *y_ptr=&dest_generic_coordinate[1],
    *z_ptr=&dest_generic_coordinate[2];

    SRM_Long_Float theta_star;

    GET_ALPHA_STAR(*theta_ptr,0,theta_star);

    GET_ALPHA_STAR(theta_star,lctp_ltse_spec->LCTP_Azimuth,theta_star); /*Subtract LCTP Azimuth*/
    GET_ALPHA_STAR(theta_star,-lctp_ltse_spec->LTSE_Azimuth,theta_star); /*ADD LTSE azimuth*/

    *x_ptr= (*rho_ptr) * srm_cos(theta_star);
    *y_ptr= (*rho_ptr) * srm_sin(theta_star);

    *z_ptr= (*zeta_ptr-lctp_ltse_spec->LCTP_Height_Offset+lctp_ltse_spec->LTSE_Height_Offset);

    return IMPL_VALID;
}


void
set_LTSE_LCTP_constants
(
    IMPL_LOC_TAN_EUCLIDEAN_SRFP      *ltse_srf_src,
    IMPL_LOC_TAN_CYL_SRFP            *lctp_srf_tgt,
    SRM_LTSE_LCTP_Specific_Constants *ltse_lctp_spec
)
{
    ltse_lctp_spec->LTSE_Azimuth=ltse_srf_src->azimuth;
    ltse_lctp_spec->LTSE_Height_Offset=ltse_srf_src->height_offset;

    ltse_lctp_spec->LCTP_Azimuth=lctp_srf_tgt->azimuth;
    ltse_lctp_spec->LCTP_Height_Offset=lctp_srf_tgt->height_offset;
}


Impl_Status
Impl_ChangeCC_Cylindrical
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    SRM_LTSE_LCTP_Specific_Constants* ltse_lctp_spec= (SRM_LTSE_LCTP_Specific_Constants*) constants;

    const SRM_Long_Float
    *x_ptr=&source_generic_coordinate[0],
    *y_ptr=&source_generic_coordinate[1],
    *z_ptr=&source_generic_coordinate[2];

    SRM_Long_Float
    *theta_ptr=  &dest_generic_coordinate[0],
    *rho_ptr=    &dest_generic_coordinate[1],
    *zeta_ptr=   &dest_generic_coordinate[2];

    if ((*x_ptr != 0.0) && (*y_ptr != 0.0))
    {
        *theta_ptr=atan2(*y_ptr,*x_ptr);

        GET_ALPHA_STAR(*theta_ptr,0,*theta_ptr);

        GET_ALPHA_STAR(*theta_ptr,ltse_lctp_spec->LTSE_Azimuth,*theta_ptr); /*Subtract LTSE azimuth*/
        GET_ALPHA_STAR(*theta_ptr,-(ltse_lctp_spec->LCTP_Azimuth),*theta_ptr); /*Add LCTP Azimuth*/
       /*Note that this line adds by subtracting a negative number because the macro in question subtracts*/

        *rho_ptr=sqrt(SQUARE(*x_ptr) +SQUARE(*y_ptr));
        *zeta_ptr=(*z_ptr - ltse_lctp_spec->LTSE_Height_Offset + ltse_lctp_spec->LCTP_Height_Offset );
    }
    else
    {
        *theta_ptr = 0.0;
        *rho_ptr   = 0.0;
        *zeta_ptr  = *z_ptr;
    }
    return IMPL_VALID;
}
