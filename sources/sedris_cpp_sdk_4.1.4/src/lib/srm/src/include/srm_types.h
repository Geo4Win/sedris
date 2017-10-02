/* SRM API
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 *
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
 *
 *
 *
 *
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 *
 */

/** @file   srm_types.h
    @author Automatically generated file
    @brief  Provide type definitions for the SRM API.
 */

/*
 * For other release dates/detailed changes, contact SAIC.
 */


#ifndef SRM_TYPES_H_INCLUDED
#define SRM_TYPES_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

#include "srm_stds.h"

/* This pragma is to remove some of the warnings about
 * truncating the debug information to 255 characters.
 * The following link has an explanation about why we
 * can't suppress them all:
 * http://support.microsoft.com/default.aspx?scid=kb;EN-US;167355
 */
#ifdef _WIN32
#pragma warning(disable: 4786)
#endif

/*!
 * ENUM: SRM_Axis_Direction
 *
 *  This data type represents the values of the axis direction parameter(s)
 *  of the SRFTs LOCAL_SPACE_RECTANGULAR_3D and LOCAL_SPACE_RECTANGULAR_2D.
 */
typedef enum
{
    SRM_AXDIR_POSITIVE_PRIMARY_AXIS,
    SRM_AXDIR_POSITIVE_SECONDARY_AXIS,
    SRM_AXDIR_POSITIVE_TERTIARY_AXIS,
    SRM_AXDIR_NEGATIVE_PRIMARY_AXIS,
    SRM_AXDIR_NEGATIVE_SECONDARY_AXIS,
    SRM_AXDIR_NEGATIVE_TERTIARY_AXIS
} SRM_Axis_Direction;


/*!
 * STRUCT: SRM_CD_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   SRFT CELESTIODETIC.
 */
typedef struct
{
    SRM_Long_Float longitude;
    SRM_Long_Float latitude;
    SRM_Long_Float ellipsoidal_height;
} SRM_CD_3D_Coordinate;


/*!
 * STRUCT: SRM_CD_Surface_Coordinate
 *
 *   This non-object data type specifies the surface coordinate-components for
 *   SRFT CELESTIODETIC.
 */
typedef struct
{
    SRM_Long_Float longitude;
    SRM_Long_Float latitude;
} SRM_CD_Surface_Coordinate;


/*!
 * REGISTERABLE ENUM: SRM_Spatial_Coordinate_Code
 *
 *  Used as the tag in the SRM_Coordinate tagged union structure
 */
typedef SRM_Integer SRM_Spatial_Coordinate_Code;

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_CC_3D
 */
#define SRM_SPACOORDCOD_CC_3D ((SRM_Spatial_Coordinate_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_CD_3D
 */
#define SRM_SPACOORDCOD_CD_3D ((SRM_Spatial_Coordinate_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_CD_SURFACE
 */
#define SRM_SPACOORDCOD_CD_SURFACE ((SRM_Spatial_Coordinate_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_CM_3D
 */
#define SRM_SPACOORDCOD_CM_3D ((SRM_Spatial_Coordinate_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_EC_AUGMENTED_3D
 */
#define SRM_SPACOORDCOD_EC_AUGMENTED_3D ((SRM_Spatial_Coordinate_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_EC_SURFACE
 */
#define SRM_SPACOORDCOD_EC_SURFACE ((SRM_Spatial_Coordinate_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_EI_3D
 */
#define SRM_SPACOORDCOD_EI_3D ((SRM_Spatial_Coordinate_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_HAEC_3D
 */
#define SRM_SPACOORDCOD_HAEC_3D ((SRM_Spatial_Coordinate_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_HEEC_3D
 */
#define SRM_SPACOORDCOD_HEEC_3D ((SRM_Spatial_Coordinate_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_HEEQ_3D
 */
#define SRM_SPACOORDCOD_HEEQ_3D ((SRM_Spatial_Coordinate_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LCC_AUGMENTED_3D
 */
#define SRM_SPACOORDCOD_LCC_AUGMENTED_3D ((SRM_Spatial_Coordinate_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LCC_SURFACE
 */
#define SRM_SPACOORDCOD_LCC_SURFACE ((SRM_Spatial_Coordinate_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LSA_2D
 */
#define SRM_SPACOORDCOD_LSA_2D ((SRM_Spatial_Coordinate_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LSP_2D
 */
#define SRM_SPACOORDCOD_LSP_2D ((SRM_Spatial_Coordinate_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LSR_2D
 */
#define SRM_SPACOORDCOD_LSR_2D ((SRM_Spatial_Coordinate_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LSR_3D
 */
#define SRM_SPACOORDCOD_LSR_3D ((SRM_Spatial_Coordinate_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LCE_3D
 */
#define SRM_SPACOORDCOD_LCE_3D ((SRM_Spatial_Coordinate_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LTSAS_3D
 */
#define SRM_SPACOORDCOD_LTSAS_3D ((SRM_Spatial_Coordinate_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LTSAS_SURFACE
 */
#define SRM_SPACOORDCOD_LTSAS_SURFACE ((SRM_Spatial_Coordinate_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LTSC_3D
 */
#define SRM_SPACOORDCOD_LTSC_3D ((SRM_Spatial_Coordinate_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LTSC_SURFACE
 */
#define SRM_SPACOORDCOD_LTSC_SURFACE ((SRM_Spatial_Coordinate_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LTSE_3D
 */
#define SRM_SPACOORDCOD_LTSE_3D ((SRM_Spatial_Coordinate_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_LTSE_SURFACE
 */
#define SRM_SPACOORDCOD_LTSE_SURFACE ((SRM_Spatial_Coordinate_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_M_AUGMENTED_3D
 */
#define SRM_SPACOORDCOD_M_AUGMENTED_3D ((SRM_Spatial_Coordinate_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_M_SURFACE
 */
#define SRM_SPACOORDCOD_M_SURFACE ((SRM_Spatial_Coordinate_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_OMS_AUGMENTED_3D
 */
#define SRM_SPACOORDCOD_OMS_AUGMENTED_3D ((SRM_Spatial_Coordinate_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_OMS_SURFACE
 */
#define SRM_SPACOORDCOD_OMS_SURFACE ((SRM_Spatial_Coordinate_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_PD_3D
 */
#define SRM_SPACOORDCOD_PD_3D ((SRM_Spatial_Coordinate_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_PD_SURFACE
 */
#define SRM_SPACOORDCOD_PD_SURFACE ((SRM_Spatial_Coordinate_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_PS_AUGMENTED_3D
 */
#define SRM_SPACOORDCOD_PS_AUGMENTED_3D ((SRM_Spatial_Coordinate_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_PS_SURFACE
 */
#define SRM_SPACOORDCOD_PS_SURFACE ((SRM_Spatial_Coordinate_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_SEC_3D
 */
#define SRM_SPACOORDCOD_SEC_3D ((SRM_Spatial_Coordinate_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_SEQ_3D
 */
#define SRM_SPACOORDCOD_SEQ_3D ((SRM_Spatial_Coordinate_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_SMD_3D
 */
#define SRM_SPACOORDCOD_SMD_3D ((SRM_Spatial_Coordinate_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_SME_3D
 */
#define SRM_SPACOORDCOD_SME_3D ((SRM_Spatial_Coordinate_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_TM_AUGMENTED_3D
 */
#define SRM_SPACOORDCOD_TM_AUGMENTED_3D ((SRM_Spatial_Coordinate_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_SPACOORDCOD_TM_SURFACE
 */
#define SRM_SPACOORDCOD_TM_SURFACE ((SRM_Spatial_Coordinate_Code)37)


/*! Upper Bound value for Spatial_Coordinate_Codes */
#define SRM_SPATIAL_COORDINATE_CODE_UBOUND 37


/*!
 * STRUCT: SRM_Euclidean_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   Euclidean space SRFTs.
 */
typedef struct
{
    SRM_Long_Float u;
    SRM_Long_Float v;
    SRM_Long_Float w;
} SRM_Euclidean_3D_Coordinate;


/*!
 * STRUCT: SRM_Spherical_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   spherical SRFTs.
 */
typedef struct
{
    SRM_Long_Float longitude;
    SRM_Long_Float latitude;
    SRM_Long_Float radius;
} SRM_Spherical_3D_Coordinate;


/*!
 * STRUCT: SRM_Map_Projection_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   map projection SRFTs.
 */
typedef struct
{
    SRM_Long_Float easting;
    SRM_Long_Float northing;
    SRM_Long_Float ellipsoidal_height;
} SRM_Map_Projection_3D_Coordinate;


/*!
 * STRUCT: SRM_Map_Projection_Surface_Coordinate
 *
 *   This non-object data type specifies the surface coordinate-components for
 *   map projection SRFTs.
 */
typedef struct
{
    SRM_Long_Float easting;
    SRM_Long_Float northing;
} SRM_Map_Projection_Surface_Coordinate;


/*!
 * STRUCT: SRM_EI_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   SRFT EQUATORIAL_INERTIAL.
 */
typedef struct
{
    SRM_Long_Float right_ascension;
    SRM_Long_Float declination;
    SRM_Long_Float radius;
} SRM_EI_3D_Coordinate;


/*!
 * STRUCT: SRM_LSA_2D_Coordinate
 *
 *   This non-object data type specifies the 2D coordinate-components for
 *   SRFT LOCAL_SPACE_AZIMUTHAL_2D.
 */
typedef struct
{
    SRM_Long_Float azimuth;
    SRM_Long_Float radius;
} SRM_LSA_2D_Coordinate;


/*!
 * STRUCT: SRM_LSP_2D_Coordinate
 *
 *   This non-object data type specifies the 2D coordinate-components for
 *   SRFT LOCAL_SPACE_POLAR_2D.
 */
typedef struct
{
    SRM_Long_Float angle;
    SRM_Long_Float radius;
} SRM_LSP_2D_Coordinate;


/*!
 * STRUCT: SRM_Euclidean_2D_Coordinate
 *
 *   This non-object data type specifies the 2D coordinate-components for
 *   Euclidean space SRFTs.
 */
typedef struct
{
    SRM_Long_Float u;
    SRM_Long_Float v;
} SRM_Euclidean_2D_Coordinate;


/*!
 * STRUCT: SRM_LTSAS_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   SRFT LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL.
 */
typedef struct
{
    SRM_Long_Float azimuth;
    SRM_Long_Float angle;
    SRM_Long_Float radius;
} SRM_LTSAS_3D_Coordinate;


/*!
 * STRUCT: SRM_LTSAS_Surface_Coordinate
 *
 *   This non-object data type specifies the surface coordinate-components for
 *   SRFT LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL.
 */
typedef struct
{
    SRM_Long_Float azimuth;
    SRM_Long_Float angle;
} SRM_LTSAS_Surface_Coordinate;


/*!
 * STRUCT: SRM_LTSC_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   SRFT LOCAL_TANGENT_SPACE_CYLINDRICAL.
 */
typedef struct
{
    SRM_Long_Float angle;
    SRM_Long_Float radius;
    SRM_Long_Float height;
} SRM_LTSC_3D_Coordinate;


/*!
 * STRUCT: SRM_LTSC_Surface_Coordinate
 *
 *   This non-object data type specifies the surface coordinate-components for
 *   SRFT LOCAL_TANGENT_SPACE_CYLINDRICAL.
 */
typedef struct
{
    SRM_Long_Float angle;
    SRM_Long_Float radius;
} SRM_LTSC_Surface_Coordinate;


/*!
 * STRUCT: SRM_LTSE_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   SRFT LOCAL_TANGENT_SPACE_EUCLIDEAN.
 */
typedef struct
{
    SRM_Long_Float x;
    SRM_Long_Float y;
    SRM_Long_Float height;
} SRM_LTSE_3D_Coordinate;


/*!
 * STRUCT: SRM_LTSE_Surface_Coordinate
 *
 *   This non-object data type specifies the surface coordinate-components for
 *   SRFT LOCAL_TANGENT_SPACE_EUCLIDEAN.
 */
typedef struct
{
    SRM_Long_Float x;
    SRM_Long_Float y;
} SRM_LTSE_Surface_Coordinate;


/*!
 * STRUCT: SRM_PD_3D_Coordinate
 *
 *   This non-object data type specifies the 3D coordinate-components for
 *   SRFT PLANETODETIC.
 */
typedef struct
{
    SRM_Long_Float longitude;
    SRM_Long_Float latitude;
    SRM_Long_Float ellipsoidal_height;
} SRM_PD_3D_Coordinate;


/*!
 * STRUCT: SRM_PD_Surface_Coordinate
 *
 *   This non-object data type specifies the surface coordinate-components for
 *   SRFT PLANETODETIC.
 */
typedef struct
{
    SRM_Long_Float longitude;
    SRM_Long_Float latitude;
} SRM_PD_Surface_Coordinate;


/*!
 * STRUCT: SRM_Coordinate
 *
 *  A tagged union structure used to store the values for an
 *  individual coordinate.
 */
typedef struct
{
    SRM_Spatial_Coordinate_Code spatial_coord_code;
    union _SRM_Coordinate_Union
    {
        SRM_Euclidean_3D_Coordinate           cc_3d;
        SRM_CD_3D_Coordinate                  cd_3d;
        SRM_CD_Surface_Coordinate             cd_surface;
        SRM_Spherical_3D_Coordinate           cm_3d;
        SRM_Map_Projection_3D_Coordinate      ec_aug_3d;
        SRM_Map_Projection_Surface_Coordinate ec_surface;
        SRM_EI_3D_Coordinate                  ei_3d;
        SRM_Spherical_3D_Coordinate           haec_3d;
        SRM_Spherical_3D_Coordinate           heec_3d;
        SRM_Spherical_3D_Coordinate           heeq_3d;
        SRM_Map_Projection_3D_Coordinate      lcc_aug_3d;
        SRM_Map_Projection_Surface_Coordinate lcc_surface;
        SRM_Euclidean_3D_Coordinate           lce_3d;
        SRM_LSA_2D_Coordinate                 lsa_2d;
        SRM_LSP_2D_Coordinate                 lsp_2d;
        SRM_Euclidean_2D_Coordinate           lsr_2d;
        SRM_Euclidean_3D_Coordinate           lsr_3d;
        SRM_LTSAS_3D_Coordinate               ltsas_3d;
        SRM_LTSAS_Surface_Coordinate          ltsas_surface;
        SRM_LTSC_3D_Coordinate                ltsc_3d;
        SRM_LTSC_Surface_Coordinate           ltsc_surface;
        SRM_LTSE_3D_Coordinate                ltse_3d;
        SRM_LTSE_Surface_Coordinate           ltse_surface;
        SRM_Map_Projection_3D_Coordinate      m_aug_3d;
        SRM_Map_Projection_Surface_Coordinate m_surface;
        SRM_Map_Projection_3D_Coordinate      oms_aug_3d;
        SRM_Map_Projection_Surface_Coordinate oms_surface;
        SRM_PD_3D_Coordinate                  pd_3d;
        SRM_PD_Surface_Coordinate             pd_surface;
        SRM_Map_Projection_3D_Coordinate      ps_aug_3d;
        SRM_Map_Projection_Surface_Coordinate ps_surface;
        SRM_Spherical_3D_Coordinate           sec_3d;
        SRM_Spherical_3D_Coordinate           seq_3d;
        SRM_Spherical_3D_Coordinate           smd_3d;
        SRM_Spherical_3D_Coordinate           sme_3d;
        SRM_Map_Projection_3D_Coordinate      tm_aug_3d;
        SRM_Map_Projection_Surface_Coordinate tm_surface;
    } coordinate;
} SRM_Coordinate;


/*!
 * ENUM: SRM_Coordinate_Valid_Region
 *
 *  This data type represents coordinate location with respect to valid regions.
 */
typedef enum
{
    SRM_COORDVALRGN_VALID,
   /*
    * VALID denotes a coordinate that is contained in the valid region and in
    * the CS domain.
    */

    SRM_COORDVALRGN_EXTENDED_VALID,
   /*
    * EXTENDED_VALID denotes a coordinate that is contained in the
    * extended valid region and in the CS domain but not in the valid region.
    */

    SRM_COORDVALRGN_DEFINED
   /*
    * DEFINED denotes a coordinate that is contained in the CS domain but not
    * in the valid or the extended valid regions.
    */
} SRM_Coordinate_Valid_Region;


/*!
 * STRUCT: SRM_Coordinate_Valid_Region_Array
 *
 *  This data type specifies an array of SRM_Coordinate_Valid_Region variables.
 */
typedef struct
{
    SRM_Integer                  length;
    SRM_Coordinate_Valid_Region *valid_region_array;
} SRM_Coordinate_Valid_Region_Array;


/*!
 * TYPEDEF: SRM_Object_Reference
 *
 *  An Object_Reference is an opaque non-object data type
 *  that allows an application to reliably access an instance
 *  of an object. Object_References may be compared for
 *  equality and tested to see if they are equal to the
 *  special value NULL_Object. If two Object_References are
 *  equal, they refer to the same object instance. In all
 *  the method specifications in the API clause of
 *  18026, whenever an argument passed to or returned from a
 *  method is an object, it is an object reference that is
 *  passed.
 */
typedef void *SRM_Object_Reference;


/*!
 * STRUCT: SRM_Coordinate2D_Array
 *
 *  Array of 2D coordinate object references.
 */
typedef struct
{
    SRM_Integer           length;
    SRM_Object_Reference *coordinate2D_array;
} SRM_Coordinate2D_Array;


/*!
 * STRUCT: SRM_Coordinate3D_Array
 *
 *  Array of 3D coordinate object references.
 */
typedef struct
{
    SRM_Integer           length;
    SRM_Object_Reference *coordinate3D_array;
} SRM_Coordinate3D_Array;


/*!
 * REGISTERABLE ENUM: SRM_CS_Code
 *
 *  The SRM_Integer code data type SRM_CS_Code specifies a CS by its code as
 *  defined in Clause 5 of 18026 or by registration.
 */
typedef SRM_Integer SRM_CS_Code;

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_UNSPECIFIED
 */
#define SRM_CSCOD_UNSPECIFIED ((SRM_CS_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_EUCLIDEAN_3D
 *
 *  Euclidean 3D.
 */
#define SRM_CSCOD_EUCLIDEAN_3D ((SRM_CS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D
 *
 *  Localized Euclidean 3D
 */
#define SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D ((SRM_CS_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_SPHERICAL
 *
 *  Spherical.
 */
#define SRM_CSCOD_SPHERICAL ((SRM_CS_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_SPHERICAL
 *
 *  Localized spherical
 */
#define SRM_CSCOD_LOCOCENTRIC_SPHERICAL ((SRM_CS_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_AZIMUTHAL_SPHERICAL
 *
 *  Azimuthal spherical.
 */
#define SRM_CSCOD_AZIMUTHAL_SPHERICAL ((SRM_CS_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL_SPHERICAL
 *
 *  Localized azimuthal spherical.
 */
#define SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL_SPHERICAL ((SRM_CS_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_GEODETIC
 *
 *  Geodetic 3D.
 */
#define SRM_CSCOD_GEODETIC ((SRM_CS_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_PLANETODETIC
 *
 *  Planetodetic 3D. Geodetic 3D with longitude in opposite direction.
 */
#define SRM_CSCOD_PLANETODETIC ((SRM_CS_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_CYLINDRICAL
 *
 *  Cylindrical.
 */
#define SRM_CSCOD_CYLINDRICAL ((SRM_CS_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_CYLINDRICAL
 *
 *  Localized cylindrical.
 */
#define SRM_CSCOD_LOCOCENTRIC_CYLINDRICAL ((SRM_CS_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_MERCATOR
 *
 *  Mercator and augmented Mercator map projection coordinate systems.
 */
#define SRM_CSCOD_MERCATOR ((SRM_CS_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_OBLIQUE_MERCATOR_SPHERICAL
 *
 *  Oblique Mercator and augmented oblique Mercator map projections of a
 *  sphere.
 */
#define SRM_CSCOD_OBLIQUE_MERCATOR_SPHERICAL ((SRM_CS_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_TRANSVERSE_MERCATOR
 *
 *  Transverse Mercator and augmented transverse Mercator map projections.
 */
#define SRM_CSCOD_TRANSVERSE_MERCATOR ((SRM_CS_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LAMBERT_CONFORMAL_CONIC
 *
 *  Lambert conformal conic and augmented Lambert conformal conic map
 *  projections.
 */
#define SRM_CSCOD_LAMBERT_CONFORMAL_CONIC ((SRM_CS_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_POLAR_STEREOGRAPHIC
 *
 *  Polar stereographic and augmented polar stereographic map projections.
 */
#define SRM_CSCOD_POLAR_STEREOGRAPHIC ((SRM_CS_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_EQUIDISTANT_CYLINDRICAL
 *
 *  Equidistant cylindrical and augmented equidistant cylindrical map
 *  projections.
 */
#define SRM_CSCOD_EQUIDISTANT_CYLINDRICAL ((SRM_CS_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_SURFACE_GEODETIC
 *
 *  Surface geodetic.
 */
#define SRM_CSCOD_SURFACE_GEODETIC ((SRM_CS_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_SURFACE_PLANETODETIC
 *
 *  Surface planetodetic. Surface geodetic with longitude in opposite
 *  direction.
 */
#define SRM_CSCOD_SURFACE_PLANETODETIC ((SRM_CS_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_SURFACE_EUCLIDEAN
 *
 *  Localization of Euclidean 2D CS into plane surface in 3D
 *  position-space.
 */
#define SRM_CSCOD_LOCOCENTRIC_SURFACE_EUCLIDEAN ((SRM_CS_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_SURFACE_AZIMUTHAL
 *
 *  Localization of azimuthal CS into plane surface in 3D position-space.
 */
#define SRM_CSCOD_LOCOCENTRIC_SURFACE_AZIMUTHAL ((SRM_CS_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_SURFACE_POLAR
 *
 *  Localization of polar CS into plane surface in 3D position-space.
 */
#define SRM_CSCOD_LOCOCENTRIC_SURFACE_POLAR ((SRM_CS_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_EUCLIDEAN_2D
 *
 *  Euclidean 2D.
 */
#define SRM_CSCOD_EUCLIDEAN_2D ((SRM_CS_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_2D
 *
 *  Localized Euclidean 2D
 */
#define SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_2D ((SRM_CS_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_AZIMUTHAL
 *
 *  Azimuthal coordinate system.
 */
#define SRM_CSCOD_AZIMUTHAL ((SRM_CS_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL
 *
 *  Localization of azimuthal CS.
 */
#define SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL ((SRM_CS_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_POLAR
 *
 *  Polar coordinate system.
 */
#define SRM_CSCOD_POLAR ((SRM_CS_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_LOCOCENTRIC_POLAR
 *
 *  Localized polar.
 */
#define SRM_CSCOD_LOCOCENTRIC_POLAR ((SRM_CS_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_CSCOD_EUCLIDEAN_1D
 *
 *  Euclidean 1D.
 */
#define SRM_CSCOD_EUCLIDEAN_1D ((SRM_CS_Code)28)


/*! Upper Bound value for CS_Codes */
#define SRM_CS_CODE_UBOUND 28


/*!
 * STRUCT: SRM_Direction_Array
 *
 *   This data type specifies an array of Direction objects.
 */
typedef struct
{
    SRM_Integer           length;
    SRM_Object_Reference *direction_array;
} SRM_Direction_Array;


/*!
 * REGISTERABLE ENUM: SRM_DSS_Code
 *
 *  Designated Spatial Surface Specification Codes
 */
typedef SRM_Integer SRM_DSS_Code;

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_UNSPECIFIED
 */
#define SRM_DSSCOD_UNSPECIFIED ((SRM_DSS_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_EGM96_GEOID
 *
 *  WGS 84 EGM 96 geoid
 */
#define SRM_DSSCOD_EGM96_GEOID ((SRM_DSS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_IGLD_1955
 *
 *  International Great Lakes datum (IGLD) 1955
 */
#define SRM_DSSCOD_IGLD_1955 ((SRM_DSS_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_IGLD_1985
 *
 *  International Great Lakes datum (IGLD) 1985
 */
#define SRM_DSSCOD_IGLD_1985 ((SRM_DSS_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_MSL
 *
 *  Mean sea level (MSL)
 */
#define SRM_DSSCOD_MSL ((SRM_DSS_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_NAVD_1988
 *
 *  North American vertical datum (NAVD) 1988
 */
