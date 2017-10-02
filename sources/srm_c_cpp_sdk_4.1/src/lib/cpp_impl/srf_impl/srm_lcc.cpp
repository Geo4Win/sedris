/*
 * SRM API
 *
 * FILE       : srm_lcc.cpp
 *
 * PROGRAMMERS: Cameron Kellough (SRI)
 *              Bill Horan (SAIC), Howard Lu (SAIC), Dan Toms (SRI)
 *
 * DESCRIPTION: Provide reusable functions for conversions between
 *              celestiodetic and Lambert Conformal Conic for LCC
 *              with one or two standard parallels.
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 * For other release dates/detailed changes, contact SRI or SAIC.
 *
 *Change Log:
 * 03JUN2008 P. Berner
 * [1]Rho nought computation in modules:
 *    set_lcc1_to_cd_constants and set_cd_to_lcc1_constants
 * rz is computed directly instead of computing the square root of its square.
 * this prevents a loss of accuracy near the poles.
 * [2] ellipsoidal adjustment factor p in modules:
 *  SRM_ChangeCD_LCC1 and SRM_ChangeCD_LCC2
 *   Approximation replaced.
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
#include "srm_stds.h"
#include "srm_types.h"

#include "srm_internal.h"
#include "srm_sincos.h"
#include "impl_srf_params.h"

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_lcc1_to_cd_constants
 *
 *   Computes and stores the constants used for converting from LCC1 to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   lcc - a pointer to the parameters of a (source) LCC system
 *
 *   lcc1_cd_spec - a pointer to where the constants will be stored
 *                   for an LCC1 to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the lcc1_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
void
set_lcc1_to_cd_constants
(
    const Impl_ORM_Data                  *e_constants,
    const IMPL_LAMBERT_CONF_CONIC_SRFP   *lcc_srf,
          SRM_LCC1_CD_Specific_Constants *lcc1_cd_spec
)
{
    SRM_Long_Float phiz, pz, xl, rz, rz2, ex, xl2, latitude_origin,
                   sin_org, porg, pa2, pa4, pa6, pa8;

    /* phiz == standard parallel, in radians */
    /* xlonz == meridian y-axis, in radians */
    /* latitude_origin == latitude origin, in radians */
    phiz                 = lcc_srf->latitude1;
    lcc1_cd_spec->xlonz  = lcc_srf->origin_longitude;
    latitude_origin      = lcc_srf->origin_latitude;

    lcc1_cd_spec->e_constants=*e_constants;

    sin_org = srm_sin(latitude_origin);

    porg = tan(SRM_PI_DIV_4 + 0.5 * latitude_origin);

    xl  = srm_sin(phiz);
    ex  = 1.0 / (xl+xl);
    xl2 = xl * xl;

    pz = tan(SRM_PI_DIV_4 + .5 * phiz);

    if (e_constants->Eps != 0.0) /* do ellipsoid calculations */
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

        lcc1_cd_spec->b1 = pa2 *    2.0 + pa4 *   4.0 + pa6 *  6.0 + pa8 * 8.0;
        lcc1_cd_spec->b2 = pa4 *   -8.0 - pa6 *  32.0 - pa8 * 80.0;
        lcc1_cd_spec->b3 = pa6 *   32.0 + pa8 * 192.0;
        lcc1_cd_spec->b4 = pa8 * -128.0;

        pz = pow((1.0 - e_constants->Eps * xl)/(e_constants->Eps * xl + 1.0),
                 e_constants->EpsH) *  pz;

        rz  = e_constants->A*cos(phiz)/(xl*sqrt(1.0 - e_constants->Eps2 * xl2));

        porg = pow((1.0 - e_constants->Eps  * sin_org) /
                   (e_constants->Eps * sin_org + 1.0), e_constants->EpsH)*porg;
    }
    else /* do sphere calculations */
    {
        rz  = e_constants->A*cos(phiz)/xl;
    }
    rz2               = rz*rz;
    lcc1_cd_spec->pz  = pz;
    lcc1_cd_spec->rz  = rz;
    lcc1_cd_spec->rz2 = rz2;
    lcc1_cd_spec->xl  = xl;
    lcc1_cd_spec->ex  = ex;

    /* prevent divide by zero  */
    if (fabs(porg)<=.000000000001)
        pz = 0.0;
    else
        pz = pz / porg;

    lcc1_cd_spec->rho_origin = rz * pow(pz , xl);
} /* end set_lcc1_to_cd_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cd_to_lcc1_constants
 *
 *   Computes and stores the constants used for converting from CD to LCC1.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   lcc - a pointer to the parameters of a (destination) LCC1 system
 *
 *   cd_lcc1_spec - a pointer to where the constants will be stored
 *                   for a CD to LCC1 conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cd_lcc1_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
void
set_cd_to_lcc1_constants
(
    const Impl_ORM_Data                  *e_constants,
    const IMPL_LAMBERT_CONF_CONIC_SRFP   *lcc_srf,
          SRM_CD_LCC1_Specific_Constants *cd_lcc1_spec
)
{
    SRM_Long_Float AA1, AA2, AA3, AA4, AA5, AA6, AA7, AA8, AA9,
                   AB1, AB2, AB3, AB4, AB5, AB6, AB7, AB8, AB9,
                   BB1, BB2, BB3, BB4, BB5;
    SRM_Long_Float latitude_origin, phiz, porg, pz, rz, xl, xl2,
                   sin_org;

   /* phiz == standard parallel, in radians */
   /* xlonz == meridian y-axis */
    phiz                      = lcc_srf->latitude1;
    cd_lcc1_spec->xlonz       = lcc_srf->origin_longitude;
    latitude_origin           = lcc_srf->origin_latitude;
    cd_lcc1_spec->e_constants = *e_constants;

    xl  = srm_sin(phiz);
    xl2 = xl*xl;

    pz = tan(SRM_PI_DIV_4 + 0.5 * phiz);

    sin_org = srm_sin(latitude_origin);

    porg = tan(SRM_PI_DIV_4 + 0.5 * latitude_origin);

    if (e_constants->Eps!=0) /* ellipsoid calcs */
    {
        AA1= 0.100000000003490E+01;
        AA2=-0.643155723158021;
        AA3=-0.333332134894985;
        AA4=-0.241457540671514E-04;
        AA5= 0.143376648162652;
        AA6= 0.356844276587295;
        AA7=-0.333332875955149;
        AA8= 0.0;
        AA9= 0.0;

        BB1=AA1;
        BB2=e_constants->Eps2*AA2;
        BB3=e_constants->Eps2*(AA3+e_constants->Eps*(AA4+e_constants->Eps*AA5));
        BB4=e_constants->Eps2*AA6;
        BB5=e_constants->Eps2*(AA7+e_constants->Eps*(AA8+e_constants->Eps*AA9));

        cd_lcc1_spec->CR11=BB3/BB5-.187E-11;
        cd_lcc1_spec->CR12=(BB2-BB4*BB3/BB5)/BB5;
        cd_lcc1_spec->CR13=(BB1-BB3/BB5)/BB5;
        cd_lcc1_spec->CR14=1.0/BB5;
        cd_lcc1_spec->CR15=BB4/BB5;

        AB1= 0.999999999957885;
        AB2=-0.115979311942142E+01;
        AB3=-0.333339671395063;
        AB4= 0.276473457331734E-03;
        AB5= 0.587786240368508;
        AB6=-0.159793128888088;
        AB7=-0.333333465982150;
        AB8= 0.746505041501704E-04;
        AB9=-0.701559218182283E-01;

        BB1=AB1;
        BB2=e_constants->Eps2*AB2;
        BB3=e_constants->Eps2*(AB3+e_constants->Eps*(AB4+e_constants->Eps*AB5));
        BB4=e_constants->Eps2*AB6;
        BB5=e_constants->Eps2*(AB7+e_constants->Eps*(AB8+e_constants->Eps*AB9));

        cd_lcc1_spec->CR21=BB3/BB5-.2689E-11;
        cd_lcc1_spec->CR22=(BB2-BB4*BB3/BB5)/BB5;
        cd_lcc1_spec->CR23=(BB1-BB3/BB5)/BB5;
        cd_lcc1_spec->CR24=1.0/BB5;
        cd_lcc1_spec->CR25=BB4/BB5;

        pz  = pow((1.0 - e_constants->Eps * xl) / (e_constants->Eps * xl + 1.0),
                  e_constants->EpsH) * pz;

        porg = pow((1.0 - e_constants->Eps  * sin_org) /
                   (e_constants->Eps * sin_org + 1.0), e_constants->EpsH)*porg;

        rz  = e_constants->A*cos(phiz)/(xl*sqrt(1.0 - e_constants->Eps2 * xl2));
    }
    else /* for sphere */
    {
        rz  = e_constants->A*cos(phiz)/xl;
    }
    cd_lcc1_spec->xl=xl;
    cd_lcc1_spec->pz=pz;
    cd_lcc1_spec->rz=rz;

   /* prevent divide by zero  */
    if (fabs(porg)<=.000000000001)
        pz = 0.0;
    else
        pz = pz / porg;

    cd_lcc1_spec->rho_origin = rz * pow(pz , xl);
} /* end set cd_to_lcc1_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_lcc2_to_cd_constants
 *
 *   Computes and stores the constants used for converting from LCC2 to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   lcc - a pointer to the parameters of a (source) LCC system
 *
 *   lcc2_cd_spec - a pointer to where the constants will be stored
 *                   for an LCC2 to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the lcc2_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
void
set_lcc2_to_cd_constants
(
    const Impl_ORM_Data                  *e_constants,
    const IMPL_LAMBERT_CONF_CONIC_SRFP   *lcc_srf,
          SRM_LCC2_CD_Specific_Constants *lcc2_cd_spec
)
{
    SRM_Long_Float phiz1, phiz2, latitude_origin, sfx, pz, s1, s12, c12, p1,
                   s2, s22, p2, rn12, rn22, temp, xl, rz, ex, c22, rz2,
                   pa2, pa4, pa6, pa8;

    phiz1                = lcc_srf->latitude1;
    phiz2                = lcc_srf->latitude2;
    lcc2_cd_spec->xlonz  = lcc_srf->origin_longitude;
    latitude_origin      = lcc_srf->origin_latitude;

    lcc2_cd_spec->e_constants=*e_constants;

    /* phix == fixed latitude */
    /* xlonz == meridian y-axis */

    pa2  = e_constants->Eps2 / 2.0 + pow(e_constants->Eps2, 2) * 5.0 / 24.0;

    pa2 += pow(e_constants->Eps2, 3) / 12.0 +
           pow(e_constants->Eps2, 4) * 13.0 / 360.0;

    pa4  = pow(e_constants->Eps2, 2) * 7.0 / 48.0 +
           pow(e_constants->Eps2, 3) * 29.0 / 240.0;

    pa4 += pow(e_constants->Eps2, 4) * 811.0 / 11520.0;

    pa6  = pow(e_constants->Eps2, 3) * 7.0 / 120.0 +
           pow(e_constants->Eps2, 4) * 81.0 / 1120.0;

    pa8  = pow(e_constants->Eps2, 4) * 4279.0 / 161280.0;

    lcc2_cd_spec->b1 = pa2 *    2.0 + pa4 *   4.0 + pa6 *  6.0 + pa8 * 8.0;
    lcc2_cd_spec->b2 = pa4 *   -8.0 - pa6 *  32.0 - pa8 * 80.0;
    lcc2_cd_spec->b3 = pa6 *   32.0 + pa8 * 192.0;
    lcc2_cd_spec->b4 = pa8 * -128.0;

    sfx = srm_sin(latitude_origin);
    s1  = srm_sin(phiz1);
    s2  = srm_sin(phiz2);
    s12 = s1 * s1;
    c12 = 1.0 - s12;
    s22 = s2 * s2;
    c22 = 1.0 - s22;

    pz = tan(SRM_PI_DIV_4 + .5 * latitude_origin);

    p1 = tan(SRM_PI_DIV_4 + .5 * phiz1);
    p2 = tan(SRM_PI_DIV_4 + .5 * phiz2);

    if (e_constants->Eps!=0.0) /* compute ellipsoidal values */
    {
        pz = pz *pow((1.0 - e_constants->Eps * sfx) /
                     (e_constants->Eps * sfx + 1.0),e_constants->EpsH);

        p1  = p1 * pow((1.0 - e_constants->Eps * s1) /
                       (e_constants->Eps * s1 + 1.0),e_constants->EpsH);

        p2  = p2 * pow((1.0 - e_constants->Eps * s2) /
                       (e_constants->Eps * s2 + 1.0),e_constants->EpsH);

        rn12 = e_constants->A2 / (1.0 - e_constants->Eps2 * s12);
        rn22 = e_constants->A2 / (1.0 - e_constants->Eps2 * s22);

        temp = p2 / p1;

        xl  = .5 * log((rn12 * c12) / (c22 * rn22)) / log(temp);
    }
    else /* compute spherical values */
    {
        temp = p2 / p1;
        rn12=e_constants->A2;
        xl = .5 * log(c12/c22)/log(temp);
    }
    rz2 = rn12 * c12 / (xl*xl);

    rz  = sqrt(rz2) * pow(p1/pz,xl);

    ex  = 1.0 / (xl+xl);

    lcc2_cd_spec->rz  = rz;
    lcc2_cd_spec->xl  = xl;
    lcc2_cd_spec->ex  = ex;
    lcc2_cd_spec->rz2 = rz2;
    lcc2_cd_spec->p1  = p1;
} /* end set_lcc2_to_cd_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cd_to_lcc2_constants
 *
 *----------------------------------------------------------------------------
 */
