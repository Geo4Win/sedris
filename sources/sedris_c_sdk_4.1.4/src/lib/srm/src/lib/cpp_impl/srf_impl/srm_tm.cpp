/*
 * SRM API
 *
 * FILE       : srm_tm.cpp
 *
 * PROGRAMMERS: Cameron Kellough (SRI)
 *              Bill Horan (SAIC), Howard Lu (SAIC), Dan Toms (SRI)
 *
 * DESCRIPTION: Provide reusable functions for conversions between
 *              TM and CD.
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 * For other release dates/detailed changes, contact SRI or SAIC.
 *
 * CHANGE LOG:
 * SRM_ChangeCD_TM and SRM_ChangeTM_CD: Sphere case replaced 06JUN2008
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
#include "srm_internal.h"
#include "srm_sincos.h"

#define ATANH(x) (log((1.0+x)/(1.0-x))*0.5)

#define ONE_POINT_ONE_DEGREES .0191986217719376253459
#define TWO_POINT_FOUR_DEGREES .0418879020478639098456
#define FOUR_POINT_ZERO_DEGREES .069813170079773183076

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: Impl_Exact_Arc_Length
 *
 *----------------------------------------------------------------------------
 */
SRM_Long_Float Impl_Exact_Arc_Length
(
    SRM_Long_Float a,
    SRM_Long_Float c_unused, /* parameter isn't used; previously named c */
    SRM_Long_Float e2,
    SRM_Long_Float xlat
)
{
    SRM_Long_Float c1,c2,c3,c4,c5,c6,con,e4,e6,t1,t2,t3,t4,t5,t6;

    c1 = 1.0 + e2 * (0.75 +
                     e2 * (45.0 / 64.0 +
                           e2 * (175.0 / 256.0 +
                                 e2 * (11025.0 / 16384.0 +
                                       e2 * (43659.0 / 65536.0)))));
    c2 = e2 * (0.75 +
               e2 * (15.0 / 16.0 +
                     e2 * (525.0 / 512.0 +
                           e2 * (2205.0 / 2048.0 + e2 * (72765.0 / 65536.0)))));

    e4 = e2 * e2;
    c3 = e4 * (15.0 / 64.0 +
               e2 * (105.0 / 256.0 +
                     e2 * (2205.0 / 4096.0 + e2 * 10395.0 / 16384)));
    e6 = e4 * e2;
    c4 = e6 * (35.0 / 512.0 + e2 * (315.0 / 2048.0 + e2 * 31185.0 / 131072.0));
    c5 = e4 * e4 * (315.0 / 16384.0 + e2 * 3465.0 / 65536.0);
    c6 = e4 * e6 * 693.0 / 131072.0;

    con = a * (1.0 - e2);

    t1 = con * c1 * xlat;
    t2 = con * c2;
    t3 = con * c3;
    t4 = con * c4;
    t5 = con * c5;
    t6 = con * c6;

    t2 = t2 * srm_sin(2.0 * xlat) / 2.0;
    t3 = t3 * srm_sin(4.0 * xlat) / 4.0;
    t4 = t4 * srm_sin(6.0 * xlat) / 6.0;
    t5 = t5 * srm_sin(8.0 * xlat) / 8.0;
    t6 = t6 * srm_sin(10.0 * xlat) / 10.0;
#if 0
    t6=0.0;
   /* This allows us to simulate a series that only uses 8 terms */
#endif

    return(t1 - t2 + t3 - t4 + t5 -t6);
} /* end Impl_Exact_Arc_Length */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_cd_to_tm_constants
 *
 *----------------------------------------------------------------------------
 */
