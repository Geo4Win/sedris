/** @file BaseSRF.cpp
@author David Shen
@brief BaseSRF SRF body.
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


#if defined(_WIN32) || defined(__CYGWIN__)
#include <windows.h>
#define SRM_LOCKED_INIT                 LONG _s_id = 0
#define SRM_LOCKED_INCREMENT            InterlockedIncrement((LONG *)&_s_id)
#elif defined(__APPLE__)
#include <libkern/OSAtomic.h>
#define SRM_LOCKED_INIT                 int32_t _s_id = 0
#define SRM_LOCKED_INCREMENT            OSAtomicIncrement32Barrier((int32_t*)&_s_id)
#elif defined(__GNUC__)
#define SRM_LOCKED_INIT                 SRM_Integer _s_id = 1
#   if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
#include <ext/atomicity.h>
#define SRM_LOCKED_INCREMENT            __gnu_cxx::__exchange_and_add(&_s_id, 1)
#   elif ((__GNUC__ == 4) && (__GNUC_MINOR__ == 1))
#include <bits/atomicity.h>
#define SRM_LOCKED_INCREMENT            __gnu_cxx::__exchange_and_add(&_s_id, 1)
#   else
#include <bits/atomicity.h>
#define SRM_LOCKED_INCREMENT            __exchange_and_add(&_s_id, 1)
#   endif
#else
#define SRM_LOCKED_INIT                 SRM_Integer _s_id = 0
#define SRM_LOCKED_INCREMENT            ++_s_id
#endif

#include "srf_all.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"
#include "orm_rd_struct.h"

// global variable - controls whether SRF cache is used to speed
// up coordinate conversion operations
bool g_fast_mode = true;

using namespace srm;


BaseSRF::BaseSRF( void *impl ) : _ref_cnt(1), _impl(impl),
      _cache(0), _validate_coords(true)
{
    static volatile SRM_LOCKED_INIT;

    _id = (SRM_Integer) SRM_LOCKED_INCREMENT;
}

// BaseSRF method bodies invoking internal implementation functions
BaseSRF *BaseSRF::createStandardSRF
(
    SRM_SRF_Code srf_code,
    SRM_RT_Code  rt_code
)
{
    Impl_Status status;
    void* impl_ptr;
    BaseSRF* this_srf;

    if (! isLegalSRFCode(srf_code))
        throw Exception(SRM_STATCOD_INVALID_CODE,
                        "createStandardSRF: Invalid SRF code");

    if (! isLegalRTCode (srf_code, rt_code))
        throw Exception(SRM_STATCOD_INVALID_CODE,
                        "createStandardSRF: Invalid RT code");

    status = Impl_createSRFStandard (srf_code, rt_code, &impl_ptr);

    if (status == IMPL_VALID)
        switch (srf_code)
        {
            case SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY: //TM
            case SRM_SRFCOD_BRITISH_OSGRS80_GRID: //TM
            case SRM_SRFCOD_DELAWARE_SPCS_1983: //TM
            case SRM_SRFCOD_IRISH_GRID_1965: //TM
            case SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989: //TM
                 this_srf = new SRF_TransverseMercator(impl_ptr);
                 break;
            case SRM_SRFCOD_GEOCENTRIC_WGS_1984: //CC
                 this_srf = new SRF_Celestiocentric(impl_ptr);
                 break;
            case SRM_SRFCOD_GEODETIC_AUSTRALIA_1984: //CD
            case SRM_SRFCOD_GEODETIC_WGS_1984: //CD
            case SRM_SRFCOD_GEODETIC_N_AMERICAN_1983: //CD
                 this_srf = new SRF_Celestiodetic(impl_ptr);
                 break;
            case SRM_SRFCOD_LAMBERT_93: //LCC
            case SRM_SRFCOD_LAMBERT_II_WIDE: //LCC
            case SRM_SRFCOD_MARYLAND_SPCS_1983: //LCC
                 this_srf = new SRF_LambertConformalConic(impl_ptr);
                 break;
            case SRM_SRFCOD_MARS_PLANETOCENTRIC_2000:
                 this_srf = new SRF_Celestiodetic(impl_ptr);
                 break;
            case SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000:
                 this_srf = new SRF_Planetodetic(impl_ptr);
                 break;
            default:
                 // this should never be reached
                 throw Exception(SRM_STATCOD_INACTIONABLE,
                                 "createStandardSRF: Inactionable failure");
        }
    else
        processStatus(status, "createStandardSRF", SRF, CREATE);

    return this_srf;
}

BaseSRF *BaseSRF::createSRFSetMember
(
    SRM_SRFS_Info srfs_info,
    SRM_RT_Code   rt
)
{
    Impl_Status status;
    void* impl_ptr;
    BaseSRF* this_srf;
    bool validSetMemberCode = true;
    bool validOrmCode = true;

    if (! isLegalSRFSetCode (srfs_info.srfs_code_info.srfs_code))
        throw Exception(SRM_STATCOD_INVALID_CODE,
                        "createSRFSetMember: Invalid SRF set code");

    switch (srfs_info.srfs_code_info.srfs_code)
    {
        case SRM_SRFSCOD_ALABAMA_SPCS:
             if (srfs_info.srfs_code_info.value.srfsm_alabama_spcs < 1 ||
                 srfs_info.srfs_code_info.value.srfsm_alabama_spcs >
                 SRM_SRFSM_ALABAMA_SPCS_CODE_UBOUND)
             {
                 validSetMemberCode = false;
             }
             if (srfs_info.orm_code != SRM_ORMCOD_N_AM_1983)
                 validOrmCode = false;
             break;
        case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM:
             if (srfs_info.srfs_code_info.value.srfsm_gtrs_gcs < 1 ||
                 srfs_info.srfs_code_info.value.srfsm_gtrs_gcs >
                 SRM_SRFSM_GTRS_GLOBAL_COORDINATE_SYSTEM_CODE_UBOUND)
             {
                 validSetMemberCode = false;
             }
             // this SRFS takes any ORM that the LTSE SRFT takes
             // which is checked later.
             break;
        case SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS:
             if (srfs_info.srfs_code_info.value.
                 srfsm_japan_rectangular_plane_cs < 1 ||
                 srfs_info.srfs_code_info.value.
                 srfsm_japan_rectangular_plane_cs >
                 SRM_SRFSM_JAPAN_RECTANGULAR_PLANE_CS_CODE_UBOUND)
             {
                 validSetMemberCode = false;
             }
             if (srfs_info.orm_code != SRM_ORMCOD_JGD_2000)
                 validOrmCode = false;
             break;
        case SRM_SRFSCOD_LAMBERT_NTF:
             if (srfs_info.srfs_code_info.value.srfsm_lambert_ntf < 1 ||
                 srfs_info.srfs_code_info.value.srfsm_lambert_ntf >
                 SRM_SRFSM_LAMBERT_NTF_CODE_UBOUND)
             {
                 validSetMemberCode = false;
             }
             if (srfs_info.orm_code != SRM_ORMCOD_NTF_1896_PM_PARIS)
                 validOrmCode = false;
             break;
        case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC:
             if (srfs_info.srfs_code_info.value.srfsm_ups < 1 ||
                 srfs_info.srfs_code_info.value.srfsm_ups >
                 SRM_SRFSM_UPS_CODE_UBOUND)
             {
                 validSetMemberCode = false;
             }
             // this SRFS takes any ORM that the LTSE SRFT takes
             // which is checked later.
             break;
        case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR:
             if (srfs_info.srfs_code_info.value.srfsm_utm < 1 ||
                 srfs_info.srfs_code_info.value.srfsm_utm >
                 SRM_SRFSM_UTM_CODE_UBOUND)
             {
                 validSetMemberCode = false;
             }
             // this SRFS takes any ORM that the LTSE SRFT takes
             // which is checked later.
             break;
        case SRM_SRFSCOD_WISCONSIN_SPCS:
             if (srfs_info.srfs_code_info.value.srfsm_wisconsin_spcs < 1 ||
                 srfs_info.srfs_code_info.value.srfsm_wisconsin_spcs >
                 SRM_SRFSM_WISCONSIN_SPCS_CODE_UBOUND)
             {
                 validSetMemberCode = false;
             }
             if (srfs_info.orm_code != SRM_ORMCOD_N_AM_1983)
                 validOrmCode = false;
             break;
        default:
             // this should never be reached
             throw Exception(SRM_STATCOD_INACTIONABLE,
                             "createSRFSetMember: Inactionable failure");
    }

    if (!validSetMemberCode)
        throw Exception(SRM_STATCOD_INVALID_CODE,
                        "createSRFSetMember: Invalid SRF set member code");

    if (!validOrmCode)
        throw Exception(SRM_STATCOD_INVALID_CODE,
                        "createSRFSetMember: Invalid ORM code");

    if (!isLegalORMCode (srfs_info.orm_code, rt))
        throw Exception(SRM_STATCOD_INVALID_CODE,
                        "createSRFSetMember: Invalid RT code");

    status = Impl_createSRFSetMember(srfs_info, rt, &impl_ptr);

    if (status == IMPL_VALID)
        switch (srfs_info.srfs_code_info.srfs_code)
        {
            case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM: //LTE
                 this_srf = new SRF_LocalTangentSpaceEuclidean(impl_ptr);
                 break;
            case SRM_SRFSCOD_LAMBERT_NTF: //LCC
            case SRM_SRFSCOD_WISCONSIN_SPCS: //LCC
                 this_srf = new SRF_LambertConformalConic(impl_ptr);
                 break;
            case SRM_SRFSCOD_ALABAMA_SPCS: //TM
            case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR: //TM
            case SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS: //TM
                 this_srf = new SRF_TransverseMercator(impl_ptr);
                 break;
            case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC: //PS
                 this_srf = new SRF_PolarStereographic(impl_ptr);
                 break;
            default:
                 // this should never be reached
                 throw Exception(SRM_STATCOD_INACTIONABLE,
                                 "createSRFSetMember: Inactionable failure");
          }
    else
        processStatus(status, "createSRFSetMember", SRF, CREATE);

    return this_srf;
}


void BaseSRF::getCodes
(
    SRM_SRFT_Code       &t_code,
    SRM_SRF_Code        &srf_code,
    SRM_SRFS_Code_Info  &srfs_code_info
) const
{
    Impl_Status status;

    status = Impl_getCodes(_impl, &srf_code,
                            &t_code, &srfs_code_info);

    if (status != IMPL_VALID)
        processStatus(status, "getCodes");
}


SRM_ORM_Code BaseSRF::get_orm() const
{
    return getOrm();
}


SRM_ORM_Code BaseSRF::getOrm() const
{
    Impl_Status status;
    SRM_ORM_Code orm;

    status = Impl_getORM(_impl, &orm);

    if (status != IMPL_VALID)
        processStatus(status, "getOrm");

    return orm;
}

SRM_RT_Code BaseSRF::get_rt() const
{
    return getRt();
}

SRM_RT_Code BaseSRF::getRt() const
{
    Impl_Status status;
    SRM_RT_Code rt;

    status = Impl_getRT(_impl, &rt);

    if (status != IMPL_VALID)
        processStatus(status, "getRt");

    return rt;
}

SRM_Long_Float BaseSRF::getA() const
{
    Impl_Status status;
    SRM_Long_Float a;

    status = Impl_getA( _impl, &a);

    if (status != IMPL_VALID)
        processStatus( status, "getA");

    return a;
}


SRM_Long_Float BaseSRF::getF() const
{
    Impl_Status status;
    SRM_Long_Float f;

    status = Impl_getF( _impl, &f);

    if (status != IMPL_VALID)
        processStatus( status, "getF");

    return f;
}


SRM_CS_Code BaseSRF::getCSCode() const
{
    Impl_Status status;
    SRM_CS_Code cs;

    status = Impl_getCSCode(_impl, &cs);

    if (status != IMPL_VALID)
        processStatus(status, "getCSCode");

    return cs;
}


bool BaseSRF::querySRFTSupport(SRM_SRFT_Code srft_code)
{
    if (! isLegalSRFTCode(srft_code))
        throw Exception(SRM_STATCOD_INVALID_CODE,
                        "querySRFTSupport: Invalid SRFT code");

    // all the SRFTs are supported
    return true;
}


bool BaseSRF::queryORMSupport
(
    SRM_ORM_Code orm_code,
    SRM_RT_Code  rt_code
)
{
    if (! Impl_wellFormedORMCode(orm_code))
        throw Exception(SRM_STATCOD_INVALID_CODE,
                        "queryORMSupport: Invalid ORM code");

    return Impl_wellFormedRTCode(orm_code, rt_code);
}


SRM_Coordinate_Valid_Region BaseSRF::changeCoordinateSRF
(
    const Coord &src_coord,
          Coord &des_coord
)
{
    Impl_Status status;
    SRM_Long_Float desCoord2D[2], desCoord3D[3];
    SRM_Coordinate_Valid_Region ret_validity;

    if (des_coord.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE,
                        "changeCoordinateSRF: "\
                        "Target coordinate associated with a different SRF");

    if (src_coord.isA(Coord::COORD_TYP_TWO_D) &&
        des_coord.isA(Coord::COORD_TYP_TWO_D))
    {
        // change SRF
        status = Impl_changeCoord2DSRF
                 (
                     src_coord.getSRF()->_impl,
                     (dynamic_cast<const Coord2D&>(src_coord)).getValues(),
                     des_coord.getSRF()->_impl, desCoord2D
                 );

        // set the coordinate values if status is "valid"
        if (status == IMPL_VALID ||
            status == IMPL_EXTENDED ||
            status == IMPL_DEFINED)
        {
            (dynamic_cast<Coord2D&>(des_coord)).setValues(desCoord2D);

            if (status == IMPL_VALID)
                ret_validity = SRM_COORDVALRGN_VALID;
            else if (status == IMPL_EXTENDED)
                ret_validity =  SRM_COORDVALRGN_EXTENDED_VALID;
            else if (status == IMPL_DEFINED)
                ret_validity =  SRM_COORDVALRGN_DEFINED;
        }
        else
            processStatus(status, "changeCoordinateSRF", COORD, MEM);
    }
    else if (src_coord.isA(Coord::COORD_TYP_THREE_D) &&
             des_coord.isA(Coord::COORD_TYP_THREE_D))
    {
        ret_validity = ((BaseSRF_3D*)(des_coord.getSRF()))->changeCoordinate3DSRF((dynamic_cast<const Coord3D&>(src_coord)),
                                          (dynamic_cast<Coord3D&>(des_coord)));

    }
    else if (src_coord.isA(Coord::COORD_TYP_SURFACE) &&
             des_coord.isA(Coord::COORD_TYP_SURFACE))
    {
        SRM_Long_Float srcCoord3D[3];
        const SRM_Long_Float * srcCoord2D;

        srcCoord2D = (dynamic_cast<const CoordSurf&>(src_coord)).getValues();

        srcCoord3D[0] = srcCoord2D[0];
        srcCoord3D[1] = srcCoord2D[1];
        srcCoord3D[2] = 0.0;

        // change SRF
        status = Impl_changeCoord3DSRF(src_coord.getSRF()->_impl, srcCoord3D,
                                       des_coord.getSRF()->_impl, desCoord3D);

        desCoord2D[0] = desCoord3D[0];
        desCoord2D[1] = desCoord3D[1];

        // set the coordinate values if status is "valid"
        if (status == IMPL_VALID ||
            status == IMPL_EXTENDED ||
            status == IMPL_DEFINED)
        {
            (dynamic_cast<CoordSurf&>(des_coord)).setValues(desCoord2D);

            if (status == IMPL_VALID)
                ret_validity = SRM_COORDVALRGN_VALID;
            else if (status == IMPL_EXTENDED)
                ret_validity =  SRM_COORDVALRGN_EXTENDED_VALID;
            else if (status == IMPL_DEFINED)
                ret_validity =  SRM_COORDVALRGN_DEFINED;
        }
        else
            processStatus(status, "changeCoordinateSRF", COORD, MEM);
    }
    // raise exception if the src and des coord are not of same dimension
    else
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE,
                        "changeCoordinateSRF: Source and destination coordinates of different dimensions");

    return ret_validity;
}

SRM_Coordinate_Valid_Region BaseSRF::checkCoordinate(const Coord &src)
{
    Impl_Status status;
    SRM_Coordinate_Valid_Region ret_validity;

    if (src.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "checkCoordinate: Source coordinate associated with a different SRF");

    if (src.isA(Coord::COORD_TYP_TWO_D))
        status = Impl_checkCoordinate2D
                 (src.getSRF()->_impl,
                  (dynamic_cast<const Coord2D&>(src)).getValues());
    else if (src.isA(Coord::COORD_TYP_THREE_D))
        status = Impl_checkCoordinate3D
                 (src.getSRF()->_impl,
                  (dynamic_cast<const Coord3D&>(src)).getValues());
    else  // must be a surface coordinate
        status = Impl_checkCoordinateSurface
                 (src.getSRF()->_impl,
                 (dynamic_cast<const CoordSurf&>(src)).getValues());

    if (status == IMPL_VALID)
        ret_validity = SRM_COORDVALRGN_VALID;
    else if (status == IMPL_EXTENDED)
        ret_validity = SRM_COORDVALRGN_EXTENDED_VALID;
    else if (status == IMPL_DEFINED)
        ret_validity = SRM_COORDVALRGN_DEFINED;
    else
        processStatus(status, "checkCoordinate", COORD, MEM);

    return ret_validity;
}


void BaseSRF::freeCoordinate(Coord *coord)
{
    if (coord->getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE,
                "freeCoordinate: Coordinate not associated with this SRF");

    try
    {
        Coord::Coord_ClassType coord_type = coord->getClassType();

        if (coord_type == Coord::COORD_TYP_THREE_D)
            delete((Coord3D*)coord);
        if (coord_type == Coord::COORD_TYP_TWO_D)
            delete((Coord2D*)coord);
        else
            delete((CoordSurf*)coord);
    }
    catch (...)
    {
        throw  Exception(SRM_STATCOD_DESTRUCTION_FAILURE,
                         "freeCoordinate: Destruction Failure");
    }
}


SRM_Long_Float BaseSRF::calculateEuclideanDistance
(
    const Coord &coord1,
    const Coord &coord2
)
{
    Impl_Status status;
    SRM_Long_Float ret_distance;

    // calculate distance if coordinates are of same dimension
    // otherwise raise exception
    if (coord1.isA(Coord::COORD_TYP_THREE_D) &&
        coord2.isA(Coord::COORD_TYP_THREE_D))
    {
        status = Impl_calculateEuclideanDistance
                 (coord1.getSRF()->_impl,
                  (dynamic_cast<const Coord3D&>(coord1)).getValues(),
                  coord2.getSRF()->_impl,
                  (dynamic_cast<const Coord3D&>(coord2)).getValues(),
                  &ret_distance);
    }
    else if (coord1.isA(Coord::COORD_TYP_TWO_D) &&
             coord2.isA(Coord::COORD_TYP_TWO_D))
    {
        status = Impl_calculateEuclideanDistance2D
                 (coord1.getSRF()->_impl,
                  (dynamic_cast<const Coord2D&>(coord1)).getValues(),
                  coord2.getSRF()->_impl,
                  (dynamic_cast<const Coord2D&>(coord2)).getValues(),
                  &ret_distance);
    }
    else if (coord1.isA(Coord::COORD_TYP_SURFACE) &&
             coord2.isA(Coord::COORD_TYP_SURFACE))
    {
        status = Impl_calculateEuclideanDistanceSurface
                 (coord1.getSRF()->_impl,
                  (dynamic_cast<const CoordSurf&>(coord1)).getValues(),
                  coord2.getSRF()->_impl,
                  (dynamic_cast<const CoordSurf&>(coord2)).getValues(),
                  &ret_distance);
    }
    else
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE,
                        "calculateEuclideanDistance: Source and destination"\
                        " coordinates of different dimensions");

    if (status != IMPL_VALID &&
        status != IMPL_EXTENDED &&
        status != IMPL_DEFINED)
    {
        processStatus(status, "calculateEuclideanDistance", COORD, MEM);
    }
    // return distance if status is valid.
    return ret_distance;
}


void BaseSRF::setCoordinateValidationOn()
{
    Impl_setValidateCoordinate( _impl, true );
    _validate_coords = true;
}


void BaseSRF::setCoordinateValidationOff()
{
    Impl_setValidateCoordinate( _impl, false );
    _validate_coords = false;
}

bool BaseSRF::coordinateValidationIsOn()
{
    return _validate_coords;
}


void BaseSRF::release()
{
    if (_ref_cnt == 1)
    {
        _ref_cnt = 0;
        // release internal structures
        try
        {
            Impl_releaseSRF(&_impl);
            delete this;
        }
        catch (...)
        {
            throw  Exception(SRM_STATCOD_DESTRUCTION_FAILURE,
                             "release: Destruction Failure");
        }
    }
    else if (_ref_cnt > 1)
        --_ref_cnt;
}
