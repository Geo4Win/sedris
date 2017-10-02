/*!
  @file   impl_vos.cpp
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


#include "impl_alloc.h"
#include "impl_change.h"
#include "orm_rd_struct.h"
#include "impl_vos.h"
extern Impl_Status Impl_GetWGS84GeoidalSeparation
(
    const SRM_Long_Float  coord_org_wgs84_cd[3],
          SRM_Long_Float *GeoidalSeparation_ptr
);


Impl_Status Impl_calcDSS_EGM84_GEOID
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    Impl_Status status=IMPL_UNIMPLEM;

#if 0
    Impl_SRF_ptr my_srf_cd=NULL;
    SRM_Long_Float my_coord_org[3]={wgs84_cd_coord[0],wgs84_cd_coord[1],0.0};
    SRM_Long_Float coord_cd[3]={IMPL_NAN,IMPL_NAN,IMPL_NAN};

    status=Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIODETIC,
                                    SRM_ORMCOD_WGS_1984,
                                    SRM_RTCOD_WGS_1984_IDENTITY,
                                    0,
                                    (void**)&my_srf_cd);

    if(status!=IMPL_VALID)
    {
        Impl_releaseSRF((void**)&my_srf_cd);
        SIMPLIFY_STATUS(status);
        return status;
    }
    status=Impl_changeCoord3DSRF(srf_org,
                                 my_coord_org,
                                 (void*)my_srf_cd,
                                 coord_cd);

    if(status&IMPL_BADSTAT)
    {
        Impl_releaseSRF((void**)&my_srf_cd);
        SIMPLIFY_STATUS(status);
        return status;
    }
    status|=Impl_GetWGS84GeoidalSeparation(coord_cd,retval);
    status|= Impl_releaseSRF((void**)&my_srf_cd);

    Impl_releaseSRF((void**)&my_srf_cd);
    SIMPLIFY_STATUS(status);
#endif

    return status;
}

Impl_Status Impl_calcDSS_IGLD_1955
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    return IMPL_UNIMPLEM;
}
Impl_Status Impl_calcDSS_IGLD_1985
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    return IMPL_UNIMPLEM;
}
Impl_Status Impl_calcDSS_MSL
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    return IMPL_UNIMPLEM;
}
Impl_Status Impl_calcDSS_NAVD_1988
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    return IMPL_UNIMPLEM;
}
Impl_Status Impl_calcDSS_NGVD_1929
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    return IMPL_UNIMPLEM;
}
Impl_Status Impl_calcDSS_OSGM_2002
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    return IMPL_UNIMPLEM;
}
Impl_Status Impl_calcDSS_WGS84_ELLIPSOID
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    // This is always 0.0
    *retval = 0.0;

    return IMPL_VALID;
}


Impl_Status Impl_calcDSS_EGM96_GEOID
(
    Impl_SRF_ptr    srf_org,
    SRM_Long_Float  wgs84_cd_coord[3],
    SRM_Long_Float *retval
)
{
    Impl_Status status=0;
    Impl_SRF_ptr my_srf_cd=NULL;
    SRM_Long_Float my_coord_org[3]={wgs84_cd_coord[0],wgs84_cd_coord[1],0.0};
    SRM_Long_Float coord_cd[3]={IMPL_NAN,IMPL_NAN,IMPL_NAN};

    status=Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIODETIC,
                                    SRM_ORMCOD_WGS_1984,
                                    SRM_RTCOD_WGS_1984_IDENTITY,
                                    0,
                                    (void**)&my_srf_cd);

    if(status!=IMPL_VALID)
    {
        Impl_releaseSRF((void**)&my_srf_cd);
        SIMPLIFY_STATUS(status);
        return status;
    }
    status=Impl_changeCoord3DSRF(srf_org,my_coord_org,(void*)my_srf_cd,coord_cd);

    if(status&IMPL_BADSTAT)
    {
        Impl_releaseSRF((void**)&my_srf_cd);
        SIMPLIFY_STATUS(status);
        return status;
    }
    status|=Impl_GetWGS84GeoidalSeparation(my_coord_org,retval);
    status|= Impl_releaseSRF((void**)&my_srf_cd);

    Impl_releaseSRF((void**)&my_srf_cd);
    SIMPLIFY_STATUS(status);

    return status;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: Impl_GetWGS84GeoidalSeparation
 *
 *   Returns the height of the WGS84 geoid above or below the WGS84
 *   ellipsoid, at the specified geodetic coordinates, using a grid
 *   of height adjustments from the WGS84 EGM 96 gravity model 15 minute
 *   increment geoid offset table.
 *   ftp://164.214.2.65/pub/gig/gravity3/WW15MGH.Z
 *
 *----------------------------------------------------------------------------
 */
