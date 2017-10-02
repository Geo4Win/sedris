/*! @file srm_predefined_srf.cpp
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


#include <math.h>
#include <signal.h>
#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_internal.h"
#include "srm_validcoord.h"
#include "impl_vos.h"
#include "srm_srfp.h"

/*The following functions allocate standard (predefined SRFs).*/

void* Impl_allocsrfNULL_SRF( SRM_RT_Code rt_code )
{
    /*This is a placeholder that shouldn't get called*/
    return NULL;
}

void* Impl_allocsrfBRITISH_NAT_GRID( SRM_RT_Code rt_code )
{
    SRM_TM_Parameters api_srf;
    SRM_ORM_Code orm=SRM_ORMCOD_OSGB_1936;

    api_srf.origin_longitude=-2.0*SRM_RADIANS_PER_DEGREE;
    api_srf.origin_latitude= 49.0*SRM_RADIANS_PER_DEGREE;
    api_srf.central_scale=      0.9996012717;
    api_srf.false_easting= 400000;  /*Checked against OSGB.gov.uk*/
    api_srf.false_northing=-100000;

    return Impl_allocsrfTRANSVERSE_MERCATOR(orm,rt_code,&api_srf);
}

void* Impl_allocsrfBRITISH_OSGRS80_GRID( SRM_RT_Code rt_code )
{
    SRM_TM_Parameters api_srf;
    SRM_ORM_Code orm=SRM_ORMCOD_ETRS_1989;

    api_srf.origin_longitude=-2.0*SRM_RADIANS_PER_DEGREE;
    api_srf.origin_latitude= 49.0*SRM_RADIANS_PER_DEGREE;
    api_srf.central_scale=      0.9996012717;
    api_srf.false_easting= 400000;  /*Checked against OSGB.gov.uk*/
    api_srf.false_northing=-100000;

    return Impl_allocsrfTRANSVERSE_MERCATOR(orm,rt_code,&api_srf);
}

void* Impl_allocsrfDELAWARE_SPCS( SRM_RT_Code rt_code )
{
    SRM_TM_Parameters api_srf;

    SRM_ORM_Code orm=SRM_ORMCOD_N_AM_1983;

    api_srf.origin_longitude=(-75.0-(25.0/60.0))*SRM_RADIANS_PER_DEGREE;/*-75 degrees 25 minutes*/
    api_srf.origin_latitude=  38.0*SRM_RADIANS_PER_DEGREE;
    api_srf.central_scale=   (1.0- (1.0/200000.0));
    api_srf.false_easting=    200000.0;
    api_srf.false_northing=   0.0;

    return Impl_allocsrfTRANSVERSE_MERCATOR(orm, rt_code,&api_srf);
}

void* Impl_allocsrfGC_WGS_1984( SRM_RT_Code rt_code )
{
    SRM_ORM_Code orm=SRM_ORMCOD_WGS_1984;
    return Impl_allocsrfCELESTIOCENTRIC(orm,rt_code,0);
}

void* Impl_allocsrfGD_AUSTRALIA_1984( SRM_RT_Code rt_code )
{
    SRM_ORM_Code orm=SRM_ORMCOD_AUSTRALIAN_GEOD_1984;

    return Impl_allocsrfCELESTIODETIC(orm,rt_code,0);
}

void* Impl_allocsrfGD_WGS_1984( SRM_RT_Code rt_code )
{
    SRM_ORM_Code orm=SRM_ORMCOD_WGS_1984;

    return Impl_allocsrfCELESTIODETIC(orm,rt_code,0);
}

void* Impl_allocsrfGD_N_AMERICAN_1983( SRM_RT_Code rt_code )
{
    SRM_ORM_Code orm=SRM_ORMCOD_N_AM_1983;

    return Impl_allocsrfCELESTIODETIC(orm,rt_code,0);
}

void* Impl_allocsrfIRISH_GRID( SRM_RT_Code rt_code )
{
    SRM_TM_Parameters api_srf;

    SRM_ORM_Code orm=SRM_ORMCOD_IRELAND_1965;

    api_srf.origin_longitude=-8.0*SRM_RADIANS_PER_DEGREE;
    api_srf.origin_latitude= (53.0+30.0/60.0)*SRM_RADIANS_PER_DEGREE;
    api_srf.central_scale= 1.000035    ;
    api_srf.false_easting= 200000.0;
    api_srf.false_northing=250000.0;

    return Impl_allocsrfTRANSVERSE_MERCATOR(orm,rt_code,&api_srf);
}


void* Impl_allocsrfIRISH_TRANS_MERCATOR( SRM_RT_Code rt_code )
{
    SRM_TM_Parameters api_srf;

    SRM_ORM_Code orm=SRM_ORMCOD_ETRS_1989;
    api_srf.origin_longitude=-8.0*SRM_RADIANS_PER_DEGREE;
    api_srf.origin_latitude= (53.0+ (30.0/60.0) )*SRM_RADIANS_PER_DEGREE;
    api_srf.central_scale= 0.999820;
    api_srf.false_easting= 600000.0;
    api_srf.false_northing=750000.0;

    return Impl_allocsrfTRANSVERSE_MERCATOR(orm,rt_code,&api_srf);
}

