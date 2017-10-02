/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/31
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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


/** @file seHelperSRM.cpp
@author Warren Macchi (Accent Geographic)
@brief seHelperSRM implementation.
*/

#include "include/seHelperSRM.h"
#include "include/seTransmittal.h"
#include "include/seException.h"
#include "include/seDRMAll.h"
#include "seCore.h"

#include "Coord.h"

#include <string.h>

using namespace sedris;


__RCSID("$Id: seHelperSRM.cpp,v 1.4 2006-07-25 20:35:36-04 shend Exp $");


seHelperSRM::seHelperSRM() : _srf(NULL)
{
}


seHelperSRM::seHelperSRM( const seHelperSRM& other )
 : _srf(NULL)
{
    if (other._srf)
    {
        _srf = other._srf->clone();
    }
}


seHelperSRM& seHelperSRM::operator=( const seHelperSRM& other )
{
    reset();

    if (other._srf)
    {
        _srf = other._srf->clone();
    }

    return *this;
}


seHelperSRM::~seHelperSRM()
{
    reset();
}


void seHelperSRM::reset()
{
    if ( _srf )
    {
        _srf->release();
        _srf = NULL;
    }
}


void seHelperSRM::init( const SRM_SRF_Parameters_Info &srf_params_info )
{
    reset();

    if ( srf_params_info.srf_params_info_code == SRM_SRFPARAMINFCOD_INSTANCE )
    {
        _srf = srm::BaseSRF::createStandardSRF(
                                srf_params_info.value.srf_instance,
                                srf_params_info.rt_code);
    }
    else if ( srf_params_info.srf_params_info_code == SRM_SRFPARAMINFCOD_SET )
    {
        _srf = srm::BaseSRF::createSRFSetMember(
                                srf_params_info.value.srf_set,
                                srf_params_info.rt_code);
    }
    else
        SE_ThrowEx("seHelperSRM: can't handle SRF_Info parameters");
}


