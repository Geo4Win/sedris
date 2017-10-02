/*
 * SRM API
 *
 * FILE       : srm_m.cpp
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
 * FUNCTION: set_cd_to_m_constants
 *
 *----------------------------------------------------------------------------
 */
void
set_cd_to_m_constants
(
    const Impl_ORM_Data               *e_constants,
    const IMPL_MERCATOR_SRFP          *m_srf,
          SRM_CD_M_Specific_Constants *cd_m_spec
)
{
    SRM_Long_Float AA1, AA2, AA3, AA4, AA5, AA6, AA7, AA8, AA9,
                   AB1, AB2, AB3, AB4, AB5, AB6, AB7, AB8, AB9,
                   BB1, BB2, BB3, BB4, BB5;

    cd_m_spec->longitude_origin = m_srf->origin_longitude;
    cd_m_spec->scale            = m_srf->central_scale;
    cd_m_spec->e_constants      = *e_constants;

    if (e_constants->Eps2!=0)
    {
        AA1 =  0.100000000003490E+01;
        AA2 = -0.643155723158021;
        AA3 = -0.333332134894985;
        AA4 = -0.241457540671514E-04;
        AA5 =  0.143376648162652;
        AA6 =  0.356844276587295;
        AA7 = -0.333332875955149;
        AA8 =  0.0;
        AA9 =  0.0;

        BB1 = AA1;
        BB2 = e_constants->Eps2*AA2;
        BB3 = e_constants->Eps2*(AA3+e_constants->Eps*(AA4+e_constants->Eps*AA5));
        BB4 = e_constants->Eps2*AA6;
        BB5 = e_constants->Eps2*(AA7+e_constants->Eps*(AA8+e_constants->Eps*AA9));

        cd_m_spec->CR11 = BB3/BB5-.187E-11;
        cd_m_spec->CR12 = (BB2-BB4*BB3/BB5)/BB5;
        cd_m_spec->CR13 = (BB1-BB3/BB5)/BB5;
        cd_m_spec->CR14 = 1.0/BB5;
        cd_m_spec->CR15 = BB4/BB5;

        AB1 =  0.999999999957885;
        AB2 = -0.115979311942142E+01;
        AB3 = -0.333339671395063;
        AB4 =  0.276473457331734E-03;
        AB5 =  0.587786240368508;
        AB6 = -0.159793128888088;
        AB7 = -0.333333465982150;
        AB8 =  0.746505041501704E-04;
        AB9 = -0.701559218182283E-01;

        BB1 = AB1;
        BB2 = e_constants->Eps2*AB2;
        BB3 = e_constants->Eps2*(AB3+e_constants->Eps*(AB4+e_constants->Eps*AB5));
        BB4 = e_constants->Eps2*AB6;
        BB5 = e_constants->Eps2*(AB7+e_constants->Eps*(AB8+e_constants->Eps*AB9));

        cd_m_spec->CR21 = BB3/BB5+.2689E-11;
        cd_m_spec->CR22 = (BB2-BB4*BB3/BB5)/BB5;
        cd_m_spec->CR23 = (BB1-BB3/BB5)/BB5;
        cd_m_spec->CR24 = 1.0/BB5;
        cd_m_spec->CR25 = BB4/BB5;
    }
} /* end set_cd_to_m_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_m_to_cd_constants
 *
 *----------------------------------------------------------------------------
 */
