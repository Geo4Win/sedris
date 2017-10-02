/*
 * SRM API
 *
 * FILE       : srm_spherical.cpp
 *
 * PROGRAMMERS: Cameron Kellough (SRI)
 *
 * DESCRIPTION: Provide reusable functions for conversions between
 *              SRFs based on spherical coordinates and position
 *              space (CC for object's reference ORM).
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 * For other release dates/detailed changes, contact SRI or SAIC.
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "srm_types.h"
#include "srm_ctypes.h"
#include "srm_internal.h"
#include "srm_sincos.h"

Impl_Status
Impl_ChangeSpherical_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    SRM_Long_Float
        *lambda_ptr=const_cast<SRM_Long_Float*>(&source_generic_coordinate[0]),
        *theta_ptr= const_cast<SRM_Long_Float*>(&source_generic_coordinate[1]),
        *rho_ptr=   const_cast<SRM_Long_Float*>(&source_generic_coordinate[2]);

    SRM_Long_Float
        *x_ptr=&dest_generic_coordinate[0],
        *y_ptr=&dest_generic_coordinate[1],
        *z_ptr=&dest_generic_coordinate[2];

    SRM_Long_Float slbt, clbt, stt, ctt;

    srm_sincos(*lambda_ptr, slbt, clbt);
    srm_sincos(*theta_ptr, stt, ctt);

    *x_ptr=(*rho_ptr) * ctt * clbt;
    *y_ptr=(*rho_ptr) * ctt * slbt;
    *z_ptr=(*rho_ptr) * stt;

    return IMPL_VALID;
}


Impl_Status
Impl_ChangeCC_Spherical
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    const SRM_Long_Float
        *x_ptr=&source_generic_coordinate[0],
        *y_ptr=&source_generic_coordinate[1],
        *z_ptr=&source_generic_coordinate[2];

    SRM_Long_Float
        *lambda_ptr=&dest_generic_coordinate[0],
        *theta_ptr= &dest_generic_coordinate[1],
        *rho_ptr=   &dest_generic_coordinate[2];

    SRM_Long_Float lambda_prime, x2, y2;

    x2= SQUARE(*x_ptr);
    y2= SQUARE(*y_ptr);

    if ((x2 > (EPSILON*EPSILON)) && (y2 > (EPSILON*EPSILON)))
    {
        lambda_prime=atan((*y_ptr)/(*x_ptr));

        if ((*x_ptr >= 0))
            if ((*y_ptr >= 0))
                *lambda_ptr=lambda_prime;
            else
                *lambda_ptr=lambda_prime;
        else if ((*y_ptr >= 0))
            *lambda_ptr=SRM_PI+lambda_prime;
        else
            *lambda_ptr=-SRM_PI+lambda_prime;
    }
    else
    {
        if (*y_ptr >= EPSILON)
            *lambda_ptr=  SRM_PI_DIV_2;
        else
            *lambda_ptr= -SRM_PI_DIV_2;

        if (*x_ptr >= EPSILON)
            *lambda_ptr=0.0;
        else
            *lambda_ptr=SRM_PI;
    }
    *rho_ptr=sqrt(x2 + y2+ SQUARE(*z_ptr));

   /*
    * If rho is zero, set declination to zero
    */
    if (*rho_ptr != 0.0)
        *theta_ptr = asin((*z_ptr)/(*rho_ptr));
    else
        *theta_ptr = 0.0;

    return IMPL_VALID;
}


void set_LAST_LTSE_constants
(
    const IMPL_LOC_TAN_AZ_SPHER_SRFP       *ltas_srf_src,
    const IMPL_LOC_TAN_EUCLIDEAN_SRFP      *ltse_srf_tgt,
          SRM_LAST_LTSE_Specific_Constants *last_ltse_spec
)
{
    last_ltse_spec->LAST_Azimuth=ltas_srf_src->azimuth;
    last_ltse_spec->LAST_Height_Offset=ltas_srf_src->height_offset;
    last_ltse_spec->LTSE_Azimuth=ltse_srf_tgt->azimuth;
    last_ltse_spec->LTSE_Height_Offset=ltse_srf_tgt->height_offset;
}

