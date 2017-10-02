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


/*! @file srm_validcoord.cpp
    @author Cameron D. Kellough (SRI)

This file contains an array of functions of type capable of access
through Impl_valid_function_ptr defined in impl_private.h.  These functions are
called to validate coordinates.  They are designed to take a private
data structure of the type for the SRF in the name.  They may also take
a pdat from another SRF (CELESTIODETIC does this) as long as only the e_constants
filed of that pdat structure is used.

The functions are designed to be called on the correct SRF for validating a
coordinate of that type which may not be the name of the function type.
The correct validation type is stored in

extern SRM_SRFT_Code (*Impl_SRFTbdef_templcode[])();
extern void* (*Impl_SRFTbdef_srf_params[])(SRM_ORM_Code orm_dst);

defined in impl_private.h.

Fo example, validating a transverse mercator coordinate, one would pass the
appropriate celestiodetic coordinate to Impl_validcoord3DTRANSVERSE_MERCACTOR
with the private data from a transverse mercator SRF.

Impl_valid_function_ptr is typed like this:

Impl_Status (*Impl_validcoord3D[])
  (Impl_Private_Data pdat,
   SRM_Long_Float v_coord[3]
   )

As greater complexity was observed, it was determined that map coordinates
require validation both in celestiodetic and the native srf.  This is due
to the fact that the numerics algorithms cannot be guaranteed to converge for
unbounded inputs.
*/

#include <math.h>
#include <signal.h>
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_validcoord.h"

static bool
Impl_withinHeightAccuracyDomain
(
    SRM_Long_Float height
)
{
    return ((height > -50000.0002) &&
            (height <= 1000000.0));
  /*Because of the numerical nature of the celestiocentric to
    celestiodetic conversion, .2mm of EPSILON error margin is added to
    so that tests on the boundary pass.  Because the output of
    celestiocentric to celestiodetic conversion is guaranteed to 1mm
    and significant figures in the code are meaningful only in the .1mm
    place and higher, this change has no significance other than preventing a
    bunch of good test data from being regenerated. --CDK June 28, 2005
  */
}


// This case now handles the cases where the angular parameter has the
// lower bound > upper bound.  That is the case where the complement angle
// needs to be computed, but there are there ranges of valid angles that makes
// this verification tedious and inefficient.
static Impl_Status Impl_validcoordCheck
(
    Valid_Region_Data *region,
    SRM_Long_Float     v_coord
)
{
    Impl_Status ret_reg=0;
    if (region == 0 || region->type == SRM_IVLTYP_UNBOUNDED)
    {
        ret_reg = IMPL_VALID;
    }
    else
    {
        ret_reg = IMPL_DEFINED;
        switch (region->type)
        {
            case SRM_IVLTYP_OPEN_INTERVAL:
                 // case for the complement circle (l->PI and -PI->h)
                 if (region->is_angular && region->lower > region->upper)
                 {
                     if ((v_coord > region->lower && v_coord < SRM_PI) ||
                         (v_coord > -SRM_PI && v_coord < region->upper))
                         ret_reg = IMPL_VALID;
                     else if ((v_coord > region->extended_lower &&
                               v_coord < SRM_PI) ||
                              (v_coord > -SRM_PI &&
                               v_coord < region->extended_upper))
                         ret_reg = IMPL_EXTENDED;
                 }
                 else
                 {
                     if (v_coord > region->lower && v_coord < region->upper)
                         ret_reg = IMPL_VALID;
                     else if (v_coord > region->extended_lower &&
                              v_coord < region->extended_upper)
                         ret_reg = IMPL_EXTENDED;
                 }
                 break;
            case SRM_IVLTYP_CLOSED_INTERVAL:
                 // case for the complement circle (l->PI and -PI->h)
                 if (region->is_angular && region->lower > region->upper)
                 {
                     if ((v_coord >= region->lower && v_coord < SRM_PI) ||
                         (v_coord > -SRM_PI && v_coord <= region->upper))
                         ret_reg = IMPL_VALID;
                     else if ((v_coord >= region->extended_lower &&
                               v_coord < SRM_PI) ||
                              (v_coord > -SRM_PI &&
                               v_coord <= region->extended_upper))
                         ret_reg = IMPL_EXTENDED;
                 }
                 else
                 {
                     if (v_coord >= region->lower && v_coord <= region->upper)
                         ret_reg = IMPL_VALID;
                     else if (v_coord >= region->extended_lower &&
                              v_coord <= region->extended_upper)
                         ret_reg = IMPL_EXTENDED;
                 }
                 break;
            case SRM_IVLTYP_GE_LT_INTERVAL:
                 // case for the complement circle (l->PI and -PI->h)
                 if (region->is_angular && region->lower > region->upper)
                 {
                     if ((v_coord >= region->lower && v_coord < SRM_PI) ||
                         (v_coord > -SRM_PI && v_coord < region->upper))
                         ret_reg = IMPL_VALID;
                     else if ((v_coord >= region->extended_lower &&
                               v_coord < SRM_PI) ||
                              (v_coord > -SRM_PI &&
                               v_coord < region->extended_upper))
                         ret_reg = IMPL_EXTENDED;
                 }
                 else
                 {
                     if (v_coord >= region->lower && v_coord < region->upper)
                         ret_reg = IMPL_VALID;
                     else if (v_coord >= region->extended_lower &&
                              v_coord < region->extended_upper)
                         ret_reg = IMPL_EXTENDED;
                 }
                 break;
            case SRM_IVLTYP_GE_SEMI_INTERVAL:
                 if (v_coord >= region->lower)
                     ret_reg = IMPL_VALID;
                 else if (v_coord >= region->extended_lower)
                     ret_reg = IMPL_EXTENDED;
                 break;
            case SRM_IVLTYP_GT_SEMI_INTERVAL:
                 if (v_coord > region->lower)
                     ret_reg = IMPL_VALID;
                 else if (v_coord > region->extended_lower)
                     ret_reg = IMPL_EXTENDED;
                 break;
            case SRM_IVLTYP_LE_SEMI_INTERVAL:
                 if (v_coord <= region->upper)
                     ret_reg = IMPL_VALID;
                 else if (v_coord <= region->extended_upper)
                     ret_reg = IMPL_EXTENDED;
                 break;
            case SRM_IVLTYP_LT_SEMI_INTERVAL:
                 if (v_coord < region->upper)
                     ret_reg = IMPL_VALID;
                 else if (v_coord < region->extended_upper)
                     ret_reg = IMPL_EXTENDED;
                 break;
            case SRM_IVLTYP_GT_LE_INTERVAL:
                 // case for the complement circle (l->PI and -PI->h)
                 if (region->is_angular && region->lower > region->upper)
                 {
                     if ((v_coord > region->lower && v_coord < SRM_PI) ||
                         (v_coord > -SRM_PI && v_coord <= region->upper))
                         ret_reg = IMPL_VALID;
                     else if ((v_coord > region->extended_lower &&
                               v_coord < SRM_PI) ||
                              (v_coord > -SRM_PI &&
                               v_coord <= region->extended_upper))
                         ret_reg = IMPL_EXTENDED;
                 }
                 else
                 {
                     if (v_coord > region->lower && v_coord <= region->upper)
                         ret_reg = IMPL_VALID;
                     else if (v_coord > region->extended_lower &&
                              v_coord <= region->extended_upper)
                         ret_reg = IMPL_EXTENDED;
                 }
                 break;
            default:
                 ret_reg = 0; // shouldn't get here, but this preserves
                              // original behaviour
                 break;
        }
    }
    return ret_reg;
}


