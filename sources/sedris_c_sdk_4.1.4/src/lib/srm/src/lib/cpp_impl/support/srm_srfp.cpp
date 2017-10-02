/*! @file srm_srfp.cpp
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
#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_internal.h"
#include "srm_validcoord.h"
#include "impl_vos.h"
#include "srm_srfp.h"

/*These functions determine the size of the SRFP struct for a for a given SRFT*/

SRM_Integer Impl_sizeofNULL()           {      return 0;}
SRM_Integer Impl_sizeofCELESTIOCENTRIC() {     return sizeof(IMPL_CELESTIOCENTRIC_SRFP);}
SRM_Integer Impl_sizeofLOC_SPACE_RECT_3D() {   return sizeof(IMPL_LSR3D_SRFP);}
SRM_Integer Impl_sizeofLOC_SPACE_RECT_2D() {   return sizeof(IMPL_LSR2D_SRFP);}
SRM_Integer Impl_sizeofCELESTIODETIC() {       return sizeof(IMPL_CELESTIODETIC_SRFP);}
SRM_Integer Impl_sizeofPLANETODETIC() {        return sizeof(IMPL_PLANETODETIC_SRFP);}
SRM_Integer Impl_sizeofLOC_TAN_EUCLIDEAN() {   return sizeof(IMPL_LOC_TAN_EUCLIDEAN_SRFP);}
SRM_Integer Impl_sizeofLOC_TAN_AZ_SPHER() {    return sizeof(IMPL_LOC_TAN_AZ_SPHER_SRFP);}
SRM_Integer Impl_sizeofAZIMUTHAL() {           return sizeof(IMPL_AZIMUTHAL_SRFP);}
SRM_Integer Impl_sizeofLOC_TAN_CYL() {         return sizeof(IMPL_LOC_TAN_CYL_SRFP);}
SRM_Integer Impl_sizeofPOLAR() {               return sizeof(IMPL_POLAR_SRFP);}
SRM_Integer Impl_sizeofCELESTIOMAGNETIC() {    return sizeof(IMPL_CELESTIOMAGNETIC_SRFP);}
SRM_Integer Impl_sizeofEQUATORIAL_INERTIAL() { return sizeof(IMPL_EQUATORIAL_INERTIAL_SRFP);}
SRM_Integer Impl_sizeofSOLAR_ECLIPTIC() {      return sizeof(IMPL_SOLAR_ECLIPTIC_SRFP);}
SRM_Integer Impl_sizeofSOLAR_EQUATORIAL() {    return sizeof(IMPL_SOLAR_EQUATORIAL_SRFP);}
SRM_Integer Impl_sizeofSOLAR_MAGNETIC_ECLIPTIC() { return sizeof(IMPL_SOLAR_MAGNETIC_ECLIPTIC_SRFP);}
SRM_Integer Impl_sizeofSOLAR_MAGNETIC_DIPOLE() {  return sizeof(IMPL_SOLAR_MAGNETIC_DIPOLE_SRFP);}
SRM_Integer Impl_sizeofHELIO_ARIES_ECLIPTIC() {return sizeof(IMPL_HELIO_ARIES_ECLIPTIC_SRFP);}
SRM_Integer Impl_sizeofHELIO_EARTH_ECLIPTIC() {return sizeof(IMPL_HELIO_EARTH_ECLIPTIC_SRFP);}
SRM_Integer Impl_sizeofHELIO_EARTH_EQUAT() {   return sizeof(IMPL_HELIO_EARTH_EQUAT_SRFP);}
SRM_Integer Impl_sizeofMERCATOR() {            return sizeof(IMPL_MERCATOR_SRFP);}
SRM_Integer Impl_sizeofOBLIQUE_MERCATOR() {    return sizeof(IMPL_OBLIQUE_MERCATOR_SRFP);}
SRM_Integer Impl_sizeofTRANSVERSE_MERCATOR() { return sizeof(IMPL_TRANSVERSE_MERCATOR_SRFP);}
SRM_Integer Impl_sizeofLAMBERT_CONF_CONIC() {  return sizeof(IMPL_LAMBERT_CONF_CONIC_SRFP);}
SRM_Integer Impl_sizeofPOLAR_STEREOGRAPHIC() { return sizeof(IMPL_POLAR_STEREOGRAPHIC_SRFP);}
SRM_Integer Impl_sizeofEQUIDISTANT_CYL() {     return sizeof(IMPL_EQUIDISTANT_CYL_SRFP);}
SRM_Integer Impl_sizeofLOCOCENTRIC_EUCLIDEAN() { return sizeof(IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP);}