#define SRM_DSSCOD_NAVD_1988 ((SRM_DSS_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_NGVD_1929
 *
 *  National Geodetic Vertical Datum (NGVD) 1929
 */
#define SRM_DSSCOD_NGVD_1929 ((SRM_DSS_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_OSGM_2002
 *
 *  Ordnance survey geoid model (OSGM) 2002
 */
#define SRM_DSSCOD_OSGM_2002 ((SRM_DSS_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_WGS84_ELLIPSOID
 *
 *  WGS 84 ellipsoid
 */
#define SRM_DSSCOD_WGS84_ELLIPSOID ((SRM_DSS_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_DSSCOD_EGM84_GEOID
 *
 *  WGS 84 EGM 84 geoid
 */
#define SRM_DSSCOD_EGM84_GEOID ((SRM_DSS_Code)9)


/*! Upper Bound value for DSS_Codes */
#define SRM_DSS_CODE_UBOUND 9


/*!
 * STRUCT: SRM_EC_Parameters
 *
 *  Equidistant Cylindrical (EC) Parameters are used as a means
 *  of specifying the EC spatial coordinate systems
 */
typedef struct
{
    SRM_Long_Float origin_longitude;
    SRM_Long_Float central_scale;
    SRM_Long_Float false_easting;
    SRM_Long_Float false_northing;
} SRM_EC_Parameters;


/*!
 * ENUM: SRM_Interval_Type
 *
 *  This data type is used to specify coordinate component intervals in the
 *  SetValidRegion, SetExtendedValidRegion, GetValidRegion, and
 *  GetExtendedValidRegion methods of class BaseSRF3D and in the
 *  SetValidGeodeticRegion and GetExtendedValidGeodeticRegion methods of
 *  class BaseSRFMapProjection.
 */
typedef enum
{
    SRM_IVLTYP_OPEN_INTERVAL,
   /*
    * The bounded open interval (a, b).
    */

    SRM_IVLTYP_GE_LT_INTERVAL,
   /*
    * The bounded interval [a, b).
    */

    SRM_IVLTYP_GT_LE_INTERVAL,
   /*
    * The bounded interval (a, b].
    */

    SRM_IVLTYP_CLOSED_INTERVAL,
   /*
    * The bounded interval [a, b].
    */

    SRM_IVLTYP_GT_SEMI_INTERVAL,
   /*
    * The unbounded interval (a, +infinity).
    */

    SRM_IVLTYP_GE_SEMI_INTERVAL,
   /*
    * The unbounded interval [a, +infinity).
    */

    SRM_IVLTYP_LT_SEMI_INTERVAL,
   /*
    * The unbounded interval (-infinity, b).
    */

    SRM_IVLTYP_LE_SEMI_INTERVAL,
   /*
    * The unbounded interval (-infinity, b].
    */

    SRM_IVLTYP_UNBOUNDED
   /*
    * All values (-infinity, +infinity).
    */
} SRM_Interval_Type;


/*!
 * STRUCT: SRM_LCC_Parameters
 *
 *  Lambert Conformal Conic (LCC) Parameters are used as a means of
 *  specifying the LCC spatial coordinate systems
 */
typedef struct
{
    SRM_Long_Float origin_longitude;
    SRM_Long_Float origin_latitude;
    SRM_Long_Float latitude1;
    SRM_Long_Float latitude2;
    SRM_Long_Float false_easting;
    SRM_Long_Float false_northing;
} SRM_LCC_Parameters;


/*!
 * TYPEDEF: SRM_Vector_3D
 *
 *   This data type specifies an array of three SRM_Long_Float variables
 *   representing a vector in 3D Euclidean space.
 */
typedef SRM_Long_Float SRM_Vector_3D[3];


/*!
 * STRUCT: SRM_LCE_3D_Parameters
 *
 *  Lococentric Euclidean 3D Parameters are used as a means of
 *  specifying the LCE 3D spatial coordinate systems
 */
typedef struct
{
    SRM_Vector_3D lococentre;
    SRM_Vector_3D primary_axis;
    SRM_Vector_3D secondary_axis;
} SRM_LCE_3D_Parameters;


/*!
 * STRUCT: SRM_Local_Tangent_Parameters
 *
 *  Local Tangent (LT) Parameters are used as a means of
 *  specifying the LT spatial coordinate systems
 */
typedef struct
{
    SRM_Long_Float geodetic_longitude;
    SRM_Long_Float geodetic_latitude;
    SRM_Long_Float azimuth;
    SRM_Long_Float height_offset;
} SRM_Local_Tangent_Parameters;


/*!
 * STRUCT: SRM_LSR_2D_Parameters
 *
 *  Local Space Rectangular (LSR) Parameters are used as a means of
 *  specifying the LSR spatial coordinate systems
 */
typedef struct
{
    SRM_Axis_Direction forward_direction;
} SRM_LSR_2D_Parameters;


/*!
 * STRUCT: SRM_LSR_3D_Parameters
 *
 *  Local Space Rectangular (LSR) Parameters are used as a means of
 *  specifying the LSR spatial coordinate systems
 */
typedef struct
{
    SRM_Axis_Direction forward_direction;
    SRM_Axis_Direction up_direction;
} SRM_LSR_3D_Parameters;


/*!
 * STRUCT: SRM_LTSE_Parameters
 *
 *  Local Tangent Space Euclidean (LTSE) Parameters are used as a means of
 *  specifying the LTSE spatial coordinate systems
 */
typedef struct
{
    SRM_Long_Float geodetic_longitude;
    SRM_Long_Float geodetic_latitude;
    SRM_Long_Float azimuth;
    SRM_Long_Float x_false_origin;
    SRM_Long_Float y_false_origin;
    SRM_Long_Float height_offset;
} SRM_LTSE_Parameters;


/*!
 * STRUCT: SRM_M_Parameters
 *
 *  Mercator (M) Parameters are used as a means of
 *  specifying the M spatial coordinate systems
 */
typedef struct
{
    SRM_Long_Float origin_longitude;
    SRM_Long_Float central_scale;
    SRM_Long_Float false_easting;
    SRM_Long_Float false_northing;
} SRM_M_Parameters;


/*!
 * TYPEDEF: SRM_Matrix_3x3
 *
 *   This data type specifies a two-dimensional array of nine SRM_Long_Float
 *   variables representing a 3x3 matrix.
 */
typedef SRM_Long_Float SRM_Matrix_3x3[3][3];


/*!
 * TYPEDEF: SRM_Matrix_4x4
 *
 *   This data type specifies a two-dimensional array of sixteen SRM_Long_Float
 *   variables representing a 4x4 matrix.
 */
typedef SRM_Long_Float SRM_Matrix_4x4[4][4];


/*!
 * STRUCT: SRM_Oblique_Mercator_Parameters
 *
 *  Oblique Mercator (OM) Parameters are used as a means of
 *  specifying the OM spatial coordinate systems
 */
typedef struct
{
    SRM_Long_Float longitude1;
    SRM_Long_Float latitude1;
    SRM_Long_Float longitude2;
    SRM_Long_Float latitude2;
    SRM_Long_Float central_scale;
    SRM_Long_Float false_easting;
    SRM_Long_Float false_northing;
} SRM_Oblique_Mercator_Parameters;


/*!
 * REGISTERABLE ENUM: SRM_ORM_Code
 *
 *  ORM Codes
 */
typedef SRM_Integer SRM_ORM_Code;

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE
 *
 *  Added for the NGA Golden Data testing.
 */
#define SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE ((SRM_ORM_Code)-1001)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EXPERIMENTAL_NGA_MAX
 *
 *  Added for the NGA Golden Data testing.
 */
#define SRM_ORMCOD_EXPERIMENTAL_NGA_MAX ((SRM_ORM_Code)-1000)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_UNSPECIFIED
 */
#define SRM_ORMCOD_UNSPECIFIED ((SRM_ORM_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ABSTRACT_2D
 *
 *  2D modelling space
 */
#define SRM_ORMCOD_ABSTRACT_2D ((SRM_ORM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ABSTRACT_3D
 *
 *  3D modelling space
 */
#define SRM_ORMCOD_ABSTRACT_3D ((SRM_ORM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ADINDAN_1991
 *
 *  Adindan
 */
#define SRM_ORMCOD_ADINDAN_1991 ((SRM_ORM_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ADRASTEA_2000
 *
 *  Adrastea
 */
#define SRM_ORMCOD_ADRASTEA_2000 ((SRM_ORM_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_AFGOOYE_1987
 *
 *  Afgooye (Somalia)
 */
#define SRM_ORMCOD_AFGOOYE_1987 ((SRM_ORM_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_AIN_EL_ABD_1970
 *
 *  Ain el Abd
 */
#define SRM_ORMCOD_AIN_EL_ABD_1970 ((SRM_ORM_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_AMALTHEA_2000
 *
 *  Amalthea
 */
#define SRM_ORMCOD_AMALTHEA_2000 ((SRM_ORM_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_AMERICAN_SAMOA_1962
 *
 *  American Samoa
 */
#define SRM_ORMCOD_AMERICAN_SAMOA_1962 ((SRM_ORM_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ANNA_1_1965
 *
 *  Anna 1 (astronomic)
 */
#define SRM_ORMCOD_ANNA_1_1965 ((SRM_ORM_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ANTIGUA_1943
 *
 *  Antigua (astronomic)
 */
#define SRM_ORMCOD_ANTIGUA_1943 ((SRM_ORM_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ARC_1950
 *
 *  Arc
 */
#define SRM_ORMCOD_ARC_1950 ((SRM_ORM_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ARC_1960
 *
 *  Arc
 */
#define SRM_ORMCOD_ARC_1960 ((SRM_ORM_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ARIEL_1988
 *
 *  Ariel
 */
#define SRM_ORMCOD_ARIEL_1988 ((SRM_ORM_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ASCENSION_1958
 *
 *  Ascension
 */
#define SRM_ORMCOD_ASCENSION_1958 ((SRM_ORM_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ATLAS_1988
 *
 *  Atlas
 */
#define SRM_ORMCOD_ATLAS_1988 ((SRM_ORM_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_AUSTRALIAN_GEOD_1966
 *
 *  Australian Geodetic
 */
#define SRM_ORMCOD_AUSTRALIAN_GEOD_1966 ((SRM_ORM_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_AUSTRALIAN_GEOD_1984
 *
 *  Australian Geodetic
 */
#define SRM_ORMCOD_AUSTRALIAN_GEOD_1984 ((SRM_ORM_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991
 *
 *  Ayabelle Lighthouse (Djibouti)
 */
#define SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991 ((SRM_ORM_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BEACON_E_1945
 *
 *  Beacon E (Iwo-jima; astronomic)
 */
#define SRM_ORMCOD_BEACON_E_1945 ((SRM_ORM_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BELINDA_1988
 *
 *  Belinda
 */
#define SRM_ORMCOD_BELINDA_1988 ((SRM_ORM_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BELLEVUE_IGN_1987
 *
 *  Bellevue (IGN)
 */
#define SRM_ORMCOD_BELLEVUE_IGN_1987 ((SRM_ORM_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BERMUDA_1957
 *
 *  Bermuda
 */
#define SRM_ORMCOD_BERMUDA_1957 ((SRM_ORM_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BIANCA_1988
 *
 *  Bianca
 */
#define SRM_ORMCOD_BIANCA_1988 ((SRM_ORM_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BISSAU_1991
 *
 *  Bissau
 */
#define SRM_ORMCOD_BISSAU_1991 ((SRM_ORM_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BOGOTA_OBS_1987
 *
 *  Bogota Observatory
 */
#define SRM_ORMCOD_BOGOTA_OBS_1987 ((SRM_ORM_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA
 *
 *  Bogota Observatory (with the Prime Meridian at Bogota)
 */
#define SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA ((SRM_ORM_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_BUKIT_RIMPAH_1987
 *
 *  Bukit Rimpah
 */
#define SRM_ORMCOD_BUKIT_RIMPAH_1987 ((SRM_ORM_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CALLISTO_2000
 *
 *  Callisto
 */
#define SRM_ORMCOD_CALLISTO_2000 ((SRM_ORM_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CALYPSO_1988
 *
 *  Calypso
 */
#define SRM_ORMCOD_CALYPSO_1988 ((SRM_ORM_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CAMP_AREA_1987
 *
 *  Camp Area (astronomic)
 */
#define SRM_ORMCOD_CAMP_AREA_1987 ((SRM_ORM_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CAMPO_INCHAUSPE_1969
 *
 *  Campo Inchauspe
 */
#define SRM_ORMCOD_CAMPO_INCHAUSPE_1969 ((SRM_ORM_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CANTON_1966
 *
 *  Canton (astronomic)
 */
#define SRM_ORMCOD_CANTON_1966 ((SRM_ORM_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CAPE_1987
 *
 *  Cape
 */
#define SRM_ORMCOD_CAPE_1987 ((SRM_ORM_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CAPE_CANAVERAL_1991
 *
 *  Cape Canaveral
 */
#define SRM_ORMCOD_CAPE_CANAVERAL_1991 ((SRM_ORM_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CARTHAGE_1987
 *
 *  Carthage
 */
#define SRM_ORMCOD_CARTHAGE_1987 ((SRM_ORM_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CHARON_1991
 *
 *  Charon
 */
#define SRM_ORMCOD_CHARON_1991 ((SRM_ORM_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CHATHAM_1971
 *
 *  Chatam (astronomic)
 */
#define SRM_ORMCOD_CHATHAM_1971 ((SRM_ORM_Code)37)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CHUA_1987
 *
 *  Chua (astronomic)
 */
#define SRM_ORMCOD_CHUA_1987 ((SRM_ORM_Code)38)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_COAMPS_1998
 *
 *  COAMPS^(TM)
 */
#define SRM_ORMCOD_COAMPS_1998 ((SRM_ORM_Code)39)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CORDELIA_1988
 *
 *  Cordelia
 */
#define SRM_ORMCOD_CORDELIA_1988 ((SRM_ORM_Code)40)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CORREGO_ALEGRE_1987
 *
 *  Corrego Alegre
 */
#define SRM_ORMCOD_CORREGO_ALEGRE_1987 ((SRM_ORM_Code)41)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_CRESSIDA_1988
 *
 *  Cressida
 */
#define SRM_ORMCOD_CRESSIDA_1988 ((SRM_ORM_Code)42)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DABOLA_1991
 *
 *  Dabola
 */
#define SRM_ORMCOD_DABOLA_1991 ((SRM_ORM_Code)43)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DECEPTION_1993
 *
 *  Deception
 */
#define SRM_ORMCOD_DECEPTION_1993 ((SRM_ORM_Code)44)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DEIMOS_1988
 *
 *  Deimos
 */
#define SRM_ORMCOD_DEIMOS_1988 ((SRM_ORM_Code)45)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DESDEMONA_1988
 *
 *  Desdemona
 */
#define SRM_ORMCOD_DESDEMONA_1988 ((SRM_ORM_Code)46)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DESPINA_1991
 *
 *  Despina
 */
#define SRM_ORMCOD_DESPINA_1991 ((SRM_ORM_Code)47)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DIONE_1982
 *
 *  Dione
 */
#define SRM_ORMCOD_DIONE_1982 ((SRM_ORM_Code)48)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DJAKARTA_1987
 *
 *  Djakarta (also known as Batavia)
 */
#define SRM_ORMCOD_DJAKARTA_1987 ((SRM_ORM_Code)49)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA
 *
 *  Djakarta (also known as Batavia; with the Prime Meridian at Djakarta)
 */
#define SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA ((SRM_ORM_Code)50)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DOS_1968
 *
 *  DOS
 */
#define SRM_ORMCOD_DOS_1968 ((SRM_ORM_Code)51)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_DOS_71_4_1987
 *
 *  DOS 71/4 (St. Helena Island; astronomic)
 */
#define SRM_ORMCOD_DOS_71_4_1987 ((SRM_ORM_Code)52)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950
 *
 *  Earth equatorial inertial, Aries mean of 1950
 */
#define SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950 ((SRM_ORM_Code)53)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE
 *
 *  Earth equatorial inertial, Aries true of date
 */
#define SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE ((SRM_ORM_Code)54)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EARTH_INERTIAL_J2000r0
 *
 *  Earth equatorial inertial, J2000.0
 */
#define SRM_ORMCOD_EARTH_INERTIAL_J2000r0 ((SRM_ORM_Code)55)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EARTH_SOLAR_ECLIPTIC
 *
 *  Solar ecliptic
 */
#define SRM_ORMCOD_EARTH_SOLAR_ECLIPTIC ((SRM_ORM_Code)56)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EARTH_SOLAR_EQUATORIAL
 *
 *  Solar equatorial
 */
#define SRM_ORMCOD_EARTH_SOLAR_EQUATORIAL ((SRM_ORM_Code)57)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EARTH_SOLAR_MAG_DIPOLE
 *
 *  Solar magnetic dipole
 */
#define SRM_ORMCOD_EARTH_SOLAR_MAG_DIPOLE ((SRM_ORM_Code)58)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EARTH_SOLAR_MAGNETOSPHERIC
 *
 *  Solar magnetospheric
 */
#define SRM_ORMCOD_EARTH_SOLAR_MAGNETOSPHERIC ((SRM_ORM_Code)59)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EASTER_1967
 *
 *  Easter
 */
#define SRM_ORMCOD_EASTER_1967 ((SRM_ORM_Code)60)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ENCELADUS_1994
 *
 *  Enceladus
 */
#define SRM_ORMCOD_ENCELADUS_1994 ((SRM_ORM_Code)61)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EPIMETHEUS_1988
 *
 *  Epimetheus
 */
#define SRM_ORMCOD_EPIMETHEUS_1988 ((SRM_ORM_Code)62)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EROS_2000
 *
 *  Eros (asteroid 433)
 */
#define SRM_ORMCOD_EROS_2000 ((SRM_ORM_Code)63)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ESTONIA_1937
 *
 *  Estonia
 */
#define SRM_ORMCOD_ESTONIA_1937 ((SRM_ORM_Code)64)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ETRS_1989
 *
 *  ETRS
 */
#define SRM_ORMCOD_ETRS_1989 ((SRM_ORM_Code)65)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EUROPA_2000
 *
 *  Europa
 */
#define SRM_ORMCOD_EUROPA_2000 ((SRM_ORM_Code)66)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EUROPE_1950
 *
 *  European
 */
#define SRM_ORMCOD_EUROPE_1950 ((SRM_ORM_Code)67)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_EUROPE_1979
 *
 *  European
 */
#define SRM_ORMCOD_EUROPE_1979 ((SRM_ORM_Code)68)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_FAHUD_1987
 *
 *  Fahud
 */
#define SRM_ORMCOD_FAHUD_1987 ((SRM_ORM_Code)69)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_FORT_THOMAS_1955
 *
 *  Fort Thomas
 */
#define SRM_ORMCOD_FORT_THOMAS_1955 ((SRM_ORM_Code)70)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GALATEA_1991
 *
 *  Galatea
 */
#define SRM_ORMCOD_GALATEA_1991 ((SRM_ORM_Code)71)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GAN_1970
 *
 *  Gan
 */
#define SRM_ORMCOD_GAN_1970 ((SRM_ORM_Code)72)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GANYMEDE_2000
 *
 *  Ganymede
 */
#define SRM_ORMCOD_GANYMEDE_2000 ((SRM_ORM_Code)73)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GASPRA_1991
 *
 *  Gaspra (asteroid 951)
 */
#define SRM_ORMCOD_GASPRA_1991 ((SRM_ORM_Code)74)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GDA_1994
 *
 *  GDA
 */
#define SRM_ORMCOD_GDA_1994 ((SRM_ORM_Code)75)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEODETIC_DATUM_1949
 *
 *  Geodetic Datum
 */
#define SRM_ORMCOD_GEODETIC_DATUM_1949 ((SRM_ORM_Code)76)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1945
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1945 ((SRM_ORM_Code)77)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1950
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1950 ((SRM_ORM_Code)78)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1955
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1955 ((SRM_ORM_Code)79)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1960
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1960 ((SRM_ORM_Code)80)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1965
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1965 ((SRM_ORM_Code)81)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1970
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1970 ((SRM_ORM_Code)82)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1975
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1975 ((SRM_ORM_Code)83)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1980
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1980 ((SRM_ORM_Code)84)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1985
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1985 ((SRM_ORM_Code)85)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1990
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1990 ((SRM_ORM_Code)86)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_1995
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_1995 ((SRM_ORM_Code)87)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GEOMAGNETIC_2000
 *
 *  Geomagnetic
 */
#define SRM_ORMCOD_GEOMAGNETIC_2000 ((SRM_ORM_Code)88)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GRACIOSA_BASE_SW_1948
 *
 *  Graciosa Base SW
 */
#define SRM_ORMCOD_GRACIOSA_BASE_SW_1948 ((SRM_ORM_Code)89)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GUAM_1963
 *
 *  Guam
 */
#define SRM_ORMCOD_GUAM_1963 ((SRM_ORM_Code)90)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GUNONG_SEGARA_1987
 *
 *  Gunung Segara
 */
#define SRM_ORMCOD_GUNONG_SEGARA_1987 ((SRM_ORM_Code)91)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_GUX_1_1987
 *
 *  GUX1 (astronomic)
 */
#define SRM_ORMCOD_GUX_1_1987 ((SRM_ORM_Code)92)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HELENE_1992
 *
 *  Helene
 */
#define SRM_ORMCOD_HELENE_1992 ((SRM_ORM_Code)93)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_J2000r0
 *
 *  Heliocentric Aries ecliptic, J2000.0
 */
#define SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_J2000r0 ((SRM_ORM_Code)94)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE
 *
 *  Heliocentric Aries ecliptic, true of date
 */
#define SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE ((SRM_ORM_Code)95)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HELIO_EARTH_ECLIPTIC
 *
 *  Heliocentric Earth ecliptic
 */
#define SRM_ORMCOD_HELIO_EARTH_ECLIPTIC ((SRM_ORM_Code)96)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HELIO_EARTH_EQUATORIAL
 *
 *  Heliocentric Earth equatorial
 */
#define SRM_ORMCOD_HELIO_EARTH_EQUATORIAL ((SRM_ORM_Code)97)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HERAT_NORTH_1987
 *
 *  Herat North
 */
#define SRM_ORMCOD_HERAT_NORTH_1987 ((SRM_ORM_Code)98)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HERMANNSKOGEL_1871
 *
 *  Hermannskogel
 */
#define SRM_ORMCOD_HERMANNSKOGEL_1871 ((SRM_ORM_Code)99)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HJORSEY_1955
 *
 *  Hjorsey
 */
#define SRM_ORMCOD_HJORSEY_1955 ((SRM_ORM_Code)100)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HONG_KONG_1963
 *
 *  Hong Kong
 */
#define SRM_ORMCOD_HONG_KONG_1963 ((SRM_ORM_Code)101)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_HU_TZU_SHAN_1991
 *
 *  Hu-Tzu-Shan
 */
#define SRM_ORMCOD_HU_TZU_SHAN_1991 ((SRM_ORM_Code)102)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_IAPETUS_1988
 *
 *  Iapetus
 */
#define SRM_ORMCOD_IAPETUS_1988 ((SRM_ORM_Code)103)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_IDA_1991
 *
 *  Ida (asteroid 243)
 */
#define SRM_ORMCOD_IDA_1991 ((SRM_ORM_Code)104)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_INDIAN_1916
 *
 *  Indian
 */
#define SRM_ORMCOD_INDIAN_1916 ((SRM_ORM_Code)105)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_INDIAN_1954
 *
 *  Indian
 */
#define SRM_ORMCOD_INDIAN_1954 ((SRM_ORM_Code)106)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_INDIAN_1956
 *
 *  Indian
 */
#define SRM_ORMCOD_INDIAN_1956 ((SRM_ORM_Code)107)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_INDIAN_1960
 *
 *  Indian
 */
#define SRM_ORMCOD_INDIAN_1960 ((SRM_ORM_Code)108)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_INDIAN_1962
 *
 *  Indian
 */
#define SRM_ORMCOD_INDIAN_1962 ((SRM_ORM_Code)109)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_INDIAN_1975
 *
 *  Indian
 */
#define SRM_ORMCOD_INDIAN_1975 ((SRM_ORM_Code)110)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_INDONESIAN_1974
 *
 *  Indonesian
 */
#define SRM_ORMCOD_INDONESIAN_1974 ((SRM_ORM_Code)111)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_IO_2000
 *
 *  Io
 */
#define SRM_ORMCOD_IO_2000 ((SRM_ORM_Code)112)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_IRELAND_1965
 *
 *  Ireland 1965
 */
