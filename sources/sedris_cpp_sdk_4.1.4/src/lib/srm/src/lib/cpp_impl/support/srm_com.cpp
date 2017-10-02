/*!
  @file srm_com.cpp
  @author David Shen (SAIC)
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
Impl_com_undefined
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  coord[3],
    SRM_Long_Float *com_value
)
{
    return IMPL_ILLEGL;
}

// this should never be called because it returns zero from impl_calc
Impl_Status
Impl_comMERCATOR
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *com_value
)
{
    *com_value = 0.0;

    return IMPL_VALID;
}

Impl_Status
Impl_comOBLIQUE_MERCATOR
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *com_value
)
{
    SRM_Long_Float sin_lon, cos_lon, sin_lat, cos_lat;
    srm_sincos(cd_coord[0], sin_lon, cos_lon);
    srm_sincos(cd_coord[1], sin_lat, cos_lat);

    // cast pointer to srf info pointer
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    OM_COM_Data* om_com= (OM_COM_Data*) my_srf_org->com_data;

    // compute initialization data if not done already
    if (my_srf_org->com_data == 0)
    {
        SRM_Long_Float
          sin_lat1=IMPL_NAN,
          cos_lat1=IMPL_NAN,
          sin_lat2=IMPL_NAN,
          cos_lat2=IMPL_NAN,
          sin_lon1=IMPL_NAN,
          cos_lon1=IMPL_NAN,
          sin_lon2=IMPL_NAN,
          cos_lon2=IMPL_NAN,
          lambda_0=IMPL_NAN,
          sin_lambda_1_minus_lambda_0=IMPL_NAN,
          sin_lambda_2_minus_lambda_0=IMPL_NAN,
          p0=IMPL_NAN,
          q0=IMPL_NAN,
          alpha_0=IMPL_NAN;

        IMPL_OBLIQUE_MERCATOR_SRFP *om_srf =
          (IMPL_OBLIQUE_MERCATOR_SRFP*)my_srf_org->private_data.impl_SRFP_struct;

        // allocate the memory for the COM initialization data.
        my_srf_org->com_data = calloc(1, sizeof(OM_COM_Data));

        om_com= (OM_COM_Data*) my_srf_org->com_data;

        if (my_srf_org->com_data == 0)
            return IMPL_MEMALLOC;

        srm_sincos(om_srf->latitude1, sin_lat1, cos_lat1);
        srm_sincos(om_srf->latitude2, sin_lat2, cos_lat2);
        srm_sincos(om_srf->longitude1, sin_lon1, cos_lon1);
        srm_sincos(om_srf->longitude2, sin_lon2, cos_lon2);

        p0=cos_lat1*sin_lat2*sin_lon1-sin_lat1*cos_lat2*sin_lon2;
        q0=cos_lat1*sin_lat2*cos_lon1-sin_lat1*cos_lat2*cos_lon2;

        lambda_0=atan2(p0,q0);

        srm_sincos(lambda_0, om_com->sl0, om_com->cl0);

        sin_lambda_1_minus_lambda_0=sin_lon1*om_com->cl0-cos_lon1*om_com->sl0;
        sin_lambda_2_minus_lambda_0=sin_lon2*om_com->cl0-cos_lon2*om_com->sl0;

        if(fabs(sin_lambda_1_minus_lambda_0)>=fabs(sin_lambda_2_minus_lambda_0))
        {
            alpha_0=atan(sin_lat1/(cos_lat1*sin_lambda_1_minus_lambda_0));
        }
        else
        {
            alpha_0=atan(sin_lat2/(cos_lat2*sin_lambda_2_minus_lambda_0));
        }
        srm_sincos(alpha_0, om_com->sa0, om_com->ca0);
    }

    {
        SRM_Long_Float sin_lambda_minus_lambda_0=(sin_lon*om_com->cl0-cos_lon*om_com->sl0);
        SRM_Long_Float cos_lambda_minus_lambda_0=(cos_lon*om_com->cl0+sin_lon*om_com->sl0);

        *com_value = atan2(-om_com->sa0*cos_lambda_minus_lambda_0,
                           om_com->ca0*cos_lat +
                           om_com->sa0*sin_lat*sin_lambda_minus_lambda_0
                           );
    }
    return IMPL_VALID;
}

Impl_Status
Impl_comTRANSVERSE_MERCATOR
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *com_value
)
{
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_TRANSVERSE_MERCATOR_SRFP *tm_srf =
      (IMPL_TRANSVERSE_MERCATOR_SRFP*)my_srf_org->private_data.impl_SRFP_struct;

    /*These are taylor series constants from the formulation for COM in
      TEC SR-7.  They are declared here as const so that they aren't
      recopied over by the runtime when the routine starts each time.
    */
    const SRM_Long_Float
      CON1=(1.0 / 3.0),
      CON2=(1.0 / 15.0),
      CON3=(1.0 / 5.0),
      CON4=(2.0 / 315.0),
      CON5=(30.0 / 315.0),
      CON6=(45.0 / 315.0);

    if (my_srf_org->com_data == 0)
    {
        // allocate the memory for the COM initialization data.
        my_srf_org->com_data = calloc(1, sizeof(TM_COM_Data));

        if (my_srf_org->com_data == 0)
            return IMPL_MEMALLOC;
    }

    // if spherical
    if (e_constants->Eps2 == 0.0)
    {
        *com_value = tan(cd_coord[0]) * srm_sin(cd_coord[1]);
    }
    // else it is ellipsoid
    else
    {
        SRM_Long_Float lambda_star;

        GET_LAMBDA_STAR(cd_coord[0],  // lon
                        tm_srf->origin_longitude,
                        lambda_star);

        SRM_Long_Float cos_phi=srm_cos(cd_coord[1]);

        const SRM_Long_Float
          two_thirds=2.0/3.0,
          seventeen_thirds=17.0/3.0,
          ten_thirds=10.0/3.0;

        const SRM_Long_Float
          CONL1 = two_thirds* e_constants->Epps2 * e_constants->Epps2,
          CONL2 = seventeen_thirds * e_constants->Epps2 * e_constants->Epps2,
          CONL3 = 2.0 * e_constants->Epps2,
          CONL4 = ten_thirds* e_constants->Epps2 * e_constants->Epps2,
          CONL5 = CON3 - e_constants->Epps2,
          CONL6 = CONL3 - CONL4;

        SRM_Long_Float CN2 = cos_phi * cos_phi;
        /*This symbol is properly called CN2 because it denotes the
          CN function from jacobi eliptic integrals SQUARED which only happens
          to reduce to cosine here.
        */

        SRM_Long_Float
          D2 = lambda_star * lambda_star;

        SRM_Long_Float
          T2 =  CON1 +  CN2 * (e_constants->Epps2 + CONL1 * CN2),
          T4 = -CON2  + CN2 * (CONL5 + CN2 * (CONL6 + CONL2* CN2)),
          T6 =  CON4  + CN2 * (-CON5 + CON6*CN2);


        *com_value =
          lambda_star * srm_sin(cd_coord[1])*
          (1.0 +
           CN2 * D2 * (T2 +
                       D2 * (T4 +
                             D2 * T6)));
    }
    return IMPL_VALID;
}


