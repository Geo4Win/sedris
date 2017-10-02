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


#ifndef _IMPL_CALC_H
#define _IMPL_CALC_H

/*! 
  @file   impl_calc.h
  @author Cameron D. Kellough, SRI
*/
#include"impl_private.h"

//!This routine calculates convergence of the meridian as defined by ISO 18026 Clause 10.

/*!This routine calculates covnergence of the meridian as defined by
  ISO 18026 Clause 10.  COM is computed by using algorithms which take
  the same initalization information as coordinate conversions to
  celestiodetic.  This routine implements
  calculateConvergenceOfTheMeridian() : srm::BaseSRF_MapProjection.

  \remark  This operation is only valid for Surface Coordinates associated with map projections.
  The API shall ensure that only surface map coordinates are passed.

  \return IMPL_VALID    The Convergence of the Meridan Returned is good.
  \return IMPL_UNIMPLEM Convergence of the Meridian is unimplemented for that case
  \return IMPL_MEMALLOC Insufficient memory to perform the operation
  \return IMPL_SRFSRC   The source SRF was bad.
  \return IMPL_CRDORG   The coordinate for which COM was desired isn't valid

*/
Impl_Status 
Impl_calculateConvergenceOfTheMeridian(void*    srf_org,
				       /*!< (Input): \impl_ptr_org_def*/
				       const SRM_Long_Float  coord_org[2],
				       /*!< (Input): \impl_coord_org_def*/
				       SRM_Long_Float* com_value
				       /*!< (Output): The angle that a map grid line makes with
					 true north independent of the compass deviation.
					 COM is a property of the map projection, not the 
					 object being modeled with the ORM.
				       */
				       );



//! This routine calculates the shortest distance between two points using a euclidean metric

/*! This routine finds the distance between two points in space by converting the points
  to an orthonormal SRF and applying sqrt(delta_x^2 +delta_y^2 +delta_z^2).  It will accept
  any coordinates and SRF's that have ORM's for the same body.  Up to two implicit conversions
  may be required for it's operation.  This routine implements calculateEuclideanDistance() : srm::BaseSRF.
  \remark Both coordinates must be 3D.
  \remark Surface Coordinates are not allowed.
  \remark There is no need for the ORM's to be the same if they are for the same body.
  \remark This operation is associated with the origin srf as opposed
  to change coordinate which associates with the destination srf.

  \returns IMPL_VALID for valid Euclidean Distance
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF
  \returns IMPL_CRDORG for an invalid origin coordinate
  \returns IMPL_CRDDST for an invalid destination coordinate
  \returns IMPL_ILLEGL for points on different bodies


*/
Impl_Status 
Impl_calculateEuclideanDistance(void* srf_org,
				/*!< (Input): \impl_ptr_org_def*/
				const SRM_Long_Float coord_org[3],
				/*!< (Input): \impl_coord_org_def*/
				void* srf_dst,
				/*!< (Input): \impl_ptr_dst_def*/ 
				const SRM_Long_Float coord_dst[3],
				/*!< (Input): \impl_coord_dst_def*/
				SRM_Long_Float* euclidean_distance
				/*!< (Output): The distance between two locations 
				  using a euclidean distance metric based on
				  the distance between the points in an 
				  orthonormal space.  This routine will convert
				  coordinates to wgs84 celestiocentric 
				  if necessary to make the computation.
				*/
				);


//! This routine calculates the shortest distance between two points using a euclidean metric