static Impl_Status
Impl_validcoord2DCheck
(
    Valid_Region_Data *region[3],
    SRM_Long_Float     v_coord[3]
)
{
    Impl_Status reg[2], ret_reg;

    for (int i=0; i<2; i++)
        reg[i] = Impl_validcoordCheck(region[i], v_coord[i]);

    if (reg[0]==IMPL_VALID && reg[1]==IMPL_VALID)
        ret_reg = IMPL_VALID;
    else if (reg[0]==IMPL_DEFINED || reg[1]==IMPL_DEFINED)
        ret_reg = IMPL_DEFINED;
    else
        ret_reg = IMPL_EXTENDED;

    return ret_reg;
}


static Impl_Status
Impl_validcoord3DCheck
(
    Valid_Region_Data *region[3],
    SRM_Long_Float     v_coord[3]
)
{
    Impl_Status reg[3], ret_reg;

    for (int i=0; i<3; i++)
        reg[i] = Impl_validcoordCheck(region[i], v_coord[i]);

    if (reg[0]==IMPL_VALID && reg[1]==IMPL_VALID && reg[2]==IMPL_VALID)
        ret_reg = IMPL_VALID;
    else if (reg[0]==IMPL_DEFINED || reg[1]==IMPL_DEFINED || reg[2]==IMPL_DEFINED)
        ret_reg = IMPL_DEFINED;
    else
        ret_reg = IMPL_EXTENDED;

    return ret_reg;
}


static Impl_Status
Impl_validcoordGDCheck
(
    Valid_Region_Data *region[2],
    SRM_Long_Float     v_coord[3]
)
{
    Impl_Status reg[2], ret_reg;

    for (int i=0; i<2; i++)
        reg[i] = Impl_validcoordCheck(region[i], v_coord[i]);

    if (reg[0]==IMPL_VALID && reg[1]==IMPL_VALID)
       ret_reg = IMPL_VALID;
    else if (reg[0]==IMPL_DEFINED || reg[1]==IMPL_DEFINED)
       ret_reg = IMPL_DEFINED;
    else
        ret_reg = IMPL_EXTENDED;

    return ret_reg;
}


Impl_Status Impl_validcoord3D_NULL_SRFS(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return IMPL_INACTBLE;
}


Impl_Status Impl_validcoord2DNoRestriction(Impl_Private_Data pdat, SRM_Long_Float v_coord[2])
{
    SRM_Long_Float nan_test_value=(v_coord[0]*v_coord[1]);

  /* Not a number is a tricky beast that can be detected because it
     has the unique and unbelievable property that it is not equal
     to itself.  (Read the glibc documentation!).  isnan() is the
     preferred way to test for it but that is not portable so the
     trick of comapring it to itself is used here. CDK March 27,2004.

     This test ensures that a routine that started with a bad
     coordinate and performed an identity operation on it will
     return a bad coordinate.  The multiplication here allows
     us to avoid testing three values for nan since any nan will
     propagate itself through the multiplication
  */
    if (nan_test_value!=nan_test_value)
        return IMPL_INVALID;
    else
        return IMPL_VALID;
}


