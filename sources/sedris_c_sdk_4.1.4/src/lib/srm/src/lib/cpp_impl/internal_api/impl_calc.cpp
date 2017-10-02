/*!
  @file   impl_calc.cpp
  @author Cameron D. Kellough, SRI
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


#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "orm_rd_struct.h"
#include "srm_internal.h"
#include "srm_sincos.h"
#include "impl_vos.h"

static int compute_geodesic_distance
(
    double  phi_1,    // latitude
    double  lambda_1, // longitude
    double  phi_2,    // latitude
    double  lambda_2, // longitude
    double  a,
    double  f,
    double *geodesic_distance
)
{
    double e2 = (2.0-f)*f;

    //Reduced latitudes
    double u1 = atan((1.0-f)*tan(phi_1));
    double u2 = atan((1.0-f)*tan(phi_2));

    double deltaomega_old = 0.0;
    double deltaomega_new = 1.0;
    double omega, sigma, cosun, sinun2, sigmam, v, t, K1, K2, K3, deltasigma,
    cos_u1, cos_u2, sin_u1, sin_u2, cos_omega, sin_omega, sin_sigma, cos_sigma,
    cos_sigmam, cos_2sigmam;

   /*
    * Kai Borre algorithm - a.k.a., the never-meant-to-be-put-in-the-API
    * Kai Borre algorithm
    *
    * In response to a question about whether it is possible for the
    * loop to never terminate, Paul recommended adding the loop limit,
    * with the understanding that this is for safety and that he has
    * not had time to do the analysis.
    * - Paul Berner, 22 September 2010
    */
    #define KAI_BORRE_LOOPLIMIT 100
    int count =0;

    while ((count < KAI_BORRE_LOOPLIMIT) &&
           (fabs(deltaomega_old-deltaomega_new) > 1.e-12))
    {
        count ++;
        deltaomega_old = deltaomega_new;
        omega = lambda_2-lambda_1+deltaomega_old;

        srm_sincos(u1, sin_u1, cos_u1);
        srm_sincos(u2, sin_u2, cos_u2);
        srm_sincos(omega, sin_omega, cos_omega);
        sigma = atan2(hypot(cos_u2*sin_omega, cos_u1*sin_u2-sin_u1*cos_u2*cos_omega),
                      sin_u1*sin_u2+cos_u1*cos_u2*cos_omega);

        srm_sincos(sigma, sin_sigma, cos_sigma);
        cosun = cos_u1*cos_u2*sin_omega/sin_sigma;
        sinun2 = 1.0-cosun*cosun;
        if (sinun2 == 0.0)
            sigmam = acos(cos_sigma-2.0);
        else
            sigmam = acos(cos_sigma-2.0*sin_u1*sin_u2/sinun2+1.e-12);
            //                                                 ^temporary fix to avoid -1.#IND
        cos_sigmam = srm_cos(sigmam);
        cos_2sigmam = srm_cos(2.0*sigmam);

        v = 0.25*f*sinun2;
        K3 = v*(1.0+f+f*f-v*(3.0+7.0*f-13.0*v));
        deltaomega_new = (1.0-K3)*f*cosun*(sigma+K3*sin_sigma*(cos_sigmam+K3*cos_sigma*cos_2sigmam));
    } /* end while */
    t  = (e2/(1.-e2))*sinun2*0.25;
    K1 = 1.0+t*(1.0-t*(3.0-t*(5.-10.9375*t))*0.25);
    K2 = t*(1.0-t*(2.0-t*(37.0-94.0*t)*0.125));
    deltasigma = K2*sin_sigma*(cos_sigmam+
                               K2*(cos_sigma*cos_2sigmam+
                                   K2*(1.0+2.0*srm_cos(2.0*sigma))*srm_cos(3.0*sigmam)/6.0)*0.25);
    *geodesic_distance = K1*(1.0-f)*a*(sigma-deltasigma);

    return count;
}


Impl_Status
Impl_calculateConvergenceOfTheMeridian
(
          void           *srf_org,
    const SRM_Long_Float  coord_org[2],
          SRM_Long_Float *com_value
)
{
    Impl_Status status;
    Impl_ORM_Data* e_constants;
    SRM_Long_Float coord[3]={coord_org[0],coord_org[1],0.0};
    SRM_Long_Float coord_cd[3];
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;
    Impl_SRF_ptr my_srf_cd;

    CHECK_SRFSRC(my_srf_org);

    e_constants=my_srf_org->private_data.e_constants;

    // special case where the COM is always 0 (zero)
    if (my_srf_org->template_code == SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL ||
        my_srf_org->template_code == SRM_SRFTCOD_MERCATOR)
    {
        status = IMPL_VALID;
        *com_value = 0.0;
    }
    else  // convert to GD and calculate COM
    {
        status = Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIODETIC,my_srf_org->orm_code,my_srf_org->rt_code,0,(void**)&my_srf_cd);

        if (status!=IMPL_VALID)
            return status;

        status=Impl_changeCoord3DSRF(srf_org,
                   coord,
                   (void*)my_srf_cd,
                   coord_cd);

        if ((status) & (~IMPL_BADSTAT))
        {
            status =Impl_com_templ[my_srf_org->template_code]
                    (
                        srf_org,
                        e_constants,
                        coord_cd,
                        com_value
                    );
        }
        status|=Impl_releaseSRF((void**)&my_srf_cd);
    }
    return status;
}