void
set_cd_to_tm_constants
(
    const Impl_ORM_Data                 *e_constants,
    const IMPL_TRANSVERSE_MERCATOR_SRFP *tm_srf,
          SRM_CD_TM_Specific_Constants  *cd_tm_spec
)
{
    cd_tm_spec->Cdb6     = 0.166666666666667;
    cd_tm_spec->Cdb24    = 0.416666666666667e-1;
    cd_tm_spec->Cdb120   = 0.833333333333333e-2;
    cd_tm_spec->Cdb720   = 0.138888888888888e-2;
    cd_tm_spec->Cdb5040  = 1.0/5040;
    cd_tm_spec->Cdb40320 = 1.0/40320.0;

    /* End of identical constants*/
    cd_tm_spec->longitude_origin = tm_srf->origin_longitude;
    cd_tm_spec->latitude_origin  = tm_srf->origin_latitude;
    cd_tm_spec->CScale           = tm_srf->central_scale;

    cd_tm_spec->e_constants=*e_constants;

    if (e_constants->Eps != 0.0) /* compute ellipsoidal values */
    {
        cd_tm_spec->Smz=Impl_Exact_Arc_Length(e_constants->A,
                                              e_constants->C,
                                              e_constants->Eps2,
                                              cd_tm_spec->latitude_origin);
        Impl_ComputeArcLengthConstants(e_constants,
                                       &(cd_tm_spec->arclength_spec));
    }
    else /* compute spherical values */
    {
        cd_tm_spec->Smz = e_constants->A * cd_tm_spec->latitude_origin;
    }
} /* end set_cd_to_tm_constants */


/*
 * Using these values as static constants prevents them from being created
 * and copied and passed around as more baggage data with the
 * tm_cd_specific constants.
 *
 * These constants were previously stored as part of the specific constants.
 */
static const SRM_Long_Float con_lon6=1.0/6.0;
static const SRM_Long_Float con_lon120=1.0/120.0;
static const SRM_Long_Float con_lon5040=1.0/5040;


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_tm_to_cd_constants
 *
 *   Computes and stores the constants used for converting from TM to CD.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   tm - a pointer to the parameters of a (source) TM system
 *
 *   tm_cd_spec - a pointer to where the constants will be stored
 *                  for a TM to CD conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the tm_cd_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
