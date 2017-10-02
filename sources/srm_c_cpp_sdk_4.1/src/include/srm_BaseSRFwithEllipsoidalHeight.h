/* SRM API
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
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
#ifndef SRM_BASESRFWITHELLIPSOIDALHEIGHT_H_INCLUDED
#define SRM_BASESRFWITHELLIPSOIDALHEIGHT_H_INCLUDED

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

#include "srm.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Associate Surface Coordinate
    @param this_object in: this SRF object
    @param coordinate in: surface coordinate
    @param on_surface_coordinate out: resulting in a surface coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_AssociateSurfaceCoordinateEH
(
        SRM_Object_Reference   this_object,
  const SRM_Coordinate3D      *coordinate,
        SRM_SurfaceCoordinate *on_surface_coordinate  /* OUT */
);

/** Creates a Local Tangent Space Euclidean SRF
    @param this_object in: this SRF object
    @param surface_coordinate in: SRF surface coordiante
    @param azimuth in: azimuth
    @param false_x_origin in: false x origin
    @param false_y_origin in: false y origin
    @param offset_height in: offset height
    @param local_tangent_Euclidean_srf out: this SRF object
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateLocalTangentSpaceEuclideanSRF
(
        SRM_Object_Reference            this_object,
  const SRM_SurfaceCoordinate          *surface_coordinate,
        SRM_Long_Float                  azimuth,
        SRM_Long_Float                  false_x_origin,
        SRM_Long_Float                  false_y_origin,
        SRM_Long_Float                  offset_height,
        SRM_LocalTangentSpaceEuclidean *local_tangent_Euclidean_srf  /* OUT */
);

/** Creates a Ellipsoidal Height surface coordinate object.
    @param this_object in: this SRF object
    @param first_coordinate_component in: this is the first coordinate of the two
    @param second_coordinate_component in: second coordinate
    @param new_coordinate out: resulting in a new coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateSurfaceCoordinateEH
(
    SRM_Object_Reference   this_object,
    SRM_Long_Float         first_coordinate_component,
    SRM_Long_Float         second_coordinate_component,
    SRM_SurfaceCoordinate *new_coordinate               /* OUT */
);

/** Destroys the  Ellipsoidal Height surface coordinate
    @param this_object in: this SRF object
    @param coordinate in: coordinate to be destroyed
    @returns a status code
*/
typedef SRM_Status_Code SRM_DestroySurfaceCoordinateEH
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference coordinate
);

/** This is the Euclidean Distance Ellipsoidal Height
    @param this_object in: this SRF object
    @param point1_coordinate in: Ellposoidal Height surface coordinate
    @param point2_coordinate in: Ellposoidal Height target surface coordinate
    @param distance out: resulting in the distance between the two points
    @returns a status code
*/
typedef SRM_Status_Code SRM_EuclideanDistanceEH
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *point1_coordinate,
  const SRM_SurfaceCoordinate *point2_coordinate,
        SRM_Long_Float        *distance           /* OUT */
);

/** This is the Geodesic Distance
    @param this_object in: this SRF object
    @param point1_coordinate in: Geodesic Distance surface coordinate
    @param point2_coordinate in: Geodesic Distance target surface coordinate
    @param distance out: resulting in the distance between the two points
    @returns a status code
*/
typedef SRM_Status_Code SRM_GeodesicDistance
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *point1_coordinate,
  const SRM_SurfaceCoordinate *point2_coordinate,
        SRM_Long_Float        *distance           /* OUT */
);

/** Retrieves the Surface Coordinate values for Ellipsoidal Height
    @param this_object in: this SRF object
    @param coordinate in: surface coordinate
    @param first_coordinate_component out: this is the first coordinate component
    @param second_coordinate_component out: this is the second coordinate component
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetSurfaceCoordinateValuesEH
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *coordinate,
        SRM_Long_Float        *first_coordinate_component,  /* OUT */
        SRM_Long_Float        *second_coordinate_component  /* OUT */
);

/** This is a 3D coordinate representing the same location as specified
    by a surface coordinate.
    @param this_object in: this SRF object
    @param surface_coordinate in: this is the surface coordinate
    @param coordinate out: this is the 3D new coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_PromoteSurfaceCoordinateEH
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *surface_coordinate,
        SRM_Coordinate3D      *coordinate          /* OUT */
);

/** Returns the Vertical Offset  (in metres) at a position.
    @param this_object in: this SRF object
    @param dss_code in: this is the vertical offset
    @param surface_coordinate in: surface coordinate for the object
    @param separation out: resulting in the separation for the object
    @returns a status code
*/
typedef SRM_Status_Code SRM_VerticalOffset
(
        SRM_Object_Reference   this_object,
        SRM_DSS_Code           dss_code,
  const SRM_SurfaceCoordinate *surface_coordinate,
        SRM_Long_Float        *separation          /* OUT */
);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef/define/endif for SRM_BASESRFWITHELLIPSOIDALHEIGHT_H_INCLUDED */