/*! This routine finds the distance between two points in space by converting the points
  to an orthonormal SRF and applying sqrt(delta_x^2 +delta_y^2 +delta_z^2).  It will accept
  any coordinates and SRF's that have ORM's for the same body.  Up to two implicit conversions
  may be required for it's operation.  This routine implements calculateEuclideanDistance() : srm::BaseSRF.
  \remark Both coordinates must be Surface.
  \remark There is no need for the ORM's to be the same if they are for the same body.
  \remark This operation is associated with the origin srf as opposed
  to change coordinate which associates with the destination srf.

  \returns IMPL_VALID for valid Euclidean Distance
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF
  \returns IMPL_CRDORG for an invalid origin coordinate
  \returns IMPL_CRDDST for an invalid destination coordinate
  \returns IMPL_ILLEGL for points on different bodies


*/
Impl_Status 
Impl_calculateEuclideanDistanceSurface(void* srf_org,
				       /*!< (Input): \impl_ptr_org_def*/
				       const SRM_Long_Float coord_org[2],
				       /*!< (Input): \impl_coord_org_def*/
				       void* srf_dst,
				       /*!< (Input): \impl_ptr_dst_def*/ 
				       const SRM_Long_Float coord_dst[2],
				       /*!< (Input): \impl_coord_dst_def*/
				       SRM_Long_Float* euclidean_distance
				       /*!< (Output): The distance between two locations 
					 using a euclidean distance metric based on
					 the distance between the points in an 
					 orthonormal space.  This routine will convert
					 coordinates to wgs84 celestiocentric 
					 if necessary to make the computation.
				       */
				       );


//! This routine calculates the shortest distance between two points using a euclidean metric

/*! This routine finds the distance between two points in space by converting the points
  to an orthonormal SRF and applying sqrt(delta_x^2 +delta_y^2 +delta_z^2).  It will accept
  any coordinates and SRF's that have ORM's for the same body.  Up to two implicit conversions
  may be required for it's operation.  This routine implements calculateEuclideanDistance() : srm::BaseSRF.
  \remark Both coordinates must be Surface.
  \remark There is no need for the ORM's to be the same if they are for the same body.
  \remark This operation is associated with the origin srf as opposed
  to change coordinate which associates with the destination srf.

  \returns IMPL_VALID for valid Euclidean Distance
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF
  \returns IMPL_CRDORG for an invalid origin coordinate
  \returns IMPL_CRDDST for an invalid destination coordinate
  \returns IMPL_ILLEGL for points on different bodies


*/
Impl_Status 
Impl_calculateEuclideanDistance2D(void* srf_org,
				  /*!< (Input): \impl_ptr_org_def*/
				  const SRM_Long_Float coord_org[2],
				  /*!< (Input): \impl_coord_org_def*/
				  void* srf_dst,
				  /*!< (Input): \impl_ptr_dst_def*/ 
				  const SRM_Long_Float coord_dst[2],
				  /*!< (Input): \impl_coord_dst_def*/
				  SRM_Long_Float* euclidean_distance
				  /*!< (Output): The distance between two locations 
				    using a euclidean distance metric based on
				    the distance between the points in an 
				    orthonormal space.  This routine will convert
				    coordinates to wgs84 celestiocentric 
				    if necessary to make the computation.
				  */
				  );



//! This routine calculates the shortest distance between two points over the surface of an ellipsoid.

/*! The calculation is performed by numerically approximating the
  elliptic integral described by ISO 18026 Equation 10.50.  Up to two
  implicit conversions may be required to perform the operation.  This
  routine implements calculateGeodesicDistance() : srm::BaseSRF_WithEllipsoidalHeight.

  \remark Geodesic Distance is defined only for surface coordinates on
  the same body and ellipsoid.  The API shall ensure that only surface
  coordinates are passed.
  \remark This operation is associated with the origin srf as opposed
  to change coordiante which associates with the destination srf.




  \returns IMPL_VALID for valid Geodesic Distance
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF
  \returns IMPL_CRDORG for an invalid origin coordinate
  \returns IMPL_CRDDST for an invalid destination coordinate
  \returns IMPL_ILLEGL for points on different bodies or ellipsoids

*/

Impl_Status 
Impl_calculateGeodesicDistance(void*   srf_org,
			       /*!< \impl_ptr_org_def*/
			       const SRM_Long_Float  coord_org[2],
			       /*!< \impl_coord_org_def*/
			       void*    srf_dst,
			       /*!< \impl_ptr_dst_def*/  
			       const SRM_Long_Float  coord_dst[2],
			       /*!< \impl_coord_dst_def*/
			       SRM_Long_Float* geodesic_distance
			       /*!< The distance between two surface points on the
				 surface of an ellipsoid ORM.  Both coordinates
				 must be on the same ORM but not necessarily the same SRF.
				 This routine will convert the coordinates to wgs84 
				 celestiodetic if necessary to make the computation*/
			       );

