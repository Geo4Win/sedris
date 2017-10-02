/*!
  @file   impl_mgrs.cpp
  @author David Shen, SAIC
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

#if defined (SC52) || defined (gnu)
using namespace std;
#endif

#include <math.h>

#include "impl_mgrs.h"
#include "BaseSRF.h"
#include "srf_all.h"
#include "mgrs.h"
#include "srm_types.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "edges.h"
#include "orm_rd_struct.h"

Impl_Status impl_get_MGRS
(
    void         *src_srf,
    srm::Coord3D *coord,
    SRM_Integer   precision,
    char         *mgrs
)
{
    Impl_Status      status=IMPL_INVALID;
    SRM_Long_Float   coord_cd[3];
    void            *my_srf_cd;
    SRM_ORM_Code     my_orm = coord->getSRF()->getOrm();
    SRM_RT_Code      my_rt = coord->getSRF()->getRt();
    Impl_RD_Struct  *rd_struct_ptr;
    Impl_ORM_Struct *orm_struct_ptr;
    SRM_Long_Float   A = IMPL_NAN;
    SRM_Long_Float   F = IMPL_NAN;
    char             ellipsoid_id[]= "WE";

    orm_struct_ptr = &Impl_ORM_array[ my_orm ];
    rd_struct_ptr  = &Impl_RD_array[orm_struct_ptr->rd_code];

    // the MGRS routines received from GEOTRANS only handles A > 0.0 and
    // F_inv > 250 and F_inv < 350
    if (rd_struct_ptr->a != IMPL_NAN  && rd_struct_ptr->a > 0.0 &&
        rd_struct_ptr->f_inverse != IMPL_NAN &&
        rd_struct_ptr->f_inverse >= 250.0 &&
        rd_struct_ptr->f_inverse <= 350.0)
    {
        A = rd_struct_ptr->a;
        F = 1.0 / rd_struct_ptr->f_inverse;

        // If a bad parameter is passed, Set_MGRS_Parameters() throws
        // an srm::Exception.
        Set_MGRS_Parameters(A, F, ellipsoid_id);
    }
    else
        return status;

    if (rd_struct_ptr->rd_code == SRM_RDCOD_BESSEL_1841_ETHIOPIA ||
        rd_struct_ptr->rd_code == SRM_RDCOD_BESSEL_1841_NAMIBIA ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1858 ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1858_MODIFIED ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1866 ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880 ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_CAPE ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_FIJI ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_IGN ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_PALESTINE ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_SYRIA)
    // "BR" is used to represent all the RD using the "AL" pattern for the
    // "if" clause in the GEOTRANS mgrs routine.
        strcpy(ellipsoid_id, "BR");

    if (coord->isA(srm::Coord::COORD_TYP_CD))
    {
        if (Convert_Geodetic_To_MGRS(((srm::Coord3D_Celestiodetic*)coord)->get_latitude(),
                                     ((srm::Coord3D_Celestiodetic*)coord)->get_longitude(),
                                     precision,
                                     mgrs)
           != MGRS_NO_ERROR)
            return status;
    }
    else // need to convert to celestiodetic
    {
        if (Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIODETIC,
                                     my_orm,
                                     my_rt,
                                     NULL,
                                     &my_srf_cd)
          != IMPL_VALID)
            return status;

        if (Impl_changeCoord3DSRF(src_srf,
                                  ((srm::Coord3D*)coord)->getValues(),
                                  my_srf_cd,
                                  coord_cd)
           != IMPL_VALID)
            return status;

        if (Convert_Geodetic_To_MGRS(coord_cd[1], //lat
                                     coord_cd[0], //lon
                                     precision,
                                     mgrs)
          != MGRS_NO_ERROR)
            return status;

        Impl_releaseSRF(&my_srf_cd);
    }
    return IMPL_VALID;
}


Impl_Status impl_set_coord
(
    void         *src_srf,
    char         *mgrs,
    srm::Coord3D *coord
)
{
    Impl_Status     status=IMPL_INVALID;
    SRM_Long_Float  coord_cd[3], orig_coord[3];
    void           *my_srf_cd;
    double           lat, lon;
    SRM_ORM_Code     my_orm = coord->getSRF()->getOrm();
    SRM_RT_Code      my_rt = coord->getSRF()->getRt();
    Impl_RD_Struct  *rd_struct_ptr;
    Impl_ORM_Struct *orm_struct_ptr;
    SRM_Long_Float   A = IMPL_NAN;
    SRM_Long_Float   F = IMPL_NAN;
    char             ellipsoid_id[]= "WE";

    orm_struct_ptr=&Impl_ORM_array[ my_orm ];

    rd_struct_ptr=&Impl_RD_array[orm_struct_ptr->rd_code];

    // the MGRS routines received from GEOTRANS only handles A > 0.0 and
    // F_inv > 250 and F_inv < 350
    if (rd_struct_ptr->a != IMPL_NAN  && rd_struct_ptr->a > 0.0 &&
        rd_struct_ptr->f_inverse != IMPL_NAN &&
        rd_struct_ptr->f_inverse >= 250.0 &&
        rd_struct_ptr->f_inverse <= 350.0)
    {
        A = rd_struct_ptr->a;
        F = 1.0 / rd_struct_ptr->f_inverse;

        // If a bad parameter is passed, Set_MGRS_Parameters() throws
        // an srm::Exception.
        Set_MGRS_Parameters(A, F, ellipsoid_id);
    }
    else
        return status;

    if (rd_struct_ptr->rd_code == SRM_RDCOD_BESSEL_1841_ETHIOPIA ||
        rd_struct_ptr->rd_code == SRM_RDCOD_BESSEL_1841_NAMIBIA ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1858 ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1858_MODIFIED ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1866 ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880 ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_CAPE ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_FIJI ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_IGN ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_PALESTINE ||
        rd_struct_ptr->rd_code == SRM_RDCOD_CLARKE_1880_SYRIA)
    // "BR" is used to represent all the RD using the "AL" pattern for the
    // "if" clause in the GEOTRANS mgrs routine.
        strcpy(ellipsoid_id, "BR");

    if (Convert_MGRS_To_Geodetic(mgrs, &lat, &lon) == MGRS_NO_ERROR)
    {
        if (coord->isA(srm::Coord::COORD_TYP_CD))
        {
            ((srm::Coord3D_Celestiodetic*)coord)->set_longitude(lon);
            ((srm::Coord3D_Celestiodetic*)coord)->set_latitude(lat);
            ((srm::Coord3D_Celestiodetic*)coord)->set_ellipsoidal_height(0.0);
            status = IMPL_VALID;
        }
        else if (Impl_createSRFFromParams(SRM_SRFTCOD_CELESTIODETIC,
                                         my_orm,
                                         my_rt,
                                         0,
                                         &my_srf_cd)
              ==IMPL_VALID)
        {
            // need to convert to celestiodetic
            coord_cd[0] = lon;
            coord_cd[1] = lat;
            coord_cd[2] = 0.0;

            if (Impl_changeCoord3DSRF(my_srf_cd,
                                      coord_cd,
                                      src_srf,
                                      orig_coord)
              ==IMPL_VALID)
            {
                ((srm::Coord3D*)coord)->setValues(orig_coord);
                status = IMPL_VALID;
            }
            Impl_releaseSRF(&my_srf_cd);
        }
    }
    return status;
}
