/*! @file srm_srf_specific_data.cpp
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


#include "srm_types.h"

/*The following group of functions computes the size of the implementation
  private data structures used to represent certain SRF's internally for computational
  purposes*/
extern SRM_Integer Impl_sizeofprivdatNULL();
extern SRM_Integer Impl_sizeofprivdatCELESTIOCENTRIC();
extern SRM_Integer Impl_sizeofprivdatLOC_SPACE_RECT_3D();
extern SRM_Integer Impl_sizeofprivdatLOC_SPACE_RECT_2D();
extern SRM_Integer Impl_sizeofprivdatCELESTIODETIC();
extern SRM_Integer Impl_sizeofprivdatPLANETODETIC();
extern SRM_Integer Impl_sizeofprivdatLOC_TAN_EUCLIDEAN();
extern SRM_Integer Impl_sizeofprivdatLOC_TAN_AZ_SPHER();
extern SRM_Integer Impl_sizeofprivdatAZIMUTHAL();
extern SRM_Integer Impl_sizeofprivdatLOC_TAN_CYL();
extern SRM_Integer Impl_sizeofprivdatPOLAR();
extern SRM_Integer Impl_sizeofprivdatCELESTIOMAGNETIC();
extern SRM_Integer Impl_sizeofprivdatEQUATORIAL_INERTIAL();
extern SRM_Integer Impl_sizeofprivdatSOLAR_ECLIPTIC();
extern SRM_Integer Impl_sizeofprivdatSOLAR_EQUATORIAL();
extern SRM_Integer Impl_sizeofprivdatSOLAR_MAGNETIC_ECLIPTIC();
extern SRM_Integer Impl_sizeofprivdatSOLAR_MAGNETIC_DIPOLE();
extern SRM_Integer Impl_sizeofprivdatHELIO_ARIES_ECLIPTIC();
extern SRM_Integer Impl_sizeofprivdatHELIO_EARTH_ECLIPTIC();
extern SRM_Integer Impl_sizeofprivdatHELIO_EARTH_EQUAT();
extern SRM_Integer Impl_sizeofprivdatMERCATOR();
extern SRM_Integer Impl_sizeofprivdatOBLIQUE_MERCATOR();
extern SRM_Integer Impl_sizeofprivdatTRANSVERSE_MERCATOR();
extern SRM_Integer Impl_sizeofprivdatLAMBERT_CONF_CONIC();
extern SRM_Integer Impl_sizeofprivdatPOLAR_STEREOGRAPHIC();
extern SRM_Integer Impl_sizeofprivdatEQUIDISTANT_CYL();
extern SRM_Integer Impl_sizeofprivdatLOCOCENTRIC_EUCLIDEAN();



/*The following group of functions allocates internal representations
  of SRF's for use by the API.  This was originally created as a mechanism
  for LTP SRF's to store there generating functions as 4x4 matrices
  internally because there are a fair number of computations needed
  to get to this form and because the code for directions and orientations
  needed to be able to get at this information.*/


/*!<This function returns a valid memory location whose
  address can be used in tests as a value to imply that
  the routine had nothing to return as opposed to NULL
  meaning that the routien got some sort of memory error
*/
extern void* Impl_allocprivdatNONE(void* local_SRFP_struct);
extern void* Impl_allocprivdatCELESTIOCENTRIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatLOC_SPACE_RECT_3D(void* local_SRFP_struct);
extern void* Impl_allocprivdatLOC_SPACE_RECT_2D(void* local_SRFP_struct);
extern void* Impl_allocprivdatCELESTIODETIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatLOC_TAN_EUCLIDEAN(void* local_SRFP_struct);
extern void* Impl_allocprivdatLOC_TAN_AZ_SPHER(void* local_SRFP_struct);
extern void* Impl_allocprivdatAZIMUTHAL(void* local_SRFP_struct);
extern void* Impl_allocprivdatLOC_TAN_CYL(void* local_SRFP_struct);
extern void* Impl_allocprivdatPOLAR(void* local_SRFP_struct);
extern void* Impl_allocprivdatCELESTIOMAGNETIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatEQUATORIAL_INERTIAL(void* local_SRFP_struct);
extern void* Impl_allocprivdatSOLAR_ECLIPTIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatSOLAR_EQUATORIAL(void* local_SRFP_struct);
extern void* Impl_allocprivdatSOLAR_MAGNETIC_DIPOLE(void* local_SRFP_struct);
extern void* Impl_allocprivdatSOLAR_MAGNETIC_ECLIPTIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatHELIO_ARIES_ECLIPTIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatHELIO_EARTH_ECLIPTIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatHELIO_EARTH_EQUAT(void* local_SRFP_struct);
extern void* Impl_allocprivdatMERCATOR(void* local_SRFP_struct);
extern void* Impl_allocprivdatOBLIQUE_MERCATOR(void* local_SRFP_struct);
extern void* Impl_allocprivdatTRANSVERSE_MERCATOR(void* local_SRFP_struct);
extern void* Impl_allocprivdatLAMBERT_CONF_CONIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatPOLAR_STEREOGRAPHIC(void* local_SRFP_struct);
extern void* Impl_allocprivdatEQUIDISTANT_CYL(void* local_SRFP_struct);
extern void* Impl_allocprivdatLOCOCENTRIC_EUCLIDEAN(void* local_SRFP_struct);
