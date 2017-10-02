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


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "srm_types.h"
#include "srm_internal.h"
#include "srm_sincos.h"
#include "impl_srf_params.h"

/*The convergence of the meridian routines were originally part of the
 *conversions themselves but the code was templated from the original into
 *separate functions to avoid the tests and the complexity in the control
 *logic.  During the work it was observed that there appeared to be sign errors
 *in the COM calculations.  This note is informative only.  The changes to the COM
 *routines happened in release version 3.1.2
 */

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: Impl_set_cd_to_ps_constants
 *
 *   Computes and stores the constants used for converting from CD to PS.
 *
 * PARAMETERS:
 *
 *   e_constants - pointer to the converted ellipse constants
 *
 *   ps - a pointer to the parameters of a (destination) PS system
 *
 *   cd_ps_spec - a pointer to where the constants will be stored
 *                 for a CD to PS conversion
 *
 * RETURNS: nothing
 *   Instead of returning a value, this function sets constants in the
 *   the structure pointed to by the cd_ps_spec parameter.
 *
 *----------------------------------------------------------------------------
 */
void
Impl_set_cd_to_ps_constants
(
    const Impl_ORM_Data                 *e_constants,
    const IMPL_POLAR_STEREOGRAPHIC_SRFP *ps_srf,
          SRM_CD_PS_Specific_Constants  *cd_ps_spec
)
{
    SRM_Long_Float origin_longitude;
    SRM_Long_Float polar_aspect_sign=1.0;

    cd_ps_spec->polar_aspect   = ps_srf->polar_aspect;
    cd_ps_spec->false_easting  = ps_srf->false_easting;
    cd_ps_spec->false_northing = ps_srf->false_northing;
    cd_ps_spec->k0=ps_srf->central_scale;
    cd_ps_spec->e_constants=*e_constants;
    cd_ps_spec->scale_factor=ps_srf->central_scale;

    if(cd_ps_spec->polar_aspect==SRM_PLRASP_SOUTH)
    {
        polar_aspect_sign=-1.0;
        cd_ps_spec->polar_aspect_constant=-1.0;
    }
    else
    {
        polar_aspect_sign=1.0;
        cd_ps_spec->polar_aspect_constant=1.0;
    }
    origin_longitude=polar_aspect_sign*ps_srf->origin_longitude;

    cd_ps_spec->eps_factor= IMPL_NAN;
    cd_ps_spec->origin_lon=origin_longitude;

    POWER_P(1.0, cd_ps_spec->P0);

    cd_ps_spec->e=e_constants->A*cd_ps_spec->P0*e_constants->B_inv;
    cd_ps_spec->e_inv=1.0/cd_ps_spec->e;

    if(e_constants->Eps!=0.0)
    {
        (void)Impl_Init_power_p_series(e_constants,
                                       cd_ps_spec->cr1,
                                       cd_ps_spec->cr2);
    }
    else
    {
        for(int i=0;i<5;i++)
        {
            cd_ps_spec->cr1[i]=IMPL_NAN;
            cd_ps_spec->cr2[i]=IMPL_NAN;
        }
    }
    srm_sincos(cd_ps_spec->origin_lon, cd_ps_spec->sin_origin_lon,
               cd_ps_spec->cos_origin_lon);
} /* end Impl_set_cd_to_ps_constants */


void
Impl_set_ps_to_cd_constants
(
    const Impl_ORM_Data                 *e_constants,
    const IMPL_POLAR_STEREOGRAPHIC_SRFP *ps_srf,
          SRM_PS_CD_Specific_Constants  *ps_cd_spec
)
{
    ps_cd_spec->e_constants=*e_constants;

    (void)Impl_Init_chi_series(e_constants, ps_cd_spec->b);
    if(e_constants->Eps!=0.0)
        (void)Impl_Init_power_p_series(e_constants,ps_cd_spec->cr1,ps_cd_spec->cr2);
    else
    {
        for(int i=0;i<5;i++)
        {
            ps_cd_spec->cr1[i]=IMPL_NAN;
            ps_cd_spec->cr2[i]=IMPL_NAN;
        }
    }
    POWER_P(1.0,ps_cd_spec->P0);

    ps_cd_spec->longitude_origin=ps_srf->origin_longitude;

    ps_cd_spec->scale_inverse=1.0/ps_srf->central_scale;

    ps_cd_spec->polar_aspect_constant=
      (ps_srf->polar_aspect==SRM_PLRASP_NORTH)?1.0:-1.0;

    ps_cd_spec->FK_inv=1.0/(2.0*ps_cd_spec->P0*
                            e_constants->A2*e_constants->B_inv);
} /* end Impl_set_ps_to_cd_constants */


