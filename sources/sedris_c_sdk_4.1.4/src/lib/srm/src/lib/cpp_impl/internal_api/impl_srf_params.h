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


/*! @file impl_srf_params.h
    @author Cameron D. Kellough (SRI)
    This file contains the internal representation of SRF parameters used
    by the implementation.  Under no circumstances should this file
    be exported outside of the implementation's internal API.
*/

#ifndef _IMPL_SRF_PARAMS_H
#define _IMPL_SRF_PARAMS_H



typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
}  IMPL_NOPARAM_SRFP;

typedef IMPL_NOPARAM_SRFP IMPL_CELESTIOCENTRIC_SRFP;


typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Axis_Direction up_direction;
  SRM_Axis_Direction forward_direction;
} IMPL_LSR3D_SRFP;

typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Axis_Direction forward_direction;
} IMPL_LSR2D_SRFP;

typedef IMPL_NOPARAM_SRFP IMPL_CELESTIODETIC_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_PLANETODETIC_SRFP;

typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Long_Float geodetic_longitude;
  SRM_Long_Float geodetic_latitude;
  SRM_Long_Float azimuth;
  SRM_Long_Float x_false_origin;
  SRM_Long_Float y_false_origin;
  SRM_Long_Float height_offset;
} IMPL_LOC_TAN_EUCLIDEAN_SRFP;

typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Long_Float geodetic_longitude;
  SRM_Long_Float geodetic_latitude;
  SRM_Long_Float azimuth;
  SRM_Long_Float height_offset;
} IMPL_LT_SRFP;

typedef IMPL_LT_SRFP      IMPL_LOC_TAN_AZ_SPHER_SRFP;
typedef IMPL_LT_SRFP      IMPL_LOC_TAN_AZ_CYL_SRFP;  /*SRM_SRFT_SURFACE_LOCAL_AZIMUTHAL_TANGENT_PLANE*/
typedef IMPL_NOPARAM_SRFP IMPL_AZIMUTHAL_SRFP;
typedef IMPL_LT_SRFP      IMPL_LOC_TAN_CYL_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_POLAR_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_CELESTIOMAGNETIC_SRFP; 
typedef IMPL_NOPARAM_SRFP IMPL_EQUATORIAL_INERTIAL_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_SOLAR_ECLIPTIC_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_SOLAR_ECLIPTIC_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_SOLAR_EQUATORIAL_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_SOLAR_EQUATORIAL_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_SOLAR_MAGNETIC_ECLIPTIC_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_SOLAR_MAGNETIC_DIPOLE_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_HELIO_ARIES_ECLIPTIC_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_HELIO_EARTH_ECLIPTIC_SRFP;
typedef IMPL_NOPARAM_SRFP IMPL_HELIO_EARTH_EQUAT_SRFP;

typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Long_Float origin_longitude;
  SRM_Long_Float central_scale;
  SRM_Long_Float false_easting;
  SRM_Long_Float false_northing;
} IMPL_MERCATOR_SRFP;

typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Long_Float origin_longitude;
  SRM_Long_Float origin_latitude;
  SRM_Long_Float central_scale;
  SRM_Long_Float false_easting;
  SRM_Long_Float false_northing;
} IMPL_TRANSVERSE_MERCATOR_SRFP;

typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Long_Float longitude1;
  SRM_Long_Float latitude1;
  SRM_Long_Float longitude2;
  SRM_Long_Float latitude2;
  SRM_Long_Float central_scale;
  SRM_Long_Float false_easting;
  SRM_Long_Float false_northing;
} IMPL_OBLIQUE_MERCATOR_SRFP;

typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Long_Float origin_longitude;
  SRM_Long_Float origin_latitude;
  SRM_Long_Float latitude1;
  SRM_Long_Float latitude2;
  SRM_Long_Float false_easting;
  SRM_Long_Float false_northing;
} IMPL_LAMBERT_CONF_CONIC_SRFP;

typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Polar_Aspect polar_aspect;
  SRM_Long_Float   origin_longitude;
  SRM_Long_Float   central_scale;
  SRM_Long_Float   false_easting;
  SRM_Long_Float   false_northing;
} IMPL_POLAR_STEREOGRAPHIC_SRFP;

/*!
 * STRUCT: SRM_EC_Parameters
 *
 *  Equidistant Cylindrical (EC) SRF Parameters are used as a means
 *  of specifying the EC spatial coordinate systems
 */
typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Long_Float origin_longitude;
  SRM_Long_Float central_scale;
  SRM_Long_Float false_easting;
  SRM_Long_Float false_northing;
} IMPL_EQUIDISTANT_CYL_SRFP;

/*!
 * STRUCT: SRM_LCE_SRF_Parameters
 *
 *  Localcentric Euclidean 3D (LCE) SRF Parameters are used as a means
 *  of specifying the LCE spatial coordinate systems
 */
typedef struct
{
  union
  {
    SRM_ORM_Code orm;
    SRM_Integer dummy1;
  };
  union
  {
    SRM_RT_Code rt;
    SRM_Integer dummy2;
  };
  SRM_Vector_3D lococentre;
  SRM_Vector_3D primary_axis;
  SRM_Vector_3D secondary_axis;
} IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP;

#endif
