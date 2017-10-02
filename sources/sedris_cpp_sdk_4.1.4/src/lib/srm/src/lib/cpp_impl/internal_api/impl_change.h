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


#ifndef _IMPL_CHANGE_H
#define _IMPL_CHANGE_H

/*! 
  @file   impl_change.h
  @author Cameron D. Kellough, SRI
*/
#include"impl_private.h"
#include"impl_status.h"
//!  Changes the represenation from one SRF to another for 2D coordinates.

/*! This routine changes the representation of a 2D location from one 2D SRF to another 2D SRF.
  This routine implements changeCoordinate2DSRF() : srm::BaseSRF_2D

  \remark It is the responsiblity of the API to call the appropriate 2D or 3D version of this function.  
  \note Invalid is directly propogated to tgt if source is invalid.
  \returns IMPL_VALID for valid target coordinate
  \returns IMPL_EXTENDED for extended target coordinate
  \returns IMPL_INVALID for invalid target coordinate  
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF

*/
Impl_Status
Impl_changeCoord2DSRF(void* srf_src,
		      /*!< (Input): \impl_ptr_src_def*/
		      const SRM_Long_Float coord_src[2],
		      /*!< (Input): \impl_coord_src_def*/
		      void* srf_tgt, 
		      /*!< (Input): \impl_ptr_tgt_def*/
		      SRM_Long_Float coord_tgt[2]
		      /*!< (Output): \impl_coord_tgt_def*/
		      );


Impl_Status
Impl_changeCoord2DSRFObject (void* srf_src,
			     /*!< (Input): \impl_ptr_src_def*/
			     const SRM_Long_Float coord_src[2],
			     /*!< (Input): \impl_coord_src_def*/
			     void* srf_tgt, 
			     /*!< (Input): \impl_ptr_tgt_def*/
			     SRM_Long_Float coord_tgt[2],
			     /*!< (Output): \impl_coord_tgt_def*/
			     const SRM_ORM_Transformation_2D_Parameters *hst
			     );

//!  Changes the represenation from one SRF to another for 3D coordinates.

/*! This routine changes the representation of a 3D location from one #D SRF to another #D SRF.
  This routine implements changeCoordinate3DSRF() : srm::BaseSRF_3D
  \remark It is the responsiblity of the API to call the appropriate 2D or 3D version of this function.

  \note Invalid is directly propogated to tgt if source is invalid.
  \returns IMPL_VALID for valid target coordinate
  \returns IMPL_EXTENDED for extended target coordinate
  \returns IMPL_INVALID for invalid target coordinate  
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF

*/
Impl_Status
Impl_changeCoord3DSRF(void* srf_src,
		      /*!< (Input): \impl_ptr_src_def*/
		      const SRM_Long_Float coord_src[3],
		      /*!< (Input): \impl_coord_src_def*/
		      void* srf_tgt,
		      /*!< (Input): \impl_ptr_tgt_def*/ 
		      SRM_Long_Float coord_tgt[3]
		      /*!< (Output): \impl_coord_tgt_def*/
		      );


Impl_Status
Impl_changeCoord3DSRFObject(void* srf_src,
			    /*!< (Input): \impl_ptr_src_def*/
			    const SRM_Long_Float coord_src[3],
			    /*!< (Input): \impl_coord_src_def*/
			    void* srf_tgt,
			    /*!< (Input): \impl_ptr_tgt_def*/ 
			    SRM_Long_Float coord_tgt[3],
			    /*!< (Output): \impl_coord_tgt_def*/
			    const SRM_ORM_Transformation_3D_Parameters* hst
			    );

//! Changes the representation of a direction from one SRF to another.

/*! This routines changes the represnation of a direction from one SRF
  to another.  It takes as parameters the components of the direction
  object in the API, not the object, and likewise returns values in the
  same fashion. This routine implements changeDirectionSRF() : srm::BaseSRF_3D.

  \remark Directions may only have 3D locations as reference locations.
  \remark The API shall ensure that no SRF's associated with 2D locations or
  surface locations are passed here.

  \note Invalid is directly propogated to tgt if source is invalid.
  \returns IMPL_VALID for valid target direction
  \returns IMPL_EXTENDED for target direction with extended \a ref_loc_tgt[]
  \returns IMPL_INVALID for target direction invalid \a ref_loc_tgt[] 
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF

*/
Impl_Status
Impl_changeDirectionSRF(void*   srf_src,
			/*!< (Input): \impl_ptr_src_def*/
			const SRM_Long_Float ref_loc_src[3],
			/*!< (Input): \impl_ref_loc_src_def*/
			const SRM_Long_Float dir_values_src[3],
			/*!< (Input): \impl_dir_values_src_def*/
			void*   srf_tgt,
			/*!< (Input): \impl_ptr_tgt_def*/
			SRM_Long_Float ref_loc_tgt[3],
			/*!< (Output): \impl_ref_loc_tgt_def*/
			SRM_Long_Float dir_values_tgt[3]
			/*!< (Output): \impl_dir_values_tgt_def*/
			);



Impl_Status
Impl_changeDirectionSRFObject(void*   srf_src,
			      /*!< (Input): \impl_ptr_src_def*/
			      const SRM_Long_Float ref_loc_src[3],
			      /*!< (Input): \impl_ref_loc_src_def*/
			      const SRM_Long_Float dir_values_src[3],
			      /*!< (Input): \impl_dir_values_src_def*/
			      void*   srf_tgt,
			      /*!< (Input): \impl_ptr_tgt_def*/
			      SRM_Long_Float ref_loc_tgt[3],
			      /*!< (Output): \impl_ref_loc_tgt_def*/
			      SRM_Long_Float dir_values_tgt[3],
			      /*!< (Output): \impl_dir_values_tgt_def*/
			      const SRM_ORM_Transformation_3D_Parameters* hst
			      );


//! Changes the representation of an orientation from one SRF to another.

/*! This routines changes the represnation of a direction from one SRF
  to another.  It takes as parameters the components of the orientation
  object in the API, not the object, and likewise returns values in the
  same fashion.  This routine implements changeOrientationSRF() : srm::BaseSRF_3D.

  \remark Orientations may only have 3D locations as reference locations.
  \remark The API shall ensure that no SRF's associated with 2D locations or
  surface locations are passed here.

  \note Invalid is directly propogated to tgt if source is invalid.
  \returns IMPL_VALID for valid target orientation
  \returns IMPL_EXTENDED for target orientation with extended \a ref_loc_tgt[]
  \returns IMPL_INVALID for target orientation invalid \a ref_loc_tgt[] 
  \returns IMPL_MEMALLOC on out of memory
  \returns IMPL_SRFSRC for a bad source SRF
  \returns IMPL_SRFTGT for a bad target SRF

*/
Impl_Status
Impl_changeOrientationSRF(void*   srf_src,
			  /*!< (Input): \impl_ptr_src_def*/
			  const SRM_Long_Float ref_loc_src[3],
			  /*!< (Input): \impl_ref_loc_src_def*/
			  const SRM_Long_Float matrix_values_src[3][3],
			  /*!< (Input): \impl_matrix_values_src_def*/
			  void*   srf_tgt,
			  /*!< (Input):\impl_ptr_tgt_def*/
			  SRM_Long_Float ref_loc_tgt[3],
			  /*!< (Output): \impl_ref_loc_tgt_def*/
			  SRM_Long_Float matrix_values_tgt[3][3]
			  /*!< (Output): \impl_matrix_values_tgt_def*/
			  );

#endif