#define SRM_ORMCOD_IRELAND_1965 ((SRM_ORM_Code)113)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ISTS_061_1968
 *
 *  International Satellite Triangulation Station (ISTS) 061 (astronomic)
 */
#define SRM_ORMCOD_ISTS_061_1968 ((SRM_ORM_Code)114)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ISTS_073_1969
 *
 *  International Satellite Triangulation Station (ISTS) 073 (astronomic)
 */
#define SRM_ORMCOD_ISTS_073_1969 ((SRM_ORM_Code)115)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JANUS_1988
 *
 *  Janus
 */
#define SRM_ORMCOD_JANUS_1988 ((SRM_ORM_Code)116)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JGD_2000
 *
 *  Japanese Geodetic Datum 2000 (JGD2000)
 */
#define SRM_ORMCOD_JGD_2000 ((SRM_ORM_Code)117)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JOHNSTON_1961
 *
 *  Johnston
 */
#define SRM_ORMCOD_JOHNSTON_1961 ((SRM_ORM_Code)118)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JULIET_1988
 *
 *  Juliet
 */
#define SRM_ORMCOD_JULIET_1988 ((SRM_ORM_Code)119)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JUPITER_1988
 *
 *  Jupiter
 */
#define SRM_ORMCOD_JUPITER_1988 ((SRM_ORM_Code)120)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JUPITER_INERTIAL
 *
 *  Jupiter equatorial inertial
 */
#define SRM_ORMCOD_JUPITER_INERTIAL ((SRM_ORM_Code)121)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JUPITER_MAGNETIC_1993
 *
 *  Jupiter magnetic
 */
#define SRM_ORMCOD_JUPITER_MAGNETIC_1993 ((SRM_ORM_Code)122)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JUPITER_SOLAR_ECLIPTIC
 *
 *  Jupiter solar ecliptic
 */
#define SRM_ORMCOD_JUPITER_SOLAR_ECLIPTIC ((SRM_ORM_Code)123)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JUPITER_SOLAR_EQUATORIAL
 *
 *  Jupiter solar equatorial
 */
#define SRM_ORMCOD_JUPITER_SOLAR_EQUATORIAL ((SRM_ORM_Code)124)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JUPITER_SOLAR_MAG_DIPOLE
 *
 *  Jupiter solar magnetic dipole
 */
#define SRM_ORMCOD_JUPITER_SOLAR_MAG_DIPOLE ((SRM_ORM_Code)125)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_JUPITER_SOLAR_MAG_ECLIPTIC
 *
 *  Jupiter solar magnetic ecliptic
 */
#define SRM_ORMCOD_JUPITER_SOLAR_MAG_ECLIPTIC ((SRM_ORM_Code)126)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_KANDAWALA_1987
 *
 *  Kandawala
 */
#define SRM_ORMCOD_KANDAWALA_1987 ((SRM_ORM_Code)127)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_KERGUELEN_1949
 *
 *  Kerguelen
 */
#define SRM_ORMCOD_KERGUELEN_1949 ((SRM_ORM_Code)128)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_KERTAU_1948
 *
 *  Kertau
 */
#define SRM_ORMCOD_KERTAU_1948 ((SRM_ORM_Code)129)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_KOREAN_GEODETIC_1995
 *
 *  Korean Geodetic System
 */
#define SRM_ORMCOD_KOREAN_GEODETIC_1995 ((SRM_ORM_Code)130)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_KUSAIE_1951
 *
 *  Kusaie 1951 (astronomic)
 */
#define SRM_ORMCOD_KUSAIE_1951 ((SRM_ORM_Code)131)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_LARISSA_1991
 *
 *  Larissa
 */
#define SRM_ORMCOD_LARISSA_1991 ((SRM_ORM_Code)132)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_LC5_1961
 *
 *  LC5 (astronomic)
 */
#define SRM_ORMCOD_LC5_1961 ((SRM_ORM_Code)133)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_LEIGON_1991
 *
 *  Leigon
 */
#define SRM_ORMCOD_LEIGON_1991 ((SRM_ORM_Code)134)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_LIBERIA_1964
 *
 *  Liberia
 */
#define SRM_ORMCOD_LIBERIA_1964 ((SRM_ORM_Code)135)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_LUZON_1987
 *
 *  Luzon
 */
#define SRM_ORMCOD_LUZON_1987 ((SRM_ORM_Code)136)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_M_PORALOKO_1991
 *
 *  M'Poraloko
 */
#define SRM_ORMCOD_M_PORALOKO_1991 ((SRM_ORM_Code)137)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MAHE_1971
 *
 *  Mahe
 */
#define SRM_ORMCOD_MAHE_1971 ((SRM_ORM_Code)138)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MARCUS_STATION_1952
 *
 *  Marcus Station (astronomic)
 */
#define SRM_ORMCOD_MARCUS_STATION_1952 ((SRM_ORM_Code)139)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MARS_2000
 *
 *  Mars
 */
#define SRM_ORMCOD_MARS_2000 ((SRM_ORM_Code)140)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MARS_INERTIAL
 *
 *  Mars equatorial inertial
 */
#define SRM_ORMCOD_MARS_INERTIAL ((SRM_ORM_Code)141)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MARS_SPHERE_2000
 *
 *  Mars (spherical)
 */
#define SRM_ORMCOD_MARS_SPHERE_2000 ((SRM_ORM_Code)142)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MASS_1999
 *
 *  MASS
 */
#define SRM_ORMCOD_MASS_1999 ((SRM_ORM_Code)143)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MASSAWA_1987
 *
 *  Massawa
 */
#define SRM_ORMCOD_MASSAWA_1987 ((SRM_ORM_Code)144)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MERCHICH_1987
 *
 *  Merchich
 */
#define SRM_ORMCOD_MERCHICH_1987 ((SRM_ORM_Code)145)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MERCURY_1988
 *
 *  Mercury
 */
#define SRM_ORMCOD_MERCURY_1988 ((SRM_ORM_Code)146)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MERCURY_INERTIAL
 *
 *  Mercury equatorial inertial
 */
#define SRM_ORMCOD_MERCURY_INERTIAL ((SRM_ORM_Code)147)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_METIS_2000
 *
 *  Metis
 */
#define SRM_ORMCOD_METIS_2000 ((SRM_ORM_Code)148)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MIDWAY_1961
 *
 *  Midway 1961 (astronomic)
 */
#define SRM_ORMCOD_MIDWAY_1961 ((SRM_ORM_Code)149)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MIMAS_1994
 *
 *  Mimas
 */
#define SRM_ORMCOD_MIMAS_1994 ((SRM_ORM_Code)150)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MINNA_1991
 *
 *  Minna
 */
#define SRM_ORMCOD_MINNA_1991 ((SRM_ORM_Code)151)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MIRANDA_1988
 *
 *  Miranda
 */
#define SRM_ORMCOD_MIRANDA_1988 ((SRM_ORM_Code)152)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MM5_1997
 *
 *  MM5 (AFWA)
 */
#define SRM_ORMCOD_MM5_1997 ((SRM_ORM_Code)153)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989
 *
 *  MODTRAN
 */
#define SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989 ((SRM_ORM_Code)154)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989
 *
 *  MODTRAN
 */
#define SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989 ((SRM_ORM_Code)155)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989
 *
 *  MODTRAN
 */
#define SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989 ((SRM_ORM_Code)156)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989
 *
 *  MODTRAN
 */
#define SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989 ((SRM_ORM_Code)157)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MODTRAN_TROPICAL_1989
 *
 *  MODTRAN
 */
#define SRM_ORMCOD_MODTRAN_TROPICAL_1989 ((SRM_ORM_Code)158)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MONTSERRAT_1958
 *
 *  Montserrat (astronomic)
 */
#define SRM_ORMCOD_MONTSERRAT_1958 ((SRM_ORM_Code)159)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MOON_1991
 *
 *  Moon
 */
#define SRM_ORMCOD_MOON_1991 ((SRM_ORM_Code)160)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989
 *
 *  Multigen flat Earth
 */
#define SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989 ((SRM_ORM_Code)161)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_N_AM_1927
 *
 *  North American
 */
#define SRM_ORMCOD_N_AM_1927 ((SRM_ORM_Code)162)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_N_AM_1983
 *
 *  North American
 */
#define SRM_ORMCOD_N_AM_1983 ((SRM_ORM_Code)163)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_N_SAHARA_1959
 *
 *  North Sahara
 */
#define SRM_ORMCOD_N_SAHARA_1959 ((SRM_ORM_Code)164)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NAHRWAN_1987
 *
 *  Nahrwan
 */
#define SRM_ORMCOD_NAHRWAN_1987 ((SRM_ORM_Code)165)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NAIAD_1991
 *
 *  Naiad
 */
#define SRM_ORMCOD_NAIAD_1991 ((SRM_ORM_Code)166)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NAPARIMA_1991
 *
 *  Naparima BWI
 */
#define SRM_ORMCOD_NAPARIMA_1991 ((SRM_ORM_Code)167)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NEPTUNE_1991
 *
 *  Neptune
 */
#define SRM_ORMCOD_NEPTUNE_1991 ((SRM_ORM_Code)168)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NEPTUNE_INERTIAL
 *
 *  Neptune equatorial inertial
 */
#define SRM_ORMCOD_NEPTUNE_INERTIAL ((SRM_ORM_Code)169)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NEPTUNE_MAGNETIC_1993
 *
 *  Neptune magnetic
 */
#define SRM_ORMCOD_NEPTUNE_MAGNETIC_1993 ((SRM_ORM_Code)170)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NOGAPS_1988
 *
 *  NOGAPS
 */
#define SRM_ORMCOD_NOGAPS_1988 ((SRM_ORM_Code)171)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NTF_1896
 *
 *  NTF
 */
#define SRM_ORMCOD_NTF_1896 ((SRM_ORM_Code)172)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_NTF_1896_PM_PARIS
 *
 *  NTF (with the Prime Meridian at Paris)
 */
#define SRM_ORMCOD_NTF_1896_PM_PARIS ((SRM_ORM_Code)173)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_OBERON_1988
 *
 *  Oberon
 */
#define SRM_ORMCOD_OBERON_1988 ((SRM_ORM_Code)174)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_OBSERV_METEORO_1939
 *
 *  Observatorio Meteorologico
 */
#define SRM_ORMCOD_OBSERV_METEORO_1939 ((SRM_ORM_Code)175)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_OLD_EGYPTIAN_1907
 *
 *  Old Egyptian
 */
#define SRM_ORMCOD_OLD_EGYPTIAN_1907 ((SRM_ORM_Code)176)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987
 *
 *  Old Hawaiian (Clarke)
 */
#define SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987 ((SRM_ORM_Code)177)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_OLD_HAWAIIAN_INT_1987
 *
 *  Old Hawaiian (International)
 */
#define SRM_ORMCOD_OLD_HAWAIIAN_INT_1987 ((SRM_ORM_Code)178)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_OPHELIA_1988
 *
 *  Ophelia
 */
#define SRM_ORMCOD_OPHELIA_1988 ((SRM_ORM_Code)179)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_OSGB_1936
 *
 *  Ordnance Survey of Great Britain
 */
#define SRM_ORMCOD_OSGB_1936 ((SRM_ORM_Code)180)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PAN_1991
 *
 *  Pan
 */
#define SRM_ORMCOD_PAN_1991 ((SRM_ORM_Code)181)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PANDORA_1988
 *
 *  Pandora
 */
#define SRM_ORMCOD_PANDORA_1988 ((SRM_ORM_Code)182)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PHOBOS_1988
 *
 *  Phobos
 */
#define SRM_ORMCOD_PHOBOS_1988 ((SRM_ORM_Code)183)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PHOEBE_1988
 *
 *  Phoebe
 */
#define SRM_ORMCOD_PHOEBE_1988 ((SRM_ORM_Code)184)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987
 *
 *  Pico de las Nieves
 */
#define SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987 ((SRM_ORM_Code)185)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PITCAIRN_1967
 *
 *  Pitcairn (astronomic)
 */
#define SRM_ORMCOD_PITCAIRN_1967 ((SRM_ORM_Code)186)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PLUTO_1994
 *
 *  Pluto
 */
#define SRM_ORMCOD_PLUTO_1994 ((SRM_ORM_Code)187)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PLUTO_INERTIAL
 *
 *  Pluto equatorial inertial
 */
#define SRM_ORMCOD_PLUTO_INERTIAL ((SRM_ORM_Code)188)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_POINT_58_1991
 *
 *  Point 58
 */
#define SRM_ORMCOD_POINT_58_1991 ((SRM_ORM_Code)189)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_POINTE_NOIRE_1948
 *
 *  Pointe Noire
 */
#define SRM_ORMCOD_POINTE_NOIRE_1948 ((SRM_ORM_Code)190)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PORTIA_1988
 *
 *  Portia
 */
#define SRM_ORMCOD_PORTIA_1988 ((SRM_ORM_Code)191)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PORTO_SANTO_1936
 *
 *  Porto Santo
 */
#define SRM_ORMCOD_PORTO_SANTO_1936 ((SRM_ORM_Code)192)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PROMETHEUS_1988
 *
 *  Prometheus
 */
#define SRM_ORMCOD_PROMETHEUS_1988 ((SRM_ORM_Code)193)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PROTEUS_1991
 *
 *  Proteus
 */
#define SRM_ORMCOD_PROTEUS_1991 ((SRM_ORM_Code)194)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PROV_S_AM_1956
 *
 *  Provisional South American
 */
#define SRM_ORMCOD_PROV_S_AM_1956 ((SRM_ORM_Code)195)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PROV_S_CHILEAN_1963
 *
 *  Provisional South Chilean (Hito XVIII)
 */
#define SRM_ORMCOD_PROV_S_CHILEAN_1963 ((SRM_ORM_Code)196)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PUCK_1988
 *
 *  Puck
 */
#define SRM_ORMCOD_PUCK_1988 ((SRM_ORM_Code)197)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PUERTO_RICO_1987
 *
 *  Puerto Rico
 */
#define SRM_ORMCOD_PUERTO_RICO_1987 ((SRM_ORM_Code)198)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_PULKOVO_1942
 *
 *  Pulkovo
 */
#define SRM_ORMCOD_PULKOVO_1942 ((SRM_ORM_Code)199)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_QATAR_NATIONAL_1974
 *
 *  Qatar National
 */
#define SRM_ORMCOD_QATAR_NATIONAL_1974 ((SRM_ORM_Code)200)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_QORNOQ_1987
 *
 *  Qornoq
 */
#define SRM_ORMCOD_QORNOQ_1987 ((SRM_ORM_Code)201)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_REUNION_1947
 *
 *  Reunion
 */
#define SRM_ORMCOD_REUNION_1947 ((SRM_ORM_Code)202)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_RGF_1993
 *
 *  Reseau Geodesique Francais
 */
#define SRM_ORMCOD_RGF_1993 ((SRM_ORM_Code)203)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_RHEA_1988
 *
 *  Rhea
 */
#define SRM_ORMCOD_RHEA_1988 ((SRM_ORM_Code)204)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ROME_1940
 *
 *  Rome (also known as Monte Mario)
 */
#define SRM_ORMCOD_ROME_1940 ((SRM_ORM_Code)205)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ROME_1940_PM_ROME
 *
 *  Rome (also known as Monte Mario) (with the Prime Meridian at Rome)
 */
#define SRM_ORMCOD_ROME_1940_PM_ROME ((SRM_ORM_Code)206)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ROSALIND_1988
 *
 *  Rosalind
 */
#define SRM_ORMCOD_ROSALIND_1988 ((SRM_ORM_Code)207)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_S_AM_1969
 *
 *  South American
 */
#define SRM_ORMCOD_S_AM_1969 ((SRM_ORM_Code)208)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_S_ASIA_1987
 *
 *  South Asia
 */
#define SRM_ORMCOD_S_ASIA_1987 ((SRM_ORM_Code)209)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_S_JTSK_1993
 *
 *  S-JTSK
 */
#define SRM_ORMCOD_S_JTSK_1993 ((SRM_ORM_Code)210)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_S42_PULKOVO
 *
 *  S-42 (Pulkovo)
 */
#define SRM_ORMCOD_S42_PULKOVO ((SRM_ORM_Code)211)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SANTO_DOS_1965
 *
 *  Santo (DOS)
 */
#define SRM_ORMCOD_SANTO_DOS_1965 ((SRM_ORM_Code)212)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SAO_BRAZ_1987
 *
 *  Sao Braz
 */
#define SRM_ORMCOD_SAO_BRAZ_1987 ((SRM_ORM_Code)213)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SAPPER_HILL_1943
 *
 *  Sapper Hill
 */
#define SRM_ORMCOD_SAPPER_HILL_1943 ((SRM_ORM_Code)214)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SATURN_1988
 *
 *  Saturn
 */
#define SRM_ORMCOD_SATURN_1988 ((SRM_ORM_Code)215)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SATURN_INERTIAL
 *
 *  Saturn equatorial inertial
 */
#define SRM_ORMCOD_SATURN_INERTIAL ((SRM_ORM_Code)216)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SATURN_MAGNETIC_1993
 *
 *  Saturn magnetic
 */
#define SRM_ORMCOD_SATURN_MAGNETIC_1993 ((SRM_ORM_Code)217)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SCHWARZECK_1991
 *
 *  Schwarzeck
 */
#define SRM_ORMCOD_SCHWARZECK_1991 ((SRM_ORM_Code)218)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SELVAGEM_GRANDE_1938
 *
 *  Selvagem Grande
 */
#define SRM_ORMCOD_SELVAGEM_GRANDE_1938 ((SRM_ORM_Code)219)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SIERRA_LEONE_1960
 *
 *  Sierra Leone
 */
#define SRM_ORMCOD_SIERRA_LEONE_1960 ((SRM_ORM_Code)220)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SIRGAS_2000
 *
 *  SIRGAS
 */
#define SRM_ORMCOD_SIRGAS_2000 ((SRM_ORM_Code)221)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_SUN_1992
 *
 *  Sun
 */
#define SRM_ORMCOD_SUN_1992 ((SRM_ORM_Code)222)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TANANARIVE_OBS_1925
 *
 *  Tananarive Observatory
 */
#define SRM_ORMCOD_TANANARIVE_OBS_1925 ((SRM_ORM_Code)223)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS
 *
 *  Tananarive Observatory (with the Prime Meridian at Paris)
 */
#define SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS ((SRM_ORM_Code)224)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TELESTO_1988
 *
 *  Telesto
 */
#define SRM_ORMCOD_TELESTO_1988 ((SRM_ORM_Code)225)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TERN_1961
 *
 *  Tern (astronomic)
 */
#define SRM_ORMCOD_TERN_1961 ((SRM_ORM_Code)226)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TETHYS_1991
 *
 *  Tethys
 */
#define SRM_ORMCOD_TETHYS_1991 ((SRM_ORM_Code)227)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_THALASSA_1991
 *
 *  Thalassa
 */
#define SRM_ORMCOD_THALASSA_1991 ((SRM_ORM_Code)228)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_THEBE_2000
 *
 *  Thebe
 */
#define SRM_ORMCOD_THEBE_2000 ((SRM_ORM_Code)229)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TIMBALAI_EVEREST_1948
 *
 *  Timbali (Everest)
 */
#define SRM_ORMCOD_TIMBALAI_EVEREST_1948 ((SRM_ORM_Code)230)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TITAN_1982
 *
 *  Titan
 */
#define SRM_ORMCOD_TITAN_1982 ((SRM_ORM_Code)231)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TITANIA_1988
 *
 *  Titania
 */
#define SRM_ORMCOD_TITANIA_1988 ((SRM_ORM_Code)232)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TOKYO_1991
 *
 *  Tokyo
 */
#define SRM_ORMCOD_TOKYO_1991 ((SRM_ORM_Code)233)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TRISTAN_1968
 *
 *  Tristan (astronomic)
 */
#define SRM_ORMCOD_TRISTAN_1968 ((SRM_ORM_Code)234)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_TRITON_1991
 *
 *  Triton
 */
#define SRM_ORMCOD_TRITON_1991 ((SRM_ORM_Code)235)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_UMBRIEL_1988
 *
 *  Umbriel
 */
#define SRM_ORMCOD_UMBRIEL_1988 ((SRM_ORM_Code)236)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_URANUS_1988
 *
 *  Uranus
 */
#define SRM_ORMCOD_URANUS_1988 ((SRM_ORM_Code)237)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_URANUS_INERTIAL
 *
 *  Uranus equatorial inertial
 */
#define SRM_ORMCOD_URANUS_INERTIAL ((SRM_ORM_Code)238)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_URANUS_MAGNETIC_1993
 *
 *  Uranus magnetic
 */
#define SRM_ORMCOD_URANUS_MAGNETIC_1993 ((SRM_ORM_Code)239)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_VENUS_1991
 *
 *  Venus
 */
#define SRM_ORMCOD_VENUS_1991 ((SRM_ORM_Code)240)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_VENUS_INERTIAL
 *
 *  Venus equatorial inertial
 */
#define SRM_ORMCOD_VENUS_INERTIAL ((SRM_ORM_Code)241)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_VITI_LEVU_1916
 *
 *  Viti Levu
 */
#define SRM_ORMCOD_VITI_LEVU_1916 ((SRM_ORM_Code)242)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_VOIROL_1874
 *
 *  Voirol
 */
#define SRM_ORMCOD_VOIROL_1874 ((SRM_ORM_Code)243)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_VOIROL_1874_PM_PARIS
 *
 *  Voirol (with the Prime Meridian at Paris)
 */
#define SRM_ORMCOD_VOIROL_1874_PM_PARIS ((SRM_ORM_Code)244)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_VOIROL_1960
 *
 *  Voirol - Revised
 */
#define SRM_ORMCOD_VOIROL_1960 ((SRM_ORM_Code)245)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_VOIROL_1960_PM_PARIS
 *
 *  Voirol - Revised (with the Prime Meridian at Paris)
 */
#define SRM_ORMCOD_VOIROL_1960_PM_PARIS ((SRM_ORM_Code)246)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_WAKE_1952
 *
 *  Wake (astronomic)
 */
#define SRM_ORMCOD_WAKE_1952 ((SRM_ORM_Code)247)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_WAKE_ENIWETOK_1960
 *
 *  Wake-Eniwetok
 */
#define SRM_ORMCOD_WAKE_ENIWETOK_1960 ((SRM_ORM_Code)248)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_WGS_1972
 *
 *  World Geodetic System
 */
#define SRM_ORMCOD_WGS_1972 ((SRM_ORM_Code)249)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_WGS_1984
 *
 *  World Geodetic System
 */
#define SRM_ORMCOD_WGS_1984 ((SRM_ORM_Code)250)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_YACARE_1987
 *
 *  Yacare (Uruguay)
 */
#define SRM_ORMCOD_YACARE_1987 ((SRM_ORM_Code)251)

/*!
 * GLOBAL CONSTANT: SRM_ORMCOD_ZANDERIJ_1987
 *
 *  Zanderij (Suriname)
 */
#define SRM_ORMCOD_ZANDERIJ_1987 ((SRM_ORM_Code)252)


/*! Upper Bound value for ORM_Codes */
#define SRM_ORM_CODE_UBOUND 252


/*!
 * STRUCT: SRM_ORM_Transformation_2D_Parameters
 *
 *   This data type defines a 2D reference transformation
 */
typedef struct
{
    SRM_Long_Float delta_x;
    SRM_Long_Float delta_y;
    SRM_Long_Float omega;
    SRM_Long_Float delta_s;
} SRM_ORM_Transformation_2D_Parameters;


/*!
 * STRUCT: SRM_ORM_Transformation_3D_Parameters
 *
 *   This data type defines a 3D reference transformation
 */
typedef struct
{
    SRM_Long_Float delta_x;
    SRM_Long_Float delta_y;
    SRM_Long_Float delta_z;
    SRM_Long_Float omega_1;
    SRM_Long_Float omega_2;
    SRM_Long_Float omega_3;
    SRM_Long_Float delta_s;
} SRM_ORM_Transformation_3D_Parameters;


/*!
 * REGISTERABLE ENUM: SRM_ORMT_Code
 *
 *   This is a list of the ORM Template Codes
 */
typedef SRM_Integer SRM_ORMT_Code;

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_UNSPECIFIED
 */
