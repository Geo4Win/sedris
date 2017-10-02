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


#ifndef CIMPL_BASESRF3D_HPP_INCLUDED
#define CIMPL_BASESRF3D_HPP_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "srm.h"

#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

typedef void *SRM_Direction_Ptr ;
typedef void *SRM_Orientation_Ptr ;

SRM_Status_Code cimpl_SRM_ChangeCoordinate3DArraySRF
(
          SRM_Object_Reference               this_object,
    const SRM_Object_Reference               source_srf,
    const SRM_Coordinate3D_Array            *source_coordinate_array,
          SRM_Coordinate3D_Array            *target_coordinate_array, /* OUT */
          SRM_Integer_Positive              *index,               /* OUT */
          SRM_Coordinate_Valid_Region_Array *region_array         /* OUT */
);


SRM_Status_Code cimpl_SRM_ChangeCoordinate3DArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate3D_Array               *source_coordinate_array,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Coordinate3D_Array               *target_coordinate_array, /* OUT */
          SRM_Integer_Positive                 *index,               /* OUT */
          SRM_Coordinate_Valid_Region_Array    *region_array         /* OUT */
);


SRM_Status_Code cimpl_SRM_ChangeCoordinate3DSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Coordinate3D            *source_coordinate,
          SRM_Coordinate3D            *target_coordinate, /* OUT */
          SRM_Coordinate_Valid_Region *region             /* OUT */
);


SRM_Status_Code cimpl_SRM_ChangeCoordinate3DSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Coordinate3D                     *source_coordinate,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Coordinate3D                     *target_coordinate, /* OUT */
          SRM_Coordinate_Valid_Region          *region             /* OUT */
);

SRM_Status_Code cimpl_SRM_CreateOrientation
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *reference_coordinate,
          SRM_Matrix_3x3        matrix,
          SRM_Orientation      *new_orientation      /* OUT */
);

SRM_Status_Code cimpl_SRM_CreateDirection
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *reference_coordinate,
          SRM_Long_Float        first_direction_component,
          SRM_Long_Float        second_direction_component,
          SRM_Long_Float        third_direction_component,
          SRM_Direction        *new_direction              /* OUT */
);

SRM_Status_Code cimpl_SRM_ChangeDirectionArraySRF
(
          SRM_Object_Reference               this_object,
    const SRM_Object_Reference               source_srf,
    const SRM_Direction_Array               *source_direction_array,
          SRM_Direction_Array               *target_direction_array, /* OUT */
          SRM_Integer_Positive              *index,                  /* OUT */
          SRM_Coordinate_Valid_Region_Array *ref_coord_region_array  /* OUT */
);

SRM_Status_Code cimpl_SRM_ChangeDirectionArraySRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Direction_Array                  *source_direction_array,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Direction_Array                  *target_direction_array, /* OUT */
          SRM_Integer_Positive                 *index,                  /* OUT */
          SRM_Coordinate_Valid_Region_Array    *ref_coord_region_array  /* OUT */
);


SRM_Status_Code cimpl_SRM_ChangeDirectionSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Direction               *source_direction,
          SRM_Direction               *target_direction, /* OUT */
          SRM_Coordinate_Valid_Region *ref_coord_region  /* OUT */
);

SRM_Status_Code cimpl_SRM_ChangeDirectionSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Direction                        *source_direction,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Direction                        *target_direction, /* OUT */
          SRM_Coordinate_Valid_Region          *ref_coord_region  /* OUT */
);


SRM_Status_Code cimpl_SRM_ChangeOrientationSRF
(
          SRM_Object_Reference         this_object,
    const SRM_Object_Reference         source_srf,
    const SRM_Orientation             *source_orientation,
          SRM_Orientation             *target_orientation, /* OUT */
          SRM_Coordinate_Valid_Region *ref_coord_region    /* OUT */
);

SRM_Status_Code cimpl_SRM_ChangeOrientationSRFObject
(
          SRM_Object_Reference                  this_object,
    const SRM_Object_Reference                  source_srf,
    const SRM_Orientation                      *source_orientation,
    const SRM_ORM_Transformation_3D_Parameters *h_st,
          SRM_Orientation                      *target_orientation, /* OUT */
          SRM_Coordinate_Valid_Region          *ref_coord_region    /* OUT */
);


SRM_Status_Code cimpl_SRM_CreateCoordinate3D
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Long_Float        third_coordinate_component,
    SRM_Coordinate3D     *new_coordinate
);


