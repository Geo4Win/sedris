/** @file PolarStereographic.cpp
@author David Shen
@brief PolarStereographic SRF body.
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


#include "PolarStereographic.h"
#include "Celestiodetic.h"
#include "TransverseMercator.h"
#include "Mercator.h"
#include "LocalTangentSpaceEuclidean.h"
#include "LococentricEuclidean3D.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"
#include "srm_validcoord.h"

#include "srfCache.h"

using namespace srm;

#define GET_IDATA(_orig) ((Impl_SRF*)(((SRF_PolarStereographic*)_orig)->getImpl()))->private_data

SRF_PolarStereographic::SRF_PolarStereographic(void *impl) : BaseSRF_MapProjection(impl)
{
    _cache = new srfCache();
}

SRF_PolarStereographic::~SRF_PolarStereographic()
{
    if (_cache)
    {
        delete (srfCache*) _cache;
        _cache = 0;
    }
}

///   Constructor by SRF parameter structure
SRF_PolarStereographic *SRF_PolarStereographic::create
(
          SRM_ORM_Code       orm,
          SRM_RT_Code        rt,
    const SRM_PS_Parameters &params
)
{
    Impl_Status             status;
    void                   *impl_ptr = 0;
    SRF_PolarStereographic *this_srf = 0;

    if (!isLegalORMCode(orm, rt))
        throw Exception(SRM_STATCOD_INVALID_CODE, "create: Invalid ORM code");

    status = Impl_createSRFFromParams(SRM_SRFTCOD_POLAR_STEREOGRAPHIC,
                                      orm,
                                      rt,
                                      (void*) &params,
                                      &impl_ptr);

    if (status == IMPL_VALID)
        this_srf = new SRF_PolarStereographic(impl_ptr);
    else
        processStatus(status, "create");

    /* only return if status == IMPL_VALID */
    return this_srf;
}


///   Constructor by individual SRF parameters
SRF_PolarStereographic *SRF_PolarStereographic::create
(
    SRM_ORM_Code     orm,
    SRM_RT_Code      rt,
    SRM_Polar_Aspect polar_aspect,
    SRM_Long_Float   origin_longitude,
    SRM_Long_Float   central_scale,
    SRM_Long_Float   false_easting,
    SRM_Long_Float   false_northing
)
{
    Impl_Status             status;
    void                   *impl_ptr = 0;
    SRF_PolarStereographic *this_srf = 0;
    SRM_PS_Parameters       params;

    if (!isLegalORMCode(orm, rt))
        throw Exception(SRM_STATCOD_INVALID_CODE, "create: Invalid ORM code");

    params.polar_aspect = polar_aspect;
    params.origin_longitude = origin_longitude;
    params.central_scale = central_scale;
    params.false_easting = false_easting;
    params.false_northing = false_northing;

    status = Impl_createSRFFromParams(SRM_SRFTCOD_POLAR_STEREOGRAPHIC,
                                      orm,
                                      rt,
                                      (void*) &params,
                                      &impl_ptr);

    if (status == IMPL_VALID)
        this_srf = new SRF_PolarStereographic(impl_ptr);
    else
        processStatus(status, "create");

    /* only return if status == IMPL_VALID */
    return this_srf;
}


/// Returns a 3D coordinate object
Coord3D *SRF_PolarStereographic::createCoordinate3D
(
    SRM_Long_Float coord_comp1,
    SRM_Long_Float coord_comp2,
    SRM_Long_Float coord_comp3
)
{
    return (new Coord3D_PolarStereographic(this, coord_comp1, coord_comp2, coord_comp3));
}


/// Returns a surface coordinate object
CoordSurf*   SRF_PolarStereographic::createSurfaceCoordinate
(
    SRM_Long_Float coord_surf_comp1,
    SRM_Long_Float coord_surf_comp2
)
{
    return (new CoordSurf_PolarStereographic(this, coord_surf_comp1, coord_surf_comp2));
}


/// Returns a reference to the SRF parameter structure
const SRM_PS_Parameters& SRF_PolarStereographic::getSRFParameters() const
{
    Impl_Status              status;
    static SRM_PS_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "getSRFParameters");

    return params;
}