#define SRM_ORMTCOD_UNSPECIFIED ((SRM_ORMT_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_BI_AXIS_ORIGIN_2D
 *
 *  x- and y-axes determined by directed perpendicular lines passing
 *  through the origin
 */
#define SRM_ORMTCOD_BI_AXIS_ORIGIN_2D ((SRM_ORMT_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_SPHERE
 *
 *  3D sphere with designated directional axis and xz-plane
 */
#define SRM_ORMTCOD_SPHERE ((SRM_ORMT_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_OBLATE_ELLIPSOID
 *
 *  Oblate ellipsoid with designated minor axis direction and xz-plane
 */
#define SRM_ORMTCOD_OBLATE_ELLIPSOID ((SRM_ORMT_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_PROLATE_ELLIPSOID
 *
 *  prolate ellipsoid with designated major axis direction and xz-plane
 */
#define SRM_ORMTCOD_PROLATE_ELLIPSOID ((SRM_ORMT_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID
 *
 *  3D tri-axial ellipsoid with designated z-axis direction and xz-plane
 */
#define SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID ((SRM_ORMT_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_BI_AXIS_ORIGIN_3D
 *
 *  x- and y-axes determined by directed perpendicular lines passing
 *  through the origin
 */
#define SRM_ORMTCOD_BI_AXIS_ORIGIN_3D ((SRM_ORMT_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_SPHERE_ORIGIN
 *
 *  Sphere with two directed perpendicular lines passing through the
 *  centre of the sphere
 */
#define SRM_ORMTCOD_SPHERE_ORIGIN ((SRM_ORMT_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN
 *
 *  Oblate ellipsoid with designated centre, minor axis direction and
 *  xz-plane
 */
#define SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN ((SRM_ORMT_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_ORMTCOD_TRI_PLANE
 *
 *  Origin determined by the intersection of three planes
 */
#define SRM_ORMTCOD_TRI_PLANE ((SRM_ORMT_Code)9)


/*! Upper Bound value for ORMT_Codes */
#define SRM_ORMT_CODE_UBOUND 9


/*!
 * ENUM: SRM_Polar_Aspect
 *
 *  This data type represents the values of the polar aspect parameter
 *  of SRFT POLAR_STEREOGRAPHIC.
 */
typedef enum
{
    SRM_PLRASP_NORTH,
    SRM_PLRASP_SOUTH
} SRM_Polar_Aspect;


/*!
 * STRUCT: SRM_PS_Parameters
 *
 *  Polar Stereographic (PS) Parameters are used as a means
 *  of specifying the PS spatial coordinate systems
 */
typedef struct
{
    SRM_Polar_Aspect polar_aspect;
    SRM_Long_Float   origin_longitude;
    SRM_Long_Float   central_scale;
    SRM_Long_Float   false_easting;
    SRM_Long_Float   false_northing;
} SRM_PS_Parameters;


/*!
 * REGISTERABLE ENUM: SRM_RD_Code
 *
 *  Reference Datum
 */
typedef SRM_Integer SRM_RD_Code;

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ORIGIN_2D
 *
 *  Origin in 2D
 */
#define SRM_RDCOD_ORIGIN_2D ((SRM_RD_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_X_UNIT_POINT_2D
 *
 *  x-axis unit point in 2D
 */
#define SRM_RDCOD_X_UNIT_POINT_2D ((SRM_RD_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_Y_UNIT_POINT_2D
 *
 *  y-axis unit point in 2D
 */
#define SRM_RDCOD_Y_UNIT_POINT_2D ((SRM_RD_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ORIGIN_3D
 *
 *  Origin in 3D
 */
#define SRM_RDCOD_ORIGIN_3D ((SRM_RD_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_X_UNIT_POINT_3D
 *
 *  x-axis unit point in 3D
 */
#define SRM_RDCOD_X_UNIT_POINT_3D ((SRM_RD_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_Y_UNIT_POINT_3D
 *
 *  y-axis unit point in 3D
 */
#define SRM_RDCOD_Y_UNIT_POINT_3D ((SRM_RD_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_Z_UNIT_POINT_3D
 *
 *  z-axis unit point in 3D
 */
#define SRM_RDCOD_Z_UNIT_POINT_3D ((SRM_RD_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_X_AXIS_2D
 *
 *  x-axis in 2D
 */
#define SRM_RDCOD_X_AXIS_2D ((SRM_RD_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_Y_AXIS_2D
 *
 *  y-axis in 2D
 */
#define SRM_RDCOD_Y_AXIS_2D ((SRM_RD_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_X_AXIS_3D
 *
 *  x-axis in 3D
 */
#define SRM_RDCOD_X_AXIS_3D ((SRM_RD_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_Y_AXIS_3D
 *
 *  y-axis in 3D
 */
#define SRM_RDCOD_Y_AXIS_3D ((SRM_RD_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_Z_AXIS_3D
 *
 *  z-axis in 3D
 */
#define SRM_RDCOD_Z_AXIS_3D ((SRM_RD_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_XY_PLANE_3D
 *
 *  xy-plane
 */
#define SRM_RDCOD_XY_PLANE_3D ((SRM_RD_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_XZ_PLANE_3D
 *
 *  xz-plane
 */
#define SRM_RDCOD_XZ_PLANE_3D ((SRM_RD_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_YZ_PLANE_3D
 *
 *  yz-plane
 */
#define SRM_RDCOD_YZ_PLANE_3D ((SRM_RD_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ADRASTEA_2000
 *
 *  Adrastea (satellite of Jupiter)
 */
#define SRM_RDCOD_ADRASTEA_2000 ((SRM_RD_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_AIRY_1830
 *
 *  Airy
 */
#define SRM_RDCOD_AIRY_1830 ((SRM_RD_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_AMALTHEA_2000
 *
 *  Amalthea (satellite of Jupiter)
 */
#define SRM_RDCOD_AMALTHEA_2000 ((SRM_RD_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ANANKE_1988
 *
 *  Ananke (satellite of Jupiter)
 */
#define SRM_RDCOD_ANANKE_1988 ((SRM_RD_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_APL_4r5_1968
 *
 *  APL 4.5
 */
#define SRM_RDCOD_APL_4r5_1968 ((SRM_RD_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ARIEL_1988
 *
 *  Ariel (satellite of Uranus)
 */
#define SRM_RDCOD_ARIEL_1988 ((SRM_RD_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ATLAS_1988
 *
 *  Atlas (satellite of Saturn)
 */
#define SRM_RDCOD_ATLAS_1988 ((SRM_RD_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_AUSTRALIAN_NATIONAL_1966
 *
 *  Australian national
 */
#define SRM_RDCOD_AUSTRALIAN_NATIONAL_1966 ((SRM_RD_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_AVERAGE_TERRESTRIAL_1977
 *
 *  Average terrestrial system
 */
#define SRM_RDCOD_AVERAGE_TERRESTRIAL_1977 ((SRM_RD_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_BELINDA_1988
 *
 *  Belinda (satellite of Uranus)
 */
#define SRM_RDCOD_BELINDA_1988 ((SRM_RD_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_BESSEL_1841_ETHIOPIA
 *
 *  Bessel (Ethiopia, Indonesia, Japan, and Korea)
 */
#define SRM_RDCOD_BESSEL_1841_ETHIOPIA ((SRM_RD_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_BESSEL_1841_NAMIBIA
 *
 *  Bessel (Namibia)
 */
#define SRM_RDCOD_BESSEL_1841_NAMIBIA ((SRM_RD_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_BIANCA_1988
 *
 *  Bianca (satellite of Uranus)
 */
#define SRM_RDCOD_BIANCA_1988 ((SRM_RD_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CALLISTO_2000
 *
 *  Callisto (satellite of Jupiter)
 */
#define SRM_RDCOD_CALLISTO_2000 ((SRM_RD_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CALYPSO_1988
 *
 *  Calypso (satellite of Saturn)
 */
#define SRM_RDCOD_CALYPSO_1988 ((SRM_RD_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CARME_1988
 *
 *  Carme (satellite of Jupiter)
 */
#define SRM_RDCOD_CARME_1988 ((SRM_RD_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CHARON_1991
 *
 *  Charon (satellite of Pluto)
 */
#define SRM_RDCOD_CHARON_1991 ((SRM_RD_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1858
 *
 *  Clarke
 */
#define SRM_RDCOD_CLARKE_1858 ((SRM_RD_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1858_MODIFIED
 *
 *  Clarke - modified
 */
#define SRM_RDCOD_CLARKE_1858_MODIFIED ((SRM_RD_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1866
 *
 *  Clarke
 */
#define SRM_RDCOD_CLARKE_1866 ((SRM_RD_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1880
 *
 *  Clarke
 */
#define SRM_RDCOD_CLARKE_1880 ((SRM_RD_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1880_CAPE
 *
 *  Clarke - Cape
 */
#define SRM_RDCOD_CLARKE_1880_CAPE ((SRM_RD_Code)37)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1880_FIJI
 *
 *  Clarke - Fiji
 */
#define SRM_RDCOD_CLARKE_1880_FIJI ((SRM_RD_Code)38)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1880_IGN
 *
 *  Clarke - IGN
 */
#define SRM_RDCOD_CLARKE_1880_IGN ((SRM_RD_Code)39)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1880_PALESTINE
 *
 *  Clarke - Palestine
 */
#define SRM_RDCOD_CLARKE_1880_PALESTINE ((SRM_RD_Code)40)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CLARKE_1880_SYRIA
 *
 *  Clarke - Syria
 */
#define SRM_RDCOD_CLARKE_1880_SYRIA ((SRM_RD_Code)41)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_COAMPS_1998
 *
 *  Coupled Ocean/Atmospheric Mesoscale Prediction System (COAMPSTM)
 */
#define SRM_RDCOD_COAMPS_1998 ((SRM_RD_Code)42)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CORDELIA_1988
 *
 *  Cordelia (satellite of Uranus)
 */
#define SRM_RDCOD_CORDELIA_1988 ((SRM_RD_Code)43)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_CRESSIDA_1988
 *
 *  Cressida (satellite of Uranus)
 */
#define SRM_RDCOD_CRESSIDA_1988 ((SRM_RD_Code)44)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_DANISH_1876
 *
 *  Danish - Andrae
 */
#define SRM_RDCOD_DANISH_1876 ((SRM_RD_Code)45)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_DEIMOS_1988
 *
 *  Deimos (satellite of Mars)
 */
#define SRM_RDCOD_DEIMOS_1988 ((SRM_RD_Code)46)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_DELAMBRE_1810
 *
 *  Delambre
 */
#define SRM_RDCOD_DELAMBRE_1810 ((SRM_RD_Code)47)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_DESDEMONA_1988
 *
 *  Desdemona (satellite of Uranus)
 */
#define SRM_RDCOD_DESDEMONA_1988 ((SRM_RD_Code)48)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_DESPINA_1991
 *
 *  Despina (satellite of Neptune)
 */
#define SRM_RDCOD_DESPINA_1991 ((SRM_RD_Code)49)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_DIONE_1982
 *
 *  Dione (satellite of Saturn)
 */
#define SRM_RDCOD_DIONE_1982 ((SRM_RD_Code)50)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ELARA_1988
 *
 *  Elara (satellite of Jupiter)
 */
#define SRM_RDCOD_ELARA_1988 ((SRM_RD_Code)51)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ENCELADUS_1994
 *
 *  Enceladus (satellite of Saturn)
 */
#define SRM_RDCOD_ENCELADUS_1994 ((SRM_RD_Code)52)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EPIMETHEUS_1988
 *
 *  Epimetheus (satellite of Saturn)
 */
#define SRM_RDCOD_EPIMETHEUS_1988 ((SRM_RD_Code)53)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EROS_2000
 *
 *  Eros (asteroid 433, a minor planet)
 */
#define SRM_RDCOD_EROS_2000 ((SRM_RD_Code)54)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EUROPA_2000
 *
 *  Europa (satellite of Jupiter)
 */
#define SRM_RDCOD_EUROPA_2000 ((SRM_RD_Code)55)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EVEREST_ADJ_1937
 *
 *  Everest 1830 - adjusted
 */
#define SRM_RDCOD_EVEREST_ADJ_1937 ((SRM_RD_Code)56)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EVEREST_1948
 *
 *  Everest
 */
#define SRM_RDCOD_EVEREST_1948 ((SRM_RD_Code)57)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EVEREST_1956
 *
 *  Everest
 */
#define SRM_RDCOD_EVEREST_1956 ((SRM_RD_Code)58)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EVEREST_REVISED_1962
 *
 *  Everest 1830 - revised definition
 */
#define SRM_RDCOD_EVEREST_REVISED_1962 ((SRM_RD_Code)59)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EVEREST_1969
 *
 *  Everest
 */
#define SRM_RDCOD_EVEREST_1969 ((SRM_RD_Code)60)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_EVEREST_BRUNEI_1967
 *
 *  Everest 1830 - 1967 definition (Brunei and East Malaysia - Sabah and
 *  Sarawak)
 */
#define SRM_RDCOD_EVEREST_BRUNEI_1967 ((SRM_RD_Code)61)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_FISCHER_1960
 *
 *  Fischer - Mercury
 */
#define SRM_RDCOD_FISCHER_1960 ((SRM_RD_Code)62)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_FISCHER_1968
 *
 *  Fischer
 */
#define SRM_RDCOD_FISCHER_1968 ((SRM_RD_Code)63)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_GALATEA_1991
 *
 *  Galatea (satellite of Neptune)
 */
#define SRM_RDCOD_GALATEA_1991 ((SRM_RD_Code)64)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_GANYMEDE_2000
 *
 *  Ganymede (satellite of Jupiter)
 */
#define SRM_RDCOD_GANYMEDE_2000 ((SRM_RD_Code)65)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_GASPRA_1991
 *
 *  Gaspra (asteroid 951, a minor planet)
 */
#define SRM_RDCOD_GASPRA_1991 ((SRM_RD_Code)66)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_GRS_1967
 *
 *  Geodetic Reference System (GRS)
 */
#define SRM_RDCOD_GRS_1967 ((SRM_RD_Code)67)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_GRS_1980
 *
 *  Geodetic Reference System (GRS)
 */
#define SRM_RDCOD_GRS_1980 ((SRM_RD_Code)68)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_HELENE_1992
 *
 *  Helene (satellite of Saturn)
 */
#define SRM_RDCOD_HELENE_1992 ((SRM_RD_Code)69)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_HELMERT_1906
 *
 *  Helmert
 */
#define SRM_RDCOD_HELMERT_1906 ((SRM_RD_Code)70)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_HIMALIA_1988
 *
 *  Himalia (satellite of Jupiter)
 */
#define SRM_RDCOD_HIMALIA_1988 ((SRM_RD_Code)71)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_HOUGH_1960
 *
 *  Hough
 */
#define SRM_RDCOD_HOUGH_1960 ((SRM_RD_Code)72)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_HYPERION_2000
 *
 *  Hyperion (satellite of Saturn)
 */
#define SRM_RDCOD_HYPERION_2000 ((SRM_RD_Code)73)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_IAG_1975
 *
 *  International Association of Geodesy (IAG) best estimate
 */
#define SRM_RDCOD_IAG_1975 ((SRM_RD_Code)74)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_IAPETUS_1988
 *
 *  Iapetus (satellite of Saturn)
 */
#define SRM_RDCOD_IAPETUS_1988 ((SRM_RD_Code)75)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_IDA_1991
 *
 *  Ida (asteroid 293, a minor planet)
 */
#define SRM_RDCOD_IDA_1991 ((SRM_RD_Code)76)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_INDONESIAN_1974
 *
 *  Indonesian
 */
#define SRM_RDCOD_INDONESIAN_1974 ((SRM_RD_Code)77)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_INTERNATIONAL_1924
 *
 *  International
 */
#define SRM_RDCOD_INTERNATIONAL_1924 ((SRM_RD_Code)78)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_IO_2000
 *
 *  Io (satellite of Jupiter)
 */
#define SRM_RDCOD_IO_2000 ((SRM_RD_Code)79)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_JANUS_1988
 *
 *  Janus (satellite of Saturn)
 */
#define SRM_RDCOD_JANUS_1988 ((SRM_RD_Code)80)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_JULIET_1988
 *
 *  Juliet (satellite of Uranus)
 */
#define SRM_RDCOD_JULIET_1988 ((SRM_RD_Code)81)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_JUPITER_1988
 *
 *  Jupiter
 */
#define SRM_RDCOD_JUPITER_1988 ((SRM_RD_Code)82)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_KLEOPATRA_2000
 *
 *  Kleopatra (asteroid 216, a minor planet)
 */
#define SRM_RDCOD_KLEOPATRA_2000 ((SRM_RD_Code)83)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_KRASSOVSKY_1940
 *
 *  Krassovsky
 */
#define SRM_RDCOD_KRASSOVSKY_1940 ((SRM_RD_Code)84)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_KRAYENHOFF_1827
 *
 *  Krayenhoff
 */
#define SRM_RDCOD_KRAYENHOFF_1827 ((SRM_RD_Code)85)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_LARISSA_1991
 *
 *  Larissa (satellite of Neptune)
 */
#define SRM_RDCOD_LARISSA_1991 ((SRM_RD_Code)86)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_LEDA_1988
 *
 *  Leda (satellite of Jupiter)
 */
#define SRM_RDCOD_LEDA_1988 ((SRM_RD_Code)87)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_LYSITHEA_1988
 *
 *  Lysithea (satellite of Jupiter)
 */
#define SRM_RDCOD_LYSITHEA_1988 ((SRM_RD_Code)88)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MARS_2000
 *
 *  Mars
 */
#define SRM_RDCOD_MARS_2000 ((SRM_RD_Code)89)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MARS_SPHERE_2000
 *
 *  Mars
 */
#define SRM_RDCOD_MARS_SPHERE_2000 ((SRM_RD_Code)90)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MASS_1999
 *
 *  MASS
 */
#define SRM_RDCOD_MASS_1999 ((SRM_RD_Code)91)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MERCURY_1988
 *
 *  Mercury
 */
#define SRM_RDCOD_MERCURY_1988 ((SRM_RD_Code)92)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_METIS_2000
 *
 *  Metis (satellite of Jupiter)
 */
#define SRM_RDCOD_METIS_2000 ((SRM_RD_Code)93)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MIMAS_1994
 *
 *  Mimas (satellite of Saturn)
 */
#define SRM_RDCOD_MIMAS_1994 ((SRM_RD_Code)94)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MIRANDA_1988
 *
 *  Miranda (satellite of Uranus)
 */
#define SRM_RDCOD_MIRANDA_1988 ((SRM_RD_Code)95)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MM5_1997
 *
 *  Mesoscale (weather) Model 5 (MM5), Air Force Weather Agency (AFWA), US
 */
#define SRM_RDCOD_MM5_1997 ((SRM_RD_Code)96)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MODIFIED_AIRY_1849
 *
 *  Modified Airy
 */
#define SRM_RDCOD_MODIFIED_AIRY_1849 ((SRM_RD_Code)97)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MODIFIED_FISCHER_1960
 *
 *  Modified Fischer
 */
#define SRM_RDCOD_MODIFIED_FISCHER_1960 ((SRM_RD_Code)98)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MODTRAN_MIDLATITUDE_1989
 *
 *  MODTRAN (midlatitude regions)
 */
#define SRM_RDCOD_MODTRAN_MIDLATITUDE_1989 ((SRM_RD_Code)99)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MODTRAN_SUBARCTIC_1989
 *
 *  MODTRAN (subarctic regions)
 */
#define SRM_RDCOD_MODTRAN_SUBARCTIC_1989 ((SRM_RD_Code)100)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MODTRAN_TROPICAL_1989
 *
 *  MODTRAN (tropical regions)
 */
#define SRM_RDCOD_MODTRAN_TROPICAL_1989 ((SRM_RD_Code)101)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MOON_1991
 *
 *  Moon (satellite of Earth)
 */
#define SRM_RDCOD_MOON_1991 ((SRM_RD_Code)102)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989
 *
 *  Multigen flat Earth
 */
#define SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989 ((SRM_RD_Code)103)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_NAIAD_1991
 *
 *  Naiad (satellite of Neptune)
 */
#define SRM_RDCOD_NAIAD_1991 ((SRM_RD_Code)104)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_NEPTUNE_1991
 *
 *  Neptune
 */
#define SRM_RDCOD_NEPTUNE_1991 ((SRM_RD_Code)105)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_NEREID_1991
 *
 *  Nereid (satellite of Neptune)
 */
#define SRM_RDCOD_NEREID_1991 ((SRM_RD_Code)106)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_NOGAPS_1988
 *
 *  Navy Operational Global Atmospheric Prediction System (NOGAPS), US
 */
#define SRM_RDCOD_NOGAPS_1988 ((SRM_RD_Code)107)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_OBERON_1988
 *
 *  Oberon (satellite of Uranus)
 */
#define SRM_RDCOD_OBERON_1988 ((SRM_RD_Code)108)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_OPHELIA_1988
 *
 *  Ophelia (satellite of Uranus)
 */
#define SRM_RDCOD_OPHELIA_1988 ((SRM_RD_Code)109)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PAN_1991
 *
 *  Pan (satellite of Saturn)
 */
#define SRM_RDCOD_PAN_1991 ((SRM_RD_Code)110)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PANDORA_1988
 *
 *  Pandora (satellite of Saturn)
 */
#define SRM_RDCOD_PANDORA_1988 ((SRM_RD_Code)111)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PASIPHAE_1988
 *
 *  Pasiphae (satellite of Jupiter)
 */
#define SRM_RDCOD_PASIPHAE_1988 ((SRM_RD_Code)112)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PHOBOS_1988
 *
 *  Phobos (satellite of Mars)
 */
#define SRM_RDCOD_PHOBOS_1988 ((SRM_RD_Code)113)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PHOEBE_1988
 *
 *  Phoebe (satellite of Saturn)
 */
#define SRM_RDCOD_PHOEBE_1988 ((SRM_RD_Code)114)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PLESSIS_MODIFIED_1817
 *
 *  Plessis - Modified
 */
#define SRM_RDCOD_PLESSIS_MODIFIED_1817 ((SRM_RD_Code)115)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PLUTO_1994
 *
 *  Pluto
 */
#define SRM_RDCOD_PLUTO_1994 ((SRM_RD_Code)116)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PORTIA_1988
 *
 *  Portia (satellite of Uranus)
 */
#define SRM_RDCOD_PORTIA_1988 ((SRM_RD_Code)117)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PROMETHEUS_1988
 *
 *  Prometheus (satellite of Saturn)
 */
#define SRM_RDCOD_PROMETHEUS_1988 ((SRM_RD_Code)118)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PROTEUS_1991
 *
 *  Proteus (satellite of Neptune)
 */
#define SRM_RDCOD_PROTEUS_1991 ((SRM_RD_Code)119)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_PUCK_1988
 *
 *  Puck (satellite of Uranus)
 */
#define SRM_RDCOD_PUCK_1988 ((SRM_RD_Code)120)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_RHEA_1988
 *
 *  Rhea (satellite of Saturn)
 */
#define SRM_RDCOD_RHEA_1988 ((SRM_RD_Code)121)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_ROSALIND_1988
 *
 *  Rosalind (satellite of Uranus)
 */
#define SRM_RDCOD_ROSALIND_1988 ((SRM_RD_Code)122)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_SATURN_1988
 *
 *  Saturn
 */
#define SRM_RDCOD_SATURN_1988 ((SRM_RD_Code)123)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_SINOPE_1988
 *
 *  Sinope (satellite of Jupiter)
 */
#define SRM_RDCOD_SINOPE_1988 ((SRM_RD_Code)124)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_SOUTH_AMERICAN_1969
 *
 *  South american
 */
#define SRM_RDCOD_SOUTH_AMERICAN_1969 ((SRM_RD_Code)125)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_SOVIET_GEODETIC_1985
 *
 *  Soviet geodetic system
 */
#define SRM_RDCOD_SOVIET_GEODETIC_1985 ((SRM_RD_Code)126)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_SOVIET_GEODETIC_1990
 *
 *  Soviet geodetic system
 */
#define SRM_RDCOD_SOVIET_GEODETIC_1990 ((SRM_RD_Code)127)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_STRUVE_1860
 *
 *  Struve
 */
#define SRM_RDCOD_STRUVE_1860 ((SRM_RD_Code)128)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_SUN_1992
 *
 *  Sun
 */
#define SRM_RDCOD_SUN_1992 ((SRM_RD_Code)129)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_TELESTO_1988
 *
 *  Telesto (satellite of Saturn)
 */