void set_tm_to_cd_constants
(
    const Impl_ORM_Data                 *e_constants,
    const IMPL_TRANSVERSE_MERCATOR_SRFP *tm_srf,
          SRM_TM_CD_Specific_Constants  *tm_cd_spec
)
{
    tm_cd_spec->longitude_origin = tm_srf->origin_longitude;
    tm_cd_spec->latitude_origin  = tm_srf->origin_latitude;
    tm_cd_spec->CScale           = tm_srf->central_scale;
    tm_cd_spec->CScale_inv       = 1.0/tm_cd_spec->CScale;

   /*
    * Note that remembering to copy the e_constants to the conversion parameters
    * is the only way to avoid driving yourself mad getting NaN's because the
    * initialization logic is trying to tell you that you didn't initialize
    * something. -CDK June 21, 2005
    */
    tm_cd_spec->e_constants=*e_constants;

    tm_cd_spec->con_lat      = 1.0/(1.0-e_constants->Eps2);
    tm_cd_spec->con_lat2     = 0.5*tm_cd_spec->con_lat;
    tm_cd_spec->con_lat24    = tm_cd_spec->con_lat/24.0;
    tm_cd_spec->con_lat120   = tm_cd_spec->con_lat/120.0;
    tm_cd_spec->con_lat720   = tm_cd_spec->con_lat/720.0;
    tm_cd_spec->con_lat40320 = tm_cd_spec->con_lat/40320.0;

    if (e_constants->Eps != 0.0) /* compute ellipsoidal values */
    {
        Impl_ComputeArcLengthConstants(e_constants,
                                       &(tm_cd_spec->arclength_spec));
       /*
        * The arc length approximation Impl_ArcLength() should not be used in
        * the initialization as it causes a 20 metre accuracy loss for
        * British National Grid. It's fine in the routine itself where the
        * values are less.
        */
        tm_cd_spec->smz=Impl_Exact_Arc_Length(e_constants->A, e_constants->C,
                                              e_constants->Eps2,
                                              tm_cd_spec->latitude_origin);

        tm_cd_spec->conap=
         e_constants->A* (1.0-
                          e_constants->Eps2*
                          (.250+
                           e_constants->Eps2*
                           (.0468750+
                            e_constants->Eps2* (0.019531250+
                                                0.010681152343750*
                                                e_constants->Eps2))));

        Impl_ComputeFootpointConstants(e_constants,
                                       &(tm_cd_spec->arclength_spec),
                                       &(tm_cd_spec->footpoint_spec),
                                       tm_cd_spec->CScale);
    }
    else /* compute spherical values */
    {
        tm_cd_spec->smz = e_constants->A * tm_cd_spec->latitude_origin;
        tm_cd_spec->conap = e_constants->A;
    }

   /*needs to be done in both cases*/
    tm_cd_spec->conap_inv=1.0/tm_cd_spec->conap;
} /* end set_tm_to_cd_constants */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeCD_TM
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeCD_TM
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status  status = IMPL_VALID;
    SRM_Long_Float
        *dest_x_ptr = &dest_generic_coordinate[0],
        *dest_y_ptr = &dest_generic_coordinate[1],
        *dest_z_ptr = &dest_generic_coordinate[2],
        source_lon  = source_generic_coordinate[0],
        source_lat  = source_generic_coordinate[1],
        source_elv  = source_generic_coordinate[2];

    SRM_Long_Float
        al=IMPL_NAN,
        al2=IMPL_NAN,
        lambda_star=IMPL_NAN,
        sin_lat=IMPL_NAN,
        cos_lat=IMPL_NAN,
        Sm=IMPL_NAN,
        tan_lat_squared=IMPL_NAN,
        tan_lat=IMPL_NAN,
        sin_squared_lat=IMPL_NAN;

    SRM_CD_TM_Specific_Constants *cd_tm_spec=(SRM_CD_TM_Specific_Constants*)
                                             (constants);
    Impl_ORM_Data                *e_constants=&cd_tm_spec->e_constants;

    srm_sincos(source_lat, sin_lat, cos_lat);

   /*
    * cos_lat cannot be zero as long as TM-specific coordinate validation
    * has been invoked before this routine is invoked
    */
    tan_lat         = sin_lat/cos_lat; /*tx*/
    tan_lat_squared = SQUARE(tan_lat); /*tn2*/
    sin_squared_lat = SQUARE(sin_lat);

    GET_LAMBDA_STAR(source_lon, cd_tm_spec->longitude_origin, lambda_star);

   /*!\bug Note that the changes made to replace dlon with
           lambda_star must be made to the convergence of the meridian
           routines
    */
    al  = lambda_star * cos_lat;
    al2 = al * al;

    if (e_constants->Eps != 0.0) /* compute ellipsoidal values */
    {
        SRM_Long_Float Fe, Fn, Rn;
        SRM_Long_Float cee=e_constants->Epps2*cos_lat*cos_lat;
        SRM_Long_Float cee_squared=SQUARE(cee);

        COMPUTE_RN(sin_squared_lat,Rn);

#if 0
        Sm=Impl_Exact_Arc_Length(e_constants->A, e_constants->C,
                                 e_constants->Eps2, source_lat);
       /*The highly accurate 8th order series approximation was if'd out and
         replaced with the very fast approximation below. CDK Jan 21, 2005
        */
#endif
        Sm=Impl_ArcLength(&(cd_tm_spec->arclength_spec), source_lat,
                          sin_lat, cos_lat);

       /*
        * here we are taking only enough terms to meet
        * accuracy requirements based on our location
        */
        if (fabs(lambda_star) <= ONE_POINT_ONE_DEGREES)
        {
            register SRM_Long_Float polx1 = 1.0 - tan_lat_squared + cee;
            register SRM_Long_Float poly1 = 5.0 - tan_lat_squared;

            Fe = 1.0+al2*polx1*cd_tm_spec->Cdb6;
            Fn = 0.5+al2*poly1*cd_tm_spec->Cdb24;
        }
        else if (fabs(lambda_star) <= TWO_POINT_FOUR_DEGREES)
        {
            register SRM_Long_Float polx1 = 1.0 - tan_lat_squared+cee;
            register SRM_Long_Float polx2 = 5.0 + tan_lat_squared*
                                                  (tan_lat_squared-18.0);
            register SRM_Long_Float poly1 = (5.0-tan_lat_squared) +
                                            cee*(9.0 + 4.0*cee);

            Fe = 1.0+al2*(polx1*cd_tm_spec->Cdb6+al2*polx2*cd_tm_spec->Cdb120);
            Fn = 0.5+al2*poly1*cd_tm_spec->Cdb24;
        }
        else if (fabs(lambda_star) <= FOUR_POINT_ZERO_DEGREES)
        {
            SRM_Long_Float polx1     = 1.0 - tan_lat_squared+cee;
            SRM_Long_Float tmp_polx2 = 5.0 + tan_lat_squared*
                                             (tan_lat_squared-18.0);
            SRM_Long_Float polx2 = tmp_polx2+cee*(14.0-58.0*tan_lat_squared);
            SRM_Long_Float poly1 = (5.0-tan_lat_squared) +cee*(9.0 + 4.0*cee);
            SRM_Long_Float tmp_poly2 = 61.0 +
                                       tan_lat_squared*(tan_lat_squared-58.0);
            SRM_Long_Float poly2 = tmp_poly2+cee*(270.0-330.0*tan_lat_squared);

            Fe = 1.0+al2*(polx1*cd_tm_spec->Cdb6+al2*polx2*cd_tm_spec->Cdb120);
            Fn = 0.5+al2*(poly1*cd_tm_spec->Cdb24+al2 *poly2*cd_tm_spec->Cdb720);
        }
        else
        {
            SRM_Long_Float polx1 = 1.0 - tan_lat_squared+cee;
            SRM_Long_Float tx2 = cee_squared*(13.0 + cee*4.0 -
                                              tan_lat_squared*(64.0+24.0*cee));
            SRM_Long_Float polx2 = tx2 + 5.0 +
                                   tan_lat_squared*(tan_lat_squared-18.0) +
                                   cee*(14.0-58.0*tan_lat_squared);
            SRM_Long_Float polx3 = 61.0 +
                                   tan_lat_squared*(-479.0 + tan_lat_squared*(179.0-tan_lat_squared));

            SRM_Long_Float poly1 = (5.0-tan_lat_squared) +cee*(9.0 + 4.0*cee);
            SRM_Long_Float tmp_poly2 = 61.0+tan_lat_squared*(tan_lat_squared-58.0);
            SRM_Long_Float poly2 = tmp_poly2+cee*(270.0-330.0*tan_lat_squared);
            SRM_Long_Float tmp_ty2 = poly2+445.0*SQUARE(cee);
            SRM_Long_Float tmp2_ty2 = tmp_ty2+324.0*CUBE(cee)-680.0*tan_lat_squared*SQUARE(cee);
            SRM_Long_Float ty2 = tmp2_ty2+88.0*SQUARE(cee)*SQUARE(cee)-600.0*tan_lat_squared*CUBE(cee);
            SRM_Long_Float new_poly2 = ty2-192.0*tan_lat_squared*SQUARE(cee)*SQUARE(cee);
            SRM_Long_Float new_poly3 = 1385.0+tan_lat_squared*(-3111.0+tan_lat_squared*(543.0-tan_lat_squared));

            Fe = 1.0+al2*(polx1*cd_tm_spec->Cdb6+al2*(polx2*cd_tm_spec->Cdb120+al2*polx3*cd_tm_spec->Cdb5040));
            Fn = 0.5+al2*(poly1*cd_tm_spec->Cdb24+al2*(new_poly2*cd_tm_spec->Cdb720+al2*new_poly3*cd_tm_spec->Cdb40320));
        }
        *dest_x_ptr = Fe*al*cd_tm_spec->CScale*Rn;
        *dest_y_ptr = cd_tm_spec->CScale*(Sm-cd_tm_spec->Smz+Rn*tan_lat*al2*Fn);
    }
    else /* compute spherical values */
    {
        SRM_Long_Float clbt, Rn, slbt;

        srm_sincos(lambda_star, slbt, clbt);

        Rn = cd_tm_spec->CScale * e_constants->A;

        *dest_x_ptr = Rn * ATANH(cos_lat*slbt);
        *dest_y_ptr = Rn * (atan(tan_lat/clbt) - cd_tm_spec->latitude_origin);
    }
   /*CDK Nov 2, 2004. The false easting and northing are added
     elsewhere; adding them in this routine would be double counting
    */
    *dest_z_ptr=source_elv;

    return status;
} /* end SRM_ChangeCD_TM */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_ChangeTM_CD
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
SRM_ChangeTM_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    SRM_TM_CD_Specific_Constants *tm_cd_spec = (SRM_TM_CD_Specific_Constants *)
                                               (constants);

    SRM_Long_Float *dest_lat_ptr=&dest_generic_coordinate[1],
                   *dest_lon_ptr=&dest_generic_coordinate[0];

    Impl_ORM_Data  *e_constants=&tm_cd_spec->e_constants;

    Impl_Status     status = IMPL_VALID;

    SRM_Long_Float src_coord[4]={
        src_coord[0]=source_generic_coordinate[0]*tm_cd_spec->CScale_inv,
        src_coord[1]=source_generic_coordinate[1]*tm_cd_spec->CScale_inv,
        src_coord[2]=source_generic_coordinate[2],
        src_coord[3]=source_generic_coordinate[3]};

    SRM_Long_Float mu=(tm_cd_spec->smz + src_coord[1])* tm_cd_spec->conap_inv;
  /* mu is the parameterization variable of footpoint latitude which is
     an intermediate variable in the computation of latitude*/

    if (e_constants->Eps != 0.0) /* compute ellipsoidal values */
    {
       /*
        * This ellipsoidal tm_cd routine is a formulation
        * based on the work of Ralph Toms and C. Kellough
        * between 2001 and 2005.  It bears little resemblance
        * to the 3.x and earlier SEDRIS software.
        */
        SRM_Long_Float phi1=Impl_Footpoint(e_constants, /* footpoint latitude */
                                           &(tm_cd_spec->arclength_spec),
                                           &(tm_cd_spec->footpoint_spec),
                                           mu), sin_phi1, cos_phi1;

        srm_sincos(phi1, sin_phi1, cos_phi1);

        SRM_Long_Float
          sec_phi1=1.0/cos_phi1,
          sin_phi1_squared=SQUARE(sin_phi1),
          tan_phi1=sin_phi1*sec_phi1,
          tan_phi1_squared=SQUARE(tan_phi1),
          omessp=(1.0-SQUARE(e_constants->Eps*sin_phi1)),
          eta_sub1_squared=e_constants->Epps2*SQUARE(cos_phi1);

        SRM_Long_Float Rn1_inv=IMPL_NAN, /*1 over the radius of curvature in the prime vertical*/
                       phi=IMPL_NAN,     /*latitude*/
                       lambda=IMPL_NAN;  /*longitude*/

        /*
         * These values are computed later in ways which cannot be
         * used as initializations.  As a result they are initialized
         * here to NaN to prevent problems if something else fails
         */
        COMPUTE_RN_INV(sin_phi1_squared,Rn1_inv);

        /*
         * Mu is the variable in which footpoint_latitude is parameterized.
         * The following definition is correct but the above form using
         * precomputed constants that is actually used is more accurate:
         *
           mu=src_coord[1]/
              (e_constants->A*
              (1.0-SQUARE(e_constants->Eps)*(0.25+SQUARE(e_constants->Eps)*
              ((3.0/64.0)+(5.0/256.0)*SQUARE(e_constants->Eps)))));

           Rn1, the radius of curvature in the prime vertical is defined thus
                but 1 over it is actually computed to save a sqrt:
                Rn1=e_constants->A/sqrt(omessp);

           Rm1, the radius of curvature in the meridian is defined as follows
                but not needed:
                Rm1=e_constants->A/sqrt(CUBE(omessp));
         */

        /*
           phi = phi1 - (tan_phi1*omessp/omes)*SQUARE(zeta)*((1.0/2.0)
                      + SQUARE(zeta)*((-b4/24.0)+(b6/720.0)*SQUARE(zeta)));
           lambda = tm_cd_spec->longitude_origin +
                    zeta*sec_phi1*(1.0+SQUARE(zeta)*((-b3/6.0) +
                    b5/120.0*SQUARE(zeta)));

           These expressions were derived from a draft of the writeup.  Both
           are known good with the following definitions of the b's in this
           function. The actually implemented code removes a number of
           divide operations which are unnecessary and does further cleanup.
         */
#define ZERO_POINT_THREE_DEGREES .005235987755982988730771072305
#define ZERO_POINT_SEVEN_FIVE_DEGREES .013089969389957471826927680763
#define TWO_POINT_ZERO_DEGREES .034906585039886591538473815369
#define TWO_POINT_SEVEN_DEGREES .047123889803846898576939650749
#define SIX_POINT_ZERO_DEGREES  .104719755119659774615421446109

        /* 0.3 2.0 6.0 >6.0 are the latitude regions in degrees*/
        {
            SRM_Long_Float zeta         = src_coord[0]*Rn1_inv,
                           zeta_squared = SQUARE(zeta);

            SRM_Long_Float lon_range=fabs(zeta*sec_phi1);

            if (lon_range< ZERO_POINT_THREE_DEGREES)
            {
                phi=phi1-tan_phi1*omessp*zeta_squared*tm_cd_spec->con_lat2;
            }
            else
            {
                SRM_Long_Float b4 = 5.0 + TRIPLE(tan_phi1_squared) +
                                    eta_sub1_squared*
                                    (1.0-4.0*eta_sub1_squared -
                                     9.0 *tan_phi1_squared);

                if (lon_range<TWO_POINT_ZERO_DEGREES)
                {
                    phi=phi1-tan_phi1*omessp*(zeta_squared*(tm_cd_spec->con_lat2-
                        zeta_squared*tm_cd_spec->con_lat24*b4));
                }
                else
                {
                    SRM_Long_Float b6 = 61.0 + tan_phi1_squared*
                                               (90.0+45.0*tan_phi1_squared)+
                      eta_sub1_squared*(46.0+tan_phi1_squared*(-252.0 -90.0*tan_phi1_squared));

                    if (lon_range< SIX_POINT_ZERO_DEGREES)
                    {
                        phi=phi1-tan_phi1*omessp*
                          (zeta_squared*(tm_cd_spec->con_lat2
                                         +zeta_squared*(-tm_cd_spec->con_lat24*b4+
                                                        zeta_squared*tm_cd_spec->con_lat720*b6)));
                    }
                    else
                    {
                        SRM_Long_Float b8=1385.0+
                            tan_phi1_squared*(3633.0+tan_phi1_squared*(4095.0+1574.0*tan_phi1_squared));

                        phi=phi1-tan_phi1*omessp*
                            zeta_squared*(tm_cd_spec->con_lat2+zeta_squared*
                                          (-tm_cd_spec->con_lat24*b4+
                                           zeta_squared*(tm_cd_spec->con_lat720*b6-
                                                         zeta_squared*tm_cd_spec->con_lat40320*b8)));
                    }
                }
            }

           /*
            * Longitude ranges 0.75 2.7 >2.7  Note, latitude test is used
            * because the longitude formula here depends on the latitude
            * we're at
            */
            {
                SRM_Long_Float b3=1.0 + DOUBLE(tan_phi1_squared)+ eta_sub1_squared;
                /* zeta/cp */

                if (lon_range < ZERO_POINT_SEVEN_FIVE_DEGREES)
                {
                    lambda=tm_cd_spec->longitude_origin+zeta*(1.0-b3*con_lon6*zeta_squared)*sec_phi1;
                }
                else
                {
                    SRM_Long_Float b5=5.0 +tan_phi1_squared*(28.0+24.0*tan_phi1_squared)+eta_sub1_squared*(6.0+8.0*tan_phi1_squared);
                    if (lon_range < TWO_POINT_SEVEN_DEGREES)
                    {
                        lambda=tm_cd_spec->longitude_origin+
                               zeta*(1.0+zeta_squared*(-b3*con_lon6+b5*con_lon120*zeta_squared))*sec_phi1;
                    }
                    else
                    {
                        SRM_Long_Float b7=61.0+662.0*tan_phi1_squared+
                            1320.0*SQUARE(tan_phi1_squared)+720.0*CUBE(tan_phi1_squared);

                        lambda=tm_cd_spec->longitude_origin+
                               zeta*(1.0+zeta_squared*(-b3*con_lon6+
                                                    zeta_squared*(b5*con_lon120-zeta_squared*b7*con_lon5040)))*sec_phi1;
                    }
                }
            }
        }
        *dest_lat_ptr=phi;
        *dest_lon_ptr=lambda;
    }
    else /* compute spherical values here*/
    {
        SRM_Long_Float B   = 1.0/(tm_cd_spec->CScale*e_constants->A);
        SRM_Long_Float D   = source_generic_coordinate[1]*B + tm_cd_spec->latitude_origin;
        SRM_Long_Float xB  = source_generic_coordinate[0]*B;
        SRM_Long_Float xB2 = xB*xB;
        SRM_Long_Float sin_D, cos_D;
        srm_sincos(D, sin_D, cos_D);
        *dest_lat_ptr = asin(sin_D*(1.+((-0.5+(5./24.-(61./720.)*xB2)*xB2)*xB2)));
                   /* = asin(sin_D*sech(xB)); Power series approx for sech() */
        *dest_lon_ptr = tm_cd_spec->longitude_origin
                + atan2(xB*(1.+xB2*((1./6.)+xB2*(1./120.)+xB2*(1./5040.))), cos_D);
             /* + atan2(sinh(xB), cos_D); Power series approx for sinh() */
    }
    dest_generic_coordinate[2]=src_coord[2];
    dest_generic_coordinate[3]=1.0;
    return status;
} /* end SRM_ChangeTM_CD */