/// Returns the polar_aspect SRF parameter value
SRM_Polar_Aspect SRF_PolarStereographic::get_polar_aspect() const
{
    Impl_Status       status;
    SRM_PS_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_polar_aspect");

    return params.polar_aspect;
}


/// Returns the origin_longitude SRF parameter value
SRM_Long_Float SRF_PolarStereographic::get_origin_longitude() const
{
    Impl_Status       status;
    SRM_PS_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_origin_longitude");

    return params.origin_longitude;
}


/// Returns the central_scale SRF parameter value
SRM_Long_Float SRF_PolarStereographic::get_central_scale() const
{
    Impl_Status       status;
    SRM_PS_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_central_scale");

    return params.central_scale;
}


/// Returns the false_easting SRF parameter value
SRM_Long_Float SRF_PolarStereographic::get_false_easting() const
{
    Impl_Status       status;
    SRM_PS_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_false_easting");

    return params.false_easting;
}


/// Returns the false_northing SRF parameter value
SRM_Long_Float SRF_PolarStereographic::get_false_northing() const
{
    Impl_Status       status;
    SRM_PS_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_false_northing");

    return params.false_northing;
}


bool SRF_PolarStereographic::isEqual(const SRF_PolarStereographic &srf) const
{
    return (Impl_compareSRFParameters(_impl, srf._impl) == 0);
}

bool SRF_PolarStereographic::operator== (const SRF_PolarStereographic &rhs) const
{
    return (Impl_compareSRFParameters(_impl, rhs._impl) == 0);
}

SRF_PolarStereographic* SRF_PolarStereographic::makeCopy() const
{
    Impl_Status             status;
    SRF_PolarStereographic *retSRF = 0;
    void                   *impl = 0;

    status = Impl_copySRF(_impl, &impl);

    if (status != IMPL_VALID)
        processStatus(status, "makeCopy", SRF, MEM);

    retSRF = new SRF_PolarStereographic(impl);

    return retSRF;
}