#define SRM_RDCOD_TELESTO_1988 ((SRM_RD_Code)130)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_TETHYS_1991
 *
 *  Tethys (satellite of Saturn)
 */
#define SRM_RDCOD_TETHYS_1991 ((SRM_RD_Code)131)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_THALASSA_1991
 *
 *  Thalassa (satellite of Neptune)
 */
#define SRM_RDCOD_THALASSA_1991 ((SRM_RD_Code)132)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_THEBE_2000
 *
 *  Thebe (satellite of Jupiter)
 */
#define SRM_RDCOD_THEBE_2000 ((SRM_RD_Code)133)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_TITAN_1982
 *
 *  Titan (satellite of Saturn)
 */
#define SRM_RDCOD_TITAN_1982 ((SRM_RD_Code)134)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_TITANIA_1988
 *
 *  Titania (satellite of Uranus)
 */
#define SRM_RDCOD_TITANIA_1988 ((SRM_RD_Code)135)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_TRITON_1991
 *
 *  Triton (satellite of Neptune)
 */
#define SRM_RDCOD_TRITON_1991 ((SRM_RD_Code)136)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_UMBRIEL_1988
 *
 *  Umbriel (satellite of Uranus)
 */
#define SRM_RDCOD_UMBRIEL_1988 ((SRM_RD_Code)137)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_URANUS_1988
 *
 *  Uranus
 */
#define SRM_RDCOD_URANUS_1988 ((SRM_RD_Code)138)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_VENUS_1991
 *
 *  Venus
 */
#define SRM_RDCOD_VENUS_1991 ((SRM_RD_Code)139)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_WALBECK_AMS_1963
 *
 *  Walbeck 1819 - AMS
 */
#define SRM_RDCOD_WALBECK_AMS_1963 ((SRM_RD_Code)140)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_WALBECK_PLANHEFT_1942
 *
 *  Walbeck 1819 - Planheft
 */
#define SRM_RDCOD_WALBECK_PLANHEFT_1942 ((SRM_RD_Code)141)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_WAR_OFFICE_1924
 *
 *  War Office - McCaw
 */
#define SRM_RDCOD_WAR_OFFICE_1924 ((SRM_RD_Code)142)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_WGS_1960
 *
 *  World Geodetic System 1960
 */
#define SRM_RDCOD_WGS_1960 ((SRM_RD_Code)143)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_WGS_1966
 *
 *  World Geodetic System 1966
 */
#define SRM_RDCOD_WGS_1966 ((SRM_RD_Code)144)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_WGS_1984
 *
 *  World geodetic system
 */
#define SRM_RDCOD_WGS_1984 ((SRM_RD_Code)145)

/*!
 * GLOBAL CONSTANT: SRM_RDCOD_WGS_1972
 *
 *  World geodetic system
 */
#define SRM_RDCOD_WGS_1972 ((SRM_RD_Code)146)


/*! Upper Bound value for RD_Codes */
#define SRM_RD_CODE_UBOUND 146


/*!
 * REGISTERABLE ENUM: SRM_RT_Code
 *
 *  RT Codes
 */
typedef SRM_Integer SRM_RT_Code;

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EXPERIMENTAL_NGA_SPHERE_IDENTITY_BY_DEFAULT
 *
 *  Added for NGA Golden Data testing.
 */
#define SRM_RTCOD_EXPERIMENTAL_NGA_SPHERE_IDENTITY_BY_DEFAULT ((SRM_RT_Code)-1001)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EXPERIMENTAL_NGA_MAX_IDENTITY_BY_DEFAULT
 *
 *  Added for NGA Golden Data testing.
 */
#define SRM_RTCOD_EXPERIMENTAL_NGA_MAX_IDENTITY_BY_DEFAULT ((SRM_RT_Code)-1000)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_UNSPECIFIED
 */
#define SRM_RTCOD_UNSPECIFIED ((SRM_RT_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ABSTRACT_2D_IDENTITY
 *
 *  Universal
 */
#define SRM_RTCOD_ABSTRACT_2D_IDENTITY ((SRM_RT_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ABSTRACT_3D_IDENTITY
 *
 *  Universal
 */
#define SRM_RTCOD_ABSTRACT_3D_IDENTITY ((SRM_RT_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ADINDAN_1991_BURKINA_FASO
 *
 *  Burkina Faso
 */
#define SRM_RTCOD_ADINDAN_1991_BURKINA_FASO ((SRM_RT_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ADINDAN_1991_CAMEROON
 *
 *  Cameroon
 */
#define SRM_RTCOD_ADINDAN_1991_CAMEROON ((SRM_RT_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ADINDAN_1991_ETHIOPIA
 *
 *  Ethiopia
 */
#define SRM_RTCOD_ADINDAN_1991_ETHIOPIA ((SRM_RT_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ADINDAN_1991_MALI
 *
 *  Mali
 */
#define SRM_RTCOD_ADINDAN_1991_MALI ((SRM_RT_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ADINDAN_1991_MEAN_SOLUTION
 *
 *  Mean Solution (Ethiopia and Sudan)
 */
#define SRM_RTCOD_ADINDAN_1991_MEAN_SOLUTION ((SRM_RT_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ADINDAN_1991_SENEGAL
 *
 *  Senegal
 */
#define SRM_RTCOD_ADINDAN_1991_SENEGAL ((SRM_RT_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ADINDAN_1991_SUDAN
 *
 *  Sudan
 */
#define SRM_RTCOD_ADINDAN_1991_SUDAN ((SRM_RT_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ADRASTEA_2000_IDENTITY
 *
 *  Global (Adrastea)
 */
#define SRM_RTCOD_ADRASTEA_2000_IDENTITY ((SRM_RT_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AFGOOYE_1987_SOMALIA
 *
 *  Somalia
 */
#define SRM_RTCOD_AFGOOYE_1987_SOMALIA ((SRM_RT_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AIN_EL_ABD_1970_BAHRAIN_ISLAND
 *
 *  Bahrain Island
 */
#define SRM_RTCOD_AIN_EL_ABD_1970_BAHRAIN_ISLAND ((SRM_RT_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AIN_EL_ABD_1970_SAUDI_ARABIA
 *
 *  Saudi Arabia
 */
#define SRM_RTCOD_AIN_EL_ABD_1970_SAUDI_ARABIA ((SRM_RT_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AMALTHEA_2000_IDENTITY
 *
 *  Global (Amalthea)
 */
#define SRM_RTCOD_AMALTHEA_2000_IDENTITY ((SRM_RT_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS
 *
 *  American Samoa Islands
 */
#define SRM_RTCOD_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS ((SRM_RT_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ANNA_1_1965_COCOS_ISLANDS
 *
 *  Cocos Islands
 */
#define SRM_RTCOD_ANNA_1_1965_COCOS_ISLANDS ((SRM_RT_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS
 *
 *  Antigua and Leeward Islands
 */
#define SRM_RTCOD_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS ((SRM_RT_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_3_ZIMBABWE
 *
 *  Zimbabwe
 */
#define SRM_RTCOD_ARC_1950_3_ZIMBABWE ((SRM_RT_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_BOTSWANA
 *
 *  Botswana
 */
#define SRM_RTCOD_ARC_1950_BOTSWANA ((SRM_RT_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_BURUNDI
 *
 *  Burundi
 */
#define SRM_RTCOD_ARC_1950_BURUNDI ((SRM_RT_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_LESOTHO
 *
 *  Lesotho
 */
#define SRM_RTCOD_ARC_1950_LESOTHO ((SRM_RT_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_MALAWI
 *
 *  Malawi
 */
#define SRM_RTCOD_ARC_1950_MALAWI ((SRM_RT_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_MEAN_SOLUTION
 *
 *  Mean Solution (Botswana, Lesotho, Malawi, Swaziland, Zaire, Zambia and
 *  Zimbabwe)
 */
#define SRM_RTCOD_ARC_1950_MEAN_SOLUTION ((SRM_RT_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_SWAZILAND
 *
 *  Swaziland
 */
#define SRM_RTCOD_ARC_1950_SWAZILAND ((SRM_RT_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_ZAIRE
 *
 *  Zaire
 */
#define SRM_RTCOD_ARC_1950_ZAIRE ((SRM_RT_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1950_ZAMBIA
 *
 *  Zambia
 */
#define SRM_RTCOD_ARC_1950_ZAMBIA ((SRM_RT_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1960_3_KENYA
 *
 *  Kenya
 */
#define SRM_RTCOD_ARC_1960_3_KENYA ((SRM_RT_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1960_MEAN_SOLUTION
 *
 *  Mean Solution (Kenya and Tanzania)
 */
#define SRM_RTCOD_ARC_1960_MEAN_SOLUTION ((SRM_RT_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARC_1960_TANZANIA
 *
 *  Tanzania
 */
#define SRM_RTCOD_ARC_1960_TANZANIA ((SRM_RT_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ARIEL_1988_IDENTITY
 *
 *  Global (Ariel)
 */
#define SRM_RTCOD_ARIEL_1988_IDENTITY ((SRM_RT_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ASCENSION_1958_ASCENSION_ISLAND
 *
 *  Ascension Island
 */
#define SRM_RTCOD_ASCENSION_1958_ASCENSION_ISLAND ((SRM_RT_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ATLAS_1988_IDENTITY
 *
 *  Global (Atlas)
 */
#define SRM_RTCOD_ATLAS_1988_IDENTITY ((SRM_RT_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA
 *
 *  Australia and Tasmania
 */
#define SRM_RTCOD_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA ((SRM_RT_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA
 *
 *  Australia and Tasmania
 */
#define SRM_RTCOD_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA ((SRM_RT_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA
 *
 *  Australia and Tasmania
 */
#define SRM_RTCOD_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA ((SRM_RT_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_AYABELLE_LIGHTHOUSE_1991_DJIBOUTI
 *
 *  Djibouti
 */
#define SRM_RTCOD_AYABELLE_LIGHTHOUSE_1991_DJIBOUTI ((SRM_RT_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BEACON_E_1945_IWO_JIMA_ISLAND
 *
 *  Iwo Jima Island
 */
#define SRM_RTCOD_BEACON_E_1945_IWO_JIMA_ISLAND ((SRM_RT_Code)37)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BELINDA_1988_IDENTITY
 *
 *  Global (Belinda)
 */
#define SRM_RTCOD_BELINDA_1988_IDENTITY ((SRM_RT_Code)38)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS
 *
 *  Efate and Erromango Islands (Vanuatu)
 */
#define SRM_RTCOD_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS ((SRM_RT_Code)39)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BERMUDA_1957_BERMUDA
 *
 *  Bermuda
 */
#define SRM_RTCOD_BERMUDA_1957_BERMUDA ((SRM_RT_Code)40)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BIANCA_1988_IDENTITY
 *
 *  Global (Bianca)
 */
#define SRM_RTCOD_BIANCA_1988_IDENTITY ((SRM_RT_Code)41)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BISSAU_1991_GUINEA_BISSAU
 *
 *  Guinea-Bissau
 */
#define SRM_RTCOD_BISSAU_1991_GUINEA_BISSAU ((SRM_RT_Code)42)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BOGOTA_OBS_1987_COLOMBIA
 *
 *  Colombia
 */
#define SRM_RTCOD_BOGOTA_OBS_1987_COLOMBIA ((SRM_RT_Code)43)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BOGOTA_OBS_1987_PM_BOGOTA_COLOMBIA
 *
 *  Colombia
 */
#define SRM_RTCOD_BOGOTA_OBS_1987_PM_BOGOTA_COLOMBIA ((SRM_RT_Code)44)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS
 *
 *  Bangka and Belitung Islands (Indonesia)
 */
#define SRM_RTCOD_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS ((SRM_RT_Code)45)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CALLISTO_2000_IDENTITY
 *
 *  Global (Callisto)
 */
#define SRM_RTCOD_CALLISTO_2000_IDENTITY ((SRM_RT_Code)46)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CALYPSO_1988_IDENTITY
 *
 *  Global (Calypso)
 */
#define SRM_RTCOD_CALYPSO_1988_IDENTITY ((SRM_RT_Code)47)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CAMP_AREA_1987_MCMURDO_CAMP
 *
 *  McMurdo Camp Area (Antarctica)
 */
#define SRM_RTCOD_CAMP_AREA_1987_MCMURDO_CAMP ((SRM_RT_Code)48)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CAMPO_INCHAUSPE_1969_ARGENTINA
 *
 *  Argentina
 */
#define SRM_RTCOD_CAMPO_INCHAUSPE_1969_ARGENTINA ((SRM_RT_Code)49)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CANTON_1966_PHOENIX_ISLANDS
 *
 *  Phoenix Islands
 */
#define SRM_RTCOD_CANTON_1966_PHOENIX_ISLANDS ((SRM_RT_Code)50)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CAPE_1987_SOUTH_AFRICA
 *
 *  South Africa
 */
#define SRM_RTCOD_CAPE_1987_SOUTH_AFRICA ((SRM_RT_Code)51)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CAPE_CANAVERAL_1991_MEAN_SOLUTION
 *
 *  Mean Solution (Bahamas and Florida)
 */
#define SRM_RTCOD_CAPE_CANAVERAL_1991_MEAN_SOLUTION ((SRM_RT_Code)52)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CARTHAGE_1987_TUNISIA
 *
 *  Tunisia
 */
#define SRM_RTCOD_CARTHAGE_1987_TUNISIA ((SRM_RT_Code)53)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CHARON_1991_IDENTITY
 *
 *  Global (Charon)
 */
#define SRM_RTCOD_CHARON_1991_IDENTITY ((SRM_RT_Code)54)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CHATHAM_1971_CHATHAM_ISLANDS
 *
 *  Chatham Islands (New Zealand)
 */
#define SRM_RTCOD_CHATHAM_1971_CHATHAM_ISLANDS ((SRM_RT_Code)55)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CHUA_1987_PARAGUAY
 *
 *  Paraguay
 */
#define SRM_RTCOD_CHUA_1987_PARAGUAY ((SRM_RT_Code)56)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_COAMPS_1998_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_COAMPS_1998_IDENTITY_BY_DEFAULT ((SRM_RT_Code)57)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CORDELIA_1988_IDENTITY
 *
 *  Global (Cordelia)
 */
#define SRM_RTCOD_CORDELIA_1988_IDENTITY ((SRM_RT_Code)58)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CORREGO_ALEGRE_1987_BRAZIL
 *
 *  Brazil
 */
#define SRM_RTCOD_CORREGO_ALEGRE_1987_BRAZIL ((SRM_RT_Code)59)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_CRESSIDA_1988_IDENTITY
 *
 *  Global (Cressida)
 */
#define SRM_RTCOD_CRESSIDA_1988_IDENTITY ((SRM_RT_Code)60)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DABOLA_1991_GUINEA
 *
 *  Guinea
 */
#define SRM_RTCOD_DABOLA_1991_GUINEA ((SRM_RT_Code)61)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DECEPTION_1993_DECEPTION_ISLAND
 *
 *  Deception Island (Antarctica)
 */
#define SRM_RTCOD_DECEPTION_1993_DECEPTION_ISLAND ((SRM_RT_Code)62)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DEIMOS_1988_IDENTITY
 *
 *  Global (Deimos)
 */
#define SRM_RTCOD_DEIMOS_1988_IDENTITY ((SRM_RT_Code)63)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DESDEMONA_1988_IDENTITY
 *
 *  Global (Desdemona)
 */
#define SRM_RTCOD_DESDEMONA_1988_IDENTITY ((SRM_RT_Code)64)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DESPINA_1991_IDENTITY
 *
 *  Global (Despina)
 */
#define SRM_RTCOD_DESPINA_1991_IDENTITY ((SRM_RT_Code)65)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DIONE_1982_IDENTITY
 *
 *  Global (Dione)
 */
#define SRM_RTCOD_DIONE_1982_IDENTITY ((SRM_RT_Code)66)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DJAKARTA_1987_PM_DJAKARTA_SUMATRA
 *
 *  Sumatra (Indonesia)
 */
#define SRM_RTCOD_DJAKARTA_1987_PM_DJAKARTA_SUMATRA ((SRM_RT_Code)67)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DJAKARTA_1987_SUMATRA
 *
 *  Sumatra (Indonesia)
 */
#define SRM_RTCOD_DJAKARTA_1987_SUMATRA ((SRM_RT_Code)68)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DOS_1968_GIZO_ISLAND
 *
 *  Gizo Island (New Georgia Islands)
 */
#define SRM_RTCOD_DOS_1968_GIZO_ISLAND ((SRM_RT_Code)69)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_DOS_71_4_1987_ST_HELENA_ISLAND
 *
 *  St. Helena Island
 */
#define SRM_RTCOD_DOS_71_4_1987_ST_HELENA_ISLAND ((SRM_RT_Code)70)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EASTER_1967_EASTER_ISLAND
 *
 *  Easter Island
 */
#define SRM_RTCOD_EASTER_1967_EASTER_ISLAND ((SRM_RT_Code)71)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ENCELADUS_1994_IDENTITY
 *
 *  Global (Enceladus)
 */
#define SRM_RTCOD_ENCELADUS_1994_IDENTITY ((SRM_RT_Code)72)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EPIMETHEUS_1988_IDENTITY
 *
 *  Global (Epimetheus)
 */
#define SRM_RTCOD_EPIMETHEUS_1988_IDENTITY ((SRM_RT_Code)73)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EROS_2000_IDENTITY
 *
 *  Global (Eros)
 */
#define SRM_RTCOD_EROS_2000_IDENTITY ((SRM_RT_Code)74)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ESTONIA_1937_ESTONIA
 *
 *  Estonia
 */
#define SRM_RTCOD_ESTONIA_1937_ESTONIA ((SRM_RT_Code)75)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ETRS_1989_IDENTITY_BY_MEASUREMENT
 *
 *  Europe
 */
#define SRM_RTCOD_ETRS_1989_IDENTITY_BY_MEASUREMENT ((SRM_RT_Code)76)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPA_2000_IDENTITY
 *
 *  Global (Europa)
 */
#define SRM_RTCOD_EUROPA_2000_IDENTITY ((SRM_RT_Code)77)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_3_CYPRUS
 *
 *  Cyprus
 */
#define SRM_RTCOD_EUROPE_1950_3_CYPRUS ((SRM_RT_Code)78)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_CHANNEL_ISLANDS
 *
 *  Channel Islands
 */
#define SRM_RTCOD_EUROPE_1950_CHANNEL_ISLANDS ((SRM_RT_Code)79)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_EGYPT
 *
 *  Egypt
 */
#define SRM_RTCOD_EUROPE_1950_EGYPT ((SRM_RT_Code)80)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_ENGLAND_SCOTLAND
 *
 *  England, Scotland, Channel Islands and Shetland Islands
 */
#define SRM_RTCOD_EUROPE_1950_ENGLAND_SCOTLAND ((SRM_RT_Code)81)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_GREECE
 *
 *  Greece
 */
#define SRM_RTCOD_EUROPE_1950_GREECE ((SRM_RT_Code)82)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_IRAN
 *
 *  Iran
 */
#define SRM_RTCOD_EUROPE_1950_IRAN ((SRM_RT_Code)83)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_IRAQ
 *
 *  Iraq
 */
#define SRM_RTCOD_EUROPE_1950_IRAQ ((SRM_RT_Code)84)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_IRELAND
 *
 *  Ireland, Northern Ireland, Wales, England, Scotland, Channel Islands,
 *  and Shetland Islands
 */
#define SRM_RTCOD_EUROPE_1950_IRELAND ((SRM_RT_Code)85)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_MALTA
 *
 *  Malta
 */
#define SRM_RTCOD_EUROPE_1950_MALTA ((SRM_RT_Code)86)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_MEAN_SOLUTION
 *
 *  Mean Solution (Austria, Belgium, Denmark, Finland, France, FRG,
 *  Gibraltar, Greece, Italy, Luxembourg, Netherlands, Norway, Portugal,
 *  Spain, Sweden and Switzerland)
 */
#define SRM_RTCOD_EUROPE_1950_MEAN_SOLUTION ((SRM_RT_Code)87)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_NORWAY
 *
 *  Finland and Norway
 */
#define SRM_RTCOD_EUROPE_1950_NORWAY ((SRM_RT_Code)88)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_PORTUGAL_SPAIN
 *
 *  Portugal and Spain
 */
#define SRM_RTCOD_EUROPE_1950_PORTUGAL_SPAIN ((SRM_RT_Code)89)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_SARDINIA
 *
 *  Sardinia (Italy)
 */
#define SRM_RTCOD_EUROPE_1950_SARDINIA ((SRM_RT_Code)90)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_SICILY
 *
 *  Sicily (Italy)
 */
#define SRM_RTCOD_EUROPE_1950_SICILY ((SRM_RT_Code)91)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_TUNISIA
 *
 *  Tunisia
 */
#define SRM_RTCOD_EUROPE_1950_TUNISIA ((SRM_RT_Code)92)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1950_W_EUROPE_MEAN_SOLUTION
 *
 *  Western Europe Mean Solution (Austria, Denmark, France, FRG,
 *  Netherlands and Switzerland)
 */
#define SRM_RTCOD_EUROPE_1950_W_EUROPE_MEAN_SOLUTION ((SRM_RT_Code)93)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_EUROPE_1979_MEAN_SOLUTION
 *
 *  Mean Solution (Austria, Finland, Netherlands, Norway, Spain, Sweden
 *  and Switzerland)
 */
#define SRM_RTCOD_EUROPE_1979_MEAN_SOLUTION ((SRM_RT_Code)94)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_FAHUD_1987_3_OMAN
 *
 *  Oman
 */
#define SRM_RTCOD_FAHUD_1987_3_OMAN ((SRM_RT_Code)95)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_FAHUD_1987_7_OMAN
 *
 *  Oman
 */
#define SRM_RTCOD_FAHUD_1987_7_OMAN ((SRM_RT_Code)96)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS
 *
 *  St. Kitts, Nevis and Leeward Islands
 */
#define SRM_RTCOD_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS ((SRM_RT_Code)97)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GALATEA_1991_IDENTITY
 *
 *  Global (Galatea)
 */
#define SRM_RTCOD_GALATEA_1991_IDENTITY ((SRM_RT_Code)98)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GAN_1970_MALDIVES
 *
 *  Republic of Maldives
 */
#define SRM_RTCOD_GAN_1970_MALDIVES ((SRM_RT_Code)99)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GANYMEDE_2000_IDENTITY
 *
 *  Global (Ganymede)
 */
#define SRM_RTCOD_GANYMEDE_2000_IDENTITY ((SRM_RT_Code)100)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GASPRA_1991_IDENTITY
 *
 *  Global (Gaspra)
 */
#define SRM_RTCOD_GASPRA_1991_IDENTITY ((SRM_RT_Code)101)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GDA_1994_IDENTITY_BY_MEASUREMENT
 *
 *  Australia
 */
#define SRM_RTCOD_GDA_1994_IDENTITY_BY_MEASUREMENT ((SRM_RT_Code)102)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEODETIC_DATUM_1949_3_NEW_ZEALAND
 *
 *  New Zealand
 */
#define SRM_RTCOD_GEODETIC_DATUM_1949_3_NEW_ZEALAND ((SRM_RT_Code)103)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEODETIC_DATUM_1949_7_NEW_ZEALAND
 *
 *  New Zealand
 */
#define SRM_RTCOD_GEODETIC_DATUM_1949_7_NEW_ZEALAND ((SRM_RT_Code)104)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1945_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1945_DGRF ((SRM_RT_Code)105)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1950_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1950_DGRF ((SRM_RT_Code)106)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1955_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1955_DGRF ((SRM_RT_Code)107)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1960_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1960_DGRF ((SRM_RT_Code)108)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1965_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1965_DGRF ((SRM_RT_Code)109)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1970_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1970_DGRF ((SRM_RT_Code)110)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1975_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1975_DGRF ((SRM_RT_Code)111)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1980_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1980_DGRF ((SRM_RT_Code)112)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1985_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1985_DGRF ((SRM_RT_Code)113)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1990_DGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1990_DGRF ((SRM_RT_Code)114)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_1995_IGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_1995_IGRF ((SRM_RT_Code)115)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GEOMAGNETIC_2000_IGRF
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_GEOMAGNETIC_2000_IGRF ((SRM_RT_Code)116)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES
 *
 *  Central Azores (Faial, Graciosa, Pico, Sao Jorge and Terceira Islands)
 */
