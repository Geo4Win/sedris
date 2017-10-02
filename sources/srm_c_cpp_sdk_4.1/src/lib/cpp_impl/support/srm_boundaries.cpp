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
#include<cstdlib>
#else
#include<stdio.h>
#endif

#include <math.h>
#include <signal.h>
#include "srm_validcoord.h"

void *Impl_bdSRFT_NULL(SRM_ORM_Code orm_dst)
{
    /*It is an internal error if this gets called*/
    return 0;
}

void *Impl_bdSRFT_CELESTIOCENTRIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_LOC_SPACE_RECT_3D(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_LOC_SPACE_RECT_2D(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_CELESTIODETIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_PLANETODETIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_LOC_TAN_EUCLIDEAN(SRM_ORM_Code orm_dst)
{
    return 0; /* $$$ What to do here? */
}

void *Impl_bdSRFT_LOC_TAN_AZ_SPHER(SRM_ORM_Code orm_dst)
{
    return 0; /* $$$ What to do here? */
}

void *Impl_bdSRFT_AZIMUTHAL(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_LOC_TAN_CYL(SRM_ORM_Code orm_dst)
{
    return 0; /* $$$ What to do here? */
}

void *Impl_bdSRFT_POLAR(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_CELESTIOMAGNETIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_EQUATORIAL_INERTIAL(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_SOLAR_ECLIPTIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_SOLAR_EQUATORIAL(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_SOLAR_MAGNETIC_ECLIPTIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_SOLAR_MAGNETIC_DIPOLE(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_HELIO_ARIES_ECLIPTIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_HELIO_EARTH_ECLIPTIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_HELIO_EARTH_EQUAT(SRM_ORM_Code orm_dst)
{
    return 0;
}


void *Impl_bdSRFT_MERCATOR(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_OBLIQUE_MERCATOR(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_TRANSVERSE_MERCATOR(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_LAMBERT_CONF_CONIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_POLAR_STEREOGRAPHIC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFT_EQUIDISTANT_CYL(SRM_ORM_Code orm_dst)
{
    return 0;
}
void *Impl_bdSRFT_LOCOCENTRIC_EUCLIDEAN(SRM_ORM_Code orm_dst)
{
    return 0;
}
/*End of functions designed to provide SRF parameters for boundary defintion SRFT's*/



/* Template Parameters Functions: Needed 1 per SRF set
 * These functions return the srf parameters of
 * the zone boundary defining SRF for a given SRF set
 * A function must be added to the array below each time an
 * SRF set is added to the API.
 *
 * Zero is returned in the cases of unimplemented.
 *
 */
void *Impl_bdSRFTforNULL_SRFS(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFTforALABAMA_SPCS(SRM_ORM_Code orm_dst)
{
    return 0;
}
void *Impl_bdSRFTforGTRS_GLOB_COORD_SYS(SRM_ORM_Code orm_dst)
{
    return 0;
}
void *Impl_bdSRFTforLAMBERT_NTF(SRM_ORM_Code orm_dst)
{
    return 0;
}
void *Impl_bdSRFTforUNIV_POLAR_STEREOG(SRM_ORM_Code orm_dst)
{
    return 0;
}
void *Impl_bdSRFTforUNIV_TRANS_MERC(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFTforWISCONSIN_SPCS(SRM_ORM_Code orm_dst)
{
    return 0;
}

void *Impl_bdSRFTforJRPS(SRM_ORM_Code orm_dst)
{
    return 0;
}
/*End of functions describing the boundary deifnition SRFT for a given SRFS*/


/*Beginning of functions that return the ORM for validating the given SRF
*/
SRM_ORM_Code  Impl_bdORMforNULL_SRFS           (SRM_ORM_Code orm_dst) { return orm_dst;}
SRM_ORM_Code  Impl_bdORMforALABAMA_SPCS        (SRM_ORM_Code orm_dst) { return orm_dst;}
SRM_ORM_Code  Impl_bdORMforGTRS_GLOB_COORD_SYS (SRM_ORM_Code orm_dst) { return SRM_ORMCOD_WGS_1984;}
SRM_ORM_Code  Impl_bdORMforLAMBERT_NTF         (SRM_ORM_Code orm_dst) { return orm_dst;}
SRM_ORM_Code  Impl_bdORMforUNIV_POLAR_STEREOG  (SRM_ORM_Code orm_dst) { return orm_dst;}
SRM_ORM_Code  Impl_bdORMforUNIV_TRANS_MERC     (SRM_ORM_Code orm_dst) { return orm_dst;}
SRM_ORM_Code  Impl_bdORMforWISCONSIN_SPCS      (SRM_ORM_Code orm_dst) { return orm_dst;}
SRM_ORM_Code  Impl_bdORMforJRPS                (SRM_ORM_Code orm_dst){ return orm_dst;}
/*End of functions returning the correct orm for validating a given SRFS*/
/************************************************************************/

/*Functions returning boundary definition RT for a given SRFS*/
SRM_RT_Code  Impl_bdRTforNULL_SRFS           (SRM_RT_Code rt_dst){ return rt_dst;}
SRM_RT_Code  Impl_bdRTforALABAMA_SPCS        (SRM_RT_Code rt_dst){ return rt_dst;}
SRM_RT_Code  Impl_bdRTforGTRS_GLOB_COORD_SYS (SRM_RT_Code rt_dst){ return SRM_RTCOD_WGS_1984_IDENTITY;}
SRM_RT_Code  Impl_bdRTforLAMBERT_NTF         (SRM_RT_Code rt_dst){ return rt_dst;}
SRM_RT_Code  Impl_bdRTforUNIV_POLAR_STEREOG  (SRM_RT_Code rt_dst){ return rt_dst;}
SRM_RT_Code  Impl_bdRTforUNIV_TRANS_MERC     (SRM_RT_Code rt_dst){ return rt_dst;}
SRM_RT_Code  Impl_bdRTforWISCONSIN_SPCS      (SRM_RT_Code rt_dst){ return rt_dst;}
SRM_RT_Code  Impl_bdRTforJRPS                (SRM_RT_Code rt_dst){ return rt_dst;}
/*End Functions returning boundary definition RT for a given SRFS*/
/*************************************************************************/

/* Template Code functions which define the boundary SRFT
   for a given SRFT*/

SRM_SRFT_Code Impl_bSRFT_NULL()
{
  /*If this routine ever gets called it is a definite error --cdk 06302004*/
    return 0;
}

SRM_SRFT_Code Impl_bSRFT_CELESTIOCENTRIC()
{
    return SRM_SRFTCOD_CELESTIOCENTRIC;
}

SRM_SRFT_Code Impl_bSRFT_LOC_SPACE_RECT_3D()
{
    return SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D;
}

SRM_SRFT_Code Impl_bSRFT_LOC_SPACE_RECT_2D()
{
    return SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D;
}

SRM_SRFT_Code Impl_bSRFT_CELESTIODETIC()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_bSRFT_PLANETODETIC()
{
    return SRM_SRFTCOD_PLANETODETIC;
}

SRM_SRFT_Code Impl_bSRFT_LOC_TAN_EUCLIDEAN()
{
    return SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN;
}

SRM_SRFT_Code Impl_bSRFT_LOC_TAN_AZ_SPHER()
{
    return SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL;
}

SRM_SRFT_Code Impl_bSRFT_AZIMUTHAL()
{
    return SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D;
}

SRM_SRFT_Code Impl_bSRFT_LOC_TAN_CYL()
{
  /*!\bug.  I'm not quite sure how to forward map all of
    this and I get the impression that it will be lots easier
    when we get the next version of the generated code.  I'm
    leaving it alone for now.
    CDK April 20, 2004
  */
    return SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL;
}

SRM_SRFT_Code Impl_bSRFT_POLAR()
{
    return SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D;
}

SRM_SRFT_Code Impl_bSRFT_CELESTIOMAGNETIC()
{
    return SRM_SRFTCOD_CELESTIOMAGNETIC;
}

SRM_SRFT_Code Impl_bSRFT_EQUATORIAL_INERTIAL()
{
    return SRM_SRFTCOD_EQUATORIAL_INERTIAL;
}

SRM_SRFT_Code Impl_bSRFT_SOLAR_ECLIPTIC()
{
    return SRM_SRFTCOD_SOLAR_ECLIPTIC;
}

SRM_SRFT_Code Impl_bSRFT_SOLAR_EQUATORIAL()
{
    return SRM_SRFTCOD_SOLAR_EQUATORIAL;
}

SRM_SRFT_Code Impl_bSRFT_SOLAR_MAGNETIC_DIPOLE()
{
    return SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE;
}

SRM_SRFT_Code Impl_bSRFT_SOLAR_MAGNETIC_ECLIPTIC()
{
    return SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC;
}

SRM_SRFT_Code Impl_bSRFT_HELIO_ARIES_ECLIPTIC()
{
    return SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC;
}

SRM_SRFT_Code Impl_bSRFT_HELIO_EARTH_ECLIPTIC()
{
    return SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC;
}

SRM_SRFT_Code Impl_bSRFT_HELIO_EARTH_EQUAT()
{
    return SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL;
}

SRM_SRFT_Code Impl_bSRFT_MERCATOR()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_bSRFT_OBLIQUE_MERCATOR()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_bSRFT_TRANSVERSE_MERCATOR()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_bSRFT_LAMBERT_CONF_CONIC()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_bSRFT_POLAR_STEREOGRAPHIC()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_bSRFT_EQUIDISTANT_CYL()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_bSRFT_LOCOCENTRIC_EUCLIDEAN()
{
    return SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D;
}
/*End of functions defining boundary SRFT for SRFTs
******************************************************/


/*Template Code Functions: Needed 1 per SRF set
* These functions return the template code of
* the SRF defining the zone boundaries for a given SRF set
* A function must be added to the array below each time an
* SRF set is added to the API.
*/
SRM_SRFT_Code Impl_bSRFT_NULL_SRFS()
{
    return 0;
}

SRM_SRFT_Code Impl_bSRFT_ALABAMA_SPCS()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}
SRM_SRFT_Code Impl_bSRFT_GTRS_GLOB_COORD_SYS()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}
SRM_SRFT_Code Impl_bSRFT_LAMBERT_NTF()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}
SRM_SRFT_Code Impl_bSRFT_UNIV_POLAR_STEREOG()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}
SRM_SRFT_Code Impl_bSRFT_UNIV_TRANS_MERC()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}
SRM_SRFT_Code Impl_bSRFT_WISCONSIN_SPCS()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}
SRM_SRFT_Code Impl_bSRFT_JRPS()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

/*End of functions for boundary defintion of SRF SETS
******************************************************/

/******************************************************/
/*Beginning of fucntions defining ORM for a given SRFT*/


SRM_ORM_Code Impl_bdORMforSRFT_NULL(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}
SRM_ORM_Code Impl_bdORMforSRFT_CELESTIOCENTRIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_LOC_SPACE_RECT_3D(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_LOC_SPACE_RECT_2D(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_CELESTIODETIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_PLANETODETIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_LOC_TAN_EUCLIDEAN(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_LOC_TAN_AZ_SPHER(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_AZIMUTHAL(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_LOC_TAN_CYL(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_POLAR(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_CELESTIOMAGNETIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_EQUATORIAL_INERTIAL(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_SOLAR_ECLIPTIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_SOLAR_EQUATORIAL(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_SOLAR_MAGNETIC_ECLIPTIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_SOLAR_MAGNETIC_DIPOLE(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_HELIO_ARIES_ECLIPTIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_HELIO_EARTH_ECLIPTIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_HELIO_EARTH_EQUAT(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_MERCATOR(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_OBLIQUE_MERCATOR(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_TRANSVERSE_MERCATOR(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_LAMBERT_CONF_CONIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_POLAR_STEREOGRAPHIC(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_EQUIDISTANT_CYL(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}

SRM_ORM_Code Impl_bdORMforSRFT_LOCOCENTRIC_EUCLIDEAN(SRM_ORM_Code orm_dst)
{
    return orm_dst;
}


/*End of functions defining ORM for SRFTs
******************************************************/


/******************************************************/
/*Beginning of functions defining RT for a given SRFT*/

SRM_RT_Code Impl_bdRTforSRFT_NULL(SRM_RT_Code rt_dst)
{
    return SRM_RTCOD_UNSPECIFIED;
}

SRM_RT_Code Impl_bdRTforSRFT_CELESTIOCENTRIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_LOC_SPACE_RECT_3D(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_LOC_SPACE_RECT_2D(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_CELESTIODETIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_PLANETODETIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_LOC_TAN_EUCLIDEAN(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_LOC_TAN_AZ_SPHER(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_AZIMUTHAL(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_LOC_TAN_CYL(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_POLAR(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_CELESTIOMAGNETIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_EQUATORIAL_INERTIAL(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_SOLAR_ECLIPTIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_SOLAR_EQUATORIAL(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_SOLAR_MAGNETIC_ECLIPTIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_SOLAR_MAGNETIC_DIPOLE(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_HELIO_ARIES_ECLIPTIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_HELIO_EARTH_ECLIPTIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_HELIO_EARTH_EQUAT(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_MERCATOR(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_OBLIQUE_MERCATOR(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_TRANSVERSE_MERCATOR(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_LAMBERT_CONF_CONIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_POLAR_STEREOGRAPHIC(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_EQUIDISTANT_CYL(SRM_RT_Code rt_dst)
{
    return rt_dst;
}

SRM_RT_Code Impl_bdRTforSRFT_LOCOCENTRIC_EUCLIDEAN(SRM_RT_Code rt_dst)
{
    return rt_dst;
}
/*End of functions defining RT for SRFTs
******************************************************/
