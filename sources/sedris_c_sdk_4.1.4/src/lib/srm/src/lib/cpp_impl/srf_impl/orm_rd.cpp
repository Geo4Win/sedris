/*
 * FILE       : orm_rd.cpp
 *
 * PROGRAMMERS: Automatically generated from SRM database
 *
 * DESCRIPTION:
 *     Internal ORM/RD structures for SRM
 *
 *      *** IMPORTANT NOTE ***
 *      This file is generated automatically from the SRM database tables using
 *      the SRM Code Generator.  DO NOT MODIFY THIS FILE BY HAND.  Changes should
 *      be made in the SRM database and SRM Code generator templates, and will be
 *      reflected in this file when the system is rebuilt.
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
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

#include "orm_rd_struct.h"
#include "srm_internal.h"

#define NGA_SPHERE_RADIUS 20000000/SRM_PI

Impl_RD_Struct Impl_RD_array[] =
{
    /* Empty Impl_RD_struct for direct indexing via RD codes */
    {
      ((SRM_RD_Code)0), /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "empty RD" /* RD Category */
    },

    /* Impl_RD_struct for RD ORIGIN_2D */
    {
      SRM_RDCOD_ORIGIN_2D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "POINT" /* RD Category */
    },

    /* Impl_RD_struct for RD X_UNIT_POINT_2D */
    {
      SRM_RDCOD_X_UNIT_POINT_2D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "POINT" /* RD Category */
    },

    /* Impl_RD_struct for RD Y_UNIT_POINT_2D */
    {
      SRM_RDCOD_Y_UNIT_POINT_2D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "POINT" /* RD Category */
    },

    /* Impl_RD_struct for RD ORIGIN_3D */
    {
      SRM_RDCOD_ORIGIN_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "POINT" /* RD Category */
    },

    /* Impl_RD_struct for RD X_UNIT_POINT_3D */
    {
      SRM_RDCOD_X_UNIT_POINT_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "POINT" /* RD Category */
    },

    /* Impl_RD_struct for RD Y_UNIT_POINT_3D */
    {
      SRM_RDCOD_Y_UNIT_POINT_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "POINT" /* RD Category */
    },

    /* Impl_RD_struct for RD Z_UNIT_POINT_3D */
    {
      SRM_RDCOD_Z_UNIT_POINT_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "POINT" /* RD Category */
    },

    /* Impl_RD_struct for RD X_AXIS_2D */
    {
      SRM_RDCOD_X_AXIS_2D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "CURVE" /* RD Category */
    },

    /* Impl_RD_struct for RD Y_AXIS_2D */
    {
      SRM_RDCOD_Y_AXIS_2D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "CURVE" /* RD Category */
    },

    /* Impl_RD_struct for RD X_AXIS_3D */
    {
      SRM_RDCOD_X_AXIS_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "CURVE" /* RD Category */
    },

    /* Impl_RD_struct for RD Y_AXIS_3D */
    {
      SRM_RDCOD_Y_AXIS_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "CURVE" /* RD Category */
    },

    /* Impl_RD_struct for RD Z_AXIS_3D */
    {
      SRM_RDCOD_Z_AXIS_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "CURVE" /* RD Category */
    },

    /* Impl_RD_struct for RD XY_PLANE_3D */
    {
      SRM_RDCOD_XY_PLANE_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "PLANE" /* RD Category */
    },

    /* Impl_RD_struct for RD XZ_PLANE_3D */
    {
      SRM_RDCOD_XZ_PLANE_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "PLANE" /* RD Category */
    },

    /* Impl_RD_struct for RD YZ_PLANE_3D */
    {
      SRM_RDCOD_YZ_PLANE_3D, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "PLANE" /* RD Category */
    },

    /* Impl_RD_struct for RD ADRASTEA_2000 */
    {
      SRM_RDCOD_ADRASTEA_2000, /* rd_code */
      1.0000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      8.0000000000000e3, /* b (semi-minor axis) */
      7.0000000000000e3, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD AIRY_1830 */
    {
      SRM_RDCOD_AIRY_1830, /* rd_code */
      6.3775633960000e6, /* a (semi-major axis) */
      2.9932496460000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD AMALTHEA_2000 */
    {
      SRM_RDCOD_AMALTHEA_2000, /* rd_code */
      1.2500000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      7.3000000000000e4, /* b (semi-minor axis) */
      6.4000000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD ANANKE_1988 */
    {
      SRM_RDCOD_ANANKE_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.0000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD APL_4r5_1968 */
    {
      SRM_RDCOD_APL_4r5_1968, /* rd_code */
      6.3781440000000e6, /* a (semi-major axis) */
      2.9823000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD ARIEL_1988 */
    {
      SRM_RDCOD_ARIEL_1988, /* rd_code */
      5.8110000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      5.7790000000000e5, /* b (semi-minor axis) */
      5.7770000000000e5, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD ATLAS_1988 */
    {
      SRM_RDCOD_ATLAS_1988, /* rd_code */
      1.8500000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.7200000000000e4, /* b (semi-minor axis) */
      1.3500000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD AUSTRALIAN_NATIONAL_1966 */
    {
      SRM_RDCOD_AUSTRALIAN_NATIONAL_1966, /* rd_code */
      6.3781600000000e6, /* a (semi-major axis) */
      2.9825000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD AVERAGE_TERRESTRIAL_1977 */
    {
      SRM_RDCOD_AVERAGE_TERRESTRIAL_1977, /* rd_code */
      6.3781350000000e6, /* a (semi-major axis) */
      2.9825700000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD BELINDA_1988 */
    {
      SRM_RDCOD_BELINDA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      3.3000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD BESSEL_1841_ETHIOPIA */
    {
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* rd_code */
      6.3773971550000e6, /* a (semi-major axis) */
      2.9915281280000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD BESSEL_1841_NAMIBIA */
    {
      SRM_RDCOD_BESSEL_1841_NAMIBIA, /* rd_code */
      6.3774838650000e6, /* a (semi-major axis) */
      2.9915281280000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD BIANCA_1988 */
    {
      SRM_RDCOD_BIANCA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      2.1000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD CALLISTO_2000 */
    {
      SRM_RDCOD_CALLISTO_2000, /* rd_code */
      2.4094000000000e6, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      2.4092000000000e6, /* b (semi-minor axis) */
      2.4093000000000e6, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CALYPSO_1988 */
    {
      SRM_RDCOD_CALYPSO_1988, /* rd_code */
      1.5000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      8.0000000000000e3, /* b (semi-minor axis) */
      8.0000000000000e3, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CARME_1988 */
    {
      SRM_RDCOD_CARME_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.5000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD CHARON_1991 */
    {
      SRM_RDCOD_CHARON_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      5.9300000000000e5, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1858 */
    {
      SRM_RDCOD_CLARKE_1858, /* rd_code */
      6.3782356000000e6, /* a (semi-major axis) */
      2.9426067680000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1858_MODIFIED */
    {
      SRM_RDCOD_CLARKE_1858_MODIFIED, /* rd_code */
      6.3782936450000e6, /* a (semi-major axis) */
      2.9426000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1866 */
    {
      SRM_RDCOD_CLARKE_1866, /* rd_code */
      6.3782064000000e6, /* a (semi-major axis) */
      2.9497869820000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1880 */
    {
      SRM_RDCOD_CLARKE_1880, /* rd_code */
      6.3782491450000e6, /* a (semi-major axis) */
      2.9346500000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1880_CAPE */
    {
      SRM_RDCOD_CLARKE_1880_CAPE, /* rd_code */
      6.3782491450000e6, /* a (semi-major axis) */
      2.9346630770000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1880_FIJI */
    {
      SRM_RDCOD_CLARKE_1880_FIJI, /* rd_code */
      6.3783010000000e6, /* a (semi-major axis) */
      2.9346500000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1880_IGN */
    {
      SRM_RDCOD_CLARKE_1880_IGN, /* rd_code */
      6.3782492000000e6, /* a (semi-major axis) */
      2.9346602080000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1880_PALESTINE */
    {
      SRM_RDCOD_CLARKE_1880_PALESTINE, /* rd_code */
      6.3783007820000e6, /* a (semi-major axis) */
      2.9346630770000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD CLARKE_1880_SYRIA */
    {
      SRM_RDCOD_CLARKE_1880_SYRIA, /* rd_code */
      6.3782478420000e6, /* a (semi-major axis) */
      2.9346635170000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD COAMPS_1998 */
    {
      SRM_RDCOD_COAMPS_1998, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.3712290000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD CORDELIA_1988 */
    {
      SRM_RDCOD_CORDELIA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.3000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD CRESSIDA_1988 */
    {
      SRM_RDCOD_CRESSIDA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      3.1000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD DANISH_1876 */
    {
      SRM_RDCOD_DANISH_1876, /* rd_code */
      6.3771044300000e6, /* a (semi-major axis) */
      3.0000000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD DEIMOS_1988 */
    {
      SRM_RDCOD_DEIMOS_1988, /* rd_code */
      7.5000000000000e3, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      6.1000000000000e3, /* b (semi-minor axis) */
      5.2000000000000e3, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD DELAMBRE_1810 */
    {
      SRM_RDCOD_DELAMBRE_1810, /* rd_code */
      6.3769852280000e6, /* a (semi-major axis) */
      3.0864000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD DESDEMONA_1988 */
    {
      SRM_RDCOD_DESDEMONA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      2.7000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD DESPINA_1991 */
    {
      SRM_RDCOD_DESPINA_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      7.4000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD DIONE_1982 */
    {
      SRM_RDCOD_DIONE_1982, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      5.6000000000000e5, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD ELARA_1988 */
    {
      SRM_RDCOD_ELARA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      4.0000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD ENCELADUS_1994 */
    {
      SRM_RDCOD_ENCELADUS_1994, /* rd_code */
      2.5630000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      2.4730000000000e5, /* b (semi-minor axis) */
      2.4460000000000e5, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD EPIMETHEUS_1988 */
    {
      SRM_RDCOD_EPIMETHEUS_1988, /* rd_code */
      6.9000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      5.5000000000000e4, /* b (semi-minor axis) */
      5.5000000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD EROS_2000 */
    {
      SRM_RDCOD_EROS_2000, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      7.3110000000000e3, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD EUROPA_2000 */
    {
      SRM_RDCOD_EUROPA_2000, /* rd_code */
      1.5641300000000e6, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.5612300000000e6, /* b (semi-minor axis) */
      1.5609300000000e6, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD EVEREST_ADJ_1937 */
    {
      SRM_RDCOD_EVEREST_ADJ_1937, /* rd_code */
      6.3772763450000e6, /* a (semi-major axis) */
      3.0080170000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD EVEREST_1948 */
    {
      SRM_RDCOD_EVEREST_1948, /* rd_code */
      6.3773040630000e6, /* a (semi-major axis) */
      3.0080170000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD EVEREST_1956 */
    {
      SRM_RDCOD_EVEREST_1956, /* rd_code */
      6.3773012430000e6, /* a (semi-major axis) */
      3.0080170000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD EVEREST_REVISED_1962 */
    {
      SRM_RDCOD_EVEREST_REVISED_1962, /* rd_code */
      6.3773096130000e6, /* a (semi-major axis) */
      3.0080170000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD EVEREST_1969 */
    {
      SRM_RDCOD_EVEREST_1969, /* rd_code */
      6.3772956640000e6, /* a (semi-major axis) */
      3.0080170000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD EVEREST_BRUNEI_1967 */
    {
      SRM_RDCOD_EVEREST_BRUNEI_1967, /* rd_code */
      6.3772985560000e6, /* a (semi-major axis) */
      3.0080170000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD FISCHER_1960 */
    {
      SRM_RDCOD_FISCHER_1960, /* rd_code */
      6.3781660000000e6, /* a (semi-major axis) */
      2.9830000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD FISCHER_1968 */
    {
      SRM_RDCOD_FISCHER_1968, /* rd_code */
      6.3781500000000e6, /* a (semi-major axis) */
      2.9830000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD GALATEA_1991 */
    {
      SRM_RDCOD_GALATEA_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      7.9000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD GANYMEDE_2000 */
    {
      SRM_RDCOD_GANYMEDE_2000, /* rd_code */
      2.6324000000000e6, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      2.6322900000000e6, /* b (semi-minor axis) */
      2.6323500000000e6, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD GASPRA_1991 */
    {
      SRM_RDCOD_GASPRA_1991, /* rd_code */
      9.1000000000000e3, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      5.2000000000000e3, /* b (semi-minor axis) */
      4.4000000000000e3, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD GRS_1967 */
    {
      SRM_RDCOD_GRS_1967, /* rd_code */
      6.3781600000000e6, /* a (semi-major axis) */
      2.9824716740000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD GRS_1980 */
    {
      SRM_RDCOD_GRS_1980, /* rd_code */
      6.3781370000000e6, /* a (semi-major axis) */
      2.9825722210100e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD HELENE_1992 */
    {
      SRM_RDCOD_HELENE_1992, /* rd_code */
      1.8000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.6000000000000e4, /* b (semi-minor axis) */
      1.5000000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD HELMERT_1906 */
    {
      SRM_RDCOD_HELMERT_1906, /* rd_code */
      6.3782000000000e6, /* a (semi-major axis) */
      2.9830000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD HIMALIA_1988 */
    {
      SRM_RDCOD_HIMALIA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      8.5000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD HOUGH_1960 */
    {
      SRM_RDCOD_HOUGH_1960, /* rd_code */
      6.3782700000000e6, /* a (semi-major axis) */
      2.9700000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD HYPERION_2000 */
    {
      SRM_RDCOD_HYPERION_2000, /* rd_code */
      1.6400000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.3000000000000e5, /* b (semi-minor axis) */
      1.0700000000000e5, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD IAG_1975 */
    {
      SRM_RDCOD_IAG_1975, /* rd_code */
      6.3781400000000e6, /* a (semi-major axis) */
      2.9825700000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD IAPETUS_1988 */
    {
      SRM_RDCOD_IAPETUS_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      7.1800000000000e5, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD IDA_1991 */
    {
      SRM_RDCOD_IDA_1991, /* rd_code */
      2.6800000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.2000000000000e4, /* b (semi-minor axis) */
      7.6000000000000e3, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD INDONESIAN_1974 */
    {
      SRM_RDCOD_INDONESIAN_1974, /* rd_code */
      6.3781600000000e6, /* a (semi-major axis) */
      2.9824700000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD INTERNATIONAL_1924 */
    {
      SRM_RDCOD_INTERNATIONAL_1924, /* rd_code */
      6.3783880000000e6, /* a (semi-major axis) */
      2.9700000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD IO_2000 */
    {
      SRM_RDCOD_IO_2000, /* rd_code */
      1.8294000000000e6, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.8293000000000e6, /* b (semi-minor axis) */
      1.8157000000000e6, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD JANUS_1988 */
    {
      SRM_RDCOD_JANUS_1988, /* rd_code */
      9.7000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      9.5000000000000e4, /* b (semi-minor axis) */
      7.7000000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD JULIET_1988 */
    {
      SRM_RDCOD_JULIET_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      4.2000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD JUPITER_1988 */
    {
      SRM_RDCOD_JUPITER_1988, /* rd_code */
      7.1492000000000e7, /* a (semi-major axis) */
      1.5414000000000e1, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD KLEOPATRA_2000 */
    {
      SRM_RDCOD_KLEOPATRA_2000, /* rd_code */
      1.0850000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      4.7000000000000e4, /* b (semi-minor axis) */
      4.0500000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD KRASSOVSKY_1940 */
    {
      SRM_RDCOD_KRASSOVSKY_1940, /* rd_code */
      6.3782450000000e6, /* a (semi-major axis) */
      2.9830000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD KRAYENHOFF_1827 */
    {
      SRM_RDCOD_KRAYENHOFF_1827, /* rd_code */
      6.3769504000000e6, /* a (semi-major axis) */
      3.0965000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD LARISSA_1991 */
    {
      SRM_RDCOD_LARISSA_1991, /* rd_code */
      1.0400000000000e5, /* a (semi-major axis) */
      6.9300000000000e0, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD LEDA_1988 */
    {
      SRM_RDCOD_LEDA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      5.0000000000000e3, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD LYSITHEA_1988 */
    {
      SRM_RDCOD_LYSITHEA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.2000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD MARS_2000 */
    {
      SRM_RDCOD_MARS_2000, /* rd_code */
      3.3961900000000e6, /* a (semi-major axis) */
      1.6989400000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD MARS_SPHERE_2000 */
    {
      SRM_RDCOD_MARS_SPHERE_2000, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      3.3895000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD MASS_1999 */
    {
      SRM_RDCOD_MASS_1999, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.3712213000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD MERCURY_1988 */
    {
      SRM_RDCOD_MERCURY_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      2.4397000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD METIS_2000 */
    {
      SRM_RDCOD_METIS_2000, /* rd_code */
      3.0000000000000e4, /* a (semi-major axis) */
      3.0000000000000e0, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD MIMAS_1994 */
    {
      SRM_RDCOD_MIMAS_1994, /* rd_code */
      2.0910000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.9620000000000e5, /* b (semi-minor axis) */
      1.9140000000000e5, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD MIRANDA_1988 */
    {
      SRM_RDCOD_MIRANDA_1988, /* rd_code */
      2.4040000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      2.3420000000000e5, /* b (semi-minor axis) */
      2.3290000000000e5, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD MM5_1997 */
    {
      SRM_RDCOD_MM5_1997, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.3700000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD MODIFIED_AIRY_1849 */
    {
      SRM_RDCOD_MODIFIED_AIRY_1849, /* rd_code */
      6.3773401890000e6, /* a (semi-major axis) */
      2.9932496460000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD MODIFIED_FISCHER_1960 */
    {
      SRM_RDCOD_MODIFIED_FISCHER_1960, /* rd_code */
      6.3781550000000e6, /* a (semi-major axis) */
      2.9830000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD MODTRAN_MIDLATITUDE_1989 */
    {
      SRM_RDCOD_MODTRAN_MIDLATITUDE_1989, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.3712300000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD MODTRAN_SUBARCTIC_1989 */
    {
      SRM_RDCOD_MODTRAN_SUBARCTIC_1989, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.3569100000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD MODTRAN_TROPICAL_1989 */
    {
      SRM_RDCOD_MODTRAN_TROPICAL_1989, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.3783900000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD MOON_1991 */
    {
      SRM_RDCOD_MOON_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.7374000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD MULTIGEN_FLAT_EARTH_1989 */
    {
      SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.3667070200000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD NAIAD_1991 */
    {
      SRM_RDCOD_NAIAD_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      2.9000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD NEPTUNE_1991 */
    {
      SRM_RDCOD_NEPTUNE_1991, /* rd_code */
      2.4764000000000e7, /* a (semi-major axis) */
      5.8544000000000e1, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD NEREID_1991 */
    {
      SRM_RDCOD_NEREID_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.7000000000000e5, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD NOGAPS_1988 */
    {
      SRM_RDCOD_NOGAPS_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.3710000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD OBERON_1988 */
    {
      SRM_RDCOD_OBERON_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      7.6140000000000e5, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD OPHELIA_1988 */
    {
      SRM_RDCOD_OPHELIA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.5000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD PAN_1991 */
    {
      SRM_RDCOD_PAN_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.0000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD PANDORA_1988 */
    {
      SRM_RDCOD_PANDORA_1988, /* rd_code */
      5.5000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      4.4000000000000e4, /* b (semi-minor axis) */
      3.1000000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD PASIPHAE_1988 */
    {
      SRM_RDCOD_PASIPHAE_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.8000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD PHOBOS_1988 */
    {
      SRM_RDCOD_PHOBOS_1988, /* rd_code */
      1.3400000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.1200000000000e4, /* b (semi-minor axis) */
      9.2000000000000e3, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD PHOEBE_1988 */
    {
      SRM_RDCOD_PHOEBE_1988, /* rd_code */
      1.1500000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.1000000000000e5, /* b (semi-minor axis) */
      1.0500000000000e5, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD PLESSIS_MODIFIED_1817 */
    {
      SRM_RDCOD_PLESSIS_MODIFIED_1817, /* rd_code */
      6.3765230000000e6, /* a (semi-major axis) */
      3.0864000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD PLUTO_1994 */
    {
      SRM_RDCOD_PLUTO_1994, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.1950000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD PORTIA_1988 */
    {
      SRM_RDCOD_PORTIA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      5.4000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD PROMETHEUS_1988 */
    {
      SRM_RDCOD_PROMETHEUS_1988, /* rd_code */
      7.4000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      5.0000000000000e4, /* b (semi-minor axis) */
      3.4000000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD PROTEUS_1991 */
    {
      SRM_RDCOD_PROTEUS_1991, /* rd_code */
      2.1800000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      2.0800000000000e5, /* b (semi-minor axis) */
      2.0100000000000e5, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD PUCK_1988 */
    {
      SRM_RDCOD_PUCK_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      7.7000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD RHEA_1988 */
    {
      SRM_RDCOD_RHEA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      7.6400000000000e5, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD ROSALIND_1988 */
    {
      SRM_RDCOD_ROSALIND_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      2.7000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD SATURN_1988 */
    {
      SRM_RDCOD_SATURN_1988, /* rd_code */
      6.0268000000000e7, /* a (semi-major axis) */
      1.0208000000000e1, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD SINOPE_1988 */
    {
      SRM_RDCOD_SINOPE_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.4000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD SOUTH_AMERICAN_1969 */
    {
      SRM_RDCOD_SOUTH_AMERICAN_1969, /* rd_code */
      6.3781600000000e6, /* a (semi-major axis) */
      2.9825000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD SOVIET_GEODETIC_1985 */
    {
      SRM_RDCOD_SOVIET_GEODETIC_1985, /* rd_code */
      6.3781360000000e6, /* a (semi-major axis) */
      2.9825700000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD SOVIET_GEODETIC_1990 */
    {
      SRM_RDCOD_SOVIET_GEODETIC_1990, /* rd_code */
      6.3781360000000e6, /* a (semi-major axis) */
      2.9825783930000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD STRUVE_1860 */
    {
      SRM_RDCOD_STRUVE_1860, /* rd_code */
      6.3782983000000e6, /* a (semi-major axis) */
      2.9473000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD SUN_1992 */
    {
      SRM_RDCOD_SUN_1992, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.9600000000000e8, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD TELESTO_1988 */
    {
      SRM_RDCOD_TELESTO_1988, /* rd_code */
      1.5000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      1.2500000000000e4, /* b (semi-minor axis) */
      7.5000000000000e3, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD TETHYS_1991 */
    {
      SRM_RDCOD_TETHYS_1991, /* rd_code */
      5.3560000000000e5, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      5.2820000000000e5, /* b (semi-minor axis) */
      5.2580000000000e5, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD THALASSA_1991 */
    {
      SRM_RDCOD_THALASSA_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      4.0000000000000e4, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD THEBE_2000 */
    {
      SRM_RDCOD_THEBE_2000, /* rd_code */
      5.8000000000000e4, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      4.9000000000000e4, /* b (semi-minor axis) */
      4.2000000000000e4, /* c (third axis in triaxial ellipsoid) */
      "TRI_AXIAL_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD TITAN_1982 */
    {
      SRM_RDCOD_TITAN_1982, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      2.5750000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD TITANIA_1988 */
    {
      SRM_RDCOD_TITANIA_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      7.8890000000000e5, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD TRITON_1991 */
    {
      SRM_RDCOD_TRITON_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      1.3526000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD UMBRIEL_1988 */
    {
      SRM_RDCOD_UMBRIEL_1988, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      5.8470000000000e5, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD URANUS_1988 */
    {
      SRM_RDCOD_URANUS_1988, /* rd_code */
      2.5559000000000e7, /* a (semi-major axis) */
      4.3616000000000e1, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD VENUS_1991 */
    {
      SRM_RDCOD_VENUS_1991, /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      6.0518000000000e6, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    },

    /* Impl_RD_struct for RD WALBECK_AMS_1963 */
    {
      SRM_RDCOD_WALBECK_AMS_1963, /* rd_code */
      6.3768960000000e6, /* a (semi-major axis) */
      3.0278000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD WALBECK_PLANHEFT_1942 */
    {
      SRM_RDCOD_WALBECK_PLANHEFT_1942, /* rd_code */
      6.3768950000000e6, /* a (semi-major axis) */
      3.0278215650000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD WAR_OFFICE_1924 */
    {
      SRM_RDCOD_WAR_OFFICE_1924, /* rd_code */
      6.3783000000000e6, /* a (semi-major axis) */
      2.9600000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD WGS_1960 */
    {
      SRM_RDCOD_WGS_1960, /* rd_code */
      6.3781650000000e6, /* a (semi-major axis) */
      2.9830000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD WGS_1966 */
    {
      SRM_RDCOD_WGS_1966, /* rd_code */
      6.3781450000000e6, /* a (semi-major axis) */
      2.9825000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD WGS_1984 */
    {
      SRM_RDCOD_WGS_1984, /* rd_code */
      6.3781370000000e6, /* a (semi-major axis) */
      2.9825722356300e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD WGS_1972 */
    {
      SRM_RDCOD_WGS_1972, /* rd_code */
      6.3781350000000e6, /* a (semi-major axis) */
      2.9826000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD NGA_SRM_MAX */
    {
      ((SRM_RD_Code)-1000), /* rd_code */
      6.4000000000000e6, /* a (semi-major axis) */
      1.5000000000000e2, /* f_inverse (inverse flattening ratio) */
      IMPL_NAN, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "OBLATE_ELLIPSOID" /* RD Category */
    },

    /* Impl_RD_struct for RD NGA_SPHERE */
    {
      ((SRM_RD_Code)-1001), /* rd_code */
      IMPL_NAN, /* a (semi-major axis) */
      IMPL_NAN, /* f_inverse (inverse flattening ratio) */
      NGA_SPHERE_RADIUS, /* r (spherical radius) */
      IMPL_NAN, /* b (semi-minor axis) */
      IMPL_NAN, /* c (third axis in triaxial ellipsoid) */
      "SPHERE" /* RD Category */
    }
}; /* end Impl_RD_struct_array */

Impl_RT_Struct Impl_RT_array[] =
{
    /* Impl_RT_structs for SRM_ORMCOD_ABSTRACT_2D */
    {
      SRM_RTCOD_ABSTRACT_2D_IDENTITY, /* RT code */
      SRM_ORMCOD_ABSTRACT_2D, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      IMPL_NAN, /* Region lower-left latitude */
      IMPL_NAN, /* Region lower-left longitude */
      IMPL_NAN, /* Region upper-right latitude */
      IMPL_NAN /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ABSTRACT_3D */
    {
      SRM_RTCOD_ABSTRACT_3D_IDENTITY, /* RT code */
      SRM_ORMCOD_ABSTRACT_3D, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      IMPL_NAN, /* Region lower-left latitude */
      IMPL_NAN, /* Region lower-left longitude */
      IMPL_NAN, /* Region upper-right latitude */
      IMPL_NAN /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ADINDAN_1991 */
    {
      SRM_RTCOD_ADINDAN_1991_BURKINA_FASO, /* RT code */
      SRM_ORMCOD_ADINDAN_1991, /* ORM code */
      -1.1800000000000e2, /* delta x */
      -1.4000000000000e1, /* delta y */
      2.1800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.0000000000000e0, /* Region lower-left latitude */
      -5.0000000000000e0, /* Region lower-left longitude */
      2.2000000000000e1, /* Region upper-right latitude */
      8.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ADINDAN_1991_CAMEROON, /* RT code */
      SRM_ORMCOD_ADINDAN_1991, /* ORM code */
      -1.3400000000000e2, /* delta x */
      -2.0000000000000e0, /* delta y */
      2.1000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.0000000000000e0, /* Region lower-left latitude */
      3.0000000000000e0, /* Region lower-left longitude */
      1.9000000000000e1, /* Region upper-right latitude */
      2.3000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ADINDAN_1991_ETHIOPIA, /* RT code */
      SRM_ORMCOD_ADINDAN_1991, /* ORM code */
      -1.6500000000000e2, /* delta x */
      -1.1000000000000e1, /* delta y */
      2.0600000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.0000000000000e0, /* Region lower-left latitude */
      2.6000000000000e1, /* Region lower-left longitude */
      2.5000000000000e1, /* Region upper-right latitude */
      5.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ADINDAN_1991_MALI, /* RT code */
      SRM_ORMCOD_ADINDAN_1991, /* ORM code */
      -1.2300000000000e2, /* delta x */
      -2.0000000000000e1, /* delta y */
      2.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e0, /* Region lower-left latitude */
      -2.0000000000000e1, /* Region lower-left longitude */
      3.1000000000000e1, /* Region upper-right latitude */
      1.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ADINDAN_1991_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_ADINDAN_1991, /* ORM code */
      -1.6600000000000e2, /* delta x */
      -1.5000000000000e1, /* delta y */
      2.0400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -5.0000000000000e0, /* Region lower-left latitude */
      1.5000000000000e1, /* Region lower-left longitude */
      3.1000000000000e1, /* Region upper-right latitude */
      5.5000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ADINDAN_1991_SENEGAL, /* RT code */
      SRM_ORMCOD_ADINDAN_1991, /* ORM code */
      -1.2800000000000e2, /* delta x */
      -1.8000000000000e1, /* delta y */
      2.2400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.0000000000000e0, /* Region lower-left latitude */
      -2.4000000000000e1, /* Region lower-left longitude */
      2.3000000000000e1, /* Region upper-right latitude */
      -5.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ADINDAN_1991_SUDAN, /* RT code */
      SRM_ORMCOD_ADINDAN_1991, /* ORM code */
      -1.6100000000000e2, /* delta x */
      -1.4000000000000e1, /* delta y */
      2.0500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.0000000000000e0, /* Region lower-left latitude */
      1.5000000000000e1, /* Region lower-left longitude */
      3.1000000000000e1, /* Region upper-right latitude */
      4.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ADRASTEA_2000 */
    {
      SRM_RTCOD_ADRASTEA_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_ADRASTEA_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_AFGOOYE_1987 */
    {
      SRM_RTCOD_AFGOOYE_1987_SOMALIA, /* RT code */
      SRM_ORMCOD_AFGOOYE_1987, /* ORM code */
      -4.3000000000000e1, /* delta x */
      -1.6300000000000e2, /* delta y */
      4.5000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -8.0000000000000e0, /* Region lower-left latitude */
      3.5000000000000e1, /* Region lower-left longitude */
      1.9000000000000e1, /* Region upper-right latitude */
      6.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_AIN_EL_ABD_1970 */
    {
      SRM_RTCOD_AIN_EL_ABD_1970_BAHRAIN_ISLAND, /* RT code */
      SRM_ORMCOD_AIN_EL_ABD_1970, /* ORM code */
      -1.5000000000000e2, /* delta x */
      -2.5000000000000e2, /* delta y */
      -1.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.4000000000000e1, /* Region lower-left latitude */
      4.9000000000000e1, /* Region lower-left longitude */
      2.8000000000000e1, /* Region upper-right latitude */
      5.3000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_AIN_EL_ABD_1970_SAUDI_ARABIA, /* RT code */
      SRM_ORMCOD_AIN_EL_ABD_1970, /* ORM code */
      -1.4300000000000e2, /* delta x */
      -2.3600000000000e2, /* delta y */
      7.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      8.0000000000000e0, /* Region lower-left latitude */
      2.8000000000000e1, /* Region lower-left longitude */
      3.8000000000000e1, /* Region upper-right latitude */
      6.2000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_AMALTHEA_2000 */
    {
      SRM_RTCOD_AMALTHEA_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_AMALTHEA_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_AMERICAN_SAMOA_1962 */
    {
      SRM_RTCOD_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS, /* RT code */
      SRM_ORMCOD_AMERICAN_SAMOA_1962, /* ORM code */
      -1.1500000000000e2, /* delta x */
      1.1800000000000e2, /* delta y */
      4.2600000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.9000000000000e1, /* Region lower-left latitude */
      -1.7400000000000e2, /* Region lower-left longitude */
      -9.0000000000000e0, /* Region upper-right latitude */
      -1.6500000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ANNA_1_1965 */
    {
      SRM_RTCOD_ANNA_1_1965_COCOS_ISLANDS, /* RT code */
      SRM_ORMCOD_ANNA_1_1965, /* ORM code */
      -4.9100000000000e2, /* delta x */
      -2.2000000000000e1, /* delta y */
      4.3500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.4000000000000e1, /* Region lower-left latitude */
      9.4000000000000e1, /* Region lower-left longitude */
      -1.0000000000000e1, /* Region upper-right latitude */
      9.9000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ANTIGUA_1943 */
    {
      SRM_RTCOD_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS, /* RT code */
      SRM_ORMCOD_ANTIGUA_1943, /* ORM code */
      -2.7000000000000e2, /* delta x */
      1.3000000000000e1, /* delta y */
      6.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.6000000000000e1, /* Region lower-left latitude */
      -6.5000000000000e1, /* Region lower-left longitude */
      2.0000000000000e1, /* Region upper-right latitude */
      -6.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ARC_1950 */
    {
      SRM_RTCOD_ARC_1950_3_ZIMBABWE, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.4200000000000e2, /* delta x */
      -9.6000000000000e1, /* delta y */
      -2.9300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.9000000000000e1, /* Region lower-left latitude */
      1.9000000000000e1, /* Region lower-left longitude */
      -9.0000000000000e0, /* Region upper-right latitude */
      3.9000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1950_BOTSWANA, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.3800000000000e2, /* delta x */
      -1.0500000000000e2, /* delta y */
      -2.8900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.3000000000000e1, /* Region lower-left latitude */
      1.3000000000000e1, /* Region lower-left longitude */
      -1.3000000000000e1, /* Region upper-right latitude */
      3.6000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1950_BURUNDI, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.5300000000000e2, /* delta x */
      -5.0000000000000e0, /* delta y */
      -2.9200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.1000000000000e1, /* Region lower-left latitude */
      2.1000000000000e1, /* Region lower-left longitude */
      4.0000000000000e0, /* Region upper-right latitude */
      3.7000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1950_LESOTHO, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.2500000000000e2, /* delta x */
      -1.0800000000000e2, /* delta y */
      -2.9500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.6000000000000e1, /* Region lower-left latitude */
      2.1000000000000e1, /* Region lower-left longitude */
      -2.3000000000000e1, /* Region upper-right latitude */
      3.5000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1950_MALAWI, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.6100000000000e2, /* delta x */
      -7.3000000000000e1, /* delta y */
      -3.1700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.1000000000000e1, /* Region lower-left latitude */
      2.6000000000000e1, /* Region lower-left longitude */
      -3.0000000000000e0, /* Region upper-right latitude */
      4.2000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1950_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.4300000000000e2, /* delta x */
      -9.0000000000000e1, /* delta y */
      -2.9400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.6000000000000e1, /* Region lower-left latitude */
      4.0000000000000e0, /* Region lower-left longitude */
      1.0000000000000e1, /* Region upper-right latitude */
      4.2000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1950_SWAZILAND, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.3400000000000e2, /* delta x */
      -1.0500000000000e2, /* delta y */
      -2.9500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.3000000000000e1, /* Region lower-left latitude */
      2.5000000000000e1, /* Region lower-left longitude */
      -2.0000000000000e1, /* Region upper-right latitude */
      4.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1950_ZAIRE, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.6900000000000e2, /* delta x */
      -1.9000000000000e1, /* delta y */
      -2.7800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.1000000000000e1, /* Region lower-left latitude */
      4.0000000000000e0, /* Region lower-left longitude */
      1.0000000000000e1, /* Region upper-right latitude */
      3.8000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1950_ZAMBIA, /* RT code */
      SRM_ORMCOD_ARC_1950, /* ORM code */
      -1.4700000000000e2, /* delta x */
      -7.4000000000000e1, /* delta y */
      -2.8300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.4000000000000e1, /* Region lower-left latitude */
      1.5000000000000e1, /* Region lower-left longitude */
      -1.0000000000000e0, /* Region upper-right latitude */
      4.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ARC_1960 */
    {
      SRM_RTCOD_ARC_1960_3_KENYA, /* RT code */
      SRM_ORMCOD_ARC_1960, /* ORM code */
      -1.5700000000000e2, /* delta x */
      -2.0000000000000e0, /* delta y */
      -2.9900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.1000000000000e1, /* Region lower-left latitude */
      2.8000000000000e1, /* Region lower-left longitude */
      8.0000000000000e0, /* Region upper-right latitude */
      4.7000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1960_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_ARC_1960, /* ORM code */
      -1.6000000000000e2, /* delta x */
      -6.0000000000000e0, /* delta y */
      -3.0200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.8000000000000e1, /* Region lower-left latitude */
      2.3000000000000e1, /* Region lower-left longitude */
      8.0000000000000e0, /* Region upper-right latitude */
      4.7000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_ARC_1960_TANZANIA, /* RT code */
      SRM_ORMCOD_ARC_1960, /* ORM code */
      -1.7500000000000e2, /* delta x */
      -2.3000000000000e1, /* delta y */
      -3.0300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.8000000000000e1, /* Region lower-left latitude */
      2.3000000000000e1, /* Region lower-left longitude */
      5.0000000000000e0, /* Region upper-right latitude */
      4.7000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ARIEL_1988 */
    {
      SRM_RTCOD_ARIEL_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_ARIEL_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ASCENSION_1958 */
    {
      SRM_RTCOD_ASCENSION_1958_ASCENSION_ISLAND, /* RT code */
      SRM_ORMCOD_ASCENSION_1958, /* ORM code */
      -2.0500000000000e2, /* delta x */
      1.0700000000000e2, /* delta y */
      5.3000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e0, /* Region lower-left latitude */
      -1.6000000000000e1, /* Region lower-left longitude */
      -6.0000000000000e0, /* Region upper-right latitude */
      -1.3000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ATLAS_1988 */
    {
      SRM_RTCOD_ATLAS_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_ATLAS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_AUSTRALIAN_GEOD_1966 */
    {
      SRM_RTCOD_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA, /* RT code */
      SRM_ORMCOD_AUSTRALIAN_GEOD_1966, /* ORM code */
      -1.3300000000000e2, /* delta x */
      -4.8000000000000e1, /* delta y */
      1.4800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.6000000000000e1, /* Region lower-left latitude */
      1.0900000000000e2, /* Region lower-left longitude */
      -4.0000000000000e0, /* Region upper-right latitude */
      1.6100000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_AUSTRALIAN_GEOD_1984 */
    {
      SRM_RTCOD_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA, /* RT code */
      SRM_ORMCOD_AUSTRALIAN_GEOD_1984, /* ORM code */
      -1.3400000000000e2, /* delta x */
      -4.8000000000000e1, /* delta y */
      1.4900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.6000000000000e1, /* Region lower-left latitude */
      1.0900000000000e2, /* Region lower-left longitude */
      -4.0000000000000e0, /* Region upper-right latitude */
      1.6100000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA, /* RT code */
      SRM_ORMCOD_AUSTRALIAN_GEOD_1984, /* ORM code */
      -1.1600000000000e2, /* delta x */
      -5.0470000000000e1, /* delta y */
      1.4169000000000e2, /* delta z */
      1.1150714665519e-6, /* omega 1 */
      1.8907733563272e-6, /* omega 2 */
      1.6677590630168e-6, /* omega 3 */
      9.8300000000000e-2, /* delta scale */
      -4.6000000000000e1, /* Region lower-left latitude */
      1.0900000000000e2, /* Region lower-left longitude */
      -4.0000000000000e0, /* Region upper-right latitude */
      1.6100000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991 */
    {
      SRM_RTCOD_AYABELLE_LIGHTHOUSE_1991_DJIBOUTI, /* RT code */
      SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991, /* ORM code */
      -7.9000000000000e1, /* delta x */
      -1.2900000000000e2, /* delta y */
      1.4500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.0000000000000e0, /* Region lower-left latitude */
      3.6000000000000e1, /* Region lower-left longitude */
      2.0000000000000e1, /* Region upper-right latitude */
      4.9000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BEACON_E_1945 */
    {
      SRM_RTCOD_BEACON_E_1945_IWO_JIMA_ISLAND, /* RT code */
      SRM_ORMCOD_BEACON_E_1945, /* ORM code */
      1.4500000000000e2, /* delta x */
      7.5000000000000e1, /* delta y */
      -2.7200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.2000000000000e1, /* Region lower-left latitude */
      1.4000000000000e2, /* Region lower-left longitude */
      2.6000000000000e1, /* Region upper-right latitude */
      1.4400000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BELINDA_1988 */
    {
      SRM_RTCOD_BELINDA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_BELINDA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BELLEVUE_IGN_1987 */
    {
      SRM_RTCOD_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS, /* RT code */
      SRM_ORMCOD_BELLEVUE_IGN_1987, /* ORM code */
      -1.2700000000000e2, /* delta x */
      -7.6900000000000e2, /* delta y */
      4.7200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.0000000000000e1, /* Region lower-left latitude */
      1.6700000000000e2, /* Region lower-left longitude */
      -1.6000000000000e1, /* Region upper-right latitude */
      1.7100000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BERMUDA_1957 */
    {
      SRM_RTCOD_BERMUDA_1957_BERMUDA, /* RT code */
      SRM_ORMCOD_BERMUDA_1957, /* ORM code */
      -7.3000000000000e1, /* delta x */
      2.1300000000000e2, /* delta y */
      2.9600000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.1000000000000e1, /* Region lower-left latitude */
      -6.6000000000000e1, /* Region lower-left longitude */
      3.4000000000000e1, /* Region upper-right latitude */
      -6.3000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BIANCA_1988 */
    {
      SRM_RTCOD_BIANCA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_BIANCA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BISSAU_1991 */
    {
      SRM_RTCOD_BISSAU_1991_GUINEA_BISSAU, /* RT code */
      SRM_ORMCOD_BISSAU_1991, /* ORM code */
      -1.7300000000000e2, /* delta x */
      2.5300000000000e2, /* delta y */
      2.7000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.0000000000000e0, /* Region lower-left latitude */
      -2.3000000000000e1, /* Region lower-left longitude */
      1.9000000000000e1, /* Region upper-right latitude */
      -7.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BOGOTA_OBS_1987 */
    {
      SRM_RTCOD_BOGOTA_OBS_1987_COLOMBIA, /* RT code */
      SRM_ORMCOD_BOGOTA_OBS_1987, /* ORM code */
      3.0700000000000e2, /* delta x */
      3.0400000000000e2, /* delta y */
      -3.1800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e1, /* Region lower-left latitude */
      -8.5000000000000e1, /* Region lower-left longitude */
      1.6000000000000e1, /* Region upper-right latitude */
      -6.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA */
    {
      SRM_RTCOD_BOGOTA_OBS_1987_PM_BOGOTA_COLOMBIA, /* RT code */
      SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA, /* ORM code */
      3.0700000000000e2, /* delta x */
      3.0400000000000e2, /* delta y */
      -3.1800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      4.9902293984507e0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e1, /* Region lower-left latitude */
      -1.1000000000000e1, /* Region lower-left longitude */
      1.6000000000000e1, /* Region upper-right latitude */
      1.3000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_BUKIT_RIMPAH_1987 */
    {
      SRM_RTCOD_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS, /* RT code */
      SRM_ORMCOD_BUKIT_RIMPAH_1987, /* ORM code */
      -3.8400000000000e2, /* delta x */
      6.6400000000000e2, /* delta y */
      -4.8000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.0000000000000e0, /* Region lower-left latitude */
      1.0300000000000e2, /* Region lower-left longitude */
      0.0, /* Region upper-right latitude */
      1.1000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CALLISTO_2000 */
    {
      SRM_RTCOD_CALLISTO_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_CALLISTO_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CALYPSO_1988 */
    {
      SRM_RTCOD_CALYPSO_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_CALYPSO_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CAMP_AREA_1987 */
    {
      SRM_RTCOD_CAMP_AREA_1987_MCMURDO_CAMP, /* RT code */
      SRM_ORMCOD_CAMP_AREA_1987, /* ORM code */
      -1.0400000000000e2, /* delta x */
      -1.2900000000000e2, /* delta y */
      2.3900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -8.5000000000000e1, /* Region lower-left latitude */
      1.3500000000000e2, /* Region lower-left longitude */
      -7.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CAMPO_INCHAUSPE_1969 */
    {
      SRM_RTCOD_CAMPO_INCHAUSPE_1969_ARGENTINA, /* RT code */
      SRM_ORMCOD_CAMPO_INCHAUSPE_1969, /* ORM code */
      -1.4800000000000e2, /* delta x */
      1.3600000000000e2, /* delta y */
      9.0000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -5.8000000000000e1, /* Region lower-left latitude */
      -7.2000000000000e1, /* Region lower-left longitude */
      -2.7000000000000e1, /* Region upper-right latitude */
      -5.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CANTON_1966 */
    {
      SRM_RTCOD_CANTON_1966_PHOENIX_ISLANDS, /* RT code */
      SRM_ORMCOD_CANTON_1966, /* ORM code */
      2.9800000000000e2, /* delta x */
      -3.0400000000000e2, /* delta y */
      -3.7500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.3000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      3.0000000000000e0, /* Region upper-right latitude */
      -1.6500000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CAPE_1987 */
    {
      SRM_RTCOD_CAPE_1987_SOUTH_AFRICA, /* RT code */
      SRM_ORMCOD_CAPE_1987, /* ORM code */
      -1.3600000000000e2, /* delta x */
      -1.0800000000000e2, /* delta y */
      -2.9200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.3000000000000e1, /* Region lower-left latitude */
      1.0000000000000e1, /* Region lower-left longitude */
      -1.5000000000000e1, /* Region upper-right latitude */
      4.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CAPE_CANAVERAL_1991 */
    {
      SRM_RTCOD_CAPE_CANAVERAL_1991_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_CAPE_CANAVERAL_1991, /* ORM code */
      -2.0000000000000e0, /* delta x */
      1.5100000000000e2, /* delta y */
      1.8100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.5000000000000e1, /* Region lower-left latitude */
      -9.4000000000000e1, /* Region lower-left longitude */
      3.8000000000000e1, /* Region upper-right latitude */
      -1.2000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CARTHAGE_1987 */
    {
      SRM_RTCOD_CARTHAGE_1987_TUNISIA, /* RT code */
      SRM_ORMCOD_CARTHAGE_1987, /* ORM code */
      -2.6300000000000e2, /* delta x */
      6.0000000000000e0, /* delta y */
      4.3100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.4000000000000e1, /* Region lower-left latitude */
      2.0000000000000e0, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      1.8000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CHARON_1991 */
    {
      SRM_RTCOD_CHARON_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_CHARON_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CHATHAM_1971 */
    {
      SRM_RTCOD_CHATHAM_1971_CHATHAM_ISLANDS, /* RT code */
      SRM_ORMCOD_CHATHAM_1971, /* ORM code */
      1.7500000000000e2, /* delta x */
      -3.8000000000000e1, /* delta y */
      1.1300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.6000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      -4.2000000000000e1, /* Region upper-right latitude */
      -1.7400000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CHUA_1987 */
    {
      SRM_RTCOD_CHUA_1987_PARAGUAY, /* RT code */
      SRM_ORMCOD_CHUA_1987, /* ORM code */
      -1.3400000000000e2, /* delta x */
      2.2900000000000e2, /* delta y */
      -2.9000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.3000000000000e1, /* Region lower-left latitude */
      -6.9000000000000e1, /* Region lower-left longitude */
      -1.4000000000000e1, /* Region upper-right latitude */
      -4.9000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_COAMPS_1998 */
    {
      SRM_RTCOD_COAMPS_1998_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_COAMPS_1998, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CORDELIA_1988 */
    {
      SRM_RTCOD_CORDELIA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_CORDELIA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CORREGO_ALEGRE_1987 */
    {
      SRM_RTCOD_CORREGO_ALEGRE_1987_BRAZIL, /* RT code */
      SRM_ORMCOD_CORREGO_ALEGRE_1987, /* ORM code */
      -2.0600000000000e2, /* delta x */
      1.7200000000000e2, /* delta y */
      -6.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.9000000000000e1, /* Region lower-left latitude */
      -8.0000000000000e1, /* Region lower-left longitude */
      -2.0000000000000e0, /* Region upper-right latitude */
      -2.9000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_CRESSIDA_1988 */
    {
      SRM_RTCOD_CRESSIDA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_CRESSIDA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DABOLA_1991 */
    {
      SRM_RTCOD_DABOLA_1991_GUINEA, /* RT code */
      SRM_ORMCOD_DABOLA_1991, /* ORM code */
      -8.3000000000000e1, /* delta x */
      3.7000000000000e1, /* delta y */
      1.2400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.0000000000000e0, /* Region lower-left latitude */
      -1.7000000000000e1, /* Region lower-left longitude */
      1.9000000000000e1, /* Region upper-right latitude */
      -7.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DECEPTION_1993 */
    {
      SRM_RTCOD_DECEPTION_1993_DECEPTION_ISLAND, /* RT code */
      SRM_ORMCOD_DECEPTION_1993, /* ORM code */
      2.6000000000000e2, /* delta x */
      1.2000000000000e1, /* delta y */
      -1.4700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.5000000000000e1, /* Region lower-left latitude */
      5.8000000000000e1, /* Region lower-left longitude */
      -6.2000000000000e1, /* Region upper-right latitude */
      6.2000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DEIMOS_1988 */
    {
      SRM_RTCOD_DEIMOS_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_DEIMOS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DESDEMONA_1988 */
    {
      SRM_RTCOD_DESDEMONA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_DESDEMONA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DESPINA_1991 */
    {
      SRM_RTCOD_DESPINA_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_DESPINA_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DIONE_1982 */
    {
      SRM_RTCOD_DIONE_1982_IDENTITY, /* RT code */
      SRM_ORMCOD_DIONE_1982, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA */
    {
      SRM_RTCOD_DJAKARTA_1987_PM_DJAKARTA_SUMATRA, /* RT code */
      SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA, /* ORM code */
      -3.7700000000000e2, /* delta x */
      6.8100000000000e2, /* delta y */
      -5.0000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      1.8641463708519e0, /* omega 3 */
      0.0, /* delta scale */
      -1.6000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e1, /* Region lower-left longitude */
      1.1000000000000e1, /* Region upper-right latitude */
      3.9000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DJAKARTA_1987 */
    {
      SRM_RTCOD_DJAKARTA_1987_SUMATRA, /* RT code */
      SRM_ORMCOD_DJAKARTA_1987, /* ORM code */
      -3.7700000000000e2, /* delta x */
      6.8100000000000e2, /* delta y */
      -5.0000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.6000000000000e1, /* Region lower-left latitude */
      8.9000000000000e1, /* Region lower-left longitude */
      1.1000000000000e1, /* Region upper-right latitude */
      1.4600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DOS_1968 */
    {
      SRM_RTCOD_DOS_1968_GIZO_ISLAND, /* RT code */
      SRM_ORMCOD_DOS_1968, /* ORM code */
      2.3000000000000e2, /* delta x */
      -1.9900000000000e2, /* delta y */
      -7.5200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e1, /* Region lower-left latitude */
      1.5500000000000e2, /* Region lower-left longitude */
      -7.0000000000000e0, /* Region upper-right latitude */
      1.5800000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_DOS_71_4_1987 */
    {
      SRM_RTCOD_DOS_71_4_1987_ST_HELENA_ISLAND, /* RT code */
      SRM_ORMCOD_DOS_71_4_1987, /* ORM code */
      -3.2000000000000e2, /* delta x */
      5.5000000000000e2, /* delta y */
      -4.9400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.8000000000000e1, /* Region lower-left latitude */
      -7.0000000000000e0, /* Region lower-left longitude */
      -1.4000000000000e1, /* Region upper-right latitude */
      -4.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_EASTER_1967 */
    {
      SRM_RTCOD_EASTER_1967_EASTER_ISLAND, /* RT code */
      SRM_ORMCOD_EASTER_1967, /* ORM code */
      2.1100000000000e2, /* delta x */
      1.4700000000000e2, /* delta y */
      1.1100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.9000000000000e1, /* Region lower-left latitude */
      -1.1100000000000e2, /* Region lower-left longitude */
      -2.6000000000000e1, /* Region upper-right latitude */
      -1.0800000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ENCELADUS_1994 */
    {
      SRM_RTCOD_ENCELADUS_1994_IDENTITY, /* RT code */
      SRM_ORMCOD_ENCELADUS_1994, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_EPIMETHEUS_1988 */
    {
      SRM_RTCOD_EPIMETHEUS_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_EPIMETHEUS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_EROS_2000 */
    {
      SRM_RTCOD_EROS_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_EROS_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ESTONIA_1937 */
    {
      SRM_RTCOD_ESTONIA_1937_ESTONIA, /* RT code */
      SRM_ORMCOD_ESTONIA_1937, /* ORM code */
      3.7400000000000e2, /* delta x */
      1.5000000000000e2, /* delta y */
      5.8800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.2000000000000e1, /* Region lower-left latitude */
      1.6000000000000e1, /* Region lower-left longitude */
      6.5000000000000e1, /* Region upper-right latitude */
      3.4000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ETRS_1989 */
    {
      SRM_RTCOD_ETRS_1989_IDENTITY_BY_MEASUREMENT, /* RT code */
      SRM_ORMCOD_ETRS_1989, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.4000000000000e1, /* Region lower-left latitude */
      -1.2000000000000e1, /* Region lower-left longitude */
      7.3000000000000e1, /* Region upper-right latitude */
      3.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_EUROPA_2000 */
    {
      SRM_RTCOD_EUROPA_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_EUROPA_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_EUROPE_1950 */
    {
      SRM_RTCOD_EUROPE_1950_3_CYPRUS, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -1.0400000000000e2, /* delta x */
      -1.0100000000000e2, /* delta y */
      -1.4000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.3000000000000e1, /* Region lower-left latitude */
      3.1000000000000e1, /* Region lower-left longitude */
      3.7000000000000e1, /* Region upper-right latitude */
      3.6000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_CHANNEL_ISLANDS, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -8.3901000000000e1, /* delta x */
      -9.8127000000000e1, /* delta y */
      -1.1863500000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.8000000000000e1, /* Region lower-left latitude */
      -4.0000000000000e0, /* Region lower-left longitude */
      5.0000000000000e1, /* Region upper-right latitude */
      -1.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_EGYPT, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -1.3000000000000e2, /* delta x */
      -1.1700000000000e2, /* delta y */
      -1.5100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.6000000000000e1, /* Region lower-left latitude */
      1.9000000000000e1, /* Region lower-left longitude */
      3.8000000000000e1, /* Region upper-right latitude */
      4.2000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_ENGLAND_SCOTLAND, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -8.6000000000000e1, /* delta x */
      -9.6000000000000e1, /* delta y */
      -1.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.8000000000000e1, /* Region lower-left latitude */
      -1.0000000000000e1, /* Region lower-left longitude */
      6.2000000000000e1, /* Region upper-right latitude */
      3.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_GREECE, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -8.4000000000000e1, /* delta x */
      -9.5000000000000e1, /* delta y */
      -1.3000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e1, /* Region lower-left latitude */
      1.4000000000000e1, /* Region lower-left longitude */
      4.8000000000000e1, /* Region upper-right latitude */
      3.4000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_IRAN, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -1.1700000000000e2, /* delta x */
      -1.3200000000000e2, /* delta y */
      -1.6400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      3.7000000000000e1, /* Region lower-left longitude */
      4.7000000000000e1, /* Region upper-right latitude */
      6.9000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_IRAQ, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -1.0300000000000e2, /* delta x */
      -1.0600000000000e2, /* delta y */
      -1.4100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.8000000000000e1, /* Region lower-left latitude */
      3.6000000000000e1, /* Region lower-left longitude */
      -4.0000000000000e0, /* Region upper-right latitude */
      5.7000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_IRELAND, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -8.6000000000000e1, /* delta x */
      -9.6000000000000e1, /* delta y */
      -1.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.8000000000000e1, /* Region lower-left latitude */
      -1.2000000000000e1, /* Region lower-left longitude */
      6.2000000000000e1, /* Region upper-right latitude */
      3.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_MALTA, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -1.0700000000000e2, /* delta x */
      -8.8000000000000e1, /* delta y */
      -1.4900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.4000000000000e1, /* Region lower-left latitude */
      1.2000000000000e1, /* Region lower-left longitude */
      3.8000000000000e1, /* Region upper-right latitude */
      1.6000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -8.7000000000000e1, /* delta x */
      -9.8000000000000e1, /* delta y */
      -1.2100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e1, /* Region lower-left latitude */
      5.0000000000000e0, /* Region lower-left longitude */
      8.0000000000000e1, /* Region upper-right latitude */
      3.3000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_NORWAY, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -8.7000000000000e1, /* delta x */
      -9.5000000000000e1, /* delta y */
      -1.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.2000000000000e1, /* Region lower-left latitude */
      -2.0000000000000e0, /* Region lower-left longitude */
      8.0000000000000e1, /* Region upper-right latitude */
      3.8000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_PORTUGAL_SPAIN, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -8.4000000000000e1, /* delta x */
      -1.0700000000000e2, /* delta y */
      -1.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e1, /* Region lower-left latitude */
      -1.5000000000000e1, /* Region lower-left longitude */
      4.9000000000000e1, /* Region upper-right latitude */
      1.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_SARDINIA, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -9.7000000000000e1, /* delta x */
      -1.0300000000000e2, /* delta y */
      -1.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.7000000000000e1, /* Region lower-left latitude */
      6.0000000000000e0, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      1.2000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_SICILY, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -9.7000000000000e1, /* delta x */
      -8.8000000000000e1, /* delta y */
      -1.3500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.5000000000000e1, /* Region lower-left latitude */
      1.0000000000000e1, /* Region lower-left longitude */
      4.0000000000000e1, /* Region upper-right latitude */
      1.7000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_TUNISIA, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -1.1200000000000e2, /* delta x */
      -7.7000000000000e1, /* delta y */
      -1.4500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.4000000000000e1, /* Region lower-left latitude */
      2.0000000000000e0, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      1.8000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_EUROPE_1950_W_EUROPE_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_EUROPE_1950, /* ORM code */
      -8.7000000000000e1, /* delta x */
      -9.6000000000000e1, /* delta y */
      -1.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e1, /* Region lower-left latitude */
      -1.5000000000000e1, /* Region lower-left longitude */
      7.8000000000000e1, /* Region upper-right latitude */
      2.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_EUROPE_1979 */
    {
      SRM_RTCOD_EUROPE_1979_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_EUROPE_1979, /* ORM code */
      -8.6000000000000e1, /* delta x */
      -9.8000000000000e1, /* delta y */
      -1.1900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e1, /* Region lower-left latitude */
      -1.5000000000000e1, /* Region lower-left longitude */
      8.0000000000000e1, /* Region upper-right latitude */
      2.4000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_FAHUD_1987 */
    {
      SRM_RTCOD_FAHUD_1987_3_OMAN, /* RT code */
      SRM_ORMCOD_FAHUD_1987, /* ORM code */
      -3.4600000000000e2, /* delta x */
      -1.0000000000000e0, /* delta y */
      2.2400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.0000000000000e1, /* Region lower-left latitude */
      4.6000000000000e1, /* Region lower-left longitude */
      3.2000000000000e1, /* Region upper-right latitude */
      6.5000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_FAHUD_1987_7_OMAN, /* RT code */
      SRM_ORMCOD_FAHUD_1987, /* ORM code */
      -1.7369000000000e2, /* delta x */
      -2.4771000000000e2, /* delta y */
      1.6208000000000e2, /* delta z */
      -5.5317241014598e-6, /* omega 1 */
      -1.3239292003739e-5, /* omega 2 */
      4.1860267668041e-5, /* omega 3 */
      1.9727000000000e1, /* delta scale */
      1.0000000000000e1, /* Region lower-left latitude */
      4.6000000000000e1, /* Region lower-left longitude */
      3.2000000000000e1, /* Region upper-right latitude */
      6.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_FORT_THOMAS_1955 */
    {
      SRM_RTCOD_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS, /* RT code */
      SRM_ORMCOD_FORT_THOMAS_1955, /* ORM code */
      -7.0000000000000e0, /* delta x */
      2.1500000000000e2, /* delta y */
      2.2500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.6000000000000e1, /* Region lower-left latitude */
      -6.4000000000000e1, /* Region lower-left longitude */
      1.9000000000000e1, /* Region upper-right latitude */
      -6.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GALATEA_1991 */
    {
      SRM_RTCOD_GALATEA_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_GALATEA_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GAN_1970 */
    {
      SRM_RTCOD_GAN_1970_MALDIVES, /* RT code */
      SRM_ORMCOD_GAN_1970, /* ORM code */
      -1.3300000000000e2, /* delta x */
      -3.2100000000000e2, /* delta y */
      5.0000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.0000000000000e0, /* Region lower-left latitude */
      7.1000000000000e1, /* Region lower-left longitude */
      9.0000000000000e0, /* Region upper-right latitude */
      7.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GANYMEDE_2000 */
    {
      SRM_RTCOD_GANYMEDE_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_GANYMEDE_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GASPRA_1991 */
    {
      SRM_RTCOD_GASPRA_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_GASPRA_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GDA_1994 */
    {
      SRM_RTCOD_GDA_1994_IDENTITY_BY_MEASUREMENT, /* RT code */
      SRM_ORMCOD_GDA_1994, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.2000000000000e1, /* Region lower-left latitude */
      1.1000000000000e2, /* Region lower-left longitude */
      -8.0000000000000e0, /* Region upper-right latitude */
      1.5500000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEODETIC_DATUM_1949 */
    {
      SRM_RTCOD_GEODETIC_DATUM_1949_3_NEW_ZEALAND, /* RT code */
      SRM_ORMCOD_GEODETIC_DATUM_1949, /* ORM code */
      8.4000000000000e1, /* delta x */
      -2.2000000000000e1, /* delta y */
      2.0900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.8000000000000e1, /* Region lower-left latitude */
      1.6500000000000e2, /* Region lower-left longitude */
      -3.3000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_GEODETIC_DATUM_1949_7_NEW_ZEALAND, /* RT code */
      SRM_ORMCOD_GEODETIC_DATUM_1949, /* ORM code */
      5.9470000000000e1, /* delta x */
      -5.0400000000000e0, /* delta y */
      1.8744000000000e2, /* delta z */
      2.2786243012148e-6, /* omega 1 */
      -4.8481368110954e-7, /* omega 2 */
      4.9644920945617e-6, /* omega 3 */
      -4.5993000000000e0, /* delta scale */
      -4.8000000000000e1, /* Region lower-left latitude */
      1.6500000000000e2, /* Region lower-left longitude */
      -3.3000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1945 */
    {
      SRM_RTCOD_GEOMAGNETIC_1945_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1945, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.5899017431930e-5, /* omega 2 */
      -3.3224281566437e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1950 */
    {
      SRM_RTCOD_GEOMAGNETIC_1950_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1950, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.5899017431930e-5, /* omega 2 */
      -3.3379421944392e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1955 */
    {
      SRM_RTCOD_GEOMAGNETIC_1955_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1955, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.5947498800040e-5, /* omega 2 */
      -3.3529714185536e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1960 */
    {
      SRM_RTCOD_GEOMAGNETIC_1960_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1960, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.5705091959486e-5, /* omega 2 */
      -3.3680006426680e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1965 */
    {
      SRM_RTCOD_GEOMAGNETIC_1965_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1965, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.5608129223264e-5, /* omega 2 */
      -3.3864235625501e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1970 */
    {
      SRM_RTCOD_GEOMAGNETIC_1970_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1970, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.5317241014598e-5, /* omega 2 */
      -3.4024224140267e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1975 */
    {
      SRM_RTCOD_GEOMAGNETIC_1975_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1975, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.4832427333489e-5, /* omega 2 */
      -3.4164820107789e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1980 */
    {
      SRM_RTCOD_GEOMAGNETIC_1980_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1980, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.4250650916157e-5, /* omega 2 */
      -3.4305416075311e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1985 */
    {
      SRM_RTCOD_GEOMAGNETIC_1985_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1985, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.3474949026382e-5, /* omega 2 */
      -3.4373289990666e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1990 */
    {
      SRM_RTCOD_GEOMAGNETIC_1990_DGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1990, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.2699247136607e-5, /* omega 2 */
      -3.4475100863699e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_1995 */
    {
      SRM_RTCOD_GEOMAGNETIC_1995_IGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_1995, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.1875063878720e-5, /* omega 2 */
      -3.4620544968032e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GEOMAGNETIC_2000 */
    {
      SRM_RTCOD_GEOMAGNETIC_2000_IGRF, /* RT code */
      SRM_ORMCOD_GEOMAGNETIC_2000, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      5.0711511044058e-5, /* omega 2 */
      -3.4698115157010e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GRACIOSA_BASE_SW_1948 */
    {
      SRM_RTCOD_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES, /* RT code */
      SRM_ORMCOD_GRACIOSA_BASE_SW_1948, /* ORM code */
      -1.0400000000000e2, /* delta x */
      1.6700000000000e2, /* delta y */
      -3.8000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.7000000000000e1, /* Region lower-left latitude */
      -3.0000000000000e1, /* Region lower-left longitude */
      4.1000000000000e1, /* Region upper-right latitude */
      -2.6000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GUAM_1963 */
    {
      SRM_RTCOD_GUAM_1963_GUAM, /* RT code */
      SRM_ORMCOD_GUAM_1963, /* ORM code */
      -1.0000000000000e2, /* delta x */
      -2.4800000000000e2, /* delta y */
      2.5900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.2000000000000e1, /* Region lower-left latitude */
      1.4300000000000e2, /* Region lower-left longitude */
      1.5000000000000e1, /* Region upper-right latitude */
      1.4600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GUNONG_SEGARA_1987 */
    {
      SRM_RTCOD_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND, /* RT code */
      SRM_ORMCOD_GUNONG_SEGARA_1987, /* ORM code */
      -4.0300000000000e2, /* delta x */
      6.8400000000000e2, /* delta y */
      4.1000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.0000000000000e0, /* Region lower-left latitude */
      1.0600000000000e2, /* Region lower-left longitude */
      9.0000000000000e0, /* Region upper-right latitude */
      1.2100000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_GUX_1_1987 */
    {
      SRM_RTCOD_GUX_1_1987_GUADALCANAL_ISLAND, /* RT code */
      SRM_ORMCOD_GUX_1_1987, /* ORM code */
      2.5200000000000e2, /* delta x */
      -2.0900000000000e2, /* delta y */
      -7.5100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.2000000000000e1, /* Region lower-left latitude */
      1.5800000000000e2, /* Region lower-left longitude */
      -8.0000000000000e0, /* Region upper-right latitude */
      1.6300000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_HELENE_1992 */
    {
      SRM_RTCOD_HELENE_1992_IDENTITY, /* RT code */
      SRM_ORMCOD_HELENE_1992, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_HERAT_NORTH_1987 */
    {
      SRM_RTCOD_HERAT_NORTH_1987_AFGHANISTAN, /* RT code */
      SRM_ORMCOD_HERAT_NORTH_1987, /* ORM code */
      -3.3300000000000e2, /* delta x */
      -2.2200000000000e2, /* delta y */
      1.1400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.3000000000000e1, /* Region lower-left latitude */
      5.5000000000000e1, /* Region lower-left longitude */
      4.4000000000000e1, /* Region upper-right latitude */
      8.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_HERMANNSKOGEL_1871 */
    {
      SRM_RTCOD_HERMANNSKOGEL_1871_3_YUGOSLAVIA, /* RT code */
      SRM_ORMCOD_HERMANNSKOGEL_1871, /* ORM code */
      6.8200000000000e2, /* delta x */
      -2.0300000000000e2, /* delta y */
      4.8000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.5000000000000e1, /* Region lower-left latitude */
      7.0000000000000e0, /* Region lower-left longitude */
      5.2000000000000e1, /* Region upper-right latitude */
      2.9000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_HJORSEY_1955 */
    {
      SRM_RTCOD_HJORSEY_1955_ICELAND, /* RT code */
      SRM_ORMCOD_HJORSEY_1955, /* ORM code */
      -7.3000000000000e1, /* delta x */
      4.6000000000000e1, /* delta y */
      -8.6000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      6.1000000000000e1, /* Region lower-left latitude */
      -2.4000000000000e1, /* Region lower-left longitude */
      6.9000000000000e1, /* Region upper-right latitude */
      -1.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_HONG_KONG_1963 */
    {
      SRM_RTCOD_HONG_KONG_1963_HONG_KONG, /* RT code */
      SRM_ORMCOD_HONG_KONG_1963, /* ORM code */
      -1.5600000000000e2, /* delta x */
      -2.7100000000000e2, /* delta y */
      -1.8900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.1000000000000e1, /* Region lower-left latitude */
      1.1200000000000e2, /* Region lower-left longitude */
      2.4000000000000e1, /* Region upper-right latitude */
      1.1600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_HU_TZU_SHAN_1991 */
    {
      SRM_RTCOD_HU_TZU_SHAN_1991_TAIWAN, /* RT code */
      SRM_ORMCOD_HU_TZU_SHAN_1991, /* ORM code */
      -6.3700000000000e2, /* delta x */
      -5.4900000000000e2, /* delta y */
      -2.0300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.0000000000000e1, /* Region lower-left latitude */
      1.1700000000000e2, /* Region lower-left longitude */
      2.8000000000000e1, /* Region upper-right latitude */
      1.2400000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_IAPETUS_1988 */
    {
      SRM_RTCOD_IAPETUS_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_IAPETUS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_IDA_1991 */
    {
      SRM_RTCOD_IDA_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_IDA_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_INDIAN_1916 */
    {
      SRM_RTCOD_INDIAN_1916_3_BANGLADESH, /* RT code */
      SRM_ORMCOD_INDIAN_1916, /* ORM code */
      2.8200000000000e2, /* delta x */
      7.2600000000000e2, /* delta y */
      2.5400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.5000000000000e1, /* Region lower-left latitude */
      8.0000000000000e1, /* Region lower-left longitude */
      3.3000000000000e1, /* Region upper-right latitude */
      1.0000000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_INDIAN_1916_7_BANGLADESH, /* RT code */
      SRM_ORMCOD_INDIAN_1916, /* ORM code */
      7.9200000000000e1, /* delta x */
      6.7030000000000e2, /* delta y */
      2.3000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      -3.5265347163908e-5, /* omega 3 */
      1.1034000000000e1, /* delta scale */
      1.5000000000000e1, /* Region lower-left latitude */
      8.0000000000000e1, /* Region lower-left longitude */
      3.3000000000000e1, /* Region upper-right latitude */
      1.0000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_INDIAN_1954 */
    {
      SRM_RTCOD_INDIAN_1954_THAILAND, /* RT code */
      SRM_ORMCOD_INDIAN_1954, /* ORM code */
      2.1700000000000e2, /* delta x */
      8.2300000000000e2, /* delta y */
      2.9900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      0.0, /* Region lower-left latitude */
      9.1000000000000e1, /* Region lower-left longitude */
      2.7000000000000e1, /* Region upper-right latitude */
      1.1100000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_INDIAN_1956 */
    {
      SRM_RTCOD_INDIAN_1956_INDIA_NEPAL, /* RT code */
      SRM_ORMCOD_INDIAN_1956, /* ORM code */
      2.9500000000000e2, /* delta x */
      7.3600000000000e2, /* delta y */
      2.5700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.0000000000000e0, /* Region lower-left latitude */
      6.2000000000000e1, /* Region lower-left longitude */
      4.4000000000000e1, /* Region upper-right latitude */
      1.0500000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_INDIAN_1960 */
    {
      SRM_RTCOD_INDIAN_1960_CON_SON_ISLAND, /* RT code */
      SRM_ORMCOD_INDIAN_1960, /* ORM code */
      1.8200000000000e2, /* delta x */
      9.1500000000000e2, /* delta y */
      3.4400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      6.0000000000000e0, /* Region lower-left latitude */
      1.0400000000000e2, /* Region lower-left longitude */
      1.1000000000000e1, /* Region upper-right latitude */
      1.0900000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_INDIAN_1960_VIETNAM_16_N, /* RT code */
      SRM_ORMCOD_INDIAN_1960, /* ORM code */
      1.9800000000000e2, /* delta x */
      8.8100000000000e2, /* delta y */
      3.1700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.1000000000000e1, /* Region lower-left latitude */
      1.0100000000000e2, /* Region lower-left longitude */
      2.3000000000000e1, /* Region upper-right latitude */
      1.1500000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_INDIAN_1962 */
    {
      SRM_RTCOD_INDIAN_1962_PAKISTAN, /* RT code */
      SRM_ORMCOD_INDIAN_1962, /* ORM code */
      2.8300000000000e2, /* delta x */
      6.8200000000000e2, /* delta y */
      2.3100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.7000000000000e1, /* Region lower-left latitude */
      5.5000000000000e1, /* Region lower-left longitude */
      4.4000000000000e1, /* Region upper-right latitude */
      8.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_INDIAN_1975 */
    {
      SRM_RTCOD_INDIAN_1975_1991_THAILAND, /* RT code */
      SRM_ORMCOD_INDIAN_1975, /* ORM code */
      2.0900000000000e2, /* delta x */
      8.1800000000000e2, /* delta y */
      2.9000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      0.0, /* Region lower-left latitude */
      9.1000000000000e1, /* Region lower-left longitude */
      2.7000000000000e1, /* Region upper-right latitude */
      1.1100000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_INDIAN_1975_1997_THAILAND, /* RT code */
      SRM_ORMCOD_INDIAN_1975, /* ORM code */
      2.1000000000000e2, /* delta x */
      8.1400000000000e2, /* delta y */
      2.8900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      0.0, /* Region lower-left latitude */
      9.1000000000000e1, /* Region lower-left longitude */
      2.7000000000000e1, /* Region upper-right latitude */
      1.1100000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_INDONESIAN_1974 */
    {
      SRM_RTCOD_INDONESIAN_1974_INDONESIA, /* RT code */
      SRM_ORMCOD_INDONESIAN_1974, /* ORM code */
      -2.4000000000000e1, /* delta x */
      -1.5000000000000e1, /* delta y */
      5.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.6000000000000e1, /* Region lower-left latitude */
      8.9000000000000e1, /* Region lower-left longitude */
      1.1000000000000e1, /* Region upper-right latitude */
      1.4600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_IO_2000 */
    {
      SRM_RTCOD_IO_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_IO_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_IRELAND_1965 */
    {
      SRM_RTCOD_IRELAND_1965_3_IRELAND, /* RT code */
      SRM_ORMCOD_IRELAND_1965, /* ORM code */
      5.0600000000000e2, /* delta x */
      -1.2200000000000e2, /* delta y */
      6.1100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.0000000000000e1, /* Region lower-left latitude */
      -1.2000000000000e1, /* Region lower-left longitude */
      5.7000000000000e1, /* Region upper-right latitude */
      -4.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_IRELAND_1965_7_IRELAND, /* RT code */
      SRM_ORMCOD_IRELAND_1965, /* ORM code */
      4.8253000000000e2, /* delta x */
      -1.3059600000000e2, /* delta y */
      5.6455700000000e2, /* delta z */
      -5.0517585571614e-6, /* omega 1 */
      -1.0375012775744e-6, /* omega 2 */
      -3.0591743278012e-6, /* omega 3 */
      8.1500000000000e0, /* delta scale */
      5.0000000000000e1, /* Region lower-left latitude */
      -1.2000000000000e1, /* Region lower-left longitude */
      5.7000000000000e1, /* Region upper-right latitude */
      -4.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ISTS_061_1968 */
    {
      SRM_RTCOD_ISTS_061_1968_SOUTH_GEORGIA_ISLAND, /* RT code */
      SRM_ORMCOD_ISTS_061_1968, /* ORM code */
      -7.9400000000000e2, /* delta x */
      1.1900000000000e2, /* delta y */
      -2.9800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -5.6000000000000e1, /* Region lower-left latitude */
      -3.8000000000000e1, /* Region lower-left longitude */
      -5.2000000000000e1, /* Region upper-right latitude */
      -3.4000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ISTS_073_1969 */
    {
      SRM_RTCOD_ISTS_073_1969_DIEGO_GARCIA, /* RT code */
      SRM_ORMCOD_ISTS_073_1969, /* ORM code */
      2.0800000000000e2, /* delta x */
      -4.3500000000000e2, /* delta y */
      -2.2900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e1, /* Region lower-left latitude */
      6.9000000000000e1, /* Region lower-left longitude */
      -4.0000000000000e0, /* Region upper-right latitude */
      7.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_JANUS_1988 */
    {
      SRM_RTCOD_JANUS_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_JANUS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_JGD_2000 */
    {
      SRM_RTCOD_JGD_2000_IDENTITY_BY_MEASUREMENT, /* RT code */
      SRM_ORMCOD_JGD_2000, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      1.1900000000000e2, /* Region lower-left longitude */
      5.1000000000000e1, /* Region upper-right latitude */
      1.5600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_JOHNSTON_1961 */
    {
      SRM_RTCOD_JOHNSTON_1961_JOHNSTON_ISLAND, /* RT code */
      SRM_ORMCOD_JOHNSTON_1961, /* ORM code */
      1.8900000000000e2, /* delta x */
      -7.9000000000000e1, /* delta y */
      -2.0200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.6000000000000e1, /* Region lower-left latitude */
      -7.6000000000000e1, /* Region lower-left longitude */
      -4.3000000000000e1, /* Region upper-right latitude */
      -7.3000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_JULIET_1988 */
    {
      SRM_RTCOD_JULIET_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_JULIET_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_JUPITER_1988 */
    {
      SRM_RTCOD_JUPITER_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_JUPITER_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_JUPITER_MAGNETIC_1993 */
    {
      SRM_RTCOD_JUPITER_MAGNETIC_1993_VOYAGER, /* RT code */
      SRM_ORMCOD_JUPITER_MAGNETIC_1993, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      4.5572486024296e-5, /* omega 2 */
      -9.7011217590018e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_KANDAWALA_1987 */
    {
      SRM_RTCOD_KANDAWALA_1987_3_SRI_LANKA, /* RT code */
      SRM_ORMCOD_KANDAWALA_1987, /* ORM code */
      -9.7000000000000e1, /* delta x */
      7.8700000000000e2, /* delta y */
      8.6000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.0000000000000e0, /* Region lower-left latitude */
      7.7000000000000e1, /* Region lower-left longitude */
      1.2000000000000e1, /* Region upper-right latitude */
      8.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_KERGUELEN_1949 */
    {
      SRM_RTCOD_KERGUELEN_1949_KERGUELEN_ISLAND, /* RT code */
      SRM_ORMCOD_KERGUELEN_1949, /* ORM code */
      1.4500000000000e2, /* delta x */
      -1.8700000000000e2, /* delta y */
      1.0300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -8.1000000000000e1, /* Region lower-left latitude */
      1.3900000000000e2, /* Region lower-left longitude */
      -7.4000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_KERTAU_1948 */
    {
      SRM_RTCOD_KERTAU_1948_3_W_MALAYSIA_SINGAPORE, /* RT code */
      SRM_ORMCOD_KERTAU_1948, /* ORM code */
      -1.1000000000000e1, /* delta x */
      8.5100000000000e2, /* delta y */
      5.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -5.0000000000000e0, /* Region lower-left latitude */
      9.4000000000000e1, /* Region lower-left longitude */
      1.2000000000000e1, /* Region upper-right latitude */
      1.1200000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_KOREAN_GEODETIC_1995 */
    {
      SRM_RTCOD_KOREAN_GEODETIC_1995_SOUTH_KOREA, /* RT code */
      SRM_ORMCOD_KOREAN_GEODETIC_1995, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.7000000000000e1, /* Region lower-left latitude */
      1.2000000000000e2, /* Region lower-left longitude */
      4.5000000000000e1, /* Region upper-right latitude */
      1.3900000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_KUSAIE_1951 */
    {
      SRM_RTCOD_KUSAIE_1951_CAROLINE_ISLANDS, /* RT code */
      SRM_ORMCOD_KUSAIE_1951, /* ORM code */
      6.4700000000000e2, /* delta x */
      1.7770000000000e3, /* delta y */
      -1.1240000000000e3, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e0, /* Region lower-left latitude */
      1.3400000000000e2, /* Region lower-left longitude */
      1.2000000000000e1, /* Region upper-right latitude */
      1.6700000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_LARISSA_1991 */
    {
      SRM_RTCOD_LARISSA_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_LARISSA_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_LC5_1961 */
    {
      SRM_RTCOD_LC5_1961_CAYMAN_BRAC_ISLAND, /* RT code */
      SRM_ORMCOD_LC5_1961, /* ORM code */
      4.2000000000000e1, /* delta x */
      1.2400000000000e2, /* delta y */
      1.4700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.8000000000000e1, /* Region lower-left latitude */
      -8.1000000000000e1, /* Region lower-left longitude */
      2.1000000000000e1, /* Region upper-right latitude */
      -7.8000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_LEIGON_1991 */
    {
      SRM_RTCOD_LEIGON_1991_3_GHANA, /* RT code */
      SRM_ORMCOD_LEIGON_1991, /* ORM code */
      -1.3000000000000e2, /* delta x */
      2.9000000000000e1, /* delta y */
      3.6400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e0, /* Region lower-left latitude */
      -9.0000000000000e0, /* Region lower-left longitude */
      1.7000000000000e1, /* Region upper-right latitude */
      7.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_LEIGON_1991_7_GHANA, /* RT code */
      SRM_ORMCOD_LEIGON_1991, /* ORM code */
      -1.3558000000000e2, /* delta x */
      1.3230000000000e1, /* delta y */
      3.6413000000000e2, /* delta z */
      9.7777223206171e-6, /* omega 1 */
      -1.2411230236404e-7, /* omega 2 */
      3.9226274938573e-6, /* omega 3 */
      7.1900000000000e-1, /* delta scale */
      -1.0000000000000e0, /* Region lower-left latitude */
      -9.0000000000000e0, /* Region lower-left longitude */
      1.7000000000000e1, /* Region upper-right latitude */
      7.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_LIBERIA_1964 */
    {
      SRM_RTCOD_LIBERIA_1964_LIBERIA, /* RT code */
      SRM_ORMCOD_LIBERIA_1964, /* ORM code */
      -9.0000000000000e1, /* delta x */
      4.0000000000000e1, /* delta y */
      8.8000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e0, /* Region lower-left latitude */
      -1.7000000000000e1, /* Region lower-left longitude */
      1.4000000000000e1, /* Region upper-right latitude */
      -1.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_LUZON_1987 */
    {
      SRM_RTCOD_LUZON_1987_MINDANAO_ISLAND, /* RT code */
      SRM_ORMCOD_LUZON_1987, /* ORM code */
      -1.3300000000000e2, /* delta x */
      -7.9000000000000e1, /* delta y */
      -7.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.0000000000000e0, /* Region lower-left latitude */
      1.2000000000000e2, /* Region lower-left longitude */
      1.2000000000000e1, /* Region upper-right latitude */
      1.2800000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND, /* RT code */
      SRM_ORMCOD_LUZON_1987, /* ORM code */
      -1.3300000000000e2, /* delta x */
      -7.7000000000000e1, /* delta y */
      -5.1000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e0, /* Region lower-left latitude */
      1.1500000000000e2, /* Region lower-left longitude */
      2.3000000000000e1, /* Region upper-right latitude */
      1.2800000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_M_PORALOKO_1991 */
    {
      SRM_RTCOD_M_PORALOKO_1991_GABON, /* RT code */
      SRM_ORMCOD_M_PORALOKO_1991, /* ORM code */
      -7.4000000000000e1, /* delta x */
      -1.3000000000000e2, /* delta y */
      4.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e1, /* Region lower-left latitude */
      3.0000000000000e0, /* Region lower-left longitude */
      8.0000000000000e0, /* Region upper-right latitude */
      2.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MAHE_1971 */
    {
      SRM_RTCOD_MAHE_1971_MAHE_ISLAND, /* RT code */
      SRM_ORMCOD_MAHE_1971, /* ORM code */
      4.1000000000000e1, /* delta x */
      -2.2000000000000e2, /* delta y */
      -1.3400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.0000000000000e0, /* Region lower-left latitude */
      5.4000000000000e1, /* Region lower-left longitude */
      -3.0000000000000e0, /* Region upper-right latitude */
      5.7000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MARCUS_STATION_1952 */
    {
      SRM_RTCOD_MARCUS_STATION_1952_MARCUS_ISLANDS, /* RT code */
      SRM_ORMCOD_MARCUS_STATION_1952, /* ORM code */
      1.2400000000000e2, /* delta x */
      -2.3400000000000e2, /* delta y */
      -2.5000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.2000000000000e1, /* Region lower-left latitude */
      1.5200000000000e2, /* Region lower-left longitude */
      2.6000000000000e1, /* Region upper-right latitude */
      1.5600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MARS_2000 */
    {
      SRM_RTCOD_MARS_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_MARS_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MARS_SPHERE_2000 */
    {
      SRM_RTCOD_MARS_SPHERE_2000_GLOBAL, /* RT code */
      SRM_ORMCOD_MARS_SPHERE_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MASS_1999 */
    {
      SRM_RTCOD_MASS_1999_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_MASS_1999, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MASSAWA_1987 */
    {
      SRM_RTCOD_MASSAWA_1987_ERITREA_ETHIOPIA, /* RT code */
      SRM_ORMCOD_MASSAWA_1987, /* ORM code */
      6.3900000000000e2, /* delta x */
      4.0500000000000e2, /* delta y */
      6.0000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      7.0000000000000e0, /* Region lower-left latitude */
      3.7000000000000e1, /* Region lower-left longitude */
      2.5000000000000e1, /* Region upper-right latitude */
      5.3000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MERCHICH_1987 */
    {
      SRM_RTCOD_MERCHICH_1987_MOROCCO, /* RT code */
      SRM_ORMCOD_MERCHICH_1987, /* ORM code */
      3.1000000000000e1, /* delta x */
      1.4600000000000e2, /* delta y */
      4.7000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.2000000000000e1, /* Region lower-left latitude */
      -1.9000000000000e1, /* Region lower-left longitude */
      4.2000000000000e1, /* Region upper-right latitude */
      5.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MERCURY_1988 */
    {
      SRM_RTCOD_MERCURY_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_MERCURY_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_METIS_2000 */
    {
      SRM_RTCOD_METIS_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_METIS_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MIDWAY_1961 */
    {
      SRM_RTCOD_MIDWAY_1961_MIDWAY_ISLANDS, /* RT code */
      SRM_ORMCOD_MIDWAY_1961, /* ORM code */
      4.0300000000000e2, /* delta x */
      -8.1000000000000e1, /* delta y */
      2.7700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.5000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      3.0000000000000e1, /* Region upper-right latitude */
      -1.6900000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MIMAS_1994 */
    {
      SRM_RTCOD_MIMAS_1994_IDENTITY, /* RT code */
      SRM_ORMCOD_MIMAS_1994, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MINNA_1991 */
    {
      SRM_RTCOD_MINNA_1991_CAMEROON, /* RT code */
      SRM_ORMCOD_MINNA_1991, /* ORM code */
      -8.1000000000000e1, /* delta x */
      -8.4000000000000e1, /* delta y */
      1.1500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.0000000000000e0, /* Region lower-left latitude */
      3.0000000000000e0, /* Region lower-left longitude */
      1.9000000000000e1, /* Region upper-right latitude */
      2.3000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_MINNA_1991_NIGERIA, /* RT code */
      SRM_ORMCOD_MINNA_1991, /* ORM code */
      -9.2000000000000e1, /* delta x */
      -9.3000000000000e1, /* delta y */
      1.2200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e0, /* Region lower-left latitude */
      -4.0000000000000e0, /* Region lower-left longitude */
      2.1000000000000e1, /* Region upper-right latitude */
      2.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MIRANDA_1988 */
    {
      SRM_RTCOD_MIRANDA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_MIRANDA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MM5_1997 */
    {
      SRM_RTCOD_MM5_1997_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_MM5_1997, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989 */
    {
      SRM_RTCOD_MODTRAN_MIDLATITUDE_N_1989_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      3.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      6.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989 */
    {
      SRM_RTCOD_MODTRAN_MIDLATITUDE_S_1989_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -6.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      -3.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989 */
    {
      SRM_RTCOD_MODTRAN_SUBARCTIC_N_1989_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      6.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      7.5000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989 */
    {
      SRM_RTCOD_MODTRAN_SUBARCTIC_S_1989_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -7.5000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      -6.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MODTRAN_TROPICAL_1989 */
    {
      SRM_RTCOD_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_MODTRAN_TROPICAL_1989, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -3.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      3.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MONTSERRAT_1958 */
    {
      SRM_RTCOD_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS, /* RT code */
      SRM_ORMCOD_MONTSERRAT_1958, /* ORM code */
      1.7400000000000e2, /* delta x */
      3.5900000000000e2, /* delta y */
      3.6500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.5000000000000e1, /* Region lower-left latitude */
      -6.4000000000000e1, /* Region lower-left longitude */
      1.8000000000000e1, /* Region upper-right latitude */
      -6.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MOON_1991 */
    {
      SRM_RTCOD_MOON_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_MOON_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989 */
    {
      SRM_RTCOD_MULTIGEN_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_N_AM_1927 */
    {
      SRM_RTCOD_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -5.0000000000000e0, /* delta x */
      1.3500000000000e2, /* delta y */
      1.7200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.7000000000000e1, /* Region lower-left latitude */
      -1.7500000000000e2, /* Region lower-left longitude */
      7.8000000000000e1, /* Region upper-right latitude */
      -1.3000000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_ALBERTA_BRITISH_COLUMBIA, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -7.0000000000000e0, /* delta x */
      1.6200000000000e2, /* delta y */
      1.8800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.3000000000000e1, /* Region lower-left latitude */
      -1.4500000000000e2, /* Region lower-left longitude */
      6.5000000000000e1, /* Region upper-right latitude */
      -1.0500000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -4.0000000000000e0, /* delta x */
      1.5400000000000e2, /* delta y */
      1.7800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      -8.3000000000000e1, /* Region lower-left longitude */
      2.9000000000000e1, /* Region upper-right latitude */
      -7.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_CANADA, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -1.0000000000000e1, /* delta x */
      1.5800000000000e2, /* delta y */
      1.8700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.6000000000000e1, /* Region lower-left latitude */
      -1.5000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      -5.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_CANAL_ZONE, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      0.0, /* delta x */
      1.2500000000000e2, /* delta y */
      2.0100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e0, /* Region lower-left latitude */
      -8.6000000000000e1, /* Region lower-left longitude */
      1.5000000000000e1, /* Region upper-right latitude */
      -7.4000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_CARIBBEAN, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -3.0000000000000e0, /* delta x */
      1.4200000000000e2, /* delta y */
      1.8300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      8.0000000000000e0, /* Region lower-left latitude */
      -8.7000000000000e1, /* Region lower-left longitude */
      2.9000000000000e1, /* Region upper-right latitude */
      -5.8000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_CENTRAL_AMERICA, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      0.0, /* delta x */
      1.2500000000000e2, /* delta y */
      1.9400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.0000000000000e0, /* Region lower-left latitude */
      -9.8000000000000e1, /* Region lower-left longitude */
      2.5000000000000e1, /* Region upper-right latitude */
      -7.7000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_CONTINENTAL_US, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -8.0000000000000e0, /* delta x */
      1.6000000000000e2, /* delta y */
      1.7600000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.5000000000000e1, /* Region lower-left latitude */
      -1.3500000000000e2, /* Region lower-left longitude */
      6.0000000000000e1, /* Region upper-right latitude */
      -6.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_CUBA, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -9.0000000000000e0, /* delta x */
      1.5200000000000e2, /* delta y */
      1.7800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.8000000000000e1, /* Region lower-left latitude */
      -8.7000000000000e1, /* Region lower-left longitude */
      2.5000000000000e1, /* Region upper-right latitude */
      -7.2000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_EAST_ALEUTIAN_ISLANDS, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -2.0000000000000e0, /* delta x */
      1.5200000000000e2, /* delta y */
      1.4900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      5.8000000000000e1, /* Region upper-right latitude */
      -1.6100000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_EASTERN_CANADA, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -2.2000000000000e1, /* delta x */
      1.6000000000000e2, /* delta y */
      1.9000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.8000000000000e1, /* Region lower-left latitude */
      -8.5000000000000e1, /* Region lower-left longitude */
      6.8000000000000e1, /* Region upper-right latitude */
      -4.5000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_EASTERN_US, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -9.0000000000000e0, /* delta x */
      1.6100000000000e2, /* delta y */
      1.7900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.8000000000000e1, /* Region lower-left latitude */
      -1.0200000000000e2, /* Region lower-left longitude */
      5.5000000000000e1, /* Region upper-right latitude */
      -6.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_HAYES_PENINSULA, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      1.1000000000000e1, /* delta x */
      1.1400000000000e2, /* delta y */
      1.9500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      7.4000000000000e1, /* Region lower-left latitude */
      -7.4000000000000e1, /* Region lower-left longitude */
      8.1000000000000e1, /* Region upper-right latitude */
      -5.6000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_MANITOBA_ONTARIO, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -9.0000000000000e0, /* delta x */
      1.5700000000000e2, /* delta y */
      1.8400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.6000000000000e1, /* Region lower-left latitude */
      -1.0800000000000e2, /* Region lower-left longitude */
      6.3000000000000e1, /* Region upper-right latitude */
      -6.9000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_MEXICO, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -1.2000000000000e1, /* delta x */
      1.3000000000000e2, /* delta y */
      1.9000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.0000000000000e1, /* Region lower-left latitude */
      -1.2200000000000e2, /* Region lower-left longitude */
      3.8000000000000e1, /* Region upper-right latitude */
      -8.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      4.0000000000000e0, /* delta x */
      1.5900000000000e2, /* delta y */
      1.8800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.3000000000000e1, /* Region lower-left latitude */
      -1.4400000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      -5.5000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_SAN_SALVADOR_ISLAND, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      1.0000000000000e0, /* delta x */
      1.4000000000000e2, /* delta y */
      1.6500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.3000000000000e1, /* Region lower-left latitude */
      -7.5000000000000e1, /* Region lower-left longitude */
      2.6000000000000e1, /* Region upper-right latitude */
      -7.4000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_WEST_ALEUTIAN_ISLANDS, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      2.0000000000000e0, /* delta x */
      2.0400000000000e2, /* delta y */
      1.0500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.0000000000000e1, /* Region lower-left latitude */
      1.6900000000000e2, /* Region lower-left longitude */
      5.8000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_WESTERN_US, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -8.0000000000000e0, /* delta x */
      1.5900000000000e2, /* delta y */
      1.7500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      -1.3200000000000e2, /* Region lower-left longitude */
      5.5000000000000e1, /* Region upper-right latitude */
      -8.7000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1927_YUKON, /* RT code */
      SRM_ORMCOD_N_AM_1927, /* ORM code */
      -7.0000000000000e0, /* delta x */
      1.3900000000000e2, /* delta y */
      1.8100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.3000000000000e1, /* Region lower-left latitude */
      -1.4700000000000e2, /* Region lower-left longitude */
      7.5000000000000e1, /* Region upper-right latitude */
      -1.1700000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_N_AM_1983 */
    {
      SRM_RTCOD_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS, /* RT code */
      SRM_ORMCOD_N_AM_1983, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.8000000000000e1, /* Region lower-left latitude */
      -1.7500000000000e2, /* Region lower-left longitude */
      7.8000000000000e1, /* Region upper-right latitude */
      -1.3500000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1983_ALEUTIAN_ISLANDS, /* RT code */
      SRM_ORMCOD_N_AM_1983, /* ORM code */
      -2.0000000000000e0, /* delta x */
      0.0, /* delta y */
      4.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.1000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      7.4000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1983_CANADA, /* RT code */
      SRM_ORMCOD_N_AM_1983, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.6000000000000e1, /* Region lower-left latitude */
      -1.5000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      -5.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1983_CONTINENTAL_US, /* RT code */
      SRM_ORMCOD_N_AM_1983, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.5000000000000e1, /* Region lower-left latitude */
      -1.3500000000000e2, /* Region lower-left longitude */
      6.0000000000000e1, /* Region upper-right latitude */
      -6.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1983_HAWAII, /* RT code */
      SRM_ORMCOD_N_AM_1983, /* ORM code */
      1.0000000000000e0, /* delta x */
      1.0000000000000e0, /* delta y */
      -1.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.7000000000000e1, /* Region lower-left latitude */
      -1.6400000000000e2, /* Region lower-left longitude */
      2.4000000000000e1, /* Region upper-right latitude */
      -1.5300000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_N_AM_1983_MEXICO_CENTRAL_AMERICA, /* RT code */
      SRM_ORMCOD_N_AM_1983, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.1000000000000e1, /* Region lower-left latitude */
      -1.2200000000000e2, /* Region lower-left longitude */
      3.5000000000000e1, /* Region upper-right latitude */
      -7.2000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_N_SAHARA_1959 */
    {
      SRM_RTCOD_N_SAHARA_1959_ALGERIA, /* RT code */
      SRM_ORMCOD_N_SAHARA_1959, /* ORM code */
      -1.8600000000000e2, /* delta x */
      -9.3000000000000e1, /* delta y */
      3.1000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.3000000000000e1, /* Region lower-left latitude */
      -1.5000000000000e1, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      1.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_NAHRWAN_1987 */
    {
      SRM_RTCOD_NAHRWAN_1987_MASIRAH_ISLAND, /* RT code */
      SRM_ORMCOD_NAHRWAN_1987, /* ORM code */
      -2.4700000000000e2, /* delta x */
      -1.4800000000000e2, /* delta y */
      3.6900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      5.7000000000000e1, /* Region lower-left longitude */
      2.2000000000000e1, /* Region upper-right latitude */
      6.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_NAHRWAN_1987_SAUDI_ARABIA, /* RT code */
      SRM_ORMCOD_NAHRWAN_1987, /* ORM code */
      -2.4300000000000e2, /* delta x */
      -1.9200000000000e2, /* delta y */
      4.7700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      8.0000000000000e0, /* Region lower-left latitude */
      2.8000000000000e1, /* Region lower-left longitude */
      3.8000000000000e1, /* Region upper-right latitude */
      6.2000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_NAHRWAN_1987_UNITED_ARAB_EMIRATES, /* RT code */
      SRM_ORMCOD_NAHRWAN_1987, /* ORM code */
      -2.4900000000000e2, /* delta x */
      -1.5600000000000e2, /* delta y */
      3.8100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.7000000000000e1, /* Region lower-left latitude */
      4.5000000000000e1, /* Region lower-left longitude */
      3.2000000000000e1, /* Region upper-right latitude */
      6.2000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_NAIAD_1991 */
    {
      SRM_RTCOD_NAIAD_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_NAIAD_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_NAPARIMA_1991 */
    {
      SRM_RTCOD_NAPARIMA_1991_TRINIDAD_TOBAGO, /* RT code */
      SRM_ORMCOD_NAPARIMA_1991, /* ORM code */
      -1.0000000000000e1, /* delta x */
      3.7500000000000e2, /* delta y */
      1.6500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      8.0000000000000e0, /* Region lower-left latitude */
      -6.4000000000000e1, /* Region lower-left longitude */
      1.3000000000000e1, /* Region upper-right latitude */
      -5.9000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_NEPTUNE_1991 */
    {
      SRM_RTCOD_NEPTUNE_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_NEPTUNE_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_NEPTUNE_MAGNETIC_1993 */
    {
      SRM_RTCOD_NEPTUNE_MAGNETIC_1993_VOYAGER, /* RT code */
      SRM_ORMCOD_NEPTUNE_MAGNETIC_1993, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      2.2737761644037e-4, /* omega 2 */
      -3.4906585039887e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_NOGAPS_1988 */
    {
      SRM_RTCOD_NOGAPS_1988_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_NOGAPS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_NTF_1896 */
    {
      SRM_RTCOD_NTF_1896_FRANCE, /* RT code */
      SRM_ORMCOD_NTF_1896, /* ORM code */
      -1.6800000000000e2, /* delta x */
      -6.0000000000000e1, /* delta y */
      3.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.2000000000000e1, /* Region lower-left latitude */
      -6.0000000000000e0, /* Region lower-left longitude */
      5.2000000000000e1, /* Region upper-right latitude */
      1.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_NTF_1896_PM_PARIS */
    {
      SRM_RTCOD_NTF_1896_PM_PARIS_FRANCE, /* RT code */
      SRM_ORMCOD_NTF_1896_PM_PARIS, /* ORM code */
      -1.6800000000000e2, /* delta x */
      -6.0000000000000e1, /* delta y */
      3.2000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      4.0792344331977e-2, /* omega 3 */
      0.0, /* delta scale */
      4.2000000000000e1, /* Region lower-left latitude */
      -8.0000000000000e0, /* Region lower-left longitude */
      5.2000000000000e1, /* Region upper-right latitude */
      8.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_OBERON_1988 */
    {
      SRM_RTCOD_OBERON_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_OBERON_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_OBSERV_METEORO_1939 */
    {
      SRM_RTCOD_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS, /* RT code */
      SRM_ORMCOD_OBSERV_METEORO_1939, /* ORM code */
      -4.2500000000000e2, /* delta x */
      -1.6900000000000e2, /* delta y */
      8.1000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.8000000000000e1, /* Region lower-left latitude */
      -3.3000000000000e1, /* Region lower-left longitude */
      4.1000000000000e1, /* Region upper-right latitude */
      -3.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_OLD_EGYPTIAN_1907 */
    {
      SRM_RTCOD_OLD_EGYPTIAN_1907_EGYPT, /* RT code */
      SRM_ORMCOD_OLD_EGYPTIAN_1907, /* ORM code */
      -1.3000000000000e2, /* delta x */
      1.1000000000000e2, /* delta y */
      -1.3000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.6000000000000e1, /* Region lower-left latitude */
      1.9000000000000e1, /* Region lower-left longitude */
      3.8000000000000e1, /* Region upper-right latitude */
      4.2000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987 */
    {
      SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_HAWAII, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987, /* ORM code */
      8.9000000000000e1, /* delta x */
      -2.7900000000000e2, /* delta y */
      -1.8300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.7000000000000e1, /* Region lower-left latitude */
      -1.5800000000000e2, /* Region lower-left longitude */
      2.2000000000000e1, /* Region upper-right latitude */
      -1.5300000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_KAUAI, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987, /* ORM code */
      4.5000000000000e1, /* delta x */
      -2.9000000000000e2, /* delta y */
      -1.7200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.0000000000000e1, /* Region lower-left latitude */
      -1.6100000000000e2, /* Region lower-left longitude */
      2.4000000000000e1, /* Region upper-right latitude */
      -1.5800000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MAUI, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987, /* ORM code */
      6.5000000000000e1, /* delta x */
      -2.9000000000000e2, /* delta y */
      -1.9000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      -1.5800000000000e2, /* Region lower-left longitude */
      2.3000000000000e1, /* Region upper-right latitude */
      -1.5400000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987, /* ORM code */
      6.1000000000000e1, /* delta x */
      -2.8500000000000e2, /* delta y */
      -1.8100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.7000000000000e1, /* Region lower-left latitude */
      -1.6400000000000e2, /* Region lower-left longitude */
      2.4000000000000e1, /* Region upper-right latitude */
      -1.5300000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_OAHU, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987, /* ORM code */
      5.8000000000000e1, /* delta x */
      -2.8300000000000e2, /* delta y */
      -1.8200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.0000000000000e1, /* Region lower-left latitude */
      -1.6000000000000e2, /* Region lower-left longitude */
      2.3000000000000e1, /* Region upper-right latitude */
      -1.5600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_OLD_HAWAIIAN_INT_1987 */
    {
      SRM_RTCOD_OLD_HAWAIIAN_INT_1987_HAWAII, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_INT_1987, /* ORM code */
      2.2900000000000e2, /* delta x */
      -2.2200000000000e2, /* delta y */
      -3.4800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.7000000000000e1, /* Region lower-left latitude */
      -1.5800000000000e2, /* Region lower-left longitude */
      2.2000000000000e1, /* Region upper-right latitude */
      -1.5300000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OLD_HAWAIIAN_INT_1987_KAUAI, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_INT_1987, /* ORM code */
      1.8500000000000e2, /* delta x */
      -2.3300000000000e2, /* delta y */
      -3.3700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.0000000000000e1, /* Region lower-left latitude */
      -1.6100000000000e2, /* Region lower-left longitude */
      2.4000000000000e1, /* Region upper-right latitude */
      -1.5800000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MAUI, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_INT_1987, /* ORM code */
      2.0500000000000e2, /* delta x */
      -2.3300000000000e2, /* delta y */
      -3.5500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      -1.5800000000000e2, /* Region lower-left longitude */
      2.3000000000000e1, /* Region upper-right latitude */
      -1.5400000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_INT_1987, /* ORM code */
      2.0100000000000e2, /* delta x */
      -2.2800000000000e2, /* delta y */
      -3.4600000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.7000000000000e1, /* Region lower-left latitude */
      -1.6400000000000e2, /* Region lower-left longitude */
      2.4000000000000e1, /* Region upper-right latitude */
      -1.5300000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OLD_HAWAIIAN_INT_1987_OAHU, /* RT code */
      SRM_ORMCOD_OLD_HAWAIIAN_INT_1987, /* ORM code */
      1.9800000000000e2, /* delta x */
      -2.2600000000000e2, /* delta y */
      -3.4700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.0000000000000e1, /* Region lower-left latitude */
      -1.6000000000000e2, /* Region lower-left longitude */
      2.3000000000000e1, /* Region upper-right latitude */
      -1.5600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_OPHELIA_1988 */
    {
      SRM_RTCOD_OPHELIA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_OPHELIA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_OSGB_1936 */
    {
      SRM_RTCOD_OSGB_1936_3_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_OSGB_1936, /* ORM code */
      3.7500000000000e2, /* delta x */
      -1.1100000000000e2, /* delta y */
      4.3100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.4000000000000e1, /* Region lower-left latitude */
      -1.4000000000000e1, /* Region lower-left longitude */
      6.6000000000000e1, /* Region upper-right latitude */
      7.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OSGB_1936_7_GREAT_BRITAIN, /* RT code */
      SRM_ORMCOD_OSGB_1936, /* ORM code */
      4.4644800000000e2, /* delta x */
      -1.2515700000000e2, /* delta y */
      5.4206000000000e2, /* delta z */
      7.2722052166430e-7, /* omega 1 */
      1.1974897923406e-6, /* omega 2 */
      4.0826160086234e-6, /* omega 3 */
      -2.0490000000000e1, /* delta scale */
      4.9000000000000e1, /* Region lower-left latitude */
      -9.0000000000000e0, /* Region lower-left longitude */
      6.0000000000000e1, /* Region upper-right latitude */
      3.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OSGB_1936_ENGLAND, /* RT code */
      SRM_ORMCOD_OSGB_1936, /* ORM code */
      3.7100000000000e2, /* delta x */
      -1.1200000000000e2, /* delta y */
      4.3400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.4000000000000e1, /* Region lower-left latitude */
      -1.2000000000000e1, /* Region lower-left longitude */
      6.1000000000000e1, /* Region upper-right latitude */
      7.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES, /* RT code */
      SRM_ORMCOD_OSGB_1936, /* ORM code */
      3.7100000000000e2, /* delta x */
      -1.1100000000000e2, /* delta y */
      4.3400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.4000000000000e1, /* Region lower-left latitude */
      -1.2000000000000e1, /* Region lower-left longitude */
      6.1000000000000e1, /* Region upper-right latitude */
      7.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS, /* RT code */
      SRM_ORMCOD_OSGB_1936, /* ORM code */
      3.8400000000000e2, /* delta x */
      -1.1100000000000e2, /* delta y */
      4.2500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.9000000000000e1, /* Region lower-left latitude */
      -1.4000000000000e1, /* Region lower-left longitude */
      6.6000000000000e1, /* Region upper-right latitude */
      4.0000000000000e0 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_OSGB_1936_WALES, /* RT code */
      SRM_ORMCOD_OSGB_1936, /* ORM code */
      3.7000000000000e2, /* delta x */
      -1.0800000000000e2, /* delta y */
      4.3400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.6000000000000e1, /* Region lower-left latitude */
      -1.1000000000000e1, /* Region lower-left longitude */
      5.9000000000000e1, /* Region upper-right latitude */
      3.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PAN_1991 */
    {
      SRM_RTCOD_PAN_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_PAN_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PANDORA_1988 */
    {
      SRM_RTCOD_PANDORA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_PANDORA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PHOBOS_1988 */
    {
      SRM_RTCOD_PHOBOS_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_PHOBOS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PHOEBE_1988 */
    {
      SRM_RTCOD_PHOEBE_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_PHOEBE_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987 */
    {
      SRM_RTCOD_PICO_DE_LAS_NIEVES_1987_CANARY_ISLANDS, /* RT code */
      SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987, /* ORM code */
      -3.0700000000000e2, /* delta x */
      -9.2000000000000e1, /* delta y */
      1.2700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.6000000000000e1, /* Region lower-left latitude */
      -2.0000000000000e1, /* Region lower-left longitude */
      3.1000000000000e1, /* Region upper-right latitude */
      -1.2000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PITCAIRN_1967 */
    {
      SRM_RTCOD_PITCAIRN_1967_PITCAIRN_ISLAND, /* RT code */
      SRM_ORMCOD_PITCAIRN_1967, /* ORM code */
      1.8500000000000e2, /* delta x */
      1.6500000000000e2, /* delta y */
      4.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.7000000000000e1, /* Region lower-left latitude */
      -1.3400000000000e2, /* Region lower-left longitude */
      -2.1000000000000e1, /* Region upper-right latitude */
      -1.1900000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PLUTO_1994 */
    {
      SRM_RTCOD_PLUTO_1994_IDENTITY, /* RT code */
      SRM_ORMCOD_PLUTO_1994, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_POINT_58_1991 */
    {
      SRM_RTCOD_POINT_58_1991_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_POINT_58_1991, /* ORM code */
      -1.0600000000000e2, /* delta x */
      -1.2900000000000e2, /* delta y */
      1.6500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      0.0, /* Region lower-left latitude */
      -1.5000000000000e1, /* Region lower-left longitude */
      1.0000000000000e1, /* Region upper-right latitude */
      2.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_POINTE_NOIRE_1948 */
    {
      SRM_RTCOD_POINTE_NOIRE_1948_CONGO, /* RT code */
      SRM_ORMCOD_POINTE_NOIRE_1948, /* ORM code */
      -1.4800000000000e2, /* delta x */
      5.1000000000000e1, /* delta y */
      -2.9100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.1000000000000e1, /* Region lower-left latitude */
      5.0000000000000e0, /* Region lower-left longitude */
      1.0000000000000e1, /* Region upper-right latitude */
      2.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PORTIA_1988 */
    {
      SRM_RTCOD_PORTIA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_PORTIA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PORTO_SANTO_1936 */
    {
      SRM_RTCOD_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS, /* RT code */
      SRM_ORMCOD_PORTO_SANTO_1936, /* ORM code */
      -4.9900000000000e2, /* delta x */
      -2.4900000000000e2, /* delta y */
      3.1400000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.1000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e1, /* Region lower-left longitude */
      3.5000000000000e1, /* Region upper-right latitude */
      -1.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PROMETHEUS_1988 */
    {
      SRM_RTCOD_PROMETHEUS_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_PROMETHEUS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PROTEUS_1991 */
    {
      SRM_RTCOD_PROTEUS_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_PROTEUS_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PROV_S_AM_1956 */
    {
      SRM_RTCOD_PROV_S_AM_1956_3_VENEZUELA, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -2.9500000000000e2, /* delta x */
      1.7300000000000e2, /* delta y */
      -3.7100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -5.0000000000000e0, /* Region lower-left latitude */
      -7.9000000000000e1, /* Region lower-left longitude */
      1.8000000000000e1, /* Region upper-right latitude */
      -5.4000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_7_VENEZUELA, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -1.9743000000000e2, /* delta x */
      1.3939000000000e2, /* delta y */
      -1.9280000000000e2, /* delta z */
      2.5530288447228e-5, /* omega 1 */
      6.0019933721361e-6, /* omega 2 */
      -1.1543413747218e-5, /* omega 3 */
      -5.1090000000000e0, /* delta scale */
      -5.0000000000000e0, /* Region lower-left latitude */
      -7.9000000000000e1, /* Region lower-left longitude */
      1.8000000000000e1, /* Region upper-right latitude */
      -5.4000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_BOLIVIA, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -2.7000000000000e2, /* delta x */
      1.8800000000000e2, /* delta y */
      -3.8800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.8000000000000e1, /* Region lower-left latitude */
      -7.5000000000000e1, /* Region lower-left longitude */
      -4.0000000000000e0, /* Region upper-right latitude */
      -5.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_COLOMBIA, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -2.8200000000000e2, /* delta x */
      1.6900000000000e2, /* delta y */
      -3.7100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e1, /* Region lower-left latitude */
      -8.5000000000000e1, /* Region lower-left longitude */
      1.6000000000000e1, /* Region upper-right latitude */
      -6.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_ECUADOR, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -2.7800000000000e2, /* delta x */
      1.7100000000000e2, /* delta y */
      -3.6700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.1000000000000e1, /* Region lower-left latitude */
      -8.5000000000000e1, /* Region lower-left longitude */
      7.0000000000000e0, /* Region upper-right latitude */
      -7.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_GUYANA, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -2.9800000000000e2, /* delta x */
      1.5900000000000e2, /* delta y */
      -3.6900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.0000000000000e0, /* Region lower-left latitude */
      -6.7000000000000e1, /* Region lower-left longitude */
      1.4000000000000e1, /* Region upper-right latitude */
      -5.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -2.8800000000000e2, /* delta x */
      1.7500000000000e2, /* delta y */
      -3.7600000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.4000000000000e1, /* Region lower-left latitude */
      -8.7000000000000e1, /* Region lower-left longitude */
      1.8000000000000e1, /* Region upper-right latitude */
      -5.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_N_CHILE_19_S, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -2.7000000000000e2, /* delta x */
      1.8300000000000e2, /* delta y */
      -3.9000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.5000000000000e1, /* Region lower-left latitude */
      -8.3000000000000e1, /* Region lower-left longitude */
      -1.2000000000000e1, /* Region upper-right latitude */
      -6.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_PERU, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -2.7900000000000e2, /* delta x */
      1.7500000000000e2, /* delta y */
      -3.7900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.4000000000000e1, /* Region lower-left latitude */
      -8.7000000000000e1, /* Region lower-left longitude */
      5.0000000000000e0, /* Region upper-right latitude */
      -6.3000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_PROV_S_AM_1956_S_CHILE_43_S, /* RT code */
      SRM_ORMCOD_PROV_S_AM_1956, /* ORM code */
      -3.0500000000000e2, /* delta x */
      2.4300000000000e2, /* delta y */
      -4.4200000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.4000000000000e1, /* Region lower-left latitude */
      -8.3000000000000e1, /* Region lower-left longitude */
      -2.0000000000000e1, /* Region upper-right latitude */
      -6.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PROV_S_CHILEAN_1963 */
    {
      SRM_RTCOD_PROV_S_CHILEAN_1963_SOUTH_CHILE, /* RT code */
      SRM_ORMCOD_PROV_S_CHILEAN_1963, /* ORM code */
      1.6000000000000e1, /* delta x */
      1.9600000000000e2, /* delta y */
      9.3000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.4000000000000e1, /* Region lower-left latitude */
      -8.3000000000000e1, /* Region lower-left longitude */
      -2.5000000000000e1, /* Region upper-right latitude */
      -6.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PUCK_1988 */
    {
      SRM_RTCOD_PUCK_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_PUCK_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PUERTO_RICO_1987 */
    {
      SRM_RTCOD_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS, /* RT code */
      SRM_ORMCOD_PUERTO_RICO_1987, /* ORM code */
      1.1000000000000e1, /* delta x */
      7.2000000000000e1, /* delta y */
      -1.0100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.6000000000000e1, /* Region lower-left latitude */
      -6.9000000000000e1, /* Region lower-left longitude */
      2.0000000000000e1, /* Region upper-right latitude */
      -6.3000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_PULKOVO_1942 */
    {
      SRM_RTCOD_PULKOVO_1942_RUSSIA, /* RT code */
      SRM_ORMCOD_PULKOVO_1942, /* ORM code */
      2.8000000000000e1, /* delta x */
      -1.3000000000000e2, /* delta y */
      -9.5000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.6000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      8.9000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_QATAR_NATIONAL_1974 */
    {
      SRM_RTCOD_QATAR_NATIONAL_1974_3_QATAR, /* RT code */
      SRM_ORMCOD_QATAR_NATIONAL_1974, /* ORM code */
      -1.2800000000000e2, /* delta x */
      -2.8300000000000e2, /* delta y */
      2.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      4.5000000000000e1, /* Region lower-left longitude */
      3.2000000000000e1, /* Region upper-right latitude */
      5.7000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_QORNOQ_1987 */
    {
      SRM_RTCOD_QORNOQ_1987_SOUTH_GREENLAND, /* RT code */
      SRM_ORMCOD_QORNOQ_1987, /* ORM code */
      1.6400000000000e2, /* delta x */
      1.3800000000000e2, /* delta y */
      -1.8900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.7000000000000e1, /* Region lower-left latitude */
      -7.7000000000000e1, /* Region lower-left longitude */
      8.5000000000000e1, /* Region upper-right latitude */
      -7.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_REUNION_1947 */
    {
      SRM_RTCOD_REUNION_1947_MASCARENE_ISLANDS, /* RT code */
      SRM_ORMCOD_REUNION_1947, /* ORM code */
      9.4000000000000e1, /* delta x */
      -9.4800000000000e2, /* delta y */
      -1.2620000000000e3, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.7000000000000e1, /* Region lower-left latitude */
      4.7000000000000e1, /* Region lower-left longitude */
      -1.2000000000000e1, /* Region upper-right latitude */
      6.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_RGF_1993 */
    {
      SRM_RTCOD_RGF_1993_IDENTITY_BY_MEASUREMENT, /* RT code */
      SRM_ORMCOD_RGF_1993, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.2000000000000e1, /* Region lower-left latitude */
      -6.0000000000000e0, /* Region lower-left longitude */
      5.2000000000000e1, /* Region upper-right latitude */
      1.0000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_RHEA_1988 */
    {
      SRM_RTCOD_RHEA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_RHEA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ROME_1940_PM_ROME */
    {
      SRM_RTCOD_ROME_1940_PM_ROME_SARDINIA, /* RT code */
      SRM_ORMCOD_ROME_1940_PM_ROME, /* ORM code */
      -2.2500000000000e2, /* delta x */
      -6.5000000000000e1, /* delta y */
      9.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      2.1733421622251e-1, /* omega 3 */
      0.0, /* delta scale */
      3.7000000000000e1, /* Region lower-left latitude */
      -8.0000000000000e0, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      8.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ROME_1940 */
    {
      SRM_RTCOD_ROME_1940_SARDINIA, /* RT code */
      SRM_ORMCOD_ROME_1940, /* ORM code */
      -2.2500000000000e2, /* delta x */
      -6.5000000000000e1, /* delta y */
      9.0000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.7000000000000e1, /* Region lower-left latitude */
      6.0000000000000e0, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      1.2000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ROSALIND_1988 */
    {
      SRM_RTCOD_ROSALIND_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_ROSALIND_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_S_AM_1969 */
    {
      SRM_RTCOD_S_AM_1969_ARGENTINA, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -6.2000000000000e1, /* delta x */
      -1.0000000000000e0, /* delta y */
      -3.7000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.2000000000000e1, /* Region lower-left latitude */
      -7.6000000000000e1, /* Region lower-left longitude */
      -2.3000000000000e1, /* Region upper-right latitude */
      -4.7000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -4.7000000000000e1, /* delta x */
      2.6000000000000e1, /* delta y */
      -4.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.0000000000000e0, /* Region lower-left latitude */
      -9.2000000000000e1, /* Region lower-left longitude */
      1.0000000000000e0, /* Region upper-right latitude */
      -8.9000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_BOLIVIA, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -6.1000000000000e1, /* delta x */
      2.0000000000000e0, /* delta y */
      -4.8000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.8000000000000e1, /* Region lower-left latitude */
      -7.5000000000000e1, /* Region lower-left longitude */
      -4.0000000000000e0, /* Region upper-right latitude */
      -5.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_BRAZIL, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -6.0000000000000e1, /* delta x */
      -2.0000000000000e0, /* delta y */
      -4.1000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.9000000000000e1, /* Region lower-left latitude */
      -8.0000000000000e1, /* Region lower-left longitude */
      -2.0000000000000e0, /* Region upper-right latitude */
      -2.9000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_CHILE, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -7.5000000000000e1, /* delta x */
      -1.0000000000000e0, /* delta y */
      -4.4000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.4000000000000e1, /* Region lower-left latitude */
      -8.3000000000000e1, /* Region lower-left longitude */
      -1.2000000000000e1, /* Region upper-right latitude */
      -6.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_COLOMBIA, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -4.4000000000000e1, /* delta x */
      6.0000000000000e0, /* delta y */
      -3.6000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e1, /* Region lower-left latitude */
      -8.5000000000000e1, /* Region lower-left longitude */
      1.6000000000000e1, /* Region upper-right latitude */
      -6.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -4.8000000000000e1, /* delta x */
      3.0000000000000e0, /* delta y */
      -4.4000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.1000000000000e1, /* Region lower-left latitude */
      -8.5000000000000e1, /* Region lower-left longitude */
      7.0000000000000e0, /* Region upper-right latitude */
      -7.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_GUYANA, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -5.3000000000000e1, /* delta x */
      3.0000000000000e0, /* delta y */
      -4.7000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.0000000000000e0, /* Region lower-left latitude */
      -6.7000000000000e1, /* Region lower-left longitude */
      1.4000000000000e1, /* Region upper-right latitude */
      -5.1000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -5.7000000000000e1, /* delta x */
      1.0000000000000e0, /* delta y */
      -4.1000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.5000000000000e1, /* Region lower-left latitude */
      -9.0000000000000e1, /* Region lower-left longitude */
      -5.0000000000000e1, /* Region upper-right latitude */
      -2.5000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_PARAGUAY, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -6.1000000000000e1, /* delta x */
      2.0000000000000e0, /* delta y */
      -3.3000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.3000000000000e1, /* Region lower-left latitude */
      -6.9000000000000e1, /* Region lower-left longitude */
      -1.4000000000000e1, /* Region upper-right latitude */
      -4.9000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_PERU, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -5.8000000000000e1, /* delta x */
      0.0, /* delta y */
      -4.4000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.4000000000000e1, /* Region lower-left latitude */
      -8.7000000000000e1, /* Region lower-left longitude */
      5.0000000000000e0, /* Region upper-right latitude */
      -6.3000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_TRINIDAD_TOBAGO, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -4.5000000000000e1, /* delta x */
      1.2000000000000e1, /* delta y */
      -3.3000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.0000000000000e0, /* Region lower-left latitude */
      -6.8000000000000e1, /* Region lower-left longitude */
      1.7000000000000e1, /* Region upper-right latitude */
      -5.5000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_AM_1969_VENEZUELA, /* RT code */
      SRM_ORMCOD_S_AM_1969, /* ORM code */
      -4.5000000000000e1, /* delta x */
      8.0000000000000e0, /* delta y */
      -3.3000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -5.0000000000000e0, /* Region lower-left latitude */
      -7.9000000000000e1, /* Region lower-left longitude */
      1.8000000000000e1, /* Region upper-right latitude */
      -5.4000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_S_ASIA_1987 */
    {
      SRM_RTCOD_S_ASIA_1987_SINGAPORE, /* RT code */
      SRM_ORMCOD_S_ASIA_1987, /* ORM code */
      7.0000000000000e0, /* delta x */
      -1.0000000000000e1, /* delta y */
      -2.6000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      0.0, /* Region lower-left latitude */
      1.0200000000000e2, /* Region lower-left longitude */
      3.0000000000000e0, /* Region upper-right latitude */
      1.0600000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_S_JTSK_1993 */
    {
      SRM_RTCOD_S_JTSK_1993_CZECH_REP, /* RT code */
      SRM_ORMCOD_S_JTSK_1993, /* ORM code */
      5.7080000000000e2, /* delta x */
      8.5700000000000e1, /* delta y */
      4.6280000000000e2, /* delta z */
      2.4230987781855e-5, /* omega 1 */
      7.6939931192083e-6, /* omega 2 */
      2.5506047763173e-5, /* omega 3 */
      3.5600000000000e0, /* delta scale */
      4.7000000000000e1, /* Region lower-left latitude */
      1.1000000000000e1, /* Region lower-left longitude */
      5.2000000000000e1, /* Region upper-right latitude */
      2.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S_JTSK_1993_CZECH_REP_SLOVAKIA, /* RT code */
      SRM_ORMCOD_S_JTSK_1993, /* ORM code */
      5.8900000000000e2, /* delta x */
      7.6000000000000e1, /* delta y */
      4.8000000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.3000000000000e1, /* Region lower-left latitude */
      6.0000000000000e0, /* Region lower-left longitude */
      5.6000000000000e1, /* Region upper-right latitude */
      2.8000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_S42_PULKOVO */
    {
      SRM_RTCOD_S42_PULKOVO_3_POLAND, /* RT code */
      SRM_ORMCOD_S42_PULKOVO, /* ORM code */
      2.3000000000000e1, /* delta x */
      -1.2400000000000e2, /* delta y */
      -8.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.3000000000000e1, /* Region lower-left latitude */
      8.0000000000000e0, /* Region lower-left longitude */
      6.0000000000000e1, /* Region upper-right latitude */
      3.0000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S42_PULKOVO_ALBANIA, /* RT code */
      SRM_ORMCOD_S42_PULKOVO, /* ORM code */
      2.4000000000000e1, /* delta x */
      -1.3000000000000e2, /* delta y */
      -9.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.4000000000000e1, /* Region lower-left latitude */
      1.4000000000000e1, /* Region lower-left longitude */
      4.8000000000000e1, /* Region upper-right latitude */
      2.6000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA, /* RT code */
      SRM_ORMCOD_S42_PULKOVO, /* ORM code */
      2.6000000000000e1, /* delta x */
      -1.2100000000000e2, /* delta y */
      -7.8000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.2000000000000e1, /* Region lower-left latitude */
      6.0000000000000e0, /* Region lower-left longitude */
      5.7000000000000e1, /* Region upper-right latitude */
      2.8000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S42_PULKOVO_G_ROMANIA, /* RT code */
      SRM_ORMCOD_S42_PULKOVO, /* ORM code */
      2.8000000000000e1, /* delta x */
      -1.2100000000000e2, /* delta y */
      -7.7000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.8000000000000e1, /* Region lower-left latitude */
      1.5000000000000e1, /* Region lower-left longitude */
      5.4000000000000e1, /* Region upper-right latitude */
      3.5000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S42_PULKOVO_HUNGARY, /* RT code */
      SRM_ORMCOD_S42_PULKOVO, /* ORM code */
      2.8000000000000e1, /* delta x */
      -1.2100000000000e2, /* delta y */
      -7.7000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      4.0000000000000e1, /* Region lower-left latitude */
      1.1000000000000e1, /* Region lower-left longitude */
      5.4000000000000e1, /* Region upper-right latitude */
      2.9000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S42_PULKOVO_KAZAKHSTAN, /* RT code */
      SRM_ORMCOD_S42_PULKOVO, /* ORM code */
      1.5000000000000e1, /* delta x */
      -1.3000000000000e2, /* delta y */
      -8.4000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.5000000000000e1, /* Region lower-left latitude */
      4.1000000000000e1, /* Region lower-left longitude */
      6.2000000000000e1, /* Region upper-right latitude */
      9.3000000000000e1 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_S42_PULKOVO_LATVIA, /* RT code */
      SRM_ORMCOD_S42_PULKOVO, /* ORM code */
      2.4000000000000e1, /* delta x */
      -1.2400000000000e2, /* delta y */
      -8.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      5.0000000000000e1, /* Region lower-left latitude */
      1.5000000000000e1, /* Region lower-left longitude */
      6.4000000000000e1, /* Region upper-right latitude */
      3.4000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SANTO_DOS_1965 */
    {
      SRM_RTCOD_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND, /* RT code */
      SRM_ORMCOD_SANTO_DOS_1965, /* ORM code */
      1.7000000000000e2, /* delta x */
      4.2000000000000e1, /* delta y */
      8.4000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.7000000000000e1, /* Region lower-left latitude */
      1.6000000000000e2, /* Region lower-left longitude */
      -1.3000000000000e1, /* Region upper-right latitude */
      1.6900000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SAO_BRAZ_1987 */
    {
      SRM_RTCOD_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS, /* RT code */
      SRM_ORMCOD_SAO_BRAZ_1987, /* ORM code */
      -2.0300000000000e2, /* delta x */
      1.4100000000000e2, /* delta y */
      5.3000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      3.5000000000000e1, /* Region lower-left latitude */
      -2.7000000000000e1, /* Region lower-left longitude */
      3.9000000000000e1, /* Region upper-right latitude */
      -2.3000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SAPPER_HILL_1943 */
    {
      SRM_RTCOD_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS, /* RT code */
      SRM_ORMCOD_SAPPER_HILL_1943, /* ORM code */
      -3.5500000000000e2, /* delta x */
      2.1000000000000e1, /* delta y */
      7.2000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -5.4000000000000e1, /* Region lower-left latitude */
      -6.1000000000000e1, /* Region lower-left longitude */
      -5.0000000000000e1, /* Region upper-right latitude */
      -5.6000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SATURN_1988 */
    {
      SRM_RTCOD_SATURN_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_SATURN_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SATURN_MAGNETIC_1993 */
    {
      SRM_RTCOD_SATURN_MAGNETIC_1993_VOYAGER, /* RT code */
      SRM_ORMCOD_SATURN_MAGNETIC_1993, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SCHWARZECK_1991 */
    {
      SRM_RTCOD_SCHWARZECK_1991_NAMIBIA, /* RT code */
      SRM_ORMCOD_SCHWARZECK_1991, /* ORM code */
      6.1600000000000e2, /* delta x */
      9.7000000000000e1, /* delta y */
      -2.5100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.5000000000000e1, /* Region lower-left latitude */
      5.0000000000000e0, /* Region lower-left longitude */
      -1.1000000000000e1, /* Region upper-right latitude */
      3.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SELVAGEM_GRANDE_1938 */
    {
      SRM_RTCOD_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS, /* RT code */
      SRM_ORMCOD_SELVAGEM_GRANDE_1938, /* ORM code */
      -2.8900000000000e2, /* delta x */
      -1.2400000000000e2, /* delta y */
      6.0000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.8000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e1, /* Region lower-left longitude */
      3.2000000000000e1, /* Region upper-right latitude */
      -1.4000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SIERRA_LEONE_1960 */
    {
      SRM_RTCOD_SIERRA_LEONE_1960_SIERRA_LEONE, /* RT code */
      SRM_ORMCOD_SIERRA_LEONE_1960, /* ORM code */
      -8.8000000000000e1, /* delta x */
      4.0000000000000e0, /* delta y */
      1.0100000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.0000000000000e0, /* Region lower-left latitude */
      -1.9000000000000e1, /* Region lower-left longitude */
      1.6000000000000e1, /* Region upper-right latitude */
      -4.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SIRGAS_2000 */
    {
      SRM_RTCOD_SIRGAS_2000_IDENTITY_BY_MEASUREMENT, /* RT code */
      SRM_ORMCOD_SIRGAS_2000, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -6.5000000000000e1, /* Region lower-left latitude */
      -9.0000000000000e1, /* Region lower-left longitude */
      -5.0000000000000e1, /* Region upper-right latitude */
      -2.5000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_SUN_1992 */
    {
      SRM_RTCOD_SUN_1992_IDENTITY, /* RT code */
      SRM_ORMCOD_SUN_1992, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TANANARIVE_OBS_1925 */
    {
      SRM_RTCOD_TANANARIVE_OBS_1925_3_MADAGASCAR, /* RT code */
      SRM_ORMCOD_TANANARIVE_OBS_1925, /* ORM code */
      -1.8900000000000e2, /* delta x */
      -2.4200000000000e2, /* delta y */
      -9.1000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.4000000000000e1, /* Region lower-left latitude */
      4.0000000000000e1, /* Region lower-left longitude */
      -8.0000000000000e0, /* Region upper-right latitude */
      5.3000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS */
    {
      SRM_RTCOD_TANANARIVE_OBS_1925_PM_PARIS_3_MADAGASCAR, /* RT code */
      SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS, /* ORM code */
      -1.8900000000000e2, /* delta x */
      -2.4200000000000e2, /* delta y */
      -9.1000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      4.0792344331977e-2, /* omega 3 */
      0.0, /* delta scale */
      -3.4000000000000e1, /* Region lower-left latitude */
      3.8000000000000e1, /* Region lower-left longitude */
      -8.0000000000000e0, /* Region upper-right latitude */
      5.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TELESTO_1988 */
    {
      SRM_RTCOD_TELESTO_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_TELESTO_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TERN_1961 */
    {
      SRM_RTCOD_TERN_1961_TERN_ISLAND, /* RT code */
      SRM_ORMCOD_TERN_1961, /* ORM code */
      1.1400000000000e2, /* delta x */
      -1.1600000000000e2, /* delta y */
      -3.3300000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.2000000000000e1, /* Region lower-left latitude */
      -1.6700000000000e2, /* Region lower-left longitude */
      2.6000000000000e1, /* Region upper-right latitude */
      -1.6500000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TETHYS_1991 */
    {
      SRM_RTCOD_TETHYS_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_TETHYS_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_THALASSA_1991 */
    {
      SRM_RTCOD_THALASSA_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_THALASSA_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_THEBE_2000 */
    {
      SRM_RTCOD_THEBE_2000_IDENTITY, /* RT code */
      SRM_ORMCOD_THEBE_2000, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TIMBALAI_EVEREST_1948 */
    {
      SRM_RTCOD_TIMBALAI_EVEREST_1948_3_BRUNEI_E_MALAYSIA, /* RT code */
      SRM_ORMCOD_TIMBALAI_EVEREST_1948, /* ORM code */
      -6.7900000000000e2, /* delta x */
      6.6900000000000e2, /* delta y */
      -4.8000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -5.0000000000000e0, /* Region lower-left latitude */
      1.0100000000000e2, /* Region lower-left longitude */
      1.5000000000000e1, /* Region upper-right latitude */
      1.2500000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_TIMBALAI_EVEREST_1948_7_BRUNEI_E_MALAYSIA, /* RT code */
      SRM_ORMCOD_TIMBALAI_EVEREST_1948, /* ORM code */
      -5.8233000000000e2, /* delta x */
      6.7157000000000e2, /* delta y */
      -1.0815000000000e2, /* delta z */
      8.4551505985503e-6, /* omega 1 */
      2.7149566142134e-6, /* omega 2 */
      1.3943241468710e-5, /* omega 3 */
      6.4950000000000e0, /* delta scale */
      -5.0000000000000e0, /* Region lower-left latitude */
      1.0100000000000e2, /* Region lower-left longitude */
      1.5000000000000e1, /* Region upper-right latitude */
      1.2500000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TITAN_1982 */
    {
      SRM_RTCOD_TITAN_1982_IDENTITY, /* RT code */
      SRM_ORMCOD_TITAN_1982, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TITANIA_1988 */
    {
      SRM_RTCOD_TITANIA_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_TITANIA_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TOKYO_1991 */
    {
      SRM_RTCOD_TOKYO_1991_JAPAN, /* RT code */
      SRM_ORMCOD_TOKYO_1991, /* ORM code */
      -1.4800000000000e2, /* delta x */
      5.0700000000000e2, /* delta y */
      6.8500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      1.1900000000000e2, /* Region lower-left longitude */
      5.1000000000000e1, /* Region upper-right latitude */
      1.5600000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_TOKYO_1991_MEAN_SOLUTION, /* RT code */
      SRM_ORMCOD_TOKYO_1991, /* ORM code */
      -1.4800000000000e2, /* delta x */
      5.0700000000000e2, /* delta y */
      6.8500000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.3000000000000e1, /* Region lower-left latitude */
      1.2000000000000e2, /* Region lower-left longitude */
      5.3000000000000e1, /* Region upper-right latitude */
      1.5500000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_TOKYO_1991_OKINAWA, /* RT code */
      SRM_ORMCOD_TOKYO_1991, /* ORM code */
      -1.5800000000000e2, /* delta x */
      5.0700000000000e2, /* delta y */
      6.7600000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.9000000000000e1, /* Region lower-left latitude */
      1.1900000000000e2, /* Region lower-left longitude */
      3.1000000000000e1, /* Region upper-right latitude */
      1.3400000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_TOKYO_1991_1991_SOUTH_KOREA, /* RT code */
      SRM_ORMCOD_TOKYO_1991, /* ORM code */
      -1.4600000000000e2, /* delta x */
      5.0700000000000e2, /* delta y */
      6.8700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.7000000000000e1, /* Region lower-left latitude */
      1.2000000000000e2, /* Region lower-left longitude */
      4.5000000000000e1, /* Region upper-right latitude */
      1.3900000000000e2 /* Region upper-right longitude */
    },

    {
      SRM_RTCOD_TOKYO_1991_1997_SOUTH_KOREA, /* RT code */
      SRM_ORMCOD_TOKYO_1991, /* ORM code */
      -1.4700000000000e2, /* delta x */
      5.0600000000000e2, /* delta y */
      6.8700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      2.7000000000000e1, /* Region lower-left latitude */
      1.2000000000000e2, /* Region lower-left longitude */
      4.5000000000000e1, /* Region upper-right latitude */
      1.3900000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TRISTAN_1968 */
    {
      SRM_RTCOD_TRISTAN_1968_TRISTAN_DA_CUNHA, /* RT code */
      SRM_ORMCOD_TRISTAN_1968, /* ORM code */
      -6.3200000000000e2, /* delta x */
      4.3800000000000e2, /* delta y */
      -6.0900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -3.9000000000000e1, /* Region lower-left latitude */
      -1.4000000000000e1, /* Region lower-left longitude */
      -3.6000000000000e1, /* Region upper-right latitude */
      -1.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_TRITON_1991 */
    {
      SRM_RTCOD_TRITON_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_TRITON_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_UMBRIEL_1988 */
    {
      SRM_RTCOD_UMBRIEL_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_UMBRIEL_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_URANUS_1988 */
    {
      SRM_RTCOD_URANUS_1988_IDENTITY, /* RT code */
      SRM_ORMCOD_URANUS_1988, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_URANUS_MAGNETIC_1993 */
    {
      SRM_RTCOD_URANUS_MAGNETIC_1993_VOYAGER, /* RT code */
      SRM_ORMCOD_URANUS_MAGNETIC_1993, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      0.0, /* delta z */
      0.0, /* omega 1 */
      2.8410081713019e-4, /* omega 2 */
      -2.5986013307471e-4, /* omega 3 */
      0.0, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_VENUS_1991 */
    {
      SRM_RTCOD_VENUS_1991_IDENTITY, /* RT code */
      SRM_ORMCOD_VENUS_1991, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_VITI_LEVU_1916 */
    {
      SRM_RTCOD_VITI_LEVU_1916_VITI_LEVU_ISLANDS, /* RT code */
      SRM_ORMCOD_VITI_LEVU_1916, /* ORM code */
      5.1000000000000e1, /* delta x */
      3.9100000000000e2, /* delta y */
      -3.6000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -2.0000000000000e1, /* Region lower-left latitude */
      1.7600000000000e2, /* Region lower-left longitude */
      -1.6000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_VOIROL_1874 */
    {
      SRM_RTCOD_VOIROL_1874_ALGERIA, /* RT code */
      SRM_ORMCOD_VOIROL_1874, /* ORM code */
      -7.3000000000000e1, /* delta x */
      -2.4700000000000e2, /* delta y */
      2.2700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.3000000000000e1, /* Region lower-left latitude */
      -1.5000000000000e1, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      1.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_VOIROL_1874_PM_PARIS */
    {
      SRM_RTCOD_VOIROL_1874_PM_PARIS_ALGERIA, /* RT code */
      SRM_ORMCOD_VOIROL_1874_PM_PARIS, /* ORM code */
      -7.3000000000000e1, /* delta x */
      -2.4700000000000e2, /* delta y */
      2.2700000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      4.0792344331977e-2, /* omega 3 */
      0.0, /* delta scale */
      1.3000000000000e1, /* Region lower-left latitude */
      -1.7000000000000e1, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      9.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_VOIROL_1960 */
    {
      SRM_RTCOD_VOIROL_1960_ALGERIA, /* RT code */
      SRM_ORMCOD_VOIROL_1960, /* ORM code */
      -1.2300000000000e2, /* delta x */
      -2.0600000000000e2, /* delta y */
      2.1900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.3000000000000e1, /* Region lower-left latitude */
      -1.5000000000000e1, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      1.1000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_VOIROL_1960_PM_PARIS */
    {
      SRM_RTCOD_VOIROL_1960_PM_PARIS_ALGERIA, /* RT code */
      SRM_ORMCOD_VOIROL_1960_PM_PARIS, /* ORM code */
      -1.2300000000000e2, /* delta x */
      -2.0600000000000e2, /* delta y */
      2.1900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      4.0792344331977e-2, /* omega 3 */
      0.0, /* delta scale */
      1.3000000000000e1, /* Region lower-left latitude */
      -1.7000000000000e1, /* Region lower-left longitude */
      4.3000000000000e1, /* Region upper-right latitude */
      9.0000000000000e0 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_WAKE_1952 */
    {
      SRM_RTCOD_WAKE_1952_WAKE_ATOLL, /* RT code */
      SRM_ORMCOD_WAKE_1952, /* ORM code */
      2.7600000000000e2, /* delta x */
      -5.7000000000000e1, /* delta y */
      1.4900000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.7000000000000e1, /* Region lower-left latitude */
      -1.7600000000000e2, /* Region lower-left longitude */
      2.1000000000000e1, /* Region upper-right latitude */
      -1.7100000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_WAKE_ENIWETOK_1960 */
    {
      SRM_RTCOD_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS, /* RT code */
      SRM_ORMCOD_WAKE_ENIWETOK_1960, /* ORM code */
      1.0200000000000e2, /* delta x */
      5.2000000000000e1, /* delta y */
      -3.8000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      1.0000000000000e0, /* Region lower-left latitude */
      1.5900000000000e2, /* Region lower-left longitude */
      1.6000000000000e1, /* Region upper-right latitude */
      1.7500000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_WGS_1972 */
    {
      SRM_RTCOD_WGS_1972_GLOBAL, /* RT code */
      SRM_ORMCOD_WGS_1972, /* ORM code */
      0.0, /* delta x */
      0.0, /* delta y */
      4.5000000000000e0, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      2.6858677933468e-6, /* omega 3 */
      2.1900000000000e-1, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_WGS_1984 */
    {
      SRM_RTCOD_WGS_1984_IDENTITY, /* RT code */
      SRM_ORMCOD_WGS_1984, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_YACARE_1987 */
    {
      SRM_RTCOD_YACARE_1987_URUGUAY, /* RT code */
      SRM_ORMCOD_YACARE_1987, /* ORM code */
      -1.5500000000000e2, /* delta x */
      1.7100000000000e2, /* delta y */
      3.7000000000000e1, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -4.0000000000000e1, /* Region lower-left latitude */
      -6.5000000000000e1, /* Region lower-left longitude */
      -2.5000000000000e1, /* Region upper-right latitude */
      -4.7000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_ZANDERIJ_1987 */
    {
      SRM_RTCOD_ZANDERIJ_1987_SURINAME, /* RT code */
      SRM_ORMCOD_ZANDERIJ_1987, /* ORM code */
      -2.6500000000000e2, /* delta x */
      1.2000000000000e2, /* delta y */
      -3.5800000000000e2, /* delta z */
      0.0, /* omega 1 */
      0.0, /* omega 2 */
      0.0, /* omega 3 */
      0.0, /* delta scale */
      -1.0000000000000e1, /* Region lower-left latitude */
      -7.6000000000000e1, /* Region lower-left longitude */
      2.0000000000000e1, /* Region upper-right latitude */
      -4.7000000000000e1 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_EXPERIMENTAL_NGA_SRM_MAX */
    {
      SRM_RTCOD_EXPERIMENTAL_NGA_MAX_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_EXPERIMENTAL_NGA_MAX, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    },

    /* Impl_RT_structs for SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE */
    {
      SRM_RTCOD_EXPERIMENTAL_NGA_SPHERE_IDENTITY_BY_DEFAULT, /* RT code */
      SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE, /* ORM code */
      IMPL_NAN, /* delta x */
      IMPL_NAN, /* delta y */
      IMPL_NAN, /* delta z */
      IMPL_NAN, /* omega 1 */
      IMPL_NAN, /* omega 2 */
      IMPL_NAN, /* omega 3 */
      IMPL_NAN, /* delta scale */
      -9.0000000000000e1, /* Region lower-left latitude */
      -1.8000000000000e2, /* Region lower-left longitude */
      9.0000000000000e1, /* Region upper-right latitude */
      1.8000000000000e2 /* Region upper-right longitude */
    }
}; /* end Impl_RT_array */

Impl_ORM_Struct Impl_ORM_array[] =
{
    /* Empty Impl_ORM_struct to faciliate indexing via ORM codes */
    {
      SRM_ORMCOD_UNSPECIFIED,  /* ORM code */
      SRM_ORMTCOD_UNSPECIFIED, /* ORM template code */
      ((SRM_OBRS_Code)0), /* OBRS code */
      SRM_ORMCOD_UNSPECIFIED,  /* Reference ORM code */
      ((SRM_RD_Code)0),   /* RD code */
      0,                  /* RT count */
      NULL                /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ABSTRACT_2D */
    {
      SRM_ORMCOD_ABSTRACT_2D,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_2D, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_ABSTRACT_2D, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[0]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ABSTRACT_3D */
    {
      SRM_ORMCOD_ABSTRACT_3D,  /* ORM code */
      SRM_ORMTCOD_TRI_PLANE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_ABSTRACT_3D, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[1]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ADINDAN_1991 */
    {
      SRM_ORMCOD_ADINDAN_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      7, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[2]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ADRASTEA_2000 */
    {
      SRM_ORMCOD_ADRASTEA_2000,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_ADRASTEA_2000, /* Reference ORM code */
      SRM_RDCOD_ADRASTEA_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[9]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM AFGOOYE_1987 */
    {
      SRM_ORMCOD_AFGOOYE_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_KRASSOVSKY_1940, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[10]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM AIN_EL_ABD_1970 */
    {
      SRM_ORMCOD_AIN_EL_ABD_1970,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[11]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM AMALTHEA_2000 */
    {
      SRM_ORMCOD_AMALTHEA_2000,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_AMALTHEA_2000, /* Reference ORM code */
      SRM_RDCOD_AMALTHEA_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[13]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM AMERICAN_SAMOA_1962 */
    {
      SRM_ORMCOD_AMERICAN_SAMOA_1962,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[14]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ANNA_1_1965 */
    {
      SRM_ORMCOD_ANNA_1_1965,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_AUSTRALIAN_NATIONAL_1966, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[15]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ANTIGUA_1943 */
    {
      SRM_ORMCOD_ANTIGUA_1943,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[16]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ARC_1950 */
    {
      SRM_ORMCOD_ARC_1950,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      9, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[17]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ARC_1960 */
    {
      SRM_ORMCOD_ARC_1960,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      3, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[26]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ARIEL_1988 */
    {
      SRM_ORMCOD_ARIEL_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_ARIEL_1988, /* Reference ORM code */
      SRM_RDCOD_ARIEL_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[29]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ASCENSION_1958 */
    {
      SRM_ORMCOD_ASCENSION_1958,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[30]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ATLAS_1988 */
    {
      SRM_ORMCOD_ATLAS_1988,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_ATLAS_1988, /* Reference ORM code */
      SRM_RDCOD_ATLAS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[31]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM AUSTRALIAN_GEOD_1966 */
    {
      SRM_ORMCOD_AUSTRALIAN_GEOD_1966,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_AUSTRALIAN_NATIONAL_1966, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[32]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM AUSTRALIAN_GEOD_1984 */
    {
      SRM_ORMCOD_AUSTRALIAN_GEOD_1984,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_AUSTRALIAN_NATIONAL_1966, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[33]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM AYABELLE_LIGHTHOUSE_1991 */
    {
      SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[35]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BEACON_E_1945 */
    {
      SRM_ORMCOD_BEACON_E_1945,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[36]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BELINDA_1988 */
    {
      SRM_ORMCOD_BELINDA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_BELINDA_1988, /* Reference ORM code */
      SRM_RDCOD_BELINDA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[37]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BELLEVUE_IGN_1987 */
    {
      SRM_ORMCOD_BELLEVUE_IGN_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[38]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BERMUDA_1957 */
    {
      SRM_ORMCOD_BERMUDA_1957,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[39]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BIANCA_1988 */
    {
      SRM_ORMCOD_BIANCA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_BIANCA_1988, /* Reference ORM code */
      SRM_RDCOD_BIANCA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[40]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BISSAU_1991 */
    {
      SRM_ORMCOD_BISSAU_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[41]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BOGOTA_OBS_1987 */
    {
      SRM_ORMCOD_BOGOTA_OBS_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[42]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BOGOTA_OBS_1987_PM_BOGOTA */
    {
      SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[43]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM BUKIT_RIMPAH_1987 */
    {
      SRM_ORMCOD_BUKIT_RIMPAH_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[44]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CALLISTO_2000 */
    {
      SRM_ORMCOD_CALLISTO_2000,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_CALLISTO_2000, /* Reference ORM code */
      SRM_RDCOD_CALLISTO_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[45]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CALYPSO_1988 */
    {
      SRM_ORMCOD_CALYPSO_1988,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_CALYPSO_1988, /* Reference ORM code */
      SRM_RDCOD_CALYPSO_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[46]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CAMP_AREA_1987 */
    {
      SRM_ORMCOD_CAMP_AREA_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[47]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CAMPO_INCHAUSPE_1969 */
    {
      SRM_ORMCOD_CAMPO_INCHAUSPE_1969,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[48]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CANTON_1966 */
    {
      SRM_ORMCOD_CANTON_1966,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[49]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CAPE_1987 */
    {
      SRM_ORMCOD_CAPE_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[50]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CAPE_CANAVERAL_1991 */
    {
      SRM_ORMCOD_CAPE_CANAVERAL_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[51]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CARTHAGE_1987 */
    {
      SRM_ORMCOD_CARTHAGE_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[52]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CHARON_1991 */
    {
      SRM_ORMCOD_CHARON_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_CHARON_1991, /* Reference ORM code */
      SRM_RDCOD_CHARON_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[53]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CHATHAM_1971 */
    {
      SRM_ORMCOD_CHATHAM_1971,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[54]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CHUA_1987 */
    {
      SRM_ORMCOD_CHUA_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[55]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM COAMPS_1998 */
    {
      SRM_ORMCOD_COAMPS_1998,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_COAMPS_1998, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[56]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CORDELIA_1988 */
    {
      SRM_ORMCOD_CORDELIA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_CORDELIA_1988, /* Reference ORM code */
      SRM_RDCOD_CORDELIA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[57]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CORREGO_ALEGRE_1987 */
    {
      SRM_ORMCOD_CORREGO_ALEGRE_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[58]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM CRESSIDA_1988 */
    {
      SRM_ORMCOD_CRESSIDA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_CRESSIDA_1988, /* Reference ORM code */
      SRM_RDCOD_CRESSIDA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[59]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DABOLA_1991 */
    {
      SRM_ORMCOD_DABOLA_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[60]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DECEPTION_1993 */
    {
      SRM_ORMCOD_DECEPTION_1993,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[61]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DEIMOS_1988 */
    {
      SRM_ORMCOD_DEIMOS_1988,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_DEIMOS_1988, /* Reference ORM code */
      SRM_RDCOD_DEIMOS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[62]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DESDEMONA_1988 */
    {
      SRM_ORMCOD_DESDEMONA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_DESDEMONA_1988, /* Reference ORM code */
      SRM_RDCOD_DESDEMONA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[63]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DESPINA_1991 */
    {
      SRM_ORMCOD_DESPINA_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_DESPINA_1991, /* Reference ORM code */
      SRM_RDCOD_DESPINA_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[64]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DIONE_1982 */
    {
      SRM_ORMCOD_DIONE_1982,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_DIONE_1982, /* Reference ORM code */
      SRM_RDCOD_DIONE_1982, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[65]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DJAKARTA_1987 */
    {
      SRM_ORMCOD_DJAKARTA_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[67]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DJAKARTA_1987_PM_DJAKARTA */
    {
      SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[66]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DOS_1968 */
    {
      SRM_ORMCOD_DOS_1968,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[68]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM DOS_71_4_1987 */
    {
      SRM_ORMCOD_DOS_71_4_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[69]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EARTH_INERTIAL_ARIES_1950 */
    {
      SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EARTH_INERTIAL_ARIES_TRUE_OF_DATE */
    {
      SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EARTH_INERTIAL_J2000r0 */
    {
      SRM_ORMCOD_EARTH_INERTIAL_J2000r0,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EARTH_SOLAR_ECLIPTIC */
    {
      SRM_ORMCOD_EARTH_SOLAR_ECLIPTIC,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_SOLAR_ECLIPTIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EARTH_SOLAR_EQUATORIAL */
    {
      SRM_ORMCOD_EARTH_SOLAR_EQUATORIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_SOLAR_EQUATORIAL, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EARTH_SOLAR_MAG_DIPOLE */
    {
      SRM_ORMCOD_EARTH_SOLAR_MAG_DIPOLE,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_SOLAR_MAGNETIC_DIPOLE, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EARTH_SOLAR_MAGNETOSPHERIC */
    {
      SRM_ORMCOD_EARTH_SOLAR_MAGNETOSPHERIC,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_SOLAR_MAGNETIC_ECLIPTIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EASTER_1967 */
    {
      SRM_ORMCOD_EASTER_1967,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[70]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ENCELADUS_1994 */
    {
      SRM_ORMCOD_ENCELADUS_1994,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_ENCELADUS_1994, /* Reference ORM code */
      SRM_RDCOD_ENCELADUS_1994, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[71]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EPIMETHEUS_1988 */
    {
      SRM_ORMCOD_EPIMETHEUS_1988,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_EPIMETHEUS_1988, /* Reference ORM code */
      SRM_RDCOD_EPIMETHEUS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[72]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EROS_2000 */
    {
      SRM_ORMCOD_EROS_2000,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_EROS_2000, /* Reference ORM code */
      SRM_RDCOD_EROS_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[73]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ESTONIA_1937 */
    {
      SRM_ORMCOD_ESTONIA_1937,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[74]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ETRS_1989 */
    {
      SRM_ORMCOD_ETRS_1989,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_GRS_1980, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[75]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EUROPA_2000 */
    {
      SRM_ORMCOD_EUROPA_2000,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_EUROPA_2000, /* Reference ORM code */
      SRM_RDCOD_EUROPA_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[76]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EUROPE_1950 */
    {
      SRM_ORMCOD_EUROPE_1950,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      16, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[77]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM EUROPE_1979 */
    {
      SRM_ORMCOD_EUROPE_1979,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[93]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM FAHUD_1987 */
    {
      SRM_ORMCOD_FAHUD_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[94]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM FORT_THOMAS_1955 */
    {
      SRM_ORMCOD_FORT_THOMAS_1955,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[96]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GALATEA_1991 */
    {
      SRM_ORMCOD_GALATEA_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_GALATEA_1991, /* Reference ORM code */
      SRM_RDCOD_GALATEA_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[97]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GAN_1970 */
    {
      SRM_ORMCOD_GAN_1970,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[98]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GANYMEDE_2000 */
    {
      SRM_ORMCOD_GANYMEDE_2000,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_GANYMEDE_2000, /* Reference ORM code */
      SRM_RDCOD_GANYMEDE_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[99]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GASPRA_1991 */
    {
      SRM_ORMCOD_GASPRA_1991,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_GASPRA_1991, /* Reference ORM code */
      SRM_RDCOD_GASPRA_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[100]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GDA_1994 */
    {
      SRM_ORMCOD_GDA_1994,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_GRS_1980, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[101]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEODETIC_DATUM_1949 */
    {
      SRM_ORMCOD_GEODETIC_DATUM_1949,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[102]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1945 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1945,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[104]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1950 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1950,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[105]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1955 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1955,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[106]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1960 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1960,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[107]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1965 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1965,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[108]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1970 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1970,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[109]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1975 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1975,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[110]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1980 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1980,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[111]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1985 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1985,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[112]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1990 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1990,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[113]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_1995 */
    {
      SRM_ORMCOD_GEOMAGNETIC_1995,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[114]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GEOMAGNETIC_2000 */
    {
      SRM_ORMCOD_GEOMAGNETIC_2000,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[115]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GRACIOSA_BASE_SW_1948 */
    {
      SRM_ORMCOD_GRACIOSA_BASE_SW_1948,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[116]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GUAM_1963 */
    {
      SRM_ORMCOD_GUAM_1963,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[117]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GUNONG_SEGARA_1987 */
    {
      SRM_ORMCOD_GUNONG_SEGARA_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[118]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM GUX_1_1987 */
    {
      SRM_ORMCOD_GUX_1_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[119]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HELENE_1992 */
    {
      SRM_ORMCOD_HELENE_1992,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_HELENE_1992, /* Reference ORM code */
      SRM_RDCOD_HELENE_1992, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[120]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HELIO_ARIES_ECLIPTIC_J2000r0 */
    {
      SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_J2000r0,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_HELIOCENTRIC_ARIES_ECLIPTIC, /* OBRS code */
      SRM_ORMCOD_SUN_1992, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE */
    {
      SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_HELIOCENTRIC_ARIES_ECLIPTIC, /* OBRS code */
      SRM_ORMCOD_SUN_1992, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HELIO_EARTH_ECLIPTIC */
    {
      SRM_ORMCOD_HELIO_EARTH_ECLIPTIC,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_HELIOCENTRIC_PLANET_ECLIPTIC, /* OBRS code */
      SRM_ORMCOD_SUN_1992, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HELIO_EARTH_EQUATORIAL */
    {
      SRM_ORMCOD_HELIO_EARTH_EQUATORIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_HELIOCENTRIC_PLANET_EQUATORIAL, /* OBRS code */
      SRM_ORMCOD_SUN_1992, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HERAT_NORTH_1987 */
    {
      SRM_ORMCOD_HERAT_NORTH_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[121]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HERMANNSKOGEL_1871 */
    {
      SRM_ORMCOD_HERMANNSKOGEL_1871,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[122]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HJORSEY_1955 */
    {
      SRM_ORMCOD_HJORSEY_1955,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[123]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HONG_KONG_1963 */
    {
      SRM_ORMCOD_HONG_KONG_1963,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[124]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM HU_TZU_SHAN_1991 */
    {
      SRM_ORMCOD_HU_TZU_SHAN_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[125]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM IAPETUS_1988 */
    {
      SRM_ORMCOD_IAPETUS_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_IAPETUS_1988, /* Reference ORM code */
      SRM_RDCOD_IAPETUS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[126]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM IDA_1991 */
    {
      SRM_ORMCOD_IDA_1991,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_IDA_1991, /* Reference ORM code */
      SRM_RDCOD_IDA_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[127]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM INDIAN_1916 */
    {
      SRM_ORMCOD_INDIAN_1916,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_ADJ_1937, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[128]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM INDIAN_1954 */
    {
      SRM_ORMCOD_INDIAN_1954,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_ADJ_1937, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[130]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM INDIAN_1956 */
    {
      SRM_ORMCOD_INDIAN_1956,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_1956, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[131]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM INDIAN_1960 */
    {
      SRM_ORMCOD_INDIAN_1960,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_ADJ_1937, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[132]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM INDIAN_1962 */
    {
      SRM_ORMCOD_INDIAN_1962,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_REVISED_1962, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[134]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM INDIAN_1975 */
    {
      SRM_ORMCOD_INDIAN_1975,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_ADJ_1937, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[135]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM INDONESIAN_1974 */
    {
      SRM_ORMCOD_INDONESIAN_1974,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INDONESIAN_1974, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[137]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM IO_2000 */
    {
      SRM_ORMCOD_IO_2000,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_IO_2000, /* Reference ORM code */
      SRM_RDCOD_IO_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[138]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM IRELAND_1965 */
    {
      SRM_ORMCOD_IRELAND_1965,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MODIFIED_AIRY_1849, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[139]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ISTS_061_1968 */
    {
      SRM_ORMCOD_ISTS_061_1968,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[141]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ISTS_073_1969 */
    {
      SRM_ORMCOD_ISTS_073_1969,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[142]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JANUS_1988 */
    {
      SRM_ORMCOD_JANUS_1988,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_JANUS_1988, /* Reference ORM code */
      SRM_RDCOD_JANUS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[143]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JGD_2000 */
    {
      SRM_ORMCOD_JGD_2000,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_GRS_1980, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[144]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JOHNSTON_1961 */
    {
      SRM_ORMCOD_JOHNSTON_1961,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[145]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JULIET_1988 */
    {
      SRM_ORMCOD_JULIET_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_JULIET_1988, /* Reference ORM code */
      SRM_RDCOD_JULIET_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[146]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JUPITER_1988 */
    {
      SRM_ORMCOD_JUPITER_1988,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_JUPITER_1988, /* Reference ORM code */
      SRM_RDCOD_JUPITER_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[147]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JUPITER_INERTIAL */
    {
      SRM_ORMCOD_JUPITER_INERTIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_JUPITER_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JUPITER_MAGNETIC_1993 */
    {
      SRM_ORMCOD_JUPITER_MAGNETIC_1993,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_JUPITER_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[148]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JUPITER_SOLAR_ECLIPTIC */
    {
      SRM_ORMCOD_JUPITER_SOLAR_ECLIPTIC,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_SOLAR_ECLIPTIC, /* OBRS code */
      SRM_ORMCOD_JUPITER_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JUPITER_SOLAR_EQUATORIAL */
    {
      SRM_ORMCOD_JUPITER_SOLAR_EQUATORIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_SOLAR_EQUATORIAL, /* OBRS code */
      SRM_ORMCOD_JUPITER_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JUPITER_SOLAR_MAG_DIPOLE */
    {
      SRM_ORMCOD_JUPITER_SOLAR_MAG_DIPOLE,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_SOLAR_MAGNETIC_DIPOLE, /* OBRS code */
      SRM_ORMCOD_JUPITER_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM JUPITER_SOLAR_MAG_ECLIPTIC */
    {
      SRM_ORMCOD_JUPITER_SOLAR_MAG_ECLIPTIC,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_SOLAR_MAGNETIC_ECLIPTIC, /* OBRS code */
      SRM_ORMCOD_JUPITER_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM KANDAWALA_1987 */
    {
      SRM_ORMCOD_KANDAWALA_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_ADJ_1937, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[149]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM KERGUELEN_1949 */
    {
      SRM_ORMCOD_KERGUELEN_1949,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[150]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM KERTAU_1948 */
    {
      SRM_ORMCOD_KERTAU_1948,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_1948, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[151]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM KOREAN_GEODETIC_1995 */
    {
      SRM_ORMCOD_KOREAN_GEODETIC_1995,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_WGS_1984, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[152]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM KUSAIE_1951 */
    {
      SRM_ORMCOD_KUSAIE_1951,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[153]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM LARISSA_1991 */
    {
      SRM_ORMCOD_LARISSA_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_LARISSA_1991, /* Reference ORM code */
      SRM_RDCOD_LARISSA_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[154]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM LC5_1961 */
    {
      SRM_ORMCOD_LC5_1961,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[155]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM LEIGON_1991 */
    {
      SRM_ORMCOD_LEIGON_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[156]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM LIBERIA_1964 */
    {
      SRM_ORMCOD_LIBERIA_1964,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[158]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM LUZON_1987 */
    {
      SRM_ORMCOD_LUZON_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[159]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM M_PORALOKO_1991 */
    {
      SRM_ORMCOD_M_PORALOKO_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[161]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MAHE_1971 */
    {
      SRM_ORMCOD_MAHE_1971,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[162]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MARCUS_STATION_1952 */
    {
      SRM_ORMCOD_MARCUS_STATION_1952,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[163]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MARS_2000 */
    {
      SRM_ORMCOD_MARS_2000,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_MARS_2000, /* Reference ORM code */
      SRM_RDCOD_MARS_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[164]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MARS_INERTIAL */
    {
      SRM_ORMCOD_MARS_INERTIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_MARS_2000, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MARS_SPHERE_2000 */
    {
      SRM_ORMCOD_MARS_SPHERE_2000,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_MARS_2000, /* Reference ORM code */
      SRM_RDCOD_MARS_SPHERE_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[165]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MASS_1999 */
    {
      SRM_ORMCOD_MASS_1999,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MASS_1999, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[166]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MASSAWA_1987 */
    {
      SRM_ORMCOD_MASSAWA_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[167]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MERCHICH_1987 */
    {
      SRM_ORMCOD_MERCHICH_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[168]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MERCURY_1988 */
    {
      SRM_ORMCOD_MERCURY_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_MERCURY_1988, /* Reference ORM code */
      SRM_RDCOD_MERCURY_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[169]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MERCURY_INERTIAL */
    {
      SRM_ORMCOD_MERCURY_INERTIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_MERCURY_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM METIS_2000 */
    {
      SRM_ORMCOD_METIS_2000,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_METIS_2000, /* Reference ORM code */
      SRM_RDCOD_METIS_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[170]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MIDWAY_1961 */
    {
      SRM_ORMCOD_MIDWAY_1961,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[171]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MIMAS_1994 */
    {
      SRM_ORMCOD_MIMAS_1994,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_MIMAS_1994, /* Reference ORM code */
      SRM_RDCOD_MIMAS_1994, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[172]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MINNA_1991 */
    {
      SRM_ORMCOD_MINNA_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[173]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MIRANDA_1988 */
    {
      SRM_ORMCOD_MIRANDA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_MIRANDA_1988, /* Reference ORM code */
      SRM_RDCOD_MIRANDA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[175]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MM5_1997 */
    {
      SRM_ORMCOD_MM5_1997,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MM5_1997, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[176]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MODTRAN_MIDLATITUDE_N_1989 */
    {
      SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MODTRAN_MIDLATITUDE_1989, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[177]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MODTRAN_MIDLATITUDE_S_1989 */
    {
      SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MODTRAN_MIDLATITUDE_1989, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[178]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MODTRAN_SUBARCTIC_N_1989 */
    {
      SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MODTRAN_SUBARCTIC_1989, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[179]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MODTRAN_SUBARCTIC_S_1989 */
    {
      SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MODTRAN_SUBARCTIC_1989, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[180]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MODTRAN_TROPICAL_1989 */
    {
      SRM_ORMCOD_MODTRAN_TROPICAL_1989,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MODTRAN_TROPICAL_1989, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[181]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MONTSERRAT_1958 */
    {
      SRM_ORMCOD_MONTSERRAT_1958,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[182]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MOON_1991 */
    {
      SRM_ORMCOD_MOON_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_MOON_1991, /* Reference ORM code */
      SRM_RDCOD_MOON_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[183]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM MULTIGEN_FLAT_EARTH_1989 */
    {
      SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[184]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM N_AM_1927 */
    {
      SRM_ORMCOD_N_AM_1927,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      20, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[185]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM N_AM_1983 */
    {
      SRM_ORMCOD_N_AM_1983,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_GRS_1980, /* RD code */
      6, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[205]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM N_SAHARA_1959 */
    {
      SRM_ORMCOD_N_SAHARA_1959,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[211]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NAHRWAN_1987 */
    {
      SRM_ORMCOD_NAHRWAN_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      3, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[212]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NAIAD_1991 */
    {
      SRM_ORMCOD_NAIAD_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_NAIAD_1991, /* Reference ORM code */
      SRM_RDCOD_NAIAD_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[215]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NAPARIMA_1991 */
    {
      SRM_ORMCOD_NAPARIMA_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[216]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NEPTUNE_1991 */
    {
      SRM_ORMCOD_NEPTUNE_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_NEPTUNE_1991, /* Reference ORM code */
      SRM_RDCOD_NEPTUNE_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[217]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NEPTUNE_INERTIAL */
    {
      SRM_ORMCOD_NEPTUNE_INERTIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_NEPTUNE_1991, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NEPTUNE_MAGNETIC_1993 */
    {
      SRM_ORMCOD_NEPTUNE_MAGNETIC_1993,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_NEPTUNE_1991, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[218]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NOGAPS_1988 */
    {
      SRM_ORMCOD_NOGAPS_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_NOGAPS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[219]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NTF_1896 */
    {
      SRM_ORMCOD_NTF_1896,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880_IGN, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[220]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM NTF_1896_PM_PARIS */
    {
      SRM_ORMCOD_NTF_1896_PM_PARIS,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880_IGN, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[221]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM OBERON_1988 */
    {
      SRM_ORMCOD_OBERON_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_OBERON_1988, /* Reference ORM code */
      SRM_RDCOD_OBERON_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[222]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM OBSERV_METEORO_1939 */
    {
      SRM_ORMCOD_OBSERV_METEORO_1939,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[223]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM OLD_EGYPTIAN_1907 */
    {
      SRM_ORMCOD_OLD_EGYPTIAN_1907,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_HELMERT_1906, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[224]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM OLD_HAWAIIAN_CLARKE_1987 */
    {
      SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      5, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[225]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM OLD_HAWAIIAN_INT_1987 */
    {
      SRM_ORMCOD_OLD_HAWAIIAN_INT_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      5, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[230]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM OPHELIA_1988 */
    {
      SRM_ORMCOD_OPHELIA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_OPHELIA_1988, /* Reference ORM code */
      SRM_RDCOD_OPHELIA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[235]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM OSGB_1936 */
    {
      SRM_ORMCOD_OSGB_1936,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_AIRY_1830, /* RD code */
      6, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[236]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PAN_1991 */
    {
      SRM_ORMCOD_PAN_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PAN_1991, /* Reference ORM code */
      SRM_RDCOD_PAN_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[242]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PANDORA_1988 */
    {
      SRM_ORMCOD_PANDORA_1988,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PANDORA_1988, /* Reference ORM code */
      SRM_RDCOD_PANDORA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[243]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PHOBOS_1988 */
    {
      SRM_ORMCOD_PHOBOS_1988,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PHOBOS_1988, /* Reference ORM code */
      SRM_RDCOD_PHOBOS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[244]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PHOEBE_1988 */
    {
      SRM_ORMCOD_PHOEBE_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PHOEBE_1988, /* Reference ORM code */
      SRM_RDCOD_PHOEBE_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[245]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PICO_DE_LAS_NIEVES_1987 */
    {
      SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[246]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PITCAIRN_1967 */
    {
      SRM_ORMCOD_PITCAIRN_1967,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[247]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PLUTO_1994 */
    {
      SRM_ORMCOD_PLUTO_1994,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PLUTO_1994, /* Reference ORM code */
      SRM_RDCOD_PLUTO_1994, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[248]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PLUTO_INERTIAL */
    {
      SRM_ORMCOD_PLUTO_INERTIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_PLUTO_1994, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM POINT_58_1991 */
    {
      SRM_ORMCOD_POINT_58_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[249]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM POINTE_NOIRE_1948 */
    {
      SRM_ORMCOD_POINTE_NOIRE_1948,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[250]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PORTIA_1988 */
    {
      SRM_ORMCOD_PORTIA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PORTIA_1988, /* Reference ORM code */
      SRM_RDCOD_PORTIA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[251]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PORTO_SANTO_1936 */
    {
      SRM_ORMCOD_PORTO_SANTO_1936,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[252]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PROMETHEUS_1988 */
    {
      SRM_ORMCOD_PROMETHEUS_1988,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PROMETHEUS_1988, /* Reference ORM code */
      SRM_RDCOD_PROMETHEUS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[253]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PROTEUS_1991 */
    {
      SRM_ORMCOD_PROTEUS_1991,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PROTEUS_1991, /* Reference ORM code */
      SRM_RDCOD_PROTEUS_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[254]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PROV_S_AM_1956 */
    {
      SRM_ORMCOD_PROV_S_AM_1956,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      10, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[255]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PROV_S_CHILEAN_1963 */
    {
      SRM_ORMCOD_PROV_S_CHILEAN_1963,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[265]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PUCK_1988 */
    {
      SRM_ORMCOD_PUCK_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_PUCK_1988, /* Reference ORM code */
      SRM_RDCOD_PUCK_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[266]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PUERTO_RICO_1987 */
    {
      SRM_ORMCOD_PUERTO_RICO_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1866, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[267]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM PULKOVO_1942 */
    {
      SRM_ORMCOD_PULKOVO_1942,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_KRASSOVSKY_1940, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[268]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM QATAR_NATIONAL_1974 */
    {
      SRM_ORMCOD_QATAR_NATIONAL_1974,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[269]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM QORNOQ_1987 */
    {
      SRM_ORMCOD_QORNOQ_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[270]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM REUNION_1947 */
    {
      SRM_ORMCOD_REUNION_1947,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[271]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM RGF_1993 */
    {
      SRM_ORMCOD_RGF_1993,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_GRS_1980, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[272]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM RHEA_1988 */
    {
      SRM_ORMCOD_RHEA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_RHEA_1988, /* Reference ORM code */
      SRM_RDCOD_RHEA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[273]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ROME_1940 */
    {
      SRM_ORMCOD_ROME_1940,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[275]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ROME_1940_PM_ROME */
    {
      SRM_ORMCOD_ROME_1940_PM_ROME,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[274]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ROSALIND_1988 */
    {
      SRM_ORMCOD_ROSALIND_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_ROSALIND_1988, /* Reference ORM code */
      SRM_RDCOD_ROSALIND_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[276]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM S_AM_1969 */
    {
      SRM_ORMCOD_S_AM_1969,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_SOUTH_AMERICAN_1969, /* RD code */
      13, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[277]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM S_ASIA_1987 */
    {
      SRM_ORMCOD_S_ASIA_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_MODIFIED_FISCHER_1960, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[290]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM S_JTSK_1993 */
    {
      SRM_ORMCOD_S_JTSK_1993,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[291]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM S42_PULKOVO */
    {
      SRM_ORMCOD_S42_PULKOVO,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_KRASSOVSKY_1940, /* RD code */
      7, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[293]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SANTO_DOS_1965 */
    {
      SRM_ORMCOD_SANTO_DOS_1965,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[300]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SAO_BRAZ_1987 */
    {
      SRM_ORMCOD_SAO_BRAZ_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[301]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SAPPER_HILL_1943 */
    {
      SRM_ORMCOD_SAPPER_HILL_1943,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[302]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SATURN_1988 */
    {
      SRM_ORMCOD_SATURN_1988,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_SATURN_1988, /* Reference ORM code */
      SRM_RDCOD_SATURN_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[303]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SATURN_INERTIAL */
    {
      SRM_ORMCOD_SATURN_INERTIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_SATURN_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SATURN_MAGNETIC_1993 */
    {
      SRM_ORMCOD_SATURN_MAGNETIC_1993,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_SATURN_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[304]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SCHWARZECK_1991 */
    {
      SRM_ORMCOD_SCHWARZECK_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_NAMIBIA, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[305]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SELVAGEM_GRANDE_1938 */
    {
      SRM_ORMCOD_SELVAGEM_GRANDE_1938,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[306]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SIERRA_LEONE_1960 */
    {
      SRM_ORMCOD_SIERRA_LEONE_1960,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[307]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SIRGAS_2000 */
    {
      SRM_ORMCOD_SIRGAS_2000,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_GRS_1980, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[308]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM SUN_1992 */
    {
      SRM_ORMCOD_SUN_1992,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_SUN_1992, /* Reference ORM code */
      SRM_RDCOD_SUN_1992, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[309]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TANANARIVE_OBS_1925 */
    {
      SRM_ORMCOD_TANANARIVE_OBS_1925,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[310]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TANANARIVE_OBS_1925_PM_PARIS */
    {
      SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[311]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TELESTO_1988 */
    {
      SRM_ORMCOD_TELESTO_1988,  /* ORM code */
      SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_TELESTO_1988, /* Reference ORM code */
      SRM_RDCOD_TELESTO_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[312]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TERN_1961 */
    {
      SRM_ORMCOD_TERN_1961,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[313]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TETHYS_1991 */
    {
      SRM_ORMCOD_TETHYS_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_TETHYS_1991, /* Reference ORM code */
      SRM_RDCOD_TETHYS_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[314]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM THALASSA_1991 */
    {
      SRM_ORMCOD_THALASSA_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_THALASSA_1991, /* Reference ORM code */
      SRM_RDCOD_THALASSA_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[315]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM THEBE_2000 */
    {
      SRM_ORMCOD_THEBE_2000,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_THEBE_2000, /* Reference ORM code */
      SRM_RDCOD_THEBE_2000, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[316]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TIMBALAI_EVEREST_1948 */
    {
      SRM_ORMCOD_TIMBALAI_EVEREST_1948,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_EVEREST_BRUNEI_1967, /* RD code */
      2, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[317]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TITAN_1982 */
    {
      SRM_ORMCOD_TITAN_1982,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_TITAN_1982, /* Reference ORM code */
      SRM_RDCOD_TITAN_1982, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[319]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TITANIA_1988 */
    {
      SRM_ORMCOD_TITANIA_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_TITANIA_1988, /* Reference ORM code */
      SRM_RDCOD_TITANIA_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[320]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TOKYO_1991 */
    {
      SRM_ORMCOD_TOKYO_1991,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_BESSEL_1841_ETHIOPIA, /* RD code */
      5, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[321]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TRISTAN_1968 */
    {
      SRM_ORMCOD_TRISTAN_1968,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[326]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM TRITON_1991 */
    {
      SRM_ORMCOD_TRITON_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_TRITON_1991, /* Reference ORM code */
      SRM_RDCOD_TRITON_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[327]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM UMBRIEL_1988 */
    {
      SRM_ORMCOD_UMBRIEL_1988,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_UMBRIEL_1988, /* Reference ORM code */
      SRM_RDCOD_UMBRIEL_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[328]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM URANUS_1988 */
    {
      SRM_ORMCOD_URANUS_1988,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_URANUS_1988, /* Reference ORM code */
      SRM_RDCOD_URANUS_1988, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[329]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM URANUS_INERTIAL */
    {
      SRM_ORMCOD_URANUS_INERTIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_URANUS_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM URANUS_MAGNETIC_1993 */
    {
      SRM_ORMCOD_URANUS_MAGNETIC_1993,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_CELESTIOMAGNETIC, /* OBRS code */
      SRM_ORMCOD_URANUS_1988, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[330]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM VENUS_1991 */
    {
      SRM_ORMCOD_VENUS_1991,  /* ORM code */
      SRM_ORMTCOD_SPHERE, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_VENUS_1991, /* Reference ORM code */
      SRM_RDCOD_VENUS_1991, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[331]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM VENUS_INERTIAL */
    {
      SRM_ORMCOD_VENUS_INERTIAL,  /* ORM code */
      SRM_ORMTCOD_BI_AXIS_ORIGIN_3D, /* ORM template code */
      SRM_OBRSCOD_EQUATORIAL_INERTIAL, /* OBRS code */
      SRM_ORMCOD_VENUS_1991, /* Reference ORM code */
      ((SRM_RD_Code)0), /* RD code */
      0, /* RT count */
      NULL /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM VITI_LEVU_1916 */
    {
      SRM_ORMCOD_VITI_LEVU_1916,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[332]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM VOIROL_1874 */
    {
      SRM_ORMCOD_VOIROL_1874,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[333]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM VOIROL_1874_PM_PARIS */
    {
      SRM_ORMCOD_VOIROL_1874_PM_PARIS,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[334]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM VOIROL_1960 */
    {
      SRM_ORMCOD_VOIROL_1960,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[335]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM VOIROL_1960_PM_PARIS */
    {
      SRM_ORMCOD_VOIROL_1960_PM_PARIS,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_CLARKE_1880, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[336]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM WAKE_1952 */
    {
      SRM_ORMCOD_WAKE_1952,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[337]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM WAKE_ENIWETOK_1960 */
    {
      SRM_ORMCOD_WAKE_ENIWETOK_1960,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_HOUGH_1960, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[338]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM WGS_1972 */
    {
      SRM_ORMCOD_WGS_1972,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_WGS_1972, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[339]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM WGS_1984 */
    {
      SRM_ORMCOD_WGS_1984,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_WGS_1984, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[340]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM YACARE_1987 */
    {
      SRM_ORMCOD_YACARE_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[341]) /* RT array pointer */
    },

    /* Impl_ORM_struct for ORM ZANDERIJ_1987 */
    {
      SRM_ORMCOD_ZANDERIJ_1987,  /* ORM code */
      SRM_ORMTCOD_OBLATE_ELLIPSOID, /* ORM template code */
      SRM_OBRSCOD_FIXED, /* OBRS code */
      SRM_ORMCOD_WGS_1984, /* Reference ORM code */
      SRM_RDCOD_INTERNATIONAL_1924, /* RD code */
      1, /* RT count */
      (Impl_RT_Struct *)(&Impl_RT_array[342]) /* RT array pointer */
    }

}; /* end Impl_ORM_struct_array */

bool
Impl_wellFormedORMCode( SRM_ORM_Code orm_code )
{
    return (orm_code != 0 && orm_code <= SRM_ORM_CODE_UBOUND);
}

bool
Impl_wellFormedRTCode( SRM_ORM_Code orm_code, SRM_RT_Code rt_code )
{
    if (!Impl_wellFormedORMCode(orm_code) || rt_code > SRM_RT_CODE_UBOUND)
        return false;
    else if (rt_code <= 0)
        return true;
    else
        return (Impl_RT_array[rt_code-1].orm_code == orm_code);
}

/*
 * function assumes orm_code and rt_code have
 * already been verified as well-formed before
 * being passed in.
 */
const Impl_RT_Struct *
Impl_getRTstruct( SRM_ORM_Code orm_code, SRM_RT_Code rt_code )
{
    if (orm_code >= 0)
        return &(Impl_RT_array[rt_code-1]);
    else if (rt_code == SRM_RTCOD_EXPERIMENTAL_NGA_MAX_IDENTITY_BY_DEFAULT)
        return &(Impl_RT_array[SRM_RT_CODE_UBOUND]);
    else if (rt_code == SRM_RTCOD_EXPERIMENTAL_NGA_SPHERE_IDENTITY_BY_DEFAULT)
        return &(Impl_RT_array[SRM_RT_CODE_UBOUND+1]);
    else
        return NULL;
}