Impl_Status
Impl_ChangeCD_PS
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status  status = IMPL_VALID;

    SRM_CD_PS_Specific_Constants
      *cd_ps_spec = (SRM_CD_PS_Specific_Constants *)(constants);

    Impl_ORM_Data
      *e_constants=&cd_ps_spec->e_constants;

    SRM_Long_Float
      source_lon=source_generic_coordinate[0]*cd_ps_spec->polar_aspect_constant,
      source_lat=source_generic_coordinate[1]*cd_ps_spec->polar_aspect_constant,
      sin_lat, cos_lat,
      sin_lon, cos_lon,
      rho=IMPL_NAN,
      P=IMPL_NAN,
      T=IMPL_NAN,
      scale_factor=cd_ps_spec->scale_factor;

    srm_sincos( source_lat, sin_lat, cos_lat );
    srm_sincos( source_lon, sin_lon, cos_lon );

    SRM_Long_Float cos_lat_inv=1.0/cos_lat;

  /*This is the equation for P.  This POWER_P macro below computes this
    with a Taylor series to avoid the costly operations.
    P=pow(((1.0-e_constants->Eps)/(1.0+e_constants->Eps)),(0.5*e_constants->Eps));
    POWER_P(sin_lat,P);
    Note that the series used for p CANNOT be inverted
    by doing algebra on the forward series used as there aren't
    enough terms for it to converge correctly in that case
  */

    if(e_constants->Eps!=0.0)
    {
        /*This is the Ellipsoidal case*/

        P=POWER_P_APPROX(cd_ps_spec->cr1,cd_ps_spec->cr2, sin_lat);

        T=(1.0-sin_lat)*cos_lat_inv/P;

        rho=2.0*e_constants->A*scale_factor*T*cd_ps_spec->e;

        {
          /*Note that the bounds don't need to be checked because you can use
            the trig angle difference formulas and thus the angles themselves
            are already converted into their trig functions and thus ranges
            won't matter as everything in this expression is always bounded.
          */
            SRM_Long_Float
              cos_arg=cos_lon*cd_ps_spec->cos_origin_lon+sin_lon*cd_ps_spec->sin_origin_lon,
              sin_arg=sin_lon*cd_ps_spec->cos_origin_lon-cos_lon*cd_ps_spec->sin_origin_lon;

            //ASSIGN RETURN VALUE AND ADJUST OUTPUT FOR POLAR ASPECT

            dest_generic_coordinate[0]= (rho*sin_arg)*cd_ps_spec->polar_aspect_constant;
            dest_generic_coordinate[1]= (-rho*cos_arg)*cd_ps_spec->polar_aspect_constant;
        }
    }
    else
    {
        T=(1.0-sin_lat)*cos_lat_inv;

        dest_generic_coordinate[0]=2.0*e_constants->A*scale_factor*
          T*((sin_lon*cd_ps_spec->cos_origin_lon)-
             (cos_lon*cd_ps_spec->sin_origin_lon))*cd_ps_spec->polar_aspect_constant;
        dest_generic_coordinate[1]=-2.0*e_constants->A*scale_factor*
          T*((cos_lon*cd_ps_spec->cos_origin_lon)+
             (sin_lon*cd_ps_spec->sin_origin_lon))*cd_ps_spec->polar_aspect_constant;
    }
    dest_generic_coordinate[2]=source_generic_coordinate[2];

    return status;
} /* end Impl_ChangeCD_PS */


