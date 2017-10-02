// - API spec. 4.1
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */

#ifndef _RAIF_UTILS_H_
#define _RAIF_UTILS_H_

#include "srm.h"
#include "se_extract_types.h"

/*!
 * STRUCT: RAIF_SRF_Wrapper
 *
 *  A tagged union structure used to store the SRFs. Each SRF is a structure.
 */
typedef struct
{
    EDCS_Unit_Code          angular_unit;
   /*
    * The units that angular measurements are stored in for this SRF
    */

    EDCS_Unit_Code          linear_unit;
   /*
    * The units that linear measurements are stored in for this SRF
    */

    EDCS_Unit_Scale_Code    linear_scale;

    SRM_SRFT_Code           srft_code;
    SRM_DSS_Code            dss_code; /* SRM_DSSCOD_UNSPECIFIED if unused */
    SRM_Object_Reference    srf;
} RAIF_SRF_Wrapper;


extern SRM_Status_Code
RAIFCreateSRFWrapper
(
    const SE_SRF_Context_Info *src_context_info,
          RAIF_SRF_Wrapper    *new_srf
);

extern bool
RAIFSRFIs2D( SRM_SRFT_Code srft_code);

extern bool
RAIFCoordIs2D( SRM_Spatial_Coordinate_Code coord_code);

extern bool
RAIFCoordIs3D( SRM_Spatial_Coordinate_Code coord_code);

extern bool
RAIFCoordIsSurface( SRM_Spatial_Coordinate_Code coord_code);


extern bool
RAIFCoordIsAngular( SRM_Spatial_Coordinate_Code coord_code);

extern SRM_Status_Code
ConvertSearchBoundsDimensionality( const SE_Search_Bounds *src_ptr,
                                         SE_Search_Dimension  dimension,
                                         SE_Search_Bounds *dest_ptr );

// Based on SRF Context Info, coverts linear and angular units if necessary and then
// calls the ChangCoordSRFFromSRF.
extern SRM_Status_Code
RAIFChangeCoordSRFFromContextInfo
(
    const SE_SRF_Context_Info *src_srf_info,
    const SRM_Coordinate      *src_coord,
    const SE_SRF_Context_Info *dest_srf_info,
          SRM_Coordinate      *dest_coord
);


// Given two SRFs converts linear and angular units if necessary,
// then the src Coord in the src SRF to the dest SRF in
// dest coord. This function will cast it to its appropriate SRF stuct and
// then call the right method.
extern SRM_Status_Code
RAIFChangeCoordSRFFromSRF
(
    const RAIF_SRF_Wrapper *src_srf,
    const SRM_Coordinate   *src_coord_in,
    const RAIF_SRF_Wrapper *dest_srf,
          SRM_Coordinate   *dest_coord_out
);


// Given the RAIF_SRF_Wrapper will call the right destroy method
extern SRM_Status_Code
RAIFDestroySRMObjectReference( RAIF_SRF_Wrapper *my_srf );


// Given the RAIF_SRF_Wrapper and the three values will will call the right SRF to create a coordinate 3D
extern SRM_Status_Code
RAIFCreateCoordinate3D
(
    const RAIF_SRF_Wrapper *my_srf,
          SRM_Long_Float    ord1,
          SRM_Long_Float    ord2,
          SRM_Long_Float    ord3,
          SRM_Coordinate3D *new_coord
);

extern SRM_Status_Code
RAIFCreateCoordinate3D
(
    const RAIF_SRF_Wrapper *my_srf,
    const SRM_Coordinate   *old_coord,
          SRM_Coordinate3D *new_coord
);

// Given the RAIF_SRF_Wrapper and the two values will call the right SRF to create a coordinate 2D
extern SRM_Status_Code
RAIFCreateCoordinate2D
(
    const RAIF_SRF_Wrapper *my_srf,
          SRM_Long_Float    ord1,
          SRM_Long_Float    ord2,
          SRM_Coordinate2D *new_coord
);


// Given the RAIF_SRF_Wrapper will call the right destroy method for the coordinate 3D
extern SRM_Status_Code
RAIFDestroyCoordinate3D( const RAIF_SRF_Wrapper *my_srf, SRM_Coordinate3D *my_coord );


extern SRM_Status_Code
RAIFDestroyCoordinate2D( const RAIF_SRF_Wrapper *my_srf, SRM_Coordinate2D *my_coord );


// Direction Related Calls
//
// These functions are used to Create, ChangeSRF, GetValues, and Destroy directions
// based on a passed in SRF. Note that these are only used with 3D SRFs.

extern SRM_Status_Code
RAIFCreateDirection
(
    const RAIF_SRF_Wrapper *my_srf,
    const SRM_Coordinate3D *ref_coord,
          SRM_Long_Float    ord1,
          SRM_Long_Float    ord2,
          SRM_Long_Float    ord3,
          SRM_Direction    *new_direction
);


extern SRM_Status_Code
RAIFChangeDirectionSRF
(
    const RAIF_SRF_Wrapper *src_srf,
    const SRM_Direction    *src_direction_in,
    const RAIF_SRF_Wrapper *dest_srf,
          SRM_Direction    *dest_direction_out
);


extern SRM_Status_Code
RAIFGetDirectionValues
(
    const RAIF_SRF_Wrapper *my_srf,
    const SRM_Direction    *my_direction,
          SRM_Coordinate3D *my_ref_coord,
          SRM_Long_Float   *ord1,
          SRM_Long_Float   *ord2,
          SRM_Long_Float   *ord3
);


extern SRM_Status_Code
RAIFDestroyDirection( const RAIF_SRF_Wrapper *my_srf, SRM_Direction *my_direction );



// Orientation Related Calls
//
// These functions are used to Create, ChangeSRF, GetValues, and Destroy orientations
// based on a passed in SRF. Note that these are only used with 3D SRFs.

extern SRM_Status_Code
RAIFCreateOrientation
(
    const RAIF_SRF_Wrapper *my_srf,
    const SRM_Coordinate3D *ref_coord,
          SRM_Matrix_3x3    matrix,
          SRM_Orientation  *new_orientation
);


extern SRM_Status_Code
RAIFChangeOrientationSRF
(
    const RAIF_SRF_Wrapper *src_srf,
    const SRM_Orientation  *src_orientation_in,
    const RAIF_SRF_Wrapper *dest_srf,
          SRM_Orientation  *dest_orientation_out
);


extern SRM_Status_Code
RAIFGetOrientationValues
(
    const RAIF_SRF_Wrapper *my_srf,
    const SRM_Orientation  *my_direction,
          SRM_Coordinate3D *my_ref_coord,
          SRM_Matrix_3x3   *matrix
);


extern SRM_Status_Code
RAIFDestroyOrientation( const RAIF_SRF_Wrapper *my_srf, SRM_Orientation *my_orientation );

#endif
