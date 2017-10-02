/*! @file impl_generated.h
    @author Cameron D. Kellough (SRI)
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


#ifndef _IMPL_GENERATED_H
#define IMPL_GENERATED_H

#if defined (SC52) || defined (gnu)
#include <cstdlib>
#else
#include <stdio.h>
#endif

#include <math.h>
#include <signal.h>
#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_internal.h"
#include "srm_validcoord.h"
#include "impl_vos.h"
#include "edges.h"
#include "srm_check.h"
#include "srm_conversions.h"
#include "srm_coord_offsets.h"
#include "srm_predefined_srf.h"
#include "srm_srfp.h"
#include "srm_srf_sets.h"
#include "srm_srf_specific_data.h"
#include "srm_validcoord.h"
#include "srm_boundaries.h"


extern void* (*Impl_allocsrf[SRM_SRFT_CODE_UBOUND+1])
(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr);

extern void* (*Impl_allocsrf_specific_data[SRM_SRFT_CODE_UBOUND+1])(void* impl_SRFP_struct );

extern Impl_Status (*Impl_checkSRFP[SRM_SRFT_CODE_UBOUND+1])(void* input_srfp);

extern SRM_SRFT_Code (*Impl_bSRFTforSRFT[SRM_SRFT_CODE_UBOUND+1])();

extern void* (*Impl_bdSRFTforSRFT[SRM_SRFT_CODE_UBOUND+1])(SRM_ORM_Code orm_dst);

extern SRM_Integer (*Impl_sizeof_templ_param[SRM_SRFT_CODE_UBOUND+1])();

extern SRM_ORM_Code (*Impl_bdORMforSRFT[SRM_SRFT_CODE_UBOUND+1])(SRM_ORM_Code orm_dst);

extern SRM_RT_Code  (*Impl_bdRTforSRFT[SRM_SRFT_CODE_UBOUND+1])(SRM_RT_Code rt_dst);

extern SRM_Integer (*Impl_sizeof_specific_data[SRM_SRFT_CODE_UBOUND+1])();

extern Impl_Status (*Impl_validcoord3DSRFT[SRM_SRFT_CODE_UBOUND+1])
  (Impl_Private_Data pdat,
   SRM_Long_Float v_coord[3]
   );

extern SRM_Integer (*Impl_get_frame_idSRFT[SRM_SRFT_CODE_UBOUND+1])(void* api_templ_param_struct_ptr);


extern SRM_SRFT_Code (*Impl_SetMembersrf_templ_code[SRM_SRFS_CODE_UBOUND+1])();

extern void* (*Impl_allocSetMembersrf[SRM_SRFS_CODE_UBOUND+1])
(SRM_SRFS_Code_Info srfs_code_info, SRM_ORM_Code orm, SRM_RT_Code rt);

extern SRM_SRFT_Code (*Impl_bSRFTforSRFS[SRM_SRFS_CODE_UBOUND+1])();

extern void* (*Impl_bdSRFTforSRFS[SRM_SRFS_CODE_UBOUND+1])(SRM_ORM_Code orm_dst);

extern SRM_ORM_Code (*Impl_bdORMforSRFS[SRM_SRFS_CODE_UBOUND+1])(SRM_ORM_Code orm_dst);

extern SRM_RT_Code (*Impl_bdRTforSRFS[SRM_SRFS_CODE_UBOUND+1])(SRM_RT_Code rt_dst);

extern Impl_Status (*Impl_validcoord3DSRFS[SRM_SRFS_CODE_UBOUND+1])
(
    Impl_Private_Data pdat,
    SRM_Long_Float    v_coord[3]
);

extern SRM_Integer (*Impl_get_frame_idSRFS[SRM_SRFS_CODE_UBOUND+1])(void* api_templ_param_struct_ptr);

extern SRM_Integer (*Impl_naturalSetMember[SRM_SRFS_CODE_UBOUND+1])( Impl_Private_Data pdat, SRM_Long_Float coordinate[3]);

extern void* (*Impl_allocStandardsrf[SRM_SRF_CODE_UBOUND+1])( SRM_RT_Code rt_code );

extern SRM_SRFT_Code (*Impl_Standardsrf_templ_code[SRM_SRF_CODE_UBOUND+1])();
#endif
