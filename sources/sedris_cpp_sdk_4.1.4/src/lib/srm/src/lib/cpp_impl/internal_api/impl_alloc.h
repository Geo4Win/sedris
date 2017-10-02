/*!
  @file   impl_alloc.h
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


#ifndef _IMPL_ALLOC_H
#define _IMPL_ALLOC_H

#include "srm_types.h"
#include "impl_private.h"
#include "impl_status.h"

//!This returns the size of the data to be copied when
//!passed a code into the brackets.
extern SRM_Integer (*Impl_sizeof_templ_param[])();


//!Creates an SRF from the appropriate parameters structure

/*!This routine creates an SRF object form the appropriate struct definition in the API
defined in ISO18026 clause 11.
This method implements the create() method of the API on each concrete SRF class.

\returns IMPL_VALID on successful allocation
\returns IMPL_MEMALLOC on out of memory
\returns IMPL_SRCSRF  for defective srf parameters

*/

Impl_Status
Impl_createSRFFromParams(SRM_SRFT_Code template_code,
			 /*!< (Input): ISO 18026 compliant SRF template code*/
			 SRM_ORM_Code          orm,
			 /*<! (Input): ISO 18026 Compliant orm code*/
			 SRM_RT_Code          rt,
			 /*<! (Input): ISO 18026 Compliant rt code*/
			 void*                 api_template_parm_struct_ptr,
			 /*!< (Input): pointer to clause 11 structure representing SRF parameters
			   which is cast to a void pointer by the caller and recast to
			   the proper form by the implementation using the code stored
			   in \a t_code */
			 void**    api_srf_representation_ptr_ptr
			 /*!< (Output): \api_ptr_ptr_def */
			 );



//!Creates an SRF from the appropriate standard SRF code.

/*!This routine creates an internal SRF object form the standard SRF code
  defined in ISO18026 clause 11.
  This routine implements createStandardSRF() : srm::BaseSRF of the API

  \returns IMPL_VALID on successful allocation
  \returns IMPL_MEMALLOC on out of memory
  \remark Doesn't return anything for bad codes because API verifies codes are good.
*/
Impl_Status
Impl_createSRFStandard(SRM_SRF_Code srf_code,
		       /*!< (Input): ISO18026 compliant Predefined SRF Code*/
		       SRM_RT_Code  rt_code,
		       /*<! (Input): ISO 18026 Compliant rt code*/
		       void** impl_srf_representation_ptr_ptr
		       /*!< (Output): \impl_ptr_ptr_def */
		       );


//!Creates an interal SRF object from the appropriate set code, member code, and ORM.

/*!This routine creates an internal SRF object using the appropriate set code, member code,
  and ORM as defined in ISO18026 clause 11.
  This routine implements the createSRFSetMember() : srm::BaseSRF of the API

  \returns IMPL_VALID on successful allocation
  \returns IMPL_MEMALLOC on out of memory
  \remark Doesn't return anything for bad codes because API verifies codes are good.
*/

Impl_Status
Impl_createSRFSetMember(SRM_SRFS_Info srfs_info,
			/*!< (Input): An ISO 18026 Compliant SRF Set/Set Member/ORM Code*/
			SRM_RT_Code rt,
			/*!< (Input): An ISO 18026 Compliant Hsr code*/
			void** api_srf_representation_ptr_ptr
			/*!< (Output): \impl_ptr_ptr_def */
			);

Impl_Status
Impl_copySRF(  void* src_api_srf_handle,
	       void** tgt_api_srf_handle
	       );

void Impl_setValidateCoordinate( void* api_template_parm_struct_ptr,
				 bool set );

bool Impl_ValidateCoordinateIsOn( void*  api_template_parm_struct_ptr );


//! Releases Any storage held by the implementation for the API.

/*! \a Impl_releaseSRF() releases any storage held by the implementation for the API under an \a Impl_SRF_ptr.
It takes \a Impl_SRF_ptr** so that it can be used to write the API's storage of the pointer
to NULL after deallocating the storage thus preventing the API from accidentally trying to re-reference
the deallocated pointer.
This routine implements release() : srm::BaseSRF.

\remark It should be called by the API when the  reference count reaches 0 for an SRF object.

\returns IMPL_VALID on success
\returns IMPL_MEMALLOC on failure deallocating the object
*/
Impl_Status
Impl_releaseSRF(void**  impl_srf_representation_ptr_ptr
		/*!< (Input/Output): \impl_ptr_ptr_def */);


#endif