Impl_Status Impl_validcoord3DNoRestriction
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    SRM_Long_Float nan_test_value=(v_coord[0]*v_coord[1]*v_coord[2]);

  /* Not a number is a tricky beast that can be detected because it
     has the unique and unbelievable property that it is not equal
     to itself.  (Read the glibc documentation!).  isnan() is the
     preferred way to test for it but that is not portable so the
     trick of comapring it to itself is used here. CDK March 27,2004.

     This test ensures that a routine that started with a bad
     coordinate and performed an identity operation on it will
     return a bad coordinate.  The multiplication here allows
     us to avoid testing three values for nan since any nan will
     propogate istself through the multiplication
  */
    if (nan_test_value!=nan_test_value)
        return IMPL_INVALID;
    else
        return IMPL_VALID;
}


Impl_Status Impl_validcoord3DIllegal
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    return IMPL_ILLEGL;
}

/*******************************************************************************
  Validation Routines for SRFT based SRFs
*******************************************************************************
*/

Impl_Status Impl_validcoord3DLSR
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *u, *v, *w;

    u=&v_coord[0];
    v=&v_coord[1];
    w=&v_coord[2];

    if (fabs(*u) + fabs(*v) + fabs(*w) > EPSILON)
    {
        return IMPL_VALID;
    }
    else
    {
        return IMPL_INVALID;
    }
}


Impl_Status Impl_validcoord2DLSR
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *u, *v;

    u=&v_coord[0];
    v=&v_coord[1];

    if (fabs(*u) + fabs(*v) > EPSILON)
    {
        return IMPL_VALID;
    }
    else
    {
        return IMPL_INVALID;
    }
}


/* This routine is called to validate a celestiodetic surface coordinate when
   it is used as part of some SRF parameters.
 */
Impl_Status
Impl_validcoord2DCELESTIODETIC_cs
(
    SRM_Long_Float *longitude,
    SRM_Long_Float *geodetic_latitude
)
{
    // In addition to (longitude,geodetic_latitude) pairs that
    // pass the well-formed tests, accept (0, +/- SRM_PI_DIV_2)
    if ((Impl_wellFormedLongitude(*longitude)&&
         Impl_wellFormedLatitude(*geodetic_latitude))
      || ((*longitude == 0.0) &&
          ((*geodetic_latitude == -SRM_PI_DIV_2)
        || (*geodetic_latitude ==  SRM_PI_DIV_2))))
    {
        return IMPL_VALID;
    }
    else
    {
        return IMPL_INVALID;
    }
}


/* This routine is called by
     Impl_validcoord3DCELESTIODETIC,
     Impl_validcoord3DTRANSVERSE_MERCATOR_cd.
   A generic SRF object is passed in and as long as we need only the
   e_constants, we can get away with accessing them on the generic SRF object.
   If ever we need to access parameters that are specific to the SRF then we
   will need to do something more sophisticated.
 */
static Impl_Status
Impl_validcoord3DCELESTIODETIC_cs
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *longitude, *geodetic_latitude, *ellipsoidal_height;

    longitude         =&v_coord[0];
    geodetic_latitude =&v_coord[1];
    ellipsoidal_height=&v_coord[2];

    // In addition to (longitude,geodetic_latitude) pairs that
    // pass the well-formed tests, accept (0, +/- SRM_PI_DIV_2)
    if (((Impl_wellFormedLongitude(*longitude)&&
          Impl_wellFormedLatitude(*geodetic_latitude))
      || ((*longitude == 0.0) &&
          ((*geodetic_latitude == -SRM_PI_DIV_2)
        || (*geodetic_latitude ==  SRM_PI_DIV_2))))
    // This validation is to assure that the ellipsoidal height does not
    // overshoot the center of the planet
     && (*ellipsoidal_height > -pdat.e_constants->B) &&
        Impl_withinHeightAccuracyDomain(*ellipsoidal_height))
    {
        return IMPL_VALID;
    }
    else
    {
        return IMPL_INVALID;
    }
}


/* This routine is called by some of the map projections.  It is a generic
   SRF object passed in and as long as we need only the e_constants, we can
   get away with accessing them on the generic SRF object.  If ever we need
   to access parameters that are specific to the SRF then we will need to do
   something more sophisticated.
 */
Impl_Status Impl_validcoord3DCELESTIODETIC
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    Impl_Status reg[2], ret_reg = IMPL_VALID;

    if ((ret_reg = Impl_validcoord3DCELESTIODETIC_cs(pdat, v_coord))
        == IMPL_VALID)
    {
        reg[0] = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
        reg[1] = Impl_validcoordGDCheck(pdat.Component_valid_gd_region, v_coord);

        if (reg[0]==IMPL_VALID && reg[1]==IMPL_VALID)
            ret_reg = IMPL_VALID;
        else if (reg[0]==IMPL_INVALID || reg[1]==IMPL_INVALID)
            ret_reg = IMPL_INVALID;
        else if (reg[0]==IMPL_DEFINED || reg[1]==IMPL_DEFINED)
            ret_reg = IMPL_DEFINED;
        else
            ret_reg = IMPL_EXTENDED;
    }
    return ret_reg;
}


