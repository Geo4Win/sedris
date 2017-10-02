/*! @file srm_srf_sets.cpp
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


#include <math.h>
#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_internal.h"
#include "srm_validcoord.h"
#include "impl_vos.h"
#include "srm_srfp.h"

/*Beginning of SRF set allocators*/

void* Impl_allocsrfNULL_SRFS
(
    SRM_SRFS_Code_Info srfs_code_info,
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt
)
{
    return 0;
}

void *Impl_allocsrfALABAMA_SPCS
(
    SRM_SRFS_Code_Info srfs_code_info,
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt
)
{
    SRM_TM_Parameters api_srf;

    switch (srfs_code_info.value.srfsm_alabama_spcs)
    {
        case SRM_SRFSMALCOD_WEST_ZONE:
             api_srf.origin_longitude=(-87.0-30.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (30.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.central_scale= 1.0-(1.0/15000.0);
             api_srf.false_easting= 600000.0;
             api_srf.false_northing=0.0;
             break;
        case SRM_SRFSMALCOD_EAST_ZONE:
             api_srf.origin_longitude=(-85.0-50.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (30.0+30.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.central_scale= 1.0-(1.0/25000.0);
             api_srf.false_easting= 200000.0;
             api_srf.false_northing=0.0;
             break;
        default:
             return 0;
    }
    return Impl_allocsrfTRANSVERSE_MERCATOR(orm,rt,&api_srf);
}


void *Impl_allocsrfGTRS_GLOB_COORD_SYS
(
    SRM_SRFS_Code_Info srfs_code_info,
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt
)
{
  SRM_LTSE_Parameters api_srf;

  api_srf.azimuth=0.0;
  api_srf.x_false_origin=50000.0;
  api_srf.y_false_origin=50000.0;
  api_srf.height_offset=0.0;

  if((srfs_code_info.value.srfsm_gtrs_gcs<0) ||(srfs_code_info.value.srfsm_gtrs_gcs> SRM_SRFSM_GTRS_GLOBAL_COORDINATE_SYSTEM_CODE_UBOUND))
    {
      return 0;
    }

  {
    LTP_cell_origin origin={0.0,0.0};
    origin = get_GCS_cell_origin
             (
                 srfs_code_info.value.srfsm_gtrs_gcs,
                 Master_GTRS_Table
             );
    api_srf.geodetic_longitude=origin.lon;
    api_srf.geodetic_latitude=origin.lat;
  }
  return Impl_allocsrfLOC_TAN_EUCLIDEAN(orm,rt,(void*)&api_srf);
}


void *Impl_allocsrfLAMBERT_NTF
(
    SRM_SRFS_Code_Info srfs_code_info,
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt
)
{
  SRM_LCC_Parameters api_srf;

  api_srf.origin_longitude=0.0*SRM_RADIANS_PER_DEGREE;

  switch(srfs_code_info.value.srfsm_lambert_ntf)
    {
    case SRM_SRFSMLAMNTFCOD_ZONE_I:
      api_srf.origin_latitude=(49.5)*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude1= (48.0+ (35.0/60.0)+ (54.682/3600.0)) *SRM_RADIANS_PER_DEGREE;
      api_srf.latitude2=(50.0+( 23.0/60.0)+( 45.282/3600.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.false_northing=200000.0;
      api_srf.false_easting= 600000.0;
      break;
    case SRM_SRFSMLAMNTFCOD_ZONE_II:
      api_srf.origin_latitude=(46.8)*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude1= (45.0+ (53.0/60.0)+  (56.108/3600.0))* SRM_RADIANS_PER_DEGREE;
      api_srf.latitude2=(47.0+( 41.0/60.0)+( 45.652/3600.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.false_northing=200000.0;
      api_srf.false_easting= 600000.0;
      break;
    case SRM_SRFSMLAMNTFCOD_ZONE_III:
      api_srf.origin_latitude=(44.1)*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude1= (43.0 + (11.0/60.0) + (57.449/3600.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude2=(44.0+( 59.0/60.0)+( 45.938/3600.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.false_northing=200000.0;
      api_srf.false_easting= 600000.0;
      break;
    case  SRM_SRFSMLAMNTFCOD_ZONE_IV:
      api_srf.origin_latitude=(42.0+(9.0/60.0)+(54.0/3600.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude1= (41.0+ (33.0/60.0) + (37.396/3600.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude2=(42.0+( 46.0/60.0)+( 3.588/3600))*SRM_RADIANS_PER_DEGREE;
      api_srf.false_northing=185861.369;
      api_srf.false_easting= 234358.0;
      break;

    default:
      return 0;
    }
    return Impl_allocsrfLAMBERT_CONF_CONIC(orm,rt,&api_srf);
}


void *Impl_allocsrfUNIV_POLAR_STEREOG
(
    SRM_SRFS_Code_Info srfs_code_info,
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt
)
{
    SRM_PS_Parameters api_srf;

    api_srf.polar_aspect= (srfs_code_info.value.srfsm_ups==1) ? SRM_PLRASP_NORTH : SRM_PLRASP_SOUTH;
    api_srf.origin_longitude=0.0;
    api_srf.central_scale=0.994;
    api_srf.false_easting=2000000.0;
    api_srf.false_northing=2000000.0;

    return Impl_allocsrfPOLAR_STEREOGRAPHIC(orm, rt,&api_srf);
}


void *Impl_allocsrfUNIV_TRANS_MERC
(
    SRM_SRFS_Code_Info srfs_code_info,
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt
)
{
    SRM_TM_Parameters api_srf;

    api_srf.origin_latitude= 0.0*SRM_RADIANS_PER_DEGREE;

    if(((SRM_Integer) srfs_code_info.value.srfsm_utm) <= 60 )
    {
        api_srf.origin_longitude=( (SRM_Long_Float)srfs_code_info.value.srfsm_utm * 6.0 - 183.0 )*SRM_RADIANS_PER_DEGREE ;
    }
    else
    {
        api_srf.origin_longitude=( (SRM_Long_Float)srfs_code_info.value.srfsm_utm * 6.0 - 543.0) *SRM_RADIANS_PER_DEGREE ;
    }
    api_srf.central_scale=0.9996;
    api_srf.false_easting=500000.0;
    api_srf.false_northing=((srfs_code_info.value.srfsm_utm<=60)? (0.0) : (10000000.0));
    return Impl_allocsrfTRANSVERSE_MERCATOR(orm,rt,&api_srf);
}


void* Impl_allocsrfWISCONSIN_SPCS
(
    SRM_SRFS_Code_Info srfs_code_info,
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt
)
{
  SRM_LCC_Parameters api_srf;
  api_srf.origin_longitude=-90.0*SRM_RADIANS_PER_DEGREE;
  api_srf.false_easting=600000.0;
  api_srf.false_northing=0.0;

  switch(srfs_code_info.value.srfsm_wisconsin_spcs)
    {
    case SRM_SRFSMWNSPCSCOD_SOUTH_ZONE:
      api_srf.origin_latitude=(42.0)                             *SRM_RADIANS_PER_DEGREE;
      api_srf.latitude1=(42.0+(44.0/60.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude2=(44.0+(4.0/60.0)) *SRM_RADIANS_PER_DEGREE;
      break;
    case SRM_SRFSMWNSPCSCOD_CENTRAL_ZONE:
      api_srf.origin_latitude=(43.0+(50.0/60.0))                 *SRM_RADIANS_PER_DEGREE;
      api_srf.latitude1=(44.0+(15.0/60.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude2=(45.0+(30.0/60.0))*SRM_RADIANS_PER_DEGREE;
      break;
    case SRM_SRFSMWNSPCSCOD_NORTH_ZONE:
      api_srf.origin_latitude=(45.0+(10.0/60.0))                 *SRM_RADIANS_PER_DEGREE;
      api_srf.latitude1=(45.0+(34.0/60.0))*SRM_RADIANS_PER_DEGREE;
      api_srf.latitude2=(46.0+(46.0/60.0))*SRM_RADIANS_PER_DEGREE;
      break;
    default:
      return 0;
    }
  return Impl_allocsrfLAMBERT_CONF_CONIC(orm,rt,&api_srf);
}


void *Impl_allocsrfJRPS
(
    SRM_SRFS_Code_Info srfs_code_info,
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt
)
{
    SRM_TM_Parameters api_srf;

    api_srf.central_scale= 0.9999;
    api_srf.false_easting= 0.0;
    api_srf.false_northing=0.0;

    switch(srfs_code_info.value.srfsm_japan_rectangular_plane_cs)
    {
        case SRM_SRFSMJPRPCSCOD_ZONE_I:
             api_srf.origin_longitude=(129.0+30.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (33.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_II:
             api_srf.origin_longitude=(131.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (33.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_III:
             api_srf.origin_longitude=(132.0+10.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (36.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_IV:
             api_srf.origin_longitude=(133.0+30.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (33.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_V:
             api_srf.origin_longitude=(134.0+20.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (36.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_VI:
             api_srf.origin_longitude=(136.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (36.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_VII:
             api_srf.origin_longitude=(137.0+10.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (36.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_VIII:
             api_srf.origin_longitude=(138.0+30.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (36.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_IX:
             api_srf.origin_longitude=(139.0+50.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (36.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_X:
             api_srf.origin_longitude=(140.0+50.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (40.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XI:
             api_srf.origin_longitude=(140.0+15.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (44.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XII:
             api_srf.origin_longitude=(142.0+15.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (44.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XIII:
             api_srf.origin_longitude=(144.0+15.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (44.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XIV:
             api_srf.origin_longitude=(142.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (26.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XV:
             api_srf.origin_longitude=(127.0+30.0/60.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (26.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XVI:
             api_srf.origin_longitude=(124.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (26.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XVII:
             api_srf.origin_longitude=(131.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (26.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XVIII:
             api_srf.origin_longitude=(136.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (20.0)*SRM_RADIANS_PER_DEGREE;
             break;
        case SRM_SRFSMJPRPCSCOD_ZONE_XIX:
             api_srf.origin_longitude=(154.0)*SRM_RADIANS_PER_DEGREE;
             api_srf.origin_latitude= (26.0)*SRM_RADIANS_PER_DEGREE;
             break;
        default:
             return 0;
    }
    return Impl_allocsrfTRANSVERSE_MERCATOR(orm,rt,&api_srf);
}

/*End of SRF set allocators*/



/*Functions to get the natural SRF member*/

SRM_Integer
Impl_naturalSetMemberNULL_SRFS(Impl_Private_Data pdat, SRM_Long_Float coordinate[3])
{
    return (SRM_Integer)-1;
}


SRM_Integer
Impl_naturalSetMemberALABAMA_SPCS(Impl_Private_Data pdat, SRM_Long_Float coordinate[3])
{
  return (SRM_Integer)-1;
}

SRM_Integer
Impl_naturalSetMemberGTRS_GLOB_COORD_SYS(Impl_Private_Data pdat, SRM_Long_Float coordinate[3])
{
    return Impl_GTRS_NaturalCell(coordinate);
}

SRM_Integer
Impl_naturalSetMemberLAMBERT_NTF(Impl_Private_Data pdat,  SRM_Long_Float coordinate[3])
{
    return (SRM_Integer)-1;
}

SRM_Integer
Impl_naturalSetMemberUNIV_POLAR_STEREOG
(
    Impl_Private_Data pdat,
    SRM_Long_Float    coordinate[3]
)
{
    if (coordinate[1] >= 83.5*SRM_RADIANS_PER_DEGREE)
    {
        return (SRM_Integer)SRM_SRFSMUPSCOD_NORTHERN_POLE;
    }
    else if(coordinate[1] <= -79.5*SRM_RADIANS_PER_DEGREE)
    {
        return (SRM_Integer)SRM_SRFSMUPSCOD_SOUTHERN_POLE;
    }
    else
        return 0; /* Nether Region */
}

SRM_Integer
Impl_naturalSetMemberUNIV_TRANS_MERC
(
    Impl_Private_Data pdat,
    SRM_Long_Float    coordinate[3]
)
{
    SRM_Integer zone;

  /*This test must be kept consistent with the one in Impl_validcoord3D_UTMC_cd*/
    if ((Impl_validcoord3DCELESTIODETIC(pdat,coordinate) & IMPL_BADSTAT) ||
        (coordinate[1] > 84.5 * SRM_RADIANS_PER_DEGREE) ||
        (coordinate[1] < -80.5* SRM_RADIANS_PER_DEGREE)
        )
    {
        zone=0;  /*Nether Region*/
      /*
        At some point the nether region should probably be detected by the actual
        UTMC CD validation routine and not this little snippet
      */
    }
    else
    {
        SRM_Long_Float fl_zone;

        GET_UTM_ZONE(coordinate[0],&fl_zone);
        if (coordinate[1]<0.0)
        {
            fl_zone+=60;
        }
        zone=static_cast<int>(fl_zone);
    }
    return zone;
}

SRM_Integer
Impl_naturalSetMemberWISCONSIN_SPCS( Impl_Private_Data pdat,SRM_Long_Float coordinate[3])
{
    return (SRM_Integer)-1;
}

SRM_Integer
Impl_naturalSetMemberJRPS( Impl_Private_Data pdat,SRM_Long_Float coordinate[3])
{
    return (SRM_Integer)-1;
}



/*!<An array of functions that returns the natural set member for a given SRF.
   \returns -1 if unimplemented.
   \returns 0 if there is no valid representation of the given coordinate (IMPL_INVALID)
   \returns zone if implemented
*/


/*Template Code Functions: Needed 1 per SRF set
 * These functions return the template code of a given SRF set
 * A function must be added to the array below each time an
 * SRF set is added to the API.
 */

extern SRM_SRFT_Code Impl_templcodeNULL_SRFS()
{
    return 0;
}

SRM_SRFT_Code Impl_templcodeALABAMA_SPCS()
{
    return SRM_SRFTCOD_TRANSVERSE_MERCATOR;
}
SRM_SRFT_Code Impl_templcodeGTRS_GLOB_COORD_SYS()
{
    return SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN;
}
SRM_SRFT_Code Impl_templcodeLAMBERT_NTF()
{
    return SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC;
}
SRM_SRFT_Code Impl_templcodeUNIV_POLAR_STEREOG()
{
    return SRM_SRFTCOD_POLAR_STEREOGRAPHIC;
}
SRM_SRFT_Code Impl_templcodeUNIV_TRANS_MERC()
{
    return SRM_SRFTCOD_TRANSVERSE_MERCATOR;
}
SRM_SRFT_Code Impl_templcodeWISCONSIN_SPCS()
{
    return SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC;
}
SRM_SRFT_Code Impl_templcodeJRPS()
{
    return SRM_SRFTCOD_TRANSVERSE_MERCATOR;
}
