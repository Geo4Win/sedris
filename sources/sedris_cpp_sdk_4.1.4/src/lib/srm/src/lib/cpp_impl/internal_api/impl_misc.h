/*!
  @file   impl_misc.h
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


#ifndef _IMPL_MISC_H
#define _IMPL_MISC_H

#include "srm_types.h"
#include "impl_private.h"

//!Instances a Coordinate with ABSTRACT_3D ORM into a real ORM
/*!This routine takes a coordinate in an abstract SRF like LSR and
  returns the location in space that the coordinate would be found at
  in a real ORM.  First, the origin of the abstract system SRF is
  moved to \a ref_loc_dst the real destination system. Then the affine
  transformation matrix \a matrix_values is applied to rotate and
  scale the axes of the coordinate systems appropriately.  Finally, this
  rotated and scaled location is returned in dst_srf.*/
Impl_Status
Impl_instance3DAbstractSpaceCoordinate
(
    void* srf_org,
    /*!< (Input) SRF with SRM_ORMCOD_ABSTRACT_3D*/
    SRM_Long_Float coord_org[3],
    /*!< (Input) abstract 3d coordinate*/
    void* srf_dst,
    /*!< (Input) The srf to be instanced into*/
    SRM_Long_Float ref_loc_dst[3],
    /*!< (Input) The location of the abstract space's origin*/
    SRM_Long_Float matrix_values[3][3],
    /*!< (Input) The affine transformation matrix to orint the point*/
    SRM_Long_Float crd_dst[3]
    /*!< (Output)The new target location*/
);

//!Instances a Coodinate with ABSTRACT_2D ORM into a real orm
/*!This routine takes a coordinate in an abstract SRF like LSR and
  returns the location in space that the coordinate would be found at
  in a real ORM.  First, the origin of the abstract system SRF is
  moved to \a ref_loc_dst the real destination system. Then the affine
  transformation matrix \a matrix_values is applied to rotate and
  scale the axes of the coordinate systems appropriately.  Finally, this
  rotated and scaled location is returned in dst_srf.*/
Impl_Status
Impl_instance2DAbstractSpaceCoordinate
(
    void* srf_org,
    /*!< (Input) SRF with SRM_ORMCOD_ABSTRACT_3D*/
    SRM_Long_Float coord_org[2],
    /*!< (Input) abstract 3d coordinate*/
    void* srf_dst,
    /*!< (Input) The srf to be instanced into*/
    SRM_Long_Float ref_loc_dst[2],
    /*!< (Input) The location of the abstract space's origin*/
    SRM_Long_Float matrix_values[2][2],
    /*!< (Input) The affine transformation matrix to orint the point*/
    SRM_Long_Float crd_dst[2]
    /*!< (Output)The new target location*/
);


//!Creates a LocalTangentEuclidean at a 3D location

/*!This function creates a LocalTangentEuclidean SRF at a given surface location
  for SRF's which have an ellipsoid based ORM.  This function will perform a
  conversion internally to the celestiodetic representation of \a coord_org
  if necessary

  This routine implements createLocalTangentEuclideanSRF() : srm::BaseSRF_WithEllipsoidalHeight

  \remark Parameter \a coord_org must be a Surface location associated with an appropriate SRF.

  \returns IMPL_VALID on successful allocation
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for an SRF with a non-ellipsoid ORM or other SRF issue
  \returns IMPL_CRDORG if the origin coordinate is bad preventing success
*/
Impl_Status
Impl_createSRFLocalTangentEuclidean
(
    void* srf_org,
    /*!< (Input): \impl_ptr_org_def*/
    const SRM_Long_Float coord_org[2],
    /*!< (Input): \impl_coord_org_def*/
    const SRM_Long_Float  azimuth,
    /*!< (Input): azimuth for LTE*/
    const SRM_Long_Float  x_false_origin,
    /*!< (Input): x_false_origin*/
    const SRM_Long_Float  y_false_origin,
    /*!< (Input): y_false_origin*/
    const SRM_Long_Float  height_offset,
    /*!< (Input): height_offset */
    void** lte_srf_ptr
    /*!< (Output): \impl_ptr_ptr_def */
);


//!This routine creates an internal API SRF object containing the appropriate
//!SRF from the the given srf set specified by \a setcode for the supplied 3D
//!Coordinate
Impl_Status
Impl_getNaturalSRFSetMemberFor3DCoord
(
    void* srf_org,
    /*!< (Input):  srf of the origin coordinate*/
    SRM_Long_Float coord_org[3],
    /*!< (Input):  origin coordinate */
    SRM_ORM_Code   orm_dst,
    /*!< (Input): destination orm code to be used for creating a set member*/
    SRM_RT_Code   rt_dst,
    /*!< (Input): destination rt code to be used for creating a set member*/
    SRM_SRFS_Code set_code,
    /*!< (Input): An ISO 18026 compliant SRF Set Code*/
    void** dst_srf_ptr
    /*!< (Output): \impl_ptr_ptr_def */
);

