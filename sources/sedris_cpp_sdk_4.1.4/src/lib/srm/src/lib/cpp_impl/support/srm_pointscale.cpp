/*!
  @file srm_pointscale.cpp
  @author Cameron D. Kellough (SRI)
*/
// SRM SDK Release 4.1.4 - July 1, 2011

// - SRM spec. 4.1

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


#include "srm_internal.h"
#include "srm_sincos.h"
#include "impl_private.h"

Impl_Status
Impl_pointscale_undefined
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  coord[3],
    SRM_Long_Float *point_scale
)
{
    return IMPL_ILLEGL;
}

Impl_Status
Impl_pointscaleMERCATOR
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *point_scale
)
{
    Impl_Status status=IMPL_VALID;
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_MERCATOR_SRFP *m_srf =
      (IMPL_MERCATOR_SRFP*)my_srf_org->private_data.impl_SRFP_struct;

    SRM_Long_Float slat = srm_sin(cd_coord[1]);
    SRM_Long_Float Rn = IMPL_NAN;

    COMPUTE_RN_FAST(slat*slat,Rn);

    *point_scale =
      m_srf->central_scale*e_constants->A/
      (Rn*srm_cos(cd_coord[1]));

    return status;
}


Impl_Status
Impl_pointscaleOBLIQUE_MERCATOR
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *point_scale
)
{
    Impl_Status status=IMPL_VALID;
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_OBLIQUE_MERCATOR_SRFP *om_srf =
      (IMPL_OBLIQUE_MERCATOR_SRFP*)my_srf_org->private_data.impl_SRFP_struct;

    SRM_CD_OM_Specific_Constants* om_distortion=
      (SRM_CD_OM_Specific_Constants*)  my_srf_org->point_distortion_data;

    SRM_Long_Float sin_lat, cos_lat, sin_lon, cos_lon;
    srm_sincos(cd_coord[1], sin_lat, cos_lat);
    srm_sincos(cd_coord[0], sin_lon, cos_lon);

    SRM_Long_Float A=IMPL_NAN;

    // compute initialization data if not done already
    if (my_srf_org->point_distortion_data == 0)
    {
        // allocate the memory for the COM initialization data.
        my_srf_org->point_distortion_data = calloc(1, sizeof(SRM_CD_OM_Specific_Constants));

        if (my_srf_org->point_distortion_data == 0)
            return IMPL_MEMALLOC;

        om_distortion = (SRM_CD_OM_Specific_Constants*)
                        my_srf_org->point_distortion_data;

        set_cd_to_om_constants
        (
            e_constants,
            om_srf,
            om_distortion
       );
    }

    A=(om_distortion->ca0*sin_lat)-
      (om_distortion->sa0*cos_lat*(sin_lon*om_distortion->cl0 - cos_lon*om_distortion->sl0));

    *point_scale =
      om_srf->central_scale / sqrt(1 -  SQUARE(A));

    return status;
}

Impl_Status
Impl_pointscaleTRANSVERSE_MERCATOR
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *point_scale
)
{
    Impl_Status status=IMPL_VALID;

    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_MERCATOR_SRFP* my_mercator_params=
      static_cast<IMPL_MERCATOR_SRFP*>(my_srf_org->private_data.impl_SRFP_struct);

    SRM_Long_Float cos_phi=srm_cos(cd_coord[1]);

    SRM_Long_Float CN2 = cos_phi * cos_phi;

    SRM_Long_Float lambda_star;

    GET_LAMBDA_STAR(cd_coord[0],  // lon
             my_mercator_params->origin_longitude,
             lambda_star);

    // if spherical
    if (e_constants->Eps2 == 0.0)
    {
        SRM_Long_Float s_lambda_star;

        s_lambda_star = srm_sin(lambda_star);

        *point_scale = my_mercator_params->central_scale /
                       sqrt(1.0 - CN2*s_lambda_star*s_lambda_star);
    }
    else
    { // ellipsoid case
        const SRM_Long_Float
              CON1 = 1.0 / 6.0,
              CON2 = 1.0 / 45.0,
              CON3 = 1.0 / 4.0,
              CON4 = 45.0 / 144.0;

        const SRM_Long_Float
              three_eighths=3.0/8.0,
              seven_fourths=7.0/4.0,
              seven_sixths=7.0/6.0,
              sixtyone_twentyfourths=61.0/24.0;

        const SRM_Long_Float
              CONL1 = .5 * e_constants->Epps2,
              CONL2 = three_eighths - seven_sixths *e_constants->Epps2,
              CONL3 = seven_fourths * e_constants->Epps2 - 2.0 *e_constants->Epps2*e_constants->Epps2,
              CONL4 = sixtyone_twentyfourths * e_constants->Epps2*e_constants->Epps2;

        SRM_Long_Float
              T2 = .5 + CONL1 * CN2,
              T4 = -CON1 + CN2*(CONL2 + CN2* (CONL3 + CONL4 * CN2)),
              T6 =  CON2 - CN2*(CON3 + CON4 * CN2),
              D2 = lambda_star * lambda_star;

        *point_scale= my_mercator_params->central_scale*
                      (1.0 + CN2 *D2 *(T2 + D2 *(T4 + D2 * T6)));
    }
    return status;
}