/*The following group of functions allocates SRFs given a void pointer
to the necessary parameter structure.  Each function assumes that it
receives a correctly typed parameters structure and this is guaranteed
by indexing the array with the proper template code below.
*/
void* Impl_allocsrfNULL(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr)
{
  /*If this get called ever then it is an internal error  --cdk 06302004*/
    return 0;
}


void* Impl_allocsrfNOPARAMS(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,sizeof(IMPL_NOPARAM_SRFP) );

    if (new_srf_ptr!=0)
    {
        IMPL_NOPARAM_SRFP* my_new_srf_ptr= (IMPL_NOPARAM_SRFP*)new_srf_ptr;

        my_new_srf_ptr->orm=orm;
        my_new_srf_ptr->rt=rt;
    }
    return new_srf_ptr;
}



void* Impl_allocsrfLOC_SPACE_RECT_3D(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofLOC_SPACE_RECT_3D());
    IMPL_LSR3D_SRFP* my_srf_ptr=(IMPL_LSR3D_SRFP*) new_srf_ptr;

    if(my_srf_ptr!=0)
    {
        SRM_LSR_3D_Parameters* api_srf_ptr=(SRM_LSR_3D_Parameters*)
          api_templ_param_struct_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->up_direction=api_srf_ptr->up_direction;
        my_srf_ptr->forward_direction=api_srf_ptr->forward_direction;
    }
    return new_srf_ptr;
}
void* Impl_allocsrfLOC_SPACE_RECT_2D(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofLOC_SPACE_RECT_3D());
    IMPL_LSR2D_SRFP* my_srf_ptr=(IMPL_LSR2D_SRFP*) new_srf_ptr;

    if (my_srf_ptr!=0)
    {
        SRM_LSR_2D_Parameters* api_srf_ptr=(SRM_LSR_2D_Parameters*)
          api_templ_param_struct_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->forward_direction=api_srf_ptr->forward_direction;
    }
    return new_srf_ptr;
}

void* Impl_allocsrfLOCOCENTRIC_EUCLIDEAN(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofLOCOCENTRIC_EUCLIDEAN());
    IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP* my_srf_ptr=(IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP*) new_srf_ptr;

    if(my_srf_ptr!=0)
    {
        SRM_LCE_3D_Parameters* api_srf_ptr=(SRM_LCE_3D_Parameters*)
           api_templ_param_struct_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        for (int i=0; i<3; i++)
        {
            my_srf_ptr->lococentre[i]=api_srf_ptr->lococentre[i];
            my_srf_ptr->primary_axis[i]=api_srf_ptr->primary_axis[i];
            my_srf_ptr->secondary_axis[i]=api_srf_ptr->secondary_axis[i];
        }
    }
    return new_srf_ptr;
}

