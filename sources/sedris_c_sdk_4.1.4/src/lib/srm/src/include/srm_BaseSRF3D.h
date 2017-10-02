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
#ifndef SRM_BASESRF3D_H_INCLUDED
#define SRM_BASESRF3D_H_INCLUDED

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

/** Changes a coordinate's values to this SRF.
    @note The destination coordinate must have been created using this SRF.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_coordinate in: this is the source coordinate
    @param target_coordinate out: this is the target coordinate
    @param region out: valid region for target coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate3DSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Coordinate3D            *source_coordinate,
          SRM_Coordinate3D            *target_coordinate, /* OUT */
          SRM_Coordinate_Valid_Region *region             /* OUT */
);

/** Changes a coordinate's values to this SRF using tranformation object.
    @note The destination coordinate must have been created using this SRF.
    @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
    @note The value of delta_s for hst must be stricly greater than -1.0.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_coordinate in: the source coordinate in some other SRF
    @param h_st in: ORM 3D transformation
    @param target_coordinate out: the destination coordinate in this SRF
    @param region out: valid region for destination coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate3DSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate3D                     *source_coordinate,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Coordinate3D                     *target_coordinate, /* OUT */
          SRM_Coordinate_Valid_Region          *region             /* OUT */
);


/** Changes an array of coordinate values to this SRF using tranformation object.
    @note The destination coordinates must have been created using this SRF.
    @note The source and destination arrays must be of same size.
    @note All the coordinates in an array must be associated with the same SRF.
    @param this_object in: this SRF object
    @param source_srf in: this is the surface SRF
    @param source_coordinate_array in: the array of source coordinates in some other SRF
    @param target_coordinate out: the array of destination coordinate in this SRF
    @param index out: the number of elements in the arrays
    @param region_array out: the valid regions associated with the destination coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate3DArraySRF
(
          SRM_Object_Reference               this_object,
    const SRM_Object_Reference               source_srf,
    const SRM_Coordinate3D_Array            *source_coordinate_array,
          SRM_Coordinate3D_Array            *target_coordinate_array, /* OUT */
          SRM_Integer_Positive              *index,                   /* OUT */
          SRM_Coordinate_Valid_Region_Array *region_array             /* OUT */
);

/** Changes an array of coordinate values to this SRF using tranformation object.
    @note The destination coordinates must have been created using this SRF.
    @note The source and destination arrays must be of same size.
    @note All the coordinates in an array must be associated with the same SRF.
    @param this_object in: this SRF object
    @param source_srf in: the array of source SRF
    @param h_st in: ORM 3D transformation
    @param target_coordinate_array out: the array of destination coordinate in this SRF
    @param index out: the number of elements in the arrays
    @param region_array out: the valid regions associated with the destination coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeCoordinate3DArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate3D_Array               *source_coordinate_array,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Coordinate3D_Array               *target_coordinate_array, /* OUT */
          SRM_Integer_Positive                 *index,                   /* OUT */
          SRM_Coordinate_Valid_Region_Array    *region_array             /* OUT */
);

/** Changes a direction's values to this SRF.
    @note The destination direction must have been created using this SRF.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_direction in: the source direction in some other SRF
    @param target_direction out: the destination direction in this SRF
    @param ref_coord_region out: reference coordinate region
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeDirectionSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Direction               *source_direction,
          SRM_Direction               *target_direction, /* OUT */
          SRM_Coordinate_Valid_Region *ref_coord_region  /* OUT */
);

/** Changes a direction's values to this SRF using tranformation object.
    @note The destination direction must have been created using this SRF.
    @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
    @note The value of delta_s for hst must be stricly greater than -1.0.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_direction in: the source direction in some other SRF
    @param h_st in: ORM 3D transformation
    @param target_direction out: the destination direction in this SRF
    @param ref_coord_region out: reference coordinate region
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeDirectionSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Direction                        *source_direction,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Direction                        *target_direction, /* OUT */
          SRM_Coordinate_Valid_Region          *ref_coord_region  /* OUT */
);

/** Changes a direction's values to this SRF using tranformation object.
    @note The destination direction must have been created using this SRF.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_direction_array in: the array of source direction in some other SRF
    @param target_direction_array out: the array of destination direction in this SRF
    @param index out: the number of elements in the arrays
    @param ref_coord_region_array out: reference coordinate region array
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeDirectionArraySRF
(
          SRM_Object_Reference               this_object,
    const SRM_Object_Reference               source_srf,
    const SRM_Direction_Array               *source_direction_array,
          SRM_Direction_Array               *target_direction_array, /* OUT */
          SRM_Integer_Positive              *index,                  /* OUT */
          SRM_Coordinate_Valid_Region_Array *ref_coord_region_array  /* OUT */
);

/** Changes a direction's values to this SRF using tranformation object.
    @note The destination direction must have been created using this SRF.
    @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
    @note The value of delta_s for hst must be stricly greater than -1.0.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_direction_array in: the source direction in some other SRF
    @param h_st in: ORM 3D transformation
    @param target_direction out: the destination direction in this SRF
    @param index out: the number of elements in the arrays
    @param ref_coord_region out: reference coordinate region array
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeDirectionArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Direction_Array                  *source_direction_array,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Direction_Array                  *target_direction_array, /* OUT */
          SRM_Integer_Positive                 *index,                  /* OUT */
          SRM_Coordinate_Valid_Region_Array    *ref_coord_region_array  /* OUT */
);