#define SRM_RTCOD_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES ((SRM_RT_Code)117)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GUAM_1963_GUAM
 *
 *  Guam
 */
#define SRM_RTCOD_GUAM_1963_GUAM ((SRM_RT_Code)118)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND
 *
 *  Kalimantan Island (Indonesia)
 */
#define SRM_RTCOD_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND ((SRM_RT_Code)119)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_GUX_1_1987_GUADALCANAL_ISLAND
 *
 *  Guadalcanal Island
 */
#define SRM_RTCOD_GUX_1_1987_GUADALCANAL_ISLAND ((SRM_RT_Code)120)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_HELENE_1992_IDENTITY
 *
 *  Global (Helene)
 */
#define SRM_RTCOD_HELENE_1992_IDENTITY ((SRM_RT_Code)121)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_HERAT_NORTH_1987_AFGHANISTAN
 *
 *  Afghanistan
 */
#define SRM_RTCOD_HERAT_NORTH_1987_AFGHANISTAN ((SRM_RT_Code)122)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_HERMANNSKOGEL_1871_3_YUGOSLAVIA
 *
 *  Yugoslavia (prior to 1990), Slovenia, Croatia, Bosnia and Herzegovina,
 *  and Serbia
 */
#define SRM_RTCOD_HERMANNSKOGEL_1871_3_YUGOSLAVIA ((SRM_RT_Code)123)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_HJORSEY_1955_ICELAND
 *
 *  Iceland
 */
#define SRM_RTCOD_HJORSEY_1955_ICELAND ((SRM_RT_Code)124)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_HONG_KONG_1963_HONG_KONG
 *
 *  Hong Kong
 */
#define SRM_RTCOD_HONG_KONG_1963_HONG_KONG ((SRM_RT_Code)125)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_HU_TZU_SHAN_1991_TAIWAN
 *
 *  Taiwan
 */
#define SRM_RTCOD_HU_TZU_SHAN_1991_TAIWAN ((SRM_RT_Code)126)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_IAPETUS_1988_IDENTITY
 *
 *  Global (Iapetus)
 */
#define SRM_RTCOD_IAPETUS_1988_IDENTITY ((SRM_RT_Code)127)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_IDA_1991_IDENTITY
 *
 *  Global (Ida)
 */
#define SRM_RTCOD_IDA_1991_IDENTITY ((SRM_RT_Code)128)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1916_3_BANGLADESH
 *
 *  Bangladesh
 */
#define SRM_RTCOD_INDIAN_1916_3_BANGLADESH ((SRM_RT_Code)129)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1916_7_BANGLADESH
 *
 *  Bangladesh
 */
#define SRM_RTCOD_INDIAN_1916_7_BANGLADESH ((SRM_RT_Code)130)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1954_THAILAND
 *
 *  Thailand
 */
#define SRM_RTCOD_INDIAN_1954_THAILAND ((SRM_RT_Code)131)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1956_INDIA_NEPAL
 *
 *  India and Nepal
 */
#define SRM_RTCOD_INDIAN_1956_INDIA_NEPAL ((SRM_RT_Code)132)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1960_CON_SON_ISLAND
 *
 *  Con Son Island (Vietnam)
 */
