/** @file BaseSRF_3D.cpp
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
#include "Direction.h"
#include "Orientation.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"

using namespace srm;

void BaseSRF_3D::freeCoordinate3D(Coord3D *coord)
{
    if (coord->getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "freeCoordinate3D: Coordinate not associated with this SRF");

    delete(coord);
}


void BaseSRF_3D::getCoordinate3DValues
(
    const Coord3D        &coord,
          SRM_Long_Float &coord_comp1,
          SRM_Long_Float &coord_comp2,
          SRM_Long_Float &coord_comp3
) const
{
    if (coord.getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_COORDINATE, "getCoordinate3DValues: Coordinate not associated with this SRF");

    coord_comp1 = coord.getValues()[0];
    coord_comp2 = coord.getValues()[1];
    coord_comp3 = coord.getValues()[2];
}


SRM_Coordinate_Valid_Region BaseSRF_3D::changeCoordinate3DSRF
(
    const Coord3D &src_coord,
          Coord3D &des_coord
)
{
    Impl_Status status;
    SRM_Long_Float desCoord[3];
    SRM_Coordinate_Valid_Region ret_validity;

    if (des_coord.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE, "changeCoordinate3DSRF: Target coordinate associated with a different SRF");

    // change SRF
    status = Impl_changeCoord3DSRF(((BaseSRF_3D *)src_coord.getSRF())->getImpl(), src_coord.getValues(),
                                   ((BaseSRF_3D *)des_coord.getSRF())->getImpl(), desCoord);

    // set the coordinate values if status is "valid"
    if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
    {
        des_coord.setValues(desCoord);

        if (status == IMPL_VALID)
            ret_validity = SRM_COORDVALRGN_VALID;
        else if (status == IMPL_EXTENDED)
            ret_validity = SRM_COORDVALRGN_EXTENDED_VALID;
        else if (status == IMPL_DEFINED)
            ret_validity = SRM_COORDVALRGN_DEFINED;
    }
    else
        processStatus(status, "changeCoordinate3DSRF", COORD, MEM);

    return ret_validity;
}


void BaseSRF_3D::changeCoordinate3DArraySRF
(
    Coord3D                     **src_coord_array,
    SRM_Integer_Positive         *index,
    Coord3D                     **des_coord_array,
    SRM_Coordinate_Valid_Region  *region_array
)
{
    Impl_Status status;
    SRM_Long_Float desCoord[3];
    SRM_Coordinate_Valid_Region ret_validity;
    SRM_Integer_Positive i;

    if (index == NULL || *index == 0)
       throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRF: index = NULL or index = 0");

    if (src_coord_array == NULL)
       throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRF: null source coordinate array");

    if (des_coord_array == NULL)
       throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRF: null destination coordinate array");

    try
    {
        for (i=0; i<*index; i++)
        {
            if (src_coord_array[i] == NULL)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRF: null source coordinate array element");
            }

            if (des_coord_array[i] == NULL)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRF: null destination coordinate array element");
            }

            if (des_coord_array[i]->getSRF() != this)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE, "changeCoordinate3DArraySRF: Target coordinate associated with a different SRF");
            }

            // change SRF
            status = Impl_changeCoord3DSRF(((BaseSRF_3D *)src_coord_array[i]->getSRF())->getImpl(), src_coord_array[i]->getValues(),
                                           ((BaseSRF_3D *)des_coord_array[i]->getSRF())->getImpl(), desCoord);

            // set the coordinate values if status is "valid"
            if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
            {
                des_coord_array[i]->setValues(desCoord);

                if (status == IMPL_VALID)
                    ret_validity = SRM_COORDVALRGN_VALID;
                else if (status == IMPL_EXTENDED)
                    ret_validity = SRM_COORDVALRGN_EXTENDED_VALID;
                else if (status == IMPL_DEFINED)
                    ret_validity = SRM_COORDVALRGN_DEFINED;
            }
            else
            {
                *index = i;
                processStatus(status, "changeCoordinate3DArraySRF", COORD, MEM);
            }

            if (region_array != NULL)
                region_array[i] = ret_validity;
        }
    }
    catch (...)
    {
        *index = i;
        throw Exception(SRM_STATCOD_INACTIONABLE, "changeCoordinate3DArraySRF: Inactionable");
    }
}


SRM_Coordinate_Valid_Region BaseSRF_3D::changeCoordinate3DSRFObject
(
    const Coord3D                              &src_coord,
    const SRM_ORM_Transformation_3D_Parameters  hst,
          Coord3D                              &des_coord
)
{
    Impl_Status status;
    SRM_Long_Float desCoord[3];
    SRM_Coordinate_Valid_Region ret_validity;

    if (des_coord.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE, "changeCoordinate3DSRFObject: Target coordinate associated with a different SRF");

    if (hst.omega_1 >= SRM_2_PI || hst.omega_1 <= -SRM_2_PI ||
        hst.omega_2 >= SRM_2_PI || hst.omega_2 <= -SRM_2_PI ||
        hst.omega_3 >= SRM_2_PI || hst.omega_3 <= -SRM_2_PI ||
        hst.delta_s <= -1.0)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DSRFObject: HST values out-of-range");

    // change SRF
    status = Impl_changeCoord3DSRFObject(((BaseSRF_3D *)src_coord.getSRF())->getImpl(), src_coord.getValues(),
                                         ((BaseSRF_3D *)des_coord.getSRF())->getImpl(), desCoord,
                                          &hst);

    // set the coordinate values if status is "valid"
    if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
    {
        des_coord.setValues(desCoord);

        if (status == IMPL_VALID)
            ret_validity = SRM_COORDVALRGN_VALID;
        else if (status == IMPL_EXTENDED)
            ret_validity = SRM_COORDVALRGN_EXTENDED_VALID;
        else if (status == IMPL_DEFINED)
            ret_validity = SRM_COORDVALRGN_DEFINED;
    }
    else
        processStatus(status, "changeCoordinate3DSRF", COORD, MEM);

    return ret_validity;
}


void BaseSRF_3D::changeCoordinate3DArraySRFObject
(
          Coord3D                              **src_coord_array,
    const SRM_ORM_Transformation_3D_Parameters   hst,
          SRM_Integer_Positive                  *index,
          Coord3D                              **des_coord_array,
          SRM_Coordinate_Valid_Region           *region_array
)
{
    Impl_Status status;
    SRM_Long_Float desCoord[3];
    SRM_Coordinate_Valid_Region ret_validity;
    SRM_Integer_Positive i;

    if (index == NULL || *index == 0)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRFObject: index = NULL or index = 0");

    if (src_coord_array == NULL)
       throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRFObject: null source coordinate array");

    if (des_coord_array == NULL)
       throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRFObject: null destination coordinate array");

    if (hst.omega_1 >= SRM_2_PI || hst.omega_1 <= -SRM_2_PI ||
        hst.omega_2 >= SRM_2_PI || hst.omega_2 <= -SRM_2_PI ||
        hst.omega_3 >= SRM_2_PI || hst.omega_3 <= -SRM_2_PI ||
        hst.delta_s <= -1.0)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRFObject: HST values out-of-range");

    try
    {
        for (i=0; i<*index; i++)
        {
            if (src_coord_array[i] == NULL)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRFObject: null source coordinate array element");
            }

            if (des_coord_array[i] == NULL)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_INPUT, "changeCoordinate3DArraySRFObject: null destination coordinate array element");
            }

            if (des_coord_array[i]->getSRF() != this)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_TARGET_COORDINATE, "changeCoordinate3DArraySRFObject: Target coordinate associated with a different SRF");
            }

            // change SRF
            status = Impl_changeCoord3DSRFObject(((BaseSRF_3D *)src_coord_array[i]->getSRF())->getImpl(), src_coord_array[i]->getValues(),
                                                 ((BaseSRF_3D *)des_coord_array[i]->getSRF())->getImpl(), desCoord,
                                                 &hst);

            // set the coordinate values if status is "valid"
            if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
            {
                des_coord_array[i]->setValues(desCoord);

                if (status == IMPL_VALID)
                    ret_validity = SRM_COORDVALRGN_VALID;
                else if (status == IMPL_EXTENDED)
                    ret_validity = SRM_COORDVALRGN_EXTENDED_VALID;
                else if (status == IMPL_DEFINED)
                    ret_validity = SRM_COORDVALRGN_DEFINED;
            }
            else
            {
                *index = i;
                processStatus(status, "changeCoordinate3DArraySRFObject", COORD, MEM);
            }

            if (region_array != NULL)
                region_array[i] = ret_validity;
        }
    }
    catch (...)
    {
        *index = i;
        throw Exception(SRM_STATCOD_INACTIONABLE, "changeCoordinate3DArraySRFObject: Inactionable");
    }
}


void BaseSRF_3D::setValidRegion
(
    const SRM_Integer       component,
    const SRM_Interval_Type type,
    const SRM_Long_Float    lower,
    const SRM_Long_Float    upper
)
{
    Impl_Status status;
    SRM_SRFT_Code t_code;
    SRM_SRF_Code srf_code;
    SRM_SRFS_Code_Info srfs_code_info;
    bool is_angular = false;

    if (component < 1 || component > 3)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidRegion: component out of range [ 1, 3 ]");

    // get the SRFT type
    if (Impl_getCodes(getImpl(), &srf_code, &t_code, &srfs_code_info) != IMPL_VALID)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidRegion: Inactionable Error!!");

    switch (t_code)
    {
        // lon, lat, h
        case SRM_SRFTCOD_CELESTIODETIC:
        case SRM_SRFTCOD_PLANETODETIC:
             if (component == 1)
             {
                 if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <= SRM_IVLTYP_LE_SEMI_INTERVAL)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                     "setValidRegion: component 1 (longitude) cannot be a semi-interval region");
                 else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                 {
                     if (!(Impl_wellFormedLongitude(lower) && Impl_wellFormedLongitude(upper)))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 1 (longitude) out of range (-PI, PI]");
                     else if (lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 1 (longitude) lower and upper bounds are the same");
                 }
                 is_angular = true;
             }
             else if (component == 2)
             {
                 if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                     "setValidRegion: component 2 (latitude) cannot be a semi-interval region");
                 else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                 {
                     if (!(Impl_wellFormedLatitude(lower) && Impl_wellFormedLatitude(upper)))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setValidRegion: component 2 (latitude) out of range (-PI/2, PI/2)");
                     else if (lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setValidRegion: component 2 (latitude) lower and upper bounds are the same");
                 }
                 is_angular = true;
             }
             else //component == 3
             {
                 if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 3 (height) lower bound greater than upper bound");
//               else if (type <= SRM_IVLTYP_CLOSED_INTERVAL && (upper <= -B || lower <= -B))
//                   throw Exception(SRM_STATCOD_INVALID_INPUT,
//                                   "setValidRegion: component 3 (height) bounds lower than minor semi-axes length");
             }
             break;
        // azimuth, elevation, radius
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
             if (component == 1)
             {
                 if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 1 (longitude) cannot be a semi-interval region");
                 else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                 {
                     if (!(Impl_wellFormedAzimuth(lower) && Impl_wellFormedAzimuth(upper)))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 1 (longitude) out of range (-PI, PI]");
                     else if (lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setValidRegion: component 1 (longitude) lower and upper bounds are the same");
                 }
                 is_angular = true;
             }
             else if (component == 2)
             {
                 if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 2 (latitude) cannot be a semi-interval region");
                 else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                 {
                     if (!(Impl_wellFormedLatitude(lower) && Impl_wellFormedLatitude(upper)))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 2 (latitude) out of range (-PI/2, PI/2)");
                     else if (lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 2 (latitude) lower and upper bounds are the same");
                 }
                 is_angular = true;
             }
             else //component == 3
             {
                 if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                     "setValidRegion: component 3 (height) lower bound greater than upper bound");
                 else if (type <= SRM_IVLTYP_CLOSED_INTERVAL && (upper <= 0.0 || lower <= 0.0))
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                     "setValidRegion: component 3 (height) bounds lower than minor semi-axes length");
             }
             break;
        // cylindrical angle, radius, h
        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
             if (component == 1)
             {
                 if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 1 (longitude) cannot be a semi-interval region");
                 else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                 {
                     if (!(Impl_wellFormedLongitude(lower) && Impl_wellFormedLongitude(upper)))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setValidRegion: component 1 (longitude) out of range (-PI, PI]");
                     else if (lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setValidRegion: component 1 (longitude) lower and upper bounds are the same");
                 }
                 is_angular = true;
             }
             else if (component == 2)
             {
                 if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 2 (height) lower bound greater than upper bound");
                 else if (type <= SRM_IVLTYP_CLOSED_INTERVAL && (upper <= 0.0 || lower <= 0.0))
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 2 (height) bounds lower than minor semi-axes length");
             }
             // component 3 has no boundaries.
             break;
             // spherical: lon, lat, h
        case SRM_SRFTCOD_CELESTIOMAGNETIC:
        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
             if (component == 1)
             {
                 if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <= SRM_IVLTYP_LE_SEMI_INTERVAL)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                     "setValidRegion: component 1 (longitude) cannot be a semi-interval region");
                 else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                 {
                     if (!(Impl_wellFormedLongitude(lower) && Impl_wellFormedLongitude(upper)))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 1 (longitude) out of range (-PI, PI]");
                     else if (lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 1 (longitude) lower and upper bounds are the same");
                 }
                 is_angular = true;
             }
             else if (component == 2)
             {
                 if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <= SRM_IVLTYP_LE_SEMI_INTERVAL)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 2 (latitude) cannot be a semi-interval region");
                 else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                 {
                     if (!(Impl_wellFormedLatitude(lower) && Impl_wellFormedLatitude(upper)))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 2 (latitude) out of range (-PI/2, PI/2)");
                     else if (lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setValidRegion: component 2 (latitude) lower and upper bounds are the same");
                 }
                 is_angular = true;
             }
             else //component == 3
             {
                 if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 3 (height) lower bound greater than upper bound");
                 else if (type <= SRM_IVLTYP_CLOSED_INTERVAL && (upper <= 0.0 || lower <= 0.0))
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setValidRegion: component 3 (height) bounds lower than minor semi-axes length");
             }
             break;
        default:
             if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                 throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidRegion: interval lower bound greater than upper bound");
             break;
    }
    status = Impl_setValidRegion(this->getImpl(), component, type, lower, upper, is_angular);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidRegion: invalid input");
}


void BaseSRF_3D::setExtendedValidRegion
(
    const SRM_Integer       component,
    const SRM_Interval_Type type,
    const SRM_Long_Float    extended_lower,
    const SRM_Long_Float    lower,
    const SRM_Long_Float    upper,
    const SRM_Long_Float    extended_upper
)
{
    Impl_Status status;
    SRM_SRFT_Code t_code;
    SRM_SRF_Code srf_code;
    SRM_SRFS_Code_Info srfs_code_info;
    bool is_angular = false;

    if (component < 1 || component > 3)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setExtendedValidRegion: component out of range [ 1, 3 ]");

    // get the SRFT type
    if (Impl_getCodes(getImpl(), &srf_code, &t_code, &srfs_code_info) != IMPL_VALID)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setValidRegion: Inactionable Error!!");;

    switch (t_code)
    {
        // lon, lat, h
        case SRM_SRFTCOD_CELESTIODETIC:
        case SRM_SRFTCOD_PLANETODETIC:
             if (component == 1)
             {
                 if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <= SRM_IVLTYP_LE_SEMI_INTERVAL)
                     throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setExtendedValidRegion: component 1 (longitude) cannot be a semi-interval region");
                 else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                     if (!(Impl_wellFormedLongitude(lower) && Impl_wellFormedLongitude(upper) &&
                           Impl_wellFormedLongitude(extended_lower) && Impl_wellFormedLongitude(extended_upper)))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setExtendedValidRegion: component 1 (longitude) out of range (-PI, PI]");
                     else if (lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) lower and upper bounds are the same");
                     else if (lower < upper  && (extended_lower > lower || extended_upper < upper))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) extended bounds falls within valid region");
                     else if (lower > upper && (extended_lower < lower || extended_upper > upper))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) extended bounds falls within valid region");

                   is_angular = true;
               }
               else if (component == 2)
               {
                   if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 2 (latitude) a cannot be semi-interval region");
                   else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                       if (!(Impl_wellFormedLatitude(lower) && Impl_wellFormedLatitude(upper) &&
                             Impl_wellFormedLatitude(extended_lower) && Impl_wellFormedLatitude(extended_upper)))
                             throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 2 (latitude) out of range (-PI/2, PI/2)");
                       else if (lower == upper)
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                           "setExtendedValidRegion: component 2 (latitude) lower and upper bounds are the same");
                       else if (lower < upper && (extended_lower > lower || extended_upper < upper))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 2 (latitude) extended bounds falls within valid region");
                       else if (lower > upper && (extended_lower < lower || extended_upper > upper))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 2 (latitude) extended bounds falls within valid region");

                   is_angular = true;
               }
               else //component == 3
               {
                   if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                      "setExtendedValidRegion: component 3 (height) lower bound greater than upper bound");
//                   else if (type <= SRM_IVLTYP_CLOSED_INTERVAL && (upper <= -B || lower <= -B))
//                       throw Exception(SRM_STATCOD_INVALID_INPUT,
//                                        "setExtendedValidRegion: component 3 (height) bounds lower than minor semi-axes length");
//             else if (type < SRM_IVLTYP_CLOSED_INTERVAL &&
//                       (extended_lower <= -B || extended_lower > lower || extended_upper < upper))
//               throw Exception(SRM_STATCOD_INVALID_INPUT,
//                                "setExtendedValidRegion: component 3 (height) extended bounds falls within valid region");
               }
               break;
          // azimuth, elevation, radius
          case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
               if (component == 1)
               {
                   if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 1 (longitude) cannot be a semi-interval region");
                   else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                       if (!(Impl_wellFormedAzimuth(lower) && Impl_wellFormedAzimuth(upper) &&
                              Impl_wellFormedAzimuth(extended_lower) && Impl_wellFormedAzimuth(extended_upper)))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 1 (longitude) out of range (-PI, PI]");
                     else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL && lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) lower and upper bounds are the same");
                     else if (lower < upper  && (extended_lower > lower || extended_upper < upper))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) extended bounds falls within valid region");
                     else if (lower > upper && (extended_lower < lower || extended_upper > upper))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) extended bounds falls within valid region");

                   is_angular = true;
               }
               else if (component == 2)
               {
                   if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 2 (latitude) cannot be a semi-interval region");
                   else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                       if (!(Impl_wellFormedLatitude(lower) && Impl_wellFormedLatitude(upper) &&
                              Impl_wellFormedLatitude(extended_lower) && Impl_wellFormedLatitude(extended_upper)))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 2 (latitude) out of range (-PI/2, PI/2)");
                       else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL && lower == upper)
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 2 (latitude) lower and upper bounds are the same");
                       else if (lower < upper && (extended_lower > lower || extended_upper < upper))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 2 (latitude) extended bounds falls within valid region");
                       else if (lower > upper && (extended_lower < lower || extended_upper > upper))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 2 (latitude) extended bounds falls within valid region");

                   is_angular = true;
               }
               else //component == 3
               {
                   if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 3 (height) lower bound greater than upper bound");
                   else if (type <= SRM_IVLTYP_CLOSED_INTERVAL && (upper <= 0.0 || lower <= 0.0))
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 3 (height) bounds lower than minor semi-axes length");
                   else if (type < SRM_IVLTYP_CLOSED_INTERVAL &&
                             (extended_lower <= 0.0 || extended_lower > lower || extended_upper < upper))
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 3 (height) extended bounds falls within valid region");
               }
               break;
          // cylindrical angle, radius, h
          case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
               if (component == 1)
               {
                   if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 1 (longitude) cannot be a semi-interval region");
                   else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                       if (!(Impl_wellFormedCylindricalAngle(lower) && Impl_wellFormedCylindricalAngle(upper) &&
                              Impl_wellFormedCylindricalAngle(extended_lower) && Impl_wellFormedCylindricalAngle(extended_upper)))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                            "setExtendedValidRegion: component 1 (longitude) out of range (-PI, PI]");
                     else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL && lower == upper)
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) lower and upper bounds are the same");
                     else if (lower < upper  && (extended_lower > lower || extended_upper < upper))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) extended bounds falls within valid region");
                     else if (lower > upper && (extended_lower < lower || extended_upper > upper))
                         throw Exception(SRM_STATCOD_INVALID_INPUT,
                                          "setExtendedValidRegion: component 1 (longitude) extended bounds falls within valid region");

                   is_angular = true;
               }
               else if (component == 2)
               {
                   if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 2 (height) lower bound greater than upper bound");
                   else if (type <= SRM_IVLTYP_CLOSED_INTERVAL && (upper <= 0.0 || lower <= 0.0))
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 2 (height) bounds lower than minor semi-axes length");
                   else if (type < SRM_IVLTYP_CLOSED_INTERVAL &&
                             (extended_lower <= 0.0 || extended_lower > lower || extended_upper < upper))
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                        "setExtendedValidRegion: component 2 (height) extended bounds falls within valid region");
               }
               // component 3 has no boundaries.
               break;
          // spherical: lon, lat, h
          case SRM_SRFTCOD_CELESTIOMAGNETIC:
          case SRM_SRFTCOD_SOLAR_ECLIPTIC:
          case SRM_SRFTCOD_SOLAR_EQUATORIAL:
          case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
          case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
          case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
               if (component == 1)
               {
                   if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <= SRM_IVLTYP_LE_SEMI_INTERVAL)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                       "setExtendedValidRegion: component 1 (longitude) cannot be a semi-interval region");
                   else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                       if (!(Impl_wellFormedLongitude(lower) && Impl_wellFormedLongitude(upper) &&
                             Impl_wellFormedLongitude(extended_lower) && Impl_wellFormedLongitude(extended_upper)))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                         "setExtendedValidRegion: component 1 (longitude) out of range (-PI, PI]");
                   else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL && lower == upper)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                       "setExtendedValidRegion: component 1 (longitude) lower and upper bounds are the same");
                   else if (lower < upper  && (extended_lower > lower || extended_upper < upper))
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                       "setExtendedValidRegion: component 1 (longitude) extended bounds falls within valid region");
                   else if (lower > upper && (extended_lower < lower || extended_upper > upper))
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                       "setExtendedValidRegion: component 1 (longitude) extended bounds falls within valid region");
                   is_angular = true;
               }
               else if (component == 2)
               {
                   if (type >= SRM_IVLTYP_GT_SEMI_INTERVAL && type <=  SRM_IVLTYP_LE_SEMI_INTERVAL)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                       "setExtendedValidRegion: component 2 (latitude) cannot be a semi-interval region");
                   else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL)
                       if (!(Impl_wellFormedLatitude(lower) && Impl_wellFormedLatitude(upper) &&
                             Impl_wellFormedLatitude(extended_lower) && Impl_wellFormedLatitude(extended_upper)))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                           "setExtendedValidRegion: component 2 (latitude) out of range (-PI/2, PI/2)");
                       else if (type < SRM_IVLTYP_GT_SEMI_INTERVAL && lower == upper)
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                           "setExtendedValidRegion: component 2 (latitude) lower and upper bounds are the same");
                       else if (lower < upper && (extended_lower > lower || extended_upper < upper))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                           "setExtendedValidRegion: component 2 (latitude) extended bounds falls within valid region");
                       else if (lower > upper && (extended_lower < lower || extended_upper > upper))
                           throw Exception(SRM_STATCOD_INVALID_INPUT,
                                           "setExtendedValidRegion: component 2 (latitude) extended bounds falls within valid region");
                   is_angular = true;
               }
               else //component == 3
               {
                   if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                       "setExtendedValidRegion: component 3 (height) lower bound greater than upper bound");
                   else if (type <= SRM_IVLTYP_CLOSED_INTERVAL && (upper <= 0.0 || lower <= 0.0))
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                       "setExtendedValidRegion: component 3 (height) bounds lower than minor semi-axes length");
                   else if (type < SRM_IVLTYP_CLOSED_INTERVAL &&
                             (extended_lower <= 0.0 || extended_lower > lower || extended_upper < upper))
                       throw Exception(SRM_STATCOD_INVALID_INPUT,
                                       "setExtendedValidRegion: component 3 (height) extended bounds falls within valid region");
               }
               break;
          default:
               if (type <= SRM_IVLTYP_CLOSED_INTERVAL && upper <= lower)
                   throw Exception(SRM_STATCOD_INVALID_INPUT, "setExtendedValidRegion: interval lower bound greater than upper bound");
               break;
      }
      status = Impl_setExtendedValidRegion(this->getImpl(), component, type,
                                            extended_lower, lower, upper, extended_upper,
                                            is_angular);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "setExtendedValidRegion: invalid input");
}


void BaseSRF_3D::getValidRegion
(
    const SRM_Integer        component,
          SRM_Interval_Type &type,
          SRM_Long_Float    &lower,
          SRM_Long_Float    &upper
)
{
    Impl_Status status;

    if (component < 1 || component > 3)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "getValidRegion: component out of range [ 1, 3 ]");

    status = Impl_getValidRegion(this->getImpl(), component, type, lower, upper);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INACTIONABLE, "getValidRegion: error retriving valid region bounds");
}


void BaseSRF_3D::getExtendedValidRegion
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

    if (component < 1 || component > 3)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "getExtendedValidRegion: component out of range [ 1, 3 ]");

    status = Impl_getExtendedValidRegion(this->getImpl(), component, type, extended_lower, lower,
                                          upper, extended_upper);

    if (status != IMPL_VALID)
        throw Exception(SRM_STATCOD_INACTIONABLE, "getValidRegion: error retriving extended valid region bounds");
}


Direction *BaseSRF_3D::createDirection
(
    const Coord3D   &ref_coord,
    const SRM_Vector_3D vec
)
{
    SRM_Vector_3D dir;
    SRM_Vector_3D ref_loc;
    Direction* ret_dir;

    // Verify that the reference coordinate is associated with the same SRF
    if (ref_coord.getSRF() != this || vec == NULL)
       throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION, "createDirection: Invalid source direction");

    dir[0] = vec[0];
    dir[1] = vec[1];
    dir[2] = vec[2];

    for (int i=0; i<3; i++)
        ref_loc[i] = ref_coord.getValues()[i];

    try
    {
        ret_dir = new Direction(this, ref_loc, dir);
    }
    catch (Exception ex)
    {
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "createDirection: "\
                        "Unable to instantiate Direction object");
    }
    return ret_dir;
}


Direction *BaseSRF_3D::createDirection
(
    const Coord3D        &ref_coord,
    const SRM_Long_Float  vectorComp1,
    const SRM_Long_Float  vectorComp2,
    const SRM_Long_Float  vectorComp3
)
{
    SRM_Vector_3D dir;
    SRM_Vector_3D ref_loc;
    Direction* ret_dir;

    // Verify that the reference coordinate is associated with the same SRF
    if (ref_coord.getSRF() != this)
         throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION, "createDirection: Invalid source direction");

    dir[0] = vectorComp1;
    dir[1] = vectorComp2;
    dir[2] = vectorComp3;

    for (int i=0; i<3; i++)
        ref_loc[i] = ref_coord.getValues()[i];

    try
    {
        ret_dir = new Direction(this, ref_loc, dir);
    }
    catch (Exception ex)
    {
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "createDirection: "\
                        "Unable to instantiate Direction object");
    }
    return ret_dir;
}


Direction *BaseSRF_3D::createDirection()
{
    SRM_Vector_3D dir;
    SRM_Vector_3D ref_loc;
    Direction* ret_dir;

    dir[0] = 0.0;
    dir[1] = 0.0;
    dir[2] = 0.0;

    for (int i=0; i<3; i++)
        ref_loc[i] = 0.0;

    try
    {
        ret_dir = new Direction(this, ref_loc, dir);
    }
    catch (Exception ex)
    {
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "createDirection: "\
                        "Unable to instantiate Direction object");
    }
    return ret_dir;
}


void BaseSRF_3D::freeDirection(Direction *direction)
{
    if (direction != NULL)
    {
        if (direction->getSRF() != this)
            throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION, "freeDirection: Direction not associated with this SRF");

        delete direction;
    }
}

void BaseSRF_3D::getDirectionValues
(
    const Direction     &direction,
          Coord3D       &ref_coord,
          SRM_Vector_3D  vec
) const
{
    if (direction.getSRF() != (BaseSRF*)this ||
         ref_coord.getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION, "getDirectionValues: Direction associated with a different SRF");

    ref_coord.setValues(direction._ref_coord);

    vec[0] = direction._vec[0];
    vec[1] = direction._vec[1];
    vec[2] = direction._vec[2];
}


SRM_Coordinate_Valid_Region BaseSRF_3D::changeDirectionSRFObject
(
    const Direction                            &src_dir,
    const SRM_ORM_Transformation_3D_Parameters  hst,
          Direction                            &des_dir
)
{
    Impl_Status status;
    SRM_Long_Float ret_dir[3];
    SRM_Long_Float ret_ref_loc[3];
    SRM_Coordinate_Valid_Region ret_validity;

    if (des_dir.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_DIRECTION, "changeDirectionSRFObject: Target direction associated with a different SRF");

    if (hst.omega_1 >= SRM_2_PI || hst.omega_1 <= -SRM_2_PI ||
         hst.omega_2 >= SRM_2_PI || hst.omega_2 <= -SRM_2_PI ||
         hst.omega_3 >= SRM_2_PI || hst.omega_3 <= -SRM_2_PI ||
         hst.delta_s <= -1.0)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionSRFObject: HST values out-of-range");

    // change SRF
    status = Impl_changeDirectionSRFObject(((BaseSRF_3D *)src_dir.getSRF())->getImpl(), src_dir._ref_coord, src_dir._vec,
                                           ((BaseSRF_3D *)des_dir.getSRF())->getImpl(), ret_ref_loc, ret_dir,
                                            &hst);

    // set the direction values if the ref location is "valid"
    if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
    {
        for (int i=0; i<3; i++)
        {
            des_dir._ref_coord[i] = ret_ref_loc[i];
            des_dir._vec[i] = ret_dir[i];
        }

        if (status == IMPL_VALID)
            ret_validity =  SRM_COORDVALRGN_VALID;
        else if (status == IMPL_EXTENDED)
            ret_validity =  SRM_COORDVALRGN_EXTENDED_VALID;
        else if (status == IMPL_DEFINED)
            ret_validity =  SRM_COORDVALRGN_DEFINED;
    }
    else
        processStatus(status, "changeDirectionSRF", DIR, MEM);

    return ret_validity;
}

void BaseSRF_3D::changeDirectionArraySRFObject
(
          Direction                            **src_direction_array,
    const SRM_ORM_Transformation_3D_Parameters   hst,
          SRM_Integer_Positive                  *index,
          Direction                            **des_direction_array,
          SRM_Coordinate_Valid_Region           *region_array
)
{
    Impl_Status status;
    SRM_Long_Float ret_dir[3];
    SRM_Long_Float ret_ref_loc[3];
    SRM_Coordinate_Valid_Region ret_validity;
    SRM_Integer_Positive i;

    if (index == NULL || *index == 0)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRFObject: index = NULL or index = 0");

    if (src_direction_array == NULL)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRFObject: null source direction array");

    if (des_direction_array == NULL)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRFObject: null destination direction array");

    if (hst.omega_1 >= SRM_2_PI || hst.omega_1 <= -SRM_2_PI ||
        hst.omega_2 >= SRM_2_PI || hst.omega_2 <= -SRM_2_PI ||
        hst.omega_3 >= SRM_2_PI || hst.omega_3 <= -SRM_2_PI ||
        hst.delta_s <= -1.0)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRFObject: HST values out-of-range");

    try
    {
        for (i=0; i<*index; i++)
        {
            if (src_direction_array[i] == NULL)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRFObject: null source direction array element");
            }

            if (des_direction_array[i] == NULL)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRFObject: null destination direction array element");
            }

            if (des_direction_array[i]->getSRF() != this)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_TARGET_DIRECTION, "changeDirectionArraySRFObject: Target direction associated with a different SRF");
            }

            // change SRF
            status = Impl_changeDirectionSRFObject(((BaseSRF_3D *)src_direction_array[i]->getSRF())->getImpl(), src_direction_array[i]->_ref_coord, src_direction_array[i]->_vec,
                                                   ((BaseSRF_3D *)des_direction_array[i]->getSRF())->getImpl(), ret_ref_loc, ret_dir,
                                                   &hst);

            // set the coordinate values if status is "valid"
            if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
            {
                for (int i=0; i<3; i++)
                {
                    des_direction_array[i]->_ref_coord[i] = ret_ref_loc[i];
                    des_direction_array[i]->_vec[i] = ret_dir[i];
                }

                if (status == IMPL_VALID)
                    ret_validity = SRM_COORDVALRGN_VALID;
                else if (status == IMPL_EXTENDED)
                    ret_validity = SRM_COORDVALRGN_EXTENDED_VALID;
                else if (status == IMPL_DEFINED)
                    ret_validity = SRM_COORDVALRGN_DEFINED;
            }
            else
            {
                *index = i;
                processStatus(status, "changeDirectionArraySRFObject", DIR, MEM);
            }

            if (region_array != NULL)
                region_array[i] = ret_validity;
        }
    }
    catch (...)
    {
        *index = i;
        throw Exception(SRM_STATCOD_INACTIONABLE, "changeDirectionArraySRFObject: Inactionable");
    }
}


SRM_Coordinate_Valid_Region BaseSRF_3D::changeDirectionSRF
(
    const Direction &src_dir,
          Direction &des_dir
)
{
    Impl_Status status;
    SRM_Long_Float ret_dir[3];
    SRM_Long_Float ret_ref_loc[3];
    SRM_Coordinate_Valid_Region ret_validity;

    if (des_dir.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_DIRECTION, "changeDirectionSRF: Target direction associated with a different SRF");


    // change SRF
    status = Impl_changeDirectionSRF(((BaseSRF_3D *)src_dir.getSRF())->getImpl(), src_dir._ref_coord, src_dir._vec,
                                     ((BaseSRF_3D *)des_dir.getSRF())->getImpl(), ret_ref_loc, ret_dir);

    // set the direction values if the ref location is "valid"
    if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
    {
        for (int i=0; i<3; i++)
        {
            des_dir._ref_coord[i] = ret_ref_loc[i];
            des_dir._vec[i] = ret_dir[i];
        }

        if (status == IMPL_VALID)
            ret_validity =  SRM_COORDVALRGN_VALID;
        else if (status == IMPL_EXTENDED)
            ret_validity =  SRM_COORDVALRGN_EXTENDED_VALID;
        else if (status == IMPL_DEFINED)
            ret_validity =  SRM_COORDVALRGN_DEFINED;
    }
    else
        processStatus(status, "changeDirectionSRF", DIR, MEM);

    return ret_validity;
}


void BaseSRF_3D::changeDirectionArraySRF
(
    Direction                   **src_direction_array,
    SRM_Integer_Positive        *index,
    Direction                   **des_direction_array,
    SRM_Coordinate_Valid_Region *region_array
)
{
    Impl_Status status;
    SRM_Long_Float ret_dir[3];
    SRM_Long_Float ret_ref_loc[3];
    SRM_Coordinate_Valid_Region ret_validity;
    SRM_Integer_Positive i;

    if (index == NULL || *index == 0)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRF: index = NULL or index = 0");

    if (src_direction_array == NULL)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRF: null source direction array");

    if (des_direction_array == NULL)
        throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRF: null destination direction array");

    try
    {
        for (i=0; i<*index; i++)
        {
            if (src_direction_array[i] == NULL)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRF: null source direction array element");
            }

            if (des_direction_array[i] == NULL)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_INPUT, "changeDirectionArraySRF: null destination direction array element");
            }

            if (des_direction_array[i]->getSRF() != this)
            {
                *index = i;
                throw Exception(SRM_STATCOD_INVALID_TARGET_DIRECTION, "changeDirectionArraySRF: Target direction associated with a different SRF");
            }

            // change SRF
            status = Impl_changeDirectionSRF(((BaseSRF_3D *)src_direction_array[i]->getSRF())->getImpl(), src_direction_array[i]->_ref_coord, src_direction_array[i]->_vec,
                                             ((BaseSRF_3D *)des_direction_array[i]->getSRF())->getImpl(), ret_ref_loc, ret_dir);

            // set the coordinate values if status is "valid"
            if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
            {
                for (int i=0; i<3; i++)
                {
                    des_direction_array[i]->_ref_coord[i] = ret_ref_loc[i];
                    des_direction_array[i]->_vec[i] = ret_dir[i];
                }

                if (status == IMPL_VALID)
                    ret_validity = SRM_COORDVALRGN_VALID;
                else if (status == IMPL_EXTENDED)
                    ret_validity = SRM_COORDVALRGN_EXTENDED_VALID;
                else if (status == IMPL_DEFINED)
                    ret_validity = SRM_COORDVALRGN_DEFINED;
            }
            else
            {
                *index = i;
                processStatus(status, "changeDirectionArraySRF", DIR, MEM);
            }

            if (region_array != NULL)
                region_array[i] = ret_validity;
        }
    }
    catch (...)
    {
        *index = i;
        throw Exception(SRM_STATCOD_INACTIONABLE, "changeDirectionArraySRF: Inactionable");
    }
}


SRM_Coordinate_Valid_Region BaseSRF_3D::checkDirection
(
    const Direction &direction
)
{
    Impl_Status status;
    SRM_Coordinate_Valid_Region ret_code;

    if (direction.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION,
                "checkDirection: Direction associated with a different SRF");

    status = Impl_checkDirection(((BaseSRF_3D *)direction.getSRF())->getImpl(),
                                 direction._ref_coord, direction._vec);

    if (status == IMPL_VALID)
        ret_code = SRM_COORDVALRGN_VALID;
    else if (status == IMPL_EXTENDED)
        ret_code = SRM_COORDVALRGN_EXTENDED_VALID;
    else if (status == IMPL_DEFINED)
        ret_code = SRM_COORDVALRGN_DEFINED;
    else
        processStatus(status, "checkDirection", DIR, MEM);

    return ret_code;
}


Orientation *BaseSRF_3D::createOrientation
(
    const Coord3D &ref_coord,
    const SRM_Matrix_3x3 mat
)
{
    SRM_Matrix_3x3 ori;
    SRM_Vector_3D ref_loc;
    Orientation* ret_ori;

    // Verify that the reference coordinate is associated with the same SRF
    if (ref_coord.getSRF() != this)
         throw Exception(SRM_STATCOD_CREATION_FAILURE, "createOrientation: Invalid reference location");

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            ori[i][j] = mat[i][j];

    for (int k=0; k<3; k++)
        ref_loc[k] = ref_coord.getValues()[k];

    try
    {
        ret_ori = new Orientation(this, ref_loc, ori);
    }
    catch (Exception ex)
    {
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "createOrientation: Unable to instantiate Orientation object");
    }
    return ret_ori;
}


Orientation *BaseSRF_3D::createOrientation
(
    const Coord3D &ref_coord,
    const SRM_Vector_3D vec1,
    const SRM_Vector_3D vec2,
    const SRM_Vector_3D vec3
)
{
    SRM_Matrix_3x3 ori;
    SRM_Vector_3D ref_loc;
    Orientation* ret_ori;

    // Verify that the reference coordinate is associated with the same SRF
    if (ref_coord.getSRF() != this)
         throw Exception(SRM_STATCOD_INVALID_SOURCE_ORIENTATION, "createOrientation: Invalid source reference location");

    for (int j=0; j<3; j++)
    {
        ori[0][j] = vec1[j];
        ori[1][j] = vec2[j];
        ori[2][j] = vec3[j];
    }

    for (int k=0; k<3; k++)
        ref_loc[k] = ref_coord.getValues()[k];

    try
    {
        ret_ori = new Orientation(this, ref_loc, ori);
    }
    catch (Exception ex)
    {
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "createOrientation: Unable to instantiate Orientation object");
    }
    return ret_ori;
}


Orientation *BaseSRF_3D::createOrientation
(
     const Direction &dir1,
     const Direction &dir2,
     const Direction &dir3
)
{
    SRM_Matrix_3x3 ori;
    SRM_Vector_3D ref_loc;
    Orientation* ret_ori;

    // Verify that the reference coordinate is associated with the same SRF
    if (dir1._srf != dir2._srf || dir1._srf != dir3._srf ||
         !isEqualVec3(dir1._ref_coord, dir2._ref_coord) ||
         !isEqualVec3(dir1._ref_coord, dir3._ref_coord))
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "createOrientation: Invalid input direction objects");

    for (int j=0; j<3; j++)
    {
        ori[0][j] = dir1._vec[j];
        ori[1][j] = dir2._vec[j];
        ori[2][j] = dir3._vec[j];
    }

    for (int k=0; k<3; k++)
        ref_loc[k] = dir1._ref_coord[k];

    try
    {
        ret_ori = new Orientation(this, ref_loc, ori);
    }
    catch (Exception ex)
    {
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "createOrientation: Unable to instantiate Orientation object");
    }
    return ret_ori;
}


Orientation *BaseSRF_3D::createOrientation()
{
    SRM_Matrix_3x3 ori;
    SRM_Vector_3D ref_loc;
    Orientation* ret_ori;

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            ori[i][j] = 0.0;

    for (int k=0; k<3; k++)
        ref_loc[k] = 0.0;

    try
    {
        ret_ori = new Orientation(this, ref_loc, ori);
    }
    catch (Exception ex)
    {
        throw Exception(SRM_STATCOD_CREATION_FAILURE, "createOrientation: Unable to instantiate Orientation object");
    }
    return ret_ori;
}


void BaseSRF_3D::freeOrientation(Orientation *orientation)
{
    if (orientation != NULL)
    {
        if (orientation->getSRF() != this)
            throw Exception(SRM_STATCOD_INVALID_SOURCE_DIRECTION, "freeOrientation: Orientation not assoicated with this SRF");

        delete orientation;
    }
}

void BaseSRF_3D::getOrientationValues
(
    const Orientation    &orientation,
          Coord3D        &ref_coord,
          SRM_Matrix_3x3  mat
) const
{
    if (orientation.getSRF() != (BaseSRF*)this ||
        ref_coord.getSRF() != (BaseSRF*)this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_ORIENTATION, "getOrientationValues: Invalid source orientation");

    ref_coord.setValues(orientation._ref_coord);

    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            mat[i][j] = orientation._mat[i][j];
}


SRM_Coordinate_Valid_Region BaseSRF_3D::checkOrientation
(
    const Orientation &orientation
)
{
    Impl_Status status;
    SRM_Coordinate_Valid_Region ret_code;

    if (orientation.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_SOURCE_ORIENTATION, "checkOrientation: Orientation associated with a different SRF");

    status = Impl_checkOrientation(((BaseSRF_3D *)orientation.getSRF())->getImpl(), orientation._ref_coord, orientation._mat);

    if (status == IMPL_VALID)
        ret_code = SRM_COORDVALRGN_VALID;
    else if (status == IMPL_EXTENDED)
        ret_code = SRM_COORDVALRGN_EXTENDED_VALID;
    else if (status == IMPL_DEFINED)
        ret_code = SRM_COORDVALRGN_DEFINED;
    else
        processStatus(status, "checkOrientation", ORI, MEM);

    return ret_code;
}


SRM_Coordinate_Valid_Region BaseSRF_3D::changeOrientationSRF
(
    const Orientation &src_orient,
          Orientation &des_orient
)
{
    Impl_Status status;
    SRM_Matrix_3x3 ret_orient;
    SRM_Vector_3D ret_ref_loc;
    SRM_Coordinate_Valid_Region ret_validity;

    if (des_orient.getSRF() != this)
        throw Exception(SRM_STATCOD_INVALID_TARGET_ORIENTATION, "changeOrientationSRF: Target orientation associated with a different SRF");

    // change SRF
    status = Impl_changeOrientationSRF(((BaseSRF_3D *)src_orient.getSRF())->getImpl(), src_orient._ref_coord, src_orient._mat,
                                       ((BaseSRF_3D *)des_orient.getSRF())->getImpl(), ret_ref_loc, ret_orient);

    // set the orientation values if the ref location is "valid"
    if (status == IMPL_VALID || status == IMPL_EXTENDED || status == IMPL_DEFINED)
    {
        for (int i=0; i<3; i++)
        {
            des_orient._ref_coord[i] = ret_ref_loc[i];

            for (int j=0; j<3; j++)
                des_orient._mat[i][j] = ret_orient[i][j];
        }

        if (status == IMPL_VALID)
            ret_validity =  SRM_COORDVALRGN_VALID;
        else if (status == IMPL_EXTENDED)
            ret_validity =  SRM_COORDVALRGN_EXTENDED_VALID;
        else if (status == IMPL_DEFINED)
            ret_validity =  SRM_COORDVALRGN_DEFINED;
    }
    else
        processStatus(status, "changeOrientationSRF", ORI, MEM);

    return ret_validity;
}

void BaseSRF_3D::instanceAbstractSpaceCoordinate
(
    const Coord3D     &src_coord,
    const Orientation &orientation,
          Coord3D     &des_coord
)
{
    throw Exception(SRM_STATCOD_NOT_IMPLEMENTED, "instanceAbstractSpaceCoordinate: Not implemented in this version");
}


SRM_SRFS_Code_Info BaseSRF_3D::getNaturalSRFSetMemberCode
(
    const Coord3D       &src_coord,
          SRM_ORM_Code   orm_dst,
          SRM_RT_Code    rt_dst,
          SRM_SRFS_Code  tgt_srfs
)
{
    Impl_Status status = IMPL_VALID;
    SRM_SRFS_Code_Info retMemberCode;
    SRM_Vector_3D      tmpCoordVal;

    tmpCoordVal[0] = src_coord.getValues()[0];
    tmpCoordVal[1] = src_coord.getValues()[1];
    tmpCoordVal[2] = src_coord.getValues()[2];

    status = Impl_getNaturalSRFSetMemberCodeFor3DCoord(((BaseSRF_3D *)src_coord.getSRF())->getImpl(),
                                                        tmpCoordVal,
                                                        orm_dst,
                                                        rt_dst,
                                                        tgt_srfs,
                                                        &retMemberCode);

    processStatus(status, "getNaturalSRFSetMemberCode", COORD, MEM);

    return retMemberCode;
}



BaseSRF_3D* BaseSRF_3D::getNaturalSRFSetMember
(
    Coord3D       &src_coord,
    SRM_ORM_Code   orm_dst,
    SRM_RT_Code    rt_dst,
    SRM_SRFS_Code  tgt_srfs
)
{
    Impl_Status  status = IMPL_VALID;
    void        *impl_ptr;
    BaseSRF_3D  *retSrf;

    SRM_Long_Float tmpCoordVal[3];

    tmpCoordVal[0] = src_coord.getValues()[0];
    tmpCoordVal[1] = src_coord.getValues()[1];
    tmpCoordVal[2] = src_coord.getValues()[2];

    status = Impl_getNaturalSRFSetMemberFor3DCoord(((BaseSRF_3D *)src_coord.getSRF())->getImpl(),
                                                    tmpCoordVal,
                                                    orm_dst,
                                                    rt_dst,
                                                    tgt_srfs,
                                                    (void**)&impl_ptr);

    switch (tgt_srfs)
    {
        case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM: //LTE
             retSrf = new SRF_LocalTangentSpaceEuclidean(impl_ptr);
             break;
        case SRM_SRFSCOD_LAMBERT_NTF: //LCC
        case SRM_SRFSCOD_WISCONSIN_SPCS: //LCC
             retSrf = new SRF_LambertConformalConic(impl_ptr);
             break;
        case SRM_SRFSCOD_ALABAMA_SPCS: //TM
        case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR: //TM
             retSrf = new SRF_TransverseMercator(impl_ptr);
             break;
        case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC: //PS
             retSrf = new SRF_PolarStereographic(impl_ptr);
             break;
        default:
             // this should never be reached
             throw Exception(SRM_STATCOD_INACTIONABLE, "getNaturalSRFSetMember: Inactionable failure");
    }
    processStatus(status, "getNaturalSRFSetMember", COORD, MEM);

    return retSrf;
}


SRM_Long_Float BaseSRF_3D::calculateEuclideanDistance
(
    const Coord3D &coord1,
    const Coord3D &coord2
)
{
    Impl_Status status;
    SRM_Long_Float ret_distance;

    status = Impl_calculateEuclideanDistance(((BaseSRF_3D *)coord1.getSRF())->getImpl(), coord1.getValues(),
                                             ((BaseSRF_3D *)coord2.getSRF())->getImpl(), coord2.getValues(), &ret_distance);

    if (status != IMPL_VALID)
        processStatus(status, "calculateEuclideanDistance", COORD, MEM);

    // return distance if status is valid.
    return ret_distance;
}