void set_LTSE_LAST_constants
(
    const IMPL_LOC_TAN_EUCLIDEAN_SRFP      *ltse_srf_src,
    const IMPL_LOC_TAN_AZ_SPHER_SRFP       *ltas_srf_tgt,
          SRM_LTSE_LAST_Specific_Constants *ltse_last_spec
)
{
    ltse_last_spec->LAST_Azimuth=ltas_srf_tgt->azimuth;
    ltse_last_spec->LAST_Height_Offset=ltas_srf_tgt->height_offset;
    ltse_last_spec->LTSE_Azimuth=ltse_srf_src->azimuth;
    ltse_last_spec->LTSE_Height_Offset=ltse_srf_src->height_offset;
}


Impl_Status
Impl_ChangeAzSpherical_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    SRM_LAST_LTSE_Specific_Constants *last_ltse_spec=(SRM_LAST_LTSE_Specific_Constants*)constants;

    SRM_Long_Float
      *alpha_ptr=const_cast<SRM_Long_Float*>(&source_generic_coordinate[0]),
      *theta_ptr=const_cast<SRM_Long_Float*>(&source_generic_coordinate[1]),
      *rho_ptr=  const_cast<SRM_Long_Float*>(&source_generic_coordinate[2]),
      alpha_star=IMPL_NAN,
      alpha_star_star=IMPL_NAN;

    SRM_Long_Float
      *x_ptr=&dest_generic_coordinate[0],
      *y_ptr=&dest_generic_coordinate[1],
      *z_ptr=&dest_generic_coordinate[2];

    GET_ALPHA_STAR(*alpha_ptr,last_ltse_spec->LAST_Azimuth,alpha_star);
    /*This subtracts the azimuth offset inherant in the Local Tangent Azimuthal
      Coordinate.  This scales the result to the correct range for Azimuth
      between 0 and 2pi
    */

    GET_ALPHA_STAR(alpha_star,-last_ltse_spec->LTSE_Azimuth,alpha_star_star);
    /*This adds the azimuth offset required to go from the zero azimuth solution
      stored in alpha_star to the Azimuth inherent in the LTSE.  This scales the
      result to the correct range for azimuth between zero and 2 pi.

      Note that the negative sign in the call is here because this routine subtracts
      by default but to correct the azimuth to the value used by the LTSE we need to add.
    */
    SRM_Long_Float sal, cal, stt, ctt;

    srm_sincos(alpha_star_star, sal, cal);
    srm_sincos(*theta_ptr, stt, ctt);

    *x_ptr=(*rho_ptr) * ctt * sal;
    *y_ptr=(*rho_ptr) * ctt * cal;

    *z_ptr=(*rho_ptr) * stt + last_ltse_spec->LAST_Height_Offset - last_ltse_spec->LTSE_Height_Offset;

    return IMPL_VALID;
}


Impl_Status
Impl_ChangeCC_AzSpherical
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    SRM_LTSE_LAST_Specific_Constants* ltse_last_spec= (SRM_LTSE_LAST_Specific_Constants*) constants;
    const SRM_Long_Float
      *x_ptr=&source_generic_coordinate[0],
      *y_ptr=&source_generic_coordinate[1],
      *z_ptr=&source_generic_coordinate[2];

    SRM_Long_Float
      *alpha_ptr= &dest_generic_coordinate[0],
      *theta_ptr= &dest_generic_coordinate[1],
      *rho_ptr=   &dest_generic_coordinate[2];

    SRM_Long_Float z_adj=*z_ptr+ltse_last_spec->LTSE_Height_Offset-ltse_last_spec->LAST_Height_Offset;

    *alpha_ptr=atan2(*x_ptr,*y_ptr);
    GET_ALPHA_STAR(*alpha_ptr,0.0,*alpha_ptr);  /*Get the range right for the angle in this SRF*/

    GET_ALPHA_STAR(*alpha_ptr,-ltse_last_spec->LTSE_Azimuth,*alpha_ptr);
    /*Subtract the LTSE azimuth offset to get the azimuth with no offset*/

    GET_ALPHA_STAR(*alpha_ptr,ltse_last_spec->LAST_Azimuth,*alpha_ptr);
    /*Add the LAST azimuth to get the effect for LAST
     note that the routine subtracts by default so we must put a negative
     sign here so that the result is added
    */

    *rho_ptr=sqrt(SQUARE((*x_ptr))+SQUARE((*y_ptr))+SQUARE((z_adj)));

   /*
    * If rho is zero, set declination to zero
    */
    if (*rho_ptr != 0.0)
        *theta_ptr=asin((z_adj) / (*rho_ptr));
    else
        *theta_ptr = 0.0;

    return IMPL_VALID;
}
