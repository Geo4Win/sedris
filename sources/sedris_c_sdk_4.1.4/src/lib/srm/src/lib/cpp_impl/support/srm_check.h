/*! @file srm_check.h
    @author Cameron D. Kellough (SRI)
    Contains prototypes for functions that validate SRF parameters.
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

#ifndef _SRM_CHECK_H
#define _SRM_CHECK_H

#include "srm_internal.h"
#include "orm_rd_struct.h"

extern Impl_Status Impl_checksrfNULL(void* input_srfp);
extern Impl_Status Impl_checksrfCELESTIOCENTRIC(void* input_srfp);
extern Impl_Status Impl_checksrfLOC_SPACE_RECT_3D(void* input_srfp);
extern Impl_Status Impl_checksrfLOC_SPACE_RECT_2D(void* input_srfp);
extern Impl_Status Impl_checksrfCELESTIODETIC(void* input_srfp);
extern Impl_Status Impl_checksrfPLANETODETIC(void* input_srfp);
extern Impl_Status Impl_checksrfLOC_TAN_EUCLIDEAN(void* input_srfp);
extern Impl_Status Impl_checksrfLOC_TAN_AZ_SPHER(void* input_srfp);
extern Impl_Status Impl_checksrfAZIMUTHAL(void* input_srfp);
extern Impl_Status Impl_checksrfLOC_TAN_CYL(void* input_srfp);
extern Impl_Status Impl_checksrfPOLAR(void* input_srfp);
extern Impl_Status Impl_checksrfCELESTIOMAGNETIC(void* input_srfp);
extern Impl_Status Impl_checksrfEQUATORIAL_INERTIAL(void* input_srfp);
extern Impl_Status Impl_checksrfSOLAR_ECLIPTIC(void* input_srfp);
extern Impl_Status Impl_checksrfSOLAR_EQUATORIAL(void* input_srfp);
extern Impl_Status Impl_checksrfSOLAR_MAGNETIC_ECLIPTIC(void* input_srfp);
extern Impl_Status Impl_checksrfSOLAR_MAGNETIC_DIPOLE(void* input_srfp);
extern Impl_Status Impl_checksrfHELIO_ARIES_ECLIPTIC(void* input_srfp);
extern Impl_Status Impl_checksrfHELIO_EARTH_ECLIPTIC(void* input_srfp);
extern Impl_Status Impl_checksrfHELIO_EARTH_EQUAT(void* input_srfp);
extern Impl_Status Impl_checksrfMERCATOR(void* input_srfp);
extern Impl_Status Impl_checksrfOBLIQUE_MERCATOR(void* input_srfp);
extern Impl_Status Impl_checksrfTRANSVERSE_MERCATOR(void* input_srfp);
extern Impl_Status Impl_checksrfLAMBERT_CONF_CONIC(void* input_srfp);
extern Impl_Status Impl_checksrfPOLAR_STEREOGRAPHIC(void* input_srfp);
extern Impl_Status Impl_checksrfEQUIDISTANT_CYL(void* input_srfp);
extern Impl_Status Impl_checksrfLOCOCENTRIC_EUCLIDEAN(void* input_srfp);


/*!< The functions here shall return
  IMPL_SRFSRC,  bad SRF
  IMPL_BADORM   bad ORM
  IMPL_VALID,   no problem
  IMPL_UNIMPLEM unimplemented validation
*/

#endif
