/*
 * SRM API
 *
 * FILE       : srm.h
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION: Provides reusable functions for conversions between
 *              various SRFs.
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 * - SRM spec. 4.1
 *
 *
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
 *
 *
 *
 *
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 *
 */

/** @file   srm.h
    @author (SAIC)
    @brief  A File to include all other include files.
*/

/*
 * For other release dates/detailed changes, contact SAIC.
 */

/** @mainpage Spatial Reference Model (SRM) C API
@section Introduction
This is the documentation for the SRM C API.

The SRM C API provides the following functionality:
- Creation
  - SRFs
    - SRF templates (e.g., LSR 3D, TM, Celestiondetic, Celestiocentric)
    - SRF set members (e.g., UTM zone 12, GTRS cell 1234, UPS northern pole)
    - SRFs (e.g., British National Grid)
  - Coordinates
    - 2D coordinate
    - 3D coordinate
    - Surface coordinate
  - Directions
  - Orientations
- Conversion
  - Coordinate conversion between SRFs
  - Direction conversion between SRFs
  - Orientation conversion between SRFs
- Validation
  - Coordinate validation within a SRF
  - Direction validation within a SRF
  - Orientation validation within a SRF
- Calculations
  - Euclidean distance
  - Geodesic distance
  - Point scale
  - Vertical separation offset
  - Convergence of the Meridian
  - Map azimuth
- Abstract space coordinate instancing in a SRF

A sample program to convert a Celestiodetic 3D coordinate to
a Celestiocentric 3D coordinate is as follows:
@code
#include <stdio.h>
#include <string.h>

#include "srm.h"


int main
(
    int   argc,
    char *argv[]
)
{
    SRM_Coordinate_Valid_Region val_region;

    SRM_Celestiocentric cc_srf;
    SRM_Celestiodetic   cd_srf;
    SRM_Coordinate3D    cc_coord;
    SRM_Coordinate3D    cd_coord;
    SRM_Long_Float      ord1,ord2,ord3;

    printf( "Running SRM Sample test program...\n" );

    if (SRM_CD_Create(SRM_ORMCOD_WGS_1984,
                      SRM_RTCOD_WGS_1984_IDENTITY,
                      &cd_srf) != SRM_STATCOD_SUCCESS)
        fprintf( stderr, "Failed to create CD SRF\n" );
    else
    {
        if (SRM_CC_Create(SRM_ORMCOD_WGS_1984,
                          SRM_RTCOD_WGS_1984_IDENTITY,
                          &cc_srf ) != SRM_STATCOD_SUCCESS )
            fprintf( stderr, "Failed to create CC SRF\n" );
        else
        {
            if ( cd_srf.methods->CreateCoordinate3D( &cd_srf,
                                                    0.0,
                                                    0.785398163397,
                                                    0.0,
                                                   &cd_coord ) != SRM_STATCOD_SUCCESS )
                fprintf( stderr, "Failed to create CD coordinate\n" );
            else
            {
                if ( cc_srf.methods->CreateCoordinate3D( &cc_srf,
                                                        0.0,
                                                        0.0,
                                                        0.0,
                                                        &cc_coord ) != SRM_STATCOD_SUCCESS )
                    fprintf( stderr, "Failed to create CC coordinate\n" );
                else
                {
                    if ( cc_srf.methods->ChangeCoordinate3DSRF( &cc_srf,
                                                                &cd_srf,
                                                                &cd_coord,
                                                                &cc_coord,
                                                                &val_region)
                         != SRM_STATCOD_SUCCESS )
                        fprintf( stderr, "SRM_ChangeCoordinateSRF failed\n" );
                    else
                    {
                        if ( cc_srf.methods->GetCoordinate3DValues( &cc_srf,
                                                                    &cc_coord,
                                                                    &ord1,
                                                                    &ord2,
                                                                    &ord3 ) != SRM_STATCOD_SUCCESS )
                            fprintf( stderr, "Failed getting the CC coordinate values\n" );

                        else
                            printf("[ %lf, %lf, %lf ]\n\n", ord1, ord2, ord3 );
                    }
                    cc_srf.methods->DestroyCoordinate3D(&cc_srf,
                                                        &cc_coord);
                }
                cd_srf.methods->DestroyCoordinate3D(&cd_srf,
                                                    &cd_coord);
            }
            cc_srf.methods->Destroy(&cc_srf);
        }
        cd_srf.methods->Destroy(&cd_srf);
    }
    return 0;
}
@endcode

Running the sample program above will produce the output as follows:
@verbatim
Running SRM Sample test program...
[ 4517590.878846, 0.000000, 4487348.408859 ]
@endverbatim
*/

/*
 * Ensure that the SRM API is only included once.
 */
#ifndef _SRM_H_INCLUDED
#define _SRM_H_INCLUDED

#if !defined(_WIN32)
#define EXPORT_DLL
#elif !defined(EXPORT_DLL)
#if defined(_LIB)
#define EXPORT_DLL
#elif defined(_USRDLL)
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#endif /* _WIN32 && EXPORT_DLL */

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "srm_types.h"
#include "srm_print.h"
#include "srm_util.h"
#include "srm_valid.h"
#include "srm_default.h"
#include "srm_struct_util.h"
#include "srm_BaseSRF.h"
#include "srm_Coordinate2D.h"
#include "srm_Coordinate3D.h"
#include "srm_SurfaceCoordinate.h"
#include "srm_Orientation.h"
#include "srm_Direction.h"
#include "srm_BaseSRF3D.h"
#include "srm_BaseSRF2D.h"
#include "srm_BaseMapProjection.h"
#include "srm_BaseSRFwithTangentPlaneSurface.h"
#include "srm_LocalTangentSpaceEuclidean.h"
#include "srm_BaseSRFwithEllipsoidalHeight.h"
#include "srm_CreateStandardSRF.h"
#include "srm_CreateSRFSetMember.h"
#include "srm_Celestiomagnetic.h"
#include "srm_Celestiodetic.h"
#include "srm_Celestiocentric.h"
#include "srm_TransverseMercator.h"
#include "srm_SolarMagneticEcliptic.h"
#include "srm_SolarMagneticDipole.h"
#include "srm_SolarEquatorial.h"
#include "srm_SolarEcliptic.h"
#include "srm_PolarStereographic.h"
#include "srm_Planetodetic.h"
#include "srm_QueryORMSupport.h"
#include "srm_QuerySRFTSupport.h"
#include "srm_ObliqueMercatorSpherical.h"
#include "srm_Mercator.h"
#include "srm_LocalTangentSpaceCylindrical.h"
#include "srm_LocalTangentSpaceAzimuthalSpherical.h"
#include "srm_LocalSpaceRectangular3D.h"
#include "srm_LococentricEuclidean3D.h"
#include "srm_LocalSpaceRectangular2D.h"
#include "srm_LocalSpacePolar.h"
#include "srm_LocalSpaceAzimuthal.h"
#include "srm_LambertConformalConic.h"
#include "srm_HeliosphericEarthEquatorial.h"
#include "srm_HeliosphericEarthEcliptic.h"
#include "srm_HeliosphericAriesEcliptic.h"
#include "srm_EquidistantCylindrical.h"
#include "srm_EquatorialInertial.h"

#ifdef __cplusplus
}
#endif

#endif