SRM_Coordinate_Valid_Region SRF_PolarStereographic::changeCoordinate3DSRF
(
    const Coord3D &src_coord,
          Coord3D &des_coord
)
{
    Impl_Status                 status=IMPL_VALID;
    SRM_Long_Float              desCoord[4], desCoord_tmp[4], srcCoord[4];
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
        PS_Cache_Constants *cv_cache = (PS_Cache_Constants*)
                                       SRF_CACHE_GET_VALUE(src_srf);

        if (!cv_cache)
        {
            // If the ORMs or RTs don't match we can't do a fast conversion
            if (src_srf->getOrm() != getOrm() || src_srf->getRt() != getRt())
            {
                cv_cache = (PS_Cache_Constants*)1;
            }
            else
            {
                SRM_SRF_Code  srf_code;
                SRM_SRFT_Code template_code;
                SRM_SRFS_Code_Info srfs_code_info;
                bool is_ups;

                ((SRF_PolarStereographic*)des_srf)->getCodes(srf_code,
                                                             template_code,
                                                             srfs_code_info);

                // check whether this PS is an UPS.
                is_ups = (srfs_code_info.srfs_code == SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC);

                switch (src_srf_type)
                {
                    case SRF_TYP_CC:
                    {
                        if ((cv_cache = new PS_Cache_Constants) != 0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            set_cc_to_cd_constants(e_constants, 0,
                                                   &(cv_cache->cc_ps.cc_cd));

                            IMPL_POLAR_STEREOGRAPHIC_SRFP ps_srf;

                            ps_srf.origin_longitude = ((SRF_PolarStereographic*)des_srf)->get_origin_longitude();
                            ps_srf.central_scale = ((SRF_PolarStereographic*)des_srf)->get_central_scale();
                            ps_srf.polar_aspect = ((SRF_PolarStereographic*)des_srf)->get_polar_aspect();
                            ps_srf.false_easting = ((SRF_PolarStereographic*)des_srf)->get_false_easting();
                            ps_srf.false_northing = ((SRF_PolarStereographic*)des_srf)->get_false_northing();

                            Impl_set_cd_to_ps_constants(e_constants, &ps_srf,
                                                        &(cv_cache->cc_ps.cd_ps));

                            cv_cache->cc_ps.ps_f_e = ps_srf.false_easting;
                            cv_cache->cc_ps.ps_f_n = ps_srf.false_northing;

                            cv_cache->cc_ps.is_ups = is_ups;

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (PS_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_TM:
                    {
                        if ((cv_cache = new PS_Cache_Constants)!=0)
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
                                                   &(cv_cache->tm_ps.tm_cd));

                            cv_cache->tm_ps.tm_f_e = tm_srf.false_easting;
                            cv_cache->tm_ps.tm_f_n = tm_srf.false_northing;

                            ((SRF_TransverseMercator*)src_srf)->getCodes(srf_code,
                                                                         template_code,
                                                                         srfs_code_info);

                            cv_cache->tm_ps.srf_set = SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR;

                            IMPL_POLAR_STEREOGRAPHIC_SRFP ps_srf;

                            ps_srf.origin_longitude = ((SRF_PolarStereographic*)des_srf)->get_origin_longitude();
                            ps_srf.central_scale = ((SRF_PolarStereographic*)des_srf)->get_central_scale();
                            ps_srf.polar_aspect = ((SRF_PolarStereographic*)des_srf)->get_polar_aspect();
                            ps_srf.false_easting = ((SRF_PolarStereographic*)des_srf)->get_false_easting();
                            ps_srf.false_northing = ((SRF_PolarStereographic*)des_srf)->get_false_northing();

                            Impl_set_cd_to_ps_constants(e_constants, &ps_srf,
                                                        &(cv_cache->tm_ps.cd_ps));

                            cv_cache->tm_ps.ps_f_e = ps_srf.false_easting;
                            cv_cache->tm_ps.ps_f_n = ps_srf.false_northing;

                            cv_cache->tm_ps.is_ups = is_ups;

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (PS_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_CD:
                    {
                        if ((cv_cache = new PS_Cache_Constants) != 0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            IMPL_POLAR_STEREOGRAPHIC_SRFP ps_srf;

                            ps_srf.origin_longitude = ((SRF_PolarStereographic*)des_srf)->get_origin_longitude();
                            ps_srf.central_scale = ((SRF_PolarStereographic*)des_srf)->get_central_scale();
                            ps_srf.polar_aspect = ((SRF_PolarStereographic*)des_srf)->get_polar_aspect();
                            ps_srf.false_easting = ((SRF_PolarStereographic*)des_srf)->get_false_easting();
                            ps_srf.false_northing = ((SRF_PolarStereographic*)des_srf)->get_false_northing();

                            Impl_set_cd_to_ps_constants(e_constants, &ps_srf,
                                                        &(cv_cache->cd_ps.cd_ps));

                            cv_cache->cd_ps.ps_f_e = ps_srf.false_easting;
                            cv_cache->cd_ps.ps_f_n = ps_srf.false_northing;

                            cv_cache->cd_ps.is_ups = is_ups;

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (PS_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_M:
                    {
                        if ((cv_cache = new PS_Cache_Constants) != 0)
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
                                                  &(cv_cache->m_ps.m_cd));

                            cv_cache->m_ps.m_f_e = m_srf.false_easting;
                            cv_cache->m_ps.m_f_n = m_srf.false_northing;

                            IMPL_POLAR_STEREOGRAPHIC_SRFP ps_srf;

                            ps_srf.origin_longitude = ((SRF_PolarStereographic*)des_srf)->get_origin_longitude();
                            ps_srf.central_scale = ((SRF_PolarStereographic*)des_srf)->get_central_scale();
                            ps_srf.polar_aspect = ((SRF_PolarStereographic*)des_srf)->get_polar_aspect();
                            ps_srf.false_easting = ((SRF_PolarStereographic*)des_srf)->get_false_easting();
                            ps_srf.false_northing = ((SRF_PolarStereographic*)des_srf)->get_false_northing();

                            Impl_set_cd_to_ps_constants(e_constants, &ps_srf,
                                                        &(cv_cache->m_ps.cd_ps));

                            cv_cache->m_ps.ps_f_e = ps_srf.false_easting;
                            cv_cache->m_ps.ps_f_n = ps_srf.false_northing;

                            cv_cache->m_ps.is_ups = is_ups;

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (PS_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_LTSE:
                    {
                        if ((cv_cache = new PS_Cache_Constants) != 0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            set_cc_to_cd_constants(e_constants, 0,
                                                   &(cv_cache->ltse_ps.cc_cd));

                            IMPL_LOC_TAN_EUCLIDEAN_SRFP ltse_params;
                            Impl_LTE_SRF_Specific_Data  ltse_spec;

                            ltse_params.geodetic_longitude = ((SRF_LocalTangentSpaceEuclidean*)src_srf)->get_geodetic_longitude();
                            ltse_params.geodetic_latitude = ((SRF_LocalTangentSpaceEuclidean*)src_srf)->get_geodetic_latitude();
                            ltse_params.azimuth = ((SRF_LocalTangentSpaceEuclidean*)src_srf)->get_azimuth();
                            ltse_params.height_offset = ((SRF_LocalTangentSpaceEuclidean*)src_srf)->get_height_offset();

                            Impl_createLTESRFspecificData(e_constants,
                                                          &ltse_params,
                                                          &ltse_spec);

                            set_lte_cc_constants(&ltse_spec,
                                                 &(cv_cache->ltse_ps.ltse_cc));

                            cv_cache->ltse_ps.f_x = ((SRF_LocalTangentSpaceEuclidean*)src_srf)->get_x_false_origin();
                            cv_cache->ltse_ps.f_y = ((SRF_LocalTangentSpaceEuclidean*)src_srf)->get_y_false_origin();

                            ((SRF_LocalTangentSpaceEuclidean*)src_srf)->getCodes(srf_code,
                                                                                 template_code,
                                                                                 srfs_code_info);

                            // check whether this LTSE is a GTRS.
                            cv_cache->ltse_ps.is_gtrs = (srfs_code_info.srfs_code == SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM);

                            IMPL_POLAR_STEREOGRAPHIC_SRFP ps_srf;

                            ps_srf.origin_longitude = ((SRF_PolarStereographic*)des_srf)->get_origin_longitude();
                            ps_srf.central_scale = ((SRF_PolarStereographic*)des_srf)->get_central_scale();
                            ps_srf.polar_aspect = ((SRF_PolarStereographic*)des_srf)->get_polar_aspect();
                            ps_srf.false_easting = ((SRF_PolarStereographic*)des_srf)->get_false_easting();
                            ps_srf.false_northing = ((SRF_PolarStereographic*)des_srf)->get_false_northing();

                            Impl_set_cd_to_ps_constants(e_constants, &ps_srf,
                                                        &(cv_cache->ltse_ps.cd_ps));

                            cv_cache->ltse_ps.ps_f_e = ps_srf.false_easting;
                            cv_cache->ltse_ps.ps_f_n = ps_srf.false_northing;

                            cv_cache->ltse_ps.is_ups = is_ups;

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (PS_Cache_Constants*)1;
                        }
                    }
                    break;

                    case SRF_TYP_LCE_3D:
                    {
                        if ((cv_cache = new PS_Cache_Constants) != 0)
                        {
                            cv_cache->src_srf_type = src_srf_type;
                            cv_cache->tgt_srf_type = this->getClassType();

                            Impl_ORM_Data *e_constants =
                              Impl_getEconstantsForORMCode(src_srf->getOrm());

                            set_cc_to_cd_constants(e_constants, 0,
                                                   &(cv_cache->lce3d_ps.cc_cd));

                            ((SRF_LococentricEuclidean3D*)src_srf)->
                            get_lococentre
                            (cv_cache->lce3d_ps.lce3d_cc.lococentre);
                            ((SRF_LococentricEuclidean3D*)src_srf)->
                            get_primary_axis
                            (cv_cache->lce3d_ps.lce3d_cc.primary_axis);
                            ((SRF_LococentricEuclidean3D*)src_srf)->
                            get_secondary_axis
                            (cv_cache->lce3d_ps.lce3d_cc.secondary_axis);

                            _cross_product
                            (cv_cache->lce3d_ps.lce3d_cc.primary_axis,
                             cv_cache->lce3d_ps.lce3d_cc.secondary_axis,
                             cv_cache->lce3d_ps.lce3d_cc.xprod_rs);

                            IMPL_POLAR_STEREOGRAPHIC_SRFP ps_srf;

                            ps_srf.origin_longitude = ((SRF_PolarStereographic*)des_srf)->get_origin_longitude();
                            ps_srf.central_scale = ((SRF_PolarStereographic*)des_srf)->get_central_scale();
                            ps_srf.polar_aspect = ((SRF_PolarStereographic*)des_srf)->get_polar_aspect();
                            ps_srf.false_easting = ((SRF_PolarStereographic*)des_srf)->get_false_easting();
                            ps_srf.false_northing = ((SRF_PolarStereographic*)des_srf)->get_false_northing();

                            Impl_set_cd_to_ps_constants(e_constants, &ps_srf,
                                                        &(cv_cache->lce3d_ps.cd_ps));

                            cv_cache->lce3d_ps.ps_f_e = ps_srf.false_easting;
                            cv_cache->lce3d_ps.ps_f_n = ps_srf.false_northing;

                            cv_cache->lce3d_ps.is_ups = is_ups;

                            free(e_constants);
                        }
                        else
                        {
                            cv_cache = (PS_Cache_Constants*)1;
                        }
                    }
                    break;

                    default:
                        cv_cache = (PS_Cache_Constants*)1;
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
                case SRF_TYP_CC:
                {
                    if ((status = SRM_ChangeCC_CD(&(cv_cache->cc_ps.cc_cd),
                        src_coord.getValues(), desCoord_tmp))
                          & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if (_validate_coords
                               && ((status |= Impl_validcoord3DCELESTIODETIC(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for UPS coordinate is UPS
                    else if (_validate_coords && cv_cache->cc_ps.is_ups
                               && ((status |= Impl_validcoord3D_UPST_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for PS coordinate is PS
                    else if (_validate_coords && !cv_cache->cc_ps.is_ups
                               && ((status |= Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = Impl_ChangeCD_PS(&(cv_cache->cc_ps.cd_ps), desCoord_tmp, desCoord))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->cc_ps.ps_f_e;
                        desCoord[1] = desCoord[1] + cv_cache->cc_ps.ps_f_n;
                        // desCoord[2] = des_coord[2];
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_TM:
                {
                    const SRM_Long_Float *tmp_coord = src_coord.getValues();

                    srcCoord[0] = tmp_coord[0] - cv_cache->tm_ps.tm_f_e;
                    srcCoord[1] = tmp_coord[1] - cv_cache->tm_ps.tm_f_n;
                    srcCoord[2] = tmp_coord[2];

                    if (_validate_coords
                          && ((status |= Impl_validcoord3DTRANSVERSE_MERCATOR_native(GET_IDATA(src_srf), srcCoord))
                            &   IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeTM_CD(&(cv_cache->tm_ps.tm_cd), srcCoord, desCoord_tmp))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for Alabama state plane coordinate system coordinate
                    // is Alabama state plane coordinate system
                    else if (_validate_coords &&
                             (cv_cache->tm_ps.srf_set == SRM_SRFSCOD_ALABAMA_SPCS) &&
                             ((status |= Impl_validcoord3D_ALSP_cd(GET_IDATA(src_srf), desCoord_tmp))
                              & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for Japan plane coordinate system coordinate
                    // is Japan plane coordinate system
                    else if (_validate_coords &&
                             (cv_cache->tm_ps.srf_set == SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS) &&
                             ((status |= Impl_validcoord3D_JRPS_cd(GET_IDATA(src_srf), desCoord_tmp))
                              & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for UTM coordinate is UTM
                    else if (_validate_coords &&
                             (cv_cache->tm_ps.srf_set == SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR) &&
                             ((status |= Impl_validcoord3D_UTMC_cd(GET_IDATA(src_srf), desCoord_tmp))
                              & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for TM coordinate is TM if it isn't a set
                    else if (_validate_coords &&
                             !((cv_cache->tm_ps.srf_set == SRM_SRFSCOD_ALABAMA_SPCS) ||
                               (cv_cache->tm_ps.srf_set == SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS) ||
                               (cv_cache->tm_ps.srf_set == SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR)) &&
                             ((status |= Impl_validcoord3DTRANSVERSE_MERCATOR_cd(GET_IDATA(src_srf), desCoord_tmp))
                              & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for UPS coordinate is UPS
                    else if (_validate_coords && cv_cache->tm_ps.is_ups
                               && ((status |= Impl_validcoord3D_UPST_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for PS coordinate is PS
                    else if (_validate_coords && !cv_cache->tm_ps.is_ups
                           && ((status |= Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd(GET_IDATA(des_srf), desCoord_tmp))
                               & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = Impl_ChangeCD_PS(&(cv_cache->tm_ps.cd_ps), desCoord_tmp, desCoord))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->tm_ps.ps_f_e;
                        desCoord[1] = desCoord[1] + cv_cache->tm_ps.ps_f_n;
                        // desCoord[2] = des_coord[2];
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_CD:
                {
                    // validation for UPS coordinate is UPS
                    if (_validate_coords && cv_cache->cd_ps.is_ups
                               && ((status |= Impl_validcoord3D_UPST_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for PS coordinate is PS
                    else if (_validate_coords && !cv_cache->cd_ps.is_ups
                          && ((status |= Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd(GET_IDATA(des_srf),
                                                                                 (SRM_Long_Float*)src_coord.getValues()))
                        &   IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = Impl_ChangeCD_PS(&(cv_cache->cd_ps.cd_ps), src_coord.getValues(), desCoord))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->cd_ps.ps_f_e;
                        desCoord[1] = desCoord[1] + cv_cache->cd_ps.ps_f_n;
                        // desCoord[2] = des_coord[2];
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_M:
                {
                    const SRM_Long_Float *tmp_coord = src_coord.getValues();

                    srcCoord[0] = tmp_coord[0] - cv_cache->m_ps.m_f_e;
                    srcCoord[1] = tmp_coord[1] - cv_cache->m_ps.m_f_n;
                    srcCoord[2] = tmp_coord[2];

                    if ((status = SRM_ChangeM_CD(&(cv_cache->m_ps.m_cd),
                        srcCoord, desCoord_tmp)) & IMPL_BADSTAT)
                    {
                      SIMPLIFY_STATUS(status);
                    }
                    else if (_validate_coords
                               && ((status |= Impl_validcoord3DMERCATOR_cd(GET_IDATA(src_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for UPS coordinate is UPS
                    else if (_validate_coords && cv_cache->m_ps.is_ups
                               && ((status |= Impl_validcoord3D_UPST_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for PS coordinate is PS
                    else if (_validate_coords && !cv_cache->m_ps.is_ups
                               && ((status |= Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = Impl_ChangeCD_PS(&(cv_cache->m_ps.cd_ps), desCoord_tmp, desCoord))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->m_ps.ps_f_e;
                        desCoord[1] = desCoord[1] + cv_cache->m_ps.ps_f_n;
                        // desCoord[2] = des_coord[2];
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_LCE_3D:
                {
                    if ((status = SRM_ChangeLCE_CC(&(cv_cache->lce3d_ps.lce3d_cc), src_coord.getValues(), desCoord))
                          & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCC_CD(&(cv_cache->lce3d_ps.cc_cd), desCoord, desCoord_tmp))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if (_validate_coords
                               && ((status |= Impl_validcoord3DCELESTIODETIC(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for UPS coordinate is UPS
                    else if (_validate_coords && cv_cache->lce3d_ps.is_ups
                               && ((status |= Impl_validcoord3D_UPST_cd(GET_IDATA(des_srf), desCoord_tmp))
                               & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for PS coordinate is PS
                    else if (_validate_coords && !cv_cache->lce3d_ps.is_ups
                               && ((status |= Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = Impl_ChangeCD_PS(&(cv_cache->lce3d_ps.cd_ps), desCoord_tmp, desCoord))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->lce3d_ps.ps_f_e;
                        desCoord[1] = desCoord[1] + cv_cache->lce3d_ps.ps_f_n;
                        // desCoord[2] = des_coord[2];
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;

                case SRF_TYP_LTSE:
                {
                    const SRM_Long_Float *tmp_coord = src_coord.getValues();

                    srcCoord[0] = tmp_coord[0] - cv_cache->ltse_ps.f_x;
                    srcCoord[1] = tmp_coord[1] - cv_cache->ltse_ps.f_y;
                    srcCoord[2] = tmp_coord[2];
                    srcCoord[3] = 1.0;

                    // only check if it is a GTRS GCS SRF.
                    if (_validate_coords && cv_cache->ltse_ps.is_gtrs
                          && ((status |= Impl_validcoord3D_GCSG(GET_IDATA(src_srf), srcCoord))
                            &   IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeLTE_CC(&(cv_cache->ltse_ps.ltse_cc), srcCoord, desCoord))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if ((status = SRM_ChangeCC_CD(&(cv_cache->ltse_ps.cc_cd), desCoord, desCoord_tmp))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else if (_validate_coords
                               && ((status |= Impl_validcoord3DCELESTIODETIC(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for UPS coordinate is UPS
                    else if (_validate_coords && cv_cache->ltse_ps.is_ups
                               && ((status |= Impl_validcoord3D_UPST_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    // validation for PS coordinate is PS
                    else if (_validate_coords && !cv_cache->ltse_ps.is_ups
                               && ((status |= Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd(GET_IDATA(des_srf), desCoord_tmp))
                                   & IMPL_BADSTAT))
                    {
                      SIMPLIFY_STATUS(status);
                    }
                    else if ((status = Impl_ChangeCD_PS(&(cv_cache->ltse_ps.cd_ps), desCoord_tmp, desCoord))
                               & IMPL_BADSTAT)
                    {
                        SIMPLIFY_STATUS(status);
                    }
                    else
                    {
                        desCoord[0] = desCoord[0] + cv_cache->ltse_ps.ps_f_e;
                        desCoord[1] = desCoord[1] + cv_cache->ltse_ps.ps_f_n;
                        // desCoord[2] = des_coord[2];
                        SIMPLIFY_STATUS(status);
                    }
                }
                break;
            }
        }
    }

    if (doVM)
    {
        status = Impl_changeCoord3DSRF(((SRF_PolarStereographic*)src_srf)->getImpl(),
                                       src_coord.getValues(),
                                       ((SRF_PolarStereographic*)des_srf)->getImpl(),
                                       desCoord);
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
const char* SRF_PolarStereographic::toString()
{
    static char       ret_string[500];
    static char       tmp_buffer[50];
    Impl_Status       status;
    SRM_ORM_Code      orm;
    SRM_RT_Code       rt;
    SRM_PS_Parameters params;

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
    sprintf(tmp_buffer, "polar_aspect=> %i\n", params.polar_aspect);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "origin_longitude=> %f\n", params.origin_longitude);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "central_scale=> %f\n", params.central_scale);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "false_easting=> %f\n", params.false_easting);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "false_northing=> %f\n", params.false_northing);
    strcat(ret_string, tmp_buffer);

    return ret_string;
}

/// the coordinate equality operator
bool Coord3D_PolarStereographic::operator== (const Coord3D_PolarStereographic &rhs) const
{
    return (((*(SRF_PolarStereographic*)(this->_srf)) == (*(SRF_PolarStereographic*)(rhs._srf))) &&
             ARE_EQUAL(_values[0], rhs._values[0]) &&
             ARE_EQUAL(_values[1], rhs._values[1]) &&
             ARE_EQUAL(_values[2], rhs._values[2]));
}

/// the coordinate equality operator
bool CoordSurf_PolarStereographic::operator== (const CoordSurf_PolarStereographic &rhs) const
{
    return (((*(SRF_PolarStereographic*)(this->_srf)) == (*(SRF_PolarStereographic*)(rhs._srf))) &&
             ARE_EQUAL(_values[0], rhs._values[0]) &&
             ARE_EQUAL(_values[1], rhs._values[1]));
}