Impl_Status
Impl_calculateEuclideanDistance
(
          void           *srf_org,
    const SRM_Long_Float  coord_org[3],
          void           *srf_dst,
    const SRM_Long_Float  coord_dst[3],
          SRM_Long_Float *euclidean_distance
)
{
  /*!\note  This routine does not make efficient use of operations caches.*/

    Impl_Status status=IMPL_VALID;

    SRM_ORM_Code orm_ref_tgt;

    SRM_Long_Float coord_org_tgt[3];
    SRM_Long_Float coord_dst_tgt[3];

    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr)srf_dst;

    Impl_SRF_ptr srf_for_distance_comp=NULL;

    /*Check for garbage data*/
    CHECK_SRFSRC(my_srf_org);
    CHECK_SRFTGT(my_srf_tgt);

    switch(my_srf_org->template_code)
    {
        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
            status|=IMPL_UNIMPLEM;
            break;
        default:
            status|=IMPL_VALID;
    }

    switch(my_srf_tgt->template_code)
    {
        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
            status|=IMPL_UNIMPLEM;
            break;
        default:
            status|=IMPL_VALID;
    }

    /*Test to see if the source and target SRF's are both for the same body*/
    if (Impl_ORM_array[my_srf_org->orm_code].reference_orm!=Impl_ORM_array[my_srf_tgt->orm_code].reference_orm)
    {
        status|=IMPL_ILLEGL;
    }

    if (status& ~IMPL_GOODSTAT)
        return status;

    orm_ref_tgt=my_srf_tgt->orm_code;

    status|=Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIOCENTRIC,orm_ref_tgt,my_srf_tgt->rt_code ,0,(void**)&srf_for_distance_comp);

    if (status& ~IMPL_GOODSTAT)
        return status;

    status|=Impl_changeCoord3DSRF(my_srf_org,
                  coord_org,
                  srf_for_distance_comp,
                  coord_org_tgt);

    if ((status)& (~(IMPL_GOODSTAT)))
    {
        Impl_releaseSRF((void**)&srf_for_distance_comp);
        *euclidean_distance=IMPL_NAN;
        return status;
    }
    status|=Impl_changeCoord3DSRF(my_srf_tgt,
                  coord_dst,
                  srf_for_distance_comp,
                  coord_dst_tgt);

    if ((status)& (~(IMPL_GOODSTAT)))
    {
        status|=Impl_releaseSRF((void**)&srf_for_distance_comp);
        *euclidean_distance=IMPL_NAN;
        return status;
    }
    {
        SRM_Long_Float delta_x,delta_y,delta_z;
        delta_x=coord_org_tgt[0]-coord_dst_tgt[0];
        delta_y=coord_org_tgt[1]-coord_dst_tgt[1];
        delta_z=coord_org_tgt[2]-coord_dst_tgt[2];

        *euclidean_distance= sqrt(SQUARE(delta_x)+
                     SQUARE(delta_y)+
                     SQUARE(delta_z));
    }
    status|=Impl_releaseSRF((void**)&srf_for_distance_comp);

    return status;
}

Impl_Status
Impl_calculateEuclideanDistanceSurface
(
          void           *srf_org,
    const SRM_Long_Float  coord_org[2],
          void           *srf_dst,
    const SRM_Long_Float  coord_dst[2],
          SRM_Long_Float *euclidean_distance
)
{
    SRM_Long_Float coord_org3[3]={coord_org[0],coord_org[1],0.0};
    SRM_Long_Float coord_dst3[3]={coord_dst[0],coord_dst[1],0.0};

    return Impl_calculateEuclideanDistance(srf_org,
                       coord_org3,
                       srf_dst,
                       coord_dst3,
                       euclidean_distance);
}

Impl_Status
Impl_calculateEuclideanDistance2D
(
          void           *srf_org,
    const SRM_Long_Float  coord_org[2],
          void           *srf_dst,
    const SRM_Long_Float  coord_dst[2],
          SRM_Long_Float *euclidean_distance
)
{
    SRM_Long_Float coord_org3[3]={coord_org[0],coord_org[1],0.0};
    SRM_Long_Float coord_dst3[3]={coord_dst[0],coord_dst[1],0.0};

    return Impl_calculateEuclideanDistance(srf_org,
                       coord_org3,
                       srf_dst,
                       coord_dst3,
                       euclidean_distance);
}

