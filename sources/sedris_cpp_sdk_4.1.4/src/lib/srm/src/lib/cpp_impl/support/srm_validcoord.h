/*! @file srm_validcoord.h
    @author C. Kellough (SRI)

    This file provides prototypes for coordinate validation functions
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

#ifndef _SRM_VALIDCOORD_H
#define _SRM_VALIDCOORD_H

#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_internal.h"

extern Impl_Status Impl_validcoord3D_NULL_SRFS(Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DNoRestriction              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord2DNoRestriction              (Impl_Private_Data pdat, SRM_Long_Float v_coord[2]);
extern Impl_Status Impl_validcoord3DIllegal                    (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);

extern Impl_Status Impl_validcoord2DLSR                        (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DLSR                        (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);

extern Impl_Status Impl_validcoord2DCELESTIODETIC_cs(SRM_Long_Float *longitude, SRM_Long_Float *geodetic_latitude);

extern Impl_Status Impl_validcoord3DCELESTIODETIC              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DPLANETODETIC               (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord2DAZIMUTHAL                  (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DLOC_TAN_CYL                (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord2DPOLAR                      (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DMERCATOR_cd                (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DMERCATOR_native            (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DOBLIQUE_MERCATOR_cd        (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DOBLIQUE_MERCATOR_native    (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DTRANSVERSE_MERCATOR_cd     (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DTRANSVERSE_MERCATOR_native (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DLAMBERT_CONF_CONIC_cd      (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DLAMBERT_CONF_CONIC_native  (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd     (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DPOLAR_STEREOGRAPHIC_native (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DEQUIDISTANT_CYL_cd         (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DEQUIDISTANT_CYL_native     (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);

extern Impl_Status Impl_validcoordSpherical            (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoordAzSpherical          (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3DCylindrical        (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);

extern Impl_Status Impl_validcoord3D_ALSP_cd              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_GCSG                 (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_GCSG_cd_special      (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_UPST_cd              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_UTMC_cd              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_WISP_cd              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_LNTF_cd              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_MTMB_cd              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_MTMP_cd              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
extern Impl_Status Impl_validcoord3D_JRPS_cd              (Impl_Private_Data pdat, SRM_Long_Float v_coord[3]);
#endif