Impl_Status Impl_validcoord3DPLANETODETIC
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *longitude, *geodetic_latitude, *ellipsoidal_height;
    Impl_Status ret_reg;

    geodetic_latitude=&v_coord[1];
    longitude=&v_coord[0];
    ellipsoidal_height=&v_coord[2];

    // In addition to (longitude,geodetic_latitude) pairs that
    // pass the well-formed tests, accept (0, +/- SRM_PI_DIV_2)
    if (((Impl_wellFormedLongitude(*longitude)&&
          Impl_wellFormedLatitude(*geodetic_latitude))
      || ((*longitude == 0.0) &&
          ((*geodetic_latitude == -SRM_PI_DIV_2)
        || (*geodetic_latitude ==  SRM_PI_DIV_2))))
     && (*ellipsoidal_height > -pdat.e_constants->B) &&
        Impl_withinHeightAccuracyDomain(*ellipsoidal_height))
    {
        ret_reg = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
    }
    else
    {
        ret_reg = IMPL_INVALID;
    }
    return ret_reg;
}


Impl_Status Impl_validcoord2DAZIMUTHAL
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *azimuth, *radius;
    Impl_Status ret_reg;

    azimuth =&v_coord[0];
    radius=&v_coord[1];

    if ((Impl_wellFormedAzimuth(*azimuth) &&
         Impl_wellFormedRadius(*radius))
     || ((*azimuth == 0.0) && (*radius == 0.0)))
    {
        ret_reg = Impl_validcoord2DCheck(pdat.Component_valid_region, v_coord);
    }
    else
    {
        ret_reg = IMPL_INVALID;
    }
    return ret_reg;
}


Impl_Status Impl_validcoord3DLOC_TAN_CYL
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *angle, *radius;

    angle =&v_coord[0];
    radius=&v_coord[1];
    // no constraint on height

    if ((Impl_wellFormedCylindricalAngle(*angle) &&
         Impl_wellFormedRadius(*radius)) ||
        ((*angle == 0.0) && (*radius == 0.0)))
    {
        return Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
    }
    else
    {
        return IMPL_INVALID;
    }
}


Impl_Status Impl_validcoord2DPOLAR
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *angle, *radius;
    Impl_Status ret_reg=IMPL_INACTBLE;

    radius=&v_coord[1];
    angle =&v_coord[0];

    if ((Impl_wellFormedRadius(*radius) &&
         Impl_wellFormedAzimuth(*angle))
     || ((*radius == 0.0) &&
         (*angle == 0.0)))
    {
        ret_reg = Impl_validcoord2DCheck(pdat.Component_valid_region, v_coord);
    }
    else
    {
        ret_reg = IMPL_INVALID;
    }
    return ret_reg;
}


Impl_Status Impl_validcoord3DMERCATOR_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
  /*!\note that this routine receives a mercator SRF but a coordinate that
    is celestiodetic since validation for mercator is performed in a
    celestiodetic SRF*/

  /*!
    \note also that this probably needs some actual validation performed
    but we have nothing in the legacy math code checking this
  */
    return Impl_validcoord3DCELESTIODETIC(pdat,v_coord);
}


/* This routine is called by some of the map projections.  It is a generic
   SRF object passed in and as long as we need only the e_constants, we can
   get away with accessing them on the generic SRF object.  If ever we need
   to access parameters that are specific to the SRF then we will need to do
   something more sophisticated.
 */
Impl_Status Impl_validcoord3DOBLIQUE_MERCATOR_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    /*This ensures that the coordinate that we got is actually a good celestiodetic*/
    return Impl_validcoord3DCELESTIODETIC(pdat,v_coord);
}


Impl_Status Impl_validcoord3DTRANSVERSE_MERCATOR_cd
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
  /*!\note that this routine receives a transverse mercator SRF but a
    coordinate that is celestiodetic since validation for mercator is
    performed in a celestiodetic SRF*/

    Impl_Status reg[2], ret_reg=IMPL_INACTBLE;

    IMPL_MERCATOR_SRFP* my_m_srf=(IMPL_MERCATOR_SRFP*)(pdat.impl_SRFP_struct);

    register SRM_Long_Float *geodetic_longitude, *geodetic_latitude;

    geodetic_longitude=&(v_coord[0]);
    geodetic_latitude=&(v_coord[1]);

 /*This ensures that the coordinate that we got is actually a good celestiodetic*/
   ret_reg = Impl_validcoord3DCELESTIODETIC_cs(pdat,v_coord);

    if (! (ret_reg & IMPL_BADSTAT))
    {
        if (
            (delta_lambda_min(*geodetic_longitude,my_m_srf->origin_longitude)
             <= (6.0*SRM_RADIANS_PER_DEGREE)) &&
            (fabs(*geodetic_latitude)
             <= (89.5*SRM_RADIANS_PER_DEGREE)))
        {
            reg[0] = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
            reg[1] = Impl_validcoordGDCheck(pdat.Component_valid_gd_region, v_coord);

            if (reg[0]==IMPL_VALID && reg[1]==IMPL_VALID)
                ret_reg = IMPL_VALID;
            else if (reg[0]==IMPL_INVALID || reg[1]==IMPL_INVALID)
                ret_reg = IMPL_INVALID;
            else if (reg[0]==IMPL_DEFINED || reg[1]==IMPL_DEFINED)
                ret_reg = IMPL_DEFINED;
            else
                ret_reg = IMPL_EXTENDED;
        }
        else
        if ((delta_lambda_min(*geodetic_longitude,my_m_srf->origin_longitude)
             <= (12.0*SRM_RADIANS_PER_DEGREE)) &&
            (fabs(*geodetic_latitude)
             <= (89.5*SRM_RADIANS_PER_DEGREE)))
        {
            reg[0] = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
            reg[1] = Impl_validcoordGDCheck(pdat.Component_valid_gd_region, v_coord);

            if (reg[0]==IMPL_VALID && reg[1]==IMPL_VALID)
                ret_reg = IMPL_VALID;
            else if (reg[0]==IMPL_INVALID || reg[1]==IMPL_INVALID)
                ret_reg = IMPL_INVALID;
            else if (reg[0]==IMPL_DEFINED || reg[1]==IMPL_DEFINED)
                ret_reg = IMPL_DEFINED;
            else
                ret_reg = IMPL_EXTENDED;
        }
        else
        {
            ret_reg = IMPL_INVALID;
        }
    }
    else
    {
        ret_reg = IMPL_INVALID;
    }
    return ret_reg;
}