Impl_Status
Impl_comLAMBERT_CONF_CONIC
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *com_value
)
{
    SRM_Long_Float lambda_star;

    // cast pointer to srf info pointer
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_LAMBERT_CONF_CONIC_SRFP *lcc_srf =
      (IMPL_LAMBERT_CONF_CONIC_SRFP*)my_srf_org->private_data.impl_SRFP_struct;

    LCC_COM_Data* lcc_com=(LCC_COM_Data*) my_srf_org->com_data;

    // compute initialization data if not done already
    if (my_srf_org->com_data == 0)
    {
        SRM_Long_Float
          sin_lat1, sin_lat2,
          epsilon_squared_sin_squared_lat1, epsilon_squared_sin_squared_lat2,
          epsilon_times_sin_lat1, epsilon_times_sin_lat2,
          m_phi1, m_phi2, tan_phi1, tan_phi2;

        // allocate the memory for the COM initialization data.
        my_srf_org->com_data = calloc(1, sizeof(LCC_COM_Data));

        if (my_srf_org->com_data == 0)
            return IMPL_MEMALLOC;

        lcc_com=(LCC_COM_Data*) my_srf_org->com_data;

        SRM_Long_Float cos_lat1, cos_lat2;

        srm_sincos(lcc_srf->latitude1, sin_lat1, cos_lat1);
        srm_sincos(lcc_srf->latitude2, sin_lat2, cos_lat2);
        epsilon_times_sin_lat1 = e_constants->Eps * sin_lat1;
        epsilon_squared_sin_squared_lat1 = epsilon_times_sin_lat1 * epsilon_times_sin_lat1;
        epsilon_times_sin_lat2 = e_constants->Eps * sin_lat2;
        epsilon_squared_sin_squared_lat2 = epsilon_times_sin_lat2 * epsilon_times_sin_lat2;

        m_phi1 = cos_lat1 / sqrt(1.0 - epsilon_squared_sin_squared_lat1);
        m_phi2 = cos_lat2 / sqrt(1.0 - epsilon_squared_sin_squared_lat2);

        tan_phi1= tan(SRM_PI_DIV_4 - lcc_srf->latitude1 * 0.5) *
          pow((1.0+epsilon_times_sin_lat1)/(1.0-epsilon_times_sin_lat1), e_constants->EpsH);

        tan_phi2= tan(SRM_PI_DIV_4 - lcc_srf->latitude2 * 0.5) *
          pow((1.0+epsilon_times_sin_lat2)/(1.0-epsilon_times_sin_lat2), e_constants->EpsH);

        if (ARE_EQUAL(lcc_srf->latitude1, lcc_srf->latitude2))
        {
            lcc_com->n = sin_lat1;
        }
        else // if different
        {
            lcc_com->n =
              (log(m_phi1) - log(m_phi2)) /
              (log(tan_phi1) - log(tan_phi2));
        }
    }
    GET_LAMBDA_STAR(cd_coord[0],  // lon
                    lcc_srf->origin_longitude,
                    lambda_star);

    *com_value = lcc_com->n * lambda_star;

    return IMPL_VALID;
}

Impl_Status
Impl_comPOLAR_STEREOGRAPHIC
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *com_value
)
{
    SRM_Long_Float lambda_star;

    // cast pointer to srf info pointer
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;

    IMPL_POLAR_STEREOGRAPHIC_SRFP *ps_srf =
      (IMPL_POLAR_STEREOGRAPHIC_SRFP*)my_srf_org->private_data.impl_SRFP_struct;

    GET_LAMBDA_STAR(cd_coord[0], //lon
                    ps_srf->origin_longitude,
                    lambda_star);

    if (ps_srf->polar_aspect == SRM_PLRASP_NORTH)
        *com_value = lambda_star;
    else // southern aspect
        *com_value = -lambda_star;

    return IMPL_VALID;
}


// this should never be called because it returns zero from impl_calc
Impl_Status
Impl_comEQUIDISTANT_CYL
(
    void           *srf_org,
    Impl_ORM_Data  *e_constants,
    SRM_Long_Float  cd_coord[3],
    SRM_Long_Float *com_value
)
{
    *com_value = 0.0;

    return IMPL_VALID;
}
