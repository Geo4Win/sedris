/*
 * FILE       : c_sample_srm_access.c
 *
 * PROGRAMMERS: Andrew Diemer, Michele Worley, William Ferrell
 *
 * DESCRIPTION:
 *     This program create CC, CD and UTM SRFs and Coordinates and then
 *     converts sequentially between them.
 *
 * Usage:
 *
 *
 * Options: none
 *
 * Examples:
 *
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

#include <stdio.h>
#include <string.h>

#include "srm.h"

#ifndef PI
#define PI 3.14159265358979323846
#endif

#define TO_DEGREES(__rad)   (__rad*(180/PI))

const char *const SrmVersionString = "4.1.x";
const char *const ToolName = "c_sample_srm_access";
const char *const ToolVersionString = "4.1.4.0";
const char *const BaseToolString = "%s v%s\n    (compatible with SRM SDK %s)\n\n\n";

/*
 * FUNCTION: main
 */
int main
(
    int   argc,
    char *argv[]
)
{
    SRM_TransverseMercator          *utm12_srf;
    SRM_Celestiocentric             cc_srf;
    SRM_Celestiodetic               cd_srf;
    SRM_Coordinate3D                utm_coord, cc_coord, cd_coord;
    SRM_Long_Float                  easting = 500000.0,
                                    northing = 0.0,
                                    ellipsoidal_height = 1000.0,
                                    tgt_ord1, tgt_ord2, tgt_ord3,
                                    src_ord1, src_ord2, src_ord3;
    SRM_ORM_Code                    orm_code = SRM_ORMCOD_WGS_1984;
    SRM_RT_Code                     rt_code  = SRM_RTCOD_WGS_1984_IDENTITY;
    SRM_SRFS_Code_Info              srfs_code_info;
    SRM_Coordinate_Valid_Region     val_region;

    printf(BaseToolString, ToolName, ToolVersionString,
           SrmVersionString);

    if (SRM_CD_Create(orm_code, rt_code, &cd_srf) != SRM_STATCOD_SUCCESS)
    {
        fprintf(stderr, "Failed to create CD SRF\n");
        return 1;
    }
    else if (cd_srf.methods->CreateCoordinate3D(&cd_srf,
            0.0, 0.0, 0.0, &cd_coord) != SRM_STATCOD_SUCCESS)
    {
        fprintf(stderr, "Failed to create CD coordinate\n");
        cd_srf.methods->Destroy(&cd_srf);
        return 1;
    }
    srfs_code_info.srfs_code = SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR;
    srfs_code_info.value.srfsm_utm =
        SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE;

    if (SRM_CreateSRFSetMember(srfs_code_info, orm_code, rt_code,
          (SRM_Object_Reference *)&utm12_srf) == SRM_STATCOD_SUCCESS)
    {
        if (utm12_srf->methods->CreateCoordinate3D(utm12_srf,
            easting, northing, ellipsoidal_height, &utm_coord)
            == SRM_STATCOD_SUCCESS)
        {
            if (utm12_srf->methods->ChangeCoordinate3DSRF(&cd_srf,
                utm12_srf, &utm_coord, &cd_coord, &val_region)
                != SRM_STATCOD_SUCCESS)
            {
                fprintf(stderr, "Failed to convert to UTM coordinate\n");
            }
            else if (cd_srf.methods->GetCoordinate3DValues(&cd_srf,
                     &cd_coord, &tgt_ord1, &tgt_ord2, &tgt_ord3)
                     != SRM_STATCOD_SUCCESS)
            {
                fprintf(stderr, "Failed getting CD coordinate values\n");
            }
            else
            {
                printf("UTM (Zone N12) [ %lf, %lf, %lf ]\n"\
                       "  => CD [ %lf, %lf, %lf ]\n\n",
                       easting, northing, ellipsoidal_height,
                       TO_DEGREES(tgt_ord1), TO_DEGREES(tgt_ord2),
                       tgt_ord3);

            }
            utm12_srf->methods->DestroyCoordinate3D(utm12_srf, &utm_coord);
        }
        else
        {
            fprintf(stderr, "Failed to create UTM coordinate\n");
        }
        utm12_srf->methods->Destroy(utm12_srf);
    }
    else
    {
        fprintf(stderr, "Failed to create UTM SRF\n");
    }

   /*
    * Copy values from previous conversion for printing later
    */
    src_ord1 = tgt_ord1;
    src_ord2 = tgt_ord2;
    src_ord3 = tgt_ord3;

    if (SRM_CC_Create(orm_code, rt_code, &cc_srf) == SRM_STATCOD_SUCCESS)
    {
        if (cc_srf.methods->CreateCoordinate3D(&cc_srf,
            0.0, 0.0, 0.0, &cc_coord) != SRM_STATCOD_SUCCESS)
        {
            fprintf(stderr, "Failed to create CC coordinate");
        }
        else
        {
            if (cc_srf.methods->ChangeCoordinate3DSRF(&cc_srf, &cd_srf,
                &cd_coord, &cc_coord, &val_region) != SRM_STATCOD_SUCCESS)
            {
                fprintf(stderr, "Failed to convert to CC coordinate\n");
            }
            else if (cc_srf.methods->GetCoordinate3DValues(&cc_srf,
                     &cc_coord, &tgt_ord1, &tgt_ord2, &tgt_ord3)
                     != SRM_STATCOD_SUCCESS)
            {
                fprintf(stderr,
                        "Failed getting the CC coordinate values\n");
            }
            else
            {
                printf("CD [ %lf, %lf, %lf ]\n", TO_DEGREES(src_ord1),
                    TO_DEGREES(src_ord2), src_ord3);
                printf("  => CC [ %lf, %lf, %lf ]\n\n",
                    tgt_ord1, tgt_ord2, tgt_ord3);
            }
            cc_srf.methods->DestroyCoordinate3D(&cc_srf,
                &cc_coord);
        }
        cc_srf.methods->Destroy(&cc_srf);
    }
    else
    {
        fprintf(stderr, "Failed to create CC SRF\n");
    }
    cd_srf.methods->DestroyCoordinate3D(&cd_srf, &cd_coord);
    cd_srf.methods->Destroy(&cd_srf);

    return 0;
}
