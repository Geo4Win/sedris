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


/** @file BaseSRF_3D.cpp
@author David Shen
@brief BaseSRF_3D SRF body.
*/

#include "srf_all.h"
#include "Direction.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"
#include <math.h>
#include <float.h>

using namespace srm;

Direction::Direction
(
          BaseSRF       *srf,
    const SRM_Vector_3D  ref_coord,
    const SRM_Vector_3D  vec
)
{
    if ( srf==NULL || ref_coord==NULL || vec==NULL )
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "Null input parameter(s)" );

    _srf = srf->clone();

    for (int i=0; i<3; i++)
    {
        _ref_coord[i] = ref_coord[i];
        _vec[i] = vec[i];
    }
}

void Direction::getRefCoord( Coord3D &coord ) const
{
    if ( coord.getSRF() != _srf )
        throw Exception( SRM_STATCOD_INVALID_SOURCE_DIRECTION,
                         "Direction::getRefCoord: Coord3D associated with a different SRF");

    coord.setValues( _ref_coord );
}

const SRM_Long_Float *Direction::getRefCoord() const
{
    return _ref_coord;
}


void Direction::getDir( SRM_Vector_3D vec ) const
{
    vec[0] = _vec[0];
    vec[1] = _vec[1];
    vec[2] = _vec[2];
}

SRM_Long_Float Direction::getVectorComp1() const
{
    return _vec[0];
}

SRM_Long_Float Direction::getVectorComp2() const
{
    return _vec[1];
}

SRM_Long_Float Direction::getVectorComp3() const
{
    return _vec[2];
}

SRM_Long_Float Direction::getVectorComp( SRM_Integer index ) const
{
    if ( index < 1 || index > 3 )
        throw Exception( SRM_STATCOD_INVALID_INPUT,
                         "Direction::getVectorComp: Vector index out of bound");

    return _vec[index-1];
}

void Direction::setVectorComp
(
    const SRM_Long_Float comp1,
    const SRM_Long_Float comp2,
    const SRM_Long_Float comp3
)
{
    _vec[0] = comp1;
    _vec[1] = comp2;
    _vec[2] = comp3;
}

void Direction::setVectorComp
(
    const SRM_Integer    index,
    const SRM_Long_Float comp
)
{
    if ( index < 1 || index > 3 )
        throw Exception( SRM_STATCOD_INVALID_INPUT,
                         "Direction::getVectorComp: Vector index out of bound");

    _vec[index-1] = comp;
}

void Direction::setVector( const SRM_Vector_3D vec )
{
    _vec[0] = vec[0];
    _vec[1] = vec[1];
    _vec[2] = vec[2];
}


bool Direction::isEqual( const Direction &dir ) const
{
    return (_srf == dir._srf &&
            srm::isEqualVec3( _vec, dir._vec ) &&
            srm::isEqualVec3( _ref_coord, dir._ref_coord ));
}


Direction* Direction::makeCopy() const
{
    return new Direction( _srf, _ref_coord, _vec );
}