#define SRM_RTCOD_INDIAN_1960_CON_SON_ISLAND ((SRM_RT_Code)133)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1960_VIETNAM_16_N
 *
 *  Vietnam (near 16'N)
 */
#define SRM_RTCOD_INDIAN_1960_VIETNAM_16_N ((SRM_RT_Code)134)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1962_PAKISTAN
 *
 *  Pakistan
 */
#define SRM_RTCOD_INDIAN_1962_PAKISTAN ((SRM_RT_Code)135)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1975_1991_THAILAND
 *
 *  Thailand
 */
#define SRM_RTCOD_INDIAN_1975_1991_THAILAND ((SRM_RT_Code)136)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDIAN_1975_1997_THAILAND
 *
 *  Thailand
 */
#define SRM_RTCOD_INDIAN_1975_1997_THAILAND ((SRM_RT_Code)137)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_INDONESIAN_1974_INDONESIA
 *
 *  Indonesia
 */
#define SRM_RTCOD_INDONESIAN_1974_INDONESIA ((SRM_RT_Code)138)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_IO_2000_IDENTITY
 *
 *  Global (Io)
 */
#define SRM_RTCOD_IO_2000_IDENTITY ((SRM_RT_Code)139)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_IRELAND_1965_3_IRELAND
 *
 *  Ireland
 */
#define SRM_RTCOD_IRELAND_1965_3_IRELAND ((SRM_RT_Code)140)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_IRELAND_1965_7_IRELAND
 *
 *  Ireland
 */
#define SRM_RTCOD_IRELAND_1965_7_IRELAND ((SRM_RT_Code)141)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ISTS_061_1968_SOUTH_GEORGIA_ISLAND
 *
 *  South Georgia Island
 */
#define SRM_RTCOD_ISTS_061_1968_SOUTH_GEORGIA_ISLAND ((SRM_RT_Code)142)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ISTS_073_1969_DIEGO_GARCIA
 *
 *  Diego Garcia
 */
#define SRM_RTCOD_ISTS_073_1969_DIEGO_GARCIA ((SRM_RT_Code)143)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_JANUS_1988_IDENTITY
 *
 *  Global (Janus)
 */
#define SRM_RTCOD_JANUS_1988_IDENTITY ((SRM_RT_Code)144)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_JGD_2000_IDENTITY_BY_MEASUREMENT
 *
 *  Japan
 */
#define SRM_RTCOD_JGD_2000_IDENTITY_BY_MEASUREMENT ((SRM_RT_Code)145)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_JOHNSTON_1961_JOHNSTON_ISLAND
 *
 *  Johnston Island
 */
#define SRM_RTCOD_JOHNSTON_1961_JOHNSTON_ISLAND ((SRM_RT_Code)146)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_JULIET_1988_IDENTITY
 *
 *  Global (Juliet)
 */
#define SRM_RTCOD_JULIET_1988_IDENTITY ((SRM_RT_Code)147)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_JUPITER_1988_IDENTITY
 *
 *  Global (Jupiter)
 */
#define SRM_RTCOD_JUPITER_1988_IDENTITY ((SRM_RT_Code)148)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_JUPITER_MAGNETIC_1993_VOYAGER
 *
 *  Global (Jupiter)
 */
#define SRM_RTCOD_JUPITER_MAGNETIC_1993_VOYAGER ((SRM_RT_Code)149)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_KANDAWALA_1987_3_SRI_LANKA
 *
 *  Sri Lanka
 */
#define SRM_RTCOD_KANDAWALA_1987_3_SRI_LANKA ((SRM_RT_Code)150)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_KERGUELEN_1949_KERGUELEN_ISLAND
 *
 *  Kerguelen Island
 */
#define SRM_RTCOD_KERGUELEN_1949_KERGUELEN_ISLAND ((SRM_RT_Code)151)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_KERTAU_1948_3_W_MALAYSIA_SINGAPORE
 *
 *  West Malaysia and Singapore
 */
#define SRM_RTCOD_KERTAU_1948_3_W_MALAYSIA_SINGAPORE ((SRM_RT_Code)152)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_KOREAN_GEODETIC_1995_SOUTH_KOREA
 *
 *  South Korea
 */
#define SRM_RTCOD_KOREAN_GEODETIC_1995_SOUTH_KOREA ((SRM_RT_Code)153)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_KUSAIE_1951_CAROLINE_ISLANDS
 *
 *  Caroline Islands (Federated States of Micronesia)
 */
#define SRM_RTCOD_KUSAIE_1951_CAROLINE_ISLANDS ((SRM_RT_Code)154)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_LARISSA_1991_IDENTITY
 *
 *  Global (Larissa)
 */
#define SRM_RTCOD_LARISSA_1991_IDENTITY ((SRM_RT_Code)155)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_LC5_1961_CAYMAN_BRAC_ISLAND
 *
 *  Cayman Brac Island
 */
#define SRM_RTCOD_LC5_1961_CAYMAN_BRAC_ISLAND ((SRM_RT_Code)156)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_LEIGON_1991_3_GHANA
 *
 *  Ghana
 */
#define SRM_RTCOD_LEIGON_1991_3_GHANA ((SRM_RT_Code)157)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_LEIGON_1991_7_GHANA
 *
 *  Ghana
 */
#define SRM_RTCOD_LEIGON_1991_7_GHANA ((SRM_RT_Code)158)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_LIBERIA_1964_LIBERIA
 *
 *  Liberia
 */
#define SRM_RTCOD_LIBERIA_1964_LIBERIA ((SRM_RT_Code)159)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_LUZON_1987_MINDANAO_ISLAND
 *
 *  Mindanao Island (Philippines)
 */
#define SRM_RTCOD_LUZON_1987_MINDANAO_ISLAND ((SRM_RT_Code)160)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND
 *
 *  Philippines (excluding Mindanao Island)
 */
#define SRM_RTCOD_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND ((SRM_RT_Code)161)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_M_PORALOKO_1991_GABON
 *
 *  Gabon
 */
#define SRM_RTCOD_M_PORALOKO_1991_GABON ((SRM_RT_Code)162)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MAHE_1971_MAHE_ISLAND
 *
 *  Mahe Island (Seychelles)
 */
#define SRM_RTCOD_MAHE_1971_MAHE_ISLAND ((SRM_RT_Code)163)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MARCUS_STATION_1952_MARCUS_ISLANDS
 *
 *  Marcus Islands
 */
#define SRM_RTCOD_MARCUS_STATION_1952_MARCUS_ISLANDS ((SRM_RT_Code)164)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MARS_2000_IDENTITY
 *
 *  Global (Mars)
 */
#define SRM_RTCOD_MARS_2000_IDENTITY ((SRM_RT_Code)165)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MARS_SPHERE_2000_GLOBAL
 *
 *  Global (Mars)
 */
#define SRM_RTCOD_MARS_SPHERE_2000_GLOBAL ((SRM_RT_Code)166)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MASS_1999_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_MASS_1999_IDENTITY_BY_DEFAULT ((SRM_RT_Code)167)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MASSAWA_1987_ERITREA_ETHIOPIA
 *
 *  Eritrea and Ethiopia
 */
#define SRM_RTCOD_MASSAWA_1987_ERITREA_ETHIOPIA ((SRM_RT_Code)168)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MERCHICH_1987_MOROCCO
 *
 *  Morocco
 */
#define SRM_RTCOD_MERCHICH_1987_MOROCCO ((SRM_RT_Code)169)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MERCURY_1988_IDENTITY
 *
 *  Global (Mercury)
 */
#define SRM_RTCOD_MERCURY_1988_IDENTITY ((SRM_RT_Code)170)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_METIS_2000_IDENTITY
 *
 *  Global (Metis)
 */
#define SRM_RTCOD_METIS_2000_IDENTITY ((SRM_RT_Code)171)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MIDWAY_1961_MIDWAY_ISLANDS
 *
 *  Midway Islands
 */
#define SRM_RTCOD_MIDWAY_1961_MIDWAY_ISLANDS ((SRM_RT_Code)172)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MIMAS_1994_IDENTITY
 *
 *  Global (Mimas)
 */
#define SRM_RTCOD_MIMAS_1994_IDENTITY ((SRM_RT_Code)173)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MINNA_1991_CAMEROON
 *
 *  Cameroon
 */
#define SRM_RTCOD_MINNA_1991_CAMEROON ((SRM_RT_Code)174)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MINNA_1991_NIGERIA
 *
 *  Nigeria
 */
#define SRM_RTCOD_MINNA_1991_NIGERIA ((SRM_RT_Code)175)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MIRANDA_1988_IDENTITY
 *
 *  Global (Miranda)
 */
#define SRM_RTCOD_MIRANDA_1988_IDENTITY ((SRM_RT_Code)176)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MM5_1997_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_MM5_1997_IDENTITY_BY_DEFAULT ((SRM_RT_Code)177)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MODTRAN_MIDLATITUDE_N_1989_IDENTITY_BY_DEFAULT
 *
 *  Northern midlatitude regions (Earth)
 */
#define SRM_RTCOD_MODTRAN_MIDLATITUDE_N_1989_IDENTITY_BY_DEFAULT ((SRM_RT_Code)178)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MODTRAN_MIDLATITUDE_S_1989_IDENTITY_BY_DEFAULT
 *
 *  Southern midlatitude regions (Earth)
 */
#define SRM_RTCOD_MODTRAN_MIDLATITUDE_S_1989_IDENTITY_BY_DEFAULT ((SRM_RT_Code)179)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MODTRAN_SUBARCTIC_N_1989_IDENTITY_BY_DEFAULT
 *
 *  Northern subarctic regions (Earth)
 */
#define SRM_RTCOD_MODTRAN_SUBARCTIC_N_1989_IDENTITY_BY_DEFAULT ((SRM_RT_Code)180)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MODTRAN_SUBARCTIC_S_1989_IDENTITY_BY_DEFAULT
 *
 *  Southern subarctic regions (Earth)
 */
#define SRM_RTCOD_MODTRAN_SUBARCTIC_S_1989_IDENTITY_BY_DEFAULT ((SRM_RT_Code)181)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT
 *
 *  Tropical regions (Earth)
 */
#define SRM_RTCOD_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT ((SRM_RT_Code)182)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS
 *
 *  Montserrat and Leeward Islands
 */
#define SRM_RTCOD_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS ((SRM_RT_Code)183)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MOON_1991_IDENTITY
 *
 *  Global (Moon)
 */
#define SRM_RTCOD_MOON_1991_IDENTITY ((SRM_RT_Code)184)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_MULTIGEN_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_MULTIGEN_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT ((SRM_RT_Code)185)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS
 *
 *  Alaska (excluding Aleutian Islands)
 */
#define SRM_RTCOD_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS ((SRM_RT_Code)186)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_ALBERTA_BRITISH_COLUMBIA
 *
 *  Canada (Alberta and British Columbia)
 */
#define SRM_RTCOD_N_AM_1927_ALBERTA_BRITISH_COLUMBIA ((SRM_RT_Code)187)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND
 *
 *  Bahamas (excluding San Salvador Island)
 */
#define SRM_RTCOD_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND ((SRM_RT_Code)188)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_CANADA
 *
 *  Canada
 */
#define SRM_RTCOD_N_AM_1927_CANADA ((SRM_RT_Code)189)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_CANAL_ZONE
 *
 *  Canal Zone
 */
#define SRM_RTCOD_N_AM_1927_CANAL_ZONE ((SRM_RT_Code)190)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_CARIBBEAN
 *
 *  Caribbean (Antigua Island, Barbados, Barbuda, Caicos Islands, Cuba,
 *  Dominican Republic, Grand Cayman, Jamaica and Turks Islands)
 */
#define SRM_RTCOD_N_AM_1927_CARIBBEAN ((SRM_RT_Code)191)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_CENTRAL_AMERICA
 *
 *  Central America (Belize, Costa Rica, El Salvador, Guatemala, Honduras
 *  and Nicaragua)
 */
#define SRM_RTCOD_N_AM_1927_CENTRAL_AMERICA ((SRM_RT_Code)192)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_CONTINENTAL_US
 *
 *  Continental United States Mean Solution
 */
#define SRM_RTCOD_N_AM_1927_CONTINENTAL_US ((SRM_RT_Code)193)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_CUBA
 *
 *  Cuba
 */
#define SRM_RTCOD_N_AM_1927_CUBA ((SRM_RT_Code)194)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_EAST_ALEUTIAN_ISLANDS
 *
 *  Aleutian Islands (east of 180'W)
 */
#define SRM_RTCOD_N_AM_1927_EAST_ALEUTIAN_ISLANDS ((SRM_RT_Code)195)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_EASTERN_CANADA
 *
 *  Eastern Canada (New Brunswick, Newfoundland, Nova Scotia and Quebec)
 */
#define SRM_RTCOD_N_AM_1927_EASTERN_CANADA ((SRM_RT_Code)196)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_EASTERN_US
 *
 *  Eastern United States (Alabama, Connecticut, Delaware, District of
 *  Columbia, Florida, Georgia, Illinois, Indiana, Kentucky, Louisiana,
 *  Maine, Maryland, Massachusetts, Michigan, Minnesota, Mississippi,
 *  Missouri, New Hampshire, New Jersey, New York, North Carolina, Ohio,
 *  Pennsylvania, Rhode Island, South Carolina, Tennessee, Vermont,
 *  Virginia, West Virginia and Wisconsin)
 */
#define SRM_RTCOD_N_AM_1927_EASTERN_US ((SRM_RT_Code)197)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_HAYES_PENINSULA
 *
 *  Hayes Peninsula (Greenland)
 */
#define SRM_RTCOD_N_AM_1927_HAYES_PENINSULA ((SRM_RT_Code)198)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_MANITOBA_ONTARIO
 *
 *  Canada (Manitoba and Ontario)
 */
#define SRM_RTCOD_N_AM_1927_MANITOBA_ONTARIO ((SRM_RT_Code)199)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_MEXICO
 *
 *  Mexico
 */
#define SRM_RTCOD_N_AM_1927_MEXICO ((SRM_RT_Code)200)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN
 *
 *  Canada (Northwest Territories and Saskatchewan)
 */
#define SRM_RTCOD_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN ((SRM_RT_Code)201)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_SAN_SALVADOR_ISLAND
 *
 *  San Salvador Island
 */
#define SRM_RTCOD_N_AM_1927_SAN_SALVADOR_ISLAND ((SRM_RT_Code)202)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_WEST_ALEUTIAN_ISLANDS
 *
 *  Aleutian Islands (west of 180'W)
 */
#define SRM_RTCOD_N_AM_1927_WEST_ALEUTIAN_ISLANDS ((SRM_RT_Code)203)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_WESTERN_US
 *
 *  Western United States (Arizona, Arkansas, California, Colorado, Idaho,
 *  Iowa, Kansas, Montana, Nebraska, Nevada, New Mexico, North Dakota,
 *  Oklahoma, Oregon, South Dakota, Texas, Utah, Washington and Wyoming)
 */
#define SRM_RTCOD_N_AM_1927_WESTERN_US ((SRM_RT_Code)204)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1927_YUKON
 *
 *  Canada (Yukon)
 */
#define SRM_RTCOD_N_AM_1927_YUKON ((SRM_RT_Code)205)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS
 *
 *  Alaska (excluding Aleutian Islands)
 */
#define SRM_RTCOD_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS ((SRM_RT_Code)206)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1983_ALEUTIAN_ISLANDS
 *
 *  Aleutian Islands
 */
#define SRM_RTCOD_N_AM_1983_ALEUTIAN_ISLANDS ((SRM_RT_Code)207)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1983_CANADA
 *
 *  Canada
 */
#define SRM_RTCOD_N_AM_1983_CANADA ((SRM_RT_Code)208)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1983_CONTINENTAL_US
 *
 *  Continental United States
 */
#define SRM_RTCOD_N_AM_1983_CONTINENTAL_US ((SRM_RT_Code)209)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1983_HAWAII
 *
 *  Hawaii
 */
#define SRM_RTCOD_N_AM_1983_HAWAII ((SRM_RT_Code)210)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_AM_1983_MEXICO_CENTRAL_AMERICA
 *
 *  Mexico and Central America
 */
#define SRM_RTCOD_N_AM_1983_MEXICO_CENTRAL_AMERICA ((SRM_RT_Code)211)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_N_SAHARA_1959_ALGERIA
 *
 *  Algeria
 */
#define SRM_RTCOD_N_SAHARA_1959_ALGERIA ((SRM_RT_Code)212)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NAHRWAN_1987_MASIRAH_ISLAND
 *
 *  Masirah Island (Oman)
 */
#define SRM_RTCOD_NAHRWAN_1987_MASIRAH_ISLAND ((SRM_RT_Code)213)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NAHRWAN_1987_SAUDI_ARABIA
 *
 *  Saudi Arabia
 */
#define SRM_RTCOD_NAHRWAN_1987_SAUDI_ARABIA ((SRM_RT_Code)214)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NAHRWAN_1987_UNITED_ARAB_EMIRATES
 *
 *  United Arab Emirates
 */
#define SRM_RTCOD_NAHRWAN_1987_UNITED_ARAB_EMIRATES ((SRM_RT_Code)215)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NAIAD_1991_IDENTITY
 *
 *  Global (Naiad)
 */
#define SRM_RTCOD_NAIAD_1991_IDENTITY ((SRM_RT_Code)216)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NAPARIMA_1991_TRINIDAD_TOBAGO
 *
 *  Trinidad and Tobago (British West Indies)
 */
#define SRM_RTCOD_NAPARIMA_1991_TRINIDAD_TOBAGO ((SRM_RT_Code)217)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NEPTUNE_1991_IDENTITY
 *
 *  Global (Neptune)
 */
#define SRM_RTCOD_NEPTUNE_1991_IDENTITY ((SRM_RT_Code)218)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NEPTUNE_MAGNETIC_1993_VOYAGER
 *
 *  Global (Neptune)
 */
#define SRM_RTCOD_NEPTUNE_MAGNETIC_1993_VOYAGER ((SRM_RT_Code)219)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NOGAPS_1988_IDENTITY_BY_DEFAULT
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_NOGAPS_1988_IDENTITY_BY_DEFAULT ((SRM_RT_Code)220)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NTF_1896_FRANCE
 *
 *  France
 */
#define SRM_RTCOD_NTF_1896_FRANCE ((SRM_RT_Code)221)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_NTF_1896_PM_PARIS_FRANCE
 *
 *  France
 */
#define SRM_RTCOD_NTF_1896_PM_PARIS_FRANCE ((SRM_RT_Code)222)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OBERON_1988_IDENTITY
 *
 *  Global (Oberon)
 */
#define SRM_RTCOD_OBERON_1988_IDENTITY ((SRM_RT_Code)223)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS
 *
 *  Corvo Flores Islands (Azores)
 */
#define SRM_RTCOD_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS ((SRM_RT_Code)224)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_EGYPTIAN_1907_EGYPT
 *
 *  Egypt
 */
#define SRM_RTCOD_OLD_EGYPTIAN_1907_EGYPT ((SRM_RT_Code)225)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_HAWAII
 *
 *  Hawaii (US)
 */
#define SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_HAWAII ((SRM_RT_Code)226)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_KAUAI
 *
 *  Kauai (US)
 */
#define SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_KAUAI ((SRM_RT_Code)227)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MAUI
 *
 *  Maui (US)
 */
#define SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MAUI ((SRM_RT_Code)228)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MEAN_SOLUTION
 *
 *  Mean Solution (Hawaii (US))
 */
#define SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MEAN_SOLUTION ((SRM_RT_Code)229)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_OAHU
 *
 *  Oahu (US)
 */
#define SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_OAHU ((SRM_RT_Code)230)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_INT_1987_HAWAII
 *
 *  Hawaii (US)
 */
#define SRM_RTCOD_OLD_HAWAIIAN_INT_1987_HAWAII ((SRM_RT_Code)231)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_INT_1987_KAUAI
 *
 *  Kauai (US)
 */
#define SRM_RTCOD_OLD_HAWAIIAN_INT_1987_KAUAI ((SRM_RT_Code)232)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MAUI
 *
 *  Maui (US)
 */
#define SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MAUI ((SRM_RT_Code)233)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MEAN_SOLUTION
 *
 *  Mean Solution (Hawaii (US))
 */
#define SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MEAN_SOLUTION ((SRM_RT_Code)234)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OLD_HAWAIIAN_INT_1987_OAHU
 *
 *  Oahu (US)
 */
#define SRM_RTCOD_OLD_HAWAIIAN_INT_1987_OAHU ((SRM_RT_Code)235)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OPHELIA_1988_IDENTITY
 *
 *  Global (Ophelia)
 */
#define SRM_RTCOD_OPHELIA_1988_IDENTITY ((SRM_RT_Code)236)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OSGB_1936_3_MEAN_SOLUTION
 *
 *  Mean Solution (England, Isle of Man, Scotland, Shetland, and Wales)
 */
#define SRM_RTCOD_OSGB_1936_3_MEAN_SOLUTION ((SRM_RT_Code)237)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OSGB_1936_7_GREAT_BRITAIN
 *
 *  Great Britain
 */
#define SRM_RTCOD_OSGB_1936_7_GREAT_BRITAIN ((SRM_RT_Code)238)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OSGB_1936_ENGLAND
 *
 *  England
 */
#define SRM_RTCOD_OSGB_1936_ENGLAND ((SRM_RT_Code)239)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES
 *
 *  England, Isle of Man, and Wales
 */
#define SRM_RTCOD_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES ((SRM_RT_Code)240)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS
 *
 *  Scotland and Shetland Islands
 */
#define SRM_RTCOD_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS ((SRM_RT_Code)241)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_OSGB_1936_WALES
 *
 *  Wales
 */
#define SRM_RTCOD_OSGB_1936_WALES ((SRM_RT_Code)242)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PAN_1991_IDENTITY
 *
 *  Global (Pan)
 */
#define SRM_RTCOD_PAN_1991_IDENTITY ((SRM_RT_Code)243)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PANDORA_1988_IDENTITY
 *
 *  Global (Pandora)
 */
#define SRM_RTCOD_PANDORA_1988_IDENTITY ((SRM_RT_Code)244)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PHOBOS_1988_IDENTITY
 *
 *  Global (Phobos)
 */
#define SRM_RTCOD_PHOBOS_1988_IDENTITY ((SRM_RT_Code)245)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PHOEBE_1988_IDENTITY
 *
 *  Global (Phoebe)
 */
#define SRM_RTCOD_PHOEBE_1988_IDENTITY ((SRM_RT_Code)246)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PICO_DE_LAS_NIEVES_1987_CANARY_ISLANDS
 *
 *  Canary Islands (Spain)
 */
#define SRM_RTCOD_PICO_DE_LAS_NIEVES_1987_CANARY_ISLANDS ((SRM_RT_Code)247)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PITCAIRN_1967_PITCAIRN_ISLAND
 *
 *  Pitcairn Island
 */
#define SRM_RTCOD_PITCAIRN_1967_PITCAIRN_ISLAND ((SRM_RT_Code)248)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PLUTO_1994_IDENTITY
 *
 *  Global (Pluto)
 */
#define SRM_RTCOD_PLUTO_1994_IDENTITY ((SRM_RT_Code)249)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_POINT_58_1991_MEAN_SOLUTION
 *
 *  Mean Solution (Burkina Faso and Niger)
 */
#define SRM_RTCOD_POINT_58_1991_MEAN_SOLUTION ((SRM_RT_Code)250)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_POINTE_NOIRE_1948_CONGO
 *
 *  Congo
 */
#define SRM_RTCOD_POINTE_NOIRE_1948_CONGO ((SRM_RT_Code)251)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PORTIA_1988_IDENTITY
 *
 *  Global (Portia)
 */
#define SRM_RTCOD_PORTIA_1988_IDENTITY ((SRM_RT_Code)252)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS
 *
 *  Porto Santo and Madeira Islands
 */
#define SRM_RTCOD_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS ((SRM_RT_Code)253)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROMETHEUS_1988_IDENTITY
 *
 *  Global (Prometheus)
 */
#define SRM_RTCOD_PROMETHEUS_1988_IDENTITY ((SRM_RT_Code)254)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROTEUS_1991_IDENTITY
 *
 *  Global (Proteus)
 */
#define SRM_RTCOD_PROTEUS_1991_IDENTITY ((SRM_RT_Code)255)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_3_VENEZUELA
 *
 *  Venezuela
 */
#define SRM_RTCOD_PROV_S_AM_1956_3_VENEZUELA ((SRM_RT_Code)256)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_7_VENEZUELA
 *
 *  Venezuela
 */
#define SRM_RTCOD_PROV_S_AM_1956_7_VENEZUELA ((SRM_RT_Code)257)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_BOLIVIA
 *
 *  Bolivia
 */
#define SRM_RTCOD_PROV_S_AM_1956_BOLIVIA ((SRM_RT_Code)258)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_COLOMBIA
 *
 *  Colombia
 */
#define SRM_RTCOD_PROV_S_AM_1956_COLOMBIA ((SRM_RT_Code)259)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_ECUADOR
 *
 *  Ecuador
 */
#define SRM_RTCOD_PROV_S_AM_1956_ECUADOR ((SRM_RT_Code)260)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_GUYANA
 *
 *  Guyana
 */
#define SRM_RTCOD_PROV_S_AM_1956_GUYANA ((SRM_RT_Code)261)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_MEAN_SOLUTION
 *
 *  Mean Solution (Bolivia, Chile, Colombia, Ecuador, Guyana, Peru and
 *  Venezuela)
 */
#define SRM_RTCOD_PROV_S_AM_1956_MEAN_SOLUTION ((SRM_RT_Code)262)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_N_CHILE_19_S
 *
 *  Northern Chile (near 19'S)
 */
#define SRM_RTCOD_PROV_S_AM_1956_N_CHILE_19_S ((SRM_RT_Code)263)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_PERU
 *
 *  Peru
 */
#define SRM_RTCOD_PROV_S_AM_1956_PERU ((SRM_RT_Code)264)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_AM_1956_S_CHILE_43_S
 *
 *  Southern Chile (near 43'S)
 */
#define SRM_RTCOD_PROV_S_AM_1956_S_CHILE_43_S ((SRM_RT_Code)265)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PROV_S_CHILEAN_1963_SOUTH_CHILE
 *
 *  South Chile (near 53'S)
 */
#define SRM_RTCOD_PROV_S_CHILEAN_1963_SOUTH_CHILE ((SRM_RT_Code)266)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PUCK_1988_IDENTITY
 *
 *  Global (Puck)
 */
#define SRM_RTCOD_PUCK_1988_IDENTITY ((SRM_RT_Code)267)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS
 *
 *  Puerto Rico and Virgin Islands
 */
#define SRM_RTCOD_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS ((SRM_RT_Code)268)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_PULKOVO_1942_RUSSIA
 *
 *  Russia
 */
#define SRM_RTCOD_PULKOVO_1942_RUSSIA ((SRM_RT_Code)269)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_QATAR_NATIONAL_1974_3_QATAR
 *
 *  Qatar
 */
#define SRM_RTCOD_QATAR_NATIONAL_1974_3_QATAR ((SRM_RT_Code)270)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_QORNOQ_1987_SOUTH_GREENLAND
 *
 *  South Greenland
 */
#define SRM_RTCOD_QORNOQ_1987_SOUTH_GREENLAND ((SRM_RT_Code)271)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_REUNION_1947_MASCARENE_ISLANDS
 *
 *  Mascarene Islands
 */
#define SRM_RTCOD_REUNION_1947_MASCARENE_ISLANDS ((SRM_RT_Code)272)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_RGF_1993_IDENTITY_BY_MEASUREMENT
 *
 *  France
 */
#define SRM_RTCOD_RGF_1993_IDENTITY_BY_MEASUREMENT ((SRM_RT_Code)273)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_RHEA_1988_IDENTITY
 *
 *  Global (Rhea)
 */
#define SRM_RTCOD_RHEA_1988_IDENTITY ((SRM_RT_Code)274)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ROME_1940_PM_ROME_SARDINIA
 *
 *  Sardinia (Italy)
 */
#define SRM_RTCOD_ROME_1940_PM_ROME_SARDINIA ((SRM_RT_Code)275)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ROME_1940_SARDINIA
 *
 *  Sardinia (Italy)
 */
#define SRM_RTCOD_ROME_1940_SARDINIA ((SRM_RT_Code)276)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ROSALIND_1988_IDENTITY
 *
 *  Global (Rosalind)
 */
#define SRM_RTCOD_ROSALIND_1988_IDENTITY ((SRM_RT_Code)277)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_ARGENTINA
 *
 *  Argentina
 */
#define SRM_RTCOD_S_AM_1969_ARGENTINA ((SRM_RT_Code)278)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS
 *
 *  Baltra and Galapagos Islands (Ecuador)
 */
#define SRM_RTCOD_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS ((SRM_RT_Code)279)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_BOLIVIA
 *
 *  Bolivia
 */
#define SRM_RTCOD_S_AM_1969_BOLIVIA ((SRM_RT_Code)280)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_BRAZIL
 *
 *  Brazil
 */
#define SRM_RTCOD_S_AM_1969_BRAZIL ((SRM_RT_Code)281)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_CHILE
 *
 *  Chile
 */
#define SRM_RTCOD_S_AM_1969_CHILE ((SRM_RT_Code)282)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_COLOMBIA
 *
 *  Colombia
 */
#define SRM_RTCOD_S_AM_1969_COLOMBIA ((SRM_RT_Code)283)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS
 *
 *  Ecuador (excluding Galapagos Islands)
 */
#define SRM_RTCOD_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS ((SRM_RT_Code)284)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_GUYANA
 *
 *  Guyana
 */
#define SRM_RTCOD_S_AM_1969_GUYANA ((SRM_RT_Code)285)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_MEAN_SOLUTION
 *
 *  Mean Solution (Argentina, Bolivia, Brazil, Chile, Colombia, Ecuador,
 *  Guyana, Paraguay, Peru, Trinidad and Tobago, and Venezuela)
 */
#define SRM_RTCOD_S_AM_1969_MEAN_SOLUTION ((SRM_RT_Code)286)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_PARAGUAY
 *
 *  Paraguay
 */
#define SRM_RTCOD_S_AM_1969_PARAGUAY ((SRM_RT_Code)287)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_PERU
 *
 *  Peru
 */
#define SRM_RTCOD_S_AM_1969_PERU ((SRM_RT_Code)288)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_TRINIDAD_TOBAGO
 *
 *  Trinidad and Tobago (British West Indies)
 */
#define SRM_RTCOD_S_AM_1969_TRINIDAD_TOBAGO ((SRM_RT_Code)289)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_AM_1969_VENEZUELA
 *
 *  Venezuela
 */
#define SRM_RTCOD_S_AM_1969_VENEZUELA ((SRM_RT_Code)290)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_ASIA_1987_SINGAPORE
 *
 *  Singapore
 */
#define SRM_RTCOD_S_ASIA_1987_SINGAPORE ((SRM_RT_Code)291)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_JTSK_1993_CZECH_REP
 *
 *  Czech Republic
 */
#define SRM_RTCOD_S_JTSK_1993_CZECH_REP ((SRM_RT_Code)292)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S_JTSK_1993_CZECH_REP_SLOVAKIA
 *
 *  Czech Republic and Slovakia
 */
#define SRM_RTCOD_S_JTSK_1993_CZECH_REP_SLOVAKIA ((SRM_RT_Code)293)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S42_PULKOVO_3_POLAND
 *
 *  Poland
 */
#define SRM_RTCOD_S42_PULKOVO_3_POLAND ((SRM_RT_Code)294)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S42_PULKOVO_ALBANIA
 *
 *  Albania
 */
#define SRM_RTCOD_S42_PULKOVO_ALBANIA ((SRM_RT_Code)295)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA
 *
 *  Czech Republic and Slovakia
 */
#define SRM_RTCOD_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA ((SRM_RT_Code)296)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S42_PULKOVO_G_ROMANIA
 *
 *  Romania
 */
#define SRM_RTCOD_S42_PULKOVO_G_ROMANIA ((SRM_RT_Code)297)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S42_PULKOVO_HUNGARY
 *
 *  Hungary
 */
#define SRM_RTCOD_S42_PULKOVO_HUNGARY ((SRM_RT_Code)298)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S42_PULKOVO_KAZAKHSTAN
 *
 *  Kazakhstan
 */
#define SRM_RTCOD_S42_PULKOVO_KAZAKHSTAN ((SRM_RT_Code)299)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_S42_PULKOVO_LATVIA
 *
 *  Latvia
 */
#define SRM_RTCOD_S42_PULKOVO_LATVIA ((SRM_RT_Code)300)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND
 *
 *  Espirito Santo Island (Vanuatu)
 */
#define SRM_RTCOD_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND ((SRM_RT_Code)301)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS
 *
 *  Sao Miguel and Santa Maria Islands (Azores)
 */
#define SRM_RTCOD_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS ((SRM_RT_Code)302)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS
 *
 *  East Falkland Islands
 */
#define SRM_RTCOD_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS ((SRM_RT_Code)303)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SATURN_1988_IDENTITY
 *
 *  Global (Saturn)
 */
#define SRM_RTCOD_SATURN_1988_IDENTITY ((SRM_RT_Code)304)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SATURN_MAGNETIC_1993_VOYAGER
 *
 *  Global (Saturn)
 */
#define SRM_RTCOD_SATURN_MAGNETIC_1993_VOYAGER ((SRM_RT_Code)305)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SCHWARZECK_1991_NAMIBIA
 *
 *  Namibia
 */
#define SRM_RTCOD_SCHWARZECK_1991_NAMIBIA ((SRM_RT_Code)306)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS
 *
 *  Salvage Islands (Ilhas Selvagens; Savage Islands)
 */
#define SRM_RTCOD_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS ((SRM_RT_Code)307)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SIERRA_LEONE_1960_SIERRA_LEONE
 *
 *  Sierra Leone
 */
#define SRM_RTCOD_SIERRA_LEONE_1960_SIERRA_LEONE ((SRM_RT_Code)308)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SIRGAS_2000_IDENTITY_BY_MEASUREMENT
 *
 *  South America
 */
#define SRM_RTCOD_SIRGAS_2000_IDENTITY_BY_MEASUREMENT ((SRM_RT_Code)309)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_SUN_1992_IDENTITY
 *
 *  Global (Sun)
 */
#define SRM_RTCOD_SUN_1992_IDENTITY ((SRM_RT_Code)310)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TANANARIVE_OBS_1925_3_MADAGASCAR
 *
 *  Madagascar
 */
#define SRM_RTCOD_TANANARIVE_OBS_1925_3_MADAGASCAR ((SRM_RT_Code)311)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TANANARIVE_OBS_1925_PM_PARIS_3_MADAGASCAR
 *
 *  Madagascar
 */
#define SRM_RTCOD_TANANARIVE_OBS_1925_PM_PARIS_3_MADAGASCAR ((SRM_RT_Code)312)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TELESTO_1988_IDENTITY
 *
 *  Global (Telesto)
 */
#define SRM_RTCOD_TELESTO_1988_IDENTITY ((SRM_RT_Code)313)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TERN_1961_TERN_ISLAND
 *
 *  Tern Island (French Frigate Shoals, Hawaiian Islands)
 */
#define SRM_RTCOD_TERN_1961_TERN_ISLAND ((SRM_RT_Code)314)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TETHYS_1991_IDENTITY
 *
 *  Global (Tethys)
 */
#define SRM_RTCOD_TETHYS_1991_IDENTITY ((SRM_RT_Code)315)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_THALASSA_1991_IDENTITY
 *
 *  Global (Thalassa)
 */
#define SRM_RTCOD_THALASSA_1991_IDENTITY ((SRM_RT_Code)316)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_THEBE_2000_IDENTITY
 *
 *  Global (Thebe)
 */
#define SRM_RTCOD_THEBE_2000_IDENTITY ((SRM_RT_Code)317)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TIMBALAI_EVEREST_1948_3_BRUNEI_E_MALAYSIA
 *
 *  Brunei and East Malaysia (Sabah and Sarawak)
 */
#define SRM_RTCOD_TIMBALAI_EVEREST_1948_3_BRUNEI_E_MALAYSIA ((SRM_RT_Code)318)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TIMBALAI_EVEREST_1948_7_BRUNEI_E_MALAYSIA
 *
 *  Brunei and East Malaysia (Sabah and Sarawak)
 */
#define SRM_RTCOD_TIMBALAI_EVEREST_1948_7_BRUNEI_E_MALAYSIA ((SRM_RT_Code)319)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TITAN_1982_IDENTITY
 *
 *  Global (Titan)
 */
#define SRM_RTCOD_TITAN_1982_IDENTITY ((SRM_RT_Code)320)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TITANIA_1988_IDENTITY
 *
 *  Global (Titania)
 */
#define SRM_RTCOD_TITANIA_1988_IDENTITY ((SRM_RT_Code)321)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TOKYO_1991_JAPAN
 *
 *  Japan
 */
#define SRM_RTCOD_TOKYO_1991_JAPAN ((SRM_RT_Code)322)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TOKYO_1991_MEAN_SOLUTION
 *
 *  Mean Solution (Japan, Korea, and Okinawa)
 */
#define SRM_RTCOD_TOKYO_1991_MEAN_SOLUTION ((SRM_RT_Code)323)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TOKYO_1991_OKINAWA
 *
 *  Okinawa (Japan)
 */
#define SRM_RTCOD_TOKYO_1991_OKINAWA ((SRM_RT_Code)324)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TOKYO_1991_1991_SOUTH_KOREA
 *
 *  South Korea
 */
#define SRM_RTCOD_TOKYO_1991_1991_SOUTH_KOREA ((SRM_RT_Code)325)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TOKYO_1991_1997_SOUTH_KOREA
 *
 *  South Korea
 */
#define SRM_RTCOD_TOKYO_1991_1997_SOUTH_KOREA ((SRM_RT_Code)326)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TRISTAN_1968_TRISTAN_DA_CUNHA
 *
 *  Tristan da Cunha
 */
#define SRM_RTCOD_TRISTAN_1968_TRISTAN_DA_CUNHA ((SRM_RT_Code)327)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_TRITON_1991_IDENTITY
 *
 *  Global (Triton)
 */
#define SRM_RTCOD_TRITON_1991_IDENTITY ((SRM_RT_Code)328)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_UMBRIEL_1988_IDENTITY
 *
 *  Global (Umbriel)
 */
#define SRM_RTCOD_UMBRIEL_1988_IDENTITY ((SRM_RT_Code)329)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_URANUS_1988_IDENTITY
 *
 *  Global (Uranus)
 */
#define SRM_RTCOD_URANUS_1988_IDENTITY ((SRM_RT_Code)330)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_URANUS_MAGNETIC_1993_VOYAGER
 *
 *  Global (Uranus)
 */
#define SRM_RTCOD_URANUS_MAGNETIC_1993_VOYAGER ((SRM_RT_Code)331)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_VENUS_1991_IDENTITY
 *
 *  Global (Venus)
 */
#define SRM_RTCOD_VENUS_1991_IDENTITY ((SRM_RT_Code)332)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_VITI_LEVU_1916_VITI_LEVU_ISLANDS
 *
 *  Viti Levu Island (Fiji Islands)
 */
#define SRM_RTCOD_VITI_LEVU_1916_VITI_LEVU_ISLANDS ((SRM_RT_Code)333)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_VOIROL_1874_ALGERIA
 *
 *  Algeria
 */
#define SRM_RTCOD_VOIROL_1874_ALGERIA ((SRM_RT_Code)334)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_VOIROL_1874_PM_PARIS_ALGERIA
 *
 *  Algeria
 */
#define SRM_RTCOD_VOIROL_1874_PM_PARIS_ALGERIA ((SRM_RT_Code)335)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_VOIROL_1960_ALGERIA
 *
 *  Algeria
 */
#define SRM_RTCOD_VOIROL_1960_ALGERIA ((SRM_RT_Code)336)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_VOIROL_1960_PM_PARIS_ALGERIA
 *
 *  Algeria
 */
#define SRM_RTCOD_VOIROL_1960_PM_PARIS_ALGERIA ((SRM_RT_Code)337)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_WAKE_1952_WAKE_ATOLL
 *
 *  Wake Atoll
 */
#define SRM_RTCOD_WAKE_1952_WAKE_ATOLL ((SRM_RT_Code)338)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS
 *
 *  Marshall Islands
 */
#define SRM_RTCOD_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS ((SRM_RT_Code)339)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_WGS_1972_GLOBAL
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_WGS_1972_GLOBAL ((SRM_RT_Code)340)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_WGS_1984_IDENTITY
 *
 *  Global (Earth)
 */
#define SRM_RTCOD_WGS_1984_IDENTITY ((SRM_RT_Code)341)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_YACARE_1987_URUGUAY
 *
 *  Uruguay
 */
#define SRM_RTCOD_YACARE_1987_URUGUAY ((SRM_RT_Code)342)

/*!
 * GLOBAL CONSTANT: SRM_RTCOD_ZANDERIJ_1987_SURINAME
 *
 *  Suriname
 */
#define SRM_RTCOD_ZANDERIJ_1987_SURINAME ((SRM_RT_Code)343)


/*! Upper Bound value for RT_Codes */
#define SRM_RT_CODE_UBOUND 343


/*!
 * REGISTERABLE ENUM: SRM_SRF_Code
 *
 *  SRF Codes
 */
typedef SRM_Integer SRM_SRF_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_UNSPECIFIED
 */
#define SRM_SRFCOD_UNSPECIFIED ((SRM_SRF_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY
 *
 *  British national grid. A transverse Mercator projection using the
 *  AIRY_1830 ellipsoid
 */
#define SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY ((SRM_SRF_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_BRITISH_OSGRS80_GRID
 *
 *  UK ordnance survey GRS80 grid. A transverse Mercator projection using
 *  the GRS_1980 ellipsoid.
 */
#define SRM_SRFCOD_BRITISH_OSGRS80_GRID ((SRM_SRF_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_DELAWARE_SPCS_1983
 *
 *  Delaware (US) state plane coordinate system
 */
#define SRM_SRFCOD_DELAWARE_SPCS_1983 ((SRM_SRF_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_GEOCENTRIC_WGS_1984
 *
 *  Geocentric WGS 1984
 */
#define SRM_SRFCOD_GEOCENTRIC_WGS_1984 ((SRM_SRF_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_GEODETIC_AUSTRALIA_1984
 *
 *  Geodetic Australia 1984
 */
#define SRM_SRFCOD_GEODETIC_AUSTRALIA_1984 ((SRM_SRF_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_GEODETIC_WGS_1984
 *
 *  Geodetic WGS 1984
 */
#define SRM_SRFCOD_GEODETIC_WGS_1984 ((SRM_SRF_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_GEODETIC_N_AMERICAN_1983
 *
 *  Geodetic north american 1983
 */
#define SRM_SRFCOD_GEODETIC_N_AMERICAN_1983 ((SRM_SRF_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_IRISH_GRID_1965
 *
 *  Irish grid
 */
#define SRM_SRFCOD_IRISH_GRID_1965 ((SRM_SRF_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989
 *
 *  Irish transverse Mercator
 */
#define SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989 ((SRM_SRF_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_LAMBERT_93
 *
 *  Lambert-93
 */
#define SRM_SRFCOD_LAMBERT_93 ((SRM_SRF_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_LAMBERT_II_WIDE
 *
 *  Lambert II etendu (Lambert II wide)
 */
#define SRM_SRFCOD_LAMBERT_II_WIDE ((SRM_SRF_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_MARS_PLANETOCENTRIC_2000
 *
 *  Mars planetocentric
 */
#define SRM_SRFCOD_MARS_PLANETOCENTRIC_2000 ((SRM_SRF_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000
 *
 *  Mars planetodetic
 */
#define SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000 ((SRM_SRF_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_SRFCOD_MARYLAND_SPCS_1983
 *
 *  Maryland (US) state plane coordinate system
 */
#define SRM_SRFCOD_MARYLAND_SPCS_1983 ((SRM_SRF_Code)14)


/*! Upper Bound value for SRF_Codes */
#define SRM_SRF_CODE_UBOUND 14


/*!
 * REGISTERABLE ENUM: SRM_SRF_Parameters_Info_Code
 *
 *  Used as the tag in SRM_SRF_Parameters_Info
 */
typedef SRM_Integer SRM_SRF_Parameters_Info_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFPARAMINFCOD_TEMPLATE
 */
#define SRM_SRFPARAMINFCOD_TEMPLATE ((SRM_SRF_Parameters_Info_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFPARAMINFCOD_SET
 */
#define SRM_SRFPARAMINFCOD_SET ((SRM_SRF_Parameters_Info_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SRFPARAMINFCOD_INSTANCE
 */
#define SRM_SRFPARAMINFCOD_INSTANCE ((SRM_SRF_Parameters_Info_Code)3)


/*! Upper Bound value for SRF_Parameters_Info_Codes */
#define SRM_SRF_PARAMETERS_INFO_CODE_UBOUND 3


/*!
 * REGISTERABLE ENUM: SRM_SRFT_Code
 *
 *  SRF Template Codes
 */
typedef SRM_Integer SRM_SRFT_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_CELESTIOCENTRIC
 *
 *  Celestiocentric SRFT
 */
#define SRM_SRFTCOD_CELESTIOCENTRIC ((SRM_SRFT_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D
 *
 *  Local Space Rectangular 3D SRFT
 */
#define SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D ((SRM_SRFT_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_CELESTIODETIC
 *
 *  Celestiodetic SRFT
 */
#define SRM_SRFTCOD_CELESTIODETIC ((SRM_SRFT_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_PLANETODETIC
 *
 *  Planetodetic SRFT
 */
#define SRM_SRFTCOD_PLANETODETIC ((SRM_SRFT_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN
 *
 *  Local Tangent Space Euclidean SRFT
 */
#define SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN ((SRM_SRFT_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL
 *
 *  Local Tangent Space Azimuthal Spherical SRFT
 */
#define SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL ((SRM_SRFT_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL
 *
 *  Local Tangent Space Cylindrical SRFT
 */
#define SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL ((SRM_SRFT_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D
 *
 *  Lococentric Euclidean 3D SRFT
 */
#define SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D ((SRM_SRFT_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_CELESTIOMAGNETIC
 *
 *  Celestiomagnetic SRFT
 */
#define SRM_SRFTCOD_CELESTIOMAGNETIC ((SRM_SRFT_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_EQUATORIAL_INERTIAL
 *
 *  Equatorial Inertial SRFT
 */
#define SRM_SRFTCOD_EQUATORIAL_INERTIAL ((SRM_SRFT_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_SOLAR_ECLIPTIC
 *
 *  Solar Ecliptic SRFT
 */
#define SRM_SRFTCOD_SOLAR_ECLIPTIC ((SRM_SRFT_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_SOLAR_EQUATORIAL
 *
 *  Solar Equatorial SRFT
 */
#define SRM_SRFTCOD_SOLAR_EQUATORIAL ((SRM_SRFT_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC
 *
 *  Solar Magnetic Ecliptic SRFT
 */
#define SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC ((SRM_SRFT_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE
 *
 *  Solar Magnetic Dipole SRFT
 */
#define SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE ((SRM_SRFT_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC
 *
 *  Heliospheric Aries Ecliptic SRFT
 */
#define SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC ((SRM_SRFT_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC
 *
 *  Heliospheric Earth Ecliptic SRFT
 */
#define SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC ((SRM_SRFT_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL
 *
 *  Heliospheric Earth Equatorial SRFT
 */
#define SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL ((SRM_SRFT_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_MERCATOR
 *
 *  Mercator SRFT
 */
#define SRM_SRFTCOD_MERCATOR ((SRM_SRFT_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL
 *
 *  Oblique Mercator SRFT for a sphere ORM
 */
#define SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL ((SRM_SRFT_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_TRANSVERSE_MERCATOR
 *
 *  Transverse Mercator SRFT
 */
#define SRM_SRFTCOD_TRANSVERSE_MERCATOR ((SRM_SRFT_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC
 *
 *  Lambert Conformal Conic SRFT
 */
#define SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC ((SRM_SRFT_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_POLAR_STEREOGRAPHIC
 *
 *  Polar Stereographic SRFT
 */
#define SRM_SRFTCOD_POLAR_STEREOGRAPHIC ((SRM_SRFT_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL
 *
 *  Equidistant Cylindrical SRFT
 */
#define SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL ((SRM_SRFT_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D
 *
 *  Local Space Rectangular 2D SRFT
 */
#define SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D ((SRM_SRFT_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D
 *
 *  Local Space Azimuthal 2D SRFT
 */
#define SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D ((SRM_SRFT_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D
 *
 *  Local Space Polar 2D SRFT
 */
#define SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D ((SRM_SRFT_Code)26)


/*! Upper Bound value for SRFT_Codes */
#define SRM_SRFT_CODE_UBOUND 26


/*!
 * STRUCT: SRM_Unused
 */
typedef struct
{
    SRM_Integer unused;
} SRM_Unused;


/*!
 * STRUCT: SRM_TM_Parameters
 *
 *  Transverse Mercator (TM) Parameters are used as a means of
 *  specifying the TM spatial coordinate systems
 */
typedef struct
{
    SRM_Long_Float origin_longitude;
    SRM_Long_Float origin_latitude;
    SRM_Long_Float central_scale;
    SRM_Long_Float false_easting;
    SRM_Long_Float false_northing;
} SRM_TM_Parameters;


/*!
 * STRUCT: SRM_SRFT_Parameters
 *
 *   Spatial Reference Frame Template Parameters
 */
typedef struct
{
    SRM_SRFT_Code template_code;
    SRM_ORM_Code  orm_code;
    union _SRM_SRFT_Parameters_Union
    {
        SRM_Unused                      cc_srf_parameters;
        SRM_LSR_3D_Parameters           lsr_3d_srf_parameters;
        SRM_Unused                      cd_srf_parameters;
        SRM_Unused                      pd_srf_parameters;
        SRM_LTSE_Parameters             ltse_srf_parameters;
        SRM_Local_Tangent_Parameters    ltsas_srf_parameters;
        SRM_Local_Tangent_Parameters    ltsc_srf_parameters;
        SRM_LCE_3D_Parameters           lce_3d_srf_parameters;
        SRM_Unused                      cm_srf_parameters;
        SRM_Unused                      ei_srf_parameters;
        SRM_Unused                      sec_srf_parameters;
        SRM_Unused                      seq_srf_parameters;
        SRM_Unused                      sme_srf_parameters;
        SRM_Unused                      smd_srf_parameters;
        SRM_Unused                      haec_srf_parameters;
        SRM_Unused                      heec_srf_parameters;
        SRM_Unused                      heeq_srf_parameters;
        SRM_M_Parameters                m_srf_parameters;
        SRM_Oblique_Mercator_Parameters oms_srf_parameters;
        SRM_TM_Parameters               tm_srf_parameters;
        SRM_LCC_Parameters              lcc_srf_parameters;
        SRM_PS_Parameters               ps_srf_parameters;
        SRM_EC_Parameters               ec_srf_parameters;
        SRM_LSR_2D_Parameters           lsr_2d_srf_parameters;
        SRM_Unused                      lsa_srf_parameters;
        SRM_Unused                      lsp_srf_parameters;
    } parameters;
} SRM_SRFT_Parameters;


/*!
 * REGISTERABLE ENUM: SRM_SRFS_Code
 *
 *  SRF Set Codes
 */
typedef SRM_Integer SRM_SRFS_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFSCOD_UNSPECIFIED
 */
#define SRM_SRFSCOD_UNSPECIFIED ((SRM_SRFS_Code)0)

/*!
 * GLOBAL CONSTANT: SRM_SRFSCOD_ALABAMA_SPCS
 *
 *  Alabama (US) state plane coordinate system.
 */
#define SRM_SRFSCOD_ALABAMA_SPCS ((SRM_SRFS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM
 *
 *  GTRS global coordinate system (GCS) (Earth).
 */
#define SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM ((SRM_SRFS_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS
 *
 *  Japan plane coordinate system
 */
#define SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS ((SRM_SRFS_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_SRFSCOD_LAMBERT_NTF
 *
 *  Lambert NTF.
 */
#define SRM_SRFSCOD_LAMBERT_NTF ((SRM_SRFS_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC
 *
 *  Universal polar stereographic (UPS) (Earth).
 */
#define SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC ((SRM_SRFS_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR
 *
 *  Universal transverse Mercator (UTM) (Earth).
 */
#define SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR ((SRM_SRFS_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_SRFSCOD_WISCONSIN_SPCS
 *
 *  Wisconsin (US) state plane coordinate system.
 */
#define SRM_SRFSCOD_WISCONSIN_SPCS ((SRM_SRFS_Code)7)


/*! Upper Bound value for SRFS_Codes */
#define SRM_SRFS_CODE_UBOUND 7


/*!
 * REGISTERABLE ENUM: SRM_SRFSM_Alabama_SPCS_Code
 *
 *  Alabama SPCS SRF Set Member Codes
 */
typedef SRM_Integer SRM_SRFSM_Alabama_SPCS_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFSMALCOD_WEST_ZONE
 */
#define SRM_SRFSMALCOD_WEST_ZONE ((SRM_SRFSM_Alabama_SPCS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMALCOD_EAST_ZONE
 */
#define SRM_SRFSMALCOD_EAST_ZONE ((SRM_SRFSM_Alabama_SPCS_Code)2)


/*! Upper Bound value for SRFSM_Alabama_SPCS_Codes */
#define SRM_SRFSM_ALABAMA_SPCS_CODE_UBOUND 2


/*!
 * TYPEDEF: SRM_SRFSM_GTRS_GCS_Code
 */
typedef SRM_Integer SRM_SRFSM_GTRS_GCS_Code;
/*! Upper Bound value for GTRS GCS SRF Set Member Codes. */
#define SRM_SRFSM_GTRS_GLOBAL_COORDINATE_SYSTEM_CODE_UBOUND 49896



/*!
 * REGISTERABLE ENUM: SRM_SRFSM_Japan_Rectangular_Plane_CS_Code
 *
 *  Japan Rectangular Plane CS SRF Set Member Codes
 */
typedef SRM_Integer SRM_SRFSM_Japan_Rectangular_Plane_CS_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_I
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_I ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_II
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_II ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_III
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_III ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_IV
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_IV ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_V
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_V ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_VI
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_VI ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_VII
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_VII ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_VIII
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_VIII ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_IX
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_IX ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_X
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_X ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XI
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XI ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XII
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XII ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XIII
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XIII ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XIV
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XIV ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XV
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XV ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XVI
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XVI ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XVII
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XVII ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XVIII
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XVIII ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMJPRPCSCOD_ZONE_XIX
 */
#define SRM_SRFSMJPRPCSCOD_ZONE_XIX ((SRM_SRFSM_Japan_Rectangular_Plane_CS_Code)19)


/*! Upper Bound value for SRFSM_Japan_Rectangular_Plane_CS_Codes */
#define SRM_SRFSM_JAPAN_RECTANGULAR_PLANE_CS_CODE_UBOUND 19


/*!
 * REGISTERABLE ENUM: SRM_SRFSM_Lambert_NTF_Code
 *
 *  Lambert NTF SRF Set Member Codes
 */
typedef SRM_Integer SRM_SRFSM_Lambert_NTF_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFSMLAMNTFCOD_ZONE_I
 */
#define SRM_SRFSMLAMNTFCOD_ZONE_I ((SRM_SRFSM_Lambert_NTF_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMLAMNTFCOD_ZONE_II
 */
#define SRM_SRFSMLAMNTFCOD_ZONE_II ((SRM_SRFSM_Lambert_NTF_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMLAMNTFCOD_ZONE_III
 */
#define SRM_SRFSMLAMNTFCOD_ZONE_III ((SRM_SRFSM_Lambert_NTF_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMLAMNTFCOD_ZONE_IV
 */
#define SRM_SRFSMLAMNTFCOD_ZONE_IV ((SRM_SRFSM_Lambert_NTF_Code)4)


/*! Upper Bound value for SRFSM_Lambert_NTF_Codes */
#define SRM_SRFSM_LAMBERT_NTF_CODE_UBOUND 4


/*!
 * REGISTERABLE ENUM: SRM_SRFSM_UPS_Code
 *
 *  UPS SRF Set Member Codes
 */
typedef SRM_Integer SRM_SRFSM_UPS_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUPSCOD_NORTHERN_POLE
 */
#define SRM_SRFSMUPSCOD_NORTHERN_POLE ((SRM_SRFSM_UPS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUPSCOD_SOUTHERN_POLE
 */
#define SRM_SRFSMUPSCOD_SOUTHERN_POLE ((SRM_SRFSM_UPS_Code)2)


/*! Upper Bound value for SRFSM_UPS_Codes */
#define SRM_SRFSM_UPS_CODE_UBOUND 2


/*!
 * REGISTERABLE ENUM: SRM_SRFSM_UTM_Code
 *
 *  UTM SRF Set Member Codes
 */
typedef SRM_Integer SRM_SRFSM_UTM_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_1_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 1, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_1_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_2_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 2, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_2_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_3_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 3, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_3_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_4_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 4, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_4_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_5_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 5, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_5_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_6_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 6, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_6_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_7_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 7, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_7_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_8_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 8, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_8_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_9_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 9, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_9_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 10, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_11_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 11, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_11_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 12, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_13_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 13, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_13_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_14_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 14, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_14_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_15_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 15, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_15_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_16_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 16, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_16_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_17_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 17, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_17_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_18_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 18, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_18_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_19_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 19, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_19_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)19)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_20_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 20, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_20_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)20)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_21_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 21, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_21_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)21)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_22_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 22, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_22_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)22)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_23_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 23, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_23_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)23)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_24_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 24, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_24_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)24)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_25_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 25, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_25_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)25)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_26_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 26, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_26_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)26)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_27_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 27, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_27_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)27)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_28_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 28, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_28_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)28)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_29_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 29, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_29_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)29)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_30_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 30, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_30_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)30)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_31_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 31, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_31_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)31)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_32_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 32, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_32_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)32)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_33_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 33, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_33_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)33)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_34_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 34, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_34_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)34)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_35_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 35, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_35_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)35)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_36_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 36, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_36_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)36)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_37_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 37, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_37_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)37)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_38_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 38, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_38_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)38)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_39_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 39, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_39_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)39)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_40_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 40, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_40_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)40)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_41_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 41, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_41_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)41)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_42_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 42, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_42_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)42)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_43_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 43, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_43_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)43)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_44_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 44, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_44_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)44)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_45_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 45, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_45_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)45)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_46_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 46, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_46_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)46)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_47_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 47, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_47_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)47)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_48_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 48, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_48_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)48)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_49_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 49, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_49_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)49)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_50_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 50, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_50_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)50)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_51_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 51, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_51_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)51)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_52_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 52, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_52_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)52)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_53_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 53, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_53_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)53)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_54_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 54, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_54_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)54)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_55_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 55, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_55_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)55)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_56_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 56, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_56_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)56)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_57_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 57, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_57_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)57)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_58_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 58, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_58_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)58)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_59_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 59, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_59_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)59)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_60_NORTHERN_HEMISPHERE
 *
 *  UTM Zone 60, northern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_60_NORTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)60)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_1_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 1, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_1_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)61)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_2_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 2, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_2_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)62)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_3_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 3, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_3_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)63)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_4_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 4, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_4_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)64)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_5_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 5, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_5_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)65)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_6_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 6, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_6_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)66)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_7_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 7, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_7_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)67)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_8_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 8, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_8_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)68)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_9_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 9, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_9_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)69)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_10_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 10, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_10_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)70)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_11_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 11, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_11_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)71)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_12_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 12, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_12_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)72)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_13_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 13, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_13_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)73)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_14_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 14, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_14_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)74)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_15_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 15, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_15_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)75)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_16_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 16, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_16_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)76)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_17_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 17, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_17_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)77)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_18_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 18, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_18_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)78)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_19_SOUTHERN_HEMISPHERE
 *
 *  UTM Zone 19, southern hemisphere
 */
