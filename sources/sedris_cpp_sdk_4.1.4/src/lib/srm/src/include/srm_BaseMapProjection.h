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
#ifndef SRM_BASEMAPPROJECTION_H_INCLUDED
#define SRM_BASEMAPPROJECTION_H_INCLUDED

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

/** This is the ConvergenceOfMeridian.
    @param this_object in: this SRF object
    @param surface_coordinate in: surface coordinate
    @param gamma out: resulting convergence of the meridian
    @returns a status code
*/
typedef SRM_Status_Code SRM_ConvergenceOfTheMeridian
(
          SRM_Object_Reference   this_object,
    const SRM_SurfaceCoordinate *surface_coordinate,
          SRM_Long_Float        *gamma               /* OUT */
);


/** Gets the Extended Valid Geodetic Region for this SRF.  This is the Lat/Long Coordinates.
    @note Given a coordinate component, the last invocation of this
          method or the setValidGeodeticRegion method determines
          the valid and extended valid intervals of the coordinate
          component values.
    @param this_object in: this SRF object
    @param component_identifier in: the coordinate component (1, 2, or 3)
    @param interval_type out: the type of interval
    @param extendend_lower_bound out: the extended lower value of the interval
    @param lower_bound out: the lower value of the interval
    @param upper_bound out: the upper value of the interval
    @param extended_upper_bound out: the extended_upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetExtendedValidGeodeticRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component_identifier,
    SRM_Interval_Type    *interval_type,         /* OUT */
    SRM_Long_Float       *extended_lower_bound,  /* OUT */
    SRM_Long_Float       *lower_bound,           /* OUT */
    SRM_Long_Float       *upper_bound,           /* OUT */
    SRM_Long_Float       *extended_upper_bound   /* OUT */
);

/** Get the Valid Geodetic Region for this SRF.
     @note: Given a coordinate component, the last invocation of this
           method or the setExtendedValidGeodeticRegion method determines
           the valid and extended valid intervals of the coordinate
           component values.
    @param this_object in: this SRF object
    @param component_identifier in: the coordinate component (1 or 2)
    @param interval_type out: the type of the interval
    @param lower_bound out: the lower value of the interval
    @param upper_bound out: the upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetValidGeodeticRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component_identifier,
    SRM_Interval_Type    *interval_type,          /* OUT */
    SRM_Long_Float       *lower_bound,            /* OUT */
    SRM_Long_Float       *upper_bound             /* OUT */
);

/** This is the MapAzimith for the SRF
    @note What is Azimith
    @param this_object in: this SRF object
    @param point1_coordinate in: surface coordinate
    @param point2_coordinate in: target coordinate
    @param azimuth out: result is azimuth
    @returns a status code
*/
typedef SRM_Status_Code SRM_MapAzimuth
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *point1_coordinate,
  const SRM_SurfaceCoordinate *point2_coordinate,
        SRM_Long_Float        *azimuth              /* OUT */
);

/** Point Distortion for the SRF
    @note
    @param this_object in: this SRF object
    @param surface_coordinate in: surface coordinate
    @param distortion in: returning distortion
    @returns a status code
*/
typedef SRM_Status_Code SRM_PointDistortion
(
        SRM_Object_Reference   this_object,
  const SRM_SurfaceCoordinate *surface_coordinate,
        SRM_Long_Float        *distortion          /* OUT */
);

/** Set the Extended Valid Region for this SRF.
    @note Given a coordinate component, the last invocation of this
          method or the setValidRegion method determines
          the valid and extended valid intervals of the coordinate
          component values.
    @note Upper or Lower value is ignored if the interval is a
          semi-interval or unbounded.
    @note The Lower value must be strictly less than the Upper value.
    @note The Extended_Lower value must be strictly greater than the Lower value and
          the Extended_Upper value must be strictly smaller than the Lower value.
    @param this_object in: this SRF object
    @param component_identifier in: the coordinate component (1, 2, or 3)
    @param interval_type in: the type of interval
    @param extended_lower_bound in: the extended lower value of the interval
    @param lower_bound in: the lower value of the interval
    @param upper_bound in: the upper value of the interval
    @param extended_upper_bound in: the extended_upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetExtendedValidGeodeticRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component_identifier,
    SRM_Interval_Type     interval_type,
    SRM_Long_Float        extended_lower_bound,
    SRM_Long_Float        lower_bound,
    SRM_Long_Float        upper_bound,
    SRM_Long_Float        extended_upper_bound
);

/** Set the Valid Region for this SRF in geodetic coordinates (lon/lat).
    @note Given a coordinate component, the last invocation of this
          method or the setExtendedValidGeodeticRegion method determines
          the valid and extended valid intervals of the coordinate
          component values.
    @note Upper or Lower value is ignored if the interval is a
          semi-interval or unbounded.
    @note The Lower value must be strictly less than the Upper bound value.
    @param this_object in: this SRF object
    @param component_identifier in: the coordinate component (1 or 2)
    @param interval_type in: the type of interval
    @param lower_bound in: the lower bound value of the interval
    @param upper_bound in: the upper bound value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetValidGeodeticRegion
(
    SRM_Object_Reference this_object,
    SRM_Integer          component_identifier,
    SRM_Interval_Type    interval_type,
    SRM_Long_Float       lower_bound,
    SRM_Long_Float       upper_bound
);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef/define/endif for SRM_BASEMAPPROJECTION_H_INCLUDED */