void
set_cd_to_lcc2_constants
(
    const Impl_ORM_Data                  *e_constants,
    const IMPL_LAMBERT_CONF_CONIC_SRFP   *lcc_srf,
          SRM_CD_LCC2_Specific_Constants *cd_lcc2_spec
)
{
    SRM_Long_Float AA1,AA2,AA3,AA4,AA5,AA6,AA7,AA8,AA9,
                   AB1,AB2,AB3,AB4,AB5,AB6,AB7,AB8,AB9,
                   BB1,BB2,BB3,BB4,BB5;
    SRM_Long_Float phiz1, phiz2, latitude_origin,sfx,pz,s1,s12,c12,p1,
                   s2,s22,p2,rn12,rn22,temp,xl,rx2,rz,c22,rx;

   /* phiz == standard parallels */
   /* xlonz == meridian y-axis */
    phiz1                = lcc_srf->latitude1;
    phiz2                = lcc_srf->latitude2;
    cd_lcc2_spec->xlonz  = lcc_srf->origin_longitude;
    latitude_origin      = lcc_srf->origin_latitude;

    cd_lcc2_spec->e_constants=*e_constants;

   /* phix == fixed latitude */

   /*
    * test whether this is a spherical transformation(Eps=0);
    * if not, then we compute these constants
    */
    if (e_constants->Eps!=0.0) /* compute ellipsoidal values */
    {
        AA1= 0.100000000003490E+01;
        AA2=-0.643155723158021;
        AA3=-0.333332134894985;
        AA4=-0.241457540671514E-04;
        AA5= 0.143376648162652;
        AA6= 0.356844276587295;
        AA7=-0.333332875955149;
        AA8= 0.0;
        AA9= 0.0;

        BB1=AA1;
        BB2=e_constants->Eps2*AA2;
        BB3=e_constants->Eps2*(AA3+e_constants->Eps*(AA4+e_constants->Eps*AA5));
        BB4=e_constants->Eps2*AA6;
        BB5=e_constants->Eps2*(AA7+e_constants->Eps*(AA8+e_constants->Eps*AA9));

        cd_lcc2_spec->CR11=BB3/BB5-.187E-11;
        cd_lcc2_spec->CR12=(BB2-BB4*BB3/BB5)/BB5;
        cd_lcc2_spec->CR13=(BB1-BB3/BB5)/BB5;
        cd_lcc2_spec->CR14=1.0/BB5;
        cd_lcc2_spec->CR15=BB4/BB5;

        AB1= 0.999999999957885;
        AB2=-0.115979311942142E+01;
        AB3=-0.333339671395063;
        AB4= 0.276473457331734E-03;
        AB5= 0.587786240368508;
        AB6=-0.159793128888088;
        AB7=-0.333333465982150;
        AB8= 0.746505041501704E-04;
        AB9=-0.701559218182283E-01;

        BB1=AB1;
        BB2=e_constants->Eps2*AB2;
        BB3=e_constants->Eps2*(AB3+e_constants->Eps*(AB4+e_constants->Eps*AB5));
        BB4=e_constants->Eps2*AB6;
        BB5=e_constants->Eps2*(AB7+e_constants->Eps*(AB8+e_constants->Eps*AB9));

        cd_lcc2_spec->CR21=BB3/BB5-.2689E-11;
        cd_lcc2_spec->CR22=(BB2-BB4*BB3/BB5)/BB5;
        cd_lcc2_spec->CR23=(BB1-BB3/BB5)/BB5;
        cd_lcc2_spec->CR24=1.0/BB5;
        cd_lcc2_spec->CR25=BB4/BB5;
    } /* end if not spherical */

    sfx = srm_sin(latitude_origin);
    s1  = srm_sin(phiz1);
    s2  = srm_sin(phiz2);

    s12 = s1*s1;
    c12 = 1.0-s12;

    s22 = s2*s2;
    c22 = 1.0-s22;

    pz = tan(SRM_PI_DIV_4 + (0.5 * latitude_origin));
    p1 = tan(SRM_PI_DIV_4 + (0.5 * phiz1));
    p2 = tan(SRM_PI_DIV_4 + (0.5 * phiz2));

    if (e_constants->Eps!=0.0) /* compute ellipsoidal values */
    {
        pz  = pz * pow((1.0 - e_constants->Eps * sfx)/
              (e_constants->Eps * sfx + 1.0),e_constants->EpsH);

        p1  = p1 * pow((1.0 - e_constants->Eps * s1)/
              (e_constants->Eps * s1 + 1.0),e_constants->EpsH);

        p2  = p2 * pow((1.0 - e_constants->Eps * s2)/
              (e_constants->Eps * s2 + 1.0),e_constants->EpsH);

        rn12 = e_constants->A2 / (1.0 - (e_constants->Eps2 * s12));
        rn22 = e_constants->A2 / (1.0 - (e_constants->Eps2 * s22));
        temp = p2/p1;
        xl  = .5 * log( (rn12 * c12)/( c22 * rn22 ) ) / log(temp);
    }
    else /* compute spherical values */
    {
        rn12 = e_constants->A2;
        temp = p2 / p1;
        xl = 0.5 * log( c12 / c22) / log(temp);
    }
    rx2 = rn12 * c12 / (xl * xl);
    rx  = sqrt(rx2);
    rz  = rx * pow(p1 / pz,xl);

    cd_lcc2_spec->rx = rx;
    cd_lcc2_spec->rz = rz;
    cd_lcc2_spec->xl = xl;
    cd_lcc2_spec->p1 = p1;
} /* end set_cd_to_lcc2_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_LCC1
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_LCC1
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status                     status = IMPL_VALID;
    SRM_CD_LCC1_Specific_Constants *cd_lcc1_spec = (SRM_CD_LCC1_Specific_Constants*)(constants);
    SRM_Long_Float                 *dest_x_ptr = NULL, *dest_y_ptr = NULL,
                                    source_elv, source_lat, source_lon;
    SRM_Long_Float                  arg, dlon, p, r, s1, sl, t;
    Impl_ORM_Data                  *e_constants = NULL;

    source_lon = source_generic_coordinate[0];
    source_lat = source_generic_coordinate[1];
    source_elv = source_generic_coordinate[2];

    dest_generic_coordinate[2]=source_elv;

    e_constants=&cd_lcc1_spec->e_constants;

    dest_x_ptr = &dest_generic_coordinate[0];
    dest_y_ptr = &dest_generic_coordinate[1];

    sl   = srm_sin(source_lat);

    if (e_constants->Eps!=0.0) /* do ellipsoid calcs */
    {
        SRM_Long_Float esl = e_constants->Eps * sl;
        p = pow( (1.0 + esl)/(1.0 - esl), e_constants->EpsH);
    }
    else /* for sphere */
    {
        p=1.0;
    }
    p = p * tan(SRM_PI_DIV_4 - 0.5 * source_lat);
    r = cd_lcc1_spec->rz * pow(cd_lcc1_spec->pz*p,cd_lcc1_spec->xl);

    GET_LAMBDA_STAR(source_lon, cd_lcc1_spec->xlonz, dlon);

    arg = cd_lcc1_spec->xl * dlon;

    srm_sincos(arg, s1, t);

    *dest_x_ptr = r * s1;
    *dest_y_ptr = cd_lcc1_spec->rho_origin - (r * t);

    /* fix signs */
    if (cd_lcc1_spec->xl < 0.0)
    {
        *dest_x_ptr=-*dest_x_ptr;
        *dest_y_ptr=-*dest_y_ptr;
    }
    return status;
} /* end SRM_ChangeCD_LCC1 */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_LCC2
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_LCC2
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status                     status = IMPL_VALID;
    SRM_CD_LCC2_Specific_Constants *cd_lcc2_spec = (SRM_CD_LCC2_Specific_Constants*)(constants);
    SRM_Long_Float                 *dest_x_ptr = &dest_generic_coordinate[0],
                                   *dest_y_ptr = &dest_generic_coordinate[1],
                                    source_lon = source_generic_coordinate[0],
                                    source_lat = source_generic_coordinate[1],
                                    source_elv = source_generic_coordinate[2];
    SRM_Long_Float                  arg, dlon, p, r, s1, sl, t;
    Impl_ORM_Data                  *e_constants=&cd_lcc2_spec->e_constants;

    dest_generic_coordinate[2]=source_elv;

    sl = srm_sin(source_lat);

    if (e_constants->Eps!=0.0) /* compute ellipsoidal values */
    {
        SRM_Long_Float esl = e_constants->Eps * sl;
        p = pow( (1.0 + esl)/(1.0 - esl), e_constants->EpsH);
    }
    else /* compute spherical values */
    {
        p=1.0;
    }

    /*
     * if sl < sin(89 degrees)
     */
    p=p * tan(SRM_PI_DIV_4 - .5 * source_lat);
    r = cd_lcc2_spec->rx*pow(cd_lcc2_spec->p1*p,cd_lcc2_spec->xl);

    GET_LAMBDA_STAR(source_lon, cd_lcc2_spec->xlonz,dlon);

    arg = cd_lcc2_spec->xl*dlon;

    srm_sincos(arg, s1, t);

    *dest_x_ptr=r * s1;
    *dest_y_ptr=cd_lcc2_spec->rz - r * t;

    if (cd_lcc2_spec->xl < 0)
    {
        *dest_x_ptr=-*dest_x_ptr;
        *dest_y_ptr=-*dest_y_ptr;
    }
    return status;
} /* end SRM_ChangeCD_LCC2 */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLCC1_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeLCC1_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status                     status = IMPL_VALID;
    SRM_LCC1_CD_Specific_Constants *lcc1_cd_spec =
                                (SRM_LCC1_CD_Specific_Constants*)(constants);
    SRM_Long_Float                 *dest_lat_ptr = NULL, *dest_lon_ptr = NULL,
                                    source_x=0.0, source_y=0.0, source_z=0.0;
    SRM_Long_Float                  cki, den, drz, r2, ski, tanz2, t2, thet, xki;
    Impl_ORM_Data                  *e_constants;

    source_x = source_generic_coordinate[0];
    source_y = source_generic_coordinate[1];
    source_z = source_generic_coordinate[2];

    e_constants=&lcc1_cd_spec->e_constants;

    dest_lon_ptr = &dest_generic_coordinate[0];
    dest_lat_ptr = &dest_generic_coordinate[1];

    if (lcc1_cd_spec->xl < 0.0)
    {
        source_x = -source_x;
        source_y = -source_y;
    }
    drz  = lcc1_cd_spec->rho_origin - source_y;
    thet = atan2(source_x, drz);
   *dest_lon_ptr = thet / lcc1_cd_spec->xl +
                   lcc1_cd_spec->xlonz;

  /* get latitude using inverse power series */

  /* Get r squared  */
    r2    = source_x * source_x + drz * drz;
    tanz2 = pow(r2 / lcc1_cd_spec->rz2, lcc1_cd_spec->ex) /
            lcc1_cd_spec->pz;

    if (e_constants->Eps != 0.0) /* do ellipsoid calculations */
    {
        SRM_Long_Float sk2, z;

       /* Use Identity to get sin & cos without trig functions */
        t2  = tanz2 * tanz2;
        den = 1.0 + t2;
        cki = 2.0 * tanz2 / den;
        ski = (1.0 -t2) / den;

        sk2 = ski * ski;
        z   = 2.0 * atan(tanz2);
        xki = SRM_PI_DIV_2 - z;

       *dest_lat_ptr = xki + ski * cki *
                       (lcc1_cd_spec->b1 + sk2 * (lcc1_cd_spec->b2 + sk2   *
                       (lcc1_cd_spec->b3 + sk2 * lcc1_cd_spec->b4)));
    }
    else /* do spherical calculations */
    {
        *dest_lat_ptr = (SRM_PI_DIV_2) - 2.0 *atan(tanz2);
    }
    SE_FIX_LONGITUDE(*dest_lon_ptr);

    dest_generic_coordinate[2] =source_z;
    return status;
} /* end SRM_ChangeLCC1_CD */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeLCC2_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeLCC2_CD
(
          void              *constants,
    const SRM_Long_Float    source_generic_coordinate[4],
          SRM_Long_Float    dest_generic_coordinate[4]

)
{
    Impl_Status                 status = IMPL_VALID;
    SRM_LCC2_CD_Specific_Constants *lcc2_cd_spec = (SRM_LCC2_CD_Specific_Constants*)(constants);
    SRM_Long_Float                 *dest_lat_ptr = &dest_generic_coordinate[1],
                                   *dest_lon_ptr = &dest_generic_coordinate[0],
                                    source_x = source_generic_coordinate[0],
                                    source_y = source_generic_coordinate[1],
                                    source_z = source_generic_coordinate[2];
    SRM_Long_Float                  drz, r2, tanz2, thet;
    Impl_ORM_Data      *e_constants=&lcc2_cd_spec->e_constants;

    dest_generic_coordinate[2]=source_z;

   /*
    * LATITUDE FIRST USING INVERSE POWER SERIES
    */
    if (lcc2_cd_spec->xl < 0.0)
    {
        source_x = -source_x;
        source_y = -source_y;
    }
    drz = lcc2_cd_spec->rz - source_y;

   /* Get r2 */
    r2    = (source_x * source_x) + (drz * drz);

    tanz2 = pow(r2/lcc2_cd_spec->rz2, lcc2_cd_spec->ex)/
            lcc2_cd_spec->p1;

    if (e_constants->Eps != 0.0) /* compute ellipsoidal values */
    {
        SRM_Long_Float cki, den, sk2, ski, t2, xki, z;

       /*
        * Use Identity to get sin & cos without trig functions
        */
        t2  = tanz2 * tanz2;
        den = 1.0 + t2;
        cki = 2.0 * tanz2 / den;
        ski = (1.0 - t2) / den;
       /* Sin and Cos of xki now done */

       /* Use inverse power series for latitude */
        sk2 = ski * ski;
        z   = 2.0 * atan(tanz2);
        xki = SRM_PI_DIV_2 - z;

        *dest_lat_ptr = xki +
                        ski * cki * (lcc2_cd_spec->b1 + sk2 *
                       (lcc2_cd_spec->b2 + sk2 *
                        (lcc2_cd_spec->b3 + sk2 *
                         lcc2_cd_spec->b4)));
    }
    else /* compute spherical values */
    {
       *dest_lat_ptr = SRM_PI_DIV_2 - 2.0* atan(tanz2);
    }
    thet = atan2(source_x, drz);

   *dest_lon_ptr =
         thet/lcc2_cd_spec->xl + lcc2_cd_spec->xlonz;

    SE_FIX_LONGITUDE(*dest_lon_ptr);

    return status;
} /* end SRM_ChangeLCC2_CD */