/** Creates a 3D coordinate object.
    @param this_object in: this SRF object
    @param first_coordinate_component in: creates the first of the three components
    @param second_coordinate_component in: creates the second of the three components
    @param third_coordinate_component in: creates the third of the three components
    @param new_coordinate out: new coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateCoordinate3D
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Long_Float        third_coordinate_component,
    SRM_Coordinate3D     *new_coordinate              /* OUT */
);

/** Creates a Orientation object.
    @param this_object in: this SRF object
    @param reference_coordinate in: reference coordinate
    @param matrix: 3x3 matrix
    @param new_orientation out: results in new orientation
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateOrientation
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *reference_coordinate,
          SRM_Matrix_3x3        matrix,
          SRM_Orientation      *new_orientation      /* OUT */
);

/** Creates a Direction object.
    @param this_object in: this SRF object
    @param reference_coordinate in: this is the surface coordinate
    @param first_direction_component in: creates first direction component
    @param second_direction_component in: creates second direction component
    @param third_direction_component in: creates third direction component
    @param new_direction out: results the new direction
    @returns a status code
*/
typedef SRM_Status_Code SRM_CreateDirection
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *reference_coordinate,
          SRM_Long_Float        first_direction_component,
          SRM_Long_Float        second_direction_component,
          SRM_Long_Float        third_direction_component,
          SRM_Direction        *new_direction              /* OUT */
);


/** Changes a Orientation's values to this SRF.
    @note The destination orientation must have been created using this SRF.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_orientation in: the source orientation in some other SRF
    @param target_orientation out: the destination orientation in this SRF
    @param ref_coord_region out: reference coordinate region
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeOrientationSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Orientation             *source_orientation,
          SRM_Orientation             *target_orientation, /* OUT */
          SRM_Coordinate_Valid_Region *ref_coord_region    /* OUT */
);

/** Changes a Orientation's values to this SRF using tranformation object.
    @note The destination orientation must have been created using this SRF.
    @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
    @note The value of delta_s for hst must be stricly greater than -1.0.
    @param this_object in: this SRF object
    @param source_srf in: this source SRF
    @param source_orientation in: the source orientation in some other SRF
    @param h_st in: ORM 3D transformation
    @param target_orientation out: the destination orientation in this SRF
    @param ref_coord_region out: reference coordinate region
    @returns a status code
*/
typedef SRM_Status_Code SRM_ChangeOrientationSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Orientation                      *source_orientation,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Orientation                      *target_orientation, /* OUT */
          SRM_Coordinate_Valid_Region          *ref_coord_region    /* OUT */
);

/** Destroys the 3D Coordinate
    @param this_object in: this SRF object
    @param coordinate in: the 3D coordinate to be destroyed
*/
typedef SRM_Status_Code SRM_DestroyCoordinate3D
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference coordinate
);


/** Destroys direction
    @param this_object in: this SRF object
    @param direction in: the direction to be destroyed
*/
typedef SRM_Status_Code SRM_DestroyDirection
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference direction
);

/** Destroys orientation
    @param this_object in: this SRF object
    @param orientation in: the orientation to be destroyed
*/
typedef SRM_Status_Code SRM_DestroyOrientation
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference orientation
);


/** Euclidean Distance 3D
    @param this_object in: this SRF object
    @param point1_coordinate in: this is the surface coordinate
    @param point2_coordinate in: this is the target coordinate
    @param distance out:  distance between the two coordinates
    @returns a status code
*/
typedef SRM_Status_Code SRM_EuclideanDistance3D
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *point1_coordinate,
    const SRM_Coordinate3D     *point2_coordinate,
          SRM_Long_Float       *distance          /* OUT */
);

/** Retrieves the 3D coordinate component values.
    @param this_object in: this SRF object
    @param coordinate in: gets the 3D coordinate
    @param first_coordinate_component out: gets the first 3D coordinate
    @param second_coordinate_component out: gets the second 3D coordinate
    @param third_coordinate_component out:  gets the third 3D coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetCoordinate3DValues
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *coordinate,
          SRM_Long_Float       *first_coordinate_component,  /* OUT */
          SRM_Long_Float       *second_coordinate_component, /* OUT */
          SRM_Long_Float       *third_coordinate_component   /* OUT */
);

/** Retrieves the orientation component values.
    @param this_object in: this SRF object
    @param orientation in: gets orientation
    @param reference_coordinate out: results the reference coordinate
    @param matrix out: results in a 3 x 3 matrix
    @returns a status code
*/

typedef SRM_Status_Code SRM_GetOrientationValues
(
          SRM_Object_Reference  this_object,
    const SRM_Orientation      *orientation,
          SRM_Coordinate3D     *reference_coordinate, /* OUT */
          SRM_Matrix_3x3       *matrix                /* OUT */
);

