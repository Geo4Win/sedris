/*
 * FILE       : sample_srm_access.cpp
 *
 * PROGRAMMERS: Andrew Diemer, Michele Worley, William Ferrell
 *
 * DESCRIPTION:
 *     This program create CC, CD and UTM SRFs and Coordinates and then
 *     converts sequentially between them.
 *
 * Options: none
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 */

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

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */

#if defined(SC52) || defined(_WIN32) || defined(linux) || defined(gnu)
#include <iostream>
using namespace std;
#else
#include <iostream.h>
#endif

#include <stdio.h>
#include "srf_all.h"

#ifndef PI
#define PI 3.14159265358979323846
#endif

#define TO_DEGREES(__rad)   (__rad*(180/PI))

const char *const SrmVersionString = "4.1.x";
const char *const ToolName = "sample_srm_access";
const char *const ToolVersionString = "4.1.4.0";
const char *const BaseToolString = "%s v%s\n    (compatible with SRM SDK %s)\n\n";

using namespace srm;

int main(int argc, char* argv[])
{
    // SRF containers, parameters, and coordinates
    SRF_TransverseMercator *utm12_srf    = NULL;
    SRF_Celestiodetic      *cd_srf        = NULL;
    SRF_Celestiocentric    *cc_srf        = NULL;
    SRM_SRFS_Info           utm12_srfs_params;

    SRM_Long_Float          src_ord1 = 500000.0,
                            src_ord2 = 0.0,
                            src_ord3 = 1000.0;
    SRM_SRFS_Code           utm_srf_code = SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR;
    SRM_SRF_Code            cd_srf_code = SRM_SRFCOD_GEODETIC_WGS_1984,
                            cc_srf_code = SRM_SRFCOD_GEOCENTRIC_WGS_1984;
    SRM_ORM_Code            orm = SRM_ORMCOD_WGS_1984;
    SRM_RT_Code             rt = SRM_RTCOD_WGS_1984_IDENTITY;

    printf(BaseToolString, ToolName, ToolVersionString, SrmVersionString);

    try
    {
        // Initialize SRFs and coordinates
        utm12_srfs_params.srfs_code_info.srfs_code = utm_srf_code;
        utm12_srfs_params.srfs_code_info.value.srfsm_utm =
            SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE;
        utm12_srfs_params.orm_code = orm;

        utm12_srf = (SRF_TransverseMercator*)
                    BaseSRF::createSRFSetMember(utm12_srfs_params, rt);
        cd_srf = (SRF_Celestiodetic *)
                 BaseSRF::createStandardSRF(cd_srf_code, rt);
        cc_srf = (SRF_Celestiocentric *)
                 BaseSRF::createStandardSRF(cc_srf_code, rt);

        Coord3D_TransverseMercator     utm_coord(utm12_srf,
                                                 src_ord1, src_ord2, src_ord3);
        Coord3D_Celestiodetic          cd_coord(cd_srf);
        Coord3D_Celestiocentric        cc_coord(cc_srf);

        // Perform conversions and print results
        cd_srf->changeCoordinate3DSRF(utm_coord, cd_coord);
        cc_srf->changeCoordinate3DSRF(cd_coord, cc_coord);

        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(6);
        cout << "UTM (Zone N12) "
             << "[ " << utm_coord.get_easting() << ", " << utm_coord.get_northing()
             << ", " << utm_coord.get_ellipsoidal_height() << " ]" << endl;
        cout << "  => CD "
             << "[ " << TO_DEGREES(cd_coord.get_longitude())
             << ", " << TO_DEGREES(cd_coord.get_latitude())
             << ", " << cd_coord.get_ellipsoidal_height()
             << " ]" << endl << endl;

        cout << "CD "
             << "[ " << TO_DEGREES(cd_coord.get_longitude())
             << ", " << TO_DEGREES(cd_coord.get_latitude())
             << ", " << cd_coord.get_ellipsoidal_height()
             << " ]" << endl;
        cout << "  => CC "
             << "[ " << cc_coord.get_u() << ", " << cc_coord.get_v()
             << ", " << cc_coord.get_w() << " ]" << endl << endl;

    }
    catch (srm::Exception(ex))
    {
        cout << "Caught exception: " << ex.getWhat() << endl;
    }
    return 0;
}