Impl_Status Impl_validcoord3DLAMBERT_CONF_CONIC_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return Impl_validcoord3DCELESTIODETIC(pdat,v_coord);
}


/*!\note that this routine receives a PS SRF but a coordinate that is
  celestiodetic since validation for PS is performed in a celestiodetic
  SRF
 */
Impl_Status Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    IMPL_POLAR_STEREOGRAPHIC_SRFP* my_ps_srf=(IMPL_POLAR_STEREOGRAPHIC_SRFP*)pdat.impl_SRFP_struct;
    Impl_Status ret_reg;

    register SRM_Long_Float  *geodetic_latitude,  *geodetic_longitude;

    geodetic_longitude=&v_coord[0];
    geodetic_latitude=&v_coord[1];
// no restriction on ellipsoidal height

  /*The fundamental definition for polar stereographic states that the
    northern polar aspect is good for the entire northern hemisphere and
    the southern polar aspect is good for the entire southern hemisphere.

    This routine assumes that the polar region is valid and anything
    to the equator is extended which lies in contrast to univeral
    polar stereographic which is defined specifically.  This also
    contrasts with the TEK-SR7 definition which lists 83.5 as the
    valid boundary for ps and -79.5 as the other valid boundary.
   */
    if (my_ps_srf->polar_aspect==SRM_PLRASP_NORTH)
    {
        if ((*geodetic_latitude >= 0.0 && *geodetic_latitude < SRM_PI_DIV_2 &&
             *geodetic_longitude > -SRM_PI && *geodetic_longitude <= SRM_PI)
         || (*geodetic_latitude ==  SRM_PI_DIV_2 &&
             *geodetic_longitude == 0.0))
        {
            ret_reg = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
        }
        else
        {
            ret_reg = IMPL_INVALID;
        }
    }
    else
    {
        if ((*geodetic_latitude > -SRM_PI_DIV_2 && *geodetic_latitude <= 0.0 &&
             *geodetic_longitude > -SRM_PI && *geodetic_longitude <= SRM_PI)
         || (*geodetic_latitude == -SRM_PI_DIV_2 &&
             *geodetic_longitude == 0.0))
        {
            ret_reg = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
        }
        else
        {
            ret_reg = IMPL_INVALID;
        }
    }
    return ret_reg;
}


Impl_Status Impl_validcoord3DEQUIDISTANT_CYL_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
  /*!\note there may be something better but this is what the standard
    showed and our EC formulation is still in flux.  CDK Feb 4, 2004
  */
    return Impl_validcoord3DCELESTIODETIC(pdat,v_coord);
}


Impl_Status Impl_validcoordSpherical
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *spherical_latitude, *spherical_longitude, *radius;

    spherical_longitude=&v_coord[0];
    spherical_latitude=&v_coord[1];
    radius=&v_coord[2];

    // three cases
    // 1) well formed spherical_longitude, spherical_latitude,
    //    and radius
    // 2) spherical_longitude == 0.0, with a spherical_latitude
    //    of + or - SRM_PI_DIV_2, and well formed radius
    // 3) (0,0,0)
    if ((((Impl_wellFormedLongitude(*spherical_longitude)&&
           Impl_wellFormedLatitude(*spherical_latitude))
      || ((*spherical_longitude == 0.0) &&
          ((*spherical_latitude == -SRM_PI_DIV_2) ||
           (*spherical_latitude ==  SRM_PI_DIV_2))))
     && Impl_wellFormedRadius(*radius))
     || ((*spherical_longitude == 0.0) &&
         (*spherical_latitude == 0.0) &&
         (*radius == 0.0)))
        return IMPL_VALID;
    else
        return IMPL_INVALID;
}


Impl_Status Impl_validcoordSpherical_cs
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *spherical_latitude, *spherical_longitude, *radius;
    Impl_Status ret_reg;

    spherical_longitude=&v_coord[0];
    spherical_latitude=&v_coord[1];
    radius=&v_coord[2];

    // three cases
    // 1) well formed spherical_longitude, spherical_latitude,,
    //    and radius
    // 2) spherical_longitude == 0.0, with a spherical_latitude
    //    of + or - SRM_PI_DIV_2, and well formed radius
    // 3) (0,0,0)
    if ((((Impl_wellFormedLongitude(*spherical_longitude)&&
           Impl_wellFormedLatitude(*spherical_latitude))
      || ((*spherical_longitude == 0.0) &&
          ((*spherical_latitude == -SRM_PI_DIV_2) ||
           (*spherical_latitude ==  SRM_PI_DIV_2))))
     && Impl_wellFormedRadius(*radius))
     || ((*spherical_longitude == 0.0) &&
         (*spherical_latitude == 0.0) &&
         (*radius == 0.0)))
        ret_reg = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
    else
        ret_reg = IMPL_INVALID;

    return ret_reg;
}