void* Impl_allocsrfLOC_TAN_EUCLIDEAN(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofLOC_TAN_EUCLIDEAN());

    if(new_srf_ptr!=0)
    {
        SRM_LTSE_Parameters *api_srf_ptr=(SRM_LTSE_Parameters*)api_templ_param_struct_ptr;
        IMPL_LOC_TAN_EUCLIDEAN_SRFP* my_srf_ptr= (IMPL_LOC_TAN_EUCLIDEAN_SRFP*)new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->geodetic_longitude=api_srf_ptr->geodetic_longitude;
        my_srf_ptr->geodetic_latitude=api_srf_ptr->geodetic_latitude;
        my_srf_ptr->azimuth=api_srf_ptr->azimuth;
        my_srf_ptr->x_false_origin=api_srf_ptr->x_false_origin;
        my_srf_ptr->y_false_origin=api_srf_ptr->y_false_origin;
        my_srf_ptr->height_offset=api_srf_ptr->height_offset;
    }
    return new_srf_ptr;
}

void* Impl_allocsrfLOC_TAN_AZ_SPHER(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofLOC_TAN_AZ_SPHER());

    if (new_srf_ptr!=0)
    {
        SRM_Local_Tangent_Parameters* api_srf_ptr=
          (SRM_Local_Tangent_Parameters*)api_templ_param_struct_ptr;
        IMPL_LOC_TAN_AZ_SPHER_SRFP*  my_srf_ptr=(IMPL_LOC_TAN_AZ_SPHER_SRFP*) new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->geodetic_longitude=api_srf_ptr->geodetic_longitude;
        my_srf_ptr->geodetic_latitude=api_srf_ptr->geodetic_latitude;
        my_srf_ptr->azimuth=api_srf_ptr->azimuth;
        my_srf_ptr->height_offset=api_srf_ptr->height_offset;
    }
    return new_srf_ptr;
}

void* Impl_allocsrfLOC_TAN_CYL(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofLOC_TAN_CYL());

    if (new_srf_ptr!=0)
    {
        SRM_Local_Tangent_Parameters* api_srf_ptr=(SRM_Local_Tangent_Parameters*)
          api_templ_param_struct_ptr;
        IMPL_LOC_TAN_CYL_SRFP* my_srf_ptr=(IMPL_LOC_TAN_CYL_SRFP*) new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->geodetic_longitude=api_srf_ptr->geodetic_longitude;
        my_srf_ptr->geodetic_latitude=api_srf_ptr->geodetic_latitude;
        my_srf_ptr->azimuth=api_srf_ptr->azimuth;
        my_srf_ptr->height_offset=api_srf_ptr->height_offset;
    }
    return new_srf_ptr;
}


void* Impl_allocsrfMERCATOR(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofMERCATOR());

    if (new_srf_ptr!=0)
    {
        SRM_M_Parameters* api_srf_ptr=
          (SRM_M_Parameters*)api_templ_param_struct_ptr;
        IMPL_MERCATOR_SRFP* my_srf_ptr=
          (IMPL_MERCATOR_SRFP*) new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->origin_longitude=api_srf_ptr->origin_longitude;
        my_srf_ptr->central_scale=api_srf_ptr->central_scale;
        my_srf_ptr->false_easting=api_srf_ptr->false_easting;
        my_srf_ptr->false_northing=api_srf_ptr->false_northing;
    }
    return new_srf_ptr;
}

void* Impl_allocsrfOBLIQUE_MERCATOR(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofOBLIQUE_MERCATOR());

    if (new_srf_ptr!=0)
    {
        SRM_Oblique_Mercator_Parameters* api_srf_ptr=
          (SRM_Oblique_Mercator_Parameters*)api_templ_param_struct_ptr;
        IMPL_OBLIQUE_MERCATOR_SRFP* my_srf_ptr=(IMPL_OBLIQUE_MERCATOR_SRFP*) new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->longitude1=api_srf_ptr->longitude1;
        my_srf_ptr->latitude1=api_srf_ptr->latitude1;
        my_srf_ptr->longitude2=api_srf_ptr->longitude2;
        my_srf_ptr->latitude2=api_srf_ptr->latitude2;
        my_srf_ptr->central_scale=api_srf_ptr->central_scale;
        my_srf_ptr->false_easting=api_srf_ptr->false_easting;
        my_srf_ptr->false_northing=api_srf_ptr->false_northing;
    }
    return new_srf_ptr;
}

