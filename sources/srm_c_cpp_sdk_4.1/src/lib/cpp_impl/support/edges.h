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


#ifndef _INCLUDED_EDGES_H
#define _INCLUDED_EDGES_H

#include "srm_internal.h"
#include "impl_private.h"

void *SRM_set_ec_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);


void *SRM_set_cd_to_ec_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);


void *SRM_set_cc_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_cd_to_cc_constants
(
    Impl_Private_Data *cd_orm,
    Impl_Private_Data *cc_orm
);


void *SRM_set_cc_to_lte_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_lte_to_cc_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);


void *SRM_set_cc_to_lce_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_lce_to_cc_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);


void *SRM_set_cd_to_lcc1_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_lcc1_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);


void *SRM_set_cd_to_lcc2_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);


void *SRM_set_lcc2_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);


void *SRM_set_cd_to_m_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_m_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_cd_to_om_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_om_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_cd_to_tm_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_tm_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);


void *SRM_set_cd_to_ps_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_ps_to_cd_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_dshift_constants
(
    Impl_Private_Data *source_srf_struct,
    Impl_Private_Data *dest_srf_struct
);

void *SRM_set_lsr3D_to_lsr3D_constants
(
    Impl_Private_Data *lsr3d_srf_src,
    Impl_Private_Data *lsr3d_srf_tgt
);


void *SRM_set_lsr2D_to_lsr2D_constants
(
    Impl_Private_Data *lsr2d_srf_src,
    Impl_Private_Data *lsr2d_srf_tgt
);

void *SRM_set_pos2_to_lsr2D_constants
(
    Impl_Private_Data *lsr2d_srf_tgt,
    Impl_Private_Data *unused
);

void *SRM_set_lsr2D_to_pos2_constants
(
    Impl_Private_Data *lsr2d_srf_src,
    Impl_Private_Data *unused
);

void *SRM_set_pos3_to_lsr3D_constants
(
    Impl_Private_Data *lsr3d_srf_tgt,
    Impl_Private_Data *unused
);

void *SRM_set_lsr3D_to_pos3_constants
(
    Impl_Private_Data *lsr3d_srf_src,
    Impl_Private_Data *unused
);

void *SRM_set_pos_to_pos_constants
(
    Impl_Private_Data *unused1,
    Impl_Private_Data *unused2
);

void* SRM_set_LAST_LTSE_constants
(
    Impl_Private_Data *last_srf_src,
    Impl_Private_Data *ltse_srf_tgt
);

void* SRM_set_LTSE_LAST_constants
(
    Impl_Private_Data *ltse_srf_tgt,
    Impl_Private_Data *last_srf_src
);

void* SRM_set_LCTP_LTSE_constants
(
    Impl_Private_Data *last_srf_src,
    Impl_Private_Data *ltse_srf_tgt
);

void* SRM_set_LTSE_LCTP_constants
(
    Impl_Private_Data *ltse_srf_tgt,
    Impl_Private_Data *last_srf_src
);



void SRM_dealloc_ec_to_cd_constants( void* dealloc_me );

void SRM_dealloc_cd_to_ec_constants( void* dealloc_me );

void SRM_dealloc_cc_to_cd_constants( void* dealloc_me );

void SRM_dealloc_cc_to_lte_constants( void* dealloc_me );

void SRM_dealloc_lte_to_cc_constants( void* dealloc_me );

void SRM_dealloc_cc_to_lce_constants( void* dealloc_me );

void SRM_dealloc_lce_to_cc_constants( void* dealloc_me );

void SRM_dealloc_cd_to_lcc1_constants( void* dealloc_me );

void SRM_dealloc_lcc1_to_cd_constants( void* dealloc_me );

void SRM_dealloc_cd_to_lcc2_constants( void* dealloc_me );

void SRM_dealloc_lcc2_to_cd_constants( void* dealloc_me );

void SRM_dealloc_cd_to_m_constants( void* dealloc_me );

void SRM_dealloc_m_to_cd_constants( void* dealloc_me );

void SRM_dealloc_cd_to_om_constants( void* dealloc_me );

void SRM_dealloc_om_to_cd_constants( void* dealloc_me );

void SRM_dealloc_cd_to_tm_constants( void* dealloc_me );

void SRM_dealloc_tm_to_cd_constants( void* dealloc_me );

void SRM_dealloc_cd_to_ps_constants( void* dealloc_me );

void SRM_dealloc_ps_to_cd_constants( void* dealloc_me );

void SRM_dealloc_dshift_constants( void* dealloc_me );

void SRM_dealloc_cd_to_cc_constants( void* dealloc_me );

void SRM_dealloc_lsr3D_to_lsr3D_constants( void* dealloc_me );

void SRM_dealloc_lsr2D_to_lsr2D_constants( void* dealloc_me );

void SRM_dealloc_LAST_to_LTSE_constants(void * dealloc_me );

void SRM_dealloc_LTSE_to_LAST_constants(void * dealloc_me );

void SRM_dealloc_LCTP_to_LTSE_constants(void * dealloc_me );

void SRM_dealloc_LTSE_to_LCTP_constants(void * dealloc_me );

Impl_ORM_Data* Impl_getEconstantsForORMCode ( SRM_ORM_Code orm );

#endif