#define SRM_SRFSMUTMCOD_ZONE_19_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)79)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_20_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_20_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)80)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_21_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_21_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)81)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_22_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_22_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)82)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_23_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_23_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)83)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_24_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_24_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)84)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_25_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_25_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)85)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_26_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_26_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)86)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_27_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_27_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)87)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_28_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_28_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)88)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_29_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_29_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)89)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_30_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_30_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)90)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_31_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_31_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)91)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_32_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_32_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)92)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_33_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_33_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)93)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_34_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_34_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)94)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_35_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_35_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)95)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_36_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_36_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)96)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_37_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_37_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)97)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_38_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_38_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)98)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_39_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_39_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)99)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_40_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_40_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)100)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_41_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_41_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)101)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_42_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_42_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)102)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_43_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_43_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)103)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_44_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_44_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)104)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_45_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_45_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)105)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_46_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_46_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)106)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_47_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_47_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)107)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_48_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_48_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)108)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_49_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_49_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)109)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_50_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_50_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)110)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_51_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_51_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)111)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_52_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_52_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)112)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_53_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_53_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)113)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_54_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_54_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)114)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_55_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_55_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)115)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_56_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_56_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)116)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_57_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_57_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)117)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_58_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_58_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)118)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_59_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_59_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)119)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMUTMCOD_ZONE_60_SOUTHERN_HEMISPHERE
 */
#define SRM_SRFSMUTMCOD_ZONE_60_SOUTHERN_HEMISPHERE ((SRM_SRFSM_UTM_Code)120)


/*! Upper Bound value for SRFSM_UTM_Codes */
#define SRM_SRFSM_UTM_CODE_UBOUND 120


/*!
 * REGISTERABLE ENUM: SRM_SRFSM_Wisconsin_SPCS_Code
 *
 *  Wisconsin SPCS SRF Set Member Codes
 */
typedef SRM_Integer SRM_SRFSM_Wisconsin_SPCS_Code;

/*!
 * GLOBAL CONSTANT: SRM_SRFSMWNSPCSCOD_SOUTH_ZONE
 */
#define SRM_SRFSMWNSPCSCOD_SOUTH_ZONE ((SRM_SRFSM_Wisconsin_SPCS_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMWNSPCSCOD_CENTRAL_ZONE
 */
#define SRM_SRFSMWNSPCSCOD_CENTRAL_ZONE ((SRM_SRFSM_Wisconsin_SPCS_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_SRFSMWNSPCSCOD_NORTH_ZONE
 */
#define SRM_SRFSMWNSPCSCOD_NORTH_ZONE ((SRM_SRFSM_Wisconsin_SPCS_Code)3)


/*! Upper Bound value for SRFSM_Wisconsin_SPCS_Codes */
#define SRM_SRFSM_WISCONSIN_SPCS_CODE_UBOUND 3


/*!
 * STRUCT: SRM_SRFS_Code_Info
 */
typedef struct
{
    SRM_SRFS_Code srfs_code;
    union _SRM_SRFS_Code_Info_Union
    {
        SRM_Integer                   srfsm_unspecified;
        SRM_SRFSM_Alabama_SPCS_Code   srfsm_alabama_spcs;
        SRM_SRFSM_GTRS_GCS_Code       srfsm_gtrs_gcs;
        SRM_SRFSM_Japan_Rectangular_Plane_CS_Code
            srfsm_japan_rectangular_plane_cs;
        SRM_SRFSM_Lambert_NTF_Code    srfsm_lambert_ntf;
        SRM_SRFSM_UPS_Code            srfsm_ups;
        SRM_SRFSM_UTM_Code            srfsm_utm;
        SRM_SRFSM_Wisconsin_SPCS_Code srfsm_wisconsin_spcs;
    } value;
} SRM_SRFS_Code_Info;


/*!
 * STRUCT: SRM_SRFS_Info
 *
 *   Spatial Reference Frame Set Information
 */
typedef struct
{
    SRM_ORM_Code       orm_code;
    SRM_SRFS_Code_Info srfs_code_info;
} SRM_SRFS_Info;


/*!
 * STRUCT: SRM_SRF_Parameters_Info
 *
 *   Spatial Reference Frame Parameters Information
 */
typedef struct
{
    SRM_SRF_Parameters_Info_Code srf_params_info_code;
    SRM_RT_Code                  rt_code;
    union _SRM_SRF_Parameters_Info_Union
    {
        SRM_SRFT_Parameters srf_template;
        SRM_SRFS_Info       srf_set;
        SRM_SRF_Code        srf_instance;
    } value;
} SRM_SRF_Parameters_Info;


/*!
 * STRUCT: SRM_SRF_Reference_Surface_Info
 *
 *   Spatial Reference Frame Reference Surface Information
 */
typedef struct
{
    SRM_DSS_Code            dss_code;
    SRM_SRF_Parameters_Info srf_parameters_info;
} SRM_SRF_Reference_Surface_Info;


/*!
 * REGISTERABLE ENUM: SRM_Status_Code
 *
 *   This data type specifies the return codes used by the SRM
 *   coordinate operations (conversion and transformation).
 */
typedef SRM_Integer SRM_Status_Code;

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_SUCCESS
 *
 *  Coordinate operation successful.
 */
#define SRM_STATCOD_SUCCESS ((SRM_Status_Code)1)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_SRF
 *
 *  The spatial reference frame (SRF) parameters are wrong,
 *  or the pointer is NULL.
 */
#define SRM_STATCOD_INVALID_SRF ((SRM_Status_Code)2)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_SOURCE_SRF
 *
 *  The source spatial reference frame (SRF) parameters are wrong,
 *  or the pointer is NULL.
 */
#define SRM_STATCOD_INVALID_SOURCE_SRF ((SRM_Status_Code)3)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_SOURCE_COORDINATE
 *
 *  The source coordinate is NULL, or invalid within the source
 *  spatial reference frame (SRF).
 */
#define SRM_STATCOD_INVALID_SOURCE_COORDINATE ((SRM_Status_Code)4)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_TARGET_COORDINATE
 *
 *  The target coordinate is NULL, or invalid within the
 *  destination SRF.
 */
#define SRM_STATCOD_INVALID_TARGET_COORDINATE ((SRM_Status_Code)5)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_POINT1_COORDINATE
 *
 *  The point 1 coordinate is NULL, or invalid within the source
 *  spatial reference frame (SRF).
 */
#define SRM_STATCOD_INVALID_POINT1_COORDINATE ((SRM_Status_Code)6)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_POINT2_COORDINATE
 *
 *  The point 2 coordinate is NULL, or invalid within the
 *  destination SRF.
 */
#define SRM_STATCOD_INVALID_POINT2_COORDINATE ((SRM_Status_Code)7)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_OPERATION_UNSUPPORTED
 *
 *  The operation requested is not supported.
 */
#define SRM_STATCOD_OPERATION_UNSUPPORTED ((SRM_Status_Code)8)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_SOURCE_DIRECTION
 *
 *  The source direction is NULL, or invalid.
 */
#define SRM_STATCOD_INVALID_SOURCE_DIRECTION ((SRM_Status_Code)9)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_TARGET_DIRECTION
 *
 *  The target direction is NULL, or invalid.
 */
#define SRM_STATCOD_INVALID_TARGET_DIRECTION ((SRM_Status_Code)10)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_CODE
 *
 *  The code is NULL, or invalid.
 */
#define SRM_STATCOD_INVALID_CODE ((SRM_Status_Code)11)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_INPUT
 *
 *  The input is NULL, or invalid.
 */
#define SRM_STATCOD_INVALID_INPUT ((SRM_Status_Code)12)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_CREATION_FAILURE
 *
 *  failed creation
 */
#define SRM_STATCOD_CREATION_FAILURE ((SRM_Status_Code)13)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_DESTRUCTION_FAILURE
 *
 *  failed destruction
 */
#define SRM_STATCOD_DESTRUCTION_FAILURE ((SRM_Status_Code)14)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_FLOATING_OVERFLOW
 *
 *  floating overflow
 */
#define SRM_STATCOD_FLOATING_OVERFLOW ((SRM_Status_Code)15)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_FLOATING_UNDERFLOW
 *
 *  floating underflow
 */
#define SRM_STATCOD_FLOATING_UNDERFLOW ((SRM_Status_Code)16)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_FLOATING_POINT_ERROR
 *
 *  floating point error
 */
#define SRM_STATCOD_FLOATING_POINT_ERROR ((SRM_Status_Code)17)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_MEMORY_ALLOCATION_ERROR
 *
 *  Unable to allocate memory
 */
#define SRM_STATCOD_MEMORY_ALLOCATION_ERROR ((SRM_Status_Code)18)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_BUFFER_OVERFLOW
 *
 *  Buffer overflow
 */
#define SRM_STATCOD_BUFFER_OVERFLOW ((SRM_Status_Code)2401)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_ENUMERATION_VALUE_INVALID
 *
 *  Invalid enumeration value
 */
#define SRM_STATCOD_ENUMERATION_VALUE_INVALID ((SRM_Status_Code)2402)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_SOURCE_ORIENTATION
 *
 *  The source orientation is NULL, or invalid.
 */
#define SRM_STATCOD_INVALID_SOURCE_ORIENTATION ((SRM_Status_Code)-100)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INVALID_TARGET_ORIENTATION
 *
 *  The target orientation is NULL, or invalid.
 */
#define SRM_STATCOD_INVALID_TARGET_ORIENTATION ((SRM_Status_Code)-101)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_NOT_IMPLEMENTED
 *
 *  not implemented
 */
#define SRM_STATCOD_NOT_IMPLEMENTED ((SRM_Status_Code)-102)

/*!
 * GLOBAL CONSTANT: SRM_STATCOD_INACTIONABLE
 *
 *  inactionable
 */
#define SRM_STATCOD_INACTIONABLE ((SRM_Status_Code)-103)


/*! Upper Bound value for Status_Codes */
#define SRM_STATUS_CODE_UBOUND -103

#ifdef __cplusplus
}
#endif

#endif /* #ifndef/define/endif for SRM_TYPES_H_INCLUDED */