srm::Coord *seHelperSRM::createCoordinate( const seDRMLocation &loc_obj ) const
{
    srm::BaseSRF_3D *srf_3d = NULL;
    srm::BaseSRF_2D *srf_2d = NULL;
    srm::BaseSRF_WithTangentPlaneSurface *srf_tpsurf = NULL;
    srm::BaseSRF_WithEllipsoidalHeight *srf_ellip = NULL;
    bool srf_mismatch = false;

    if ( !_srf )
        SE_ThrowEx("seHelperSRM: helper is not initialized");
    else if ( _srf->isA(srm::BaseSRF::SRF_TYP_TWO_D) )
        srf_2d = dynamic_cast<srm::BaseSRF_2D *>(_srf);
    else if ( _srf->isA(srm::BaseSRF::SRF_TYP_THREE_D) )
        srf_3d = dynamic_cast<srm::BaseSRF_3D *>(_srf);
    else
        SE_ThrowEx("seHelperSRM: can't handle SRF type");

    if ( _srf->isA(srm::BaseSRF::SRF_TYP_WITH_TANGENT_PLANE_SURFACE) )
        srf_tpsurf = dynamic_cast<srm::BaseSRF_WithTangentPlaneSurface *>(_srf);
    else if ( _srf->isA(srm::BaseSRF::SRF_TYP_WITH_ELLIPSOIDAL_HEIGHT) )
        srf_ellip = dynamic_cast<srm::BaseSRF_WithEllipsoidalHeight *>(_srf);

    switch ( loc_obj.getDRMClass() )
    {
    case SE_CLS_DRM_LSA_2D_LOCATION:
        if ( srf_2d )
        {
            seDRMLSA2DLocation loc(loc_obj);

            return srf_2d->createCoordinate2D(
                    loc.get_coordinate().azimuth,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_CC_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMCC3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().u,
                    loc.get_coordinate().v,
                    loc.get_coordinate().w);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_CD_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMCD3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().ellipsoidal_height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_CD_SURFACE_LOCATION:
        if ( srf_ellip )
        {
            seDRMCDSurfaceLocation loc(loc_obj);

            return srf_ellip->createSurfaceCoordinate(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_CM_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMCM3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMECAugmented3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing,
                    loc.get_coordinate().ellipsoidal_height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_EC_SURFACE_LOCATION:
        if ( srf_ellip )
        {
            seDRMECSurfaceLocation loc(loc_obj);

            return srf_ellip->createSurfaceCoordinate(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_EI_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMEI3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().right_ascension,
                    loc.get_coordinate().declination,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_HAEC_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMHAEC3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_HEEC_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMHEEC3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_HEEQ_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMHEEQ3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMLCCAugmented3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing,
                    loc.get_coordinate().ellipsoidal_height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LCC_SURFACE_LOCATION:
        if ( srf_ellip )
        {
            seDRMLCCSurfaceLocation loc(loc_obj);

            return srf_ellip->createSurfaceCoordinate(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LCE_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMLCE3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().u,
                    loc.get_coordinate().v,
                    loc.get_coordinate().w);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LSR_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMLSR3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().u,
                    loc.get_coordinate().v,
                    loc.get_coordinate().w);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LSR_2D_LOCATION:
        if ( srf_2d )
        {
            seDRMLSR2DLocation loc(loc_obj);

            return srf_2d->createCoordinate2D(
                    loc.get_coordinate().u,
                    loc.get_coordinate().v);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LTSAS_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMLTSAS3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().azimuth,
                    loc.get_coordinate().angle,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LTSAS_SURFACE_LOCATION:
        if ( srf_tpsurf )
        {
            seDRMLTSASSurfaceLocation loc(loc_obj);

            return srf_tpsurf->createSurfaceCoordinate(
                    loc.get_coordinate().azimuth,
                    loc.get_coordinate().angle);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LTSC_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMLTSC3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().angle,
                    loc.get_coordinate().radius,
                    loc.get_coordinate().height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LTSC_SURFACE_LOCATION:
        if ( srf_tpsurf )
        {
            seDRMLTSCSurfaceLocation loc(loc_obj);

            return srf_tpsurf->createSurfaceCoordinate(
                    loc.get_coordinate().angle,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LTSE_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMLTSE3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().x,
                    loc.get_coordinate().y,
                    loc.get_coordinate().height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LTSE_SURFACE_LOCATION:
        if ( srf_tpsurf )
        {
            seDRMLTSESurfaceLocation loc(loc_obj);

            return srf_tpsurf->createSurfaceCoordinate(
                    loc.get_coordinate().x,
                    loc.get_coordinate().y);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_M_AUGMENTED_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMMAugmented3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing,
                    loc.get_coordinate().ellipsoidal_height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_M_SURFACE_LOCATION:
        if ( srf_ellip )
        {
            seDRMMSurfaceLocation loc(loc_obj);

            return srf_ellip->createSurfaceCoordinate(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMOMSAugmented3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing,
                    loc.get_coordinate().ellipsoidal_height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_OMS_SURFACE_LOCATION:
        if ( srf_ellip )
        {
            seDRMOMSSurfaceLocation loc(loc_obj);

            return srf_ellip->createSurfaceCoordinate(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_LSP_2D_LOCATION:
        if ( srf_2d )
        {
            seDRMLSP2DLocation loc(loc_obj);

            return srf_2d->createCoordinate2D(
                    loc.get_coordinate().angle,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMPSAugmented3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing,
                    loc.get_coordinate().ellipsoidal_height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_PS_SURFACE_LOCATION:
        if ( srf_ellip )
        {
            seDRMPSSurfaceLocation loc(loc_obj);

            return srf_ellip->createSurfaceCoordinate(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_PD_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMPD3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().ellipsoidal_height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_PD_SURFACE_LOCATION:
        if ( srf_ellip )
        {
            seDRMPDSurfaceLocation loc(loc_obj);

            return srf_ellip->createSurfaceCoordinate(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_SEC_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMSEC3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_SEQ_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMSEQ3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_SME_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMSME3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_SMD_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMSMD3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().longitude,
                    loc.get_coordinate().latitude,
                    loc.get_coordinate().radius);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION:
        if ( srf_3d )
        {
            seDRMTMAugmented3DLocation loc(loc_obj);

            return srf_3d->createCoordinate3D(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing,
                    loc.get_coordinate().ellipsoidal_height);
        }
        else
            srf_mismatch = true;
    	break;

    case SE_CLS_DRM_TM_SURFACE_LOCATION:
        if ( srf_ellip )
        {
            seDRMTMSurfaceLocation loc(loc_obj);

            return srf_ellip->createSurfaceCoordinate(
                    loc.get_coordinate().easting,
                    loc.get_coordinate().northing);
        }
        else
            srf_mismatch = true;
    	break;

    default:
        SE_ThrowEx("seHelperSRM: can't handle %s", loc_obj.getDRMClassName());
        break;
    }

    if ( srf_mismatch )
        SE_ThrowEx("seHelperSRM: SRF mismatch for %s", loc_obj.getDRMClassName());
    else
        SE_ThrowEx("seHelperSRM: couldn't handle %s", loc_obj.getDRMClassName());

    return NULL;
}


void seHelperSRM::freeCoordinate( srm::Coord *coord )
{
    bool srf_mismatch = false;

    if ( !coord )
        SE_ThrowEx("seHelperSRM: invalid coordinate");

    srm::BaseSRF *srf = coord->getSRF();

    if ( coord->isA(srm::Coord::COORD_TYP_TWO_D) )
    {
        srm::Coord2D *coord_2d = dynamic_cast<srm::Coord2D *>(coord);
        srm::BaseSRF_2D *srf_2d = dynamic_cast<srm::BaseSRF_2D *>(srf);

        if ( srf_2d )
            srf_2d->freeCoordinate2D(coord_2d);
        else
            srf_mismatch = true;
    }
    else if ( coord->isA(srm::Coord::COORD_TYP_SURFACE) )
    {
        srm::CoordSurf *coord_surf = dynamic_cast<srm::CoordSurf *>(coord);
        srm::BaseSRF_WithTangentPlaneSurface *srf_tpsurf =
                    dynamic_cast<srm::BaseSRF_WithTangentPlaneSurface *>(srf);

        if ( srf_tpsurf )
            srf_tpsurf->freeSurfaceCoordinate(coord_surf);
        else
        {
            srm::BaseSRF_WithEllipsoidalHeight *srf_ellip =
                        dynamic_cast<srm::BaseSRF_WithEllipsoidalHeight *>(srf);

            if ( srf_ellip )
                srf_ellip->freeSurfaceCoordinate(coord_surf);
            else
                srf_mismatch = true;
        }
    }
    else if ( coord->isA(srm::Coord::COORD_TYP_THREE_D) )
    {
        srm::Coord3D *coord_3d = dynamic_cast<srm::Coord3D *>(coord);
        srm::BaseSRF_3D *srf_3d = dynamic_cast<srm::BaseSRF_3D *>(srf);

        if ( srf_3d )
            srf_3d->freeCoordinate3D(coord_3d);
        else
            srf_mismatch = true;
    }
    else
        SE_ThrowEx("seHelperSRM: can't handle coordinate type");

    if ( srf_mismatch )
        SE_ThrowEx("seHelperSRM: SRF <> coordinate mismatch");
}


void seHelperSRM::createDRMLocation
(
    seTransmittal &xmtal,
    const srm::Coord &coord,
    seDRMLocation &loc_obj
)
{
    switch ( coord.getClassType() )
    {
    case srm::Coord::COORD_TYP_LSA:
        {
            seDRMLSA2DLocation loc;
            const srm::Coord2D_LSA& loc_coord =
                dynamic_cast<const srm::Coord2D_LSA&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LSA_2D_LOCATION);
            loc.set_coordinate(loc_coord.get_azimuth(), loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_CC:
        {
            seDRMCC3DLocation loc;
            const srm::Coord3D_CC &loc_coord =
                dynamic_cast<const srm::Coord3D_CC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_CC_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_u(), loc_coord.get_v(),
                                loc_coord.get_w());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_CD:
        {
            seDRMCD3DLocation loc;
            const srm::Coord3D_CD &loc_coord =
                dynamic_cast<const srm::Coord3D_CD&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_CD_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(), loc_coord.get_latitude(),
                                loc_coord.get_ellipsoidal_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_CD:
        {
            seDRMCDSurfaceLocation loc;
            const srm::CoordSurf_CD &loc_coord =
                dynamic_cast<const srm::CoordSurf_CD&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_CD_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_CM:
        {
            seDRMCM3DLocation loc;
            const srm::Coord3D_CM &loc_coord =
                dynamic_cast<const srm::Coord3D_CM&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_CM_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_EC:
        {
            seDRMECAugmented3DLocation loc;
            const srm::Coord3D_EC &loc_coord =
                dynamic_cast<const srm::Coord3D_EC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing(),
                                loc_coord.get_ellipsoidal_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_EC:
        {
            seDRMECSurfaceLocation loc;
            const srm::CoordSurf_EC &loc_coord =
                dynamic_cast<const srm::CoordSurf_EC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_EC_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_EI:
        {
            seDRMEI3DLocation loc;
            const srm::Coord3D_EI &loc_coord =
                dynamic_cast<const srm::Coord3D_EI&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_EI_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_right_ascension(),
                                loc_coord.get_declination(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_HAEC:
        {
            seDRMHAEC3DLocation loc;
            const srm::Coord3D_HAEC &loc_coord =
                dynamic_cast<const srm::Coord3D_HAEC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_HAEC_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_HEEC:
        {
            seDRMHEEC3DLocation loc;
            const srm::Coord3D_HEEC &loc_coord =
                dynamic_cast<const srm::Coord3D_HEEC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_HEEC_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_HEEQ:
        {
            seDRMHEEQ3DLocation loc;
            const srm::Coord3D_HEEQ &loc_coord =
                dynamic_cast<const srm::Coord3D_HEEQ&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_HEEQ_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_LCC:
        {
            seDRMLCCAugmented3DLocation loc;
            const srm::Coord3D_LCC &loc_coord =
                dynamic_cast<const srm::Coord3D_LCC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing(),
                                loc_coord.get_ellipsoidal_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_LCC:
        {
            seDRMLCCSurfaceLocation loc;
            const srm::CoordSurf_LCC &loc_coord =
                dynamic_cast<const srm::CoordSurf_LCC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LCC_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_LCE_3D:
        {
            seDRMLCE3DLocation loc;
            const srm::Coord3D_LCE_3D &loc_coord =
                dynamic_cast<const srm::Coord3D_LCE_3D&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LCE_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_u(), loc_coord.get_v(),
                                loc_coord.get_w());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_LSR_3D:
        {
            seDRMLSR3DLocation loc;
            const srm::Coord3D_LSR_3D &loc_coord =
                dynamic_cast<const srm::Coord3D_LSR_3D&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LSR_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_u(), loc_coord.get_v(),
                                loc_coord.get_w());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_LSR_2D:
        {
            seDRMLSR2DLocation loc;
            const srm::Coord2D_LocalSpaceRectangular2D &loc_coord =
                dynamic_cast<const srm::Coord2D_LocalSpaceRectangular2D&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LSR_2D_LOCATION);
            loc.set_coordinate(loc_coord.get_u(), loc_coord.get_v());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_LTSAS:
        {
            seDRMLTSAS3DLocation loc;
            const srm::Coord3D_LTSAS &loc_coord =
                dynamic_cast<const srm::Coord3D_LTSAS&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LTSAS_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_azimuth(), loc_coord.get_angle(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_LTSAS:
        {
            seDRMLTSASSurfaceLocation loc;
            const srm::CoordSurf_LTSAS &loc_coord =
                dynamic_cast<const srm::CoordSurf_LTSAS&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LTSAS_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_azimuth(), loc_coord.get_angle());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_LTSC:
        {
            seDRMLTSC3DLocation loc;
            const srm::Coord3D_LTSC &loc_coord =
                dynamic_cast<const srm::Coord3D_LTSC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LTSC_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_angle(), loc_coord.get_radius(),
                                loc_coord.get_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_LTSC:
        {
            seDRMLTSCSurfaceLocation loc;
            const srm::CoordSurf_LTSC &loc_coord =
                dynamic_cast<const srm::CoordSurf_LTSC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LTSC_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_angle(), loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_LTSE:
        {
            seDRMLTSE3DLocation loc;
            const srm::Coord3D_LTSE &loc_coord =
                dynamic_cast<const srm::Coord3D_LTSE&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LTSE_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_x(), loc_coord.get_y(),
                                loc_coord.get_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_LTSE:
        {
            seDRMLTSESurfaceLocation loc;
            const srm::CoordSurf_LTSE &loc_coord =
                dynamic_cast<const srm::CoordSurf_LTSE&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LTSE_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_x(), loc_coord.get_y());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_M:
        {
            seDRMMAugmented3DLocation loc;
            const srm::Coord3D_M &loc_coord =
                dynamic_cast<const srm::Coord3D_M&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_M_AUGMENTED_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing(),
                                loc_coord.get_ellipsoidal_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_M:
        {
            seDRMMSurfaceLocation loc;
            const srm::CoordSurf_Mercator &loc_coord =
                dynamic_cast<const srm::CoordSurf_Mercator&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_M_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_OMS:
        {
            seDRMOMSAugmented3DLocation loc;
            const srm::Coord3D_OMS &loc_coord =
                dynamic_cast<const srm::Coord3D_OMS&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing(),
                                loc_coord.get_ellipsoidal_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_OMS:
        {
            seDRMOMSSurfaceLocation loc;
            const srm::CoordSurf_OMS &loc_coord =
                dynamic_cast<const srm::CoordSurf_OMS&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_OMS_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_LSP:
        {
            seDRMLSP2DLocation loc;
            const srm::Coord2D_LSP &loc_coord =
                dynamic_cast<const srm::Coord2D_LSP&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_LSP_2D_LOCATION);
            loc.set_coordinate(loc_coord.get_angle(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_PS:
        {
            seDRMPSAugmented3DLocation loc;
            const srm::Coord3D_PS &loc_coord =
                dynamic_cast<const srm::Coord3D_PS&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing(),
                                loc_coord.get_ellipsoidal_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_PS:
        {
            seDRMPSSurfaceLocation loc;
            const srm::CoordSurf_PS &loc_coord =
                dynamic_cast<const srm::CoordSurf_PS&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_PS_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_PD:
        {
            seDRMPD3DLocation loc;
            const srm::Coord3D_PD &loc_coord =
                dynamic_cast<const srm::Coord3D_PD&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_PD_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_ellipsoidal_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_PD:
        {
            seDRMPDSurfaceLocation loc;
            const srm::CoordSurf_PD &loc_coord =
                dynamic_cast<const srm::CoordSurf_PD&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_PD_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SEC:
        {
            seDRMSEC3DLocation loc;
            const srm::Coord3D_SEC &loc_coord =
                dynamic_cast<const srm::Coord3D_SEC&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_SEC_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SEQ:
        {
            seDRMSEQ3DLocation loc;
            const srm::Coord3D_SEQ &loc_coord =
                dynamic_cast<const srm::Coord3D_SEQ&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_SEQ_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SME:
        {
            seDRMSME3DLocation loc;
            const srm::Coord3D_SME &loc_coord =
                dynamic_cast<const srm::Coord3D_SME&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_SME_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SMD:
        {
            seDRMSMD3DLocation loc;
            const srm::Coord3D_SMD &loc_coord =
                dynamic_cast<const srm::Coord3D_SMD&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_SMD_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_longitude(),
                                loc_coord.get_latitude(),
                                loc_coord.get_radius());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_TM:
        {
            seDRMTMAugmented3DLocation loc;
            const srm::Coord3D_TM &loc_coord =
                dynamic_cast<const srm::Coord3D_TM&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing(),
                                loc_coord.get_ellipsoidal_height());
            loc_obj = loc;
        }
    	break;

    case srm::Coord::COORD_TYP_SURF_TM:
        {
            seDRMTMSurfaceLocation loc;
            const srm::CoordSurf_TM &loc_coord =
                dynamic_cast<const srm::CoordSurf_TM&>(coord);

            xmtal.createObject(loc, SE_CLS_DRM_TM_SURFACE_LOCATION);
            loc.set_coordinate(loc_coord.get_easting(),
                                loc_coord.get_northing());
            loc_obj = loc;
        }
    	break;

    default:
        SE_ThrowEx("seHelperSRM: can't handle SRM coordinate type");
        break;
    }
}
