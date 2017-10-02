/** @file LocalTangentSpaceEuclidean.cpp
@author David Shen
@brief LocalTangentSpaceEuclidean SRF body.
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


#include "LocalTangentSpaceEuclidean.h"
#include "Celestiocentric.h"
#include "TransverseMercator.h"
#include "Mercator.h"
#include "LococentricEuclidean3D.h"
#include "PolarStereographic.h"
#include "LococentricEuclidean3D.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"
#include "srm_validcoord.h"

#include "srfCache.h"

using namespace srm;

// this macro to get to the SRF private data works for all SRFs have the same
// internal data structure
#define GET_IDATA(_orig) ((Impl_SRF*)(((SRF_LocalTangentSpaceEuclidean*)_orig)->getImpl()))->private_data

SRF_LocalTangentSpaceEuclidean::SRF_LocalTangentSpaceEuclidean(void *impl) : BaseSRF_WithTangentPlaneSurface(impl)
{
    _cache = new srfCache();
}

SRF_LocalTangentSpaceEuclidean::~SRF_LocalTangentSpaceEuclidean()
{
    if (_cache)
    {
        delete (srfCache*) _cache;
        _cache = 0;
    }
}

/// Constructor by SRF parameter structure
SRF_LocalTangentSpaceEuclidean* SRF_LocalTangentSpaceEuclidean::create
(
          SRM_ORM_Code         orm,
          SRM_RT_Code          rt,
    const SRM_LTSE_Parameters &params
)
{
    Impl_Status                     status;
    void                           *impl_ptr = 0;
    SRF_LocalTangentSpaceEuclidean *this_srf = 0;

    if (!isLegalORMCode(orm, rt))
        throw Exception(SRM_STATCOD_INVALID_CODE, "create: Invalid ORM code");

    status = Impl_createSRFFromParams(SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN,
                                      orm,
                                      rt,
                                      (void*) &params,
                                      &impl_ptr);

    if (status == IMPL_VALID)
        this_srf = new SRF_LocalTangentSpaceEuclidean(impl_ptr);
    else
        processStatus(status, "create");

    /* only return if status == IMPL_VALID */
    return this_srf;
}


/// Constructor by individual SRF parameters
SRF_LocalTangentSpaceEuclidean* SRF_LocalTangentSpaceEuclidean::create
(
    SRM_ORM_Code orm,
    SRM_RT_Code rt,
    SRM_Long_Float geodetic_longitude,
    SRM_Long_Float geodetic_latitude,
    SRM_Long_Float azimuth,
    SRM_Long_Float x_false_origin,
    SRM_Long_Float y_false_origin,
    SRM_Long_Float height_offset
)
{
    Impl_Status                     status;
    void                           *impl_ptr = 0;
    SRF_LocalTangentSpaceEuclidean *this_srf = 0;
    SRM_LTSE_Parameters             params;

    if (!isLegalORMCode(orm, rt))
        throw Exception(SRM_STATCOD_INVALID_CODE, "create: Invalid ORM code");

    params.geodetic_longitude = geodetic_longitude;
    params.geodetic_latitude = geodetic_latitude;
    params.azimuth = azimuth;
    params.x_false_origin = x_false_origin;
    params.y_false_origin = y_false_origin;
    params.height_offset = height_offset;

    status = Impl_createSRFFromParams(SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN,
                                      orm,
                                      rt,
                                      (void*) &params,
                                      &impl_ptr);

    if (status == IMPL_VALID)
        this_srf = new SRF_LocalTangentSpaceEuclidean(impl_ptr);
    else
        processStatus(status, "create");

    /* only return if status == IMPL_VALID */
    return this_srf;
}


/// Returns a 3D coordinate object
Coord3D* SRF_LocalTangentSpaceEuclidean::createCoordinate3D
(
    SRM_Long_Float coord_comp1,
    SRM_Long_Float coord_comp2,
    SRM_Long_Float coord_comp3
)
{
    return (new Coord3D_LocalTangentSpaceEuclidean(this, coord_comp1, coord_comp2, coord_comp3));
}