void* Impl_allocsrfLAMBERT_93( SRM_RT_Code rt_code )
{
    SRM_LCC_Parameters api_srf;

    SRM_ORM_Code orm=SRM_ORMCOD_RGF_1993;

    api_srf.origin_longitude=3.0*SRM_RADIANS_PER_DEGREE;
    api_srf.origin_latitude=(46.0+(30.0/60.0))*SRM_RADIANS_PER_DEGREE;
    api_srf.latitude1=44.0*SRM_RADIANS_PER_DEGREE;
    api_srf.latitude2=49.0*SRM_RADIANS_PER_DEGREE;
    api_srf.false_easting=700000.0;
    api_srf.false_northing=6600000.0;

    return Impl_allocsrfLAMBERT_CONF_CONIC(orm,rt_code,&api_srf);
}

void* Impl_allocsrfLAMBERT_II_WIDE( SRM_RT_Code rt_code )
{
    SRM_LCC_Parameters api_srf;

    SRM_ORM_Code orm=SRM_ORMCOD_NTF_1896_PM_PARIS;
    api_srf.origin_longitude=0.0*SRM_RADIANS_PER_DEGREE;
    api_srf.origin_latitude=(46.0+(48.0/60.0))*SRM_RADIANS_PER_DEGREE;
    api_srf.latitude1=(45.0+(53.0/60.0)+(56.108/3600.0))*SRM_RADIANS_PER_DEGREE;
    api_srf.latitude2=(47.0+(41.0/60.0)+(45.652/3600.0))*SRM_RADIANS_PER_DEGREE;
    api_srf.false_easting=600000.0;
    api_srf.false_northing=2200000.0;

    return Impl_allocsrfLAMBERT_CONF_CONIC(orm,rt_code,&api_srf);
}

void* Impl_allocsrfMARYLAND_SPCS( SRM_RT_Code rt_code )
{
    SRM_LCC_Parameters api_srf;
    SRM_ORM_Code orm=SRM_ORMCOD_N_AM_1983;
    api_srf.origin_longitude=-77.0*SRM_RADIANS_PER_DEGREE;
    api_srf.origin_latitude=(37.0+(40.0/60.0))*SRM_RADIANS_PER_DEGREE;
    api_srf.latitude1=(38.0+18.0/60)*SRM_RADIANS_PER_DEGREE;
    api_srf.latitude2=(39.0+(27.0/60.0))*SRM_RADIANS_PER_DEGREE;
    api_srf.false_easting=400000.0;
    api_srf.false_northing=0.0;

    return Impl_allocsrfLAMBERT_CONF_CONIC(orm,rt_code,&api_srf);
}


void* Impl_allocsrfMARS_PLANETOCENTRIC_2000( SRM_RT_Code rt_code )
{
    SRM_ORM_Code orm=SRM_ORMCOD_MARS_SPHERE_2000;

    return Impl_allocsrfCELESTIODETIC(orm,rt_code,0);
}

void* Impl_allocsrfMARS_PLANETOGRAPHIC_2000( SRM_RT_Code rt_code )
{
    SRM_ORM_Code orm=SRM_ORMCOD_MARS_2000;

    return Impl_allocsrfPLANETODETIC(orm,rt_code,0);
}

/*The following group of functions returns the SRFT code for a given
  predefined standard SRF
*/

SRM_SRFT_Code Impl_templcodeNULL_SRF()
{
    return 0;
    /*placehoulder that shouldn't get called*/
}

SRM_SRFT_Code Impl_templcodeBRITISH_NAT_GRID()
{
    return SRM_SRFTCOD_TRANSVERSE_MERCATOR;
}

SRM_SRFT_Code Impl_templcodeBRITISH_OSGRS80_GRID()
{
    return SRM_SRFTCOD_TRANSVERSE_MERCATOR;
}

SRM_SRFT_Code Impl_templcodeDELAWARE_SPCS()
{
    return SRM_SRFTCOD_TRANSVERSE_MERCATOR;
}

SRM_SRFT_Code Impl_templcodeGC_WGS_1984()
{
    return SRM_SRFTCOD_CELESTIOCENTRIC;
}

SRM_SRFT_Code Impl_templcodeGD_AUSTRALIA_1984()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_templcodeGD_WGS_1984()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}
SRM_SRFT_Code Impl_templcodeGD_N_AMERICAN_1983()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}
SRM_SRFT_Code Impl_templcodeIRISH_GRID()
{
    return SRM_SRFTCOD_TRANSVERSE_MERCATOR;
}
SRM_SRFT_Code Impl_templcodeIRISH_TRANS_MERCATOR()
{
    return SRM_SRFTCOD_TRANSVERSE_MERCATOR;
}
SRM_SRFT_Code Impl_templcodeLAMBERT_93()
{
    return SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC;
}
SRM_SRFT_Code Impl_templcodeLAMBERT_II_WIDE()
{
    return SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC;
}
SRM_SRFT_Code Impl_templcodeMARYLAND_SPCS()
{
    return SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC;
}

SRM_SRFT_Code Impl_templcodeMARS_PLANETOCENTRIC_2000()
{
    return SRM_SRFTCOD_CELESTIODETIC;
}

SRM_SRFT_Code Impl_templcodeMARS_PLANETOGRAPHIC_2000()
{
    return SRM_SRFTCOD_PLANETODETIC;
}