//!This routine creates an internal API SRF object containing the appropriate
//!SRF from the the given srf set specified by \a setcode for the supplied SURF Coordinate
//!
/*!
   \returns IMPL_VALID for coordinate inside of valid region for natural cell.
   \returns IMPL_EXTENDED for a coordinate inside extended region of natural cell.
   \returns IMPL_INVALID for a coordinate that has no representation in that set
   \returns IMPL_BADORM for a coordinate that has no representation in that set
*/
Impl_Status
Impl_getNaturalSRFSetMemberForSURFCoord
(
    void* srf_org,
    /*!< (Input):  srf of the origin coordinate*/
    SRM_Long_Float coord_org[2],
    /*!< (Input):  origin coordinate */
    SRM_ORM_Code   orm_dst,
    /*!< (Input): destination orm code to be used for creating a set member*/
    SRM_RT_Code   rt_dst,
    /*!< (Input): destination rt code to be used for creating a set member*/
    SRM_SRFS_Code set_code,
    /*!< (Input): An ISO 18026 compliant SRF Set Code*/
    void** dst_srf_ptr
    /*!< (Output): \impl_ptr_ptr_def */
);


//!This routine creates an internal API SRF object containing the appropriate
//!SRF from the the given srf set specified by \a setcode for the supplied 3D
//!Coordinate
Impl_Status
Impl_getNaturalSRFSetMemberCodeFor3DCoord
(
    void* srf_org,
    /*!< (Input):  srf of the origin coordinate*/
    SRM_Long_Float coord_org[3],
    /*!< (Input):  origin coordinate */
    SRM_ORM_Code   orm_dst,
    /*!< (Input): destination orm code to be used for creating a set member*/
    SRM_RT_Code   rt_dst,
    /*!< (Input): destination rt code to be used for creating a set member*/
    SRM_SRFS_Code set_code,
    /*!< (Input): An ISO 18026 compliant SRF Set Code*/
    SRM_SRFS_Code_Info* srfs_code_info
    /*!< (Output): set member code for the proper member of the given SRFS*/
);

//!This routine creates an internal API SRF object containing the appropriate
//!SRF from the the given SRF set specified by \a setcode for the supplied SURF
//!Coordinate
Impl_Status
Impl_getNaturalSRFSetMemberCodeForSURFCoord
(
    void* srf_org,
    /*!< (Input):  srf of the origin coordinate*/
    SRM_Long_Float coord_org[2],
    /*!< (Input):  origin coordinate */
    SRM_ORM_Code   orm_dst,
    /*!< (Input): destination orm with which to create the set member*/
    SRM_RT_Code   rt_dst,
    /*!< (Input): destination rt code to be used for creating a set member*/
    SRM_SRFS_Code set_code,
    /*!< (Input): An ISO 18026 compliant SRF Set Code*/
    SRM_SRFS_Code_Info* srfs_code_info
    /*!< (Output):  set member code for the proper member of the given SRFS*/
);


//! This routine gets the codes that represent the lineage of the SRF

/*! This routine gets the codes that represent the SRF in the manner of ISO 18026 codes.
  IMPL accepts pointers to locations for pertinent code values from the API.  It is the
  API's responsibility to manage the storage under the pointers.

  \note It is the API's responsiblity to ensure that only good \a srf_org's are passed to this function
  \returns IMPL_VALID on success
  \returns IMPL_MEMALLOC on bad pointers
*/
Impl_Status
Impl_getCodes
(
    void* srf_org,
     /*!< (Input): \impl_ptr_org_def*/
    SRM_SRF_Code* srf_code,
     /*!< (Output): An ISO 18026 compliant Predefined SRF Code*/
    SRM_SRFT_Code* template_code,
     /*!< (Output): An ISO 18026 compliant SRF template code*/
    SRM_SRFS_Code_Info* srfs_code_info
     /*!< (Output): An ISO 18026 compliant SRF Set/Set Member Codes*/
);


//!This routine gets the parameters from IMPL private storage