Impl_Status Impl_validcoordAzSpherical
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *azimuth, *elevation_angle, *radius;
    Impl_Status ret_reg;

    azimuth=&v_coord[0];
    elevation_angle=&v_coord[1];
    radius=&v_coord[2];

    // three cases
    // 1) well formed azimuth, elevation_angle,
    //    and radius
    // 2) azimuth == 0.0, with an elevation_angle
    //    of + or - SRM_PI_DIV_2, and well formed radius
    // 3) (0,0,0)
    if ((((Impl_wellFormedAzimuth(*azimuth)&&
           Impl_wellFormedLatitude(*elevation_angle))
      || ((*azimuth == 0.0) &&
          ((*elevation_angle == -SRM_PI_DIV_2) ||
           (*elevation_angle ==  SRM_PI_DIV_2))))
     && Impl_wellFormedRadius(*radius))
     || ((*azimuth == 0.0) &&
         (*elevation_angle == 0.0) &&
         (*radius == 0.0)))
        ret_reg = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
    else
        ret_reg = IMPL_INVALID;

    return ret_reg;
}


Impl_Status Impl_validcoord3DCylindrical
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    register SRM_Long_Float *cylindrical_angle_theta, *radius_rho;
    Impl_Status ret_reg;

    cylindrical_angle_theta=&v_coord[0];
    radius_rho=&v_coord[1];
//  no constraint on height_zeta

    if ((Impl_wellFormedCylindricalAngle(*cylindrical_angle_theta)&&
         Impl_wellFormedRadius(*radius_rho))
     || (*cylindrical_angle_theta == 0.0 &&
         *radius_rho              == 0.0))
        ret_reg = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
    else
        ret_reg = IMPL_INVALID;

    return ret_reg;
}


/**********************************************************************************
  Validation routines for SRF sets.

***********************************************************************************/

Impl_Status Impl_validcoord3D_ALSP_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
}


Impl_Status Impl_validcoord3D_GCSG(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
  /*This is the version that is used in conversions where it is not on the path to
    check the validity
  */
    return Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
}


Impl_Status Impl_validcoord3D_GCSG_cd_special(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
  /*This uses code inside of the GTRS library to look up the validity of a
    GCS coordinate. It takes the cellid and the WGS84 Celestiodetic
    coordinates of a point
  */
    return Impl_GTRS_validcoord(pdat.srfs_member_code,v_coord);
}


Impl_Status Impl_validcoord3D_UPST_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
  /*!\note that this routine receives a transverse mercator SRF but a
    coordinate that is celestiodetic since validation for mercator is
    performed in a celestiodetic SRF*/
    Impl_Status ret_reg;

    register SRM_Long_Float *geodetic_latitude;

//  no constraint on geodetic_longitude or ellipsoidal height
    geodetic_latitude=&v_coord[1];

    // if user set valid region for latitude then use them
    if (pdat.Component_valid_region[1] != 0)
    {
        // if northern pole and within the default northern extended region or
        // if southern pole and within the default southern extended region
        if ((pdat.srfs_member_code == SRM_SRFSMUPSCOD_NORTHERN_POLE &&
             *geodetic_latitude >= 83.5*SRM_RADIANS_PER_DEGREE) ||
            (pdat.srfs_member_code == SRM_SRFSMUPSCOD_SOUTHERN_POLE &&
             *geodetic_latitude <= -79.5*SRM_RADIANS_PER_DEGREE))
        {
            ret_reg = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
        }
        else
        {
            ret_reg = IMPL_INVALID;
        }
    }
    else // if no user set valid region, then use default valid regions
    {
        if (pdat.srfs_member_code== SRM_SRFSMUPSCOD_NORTHERN_POLE)
        {
            if (*geodetic_latitude>= 84.0*SRM_RADIANS_PER_DEGREE)
            {
                ret_reg = IMPL_VALID;
            }
            else if (*geodetic_latitude>= 83.5*SRM_RADIANS_PER_DEGREE)
            {
                ret_reg = IMPL_EXTENDED;
            }
            else
            {
                ret_reg = IMPL_INVALID;
            }
        }
        else
        {
            if (*geodetic_latitude<= -80.0*SRM_RADIANS_PER_DEGREE)
            {
                ret_reg = IMPL_VALID;
            }
            else if (*geodetic_latitude<= -79.5*SRM_RADIANS_PER_DEGREE)
            {
                ret_reg = IMPL_EXTENDED;
            }
            else
            {
                ret_reg = IMPL_INVALID;
            }
        }
    }
    return ret_reg;
}


Impl_Status Impl_validcoord3D_UTMC_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
  /*!\note that this routine receives a transverse mercator SRF but a
    coordinate that is celestiodetic since validation for mercator is
    performed in a celestiodetic SRF*/
    IMPL_MERCATOR_SRFP* my_m_srf=(IMPL_MERCATOR_SRFP*)(pdat.impl_SRFP_struct);
    Impl_Status ret_reg = 1;

    register SRM_Long_Float *geodetic_longitude, *geodetic_latitude;

    geodetic_longitude=&(v_coord[0]);
    geodetic_latitude=&(v_coord[1]);