Impl_Status
Impl_pointscaleLAMBERT_CONF_CONIC
(
     void           *srf_org,
     Impl_ORM_Data  *e_constants,
     SRM_Long_Float  cd_coord[3],
     SRM_Long_Float *point_scale
)
{
    // cast pointer to srf info pointer
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_LAMBERT_CONF_CONIC_SRFP *lcc_srf =
      (IMPL_LAMBERT_CONF_CONIC_SRFP*)my_srf_org->private_data.impl_SRFP_struct;

    LCC_Point_Distortion_Data* lcc_distortion=(LCC_Point_Distortion_Data*) my_srf_org->point_distortion_data;

    SRM_Long_Float esphi, mphi, sphi, tphi;

    // compute initialization data if not done already
    if (my_srf_org->point_distortion_data == 0)
    {
        SRM_Long_Float
        slat1, slat2, e2slat12, e2slat22, eslat1, eslat2, mphi2, tphi2;

        // allocate the memory for the COM initialization data.
        my_srf_org->point_distortion_data = calloc(1, sizeof(LCC_Point_Distortion_Data));

        if (my_srf_org->point_distortion_data == 0)
            return IMPL_MEMALLOC;

        lcc_distortion =(LCC_Point_Distortion_Data*)
                        my_srf_org->point_distortion_data;

        slat1    = srm_sin(lcc_srf->latitude1);
        eslat1   = e_constants->Eps * slat1;
        e2slat12 = eslat1 * eslat1;
        slat2    = srm_sin(lcc_srf->latitude2);
        eslat2   = e_constants->Eps * slat2;
        e2slat22 = eslat2 * eslat2;

        lcc_distortion->mphi1 =
            srm_cos(lcc_srf->latitude1) / sqrt(1.0 - e2slat12);
        mphi2 =
            srm_cos(lcc_srf->latitude2) / sqrt(1.0 - e2slat22);

        lcc_distortion->tphi1=
            tan(SRM_PI_DIV_4 - lcc_srf->latitude1 * 0.5) *
            pow((1.0+eslat1)/(1.0-eslat1), e_constants->EpsH);
        tphi2=
            tan(SRM_PI_DIV_4 - lcc_srf->latitude2 * 0.5) *
            pow((1.0+eslat2)/(1.0-eslat2), e_constants->EpsH);

        if (ARE_EQUAL(lcc_srf->latitude1, lcc_srf->latitude2))
        {
            lcc_distortion->n = slat1;
        }
        else // if different
        {
            lcc_distortion->n =
              (log(lcc_distortion->mphi1) - log(mphi2)) /
              (log(lcc_distortion->tphi1) - log(tphi2));
        }
    }
    sphi = srm_sin(cd_coord[1]);
    esphi = e_constants->Eps * sphi;

    tphi =
      tan(SRM_PI_DIV_4 - cd_coord[1] * 0.5) *
      pow((1.0+esphi)/(1.0-esphi), e_constants->EpsH);

    mphi =
      srm_cos(cd_coord[1]) /
      sqrt(1.0 - esphi*esphi);

    *point_scale =
      (lcc_distortion->mphi1/mphi) *
      pow(tphi/lcc_distortion->tphi1, lcc_distortion->n);

    return IMPL_VALID;
}


Impl_Status
Impl_pointscalePOLAR_STEREOGRAPHIC
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *point_scale
)
{
    Impl_Status status=IMPL_VALID;

    // cast pointer to srf info pointer
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_POLAR_STEREOGRAPHIC_SRFP *ps_srf =
      (IMPL_POLAR_STEREOGRAPHIC_SRFP*)my_srf_org->private_data.impl_SRFP_struct;

    PS_Point_Distortion_Data* ps_distortion=(PS_Point_Distortion_Data*) my_srf_org->point_distortion_data;

    SRM_Long_Float abs_phi, cphi, eps_sabs_phi, Rn, sphi, tphi;

    // compute initialization data if not done already
    if (my_srf_org->point_distortion_data == 0)
    {
        SRM_Long_Float E;

        // allocate the memory for the COM initialization data.
        my_srf_org->point_distortion_data = calloc(1, sizeof(PS_Point_Distortion_Data));

        if (my_srf_org->point_distortion_data == 0)
            return IMPL_MEMALLOC;

        ps_distortion=(PS_Point_Distortion_Data*) my_srf_org->point_distortion_data;

        E = (e_constants->A / e_constants-> B) *
            pow((1-e_constants->Eps)/(1+e_constants->Eps), e_constants->EpsH);

        ps_distortion->TwoAk0E = 2. * e_constants->A * ps_srf->central_scale * E;
    }
    abs_phi = fabs(cd_coord[1]);

    srm_sincos(cd_coord[1], sphi, cphi);

    eps_sabs_phi = e_constants->Eps * srm_sin(abs_phi);

    tphi =
      tan(SRM_PI_DIV_4 - (abs_phi * 0.5)) *
      pow((1.0+eps_sabs_phi)/(1.0-eps_sabs_phi),
       e_constants->EpsH);

    COMPUTE_RN_EXACT(sphi*sphi, Rn);

    *point_scale = (ps_distortion->TwoAk0E * tphi) / (Rn * cphi);

    return status;
}


Impl_Status
Impl_pointscaleEQUIDISTANT_CYL
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *point_scale
)
{
    Impl_Status status=IMPL_VALID;

    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_EQUIDISTANT_CYL_SRFP* my_ec_params=
      static_cast<IMPL_EQUIDISTANT_CYL_SRFP*>
      (my_srf_org->private_data.impl_SRFP_struct);

    if (ARE_EQUAL(cd_coord[1], 0.0))
    {
        *point_scale = my_ec_params->central_scale;
    }
    else
    {
        SRM_Long_Float cos_lat, Rn, sin_lat, sin_lat_squared;
        sin_lat         = srm_sin(cd_coord[1]);
        sin_lat_squared = sin_lat*sin_lat;

        COMPUTE_RN(sin_lat_squared,Rn);

        cos_lat=srm_cos(cd_coord[1]);

        *point_scale=
          (my_ec_params->central_scale*e_constants->A)/
          (Rn*cos_lat);
    }
    return status;
}
