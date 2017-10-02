/** @file Coord.cpp
@author David Shen
@brief Coord body.
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

#include "Coord.h"
#include "Exception.h"
#include "impl_mgrs.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace srm;

const char* Coord2D::toString()
{
    static char ret_string[50];
    sprintf(ret_string,"[ %lf, %lf ]\n", _values[0],  _values[1]);
    return ret_string;
}

const char* CoordSurf::toString()
{
    static char ret_string[50];
    sprintf( ret_string,"[ %lf, %lf ]\n", _values[0], _values[1] );
    return ret_string;
}

const char* Coord3D::toString()
{
    static char ret_string[75];
    sprintf(ret_string, "[ %lf, %lf, %lf ]\n",
            _values[0],  _values[1],  _values[2]);
    return ret_string;
}

const char* Coord3D::getMGRS(SRM_Integer precision)
{
    static char mgrs[20];
    Impl_Status status;

    status = impl_get_MGRS(this->getSRF()->_impl,
                           this,
                           precision,
                           mgrs);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INVALID_INPUT,
                        "getMGRS: Invalid input for MGRS conversion from coordinate");

    return mgrs;
}

void Coord3D::setCoord(const char* mgrs)
{
    Impl_Status status;
    static char my_mgrs[16];

    strcpy(my_mgrs, mgrs);

    status = impl_set_coord(this->getSRF()->_impl,
                             my_mgrs,
                             this);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INVALID_INPUT,
                        "setCoord: Invalid input for MGRS conversion to coordinate");
}
