/** @file Orientation.cpp
@author David Shen
@brief BaseSRF_3D SRF body.
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
#include "Orientation.h"
#include "Direction.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"

using namespace srm;


Orientation::Orientation
(
          BaseSRF        *srf,
    const SRM_Vector_3D   ref_coord,
    const SRM_Matrix_3x3  mat
)
{
    if (srf==NULL || ref_coord==NULL || mat==NULL)
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "Null input parameter(s)");

    _srf = srf->clone();

    for (int i=0; i<3; i++)
    {
        _ref_coord[i] = ref_coord[i];

        for (int j=0; j<3; j++)
            _mat[i][j] = mat[i][j];
    }
}

Orientation::~Orientation()
{
    _srf->release();
}

void Orientation::getRefCoord(Coord3D &coord) const
{
    if (coord.getSRF() != _srf)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION,
                        "Orientation::getRefCoord: Coord3D associated with a different SRF");

    coord.setValues(_ref_coord);
}

void Orientation::getMatrix(SRM_Matrix_3x3 mat) const
{
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            mat[i][j] = _mat[i][j];
}

void Orientation::getDirectionComp1(Direction &dir) const
{
    if (dir.getSRF() != _srf || !isEqualVec3(dir.getRefCoord(), _ref_coord))
        throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION,
                        "Orientation::getDirectionComp1: Direction using a different reference coordinate");

    dir.setVectorComp(_mat[0][0], _mat[0][1], _mat[0][2]);
}

void Orientation::getDirectionComp2(Direction &dir) const
{
    if (dir.getSRF() != _srf || !isEqualVec3(dir.getRefCoord(), _ref_coord))
        throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION,
                       "Orientation::getDirectionComp2: Direction using a different reference coordinate");

    dir.setVectorComp(_mat[1][0], _mat[1][1], _mat[1][2]);
}

void Orientation::getDirectionComp3(Direction &dir) const
{
    if (dir.getSRF() != _srf || !isEqualVec3(dir.getRefCoord(), _ref_coord))
        throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION,
                        "Orientation::getDirectionComp3: Direction using a different reference coordinate");

    dir.setVectorComp(_mat[2][0], _mat[2][1], _mat[2][2]);
}

void Orientation::getDirectionComp(SRM_Integer index, Direction &dir) const
{
    if (dir.getSRF() != _srf || !isEqualVec3(dir.getRefCoord(), _ref_coord))
        throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION,
                        "Orientation::getDirectionComp: Direction using a different reference coordinate");

    if (index < 1 || index > 3)
        throw Exception(SRM_STATCOD_INVALID_INPUT,
                        "Direction::getDirectionComp: Vector index out of bound");

    dir.setVectorComp(_mat[index-1][0], _mat[index-1][1], _mat[index-1][2]);
}

void Orientation::setDirectionComp
(
    const Direction &dir1,
    const Direction &dir2,
    const Direction &dir3
)
{
    if (dir1.getSRF() != _srf || dir2.getSRF() != _srf || dir3.getSRF() != _srf ||
         !isEqualVec3(dir1.getRefCoord(), _ref_coord) ||
         !isEqualVec3(dir2.getRefCoord(), _ref_coord) ||
         !isEqualVec3(dir3.getRefCoord(), _ref_coord))
       throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION, "setDirectionComp: Invalid input direction objects");

    for (int j=0; j<3; j++)
    {
        _mat[0][j] = dir1.getVectorComp(j+1);
        _mat[1][j] = dir2.getVectorComp(j+1);
        _mat[2][j] = dir3.getVectorComp(j+1);
    }
}

void Orientation::setDirectionComp
(
    const SRM_Integer  index,
    const Direction   &dir
)
{
    if (dir.getSRF() != _srf || !isEqualVec3(dir.getRefCoord(), _ref_coord))
        throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION,
                        "Orientation::setDirectionComp: Direction using a different reference coordinate");

    if (index < 1 || index > 3)
        throw Exception(SRM_STATCOD_INVALID_INPUT,
                        "Direction::setDirectionComp: Vector index out of bound");

    for (int j=0; j<3; j++)
    {
        _mat[index-1][j] = dir.getVectorComp(j+1);
    }
}

void Orientation::setMatrix(const SRM_Matrix_3x3 mat)
{
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            _mat[i][j] = mat[i][j];
}

bool Orientation::isEqual(const Orientation &ori) const
{
    return (_srf == ori._srf &&
            srm::isEqualMat(_mat, ori._mat) &&
            srm::isEqualVec3(_ref_coord, ori._ref_coord));
}

bool Orientation::operator==(const Orientation &rhs) const
{
    return (_srf == rhs._srf &&
            srm::isEqualMat(_mat, rhs._mat) &&
            srm::isEqualVec3(_ref_coord, rhs._ref_coord));
}

Orientation* Orientation::makeCopy() const
{
    return new Orientation(_srf, _ref_coord, _mat);
}
