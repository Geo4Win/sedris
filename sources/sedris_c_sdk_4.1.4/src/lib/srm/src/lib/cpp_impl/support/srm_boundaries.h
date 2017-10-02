/*! @author Cameron D. Kellough (SRI)
    @file impl_boundaries.h
    Prototypes for functions that define the
    valid boundaries and other parameters for various SRFTs
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

#include <math.h>
#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_internal.h"
#include "srm_validcoord.h"

/*End of functions designed to provide SRF parameters for
  boundary defintion SRFTs*/
extern void* Impl_bdSRFT_NULL(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_CELESTIOCENTRIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_LOC_SPACE_RECT_3D(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_LOC_SPACE_RECT_2D(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_CELESTIODETIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_PLANETODETIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_LOC_TAN_EUCLIDEAN(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_LOC_TAN_AZ_SPHER(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_AZIMUTHAL(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_LOC_TAN_CYL(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_POLAR(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_CELESTIOMAGNETIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_EQUATORIAL_INERTIAL(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_SOLAR_ECLIPTIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_SOLAR_EQUATORIAL(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_SOLAR_MAGNETIC_ECLIPTIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_SOLAR_MAGNETIC_DIPOLE(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_HELIO_ARIES_ECLIPTIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_HELIO_EARTH_ECLIPTIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_HELIO_EARTH_EQUAT(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_MERCATOR(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_OBLIQUE_MERCATOR(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_TRANSVERSE_MERCATOR(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_LAMBERT_CONF_CONIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_POLAR_STEREOGRAPHIC(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_EQUIDISTANT_CYL(SRM_ORM_Code orm_dst);
extern void* Impl_bdSRFT_LOCOCENTRIC_EUCLIDEAN(SRM_ORM_Code orm_dst);
/*End of functions designed to provide SRF parameters for
  boundary defintion SRFTs*/



/*Template Parameters Functions: Needed 1 per SRF set
* These functions return the srf parameters of
* the zone boundary defining SRF for a given SRF set
* A function must be added to the array below each time an
* SRF set is added to the API.
*
*NULL is returned in the cases of unimplemented.
*
*/
extern void * Impl_bdSRFTforNULL_SRFS(SRM_ORM_Code orm_dst);
extern void * Impl_bdSRFTforALABAMA_SPCS(SRM_ORM_Code orm_dst);
extern void * Impl_bdSRFTforGTRS_GLOB_COORD_SYS(SRM_ORM_Code orm_dst);
extern void * Impl_bdSRFTforLAMBERT_NTF(SRM_ORM_Code orm_dst);
extern void * Impl_bdSRFTforUNIV_POLAR_STEREOG(SRM_ORM_Code orm_dst);
extern void * Impl_bdSRFTforUNIV_TRANS_MERC(SRM_ORM_Code orm_dst);
extern void * Impl_bdSRFTforWISCONSIN_SPCS(SRM_ORM_Code orm_dst);
extern void * Impl_bdSRFTforJRPS(SRM_ORM_Code orm_dst);
/*End of functions describing the boundary deifnition SRFT for a given SRFS*/


/*Beginning of functions that return the ORM for validating the given SRF
*/
extern SRM_ORM_Code  Impl_bdORMforNULL_SRFS           (SRM_ORM_Code orm_dst);
extern SRM_ORM_Code  Impl_bdORMforALABAMA_SPCS        (SRM_ORM_Code orm_dst);
extern SRM_ORM_Code  Impl_bdORMforGTRS_GLOB_COORD_SYS (SRM_ORM_Code orm_dst);
extern SRM_ORM_Code  Impl_bdORMforLAMBERT_NTF         (SRM_ORM_Code orm_dst);
extern SRM_ORM_Code  Impl_bdORMforUNIV_POLAR_STEREOG  (SRM_ORM_Code orm_dst);
extern SRM_ORM_Code  Impl_bdORMforUNIV_TRANS_MERC     (SRM_ORM_Code orm_dst);
extern SRM_ORM_Code  Impl_bdORMforWISCONSIN_SPCS      (SRM_ORM_Code orm_dst);
extern SRM_ORM_Code  Impl_bdORMforJRPS                (SRM_ORM_Code orm_dst);
/*End of functions returning the correct ORM for validating a given SRFS*/
/************************************************************************/

/*Functions returning boundary defintion RT for a given SRFS*/
extern SRM_RT_Code  Impl_bdRTforNULL_SRFS           (SRM_RT_Code rt_dst);
extern SRM_RT_Code  Impl_bdRTforALABAMA_SPCS        (SRM_RT_Code rt_dst);
extern SRM_RT_Code  Impl_bdRTforGTRS_GLOB_COORD_SYS (SRM_RT_Code rt_dst);
extern SRM_RT_Code  Impl_bdRTforLAMBERT_NTF         (SRM_RT_Code rt_dst);
extern SRM_RT_Code  Impl_bdRTforUNIV_POLAR_STEREOG  (SRM_RT_Code rt_dst);
extern SRM_RT_Code  Impl_bdRTforUNIV_TRANS_MERC     (SRM_RT_Code rt_dst);
extern SRM_RT_Code  Impl_bdRTforWISCONSIN_SPCS      (SRM_RT_Code rt_dst);
extern SRM_RT_Code  Impl_bdRTforJRPS                (SRM_RT_Code rt_dst);
/*End Functions returning boundary defintion RT for a given SRFS*/
/*************************************************************************/

/* Template Code functions which define the boundary SRFT
   for a given SRFT*/
extern SRM_SRFT_Code Impl_bSRFT_NULL();
extern SRM_SRFT_Code Impl_bSRFT_CELESTIOCENTRIC();
extern SRM_SRFT_Code Impl_bSRFT_LOC_SPACE_RECT_3D();
extern SRM_SRFT_Code Impl_bSRFT_LOC_SPACE_RECT_2D();
extern SRM_SRFT_Code Impl_bSRFT_CELESTIODETIC();
extern SRM_SRFT_Code Impl_bSRFT_PLANETODETIC();
extern SRM_SRFT_Code Impl_bSRFT_LOC_TAN_EUCLIDEAN();
extern SRM_SRFT_Code Impl_bSRFT_LOC_TAN_AZ_SPHER();
extern SRM_SRFT_Code Impl_bSRFT_AZIMUTHAL();
extern SRM_SRFT_Code Impl_bSRFT_LOC_TAN_CYL();
extern SRM_SRFT_Code Impl_bSRFT_POLAR();
extern SRM_SRFT_Code Impl_bSRFT_CELESTIOMAGNETIC();
extern SRM_SRFT_Code Impl_bSRFT_EQUATORIAL_INERTIAL();
extern SRM_SRFT_Code Impl_bSRFT_SOLAR_ECLIPTIC();
extern SRM_SRFT_Code Impl_bSRFT_SOLAR_EQUATORIAL();
extern SRM_SRFT_Code Impl_bSRFT_SOLAR_MAGNETIC_ECLIPTIC();
extern SRM_SRFT_Code Impl_bSRFT_SOLAR_MAGNETIC_DIPOLE();
extern SRM_SRFT_Code Impl_bSRFT_HELIO_ARIES_ECLIPTIC();
extern SRM_SRFT_Code Impl_bSRFT_HELIO_EARTH_ECLIPTIC();
extern SRM_SRFT_Code Impl_bSRFT_HELIO_EARTH_EQUAT();
extern SRM_SRFT_Code Impl_bSRFT_MERCATOR();
extern SRM_SRFT_Code Impl_bSRFT_OBLIQUE_MERCATOR();
extern SRM_SRFT_Code Impl_bSRFT_TRANSVERSE_MERCATOR();
extern SRM_SRFT_Code Impl_bSRFT_LAMBERT_CONF_CONIC();
extern SRM_SRFT_Code Impl_bSRFT_POLAR_STEREOGRAPHIC();
extern SRM_SRFT_Code Impl_bSRFT_EQUIDISTANT_CYL();
extern SRM_SRFT_Code Impl_bSRFT_LOCOCENTRIC_EUCLIDEAN();
/*End of functions defining boundary SRFT for SRFTs
******************************************************/


/*Template Code Functions: Needed 1 per SRF set
* These functions return the template code of
* the SRF defining the zone boundaries for a given SRF set
* A function must be added to the array below each time an
* SRF set is added to the API.
*/
extern SRM_SRFT_Code Impl_bSRFT_NULL_SRFS();
extern SRM_SRFT_Code Impl_bSRFT_ALABAMA_SPCS();
extern SRM_SRFT_Code Impl_bSRFT_GTRS_GLOB_COORD_SYS();
extern SRM_SRFT_Code Impl_bSRFT_LAMBERT_NTF();
extern SRM_SRFT_Code Impl_bSRFT_UNIV_POLAR_STEREOG();
extern SRM_SRFT_Code Impl_bSRFT_UNIV_TRANS_MERC();
extern SRM_SRFT_Code Impl_bSRFT_WISCONSIN_SPCS();
extern SRM_SRFT_Code Impl_bSRFT_JRPS();
/*End of functions for boundary defintion of SRF SETS
******************************************************/

/******************************************************/
/*Beginning of functions defining ORM for a given SRFT*/

extern SRM_ORM_Code Impl_bdORMforSRFT_NULL(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_CELESTIOCENTRIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_LOC_SPACE_RECT_3D(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_LOC_SPACE_RECT_2D(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_CELESTIODETIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_PLANETODETIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_LOC_TAN_EUCLIDEAN(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_LOC_TAN_AZ_SPHER(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_AZIMUTHAL(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_LOC_TAN_CYL(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_POLAR(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_CELESTIOMAGNETIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_EQUATORIAL_INERTIAL(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_SOLAR_ECLIPTIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_SOLAR_EQUATORIAL(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_SOLAR_MAGNETIC_ECLIPTIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_SOLAR_MAGNETIC_DIPOLE(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_HELIO_ARIES_ECLIPTIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_HELIO_EARTH_ECLIPTIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_HELIO_EARTH_EQUAT(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_MERCATOR(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_OBLIQUE_MERCATOR(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_TRANSVERSE_MERCATOR(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_LAMBERT_CONF_CONIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_POLAR_STEREOGRAPHIC(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_EQUIDISTANT_CYL(SRM_ORM_Code orm_dst);
extern SRM_ORM_Code Impl_bdORMforSRFT_LOCOCENTRIC_EUCLIDEAN(SRM_ORM_Code orm_dst);

/*End of functions defining ORM for SRFTs
******************************************************/


/******************************************************/
/*Beginning of functions defining RT for a given SRFT*/

extern SRM_RT_Code Impl_bdRTforSRFT_NULL(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_CELESTIOCENTRIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_LOC_SPACE_RECT_3D(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_LOC_SPACE_RECT_2D(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_CELESTIODETIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_PLANETODETIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_LOC_TAN_EUCLIDEAN(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_LOC_TAN_AZ_SPHER(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_AZIMUTHAL(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_LOC_TAN_CYL(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_POLAR(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_CELESTIOMAGNETIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_EQUATORIAL_INERTIAL(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_SOLAR_ECLIPTIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_SOLAR_EQUATORIAL(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_SOLAR_MAGNETIC_ECLIPTIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_SOLAR_MAGNETIC_DIPOLE(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_HELIO_ARIES_ECLIPTIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_HELIO_EARTH_ECLIPTIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_HELIO_EARTH_EQUAT(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_MERCATOR(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_OBLIQUE_MERCATOR(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_TRANSVERSE_MERCATOR(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_LAMBERT_CONF_CONIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_POLAR_STEREOGRAPHIC(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_EQUIDISTANT_CYL(SRM_RT_Code rt_dst);
extern SRM_RT_Code Impl_bdRTforSRFT_LOCOCENTRIC_EUCLIDEAN(SRM_RT_Code rt_dst);
/*End of functions defining RT for SRFTs
******************************************************/