//! This routine calculates the map azimuth between two points.

/*! This routine calculates the azimuth from \a coord_org to \a
  coord_dst under the srf specified for \a srf_org.  This formulation
  allows the map azimuth between origin and destination on two
  different maps to be computed directly with respect to \a srf_org
  thus this routine may generate an implicit conversion.  This routine
  implements calculateMapAzimuth() : srm::BaseSRF_MapProjection.

  \remark Map azimuth is a function of surface coordinates only.
  \remark Map azimuth between two points is defined as long as \a
  srf_org and \a srf_dst are for the same body and ellipsoid and \a srf_org is a map SRF.


  \returns IMPL_VALID for valid Map Azimuth
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF
  \returns IMPL_CRDORG for an invalid origin coordinate
  \returns IMPL_CRDDST for an invalid destination coordinate
  \returns IMPL_ILLEGL for points on different bodies


*/
Impl_Status 
Impl_calculateMapAzimuth(void*    srf,
			 /*!< (Input):\impl_ptr_org_def*/
			 const SRM_Long_Float  coord_org[2],
			 /*!< (Input): \impl_ptr_dst_def*/  
			 const SRM_Long_Float  coord_dst[2],
			 /*!< (Input):\impl_coord_dst_def */
			 SRM_Long_Float* map_azimuth
			 /*!< (Output): The angle measured from a line drawn between 
			   the origin coordinate in the first SRF
			   and the representation of the location 
			   of the second coordinate in 
			   the first SRF to a map north south grid line.*/
			 );



//!This routine calculates the point scale for a given location on a Map SRF.
/*!This routine calculates the point scale for a given location on a
  Map SRF.  The routine will generate an implict conversion when used.
  This routine implements calculatePointScale() : srm::BaseSRF_MapProjection

\remark This operation is defined only for surface map coordinates and
it is the responsiblity of the API to ensure that only surface map
coordinates are passed.
\remark This operation is associated with the origin srf as opposed
  to change coordiante which associates with the destination srf.

\returns IMPL_VALID for valid Point Scale
\returns IMPL_MEMALLOC on out of memory
\returns IMPL_SRFSRC for a bad source SRF
\returns IMPL_CRDORG for an invalid origin coordinate


*/
Impl_Status 
Impl_calculatePointScale(void*         srf_org,
			 /*!< (Input): \impl_ptr_org_def*/
			 const SRM_Long_Float  coord_org[2],
			 /*!< (Input): \impl_coord_org_def*/
			 SRM_Long_Float* point_scale
			 /*!< (Output): The ratio of the distance represented 
			   on a  map to the distance represented on 
			   the ground for a differentially small distance 
			   at a given geometic point*/
			 );

//!This routine calculates the offset between the ellipsoid and a Vertical Offset Surface.

/*!This routine calculates the offset between the ellipsoid and a
  Vertical Offset Surface.  Currently, only the WGS84 Geoid offset is
  supported.  This routine implements
  calculateVerticalSeparationOffset():  srm::BaseSRF_WithEllipsoidalHeight.

  \remark The API shall ensure that only Surface coordinates are passed to this routine.
  \note  API is assumed to have checked the vos code
  
  \returns IMPL_VALID for valid Vertical Offset
  \returns IMPL_UNIMPLEM for unimplemented Vertical Offset Model
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_CRDORG for an invalid origin coordinate
  
*/
Impl_Status
Impl_calculateVerticalSeparationOffset(void*                    srf_org,
				       /*!< (Input): \impl_ptr_org_def*/
				       const SRM_Long_Float                   coord_org[2],
				       /*!< (Input): \impl_coord_org_def*/
				       SRM_DSS_Code vos_code,
				       /*!< (Input): ISO18026 Compliant Vertical Offset Surface Code*/
				       SRM_Long_Float*                  vertical_offset
				       /*!< (Output): The signed difference in ellipsoidal height at 
					 a given point between the ORM and measured
					 data. Example: The difference between the WGS84
					 Ellipsoid and the WGS84 Geoid derived from 
					 gravimetric measurements is one definition.*/
				       );


#endif