Impl_Status
Impl_ChangePS_CD
(
          void           *constants,
    const SRM_Long_Float  source_generic_coordinate[4],
          SRM_Long_Float  dest_generic_coordinate[4]
)
{
    Impl_Status  status = IMPL_VALID;

    SRM_PS_CD_Specific_Constants
      *ps_cd_spec = (SRM_PS_CD_Specific_Constants *)(constants);

    Impl_ORM_Data
      *e_constants=&ps_cd_spec->e_constants;

    SRM_Long_Float
      easting=source_generic_coordinate[0],
      northing=source_generic_coordinate[1],
      *longitude=&dest_generic_coordinate[0],
      *latitude=&dest_generic_coordinate[1],
      longitude_origin=ps_cd_spec->longitude_origin,
      rho=sqrt(SQUARE(easting)+SQUARE(northing)),
      tanz2=IMPL_NAN,
      ski=IMPL_NAN,
      cki=IMPL_NAN;

    if ((rho)<(EPSILON))
    {
        /*
          POINT AT POLE
          We know that we are at a pole and forego the remainder
          of the routine except for the setting of the polar
          aspect.
        */
        *latitude=SRM_PI_DIV_2;
        *longitude=longitude_origin;
    }
    else
    {
        /*POINT NOT AT A POLE: do the whole calculation*/

        northing*= ps_cd_spec->polar_aspect_constant;
        easting*=ps_cd_spec->polar_aspect_constant;
        longitude_origin*=ps_cd_spec->polar_aspect_constant;

        if (e_constants->Eps!=0.0)
        {
            tanz2=rho*ps_cd_spec->scale_inverse*ps_cd_spec->FK_inv;
            {
                /*Get sine and cosine of chi by trig identity from tangent squared*/
                SRM_Long_Float T2=tanz2*tanz2;
                SRM_Long_Float DEN_INV=1.0/(1.0+T2);
                cki=2.0*tanz2*DEN_INV;
                ski=(1.0-T2)*DEN_INV;
            }

            // SIN & COS CHI NOW DONE
            // USE INVERSE POWER SERIES FOR LATITUDE (NO ITERATION)
            {
                SRM_Long_Float sk2=ski*ski;
                SRM_Long_Float xki=SRM_PI_DIV_2-2.0*atan(tanz2);

                *latitude=xki+ski*cki*IMPL_CHI_APPROX(ps_cd_spec->b,sk2);
            }

            //C COMPUTED LATITUDE MAY EXCEED +-PI DUE TO ROUND OFF SO REPAIR IT

            if (*latitude>SRM_PI_DIV_2)
            {
              *latitude=SRM_PI_DIV_2;
            }
            else if (*latitude<-SRM_PI_DIV_2)
            {
              *latitude=-SRM_PI_DIV_2;
            }
        }
        else
        {
            /*Spherical Case (Latitude is different from ellipsoidal case but longitude is the same)*/

            tanz2=rho*(0.5*e_constants->A_inv*ps_cd_spec->scale_inverse);
            *latitude= SRM_PI_DIV_2 - 2.0 * atan(tanz2);
        }

        //C COMPUTE LONGITUDE--MUST USE ATAN2
        *longitude=longitude_origin+atan2(easting,-northing);

        //C CHECK TO SEE IF LON IS IN CORRECT INTERVAL

        if (*longitude> SRM_PI)
        {
            *longitude-=SRM_2_PI;
        }
        else if(*longitude< -SRM_PI)
        {
            *longitude+=SRM_2_PI;
        }
    }
    *latitude *=ps_cd_spec->polar_aspect_constant;
    *longitude*=ps_cd_spec->polar_aspect_constant;
    dest_generic_coordinate[2]=source_generic_coordinate[2];

  /*
    This comment contains Ralph Toms FORTRAN design for
    scale factor computation.  It won't be implemented in this
    routine and instead will be implemented in a separate routine.

    C COMPUTE SCALE
    C SCALE (DEPENDS ON LATITUDE)
    IF (DABS(XLAT) .EQ. PIA2) THEN
    XK=.5D0*XKC*XMC/(E*TC)

    C THIS IS A CORRECTION TO EQUATION (21-35) IN SNYDER WHICH HAS AN
    C EXTRA A IN THE DENOMINATOR.
    WRITE (9,120)
    WRITE (9) "SCALE AT THE POLE"
    WRITE (9,120)
    ELSE
    SN=DSIN(XLAT)
    XM=DCOS(XLAT)/DSQRT(1.D0-e_constants->Eps2*SN*SN)
    XK=RHO/(A*XM)

    END IF

    WRITE (9,120) XLAT,XLON,XK
    WRITE (9,120) G*XLAT,G*XLON,XK
  */
    return status;
} /* end Impl_ChangePS_CD */
