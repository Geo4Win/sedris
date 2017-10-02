/*
 * SRM API
 *
 * FILE       : srm_om.cpp
 *
 * PROGRAMMERS: Cameron Kellough (SRI)
 *
 * DESCRIPTION:
 *   This file is internal to the SRM API.
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
#include "srm_internal.h"
#include "srm_sincos.h"
#include "impl_srf_params.h"
/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cd_to_om_constants
 *
 *----------------------------------------------------------------------------
 */
void
set_cd_to_om_constants
(
    const Impl_ORM_Data                *e_constants,
    const IMPL_OBLIQUE_MERCATOR_SRFP   *om_srf,
          SRM_CD_OM_Specific_Constants *cd_om_spec
)
{
  SRM_Long_Float sin_lat1=IMPL_NAN,
                 cos_lat1=IMPL_NAN,
                 sin_lat2=IMPL_NAN,
                 cos_lat2=IMPL_NAN,
                 sin_lon1=IMPL_NAN,
                 cos_lon1=IMPL_NAN,
                 sin_lon2=IMPL_NAN,
                 cos_lon2=IMPL_NAN,
                 p0=IMPL_NAN,
                 q0=IMPL_NAN,
                 lambda_0=IMPL_NAN,
                 alpha_0=IMPL_NAN,
                 sin_lambda_1_minus_lambda_0=IMPL_NAN,
                 sin_lambda_2_minus_lambda_0=IMPL_NAN;

    cd_om_spec->e_constants=*e_constants;

    srm_sincos(om_srf->latitude1, sin_lat1, cos_lat1);
    srm_sincos(om_srf->latitude2, sin_lat2, cos_lat2);
    srm_sincos(om_srf->longitude1, sin_lon1, cos_lon1);
    srm_sincos(om_srf->longitude2, sin_lon2, cos_lon2);

    p0=cos_lat1*sin_lat2*sin_lon1-sin_lat1*cos_lat2*sin_lon2;
    q0=cos_lat1*sin_lat2*cos_lon1-sin_lat1*cos_lat2*cos_lon2;

    lambda_0=atan2(p0,q0);

    cd_om_spec->lambda_0=lambda_0;

    srm_sincos(lambda_0, cd_om_spec->sl0, cd_om_spec->cl0);

    sin_lambda_1_minus_lambda_0=sin_lon1*cd_om_spec->cl0-cos_lon1*cd_om_spec->sl0;
    sin_lambda_2_minus_lambda_0=sin_lon2*cd_om_spec->cl0-cos_lon2*cd_om_spec->sl0;

    if(fabs(sin_lambda_1_minus_lambda_0)>=fabs(sin_lambda_2_minus_lambda_0))
    {
        alpha_0=atan(sin_lat1/(cos_lat1*sin_lambda_1_minus_lambda_0));
    }
    else
    {
        alpha_0=atan(sin_lat2/(cos_lat2*sin_lambda_2_minus_lambda_0));
    }
    srm_sincos(alpha_0, cd_om_spec->sa0, cd_om_spec->ca0);
    cd_om_spec->ak0=e_constants->A*om_srf->central_scale;
} /* end set_cd_to_om_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_OM
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_OM
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status    status = IMPL_VALID;

    SRM_CD_OM_Specific_Constants *cd_om_spec = (SRM_CD_OM_Specific_Constants *)(constants);

    SRM_Long_Float source_lon = source_generic_coordinate[0];
    SRM_Long_Float source_lat = source_generic_coordinate[1];
    SRM_Long_Float source_elv = source_generic_coordinate[2];

    SRM_Long_Float *dest_x_ptr, *dest_y_ptr;

    SRM_Long_Float
      sin_phi=IMPL_NAN,
      cos_phi=IMPL_NAN,
      sin_lambda=IMPL_NAN,
      cos_lambda=IMPL_NAN,
      p1=IMPL_NAN,
      p2=IMPL_NAN,
      sin_lambda_minus_lambda_0=IMPL_NAN,
      cos_lambda_minus_lambda_0=IMPL_NAN;

    dest_x_ptr = &dest_generic_coordinate[0];
    dest_y_ptr = &dest_generic_coordinate[1];

    dest_generic_coordinate[2]=source_elv;

    srm_sincos(source_lon, sin_lambda, cos_lambda);
    srm_sincos(source_lat, sin_phi, cos_phi);

    sin_lambda_minus_lambda_0=(sin_lambda*cd_om_spec->cl0 - cos_lambda*cd_om_spec->sl0); /*good*/
    cos_lambda_minus_lambda_0=(cos_lambda*cd_om_spec->cl0 + sin_lambda*cd_om_spec->sl0); /*good*/

    p1= ( cd_om_spec->sa0*sin_phi) + cd_om_spec->ca0 * cos_phi * sin_lambda_minus_lambda_0;
    p2= (-cd_om_spec->ca0*sin_phi) + cd_om_spec->sa0 * cos_phi * sin_lambda_minus_lambda_0;

    *dest_x_ptr=cd_om_spec->ak0*atan2(p1,cos_phi*cos_lambda_minus_lambda_0);
    *dest_y_ptr=0.5*cd_om_spec->ak0*log((1-p2)/(1+p2));

    return status;
} /* end SRM_ChangeCD_OM */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_om_to_cd_constants
 *
 *----------------------------------------------------------------------------
 */
