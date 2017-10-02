/*
 * SRM API
 *
 * FILE       : srm_gc.cpp
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
#include "srm_internal.h"
#include "srm_sincos.h"

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cc_to_cd_constants
 *
 *   Computes and stores the constants used for converting from CC to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   cd_srfp - a pointer to the parameters of a (destination) CD system
 *
 *   cc_cd_spec - a pointer to where the constants will be stored
 *                  for a CC to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cc_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */

#define REGION_1 0
#define REGION_2 1
#define REGION_3 2
#define REGION_4 3
#define REGION_5 4
#define REGION_UNDEFINED 5
#define REGION_SPHERICAL 6

void
set_cc_to_cd_constants
(
    const Impl_ORM_Data                *e_constants,
    const IMPL_CELESTIODETIC_SRFP      *cd_srfp,
          SRM_CC_CD_Specific_Constants *cc_cd_spec
)
{
    SRM_Long_Float CE2;
    SRM_Long_Float del[5];
    SRM_Long_Float hmn, hmx, g1, g2, g3, g4, gm, hm,
                   d1, d2, d3, d4, d5, d6, sm, rnm, zm, wm, z2, w2,
                   d7, d8, d9, d10, a1, a2, a3, a4, a5, f1, f2;
    SRM_Integer i;

    cc_cd_spec->e_constants=*e_constants;

    if (e_constants->Eps > EPSILON*EPSILON)
    {
        CE2 = e_constants->A2 - e_constants->C2;

        cc_cd_spec->Eps21  = e_constants->Eps2 - 1.0;
        cc_cd_spec->C254   = 54.0 * e_constants->C2;
        cc_cd_spec->CEEps2 = e_constants->Eps2 * CE2;
        cc_cd_spec->CEE    = e_constants->Eps2 * e_constants->Eps2;
        cc_cd_spec->TwoCEE = 2.0 * cc_cd_spec->CEE;
        cc_cd_spec->C2DA   = e_constants->C2 / e_constants->A;
        cc_cd_spec->tem    = CE2 / e_constants->C2;

        cc_cd_spec->rho     = e_constants->A / e_constants->C;
        cc_cd_spec->rho_inv = e_constants->C / e_constants->A;
        cc_cd_spec->aeps21  = e_constants->A * (e_constants->Eps2 - 1.0);
        cc_cd_spec->ak1     = e_constants->C * e_constants->Eps2 /
                              (1.0 - e_constants->Eps2);
        cc_cd_spec->ak2     = e_constants->Eps2 * e_constants->A;

        del[0] = 3E4;
        del[1] = 5E4;
        del[2] = 2.2E7 - 5E4;
        del[3] = 4.5E8 - 2.2E7;
        del[4] = 1E10;

        hmn = -30000.0;

        for (i=0; i < 5; i++)
        {
            hmx = hmn + del[i];
            g1 = gee(hmn,0.0,e_constants->A,e_constants->Eps2);  /* changed 0 to 1e-14*/
            g2 = gee(hmx,0.0,e_constants->A,e_constants->Eps2);
            g3 = gee(hmx,SRM_PI_DIV_2,e_constants->A,e_constants->Eps2);
            g4 = gee(hmn,SRM_PI_DIV_2,e_constants->A,e_constants->Eps2);

            hm = (hmx - hmn) *0.5;

            gm = gee(hm,SRM_PI_DIV_4,e_constants->A,e_constants->Eps2);

            d1 = SQUARE(e_constants->C + hmx) * g3 -
                 SQUARE(e_constants->C + hmn) * g4;
            d1 = d1 / (SQUARE(e_constants->C + hmx) -
                       SQUARE(e_constants->C + hmn));

            d2 = - (g4 - g3) / (SQUARE(e_constants->C + hmx) -
                                SQUARE(e_constants->C + hmn));

            d3 = SQUARE(e_constants->C + hmx) * d2 - g3;

            d4 = SQUARE(e_constants->C + hmx) * (g3 - d1);

            d5 = (g1 + d3) / SQUARE(e_constants->A + hmn) - (g2 + d3) /
                 SQUARE(e_constants->A + hmx);

            d5 = d5 / (g2 -g1);

            d6 = 1.0 / SQUARE(e_constants->A + hmx) -
                 1.0 / SQUARE(e_constants->A + hmn);

            d6 = d6 * d4 / (g2 - g1);

            sm = SRM_1_DIV_ROOT_2;  /*sin(SRM_PI_DIV_4)=1/sqrt(2)*/

            rnm = e_constants->A / sqrt(1.0 - e_constants->Eps2 * SQUARE(sm));

            zm = ((1.0 - e_constants->Eps2) * rnm + hm) * sm;
            wm = (rnm + hm) * SRM_1_DIV_ROOT_2;  /*cos(SRM_PI_DIV_4)=1/sqrt(2)*/

            z2 = zm * zm;
            w2 = wm * wm;

            d7 = (z2*d2 - d3 - gm - gm*w2*d5) / w2;

            d8 = (z2*gm - d4 - z2*d1 + gm*w2*d6) / w2;

            d9 = (g2 + d3) / SQUARE(e_constants->A + hmx) + g2 * d5;

            d10 = -d4 / SQUARE(e_constants->A + hmx) + d6 * g2;

            a4 = (d8 - d10) / (d9 + d7);
            a2 = d9 *a4 + d10;
            a5 = d5 * a4 + d6;
            a1 = d4 - d3 * a4;
            a3 = d1 + d2 * a4;

            cc_cd_spec->b1[i] = a3;
            cc_cd_spec->b2[i] = a1 - a3 * a4;
            cc_cd_spec->b3[i] = a2 - a3 * a5;
            cc_cd_spec->b4[i] = a4;
            cc_cd_spec->b5[i] = a5;

            f1 = SQUARE(e_constants->A + hmn - 1E-8);
            f2 = SQUARE(e_constants->C + hmn - 1E-8);

            cc_cd_spec->u[i] = f1 / f2;
            cc_cd_spec->v[i] = f1;
            hmn              = hmx;
        }
    }
    else
    {
        cc_cd_spec->Eps21  = IMPL_NAN;
        cc_cd_spec->C254   = IMPL_NAN;
        cc_cd_spec->CEEps2 = IMPL_NAN;
        cc_cd_spec->CEE    = IMPL_NAN;
        cc_cd_spec->TwoCEE = IMPL_NAN;
        cc_cd_spec->C2DA   = IMPL_NAN;
        cc_cd_spec->tem    = IMPL_NAN;
        cc_cd_spec->ARat1  = IMPL_NAN;
        cc_cd_spec->ARat2  = IMPL_NAN;
        cc_cd_spec->BRat1  = IMPL_NAN;
        cc_cd_spec->BRat2  = IMPL_NAN;
        {
            for (int i=0;i<5;i++)
            {
                cc_cd_spec->b1[i] = IMPL_NAN;
                cc_cd_spec->b2[i] = IMPL_NAN;
                cc_cd_spec->b3[i] = IMPL_NAN;
                cc_cd_spec->b4[i] = IMPL_NAN;
                cc_cd_spec->b5[i] = IMPL_NAN;
                cc_cd_spec->u[i]  = IMPL_NAN;
                cc_cd_spec->v[i]  = IMPL_NAN;
            }
        }
        cc_cd_spec->aeps21  = IMPL_NAN;
        cc_cd_spec->ak1     = IMPL_NAN;
        cc_cd_spec->ak2     = IMPL_NAN;
        cc_cd_spec->rho     = IMPL_NAN;
        cc_cd_spec->rho_inv = IMPL_NAN;
    }
} /* end set_cc_to_cd_constants */

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCC_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCC_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coord[4],
          SRM_Long_Float  dest_generic_coord[4]
)
{
    SRM_Long_Float cl, p, rr, w, w2, z2;

    SRM_Long_Float *dest_lat_ptr, *dest_lon_ptr, *dest_elv_ptr;

    SRM_Integer region = REGION_UNDEFINED;

    SRM_CC_CD_Specific_Constants *cc_cd_spec=(SRM_CC_CD_Specific_Constants*)constants;

    Impl_ORM_Data                *e_constants=&cc_cd_spec->e_constants;

    Impl_Status status = IMPL_VALID;

    SRM_Boolean done_by_special_case = SRM_FALSE;

    w2 = SQUARE(source_generic_coord[0]) + SQUARE(source_generic_coord[1]);
    z2 = SQUARE(source_generic_coord[2]);
    w  = sqrt(w2);

    dest_lon_ptr = &dest_generic_coord[0];
    dest_lat_ptr = &dest_generic_coord[1];
    dest_elv_ptr = &dest_generic_coord[2];

    if (fabs(e_constants->Eps)<= (1.0e-12))
    {
        /*This is the spherical special case*/
        /**dest_lon_ptr=atan2(source_generic_coord[1],source_generic_coord[0]);*/
        /*This is done below at the end to avoid duplicating the code*/
        *dest_lat_ptr=atan2(source_generic_coord[2]/*z*/,w);
        *dest_elv_ptr=sqrt(w2 + z2)-e_constants->A;
        region=REGION_SPHERICAL;
        goto END_REGION_CHECK;
    }
    else
    {
        /* Check for special cases */
        if (fabs(source_generic_coord[0]) <= (1.0e-12))
        {
            if (source_generic_coord[1] > 0.0)
            {
                *dest_lon_ptr = SRM_PI_DIV_2;
            }
            else if (source_generic_coord[1] < 0.0)
            {
                *dest_lon_ptr = -SRM_PI_DIV_2;
            }
            else /* y == 0 */
            {
                if (source_generic_coord[2] >= 0)
                {
                    *dest_lat_ptr = SRM_PI_DIV_2;
                    *dest_lon_ptr = 0.0;
                    *dest_elv_ptr = source_generic_coord[2] - e_constants->C;

                    done_by_special_case = SRM_TRUE;
                } /* end if z> 0 */
                else if (source_generic_coord[2] <= 0.0)
                {
                    *dest_lat_ptr = -SRM_PI_DIV_2;
                    *dest_lon_ptr =  0.0;
                    *dest_elv_ptr = - (source_generic_coord[2] + e_constants->C);

                    done_by_special_case =SRM_TRUE;
                } /* end if z < 0 */
                else
                {
                    /* at origin */

                    return IMPL_CRDDST;
                } /* end else at origin */
            } /* end else y == 0 */
        } /* end if x == 0 */
    }
  /* end of special cases */

    if (!done_by_special_case)
    {
        SRM_Long_Float ga, q, s12, top, top2, lowerBound, upperBound;

        /* region 2      0-50 kilometers*/

        lowerBound = w2 + cc_cd_spec->u[REGION_2] * z2;
        upperBound = w2 + cc_cd_spec->u[REGION_3] * z2;
        if ((lowerBound >= cc_cd_spec->v[REGION_2]) &&
            (upperBound <= cc_cd_spec->v[REGION_3]))
        {
            region = REGION_2;
        }
        else
        {
            /* region 3  50 - 23000 kilometers*/
            lowerBound = upperBound;
            upperBound = w2 + z2 * cc_cd_spec->u[REGION_4];
            if ((lowerBound >= cc_cd_spec->v[REGION_3]) &&
                (upperBound <= cc_cd_spec->v[REGION_4]))
            {
                region = REGION_3;
            }
            else
            {
                /* region 1 -30 to 0 kilometers */
                lowerBound = w2 + z2 * cc_cd_spec->u[REGION_1];
                upperBound = w2 + z2 * cc_cd_spec->u[REGION_2];
                if ((lowerBound >= cc_cd_spec->v[REGION_1]) &&
                    (upperBound <= cc_cd_spec->v[REGION_2]))
                {
                    region = REGION_1;
                }
                else
                {
                    /* region 4  23000 to 10e6 kilometers */
                    lowerBound = upperBound;
                    upperBound = w2 + z2 * cc_cd_spec->u[REGION_5];
                    if ((lowerBound >= cc_cd_spec->v[REGION_4]) &&
                        (upperBound <= cc_cd_spec->v[REGION_5]))
                    {
                        region = REGION_4;
                    }
                    else
                    {
                        /*Declare region 5 unless the following test fails*/
                        region=REGION_5;
                        /* region 5 < -30 or > 10e6 kilometers*/
                    }
                }
            }
        }

    END_REGION_CHECK:

       /* Approximation to g function*/
        ga = cc_cd_spec->b1[region] +
             (cc_cd_spec->b2[region] + cc_cd_spec->b3[region] * w2) /
             (cc_cd_spec->b4[region] + cc_cd_spec->b5[region] * w2 + z2);

      /*
        GA=B1(II)+(B2(II)+B3(II)*W2)/(B4(II)+B5(II)*W2+Z2)
      */

        switch(region)
        {
            case REGION_1:
            case REGION_2:
            {
                 SRM_Long_Float Rn;

                 top = source_generic_coord[2] *ga;
                 *dest_lat_ptr = atan2(top,w);
                 top2 = top * top;
                 rr   = top2 + w2;
                 q    = sqrt(rr);
                 s12  = top2 / rr;

                /* uses a Newton-Raphson single iteration with
                   excellent first guess using only multiplications*/

                 COMPUTE_RN_FAST(s12, Rn);

                 if (s12 <= 0.5) /* If between +- 45 degrees latitude */
                     *dest_elv_ptr = q - Rn;
                 else
                     *dest_elv_ptr = q / ga + cc_cd_spec->aeps21*Rn*e_constants->A_inv;

              /******************************************************************
               Done below at end of function as optimization
               *dest_lon_ptr = atan2(src.source_y,src.source_x);
               ****************************************************************/
                 break;
            }

            case REGION_3:
            case REGION_4:
            {
                 SRM_Long_Float bot;

                /* correct g by using it as a first guess into the bowring formula*/
                 top = source_generic_coord[2] * ga * cc_cd_spec->rho_inv;
                 top2 = top * top;
                 rr   = top2+w2;
                 q    = sqrt(rr);
                 {
                     register SRM_Long_Float qinv,sn,cn,s3,c3;
                     qinv=1.0/q;
                     sn = top *qinv;
                     cn = w*qinv;
                     s3 = CUBE(sn);
                     c3 = CUBE(cn);
                     top = source_generic_coord[2] + cc_cd_spec->ak1 * s3;
                     bot = w - cc_cd_spec->ak2 * c3;
                 }
                 top2 = SQUARE(top);
                 rr   = top2 + SQUARE(bot);
                 q    = sqrt(rr);
                 s12  = top2/rr;

                /*Fast Rn computation*/
                 {
                     SRM_Long_Float Rn;
                     COMPUTE_RN_FAST(s12, Rn);
                     /*Fast Computation of Rn = a/sqrt(1.0-Eps2*sin_squared(latitude))*/

                     if (s12 <= 0.5)
                     {
                         *dest_elv_ptr = w * q/bot - Rn;
                     }
                     else
                     {
                         *dest_elv_ptr = source_generic_coord[2]*q/top +
                           cc_cd_spec->aeps21 * Rn*e_constants->A_inv;
                     }
                 }
                 *dest_lat_ptr = atan2(top, bot);
            }
            break;
            case REGION_5:
            {
                 SRM_Long_Float alpha, arg, arg2, cf, gee, ro, roe, s, s1, v, xarg, zo;

                 cf  = cc_cd_spec->C254 * z2;
                 gee = w2 - (cc_cd_spec->Eps21 * z2) - cc_cd_spec->CEEps2;
                 {
                     SRM_Long_Float g_inv=1.0/gee;
                     alpha = cf *SQUARE(g_inv);
                     cl    = cc_cd_spec->CEE * w2 * alpha * g_inv;
                 }
                 arg2 = cl * (cl + 2.0);
                 s1   = 1.0 + cl + sqrt(arg2);
                 s    = pow(s1,(.333333333333333333333333333333));
                 {
                     SRM_Long_Float temp=s/(SQUARE(s)+1.0+s);
                     p = alpha * .333333333333333333333333333 * SQUARE(temp);
                 }
                 xarg = 1.0 + (cc_cd_spec->TwoCEE * p);
                 q    = sqrt(xarg);
                 {
                     SRM_Long_Float r1, r2;
                     SRM_Long_Float q_inv=1.0/q;
                     SRM_Long_Float one_plus_q_inv=1.0/(1.0+q);
                     r2= -p * (2.0 * (1.0 - e_constants->Eps2) * z2 * (q_inv * one_plus_q_inv)
                         + w2);
                     r1=(1.0 + q_inv);
                     r2 *=e_constants->A2_inv;
                    /*
                     * DUE TO PRECISION ERRORS THE ARGUMENT MAY BECOME
                     * NEGATIVE. IF SO SET THE ARGUMENT TO ZERO.
                     */
                     if (r1+r2 > 0.0)
                         ro = e_constants->A * sqrt(.50 * (r1+r2));
                     else
                         ro=0.0;
                     ro=ro - p * e_constants->Eps2 * w * one_plus_q_inv;
                 }
                 roe = e_constants->Eps2 * ro;
                 arg = SQUARE(w - roe) + z2;
                 v   = sqrt(arg - e_constants->Eps2 * z2);
                 {
                     SRM_Long_Float v_inv=1.0/v;
                     zo=cc_cd_spec->C2DA * source_generic_coord[2] *v_inv;
                     *dest_elv_ptr = sqrt(arg)*(1.0 - cc_cd_spec->C2DA*v_inv);
                 }
                 top=source_generic_coord[2]+ cc_cd_spec->tem*zo;
                 *dest_lat_ptr = atan(top / w);

            /************************************************************
              As an optimization, this is done below
              *dest_lon_ptr = atan2(src.source_y, src.source_x);
              ************************************************************/
                 /* end of Exact solution */
                 }
                 break;
            case REGION_SPHERICAL:
                /* This case gets out of the switch statement and lets the longitude
                 * be computed at the end of the routine with a single return statement
                 * Conclusion:  Don't Remove this case or there won't be a good way
                 * to skip the region test and this won't work very well.
                 */
                  break;

            default:
                 status=IMPL_CRDDST;
                 break;
        }

      /*Since longitude calculation is common to all regions and requires lots of time,
        we'll just do it here to break interlock and hopefully have it occur
        during some of the function return bureaucracy*/

        *dest_lon_ptr = atan2(source_generic_coord[1],source_generic_coord[0]);
    }
    return status;
}