//  only constraint on ellipsoidal_height is enforced by
//  Impl_validcoord3DCELESTIODETIC

    SRM_Long_Float dlm = delta_lambda_min(*geodetic_longitude,my_m_srf->origin_longitude);

    /*This ensures that the coordinate we got is actually a good celestiodetic*/
    ret_reg=Impl_validcoord3DCELESTIODETIC(pdat,v_coord);

    if (ret_reg&IMPL_BADSTAT)
        ret_reg = IMPL_INVALID;

    // if user set valid region for lon and lat then use them
    if (pdat.Component_valid_region[0] != 0 && pdat.Component_valid_region[1] != 0)
    {
        // We just need to verify whether it is within the extended valid region
        if ((pdat.srfs_member_code<=60 &&
             (dlm <= (6.0*SRM_RADIANS_PER_DEGREE))&&
             (*geodetic_latitude < 84.5*SRM_RADIANS_PER_DEGREE)&&
             (*geodetic_latitude >= -0.5*SRM_RADIANS_PER_DEGREE)) ||
            (pdat.srfs_member_code > 60 &&
             (dlm <= (6.0*SRM_RADIANS_PER_DEGREE))&&
             (*geodetic_latitude < 0.5  *SRM_RADIANS_PER_DEGREE)&&
             (*geodetic_latitude >= -80.5*SRM_RADIANS_PER_DEGREE)))
        {
            ret_reg = Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
        }
    }
    // $$$ need to come back and add some case for partially set regions, ie., only lon or lat.
    else
    {
        if (pdat.srfs_member_code<=60)
        {
            if (
               (dlm <= (3.0*SRM_RADIANS_PER_DEGREE)) &&
               (*geodetic_latitude < (84.0*SRM_RADIANS_PER_DEGREE))&&
               (*geodetic_latitude >= (0.0*SRM_RADIANS_PER_DEGREE))
               )
            {
                ret_reg = IMPL_VALID;
            }
            else
            {
                if (
                   (dlm <= (6.0*SRM_RADIANS_PER_DEGREE))&&
                   (*geodetic_latitude < (84.5*SRM_RADIANS_PER_DEGREE))&&
                   (*geodetic_latitude >= (-0.5*SRM_RADIANS_PER_DEGREE))
                   )
                {
                    ret_reg = IMPL_EXTENDED;
                }
                else
                {
                    ret_reg = IMPL_INVALID;
                }
            }
        }
        else
        {
            if (
               (dlm <= (3.0*SRM_RADIANS_PER_DEGREE))&&
               (*geodetic_latitude<=   (0.0*SRM_RADIANS_PER_DEGREE))&&
               (*geodetic_latitude>= (-80.0*SRM_RADIANS_PER_DEGREE))
               )
            {
                ret_reg = IMPL_VALID;
            }
            else
            {
                if (
                   (dlm <= (6.0*SRM_RADIANS_PER_DEGREE))&&
                   (*geodetic_latitude<= (0.5*SRM_RADIANS_PER_DEGREE))&&
                   (*geodetic_latitude>= (-80.5*SRM_RADIANS_PER_DEGREE))
                   )
                {
                    ret_reg = IMPL_EXTENDED;
                }
                else
                {
                    ret_reg = IMPL_INVALID;
                }
            }
        }
    }
    return ret_reg;
}


Impl_Status Impl_validcoord3D_WISP_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return Impl_validcoord3DLAMBERT_CONF_CONIC_cd(pdat,v_coord);
}


Impl_Status Impl_validcoord3D_LNTF_cd
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    Impl_Status status;

    switch (pdat.srfs_member_code)
    {
        case SRM_SRFSMLAMNTFCOD_ZONE_I:
             if ((v_coord[0]>=  -5.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[0]<=  10.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[1]>=  53.5*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[1]<=  57.0*SRM_RADIANS_PER_DEGREE))
                 status= Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
             else
                 status=IMPL_INVALID;
             break;
        case SRM_SRFSMLAMNTFCOD_ZONE_II:
             if ((v_coord[0]>=  -5.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[0]<=  10.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[1]>=  50.5*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[1]<=  53.5*SRM_RADIANS_PER_DEGREE))
                 status= Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
             else
                 status=IMPL_INVALID;
             break;
        case SRM_SRFSMLAMNTFCOD_ZONE_III:
             if ((v_coord[0]>=  -5.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[0]<=  10.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[1]>=  47.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[1]<=  50.5*SRM_RADIANS_PER_DEGREE))
                 status= Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
             else
                 status= IMPL_INVALID;
             break;
        case SRM_SRFSMLAMNTFCOD_ZONE_IV:
             if ((v_coord[0]>=   8.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[0]<=  10.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[1]>=  41.0*SRM_RADIANS_PER_DEGREE)&&
                 (v_coord[1]<=  43.5*SRM_RADIANS_PER_DEGREE))
                 status= Impl_validcoord3DCheck(pdat.Component_valid_region, v_coord);
             else
                 status= IMPL_INVALID;
             break;
        default:
             status=IMPL_INACTBLE;
             break;
    }
    return status;
}


Impl_Status Impl_validcoord3D_MTMB_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
}


Impl_Status Impl_validcoord3D_MTMP_cd(Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
}