/// Returns a surface coordinate object
CoordSurf* SRF_LocalTangentSpaceEuclidean::createSurfaceCoordinate
(
    SRM_Long_Float coord_surf_comp1,
    SRM_Long_Float coord_surf_comp2
)
{
    return (new CoordSurf_LocalTangentSpaceEuclidean(this, coord_surf_comp1, coord_surf_comp2));
}


/// Returns a reference to the SRF parameter structure
const SRM_LTSE_Parameters& SRF_LocalTangentSpaceEuclidean::getSRFParameters() const
{
    Impl_Status                status;
    static SRM_LTSE_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "getSRFParameters");

    return params;
}


/// Returns the geodetic_longitude SRF parameter value
SRM_Long_Float SRF_LocalTangentSpaceEuclidean::get_geodetic_longitude() const
{
    Impl_Status         status;
    SRM_LTSE_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_geodetic_longitude");

    return params.geodetic_longitude;
}


/// Returns the geodetic_latitude SRF parameter value
SRM_Long_Float SRF_LocalTangentSpaceEuclidean::get_geodetic_latitude() const
{
    Impl_Status         status;
    SRM_LTSE_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_geodetic_latitude");

    return params.geodetic_latitude;
}


/// Returns the azimuth SRF parameter value
SRM_Long_Float SRF_LocalTangentSpaceEuclidean::get_azimuth() const
{
    Impl_Status         status;
    SRM_LTSE_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_azimuth");

    return params.azimuth;
}


/// Returns the x_false_origin SRF parameter value
SRM_Long_Float SRF_LocalTangentSpaceEuclidean::get_x_false_origin() const
{
    Impl_Status         status;
    SRM_LTSE_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_x_false_origin");

    return params.x_false_origin;
}


/// Returns the y_false_origin SRF parameter value
SRM_Long_Float SRF_LocalTangentSpaceEuclidean::get_y_false_origin() const
{
    Impl_Status         status;
    SRM_LTSE_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_y_false_origin");

    return params.y_false_origin;
}


/// Returns the height_offset SRF parameter value
SRM_Long_Float SRF_LocalTangentSpaceEuclidean::get_height_offset() const
{
    Impl_Status         status;
    SRM_LTSE_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_height_offset");

    return params.height_offset;
}


bool SRF_LocalTangentSpaceEuclidean::isEqual(const SRF_LocalTangentSpaceEuclidean &srf) const
{
    return (Impl_compareSRFParameters(_impl, srf._impl) == 0);
}

bool SRF_LocalTangentSpaceEuclidean::operator== (const SRF_LocalTangentSpaceEuclidean &rhs) const
{
    return(Impl_compareSRFParameters(_impl, rhs._impl) == 0);
}

SRF_LocalTangentSpaceEuclidean* SRF_LocalTangentSpaceEuclidean::makeCopy() const
{
    Impl_Status                     status;
    SRF_LocalTangentSpaceEuclidean *retSRF = 0;
    void                           *impl = 0;

    status = Impl_copySRF(_impl, &impl);

    if (status != IMPL_VALID)
        processStatus(status, "makeCopy", SRF, MEM);

    retSRF = new SRF_LocalTangentSpaceEuclidean(impl);

    return retSRF;
}