/*!This routine retrieves the SRF parameters ino the ISO 18026 clause 11
  SRF Parameters structure appropriate for the SRF.  IMPL presumes that the
  API knew what type of data it was requesting and passed a void pointer
  to an appropriately typed structure on the API side.  IMPL will write the
  requested values into that structure.

  \returns IMPL_VALID on success
  \returns IMPL_MEMALLOC on bad pointer
*/
Impl_Status
Impl_getSRFParameters
(
    void *srf_org,
   /*!< (Input):\impl_ptr_org_def*/
    void *api_template_parm_struct_ptr
   /*!< (Output): pointer to a clause 11 SRF parameters
      structure correctly associated with \a srf_org.  The
      structure to which this parameter points is owned by the API.
      The Implementation will copy the contents
      of its internal structure to the API's structure leaving the
      API to manage the storage associated with its structure.*/
);

//!Gets the ORM of the origin SRF for the convenience of the API
/*! \returns IMPL_VALID  on success
    \returns IMPL_SRFSRC of bad srf_org
    \returns IMPL_MEMALLOC on NULL orm pointer
*/
Impl_Status
Impl_getORM
(
    void         *srf_org, /*!< (Input): origin srf whose orm is to be returned*/
    SRM_ORM_Code *orm      /*!< (Output): ORM of origin srf*/
);

//!Gets the RT of the origin SRF for the convenience of the API
/*! \returns IMPL_VALID  on success
    \returns IMPL_SRFSRC of bad srf_org
    \returns IMPL_MEMALLOC on NULL rt pointer
*/
Impl_Status
Impl_getRT
(
    void        *srf_org,
    SRM_RT_Code *rt
);

Impl_Status
Impl_getA
(
    void           *srf_org,
    SRM_Long_Float *a
);

Impl_Status
Impl_getF
(
    void           *srf_org,
    SRM_Long_Float *f
);

Impl_Status
Impl_getCSCode
(
    void        *srf_org,
    SRM_CS_Code *cs
);

Impl_Status Impl_setValidRegion
(
    void              *srf_data,
    SRM_Integer        component,
    SRM_Interval_Type  type,
    SRM_Long_Float     lower,
    SRM_Long_Float     upper,
    bool               is_angular
);

Impl_Status Impl_setExtendedValidRegion
(
    void              *srf_data,
    SRM_Integer        component,
    SRM_Interval_Type  type,
    SRM_Long_Float     extended_lower,
    SRM_Long_Float     lower,
    SRM_Long_Float     upper,
    SRM_Long_Float     extended_upper,
    bool               is_angular
);

Impl_Status Impl_getValidRegion
(
    void              *srf_data,
    SRM_Integer        component,
    SRM_Interval_Type &type,
    SRM_Long_Float    &lower,
    SRM_Long_Float    &upper
);

Impl_Status Impl_getExtendedValidRegion
(
    void              *srf_data,
    SRM_Integer        component,
    SRM_Interval_Type &type,
    SRM_Long_Float    &extended_lower,
    SRM_Long_Float    &lower,
    SRM_Long_Float    &upper,
    SRM_Long_Float    &extended_upper
);


Impl_Status Impl_setValidGeodeticRegion
(
    void              *srf_data,
    SRM_Integer        component,
    SRM_Interval_Type  type,
    SRM_Long_Float     lower,
    SRM_Long_Float     upper
);

Impl_Status Impl_setExtendedValidGeodeticRegion
(
    void              *srf_data,
    SRM_Integer        component,
    SRM_Interval_Type  type,
    SRM_Long_Float     extended_lower,
    SRM_Long_Float     lower,
    SRM_Long_Float     upper,
    SRM_Long_Float     extended_upper
);

Impl_Status Impl_getValidGeodeticRegion
(
    void              *srf_data,
    SRM_Integer        component,
    SRM_Interval_Type &type,
    SRM_Long_Float    &lower,
    SRM_Long_Float    &upper
);

Impl_Status Impl_getExtendedValidGeodeticRegion
(
    void              *srf_data,
    SRM_Integer        component,
    SRM_Interval_Type &type,
    SRM_Long_Float    &extended_lower,
    SRM_Long_Float    &lower,
    SRM_Long_Float    &upper,
    SRM_Long_Float    &extended_upper
);


//!Compares the SRF parameters by comparing the map keys used by the initialization
/*! \returns memcmp outputs thus zero 0 for equal*/
SRM_Integer
Impl_compareSRFParameters
(
    void *srf_org,
    void *srf_dst
);

//!Maintenence function which dumps the adjacencies for all known srf templates
/*! \returns IMPL_VALID  on success*/
Impl_Status
Impl_dumpNodeGraph
(
    SRM_Integer select /*!< 1 -> conversions 2-> datum shifts*/
);

#endif