void
set_m_to_cd_constants
(
    const Impl_ORM_Data               *e_constants,
    const IMPL_MERCATOR_SRFP          *m_srf,
          SRM_M_CD_Specific_Constants *m_cd_spec
)
{
    SRM_Long_Float pa2, pa4, pa6, pa8;

    m_cd_spec->longitude_origin  = m_srf->origin_longitude;
    m_cd_spec->scale_inv         = 1.0/m_srf->central_scale;
    m_cd_spec->e_constants       = *e_constants;

    if (e_constants->Eps!=0.0) /* compute ellipsoidal values */
    {
        pa2 = e_constants->Eps2 / 2.0 +
              pow(e_constants->Eps2, 2.0) * 5.0 / 24.0;

        pa2 += pow(e_constants->Eps2, 3.0) / 12.0 +
               pow(e_constants->Eps2, 4.0) * 13.0 / 360.0;

        pa4 = pow(e_constants->Eps2, 2.0) * 7.0 / 48.0 +
              pow(e_constants->Eps2, 3.0) * 29.0 / 240.0;

        pa4 += pow(e_constants->Eps2, 4.0) * 811.0 / 11520.0;

        pa6 = pow(e_constants->Eps2, 3.0) * 7.0 / 120.0 +
              pow(e_constants->Eps2, 4.0) * 81.0 / 1120.0;

        pa8 = pow(e_constants->Eps2, 4.0) * 4279.0 / 161280.0;

        m_cd_spec->b1 = pa2 *    2.0 + pa4 *   4.0 + pa6 *  6.0 + pa8 * 8.0;
        m_cd_spec->b2 = pa4 *   -8.0 - pa6 *  32.0 - pa8 * 80.0;
        m_cd_spec->b3 = pa6 *   32.0 + pa8 * 192.0;
        m_cd_spec->b4 = pa8 * -128.0;
    }
}/* end set_m_to_cd_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_M
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_M
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status    status = IMPL_VALID;

    SRM_CD_M_Specific_Constants *cd_m_spec = (SRM_CD_M_Specific_Constants *)(constants);

    Impl_ORM_Data      *e_constants=&cd_m_spec->e_constants;

    SRM_Long_Float source_lon;
    SRM_Long_Float source_lat = source_generic_coordinate[1];
    SRM_Long_Float source_elv = source_generic_coordinate[2];

    SRM_Long_Float p, sin_lat= srm_sin(source_lat);

    SRM_Long_Float
      *dest_x_ptr = &dest_generic_coordinate[0],
      *dest_y_ptr = &dest_generic_coordinate[1];

    dest_generic_coordinate[2]=source_elv;

    GET_LAMBDA_STAR(source_generic_coordinate[0], cd_m_spec->longitude_origin, source_lon);

    if (e_constants->Eps!=0.0)
    {
        /* compute ellipsoidal values */

        SRM_Long_Float abs_sin_lat = fabs(sin_lat);

        if (abs_sin_lat <= (35.5*SRM_RADIANS_PER_DEGREE))
        {
            p = cd_m_spec->CR11 +
                (cd_m_spec->CR12 * abs_sin_lat + cd_m_spec->CR13)/
                (cd_m_spec->CR14 + abs_sin_lat * (cd_m_spec->CR15 + abs_sin_lat));
        }
        else
        {
            p = cd_m_spec->CR21 +
                (cd_m_spec->CR22 * abs_sin_lat + cd_m_spec->CR23)/
                (cd_m_spec->CR24 + abs_sin_lat * (cd_m_spec->CR25 + abs_sin_lat));
        }

        if (sin_lat < 0.0)
            p = 1.0/p;

        p = p * sqrt((1.0 + sin_lat)/(1.0 - sin_lat));
    }
    else
    {
        /* compute spherical values */
        p = sqrt((1.0 + sin_lat)/(1.0 - sin_lat));
    }

    /* fix quadrant on longitude */
    SE_FIX_LONGITUDE(source_lon);

    /* COMPUTE EASTING */

    *dest_x_ptr = cd_m_spec->scale * e_constants->A * source_lon;

    /* COMPUTE NORTHING */

    *dest_y_ptr = cd_m_spec->scale * e_constants->A * log(p);

    return status;
} /* end SRM_ChangeCD_M */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_COM_M
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_COM_M
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
} /* end SRM_COM_M */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeM_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeM_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status              status = IMPL_VALID;

    SRM_M_CD_Specific_Constants *m_cd_spec = (SRM_M_CD_Specific_Constants*)(constants);
    Impl_ORM_Data      *e_constants=&m_cd_spec->e_constants;

    SRM_Long_Float      *dest_lat_ptr = &dest_generic_coordinate[1],
                        *dest_lon_ptr = &dest_generic_coordinate[0],
                         source_x = 0.0, source_y = 0.0, source_z = 0.0;
    SRM_Long_Float       tanz2, z;

    source_x = source_generic_coordinate[0]*m_cd_spec->scale_inv;
    source_y = source_generic_coordinate[1]*m_cd_spec->scale_inv;
    source_z = source_generic_coordinate[2];

    dest_generic_coordinate[2] = source_z;

    /* COMPUTE LONGITUDE */

    *dest_lon_ptr = source_x * e_constants->A_inv +
                    m_cd_spec->longitude_origin;

    tanz2 = exp(-source_y * e_constants->A_inv);

    z = 2.0 * atan(tanz2);

    if (e_constants->Eps!=0.0) /* compute ellipsoidal values */
    {
        SRM_Long_Float cki, den_inv, sk2, ski, t2, xki;

        /*COMPUTE ELLIPSOIDAL LATITUDE */

        /*
         * Use identity to get SIN and COS of xki without trig
         * functions
         */
        t2  = tanz2 * tanz2;
        den_inv = 1.0/(1.0 + t2);
        cki = 2.0 * tanz2*den_inv;
        ski = (1.0 - t2)*den_inv;

       /* Use inverse power series for latitude */
        sk2 = ski * ski;

        xki = SRM_PI_DIV_2 - z;

        *dest_lat_ptr = xki + ski * cki * (m_cd_spec->b1 + sk2 *
                        (m_cd_spec->b2 + sk2 *
                        (m_cd_spec->b3 + sk2 * m_cd_spec->b4)));
    }
    else
    {
        /*COMPUTE SPHERICAL LATITUDE*/
        *dest_lat_ptr = SRM_PI_DIV_2 - z;
    }
    SE_FIX_LONGITUDE(*dest_lon_ptr);

    return status;
} /* end SRM_ChangeM_CD */
