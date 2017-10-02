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
#ifndef SRM_BASESRFWITHTANGENTPLANESURFACE_H_INCLUDED
#define SRM_BASESRFWITHTANGENTPLANESURFACE_H_INCLUDED

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

/** This is the Associate Surface Coordinate for Tangent Place Surface
    @param this_object in: this SRF object
    @param coordinate in: surface coordinate
    @param on_surface_coordinate out: resulting in a surface coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_AssociateSurfaceCoordinateTPS
(
        SRM_Object_Reference   this_object,
  const SRM_Coordinate3D      *coordinate,
        SRM_SurfaceCoordinate *on_surface_coordinate /* OUT */
);

/** This creates the Surface Coordinate for the Tangent Place Surface
    @param this_object in: this SRF object
    @param first_coordinate_component in: this is the first component
    @param second_coordinate_component in: this is the second component
    @param new_coordinate out: resulting in a new tangent plane coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateSurfaceCoordinateTPS
(
    SRM_Object_Reference   this_object,
    SRM_Long_Float         first_coordinate_component,
    SRM_Long_Float         second_coordinate_component,
    SRM_SurfaceCoordinate *new_coordinate               /* OUT */
);

/** This destroys the Tangent Place Surface coordinate
    @param this_object in: this SRF object
    @param coordinate in: coordinate to be destroyed
    @returns a status code
*/
typedef SRM_Status_Code SRM_DestroySurfaceCoordinateTPS
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference coordinate
);

/** This is the Euclidean Distance for the Tangent Plane Surface
    @param this_object in: this SRF object
    @param point1_coordinate in: surface coordinate for the source
    @param point2_coordinate in: surface coordinate for the target
    @param distance out: distance between the two coordinates
    @returns a status code
*/
typedef SRM_Status_Code SRM_EuclideanDistanceTPS
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *point1_coordinate,
  const SRM_SurfaceCoordinate *point2_coordinate,
        SRM_Long_Float        *distance           /* OUT */
);

/** This gets the Surface Coordinate values for the Tangent Place Surface
    @param this_object in: th SRF object
    @param point1_coordinate in: surface coordinate for the source
    @param point2_coordinate in: surface coordinate for the target
    @param distance out: distance between the two coordinates
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetSurfaceCoordinateValuesTPS
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *coordinate,
        SRM_Long_Float        *first_coordinate_component,  /* OUT */
        SRM_Long_Float        *second_coordinate_component  /* OUT */
);

/** This is the Promote Surface Coordinate for the Tangent Place Surface
    @param this_object in: this SRF object
    @param surface_coordinate in: surface coordinate for the source
    @param point2_coordinate in: surface coordinate for the target
    @param coordinate out: resulting in a coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_PromoteSurfaceCoordinateTPS
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *surface_coordinate,
        SRM_Coordinate3D      *coordinate          /* OUT */
);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef/define/endif for SRM_BASESRFWITHTANGENTPLANESURFACE_H_INCLUDED */