void
set_cd_to_cc_constants
(
    const Impl_ORM_Data                *e_constants,
    const IMPL_CELESTIODETIC_SRFP      *cd_srfp,
          SRM_CD_CC_Specific_Constants *cd_cc_spec
)
{
    cd_cc_spec->e_constants=*e_constants;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_CC
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_CC
(
          void           *constants,
    const SRM_Long_Float  source_generic_coord[4],
          SRM_Long_Float  dest_generic_coord[4]
)
{
    SRM_Long_Float clat, rn, Rnc2a2, Rnhc, slat, temp;
    SRM_Long_Float source_lon = source_generic_coord[0],
                   source_lat = source_generic_coord[1],
                   source_elv = source_generic_coord[2];

    Impl_Status status = IMPL_VALID;

    SRM_CD_CC_Specific_Constants *cd_cc_spec=(SRM_CD_CC_Specific_Constants*)constants;
    Impl_ORM_Data                *e_constants=&cd_cc_spec->e_constants;

    srm_sincos(source_lat, slat, clat);

    if (e_constants->Eps!=0.0) /* compute ellipsoidal values */
    {
        temp   = e_constants->Eps25 * slat * slat;
        temp   = 0.5 - temp;
        temp   = temp + (temp - .25)/temp;
        rn     = (e_constants->A)/temp;
        Rnc2a2 = rn * e_constants->C2 / e_constants->A2;
    }
    else /* compute spherical values */
    {
        rn     = e_constants->A;
        Rnc2a2 = rn;
    }
    Rnhc = (rn + source_elv) * clat;

    dest_generic_coord[0] = Rnhc * srm_cos(source_lon);
    dest_generic_coord[1] = Rnhc * srm_sin(source_lon);
    dest_generic_coord[2] = (Rnc2a2 + source_elv) * slat;

    return status;
}