void
set_om_to_cd_constants
(
    const Impl_ORM_Data                *e_constants,
    const IMPL_OBLIQUE_MERCATOR_SRFP   *om_srf,
          SRM_OM_CD_Specific_Constants *om_cd_spec
)
{
    SRM_Long_Float sin_lat1=IMPL_NAN,
                   cos_lat1=IMPL_NAN,
                   sin_lat2=IMPL_NAN,
                   cos_lat2=IMPL_NAN,
                   sin_lon1=IMPL_NAN,
                   cos_lon1=IMPL_NAN,
                   sin_lon2=IMPL_NAN,
                   cos_lon2=IMPL_NAN,
                   p0=IMPL_NAN,
                   q0=IMPL_NAN,
                   lambda_0=IMPL_NAN,
                   alpha_0=IMPL_NAN,
                   sin_lambda_1_minus_lambda_0=IMPL_NAN,
                   sin_lambda_2_minus_lambda_0=IMPL_NAN;

    om_cd_spec->e_constants=*e_constants;

    srm_sincos(om_srf->latitude1, sin_lat1, cos_lat1);
    srm_sincos(om_srf->latitude2, sin_lat2, cos_lat2);
    srm_sincos(om_srf->longitude1, sin_lon1, cos_lon1);
    srm_sincos(om_srf->longitude2, sin_lon2, cos_lon2);

    p0=cos_lat1*sin_lat2*sin_lon1-sin_lat1*cos_lat2*sin_lon2;
    q0=cos_lat1*sin_lat2*cos_lon1-sin_lat1*cos_lat2*cos_lon2;

    lambda_0=atan(p0/q0);
  /*This should *_NOT_* be atan2(p0,q0) as suggested by ISO 18026 table 5.19
    CDK July 23, 2005
  */

    om_cd_spec->lambda_0=lambda_0;

    srm_sincos(lambda_0, om_cd_spec->sl0, om_cd_spec->cl0);

    sin_lambda_1_minus_lambda_0=srm_sin(om_srf->longitude1-lambda_0);
  //sin_lon1*cd_om_spec->cl0-cos_lon1*cd_om_spec->sl0;
    sin_lambda_2_minus_lambda_0=srm_sin(om_srf->longitude2-lambda_0);
  //sin_lon2*cd_om_spec->cl0-cos_lon2*cd_om_spec->sl0;

    if(fabs(sin_lambda_1_minus_lambda_0)>=fabs(sin_lambda_2_minus_lambda_0))
    {
        alpha_0=atan(sin_lat1/(cos_lat1*sin_lambda_1_minus_lambda_0));
    }
    else
    {
        alpha_0=atan(sin_lat2/(cos_lat2*sin_lambda_2_minus_lambda_0));
    }
    srm_sincos(alpha_0, om_cd_spec->sa0, om_cd_spec->ca0);
    om_cd_spec->inv_ak0=1.0/(e_constants->A*om_srf->central_scale);
} /* end set_om_to_cd_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeOM_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeOM_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status              status = IMPL_VALID;

    SRM_OM_CD_Specific_Constants *om_cd_spec = (SRM_OM_CD_Specific_Constants*)(constants);

    SRM_Long_Float *dest_lat_ptr = &dest_generic_coordinate[1],
                   *dest_lon_ptr = &dest_generic_coordinate[0],
                    source_x = source_generic_coordinate[0],
                    source_y = source_generic_coordinate[1],
                    source_z = source_generic_coordinate[2];

    SRM_Long_Float  u_star=IMPL_NAN,
                    v_star=IMPL_NAN,
                    sinh_v=IMPL_NAN,
                    cosh_v=IMPL_NAN,
                    sin_u=IMPL_NAN,
                    cos_u=IMPL_NAN,
                    xlon1=IMPL_NAN,
                    q1=IMPL_NAN,
                    q2=IMPL_NAN;

    dest_generic_coordinate[2] = source_z;

    u_star = source_x * om_cd_spec->inv_ak0;
    v_star = source_y * om_cd_spec->inv_ak0;
  /*Note that the false northing and easting has already been subtracted by the caller
   CDK 7/25/2005
  */

#if 0
  /*The following four lines compute the hyperbolic functions of v
    using an exponential and and inverse instead of two exponentials.
    It's likely to be almost twice as fast as two hyperbolics.

    Unfortunately, this
  */
    SRM_Long_Float exp_v=IMPL_NAN;

    exp_v = exp( v_star );
    inv_expv=1.0 / exp_v;
    sinh_v = 0.5*  (exp_v - inv_expv);
    cosh_v = 0.5*  (exp_v + inv_expv);
#endif

    sinh_v = sinh(v_star);
    cosh_v = cosh(v_star);

    srm_sincos(u_star, sin_u, cos_u);

    q1=om_cd_spec->ca0*sin_u-om_cd_spec->sa0*sinh_v;
    q2=om_cd_spec->sa0*sin_u+om_cd_spec->ca0*sinh_v;

    xlon1 = atan2( q1, cos_u );

    GET_LAMBDA_STAR( xlon1, (-om_cd_spec->lambda_0), *dest_lon_ptr);

    *dest_lat_ptr = asin( q2 / cosh_v );

    return status;
} /* end SRM_ChangeOM_CD */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_COM_OM
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_COM_OM
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status status=IMPL_VALID;
    dest_generic_coordinate[0]=0.0;  /*sin(gamma=0.0)=0.0*/
    dest_generic_coordinate[1]=1.0;  /*cos(gamma=0.0)=1.0*/

    return status;
} /* end SRM_COM_OM */