Impl_Status
Impl_calculateGeodesicDistance
(
          void           *srf_org,
    const SRM_Long_Float  coord_org[2],
          void           *srf_dst,
    const SRM_Long_Float  coord_dst[2],
          SRM_Long_Float *geodesic_distance
)
{
   /*!\note  This routine does not make efficient use of operations caches.*/

    Impl_Status status=IMPL_VALID;

    Impl_ORM_Data *orm_data;

    SRM_ORM_Code orm_ref_tgt;

    SRM_Long_Float coord_org_tgt[3];
    SRM_Long_Float coord_dst_tgt[3];

    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;
    Impl_SRF_ptr my_srf_tgt=(Impl_SRF_ptr)srf_dst;

    Impl_SRF_ptr srf_for_distance_comp=NULL;

    /*Check for garbage data*/
    CHECK_SRFSRC(my_srf_org);
    CHECK_SRFTGT(my_srf_tgt);

    /*Test to see if the source and target orm/rt are the same otherwise we cannot execute*/
    if (my_srf_org->orm_code!=my_srf_tgt->orm_code || my_srf_org->rt_code!=my_srf_tgt->rt_code)
    {
        status|=IMPL_ILLEGL;
    }

    if (status& ~IMPL_GOODSTAT)
        return status;

    orm_ref_tgt=my_srf_tgt->orm_code;

    status|=Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIODETIC,orm_ref_tgt,my_srf_tgt->rt_code ,0,(void**)&srf_for_distance_comp);

    if (status& ~IMPL_GOODSTAT)
        return status;

    status|=Impl_changeCoord3DSRF(my_srf_org,
                  coord_org,
                  srf_for_distance_comp,
                  coord_org_tgt);

    if ((status)& (~(IMPL_GOODSTAT)))
    {
        Impl_releaseSRF((void**)&srf_for_distance_comp);
        *geodesic_distance=IMPL_NAN;
        return status;
    }
    status|=Impl_changeCoord3DSRF(my_srf_tgt,
                  coord_dst,
                  srf_for_distance_comp,
                  coord_dst_tgt);

    if ((status)& (~(IMPL_GOODSTAT)))
    {
        status|=Impl_releaseSRF((void**)&srf_for_distance_comp);
        *geodesic_distance=IMPL_NAN;
        return status;
    }
    orm_data = Impl_getEconstantsForORMCode(my_srf_org->orm_code);

    //                         latitude          longitude
    compute_geodesic_distance(coord_org_tgt[1], coord_org_tgt[0],
                   coord_dst_tgt[1], coord_dst_tgt[0],
                   orm_data->A, orm_data->F,
                   geodesic_distance);

    status|=Impl_releaseSRF((void**)&srf_for_distance_comp);

    return status;
}

Impl_Status
Impl_calculateMapAzimuth
(
          void           *srf,
    const SRM_Long_Float  coord_org[2],
    const SRM_Long_Float  coord_dst[2],
          SRM_Long_Float *map_azimuth
)
{
    Impl_Status status = IMPL_VALID;

    if (coord_dst[0] == coord_org[0] &&
        coord_dst[1] == coord_org[1])
    {
        status = IMPL_ILLEGL;
    }
    else
    {
        *map_azimuth = atan2(coord_dst[0]-coord_org[0],
                             coord_dst[1]-coord_org[1]);

        if (*map_azimuth < 0.0)
            *map_azimuth += SRM_2_PI;
    }
    return status;
}


Impl_Status
Impl_calculatePointScale
(
          void           *srf_org,
    const SRM_Long_Float  coord_org[2],
          SRM_Long_Float *point_scale
)
{
    Impl_Status status;
    Impl_ORM_Data* e_constants;
    SRM_Long_Float coord[3]={coord_org[0],coord_org[1],0.0};
    SRM_Long_Float coord_cd[3];
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;
    Impl_SRF_ptr my_srf_cd;

    CHECK_SRFSRC(my_srf_org);

    e_constants=my_srf_org->private_data.e_constants;


    status=Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIODETIC,my_srf_org->orm_code,my_srf_org->rt_code,0,(void**)&my_srf_cd);

    if (status!=IMPL_VALID)
        return status;

    status=Impl_changeCoord3DSRF(srf_org,
                     coord,
                     (void*)my_srf_cd,
                     coord_cd);

    if ((status) & (~IMPL_BADSTAT))
    {
        status=Impl_pointscale_templ[my_srf_org->template_code]
               (
                   srf_org,
                   e_constants,
                   coord_cd,
                   point_scale
               );
    }
    status|=Impl_releaseSRF((void**)&my_srf_cd);

    return status;
}

Impl_Status
Impl_calculateVerticalSeparationOffset
(
          void           *srf_org,
    const SRM_Long_Float  coord_org[2],
          SRM_DSS_Code    dss_code,
          SRM_Long_Float *vertical_offset
)
{
    Impl_Status status;
    Impl_SRF_ptr my_srf_org=(Impl_SRF_ptr)srf_org;
    CHECK_SRFSRC(my_srf_org);

    SRM_Long_Float my_coord_org[3]={coord_org[0],coord_org[1],0.0};

    status=Impl_calcDSS[dss_code](my_srf_org, my_coord_org, vertical_offset);

    SIMPLIFY_STATUS(status);
    return status;
}
