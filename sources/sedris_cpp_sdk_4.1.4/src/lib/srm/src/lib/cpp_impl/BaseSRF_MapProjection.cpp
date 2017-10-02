/** @file BaseSRF_MapProjection.cpp
@author David Shen
@brief BaseSRF_MapProjection SRF body.
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


#include "BaseSRF.h"
#include "Coord.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"

using namespace srm;

void BaseSRF_MapProjection::setValidGeodeticRegion
(
    const SRM_Integer       component,
    const SRM_Interval_Type type,
    const SRM_Long_Float    lower,
    const SRM_Long_Float    upper
)
{
    Impl_Status status;

    if (component < 1 || component > 2)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidGeodeticRegion: component out of range [ 1, 2 ]");

    if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL )
        throw Exception(SRM_STATCOD_INVALID_INPUT,
                         "setValidGeodeticRegion: cannot be a semi-interval region");

    if (component == 1 && !(type==SRM_IVLTYP_UNBOUNDED) &&
        lower<=-SRM_PI && lower>SRM_PI &&
        upper<=-SRM_PI && upper>SRM_PI)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidGeodeticRegion: component 1 (longitude) out of range (-PI, PI]");

    if (!(type==SRM_IVLTYP_UNBOUNDED) && lower == upper)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidGeodeticRegion: lower and upper bounds are the same");

    if (component == 2 && !(type==SRM_IVLTYP_UNBOUNDED) &&
        lower<=-SRM_PI_DIV_2 && lower>=SRM_PI_DIV_2 &&
        upper<=-SRM_PI_DIV_2 && upper>=SRM_PI_DIV_2)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidGeodeticRegion: component 2 (latitude) out of range (-PI/2, PI/2)");

    status = Impl_setValidGeodeticRegion(this->getImpl(), component, type, lower, upper);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidGeodeticRegion: invalid input");
}


void BaseSRF_MapProjection::setExtendedValidGeodeticRegion
(
    const SRM_Integer component,
    const SRM_Interval_Type type,
    const SRM_Long_Float extended_lower,
    const SRM_Long_Float lower,
    const SRM_Long_Float upper,
    const SRM_Long_Float extended_upper
)
{
    Impl_Status status;

    if (component < 1 || component > 2)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setExtendedValidGeodeticRegion: component out of range [ 1, 2 ]");

    if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL )
        throw Exception(SRM_STATCOD_INVALID_INPUT,
                         "setExtendedValidGeodeticRegion: cannot be a semi-interval region");

    if (component == 1 && !(type==SRM_IVLTYP_UNBOUNDED) &&
         lower<=-SRM_PI && lower>SRM_PI &&
         upper<=-SRM_PI && upper>SRM_PI)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setExtendedValidGeodeticRegion: component 1 (longitude) out of range (-PI, PI]");

    if (component == 2 && !(type==SRM_IVLTYP_UNBOUNDED) &&
         lower<=-SRM_PI_DIV_2 && lower>=SRM_PI_DIV_2 &&
         upper<=-SRM_PI_DIV_2 && upper>=SRM_PI_DIV_2)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setExtendedValidGeodeticRegion: component 2 (latitude) out of range (-PI/2, PI/2)");

    if (!(type==SRM_IVLTYP_UNBOUNDED) && lower == upper)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setExtendedValidGeodeticRegion: lower and upper bounds are the same");

    if (!(type==SRM_IVLTYP_UNBOUNDED))
        if (lower < upper  && (extended_lower > lower || extended_upper < upper))
            throw Exception(SRM_STATCOD_INVALID_INPUT,
                             "setExtendedValidGeodeticRegion: extended bounds falls within valid region");
        else if (lower > upper && (extended_lower < lower || extended_upper > upper))
            throw Exception(SRM_STATCOD_INVALID_INPUT,
                            "setExtendedValidGeodeticRegion: extended bounds falls within valid region");

    status = Impl_setExtendedValidGeodeticRegion(this->getImpl(), component, type, extended_lower, lower, upper, extended_upper);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setExtendedValidGeodeticRegion: invalid input");
}


void BaseSRF_MapProjection::getValidGeodeticRegion
(
    const SRM_Integer        component,
          SRM_Interval_Type &type,
          SRM_Long_Float    &lower,
          SRM_Long_Float    &upper
)
{
    Impl_Status status;

    if (component < 1 || component > 2)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "getValidGeodeticRegion: component out of range [ 1, 2 ]");

    status = Impl_getValidGeodeticRegion(this->getImpl(), component, type, lower, upper);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INACTIONABLE, "getValidGeodeticRegion: error retriving valid region bounds");
}


void BaseSRF_MapProjection::getExtendedValidGeodeticRegion
(
    const SRM_Integer        component,
          SRM_Interval_Type &type,
          SRM_Long_Float    &extended_lower,
          SRM_Long_Float    &lower,
          SRM_Long_Float    &upper,
          SRM_Long_Float    &extended_upper
)
{
    Impl_Status status;

    if (component < 1 || component > 2)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "getExtendedValidGeodeticRegion: component out of range [ 1, 2 ]");

    status = Impl_getExtendedValidGeodeticRegion(this->getImpl(), component, type, extended_lower, lower,
                                                  upper, extended_upper);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INACTIONABLE, "getValidGeodeticRegion: error retriving extended valid region bounds");
}


// BaseSRF_MapProjection method bodies invoking internal implementation functions
SRM_Long_Float BaseSRF_MapProjection::calculateConvergenceOfTheMeridian(const CoordSurf &surf_coord)
{
    Impl_Status status;
    SRM_Long_Float ret_com;

    if (surf_coord.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "calculateConvergenceOfTheMeridian: Surface coordinate associated with a different SRF");

    // calculate distance
    status = Impl_calculateConvergenceOfTheMeridian(this->getImpl(), surf_coord.getValues(), &ret_com);

    if (status != IMPL_VALID)
        processStatus(status, "calculateConvergenceOfTheMeridian", COORD, MEM);

    // return distance if status is valid.
    return ret_com;
}


SRM_Long_Float BaseSRF_MapProjection::calculatePointDistortion(const CoordSurf &surf_coord)
{
    Impl_Status status;
    SRM_Long_Float ret_scale;

    if (surf_coord.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "calculatePointDistortion: Surface coordinate associated with a different SRF");

    // calculate distance
    status = Impl_calculatePointScale(this->getImpl(), surf_coord.getValues(), &ret_scale);

    if (status != IMPL_VALID)
        processStatus(status, "calculatePointDistortion", COORD, MEM);

    // return distance if status is valid.
    return ret_scale;
}


SRM_Long_Float BaseSRF_MapProjection::calculateMapAzimuth
(
    const CoordSurf &src_coord,
    const CoordSurf &des_coord
)
{
    Impl_Status status;
    SRM_Long_Float ret_distance;

    if (src_coord.getSRF() != this || des_coord.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "calculateMapAzimuth: surface coordinate associated with a different SRF");

    // calculate distance
    status = Impl_calculateMapAzimuth(this->getImpl(), src_coord.getValues(),
                                     des_coord.getValues(), &ret_distance);

    if (status != IMPL_VALID)
        processStatus(status, "calculateMapAzimuth", COORD, MEM);

    // return distance if status is valid.
    return ret_distance;
}