/** Retrieves the direction component values.
    @param this_object in: this SRF object
    @param direction in: gets direction
    @param reference_coordinate out: results the reference coordinate
    @param first_direction_component out: first direction component
    @param second_direction_component out: second direction component
    @param third_direction_component out: third direction component
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetDirectionValues
(
          SRM_Object_Reference  this_object,
    const SRM_Direction        *direction,
          SRM_Coordinate3D     *reference_coordinate,       /* OUT */
          SRM_Long_Float       *first_direction_component,  /* OUT */
          SRM_Long_Float       *second_direction_component, /* OUT */
          SRM_Long_Float       *third_direction_component   /* OUT */
);


/** Get the Extended Valid Region for this SRF.
    @note Given a coordinate component, the last invocation of this
          method or the setValidRegion method determines
          the valid and extended valid intervals of the coordinate
          component values.
    @param this_object in: this SRF object
    @param component_identifier in: identifies the component
    @param interval_type out: the type of interval
    @param extended_lower_bound out: the extended lower value of the interval
    @param lower_bound out: the lower value of the interval
    @param upper_bound out: the upper value of the interval
    @param extended_upper_bound out: the extended_upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetExtendedValidRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component_identifier,
    SRM_Interval_Type    *interval_type,        /* OUT */
    SRM_Long_Float       *extended_lower_bound, /* OUT */
    SRM_Long_Float       *lower_bound,          /* OUT */
    SRM_Long_Float       *upper_bound,          /* OUT */
    SRM_Long_Float       *extended_upper_bound  /* OUT */
);


/** Get the Valid Region for this SRF.
    @note Given a coordinate component, the last invocation of this
          method or the setExtendedValidRegion method determines
          the valid and extended valid intervals of the coordinate
          component values.
    @param this_object in: this SRF object
    @param component_identifier in: identifies the component
    @param interval_type out: the type of interval
    @param lower_bound out: the lower value of the interval
    @param upper_bound out: the upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetValidRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component_identifier,
    SRM_Interval_Type    *interval_type,       /* OUT */
    SRM_Long_Float       *lower_bound,         /* OUT */
    SRM_Long_Float       *upper_bound          /* OUT */
);

/** Get the Natural Set Member Code
    @param this_object in: this SRF object
    @param source_coordinate in: this is the source coordinate
    @param orm_code in: orm code
    @param rt_code in: rt code
    @param target_srfs in:  this outputs the correct target srfs
    @param srfs_code_info out: results in set member
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetNaturalSRFSMemberCode
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *source_coordinate,
          SRM_ORM_Code          orm_code,
          SRM_RT_Code           rt_code,
          SRM_SRFS_Code         target_srfs,
          SRM_SRFS_Code_Info   *srfs_code_info     /* OUT */
);


/** Sets the 3D coordinate component values.
    @param this_object in: this SRF object
    @param coordinate in out: sets the 3D coordinate
    @param first_coordinate_component in: sets the first 3D coordinate
    @param second_coordinate_component in: sets the second 3D coordinate
    @param third_coordinate_component in:  sets the third 3D coordinate
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetCoordinate3DValues
(
    SRM_Object_Reference  this_object,
    SRM_Coordinate3D     *coordinate, /* IN / OUT */
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Long_Float        third_coordinate_component
);


/** Set the Extended Valid Region for this SRF.
    @note Given a coordinate component, the last invocation of this
          method or the setValidRegion method determines
          the valid and extended valid intervals of the coordinate
          component values.
    @note Upper or Lower value is ignored if the interval is a
          semi-interval or unbounded.
    @note The Lower value must be strictly less than the Upper value.
    @note The Extended_Lower value must be strictly greater than the Lower value
    and the Extended_Upper value must be strictly smaller than the Lower value.
    @param this_object in: this SRF object
    @param component_identifier in: identifies the component
    @param interval_type out: the type of interval
    @param extended_lower_bound out: the extended lower value of the interval
    @param lower_bound out: the lower value of the interval
    @param upper_bound out: the upper value of the interval
    @param extended_upper_bound out: the extended_upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetExtendedValidRegion
(
    SRM_Object_Reference this_object,
    SRM_Integer          component_identifier,
    SRM_Interval_Type    interval_type,
    SRM_Long_Float       extended_lower_bound,
    SRM_Long_Float       lower_bound,
    SRM_Long_Float       upper_bound,
    SRM_Long_Float       extended_upper_bound
);


/**Set the Valid Region for this SRF.
    @note Given a coordinate component, the last invocation of this
          method or the setExtendedValidRegion method determines
          the valid and extended valid intervals of the coordinate
          component values.
    @note Upper or Lower value is ignored if the interval is a
          semi-interval or unbounded.
    @note The Lower value must be strictly less than the Upper value.
    @param this_object in: this SRF object
    @param component_identifier in: identifies the component
    @param interval_type out: the type of interval
    @param lower_bound out: the lower value of the interval
    @param upper_bound out: the upper value of the interval
    @returns a status code
*/
typedef SRM_Status_Code SRM_SetValidRegion
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
#endif /* #ifndef/define/endif for SRM_BASESRF3D_H_INCLUDED */