Impl_Status
Impl_GetWGS84GeoidalSeparation
(
    const SRM_Long_Float  coord_org_wgs84_cd[3],
          SRM_Long_Float *GeoidalSeparation_ptr
)
{
    SRM_Integer_Unsigned  Index,ScaleFactor,NumbGeoidCols,NumbGeoidRows;
    SRM_Long_Float DeltaX, DeltaY,
               ElevationSE, ElevationSW, ElevationNE, ElevationNW,
               OffsetX, OffsetY, PostX, PostY, UpperY, LowerY;
    Impl_Status status = IMPL_VALID;

    ScaleFactor = 4;
    NumbGeoidCols = 1441;
    NumbGeoidRows = 721;

    const SRM_Integer_Unsigned MaxTableIndex = (SRM_Integer_Unsigned)(sizeof(WGS84_GeoidSeparationTable)/sizeof(float)-1);

   /*
    *  Compute X and Y Offsets into Geoid Height Array.
    */
    if (coord_org_wgs84_cd[0] < 0.0)
    {
        OffsetX = (coord_org_wgs84_cd[0]*SRM_DEGREES_PER_RADIAN + 360.0)
                  * ScaleFactor;
    }
    else
    {
        OffsetX = coord_org_wgs84_cd[0]*SRM_DEGREES_PER_RADIAN* ScaleFactor;
    }

    OffsetY = (90.0 - coord_org_wgs84_cd[1]*SRM_DEGREES_PER_RADIAN)
              * ScaleFactor;

   /*
    *  Find Four Nearest Geoid Height Cells for specified Latitude, Longitude;
    *  Assumes that (0,0) of Geoid Height Array is at Northwest corner.
    */
    PostX = floor( OffsetX );
    if ((PostX + 1) == NumbGeoidCols)
        PostX--;
    PostY = floor( OffsetY );
    if ((PostY + 1) == NumbGeoidRows)
        PostY--;

    // compute NW and NE elevations
    Index = (SRM_Integer_Unsigned)(PostY * NumbGeoidCols + PostX);
    if( (Index > MaxTableIndex ) || (Index < 0 ) )
    {
      status= IMPL_INACTBLE;
      *GeoidalSeparation_ptr=IMPL_NAN;
      return status;
    }
    ElevationNW = WGS84_GeoidSeparationTable[Index];
    ElevationNE = WGS84_GeoidSeparationTable[Index+ 1];

    // compute SW and SE elevations
    Index = (SRM_Integer_Unsigned)((PostY + 1) * NumbGeoidCols + PostX);
    if( (Index > MaxTableIndex ) || (Index < 0 ) )
    {
      status= IMPL_INACTBLE;
      *GeoidalSeparation_ptr=IMPL_NAN;
      return status;
    }
    ElevationSW = WGS84_GeoidSeparationTable[Index];
    ElevationSE = WGS84_GeoidSeparationTable[ Index + 1 ];

   /*
    *  Perform Bi-Linear Interpolation to compute Height above Ellipsoid
    */
    DeltaX = OffsetX - PostX;
    DeltaY = OffsetY - PostY;

    UpperY = ElevationNW + DeltaX * ( ElevationNE - ElevationNW );
    LowerY = ElevationSW + DeltaX * ( ElevationSE - ElevationSW );

   *GeoidalSeparation_ptr = UpperY + DeltaY * ( LowerY - UpperY );

    return status;
} /* end SRM_GetWGS84GeoidalSeparation */



Impl_Status(*Impl_calcDSS[SRM_DSS_CODE_UBOUND+1])(Impl_SRF_ptr srf, SRM_Long_Float coord[3], SRM_Long_Float* retval)=
{
  0,
  Impl_calcDSS_EGM96_GEOID,
  Impl_calcDSS_IGLD_1955,
  Impl_calcDSS_IGLD_1985,
  Impl_calcDSS_MSL,
  Impl_calcDSS_NAVD_1988,
  Impl_calcDSS_NGVD_1929,
  Impl_calcDSS_OSGM_2002,
  Impl_calcDSS_WGS84_ELLIPSOID,
  Impl_calcDSS_EGM84_GEOID
};