Impl_Status Impl_validcoord3D_JRPS_cd
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    Impl_Status status;

    switch (pdat.srfs_member_code)
    {
        case SRM_SRFSMJPRPCSCOD_ZONE_I:
        case SRM_SRFSMJPRPCSCOD_ZONE_II:
        case SRM_SRFSMJPRPCSCOD_ZONE_III:
        case SRM_SRFSMJPRPCSCOD_ZONE_IV:
        case SRM_SRFSMJPRPCSCOD_ZONE_V:
        case SRM_SRFSMJPRPCSCOD_ZONE_VI:
        case SRM_SRFSMJPRPCSCOD_ZONE_VII:
        case SRM_SRFSMJPRPCSCOD_ZONE_VIII:
        case SRM_SRFSMJPRPCSCOD_ZONE_IX:
        case SRM_SRFSMJPRPCSCOD_ZONE_X:
        case SRM_SRFSMJPRPCSCOD_ZONE_XI:
        case SRM_SRFSMJPRPCSCOD_ZONE_XII:
        case SRM_SRFSMJPRPCSCOD_ZONE_XIII:
             // make this more specific as the zone information is
             // made more quantitative
             status = Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XIV:
             if (((v_coord[0] > 140.5*SRM_RADIANS_PER_DEGREE) &&
                  (v_coord[0] < 143.0*SRM_RADIANS_PER_DEGREE)) &&
                  (v_coord[1] < 28.0*SRM_RADIANS_PER_DEGREE))
             {
                 status = Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
             }
             else
             {
                 status= IMPL_INVALID;
             }
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XV:
             if ((v_coord[0] > 126.0*SRM_RADIANS_PER_DEGREE) &&
                 (v_coord[0] < 130.0*SRM_RADIANS_PER_DEGREE))
             {
                 status = Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
             }
             else
             {
                 status= IMPL_INVALID;
             }
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XVI:
             if (v_coord[0] > 126.0*SRM_RADIANS_PER_DEGREE)
             {
                 status = Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
             }
             else
             {
                 status= IMPL_INVALID;
             }
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XVII:
             if (v_coord[0] > 130.0*SRM_RADIANS_PER_DEGREE)
             {
                 status = Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
             }
             else
             {
                 status= IMPL_INVALID;
             }
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XVIII:
             if ((v_coord[0] > 140.5*SRM_RADIANS_PER_DEGREE)
              && (v_coord[1] < 28.0*SRM_RADIANS_PER_DEGREE))
             {
                 status = Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
             }
             else
             {
                 status= IMPL_INVALID;
             }
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XIX:
             if ((v_coord[0] > 143.0*SRM_RADIANS_PER_DEGREE)
              && (v_coord[1] < 28.0*SRM_RADIANS_PER_DEGREE))
             {
                 status = Impl_validcoord3DTRANSVERSE_MERCATOR_cd(pdat,v_coord);
             }
             else
             {
                 status= IMPL_INVALID;
             }
             break;
        default:
             status=IMPL_INACTBLE;
             break;
    }
    return status;
}


Impl_Status Impl_validcoord3DMERCATOR_native (Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    IMPL_MERCATOR_SRFP* m=(IMPL_MERCATOR_SRFP*) (pdat.impl_SRFP_struct);

  /* checks to see if the mercator coordinate falls inside a box
     slightly larger than what would happen if a spherical planet's
     equator were flattened as the x axis of the box and the prime
     meridian were flattened as the y axis*/
    if ((fabs((double)v_coord[0]+m->false_easting) > 1.3 *SRM_2_PI* pdat.e_constants->A*m->central_scale)||
        (fabs((double)v_coord[1]+m->false_northing) > 1.3 *SRM_2_PI* pdat.e_constants->B*m->central_scale)
        )
        return IMPL_INVALID;
    else
        return IMPL_VALID;
}


Impl_Status Impl_validcoord3DOBLIQUE_MERCATOR_native    (Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return IMPL_UNIMPLEM;
}


Impl_Status Impl_validcoord3DTRANSVERSE_MERCATOR_native
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
)
{
    Impl_Status                   status = IMPL_VALID;
    Impl_TMERC_SRF_Specific_Data *my_ssd= (Impl_TMERC_SRF_Specific_Data*) (pdat.impl_SRF_data);

    if (v_coord[1] > my_ssd->y_threshold)
    {
        if (v_coord[1] > (my_ssd->m*-fabs(v_coord[0])+my_ssd->bl))
            status = IMPL_INVALID;
    }
    else if (v_coord[1]< -my_ssd->y_threshold)
    {
        if (v_coord[1] < (-my_ssd->m*-fabs(v_coord[0])-my_ssd->bl))
            status = IMPL_INVALID;
    }
    else if (fabs(v_coord[0])> my_ssd->x_threshold)
        status = IMPL_INVALID;

    return status;
}


Impl_Status Impl_validcoord3DLAMBERT_CONF_CONIC_native  (Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
  /*It is possible that Lambert Conformal Conic needs a sophisticated
    validation algorithm for rejecting points outside the region of
    convergence for the inverse algorithm similar to transverse
    mercator.  Currently we check only that the CD coordinate is valid
    after the LCC -> CD operation.  The consequences of not checking
    the validity of coordinates passed to inverse LCC is unknown and
    based on the precise convergence characteristics of the LCC to CD
    conversions.
  */
    return IMPL_UNIMPLEM;
}


Impl_Status Impl_validcoord3DPOLAR_STEREOGRAPHIC_native (Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return IMPL_UNIMPLEM;
}


Impl_Status Impl_validcoord3DEQUIDISTANT_CYL_native     (Impl_Private_Data pdat, SRM_Long_Float v_coord[3])
{
    return IMPL_UNIMPLEM;
}
