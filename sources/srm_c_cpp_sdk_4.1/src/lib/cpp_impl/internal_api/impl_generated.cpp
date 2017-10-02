/*! @file impl_generated.cpp
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
#include "srm_boundaries.h"
#include "srm_pointscale.h"
#include "srm_com.h"

void* (*Impl_allocsrf[SRM_SRFT_CODE_UBOUND+1])
(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr)=
{
Impl_allocsrfNULL,
Impl_allocsrfNOPARAMS,
Impl_allocsrfLOC_SPACE_RECT_3D,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfLOC_TAN_EUCLIDEAN,
Impl_allocsrfLOC_TAN_AZ_SPHER,
Impl_allocsrfLOC_TAN_CYL,
Impl_allocsrfLOCOCENTRIC_EUCLIDEAN,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS,
Impl_allocsrfMERCATOR,
Impl_allocsrfOBLIQUE_MERCATOR,
Impl_allocsrfTRANSVERSE_MERCATOR,
Impl_allocsrfLAMBERT_CONF_CONIC,
Impl_allocsrfPOLAR_STEREOGRAPHIC,
Impl_allocsrfEQUIDISTANT_CYL,
Impl_allocsrfLOC_SPACE_RECT_2D,
Impl_allocsrfNOPARAMS,
Impl_allocsrfNOPARAMS
};

Impl_Status (*Impl_checkSRFP[SRM_SRFT_CODE_UBOUND+1])(void* input_srfp)=
{
Impl_checksrfNULL,
Impl_checksrfCELESTIOCENTRIC,
Impl_checksrfLOC_SPACE_RECT_3D,
Impl_checksrfCELESTIODETIC,
Impl_checksrfPLANETODETIC,
Impl_checksrfLOC_TAN_EUCLIDEAN,
Impl_checksrfLOC_TAN_AZ_SPHER,
Impl_checksrfLOC_TAN_CYL,
Impl_checksrfLOCOCENTRIC_EUCLIDEAN,
Impl_checksrfCELESTIOMAGNETIC,
Impl_checksrfEQUATORIAL_INERTIAL,
Impl_checksrfSOLAR_ECLIPTIC,
Impl_checksrfSOLAR_EQUATORIAL,
Impl_checksrfSOLAR_MAGNETIC_ECLIPTIC,
Impl_checksrfSOLAR_MAGNETIC_DIPOLE,
Impl_checksrfHELIO_ARIES_ECLIPTIC,
Impl_checksrfHELIO_EARTH_ECLIPTIC,
Impl_checksrfHELIO_EARTH_EQUAT,
Impl_checksrfMERCATOR,
Impl_checksrfOBLIQUE_MERCATOR,
Impl_checksrfTRANSVERSE_MERCATOR,
Impl_checksrfLAMBERT_CONF_CONIC,
Impl_checksrfPOLAR_STEREOGRAPHIC,
Impl_checksrfEQUIDISTANT_CYL,
Impl_checksrfLOC_SPACE_RECT_2D,
Impl_checksrfAZIMUTHAL,
Impl_checksrfPOLAR
};
SRM_SRFT_Code (*Impl_bSRFTforSRFT[SRM_SRFT_CODE_UBOUND+1])()=
{
Impl_bSRFT_NULL,
Impl_bSRFT_CELESTIOCENTRIC,
Impl_bSRFT_LOC_SPACE_RECT_3D,
Impl_bSRFT_CELESTIODETIC,
Impl_bSRFT_PLANETODETIC,
Impl_bSRFT_LOC_TAN_EUCLIDEAN,
Impl_bSRFT_LOC_TAN_AZ_SPHER,
Impl_bSRFT_LOC_TAN_CYL,
Impl_bSRFT_LOCOCENTRIC_EUCLIDEAN,
Impl_bSRFT_CELESTIOMAGNETIC,
Impl_bSRFT_EQUATORIAL_INERTIAL,
Impl_bSRFT_SOLAR_ECLIPTIC,
Impl_bSRFT_SOLAR_EQUATORIAL,
Impl_bSRFT_SOLAR_MAGNETIC_ECLIPTIC,
Impl_bSRFT_SOLAR_MAGNETIC_DIPOLE,
Impl_bSRFT_HELIO_ARIES_ECLIPTIC,
Impl_bSRFT_HELIO_EARTH_ECLIPTIC,
Impl_bSRFT_HELIO_EARTH_EQUAT,
Impl_bSRFT_MERCATOR,
Impl_bSRFT_OBLIQUE_MERCATOR,
Impl_bSRFT_TRANSVERSE_MERCATOR,
Impl_bSRFT_LAMBERT_CONF_CONIC,
Impl_bSRFT_POLAR_STEREOGRAPHIC,
Impl_bSRFT_EQUIDISTANT_CYL,
Impl_bSRFT_LOC_SPACE_RECT_2D,
Impl_bSRFT_AZIMUTHAL,
Impl_bSRFT_POLAR
};

void* (*Impl_bdSRFTforSRFT[SRM_SRFT_CODE_UBOUND+1])(SRM_ORM_Code orm_dst)=
{
Impl_bdSRFT_NULL,
Impl_bdSRFT_CELESTIOCENTRIC,
Impl_bdSRFT_LOC_SPACE_RECT_3D,
Impl_bdSRFT_CELESTIODETIC,
Impl_bdSRFT_PLANETODETIC,
Impl_bdSRFT_LOC_TAN_EUCLIDEAN,
Impl_bdSRFT_LOC_TAN_AZ_SPHER,
Impl_bdSRFT_LOC_TAN_CYL,
Impl_bdSRFT_LOCOCENTRIC_EUCLIDEAN,
Impl_bdSRFT_CELESTIOMAGNETIC,
Impl_bdSRFT_EQUATORIAL_INERTIAL,
Impl_bdSRFT_SOLAR_ECLIPTIC,
Impl_bdSRFT_SOLAR_EQUATORIAL,
Impl_bdSRFT_SOLAR_MAGNETIC_ECLIPTIC ,
Impl_bdSRFT_SOLAR_MAGNETIC_DIPOLE,
Impl_bdSRFT_HELIO_ARIES_ECLIPTIC,
Impl_bdSRFT_HELIO_EARTH_ECLIPTIC,
Impl_bdSRFT_HELIO_EARTH_EQUAT,
Impl_bdSRFT_MERCATOR,
Impl_bdSRFT_OBLIQUE_MERCATOR,
Impl_bdSRFT_TRANSVERSE_MERCATOR,
Impl_bdSRFT_LAMBERT_CONF_CONIC,
Impl_bdSRFT_POLAR_STEREOGRAPHIC,
Impl_bdSRFT_EQUIDISTANT_CYL,
Impl_bdSRFT_LOC_SPACE_RECT_2D,
Impl_bdSRFT_AZIMUTHAL,
Impl_bdSRFT_POLAR,
};

SRM_ORM_Code (*Impl_bdORMforSRFT[SRM_SRFT_CODE_UBOUND+1])(SRM_ORM_Code orm_dst)=
{
Impl_bdORMforSRFT_NULL,
Impl_bdORMforSRFT_CELESTIOCENTRIC,
Impl_bdORMforSRFT_LOC_SPACE_RECT_3D,
Impl_bdORMforSRFT_CELESTIODETIC,
Impl_bdORMforSRFT_PLANETODETIC,
Impl_bdORMforSRFT_LOC_TAN_EUCLIDEAN,
Impl_bdORMforSRFT_LOC_TAN_AZ_SPHER,
Impl_bdORMforSRFT_LOC_TAN_CYL,
Impl_bdORMforSRFT_LOCOCENTRIC_EUCLIDEAN,
Impl_bdORMforSRFT_CELESTIOMAGNETIC,
Impl_bdORMforSRFT_EQUATORIAL_INERTIAL,
Impl_bdORMforSRFT_SOLAR_ECLIPTIC,
Impl_bdORMforSRFT_SOLAR_EQUATORIAL,
Impl_bdORMforSRFT_SOLAR_MAGNETIC_ECLIPTIC ,
Impl_bdORMforSRFT_SOLAR_MAGNETIC_DIPOLE,
Impl_bdORMforSRFT_HELIO_ARIES_ECLIPTIC,
Impl_bdORMforSRFT_HELIO_EARTH_ECLIPTIC,
Impl_bdORMforSRFT_HELIO_EARTH_EQUAT,
Impl_bdORMforSRFT_MERCATOR,
Impl_bdORMforSRFT_OBLIQUE_MERCATOR,
Impl_bdORMforSRFT_TRANSVERSE_MERCATOR,
Impl_bdORMforSRFT_LAMBERT_CONF_CONIC,
Impl_bdORMforSRFT_POLAR_STEREOGRAPHIC,
Impl_bdORMforSRFT_EQUIDISTANT_CYL,
Impl_bdORMforSRFT_LOC_SPACE_RECT_2D,
Impl_bdORMforSRFT_AZIMUTHAL,
Impl_bdORMforSRFT_POLAR
};

SRM_RT_Code  (*Impl_bdRTforSRFT[])(SRM_RT_Code rt_dst)=
{
Impl_bdRTforSRFT_NULL,
Impl_bdRTforSRFT_CELESTIOCENTRIC,
Impl_bdRTforSRFT_LOC_SPACE_RECT_3D,
Impl_bdRTforSRFT_CELESTIODETIC,
Impl_bdRTforSRFT_PLANETODETIC,
Impl_bdRTforSRFT_LOC_TAN_EUCLIDEAN,
Impl_bdRTforSRFT_LOC_TAN_AZ_SPHER,
Impl_bdRTforSRFT_LOC_TAN_CYL,
Impl_bdRTforSRFT_LOCOCENTRIC_EUCLIDEAN,
Impl_bdRTforSRFT_CELESTIOMAGNETIC,
Impl_bdRTforSRFT_EQUATORIAL_INERTIAL,
Impl_bdRTforSRFT_SOLAR_ECLIPTIC,
Impl_bdRTforSRFT_SOLAR_EQUATORIAL,
Impl_bdRTforSRFT_SOLAR_MAGNETIC_ECLIPTIC ,
Impl_bdRTforSRFT_SOLAR_MAGNETIC_DIPOLE,
Impl_bdRTforSRFT_HELIO_ARIES_ECLIPTIC,
Impl_bdRTforSRFT_HELIO_EARTH_ECLIPTIC,
Impl_bdRTforSRFT_HELIO_EARTH_EQUAT,
Impl_bdRTforSRFT_MERCATOR,
Impl_bdRTforSRFT_OBLIQUE_MERCATOR,
Impl_bdRTforSRFT_TRANSVERSE_MERCATOR,
Impl_bdRTforSRFT_LAMBERT_CONF_CONIC,
Impl_bdRTforSRFT_POLAR_STEREOGRAPHIC,
Impl_bdRTforSRFT_EQUIDISTANT_CYL,
Impl_bdRTforSRFT_LOC_SPACE_RECT_2D,
Impl_bdRTforSRFT_AZIMUTHAL,
Impl_bdRTforSRFT_POLAR
};

SRM_Integer (*Impl_sizeof_templ_param[SRM_SRFT_CODE_UBOUND+1])()=
{
Impl_sizeofNULL,
Impl_sizeofCELESTIOCENTRIC,
Impl_sizeofLOC_SPACE_RECT_3D,
Impl_sizeofCELESTIODETIC,
Impl_sizeofPLANETODETIC,
Impl_sizeofLOC_TAN_EUCLIDEAN,
Impl_sizeofLOC_TAN_AZ_SPHER,
Impl_sizeofLOC_TAN_CYL,
Impl_sizeofLOCOCENTRIC_EUCLIDEAN,
Impl_sizeofCELESTIOMAGNETIC,
Impl_sizeofEQUATORIAL_INERTIAL,
Impl_sizeofSOLAR_ECLIPTIC,
Impl_sizeofSOLAR_EQUATORIAL,
Impl_sizeofSOLAR_MAGNETIC_ECLIPTIC ,
Impl_sizeofSOLAR_MAGNETIC_DIPOLE,
Impl_sizeofHELIO_ARIES_ECLIPTIC,
Impl_sizeofHELIO_EARTH_ECLIPTIC,
Impl_sizeofHELIO_EARTH_EQUAT,
Impl_sizeofMERCATOR,
Impl_sizeofOBLIQUE_MERCATOR,
Impl_sizeofTRANSVERSE_MERCATOR,
Impl_sizeofLAMBERT_CONF_CONIC,
Impl_sizeofPOLAR_STEREOGRAPHIC,
Impl_sizeofEQUIDISTANT_CYL,
Impl_sizeofLOC_SPACE_RECT_2D,
Impl_sizeofAZIMUTHAL,
Impl_sizeofPOLAR
};

SRM_Integer (*Impl_sizeof_specific_data[SRM_SRFT_CODE_UBOUND+1])()=
{
Impl_sizeofprivdatNULL,
Impl_sizeofprivdatCELESTIOCENTRIC,
Impl_sizeofprivdatLOC_SPACE_RECT_3D,
Impl_sizeofprivdatCELESTIODETIC,
Impl_sizeofprivdatPLANETODETIC,
Impl_sizeofprivdatLOC_TAN_EUCLIDEAN,
Impl_sizeofprivdatLOC_TAN_AZ_SPHER,
Impl_sizeofprivdatLOC_TAN_CYL,
Impl_sizeofprivdatLOCOCENTRIC_EUCLIDEAN,
Impl_sizeofprivdatCELESTIOMAGNETIC,
Impl_sizeofprivdatEQUATORIAL_INERTIAL,
Impl_sizeofprivdatSOLAR_ECLIPTIC,
Impl_sizeofprivdatSOLAR_EQUATORIAL,
Impl_sizeofprivdatSOLAR_MAGNETIC_ECLIPTIC ,
Impl_sizeofprivdatSOLAR_MAGNETIC_DIPOLE,
Impl_sizeofprivdatHELIO_ARIES_ECLIPTIC,
Impl_sizeofprivdatHELIO_EARTH_ECLIPTIC,
Impl_sizeofprivdatHELIO_EARTH_EQUAT,
Impl_sizeofprivdatMERCATOR,
Impl_sizeofprivdatOBLIQUE_MERCATOR,
Impl_sizeofprivdatTRANSVERSE_MERCATOR,
Impl_sizeofprivdatLAMBERT_CONF_CONIC,
Impl_sizeofprivdatPOLAR_STEREOGRAPHIC,
Impl_sizeofprivdatEQUIDISTANT_CYL,
Impl_sizeofprivdatLOC_SPACE_RECT_2D,
Impl_sizeofprivdatAZIMUTHAL,
Impl_sizeofprivdatPOLAR
};

void* (*Impl_allocsrf_specific_data[SRM_SRFT_CODE_UBOUND+1])(void* impl_SRFP_struct)=
{
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatLOC_TAN_EUCLIDEAN,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatTRANSVERSE_MERCATOR,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE,
Impl_allocprivdatNONE
};


Impl_Status (*Impl_pointscale_templ[SRM_SRFT_CODE_UBOUND+1])
  (void* srf_org,
   Impl_ORM_Data* e_constants,
   SRM_Long_Float cd_coord[3],
   SRM_Long_Float* point_scale
   )=
{
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscaleMERCATOR,
Impl_pointscaleOBLIQUE_MERCATOR,
Impl_pointscaleTRANSVERSE_MERCATOR,
Impl_pointscaleLAMBERT_CONF_CONIC,
Impl_pointscalePOLAR_STEREOGRAPHIC,
Impl_pointscaleEQUIDISTANT_CYL,
Impl_pointscale_undefined,
Impl_pointscale_undefined,
Impl_pointscale_undefined
};

Impl_Status (*Impl_com_templ[SRM_SRFT_CODE_UBOUND+1])
  (void* srf_org,
   Impl_ORM_Data* e_constants,
   SRM_Long_Float cd_coord[3],
   SRM_Long_Float* com_value
   )=
{
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined,
Impl_comMERCATOR,
Impl_comOBLIQUE_MERCATOR,
Impl_comTRANSVERSE_MERCATOR,
Impl_comLAMBERT_CONF_CONIC,
Impl_comPOLAR_STEREOGRAPHIC,
Impl_comEQUIDISTANT_CYL,
Impl_com_undefined,
Impl_com_undefined,
Impl_com_undefined
};


Impl_Status (*Impl_validcoord3DSRFT[SRM_SRFT_CODE_UBOUND+1])
  (Impl_Private_Data pdat,
   SRM_Long_Float v_coord[3]
   )=
{
Impl_validcoord3DIllegal,
Impl_validcoord3DNoRestriction,
Impl_validcoord3DNoRestriction,
Impl_validcoord3DCELESTIODETIC,
Impl_validcoord3DPLANETODETIC,
Impl_validcoord3DNoRestriction,
Impl_validcoordAzSpherical,
Impl_validcoord3DCylindrical,
Impl_validcoord3DNoRestriction,
Impl_validcoordSpherical,
Impl_validcoordSpherical,
Impl_validcoordSpherical,
Impl_validcoordSpherical,
Impl_validcoordSpherical,
Impl_validcoordSpherical,
Impl_validcoordSpherical,
Impl_validcoordSpherical,
Impl_validcoordSpherical,
Impl_validcoord3DMERCATOR_cd,
Impl_validcoord3DOBLIQUE_MERCATOR_cd,
Impl_validcoord3DTRANSVERSE_MERCATOR_cd,
Impl_validcoord3DLAMBERT_CONF_CONIC_cd,
Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd,
Impl_validcoord3DEQUIDISTANT_CYL_cd,
Impl_validcoord3DNoRestriction, // we use 3D for LSR_2D because is make no difference
Impl_validcoord2DAZIMUTHAL,
Impl_validcoord2DPOLAR
};

SRM_Integer (*Impl_get_frame_idSRFT[SRM_SRFT_CODE_UBOUND+1])(void* api_templ_param_struct_ptr)=
{
Impl_get_frame_idNULL,
Impl_get_frame_idCELESTIOCENTRIC,
Impl_get_frame_idLOC_SPACE_RECT_3D,
Impl_get_frame_idCELESTIODETIC,
Impl_get_frame_idPLANETODETIC,
Impl_get_frame_idLOC_TAN_EUCLIDEAN,
Impl_get_frame_idLOC_TAN_AZ_SPHER,
Impl_get_frame_idLOC_TAN_CYL,
Impl_get_frame_idLOCOCENTRIC_EUCLIDEAN,
Impl_get_frame_idCELESTIOMAGNETIC,
Impl_get_frame_idEQUATORIAL_INERTIAL,
Impl_get_frame_idSOLAR_ECLIPTIC,
Impl_get_frame_idSOLAR_EQUATORIAL,
Impl_get_frame_idSOLAR_MAGNETIC_ECLIPTIC ,
Impl_get_frame_idSOLAR_MAGNETIC_DIPOLE,
Impl_get_frame_idHELIO_ARIES_ECLIPTIC,
Impl_get_frame_idHELIO_EARTH_ECLIPTIC,
Impl_get_frame_idHELIO_EARTH_EQUAT,
Impl_get_frame_idMERCATOR,
Impl_get_frame_idOBLIQUE_MERCATOR,
Impl_get_frame_idTRANSVERSE_MERCATOR,
Impl_get_frame_idLAMBERT_CONF_CONIC,
Impl_get_frame_idPOLAR_STEREOGRAPHIC,
Impl_get_frame_idEQUIDISTANT_CYL,
Impl_get_frame_idLOC_SPACE_RECT_2D,
Impl_get_frame_idAZIMUTHAL,
Impl_get_frame_idPOLAR
};

SRM_SRFT_Code (*Impl_SetMembersrf_templ_code[SRM_SRFS_CODE_UBOUND+1])()=
{
Impl_templcodeNULL_SRFS,
Impl_templcodeALABAMA_SPCS,
Impl_templcodeGTRS_GLOB_COORD_SYS,
Impl_templcodeJRPS,
Impl_templcodeLAMBERT_NTF,
Impl_templcodeUNIV_POLAR_STEREOG,
Impl_templcodeUNIV_TRANS_MERC,
Impl_templcodeWISCONSIN_SPCS,
};
void* (*Impl_allocSetMembersrf[SRM_SRFS_CODE_UBOUND+1])
(SRM_SRFS_Code_Info srfs_code_info, SRM_ORM_Code orm, SRM_RT_Code rt)=
{
Impl_allocsrfNULL_SRFS,
Impl_allocsrfALABAMA_SPCS,
Impl_allocsrfGTRS_GLOB_COORD_SYS,
Impl_allocsrfJRPS,
Impl_allocsrfLAMBERT_NTF,
Impl_allocsrfUNIV_POLAR_STEREOG,
Impl_allocsrfUNIV_TRANS_MERC,
Impl_allocsrfWISCONSIN_SPCS,
};
SRM_SRFT_Code (*Impl_bSRFTforSRFS[SRM_SRFS_CODE_UBOUND+1])()=
{
Impl_bSRFT_NULL_SRFS,
Impl_bSRFT_ALABAMA_SPCS,
Impl_bSRFT_GTRS_GLOB_COORD_SYS,
Impl_bSRFT_JRPS,
Impl_bSRFT_LAMBERT_NTF,
Impl_bSRFT_UNIV_POLAR_STEREOG,
Impl_bSRFT_UNIV_TRANS_MERC,
Impl_bSRFT_WISCONSIN_SPCS,
};
void* (*Impl_bdSRFTforSRFS[SRM_SRFS_CODE_UBOUND+1])(SRM_ORM_Code orm_dst)=
{
Impl_bdSRFTforNULL_SRFS,
Impl_bdSRFTforALABAMA_SPCS,
Impl_bdSRFTforGTRS_GLOB_COORD_SYS,
Impl_bdSRFTforJRPS,
Impl_bdSRFTforLAMBERT_NTF,
Impl_bdSRFTforUNIV_POLAR_STEREOG,
Impl_bdSRFTforUNIV_TRANS_MERC,
Impl_bdSRFTforWISCONSIN_SPCS,
};
SRM_ORM_Code (*Impl_bdORMforSRFS[SRM_SRFS_CODE_UBOUND+1])(SRM_ORM_Code orm_dst)=
{
Impl_bdORMforNULL_SRFS,
Impl_bdORMforALABAMA_SPCS,
Impl_bdORMforGTRS_GLOB_COORD_SYS,
Impl_bdORMforJRPS,
Impl_bdORMforLAMBERT_NTF,
Impl_bdORMforUNIV_POLAR_STEREOG,
Impl_bdORMforUNIV_TRANS_MERC,
Impl_bdORMforWISCONSIN_SPCS,
};
SRM_ORM_Code (*Impl_bdRTforSRFS[SRM_SRFS_CODE_UBOUND+1])(SRM_RT_Code rt_dst)=
{
Impl_bdRTforNULL_SRFS,
Impl_bdRTforALABAMA_SPCS,
Impl_bdRTforGTRS_GLOB_COORD_SYS,
Impl_bdRTforJRPS,
Impl_bdRTforLAMBERT_NTF,
Impl_bdRTforUNIV_POLAR_STEREOG,
Impl_bdRTforUNIV_TRANS_MERC,
Impl_bdRTforWISCONSIN_SPCS,
};
Impl_Status (*Impl_validcoord3DSRFS[SRM_SRFS_CODE_UBOUND+1])
             (Impl_Private_Data pdat,
              SRM_Long_Float v_coord[3]
              )=
{
Impl_validcoord3D_NULL_SRFS,
Impl_validcoord3D_ALSP_cd,
Impl_validcoord3D_GCSG_cd_special,
Impl_validcoord3D_JRPS_cd,
Impl_validcoord3D_LNTF_cd,
Impl_validcoord3D_UPST_cd,
Impl_validcoord3D_UTMC_cd,
Impl_validcoord3D_WISP_cd,
};
SRM_Integer (*Impl_get_frame_idSRFS[SRM_SRFS_CODE_UBOUND+1])(void* api_templ_param_struct_ptr)=
{
Impl_get_frameid_NULL_SRFS,
Impl_get_frame_idALSP,
Impl_get_frame_idGCSG,
Impl_get_frame_idJRPS,
Impl_get_frame_idLNTF,
Impl_get_frame_idUPST,
Impl_get_frame_idUTMC,
Impl_get_frame_idWISP,
};
SRM_Integer (*Impl_naturalSetMember[SRM_SRFS_CODE_UBOUND+1])( Impl_Private_Data pdat, SRM_Long_Float coordinate[3])=
{
Impl_naturalSetMemberNULL_SRFS,
Impl_naturalSetMemberALABAMA_SPCS,
Impl_naturalSetMemberGTRS_GLOB_COORD_SYS,
Impl_naturalSetMemberJRPS,
Impl_naturalSetMemberLAMBERT_NTF,
Impl_naturalSetMemberUNIV_POLAR_STEREOG,
Impl_naturalSetMemberUNIV_TRANS_MERC,
Impl_naturalSetMemberWISCONSIN_SPCS,
};

void* (*Impl_allocStandardsrf[SRM_SRF_CODE_UBOUND+1])( SRM_RT_Code rt_code )=
{
Impl_allocsrfNULL_SRF,
Impl_allocsrfBRITISH_NAT_GRID,
Impl_allocsrfBRITISH_OSGRS80_GRID,
Impl_allocsrfDELAWARE_SPCS,
Impl_allocsrfGC_WGS_1984,
Impl_allocsrfGD_AUSTRALIA_1984,
Impl_allocsrfGD_WGS_1984,
Impl_allocsrfGD_N_AMERICAN_1983,
Impl_allocsrfIRISH_GRID,
Impl_allocsrfIRISH_TRANS_MERCATOR,
Impl_allocsrfLAMBERT_93,
Impl_allocsrfLAMBERT_II_WIDE,
Impl_allocsrfMARS_PLANETOCENTRIC_2000,
Impl_allocsrfMARS_PLANETOGRAPHIC_2000,
Impl_allocsrfMARYLAND_SPCS,
};


SRM_SRFT_Code (*Impl_Standardsrf_templ_code[SRM_SRF_CODE_UBOUND+1])()=
{
Impl_templcodeNULL_SRF,
Impl_templcodeBRITISH_NAT_GRID,
Impl_templcodeBRITISH_OSGRS80_GRID,
Impl_templcodeDELAWARE_SPCS,
Impl_templcodeGC_WGS_1984,
Impl_templcodeGD_AUSTRALIA_1984,
Impl_templcodeGD_WGS_1984,
Impl_templcodeGD_N_AMERICAN_1983,
Impl_templcodeIRISH_GRID,
Impl_templcodeIRISH_TRANS_MERCATOR,
Impl_templcodeLAMBERT_93,
Impl_templcodeLAMBERT_II_WIDE,
Impl_templcodeMARS_PLANETOCENTRIC_2000,
Impl_templcodeMARS_PLANETOGRAPHIC_2000,
Impl_templcodeMARYLAND_SPCS,
};