SRM_Coordinate_Valid_Region SRF_LocalTangentSpaceEuclidean::changeCoordinate3DSRF
(
    const Coord3D &src_coord,
                                                                                          Coord3D &des_coord
)
{
    Impl_Status                 status=IMPL_VALID;
    SRM_Long_Float              desCoord[4], desCoord_tmp[4]={0.0, 0.0, 0.0, 1.0}, srcCoord[4];
    SRM_Long_Float              tmp_vec[3];
    SRM_Coordinate_Valid_Region ret_validity;

    if (des_coord.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE, "changeCoordinate3DSRF: Target coordinate associated with a different SRF");

    BaseSRF *src_srf = src_coord.getSRF();
    BaseSRF *des_srf = des_coord.getSRF();
    SRF_ClassType src_srf_type = src_srf->getClassType();
    bool doVM = true;

    if (g_fast_mode)
    {
        LTSE_Cache_Constants *cv_cache = (LTSE_Cache_Constants*)
                                         SRF_CACHE_GET_VALUE(src_srf);

        if (!cv_cache)
        {
            // If the ORMs or RTs don't match we can't do a fast conversion
            if (src_srf->getOrm() != getOrm() || src_srf->getRt() != getRt())
            {
                cv_cache = (LTSE_Cache_Constants*)1;
            }
            else
            {
                SRM_SRF_Code       srf_code;
                SRM_SRFT_Code      template_code;
                SRM_SRFS_Code_Info srfs_code_info;

                switch (src_srf_type)
                {
                    case SRF_TYP_TM:
                    {
                        if ((cv_cache = new LTSE_Cache_Constants)!=0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            IMPL_TRANSVERSE_MERCATOR_SRFP tm_srf;
                            tm_srf.origin_longitude = ((SRF_TransverseMercator*)src_srf)->get_origin_longitude();
                            tm_srf.origin_latitude = ((SRF_TransverseMercator*)src_srf)->get_origin_latitude();
                            tm_srf.central_scale = ((SRF_TransverseMercator*)src_srf)->get_central_scale();
                            tm_srf.false_easting = ((SRF_TransverseMercator*)src_srf)->get_false_easting();
                            tm_srf.false_northing = ((SRF_TransverseMercator*)src_srf)->get_false_northing();

                            set_tm_to_cd_constants(e_constants, &tm_srf,
                                                   &(cv_cache->tm_ltse.tm_cd));

                            cv_cache->tm_ltse.tm_f_e = tm_srf.false_easting;
                            cv_cache->tm_ltse.tm_f_n = tm_srf.false_northing;

                            cv_cache->tm_ltse.cd_cc.e_constants = *e_constants;

                            ((SRF_TransverseMercator*)src_srf)->getCodes(srf_code,
                                                                         template_code,
                                                                         srfs_code_info);

                            // check whether this TM is an UTM.
                            cv_cache->tm_ltse.srf_set = srfs_code_info.srfs_code;

                            IMPL_LOC_TAN_EUCLIDEAN_SRFP ltse_params;
                            Impl_LTE_SRF_Specific_Data  ltse_spec;

                            ltse_params.geodetic_longitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_longitude();
                            ltse_params.geodetic_latitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_latitude();
                            ltse_params.azimuth = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_azimuth();
                            ltse_params.height_offset = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_height_offset();

                            Impl_createLTESRFspecificData(e_constants,
                                                          &ltse_params,
                                                          &ltse_spec);

                            set_cc_lte_constants(&ltse_spec,
                                                 &(cv_cache->tm_ltse.cc_ltse));

                            cv_cache->tm_ltse.f_x = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_x_false_origin();
                            cv_cache->tm_ltse.f_y = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_y_false_origin();

                            ((SRF_LocalTangentSpaceEuclidean*)des_srf)->
                            getCodes(srf_code,
                                     template_code,
                                     srfs_code_info);

                            // check whether this LTSE is GTRS GCS.
                            cv_cache->tm_ltse.is_gtrs = (srfs_code_info.srfs_code == SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM);

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (LTSE_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_PS:
                    {
                        if ((cv_cache = new LTSE_Cache_Constants)!=0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            IMPL_POLAR_STEREOGRAPHIC_SRFP ps_srf;

                            ps_srf.origin_longitude = ((SRF_PolarStereographic*)src_srf)->get_origin_longitude();
                            ps_srf.central_scale = ((SRF_PolarStereographic*)src_srf)->get_central_scale();
                            ps_srf.polar_aspect = ((SRF_PolarStereographic*)src_srf)->get_polar_aspect();
                            ps_srf.false_easting = ((SRF_PolarStereographic*)src_srf)->get_false_easting();
                            ps_srf.false_northing = ((SRF_PolarStereographic*)src_srf)->get_false_northing();

                            Impl_set_ps_to_cd_constants(e_constants, &ps_srf,
                                                        &(cv_cache->ps_ltse.ps_cd));

                            cv_cache->ps_ltse.ps_f_e = ps_srf.false_easting;
                            cv_cache->ps_ltse.ps_f_n = ps_srf.false_northing;

                           ((SRF_PolarStereographic*)src_srf)->getCodes(srf_code,
                                                                        template_code,
                                                                        srfs_code_info);

                            // check whether this PS is a UPS.
                            cv_cache->ps_ltse.is_ups =
                              (srfs_code_info.srfs_code ==
                               SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC);

                            cv_cache->ps_ltse.cd_cc.e_constants = *e_constants;

                            IMPL_LOC_TAN_EUCLIDEAN_SRFP ltse_params;
                            Impl_LTE_SRF_Specific_Data  ltse_spec;

                            ltse_params.geodetic_longitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_longitude();
                            ltse_params.geodetic_latitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_latitude();
                            ltse_params.azimuth = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_azimuth();
                            ltse_params.height_offset = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_height_offset();

                            Impl_createLTESRFspecificData(e_constants,
                                                          &ltse_params,
                                                          &ltse_spec);

                            set_cc_lte_constants(&ltse_spec,
                                                 &(cv_cache->ps_ltse.cc_ltse));

                            cv_cache->ps_ltse.f_x = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_x_false_origin();
                            cv_cache->ps_ltse.f_y = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_y_false_origin();

                            ((SRF_LocalTangentSpaceEuclidean*)des_srf)->
                            getCodes(srf_code,
                                     template_code,
                                     srfs_code_info);

                            // check whether this LTSE is GTRS GCS.
                            cv_cache->ps_ltse.is_gtrs =
                              (srfs_code_info.srfs_code ==
                               SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM);

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (LTSE_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_CD:
                    {
                        if ((cv_cache = new LTSE_Cache_Constants)!=0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            cv_cache->cd_ltse.cd_cc.e_constants = *e_constants;

                            IMPL_LOC_TAN_EUCLIDEAN_SRFP ltse_params;
                            Impl_LTE_SRF_Specific_Data  ltse_spec;

                            ltse_params.geodetic_longitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_longitude();
                            ltse_params.geodetic_latitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_latitude();
                            ltse_params.azimuth = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_azimuth();
                            ltse_params.height_offset = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_height_offset();

                            Impl_createLTESRFspecificData(e_constants,
                                                          &ltse_params,
                                                          &ltse_spec);

                            set_cc_lte_constants(&ltse_spec,
                                                 &(cv_cache->cd_ltse.cc_ltse));

                            cv_cache->cd_ltse.f_x = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_x_false_origin();
                            cv_cache->cd_ltse.f_y = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_y_false_origin();

                            ((SRF_LocalTangentSpaceEuclidean*)des_srf)->
                            getCodes(srf_code,
                                     template_code,
                                     srfs_code_info);

                            // check whether this LTSE is GTRS GCS.
                            cv_cache->cd_ltse.is_gtrs = (srfs_code_info.srfs_code == SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM);

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (LTSE_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_LCE_3D:
                    {
                        if ((cv_cache = new LTSE_Cache_Constants)!=0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            ((SRF_LococentricEuclidean3D*)src_srf)->
                            get_lococentre
                            (cv_cache->lce3d_ltse.lce3d_cc.lococentre);
                            ((SRF_LococentricEuclidean3D*)src_srf)->
                            get_primary_axis
                            (cv_cache->lce3d_ltse.lce3d_cc.primary_axis);
                            ((SRF_LococentricEuclidean3D*)src_srf)->
                            get_secondary_axis
                            (cv_cache->lce3d_ltse.lce3d_cc.secondary_axis);

                            _cross_product
                            (cv_cache->lce3d_ltse.lce3d_cc.primary_axis,
                             cv_cache->lce3d_ltse.lce3d_cc.secondary_axis,
                             cv_cache->lce3d_ltse.lce3d_cc.xprod_rs);

                            IMPL_LOC_TAN_EUCLIDEAN_SRFP ltse_params;
                            Impl_LTE_SRF_Specific_Data  ltse_spec;

                            ltse_params.geodetic_longitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_longitude();
                            ltse_params.geodetic_latitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_latitude();
                            ltse_params.azimuth = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_azimuth();
                            ltse_params.height_offset = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_height_offset();

                            Impl_createLTESRFspecificData(e_constants,
                                                          &ltse_params,
                                                          &ltse_spec);

                            set_cc_lte_constants(&ltse_spec,
                                                 &(cv_cache->lce3d_ltse.cc_ltse));

                            cv_cache->lce3d_ltse.f_x = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_x_false_origin();
                            cv_cache->lce3d_ltse.f_y = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_y_false_origin();

                            ((SRF_LocalTangentSpaceEuclidean*)des_srf)->getCodes(srf_code,
                                                                                 template_code,
                                                                                 srfs_code_info);

                            // check whether this LTSE is GTRS GCS.
                            cv_cache->lce3d_ltse.is_gtrs =
                              (srfs_code_info.srfs_code ==
                               SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM);

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (LTSE_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_CC:
                    {
                        if ((cv_cache = new LTSE_Cache_Constants)!=0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            IMPL_LOC_TAN_EUCLIDEAN_SRFP ltse_params;
                            Impl_LTE_SRF_Specific_Data  ltse_spec;

                            ltse_params.geodetic_longitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_longitude();
                            ltse_params.geodetic_latitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_latitude();
                            ltse_params.azimuth = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_azimuth();
                            ltse_params.height_offset = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_height_offset();

                            Impl_createLTESRFspecificData(e_constants,
                                                          &ltse_params,
                                                          &ltse_spec);

                            set_cc_lte_constants(&ltse_spec,
                                                 &(cv_cache->cc_ltse.cc_ltse));

                            cv_cache->cc_ltse.f_x = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_x_false_origin();
                            cv_cache->cc_ltse.f_y = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_y_false_origin();

                            ((SRF_LocalTangentSpaceEuclidean*)des_srf)->
                            getCodes(srf_code,
                                     template_code,
                                     srfs_code_info);

                            // check whether this LTSE is GTRS GCS.
                            cv_cache->cc_ltse.is_gtrs =
                              (srfs_code_info.srfs_code ==
                               SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM);

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (LTSE_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_M:
                    {
                        if ((cv_cache = new LTSE_Cache_Constants)!=0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            IMPL_MERCATOR_SRFP m_srf;

                            m_srf.origin_longitude = ((SRF_Mercator*)src_srf)->get_origin_longitude();
                            m_srf.central_scale = ((SRF_Mercator*)src_srf)->get_central_scale();
                            m_srf.false_easting = ((SRF_Mercator*)src_srf)->get_false_easting();
                            m_srf.false_northing = ((SRF_Mercator*)src_srf)->get_false_northing();

                            set_m_to_cd_constants(e_constants, &m_srf,
                                                  &(cv_cache->m_ltse.m_cd));

                            cv_cache->m_ltse.m_f_e = m_srf.false_easting;
                            cv_cache->m_ltse.m_f_n = m_srf.false_northing;

                            cv_cache->m_ltse.cd_cc.e_constants = *e_constants;

                            IMPL_LOC_TAN_EUCLIDEAN_SRFP ltse_params;
                            Impl_LTE_SRF_Specific_Data  ltse_spec;

                            ltse_params.geodetic_longitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_longitude();
                            ltse_params.geodetic_latitude = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_geodetic_latitude();
                            ltse_params.azimuth = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_azimuth();
                            ltse_params.height_offset = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_height_offset();

                            Impl_createLTESRFspecificData(e_constants,
                                                          &ltse_params,
                                                          &ltse_spec);

                            set_cc_lte_constants(&ltse_spec,
                                                 &(cv_cache->m_ltse.cc_ltse));

                            cv_cache->m_ltse.f_x = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_x_false_origin();
                            cv_cache->m_ltse.f_y = ((SRF_LocalTangentSpaceEuclidean*)des_srf)->get_y_false_origin();

                            ((SRF_LocalTangentSpaceEuclidean*)des_srf)->
                            getCodes(srf_code,
                                     template_code,
                                     srfs_code_info);

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (LTSE_Cache_Constants*)1;
                        }
                    }
                    break;

                    default:
                        cv_cache = (LTSE_Cache_Constants*)1;
                        break;
                }
            }
            SRF_CACHE_ADD_VALUE(src_srf, cv_cache);
        }

        if (SRF_CACHE_CAN_USE(cv_cache))
        {
            doVM = false;

            switch (src_srf_type)
            {
                case SRF_TYP_TM:
                {
                    const SRM_Long_Float *tmp_coord = src_coord.getValues();

                    srcCoord[0] = tmp_coord[0] - cv_cache->tm_ltse.tm_f_e;
                    srcCoord[1] = tmp_coord[1] - cv_cache->tm_ltse.tm_f_n;
                    srcCoord[2] = tmp_coord[2];

                    // set the 4 component of the source coordinate for CC->LTSE to 1.0
                    desCoord_tmp[3] = 1.0;

                    if (_validate_coords
                        && ((status |= Impl_validcoord3DTRANSVERSE_MERCATOR_native(GET_IDATA(src_srf), srcCoord))
                            & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeTM_CD(&(cv_cache->tm_ltse.tm_cd), srcCoord, desCoord))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for Alabama state plane coordinate system coordinate
                    // is Alabama state plane coordinate system
                    else if (_validate_coords &&
                             (cv_cache->tm_ltse.srf_set == SRM_SRFSCOD_ALABAMA_SPCS) &&
                             ((status |= Impl_validcoord3D_ALSP_cd(GET_IDATA(src_srf), desCoord))
                              & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for Japan plane coordinate system coordinate
                    // is Japan plane coordinate system
                    else if (_validate_coords &&
                             (cv_cache->tm_ltse.srf_set == SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS) &&
                             ((status |= Impl_validcoord3D_JRPS_cd(GET_IDATA(src_srf), desCoord))
                              & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for UTM coordinate is UTM
                    else if (_validate_coords &&
                             (cv_cache->tm_ltse.srf_set == SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR) &&
                             ((status = Impl_validcoord3D_UTMC_cd(GET_IDATA(src_srf), desCoord))
                               & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for TM coordinate is TM
                    else if (_validate_coords &&
                             !((cv_cache->tm_ltse.srf_set == SRM_SRFSCOD_ALABAMA_SPCS) ||
                               (cv_cache->tm_ltse.srf_set == SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS) ||
                               (cv_cache->tm_ltse.srf_set == SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR))
                           && ((status = Impl_validcoord3DTRANSVERSE_MERCATOR_cd(GET_IDATA(src_srf), desCoord))
                               & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // This validation is to assure that the ellipsoidal height does not overshoot the center of the planet
                    else if (_validate_coords && !(-cv_cache->tm_ltse.cd_cc.e_constants.B < desCoord[2]))
                        status = IMPL_INVALID;
                    else if ((status = SRM_ChangeCD_CC(&(cv_cache->tm_ltse.cd_cc), desCoord, desCoord_tmp))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCC_LTE(&(cv_cache->tm_ltse.cc_ltse), desCoord_tmp, desCoord))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->tm_ltse.f_x;
                        desCoord[1] = desCoord[1] + cv_cache->tm_ltse.f_y;
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_PS:
                {
                    const SRM_Long_Float *tmp_coord = src_coord.getValues();

                    srcCoord[0] = tmp_coord[0] - cv_cache->ps_ltse.ps_f_e;
                    srcCoord[1] = tmp_coord[1] - cv_cache->ps_ltse.ps_f_n;
                    srcCoord[2] = tmp_coord[2];

                    if ((status = Impl_ChangePS_CD(&(cv_cache->ps_ltse.ps_cd), srcCoord, desCoord))
                        & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for UPS coordinate is UPS
                    else if (_validate_coords && cv_cache->ps_ltse.is_ups
                             && ((status |= Impl_validcoord3D_UPST_cd(GET_IDATA(src_srf), desCoord_tmp))
                                 & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for PS coordinate is PS
                    else if (_validate_coords && !cv_cache->ps_ltse.is_ups
                             && ((status |= Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd(GET_IDATA(src_srf), desCoord))
                                 & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if (_validate_coords
                             && ((status |= Impl_validcoord3DCELESTIODETIC(GET_IDATA(src_srf), desCoord))
                                 & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCD_CC(&(cv_cache->ps_ltse.cd_cc), desCoord, desCoord_tmp))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCC_LTE(&(cv_cache->ps_ltse.cc_ltse), desCoord_tmp, desCoord))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->ps_ltse.f_x;
                        desCoord[1] = desCoord[1] + cv_cache->ps_ltse.f_y;
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_M:
                {
                    const SRM_Long_Float *tmp_coord = src_coord.getValues();

                    srcCoord[0] = tmp_coord[0] - cv_cache->m_ltse.m_f_e;
                    srcCoord[1] = tmp_coord[1] - cv_cache->m_ltse.m_f_n;
                    srcCoord[2] = tmp_coord[2];

                    if ((status = SRM_ChangeM_CD(&(cv_cache->m_ltse.m_cd), srcCoord, desCoord))
                        & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if (_validate_coords
                             && ((status |= Impl_validcoord3DMERCATOR_cd(GET_IDATA(src_srf), desCoord))
                                 & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if (_validate_coords
                             && ((status |= Impl_validcoord3DCELESTIODETIC(GET_IDATA(src_srf), desCoord))
                                 & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCD_CC(&(cv_cache->m_ltse.cd_cc), desCoord, desCoord_tmp))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCC_LTE(&(cv_cache->m_ltse.cc_ltse), desCoord_tmp, desCoord))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->m_ltse.f_x;
                        desCoord[1] = desCoord[1] + cv_cache->m_ltse.f_y;
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_CD:
                {
                    if (_validate_coords
                        && ((status |= Impl_validcoord3DCELESTIODETIC(GET_IDATA(src_srf), (SRM_Long_Float*)src_coord.getValues()))
                            & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCD_CC(&(cv_cache->cd_ltse.cd_cc), src_coord.getValues(), desCoord_tmp))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCC_LTE(&(cv_cache->cd_ltse.cc_ltse), desCoord_tmp, desCoord))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->cd_ltse.f_x;
                        desCoord[1] = desCoord[1] + cv_cache->cd_ltse.f_y;
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_CC:
                {
                    const SRM_Long_Float *tmp_coord = src_coord.getValues();

                    srcCoord[0] = tmp_coord[0];
                    srcCoord[1] = tmp_coord[1];
                    srcCoord[2] = tmp_coord[2];
                    srcCoord[3] = 1.0;

                    if ((status = SRM_ChangeCC_LTE(&(cv_cache->cc_ltse.cc_ltse), srcCoord, desCoord))
                        & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->cc_ltse.f_x;
                        desCoord[1] = desCoord[1] + cv_cache->cc_ltse.f_y;
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_LCE_3D:
                {
                    if ((status = SRM_ChangeLCE_CC(&(cv_cache->lce3d_ltse.lce3d_cc), src_coord.getValues(), desCoord_tmp))
                        & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCC_LTE(&(cv_cache->lce3d_ltse.cc_ltse), desCoord_tmp, desCoord))
                             & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->lce3d_ltse.f_x;
                        desCoord[1] = desCoord[1] + cv_cache->lce3d_ltse.f_y;
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;
            }
        }
    }

    if (doVM)
    {
        status = Impl_changeCoord3DSRF(((SRF_LocalTangentSpaceEuclidean*)src_srf)->_impl, src_coord.getValues(),
                                       ((SRF_LocalTangentSpaceEuclidean*)des_srf)->_impl, desCoord);
    }

    // set the coordinate values if status is "valid"
    if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
    {
        memcpy(tmp_vec, desCoord, 3*sizeof(SRM_Long_Float));
        des_coord.setValues(tmp_vec);

        if (status == IMPL_VALID)
            ret_validity = SRM_COORDVALRGN_VALID;
        else if (status == IMPL_EXTENDED)
            ret_validity = SRM_COORDVALRGN_EXTENDED_VALID;
        else if (status == IMPL_DEFINED)
            ret_validity = SRM_COORDVALRGN_DEFINED;
    }
    else
        processStatus(status, "changeCoordinate3DSRF", COORD, MEM);

    return ret_validity;
}


/// Return char* of Parameter names and their values (one per line)
const char* SRF_LocalTangentSpaceEuclidean::toString()
{
    static char         ret_string[500];
    static char         tmp_buffer[50];
    Impl_Status         status;
    SRM_ORM_Code        orm;
    SRM_RT_Code         rt;
    SRM_LTSE_Parameters params;

    status  = Impl_getSRFParameters(this->_impl, (void *)&params);
    status |= Impl_getORM(this->_impl, &orm);
    status |= Impl_getRT(this->_impl, &rt);

    if (status != IMPL_VALID)
        processStatus(status, "toString");

    // set the char* to null
    ret_string[0] = '\0';

    sprintf(tmp_buffer, "orm=> %i\n", orm);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "rt=> %i\n", rt);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "geodetic_longitude=> %f\n", params.geodetic_longitude);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "geodetic_latitude=> %f\n", params.geodetic_latitude);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "azimuth=> %f\n", params.azimuth);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "x_false_origin=> %f\n", params.x_false_origin);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "y_false_origin=> %f\n", params.y_false_origin);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "height_offset=> %f\n", params.height_offset);
    strcat(ret_string, tmp_buffer);

    return ret_string;
}

/// the coordinate equality operator
bool Coord3D_LocalTangentSpaceEuclidean::operator== (const Coord3D_LocalTangentSpaceEuclidean &rhs) const
{
    return (((*(SRF_LocalTangentSpaceEuclidean*)(this->_srf)) == (*(SRF_LocalTangentSpaceEuclidean*)(rhs._srf))) &&
            ARE_EQUAL(_values[0], rhs._values[0]) &&
            ARE_EQUAL(_values[1], rhs._values[1]) &&
            ARE_EQUAL(_values[2], rhs._values[2]));
}

/// the coordinate equality operator
bool CoordSurf_LocalTangentSpaceEuclidean::operator== (const CoordSurf_LocalTangentSpaceEuclidean &rhs) const
{
    return (((*(SRF_LocalTangentSpaceEuclidean*)(this->_srf)) == (*(SRF_LocalTangentSpaceEuclidean*)(rhs._srf))) &&
            ARE_EQUAL(_values[0], rhs._values[0]) &&
            ARE_EQUAL(_values[1], rhs._values[1]));
}
