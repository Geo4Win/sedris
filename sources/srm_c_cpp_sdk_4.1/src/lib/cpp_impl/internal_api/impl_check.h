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


#ifndef _IMPL_CHECK_H
#define _IMPL_CHECK_H

/*! 
  @file   impl_check.h
  @author Cameron D. Kellough, SRI
*/
#include"impl_private.h"

//!This routine checks a coordinate for validity based on the library's internal criteria.

/*!This routine checks a coordinate for validity based on the library's internal criteria
  for the mathematical validity of operations on it.  In many cases this operation will involve
  an implicit conversion performed internal to the library.  This routine implements 
  checkCoordinate() : srm::BaseSRF.  Return is through the status code.
  
  \return IMPL_VALID    The passed coordinate is valid
  \return IMPL_EXTENDED The passed coordinate is extended
  \return IMPL_INVALID  The passed coordinate is invalid
  \return IMPL_DEFINED  The passed coordinate is defined but not extended or valid
  \return IMPL_MEMALLOC A probelm obtaining memory for the test occurred
  \return IMPL_SRFSRC   The passed SRF has parameters that are not consistent with their definitions

*/
Impl_Status
Impl_checkCoordinate2D(void* srf_org,
		     /*!< (Input): \impl_ptr_org_def*/
		       const SRM_Long_Float coord_org[]
		     /*!< (Input): \impl_coord_org_def*/
		     );

//!This routine checks a coordinate for validity based on the library's internal criteria.

/*!This routine checks a coordinate for validity based on the library's internal criteria
  for the mathematical validity of operations on it.  In many cases this operation will involve
  an implicit conversion performed internal to the library.  This routine implements 
  checkCoordinate() : srm::BaseSRF.  Return is through the status code.
  
  \return IMPL_VALID    The passed coordinate is valid
  \return IMPL_EXTENDED The passed coordinate is extended
  \return IMPL_INVALID  The passed coordinate is invalid
  \return IMPL_DEFINED  The passed coordinate is defined but not extended or valid
  \return IMPL_MEMALLOC A problem obtaining memory for the test occurred
  \return IMPL_SRFSRC   The passed SRF has parameters that are not consistent with their definitions

*/
Impl_Status
Impl_checkCoordinate3D(void* srf_org,
		     /*!< (Input): \impl_ptr_org_def*/
		     const SRM_Long_Float coord_org[]
		     /*!< (Input): \impl_coord_org_def*/
		     );

//!This routine checks a surface coordinate for validity based on the library's internal criteria.

/*!This routine checks a surface coordinate for validity based on the library's internal criteria
  for the mathematical validity of operations on it.  In many cases this operation will involve
  an implicit conversion performed internal to the library.  This routine implements 
  checkCoordinate() : srm::BaseSRF.  Return is through the status code.
  
  \return IMPL_VALID    The passed coordinate is valid
  \return IMPL_EXTENDED The passed coordinate is extended
  \return IMPL_INVALID  The passed coordinate is invalid
  \return IMPL_DEFINED  The passed coordinate is defined but not extended or valid
  \return IMPL_MEMALLOC A probelm obtaining memory for the test occurred
  \return IMPL_SRFSRC   The passed SRF has parameters that are not consistent with their definitions

*/
Impl_Status
Impl_checkCoordinateSurface(void* srf_org,
			    /*!< (Input): \impl_ptr_org_def*/
			    const SRM_Long_Float coord_org[]
			    /*!< (Input): \impl_coord_org_def*/
			    );

//!This routine checks a direction for validity based on the library's internal criteria.

/*!This routine checks a direction for validity based on the library's internal criteria
  for the mathematical validity of operations on it.  In many cases this operation will involve
  an implicit conversion performed internally by the library.  This routine implements 
  checkDirection() : srm::BaseSRF_3D.  Return is through the status code.

  \returns IMPL_VALID for valid direction
  \returns IMPL_EXTENDED for direction with extended \a ref_loc_org[]
  \returns IMPL_INVALID for direction with invalid \a ref_loc_org[]
  \returns IMPL_OBJSRC for direction within epsilon of having zero magnitude 
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad \a srf_org

*/
Impl_Status
Impl_checkDirection(void*   srf_org,
		    /*!< (Input): \impl_ptr_org_def*/
		    const SRM_Long_Float ref_loc_org[3],
		    /*!< (Input): \impl_ref_loc_org_def*/
		    const SRM_Long_Float dir_values_org[3]
		    /*!< (Input): \impl_dir_values_org_def*/
		    );

//!This routine checks an orientation for validity based on the library's internal criteria.

/*!This routine checks a orientation for validity based on the library's internal criteria
  for the mathematical validity of operations on it.  In many cases this operation will involve
  an implicit conversion performed internally by the library.  This routine implements 
  checkOrientation() : srm::BaseSRF_3D. Return is through the status code.

  \returns IMPL_VALID for valid orientation
  \returns IMPL_EXTENDED for orientation with extended \a ref_loc_tgt[]
  \returns IMPL_INVALID for orientation with invalid \a ref_loc_tgt[] 
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF

*/
Impl_Status
Impl_checkOrientation(void*   srf_org,
		      /*!< (Input) \impl_ptr_org_def*/
		      const SRM_Long_Float ref_loc_org[3],
		      /*!< (Input): \impl_ref_loc_org_def*/
		      const SRM_Long_Float matrix_values_org[3][3]
		      /*!< (Input): \impl_dir_values_org_def*/		      
		      );
#endif
