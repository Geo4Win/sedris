/** @file BaseSRF_WithTangentPlaneSurface.cpp
@author David Shen
@brief BaseSRF_WithTangentPlaneSurface SRF body.
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

#include "srf_all.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"

using namespace srm;

void BaseSRF_WithTangentPlaneSurface::getSurfaceCoordinateValues
(
    const CoordSurf      &coord_surf,
          SRM_Long_Float &coord_surf_comp1,
          SRM_Long_Float &coord_surf_comp2
) const
{
    if (coord_surf.getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "getSurfaceCoordinateValues: Surface coordinate associated with a different SRF");

    coord_surf_comp1 = coord_surf.getValues()[0];
    coord_surf_comp2 = coord_surf.getValues()[1];
}


void BaseSRF_WithTangentPlaneSurface::freeSurfaceCoordinate(CoordSurf *coord_surf)
{
    if (coord_surf->getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "freeSurfaceCoordinate: Surface coordinate associated with a different SRF");

    delete(coord_surf);
}

void BaseSRF_WithTangentPlaneSurface::getAssociatedSurfaceCoordinate
(
    const Coord3D   &coord,
          CoordSurf &on_surface_coord
)
{
    SRM_Long_Float coord_surf_values[2];

    if (coord.getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "getAssociatedSurfaceCoordinate: Source coordinate associated with a different SRF");
    if (on_surface_coord.getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE, "getAssociatedSurfaceCoordinate: Target coordinate associated with a different SRF");

    // use only the first two component values from the 3d coordinate
    coord_surf_values[0] = coord.getValues()[0];
    coord_surf_values[1] = coord.getValues()[1];

    on_surface_coord.setValues(coord_surf_values);
}


void BaseSRF_WithTangentPlaneSurface::getPromotedSurfaceCoordinate
(
    const CoordSurf &surf_coord,
            Coord3D &three_d_coord
)
{
    SRM_Long_Float coord_3d_values[3];

    if (surf_coord.getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "getPromotedSurfaceCoordinate: Source coordinate associated with a different SRF");
    if (three_d_coord.getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE, "getPromotedSurfaceCoordinate: Target coordinate associated with a different SRF");

    // the component values from the 2d coordinate and set the their component to 0.0
    coord_3d_values[0] = surf_coord.getValues()[0];
    coord_3d_values[1] = surf_coord.getValues()[1];
    coord_3d_values[2] = 0.0;

    three_d_coord.setValues(coord_3d_values);
}


SRM_Long_Float BaseSRF_WithTangentPlaneSurface::calculateEuclideanDistance
(
    const CoordSurf &coord1,
    const CoordSurf &coord2
)
{
    Impl_Status status;
    SRM_Long_Float ret_distance;

    status = Impl_calculateEuclideanDistanceSurface(((BaseSRF_WithTangentPlaneSurface*)coord1.getSRF())->getImpl(), coord1.getValues(),
                                                     ((BaseSRF_WithTangentPlaneSurface*)coord2.getSRF())->getImpl(), coord2.getValues(), &ret_distance);

    if (status != IMPL_VALID)
        processStatus(status, "calculateEuclideanDistance", COORD, MEM);

    // return distance if status is valid.
    return ret_distance;
}
