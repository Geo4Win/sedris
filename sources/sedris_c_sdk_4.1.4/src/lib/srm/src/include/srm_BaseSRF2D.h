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
#ifndef SRM_BASESRF2D_H_INCLUDED
#define SRM_BASESRF2D_H_INCLUDED

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

/** Changes an array of coordinate values to this SRF.
    @note The destination coordinates must have been created using this SRF.
    @note The source and destination arrays must be of same size.
    @note All the coordinates in an array must be associated with the same SRF.
    @note When an exception is raised, the index will be set to the offending coordinate.
    @param this_object in: this SRF object
    @param source_srf in: source SRF
    @param source_coordinate_array out: the array of source coordinates in some other SRF
    @param target_coordinate_array out: the array of destination coordinate in this SRF
    @param index in: the number of elements in the arrays
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate2DArraySRF
(
          SRM_Object_Reference    this_object,
    const SRM_Object_Reference    source_srf,
    const SRM_Coordinate2D_Array *source_coordinate_array,
          SRM_Coordinate2D_Array *target_coordinate_array, /* OUT */
          SRM_Integer_Positive   *index                    /* OUT */
);

/** Changes an array of coordinate values to this SRF using tranformation object.
    @note The destination coordinates must have been created using this SRF.
    @note The source and destination arrays must be of same size.
    @note All the coordinates in an array must be associated with the same SRF.
    @note When an exception is raised, the index will be set to the offending coordinate.
    @param this_object in: this SRF object
    @param source_srf in: source SRF
    @param source_coordinate_array in: the array of source coordinates in some other SRF.
    @param h_st in: 2D ORM four parameter transformation
    @param target_coordinate_array out: the array of destination coordinate in this SRF.
    @param index out: the number of elements in the arrays
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate2DArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate2D_Array               *source_coordinate_array,
    const SRM_ORM_Transformation_2D_Parameters *h_st,
          SRM_Coordinate2D_Array               *target_coordinate_array, /* OUT */
          SRM_Integer_Positive                 *index                    /* OUT */
);

/** Changes a coordinate's values to this SRF.
    @note The destination coordinate must have been created using this SRF.
    @param this_object in: this SRF object.
    @param source_srf in: source SRF.
    @param source_coordinate in: the source coordinate in some other SRF.
    @param target_coordinate out: the destination coordinate in this SRF
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate2DSRF
(
          SRM_Object_Reference  this_object,
    const SRM_Object_Reference  source_srf,
    const SRM_Coordinate2D     *source_coordinate,
          SRM_Coordinate2D     *target_coordinate  /* OUT */
);

/** Changes a coordinate's values to this SRF using tranformation object.
    @note The destination coordinate must have been created using this SRF.
    @note The value of omega for hst must be within the range ( -2_PI, 2_PI ).
    @note The value of delta_s for hst must be stricly greater than -1.0.
    @param this_object in: this SRF object.
    @param source_srf in: source SRF.
    @param surface_coordinate in: the source coordinate in some other SRF
    @param h_st in: 2D ORM transformation
    @param target_coordinate out: the destination coordinate in this SRF
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate2DSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate2D                     *source_coordinate,
    const SRM_ORM_Transformation_2D_Parameters *h_st,
          SRM_Coordinate2D                     *target_coordinate  /* OUT */
);

/** Creates a 2D coordinate object.
    @see freeCoordinate2D()
    @param this_object in: this SRF object
    @param first_coordinate_component in:  first component
    @param second_coordinate_component in: second component
    @param new_coordinate out: new coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateCoordinate2D
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Coordinate2D     *new_coordinate               /* OUT */
);

/** Destroys the 2D Coordinate
    @param this_object in: this SRF object
    @param coordinate in: destroy this coordinate
*/
typedef SRM_Status_Code SRM_DestroyCoordinate2D
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference coordinate
);

/** Euclidean Distance 2D
    @param this_object in: this SRF object
    @param surface_coordinate in: this is the surface coordinate
    @param target_coordinate in: this is the target coordinate
    @param distance out: outputs the distance
    @returns a status code
*/
typedef SRM_Status_Code SRM_EuclideanDistance2D
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate2D     *source_coordinate,
    const SRM_Coordinate2D     *target_coordinate,
          SRM_Long_Float       *distance           /* OUT */
);

/** Retrieves the 2D coordinate component values.
    @param this_object in: this SRF object
    @param coordinate in: 2D coordinate
    @param first_coordinate_component out: first coordinate
    @param second_coordinate_component out: second coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetCoordinate2DValues
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate2D     *coordinate,
          SRM_Long_Float       *first_coordinate_component,  /* OUT */
          SRM_Long_Float       *second_coordinate_component  /* OUT */
);

/** Sets the 2D coordinate component values.
    @param this_object in: this SRF object
    @param coordinate in out: 2D coordinate
    @param first_coordinate_component in: first coordinate
    @param second_coordinate_component in: second coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetCoordinate2DValues
(
    SRM_Object_Reference  this_object,
    SRM_Coordinate2D     *coordinate, /* IN / OUT */
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component
);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef/define/endif for SRM_BASESRF2D_H_INCLUDED */