void* Impl_allocsrfTRANSVERSE_MERCATOR(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofTRANSVERSE_MERCATOR());

    if (new_srf_ptr!=0)
    {
        SRM_TM_Parameters* api_srf_ptr=
          (SRM_TM_Parameters*)api_templ_param_struct_ptr;
        IMPL_TRANSVERSE_MERCATOR_SRFP* my_srf_ptr=
          (IMPL_TRANSVERSE_MERCATOR_SRFP*) new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->origin_longitude=api_srf_ptr->origin_longitude;
        my_srf_ptr->origin_latitude=api_srf_ptr->origin_latitude;
        my_srf_ptr->central_scale=api_srf_ptr->central_scale;
        my_srf_ptr->false_easting=api_srf_ptr->false_easting;
        my_srf_ptr->false_northing=api_srf_ptr->false_northing;
    }
    return new_srf_ptr;
}
void* Impl_allocsrfLAMBERT_CONF_CONIC(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofLAMBERT_CONF_CONIC());

    if (new_srf_ptr!=0)
    {
        SRM_LCC_Parameters* api_srf_ptr=
          (SRM_LCC_Parameters*)api_templ_param_struct_ptr;
        IMPL_LAMBERT_CONF_CONIC_SRFP* my_srf_ptr=
          (IMPL_LAMBERT_CONF_CONIC_SRFP*) new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->origin_longitude=api_srf_ptr->origin_longitude;
        my_srf_ptr->origin_latitude=api_srf_ptr->origin_latitude;
        my_srf_ptr->latitude1=api_srf_ptr->latitude1;
        my_srf_ptr->latitude2=api_srf_ptr->latitude2;
        my_srf_ptr->false_easting=api_srf_ptr->false_easting;
        my_srf_ptr->false_northing=api_srf_ptr->false_northing;
    }
    return new_srf_ptr;
}
void* Impl_allocsrfPOLAR_STEREOGRAPHIC(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofPOLAR_STEREOGRAPHIC());

    if (new_srf_ptr!=0)
    {
        SRM_PS_Parameters* api_srf_ptr=
          (SRM_PS_Parameters*)api_templ_param_struct_ptr;
        IMPL_POLAR_STEREOGRAPHIC_SRFP* my_srf_ptr=
          (IMPL_POLAR_STEREOGRAPHIC_SRFP*) new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->polar_aspect=api_srf_ptr->polar_aspect;
        my_srf_ptr->origin_longitude=api_srf_ptr->origin_longitude;
        my_srf_ptr->central_scale=api_srf_ptr->central_scale;
        my_srf_ptr->false_easting=api_srf_ptr->false_easting;
        my_srf_ptr->false_northing=api_srf_ptr->false_northing;
    }
    return new_srf_ptr;
}

void* Impl_allocsrfEQUIDISTANT_CYL(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr)
{
    void* new_srf_ptr=calloc(1,Impl_sizeofEQUIDISTANT_CYL());

    if (new_srf_ptr!=0)
    {
        SRM_EC_Parameters* api_srf_ptr=
          (SRM_EC_Parameters*)api_templ_param_struct_ptr;
        IMPL_EQUIDISTANT_CYL_SRFP* my_srf_ptr=
          (IMPL_EQUIDISTANT_CYL_SRFP*) new_srf_ptr;

        my_srf_ptr->orm=orm;
        my_srf_ptr->rt=rt;
        my_srf_ptr->origin_longitude=api_srf_ptr->origin_longitude;
        my_srf_ptr->central_scale=api_srf_ptr->central_scale;
        my_srf_ptr->false_easting=api_srf_ptr->false_easting;
        my_srf_ptr->false_northing=api_srf_ptr->false_northing;
    }
    return new_srf_ptr;
}