SRM_Status_Code cimpl_SRM_DestroyCoordinate3D
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference coordinate
);


SRM_Status_Code cimpl_SRM_DestroyThisCoordinate3D
(
    SRM_Object_Reference coordinate
);


SRM_Status_Code cimpl_SRM_DestroyDirection
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference direction
);

SRM_Status_Code cimpl_SRM_DestroyThisDirection
(
    SRM_Object_Reference direction
);

SRM_Status_Code cimpl_SRM_DestroyOrientation
(
    SRM_Object_Reference this_object,
    SRM_Object_Reference orientation
);


SRM_Status_Code cimpl_SRM_DestroyThisOrientation
(
    SRM_Object_Reference orientation
);

SRM_Status_Code cimpl_SRM_EuclideanDistance3D
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *source_coordinate,
    const SRM_Coordinate3D     *target_coordinate,
          SRM_Long_Float       *distance           /* OUT */
);


SRM_Status_Code cimpl_SRM_GetCoordinate3DValues
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *coordinate,
          SRM_Long_Float       *first_coordinate_component,  /* OUT */
          SRM_Long_Float       *second_coordinate_component, /* OUT */
          SRM_Long_Float       *third_coordinate_component   /* OUT */
);

SRM_Status_Code cimpl_SRM_GetOrientationValues
(
          SRM_Object_Reference  this_object,
    const SRM_Orientation      *orientation,
          SRM_Coordinate3D     *reference_coordinate, /* OUT */
          SRM_Matrix_3x3       *matrix                /* OUT */
);

SRM_Status_Code cimpl_SRM_GetDirectionValues
(
          SRM_Object_Reference  this_object,
    const SRM_Direction        *direction,
          SRM_Coordinate3D     *reference_coordinate,       /* OUT */
          SRM_Long_Float       *first_direction_component,  /* OUT */
          SRM_Long_Float       *second_direction_component, /* OUT */
          SRM_Long_Float       *third_direction_component   /* OUT */
);


SRM_Status_Code cimpl_SRM_GetExtendedValidRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component,
    SRM_Interval_Type    *type,           /* OUT */
    SRM_Long_Float       *extended_lower, /* OUT */
    SRM_Long_Float       *lower,          /* OUT */
    SRM_Long_Float       *upper,          /* OUT */
    SRM_Long_Float       *extended_upper  /* OUT */
);


SRM_Status_Code cimpl_SRM_GetValidRegion
(
    SRM_Object_Reference  this_object,
    SRM_Integer           component,
    SRM_Interval_Type    *type,      /* OUT */
    SRM_Long_Float       *lower,     /* OUT */
    SRM_Long_Float       *upper      /* OUT */
);


SRM_Status_Code cimpl_SRM_SetCoordinate3DValues
(
    SRM_Object_Reference  this_object,
    SRM_Coordinate3D     *coordinate, /* IN/OUT */
    SRM_Long_Float        first_coordinate_component,
    SRM_Long_Float        second_coordinate_component,
    SRM_Long_Float        third_coordinate_component
);


SRM_Status_Code cimpl_SRM_SetExtendedValidRegion
(
    SRM_Object_Reference this_object,
    SRM_Integer          component,
    SRM_Interval_Type    type,
    SRM_Long_Float       extended_lower,
    SRM_Long_Float       lower,
    SRM_Long_Float       upper,
    SRM_Long_Float       extended_upper
);

SRM_Status_Code cimpl_SRM_GetNaturalSRFSMemberCode
(
          SRM_Object_Reference  this_object,
    const SRM_Coordinate3D     *source_coordinate,
          SRM_ORM_Code          orm_code,
          SRM_RT_Code           rt_code,
          SRM_SRFS_Code         target_srfs,
          SRM_SRFS_Code_Info   *srfs_code_info    /* OUT */
);


SRM_Status_Code cimpl_SRM_SetValidRegion
(
    SRM_Object_Reference this_object,
    SRM_Integer          component,
    SRM_Interval_Type    type,
    SRM_Long_Float       lower,
    SRM_Long_Float       upper
);

// These are based on Coordinate 3D classes
SRM_Status_Code cimpl_SRM_GetMGRS
(
          SRM_Object_Reference   this_object,
          SRM_Integer            precision,
    const char                 **mgrs_string
);

SRM_Status_Code cimpl_SRM_SetCoord
(
          SRM_Object_Reference  this_object,
    const char                 *mgrs_string   /* IN params */
);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef/define/endif for CIMPL_BASESRF3D_HPP_INCLUDED */
